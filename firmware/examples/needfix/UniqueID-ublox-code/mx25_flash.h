#ifndef MX25_FLASH_H
#define MX25_FLASH_H

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
* File        : mx25_flash.h
*
* Description : Functionality for mx25xx flash memory otp management
*-------------------------------------------------------------------------*/
#include <stdbool.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Write to otp memory. 
*        Write will only be performed if otp is not locked.
* @note  Writing otp memory can only be done once!
*
* @param offset otp memory flash write start offset
* @param data write buffer
* @param len length of write buffer
*
* @return ESP_OK if write is successful, ESP_FAIL if not
*/
esp_err_t spi_flash_write_otp(uint32_t offset, uint8_t *data, uint32_t len);

/**
* @brief Read from otp memory.
*
* @param offset otp memory flash read start offset
* @param data read buffer
* @param len length of read buffer
*
* @return ESP_OK if read is successful, ESP_FAIL if not
*/
esp_err_t spi_flash_read_otp(uint32_t offset, uint8_t *data, uint32_t len);

/**
* @brief Lock otp memory. After this operation no writes can be performed to otp memory
*
* @return ESP_OK if lock is successful, ESP_FAIL if not
*/
esp_err_t spi_flash_lock_otp(void);

/**
* @brief Check if otp memory is locked.
*
* @return True if otp is locked. False if not.
*/
bool spi_flash_otp_is_locked(void);

#ifdef __cplusplus
}
#endif

#endif //MX25_FLASH_H
