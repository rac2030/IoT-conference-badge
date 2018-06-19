#ifndef OTP_DEFS_H
#define OTP_DEFS_H

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
* File        : otp_defs.h
*
* Description : Functionality for reading otp parameters
*-------------------------------------------------------------------------*/
#define cbOTP_BASE_ADDRESS                      (0)
#define cbOTP_SIZE                              (512)
#define cbOTP_MAX_PARAMETER_SIZE                (256)

#define cbOTP_SIZE_RF_FREQ_CALIBRATION          (1)
#define cbOTP_SIZE_SERIAL                       (8)
#define cbOTP_SIZE_FEATURE_MASK                 (8)

#define cbOTP_OFFSET_RF_FREQ_CALIBRATION        (cbOTP_BASE_ADDRESS)
#define cbOTP_OFFSET_FEATURE_MASK               (cbOTP_SIZE_RF_FREQ_CALIBRATION + 40)
#define cbOTP_OFFSET_SERIAL                     (cbOTP_OFFSET_FEATURE_MASK + cbOTP_SIZE_FEATURE_MASK)

#define cbOTP_FEATURE_ANTENNA_PAD               (1 << 3)

#endif
