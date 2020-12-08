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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_usb_normalmode.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#ifdef __USB_MMI_DEBUG__
#ifndef __MTK_TARGET__
#ifndef __MMI_USB_SUPPORT__
#define __MMI_USB_SUPPORT__
#endif
#endif
#endif

#include "MMI_features.h" 
     
     
#if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#include "mmi_include.h"
#include "notificationgprot.h"
#include "bootupsrvgprot.h"
#include "shutdownsrvgprot.h"
#include "FileMgrSrvGProt.h"
#include "ucmsrvgprot.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif
#include "AlarmFrameworkProt.h"
#include "NwUsabSrvGprot.h"
#include "wap_adp.h"
#include "mma_api.h"
#include "GlobalResDef.h"
#include "CharBatSrvGProt.h"
#include "USBSrvIprot.h"
#include "usbsrvgprot.h"
#include "wgui.h"
#ifdef __USB_TETHERING__
#include "TetheringSrvGProt.h"
#endif
}
#endif
#include "vapp_usb_gprot.h"
#include "Vapp_usb_normalmode.h"
#include "Vcp_global_popup.h"
#include "vcp_status_icon_bar.h"
#include "vapp_nmgr_gprot.h"
#include "../xml/vfx_xml_loader.h"
#include "mmi_rp_vapp_usbmmi_def.h"
#include "vfx_mmi.h"

//extern "C" void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate);
#ifdef __MMI_WEBCAM__
extern "C" void mmi_webcam_enter(void);
extern "C" void mmi_webcam_exit(void);

#endif
#ifdef __USB_TETHERING__
extern void usbTetheringLaunch();
#endif
#define VAPP_USB_CMD_POPUP_INVALID_ID   0xffff
#define USB_EXIT_MS_PROGRESS_TIMER_DUR  500

 
VfxS32 VappUSBNormalModeContext::m_staticConfirm = 0;

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" MMI_BOOL nmgrNotifyCallback(mmi_scenario_id scen_id, void *arg)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_NMGRNOTIFYCALLBACK);
    return (MMI_BOOL)VappUSBNormalModeContext::preShowCfgListNotify();
}

extern "C" void vapp_usb_unavailable_popup(VfxResId str)
{
    if (str)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_INFO, 
            VFX_WSTR_RES(str));
    }
    else
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_INFO, 
            VFX_WSTR_RES(vapp_usb_get_error_info(0, NULL)));
    }
}

extern "C" VfxResId vapp_usb_get_error_info(VfxS32 error, VcpPopupTypeEnum *popupType)
{
    if (popupType)
    *popupType = VCP_POPUP_TYPE_INFO;
#ifdef  __MTP_ENABLE__
    if (srv_usb_get_owner() == SRV_USB_MS_STORAGE_MTP)
        return STR_ID_VAPP_USB_NOT_AVAILABLE_IN_MTP_MODE;
#endif
    return STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
}

VappUSBNormalModeContext* VappUSBNormalModeContext::m_inst = NULL;
VcpPopupTypeEnum VappUSBNormalModeContext::m_globalPopupType = VCP_POPUP_TYPE_FAILURE;
VfxResId VappUSBNormalModeContext::m_globalPopupString = 0;
    
void VappUSBNormalModeContext::preShowCfgList(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_PRESHOWCFGLIST);
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_NON_TONE, 
        nmgrNotifyCallback, NULL);
}

VfxBool VappUSBNormalModeContext::preShowCfgListNotify(void)
{
    srv_usb_status_enum usb_state = srv_usb_get_status();

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_PRESHOWCFGLISTNOTIFY);
    
    if (usb_state == SRV_USBSTATUS_PLUGIN ||
        (usb_state == SRV_USBSTATUS_PLUGIN && srv_usb_is_connected())
    #ifdef __USB_IN_NORMAL_MODE__
        || srv_usb_is_leaving_ms_mode()
    #endif
       )
    {
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_NOT_CONTINUE_SHOW_USB_CFG);
        return VFX_FALSE;
    }

    if ((srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL &&
          !srv_bootup_is_booting()) ||
          mmiPermitCheck())
    {
        if (VappUSBNormalModeContext::m_inst)
        {
            VappUSBNormalModeContext::m_inst->createScreen();
        }
        srv_usb_unblock_event(EVT_ID_USB_PERMIT_CFG);
        return VFX_TRUE;
    }
    else
    {
        srv_usb_block_event(EVT_ID_USB_PERMIT_CFG);
        return VFX_FALSE;
    }
}

void VappUSBNormalModeContext::createScreen(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CREATESCREEN);
    if (!m_screen)
    {
        VFX_OBJ_CREATE(m_screen, VappUSBNormalModeScrn, getParent());
        m_screen->m_confirmCloseSignal.connect(this, &VappUSBNormalModeContext::confirmCloseHdlr);
        m_screen->m_cfgListSelectSignal.connect(this, &VappUSBNormalModeContext::onCommandPopupClick);
        m_screen->m_screenClosedSignal.connect(this, &VappUSBNormalModeContext::onScreenClosed);
        m_screen->show();
    }
}

void VappUSBNormalModeContext::closeScreen(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CLOSESCREEN);
    if (m_screen)
    {
        m_screen->exit();
        m_screen = NULL;
    }
}

void VappUSBNormalModeContext::preShowCfgListCheck(void)
{
    VfxBool ret;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_PRESHOWCFGLISTCHECK);

    ret = mmiPermitCheck();
    if (ret)
    {
        srv_usb_unblock_event(EVT_ID_USB_PERMIT_CFG_PRE_CHECK);
    }
    else
    {
        srv_usb_block_event(EVT_ID_USB_PERMIT_CFG_PRE_CHECK);
    }
}

VfxBool VappUSBNormalModeContext::mmiPermitCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_MMIPERMITCHECK);
    
    if (!srv_bootup_is_completed() || 
        srv_fmgr_async_is_busy() ||
        //mmi_phb_check_processing()==MMI_TRUE ||
        //mmi_secset_is_in_puk_check() ||                 /* PUK needed after SIM lock failed or change PIN1 failed */
#ifdef __MMI_DUAL_SIM_MASTER__
        //mmi_secset_is_in_sim2_puk_check() ||
#endif    	
    #if defined(__DM_LAWMO_SUPPORT__)
        ((kal_int8)mmi_dmui_is_phone_lock()!=0) ||
        mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING ||
    #endif
        srv_shutdown_is_running()) 
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_CONF_SCR_NOT_ALLOW_FALSE);
        return VFX_FALSE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_CONF_SCR_NOT_ALLOW_TURE);
        return VFX_TRUE;
    }
}

void VappUSBNormalModeContext::showCfgList(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_SHOWCFGLIST);
    if (m_screen)
    {
        m_screen->showCfgList();
        m_screen->setContext(this);
		srv_usb_set_status(SRV_USBSTATUS_CONF_PAGE);
    }
}

void VappUSBNormalModeContext::closeCfgList(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CLOSECFGLIST);
    if (m_screen)
    {
        m_screen->closeCfgList();
    }
}
void VappUSBNormalModeScrn::onCancelClick(VfxObject* sender, VfxFloat id)
{
	MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRC_CANCLECLICK);

	 m_cfgListSelectSignal.emit(ITEM_ID_MAX_CANCEL); 
	 if(timer)
	 {
	    VFX_OBJ_CLOSE(timer);
	 }
}
void VappUSBNormalModeScrn::onExitProgress(VfxTimer* timer)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_IS_MS_EXIT_JUGE, srv_usb_is_ms_exit_done());
    if (MMI_TRUE == srv_usb_is_ms_exit_done())
    {
        my_progress->exit(MMI_TRUE);
	    my_progress = NULL;
	    srv_usb_set_status(SRV_USBSTATUS_PLUGIN);
        showMSConfirm(m_msSelId);
    }
    else
    {
		timer->start();
    }
}
void VappUSBNormalModeContext::onCommandPopupClick(VfxId id)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_ONCOMMANDPOPUPCLICK, id);
    
#ifdef __DM_LAWMO_SUPPORT__
    if (srv_usb_is_dm_lock())
    {
        showPopup(SELECT_INVALID);
        return;
    }
#endif

    if ( (srv_usb_get_status() == SRV_USBSTATUS_PLUGOUT))
	{
        if (id != VAPP_USB_CMD_POPUP_INVALID_ID)
            showPopup(SELECT_INVALID);
		closeCfgList();
		return;
	}
    switch(id)
    {
    #ifdef __USB_MASS_STORAGE_ENABLE__
        case ITEM_ID_MS:
            srv_usb_set_owner(SRV_USB_MS_STORAGE_MS);
            configMSMTP(DEVUSB_CFG_ACTION_MASS_STORAGE);
            break;
    #endif

    #ifdef __USB_COM_PORT_ENABLE__
        case ITEM_ID_COM:
            srv_usb_set_owner(SRV_USB_COMPORT_PS);
    		configCOM();
            break;
    #endif

    #ifdef __MMI_WEBCAM__
        case ITEM_ID_WEBCAM:
            configWebcam();
            break;
    #endif

    #if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__)
        case ITEM_ID_JAVA:
            srv_usb_set_owner(SRV_USB_COMPORT_JAVA);
            configCOM();
            break;
    #endif

    #ifdef  __MTP_ENABLE__
        case ITEM_ID_MTP:
            srv_usb_set_owner(SRV_USB_MS_STORAGE_MTP);
            configMSMTP(DEVUSB_CFG_ACTION_MTP);
            break;
    #endif

    #ifdef __MMI_PICT_BRIDGE_SUPPORT__
        case ITEM_ID_PICTBRIDGE:
            srv_usb_set_status(SRV_USBSTATUS_PICTBRIGE);
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_PICTBRIGE);      
            //closeCfgList();
            closeScreen();
            break;
    #endif

        case ITEM_ID_USBTETHERING:
            
        #ifdef __USB_TETHERING__
            if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
            {
                showPopup(CURRENTLY_INVALID);
                return;
            }
			srv_usb_set_status(SRV_USBSTATUS_USBTETHERING);
            usbTetheringLaunch();
        #endif
            closeScreen();
            break;
            
        case ITEM_ID_MAX_CANCEL:
            if (m_screen)
                m_screen->resetCfgList();
            closeScreen();
            srv_usb_set_status(SRV_USBSTATUS_IGNORED);
            break;
            
        default:
			if (m_screen)
                m_screen->resetCfgList();
            closeScreen();
            srv_usb_set_status(SRV_USBSTATUS_IGNORED);
            return;
    }
}

void VappUSBNormalModeContext::configMSMTP(devusb_cfg_action_enum action)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CONFIGMSMTP);

#ifdef __USB_TETHERING__
    if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
    {
        showPopup(CURRENTLY_INVALID);
        return;
    }
#endif

#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
    if (!srv_usb_is_any_exported_drive())
    {
        showPopup(NO_MS_FOR_PC);
        srv_usb_set_status(SRV_USBSTATUS_IGNORED);
        return;
    }
#endif /* defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)*/

    if (!needReboot())
    {
        if (!wapSysRead())
        {
            showPopup(SYS_NOT_READY);
            srv_usb_set_status(SRV_USBSTATUS_IGNORED);
	}
        else
        {
            srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
			#ifdef __USB_IN_NORMAL_MODE__
            srv_usb_enter_ms_proc();
			#endif
        }
    }
    else
    {
        if ((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_USB) || 
            (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM) ||
            (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_CHARGE))
        {
            srv_usb_start_ms_shutdown();
            srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
            m_screenClosedSignal.emit();
        }
        else
        {
            /* USB split revise*/
            srv_usb_send_config_to_hw(action);
            srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
            m_screenClosedSignal.emit();
        }
    }      
}

VfxBool VappUSBNormalModeContext::needReboot(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_NEEDREBOOT);
    
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool VappUSBNormalModeContext::wapSysRead(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_WAPSYSREAD);
#ifdef WAP_SUPPORT
	if (srv_nw_usab_is_any_network_available())
	{
		if (!wap_is_ready())
		{							
			return VFX_FALSE;
		}
	}
#endif
	
#ifdef MMS_SUPPORT
	if (srv_nw_usab_is_any_network_available())
	{
		if (!mma_is_ready_for_usb())
		{
			return VFX_FALSE;
		}
	}
#endif /* MMS_SUPPORT */

    return VFX_TRUE;
}



void VappUSBNormalModeContext::showProgress(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_SHOWPROGRESS);
    if (m_screen)
    {
        m_screen->showProgress();
    }
}

void VappUSBNormalModeContext::closeProgress(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CLOSEPROGRESS);
    if (m_screen)
    {
        m_screen->closeProgress();
    }
}

void VappUSBNormalModeContext::showPopup(PopupTypeEnum type)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_SHOWPOPUP);
    switch(type)
    {
        case MS_SUCCESS:
        case MTP_SUCCESS:
        case COM_SUCCESS:
        case JAVA_SUCCESS:
        case CFG_SUCCESS:
        case PICTBRIDGE_SUCCESS:
            showInfoBollon(type);
            return;;
            
        default:
            break;
    }
    createScreen();
    m_screen->showPopup(type);
}

void VappUSBNormalModeContext::showInfoBollon(PopupTypeEnum type)
{
    VfxWString popupString;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_SHOWINFOBOLLON);
	#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)||defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) ||defined(__MMI_IME_MEMORY_CARD_SUPPORT__) ||defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
    if (type == MS_SUCCESS || type == MS_SUCCESS)
    {
        return;
    }
	#endif
#if 1
    switch(type)
    {
        case MS_SUCCESS:
            popupString = VFX_WSTR_RES(STR_ID_VAPP_USB_CONFIG_MS);
            break;
            
        case MTP_SUCCESS:
            popupString = VFX_WSTR_RES(STR_ID_VAPP_USB_CONFIG_MTP);
            break;
            
        case COM_SUCCESS:
            popupString = VFX_WSTR_RES(STR_ID_VAPP_USB_COM);
            break;
            
        case JAVA_SUCCESS:
            popupString = VFX_WSTR_RES(STR_ID_VAPP_USB_CONFIG_COMPORT_JAVA);
            break;
            
        case PICTBRIDGE_SUCCESS:
            popupString = VFX_WSTR_EMPTY;
            break;
            
        default:
            popupString = VFX_WSTR_EMPTY;
            break;
    }

    popupString += VFX_WSTR_RES(STR_ID_VAPP_USB_CONNECT_SUCCESS);
    
#endif
	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
	   	  MMI_EVENT_INFO_BALLOON, 
	   	  MMI_NMGR_BALLOON_TYPE_SUCCESS, 
	   	  (WCHAR*)popupString.getBuf());

   
}

void VappUSBNormalModeContext::showStaticComfirm(PopupTypeEnum type)
{    
    m_staticConfirm = vapp_nmgr_global_popup_show_confirm_one_button_id(MMI_SCENARIO_ID_DEFAULT,
        VCP_POPUP_TYPE_FAILURE,
        STR_ID_VAPP_USB_CONNECT_FAIL,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        &VappUSBNormalModeContext::staticConfirmCallback,
        NULL);
/*
    switch(type)
    {
        default:
            m_globalPopupType = VCP_POPUP_TYPE_FAILURE;
            m_globalPopupString = STR_ID_VAPP_USB_CONNECT_FAIL;
            break;
    }

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, vapp_usb_global_popup_nmgr_callback, NULL);
*/
}

void VappUSBNormalModeContext::closeStaticComfirm(void)
{
	if (m_staticConfirm)
	{
		vapp_nmgr_global_popup_cancel(m_staticConfirm);
		m_staticConfirm = 0;
	}
}

void VappUSBNormalModeContext::staticConfirmCallback(VfxId id, void *usrData)
{
	m_staticConfirm = 0;
}

void VappUSBNormalModeContext::configCOM(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CONFIGCOM);

#ifdef __USB_TETHERING__
    if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
    {
        showPopup(CURRENTLY_INVALID);
        return;
    }
#endif

    //nvram_get_ps(&ps_port, &ps_baudrate);

    if (srv_usb_get_ps_port() == uart_port_null)
    {
        //mmi_usb_display_popup(STR_ID_USB_UART2_OCCUPIED, MMI_EVENT_FAILURE);
        showPopup(COM_OCCUPIED);
        closeCfgList();
        return;
    }

    //closeCfgList();

    /* avoid entry UART setting screen */
   #ifdef __MMI_ENGINEER_MODE__
//	   DeleteScreenIfPresent(EM_DEV_INLINE_CONFIG_UART_MENU_SCR);
//	   DeleteScreenIfPresent(EM_DEV_SET_UART_MENU_SCR);
   #endif /* __MMI_ENGINEER_MODE__ */ 

    srv_usb_set_status(SRV_USBSTATUS_CDCACM_PROC);
    //showProgress();

#ifdef __MMI_USB_MULTIPLE_COMPORT_SUPPORT__
    #if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__)
        if (srv_usb_get_owner() == SRV_USB_COMPORT_JAVA)
        {
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_CDC_ACM);
        }
        else
    #endif
        srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_MULTI_COM);
#else
        srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_CDC_ACM);
#endif
        m_screenClosedSignal.emit();
}

void VappUSBNormalModeContext::configWebcam(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CONFIGWEBCAM);

#ifdef __USB_TETHERING__
    if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
    {
        showPopup(CURRENTLY_INVALID);
        return;
    }
#endif
    if (srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        //mmi_usb_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE);
        showPopup(INVALID_DURING_CALL);
        closeCfgList();
        return;
    }
#ifdef __MMI_WEBCAM__
    mmi_webcam_enter();
#endif
    srv_usb_set_status(SRV_USBSTATUS_WEBCAM);
    closeScreen();
}

void VappUSBNormalModeContext::usbCfgRspHdlr(VfxU8 mode, VfxBool result)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_USBCFGRSPHDLR);
    
	if (!result && (mode != DEVUSB_CFG_ACTION_WEBCAM))
	{
	    showPopup(MS_FAIL);
	    closeProgress();           
        closeCfgList();
	    return;
	}
	
    switch (mode)
    {
        case DEVUSB_CFG_ACTION_MASS_STORAGE:
    #ifdef __MTP_ENABLE__			
        case DEVUSB_CFG_ACTION_MTP:
    #endif
	#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)||defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) ||defined(__MMI_IME_MEMORY_CARD_SUPPORT__) ||defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
			srv_usb_start_ms_shutdown();
			 break;
    #endif
            if (!srv_usb_is_any_exported_drive())
            {
                showPopup(NO_MS_FOR_PC);
            }
            closeProgress();
            closeCfgList();
			closeScreen();
            break;

	#ifdef __MMI_PICT_BRIDGE_SUPPORT__
        case DEVUSB_CFG_ACTION_PICTBRIGE: /* PictBrige */
            showPopup(PICTBRIDGE_SUCCESS);
            closeProgress();
            closeCfgList();
            closeScreen();
            break;
    #endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

        case DEVUSB_CFG_ACTION_WEBCAM:
            closeScreen();
            break;
            
        default:
            showPopup(CFG_SUCCESS);
            closeProgress();
            closeScreen();
            break;
    }
}

void VappUSBNormalModeContext::confirmCloseHdlr(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_CONFIRMCLOSEHDLR);
    closeScreen();
}

void VappUSBNormalModeContext::onScreenClosed(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_ONSCREENCLOSED);
    m_screenClosedSignal.postEmit();
}

void VappUSBNormalModeContext::exitWebCam(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODECONTEXT_EXITWEBCAM);
#ifdef __MMI_WEBCAM__
    mmi_webcam_exit();
#endif
}


VfxBool VappUSBCommandPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK)
    {
        m_byBackKey = VFX_TRUE;
    }
    else
    {
        m_byBackKey = VFX_FALSE;
    }

    return VcpCommandPopup::onKeyInput(event);
}

VfxBool VappUSBCommandPopup::isByBackKey(void)
{
    return m_byBackKey;
}

VfxS32 VappUSBNormalModeScrn::m_sUsbCheckFialPopId = 0;
VFX_IMPLEMENT_CLASS("VappUSBNormalModeScrn", VappUSBNormalModeScrn, VfxAppScr); //VfxMainScr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappUSBNormalModeScrn::onInit()
{
    

    VfxAppScr::onInit();
    m_statusBar = NULL;
    
}

void VappUSBNormalModeScrn::onBeforeDeinit()
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_ONBEFOREDEINIT);
    VfxAppScr::onBeforeDeinit();
    m_screenClosedSignal.emit();
}

void VappUSBNormalModeScrn::onEnter(VfxBool back)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_ONENTER, back, m_bShowCfgList);

    VfxAppScr::onEnter(back);
    if(m_statusBar == NULL)
    {
     VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
     m_statusBar->setAutoAnimate(VFX_TRUE);
     m_statusBar->setPos(0, 0);
     m_statusBar->bringToFront();
	}
	
    if (back && (srv_usb_get_status()==SRV_USBSTATUS_CONF_PAGE) && m_bShowCfgList)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_SHOW_CFG_AGAIN);
		if (m_cfgList)
		{
            m_cfgList->m_signalButtonClicked.connect(this, &VappUSBNormalModeScrn::onCommandPopupClick);
		}
    }
}

void VappUSBNormalModeScrn::onQueryRotateEx(VfxScreenRotateParam &param)
{
   param.durTime = 0; 
}


void VappUSBNormalModeScrn::onRotate(const VfxScreenRotateParam & param)
{
	VfxAppScr::onRotate(param);
	
	if (m_statusBar != NULL)
	{
		m_statusBar->setSize(getSize().width, MMI_STATUS_BAR_HEIGHT);
	}
}


void VappUSBNormalModeScrn::showCfgList(void)
{
    VfxRenderer *render = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_SHOWCFGLIST);

    m_bShowCfgList = VFX_TRUE;

    if (!m_cfgList)
    {
        VFX_OBJ_CREATE(m_cfgList, VappUSBCommandPopup, this);
        m_cfgList->setAutoDestory(VFX_FALSE);
        m_cfgList->setText(STR_ID_VAPP_USB_CONFIG_TITLE);
    
        VfxS32 count = sizeof(m_listItem) / sizeof(m_listItem[0]);
        VfxS32 i;

        for(i = 0; i < count - 1; i++)
        {
            m_cfgList->addItem(m_listItem[i].id, 
                VFX_WSTR_RES(m_listItem[i].string),
                VCP_POPUP_BUTTON_TYPE_NORMAL);
        }
        m_cfgList->addItem(m_listItem[i].id, 
                VFX_WSTR_RES(m_listItem[i].string),
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    }
    m_cfgList->m_signalButtonClicked.connect(this, &VappUSBNormalModeScrn::onCommandPopupClick);
    m_cfgList->show(VFX_TRUE);
}

void VappUSBNormalModeScrn::closeCfgList(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_CLOSECFGLIST);
    if (m_cfgList)
    {
        m_cfgList->m_signalButtonClicked.disconnect(this, &VappUSBNormalModeScrn::onCommandPopupClick);
        m_cfgList->exit(VFX_FALSE);
        m_cfgList = NULL;
        m_bShowCfgList = VFX_FALSE;
    }
}

void VappUSBNormalModeScrn::resetCfgList(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_RESETCFGLIST);
    m_cfgList = NULL;
}

void VappUSBNormalModeScrn::setContext(VfxObject *context)
{
    m_context = context;
}

void VappUSBNormalModeScrn::showProgress(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_SHOWPROGRESS);
    if (!m_progress)
    {
        VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, this);

        m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS);
        m_progress->setText(STR_ID_VAPP_USB_CONNECTING);
        m_progress->setAutoDestory(VFX_FALSE);
    }
    m_progress->show(VFX_TRUE);
}

void VappUSBNormalModeScrn::closeProgress(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_CLOSEPROGRESS);
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
        m_progress = NULL;
    }
}

void VappUSBNormalModeScrn::showPopup(PopupTypeEnum type)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_SHOWPOPUP, type);
    switch(type)
    {
        case MS_SUCCESS:
        case MTP_SUCCESS:
        case COM_SUCCESS:
        case JAVA_SUCCESS:
        case CFG_SUCCESS:
        case PICTBRIDGE_SUCCESS:
            showInfoBollon(type);
            m_confirmCloseSignal.emit();
            break;
            
        case MS_FAIL:
        case MTP_FAIL:
        case COM_FAIL:
        case JAVA_FAIL:
        case SELECT_INVALID:
        case CFG_FAIL:
        case INVALID_DURING_CALL:
        case CURRENTLY_INVALID:
        case NO_MS_FOR_PC:
        case SYS_NOT_READY:
        case COM_OCCUPIED:
            showConfirmPopup(type);
            break;
            
        default:
            return;
    }
}

void VappUSBNormalModeScrn::showInfoBollon(PopupTypeEnum type)
{
}

void VappUSBNormalModeScrn::showConfirmPopup(PopupTypeEnum type)
{
     
    VfxResId str;
    
     

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_SHOWCONFIRMPOPUP);
    
    switch(type)
    {
        case INVALID_DURING_CALL:
            str = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
            break;

        case CURRENTLY_INVALID:
            str = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
            break;
            
        case MS_FAIL:
        case MTP_FAIL:
        case COM_FAIL:
        case JAVA_FAIL:
        case SELECT_INVALID:
        case CFG_FAIL:
        case NO_MS_FOR_PC:
        case SYS_NOT_READY:
        case COM_OCCUPIED:
            str = STR_ID_VAPP_USB_CONNECT_FAIL;
            break;
            
        default:
            return;
    }
    
	m_confirmCloseSignal.emit();
    m_sUsbCheckFialPopId = vapp_nmgr_global_popup_show_confirm_one_button_id(
				MMI_SCENARIO_ID_DEFAULT,
				VCP_POPUP_TYPE_WARNING,
				str,
				STR_GLOBAL_OK,
				VCP_POPUP_BUTTON_TYPE_NORMAL,
				&VappUSBNormalModeScrn::failPopConfirmCallback,
				NULL);
	
    
    
}

void VappUSBNormalModeScrn::closeFailPopComfirm(void)
{
    if (m_sUsbCheckFialPopId)
    {
        vapp_nmgr_global_popup_cancel(m_sUsbCheckFialPopId);
        m_sUsbCheckFialPopId = 0;
    }
}

void VappUSBNormalModeScrn::failPopConfirmCallback(VfxId id, void *usrData)
{
    m_sUsbCheckFialPopId = 0;
}

void VappUSBNormalModeScrn::showMSConfirm(ItemIdEnum itemId)
{
    VcpConfirmPopup *confirm;

    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
	MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_SHOWMSCONFIRM,itemId);
	#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)||defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) ||defined(__MMI_IME_MEMORY_CARD_SUPPORT__) ||defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
			confirm->setText(STR_ID_VAPP_USB_MS_SHUT_DOWN_CONFIRM);
#else

    if (itemId == ITEM_ID_MS)
    {
        confirm->setText(STR_ID_VAPP_USB_MS_CONFIRM);
    }
    else if (itemId == ITEM_ID_MTP)
    {
        confirm->setText(STR_ID_VAPP_USB_MTP_CONFIRM);
    }
#endif
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirm->setCustomButton(STR_ID_VAPP_USB_CONTINUE , 
        STR_GLOBAL_CANCEL, 
        VCP_POPUP_BUTTON_TYPE_NORMAL, 
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    
    confirm->m_signalButtonClicked.connect(this, &VappUSBNormalModeScrn::onMSConfirmClick);
    confirm->show(VFX_TRUE);
}

 

void VappUSBNormalModeScrn::onMSConfirmClick(VfxObject* obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_ONMSCONFIRMCLICK, id);
    
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VCP_CONFIRM_POPUP_BUTTON_USER_1);
        if (m_msSelId == ITEM_ID_MS ||
            m_msSelId == ITEM_ID_MTP)
            m_cfgListSelectSignal.emit(m_msSelId);
        else
            VFX_ASSERT(0);
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_ITEM_ID_MAX_CANCEL);
        m_cfgListSelectSignal.emit(ITEM_ID_MAX_CANCEL);
    }
}

void VappUSBNormalModeScrn::onCommandPopupClick(VfxObject * obj, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBNORMALMODESCRN_ONCOMMANDPOPUPCLICK, id);

    /* It is covered or press Back key*/
    if (id == VAPP_USB_CMD_POPUP_INVALID_ID)
    {
        if (m_cfgList)
        {
            if (m_cfgList->isByBackKey()) /* Press Back key, handle it as Cancel*/
            {
                m_cfgListSelectSignal.emit(ITEM_ID_MAX_CANCEL);
            }
            else /* It is covered, re-connect in onEnter*/
            {
                m_cfgList->m_signalButtonClicked.disconnect(this, &VappUSBNormalModeScrn::onCommandPopupClick);
                //m_cfgList = NULL;
            }
        }
        return;
    }

    if (id == ITEM_ID_MS ||
        id == ITEM_ID_MTP)
    {
		m_msSelId = (ItemIdEnum)id;
		MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_IS_MS_EXIT_JUGE, srv_usb_is_ms_exit_done());

		if (MMI_TRUE == srv_usb_is_ms_exit_done())
		{
			showMSConfirm((ItemIdEnum)id); 
		}
		else
		{
			VFX_OBJ_CREATE(my_progress, VcpIndicatorPopup, this);
		
			my_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
			my_progress->setText(STR_ID_VAPP_USB_WAIT_CONFIG_MS);
			my_progress->setProgress(1.0f);
			my_progress->setIsAnimate(VFX_FALSE);
			my_progress->show(VFX_TRUE);
			my_progress->m_signalCanceled.connect(this, &VappUSBNormalModeScrn::onCancelClick);
					   
		    VFX_OBJ_CREATE(timer, VfxTimer, this);
		    timer->setStartDelay(USB_EXIT_MS_PROGRESS_TIMER_DUR);
		    timer->m_signalTick.connect(this, &VappUSBNormalModeScrn::onExitProgress);
		    timer->start();
		   
		}
        return;
    }
    m_cfgListSelectSignal.emit(id);
}


 

#endif
