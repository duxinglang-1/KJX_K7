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
 * mmi_frm_input_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI input event handle
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_FRM_INPUT_GPROT_H
#define MMI_FRM_INPUT_GPROT_H

/*----------------------------------------------------------------*
  General input
 *----------------------------------------------------------------*/

//RHR Add    
#include "kal_release.h"
#include "app_ltlcom.h"    
#include "MMIDataType.h"
#include "mmi_features.h"
#include "dcl.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/* perferred input device enum */
typedef enum
{
    /* prefered device is keypad */
    MMI_UE_STYLE_PREFER_KEYPAD,
    /* prefered device is touch panel */
    MMI_UE_STYLE_PREFER_TOUCH,
    /* no use enum */
    MMI_UE_STYLE_MAX
} mmi_ue_style_enum;

/* input type of the project */
typedef enum
{
    /* input style is qwerty keypad with no touch */ 
    KEYPAD_QWERTY_NON_TOUCH,
    /* input style is qwerty keypad with single touch panel and you need to use pen to touch the screen */
    KEYPAD_QWERTY_SINGLE_TOUCH_PEN,
    /* input style is qwerty keypad with single touch panel and you could use finger to touch the screen */
    KEYPAD_QWERTY_SINGLE_TOUCH_FINGER,
    /* input style is qwerty keypad with multi-touch panel(capacity) and you must use finger to touch the screen */
    KEYPAD_QWERTY_MULTI_TOUCH_FINGER,
    /* input style is normal keypad with no touch supported */
    KEYPAD_NUMERICAL_NON_TOUCH,
    /* input style is normal keypad with single touch panel and you need to use pen to touch the screen */
    KEYPAD_NUMERICAL_SINGLE_TOUCH_PEN,
    /* input style is normal keypad with single touch panel and you could use finger to touch the screen */
    KEYPAD_NUMERICAL_SINGLE_TOUCH_FINGER,
    /* input style is normal keypad with multi-touch panel(capacity) and you must use finger to touch the screen */
    KEYPAD_NUMEIRCAL_MULTI_TOUCH_FINGER,
    /* input style is reduced keypad with single touch panel and you need to use pen to touch the screen */
    KEYPAD_NAVIGATION_SINGLE_TOUCH_PEN,
    /* input style is reduced keypad with single touch panel and you could use finger to touch the screen */
    KEYPAD_NAVIGATION_SINGLE_TOUCH_FINGER,
    /* input style is reduced keypad with multi-touch panel(capacity) and you must use finger to touch the screen */
    KEYPAD_NAVIGATION_MULTI_TOUCH_FINGER,
    /* no use */ 
    INPUT_TYPE_MAX           
} mmi_input_type_enum;


/*****************************************************************************
 * FUNCTION
 *  mmi_query_input_style
 * DESCRIPTION
 *  This API is used to query the preferred input style and the input type
 *  of the project.
 * PARAMETERS
 *  void
 * RETURNS
 *  16H - the prefered device please refer mmi_ue_style_enum, 16L - input type,
 *  please refer mmi_input_type_enum.
 *****************************************************************************/
extern U32 mmi_query_input_style(void);

#ifndef _KEYBRD_INT_H_
#define _KEYBRD_INT_H_
/*----------------------------------------------------------------*
  Key
 *----------------------------------------------------------------*/
/***************************************************************************** 
* Define
*****************************************************************************/

/* 
 * Return value of the key proc who wants to stop the key event routing
 * If it doesn't want to stop the key event routing, please return MMI_RET_OK 
 */
#define MMI_RET_KEY_HANDLED   (1)

/*
 * the proc who receiving EVT_ID_PRE_KEY_EVT_ROUTING event can return this value
 * to stop the key events rouing
 */
#define MMI_RET_STOP_KEY_HANDLE  (2)
 
/* If applications want to full control END VOL_UP VOL_DOWN in call
 * Please use mmi_frm_set_key_handler_ex(SetKeyHandlerEx) with this macro
 *
 * Example: mmi_frm_set_key_handler_ex(XXX_HDLR, XXX_CODE, XXX_TYPE, MMI_FRM_APP_FULL_CONTROL);
 */
#define MMI_FRM_APP_FULL_CONTROL    (0x0001)

/* 
 * The element number of PresentAllKeys
 * This macro is used when applications use  mmi_frm_set_group_key_handler(SetGroupKeyHandler)
 * to Set All key handler as the same one.
 * 
 * Example: mmi_frm_set_group_key_handler(XXX_HDLR, PresentAllKeys, TOTAL_KEYS, XXX_TYPE);
 *
 */ 
#define TOTAL_KEYS                  mmi_frm_get_present_all_key_num()

/* 
 * The element number of PresentAllDialerKeys 
 * This macro is mainly used by UCM which uses mmi_frm_set_group_key_handler(SetGroupKeyHandler)
 * to set all dialer keys as the same key handler
 *
 * Example: mmi_frm_set_group_key_handler(XXX_HDLR, PresentAllDialerKeys, TOTAL_DIALER_KEYS, XXX_TYPE);
 */
#define TOTAL_DIALER_KEYS           mmi_frm_get_all_dial_key_num()

/* 
 * Special key means, the keys which can be used together with
 * other keys, such Ctrl + C, Alt + Enter.
 * In QWERTY project, the translate key handler will get the special key flag,
 * the flag indicate the special key is down or not at that time.
 * The following macro is the position of the specific special key in the special key flag
 * of the translate key handler.
 * If the applications want to know the special key is down or not in translate key hander,
 * he may use the following code:
 *  MMI_BOOL shift_down = 
 *            (special_key_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT == MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
 *  Notes: The special key flag has special meanings for Input Method Module.
 */
#define MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT     (0x00000001)
/* Discription SEE ALSO MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT */
#define MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_ALT       (0x00000002)
/* Discription SEE ALSO MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT */
#define MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_CAPSLOCK  (0x00000004)
/* Discription SEE ALSO MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT */
#define MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_CTRL      (0x00000008)
/* Discription SEE ALSO MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT */
#define MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN        (0x00000010)
/* Discription SEE ALSO MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT */
#define MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK   (0x00000020)

#define MMI_FRM_QWERTY_OUT_PUT_KEY_FLAG           (0x00000040)

/*
 * translate key code: 32 bit unsigned integer
 * higher 16 bit is reserved now. (It is design to store key code, but now it is not used)
 * lower  16 bit is ucs2 value:
 */
#define MMI_FRM_QWERTY_INVALID_TRANSLATED_CODE       (0x00FE0000)

/* Get UCS2 code */
#define MMI_QWERTY_GET_UCS2_CODE(translated_code)    ((UI_character_type)(translated_code & 0xFFFF))
/* Get MMI key code */
#define MMI_QWERTY_GET_MMI_KEY_CODE(translated_code) ((U16)(((translated_code) >> 16)) & 0xFFFF)

/* The maximun number of WGUI key event routing layer */
#define MMI_FRM_WGUI_ROUTING_LAYER_NUM    (4)

/* DOM-NOT_FOR_SDK-BEGIN */
/* Deprecated API and type: Please use the new API and new type */
#define mmi_kbd_set_concurrent_mode        mmi_frm_set_keypad_mode
#define SetkeyInfo                         mmi_frm_set_key_info
#define SetKeyHandlerEx                    mmi_frm_set_key_handler_ex
#define ClearAllKeyHandler                 mmi_frm_clear_all_key_handler
#define StopCurrentKeyPadTone              mmi_frm_stop_curr_key_tone
#define GetCurKeypadTone                   mmi_frm_get_curr_key_tone
#define SetCurKeypadTone                   mmi_frm_set_curr_key_tone
#define mmi_kbn_key_tone_hdlr              mmi_frm_key_tone_hdlr
#define mmi_kbd_reverse_code               mmi_frm_get_dev_key_code
#define mmi_suspend_handle_key_process     mmi_frm_suspend_handle_key_process
#define CONCURRENT_KEY_MODE_1_KEY          KEYPAD_1KEY_NUMBER
#define CONCURRENT_KEY_MODE_2_KEYS         KEYPAD_2KEY_NUMBER
#define CONCURRENT_KEY_MODE_3_KEYS         KEYPAD_3KEY_NUMBER
#define ProcessKeyEvent(a, b)
#define mmi_frm_set_key_handle_in_high_frequency(a)

/* Deprecated API, please use the new old, we keep it for vendor compatible */
extern void ExecuteCurrKeyHandler(S16 keyCode, S16 keyType);                         /* mmi_frm_exec_key_handler */
extern void GetkeyInfo(U16 *keyCode, U16 *keyType);                                  /* mmi_frm_get_key_info */  
extern FuncPtr GetKeyHandler(U16 keyCode, U16 keyType);                              /* mmi_frm_get_key_handler */
extern void SetKeyHandler(FuncPtr funcPtr, U16 keyCode, U16 keyType);                /* mmi_frm_set_key_handler */
extern void SetGroupKeyHandler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType); /* mmi_frm_set_group_key_handler */  
extern void ClearKeyHandler(U16 keyCode, U16 keyType);                               /* mmi_frm_clear_key_handler */
extern void PowerAndEndKeyHandler(void);                                             /* mmi_frm_set_power_end_key_handler */
extern void ClearKeyEvents(void);                                                    /* mmi_frm_clear_key_events */
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* 
 * key tone state
 * If an application wants to disable some key's key tone in some scenario,
 * we can add a enum here and modify the API mmi_frm_kbd_is_tone_enabled
 * For example, Diable LSK's key tone
 * Add MMI_KEY_LSK_TONE_DISABLE
 * application use the API mmi_frm_kbd_set_tone_state(MMI_KEY_LSK_TONE_DISABLE)
 */
typedef enum
{
    MMI_KEY_TONE_ENABLED                    , /* Not Disable all key tone */
    MMI_KEY_VOL_TONE_DISABLED               , /* Disable VOL_UP VOL_DOWN key tone */
    MMI_KEY_VOL_UP_DOWN_TONE_DISABLED       , /* Disable VOL_UP, VOL_DOWN, UP_ARROW, DOWN_ARROW key tone */
    MMI_KEY_VOL_UP_DOWN_RIGHT_LEFT_ARROW_DISABLE, /* Disable VOL_UP, VOLE_DOWN, LEFT_ARROW, RIGHT_ARROW */
    MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED  , /* Disable LEFT ARROW, RIGHT ARROW */
    MMI_KEY_LSK_TONE_DISABLE, /* Disable LSK KEY TONE */
    MMI_KEY_RSK_TONE_DISABLE, /* Disable RSK KEY TONE */
    MMI_KEY_LSK_RSK_TONE_DISABLE, /* Disable LSK, RSK KEY TONE */
    MMI_KEY_TONE_DISABLED                   , /* Disable all key tone */
    MMI_KEY_TONE_INVALID
} mmi_frm_kbd_tone_state_enum;


typedef enum
{
    MMI_DIALER_KEY_TONE_DTMF,
    MMI_DIALER_KEY_TONE_NORMAL,
    MMI_DIALER_KEY_TONE_MAX
} mmi_frm_dial_key_tone_type_enum;

/* 
 * Input event device
 * one bit indicates one device.
 * If we add a new input device such as jog ball
 * we could add MMI_DEVICE_JOG_BALL = 0x0004;
 * and Modify MMI_DEVICE_ALL = (MMI_DEVICE_KEY | MMI_DEVICE_PEN | MMI_DEVICE_JOG_BALL)
 */
typedef enum
{
    /* No device */
    MMI_DEVICE_NONE = 0x0000,
    /* device is key */
    MMI_DEVICE_KEY  = 0x0001,
    /* device is pen */
    MMI_DEVICE_PEN  = 0x0002,
    /* All types of device */
    MMI_DEVICE_ALL  = (MMI_DEVICE_KEY | MMI_DEVICE_PEN),
    /* Max device type */
    MMI_DEVICE_MAX
} mmi_frm_input_device_type_emun;

/* 
 * traditional key messsage structure used by pre and post key handler
 * and key tone handler, the whole member is 
 typedef struct KEYBRD_MESSAGE
{
    //Local parameter header 
    LOCAL_PARA_HDR
    // Message type
    S16 nMsgType;
    //Key code 
    S16 nKeyCode;
} KEYBRD_MESSAGE;
 */
typedef struct KEYBRD_MESSAGE
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* Local parameter header */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    /* Message type */
    S16 nMsgType;
    /* Key code */
    S16 nKeyCode;
} KEYBRD_MESSAGE;
 
/* 
 * layer of translate key handler
 * SYS: this layer is used to handle END, VOL_DOWN, VOL_UP key in call
 * APP: used for application, JAVA only now.
 * EDITOR: used for IME
 */
typedef enum
{
    /* SYS: this layer is used to handle END, VOL_DOWN, VOL_UP key in call */
    MMI_FRM_TRANS_KEY_SYS = 0,
    MMI_FRM_TRANS_KEY_VENUS,
    /* APP: used for application, JAVA only now. */
    MMI_FRM_TRANS_KEY_APP,
    /* EDITOR: used for IME */
    MMI_FRM_TRANS_KEY_EDITOR,
    /* Translate Key handler end */
    MMI_FRM_TRANS_KEY_HANDLE_END
} mmi_frm_trans_key_handle_enum;

/* 
 * key event routing layer
 * SYS   1
 * SCR   1
 * CAT   1
 * WGUI  (MMI_FRM_WGUI_ROUTING_LAYER_NUM)
 */
typedef enum
{
    MMI_KEY_ROUTING_SYS,
    MMI_KEY_ROUTING_SCR,
    MMI_KEY_ROUTING_CAT,
    MMI_KEY_ROUTING_WGUI,
    MMI_KEY_ROUTING_KEY_HDLR = MMI_KEY_ROUTING_WGUI + MMI_FRM_WGUI_ROUTING_LAYER_NUM,
    MMI_KEY_ROUTING_TOTAL
} mmi_key_routing_layer_enum;


/* 
 * keypad mode
 * This enum is named by KEYPAD_xKEY_YYY
 * x means the key event flow:
 *   1. one key concurrent
 *      eg. KEY1 DOWN, KEY1 UP, KEY2 DOWN, KEY2 UP, KEY3 DOWN, KEY3 UP
 *   2. tow keys concurrent
 *      eg. KEY1 DOWN, KEY2 DOWN, KEY1 UP, KEY3 DOWN, KEY3 UP, KEY2 UP
 *   3. three keys concurrent
 *      eg. KEY1 DOWN, KEY2 DOWN, KEY3 DOWN, KEY1 UP, KEY2 UP, KEY3 UP
 * The driver's limitation of three key concurrent.
 *   Please see the following hardware layout (KEY1, KEY4) (KEY2 KEY3) is in diagonal
 *   Key1 Key2
 *   Key3 Key4
 *   If Key2, Key3 are pressed, the user press Key1, the driver cannot get the right key code of Key1, it may
 *   get the key code of Key4.
 * 
 * YYY means the key code will be got by application in the following case.
 *     1/E is in the same hard key in the qwerty project, which key code will be got by application KEY_E or KEY_1?
 *     if YYY == NUMBER, KEY_1 will be got
 *     if YYY == QWERTY, KEY_E will be got
 * why don't we use the ucs2 value instead of using 2 MMI key code?
 *     The reason is that we design this to backward compitable the old code in PLUTOMMI because app may not modify
 *     their code according to our design. As a result, we must make old code can work in QWERTY project if application
 *     do not change their code any more.
 *   
 */
typedef enum
{
    /* KEY1 Number */
    KEYPAD_1KEY_NUMBER,
    /* KEY2 Number */
    KEYPAD_2KEY_NUMBER,
    /* KEY3 Number */
    KEYPAD_3KEY_NUMBER,
    /* KEY1 Qwerty */
    KEYPAD_1KEY_QWERTY,
    /* KEY2 Qwerty */
    KEYPAD_2KEY_QWERTY,
    /* KEY3 Qwerty */
    KEYPAD_3KEY_QWERTY,
    /* Keypad mode end */
    KEYPAD_MODE_END
} mmi_frm_keypad_mode_enum;

/*
 *  Key event structure
 *  Framework key module will provide 5 events
 *      EVT_ID_PRE_ROUTING    : send before key event routing is started
 *      EVT_ID_POST_ROUTING   : send after key event routing is finished
 *      EVT_ID_ON_KEY         : send during the key event routing
 *      EVT_ID_PRE_KEY        : send during the key event routing
 *      EVT_ID_POST_KEY       : send during the key event routing
 *  For most applications will interest EVT_ID_ON_KEY
 *  
 *  This event provide 4 parameters
 *
 *  For NON-QWERTY project, key_code & key type is valid
 *  ucs2_value & special_key_flag will always 0. Please ignore these
 *  2 parameters in NON-QWERTY project
 *
 *  For QWERTY project, the four parameter all have meaning.
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER    /* base event member */
    U8  key_code;           /* mmi key code */
    U8  key_type;           /* mmi key type */
    U16 ucs2_value;         /* ucs2 value of the key represented (valid in QWERTY project) */ 
    U32 special_key_flag;   /* special key flag(like SHIFT, FN) (valid in QWERTY project) */
	mmi_ret result;         /* if the key is handled before the event is received */
} mmi_frm_key_evt_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
/*
 * All mmi keys except KEY_CSK & QWERTY keys like KEY_A...
 * are listed in this table. However, in QWERTY project,
 * the array has special meanings when use it at mmi_frm_set_group_key_handler(SetGroupKeyHandler): 
 * even though it does not contain qwerty keys, but it means all keys in the keypad.
 * So any key handler is implemented for this. Please see mmi_frm_set_group_key_handler(SetGroupKeyHandler) for
 * details.
 * This array is mainly used for mmi_frm_set_group_key_handler(SetGroupKeyhandler)
 */
extern const U16 PresentAllKeys[];

/*
 *  We add this array for UCM and video call
 *  They will handle key 0~9 *#  in number key pad
 *  handle 0~9 *# PW+ in QWERTY project
 *  They using mmi_frm_set_group_key_handler(XXX, PresentAllDialerKeys, TOTAL_DIALER_KEYS, XXX)
 *  in qwert project, we will record P and W' handler in any key handler
 *  The application should skip other keys.
 *  Please see mmi_frm_set_group_key_handler(SetGroupKeyHandler) for detail
 *
 */
extern const U16 PresentAllDialerKeys[];



/***************************************************************************** 
* Call back
*****************************************************************************/

/*****************************************************************************
 * CALLBACK
 *  pre key handler and post key  handler
 * DESCRIPTION
 *  The pre key handler is invoked before key handler, the application can set 
 *  the pre key handler's return value as MMI_FALSE to disable the key handler's execution.
 *  The relateship of pre key handler , key handler and the post key handler is
 *      if(pre_key_hdlr() == MMI_TRUE)
 *      {
 *          key_hdlr();
 *      }
 *      post_key_hdlr();
 * PARAMETERS
 *  msg       : [IN] key msg see struct KEYBRD_MESSAGE
 * RETURNS
 *  to return MMI_TRUE for pre key handler if he want to disable key handler
 *****************************************************************************/
typedef U8 (*PsKeyProcessCBPtr)(KEYBRD_MESSAGE *msg);

/*****************************************************************************
 * CALLBACK
 *  translate key handler
 * DESCRIPTION
 *  The translate key handler is mainly implemented for QWERTY project. But in Non qwerty project, it can also be
 *  used, but it's ucs2_value and special_key_flag is 0.
 *  The mainly function of the translate key handler is application can get ucs2value from this handler.
 *  Moreover, application can handle concurrent key in this translate key handler by using set the proper key pad 
 *  mode.
 *  For which key code will be got and the special flag's meaning, please refer the enum mmi_frm_keypad_mode_enum
 *  and the Macro MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_XXX
 *  
 *  There is 2 level of translate key handler now SYS and APP(EDITOR), the invoke seuency is
 *      if (sys_translate_key_handler() == MMI_FALSE)
 *      {
 *          app_translate_key_handler();
 *      }
 *  
 *  The relateship of pre key handler , translate handler, traditional key handler and the post key handler is
 *      if(pre_key_hdlr() == MMI_TRUE)
 *      {
 *          if (translate_key_hdlr() == MMI_FALSE)
 *          {
 *              traditional_key_hdlr();
 *          }
 *      }
 *      post_key_hdlr();
 *   Note: 
 *       1. If you want to handle LSK/RSK/CSK in translate key handler, please pay attention that the confliction
 *       of the WGUI softkey.
 *       2. Please pay attention the confliction with the traditional key handler, if you don't return MMI_TRUE
 *       3. return MMI_FALSE, to don't care about some keys.
 * PARAMETERS
 *  mmi_key_code       : [IN] mmi key code
 *  mmi_key_type       : [IN] mmi key type
 *  ucs2_value         : [IN] ucs2 value
 *  special_key_flag   : [IN] down or up state of the special key
 * RETURNS
 *  TO return MMI_TRUE to stop the key dispatch to next level
 * EXAMPLE
 *  <code>
 *  MMI_BOOL my_translate_key_hdlr(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
 *  {
 *      //handle key code, key type, all key code can be got include special key code such as KEY_SHIFT
 *      if (mmi_key_code == KEY_1 && mmi_key_type == KEY_EVENT_DOWN)
 *      {
 *          do_some_thing_1();
 *          return MMI_TRUE; // to stop key routing
 *      }
 *      
 *      //handle another key code, but don't stop key routing
 *      if (mmi_key_code == KEY_END && mmi_key_type == KEY_EVENT_DOWN)
 *      {
 *          do_something_2(); 
 *          return MMI_FALSE;// don't stop key routing
 *      }
 *      //handle special key flag, shift + T
 *      if (mmi_key_code == KEY_T && mmi_key_type == KEY_EVENT_DOWN)
 *      {
 *          if (special_key_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT == MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
 *          {
 *               do_some_thing_2();
 *               return MMI_TRUE;
 *          }
 *      }
 *      //handle ucs2 value
 *      if (ucs2_value == 0x0040)
 *      {
 *           do_some_thing_3();
 *           return MMI_TRUE;
 *      }
 *      return MMI_FALSE; // for other case continue key routing      
 *  }
 *  </code>
 *****************************************************************************/
typedef MMI_BOOL ( *mmi_frm_translate_keyhandler_func_ptr)(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
 * CALLBACK
 *  customized special key flag change call back
 * DESCRIPTION
 *  This call back is registered by IME module to handle special key flag change for his own.
 *  The special key's flag is on or off determined by IME himself.
 *  Example, press shift ON, press A, after A UP, OFF
 *           press shift ON, press shift LOCK(it means always ON if press other key), press shift OFF
 * 
 * PARAMETERS
 *  special_key_flag       : [IN] specific meaning of special key on/off
 *  special_key_lock_flag  : [IN] lock the special key state change
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mmi_frm_qwerty_customized_special_key_flag_change_callback_funcptr)(U32 special_key_flag, U32 special_key_lock_flag);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_send_incomplete_key_event_to_new_screen
 * DESCRIPTION
 *  This function is used to enable the ability to receiving incomplete key event
 *  in the new screen.
 *  For example, key down to enter new screen, if the new screen want to action
 *  the following key event like long press, repeat, up, the user should enable
 *  this feature. The user needn't to reset this ability to false, framework will
 *  help to disable this ability when key up.
 *
 * PARAMETERS
 *  enable       : [IN]  enable this ability or not
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_send_incomplete_key_event_to_new_screen(MMI_BOOL enable);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_all_key_hdlr_null
 * DESCRIPTION
 *  This function is used to set all key handlers as NULL
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_all_key_hdlr_null(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_all_slave_master_key_hdlr_null
 * DESCRIPTION
 *  This function is used to set all sub-lcd slave and master mode key handlers as NULL
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD_MASTER_MODE__ 
extern void mmi_frm_set_all_slave_master_key_hdlr_null(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_proc
 * DESCRIPTION
 *  This function is used to set key proc function for all key event routing layer.
 *
 * PARAMETERS
 *  layer      : [IN]   key event routing layer, see mmi_key_routing_layer_enum
 *  key_proc   : [IN]   proc function that will process key event
 *  user_data  : [IN]   user data that the user will use
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_key_proc(mmi_key_routing_layer_enum layer, mmi_proc_func key_proc, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  MMI_CAT_SET_KEY_PROC
 * DESCRIPTION
 *  This function is used to set key proc function for framework
 *
 * PARAMETERS
 *  key_proc   : [IN]   proc function that will process key event
 *  user_data  : [IN]   user data that the user will use
 *
 * RETURNS
 *  void
 *****************************************************************************/
#define MMI_SYS_SET_KEY_PROC(key_proc, user_data)  mmi_frm_set_key_proc(MMI_KEY_ROUTING_SYS,  (mmi_proc_func)key_proc, (void *)user_data)

/*****************************************************************************
 * FUNCTION
 *  MMI_CAT_SET_KEY_PROC
 * DESCRIPTION
 *  This function is used to set key proc function for screen
 *
 * PARAMETERS
 *  key_proc   : [IN]   proc function that will process key event
 *  user_data  : [IN]   user data that the user will use
 *
 * RETURNS
 *  void
 *****************************************************************************/
#define MMI_SCR_SET_KEY_PROC(key_proc, user_data)  mmi_frm_set_key_proc(MMI_KEY_ROUTING_SCR,  (mmi_proc_func)key_proc, (void *)user_data)

/*****************************************************************************
 * FUNCTION
 *  MMI_CAT_SET_KEY_PROC
 * DESCRIPTION
 *  This function is used to set key proc function for categories
 *
 * PARAMETERS
 *  key_proc   : [IN]   proc function that will process key event
 *  user_data  : [IN]   user data that the user will use
 *
 * RETURNS
 *  void
 *****************************************************************************/
#define MMI_CAT_SET_KEY_PROC(key_proc, user_data)  mmi_frm_set_key_proc(MMI_KEY_ROUTING_CAT,  (mmi_proc_func)key_proc, (void *)user_data)

/*****************************************************************************
 * FUNCTION
 *  MMI_WGUI_SET_KEY_PROC
 * DESCRIPTION
 *  This function is used to set key proc function for WGUI components
 *
 * PARAMETERS
 *  key_proc   : [IN]   proc function that will process key event
 *  user_data  : [IN]   user data that the user will use
 *
 * RETURNS
 *  void
 *****************************************************************************/
#define MMI_WGUI_SET_KEY_PROC(key_proc, user_data) mmi_frm_set_key_proc(MMI_KEY_ROUTING_WGUI, (mmi_proc_func)key_proc, (void *)user_data)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_exec_key_handler
 * DESCRIPTION
 *  Because of history reason, applications may call this function directly to
 *  invoke current key handler.
 *  There are mainly 2 kinds of using cases.
 *    1. Call this function in Pen down and pen up handler
 *    2. press key, then in key handler entry new screen, show category and record the key code
 *       then use this key code to call this function.
 * 
 *  If you use it, pay attention that 
 *      This interface will update key info 
 *      will call translate key handler and key handler
 *  If the translate key handler and key handler are changed by someone else,
 *  applications should cover this case.
 *
 *  This interface will happen to filter some key event, for example
 *  mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_UP);
 *  mmi_frm_exec_key_handler(XXX_CODE, KEY_REPEAT);
 *  KEY_REPEAT will be filtered. It is for MAUI_01882849
 *
 *  However: mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_DOWN);
 *           mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_DOWN);
 *           The second down should not be filtered for the using case 2 above.
 *
 *   
 *  If we design multiple key handler in the future, this function should be considered
 *  because in one of the multiple key handler, application may call this function,
 *  it will make the code hard to maintain.
 *
 *  It is hard to remove this interface.
 * 
 * PARAMETERS
 *  mmi_key_code    : [IN]  mmi key code such as KEY_0, KEY_1...                             
 *  mmi_key_type    : [IN]  mmi key type such as KEY_EVENT_UP, KEY_EVENT_DOWN... 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_exec_key_handler(S16 keyCode, S16 keyType);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_info
 * DESCRIPTION
 *  This function is used to query key code & key type of last key event.
 *  This function is mainly used with group key handler.
 *  Because the application cannot get the key code and key type in his group
 *  key handler, so it needs this interface to get the key code and key type.
 *  
 *  Typically,
 *    mmi_frm_set_group_key_handler(xxx_hdr, xxx_array, xxx_num, xxx_type);
 *    in xxx_hdlr
 *    void xxx_hdlr()
 *    {
 *        mmi_frm_get_key_info(&key_code, &key_type);
 *        switch(key_code)
 *        {
 *           case KEY_0:
 *               // do the thing you want
 *               break;
 *               ...
 *        }
 *    }
 *  Notes: 
 *      1. The key info updates before invoke translate key handler and key handler.
 *      2. It's safe to use it in translate key handler and key handler
 *      3. Don't use this in pre and post key handler.
 *      4. Don't use this in some timer's callback
 *      5. It's safe to use it in translate key handler and key handler.
 *      6. Don't this API to judge if the key handle is finished or no key is pressed.
 *      
 * PARAMETERS
 *  mmi_key_code     : [OUT]  The pointer to the Key Code.
 *  mmi_key_type     : [OUT]  The pointer to the Key type.       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_get_key_info(U16 *mmi_key_code, U16 *mmi_key_type);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_info
 * DESCRIPTION
 *  This function is used to set the key info.
 *  some applications may simulate the key process but don't use mmi_frm_exec_key_handler
 *  he may use the following case:
 *   FuncPtr key_handler = mmi_frm_get_key_handler(KEY_0, KEY_EVENT_DOWN);
 *   mmi_frm_set_key_info(KEY_0, KEY_EVENT_DOWN);
 *   if (key_handler)
 *   {
 *      key_handler();
 *   }
 *   here to set key info because the key_handler may be the group key handler it may use
 *   get key info to get corrent key code. Because it simulates key, framework doesn't know this
 *   it needs the application to set key info by himself.
 *  
 * PARAMETERS
 *  mmi_key_code     : [IN]  Key to which this event is associated         
 *  mmi_key_type     : [IN]  KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key 
 *                           is pressed or released      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_key_info(U16 mmi_key_code, U16 mmi_key_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_handler
 * DESCRIPTION
 *  This function is used for gets the key event handler for key handler table
 *  
 *  Note:
 *    1. App may use this interface to get the key handler and then invoke the key handler
 *    2. App may use this interface to save some key handler and then to restore them
 *    3. App may use this interface to get the key handler to judge something.
 *    4. In QWERTY project, key code >= MAX_KEYES do not have key handler
 *       eg, mmi_frm_get_key_handler(KEY_A, KEY_EVENT_DOWN) will always return NULL
 * PARAMETERS
 *  mmi_key_code     : [IN]  Key to which this event is associated.       
 *  mmi_key_type     : [IN]  What key type is wanted to query.       
 * RETURNS
 *  void
 *****************************************************************************/
extern FuncPtr mmi_frm_get_key_handler(U16 mmi_key_code, U16 mmi_key_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_handler
 * DESCRIPTION
 *  This is used to sets the key event handler that corresponse to one [key_code, key_type].
 *  
 *  Notes:
 *       1. The life cycle of the key handler is within a screen. When screen switch,
 *          END/VOL_UP/VOL_DOWN will be reset to their's default key handler
 *       2. There is only one entry for a [key_code, key_type] pair, overwriten may happen.
 *          
 * PARAMETERS
 *  funcPtr     : [IN] Function to be executed on occurrence of the event.
 *  keyCode     : [IN] Key to which this event is associated.
 *  keyType     : [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key
 *                   is pressed or released
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_key_handler(FuncPtr funcPtr,U16 keyCode,U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_group_key_handler
 * DESCRIPTION
 *  This is used to sets the same key handler for a group of keycodes.
 *  For example
 *      1. U16 keys[4] = {KEY_1, KEY_2, KEY_3, KEY_4};
 *         mmi_frm_set_group_key_handler(xxx_hdlr, keys, 4, KEY_EVENT_DOWN);
 *      2. using PresentAllKeys as the array
 *         If applications needs all keys have the same key handler, he may use
 *         mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllKeys, KEY_EVENT_DOWN);
 *         It is needed to pay attention in QWERTY project, in order to make the 
 *         modification of application as little as possible when implement qwerty key pad
 *         framework cover the case if application wants to handle all keys in one key handler
 *         in qwerty project even though keys like KEY_A has not the key handler in fact.
 *         Application uses this mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllKeys, KEY_EVENT_DOWN);
 *         he will receive KEY_A's down in xxx_hdlr.
 *    
 *      3. using PresentAllDialerKeys as array
 *         This is the special implementation for UCM/video call in QWERTY project.
 *         Because in QWERTY project, there is KEY_W. So the UCM/Video call needs to
 *         handle KEY_W, but the app owner don't want to use translate key handler
 *         So we implement this.
 *         app uses this interface as the following,
 *         mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
 *         In xxx_hdlr, app should filter the key he doesn't interest Because we will give all the keys
 *         that doesn't has key handler.
 *     
 * PARAMETERS
 *  funcPtr         : [IN] Function to be executed on occurrence of the event.
 *  keyCodes        : [IN] Key array to which these events are associated.
 *  len             : [IN] The keyCodes array size.
 *  keyType         : [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key is pressed or released.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_handler
 * DESCRIPTION
 *  This function is used to set the key handler as NULL.
 * PARAMETERS
 *  keyCode     : [IN] Key to which this event is associated.
 *  keyType     : [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, free the event associated
 *                   with press or released state.       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_clear_key_handler(U16 keyCode, U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_key_handler
 * DESCRIPTION
 *  This function is used to clear all the key handlers associated with
 *  current screen.
 *  
 * Note: 1.This API will set END/VOL_UP/VOL_DOWN to their's default key handler
 *       set all other key handler as NULL, clear any key handler and translate key handler.
 *       2.This API is always be invoked when screen switch.
 *       3.This API is different with mmi_frm_clear_key_events. invoke this events can also
 *         be received but do nothing.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_clear_all_key_handler(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_events
 * DESCRIPTION
 *  This function is used to clear Keyboard buffer.
 *   
 *  1. END Key's longpress will not be cleared, we will make sure the handset can be shut down.
 *  2. When mmi_frm_clear_key_events is invoked, all keys are changed to release state in software.
 *     That means
 *         Example, in KEY1 DOWN handler we will drop KEY1's long press repeat untill KEY1' UP.
 *         Even though KEY1's UP is not in the keyboard buffer now. We will drop it when it is received in
 *         future.
 *  3. If application use this interface in KEY down' handler, it will not receive this key's up. 
 *  4. Framework will not invoke this interface when screen switch because the delay action effect of key needed by
 *     BD team.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_clear_key_events(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_power_end_key_handler
 * DESCRIPTION
 *  This function is used for sets defaullt power key & end key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_power_end_key_handler(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_default_power_onoff_key
 * DESCRIPTION
 *  This function is used to set power on/off key to default handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_default_power_onoff_key(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_stop_curr_key_tone
 * DESCRIPTION
 *  This function is used to stop current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_stop_curr_key_tone(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_curr_key_tone
 * DESCRIPTION
 *  This function is used for queries the current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the keypad tone enum. Refer audio_id_enum.
 *****************************************************************************/
extern U16 mmi_frm_get_curr_key_tone(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_curr_key_tone
 * DESCRIPTION
 *  This function is used for sets the current keypad tone.
 * PARAMETERS
 *  KeyTone     : [IN]  the keypad tone enum. Refer audio_id_enum.      
 * RETURNS
 *  Always returns MMI_TURE.  
 *****************************************************************************/
extern U8 mmi_frm_set_curr_key_tone(U16 KeyTone);

/*****************************************************************************
* FUNCTION
*  mmi_frm_key_tone_player
* DESCRIPTION
*  This function is used to play key tone according to the key code and key type
*
*  Behavior
*  case1
*     KEY_1 DOWN - play KEY_1's tone
*     KEY_1 UP   - stop KEY_1's tone
*  case2
*     KEY_1 DOWN - play KEY_1's tone
*     KEY_2 DOWN - stop KEY_1's tone, play KEY_2's tone
*     KEY_1 UP   - do nothing
*     KEY_2 UP   - stop KEY_2's tone
*  case3
*     KEY_1 DOWN - play KEY_1's tone
*     KEY_2 DOWN - stop KEY_1's tone, play KEY_2's tone
*     KEY_2 UP   - stop KEY_2's tone
*     KEY_1 UP   - do nothing
* PARAMETERS
*  key_code   :[IN] mmi key code
*  key_type   :[IN] mmi key type
* RETURNS
*  void
*****************************************************************************/
extern void mmi_frm_key_tone_player(U8 key_code, U8 key_type);

/*****************************************************************************
* FUNCTION
*  mmi_frm_set_dial_key_tone_type
* DESCRIPTION
*  This function is used to set dialer key tone type
*
* PARAMETERS
*  type      : [IN]  see mmi_frm_dial_key_tone_type_enum
* RETURNS
*  void
*****************************************************************************/
extern void mmi_frm_set_dial_key_tone_type(mmi_frm_dial_key_tone_type_enum  type);


/*****************************************************************************
* FUNCTION
*  mmi_frm_get_dial_key_tone_type
* DESCRIPTION
*  This function is used to get dialer key tone type
*
* PARAMETERS
*  void
* RETURNS
*  see mmi_frm_dial_key_tone_type_enum
*****************************************************************************/
extern mmi_frm_dial_key_tone_type_enum mmi_frm_get_dial_key_tone_type(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_suspend_handle_key_process
 * DESCRIPTION
 *  This function is used to suspend key process.
 * PARAMETERS
 *  enable     : [IN] MMI_TRUE enable, MMI_FALSE disable
 *
 * RETURNS
 *  Always return MMI_TRUE now 
 *****************************************************************************/
extern MMI_BOOL mmi_frm_suspend_handle_key_process(MMI_BOOL enable);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_key_supported
 * DESCRIPTION
 *  query if specified mmi key code is supported in the platform
 * PARAMETERS
 *  mmi_key_code    : [IN]    mmi key code (mmi_keypads_enum) to query
 * RETURNS
 *  key is supported or not
 *****************************************************************************/
extern MMI_BOOL mmi_frm_kbd_is_key_supported(S16 key_code);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_dev_key_code
 * DESCRIPTION
 *  This function is used to reversly get the driver key code.
 * PARAMETERS
 *  mmi_key_code        : [IN]        Key code of MMI
 * RETURNS
 *  driver key code
 *****************************************************************************/
extern S16 mmi_frm_get_dev_key_code(S16 mmi_key_code);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_set_tone_state
 * DESCRIPTION
 *  This function is used to change the state of keypad tone.
 *
 * PARAMETERS
 *  state       : [IN]  Keypad tone state that want to be changed      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_get_key_tone_state
 * DESCRIPTION
 *  This function is used to get the state to see if keypad tone is disabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the key pad tone state. Refer mmi_frm_kbd_tone_state_enum.
 *****************************************************************************/
extern mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_get_pre_key_hdlr
 * DESCRIPTION
 *  This function is used for get framework pre-key handler
 *  keypad handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  PsKeyProcessCBPtr
 *****************************************************************************/
extern PsKeyProcessCBPtr mmi_frm_kbd_get_pre_key_hdlr(void);

 /*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_pre_key_hdlr
 * DESCRIPTION
 *  This function is used for regiester function to execute before general 
 *  keypad handler.
 * PARAMETERS
 *  func        : [IN]  Pre-Key handler      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_kbd_reg_pre_key_hdlr(PsKeyProcessCBPtr func);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_post_key_hdlr
 * DESCRIPTION
 *  This function is used for register function to execute after general 
 *  keypad handler.
 * PARAMETERS
 *  func        : [IN]  Post-Key handler     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_kbd_reg_post_key_hdlr(PsKeyProcessCBPtr func);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_register_customized_special_key_flag_change_callback
 * DESCRIPTION
 *  This function is used to register customized special key flag change call back.
 *  This function is used by IME module.
 *  when customized special key flag change, framwork qwerty module will invoke this
 *  call back.
 * PARAMETERS
 *  f         : [IN]  special key changed call back
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_qwerty_register_customized_special_key_flag_change_callback(mmi_frm_qwerty_customized_special_key_flag_change_callback_funcptr f);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_clear_customized_special_key_flag_change_callback
 * DESCRIPTION
 *  This function is used to clear customized special key flag change callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_qwerty_clear_customized_special_key_flag_change_callback(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_reset_key_status
 * DESCRIPTION
 *  reset special key flag and special key lock state. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_qwerty_reset_key_status(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_get_customized_special_key_flag
 * DESCRIPTION
 *  IME module uses this interface to get the special key flag that customized by IME
 * PARAMETERS
 *  void
 * RETURNS
 *  special key flag
 *****************************************************************************/
extern U32  mmi_frm_qwerty_get_customized_special_key_flag(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_set_invalid_customized_special_key
 * DESCRIPTION
 *  If IME want to ignore some special key's change, it may use this interface
 *  to set this information.
 * PARAMETERS
 *  special_key_flag  : [IN] special flag that needs to be ignore.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_qwerty_set_invalid_customized_special_key(U32 special_key_flag);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_app_translate_key_handler
 * DESCRIPTION
 *  This function is used to set translate key handler for applications.
 *  Currently, there are three layers for translate key handler,system layer,
 *  application layer and editor layer. Application layer and editor layer have
 *  the same translate key handler entry. So in fact we have tow level now.  
 *  The invoke sequency is:
 *  If SYS is false
 *   then if APP is false
 *     then traditional keyhandler
 *  or 
 *  If SYS is false
 *  then 
 *      If EDITOR is false
 *      then traditional keyhandler 
 *
 * PARAMETERS
 *  func_ptr      : [IN]   translate key handler that will be set
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void my_entry_function()
 * {
 *     EntryNewScreen(...);
 *     mmi_frm_set_app_translate_key_handler(my_translate_key_handler);  
 * }
 * </code>
 *****************************************************************************/
extern void mmi_frm_set_app_translate_key_handler(mmi_frm_translate_keyhandler_func_ptr func_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_app_translate_key_handler
 * DESCRIPTION
 *  Clear translate key handler for application layer.
 *  All translate key handler will be cleared when screen switch, so if application
 *  don't have special usage. It is not necessary to invoke this interface.
 *  we use func_ptr which application used when call mmi_frm_set_app_translate_key_handler
 *  as the parameters for futher extension.
 *  For example, we may support multi-translate key handler in the same layer
 *      mmi_frm_set_app_translate_key_handler(my_translate_key_handler1);
 *      mmi_frm_set_app_translate_key_handler(my_translate_key_handler2);
 *      we will has two translater key handler in application layer.
 *      when clear, we use the translate key handler to distinguish 
 *      which key handler should be cleared.
 *
 * PARAMETERS     
 *  func_ptr      : [IN] translate key handler application use it in mmi_frm_set_app_translate_key_handler
 * RETURNS
 *  MMI_TRUE, cleared successfully, MMI_FALSE, already changed by another one
 * EXAMPLE
 * <code>
 *
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void my_entry_function()
 * {
 *     EntryNewScreen(...);
 *     mmi_frm_set_app_translate_key_handler(my_translate_key_handler);  
 * }
 *  
 * void some_function()
 * {
 *     mmi_frm_clear_app_translate_key_handler(my_translate_key_handler); 
 * }
 * </code>
 *****************************************************************************/
extern MMI_BOOL mmi_frm_clear_app_translate_key_handler(mmi_frm_translate_keyhandler_func_ptr func_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_translate_key_handler
 * DESCRIPTION
 *  Currently, there are three layers for translate key handler,system layer,
 *  application layer and editor layer. application level and editor layer have
 *  the same translate key handler entry. So in fact we have tow level now.
 *  The invoke sequency is:
 *  If SYS is false
 *  then If APP is false
 *      then traditional keyhandler
 *  or 
 *  If SYS is false
 *  then If EDITOR is false
 *      then traditional keyhandler      
 *
 * PARAMETERS
 *  layer         : [IN]   translate key handler level which determine the invoke
 *                        sequency of the translate key handler
 *  func_ptr      : [IN]   translate key handler that will be set
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * //IME usage
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void some_input_method_proc()
 * {
 *     mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, my_translate_key_handler);  
 * }
 * </code>
 *****************************************************************************/
extern void mmi_frm_set_translate_key_handler(mmi_frm_trans_key_handle_enum type, mmi_frm_translate_keyhandler_func_ptr func_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_translate_key_handler
 * DESCRIPTION
 *  Clear translate key handler for specific layer.
 *  All translate key handler will be cleared when screen switch, so if user
 *  don't have special usage. It is not necessary to invoke this interface.
 *  we use func_ptr which user used when call mmi_frm_set_translate_key_handler
 *  as the parameters for futher extension.
 *  For example, we may support multi-translate key handler in the same layer in the future
 *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_APP, my_translate_key_handler1);
 *      mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_APP, my_translate_key_handler2);
 *      we will has two translater key handler in application layer.
 *      when clear, we use the translate key handler to distinguish 
 *      which key handler should be cleared.
 *
 * PARAMETERS
 *  layer         : [IN] translate key handler level which determine the invoke
 *                        sequency of the translate key handler 
 *  func_ptr      : [IN] translate key handler application use it in mmi_frm_set_app_translate_key_handler
 * RETURNS
 *  MMI_TRUE, cleared successfully, MMI_FALSE, already changed by another one
 * EXAMPLE
 * <code>
 *
 * MMI_BOOL my_translate_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
 * {
 *     ... 
 * }
 * void my_entry_function()
 * {
 *     EntryNewScreen(...);
 *     mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, my_translate_key_handler);  
 * }
 *  
 * void some_function()
 * {
 *     mmi_frm_clear_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, my_translate_key_handler); 
 * }
 * </code>
 *****************************************************************************/
extern MMI_BOOL mmi_frm_clear_translate_key_handler(mmi_frm_trans_key_handle_enum type, mmi_frm_translate_keyhandler_func_ptr func_ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_translate_key_handler
 * DESCRIPTION
 *  Clear all translate key handler.
 *  Generally, this function is invoked when screen switch, the call stack is
 *  ExecuteCurrExitHandler->
 *  ClearInputEventHandler->
 *  mmi_frm_clear_all_key_handler->
 *  mmi_frm_clear_all_translate_key_handler
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_clear_all_translate_key_handler(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_keypad_mode
 * DESCRIPTION
 *  This function is used to set keypad mode
 * PARAMETERS
 *  mode        : [IN]   see mmi_frm_keypad_mode_enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_keypad_mode(U8 mode);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_key_event
 * DESCRIPTION
 *  This function is used to judge if key handler is triggered by key or touch
 *  
 *  Notes:
 *    1. provide this API because dialer need to judge if the key handler is triggered
 *       by pen or by key. If trigger by pen, the PW+ is input by multi-tap of *
 *       If triggered by key, the PW+ is input by KEY_W/shift + W/KEY_p.
 *    2. If the key handler is not invoked by mmi_frm_exec_key_handler, please don't use 
 *       this interface.
 *       
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_frm_is_key_event(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_mmi_key_state
 * DESCRIPTION
 *  This API is used to query mmi key state in MMI level
 *  only for dial to query mmi key state now.
 * PARAMETERS
 *  mmi_key_code : [IN] mmi key code
 * RETURNS
 *  mmi key type
 *****************************************************************************/
extern U8 mmi_frm_query_mmi_key_state(S16 mmi_key_code);

/*****************************************************************************
* FUNCTION
*  mmi_frm_construct_key_event
* DESCRIPTION
*  This function is used to initialize the key event structure.
*  If a module want to send/post a key event to another module
* 
* PARAMETERS
*  key_code     : [IN]  mmi key code
*  key_type     : [IN]  mmi key type
*  key_evt_p    : [IN]  the key event struct that need to be initialized 
*    
* RETURNS
*  void
* EXAMPLE
* <code>
*   //send a key event to xxx module's key proc function
*   mmi_frm_key_evt_struct key_evt;
*   mmi_frm_construct_key_event(KEY_1, KEY_EVENT_DOWN, &key_evt);
*   user_data = mmi_xxx_get_user_data();
*   mmi_frm_send_event(&key_evt, mmi_xxx_key_proc, user_data);
*
*   //post a key event to xxx module's key proc function
*   mmi_frm_key_evt_struct key_evt;
*   mmi_frm_construct_key_event(KEY_1, KEY_EVENT_DOWN, &key_evt);
*   user_data = mmi_xxx_get_user_data();
*   mmi_frm_post_event(&key_evt, mmi_xxx_key_proc, user_data);  
* </code>
*****************************************************************************/
extern void mmi_frm_construct_key_event(U8 key_code, U8 key_type, mmi_frm_key_evt_struct *key_evt_p);

/*****************************************************************************
* FUNCTION
*  mmi_frm_send_key_event
* DESCRIPTION
*  This function is used to initialize the key event structure.
*  If a module want to send/post a key event to another module
* 
* PARAMETERS
*  key_code     : [IN]  mmi key code
*  key_type     : [IN]  mmi key type
*    
* RETURNS
*  void
* EXAMPLE
* <code>
* </code>
*****************************************************************************/
extern void mmi_frm_send_key_event(U8 key_code, U8 key_type);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_present_all_key_num
 * DESCRIPTION
 *  This function is used to get the elment number of PresentAllKeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 mmi_frm_get_present_all_key_num(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_present_all_key_num
 * DESCRIPTION
 *  This function is used to get the element number of PresentAllDialerKeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 mmi_frm_get_all_dial_key_num(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_handle
 * DESCRIPTION
 *  This function is used for process the keypad handler.
 * PARAMETERS
 *  paraBuff        : [IN]  The pointer to the parameter buffer.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_key_handle(void *paraBuff);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_evt_report_ind
 * DESCRIPTION
 *  protocol event handler of MSG_ID_MMI_AT_KEYPAD_EVENT_ACT_IND
 *
 * PARAMETERS
 *  para       : [IN] local parameter of MSG_ID_MMI_AT_KEYPAD_EVENT_ACT_IND
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_evt_report_ind(void *para);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_event_count
 * DESCRIPTION
 *  This function is used to get the pending key events' number
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  pending key events number
 *****************************************************************************/
extern U32 mmi_frm_get_key_event_count(void);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-END */
#endif /* _KEYBRD_INT_H_ */



#ifndef _TOUCH_SCREEN_GPROT_INT_H
#define _TOUCH_SCREEN_GPROT_INT_H
/*----------------------------------------------------------------*
  Touch Screen
 *----------------------------------------------------------------*/
/***************************************************************************** 
* Define
*****************************************************************************/
/* Sampling period of Event-Based pen events (~ 12 samples/sec), the unit is multiple of 10ms */
#ifdef __MMI_FTE_SUPPORT__
#define MMI_PEN_SAMPLING_PERIOD_1      (3)
#else
#define MMI_PEN_SAMPLING_PERIOD_1      (8)
#endif

/* Sampling period of Stroke-Based pen events (50 samples/sec),the unit is multiple of 10ms */
#define MMI_PEN_SAMPLING_PERIOD_2      (5)

/* Delay time for Pen Repeat on Modis, the unit is multiple of 10ms */
#define MMI_PEN_REPEAT_TIME            (30)

/* Utility macro functions, check pen bound */
#define PEN_CHECK_BOUND(x, y, x1, y1, width, height) ((x) >= (x1) && (y) >= (y1) && (x) < ((x1) + (width)) && (y) < ((y1) + (height)))

/* Utility macro functions, compute absolute value */
#define PEN_ABS(a, b) (((a) > (b)) ? (a-b) : (b-a))

/* Utility macro functions, return the smaller one */
#define PEN_MIN(a, b) (((a) > (b)) ? (b) : (a))

/* Utility macro functions, return the bigger one */
#define PEN_MAX(a, b) (((a) > (b)) ? (a) : (b))

/* If pen does not move over this distance, donot generate Pen Move event at all. */
#define MMI_PEN_SKIP_MOVE_OFFSET                5

/* If pen does not move over this distance, donot generate Stroke Move event at all. */
#define MMI_PEN_SKIP_STROKE_MOVE_OFFSET         1

#if defined(__TOUCH_PANEL_CAPACITY__) && defined(__MTK_TARGET__)
/* Maximum move offset for generating LongTap event(Capacity touch panel0.5/2.54/2) */
#define MMI_PEN_SKIP_LONGTAP_OFFSET   (0.098 * LCM_DPI)
#else
/* Maximum move offset for generating LongTap event (Resistance touch panel)*/
#define MMI_PEN_SKIP_LONGTAP_OFFSET             10
#endif

/* Maximum move offset for generating Stroke-LongTap event (MMI_PEN_SUPPORT_STROKE_LONGTAP) */
#define MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET      14

/* The threshold for identifying double-click event, 500ms */
#define MMI_PEN_DOUBLE_CLICK_THRESHOLD  (KAL_TICKS_500_MSEC)
/* If pen click out this distance, donot generate Pen double click event at all. */
#define MMI_PEN_SKIP_DOUBLE_CLICK_OFFSET_SQUARE       (25)
/* Delay time for Pen LongTap, multiple of 10ms */
#define MMI_PEN_LONGTAP_TIME           (60)
/* Delay time for Stroke LongTap (MMI_PEN_SUPPORT_STROKE_LONGTAP),multiple of 10ms */
#define MMI_PEN_STROKE_LONGTAP_TIME    (80)

/* DOM-NOT_FOR_SDK-BEGIN */
/* Minimum offset to Pen Down position in order to switch from event-based mode to stroke-based mode */
#if defined(__MMI_HANDWRITING_PAD__)
#define MMI_PEN_STROKE_MIN_OFFSET               0

#elif defined(__MMI_IME_V3__)
#define MMI_PEN_STROKE_MIN_OFFSET   10

#else 
#define MMI_PEN_STROKE_MIN_OFFSET               9
#endif 
/* DOM-NOT_FOR_SDK-END */

/* Number of doubles in one set of  calibation data */
#define PEN_CALIBRATION_DATA_SIZE   4

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_HANDWRITING_PAD__
#define TP_MAPPING_KEY_MASK                 (0x000000FF)
#define TP_MAPPING_KEY                      (0x00000100)
#define TP_CUSTOM_HANDLE                    (0x00000200)
#define TP_CONTROL_AREA                     (0x80000000)
#define TP_HANDWRITING_AREA                 (0x40000000)
#define TP_HANDWRITING_SUPPORTS_FULL_AREA   (0x20000000)

#define IS_ENABLE_FLAG(data, f)             ((data & (f)) == (f))
#endif /* __MMI_HANDWRITING_PAD__ */ 
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */

/* This enum is used to print trace only */
typedef enum
{
    DRV_PEN_DOWN           = DCL_PEN_DOWN,
    DRV_PEN_UP             = DCL_PEN_UP,
    DRV_PEN_MOVE           = DCL_PEN_MOVE,
    DRV_PEN_PEN_LONGTAP    = DCL_PEN_LONGTAP,
    DRV_PEN_REPEAT         = DCL_PEN_REPEAT,
    DRV_PEN_ABORT          = DCL_PEN_ABORT, 
    DRV_PEN_UNKNOW_EVENT   = DCL_TP_UNKNOWN_EVENT,
    DRV_STROKE_MOVE        = DCL_STROKE_MOVE,
    DRV_STROKE_STATICAL    = DCL_STROKE_STATICAL,
    DRV_STROKE_HOLD        = DCL_STROKE_HOLD,
    DRV_PEN_LONGTAP_HOLE   = DCL_PEN_LONGTAP_HOLD,
    DRV_PEN_REPEAT_HOLD    = DCL_PEN_REPEAT_HOLD,
    DRV_PEN_STROKE_DOWN    = DCL_STROKE_DOWN,
    DRV_PEN_STROKE_LONGTAP = DCL_STROKE_LONGTAP,
    DRV_STROKE_UP          = DCL_STROKE_UP
} drv_pen_evt_enum;
/* DOM-NOT_FOR_SDK-END */

/* structure of Point */
typedef struct
{
    /* x coordinate */
    S16 x;
    /* x coordinate */
    S16 y;
} mmi_pen_point_struct;

/* MMI touch event type, it includes pen event and touch event */
typedef enum
{
    /* MMI pen event down */
    MMI_PEN_EVENT_DOWN,
    /* MMI pen event up */
    MMI_PEN_EVENT_UP,
    /* MMI pen event long tap */
    MMI_PEN_EVENT_LONG_TAP,
    /* MMI pen event repeat */
    MMI_PEN_EVENT_REPEAT,
    /* MMI pen event move */
    MMI_PEN_EVENT_MOVE,
    /* MMI pen event abort */
    MMI_PEN_EVENT_ABORT,
    /* MMI pen event double click */
    MMI_PEN_EVENT_DOUBLE_CLICK,
    /* No MMI pen event */
    MMI_PEN_EVENT_NONE,
    /* MMI pen event type total number */
    MMI_PEN_EVENT_TYPE_MAX = MMI_PEN_EVENT_NONE,
    /* not time out of the longtap timer, no need to handle this event */
    MMI_PEN_LONGTAP_HOLD,
    /* not time out of the repeat timer, no need to handle this evnet */
    MMI_PEN_REPEAT_HOLD,
    /* The stroke down event in handwriting */
    MMI_STROKE_DOWN,
    /* just temp state between stroke down and stroke longtap, no need to handle this evnet */
    MMI_STROKE_STATICAL,
    /* just temp state, it is not match the move condition, no need to handle this evnet */
    MMI_STROKE_HOLD,
    /* The stroke up event in handwriting */
    MMI_STROKE_UP,
    /* The stroke move event in handwriting */
    MMI_STROKE_MOVE,
    /* The stroke longtap event in handwriting, no use now */
    MMI_STROKE_LONGTAP,
    /* no stroke event, you should not handle this */
    MMI_STROKE_NONE,
    /* MMI pen event total number, you should not handle this */
    MMI_STROKE_TYPE_MAX = MMI_STROKE_NONE,
    /* mmi pen invalid event, you should not handle this */
    MMI_PEN_INVALID_EVENT = 0xff,
} mmi_pen_event_type_enum;

/* MMI stroke event type */
typedef enum
{   
    /* MMI stroke event down */
    MMI_PEN_STROKE_DOWN,
    /* MMI stroke event up */
    MMI_PEN_STROKE_UP,
    /* MMI stroke event move */
    MMI_PEN_STROKE_MOVE,
    /* MMI stroke event longtap, No Handle for stroke long tap */
    MMI_PEN_STROKE_LONGTAP,
     /* No MMI stroke event */
    MMI_PEN_STROKE_NONE,
     /* MMI stroke event type total number */
    MMI_PEN_STROKE_TYPE_MAX = MMI_PEN_STROKE_NONE
} mmi_pen_stroke_type_enum;


/* The return value of handling touch event when you stop the touch event routing. */
#define MMI_RET_STOP_TOUCH_HANDLE  (10)

/* Pen abort type */
typedef enum
{
    /* No Pen abort type */
    MMI_PEN_ABORT_TYPE_NONE,
    /* Pen abort type, drive queue is full */
    MMI_PEN_ABORT_TYPE_DRVQ_FULL,
    /* Pen abort type, switch screen */
    MMI_PEN_ABORT_TYPE_SWITCH_SCRN,
    /* Pen abort type total number */
    MMI_PEN_ABORT_TYPE_TOTAL
} mmi_pen_abort_type_enum;

/* touch screen mode */
typedef enum
{
    /* Stroke event, mostly this is in handwring area */
    TOUCH_SCREEN_STROKE_BASE,
    /* general pen event */
    TOUCH_SCREEN_EVENT_BASE,
    /* no use */
    TOUCH_SCREEN_MODE_END
} mmi_pen_mode_enum;



/* structure of polygon */
typedef struct
{
    /* polygon area points */
    mmi_pen_point_struct *points;
    /* Number of points */
    S16 num;
} mmi_pen_polygon_area_struct;

/* structure of handwriting aread */
typedef struct
{
    /* x coordinate of left-top point */
    S16 x1; 
    /* y coordinate of left-top point */
    S16 y1;
    /* x coordinate of right-bottom point */
    S16 x2;
    /* y coordinate of right-bottom point */
    S16 y2;
} mmi_pen_handwriting_area_struct;

/* structure for pen calibration data  */
typedef struct
{   
    /* pen calibration data */
    double data[PEN_CALIBRATION_DATA_SIZE];
} mmi_pen_calibration_struct;

/* structure for current pen information */
typedef struct
{
    /* the current pen mode, event base or stroke base */
    mmi_pen_mode_enum mode;
    /* event enum, please refer mmi_pen_event_type_enum or mmi_pen_stroke_type_enum */
    U8 event;
    /* touch position information */
    mmi_pen_point_struct point;
    /* time stamp */
    U16 time_stamp;
} mmi_pen_info_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_HANDWRITING_PAD__
typedef struct tp_area_struct_tag
{
    kal_uint32 id;
    kal_uint32 flag;
    const mmi_pen_point_struct *pos;
    mmi_pen_hdlr *hdlr_table;

} tp_area_struct;

#endif /* __MMI_HANDWRITING_PAD__ */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8  type;
    kal_uint16 x;
    kal_uint16 y;
} mmi_csta_req_struct;

typedef struct  
{
    LOCAL_PARA_HDR
    kal_int32  res;
} mmi_csta_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
} mmi_css_req_struct;
 
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32  max_x;
    kal_int32  max_y;
} mmi_css_ind_struct;
/* DOM-NOT_FOR_SDK-END */


/* Touch screen mode */
typedef enum
{
    /* Single touch mode, just send one finger event to application, this is default behavior */
    MMI_FRM_SINGLE_TOUCH,
    /* Multi-touch mode, send several events to application, according to how many fingers on the screen, at most it is five */
    MMI_FRM_MULTI_TOUCH,
    /* Total touch event total, no need to handle this */
    MMI_FRM_MULTI_TOUCH_TOTAL
} mmi_frm_touch_mode;

/* The finger id type in touch event structure */
#define MMI_TOUCH_ID U16

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
/* The max finger number supports by framework */
#define MMI_FRM_MULTI_TOUCH_MAX_FINGER 5

#else
/* The max finger number supports by framework */
#define MMI_FRM_MULTI_TOUCH_MAX_FINGER 1

#endif

/* The touch position structure */
typedef struct
{
    /* The coordinates of this event */
    mmi_pen_point_struct pos;
    /* The timestamp of this event */
    U32 timestamp;
} mmi_touch_pos_struct;

/*
 *  Each finger touch data information
 *  Example:
 *  typedef struct
 *  {
 *      MMI_TOUCH_ID id; // 1
 *      mmi_pen_event_type_enum  event; // MMI_PEN_EVENT_MOVE
 *      mmi_touch_pos_struct currpos; // ((200, 150), 30000)
 *      U16 area; // 50
 *      mmi_pen_event_type_enum pre_event; // MMI_PEN_EVENT_DOWN
 *      mmi_touch_pos_struct pre_pos; // ((200, 110), 29999)
 *      mmi_touch_pos_struct down_pos; // ((200, 110), 29999)
 *      U16 merge_num; // 2
 *      mmi_touch_pos_struct* merge_points; // ((200, 200), 30010), ((200, 250), 30020)
 *      U16* merge_area; // (50, 40)
 *  } mmi_touch_data_struct;
 */
typedef struct
{
    MMI_TOUCH_ID id; /* finger id */
    mmi_pen_event_type_enum  event; /* current touch event */
    mmi_touch_pos_struct currpos; /* current touch info */
    U16 area; /* current finger area */
    mmi_pen_event_type_enum pre_event; /* previous touch event */
    mmi_touch_pos_struct pre_pos; /* previous touch info */
    mmi_touch_pos_struct down_pos; /* pen down info */
    U16 merge_num;  /* if there are several pen move events, we will send several pen move events together to application */
    mmi_touch_pos_struct* merge_points; /* pen move events array */
    U16* merge_area; /* related pen move area */
} mmi_touch_data_struct;

/* The touch event struct, the structure header is MMI_EVT_PARAM_HEADER */
typedef struct
{
    /* The touch event header, the event id could be EVT_ID_PRE_TOUCH_EVT_ROUTING,
     * EVT_ID_POST_TOUCH_EVT_ROUTING or EVT_ID_ON_TOUCH.
     */
    MMI_EVT_PARAM_HEADER
    /* The finger number of this event, at most it is five */
    U16 touch_num;
    /* The touch data of each event */
    mmi_touch_data_struct touch_data[MMI_FRM_MULTI_TOUCH_MAX_FINGER];
    /* main point of multi-touch */
    mmi_touch_data_struct main_point;
} mmi_multi_touch_event_struct;



/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_HANDWRITING_PAD__

/* touch panel calibration point */
extern const mmi_pen_point_struct tp_calibration_point[];

/* touch panel area table */
extern const tp_area_struct tp_area_table[];
#endif /* __MMI_HANDWRITING_PAD__ */ 
/* DOM-NOT_FOR_SDK-END */
/***************************************************************************** 
* Call back
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/***************************************************************************** 
 * CALLBACK
 *  pre pen or post pen call back function
 * DESCRIPTION
 *  pre or post pen handler call back function
 * PARAMETERS    
 *  pen_event : [IN] pen event
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*func_ptr_short) (U16 pen_event);
/* DOM-NOT_FOR_SDK-END */
    
/***************************************************************************** 
 * DESCRIPTION
 *  pen event or stroke event handler call back function
 * PARAMETERS    
 *  pos        : [IN] The coordinate of touch point
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mmi_pen_hdlr) (mmi_pen_point_struct pos);

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_dummy_hdlr
 * DESCRIPTION
 *  This function is the dummy pen handler. It will do nothing.
 *  Some applications will use this function as the dump pen handler 
 *  
 * PARAMETERS
 *  pos     : [IN] The position of the touched point.        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_dummy_hdlr(mmi_pen_point_struct);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_sampling_period
 * DESCRIPTION
 *  Config sampling period of Event-based and Stroke-Based
 * PARAMETERS
 *  low         : [IN]        (Pen Event)Sampling period in non-handwriting area (multiple of 10ms)
 *  high        : [IN]        (Stroke Event)Sampling period in handwriting area (multiple of 10ms)
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_config_sampling_period(kal_uint32 low, kal_uint32 high);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_timeout_period
 * DESCRIPTION
 *  Config timeout period for LongTap and Repeat
 * PARAMETERS
 *  longtap             : [IN]        Timeout period for Pen LongTap event (multiple of 10ms).
 *  repeat              : [IN]        Timeout period for Pen Repeat event (multiple of 10ms).
 *  stroke_longtap      : [IN]        Timeout period for Stroke LongTap event (multiple of 10ms).
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_config_timeout_period(kal_uint32 longtap, kal_uint32 repeat, kal_uint32 stroke_longtap);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_move_offset
 * DESCRIPTION
 *  Config
 * PARAMETERS
 *  event_based         : [IN]        Minimum move offset for Pen Move event
 *  stroke_based        : [IN]        Minimum move offset for Stroke Move event
 *  long_tap            : [IN]        Maximum move offset for Pen LongTap event
 *  stroke_long_tap     : [IN]        Maximum move offset for Stroke LongTap event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_config_move_offset(
                kal_uint32 event_based,
                kal_uint32 stroke_based,
                kal_uint32 long_tap,
                kal_uint32 stroke_long_tap);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_init
 * DESCRIPTION
 *  Initialize pen system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_is_in_at_mode
 * DESCRIPTION
 *  For setting/calibraction, if in the AT command mode, just do as modis behavior.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_pen_is_in_at_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_block
 * DESCRIPTION
 *  Block pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 *  mmi_pen_enable()/mmi_pen_disable() are ignored when pen is blocked.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_block(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_unblock
 * DESCRIPTION
 *  Unblock pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 *  mmi_pen_enable()/mmi_pen_disable() are ignored when pen is blocked.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_unblock(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_enable
 * DESCRIPTION
 *  Enable pen system
 *  
 *  Note: typically on Keypad Up
 *  If g_pen_initialized is not true, we do not enable touch screen because
 *  TP task might not be running
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_enable(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_disable
 * DESCRIPTION
 *  Disable pen system, all touch event will not send to applications.
 *  
 *  Note: typically on Keypad Down because we don't want to use keypad and touch screen
 *  at the same time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_disable(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_reset
 * DESCRIPTION
 *  Reset the status of touch screen
 *  - Flush event queue
 *  - If the pen is currently tapped down, ignore all subsequent pen events until the pen is up.
 *  
 *  Note: typically on MMI screen switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_reset(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_state
 * DESCRIPTION
 *  Get the current state of touch screen
 *  It returns the current state *inside MMI task*, real pen state might be changed, but
 *  the driver indication might not be processed yet.
 *
 * PARAMETERS
 *  is_enabled      : [OUT] Is pen enabled or not        
 *  is_pen_down     : [OUT] Is pen down or not
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_get_state(kal_bool *is_enabled, kal_bool *is_pen_down);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_info
 * DESCRIPTION
 *  Get the current information of pen event.
 * PARAMETERS
 *  pen_type        : [OUT]  If the current event is pen event, pen event will be got      
 *  stroke_type     : [OUT]  If the current event is stroke event, stroke event will be got      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_get_info(mmi_pen_event_type_enum *pen_type, mmi_pen_stroke_type_enum *stroke_type);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_set_event_handler_callback
 * DESCRIPTION
 *  The application could set the pen callback function 
 *  (pre- and post- callback function)
 *  We will invoke the callback when touch-screen calls the pen event handler.
 *  The application can only set it when the pre pen handler and post pen handler
 *  is NULL.
 *
 * PARAMETERS
 *  pre_fp      : [IN] pre pen handler         
 *  post_fp     : [IN] post pen handler       
 * RETURNS
 * void
 *****************************************************************************/
extern void mmi_pen_set_event_handler_callback(func_ptr_short pre_fp, func_ptr_short post_fp);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_reset_event_handler_callback
 * DESCRIPTION
 *  The application can reset the pre and post pen handler of their own using
 *  the pre and post pen  handler they set before.
 *
 * PARAMETERS
 *  pre_fp      : [IN] The pre pen handler that app set         
 *  post_fp     : [IN] The post pen handler htat app set       
 * RETURNS
 * void
 *****************************************************************************/
extern void mmi_pen_reset_event_handler_callback(func_ptr_short pre_fp, func_ptr_short post_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_calibration
 * DESCRIPTION
 *  Start pen calibration
 *  After mmi_pen_reset(), the calibration process is terminated.
 * PARAMETERS
 *  num         : [IN]        Number of calibration points
 *  points      : [IN]        Calibration points buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_start_calibration(kal_uint16 num, const mmi_pen_point_struct *points);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_set_calibration_data
 * DESCRIPTION
 *  Assign driver calibration data
 * PARAMETERS
 *  data        : [IN]   calibration data     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_set_calibration_data(const mmi_pen_calibration_struct *data);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_read_calibration_data
 * DESCRIPTION
 *  Read the current value of driver calibration data
 * PARAMETERS
 *  data        : [OUT] calibration data from driver       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_read_calibration_data(mmi_pen_calibration_struct *data);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_down_handler
 * DESCRIPTION
 *  Register the Pen Down handler
 * PARAMETERS
 *  pen_fp      : [IN]  Callback function for Pen Down event.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_long_tap_handler
 * DESCRIPTION
 *  Register the Pen LongTap handler
 *  
 *  Note:
 *  1. LongTap handler is invoked when  the pen is tapped for a period of time
 *  and stays at the same place where it is tapped down.
 *  
 *  2. If pen move happen after pen down, there will be no pen longtap event.
 *  3. Pen long tap can only happen one time at most.
 * 
 * PARAMETERS
 *  pen_fp      : [IN]   Callback function for Pen LongTap event.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_repeat_handler
 * DESCRIPTION
 *  Register the Pen Repeat handler.
 *  
 *  Note:
 *  1. Repeat can happen after LongTap or move or another repeat.
 *  2. Repeat event's coordinate will follow the previous events
 *  
 * PARAMETERS
 *  pen_fp      : [IN]  Callback function for Pen Repeat event.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_move_handler
 * DESCRIPTION
 *  Register the Pen Move handler.
 *  The invocation frequency of Pen Move handler is typically less than driver sampling rate.
 * PARAMETERS
 *  pen_fp      : [IN]   Callback function for Pen Move event.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_up_handler
 * DESCRIPTION
 *  Register the Pen Up handler.
 * PARAMETERS
 *  pen_fp      : [IN]  Callback function for Pen Up event.      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_abort_handler
 * DESCRIPTION
 *  Register the Pen Abort handler.
 * PARAMETERS
 *  pen_fp      : [IN]  Callback function for Pen Abort event.      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_abort_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_double_click_handler
 * DESCRIPTION
 *  Register the Pen double click handler.
 * PARAMETERS
 *  pen_fp      : [IN]  Callback function for Pen Repeat event.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_double_click_handler(mmi_pen_hdlr pen_fp);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
* FUNCTION
*  mmi_pen_get_handler
* DESCRIPTION
*  This function is used for gets the pen event handler for current screen.
* PARAMETERS
*  pen_event     : [IN]  Which pen event's handler is wanted to query.       
* RETURNS
*  The handler of pen event.
*****************************************************************************/
extern mmi_pen_hdlr mmi_pen_get_pen_handler(mmi_pen_event_type_enum pen_event);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_capture_strokes
 * DESCRIPTION
 *  Start to capture stroke inside the handwriting area.
 *
 *  This API is typically used in entry function of editor screen.
 *
 *  The points are en-queued in 'point_array' in the following format:
 * 
 *  Each point contains two 16-bit integers for x, y coordinates. Two strokes are separated with
 *  marker (0xffff, 0), and all strokes of one character are ended with (0xffff, 0xffff) by
 *  mmi_pen_end_strokes_of_character(). The parameter 'max_points' should also include the memory 
 *  used by markers.
 *  (x0, y0) (x1, y1) ¡K (0xffff, 0), ¡K(0xffff, 0), ¡K(0xffff, 0xffff)
 *  
 *  We has the following types of stroke-based handler
 *  - Stroke Down
 *  - Stroke Move
 *  - Stroke Up
 *  However, it does not have Stroke Repeat handler.
 *  
 *  In single-block mode ('num_regions' > 1), it enters stroke-based mode when pen is down in 
 *  handwriting area and then moves across MMI_PEN_STROKE_MIN_OFFSET pixels.
 *
 *  In multi-block mode ('num_regions' > 1), it enters stroke-based mode immediately after pen 
 *  is down in handwriting area.
 * 
 *  Note: the parameter 'ext_region' can only be used in single-block mode.
 * 
 * PARAMETERS
 *  max_points          : [IN]        Maximum number of points can be en-queued.
 *  point_array         : [IN]        Array for storing sampled points in strokes.
 *  num_regions         : [IN]        Number of handwriting regions
 *  region_array        : [IN]        Handwriting regions
 *  ext_region          : [IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_start_capture_strokes(
                kal_uint32 max_points,
                mmi_pen_point_struct *point_array,
                kal_uint32 num_regions,
                const mmi_pen_handwriting_area_struct *region_array,
                const mmi_pen_handwriting_area_struct *ext_region);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_stop_capture_strokes
 * DESCRIPTION
 *  Stop capturing stroke
 *  
 *  Note: mmi_pen_reset() should be used to flush driver pen queue
 *  after this function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/                
extern void mmi_pen_stop_capture_strokes(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_enable_stroke_event
 * DESCRIPTION
 *  This function is used to enable stroke event in single block handwriting mode
 *  To design this API is to enable stroke event. If IME disable stroke event in
 *  single box handwriting mode, IME must invoke this API to enable stroke event
 *  when it finish its work. Please refer mmi_pen_disable_stroke_event for more 
 *  detail information.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *   //In pen down handler to disable stroke events
 *   void pen_down_hdlr(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_disable_stroke_event();
 *       }
 *   }
 *
 *   //In pen up handler to enable stroke events
 *   void pen_up_handler(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_enable_stroke_event();
 *       }
 *   }
 *   //In pen abort handler to enable stroke events
 *   {
 *        if (handwriting_mode == SINGLE_BLOCK)
 *        {
 *            mmi_pen_enable_stroke_event();
 *        }
 *   }
 * </code>
 *****************************************************************************/
extern void mmi_pen_enable_stroke_event(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_disable_stroke_event
 * DESCRIPTION
 *  This function is used to disable stroke events in single-block Handwriting
 *  mode. Please don't use this interface in multi-block handwriting mode.
 *  To design this API is to disable stroke events when pen is down in an area,
 *  where IME will hope to receive pen events instead of stroke events.
 *  The mechanism is based on the original single block pen event mechanism.
 *  That is.
 *    stroke down => pen down
 *    stroke move => pen move if stroke move offset > MMI_PEN_SKIP_MOVE_OFFSET
 *    if square(stroke move offset) > g_pen_stroke_min_offset = square(MMI_PEN_STROKE_MIN_OFFSET)
 *    stroke move => pen abort stroke down stroke move
 *
 *  So this API sets the g_pen_stroke_min_offset as 0x7FFF to make sure
 *  stroke move offset will always < g_pen_stroke_min_offset to implement
 *  disable stroke events in the whole touch panel.
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *   //In pen down handler to disable stroke events
 *   void pen_down_hdlr(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_disable_stroke_event();
 *       }
 *   }
 *
 *   //In pen up handler to enable stroke events
 *   void pen_up_handler(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_enable_stroke_event();
 *       }
 *   }
 *   //In pen abort handler to enable stroke events
 *   {
 *        if (handwriting_mode == SINGLE_BLOCK)
 *        {
 *            mmi_pen_enable_stroke_event();
 *        }
 *   }
 * </code>
 *****************************************************************************/
extern void mmi_pen_disable_stroke_event(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_change_handwriting_area
 * DESCRIPTION
 *  Change hand-written area.
 *  It is typically used when changing input language.
 *  
 *  It will
 *  1. reset handwriting and g_pen_stroke_min_offset_square
 *  2. mmi_pen_reset() to flush queue.
 * PARAMETERS
 *  num_regions         : [IN]        Number of handwriting regions
 *  region_array        : [IN]        Handwriting regions
 *  ext_region          : [IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_change_handwriting_area(
                kal_uint32 num_regions,
                const mmi_pen_handwriting_area_struct *region_array,
                const mmi_pen_handwriting_area_struct *ext_region);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_change_handwriting_area_ex
 * DESCRIPTION
 *  Change hand-written area.
 *  It is typically used when changing input language.
 *  
 *  It will
 *  1. reset handwriting and g_pen_stroke_min_offset_square
 *  2. mmi_pen_reset() to flush queue.
 * PARAMETERS
 *  num_regions         : [IN]        Number of handwriting regions
 *  region_array        : [IN]        Handwriting regions
 *  ext_region          : [IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_change_handwriting_area_ex(
                kal_uint32 num_regions,
                const mmi_pen_handwriting_area_struct *region_array,
                const mmi_pen_handwriting_area_struct *ext_region);
                
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_begin_strokes_of_character
 * DESCRIPTION
 *  Start to write a new character
 *  
 *  It is typically coupled with mmi_pen_end_strokes_of_character(), which stops en-queueing
 *  strokes inside 'point_array'.
 *  In mmi_pen_begin_strokes_of_character(), MMI continue to en-queue strokes from the head of 'point_array'.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_begin_strokes_of_character(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_end_strokes_of_character
 * DESCRIPTION
 *  End a written character.
 *  
 *  The following procedures are executed
 *  o Reset handwriting area to original size
 *  o Stop en-queueing new strokes inside 'point_array'. (But incoming strokes are still en-queued in driver ring buffer)
 *  o Append end marker (0xffff, 0xffff) in 'point_array'
 *  This API should be used only if there is no unfinished stroke (checked by mmi_pen_peek_stroke_state()).
 *  After it returns, we may pass 'point_array' to handwriting recognition engine.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_end_strokes_of_character(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_down_handler
 * DESCRIPTION
 *  Register the Stroke Down handler
 * PARAMETERS
 *  pen_fp      : [IN]   Callback function for Stroke Down event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_stroke_down_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_move_handler
 * DESCRIPTION
 *  Register the Stroke Move handler
 *  Note: pre and post multiple stroke move handler is not used any more.
 *        So we will remove it gradually.
 * PARAMETERS
 *  begin_fp        : [IN]        Callback function before multiple Stroke Move events
 *  end_fp          : [IN]        Callback function after multiple Stroke Move events
 *  pen_fp          : [IN]        Callback function for Stroke Move event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_stroke_move_handler(mmi_pen_hdlr pen_fp);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_touch_set_mode
 * DESCRIPTION
 *  set touch screen mode
 * PARAMETERS
 *  mode : [IN] the parameter should be mmi_frm_touch_mode, single or multiple
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_touch_set_mode(mmi_frm_touch_mode mode);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_touch_get_mode
 * DESCRIPTION
 *  get current screen touch mode
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_frm_touch_mode
 *****************************************************************************/
extern mmi_frm_touch_mode mmi_frm_touch_get_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_touch_register_proc
 * DESCRIPTION
 *  Register touch proc by screen level, no need to reset, the single touch event or
 *  multi-touch event will be both sent to the proc. The event id is EVT_ID_ON_TOUCH, If you want to handle EVT_ID_PRE_TOUCH_EVT_ROUTING
 *  or EVT_ID_POST_TOUCH_EVT_ROUTING, you could use callback manager to register the two events. When you want to stop touch event routing,
 *  you should return MMI_RET_STOP_TOUCH_HANDLE in your proc.
 *  This is new method, if you register pen event callback, it also could work. 
 * PARAMETERS
 *  proc : [IN] the proc, the event in the proc should be mmi_multi_touch_event_struct.
 *  user_data : [IN] user data, framework will send this user_data to your proc
 * RETURNS
 *  mmi_frm_touch_mode
 *****************************************************************************/
extern void mmi_frm_touch_register_proc(mmi_proc_func proc, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_up_handler
 * DESCRIPTION
 *  Register the Stroke Up handler
 * PARAMETERS
 *  pen_fp      : [IN]       Callback function for Stroke Up event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_register_stroke_up_handler(mmi_pen_hdlr pen_fp);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_peek_stroke_state
 * DESCRIPTION
 * PARAMETERS
 *  has_unfinished_stroke       : [OUT]   Whether there are more strokes to come
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_peek_stroke_state(MMI_BOOL *has_unfinished_stroke);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_stroke_handler
 * DESCRIPTION
 *  This function is used for gets the stroke event handler for current screen.
 * PARAMETERS
 *  stroke_event     :[IN]  Which stroke event's handler is wanted to query.       
 * RETURNS
 *  The handler of stroke event.
 *****************************************************************************/
extern mmi_pen_hdlr mmi_pen_get_stroke_handler(mmi_pen_stroke_type_enum stroke_event);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_pen_abort_type
 * DESCRIPTION
 *  Get pen abort type, since mmi_pen_reset will be invoked when driver queue full
 *  or screen is switched, so pen abort will happen in these cases, application need
 *  to differentiate these scenario.
 * PARAMETERS
 *  void
 * RETURNS
 *  pen abort type
 *****************************************************************************/
extern mmi_pen_abort_type_enum mmi_pen_get_pen_abort_type(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_curr_pen_info
 * DESCRIPTION
 *  This function is used to get curr pen info.
 *     case1: invoke it in pen handler, eg. in pen down handler, curr info is pen down 
 *     case2: invoke it after pen handler, eg. after pen down hander, curr info is also pen down 
 * PARAMETERS
 *  info      :[OUT] curr pen info
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_get_curr_pen_info(mmi_pen_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_prev_pen_info
 * DESCRIPTION
 *  This function is used to get the previous pen info
 *      If the pen event sequency is pen down, pen up, after pen up is handled by
 *      app, the curr pen info is pen up, and the prev pen info is pen down.
 *
 * PARAMETERS
 *  info      :[OUT] previous pen info
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_pen_get_prev_pen_info(mmi_pen_info_struct *info);

#ifdef __MMI_HANDWRITING_PAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_setup_default_pen_handler
 * DESCRIPTION
 *  the default pen handlers for the handwriting pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_setup_default_pen_handler(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_inside_control_area
 * DESCRIPTION
 *  Check the pen event if in the control area
 *  We will check the pen event for each control area that defined
 *  in tp_area_table[]
 * PARAMETERS
 *  pos     : [IN]        Pen event position
 * RETURNS
 *  S32   return the index of tp_area_table[]; return -1 if can't found
 *****************************************************************************/
extern S32 mmi_pen_check_inside_control_area(mmi_pen_point_struct pos);
#endif /* __MMI_HANDWRITING_PAD__ */
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_inside_polygon
 * DESCRIPTION
 *  Check if a point is inside a polygon.
 *  
 * PARAMETERS
 *  polygon     : [IN] The top points of the polygon        
 *  pos         : [IN] point that need to be judged.       
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_is_sw_pen_down
 * DESCRIPTION
 *  This function is used to check if the pen down event is generate by Framework
 *  when enter the new screen to ignore pen reset
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_pen_is_sw_pen_down(void);

#endif /* _TOUCH_SCREEN_GPROT_INT_H */

#endif /* MMI_FRM_INPUT_GPROT_H */ 


