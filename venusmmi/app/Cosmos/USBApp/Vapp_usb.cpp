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
 *  vapp_usb_basecontext.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
//#include "mmi_include.h"
#ifdef __cplusplus
extern "C"
{
#include "MMIDataType.h"
#include "GpioSrvGprot.h"
#include "CharBatSrvGProt.h"
#include "gpiosrvgprot.h"
#include "bootupsrvgprot.h"
#include "FileMgrSrvGProt.h"
#include "shutdownsrvgprot.h"
#include "notificationgprot.h"
#include "wgui_categories_util.h"
#include "USBSrvIprot.h"
#include "USBSrvGProt.h"
#include "PenCalibrationSrvGprot.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "DMSrvGprot.h"
#endif
}
#endif

#include "vcp_form.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_usb.h"
#include "..\Calendar\vapp_cal_reminder.h"
#include "..\screenlock\vapp_screen_lock_main.h"
#include "..\clock\alarm\vapp_alarm_indication.h"
#include "vfx_app_launcher.h"
#include "..\..\common\platform\vapp_platform_context.h"


#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static mmi_id gAppInst;
static VfxBool gIsUnlocked;
static PopupTypeEnum gCfgSuccessPopType;
power_on_status_enum VappUSBApp::m_powerOnMode = POWER_ON_UNINIT;//POWER_ON_KEYPAD;
usbAppBlockedFunc VappUSBApp::m_blockedFunc = NULL;
void* VappUSBApp::m_blockedFuncData = NULL;
VappUSBApp* VappUSBApp::m_inst = NULL;

/***************************************************************************** 
 * Ewtern
 *****************************************************************************/
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
extern "C" void InitUnicodeSupport(void);
#endif

extern "C" void InitHardwareEvents(void);
extern "C" void InitSettingBootup(void);
extern "C" void InitSettingNVRAM(void);
//extern "C" void PhnsetReadNvramCalibrationData(void);
extern "C" void InitRingToneComposer(void);
//extern "C" void PmgInitExtMelodyStruct(void);
extern "C" void InitAlarmFrameWork(void);
extern "C" void PendingAlarmReminder(void);

extern "C" void InitFramework(void);
extern "C" void setup_UI_wrappers(void);
extern "C" void PopulateResData(void);
extern "C" void initialize_UI_demo(void);
extern "C" void PhnsetSetLangByNvramValue(void);

//extern "C" void mmi_alm_disable_pwroff(void);
extern "C" void InitChargerPwrOn(void);
//extern "C" void mmi_alm_enable_pwroff(void);
extern "C" void mdi_init(void);
extern "C" void vapp_charger_launch_charger_mode(void);
#ifdef __MMI_WEBCAM__
extern "C" void mmi_webcam_exit(void);
#endif
extern "C" void InitStringLanguage(void);
extern "C" mmi_id vapp_theme_init(mmi_event_struct *evt);

typedef enum
{
    VAPP_USB_STATUS_ICON_SHOW,
    VAPP_USB_STATUS_ICON_HIDE,
    VAPP_USB_STATUS_ICON_BLINK,
    VAPP_USB_STATUS_ICON_MAX_ITEM
} vapp_usb_status_icon_type_enum;

static void vapp_usb_set_status_icon(S32 icon, vapp_usb_status_icon_type_enum type);
static VfxBool vapp_usb_is_success_notify(srv_usb_config_result_struct* result);
static void vapp_usb_show_cfg_result_popup(srv_usb_config_result_struct* result);
static void vapp_usb_unlock_screen(void);

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void vapp_usb_launch(power_on_status_enum mode)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_LAUNCH, mode);

    #ifndef __MMI_USB_SLIM__
	VfxContext *cntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);
	
    gAppInst = VfxAppLauncher::launchWithCtx(
        VAPP_USBMMI,
        VFX_OBJ_CLASS_INFO(VappUSBApp),
        GRP_ID_ROOT,
        cntx,
        NULL,
        0);
	#else
	gAppInst =VfxAppLauncher::launch( 
			VAPP_USBMMI, 
			VFX_OBJ_CLASS_INFO(VappUSBApp),
			GRP_ID_ROOT);

	#endif
}

extern "C" void vapp_usb_launch_usbmode(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_LAUNCH_USBMODE);
    VappUSBApp::initApp(POWER_ON_USB);
    vapp_usb_launch(POWER_ON_USB);
}

extern "C" void vapp_launch_charger(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_LAUNCH_CHARGER);
    VappUSBApp::initApp(POWER_ON_CHARGER_IN);
    vapp_usb_launch(POWER_ON_CHARGER_IN);
}

extern "C" void vapp_usb_launch_normalmode(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_LAUNCH_NORMALMODE);
    vapp_usb_launch(POWER_ON_KEYPAD);
}

extern "C" void vapp_usb_init_normalmode(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_INIT_NORMALMODE);
    VappUSBApp::initApp(POWER_ON_KEYPAD);
}

VfxBool vapp_usb_handle_mmi_notify(srv_usb_mmi_notify_action_enum action)
{
    VfxBool ret = VFX_FALSE;
    
    switch(action)
    {
        case SRV_USB_MMI_NOTIFY_REMOVED:
        case SRV_USB_MMI_NOTIFY_POWER_OFF_REMOVED:
        case SRV_USB_MMI_NOTIFY_CLOSE_CFG_LIST:
        case SRV_USB_MMI_NOTIFY_CLOSE_PROGRESS:
            if (!VappUSBApp::m_inst)
                ret = VFX_TRUE;
            else
                ret = VFX_FALSE;
            break;

        case SRV_USB_MMI_NOTIFY_PLUGOUT:
            vapp_usb_set_status_icon(STATUS_ICON_USB, VAPP_USB_STATUS_ICON_HIDE);
			VappUSBNormalModeContext::closeStaticComfirm();
            VappUSBNormalModeScrn::closeFailPopComfirm();
            ret = VFX_TRUE;
            break;

		case SRV_USB_MMI_NOTIFY_EXIT_WEBCAM:
        #ifdef __MMI_WEBCAM__
            mmi_webcam_exit();
        #endif
            ret = VFX_TRUE;
            break;

        case SRV_USB_MMI_NOTIFY_CFG_END:
            VappUSBNormalModeContext::showInfoBollon(gCfgSuccessPopType);
            ret = VFX_TRUE;
            break;

		case SRV_USB_MMI_NOTIFY_CFG_ERROR:
        default:
            ret = VFX_FALSE;
            break;
    }

    return ret;
}

extern "C" mmi_ret vapp_usb_mmi_notify_callback(mmi_event_struct *evt)
{
	srv_usb_mmi_notify_action_enum act = (srv_usb_mmi_notify_action_enum)((VfxU32)(evt->user_data));

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_MMI_NOTIFY_CALLBACK);

    if (vapp_usb_handle_mmi_notify(act) == VFX_TRUE)
    {
        return MMI_RET_OK;
    }
    
    if (!VappUSBApp::m_inst)
    {
        vapp_usb_launch_normalmode();
    }
    
	if (VappUSBApp::m_inst)
	{
	    VappUSBApp::m_inst->usbSrvNotifyHdlr(act);
    }
    return MMI_RET_OK;
}


extern "C" mmi_ret vapp_usb_reminder_notify_hdlr(mmi_event_struct *evt)
{
  srv_bootup_mode_enum mode = srv_bootup_get_booting_mode();
  
	if (mode == SRV_BOOTUP_MODE_NORMAL)
	{
		return MMI_RET_OK;
	}
	
	if (mode == SRV_BOOTUP_MODE_USB && srv_usb_is_connected())
	{
		if (!VappUSBApp::m_inst)
		 {
			 vapp_usb_launch_usbmode();
		 }
	}

  return MMI_RET_OK; 
}


extern "C" mmi_ret vapp_usb_cfg_rsp_callback(mmi_event_struct *evt)
{
	srv_usb_config_result_struct *result = (srv_usb_config_result_struct*)evt->user_data;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_CFG_RSP_CALLBACK);

    if (VappUSBApp::m_inst)
    {
        VappUSBApp::m_inst->usbCfgRspHdlr(result->mode, result->suc);
        if (vapp_usb_is_success_notify(result) )
			
		    {
		        vapp_usb_show_cfg_result_popup(result);
		    }
        return MMI_RET_OK;
    }

    
    {
        vapp_usb_show_cfg_result_popup(result);
    }
    
    return MMI_RET_OK;
}

void vapp_usb_do_plug_in_hdlr(void *data)
{
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL || 
        srv_bootup_is_exception_mode())
    {
        if (VappUSBApp::m_inst)
    	{
    	    VappUSBApp::m_inst->usbPlugInHdlr();
        }
    }
}

extern "C" mmi_ret vapp_usb_handle_plug_in(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_HANDLE_PLUG_IN);

    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL || 
        srv_bootup_is_exception_mode())
    {
        if (!VappUSBApp::m_inst)
        {
            vapp_usb_launch_normalmode();
        }

        if (VappUSBApp::m_inst)
    	{
    	    VappUSBApp::m_inst->usbPlugInHdlr();
        }
        else
        {
            VappUSBApp::setAppBlockFunc(vapp_usb_do_plug_in_hdlr, NULL);
        }
    }
    else
    {
        VappUSBModeContext::ShowMSMode();
    }
    return MMI_RET_OK;
}

static void vapp_usb_unlock_screen(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_UNBLOCK_SCREEN);
    
    if (vapp_screen_lock_is_exist())
    {
	  #ifndef __LOW_COST_SUPPORT_COMMON__
	   vapp_cal_reminder_screen_lock_close();
	  
	    mmi_usb_terminate_alarm();
	  #endif
        vapp_screen_lock_close();
        gIsUnlocked = VFX_TRUE;
    }
}

VfxBool mmiPermitCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_MMIPERMITCHECK);
    
    if (!srv_bootup_is_completed() || 
        srv_fmgr_async_is_busy() ||
        //mmi_phb_check_processing()==MMI_TRUE ||
        //mmi_secset_is_in_puk_check() ||                 /* PUK needed after SIM lock failed or change PIN1 failed */
#ifdef __MMI_DUAL_SIM_MASTER__
        //mmi_secset_is_in_sim2_puk_check() ||
#endif    	
    #if defined(__DM_LAWMO_SUPPORT__)
        srv_dm_lawmo_is_locked() ||
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

extern "C" mmi_ret vapp_usb_handle_query_permit_pre_check(mmi_event_struct *evt)
{
    VfxBool ret;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_HANDLE_QUERY_PERMIT_PRE_CHECK);
    
    ret = mmiPermitCheck();
    if (ret)
    {
        srv_usb_unblock_event(EVT_ID_USB_PERMIT_CFG_PRE_CHECK);
    }
    else
    {
        srv_usb_block_event(EVT_ID_USB_PERMIT_CFG_PRE_CHECK);
    }
    vapp_usb_set_status_icon(STATUS_ICON_USB, VAPP_USB_STATUS_ICON_SHOW);
    return MMI_RET_OK;
}

VfxBool preShowCfgListNotify(void)
{
    srv_usb_status_enum usb_state = srv_usb_get_status();

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_PRESHOWCFGLISTNOTIFY);
    
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
        srv_usb_unblock_event(EVT_ID_USB_PERMIT_CFG);
        return VFX_TRUE;
    }
    else
    {
        srv_usb_block_event(EVT_ID_USB_PERMIT_CFG);
        return VFX_FALSE;
    }
}

extern "C" MMI_BOOL usbNmgrNotifyCallback(mmi_scenario_id scen_id, void *arg)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_USBNMGRNOTIFYCALLBACK);
    return (MMI_BOOL)preShowCfgListNotify();
}

extern "C" mmi_ret vapp_usb_handle_query_permit_show(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_HANDLE_QUERY_PERMIT_SHOW);
	
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_HIGH_SCRN, MMI_EVENT_NON_TONE, 
        usbNmgrNotifyCallback, NULL);
    
    vapp_usb_set_status_icon(STATUS_ICON_USB, VAPP_USB_STATUS_ICON_SHOW);
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_usb_charger_notify_hdlr(mmi_event_struct *evt)
{
    srv_charbat_evt_notify_struct *info = (srv_charbat_evt_notify_struct*)evt;
    VfxS32 level;
    power_on_status_enum mode;
    
    mode = VappUSBApp::getUsbMode();
        
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_CHARGERNOTIFYHDLR, mode);
    
    if ((mode == POWER_ON_USB ||
         mode == POWER_ON_CHARGER_IN ||
         mode == POWER_ON_PRECHARGE) &&
         VappUSBApp::m_inst)
	{
        level = info->battery_level;
       
        VappUSBApp::m_inst->chargerNotifyHdlr(info->status, level);
    }
    return MMI_RET_OK;
}

extern "C" void updateChargingState(kal_uint16 state, kal_uint8 level)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_UPDATECHARGINGSTATE, state, level);
    
    if (VappUSBApp::m_inst == NULL)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_NO_INST);
        return;
    }

    VappUSBApp::m_inst->chargerNotifyHdlr(state, level);
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
#endif
static void vapp_usb_set_status_icon(S32 icon, vapp_usb_status_icon_type_enum type)
{
    
    switch(type)
    {
        case VAPP_USB_STATUS_ICON_SHOW:
            wgui_status_icon_bar_set_icon_display(icon);
            break;
            
        case VAPP_USB_STATUS_ICON_HIDE:
            wgui_status_icon_bar_reset_icon_display(icon);
            break;
            
        default:
            break;
    }
}

static VfxBool vapp_usb_is_success_notify(srv_usb_config_result_struct* result)
{
    switch(result->mode)
    {
        case DEVUSB_CFG_ACTION_CDC_ACM:
        case DEVUSB_CFG_ACTION_MASS_STORAGE:
        case DEVUSB_CFG_ACTION_MULTI_COM:
        case DEVUSB_CFG_ACTION_PICTBRIGE:
        case DEVUSB_CFG_ACTION_MTP:
            return (VfxBool)result->suc;
            
        default:
            return VFX_FALSE;
    }
}

static void vapp_usb_show_cfg_result_popup(srv_usb_config_result_struct* result)
{
    PopupTypeEnum type;

    if (result->suc)
    {
        switch(result->mode)
        {
            case DEVUSB_CFG_ACTION_MASS_STORAGE:
                type = MS_SUCCESS;
                gCfgSuccessPopType = MS_SUCCESS;
                break;
                
        #ifdef __MTP_ENABLE__			
            case DEVUSB_CFG_ACTION_MTP:
                type = MTP_SUCCESS;
                gCfgSuccessPopType = MTP_SUCCESS;
                break;
        #endif

				#ifdef __MMI_USB_MULTIPLE_COMPORT_SUPPORT__
						case DEVUSB_CFG_ACTION_MULTI_COM:
				#endif
            case DEVUSB_CFG_ACTION_CDC_ACM:
            #if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__)
        				if (srv_usb_get_owner() == SRV_USB_COMPORT_JAVA)
        				{
        					type = JAVA_SUCCESS;
                	gCfgSuccessPopType = JAVA_SUCCESS;
        				}
        				else
        		#endif
        				{
                	type = COM_SUCCESS;
                	gCfgSuccessPopType = COM_SUCCESS;
                }
                break;
            
        #ifdef __MMI_PICT_BRIDGE_SUPPORT__
            case DEVUSB_CFG_ACTION_PICTBRIGE: /* PictBrige */
                type = PICTBRIDGE_SUCCESS;
                gCfgSuccessPopType = PICTBRIDGE_SUCCESS;
                break;
        #endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

            case DEVUSB_CFG_ACTION_WEBCAM: 
                return;
                
            default:
                type = CFG_SUCCESS;
                gCfgSuccessPopType = CFG_SUCCESS;
                break;
        }
        if (result->mode != DEVUSB_CFG_ACTION_MASS_STORAGE &&
            result->mode != DEVUSB_CFG_ACTION_MTP)
        {
            VappUSBNormalModeContext::showInfoBollon(type);
        }
        else
        {
            srv_usb_unblock_event(EVT_ID_USB_CONFIG_RSP);
        }
    }
    else
    {
        switch(result->mode)
        {
            case DEVUSB_CFG_ACTION_MASS_STORAGE:
                type = MS_FAIL;
                break;
                
        #ifdef __MTP_ENABLE__			
            case DEVUSB_CFG_ACTION_MTP:
                type = MTP_FAIL;
                break;
        #endif

				#ifdef __MMI_USB_MULTIPLE_COMPORT_SUPPORT__
						case DEVUSB_CFG_ACTION_MULTI_COM:
				#endif
        case DEVUSB_CFG_ACTION_CDC_ACM:
        		#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__)
        				if (srv_usb_get_owner() == SRV_USB_COMPORT_JAVA)
        				{
        					type = JAVA_FAIL;
        				}
        				else
        		#endif
        		    {
                type = COM_FAIL;
                }
                break;
        case DEVUSB_CFG_ACTION_WEBCAM: 
                return;
                
            default:
                type = CFG_FAIL;
                break;
        }
        VappUSBNormalModeContext::showStaticComfirm(type);
    }
}

VFX_IMPLEMENT_CLASS("VappUSBApp", VappUSBApp, VfxApp);

void VappUSBApp::initApp(power_on_status_enum mode)
{
    if (VappUSBApp::m_powerOnMode != POWER_ON_UNINIT)
        return;
    
    VappUSBApp::m_powerOnMode = mode;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_INITAPP, mode);
    
    if (mode == POWER_ON_USB)
    {
        VappUSBApp::initUSBMode();
    }
    else if (mode == POWER_ON_KEYPAD)
    {
        initNormalMode();
    }
    else if (mode == POWER_ON_CHARGER_IN ||
        mode == POWER_ON_PRECHARGE)
    {
        srv_usb_init_context();
        VappUSBApp::initChargerMode();
    }
}

void VappUSBApp::initUSBMode(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_INITUSBMODE);
    
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
	InitUnicodeSupport();
#endif
    InitStringLanguage();
	srv_gpio_setting_init();
	srv_backlight_init_context_early();
	srv_usb_init_bootup();
    if (!srv_charbat_is_charger_connect())
        srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_IN);
	mmi_fe_init();
	InitFramework();
	setup_UI_wrappers();
	PopulateResData();
	initialize_UI_demo();
	/*init sound effect settings, this shall be done before set lang by nvram 
	  since it might effect equalizer values*/
	PhnsetSetLangByNvramValue(); 
    mdi_init();
	mdi_audio_init();
	InitHardwareEvents();
	InitTime();
    vapp_theme_init(NULL);
	srv_prof_init();
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
	//PhnsetReadNvramCalibrationData();
	srv_setting_pen_calibration_init_data();
#endif 
	InitSettingNVRAM();
/*
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
	PmgInitExtMelodyStruct();
#endif 
*/
	srv_gpio_setting_contrast_restore();
	InitAlarmFrameWork();
	//mmi_alm_disable_pwroff();
	srv_led_pattern_start_charging();
	//g_charbat_context.PowerOnCharger = 1;
	//g_charbat_context.isChargerConnected = 1;
	PendingAlarmReminder();
	InitChargerPwrOn();

	//SetProtocolEventHandler(srv_usb_detect_ind_hdlr, MSG_ID_MMI_EQ_USBDETECT_IND);
	//SetProtocolEventHandler(VappUSBApp::chargerNotifyHdlr, MSG_ID_MMI_EQ_BATTERY_STATUS_IND);
	srv_usb_init_event_hdlr();
	VappUSBModeContext::initContext();
	//mmi_usb_boot_show_scrn();
	//srv_backlight_turn_on(1);
}

void VappUSBApp::initChargerMode(void)
{
    vapp_charger_launch_charger_mode();
}

power_on_status_enum VappUSBApp::getUsbMode(void)
{
    return m_powerOnMode;
}

void VappUSBApp::setAppBlockFunc(usbAppBlockedFunc func, void *data)
{
    m_blockedFunc = func;
    m_blockedFuncData = data;
}

usbAppBlockedFunc VappUSBApp::getAppBlockFunc(void)
{
    return m_blockedFunc;
}

void VappUSBApp::runAppBlockFunc(void)
{
    if (m_blockedFunc)
    {
        m_blockedFunc(m_blockedFuncData);
        m_blockedFunc = NULL;
    }
}

void VappUSBApp::initNormalMode(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_INITNORMALMODE);
    srv_usb_init_context();
    srv_usb_init_event_hdlr();
}

void VappUSBApp::updatePowerOnMode(void)
{
    switch(srv_bootup_get_booting_mode())
    {
        case SRV_BOOTUP_MODE_INVALID:
            break;
            
        case SRV_BOOTUP_MODE_NORMAL:
            VappUSBApp::m_powerOnMode = POWER_ON_KEYPAD;
            break;
            
        case SRV_BOOTUP_MODE_USB:
            VappUSBApp::m_powerOnMode = POWER_ON_USB;
            break;
            
        case SRV_BOOTUP_MODE_ALARM:
            VappUSBApp::m_powerOnMode = POWER_ON_ALARM;
            break;
            
        case SRV_BOOTUP_MODE_PRECHARGE:
            VappUSBApp::m_powerOnMode = POWER_ON_PRECHARGE;
            break;
            
        case SRV_BOOTUP_MODE_CHARGE:
            VappUSBApp::m_powerOnMode = POWER_ON_CHARGER_IN;
            break;

        default:
            break;
    }
}

void VappUSBApp::onRun(void* args, VfxU32 argSize)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_ONRUN);
	VfxApp::onRun(args, argSize);

    updatePowerOnMode();
    
	// Create context by power on mode
	if (VappUSBApp::m_powerOnMode == POWER_ON_USB ||
        VappUSBApp::m_powerOnMode == POWER_ON_CHARGER_IN ||
        VappUSBApp::m_powerOnMode == POWER_ON_PRECHARGE)
	{
        if (!m_usbModeContext)
        {
    		VFX_OBJ_CREATE(m_usbModeContext, VappUSBModeContext, this);
    		m_usbModeContext->initContext();
    		m_usbModeContext->showScreen();
              if (VappUSBApp::m_powerOnMode == POWER_ON_CHARGER_IN ||
                    VappUSBApp::m_powerOnMode == POWER_ON_PRECHARGE)
              {
                m_usbModeContext->m_closeSingal.connect(this, &VappUSBApp::onContextClose);
              }
        }
	}
	else if (VappUSBApp::m_powerOnMode == POWER_ON_KEYPAD)
	{
        if (!m_normalModeContext)
        {
            VFX_OBJ_CREATE(m_normalModeContext, VappUSBNormalModeContext, this);
            m_normalModeContext->m_screenClosedSignal.connect(this, &VappUSBApp::onContextScreenClosed);
        }
        else
        {
            if (srv_usb_get_status() == SRV_USBSTATUS_CONF_PAGE)
            {
                m_normalModeContext->showCfgList();
            }
        }
	}
    else
    {        
    }

    runAppBlockFunc();
}

void VappUSBApp::onDeinit()
{
    VfxApp::onDeinit();

    switch (srv_usb_get_status())
    {
        case SRV_USBSTATUS_WEBCAM:
        case SRV_USBSTATUS_USBTETHERING:
			vapp_usb_unlock_screen();
            break;

        default:
            
            break;
    }
}

void VappUSBApp::chargerNotifyHdlr(VfxU16 status, VfxU8 level)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_CHARGERNOTIFYHDLR, status, level);
    if (m_usbModeContext)
    {
        m_usbModeContext->updateChargingState(status, level);
    }
}

void VappUSBApp::usbSrvNotifyHdlr(srv_usb_mmi_notify_action_enum action)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_USBSRVNOTIFYHDLR, action);
	switch(action)
	{
		case SRV_USB_MMI_NOTIFY_POWER_OFF_REMOVED:
			onPowerOffRemoved();
			break;

		default:
            onNormalModeSrvNotify(action);
			break;
	}
}

void VappUSBApp::usbCfgRspHdlr(VfxU8 mode, VfxBool result)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_USBCFGRSPHDLR, mode, result);
    if (m_normalModeContext)
    {
        m_normalModeContext->usbCfgRspHdlr(mode, result);
    }
}

void VappUSBApp::usbPlugInHdlr(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_USBPLUGINHDLR);
    showCfgList();
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}

void VappUSBApp::usbPermitPreCheckHdlr(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_USBPERMITPRECHECKHDLR);
    if (m_normalModeContext)
    {
        m_normalModeContext->preShowCfgListCheck();
    }
}

void VappUSBApp::usbPermitCheckHdlr(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_USBPERMITCHECKHDLR);
    if (m_normalModeContext)
    {
        m_normalModeContext->preShowCfgList();
    }
}

VfxAppCloseAnswerEnum VappUSBApp::onProcessClose(VfxAppCloseOption options)
{
    if (srv_usb_get_status() == SRV_USBSTATUS_CONF_PAGE)
    {
        srv_usb_set_status(SRV_USBSTATUS_IGNORED);
    }
    if (m_normalModeContext)
    {
        m_normalModeContext->closeCfgList();
    }
    return VFX_APP_CLOSE_ANSWER_YES;
}

void VappUSBApp::onPowerOffRemoved(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_ONPOWEROFFREMOVED);
    if (m_usbModeContext)
    {
        m_usbModeContext->closeScreen();
    }
	//mmi_alm_enable_pwroff();
    terminate();
}

void VappUSBApp::onNormalModeSrvNotify(srv_usb_mmi_notify_action_enum action)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_ONNORMALMODESRVNOTIFY, action);
    
    if (!m_normalModeContext)
    {
        return;
    }
    switch(action)
	{
        case SRV_USB_MMI_NOTIFY_PLUGOUT:
            vapp_usb_set_status_icon(STATUS_ICON_USB, VAPP_USB_STATUS_ICON_HIDE);
			VappUSBNormalModeContext::closeStaticComfirm();
            VappUSBNormalModeScrn::closeFailPopComfirm();
            break;
            
		case SRV_USB_MMI_NOTIFY_REMOVED:
			//BatteryIndicationPopup(STR_USB_CHARGER_REMOVED);
			terminate();
			break;
			
		case SRV_USB_MMI_NOTIFY_CLOSE_CFG_LIST:
			m_normalModeContext->closeCfgList();
			break;

		case SRV_USB_MMI_NOTIFY_CLOSE_PROGRESS:
			m_normalModeContext->closeProgress();
			break;

		case SRV_USB_MMI_NOTIFY_EXIT_WEBCAM:
    #ifdef __MMI_WEBCAM__
			m_normalModeContext->exitWebCam();
    #endif
            terminate();
			break;

		case SRV_USB_MMI_NOTIFY_CFG_ERROR:
			m_normalModeContext->showPopup(CFG_FAIL);
			break;
			
		default:
			break;
	}
}

void VappUSBApp::onContextScreenClosed(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_ONCONTEXTSCREENCLOSED);
    terminate();
}

void VappUSBApp::terminate(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_TERMINATE);
    if (gAppInst)
    {
        VfxAppLauncher::terminate(gAppInst);
        gAppInst = NULL;
    }
}

void VappUSBApp::showCfgList(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBAPP_SHOWCFGLIST);
    if (m_normalModeContext)
    {
        m_normalModeContext->createScreen();
        m_normalModeContext->showCfgList();
    }
}

void VappUSBApp::onContextClose(void)
{
    terminate();
}

#ifdef __AFX_RT_TEST__
VtstTestResultEnum vtst_rt_vapp_usb(VfxU32 param)
{
    vapp_usb_launch(POWER_ON_KEYPAD);
    return VTST_TR_OK;
}
#endif

#endif /* __MMI_USB_SUPPORT__*/ 

#if !defined(__MMI_USB_SUPPORT__)
#ifdef __cplusplus
extern "C"
{
#include "mmi_include.h"
#include "MMIDataType.h"
#include "USBSrvGProt.h"
}
#endif

extern "C" mmi_ret vapp_usb_mmi_notify_callback(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

// For modis resgen
extern "C" mmi_ret vapp_usb_reminder_notify_hdlr(mmi_event_struct *evt)
{
	return MMI_RET_OK; 
}

extern "C" mmi_ret vapp_usb_cfg_rsp_callback(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_usb_handle_plug_in(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_usb_handle_query_permit_pre_check(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_usb_handle_query_permit_show(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_usb_charger_notify_hdlr(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
#endif
