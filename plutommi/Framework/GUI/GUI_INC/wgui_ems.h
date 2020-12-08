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
 * wgui_ems.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for UI wrapper routines for EMS
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_ems.h
   Author:         steven wu
   Date Created:  March-22-2003
   Contains:      UI wrapper routines for EMS and category screens
**********************************************************************************/

#ifndef __WGUI_EMS_H__
#define __WGUI_EMS_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "gui_config.h"
#include "MMIDataType.h"
#include "ImeGprot.h"

    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "MessagesExDcl.h"
    #include "MMI_features.h"
    #include "ems.h"
    #include "wgui.h"
    
    #include "wgui_inputs.h"

#include "gui_ems.h"
//#include "wgui_categories.h"

#ifdef UI_EMS_SUPPORT

    /* EMS Application menus               */
    extern void GotoEMSTextFormattingMenu(void);
    extern void EntryEMSMainMenu(void);
    extern void ExitEMSMainMenu(void);
    extern void EntryEMSObjectsMenu(void);
    extern void ExitEMSObjectsMenu(void);
    extern void EntryEMSTextFormattingMenu(void);
    extern void ExitEMSTextFormattingMenu(void);
    extern void EntryEMSTextSizeSelectionMenu(void);
    extern void ExitEMSTextSizeSelectionMenu(void);
    extern void EntryEMSTextStyleSelectionMenu(void);
    extern void ExitEMSTextStyleSelectionMenu(void);
    extern void EntryEMSTextAlignmentSelectionMenu(void);
    extern void ExitEMSTextAlignmentSelectionMenu(void);
    extern void EntryEMSNewParagraphAlignmentMenu(void);
    extern void ExitEMSNewParagraphAlignmentMenu(void); 
    extern MMI_BOOL EMS_inputbox_multitap_input(UI_character_type c);
    extern MMI_BOOL EMS_inputbox_multitap_input_no_draw(UI_character_type c);
    extern void EMS_inputbox_multitap_input_complete(void);
    extern void EMS_inputbox_multitap_input_complete_no_draw(void);
    /* External functions from wgui_categories   */
    extern U8 *dummy_get_history(U8 *buffer);
    extern S32 dummy_get_history_size(void);
    extern void show_input_mode(void);

    /* Leo start 20050722, remove compile warnings */
    extern void wgui_EMS_setup_input_information(S32 x, S32 y, S32 width, S32 height);
    extern void wgui_EMS_reset_input_information(void);
    extern void move_EMS_inputbox(S32 x, S32 y);
    extern void resize_EMS_inputbox(S32 width, S32 height);
    extern void wgui_EMS_redraw_input_information_bar(void);
    extern void show_EMS_inputbox(void);
    extern void get_EMS_inputbox_category_history(U16 history_ID, U8 *history_buffer);
    extern U8 set_EMS_inputbox_category_history(U16 history_ID, U8 *history_buffer);
    /* Leo end 20050722 */
#define EMS_USE_INTERNAL_MENU             0
#define ENABLE_EMS_TEST_DEMO              0
#define EMS_USE_STUB_MENU                 0
#define ENABLE_EMS_TEST_OBJECTS              0
#define ENABLE_EMS_TEST_WORD_HIGHLIGHT       0
#define EMS_INPUTBOX_DEBUG                0
#define EMS_USE_GSM_EXTENDED              0


#define EMS_PREDEFINED_PICTURE         1
#define EMS_USERDEFINED_PICTURE        2
#define EMS_PREDEFINED_ANIMATION    3
#define EMS_USERDEFINED_ANIMATION      4
#define EMS_PREDEFINED_SOUND        5
#define EMS_PREDEFINED_MELODY       6
#define EMS_USERDEFINED_MELODY         7
#ifndef CATEGORY144_FMGR_PREVIEW
#define CATEGORY144_FMGR_PREVIEW    0x1000
#endif 
#define CATEGORY144_DISABLE_PREVIEW 0x0100
#define CATEGORY144_EMAIL_PREVIEW       0x0010
#ifdef __MMI_MESSAGES_EMS__
    extern EMSTATUS EMS_load_object(U32 type, U8 *data, S32 index, EMSObjData *object);
#endif 
    extern EMSTATUS EMS_inputbox_insert_predefined_picture(S32 index);
    extern EMSTATUS EMS_inputbox_insert_userdefined_picture(U8 *data);
    extern EMSTATUS EMS_inputbox_insert_predefined_animation(S32 index);
    extern EMSTATUS EMS_inputbox_insert_userdefined_animation(U8 *data);
    extern EMSTATUS EMS_inputbox_insert_predefined_sound(S32 index);
    extern EMSTATUS EMS_inputbox_insert_predefined_melody(S32 index);
    extern EMSTATUS EMS_inputbox_insert_userdefined_melody(U8 *data);

    extern void EMS_load_predefined_picture(S32 index, U8 *data);
    extern S32 EMS_get_predefined_picture_size(S32 index);
    extern S32 EMS_get_predefined_picture_data_size(U8 *data);
    extern S32 EMS_get_userdefined_picture_size(U8 *data);
    extern S32 EMS_get_predefined_animation_size(S32 index);
    extern S32 EMS_get_userdefined_animation_size(U8 *data);
    extern S32 EMS_get_predefined_sound_size(S32 index);
    extern void EMS_load_predefined_melody(S32 index, U8 *data);
    extern S32 EMS_get_predefined_melody_size(S32 index);
    extern S32 EMS_get_predefined_melody_data_size(U8 *data);
    extern S32 EMS_get_userdefined_melody_size(U8 *data);

    extern S32 EMS_check_userdefined_picture_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_predefined_picture_data_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_userdefined_animation_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_predefined_melody_data_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_userdefined_melody_size(U8 *data, U8 *allowed);

    extern void EMS_userdefined_melody_attach_header(U8 *src, U8 *dst, S32 *size);
    extern void EMS_userdefined_melody_detach_header(U8 *src, U8 *dst, S32 *size);
    extern void EMS_predefined_melody_attach_header(U8 *src, U8 *dst, S32 *size);
    extern void EMS_predefined_melody_detach_header(U8 *src, U8 *dst, S32 *size);

    extern void EMS_inputbox_set_text_size(EMSFONTSIZE s);
    extern EMSFONTSIZE EMS_inputbox_get_text_size(void);
    extern void EMS_inputbox_set_text_style(U8 isBold, U8 isItalic, U8 isUnderline, U8 isStrikethrough);
    extern void EMS_inputbox_get_text_style(U8 *isBold, U8 *isItalic, U8 *isUnderline, U8 *isStrikethrough);
    extern EMSTATUS EMS_inputbox_set_text_alignment(EMSALIGNMENT a);
    extern EMSALIGNMENT EMS_inputbox_get_text_alignment(void);
    extern EMSTATUS EMS_inputbox_create_new_paragraph(EMSALIGNMENT a);
    extern void EMS_inputbox_backspace(void);
    extern	void EMS_inputbox_delete_all(void);
    extern U8 test_EMS_inputbox_change_mode(void);
    extern void initialize_EMS_objects(void);
    extern void register_EMS_inputbox_keys(void);
    extern void close_EMS_objects(void);
    extern void reset_EMS_inputbox(void);
    extern void register_EMS_inputbox_viewer_keys(void);
    extern	void create_EMS_viewer_header(U8 *message);
    extern void EMS_viewer_show_header(S32 x1, S32 y1, S32 x2, S32 y2);
    extern	S32 EMS_viewer_measure_header(void);
    extern void EMS_inputbox_handle_key_down(MMI_key_code_type k);
    extern void wgui_set_EMS_inputbox_RSK(void);
    extern void wgui_inputs_EMS_disable(void);
    extern void wgui_inputs_EMS_enable(void);
    extern S32 wgui_inputs_EMS_is_area_visible(S32 x, S32 y, S32 width, S32 height, S32 gap);

#ifdef __OP01_FWPBW__
    extern void wgui_set_EMS_inputbox_RSK_no_show_counter(void);
#endif

#ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
    extern void wgui_inputs_EMS_set_hilite_list(
                    EMS_HILITE *hilite_list,
                    U16 number_of_list,
                    U16 curr_hilite_idx,
                    void (*hilite_cb)(S32 idx),
                    void (*click_cb)(S32 idx));
    extern void wgui_inputs_EMS_reset_hilite_list(void);
    extern void wgui_inputs_EMS_set_hilite_info(void);
#endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */

#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    extern void ShowCategory28Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSData *data,
                    U8 *history_buffer);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

    extern void ExitCategory28Screen(void);
    extern S32 GetCategory28HistorySize(void);
    extern U8 *GetCategory28History(U8 *history_buffer);
    extern void CloseCategory28Screen(void);
    void SetCategory28RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    extern U8 AppendCategory28String(U32 input_type, EMSData *data, U8 *s, U8 *history_buffer);
    extern U8 AppendEMSString(U32 input_type, EMSData *data, U8 *s, U8 dcs, U8 *history_buffer);
    extern MMI_BOOL EMS_inputbox_direct_input(UI_character_type c);
    extern MMI_BOOL EMS_inputbox_direct_input_no_draw(UI_character_type c);
    extern void redraw_EMS_inputbox(void);
    extern void EMS_inputbox_next_line(void);

    extern U32 wgui_inputs_ems_insert_string(UI_string_type str, U32 len, MMI_BOOL is_redraw);
    extern S32 EMS_inputbox_multitap_input_string(PU8 str);
    extern void EMS_inputbox_insert_new_line(void);
    extern void EMS_inputbox_previous(void);
    extern void EMS_inputbox_next(void);
    extern void EMS_inputbox_backspace_no_draw(void);
    extern void EMS_inputbox_previous_line(void);
    extern void RedrawCategory29Screen(void);
    extern void ShowCategory29Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSData *data,
                    U8 *history_buffer);
    extern void ExitCategory29Screen(void);
    extern S32 GetCategory29HistorySize(void);
    extern U8 *GetCategory29History(U8 *history_buffer);
    extern void CloseCategory29Screen(void);

    extern void RedrawCategory39Screen(void);
    extern void ShowCategory39Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSData *data,
                    U8 *header,
                    U8 *history_buffer);
    extern void ExitCategory39Screen(void);
    extern S32 GetCategory39HistorySize(void);
    extern U8 *GetCategory39History(U8 *history_buffer);
    extern void CloseCategory39Screen(void);

	typedef struct _EMS_inputbox_category_history
	{
		U16 history_ID;
		S16 cursor_ax, cursor_ay;
		S16 cursor_line_height;
		S16 display_y;
        S32 active_multitap;
		S16 UCS2_count;
		S16 text_offset;
		S16 input_mode_text_offset;
        S16 input_mode_start_text_offset;
        mmi_imc_history ime_history;
    #ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
        S32	current_hilite_idx;
    #endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */
	} EMS_inputbox_category_history;


    typedef struct
    {
        const U8 *data;
        kal_uint32 len;
    } ems_resource_struct;

    extern void move_EMS_inputbox(S32 x, S32 y);
    extern void resize_EMS_inputbox(S32 width, S32 height);

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    /* cat28 recipients flag */
    #define WGUI_CAT28_DEFAULT_FLAGS                          (0x00000000)
    #define WGUI_CAT28_HIGHLIGHT_RECIPIENT                    (0x00000001)
    #define WGUI_CAT28_WRAPPING_DELETE_RECIPIENT              (0x00000002)
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

    extern void wgui_EMS_set_text_format(EMSTextFormat text_format);
    extern void wgui_inputs_EMS_handle_right_softkey_repeat(void);
    extern void wgui_inputs_EMS_handle_right_softkey_touch_repeat(void);

    extern void wgui_inputs_EMS_disalbe_show(MMI_BOOL b_disable);

    typedef MMI_BOOL (*wgui_inputs_ems_key_hdlr) (S16 keyCode);

#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    /* highlight handler */
    typedef void (*wgui_cat28_highlight_handler) (S32 pre_hilite_index, S32 cur_hilite_index, MMI_BOOL is_pre_text_changed);
    typedef void (*wgui_cat28_remove_recipient_handler) (S32 recipient_index);
    typedef void (*wgui_cat28_add_recipient_handler) (S32 recipient_index);
    typedef void (*wgui_cat28_recipient_changed_handler) (S32 recipient_index);

#if defined(__MMI_MAINLCD_128X128__)
    #define WGUI_CAT28_INLINE_SL_HEIGHT                (27)
#elif defined(__MMI_MAINLCD_128X160__)
    #define WGUI_CAT28_INLINE_SL_HEIGHT                (27)
#elif defined(__MMI_MAINLCD_320X480__)
    #define WGUI_CAT28_INLINE_SL_HEIGHT                (35)
#else /* 176x220, 240x320, 320x240, 240x400 */ 
    #define WGUI_CAT28_INLINE_SL_HEIGHT                (35)
#endif

    #define WGUI_CAT28_INLINE_SL_TEXT_DEFAULT_HEIGHT   ((WGUI_CAT28_INLINE_SL_HEIGHT >> 1) + (WGUI_CAT28_INLINE_SL_HEIGHT >> 2))
    #define WGUI_CAT28_RECIPIENTS_MAX_CHAR_COUNT       (13)
    #define WGUI_CAT28_RECIPIENTS_MAX_NUM              (20)
    #define WGUI_CAT28_HEADER_GAP_Y                    (2)
    #define WGUI_CAT28_HEADER_GAP_X                    (4)

    #define WGUI_CAT28_PEN_ON_EMPTY                    (-1)
    #define WGUI_CAT28_PEN_ON_LABEL                    (-2)
    #define WGUI_CAT28_PEN_ON_TEXT                     (-3)


    typedef enum
    {
        WGUI_CAT28_RECIPIENTS,
        WGUI_CAT28_EDITOR,    
        WGUI_CAT28_TOTAL
    } wgui_cat28_region_id_enum;
    
    /* EMS recipients info structure */
    typedef struct
    {
        MMI_BOOL is_valid;                   /* only valid recipient will be displayed */
        UI_buffer_type input_buf;            /* name buffer */
        U32 editor_flags;                    /* editor flags */
    } wgui_cat28_recipients_struct;
    
    /* EMS recipients label structure */
    typedef struct
    {
        PU8 label_normal_image;               /* Label normal image */
        PU8 label_pressed_image;              /* Label pressed image */
        UI_buffer_type label_string;             /* Label string */
        FuncPtr label_callback;                 /* Label callback function */
    } wgui_cat28_recipients_label_struct;
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    typedef struct
    {
        MMI_BOOL inline_recipients;
        wgui_cat28_recipients_label_struct recipients_label;
        S32 max_label_width;
        MMI_BOOL is_pressed_label;
        
        //wgui_cat28_recipients_struct recipient[WGUI_CAT28_RECIPIENTS_MAX_NUM];//replace with macro
        wgui_cat28_recipients_struct *recipient;
        S32 recipient_buffer_size;   /* buffer size for one recipient */
        U32 recipient_input_type;   /* input type */
        S32 max_recipients_num;
        
        U32 ml_input_type;
        U16 right_softkey;
        U16 right_softkey_icon;

        wgui_cat28_region_id_enum highlight_state;
        S32 highlight_index;
        UI_buffer_type sl_history;
            
        wgui_cat28_highlight_handler highlight_handler;
        wgui_cat28_remove_recipient_handler remove_recipient_handler;
        wgui_cat28_add_recipient_handler add_recipient_handler;
        wgui_cat28_recipient_changed_handler recipient_change_callback;

        MMI_BOOL need_to_set_sl_ime;
        mmi_imc_history sl_ime;
        MMI_BOOL need_to_set_ml_ime;
        mmi_imc_history ml_ime;
        MMI_BOOL is_insert_semicolon;
        U16 current_inputs;
    } wgui_cat28_context_struct;
    /* DOM-NOT_FOR_SDK-END */

    extern void ShowCategory28Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                EMSData *data,
                U8 *history_buffer);

    /* initialize recipients */
    extern void wgui_cat28_initialize_recipients(
            wgui_cat28_recipients_struct recipient[],
            S32 max_recipients_num,
            S32 buffer_size,
            U32 input_type,
            wgui_cat28_recipients_label_struct *label,
            wgui_cat28_region_id_enum highlight_state,
            wgui_cat28_highlight_handler highlight_handler,
            wgui_cat28_add_recipient_handler add_recipient_handler,
            wgui_cat28_remove_recipient_handler remove_recipient_handler);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat28_get_highlight_state
 * DESCRIPTION
 *  get current highlight state.
 * PARAMETERS
 *  region_id             [OUT]   the highlighted region id.
 *  recipient_index       [OUT]   the recipient index, if highlighted is not no recipinets area, return -1.
 * RETURNS
 *  void
 *****************************************************************************/
    extern void wgui_cat28_get_highlight_state(wgui_cat28_region_id_enum *region_id, S32 *recipient_index);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat28_get_recipients_num
 * DESCRIPTION
 *  get the recipients number.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32   return the recipients number.
 *****************************************************************************/
     extern S32 wgui_cat28_get_recipients_num(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat28_set_highlight_state_and_index
 * DESCRIPTION
 *  set highlight state and index.
 * PARAMETERS
 *  state   [IN]  highlight state
 *  index   [IN]  highlight index
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat28_set_highlight_state_and_index(wgui_cat28_region_id_enum state, S32 index);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat28_register_recipient_change_callback
 * DESCRIPTION
 *  If single line editor text changed, we will callback to app if necessary.
 * PARAMETERS
 *  func:           [IN] (N/A) the change callback function.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat28_register_recipient_change_callback(wgui_cat28_recipient_changed_handler func);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat28_highlight_to_content
 * DESCRIPTION
 *  adjust the highlight in background.
 * PARAMETERS
 *  history_buffer      [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat28_highlight_to_content(U8 *history_buffer);

    /* add a new recipient */
    extern MMI_BOOL wgui_cat28_insert_new_recipient(S32 index, UI_buffer_type new_recipient, U32 editor_flags, MMI_BOOL need_to_highlight);
    extern MMI_BOOL wgui_cat28_add_new_recipient(UI_buffer_type new_recipient, U32 editor_flags, MMI_BOOL need_to_highlight);
    extern MMI_BOOL wgui_cat28_set_phb_recipient(S32 buffer_index, U32 editor_flags, UI_buffer_type phb_recipient_name);

    /* remove recipient */
    extern MMI_BOOL wgui_cat28_remove_recipient(S32 index);

#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_EMS_move_cursor
 * DESCRIPTION
 *  Move the EMS editor cursor
 * PARAMETERS
 *  pos             [IN]                              cursor position
 *                  WGUI_INPUTS_CURSOR_POS_START   start position
 *                  WGUI_INPUTS_CURSOR_POS_END     end position
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_EMS_move_cursor(wgui_inputs_cursor_pos_enum pos);

/*****************************************************************************
* FUNCTION
*  wgui_inputs_ems_register_pre_key_handler
* DESCRIPTION
*  Register EMS inputbox pre key handler
* PARAMETERS
*  wgui_inputs_ems_key_hdlr     [IN]       pre key handler   
* RETURNS
*  void
*****************************************************************************/
extern void wgui_inputs_ems_register_pre_key_handler(wgui_inputs_ems_key_hdlr f);

/*****************************************************************************
 * FUNCTION
 *  wgui_inputs_ems_register_set_key_callback
 * DESCRIPTION
 *  Set key handler for App in editor screen
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inputs_ems_register_set_key_callback(void (*f) (void));

#ifdef __cplusplus
}
#endif 

#endif /* __WGUI_EMS_H__ */ 
#endif /* UI_EMS_SUPPORT */


