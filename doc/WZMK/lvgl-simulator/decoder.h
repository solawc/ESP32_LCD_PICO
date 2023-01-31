#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include "wels/codec_api.h"
#include "wels/codec_def.h"
#include <stdint.h>
#include <stddef.h>

void Yuv420p2Rgb565(uint16_t *dst, uint8_t *yp, uint8_t *up, uint8_t*vp, size_t width, size_t height);
int OpenH264_Init(void);
int OpenH264_Decode(const unsigned char* pSrc, const int iSrcLen, unsigned char** ppDst, SBufferInfo* pDstInfo);
void OpenH264_GetOption(void* pOption);
void OpenH264_FlashFrame(unsigned char** ppDst, SBufferInfo* pDstInfo);
void OpenH264_Uninit(void);
#ifdef __cplusplus
}
#endif
