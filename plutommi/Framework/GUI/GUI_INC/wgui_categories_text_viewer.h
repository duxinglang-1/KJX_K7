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
 *  wgui_categories_text_viewer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Category header file of text viewers
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_TEXT_VIEWER_H__
#define __WGUI_CATEGORIES_TEXT_VIEWER_H__

/* Slim version don't support slide controls in text viewer screen */
#if !defined (__MMI_BASIC_UI_STYLE__) && !defined(__MMI_SLIM_IMG_RES__)
    #ifndef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
        #define __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    #endif
#endif


#if  defined(__SOCIAL_NETWORK_SUPPORT__)
   #define __MMI_CATEGORY79_IMGAGE_SUPPORT__     //slim_slim_3_2
#endif 
//RHR
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "lcd_sw_inc.h"
    #include "gui_data_types.h"
    #include "wgui_inputs.h"
    #include "gui_inputs.h"
    #include "MMI_features.h"
    #include "wgui_draw_manager.h"
    #include "Gui_Setting.h"
    #include "gdi_datatype.h"
    #include "gui_windows.h"
    #include "wgui_categories_list.h"

#if defined(__MMI_MAINLCD_96X64__)
#define   MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE  // SLIM_96_64_SLIM  
#endif
    
#ifdef  MMI_CATEGORIES_TEXT_VIEWER_SUPPORT_ICON_TITLE
    extern void wgui_cat_text_viewer_setup_title_change(U16 icon_ID, U16 icon2_ID, U8 *text, U32 flag);
#endif
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
typedef struct _wgui_cat_slide_control_cntx
{
    U16 left_button_id;
    WCHAR* left_button_string;
    PU8 left_button_down_image;
    PU8 left_button_up_image;
    FuncPtr left_button_function;
    U16 right_button_id;
    WCHAR* right_button_string;
    PU8 right_button_down_image;
    PU8 right_button_up_image;
    FuncPtr right_button_function;
    WCHAR* middle_string;
    U32 flags;
} wgui_cat_slide_control_cntx;

#define WGUI_CAT_SLIDE_CONTROL_H                     (MMI_SINGLELINE_INPUTBOX_HEIGHT + 4)
#define WGUI_CAT_SLIDE_CONTROL_STRING_MAX_W       (UI_DEVICE_WIDTH >> 1)

/* text viewer category slide buttons */
extern wgui_cat_slide_control_cntx *g_wgui_cat_slide_control_ptr;
extern void wgui_cat_clear_button_bg(void *button);
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */


/***************************************************************************** 
* define
*****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__)
    #define WGUI_CAT_TEXT_VIEWER_TOP_MARGIN                  (10)
    #define WGUI_CAT_TEXT_VIEWER_BOTTOM_MARGIN               (-1)
    #define WGUI_CAT_TEXT_VIEWER_LEFT_MARGIN                 (10)
    #define WGUI_CAT_TEXT_VIEWER_RIGHT_MARGIN                (10)
    #define WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN         (10)
#elif defined(__MMI_MAINLCD_240X400__)
    #define WGUI_CAT_TEXT_VIEWER_TOP_MARGIN                  (10)
    #define WGUI_CAT_TEXT_VIEWER_BOTTOM_MARGIN               (-1)
    #define WGUI_CAT_TEXT_VIEWER_LEFT_MARGIN                 (10)
    #define WGUI_CAT_TEXT_VIEWER_RIGHT_MARGIN                (10)
    #define WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN         (10)
#elif defined(__MMI_MAINLCD_320X480__)
    #define WGUI_CAT_TEXT_VIEWER_TOP_MARGIN                  (15)
    #define WGUI_CAT_TEXT_VIEWER_BOTTOM_MARGIN               (-1)
    #define WGUI_CAT_TEXT_VIEWER_LEFT_MARGIN                 (15)
    #define WGUI_CAT_TEXT_VIEWER_RIGHT_MARGIN                (15)
    #define WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN         (15)
#else
    #define WGUI_CAT_TEXT_VIEWER_TOP_MARGIN                  (10)
    #define WGUI_CAT_TEXT_VIEWER_BOTTOM_MARGIN               (-1)
    #define WGUI_CAT_TEXT_VIEWER_LEFT_MARGIN                 (10)
    #define WGUI_CAT_TEXT_VIEWER_RIGHT_MARGIN                (10)
    #define WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN         (10)
#endif

#define WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_WIDTH             (MMI_SUBMENU_CONTENT_WIDTH - UI_SCROLLBAR_WIDTH - WGUI_CAT_TEXT_VIEWER_LEFT_MARGIN - WGUI_CAT_TEXT_VIEWER_RIGHT_MARGIN)
#define WGUI_CAT_TEXT_VIEWER_IMAGE_MAX_HEIGHT            (MMI_SUBMENU_CONTENT_HEIGHT - (MMI_SINGLELINE_INPUTBOX_HEIGHT << 1))
#define WGUI_CAT_TEXT_VIEWER_IMAGE_MIN_HEIGHT            ((MMI_SUBMENU_CONTENT_HEIGHT >> 1) - WGUI_CAT_TEXT_VIEWER_IMAGE_BOTTOM_MARGIN)


  /****************************************************************************
  * FUNCTION
  *  ShowCategory21Screen
  * Description
  *  Displays a simple text viewer screen by string ID.
  *  [FTE]: support(tool bar is avaiable)
  *
  *  <img name="wgui_cat021_img1" />
  * Parameters
  * title :                 [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * message :               [IN] <UNLIM /> String ID of the text.
  * history_buffer :        [IN] <N/A /> History buffer.
  * Returns
  *  void     
  * Example
  * <code>
  *  void EntryScreen_21(void)
  *  {
  *       U8 *guiBuffer = NULL;
  * 
  *       EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *       ShowCategory21Screen(
  *           STR_ID_CSB_CATEGORY_TEXT,
  *           0,
  *           STR_ID_CSB_LSK_TEXT,
  *           0,
  *           STR_ID_CSB_RSK_TEXT,
  *           0,
  *           STR_ID_CSB_DUMMY_TEXT,
  *           guiBuffer);
  * 
  *       csb_set_key_handlers();
  *  }
  * </code>                                                                
  ****************************************************************************/
    extern void ShowCategory21Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message,
                    U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory21Screen_int(
                   U16 title,
                   U16 title_icon,
                   U16 left_softkey,
                   U16 right_softkey,
                   U16 message,
                   U8 *history_buffer);

#define ShowCategory21Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
           ShowCategory21Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7)
/* DOM-NOT_FOR_SDK-END */

   #define wgui_cat74_is_display_string wgui_is_display_medium_font_string
    extern void RedrawCategory74Screen(void);
    
  /****************************************************************************
  * FUNCTION
  *  ShowCategory74Screen
  * Description
  *  This is a category screen to show a text viewer screen to user.
  *  <FTE: support(tool bar is avaiable) />
  *
  *  <img name="wgui_cat074_img1" />
  * Parameters
  * title :                 [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * buffer :                [IN] <UNLIM /> Text buffer.
  * buffer_length :         [IN] <N/A /> Size of text buffer.
  * history_buffer :        [IN] <N/A /> History buffer.
  * Returns
  *  void           
  * Example
  * <code>
  *  void EntryScreen_74(void)
  *  {
  *      U8 *guiBuffer = NULL;
  *
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      memset(g_buffer, 0, MAX_LOCAL_BUFFER);
  *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category74");
  *
  *      ShowCategory74Screen(
  *          STR_ID_CSB_CATEGORY_TEXT,
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          (U8*) g_buffer,
  *          mmi_ucs2strlen((S8*) g_buffer),
  *          guiBuffer);
  *
  *      csb_set_key_handlers();
  *  }
  * </code>                                                          
  ****************************************************************************/
    extern void ShowCategory74Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *buffer,
                    S32 buffer_length,
                    U8 *history_buffer);
  
/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory74Screen_int(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 right_softkey,
                    U8 *buffer,
                    S32 buffer_length,
                    U8 *history_buffer);
  
#define ShowCategory74Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8) \
             ShowCategory74Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8)
/* DOM-NOT_FOR_SDK-END */


    /* DOM-NOT_FOR_SDK-BEGIN */
    extern void ExitCategory74Screen(void);
    extern U8 *GetCategory74History(U8 *history_buffer);
    extern S32 GetCategory74HistorySize(void);
    /* DOM-NOT_FOR_SDK-END */

  /****************************************************************************
  * FUNCTION
  *  wgui_cat074_change_text.
  * Description
  *  Change the text for category74.
  * Parameters
  * new_string :            [IN] <UNLIM /> Text buffer.
  * buffer_size :           [IN] <N/A /> Size of text buffer.
  * is_reset_y :            [IN] <N/A /> Reset the Y-axis or not, after the text is changed.
  * Returns
  *  void                                                                    
  ****************************************************************************/
    extern void wgui_cat074_change_text(U8 *new_string, S32 buffer_size, MMI_BOOL is_reset_y);

  /****************************************************************************
  * FUNCTION
  *  ShowCategory79Screen
  * Description
  *  Displays a simple text viewer screen by text buffer (No scrollbar and cannot scroll the text).
  *  [FTE]: support(tool bar is avaiable)
  *
  *  <img name="wgui_cat079_img1" />
  * Parameters
  * title :                 [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * buffer :                [IN] <UNLIM /> Text buffer.
  * buffer_length :         [IN] <N/A /> Size of text buffer.
  * history_buffer :        [IN] <N/A /> History buffer.
  * Returns
  *  void     
  * Example
  * <code>
  *  void EntryScreen_79(void)
  *  {
  *      U8 *guiBuffer = NULL;
  * 
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *
  *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category79\r\nCategory79\r\nCategory79\r\nCategory79");
  *      ShowCategory79Screen(
  *          get_string(STR_ID_CSB_CATEGORY_TEXT),
  *          NULL,
  *          get_string(STR_ID_CSB_LSK_TEXT),
  *          NULL,
  *          get_string(STR_ID_CSB_RSK_TEXT),
  *          NULL,
  *          MMI_FALSE,
  *          (UI_buffer_type) g_buffer,
  *          mmi_ucs2strlen((S8*) g_buffer) + 1,
  *          guiBuffer);
  *
  *      csb_set_key_handlers();
  *  }
  * </code>                                                                
  ****************************************************************************/
    extern void ShowCategory79Screen(
                    UI_string_type title,
                    PU8 title_icon,
                    UI_string_type left_softkey,
                    PU8 left_softkey_icon,
                    UI_string_type right_softkey,
                    PU8 right_softkey_icon,
                    MMI_BOOL  scroll_flag,
                    MMI_BOOL is_r2l_display,
                    UI_buffer_type buffer,
                    S32 buffer_length,
                    UI_buffer_type history_buffer);


  /****************************************************************************
  * FUNCTION
  *  wgui_cat079_change_text
  * Description
  *  Change the text for category79.
  * Parameters
  * new_string :            [IN] <UNLIM /> Text buffer.
  * buffer_length :         [IN] <N/A /> Size of text buffer.
  * is_reset_y :            [IN] <N/A /> Reset the Y-axis or not, after the text is changed.
  * scroll_flag :           [IN] <N/A /> Display the scrollbar or not, after the text is changed.
  * Returns
  *  void                                                                    
  ****************************************************************************/
    extern void ChangeCategory79MessageString(U8 *new_string, S32 buffer_size, MMI_BOOL is_reset_y, MMI_BOOL scroll_flag, MMI_BOOL is_r2l_display);
    extern void ChangeCategory79Title(UI_string_type title, U16 title_icon);
  
/*****************************************************************************
  * FUNCTION
  *  wgui_cat79_get_visible_count_bg
  * DESCRIPTION
  *  typesetting without display.
  * PARAMETERS
  *  new_string :     [IN]  <UNLIM /> New content of string
  *  buffer_size :    [IN]  <N/A /> string buffer size
  *  scroll_flag :    [IN]  <N/A /> Need scroll-bar or not
  *  start :          [OUT] <N/A /> The first character in visibel area
  *  end :            [OUT] <N/A /> The last character in visibel area
  * RETURNS
  *  void
  *****************************************************************************/
  extern void wgui_cat79_get_visible_count_bg(
        U8 *new_string, 
        S32 buffer_size, 
        MMI_BOOL scroll_flag,
        S32 *start, 
        S32 *end);
    
/*****************************************************************************
 * FUNCTION
 *  wgui_cat3001_show
 * DESCRIPTION
 *  Displays the category3001 screen, 
 *  category3001 is a text viewer screen with tab bar.
 *  [FTE]: support(tool bar is avaiable)
 *
 *  <img name="wgui_cat3001_img1" />
 * PARAMETERS
 *  tab_title :              [IN] <TITLE /> Title for the screen
 *  left_softkey :           [IN] <LSK /> Left softkey label
 *  left_softkey_icon :      [IN] <N/A /> Icon for the Left softkey
 *  right_softkey :          [IN] <RSK /> Right softkey label
 *  right_softkey_icon :     [IN] <N/A /> Icon for the right softkey
 *  highlighted_tab :        [IN] <N/A /> Highlighted tab
 *  need_scrollbar :         [IN] <N/A /> Text-scroll is allowed or not 
 *  buffer :                 [IN] <UNLIM /> Buffer the input box should use
 *  buffer_size :            [IN] <N/A /> Size of the buffer
 *  history_buffer :         [IN] <N/A /> History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3001_show(
            UI_string_type tab_title,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S8 highlighted_tab,
            MMI_BOOL need_scrollbar,
            UI_buffer_type buffer,
            S32 buffer_length,
            UI_buffer_type history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void wgui_cat3001_show_int(
            UI_string_type tab_title,
            UI_string_type left_softkey,
            UI_string_type right_softkey,
            S8 highlighted_tab,
            MMI_BOOL need_scrollbar,
            UI_buffer_type buffer,
            S32 buffer_length,
            UI_buffer_type history_buffer);
    
#define wgui_cat3001_show(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
               wgui_cat3001_show_int(_arg0, _arg1, _arg3, _arg5, _arg6, _arg7, _arg8, _arg9)
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3002_show
 * DESCRIPTION
 *  Displays the category3001 screen, 
 *  category3002 is a text viewer screen with title and tab bar.
 * PARAMETERS
 *  tab_title               [IN]        Title for the screen
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  highlighted_tab         [IN]        Highlighted tab
 *  need_scrollbar          [IN]        Text-scroll is allowed or not 
 *  buffer                  [IN]        Buffer the input box should use
 *  buffer_length           [IN]        Size of the buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3002_show(
            UI_string_type tab_title,
            UI_string_type left_softkey,
            UI_string_type right_softkey,
            S8 highlighted_tab,
            MMI_BOOL need_scrollbar,
            UI_buffer_type buffer,
            S32 buffer_length,
            UI_buffer_type history_buffer);
        

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3005_show
 * DESCRIPTION
 *  Displays the category3005 screen, 
 *  Text viewer support rich text.
 *  [FTE]: support(tool bar is avaiable)
 *
 *  <img name="wgui_cat03005_img1" />
 * Parameters
 * title :                 [IN] <TITLE /> String ID of title.
 * title_icon :            [IN] <N/A /> Image ID of title icon.
 * left_softkey :          [IN] <LSK /> String ID of left softkey.
 * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
 * right_softkey :         [IN] <RSK /> String ID of right softkey.
 * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
 * buffer :                [IN] <UNLIM /> Text buffer.
 * buffer_length :         [IN] <N/A /> Size of text buffer.
 * history_buffer :        [IN] <N/A /> History buffer.
 * Returns
 *  void           
 * Example
 * <code>
 *  void EntryScreen_3005(void)
 *  {
 *      U8 *guiBuffer = NULL;
 *
 *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 *      memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category3005");
 *
 *      wgui_cat3005_show(
 *          STR_ID_CSB_CATEGORY_TEXT,
 *          0,
 *          STR_ID_CSB_LSK_TEXT,
 *          0,
 *          STR_ID_CSB_RSK_TEXT,
 *          0,
 *          (U8*) g_buffer,
 *          mmi_ucs2strlen((S8*) g_buffer),
 *          guiBuffer);
 *
 *      csb_set_key_handlers();
 *  }
 * </code>  

 *****************************************************************************/
extern void wgui_cat3005_show(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        UI_buffer_type buffer,
        S32 buffer_length,
        UI_buffer_type history_buffer);
        
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_setup_slide_buttons
 * DESCRIPTION
 *  Setup the slide buttons for text viewer screen.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  left_button_string :          [IN] Left button string.
 *  left_button_down_image :      [IN] Left button down image.
 *  left_button_up_image :        [IN] Left button normal image.
 *  left_button_function :        [IN] Left button call back function.
 *  right_button_string :         [IN] Right button string.
 *  right_button_down_image :     [IN] Right button down image.
 *  right_button_up_image :       [IN] Right button normal image.
 *  right_button_function :       [IN] Right button call back function.
 *  middle_string :               [IN] The string between the buttons.
 *  flags :                       [IN] Flags.(Unused)
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_text_viewer_setup_slide_buttons(
            WCHAR* left_button_string,
            PU8 left_button_down_image,
            PU8 left_button_up_image,
            FuncPtr left_button_function,
            WCHAR* right_button_string,
            PU8 right_button_down_image,
            PU8 right_button_up_image,
            FuncPtr right_button_function,
            WCHAR* middle_string,
            U32 flags);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_change_slide_buttons_string
 * DESCRIPTION
 *  Change the text of the slide buttons for text viewer screen.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_text_viewer_change_slide_buttons_string(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_right_slide_button_down
 * DESCRIPTION
 *  Show right button down effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_text_viewer_show_right_slide_button_down(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_left_slide_button_down
 * DESCRIPTION
 *  Show left button down effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_text_viewer_show_left_slide_button_down(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_right_slide_button_up
 * DESCRIPTION
 *  Show right button up effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_text_viewer_show_right_slide_button_up(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_show_left_slide_button_up
 * DESCRIPTION
 *  Show left button up effect.
 *  Only support category74 / 39 / 78.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_text_viewer_show_left_slide_button_up(void);

#define WGUI_CAT_TEXT_VIEWER_LARGE_MARGIN         (0x00000001)
#define WGUI_CAT_TEXT_VIEWER_VERTICAL_CENTER      (0x00000002)
#define WGUI_CAT_TEXT_VIEWER_HORIZONTAL_CENTER    (0x00000004)
#define WGUI_CAT_TEXT_VIEWER_DISABLE_CILPBOARD    (0x00000008)
/*****************************************************************************
 * FUNCTION
*  wgui_cat_setup_special_style
* DESCRIPTION
*  Set the special style
* PARAMETERS
*  style_flags      [IN]       style flags
* RETURNS
*  void
*****************************************************************************/
extern void wgui_cat_setup_special_style(U32 style_flags);

#if defined(__MMI_EBOOK_READER__)
  /****************************************************************************
  * FUNCTION
  *  ShowCategory75Screen
  * Description
  *  Displays the paging Ebook viewer screen.
  *  This function depended on the compile option: __MMI_EBOOK_READER__
  *
  *  <img name="wgui_cat075_img1" />
  * Parameters
  * name :                  [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * buffer :                [IN] <UNLIM /> Text buffer.
  * buffer_size :           [IN] <N/A /> Size of text buffer.
  * history_buffer :        [IN] <N/A /> History buffer.
  * stop_scroll_callback :  [IN] <N/A /> The callback function for auto-scroll.
  * gui_page_info_app :     [IN] <N/A /> The structure for page information.
  * Returns
  *  void         
  * Example
  * <code>
  *  void EntryScreen_75(void)
  *  {
  *      gui_page_info_app ebook_frm_setting_struct_csb;
  *      gui_page_info_app *ebook_frm_setting_csb = &ebook_frm_setting_struct_csb;
  *      
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      memset(g_buffer, 0, MAX_LOCAL_BUFFER);
  *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category75");
  *      
  *      ebook_frm_setting_csb->end_id = 10;
  *      ebook_frm_setting_csb->start_id = 1;
  *      ebook_frm_setting_csb->doc_size = 100;
  *      ebook_frm_setting_csb->last_text_offset_y = 0;
  *      ebook_frm_setting_csb->jump_offset_from_app = 0;
  *      ebook_frm_setting_csb->text_offset = 0;
  *      ebook_frm_setting_csb->scroll_speed = 0;
  *      ebook_frm_setting_csb->scroll_type = 1;
  *      ebook_frm_setting_csb->scroll_flag = 0;
  *      ebook_frm_setting_csb->font_size = 1;
  *      ebook_frm_setting_csb->search_str_len = 3;
  *      ebook_frm_setting_csb->font_style = 0;
  *      ebook_frm_setting_csb->jump_to_end = FALSE;
  *      ebook_frm_setting_csb->highlight_string = FALSE;
  *      ebook_frm_setting_csb->search_flag_is_on = FALSE;
  *      ebook_frm_setting_csb->last_showed_percentage = 10;
  *  #ifdef __MMI_TOUCH_SCREEN__
  *      ebook_frm_setting_csb->key_callback = cat_75_vk_callback;
  *  #endif
  *  
  *      ShowCategory75Screen(
  *          (U16*) GetString(STR_ID_CSB_CATEGORY_TEXT),
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          (U8*) g_buffer,
  *          mmi_ucs2strlen((S8*) g_buffer),
  *          NULL,
  *          NULL,
  *          &ebook_frm_setting_csb);
  *     
  *      csb_set_key_handlers();
  *  }
  * </code>                                                            
  ****************************************************************************/
    extern void ShowCategory75Screen(
                    U16 *name,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer,
                    void (*stop_scroll_callback)(void),
                    gui_page_info_app **);

    extern void ExitCategory75Screen(void);

  /****************************************************************************
  * FUNCTION
  *  ShowCategory77Screen
  * Description
  *  Displays the paging Ebook viewer screen (full screen).
  *  This function depended on the compile option: __MMI_EBOOK_READER__
  *
  *  <img name="wgui_cat077_img1" />
  * Parameters
  * name :                  [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * buffer :                [IN] <UNLIM /> Text buffer.
  * buffer_size :           [IN] <N/A /> Size of text buffer.
  * history_buffer :        [IN] <N/A /> History buffer.
  * stop_scroll_callback :  [IN] <N/A /> The callback function for auto-scroll.
  * gui_page_info_app :     [IN] <N/A /> The structure for page information.
  * Returns
  *  void     
  * Example
  * <code>
  *  void EntryScreen_77(void)
  *  {
  *      gui_page_info_app ebook_frm_setting_struct_csb;
  *      gui_page_info_app *ebook_frm_setting_csb = &ebook_frm_setting_struct_csb;
  *      
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      memset(g_buffer, 0, MAX_LOCAL_BUFFER);
  *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category77");
  *      
  *      ebook_frm_setting_csb->end_id = 10;
  *      ebook_frm_setting_csb->start_id = 1;
  *      ebook_frm_setting_csb->doc_size = 100;
  *      ebook_frm_setting_csb->last_text_offset_y = 0;
  *      ebook_frm_setting_csb->jump_offset_from_app = 0;
  *      ebook_frm_setting_csb->text_offset = 0;
  *      ebook_frm_setting_csb->scroll_speed = 0;
  *      ebook_frm_setting_csb->scroll_type = 1;
  *      ebook_frm_setting_csb->scroll_flag = 0;
  *      ebook_frm_setting_csb->font_size = 1;
  *      ebook_frm_setting_csb->search_str_len = 3;
  *      ebook_frm_setting_csb->font_style = 0;
  *      ebook_frm_setting_csb->jump_to_end = FALSE;
  *      ebook_frm_setting_csb->highlight_string = FALSE;
  *      ebook_frm_setting_csb->search_flag_is_on = FALSE;
  *      ebook_frm_setting_csb->last_showed_percentage = 1;
  *      
  *      ShowCategory77Screen(
  *          (U16*) GetString(STR_ID_CSB_CATEGORY_TEXT),
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          (U8*) g_buffer,
  *          mmi_ucs2strlen((S8*) g_buffer),
  *          NULL,
  *          NULL,
  *          &ebook_frm_setting_csb);
  *            
  *          csb_set_key_handlers();
  *  }
  * </code>                                                                
  ****************************************************************************/
    extern void ShowCategory77Screen(
                    U16 *name,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer,
                    void (*stop_scroll_callback)(void),
                    gui_page_info_app **);

    extern void ExitCategory77Screen(void);

    extern void ShowCategory375Screen(
                    U16 *name,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *history_buffer,
                    void (*stop_scroll_callback)(void),
                    wgui_ml_line_base_info **page_info_app,
                    MMI_BOOL is_fullscreen);
    extern void ExitCategory375Screen(void);
    extern void wgui_category375_redraw_inputbox_and_counter(void);
    extern void wgui_category375_resize_inputbox_and_counter(multi_line_input_box *b, S32 width, S32 height);
    extern void wgui_category375_get_inputbox_and_counter_size(S32 *x, S32 *y, S32 *width, S32 *height);

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_show
 * DESCRIPTION
 *  Displays the linebased category375 screen(For FTE)
 * PARAMETERS
 *  name :                   [IN]   <TITLE /> Title string
 *  title_icon :             [IN]   <N/A /> Icon shown with the title
 *  left_softkey :           [IN]   <LSK /> Left softkey label
 *  left_softkey_icon :      [IN]   <N/A /> Icon for the Left softkey
 *  right_softkey :          [IN]   <RSK /> Right softkey label
 *  right_softkey_icon :     [IN]   <N/A /> Icon for the right softkey
 *  buffer :                 [IN]   <UNLIM /> Buffer the input box should use
 *  buffer_size :            [IN]   <N/A /> Size of the buffer
 *  history_buffer :         [IN]   <N/A /> History buffer
 *  stop_scroll_callback :   [IN]   <N/A /> Stop scroll callback function
 *  page_info_app :          [IN]   <N/A /> Info of page
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3003_show(
        U16 *name,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer,
        void (*stop_scroll_callback)(void),
        wgui_ml_line_base_info **page_info_app,
        MMI_BOOL is_fullscreen);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_register_pen_event_handler
 * DESCRIPTION
 *  set category3003 tap/move event callback function
 * PARAMETERS
 *  tap_event        [IN]        tap event callback function
 *  move_event       [IN]        move_event callback function
 *  pen_down_icon_bar_callback      [IN]        pen down on icon bar callback function
 *  pen_down_icon_bar_callback      [IN]        pen up on icon bar  callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3003_register_pen_event_handler(
void (*tap_event) (void), 
        void (*move_event) (void),
        void (*pen_down_icon_bar_callback) (void), 
        void (*pen_up_icon_bar_callback) (void));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_icon_bar_is_displayed
 * DESCRIPTION
 *  Check the icon bar state in full screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL      Icon bar is displayed or not.
 *****************************************************************************/
extern MMI_BOOL wgui_cat3003_icon_bar_is_displayed(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_counter_is_displayed
 * DESCRIPTION
 *  Check the counter state in full screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL      Icon bar is displayed or not.
 *****************************************************************************/
extern MMI_BOOL wgui_cat3003_counter_is_displayed(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_show_counter
 * DESCRIPTION
 *  draw counter for line-based ebook.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3003_show_counter(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_hide_counter
 * DESCRIPTION
 *  hide counter.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3003_hide_counter(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_update_counter
 * DESCRIPTION
 *  update counter.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3003_update_counter(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_show_floating_iconbar
 * DESCRIPTION
 *  draw floating iconbar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3003_show_floating_iconbar(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3003_hide_floating_iconbar
 * DESCRIPTION
 *  hide floating iconbar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3003_hide_floating_iconbar(void);

#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_TOUCH_SCREEN__
    extern void RedrawCategoryControlledArea75Screen(dm_coordinates *coordinate);
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif /* defined(__MMI_EBOOK_READER__) */ 

/*****************************************************************************
* FUNCTION
*  wgui_cat_ebook_is_full_screen
* DESCRIPTION
*  current screen is full screen ebook or not.
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL wgui_cat_ebook_is_full_screen(void);

    extern void ShowCategory76Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer);

  /****************************************************************************
  * FUNCTION
  *  ShowCategory78Screen
  * Description
  *  Displays a text viewer screen (Transform string to icon is supported).
  *  [FTE]: support(tool bar is avaiable)
  *
  *  <img name="wgui_cat078_img1" />
  * Parameters
  * title :                 [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * icon_callback :         [IN] <N/A /> The callback function for transform string.
  * buffer :                [IN] <UNLIM /> Text buffer.
  * buffer_size :           [IN] <N/A /> Size of text buffer.
  * history_buffer :        [IN] <N/A /> History buffer.
  * Returns
  *  void           
  * Example
  * <code>
  *  void EntryScreen_78(void)
  *  {
  *      U8 *guiBuffer = NULL;
  *      
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      memset(g_buffer, 0, MAX_LOCAL_BUFFER);
  *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category78");
  *      
  *      ShowCategory78Screen(
  *          STR_ID_CSB_CATEGORY_TEXT,
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          NULL,
  *          (U8*) g_buffer,
  *          mmi_ucs2strlen((S8*) g_buffer),
  *          guiBuffer);
  *          
  *      csb_set_key_handlers();
  *  }
  * </code>                                                          
  ****************************************************************************/
    extern void ShowCategory78Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    multi_line_input_box_icon_hdlr icon_callback,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer);
    
/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory78Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                multi_line_input_box_icon_hdlr icon_callback,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);
        
#define ShowCategory78Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9) \
            ShowCategory78Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9)
/* DOM-NOT_FOR_SDK-END */

/* barcode */

  /****************************************************************************
  * FUNCTION
  *  ShowCategory228Screen
  * Description
  *  Displays a text viewer screen (Highlight string is supported).
  *  [FTE]: support(tool bar is avaiable)
  *
  *  <img name="wgui_cat228_img1" />
  * Parameters
  * title :                 [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * buffer :                [IN] <UNLIM /> Text buffer.
  * buffer_size :           [IN] <N/A /> Size of text buffer.
  * hilite_str_list :       [IN] <N/A /> List of highlight string.
  * hilite_str_number :     [IN] <N/A /> Number of highlight string.
  * hilite_cb :             [IN] <N/A /> The callback function of highlight string.
  * history_buffer :        [IN] <N/A /> History buffer.
  * Returns
  *  void        
  * Example
  * <code>
  *  void EntryScreen_228(void)
  *  {
  *      U8 *guiBuffer = NULL;
  *      HILITE_STR *hilite_list = NULL;
  *      
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      
  *      hilite_list = OslMalloc(sizeof(HILITE_STR));
  *      
  *      memset(g_buffer, 0, MAX_LOCAL_BUFFER);
  *      memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);
  *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category228");
  *      
  *      hilite_list->str_addr = (PS8) g_buffer + 4;
  *      hilite_list->length = 6;
  *      
  *      ShowCategory228Screen(
  *          STR_ID_CSB_CATEGORY_TEXT,
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          (PU8) g_buffer,
  *          mmi_ucs2strlen((PS8) g_buffer),
  *          hilite_list,
  *          (U16) 1,
  *          category228_callback,
  *          guiBuffer);
  *      
  *      csb_set_key_handlers();
  *  }
  * </code>                                                             
  ****************************************************************************/
    extern void ShowCategory228Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8* buffer,
                    S32 buffer_size,
                    HILITE_STR hilite_str_list[],
                    U16 hilite_str_number,
                    void (*hilite_cb)(S32 idx),
                    U8* history_buffer);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_text_viewer_set_highlight_click_callback
 * DESCRIPTION
 *  set the highlight text click callback.
 * PARAMETERS
 *  click_cb :               [IN] (N?A) callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_text_viewer_set_highlight_click_callback(void (*click_cb) (S32 idx));

  /****************************************************************************
  * FUNCTION
  *  ShowCategory152Screen
  * Description
  *  Displays the IMEI screen.
  *  [FTE]: support(tool bar is avaiable)
  *
  *  <img name="wgui_cat152_img1" />
  * Parameters
  * title :                 [IN] <TITLE /> String ID of title.
  * title_icon :            [IN] <N/A /> Image ID of title icon.
  * left_softkey :          [IN] <LSK /> String ID of left softkey.
  * left_softkey_icon :     [IN] <N/A /> Image ID of left softkey.
  * right_softkey :         [IN] <RSK /> String ID of right softkey.
  * right_softkey_icon :    [IN] <N/A /> Image ID of right softkey.
  * message :               [IN] <UNLIM /> Text buffer.
  * history_buffer :        [IN] <N/A /> History buffer.
  * Returns
  *  void         
  * Example
  * <code>
  *  void EntryScreen_152(void)
  *  {
  *      U8 *guiBuffer = NULL;
  *      
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category152");
  *      
  *      ShowCategory152Screen(
  *          STR_ID_CSB_CATEGORY_TEXT,
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          (U8*) g_buffer,
  *          guiBuffer);
  *      
  *      csb_set_key_handlers();
  *  }
  * </code>                                                            
  ****************************************************************************/
    extern void ShowCategory152Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory152Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                U8 *message,
                U8 *history_buffer);
            
#define ShowCategory152Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
                ShowCategory152Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7)
/* DOM-NOT_FOR_SDK-END */

    extern void ExitCategory152Screen(void);
    extern S32 GetCategory152HistorySize(void);
    extern U8 *GetCategory152History(U8 *history_buffer);
    
#define WGUI_CAT7_STRING_BUF_SIZE 1024
 /*****************************************************************************
 * FUNCTION
 *  ShowCategory7Screen
 * DESCRIPTION
 *  Displays the category7 screen
 *  [FTE]: support(tool bar is avaiable)
 * 
 * <img name="wgui_cat002_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> Title for the screen
 *   title_icon                    : [IN ] <N/A /> Icon shown with the title
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the left softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the right softkey
 *   message                       : [IN ] <UNLIM /> Notification message (string. Not string ID)
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_7(void)
 * {
 * 
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category 7");
 * 
 *     ShowCategory7Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         (PU8) g_buffer,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * 
 * }
 * </code>
 *****************************************************************************/
    extern void ShowCategory7Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U8 *history_buffer);


/* DOM-NOT_FOR_SDK-BEGIN */
/* Just for backward compatible with the existing category. */
extern void ShowCategory7Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                U8 *message,
                U8 *history_buffer);
            
#define ShowCategory7Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7) \
                ShowCategory7Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7)
/* DOM-NOT_FOR_SDK-END */

/* category 3006 */
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_176X220__)
#define WGUI_CAT3006_CONTROL_AREA_Y       (MMI_STATUS_BAR_HEIGHT)
#define WGUI_CAT3006_CONTROL_AREA_H  (56)
#define WGUI_CAT3006_ML_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_CONTROL_AREA_H)
#define WGUI_CAT3006_ML_H          (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_CAT3006_CONTROL_AREA_Y - WGUI_CAT3006_CONTROL_AREA_H) /*228*/
#define WGUI_CAT3006_PREVIEW_X            (6)
#define WGUI_CAT3006_PREVIEW_W        (76)
#define WGUI_CAT3006_PREVIEW_Y            (WGUI_CAT3006_CONTROL_AREA_Y + 2)
#define WGUI_CAT3006_PREVIEW_H       (52)

#define WGUI_CAT3006_NAME_TIME_GAP  (4)
#define WGUI_CAT3006_NAME_X               (WGUI_CAT3006_PREVIEW_X + WGUI_CAT3006_PREVIEW_W + 5)
#define WGUI_CAT3006_NAME_W           (MAIN_LCD_DEVICE_WIDTH - WGUI_CAT3006_NAME_X-WGUI_CAT3006_PREVIEW_X)
#define WGUI_CAT3006_NAME_H          ((WGUI_CAT3006_CONTROL_AREA_H - 3*WGUI_CAT3006_NAME_TIME_GAP) >> 1)
#define WGUI_CAT3006_NAME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_NAME_TIME_GAP )

#define WGUI_CAT3006_TIME_X               (WGUI_CAT3006_NAME_X)
#define WGUI_CAT3006_TIME_W           (WGUI_CAT3006_NAME_W)
#define WGUI_CAT3006_TIME_H          (WGUI_CAT3006_NAME_H)
#define WGUI_CAT3006_TIME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + (WGUI_CAT3006_NAME_TIME_GAP << 1) + WGUI_CAT3006_NAME_H)

#elif defined(__MMI_MAINLCD_320X240__)
#define WGUI_CAT3006_CONTROL_AREA_Y       (MMI_STATUS_BAR_HEIGHT)
#define WGUI_CAT3006_CONTROL_AREA_H  (74)
#define WGUI_CAT3006_ML_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_CONTROL_AREA_H)
#define WGUI_CAT3006_ML_H          (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_CAT3006_CONTROL_AREA_Y - WGUI_CAT3006_CONTROL_AREA_H) /*228*/
#define WGUI_CAT3006_PREVIEW_X            (6)
#define WGUI_CAT3006_PREVIEW_W        (104)
#define WGUI_CAT3006_PREVIEW_Y            (WGUI_CAT3006_CONTROL_AREA_Y + 2)
#define WGUI_CAT3006_PREVIEW_H       (70)


#define WGUI_CAT3006_NAME_TIME_GAP  (5)
#define WGUI_CAT3006_NAME_X               (WGUI_CAT3006_PREVIEW_X + WGUI_CAT3006_PREVIEW_W + 5)
#define WGUI_CAT3006_NAME_W           (MAIN_LCD_DEVICE_WIDTH - WGUI_CAT3006_NAME_X-WGUI_CAT3006_PREVIEW_X)
#define WGUI_CAT3006_NAME_H          ((WGUI_CAT3006_CONTROL_AREA_H - 3*WGUI_CAT3006_NAME_TIME_GAP) >> 1)
#define WGUI_CAT3006_NAME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_NAME_TIME_GAP )

#define WGUI_CAT3006_TIME_X               (WGUI_CAT3006_NAME_X)
#define WGUI_CAT3006_TIME_W           (WGUI_CAT3006_NAME_W)
#define WGUI_CAT3006_TIME_H          (WGUI_CAT3006_NAME_H)
#define WGUI_CAT3006_TIME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + (WGUI_CAT3006_NAME_TIME_GAP << 1) + WGUI_CAT3006_NAME_H)

#elif defined(__MMI_MAINLCD_240X320__)
#define WGUI_CAT3006_CONTROL_AREA_Y       (MMI_STATUS_BAR_HEIGHT)
#define WGUI_CAT3006_CONTROL_AREA_H  (76)
#define WGUI_CAT3006_ML_Y               (WGUI_CAT3006_CONTROL_AREA_Y+WGUI_CAT3006_CONTROL_AREA_H)
#define WGUI_CAT3006_ML_H          (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_CAT3006_CONTROL_AREA_Y - WGUI_CAT3006_CONTROL_AREA_H)/*(182)*/
#define WGUI_CAT3006_PREVIEW_X            (6)
#define WGUI_CAT3006_PREVIEW_W        (74)
#define WGUI_CAT3006_PREVIEW_Y            (WGUI_CAT3006_CONTROL_AREA_Y + 12) /*29*/
#define WGUI_CAT3006_PREVIEW_H       (56)

#define WGUI_CAT3006_NAME_TIME_GAP  (10)
#define WGUI_CAT3006_NAME_X               (WGUI_CAT3006_PREVIEW_X + WGUI_CAT3006_PREVIEW_W + 5)
#define WGUI_CAT3006_NAME_W           (MAIN_LCD_DEVICE_WIDTH - WGUI_CAT3006_NAME_X-WGUI_CAT3006_PREVIEW_X)
#define WGUI_CAT3006_NAME_H          ((WGUI_CAT3006_CONTROL_AREA_H - 3*WGUI_CAT3006_NAME_TIME_GAP) >> 1)
#define WGUI_CAT3006_NAME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_NAME_TIME_GAP )

#define WGUI_CAT3006_TIME_X               (WGUI_CAT3006_NAME_X)
#define WGUI_CAT3006_TIME_W           (WGUI_CAT3006_NAME_W)
#define WGUI_CAT3006_TIME_H          (WGUI_CAT3006_NAME_H)
#define WGUI_CAT3006_TIME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + (WGUI_CAT3006_NAME_TIME_GAP << 1) + WGUI_CAT3006_NAME_H)

#elif defined(__MMI_MAINLCD_240X400__) /* __MMI_MAINLCD_240X320__ */
#define WGUI_CAT3006_CONTROL_AREA_Y       (MMI_STATUS_BAR_HEIGHT + MMI_TITLE_HEIGHT)
#define WGUI_CAT3006_CONTROL_AREA_H  (66)
#define WGUI_CAT3006_ML_Y               (WGUI_CAT3006_CONTROL_AREA_Y+WGUI_CAT3006_CONTROL_AREA_H)
#define WGUI_CAT3006_ML_H          (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_CAT3006_CONTROL_AREA_Y - WGUI_CAT3006_CONTROL_AREA_H) /*228*/
#define WGUI_CAT3006_PREVIEW_X            (6)
#define WGUI_CAT3006_PREVIEW_W        (74)
#define WGUI_CAT3006_PREVIEW_Y            (WGUI_CAT3006_CONTROL_AREA_Y + 2)
#define WGUI_CAT3006_PREVIEW_H       (56)

#define WGUI_CAT3006_NAME_TIME_GAP  (10)
#define WGUI_CAT3006_NAME_X               (WGUI_CAT3006_PREVIEW_X + WGUI_CAT3006_PREVIEW_W + 5)
#define WGUI_CAT3006_NAME_W           (MAIN_LCD_DEVICE_WIDTH - WGUI_CAT3006_NAME_X-WGUI_CAT3006_PREVIEW_X)
#define WGUI_CAT3006_NAME_H          ((WGUI_CAT3006_CONTROL_AREA_H - 3*WGUI_CAT3006_NAME_TIME_GAP) >> 1)
#define WGUI_CAT3006_NAME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_NAME_TIME_GAP )

#define WGUI_CAT3006_TIME_X               (WGUI_CAT3006_NAME_X)
#define WGUI_CAT3006_TIME_W           (WGUI_CAT3006_NAME_W)
#define WGUI_CAT3006_TIME_H          (WGUI_CAT3006_NAME_H)
#define WGUI_CAT3006_TIME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + (WGUI_CAT3006_NAME_TIME_GAP << 1) + WGUI_CAT3006_NAME_H)

#elif defined(__MMI_MAINLCD_320X480__) /* __MMI_MAINLCD_240X320__ */
#define WGUI_CAT3006_CONTROL_AREA_Y       (MMI_CONTENT_Y)
#define WGUI_CAT3006_CONTROL_AREA_H  (70)
#define WGUI_CAT3006_ML_Y               (WGUI_CAT3006_CONTROL_AREA_Y+WGUI_CAT3006_CONTROL_AREA_H)
#define WGUI_CAT3006_ML_H          (MAIN_LCD_DEVICE_HEIGHT - WGUI_CAT3006_CONTROL_AREA_H - WGUI_CAT3006_CONTROL_AREA_Y - MMI_SOFTKEY_HEIGHT)
#define WGUI_CAT3006_PREVIEW_X            (6)
#define WGUI_CAT3006_PREVIEW_W        (88)
#define WGUI_CAT3006_PREVIEW_Y            (WGUI_CAT3006_CONTROL_AREA_Y + 2)
#define WGUI_CAT3006_PREVIEW_H       (66)

#define WGUI_CAT3006_NAME_TIME_GAP  (4)
#define WGUI_CAT3006_NAME_X               (WGUI_CAT3006_PREVIEW_X + WGUI_CAT3006_PREVIEW_W + 5)
#define WGUI_CAT3006_NAME_W           (MAIN_LCD_DEVICE_WIDTH - WGUI_CAT3006_NAME_X-WGUI_CAT3006_PREVIEW_X)
#define WGUI_CAT3006_NAME_H          ((WGUI_CAT3006_CONTROL_AREA_H - 3*WGUI_CAT3006_NAME_TIME_GAP) >> 1)
#define WGUI_CAT3006_NAME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_NAME_TIME_GAP )

#define WGUI_CAT3006_TIME_X               (WGUI_CAT3006_NAME_X)
#define WGUI_CAT3006_TIME_W           (WGUI_CAT3006_NAME_W)
#define WGUI_CAT3006_TIME_H          (WGUI_CAT3006_NAME_H)
#define WGUI_CAT3006_TIME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + (WGUI_CAT3006_NAME_TIME_GAP << 1) + WGUI_CAT3006_NAME_H)

#else /* __MMI_MAINLCD_240X320__ */ 
#define WGUI_CAT3006_CONTROL_AREA_Y       (MMI_CONTENT_Y)
#define WGUI_CAT3006_CONTROL_AREA_H  (74)
#define WGUI_CAT3006_ML_Y               (WGUI_CAT3006_CONTROL_AREA_Y+WGUI_CAT3006_CONTROL_AREA_H)
#define WGUI_CAT3006_ML_H          (MAIN_LCD_DEVICE_HEIGHT - WGUI_CAT3006_CONTROL_AREA_H - WGUI_CAT3006_CONTROL_AREA_Y - MMI_SOFTKEY_HEIGHT)
#define WGUI_CAT3006_PREVIEW_X            (6)
#define WGUI_CAT3006_PREVIEW_W        (96)
#define WGUI_CAT3006_PREVIEW_Y            (WGUI_CAT3006_CONTROL_AREA_Y + 2)
#define WGUI_CAT3006_PREVIEW_H       (72)

#define WGUI_CAT3006_NAME_TIME_GAP  (4)
#define WGUI_CAT3006_NAME_X               (WGUI_CAT3006_PREVIEW_X + WGUI_CAT3006_PREVIEW_W + 5)
#define WGUI_CAT3006_NAME_W           (MAIN_LCD_DEVICE_WIDTH - WGUI_CAT3006_NAME_X-WGUI_CAT3006_PREVIEW_X)
#define WGUI_CAT3006_NAME_H          ((WGUI_CAT3006_CONTROL_AREA_H - 3*WGUI_CAT3006_NAME_TIME_GAP) >> 1)
#define WGUI_CAT3006_NAME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + WGUI_CAT3006_NAME_TIME_GAP )

#define WGUI_CAT3006_TIME_X               (WGUI_CAT3006_NAME_X)
#define WGUI_CAT3006_TIME_W           (WGUI_CAT3006_NAME_W)
#define WGUI_CAT3006_TIME_H          (WGUI_CAT3006_NAME_H)
#define WGUI_CAT3006_TIME_Y               (WGUI_CAT3006_CONTROL_AREA_Y + (WGUI_CAT3006_NAME_TIME_GAP << 1) + WGUI_CAT3006_NAME_H)
#endif /* __MMI_MAINLCD_240X320__ */ 

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    UI_string_type preview_name;
    UI_string_type preview_time;
    scrolling_text preview_name_scrolling_text;
    PU8 preview_image;
    wgui_multiline_icon_struct icon_table[1];
} wgui_cat3006_context_struct;  

/*****************************************************************************
 * FUNCTION
 *  wgui_cat3006_show
 * DESCRIPTION
 *  Show text viewer screen with preview video.
 *  [FTE]: support(tool bar is not avaiable)
 *
 * PARAMETERS
 *  title :                   [IN] <TITLE /> Title for the screen
 *  title_icon :              [IN] <N/A /> Icon shown with the title
 *  left_softkey :            [IN] <LSK /> Left softkey label
 *  left_softkey_icon :       [IN] <N/A /> Icon for the Left softkey
 *  right_softkey :           [IN] <RSK /> Right softkey label
 *  right_softkey_icon :      [IN] <N/A /> Icon for the right softkey
 *  buffer :                  [IN] <N/A /> Buffer the input box should use
 *  history_buffer :          [IN] <N/A /> History buffer
 *  video_name :              [IN] <N/A /> video name string
 *  video_time :              [IN] <N/A /> video time string
 *  preview_image :           [IN] <N/A /> preview image
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat3006_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        UI_buffer_type buffer,
        UI_buffer_type history_buffer,
        WCHAR* video_name,
        WCHAR* video_time,
        PU8 preview_image,
        U32 icon_position,
        PU8 icon_data,
        HILITE_STR hilite_str_list[],
        U16 hilite_str_number,
        void (*hilite_cb) (S32 idx),
        void (*click_cb) (S32 idx));

#if defined(__SOCIAL_NETWORK_SUPPORT__)
#include "wgui_categories_sns.h"
/*****************************************************************************
 * FUNCTION
 *  wgui_cat74_setup_sns_title
 * DESCRIPTION
 *  setup the sns title.
 * PARAMETERS
 *  wgui_cat_sns_title      [IN]        sns title
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat74_setup_sns_title(wgui_cat_sns_title* title);
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#endif /* __WGUI_CATEGORIES_TEXT_VIEWER_H__ */ 


