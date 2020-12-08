
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
 * BrowserUIPlugIn.c
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
 *
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _VAPP_BRW_INTERFACE_CPP_
#define _VAPP_BRW_INTERFACE_CPP_

#ifdef __MMI_BROWSER_2__

/*  Include: MMI header file */
#include "vapp_brw_interface.h"
#include "vapp_brw_main.h"
#include "vcp_global_popup.h"

//VFX_IMPLEMENT_CLASS("VappBrwServiceInterface", VappBrwServiceInterface, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappBrwServiceInterface);

// Browser service event handler function 
#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "UriAgentSrvGprot.h"      /* for the Uri agent enum */
#include "BrowserSrvInterface.h"
#include "BrowserSrvMsgHdlr.h"
#include "CbmSrvGprot.h"
#include "Cbm_api.h"
#include "Wps_struct.h"
#include "vBookmark.h"
#include "PhoneBookGprot.h"
#include "UcmGprot.h"
#include "BrowserSrvProts.h"
#include "CbmSrvGprot.h"
#include "Das_struct.h"
/*#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif*/

extern void bam_received_transaction_status(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */

VfxS32 m_brwUhaAppId = 0;

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
extern "C" void vapp_brw_app_launch(void);

extern "C" void vapp_brw_app_launch_low_mem_mode(void);

extern "C" void vapp_brw_app_launch_by_sat(mmi_event_struct *event);
void vappBrwUriSchemeHandler(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb uri_agent_cb);


MMI_ID vapp_brw_app_launch_ext(void* param, U32 param_size)
{
    memset(g_srv_brw_cntx.url, 0, sizeof(g_srv_brw_cntx.url));
    vapp_brw_app_launch();
    return MMI_RET_OK;
}

void vapp_brw_display_popup(VfxU16 displayStr)
{
	VappBrowserUtility::displayPopup(
				displayStr,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
}
mmi_ret vapp_brw_app_launch_proc(mmi_event_struct *param)
{
	return MMI_RET_DONT_CARE;
}

void vapp_brw_start_browser_action(U8 option, U8 *url)
{
    U8 url_ascii[SRV_BRW_MAX_URL_LEN + 1];

    memset(url_ascii, 0, SRV_BRW_MAX_URL_LEN + 1);
    if (url)
    {
        mmi_ucs2_n_to_asc((CHAR*) url_ascii, (CHAR*) url, SRV_BRW_MAX_URL_LEN * ENCODING_LENGTH);
    }
	mmi_ucs2ncpy((char*)g_srv_brw_cntx.url, (char*)url, WAP_MAX_SEARCH_URL_LENGTH + 1);
	g_srv_brw_cntx.option = option;
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_START_BRW_ACTION, option);

    MMI_PRINT(MOD_MMI_INET_APP, MMI_INET_TRC_G4_BRW, "[BrowserMain][mmi_brw_start_browser_action] url=%s", url_ascii);
    switch (option)
    {
        case WAP_BROWSER_GOTO_URL_BACKGROUND:
        {
            MMI_ASSERT(url);
            if(m_browserAppID !=0)
            {
                srv_brw_load_url_req((U8*)url, WAP_BAM_UNKNOWN_CHARSET);
                memset(g_srv_brw_cntx.url, 0, sizeof(g_srv_brw_cntx.url));
            }
            else
            {
                vapp_brw_app_launch();
            }
            break;
        }
        case WAP_BROWSER_GOTO_URL:
        {
            MMI_ASSERT(url);
			#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
            if(m_bowserBookmarkCuiId != GRP_ID_INVALID)
            {
                VfxAppLauncher::terminate(m_bowserBookmarkCuiId);
            }
			#endif
            if(m_browserAppID != GRP_ID_INVALID)
            {
                ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_relaunchCallback.emit();
            }
            else
            {
                vapp_brw_app_launch();
            }
            break;
        }
		case WAP_BROWSER_LOW_MEMORY:
		{
			MMI_ASSERT(url);
			#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
			if(m_bowserBookmarkCuiId != GRP_ID_INVALID)
            {
                VfxAppLauncher::terminate(m_bowserBookmarkCuiId);
            }
			#endif
            if(m_browserAppID != GRP_ID_INVALID)
            {
                ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_relaunchCallback.emit();
            }
            else
            {
                vapp_brw_app_launch_low_mem_mode();
            }
			break;
		}
        default:
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_UNSUPPORTED_ACTION,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                MMI_EVENT_INFO_BALLOON);
            return;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwBootupInitCallback
 * DESCRIPTION
 *  This function is the callback function registered with the bootup application
 * to be called during bootup to initialize the Browser
 * call
 * PARAMETERS
 *  
 * RETURNS
 *  pBOOL 
 *****************************************************************************/
mmi_ret vappBrwBootupInitCallback(mmi_event_struct *evt)
{
#ifdef __MMI_URI_AGENT__
    srv_uriagent_err_enum err;
#endif 
    srv_brw_init();

#ifdef __MMI_URI_AGENT__
    err = srv_uriagent_register_hdlr_by_scheme(BRW_HTTP_URI_SCHEME, vappBrwUriSchemeHandler, MMI_TRUE);
    MMI_ASSERT(err == SRV_URIAGENT_ERR_OK);
    err = srv_uriagent_register_hdlr_by_scheme(BRW_HTTPS_URI_SCHEME, vappBrwUriSchemeHandler, MMI_TRUE);
    MMI_ASSERT(err == SRV_URIAGENT_ERR_OK);
#ifdef OBIGO_Q05A
    err = srv_uriagent_register_hdlr_by_scheme(BRW_FILE_URI_SCHEME, vappBrwUriSchemeHandler, MMI_TRUE);
    MMI_ASSERT(err == SRV_URIAGENT_ERR_OK);
#endif /* OBIGO_Q05A */
#endif /* __MMI_URI_AGENT__ */ 

    m_browserAppID = GRP_ID_INVALID;

    VappBrwServiceInterface *brwServiceInterface = VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_if_enter_usb_mode
 * DESCRIPTION
 *  This function is the handler function registered to handle the USB mode
 * enter event call
 * PARAMETERS
 *  
 * RETURNS
 *  pBOOL 
 *****************************************************************************/
mmi_ret vappBrwEnterUsbModeHandler(mmi_event_struct* para)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_usbModeCallback.emit(1);
    return MMI_RET_OK;
}

mmi_ret vappBrwExitUsbModeHandler(mmi_event_struct* para)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_usbModeCallback.emit(0);
    return MMI_RET_OK;
}

//#pragma arm section code = "DYNAMIC_CODE_BROWSER_ROCODE", rodata = "DYNAMIC_CODE_BROWSER_RODATA"
/*****************************************************************************
 * FUNCTION
 *  vappBrwBearerStatusHandler
 * DESCRIPTION
 *  This func is callback for getting the current bearer status
 * PARAMETERS  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwBearerStatusHandler(mmi_event_struct* event)
{
    return MMI_RET_OK;
}

#ifdef __MMI_URI_AGENT__
void onUriScheemConfirmDialog (VfxId id, void *userData) 
{
    m_brwUhaAppId = 0;
    vappBrwUhaHandlerStruct *uhaHandler = (vappBrwUhaHandlerStruct*)userData;
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            mmi_chset_utf8_to_ucs2_string((U8*) g_srv_brw_cntx.url, (WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH, (U8*)uhaHandler->url);
            vapp_brw_start_browser_action(WAP_BROWSER_GOTO_URL, (U8*)g_srv_brw_cntx.url);
            if (uhaHandler->uri_agent_cb)
            {
                uhaHandler->uri_agent_cb(uhaHandler->ura_appid, SRV_URIAGENT_APPID_BRW, MMI_TRUE);
            }
            break;
        }
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        case VCP_POPUP_BUTTON_NO_PRESSED:
        {
            if (uhaHandler->uri_agent_cb)
            {
                uhaHandler->uri_agent_cb(uhaHandler->ura_appid, SRV_URIAGENT_APPID_BRW, MMI_FALSE);
            }
        	mmi_frm_temp_free(uhaHandler);
            break;
        }

        default:
            break;
    }
}
#endif

 /*****************************************************************************
 * FUNCTION
 *  vappBrwUriSchemeHandler
 * DESCRIPTION
 *  This function is the callback function registered with the URI 
 * Agent to launch URI schemes handled by the Browser
 * PARAMETERS
 *  
 * RETURNS
 *  void 
 *****************************************************************************/
void vappBrwUriSchemeHandler(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb uri_agent_cb)
{
    if (strlen((CHAR*) url) > WAP_MAX_SEARCH_URL_LENGTH)
    {
        VappBrowserUtility::displayPopup(
            STR_GLOBAL_INVALID_URL,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
		    MMI_EVENT_INFO_BALLOON);
        if (uri_agent_cb)
        {
            uri_agent_cb(ura_appid, SRV_URIAGENT_APPID_BRW, MMI_FALSE);
        }
        return;
    }


    if(m_brwUhaAppId != 0)
    {
        if (uri_agent_cb)
        {
            uri_agent_cb(ura_appid, SRV_URIAGENT_APPID_BRW, MMI_FALSE);
        }
        return;
    }

	#ifdef __MMI_URI_AGENT__
    if (options == SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
    {
        vappBrwUhaHandlerStruct *uhaHandler = NULL;
        uhaHandler = (vappBrwUhaHandlerStruct*)mmi_frm_temp_alloc(sizeof(vappBrwUhaHandlerStruct));
        memset(uhaHandler, 0, sizeof(vappBrwUhaHandlerStruct));

        uhaHandler->ura_appid = ura_appid;
        strcpy((CHAR*) uhaHandler->url, (CHAR*) url);
        uhaHandler->uri_agent_cb = uri_agent_cb;

        m_brwUhaAppId = vcp_global_popup_show_confirm_two_button_id(GRP_ID_ROOT,
            VCP_POPUP_TYPE_QUESTION,
            STR_ID_VAPP_BRW_UHA_CONNECT_TO_BROWSER,
            STR_GLOBAL_YES,
            STR_GLOBAL_NO,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL,
            onUriScheemConfirmDialog,
            (void*)uhaHandler);
    }
    else
	#endif
    {
        mmi_chset_utf8_to_ucs2_string((U8*) g_srv_brw_cntx.url, (WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH, (U8*)url);
        vapp_brw_start_browser_action(WAP_BROWSER_GOTO_URL, (U8*)g_srv_brw_cntx.url);
        if (uri_agent_cb)
        {
            uri_agent_cb(ura_appid, SRV_URIAGENT_APPID_BRW, MMI_TRUE);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceErrorIndHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_ERROR_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceErrorIndHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_errorIndCallback.emit((void*)event);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceErrorPopupHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SHOW_POPUP emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceErrorPopupHandler(mmi_event_struct *event)
{
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceStartTransactionHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceStartTransactionHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_transactionCallback.emit(WAP_BAM_STATUS_START_TRANSACTION, (void*)event);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceEndTransactionHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceEndTransactionHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_transactionCallback.emit(WAP_BAM_STATUS_END_TRANSACTION, (void*)event);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceContinueTransactionHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceContinueTransactionHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_transactionCallback.emit(WAP_BAM_STATUS_TRANSACTION_STATUS, (void*)event);
    bam_received_transaction_status();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceDocumentIndHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_DOC_INFO_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceDocumentIndHandler(mmi_event_struct *event)
{
	((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_documentInfoCallback.emit((void*)event);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceSecConfirmHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SHOW_SEC_CNF_DLG emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceSecConfirmHandler(mmi_event_struct *evt)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_secConfirmCallback.emit((void*)evt);
    return MMI_RET_OK;
}

#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceSelectFileIndHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SELECT_FILE_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceSelectFileIndHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_selectUploadFileCallback.emit();
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  vappBrwGetPBResult
 * DESCRIPTION
 *  Convert the UCM error into WAP error.
 * PARAMETERS
 *  res          [IN]
 * RETURNS
 *  Error code in WAP error.
 *****************************************************************************/
#ifdef __MMI_URI_AGENT__
U16 vappBrwGetPBResult(S32 res)
{
    switch (res)
    {
        case MMI_PHB_URIAGENT_ERR_OK:
        {
            return WAP_BAM_WTAI_RESULT_OK;
        }
        case MMI_PHB_URIAGENT_ERR_URI_FORMAT_WRONG:
        {
            return WAP_BAM_WTAI_RESULT_INVALID;
        }
        case MMI_PHB_URIAGENT_ERR_NAME_TOO_LONG:
        {
            return WAP_BAM_WTAI_RESULT_PB_IN_NAME;
        }
        case MMI_PHB_URIAGENT_ERR_NUM_TOO_LONG:
        {
            return WAP_BAM_WTAI_RESULT_PB_NUMBER_TO_LONG;
        }
        case MMI_PHB_URIAGENT_ERR_PHB_WRITE_ERROR:
        {
            return WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_ENTRY;
        }
        case MMI_PHB_URIAGENT_ERR_PHB_IS_FULL:
        {
            return WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_IS_FULL;
        }
        case MMI_PHB_URIAGENT_ERR_PHB_NOT_READY:
        case MMI_PHB_URIAGENT_ERR_PHB_PROCESS_USIM:
        case MMI_PHB_URIAGENT_ERR_PHB_IN_SYNC:
        case MMI_PHB_URIAGENT_ERR_FDN_ON_ERROR:
        default:
        {
            return WAP_BAM_WTAI_RESULT_UNSPECIFIED;
        }
    }
}
#endif

#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  vappBrwGetTelResult
 * DESCRIPTION
 *  Convert the UCM error into WAP error.
 * PARAMETERS
 *  res          [IN]
 * RETURNS
 *  Error code in WAP error.
 *****************************************************************************/
U16 vappBrwGetTelResult(S32 res)
{
    switch (res)
    {
        case MMI_UCM_RESULT_OK:
        {
            return WAP_BAM_WTAI_RESULT_OK;
        }
        case MMI_UCM_RESULT_INVALID_NUMBER:
        case MMI_UCM_RESULT_EMPTY_NUMBER:
        {
            return WAP_BAM_WTAI_RESULT_INVALID;
        }
        case MMI_UCM_RESULT_CALLED_PARTY_BUSY:
        {
            return WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_IS_BUSY;
        }
        case MMI_UCM_RESULT_NETWORK_NOT_AVAILABLE:
        {
            return WAP_BAM_WTAI_RESULT_TEL_NETWORK_NOT_AVAILABLE;
        }
        case MMI_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED:
        {
            return WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_NO_ANSWER;
        }
        case MMI_UCM_RESULT_NO_ACTIVE_VOICE_CALL:
        {
            return WAP_BAM_WTAI_RESULT_TEL_NO_ACTIVE_CONNECTION;
        }
        case MMI_UCM_RESULT_USER_ABORT:
        case MMI_UCM_RESULT_UCM_BUSY:
        case MMI_UCM_RESULT_CANCEL:
        case MMI_UCM_RESULT_FLIGHT_MODE_PROHIBIT:
        case MMI_UCM_RESULT_PREFERRED_MODE_PROHIBIT:
        case MMI_UCM_RESULT_SOS_CALL_EXISTS:
        case MMI_UCM_RESULT_SOS_NUMBER_ONLY:
        case MMI_UCM_RESULT_UNSPECIFIED_ERROR:
        default:
        {
            return WAP_BAM_WTAI_RESULT_UNSPECIFIED;
        }
    }
}
#endif /* __MMI_UCM__ */

#ifdef __MMI_URI_AGENT__
void vappBrwUriCallback(srv_uriagent_appid_enum ura_appid, srv_uriagent_appid_enum uha_appid, S32 result)
{
    if (ura_appid == SRV_URIAGENT_APPID_BRW)
    {
        switch (uha_appid)
        {
            case SRV_URIAGENT_APPID_PHONEBOOK:
            {
            #ifdef OBIGO_Q03C_BROWSER
                srv_brw_uri_req_rsp((U16) vappBrwGetPBResult(result));
            #else
                srv_brw_wtai_pb_rsp((U16) vappBrwGetPBResult(result));
            #endif
                break;
            }
        #ifdef __MMI_UCM__
            case SRV_URIAGENT_APPID_CALLMANAGER:
            {
            #ifdef OBIGO_Q03C_BROWSER
                srv_brw_uri_req_rsp((U16) vappBrwGetTelResult(result));
            #else
                srv_brw_wtai_tel_rsp((U16) vappBrwGetTelResult(result));
            #endif
                break;
            }
        #endif /* __MMI_UCM__ */
            default:
            #ifdef OBIGO_Q03C_BROWSER
                srv_brw_uri_req_rsp(WAP_BAM_WTAI_RESULT_UNSPECIFIED);
            #endif /* OBIGO_Q03C_BROWSER */
                break;
        }
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceUriReqHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_URI_REQ_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceUriReqHandler(mmi_event_struct *event)
{
	#ifdef __MMI_URI_AGENT__
    srv_brw_uri_req_event_struct *uri_evt = (srv_brw_uri_req_event_struct*)event;
    srv_uriagent_err_enum err;
    if (srv_uriagent_has_registered_hdlr((CHAR*)uri_evt->url_string))
    {
        err = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                (CHAR*)uri_evt->url_string,
                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP,
                vappBrwUriCallback);
        /* Reject the request if URI Agent is still processing */
        if (err == SRV_URIAGENT_ERR_PROCESSING)
        {
        #ifdef OBIGO_Q03C_BROWSER
            srv_brw_uri_req_rsp(WAP_BAM_WTAI_RESULT_UNSPECIFIED);
        #endif /* OBIGO_Q03C_BROWSER */
           VappBrowserUtility::displayPopup(
		        STR_ID_VAPP_BRW_URI_BUSY,
		        MMI_NMGR_BALLOON_TYPE_FAILURE,
			    MMI_EVENT_INFO_BALLOON);
            return MMI_RET_OK;
        }
        MMI_ASSERT(err == SRV_URIAGENT_ERR_OK);
    }
    else
	#endif
    {
       VappBrowserUtility::displayPopup(
		    STR_GLOBAL_NOT_SUPPORTED,
		    MMI_NMGR_BALLOON_TYPE_FAILURE,
			MMI_EVENT_INFO_BALLOON);
    #ifdef OBIGO_Q03C_BROWSER
        srv_brw_uri_req_rsp(WAP_BAM_WTAI_RESULT_UNSPECIFIED);
    #endif /* OBIGO_Q03C_BROWSER */
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceAuthenticationIndHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SHOW_AUTH_DLG emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceAuthenticationIndHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayAuthenticationCallback.emit();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceStartBrowserHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_START_BROWSER_ACTION_IND emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceStartBrowserHandler(mmi_event_struct *event)
{
    srv_brw_startup_req_event_struct *startup_evt = (srv_brw_startup_req_event_struct*)event;
    vapp_brw_start_browser_action(startup_evt->req_type, (U8*)startup_evt->url_ucs2);
    return MMI_RET_OK;
}


#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 * FUNCTION
 *  vappBrwDisplayWapEditor
 * DESCRIPTION
 *  This func is the interface function called by Widget to display the full
 * screen editor for the Web page
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vappBrwDisplayWapEditor(vappBrwFullScreenEditorStruct *obj)
{
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
	((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayWapEditorCallback.emit((void*)obj);
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwCloseWapEditor
 * DESCRIPTION
 *  This func is the interface function called by Widget to close the full
 * screen editor displayed for the Web page
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vappBrwCloseWapEditor(void)
{
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    if(m_brwApp->scr->page->m_editorInput)
    {
        VFX_OBJ_CLOSE(m_brwApp->scr->page->m_editorInput);
        m_brwApp->scr->page->resumeBrowserRendering();
    }
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwDisplayWapListMenu
 * DESCRIPTION
 *  This func is the interface function called by Widget to display the WAP
 * list menu for Web page
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vappBrwDisplayWapListMenu(vappBrwListMenuChoiceEnum listMenuType)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayWapListMenuCallback.emit(listMenuType);
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwCloseWapListMenu
 * DESCRIPTION
 *  This func is the interface function called by Widget to close the WAP
 * list menu for Web page
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vappBrwCloseWapListMenu(void)
{
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    if(m_brwApp->scr->page->m_wapListMenu)
    {
        VFX_OBJ_CLOSE(m_brwApp->scr->page->m_wapListMenu);
        m_brwApp->scr->page->resumeBrowserRendering();
    }
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwDisplayWapEditor
 * DESCRIPTION
 *  This func is the interface function called by Widget to display the full
 * screen editor for the Web page
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vappBrwSendTouchFeedback(mmi_pen_event_type_enum obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_TouchFeedbackCallback.emit(obj);
}
/*****************************************************************************/

#endif


#ifdef __SAT__
/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceSatLaunchHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_SAT_LAUNCH_REQ emitted by the Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceSatLaunchHandler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_sat_launch_req_struct *sat_evt = (srv_brw_sat_launch_req_struct*)event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
        #if (MMI_MAX_SIM_NUM >= 2)
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
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
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
        #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
    U8 url_ascii[SRV_BRW_MAX_URL_LEN + 1];

    memset(url_ascii, 0, SRV_BRW_MAX_URL_LEN + 1);
    if (sat_evt->url)
    {
        mmi_ucs2_n_to_asc((CHAR*) url_ascii, (CHAR*) sat_evt->url, SRV_BRW_MAX_URL_LEN * ENCODING_LENGTH);
    }
	mmi_ucs2ncpy((char*)g_srv_brw_cntx.url, (char*)sat_evt->url, SRV_BRW_MAX_URL_LEN + 1);
	g_srv_brw_cntx.option = WAP_BROWSER_GOTO_URL;
    if(m_browserAppID != GRP_ID_INVALID)
    {
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_relaunchCallback.emit();
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 16, 16, 16, 0);
        //vapp_brw_app_launch();
        vapp_brw_app_launch_by_sat(event);
    }
    return MMI_RET_OK;
}
#endif


mmi_ret vappBrwServiceElementFocusHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayImageOptionCallback.emit();
    return MMI_RET_OK;
}

void vappBrwBookmarkOptionsHandler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    FS_HANDLE file_handle = FS_Open((UI_string_type) filepath, FS_READ_ONLY);
    if (file_handle >= 0)
    {
        if (srv_vbkm_reader_validate_file(file_handle))
        {
            VfxWString url;
            VfxWChar *urlBuff = url.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
            srv_vbkm_reader_extract_url(file_handle, (U8*)urlBuff);
            vapp_brw_start_browser_action(WAP_BROWSER_GOTO_URL, (U8*)urlBuff);
            url.unlockBuf();
        }
        else
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_INVALID_BOOKMARK_FILE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                MMI_EVENT_INFO_BALLOON);
        }
        FS_Close(file_handle);
        return;
    }
    else
    {
        VappBrowserUtility::fileSystemErrorHandler(file_handle);
        return;
    }
}


void vappBrwCopyBookmarkCallback(void *msg)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_bookmarkExportCallback.emit(msg);
}

mmi_ret vappBrwWmlsDlgHandler(mmi_event_struct *param)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_wmslDialogCallback.emit((void*) param->user_data);
    return MMI_RET_OK;
}

mmi_ret vappBrwBkmProvisioningHandler(mmi_event_struct *param)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_bkmprovisioningCallback.emit((void*) param->user_data);
    return MMI_RET_OK;
}

void vappBrwCloseSocketsHdlr(S32 user_data, U32 result, void *obj)
{
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 8, 0, 0, 0);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_bearerSwitchCallback.emit(VFX_TRUE);
}


void vappBrwTakeHomepageSnapshot(void)
{
#ifndef __MMI_BRW_SLIM__
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_homepageSnapshotCallback.emit();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vappBrwServiceOpenBearerHandler
 * DESCRIPTION
 *  This func is the handler function registered with the Framework for the
 * event EVT_ID_SRV_BRW_OPEN_BEARER_IND emitted by the 
 * Browser service
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vappBrwServiceOpenBearerHandler(mmi_event_struct *event)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_openBearerCallback.emit();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwDisplayProgressPopup
 * DESCRIPTION
 *  This func is the interface function called by Widget to display the 
 * Please wait progress popup
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vappBrwDisplayProgressPopup(void)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayProgressPopupCallback.postEmit();
}

/*****************************************************************************
 * FUNCTION
 *  vappBrwCloseProgressPopup
 * DESCRIPTION
 *  This func is the interface function called by Widget to close the 
 * Please wait progress popup
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vappBrwCloseProgressPopup(void)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_closeProgressPopupCallback.postEmit();
}

#ifdef __cplusplus
}
#endif /* __cplusplus */



void VappBrwServiceInterface :: getRecentPageListHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_getRecentPagesListCallback.emit(user_data, result, obj);
}

void VappBrwServiceInterface::deleteRecentPageHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_deleteRecentPageCallback.emit(user_data, result, obj);
}

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
void VappBrwServiceInterface :: getStoredPageListHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_getStoredPagesListCallback.emit(user_data, result, obj);
}

void VappBrwServiceInterface :: getStoredPageHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_getStoredPageDetailsCallback.emit(user_data, result, obj);
}

void VappBrwServiceInterface::deleteStoredPageHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_deleteStoredPageCallback.emit(user_data, result, obj);
}

#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

void VappBrwServiceInterface::createInstanceHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_createInstanceCallback.emit(user_data, result, obj);
}

void VappBrwServiceInterface::deleteInstanceHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_deleteInstanceCallback.emit(0);
    mmi_frm_asm_free_r(VAPP_BROWSER, g_srv_brw_memory_pool);
	kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 4);
    g_srv_brw_memory_pool = NULL;
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_deleteInstanceCallback.emit(1);
    if(user_data > 0)
    {
        vapp_brw_app_launch();
    }
}
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__

void VappBrwServiceInterface::savePageHdlr(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_savePageCallback.emit(user_data, result, obj);
}
#endif
void VappBrwServiceInterface::setProfileRspHandler(S32 user_data, U32 result, void *obj)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.emit();
}

mmi_ret VappBrwServiceInterface::vappBrwWifiBearerStatusHandler(mmi_event_struct *param)
{
    srv_cbm_bearer_info_struct *bearer_info_p = (srv_cbm_bearer_info_struct*)param;
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p &&  g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_activating_wifi)
    {
        switch (bearer_info_p->state)
        {
            case SRV_CBM_ACTIVATED:
            {
                srv_wap_prof_profile_content_struct *profile_content_p;
                srv_brw_act_req_struct obj = {0};
                srv_brw_set_profile_req_struct prof = {0};
                srv_brw_get_profile_content((void **)&profile_content_p);
                obj.rsp_callback = VappBrwServiceInterface::setProfileRspHandler;
                prof.currprof = profile_content_p;
                prof.setting_id = wap_bam_setting_type_profile;
            #ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
                if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer)
            #endif
                {
                    prof.type = wap_bam_do_not_set_profile_to_brs;
                }
                obj.req_data = (void*)&prof;
                srv_brw_set_profile_req_by_data(&obj);
                OslMfree(profile_content_p);
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_activating_wifi = MMI_FALSE;
                MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 1, 0, 0, 0);
                ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_WifiBearerCallback.emit(bearer_info_p->state, bearer_info_p->error_cause);
            }
            break;

            case SRV_CBM_DEACTIVATED:
            {
                U8 app_id;
                srv_wap_prof_profile_content_struct *profile_content_p;
                if (srv_brw_is_holding_bearer())
                {
                    srv_brw_set_bearer(MMI_FALSE);
                }
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_activating_wifi = MMI_FALSE;
                srv_brw_get_profile_content((void **)&profile_content_p);
                app_id = cbm_get_app_id(profile_content_p->data_account_primary_id);
                OslMfree(profile_content_p);
                srv_cbm_deregister_bearer_info(app_id);
                MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 2, 0, 0, 0);
                ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_WifiBearerCallback.emit(bearer_info_p->state, bearer_info_p->error_cause);
            }
            break;
        }
    }
    return MMI_RET_OK;
}

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
mmi_ret VappBrwServiceInterface::vappBrwBearerSwitchHandler(mmi_event_struct *param)
{
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p &&  g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_activating_wifi)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 12, 0, 0, 0);
        return MMI_RET_OK;
    }
    srv_cbm_bearer_event_struct *evt = (srv_cbm_bearer_event_struct*) param;
    if(evt->type == SRV_CBM_BEARER_EVENT_DISCONNECT)
    {
        if(srv_brw_is_in_transaction())
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer = MMI_TRUE;
            MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 8, 0, 0, 0);
        }
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 9, 0, 0, 0);
        return MMI_RET_OK;
    }
    wap_mmi_file_dl_nw_switch_ind_struct *myMsgPtr = (wap_mmi_file_dl_nw_switch_ind_struct *)
		    construct_local_para((kal_uint16) sizeof(wap_mmi_file_dl_nw_switch_ind_struct),
				    TD_RESET);
    myMsgPtr->user_result = evt->user_result;
    myMsgPtr->switch_type = (kal_int32) evt->switch_type;
    srv_brw_event_hdlr_send_ilm_to_mmi(MSG_ID_WAP_MMI_FILE_DL_NW_SWITCH_IND, myMsgPtr, NULL);
    if (evt->user_result)
    {
        if (srv_brw_is_holding_bearer())
        {
            MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 10, 0, 0, 0);
            srv_brw_set_bearer(MMI_FALSE);
        }
        if(srv_brw_is_in_transaction())
        {
            MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 11, 0, 0, 0);
            srv_brw_stop_page_fetching_req();
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer = MMI_TRUE;
        }
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 13, 0, 0, evt->switch_type);
        if (evt->switch_type ==  SRV_CBM_BEARER_SWITCH_PS_TO_WIFI
            || evt->switch_type == SRV_CBM_BEARER_SWITCH_WIFI_TO_PS
            || evt->switch_type == SRV_CBM_BEARER_SWITCH_WIFI_TO_WIFI)
        {
            if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_closing_sockets)
            {
                MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 5, 0, 0, evt->switch_type);
            }
            else
            {
                srv_brw_act_req_struct obj = {0};
                srv_brw_list_element_req_struct data;
                MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 6, 0, 0, evt->switch_type);
                obj.rsp_callback = vappBrwCloseSocketsHdlr;
                srv_brw_release_sockets_req(&obj);
                ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_bearerSwitchCallback.emit(VFX_FALSE);
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 7, 0, 0, 0);
    }
    return MMI_RET_OK;
}
#endif
//#pragma arm section code, rodata


#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */

MMI_BOOL vappBrwRenderedPageOpen(void)
{
    if(m_browserAppID !=0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

//To remove
void mmi_brw_bookmarks_goto_from_fmgr(void *fullname, int is_short)
{
}
void mmi_brw_bookmarks_open_from_fmgr(void *fullname, int is_short)
{
}
U16 mmi_brw_get_error_string_id(void)
{
    return MMI_RET_OK;
}
U16 mmi_brw_get_screen_id(void)
{
    return MMI_RET_OK;
}
void mmi_brw_start_browser_action(U8 option, U8 *url)
{ 
}
void mmi_brw_ren_page_clear_keys(void)
{}
kal_bool mmi_brw_is_active_profile_in_use(mmi_brw_sim_id_enum sim_id)
{return KAL_FALSE;}
MMI_BOOL mmi_brw_is_rendered_page_present(void)
{return MMI_TRUE;}
MMI_BOOL mmi_brw_is_rendered_page_active(void)
{return MMI_TRUE;}
MMI_BOOL mmi_brw_is_temp_busy_screen_active(void)
{return MMI_FALSE;}
void mmi_brw_wait_user_action_handler(
        int enable_positive_sk,
        const char *positive_label,
        int positive_label_len,
        int enable_negative_sk,
        const char *negative_label,
        int negative_label_len)
{}

MMI_BOOL mmi_brw_is_in_transaction(void)
{return MMI_FALSE;}
U16 mmi_brw_get_wap_icon(void)
{return MMI_TRUE;}
void mmi_brw_paint_outside_look(void)
{}
void mmi_brw_load_service_message (kal_uint8 *url, kal_bool is_from_inbox, kal_uint16 sim_id)
{}
void mmi_brw_app_deinit(void)
{
}
void mmi_brw_app_if_reload_req_processed(void)
{} 
MMI_BOOL mmi_brw_app_is_temp_busy_screen_active(void)
{return MMI_FALSE;}
kal_bool mmi_brw_scrn_is_present(void)
{return KAL_FALSE;}

void mmi_brw_app_if_load_url_req_processed(void)
{
}
#ifdef __cplusplus
}
#endif /* __CPLUSPLUS__ */

#endif /* __MMI_BROWSER_2__ */


#endif /* _VAPP_BRW_INTERFACE_CPP_ */
