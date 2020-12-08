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
 * VappBrowserMain.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_BRW_INTERFACE_H_
#define _VAPP_BRW_INTERFACE_H_

#include "MMI_features.h" 

#ifdef __MMI_BROWSER_2__

#include "BrowserSrvConfig.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_brw_struct.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "UriAgentSrvGprot.h"      /* for the Uri agent enum */
#include "BrowserSrvProts.h"
#include "wap_adp.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */


#ifdef __MMI_URI_AGENT__
typedef struct
{
    srv_uriagent_appid_enum ura_appid;
    U8 url[WAP_MAX_SEARCH_URL_LENGTH + 1];
    srv_uriagent_uri_request_hdlr_cb uri_agent_cb;
} vappBrwUhaHandlerStruct;
#endif /* __MMI_URI_AGENT__ */


/****************************************************************************
* Class VappBrwServiceInterface
****************************************************************************/
class VappBrwServiceInterface : public VfxObject
{
    //VFX_DECLARE_CLASS(VappBrwServiceInterface);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappBrwServiceInterface);
public:
    // Callback function provided to the service when the Application
    // requests to create a new service instance
    static void createInstanceHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the view trusted certificate operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests to delete the instance
    static void deleteInstanceHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the delete instance operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests to clear some security data like cache, cookie and authentication
    static void clearSecDataHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the clear security data operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests set the profile content to the service
    static void setProfileHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the set profile request operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests to get the details of a recent page
    static void getRecentPageHdlr(
        S32 user_data,       // the user data provided to the service by the application
        U32 result,              // the result of the get recent page operation
        void *obj                 // the void pointer containing the data if needed by application
        );
    // Callback function provided to the service when the Application
    // requests to get the recent page list
    static void getRecentPageListHdlr(
        S32 user_data,       // the user data provided to the service by the application
        U32 result,              // the result of the get recent page list operation
        void *obj                 // the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests to delete a particular recent page
    static void deleteRecentPageHdlr(
        S32 user_data,       // the user data provided to the service by the application
        U32 result,              // the result of the delete recent page operation
        void *obj                 // the void pointer containing the data if needed by application
        );

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    // Callback function provided to the service when the Application
    // requests to save a new page into offline memory
    static void savePageHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the save page operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );
    // Callback function provided to the service when the Application
    // requests to get the details of a particular saved page
    static void getStoredPageHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the get stored page list operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests to get the stored page list
    static void deleteStoredPageHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the delete stored page operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests to delete a particular stored page from offline memory
    static void getStoredPageListHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the delete stored page operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifdef WAP_SEC_SUPPORT
    // Callback function provided to the service when the Application
    // requests to get the details of a rtrusted certificate
    static void viewTrustedCertificateHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the view trusted certificate operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );
    // Callback function provided to the service when the Application
    // requests to get the trusted certificate list
    static void getTrustedCertificateListHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the get trusted certificate list operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    // Callback function provided to the service when the Application
    // requests to delete a particular trusted certificate
    static void deleteTrustedCertificateHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the delete trusted certificate operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );
#endif /* WAP_SEC_SUPPORT */

    // Callback function provided to the service when the Application
    // requests to service to initialize its ASM pool
    static void intializeServiceAsmPool(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the delete trusted certificate operation
        void *obj                 // [IN] the void pointer containing the data if needed by application
        );

    static void setProfileRspHandler(
        S32 user_data, 
        U32 result, 
        void *obj
        );

    static mmi_ret vappBrwWifiBearerStatusHandler(
        mmi_event_struct *param
        );

    static mmi_ret vappBrwBearerSwitchHandler(
        mmi_event_struct *param
        );

    VfxSignal3<S32 , U32 , void *> m_getRecentPagesListCallback;
    VfxSignal3<S32 , U32 , void *> m_getStoredPagesListCallback;
    VfxSignal3<S32 , U32 , void *> m_deleteStoredPageCallback;
    VfxSignal3<S32 , U32 , void *> m_deleteRecentPageCallback;
    VfxSignal3<S32 , U32 , void *> m_getStoredPageDetailsCallback;
    VfxSignal3<S32 , U32 , void *> m_createInstanceCallback;
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    VfxSignal3<S32 , U32 , void *> m_savePageCallback;
    #endif
    VfxSignal2<U8 , void *> m_transactionCallback;
    VfxSignal1<void *> m_documentInfoCallback;
    VfxSignal0 m_displayImageOptionCallback;
    VfxSignal1<void *> m_displayWapEditorCallback;
    VfxSignal1<vappBrwListMenuChoiceEnum> m_displayWapListMenuCallback;
    VfxSignal0 m_displayAuthenticationCallback;
    VfxSignal1<void *> m_secConfirmCallback;
    VfxSignal1<void *> m_bookmarkExportCallback;
    VfxSignal1<void *> m_errorIndCallback;
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    VfxSignal0 m_selectUploadFileCallback;
#endif
    VfxSignal1<void *> m_wmslDialogCallback;
    VfxSignal1<void *> m_bkmprovisioningCallback;
    VfxSignal0 m_relaunchCallback;
    VfxSignal1<U8 > m_deleteInstanceCallback;
    VfxSignal1<U8 > m_usbModeCallback;
    VfxSignal1<mmi_pen_event_type_enum> m_TouchFeedbackCallback;
    VfxSignal2<VfxU32, VfxU32> m_WifiBearerCallback;  
    VfxSignal1<VfxBool> m_bearerSwitchCallback;  
    VfxSignal0 m_setProfileCallback;  
    VfxSignal0 m_homepageSnapshotCallback;
    VfxSignal0 m_openBearerCallback;
    VfxSignal0 m_displayProgressPopupCallback;
    VfxSignal0 m_closeProgressPopupCallback;
};
 
#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_INTERFACE_H_ */
