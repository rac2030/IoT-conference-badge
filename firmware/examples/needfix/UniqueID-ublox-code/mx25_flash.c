
/*---------------------------------------------------------------------------
* Copyright (c) 2018 u-blox
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* Component   : mx25x flash
* File        : mx25_flash.c
*
* Description : Functionality for mx25xx flash memory otp management
*-------------------------------------------------------------------------*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>


#include <rom/spi_flash.h>
#include <rom/cache.h>
#include <soc/soc.h>
#include <soc/dport_reg.h>
#include "sdkconfig.h"
#include "esp_ipc.h"
#include "esp_attr.h"
#include "esp_spi_flash.h"
#include "mx25_flash.h"
#include "esp_log.h"

/*===========================================================================
* DEFINES
*=========================================================================*/
// undef to use actual OTP 
//#define OTP_TEST

#define SPI_CONTROLLER_ID                           1
#define MAX_TRANSFER_SIZE                           64
#define MAX_READ_SIZE                               (MAX_TRANSFER_SIZE - 4)
#define MAX_WRITE_SIZE                              (MAX_TRANSFER_SIZE - 4)

#define OTP_AREA_SIZE                               0x200
#define PAGE_SIZE                                   0x100
#define REGISTER_VALUE_OFFSET                       0x01
#define STATUS_REG_WRITE_IN_PROGRESS_BIT            0x01
#define STATUS_REG_WRITE_ENABLED_BIT                0x02
#define SECURITY_REG_LOCK_DOWN_SEC_OTP_BIT          0x02

#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define CMD_READ        0x03
#define CMD_PP          0x02
#define CMD_ENSO        0xB1
#define CMD_EXSO        0xC1
#define CMD_WRSCUR      0x2F
#define CMD_RDSCUR      0x2B
#define CMD_WREN        0x06
#define CMD_RDSR        0x05


/*===========================================================================
* DECLARATIONS
*=========================================================================*/
static esp_err_t IRAM_ATTR spi_transfer(uint8_t *cmd, uint32_t cmd_len, uint8_t *data_out, uint32_t data_out_len, uint8_t *data_in, uint32_t data_in_len);
static esp_err_t IRAM_ATTR spi_flash_write_otp_chunk(uint32_t offset, uint8_t *data, uint32_t len);
static esp_err_t IRAM_ATTR spi_flash_read_otp_chunk(uint32_t offset, uint8_t *data, uint32_t len);
static void IRAM_ATTR store_spi_registers(uint32_t prev[]);
static void IRAM_ATTR restore_spi_registers(uint32_t prev[]);
static void IRAM_ATTR configure_spi(void);

static esp_err_t IRAM_ATTR cmd_enso(void);
static esp_err_t IRAM_ATTR cmd_exso(void);
static esp_err_t IRAM_ATTR cmd_wren(void);
static esp_err_t IRAM_ATTR cmd_read(uint32_t offset, uint8_t *buf, uint32_t size);
static esp_err_t IRAM_ATTR cmd_pp(uint32_t offset, uint8_t *buf, uint32_t size);
static esp_err_t IRAM_ATTR cmd_rdsr(uint8_t *status);
static esp_err_t IRAM_ATTR cmd_rdscur(uint8_t *status);
static esp_err_t IRAM_ATTR cmd_wrscur(void);

extern void spi_flash_disable_interrupts_caches_and_other_cpu(void);
extern void spi_flash_enable_interrupts_caches_and_other_cpu(void);

/*===========================================================================
* FUNCTIONS
*=========================================================================*/

/**
* @brief Read from otp memory.
*
*        Maximum data size for the underlying spi transfer is 64 bytes.
*        4 of these are used for the spi command and next 60 bytes data
*        This function splits the read into suitable chunks.
*
*/
esp_err_t spi_flash_read_otp(uint32_t offset, uint8_t *data, uint32_t len)
{
    esp_err_t err = ESP_OK;
    uint32_t read_offset = offset;

    if ((offset > OTP_AREA_SIZE) || ((offset + len) > OTP_AREA_SIZE)) {
        return ESP_FAIL;
    }

    while ((err == ESP_OK) &&
           (read_offset < (offset + len))) {
        uint32_t read_len = offset + len - read_offset;

        // Handle spi max transfer size
        read_len = MIN(read_len, MAX_READ_SIZE);

        err = spi_flash_read_otp_chunk(read_offset, data, read_len);
        read_offset += read_len;
        data += read_len;
    }

    return err;
}

/**
* @brief Write to otp memory.
*
*        Only one page can be written in each write page program command.
*        Maximum data size for the underlying spi transfer is 64 bytes.
*        4 of these are used for the spi command and next 60 bytes data
*        This function splits the write into suitable chunks.
*
*/
esp_err_t spi_flash_write_otp(uint32_t offset, uint8_t *data, uint32_t len)
{
    esp_err_t err = ESP_OK;
    uint32_t write_offset = offset;

    if ((offset > OTP_AREA_SIZE) || ((offset + len) > OTP_AREA_SIZE)) {
        return ESP_FAIL;
    }

    if (spi_flash_otp_is_locked()) {
        return ESP_FAIL;
    }

    while ((err == ESP_OK) &&
           (write_offset < (offset + len))) {
        uint32_t write_len = offset + len - write_offset;

        // Handle HW limitations, page boundaries and spi max transfer size
        write_len = MIN(write_len, PAGE_SIZE - (write_offset & 0xFF));
        write_len = MIN(write_len, MAX_WRITE_SIZE);

        err = spi_flash_write_otp_chunk(write_offset, data, write_len);
        write_offset += write_len;
        data += write_len;
    }

    return err;
}

esp_err_t IRAM_ATTR spi_flash_lock_otp(void)
{
    uint32_t spi_config[8];
    uint8_t status;
#ifndef BOOTLOADER_BUILD
    spi_flash_disable_interrupts_caches_and_other_cpu();
#endif
    store_spi_registers(spi_config);
    configure_spi();

    cmd_wren(); 

    do
    {
        cmd_rdsr(&status);
    } while ((status & STATUS_REG_WRITE_ENABLED_BIT) == 0);

    do
    {
        cmd_wrscur();
        cmd_rdscur(&status);
    } while ((status & SECURITY_REG_LOCK_DOWN_SEC_OTP_BIT) == 0);
    
    restore_spi_registers(spi_config);
#ifndef BOOTLOADER_BUILD
    spi_flash_enable_interrupts_caches_and_other_cpu();
#endif
    return ESP_OK;
}

bool IRAM_ATTR spi_flash_otp_is_locked(void)
{
    uint32_t spi_config[8];
    uint8_t value;
#ifndef BOOTLOADER_BUILD
    spi_flash_disable_interrupts_caches_and_other_cpu();
#endif
    store_spi_registers(spi_config);
    configure_spi();

    cmd_rdscur(&value);

    restore_spi_registers(spi_config);
#ifndef BOOTLOADER_BUILD
    spi_flash_enable_interrupts_caches_and_other_cpu();
#endif
    return ((value & SECURITY_REG_LOCK_DOWN_SEC_OTP_BIT) == SECURITY_REG_LOCK_DOWN_SEC_OTP_BIT);
}

esp_err_t IRAM_ATTR spi_flash_read_otp_chunk(uint32_t offset, uint8_t *data, uint32_t len)
{
    esp_err_t ret;
    uint32_t prev[8];

    if ((offset > OTP_AREA_SIZE) || ((offset + len) > OTP_AREA_SIZE)) {
        return ESP_FAIL;
    }
    
#ifndef BOOTLOADER_BUILD
    spi_flash_disable_interrupts_caches_and_other_cpu();
#endif
    store_spi_registers(prev);
    configure_spi();

    cmd_enso();

    ret = cmd_read(offset, data, len);

    cmd_exso();

    restore_spi_registers(prev);
#ifndef BOOTLOADER_BUILD
    spi_flash_enable_interrupts_caches_and_other_cpu();
#endif
    return ret;
}


static esp_err_t IRAM_ATTR spi_flash_write_otp_chunk(uint32_t offset, uint8_t *data, uint32_t len) 
{
    esp_err_t ret;
    uint32_t spi_config[8];
    uint8_t status;
#ifndef BOOTLOADER_BUILD
    spi_flash_disable_interrupts_caches_and_other_cpu();
#endif
    store_spi_registers(spi_config);
    configure_spi();

    cmd_enso();
    cmd_wren();

    do 
    {
        cmd_rdsr(&status);
    } while ((status & STATUS_REG_WRITE_ENABLED_BIT) == 0);

    ret = cmd_pp(offset, data, len);

    do
    {
        cmd_rdsr(&status);
    } while ((status & STATUS_REG_WRITE_IN_PROGRESS_BIT) != 0);

    cmd_exso();

    restore_spi_registers(spi_config);
#ifndef BOOTLOADER_BUILD
    spi_flash_enable_interrupts_caches_and_other_cpu();
#endif
    return ret;
}

static void IRAM_ATTR store_spi_registers(uint32_t prev[])
{
    prev[0] = READ_PERI_REG(SPI_USER_REG(1));
    prev[1] = READ_PERI_REG(SPI_USER1_REG(1));
    prev[2] = READ_PERI_REG(SPI_USER2_REG(1));
    prev[3] = READ_PERI_REG(SPI_CTRL_REG(1));
    prev[4] = READ_PERI_REG(SPI_CTRL2_REG(1));
    prev[5] = READ_PERI_REG(SPI_SLAVE_REG(1));
    prev[6] = READ_PERI_REG(SPI_PIN_REG(1));
    prev[7] = READ_PERI_REG(SPI_CLOCK_REG(1));
}

static void IRAM_ATTR restore_spi_registers(uint32_t prev[])
{
    WRITE_PERI_REG(SPI_USER_REG(1), prev[0]);
    WRITE_PERI_REG(SPI_USER1_REG(1), prev[1]);
    WRITE_PERI_REG(SPI_USER2_REG(1), prev[2]);
    WRITE_PERI_REG(SPI_CTRL_REG(1), prev[3]);
    WRITE_PERI_REG(SPI_CTRL2_REG(1), prev[4]);
    WRITE_PERI_REG(SPI_SLAVE_REG(1), prev[5]);
    WRITE_PERI_REG(SPI_PIN_REG(1), prev[6]);
    WRITE_PERI_REG(SPI_CLOCK_REG(1), prev[7]);
}

static void IRAM_ATTR configure_spi(void)
{
    // Clean SPI registers
    WRITE_PERI_REG(SPI_USER_REG(1), 0);
    WRITE_PERI_REG(SPI_USER1_REG(1), 0);
    WRITE_PERI_REG(SPI_USER2_REG(1), 0);
    WRITE_PERI_REG(SPI_CTRL_REG(1), 0);
    WRITE_PERI_REG(SPI_CTRL2_REG(1), 0);
    WRITE_PERI_REG(SPI_SLAVE_REG(1), 0);
    WRITE_PERI_REG(SPI_PIN_REG(1), 0);

    // Set SPI mode 0
    CLEAR_PERI_REG_MASK(SPI_PIN_REG(1), SPI_CK_IDLE_EDGE);
    CLEAR_PERI_REG_MASK(SPI_USER_REG(1), SPI_CK_OUT_EDGE);

    // Set bit order to MSB
    CLEAR_PERI_REG_MASK(SPI_CTRL_REG(1), SPI_WR_BIT_ORDER | SPI_RD_BIT_ORDER);

    // Enable full-duplex communication
    SET_PERI_REG_MASK(SPI_USER_REG(1), SPI_DOUTDIN);

    // Configure as master
    WRITE_PERI_REG(SPI_USER1_REG(1), 0);
    SET_PERI_REG_BITS(SPI_CTRL2_REG(1), SPI_MISO_DELAY_MODE, 0, SPI_MISO_DELAY_MODE_S);
    CLEAR_PERI_REG_MASK(SPI_SLAVE_REG(1), SPI_SLAVE_MODE);

    // Set clock to 1 Mhz 
    WRITE_PERI_REG(SPI_CLOCK_REG(1), 0x1FFE18);

    // Enable MOSI / MISO / CS
    SET_PERI_REG_MASK(SPI_USER_REG(1), SPI_CS_SETUP | SPI_CS_HOLD | SPI_USR_MOSI | SPI_USR_MISO);
    SET_PERI_REG_MASK(SPI_CTRL2_REG(1), ((0x4 & SPI_MISO_DELAY_NUM) << SPI_MISO_DELAY_NUM_S));

    // Don't use command / address phase
    CLEAR_PERI_REG_MASK(SPI_USER_REG(1), SPI_USR_COMMAND);
    SET_PERI_REG_BITS(SPI_USER2_REG(1), SPI_USR_COMMAND_BITLEN, 0, SPI_USR_COMMAND_BITLEN_S);

    CLEAR_PERI_REG_MASK(SPI_USER_REG(1), SPI_USR_ADDR);
    SET_PERI_REG_BITS(SPI_USER1_REG(1), SPI_USR_ADDR_BITLEN, 0, SPI_USR_ADDR_BITLEN_S);
}


/**
 * @brief Perform SPI transfer
 *
 * The maximum total transfer size is 64 bytes.
 * SPI data buffer hardware is 16 32-bit size registers,
 *
 * return ESP_OK if operation succeeds, ESP_FAIL is not
 */
static esp_err_t IRAM_ATTR spi_transfer(uint8_t *cmd, uint32_t cmd_len,
                                        uint8_t *data_out, uint32_t data_out_len,
                                        uint8_t *data_in, uint32_t data_in_len)
{
    uint8_t buffer[MAX_TRANSFER_SIZE];          // Transfer buffer
    uint32_t *p_buffer = (uint32_t*)&buffer;     // 32-bit representation of transfer buffer

    uint32_t bytes = cmd_len + data_out_len + data_in_len;
    uint32_t read_offset = cmd_len + data_out_len;
    uint32_t idx = 0;

    if (bytes > sizeof(buffer)){
        return ESP_FAIL;
    }

    for (uint32_t j = 0; j < bytes; j++) {
        if (cmd && (j < cmd_len)) {
            buffer[j] = *cmd;
            cmd++;
        }
        else if (data_out && (j < (cmd_len + data_out_len))) {
            buffer[j] = *data_out;
            data_out++;
        }
        else {
            buffer[j] = 0xFF;
        }
    }

    // Wait for SPI bus ready
    while (READ_PERI_REG(SPI_CMD_REG(SPI_CONTROLLER_ID))&SPI_USR);
        
    // Load send buffer
    SET_PERI_REG_BITS(SPI_MOSI_DLEN_REG(SPI_CONTROLLER_ID), SPI_USR_MOSI_DBITLEN, bytes*8 - 1, SPI_USR_MOSI_DBITLEN_S);
    SET_PERI_REG_BITS(SPI_MISO_DLEN_REG(SPI_CONTROLLER_ID), SPI_USR_MISO_DBITLEN, bytes*8 - 1, SPI_USR_MISO_DBITLEN_S);

    for (idx = 0; (idx << 2) < bytes; idx++) {
        WRITE_PERI_REG(SPI_W0_REG(SPI_CONTROLLER_ID) + (idx << 2), p_buffer[idx]);
    }

    // Start transfer
    SET_PERI_REG_MASK(SPI_CMD_REG(SPI_CONTROLLER_ID), SPI_USR);
    // Wait for SPI bus ready
    while (READ_PERI_REG(SPI_CMD_REG(SPI_CONTROLLER_ID))&SPI_USR);

    if (data_in) {
        // Read data into buffer
        for (idx = 0; (idx << 2) < bytes; idx++) {
            p_buffer[idx] = READ_PERI_REG(SPI_W0_REG(SPI_CONTROLLER_ID) + (idx << 2));
        }

        for (uint32_t k = read_offset; k < bytes; k++){
            *data_in = buffer[k];
            data_in++;
        }
    }

    return ESP_OK;
}

static esp_err_t IRAM_ATTR cmd_enso(void)
{
#ifndef OTP_TEST
    uint8_t cmd[] = { CMD_ENSO };
    return spi_transfer(cmd, sizeof(cmd), NULL, 0, NULL, 0);
#else
    return ESP_OK;
#endif
}

static esp_err_t IRAM_ATTR cmd_exso(void)
{
#ifndef OTP_TEST
    uint8_t cmd[] = { CMD_EXSO };
    return spi_transfer(cmd, sizeof(cmd), NULL, 0, NULL, 0);
#else
    return ESP_OK;
#endif
}

static esp_err_t inline cmd_wren(void)
{
    uint8_t cmd[] = { CMD_WREN };
    return spi_transfer(cmd, sizeof(cmd), NULL, 0, NULL, 0);
}

static esp_err_t IRAM_ATTR cmd_read(uint32_t offset, uint8_t *buf, uint32_t size)
{
    uint8_t cmd[] = {
        CMD_READ,
        (uint8_t)(offset >> 16),
        (uint8_t)(offset >> 8),
        (uint8_t)(offset) 
    };

    return spi_transfer(cmd, sizeof(cmd), NULL, 0, buf, size);
}

static esp_err_t IRAM_ATTR cmd_pp(uint32_t offset, uint8_t *buf, uint32_t size)
{
    uint8_t cmd[] = {
        CMD_PP,
        (uint8_t)(offset >> 16),
        (uint8_t)(offset >> 8),
        (uint8_t)(offset)
    };

    return spi_transfer(cmd, sizeof(cmd), buf, size, NULL, 0);
}

static esp_err_t IRAM_ATTR cmd_rdsr(uint8_t *status)
{
    uint8_t cmd[] = { CMD_RDSR };
    return spi_transfer(cmd, sizeof(cmd), NULL, 0, status, 1);
}

static esp_err_t IRAM_ATTR cmd_rdscur(uint8_t *status)
{
    uint8_t cmd[] = { CMD_RDSCUR };
    return spi_transfer(cmd, sizeof(cmd), NULL, 0, status, 1);
}

static esp_err_t IRAM_ATTR cmd_wrscur(void)
{
#ifndef OTP_TEST
    uint8_t cmd[] = { CMD_WRSCUR };
    return spi_transfer(cmd, sizeof(cmd),  NULL, 0, NULL, 0);
#else
    return ESP_OK;
#endif
}
