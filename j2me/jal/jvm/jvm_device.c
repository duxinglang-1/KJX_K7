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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  jvm_is_vibrate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#include "MMI_features.h"

#include "mmi_frm_gprot.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "mmiapi_struct.h"
#include "mmiapi_enum.h"
#include "mmiapi.h"
#include "jam_interface.h"
#include "jvm_adaptor.h"
#include "jvm_interface.h"
#include "j2me_trace.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_include.h"
#include "Gpiosrvgprot.h"   /* add for turn on/off backlight */
extern kal_uint8 GpioCtrlReq(kal_uint8 action);
extern kal_uint8 GpioPlayReq(kal_uint8 p_type, kal_uint8 p_level);
extern stack_timer_struct g_jam_vibrator_timer;
extern kal_mutexid g_jam_device_mutex;

static kal_bool vibrationPlaying = KAL_FALSE; 
//static kal_bool backlight_force_on = KAL_FALSE;
static kal_uint8 backlight_force_on = 0;
static kal_bool device_control = KAL_FALSE;
/***************************
 *  prototype
 ********************************/
static void jvm_send_vibrate_req(kal_bool on);

static volatile module_type jvm_device_mutex_tid = MOD_NIL;
static volatile int jvm_device_mutex_cnt = 0;

/*****************************************************************************
 * FUNCTION
 *  jvm_device_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_device_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_get_active_module_id() != jvm_device_mutex_tid)
    {
        kal_take_mutex(g_jam_device_mutex);
        jvm_device_mutex_tid = kal_get_active_module_id();
    }
    ++jvm_device_mutex_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_device_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_device_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jvm_device_mutex_tid == kal_get_active_module_id());

    --jvm_device_mutex_cnt;

    if (jvm_device_mutex_cnt == 0)
    {
        jvm_device_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_device_mutex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_is_vibrate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE:  is vibrating
 *  KAL_FALSE: do not vibrate
 *****************************************************************************/
kal_bool jvm_is_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_device_mutex_lock();
    result = vibrationPlaying;
    jvm_device_mutex_unlock();

    return result;
}

static kal_uint32 Vibrate_time = 0;

/*****************************************************************************
 * FUNCTION
 *  jvm_startVibrate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dursamples      [IN]        
 * RETURNS
 *  KAL_TRUE:     successful
 *  KAL_FALSE:    failed
 *****************************************************************************/
kal_bool jvm_startVibrate(int dursamples)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_device_mutex_lock();
    kal_trace(TRACE_GROUP_9, FUNC_JVM_START_VIBRATE_TIME, dursamples);
    if (jam_get_vib_on() && dursamples >= 1)
    {
        if(dursamples < 1000)
        {
            dursamples = 1000;
        }
        if (device_control)
        {
			vibrationPlaying = KAL_TRUE;
            kal_get_time(&Vibrate_time);        
            kal_trace(TRACE_GROUP_9, FUNC_JVM_START_VIBRATE_CURR_TIME, Vibrate_time);
            stack_start_timer(&g_jam_vibrator_timer, 1, dursamples >> 2);
            jvm_send_vibrate_req(KAL_TRUE);
            result = KAL_TRUE;
        }
    }
    jvm_device_mutex_unlock();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_stopVibrate_call_by_Jdaemon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE:     successful
 *  KAL_FALSE:    failed
 *****************************************************************************/
kal_bool jvm_stopVibrate_call_by_Jdaemon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_device_mutex_lock();
    kal_trace(TRACE_GROUP_9, FUNC_JVM_STOP_VIBRATE_JASN);    
    //MMI_PRINT(MOD_J2ME,TRACE_GROUP_9,"JVM: jvm_stopVibrate_call_by_Jdaemon");  
    if (jam_get_vib_on() && vibrationPlaying)
    {
        vibrationPlaying = KAL_FALSE;
        if (device_control)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_STOP_VIBRATE_JASN_HAVE_DEV);    
            stack_stop_timer(&g_jam_vibrator_timer);
            jvm_send_vibrate_req(KAL_FALSE);
        }
        result = KAL_TRUE;
    }
    jvm_device_mutex_unlock();
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_stopVibrate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE:     successful
 *  KAL_FALSE:    failed
 *****************************************************************************/
kal_bool jvm_stopVibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 v_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&v_time);
    kal_trace(TRACE_GROUP_9, FUNC_JVM_STOP_VIBRATE_CURR_TIME, v_time);      
    kal_trace(TRACE_GROUP_9, FUNC_JVM_STOP_VIBRATE_START_TIME, Vibrate_time);          
    if(v_time >= Vibrate_time)
    {
        if(TICK_2_MS((v_time - Vibrate_time)) < 1000)
        {   
            stack_stop_timer(&g_jam_vibrator_timer);  
            stack_start_timer(&g_jam_vibrator_timer, 1, MS_2_TICK(1000));            
        }
        else
        {
            jvm_stopVibrate_call_by_Jdaemon();
        }
    }
    else
    {
        ASSERT(0);
    }
    
    return KAL_TRUE;
    
}

/*****************************************************************************
 * FUNCTION
 *  jvm_IsBackLightOn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE:     back light is on
 *  KAL_FALSE:    back light is off
 *****************************************************************************/
kal_bool jvm_IsBackLightOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    return (kal_bool)srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD);	
}

/*****************************************************************************
 * FUNCTION
 *  jvm_BackLightOn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE:     successful
 *  KAL_FALSE:    failed
 *****************************************************************************/
kal_bool jvm_BackLightOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_device_mutex_lock();
    if (device_control)
    {
        if (!backlight_force_on)
        {
            if(jvm_IsBackLightOn())
            {
                srv_backlight_all_lcd_on();
            }
        }
        result = KAL_TRUE;
    }
    jvm_device_mutex_unlock();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_BackLightOff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE:     successful
 *  KAL_FALSE:    failed
 *****************************************************************************/
kal_bool jvm_BackLightOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_device_mutex_lock();
    if (!backlight_force_on)
    {
        if (device_control)
        {
            if(jvm_IsBackLightOn())
            {        	
                srv_backlight_all_lcd_off();
                result = KAL_TRUE;
            }                
        }
    }
    jvm_device_mutex_unlock();
    return result;
}

void jvm_send_backlight_ctrl_req(kal_uint8 on_off, kal_uint8 disable_timer);
/*****************************************************************************
 * FUNCTION
 *  jvm_GetDeviceControl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_resume       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_GetDeviceControl(kal_bool is_resume)   /* this function is run by MMI task */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jvm_device_mutex_lock();

    device_control = KAL_TRUE;

    if(jvm_IsBackLightOn())
    {
        srv_backlight_all_lcd_on();
    }
    if (!is_resume)
    {
        jvm_stopVibrate();
    }
    else if(vibrationPlaying)
    {
        jvm_send_vibrate_req(KAL_TRUE);
    }

    if(!is_resume)
    {
        jvm_force_backlight_on(KAL_FALSE);
    }
    else if(backlight_force_on)
    {
        //backlight_force_on--;
        //jvm_force_backlight_on(KAL_TRUE);
        jvm_send_backlight_ctrl_req(1, 1);
    }

    jvm_device_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jvm_ReleaseDeviceControl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_pause        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_ReleaseDeviceControl(kal_bool is_pause)    /* MMI */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jvm_device_mutex_lock();

    if (vibrationPlaying)
    {
        //GpioPlayReq(MMIAPI_DEV_TYPE_VIBRATOR, MMIAPI_DEV_LEVEL_0);
        jvm_send_vibrate_req(KAL_FALSE);
    }
    
    if(jvm_IsBackLightOn())
    {
        srv_backlight_all_lcd_on();
    }
    kal_trace(TRACE_GROUP_9, FUNC_JVM_RELEASE_DEVICE_CONTROL, backlight_force_on);

    
    if (backlight_force_on)
    {
        jvm_send_backlight_ctrl_req(1, 0);    		
        srv_backlight_turn_off();
    }

    device_control = KAL_FALSE;

    jvm_device_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jvm_send_vibrate_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_send_vibrate_req(kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_device_play_req_struct *p =
        (mmiapi_device_play_req_struct*) construct_local_para(sizeof(mmiapi_device_play_req_struct), TD_CTRL);
    module_type module = stack_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->src_mod_id = MOD_JASYN;
    p->type = MMIAPI_DEV_TYPE_VIBRATOR;

    if (on == KAL_FALSE)
    {
        p->level = MMIAPI_DEV_LEVEL_0;
    }
    else
    {
        p->level = MMIAPI_DEV_LEVEL_1;
    }

    if (module == MOD_J2ME)
    {
        module = MOD_JASYN;
    }
    java_send_msg(module,MOD_MMI,MMI_J2ME_SAP,MSG_ID_MMIAPI_DEVICE_PLAY_REQ,p);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_send_backlight_ctrl_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on_off              [IN]        
 *  disable_timer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_send_backlight_ctrl_req(kal_uint8 on_off, kal_uint8 disable_timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_backlight_control_req_struct *msg_p = (mmiapi_backlight_control_req_struct*)
        construct_local_para(sizeof(mmiapi_backlight_control_req_struct), TD_RESET);
    module_type module = stack_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->on_off = on_off;
    msg_p->disable_timer = disable_timer;

    if (module == MOD_J2ME)
    {
        module = MOD_JASYN;
    }

    java_send_msg(module, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMIAPI_BACKLIGHT_CONTROL_REQ, msg_p);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_force_backlight_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  force_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_force_backlight_on(kal_bool force_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    module_type mod_id = stack_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_device_mutex_lock();
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FORCE_BKLIGHT_ON, force_on,device_control);
        
    if (device_control)
    {
        if (force_on == KAL_TRUE)
        {
            /* TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);*/
        #ifdef __COSMOS_MMI_PACKAGE__
            /* turn backlight on permanently, and can be turn off when locking screen for cosmos */
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        #else
            jvm_send_backlight_ctrl_req( 1, 1);
        #endif
            backlight_force_on++;
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FORCE_BKLIGHT_ON_2, backlight_force_on);            
              
            
        }
        else if (force_on == KAL_FALSE && backlight_force_on > 0)
        {

            /* TurnOffBacklight(); */
            backlight_force_on--;
            if(!backlight_force_on)
            {
            #ifdef __COSMOS_MMI_PACKAGE__
                srv_backlight_turn_off();
            #else 
                jvm_send_backlight_ctrl_req(1, 0);
            #endif
            }                
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FORCE_BKLIGHT_ON_2, backlight_force_on);                         
            
        }
    }


    jvm_device_mutex_unlock();

    if (mod_id != MOD_MMI)
        kal_sleep_task(20); /* let mmi task to get message */
}


/*****************************************************************************
 * FUNCTION
 *  jvm_is_force_backlight_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  return if backlight on
 *****************************************************************************/

kal_bool jvm_is_force_backlight_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jvm_device_mutex_lock();
    result = (kal_bool)backlight_force_on;
    jvm_device_mutex_unlock();

    return result;
}



