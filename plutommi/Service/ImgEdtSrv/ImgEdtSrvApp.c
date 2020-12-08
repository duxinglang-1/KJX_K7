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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SRV_IES__
#include "ImgEdtSrvConfig.h"
#include "ImgEdtSrvStruct.h"

DECLARE_STATIC_RESERVE_SLOT(srv_ies_app_session, 2);

U32 srv_ies_app_session_get_required_mem_size(srv_ies_feature_enum feature)
{
    U32 memorySize;

    switch(feature)
    {
        case SRV_IES_FEATURE_EDIT:
            memorySize = SRV_IES_EDIT_WORK_MEMORY;
            break;
        case SRV_IES_FEATURE_ALL:
            memorySize = SRV_IES_ALL_WORK_MEMORY;
            break;
        case SRV_IES_FEATURE_VIEW:
            memorySize = SRV_IES_VIEW_WORK_MEMORY;
            break;
        default:
            ASSERT(0);
            return 0;
    }

    return memorySize;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_app_session_create(MMI_ID                        appID, 
                                          srv_ies_feature_enum          feature,
                                          void                          *pBuf, 
                                          U32                           bufSize, 
                                          srv_ies_app_session_handle    *pHApp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_app_session *pApp;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_APP_SESSION_CREATE, 5, appID);

    TYPED_ALLOC(pApp, srv_ies_app_session);
    ASSERT(NULL != pApp);

    // Try to pervent double-initialization
    ASSERT(SRV_IES_APP_SESSION_PATTERN != pApp->guard);

    pApp->guard     = SRV_IES_APP_SESSION_PATTERN;
    pApp->appID     = appID;
    pApp->pBuf      = pBuf;
    pApp->bufSize   = bufSize;
    pApp->feature   = feature;

    // For fixing MAUI_02730397 temporarily
    if(!is_caps_engine_inited())
    {
        caps_engine_init(pBuf, bufSize);
        pApp->bufOwner = MMI_TRUE;
    }
    else
    {
        pApp->bufOwner = MMI_FALSE;
    }

    srv_ies_meta_init(pApp);

    srv_ies_job_init(pApp);

    if(pHApp)
    {
        *pHApp = pApp;
    }

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


/* see ImgEdtSrvGpro.h for interface documentation */
srv_ies_result srv_ies_app_session_destroy(srv_ies_app_session_handle hApp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_APP_SESSION_DESTROY, 1, hApp);

    if (NULL == hApp)
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    ASSERT(SRV_IES_APP_SESSION_PATTERN == hApp->guard);

    // Check if there are any image leakage   
    srv_ies_job_deinit(hApp);

    srv_ies_meta_deinit(hApp);

    //IS_ANY_ALLOCATED(hApp, srv_ies_image);

    if (MMI_TRUE == hApp->bufOwner)
    {
        caps_engine_deinit();
    }

    memset(hApp, 0x0, sizeof(srv_ies_app_session));
    TYPED_FREE(hApp, srv_ies_app_session);

    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


srv_ies_result srv_ies_app_session_get_buf_ptr(srv_ies_app_session_handle   hApp,
                                               void                         **ppBuf)
{
    if(NULL == ppBuf)
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    *ppBuf = hApp->pBuf;

    return SRV_IES_OK;
}

#endif //__MMI_SRV_IES__
