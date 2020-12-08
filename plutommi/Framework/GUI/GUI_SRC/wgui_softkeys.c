/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wgui_softkeys.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  softkey related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 20 2013 hujin.hu
 * removed!
 * .
 *
 * 02 20 2013 hujin.hu
 * removed!
 * .
 *
 * 02 19 2013 hujin.hu
 * removed!
 * .
 *
 * 01 25 2013 hujin.hu
 * removed!
 * .
 *
 * 01 17 2013 hujin.hu
 * removed!
 * .build warning
 *
 * 01 11 2013 hujin.hu
 * removed!
 * .change as rollback to version20
 *
 * 01 11 2013 hujin.hu
 * removed!
 * Rollback //MAUI/TRUNK/11B/mcu/plutommi/Framework/GUI/GUI_SRC/wgui_softkeys.c to revision 20
 *
 * 12 25 2012 hujin.hu
 * removed!
 * .
 *
 * 12 25 2012 hujin.hu
 * removed!
 * .
 *
 * 12 06 2012 hujin.hu
 * removed!
 * .
 *
 * 06 05 2012 shuaihui.ren
 * removed!
 * .
 *
 * 05 27 2012 shuaihui.ren
 * removed!
 * set font before measure string.
 *
 * 05 03 2012 shuaihui.ren
 * removed!
 * Use the baseline of default string "On" for all softkey texts.
 *
 * 04 19 2012 shuaihui.ren
 * removed!
 * Sync text baseline for each softkey.
 *
 * 04 17 2012 shuaihui.ren
 * removed!
 * Support EnableCentersoftkeyDisplay/DisableCentersoftkeyDisplay.
 *
 * 11 14 2011 helena.li
 * removed!
 * .
 *
 * 09 23 2011 helena.li
 * removed!
 * .
 *
 * 09 13 2011 helena.li
 * removed!
 * .
 *
 * 08 31 2011 helena.li
 * removed!
 * .
 *
 * 08 26 2011 helena.li
 * removed!
 * .
 *
 * 07 04 2011 helena.li
 * removed!
 * .
 *
 * 06 27 2011 helena.li
 * removed!
 * .
 *
 * 06 10 2011 helena.li
 * removed!
 * .
 *
 * 06 09 2011 helena.li
 * removed!
 * .
 *
 * 06 09 2011 helena.li
 * removed!
 * .
 *
 * 06 07 2011 helena.li
 * removed!
 * .
 *
 * 05 16 2011 helena.li
 * removed!
 * .
 *
 * 04 14 2011 helena.li
 * removed!
 * .
 *
 * 04 14 2011 helena.li
 * removed!
 * .
 *
 * 04 12 2011 helena.li
 * removed!
 * .
 *
 * 04 11 2011 helena.li
 * removed!
 * .
 *
 * 03 16 2011 helena.li
 * removed!
 * .
 *
 * 02 22 2011 hongxi.shi
 * removed!
 * .
 *
 * 02 10 2011 helena.li
 * removed!
 * .
 *
 * 02 08 2011 ray.wu
 * removed!
 * .
 *
 * 02 08 2011 mason.chang
 * removed!
 * Rename/move file(s)
 *
 * 12 14 2010 helena.li
 * removed!
 * .
 *
 * 09 17 2010 helena.li
 * removed!
 * .
 *
 * removed!
 * removed!
 * Resume the lock before the idle group is entered.
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
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 * rebase maintrunk.MAUI_MBJ on 2007-3-17 23:21:53.
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
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_softkeys.c
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines for Softkeys
**********************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"
#include "PixcomFontEngine.h"
#include "MMI_trc_Int.h"
#include "wgui_softkeys_pre_oem.h"
#include "wgui_softkeys.h"
#include "wgui_softkeys_post_oem.h"
#include "gdi_include.h"
#include "gui_font_size.h"

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
#include "MainMenuDef.h"
#include "gui_effect_oem.h"
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

#if defined(__MMI_VUI_ENGINE__)
#include "vadp_p2v_uc.h"
#endif /* __MMI_VUI_ENGINE__ */

#include "gui_switch.h"
#include "wgui_categories_list.h"
#include "gui_themes.h"
#include "gui.h"
#include "ImeGprot.h"
#include "GlobalConstants.h"
#include "ScreenRotationGprot.h"
#include "wgui_include.h"
#include "mmi_frm_input_gprot.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "wgui_inputs.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"
#include "CustThemesRes.h"
#if defined(__PLUTO_MMI_PACKAGE__)
#include "mmi_rp_app_mainmenu_def.h"
#endif
#include "wgui_categories_util.h"

#ifdef __MMI_FWUI_SLIM__
  #ifndef __MMI_UI_SOFTKEY_SLIM__
  #define __MMI_UI_SOFTKEY_SLIM__
  #endif
#endif
/* Globals                 */
/* softkey width */
S32 MMI_softkey_width = MMI_SOFTKEY_WIDTH;
S32 MMI_center_softkey_width = MMI_CENTER_SOFTKEY_WIDTH;

//MMI_BOOL MMI_softkey_filler_disabled = MMI_FALSE;

#ifndef __MMI_WGUI_DISABLE_CSK__
static MMI_BOOL wgui_softkey_execute_csk_always = MMI_FALSE;
#endif

static MMI_BOOL wgui_softkey_is_in_popup_screen = MMI_FALSE;
static MMI_BOOL wgui_softkey_enable_double_buffer = MMI_FALSE;

static MMI_BOOL wgui_softkey_lock_state[WGUI_MAX_SOFTKEYS];

/* softkey height */
S32 MMI_softkey_height = MMI_SOFTKEY_HEIGHT;

void (*wgui_softkey_show) (WGUI_SOFTKEY_ENUM key) = NULL;
void (*wgui_softkey_hide) (WGUI_SOFTKEY_ENUM key) = NULL;

/* Softkey wrappers        */
icontext_button MMI_softkeys[WGUI_MAX_SOFTKEYS];

#define  MMI_left_softkey  MMI_softkeys[MMI_LEFT_SOFTKEY]
#define  MMI_right_softkey MMI_softkeys[MMI_RIGHT_SOFTKEY]
#define  MMI_center_softkey   MMI_softkeys[MMI_CENTER_SOFTKEY]

/* LSK key handler */
U8 left_softkey_keyboard_handler_active = 0;
/* RSK key handler */
U8 right_softkey_keyboard_handler_active = 0;
#ifndef __MMI_WGUI_DISABLE_CSK__
/* CSK key handler */
U8 center_softkey_keyboard_handler_active = 0;
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
stFontAttribute softkey_font;
#endif
/* add softkey_target_layer to set softkey's display layer,
 * it only can be used for softkey
 */
static GDI_HANDLE wgui_softkey_target_layer = GDI_NULL_HANDLE;
static GDI_HANDLE wgui_softkey_abm_layer = GDI_NULL_HANDLE;
#ifndef __MMI_WGUI_DISABLE_CSK__
static MMI_BOOL wgui_softkey_is_csk_on_enter_key = MMI_FALSE;
static MMI_BOOL wgui_softkey_is_csk_enable = MMI_FALSE;
#if !defined(__MMI_MAINLCD_96X64__) && (defined(__MMI_BASIC_UI_STYLE__)) || defined(__OP01_FWPBW__) || defined(__MMI_FTE_SUPPORT__)
static MMI_BOOL wgui_softkey_is_display_csk = MMI_FALSE;
#else
static MMI_BOOL wgui_softkey_is_display_csk = MMI_TRUE;
#endif
#endif

#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL wgui_softkey_show_softkey_background[WGUI_MAX_SOFTKEYS];
#endif
//static MMI_BOOL wgui_softkey_clear_down_state_by_softkey[WGUI_MAX_SOFTKEYS];
#ifndef __MMI_UI_SOFTKEY_SLIM__
static MMI_BOOL wgui_softkey_is_need_sync_text_y = MMI_FALSE;
#endif
static MMI_BOOL wgui_softkey_change_by_length = MMI_FALSE;

#define  WGUI_MAX_SOFTKEY_FUNCTIONS 4

#define  WGUI_SOFTKEY_TOUCH_GAP      3

void (*softkey_functions[WGUI_MAX_SOFTKEYS][WGUI_MAX_SOFTKEY_FUNCTIONS]) (void);

#define           left_softkey_functions  softkey_functions[MMI_LEFT_SOFTKEY]
#define           right_softkey_functions    softkey_functions[MMI_RIGHT_SOFTKEY]
#define           center_softkey_functions      softkey_functions[MMI_CENTER_SOFTKEY]

/* Functions to hide softkeys */
void (*hide_softkey[WGUI_MAX_SOFTKEYS]) (void);

void softkey_keyboard_handler(S32 vkey_code, S32 key_state);
static void clear_softkey_button_background_callback(void *button_object);
static void DisableSoftkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key);
static void EnableSoftkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key);
static void ChangeSoftkeyByString(UI_string_type s, PU8 i, WGUI_SOFTKEY_ENUM key);
static void ChangeSoftkeyByStringLength(UI_string_type s, PU8 i, WGUI_SOFTKEY_ENUM key);
static void ChangeSoftkeyExt(U16 s, WGUI_SOFTKEY_ENUM key);

static void SetSoftkeyFunction(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
static void softkey_down(WGUI_SOFTKEY_ENUM key);
static void softkey_up(WGUI_SOFTKEY_ENUM key);
static void softkey_hold(WGUI_SOFTKEY_ENUM key);



void left_softkey_down(void);
void left_softkey_up(void);
void left_softkey_hold(void);
void right_softkey_down(void);
void right_softkey_up(void);
void right_softkey_hold(void);

//#ifndef __MMI_WGUI_DISABLE_CSK__
void center_softkey_down(void);
void center_softkey_up(void);
void center_softkey_hold(void);
//#endif

void(*softkey_handlers[WGUI_MAX_SOFTKEYS][WGUI_MAX_SOFTKEY_FUNCTIONS-1])(void)=
{
 	{left_softkey_down, left_softkey_up, left_softkey_hold},
 	{right_softkey_down, right_softkey_up, right_softkey_hold},
 	{center_softkey_down, center_softkey_up,center_softkey_hold}
};


extern UI_string_type get_string(MMI_ID_TYPE i);
extern PU8 get_image(MMI_ID_TYPE i);
extern S32 UI_strlen(UI_string_type text);
extern void mmi_imc_key_setup_lsk_function(FuncPtr f);
extern void mmi_imc_key_setup_rsk_function(FuncPtr f);

void (*mmi_imc_key_setup_text_handlers[WGUI_MAX_SOFTKEYS])(void)=
{
  mmi_imc_key_setup_lsk_text,
  mmi_imc_key_setup_rsk_text,
  mmi_imc_key_setup_csk_text

};

/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_prev_exit_function
 * DESCRIPTION
 *  If softkey is in down state when exit, just draw up state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_softkey_prev_exit_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
#ifndef __MMI_WGUI_DISABLE_CSK__
        if (i == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
        {
            continue;
        }
#endif		
        if (MMI_softkeys[i].flags & UI_BUTTON_STATE_CLICKED)
        {
            MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_CLICKED;
            MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_DOWN;
            redraw_softkey((WGUI_SOFTKEY_ENUM)i);
        }
    }
}
#ifndef __MMI_UI_SOFTKEY_SLIM__
/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_sync_text_y
 * DESCRIPTION
 *  Set the same text y for LSK/RSK/CSK to draw the strings in the same baseline
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_softkey_sync_text_y(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_fe_get_string_info_param_struct query;
    //S32 baseline[WGUI_MAX_SOFTKEYS];
    S32 base_y, base_baseline;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)get_string(STR_GLOBAL_ON);
    query.n = mmi_ucs2strlen((const char*)query.String);
    query.w = 0;
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
    mmi_fe_get_string_widthheight_varient(&query);
    base_baseline = query.baseline;
    base_y = (MMI_SOFTKEY_HEIGHT - query.pHeight)>>1;

    for(i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    {
        if(MMI_softkeys[i].text != NULL)
        {
            memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
            query.String = (U8*)MMI_softkeys[i].text;
            query.n = mmi_ucs2strlen((const char*)MMI_softkeys[i].text);
            query.w = 0;
            mmi_fe_get_string_widthheight_varient(&query);
            MMI_softkeys[i].text_y = base_y + base_baseline - query.baseline;
        }
    }
    wgui_softkey_is_need_sync_text_y = MMI_FALSE;

}
#endif
/*****************************************************************************
 * FUNCTION
 *  clear_softkey_button_background_callback
 * DESCRIPTION
 *  Clear the background of softkey. Used of callback function in icontext_button.clear_background_fp
 * PARAMETERS
 *  button_object       [IN]        The target button
 * RETURNS
 *  void
 *****************************************************************************/
void setSoftkeyTargetLayer(MMI_BOOL enable_double_buffer)
{

   if (wgui_softkey_target_layer != GDI_NULL_HANDLE)
   {
	   gdi_layer_push_and_set_active(wgui_softkey_target_layer);
	   if (enable_double_buffer)
	   {
		   gdi_layer_toggle_double();
		   gdi_layer_copy_double();
	   }
   }

   if (wgui_softkey_abm_layer != GDI_NULL_HANDLE)
   {
	   gdi_push_and_set_alpha_blending_source_layer(wgui_softkey_abm_layer);
   }

}

/*****************************************************************************
 * FUNCTION
 *  clear_softkey_button_background_callback
 * DESCRIPTION
 *  Clear the background of softkey. Used of callback function in icontext_button.clear_background_fp
 * PARAMETERS
 *  button_object       [IN]        The target button
 * RETURNS
 *  void
 *****************************************************************************/
void restoreSoftkeyTargetLayer(void)
{
    if (wgui_softkey_abm_layer != GDI_NULL_HANDLE)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    if (wgui_softkey_target_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}

/*****************************************************************************
 * FUNCTION
 *  clear_softkey_button_background_callback
 * DESCRIPTION
 *  Clear the background of softkey. Used of callback function in icontext_button.clear_background_fp
 * PARAMETERS
 *  button_object       [IN]        The target button
 * RETURNS
 *  void
 *****************************************************************************/
static void clear_softkey_button_background_callback(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
        if (button_object == (void*)&MMI_softkeys[i])
        {
          setSoftkeyTargetLayer(wgui_softkey_enable_double_buffer);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_softkey_show_softkey_background[i] = MMI_TRUE;
        #endif
            (hide_softkey[i]) ();
		   restoreSoftkeyTargetLayer();
            return;
        }
    }
    MMI_DBG_ASSERT(0);
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_show_pen_down
 * DESCRIPTION
 *  draw pen down of softkey
 * PARAMETERS
 *  button_object       [IN]        The target button
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL wgui_softkey_show_pen_down(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
        if (button_object == (void*)&MMI_softkeys[i])
        {
#ifndef __MMI_WGUI_DISABLE_CSK__

            if(i == MMI_CENTER_SOFTKEY && !wgui_softkey_is_display_csk)
            {
                return MMI_FALSE;
            }
#endif			
            if (!wgui_softkey_show_softkey_background[i])
            {
                return MMI_FALSE;
            }
			setSoftkeyTargetLayer(MMI_FALSE);
            gui_icontext_button_show_down_by_pen((void*)&MMI_softkeys[i]);
			restoreSoftkeyTargetLayer();
            wgui_softkey_show_softkey_background[i] = MMI_FALSE;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_show_pen_up
 * DESCRIPTION
 *  draw pen up of softkey
 * PARAMETERS
 *  button_object       [IN]        The target button
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_softkey_show_pen_up(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
        if (button_object == (void*)&MMI_softkeys[i])
        {
#ifndef __MMI_WGUI_DISABLE_CSK__        
            if(i == MMI_CENTER_SOFTKEY && !wgui_softkey_is_display_csk )
            {
                return MMI_FALSE;
            }
#endif
            if (!wgui_softkey_show_softkey_background[i])
            {
                return MMI_FALSE;
            }
			setSoftkeyTargetLayer(MMI_FALSE);
            gui_icontext_button_show_up_by_pen((void*)&MMI_softkeys[i]);
			restoreSoftkeyTargetLayer();
            wgui_softkey_show_softkey_background[i] = MMI_FALSE;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  create_softkeys
 * DESCRIPTION
 *  Creates and set default value of softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, key = 0, offset_x;
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set theme of LSK */
    set_MMI_LSK_theme();
    /* set theme of RSK */
    set_MMI_RSK_theme();

	//create LSK, RSK

	
	 for (key = 0; key < MMI_CENTER_SOFTKEY; key++)
	{
	   if(key == 0)
	   	offset_x = 0;
	   else
	   	offset_x = UI_device_width - MMI_softkey_width;
	   
	   gui_create_icontext_button(
		   &MMI_softkeys[key],
		   offset_x,
		   UI_device_height - MMI_softkey_height,
		   MMI_softkey_width,
		   MMI_softkey_height,
		   NULL,
		   NULL);
	   gui_icontext_set_horizontal_gap(&MMI_softkeys[key], MMI_UI_SOFTKEY_GAP);
   
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
#ifndef __MMI_FTE_SUPPORT__
	   MMI_softkeys[key].flags |=
		   (UI_BUTTON_SHIFT_BUTTON1| UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
			UI_BUTTON_ALIGN_ICON_TEXT | UI_BUTTON_DISABLE_BACKGND_DISPLAY);
#else /* __MMI_FTE_SUPPORT__ */
	   MMI_softkeys[key].flags |=
		   (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
			UI_BUTTON_ALIGN_ICON_TEXT | UI_BUTTON_FULL_TOUCH_AREA);
#endif /* __MMI_FTE_SUPPORT__ */
#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
	   MMI_softkeys[key].flags |=
		   (UI_BUTTON_SHIFT_BUTTON1| UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
			UI_BUTTON_ALIGN_ICON_TEXT);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
#ifdef __MMI_TOUCH_SCREEN__
	   gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
	   x1 -= WGUI_SOFTKEY_TOUCH_GAP;
	   x2 += WGUI_SOFTKEY_TOUCH_GAP;
	   if (x1 < MMI_softkeys[key].x)
		   x1 = MMI_softkeys[key].x;
	   if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
		   x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
	   gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, MMI_softkeys[key].y, x2, MMI_softkeys[key].y + MMI_softkeys[key].height - 1);
#endif

	}

	MMI_softkeys[MMI_LEFT_SOFTKEY].flags |= UI_BUTTON_LEFT_ALIGN;	
	MMI_softkeys[MMI_RIGHT_SOFTKEY].flags |= UI_BUTTON_RIGHT_ALIGN;
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
    wgui_softkey_reset_theme(MMI_LEFT_SOFTKEY);
    wgui_softkey_reset_theme(MMI_RIGHT_SOFTKEY);
#endif

#ifndef __MMI_WGUI_DISABLE_CSK__
    /* The following statement will remove after app finish their change for key rule */
    wgui_softkey_is_csk_enable = MMI_TRUE;
    #if !defined (__MMI_TOUCH_SCREEN__)
        if (!mmi_frm_kbd_is_key_supported(KEY_ENTER))
        {
            wgui_softkey_is_csk_enable = MMI_FALSE;
        }
    #endif

	
    if (wgui_softkey_is_csk_enable)
    {
        /* create CSK button */
        gui_create_icontext_button(
            &MMI_softkeys[MMI_CENTER_SOFTKEY],
            MMI_softkey_width + ((UI_device_width - (MMI_softkey_width) * 2 - MMI_center_softkey_width) >> 1),
            UI_device_height - MMI_softkey_height,
            MMI_center_softkey_width,
            MMI_softkey_height,
            NULL,
            NULL);

    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
        MMI_center_softkey.flags |=
            (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_TEXT_X | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y |
            UI_BUTTON_ALIGN_ICON_TEXT | UI_BUTTON_DISABLE_BACKGND_DISPLAY);
    #else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
        MMI_center_softkey.flags |=
            (UI_BUTTON_SHIFT_BUTTON1 | UI_BUTTON_CENTER_TEXT_Y | UI_BUTTON_CENTER_ICON_Y | UI_BUTTON_ALIGN_ICON_TEXT);
    #endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) */ 
    #ifdef __MMI_TOUCH_SCREEN__
        gui_icontext_button_get_display_area(&MMI_softkeys[MMI_CENTER_SOFTKEY], &x1, &y1, &x2, &y2);  
        x1 -= WGUI_SOFTKEY_TOUCH_GAP;
        x2 += WGUI_SOFTKEY_TOUCH_GAP;
        if (x1 < MMI_softkeys[MMI_CENTER_SOFTKEY].x)
            x1 = MMI_softkeys[MMI_CENTER_SOFTKEY].x;
        if (x2 > MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width - 1)
            x2 = MMI_softkeys[MMI_CENTER_SOFTKEY].x + MMI_softkeys[MMI_CENTER_SOFTKEY].width - 1;
        gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[MMI_CENTER_SOFTKEY], x1, MMI_softkeys[MMI_CENTER_SOFTKEY].y, x2, MMI_softkeys[MMI_CENTER_SOFTKEY].y + MMI_softkeys[MMI_CENTER_SOFTKEY].height - 1);
    #endif
    }
#endif

    /* initilaize softkey functions to dummy func */
    for (key = 0; key < WGUI_MAX_SOFTKEYS; key++)
    {
#ifndef __MMI_WGUI_DISABLE_CSK__    
        if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
        {
            continue;
        }
#endif		
        MMI_softkeys[key].clear_background_fp = clear_softkey_button_background_callback;
    #ifdef __MMI_TOUCH_SCREEN__
        MMI_softkeys[key].draw_down_fp = wgui_softkey_show_pen_down;
        MMI_softkeys[key].draw_up_fp = wgui_softkey_show_pen_up;
    #endif
        hide_softkey[key] = UI_dummy_function;
        for (i = 0; i < WGUI_MAX_SOFTKEY_FUNCTIONS; i++)
        {
            softkey_functions[key][i] = UI_dummy_function;
        }
    }
#ifndef __MTK_TARGET__	
    register_keyboard_global_key_handler(softkey_keyboard_handler);
#endif	
    wgui_softkey_show = wgui_softkey_oem_show;
    wgui_softkey_hide = wgui_softkey_oem_hide;
}


/*****************************************************************************
 * FUNCTION
 *  restore_softkeys
 * DESCRIPTION
 *  set the softkeys to the MMI's default positions and sizes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (key = 0; key < WGUI_MAX_SOFTKEYS; key++)
    {
#ifndef __MMI_WGUI_DISABLE_CSK__
		if ((key < MMI_CENTER_SOFTKEY )
			||(key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable))
#endif			
			gui_resize_icontext_button(&MMI_softkeys[key], MMI_center_softkey_width, MMI_softkey_height);
			
	#ifndef __MMI_UI_SOFTKEY_SLIM__
    wgui_softkey_is_need_sync_text_y = MMI_TRUE;
	#endif
        gui_move_icontext_button(&MMI_softkeys[key], 0, UI_device_height - MMI_softkey_height);
        gui_set_icontext_button_current_theme(&MMI_softkeys[key]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_softkey_by_string_length
 * DESCRIPTION
 *  resize the left softkey width according the the string
 * PARAMETERS
 *  s       [IN]        String
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void resize_softkey_by_string_length(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
	if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return;
    }
#endif	
    gui_set_font(MMI_softkeys[key].text_font);
    gui_measure_string(s, &sw, &sh);
    gui_resize_icontext_button(&MMI_softkeys[key], sw + WGUI_SOFTKEY_STRING_GAP, MMI_softkeys[key].height);
#ifndef __MMI_UI_SOFTKEY_SLIM__
	wgui_softkey_is_need_sync_text_y = MMI_TRUE;
#endif

    gui_move_icontext_button(&MMI_softkeys[key], 0, UI_device_height - MMI_softkeys[key].height);
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_label_for_IME
 * DESCRIPTION
 *  Changes the label of softkeys
 * PARAMETERS
 *  s       [IN]        String
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_label_for_IME(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return;
    }
#endif
    MMI_softkeys[key].text = s;
    if ((s != NULL) && (UI_strlen(s) == 0))
    {
        MMI_softkeys[key].text = NULL;
    }
    if (MMI_softkeys[key].normal_down_icon == NULL)
    {
        MMI_softkeys[key].flags &= ~UI_BUTTON_CENTER_ICON_X;
		
#ifndef __MMI_WGUI_DISABLE_CSK__		
        if (key == MMI_CENTER_SOFTKEY)
        {
            MMI_softkeys[key].flags |= UI_BUTTON_CENTER_TEXT_X;
        }
#endif

    #if !(defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_128X128__)  || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__) || defined (__MMI_MAINLCD_128X64__))
        MMI_softkeys[key].flags |= UI_BUTTON_CENTER_TEXT_X;
    #endif 
    }
    gui_resize_icontext_button(&MMI_softkeys[key], MMI_softkeys[key].width, MMI_softkeys[key].height);
#ifndef __MMI_UI_SOFTKEY_SLIM__
	wgui_softkey_is_need_sync_text_y = MMI_TRUE;
#endif

#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, MMI_softkeys[key].y, x2, MMI_softkeys[key].y + MMI_softkeys[key].height - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_icon_for_IME
 * DESCRIPTION
 *  Changes the icon of softkeys
 * PARAMETERS
 *  icon    [IN]        icon content
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_icon_for_IME(PU8 icon, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 new_icon = icon;
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return;
    }
#endif

  
    if ((icon != NULL) && (CheckIsEmptyImage(icon)))
    {
        new_icon = NULL;
    }

    if (icon != NULL && icon == MMI_softkeys[key].normal_up_icon)
    {
        return;
    }

    /* set icon of LSK button */
    gui_icontext_button_set_icon(&MMI_softkeys[key], new_icon, gui_transparent_color(0, 0, 0));
    if (MMI_softkeys[key].text == NULL)
    {
        MMI_softkeys[key].flags &= ~UI_BUTTON_CENTER_TEXT_X;
        MMI_softkeys[key].flags |= UI_BUTTON_CENTER_ICON_X;
    }
    gui_resize_icontext_button(&MMI_softkeys[key], MMI_softkeys[key].width, MMI_softkeys[key].height);
#ifndef __MMI_UI_SOFTKEY_SLIM__
	wgui_softkey_is_need_sync_text_y = MMI_TRUE;
#endif

#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, MMI_softkeys[key].y, x2, MMI_softkeys[key].y + MMI_softkeys[key].height - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_label
 * DESCRIPTION
 *  Changes the label of softkeys
 * PARAMETERS
 *  s       [IN]        String
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_label(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_softkey_lock_state[key])
    {
        return;
    }

    set_softkey_label_for_IME(s, key);
#ifndef __MMI_WGUI_DISABLE_CSK__	
	if(key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
		return;
#endif	
	mmi_imc_key_setup_text_handlers[key]();
}


/*****************************************************************************
 * FUNCTION
 *  get_softkey_label
 * DESCRIPTION
 *  get softkey text label
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  Softkey text label
 *****************************************************************************/
UI_string_type get_softkey_label(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key >= WGUI_MAX_SOFTKEYS)
    {
        return NULL;
    }
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return NULL;
    }
#endif
    return MMI_softkeys[key].text;
}


/*****************************************************************************
 * FUNCTION
 *  get_softkey_icon
 * DESCRIPTION
 *  get softkey icon
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  PU8
 *****************************************************************************/
PU8 get_softkey_icon(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key >= WGUI_MAX_SOFTKEYS)
    {
        return NULL;
    }
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return NULL;
    }
#endif
    return MMI_softkeys[key].normal_up_icon;
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_icon
 * DESCRIPTION
 *  Changes the icon of softkeys
 * PARAMETERS
 *  icon        [IN]        Icon
 *  key         [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_icon(PU8 icon, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_softkey_set_icon_for_IME(icon, key);
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable)
    {
    /* The following compile option will remove when app finish their change for key rule */
        mmi_imc_key_setup_csk_icon();
    }
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  change_softkey
 * DESCRIPTION
 *  Changes the string and icon of softkeys
 * PARAMETERS
 *  s       [IN]        String
 *  i       [IN]        Icon
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void change_softkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_softkey_label(str, key);
    }
    else
    {
        set_softkey_label(NULL, key);
    }

    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

        set_softkey_icon(img, key);
    }
    else
    {
        set_softkey_icon(NULL, key);
    }
    if ((s == NULL) && (i == NULL))
    {
        reset_softkey(key);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_function
 * DESCRIPTION
 *  Changes the handler of softkeys
 * PARAMETERS
 *  f       [IN]        Handler function
 *  k       [IN]        Key event type
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }

    if (wgui_softkey_lock_state[key])
    {
        return;
    }

    switch (key)
    {
        case MMI_LEFT_SOFTKEY:

        case MMI_RIGHT_SOFTKEY:
            softkey_functions[key][k] = f;
            break;

        case MMI_CENTER_SOFTKEY:
#ifndef __MMI_WGUI_DISABLE_CSK__			
            if (wgui_softkey_is_csk_enable)
#endif  
            {
                softkey_functions[key][k] = f;
            #if !defined (__MMI_TOUCH_SCREEN__)
                register_center_softkey_to_enter_key();
            #endif /* __MMI_TOUCH_SCREEN__ */
            }
/*
#else
      SetKeyHandler(f, KEY_CSK, k);
     #if !defined (__MMI_TOUCH_SCREEN__)
                SetKeyHandler(f, KEY_ENTER, k);
     #endif 

#endif
*/
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_softkey_function
 * DESCRIPTION
 *  get softkey handlers
 * PARAMETERS
 *  k       [IN]        Key event
 *  key     [IN]        Softkey enum
 * RETURNS
 *  Softkey callback functions
 *****************************************************************************/
FuncPtr get_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return NULL;
    }
#ifndef __MMI_WGUI_DISABLE_CSK__

    if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return NULL;
    }
#endif
    return softkey_functions[key][k];
}


/*****************************************************************************
 * FUNCTION
 *  execute_softkey_function
 * DESCRIPTION
 *  execute softkey handlers
 * PARAMETERS
 *  k       [IN]        Key event
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void execute_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }
#ifndef __MMI_WGUI_DISABLE_CSK__

    if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return;
    }
#endif

	if(key != MMI_CENTER_SOFTKEY)
	{
    if ((MMI_softkeys[key].text == NULL) && (MMI_softkeys[key].normal_up_icon == NULL))
    {
        if (k == KEY_EVENT_UP)
        {
            clear_softkey_handler(key);
        }
        return;
    }
	}
    if (softkey_functions[key][k] != NULL)
    {
    #if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__PLUTO_MMI_PACKAGE__)
        if (GetActiveScreenId() == MAIN_MENU_SCREENID && ((key == MMI_LEFT_SOFTKEY) || (key == MMI_CENTER_SOFTKEY)))
        {
            gui_screen_switch_effect_setup_MM();
        }
    #endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

        if (softkey_functions[key][k] == UI_dummy_function)
        {
            if (k == KEY_EVENT_UP)
            {
                mmi_event_struct evt;
    
                MMI_FRM_INIT_EVENT(&evt, 0);
				evt.evt_id = EVT_ID_WGUI_LSK_CLICK + key-MMI_LEFT_SOFTKEY;
                MMI_FRM_CB_EMIT_EVENT(&evt);
            }
        }
        else
        {
            softkey_functions[key][k] ();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey
 * DESCRIPTION
 *  Sets the label and the function to be called for the softkey
 * PARAMETERS
 *  s       [IN]        New string to be used as the softkey label
 *  f       [IN]        Function that is called when a particular softkey event occurs
 *  k       [IN]        Key event
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey(UI_string_type s, void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (k >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }

    set_softkey_label(s, key);
    set_softkey_function(f, k, key);
}


/*****************************************************************************
 * FUNCTION
 *  clear_softkey_display_functions
 * DESCRIPTION
 *  Clear the functions of the softkey
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void clear_softkey_display_functions(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hide_softkey[key] = UI_dummy_function;
    for (i = 0; i < WGUI_MAX_SOFTKEY_FUNCTIONS; i++)
    {
        softkey_functions[key][i] = UI_dummy_function;
    }
    if (key == MMI_LEFT_SOFTKEY)
    {
        mmi_imc_key_setup_lsk_function(UI_dummy_function);
    }
    if (key == MMI_RIGHT_SOFTKEY)
    {
        mmi_imc_key_setup_rsk_function(UI_dummy_function);
    }
	
    if (key == MMI_CENTER_SOFTKEY)
    {
        mmi_imc_key_setup_csk_function(UI_dummy_function);
		
    }

}


/*****************************************************************************
 * FUNCTION
 *  show_softkey
 * DESCRIPTION
 *  Displays softkey
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void show_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
	if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_display_csk == MMI_FALSE)
    {
        return;
    }

    if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }
#else
	if(key == MMI_CENTER_SOFTKEY)
		return;
#endif
    if ((MMI_softkeys[key].text == NULL) && (MMI_softkeys[key].normal_up_icon == NULL))
    {
        return;
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_SCREEN_ROTATE__)
    if (mmi_frm_is_screen_width_height_swapped())
    {
        if (MMI_softkeys[key].flags & UI_BUTTON_NO_UNDER_BAR)
        {
            MMI_softkeys[key].normal_up_filler = NULL;
            MMI_softkeys[key].normal_down_filler = NULL;
            MMI_softkeys[key].clicked_up_filler = NULL;
            MMI_softkeys[key].clicked_down_filler = NULL; 
        }
        else
        {
            MMI_softkeys[key].normal_up_filler = current_MMI_theme->softkey_lsk_up_filler;
            MMI_softkeys[key].normal_down_filler = current_MMI_theme->softkey_lsk_down_filler;
            MMI_softkeys[key].clicked_up_filler = current_MMI_theme->softkey_lsk_up_filler;
            MMI_softkeys[key].clicked_down_filler = current_MMI_theme->softkey_lsk_down_filler;
        }
    }
#endif
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
    if(wgui_is_wallpaper_on_bottom() && (current_MMI_theme->softkey_bar_bkg_filler == NULL))//MMI_softkey_filler_disabled || 
    {
        softkey_font = *((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));
        softkey_font.smallCaps = 2;
        MMI_softkeys[key].text_font = &softkey_font;
    }
#endif

   #ifndef __MMI_UI_SOFTKEY_SLIM__
    if(wgui_softkey_is_need_sync_text_y)// == MMI_TRUE
    {
        wgui_softkey_sync_text_y();
    }
	#endif
        wgui_softkey_show(key);
}


/*****************************************************************************
 * FUNCTION
 *  move_softkey
 * DESCRIPTION
 *  change the position of softkey
 * PARAMETERS
 *  x       [IN]        New x-coordinate of softkey
 *  y       [IN]        New y-coordinate of softkey
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void move_softkey(S32 x, S32 y, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
	if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }
#endif

    gui_move_icontext_button(&MMI_softkeys[key], x, y);
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, MMI_softkeys[key].y, x2, MMI_softkeys[key].y + MMI_softkeys[key].height - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  resize_softkey
 * DESCRIPTION
 *  change the width and height of softkey
 * PARAMETERS
 *  width       [IN]        New width of softkey
 *  height      [IN]        New height of softkey
 *  key         [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void resize_softkey(S32 width, S32 height, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }
#endif	
    gui_resize_icontext_button(&MMI_softkeys[key], width, height);
#ifndef __MMI_UI_SOFTKEY_SLIM__
    wgui_softkey_is_need_sync_text_y = MMI_TRUE;
#endif
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_get_display_area(&MMI_softkeys[key], &x1, &y1, &x2, &y2);
    x1 -= WGUI_SOFTKEY_TOUCH_GAP;
    x2 += WGUI_SOFTKEY_TOUCH_GAP;
    if (x1 < MMI_softkeys[key].x)
        x1 = MMI_softkeys[key].x;
    if (x2 > MMI_softkeys[key].x + MMI_softkeys[key].width - 1)
        x2 = MMI_softkeys[key].x + MMI_softkeys[key].width - 1;
    gui_icontext_button_overwirte_pen_response_area(&MMI_softkeys[key], x1, MMI_softkeys[key].y, x2, MMI_softkeys[key].y + MMI_softkeys[key].height - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  redraw_softkey
 * DESCRIPTION
 *  Redraw softkey
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;//061506 double buffer

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// baiwenlin 20130830  
#if defined(__OLED_BW_MMI__)
	return;
#endif /* __OLED_BW_MMI__ */
	
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        return;
    }
#endif /* __MMI_VUI_ENGINE__ */
#ifndef __MMI_WGUI_DISABLE_CSK__

    if(key == MMI_CENTER_SOFTKEY && wgui_softkey_is_display_csk == MMI_FALSE)
    {
        return;
    }

    if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }
#endif
	setSoftkeyTargetLayer(wgui_softkey_enable_double_buffer);
    
    gdi_layer_lock_frame_buffer();

    if ( !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY) ||
         (key == MMI_LEFT_SOFTKEY && !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_TEXT_DISPLAY)) ||
         (key == MMI_RIGHT_SOFTKEY && !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_TEXT_DISPLAY)) ||
         (key == MMI_CENTER_SOFTKEY && !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_IMAGE_DISPLAY)))
    {
        hide_softkey[key] ();
    }
    show_softkey(key);

    gdi_layer_unlock_frame_buffer();

	restoreSoftkeyTargetLayer();

	gdi_layer_blt_previous(
                MMI_softkeys[key].x,
                MMI_softkeys[key].y,
                (MMI_softkeys[key].x + MMI_softkeys[key].width + 2),
                (MMI_softkeys[key].y + MMI_softkeys[key].height + 2));
         
    /* 061506 double buffer Start */
    for (idx = 0; idx < WGUI_STATUS_ICON_BAR_TOTAL_BAR; idx++)
    {
        if(wgui_status_icon_bar_whether_double_buffer((wgui_status_icon_bar_enum)idx))
        {
            gdi_layer_push_and_set_active(wgui_status_icon_bar_get_target_layer((wgui_status_icon_bar_enum)idx));
            gdi_layer_toggle_double();
            gdi_layer_copy_double();//070306 copy double
            gdi_layer_pop_and_restore_active();
        }
    }
    /* 061506 double buffer End */
}


/*****************************************************************************
 * FUNCTION
 *  left_softkey_down
 * DESCRIPTION
 *  Handles left softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void left_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	softkey_down(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  left_softkey_up
 * DESCRIPTION
 *  Handles left softkey up event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void left_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	softkey_up(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  left_softkey_hold
 * DESCRIPTION
 *  Handles left softkey hold event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void left_softkey_hold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    softkey_hold(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  left_softkey_up
 * DESCRIPTION
 *  Handles left softkey up event but no redraw
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_softkey_state_no_redraw( U16 KeyCode, U16 KeyType)
{
		if ( KeyType == KEY_EVENT_UP )
		{
			if (MMI_softkeys[KeyCode].flags & UI_BUTTON_STATE_CLICKED)
			{   /* change the state of LSK button */
				MMI_softkeys[KeyCode].flags &= ~UI_BUTTON_STATE_CLICKED;
				MMI_softkeys[KeyCode].flags &= ~UI_BUTTON_STATE_DOWN;
			}
		}
		else if ( KeyType == KEY_EVENT_DOWN )
		{
			if (!(MMI_softkeys[KeyCode].flags & UI_BUTTON_STATE_CLICKED))
			{
				/* change the state of LSK button */
				MMI_softkeys[KeyCode].flags |= UI_BUTTON_STATE_CLICKED;
				MMI_softkeys[KeyCode].flags |= UI_BUTTON_STATE_DOWN;
			}
		}
}

/*****************************************************************************
 * FUNCTION
 *  right_softkey_down
 * DESCRIPTION
 *  Handles right softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void right_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	softkey_down(MMI_RIGHT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  right_softkey_hold
 * DESCRIPTION
 *  Handles right softkey hold event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void right_softkey_hold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    softkey_hold(MMI_RIGHT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  right_softkey_up
 * DESCRIPTION
 *  Handles right softkey up event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	softkey_up(MMI_RIGHT_SOFTKEY);
}

/*****************************************************************************
 * FUNCTION
 *  center_softkey_down
 * DESCRIPTION
 *  Handles center softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void softkey_down(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_softkeys[key].flags & UI_BUTTON_STATE_CLICKED))
    {
        /* change the state of RSK button */
        MMI_softkeys[key].flags |= UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[key].flags |= UI_BUTTON_STATE_DOWN;
        redraw_softkey(key);
        gui_add_pre_cleanup_hook(wgui_softkey_prev_exit_function);
       // if ((MMI_softkeys[key].flags & UI_BUTTON_STATE_CLICKED) && 
       //     (MMI_softkeys[key].flags & UI_BUTTON_STATE_DOWN))
       // {
            execute_softkey_function(KEY_EVENT_DOWN, key);
      //  }
    }


}

/*****************************************************************************
 * FUNCTION
 *  center_softkey_down
 * DESCRIPTION
 *  Handles center softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void softkey_up(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_softkeys[key].flags & UI_BUTTON_STATE_CLICKED)
    {   /* change the state of LSK button */
        MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_DOWN;
//        wgui_softkey_clear_down_state_by_softkey[key] = MMI_TRUE;
        redraw_softkey(key);

        /* call function handlers of LSK Up */
      //  if (wgui_softkey_clear_down_state_by_softkey[key] == MMI_TRUE)
      //  {
            execute_softkey_function(KEY_EVENT_UP, key);
      //  }
    }

}


/*****************************************************************************
 * FUNCTION
 *  center_softkey_down
 * DESCRIPTION
 *  Handles center softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void softkey_hold(WGUI_SOFTKEY_ENUM key)
{
      /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_softkeys[key].flags & UI_BUTTON_STATE_CLICKED)
    {
        execute_softkey_function(KEY_LONG_PRESS, key);
    }
}

//#ifndef __MMI_WGUI_DISABLE_CSK__
/*****************************************************************************
 * FUNCTION
 *  center_softkey_down
 * DESCRIPTION
 *  Handles center softkey down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void center_softkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__    
    if (wgui_softkey_execute_csk_always ==  MMI_TRUE)
    {
        left_softkey_down();
        return;
    }
#endif
	softkey_down(MMI_CENTER_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  center_softkey_hold
 * DESCRIPTION
 *  Handles center softkey hold event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void center_softkey_hold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__    
    if (wgui_softkey_execute_csk_always ==  MMI_TRUE)
    {
        left_softkey_hold();
        return;
    }
#endif
	softkey_hold(MMI_CENTER_SOFTKEY); 
}


/*****************************************************************************
 * FUNCTION
 *  center_softkey_up
 * DESCRIPTION
 *  Handles left softkey up event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void center_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (wgui_softkey_execute_csk_always ==  MMI_TRUE)
    {
        left_softkey_up();
        return;
    }
#endif

	softkey_up(MMI_CENTER_SOFTKEY);
}

//#endif

/*****************************************************************************
 * FUNCTION
 *  register_softkey_handler
 * DESCRIPTION
 *  Register handlers of softkeys
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void register_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // WGUI_SOFTKEY_ENUM i;
	mmi_key_types_enum j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if(key != MMI_CENTER_SOFTKEY)
{
    if ((MMI_softkeys[key].text == NULL) && (MMI_softkeys[key].normal_up_icon == NULL))
    {
        return;
    }
}   
  if (MMI_softkeys[key].flags & UI_BUTTON_STATE_DISABLED)
    {
        return;
    }

#ifndef __MMI_WGUI_DISABLE_CSK__	
    if(key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
		return;
//#else
//  if(key == MMI_CENTER_SOFTKEY)
//	return;
#endif

	for(j=KEY_EVENT_DOWN; j<=KEY_LONG_PRESS; j++)
	   SetKeyHandler(softkey_handlers[key][j-KEY_EVENT_DOWN],
	      key-MMI_LEFT_SOFTKEY + KEY_LSK, j);
	//to support cosmos back key
#if defined(__COSMOS_MMI_PACKAGE__)
   if(key==MMI_RIGHT_SOFTKEY)
   {
     if(mmi_frm_kbd_is_key_supported(KEY_BACK))
     {
        SetKeyHandler(right_softkey_down, KEY_BACK, KEY_EVENT_DOWN);
		SetKeyHandler(right_softkey_up, KEY_BACK, KEY_EVENT_UP);
		SetKeyHandler(right_softkey_hold, KEY_BACK, KEY_LONG_PRESS);
     }
   }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  register_center_softkey_to_enter_key
 * DESCRIPTION
 *  Register center softkey handlers to enter key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_center_softkey_to_enter_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_types_enum i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (wgui_softkey_is_csk_enable == MMI_TRUE)
    {  
#endif    
         for(i=KEY_EVENT_UP; i<=KEY_LONG_PRESS; i++)
	   		SetKeyHandler(softkey_handlers[MMI_CENTER_SOFTKEY][i], KEY_ENTER, i);
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
#ifndef __MMI_WGUI_DISABLE_CSK__		
    	wgui_softkey_is_csk_on_enter_key = MMI_TRUE;
    }
#endif    
//#else
//   for(i=KEY_EVENT_UP; i<=KEY_LONG_PRESS; i++)
//	   		SetKeyHandler(GetKeyHandler(KEY_CSK, i), KEY_ENTER, i);
//#endif
}


/*****************************************************************************
 * FUNCTION
 *  clear_softkey_handler
 * DESCRIPTION
 *  Register handlers of softkeys
 * PARAMETERS
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void clear_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_types_enum key_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__

	if(key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
		return;
#endif
	for(key_type=KEY_EVENT_DOWN; key_type<=KEY_LONG_PRESS; key_type++)
	 ClearKeyHandler(key-MMI_LEFT_SOFTKEY + KEY_LSK, key_type);
}


/*****************************************************************************
 * FUNCTION
 *  softkey_keyboard_handler
 * DESCRIPTION
 *  Keyboard handler (Simulator) for softkeys
 * PARAMETERS
 *  vkey_code       [IN]        Key type
 *  key_state       [IN]        Key event type
 * RETURNS
 *  void
 *****************************************************************************/
void softkey_keyboard_handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 112:
                if (left_softkey_keyboard_handler_active)
                {
                    left_softkey_down();
                }
                break;
            case 113:
                if (right_softkey_keyboard_handler_active)
                {
                    right_softkey_down();
                }
                break;
        }
    }
    else
    {
        switch (vkey_code)
        {
            case 112:
                if (left_softkey_keyboard_handler_active)
                {
                    left_softkey_up();
                }
                break;
            case 113:
                if (right_softkey_keyboard_handler_active)
                {
                    right_softkey_up();
                }
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  register_hide_softkey
 * DESCRIPTION
 *  Register handlers of hide softkeys
 * PARAMETERS
 *  f       [IN]        Callback function to hide softkey
 *  key     [IN]        Softkey enum
 * RETURNS
 *  void
 *****************************************************************************/
void register_hide_softkey(void (*f) (void), WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__	
    if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return;
    }
#endif

    hide_softkey[key] = f;
}


/*****************************************************************************
 * FUNCTION
 *  reset_softkeys
 * DESCRIPTION
 *  Sets the softkey states to normal and clears the hide functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
        MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_CLICKED;
        MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_DOWN;
        MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_DISABLED;
        MMI_softkeys[i].flags &= ~UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE;
        MMI_softkeys[i].flags &= ~UI_BUTTON_NO_SHIFT_BUTTON;
    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        MMI_softkeys[i].flags &= ~UI_BUTTON_TEXT_NO_TRANSLUCENCE;
    #endif
    #ifdef __MMI_FTE_SUPPORT__	
        MMI_softkeys[i].flags &= ~UI_BUTTON_DISABLE_BACKGND_DISPLAY;
    #endif
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_softkey_show_softkey_background[i] = MMI_FALSE;
    #endif
    //    wgui_softkey_clear_down_state_by_softkey[i] = MMI_FALSE;
        hide_softkey[i] = UI_dummy_function;
		set_softkey_flags_off(UI_BUTTON_ENABLE_DOUBLE_BUFFER, (WGUI_SOFTKEY_ENUM)i);
    }
   // MMI_softkey_filler_disabled = MMI_FALSE;
    wgui_softkey_target_layer = GDI_NULL_HANDLE;
    wgui_softkey_abm_layer = GDI_NULL_HANDLE;
    wgui_softkey_is_in_popup_screen = MMI_FALSE;

    wgui_softkey_enable_double_buffer = MMI_FALSE;
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
    wgui_softkey_reset_theme(MMI_LEFT_SOFTKEY);
    wgui_softkey_reset_theme(MMI_RIGHT_SOFTKEY);
#endif

#ifndef __MMI_WGUI_DISABLE_CSK__
    wgui_softkey_is_csk_on_enter_key = MMI_FALSE;
    wgui_softkey_execute_csk_always = MMI_FALSE;
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  reset_softkey
 * DESCRIPTION
 *  Sets the softkey states to normal and clears the hide functions
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void reset_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__

   if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return;
    }
 #endif  
    MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_CLICKED;
    MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_DOWN;
    MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_DISABLED;
    MMI_softkeys[key].flags &= ~UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE;
    /* Do not reset UI_BUTTON_NO_SHIFT_BUTTON and hide_softkey[] */
}


/*****************************************************************************
 * FUNCTION
 *  disable_softkey_background
 * DESCRIPTION
 *  Set some flags to disable background display of softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_softkey_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
    #ifndef __MMI_WGUI_DISABLE_CSK__
        if (i == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable )
        {
            continue;
        }
	#endif

    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
        MMI_softkeys[i].flags |= UI_BUTTON_NO_UNDER_BAR;
        #ifdef __MMI_FTE_SUPPORT__
            MMI_softkeys[i].flags |= UI_BUTTON_DISABLE_BACKGND_DISPLAY;
        #endif /* __MMI_FTE_SUPPORT__ */
    #else 
        MMI_softkeys[i].flags |= UI_BUTTON_DISABLE_BACKGND_DISPLAY;
    #endif 
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
#endif

/*****************************************************************************
 * FUNCTION
 *  enable_softkey_background
 * DESCRIPTION
 *  Set some flags to disable background display of softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enable_softkey_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
    #ifndef __MMI_WGUI_DISABLE_CSK__
        if (i == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
        {
            continue;
        }
	#endif	

    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
        MMI_softkeys[i].flags &= ~UI_BUTTON_NO_UNDER_BAR;
        #ifdef __MMI_FTE_SUPPORT__
            MMI_softkeys[i].flags &= ~UI_BUTTON_DISABLE_BACKGND_DISPLAY;
        #endif /* __MMI_FTE_SUPPORT__ */
    #else 
        MMI_softkeys[i].flags &= ~UI_BUTTON_DISABLE_BACKGND_DISPLAY;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_flags_on
 * DESCRIPTION
 *  turn on flag of softkeys
 * PARAMETERS
 *  flag        [IN]        
 *  key         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_flags_on(S32 flag, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }
	#endif
    MMI_softkeys[key].flags |= flag;
}


/*****************************************************************************
 * FUNCTION
 *  set_softkey_flags_off
 * DESCRIPTION
 *  turn off  flag of softkeys
 * PARAMETERS
 *  flag        [IN]        
 *  key         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_softkey_flags_off(S32 flag, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifndef __MMI_WGUI_DISABLE_CSK__
    if (key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }
	#endif
    MMI_softkeys[key].flags &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_softkey_get_offset(
          UI_string_type sk_str_p,
          S32 *offset_x,
          S32 *offset_y,
          S32 *truncated_width,
          WGUI_SOFTKEY_ENUM key,
          mmi_frm_screen_rotate_enum rotate_degree)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;
    MMI_BOOL need_truncate = MMI_FALSE;
    S32 x_width;
    UI_font_type f = UI_font;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((key >= WGUI_MAX_SOFTKEYS)
#ifndef __MMI_WGUI_DISABLE_CSK__
	||(key == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
#endif
)
    {
        *offset_x = 0;
        *offset_y = 0;
        *truncated_width = 0;
        return MMI_FALSE;
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
    if ((key == MMI_LEFT_SOFTKEY || key == MMI_RIGHT_SOFTKEY) &&
        f->size == (MMI_softkeys[key].text_font)->size &&
        (MMI_softkeys[key].text_font)->smallCaps == 2)
    {
        gui_set_font(MMI_softkeys[key].text_font); 
    }
#endif

    gui_measure_string(sk_str_p, &sw, &sh);
    sw = sw + 2; /* 2 is border width */

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)
    if (rotate_degree != MMI_FRM_SCREEN_ROTATE_0)
    {
        if (key == MMI_LEFT_SOFTKEY || key == MMI_RIGHT_SOFTKEY)
        {
            x_width = MMI_ROTATED_SOFTKEY_WIDTH - MMI_ROTATED_SOFTKEY_GAP;
        }
        else
        {
            x_width = MMI_ROTATED_SOFTKEY_WIDTH;
        }
        if (sw > x_width)
        {
            need_truncate = MMI_TRUE;
            *offset_x = MMI_ROTATED_BUTTON_BAR_X + 1; /* 1 is pixel of border */
            *truncated_width = x_width - 2; /* text truncated function not regard border */
        }
        else
        {
            *offset_x =  MMI_ROTATED_BUTTON_BAR_X + (MMI_ROTATED_SOFTKEY_WIDTH - MMI_ROTATED_SOFTKEY_GAP) - sw + 1;
            *truncated_width = MMI_ROTATED_SOFTKEY_WIDTH;
        }

        if (key == MMI_LEFT_SOFTKEY)
        {
            *offset_y =  MMI_ROTATED_BUTTON_BAR_HEIGHT - GUI_BUTTON_VERTICAL_GAP - sh - 
                (MMI_ROTATED_SOFTKEY_HEIGHT - GUI_BUTTON_VERTICAL_GAP - sh) / 2;
        }
        else if (key == MMI_RIGHT_SOFTKEY)
        {        
            *offset_y =  MMI_ROTATED_BUTTON_BAR_Y + GUI_BUTTON_VERTICAL_GAP +
                (MMI_ROTATED_SOFTKEY_HEIGHT - GUI_BUTTON_VERTICAL_GAP) / 2 - sh / 2;
        }
        else
        {
            *offset_y =  MMI_ROTATED_LCD_HEIGHT / 2 - sh / 2;
        }
    }
    else
    {
#endif /* __MMI_MAINLCD_176X220__ */        
        *offset_y = MMI_softkeys[key].y + (MMI_softkey_height >> 1) - (sh - (sh >> 1));
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
        if (key == MMI_LEFT_SOFTKEY || key == MMI_RIGHT_SOFTKEY)
        {
            x_width = MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP;
        }
        else
        {
            x_width = MMI_CENTER_SOFTKEY_WIDTH;
        }
    #else
        x_width = MMI_SOFTKEY_WIDTH;
    #endif
        *truncated_width = x_width;

        if (sw > x_width)
        {
            need_truncate = MMI_TRUE;
            *truncated_width = x_width - 2; /* text truncated function not regard border */
        }

        if (key == MMI_LEFT_SOFTKEY)
        {
        #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
            *offset_x =  MMI_softkeys[key].x + MMI_UI_SOFTKEY_GAP + 1;
        #else
            if (need_truncate)
            {
                *offset_x = MMI_softkeys[key].x + 1;
            }
            else
            {
                *offset_x = (MMI_softkeys[key].width - sw) / 2 + 1;
            }
        #endif
        }
        else if (key == MMI_RIGHT_SOFTKEY)
        {        
        #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
            if (need_truncate)
            {
                *offset_x = MMI_softkeys[key].x + 1;
            }
            else
            {
                *offset_x =  MMI_softkeys[key].x + MMI_softkeys[key].width - MMI_UI_SOFTKEY_GAP - sw + 1;
            }
        #else
            if (need_truncate)
            {
                *offset_x = MMI_softkeys[key].x + 1;
            }
            else
            {
                *offset_x = MMI_softkeys[key].x  + 
                            (MMI_softkeys[MMI_RIGHT_SOFTKEY].width - sw) / 2 + 1;
            }
        #endif
        }
        else
        {
            if (need_truncate)
            {
                *offset_x = MMI_softkeys[key].x + 1;
            }
            else
            {
                *offset_x = MMI_softkeys[key].x  + 
                            (MMI_softkeys[MMI_CENTER_SOFTKEY].width - sw) / 2 + 1;
            }
        }
        
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)
    }
#endif /* __MMI_MAINLCD_176X220__ */        

    if (mmi_fe_get_r2l_state())
    {
        if (!need_truncate)
        {
            *offset_x = *offset_x + (sw - 2) - 1;
        }
        else
        {
            *offset_x = *offset_x + x_width - 1;
        }
    }
    gui_set_font(f);
    return need_truncate;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  translate_softkey_pen_event
 * DESCRIPTION
 *  translate low level key events to softkey related events
 * PARAMETERS
 *  key                 [IN]            One of value of WGUI_SOFTKEY_ENUM
 *  pen_event           [IN]            Low level pen event type
 *  x                   [IN]            X-coordinate of pen event
 *  y                   [IN]            Y-coordinate of pen event
 *  button_event        [IN/OUT]        Softkey related event type
 * RETURNS
 *  void
 *****************************************************************************/
BOOL translate_softkey_pen_event(
        WGUI_SOFTKEY_ENUM key,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_button_pen_enum *button_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
	if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
    {
        return MMI_FALSE;
    }
#endif
    return gui_icontext_button_translate_pen_event(&MMI_softkeys[key], pen_event, x, y, button_event);
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_dimension
 * DESCRIPTION
 *  get softkey dimenstion
 * PARAMETERS
 *  key         [IN]            One of value of WGUI_SOFTKEY_ENUM
 *  width       [IN/OUT]        Width of softkey
 *  height      [IN/OUT]        Height of softkey
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_get_dimension(WGUI_SOFTKEY_ENUM key, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MMI_softkeys[key].width;
    *height = MMI_softkeys[key].height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_position
 * DESCRIPTION
 *  get softkey position
 * PARAMETERS
 *  key         [IN]            One of value of WGUI_SOFTKEY_ENUM
 *  x           [IN/OUT]        X-position of softkey
 *  y           [?]             
 *  yx(?)       [IN/OUT]        Y-positino of softkey
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_get_position(WGUI_SOFTKEY_ENUM key, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *x = MMI_softkeys[key].x;
    *y = MMI_softkeys[key].y;
}


/*****************************************************************************
 * FUNCTION
 *  show_softkey_background
 * DESCRIPTION
 *  Draws a background behind the softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_softkey_background(void)
{
    wgui_softkey_hide(WGUI_MAX_SOFTKEYS);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_softkey
 * DESCRIPTION
 *  Hides the softkeys using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifndef __MMI_WGUI_DISABLE_CSK__
	if (key == MMI_CENTER_SOFTKEY && !wgui_softkey_is_csk_enable)
		return;
	#endif
	
#ifdef __MMI_SCREEN_ROTATE__
	if (mmi_frm_is_screen_width_height_swapped())
	{
	    gdi_draw_solid_rect(
	        MMI_softkeys[key].x,
	        MMI_softkeys[key].y,
	        MMI_softkeys[key].x + MMI_softkeys[key].width + 2,
	        MMI_softkeys[key].y + MMI_softkeys[key].height + 2,
	        GDI_COLOR_TRANSPARENT);
	}
	else
#endif /* __MMI_SCREEN_ROTATE__ */ 
	    gdi_draw_solid_rect(
	        MMI_softkeys[key].x,
	        UI_device_height - MMI_softkey_height,
	        MMI_softkeys[key].x + MMI_softkeys[key].width + 2,
	        UI_device_height - 1,
	        GDI_COLOR_TRANSPARENT);
   
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_left_softkey
 * DESCRIPTION
 *  Hides the left softkey using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_left_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clear_softkey(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_clear_right_softkey
 * DESCRIPTION
 *  Hides the left softkey using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_right_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clear_softkey(MMI_RIGHT_SOFTKEY);
}

#ifndef __MMI_WGUI_DISABLE_CSK__
/*****************************************************************************
 * FUNCTION
 *  wgui_clear_center_softkey
 * DESCRIPTION
 *  Hides the left softkey using transparent color
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_clear_center_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_clear_softkey(MMI_CENTER_SOFTKEY);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_hide_left_softkey
 * DESCRIPTION
 *  Hides the left softkey
 *  
 *  Default hide left softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_hide_left_softkey(void)
{
    wgui_softkey_hide(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_hide_right_softkey
 * DESCRIPTION
 *  Hides the right softkey
 *  
 *  Default hide right softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_hide_right_softkey(void)
{
    wgui_softkey_hide(MMI_RIGHT_SOFTKEY);
}

#ifndef __MMI_WGUI_DISABLE_CSK__
/*****************************************************************************
 * FUNCTION
 *  wgui_hide_center_softkey
 * DESCRIPTION
 *  Hides the center softkey
 *  
 *  Default hide center softkey function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_hide_center_softkey(void)
{
    if (wgui_softkey_is_csk_enable == MMI_TRUE)
    {
        wgui_softkey_hide(MMI_CENTER_SOFTKEY);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  register_default_hide_softkeys
 * DESCRIPTION
 *  Registers the default functions to hide the softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_default_hide_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_hide_left_softkey(wgui_hide_left_softkey);
    register_hide_right_softkey(wgui_hide_right_softkey);
	#ifndef __MMI_WGUI_DISABLE_CSK__
    register_hide_softkey(wgui_hide_center_softkey, MMI_CENTER_SOFTKEY);
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  register_default_hide_softkeys_to_transparent
 * DESCRIPTION
 *  Registers the default functions to hide the softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_default_hide_softkeys_to_transparent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_hide_softkey(wgui_clear_left_softkey, MMI_LEFT_SOFTKEY);
    register_hide_softkey(wgui_clear_right_softkey, MMI_RIGHT_SOFTKEY);
	#ifndef __MMI_WGUI_DISABLE_CSK__
    register_hide_softkey(wgui_clear_center_softkey, MMI_CENTER_SOFTKEY);
	#endif
}

static void ChangeSoftkeyExt(U16 s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_softkey_lock_state[key] == MMI_TRUE)
    {
        return;
    }

    /* Redraw the left softkey only if the string changed to enhance efficiency */
    if ((s != STRING_ID_NULL && MMI_softkeys[key].text!= NULL &&
        !mmi_ucs2cmp((const S8 *)get_string(s), (const S8 *)MMI_softkeys[key].text)) ||
        (s == STRING_ID_NULL && MMI_softkeys[key].text == NULL))
    {
        mmi_imc_key_setup_text_handlers[key]();
        return;
    }
	
	setSoftkeyTargetLayer(MMI_FALSE);
    if ( !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY) ||
         !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_TEXT_DISPLAY))
    {
        hide_softkey[key] ();
    }

	restoreSoftkeyTargetLayer();
    change_softkey(s, NULL, key);
    redraw_softkey(key);
    if (s != 0)
    {
        register_softkey_handler(key);
    }
}

/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkey
 * DESCRIPTION
 *  Changes the left softkey label and icon
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkeyExt(U16 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeSoftkeyExt(s, MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  ChangeRightSoftkey
 * DESCRIPTION
 *  Changes the right softkey label and icon
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkeyExt(U16 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeSoftkeyExt(s, MMI_RIGHT_SOFTKEY);
}

//#ifndef __MMI_WGUI_DISABLE_CSK__

/*****************************************************************************
 * FUNCTION
 *  ChangeCenterSoftkey
 * DESCRIPTION
 *  Changes the left softkey label and icon
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeCenterSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__    
    if (wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }

    if (wgui_softkey_lock_state[MMI_CENTER_SOFTKEY] == MMI_TRUE)
    {
        return;
    }

    wgui_softkey_execute_csk_always = MMI_FALSE;

    /* Redraw the center softkey only if the string changed to enhance efficiency */
    if ((s != STRING_ID_NULL && MMI_softkeys[MMI_CENTER_SOFTKEY].text!= NULL &&
        !mmi_ucs2cmp((const S8 *)get_string(s), (const S8 *)MMI_softkeys[MMI_CENTER_SOFTKEY].text)) ||
        (s == STRING_ID_NULL && MMI_softkeys[MMI_CENTER_SOFTKEY].text == NULL))
    {
        if ((i != IMAGE_ID_NULL && get_image(i) == MMI_softkeys[MMI_CENTER_SOFTKEY].normal_up_icon)||
            (i == IMAGE_ID_NULL && MMI_softkeys[MMI_CENTER_SOFTKEY].normal_up_icon == NULL))
        {
            if (i == IMG_NONE)
            {
                wgui_softkey_execute_csk_always = MMI_TRUE;
            }
        /* The following compile option will remove when app finish their change for key rule */
            mmi_imc_key_setup_csk_text();
            mmi_imc_key_setup_csk_icon();
            return;
        }
    }
     setSoftkeyTargetLayer(MMI_FALSE);
    if ( !(MMI_softkeys[MMI_CENTER_SOFTKEY].flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY) ||
         !(MMI_softkeys[MMI_CENTER_SOFTKEY].flags & UI_BUTTON_DISABLE_TEXT_DISPLAY))
    {
        hide_softkey[MMI_CENTER_SOFTKEY] ();
    }
	restoreSoftkeyTargetLayer();

    /* if image is IMG_NONE, we need support to execute csk always */
    if (i == IMG_NONE)
    {
        wgui_softkey_execute_csk_always = MMI_TRUE;
    }

    change_softkey(s, i, MMI_CENTER_SOFTKEY);
 #endif   
    register_softkey_handler(MMI_CENTER_SOFTKEY);
 #ifndef __MMI_WGUI_DISABLE_CSK__   
    redraw_softkey(MMI_CENTER_SOFTKEY);
 #endif
}
//#endif

/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkeyByStringLength
 * DESCRIPTION
 *  Changes the left softkey label and icon and also adjust the width according to the string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeSoftkeyByStringLength(UI_string_type s, PU8 i, WGUI_SOFTKEY_ENUM key)
{
	/*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	wgui_softkey_change_by_length = MMI_TRUE;
	ChangeSoftkeyByString(s, i, key);
}
/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkeyByStringLength
 * DESCRIPTION
 *  Changes the left softkey label and icon and also adjust the width according to the string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkeyByStringLength(UI_string_type s, PU8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeSoftkeyByStringLength(s, i, MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  ChangeRightSoftkeyByStringLength
 * DESCRIPTION
 *  Changes the right softkey label and icon and also adjust the width according to the string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkeyByStringLength(UI_string_type s, PU8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeSoftkeyByStringLength(s, i, MMI_RIGHT_SOFTKEY);
}

/* Calvin end */

/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkeyByString
 * DESCRIPTION
 *  Changes the left softkey label using a dynamic string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeSoftkeyByString(UI_string_type s, PU8 i, WGUI_SOFTKEY_ENUM key)
{
	/*----------------------------------------------------------------*/
	  /* Local Variables												*/
	  /*----------------------------------------------------------------*/
	
	  /*----------------------------------------------------------------*/
	  /* Code Body														*/
	  /*----------------------------------------------------------------*/
	  gui_lock_double_buffer();
      setSoftkeyTargetLayer(MMI_FALSE);
	  if ( !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY) ||
		   !(MMI_softkeys[key].flags & UI_BUTTON_DISABLE_TEXT_DISPLAY))
	  {
		  hide_softkey[key] ();
	  }
	  restoreSoftkeyTargetLayer();
	  if(wgui_softkey_change_by_length)
	  {
	  	resize_softkey_by_string_length(s,key);
		wgui_softkey_change_by_length = MMI_FALSE;
	  }
	  set_softkey_label(s, key);
	  set_softkey_icon(i, key);
	  redraw_softkey(key);
	  gui_unlock_double_buffer();
	  gui_BLT_double_buffer(0, UI_device_height - MMI_softkey_height, UI_device_width - 1, UI_device_height - 1);

}

/*****************************************************************************
 * FUNCTION
 *  ChangeLeftSoftkeyByString
 * DESCRIPTION
 *  Changes the left softkey label using a dynamic string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkeyByString(UI_string_type s, PU8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeSoftkeyByString(s, i, MMI_LEFT_SOFTKEY); 
}


/*****************************************************************************
 * FUNCTION
 *  ChangeRightSoftkeyByString
 * DESCRIPTION
 *  Changes the right softkey label using a dynamic string
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkeyByString(UI_string_type s, PU8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeSoftkeyByString(s, i, MMI_RIGHT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  EnableLeftSoftkey
 * DESCRIPTION
 *  Enable the left soft key , set string and icon of LSK and display LSK
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableLeftSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableSoftkey(s, i, MMI_LEFT_SOFTKEY); 
}

/*****************************************************************************
 * FUNCTION
 *  DisableLeftSoftkey
 * DESCRIPTION
 *  Disable the left soft key , set string and icon of LSK and display LSK
 *  with disable color
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void DisableSoftkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

		set_softkey_label(str, key);
        //set_left_softkey_label(str);
    }
    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);

		set_softkey_icon(img, key);
        //set_left_softkey_icon(img);
    }
    MMI_softkeys[key].flags |= UI_BUTTON_STATE_DISABLED;
    MMI_softkeys[key].disabled_up_filler = NULL;
    MMI_softkeys[key].disabled_down_filler = NULL;
    redraw_softkey(key);
    clear_softkey_handler(key);

}

/*****************************************************************************
 * FUNCTION
 *  DisableLeftSoftkey
 * DESCRIPTION
 *  Disable the left soft key , set string and icon of LSK and display LSK
 *  with disable color
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableSoftkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key)
{
    MMI_softkeys[key].flags &= ~UI_BUTTON_STATE_DISABLED;

    if (s != STRING_ID_NULL)
    {
        UI_string_type str = get_string(s);

        set_softkey_label(str, key);
    }
    if (i != IMAGE_ID_NULL)
    {
        PU8 img = get_image(i);
		#ifndef __MMI_WGUI_DISABLE_CSK__
         /* if image is IMG_NONE, we need support to execute csk always */
        if (key == MMI_CENTER_SOFTKEY && i == IMG_NONE)
        {
            wgui_softkey_execute_csk_always = MMI_TRUE;
        }  
		#endif
        set_softkey_icon(img, key);
    }
    redraw_softkey(key);
    register_softkey_handler(key);
}



/*****************************************************************************
 * FUNCTION
 *  DisableLeftSoftkey
 * DESCRIPTION
 *  Disable the left soft key , set string and icon of LSK and display LSK
 *  with disable color
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void DisableLeftSoftkey(U16 s, U16 i)
{
  DisableSoftkey(s, i, MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  EnableRightSoftkey
 * DESCRIPTION
 *  Enable the right soft key , set string and icon of RSK and display RSK
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableRightSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     EnableSoftkey(s, i, MMI_RIGHT_SOFTKEY); 
}


/*****************************************************************************
 * FUNCTION
 *  DisableRightSoftkey
 * DESCRIPTION
 *  Disable the right soft key , set string and icon of RSK and display RSK
 *  with disable color
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void DisableRightSoftkey(U16 s, U16 i)
{
    DisableSoftkey(s, i, MMI_RIGHT_SOFTKEY);
}


//#ifndef __MMI_WGUI_DISABLE_CSK__
/*****************************************************************************
 * FUNCTION
 *  EnableCenterSoftkey
 * DESCRIPTION
 *  Enable the left soft key , set string and icon of LSK and display LSK
 * PARAMETERS
 *  s       [IN]        Is the string to be displayed in the softkey
 *  i       [IN]        Is the image to be displayed in the softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableCenterSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__
    if (wgui_softkey_is_csk_enable == MMI_FALSE)
    {
        return;
    }

    if (wgui_softkey_lock_state[MMI_CENTER_SOFTKEY] == MMI_TRUE)
    {
        return;
    }

    /* reset wgui_softkey_execute_csk_always */
    wgui_softkey_execute_csk_always = MMI_FALSE;
#endif
    EnableSoftkey(s, i,MMI_CENTER_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  ResetCenterSoftkey
 * DESCRIPTION
 *  Disable center softkey display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCenterSoftkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__    
    if (wgui_softkey_is_csk_enable == MMI_TRUE)
#endif
        change_softkey(0, 0, MMI_CENTER_SOFTKEY);
 
}
#ifndef __MMI_WGUI_DISABLE_CSK__
/*****************************************************************************
 * FUNCTION
 *  EnableCenterSoftkeyDisplay
 * DESCRIPTION
 *  Enable center softkey display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnableCenterSoftkeyDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_rsk_width = ((MMI_SOFTKEY_WIDTH) << 1)/3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_softkey_is_display_csk = MMI_TRUE;
    move_softkey(0, UI_device_height - MMI_SOFTKEY_HEIGHT, MMI_LEFT_SOFTKEY);
    move_softkey(UI_device_width - lsk_rsk_width, UI_device_height - MMI_SOFTKEY_HEIGHT, MMI_RIGHT_SOFTKEY);
    move_softkey(lsk_rsk_width, UI_device_height - MMI_SOFTKEY_HEIGHT, MMI_CENTER_SOFTKEY);
    resize_softkey(lsk_rsk_width, MMI_SOFTKEY_HEIGHT, MMI_LEFT_SOFTKEY);
    resize_softkey(lsk_rsk_width, MMI_SOFTKEY_HEIGHT, MMI_RIGHT_SOFTKEY);
    resize_softkey(UI_device_width - (lsk_rsk_width << 1), MMI_SOFTKEY_HEIGHT, MMI_CENTER_SOFTKEY);
}

/*****************************************************************************
 * FUNCTION
 *  DisableCenterSoftkeyDisplay
 * DESCRIPTION
 *  Enable center softkey display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisableCenterSoftkeyDisplay(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_softkey_is_display_csk = MMI_FALSE;
    move_softkey(0, UI_device_height - MMI_SOFTKEY_HEIGHT, MMI_LEFT_SOFTKEY);
    move_softkey(UI_device_width - MMI_SOFTKEY_WIDTH, UI_device_height - MMI_SOFTKEY_HEIGHT, MMI_RIGHT_SOFTKEY);
    move_softkey(MMI_SOFTKEY_WIDTH, UI_device_height - MMI_SOFTKEY_HEIGHT, MMI_CENTER_SOFTKEY);
    resize_softkey(MMI_SOFTKEY_WIDTH, MMI_SOFTKEY_HEIGHT, MMI_LEFT_SOFTKEY);
    resize_softkey(MMI_SOFTKEY_WIDTH, MMI_SOFTKEY_HEIGHT, MMI_RIGHT_SOFTKEY);
    resize_softkey(MMI_CENTER_SOFTKEY_WIDTH, MMI_SOFTKEY_HEIGHT, MMI_CENTER_SOFTKEY);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  SetLeftSoftkeyAlwaysKeyUpByPen
 * DESCRIPTION
 *  Emulate Key Up event even when pen is up outside the LSK button
 *  (By default, Key Up is only generated when pen is up inside a button)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetLeftSoftkeyAlwaysKeyUpByPen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_softkey_flags_on(UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE, MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  SetRightSoftkeyAlwaysKeyUpByPen
 * DESCRIPTION
 *  Emulate Key Up event even when pen is up outside the RSK button
 *  (By default, Key Up is only generated when pen is up inside a button)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetRightSoftkeyAlwaysKeyUpByPen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_softkey_flags_on(UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE, MMI_RIGHT_SOFTKEY);
}

#ifndef __MMI_WGUI_DISABLE_CSK__	

/*****************************************************************************
 * FUNCTION
 *  SetCenterSoftkeyAlwaysKeyUpByPen
 * DESCRIPTION
 *  Emulate Key Up event even when pen is up outside the center softkey
 *  (By default, Key Up is only generated when pen is up inside a button)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCenterSoftkeyAlwaysKeyUpByPen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_softkey_is_csk_enable == MMI_TRUE)
    {
        set_softkey_flags_on(UI_BUTTON_ALWAYS_SEND_PEN_UP_INSIDE, MMI_CENTER_SOFTKEY);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  SetLeftSoftkeyFunction
 * DESCRIPTION
 *  Sets the function that is called when a particular softkey event occurs
 * PARAMETERS
 *  f       [IN]        Is the function that is called
 *  k       [IN]        Is the key event (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void SetSoftkeyFunction(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_softkey_lock_state[key] == MMI_TRUE)
    {
        return;
    }

    register_softkey_handler(key);
    set_softkey_function(f, k, key);

	switch(key)
	{
	case MMI_LEFT_SOFTKEY:
      mmi_imc_key_setup_lsk_function(f);
	  break;
	case MMI_RIGHT_SOFTKEY:
	  mmi_imc_key_setup_rsk_function(f);
	  break;
//#ifndef __MMI_WGUI_DISABLE_CSK__	  
	case MMI_CENTER_SOFTKEY:
		mmi_imc_key_setup_csk_function(f);
		break;
//#endif		
		
	}


}

/*****************************************************************************
 * FUNCTION
 *  SetLeftSoftkeyFunction
 * DESCRIPTION
 *  Sets the function that is called when a particular softkey event occurs
 * PARAMETERS
 *  f       [IN]        Is the function that is called
 *  k       [IN]        Is the key event (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetSoftkeyFunction(f, k, MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  SetRightSoftkeyFunction
 * DESCRIPTION
 *  Sets the function that is called when a particular softkey event occurs
 * PARAMETERS
 *  f       [IN]        Is the function that is called
 *  k       [IN]        Is the key event (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void SetRightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetSoftkeyFunction(f, k, MMI_RIGHT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  SetCenterSoftkeyFunction
 * DESCRIPTION
 *  Sets the function that is called when a particular softkey event occurs
 * PARAMETERS
 *  f       [IN]        Is the function that is called
 *  k       [IN]        Is the key event (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void SetCenterSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WGUI_DISABLE_CSK__	
    if (wgui_softkey_is_csk_enable == MMI_TRUE)  
#endif     
       SetSoftkeyFunction(f, k, MMI_CENTER_SOFTKEY);

    mmi_imc_key_setup_csk_function(f);  

}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_target_layer
 * DESCRIPTION
 *  set softkey's target layer
 * PARAMETERS
 *  target_layer        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_target_layer(GDI_HANDLE target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_softkey_target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_double_buffer_enable
 * DESCRIPTION
 *  Set whether to enable double buffer of softkey 
 * PARAMETERS
 *  enable_double_buffer        [IN]    state of enable double buffer or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_double_buffer_enable(MMI_BOOL enable_double_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WGUI_SOFTKEY_ENUM i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  wgui_softkey_enable_double_buffer = enable_double_buffer;
  
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    {
       if(enable_double_buffer)	   	
	      set_softkey_flags_on(UI_BUTTON_ENABLE_DOUBLE_BUFFER, i);
	   else
		   set_softkey_flags_off(UI_BUTTON_ENABLE_DOUBLE_BUFFER, i);
	   	   
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_double_buffer_enable
 * DESCRIPTION
 *  Get whether to enable double buffer of softkey 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE : Enable softkey to use double buffer.
 *  MMI_FALSE : Disable softkey to use double buffer.
 * REMARKS
 *  Softkey will not use double buffer in default.
 *****************************************************************************/
MMI_BOOL wgui_softkey_get_double_buffer_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_softkey_enable_double_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_target_layer
 * DESCRIPTION
 *  get softkey's target layer
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE wgui_softkey_get_target_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_softkey_target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_abm_layer
 * DESCRIPTION
 *  set softkey's abm source layer
 * PARAMETERS
 *  abm_layer        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_abm_layer(GDI_HANDLE abm_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_softkey_abm_layer = abm_layer;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_abm_layer
 * DESCRIPTION
 *  get softkey's abm layer
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE wgui_softkey_get_abm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_softkey_abm_layer;
}

#ifndef __MMI_WGUI_DISABLE_CSK__
/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_is_csk_registered_to_enter_key
 * DESCRIPTION
 *  is center soft key registered to enter key
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_softkey_is_csk_registered_to_enter_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_softkey_is_csk_enable == MMI_TRUE)
    {
        return wgui_softkey_is_csk_on_enter_key;
    }
    return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_reset_theme
 * DESCRIPTION
 *  reset softkey's theme
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
void wgui_softkey_reset_theme(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_FTE_SUPPORT__
        MMI_softkeys[key].normal_up_filler = NULL;
        MMI_softkeys[key].normal_down_filler = NULL;
        MMI_softkeys[key].clicked_up_filler = NULL;
        MMI_softkeys[key].clicked_down_filler = NULL;
    #else /* __MMI_FTE_SUPPORT__ */
        MMI_softkeys[key].normal_up_filler = current_MMI_theme->softkey_lsk_up_filler;
        MMI_softkeys[key].normal_down_filler = current_MMI_theme->softkey_lsk_down_filler;
        MMI_softkeys[key].clicked_up_filler = current_MMI_theme->softkey_lsk_up_filler;
        MMI_softkeys[key].clicked_down_filler = current_MMI_theme->softkey_lsk_down_filler;
    #endif /* __MMI_FTE_SUPPORT__ */
        MMI_softkeys[key].normal_up_text_color = *current_MMI_theme->LSK_up_text_color;
        MMI_softkeys[key].normal_down_text_color = *current_MMI_theme->LSK_down_text_color;
        MMI_softkeys[key].normal_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
        MMI_softkeys[key].normal_down_text_border_color = *current_MMI_theme->softkey_down_text_border_color;
        MMI_softkeys[key].clicked_up_text_color = *current_MMI_theme->LSK_up_text_color;
        MMI_softkeys[key].clicked_down_text_color = *current_MMI_theme->LSK_down_text_color;
        MMI_softkeys[key].clicked_up_text_border_color = *current_MMI_theme->softkey_text_border_color;
        MMI_softkeys[key].clicked_down_text_border_color = *current_MMI_theme->softkey_down_text_border_color;
        MMI_softkeys[key].text_font = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_theme
 * DESCRIPTION
 *  set softkey's theme
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
void wgui_softkey_set_theme(
      WGUI_SOFTKEY_ENUM key,
      UI_filled_area *up_filler,
      UI_filled_area *down_filler,
      color up_text_color,
      color down_text_color,
      color text_border_color,
      UI_font_type text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        MMI_softkeys[key].normal_up_filler = up_filler;
        MMI_softkeys[key].normal_down_filler = down_filler;
        MMI_softkeys[key].clicked_up_filler = up_filler;
        MMI_softkeys[key].clicked_down_filler = down_filler;
        MMI_softkeys[key].normal_up_text_color = up_text_color;
        MMI_softkeys[key].normal_down_text_color = down_text_color;
        MMI_softkeys[key].normal_up_text_border_color = text_border_color;
        MMI_softkeys[key].normal_down_text_border_color = text_border_color;
        MMI_softkeys[key].clicked_up_text_color = up_text_color;
        MMI_softkeys[key].clicked_down_text_color = down_text_color;
        MMI_softkeys[key].clicked_up_text_border_color = text_border_color;
        MMI_softkeys[key].clicked_down_text_border_color = text_border_color;
        MMI_softkeys[key].text_font = text_font;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_disable_text_translucence
 * DESCRIPTION
 *  disable the softkey's text translucence effect
 *  add only for video play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
void wgui_softkey_disable_text_translucence(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    U8 i = 0;
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
   #ifndef __MMI_WGUI_DISABLE_CSK__ 
        if (i == MMI_CENTER_SOFTKEY && wgui_softkey_is_csk_enable == MMI_FALSE)
        {
            continue;
        }
	#endif	
        MMI_softkeys[i].flags |= UI_BUTTON_TEXT_NO_TRANSLUCENCE;
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
}
 

 /*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_in_popup
 * DESCRIPTION
 *  set in popup screen or not
 * PARAMETERS
 *  MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_is_in_popup(MMI_BOOL is_in_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_softkey_is_in_popup_screen = is_in_popup;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_is_in_popup
 * DESCRIPTION
 *  get is in popup screen or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_softkey_is_in_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_softkey_is_in_popup_screen;
}

#ifndef __MMI_WGUI_DISABLE_CSK__
/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_is_center_softkey_registered
 * DESCRIPTION
 *  Is center softkey be registered or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE : If center softkey be registered.
 *  MMI_FALSE : If center softkey not be registered.
 *****************************************************************************/
MMI_BOOL wgui_softkey_is_center_softkey_registered(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_softkey_is_csk_enable == MMI_TRUE &&
        (MMI_softkeys[MMI_CENTER_SOFTKEY].text != NULL ||
         MMI_softkeys[MMI_CENTER_SOFTKEY].normal_up_icon != NULL))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_is_csk_enable
 * DESCRIPTION
 *  get center softkey is enable or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_softkey_is_csk_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_softkey_is_csk_enable;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_disable_softkey
 * DESCRIPTION
 *  Disable all softkey and redraw.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_disable_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WGUI_SOFTKEY_ENUM i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    	{
    MMI_softkeys[i].flags |= UI_BUTTON_STATE_DISABLED;
    	}
    gdi_layer_lock_frame_buffer();
	
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    {
	    redraw_softkey(i);
    //redraw_softkey(MMI_RIGHT_SOFTKEY);
    //redraw_softkey(MMI_CENTER_SOFTKEY);
    	}
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        0, 
        UI_device_height - MMI_softkey_height,
        UI_device_width - 1,
        UI_device_height - 1);
	
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    	{
    clear_softkey_handler(i);
    	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_enable_softkeys
 * DESCRIPTION
 *  Enable all softkey and redraw.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_enable_softkeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	WGUI_SOFTKEY_ENUM i;
#ifdef __MMI_TOUCH_SCREEN__
    S32 x1, y1, x2, y2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    {
    #ifndef __MMI_WGUI_DISABLE_CSK__
        if (wgui_softkey_is_csk_enable == MMI_FALSE && i == MMI_CENTER_SOFTKEY)
        {
            continue;
        }
	#endif	
	    MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_DISABLED;
	    MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_CLICKED;
	    MMI_softkeys[i].flags &= ~UI_BUTTON_STATE_DOWN;
    }
    gdi_layer_lock_frame_buffer();
#ifdef __MMI_TOUCH_SCREEN__
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    {
    #ifndef __MMI_WGUI_DISABLE_CSK__
        if (wgui_softkey_is_csk_enable == MMI_FALSE && i == MMI_CENTER_SOFTKEY)
        {
            continue;
        }
	#endif	
        gui_resize_icontext_button(
            &MMI_softkeys[i],
            MMI_softkeys[i].width,
            MMI_softkeys[i].height);
	#ifndef __MMI_UI_SOFTKEY_SLIM__
        wgui_softkey_is_need_sync_text_y = MMI_TRUE;
	#endif
        gui_icontext_button_get_display_area(&MMI_softkeys[i], &x1, &y1, &x2, &y2);
        x1 -= WGUI_SOFTKEY_TOUCH_GAP;
        x2 += WGUI_SOFTKEY_TOUCH_GAP;
        if (x1 < MMI_softkeys[i].x)
            x1 = MMI_softkeys[i].x;
        if (x2 > MMI_softkeys[i].x + MMI_softkeys[i].width - 1)
            x2 = MMI_softkeys[i].x + MMI_softkeys[i].width - 1;
        gui_icontext_button_overwirte_pen_response_area(
            &MMI_softkeys[i],
            x1,
            MMI_softkeys[i].y,
            x2,
            MMI_softkeys[i].y + MMI_softkeys[i].height - 1);
    }
#endif /* __MMI_TOUCH_SCREEN__ */
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    {
	    redraw_softkey(i);
   // redraw_softkey(MMI_RIGHT_SOFTKEY);
   // redraw_softkey(MMI_CENTER_SOFTKEY);
    }
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        0, 
        UI_device_height - MMI_softkey_height,
        UI_device_width - 1,
        UI_device_height - 1);
	
    for (i = MMI_LEFT_SOFTKEY; i < WGUI_MAX_SOFTKEYS; i++)
    {
	   register_softkey_handler(i);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_get_hide_func_ptr
 * DESCRIPTION
 *  Get the softkey hide function pointer.
 * PARAMETERS
 *  void
 * RETURNS
 *  WGUISoftkeyHideFuncPtr
 *****************************************************************************/
WGUISoftkeyHideFuncPtr wgui_softkey_get_hide_func_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (WGUISoftkeyHideFuncPtr)wgui_softkey_hide;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_set_hide_func_ptr
 * DESCRIPTION
 *  Set the softkey hide function pointer.
 * PARAMETERS
 *  f       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_hide_func_ptr(WGUISoftkeyHideFuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_softkey_hide = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_lock_softkey
 * DESCRIPTION
 *  Lock softkey .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_lock_softkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }

    change_softkey(s, i, key);
    wgui_softkey_lock_state[key] = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_unlock_softkey
 * DESCRIPTION
 *  Unlock softkey .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_unlock_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key >= WGUI_MAX_SOFTKEY_FUNCTIONS)
    {
        return;
    }

    wgui_softkey_lock_state[key] = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_update
 * DESCRIPTION
 *  Update the whole softkey display to LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < WGUI_MAX_SOFTKEYS; i++)
    {
        redraw_softkey((WGUI_SOFTKEY_ENUM)i);
    }
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        0,
        UI_device_height - MMI_softkey_height,
        UI_device_width - 1,
        UI_device_height - 1);
}

