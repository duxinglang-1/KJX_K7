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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef _VAPP_BRW_MAIN_CPP_
#define _VAPP_BRW_MAIN_CPP_

#ifdef __MMI_BROWSER_2__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "vapp_brw_main.h"
#include "vapp_brw_interface.h"
#include "vapp_brw_title_bar.h"
#include "vapp_brw_home_page.h"
#include "mmi_rp_vapp_browser_def.h"
#ifdef __MMI_UNIFIED_COMPOSER__
#include "vapp_uc_gprot.h"
#endif
#if defined(__MMI_OPP_SUPPORT__ )
#include "vcui_bt_gprot.h"
#include "vapp_bt_send_gprot.h"
#endif
#include "vapp_fmgr_cui_gprot.h"
#include "vcp_menu_popup.h"
#include "vapp_usb_gprot.h"
#include "vcp_global_popup.h"

#ifdef __MMI_SMS_COMPOSER__
	#include "vcui_sms_composer_gprot.h"
#endif

mmi_id m_browserAppID;
VfxBool m_isLowMemMode = VFX_FALSE;
VfxBool m_exitScreen = VFX_FALSE;
/* Kamal */
#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "BrowserSrvInterface.h"      /* for the Uri agent enum */
#include "BrowserSrvMsgHdlr.h"      /* for the Uri agent enum */
#include "EmailAppGprot.h"      /* for the email API mmi_email_is_email_can_forward */
#include "BTMMIScrGprots.h"      /* for the email API mmi_email_is_email_can_forward */
#include "FileMgrSrvGprot.h"
#include "UcSrvGprot.h"
#include "UcmSrvGprot.h"
#include "EmailAppGprot.h"
#include "Wps_struct.h"
#include "Conversions.h"
#include "NwUsabSrvGprot.h"
#include "NetSetSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "Drm_gprot.h"
#include "USBsrvGprot.h"
#include "vfx_adp_device.h"
#include "ModeSwitchSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "CbmSrvGprot.h"
#include "Cbm_api.h"
#include "ProfilesSrvGprot.h"
#include "custom_events_notify.h"
#include "BrowserSrvGProt.h" 	/* for SAT remember */

/*#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif*/


extern void mmi_frm_set_keypad_mode(U8 mode);
extern void widget_accept_fullscreen_input_from_browser(kal_uint8 *inputbuffer);
extern U32 widget_return_no_of_menu_items(void);
extern pBOOL widget_fullscreen_checkbox_menu_get_item_hdlr(S32 item_index, UI_string_type str_buff);
extern void widget_fullscreen_checkbox_menu_okay(void);
extern void widget_checkbox_set_selection_state(int index, MMI_BOOL state);
extern MMI_BOOL widget_checkbox_get_selection_state(int index);
extern void widget_fullscreen_checkbox_menu_back(void);
extern void widget_exit_fullscreen_editor_with_cancel_level1(void);
extern U16 widget_get_selected_radio_id(void);
extern pBOOL widget_fullscreen_radio_menu_get_item_hdlr(S32 item_index, UI_string_type str_buff,PU8 *img_buff_p,U8 str_img_mask);
extern void widget_fullscreen_radio_menu_back(void);
extern void widget_fullscreen_radio_menu_okay(void);
extern void widget_set_item_radio_menu(int index);
extern void widget_create_web_page_bmp (CHAR* file_name);
extern GDI_RESULT gdi_image_encode_file_to_jpeg(
            CHAR *src_file_name,
            CHAR *dest_file_name,
            S32 dest_width,
            S32 dest_height,
            U8 *buf_ptr,
            S32 buf_size);
extern void widget_checkbox_reset_selection_state(void);
extern void widget_paintbox_free_doubble_buffer(void);
extern PU8 layer_buf_ptr;
extern void widget_MMI_key_handler(void);
extern U8 mmi_wap_prof_register_cbm_app_id(MMI_BOOL id, srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id);
extern void mmi_brw_app_srvHdlr_set_profile_req(void);

#ifdef __cplusplus
}
#endif /* __CPLUSPLUS__ */

VfxSignal1<void *> VappBrowserApp::m_eventCallback;

extern "C" void vapp_brw_app_launch_by_sat(mmi_event_struct * event)
{
	MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_COMMON_GATEWAY);
	//VappBrowserUtility::checkNetworkStatus();
	m_isLowMemMode = VFX_FALSE;
	if(VFX_TRUE != VappBrowserUtility::checkNetworkStatus())//VappBrowserUtility::checkNetworkStatus();
	{
		return;
	}
	srv_brw_sat_launch_req_struct *sat_evt = (srv_brw_sat_launch_req_struct*)event;
	g_srv_brw_cntx.session_sim_id = sat_evt->sim_setting;
	#if (defined(__SAT__) && defined(__MMI_WLAN_FEATURES__))
    g_srv_brw_cntx.app_type = SRV_BRW_APPTYPE_NO_WIFI;
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 16, 16, 0, g_srv_brw_cntx.app_type);
	#endif
	/*#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Load(DYNAMIC_CODE_COMPRESS_BROWSER, 0, 0);
	#endif*/
	VfxAppLauncher::launch( 
			VAPP_BROWSER,
			VFX_OBJ_CLASS_INFO(VappBrowserApp),
			GRP_ID_ROOT);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_create_service_instance
 * DESCRIPTION
 *  This func is used for creating a instance of Browser WAP service for 
 * launching Browser.
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void vapp_brw_app_launch_low_mem_mode(void)
{
	MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_COMMON_GATEWAY);	
	m_isLowMemMode = VFX_TRUE;
	if(VFX_TRUE != VappBrowserUtility::checkNetworkStatus())//VappBrowserUtility::checkNetworkStatus();
	{
		return;
	}
	VappBrowserUtility::setSimSettingId();
// TODO:check for re-enterance cases
/*#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Load(DYNAMIC_CODE_COMPRESS_BROWSER, 0, 0);
	#endif*/
	VfxAppLauncher::launch( 
		VAPP_BROWSER_LOW_MEM,
		VFX_OBJ_CLASS_INFO(VappBrowserApp),
		GRP_ID_ROOT);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_app_create_service_instance
 * DESCRIPTION
 *  This func is used for creating a instance of Browser WAP service for 
 * launching Browser.
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void vapp_brw_app_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_COMMON_GATEWAY);
	m_isLowMemMode = VFX_FALSE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    	#ifndef __OP01__
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifndef __OP01__
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    	#ifndef __OP01__
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifndef __OP01__
/* under construction !*/
	#endif
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

	//VappBrowserUtility::checkNetworkStatus();
	if(VFX_TRUE != VappBrowserUtility::checkNetworkStatus())//VappBrowserUtility::checkNetworkStatus();
	{
		return;
	}
	VappBrowserUtility::setSimSettingId();
#if 0
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#if 0
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif //0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
// TODO:check for re-enterance cases

/*#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Load(DYNAMIC_CODE_COMPRESS_BROWSER, 0, 0);
	#endif*/
    VfxAppLauncher::launch( 
        VAPP_BROWSER,
        VFX_OBJ_CLASS_INFO(VappBrowserApp),
        GRP_ID_ROOT);
}

void VappBrowserApp::onDeinit(void)
{
    closeBrowserService();
    VfxApp::onDeinit();
    m_browserAppID = GRP_ID_INVALID;
	m_isLowMemMode = VFX_FALSE;
/*#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Unload(DYNAMIC_CODE_COMPRESS_BROWSER);
#endif*/
}
void VappBrowserUtility::displayPopup(VfxU16 stringId, mmi_nmgr_balloon_type_enum balloon_type, mmi_event_notify_enum event_id)
{
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_GENERAL,
        event_id,
        balloon_type,
        (WCHAR*)(VFX_WSTR_RES(stringId).getBuf()));
}

VcpConfirmPopup* VappBrowserUtility::displayConfirmPopup(VfxObject *page, VcpPopupTypeEnum popupType, const VfxWString &msgString, const VfxWString &buttonString)
{
    MMI_ASSERT(page);
    VcpConfirmPopup *m_confirmPopup;
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, page);
    m_confirmPopup->setInfoType(popupType);
    m_confirmPopup->setText(msgString);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(buttonString, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_RECOMMEND, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->show(VFX_TRUE);
    return (m_confirmPopup);
}

VcpConfirmPopup* VappBrowserUtility::displayDeleteConfirmPopup(VfxObject *page, VcpPopupTypeEnum popupType, const VfxWString &msgString, const VfxWString &buttonString)
{
    MMI_ASSERT(page);
    VcpConfirmPopup *m_confirmPopup;
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, page);
    m_confirmPopup->setInfoType(popupType);
    m_confirmPopup->setText(msgString);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(buttonString, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->show(VFX_TRUE);
    return (m_confirmPopup);
}

void VappBrowserUtility::fileSystemErrorHandler(VfxS32 error_code)
{
    VappBrowserUtility::displayPopup(
        srv_fmgr_fs_error_get_string(error_code),
        MMI_NMGR_BALLOON_TYPE_FAILURE,
		MMI_EVENT_INFO_BALLOON);
}

VfxU16 VappBrowserUtility::getErrorString(VfxS32 error_code)
{
    switch(error_code)
    {
        case SRV_BRW_BKM_ERROR_NOT_ENOUGH_MEMORY:
        {
            return STR_GLOBAL_NOT_ENOUGH_MEMORY;
        }
        case SRV_BRW_BKM_ERROR_EMPTY_FILE_NAME:
        {
            return STR_ID_VAPP_BRW_PLEASE_INPUT_BOOKMARK_NAME;
        }
        case SRV_BRW_BKM_ERROR_INVALID_TITLE:
        {
            return STR_ID_VAPP_BRW_INVALID_TITLE;
        }
        case SRV_BRW_BKM_ERROR_INVALID_URL:
        {
            return STR_GLOBAL_INVALID_URL;
        }
        case SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS:
        {
            return STR_GLOBAL_FILE_ALREADY_EXISTS;
        }
        case SRV_BRW_BKM_ERROR_EMPTY_FOLDER_NAME:
        {
            return STR_ID_VAPP_BRW_PLEASE_INPUT_FOLDER_NAME;
        }
        default:
        {
            return srv_fmgr_fs_error_get_string(error_code);
        }

    }
}


VfxBool VappBrowserUtility::checkAvailableBookmarkMemory(void)
{
    if (g_srv_brw_cntx.bookmark_count == SRV_BRW_BKM_MAX_COUNT)
    {
        VappBrowserUtility::displayPopup(
            STR_GLOBAL_NOT_ENOUGH_MEMORY,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
			MMI_EVENT_INFO_BALLOON);
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


void VappBrowserUtility::wpsErrorHandler(U16 error_code)
{
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_WPS_ERROR_HNDLR, error_code);

    switch (error_code)
    {
        case WPS_ERROR_INVALID_PARAM:   /* 3 */
        {
			VappBrowserUtility::displayPopup(
				STR_ID_VAPP_BRW_INVALID_PARAM,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WPS_ERROR_INVALID_CHANNEL_ID:  /* 5 */
        {
			VappBrowserUtility::displayPopup(
				STR_ID_VAPP_BRW_INVAL_CHANNEL_ID,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);        
            break;
        }
        case WPS_ERROR_INVALID_REQUEST_ID:  /* 6 */
        {
			VappBrowserUtility::displayPopup(
				STR_ID_VAPP_BRW_INVAL_REQUEST_ID,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WPS_ERROR_INVALID_SEQUENCE_NUM:    /* 7 */
        {
			VappBrowserUtility::displayPopup(
				STR_ID_VAPP_BRW_INVAL_SEQUENCE_NUM,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);           
            break;
        }
        case WPS_ERROR_ACCESS_DENY: /* 12 */
        {
			VappBrowserUtility::displayPopup(
				STR_ID_VAPP_BRW_ACCESS_DENIED,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);   
            break;
        }
        case WPS_ERROR_REQ_ABORT:   /* 15 */
        {
			VappBrowserUtility::displayPopup(
				STR_ID_VAPP_BRW_REQUEST_ABORTED,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WPS_ERROR_NOT_FOUND:   /* 16 */
        {
			VappBrowserUtility::displayPopup(
				STR_ID_VAPP_BRW_NOT_FOUND,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);       
            break;
        }
        default:
        {
           VappBrowserUtility::displayPopup(
				STR_GLOBAL_ERROR,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    }
}

void VappBrowserUtility::bamErrorHandler(U16 error_code)
{
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BAM_ERROR_HNDLR, error_code);
    if (!(g_srv_brw_cntx.brw_instance_id > 0 && !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending))
    {
        return;
    }

    switch (error_code)
    {
        case WAP_BAM_ERROR_INVALID_INPUT:   /* 14 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_INVALID_PARAM,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_INVALID_URL: /* 15 */
        {
            VappBrowserUtility::displayPopup(
                STR_GLOBAL_INVALID_URL,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_INVALID_SCHEME:  /* 16 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_UNSUPPORTED_SCHEME,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_UNKNOWN_CHARSET: /* 21 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_UNSUPPORTED_ENCODING,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_SYNTAX:  /* 22 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_SYNTAX_ERROR,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_UNKNOWN_DOCTYPE: /* 23 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_UNKNOWN_DOC_TYPE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_UNSUPPORTED_WBXML:   /* 24 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_UNSUPPORTED_WBXML,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_VALIDATION:  /* 25 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_DOC_VALIDATION_ERROR,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_ABORTED: /* 26 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_PARSER_NOT_INITIALIZED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WML: /* 40 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERR_WML_ACCESS_VIOLATION,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WMLS:    /* 41 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERR_WML_SCRIPT_ACCESS_VIOLATION,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_COMMUNICATION:   /* 50 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_COMMUNICATION,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_HOST_NOT_FOUND:  /* 51 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_HOST_NOT_FOUND,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_REQUEST_TIMED_OUT:   /* 52 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_REQUEST_TIMEOUT,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_CONNECTION_FAILED:   /* 53 */
        case WAP_BAM_ERROR_CSD_REACTIVATE:  /* 115 */
		case WAP_BAM_ERROR_CSD_PPP_NEGOTIATED_FAILED:  /* 116 */
		case WAP_BAM_ERROR_CSD_ACT_FAILED:  /* 117 */
		case WAP_BAM_ERROR_CSD_CALL_SETUP_FAILED:  /* 118 */
		case WAP_BAM_ERROR_ABM_REJECTED:    /* 119 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_CONNECTION_FAILED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_SECURE_CONNECTION_FAILED:    /* 54 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_SECURE_CONNECTION_FAILED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_AUTHENTICATION:  /* 55 */ /* Only Q05A */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_AUTHENTICATION,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_SECURE_CONNECTION_CANCELLED: /* 56 */ /* Only Q05A */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_SECURE_CONNECTION_CANCELLED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #endif /*#ifdef OBIGO_Q05A */
    #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
        case WAP_BAM_ERROR_FILE_SIZE_TOO_LARGE: /* 59 */ /* Only Q05A */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_FILE_SIZE_TOO_LARGE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #endif /*#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
        case WAP_BAM_ERROR_INTERNAL:    /* 70 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_INTERNAL_ERROR,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_RESEND_POST_WARNING: /* 71 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_RESEND_POST_WARNING,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_LOW_MEMORY:  /* 72 */ /* Only Q05A */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_LOW_MEMORY,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #endif /* OBIGO_Q05A */
        case WAP_BAM_ERROR_CONTENT_TOO_LARGE:   /* 73 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_CONTENT_TOO_LARGE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_OUT_OF_MEMORY:   /* 75 */
        {
            VappBrowserUtility::displayPopup(
                STR_GLOBAL_INSUFFICIENT_MEMORY,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_LONG_IDLE_TIMEOUT:   /* 76 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_LONG_IDLE_TIMEOUT,
                MMI_NMGR_BALLOON_TYPE_INFO,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_EXISTS:  /* 81 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_PAGE_ALREADY_EXISTS,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_FAILED:  /* 82 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_REQUEST_FAILED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_PARTIAL: /* 83 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_PAGE_SAVED_PARTIALLY,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_SAVED_PAGES_LIMIT_EXCEEDED:  /* 84 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_PAGE_LIMIT_EXCEEDED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_PAGE_NOT_FOUND: /* 57 */ /* Only Q05A */
        case WAP_BAM_ERROR_RECENT_PAGES_NOT_FOUND:   /* 80 */ /* Only Q05A */
    #endif /* OBIGO_Q05A */
        case WAP_BAM_ERROR_SAVED_PAGES_NOT_FOUND:  /* 90 */ /* Only Q05A */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_PAGE_NOT_FOUND,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_RECENT_PAGES_FAILED: /* 91 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_REQUEST_FAILED,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);              
            break;
        }
    #ifdef OBIGO_Q05A
        case WAP_BAM_ERROR_EXCEED_MAX_NUM_OF_INLINE_VDO:    /* 101 */ /* Only Q05A */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_VIDEO_OBJS_EXCEED_MAX_LIMIT,
                MMI_NMGR_BALLOON_TYPE_INFO,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_CANNOT_PLAY_INLINE_VDO_IN_CALL:  /* 102 */ /* Only Q05A */
        {
            VappBrowserUtility::displayPopup(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #endif /* OBIGO_Q05A */
        case WAP_BAM_ERROR_GPRS_UNKNOWN_APN:    /* 110 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_GPRS_UNKNOWN_APN,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_GPRS_AUTHENTICATION_FAILURE: /* 111 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_GPRS_AUTHENTICATION_FAILURE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_GPRS_UNSUPPORTED:    /* 112 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_GPRS_UNSUPPORTED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_GPRS_NOT_SUBSCRIBED: /* 113 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_GPRS_NOT_SUBSCRIBED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_CSD_AUTHENTICATION_FAILURE:  /* 114 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_ERROR_CSD_AUTHENTICATION_FAILURE,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
    #ifdef OBIGO_Q03C_BROWSER
        case WAP_BAM_ERROR_UNSUPPORTED_SCRIPT_WARNING:  /* 114 */
        {
        #ifdef __GOOGLE_SEARCH_SUPPORT__
            if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_scripts_warning_disabled)
        #endif
            {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_UNSUPPORTED_SCRIPTS,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            #ifdef __GOOGLE_SEARCH_SUPPORT__
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_scripts_warning_disabled = MMI_TRUE;
            #endif
            }
            break;
        }
        case WAP_BAM_ERROR_REQUIRE_FRAMES:  /* 27 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_REQUIRES_FRAME_SUPPORT,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
        case WAP_BAM_ERROR_NO_DISPLAY_CONTENT:  /* 134 */
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_NO_DISPLAY_CONTENT,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }

    #endif /* OBIGO_Q03C_BROWSER */
        default:
        {
            VappBrowserUtility::displayPopup(
                STR_GLOBAL_ERROR,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
				MMI_EVENT_INFO_BALLOON);
            break;
        }
	}
}

VfxU8 VappBrowserUtility::getBookmarkItems(VfxU8* sel_folder_name, srv_brw_bkm_bookmark_list_struct* bkm_list)
{
    U8 array_index = 0, index = 0, temp_array_count = 0;
	#if 0
/* under construction !*/
	#endif
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    MMI_ASSERT(bkm_cntx_ptr);
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    VfxU8 parent_folder_index = srv_brw_bkm_get_parent_folder_index(sel_folder_name);
#endif

    for(index = 0; index < SRV_BRW_BKM_MAX_COUNT; index++)
    {
        if(bkm_cntx_ptr[index].type != SRV_BRW_BKM_TYPE_EMPTY)
        {
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            if(bkm_cntx_ptr[index].parent_index == parent_folder_index)
        #endif
            {
                bkm_list[array_index].actual_index = index;
                array_index++;
                temp_array_count++;
            }
        }
    }
    return temp_array_count;
}

VfxS32 VappBrowserUtility::deleteBookmarkFolder(VfxU8 selFolderIndex)
{
    MMI_ASSERT(selFolderIndex <= SRV_BRW_BKM_MAX_COUNT);
    MMI_ASSERT(g_srv_brw_cntx.bkm_cntx_p[selFolderIndex].type != SRV_BRW_BKM_TYPE_EMPTY);
    VfxS32 result = SRV_BRW_BKM_ERROR_OK;
    srv_brw_bkm_bookmark_list_struct bkmList[SRV_BRW_BKM_MAX_COUNT] = {0};
    VfxU8 listCount = VappBrowserUtility::getBookmarkItems(g_srv_brw_cntx.bkm_cntx_p[selFolderIndex].title, bkmList);
    for(;listCount > 0; listCount--)
    {
        result = srv_brw_bkm_delete_bookmark(bkmList[listCount - 1].actual_index);
        if(result < 0)
        {
            break;
        }
    }
    if(result == 0)
    {
        result = srv_brw_bkm_delete_bookmark(selFolderIndex);
    }
    return result;
}

kal_int8 VappBrowserUtility::openBearer(void)
{
    kal_int8 ret = CBM_OK;
    srv_wap_prof_profile_content_struct *profile_content_p;
    srv_brw_get_profile_content((void **)&profile_content_p);
    srv_cbm_register_bearer_info(
            (U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id)),
            SRV_CBM_ACTIVATING | SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED,
            SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_WIFI,
            VappBrwServiceInterface::vappBrwWifiBearerStatusHandler,
            NULL);
    ret = cbm_open_bearer(profile_content_p->data_account_primary_id);
    OslMfree(profile_content_p);
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 0, 0, 0, ret);
    if(ret == CBM_WOULDBLOCK)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_activating_wifi = MMI_TRUE;
        srv_brw_set_bearer(MMI_TRUE);
    }
    else if (ret != CBM_OK)
    {
        VappBrowserUtility::displayPopup(
            STR_ID_VAPP_BRW_CONNECTION_FAILED,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
			MMI_EVENT_INFO_BALLOON);
    }
    return ret;
}

VfxBool VappBrowserUtility::setSimSettingId()
{
	#if (MMI_MAX_SIM_NUM >= 2)
    srv_dtcnt_sim_type_enum sim_id;
    srv_dtcnt_get_sim_preference(&sim_id);
    g_srv_brw_cntx.session_sim_id = srv_brw_convert_dtcnt_sim_id_to_sim_setting(sim_id);
    #else
    #if 0
    #ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif //0
	    {
	        g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
	    }
    #endif
	return VFX_TRUE;
}
VfxBool VappBrowserUtility::checkSrvNwUsabIsAnyNetworkAvailable()
{
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

    /* On WLAN project, if WLAN is not GSM only, network is always available. */
	#ifdef __MMI_WLAN_FEATURES__
		if (srv_netset_get_pref_mode() != SRV_NETSET_PREF_MODE_GSM_ONLY)
		{
			return VFX_TRUE;
		}
	#endif /* __MMI_WLAN_FEATURES__ */

		/* Then, check the SIM service usablility */
	#if (MMI_MAX_SIM_NUM >= 2)
		if (srv_nw_usab_get_one_usable_sim() != MMI_SIM_NONE)
		{
			return VFX_TRUE;
		}
	#else
		if (srv_sim_ctrl_is_available(MMI_SIM1))
		{
			return VFX_TRUE;
		}
	#endif

    return VFX_FALSE;
}

VfxBool VappBrowserUtility::checkNetworkStatus()
{
	/* check if we are currently in flight mode or not */
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    	#ifndef __OP01__
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifndef __OP01__
/* under construction !*/
	#endif
/* under construction !*/
	#endif

	/* check if there is MT background call */

	if(srv_ucm_is_any_call())
	{
		VappBrowserUtility::displayPopup(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
			MMI_EVENT_INFO_BALLOON);
		//g_brw_app_cntx.brw_launching_pad = BRW_LPD_NONE;
		//return brw_grp_id;
		return VFX_FALSE;
	}
	
    /* check if any network is available or not */
    //if (!srv_nw_usab_is_any_network_available())
    if(!checkSrvNwUsabIsAnyNetworkAvailable())
    {
    	//__OP01__ is for CMCC compile option
		//WiFi still can't be turned on in flight mode in CMCC project
		
    	#ifndef __OP01__
		if(srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_INACTIVE)
		{
	#endif
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
		vcp_global_popup_show_confirm_one_button_id(
				GRP_ID_ROOT,
                VCP_POPUP_TYPE_WARNING,
                #ifdef __MMI_WLAN_FEATURES__
                STR_ID_VAPP_BRW_NETWORK_NOT_AVAILABLE,
                #else
				STR_ID_VAPP_BRW_NETWORK_NOT_AVAILABLE_NO_WIFI,
				#endif
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                NULL,
                NULL
				);
		srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_WARNING), NULL);
        return VFX_FALSE;
        #ifndef __OP01__
		}
	#endif
    }

    /* Check if Browser WAP service is ready or not */
    if (!srv_brw_is_wap_ready() || !wap_is_ready())
    {
        VappBrowserUtility::displayPopup(
            STR_ID_VAPP_BRW_WAP_NOT_READY,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
			MMI_EVENT_INFO_BALLOON);
        return VFX_FALSE;;
    }
	return VFX_TRUE;
}

//#pragma arm section code = "DYNAMIC_CODE_BROWSER_ROCODE", rodata = "DYNAMIC_CODE_BROWSER_RODATA"

void VappBrwRenderPagecp::onInit()
{
    VfxControl::onInit(); // call base class

	setBgColor(0);
    registerKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW);
	registerKeyHandler(VFX_KEY_CODE_CSK);

	}
		
void VappBrwRenderPagecp::onDeinit()
	{
   unregisterKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW);
   unregisterKeyHandler(VFX_KEY_CODE_CSK);
   VfxControl::onDeinit(); // call base class

}

VfxBool VappBrwRenderPagecp::onKeyInput(VfxKeyEvent &event)
{
    widget_MMI_key_handler();
    return VFX_TRUE;
    }

void* VappBrowserASMMemoryMgmt::allocMemory(U32 size)
    {
    void *memPtr;
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    VFX_ALLOC_MEM(memPtr, size, m_brwApp->scr);
    return (memPtr);
		}
		
void VappBrowserASMMemoryMgmt::freeMemory(void* memPtr)
		{
    VFX_FREE_MEM(memPtr);
    }

/* Kamal END */



VFX_IMPLEMENT_CLASS("VappBrowserApp", VappBrowserApp, VfxApp);

void VappBrowserApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    m_browserAppID = getGroupId();

    // create and display main screen
    VFX_OBJ_CREATE(scr, VappBrowserScreen, this);
    scr->show();
}

VfxBool VappBrowserApp::closeBrowserService(void)
{
    if(g_srv_brw_cntx.brw_instance_id > 0 && !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
    {
    	kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 21);
        srv_brw_global_shortcuts_list_update_data();

        if (srv_brw_is_holding_bearer())
        {
            srv_brw_set_bearer(MMI_FALSE);
        }
        g_srv_brw_cntx.srv_brw_profile_type = SRV_BRW_PROFILE_TYPE_NONE;
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_DEINIT_FOR_ACTIVE_BROWSER);
        srv_brw_recent_pages_list_end_req();
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        srv_brw_stored_pages_list_end_req();
    #endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
		#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        srv_brw_background_downloads_req(MMI_DA_WAP_NOTIFY_BROWSER_CLOSED);
		#endif
    #ifdef __SAT__
        srv_brw_sat_send_termination_ind(SRV_BRW_SAT_USER_TERMINATION);
    #endif 
        srv_cbm_deregister_bearer_info((U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id)));
        srv_cbm_deregister_bearer_event((U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id)));
        srv_brw_act_req_struct obj = {0};
        obj.user_data = scr->page->m_relaunchNeeded;
        obj.rsp_callback =  &VappBrwServiceInterface::deleteInstanceHdlr;
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_deleteInstanceCallback.connect(this , &VappBrowserApp::deleteInstanceCallback);
        srv_brw_delete_instance_req(&obj);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending = MMI_TRUE;
		return VFX_TRUE;
    }
	else if(g_srv_brw_cntx.brw_instance_id > 0 && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending)
	{
		kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 22);
		return VFX_TRUE;
	}
	else
	{
		kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 23);
		return VFX_FALSE;
    }
}

void VappBrowserApp::deleteInstanceCallback(VfxU8 isBrowserClosed)
{
    if(isBrowserClosed)
    {
        if(isInternallyClosed)
        {
            VfxAppLauncher::terminate(m_browserAppID);
        }
        else
        {
        	kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 5);
            VfxApp::continueClose(VFX_APP_CLOSE_ANSWER_YES);
        }
    }
    else
    {
    	kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 3);
        scr->page->updateLayerHandle(GDI_NULL_HANDLE);
        widget_paintbox_free_doubble_buffer();
        srv_brw_free_browser_memory((void**)&layer_buf_ptr);
    }
}

void VappBrowserApp::internalTerminateCallback(void)
{
    isInternallyClosed = VFX_TRUE;
    VcpIndicatorPopup *popup;
    VFX_OBJ_CREATE(popup,VcpIndicatorPopup,scr);
    popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
    popup->setAutoDestory(VFX_FALSE);
    popup->show(VFX_TRUE);
    closeBrowserService();
}



VfxAppCloseAnswerEnum VappBrowserApp::onProcessClose(VfxAppCloseOption options)
{
	kal_prompt_trace(MOD_MMI,"start VappBrowserApp::onProcessClose %d", 1);
	isProcessingClosed = VFX_TRUE;
	if(scr->page->m_clickOk == VFX_TRUE) // if it has closed browser from back key
	{
		return VFX_APP_CLOSE_ANSWER_NO;
	}
    if(!closeBrowserService())
    {
    	kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 999);
		return VFX_APP_CLOSE_ANSWER_YES;
	}
	else
	{
		kal_prompt_trace(MOD_MMI,"VappBrowserApp::onProcessClose %d", 2);
    return VFX_APP_CLOSE_ANSWER_LATER;
}
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

void VappBrowserScreen::processEnter(VfxBool isBackward)
{
	m_isScreenFirstEnter = VFX_FALSE;
	VfxMainScr::processEnter(isBackward);
}

void VappBrowserScreen::onExited(VfxBool isBackward)
{
	m_exitScreen = VFX_TRUE;
}

void VappBrowserScreen::onEntered(VfxBool isBackward)
{
    if(isBackward)
    {
    	
        if(!page->m_wapListMenu && !page->m_editorInput && page->m_renderPageCP 
		#ifndef __MMI_BRW_SLIM__
			&& !page->m_homePage
		#else
			&& !page->m_homePageList
		#endif
			)
        {
            page->resumeBrowserRendering();
            //bam_resume_browser_rendering();
        }
	#ifdef __MMI_BRW_SLIM__
		if(page->m_homePageList)
		{
			page->setHomePageListTotalNumber();
			page->m_homePageList->resetAllItems(VFX_TRUE);
		}
	#endif
    }
}

//VFX_IMPLEMENT_CLASS("VappBrowserScreen", VappBrowserScreen, VfxMainScr);

void VappBrowserScreen::on1stReady()
{
    VfxMainScr::on1stReady();
    VFX_OBJ_CREATE(page, VappBrowserPage, this);
    pushPage(BRW_PAGE_RENDERED_PAGE, page);
	VfxKeypad::registerHandler(VFX_KEY_CODE_SPECIAL_ALL, this);
}

void VappBrowserScreen::on2ndReady()
{
    //VfxKeypad::registerHandler(VFX_KEY_CODE_SPECIAL_ALL, this);
    if(m_isLowMemMode == VFX_TRUE)
    {
    	g_srv_brw_memory_pool = mmi_frm_asm_alloc_nc_r(VAPP_BROWSER_LOW_MEM, BROWSER_POOL_SIZE);
    }else
    {
    g_srv_brw_memory_pool = mmi_frm_asm_alloc_nc_r(VAPP_BROWSER, BROWSER_POOL_SIZE);
	}
    MMI_ASSERT(g_srv_brw_memory_pool);


#if (defined(__SAT__) && defined(__MMI_WLAN_FEATURES__))
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 16, 0, 0, g_srv_brw_cntx.app_type);
    if(g_srv_brw_cntx.app_type == SRV_BRW_APPTYPE_NO_WIFI)
    {
        VfxU8 value = mmi_wap_prof_register_cbm_app_id(MMI_TRUE, 
            srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id),
            SRV_WAP_PROF_APPID_BRW);
        VappBrowserUtility::displayPopup(
            STR_ID_VAPP_BRW_SIM_IN_USE,
            MMI_NMGR_BALLOON_TYPE_INFO,
		    MMI_EVENT_INFO_BALLOON);
        m_isProfileUpdateNeeded = VFX_TRUE;
        g_srv_brw_cntx.app_type = SRV_BRW_APPTYPE_WIFI;
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 14, 0, 0, value);
    }
    else
    {
        if(g_srv_brw_cntx.app_type == SRV_BRW_APPTYPE_WIFI)
        {
            VfxU8 value = mmi_wap_prof_register_cbm_app_id(MMI_FALSE, 
                srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id),
                SRV_WAP_PROF_APPID_BRW);
            g_srv_brw_cntx.app_type = SRV_BRW_APPTYPE_NONE;
            m_isProfileUpdateNeeded = VFX_TRUE;
            MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 15, 0, 0, value);
        }
    }
#endif
    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->show(VFX_TRUE);
    createServiceInstance();
}

void VappBrowserScreen::createServiceInstance(void)
{
    srv_brw_act_req_struct obj = {0};
    srv_brw_screen_info_struct screen_info = {0};

#ifdef __MMI_FTE_SUPPORT__
   screen_info.h = screen_info.h - MMI_ICON_BAR_HEIGHT;
#endif
   screen_info.x = 0;
   screen_info.y = 0;
   screen_info.w = LCD_WIDTH;
   screen_info.h = LCD_HEIGHT;

    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_createInstanceCallback.connect(this , &VappBrowserScreen::createServiceInstanceCallback);
    obj.rsp_callback = &VappBrwServiceInterface::createInstanceHdlr;
    obj.req_data = (void*)&screen_info;
    srv_brw_create_instance_req(&obj, NULL);
}

void VappBrowserScreen::createServiceInstanceCallback(S32 userData, U32 result, void *data)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_createInstanceCallback.disconnect(this , &VappBrowserScreen::createServiceInstanceCallback);
    srv_brw_read_shortcuts_data();
    srv_brw_update_shortcut_points();
	#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    srv_brw_read_address_list_data();
	#endif
    srv_brw_read_search_item_list_data();
    srv_brw_bkm_initialize_bookmark_context();
    if(m_isProfileUpdateNeeded)
    {
        srv_wap_prof_profile_content_struct *profile_content_p;
        srv_brw_act_req_struct obj = {0};
        srv_brw_set_profile_req_struct prof;
        srv_brw_get_profile_content((void **)&profile_content_p);
        obj.rsp_callback = VappBrwServiceInterface::setProfileRspHandler;
        prof.currprof = profile_content_p;
        prof.setting_id = wap_bam_setting_type_profile;
        obj.req_data = (void*)&prof;
        srv_brw_set_profile_req_by_data(&obj);
        OslMfree(profile_content_p);
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.connect(this , &VappBrowserScreen::setProfileCallback);
    }
    else
    {
    page->displayPage();
}
}

void VappBrowserScreen::setProfileCallback(void)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.disconnect(this , &VappBrowserScreen::setProfileCallback);
    page->displayPage();
}

VfxBool VappBrowserScreen::onPenInput(VfxPenEvent& event)
{
    if ((!page) || (!page->m_renderPageCP))
        return VFX_TRUE;
    VfxPoint relPoint = event.getRelPos(this);
    mmi_pen_point_struct point;
    if (page->m_isFullScreenMode)
    {
        point.x = relPoint.x;
        point.y = relPoint.y;
    }
    else
    {
        point.x = relPoint.x;
        point.y = relPoint.y - (page->m_titleBar->getRect().origin.y+ page->m_titleBar->getRect().size.height);
    }
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            srv_brw_handle_pen_event_req(point, MMI_PEN_EVENT_DOWN);
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
            srv_brw_handle_pen_event_req(point, MMI_PEN_EVENT_UP);
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            srv_brw_handle_pen_event_req(point, MMI_PEN_EVENT_MOVE);
            break;
        }

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
            srv_brw_handle_pen_event_req(point, MMI_PEN_EVENT_LONG_TAP);
            break;
        }

        case VFX_PEN_EVENT_TYPE_ABORT:
        {
           srv_brw_handle_pen_event_req(point, MMI_PEN_EVENT_ABORT);
            break;
        } 

        default:
            break;
    }
    return VFX_TRUE;
}

void VappBrowserScreen::onRotate(const VfxScreenRotateParam &param)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
	VfxMainScr::onRotate(param);
#endif
}

void VappBrowserScreen::onQueryRotateEx(VfxScreenRotateParam &param)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
	VfxMainScr::onQueryRotateEx(param);
#endif
}

void VappBrowserScreen::onDeinit()
{
    VfxMainScr::onDeinit();
}

mmi_ret VappBrowserApp:: onProc(mmi_event_struct *param)
{
    VappBrowserApp::m_eventCallback.emit((void*)param);
    return MMI_RET_OK;
}


#ifdef __MMI_BRW_SLIM__
VfxBool VappBrowserHomePageDataProvider::getItemTextFrameFormat(
			VfxU32 index,
			VcpListMenuFieldEnum fieldType,
			VfxTextFrame * frame)
{
	frame->setColor(VRT_COLOR_BLACK);// change the item text color .
	return VFX_TRUE;
}

VfxBool VappBrowserHomePageDataProvider::getItemText(
			VfxU32 index,
			VcpListMenuFieldEnum fieldType,
			VfxWString & text,
			VcpListMenuTextColorEnum & color)
{
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
		if(!srv_brw_is_shortcut_index_empty(index))
	    {
	        nvram_brw_global_shortcuts_item_struct* shortcutItem = srv_brw_get_global_shortcut(index);
	        if(strlen((CHAR*)shortcutItem->title.title))
	        {
	            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
	            if(shortcutItem->title.dcs == SRV_BRW_DCS_UCS)
	            {
	                mmi_ucs2ncpy((CHAR*) textBuff, (CHAR*) shortcutItem->title.title , SRV_BRW_MAX_TITLE_LENGTH);
	            }
	            else
	            {
	                mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
	                    (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
	                    (U8*) shortcutItem->title.title);
	            }
	            text.unlockBuf();
	        }
	        else
	        {
	            VfxWChar *titleBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
	            memset(titleBuff, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
	            mmi_asc_n_to_ucs2((CHAR*)titleBuff, (CHAR*) shortcutItem->url, SRV_BRW_MAX_URL_LENGTH);
	            text.unlockBuf();
	        }
		}
	}
	return VFX_TRUE;
}

VfxBool VappBrowserHomePageDataProvider::getItemImage(
			VfxU32 index,
			VcpListMenuFieldEnum fieldType,
			VfxImageSrc & image)
{
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	if(fieldType == VCP_LIST_MENU_FIELD_ICON)
	{
		if(!srv_brw_is_shortcut_index_empty(index))
		{
			//nvram_brw_global_shortcuts_item_struct* shortcutItem = srv_brw_get_global_shortcut(index);
			if(index < BRW_DEFAULT_SHORTCUT_TOTAL)
            {
            image.setResId(IMG_ID_VAPP_BRW_SNAPSHOT_BEGIN + index + 1);
            }
            else
            {
            	image.setResId(IMG_ID_VAPP_BRW_SHORTCUTS_ICON);
            }
		}
		else
	    {
	        image.setResId(IMG_ID_VAPP_BRW_ADD_LINK);
	    }	
	}
	return VFX_TRUE;
}
#endif

//VFX_IMPLEMENT_CLASS("VappBrowserPage", VappBrowserPage, VfxPage);

void VappBrowserPage::onInit()
{
    VfxPage::onInit(); // call base class
    setBgColor(VfxColor(VFX_COLOR_WHITE));
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_transactionCallback.connect(this , &VappBrowserPage::transactionCallback);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_documentInfoCallback.connect(this , &VappBrowserPage::documentInfoCallback);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayWapEditorCallback.connect(this, &VappBrowserPage::displayWapEditor);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayWapListMenuCallback.connect(this, &VappBrowserPage::displayWapListMenu);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayAuthenticationCallback.connect(this, &VappBrowserPage::displayAuthentication);
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_secConfirmCallback.connect(this , &VappBrowserPage::secConfirmCallback);
#endif
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_errorIndCallback.connect(this , &VappBrowserPage::errorIndCallback);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayImageOptionCallback.connect(this, &VappBrowserPage::displayImageOptions);
#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_selectUploadFileCallback.connect(this, &VappBrowserPage::selectUploadFile);
#endif
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_wmslDialogCallback.connect(this, &VappBrowserPage::showWmlsDialog);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_relaunchCallback.connect(this, &VappBrowserPage::relaunchBrowserCallback);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_usbModeCallback.connect(this, &VappBrowserPage::usbModeCallback);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_TouchFeedbackCallback.connect(this, &VappBrowserPage::vappBrwSendTouchFeedbackCallback);
#ifndef __MMI_BRW_SLIM__	
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_homepageSnapshotCallback.connect(this, &VappBrowserPage::homepageSnapshotCallback);
#endif
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_openBearerCallback.connect(this, &VappBrowserPage::openBearerCallback);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_displayProgressPopupCallback.connect(this, &VappBrowserPage::displayProgressPopupCallback);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_closeProgressPopupCallback.connect(this, &VappBrowserPage::closeProgressPopupCallback);
    addPageBars();
}

void VappBrowserPage::usbModeCallback(VfxU8 isEnter)
{
    if(isEnter)
    {
        m_isMassStorageMode = VFX_TRUE;
        getMainScr()->closePage(BRW_PAGE_ADD_PAGE);
		#ifndef __MMI_BRW_SLIM__
        if(m_homePage)
        {
            m_homePage->updateItems();
        }
		#endif
    }
    else
    {
        m_isMassStorageMode = VFX_FALSE;
		#ifndef __MMI_BRW_SLIM__
        if(m_homePage)
        {
            m_homePage->updateItems();
        }
		#endif
    }
}

void VappBrowserPage::relaunchBrowserCallback(void)
{
    m_relaunchNeeded = VFX_TRUE;
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    m_brwApp->internalTerminateCallback();
}

void VappBrowserPage::onBack()
{
	setFocused(VFX_TRUE);
    if(srv_brw_is_backward_navigation())
    {
        if(!srv_brw_is_in_transaction())
        {
            srv_brw_navigate_req(WAP_BAM_MOVE_BACKWARD);
        }
    }
    else
    {
        VcpConfirmPopup *m_confirmPopup;
        VfxWString confirmString;
        confirmString.loadFromRes(STR_ID_VAPP_BRW_EXIT_BROWSER);
        confirmString += VFX_WSTR_RES(STR_ID_VAPP_BRW_QUESTION_MARK);
        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        m_confirmPopup->setText(confirmString);
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmPopup->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_EXIT), VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_RECOMMEND, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_confirmPopup->show(VFX_TRUE);
        m_confirmPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::exitBrowserHandler);
        m_confirmPopup->m_signalPopupState.connect(this, &VappBrowserPage::onExitConfrmPopupStateChanged);
    }
}

void VappBrowserPage::processRotate(const VfxScreenRotateParam &param)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    VfxPage::processRotate(param);
    
    VfxAutoAnimate::commit();
}

void VappBrowserPage::rotationTimerCallback(VfxTimer *timer)
{
    widget_paintbox_relayout();
    VFX_OBJ_CLOSE(timer);
}

void VappBrowserPage::exitBrowserHandler(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1/*VCP_CONFIRM_POPUP_BUTTON_YES*/)
    {
        m_clickOk = VFX_TRUE;
#if 0
/* under construction !*/
/* under construction !*/
#endif //0
    }
}

void VappBrowserPage::onHomePageIconTap()
{
    srv_brw_load_url_req((U8*)BRW_HOMEPAGE_URL_STR, WAP_BAM_UNKNOWN_CHARSET);
    m_titleBar->enableHomePageTap(VFX_FALSE);
}

void VappBrowserPage::removePageBars()
{
    VFX_OBJ_CLOSE(m_titleBar);
	VFX_OBJ_CLOSE(m_toolBar);
}

void VappBrowserPage::addPageBars()
{
    VFX_OBJ_CREATE(m_toolBar,VcpToolBar,this);
    m_toolBar->m_signalButtonTap.connect(this, &VappBrowserPage::onTBClick);
    setBottomBar(m_toolBar);
	m_toolBar->setBgColor(VFX_COLOR_BLACK);

    m_toolBar->addItem(BROWSER_PAGE_BACK, VFX_WSTR_RES(STR_GLOBAL_BACK),IMG_ID_VAPP_BRW_TOOLBAR_BACK);
    m_toolBar->addItem(BROWSER_PAGE_FORWARD, VFX_WSTR_RES(STR_ID_VAPP_BRW_FORWARD),VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD);
    m_toolBar->addItem(BROWSER_PAGE_FAVOTIRES, VFX_WSTR_RES(STR_ID_VAPP_BRW_FAVORITES),IMG_ID_VAPP_BRW_TOOLBAR_FAVORITES);
    m_toolBar->addItem(BROWSER_PAGE_ADD, VFX_WSTR_RES(STR_ID_VAPP_BRW_ADD),VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
	#ifndef __MMI_BRW_SLIM__
    m_toolBar->addItem(BROWSER_PAGE_SHARE, VFX_WSTR_RES(STR_GLOBAL_SHARE),VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE);
	#endif
    m_toolBar->addItem(BROWSER_PAGE_SETTINGS, VFX_WSTR_RES(STR_GLOBAL_SETTINGS),VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
    m_toolBar->addItem(BROWSER_PAGE_EXIT_BROWSER, VFX_WSTR_RES(STR_ID_VAPP_BRW_EXIT_BROWSER),VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT);
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        updateToolBarItemsState();
    }
    VfxRect page_rect = getRect();

	VFX_OBJ_CREATE(m_titleBar,VappBrwTitleBar,this);
	m_titleBar->setBgColor(VFX_COLOR_BLACK);
	setTopBar(m_titleBar); 

	VcpTextView* textViewer = m_titleBar->getTitleTextEditor();
    textViewer->setHint(VFX_WSTR_RES(STR_ID_VAPP_BRW_INPUT_ADDRESS_OR_KEYWORDS));   /* Set hint text when editor content is empty */
    textViewer->m_signalTapEvent.connect(this, &VappBrowserPage::onTextViewerActivated); 
    textViewer->setText(VFX_WSTR(""), SRV_BRW_MAX_URL_LENGTH);
    textViewer->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_titleBar->m_homePageIconTap.connect(this, &VappBrowserPage::onHomePageIconTap);
    m_titleBar->m_screenModeIconTap.connect(this, &VappBrowserPage::onFullScreenIconTap);
    m_titleBar->m_editorIconTap.connect(this, &VappBrowserPage::onTitleBarEditorIconTap);
    m_titleBar->m_editorKeyInput.connect(this, &VappBrowserPage::onTitleBarEditorKeyInput);
}

void VappBrowserPage::onTitleBarEditorIconTap()
{
    if(m_progressValue == 0)
    {
        srv_brw_reload_req();
    }
    else
    {
        srv_brw_stop_page_fetching_req();
    }
}

void VappBrowserPage::onUpdate(void)
{
	VfxPage::onUpdate();
    if(m_isHomepageMode)
    {
        m_isHomepageMode = VFX_FALSE;
		#ifndef __MMI_BRW_SLIM__
        if(!m_homePage)
        {
            VFX_OBJ_CREATE(m_homePage,VappBrwHomePage,this);
            VfxRect page_rect = getRect();
            m_homePage->setPos(0,0);
            m_homePage->setSize(page_rect.getWidth(), page_rect.getHeight());
            VfxCallback4<VfxU8 , VfxImageSrc &, VfxWString &, VfxBool &> callback(this, &VappBrowserPage::getHomepageShortcutInfo);
            m_homePage->registerCallback(callback);
            m_homePage->m_iconItemLongPress.connect(this, &VappBrowserPage::onShortcutLongTap);
            m_homePage->m_iconItemTap.connect(this, &VappBrowserPage::onShortcutItemTap);
            updateHomePageElemSize();
            m_homePage->setHomePageElementsSize(m_iconWidth,m_iconHeight,m_lockIconWidth, m_lockIconHeight, m_iconTextHeight, m_iconTitleMargin, m_HorizontalpageMargin, m_iconTextFontSize, m_VerticalpageMargin, m_HorizontalExtraMargin, m_VerticalExtraMargin, m_LockTitleTextMargin);
            m_homePage->setRowsColumns(m_NoOfRows,m_NoOfColmns);
        }
		#else
		createHomePageList();
		#endif
    }
}

#ifndef __MMI_BRW_SLIM__
void VappBrowserPage::getHomepageShortcutInfo(VfxU8 index, VfxImageSrc &shortcutImage, VfxWString &shotcutTitle, VfxBool &isLocked)
{
    if(!srv_brw_is_shortcut_index_empty(index))
    {
        nvram_brw_global_shortcuts_item_struct* shortcutItem = srv_brw_get_global_shortcut(index);
        isLocked = (VfxBool)shortcutItem->is_locked;
        if(strlen((CHAR*)shortcutItem->title.title))
        {
            VfxWChar *textBuff = shotcutTitle.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
            if(shortcutItem->title.dcs == SRV_BRW_DCS_UCS)
            {
                mmi_ucs2ncpy((CHAR*) textBuff, (CHAR*) shortcutItem->title.title , SRV_BRW_MAX_TITLE_LENGTH);
            }
            else
            {
                mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                    (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
                    (U8*) shortcutItem->title.title);
            }
            shotcutTitle.unlockBuf();
        }
        else
        {
            VfxWChar *titleBuff = shotcutTitle.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            memset(titleBuff, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((CHAR*)titleBuff, (CHAR*) shortcutItem->url, SRV_BRW_MAX_URL_LENGTH);
            shotcutTitle.unlockBuf();
        }
        if(index < BRW_DEFAULT_SHORTCUT_TOTAL)
            {
            shortcutImage.setResId(IMG_ID_VAPP_BRW_SNAPSHOT_BEGIN + index + 1);
            }
            else
            {
                if(m_isMassStorageMode)
                {
                    shortcutImage.setResId(IMG_ID_VAPP_BRW_SHORTCUTS_ICON);
                }
                else
                {
                    VfxWString imagePath;
                    imagePath.format("%c:\\%s\\homepage_snapshot%d.jpg", BRW_HOMEPAGE_SNAPSHOT_FILE_DRIVE, BRW_HOMEPAGE_SHORTCUT_FOLDER_NAME, shortcutItem->id);
                    VfxWChar *tempFile = imagePath.lockBuf(SRV_BRW_BKM_MAX_PATH_LEN);
                    FS_HANDLE fileHandle= FS_Open((const WCHAR*) tempFile, FS_READ_ONLY);
                    imagePath.unlockBuf();
                    if(fileHandle >= 0)
                    {
                        shortcutImage.setPath(imagePath);
                        FS_Close(fileHandle);
                    }
                    else
                    {
                        shortcutImage.setResId(IMG_ID_VAPP_BRW_SHORTCUTS_ICON);
                    }
                }
            }
        }
    else
    {
        shortcutImage.setResId(IMG_ID_VAPP_BRW_ADD_LINK);
    }
}


void VappBrowserPage::onShortcutItemTap(VfxU8 index)
{
    if((m_progressValue !=0))
    {
        return;
    }

    if(srv_brw_is_shortcut_index_empty((U8)index))
    {
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	    VFX_OBJ_CREATE_EX(m_brwApp->scr->m_editShortcutPage,VappBrowserEditShortcut,m_brwApp->scr, (index));
        m_brwApp->scr->pushPage(BRW_PAGE_EDIT_SHORTCUT, m_brwApp->scr->m_editShortcutPage);
		updateLayerHandle(NULL);
    }
    else
    {
            srv_brw_launch_global_shortcut(index);
        }
    }

void VappBrowserPage::onShortcutLongTap(VfxU8 index)
{
    if((m_progressValue !=0) || srv_brw_is_shortcut_index_empty((U8)index))
    {
        return;
    }
    if(index < BRW_DEFAULT_SHORTCUT_TOTAL)
    {
        return;
    }
    VcpMenuPopup *m_contextMenu;
    VFX_OBJ_CREATE(m_contextMenu, VcpMenuPopup, this);
    VfxWString title;
    nvram_brw_global_shortcuts_item_struct* shortcutItem = srv_brw_get_global_shortcut(index);
    if(strlen((CHAR*)shortcutItem->title.title))
    {
        VfxWChar *textBuff = title.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
        if(shortcutItem->title.dcs == SRV_BRW_DCS_UCS)
        {
            mmi_ucs2ncpy((CHAR*) textBuff, (CHAR*) shortcutItem->title.title , SRV_BRW_MAX_TITLE_LENGTH);
        }
        else
        {           
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) shortcutItem->title.title);            
        }
        title.unlockBuf();
    }
    else
    {
        VfxWChar *titleBuff = title.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
        memset(titleBuff, 0,(SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
        mmi_asc_n_to_ucs2((CHAR*)titleBuff, (CHAR*) shortcutItem->url, SRV_BRW_MAX_URL_LENGTH);
        title.unlockBuf();
    }
    m_contextMenu->setTitle(title);
    if(srv_brw_is_global_shortcut_locked((U8)index))
    {
		m_contextMenu->addItem(COMMAND_SHORTCUT_UNLOCK, VFX_WSTR_RES(STR_ID_VAPP_BRW_UNLOCK_SHORTCUT));
    }
    else
    {
		m_contextMenu->addItem(COMMAND_SHORTCUT_LOCK, VFX_WSTR_RES(STR_ID_VAPP_BRW_LOCK_SHORTCUT));
    }
	m_contextMenu->addItem(COMMAND_SHORTCUT_EDIT, VFX_WSTR_RES(STR_ID_VAPP_BRW_EDIT_ADDRESS));
	m_contextMenu->addItem(COMMAND_SHORTCUT_DELETE, VFX_WSTR_RES(STR_ID_VAPP_BRW_DELETE_SHORTCUT));
    m_contextMenu->m_signalMenuCallback.connect(this, &VappBrowserPage::contextMenuCallack);
    m_contextMenu->show(VFX_TRUE);
    m_selectedShortcutID = index;
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
}


void VappBrowserPage::contextMenuCallack(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item)
{
    if(event != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }
    switch(item->getId())
    {
        case COMMAND_SHORTCUT_LOCK:
        {
            srv_brw_global_shortcuts_set_item_lock(m_selectedShortcutID, MMI_TRUE);
			#ifndef __MMI_BRW_SLIM__
            m_homePage->updateItems(m_selectedShortcutID);
			#else
			
			#endif
            break;
        }

        case COMMAND_SHORTCUT_UNLOCK:
        {
            srv_brw_global_shortcuts_set_item_lock(m_selectedShortcutID, MMI_FALSE);
			#ifndef __MMI_BRW_SLIM__
            m_homePage->updateItems(m_selectedShortcutID);
			#else
			
			#endif
            break;
        }

        case COMMAND_SHORTCUT_EDIT:
        {
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
			VFX_OBJ_CREATE_EX(m_brwApp->scr->m_editShortcutPage,VappBrowserEditShortcut,m_brwApp->scr, (m_selectedShortcutID));
            m_brwApp->scr->pushPage(BRW_PAGE_EDIT_SHORTCUT, m_brwApp->scr->m_editShortcutPage);
			updateLayerHandle(NULL);
            break;
        }

        case COMMAND_SHORTCUT_DELETE:
        {
            VcpConfirmPopup *confirmPopup;
            confirmPopup = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
                VFX_WSTR_RES(STR_ID_VAPP_BRW_DELETE_SHORTCUT_CONFIRM),
                VFX_WSTR_RES(STR_GLOBAL_DELETE));
            confirmPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::shortcutDeleteHandler);
            break;
        }
    }
}

void VappBrowserPage::shortcutDeleteHandler(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        srv_brw_delete_global_shortcut(m_selectedShortcutID);
        srv_brw_reposition_global_shortcuts();
        m_homePage->updateItems();
    }
}
#endif

void VappBrowserPage::updateToolBarItemsState()
{
    if(m_toolBar)
    {
        if(!m_toolBar->isFolded())
        {
            m_toolBar->switchFoldMode();
        }
        m_toolBar->removeItem(BROWSER_PAGE_ADD);
        m_toolBar->removeItem(BROWSER_PAGE_FAVOTIRES);
		#ifndef __MMI_BRW_SLIM__
        m_toolBar->removeItem(BROWSER_PAGE_SHARE);
		#endif
        m_toolBar->removeItem(BROWSER_PAGE_SETTINGS);
        m_toolBar->removeItem(BROWSER_PAGE_EXIT_BROWSER);

        if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p && !(strcmp((CHAR*)"about:homepage",  g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url)))
        {
            m_toolBar->addItem(BROWSER_PAGE_FAVOTIRES, VFX_WSTR_RES(STR_ID_VAPP_BRW_FAVORITES),IMG_ID_VAPP_BRW_TOOLBAR_FAVORITES);
            m_toolBar->addItem(BROWSER_PAGE_SETTINGS, VFX_WSTR_RES(STR_GLOBAL_SETTINGS),VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
            m_toolBar->addItem(BROWSER_PAGE_EXIT_BROWSER, VFX_WSTR_RES(STR_ID_VAPP_BRW_EXIT_BROWSER),VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT);
        }
        else
        {
            m_toolBar->addItem(BROWSER_PAGE_ADD, VFX_WSTR_RES(STR_ID_VAPP_BRW_ADD),VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
            m_toolBar->addItem(BROWSER_PAGE_FAVOTIRES, VFX_WSTR_RES(STR_ID_VAPP_BRW_FAVORITES),IMG_ID_VAPP_BRW_TOOLBAR_FAVORITES);
			#ifndef __MMI_BRW_SLIM__
            m_toolBar->addItem(BROWSER_PAGE_SHARE, VFX_WSTR_RES(STR_GLOBAL_SHARE),VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE);
			#endif
            m_toolBar->addItem(BROWSER_PAGE_SETTINGS, VFX_WSTR_RES(STR_GLOBAL_SETTINGS),VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
            m_toolBar->addItem(BROWSER_PAGE_EXIT_BROWSER, VFX_WSTR_RES(STR_ID_VAPP_BRW_EXIT_BROWSER),VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT);
        }
        m_toolBar->setDisableItem(BROWSER_PAGE_FORWARD, (VfxBool)(!srv_brw_is_forward_navigation()));
        m_toolBar->setDisableItem(BROWSER_PAGE_BACK, (VfxBool)(!srv_brw_is_backward_navigation()));
        m_toolBar->setDisableItem(BROWSER_PAGE_ADD, (VfxBool)(!srv_brw_is_page_valid_for_add()));
		#ifndef __MMI_BRW_SLIM__
        m_toolBar->setDisableItem(BROWSER_PAGE_SHARE, (VfxBool)(!srv_brw_is_page_url_valid()));
		#endif
    }
}

void VappBrowserPage::onTitleBarEditorKeyInput(VfxKeyEvent &event)
{
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	#ifndef __MMI_BRW_SLIM__
    if(!m_homePage)
    {
        return;	
	}
	#else
	if(!m_homePageList)
	{
        return;
	}
	#endif
#ifndef __MMI_BRW_SLIM__
    VFX_OBJ_CREATE(m_brwApp->scr->m_editShortcutPage,VappBrowserEditShortcut,m_brwApp->scr);
    m_brwApp->scr->pushPage(BRW_PAGE_EDIT_SHORTCUT, m_brwApp->scr->m_editShortcutPage);
    m_brwApp->scr->m_editShortcutPage->handleKeyInput(event);
	updateLayerHandle(NULL);
#else
	createUrlInputPopup(-1, VFX_TRUE);
#endif

}

void VappBrowserPage::onTextViewerActivated(VcpTextView *viewer, VcpTextTapAreaEnum area, VcpRichTextFormat *format)
{
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    VfxWChar *textBuffer = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
	#ifndef __MMI_BRW_SLIM__
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p && !m_homePage)
    {
        mmi_asc_n_to_ucs2((CHAR*)textBuffer, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
    }
	else if(m_brwApp->scr->page->m_titleTextBuffer && !m_homePage)
	{
		mmi_wcscpy(textBuffer, m_brwApp->scr->page->m_titleTextBuffer);
	}
    else
	#else
	if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p && !m_homePageList)
    {
        mmi_asc_n_to_ucs2((CHAR*)textBuffer, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
    }
	else if(m_brwApp->scr->page->m_titleTextBuffer && !m_homePageList)
	{
		mmi_wcscpy(textBuffer, m_brwApp->scr->page->m_titleTextBuffer);
	}
    else
	#endif
    {
        memset(textBuffer, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
    }
#ifndef __MMI_BRW_SLIM__
    VFX_OBJ_CREATE_EX(m_brwApp->scr->m_editShortcutPage,VappBrowserEditShortcut,m_brwApp->scr, (textBuffer));
    VappBrowserASMMemoryMgmt::freeMemory(textBuffer);
    m_brwApp->scr->pushPage(BRW_PAGE_EDIT_SHORTCUT, m_brwApp->scr->m_editShortcutPage);	
	updateLayerHandle(NULL);
#else
	createUrlInputPopup(-1, VFX_FALSE);
	VappBrowserASMMemoryMgmt::freeMemory(textBuffer);
#endif
	
	
}

void VappBrowserPage::suspendBrowserRendering(void)
{
    bam_suspend_browser_rendering();
}

void VappBrowserPage::resumeBrowserRendering(void)
{
    updateLayerHandle(paintbox_layer_handle);
    bam_resume_browser_rendering();
}

void VappBrowserPage::notifyScreenInfo(VfxU8 x, VfxU8 y, VfxU16 w, VfxU16 h, VfxS32 handle1, VfxS8 handle2, VfxS8 isRefresh)
{
    bam_notify_screen_info(0,0,w,h, NULL, NULL, TRUE);
    widget_set_coordinates_screen(x, y, w, h);
}
#ifndef __MMI_BRW_SLIM__ 	
void VappBrowserPage::updateHomePageElemSize(void)
{
    if(getRotate() == VFX_SCR_ROTATE_TYPE_0)
    {
        m_iconWidth = HOME_PAGE_ICON_WIDTH;
        m_iconHeight = HOME_PAGE_ICON_HEIGHT;
        m_lockIconWidth = HOME_PAGE_ICON_LOCK_WIDTH;
        m_lockIconHeight = HOME_PAGE_ICON_LOCK_HEIGHT;
        m_iconTextHeight = HOME_PAGE_ICON_TEXT_HEIGHT;
        m_iconTitleMargin = HOME_PAGE_ICON_TITLE_MARGIN;
		m_HorizontalpageMargin = HOME_PAGE_HORIZONTAL_MARGIN;
        m_VerticalpageMargin = HOME_PAGE_VERTICAL_MARGIN;
		m_HorizontalExtraMargin = HOME_PAGE_HORIZONTAL_EXTRA_MARGIN;
		m_VerticalExtraMargin = HOME_PAGE_VERTICAL_EXTRA_MARGIN;
		m_iconTextFontSize = HOME_PAGE_ICON_TEXT_FONT_SIZE;
        m_LockTitleTextMargin = HOME_PAGE_LOCK_TITLE_TEXT_MARGIN;
#if defined(__MMI_MAINLCD_240X320__)
	m_NoOfColmns = 3;
	m_NoOfRows = 2;
#else
	m_NoOfColmns = 3;
	m_NoOfRows = 3;
#endif /* __MMI_MAINLCD_320X240__ */
    }
    else if(getRotate() == VFX_SCR_ROTATE_TYPE_270 || getRotate() == VFX_SCR_ROTATE_TYPE_90)
    {
        m_iconWidth = ROTATED_HOME_PAGE_ICON_WIDTH;
        m_iconHeight = ROTATED_HOME_PAGE_ICON_HEIGHT;
        m_lockIconWidth = ROTATED_HOME_PAGE_ICON_LOCK_WIDTH;
        m_lockIconHeight = ROTATED_HOME_PAGE_ICON_LOCK_HEIGHT;
        m_iconTextHeight = ROTATED_HOME_PAGE_ICON_TEXT_HEIGHT;
        m_iconTitleMargin = ROTATED_HOME_PAGE_ICON_TITLE_MARGIN;
        m_HorizontalpageMargin = ROTATED_HOME_PAGE_HORIZONTAL_MARGIN;
        m_VerticalpageMargin = ROTATED_HOME_PAGE_VERTICAL_MARGIN;
		m_iconTextFontSize = ROTATED_HOME_PAGE_ICON_TEXT_FONT_SIZE;
		m_HorizontalExtraMargin = ROTATED_HOME_PAGE_HORIZONTAL_EXTRA_MARGIN;
		m_VerticalExtraMargin = ROTATED_HOME_PAGE_VERTICAL_EXTRA_MARGIN;
        m_LockTitleTextMargin = ROTATED_HOME_PAGE_LOCK_TITLE_TEXT_MARGIN;
#if defined(__MMI_MAINLCD_240X320__)
	m_NoOfColmns = 4;
	m_NoOfRows = 2;
#else
	m_NoOfColmns = 5;
	m_NoOfRows = 2;
#endif /* __MMI_MAINLCD_320X240__ */
    }
}
#endif

void VappBrowserPage::onEnter(VfxBool isBackward)
{
	#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_QWERTY);
	#endif
    if(isBackward)
    {
    	
        if(!m_wapListMenu && !m_editorInput && m_renderPageCP 
			#ifndef __MMI_BRW_SLIM__
			&& !m_homePage
			#else
			&& !m_homePageList
			#endif
			)
        {
        	if(m_exitScreen != VFX_TRUE)
        	{
            resumeBrowserRendering();
        }
        }
		#ifdef __MMI_BRW_SLIM__
		if(m_homePageList)
		{
			setHomePageListTotalNumber();
			m_homePageList->resetAllItems(VFX_TRUE);
		}
		#endif
    }
}

void VappBrowserPage::onEntered()
{
	if(m_exitScreen == VFX_TRUE)
	{
		m_exitScreen = VFX_FALSE;
	}
}
#ifdef __MMI_BRW_SLIM__

void VappBrowserPage::createHomePageList(void)
{
	if(!m_homePageList)
	{
		VFX_OBJ_CREATE(m_homePageList,VcpListMenu,this);
		VFX_OBJ_CREATE(m_homePageDataProvider,VappBrowserHomePageDataProvider,this);
		setHomePageListTotalNumber();
		VfxRect page_rect = getRect();
		m_homePageList->setPos(0,0);
		m_homePageList->setSize(page_rect.getWidth(), page_rect.getHeight());
		m_homePageList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
		m_homePageList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
		m_homePageList->setContentProvider(m_homePageDataProvider);
		m_homePageList->setBgColor(VRT_COLOR_WHITE);

		m_homePageList->m_signalItemTapped.connect(this, &VappBrowserPage::onShortCutListItemTap);
		m_homePageList->m_signalItemLongTapped.connect(this, &VappBrowserPage::onShortCutListItemLongTapped);

		
	}
}

void VappBrowserPage::setHomePageListTotalNumber(void)
{
	U8 m_totalNumber = srv_brw_global_shortcuts_list_get_number_of_items ();
	if(m_totalNumber < 9)
	{
		m_homePageDataProvider->totalShortcut = m_totalNumber + 1;
	}
	else
	{
		m_homePageDataProvider->totalShortcut = 9;
	}
}
void VappBrowserPage::onShortCutListItemTap(VcpListMenu * sender,VfxU32 index)
{
	
    if((m_progressValue !=0))
    {
        return;
    }
    if(srv_brw_is_shortcut_index_empty((U8)index))
    {
		createUrlInputPopup(index, VFX_TRUE);
		updateLayerHandle(NULL);
    }
    else
    {
        srv_brw_launch_global_shortcut(index);
    }

}

void VappBrowserPage::createUrlInputPopup(VfxS32 index, VfxBool isShortCut)
{
        m_urlBuffer = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
        memset(m_urlBuffer, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
	if(isShortCut && index >= 0)
    {
        nvram_brw_global_shortcuts_item_struct* shortcutItem = srv_brw_get_global_shortcut(index);
        mmi_asc_to_ucs2((CHAR*) m_urlBuffer, (CHAR*) shortcutItem->url);
    }
	
	if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p && !m_homePageList)
    {
       	mmi_asc_n_to_ucs2((CHAR*)m_urlBuffer, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
    }
	
	if(isShortCut && 0 == mmi_ucs2strlen((CHAR*)m_urlBuffer))
	{
		mmi_asc_to_ucs2((CHAR*) m_urlBuffer, (CHAR*) BRW_DEFAULT_ENTER_ADDR_STR);
	}
	
	VFX_OBJ_CREATE(m_inputPopup, VappUrlInputPopup, this);
	m_inputPopup->setIndex(index);
	m_inputPopup->setIsShortCut(isShortCut);
	m_inputPopup->setTitle(VFX_WSTR_RES(STR_GLOBAL_EDIT));
	m_inputPopup->setText(m_urlBuffer, SRV_BRW_MAX_URL_LENGTH);          /* set text without any text format*/
	if(!isShortCut)
	{
		m_inputPopup->setIME(IMM_INPUT_TYPE_SENTENCE);
	}
	else
	{
	        m_inputPopup->setIME(IMM_INPUT_TYPE_URL, IME_DISABLE_NEW_LINE_SYMBOL);
	}	
	m_inputPopup->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_TAP_TO_INPUT));   /* Set hint text when editor content is empty */
	m_inputPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::onInputPopupBtnClicked);
	m_inputPopup->show(VFX_TRUE);
		
	VappBrowserASMMemoryMgmt::freeMemory(m_urlBuffer);
    m_urlBuffer = NULL;
	
}
 
void VappBrowserPage::onInputPopupBtnClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
	switch(id)
	{
		case VCP_INPUT_POPUP_BTN_OK:
		{
			VfxU32 index = m_inputPopup->getIndex();
			VcpTextEditor *editor = m_inputPopup->getInputbox();
			VfxWChar *inputString = editor->getText();
			VfxBool isShortCut = m_inputPopup->getIsShortCut();
			if(isShortCut)
			{
				if (srv_brw_validate_url((U8*)inputString, SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1) < 0)
            	{
		        VappBrowserUtility::displayPopup(
			        STR_GLOBAL_INVALID_URL,
			        MMI_NMGR_BALLOON_TYPE_FAILURE,
				    MMI_EVENT_INFO_BALLOON);
	            }
	            else
	            {
	                nvram_brw_global_shortcuts_item_struct *newItem;
	                nvram_brw_global_shortcuts_item_struct *oldItem;
	                newItem = (nvram_brw_global_shortcuts_item_struct*)  VappBrowserASMMemoryMgmt::allocMemory(sizeof(nvram_brw_global_shortcuts_item_struct));
	                memset(newItem, 0, sizeof(nvram_brw_global_shortcuts_item_struct));
	                mmi_chset_ucs2_to_utf8_string((U8*)newItem->url, (NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, (U8*)inputString);
	                oldItem = srv_brw_get_global_shortcut(index);
	                if(strcmp((CHAR*)newItem->url,  (CHAR*)oldItem->url))
	                {
	                    newItem->time = srv_brw_get_current_utc_time();
	                    newItem->is_locked = MMI_FALSE; // default should be FALSE, we will not save the position in 6260
	                    srv_brw_global_shortcuts_list_add_item_at(newItem, index);
	                }
	                VappBrowserASMMemoryMgmt::freeMemory(newItem);
	            }	
			}
			else
			{
				if(mmi_ucs2strlen((CHAR*)inputString) == 0)
                {
                    VappBrowserUtility::displayPopup(
				        STR_ID_VAPP_BRW_INVALID_INPUT,
				        MMI_NMGR_BALLOON_TYPE_FAILURE,
					    MMI_EVENT_INFO_BALLOON);
                    return;
                }
				if (srv_brw_validate_url_ex((U8*)inputString, (SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1), MMI_FALSE) < 0)
                {
                    VfxChar *searchItemString = (VfxChar*)VappBrowserASMMemoryMgmt::allocMemory(SRV_BRW_SEARCH_ITEM_LENGTH + 1);
                    memset(searchItemString, 0, SRV_BRW_SEARCH_ITEM_LENGTH + 1);
                    mmi_chset_ucs2_to_utf8_string((U8*)searchItemString, SRV_BRW_SEARCH_ITEM_LENGTH, (U8*)inputString);
                    srv_brw_launch_search_string((U8*)searchItemString, srv_brw_read_search_engine());
                    VappBrowserASMMemoryMgmt::freeMemory(searchItemString);
                }
                else
                {
                    srv_brw_load_url_req((U8*)inputString, WAP_BAM_UNKNOWN_CHARSET);
                }
				VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
                VcpTextView* textViewer = m_brwApp->scr->page->m_titleBar->getTitleTextEditor();
                if(!m_brwApp->scr->page->m_titleTextBuffer)
                {
                    m_brwApp->scr->page->m_titleTextBuffer = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
                }
                mmi_ucs2cpy((CHAR*) m_brwApp->scr->page->m_titleTextBuffer, (CHAR*) inputString);
                textViewer->setText((VfxWChar*)m_brwApp->scr->page->m_titleTextBuffer, SRV_BRW_MAX_URL_LENGTH);
			}
				
			break;
		}
		case VCP_INPUT_POPUP_BTN_CANCEL:
		{
			break;
		}
		default:
			break;
	}
	if(m_homePageList)
	{
		setHomePageListTotalNumber();
		m_homePageList->resetAllItems(VFX_TRUE);
	}
	VFX_OBJ_CLOSE(sender);
}

void VappBrowserPage::onShortCutListItemLongTapped(VcpListMenu * sender,VfxU32 index)
{
	if((m_progressValue !=0) || srv_brw_is_shortcut_index_empty((U8)index))
    {
        return;
    }
    if(index < BRW_DEFAULT_SHORTCUT_TOTAL)
    {
        return;
    }
    VcpMenuPopup *m_contextMenu;
    VFX_OBJ_CREATE(m_contextMenu, VcpMenuPopup, this);
    VfxWString title;
    nvram_brw_global_shortcuts_item_struct* shortcutItem = srv_brw_get_global_shortcut(index);
    if(strlen((CHAR*)shortcutItem->title.title))
    {
        VfxWChar *textBuff = title.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
        if(shortcutItem->title.dcs == SRV_BRW_DCS_UCS)
        {
            mmi_ucs2ncpy((CHAR*) textBuff, (CHAR*) shortcutItem->title.title , SRV_BRW_MAX_TITLE_LENGTH);
        }
        else
        {           
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) shortcutItem->title.title);            
        }
        title.unlockBuf();
    }
    else
    {
        VfxWChar *titleBuff = title.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
        memset(titleBuff, 0,(SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
        mmi_asc_n_to_ucs2((CHAR*)titleBuff, (CHAR*) shortcutItem->url, SRV_BRW_MAX_URL_LENGTH);
        title.unlockBuf();
    }
    m_contextMenu->setTitle(title);
	m_contextMenu->addItem(COMMAND_SHORTCUT_EDIT, VFX_WSTR_RES(STR_ID_VAPP_BRW_EDIT_ADDRESS));
	m_contextMenu->addItem(COMMAND_SHORTCUT_DELETE, VFX_WSTR_RES(STR_ID_VAPP_BRW_DELETE_SHORTCUT));
    m_contextMenu->m_signalMenuCallback.connect(this, &VappBrowserPage::shortCutMenuPopupCallBack);
    m_contextMenu->show(VFX_TRUE);
    m_selectedShortcutID = index;
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
}

void VappBrowserPage::shortCutMenuPopupCallBack(VcpMenuPopup * menu,VcpMenuPopupEventEnum event,VcpMenuPopupItem * item)
{
	if(event != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }
    switch(item->getId())
    {
        case COMMAND_SHORTCUT_EDIT:
        {
			createUrlInputPopup(m_selectedShortcutID, VFX_TRUE);	
			updateLayerHandle(NULL);
            break;
        }

        case COMMAND_SHORTCUT_DELETE:
        {
            VcpConfirmPopup *confirmPopup;
            confirmPopup = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
                VFX_WSTR_RES(STR_ID_VAPP_BRW_DELETE_SHORTCUT_CONFIRM),
                VFX_WSTR_RES(STR_GLOBAL_DELETE));
            confirmPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::shortCutMenuDeleteCallBack);
            break;
        }
    }
}

void VappBrowserPage::shortCutMenuDeleteCallBack(VfxObject * obj,VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        srv_brw_delete_global_shortcut(m_selectedShortcutID);
        srv_brw_reposition_global_shortcuts();
		if(m_homePageList)
		{
			setHomePageListTotalNumber();
			m_homePageList->resetAllItems(VFX_TRUE);
		}
    }
	
}

#endif
void VappBrowserPage::displayPage(void)
{
    VfxRect page_rect = getRect();
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
        srv_cbm_register_bearer_event(
                SRV_CBM_BEARER_EVENT_DISCONNECT | SRV_CBM_BEARER_EVENT_SWITCH,
                (U8) srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id)),
                VappBrwServiceInterface::vappBrwBearerSwitchHandler,
                NULL);
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_bearerSwitchCallback.connect(this , &VappBrowserPage::bearerSwitchCallback);
#endif
    notifyScreenInfo(page_rect.getX(), page_rect.getY(), page_rect.getWidth(), page_rect.getHeight(), NULL, NULL, TRUE);
    layer_buf_ptr = (PU8)srv_brw_malloc(((LCD_WIDTH*LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);
    widget_paintbox_create_doubble_buffer(page_rect.getX(), page_rect.getY(), page_rect.getWidth(), page_rect.getHeight());
	//this change is for increase the MED buffer size
	//resumeBrowserRendering();
    if(mmi_ucs2strlen((CHAR*)g_srv_brw_cntx.url) > 0)
    {
	    resumeBrowserRendering();
		
        updateToolBarItemsState();
        if(!m_renderPageCP)
        {
            VFX_OBJ_CREATE(m_renderPageCP,VappBrwRenderPagecp,this);
            m_titleBar->setRightIcon(VfxImageSrc(IMG_ID_VAPP_BRW_FULLSCREEN));
            m_titleBar->enableHomePageTap(VFX_TRUE);
        }
            srv_brw_load_url_req((U8*)g_srv_brw_cntx.url, WAP_BAM_UNKNOWN_CHARSET);
            memset(g_srv_brw_cntx.url, 0, sizeof(g_srv_brw_cntx.url));
        }
    else
    {
        srv_brw_load_url_req((U8*)BRW_HOMEPAGE_URL_STR, WAP_BAM_UNKNOWN_CHARSET);
		#ifndef __MMI_BRW_SLIM__
        if(!m_homePage)
        {
            VFX_OBJ_CREATE(m_homePage,VappBrwHomePage,this);
            VfxRect page_rect = getRect();
            m_homePage->setPos(0,0);
            m_homePage->setSize(page_rect.getWidth(), page_rect.getHeight());
            VfxCallback4<VfxU8 , VfxImageSrc &, VfxWString &, VfxBool &> callback(this, &VappBrowserPage::getHomepageShortcutInfo);
            m_homePage->registerCallback(callback);
            m_homePage->m_iconItemLongPress.connect(this, &VappBrowserPage::onShortcutLongTap);
            m_homePage->m_iconItemTap.connect(this, &VappBrowserPage::onShortcutItemTap);
            updateHomePageElemSize();
            m_homePage->setHomePageElementsSize(m_iconWidth,m_iconHeight,m_lockIconWidth, m_lockIconHeight, m_iconTextHeight, m_iconTitleMargin, m_HorizontalpageMargin, m_iconTextFontSize, m_VerticalpageMargin, m_HorizontalExtraMargin, m_VerticalExtraMargin, m_LockTitleTextMargin);
            m_homePage->setRowsColumns(m_NoOfRows,m_NoOfColmns);
            m_titleBar->enableHomePageTap(VFX_FALSE);
        }
		#else
		createHomePageList();
		#endif
    }
}

void VappBrowserPage::wifiBearerCallback(VfxU32 state, VfxU32 errorCause)
{
    if(state == SRV_CBM_ACTIVATED)
    {
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.connect(this , &VappBrowserPage::launchUrlCallback);
    }
    else
    {
        srv_brw_open_bearer_rsp(0);
        if(errorCause != ABM_E_REJECTED)
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_CONNECTION_FAILED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
			    MMI_EVENT_INFO_BALLOON);
        }
    }
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_WifiBearerCallback.disconnect(this , &VappBrowserPage::wifiBearerCallback);
}

void VappBrowserPage::launchUrlCallback(void)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.disconnect(this , &VappBrowserPage::launchUrlCallback);
    srv_brw_open_bearer_rsp(1);
}

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
void VappBrowserPage::bearerSwitchCallback(VfxBool isSocketClosed)
{
    if(!isSocketClosed)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 21, 0, 0, 0);
        VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 25, 0, 0, 0);
    kal_int8 ret = VappBrowserUtility::openBearer();
    if(ret == CBM_WOULDBLOCK)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 23, 0, 0, 0);
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_WifiBearerCallback.connect(this , &VappBrowserPage::wifiBearerSwitchCallback);
    }
    else
    {
        srv_brw_error_enum err = srv_brw_relaunch_last_browser_req();
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 24, 0, 0, err);
        if(err == SRV_BRW_ERROR)
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_BEARER_SWITCH_RETRY,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                MMI_EVENT_INFO_BALLOON);
        }
        VFX_OBJ_CLOSE(m_popup);
    }
}

void VappBrowserPage::wifiBearerSwitchCallback(VfxU32 state, VfxU32 errorCause)
{
    if(state == SRV_CBM_ACTIVATED)
    {
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.connect(this , &VappBrowserPage::relaunchUrlCallback);
    }
    else
    {
        if(errorCause != ABM_E_REJECTED)
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_CONNECTION_FAILED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
			    MMI_EVENT_INFO_BALLOON);
        }
        VFX_OBJ_CLOSE(m_popup);
    }
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_WifiBearerCallback.disconnect(this , &VappBrowserPage::wifiBearerSwitchCallback);
}


void VappBrowserPage::relaunchUrlCallback(void)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.disconnect(this , &VappBrowserPage::relaunchUrlCallback);
    srv_brw_error_enum ret = srv_brw_relaunch_last_browser_req();
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 22, 0, 0, ret);
    if(ret == SRV_BRW_ERROR)
    {
        VappBrowserUtility::displayPopup(
            STR_ID_VAPP_BRW_BEARER_SWITCH_RETRY,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            MMI_EVENT_INFO_BALLOON);
    }
    VFX_OBJ_CLOSE(m_popup);
}
#endif

void VappBrowserPage::onExit(VfxBool isBackward)
{
    suspendBrowserRendering();
}


void VappBrowserPage::onFullScreenIconTap()
{
	setAutoAnimate(VFX_FALSE);
    m_fullsScreenIconSize = m_titleBar->getRightIconRect();
    g_page_rect = getRect();
    /* if the toolbar is not folder then add half the height of the toolbar into the page rect
    height to get the actual height of the rendered page */
    if(!m_toolBar->isFolded())
    {
        g_page_rect.size.height += (m_toolBar->getRect().getHeight()/2);
    }
    setStatusBar(VFX_FALSE);
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_toolBar);
	setFocused(VFX_TRUE);
    if(getRotate() == VFX_SCR_ROTATE_TYPE_0)
    {
        m_fullsScreenIconSize.origin.x = FULL_SCREEN_ICON_POS_X;
        m_fullsScreenIconSize.origin.y = FULL_SCREEN_ICON_POS_Y;
        updateLayerHandle(GDI_NULL_HANDLE);
        widget_paintbox_recreate_double_buffer(0,0,LCD_WIDTH,LCD_HEIGHT);
        notifyScreenInfo(0, 0, LCD_WIDTH, LCD_HEIGHT, NULL, NULL, TRUE);
    }
    else if(getRotate() == VFX_SCR_ROTATE_TYPE_270 || getRotate() == VFX_SCR_ROTATE_TYPE_90)
    {
        m_fullsScreenIconSize.origin.x = ROTATED_FULL_SCREEN_ICON_POS_X;
        m_fullsScreenIconSize.origin.y = ROTATED_FULL_SCREEN_ICON_POS_Y;
        updateLayerHandle(GDI_NULL_HANDLE);
        widget_paintbox_recreate_double_buffer(0,0,LCD_HEIGHT,LCD_WIDTH);
        notifyScreenInfo(0, 0, LCD_HEIGHT,LCD_WIDTH,NULL, NULL, TRUE);
    }
    updateLayerHandle(paintbox_layer_handle);
    widget_paintbox_relayout();
    VFX_OBJ_CREATE(m_exitFullScreenIcon, VcpImageButton, this);
	m_exitFullScreenIcon->setId(0);
    m_exitFullScreenIcon->setPos(m_fullsScreenIconSize.getX(), m_fullsScreenIconSize.getY());
    m_exitFullScreenIcon->setSize(m_fullsScreenIconSize.getWidth(),m_fullsScreenIconSize.getHeight());
	m_exitFullScreenIcon->setImage(VcpStateImage(IMG_ID_VAPP_BRW_MINIMIZE_FULL_SCREEN));
	m_exitFullScreenIcon->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
    m_exitFullScreenIcon->m_signalClicked.connect(this, &VappBrowserPage::onClickFullScreenIcon);
	
    m_isFullScreenMode = VFX_TRUE;
}

void VappBrowserPage::onClickFullScreenIcon(VfxObject *obj, VfxId id)
{
    fullScreenModeExit();
}

void VappBrowserPage::onFullScreenRotate(VfxU32 rotateAngle)
{
    VFX_OBJ_CLOSE(m_exitFullScreenIcon);
    if(rotateAngle == VFX_SCR_ROTATE_TYPE_0)
    {
        m_fullsScreenIconSize.origin.x = FULL_SCREEN_ICON_POS_X;
        m_fullsScreenIconSize.origin.y = FULL_SCREEN_ICON_POS_Y;
        updateLayerHandle(GDI_NULL_HANDLE);
        widget_paintbox_recreate_double_buffer(0,0,LCD_WIDTH,LCD_HEIGHT);
        notifyScreenInfo(0, 0, LCD_WIDTH, LCD_HEIGHT, NULL, NULL, TRUE);
    }
    else if(rotateAngle == VFX_SCR_ROTATE_TYPE_270 || rotateAngle == VFX_SCR_ROTATE_TYPE_90)
    {
        m_fullsScreenIconSize.origin.x = ROTATED_FULL_SCREEN_ICON_POS_X;
        m_fullsScreenIconSize.origin.y = ROTATED_FULL_SCREEN_ICON_POS_Y;
        updateLayerHandle(GDI_NULL_HANDLE);
        widget_paintbox_recreate_double_buffer(0,0,LCD_HEIGHT,LCD_WIDTH);
        notifyScreenInfo(0, 0, LCD_HEIGHT,LCD_WIDTH,NULL, NULL, TRUE);
    }
    updateLayerHandle(paintbox_layer_handle);
	VFX_OBJ_CREATE(m_exitFullScreenIcon, VcpImageButton, this);
	m_exitFullScreenIcon->setId(0);
    m_exitFullScreenIcon->setPos(m_fullsScreenIconSize.getX(), m_fullsScreenIconSize.getY());
    m_exitFullScreenIcon->setSize(m_fullsScreenIconSize.getWidth(),m_fullsScreenIconSize.getHeight());
	m_exitFullScreenIcon->setImage(VcpStateImage(IMG_ID_VAPP_BRW_MINIMIZE_FULL_SCREEN));
	m_exitFullScreenIcon->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
    m_exitFullScreenIcon->m_signalClicked.connect(this, &VappBrowserPage::onClickFullScreenIcon);
	
}

VfxBool VappBrowserPage::onKeyInput(VfxKeyEvent & event)
{
	if(!g_srv_brw_cntx.brw_instance_id && event.type == VFX_KEY_EVENT_TYPE_DOWN 
        && (event.keyCode == VFX_KEY_CODE_HOME || event.keyCode == VFX_KEY_CODE_BACK))
    {
        return VFX_TRUE;
    }
    return VfxPage::onKeyInput(event);
}


void VappBrowserPage::onRotate(const VfxScreenRotateParam &param)
{
	#ifndef __MMI_BRW_SLIM__
    updateHomePageElemSize();
    if(m_homePage)
    {
        VfxRect page_rect = getRect();
        m_homePage->setRect(0,0, page_rect.getWidth(), page_rect.getHeight());
        m_homePage->setHomePageElementsSize(m_iconWidth,m_iconHeight,m_lockIconWidth, m_lockIconHeight, m_iconTextHeight, m_iconTitleMargin, m_HorizontalpageMargin, m_iconTextFontSize, m_VerticalpageMargin, m_HorizontalExtraMargin, m_VerticalExtraMargin, m_LockTitleTextMargin);
        m_homePage->setRowsColumns(m_NoOfRows,m_NoOfColmns);
		if(param.rotateFrom != param.rotateTo)
        {
            updateLayerHandle(GDI_NULL_HANDLE);
            widget_paintbox_recreate_double_buffer(page_rect.getX(),page_rect.getY(),page_rect.getWidth(),page_rect.getHeight());
            notifyScreenInfo(page_rect.getX(), page_rect.getY(), page_rect.getWidth(), page_rect.getHeight(), NULL, NULL, TRUE);
            updateLayerHandle(paintbox_layer_handle);
            if(param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)
            {
                widget_set_screen_rotate_mode(MMI_TRUE);
            }
            else if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0)
            {
                widget_set_screen_rotate_mode(MMI_FALSE);
            }/*
            VfxTimer *rotationTimer; 
            VFX_OBJ_CREATE(rotationTimer, VfxTimer, this);
            rotationTimer->setStartDelay(param.durTime);
            rotationTimer->m_signalTick.connect(this, &VappBrowserPage::rotationTimerCallback);
            rotationTimer->start();*/
        }
    }
	#else
	if(m_homePageList)	
	{
		VfxRect page_rect = getRect();
		m_homePageList->setSize(page_rect.getWidth(), page_rect.getHeight());

		if(param.rotateFrom != param.rotateTo)
        {
            updateLayerHandle(GDI_NULL_HANDLE);
            widget_paintbox_recreate_double_buffer(page_rect.getX(),page_rect.getY(),page_rect.getWidth(),page_rect.getHeight());
            notifyScreenInfo(page_rect.getX(), page_rect.getY(), page_rect.getWidth(), page_rect.getHeight(), NULL, NULL, TRUE);
            updateLayerHandle(paintbox_layer_handle);
            if(param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)
            {
                widget_set_screen_rotate_mode(MMI_TRUE);
            }
            else if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0)
            {
                widget_set_screen_rotate_mode(MMI_FALSE);
            }/*
            VfxTimer *rotationTimer; 
            VFX_OBJ_CREATE(rotationTimer, VfxTimer, this);
            rotationTimer->setStartDelay(param.durTime);
            rotationTimer->m_signalTick.connect(this, &VappBrowserPage::rotationTimerCallback);
            rotationTimer->start();*/
        }
		
    }
	#endif
    else
    {

        if(param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)
        {
            VfxRect page_rect = getRect();
            widget_set_screen_rotate_mode(MMI_TRUE);
            if(m_isFullScreenMode)
            {
                onFullScreenRotate(VFX_SCR_ROTATE_TYPE_270);
            }
            else
            {
                updateLayerHandle(GDI_NULL_HANDLE);
                widget_paintbox_recreate_double_buffer(page_rect.getX(),page_rect.getY(),page_rect.getWidth(),page_rect.getHeight());
                notifyScreenInfo(page_rect.getX(), page_rect.getY(), page_rect.getWidth(), page_rect.getHeight(), NULL, NULL, TRUE);
                updateLayerHandle(paintbox_layer_handle);
            }
        }
        else if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0)
        {
            VfxRect page_rect = getRect();
            widget_set_screen_rotate_mode(MMI_FALSE);
            if(m_isFullScreenMode)
            {
                onFullScreenRotate(VFX_SCR_ROTATE_TYPE_0);
            }
            else
            {
                updateLayerHandle(GDI_NULL_HANDLE);
                widget_paintbox_recreate_double_buffer(page_rect.getX(),page_rect.getY(),page_rect.getWidth(),page_rect.getHeight());
                notifyScreenInfo(page_rect.getX(), page_rect.getY(), page_rect.getWidth(), page_rect.getHeight(), NULL, NULL, TRUE);
                updateLayerHandle(paintbox_layer_handle);
            }
        }
        VfxTimer *rotationTimer; 
        VFX_OBJ_CREATE(rotationTimer, VfxTimer, this);
        rotationTimer->setStartDelay(param.durTime);
        rotationTimer->m_signalTick.connect(this, &VappBrowserPage::rotationTimerCallback);
        rotationTimer->start();
    }
}

void VappBrowserPage::fullScreenModeExit()
{
	updateLayerHandle(GDI_NULL_HANDLE);
	VFX_OBJ_CLOSE(m_exitFullScreenIcon);
    setStatusBar(VFX_TRUE);
    addPageBars();
    updateTitleBarState(VFX_TRUE);
    onUpdate();
    VfxRect page_rect = getRect();
    if(getRotate() == VFX_SCR_ROTATE_TYPE_0)
    {
        widget_paintbox_recreate_double_buffer(0,page_rect.getY(),LCD_WIDTH,page_rect.getHeight());
        notifyScreenInfo(0, page_rect.getY(), LCD_WIDTH, page_rect.getHeight(), NULL, NULL, TRUE);
    }
    else if(getRotate() == VFX_SCR_ROTATE_TYPE_270 || getRotate() == VFX_SCR_ROTATE_TYPE_90)
    {
        widget_paintbox_recreate_double_buffer(0,page_rect.getY(),LCD_HEIGHT,page_rect.getHeight());
        notifyScreenInfo(0,page_rect.getY(),LCD_HEIGHT,page_rect.getHeight(), NULL, NULL, TRUE);
    }
    updateLayerHandle(paintbox_layer_handle);
    widget_paintbox_relayout();
    m_isFullScreenMode = VFX_FALSE;
	setAutoAnimate(VFX_TRUE);
}

void VappBrowserPage::updateLayerHandle(VfxU32 layerHandle)
{
	if(!mmi_frm_group_is_in_active_serial(m_browserAppID))
	{
		return;
	}
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
    setLayerHandle(layerHandle);
    vrt_set_video_layer(VRT_SYS_VIDEO_LAYER_INDEX_0, layerHandle, 0);
}

void VappBrowserPage::onDeinit()
{
    if(m_connectionTimer)
    {
        VFX_OBJ_CLOSE(m_connectionTimer);
    }
	if(m_titleTextBuffer)
	{
        VappBrowserASMMemoryMgmt::freeMemory(m_titleTextBuffer);
	}
    suspendBrowserRendering();
    VFX_OBJ_CLOSE(m_toolBar);
    if(m_frame1)
        VFX_OBJ_CLOSE(m_frame1);
    if(m_searchItemList)
    {
        VFX_OBJ_CLOSE(m_frame1);
	VFX_OBJ_CLOSE(m_searchItemList);
        VFX_OBJ_CLOSE(m_editItemListContentProvider);
    }

    VFX_OBJ_CLOSE(m_page_panel);
    VfxPage::onDeinit(); // call base class
}

void VappBrowserPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	param.durTime = 0;
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
	{
		
	}
	else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	}
}

void VappBrowserPage::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case BROWSER_PAGE_ADD:
        {
            VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
            m_commandPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
            m_commandPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_ADD));
            m_commandPopup->addItem(COMMAND_ADD_TO_BOOKMARKS, VFX_WSTR_RES(STR_ID_VAPP_BRW_ADD_TO_BOOKMARK));
			#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
            m_commandPopup->addItem(COMMAND_ADD_SAVE_PAGE, VFX_WSTR_RES(STR_ID_VAPP_BRW_SAVE_PAGE));
            if(m_progressValue != 0 || g_srv_brw_cntx.private_mode_setting == 1)//|| g_srv_brw_cntx.private_mode_setting == 1 mean private mode on
            {
                m_commandPopup->disableItem(COMMAND_ADD_SAVE_PAGE);
            }
			#endif
            m_commandPopup->addItem(COMMAND_ADD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_commandPopup->show(VFX_TRUE);
            m_commandPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::onAddCommandCallClick);
            break;
        }
		#ifndef __MMI_BRW_SLIM__
        case BROWSER_PAGE_SHARE:
        {
            VappBrowserShareLink *m_browserShareLink;
            VfxWChar *shareURL = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
            memset(shareURL, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((CHAR*)shareURL, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
            VFX_OBJ_CREATE_EX(m_browserShareLink, VappBrowserShareLink, this, (shareURL));
            m_browserShareLink->showCommandPopup();
            VappBrowserASMMemoryMgmt::freeMemory(shareURL);
            break;
        }
		#endif
        case BROWSER_PAGE_SETTINGS:
        {
			VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
			VFX_OBJ_CREATE(m_brwApp->scr->m_settings, VappSettingsPage, m_brwApp->scr);
			//m_brwApp->scr->pushPage(VFX_ID_NULL, m_brwApp->scr->m_settings);
			m_brwApp->scr->pushPage(BRW_PAGE_SETTINGS, m_brwApp->scr->m_settings);
			updateLayerHandle(NULL);
            break;
        }
        case BROWSER_PAGE_BACK:
        {
            if(srv_brw_is_backward_navigation())
            {
                if(!srv_brw_is_in_transaction())
                {
                    srv_brw_navigate_req(WAP_BAM_MOVE_BACKWARD);
                }
            }
            break;
        }
        case BROWSER_PAGE_FORWARD:
        {
            if(srv_brw_is_forward_navigation())
            {
                srv_brw_navigate_req(WAP_BAM_MOVE_FORWARD);
            }
            break;
        }
        case BROWSER_PAGE_FAVOTIRES:
        {
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
			#ifndef __MMI_BRW_SLIM__
			VFX_OBJ_CREATE(m_brwApp->scr->m_favouritePage,VappBrowserFavouritesPage,m_brwApp->scr);
            m_brwApp->scr->pushPage(BRW_PAGE_FAVORITES, m_brwApp->scr->m_favouritePage);
			#else
			VFX_OBJ_CREATE(m_brwApp->scr->m_bookmarkPage,VappBrowserBookmarkPage,m_brwApp->scr);
			m_brwApp->scr->pushPage(BRW_PAGE_BOOKMARK, m_brwApp->scr->m_bookmarkPage);
			#endif
			updateLayerHandle(NULL);
            break;
        }
        case BROWSER_PAGE_EXIT_BROWSER:
        {
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
            m_brwApp->internalTerminateCallback();
        }
        default:
            break;
	}
} 

void VappBrowserPage::vappBrwSendTouchFeedbackCallback(mmi_pen_event_type_enum pen_input_type)
{
    if(pen_input_type == MMI_PEN_EVENT_DOWN)
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
    else if(pen_input_type == MMI_PEN_EVENT_LONG_TAP)
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
}

void VappBrowserPage::onAddCommandCallClick(VfxObject *obj, VfxId id)
{
    switch(id)
    {
        case COMMAND_ADD_TO_BOOKMARKS:
        {
            if(VappBrowserUtility::checkAvailableBookmarkMemory() == VFX_FALSE)
            {
                m_commandPopup = NULL;
                return;
            }
            VfxWString titleStr;
            VfxWString urlStr;
            VfxWChar *titleBuffPtr = titleStr.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
            VfxWChar *urlBuffPtr = urlStr.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);

            mmi_chset_utf8_to_ucs2_string(
                (U8*) titleBuffPtr,
                SRV_BRW_MAX_TITLE_LENGTH * ENCODING_LENGTH,
                (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);
            memset(urlBuffPtr, 0, (SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((CHAR*)urlBuffPtr, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
            urlStr.unlockBuf();
            titleStr.unlockBuf();
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
            VFX_OBJ_CREATE_EX(m_brwApp->scr->m_addBookmarkPage,VappBrowserAddBookmark,m_brwApp->scr, 
                (titleStr, urlStr, VappBrowserAddBookmark::BOOKMARK_MODE_ADD_TO));
            m_brwApp->scr->pushPage(BRW_PAGE_ADD_BOOKMARK, m_brwApp->scr->m_addBookmarkPage);
            m_commandPopup = NULL;
			updateLayerHandle(NULL);
            break;
        }
		#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case COMMAND_ADD_SAVE_PAGE:
        {
        #ifdef __MMI_USB_SUPPORT__
            if(srv_usb_is_in_mass_storage_mode())
            {
                m_commandPopup = NULL;
                vapp_usb_unavailable_popup(0);
            }
            else
        #endif
            {
                VfxWChar *title = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
                VfxWChar *url = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
                memset(title, 0, (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
                memset(url, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);

                mmi_chset_utf8_to_ucs2_string((U8*)title, (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);
                mmi_asc_n_to_ucs2((CHAR*)url, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);

                VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
                VFX_OBJ_CREATE_EX(m_brwApp->scr->m_addPage, VappBrowserAddPage, m_brwApp->scr,
                    ((VfxWChar*)title, (VfxWChar*)url));
                m_brwApp->scr->pushPage(BRW_PAGE_ADD_PAGE, m_brwApp->scr->m_addPage);
                VappBrowserASMMemoryMgmt::freeMemory(title);
                VappBrowserASMMemoryMgmt::freeMemory(url);
                m_commandPopup = NULL;
				updateLayerHandle(NULL);
            }
            break;
        }
		#endif
        case COMMAND_ADD_CANCEL:
        {
            m_commandPopup = NULL;
            break;
        }

        default:
            break;
	}
}


void VappBrowserPage::serverConnectionTimerCallback(VfxTimer *timer)
{
    VappBrowserUtility::bamErrorHandler(WAP_BAM_ERROR_REQUEST_TIMED_OUT);
    srv_brw_stop_page_fetching_req();
    VFX_OBJ_CLOSE(m_connectionTimer);
}


void VappBrowserPage::transactionCallback(U8 transactionStatus, void *userData)
{
    switch(transactionStatus)
    {
        case WAP_BAM_STATUS_START_TRANSACTION:
        {
			widget_paintbox_relayout();
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
			#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
			m_brwApp->scr->closePage(BRW_PAGE_ADD_PAGE);
			#endif
			m_brwApp->scr->closePage(BRW_PAGE_LIST_MENU);
            if(m_brwApp->scr->m_popup)
            {
                m_brwApp->scr->m_popup->hide(VFX_TRUE);
                VFX_OBJ_CLOSE(m_brwApp->scr->m_popup);
            }
            VFX_OBJ_CREATE(m_connectionTimer, VfxTimer, this);
            m_connectionTimer->setStartDelay(g_srv_brw_cntx.timeout_value * 1000);
            m_connectionTimer->m_signalTick.connect(this, &VappBrowserPage::serverConnectionTimerCallback);
            m_connectionTimer->start();

            if(!m_isFullScreenMode)
            {
                m_titleBar->enableScreenModeIconTap(VFX_FALSE);
              	m_titleBar->setEditorIcon(VfxImageSrc(IMG_ID_VAPP_BRW_STOP));
                VcpTextView* textEditor = m_titleBar->getTitleTextEditor();
                textEditor->setIsUnhittable(VFX_TRUE);
                updateToolBarItemsState();
            }
			#ifndef __MMI_BRW_SLIM__
            if(m_homePage)
            {
                m_homePage->setIsUnhittable(VFX_TRUE);
            }
			#else
			if(m_homePageList)
			{
				//m_homePageList->setIsUnhittable(VFX_TRUE);
			}
			#endif
            m_progressValue = 10;
			m_isStopFetching = VFX_FALSE;
            break;
        }

        case WAP_BAM_STATUS_END_TRANSACTION:
        {
			widget_paintbox_relayout();
            VFX_OBJ_CLOSE(m_connectionTimer);
			#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
            srv_brw_set_address_list_entry_flag(MMI_FALSE);
			#endif
            m_progressValue = 0;
            if(!m_isFullScreenMode)
            {
                if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
                {
                    m_titleBar->enableScreenModeIconTap(VFX_TRUE);
                }
				#ifndef __MMI_BRW_SLIM__
                if(m_homePage)
                {
                    m_titleBar->deleteEditorIcon();
                }
                else
				#else
				if(m_homePageList)
				{
					m_titleBar->deleteEditorIcon();
				}
				else
				#endif
                {
                    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
                    {
                        m_titleBar->setEditorIcon(VfxImageSrc(IMG_ID_VAPP_BRW_REFRESH));
                    }
                    else
                    {
                        m_titleBar->deleteEditorIcon();
                    }
                }
                VcpTextView* textEditor = m_titleBar->getTitleTextEditor();
                textEditor->setIsUnhittable(VFX_FALSE);
				#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
                if(m_commandPopup && g_srv_brw_cntx.private_mode_setting != 1)
                {
                    m_commandPopup->enableItem(COMMAND_ADD_SAVE_PAGE);
                }
				#endif
            }
        #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
            if(m_uploadProgress)
            {
                VFX_OBJ_CLOSE(m_uploadProgress);
            }
            if(m_uploadCompleted)
            {
                VFX_OBJ_CLOSE(m_uploadCompleted);
            }
        #endif
            updateToolBarItemsState();
            if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
            {
                if(!m_titleTextBuffer)
                {
                    m_titleTextBuffer = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
                }
				#ifndef __MMI_BRW_SLIM__
                if(!m_homePage)
                {
                    if(strlen(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title))
                    {
                        mmi_chset_utf8_to_ucs2_string(
                            (U8*) m_titleTextBuffer,
                            (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH,
                            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);
                    }
                    else
                    {
                        mmi_asc_n_to_ucs2((CHAR*)m_titleTextBuffer, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
                    }
						updateTitleBarState(VFX_FALSE);
                }
                else
				#else
				if(!m_homePageList)
				{
					if(strlen(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title))
                    {
                        mmi_chset_utf8_to_ucs2_string(
                            (U8*) m_titleTextBuffer,
                            (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH,
                            (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->title);
                    }
                    else
                    {
                        mmi_asc_n_to_ucs2((CHAR*)m_titleTextBuffer, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
                    }
						updateTitleBarState(VFX_FALSE);
				}
				else
				#endif
                {
					m_titleBar->enableHomePageTap(VFX_FALSE);
                    memset(m_titleTextBuffer, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
                }
            }
			#ifndef __MMI_BRW_SLIM__
            if(m_homePage)
            {
                m_homePage->setIsUnhittable(VFX_FALSE);
            }
			#else
			if(!m_homePageList)
            {
                //m_homePageList->setIsUnhittable(VFX_FALSE);
            }
			#endif
        #ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
            if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer)
            {
                MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 52, 0, 0, g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type);
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_NONE;
            }
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.is_switching_bearer = MMI_FALSE;
        #endif
            break;
        }

        case WAP_BAM_STATUS_TRANSACTION_STATUS:
        {
        #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
            if ( g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent > 0 &&
                 g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total > 0)
            {
                showUploadProgress();
            }
            else
        #endif
            {
                if(m_progressValue < 100)
                {
                    m_progressValue += 10;
                }
            }
            break;
        }
    }

    if(!m_isFullScreenMode)
    {
        VcpTextView* textEditor = m_titleBar->getTitleTextEditor();
    	if(m_isStopFetching == VFX_FALSE)
    	{
			kal_prompt_trace(MOD_MMI,"m_progressValue = %d",m_progressValue);
        textEditor->setProgressValue((VfxFloat)m_progressValue/100);
    }
		else
		{	
			m_progressValue = 0;
			textEditor->setProgressValue(m_progressValue);
			kal_prompt_trace(MOD_MMI,"m_isStopFetching = VFX_TRUE");
		}
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
    }
}

#ifndef __MMI_BRW_SLIM__

void VappBrowserPage::homepageSnapshotCallback(void)
{
    if(m_isShortcutFetchedSuccessfully)
    {
        VfxWString snapshotFolderPath;
        snapshotFolderPath.format("%c:\\%s", BRW_HOMEPAGE_SNAPSHOT_FILE_DRIVE, BRW_HOMEPAGE_SHORTCUT_FOLDER_NAME);
        VfxWChar *folderBuffPtr = snapshotFolderPath.lockBuf(SRV_BRW_BKM_MAX_PATH_LEN);
        FS_HANDLE fileHandle= FS_Open((const WCHAR*) folderBuffPtr, FS_READ_ONLY | FS_OPEN_DIR);
        if(fileHandle < FS_NO_ERROR)
        {
            FS_CreateDir((const WCHAR*) folderBuffPtr);
            S32 attr;
            attr = FS_GetAttributes((WCHAR*) folderBuffPtr);
            attr |= FS_ATTR_HIDDEN;
            FS_SetAttributes((WCHAR*) folderBuffPtr, (BYTE) attr);
        }
        snapshotFolderPath.unlockBuf();
        FS_Close(fileHandle);
        VfxWString tempImagePath;
        VfxWString shortcutImagePath;
        if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].id == 0)
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].id = srv_brw_find_available_shortcut_id();
            srv_brw_global_shortcuts_list_update_data();
        }
        shortcutImagePath.format("%c:\\%s\\homepage_snapshot%d.jpg", BRW_HOMEPAGE_SNAPSHOT_FILE_DRIVE, BRW_HOMEPAGE_SHORTCUT_FOLDER_NAME, 
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index].id);
        tempImagePath.format("%c:\\%s\\temp.jpg", BRW_HOMEPAGE_SNAPSHOT_FILE_DRIVE, BRW_HOMEPAGE_SHORTCUT_FOLDER_NAME);
        VfxWChar *tempFile = tempImagePath.lockBuf(SRV_BRW_BKM_MAX_PATH_LEN);
        VfxWChar *snapshotFile = shortcutImagePath.lockBuf(SRV_BRW_BKM_MAX_PATH_LEN);
        widget_create_web_page_bmp((CHAR*)tempFile);
        VfxU8 *buffer = (VfxU8*)mmi_frm_asm_alloc_anonymous_nc((HOME_PAGE_ICON_WIDTH*HOME_PAGE_ICON_HEIGHT*2) + 50);
        gdi_image_encode_file_to_jpeg(
                (CHAR*) tempFile,
                (CHAR *) snapshotFile,
                HOME_PAGE_ICON_WIDTH,
                HOME_PAGE_ICON_HEIGHT,
                buffer,
                ((HOME_PAGE_ICON_WIDTH*HOME_PAGE_ICON_HEIGHT*2) + 50));
        mmi_frm_asm_free_anonymous(buffer);
        FS_Delete(tempFile);
        tempImagePath.unlockBuf();
        shortcutImagePath.unlockBuf();
        m_isShortcutFetchedSuccessfully = VFX_FALSE;
    }
}
#endif

void VappBrowserPage::openBearerCallback(void)
{
    kal_int8 ret_code = CBM_OK;
    ret_code = VappBrowserUtility::openBearer();
    if (ret_code == CBM_OK)
    {
        srv_brw_open_bearer_rsp(1);
    }
    else if(ret_code != CBM_WOULDBLOCK)
    {
        srv_brw_open_bearer_rsp(0);
    }
    else
    {
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_WifiBearerCallback.connect(this , &VappBrowserPage::wifiBearerCallback);
    }
}

void VappBrowserPage::displayProgressPopupCallback(void)
{
    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->show(VFX_TRUE);
}

void VappBrowserPage::closeProgressPopupCallback(void)
{
    VFX_OBJ_CLOSE(m_popup);
}

#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
void VappBrowserPage::showUploadProgress(void)
{
    VfxU32 bytesSent = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_sent;
    VfxU32 bytesTotal = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p->upload_bytes_total;
    if(bytesSent >= bytesTotal)
    {
        if(!m_uploadCompleted)
        {
                VFX_OBJ_CREATE(m_uploadCompleted,VcpIndicatorPopup,this);
                m_uploadCompleted->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS);
                m_uploadCompleted->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_UPLOAD_COMPLETED));
                m_uploadCompleted->setAutoDestory(VFX_FALSE);
                m_uploadCompleted->setProgress((VfxFloat)1.0);
                m_uploadCompleted->show(VFX_TRUE);

                VFX_OBJ_CREATE(m_uploadTimer, VfxTimer, this);
                m_uploadTimer->setStartDelay(BRW_UPLOAD_COMPLETED_TIMER_VALUE);
                m_uploadTimer->m_signalTick.connect(this, &VappBrowserPage::onUploadTimerCallBack);
                m_uploadTimer->start();
        }
        if(m_uploadProgress)
        {
            VFX_OBJ_CLOSE(m_uploadProgress);
        }
    }
    else
    {
        if(!m_uploadProgress)
        {
                VFX_OBJ_CREATE(m_uploadProgress,VcpIndicatorPopup,this);
                m_uploadProgress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON );
                m_uploadProgress->setAutoDestory(VFX_FALSE);
                m_uploadProgress->show(VFX_TRUE);
                m_uploadProgress->m_signalCanceled.connect(this, &VappBrowserPage::onUploadCancelClick);
        }
        VfxWString uploadText;
        uploadText.loadFromRes(STR_ID_VAPP_BRW_UPLOADING);
        VfxChar *completeBuff;
		VFX_ALLOC_MEM(completeBuff, 20, this);
        memset(completeBuff, 0, 20);
        formatUploadSizeTotal(bytesSent, bytesTotal, completeBuff);
        VfxWString completeString;
        completeString.format("(%s)", completeBuff);
    	VFX_FREE_MEM(completeBuff);
        uploadText += completeString;
        m_uploadProgress->setText(uploadText);
        VfxFloat progress = 0.0;
        progress = ((VfxFloat)bytesSent/ bytesTotal);
        m_uploadProgress->setProgress(progress);
    }
}

void VappBrowserPage::onUploadTimerCallBack(VfxTimer *timer)
{
    VFX_OBJ_CLOSE(m_uploadCompleted);
    VFX_OBJ_CLOSE(m_uploadTimer);
}

void VappBrowserPage::formatUploadSizeTotal(VfxU32 bytesSent, VfxU32 bytesTotal, VfxChar *outputBuff)
{
    VfxS8 *ptr;
    VfxChar *tempString;
    VFX_ALLOC_MEM(tempString, 10, this);
    memset(tempString, 0, 10);
    formatUploadSize(bytesSent, (CHAR*) tempString);
    strcpy((CHAR*) outputBuff, (CHAR*) tempString);
    if (bytesTotal)
    {
        ptr = (VfxS8*) outputBuff + strlen((CHAR*) outputBuff);
        ptr[0] = (VfxS8) '/';
        ptr++;
        memset(tempString, 0, 10);
        formatUploadSize(bytesTotal, (CHAR*) tempString);
        strcpy((CHAR*) ptr, (CHAR*) tempString);
    }
	VFX_FREE_MEM(tempString);
}

void VappBrowserPage::formatUploadSize(VfxU64 size, VfxChar *outputBuff)
{
    #define BRW_DISPLAY_UNIT 1024
    VfxS8 unit;
    VfxU16 remain;

    if (size >= BRW_DISPLAY_UNIT * 1024 * 1024)
    {
        size = size / (1024 * 1024);
        unit = 'G';
    }
    else if (size >= BRW_DISPLAY_UNIT * 1024)
    {
        size = size / 1024;
        unit = 'M';
    }
    else if (size >= BRW_DISPLAY_UNIT)
    {
        unit = 'K';
    }
    else
        unit = 'B';

    if (size >= BRW_DISPLAY_UNIT)
    {
        remain = (U16) ((size % 1024) / 103);
        size = size / 1024;
    }
    else
        remain = 0;

    if (remain)
    {
        sprintf((CHAR*) outputBuff, "%d.%d%c", (U16) size, (U16) remain, unit);
    }
    else
    {
        sprintf((CHAR*) outputBuff, "%d%c", (U16) size, unit);
    }
}

void VappBrowserPage::onUploadCancelClick(VfxObject* sender, VfxFloat curr_progress)
{
    srv_brw_stop_page_fetching_req();
    VFX_OBJ_CLOSE(m_uploadProgress);
}
#endif

void VappBrowserPage::documentInfoCallback(void *userData)
{
	// when the redirect url happen, if saved page or waplistmenu is open , close it, or will get fatal error
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	
	if(m_brwApp != NULL)
	{
		#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
		m_brwApp->scr->closePage(BRW_PAGE_ADD_PAGE);
		#endif
		m_brwApp->scr->closePage(BRW_PAGE_LIST_MENU);
	}
	//end
    VFX_OBJ_CLOSE(m_connectionTimer);
	if(m_parent.isValid())
	{
		VFX_OBJ_CLOSE(m_contextMenu);
	}
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcut_item_flag)
    {
        m_isShortcutFetchedSuccessfully = VFX_TRUE;
    }
    if(!(strcmp((CHAR*)"about:homepage",  g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url)))
    {
        if(m_isFullScreenMode)
        {
            fullScreenModeExit();
        }
		
        if(
			#ifndef __MMI_BRW_SLIM__
			!m_homePage
			#else
			!m_homePageList
			#endif
			)
        {
            m_isHomepageMode = VFX_TRUE;
            if(m_titleBar)
            {
                VcpTextView* textEditor = m_titleBar->getTitleTextEditor();
                textEditor->setText(VFX_WSTR(""), SRV_BRW_MAX_URL_LENGTH);               /* set text without any text format*/
                textEditor->setHint(VFX_WSTR_RES(STR_ID_VAPP_BRW_INPUT_ADDRESS_OR_KEYWORDS));   /* Set hint text when editor content is empty */
      	        textEditor->setAutoAnimate(VFX_TRUE);
      	        m_titleBar->deleteRightIcon();
                m_titleBar->enableHomePageTap(VFX_FALSE);
                m_titleBar->deleteEditorIcon();
            }
            checkUpdate();
			updateLayerHandle(NULL);
        }
    }
    else
    {
        if(!m_renderPageCP)
        {
    	    VFX_OBJ_CREATE(m_renderPageCP,VappBrwRenderPagecp,this);
        }
		#ifndef __MMI_BRW_SLIM__
        if(m_homePage)
        {
            VFX_OBJ_CLOSE(m_homePage);
        }
		#else
		if(m_homePageList)
		{
			VFX_OBJ_CLOSE(m_homePageList);
		}
		#endif
        if(!m_titleTextBuffer)
        {
            m_titleTextBuffer = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
        }
        mmi_asc_n_to_ucs2((CHAR*)m_titleTextBuffer, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, SRV_BRW_MAX_URL_LENGTH);
        updateTitleBarState(VFX_TRUE);
		resumeBrowserRendering();
    }
    updateToolBarItemsState();
}

void VappBrowserPage::updateTitleBarState(VfxBool enable)
{
    if(m_titleBar)
    {
        m_titleBar->setRightIcon(VfxImageSrc(IMG_ID_VAPP_BRW_FULLSCREEN));
        if(m_progressValue !=0)
        {
            m_titleBar->setEditorIcon(VfxImageSrc(IMG_ID_VAPP_BRW_STOP));
            m_titleBar->enableScreenModeIconTap(VFX_FALSE);
        }
        else
        {
            if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
            {
  	            m_titleBar->setEditorIcon(VfxImageSrc(IMG_ID_VAPP_BRW_REFRESH));
            }
            else
            {
          	    m_titleBar->deleteEditorIcon();
            }
        }
        /* MAUI_03105495  
		    enable = VFX_TRUE  : eableHomePageTap
		    enable = VFX_FALSE : diaableHomePageTap
            */
		if(enable == VFX_TRUE)
		{
        m_titleBar->enableHomePageTap(VFX_TRUE);
		}
        VcpTextView* textEditor = m_titleBar->getTitleTextEditor();
        if(m_titleTextBuffer)
        {
            textEditor->setText(m_titleTextBuffer, SRV_BRW_MAX_URL_LENGTH);
        }
        textEditor->setAutoAnimate(VFX_FALSE);
    }
}

void VappBrowserPage::errorIndCallback(void *userData)
{
    VFX_OBJ_CLOSE(m_connectionTimer);
    srv_brw_rendering_error_event_struct *evt = (srv_brw_rendering_error_event_struct*)userData;
    if(evt->error_code == WAP_BAM_ERROR_OUT_OF_MEMORY)
    {
        VcpConfirmPopup *m_confirmPopup;
        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_INSUFFICIENT_MEMORY_CONFIRM));
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_confirmPopup->setAutoDestory(VFX_FALSE);
        m_confirmPopup->show(VFX_TRUE);
        m_confirmPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::insufficientMemoryEventHandler);
    }
#ifdef __BAIDU_TRANSCODING_SUPPORT__
#ifdef OBIGO_Q03C
    else if(evt->error_code == WAP_BAM_ERROR_PAGE_NOT_FOUND)
    {
        if(g_srv_brw_cntx.baidu_proxy_status)
        {
            VcpConfirmPopup *m_confirmPopup;
            VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
            m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_SWITCH_OFF_BAIDU_PROXY_CONFIRM));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_confirmPopup->setAutoDestory(VFX_FALSE);
            m_confirmPopup->setCustomButton(
			    VFX_WSTR_RES(STR_GLOBAL_YES),
			    VFX_WSTR_RES(STR_GLOBAL_NO),
			    VCP_POPUP_BUTTON_TYPE_NORMAL,
			    VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->show(VFX_TRUE);
            m_confirmPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::onBaiduProxyErrorConfirm);
        }
    }
#endif /* OBIGO_Q03C */
#endif //#ifdef __BAIDU_TRANSCODING_SUPPORT__
    else
    {
        VappBrowserUtility::bamErrorHandler(evt->error_code);
    }
}
#ifdef __BAIDU_TRANSCODING_SUPPORT__
void VappBrowserPage::onBaiduProxyErrorConfirm(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        g_srv_brw_cntx.baidu_proxy_status = 0;
        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY);
	    srv_brw_change_setting_value_req(
		wap_bam_setting_value_type_int,
		wap_bam_setting_id_transcode_proxy,
		g_srv_brw_cntx.baidu_proxy_status,
		NULL);
    }
}
#endif //#ifdef __BAIDU_TRANSCODING_SUPPORT__

void VappBrowserPage::insufficientMemoryEventHandler(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_OK || id == VCP_POPUP_BUTTON_NO_PRESSED)
    {
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
        m_brwApp->internalTerminateCallback();
    }
}

#if (defined (WAP_SEC_SUPPORT) && !defined (__LOW_COST_SUPPORT_COMMON__))
void VappBrowserPage::secConfirmCallback(void *userData)
{
    VFX_OBJ_CLOSE(m_connectionTimer);
    MMI_ASSERT(m_secRequestID == 0);
    srv_brw_confirm_action_event_struct *event = (srv_brw_confirm_action_event_struct*)userData;
    wps_show_confirm_dialog_ind_struct *sec = (wps_show_confirm_dialog_ind_struct*)event->data_ptr;
    VFX_OBJ_CREATE(m_secConfirmPopup, VcpConfirmPopup, this);
    m_secRequestID = sec->request_id;
    switch(sec->dialog_type)
    {
        case WPS_DLG_INFO:
        {
            m_secConfirmPopup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
            break;
        }
        case WPS_DLG_ERROR:
        {
            m_secConfirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
            break;
        }
        default:
        {
            m_secConfirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            break;
        }
    }
    m_secConfirmPopup->setText(VFX_WSTR_RES(sec->text_id));
    m_secConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    if(sec->buttons == WPS_DLG_BUTTON_YESNO)
    {
        m_secConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    }
    else
    {
        m_secConfirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    }
    m_secConfirmPopup->setAutoDestory(VFX_FALSE);
    m_secConfirmPopup->show(VFX_TRUE);
    m_secConfirmPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::secConfirmEventHandler);
}

void VappBrowserPage::secConfirmEventHandler(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        srv_brw_ren_page_sec_confirm_dialog_res(m_secRequestID, WPS_DLG_OK);
    }
    else
    {
        srv_brw_ren_page_sec_confirm_dialog_res(m_secRequestID, WPS_DLG_CANCEL);
    }
    m_secRequestID = 0;
}
#endif

void VappBrowserPage::displayImageOptions(void)
{
    VFX_OBJ_CREATE(m_contextMenu, VcpMenuPopup, this);
	m_parent = m_contextMenu;
    m_contextMenu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_PICTURE_OPTION));
    if(strlen(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->url))
    {
        m_contextMenu->addItem(IMAGE_OPTION_OPEN, VFX_WSTR_RES(STR_ID_VAPP_BRW_OPEN_IN_NEW_PAGE));
    }
    m_contextMenu->addItem(IMAGE_OPTION_SAVE, VFX_WSTR_RES(STR_ID_VAPP_BRW_SAVE_PICTURE));
    m_contextMenu->m_signalMenuCallback.connect(this, &VappBrowserPage::imageMenuCallack);
	m_contextMenu->setAutoDestory(VFX_FALSE);
    m_contextMenu->show(VFX_TRUE);
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
}

void VappBrowserPage::imageMenuCallack(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item)
{
    if(event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        switch(item->getId())
        {
            case IMAGE_OPTION_OPEN:
            {
                VfxWString imageUrl;
                VfxWChar *imageUrlBuff = imageUrl.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1)* ENCODING_LENGTH);
                mmi_asc_to_ucs2((CHAR*) imageUrlBuff, (CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->url);
                srv_brw_load_url_req((U8*)imageUrlBuff, WAP_BAM_UNKNOWN_CHARSET);
                imageUrl.unlockBuf();
                break;
            }

            case IMAGE_OPTION_SAVE:
            {
            #ifdef __MMI_USB_SUPPORT__
                if(srv_usb_is_in_mass_storage_mode())
                {
                    vapp_usb_unavailable_popup(0);
                    return;
                }
            #endif
                srv_brw_ren_page_object_action_req(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p->type);
                break;
            }
        }
    }
}

void VappBrowserPage::displayWapEditor(void *obj)
{
    suspendBrowserRendering();
    vappBrwFullScreenEditorStruct *editorInfo = (vappBrwFullScreenEditorStruct*)obj;
	if(editorInfo->is_textarea == VFX_FALSE)
	{
    VFX_OBJ_CREATE(m_editorInput, VcpInputPopup, this);
    m_editorInput->setTitle(VFX_WSTR_RES(STR_GLOBAL_EDIT));
    m_editorInput->m_signalButtonClicked.connect(this, &VappBrowserPage::OnEditorButtonClicked);
    VcpTextEditor *wapEditor = m_editorInput->getInputbox();
    wapEditor->setIME(editorInfo->inputType, IME_DISABLE_NEW_LINE_SYMBOL);
    wapEditor->setText((VfxWChar*)editorInfo->dataBuffer, editorInfo->maxLen);
		wapEditor->setMaxLength(editorInfo->maxLen);
    m_editorInput->setIsAllowedEmptyContent(VFX_TRUE);
    m_editorInput->setAutoDestory(VFX_FALSE);
    m_editorInput->show(VFX_TRUE);
	}
	else
	{
		VFX_OBJ_CREATE(m_editorInput, VappBrowserTextAreaInputPopup, this);
		m_editorInput->setTitle(VFX_WSTR_RES(STR_GLOBAL_EDIT));
	    m_editorInput->m_signalButtonClicked.connect(this, &VappBrowserPage::OnEditorButtonClicked);
	    VcpTextEditor *wapEditor = m_editorInput->getInputbox();
		wapEditor->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
	    wapEditor->setText((VfxWChar*)editorInfo->dataBuffer, editorInfo->maxLen);	
		wapEditor->setIME(editorInfo->inputType);
	    m_editorInput->setIsAllowedEmptyContent(VFX_TRUE);
	    m_editorInput->setAutoDestory(VFX_FALSE);
	    m_editorInput->show(VFX_TRUE);
	}
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}

void VappBrowserPage::OnEditorButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VcpTextEditor *editor = m_editorInput->getInputbox();
            VfxWChar *editorBuffer = editor->getText();
            widget_accept_fullscreen_input_from_browser((U8*)editorBuffer);
            VFX_OBJ_CLOSE(m_editorInput);
            break;
        }
        case VCP_INPUT_POPUP_BTN_CANCEL:
        {
            widget_exit_fullscreen_editor_with_cancel_level1();
            VFX_OBJ_CLOSE(m_editorInput);
            break;
        }
        default:
            break;
    }
    resumeBrowserRendering();
}

void VappBrowserPage::displayWapListMenu(vappBrwListMenuChoiceEnum listType)
{
	srv_brw_stop_page_fetching_req();
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	
	m_brwApp->scr->page->m_progressValue = 0;
	m_brwApp->scr->page->m_isStopFetching = VFX_TRUE;
	VFX_OBJ_CREATE_EX(m_brwApp->scr->m_waplistmenu, VappWapListMenuPage, m_brwApp->scr, (listType));
	//m_brwApp->scr->pushPage(VFX_ID_NULL, m_brwApp->scr->m_waplistmenu);
	m_brwApp->scr->pushPage(BRW_PAGE_LIST_MENU, m_brwApp->scr->m_waplistmenu);
	updateLayerHandle(NULL);
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
#endif //0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
void VappBrowserPage::onExitConfrmPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        if(m_clickOk == VFX_TRUE)
        {
            m_clickOk = VFX_FALSE;
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
            m_brwApp->internalTerminateCallback();
        }
    }
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
#endif //0

void VappBrowserPage::displayAuthentication(void)
{
    VFX_OBJ_CLOSE(m_connectionTimer);
    VFX_OBJ_CREATE(m_authenticationInput, VcpInputPopup, this);
    m_authenticationInput->setGroupNum(AUTH_EDITOR_TOTAL);
    m_authenticationInput->setTitle(VFX_WSTR_RES(STR_GLOBAL_AUTHENTICATION));
    m_authenticationInput->setHintText(VFX_WSTR_RES(STR_GLOBAL_USERNAME), AUTH_EDITOR_USERNAME);
    m_authenticationInput->setHintText(VFX_WSTR_RES(STR_GLOBAL_PASSWORD), AUTH_EDITOR_PASSWORD);
    m_authenticationInput->m_signalButtonClicked.connect(this, &VappBrowserPage::OnAuthenticationButtonClicked);
    VfxWString username;
    VfxWString password;
    VfxWChar *usernameBuff = username.lockBuf((WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH);
    VfxWChar *passwordBuff = password.lockBuf((WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) usernameBuff,
        (WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.http_auth_info_p->username);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) passwordBuff,
        (WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH,
        (U8*) g_srv_brw_cntx.http_auth_info_p->password);
    username.unlockBuf();
    password.unlockBuf();
    VcpTextEditor *usernameEditor = m_authenticationInput->getInputbox(AUTH_EDITOR_USERNAME);
    VcpTextEditor *passwordEditor = m_authenticationInput->getInputbox(AUTH_EDITOR_PASSWORD);
    usernameEditor->setText(username, WAP_BAM_MAX_USER_PASSWD_LENGTH);
    passwordEditor->setText(password, WAP_BAM_MAX_USER_PASSWD_LENGTH);
    usernameEditor->setIME(IMM_INPUT_TYPE_NO_TITLECASE_SENTENCE, IME_DISABLE_NEW_LINE_SYMBOL);
    passwordEditor->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, IME_DISABLE_NEW_LINE_SYMBOL);
    m_authenticationInput->setAutoDestory(VFX_FALSE);
    m_authenticationInput->show(VFX_TRUE);
}

void VappBrowserPage::OnAuthenticationButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    VfxWString inputText0;
    VfxWString inputText1;
    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VfxWString username = m_authenticationInput->getText(0);
            VfxWString password = m_authenticationInput->getText(1);

            /*if (username.isEmpty() && password.isEmpty())
            {
            }
            */
            VfxWChar *usernameBuff = username.lockBuf((WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH);
            VfxWChar *passwordBuff = password.lockBuf((WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH);
            srv_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD, (U8*)usernameBuff, (U8*)passwordBuff);
            username.unlockBuf();
            password.unlockBuf();
            VFX_OBJ_CLOSE(m_authenticationInput);
            break;
        }
        case VCP_INPUT_POPUP_BTN_CANCEL:
        {
            srv_brw_ren_page_show_auth_dialog_res(WAP_BAM_AUTH_OPTIONS_CANCEL, NULL, NULL);
            VFX_OBJ_CLOSE(m_authenticationInput);
            break;
        }
        default:
            break;
    }
}


#ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
void VappBrowserPage::selectUploadFile(void)
{
    FMGR_FILTER filter;
    FMGR_FILTER_INIT(&filter);
    //FMGR_FILTER_SET(&filter, FMGR_TYPE_ALL);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_id cui_id = vcui_file_selector_create(m_browserAppID, (const WCHAR*)L"root", &filter, VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);
    if (cui_id != GRP_ID_INVALID)
    {
	    vcui_file_selector_run(cui_id);
        VappBrowserApp::m_eventCallback.connect(this, &VappBrowserPage::fmgrCuiCallback);
    }
}

void VappBrowserPage::fmgrCuiCallback(void *param)
{
    switch(((mmi_event_struct*)param)->evt_id)
    {
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:
        {
			vcui_file_selector_result_event_struct *evt = (vcui_file_selector_result_event_struct*)param;
			if (evt->result == 1)
			{
				VfxWChar *filePath = NULL;
				VFX_ALLOC_MEM(filePath, (SRV_BRW_BKM_MAX_PATH_LEN + 1)* ENCODING_LENGTH, this);
				memset(filePath, 0, (SRV_BRW_BKM_MAX_PATH_LEN + 1)* ENCODING_LENGTH);
				vcui_file_selector_get_selected_filepath(evt->sender_id, NULL, (WCHAR*)filePath, (SRV_BRW_BKM_MAX_PATH_LEN + 1)* ENCODING_LENGTH);
            #if defined (__DRM_SUPPORT__)
                VfxU8 drm_result = DRM_get_object_method(0, (kal_wchar*) filePath);
                if (drm_result & DRM_METHOD_FORWARD_LOCK || drm_result & DRM_METHOD_COMBINED_DELIVERY)
                {
                    srv_brw_select_file_rsp(WAP_BAM_ERROR_FILE_SELECTION_FAILED, (U8*) NULL);
                    VappBrowserUtility::displayPopup(
                        STR_GLOBAL_DRM_PROHIBITED,
                        MMI_NMGR_BALLOON_TYPE_FAILURE,
					    MMI_EVENT_INFO_BALLOON);
                }
                else
            #endif
                {
                    srv_brw_select_file_rsp(WAP_BAM_ERROR_FILE_SELECTION_OK, (U8*) filePath);
                }
				VFX_FREE_MEM(filePath);
            }
            else
            {
                srv_brw_select_file_rsp(WAP_BAM_ERROR_FILE_SELECTION_FAILED, (U8*) NULL);
            }
            VappBrowserApp::m_eventCallback.disconnect(this, &VappBrowserPage::fmgrCuiCallback);
    	    vcui_file_selector_close(evt->sender_id);					
        }
    }
}
#endif


void VappBrowserPage::showWmlsDialog(void *param)
{
    wap_bam_wmls_create_dialogue_req_struct *dialog = (wap_bam_wmls_create_dialogue_req_struct*)param;
    if(dialog->dialup_type == BAM_DLG_WMLS_PROMPT)
    {
        VcpInputPopup *editorInput;
        VFX_OBJ_CREATE(editorInput, VcpInputPopup, this);
        editorInput->setTitle(VFX_WSTR_RES(STR_GLOBAL_EDIT));
        editorInput->m_signalButtonClicked.connect(this, &VappBrowserPage::OnPromptButtonClicked);
        VcpTextEditor *dialogPrompt = editorInput->getInputbox();
        dialogPrompt->setIME(IMM_INPUT_TYPE_SENTENCE, IME_DISABLE_NEW_LINE_SYMBOL);
        VfxWChar *promptText = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((WAP_BAM_MAX_WMLS_MSG_LENGTH + 1)* ENCODING_LENGTH);
        memset(promptText, 0, (WAP_BAM_MAX_WMLS_MSG_LENGTH + 1)* ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string((U8*)promptText, 
            (WAP_BAM_MAX_WMLS_MSG_LENGTH + 1) * ENCODING_LENGTH, 
            (U8*) dialog->prompt_msg);
        dialogPrompt->setText(promptText, WAP_BAM_MAX_WMLS_MSG_LENGTH);
        mmi_chset_utf8_to_ucs2_string((U8*)promptText, 
            (WAP_BAM_MAX_WMLS_MSG_LENGTH + 1) * ENCODING_LENGTH, 
            (U8*) dialog->msg);
        editorInput->setHintText(VFX_WSTR_MEM(promptText));
        editorInput->setAutoDestory(VFX_FALSE);
        editorInput->show(VFX_TRUE);
        VappBrowserASMMemoryMgmt::freeMemory(promptText);
    }
    else
    {
        VcpConfirmPopup *confirmPopup;
        VfxWChar *promptText = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((WAP_BAM_MAX_WMLS_MSG_LENGTH + 1)* ENCODING_LENGTH);
        memset(promptText, 0, (WAP_BAM_MAX_WMLS_MSG_LENGTH + 1)* ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string((U8*)promptText, 
            (WAP_BAM_MAX_WMLS_MSG_LENGTH + 1) * ENCODING_LENGTH, 
            (U8*) dialog->msg);

        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
        confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        confirmPopup->setText(VFX_WSTR_MEM(promptText));
        if(dialog->dialup_type == BAM_DLG_WMLS_ALERT)
        {
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        }
        else
        {
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            VfxWChar *lsk = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory(strlen(dialog->lsk) * ENCODING_LENGTH);
            VfxWChar *rsk = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory(strlen(dialog->rsk) * ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*)lsk, 
                (strlen(dialog->lsk) * ENCODING_LENGTH), 
                (U8*) dialog->lsk);
            mmi_chset_utf8_to_ucs2_string((U8*)rsk, 
                (strlen(dialog->rsk) * ENCODING_LENGTH), 
                (U8*) dialog->rsk);
            confirmPopup->setCustomButton(VFX_WSTR_MEM(lsk), VFX_WSTR_MEM(rsk), VCP_POPUP_BUTTON_TYPE_RECOMMEND, VCP_POPUP_BUTTON_TYPE_CANCEL);
            VappBrowserASMMemoryMgmt::freeMemory(lsk);
            VappBrowserASMMemoryMgmt::freeMemory(rsk);
        }
        confirmPopup->show(VFX_TRUE);
        confirmPopup->m_signalButtonClicked.connect(this, &VappBrowserPage::OnWmlsConfirmButtonClicked);
    }
}


void VappBrowserPage::OnPromptButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VcpInputPopup *editorInput = (VcpInputPopup*)sender;
            VcpTextEditor *editor = editorInput->getInputbox();
            VfxWChar *editorBuffer = editor->getText();
            srv_brw_wmls_dialog_rsp(1, BAM_DLG_WMLS_PROMPT, (U8*)editorBuffer);
            break;
        }
        default:
        {
            srv_brw_wmls_dialog_rsp(0, BAM_DLG_WMLS_PROMPT, NULL);
            break;
        }
    }
    VFX_OBJ_CLOSE(sender);
}

void VappBrowserPage::OnWmlsConfirmButtonClicked(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        srv_brw_wmls_dialog_rsp(1, BAM_DLG_WMLS_CONFIRM, NULL);
    }
    else if(id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        srv_brw_wmls_dialog_rsp(0, BAM_DLG_WMLS_CONFIRM, NULL);
    }
    else if(id == VCP_CONFIRM_POPUP_BUTTON_OK)
    {
        srv_brw_wmls_dialog_rsp(1, BAM_DLG_WMLS_ALERT, NULL);
    }
    else
    {
        srv_brw_wmls_dialog_rsp(0, BAM_DLG_WMLS_CONFIRM, NULL);
    }
}

mmi_ret VappBrowserScreen::onProc(mmi_event_struct * evt)
{
	#ifdef __MMI_SMS_COMPOSER__
	switch(evt->evt_id)
	{
		case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
		{
			// just close the cui
			VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct *)evt;
			vcui_sms_composer_close(ucEvt->sender_id);
			break;
		}
	}
	#endif
	return MMI_RET_OK;
}

#ifndef __MMI_BRW_SLIM__

VappBrowserShareLink::VappBrowserShareLink(VfxWChar *shareUrl)
{
    MMI_ASSERT(shareUrl);
    m_shareUrl =  (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory(520);
    memset(m_shareUrl, 0, 520);
    mmi_ucs2ncpy((CHAR*) m_shareUrl, (CHAR*) shareUrl , 520);
}

void VappBrowserShareLink::showCommandPopup(void)
{
    setInfoType(VCP_POPUP_TYPE_QUESTION);
    setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_SHARE_LINK));
	if(m_isLowMemMode != VFX_TRUE)
	{
#if defined (__MMI_UNIFIED_COMPOSER__) || defined(__MMI_SMS_COMPOSER__)
    addItem(COMMAND_SHARE_VIA_SMS, VFX_WSTR_RES(STR_ID_VAPP_BRW_SHARE_VIA_SMS));
#endif
#ifndef __LOW_COST_SUPPORT_COMMON__    
#ifdef __MMI_UNIFIED_COMPOSER__
    addItem(COMMAND_SHARE_VIA_MMS, VFX_WSTR_RES(STR_ID_VAPP_BRW_SHARE_VIA_MMS));
#endif
#endif
	}
	
#if defined(__MMI_EMAIL__)
    if(mmi_email_is_email_can_forward())
    {
        addItem(COMMAND_SHARE_VIA_EMAIL, VFX_WSTR_RES(STR_ID_VAPP_BRW_SHARE_LINK_VIA_EMAIL));
    }
#endif /* defined(__MMI_EMAIL__) */
#if defined(__MMI_OPP_SUPPORT__ )
    if(mmi_bt_is_to_display_bt_menu())
    {
        addItem(COMMAND_SHARE_VIA_BT, VFX_WSTR_RES(STR_ID_VAPP_BRW_SHARE_LINK_VIA_BLUETOOTH));
    }
#endif /* defined(__MMI_BT_MULTI_SEND_SUPPORT__) */ 
    addItem(COMMAND_SHARE_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    show(VFX_TRUE);
    m_signalButtonClicked.connect(this, &VappBrowserShareLink::onShareCommandCallClick);
}

void VappBrowserShareLink::onShareCommandCallClick(VfxObject *obj, VfxId id)
{
    switch(id)
    {
        case COMMAND_SHARE_VIA_SMS:
        {
    	#ifdef __MMI_UNIFIED_COMPOSER__
            VappUcEntryStruct ucSMSData = {0};
            ucSMSData.info_type = (srv_uc_info_type_enum)SRV_UC_INFO_TYPE_SMS;
            ucSMSData.type = (srv_uc_state_enum)SRV_UC_STATE_WRITE_NEW_MSG;
            ucSMSData.operation = (vappUcMsgOperationEnum)UC_OPERATION_WRITE_NEW_MSG;
            ucSMSData.text_buffer = (U8*)m_shareUrl;
            ucSMSData.text_num = mmi_ucs2strlen((CHAR*)m_shareUrl);
			#ifdef __LOW_COST_SUPPORT_COMMON__
			ucSMSData.msg_type = (srv_uc_msg_type_enum)SRV_UC_MSG_TYPE_SMS_ONLY;
			#endif
            mmi_id cui_id = vcui_unifiedcomposer_create(m_browserAppID, &ucSMSData);
            if(cui_id != GRP_ID_INVALID)
            {
                vcui_unifiedcomposer_run(cui_id);
            }
            //break;
		#else
			#ifdef __MMI_SMS_COMPOSER__
			mmi_id smsComposerCui = 0;
			VcuiSmsComposerEntryStruct entryData ; 
			memset(&entryData, 0, sizeof(VcuiSmsComposerEntryStruct));
			//VFX_ALLOC_MEM(entryData,sizeof(VcuiSmsComposerEntryStruct),this);
			//vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct));

			//set text
			VfxWChar *m_tempShareUrl = NULL;
            m_tempShareUrl =  (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory(520);
            memset(m_tempShareUrl, 0, 520);
            mmi_ucs2ncpy((CHAR*) m_tempShareUrl, (CHAR*) m_shareUrl , 520);
            
			entryData.text_buffer = (VfxWChar *)m_tempShareUrl;
			entryData.text_num = mmi_ucs2strlen((CHAR*)m_tempShareUrl);

			smsComposerCui = vcui_sms_composer_create(m_browserAppID);
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
			if(smsComposerCui != GRP_ID_INVALID)
			{
				vcui_sms_composer_set_entry_data(smsComposerCui, &entryData);
				vfxSetCuiCallerScr(smsComposerCui, m_brwApp->scr);
				vcui_sms_composer_run(smsComposerCui);
        }
            VFX_FREE_MEM(m_tempShareUrl);
			//VFX_FREE_MEM(entryData);
            //break;
		#endif
		#endif
            break;
        }
		#ifndef __LOW_COST_SUPPORT_COMMON__
		#ifdef __MMI_UNIFIED_COMPOSER__
        case COMMAND_SHARE_VIA_MMS:
        {
            VappUcEntryStruct ucMMSData = {0};
            ucMMSData.info_type = (srv_uc_info_type_enum)SRV_UC_INFO_TYPE_MMS;
            ucMMSData.msg_type = (srv_uc_msg_type_enum)SRV_UC_MSG_TYPE_MMS_ONLY;
            ucMMSData.type = (srv_uc_state_enum)SRV_UC_STATE_WRITE_NEW_MSG;
            ucMMSData.operation = (vappUcMsgOperationEnum)UC_OPERATION_WRITE_NEW_MSG;
            ucMMSData.text_buffer = (U8*)m_shareUrl;
            ucMMSData.text_num = mmi_ucs2strlen((CHAR*)m_shareUrl);
            mmi_id cui_id = vcui_unifiedcomposer_create(m_browserAppID, &ucMMSData);
            if(cui_id != GRP_ID_INVALID)
            {
                vcui_unifiedcomposer_run(cui_id);
            }
            break;
        }
		#endif
		#endif

    #if defined(__MMI_EMAIL__)
        case COMMAND_SHARE_VIA_EMAIL:
        {
            mmi_email_app_send_cont((CHAR*) m_shareUrl);
            break;
        }
    #endif
    #if defined(__MMI_OPP_SUPPORT__ )
        case COMMAND_SHARE_VIA_BT:
        {
            VfxU32 option = 0;
            vapp_bt_send_app_info appInfo = {0};
            appInfo.group_id = m_browserAppID;
            VfxWChar *objArray[1];
            U8 def_drive_str[SRV_BRW_BKM_DRIVE_NAME_LENGTH];
            sprintf((CHAR*) def_drive_str, "%c", BRW_TEMP_VBKM_FILE_DRIVE);
            VfxWChar *shareFilePath = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_BKM_MAX_PATH_LEN + 1) *ENCODING_LENGTH);
            memset(shareFilePath, 0, (SRV_BRW_BKM_MAX_PATH_LEN + 1) *ENCODING_LENGTH);
            mmi_asc_to_ucs2((CHAR*) shareFilePath, (CHAR*) def_drive_str);
            mmi_ucs2cat((CHAR*) shareFilePath, (CHAR*) L":");
            mmi_ucs2cat((CHAR*) shareFilePath, (CHAR*) BRW_TEMP_VBKM_FILE_PATH);
            VfxS32 error_code = srv_brw_bookmarks_create_standard_vbookmark_file((U8*)shareFilePath,(U8*)m_shareUrl);
            if(error_code != FS_NO_ERROR)
            {
                VappBrowserUtility::fileSystemErrorHandler(error_code);
                VappBrowserASMMemoryMgmt::freeMemory(m_shareUrl);
				m_shareUrl = NULL;
				VappBrowserASMMemoryMgmt::freeMemory(shareFilePath);
                VFX_OBJ_CLOSE(obj);
                return;
            }
            option = VAPP_BT_SEND_DELETE_FILE;
            objArray[0] = shareFilePath;
            vapp_bt_send_obj(&appInfo, option, 1, (VfxWChar**)&objArray);
            VappBrowserASMMemoryMgmt::freeMemory(shareFilePath);
            break;
        }
    #endif
        case COMMAND_SHARE_CANCEL:
        {
            break;
        }

        default:
            break;
	}
}

#endif	//	?__MMI_BRW_SLIM__

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__

VappBrowserAddPage::VappBrowserAddPage(VfxWChar *pageTitle, VfxWChar *pageUrl):
     m_titleBar(NULL),
     m_form(NULL),
     m_titleCaption(NULL),
     m_titleInput(NULL),
     m_urlCaption(NULL),
     m_urlInput(NULL),
     m_funcBar(NULL),
     m_urlView(NULL),
     m_toolBar(NULL)
 {
    m_pageTitle = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
    memset(m_pageTitle, 0, (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
    m_pageUrl = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
    memset(m_pageUrl, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
    if(pageTitle)
    {
       mmi_ucs2ncpy((CHAR*)m_pageTitle, (CHAR*)pageTitle, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    }
    if(pageUrl)
    {
       mmi_ucs2ncpy((CHAR*)m_pageUrl, (CHAR*)pageUrl, SRV_BRW_MAX_URL_LENGTH);
    }
    else
    {
       MMI_ASSERT(0);
    }
}



// Add saved Page Begin
void VappBrowserAddPage::onInit(void)
{
    VfxPage::onInit();
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_SAVE_PAGE));
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(ADD_PAGE_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem(ADD_PAGE_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappBrowserAddPage::onTBClick);
    setBottomBar(m_toolBar); 

    VFX_OBJ_CREATE(m_form, VcpForm, this);

    VfxRect page_rect = getRect();
    m_form->setRect(0, 0, page_rect.size.width, page_rect.size.height);
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_titleCaption , VcpFormItemCaption, this);
	m_titleCaption->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_NAME));

	VFX_OBJ_CREATE(m_titleInput, VcpFormItemTextInput, m_form);
    VcpTextEditor *textEditor = m_titleInput->getTextBox();
    textEditor->setText(m_pageTitle, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    textEditor->setIME(IMM_INPUT_TYPE_SENTENCE);

    VFX_OBJ_CREATE(m_urlCaption , VcpFormItemCaption, this);
	 m_urlCaption->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_URL));

    VFX_OBJ_CREATE(m_urlInput, VcpFormItemCustomFrame, m_form);
    VFX_OBJ_CREATE(m_urlView, VcpTextView, m_urlInput);
    m_urlInput->setHeight(VCPFRM_STD_UI_EDITOR_HEIGHT + (2 * VCPFRM_ITEM_HORZ_GAP_2));
    m_urlView->setText(m_pageUrl);
    m_urlView->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_urlView->disableBackground(VFX_FALSE);
    m_urlView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_GREY);
    VfxRect rect = m_form->getRect();
    m_urlView->setPos(VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2, VCPFRM_ITEM_HORZ_GAP_2);
    m_urlView->setSize(rect.getWidth() - (2 *(VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2)), VCPFRM_STD_UI_EDITOR_HEIGHT);
	m_urlView->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    m_form->addItem(m_titleCaption,0);
    m_form->addItem(m_titleInput,1);
    m_form->addItem(m_urlCaption,2);
    m_form->addItem(m_urlInput,3);
    VappBrowserASMMemoryMgmt::freeMemory(m_pageTitle);
    VappBrowserASMMemoryMgmt::freeMemory(m_pageUrl);

    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem(0, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_funcBar->setItemSpecial(0);
    (m_titleInput->getTextBox())->setFunctionBar(m_funcBar);
    m_funcBar->m_signalButtonTap.connect(this,&VappBrowserAddPage::onFuncBarItemSelected);
    (m_titleInput->getTextBox())->activate();
}

void VappBrowserAddPage::onFuncBarItemSelected(VfxObject *sender, VfxId id)
{
    onTBClick((VfxObject*)m_toolBar, ADD_PAGE_SAVE);
}

void VappBrowserAddPage::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case ADD_PAGE_SAVE:
        {
            m_titleInput->setWarningText((VFX_WSTR_RES(0)));
            VfxWString title = m_titleInput->getText();
            VfxWChar *titleBuffPtr = title.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
            if(!mmi_ucs2strlen((CHAR*)titleBuffPtr))
            {
                m_titleInput->setWarningText((VFX_WSTR_RES(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME)));
                return;
            }
			else
			{
				VfxBool is_Space = VFX_TRUE;
				while(*titleBuffPtr!='\0')
				{
					if(*titleBuffPtr != ' ')
					{
						is_Space = VFX_FALSE;
						break;
					}
					titleBuffPtr++;
				}
				if(is_Space)
				{
					m_titleInput->setWarningText((VFX_WSTR_RES(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME)));
                	return;
				}
			}
            VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
            m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
            m_popup->setAutoDestory(VFX_FALSE);
            m_popup->show(VFX_TRUE);
            srv_brw_act_req_struct obj = {0};
            srv_brw_stored_page_operation_req_struct data;
            ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_savePageCallback.connect(this , &VappBrowserAddPage::savePageCallback);
            obj.rsp_callback = &VappBrwServiceInterface::savePageHdlr;
            data.page_label = (U8*)titleBuffPtr;
            obj.req_data = (void*)&data;
            srv_brw_save_as_stored_page_req(&obj);
            break;
        }

        case ADD_PAGE_CANCEL:
            getMainScr()->popPage();
            break;

        default:
            break;
	}
}

void VappBrowserAddPage::savePageCallback(S32 userData, U32 result, void *data)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_savePageCallback.disconnect(this , &VappBrowserAddPage::savePageCallback);
    m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_popup);
    getMainScr()->closePage(BRW_PAGE_ADD_PAGE);
    if(result>0)
    {
        VappBrowserUtility::bamErrorHandler(result);
    }
    else
    {
        VappBrowserUtility::displayPopup(
            STR_ID_VAPP_BRW_PAGE_SAVED,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
			MMI_EVENT_INFO_BALLOON);
    }
}

void VappBrowserAddPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
	{
			
	}
	else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	}
}

void VappBrowserAddPage::onDeinit(void)
{
    VFX_OBJ_CLOSE(m_urlView);
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_titleCaption);
    VFX_OBJ_CLOSE(m_titleInput);
    VFX_OBJ_CLOSE(m_urlCaption);
    VFX_OBJ_CLOSE(m_urlInput);
    VFX_OBJ_CLOSE(m_form);
    VFX_OBJ_CLOSE(m_toolBar);
    VfxPage::onDeinit(); 
}
#endif

//VFX_IMPLEMENT_CLASS("VappWapListMenuPage", VappWapListMenuPage, VfxPage);

/***************************************************************************** 
 * class VappStaticListPage
 *****************************************************************************/

//Init method. Called when object is created for the class
void VappWapListMenuPage::onInit()
{	
	VfxPage::onInit(); // call base class
	
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_OPTIONS));
    setTopBar(titleBar); 
    //update toolbar
    VFX_OBJ_CREATE(m_tool_bar, VcpToolBar,this);
	m_tool_bar->m_signalButtonTap.connect(this, &VappWapListMenuPage::onWapListMenuToolBarClick);
	setBottomBar(m_tool_bar);
	m_tool_bar->addItem(BRW_LIST_TOOLBAR_BUTTON_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE),VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	m_tool_bar->addItem(BRW_LIST_TOOLBAR_BUTTON_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL),VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	
	m_list->setPos(0,0);
    VfxRect page_rect = getRect();
	m_list->setRect(0, 0, page_rect.size.width, page_rect.size.height);
    m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
	//m_updateStaticListSize();
    VFX_OBJ_CREATE(m_waplistcontentprovider, VappWapListMenucontentprovider, this);
	m_list->setContentProvider(m_waplistcontentprovider);
    if(m_listmenu_type == VAPP_BRW_CHOICE_MULTIPLE)
    {
		m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_FALSE); 
		m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        m_selectedListInfo = (VfxU8*)VappBrowserASMMemoryMgmt::allocMemory((VfxU32)widget_return_no_of_menu_items());
    }
    else if(m_listmenu_type == VAPP_BRW_CHOICE_EXCLUSIVE)
    {
        m_list->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_FALSE); 
		m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        m_selectedListInfo = NULL;
    }
   m_updateselecteditemsinfo();
	
	//m_updateStaticListStyle(); //update page style as per the page tye
	//m_updateContentProvider(); //associate a content provider
	//UpdateStaticListSelectedItems();
	
	//Event handler functions
    m_list->m_signalItemTapped.connect(this, &VappWapListMenuPage::m_signalListItemTapped);
	m_list->m_signalItemSelectionStateChanged.connect(this, &VappWapListMenuPage::m_signalListItemSelected);

	m_list->setVisibleMenuItem(m_index);
	m_shown = VFX_TRUE;
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	m_brwApp->isProcessingClosed = VFX_FALSE;
	//m_list->m_signalFocusChanged.connect(this, &VappStaticListPage::m_signalListFocusChanged);

}

//Return : Rotate type supported by the page, currently Landscape and Portrait

void VappWapListMenuPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
	{
		
	}
	else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	}
}

void VappWapListMenuPage::onDeinit()
{
	if(m_listmenu_type == VAPP_BRW_CHOICE_MULTIPLE)
    {
        widget_fullscreen_checkbox_menu_back();
    }
    else
    {
        widget_fullscreen_radio_menu_back();
    }
    if(m_selectedListInfo)
        VappBrowserASMMemoryMgmt::freeMemory(m_selectedListInfo);
    VFX_OBJ_CLOSE(m_list);
    VFX_OBJ_CLOSE(titleBar);
    VFX_OBJ_CLOSE(m_tool_bar);
    VfxPage::onDeinit(); 
}

void VappWapListMenuPage::m_updateselecteditemsinfo(void)
{
	if(m_listmenu_type == VAPP_BRW_CHOICE_MULTIPLE)
	{
		for (int index = 0; index < (int)widget_return_no_of_menu_items(); index++)
		{
			if((VfxBool)widget_checkbox_get_selection_state(index))
				m_selectedListInfo[index] = 1;
			else
				m_selectedListInfo[index] = 0;
		}
	}
	else
    {
        {
			m_index = widget_get_selected_radio_id();
		}
	}
}

void VappWapListMenuPage::onEnter(VfxBool isBackward)
{
    
}

void VappWapListMenuPage::onBack()
{
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	m_brwApp->isProcessingClosed = VFX_TRUE;
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
    VfxPage::onBack();
}

void VappWapListMenuPage::onWapListMenuToolBarClick(VfxObject* sender, VfxId id)
{
		switch(id)
		{
			case BRW_LIST_TOOLBAR_BUTTON_SAVE:
				{
					if(m_listmenu_type == VAPP_BRW_CHOICE_MULTIPLE)
					{
						widget_checkbox_reset_selection_state();
                        for (int index = 0; index < (int)widget_return_no_of_menu_items(); index++)
                        {
                            if(m_selectedListInfo[index] == 1)
                                widget_checkbox_set_selection_state(index, MMI_TRUE);
                            else
                                widget_checkbox_set_selection_state(index, MMI_FALSE);
                        }
                        widget_fullscreen_checkbox_menu_okay();
                    }
                    else
                    {
                        widget_set_item_radio_menu(m_index);
                        widget_fullscreen_radio_menu_okay();
                    }
                    getMainScr()->popPage();
					m_shown = VFX_FALSE;
                }
			   break;
			case BRW_LIST_TOOLBAR_BUTTON_CANCEL:
            {
				if(m_listmenu_type == VAPP_BRW_CHOICE_MULTIPLE)
                {
                    widget_fullscreen_checkbox_menu_back();
                }
                else
                {
                    widget_fullscreen_radio_menu_back();
                }
                getMainScr()->popPage();
				m_shown = VFX_FALSE;
            }
			    break;
		   default:
				break;
		}
}

void VappWapListMenuPage::m_signalListItemTapped(VcpListMenu *listmenu, VfxU32 id)
{
}
void VappWapListMenuPage::m_signalListItemSelected(VcpListMenu *listmenu, VfxU32 id, VcpListMenuItemStateEnum state)
{
	if(m_listmenu_type == VAPP_BRW_CHOICE_MULTIPLE)
	{
        if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            m_selectedListInfo[id] = 1;
        else
            m_selectedListInfo[id] = 0;
    }
    else
    {
        if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            m_index = id;
    }
}

VfxBool VappWapListMenucontentprovider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        ) 
{
	if(getCount()==0 || index >= getCount())
	{
		return VFX_FALSE;
	}
    VfxWString itemText;
	#if 0
/* under construction !*/
	#endif
    VfxWChar *itemTextBuff = text.lockBuf(128);
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    vappBrwListMenuChoiceEnum list_type = m_brwApp->scr->m_waplistmenu->m_listmenu_type;    
    if(list_type == VAPP_BRW_CHOICE_MULTIPLE)
    {
        widget_fullscreen_checkbox_menu_get_item_hdlr((S32)index, (UI_string_type)itemTextBuff);
    }
    else
    {
        widget_fullscreen_radio_menu_get_item_hdlr((S32)index, (UI_string_type)itemTextBuff, NULL, 0);
    }
    text.unlockBuf();
	return VFX_TRUE;
}

VcpListMenuItemStateEnum VappWapListMenucontentprovider::getItemState(VfxU32 index) const
{
	if(getCount() == 0 || index >= getCount())
	{
		return VCP_LIST_MENU_ITEM_STATE_NONE;
	}
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    vappBrwListMenuChoiceEnum list_type = m_brwApp->scr->m_waplistmenu->m_listmenu_type;    
    if(list_type == VAPP_BRW_CHOICE_MULTIPLE)
    {
        if((VfxBool)widget_checkbox_get_selection_state(index))
        {
			m_brwApp->scr->m_waplistmenu->m_list->setVisibleMenuItem(index, VFX_TRUE);
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
    else
    {
        if((VfxBool)(index == widget_get_selected_radio_id()))
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
}

VfxBool VappWapListMenucontentprovider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
{
		return VFX_FALSE;
}

VfxU32 VappWapListMenucontentprovider::getCount()const
	{
		VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    	VfxBool is_shown = m_brwApp->scr->m_waplistmenu->m_shown;   
		if(is_shown == VFX_TRUE && m_brwApp->isProcessingClosed == VFX_FALSE)
		{
		return (VfxU32)widget_return_no_of_menu_items();
		}else
		{
			return 0;
		}
		
	} 

VappBrowserTextAreaInputPopup::VappBrowserTextAreaInputPopup()
{
	//m_textAreaContent =  (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory(m_length);
    //memset(m_textAreaContent, 0, m_length);
    //mmi_ucs2ncpy((CHAR*) m_textAreaContent, (CHAR*) m_Content , m_length);
    m_textAreaContent = NULL;
	m_contectlength = 0;
}

VappBrowserTextAreaInputPopup::~VappBrowserTextAreaInputPopup()
{
	//if(m_textAreaContent)
    //{
    //    VappBrowserASMMemoryMgmt::freeMemory(m_textAreaContent);
    //    m_textAreaContent = NULL;
    //}
}

void VappBrowserTextAreaInputPopup::showCommandPopup()
{

}

void VappBrowserTextAreaInputPopup::onUpdate()
{
	VfxS32 i = 0;
    VfxS32 xPos = VCP_INPUT_POPUP_LR_GAP;
    VfxS32 yPos = VCP_INPUT_POPUP_TITLE_Y + VCP_INPUT_POPUP_TITLE_HEIGHT + VCP_INPUT_POPUP_TD_GAP;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
	VfxS32 multiple = 18;

    VfxS32 popupWidth;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        popupWidth = VCP_INPUT_POPUP_WIDTH;
    }
    else
    {
        popupWidth = VCP_INPUT_POPUP_LANDSCAPE_WIDTH;
    }
    VfxS32 contentWidth = (popupWidth - 2 * VCP_INPUT_POPUP_LR_GAP);

    // resize title
    m_titleBg->setSize(popupWidth, VCP_INPUT_POPUP_TITLE_HEIGHT);
    m_titleFrame->setSize(popupWidth, VCP_INPUT_POPUP_TITLE_HEIGHT);

    // disable ok button if inputbox is empty
	//setOkBtnState();
    // set group element pos (hint text, inputbox, error text)
    for (i = 0; i < m_groupNum; i++)
    {
        // show hint text only when more than one group
        if (m_groupNum > 1)
        {
            if (!m_hintText[i].isEmpty())
            {
                if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
                {
                    m_hintTextFrame[i]->setMaxLines(VCP_INPUT_POPUP_HINT_TEXT_MAX_LINE);
                }
                else
                {
                    // only display one line in landscape mode
                    m_hintTextFrame[i]->setMaxLines(1);
                }
                m_hintTextFrame[i]->setSize(contentWidth, 0);
                m_hintTextFrame[i]->setPos(xPos, yPos);
                yPos += (m_hintTextFrame[i]->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
            }
            else
            {
                VFX_OBJ_CLOSE(m_hintTextFrame[i]);
            }
        }
        else
        {
            VFX_OBJ_CLOSE(m_hintTextFrame[i]);
        }
        m_inputbox[i]->setPos(xPos, yPos);
        m_inputbox[i]->setSize(contentWidth, VCP_INPUT_POPUP_INPUTBOX_HEIGHT + multiple);
        yPos += (VCP_INPUT_POPUP_INPUTBOX_HEIGHT + multiple + VCP_INPUT_POPUP_TD_GAP);
        if (!m_errorText[i].isEmpty())
        {
            if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
            {
                m_errorTextFrame[i]->setMaxLines(VCP_INPUT_POPUP_ERROR_TEXT_MAX_LINE);
            }
            else
            {
                // only display one line in landscape mode
                m_errorTextFrame[i]->setMaxLines(1);
            }
            m_errorTextFrame[i]->setPos(xPos, yPos);
            m_errorTextFrame[i]->setSize(contentWidth, 0);
            yPos += (m_errorTextFrame[i]->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
        }
    }

    // set button pos
    VfxS32 buttonWidth = ((contentWidth - VCP_INPUT_POPUP_BUTTON_GAP) / 2);

    m_okButton->setInnerRect(VfxRect(
        VCP_INPUT_POPUP_LR_GAP,
        yPos,
        buttonWidth,
        VCP_INPUT_POPUP_BUTTON_HEIGHT));
    m_cancelButton->setInnerRect(VfxRect(
        VCP_INPUT_POPUP_LR_GAP + buttonWidth + VCP_INPUT_POPUP_BUTTON_GAP,
        yPos,
        buttonWidth,
        VCP_INPUT_POPUP_BUTTON_HEIGHT));

    yPos += VCP_INPUT_POPUP_BUTTON_HEIGHT + VCP_INPUT_POPUP_BOTTOM_GAP;

    // set background bounds
    m_background->setBounds(0, 0, popupWidth, yPos - VCP_INPUT_POPUP_TITLE_HEIGHT);

    // set Popup bounds
    setBounds(0, 0, popupWidth, yPos);
}

//#pragma arm section code, rodata

#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_MAIN_CPP_ */
