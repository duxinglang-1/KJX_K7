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
 *  vapp_gpio_app.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Utility functions for GPIO
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "vapp_gpio_gprot.h"
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"
#include "MMI_include.h"
#include "MMI_common_app_trc.h"    
#include "MMIDataType.h"
#include "gui.h"
#include "wgui_categories_util.h"
#include "wgui_categories_CM.h"
#include "mmi_frm_events_gprot.h"
#include "gui_typedef.h"
#include "kal_general_types.h"
#include "BtcmSrvGprot.h"
#include "gdi_include.h"
#include "IdleAppDef.h"
#ifdef __MMI_ENGINEER_MODE__
#include "EngineerModeGprot.h"
#endif
#ifdef __MMI_FACTORY_MODE__
#include "FactoryModeProt.h"
#endif
#include "CommonScreens.h"    
    
#include "BootupSrvGprot.h"
#include "shutdownSrvGprot.h" 
#include "UcmSrvGprot.h"
#include "GpioSrvGprot.h"


#ifdef __cplusplus
}
#endif


/***************************************************************************** 
* Local variable
*****************************************************************************/

/***************************************************************************** 
* Local function
*****************************************************************************/


/***************************************************************************** 
* Global variable
*****************************************************************************/

/***************************************************************************** 
* External variable
*****************************************************************************/
#if ( defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
extern "C" U8 gCurrentMode;
#endif 

extern "C" void UI_BLT_double_buffer(S32 x1, S32 y1, S32 x2, S32 y2);

#ifdef __MMI_FACTORY_MODE__
extern "C" void FM_RestoreAudio(void);
#endif

/***************************************************************************** 
* External functitons
*****************************************************************************/

//This function update datetime area when LCD sleep out
static mmi_ret vapp_gpio_handle_lcd_sleep_out(mmi_event_struct *evt)
{
#ifdef __MMI_CABC__
    gdi_cabc_set_mode(gdi_cabc_get_mode());
#endif
	UI_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
	
	update_mainlcd_dt_display();
    update_sublcd_dt_display();

    wgui_cat020_update_duration();
    wgui_cat403_update_duration();
	
#if defined(__MMI_SUBLCD__)
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    mmi_frm_ui_force_update_now();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* (__MMI_SUBLCD__) */ 

    /* redraw main lcd */
    mmi_frm_ui_force_update_now();
	
    return MMI_RET_OK;
}


//This function mutes the phone i,e currently changing the global flag.
//This is a part of other hardware application.
static mmi_ret vapp_gpio_handle_mute_phone(mmi_event_struct *evt)
{
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_HANDLE_MUTE_PHONE, 1);
    wgui_status_icon_bar_show_icon(STATUS_ICON_MUTE); 
	return MMI_RET_OK;
}


//This function unmutes the phone i,e currently changing the global flag.
//This is a part of other hardware application.
static mmi_ret vapp_gpio_handle_unmute_phone(mmi_event_struct *evt)
{
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_HANDLE_MUTE_PHONE, 0);
    wgui_status_icon_bar_hide_icon(STATUS_ICON_MUTE);    
	return MMI_RET_OK;
}


//This function show earphone status icon when insert earphone
static mmi_ret vapp_gpio_handle_earphone_plug_in(mmi_event_struct *evt)
{
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_HANDLE_EARPHONE_PLUG, 1);
    
    // wired earphone and Bluetooth earphone will share one status icon
    wgui_status_icon_bar_show_icon(STATUS_ICON_EARPHONE_INDICATOR);	
	
    // in Cosmos, BD define no need poup earphone in/out    
	return MMI_RET_OK;
}


//This function disappear earphone status icon when remove earphone
static mmi_ret vapp_gpio_handle_earphone_plug_out(mmi_event_struct *evt)
{
    MMI_TRACE(VGPIO_TRC_INFO, TRC_VGPIO_HANDLE_EARPHONE_PLUG, 0);
    wgui_status_icon_bar_hide_icon(STATUS_ICON_EARPHONE_INDICATOR);
    
    // in Cosmos, BD define no need poup earphone in/out
	return MMI_RET_OK;
}


#ifdef __MMI_CLAMSHELL__

//Function for clam close go back to idle screen
static void vapp_gpio_clam_close_goto_idle(void)
{
#if (defined(__MMI_CLAMCLOSE_BACK2IDLE__))
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        if (srv_earphone_is_plug_in()
        #if defined(__MMI_BT_SUPPORT__)
            || srv_bt_cm_is_incall_aud_swap2bt() == MMI_TRUE
        #endif 
            )
            return;
    }

#ifdef __MMI_FACTORY_MODE__
    if (gCurrentMode == FACTORY_MODE)
    {
        FM_RestoreAudio();
        return;
    }
#endif /* __MMI_FACTORY_MODE__ */ 

    ClearKeyEvents();
    mmi_frm_send_key_event(KEY_END, KEY_EVENT_DOWN); // Back to idle in Main LCD

#ifdef __MMI_SUBLCD_MASTER_MODE__
    SubLCDMasterModeClamclosed();
#endif
	
#endif
}


//This function handle clamshell open
static mmi_ret vapp_gpio_handle_clam_open(mmi_event_struct *evt)
{
#ifdef __MMI_SUBLCD_MASTER_MODE__
    SubLCDMasterModeClamOpen();
#endif   

    if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_ALARM)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }

    if (!srv_bootup_is_booting())
    {
        if (srv_gpio_allow_clam_tone()&& mdi_audio_mma_is_idle())
        {
            srv_prof_play_tone(COVER_OPEN_TONE, NULL);
        }
    }

    return MMI_RET_OK;
}


//This function handle clamshell close
static mmi_ret vapp_gpio_handle_clam_close(mmi_event_struct *evt)
{
	if (!srv_bootup_is_booting())
    {
    #ifdef __MMI_SLIDE__
        if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_ALARM)
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        }
    #else
        vapp_gpio_clam_close_goto_idle();
        srv_backlight_close();
    #endif /* __MMI_SLIDE__ */ 

        if (srv_gpio_allow_clam_tone()&& mdi_audio_mma_is_idle())
        {
            srv_prof_play_tone(COVER_CLOSE_TONE, NULL);
        }
    }

    return MMI_RET_OK;
}

#endif



//This function is the main event handler of screen saver.
extern "C"
mmi_ret vapp_gpio_main_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret = MMI_RET_OK;

    switch (event->evt_id)
    {
        case EVT_ID_GPIO_EARPHONE_PLUG_IN:
            ret = vapp_gpio_handle_earphone_plug_in(event);
            break;

        case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
            ret = vapp_gpio_handle_earphone_plug_out(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            ret = vapp_gpio_handle_lcd_sleep_out(event);
            break;

        case EVT_ID_GPIO_MUTE_PHONE:
            ret = vapp_gpio_handle_mute_phone(event);
            break;

        case EVT_ID_GPIO_UNMUTE_PHONE:
            ret = vapp_gpio_handle_unmute_phone(event);
            break;

    #if defined(__MMI_CLAMSHELL__)
        case EVT_ID_GPIO_CLAM_OPEN:
            ret = vapp_gpio_handle_clam_open(event);
            break;

        case EVT_ID_GPIO_CLAM_CLOSE:
            ret = vapp_gpio_handle_clam_close(event);
            break;
    #endif /* defined(__MMI_CLAMSHELL__) */

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}

