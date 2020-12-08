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
 * mmi_gpio_backlight.c
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
 *------------------------------------------------------------------------------
  * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
  *============================================================================
  ****************************************************************************/
 
 /***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_include.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "custom_equipment.h"
#include "mmiapi_struct.h"

#include "mmi_frm_timer_gprot.h"
#include "device.h"
#include "TimerEvents.h"
#include "lcd_if.h"
#include "mdi_audio.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "wgui_categories_util.h"
#include "gui.h"
#include "stack_config.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi_msg_struct.h"
#include "kal_public_api.h"
#include "gdi_include.h"

#include "IdleAppGprot.h"
#include "BootupSrvGprot.h"
#include "GpioSrvGprot.h"
#include "GpioSrvprot.h"
#include "mmi_rp_srv_gpio_def.h"


typedef struct
{
    U8 mode;             /* 0: backlight is contrl by other AP */
    U8 is_timer_suspend; /* Is UI timer (aligned) suspended. 0 == non-suspend, 1 == suspend */
    U8 keypad_state;     /* 0 = dark. 1 = light */  
    U8 lcd_state;        /* 0 = dark, 1 = half light, 2 = full light  */
    U8 lcd_level;        /* 0: dark, 5: light */
    U8 lcd_real_level;   /* 0 - 5: from phnset */
    S32 hf_time;         /* time form full bright to half bright */
    S32 default_hf_time;
    U8 dim_time;         /* time form half bright to full drak */
    U8 default_dim_time;
    U8 sublcd_level;
    U8 sublcd_state;     /* 0 = dark, 1 = half light, 2 = full light  */
    srv_backlight_timer_state_enum timer_status;
} srv_backlight_context_struct;

static srv_backlight_context_struct g_mmi_gpio_context;
static srv_backlight_context_struct *g_gpio_p = &g_mmi_gpio_context;
//static MMI_BOOL g_srv_backlight_is_ctrl = MMI_FALSE; // if backlight is controled by other AP

/***************************************************************************** 
* Local variable
*****************************************************************************/
#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
static MMI_BOOL is_in_sleep_mode = MMI_FALSE;
#endif
static MMI_BOOL g_srv_backligit_is_sleeping = MMI_FALSE; // start sleep to full sleep
//static srv_backlight_timer_type_enum g_srv_backlight_pending_timer_type = SRV_BACKLIGHT_SHORT_TIME;
/***************************************************************************** 
* Local function
*****************************************************************************/
static void srv_backlight_lcd_sleep_in(void);
static void srv_backlight_lcd_sleep_out(void);
static void srv_backlight_timer_hdlr(void);
//static mmi_ret srv_backlight_pending_turn_on(mmi_event_struct *param);


/***************************************************************************** 
* Global function
*****************************************************************************/
#if defined(__CITY_EASY_WEB_DOG__)
extern U8 g_idle_sleep;
#if defined(__ACC_MAG_SUPPORT__)
extern void g_sensor_game_cb(BOOL result);
#endif /* __ACC_MAG_SUPPORT__ */

#endif /* __CITY_EASY_WEB_DOG__ */

/***************************************************************************** 
* External functitons
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_backlight_init_context_early
 * DESCRIPTION
 *  inti funciton, set the bl hf time and some status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_backlight_init_context_early(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	static MMI_BOOL is_init = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gpio_p->hf_time = g_gpio_p->default_hf_time;
    g_gpio_p->dim_time = g_gpio_p->default_dim_time = SRV_GPIO_BACKLIGHT_DIMMING_TIME/1000;
    g_gpio_p->mode = 1;
	if (is_init == MMI_FALSE)
	{
    	g_gpio_p->lcd_state = 1; // refer to CR solution
    	is_init = MMI_TRUE;
	}
    g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_resume_time
 * DESCRIPTION
 *  Wake up timer, if current no_aligemnt timer is suspended
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_backlight_resume_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gpio_p->is_timer_suspend == 1)
    {
        mmi_frm_resume_timers(TIMER_IS_NO_ALIGNMENT);
        g_gpio_p->is_timer_suspend = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gpio_turn_on_keypad_light
 * DESCRIPTION
 *  turn on keypad backlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_backlight_turn_on_keypad_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_clam_is_close() && !g_srv_gpio_property_info.keypad_locked)
    {
        if (0 == g_gpio_p->hf_time)
            return; // because backlight APP haven't finished init wrok, so needn't turn on
            
        srv_backlight_keypad_on();
        g_gpio_p->keypad_state = 1;
        
        StartTimer(GPIO_KEYPAD_LIGHT_TIMER, g_gpio_p->hf_time * 1000, srv_backlight_turn_off_keypad_light);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_turn_off_keypad_light
 * DESCRIPTION
 *  turn off keypad backlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_backlight_turn_off_keypad_light(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(GPIO_KEYPAD_LIGHT_TIMER);
    if (g_gpio_p->keypad_state == 1)
    {
        srv_backlight_keypad_off();
        g_gpio_p->keypad_state = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_lcd_sleep_in
 * DESCRIPTION
 *  Wake up LCM
 *  PARAMETERS:
 *  void
 *****************************************************************************/
#if defined(__OLDMAN_STYLE__)
extern U8 g_oldman_idle_sleep;
#endif
static void srv_backlight_lcd_sleep_in(void)
{
#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_in_sleep_mode == MMI_FALSE)
    {
       /* use emit(not post) to submit, because LCD sleep in should after app sleep in */
        srv_gpio_emit_event(EVT_ID_GPIO_LCD_SLEEP_IN);
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_SLEPP, 1, 0);
        lcd_sleep_in(MAIN_LCD);        
    #ifdef __MMI_SUBLCD__
        lcd_sleep_in(SUB_LCD);
    #endif
        is_in_sleep_mode = MMI_TRUE;
#if defined(__OLDMAN_STYLE__)
		g_oldman_idle_sleep = 1;
#endif
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_SLEPP, 1, 1);
    }
#endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */    
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_lcd_sleep_out
 * DESCRIPTION
 *  Sleep LCM
 * PARAMETERS:
 *  void
 *****************************************************************************/
static void srv_backlight_lcd_sleep_out(void)
{
#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_in_sleep_mode)
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_SLEPP, 0, 0);
        lcd_sleep_out(MAIN_LCD);        
    #ifdef __MMI_SUBLCD__
        lcd_sleep_out(SUB_LCD);
    #endif

        is_in_sleep_mode = MMI_FALSE;
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_SLEPP, 0, 1);

        srv_gpio_emit_event(EVT_ID_GPIO_LCD_SLEEP_OUT);

        gdi_layer_enter_draw_section(); // wait vrt non-blocking blt to finish, help Vrt Engine workaround
        gdi_layer_exit_draw_section();
        kal_sleep_task(8); // sleep 17ms, to wait blt finish, then GPIO can turn on backlight, help LCD blt workaround, and 2 tick for VRT
    }
#endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */        
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_enter_dimming_status
 * DESCRIPTION
 *  when Phone enter half mode, i will send primitive to UEM, if support 20 Level
 *  i will send GPIO_DEV_LED_BACKLIGHT_DIMMING, else send GPIO_DEV_LED_MAINLCD
 * PARAMETERS:
 *  void
 *****************************************************************************/
void srv_backlight_enter_dimming_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if (SRV_GPIO_BACKLIGHT_MAX_LEVEL > LED_LIGHT_LEVEL5)
    srv_gpio_set_device_level(GPIO_DEV_LED_BACKLIGHT_DIMMING, LED_LIGHT_LEVEL1);
else
    srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL1);
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_half_mode
 * DESCRIPTION
 *  Takes the Backlight to Half Mode
 *  (Backlit is dimmed but not black)
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void srv_backlight_half_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* [MMIGPIO]srv_backlight_turn_on(),SYNC_MODE=%d,timer_enum=%d,timer_status=%d,lcd_state=%d,sublcd_state=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_TURNON_BACKLIGHT,
                10, 10, g_gpio_p->timer_status, g_gpio_p->lcd_state, g_gpio_p->sublcd_state);    
    
    if (g_gpio_p->mode == 0)
        return;

    if (g_gpio_p->lcd_state == 0 && !srv_clam_is_close())   /* sleep mode */
    {
        srv_backlight_lcd_sleep_out();
        srv_backlight_enter_dimming_status();
        g_gpio_p->lcd_state = 1;
    }

#ifdef __MMI_SUBLCD__
    if (g_gpio_p->sublcd_state == 0)
    {
        srv_gpio_set_device_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
        g_gpio_p->sublcd_state = 2;
    }
#endif

    srv_backlight_resume_time();
    
    if (g_gpio_p->timer_status > SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE)
    {
        StartTimer(BACKLIGHT_TIMER, g_gpio_p->dim_time * 1000, srv_backlight_timer_hdlr);
        g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_to_sleep_mode
 * DESCRIPTION
 *  Takes the Backlight to black and let LCD to sleep in
 * PARAMETERS:
 *  void
 *****************************************************************************/
void srv_backlight_to_sleep_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* [MMIGPIO]srv_backlight_turn_off_all_light(),SYNC_MODE=%d,lcd_state=%d,sublcd_state=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_TURN_OFF_ALL_LIGHT,
                10, g_gpio_p->lcd_state, g_gpio_p->is_timer_suspend);

#ifdef __OP01_FWPBW__
    if (g_gpio_p->lcd_state != 0)
    { 
        srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
        g_gpio_p->lcd_state = 0;
    }
    return; /* In Fix Phone, don't sleep LCD and timer */
#endif

    g_srv_backligit_is_sleeping = MMI_TRUE; // start sleep
    
    if (g_gpio_p->lcd_state != 0) // modify from ==1 to !=0
    {   
        if (srv_gpio_emit_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN)) /* query if can turn off backlight */
        {
            srv_gpio_emit_event(EVT_ID_GPIO_BACKLIGHT_OFF); /* notify special APP do thing, like fancy animation */
            
            srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
            g_gpio_p->lcd_state = 0;
            srv_backlight_lcd_sleep_in();
            g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_IN_SLEEP_MODE;

            if (g_gpio_p->is_timer_suspend == 0  && srv_gpio_emit_event(EVT_ID_GPIO_AFTER_LCD_SLEEP_IN))
            {
                mmi_frm_suspend_timers(TIMER_IS_NO_ALIGNMENT);
                g_gpio_p->is_timer_suspend = 1;
            }
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_EXT, 1, 1); // some APP prevent turn off backlight
        /*
            g_srv_backligit_is_sleeping = MMI_FALSE;
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            return;
        */    
        }
    }

    g_srv_backligit_is_sleeping = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_turn_on_all_light
 * DESCRIPTION
 *  Turn on all light to whole bright
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
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
#ifndef __MMI_SYNC_LCD_GPIO_MODE__
/* under construction !*/
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
#ifndef __MMI_SYNC_LCD_GPIO_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_backlight_timer_hdlr
 * DESCRIPTION
 *  Timer handler to switch backlight state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_backlight_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* [MMIGPIO]srv_backlight_timer_hdlr(),SYNC_MODE=%d,timer_status=%d,lcd_state=%d,sublcd_state=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_BACKLIGHT_TIMER_HDLR,
                0, g_gpio_p->timer_status, g_gpio_p->lcd_state, g_gpio_p->sublcd_state);    

    if (g_gpio_p->mode == 0)
    {
        return;
    }

    if (g_gpio_p->timer_status == SRV_BACKLIGHT_TIMER_STATE_NO_TIMER) /* resume backlight mechanism */
    {
        g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
        StartTimer(BACKLIGHT_TIMER, g_gpio_p->hf_time * 1000, srv_backlight_timer_hdlr);
    }
    else if (g_gpio_p->timer_status == SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE)
    {
        if ( MMI_FALSE == srv_gpio_emit_event(EVT_ID_GPIO_BACKLIGHT_DIMMING))
        {
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_EXT, 2, 2); // some APP prevent dimming backlight
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            return;
        }
        
        if (g_gpio_p->lcd_state == 2) /* full light, switch to half light */
        {
            srv_backlight_enter_dimming_status();
            g_gpio_p->lcd_state = 1;
        }

        StartTimer(BACKLIGHT_TIMER, g_gpio_p->dim_time * 1000, srv_backlight_timer_hdlr);
        g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
    }
    else    /* g_gpio_p->timer_status == SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE */
    {
        srv_backlight_to_sleep_mode();
    }
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
void srv_backlight_turn_on(srv_backlight_timer_type_enum time_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*#ifdef __MMI_SYNC_LCD_GPIO_MODE__
    S32 opt_flag = 1;
#else
    S32 opt_flag = 0;
#endif*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* [MMIGPIO]srv_backlight_turn_on(),SYNC_MODE=%d,timer_enum=%d,timer_status=%d,lcd_state=%d,sublcd_state=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_TURNON_BACKLIGHT, time_enum, g_gpio_p->timer_status, g_gpio_p->lcd_state, g_gpio_p->sublcd_state);
#if defined(__CITY_EASY_WEB_DOG__)
#if defined(__ACC_MAG_SUPPORT__)
	if(g_idle_sleep == 1)
	{
		g_sensor_game_cb(KAL_TRUE);
	}
#endif /* __ACC_MAG_SUPPORT__ */
#endif /* __CITY_EASY_WEB_DOG__ */

    if (g_srv_backligit_is_sleeping)
    {
        //mmi_event_struct evt;
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_EXT, 3, 3); // post to turn on backlight
    /*
        g_srv_backlight_pending_timer_type = time_enum;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_GPIO_PENDING_TRUN_ON_BLT);
        MMI_FRM_POST_EVENT(&evt, srv_backlight_pending_turn_on, NULL);
    */
        return;
    }
    if (time_enum != SRV_BACKLIGHT_PERMANENT)
    {
        srv_backlight_turn_on_keypad_light();
    }

    if (g_gpio_p->mode == 0)
    {
        return;
    }

    srv_backlight_resume_time();

    /* [MMIGPIO]srv_backlight_turn_on(),lcd_state=%d,clam_is_close=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_TURNON_BACKLIGHT_CHECK_CLAM,
                g_gpio_p->lcd_state, srv_clam_is_close());

    if (g_gpio_p->lcd_state == 0)
    {
        srv_backlight_lcd_sleep_out();
        srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        g_gpio_p->lcd_state = 2;
    }
    else if (g_gpio_p->lcd_state == 1)
    {
        srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        g_gpio_p->lcd_state = 2;
    }
    else if (g_gpio_p->lcd_state == 2)
    {
        srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    }
    srv_gpio_emit_event(EVT_ID_GPIO_BACKLIGHT_ON); /* notify special APP do thing, like screenlock */
   
#ifdef __MMI_SUBLCD__
   if (g_gpio_p->sublcd_state == 0)
   {
       srv_backlight_lcd_sleep_out();
       srv_gpio_set_device_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
       g_gpio_p->sublcd_state = 2;
   }
#endif

    /* start/stop timer according to input parameter */
    if (time_enum == SRV_BACKLIGHT_PERMANENT)
    {
        StopTimer(BACKLIGHT_TIMER);
        g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_NO_TIMER;
    }
    else if (g_gpio_p->timer_status != SRV_BACKLIGHT_TIMER_STATE_NO_TIMER)    /* start a timer */
    {
        if (!srv_clam_is_close()) // open status
        {
            StartTimer(BACKLIGHT_TIMER, g_gpio_p->hf_time * 1000, srv_backlight_timer_hdlr);
            g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
        }
        else 
        {
            StartTimer(BACKLIGHT_TIMER, g_gpio_p->dim_time * 1000, srv_backlight_timer_hdlr);
            g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
        }
    }
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
void srv_backlight_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* [MMIGPIO]srv_backlight_close(),SYNC_MODE=%d,timer_status=%d,lcd_state=%d,sublcd_state=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_CLOSE_BACKLIGHT,
                 1, g_gpio_p->timer_status, g_gpio_p->lcd_state, g_gpio_p->sublcd_state);
    
#if defined(__MMI_SYNC_LCD_GPIO_MODE__)
    
    if (g_gpio_p->mode == 0)
    {
        return;
    }

    srv_backlight_lcd_sleep_out(); // should sleep out, if current is sleep in
    srv_backlight_resume_time();
    
    srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);        
    g_gpio_p->lcd_state = 2;
#ifdef __MMI_SUBLCD__
    srv_gpio_set_device_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
    g_gpio_p->sublcd_state = 2;
#endif

    srv_backlight_turn_off_keypad_light();
    StartTimer(BACKLIGHT_TIMER, g_gpio_p->dim_time * 1000, srv_backlight_timer_hdlr);
    g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;

#else /* __MMI_SYNC_LCD_GPIO_MODE__ */
    srv_backlight_turn_off_ext();
#endif /* __MMI_SYNC_LCD_GPIO_MODE__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_pending_turn_on
 * DESCRIPTION
 *  Some AP want to turn on backlight, while GPIO is turning off backlight, so i
 *  will post event to turn on backlight, else will happen write screen...
 * PARAMETERS: void
 *  void
 *****************************************************************************/
/*static mmi_ret srv_backlight_pending_turn_on(mmi_event_struct *param)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_BACKLIGHT_EXT, 4, g_srv_backlight_pending_timer_type);
    srv_backlight_turn_on(g_srv_backlight_pending_timer_type);
    return MMI_RET_OK;
}
*/

/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
void srv_backlight_turn_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* [MMIGPIO]srv_backlight_turn_off(),SYNC_MODE=%d,timer_status=%d,lcd_state=%d,sublcd_state=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_TURN_OFF_BACKLIGHT,
                0, g_gpio_p->timer_status, g_gpio_p->lcd_state, g_gpio_p->sublcd_state);
        
    /* IMY or AT command disables backlight mechanism */
    if (g_gpio_p->mode == 0)
    {
        return;
    }

    if (g_gpio_p->timer_status == SRV_BACKLIGHT_TIMER_STATE_NO_TIMER) /* resume backlight timer mechanism */
    {
        srv_backlight_turn_on_keypad_light();
        StartTimer(BACKLIGHT_TIMER, g_gpio_p->hf_time * 1000, srv_backlight_timer_hdlr);
        g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE;
    }
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
void srv_backlight_turn_off_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* [MMIGPIO]srv_backlight_turn_off(),SYNC_MODE=%d,timer_status=%d,lcd_state=%d,sublcd_state=%d */
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_TURN_OFF_BACKLIGHT,
                10, g_gpio_p->timer_status, g_gpio_p->lcd_state, g_gpio_p->sublcd_state);
    
    /* AT command disables backlight mechanism */
    if (g_gpio_p->mode == 0)
    {
        return;
    }

    /* turn off keypad backlight */
    srv_backlight_turn_off_keypad_light();

#ifdef __MMI_SUBLCD__
    /* turn on sub-lcd baclight */
    if (g_gpio_p->sublcd_state != 0)
    {
        srv_gpio_set_device_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL0);
        g_gpio_p->sublcd_state = 0;
    }
#endif

    /* turn off main-lcd backlight */
    if (g_gpio_p->lcd_state != 0)
    {
        g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE;
        StopTimer(BACKLIGHT_TIMER);
        srv_backlight_timer_hdlr();  
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
/*****************************************************************************
 * FUNCTION
 *  srv_backlight_lcd_keypad_off
 * DESCRIPTION
 *  srv_backlight_lcd_keypad_off
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS:
 *  void
 *****************************************************************************/
void srv_backlight_lcd_keypad_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TIMER_KEYPAD_BACKLIGHT);
    srv_backlight_all_lcd_off();
    srv_backlight_keypad_off();
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_mode_exe
 * DESCRIPTION
 *  Sets BackLight Mode
 *  
 *  PARAMETERS: void
 *  mode        [IN]        
 *****************************************************************************/
void srv_backlight_set_mode_exe(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == 1)  /* enable backlight mechanism. */
    {
        g_gpio_p->mode = mode;
        srv_backlight_turn_off();
    }
    else    /* disable backlight mechanism. */
    {
        g_gpio_p->mode = 1;
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        g_gpio_p->mode = mode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_mode
 * DESCRIPTION
 *  Protocol Handler for MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND
 *  
 *  PARAMETERS: info: Data from L4
 *  info        [IN]        
 *****************************************************************************/
void srv_backlight_set_mode(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_sleep_mode_req_ind_struct *msg = (mmi_eq_set_sleep_mode_req_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_set_mode_exe((U8) msg->on_off);
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_timer_int
 * DESCRIPTION
 *
 *  SET_TIMER_DEFAULT is only used by GPIO setting.
 *
 *  If App wants set backlight permanent bright timer, should use SET_TIMER_PERMANENT,
 *  and pass 0 to the 2nd and 3rd parameter
 *  If App wants customize backlight timer, should use SET_TIMER_BY_APP, App can only
 *  set hf_time, or only set dim_time, or both; pass 0 to the 2nd or 3rd paramenter means
 *  don't customize this filed.
 *
 *  Must notes: 
 *  After SET_TIMER_PERMANENT, caller should remerber to call this API to RESTORE_TIMER_PERMANENT 
 *  After SET_TIMER_BY_APP, caller should remerber to call this API to RESTORE_TIMER_BY_APP
 *
 * PARAMETERS
 *  type          [IN]        
 *  hf_time       [IN]
 *  dim_time      [IN]      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_backlight_set_timer_int(srv_backlight_set_timer_type_enum type, U32 hf_time, U8 dim_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_8, "srv_backlight_set_timer_int,type=%d,hf_time=%d,dim_time=%d", type, hf_time, dim_time);
    if (type == SRV_BACKLIGHT_SET_TIMER_BY_APP)
    {
		if (hf_time == 0 && dim_time == 0)
			return;
        g_gpio_p->hf_time = hf_time;
        g_gpio_p->dim_time = dim_time;
    }
    else if (type == SRV_BACKLIGHT_RESTORE_TIMER_BY_APP)
    {
        g_gpio_p->hf_time = g_gpio_p->default_hf_time;
        g_gpio_p->dim_time = g_gpio_p->default_dim_time;        
    }
    else if (type == SRV_BACKLIGHT_SET_TIMER_PERMANENT)
    {
        StopTimer(BACKLIGHT_TIMER);
        g_gpio_p->timer_status = SRV_BACKLIGHT_TIMER_STATE_NO_TIMER;
    }    
    else if (type == SRV_BACKLIGHT_RESTORE_TIMER_PERMANENT)
    {
        srv_backlight_turn_off();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_hf_time
 * DESCRIPTION
 *  set the bl hf time
 * PARAMETERS
 *  action          [IN]        
 *  Action(?)       [IN]        Battery_sttus
 * RETURNS
 *  void
 *****************************************************************************/
void srv_backlight_set_hf_time(srv_backlight_set_timer_type_enum type, S32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == SRV_BACKLIGHT_SET_TIMER_DEFAULT)
    {    
        g_gpio_p->hf_time =  g_gpio_p->default_hf_time = 15;//time;        
    }
    else if (type == SRV_BACKLIGHT_SET_TIMER_BY_APP)
    {
        g_gpio_p->hf_time = 15;  //time;
    }
    else
    {
        ASSERT(0);
    }    
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
S32 srv_backlight_get_hf_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gpio_p->hf_time;
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
U8 srv_backlight_get_level(srv_backlight_device_type_enum lcd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_backlight_get_real_level(lcd_type);
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
void srv_backlight_set_real_level(srv_backlight_device_type_enum lcd_type, U8 level)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL needEmit = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_type == SRV_BACKLIGHT_TYPE_MAINLCD)
    {
		if (g_gpio_p->lcd_real_level != level)
    	{
    		needEmit = MMI_TRUE;
    	}

        g_gpio_p->lcd_real_level = level;
    }
    else if (lcd_type == SRV_BACKLIGHT_TYPE_SUBLCD)
    {
        g_gpio_p->sublcd_level = level;
    }
    else
    {
    }
    
	if (needEmit == MMI_TRUE)
		srv_gpio_emit_event(EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_get_level_from_setting
 * DESCRIPTION
 *  get current backlight level  
 *  PARAMETERS: 
 *  lcd_type    [IN]        lcd type
 *  RETURNS
 *  real backlight level.
 *****************************************************************************/
U8 srv_backlight_get_real_level(srv_backlight_device_type_enum lcd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_type == SRV_BACKLIGHT_TYPE_MAINLCD)
    {
        return g_gpio_p->lcd_real_level;
    }
    else if (lcd_type == SRV_BACKLIGHT_TYPE_SUBLCD)
    {
        return g_gpio_p->sublcd_level;
    }
    else if (lcd_type == SRV_BACKLIGHT_TYPE_KEYPAD)
    {
        if (g_gpio_p->keypad_state == 1)
            return (U8)LED_LIGHT_LEVEL5;
        else
            return (U8)LED_LIGHT_LEVEL0;
    }
    return 0;
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
srv_backlight_timer_state_enum srv_backlight_get_timer_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gpio_p->timer_status;
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
MMI_BOOL srv_backlight_is_on(srv_backlight_device_type_enum lcd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret=MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(lcd_type)
    {
        case SRV_BACKLIGHT_TYPE_MAINLCD:
        {
            if (g_gpio_p->lcd_state != 0)
            {
                ret = MMI_TRUE;
            }
            break;
        }
        case SRV_BACKLIGHT_TYPE_SUBLCD:
        {
            if (g_gpio_p->sublcd_state != 0)
            {
                ret = MMI_TRUE;
            }
            break;
        }
        case SRV_BACKLIGHT_TYPE_KEYPAD:
        {
            if (g_gpio_p->keypad_state != 0)
            {
                ret = MMI_TRUE;
            }
            break;
        }
        default:
            break;
    }

    return ret;
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
S32 srv_backlight_get_lcd_state(srv_backlight_device_type_enum lcd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(lcd_type)
    {
        case SRV_BACKLIGHT_TYPE_MAINLCD:
        {
            return g_gpio_p->lcd_state;
           // break;
        }
        case SRV_BACKLIGHT_TYPE_SUBLCD:
        {
            return g_gpio_p->sublcd_state;
          //  break;
        }
        case SRV_BACKLIGHT_TYPE_KEYPAD:
        {
            return g_gpio_p->keypad_state;
         //   break;
        }
        default:
        {
            return 0;
         //   break;
        }
    }
}


/*--------------------------------------------------------------------------*/
/* Please refer to GpioSrvGprot.h                                           */
/*--------------------------------------------------------------------------*/
MMI_BOOL srv_backlight_is_lcd_sleep(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
    return is_in_sleep_mode;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_at_set_level_hdlr
 * DESCRIPTION
 *  AT command set backlight level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_backlight_at_set_level_hdlr(void *msg, int source, void *data)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *rsp;
    mmi_eq_exe_gpio_level_req_ind_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmi_eq_exe_gpio_level_req_ind_struct*) msg;
    rsp = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    switch(req->gpio_dev_type)
    {
        case GPIO_DEV_LED_MAINLCD:
        {
            rsp->result = KAL_TRUE;
            
            if (req->gpio_dev_level == 0)
            {
                srv_backlight_close();
                srv_backlight_turn_off();
            }
            else if (req->gpio_dev_level == 5)
            {
                if (req->duration == 0xFFFF)
                {
                    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
                }
                else if (srv_backlight_get_timer_state() == SRV_BACKLIGHT_TIMER_STATE_NO_TIMER)
                {
                    /* backlight turn on permanent */
                    rsp->result = KAL_FALSE;
                }
                else
                {
                    if (req->duration == 0)
                    {
                        g_gpio_p->hf_time =  g_gpio_p->default_hf_time;
                        
                        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
                    }                
                    else
                    {
                        g_gpio_p->hf_time = (S32)req->duration;
                        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
                    }
                }
            }
            else
            {
                rsp->result = KAL_FALSE;
            }
            
            break;
        }

        default:
            rsp->result = KAL_FALSE;
            break;
    }

    srv_gpio_send_message(source, MSG_ID_MMI_AT_GENERAL_RES_REQ, (void*)rsp, NULL);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_at_query_level_hdlr
 * DESCRIPTION
 *  AT command set backlight level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_backlight_at_query_level_hdlr(void *msg, int source, void *data)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_cbklt_query_res_req_struct *rsp;
    MMI_BOOL backlight_on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    rsp = (mmi_at_cbklt_query_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_cbklt_query_res_req_struct));
   
    backlight_on = srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD);
    
    if (backlight_on)
        rsp->level = 5;
    else
        rsp->level = 0;

    if (srv_backlight_get_timer_state() == SRV_BACKLIGHT_TIMER_STATE_NO_TIMER)
    {
        rsp->duration = 0xFFFF;
    }
    else if (g_gpio_p->hf_time ==  g_gpio_p->default_hf_time)
    {
        rsp->duration = 0;
    }
    else
    {
        rsp->duration = g_gpio_p->hf_time;
    }

    srv_gpio_send_message(source, MSG_ID_MMI_AT_CBKLT_QUERY_RES_REQ, (void*)rsp, NULL);
#endif    
}

