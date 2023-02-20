/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_LARGE_CONST
#define LV_ATTRIBUTE_LARGE_CONST
#endif

#ifndef LV_ATTRIBUTE_IMG__RETURN_ALPHA_25X21
#define LV_ATTRIBUTE_IMG__RETURN_ALPHA_25X21
#endif

const LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG__RETURN_ALPHA_25X21 uint8_t _return_alpha_25x21_map[] = {
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x11, 0xff, 0x06, 0x01, 0xff, 0x25, 0x01, 0xff, 0x23, 0x92, 0xff, 0x42, 0xa2, 0xff, 0xa4, 0x61, 0xff, 0x45, 0x31, 0xff, 0x06, 0x09, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xdb, 0x06, 0x19, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x45, 0x29, 0xff, 0xc4, 0x69, 0xff, 0x23, 0xa2, 0xff, 0xa2, 0xd2, 0xff, 0xa2, 0xca, 0xff, 0xa4, 0x61, 0xff, 0x25, 0x19, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x09, 0xff, 0x06, 0x11, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xdb, 0x06, 0x19, 0xa0, 
  0x06, 0x19, 0xff, 0x26, 0x21, 0xff, 0x45, 0x31, 0xff, 0x65, 0x49, 0xff, 0xe4, 0x79, 0xff, 0x62, 0xaa, 0xff, 0xe0, 0xe2, 0xff, 0x20, 0xfb, 0xff, 0xe1, 0xe2, 0xff, 0xe3, 0x79, 0xff, 0x65, 0x41, 0xff, 0x45, 0x31, 0xff, 0x45, 0x39, 0xff, 0x45, 0x39, 0xff, 0x45, 0x39, 0xff, 0x45, 0x39, 0xff, 0x45, 0x39, 0xff, 0x45, 0x31, 0xff, 0x26, 0x29, 0xff, 0x26, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xdb, 0x06, 0x19, 0xa0, 
  0x25, 0x19, 0xff, 0x65, 0x31, 0xff, 0xc4, 0x69, 0xff, 0x62, 0xaa, 0xff, 0xc1, 0xd2, 0xff, 0x00, 0xeb, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0x00, 0xeb, 0xff, 0x42, 0xa2, 0xff, 0x03, 0x82, 0xff, 0xe3, 0x71, 0xff, 0xe3, 0x79, 0xff, 0xe3, 0x79, 0xff, 0xe3, 0x79, 0xff, 0xe3, 0x79, 0xff, 0xe3, 0x79, 0xff, 0xc4, 0x69, 0xff, 0xa4, 0x51, 0xff, 0x45, 0x29, 0xff, 0x25, 0x11, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xdb, 0x06, 0x19, 0xa0, 
  0x84, 0x51, 0xff, 0x03, 0x82, 0xff, 0x82, 0xba, 0xff, 0xe0, 0xe2, 0xff, 0x00, 0xf3, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0x00, 0xf3, 0xff, 0xa1, 0xd2, 0xff, 0x81, 0xba, 0xff, 0x82, 0xb2, 0xff, 0x81, 0xba, 0xff, 0x81, 0xba, 0xff, 0x81, 0xba, 0xff, 0x81, 0xba, 0xff, 0x82, 0xba, 0xff, 0x62, 0xb2, 0xff, 0x62, 0xaa, 0xff, 0x23, 0x9a, 0xff, 0xc4, 0x71, 0xff, 0x45, 0x31, 0xff, 0x26, 0x19, 0xff, 0x06, 0x11, 0xdb, 0x06, 0x19, 0xa0, 
  0xa4, 0x61, 0xff, 0x42, 0xa2, 0xff, 0xc0, 0xda, 0xff, 0x00, 0xf3, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0xc1, 0xda, 0xff, 0xc1, 0xd2, 0xff, 0xa1, 0xca, 0xff, 0xa1, 0xca, 0xff, 0xa1, 0xca, 0xff, 0xa1, 0xca, 0xff, 0xa1, 0xca, 0xff, 0xa1, 0xca, 0xff, 0xc1, 0xd2, 0xff, 0xc1, 0xd2, 0xff, 0xc0, 0xd2, 0xff, 0x62, 0xb2, 0xff, 0xe4, 0x79, 0xff, 0x65, 0x41, 0xff, 0x26, 0x19, 0xdb, 0x06, 0x19, 0xa0, 
  0x65, 0x39, 0xff, 0xe4, 0x71, 0xff, 0x62, 0xaa, 0xff, 0xc0, 0xd2, 0xff, 0x00, 0xeb, 0xff, 0x20, 0xfb, 0xff, 0x20, 0xfb, 0xff, 0x40, 0xfb, 0xff, 0x00, 0xf3, 0xff, 0x62, 0xb2, 0xff, 0x23, 0x92, 0xff, 0x03, 0x8a, 0xff, 0x23, 0x8a, 0xff, 0x23, 0x8a, 0xff, 0x23, 0x8a, 0xff, 0x23, 0x8a, 0xff, 0x23, 0x8a, 0xff, 0x42, 0x9a, 0xff, 0x62, 0xaa, 0xff, 0xc0, 0xd2, 0xff, 0xc0, 0xda, 0xff, 0xa1, 0xca, 0xff, 0xe3, 0x79, 0xff, 0x45, 0x31, 0xdb, 0x06, 0x11, 0xa0, 
  0x25, 0x21, 0xff, 0x65, 0x49, 0xff, 0xe4, 0x71, 0xff, 0x43, 0x9a, 0xff, 0x82, 0xc2, 0xff, 0xc0, 0xda, 0xff, 0x00, 0xf3, 0xff, 0x20, 0xfb, 0xff, 0x01, 0xeb, 0xff, 0x23, 0x8a, 0xff, 0xa4, 0x59, 0xff, 0x85, 0x49, 0xff, 0x84, 0x51, 0xff, 0x84, 0x51, 0xff, 0x84, 0x51, 0xff, 0x84, 0x51, 0xff, 0x84, 0x51, 0xff, 0xa4, 0x59, 0xff, 0xe4, 0x79, 0xff, 0x43, 0xa2, 0xff, 0xa1, 0xca, 0xff, 0xe0, 0xe2, 0xff, 0x82, 0xba, 0xff, 0xc4, 0x79, 0xdb, 0x05, 0x09, 0xa0, 
  0x06, 0x19, 0xff, 0x26, 0x19, 0xff, 0x45, 0x29, 0xff, 0x84, 0x41, 0xff, 0xe3, 0x79, 0xff, 0x62, 0xaa, 0xff, 0xa1, 0xca, 0xff, 0x00, 0xeb, 0xff, 0xc1, 0xda, 0xff, 0xc4, 0x69, 0xff, 0x45, 0x29, 0xff, 0x26, 0x11, 0xff, 0x25, 0x21, 0xff, 0x25, 0x21, 0xff, 0x25, 0x21, 0xff, 0x25, 0x21, 0xff, 0x25, 0x21, 0xff, 0x25, 0x21, 0xff, 0x45, 0x29, 0xff, 0x84, 0x41, 0xff, 0x43, 0xa2, 0xff, 0xe0, 0xe2, 0xff, 0xe0, 0xe2, 0xff, 0x43, 0xaa, 0xdb, 0x64, 0x41, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x26, 0x19, 0xff, 0x25, 0x29, 0xff, 0x65, 0x41, 0xff, 0xa4, 0x61, 0xff, 0x03, 0x82, 0xff, 0x81, 0xba, 0xff, 0x82, 0xba, 0xff, 0xa4, 0x61, 0xff, 0x45, 0x29, 0xff, 0x06, 0x11, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x26, 0x19, 0xff, 0x25, 0x11, 0xff, 0xc4, 0x69, 0xff, 0x61, 0xb2, 0xff, 0x00, 0xf3, 0xff, 0xa1, 0xd2, 0xdb, 0x03, 0x82, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x26, 0x11, 0xff, 0x45, 0x21, 0xff, 0x85, 0x41, 0xff, 0xe3, 0x79, 0xff, 0x03, 0x82, 0xff, 0x84, 0x49, 0xff, 0x25, 0x29, 0xff, 0x06, 0x11, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x01, 0xff, 0x65, 0x39, 0xff, 0x03, 0x8a, 0xff, 0x00, 0xf3, 0xff, 0x00, 0xeb, 0xdb, 0x81, 0xc2, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x26, 0x21, 0xff, 0x65, 0x31, 0xff, 0x65, 0x39, 0xff, 0x45, 0x31, 0xff, 0x26, 0x21, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x11, 0xff, 0x25, 0x01, 0xff, 0xc4, 0x71, 0xff, 0x01, 0xf3, 0xff, 0x20, 0xfb, 0xdb, 0xe0, 0xe2, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x26, 0x21, 0xff, 0x26, 0x21, 0xff, 0x26, 0x21, 0xff, 0x26, 0x21, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x11, 0xff, 0x05, 0x01, 0xff, 0xa4, 0x69, 0xff, 0x01, 0xf3, 0xff, 0x20, 0xfb, 0xdb, 0x00, 0xeb, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x09, 0xff, 0x25, 0x11, 0xff, 0xe3, 0x79, 0xff, 0x00, 0xf3, 0xff, 0x00, 0xf3, 0xdb, 0xc0, 0xda, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x01, 0xff, 0x85, 0x51, 0xff, 0x42, 0x9a, 0xff, 0x00, 0xf3, 0xff, 0xe0, 0xe2, 0xdb, 0x62, 0xaa, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x26, 0x19, 0xff, 0x05, 0x01, 0xff, 0xe4, 0x81, 0xff, 0xc1, 0xd2, 0xff, 0x00, 0xf3, 0xff, 0x82, 0xc2, 0xdb, 0xa4, 0x61, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x06, 0x01, 0xff, 0x05, 0x01, 0xff, 0x25, 0x01, 0xff, 0x65, 0x39, 0xff, 0xe4, 0x79, 0xff, 0x82, 0xc2, 0xff, 0x00, 0xeb, 0xff, 0xc0, 0xd2, 0xff, 0x23, 0x9a, 0xdb, 0x25, 0x21, 0xa0, 
  0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x06, 0x19, 0xff, 0x45, 0x39, 0xff, 0x85, 0x51, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xa5, 0x61, 0xff, 0xc4, 0x69, 0xff, 0x03, 0x82, 0xff, 0x81, 0xc2, 0xff, 0xe0, 0xe2, 0xff, 0xe0, 0xe2, 0xff, 0x62, 0xa2, 0xff, 0xa4, 0x61, 0xdb, 0x06, 0x01, 0xa0, 
  0x06, 0x19, 0xfe, 0x06, 0x19, 0xfe, 0x06, 0x11, 0xfe, 0x06, 0x01, 0xfe, 0xa4, 0x69, 0xfe, 0x42, 0xa2, 0xfe, 0xa2, 0xca, 0xfe, 0xa1, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa2, 0xca, 0xfe, 0xa1, 0xca, 0xfe, 0xc1, 0xda, 0xfe, 0xe1, 0xe2, 0xfe, 0x00, 0xf3, 0xfe, 0xe0, 0xe2, 0xfe, 0x62, 0xb2, 0xfe, 0xa5, 0x61, 0xff, 0x25, 0x19, 0xda, 0x06, 0x19, 0x9f, 
  0x06, 0x19, 0xee, 0x06, 0x19, 0xee, 0x06, 0x11, 0xee, 0xe6, 0x00, 0xee, 0xe4, 0x79, 0xee, 0x81, 0xba, 0xee, 0x00, 0xeb, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xf3, 0xee, 0x00, 0xeb, 0xee, 0xe0, 0xe2, 0xee, 0xa2, 0xca, 0xee, 0x43, 0xa2, 0xee, 0xa4, 0x69, 0xef, 0x25, 0x29, 0xf2, 0xe6, 0x00, 0xcd, 0x06, 0x19, 0x96, 
  0x06, 0x19, 0xde, 0x06, 0x19, 0xde, 0x06, 0x09, 0xde, 0xe6, 0x00, 0xde, 0xe4, 0x81, 0xde, 0xa0, 0xca, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x20, 0xfb, 0xde, 0x00, 0xeb, 0xde, 0xa1, 0xc2, 0xde, 0x03, 0x7a, 0xde, 0x65, 0x31, 0xde, 0xe6, 0x00, 0xdf, 0x06, 0x11, 0xe2, 0x06, 0x19, 0xbf, 0x06, 0x19, 0x8c, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x11, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x25, 0xff, 0x92, 0x23, 0xff, 0xa2, 0x42, 0xff, 0x61, 0xa4, 0xff, 0x31, 0x45, 0xff, 0x09, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xdb, 0x19, 0x06, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x29, 0x45, 0xff, 0x69, 0xc4, 0xff, 0xa2, 0x23, 0xff, 0xd2, 0xa2, 0xff, 0xca, 0xa2, 0xff, 0x61, 0xa4, 0xff, 0x19, 0x25, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x09, 0x06, 0xff, 0x11, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xdb, 0x19, 0x06, 0xa0, 
  0x19, 0x06, 0xff, 0x21, 0x26, 0xff, 0x31, 0x45, 0xff, 0x49, 0x65, 0xff, 0x79, 0xe4, 0xff, 0xaa, 0x62, 0xff, 0xe2, 0xe0, 0xff, 0xfb, 0x20, 0xff, 0xe2, 0xe1, 0xff, 0x79, 0xe3, 0xff, 0x41, 0x65, 0xff, 0x31, 0x45, 0xff, 0x39, 0x45, 0xff, 0x39, 0x45, 0xff, 0x39, 0x45, 0xff, 0x39, 0x45, 0xff, 0x39, 0x45, 0xff, 0x31, 0x45, 0xff, 0x29, 0x26, 0xff, 0x19, 0x26, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xdb, 0x19, 0x06, 0xa0, 
  0x19, 0x25, 0xff, 0x31, 0x65, 0xff, 0x69, 0xc4, 0xff, 0xaa, 0x62, 0xff, 0xd2, 0xc1, 0xff, 0xeb, 0x00, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xeb, 0x00, 0xff, 0xa2, 0x42, 0xff, 0x82, 0x03, 0xff, 0x71, 0xe3, 0xff, 0x79, 0xe3, 0xff, 0x79, 0xe3, 0xff, 0x79, 0xe3, 0xff, 0x79, 0xe3, 0xff, 0x79, 0xe3, 0xff, 0x69, 0xc4, 0xff, 0x51, 0xa4, 0xff, 0x29, 0x45, 0xff, 0x11, 0x25, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xdb, 0x19, 0x06, 0xa0, 
  0x51, 0x84, 0xff, 0x82, 0x03, 0xff, 0xba, 0x82, 0xff, 0xe2, 0xe0, 0xff, 0xf3, 0x00, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xf3, 0x00, 0xff, 0xd2, 0xa1, 0xff, 0xba, 0x81, 0xff, 0xb2, 0x82, 0xff, 0xba, 0x81, 0xff, 0xba, 0x81, 0xff, 0xba, 0x81, 0xff, 0xba, 0x81, 0xff, 0xba, 0x82, 0xff, 0xb2, 0x62, 0xff, 0xaa, 0x62, 0xff, 0x9a, 0x23, 0xff, 0x71, 0xc4, 0xff, 0x31, 0x45, 0xff, 0x19, 0x26, 0xff, 0x11, 0x06, 0xdb, 0x19, 0x06, 0xa0, 
  0x61, 0xa4, 0xff, 0xa2, 0x42, 0xff, 0xda, 0xc0, 0xff, 0xf3, 0x00, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xda, 0xc1, 0xff, 0xd2, 0xc1, 0xff, 0xca, 0xa1, 0xff, 0xca, 0xa1, 0xff, 0xca, 0xa1, 0xff, 0xca, 0xa1, 0xff, 0xca, 0xa1, 0xff, 0xca, 0xa1, 0xff, 0xd2, 0xc1, 0xff, 0xd2, 0xc1, 0xff, 0xd2, 0xc0, 0xff, 0xb2, 0x62, 0xff, 0x79, 0xe4, 0xff, 0x41, 0x65, 0xff, 0x19, 0x26, 0xdb, 0x19, 0x06, 0xa0, 
  0x39, 0x65, 0xff, 0x71, 0xe4, 0xff, 0xaa, 0x62, 0xff, 0xd2, 0xc0, 0xff, 0xeb, 0x00, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x20, 0xff, 0xfb, 0x40, 0xff, 0xf3, 0x00, 0xff, 0xb2, 0x62, 0xff, 0x92, 0x23, 0xff, 0x8a, 0x03, 0xff, 0x8a, 0x23, 0xff, 0x8a, 0x23, 0xff, 0x8a, 0x23, 0xff, 0x8a, 0x23, 0xff, 0x8a, 0x23, 0xff, 0x9a, 0x42, 0xff, 0xaa, 0x62, 0xff, 0xd2, 0xc0, 0xff, 0xda, 0xc0, 0xff, 0xca, 0xa1, 0xff, 0x79, 0xe3, 0xff, 0x31, 0x45, 0xdb, 0x11, 0x06, 0xa0, 
  0x21, 0x25, 0xff, 0x49, 0x65, 0xff, 0x71, 0xe4, 0xff, 0x9a, 0x43, 0xff, 0xc2, 0x82, 0xff, 0xda, 0xc0, 0xff, 0xf3, 0x00, 0xff, 0xfb, 0x20, 0xff, 0xeb, 0x01, 0xff, 0x8a, 0x23, 0xff, 0x59, 0xa4, 0xff, 0x49, 0x85, 0xff, 0x51, 0x84, 0xff, 0x51, 0x84, 0xff, 0x51, 0x84, 0xff, 0x51, 0x84, 0xff, 0x51, 0x84, 0xff, 0x59, 0xa4, 0xff, 0x79, 0xe4, 0xff, 0xa2, 0x43, 0xff, 0xca, 0xa1, 0xff, 0xe2, 0xe0, 0xff, 0xba, 0x82, 0xff, 0x79, 0xc4, 0xdb, 0x09, 0x05, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x26, 0xff, 0x29, 0x45, 0xff, 0x41, 0x84, 0xff, 0x79, 0xe3, 0xff, 0xaa, 0x62, 0xff, 0xca, 0xa1, 0xff, 0xeb, 0x00, 0xff, 0xda, 0xc1, 0xff, 0x69, 0xc4, 0xff, 0x29, 0x45, 0xff, 0x11, 0x26, 0xff, 0x21, 0x25, 0xff, 0x21, 0x25, 0xff, 0x21, 0x25, 0xff, 0x21, 0x25, 0xff, 0x21, 0x25, 0xff, 0x21, 0x25, 0xff, 0x29, 0x45, 0xff, 0x41, 0x84, 0xff, 0xa2, 0x43, 0xff, 0xe2, 0xe0, 0xff, 0xe2, 0xe0, 0xff, 0xaa, 0x43, 0xdb, 0x41, 0x64, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x26, 0xff, 0x29, 0x25, 0xff, 0x41, 0x65, 0xff, 0x61, 0xa4, 0xff, 0x82, 0x03, 0xff, 0xba, 0x81, 0xff, 0xba, 0x82, 0xff, 0x61, 0xa4, 0xff, 0x29, 0x45, 0xff, 0x11, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x26, 0xff, 0x11, 0x25, 0xff, 0x69, 0xc4, 0xff, 0xb2, 0x61, 0xff, 0xf3, 0x00, 0xff, 0xd2, 0xa1, 0xdb, 0x82, 0x03, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x11, 0x26, 0xff, 0x21, 0x45, 0xff, 0x41, 0x85, 0xff, 0x79, 0xe3, 0xff, 0x82, 0x03, 0xff, 0x49, 0x84, 0xff, 0x29, 0x25, 0xff, 0x11, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x01, 0x06, 0xff, 0x39, 0x65, 0xff, 0x8a, 0x03, 0xff, 0xf3, 0x00, 0xff, 0xeb, 0x00, 0xdb, 0xc2, 0x81, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x21, 0x26, 0xff, 0x31, 0x65, 0xff, 0x39, 0x65, 0xff, 0x31, 0x45, 0xff, 0x21, 0x26, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x11, 0x06, 0xff, 0x01, 0x25, 0xff, 0x71, 0xc4, 0xff, 0xf3, 0x01, 0xff, 0xfb, 0x20, 0xdb, 0xe2, 0xe0, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x21, 0x26, 0xff, 0x21, 0x26, 0xff, 0x21, 0x26, 0xff, 0x21, 0x26, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x11, 0x06, 0xff, 0x01, 0x05, 0xff, 0x69, 0xa4, 0xff, 0xf3, 0x01, 0xff, 0xfb, 0x20, 0xdb, 0xeb, 0x00, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x09, 0x06, 0xff, 0x11, 0x25, 0xff, 0x79, 0xe3, 0xff, 0xf3, 0x00, 0xff, 0xf3, 0x00, 0xdb, 0xda, 0xc0, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x01, 0x06, 0xff, 0x51, 0x85, 0xff, 0x9a, 0x42, 0xff, 0xf3, 0x00, 0xff, 0xe2, 0xe0, 0xdb, 0xaa, 0x62, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x26, 0xff, 0x01, 0x05, 0xff, 0x81, 0xe4, 0xff, 0xd2, 0xc1, 0xff, 0xf3, 0x00, 0xff, 0xc2, 0x82, 0xdb, 0x61, 0xa4, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x06, 0xff, 0x01, 0x05, 0xff, 0x01, 0x25, 0xff, 0x39, 0x65, 0xff, 0x79, 0xe4, 0xff, 0xc2, 0x82, 0xff, 0xeb, 0x00, 0xff, 0xd2, 0xc0, 0xff, 0x9a, 0x23, 0xdb, 0x21, 0x25, 0xa0, 
  0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x19, 0x06, 0xff, 0x39, 0x45, 0xff, 0x51, 0x85, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x61, 0xa5, 0xff, 0x69, 0xc4, 0xff, 0x82, 0x03, 0xff, 0xc2, 0x81, 0xff, 0xe2, 0xe0, 0xff, 0xe2, 0xe0, 0xff, 0xa2, 0x62, 0xff, 0x61, 0xa4, 0xdb, 0x01, 0x06, 0xa0, 
  0x19, 0x06, 0xfe, 0x19, 0x06, 0xfe, 0x11, 0x06, 0xfe, 0x01, 0x06, 0xfe, 0x69, 0xa4, 0xfe, 0xa2, 0x42, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa1, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa2, 0xfe, 0xca, 0xa1, 0xfe, 0xda, 0xc1, 0xfe, 0xe2, 0xe1, 0xfe, 0xf3, 0x00, 0xfe, 0xe2, 0xe0, 0xfe, 0xb2, 0x62, 0xfe, 0x61, 0xa5, 0xff, 0x19, 0x25, 0xda, 0x19, 0x06, 0x9f, 
  0x19, 0x06, 0xee, 0x19, 0x06, 0xee, 0x11, 0x06, 0xee, 0x00, 0xe6, 0xee, 0x79, 0xe4, 0xee, 0xba, 0x81, 0xee, 0xeb, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xf3, 0x00, 0xee, 0xeb, 0x00, 0xee, 0xe2, 0xe0, 0xee, 0xca, 0xa2, 0xee, 0xa2, 0x43, 0xee, 0x69, 0xa4, 0xef, 0x29, 0x25, 0xf2, 0x00, 0xe6, 0xcd, 0x19, 0x06, 0x96, 
  0x19, 0x06, 0xde, 0x19, 0x06, 0xde, 0x09, 0x06, 0xde, 0x00, 0xe6, 0xde, 0x81, 0xe4, 0xde, 0xca, 0xa0, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xfb, 0x20, 0xde, 0xeb, 0x00, 0xde, 0xc2, 0xa1, 0xde, 0x7a, 0x03, 0xde, 0x31, 0x65, 0xde, 0x00, 0xe6, 0xdf, 0x11, 0x06, 0xe2, 0x19, 0x06, 0xbf, 0x19, 0x06, 0x8c, 
#endif
};

const LV_ATTRIBUTE_LARGE_CONST lv_img_dsc_t _return_alpha_25x21 = {
  .header.always_zero = 0,
  .header.w = 25,
  .header.h = 21,
  .data_size = 525 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = _return_alpha_25x21_map,
};
