
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
* File        : otp_reader.c
*
* Description : Functionality for reading otp parameters
*-------------------------------------------------------------------------*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "esp_err.h"
#include "mx25_flash.h"
#include "otp_defs.h"
#include "otp_reader.h"
#include <Arduino.h>


/*===========================================================================
* DEFINES
*=========================================================================*/

/*===========================================================================
* DECLARATIONS
*=========================================================================*/
static esp_err_t is_valid_parameter(uint8_t buf[], uint32_t len);

/*===========================================================================
* FUNCTIONS
*=========================================================================*/

int8_t otp_read_rf_freq_calibration(void)
{
    int8_t freq_calibration;
    esp_err_t ret;

    ret = spi_flash_read_otp(cbOTP_OFFSET_RF_FREQ_CALIBRATION, (uint8_t*)&freq_calibration, 1);
    if (ret != ESP_OK) {
        freq_calibration = 0;
    }

    return freq_calibration;
}

esp_err_t otp_read_serial_number(uint8_t serial_number[cbOTP_SIZE_SERIAL])
{
    esp_err_t ret;
    Serial.println("inside otp_read_serial_number");
    if (serial_number == NULL) {
        Serial.println("serial_number == null");
        return ESP_ERR_INVALID_ARG;
    }
    Serial.println("Begin spi_flash_read_otp");
    ret = spi_flash_read_otp(cbOTP_OFFSET_SERIAL, serial_number, cbOTP_SIZE_SERIAL);
    Serial.println("End spi_flash_read_otp");
    if (ret != ESP_OK) {
        memset(serial_number, 0, cbOTP_SIZE_SERIAL);
    } else {
        ret = is_valid_parameter(serial_number, cbOTP_SIZE_SERIAL);
    }
    return ret;
}

esp_err_t otp_read_feature_mask(uint8_t feature_mask[cbOTP_SIZE_FEATURE_MASK])
{
    esp_err_t ret;

    if (feature_mask == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    ret = spi_flash_read_otp(cbOTP_OFFSET_FEATURE_MASK, feature_mask, cbOTP_SIZE_FEATURE_MASK);
    if (ret != ESP_OK) {
        memset(feature_mask, 0, cbOTP_SIZE_FEATURE_MASK);
    }
	else {
		ret = is_valid_parameter(feature_mask, cbOTP_SIZE_FEATURE_MASK);
	}
    return ret;
}

/**
* @brief Check if OTP parameter is programmed.
*
* @param buf pointer to parameter value buffer
* @param len length of parameter
*
* @return ESP_OK if parameter is valid , ESP_FAIL if not
*/
static esp_err_t is_valid_parameter(uint8_t buf[], uint32_t len)
{
    for (uint8_t i = 0; i < len; i++) {
        if (buf[i] != 0xFF)
            return ESP_OK;
    }
    /* Assume non programmed memory area if contains all 0xff */
    return ESP_FAIL;
}
