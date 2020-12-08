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
 *   wgui_softkeys.h
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
 * 12 25 2012 hujin.hu
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
 */

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

/**********************************************************************************
   Filename:      wgui_softkeys.h
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines header for softkeys
**********************************************************************************/

#ifndef __WGUI_SOFTKEYS_H__
#define __WGUI_SOFTKEYS_H__
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "gui_buttons.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "ScreenRotationGprot.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 




/* Softkey wrappers        */
extern icontext_button MMI_softkeys[WGUI_MAX_SOFTKEYS];

#define  MMI_left_softkey  MMI_softkeys[MMI_LEFT_SOFTKEY]
#define MMI_right_softkey  MMI_softkeys[MMI_RIGHT_SOFTKEY]
#define  MMI_center_softkey   MMI_softkeys[MMI_CENTER_SOFTKEY]

#define WGUI_SOFTKEY_STRING_GAP  4
   
typedef void (*WGUISoftkeyHideFuncPtr) (WGUI_SOFTKEY_ENUM key);
   
//extern MMI_BOOL MMI_softkey_filler_disabled;
    extern S32 MMI_softkey_width;
    extern S32 MMI_softkey_height;
	extern S32 MMI_center_softkey_width;

    extern U8 left_softkey_keyboard_handler_active;
    extern U8 right_softkey_keyboard_handler_active;

#define resize_left_softkey_by_string_length( S )  resize_softkey_by_string_length(S,MMI_LEFT_SOFTKEY)
#define resize_right_softkey_by_string_length( S ) resize_softkey_by_string_length(S,MMI_RIGHT_SOFTKEY)
#define set_left_softkey_label_for_IME( S )     set_softkey_label_for_IME(S,MMI_LEFT_SOFTKEY)
#define set_right_softkey_label_for_IME( S )     set_softkey_label_for_IME(S,MMI_RIGHT_SOFTKEY)

#define reset_left_softkey()                 reset_softkey(MMI_LEFT_SOFTKEY)
#define reset_right_softkey()                reset_softkey(MMI_RIGHT_SOFTKEY)

    extern void create_softkeys(void);
    extern void resize_softkey_by_string_length(UI_string_type s, WGUI_SOFTKEY_ENUM key);
    extern void left_softkey_down(void);
    extern void left_softkey_up(void);
    extern void right_softkey_down(void);
    extern void right_softkey_up(void);
    extern void update_softkey_state_no_redraw( U16 KeyCode, U16 KeyType);
    extern void reset_softkey(WGUI_SOFTKEY_ENUM key);

/* Only for input method, Application can not invoke this function*/
extern void set_softkey_label_for_IME(UI_string_type s, WGUI_SOFTKEY_ENUM key);   
extern void wgui_softkey_set_icon_for_IME(PU8 icon, WGUI_SOFTKEY_ENUM key);
extern void register_default_hide_softkeys_to_transparent(void);

/* 030705 Calvin added */
extern void ChangeLeftSoftkeyByStringLength(UI_string_type s, PU8 i);
extern void ChangeRightSoftkeyByStringLength(UI_string_type s, PU8 i);
extern GDI_HANDLE wgui_softkey_get_target_layer(void);
extern GDI_HANDLE wgui_softkey_get_abm_layer(void);
void SetCenterSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
void register_center_softkey_to_enter_key(void);
void EnableCenterSoftkey(U16 s, U16 i);
void ResetCenterSoftkey(void);
void ChangeCenterSoftkey(U16 s, U16 i);
#ifndef __MMI_WGUI_DISABLE_CSK__
MMI_BOOL wgui_softkey_is_csk_registered_to_enter_key(void);
MMI_BOOL wgui_softkey_is_center_softkey_registered(void);
MMI_BOOL wgui_softkey_is_csk_enabled(void);
void SetCenterSoftkeyAlwaysKeyUpByPen(void); 


void EnableCenterSoftkeyDisplay(void);  
void DisableCenterSoftkeyDisplay(void);
#else
#define wgui_softkey_is_csk_registered_to_enter_key() 
#define wgui_softkey_is_center_softkey_registered() 
#define wgui_softkey_is_csk_enabled() 
//#define ChangeCenterSoftkey(_arg1, _arg2)  
//#define EnableCenterSoftkey(_arg1, _arg2) 
//#define ResetCenterSoftkey() 
#define DisableCenterSoftkeyDisplay() 
#define EnableCenterSoftkeyDisplay() 
//#define wgui_clear_center_softkey() 0
#define wgui_clear_center_softkey 
#define wgui_hide_center_softkey() 
#define SetCenterSoftkeyAlwaysKeyUpByPen() 

#endif

void setSoftkeyTargetLayer(MMI_BOOL enable_double_buffer);
void restoreSoftkeyTargetLayer(void);


/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  set_softkey_function
 * DESCRIPTION
 *  Set the key event function to one specific softkey.
 * REMARKS
 *  This API is a corresponding API of get_softkey_function.
 * PARAMETERS
 *  f        : [IN] Is the function handler which will be called when one specific key event occurs
 *  k        : [IN] Is the key event
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  get_softkey_function
 * DESCRIPTION
 *  Set the key event function of one specific softkey.
 * REMARKS
 *  This API is a corresponding API of set_softkey_function.
 * PARAMETERS
 *  k        : [IN] Is the key event
 *  key      : [IN] Is the softkey
 * RETURNS
 *  FuncPtr
 * RETURN VALUES
 *  FuncPtr : Is the key event function handler.
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
FuncPtr get_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_misc>
 * FUNCTION
 *  execute_softkey_function
 * DESCRIPTION
 *  Execute key event function of one specific softkey when particular softkey event occurs.
 * PARAMETERS
 *  k        : [IN] Is the key event
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void execute_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_basic>
 * FUNCTION
 *  redraw_softkey
 * DESCRIPTION
 *  Redraw the one specific softkey's content to main LCD and blt it to main LCD.
 * PARAMETERS
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void redraw_softkey(WGUI_SOFTKEY_ENUM key);


/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  ChangeLeftSoftkey
 * DESCRIPTION
 *  Changes the string and icon of left softkey and redraw.
 * PARAMETERS
 *  s        : [IN] Is the string of left softkey
 *  i        : [IN] Is the icon of left softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkeyExt(U16 s);
#define ChangeLeftSoftkey(s, i)  ChangeLeftSoftkeyExt(s)

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  ChangeRightSoftkey
 * DESCRIPTION
 *  Changes the string and icon of right softkey and redraw.
 * PARAMETERS
 *  s        : [IN] Is the string of right softkey
 *  i        : [IN] Is the icon of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkeyExt(U16 s);
#define ChangeRightSoftkey(s, i)    ChangeRightSoftkeyExt(s)

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  EnableLeftSoftkey
 * DESCRIPTION
 *  Set string and icon to left softkey, redraw left softkey and regiester left softkey to KEY_LSK.
 * PARAMETERS
 *  s        : [IN] Is the string of left softkey
 *  i        : [IN] Is the image of left softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableLeftSoftkey(U16 s, U16 i);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  DisableLeftSoftkey
 * DESCRIPTION
 *  Disable the left softkey, set string and icon to left softkey and redraw left softkey
 *  with disabled color.
 * PARAMETERS
 *  s        : [IN] Is the string of left softkey
 *  i        : [IN] Is the image of left softkey
 * RETURNS
 *  void
 *****************************************************************************/
void DisableLeftSoftkey(U16 s, U16 i);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  EnableRightSoftkey
 * DESCRIPTION
 *  Set string and icon to right softkey, redraw right softkey and regiester right softkey to KEY_RSK.
 * PARAMETERS
 *  s        : [IN] Is the string of right softkey
 *  i        : [IN] Is the image of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
void EnableRightSoftkey(U16 s, U16 i);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  DisableRightSoftkey
 * DESCRIPTION
 *  Disable the right softkey, set string and icon to right softkey and redraw right softkey
 *  with disabled color.
 * PARAMETERS
 *  s        : [IN] Is the string of right softkey
 *  i        : [IN] Is the image of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
void DisableRightSoftkey(U16 s, U16 i);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  SetLeftSoftkeyFunction
 * DESCRIPTION
 *  Set the key event function to left softkey and register left softkey to KEY_LSK.
 * PARAMETERS
 *  f        : [IN] Is the key event function handler which will be called when one specific key event occurs
 *  k        : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  SetRightSoftkeyFunction
 * DESCRIPTION
 *  Set the key event function to right softkey and register right softkey to KEY_RSK.
 * PARAMETERS
 *  f        : [IN] Is the key event function handler which will be called when one specific key event occurs
 *  k        : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
void SetRightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_misc>
 * FUNCTION
 *  wgui_softkey_disable_softkey
 * DESCRIPTION
 *  Disable all softkey and redraw.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_disable_softkeys(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_misc>
 * FUNCTION
 *  wgui_softkey_enable_softkeys
 * DESCRIPTION
 *  Enable all softkey and redraw.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_enable_softkeys(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_misc>
 * FUNCTION
 *  wgui_softkey_lock_softkey
 * DESCRIPTION
 *  Lock softkey.
 * PARAMETERS
 *  s       : [IN] Is the new string of softkey
 *  i       : [IN] Is the new icon of softkey
 *  key     : [IN] Is the key enum of softkey
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_lock_softkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key);


/*****************************************************************************
 * <group dom_softkey_wgui_layer_misc>
 * FUNCTION
 *  wgui_softkey_unlock_softkey
 * DESCRIPTION
 *  Unlock softkey.
 * PARAMETERS
 *  key     : [IN] Is the key enum of softkey
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_unlock_softkey(WGUI_SOFTKEY_ENUM key);

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
void wgui_softkey_update(void);


/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_left_softkey_function
 * DESCRIPTION
 *  Set the key event function to left softkey.
 * PARAMETERS
 *  FUNC      : [IN] Is the function handler which will be called when one specific key event occurs
 *  KEY_TYPE  : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
#define set_left_softkey_function(FUNC, KEY_TYPE)       set_softkey_function(FUNC, KEY_TYPE, MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_right_softkey_function
 * DESCRIPTION
 *  Set the key event function to right softkey.
 * PARAMETERS
 *  FUNC      : [IN] Is the function handler which will be called when one specific key event occurs
 *  KEY_TYPE  : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
#define set_right_softkey_function(FUNC, KEY_TYPE)      set_softkey_function(FUNC, KEY_TYPE, MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  get_left_softkey_function
 * DESCRIPTION
 *  Get the key event function of left softkey.
 * REMARKS
 *  This API is the corresponding API of set_left_softkey_function.
 * PARAMETERS
 *  k        : [IN] Is the key event
 * RETURNS
 *  FuncPtr
 * RETURN VALUES
 *  FuncPtr : Is the function handler which will be called when one specific key event occurs.
 *****************************************************************************/
#define get_left_softkey_function(KEY_TYPE)             get_softkey_function(KEY_TYPE, MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  get_right_softkey_function
 * DESCRIPTION
 *  Get the key event function of right softkey.
 * REMARKS
 *  This API is the corresponding API of set_right_softkey_function.
 * PARAMETERS
 *  k        : [IN] Is the key event
 * RETURNS
 *  FuncPtr
 * RETURN VALUES
 *  FuncPtr : Is the function handler which will be called when one specific key event occurs.
 *****************************************************************************/
#define get_right_softkey_function(KEY_TYPE)            get_softkey_function(KEY_TYPE, MMI_RIGHT_SOFTKEY)


/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  execute_left_softkey_function
 * DESCRIPTION
 *  Execute key event function of left softkey when particular softkey event occurs.
 * PARAMETERS
 *  k        : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
#define execute_left_softkey_function(KEY_TYPE)         execute_softkey_function(KEY_TYPE,MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  execute_right_softkey_function
 * DESCRIPTION
 *  Execute key event function of right softkey when particular softkey event occurs.
 * PARAMETERS
 *  k        : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
#define execute_right_softkey_function(KEY_TYPE)        execute_softkey_function(KEY_TYPE,MMI_RIGHT_SOFTKEY)


/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  redraw_left_softkey
 * DESCRIPTION
 *  Redraw the left softkey's content to main LCD and blt it to main LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define redraw_left_softkey()                           redraw_softkey(MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  redraw_right_softkey
 * DESCRIPTION
 *  Redraw the right softkey's content to main LCD and blt it to main LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define redraw_right_softkey()                          redraw_softkey(MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  redraw_center_softkey
 * DESCRIPTION
 *  Redraw the center softkey's content to main LCD and blt it to main LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define redraw_center_softkey()                         redraw_softkey(MMI_CENTER_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  resize_left_softkey
 * DESCRIPTION
 *  Resize left softkey to new dimension.
 * PARAMETERS
 *  WIDTH        : [IN] Is the new width of left softkey
 *  HEIGHT       : [IN] Is the new height of left softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define resize_left_softkey(WIDTH, HEIGHT)          resize_softkey(WIDTH, HEIGHT,MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  resize_right_softkey
 * DESCRIPTION
 *  Resize right softkey to new dimension.
 * PARAMETERS
 *  WIDTH        : [IN] Is the new width of right softkey
 *  HEIGHT       : [IN] Is the new height of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define resize_right_softkey(WIDTH, HEIGHT)         resize_softkey(WIDTH, HEIGHT,MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_left_softkey_label
 * DESCRIPTION
 *  Set the string to left softkey.
 * PARAMETERS
 *  s        : [IN] Is the new string of left softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define set_left_softkey_label(S)                   set_softkey_label(S, MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_right_softkey_label
 * DESCRIPTION
 *  Set the string to right softkey.
 * PARAMETERS
 *  s        : [IN] Is the new string of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define set_right_softkey_label(S)                  set_softkey_label(S, MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  get_left_softkey_label
 * DESCRIPTION
 *  Get the string of left softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 * RETURN VALUES
 *  UI_string_type : Is the string of left softkey.
 *****************************************************************************/
#define get_left_softkey_label()                    get_softkey_label(MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  get_right_softkey_label
 * DESCRIPTION
 *  Get the string of right softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 * RETURN VALUES
 *  UI_string_type : It is the string of right softkey.
 *****************************************************************************/
#define get_right_softkey_label()                   get_softkey_label(MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  get_center_softkey_icon
 * DESCRIPTION
 *  Get the icon of center softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  PU8
 * RETURN VALUES
 *  PU8 : It is the icon of center softkey.
 *****************************************************************************/
#define get_center_softkey_icon()                   get_softkey_icon(MMI_CENTER_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_left_softkey_icon
 * DESCRIPTION
 *  Set the icon to left softkey.
 * PARAMETERS
 *  ICON         : [IN] Is the new icon of left softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define set_left_softkey_icon(ICON)                 set_softkey_icon(ICON, MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_right_softkey_icon
 * DESCRIPTION
 *  Set the icon to right softkey.
 * PARAMETERS
 *  ICON         : [IN] Is the new icon of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define set_right_softkey_icon(ICON)                set_softkey_icon(ICON, MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  change_left_softkey
 * DESCRIPTION
 *  Change the string and icon of left softkey.
 * PARAMETERS
 *  S        : [IN] Is the new string of left softkey
 *  I        : [IN] Is the new icon of left softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define change_left_softkey(S, I)                   change_softkey(S, I, MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  change_right_softkey
 * DESCRIPTION
 *  Changes the string and icon of right softkey.
 * PARAMETERS
 *  S        : [IN] Is the new string of right softkey
 *  I        : [IN] Is the new icon of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
#define change_right_softkey(S, I)                  change_softkey(S, I, MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_left_softkey
 * DESCRIPTION
 *  Set the string and key event function to the left softkey.
 * PARAMETERS
 *  S          : [IN] Is the new string of left softkey
 *  FUNC       : [IN] Is the key event function handler which will be called when one specific key event occurs
 *  KEY_TYPE   : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
#define set_left_softkey(S, FUNC, KEY_TYPE)         set_softkey(S, FUNC, KEY_TYPE, MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  set_right_softkey
 * DESCRIPTION
 *  Set the string and key event function to the left softkey.
 * PARAMETERS
 *  S        : [IN] Is the new string of right softkey
 *  FUNC     : [IN] Is the key event function handler which will be called when one specific key event occurs
 *  KEY_TYPE : [IN] Is the key event
 * RETURNS
 *  void
 *****************************************************************************/
#define set_right_softkey(S, FUNC, KEY_TYPE)        set_softkey(S, FUNC, KEY_TYPE, MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  clear_left_softkey
 * DESCRIPTION
 *  Clear hide callback function and all key event functions of left softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define clear_left_softkey()                        clear_softkey_display_functions(MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  clear_right_softkey
 * DESCRIPTION
 *  Clear hide callback function and all key event functions of right softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define clear_right_softkey()                       clear_softkey_display_functions(MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  show_left_softkey
 * DESCRIPTION
 *  Display left softkey to main LCD but not blt.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define show_left_softkey()                         show_softkey(MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  show_right_softkey
 * DESCRIPTION
 *  Display right softkey to main LCD but not blt.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define show_right_softkey()                        show_softkey(MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  register_hide_left_softkey
 * DESCRIPTION
 *  Register the hide callback function to left softkeys.
 * PARAMETERS
 *  f        : [IN] Is the handler of hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
#define register_hide_left_softkey(FUNC)            register_hide_softkey(FUNC, MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  register_hide_right_softkey
 * DESCRIPTION
 *  Register the hide callback function to right softkeys.
 * PARAMETERS
 *  f        : [IN] Is the handler of hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
#define register_hide_right_softkey(FUNC)           register_hide_softkey(FUNC, MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  register_left_softkey_handler
 * DESCRIPTION
 *  Register left softkey's key handler to KEY_LSK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define register_left_softkey_handler()             register_softkey_handler(MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  register_right_softkey_handler
 * DESCRIPTION
 *  Register right softkey's key handler to KEY_RSK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define register_right_softkey_handler()            register_softkey_handler(MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  clear_left_softkey_handler
 * DESCRIPTION
 *  Clear key handler of left softkey from KEY_LSK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define clear_left_softkey_handler()                clear_softkey_handler(MMI_LEFT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_macro>
 * FUNCTION
 *  clear_right_softkey_handler
 * DESCRIPTION
 *  Clear key handler of right softkey from KEY_RSK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define clear_right_softkey_handler()               clear_softkey_handler(MMI_RIGHT_SOFTKEY)

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  register_softkey_handler
 * DESCRIPTION
 *  Register softkey's key handler to corresponding key.
 * PARAMETERS
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void register_softkey_handler(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  set_softkey_label
 * DESCRIPTION
 *  Set the string to softkey.
 * PARAMETERS
 *  s        : [IN] Is the new string of softkey
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void set_softkey_label(UI_string_type s, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  get_softkey_label
 * DESCRIPTION
 *  Get the string of softkey.
 * PARAMETERS
 *  key      : [IN] Is the softkey
 * RETURNS
 *  UI_string_type
 * RETURN VALUES
 *  UI_string_type : Is the string of softkey.
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
UI_string_type get_softkey_label(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  set_softkey_icon
 * DESCRIPTION
 *  Set the icon to softkey.
 * PARAMETERS
 *  icon         : [IN] Is the new icon of softkey
 *  key          : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void set_softkey_icon(PU8 i, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  get_softkey_icon
 * DESCRIPTION
 *  Get the icon of softkey.
 * PARAMETERS
 *  key      : [IN] Is the softkey
 * RETURNS
 *  PU8
 * RETURN VALUES
 *  PU8 : It is the icon of softkey.
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
PU8 get_softkey_icon(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  change_softkey
 * DESCRIPTION
 *  Change the string and icon of softkey.
 * PARAMETERS
 *  s        : [IN] Is the new string of softkey
 *  i        : [IN] Is the new icon of softkey
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void change_softkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_basic>
 * FUNCTION
 *  show_softkey
 * DESCRIPTION
 *  Display softkey to main LCD but not blt.
 * PARAMETERS
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void show_softkey(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  register_hide_softkey
 * DESCRIPTION
 *  Register the hide callback function to softkeys.
 * PARAMETERS
 *  f        : [IN] Is the handler of hide callback function
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void register_hide_softkey(void (*f) (void), WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_misc>
 * FUNCTION
 *  clear_softkey_display_functions
 * DESCRIPTION
 *  Clear hide callback function and all key event functions of softkey.
 * PARAMETERS
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void clear_softkey_display_functions(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_basic>
 * FUNCTION
 *  reset_softkeys
 * DESCRIPTION
 *  Sets all softkeys' states to normal and clear hide callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_softkeys(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_misc>
 * FUNCTION
 *  clear_softkey_handler
 * DESCRIPTION
 *  Clear key handler of softkey from corresponding key.
 * PARAMETERS
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void clear_softkey_handler(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  enable_softkey_background
 * DESCRIPTION
 *  Enable to display the background of softkeys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void enable_softkey_background(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  disable_softkey_background
 * DESCRIPTION
 *  Disable to display the background of softkeys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_softkey_background(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_set_filler_disabled
 * DESCRIPTION
 *  Set the enable state of softkey's filler.
 * PARAMETERS
 *  filler_disabled     : [IN] Is the enable state of softkey's filler
 * RETURNS
 *  void
 *****************************************************************************/
//void wgui_softkey_set_filler_disabled(MMI_BOOL filler_disabled);
#define wgui_softkey_set_filler_disabled(_arg) 

/* For Draw Manager  */

/*****************************************************************************
 * <group dom_softkey_wgui_layer_basic>
 * FUNCTION
 *  move_softkey
 * DESCRIPTION
 *  Move the softkey to a new position.
 * PARAMETERS
 *  x        : [IN] Is the new x position of softkey
 *  y        : [IN] Is the new y position of softkey
 *  key      : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void move_softkey(S32 x, S32 y, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_basic>
 * FUNCTION
 *  resize_softkey
 * DESCRIPTION
 *  Resize the softkey to the new dimension.
 * PARAMETERS
 *  width        : [IN] Is the new width of softkey
 *  height       : [IN] Is the new height of softkey
 *  key          : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void resize_softkey(S32 width, S32 height, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_basic>
 * FUNCTION
 *  restore_softkeys
 * DESCRIPTION
 *  set the softkeys to its default position and size.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_softkeys(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  set_softkey_flags_on
 * DESCRIPTION
 *  Set flag to softkey.
 * PARAMETERS
 *  flag         : [IN] Is the flag of softkey
 *  key          : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void set_softkey_flags_on(S32 flag, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  set_softkey_flags_off
 * DESCRIPTION
 *  Reset flag to softkey.
 * PARAMETERS
 *  flag         : [IN] Is the flag of softkey
 *  key          : [IN] Is the softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
void set_softkey_flags_off(S32 flag, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_get_offset
 * DESCRIPTION
 *  Get string's display position of softkey.
 * PARAMETERS
 *  sk_str_p         : [IN] Is the string to be displayed
 *  offset_x         : [IN/OUT] Is the pointer of parameter to get string's x position
 *  offset_y         : [IN/OUT] Is the pointer of parameter to get string's y position
 *  truncated_width  : [IN/OUT] Is the text width that should be truncated
 *  key              : [IN] Is the softkey
 *  rotate_degree    : [IN] Is the rotate degree of screen
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM as well.
 *****************************************************************************/
MMI_BOOL wgui_softkey_get_offset(
          UI_string_type sk_str_p,
          S32 *offset_x,
          S32 *offset_y,
          S32 *truncated_width,
          WGUI_SOFTKEY_ENUM key,
          mmi_frm_screen_rotate_enum rotate_degree);


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * <group dom_softkey_wgui_layer_touch>
 * FUNCTION
 *  translate_softkey_pen_event
 * DESCRIPTION
 *  Translate pen event of a softkey and display the corresponding effect.
 * PARAMETERS
 *  key                  : [IN] Is the softkey
 *  pen_event            : [IN] Is the pen event
 *  x                    : [IN] Is the x position of pen
 *  y                    : [IN] Is the y position of pen
 *  button_event         : [IN/OUT] Is the pointer of parameter to get softkey's pen event
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM & gui_button_pen_enum as well.
 *****************************************************************************/
BOOL translate_softkey_pen_event(
                    WGUI_SOFTKEY_ENUM key,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);

#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_get_dimension
 * DESCRIPTION
 *  Get the dimenstion of softkey.
 * PARAMETERS
 *  key          : [IN]  Is the softkey
 *  width        : [IN/OUT] Is the pointer of parameter to get softkey's width
 *  height       : [IN/OUT] Is the pointer of parameter to get softkey's height
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know WGUI_SOFTKEY_ENUM and gui_button_pen_enum as well.
 *****************************************************************************/
void wgui_softkey_get_dimension(
             WGUI_SOFTKEY_ENUM key,
             S32 *width,
             S32 *height);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_get_position
 * DESCRIPTION
 *  Get the position of softkey.
 * PARAMETERS
 *  key          : [IN] Is the softkey
 *  x            : [IN/OUT] Is the pointer of parameter to get the x position of softkey
 *  y            : [IN/OUT] Is the pointer of parameter to get the y position of softkey
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also need to know WGUI_SOFTKEY_ENUM as well
 *****************************************************************************/
void wgui_softkey_get_position(WGUI_SOFTKEY_ENUM key, S32 *x, S32 *y);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_basic>
 * FUNCTION
 *  show_softkey_background
 * DESCRIPTION
 *  Draw softkey's background.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_softkey_background(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  register_default_hide_softkeys
 * DESCRIPTION
 *  Register the default hide callback function to softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_default_hide_softkeys(void);

/* DOM-NOT_FOR_SDK-BEGIN */

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
void SetLeftSoftkeyAlwaysKeyUpByPen(void);

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
void SetRightSoftkeyAlwaysKeyUpByPen(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_softkey_wgui_layer_theme>
 * FUNCTION
 *  wgui_softkey_reset_theme
 * DESCRIPTION
 *  Reset softkey's theme to default theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_reset_theme(WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_theme>
 * FUNCTION
 *  wgui_softkey_set_theme
 * DESCRIPTION
 *  Set the given theme to softkey.
 * PARAMETERS
 *  key                  : [IN] Is the softkey
 *  up_filler            : [IN] Is the softkey's background filler in its key up state
 *  down_filler          : [IN] Is the softkey's background filler in its key down state
 *  up_text_color        : [IN] Is the softkey's text color in its key up state
 *  down_text_color      : [IN] Is the softkey's text color in its key down state
 *  text_border_color    : [IN] Is the text border color of softkey
 *  text_font            : [IN] Is the text font size of softkey
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_theme(
             WGUI_SOFTKEY_ENUM key,
             UI_filled_area *up_filler,
             UI_filled_area *down_filler,
             color up_text_color,
             color down_text_color,
             color text_border_color,
             UI_font_type text_font);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_set_in_popup
 * DESCRIPTION
 *  Set the flag of softkey is in popup screen or not.
 * PARAMETERS
 *  MMI_BOOL        : [IN] Is the flag of softkey is in popup screen or not.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_is_in_popup(MMI_BOOL is_in_popup);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_set_double_buffer_enable
 * DESCRIPTION
 *  Set the flag of softkey enable double buffer or not.
 * PARAMETERS
 *  MMI_BOOL        : [IN] Is the flag of softkey enable double buffer or not.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_double_buffer_enable(MMI_BOOL enable_double_buffer);


/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  ChangeLeftSoftkeyByString
 * DESCRIPTION
 *  Changes the left softkey label using a dynamic string
 * PARAMETERS
 *  s        : [IN] is the string to be displayed in left softkey
 *  i        : [IN] is the icon to be displayed in left softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeLeftSoftkeyByString(UI_string_type s, PU8 i);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  ChangeRightSoftkeyByString
 * DESCRIPTION
 *  Changes the right softkey label using a dynamic string
 * PARAMETERS
 *  s        : [IN] is the string to be displayed in right softkey
 *  i        : [IN] is the icon to be displayed in right softkey
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRightSoftkeyByString(UI_string_type s, PU8 i);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_set_target_layer
 * DESCRIPTION
 *  Set the target layer to softkey.
 * PARAMETERS
 *  target_layer         : [IN] Is the handle of target layer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_target_layer(GDI_HANDLE target_layer);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_get_target_layer
 * DESCRIPTION
 *  Get the target layer of softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 * RETURN VALUES
 *  GDI_HANDLE : Is the target layer of softkey.
 *****************************************************************************/
GDI_HANDLE wgui_softkey_get_target_layer(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_set_abm_layer
 * DESCRIPTION
 *  Set the alpha blending (abm) layer to softkey.
 * PARAMETERS
 *  abm_layer         : [IN] Is the handle of alpha blending layer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_set_abm_layer(GDI_HANDLE abm_layer);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_get_abm_layer
 * DESCRIPTION
 *  Get the alpha blending (abm) layer of softkey.
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 * RETURN VALUES
 *  GDI_HANDLE : Is the alpha blending layer of softkey.
 *****************************************************************************/
GDI_HANDLE wgui_softkey_get_abm_layer(void);

/*****************************************************************************
 * <group dom_softkey_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_softkey_disable_text_translucence
 * DESCRIPTION
 *  Disable text's translucence effect of softkey.
 * REMARKS
 *  This API is only provided for video's play screen to disable vector font's translucence effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_softkey_disable_text_translucence(void);

extern MMI_BOOL wgui_softkey_is_in_popup(void);
extern MMI_BOOL wgui_softkey_get_double_buffer_enable(void);
extern WGUISoftkeyHideFuncPtr wgui_softkey_get_hide_func_ptr(void);
extern void wgui_softkey_set_hide_func_ptr(WGUISoftkeyHideFuncPtr f);
#ifdef __cplusplus
}
#endif 

#endif /* __WGUI_SOFTKEYS_H__ */ 


