#ifndef OTP_READER_H
#define OTP_READER_H

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
* File        : otp_reader.h
*
* Description : Functionality for reading otp parameters
*-------------------------------------------------------------------------*/
#include "esp_err.h"
#include "otp_defs.h"

/**
* @brief Read device specific rf frequency calibration value from otp.
*
* @return frequency calibration value
*/
int8_t otp_read_rf_freq_calibration(void);

/**
* @brief Read device serial number
*
* @param serial_number pointer to the serial_number
*
* @return ESP_OK if read is successful, ESP_FAIL if not
*/
esp_err_t otp_read_serial_number(uint8_t serial_number[cbOTP_SIZE_SERIAL]);

/**
* @brief Read device feature mask from from otp
*
* @param feature_mask pointer to feature mask
*
* @return ESP_OK if read is successful, ESP_FAIL if not
*/
esp_err_t otp_read_feature_mask(uint8_t feature_mask[cbOTP_SIZE_FEATURE_MASK]);


#endif //OTP_READER_H
