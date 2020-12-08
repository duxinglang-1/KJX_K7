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
 *  FSEditorCuiGprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_FSEDITORCUIGPROT_H
#define MMI_FSEDITORCUIGPROT_H

#ifdef __cplusplus
extern "C"{
#endif 

//#include "MMI_include.h"

    #include "mmi_res_range_def.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "ImeGprot.h"
    #include "gui_data_types.h"
    #include "gui_typedef.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
*  Define
*****************************************************************************/
#define     STR_ID_CUI_FSEDITOR_DEFAULT             0xFFFF
#define     IMG_ID_CUI_FSEDITOR_DEFAULT             0xFFFF

/* This API will be removed */
#define cui_fseditor_set_buffer(GID, BUFFER, B_SIZE, EDIT_LEN) cui_fseditor_set_text(GID, (WCHAR*)BUFFER, B_SIZE, EDIT_LEN)

/***************************************************************************** 
*  Typedef 
*****************************************************************************/

/* FSEditor event id */
typedef enum
{
    /* when user finish edit (Select Done in Options or Press LSK (Ok)) */
    EVT_ID_CUI_FSEDITOR_SUBMIT = (EDITOR_BASE + 1),
    
    /* Spelling mistake, reserve for App usage */
    EVT_ID_CUI_FSEDITOR_SUBMMIT = EVT_ID_CUI_FSEDITOR_SUBMIT,

    /* when user cancel edit (Select Cancel in Options or Press RSK (Back)) */
    EVT_ID_CUI_FSEDITOR_ABORT,

    /* when edit content change to empty */
    EVT_ID_CUI_FSEDITOR_EMPTY,

    /* when edit content change to not empty */
    EVT_ID_CUI_FSEDITOR_NOT_EMPTY,

    /* when edit content changes (delete/insert characters) */
    EVT_ID_CUI_FSEDITOR_CHANGED,

    /* When entry editor screen or editor content changes, used for Apps need to know the editor content/length
       It is the same as RegisterInputBoxValidationFunction */
    EVT_ID_CUI_FSEDITOR_VALIDATION,

    /* when need to set special key handler when show edit CUI */
    EVT_ID_CUI_FSEDITOR_SET_KEY,

    /* Before a char to be insert, used for App need to decide if the character can be insert or not */
    EVT_ID_CUI_FSEDITOR_INSERT_CHAR,

    /* Before a char to be delete, used for App need to decide if the character can be delete or not */
    EVT_ID_CUI_FSEDITOR_DELETE_CHAR,

    /* when input method changes */
    EVT_ID_CUI_FSEDITOR_INPUT_METHOD_CHANGE,

    /* when App custom menu item selected */
    EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED,

    /* when user customize CSK behaivor and csk is pressed */
    EVT_ID_CUI_FSEDITOR_CSK_PRESSED,

    /* The editor CUI group deinited*/
    EVT_ID_CUI_FSEDITOR_DEINIT,

    EVT_ID_CUI_FSEDITOR_MAX
} cui_fseditor_evt_enum;


/* FSEditor basic event structure, used by following event
   1) EVT_ID_CUI_FSEDITOR_SUBMMIT
   2) EVT_ID_CUI_FSEDITOR_ABORT 
   3) EVT_ID_CUI_FSEDITOR_EMPTY 
   4) EVT_ID_CUI_FSEDITOR_NOT_EMPTY
   5) EVT_ID_CUI_FSEDITOR_SET_KEY
   6) EVT_ID_CUI_FSEDITOR_CSK_PRESSED */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER         /* evt_id: event is; user_data: the receiver's user_data */
    /* DOM-NOT_FOR_SDK-END */
} cui_fseditor_evt_struct; 


/* Edit(Insert/delete) event structure, used by following event:
   1) EVT_ID_CUI_FSEDITOR_INSERT_CHAR
   2) EVT_ID_CUI_FSEDITOR_DELETE_CHAR */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER         /* evt_id: event is; user_data: the receiver's user_data */
    /* DOM-NOT_FOR_SDK-END */
    U16 c;                       /* character to be inserted or deleted */
} cui_fseditor_edit_evt_struct;


/* custom menu selected event structure, used by following event:
   1) EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER         /* evt_id: event is; user_data: the receiver's user_data */
    /* DOM-NOT_FOR_SDK-END */
    U16 menu_id;                 /* selected app's custom menu id */
} cui_fseditor_custom_menu_select_evt_struct;


/* Editor content changed event structure, used by following event:
   1) EVT_ID_CUI_FSEDITOR_CHANGED */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER        /* evt_id: event is; user_data: the receiver's user_data */
    /* DOM-NOT_FOR_SDK-END */
    PU8 text;                   /* Editor text buffer pointer */
    PU8 cursor_position;        /* Editor Cursor position */
    U16 text_length;            /* Editor text length */
} cui_fseditor_change_evt_struct; 


/* Editor input method changed event structure, used by following event:
   1) EVT_ID_CUI_FSEDITOR_INPUT_METHOD_CHANGE */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER       /* evt_id: event is; user_data: the receiver's user_data */
    /* DOM-NOT_FOR_SDK-END */
    U16 input_method;          /* new changed input method */
} cui_fseditor_input_method_change_evt_struct; 

typedef struct
{
    U16 title;                /* title label */
    U16 title_icon;           /* title icon */
    WCHAR *title_string;         /* title string */
    WCHAR *buffer;               /* buffer for editor */
    S32 buffer_size;          /* buffer size */
    S32 edit_length;          /* Edit limit length */
    U32 parent_data;              /* parent data */
    U32 input_type;           /* input type */
    mmi_imm_input_mode_enum *required_input_mode_set; /* input mode set */
    S16 input_ext_type;       /* extended input type */
    U16 lsk_label;
    U16 lsk_icon;
    U16 rsk_label;
    U16 rsk_icon;
    U16 csk_label;
    U16 csk_icon;
    U16 options_done_label;       /* Done label in Option menu */
    U16 options_cancel_label;     /* Cancel label in Option menu */
    PU16 options_cust_menu_list;  /* App customized menu item */
    U8  options_cust_menu_count;  /* App customized menu item count */
    UI_character_type *set_characters_list;
    MMI_BOOL set_characters_flag;
    MMI_BOOL disable_def_opt_menu_flag; /* Disable default option menu (Done/Cancel) or not */
} cui_fseditor_property_struct, *cui_fseditor_property_struct_p; 

/***************************************************************************** 
*  Extern Variables
*****************************************************************************/


/***************************************************************************** 
*  Global Variables
*****************************************************************************/


/*****************************************************************************  
*  Local Variables 
*****************************************************************************/


/*****************************************************************************  
*   Extern Functions 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_create
 * DESCRIPTION
 *  Create fsedtior CUI.
 *  WARNING: if max fseditor CUI instance number has reached, it will fail to 
 *           create CUI and return GRP_ID_INVALID.
 * PARAMETERS
 *  parent_gid     : [IN]        App's Group ID
 * RETURNS
 *  FSeditor CUI group ID
 *****************************************************************************/
extern mmi_id cui_fseditor_create(mmi_id parent_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_run
 * DESCRIPTION
 *  FSeditor CUI run function. It will entry FSEditor screen after called it
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_run(mmi_id fseditor_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_close
 * DESCRIPTION
 *  FSEditor CUI close function. It will delete ALL Editor CUI's screen by calling it
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_close(mmi_id fseditor_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title
 * DESCRIPTION
 *  Set editor title by text resource ID and icon resource ID.
 *  In most case, App should use string/icon ID to set title because Editor CUI
 *  will not keep a copy of title string/icon
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 *  label              : [IN]        title text ID
 *  icon               : [IN]        title icon ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_title(mmi_id fseditor_gid, U16 label, U16 icon);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title_string
 * DESCRIPTION
 *  Set editor title text by string.
 *  For some special app which need to set title by dynamically generate string.
 *  App should use static/global string for this string, User should be responsible for
 *  it's life cycle. Editor CUI will not keep a copy of this string
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 *  label              : [IN]        title text string
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_title_string(mmi_id fseditor_gid, const WCHAR *label);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title_icon
 * DESCRIPTION
 *  Set editor title icon ID. It can be used with cui_fseditor_set_title_string
 *  to set a title with string pointer and icon ID
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 *  icon               : [IN]        title icon ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_title_icon(mmi_id fseditor_gid, U16 icon);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_input_method
 * DESCRIPTION
 *  Set editor input method
 *  NOTE: It should be called only before Editor CUI run, otherwise the default input
 *        method will be used.
 *  The required_input_mode_set is a input mode array ended by IMM_INPUT_MODE_NONE
 *  It should be static/global array and Editor CUI will not keep a copy of it. App should
 *  be responsible for its life cycle
 *  For example:
 *        mmi_imm_input_mode_enum g_ctm_required_input_modes[] = {
 *            IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
 *            IMM_INPUT_MODE_123_SYMBOLS,
 *            IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
 *            IMM_INPUT_MODE_NONE};
 * For more information about input_type and input_ext_type, please refer to ImeGprot.h
 * PARAMETERS
 *  fseditor_gid               : [IN]        FSEditor CUI Group ID
 *  input_type                 : [IN]        Input type
 *  required_input_mode_set    : [IN]        App specific input mode list
 *  input_ext_type             : [IN]        Input extention type
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_input_method(
                mmi_id fseditor_gid,
                U32 input_type,
                const mmi_imm_input_mode_enum *required_input_mode_set,
                S16 input_ext_type);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_text
 * DESCRIPTION
 *  Set FSEditor CUI buffer. It can be call before/after CUI run.
 *  [USAGE]:
 *    1. If edit buffer is smaller than CUI_FSEDITOR_MAX_BUFFER_SIZE, Editor CUI will use internal memory for editing
 *       1) If App pass NULL for buffer, Editor will use internal text buffer for edit and initialize it as empty text
 *       2) If App pass local text buffer, Editor will use internal text buffer for edit and copy the local text.
 *    2. If edit buffer is large than CUI_FSEDITOR_MAX_BUFFER_SIZE, App must pass the global/static memory for editing.
 *  [NOTE]: 
 *    1. When finish editing, App must call cui_fseditor_get_text to get text, no matter use app's buffer or editor CUI's buffer.
 *    2. If App call this function after CUI run, 
 *       1) If current screen is editor screen, It will refresh editor content by re entry editor screen
 *       2) If editor screen is in history, it won't refresh editor screen. And only set history buffer
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  buffer              [IN]        Editor Buffer
 *  buffer_size         [IN]        Editor buffer size in Bytes, including NULL terminal char
 *  edit_length         [IN]        Editor editable text length in character count, not including NULL terminal
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_text(mmi_id fseditor_gid, WCHAR *buffer, S32 buffer_size, S32 edit_length);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_text
 * DESCRIPTION
 *  Copy the edit text from FSEDITOR CUI to APP's buffer. 
 *  [NOTE]:
 *    1. After finish edit, App MUST call this API to get text, no matter use app's buffer or editor CUI's buffer
 *    2. App should guarantee the buffer_size of dest buffer is large enough to copy, if the editor text length is
 *       bigger than the buffer size, edit text will be truncated for app's buffer_size.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  buffer              [OUT]        Buffer to copy edit content
 *  buffer_size         [IN]         buffer size to copy the edit content
 * RETURNS
 *  S32  real text length (character count) in editor buffer
 *****************************************************************************/
extern S32 cui_fseditor_get_text(mmi_id fseditor_gid, WCHAR *buffer, S32 buffer_size);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_text_len
 * DESCRIPTION
 *  Get the real text length (character count) of editor after editing.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 * RETURNS
 *  S32    text length (character count) of editor buffer
 *****************************************************************************/
extern S32 cui_fseditor_get_text_len(mmi_id fseditor_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_softkey_text
 * DESCRIPTION
 *  Set Editor softykey text.
 *  NOTE: It call be call before/after editor CUI run.
 *        If CUI is running and current screen is editor screen, it will redraw softkey
 *        Otherwise, it only update softkey variables.
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 *  key_type           : [IN]        softkey type:
                                    MMI_LEFT_SOFTKEY   -> LSK
                                    MMI_RIGHT_SOFTKEY  -> RSK
                                    MMI_CENTER_SOFTKEY -> CSK
 *  text               : [IN]        softkey text
                                    Use STR_ID_CUI_FSEDITOR_DEFAULT set to default value
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_softkey_text(mmi_id fseditor_gid, WGUI_SOFTKEY_ENUM key_type, U16 text);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_softkey_icon
 * DESCRIPTION
 *  Set Editor softykey icon.
 *  NOTE: It call be call before/after editor CUI run.
 *        If CUI is running and current screen is editor screen, it will redraw softkey
 *        Otherwise, it only update softkey variables.
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 *  key_type           : [IN]        softkey type
                                    MMI_LEFT_SOFTKEY   -> LSK
                                    MMI_RIGHT_SOFTKEY  -> RSK
                                    MMI_CENTER_SOFTKEY -> CSK
 *  text               : [IN]        softkey icon
                                    Use IMG_ID_CUI_FSEDITOR_DEFAULT: set to default value 
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_softkey_icon(mmi_id fseditor_gid, WGUI_SOFTKEY_ENUM key_type, U16 icon);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_characters_filter
 * DESCRIPTION
 *  Set allowed/disallowed filter character list.
 *  App can specify which character can/can't be inserted to editor
 *  characters_list is a characters string array end by \0 and it
 *  should be static/global array and Editor CUI will not keep a copy of it.
 *  App should be responsible for its life cycle
 * PARAMETERS
 *  fseditor_gid       : [IN]        FSEditor CUI Group ID
 *  is_allowed         : [IN]        MMI_TRUE: can be inserted, MMI_FALSE: Can't be inserted
 *  characters_list    : [IN]        Filter character list
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_characters_filter(mmi_id fseditor_gid, MMI_BOOL is_allowed, const UI_character_type *characters_list);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_default_options_menu
 * DESCRIPTION
 *  Set default editor options menu item (Done/Cancel)
 *  App can use this API to change the Done/Cancel item to any other text
 *  NOTE: Editor will always send Submit event for Done, Abort event for Cancel menu item even if App
 *        has change its text.
 * PARAMETERS
 *  fseditor_gid               : [IN]        FSEditor CUI Group ID
 *  options_done_label         : [IN]        Editor Options done menu item label, use STR_ID_CUI_FSEDITOR_DEFAULT set to default value
 *  options_cancel_label       : [IN]        Editor Options cancel menu item label, use STR_ID_CUI_FSEDITOR_DEFAULT set to default value
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_default_options_menu(mmi_id fseditor_gid, U16 options_done_label, U16 options_cancel_label);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_custom_options_menu
 * DESCRIPTION
 *  Set App custom options menu list. Custom options menu item will be add after Default menu item (Done/Cancel)
 *  Editor CUI will send EVT_ID_CUI_FSEDITOR_CUSTOM_MENU_SELECTED event to APP when custom options menu selected.
 * PARAMETERS
 *  fseditor_gid               : [IN]        FSEditor CUI Group ID
 *  is_diable_defaut_menu      : [IN]        If disable default menu item (Done) or not
 *  menu_list                  : [IN]        Custom options menu ID list
 *  count                      : [IN]        Custom options menu count
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_custom_options_menu(mmi_id fseditor_gid, MMI_BOOL is_diable_defaut_menu, PU16 menu_list, U8 count);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_disable_cancel_options_item
 * DESCRIPTION
 *  Disable Cancel option item or item
 * PARAMETERS
 *  fseditor_gid                [IN]        FSEditor CUI Group ID
 *  is_diable                   [IN]        If disable Cancel) or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_disable_cancel_options_item(mmi_id fseditor_gid, MMI_BOOL is_disable);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_property
 * DESCRIPTION
 *  Set fseditor CUI property. Set all fseditor CUI property at once. App need to create a fseditor property instance
 *  and set the specify value. Example:
 * <code>
    cui_fseditor_property_struct fseditor_property;
    mmi_id fseditor = cui_fseditor_create(my_id);

    CUI_FSEDITOR_STRUCT_INIT(&fseditor_property);
    fseditor_property.buffer = g_buffer;
    fseditor_property.buffer_size = MMI_APP_EDITOR_BUFFER_SIZE;
    fseditor_property.edit_length = MMI_APP_EDITOR_LENGTH;
    fseditor_property.input_type = IMM_INPUT_MODE_123;
    fseditor_property.title = STR_APP_TITLE;
    fseditor_property.title_icon = IMG_APP_ICON;
    cui_fseditor_set_property(fseditor, &fseditor_property);
  * </code>  
 * PARAMETERS
 *  fseditor_gid                [IN]        FSEditor CUI Group ID
 *  s                           [IN]        FSeditor CUI structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_property(mmi_id fseditor_gid, cui_fseditor_property_struct_p s);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_parent_data
 * DESCRIPTION
 *  Set parent data. App can set parent data and retrieve it by cui_fseditor_get_parent_data
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  parent_data         [IN]        Parent data
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_parent_data(mmi_id fseditor_gid, U32 parent_data);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_parent_data
 * DESCRIPTION
 *  Get parent data. App can set parent data by cui_fseditor_set_parent_data
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 cui_fseditor_get_parent_data(mmi_id fseditor_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_append_text
 * DESCRIPTION
 *  Append text to the end of editor CUI buffer
 * PARAMETERS
 *  fseditor_gid        [IN]        FSEditor CUI Group ID
 *  text                [IN]        text
 * RETURNS
 *  U32
 *****************************************************************************/
extern void cui_fseditor_append_text(mmi_id fseditor_gid, WCHAR *text);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_title_in_header
 * DESCRIPTION
 *  Set title in editor header area. For Landscape screen, there is no title in editor
 *  screen, if App want to display information on title, can set this flag.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  title_in_header     [IN]         title in header or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_title_in_header(mmi_id fseditor_gid, MMI_BOOL title_in_header);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_cursor_first_pos
 * DESCRIPTION
 *  Set cursor position to the beginning of whole text.
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  is_first_pos        [IN]         is cursor at first pos
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_cursor_first_pos(mmi_id fseditor_gid, MMI_BOOL is_first_pos);


/*****************************************************************************
 * FUNCTION
 *  CUI_FSEDITOR_STRUCT_INIT
 * DESCRIPTION
 *  Initialize editor CUI structure.
 * PARAMETERS
 *  _editor :             [IN]    editor structure pointer;
 * RETURNS
 *  void
 *****************************************************************************/
#define CUI_FSEDITOR_STRUCT_INIT(_editor)  \
        do {    \
            memset((_editor), 0, sizeof(*(_editor)));   \
        } while(0)

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_auto_display_remaining_counter
 * DESCRIPTION
 *  set auto display editor counter (Only show the counter when reach certain length)
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_auto_display_remaining_counter(mmi_id fseditor_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_clear_key_delete_all_mode
 * DESCRIPTION
 *  Set clear key delete all mode. 
 *  By default the clear key long press will fast delete character by character
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_clear_key_delete_all_mode(mmi_id fseditor_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_is_disable_ncenter
 * DESCRIPTION
 *  set disable ncenter or not
 * PARAMETERS
 *  fseditor_gid        [IN]         FSEditor CUI Group ID
 *  value               [IN]         disable or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_fseditor_set_is_disable_ncenter(mmi_id fseditor_gid, MMI_BOOL value);

/* DOM-NOT_FOR_SDK-END */
        

/*****************************************************************************  
*   Local Functions  
*****************************************************************************/


#endif /* MMI_FSEDITORCUIGPROT_H */
