/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   utility_feature_ctrl.c
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   utility feature control function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "kal_release.h"
#include "utility_comm_def.h"
#include "mm_comm_def.h"
#include "cache_sw.h"
#include "mmu.h"
#include "jpeg_enum.h"
#include "jpeg_decode_api.h"
#include "utility_core.h"

void UtlExtMemSwitchCachableRegion(P_UTL_SWITCH_CACHE_STRUCT pSwitchCache, P_UTL_SWITCH_CACHE_RESULT_STRUCT pRet)
{
    kal_bool Ret = KAL_FALSE;
#if (defined(__MTK_TARGET__)&&(defined(__ARM9_DCACHEABLE__)||defined(__DYNAMIC_SWITCH_CACHEABILITY__)))
    kal_uint32 BufferSize = pSwitchCache->Size;
    kal_uint32 *pMemAddr = pSwitchCache->pMemAddr;
    kal_bool CacheableFlag = pSwitchCache->CacheableFlag;
    kal_uint8   RemainBits;

    RemainBits =  (*pMemAddr & (0x1f));
    *pMemAddr &= (~0x1f);

    if((BufferSize%CPU_CACHE_LINE_SIZE) != 0)
    {
        BufferSize = ((BufferSize+CPU_CACHE_LINE_SIZE-1)/CPU_CACHE_LINE_SIZE)*CPU_CACHE_LINE_SIZE;
    }
    if(CacheableFlag == KAL_TRUE)
    {
        if(INT_QueryIsNonCachedRAM(*pMemAddr, BufferSize) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((void*)pMemAddr, BufferSize, PAGE_CACHEABLE);
            Ret = KAL_TRUE;
        }
    }
    else
    {
        if(INT_QueryIsCachedRAM(*pMemAddr, BufferSize) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((void*)pMemAddr, BufferSize, PAGE_NO_CACHE);
            Ret = KAL_TRUE;
        }
    }
    *pMemAddr |= RemainBits;
#endif  // __MTK_TARGET__ && (__ARM9_DCACHEABLE__ || __DYNAMIC_SWITCH_CACHEABILITY__)
    if (pRet != NULL) pRet->Ret = Ret;
}


void UtlJpegDecode(P_UTL_CLIP_STRUCT pClipInfo)
{
#if defined(JPG_DECODE)
    JPEG_DECODER_HANDLE JpegHandle;
    kal_int32  JpegDecResult;
    STFSAL JpegSrc;
    kal_uint32 ReadBufferSizeBest = 0, ReadBufferSizeMinimum = 0;
    kal_uint32 FsalCacheSizeBest = 0, FsalCacheSizeMinimum = 0;
    void *pReadBuffer = NULL;
    void *pFsalCacheAddr = NULL;
    kal_uint32 IntMemSizeBest = 0, IntMemSizeMinimum = 0;
    kal_uint32 ExtMemSizeBest = 0, ExtMemSizeMinimum = 0;
    kal_uint32 *pIntMemAddr = NULL;
    kal_uint32 *pExtMemAddr = NULL;
    UTL_SWITCH_CACHE_STRUCT CacheSwitch;
    UTL_SWITCH_CACHE_RESULT_STRUCT SwitchRet;
    kal_int32   RetValue;
    kal_uint8 CodecType = JPEG_CODEC_TYPE_HW;
    kal_uint32 ClipExtMemAddr;
    JPEG_CODEC_STATE_ENUM utl_jpeg_dec_state;
    
    /* create jpeg decoder handler */
    JpegDecResult = jpegDecGetDecoder(JPEG_CODEC_TYPE_HW, &JpegHandle);
    if (JPEG_STATUS_OK != JpegDecResult)
    {
        JpegDecResult = jpegDecGetDecoder(JPEG_CODEC_TYPE_SW, &JpegHandle);
        CodecType= JPEG_CODEC_TYPE_SW;
        if (JPEG_STATUS_OK != JpegDecResult)
        {
            ASSERT(0);
        }
    }
    
    /* set canvas window */
    if (MM_IMAGE_FORMAT_RGB565 == pClipInfo->ImageDstFormat)
    {
        if (JPEG_CODEC_TYPE_HW == CodecType)
        {
            /* switch to noncache */
            CacheSwitch.pMemAddr = (kal_uint32 *)&pClipInfo->ExtMemAddr;
            CacheSwitch.Size = pClipInfo->ExtMemSize;
            CacheSwitch.CacheableFlag = KAL_FALSE;
            UtlExtMemSwitchCachableRegion(&CacheSwitch, &SwitchRet);
            
            CacheSwitch.pMemAddr = (kal_uint32 *)&pClipInfo->ImageDstBuffer;
            CacheSwitch.Size = (pClipInfo->DstWidth*pClipInfo->DstHeight*2);
            CacheSwitch.CacheableFlag = KAL_FALSE;
            UtlExtMemSwitchCachableRegion(&CacheSwitch, &SwitchRet);
        }
        jpegDecSetRGBCanvas(JpegHandle,
            pClipInfo->ImageDstBuffer, pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_RGB_FORMAT_RGB565);
    }
    else if (MM_IMAGE_FORMAT_YUV420 == pClipInfo->ImageDstFormat)
    {
#if defined(MT6268T) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268H)
         /* mt6268 HW jpeg dec not support YUV420 */
         /* HDR */
#else
        if (JPEG_CODEC_TYPE_HW == CodecType)
        {
            /* switch to noncache */
            CacheSwitch.pMemAddr = (kal_uint32 *)&pClipInfo->ExtMemAddr;
            CacheSwitch.Size = pClipInfo->ExtMemSize;
            CacheSwitch.CacheableFlag = KAL_FALSE;
            UtlExtMemSwitchCachableRegion(&CacheSwitch, &SwitchRet);
            
            CacheSwitch.pMemAddr = (kal_uint32 *)&pClipInfo->ImageDstBuffer;
            CacheSwitch.Size = (pClipInfo->DstWidth*pClipInfo->DstHeight*3+1)/2;
            CacheSwitch.CacheableFlag = KAL_FALSE;
            UtlExtMemSwitchCachableRegion(&CacheSwitch, &SwitchRet);
        }
#endif
        
        JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                pClipInfo->ImageDstBuffer, 
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight,
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight + (pClipInfo->DstWidth*pClipInfo->DstHeight)/4,
                                pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_YUV420);
        /* mt6268 HW jpeg dec not support YUV420 */
        if (JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT == JpegDecResult)  
        {
            jpegDecReleaseDecoder(JpegHandle);
            JpegDecResult = jpegDecGetDecoder(JPEG_CODEC_TYPE_SW, &JpegHandle);
            CodecType= JPEG_CODEC_TYPE_SW;
            if (JPEG_STATUS_OK != JpegDecResult)
            {
                ASSERT(0);
            }
           
            JpegDecResult = jpegDecSetYUVCanvas(JpegHandle,
                                pClipInfo->ImageDstBuffer, 
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight,
                                pClipInfo->ImageDstBuffer + pClipInfo->DstWidth*pClipInfo->DstHeight + (pClipInfo->DstWidth*pClipInfo->DstHeight)/4,
                                pClipInfo->DstWidth, pClipInfo->DstHeight, JPEG_YUV_FORMAT_YUV420);
        }
    }
    else
    {
        ASSERT(0);
    }
    
    ClipExtMemAddr = pClipInfo->ExtMemAddr;

    /* Set source image */
    JpegDecResult = jpegDecQueryFileBuffer( JpegHandle,
        &ReadBufferSizeBest, &ReadBufferSizeMinimum,
        &FsalCacheSizeBest, &FsalCacheSizeMinimum);

    /* allocate file buffer */
    if (JPEG_CODEC_TYPE_HW == CodecType)
    {
        pReadBuffer = (void *)ClipExtMemAddr;
    }
    else
    {
        ClipExtMemAddr = ((ClipExtMemAddr + 3) & (~0x3));
        pReadBuffer = (void *)ClipExtMemAddr;
    }
    ClipExtMemAddr += ReadBufferSizeMinimum;
    
    if ((pReadBuffer == NULL) || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    }

    /* allocate fsal cache */
    if (JPEG_CODEC_TYPE_HW == CodecType)
    {
        pFsalCacheAddr = (void *)ClipExtMemAddr;
    }
    else
    {
        ClipExtMemAddr = ((ClipExtMemAddr + 3) & (~0x3));
        pFsalCacheAddr = (void *)ClipExtMemAddr;
    }
    ClipExtMemAddr += FsalCacheSizeMinimum;
    
    if ((pFsalCacheAddr == NULL) || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    } 
    
    /* open file */
    FSAL_Direct_SetRamFileSize(&JpegSrc, pClipInfo->ImageSrcBufferSize);
    RetValue = FSAL_Open(&JpegSrc, (void *)pClipInfo->ImageSrcBuffer, FSAL_ROMFILE);

    /* set source file */
    if (FSAL_OK != RetValue) 
    {
        // ERR_OPEN_FILE_FAILED;
        ASSERT(0);
    }
    else
    {
        JpegDecResult = jpegDecSetSourceFile(JpegHandle,
            &JpegSrc, pReadBuffer, ReadBufferSizeMinimum, pFsalCacheAddr, FsalCacheSizeMinimum);
    }

    if (JPEG_STATUS_OK != JpegDecResult)
    {
        ASSERT(0);
    }

    /* set callback function*/
    JpegDecResult = jpegDecSetCallbackFunction(JpegHandle, NULL);
    
    jpegDecSetClipWindow(JpegHandle,
        pClipInfo->DstRoiX, pClipInfo->DstRoiY, pClipInfo->RoiWidth, pClipInfo->RoiHeight);
    jpegDecSetOutputWindow(JpegHandle,
        (kal_int32)(pClipInfo->DstRoiX-pClipInfo->SrcRoiX),
        (kal_int32)(pClipInfo->DstRoiY-pClipInfo->SrcRoiY),
        pClipInfo->SrcWidth, pClipInfo->SrcHeight);
    jpegDecSetDecodeMode(JpegHandle, JPEG_DECODE_MODE_MAIN_IMAGE);
    
    /* query working buffer */
    JpegDecResult = jpegDecQueryWorkingMemory(JpegHandle,
        &IntMemSizeBest, &IntMemSizeMinimum,
        &ExtMemSizeBest, &ExtMemSizeMinimum);

    pIntMemAddr = (void *)ClipExtMemAddr;
    ClipExtMemAddr += IntMemSizeMinimum;
    
    if (NULL == pIntMemAddr || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    }

    if (JPEG_CODEC_TYPE_HW == CodecType)
    {
        pExtMemAddr = (void *)ClipExtMemAddr;
    }
    else
    {
        ClipExtMemAddr = ((ClipExtMemAddr + 3) & (~0x3));
        pExtMemAddr = (void *)ClipExtMemAddr;
    }
    ClipExtMemAddr += ExtMemSizeMinimum;

    if (NULL == pExtMemAddr || ((ClipExtMemAddr - pClipInfo->ExtMemAddr) > pClipInfo->ExtMemSize))
    {
        // ERR_FRAME_BUFFER_NOT_ENOUGH;
        ASSERT(0);
    }
    
    /* set working buffer */    
    JpegDecResult = jpegDecSetWorkingMemory(JpegHandle,
        pIntMemAddr, IntMemSizeMinimum,
        pExtMemAddr, ExtMemSizeMinimum);
    
    if (JPEG_STATUS_OK != JpegDecResult)
    {
        ASSERT(0);
    }
    
    /* run decoder*/
    JpegDecResult = jpegDecStart(JpegHandle);
    
    if (JPEG_STATUS_OK != jpegDecGetLastError(JpegHandle))
    {
        ASSERT(0);
    }
    
    /// the following is to simulate the behavior of message handler
    if (JPEG_CODEC_TYPE_HW == CodecType)
    {
        jpegDecGetDecoderState(JpegHandle, &utl_jpeg_dec_state);
        while (JPEG_CODEC_STATE_COMPLETE != utl_jpeg_dec_state)
        {
            switch (utl_jpeg_dec_state) 
            {
                case JPEG_CODEC_STATE_BUSY:
                    /// still decoding, nothing to do...
                    kal_sleep_task(1);
                    break;
                case JPEG_CODEC_STATE_PAUSED:
                    JpegDecResult = jpegDecResume(JpegHandle);
                    if (JPEG_STATUS_OK != JpegDecResult)
                    {
                        ASSERT(0);
                    }
                    break;
                case JPEG_CODEC_STATE_ERROR:
                    ASSERT(0);
                    break;            
                case JPEG_CODEC_STATE_COMPLETE:
                    // decode done
                    break;
                case JPEG_CODEC_STATE_FREE:
                    break;
                default:
                    break;
            }
            jpegDecGetDecoderState(JpegHandle, &utl_jpeg_dec_state);
        }
    }
    
    jpegDecReleaseDecoder(JpegHandle);
    FSAL_Close(&JpegSrc);

    if ((JPEG_CODEC_TYPE_HW == CodecType)&&(KAL_TRUE == pClipInfo->IsSwitchCachable)&&(KAL_TRUE == SwitchRet.Ret))
    {
        CacheSwitch.CacheableFlag = KAL_TRUE;
        UtlExtMemSwitchCachableRegion(&CacheSwitch, &SwitchRet);
    }
#endif /* defined(JPG_DECODE) */     
}

void UtlImageCLip(P_UTL_CLIP_STRUCT pClipInfo)
{
    if (MM_IMAGE_FORMAT_YUV420 == pClipInfo->ImageSrcFormat)
    {
        if (MM_IMAGE_FORMAT_YUV420 == pClipInfo->ImageDstFormat)
        {
            UtlYUVImageClip(pClipInfo, KAL_FALSE);
        }
        else if (MM_IMAGE_FORMAT_YUV400 == pClipInfo->ImageDstFormat)
        {
            UtlYUVImageClip(pClipInfo, KAL_TRUE);
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (MM_IMAGE_FORMAT_YUV400 == pClipInfo->ImageSrcFormat)
    {
        if (MM_IMAGE_FORMAT_YUV400 == pClipInfo->ImageDstFormat)
        {
            UtlYUVImageClip(pClipInfo, KAL_TRUE);
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (MM_IMAGE_FORMAT_JPEG == pClipInfo->ImageSrcFormat)
    {
        UtlJpegDecode(pClipInfo);
    }
    else
    {
        ASSERT(0);
    }
}

void UtlCalSad(P_UTL_SAD_PARA_STRUCT pSadPara, P_UTL_SAD_RESULT_STRUCT pSadResult)
{
    kal_uint8 *pImg1X, *pImg1XEnd, *pImg1Y, *pImg1YEnd, *pImg2X, *pImg2Y;
    kal_uint32 xoffset, yoffset1, yoffset2;
    kal_uint32 SadSum = 0, Count = 0;
    {
        pImg1Y = pSadPara->Img1;
        pImg1YEnd = pImg1Y + (pSadPara->RoiH-1)*pSadPara->Img1W;
        pImg2Y = pSadPara->Img2;
        yoffset1 = pSadPara->SubH*pSadPara->Img1W;
        yoffset2 = pSadPara->SubH*pSadPara->Img2W;
        xoffset = pSadPara->SubW;

        for (; pImg1Y <= pImg1YEnd; pImg1Y+=yoffset1, pImg2Y+=yoffset2)
        {
            pImg1X = pImg1Y;
            pImg2X = pImg2Y;
            pImg1XEnd = pImg1X + (pSadPara->RoiW-1);
            for (; pImg1X <= pImg1XEnd; pImg1X+=xoffset, pImg2X+=xoffset)
            {
                SadSum += UTL_ABS((kal_int32)*pImg2X - (kal_int32)*pImg1X);
                Count+=1;
            }
        }
    }
    pSadResult->Sum = SadSum;
    pSadResult->Count = Count;
}

void UtlYV12toNV21(UTL_IMAGE_TRANS_INFO_STRUCT* pImgInfo)
{
    kal_uint32 u_offset = pImgInfo->ImgWidth*pImgInfo->ImgHeight;
    kal_uint32 u_size = u_offset>>2;
    kal_uint32 v_offset = u_offset + u_size;
    kal_uint8 *src_u = (kal_uint8*)(pImgInfo->ImgAddr + u_offset);
    kal_uint8 *src_v = (kal_uint8*)(pImgInfo->ImgAddr + v_offset);
    kal_uint8 *buffer_uv = (kal_uint8*)pImgInfo->BufAddr;
	kal_int32 i;

    // convert format and store in buffer
    for(i=u_size; i>0; i--)
    {
        *buffer_uv++ = *src_u++;
        *buffer_uv++ = *src_v++;
    }

    // copy from buffer to source
    memcpy( (void*)(pImgInfo->ImgAddr+u_offset), (void*)pImgInfo->BufAddr, u_size*2);

}
void UtlNV21toYV12(UTL_IMAGE_TRANS_INFO_STRUCT* pImgInfo)
{
    kal_uint32 uv_offset = pImgInfo->ImgWidth*pImgInfo->ImgHeight;
    kal_uint32 u_size = uv_offset>>2;
    kal_uint8 *src_uv = (kal_uint8 *)(pImgInfo->ImgAddr + uv_offset);
    kal_uint8 *buffer_u = (kal_uint8 *)pImgInfo->BufAddr;
    kal_uint8 *buffer_v = (kal_uint8 *)(pImgInfo->BufAddr + u_size);
	kal_int32 i;

    // convert format and store in buffer
    for(i=u_size; i>0; i--)
    {
        *buffer_u++ = *src_uv++;
        *buffer_v++ = *src_uv++;
    }

    // copy from buffer to source
    memcpy((void*)(pImgInfo->ImgAddr + uv_offset), (void*)pImgInfo->BufAddr, u_size*2);
}

/*
 * YCbCr in Rec. 601 format
 * RGB values are in the range [0..255]
 *
 * [ Y  ]   [  16 ]    1    [  66   129    25 ]   [ R ]
 * [ Cb ] = [ 128 ] + --- * [ -38   -74   112 ] * [ G ]
 * [ Cr ]   [ 128 ]   256   [ 112   -94   -18 ]   [ B ]
 */
void UtlRGB888toYV12(UTL_IMAGE_TRANS_INFO_STRUCT* pImgInfo)
{
    kal_uint8 *data_rgb = (kal_uint8 *)(pImgInfo->ImgAddr);
    kal_int32 width = pImgInfo->ImgWidth;
    kal_int32 height = pImgInfo->ImgHeight;
    kal_uint8 *data_yuv = (kal_uint8 *)(pImgInfo->BufAddr);

    kal_int32 x, y, row_stride = width * 3;
    kal_uint8 *rgb, *Y, *U, *V;

    kal_uint8 u00, u01, u10, u11;
    kal_uint8 v00, v01, v10, v11;

    kal_int32 RtoYCoeff = (kal_int32) ( 66 * 256);
    kal_int32 GtoYCoeff = (kal_int32) (129 * 256);
    kal_int32 BtoYCoeff = (kal_int32) ( 25 * 256);

    kal_int32 RtoUCoeff = (kal_int32) (-38 * 256);
    kal_int32 GtoUCoeff = (kal_int32) (-74 * 256);
    kal_int32 BtoUCoeff = (kal_int32) (112 * 256);

    kal_int32 RtoVCoeff = (kal_int32) (112 * 256);
    kal_int32 GtoVCoeff = (kal_int32) (-94 * 256);
    kal_int32 BtoVCoeff = (kal_int32) (-18 * 256);

    /* Y plane */
    rgb = data_rgb;
    Y   = data_yuv;

    for (y = height; y-- > 0; ) 
    {
        for (x = width; x-- > 0; ) 
        {
            /* No need to saturate between 16 and 235 */
            *Y = 16 + ((32768 +
                        RtoYCoeff * *(rgb) +
                        GtoYCoeff * *(rgb + 1) +
                        BtoYCoeff * *(rgb + 2)) >> 16);
            Y++;
            rgb += 3;
        }
    }

    /* U and V planes */
    rgb = data_rgb;
    U   = data_yuv + (width*height);
    V   = data_yuv + (width*height + ((width*height)/4));

    for (y = height / 2; y-- > 0; ) 
    {
        for (x = width / 2; x-- > 0; ) 
        {
            /* No need to saturate between 16 and 240 */
            u00 = 128 + ((32768 +
                        RtoUCoeff * *(rgb) +
                        GtoUCoeff * *(rgb + 1) +
                        BtoUCoeff * *(rgb + 2)) >> 16);
            u01 = 128 + ((32768 +
                        RtoUCoeff * *(rgb + 3) +
                        GtoUCoeff * *(rgb + 4) +
                        BtoUCoeff * *(rgb + 5)) >> 16);
            u10 = 128 + ((32768 +
                        RtoUCoeff * *(rgb + row_stride) +
                        GtoUCoeff * *(rgb + row_stride + 1) +
                        BtoUCoeff * *(rgb + row_stride + 2)) >> 16);
            u11 = 128 + ((32768 +
                        RtoUCoeff * *(rgb + row_stride + 3) +
                        GtoUCoeff * *(rgb + row_stride + 4) +
                        BtoUCoeff * *(rgb + row_stride + 5)) >> 16);
            *U++ = (2 + u00 + u01 + u10 + u11) >> 2;

            v00 = 128 + ((32768 +
                        RtoVCoeff * *(rgb) +
                        GtoVCoeff * *(rgb + 1) +
                        BtoVCoeff * *(rgb + 2)) >> 16);
            v01 = 128 + ((32768 +
                        RtoVCoeff * *(rgb + 3) +
                        GtoVCoeff * *(rgb + 4) +
                        BtoVCoeff * *(rgb + 5)) >> 16);
            v10 = 128 + ((32768 +
                        RtoVCoeff * *(rgb + row_stride) +
                        GtoVCoeff * *(rgb + row_stride + 1) +
                        BtoVCoeff * *(rgb + row_stride + 2)) >> 16);
            v11 = 128 + ((32768 +
                        RtoVCoeff * *(rgb + row_stride + 3) +
                        GtoVCoeff * *(rgb + row_stride + 4) +
                        BtoVCoeff * *(rgb + row_stride + 5)) >> 16);
            *V++ = (2 + v00 + v01 + v10 + v11) >> 2;

            rgb += 6;
        }

        rgb += row_stride;
    }
}

/*
 * YCbCr in Rec. 601 format
 * RGB values are in the range [0..255]
 *
 * [ R ]    1    [ 298      0    409 ]   [ Y -  16 ]
 * [ G ] = --- * [ 298   -100   -208 ] * [ U - 128 ]
 * [ B ]   256   [ 298    516      0 ]   [ V - 128 ]
 */
void UtlYV12toRGB888(UTL_IMAGE_TRANS_INFO_STRUCT* pImgInfo)
{
    kal_uint8 *data_yuv = (kal_uint8 *)(pImgInfo->ImgAddr);
    kal_int32 width = pImgInfo->ImgWidth;
    kal_int32 height = pImgInfo->ImgHeight;
    kal_uint8 *data_rgb = (kal_uint8 *)(pImgInfo->BufAddr);

    kal_int32 x, y, row_stride = width * 3;
    kal_uint8 *R, *G, *B, *Y, *U, *V;

    kal_int32 YtoRCoeff = (kal_int32) ( 298 * 256);
    kal_int32 UtoRCoeff = (kal_int32) (   0 * 256);
    kal_int32 VtoRCoeff = (kal_int32) ( 409 * 256);

    kal_int32 YtoGCoeff = (kal_int32) ( 298 * 256);
    kal_int32 UtoGCoeff = (kal_int32) (-100 * 256);
    kal_int32 VtoGCoeff = (kal_int32) (-208 * 256);

    kal_int32 YtoBCoeff = (kal_int32) (298 * 256);
    kal_int32 UtoBCoeff = (kal_int32) (516 * 256);
    kal_int32 VtoBCoeff = (kal_int32) (  0 * 256);

    /* R plane */
    R = data_rgb;
    G = data_rgb + 1;
    B = data_rgb + 2;
    Y = data_yuv;
    U = data_yuv + (width*height);
    V = data_yuv + (width*height + ((width*height)>>2));

    for (y = height/2; y-- > 0; )
    {
        for (x = width/2; x-- > 0; )
        {
            /* P00 */
            *R = UTL_CLIP8(
                 ((32768 + 
                   YtoRCoeff * (*(Y) -  16) +
                   UtoRCoeff * (*(U) - 128) +
                   VtoRCoeff * (*(V) - 128)) >> 16) );
            *G = UTL_CLIP8(
                 ((32768 + 
                   YtoGCoeff * (*(Y) -  16) +
                   UtoGCoeff * (*(U) - 128) +
                   VtoGCoeff * (*(V) - 128)) >> 16) );
            *B = UTL_CLIP8(
                 ((32768 + 
                   YtoBCoeff * (*(Y) -  16) +
                   UtoBCoeff * (*(U) - 128) +
                   VtoBCoeff * (*(V) - 128)) >> 16) );

            /* P01 */
            *(R+3) = UTL_CLIP8(
                     ((32768 + 
                       YtoRCoeff * (*(Y+1) -  16) +
                       UtoRCoeff * (*(U)   - 128) +
                       VtoRCoeff * (*(V)   - 128)) >> 16) );
            *(G+3) = UTL_CLIP8(
                     ((32768 + 
                       YtoGCoeff * (*(Y+1) -  16) +
                       UtoGCoeff * (*(U)   - 128) +
                       VtoGCoeff * (*(V)   - 128)) >> 16) );
            *(B+3) = UTL_CLIP8(
                     ((32768 + 
                       YtoBCoeff * (*(Y+1) -  16) +
                       UtoBCoeff * (*(U)   - 128) +
                       VtoBCoeff * (*(V)   - 128)) >> 16) );

            /* P10 */
            *(R+row_stride) = UTL_CLIP8(
                              ((32768 + 
                                YtoRCoeff * (*(Y+width) -  16) +
                                UtoRCoeff * (*(U)       - 128) +
                                VtoRCoeff * (*(V)       - 128)) >> 16) );
            *(G+row_stride) = UTL_CLIP8(
                              ((32768 + 
                                YtoGCoeff * (*(Y+width) -  16) +
                                UtoGCoeff * (*(U)       - 128) +
                                VtoGCoeff * (*(V)       - 128)) >> 16) );
            *(B+row_stride) = UTL_CLIP8(
                              ((32768 + 
                                YtoBCoeff * (*(Y+width) -  16) +
                                UtoBCoeff * (*(U)       - 128) +
                                VtoBCoeff * (*(V)       - 128)) >> 16) );

            /* P11 */
            *(R+row_stride+3) = UTL_CLIP8(
                                ((32768 + 
                                  YtoRCoeff * (*(Y+width+1) -  16) +
                                  UtoRCoeff * (*(U)         - 128) +
                                  VtoRCoeff * (*(V)         - 128)) >> 16) );
            *(G+row_stride+3) = UTL_CLIP8(
                                ((32768 + 
                                  YtoGCoeff * (*(Y+width+1) -  16) +
                                  UtoGCoeff * (*(U)         - 128) +
                                  VtoGCoeff * (*(V)         - 128)) >> 16) );
            *(B+row_stride+3) = UTL_CLIP8(
                                ((32768 + 
                                  YtoBCoeff * (*(Y+width+1) -  16) +
                                  UtoBCoeff * (*(U)         - 128) +
                                  VtoBCoeff * (*(V)         - 128)) >> 16) );

            R += 6;
            G += 6;
            B += 6;

            Y += 2;
            U += 1;
            V += 1;
        }
        R += row_stride;
        G += row_stride;
        B += row_stride;

        Y += width;
    }
}

MM_ERROR_CODE_ENUM UtlFeatureCtrl(UTL_FEATURE_ENUM FeatureId,
									void* pParaIn, void* pParaOut,kal_uint16 ParaOutLen)
{
	P_UTL_BILINEAR_RESIZER_STRUCT pUtlRisizerInfo = (P_UTL_BILINEAR_RESIZER_STRUCT) pParaIn;

	switch (FeatureId)
	{
	    case UTL_FEATURE_BILINEAR_RESIZER:
			UtlBilinearResizer(pUtlRisizerInfo);
		break;
        case UTL_FEATURE_RGB565_TO_GRAY:
            UtlRgb565ToGray((P_UTL_IMAGE_INFO_STRUCT)pParaIn);
        break;
        case UTL_FEATURE_IMAGE_CLIP:
            UtlImageCLip((P_UTL_CLIP_STRUCT)pParaIn);
        break;
        case UTL_FEATURE_JPEG_DECODE:
            UtlJpegDecode((P_UTL_CLIP_STRUCT)pParaIn);
        break;
        case UTL_FEATURE_CAL_SAD:
            UtlCalSad((P_UTL_SAD_PARA_STRUCT)pParaIn, (P_UTL_SAD_RESULT_STRUCT)pParaOut);
        break;
        case UTL_FEATURE_EXT_MEM_SWITCH_CACHE:
            UtlExtMemSwitchCachableRegion((P_UTL_SWITCH_CACHE_STRUCT)pParaIn, (P_UTL_SWITCH_CACHE_RESULT_STRUCT)pParaOut);
        break;		
        case UTL_FEATURE_NV21_TO_YV12:
            UtlNV21toYV12((P_UTL_IMAGE_TRANS_INFO_STRUCT)pParaIn);
        break;
        case UTL_FEATURE_YV12_TO_NV21:
            UtlYV12toNV21((P_UTL_IMAGE_TRANS_INFO_STRUCT)pParaIn);
        break;
        case UTL_FEATURE_RGB888_TO_YV12:
            UtlRGB888toYV12((P_UTL_IMAGE_TRANS_INFO_STRUCT)pParaIn);
        break;
        case UTL_FEATURE_YV12_TO_RGB888:
            UtlYV12toRGB888((P_UTL_IMAGE_TRANS_INFO_STRUCT)pParaIn);
        break;
		default:
            ASSERT(0);
	}
	return MM_ERROR_NONE;
}	/* UtlFeatureControl() */



