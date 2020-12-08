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
 * KeyBrd_Int.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI keypad config function.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/


#ifndef _KEYBRD_INT_H_
#define _KEYBRD_INT_H_


/***************************************************************************** 
* Define
*****************************************************************************/
/* Total mmi keys except mmi key codes for qwerty project */
#define TOTAL_KEYS mmi_frm_get_present_all_key_num()

/* Framework have special KEY_END handling, and allow the applications could full control KEY_END handler */
#define MMI_FRM_APP_FULL_CONTROL    0x0001

/* Deprecated API and type: Please use the new API and new type */
#define mmi_kbd_set_concurrent_mode        mmi_frm_set_keypad_mode
#define SetkeyInfo                         mmi_frm_set_key_info
#define SetKeyHandlerEx                    mmi_frm_set_key_handler_ex
#define ClearAllKeyHandler                 mmi_frm_clear_all_key_handler
#define ExecuteCurrKeyHandler              mmi_frm_exec_key_handler
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

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_KEY_TONE_ENABLED = 0,
    MMI_KEY_VOL_TONE_DISABLED,
    MMI_KEY_VOL_UP_DOWN_TONE_DISABLED,
    MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED,
    MMI_KEY_TONE_DISABLED,
    MMI_KEY_TONE_INVALID
} mmi_frm_kbd_tone_state_enum;

typedef struct KEYBRD_MESSAGE
{
    LOCAL_PARA_HDR
    S16 nMsgType;
    S16 nKeyCode;
} KEYBRD_MESSAGE;
 
typedef U8(*PsKeyProcessCBPtr) (KEYBRD_MESSAGE *);



/* DOM-NOT_FOR_SDK-BEGIN */
/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern const U16 PresentAllKeys[];
#ifdef __MMI_SUBLCD_MASTER_MODE__                                   
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
extern FuncPtr currKeyFuncPtrs_slave[MAX_KEYS][MAX_KEY_TYPE];
extern FuncPtr currKeyFuncPtrs_master[MAX_KEYS][MAX_KEY_TYPE];
#else
extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];
#endif /* __MMI_SUBLCD_MASTER_MODE__ */

/*********************************************************************************************************************
* External Keypad & Key handler API
**********************************************************************************************************************/
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_exec_key_handler
 * DESCRIPTION
 *  This function is used for executes current key function handler only. 
 *  This function won't execute pre key handler and post key handler.
 * PARAMETERS
 *  keyCode     [IN]    Key to which this event is associated.     
 *  keyType     [IN]    KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                      key is pressed or released.      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_exec_key_handler(S16 keyCode, S16 keyType);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_info
 * DESCRIPTION
 *  This function is used for querying key code & key type of last key event.
 * PARAMETERS
 *  keyCode     [OUT]  The pointer to the Key Code.
 *  keyType     [OUT]  The pointer to the Key type.       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_get_key_info(U16 *keyCode, U16 *keyType);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_info
 * DESCRIPTION
 *  This function is used for temporary sets key code & key type of last key event.
 * PARAMETERS
 *  keyCode     [IN]  Key to which this event is associated         
 *  keyType     [IN]  KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key 
 *                    is pressed or released      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_key_info(U16 keyCode, U16 keyType);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_handler
 * DESCRIPTION
 *  This function is used for gets the key event handler for current screen.
 * PARAMETERS
 *  keyCode     [IN]  Key to which this event is associated.       
 *  keyType     [IN]  What key type is wanted to query.       
 * RETURNS
 *  void
 *****************************************************************************/
extern FuncPtr mmi_frm_get_key_handler(U16 keyCode, U16 keyType);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_handler
 * DESCRIPTION
 *  This is used to sets the curent screen key handlers
 * PARAMETERS
 *  funcPtr     [IN] Function to be executed on occurrence of the event.
 *  keyCode     [IN] Key to which this event is associated.
 *  keyType     [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key
 *                   is pressed or released
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_key_handler(FuncPtr funcPtr,U16 keyCode,U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_handler_ex
 * DESCRIPTION
 *  This is used to sets the curent screen key handlers
 * PARAMETERS
 *  funcPtr     [IN] Function to be executed on occurrence of the event.
 *  keyCode     [IN] Key to which this event is associated.      
 *  keyType     [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key
 *                   is pressed or released
 *  flag        [IN] flag of full control or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_key_handler_ex(FuncPtr funcPtr,U16 keyCode,U16 keyType,U16 flag);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_group_key_handler
 * DESCRIPTION
 *  This is used to sets the same key handler for a group of keycodes.
 * PARAMETERS
 *  funcPtr         [IN] Function to be executed on occurrence of the event.
 *  keyCodes        [IN] Key array to which these events are associated.
 *  len             [IN] The keyCodes array size.
 *  keyType         [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                       key is pressed or released.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_handler
 * DESCRIPTION
 *  This function is used for clear the key event handler for current screen.
 * PARAMETERS
 *  keyCode     [IN] Key to which this event is associated.
 *  keyType     [IN] KEY_EVENT_UP, KEY_EVENT_DOWN, free the event associated
 *                   with press or released state.       
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_clear_key_handler(U16 keyCode, U16 keyType);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_key_handler
 * DESCRIPTION
 *  This function is used for clears all the key handlers associated with
 *  current screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/            
extern void mmi_frm_clear_all_key_handler(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_power_end_key_handler
 * DESCRIPTION
 *  This function is used for sets power key & end key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_power_end_key_handler(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_suspend_handle_key_process
 * DESCRIPTION
 *  This function is used to suspend key process.
 * PARAMETERS
 *  enable     [IN] MMI_TRUE enable, MMI_FALSE disable
 *
 * RETURNS
 *  Always return MMI_TRUE now 
 *****************************************************************************/
extern MMI_BOOL mmi_frm_suspend_handle_key_process(MMI_BOOL enable);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_stop_curr_key_tone
 * DESCRIPTION
 *  This function is used for stops current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_stop_curr_key_tone(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_key_supported
 * DESCRIPTION
 *  query if specified mmi key code is supported
 * PARAMETERS
 *  mmi_key_code    [IN]    mmi key code (mmi_keypads_enum) to query
 * RETURNS
 *  key is supported or not
 *****************************************************************************/
extern MMI_BOOL mmi_frm_kbd_is_key_supported(S16 key_code);


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
 *  KeyTone     [IN]  the keypad tone enum. Refer audio_id_enum.      
 * RETURNS
 *  Always returns MMI_TURE.  
 *****************************************************************************/
extern U8 mmi_frm_set_curr_key_tone(U16 KeyTone);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_dev_key_code
 * DESCRIPTION
 *  This function is used for reversly get the driver key code.
 * PARAMETERS
 *  mmi_key_code        [IN]        Key code of MMI
 * RETURNS
 *  driver key code
 *****************************************************************************/
extern S16 mmi_frm_get_dev_key_code(S16 mmi_key_code);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_set_tone_state
 * DESCRIPTION
 *  This function is used for chages the state of keypad tone.
 *  To prevent abnormal cases, keypad tone will be stopped before state changed.
 * PARAMETERS
 *  state       [IN]  Keypad tone state that want to be changed      
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_get_key_tone_state
 * DESCRIPTION
 *  This function is used for gets the state to see if keypad tone is disabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the key pad tone state. Refer mmi_frm_kbd_tone_state_enum.
 *****************************************************************************/
extern mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void);


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
 *  func        [IN]  Pre-Key handler      
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
 *  func        [IN]  Post-Key handler     
 * RETURNS
 *  void
 *****************************************************************************/
 extern void mmi_frm_kbd_reg_post_key_hdlr(PsKeyProcessCBPtr func);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_tone_enabled
 * DESCRIPTION
 *  This function is used for checks if keypad tone can be played or not.
 * PARAMETERS
 *  key_code        [IN]   Key to which this event is associated.
 *  key_type        [IN]   KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                         key is pressed or released.
 * RETURNS
 *  TRUE if the keypad tone shall be played by framework; otherwise, FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_kbd_is_tone_enabled(S16 key_code, S16 key_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_play_keypad_tone
 * DESCRIPTION
 *  This function is used for plays corresponding keypad tone.
 * PARAMETERS
 *  key_code        [IN]     Key to which this event is associated.
 * RETURNS
 *  void
 *****************************************************************************/
 extern void mmi_frm_play_keypad_tone(S16 key_code);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_stop_keypad_tone
 * DESCRIPTION
 *  This function is used for stops corresponding keypad tone.
 * PARAMETERS
 *  key_code        [IN]        Key code
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_stop_keypad_tone(S16 key_code);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_events
 * DESCRIPTION
 *  This function is used for clears Keyboard buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_clear_key_events(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/**********************************************************************************************************************
 * Framework Internal
 **********************************************************************************************************************/
#ifdef __MMI_SUBLCD_MASTER_MODE__
extern void mmi_frm_switch_key_func_ptr(void);
#endif
extern void mmi_frm_init_kpd_bf_pwon(void);
extern void mmi_frm_key_handle(void *paraBuff);
extern void mmi_frm_set_default_power_onoff_key(void);
/* DOM-NOT_FOR_SDK-END */

#endif /* _KEYBRD_INT_H_ */ 


