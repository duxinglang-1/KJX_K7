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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SRV_IES__
#include "ImgEdtSrvConfig.h"
#include "ImgEdtSrvStruct.h"

DECLARE_STATIC_RESERVE_SLOT(srv_ies_meta, 7);

srv_ies_result srv_ies_meta_init(srv_ies_app_session_handle hApp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hApp->appState |= SRV_IES_APP_STATE_META_INITED;

    return SRV_IES_OK;
}

srv_ies_result srv_ies_meta_create_from_file(srv_ies_app_session_handle    hApp,
                                             const WCHAR                   *pPath,
                                             U32                           width,
                                             U32                           height,
                                             srv_ies_meta_handle           *pHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTStream            *pStream;
    CTSpmoOptions       *pOption;
    CTSpmo              *pSPMO;
    CTSize              size;
    srv_ies_meta_handle hMeta;

    IES_LOG_SETUP();

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_META_CREATE_FROM_FILE, 4, pPath);

    if (0 == (hApp->appState & SRV_IES_APP_STATE_META_INITED))
    {
        IES_LOG_END(SRV_IES_E_UNEXPECTED);
        return SRV_IES_E_UNEXPECTED;
    }

    if (NULL == pHandle)
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    result = ctstream_createFileStreamEx((const S_DCHAR*)pPath,
                                         FOF_ACCESS_READ | FOF_MODE_BINARY,
                                         SRV_IES_STREAM_CHUNK_SIZE,
                                         &pStream);
    ASSERT(NULL != pStream);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    pOption = NULL;

    size.w = width;
    size.h = height;

    MEASURE_BEGIN();
    result = caps_createSpmo(pStream,
                             IMAGE_FORMAT_JPEG,
                             size,
                             0,
                             &pSPMO,
                             0);
    MEASURE_END(caps_createSpmo);

    if (CFAILED(result))
    {
        caps_spmoDestroyOptions(pOption);
        ctstream_destroy(pStream);
        *pHandle = NULL;

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    ctstream_destroy(pStream);

    TYPED_ALLOC(hMeta, srv_ies_meta);
    ASSERT(NULL != hMeta);

    hMeta->pParent  = hApp;
    hMeta->pSPMO    = pSPMO;
    hMeta->pOption  = NULL;

    *pHandle = hMeta;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_create_meta_async
 * DESCRIPTION
 *  Create meta for the specified image asynchronously
 * RETURNS
 *  SRV_IES_OK if succeeded
 *****************************************************************************/
srv_ies_result srv_ies_meta_create_from_file_async(srv_ies_app_session_handle       hApp,
                                                   const WCHAR                      *pPath,
                                                   U32                              width,
                                                   U32                              height,
                                                   srv_ies_async_callback_func_ptr  callback,
                                                   void                             *pUserData,
                                                   srv_ies_job_handle               *pHJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT             result;
    CTFile              *pImage;
    srv_ies_meta_handle hMeta;
    CTStream            *pSource;
    CTImageFormat       format;
    CTSpmoOptions       *pOption;
    CTSize              size;
    CTIterator          *pItr;
    srv_ies_job_handle  hJob;
    MMI_BOOL            jobSent;

    IES_LOG_SETUP();

    MEASURE_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_META_CREATE_FROM_FILE_ASYNC,
                  6,
                  pPath,
                  width,
                  height,
                  callback,
                  pUserData,
                  pHJob);

    if (0 == (hApp->appState & SRV_IES_APP_STATE_META_INITED))
    {
        IES_LOG_END(SRV_IES_E_UNEXPECTED);
        return SRV_IES_E_UNEXPECTED;
    }

    if (NULL == pHJob)
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    oslfile_open((const S_DCHAR*)pPath, FOF_ACCESS_READ, &pImage);
    ASSERT(pImage != NULL);

    result = caps_getImageTypeFromHdrFileHandle(pImage, &format);
    if (CFAILED(result))
    {
        oslfile_close(pImage);

        IES_LOG_END(SRV_IES_E_UNSUPPORTED_FORMAT);
        return SRV_IES_E_UNSUPPORTED_FORMAT;
    }

    ASSERT(IMAGE_FORMAT_JPEG == format);

    if (oslfile_size(pImage) > SRV_IES_JPEG_MAX_FILE_SIZE)
    {
        oslfile_close(pImage);

        IES_LOG_END(SRV_IES_E_FILE_SIZE_TOO_LARGE);
        return SRV_IES_E_FILE_SIZE_TOO_LARGE;
    }

    oslfile_close(pImage);

    TYPED_ALLOC(hMeta, srv_ies_meta);
    ASSERT(NULL != hMeta);

    result = caps_spmoCreateOptions(&pOption);
    ASSERT(CERR_OK == result);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   

    MEASURE_BEGIN();
    result = ctstream_createFileStreamEx((const S_DCHAR*)pPath,
                                          FOF_ACCESS_READ | FOF_MODE_BINARY,
                                          SRV_IES_STREAM_CHUNK_SIZE,
                                          &pSource);
    MEASURE_END(ctstream_createFileStreamEx);
    if (CERR_OK != result)
    {
        caps_spmoDestroyOptions(pOption);
        TYPED_FREE(hMeta, srv_ies_meta);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    size.w = width;
    size.h = height;

    MEASURE_BEGIN();
    result = caps_createSpmo(pSource,
                             IMAGE_FORMAT_JPEG,
                             size,
                             pOption,
                             &(hMeta->pSPMO),
                             &pItr);
    MEASURE_END(caps_createSpmo);
    if (CERR_OK != result)
    {
        caps_spmoDestroyOptions(pOption);
        ctstream_destroy(pSource);
        TYPED_FREE(hMeta, srv_ies_meta);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    hMeta->pParent = hApp;
    hMeta->pOption = pOption;
    hMeta->pSource = pSource;

    do
    {
        hJob = srv_ies_job_create(hApp,
                                  MOD_IES,
                                  SRV_IES_JOB_TYPE_CREATE_META,
                                  hMeta,
                                  NULL,
                                  pItr,
                                  hMeta,
                                  1,
                                  callback,
                                  pUserData);
        ASSERT(hJob != NULL);

        jobSent = srv_ies_job_send_request(hJob);
        if(MMI_FALSE == jobSent)
        {
            caps_destroyIterator(pItr);
            caps_spmoDestroyOptions(pOption);
            ctstream_destroy(pSource);
            break;
        }

        if(pHJob)
        {
            *pHJob = hJob;
        }

        IES_LOG_END(SRV_IES_OK);
        return SRV_IES_OK;
    } while(0);

    srv_ies_job_destroy(hJob);
    if(pHJob)
    {
        *pHJob = NULL;
    }

    TYPED_FREE(hMeta, srv_ies_meta);

    IES_LOG_END(SRV_IES_E_UNEXPECTED);
    return SRV_IES_E_UNEXPECTED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ies_meta_create_from_buffer
 * DESCRIPTION
 *  Create meta handle from the data provided in the buffer.
 *  The raw buffer should contain the raw data for the SPMO.
 * RETURNS
 *  SRV_IES_OK if succeeded
 *****************************************************************************/
srv_ies_result srv_ies_meta_create_from_buffer(srv_ies_app_session_handle   hApp,
                                               U8                           *pRaw,
                                               U32                          size,
                                               srv_ies_meta_handle          *pHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT              result;
    CTBuffer             buffer;
    CTStream             *pSource;
    CTSpmo               *pSPMO;
    srv_ies_meta_handle  hMeta;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_META_CREATE_FROM_BUFFER,
                  3,
                  pRaw,
                  size,
                  pHandle);

    if (0 == (hApp->appState & SRV_IES_APP_STATE_META_INITED))
    {
        IES_LOG_END(SRV_IES_E_UNEXPECTED);
        return SRV_IES_E_UNEXPECTED;
    }

    if (NULL == pHandle)
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    if ((hApp->feature == SRV_IES_FEATURE_VIEW) &&
        (oslmem_free_space() <= (7.5 * 1024 * 1024)))
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }

    buffer.data = pRaw;
    buffer.size = size;
    result = ctstream_createBufferStream(&buffer,
                                         size,
                                         &pSource);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    result = caps_getSpmo(pSource, &pSPMO);
    if (CFAILED(result))
    {
        ctstream_destroy(pSource);

        IES_LOG_FAIL(result);
        IES_RET_FAIL(result);
    }

    ctstream_destroy(pSource);

    TYPED_ALLOC(hMeta, srv_ies_meta);
    ASSERT(NULL != hMeta);

    hMeta->pParent   = hApp;
    hMeta->pOption   = NULL;
    hMeta->pSource   = NULL;
    hMeta->pSPMO     = pSPMO;

    *pHandle = hMeta;

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ies_meta_query_meta_data
 * DESCRIPTION
 *  Query or get meta data from the specified meta handle
 * RETURNS
 *  SRV_IES_OK if succeeded
 *****************************************************************************/
srv_ies_result srv_ies_meta_query_data(srv_ies_meta_handle hMeta,
                                       U32                 bufSize,
                                       void                *pRaw,
                                       U32                 *pSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT  result;
    CTBuffer *pBuffer;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_META_QUERY_DATA, 3, hMeta);

    if((NULL == hMeta) || (NULL == pSize))
    {
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    ASSERT(NULL != hMeta->pSPMO);

    result = caps_spmoGetDataBuffer(hMeta->pSPMO,
                                    &pBuffer);
    if (CFAILED(result))
    {
        IES_LOG_FAIL(result);
        IES_RET_FAIL(result); 
    }

    if((NULL == pRaw) || (bufSize < pBuffer->size))
    {
        *pSize = pBuffer->size;
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }

    // really copy the spmo
    memcpy(pRaw, pBuffer->data, pBuffer->size);
    *pSize = pBuffer->size;


    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ies_meta_destroy
 * DESCRIPTION
 *  Destroy the specified meta handle
 * RETURNS
 *  SRV_IES_OK if succeeded
 *****************************************************************************/
srv_ies_result srv_ies_meta_destroy(srv_ies_meta_handle hMeta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_META_DESTROY, 1, hMeta);

    if (NULL == hMeta)
    {
        ASSERT(0);
        IES_LOG_END(SRV_IES_E_INVALID_ARGS);
        return SRV_IES_E_INVALID_ARGS;
    }

    if(hMeta->jobInfo.pCurrJob)
    {
        srv_ies_job_cancel(hMeta->jobInfo.pCurrJob);
        hMeta->jobInfo.pCurrJob = NULL;
    }

    if (NULL != hMeta->pSource)
    {
        ctstream_destroy(hMeta->pSource);
        hMeta->pSource = NULL;
    }

    if (NULL != hMeta->pOption)
    {
        caps_spmoDestroyOptions(hMeta->pOption);
        hMeta->pOption = NULL;
    }

    if (NULL != hMeta->pSPMO)
    {
        caps_destroySpmo(hMeta->pSPMO);
        hMeta->pSPMO = NULL;
    }

    TYPED_FREE(hMeta, srv_ies_meta);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}

srv_ies_result srv_ies_meta_deinit(srv_ies_app_session_handle hApp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IS_ANY_ALLOCATED(hApp, srv_ies_meta);

    hApp->appState &= ~SRV_IES_APP_STATE_META_INITED;

    return SRV_IES_OK;
}

#endif  //__MMI_SRV_IES__
