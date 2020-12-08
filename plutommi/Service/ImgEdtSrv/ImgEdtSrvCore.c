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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SRV_IES__
#include "ImgEdtSrvConfig.h"
#include "ImgEdtSrvStruct.h"
#include "gdi_include.h"

#if defined(__MTK_TARGET__)
#include "cache_sw.h"
#include "mmu.h"
#endif // __MTK_TARGET__

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined(__MTK_TARGET__)
   #undef __DYNAMIC_SWITCH_CACHEABILITY__
#endif

/*****************************************************************************
 * Global structure for logging
 *****************************************************************************/
srv_ies_log_struct   g_srv_ies_log_info[SRV_IES_LOG_MAX_LOG_COUNT];
kal_uint32           g_srv_ies_log_index = 0;


/*****************************************************************************
 * Reserve data handles
 *****************************************************************************/
DECLARE_STATIC_RESERVE_SLOT(srv_ies_image, 3);          // Allow at most 3 image handles
DECLARE_STATIC_RESERVE_SLOT(srv_ies_preview, 3);        // Allow at most 3 preview handles
DECLARE_STATIC_RESERVE_SLOT(srv_ies_doodle_info, 5);    // Allow at most 5 doodle handles


/*****************************************************************************
 * FUNCTIONS
 *****************************************************************************/

#define FUNC_GROUP_IMAGE

static srv_ies_image* _srv_ies_image_new(srv_ies_app_session    *pParent,
                                         CTSession              session,
                                         CTStream               *pStream,
                                         CTuint32               fileSize,
                                         srv_ies_meta_handle    hMeta,
                                         kal_bool               ownMeta,
                                         kal_bool               switchXY)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_image   *pImage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TYPED_ALLOC(pImage, srv_ies_image);
    ASSERT(NULL != pImage);

    pImage->pParent         = pParent;
    pImage->session         = session;
    pImage->pStream         = pStream;
    pImage->fileSize        = fileSize;
    pImage->hMeta           = hMeta;
    pImage->ownMeta         = ownMeta;
    pImage->orientation     = SRV_IES_ROT_0;
    pImage->rotation        = SRV_IES_ROT_0;
    pImage->extraMargin     = 0;
    pImage->switchXY        = switchXY;

    return pImage;
}


static void _srv_ies_image_delete(srv_ies_image *pImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_CHECK_IMAGE(pImage);

    // Should cleanup/finish all effect first
    ASSERT(NULL == pImage->clipArt); 
    ASSERT(NULL == pImage->pEffect);

    kal_trace(MOD_IES, TRACE_GROUP_2, "_srv_ies_image_delete with user count %d", pImage->userCount);

    if(pImage->session)
    {
        caps_destroySession(pImage->session);
	     pImage->session = NULL;
    }

    if (NULL != pImage->pStream)
    {
        ctstream_destroy(pImage->pStream);
        pImage->pStream = NULL;
    }

    if (KAL_TRUE == pImage->ownMeta)
    {
       srv_ies_meta_destroy(pImage->hMeta);
       pImage->hMeta    = NULL;
       pImage->ownMeta  = KAL_FALSE;
    }

    pImage->pParent = NULL;

    TYPED_FREE(pImage, srv_ies_image);
}


srv_ies_result srv_ies_image_create_from_file(srv_ies_app_session_handle    hApp,
                                              const WCHAR                   *pPath,
                                              srv_ies_meta_handle           hMeta,
                                              srv_ies_image_handle          *pHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTImageFormat       format;
    CTBuffer            *pBuffer;
    CTFile              *pSource;
    CTuint32            count;
    CTuint16			   orient;
    CTStream            *pStream;
    CTuint32            fileSize;
    srv_ies_meta_handle hCache;
    kal_bool            ownMeta;
    CTSession           session;
    CTSize              size;
    CTImageInfo         *pInfo;
    CTbool              isProg;
    srv_ies_result      error;
    kal_bool            switchXY;

    IES_LOG_SETUP();

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_CREATE_FROM_FILE, 4, hApp);

    oslfile_open((const S_DCHAR*)pPath, FOF_ACCESS_READ, &pSource);
    if (NULL == pSource)
    {
        IES_LOG_END(SRV_IES_E_FILE_ACCESS_DENIED);
        return SRV_IES_E_FILE_ACCESS_DENIED;
    }

    // Check if the file size is bigger than the supported size.
    fileSize = oslfile_size(pSource);
    if (fileSize > SRV_IES_JPEG_MAX_FILE_SIZE)
    {
        oslfile_close(pSource);

        IES_LOG_END(SRV_IES_E_FILE_SIZE_TOO_LARGE);
        return SRV_IES_E_FILE_SIZE_TOO_LARGE;
    }

#if 1
    caps_createBuffer(fileSize, &pBuffer);

    count = oslfile_read(pSource, pBuffer->data, pBuffer->size);
    ASSERT(count <= pBuffer->size);

	 orient = 0;  // Default value

    // Get the EXIF orientation
    exif_getImageOrientation(pBuffer, &orient);
    
    caps_destroyBuffer(pBuffer);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // 0

    oslfile_close(pSource);

    /*
     * Create the source stream for decoding. The buffer size is
     * specified by SRV_IES_STREAM_CHUNK_SIZE.
     */
    result = ctstream_createFileStreamEx((const S_DCHAR*)pPath,
                                         FOF_ACCESS_READ | FOF_MODE_BINARY, 
                                         SRV_IES_STREAM_CHUNK_SIZE,
                                         &pStream);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    /* Because we only support editing JPEG images,
     * we will check the image format firstly.
     */
    result = caps_getImageType(pStream, &format);
    if (CFAILED(result))
    {
        ctstream_destroy(pStream);

        IES_LOG_END(SRV_IES_E_UNSUPPORTED_FORMAT);
        return SRV_IES_E_UNSUPPORTED_FORMAT;
    }

    // Assert if the source is not a JPEG image.
    ASSERT(format == IMAGE_FORMAT_JPEG);

    hCache  = hMeta;
    ownMeta = KAL_FALSE;

    // Create Scalado's SPMO for accelerating the editing functionality.
    if ((NULL == hCache) && (SRV_IES_FEATURE_EDIT == hApp->feature))
    {
        ownMeta = KAL_TRUE;

        // Create a SPMO with the resolution (LCD_WIDTH, LCD_HEIGHT).
        error = srv_ies_meta_create_from_file(hApp,
                                              pPath,
                                              GDI_LCD_WIDTH,
                                              GDI_LCD_HEIGHT,
                                              &hCache);
        if (SRV_IES_OK != error)
        {
            ownMeta = KAL_FALSE;
            hCache = NULL;
        }
    }

    session = NULL;  // Default value for session

    // If we do have SPMO object, we can create a session with SPMO for fast decoding.
    if (NULL != hCache)
    {
        MEASURE_BEGIN();

        // Create a session with the SPMO object.
        result = caps_createSessionWithSpmo(pStream,
                                            format,
                                            hCache->pSPMO,
                                            SPMO_VERIFICATION_MODE_ENABLED,
                                            &session);
        MEASURE_END(caps_createSessionWithSpmo);
        if(CFAILED(result))
        {
            kal_trace(MOD_IES, TRACE_GROUP_2, "caps_spmoNewSessionWithFileHandle failed with %x", result);
            ctstream_seek(pStream, 0);
            session = NULL;
        }
        else
        {
            caps_uthSetSpmoDecodeMode(session, CAPS_DECODE_OPTIMIZE_QUALITY);
        }
    }

    // If the session is not created (i.e. No SPMO or some other reasons), we
    // will create a session without the SPMO object.
    if (NULL == session)
    {
        MEASURE_BEGIN();

        // Create a session without SPMO objects
        result = caps_createSession(pStream, format, &session);
        MEASURE_END(caps_createSession);
        if (CFAILED(result))
        {
            if (NULL != pStream)
            {
                ctstream_destroy(pStream);
            }

            IES_LOG_FAIL(result);
            IES_RET_FAIL(result);
        }
    }

    // Check if we can support the specified image
    pInfo = NULL;
    do
    {
        result = caps_getSourceImageSize(session, &size);
        if (CFAILED(result))
        {
            error = srv_ies_util_error_get_result(result);
            break;
        }

        if (hApp->feature == SRV_IES_FEATURE_EDIT)
        {
            if ((size.w * size.h) < (SRV_IES_MIN_EDITABLE_WIDTH * SRV_IES_MIN_EDITABLE_HEIGHT))
            {
                error = SRV_IES_E_RESOLUTION_TOO_SMALL;
                break;
            }
        
            if((size.w * size.h) > (SRV_IES_MAX_EDITABLE_WIDTH * SRV_IES_MAX_EDITABLE_HEIGHT))
            {
                error = SRV_IES_E_RESOLUTION_TOO_LARGE;
                break;
            }
        }

        if (((kal_int32)(size.w * size.h / 1000000.0f)) > SRV_IES_JPEG_MAX_MEGA_PIXEL)
        {
            error = SRV_IES_E_RESOLUTION_TOO_LARGE;
            break;
        }

        // Check max save dimension
        if ((size.w > SRV_IES_JPEG_MAX_SAVE_WIDTH) || (size.h > SRV_IES_JPEG_MAX_SAVE_HEIGHT))
        {
            error = SRV_IES_E_RESOLUTION_TOO_LARGE;
            break;
        }
            
        result = caps_getSourceImageInfo(session, &pInfo);
        if (CFAILED(result))
        {
            error = srv_ies_util_error_get_result(result);
            break;
        }

        isProg = false;
        result = caps_getImageInfoField(pInfo, IIF_ISPROGRESSIVE, (CTint32*)&isProg);
        if (CFAILED(result))
        {
            error = srv_ies_util_error_get_result(result);
            break;
        }

        // Currently, we can only support progressive JPEG image up to 720 x 720
        if (isProg && ((size.w * size.h) > (SRV_IES_JPEG_MAX_PROG_WIDTH * SRV_IES_JPEG_MAX_PROG_HEIGHT)))
        {
            error = SRV_IES_E_UNSUPPORTED_FORMAT;
            break;
        }

        caps_destroyImageInfo(pInfo);

        error = SRV_IES_OK;
    } while (0);

    if (SRV_IES_OK != error)
    {
        if (NULL != pInfo)
        {
            caps_destroyImageInfo(pInfo);
            pInfo = NULL;
        }
    
        caps_destroySession(session);

        if (NULL != pStream)
        {
            ctstream_destroy(pStream);
            pStream = NULL;
        }

        if (KAL_TRUE == ownMeta)
        {
            // Meta is created by ourself
            srv_ies_meta_destroy(hCache);
        }

        IES_LOG_END(error);
        return error;
    }

    MEASURE_BEGIN();
    caps_uthSetPrefetchFlag(session, 0);
    caps_uthSetRenderQuality(session, CAPS_RENDERMODE_NORMAL);
    caps_uthSetJpegDecodeMode(session, CAPS_DECODE_NORMAL);
    if(SRV_IES_FEATURE_EDIT == hApp->feature)
    {
        caps_uthSetRajpegCacheSize(session, SRV_IES_CAPS_RAJPEG_CACHE);
        
    }
    MEASURE_END(caps_uthControl);

    // Adjust the image according to the orientation angle.
    switch(orient)
    {
       case 2:
         caps_beginFlip(session);
         caps_setFlip(session, FLIP_HORIZONTAL);
         caps_endFlip(session);
         switchXY = KAL_FALSE;
         break;
       case 3:
         caps_beginRotate(session);
         caps_setRotate(session, ROTATE_TO_180);
         caps_endRotate(session);
         switchXY = KAL_FALSE;
         break;
       case 4:
         caps_beginFlip(session);
         caps_setFlip(session, FLIP_VERTICAL);
         caps_endFlip(session);
         switchXY = KAL_FALSE;
		   break;
       case 5:
         caps_beginRotate(session);
         caps_setRotate(session, ROTATE_TO_90);
         caps_endRotate(session);
         
		   caps_beginFlip(session);
         caps_setFlip(session, FLIP_HORIZONTAL);
         caps_endFlip(session);
         switchXY = KAL_TRUE;
         break;  
	   case 6:
         caps_beginRotate(session);
         caps_setRotate(session, ROTATE_TO_90);
         caps_endRotate(session);
         switchXY = KAL_TRUE;
         break;
       case 7:
         caps_beginFlip(session);
         caps_setFlip(session, FLIP_HORIZONTAL);
         caps_endFlip(session);

         caps_beginRotate(session);
         caps_setRotate(session, ROTATE_TO_90);
         caps_endRotate(session);
         switchXY = KAL_TRUE;
         break;
       case 8:
         caps_beginRotate(session);
         caps_setRotate(session, ROTATE_TO_270);
         caps_endRotate(session);
         switchXY = KAL_TRUE;
         break;
       default:
         switchXY = KAL_FALSE;
         break;
    }

    // Create the image handle with the related parameters.
    *pHandle = _srv_ies_image_new(hApp, session, pStream, fileSize, hCache, ownMeta, switchXY);
    if(NULL == *pHandle)
    {
        kal_trace(MOD_IES, TRACE_GROUP_2, "Can't allocate image handle!");

        caps_destroySession(session);

        if (NULL != pStream)
        {
            ctstream_destroy(pStream);
            pStream = NULL;
        }

        if (KAL_TRUE == ownMeta)
        {
            // Meta is created by ourself
            srv_ies_meta_destroy(hCache);
        }

        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }

    kal_trace(MOD_IES, TRACE_GROUP_2, "_srv_ies_image_new: created %x", *pHandle);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


MMI_BOOL srv_ies_is_image_handle_has_meta(srv_ies_image_handle hImage)
{
    if (hImage)
    {
        if (hImage->hMeta)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    return MMI_FALSE;
}


srv_ies_result srv_ies_image_set_meta_info(srv_ies_image_handle  hImage,
                                           srv_ies_meta_handle   hMeta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_SET_META_INFO, 2, hImage);

    IES_CHECK_IMAGE(hImage);

    if (NULL == hMeta)
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    ctstream_seek(hImage->pStream, 0);

    // Set the SPMO for the session. Because the upper layer may
    // need time to create SPMO or load SPMO from database, it 
    // case set the SPMO object when the preparation is ready.
    result = caps_setSourceImageWithSpmo(hImage->session,
                                         hImage->pStream,
                                         IMAGE_FORMAT_JPEG,
                                         hMeta->pSPMO,
                                         SPMO_VERIFICATION_MODE_ENABLED);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // Singify the session info have changed.
	 caps_signalSessionEvent(hImage->session, EVENT_SOURCEDATA_CHANGE);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_destroy(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_image_destroy %x", hImage);

    IES_LOG_BEGIN(SRV_IES_IMAGE_DESTROY, 1, hImage);

    // Check if there's running job. if there's one, cancel it.
    if(hImage->jobInfo.pCurrJob)
    {
        srv_ies_job_cancel(hImage->jobInfo.pCurrJob);
        hImage->jobInfo.pCurrJob = NULL;
    }

    // Check if we have any memory leakage
    IS_ANY_ALLOCATED(hImage, srv_ies_doodle_info);
    IS_ANY_ALLOCATED(hImage, srv_ies_preview);

    // Don't check for double destory
    _srv_ies_image_delete(hImage);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_app_session_handle srv_ies_image_get_parent_app_session(srv_ies_image_handle hImage)
{
    return hImage->pParent;
}


S32 srv_ies_image_get_user_counter(srv_ies_image_handle hImage)
{
    return hImage->userCount;
}


S32 srv_ies_image_increase_user_counter(srv_ies_image_handle hImage)
{
    // TODO: use interlocked_increment here to prevent race condition
    ++hImage->userCount;
    return hImage->userCount;
}


S32 srv_ies_image_decrease_user_counter(srv_ies_image_handle hImage)
{
    // TODO: use interlocked_increment here to prevent race condition
    --hImage->userCount;
    return hImage->userCount;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_get_source_size(srv_ies_image_handle   hImage,
                                             S32                    *pWidth,
                                             S32                    *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTSize  size;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_GET_SOURCE_SIZE, 3, hImage);

    IES_CHECK_IMAGE(hImage);

    // Check if the parameters are valid.
    if ((NULL == pWidth) || (NULL == pHeight))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    // Get the original source image size.
    result = caps_getSourceImageSize(hImage->session, &size);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // Adjust the image size according to the EXIF orienation.
    if (KAL_FALSE == hImage->switchXY)
    {
       *pWidth  = size.w;
       *pHeight = size.h;
    }
    else
    {
       *pWidth  = size.h;
       *pHeight = size.w;
    }

    IES_LOG_END(SRV_IES_E_INVALID_ARGS);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_crop(srv_ies_image_handle  hImage,
                                  S32                   left,
                                  S32                   top,
                                  S32                   width,
                                  S32                   height)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTRect  target;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_CROP, 5, hImage);

    IES_CHECK_IMAGE(hImage);

    // Check if the parameters are valid.
    if ((width < 10) || (height < 10) ||
        (width >= 16384) || (height >= 16384))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    // Setup the parameters for CAPs engine.
    target.x = left;
    target.y = top;
    target.w = width;
    target.h = height;

    // Apply the parameters for the session.
    result = caps_doCrop(hImage->session, target);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_image_get_current_size(srv_ies_image_handle  hImage,
                                              S32                   *pWidth,
                                              S32                   *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTSize  size;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_GET_CURRENT_SIZE, 3, hImage);

    IES_CHECK_IMAGE(hImage);

    // Check if the parameters are valid
    if ((NULL == pWidth) || (NULL == pHeight))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    // Current size are affected by the following factors:
    // 1. The zoom level
    // 2. Crop rectangle
    // 3. Rotation angle
    result = caps_getCurrentImageSize(hImage->session, &size);
    IES_RET_IF_FAIL(result);
   
    *pWidth  = size.w;
    *pHeight = size.h;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_undo(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_UNDO, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    // Undo the lastest effect
    result = caps_undo(hImage->session);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_render_buffer_async(srv_ies_image_handle               hImage,
                                                 void                               *pBuf,
                                                 U32                                bufSize,
                                                 U32                                width,
                                                 U32                                height,
                                                 U32                                pitch,
                                                 srv_ies_colorformat_enum           format,
                                                 srv_ies_async_callback_func_ptr    callback,
                                                 void                               *pUserData,
                                                 srv_ies_job_handle                 *pHJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTSize              target;
    CTImage             *pImage;
    CTIterator          *pItr;
    srv_ies_job_handle  hJob;
    MMI_BOOL            jobSent;

    IES_LOG_SETUP();

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_image_render_buffer_async on image %x", hImage);

    IES_LOG_BEGIN(SRV_IES_IMAGE_RENDER_BUFFER_ASYNC, 10, hImage);

    IES_CHECK_IMAGE(hImage);

    // Check if the parameters are valid
    if((NULL == pHJob) || (NULL == callback))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

 	 hJob = NULL;
    do
    {
        // Setup the target width and height
        target.w    = width;
        target.h    = height;

        // Setup the target buffer info
        hImage->buffer.size = bufSize;
        hImage->buffer.data = pBuf;

        MEASURE_BEGIN();

        // Create the image handle for rendering
        result = caps_createImage(&(hImage->buffer),
                                  target,
                                  pitch,
                                  _srv_ies_convert_ies_color_to_caps_color(format),
                                  &pImage);
        MEASURE_END(caps_createImage);
        if (CFAILED(result))
        {
            break;
        }

        MEASURE_BEGIN();

        // Render the image asynchronously by createing a iterator
        result = caps_renderAsRawToBuffer(hImage->session,
                                          pImage,
                                          CAPS_OUTPUT_PRESERVE_AR,
                                          &pItr);
        MEASURE_END(caps_renderAsRawToBuffer);
        if (CFAILED(result))
        {
            pImage->pixels = NULL;
            caps_destroyImage(pImage);
            break;
        }

        // Create a IES job to represent the rendering progress
        hJob = srv_ies_job_create(hImage->pParent,
                                  MOD_IES,
                                  SRV_IES_JOB_TYPE_RENDER_BUFFER,
                                  hImage,
                                  NULL,
                                  pItr,
                                  pImage,
                                  1,
                                  callback,
                                  pUserData);
        ASSERT(hJob != NULL);

        // Sen the job to the background IES task
        jobSent = srv_ies_job_send_request(hJob);
        if (MMI_FALSE == jobSent)
        {
            pImage->pixels = NULL;
            caps_destroyImage(pImage);
            caps_destroyIterator(pItr);
            break;
        }

        // Store the job handle for the caller
        *pHJob = hJob;

        IES_LOG_END(SRV_IES_OK);
        return SRV_IES_OK;
    } while(0);

    if (NULL != hJob)
    {
       srv_ies_job_destroy(hJob);
    }

    *pHJob = NULL;

    IES_LOG_END(SRV_IES_E_UNEXPECTED);
    return SRV_IES_E_UNEXPECTED;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_render_file_async(srv_ies_image_handle             hImage,
                                               const WCHAR                      *pPath,
                                               U32                              width,
                                               U32                              height,
                                               srv_ies_render_enum              option,
                                               srv_ies_async_callback_func_ptr  callback, 
                                               void                             *pUserData,
                                               srv_ies_job_handle               *pHJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTSize              target;
    CTuint32            chunkSize;
    CTStream            *pStream;
    CTIterator          *pItr;
    srv_ies_job_handle  hJob;
    kal_uint32          maxStep;
    MMI_BOOL            jobSent;

    IES_LOG_SETUP();

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_image_render_file_async on image %x", hImage);

    IES_LOG_BEGIN(SRV_IES_IMAGE_RENDER_FILE_ASYNC, 7, hImage);

    IES_CHECK_IMAGE(hImage);

    // Check if the parameters are valid
    if ((NULL == pHJob) || (NULL == pPath) || (NULL == callback))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    // Setup the target width and height
    target.w = width;
    target.h = height;

    // Setup the buffer size for the output stream. The ">> 5" is from our experiments.
    // The bigger the buffer size, the worse calcellation response during the encoding progress.
    chunkSize = (hImage->fileSize >> 5);
    if (chunkSize < 512)
    {
        chunkSize = 512;
    }

    // Create the output stream
    result = ctstream_createFileStreamEx((const S_DCHAR*)pPath,
                                         FOF_ACCESS_WRITE | FOF_MODE_BINARY, 
                                         chunkSize,
                                         &pStream);
    IES_RET_IF_FAIL(result);

    // Check if the user wans to keep the aspect ration
    if (SRV_IES_RENDER_KEEP_AR == option)
    {
        MEASURE_BEGIN();

        // Keep the aspect ratio for the output image
        result = caps_render(hImage->session, 
                             pStream, 
                             target, 
                             CAPS_OUTPUT_PRESERVE_AR, 
                             IMAGE_FORMAT_JPEG, 
                             &pItr);
        MEASURE_END(caps_render);
    }
    else
    {
        MEASURE_BEGIN();

        // Don't keep the aspect ratio for the output image
        result = caps_render(hImage->session, 
                             pStream, 
                             target, 
                             CAPS_OUTPUT_STRETCH, 
                             IMAGE_FORMAT_JPEG, 
                             &pItr);
        MEASURE_END(caps_render);
    }

    if(CFAILED(result))
    {
        ctstream_destroy(pStream);
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    do
    {
        // The IES task will process current job "maxStep" times before checking
        // for the higher priority jobs.
        if ((hImage->pParent->feature == SRV_IES_FEATURE_VIEW) || (chunkSize <= 1024))
        {
            maxStep = 1;
        }
        else
        {
            maxStep = SRV_IES_JOB_ITER_PER_STEP;
        }

        // Create the job handle
        hJob = srv_ies_job_create(hImage->pParent,
                                  MOD_IES,
                                  SRV_IES_JOB_TYPE_RENDER_FILE,
                                  hImage,
                                  (void*)pStream,
                                  pItr,
                                  (void*)pPath,
                                  maxStep,
                                  callback,
                                  pUserData);
        ASSERT(hJob != NULL);

        // Send the job to the background IES task
        jobSent = srv_ies_job_send_request(hJob);
        if (MMI_FALSE == jobSent)
        {
            caps_destroyIterator(pItr);
            ctstream_destroy(pStream);
            break;
        }

         // Store the job handle for the caller
        *pHJob = hJob;

        IES_LOG_END(SRV_IES_OK);
        return SRV_IES_OK;
    } while(0);

    if (NULL != hJob)
    {
       srv_ies_job_destroy(hJob);
    }

    *pHJob = NULL;

    IES_LOG_END(SRV_IES_E_UNEXPECTED);
    return SRV_IES_E_UNEXPECTED;
}


#define FUNC_GROUP_PREVIEW

static srv_ies_preview* _srv_ies_preview_new(srv_ies_image *pParent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_preview *pPreview;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TYPED_ALLOC(pPreview, srv_ies_preview);
    ASSERT(NULL != pPreview);

    pPreview->pParent           = pParent;
    pPreview->screen            = NULL;
    pPreview->buffer.data       = NULL;
    pPreview->buffer.size       = 0;
    pPreview->pAnim             = NULL;
    pPreview->animDst           = 1.0f;
    pPreview->pDoodleBuf        = NULL;

    kal_trace(MOD_IES, TRACE_GROUP_2, "_srv_ies_preview_new %x", pPreview);
 
    return pPreview;
}


static void _srv_ies_preview_delete(srv_ies_preview *pPreview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *pBuf;
    U32  bufSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "_srv_ies_preview_delete %x", pPreview);

    IES_CHECK_PREVIEW(pPreview);

    pBuf    = pPreview->buffer.data;
    bufSize = pPreview->buffer.size;

    // Must destroy asscociated animation before the screen itself.
    if(pPreview->pAnim)
    {
        caps_animationDestroy(pPreview->pAnim);
        pPreview->pAnim = NULL;
    }

    if(pPreview->screen)
    {
        caps_destroyScreen(pPreview->screen);
        pPreview->screen = NULL;
    }

    if (NULL != pPreview->pDoodleBuf)
    {
        caps_destroyImage(pPreview->pDoodleBuf);
        pPreview->pDoodleBuf = NULL;
    }

#if 0 //defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __DYNAMIC_SWITCH_CACHEABILITY__

    pPreview->pParent = NULL;

    TYPED_FREE(pPreview, srv_ies_preview);
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_create(srv_ies_image_handle      hImage,
                                      srv_ies_preview_handle    *pHPreview,
                                      U8                        *pBuf, 
                                      U32                       bufSize,
                                      U32                       width, 
                                      U32                       height, 
                                      U32                       pitch,
                                      srv_ies_colorformat_enum  format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT          result;
    CTSize           target;
    srv_ies_preview  *pPreview;
    CTRect           canvas;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_preview_create on image %x", hImage);

    IES_LOG_BEGIN(SRV_IES_PREVIEW_CREATE, 8, hImage);

    IES_CHECK_IMAGE(hImage);

    ASSERT(bufSize >= (height * pitch));

    // Check if the parameters are valid
    if((NULL == pHPreview) || (NULL == hImage))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

#if SRV_IES_CAPS_PREFETCH_ON
    // If the caller is image editor, we will not enable perfetch for saving memory.
    if(SRV_IES_FEATURE_EDIT != hImage->pParent->feature)
    {
        // Ehable prefetch for accelerating the decode progress.
        // When prefetch is on, CAPs will load the whole image into
        // memory for accelerating the decoding progress.
        caps_uthSetPrefetchFlag(hImage->session, 1);

        // Singify the session that the image info have been changed
	     caps_signalSessionEvent(hImage->session,
	                             EVENT_SOURCEDATA_CHANGE);
    }
#endif  // SRV_IES_CAPS_PREFETCH_ON

    // Setup target width and height
    target.w = width;
    target.h = height;

    // Allocate buffer for the preview handle
    pPreview = _srv_ies_preview_new(hImage);
    ASSERT(NULL != pPreview);

#if 0 //defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __DYNAMIC_SWITCH_CACHEABILITY__

    // Setup the target output buffer
    pPreview->buffer.data = pBuf;
    pPreview->buffer.size = bufSize;

    // Create the preview (i.e. CAPs screen) object
    result = caps_createScreen(hImage->session,
                               target,
                               _srv_ies_convert_ies_color_to_caps_color(format),
                               &pPreview->buffer,
                               &pPreview->screen);
    if(CFAILED(result))
    {
        _srv_ies_preview_delete(pPreview);
        *pHPreview = NULL;

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // Get the canvas area (i.e. zoom level 1x) being rendered
    result = caps_getScreenCanvasArea(pPreview->screen, &canvas);
    if(CFAILED(result))
    {
        _srv_ies_preview_delete(pPreview);
        *pHPreview = NULL;

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // Store the 1x image width and height
    pPreview->width1X  = canvas.w;
    pPreview->height1X = canvas.h;

    // Store the preview handle for the caller
    *pHPreview = pPreview;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_destroy(srv_ies_preview_handle hPreview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_DESTROY, 1, hPreview);

    _srv_ies_preview_delete(hPreview);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_set_zoom_level(srv_ies_preview_handle    hPreview,
                                              float                     level)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_SET_ZOOM_LEVEL, 2, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    // Set the desired zoom level
    result = caps_setZoom(hPreview->screen, level);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_preview_set_zoom_rect(srv_ies_preview_handle  hPreview, 
                                             S32                     left, 
                                             S32                     top,
                                             S32                     width, 
                                             S32                     height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTRect  target;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_SET_ZOOM_RECT, 5, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    // Setup the target info
    target.x = left;
    target.y = top;
    target.w = width;
    target.h = height;

    // Setup the zoom rectangle
    result = caps_setZoomRect(hPreview->screen, &target);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_get_screen_rect(srv_ies_preview_handle  hPreview, 
                                               S32                     *pLeft, 
                                               S32                     *pTop,
                                               S32                     *pWidth, 
                                               S32                     *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTPoint leftTop;
    CTPoint rightBot;
    CTSize  screen;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_GET_SCREEN_RECT, 5, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    if ((NULL == pLeft) || (NULL == pTop) || (NULL == pWidth) || (NULL == pHeight))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_getScreenSize(hPreview->screen, &screen);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // get left-top
    leftTop.x = 0;
    leftTop.y = 0;
    result = caps_coordScreenToCurrent(hPreview->screen, &leftTop);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // get right-bottom
    rightBot.x = screen.w;
    rightBot.y = screen.h;
    result = caps_coordScreenToCurrent(hPreview->screen, &rightBot);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // output
    *pLeft   = leftTop.x;
    *pTop    = leftTop.y;
    *pWidth  = rightBot.x - leftTop.x;
    *pHeight = rightBot.y - leftTop.y;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_set_pan_delta(srv_ies_preview_handle hPreview,
                                             S32                    deltaX,
                                             S32                    deltaY)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT    result;
    CTfloat    level;
    CTSize     size;
    CTPoint    point;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_SET_PAN_DELTA, 3, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    result = caps_getZoomPoint(hPreview->screen, &level, &point);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    result = caps_getCurrentImageSize(hPreview->pParent->session, &size);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    deltaX = (S32)(((deltaX * size.w) / (hPreview->width1X  * level)) + 0.5);
    deltaY = (S32)(((deltaY * size.h) / (hPreview->height1X * level)) + 0.5);

    point.x += deltaX;
    point.y += deltaY;

    result = caps_setZoomPoint(hPreview->screen, level, &point);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_set_zoom_and_pan(srv_ies_preview_handle  hPreview,
                                                float                   zoom,
                                                float                   panX,
                                                float                   panY)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_SET_ZOOM_AND_PAN, 4, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    result = caps_setZoom(hPreview->screen, zoom);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    result = caps_setPan(hPreview->screen, panX, panY);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_get_zoom_and_pan(srv_ies_preview_handle  hPreview,
                                                float                   *pLevel,
                                                float                   *pPanX,
                                                float                   *pPanY)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_GET_ZOOM_AND_PAN, 4, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    if ((NULL == pLevel) || (NULL == pPanX) || (NULL == pPanY))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_getZoom(hPreview->screen, pLevel);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }
    
    result = caps_getPan(hPreview->screen, pPanX, pPanY);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_preview_get_canvas_rect(srv_ies_preview_handle   hPreview, 
                                               S32                      *pLeft, 
                                               S32                      *pTop,
                                               S32                      *pWidth, 
                                               S32                      *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTRect  canvas;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_GET_CANVAS_RECT, 5, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    if ((NULL == pLeft) || (NULL == pTop) || (NULL == pWidth) || (NULL == pHeight))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_getScreenCanvasArea(hPreview->screen, &canvas);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    *pLeft   = canvas.x;
    *pTop    = canvas.y;
    *pWidth  = canvas.w;
    *pHeight = canvas.h;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_preview_get_current_size(srv_ies_preview_handle  hPreview,
                                                S32                     *pWidth,
                                                S32                     *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTfloat level;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_GET_CURRENT_SIZE, 3, hPreview);

    IES_CHECK_PREVIEW(hPreview);
    
    if ((NULL == pWidth) || (NULL == pHeight))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_getZoom(hPreview->screen, &level);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    *pWidth  = (S32)(hPreview->width1X  * level + 0.5f);
    *pHeight = (S32)(hPreview->height1X * level + 0.5f);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_preview_get_current_rect(srv_ies_preview_handle  hPreview, 
                                                S32                     *pLeft, 
                                                S32                     *pTop,
                                                S32                     *pWidth, 
                                                S32                     *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTfloat level;
    CTPoint point;
    CTSize  size;
    CTRect  canvas;
    S32     limit;
    S32     width;
    S32     height;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_GET_CURRENT_RECT, 5, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    if ((NULL == pLeft) || (NULL == pTop) || (NULL == pWidth) || (NULL == pHeight))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_getZoomPoint(hPreview->screen, &level, &point);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    result = caps_getCurrentImageSize(hPreview->pParent->session, &size);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    point.x = (S32)((point.x * hPreview->width1X  * level / size.w) + 0.5);
    point.y = (S32)((point.y * hPreview->height1X * level / size.h) + 0.5);

    result = caps_getScreenCanvasArea(hPreview->screen, &canvas);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    point.x -= canvas.w / 2;
    point.y -= canvas.h / 2;

    if (point.x <= 5)
    {
        point.x = 0;
    }

    if (point.y <= 5)
    {
        point.y = 0;
    }

    limit = (S32)(hPreview->width1X * level + 0.5f);
    if ((point.x + canvas.w + 5) >= limit)
    {
       point.x = limit - canvas.w;
    }

    limit = (S32)(hPreview->height1X * level + 0.5f);
    if ((point.y + canvas.h + 5) >= limit)
    {
       point.y = limit - canvas.h;
    }

    result = caps_getZoom(hPreview->screen, &level);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    width  = (S32)(hPreview->width1X  * level + 0.5f);
    height = (S32)(hPreview->height1X * level + 0.5f);

    if ((point.x + canvas.w - 1) >= width)
    {
       canvas.w = width - point.x;
    }

    if ((point.y + canvas.h - 1) >= height)
    {
       canvas.h = height - point.y;
    }

    *pLeft   = point.x;
    *pTop    = point.y;
    *pWidth  = canvas.w;
    *pHeight = canvas.h;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* These may fail because job already finished */
srv_ies_result srv_ies_preview_render(srv_ies_preview_handle hPreview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_RENDER, 1, hPreview);

    SCALADO_START_CTX_LOGGING("PRS");

    MEASURE_BEGIN();
    result = caps_renderScreen(hPreview->screen, NULL);
    MEASURE_END(caps_renderScreen);

    SCALADO_STOP_CTX_LOGGING("PRS");

    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // Extra checking: check incomplete render
    result = caps_getSourceRenderResult(hPreview->pParent->session);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

#if 0 //defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __DYNAMIC_SWITCH_CACHEABILITY__

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_preview_render_async(srv_ies_preview_handle          hPreview,
                                            srv_ies_async_callback_func_ptr callback, 
                                            void                            *pUserData,
                                            srv_ies_job_handle              *pHJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTIterator          *pItr;
    srv_ies_job_handle  hJob;
    MMI_BOOL            jobSent;

    IES_LOG_SETUP();

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_PREVIEW_RENDER_ASYNC, 4, hPreview);

    IES_CHECK_PREVIEW(hPreview);

    if ((NULL == pHJob) || (NULL == callback))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    MEASURE_BEGIN();
    result = caps_renderScreen(hPreview->screen, &pItr);
    MEASURE_END(caps_renderScreen);

    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    do
    {
        hJob = srv_ies_job_create(hPreview->pParent->pParent,
                                  MOD_IES,
                                  SRV_IES_JOB_TYPE_RENDER_PREVIEW,
                                  hPreview->pParent,
                                  NULL,
                                  pItr,
                                  hPreview,
                                  1,
                                  callback,
                                  pUserData);
        ASSERT(hJob != NULL);

        jobSent = srv_ies_job_send_request(hJob);
        if (MMI_FALSE == jobSent)
        {
            caps_destroyIterator(pItr);
            break;
        }

        *pHJob = hJob;

        IES_LOG_END(SRV_IES_OK);
        return SRV_IES_OK;
    } while(0);

    if (NULL != hJob)
    {
       srv_ies_job_destroy(hJob);
    }

    *pHJob = NULL;

    IES_LOG_END(SRV_IES_E_UNEXPECTED);
    return SRV_IES_E_UNEXPECTED;
}


#if SRV_IES_CAPS_FAST_ANIMX
srv_ies_result srv_ies_preview_render_animated(srv_ies_preview_handle   hPreview, 
                                               float                    animDst,
                                               float                    progress,
                                               MMI_BOOL                 endAnim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT     result;
    CTuint32    total;
    CTuint32    count;

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_CHECK_PREVIEW(hPreview);

    if((animDst != hPreview->animDst) && !endAnim)
    {
        // create animation
        kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_render_animated begin");

        if (NULL != hPreview->pAnim)
        {
            caps_animationUpdateScreen(hPreview->pAnim, 1.0f, 0);
            caps_animationDestroy(hPreview->pAnim);
            hPreview->pAnim = NULL;                 
        
            result = caps_setZoom(hPreview->screen, hPreview->animDst);
            IES_RET_IF_FAIL(result);

        }

        if (NULL == hPreview->pAnim)
        {
            result = caps_animationCreate(hPreview->screen, &hPreview->pAnim);
            IES_RET_IF_FAIL(result);

            MEASURE_BEGIN();
            result = caps_animationBeginZoom(hPreview->pAnim, animDst, NULL, &hPreview->pAnimItr);
            MEASURE_END(caps_animationBeginZoom);

            if (CFAILED(result))
            {
                caps_animationDestroy(hPreview->pAnim);
                hPreview->pAnim = NULL;      

                IES_RET_FAIL(result);
            }

            if (animDst > hPreview->animDst)
            {
                hPreview->animStep = 0.51f;
            }
            else
            {
                hPreview->animStep = 0.9f;
            }

            hPreview->animDst   = animDst;
            hPreview->animProg  = 0.25f;
        }
    }

    if (NULL != hPreview->pAnim)
    {
        if(endAnim)
        {
            kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_render_animated end");

            // After End(), the animation cannot be used.
            if(NULL != hPreview->pAnim)
            {
                MEASURE_BEGIN();
                result = caps_animationEnd(hPreview->pAnim, NULL);
                MEASURE_END(caps_animationEnd);

                caps_animationDestroy(hPreview->pAnim);
                hPreview->pAnim = NULL;

                IES_RET_IF_FAIL(result);
            }
        }
        else if (0.0f == progress)
        {
            result = caps_estimateIterationCount(hPreview->pAnimItr, &total);
            IES_RET_IF_FAIL(result);

            total >>= 1;
            count   = 0;
            do
            {
                result = caps_doNextIteration(hPreview->pAnimItr);
                if (++count > total)
                {
                    break;
                }
            } while(CERR_OK == result);
        }
        else
        {
            kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_render_animated update");

            if (NULL != hPreview->pAnimItr)
            {
                do
                {
                    result = caps_doNextIteration(hPreview->pAnimItr);
                } while(CERR_OK == result);
                hPreview->pAnimItr = NULL;
            }

            MEASURE_BEGIN();
            result = caps_animationUpdateScreen(hPreview->pAnim,
                                                hPreview->animProg,
                                                hPreview->animStep);
            MEASURE_END(caps_animationUpdateScreen);
            if (CFAILED(result))
            {
                result = caps_animationEnd(hPreview->pAnim, NULL);

                caps_animationDestroy(hPreview->pAnim);
                hPreview->pAnim = NULL;

                IES_RET_FAIL(result);
            }

            hPreview->animProg += 0.25f;
            hPreview->animStep  = 0.13f;
        }
    }

#if 0 //defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __DYNAMIC_SWITCH_CACHEABILITY__

    return SRV_IES_OK;
}
#else
srv_ies_result srv_ies_preview_render_animated(srv_ies_preview_handle   hPreview, 
                                               float                    animDst,
                                               float                    progress,
                                               MMI_BOOL                 endAnim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_CHECK_PREVIEW(hPreview);
    
    if((animDst != hPreview->animDst) && !endAnim)
    {
        // create animation
        kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_render_animated begin");
        {
            if (hPreview->pAnim)
            {
                result = caps_animationEnd(hPreview->pAnim, NULL);
                IES_RET_IF_FAIL(result);

                caps_animationDestroy(hPreview->pAnim);
                hPreview->pAnim = NULL;                 
            }
            else
            {
                result = caps_animationCreate(hPreview->screen, &hPreview->pAnim);
                IES_RET_IF_FAIL(result);

                hPreview->animDst = animDst;

                MEASURE_BEGIN();
                result = caps_animationBeginZoom(hPreview->pAnim, hPreview->animDst, NULL, NULL);
                MEASURE_END(caps_animationBeginZoom);

                if (CFAILED(result))
                {
                    caps_animationDestroy(hPreview->pAnim);
                    hPreview->pAnim = NULL;      

                    IES_RET_FAIL(result);
                }
            }
        }
    }

    if(endAnim)
    {
        kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_render_animated end");

        // after End(), the animation cannot be used.
        if(hPreview->pAnim)
        {
            MEASURE_BEGIN();
            result = caps_animationEnd(hPreview->pAnim, NULL);
            MEASURE_END(caps_animationEnd);

            caps_animationDestroy(hPreview->pAnim);
            hPreview->pAnim = NULL;

            IES_RET_IF_FAIL(result);
        }
    }
    else
    {
        kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_render_animated update");
        MEASURE_BEGIN();
        result = caps_animationUpdateScreen(hPreview->pAnim, progress, progress);
        MEASURE_END(caps_animationUpdateScreen);

        if (CFAILED(result))
        {
            caps_animationDestroy(hPreview->pAnim);
            hPreview->pAnim = NULL;      

            IES_RET_FAIL(result);
        }
    }

    return SRV_IES_OK;
}
#endif  // SRV_IES_CAPS_FAST_ANIMX


srv_ies_result srv_ies_animation_begin(srv_ies_preview_handle   hPreview, 
                                       float                    animDst,
                                       U32                      frameCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    
    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_animation_begin");

#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= (SRV_IES_SAVE_WORK_BUFFER + SRV_IES_ANIM_WORK_BUFFER))
    {
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif //__COSMOS_MMI_PACKAGE__

    ASSERT(NULL == hPreview->pAnim);

    caps_getZoom(hPreview->screen, &hPreview->animLevel);

    result = caps_animationCreate(hPreview->screen, &hPreview->pAnim);
    IES_RET_IF_FAIL(result);

    MEASURE_BEGIN();
    result = caps_animationBeginZoom(hPreview->pAnim, animDst, NULL, NULL);
    MEASURE_END(caps_animationBeginZoom);

    if (CFAILED(result))
    {
        caps_animationDestroy(hPreview->pAnim);
        hPreview->pAnim = NULL;

        IES_RET_FAIL(result);
    }

    if (animDst > hPreview->animDst)
    {
        hPreview->animStep = 0.51f;
    }
    else
    {
        hPreview->animStep = 0.9f;
    }

    hPreview->animDst   = animDst;
    hPreview->animProg  = 1.0f / frameCount;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_animation_adjust(srv_ies_preview_handle  hPreview,
                                        float                   animDst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_animation_adjust");

    ASSERT(NULL != hPreview->pAnim);

    if (hPreview->animDst != animDst)
    {
        caps_animationDestroy(hPreview->pAnim);
        hPreview->pAnim = NULL;                 
        
        result = caps_setZoom(hPreview->screen, hPreview->animDst);
        IES_RET_IF_FAIL(result);

        result = caps_animationCreate(hPreview->screen, &hPreview->pAnim);
        IES_RET_IF_FAIL(result);

        MEASURE_BEGIN();
        result = caps_animationBeginZoom(hPreview->pAnim, animDst, NULL, NULL);
        MEASURE_END(caps_animationBeginZoom);

        IES_RET_IF_FAIL(result);

        hPreview->animDst   = animDst;
        hPreview->animLevel = animDst;
    }

    return SRV_IES_OK;
}


srv_ies_result srv_ies_animation_render(srv_ies_preview_handle  hPreview,
                                        U32                     frameIndex)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    float   progress;

	  MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_animation_render %d", frameIndex);

    ASSERT(NULL != hPreview->pAnim);

    progress = hPreview->animProg * frameIndex;

    MEASURE_BEGIN();

    SCALADO_START_CTX_LOGGING("ANR");
    result = caps_animationUpdateScreen(hPreview->pAnim,
                                        progress,
                                        hPreview->animStep);  
    SCALADO_STOP_CTX_LOGGING("ANR");

    MEASURE_END(caps_animationUpdateScreen);

    IES_RET_IF_FAIL(result);

    result = caps_animationGetZoomPoint(hPreview->pAnim,
                                        progress,
                                        &hPreview->animCenter,
                                        &hPreview->animLevel);
    IES_RET_IF_FAIL(result);

    hPreview->animStep  = 0.13f;

#if 0 //defined(__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __DYNAMIC_SWITCH_CACHEABILITY__

    return SRV_IES_OK;
}


srv_ies_result srv_ies_animation_cancel(srv_ies_preview_handle hPreview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_animation_cancel");

    caps_animationDestroy(hPreview->pAnim);
    hPreview->pAnim = NULL;

    caps_setZoom(hPreview->screen, hPreview->animLevel);

    caps_setPan(hPreview->screen, hPreview->animCenter.x, hPreview->animCenter.y);

    return SRV_IES_OK;
}


srv_ies_result srv_ies_animation_end(srv_ies_preview_handle hPreview)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
	CTfloat level;

	MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2,  " srv_ies_preview_animation_end");

    // After End(), the animation cannot be used.
    ASSERT(NULL != hPreview->pAnim);

    if (hPreview->animDst != hPreview->animLevel)
    {
        caps_animationDestroy(hPreview->pAnim);
        hPreview->pAnim = NULL;    

        caps_getZoom(hPreview->screen, &level);
        if (hPreview->animLevel == level)
        {
		      return SRV_IES_OK;
        }

        result = caps_animationCreate(hPreview->screen, &hPreview->pAnim);
        IES_RET_IF_FAIL(result);

        MEASURE_BEGIN();
        result = caps_animationBeginZoom(hPreview->pAnim, hPreview->animLevel, NULL, NULL);
        MEASURE_END(caps_animationBeginZoom);

        if (CFAILED(result))
        {
            caps_animationDestroy(hPreview->pAnim);
            hPreview->pAnim = NULL;

			caps_setZoom(hPreview->screen, hPreview->animLevel);

			caps_getZoom(hPreview->screen, &level);
			hPreview->animDst   = level;

            // Avoid unexpected error for MAUI_03106005
			//IES_RET_FAIL(result);

			return SRV_IES_OK;
		}
    }

    MEASURE_BEGIN();
    result = caps_animationEnd(hPreview->pAnim, NULL);
    MEASURE_END(caps_animationEnd);

    caps_animationDestroy(hPreview->pAnim);
    hPreview->pAnim = NULL;

    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}


#define FUNC_GROUP_ROTATE

/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_rotate_begin(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_ROTATE_BEGIN, 1, hImage);

    IES_CHECK_IMAGE(hImage);

#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= SRV_IES_SAVE_WORK_BUFFER)
    {
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif //__COSMOS_MMI_PACKAGE__

    result = caps_beginRotate(hImage->session);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // Store initial orientation
    hImage->rotation = hImage->orientation;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_rotate_adjust(srv_ies_image_handle hImage,
                                           srv_ies_rot_enum     rotType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT         result;
    CAPS_ROTATION   capsRot;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_ROTATE_ADJUST, 2, hImage);

    IES_CHECK_IMAGE(hImage);

    switch(rotType)
    {
    case SRV_IES_ROT_0:
        capsRot = ROTATE_TO_0;
        break;
    case SRV_IES_ROT_90:
        capsRot = ROTATE_TO_90;
        break;
    case SRV_IES_ROT_180:
        capsRot = ROTATE_TO_180;
        break;
    case SRV_IES_ROT_270:
        capsRot = ROTATE_TO_270;
        break;
    default:
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_setRotate(hImage->session, capsRot);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }
    
    // Keep tracking current orientation
    hImage->rotation = rotType;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_rotate_cancel(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTbool  canUndo;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_ROTATE_CANCEL, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    caps_endRotate(hImage->session);

    result = caps_canUndo(hImage->session, &canUndo);
    IES_RET_IF_FAIL(result);

    if(!canUndo)
    {
        IES_LOG_END(SRV_IES_E_UNEXPECTED);
        return SRV_IES_E_UNEXPECTED;
    }

    result = caps_undo(hImage->session);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_rotate_end(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_ROTATE_END, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    caps_endRotate(hImage->session);

    hImage->orientation = hImage->rotation;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


#define FUNC_GROUP_FLIP

/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_flip_begin(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_FLIP_BEGIN, 1, hImage);

    IES_CHECK_IMAGE(hImage);

#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= SRV_IES_SAVE_WORK_BUFFER)
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif  // __COSMOS_MMI_PACKAGE__

    result = caps_beginFlip(hImage->session);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_flip_adjust(srv_ies_image_handle   hImage,
                                         MMI_BOOL               bHorzFlip,
                                         MMI_BOOL               bVertFlip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT         result;
    CAPS_FLIP_MODE  flipMode;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_FLIP_ADJUST, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    if (bHorzFlip && bVertFlip)
    {
        flipMode = FLIP_BOTH;
    }
    else if(bHorzFlip)
    {
        flipMode = FLIP_HORIZONTAL;
    }
    else if(bVertFlip)
    {
        flipMode = FLIP_VERTICAL;
    }
    else
    {
       flipMode = FLIP_NONE;
    }

    result = caps_setFlip(hImage->session, flipMode);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_flip_cancel(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTbool  canUndo;
    
    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_FLIP_CANCEL, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    caps_endFlip(hImage->session);

    result = caps_canUndo(hImage->session, &canUndo);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    if(!canUndo)
    {
        IES_LOG_END(SRV_IES_E_UNEXPECTED);
        return SRV_IES_E_UNEXPECTED;
    }

    result = caps_undo(hImage->session);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_image_flip_end(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_IMAGE_FLIP_END, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    caps_endFlip(hImage->session);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


#define FUNC_GROUP_ICON

// Internal utility function, assign clipart position to center and fit current image size.
srv_ies_result _srv_ies_icon_apply_default_pos(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTSize  image;
    CTSize  source;
    CTPoint center; 
    CTfloat scale;
    CTfloat angle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != hImage->clipArt);

    // Default to center of current (may be cropped) image.
    result = caps_getCurrentImageSize(hImage->session, &image);
    IES_RET_IF_FAIL(result);

    center.x = image.w / 2;
    center.y = image.h / 2;

    // Adjust the size to half of the current image size (may be cropped)
    result = caps_getClipartSize(hImage->clipArt, &source);
    IES_RET_IF_FAIL(result);

    // Inner-fit image bound
    if(image.w < image.h)
    {
        scale = image.w * 1.0f / source.w;
    }
    else
    {
        scale = image.h * 1.0f / source.h;
    }

    if ((scale < 0.1) || (scale > 64))
    {
        return SRV_IES_E_NOT_IMPLEMENTED;
    }

    angle = 0.0f;

    result = caps_setClipartOrientation(hImage->clipArt, center, scale, angle);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_icon_begin_from_file(srv_ies_image_handle    hImage,
                                            const WCHAR             *pPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT         result;
    CTStream        *pStream;
    CTImageFormat   format;
    CTPoint         center;
    srv_ies_result  error;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_BEGIN_FROM_FILE, 2, hImage);

    IES_CHECK_IMAGE(hImage);

    if (NULL == pPath)
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    // Reserve memory for saving file
#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= (SRV_IES_SAVE_WORK_BUFFER + SRV_IES_ICON_WORK_BUFFER + hImage->extraMargin))
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif // __COSMOS_MMI_PACKAGE__

    ASSERT(NULL == hImage->clipArt);

    // clip art does not support color key
    // after calling begin(), only adjust() or end() can be called.
    result = ctstream_createFileStreamEx((const S_DCHAR*)pPath,
                                         FOF_ACCESS_READ,
                                         SRV_IES_STREAM_CHUNK_SIZE,
                                         &pStream);
    IES_RET_IF_FAIL(result);

    result = caps_getImageType(pStream, &format);
    if (CFAILED(result))
    {
        ctstream_destroy(pStream);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }
    
    // Put to top-left corner of current image first.
    center.x = 0;
    center.y = 0;

    // File stream are owned by CAPS, while 
    // memory stream should be never be freeed (it's ROM in our case)
    result = caps_beginClipart(hImage->session, 
                               pStream, 
                               OWNERSHIP_CAPS, 
                               format, 
                               center,
                               1.0f,
                               0.0f,
                               &hImage->clipArt);
    if (CFAILED(result))
    {
        ctstream_destroy(pStream);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    error = _srv_ies_icon_apply_default_pos(hImage);
    if (SRV_IES_OK != error)
    {
        caps_endClipart(hImage->clipArt);
        hImage->clipArt = NULL;

        IES_LOG_END(error);
        return error;
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


static CTColormode _srv_ies_convert_ies_color_to_caps_color(srv_ies_colorformat_enum ies_format)
{
    switch(ies_format)
    {
    case SRV_IES_COLORFORMAT_RGB565:
        return CM_RGB565D;
    case SRV_IES_COLORFORMAT_RGB888:
        return CM_BGR888;
    case SRV_IES_COLORFORMAT_RGBA8888:
        // note we reverse order here
        return CM_BGRA8888;
    case SRV_IES_COLORFORMAT_RGBX8888:
        // note we reverse order here
        return CM_BGRX8888;
    }

    ASSERT(0);  // Unknown color format

    return CM_RGB565D;
}


srv_ies_result srv_ies_icon_begin_from_raw_buffer(srv_ies_image_handle      hImage,
                                                  void                      *pBuf,
                                                  U32                       bufSize,
                                                  U32                       width,
                                                  U32                       height,
                                                  U32                       pitch,
                                                  srv_ies_colorformat_enum  format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT         result;
    CTImage         *pImage;
    CTSize          size;
    CTPoint         center;
    srv_ies_result  error;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_BEGIN_FROM_BUFFER, 7, hImage);

    IES_CHECK_IMAGE(hImage);

    // Reserve memory for saving file
#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= (SRV_IES_SAVE_WORK_BUFFER + SRV_IES_ICON_WORK_BUFFER + hImage->extraMargin))
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif // __COSMOS_MMI_PACKAGE__

    ASSERT(NULL == hImage->clipArt);

    size.w   = width;
    size.h   = height;

    hImage->clipArtBuf.data = pBuf;
    hImage->clipArtBuf.size = bufSize;

    result = caps_createImage(&hImage->clipArtBuf, 
                              size, 
                              pitch,
                              _srv_ies_convert_ies_color_to_caps_color(format), 
                              &pImage);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // Put to top-left corner of current image first.
    center.x = 0;
    center.y = 0;

    result = caps_beginClipartFromRaw(hImage->session,
                                      pImage, 
                                      OWNERSHIP_EXTERNAL,  // This is external memory, maintained by client.
                                      center,
                                      1.0f, 
                                      0.0f, 
                                      &hImage->clipArt);
    if (CFAILED(result))
    {
        pImage->pixels = NULL;
        caps_destroyImage(pImage);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    error = _srv_ies_icon_apply_default_pos(hImage);
    if (SRV_IES_OK != error)
    {
        caps_endClipart(hImage->clipArt);

        pImage->pixels = NULL;
        caps_destroyImage(pImage);

        hImage->clipArt = NULL;

        IES_LOG_END(error);
        return error;
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


static U8* _srv_ies_switch_address(U8 *pVirtualAddr, U32 len, U32 cached)
{
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    U32 switchResult;
    U8  *pPhysicalAddr;

    pPhysicalAddr = pVirtualAddr;

    switchResult = dynamic_switch_cacheable_region((void*)&pPhysicalAddr, len, cached);
    ASSERT(0 == switchResult);

    return pPhysicalAddr;
#else
    return pVirtualAddr;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  _srv_ies_prepare_img_id
 * DESCRIPTION
 *  Convert a resource ID and optionally stretch it into a CAPS CTImage.
 *  The generated CAPS CTImage is alloacted in CAPS heap.
 *  The ownership of the CTImage is transferred to CAPS.
 *  
 * PARAMETERS
 *  img_id          [IN]    The image source id to convert
 *  w               [IN]    0 means original width. Otherwise the width is stretched.
 *  h               [IN]    0 means original height. Otherwise the height is stretched.
 *  stretched_image [OUT]   The resulting stretched CAPS CTImage object.
 *
 * RETURNS
 *  TRUE if the suffix is in support list
 *****************************************************************************/
static srv_ies_result _srv_ies_prepare_img_id(MMI_ID    imgID,
                                              S32       width,
                                              S32       height,
                                              CTImage   **pImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT     result;
    U8          *pCached;
    U8          *pNonCached;
    U32         bufSize;
    U32         length;
    CTSize      target;
    CTImage     *capsImg;
    CTBuffer    *capsBuf;   // Allocate the memory in caps heap
    gdi_handle  layer;
    U32         error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((width == 0) || (height == 0))
    {
        error = gdi_image_get_dimension_id(imgID, &width, &height);
        if(GDI_SUCCEED != error)
        {
            return SRV_IES_E_UNSUPPORTED_FORMAT;
        }
    }
   
    bufSize = width * height * 4 + 63;

    result = caps_createBuffer(bufSize, &capsBuf);
    IES_RET_IF_FAIL(result);
    
    
    target.w = width;
    target.h = height;
    result = caps_createImage(capsBuf, target, width * 4, CM_BGRA8888, &capsImg);
    IES_RET_IF_FAIL(result);

    pCached = (U8*)(((U32)capsBuf->data + 31) & ~31);  // 32-byte alginment
    length  = (bufSize + 31) & ~31;  // 32-byte alignment

    pNonCached = _srv_ies_switch_address(pCached, length, 0);

    gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32,
                                             0,
                                             0,
                                             width,
                                             height,
                                             &layer,
                                             pNonCached,
                                             capsBuf->size);
    if(NULL == (void*)layer)
    {
        caps_destroyImage(capsImg);
        capsImg = NULL;
        return SRV_IES_E_UNSUPPORTED_FORMAT;
    }

    gdi_layer_push_and_set_active(layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_push_and_set_alpha_blending_source_layer(GDI_NULL_HANDLE);

    error = gdi_image_draw_resized_id(0, 0, width, height, imgID);

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(layer);
    layer = NULL;

    if(GDI_SUCCEED != error)
    {
        return SRV_IES_E_UNSUPPORTED_FORMAT;
    }

    if (pNonCached != pCached)
    {
       _srv_ies_switch_address(pNonCached, length, 1);
    }

    if (pCached != capsBuf->data)
    {
       memcpy(capsBuf->data, pCached, width * 4 * height);
    }

    *pImage = capsImg;

    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_icon_begin_from_id(srv_ies_image_handle hImage, MMI_IMG_ID imgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT         result;
    srv_ies_result  error;
    CTImage         *pIcon;
    CTPoint         center;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_BEGIN_FROM_ID, 2, hImage);

    IES_CHECK_IMAGE(hImage);

    // Reserve memory for saving file
#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= (SRV_IES_SAVE_WORK_BUFFER + SRV_IES_ICON_WORK_BUFFER + hImage->extraMargin))
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif // __COSMOS_MMI_PACKAGE__

    ASSERT(NULL == hImage->clipArt);    

    // Convert the image ID into CAPS image buffer
    error = _srv_ies_prepare_img_id(imgID, 0, 0, &pIcon);
    if(SRV_IES_OK != error)
    {
        IES_LOG_END(error);
        return error;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    // Put to top-left corner of current image first.
    center.x = 0;
    center.y = 0;

    result = caps_beginClipartFromRaw(hImage->session, 
                                      pIcon, 
                                      OWNERSHIP_CAPS,  // Transfer the image to CAPS
                                      center,
                                      1.0f, 
                                      0.0f, 
                                      &hImage->clipArt);
    if(CFAILED(result))
    {
        // must destory the image, since
        // ownership is only transferred when succeeded.
        caps_destroyImage(pIcon);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }
    
    error = _srv_ies_icon_apply_default_pos(hImage);
    if (SRV_IES_OK != error)
    {
        caps_endClipart(hImage->clipArt);
        hImage->clipArt = NULL;

        IES_LOG_END(error);
        return error;
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_icon_get_current_size(srv_ies_image_handle   hImage,
                                             S32                    *pWidth,
                                             S32                    *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTSize  size;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_GET_CURRENT_SIZE, 3, hImage);

    IES_CHECK_IMAGE(hImage);

    if ((NULL == pWidth) || (NULL == pHeight))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    ASSERT(NULL != hImage->clipArt);

    result = caps_getClipartSize(hImage->clipArt, &size);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    *pWidth  = size.w;
    *pHeight = size.h;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_icon_get_min_max_adjustable_size(srv_ies_image_handle    hImage,
                                                        S32                     *pMin,
                                                        S32                     *pMax)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTSize  size;
    S32     dim;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_GET_MIN_MAX_SIZE, 3, hImage);

    IES_CHECK_IMAGE(hImage);

    if ((NULL == pMin) || (NULL == pMax))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    ASSERT(NULL != hImage->clipArt); // must call srv_ies_icon_begin() first.

    result = caps_getClipartSize(hImage->clipArt, &size);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // this limitation is CAPS-dependent. Newer versions may change this limitation.
    // in CAPS 3.9, the limitation ratio for clipart is [0.1, 64.0]
    dim = size.h > size.w ? size.h: size.w;

    *pMin = (S32)((dim + 9) / 10);  // ceiling for conservative answer
    *pMax = (S32)(dim * 64);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


// if width & height is 0, icon size is used.
srv_ies_result srv_ies_icon_adjust_pos(srv_ies_image_handle hImage,
                                       S32                  centerX,
                                       S32                  centerY)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTPoint center;
    CTfloat scale;
    CTfloat angle;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_ADJUST_POS, 3, hImage);

    IES_CHECK_IMAGE(hImage);

    ASSERT(NULL != hImage->clipArt); // must call srv_ies_icon_begin() first.
    
    result = caps_getClipartOrientation(hImage->clipArt, &center, &scale, &angle);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    center.x = centerX;
    center.y = centerY;

    // set center, scale & rotation
    result = caps_setClipartOrientation(hImage->clipArt, center, scale, angle);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


static float _srv_ies_rotate_type_to_degree(srv_ies_rot_enum rotateType)
{
    switch(rotateType)
    {
    case SRV_IES_ROT_0:
        return 0.0f;
    case SRV_IES_ROT_90:
        return 90.0f;
    case SRV_IES_ROT_180:
        return 180.0f;
    case SRV_IES_ROT_270:
        return 270.0f;
    default:
        return 0.0f;
    }
}


srv_ies_result srv_ies_icon_adjust_rotation(srv_ies_image_handle hImage, srv_ies_rot_enum rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTPoint center;
    CTfloat scale;
    CTfloat angle;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_ADJUST_ROTATION, 2, hImage);

    IES_CHECK_IMAGE(hImage);

    ASSERT(NULL != hImage->clipArt); // must call srv_ies_icon_begin() first.

    result = caps_getClipartOrientation(hImage->clipArt, &center, &scale, &angle);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    angle = _srv_ies_rotate_type_to_degree(rotation);

    result = caps_setClipartOrientation(hImage->clipArt, center, scale, angle);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }


    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


static float _srv_ies_convert_dimension_to_scale(S32 dstW, S32 dstH, S32 srcW, S32 srcH)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float scaleW;
    float scaleH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    scaleW = dstW * 1.0f / srcW;
    scaleH = dstH * 1.0f / srcH;

    // choose the bigger scale
    if(scaleH > scaleW)
    {
        scaleW = scaleH;
    }

    return scaleW;
}


srv_ies_result srv_ies_icon_adjust(srv_ies_image_handle hImage,
                                   S32                  centerX,
                                   S32                  centerY,
                                   S32                  width,
                                   S32                  height,
                                   srv_ies_rot_enum     rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTPoint center;
    CTfloat scale;
    CTSize  size;
    CTfloat angle;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_ADJUST, 6, hImage);

    IES_CHECK_IMAGE(hImage);

    ASSERT(NULL != hImage->clipArt);

    result = caps_getClipartOrientation(hImage->clipArt, &center, &scale, &angle);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    center.x = centerX;
    center.y = centerY;
    angle = _srv_ies_rotate_type_to_degree(rotation);
    
    result = caps_getClipartSize(hImage->clipArt, &size);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    scale = _srv_ies_convert_dimension_to_scale(width, height, size.w, size.h);

    result = caps_setClipartOrientation(hImage->clipArt, center, scale, angle);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_icon_cancel(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_CANCEL, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    ASSERT(NULL != hImage->clipArt);

    result = caps_endClipart(hImage->clipArt);
    hImage->clipArt = NULL;
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    result = caps_undo(hImage->session);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}



static CRESULT _srv_ies_frame_custom_undo(CTSession session, void *opData)
{
    CRESULT                 result;
    srv_ies_frame_info      *pParam;
    srv_ies_image_handle    hImage;

    pParam = (srv_ies_frame_info*)opData;
    hImage = pParam->hImage;

    if (pParam->frameSize <= (240 * 320))
    {
        hImage->extraMargin -= SRV_IES_QVGA_FRAME_MARGIN;
    }
    else if (pParam->frameSize <= (240 * 400))
    {
        hImage->extraMargin -= SRV_IES_WQVGA_FRAME_MARGIN;
    }
    else if (pParam->frameSize <= (320 * 480))
    {
        hImage->extraMargin -= SRV_IES_HVGA_FRAME_MARGIN;
    }
    else if (pParam->frameSize <= (480 * 640))
    {
        hImage->extraMargin -= SRV_IES_VGA_FRAME_MARGIN;
    }
    else if (pParam->frameSize <= (480 * 800))
    {
        hImage->extraMargin -= SRV_IES_WVGA_FRAME_MARGIN;
    }
    else
    {
        hImage->extraMargin -= SRV_IES_MAX_FRAME_MARGIN;
    }

    result = caps_undo(session);
    ASSERT(result == CERR_OK);

    oslmem_free(pParam);

    return CERR_OK;
}

static CRESULT _srv_ies_frame_custom_redo(CTSession session, void *opData)
{
    return CERR_OK;
}   


static CRESULT _srv_ies_frame_custom_remove(CTSession session, void *opData)
{
    oslmem_free(opData);

    return CERR_OK;
}


srv_ies_result srv_ies_icon_end(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTSize              current;
    srv_ies_frame_info  *pData;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_ICON_END, 1, hImage);

    IES_CHECK_IMAGE(hImage);

    ASSERT(NULL != hImage->clipArt);

    result = caps_getClipartSize(hImage->clipArt, &current);
    ASSERT(CERR_OK == result);

    if ((current.w * current.h) <= (240 * 320))
    {
        hImage->extraMargin += SRV_IES_QVGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (240 * 400))
    {
        hImage->extraMargin += SRV_IES_WQVGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (320 * 480))
    {
        hImage->extraMargin += SRV_IES_HVGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (480 * 640))
    {
        hImage->extraMargin += SRV_IES_VGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (480 * 800))
    {
        hImage->extraMargin += SRV_IES_WVGA_FRAME_MARGIN;
    }
    else
    {
        hImage->extraMargin += SRV_IES_MAX_FRAME_MARGIN;
    }

    result = caps_endClipart(hImage->clipArt);
    hImage->clipArt = NULL;

    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    pData = (srv_ies_frame_info*)oslmem_alloc(sizeof(srv_ies_frame_info));
    ASSERT(NULL != pData);

    pData->frameSize = current.w * current.h;
    pData->hImage    = hImage;

    result = caps_addCustomUndoOperation(hImage->session,               // Session
                                         _srv_ies_frame_custom_undo,    // Undo
                                         _srv_ies_frame_custom_redo,    // Redo
                                         _srv_ies_frame_custom_remove,  // Remove
                                         pData);                        // Data

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


#define FUNC_GROUP_FRAME

srv_ies_result srv_ies_frame_begin_from_id(srv_ies_image_handle hImage,
                                           MMI_ID               frameID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // Slightly enlarge the frame to make sure it covers whole image
    static const float SRV_IES_FRAME_SCALE_DELTA = 1.01f;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT        result;
    srv_ies_result error;
    CTSize         current;
    CTScreen       *pScreen;
    CTImage        *pFrame;
    //CTSize         frameSize;
    CTRect         canvasRect;
    CTPoint        clipPoint;
    CTfloat        clipScale;
    CTfloat        clipAngle;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_FRAME_BEGIN_FROM_ID, 2, hImage);

    IES_CHECK_IMAGE(hImage);

    // Reserve memory for saving file
#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= (SRV_IES_RENDER_WORK_BUFFER + SRV_IES_FRAME_WORK_BUFFER + hImage->extraMargin))
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif  // __COSMOS_MMI_PACKAGE__

    result = caps_getCurrentImageSize(hImage->session, &current);
    IES_RET_IF_FAIL(result);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    result = caps_getCurrentScreen(hImage->session, &pScreen);
    ASSERT(CERR_OK == result);

    result = caps_getScreenCanvasArea(pScreen, &canvasRect);
    ASSERT(CERR_OK == result);
#endif

    error = _srv_ies_prepare_img_id(frameID,
                                    canvasRect.w,
                                    canvasRect.h,
                                    &pFrame);
    if(SRV_IES_OK != error)
    {
        IES_LOG_END(error);
        return error;
    }

    // always stretch to full-image
    clipPoint.x    = current.w / 2;
    clipPoint.y    = current.h / 2;
    clipAngle      = 0.0f;
    clipScale      = current.h * SRV_IES_FRAME_SCALE_DELTA / canvasRect.h;

    if (clipScale < 0.1)
    {
        caps_destroyImage(pFrame);

        IES_LOG_END(SRV_IES_E_RESOLUTION_TOO_SMALL);
        return SRV_IES_E_RESOLUTION_TOO_SMALL;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    result = caps_beginClipartFromRaw(hImage->session,
                                      pFrame,
                                      OWNERSHIP_CAPS,
                                      clipPoint,
                                      clipScale,
                                      0.0f,
                                      &hImage->clipArt);
    if (CFAILED(result))
    {
        caps_destroyImage(pFrame);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    result = caps_setClipartOrientation(hImage->clipArt,
                                        clipPoint,
                                        clipScale,
                                        clipAngle);
    if (CFAILED(result))
    {
        caps_endClipart(hImage->clipArt);
        hImage->clipArt = NULL;

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_frame_cancel(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTbool  canUndo;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_FRAME_CANCEL, 1, hImage);

    if(NULL == hImage->clipArt)
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_endClipart(hImage->clipArt);
    IES_RET_IF_FAIL(result);

    hImage->clipArt = NULL;

    result = caps_canUndo(hImage->session, &canUndo);
    IES_RET_IF_FAIL(result);

    if(!canUndo)
    {
        IES_LOG_END(SRV_IES_E_UNEXPECTED);
        return SRV_IES_E_UNEXPECTED;
    }

    result = caps_undo(hImage->session);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_frame_end(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTSize              current;
    srv_ies_frame_info  *pData;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_FRAME_END, 1, hImage);

    if(NULL == hImage->clipArt)
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = caps_endClipart(hImage->clipArt);
    hImage->clipArt = NULL;

    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    result = caps_getCurrentImageSize(hImage->session, &current);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    if ((current.w * current.h) <= (240 * 320))
    {
        hImage->extraMargin += SRV_IES_QVGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (240 * 400))
    {
        hImage->extraMargin += SRV_IES_WQVGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (320 * 480))
    {
        hImage->extraMargin += SRV_IES_HVGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (480 * 640))
    {
        hImage->extraMargin += SRV_IES_VGA_FRAME_MARGIN;
    }
    else if ((current.w * current.h) <= (480 * 800))
    {
        hImage->extraMargin += SRV_IES_WVGA_FRAME_MARGIN;
    }
    else
    {
        hImage->extraMargin += SRV_IES_MAX_FRAME_MARGIN;
    }

    pData = (srv_ies_frame_info*)oslmem_alloc(sizeof(srv_ies_frame_info));
    ASSERT(NULL != pData);

    pData->frameSize = current.w * current.h;
    pData->hImage    = hImage;

    result = caps_addCustomUndoOperation(hImage->session,               // Session
                                         _srv_ies_frame_custom_undo,    // Undo
                                         _srv_ies_frame_custom_redo,    // Redo
                                         _srv_ies_frame_custom_remove,  // Remove
                                         pData);                        // Data

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


#define FUNC_GROUP_DOODLE

srv_ies_result srv_ies_doodle_create(srv_ies_preview_handle     hPreview,
                                     srv_ies_doodle_info_handle *pHDoodle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT                 result;
    CTColor                 color;
    CTColormode             colorMode;
    srv_ies_doodle_info     *pDoodle;
    CAPS_SCRIBBLE           scribble;

#ifdef __COSMOS_MMI_PACKAGE__
    srv_ies_image_handle    hImage;
#else
    CTuint32                pixelBPP;
    CTBuffer                *pRawBuf;
    CTSize                  dims;
    CTImage                 *pImage;
#endif // __COSMOS_MMI_PACKAGE__

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_doodle_create on preview %x", hPreview);

    IES_LOG_BEGIN(SRV_IES_DOODLE_CREATE, 2, hPreview);

    if((NULL == pHDoodle) ||  (NULL == hPreview) || (NULL == hPreview->screen))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    // Reserve memory for saving file
#ifdef __COSMOS_MMI_PACKAGE__
    hImage = (srv_ies_image_handle)hPreview->pParent;

    if (oslmem_free_space() <= (SRV_IES_RENDER_WORK_BUFFER + SRV_IES_DOODLE_WORK_BUFFER + hImage->extraMargin))
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif  //__COSMOS_MMI_PACKAGE__

    TYPED_ALLOC(pDoodle, srv_ies_doodle_info);
    ASSERT(NULL != pDoodle);

    color.a = 255;
    color.r = 255;
    color.g = 0;
    color.b = 0;

#ifdef __COSMOS_MMI_PACKAGE__
    // Support multiple doodle
    colorMode = CM_RGB565_G0;
    result = caps_beginScribble(hPreview->screen,
                                NULL,
                                &colorMode,
                                color,
                                &scribble);
#else
    // Support single doodle
    result = caps_getScreenSize(hPreview->screen, &dims);
    if (CFAILED(result))
    {
        TYPED_FREE(pDoodle, srv_ies_doodle_info);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    colorMode = CM_RGB565_G0;
    pixelBPP  = caps_pixelByteSize(colorMode);
    ASSERT(pixelBPP > 0);

    if ((NULL == hPreview->pDoodleBuf) ||
        (hPreview->pDoodleBuf->format != colorMode) ||
        (hPreview->pDoodleBuf->dims.w != dims.w) ||
        (hPreview->pDoodleBuf->dims.h != dims.h))
    {
        if (NULL != hPreview->pDoodleBuf)
        {
            caps_destroyImage(hPreview->pDoodleBuf);
            hPreview->pDoodleBuf = NULL;
        }

        result = caps_createBuffer(pixelBPP * dims.w * dims.h, &pRawBuf);
        if (CFAILED(result))
        {
            TYPED_FREE(pDoodle, srv_ies_doodle_info);

            IES_LOG_FAIL(result);
            IES_RET_FAIL(result);
        }

        result = caps_createImage(pRawBuf,
                                  dims,
                                  dims.w * pixelBPP,
                                  colorMode,
                                  &pImage);
        if (CFAILED(result))
        {
            caps_destroyBuffer(pRawBuf);

            TYPED_FREE(pDoodle, srv_ies_doodle_info);

            IES_LOG_FAIL(result);
            IES_RET_FAIL(result);
        }

        hPreview->pDoodleBuf = pImage;
    }

    result = caps_beginScribble(hPreview->screen,
                                hPreview->pDoodleBuf, 
                                NULL,
                                color,
                                &scribble);
#endif  // __COSMOS_MMI_PACKAGE__

    if(CFAILED(result))
    {
        TYPED_FREE(pDoodle, srv_ies_doodle_info);
        *pHDoodle = NULL;

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    pDoodle->pParent        = hPreview->pParent;
    pDoodle->screen         = hPreview->screen;
    pDoodle->scribble       = scribble;
    pDoodle->lineRadius     = 1;

    *pHDoodle = pDoodle;

    IES_LOG_END(SRV_IES_OK);    
    return SRV_IES_OK;
}


srv_ies_result srv_ies_doodle_set_color(srv_ies_doodle_info_handle  hDoodle,
                                        U8                          red,
                                        U8                          green,
                                        U8                          blue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTColor color;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_DOODLE_SET_COLOR, 4, hDoodle);

    IES_CHECK_DOODLE(hDoodle);

    color.a = 255;
    color.r = red;
    color.g = green;
    color.b = blue;

    result = caps_setScribbleColor(hDoodle->scribble, color);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_doodle_set_line_width(srv_ies_doodle_info_handle hDoodle,
                                             U32                        linwWidth)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_DOODLE_SET_LINE_WIDTH, 2, hDoodle);

    IES_CHECK_DOODLE(hDoodle);

    if(0 == linwWidth)
    {
        linwWidth = 1;
    }

    // Because the width of the border will be ( 2 * line_radius +1 ) pixels wide.
    // (from CAPS manual)
    hDoodle->lineRadius = (linwWidth - 1) / 2;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


static void _srv_ies_scribble_bracket_line_to_canvas(CTRect     canvasRect,
                                                     CTPoint    *bracketThis,
                                                     CTint32    brushRadius)
{
    if ((canvasRect.y + brushRadius) >= bracketThis->y)
    {
        bracketThis->y = canvasRect.y + brushRadius;
    }
    else if ( ((canvasRect.y + canvasRect.h - 1) - brushRadius) <= bracketThis->y )
    {
        bracketThis->y = (canvasRect.y + canvasRect.h - 1) - brushRadius;
    }

    if ((canvasRect.x + brushRadius) >= bracketThis->x)
    {
        bracketThis->x = canvasRect.x + brushRadius;
    }
    else if ( ((canvasRect.x + canvasRect.w - 1) - brushRadius) <= bracketThis->x )
    {
        bracketThis->x = (canvasRect.x + canvasRect.w - 1) - brushRadius;
    }
}


srv_ies_result srv_ies_doodle_add_line(srv_ies_doodle_info_handle   hDoodle,
                                       S32                          srcX,
                                       S32                          srcY,
                                       S32                          dstX,
                                       S32                          dstY)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTRect  canvasRect;
    CTPoint srcCoords;
    CTPoint dstCoords;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_DOODLE_ADD_LINE, 5, hDoodle);

    IES_CHECK_DOODLE(hDoodle);

    result = caps_getScreenCanvasArea(hDoodle->screen, &canvasRect);
    ASSERT(CERR_OK == result);

    srcCoords.x = srcX;
    srcCoords.y = srcY;

    dstCoords.x = dstX;
    dstCoords.y = dstY;
    
    _srv_ies_scribble_bracket_line_to_canvas(canvasRect, &srcCoords, hDoodle->lineRadius);
    _srv_ies_scribble_bracket_line_to_canvas(canvasRect, &dstCoords, hDoodle->lineRadius);
    
    result = caps_setLineInScribble(hDoodle->scribble,
                                    srcCoords,
                                    dstCoords,
                                    hDoodle->lineRadius, 
                                    SRV_IES_DOODLE_LINE_SHAPE);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_doodle_erase_line(srv_ies_doodle_info_handle hDoodle, 
                                         S32                        srcX,
                                         S32                        srcY, 
                                         S32                        dstX,
                                         S32                        dstY, 
                                         S32                        radius)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;
    CTPoint srcCoords;
    CTPoint dstCoords;
    CTColor eraseColor;
    CTColor orgColor;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_DOODLE_ERASE_LINE, 6, hDoodle);

    IES_CHECK_DOODLE(hDoodle);

    // Erase line is actually drawing an "transparent" line
    eraseColor.b = 255;
    eraseColor.g = 255;
    eraseColor.r = 255;
    eraseColor.a = 0;

    result = caps_getScribbleColor(hDoodle->scribble, &orgColor);
    result = caps_setScribbleColor(hDoodle->scribble, eraseColor);

    srcCoords.x = srcX;
    srcCoords.y = srcY;

    dstCoords.x = dstX;
    dstCoords.y = dstY;
    
    result = caps_setLineInScribble(hDoodle->scribble,
                                    srcCoords,
                                    dstCoords, 
                                    radius, 
                                    SRV_IES_DOODLE_LINE_SHAPE);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    // restore original color
    result = caps_setScribbleColor(hDoodle->scribble, orgColor);
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_doodle_cancel_and_destroy(srv_ies_doodle_info_handle hDoodle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_DOODLE_CANCEL_AND_DESTROY, 1, hDoodle);

    IES_CHECK_DOODLE(hDoodle);

    caps_eraseScribbleBuffer(hDoodle->scribble);

    caps_endScribble(hDoodle->scribble);

    result = caps_undo(hDoodle->pParent->session);

    hDoodle->pParent = NULL;

    TYPED_FREE(hDoodle, srv_ies_doodle_info);
    
    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


// We must commit the doodle before moving the preview
srv_ies_result srv_ies_doodle_commit_and_destroy(srv_ies_doodle_info_handle hDoodle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_DOODLE_COMMIT_AND_DESTROY, 1, hDoodle);

    IES_CHECK_DOODLE(hDoodle);

    result = caps_endScribble(hDoodle->scribble);
    hDoodle->pParent = NULL;

    TYPED_FREE(hDoodle, srv_ies_doodle_info);

    if(CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}

#endif /* __MMI_SRV_IES__ */
