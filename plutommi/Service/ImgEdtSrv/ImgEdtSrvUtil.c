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
 * ImgEdtSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Image Edit Service internal data type definitions
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SRV_IES__
#include "ImgEdtSrvConfig.h"
#include "ImgEdtSrvStruct.h"

#include "mmi_rp_srv_filemanager_def.h"
#include "mmi_rp_srv_imgedt_def.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "app_mem_med.h"
#else
#include "med_utility.h"
#endif

typedef struct srv_ies_error_info_struct
{
    srv_ies_result  error;      // error code value
    mmi_str_id      strID;      // error string ID
} srv_ies_error_info_struct;


/*****************************************************************************
 * ERROR STRINGS
 *****************************************************************************/
const static srv_ies_error_info_struct g_srv_ies_error_table[] = 
{
    { SRV_IES_E_UNEXPECTED,             STR_GLOBAL_ERROR },
    { SRV_IES_E_INVALID_ARGS,           STR_GLOBAL_ERROR },
    { SRV_IES_E_NOT_ENOUGH_BUFFER,      STR_GLOBAL_NOT_ENOUGH_MEMORY },
    { SRV_IES_E_FILE_SIZE_TOO_LARGE,    STR_GLOBAL_UNSUPPORTED_FORMAT },
    { SRV_IES_E_FILE_WRITE_FAILED,      STR_ID_IES_ERR_CANNOT_WRITE_FILE },
#if defined(__LOW_COST_SUPPORT_COMMON__)
    { SRV_IES_E_FILE_ACCESS_DENIED,     STR_GLOBAL_ERROR },
#else
    { SRV_IES_E_FILE_ACCESS_DENIED,     FMGR_FS_ACCESS_DENIED_TEXT },
#endif
    { SRV_IES_E_RESOLUTION_TOO_SMALL,   STR_ID_IES_ERR_IMAGE_TOO_SMALL },
    { SRV_IES_E_RESOLUTION_TOO_LARGE,   STR_ID_IES_ERR_IMAGE_TOO_LARGE },
    { SRV_IES_E_UNSUPPORTED_FORMAT,     STR_GLOBAL_UNSUPPORTED_FORMAT },
    { SRV_IES_E_NOT_IMPLEMENTED,        STR_GLOBAL_ERROR }
};

#define SRV_IES_ERROR_TABLE_SIZE        (sizeof(g_srv_ies_error_table) / sizeof(srv_ies_error_info_struct))


srv_ies_result srv_ies_util_error_get_result(CRESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_util_error_get_result: %x", result);

    //IES_LOG_PARAM(SRV_IES_UTIL_ERROR_GET_RESULT, 1, result);

    switch(result)
    {
    case CRES_TASK_COMPLETE:
        return SRV_IES_OK;
    case CERR_MEMALLOC_FAILED:
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    case CERR_ITEM_NOT_FOUND:
    case CERR_ILLEGAL_CALL:
        return SRV_IES_E_INVALID_ARGS;
    case CERR_FILE_NOT_FOUND:
    case CERR_FILE_READ_FAILED:
    case CERR_FILE_ACCESS_DENIED:
    case CERR_FILE_REMOVE_FAILED:
    case CERR_FILE_SEEK_FAILED:
        return SRV_IES_E_FILE_ACCESS_DENIED;
    case CERR_FILE_WRITE_FAILED:
    case CERR_FILE_FLUSH_FAILED:
        return SRV_IES_E_FILE_WRITE_FAILED;
    case CERR_INCOMPATIBLE_IMAGE:
    case CERR_UNSUPPORTED_IMAGE:
    case CERR_INCOMPLETE_IMAGE:
    case CERR_IMAGE_CORRUPT:
    case CERR_DATA_CORRUPT:
    case CERR_FILTER_CONNECTION_FAILED:
    case CERR_ILLEGAL_FILTER:
    case CERR_INVALID_FILTER_GRAPH:
    case CERR_FILTER_INCOMPATIBLE_COLOR_FORMAT:
    case CERR_DECODER_NOT_PREPARED:
    case CERR_DECODER_NOT_PARSED:
    case CERR_RAJPEG_NO_SOI_MARKER:
    case CERR_RAJPEG_NUM_COMPONENTS:
    case CERR_RAJPEG_TOO_MANY_COEFFS:
    case CERR_RAJPEG_MISSING_RESTART:
    case CERR_RAJPEG_NO_EOI_MARKER:
    case CERR_RAJPEG_NOT_ENOUGH_DATA:
    case CERR_RAJPEG_JFIF_LENGTH:
    case CERR_RAJPEG_JFIF_SOS:
    case CERR_RAJPEG_42:
    case CERR_RAJPEG_43:
    case CERR_RAJPEG_JFIF_42:
        return SRV_IES_E_UNSUPPORTED_FORMAT;
    default:
        return SRV_IES_E_UNEXPECTED;
    }
}

mmi_str_id srv_ies_util_error_get_string(srv_ies_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //IES_LOG_PARAM(SRV_IES_UTIL_ERROR_GET_STRING, 1, result);

    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_util_error_get_string: %x", result);

    for(index = 0; index < SRV_IES_ERROR_TABLE_SIZE; index++)
    {
        if (g_srv_ies_error_table[index].error == result)
        {
            return g_srv_ies_error_table[index].strID;
        }
    }
    
    return STR_GLOBAL_ERROR;
}


/* see ImgEdtSrvGpro.h for interface documentation */
MMI_BOOL srv_ies_util_is_suffix_supported(const WCHAR *pPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT                     result;
    CTImageFormat               format;
    MMI_BOOL                    unused;
    U8                          *pHeap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //IES_LOG_PARAM(SRV_IES_UTIL_IS_SUFFIX_SUPPORTED, 1, pPath);

    unused = MMI_FALSE;
    pHeap  = NULL;
    if(!is_caps_engine_inited())
    {
        // initialize an very small utility heap
        unused = MMI_TRUE;

#ifdef __COSMOS_MMI_PACKAGE__
        pHeap = applib_asm_alloc_anonymous(SRV_IES_UTIL_MAX_HEAP_SIZE);
#else
        pHeap = med_alloc_ext_mem_cacheable(SRV_IES_UTIL_MAX_HEAP_SIZE);
#endif  //__COSMOS_MMI_PACKAGE__
       
        caps_engine_init(pHeap, SRV_IES_UTIL_MAX_HEAP_SIZE);
    }

    result = caps_getImageTypeFromExt((const S_DCHAR*)pPath, &format);

    if(unused)
    {
        caps_engine_deinit();

#ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_anonymous(pHeap);
#else
        med_free_ext_mem(&pHeap);
#endif  // __COSMOS_MMI_PACKAGE__
    }

    if (CFAILED(result))
    {
        return MMI_FALSE;
    }

    if (format != IMAGE_FORMAT_JPEG)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_util_is_file_supported(const WCHAR *pPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT                     capsResult;
    U8                          *pHeap;
    CTFile                      *pSource;
    GDI_RESULT                  gdiResult;
    CTImageFormat               format;
    S32                         srcWidth;
    S32                         srcHeight;
    MMI_BOOL                    unused;
    CTSession                   session;
    CTImageInfo                 *pInfo;
    CTbool                      isProg;
    srv_ies_result              iesResult;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //IES_LOG_PARAM(SRV_IES_UTIL_IS_FILE_SUPPRRTED, 1, pPath);

    unused = MMI_FALSE;
    pHeap  = NULL;
    if(!is_caps_engine_inited())
    {
        // initialize an very small utility heap
        unused = MMI_TRUE;

#ifdef __COSMOS_MMI_PACKAGE__
        pHeap = applib_asm_alloc_anonymous(SRV_IES_UTIL_MAX_HEAP_SIZE);
#else
        pHeap = med_alloc_ext_mem_cacheable(SRV_IES_UTIL_MAX_HEAP_SIZE);
#endif  //__COSMOS_MMI_PACKAGE__

        caps_engine_init(pHeap, SRV_IES_UTIL_MAX_HEAP_SIZE);
    }

    pSource = NULL;
    session = NULL;
    pInfo   = NULL;
    do
    {
        // For CAPS capability, we only support JPEG editing.
        // (PNG and BMP would consume too much memory for full-res editing)
        capsResult = oslfile_open((const S_DCHAR*)pPath, FOF_ACCESS_READ, &pSource);
        if (CFAILED(capsResult))
        {
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }
        
        capsResult = caps_getImageTypeFromHdrFileHandle(pSource, &format);
        if (CFAILED(capsResult))
        {
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }

        if (format != IMAGE_FORMAT_JPEG)
        {
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }

        // Extra GDI size check; we use GDI because
        // if we open file with CAPS, we may need larger heap.
        // This 10x10 limitation is used to prevent extreme conditions like 10240x1
        gdiResult = gdi_image_get_dimension_file((S8*)pPath, &srcWidth, &srcHeight);
        if(GDI_SUCCEED != gdiResult)
        {
            kal_trace(MOD_IES, TRACE_GROUP_2, "Unsupported due to fail to check size with GDI");
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }
        else
        {
            // Check minimum dimension
            if((srcWidth * srcHeight)  < (SRV_IES_MIN_EDITABLE_WIDTH * SRV_IES_MIN_EDITABLE_HEIGHT))
            {
                kal_trace(MOD_IES, TRACE_GROUP_2, "Unsupported due to size too small");
                iesResult = SRV_IES_E_RESOLUTION_TOO_SMALL;
                break;
            }

            // Check maximum dimension
            if((srcWidth * srcHeight)  > (SRV_IES_MAX_EDITABLE_WIDTH * SRV_IES_MAX_EDITABLE_HEIGHT))
            {
                kal_trace(MOD_IES, TRACE_GROUP_2, "Unsupported due to size too large");
                iesResult = SRV_IES_E_RESOLUTION_TOO_LARGE;
                break;
            }

            // Check max Mega Pixel support (mainly for JPEG images)
            if(((kal_int32)(srcWidth * srcHeight / 1000000.0f)) > SRV_IES_JPEG_MAX_MEGA_PIXEL)
            {
                kal_trace(MOD_IES, TRACE_GROUP_2, "Unsupported due to size too large");

                iesResult = SRV_IES_E_RESOLUTION_TOO_LARGE;
                break;
            }

            // Check max save dimension
            if ((srcWidth > SRV_IES_JPEG_MAX_SAVE_WIDTH) || (srcHeight > SRV_IES_JPEG_MAX_SAVE_HEIGHT))
            {
                iesResult = SRV_IES_E_RESOLUTION_TOO_LARGE;
                break;
            }
        }

        oslfile_seek(pSource, 0, OSLFILE_SEEK_SET);

        if (oslfile_size(pSource) > SRV_IES_JPEG_MAX_FILE_SIZE)
        {
            iesResult = SRV_IES_E_FILE_SIZE_TOO_LARGE;
            break;
        }

        capsResult = caps_newSessionWithFileHandle(pSource, IMAGE_FORMAT_JPEG, &session);
        if (CFAILED(capsResult))
        {
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }

        caps_uthSetPrefetchFlag(session, 0);

        capsResult = caps_getSourceImageInfo(session, &pInfo);
        if (CFAILED(capsResult))
        {
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }

        isProg = false;
        capsResult = caps_getImageInfoField(pInfo, IIF_ISPROGRESSIVE, (CTint32*)&isProg);
        if (CFAILED(capsResult))
        {
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }

        if (isProg && ((srcWidth * srcHeight) > (SRV_IES_JPEG_MAX_PROG_WIDTH * SRV_IES_JPEG_MAX_PROG_HEIGHT)))
        {
            iesResult = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }

        iesResult = SRV_IES_OK;
    } while(0);

    if (NULL != pInfo)
    {
        caps_destroyImageInfo(pInfo);
        pInfo = NULL;
    }

    if (NULL != session)
    {
        caps_destroySession(session);
        session = NULL;
    }

    if(pSource)
    {
        oslfile_close(pSource);
        pSource = NULL;
    }

    if(unused)
    {
        caps_engine_deinit();

#ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_anonymous(pHeap);
#else
        med_free_ext_mem(&pHeap);
#endif  // __COSMOS_MMI_PACKAGE__
    }

    return iesResult;
}


srv_ies_result srv_ies_util_fit_bbox(S32  bboxWidth,
                                     S32  bboxHeight,
                                     S32  srcWidth,
                                     S32  srcHeight,
                                     S32  *pOutputX,
                                     S32  *pOutputY,
                                     S32  *pOutputW,
                                     S32  *pOutputH)
{
    CTSize     scrsize;
    CTSize     imgsize;
    CTRect     destRect;
    CTRect     output;
    CTuint32   wFactor;
    CTuint32   hFactor;

    scrsize.w = bboxWidth;
    scrsize.h = bboxHeight;
    imgsize.w = srcWidth;
    imgsize.h = srcHeight;

    if ((imgsize.w < scrsize.w) && (imgsize.h < scrsize.h))
    {
        output.w = (CTint32)(((CTfloat) imgsize.w));
        output.h = (CTint32)(((CTfloat) imgsize.h)); 

        output.x = (scrsize.w - output.w) / 2;
        output.y = (scrsize.h - output.h) / 2;

        destRect.x = output.x;
        destRect.y = output.y;
        destRect.w = output.w;
        destRect.h = output.h;
    }
    else
    {
        output.w = imgsize.w;
        output.h = imgsize.h;

        wFactor = (CTint32)(((CTuint32)(scrsize.w << 16)) / output.w);
        hFactor = (CTint32)(((CTuint32)(scrsize.h << 16)) / output.h);

        if (hFactor < wFactor)
        {
            output.h = scrsize.h;
            output.w = (imgsize.w * hFactor + 32768) >> 16;    

            if (output.w > scrsize.w)
            {
                output.w = scrsize.w;
            }

            if(output.w < 1)
            {
                output.w = 1;
            }

            if((imgsize.w / output.w) != (imgsize.h / output.h))
            {
                output.h = imgsize.h / (imgsize.w / output.w);
            }

            if (output.h > scrsize.h)
            {
                output.h = scrsize.h;
            }
        }
        else 
        {
            output.w = scrsize.w;
            output.h = (CTuint32)((output.h * wFactor + 32768) >> 16);

            if (output.h > scrsize.h)
            {
                output.h = scrsize.h;
            }

            if(output.h < 1)
            {
                output.h = 1;
            }

            if((imgsize.w / output.w) != (imgsize.h / output.h))
            {
                output.w = imgsize.w / (imgsize.h / output.h);
            }
        
            if (output.w > scrsize.w)
            {
                output.w = scrsize.w;
            }
        }

        output.x = (scrsize.w - output.w + 1) >> 1;
        if( (output.x & 0x01) != 0 )
        {
            output.x--;
        }

        output.y = (scrsize.h - output.h + 1) >> 1;
        if( (output.y & 0x01) != 0 )
        {
            output.y--;
        }

        destRect.x = output.x;
        destRect.y = output.y;
        destRect.w = output.w;
        destRect.h = output.h;

    }

    *pOutputX = (bboxWidth  - destRect.w) / 2;
    *pOutputY = (bboxHeight - destRect.h) / 2;
    *pOutputW = destRect.w;
    *pOutputH = destRect.h;

    return SRV_IES_OK;
}

#endif  // __MMI_SRV_IES__
