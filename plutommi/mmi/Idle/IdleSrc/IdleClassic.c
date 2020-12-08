/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  IdleClassic.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the classic idle screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "DialerGprot.h"
#include "PhoneSetupGprots.h"
#include "PhoneSetup.h"
#ifdef __MMI_OP01_DCD__
#include "DCDGprot.h"
#endif
#include "browser_api.h"
#include "UmGprot.h"
#include "CallLogGprot.h"
#include "AudioPlayerProt.h"

#if defined(__MMI_SEARCH_WEB_GOOGLE__)
#include "SearchWebGProt.h"
#endif

// TODO: phase out this.
#include "IdleAppProt.h"

// auto add by kw_check begin
#include "IdleClassic.h"
#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "IdleMain.h"
#include "mmi_rp_app_idle_def.h"
#include "wgui_categories_idlescreen.h"
#include "IdleObject.h"
#include "GlobalResDef.h"
#include "gui_effect_oem.h"
#include "IdleCommon.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "Unicodexdcl.h"
#include "IdleGprot.h"
#ifdef __KJX_FUN__
#include "mmi_rp_app_kjx_def.h"
#include "kjx_main.h"
#endif
// auto add by kw_check end 

#ifndef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
#include "ScrLockerGprot.h"
#endif


#ifdef __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__

/****************************************************************************
 * Function
 ****************************************************************************/

#if defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_classic_set_icon_shct
 * DESCRIPTION
 *  This function sets the handler for the idle icon shortcuts.
 * PARAMETERS
 *  idx         : [IN]      Index of the icon shortcut
 *  hdlr        : [IN]      Handler associated with this shortcut icon
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_classic_set_icon_shct(
                mmi_idle_classic_struct *obj,
                S32 idx,
                U16 img_up,
                U16 img_down,
                U16 hint,
                FuncPtr hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj && idx >= 0 && idx < MMI_IDLE_CLASSIC_MAX_ICON_SHORTCUT);

    obj->icon_shct_up[idx]   = (PU8)get_image(img_up);
    obj->icon_shct_down[idx] = (PU8)get_image(img_down);
    obj->icon_shct_hint[idx] = (PU8)get_string(hint);
    obj->icon_shct_hdlr[idx] = hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_classic_exec_icon_shct
 * DESCRIPTION
 *  This function executes the handler for the idle icon shortcuts.
 * PARAMETERS
 *  idx         : [IN]      Index of the shortcut to be launched
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_classic_exec_icon_shct(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_classic_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (mmi_idle_classic_struct *)mmi_idle_get_obj();

    MMI_ASSERT(obj && idx >= 0 && idx < MMI_IDLE_CLASSIC_MAX_ICON_SHORTCUT);

    if (obj->icon_shct_hdlr[idx])
    {
        obj->icon_shct_hdlr[idx]();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_classic_init_icon_shct
 * DESCRIPTION
 *  This function enables the idle screen icon shortcuts functionality. The
 *  parameters passed to WGUI must be static because WGUI does not internally
 *  save it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_classic_init_icon_shct(mmi_idle_classic_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Audio player:
     */
#if defined(__MMI_AUDIO_PLAYER__)
    mmi_idle_classic_set_icon_shct(
        obj,
        idx,
        IMG_ID_IDLE_ICON_SHORTCUT_AUDIO_UP,
        IMG_ID_IDLE_ICON_SHORTCUT_AUDIO_DOWN,
        STR_ID_IDLE_ICON_SHORTCUT_HINT_AUDIO,
        mmi_audply_entry_main);
    ++idx;
#endif /* defined(__MMI_AUDIO_PLAYER__) */

    /*
     * Browser:
     */
#if defined(BROWSER_SUPPORT)
    mmi_idle_classic_set_icon_shct(
        obj,
        idx,
        IMG_ID_IDLE_ICON_SHORTCUT_BROSWER_UP,
        IMG_ID_IDLE_ICON_SHORTCUT_BROSWER_DOWN,
        STR_ID_IDLE_ICON_SHORTCUT_HINT_BROWSER,
        goto_mobile_suite_screen);
    ++idx;
#endif /* defined(BROWSER_SUPPORT) */

    /*
     * Dial pad:
     */
    mmi_idle_classic_set_icon_shct(
        obj,
        idx,
        IMG_ID_IDLE_ICON_SHORTCUT_DIAL_UP,
        IMG_ID_IDLE_ICON_SHORTCUT_DIAL_DOWN,
        STR_ID_IDLE_ICON_SHORTCUT_HINT_DIAL,
        mmi_dialer_launch);
    ++idx;

    /*
     * Message:
     */
#if defined(__MOD_SMSAL__)
    mmi_idle_classic_set_icon_shct(
        obj,
        idx,
        IMG_ID_IDLE_ICON_SHORTCUT_MG_UP,
        IMG_ID_IDLE_ICON_SHORTCUT_MG_DOWN,
        STR_ID_IDLE_ICON_SHORTCUT_HINT_MG,
        mmi_um_entry_main_message_menu);
    ++idx;
#endif /* defined(__MOD_SMSAL__) */

    /*
     * Call log:
     */
    mmi_idle_classic_set_icon_shct(
        obj,
        idx,
        IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_UP,
        IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_DOWN,
        STR_ID_IDLE_ICON_SHORTCUT_HINT_ALL_CALLS,
        mmi_clog_sendkey_launch);
    ++idx;

    if (idx > 0)
    {
        wgui_cat033_enable_icon_shortcut_bar_display(
            idx,
            mmi_idle_classic_exec_icon_shct,
            obj->icon_shct_hint,
            obj->icon_shct_down,
            obj->icon_shct_up);
    }
}
#endif /* defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__) */


#if defined(__MMI_SEARCH_WEB_GOOGLE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_classic_search_bar_trigger_by_touch_hdlr
 * DESCRIPTION
 *  Trigger search application when search bar is touched.
 *****************************************************************************/
static void mmi_idle_classic_search_bar_trigger_by_touch_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_search_web_trigger_by_hot_key(MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT);
}
#endif

#if defined(__HEART_RATE_SUPPORT__)
#ifndef WIN32
extern void pah8001_sensor_main(void);
extern void TimeISR();
S32 sensor_flag = 0;
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_classic_on_enter
 * DESCRIPTION
 *  This function enters the idle screen.
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_classic_on_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_classic_struct *p;
#if defined(__MMI_SEARCH_WEB_GOOGLE__)
    const U8 *image;
    const WCHAR *string;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    p = (mmi_idle_classic_struct *)obj;

#if defined(MMI_IDLE_CLASSIC_CSK_SUPPORT)
    EnableCenterSoftkey(0, IMG_GLOBAL_DIAL_PAD_CSK);
#endif

#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
    if (PhnsetGetCalendarIdleScreen())
    {
        idle_screen_enable_calendar_display();
    }
#endif /* defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) */

#ifdef __MMI_OP01_DCD__
    if (mmi_dcd_is_switch_on())
    {
        mmi_dcd_entry_idlescreen();
    }
#endif /* __MMI_OP01_DCD__ */

#if defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
    mmi_idle_classic_init_icon_shct(p);
#endif

#if defined(__MMI_SEARCH_WEB_GOOGLE__)
    if(mmi_search_web_get_idle_hint(&image, &string))
    {
        idle_screen_enable_search_bar(image, string, mmi_idle_classic_search_bar_trigger_by_touch_hdlr);
    }
#endif

    gui_sse_setup_scenario(GUI_SSE_SCENARIO_ENTER_IDLE);

    ShowCategory33Screen(
        STR_ID_IDLE_MAIN_MENU,
        0,
        STR_ID_IDLE_CONTACT,
        0,
        NULL);

    mmi_idle_set_handler((mmi_idle_obj_struct *)p);

    mmi_phnset_save_wallpaper_to_speedup();

    ClearKeyEvents();

    mmi_idle_sublcd_display();

#ifndef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
    if(mmi_scr_locker_is_locked())
    {
        // softkey needs to update after show category
        // TODO: framework should emit the event after show category
        // then update can be done by scrlocker self.
        wgui_softkey_update();
    }
#endif

#if defined(__HEART_RATE_SUPPORT__)
#ifndef WIN32
{
	if(sensor_flag == 0)
	{
		sensor_flag = 1;
		pah8001_sensor_main();
	}
}
#endif
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_classic_on_update_service_indication
 * DESCRIPTION
 *  This function updates the service indication.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_MAINLCD_96X64__

void mmi_idle_classic_on_update_service_indication(mmi_idle_obj_struct *obj)
{
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM <= 2)
	 mmi_idle_service_indication_struct *service_indication;
	 WCHAR *str, *str2;
 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 mmi_idle_update_service_indication_context(obj);
 
	 service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM1); 
	 str = (mmi_wcslen(service_indication->line1) ? service_indication->line1 : NULL);	 
  
#if (MMI_MAX_SIM_NUM == 2)
	 service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM2); 
	 str2 = (mmi_wcslen(service_indication->line1) ? service_indication->line1 : NULL);
	 str = mmi_wcscat(str, L"   ");
	 str = mmi_wcscat(str, str2);
#endif /* (MMI_MAX_SIM_NUM == 2) */

	 SetIdleScreenNetworkName((U8 *)str);
 
	 /*
	  * TODO: category should export the API to update it specifically. Should
	  * 	  not duplicate the dispatching condition in the function.
	  */
#endif
	 idle_screen_show_network_details();
 
}

#else
void mmi_idle_classic_on_update_service_indication(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__BOSCH_BMP280_PRESSURE__)
	extern WCHAR Temp_show[128];
	extern WCHAR Altitude_show[128];
#endif
#if defined(__KJX_FUN_STEPS__)
	extern WCHAR Step_show[128];
	extern WCHAR Calorie_show[128];
#endif

#if (MMI_MAX_SIM_NUM <= 2)
    mmi_idle_service_indication_struct *service_indication;
    WCHAR *str;

	extern void SetIdleScreenSlaveNetworkName(U8 *s);
	extern void SetIdleScreenSlaveNetworkStatus(U8 *s);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_update_service_indication_context(obj);

    service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM1);

    str = (mmi_wcslen(service_indication->line1) ? service_indication->line1 : NULL);
    SetIdleScreenNetworkName((U8 *)str);

    str = (mmi_wcslen(service_indication->line2) ? service_indication->line2 : NULL);
    SetIdleScreenNetworkStatus((U8 *)str);

#if (MMI_MAX_SIM_NUM == 2)
    service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM2);

    str = (mmi_wcslen(service_indication->line1) ? service_indication->line1 : NULL);
    SetIdleScreenSlaveNetworkName((U8 *)str);

    str = (mmi_wcslen(service_indication->line2) ? service_indication->line2 : NULL);
    SetIdleScreenSlaveNetworkStatus((U8 *)str);
#endif /* (MMI_MAX_SIM_NUM == 2) */

    /*
     * TODO: category should export the API to update it specifically. Should
     *       not duplicate the dispatching condition in the function.
     */
#endif

#if defined(__KJX_FUN__)	//xb add 2017-07-18
	SetIdleScreenNetworkName(NULL);
	//SetIdleScreenNetworkStatus((U8 *)GetString(STR_KJX_IDLE_SHOW_TOUR));
	SetIdleScreenNetworkStatus((U8 *)g_kjx_titlestr);
#ifdef __KJX_WEATHER_SUPPORT__
	SetIdleScreenSlaveNetworkName(NULL);
	SetIdleScreenSlaveNetworkStatus((U8 *)Temp_show);
#elif defined(__BOSCH_BMP280_PRESSURE__)
	//温度
	if(mmi_ucs2strlen((S8*)Temp_show) <= 0)
	{
		mmi_ucs2cpy((CHAR*)Temp_show, (CHAR*)GetString(STR_KJX_IDLE_TEMPERATURE));
		mmi_ucs2cat((CHAR*)Temp_show, (CHAR*)L"0 C");
	}
	//海拔
	if(mmi_ucs2strlen((S8*)Altitude_show) <= 0)
	{
		mmi_ucs2cpy((CHAR*)Altitude_show, (CHAR*)GetString(STR_KJX_IDLE_ALTITUDE));
		mmi_ucs2cat((CHAR*)Altitude_show, (CHAR*)L"0 M");
	}
#endif

#if defined(__KJX_FUN_STEPS__)
	//计步
	if(mmi_ucs2strlen((S8*)Step_show) <= 0)
	{
		mmi_ucs2cpy((CHAR*)Step_show, (CHAR*)GetString(STR_KJX_IDLE_STEP));
		mmi_ucs2cat((CHAR*)Step_show, (CHAR*)L"0 STEP");
	}
	//卡路里
	if(mmi_ucs2strlen((S8*)Calorie_show) <= 0)
	{
		mmi_ucs2cpy((CHAR*)Calorie_show, (CHAR*)GetString(STR_KJX_IDLE_CALORIE));
		mmi_ucs2cat((CHAR*)Calorie_show, (CHAR*)L"0 CAL");
	}
#endif

#endif

    idle_screen_show_network_details();
}
#endif /*__MMI_MAINLCD_96X64__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_classic_on_init
 * DESCRIPTION
 *  This function initializes the idle object.
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_classic_on_init(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_classic_struct *p;
#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    U32 *capability;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_on_init(obj);

    p = (mmi_idle_classic_struct *)obj;

    /* Member variable. */
    p->type = MMI_IDLE_TYPE_CLASSIC;

    /* Member function. */
    p->on_enter = mmi_idle_classic_on_enter;
    p->on_update_service_area = mmi_idle_classic_on_update_service_indication;

	/*for __MMI_TOUCH_IDLESCREEN_SHORTCUTS__, the softkey area is owned by shortcut */
#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    /* Change the capabilities. */
    capability = &obj->capability;

    *capability &= ~ENABLE_CENTER_SOFT_KEY;
    *capability &= ~ENABLE_SOFT_KEY_AREA;    
#endif
}
#endif /*__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__*/
