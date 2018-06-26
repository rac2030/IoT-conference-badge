#ifndef _mzlogo_H_
#define _mzlogo_H_

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

const unsigned char IMAGE_MZ_LOGO_FULLSCREEN[] = { 
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xf8,0x00,0x1f,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xfc,0x7f,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xf8,0x00,0x7f,0xff,0xcf,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xc8,0x00,0xff,0x87,0xf9,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0x78,0x3f,0xff,0xfe,0x7f,0x7f,0xff,0xff,0xff
,0xff,0xff,0xff,0xfd,0xfb,0xff,0xff,0xff,0xef,0xdf,0xff,0xff,0xff
,0xff,0xff,0xff,0xf7,0xcf,0xff,0xff,0xff,0xf9,0xf7,0xff,0xff,0xff
,0xff,0xff,0xff,0xef,0x7f,0xff,0xff,0xff,0xff,0x7b,0xff,0xff,0xff
,0xff,0xff,0xff,0xbd,0xff,0xff,0xff,0xff,0xff,0xde,0xff,0xff,0xff
,0xff,0xff,0xff,0xf3,0xff,0xff,0xff,0xff,0xff,0xe7,0x7f,0xff,0xff
,0xff,0xff,0xfd,0xef,0xff,0xff,0xff,0xff,0xff,0xfb,0xdf,0xff,0xff
,0xff,0xff,0xfb,0xbf,0xff,0xff,0xff,0xff,0xff,0xfe,0xef,0xff,0xff
,0xff,0xff,0xf7,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xff,0xff
,0xff,0xff,0xee,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xbb,0xff,0xff
,0xff,0xff,0xdd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdd,0xff,0xff
,0xff,0xff,0xbb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xff,0xff
,0xff,0xff,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0x7f,0xff
,0xff,0xfe,0xef,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xbf,0xff
,0xff,0xfd,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xdf,0xff
,0xff,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xff,0xff
,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff
,0xff,0xf6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xb7,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xed,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff
,0xff,0xdb,0xff,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xed,0xff
,0xff,0xff,0xff,0xe0,0x3f,0xff,0xff,0xff,0xfe,0x07,0xff,0xef,0xff
,0xff,0xb7,0xff,0xc0,0x1f,0xff,0xff,0xff,0xfc,0x03,0xff,0xf6,0xff
,0xff,0xff,0xff,0x8f,0x8f,0xff,0xff,0xff,0xf8,0xf9,0xff,0xff,0xff
,0xff,0x6f,0xff,0x8f,0x87,0xff,0xff,0xff,0xf9,0xf9,0xff,0xfb,0x7f
,0xff,0xff,0xff,0x9f,0xc3,0xff,0xff,0xff,0xf9,0xfc,0xff,0xff,0xff
,0xfe,0xdf,0xff,0x9f,0xc1,0xff,0xff,0xff,0xf9,0xfc,0xff,0xfd,0xbf
,0xfe,0xdf,0xff,0x9f,0xc0,0x7f,0xff,0xff,0xf9,0xfc,0xff,0xfd,0xbf
,0xff,0xff,0xff,0x8f,0x80,0x3f,0xff,0xff,0xf9,0xf8,0xff,0xff,0xff
,0xfd,0xbf,0xff,0x82,0x00,0x1f,0xff,0xff,0xf8,0x70,0xff,0xfe,0xdf
,0xfd,0xff,0xff,0x80,0x00,0x0f,0xff,0xff,0xf8,0x00,0xff,0xff,0xdf
,0xff,0xff,0xff,0x80,0x00,0x03,0xff,0xff,0xf8,0x00,0xff,0xff,0xff
,0xfb,0x7f,0xff,0x80,0x00,0x01,0xff,0xff,0xf8,0x00,0xff,0xff,0x6f
,0xfb,0x7f,0xff,0x80,0x00,0x00,0xff,0xff,0xf8,0x00,0xff,0xff,0x6f
,0xfb,0xff,0xff,0x80,0x00,0x00,0x7f,0xff,0xf8,0x00,0xff,0xff,0xef
,0xff,0xff,0xff,0x80,0x00,0x00,0x3f,0xff,0xf8,0x00,0xff,0xff,0xff
,0xfe,0xff,0xff,0x80,0x00,0x00,0x0f,0xff,0xf8,0x00,0xff,0xff,0xbf
,0xf6,0xff,0xff,0x80,0x00,0x00,0x07,0xff,0xf8,0x00,0xff,0xff,0xb7
,0xf6,0xff,0xff,0x80,0x08,0x00,0x03,0xff,0xf8,0x00,0xff,0xff,0xb7
,0xf6,0xff,0xff,0x80,0x0c,0x00,0x01,0xff,0xf8,0x00,0xff,0xff,0xb7
,0xf7,0xff,0xff,0x80,0x0e,0x00,0x00,0xff,0xf8,0x00,0xff,0xff,0xf7
,0xf7,0xff,0xff,0x80,0x0f,0x00,0x00,0x3f,0xf8,0x00,0xff,0xff,0xc7
,0xf7,0xff,0xff,0x80,0x0f,0xc0,0x00,0x1f,0xf8,0x00,0xff,0xff,0xc7
,0xf7,0xff,0xff,0x80,0x0f,0xe0,0x00,0x0f,0xf8,0x00,0xff,0xff,0xc7
,0xf7,0xff,0xff,0x80,0x0f,0xf0,0x00,0x07,0xf8,0x00,0xff,0xff,0xc7
,0xf7,0xff,0xff,0x80,0x0f,0xf8,0x00,0x03,0xf8,0x00,0xff,0xff,0xc7
,0xf7,0xff,0xff,0x80,0x0f,0xfc,0x00,0x00,0xf8,0x00,0xff,0xff,0xc7
,0xf7,0xff,0xff,0x80,0x0f,0xff,0x00,0x00,0x78,0x00,0xff,0xff,0xc7
,0xf7,0xff,0xff,0x80,0x0f,0xff,0x80,0x00,0x38,0x00,0xff,0xff,0xc7
,0xf6,0xff,0xff,0x80,0x0f,0xff,0xc0,0x00,0x18,0x00,0xff,0xff,0x87
,0xf6,0xff,0xff,0x80,0x0f,0xff,0xe0,0x00,0x00,0x00,0xff,0xff,0x87
,0xfe,0xff,0xff,0x80,0x0f,0xff,0xf8,0x00,0x00,0x00,0xff,0xff,0x8f
,0xfe,0xff,0xff,0x80,0x0f,0xff,0xfc,0x00,0x00,0x00,0xff,0xff,0x8f
,0xff,0xff,0xff,0x80,0x0f,0xff,0xfe,0x00,0x00,0x00,0xff,0xff,0x8f
,0xfb,0xff,0xff,0x80,0x0f,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0x8f
,0xfb,0x7f,0xff,0x80,0x0f,0xff,0xff,0x80,0x00,0x00,0xff,0xff,0x0f
,0xff,0x7f,0xff,0x80,0x0f,0xff,0xff,0xe0,0x00,0x00,0xff,0xff,0x1f
,0xff,0xff,0xff,0x80,0x0f,0xff,0xff,0xf0,0x00,0x00,0xff,0xff,0x1f
,0xfd,0xbf,0xff,0x80,0x0f,0xff,0xff,0xf8,0x00,0x00,0xff,0xfe,0x1f
,0xfd,0xbf,0xff,0x8f,0x0f,0xff,0xff,0xfc,0x00,0x70,0xff,0xfe,0x1f
,0xfe,0x3f,0xff,0x9f,0x8f,0xff,0xff,0xfe,0x01,0xf8,0xff,0xfe,0x3f
,0xfe,0x1f,0xff,0x9f,0xcf,0xff,0xff,0xff,0x81,0xfc,0xff,0xfc,0x3f
,0xff,0x1f,0xff,0x9f,0xcf,0xff,0xff,0xff,0xc1,0xfc,0xff,0xfc,0x7f
,0xff,0x0f,0xff,0x9f,0xcf,0xff,0xff,0xff,0xe1,0xfc,0xff,0xf8,0x7f
,0xff,0x0f,0xff,0x9f,0x9f,0xff,0xff,0xff,0xf0,0xf9,0xff,0xf8,0x7f
,0xff,0x87,0xff,0xc7,0x1f,0xff,0xff,0xff,0xf8,0x71,0xff,0xf0,0xff
,0xff,0x87,0xff,0xe0,0x3f,0xff,0xff,0xff,0xfc,0x03,0xff,0xf0,0xff
,0xff,0xc3,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x07,0xff,0xe1,0xff
,0xff,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xff
,0xff,0xe1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xff
,0xff,0xf0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x87,0xff
,0xff,0xf8,0x7f,0xff,0xff,0xe0,0x00,0x03,0xff,0xff,0xff,0x07,0xff
,0xff,0xf8,0x7f,0xff,0xfe,0x1f,0xff,0xfc,0x3f,0xff,0xff,0x0f,0xff
,0xff,0xfc,0x3f,0xff,0xf1,0xff,0xff,0xff,0xc7,0xff,0xfe,0x1f,0xff
,0xff,0xfe,0x1f,0xff,0x8f,0xf0,0x00,0x07,0xf8,0xff,0xfc,0x3f,0xff
,0xff,0xff,0x0f,0xfe,0x3f,0x00,0x00,0x00,0x7e,0x3f,0xf8,0x7f,0xff
,0xff,0xff,0x07,0xf9,0xf8,0x00,0x00,0x00,0x0f,0xcf,0xf0,0x7f,0xff
,0xff,0xff,0x83,0xf3,0xc0,0x00,0x00,0x00,0x01,0xf7,0xe0,0xff,0xff
,0xff,0xff,0xc1,0xcf,0x00,0x00,0x00,0x00,0x00,0x79,0xc1,0xff,0xff
,0xff,0xff,0xe0,0x3c,0x00,0x00,0x00,0x00,0x00,0x1e,0x03,0xff,0xff
,0xff,0xff,0xf8,0x38,0x00,0x00,0x00,0x00,0x00,0x0e,0x0f,0xff,0xff
,0xff,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff,0xff
,0xff,0xff,0xfa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0xff,0xff
,0xff,0xff,0xf7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0xff,0xff
,0xff,0xff,0xee,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3b,0xff,0xff
,0xff,0xff,0xc4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1d,0xff,0xff
,0xff,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0xff,0xff
,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xff
,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xff
,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xff
,0xff,0xfc,0x00,0x1f,0xff,0xff,0xff,0xff,0xff,0xf8,0x00,0x1f,0xff
,0xff,0xf8,0x00,0x3f,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x0f,0xff
,0xff,0xf0,0x00,0x78,0xff,0xff,0xff,0xff,0xff,0x8e,0x00,0x07,0xff
,0xff,0xf0,0x00,0x70,0x7f,0xff,0xff,0xff,0xff,0x07,0x00,0x07,0xff
,0xff,0xec,0x00,0x60,0x3f,0xff,0xff,0xff,0xfe,0x03,0x00,0x03,0xff
,0xff,0xdc,0x00,0x60,0x3f,0xff,0xff,0xff,0xfe,0x03,0x00,0x01,0xff
,0xff,0xd8,0x00,0x60,0x3f,0xff,0xff,0xff,0xfe,0x03,0x00,0x01,0xff
,0xff,0xb8,0x00,0x70,0x7f,0xff,0xff,0xff,0xff,0x07,0x00,0x00,0xff
,0xff,0xb0,0x00,0x3d,0xff,0xff,0xff,0xff,0xff,0x9e,0x00,0x00,0xff
,0xff,0x70,0x00,0x1f,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x00,0x7f
,0xff,0x60,0x00,0x0f,0xff,0xff,0xff,0xff,0xff,0xf8,0x00,0x00,0x7f
,0xff,0x60,0x00,0x07,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x7f
,0xfe,0xe0,0x00,0x03,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0xbf
,0xfe,0xc0,0x00,0x01,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x01,0xbf
,0xfe,0xc0,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x01,0xbf
,0xfd,0x80,0x00,0x00,0x7f,0xff,0x80,0x00,0x00,0x00,0x00,0x01,0xdf
,0xfd,0x80,0x00,0x00,0x3f,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0xdf
,0xfd,0x80,0x00,0x00,0x1f,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0xdf
,0xfd,0x80,0x00,0x00,0x0f,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0xdf
,0xfb,0x00,0x00,0x00,0x07,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0xef
,0xfb,0x00,0x00,0x00,0x03,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x01,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x00,0x7f,0xff,0x80,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x00,0x3f,0xe3,0x80,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x00,0x1f,0xc1,0xc0,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x00,0x0f,0x80,0xc0,0x00,0x00,0x00,0x00,0x6f
,0xff,0x00,0x00,0x00,0x00,0x0f,0x80,0xc0,0x00,0x00,0x00,0x00,0x7f
,0xff,0x00,0x00,0x00,0x00,0x1f,0x80,0xc0,0x00,0x00,0x00,0x00,0x7f
,0xff,0x00,0x00,0x00,0x00,0x3f,0xc1,0xc0,0x00,0x00,0x00,0x00,0x7f
,0xfb,0x00,0x00,0x00,0x00,0x7f,0xf7,0x80,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x01,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x03,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x07,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x0f,0xff,0xf0,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x00,0x00,0x00,0x1f,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x6f
,0xfb,0x80,0x00,0x00,0x3f,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0xef
,0xfd,0x80,0x00,0x00,0x7f,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0xdf
,0xfd,0x80,0x00,0x00,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xdf
,0xfd,0x80,0x00,0x01,0xff,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0xdf
,0xfd,0xc0,0x00,0x03,0xff,0xfc,0x00,0x00,0x00,0x00,0x00,0x01,0xdf
,0xfe,0xc0,0x00,0x07,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x01,0xbf
,0xfe,0xc0,0x00,0x0f,0xff,0xff,0xff,0xff,0xff,0xe0,0x00,0x01,0xbf
,0xfe,0xe0,0x00,0x1f,0xff,0xff,0xff,0xff,0xff,0xf8,0x00,0x03,0xbf
,0xff,0x60,0x00,0x3f,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x03,0x7f
,0xff,0x70,0x00,0x70,0xff,0xff,0xff,0xff,0xff,0x0e,0x00,0x07,0x7f
,0xff,0xb0,0x00,0x70,0x7f,0xff,0xff,0xff,0xfe,0x07,0x00,0x06,0xff
,0xff,0xb0,0x00,0x60,0x3f,0xff,0xff,0xff,0xfe,0x03,0x00,0x06,0xff
,0xff,0xd8,0x00,0x60,0x3f,0xff,0xff,0xff,0xfe,0x03,0x00,0x0d,0xff
,0xff,0xdc,0x00,0x60,0x7f,0xff,0xff,0xff,0xfe,0x07,0x00,0x1d,0xff
,0xff,0xec,0x00,0x70,0x7f,0xff,0xff,0xff,0xff,0x06,0x00,0x1b,0xff
,0xff,0xee,0x00,0x3f,0xff,0xff,0xff,0xff,0xff,0xfe,0x00,0x3b,0xff
,0xff,0xf6,0x00,0x1f,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x37,0xff
,0xff,0xf3,0x00,0x0f,0xff,0xff,0xff,0xff,0xff,0xf0,0x00,0x67,0xff
,0xff,0xfb,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xef,0xff
,0xff,0xfd,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xdf,0xff
,0xff,0xfe,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xbf,0xff
,0xff,0xfe,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x3f,0xff
,0xff,0xff,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x7f,0xff
,0xff,0xff,0xb8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xff,0xff
,0xff,0xff,0xdc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1d,0xff,0xff
,0xff,0xff,0xef,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7b,0xff,0xff
,0xff,0xff,0xf3,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xe7,0xff,0xff
,0xff,0xff,0xf9,0xc0,0x00,0x00,0x00,0x00,0x00,0x01,0xcf,0xff,0xff
,0xff,0xff,0xfc,0xf0,0x00,0x00,0x00,0x00,0x00,0x07,0x9f,0xff,0xff
,0xff,0xff,0xff,0x70,0x00,0x00,0x00,0x00,0x00,0x0f,0x7f,0xff,0xff
,0xff,0xff,0xff,0x90,0x00,0x00,0x00,0x00,0x00,0x3c,0xff,0xff,0xff
,0xff,0xff,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0xfb,0xff,0xff,0xff
,0xff,0xff,0xff,0xf0,0x00,0x00,0x00,0x00,0x03,0xe7,0xff,0xff,0xff
,0xff,0xff,0xff,0xfc,0x00,0x00,0x00,0x00,0x0f,0x9f,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x0c,0x7f,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x01,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x0f,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0x80,0x00,0x00,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x0f,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};

#endif
/* FILE END */
