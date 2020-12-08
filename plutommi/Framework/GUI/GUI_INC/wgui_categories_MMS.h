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
 *  wgui_categories_MMS.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS related categories. 
 *
 *  [Category275]       MMS SMIL editor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_MMS_H__
#define __WGUI_CATEGORIES_MMS_H__

//RHR
    #include "wgui_categories_inputs.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gui_data_types.h"
    #include "wgui.h"
    #include "wgui_draw_manager.h"

#ifndef __WGUI_CATEGORIES_INPUTS_H__
#error "wgui_categories_inputs.h should be included before wgui_categories_MMS.h "
#endif 


/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef void (*wgui_cat275_draw_title_hdlr) (U32 identifier);
typedef void (*wgui_cat275_draw_area_hdlr) (U32 identifier, S32 y_offset, S32 clip_x1, S32 clip_y1, S32 clip_x2,
                                            S32 clip_y2);

typedef void (*wgui_cat275_draw_area_hdlr_ex) (U32 identifier, S32 y_offset, S32 clip_x1, S32 clip_y1, S32 clip_x2,
                                            S32 clip_y2, MMI_BOOL is_draw);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  RedrawCategory275Screen
 * DESCRIPTION
 *  Redraws the category275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void RedrawCategory275Screen(void);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory275Screen
 * DESCRIPTION
 *  Displays the category275 screen
 * 
 * <img name="wgui_cat275_img1" />
 * PARAMETERS
 *   identifier                    : [IN ] (N/A) Used as parameter for the callback functions described before
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   input_type                    : [IN ] (N/A) Type of input to use
 *   buffer                        : [IN ] (UNLIM) Buffer the input box should use.
 *   buffer_size                   : [IN ] (N/A) Size of the buffer.
 *   vbar_width                    : [IN ] (N/A) Width of vertical bar
 *   draw_title_fp                 : [IN ] (N/A) Function pointer to draw the title bar
 *   draw_area_1_height            : [IN ] (N/A) Height of the area where picture is to be shown
 *   draw_area_1_fp                : [IN ] (N/A) Function to draw the picture in area1
 *   draw_area_2_height            : [IN ] (N/A) Text area height
 *   draw_area_2_fp                : [IN ] (N/A) Function to insert the text
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * </code>
 *****************************************************************************/
extern void ShowCategory275Screen(
                U32 identifier,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U16 vbar_width,
                wgui_cat275_draw_title_hdlr draw_title_fp,
                U16 draw_area_1_height,
                wgui_cat275_draw_area_hdlr draw_area_1_fp,
                U16 draw_area_2_height,
                wgui_cat275_draw_area_hdlr draw_area_2_fp,
                U8 *history_buffer);



/*****************************************************************************
 * FUNCTION
 *  ShowCategory277Screen
 * DESCRIPTION
 *  Displays the category277 screen
 * 
 * <img name="wgui_cat277_img1" />
 * PARAMETERS
 *   identifier                    : [IN ] (N/A) Used as parameter for the callback functions described before
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   input_type                    : [IN ] (N/A) Type of input to use
 *   buffer                        : [IN ] (UNLIM) Buffer the input box should use.
 *   buffer_size                   : [IN ] (N/A) Size of the buffer.
 *   vbar_width                    : [IN ] (N/A) Width of vertical bar
 *   draw_title_fp                 : [IN ] (N/A) Function pointer to draw the title bar
 *   draw_area_1_height            : [IN ] (N/A) Height of the area where picture is to be shown
 *   draw_area_1_fp                : [IN ] (N/A) Function to draw the picture in area1
 *   draw_area_2_height            : [IN ] (N/A) Text area height
 *   draw_area_2_fp                : [IN ] (N/A) Function to insert the text
 *   text_font                     : [IN ] (N/A) Text font
 *   text_color                    : [IN ] (N/A) Text color
 *   selected_text_color           : [IN ] (N/A) Selected text color
 *   bg_color                      : [IN ] (N/A) Background color
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_277(void)
 * {
 *     U8 *gui_buffer = NULL;
 *     U16 area1_height, area2_height;
 *     stFontAttribute editor_font = MMI_small_font;
 *     UI_font_type text_font;
 *     color text_color = {0, 0, 0, 100};
 *     color selected_text_color = {0, 255, 0, 100};
 *     color bg_color = {255, 255, 255, 100};
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     text_font = &editor_font;
 * 
 *     memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category277");
 * 
 *     area1_height = 110;
 *     area2_height = 0;
 * 
 *     ShowCategory277Screen(
 *         1,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         IMM_INPUT_TYPE_SENTENCE,
 *         (U8*) g_buffer,
 *         (S32) 20,
 *         (U16) 10,
 *         mmi_show_editor_title,
 *         area1_height,
 *         mmi_show_editor_draw_area_1,
 *         area2_height,
 *         mmi_show_editor_draw_area_2,
 *         &text_font,
 *         &text_color,
 *         &selected_text_color,
 *         &bg_color,
 *         gui_buffer);
 * 
 *     SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
 *     SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory277Screen(
                U32 identifier,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U16 vbar_width,
                wgui_cat275_draw_title_hdlr draw_title_fp,
                U16 draw_area_1_height,
                wgui_cat275_draw_area_hdlr draw_area_1_fp,
                U16 draw_area_2_height,
                wgui_cat275_draw_area_hdlr draw_area_2_fp,
                UI_font_type *text_font,
                color *text_color,
                color *selected_text_color,
                color *bg_color,
                U8 *history_buffer);

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) || defined(__MMI_SMART_MESSAGE_MT__)
extern void ShowCategoryNSM275Screen(
                U32 identifier,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U16 vbar_width,
                wgui_cat275_draw_title_hdlr draw_title_fp,
                U16 draw_area_1_height,
                wgui_cat275_draw_area_hdlr draw_area_1_fp,
                U16 draw_area_2_height,
                wgui_cat275_draw_area_hdlr draw_area_2_fp,
                U8 *history_buffer);
extern void ExitCategoryNSM275Screen(void);
extern void RedrawCategoryNSM275Screen(void);

#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) || defined(__MMI_SMART_MESSAGE_MT__) */ 



/*****************************************************************************
 * FUNCTION
 *  ExitCategory275Screen
 * DESCRIPTION
 *  Exits the category275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ExitCategory275Screen(void);


/*****************************************************************************
 * FUNCTION
 *  GetCategory275HistorySize
 * DESCRIPTION
 *  Gets the size of the history buffer for category275 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
extern S32 GetCategory275HistorySize(void);


/*****************************************************************************
 * FUNCTION
 *  GetCategory275History
 * DESCRIPTION
 *  Gets the history buffer for category275 screen
 * PARAMETERS
 *   history_buffer                : [IN ] (N/A) Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  Pointer to the history buffer
 *****************************************************************************/
extern U8 *GetCategory275History(U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  SetCategory275RightSoftkeyFunction
 * DESCRIPTION
 *  right softkey function
 * PARAMETERS
 *  f                              : [IN ] (N/A) Function
 *  k                              : [IN ] (N/A) Event type
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory275RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
/* DOM-NOT_FOR_SDK-BEGIN */ 
#define SetCategory275RightSoftkeyFunction(_arg0, _arg1) wgui_inputs_category_set_rsk_func(_arg0)
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  Category275GotoTop
 * DESCRIPTION
 *  Invoked after ShowCategory275Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category275GotoTop(void);


/*****************************************************************************
 * FUNCTION
 *  Category275GotoBottom
 * DESCRIPTION
 *  Invoked after ShowCategory275Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category275GotoBottom(void);


/*****************************************************************************
 * FUNCTION
 *  Category275SetUnmodified
 * DESCRIPTION
 *  Set that category 275 is unmodified.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category275SetUnmodified(void);


/*****************************************************************************
 * FUNCTION
 *  Category275CheckIfModified
 * DESCRIPTION
 *  Get is modified
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether category 275 is modified.
 *****************************************************************************/
extern BOOL Category275CheckIfModified(void);


extern color(*category275_get_bg_color) (void);         /* to set background color */
extern color(*category275_get_text_color) (void);       /* to set editor text color. */
extern UI_font_type(*category275_get_text_font) (void); /* to set editor text font. */


/*****************************************************************************
 * FUNCTION
 *  AppendCategory275String
 * DESCRIPTION
 *  append the string in category 275 (editor) text
 * PARAMETERS
 *   input_type                    : [IN ] (N/A) Input ype
 *   buffer                        : [IN ] (UNLIM) Buffer
 *   buffer_size                   : [IN ] (N/A) Buffer isze
 *   s                             : [IN ] (N/A) String
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void AppendCategory275String(U32 input_type, U8 *buffer, S32 buffer_size, U8 *s, U8 *history_buffer);



/*****************************************************************************
 * FUNCTION
 *  RedrawCategory276Screen
 * DESCRIPTION
 *  redraw category screen 276
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void RedrawCategory276Screen(void);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory276Screen
 * DESCRIPTION
 *  This category screen is used in MMS. It is just an blank screen.
 * 
 * <img name="wgui_cat276_img1" />
 * PARAMETERS
 *   title                         : [IN ] (N/A) Title string
 *   title_icon                    : [IN ] (N/A) Title icon
 *   left_softkey                  : [IN ] (N/A) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Icon for the left softkey
 *   right_softkey                 : [IN ] (N/A) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_276(void)
 * {
 *     U8 *gui_buffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     wgui_set_touch_title_bar_buttons();
 * 
 *     ShowCategory276Screen(
 *         (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *         0,
 *         0,
 *         0,
 *         0,
 *         0,
 *         gui_buffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory276Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  DrawCat276SlidingBar
 * DESCRIPTION
 *  Draw category 276 sliding bar.
 * PARAMETERS
 *   percentage                    : [IN ] (N/A) percentage of silding bar
 * RETURNS
 *  void
 *****************************************************************************/
extern void DrawCat276SlidingBar(U8 percentage);



/*****************************************************************************
 * FUNCTION
 *  ExitCategory276Screen
 * DESCRIPTION
 *  Exit category276 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ExitCategory276Screen(void);


/*****************************************************************************
 * FUNCTION
 *  DrawCat276TitleButton
 * DESCRIPTION
 *  This function is used to draw the buttons
 * PARAMETERS
 *   index                         : [IN ] (N/A) Index of the buttons to be drawn
 * RETURNS
 *  void
 *****************************************************************************/
extern void DrawCat276Title(U8 *title);


/*****************************************************************************
 * FUNCTION
 *  dm_category_276_controlled_area
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category screen
 * PARAMETERS
 *   coordinate                    : [IN/OUT] (N/A) Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
extern void dm_category_276_controlled_area(dm_coordinates *coordinate);

#endif /* __WGUI_CATEGORIES_MMS_H__ */ 


