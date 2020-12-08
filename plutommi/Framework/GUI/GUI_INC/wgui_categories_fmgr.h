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
 *  wgui_categories_fmgr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  File Manager related categories.
 *
 *  [Category212]       Info Style Dynamic List Menu 
 *  [Category213]       Thick Style Dynamic List Menu 
 *  [Category214]       Matrix Style Dynamic Image Menu 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef __WGUI_CATEGORIES_FMGR_H__
#define __WGUI_CATEGORIES_FMGR_H__
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "kal_general_types.h"
#include "gui_windows.h"
#include "custom_mmi_default_value.h"
#include "GlobalConstants.h"
/* #include "FileMgrGProt.h" */
/* DOM-NOT_FOR_SDK-END */
/***************************************************************************** 
* Define
*****************************************************************************/
#define CAT213_ARROW_UP    0x1
#define CAT213_ARROW_DOWN  0x2
#define CAT213_ARROW_LEFT  0x4
#define CAT213_ARROW_RIGHT 0x8
#define CAT213_ARROW_ALL   0xf

//#if !defined(LOW_COST_SUPPORT) || defined(__OP12__)
#ifndef __MMI_SLIM_FILE_MANAGER__
#ifndef __MMI_CAT216_CAT212_SUPPORT_FMGR__
	#define __MMI_CAT216_CAT212_SUPPORT_FMGR__
#endif
#ifndef __MMI_CAT217_CAT213_SUPPORT_FMGR__
    #define __MMI_CAT217_CAT213_SUPPORT_FMGR__
#endif
#endif
/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef void (*Cat212DrawInfoFuncPtr) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat212HideInfoFuncPtr) (void);

typedef void (*Cat213DrawMenuItemFuncPtr) (S32 idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat213HideMenuItemFuncPtr) (void);

typedef void (*Cat214DrawImageFuncPtr) (S32 idx, S32 page_star_idx, S32 page_end_idx, BOOL is_hilighted,
                                        BOOL is_need_update, BOOL is_new_page, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat214HideImageFuncPtr) (S32 idx);

typedef void (*Cat219DecodeDoneHdlr) (S32 idx);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP FILEMANAGER> 
 * FUNCTION
 *  ShowCategory216Screen
 * DESCRIPTION
 *  Show category 216 screen.
 *  [FTE]: support (tool bar is avaiable)
 * <img name="wgui_cat216_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  right_softkey               [IN]        Rsk string id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  list_icon                   [IN]        Icon used before text, measure the image's width and height
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  get_image_func              [IN]        Get state of check-box function pointer
 *  set_state_func              [IN]        Set state of check-box function pointer 
 *  info_box_height             [IN]        Height of info box
 *  info_bg_img_id              [IN]        (unused)
 *  info_message                [IN]        Show info message in bottom 
 *	empty_message				[IN]		Show empty message if count = 0
 *  highlighted_item            [IN]        Highlighted item
 *  is_two_line                 [IN]        If show top info area or use two line to show info
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN]        Async-Dynamic list error flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory216Screen(
            U16  title,
            U16 title_icon,
            U16 left_softkey,
            U16 right_softkey,
            S32 num_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            U16 list_icon,
            Cat212DrawInfoFuncPtr draw_info_callback,
            Cat212HideInfoFuncPtr hide_info_callback,
            checkbox_get_image_funcptr_type get_image_func,
            checkbox_clicked_funcptr_type set_state_func,
            S32 info_box_height,
            U16 info_bg_img_id,
            U8* info_message,
			UI_string_type empty_message,
            S32 highlighted_item,
            S8 highlighted_tab,
            MMI_BOOL is_two_line,
            U8 *history_buffer,
            MMI_BOOL tab_flag,
            S32 *category_error_flag);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <GROUP FILEMANAGER> 
 * FUNCTION
 *  ShowCategory211Screen
 * DESCRIPTION
 *  Show Category 211 screen.
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat211_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string id
 *   title_icon                    : [IN ] (N/A) Title image id
 *   left_softkey                  : [IN ] (LSK) Lsk string id
 *   left_softkey_icon             : [IN ] (N/A) Lsk image id
 *   right_softkey                 : [IN ] (RSK) Rsk string id
 *   right_softkey_icon            : [IN ] (N/A) Rsk image id
 *   num_of_items                  : [IN ] (N/A) How many items
 *   get_item_func                 : [IN ] (ICONTEXT) Callback function to get item string
 *   get_hint_func                 : [IN ] (HINT) Callback function to get item hint
 *   draw_info_callback            : [IN ] (C211_1) Callback function to draw info
 *   hide_info_callback            : [IN ] (N/A) Callback function to hide info
 *   info_box_height               : [IN ] (N/A) Height of info box
 *   info_bg_img_id                : [IN ] (N/A) (unused)
 *   highlighted_item              : [IN ] (N/A) Highlighted item
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_211(void)
 * {
 *     PU8 guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory211Screen(
 *         STR_ID_CSB_DUMMY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         10,
 *         mmi_csb_get_dynamic_item,
 *         NULL,
 *         mmi_csb_fmgr_211_draw_info_empty,
 *         NULL,
 *         40,
 *         0,
 *         0,
 *         (U8*) guiBuffer);
 * 
 *     csb_set_key_handlers();
 * 
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory211Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                Cat212DrawInfoFuncPtr draw_info_callback,
                Cat212HideInfoFuncPtr hide_info_callback,
                S32 info_box_height,
                U16 info_bg_img_id,
                S32 highlighted_item,
                U8 *history_buffer);

/* Info style dynamic list category */


/*****************************************************************************
 * <GROUP FILEMANAGER>
 * FUNCTION
 *  ShowCategory212Screen
 * DESCRIPTION
 *  Show Category 212 screen.
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat212_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string id
 *   title_icon                    : [IN ] (N/A) Title image id
 *   left_softkey                  : [IN ] (LSK) Lsk string id
 *   left_softkey_icon             : [IN ] (N/A) Lsk image id
 *   right_softkey                 : [IN ] (RSK) Rsk string id
 *   right_softkey_icon            : [IN ] (N/A) Rsk image id
 *   num_of_items                  : [IN ] (N/A) How many items
 *   get_item_func                 : [IN ] (ICONTEXT) Callback function to get item string
 *   get_hint_func                 : [IN ] (HINT) Callback function to get item hint
 *   draw_info_callback            : [IN ] (C211_1) Callback function to draw info
 *   hide_info_callback            : [IN ] (N/A) Callback function to hide info
 *   num_of_info_box_rows          : [IN ] (N/A) How many row (height) for info box
 *   info_bg_img_id                : [IN ] (N/A) (unused)
 *   highlighted_item              : [IN ] (N/A) Highlighted item
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_212(void)
 * {
 *     PU8 guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory212Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         10,
 *         mmi_csb_get_dynamic_item,
 *         NULL,
 *         mmi_csb_fmgr_211_draw_info_empty,
 *         NULL,
 *         2,
 *         0,
 *         0,
 *         (U8*) guiBuffer);
 * 
 *     csb_set_key_handlers();
 * 
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory212Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                Cat212DrawInfoFuncPtr draw_info_callback,
                Cat212HideInfoFuncPtr hide_info_callback,
                U16 num_of_info_box_rows,
                U16 info_bg_img_id,
                S32 highlighted_item,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void Cat212ShortCutHdlr(S32 item_index);
extern void DrawTextAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2);
extern void FillFullTextBackground(S32 x1, S32 y1, S32 x2, S32 y2);
/* DOM-NOT_FOR_SDK-END */

/* Thick style dynamic list category */


/*****************************************************************************
 * <GROUP FILEMANAGER>
 * FUNCTION
 *  ShowCategory213Screen
 * DESCRIPTION
 *  Show Category 213 screen.
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat213_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string id
 *   title_icon                    : [IN ] (N/A) Title image id
 *   left_softkey                  : [IN ] (LSK) Lsk string id
 *   left_softkey_icon             : [IN ] (N/A) Lsk image id
 *   right_softkey                 : [IN ] (RSK) Rsk string id
 *   right_softkey_icon            : [IN ] (N/A) Rsk image id
 *   num_of_items                  : [IN ] (N/A) How many items
 *   draw_menuitem_callback        : [IN ] (C213_1) Callback function to draw menuitem
 *   hide_menuitem_callback        : [IN ] (N/A) Callback function to hide menuitem
 *   highlighted_item              : [IN ] (N/A) Highlighted item index
 *   arrow_flag                    : [IN ] (N/A) Arrow on buttom bar
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_213(void)
 * {
 *     PU8 guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory213Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         10,
 *         mmi_csb_fmgr_213_draw_info_empty,
 *         NULL,
 *         0,
 *         0,
 *         (U8*) guiBuffer);
 * 
 *     csb_set_key_handlers();
 * 
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory213Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                Cat213DrawMenuItemFuncPtr draw_menuitem_callback,
                Cat213HideMenuItemFuncPtr hide_menuitem_callback,
                S32 highlighted_item,
                U8 arrow_flag,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP FILEMANAGER> 
 * FUNCTION
 *  ShowCategory217Screen
 * DESCRIPTION
 *  Show sategory 217 screen. async-dynamic list of category 213
 *  [FTE]: support (tool bar is avaiable)
 * <img name="wgui_cat217_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_menuitem_callback      [IN]        Callback function to draw menuitem
 *  hide_menuitem_callback      [IN]        Callback function to hide menuitem
 *  empty_message               [IN]        String shown on screen when list is empty.
 *  highlighted_item            [IN]        Highlighted item index
 *  arrow_flag                  [IN]        Arrow on buttom bar
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory217Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        Cat213DrawMenuItemFuncPtr draw_menuitem_callback,
        Cat213HideMenuItemFuncPtr hide_menuitem_callback,
        UI_string_type empty_message,
        S32 highlighted_item,
        U8 arrow_flag,
        U8 *history_buffer,
        S32 *category_error_flag);
/* DOM-NOT_FOR_SDK-END */

/* Matrix style dynamic image category */


/*****************************************************************************
 * <GROUP FILEMANAGER>
 * FUNCTION
 *  ShowCategory214Screen
 * DESCRIPTION
 *  Show Category 214 screen.
 *  [FTE]: support (tool bar is avaiable)
 * <img name="wgui_cat214_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string id
 *   title_icon                    : [IN ] (N/A) Title image id
 *   left_softkey                  : [IN ] (LSK) Lsk string id
 *   left_softkey_icon             : [IN ] (N/A) Lsk image id
 *   right_softkey                 : [IN ] (RSK) Rsk string id
 *   right_softkey_icon            : [IN ] (N/A) Rsk image id
 *   num_of_items                  : [IN ] (N/A) How many items
 *   draw_image_callback           : [IN ] (N/A) Callback function to draw image
 *   hide_image_callback           : [IN ] (N/A) Callback function to hide
 *   num_per_row                   : [IN ] (N/A) Num of image pre row
 *   num_per_col                   : [IN ] (N/A) Num of image pre col
 *   highlighted_item              : [IN ] (N/A) Highlighted item
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_214(void)
 * {
 *     PU8 guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory214Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         15,
 *         mmi_icon_select_draw_image_callback,
 *         mmi_icon_select_hide_image_callback,
 *         3,
 *         3,
 *         0,
 *         (U8*) guiBuffer);
 * 
 *     csb_set_key_handlers();
 * 
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory214Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 num_of_items,
                Cat214DrawImageFuncPtr draw_image_callback,
                Cat214HideImageFuncPtr hide_image_callback,
                U8 num_per_row,
                U8 num_per_col,
                S32 highlighted_item,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void GetCategory214BoxSize(S32 num_per_row, S32 num_per_col, S32 *box_width_ptr, S32 *box_height_ptr);
extern void wgui_cat214_disable_draw_highlight(void);

//#define mmi_fmgr_draw_hilight_menuitem_bg(x1, y1, x2 ,y2)   wgui_fmgr_draw_hilight_menuitem_bg(x1, y1, x2, y2)



//#if defined(__MMI_FMGR_SUPPORT_THUMB_DECODE__)
#define FMGR_THUMB_IMAGE_CACHE_MAX_COUNT        (50)    /* may cache up to 30 images */
#define FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT       (16)    /* may decode up to 12 images on a screen at a time */
#define FMGR_DELAY_DECODER_COUNT                (16)
//#endif


#if defined (__MMI_MAINLCD_320X480__)
#define FMGR_UI_IMAGE_BOX_SPACING      (6)
#elif defined (__MMI_MAINLCD_240X400__)
#define FMGR_UI_IMAGE_BOX_SPACING      (7)
#else
#define FMGR_UI_IMAGE_BOX_SPACING      (2)
#endif

#define FMGR_UI_TEXT_SPACING           (4)

/* DOM-NOT_FOR_SDK-END */

/* Category 21x image type */
typedef enum
{
    WGUI_CAT21X_INFO_TYPE_DRV,  /* Driver type */
    WGUI_CAT21X_INFO_TYPE_FILE  /* File type */
}wgui_fmgr_info_type;

/* Enum of fmgr image style */
typedef enum
{
    MMI_FMGR_GUI_LIST_STYLE,    /* List style */
    MMI_FMGR_GUI_INFO_STYLE,    /* Info area style */
    MMI_FMGR_GUI_MATRIX_STYLE,  /* Matrix style */
    MMI_FMGR_GUI_HILITE_STYLE   /* Two line hilite style */
}wgui_fmgr_style_enum;

/* Struct of fmgr info area */
typedef struct
{
    UI_string_type info_text_l1_s1;         /* Line1 1st string */
    UI_character_type info_text_l1_s2[32]; /* Line1 2nd string */
    UI_string_type info_text_l2_s1;         /* Line2 1st string */
    UI_character_type info_text_l2_s2[64]; /* Line1 2nd string */
    MMI_BOOL is_show_thumb;                 /* If show this image as a thumb image */
    wgui_fmgr_info_type info_type;          /* Type of this item DRV or FILE */
    U32 drv_ratio;                          /* When it's a DRV item, the ratio of this drv */
    PU8 file_icon_ptr;                      /* Default image pointer */
} wgui_fmgr_info_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
typedef struct
{
    scrolling_text scroll_text;
    S8 scroll_text_buf[(MAX_SUBMENU_CHARACTERS + 1) *ENCODING_LENGTH];
    
    /* UI use */
    U16 delay_decode_index;
} wgui_fmgr_category_struct;
/* DOM-NOT_FOR_SDK-END */

/* Filemanager category menuitem thumb image cache structure  */
typedef struct
{
    UI_character_type menu_text_l1_s1[MAX_SUBMENU_CHARACTERS + 1]; /* Line1 1st string */
    UI_character_type menu_text_l2_s1[32]; /* Line2 1st string */
    UI_character_type menu_text_l2_s2[64]; /* Line2 2nd string */
    S32 info_type;                          /* Type of this item DRV or FILE */
    U32 drv_ratio;                          /* When it's a DRV item, the ratio of this drv */
    PU8 file_icon_ptr;                      /* Default image pointer */
    MMI_BOOL is_show_thumb;                 /* If show this image as a thumb image */
} wgui_fmgr_menuitem_data_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
typedef void (*Cat212GetInfoData)(S32 item_idx, wgui_fmgr_info_struct *fmgr_info);
typedef void (*Cat212HideInfoData)(void);
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  CatFmgrGetFileData
 * DESCRIPTION
 *  Get the item data from application
 * PARAMETERS
 *  item_idx             [IN]        Index of items
 *  is_hilighted         [IN]        Is this item highlighted
 *  menuitem_data        [IN]        Content buffer to fill
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*CatFmgrGetFileData)(S32 item_idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data);

/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  CatFmgrHideFileData
 * DESCRIPTION
 *  Notification callback when hide the item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*CatFmgrHideFileData)(void);

/* DOM-NOT_FOR_SDK-BEGIN */
#define SET_UCS2STR_EMPTY(x) x[0]='\0';x[1]='\0';
#define CHECK_UCS2STR_EMPTY(x) (x[0]=='\0' && x[1]=='\0')
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  wgui_fmgr_set_displayable_func
 * DESCRIPTION
 *  Set if should display this item.
 * PARAMETERS
 *  item_idx             [IN]        Index of items
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*wgui_fmgr_set_displayable_func)(S32 index, MMI_BOOL displayable);

/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  wgui_fmgr_get_displayable_func
 * DESCRIPTION
 *  Get if should display this item.
 * PARAMETERS
 *  item_idx             [IN]        Index of items
 * RETURNS
 *  void
 *****************************************************************************/
typedef MMI_BOOL (*wgui_fmgr_get_displayable_func)(S32 item_idx);

/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  wgui_fmgr_get_thumb_image_func
 * DESCRIPTION
 *  Get the thumb image path
 * PARAMETERS
 *  item_idx             [IN]        Index of items
 *  file_path            [IN]        File path to show the thumb
 * RETURNS
 *  void
 *****************************************************************************/
typedef MMI_BOOL (*wgui_fmgr_get_thumb_image_func)(S32 item_idx, S8 *file_path);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory216FmgrMarkScreen
 *  [FTE]: support (tool bar is avaiable)
 * DESCRIPTION
 *  Show Category 216 only for fmgr screen multi-select. async + info area + mark
 * <img name="wgui_cat216fmgrmark_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  list_icon                   [IN]        Icon of list, used to calculate size of icon
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  get_image_func              [IN]        Get check-box image callback
 *  set_state_func              [IN]        Set select state callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  info_message                [IN]        String buffer
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN/OUT]    Error flag for async list
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory216FmgrMarkScreen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 list_icon,
                Cat212GetInfoData get_info_data,
                Cat212HideInfoData hide_info_data,
                checkbox_get_image_funcptr_type get_image_func,
                checkbox_clicked_funcptr_type set_state_func,
                U16 num_of_info_box_rows,
                U16 info_bg_img_id,
                U8* info_message,
				UI_string_type empty_string,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag);    

/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory216FmgrScreen
 *  [FTE]: support (tool bar is avaiable)
 * DESCRIPTION
 *  Show Category 216 only for fmgr screen. async + info area
 * <img name="wgui_cat216fmgr_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string for async dynamic list
 *  get_hint_func               [IN]        Callback function to get item hint  for async dynamic list
 *  list_icon                   [IN]        Icon of list, used to calculate size of icon
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN/OUT]    Error flag for async list
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory216FmgrScreen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 list_icon,
                Cat212GetInfoData get_info_data,
                Cat212HideInfoData hide_info_data,
                U16 num_of_info_box_rows,
                U16 info_bg_img_id,
				UI_string_type empty_string,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory218FmgrMarkScreen
 * DESCRIPTION
 *  Show Category 218 only for fmgr screen multi-select, async + two line highlight mode + mark
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat218fmgrmark_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  list_icon                   [IN]        Icon of list, used to calculate size of icon
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  get_image_func              [IN]        Get check-box image callback
 *  set_state_func              [IN]        Set select state callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  info_message                [IN]        String buffer
 *	empty_string				[IN]		show empty stirng if count = 0
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN/OUT]    Error flag for async list
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory218FmgrMarkScreen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 list_icon,
                Cat212GetInfoData get_info_data,
                Cat212HideInfoData hide_info_data,
                checkbox_get_image_funcptr_type get_image_func,
                checkbox_clicked_funcptr_type set_state_func,
                U16 num_of_info_box_rows,
                U16 info_bg_img_id,
                U8* info_message,
                UI_string_type empty_string,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory218FmgrScreen
 * DESCRIPTION
 *  Show Category 218 only for fmgr screen, async + two line highlight mode.
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat218fmgr_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string for async dynamic list
 *  get_hint_func               [IN]        Callback function to get item hint  for async dynamic list
 *  list_icon                   [IN]        Icon of list, used to calculate size of icon
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *	empty_string				[IN]		show empty stirng if count = 0
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN/OUT]    Error flag for async list
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory218FmgrScreen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 list_icon,
                Cat212GetInfoData get_info_data,
                Cat212HideInfoData hide_info_data,
                U16 num_of_info_box_rows,
                U16 info_bg_img_id,
                UI_string_type empty_string,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory218FmgrTabScreen
 * DESCRIPTION
 *  Show Category 218 only for fmgr screen, async + two line highlight mode + tab bar.
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat218fmgr_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string for async dynamic list
 *  get_hint_func               [IN]        Callback function to get item hint  for async dynamic list
 *  list_icon                   [IN]        Icon of list, used to calculate size of icon
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *	empty_string				[IN]		show empty stirng if count = 0
 *  highlighted_item            [IN]        Highlighted item
 *	highlighted_tab				[IN]		Highlighted tab
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN/OUT]    Error flag for async list
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory218FmgrTabScreen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
				S32 num_of_items,
				GetAsyncItemFuncPtr get_item_func,
				GetAsyncHintFuncPtr get_hint_func,
				S32 list_icon,
				Cat212GetInfoData get_info_data,
				Cat212HideInfoData hide_info_data,
				U16 num_of_info_box_rows,
				U16 info_bg_img_id,
				UI_string_type empty_string,
				S32 highlighted_item,
				S8 highlighted_tab,
				U8 *history_buffer,
				S32 *category_error_flag);


/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory217FmgrScreen
 * DESCRIPTION
 *  Show Category 217 only for fmgr screen, async + two line.
 *  [FTE]: support (tool bar is avaiable)
 *  [FTE]: support (tool bar is avaiable)
 * <img name="wgui_cat217fmgr_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_menuitem_data           [IN]        Callback function to get item string for async dynamic list
 *  hide_menuitem_data          [IN]        Callback function to get item hint  for async dynamic list
 *  empty_message               [IN]        String shown on screen when list is empty.
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 *  arrow_flag                  [IN]        Arrow on buttom bar(Not used)
 *  category_error_flag         [IN/OUT]    Error flag for async list
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory217FmgrScreen(
           U16 title,
           U16 title_icon,
           U16 left_softkey,
           U16 left_softkey_icon,
           U16 right_softkey,
           U16 right_softkey_icon,
           S32 num_of_items,
           GetAsyncItemFuncPtr get_item_func,
           GetAsyncHintFuncPtr get_hint_func,
           CatFmgrGetFileData get_menuitem_data,
           CatFmgrHideFileData hide_menuitem_data,
           UI_string_type empty_message,
           S32 highlighted_item,
           U8 arrow_flag,
           U8 *history_buffer,
           S32 *category_error_flag);


/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory212FmgrScreen
 * DESCRIPTION
 *  Show Category 212 only for fmgr screen, dynamic + info area
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat212fmgr_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string for async dynamic list
 *  get_hint_func               [IN]        Callback function to get item hint  for async dynamic list
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory212FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        S32 highlighted_item,
        U8 *history_buffer);
        

/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory212FmgrMarkScreen
 * DESCRIPTION
 *  Show Category 212 only for fmgr screen multi-select. dynamic list + info area + multi-select.
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat212fmgrmark_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  get_image_func              [IN]        Get check-box image callback
 *  set_state_func              [IN]        Set select state callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  info_message                [IN]        String buffer
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory212FmgrMarkScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        U8* info_message,
        S32 highlighted_item,
        U8 *history_buffer);
        
/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory213FmgrScreen
 * DESCRIPTION
 *  Show Category 213 only for fmgr screen, dynamic list + two line
 *  [FTE]: support (tool bar is not avaiable)
 * <img name="wgui_cat213fmgr_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string for async dynamic list
 *  get_hint_func               [IN]        Callback function to get item hint  for async dynamic list
 *  list_icon                   [IN]        Icon of list, used to calculate size of icon
 *  get_info_data               [IN]        Info area get data
 *  hide_info_data              [IN]        Hide info area callback
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 *  category_error_flag         [IN/OUT]    Error flag for async list
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory213FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        S32 highlighted_item,
        U8 arrow_flag,
        U8 *history_buffer);

/*****************************************************************************
 * <GROUP ONLYFMGR> 
 * FUNCTION
 *  ShowCategory214FmgrScreen
 * DESCRIPTION
 *  Show sategory 214 screen for filemanager only. It's dynamic list + matrix category to show images
 *  [FTE]: support (tool bar is avaiable)
 * <img name="wgui_cat214fmgr_img1" />
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_menuitem_data           [IN]        Callback function to get item
 *  hide_menuitem_data          [IN]        Callback function when hide item
 *  num_per_row                 [IN]        Number per row
 *  num_per_col                 [IN]        Number per colume
 *  highlighted_item            [IN]        highlight index
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory214FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  wgui_cat21x_register_set_displayable
 * DESCRIPTION
 *  set set displayable flag callback to filemanager category
 * PARAMETERS
 *  set_displayable             [IN]        Callback function to set displayable flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat21x_register_set_displayable(wgui_fmgr_set_displayable_func set_displayable);

/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  wgui_cat21x_register_get_displayable
 * DESCRIPTION
 *  set get displayable flag callback to filemanager category
 * PARAMETERS
 *  get_displayable             [IN]        callback function to get displayable flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat21x_register_get_displayable(wgui_fmgr_get_displayable_func get_displayable);

/*****************************************************************************
 * <GROUP ONLYFMGR>
 * FUNCTION
 *  wgui_cat21x_register_get_thumb_image
 * DESCRIPTION
 *  set get thumb callback to filemanager category
 * PARAMETERS
 *  get_thumb_image             [IN]        callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat21x_register_get_thumb_image(wgui_fmgr_get_thumb_image_func get_thumb_image);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void wgui_cat212_fmgr_draw_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat212_fmgr_hide_info(void);

extern void wgui_cat213_fmgr_draw_menuitem(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat213_fmgr_hide_menuitem(void);

extern void wgui_cat214_fmgr_draw_menuitem_matrix(S32 idx, S32 page_start_idx, S32 page_end_idx,
                                             BOOL is_hilighted, BOOL is_need_update, BOOL is_new_page,
                                             S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat214_fmgr_hide_menuitem_matrix(S32 idx);

extern void wgui_cat218_fmgr_draw_hilite_item(S32 item_idx, UI_string_type string, S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat218_fmgr_hide_hilite_item(void);

extern void wgui_fmgr_draw_free_space_icon(S32 box_x1, S32 box_y1, S32 box_height, U32 drv_ratio, PU8 file_icon_ptr);

extern void wgui_fmgr_cache_stop_decoder(void);

#if defined(__MMI_CAT216_CAT212_SUPPORT_FMGR__) || defined(__MMI_CAT217_CAT213_SUPPORT_FMGR__)
extern void wgui_fmgr_draw_hilight_menuitem_timer_callback(void);
extern void wgui_fmgr_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2);
#endif
/* DOM-NOT_FOR_SDK-END */  
extern void wgui_cat21x_fmgr_set_slow_data_mode(MMI_BOOL slow_mode);
extern void ShowCategory219FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag);
extern void ShowCategory219FmgrScreen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag);
#define ShowCategory219FmgrScreen(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8,_arg9,\
    _arg10,_arg11,_arg12,_arg13,_arg14,_arg15,_arg16)\
    ShowCategory219FmgrScreen_int(_arg1,_arg2,_arg3,_arg5,_arg7,_arg8,_arg9,\
    _arg10,_arg11,_arg12,_arg13,_arg14,_arg15,_arg16)
extern void ShowCategory219Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        Cat214DrawImageFuncPtr draw_image_callback,
        Cat214HideImageFuncPtr hide_image_callback,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag);
extern void ShowCategory219FmgrScreen_ext(   // for sns
        WCHAR* title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        WCHAR* empty_string,
        S32 *category_error_flag);
extern void wgui_cat219_register_decode_done_hdlr(Cat219DecodeDoneHdlr decode_done_hdlr);  // for sns
extern MMI_BOOL wgui_cat219_get_index_is_cached(S32 index); // for sns.

#endif /* __WGUI_CATEGORIES_FMGR_H__ */ 


