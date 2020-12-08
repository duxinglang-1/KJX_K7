/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_charger_main.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
     
/* Pluto MMI headers: */
#ifdef __cplusplus
 extern "C"
 {
#include "MMIDataType.h"
#include "mmi_features.h"

//#include "MMI_include.h" 
//#include "kal_general_types.h"
//#include "stack_common.h"

#include "gdi_include.h"
//#include "stack_msgs.h"
#include "MMI_common_app_trc.h"
#include "gpiosrvgprot.h"
#include "ProfilesSrvGprot.h"
#include "CharBatSrvGprot.h"
#include "wgui_categories_util.h"
#include "Device.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_events.h"
#include "NotificationGprot.h"
#include "TimerEvents.h"
}
#endif

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vfx_cpp_base.h"
#include "vcp_popup.h"
#include "vcp_global_popup.h"
 
#include "vapp_charger_gprot.h"
#include "mmi_rp_vapp_device_def.h"
#include "mmi_rp_srv_status_icons_def.h"


 /***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Extern
 *****************************************************************************/
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ 
extern "C" void InitUnicodeSupport(void);
#endif

#ifdef __MMI_USB_SUPPORT__
extern "C" void InitMMIUsbContext(void);
#endif

#ifdef __MMI_WEBCAM__
extern "C" void mmi_webcam_init_context(void);
#endif

extern "C" void mdi_audio_init(void);
extern "C" void mmi_fe_init(void);
extern "C" void InitFramework(void);
extern "C" void InitHardwareEvents(void);
extern "C" void mmi_fe_init(void);
extern "C" void InitFramework(void);
extern "C" void applib_dt_init_time(void);
extern "C" void setup_UI_wrappers(void);
extern "C" void PopulateResData(void);
extern "C" void initialize_UI_demo(void);
extern "C" void InitSettingNVRAM(void);
extern "C" void InitAlarmFrameWork(void);
extern "C" mmi_id vapp_theme_init(mmi_event_struct *evt);
extern "C" void PendingAlarmReminder(void);
extern "C" MMI_BOOL mmi_alm_is_in_alarm(void);


/***************************************************************************** 
 * static
 *****************************************************************************/
static void vapp_charger_update_status_icon_level(VfxS32 battery_level);
static void vapp_charger_low_pwr_auto_shutdown(void);
static void vapp_charger_low_pwr_auto_shutdown_timer_hdlr(void);
static void vapp_charger_precharge_mode(void *msg);
static void vapp_charger_check_low_power_off(S32 battery_level);

static MMI_BOOL vapp_charger_notify_hdlr(mmi_scenario_id scen_id, void *arg);
static void vapp_charger_popup(void *user_data);
static void vapp_charger_popup_cbk(VfxId id, void *userData);
static MMI_BOOL vapp_charger_notify_low_pwr_hdlr(mmi_scenario_id scen_id, void *user_data);
static void vapp_charger_notify_low_pwr_popup_cbk(VfxId id, void *user_data);

static MMI_BOOL vapp_charger_notify_abnormal_hdlr(mmi_scenario_id scen_id, void *user_data);
static void vapp_charger_notify_abnormal_popup_cbk(VfxId id, void *user_data);

static MMI_BOOL vapp_charger_notify_shutdown_hdlr(mmi_scenario_id scen_id, void *user_data);
static void vapp_charger_notify_shutdown_popup_cbk(VfxId id, void *user_data);
static void vapp_charger_play_low_battery_tone(void);


/***************************************************************************** 
 * Other
 *****************************************************************************/
    
#define   VAPP_CHARGER_INVALID_ID    0
static VfxS32 vapp_charger_low_pwr_popup_hdlr = VAPP_CHARGER_INVALID_ID;
/***************************************************************************** 
 * Function
 *****************************************************************************/
#define VAPP_CHARGER_API_START

extern "C"
mmi_ret vapp_charger_init(mmi_event_struct *evt)
{
    vapp_charger_update_status_icon();
    return MMI_RET_OK;
}


// Power_off -> insert charger
extern "C"
void vapp_charger_launch_charger_mode(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_PWRON_CHARGE_INIT);
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    InitUnicodeSupport();
#endif

    gdi_init();

    srv_gpio_setting_init();
    srv_backlight_init_context_early();
    if (!srv_charbat_is_charger_connect()) // in case change some status
        srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_IN);

#ifdef __MMI_USB_SUPPORT__
    InitMMIUsbContext();
#endif 
#ifdef __MMI_WEBCAM__
    mmi_webcam_init_context();
#endif

    mdi_audio_init();
    mmi_fe_init();    
    InitFramework();
    InitHardwareEvents();
    InitTime();
    setup_UI_wrappers();
    PopulateResData();
    vapp_theme_init(NULL);
    initialize_UI_demo();
    vapp_charger_update_status_icon();
    
    /* Precharge Power On */
    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_PRECHARGE)
    {
        mmi_frm_set_protocol_event_handler(
            MSG_ID_MMI_EQ_LEAVE_PRECHARGE_IND, (PsIntFuncPtr)vapp_charger_precharge_mode, MMI_FALSE);
    }

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    srv_prof_init();

    InitSettingNVRAM();

    InitAlarmFrameWork();
#if 0
/* under construction !*/
#endif
    srv_charbat_init_event_hdlr();
    /* To wake up pending alarm */
    PendingAlarmReminder();
}


static void vapp_charger_precharge_mode(void *msg)
{
    ClearInputEventHandler(MMI_DEVICE_ALL);
}

extern "C"
VfxBool vapp_charger_low_pwr_popup_exist()
{
  if(vapp_charger_low_pwr_popup_hdlr != VAPP_CHARGER_INVALID_ID)
  	{
      return VFX_TRUE;
  }
  return VFX_FALSE;
}




extern "C"
void vapp_charger_update_status_icon(void)
{
   
   MMI_TRACE(MMI_COMMON_TRC_G8_DEV,TRC_MMI_CHARBAT_UPDATE_STATUS_ICON);
    if (srv_charbat_is_charging())
    { 
      
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV,TRC_MMI_CHARBAT_IS_CHARGING);
        wgui_status_icon_bar_reset_icon_animate(STATUS_ICON_BATTERY_STRENGTH);
        #ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_reset_icon_animate(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);        
        #endif
        switch (srv_charbat_get_battery_level())
        {
            case BATTERY_LOW_POWEROFF:
            case BATTERY_LOW_TX_PROHIBIT:
            case BATTERY_LOW_WARNING:
            case BATTERY_LEVEL_0:
            case BATTERY_LEVEL_1:
                wgui_status_icon_bar_change_icon_image(STATUS_ICON_BATTERY_STRENGTH, IMG_SI_BATTERY_CHARGE_STRENGTH_1);
                break;
                
            case BATTERY_LEVEL_2:
                wgui_status_icon_bar_change_icon_image(STATUS_ICON_BATTERY_STRENGTH, IMG_SI_BATTERY_CHARGE_STRENGTH_2);
                break;
                
            case BATTERY_LEVEL_3:
                wgui_status_icon_bar_change_icon_image(STATUS_ICON_BATTERY_STRENGTH, IMG_SI_BATTERY_CHARGE_STRENGTH_3);
                break;
        }
		
		MMI_TRACE(MMI_COMMON_TRC_G8_DEV,TRC_MMI_CHARBAT_SET_ANIMATE);
        wgui_status_icon_bar_set_icon_animate(STATUS_ICON_BATTERY_STRENGTH);
        #ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_set_icon_animate(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        #endif
        wgui_status_icon_bar_update();
        //MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_IN); 
    }
    else // when no charging, or charging complete
    {
         
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV,TRC_MMI_CHARBAT_IS_NOT_CHARGING);
		MMI_TRACE(MMI_COMMON_TRC_G8_DEV,TRC_MMI_CHARBAT_RESET_ANIMATE);
        wgui_status_icon_bar_reset_icon_animate(STATUS_ICON_BATTERY_STRENGTH);
        #ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_reset_icon_animate(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
        #endif
        wgui_status_icon_bar_update();
        vapp_charger_update_status_icon_level(srv_charbat_get_battery_level());
        //MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_OUT);
    }
}


static void vapp_charger_update_status_icon_level(VfxS32 battery_level)
{
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_BATTERY_STRENGTH, IMG_SI_BATTERY_STRENGTH);
    switch (battery_level)
    {
        case BATTERY_LOW_POWEROFF:
        case BATTERY_LOW_TX_PROHIBIT:
        case BATTERY_LOW_WARNING:
        case BATTERY_LEVEL_0:
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_LOW_BATTERY_WARNING, battery_level);
            wgui_status_icon_bar_change_icon_level(STATUS_ICON_BATTERY_STRENGTH, 0);
            #ifdef __MMI_SUBLCD__
            wgui_status_icon_bar_change_icon_level(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 0);
            #endif
            break;
        }

        case BATTERY_LEVEL_1:
        case BATTERY_LEVEL_2:
        case BATTERY_LEVEL_3:
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_BATTERY_LEVEL, battery_level);
            wgui_status_icon_bar_change_icon_level(
                (S16) STATUS_ICON_BATTERY_STRENGTH, 
                (U8) (33 * (battery_level - BATTERY_LEVEL_0)));
                #ifdef __MMI_SUBLCD__
            wgui_status_icon_bar_change_icon_level(
                (S16) STATUS_ICON_SUBLCD_BATTERY_STRENGTH,
                (U8) (33 * (battery_level - BATTERY_LEVEL_0)));
                #endif

            break;
        }

        default:
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_BATTERY_STATE_UNKNOWN_VOLTAGE);            
            wgui_status_icon_bar_change_icon_level(STATUS_ICON_BATTERY_STRENGTH, 33);
            #ifdef __MMI_SUBLCD__
            wgui_status_icon_bar_change_icon_level(STATUS_ICON_SUBLCD_BATTERY_STRENGTH, 33);
            #endif
            break;
        }
    }
    wgui_status_icon_bar_update();
}


extern "C"
mmi_ret vapp_charger_main_evt_hdlr(mmi_event_struct* para)
{
    srv_charbat_evt_notify_struct *p = (srv_charbat_evt_notify_struct *)para;

    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_MAIN_EVT_HDLR, p->status, p->battery_level);
    switch (p->status)
    {
        case PMIC_USB_NO_CHARGER_IN:
        case PMIC_USB_CHARGER_IN:
        case PMIC_CHARGER_IN:
        {
            if (srv_bootup_is_launched())
                srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            if (vapp_charger_low_pwr_popup_hdlr != VAPP_CHARGER_INVALID_ID)
            {
                vcp_global_popup_cancel(vapp_charger_low_pwr_popup_hdlr);
            }
            vapp_charger_update_status_icon();
			#if 0 
/* under construction !*/
			#endif
            break;
        }

        case PMIC_USB_NO_CHARGER_OUT:
        case PMIC_USB_CHARGER_OUT:
        case PMIC_CHARGER_OUT:
        {
            if ((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_CHARGE ||
                 srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_PRECHARGE) &&
                mmi_alm_is_in_alarm() == 0)
            {
                mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_OFF_REQ, 
                    NULL, NULL);
            }
            else
            {
                if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
                    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
                vapp_charger_update_status_icon();
				#if 0
/* under construction !*/
				#endif
            }
            break;
        }

        case PMIC_CHARGE_COMPLETE:  /* battery full charged. */
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            vapp_charger_update_status_icon();
			#if 0 
/* under construction !*/
			#endif
            
            // show charging completed page by USB APP if in poweroff            
            break;
        }

        case PMIC_VBAT_STATUS:
        {
            vapp_charger_check_low_power_off(p->battery_level);
            vapp_charger_update_status_icon();
            break;
        }

        case PMIC_OVERVOLPROTECT:
        case PMIC_OVERCHARGECURRENT:
        case PMIC_CHARGING_TIMEOUT:
        case PMIC_INVALID_CHARGER:
        case PMIC_LOWCHARGECURRENT:
        case PMIC_CHARGE_BAD_CONTACT:
        {
            // show error popup and error text
            vapp_charger_notify(STR_ID_VAPP_CHARGER_CHARGING_ERROR);
            break;
        }

        case PMIC_OVERBATTEMP:
        case PMIC_INVALID_BATTERY:
        case PMIC_LOWBATTEMP:
        case PMIC_BATTERY_BAD_CONTACT:
        {
            // show error popup and error text
            vapp_charger_notify(STR_ID_VAPP_CHARGER_BATTERY_ERROR);
            break;
        }

        default:
            break;
    }
	return MMI_RET_OK;
}

extern "C"
mmi_ret vapp_charger_other_evt_hdlr(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CHARBAT_REMIND_LOW_POWER:
        {
            vapp_charger_notify(STR_ID_VAPP_CHARGER_LOW_BATTERY);
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


#define VAPP_CHARGER_SCENARIO_API_START
extern "C"
void vapp_charger_notify(VfxU16 stringId)
{    
    if ( stringId == STR_ID_VAPP_CHARGER_LOW_BATTERY) // low battery
    {
        if (vapp_charger_low_pwr_popup_hdlr != VAPP_CHARGER_INVALID_ID)
        {
            vcp_global_popup_cancel(vapp_charger_low_pwr_popup_hdlr);
        }
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_BATTERY_HIGHEST, 
            MMI_EVENT_WARNING, 
            vapp_charger_notify_low_pwr_hdlr, 
            NULL);
    }
    else if (stringId == STR_ID_VAPP_CHARGER_CHARGING_ERROR || stringId == STR_ID_VAPP_CHARGER_BATTERY_ERROR) // abnormal
    {
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_CHARGING_ERR, 
            MMI_EVENT_FAILURE, 
            vapp_charger_notify_abnormal_hdlr, 
            NULL);
    }
    else if (stringId == STR_ID_VAPP_CHARGER_LOW_BATTERY_SHUTDOWN)// auto-shutdown
    {
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_BATTERY_HIGHEST, 
            MMI_EVENT_WARNING, 
            vapp_charger_notify_shutdown_hdlr, 
            NULL);
    }
    else
    {
        return;
    }
}


static MMI_BOOL vapp_charger_notify_low_pwr_hdlr(mmi_scenario_id scen_id, void *user_data)
{
    mmi_frm_start_scenario(scen_id);

    vapp_charger_low_pwr_popup_hdlr = 
        vcp_global_popup_show_confirm_one_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_WARNING,
                STR_ID_VAPP_CHARGER_LOW_BATTERY,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                vapp_charger_notify_low_pwr_popup_cbk,
                NULL
                );
    return MMI_TRUE;
}

static void vapp_charger_notify_low_pwr_popup_cbk(VfxId id, void *user_data)
{    
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BATTERY_HIGHEST);
    vapp_charger_low_pwr_popup_hdlr = VAPP_CHARGER_INVALID_ID;
}

static MMI_BOOL vapp_charger_notify_abnormal_hdlr(mmi_scenario_id scen_id, void *user_data)
{
    mmi_frm_start_scenario(scen_id);
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_CHARBAT_BATTERYINDICATION_POPUP);
    
    vcp_global_popup_show_confirm_one_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_FAILURE,
                STR_ID_VAPP_CHARGER_BATTERY_ERROR,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                vapp_charger_notify_abnormal_popup_cbk,
                NULL
                );
    return MMI_TRUE;
}

static void vapp_charger_notify_abnormal_popup_cbk(VfxId id, void *user_data)
{    
    mmi_frm_end_scenario(MMI_SCENARIO_ID_CHARGING_ERR);
}

static MMI_BOOL vapp_charger_notify_shutdown_hdlr(mmi_scenario_id scen_id, void *user_data)
{
    mmi_frm_start_scenario(scen_id);

    vcp_global_popup_show_confirm_one_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_WARNING,
                STR_ID_VAPP_CHARGER_LOW_BATTERY_SHUTDOWN,
                STR_GLOBAL_OK,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                vapp_charger_notify_shutdown_popup_cbk,
                NULL
                );
    return MMI_TRUE;
}

static void vapp_charger_notify_shutdown_popup_cbk(VfxId id, void *user_data)
{    
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BATTERY_HIGHEST);
}


/* battery is too low, if not connect charger,USB, will power off */
static void vapp_charger_check_low_power_off(S32 battery_level)
{
    if (BATTERY_LOW_POWEROFF != battery_level)
        return;
    
    if (!srv_charbat_is_charging() && !srv_bootup_is_booting())
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_LOW_BATTERY_POWER_OFF);
        vapp_charger_low_pwr_auto_shutdown();
    }
}


static void vapp_charger_low_pwr_auto_shutdown(void)
{
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    // show low battery shutdown globla popup
    vapp_charger_notify(STR_ID_VAPP_CHARGER_LOW_BATTERY_SHUTDOWN);

    mmi_frm_clear_all_protocol_event_handler();

    StartTimer(VAPP_LOW_BATTERY_SCR_TIMER, 
        VAPP_CHARGER_LBAT_SHUTDOWN_SCR_TIMER_DUR, 
        vapp_charger_low_pwr_auto_shutdown_timer_hdlr);

    vapp_charger_play_low_battery_tone();
}


static void vapp_charger_play_low_battery_tone(void)
{
    if (!srv_charbat_is_charging())
    {
        srv_prof_play_tone(BATTERY_LOW_TONE, NULL);        
    }
}


static void vapp_charger_low_pwr_auto_shutdown_timer_hdlr(void)
{
    StopTimer(VAPP_LOW_BATTERY_SCR_TIMER);
#ifdef __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__
    srv_shutdown_exit_system(VAPP_DEVICE);
#else
    /* if low battery shutdown at power on, do no play power off animation */
    if (srv_bootup_is_booting())
    {
        srv_shutdown_exit_system(VAPP_DEVICE);
    }
    else
    {
        srv_shutdown_normal_start(VAPP_DEVICE);
    }
#endif /* __MMI_LOW_BATTERY_SHUTDOWN_NO_ANIMATION__ */ 
}


