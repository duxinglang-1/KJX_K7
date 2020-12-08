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
 *  wgui_categories_clock.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Category header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_CLOCK_H__
#define __WGUI_CATEGORIES_CLOCK_H__

//RHR
    #include "MMIDataType.h"
    #include "wgui_draw_manager.h"
    #include "MMI_features.h"
    #include "kal_general_types.h"
    #include "wgui.h"
    #include "wgui_include.h"

#if !defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)||defined(__MMI_SCREEN_SAVER__)

#if (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__))
#define ANALOG_CLOCK_CATEGORY_FLAG    0
#define DIGITAL_CLOCK_CATEGORY_FLAG   1
#endif /* (__MMI_ANALOG_CLOCK__) || (__MMI_DIGITAL_CLOCK__) */ 



#if (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__))
extern void wgui_category_hide_clock(S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_category_draw_clock_control_area(dm_coordinates *coordinate);
extern void wgui_category_exit_clock_category(void);
extern void wgui_category_show_clock_category(
                U16 title, 
                U16 title_icon, 
                U16 left_softkey, 
                U16 left_softkey_icon, 
                U16 right_softkey, 
                U16 right_softkey_icon, 
                U16 screen_img, 
                U8 *history_buffer,
                U8  clock_types);
#endif /* (__MMI_ANALOG_CLOCK__) || (__MMI_DIGITAL_CLOCK__) */ 

#ifdef __MMI_ANALOG_CLOCK__
/****************************************************************************
  * FUNCTION
  *  ShowCategory86Screen
  * Description
  *  Displays the analog clock, This function depended on the compile option: __MMI_ANALOG_CLOCK__.
  *
  *  <img name="wgui_cat086_img1" />
  * Parameters
  * title :                 [IN] (TITLE(without title button) / C086_1(with title button)) String ID of title.
  * title_icon :            [IN] (N/A) Image ID of title icon.
  * left_softkey :          [IN] (LSK) String ID of left softkey.
  * left_softkey_icon :     [IN] (N/A) Image ID of left softkey.
  * right_softkey :         [IN] (RSK) String ID of right softkey.
  * right_softkey_icon :    [IN] (N/A) Image ID of right softkey.
  * screen_img :            [IN] (N/A) The background image ID.
  * history_buffer :        [IN] (N/A) History buffer.
  * Returns
  *  void    
  * Example
  * <code>
  *  void EntryScreen_86(void)
	*	 {
  *      U8 *guiBuffer = NULL;
  *
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      wgui_set_touch_title_bar_buttons();
  *
  *      ShowCategory86Screen(
  *          STR_ID_CSB_CATEGORY_TEXT,
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          IMG_ID_PHNSET_WP_5,
  *          guiBuffer);
  *
  *      csb_set_key_handlers();
  *  }
  * </code>                                                                 
  ****************************************************************************/
extern void ShowCategory86Screen(
                U16 title, 
                U16 title_icon, 
                U16 left_softkey, 
                U16 left_softkey_icon, 
                U16 right_softkey, 
                U16 right_softkey_icon, 
                U16 screen_img, 
                U8 *history_buffer);
#endif /* __MMI_ANALOG_CLOCK__ */ 

#ifdef __MMI_DIGITAL_CLOCK__
/****************************************************************************
  * FUNCTION
  *  ShowCategory128Screen
  * Description
  *  Displays the digital clock, This function depended on the compile option: __MMI_DIGITAL_CLOCK__.
  *
  *  <img name="wgui_cat128_img1" />
  * Parameters
  * title :                 [IN] (TITLE(without title button) / C128_1(with title button)) String ID of title.
  * title_icon :            [IN] (N/A) Image ID of title icon.
  * left_softkey :          [IN] (LSK) String ID of left softkey.
  * left_softkey_icon :     [IN] (N/A) Image ID of left softkey.
  * right_softkey :         [IN] (RSK) String ID of right softkey.
  * right_softkey_icon :    [IN] (N/A) Image ID of right softkey.
  * screen_img :            [IN] (N/A) The background image ID.
  * history_buffer :        [IN] (N/A) History buffer.
  * Returns
  *  void
  * Example
  * <code>
  *  void EntryScreen_128(void)
	*	 {
  *      U8 *guiBuffer = NULL;
  *
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      wgui_set_touch_title_bar_buttons();
  *
  *      ShowCategory128Screen(
  *          STR_ID_CSB_CATEGORY_TEXT,
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          IMG_ID_PHNSET_WP_3,
  *          guiBuffer);
  *
  *      csb_set_key_handlers();
  *  }
  * </code>                                                               
  ****************************************************************************/
extern void ShowCategory128Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 screen_img,
                U8 *history_buffer);
#endif /* __MMI_DIGITAL_CLOCK__ */ 
#endif /*#if !defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)||defined(__MMI_SCREEN_SAVER__)*/

#ifdef __MMI_SCREEN_SAVER__
/****************************************************************************
  * FUNCTION
  *  ShowCategory131Screen
  * Description
  *  Displays the clock on screensaver screen.
  *
  *  <img name="wgui_cat131_img1" />
  * Parameters
  * icon_screensaver :       [IN] (N/A) The background image ID.
  * screen_saver_type :      [IN] (N/A) The type of screensaver: normal, digital clock, or analog clock.
  * history_buffer :         [IN] (N/A) History buffer.
  * Returns
  *  void    
  * Example
  * <code>
  *  void EntryScreen_131(void)
	*	 {
  *      U16 current_ID;
  *
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *      current_ID = IMG_ID_PHNSET_SS_0;
  *
  *      ShowCategory131Screen(
  *          current_ID,
  *          DIGITAL_SCREEN_SAVER,
  *          NULL);
  *
  *      csb_set_key_handlers();
  *  }
  * </code>                                                                 
  ****************************************************************************/
extern void ShowCategory131Screen(U16 icon_screensaver, U8 screen_saver_type, U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ExitCategory131Screen(void);
/* DOM-NOT_FOR_SDK-END */
#endif /*__MMI_SCREEN_SAVER__*/


#if defined ( __MMI_MAINLCD_240X320__) || defined ( __MMI_MAINLCD_320X240__) ||  defined (__MMI_MAINLCD_240X400__) ||  defined (__MMI_MAINLCD_320X480__) ||  defined (__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    typedef struct
    {
        S32 static_x;
        S32 static_y;
        S32 dynamic_x;
        S32 dynamic_y;
        U8 *static_string;
        U8 *dynamic_string;
        U8 *hint_string;
        U8 *city_string;
        MMI_BOOL need_redraw;//NITZ category
    } cat230_paint_wc_info_struct;



/*****************************************************************************
 * FUNCTION
 *  SetCat230IndexInfo
 * DESCRIPTION
 *  set category index info
 * PARAMETERS
 *   index_num                     : [IN ] (N/A) Index to set info
 *   info_string                   : [IN ] (N/A) Info string to set
 * RETURNS
 *  void
 *****************************************************************************/
    extern void SetCat230IndexInfo(U8 index_num, U8* info_string);
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  RegisterCat230PaintPenEventHandler
 * DESCRIPTION
 *  register 230 category pen event handler
 * PARAMETERS
 *   AppPaintPenEventHandler       : [IN ] (N/A) 
 * RETURNS
 *  void
 *****************************************************************************/
    extern void RegisterCat230PaintPenEventHandler(void (*AppPaintPenEventHandler) (S32 x, S32 y, S32 event_type));
#endif
    extern void Cat230UpdateTime(void);

    extern void ExitCategory230Screen(void);
    extern U8 *GetCategory230History(U8 *history_buffer);
    extern S32 GetCategory230HistorySize(void);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory230Screen
 * DESCRIPTION
 *  category screen of world clock supporting time zones and cities.
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat230_img1" />
 * PARAMETERS
 *   title                         : [IN ] (N/A) Title string
 *   number_of_index               : [IN ] (N/A) Number of index
 *   index_info                    : [IN ] (C230_1) Timezones and cities information
 *   highlighted_index             : [IN ] (N/A) Highlighted index
 *   screen_type                   : [IN ] (N/A) Screen type
 *   left_key_handler              : [IN ] (N/A) Function pointer to app left key handler
 *   right_key_handler             : [IN ] (N/A) Function pointer to app right key handler
 *   get_paint_info                : [IN ] (N/A) Function pointer to get info of non-index area
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_230(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     gIndexInfo[0] = OslMalloc(128);
 *     gIndexInfo[1] = OslMalloc(128);
 *     homeTime = OslMalloc(128);
 *     foreTime = OslMalloc(128);
 * 
 *     memcpy(gIndexInfo[0], (S8*) GetString(STR_ID_CSB_DUMMY_TEXT), 40);
 * 
 * #ifdef __MMI_TOUCH_SCREEN__
 *     RegisterCat230PaintPenEventHandler(mmi_wc_paint_pen_handler);
 * #endif 
 *     ShowCategory230Screen(
 *         (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *         2,
 *         gIndexInfo,
 *         0,
 *         CAT230_WC_DT,
 *         mmi_wc_leftkey_handler,
 *         mmi_wc_rightkey_handler,
 *         mmi_wc_get_index_info);
 * 
 *     ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
 *     ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);
 * 
 *     csb_set_key_handlers();
 * 
 *     OslMfree(gIndexInfo[0]);
 *     OslMfree(gIndexInfo[1]);
 *     OslMfree(homeTime);
 *     OslMfree(foreTime);
 * }
 * </code>
 *****************************************************************************/
    extern void ShowCategory230Screen(
                    U8 *title,
                    U8 number_of_index,
                    U8 **index_info,
                    U8 highlighted_index,
                    U8 screen_type,
                    void (*left_key_handler) (U8 index_num),
                    void (*right_key_handler) (U8 index_num),
                    void (*get_paint_info) (void *paint_info));
#endif
/* NITZ category End */
#if defined (__MMI_FTE_SUPPORT__)
#if defined ( __MMI_MAINLCD_320X480__)

    #define CAT230_TITLE_HEIGHT MMI_TITLE_HEIGHT
    #define CAT230_INDEX_HEIGHT 36 
    #define MAX_CAT230_INDEX    3
    #define CAT230_TIME_HEIGHT  22
    #define CAT230_CITY_HEIGHT  24
    #define CAT230_ARROW_OFFSET 5
	#define CAT230_ARROW_SHIFT  20
    
    #elif defined (__MMI_MAINLCD_240X400__)
    
    #define CAT230_TITLE_HEIGHT MMI_TITLE_HEIGHT
    #define CAT230_INDEX_HEIGHT 32
    #define MAX_CAT230_INDEX    3
    #define CAT230_TIME_HEIGHT  22
    #define CAT230_CITY_HEIGHT  22
    #define CAT230_ARROW_OFFSET 5
    #define CAT230_ARROW_SHIFT  15
    
    #else
    
    #define CAT230_TITLE_HEIGHT MMI_TITLE_HEIGHT
    #define CAT230_INDEX_HEIGHT 29
    #define MAX_CAT230_INDEX    3
    #define CAT230_TIME_HEIGHT  20
    #define CAT230_CITY_HEIGHT  21
    #define CAT230_ARROW_OFFSET 5
	#define CAT230_ARROW_SHIFT  8
    
    #endif
    
#elif defined ( __MMI_MAINLCD_320X480__)

#define CAT230_TITLE_HEIGHT 44
#define CAT230_INDEX_HEIGHT 36
#define MAX_CAT230_INDEX    3
#define CAT230_TIME_HEIGHT  29
#define CAT230_CITY_HEIGHT  30
#define CAT230_ARROW_OFFSET 5
#define CAT230_ARROW_SHIFT  10

#elif defined ( __MMI_MAINLCD_240X320__)

#define CAT230_TITLE_HEIGHT 28
#define CAT230_INDEX_HEIGHT 24
#define MAX_CAT230_INDEX    3
#define CAT230_TIME_HEIGHT  19
#define CAT230_CITY_HEIGHT  21
#define CAT230_ARROW_OFFSET 5
#define CAT230_ARROW_SHIFT  8

#elif defined (__MMI_MAINLCD_320X240__)

#define CAT230_TITLE_HEIGHT 28
#define CAT230_INDEX_HEIGHT 22
#define MAX_CAT230_INDEX    3
#define CAT230_TIME_HEIGHT  20
#define CAT230_CITY_HEIGHT  21
#define CAT230_ARROW_OFFSET 5
#define CAT230_ARROW_SHIFT  10

#elif defined (__MMI_MAINLCD_240X400__)

#define CAT230_TITLE_HEIGHT 46
#define CAT230_INDEX_HEIGHT 28
#define MAX_CAT230_INDEX    3
#define CAT230_TIME_HEIGHT  28
#define CAT230_CITY_HEIGHT  28
#define CAT230_ARROW_OFFSET 5
#define CAT230_ARROW_SHIFT  10

#elif defined (__MMI_MAINLCD_360X640__)

#define CAT230_TITLE_HEIGHT 46
#define CAT230_INDEX_HEIGHT 28
#define MAX_CAT230_INDEX    3
#define CAT230_TIME_HEIGHT  28
#define CAT230_CITY_HEIGHT  28
#define CAT230_ARROW_OFFSET 5
#define CAT230_ARROW_SHIFT  10
#elif defined (__MMI_MAINLCD_480X800__)

#define CAT230_TITLE_HEIGHT 46
#define CAT230_INDEX_HEIGHT 28
#define MAX_CAT230_INDEX    3
#define CAT230_TIME_HEIGHT  28
#define CAT230_CITY_HEIGHT  28
#define CAT230_ARROW_OFFSET 5
#define CAT230_ARROW_SHIFT  10
#endif   
// baiwenlin 20130821  
#if defined ( __MMI_MAINLCD_128X128__) || defined ( __MMI_MAINLCD_128X160__) ||  defined (__MMI_MAINLCD_176X220__) ||  defined (__MMI_MAINLCD_480X800__)|| defined (__MMI_MAINLCD_128X64__)|| defined (__MMI_MAINLCD_128X36__)|| defined (__MMI_MAINLCD_240X240__)

typedef struct 
{
    S32 x;
    S32 y;
    MMI_ID_TYPE  curMap;
    U8 *title_string;
    U8 *date_string;
    U8 *time_string;
    MMI_ID_TYPE day_image;
}cat231_paint_wc_info_struct;



/*****************************************************************************
 * FUNCTION
 *  ShowCategory231Screen
 * DESCRIPTION
 *  category screen of world clock supporting cities only.
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat231_img1" />
 * PARAMETERS
 *   left_key_handler              : [IN ] (N/A) Function pointer to app left key handler
 *   right_key_handler             : [IN ] (N/A) Function pointer to app right key handler
 *   get_paint_info                : [IN ] (N/A) Function pointer to get info of non-index area
 *   show_status_icons             : [IN ] (N/A) Flag indicating if category should show status bar
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_231(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 * #ifdef __MMI_TOUCH_SCREEN__
 *	   RegisterCat231PaintPenEventHandler(mmi_wc_paint_pen_handler);
 * #endif
 *
 *	   ShowCategory231Screen(
 *         mmi_wc_leftkey_handler, 
 *		   mmi_wc_rightkey_handler, 
 *		   mmi_wc_get_index_info,
 *	     #ifdef __MMI_WC_NO_STATUSBAR__
 *		   MMI_FALSE
 *		 #else
 *		   MMI_TRUE
 *		 #endif
 *	   );
 * 
 *     ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
 *     ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);
 * 
 *     csb_set_key_handlers();
 * 
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory231Screen(
        void (*left_key_handler) (void),
        void (*right_key_handler) (void),
        void (*get_paint_info) (void *paint_info),
        MMI_BOOL show_status_icons);



/*****************************************************************************
 * FUNCTION
 *  Cat231UpdateDT
 * DESCRIPTION
 *  Function to update date and time information of category 231
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
extern void Cat231UpdateDT(void);


/*****************************************************************************
 * FUNCTION
 *  Cat231Redraw
 * DESCRIPTION
 *  Function to redraw controlled area of category 231
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
extern void Cat231Redraw(void);


#endif /* defined ( __MMI_MAINLCD_128X128__) || defined ( __MMI_MAINLCD_128X160__) ||  defined (__MMI_MAINLCD_176X220__) */

#endif /* __WGUI_CATEGORIES_CLOCK_H__ */ 


