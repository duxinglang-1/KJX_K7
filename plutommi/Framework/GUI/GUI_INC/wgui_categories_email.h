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
 *  wgui_categories_email.h
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef WGUI_CATEGORIES_EMAIL_H
#define  WGUI_CATEGORIES_EMAIL_H

/*RHR*/
    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "gui_typedef.h"
    #include "kal_general_types.h"
/*RHR end*/

typedef enum{
    CAT261_DISPLAY_THREE_LINE = 0,
    CAT261_DISPLAY_TWO_LINE,
    CAT261_DISPLAY_MAX
}MMI_CAT261_DISPLAY_STYLE;
#define MMI_CAT261_DISPLAY_THREE_LINE       CAT261_DISPLAY_THREE_LINE
#define MMI_CAT261_DISPLAY_TWO_LINE         CAT261_DISPLAY_TWO_LINE

typedef enum{
    CAT263_DISPLAY_DEFAULT = 0,
    CAT263_DISPLAY_ALL,
    CAT263_DISPLAY_TIME_SUBJECT,
    CAT263_DISPLAY_TIME_SENDER,
    CAT263_DISPLAY_SUBJECT_TIME,
    CAT263_DISPLAY_SUBJECT_SENDER,
    CAT263_DISPLAY_SENDER_TIME,
    CAT263_DISPLAY_SENDER_SUBJECT,
    CAT263_FLAG_MAX
}MMI_CAT263_DISPLAY_STYLE;

#define MMI_CAT263_DISPLAY_NONE             CAT263_DISPLAY_DEFAULT        /* display as before */
#define MMI_CAT263_DISPLAY_ALL              CAT263_DISPLAY_ALL            /* display two line with three text items */
#define MMI_CAT263_DISPLAY_TIME_SUBJECT     CAT263_DISPLAY_TIME_SUBJECT   /* display two line with time and subject */
#define MMI_CAT263_DISPLAY_TIME_SENDER      CAT263_DISPLAY_TIME_SENDER    /* display two line with time and sender */
#define MMI_CAT263_DISPLAY_SUBJECT_TIME     CAT263_DISPLAY_SUBJECT_TIME   /* display two line with subject and time */
#define MMI_CAT263_DISPLAY_SUBJECT_SENDER   CAT263_DISPLAY_SUBJECT_SENDER /* display two line with subject and sender */
#define MMI_CAT263_DISPLAY_SENDER_TIME      CAT263_DISPLAY_SENDER_TIME    /* display two line with sender and time */
#define MMI_CAT263_DISPLAY_SENDER_SUBJECT   CAT263_DISPLAY_SENDER_SUBJECT /* display two line with sender and subject */

/********** EMAIL SCREEN START **********/
extern void ShowCategory251Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U16 *list_of_icons1,
                U16 *list_of_icons2,
                S32 highlighted_item,
                U8 *history_buffer,
                U8 screen_look);
extern void DrawCategory251InfoBox(U8 *, U8 *);
extern void RedrawCategory251InfoBox(U8 *, U8 *);

extern void ShowCategory252Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U16 *list_of_icons1,
                S32 highlighted_item,
                U8 *history_buffer,
                U8 screen_look);
extern void DrawCategory252InfoBox(U16, U8 *, U8 *);
extern void RedrawCategory252InfoBox(U16, U8 *, U8 *);

extern void ShowCategory253Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U8 **list_of_items2,
                U16 *list_of_icons1,
                U16 *list_of_icons2,
                U16 *list_of_icons3,
                U16 *list_of_icons4,
                U8 *n_of_icons2,
                S32 highlighted_item,
                U8 *history_buffer);

extern UI_string_type get_asyncdynamic_item_text(S32 index);
extern void asyncdynamic_list_highlight_handler(S32 item_index);
extern void set_asyncdynamic_pop_up_descriptions(S32 highlighted_item);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory261Screen
 * DESCRIPTION
 *  Show category 261
 * 
 * <img name="wgui_cat261_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon ID
 *   left_softkey                  : [IN ] (LSK) Left softkey string ID
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon ID
 *   right_softkey                 : [IN ] (RSK) Right softkey string ID
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon ID
 *   number_of_items               : [IN ] (N/A) Number of items to be displayed
 *   get_item_func                 : [IN ] (C261_1,C261_2) Function pointer to get next displayed items
 *   get_hint_func                 : [IN ] (HINT) Function pointer to get next displayed hint data
 *   highlighted_item              : [IN ] (N/A) Index of item to be highlighted
 *   list_icon                     : [IN ] (N/A) Icon of list
 *   attach_icon                   : [IN ] (N/A) Attach icon
 *   history_buffer                : [IN ] (N/A) History buffer
 *   no_of_string                  : [IN ] (N/A) string count
 *   no_of_icons                   : [IN ] (N/A) icon count
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_261(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     S32 error;
 * 
 *     if (mmi_frm_scrn_enter(
 *         GRP_ID_CSB_ROOT, SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, MMI_FRM_UNKNOW_SCRN))
 *     {
 * 
 *         ShowCategory261Screen(
 *             (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *             0,
 *             STR_ID_CSB_LSK_TEXT,
 *             0,
 *             STR_ID_CSB_RSK_TEXT,
 *             0,
 *             4,
 *             get261_async_items,
 *             NULL,
 *             0,
 *             IMG_GLOBAL_L1,
 *             IMG_HORIZONTAL_TAB_L_ARROW,
 *             guiBuffer,
 *             2,
 *             4,
 *            &error);
 * 
 *         csb_set_key_handlers();
 *     }
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory261Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U16 attach_icon,
                U8 *history_buffer,
                S32 no_of_string,
                S32 no_of_icons,
                S32 *category_error_flag);
extern void ExitCategory261Screen(void);
extern void wgui_cat261_set_display_style(S32 style);

extern void wgui_cat261_ext_show(
                 U8 *title,
                 U16 title_icon,
                 U16 left_softkey,
                 U16 left_softkey_icon,
                 U16 right_softkey,
                 U16 right_softkey_icon,
                 S32 number_of_items,
                 GetAsyncItemFuncPtr get_item_func,
                 GetAsyncHintFuncPtr get_hint_func,
                 S32 highlighted_item,
                 U16 list_icon,
                 U8 *history_buffer,
                 S32 *category_error_flag);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory262Screen
 * DESCRIPTION
 *  Displays the category262 screen
 *  This is the icon-text list category screen with description.
 *  This is the async dynamic list menu, and it is composed of icon, text and description.
 * 
 * <img name="wgui_cat262_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string 
 *   title_icon                    : [IN ] (N/A) Title icon ID
 *   left_softkey                  : [IN ] (LSK) Left softkey string ID
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon ID
 *   right_softkey                 : [IN ] (RSK) Right softkey string ID
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon ID
 *   number_of_items               : [IN ] (N/A) Number of items to be displayed
 *   get_item_func                 : [IN ] (ICONTEXT) Function pointer to get next displayed items
 *   get_hint_func                 : [IN ] (HINT) Function pointer to get next displayed hint data
 *   highlighted_item              : [IN ] (N/A) Index of item to be highlighted
 *   list_icon                     : [IN ] (N/A) Icon of list
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_262(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     S32 error;
 * 
 *     if (mmi_frm_scrn_enter(
 *         GRP_ID_CSB_ROOT, SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, MMI_FRM_UNKNOW_SCRN))
 *     {
 * 
 *         ShowCategory262Screen(
 *             (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *             0,
 *             STR_ID_CSB_LSK_TEXT,
 *             0,
 *             STR_ID_CSB_RSK_TEXT,
 *             0,
 *             3,
 *             get263_async_items,
 *             NULL,
 *             0,
 *             IMG_GLOBAL_L1,
 *             guiBuffer,
 *             &error);
 * 
 *         csb_set_key_handlers();
 *     }
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory262Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

extern void RedrawCategory263InfoBox(U8 *infoText1, U8 *infoText2);
extern void wgui_cat263_set_display_style(S32 flag);
extern void wgui_cat263_tab_show(
                WCHAR *title,
                PU8 title_icon,
                WCHAR *left_softkey,
                WCHAR *right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                S8 highlighted_tab,    
                PU8 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory263Screen
 * DESCRIPTION
 *  Show category 263
 * 
 * <img name="wgui_cat263_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon ID
 *   left_softkey                  : [IN ] (LSK) Left softkey string ID
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon ID
 *   right_softkey                 : [IN ] (RSK) Right softkey string ID
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon ID
 *   number_of_items               : [IN ] (N/A) Number of items to be displayed
 *   get_item_func                 : [IN ] (ICONTEXT) Function pointer to get next displayed items
 *   get_hint_func                 : [IN ] (HINT) Function pointer to get next displayed hint data
 *   highlighted_item              : [IN ] (N/A) Index of item to be highlighted
 *   list_icon                     : [IN ] (N/A) Icon of list
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_263(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     S32 error;
 * 
 *     if (mmi_frm_scrn_enter(
 *         GRP_ID_CSB_ROOT, SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, MMI_FRM_UNKNOW_SCRN))
 *     {
 * 
 *         mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category263");
 *         mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Info text");
 *         mmi_asc_to_ucs2((PS8) csb_empty_string, (PS8) "Folder \'Photos\' empty!hhhhhhh");
 * 
 *         wgui_cat_set_list_menu_empty_lable((UI_string_type)csb_empty_string);
 * 
 *         ShowCategory263Screen(
 *             (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *             0,
 *             STR_ID_CSB_LSK_TEXT,
 *             0,
 *             STR_ID_CSB_RSK_TEXT,
 *             0,
 *             5,
 *             get263_async_items,
 *             NULL,
 *             0,
 *             IMG_GLOBAL_L1,
 *             guiBuffer,
 *             &error);
 * 
 *         RedrawCategory263InfoBox(g_buffer, g_buffer1);
 * 
 *         csb_set_key_handlers();
 *     }
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory263Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

extern void ShowCategory263Screen_int(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

#define ShowCategory263Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)	\
	ShowCategory263Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)

extern void RedrawCategory267InfoBox(U8 *infoText1, U8 *infoText2);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat267_tab_show
 * DESCRIPTION
 *  similar to category 263, but add a checkbox in front of each item and have a tab bar
 * 
 * <img name="wgui_cat267_tab_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon
 *   left_softkey                  : [IN ] (LSK) Left softkey string
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey string
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   number_of_items               : [IN ] (N/A) Number of items of list
 *   get_item_func                 : [IN ] (C267_1) Get item function pointer
 *   get_hint_func                 : [IN ] (HINT) Get hint function pointer
 *   get_state_func                : [IN ] (N/A) Get state of check-box function pointer
 *   set_state_func                : [IN ] (N/A) Set state of check-box function pointer
 *   info_message                  : [IN ] (C267_2) Char array of information message
 *   highlighted_item              : [IN ] (N/A) Currently highlighted item
 *   highlighted_tab               : [IN ] (N/A) Currently highlighted item
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat267_tab_show(
                WCHAR *title,
                PU8 title_icon,
                WCHAR *left_softkey,
                WCHAR *right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                checkbox_get_image_funcptr_type get_state_func,
                checkbox_clicked_funcptr_type set_state_func,
                WCHAR *info_message,
                S32 highlighted_item,
                S8 highlighted_tab,
                PU8 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory267Screen
 * DESCRIPTION
 *  similar to category 263, but add a checkbox in front of each item
 * 
 * <img name="wgui_cat267_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon
 *   left_softkey                  : [IN ] (LSK) Left softkey string
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey string
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   number_of_items               : [IN ] (N/A) Number of items of list
 *   get_item_func                 : [IN ] (C267_1) Get item function pointer
 *   get_hint_func                 : [IN ] (HINT) Get hint function pointer
 *   get_state_func                : [IN ] (N/A) Get state of check-box function pointer
 *   set_state_func                : [IN ] (N/A) Set state of check-box function pointer
 *   info_message                  : [IN ] (C267_2) Char array of information message
 *   highlighted_item              : [IN ] (N/A) Currently highlighted item
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_267(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     S32 error;
 * 
 *     if (mmi_frm_scrn_enter(
 *         GRP_ID_CSB_ROOT, SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, MMI_FRM_UNKNOW_SCRN))
 *     {
 * 
 *         mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category267");
 *         mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Info text");
 * 
 *         ShowCategory267Screen(
 *             get_string(STR_ID_CSB_CATEGORY_TEXT),
 *             0,
 *             get_string(STR_ID_CSB_LSK_TEXT),
 *             0,
 *             get_string(STR_ID_CSB_RSK_TEXT),
 *             0,
 *             6,
 *             get263_async_items,
 *             NULL,
 *             cat384_checkbox_get_image_callback,
 *             cat384_checkbox_clicked_callback,
 *             L"Press * to turn on/off",
 *             0,
 *             IMG_GLOBAL_L1,
 *             guiBuffer,
 *             &error);
 * 
 *         RedrawCategory263InfoBox(g_buffer, g_buffer1);
 * 
 *         csb_set_key_handlers();
 *     }
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory267Screen(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                checkbox_get_image_funcptr_type get_state_func,
                checkbox_clicked_funcptr_type set_state_func,
                UI_string_type info_message,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

extern void ShowCategory267Screen_int(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                UI_string_type right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                checkbox_get_image_funcptr_type get_state_func,
                checkbox_clicked_funcptr_type set_state_func,
                UI_string_type info_message,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

#define ShowCategory267Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)	\
	ShowCategory267Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)

/*****************************************************************************
 * FUNCTION
 *  ShowCategory268Screen
 * DESCRIPTION
 *  Category 268 is an async dynamic list menu category.
 *  It displays text index 1 in the 1st line, and displays text index 0 in the 2nd line when highlighted.
 * 
 * <img name="wgui_cat268_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon
 *   left_softkey                  : [IN ] (LSK) Left softkey string
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey string
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   number_of_items               : [IN ] (N/A) Number of items to be displayed
 *   get_item_func                 : [IN ] (C268_1,C268_2) Function pointer to get next displayed items
 *   get_hint_func                 : [IN ] (HINT) Function pointer to get next displayed hint data
 *   highlighted_item              : [IN ] (N/A) Index of item to be highlighted
 *   highlighted_tab               : [IN ] (N/A) Index of tab to be highlighted
 *   list_icon                     : [IN ] (N/A) Icon of list
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat268_with_tab_show(
               WCHAR *title,
               PU8 title_icon,
               WCHAR *left_softkey,
               PU8 left_softkey_icon,
               WCHAR *right_softkey,
               PU8 right_softkey_icon,
               S32 number_of_items,
               GetAsyncItemFuncPtr get_item_func,
               GetAsyncHintFuncPtr get_hint_func,
               S32 highlighted_item,
               S8 highlighted_tab,
               PU8 list_icon,
               U8 *history_buffer,
               S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory268Screen
 * DESCRIPTION
 *  Category 268 is an async dynamic list menu category.
 *  It displays text index 1 in the 1st line, and displays text index 0 in the 2nd line when highlighted.
 * 
 * <img name="wgui_cat268_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon ID
 *   left_softkey                  : [IN ] (LSK) Left softkey string ID
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon ID
 *   right_softkey                 : [IN ] (RSK) Right softkey string ID
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon ID
 *   number_of_items               : [IN ] (N/A) Number of items to be displayed
 *   get_item_func                 : [IN ] (C268_1,C268_2) Function pointer to get next displayed items
 *   get_hint_func                 : [IN ] (HINT) Function pointer to get next displayed hint data
 *   highlighted_item              : [IN ] (N/A) Index of item to be highlighted
 *   list_icon                     : [IN ] (N/A) Icon of list
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_268(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     S32 error;
 * 
 *     if (mmi_frm_scrn_enter(
 *         GRP_ID_CSB_ROOT, SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, MMI_FRM_UNKNOW_SCRN))
 *     {
 * 
 *         mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category268");
 *         wgui_cat_set_list_menu_empty_lable(L"Hello, World");
 * 
 *         ShowCategory268Screen(
 *             (U8*) g_buffer,
 *             0,
 *             STR_ID_CSB_LSK_TEXT,
 *             0,
 *             STR_ID_CSB_RSK_TEXT,
 *             0,
 *             5,
 *             get268_async_items,
 *             NULL,
 *             0,
 *             IMG_GLOBAL_L1,
 *             guiBuffer,
 *             &error);
 * 
 *         csb_set_key_handlers();
 *     }
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory268Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

extern void ShowCategory268Screen_int(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

#define ShowCategory268Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)	\
    ShowCategory268Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1002_tab_show
 * DESCRIPTION
 *  Category 1002 with tab is an async dynamic list menu category with checkbox before each item.
 *  It displays text index 0 in the 1st line, and displays text index 1 in the 2nd line when highlighted.
 * 
 * <img name="wgui_cat1002_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon
 *   left_softkey                  : [IN ] (LSK) Left softkey string
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey string
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   number_of_items               : [IN ] (N/A) Number of items of list
 *   get_item_func                 : [IN ] (C267_1) Get item function pointer
 *   get_hint_func                 : [IN ] (HINT) Get hint function pointer
 *   get_state_func                : [IN ] (N/A) Get state of check-box function pointer
 *   set_state_func                : [IN ] (N/A) Set state of check-box function pointer
 *   info_message                  : [IN ] (C267_2) Char array of information message
 *   highlighted_item              : [IN ] (N/A) Currently highlighted item
 *   highlighted_tab               : [IN ] (N/A) current highlighted tab
 *   list_icon                     : [IN]  (N/A) Icon of list
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1002_tab_show(
                WCHAR *title,
                PU8 title_icon,
                WCHAR *left_softkey,
                PU8 left_softkey_icon,
                WCHAR *right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                checkbox_get_image_funcptr_type get_state_func,
                checkbox_clicked_funcptr_type set_state_func,
                WCHAR *info_message,
                S32 highlighted_item,
                S8 highlighted_tab,
                PU8 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1002_show
 * DESCRIPTION
 *  Category 1002 is an async dynamic list menu category with checkbox before each item.
 *  It displays text index 0 in the 1st line, and displays text index 1 in the 2nd line when highlighted.
 * 
 * <img name="wgui_cat1002_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon
 *   left_softkey                  : [IN ] (LSK) Left softkey string
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey string
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   number_of_items               : [IN ] (N/A) Number of items of list
 *   get_item_func                 : [IN ] (C267_1) Get item function pointer
 *   get_hint_func                 : [IN ] (HINT) Get hint function pointer
 *   get_state_func                : [IN ] (N/A) Get state of check-box function pointer
 *   set_state_func                : [IN ] (N/A) Set state of check-box function pointer
 *   info_message                  : [IN ] (C267_2) Char array of information message
 *   highlighted_item              : [IN ] (N/A) Currently highlighted item
 *   list_icon                     : [IN]  (N/A) Icon of list
 *   history_buffer                : [IN ] (N/A) History buffer
 *   category_error_flag           : [OUT] (N/A) error flag
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_1002(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     S32 error;
 * 
 *     if (mmi_frm_scrn_enter(
 *         GRP_ID_CSB_ROOT, SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, MMI_FRM_UNKNOW_SCRN))
 *     {
 * 
 *         mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category1002");
 * 
 *         wgui_cat1002_show(
 *             (UI_string_type) g_buffer,
 *             0,
 *             get_string(STR_ID_CSB_LSK_TEXT),
 *             0,
 *             get_string(STR_ID_CSB_RSK_TEXT),
 *             0,
 *             10,
 *             get263_async_items,
 *             NULL,
 *             cat1002_checkbox_get_image_callback,
 *             cat1002_checkbox_clicked_callback,
 *             L"Press * to turn on/off",
 *             0,
 *             IMG_GLOBAL_L1,
 *             guiBuffer,
 *             &error);
 * 
 *         csb_set_key_handlers();
 *     }
 * }
 * </code>
 *****************************************************************************/
extern void wgui_cat1002_show(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                checkbox_get_image_funcptr_type get_state_func,
                checkbox_clicked_funcptr_type set_state_func,
                UI_string_type info_message,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

extern void wgui_cat1002_show_int(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                UI_string_type right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                checkbox_get_image_funcptr_type get_state_func,
                checkbox_clicked_funcptr_type set_state_func,
                UI_string_type info_message,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

#define wgui_cat1002_show(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)	\
	wgui_cat1002_show_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)

#ifdef __GEMINI__  
/*Valid for cat263, cat267, cat268, cat1002 */        
extern void wgui_cat_list_set_display_more_icon(MMI_BOOL IsMoreIcon);
#endif

#endif /* WGUI_CATEGORIES_EMAIL_H */ 
/********** EMAIL SCREEN END **********/


