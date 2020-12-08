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
 *  vapp_screen_lock_main.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h" 
#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_system.h"

#include "vapp_screen_lock_screen.h"
#include "vapp_screen_lock_main.h" 
#include "vapp_wallpaper_kit.h"
#include "vapp_widget_music_player.h"
#include "vapp_ncenter_gprot.h"
#include "mmi_rp_vapp_screen_lock_def.h"
#include "vapp_screen_lock_gprot.h"

// for wallpaper setting api
#include "vapp_wallpaper_setting_method_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "PhoneSetupGprots.h"
#include "GpioSrvGProt.h"
#include "ShutdownSrvGprot.h"
#include "GlobalResDef.h"
#include "AppMgrSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "gpiosrvgprot.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_input_gprot.h"

// for fm radio panel
#include "vapp_widget_fm_radio.h"

// memory context for screen lock
#include "vapp_platform_context.h"

// To be removed
#include "ScrLockerGprot.h"
#include "ScrSaverGprot.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static MMI_BOOL stopKeyRouting = MMI_FALSE;
vapp_screen_lock_mode_enum lockMode = VAPP_SCREEN_LOCK_MODE_BY_AUTO_LOCK;

static VfxU16 flag;


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Option flag. */
#define VAPP_SCREEN_LOCK_FLAG_SELF_SUSPEND               (1 << 0)
#define VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_FLAG           (1 << 1)
#define VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_PEN_FLAG       (1 << 2)

    
    /* Set / Clear / Has flag. */
#define VAPP_SCREEN_LOCK_SET(_f) (flag |= _f)
#define VAPP_SCREEN_LOCK_CLR(_f) (flag &= ~_f)
#define VAPP_SCREEN_LOCK_HAS(_f) (((flag & _f) == _f))

extern "C" mmi_ret vapp_screen_lock_main_evt_hdlr(mmi_event_struct *event);


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Function
 *****************************************************************************/

MMI_BOOL vapp_screen_lock_sim_not_in_verifying(void)
{
    if(!srv_sim_ctrl_any_verifying_sim())
    {
        return MMI_TRUE;
    }

    //Screen lock can be launched if the sim status is in initializing.
    //Scenario: In home screen, insert sim card(pop up sim inserted) and press power key immediately.
    //          It should able to launch screen lock.
    for (S32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sim_ctrl_get_unavailable_cause(mmi_frm_index_to_sim(i)) != SRV_SIM_CTRL_UA_CAUSE_INITIALIZING) 
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


MMI_BOOL vapp_screen_lock_is_allowed_launch(void)
{
    if(((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
        && vapp_screen_lock_sim_not_in_verifying()
        && !(srv_bootup_is_booting() || srv_shutdown_is_running())))
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_ALLOWED_LAUNCH, 200);

        // Emit pre lock evt to know whether allowed to launch lock
        vapp_screen_lock_pre_lock_evt_struct evt;
        mmi_ret ret;
        
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING);
        evt.mode= lockMode;
        ret = MMI_FRM_CB_EMIT_EVENT(&evt);
        if (ret == MMI_RET_OK || ret == MMI_RET_ERR_NO_REG_CB)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_ALLOWED_LAUNCH, 201);
            lockMode = VAPP_SCREEN_LOCK_MODE_BY_AUTO_LOCK;  //initial lock mode
            return MMI_TRUE;
        }
    }
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_ALLOWED_LAUNCH, 300);
    return MMI_FALSE;
}


mmi_id vapp_screen_lock_launch(void)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_LAUNCH, 200);
    
    VfxContext *cntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);
    
    return VfxAppLauncher::launchWithCtx(
                        VAPP_SCREEN_LOCK,
                        VFX_OBJ_CLASS_INFO(VappScreenLockApp),
                        GRP_ID_ROOT,
                        cntx);
}


void vapp_screen_lock_post_launch(void)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_POST_LAUNCH_REQ, 200);
    
    mmi_event_struct event;
    MMI_FRM_INIT_EVENT(&event, EVT_ID_VAPP_SCREEN_LOCK_LAUNCH_REQ);
    MMI_FRM_POST_EVENT(&event, vapp_screen_lock_main_evt_hdlr, NULL);
}


MMI_BOOL vapp_screen_lock_is_locked()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app = VfxAppLauncher::findApp(
            VAPP_SCREEN_LOCK,
            VFX_OBJ_CLASS_INFO(VappScreenLockApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if(app)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_LOCKED, app->isActive());
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_LOCKED, -1);
    }

    if (app && app->isActive())
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


MMI_BOOL vapp_screen_lock_is_exist()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app = VfxAppLauncher::findApp(
            VAPP_SCREEN_LOCK,
            VFX_OBJ_CLASS_INFO(VappScreenLockApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (app)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_EXIST, 200);
        return MMI_TRUE;
    }

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_EXIST, 300);
    return MMI_FALSE;
}


// close screen guard
void vapp_screen_lock_close()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxApp *app;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app = VfxAppLauncher::findApp(
            VAPP_SCREEN_LOCK,
            VFX_OBJ_CLASS_INFO(VappScreenLockApp),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);
    if(app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }
}


void vapp_screen_lock_disable_backlight_timer(MMI_BOOL disable)
{
    // TODO: use gpio service api: app timer
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
#endif
}


static MMI_BOOL vapp_screen_lock_is_switch_backlight_key(mmi_event_struct *event)
{
    mmi_frm_key_evt_struct *evt;
    evt = (mmi_frm_key_evt_struct *)event;

    MMI_BOOL isSwitchBacklight;
    if(evt->key_code == KEY_POWER)
    {
        isSwitchBacklight =  MMI_TRUE;
    }
    else
    {
        isSwitchBacklight = MMI_FALSE;
    }
    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_SWITCH_BACKLIGHT_KEY, isSwitchBacklight);
    return isSwitchBacklight;
}


static MMI_BOOL vapp_screen_lock_is_turn_on_backlight_key(mmi_event_struct *event)
{
//
// Only for special UE behavior. 
// On Victor56, we allow the user to turn on the backlight with any key. 
// Removing these codes doesn't affect the functionality. 
// It only affect the UE behavior.
//
#if defined(VICTOR56_DEMO_BB)
    return MMI_TRUE;
#endif

    mmi_frm_key_evt_struct *evt;
    evt = (mmi_frm_key_evt_struct *)event;

    MMI_BOOL isTurnOnBacklight;
    if(evt->key_code == KEY_HOME || vapp_screen_lock_is_switch_backlight_key(event))
    {
        isTurnOnBacklight =  MMI_TRUE;
    }
    else
    {
        isTurnOnBacklight = MMI_FALSE;
    }
    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_TURN_ON_BACKLIGHT_KEY, isTurnOnBacklight);
    return isTurnOnBacklight;
}


static MMI_BOOL vapp_screen_lock_is_volume_key(mmi_event_struct *event)
{
    mmi_frm_key_evt_struct *evt;
    evt = (mmi_frm_key_evt_struct *)event;

    MMI_BOOL isVolumeKey;
    if(evt->key_code == KEY_VOL_UP || evt->key_code == KEY_VOL_DOWN)
    {
        isVolumeKey =  MMI_TRUE;
    }
    else
    {
        isVolumeKey = MMI_FALSE;
    }
    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_IS_VOLUME_KEY, isVolumeKey);
    return isVolumeKey;
}


static mmi_ret vapp_screen_lock_handle_bootup_early_init(mmi_event_struct *event)
{
    vapp_screen_lock_sys_init();

    return MMI_RET_OK;
}


static mmi_ret vapp_screen_lock_handle_gpio_lcd_sleep_in(mmi_event_struct *event)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_GPIO_LCD_SLEEP_IN, 200);

    if(!vapp_screen_lock_is_exist() && vapp_screen_lock_is_allowed_launch())
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_GPIO_LCD_SLEEP_IN, 201);
        vapp_screen_lock_launch();
    }
    
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_block();
#endif

    return MMI_RET_OK;
}


static mmi_ret vapp_screen_lock_handle_gpio_lcd_sleep_out(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_unblock();
#endif

    // PXS may turn on backlight themself, it needs to reset flag in this case,
    // or key will still be blocked even in light backlight.
    if(VAPP_SCREEN_LOCK_HAS(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_FLAG))
    {
        VAPP_SCREEN_LOCK_CLR(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_FLAG);
    }

    return MMI_RET_OK;
}


#if defined(__MMI_CLAMSHELL__)
/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_handle_gpio_clam_open
 * DESCRIPTION
 *  This function handles the clam open event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret vapp_screen_lock_handle_gpio_clam_open(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_GPIO_CLAM_OPEN, 200);
    if (vapp_screen_lock_is_exist())
    {
        vapp_screen_lock_close();
    }
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    return MMI_RET_OK;
}
#endif /* defined(__MMI_CLAMSHELL__) */


static void vapp_screen_lock_turn_on_backlight(void)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_TURN_ON_BACKLIGHT, 200);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}


static mmi_ret vapp_screen_lock_handle_pre_key_routing(mmi_event_struct *event)
{
    VFX_DEV_ASSERT(event);
    mmi_frm_key_evt_struct *evt;
    evt = (mmi_frm_key_evt_struct *)event;

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_PRE_KEY_ROUTING, evt->key_code, 200);

    if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE &&
        evt->key_type == KEY_EVENT_DOWN)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_PRE_KEY_ROUTING, evt->key_code, 201);

        // UE: volume key works when backlight off
        //     backlight on after press volume key
        if(vapp_screen_lock_is_volume_key(event))
        {
            vapp_screen_lock_turn_on_backlight();
            VAPP_SCREEN_LOCK_CLR(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_FLAG);
            return MMI_RET_OK;
        }
      
        if(vapp_screen_lock_is_turn_on_backlight_key(event))
        {
            vapp_screen_lock_turn_on_backlight();
        }
        
        /* Block key event until the specific key(KEY_POWER, KEY_HOME) is released. */
        VAPP_SCREEN_LOCK_SET(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_FLAG);
        stopKeyRouting = MMI_TRUE;
        return MMI_RET_STOP_KEY_HANDLE;
    }
    
    /* Block key event until the key is released. */
    if (VAPP_SCREEN_LOCK_HAS(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_FLAG))
    {
        if (evt->key_type == KEY_EVENT_UP && vapp_screen_lock_is_turn_on_backlight_key(event))
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_PRE_KEY_ROUTING, evt->key_code, 202);
            VAPP_SCREEN_LOCK_CLR(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_FLAG);
        }
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_PRE_KEY_ROUTING, evt->key_code, 203);
        stopKeyRouting = MMI_TRUE;
        return MMI_RET_STOP_KEY_HANDLE;
    }

    if (evt->key_type == KEY_EVENT_UP && vapp_screen_lock_is_switch_backlight_key(event))
    {
        if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_TRUE)
        {          
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_PRE_KEY_ROUTING, evt->key_code, 300);
            lockMode = VAPP_SCREEN_LOCK_MODE_BY_POWER_KEY;
            srv_backlight_turn_off_ext();
            stopKeyRouting = MMI_TRUE;
            return MMI_RET_STOP_KEY_HANDLE;  
        }
    }

    // stop shutdown when screen lock
    if( vapp_screen_lock_is_locked() && 
        evt->key_type == KEY_EVENT_LONG_PRESS && 
        evt->key_code== KEY_POWER)
    {
        return MMI_RET_STOP_KEY_HANDLE;
    }
    return MMI_RET_OK;
}


static mmi_ret vapp_screen_lock_handle_post_key_routing(mmi_event_struct *event)
{
    if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE)
    {          
        if(!vapp_screen_lock_is_turn_on_backlight_key(event))
        {
            return MMI_RET_OK;
        }
    }

    if(stopKeyRouting)
    {
        stopKeyRouting = MMI_FALSE;
        return MMI_RET_OK;
    }

    /*
     * Turn on backlight if the handset is not shutdowning.
     * Workaound for backlight service, ref:MAUI_03103960
     */
    
    if (!srv_shutdown_is_running() && 
            ((mmi_frm_get_key_event_count() == 0)||
            (srv_backlight_get_timer_state() == SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE)))
    {
        vapp_screen_lock_turn_on_backlight();
    }

    return MMI_RET_OK;
}


static mmi_ret vapp_screen_lock_handle_pre_pen_routing(mmi_event_struct *event)
{
    mmi_multi_touch_event_struct *evt;
    evt = (mmi_multi_touch_event_struct *)event;
    mmi_touch_data_struct *touch_data;
    touch_data = evt->touch_data;
  
    if(touch_data->event == MMI_PEN_EVENT_ABORT)
    {
        return MMI_RET_OK;
    }
  
    // if query MAIN_LCD state: 0 = dark, 1 = half light, 2 = full light
    if((srv_backlight_get_lcd_state(SRV_BACKLIGHT_TYPE_MAINLCD) <= 1) &&
       (touch_data->event== MMI_PEN_EVENT_DOWN || touch_data->event == MMI_STROKE_DOWN))
    {
        /*
         * always turn on backlight, do not concern pen event type 
         */
        if(!srv_shutdown_is_running())
        {
            vapp_screen_lock_turn_on_backlight();
        }
        
        /* Block pen event until pen is released. */
        VAPP_SCREEN_LOCK_SET(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_PEN_FLAG);
        return MMI_RET_STOP_TOUCH_HANDLE;;
    }
    
    /* Block pen event until pen is released. */
    if (VAPP_SCREEN_LOCK_HAS(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_PEN_FLAG))
    {
        if (touch_data->event== MMI_PEN_EVENT_UP || touch_data->event == MMI_STROKE_UP)
        {
            VAPP_SCREEN_LOCK_CLR(VAPP_SCREEN_LOCK_BACKLIGHT_LOCKED_PEN_FLAG);
        }
        return MMI_RET_STOP_TOUCH_HANDLE;;
    }

    /*
     * always turn on backlight, do not concern pen event type 
     */
    if(!srv_shutdown_is_running())
    {
        vapp_screen_lock_turn_on_backlight();
    }
    return MMI_RET_OK;
}


static mmi_ret vapp_screen_lock_handle_launch_req(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_LAUNCH_REQ, 200);
    
    if(!vapp_screen_lock_is_exist() && vapp_screen_lock_is_allowed_launch())
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_HANDLE_LAUNCH_REQ, 201);
        vapp_screen_lock_launch();
    }

    return MMI_RET_OK;
}


extern "C" mmi_ret vapp_screen_lock_main_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = vapp_screen_lock_handle_bootup_early_init(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_IN:
            ret = vapp_screen_lock_handle_gpio_lcd_sleep_in(event);
            break;
            
        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            ret = vapp_screen_lock_handle_gpio_lcd_sleep_out(event);
            break;

        #if defined(__MMI_CLAMSHELL__)
            case EVT_ID_GPIO_CLAM_OPEN:
                ret = vapp_screen_lock_handle_gpio_clam_open(event);
                break;
        #endif /* defined(__MMI_CLAMSHELL__) */

        case EVT_ID_PRE_KEY_EVT_ROUTING:
            ret = vapp_screen_lock_handle_pre_key_routing(event);
            break;
            
        case EVT_ID_POST_KEY_EVT_ROUTING:
            ret = vapp_screen_lock_handle_post_key_routing(event);
            break;

        case EVT_ID_PRE_TOUCH_EVT_ROUTING:
            ret = vapp_screen_lock_handle_pre_pen_routing(event);
            break;

        case EVT_ID_VAPP_SCREEN_LOCK_LAUNCH_REQ:
            ret = vapp_screen_lock_handle_launch_req(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


extern "C" mmi_id vapp_screen_lock_get_group_id()
{
    return VAPP_SCREEN_LOCK;
}


/***************************************************************************** 
 * VappScreenLockApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockApp", VappScreenLockApp, VfxApp);


void VappScreenLockApp::onInit()
{
    VfxApp::onInit();

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
}


void VappScreenLockApp::onDeinit()
{
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);

    VfxApp::onDeinit();
}


VfxAppCloseAnswerEnum VappScreenLockApp::onProcessClose(VfxAppCloseOption options)
{
    return VFX_APP_CLOSE_ANSWER_NO;
}


void VappScreenLockApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappScreenLockScreen *scr;
    VFX_OBJ_CREATE(scr, VappScreenLockScreen, this);
    m_screenId = scr->show();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_APP_ON_RUN, m_screenId, 200);
    
    // Send screen locked event
    // Scenario: MAUI_03146061, for CBM Screen pop-up,
    mmi_event_struct evt;
    MMI_FRM_INIT_EVENT(&evt,EVT_ID_VAPP_SCREEN_LOCK_LOCKED_EVT);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


mmi_id VappScreenLockApp::getScreenId()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_APP_GET_SCREEN_ID, m_screenId, 200);
    return m_screenId;
}


void VappScreenLockApp::onGroupActive()
{
    VfxApp::onGroupActive();
    m_signalActive.emit();
}


void VappScreenLockApp::onGroupInactive()
{
    m_signalInactive.emit();
    VfxApp::onGroupInactive();
}


void VappScreenLockApp::onGroupSnapshotActive()
{
    VfxApp::onGroupSnapshotActive();
    m_signalSnapshotActive.emit();
}


void VappScreenLockApp::onGroupSnapshotInactive()
{
    VfxApp::onGroupSnapshotInactive();
    m_signalSnapshotInactive.emit();
}


/***************************************************************************** 
 * Adapt Function: To be removed
 *****************************************************************************/
extern "C" mmi_ret mmi_slk_main_evt_hdlr(mmi_event_struct *event)
{
    return MMI_RET_OK;
}

extern "C" mmi_ret mmi_ssv_main_evt_hdlr(mmi_event_struct *event)
{
    return MMI_RET_OK;
}


void mmi_scr_locker_start_manual_lock(U16 key_code)
{
}

void mmi_scr_locker_start_timer(void)
{
}

void mmi_scr_locker_restart_timer(void)
{
}

void mmi_scr_locker_stop_timer(void)
{
}

void mmi_scr_locker_suspend(void)
{
}

void mmi_scr_locker_resume(void)
{
}

MMI_BOOL mmi_scr_locker_is_locked(void)
{
    return vapp_screen_lock_is_locked();
}

mmi_scr_locker_type_enum mmi_scr_locker_get_type(void)
{
    return MMI_SCR_LOCKER_TYPE_INVALID;
}

void mmi_scr_locker_launch(void)
{
}

void mmi_scr_locker_launch_ex(mmi_scr_locker_type_enum type)
{
}

void mmi_scr_locker_close(void)
{
}

void mmi_scr_locker_turn_on_backlight(void)
{
    vapp_screen_lock_turn_on_backlight();
}

#if defined(__MMI_AUTO_KEYPAD_LOCK__)
mmi_ret mmi_scr_locker_secset_menu_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
#endif

void mmi_scr_saver_start_timer(void)
{}

void mmi_scr_saver_restart_timer(void)
{}

void mmi_scr_saver_stop_timer(void)
{}

MMI_BOOL mmi_scr_saver_is_active(void)
{
    return MMI_FALSE;
}

void mmi_scr_saver_launch(void)
{}

#if defined(__MMI_SCREEN_SAVER__)
void mmi_scr_saver_launch_ex(mmi_scr_saver_type_enum type)
{}
#endif

void mmi_scr_saver_close(void)
{}

void mmi_scr_saver_date_time_ind_hdlr(void)
{}

extern "C" U8 GetAutoKeypadLockTime(void)
{
   return 0;
}

