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
 *  wgui_categories_email.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Email related categories
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

#include "MMI_features.h"
#ifdef __MMI_SCREEN_ROTATE__
#include "ScreenRotationGprot.h"
#endif  
#include "wgui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menus.h"
#include "gui_font_size.h"

/*RHR*/
    #include "CustThemesRes.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gui_data_types.h"
    #include "wgui_categories_util.h"
    #include "wgui_include.h"
    #include "wgui_fixed_menus.h"
    #include "gui_windows.h"
    #include "wgui_categories_fmgr.h"
    #include "PixcomFontEngine.h"
    #include "gui.h"
    #include "gdi_include.h"
    #include "wgui_inputs.h"
    #include "gui_typedef.h"
    #include "wgui_categories_email.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "wgui_draw_manager.h"
    #include "wgui.h"
    #include "wgui_categories_enum.h"
    #include "gui_fixed_menus.h"
    #include "CustDataRes.h"
    #include "gui_switch.h"
    #include "gui_config.h"
    #include "gui_scrollbars.h"
    #include "gui_themes.h"
    #include "FontRes.h"
    #include "gui_fixed_menuitems.h"
    #include "wgui_asyncdynamic_menuitems.h"
    #include "mmi_frm_history_gprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalResDef.h"
    #include "wgui_categories_list.h"
    #include "wgui_categories_CM.h"
    #include "wgui_categories.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
/*RHR end*/

//extern BOOL r2lMMIFlag;
extern S32 g_cat_tab_num;

extern void reset_fixed_list_show_empty(void);
extern void disable_fixed_list_show_empty(void);

static void wgui_cat268_resume_scroll(void);
#ifdef __GEMINI__
static MMI_BOOL wgui_cat_list_get_display_more_icon(void);
#endif

#if defined(__MMI_FTE_SUPPORT__)
static MMI_BOOL mmi_cat263_show = MMI_FALSE;
#endif /* __MMI_FTE_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  wgui_async_dynamic_list_exit
 * DESCRIPTION
 *  common exit category function of async dynamic list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_async_dynamic_list_exit(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    reset_fixed_list_show_empty();
}


/*****************************Category 251 Start*******************************/
#define _EMAIL_ENABLE_SECOND_STR_SCROLL_  1
#define UI_CATEGORY251_INFOBOX_HEIGHT 32
#define CAT267_MARGIN_GAP   2

#if defined(__MMI_MAINLCD_320X480__)
  #define WGUI_CAT261_GAP 6
#elif defined(__MMI_MAINLCD_240X400__)
  #define WGUI_CAT261_GAP 0
#else
  #define WGUI_CAT261_GAP 1
#endif  /* __MMI_MAINLCD_320X480__*/

static U8 *category_251_info_text1;
static U8 *category_251_info_text2;
static scrolling_text scroll_text_cat251;

#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)
static scrolling_text scroll_text_cat251A;
#endif 
/*****************************************************************************
 * FUNCTION
 *  cat251scrolling_timer
 * DESCRIPTION
 *  timer callback of category251 scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat251scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&scroll_text_cat251);
}

#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)


/*****************************************************************************
 * FUNCTION
 *  cat251scrolling_timerA
 * DESCRIPTION
 *  category 251 scrolling timer handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cat251scrolling_timerA(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&scroll_text_cat251A);
}
#endif /* (_EMAIL_ENABLE_SECOND_STR_SCROLL_) */ 


/*****************************************************************************
 * FUNCTION
 *  cat251_scrolling_text_draw_background
 * DESCRIPTION
 *  draw background callback function of scrolling text of category251
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void cat251_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X128__)    
    color c = gui_color(159, 159, 255);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X128__)        
    gui_fill_rectangle(x1, y1, x2, y2, c);
#else
    FillFullTextBackground(x1, y1, x2, y2);
#endif
}

#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)


/*****************************************************************************
 * FUNCTION
 *  cat251_scrolling_text_draw_backgroundA
 * DESCRIPTION
 *  Draw category 251 scrolling text draw background
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
void cat251_scrolling_text_draw_backgroundA(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X128__)       
    color c = gui_color(159, 159, 255);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X128__)      
    gui_fill_rectangle(x1, y1, x2, y2, c);
#else
    FillFullTextBackground(x1,y1,x2,y2);
#endif
}
#endif /* (_EMAIL_ENABLE_SECOND_STR_SCROLL_) */ 


/*****************************************************************************
 * FUNCTION
 *  DrawCategory251InfoBox
 * DESCRIPTION
 *  Draw the info text box for category 251
 * PARAMETERS
 *  info_string1        [IN]         String1 to draw
 *  info_string2        [IN]         String2 to draw
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCategory251InfoBox(U8 *info_string1, U8 *info_string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    stFontAttribute *f = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE);
    S32 fh, w, w1, h, h1, fh1;
	S32 var, below_title = MMI_title_y + MMI_title_height;

#if defined (__MMI_FTE_SUPPORT__)
    stFontAttribute sf = MMI_small_font;
    stFontAttribute df = MMI_default_font;
#endif /* __MMI_FTE_SUPPORT__ */
#if defined (__MMI_MAINLCD_128X128__)
	UI_filled_area color_dialog_bg = {
	    UI_FILLED_AREA_TYPE_COLOR,
		UI_NULL_IMAGE,
		NULL,
		{159, 159, 255, 100},
		{0, 0, 0, 0},
		{0, 0, 0, 100},
		{50, 50, 50, 100},
		0
	};
#endif /* __MMI_MAINLCD_128X128__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(f);

#if defined (__MMI_FTE_SUPPORT__)
    if(mmi_cat263_show) 
    {
        gui_set_font((UI_font_type)&sf);
		var = sf.size;
    }
    else
    {
        var = f->size;
    }
#else /* __MMI_FTE_SUPPORT__ */
    var = f->size;
#endif /* __MMI_FTE_SUPPORT__ */
    fh1 = Get_CharHeightOfAllLang((U8)var);
    fh = fh1 * 2 + 5;
	
    gdi_layer_lock_frame_buffer();
    gdi_layer_reset_clip();

#if defined(__MMI_MAINLCD_128X128__)  
    c = gui_color(255, 255, 255);
    gui_fill_rectangle(
        0,
        (below_title),
        (UI_device_width - 1),
        (below_title + fh - 1),
        c);
    color_dialog_bg.flags |= UI_FILLED_AREA_BORDER;
    color_dialog_bg.flags |= UI_FILLED_AREA_ROUNDED_BORDER;
    gui_draw_filled_area(
        1,
        (below_title + 1),
        (UI_device_width - 2),
        (below_title + fh - 2),
        &color_dialog_bg);
#else
    DrawTextAreaBackground(
        0,
        (below_title),
        (UI_device_width - 1),
        (below_title + fh - 1));
#endif

#if defined(__MMI_FTE_SUPPORT__)
    c = gui_color(255, 255, 255);
#else
    c = gui_color(0, 0, 0);
#endif

    gdi_layer_set_clip(
        1,
        (below_title),
        (UI_device_width - 2),
        (below_title + fh - 1));
    gui_set_text_color(c);
    gui_measure_string((UI_string_type) info_string1, &w, &h);
    if (h == 0)
    {
        h = fh1;
    }

    var = below_title + (2 + ((fh1 - h) >> 1));
    if (w < UI_device_width - 10)
    {
        w = 5;
        if (mmi_fe_get_r2l_state())
        {
            w = UI_device_width - 4;
        }
        gui_move_text_cursor(w, var);
        gui_print_text((UI_string_type) info_string1);
    }
    else
    {
        flag_scroll = TRUE;
        gui_create_scrolling_text(&scroll_text_cat251, 5, var, (UI_device_width - 10), h, (UI_string_type) info_string1, cat251scrolling_timer, cat251_scrolling_text_draw_background, c, gui_color(255, 255, 255));  /* 120204 Calvin modified for calculate the height of the info box */
        gui_show_scrolling_text(&scroll_text_cat251);
    }

#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)
    gui_measure_string((UI_string_type) info_string2, &w1, &h1);
#endif 

    var = below_title + (fh >> 1) + 1 + ((fh1 - h1) >> 1);
#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)
    if (w1 < UI_device_width - 10)
    {
#endif /* (_EMAIL_ENABLE_SECOND_STR_SCROLL_) */ 
        w1 = 5;
        if (mmi_fe_get_r2l_state())
        {
            w1 = UI_device_width - 4;
        }
		gui_move_text_cursor(w1, var);
        gui_print_text((UI_string_type) info_string2);
        
#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)
    }
    else
    {
        flag_scroll = TRUE;
        gui_create_scrolling_text(&scroll_text_cat251A, 5, var, (UI_device_width - 10), h1, (UI_string_type) info_string2, cat251scrolling_timerA, cat251_scrolling_text_draw_backgroundA, c, gui_color(255, 255, 255));  
        gui_show_scrolling_text(&scroll_text_cat251A);
    }
#endif /* (_EMAIL_ENABLE_SECOND_STR_SCROLL_) */ 
	
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

#if defined (__MMI_FTE_SUPPORT__)
    if(mmi_cat263_show)
    {
        gui_set_font((UI_font_type)&df);
    }
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory251InfoBox
 * DESCRIPTION
 *  Set the info text box strings to be display and redraw category 251
 * PARAMETERS
 *  infoText1       [IN]         infotext 1 to redraw
 *  infoText2       [IN]         infotext 2 to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory251InfoBox(U8 *infoText1, U8 *infoText2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    category_251_info_text1 = infoText1;
    gui_scrolling_text_stop(&scroll_text_cat251);
    category_251_info_text2 = infoText2;

#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)
    gui_scrolling_text_stop(&scroll_text_cat251A);
#endif 

    DrawCategory251InfoBox(category_251_info_text1, category_251_info_text2);
}

/* Dynamic Multi String/Iconic List */
extern S32 gui_asyncdynamic_list_error;

/*----------------------------Async Dynamic Multi Row List-----------------------------*/

#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
static S32 mmi_cat263_display_style = MMI_CAT261_DISPLAY_THREE_LINE;
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat261_set_display_style
 * DESCRIPTION
 *  set display flag of cateogyr261
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat261_set_display_style(S32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((style >= CAT261_DISPLAY_THREE_LINE) && (style <= CAT261_DISPLAY_TWO_LINE));
#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    mmi_cat263_display_style = style;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory261Screen
 * DESCRIPTION
 *  Exit category 261
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory261Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_async_dynamic_list_exit();
#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    mmi_cat263_display_style = MMI_CAT261_DISPLAY_THREE_LINE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory261Screen
 * DESCRIPTION
 *  Show category 261
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  list_icon               [IN]        Icon of list
 *  attach_icon             [IN]        Attach icon
 *  history_buffer          [IN]        History buffer
 *  no_of_string            [IN]        string count
 *  no_of_icons             [IN]        icon count
 *  category_error_flag     [OUT]       error flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory261Screen(
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
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 img;
    S32 h, w, h1, w1, text_width;
#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    S32 font_height_m, font_height_s;
    S32 ty = 0;
#endif
    S32 icon0_y = 0;
    S32 list_height = MMI_content_height;
    U8 h_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* Reset The Error Variable */
    gui_asyncdynamic_list_error = 0;
    /* Set The Application Side Variable To True */
    *category_error_flag = 1;

    gdi_layer_lock_frame_buffer();
	dm_add_title((UI_string_type)title, get_image(title_icon));
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        no_of_string,
        no_of_icons,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MULTIROW_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_MULTIROW,
        0,
        NULL);

    h_flag = set_list_menu_category_history(MMI_CATEGORY261_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

    img = (U8*) GetImage(list_icon);
    gui_measure_image(img, &w, &h);

    if (w == 0)
    {
        w = 30;
    }
    if (h == 0)
    {
        h = 30;
    }

    img = (U8*) GetImage(attach_icon);
    gui_measure_image(img, &w1, &h1);

    if (w1 == 0)
    {
        w1 = 9;
    }
    if (h1 == 0)
    {
        h1 = 9;
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif/*__MMI_ICON_BAR_SUPPORT__*/
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - w - GUI_MENUITEM_TEXT_RIGHT_GAP - 4;
    if(MMI_MULTIROW_MENUITEM_HEIGHT > h)
    {
        icon0_y = (MMI_MULTIROW_MENUITEM_HEIGHT - h) >> 1;
    }
#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    gui_set_font(&MMI_small_font);
    font_height_s = gui_get_character_height();
    gui_set_font(&MMI_medium_font);
    /* It may contain non-alphanumeric characters like Chinese */
    font_height_m = Get_CharHeightOfAllLang(MEDIUM_FONT);
    set_fixed_icontext_list_icon_coordinates(0, 1, icon0_y, w, h);
    
    if(no_of_icons == 1)
    {
        if(mmi_cat263_display_style == MMI_CAT261_DISPLAY_THREE_LINE)
        {
            MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_default_font;
            set_fixed_icontext_list_text_coordinates(0, (3 + w), ((MMI_MULTIROW_MENUITEM_HEIGHT >> 1) - font_height_m) >> 1, text_width, font_height_m);
            set_fixed_icontext_list_text_coordinates(1, (3 + w), (((MMI_MULTIROW_MENUITEM_HEIGHT >> 1) - font_height_m) >> 1) + (MMI_MULTIROW_MENUITEM_HEIGHT >> 1), text_width, font_height_m);
        }
        else if(mmi_cat263_display_style == MMI_CAT261_DISPLAY_TWO_LINE)
        {
            MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
            ty = (MMI_MULTIROW_MENUITEM_HEIGHT - (font_height_m<<1))/3;

            set_fixed_icontext_list_text_coordinates(0, (3 + w), ty, text_width, font_height_m);
            set_fixed_icontext_list_text_coordinates(1, (3 + w), (ty<<1) + font_height_m, text_width, font_height_m);
        }
        else
        {
            MMI_ASSERT(MMI_FALSE);
        }
    }
    else
    {
        set_fixed_icontext_list_text_coordinates(0, (3 + w), WGUI_CAT261_GAP, text_width, font_height_m);
        set_fixed_icontext_list_text_coordinates(1, (3 + w), font_height_m + 2*WGUI_CAT261_GAP, text_width, font_height_s);
        set_fixed_icontext_list_icon_coordinates(1, (3 + w), font_height_m + font_height_s + 3*WGUI_CAT261_GAP, w1, h1);
        set_fixed_icontext_list_icon_coordinates(2, 3 + w + w1 + 2, font_height_m + font_height_s + 3*WGUI_CAT261_GAP, w1, h1);
        set_fixed_icontext_list_icon_coordinates(3, 3 + w + w1 + 2 + w1 + 2, font_height_m + font_height_s + 3*WGUI_CAT261_GAP, w1, h1);
    }
#else /* defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__)*/ 
    set_fixed_icontext_list_icon_coordinates(0, 1, icon0_y, w, h);
    set_fixed_icontext_list_text_coordinates(0, (3 + w), 0, text_width, 16);
    set_fixed_icontext_list_text_coordinates(1, (3 + w), 16, text_width, 10);
    set_fixed_icontext_list_icon_coordinates(1, (3 + w), 16 + 12, w1, h1);
    set_fixed_icontext_list_icon_coordinates(2, 3 + w + w1 + 2, 16 + 12, w1, h1);
    set_fixed_icontext_list_icon_coordinates(3, 3 + w + w1 + 2 + w1 + 2, 16 + 12, w1, h1);
#endif /* defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)*/ 

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_RIGHT_JUSTIFY | UI_MENUITEM_ICONTEXT_LIST_ALL_TEXT_VERTICAL_ALIGN_CENTER | UI_MENUITEM_AUTO_CHOOSE_MARQUEE;

    MMI_fixed_list_menu.show_loading_index = 0;

    resize_asyncdynamic_icontext_menuitems_to_list_width();
    wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
    wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        disable_fixed_list_show_empty();
    }

    wgui_cat_setup_category_default_history(MMI_CATEGORY261_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory261Screen);
    dm_redraw_category_screen();

    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    /* Reset The Application Side Flag */
    *category_error_flag = 0;
}


void wgui_cat261_ext_show(
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
          S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    mmi_cat263_display_style = MMI_CAT261_DISPLAY_TWO_LINE;
#endif
    ShowCategory261Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        list_icon,
        IMG_NONE,
        history_buffer,
        2,
        1,
        category_error_flag);
}

/*----------------------------------AsyncDynamic Iconic List---------------------------*/


/*****************************************************************************
 * FUNCTION
 *  ExitCategory262Screen
 * DESCRIPTION
 *  Exit category 262
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory262Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_async_dynamic_list_exit();
#ifdef __GEMINI__
    wgui_cat_list_set_display_more_icon(MMI_FALSE);
#endif /* __GEMINI__ */
}

/* Work On Variable w and h to fix the cordinate issue. */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory262Screen
 * DESCRIPTION
 *  Show category 262
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  list_icon               [IN]        Icon of list
 *  history_buffer          [IN]        History buffer
 *  category_error_flag     [OUT]       error flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory262Screen(
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
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 img;
    U8 h_flag = 0;
    S32 h, w, text_width;
    S32 list_height = MMI_content_height;
    S32 icon_column = 1;
#ifdef __GEMINI__
	S32 icon2_x;
#endif /* __GEMINI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    gui_asyncdynamic_list_error = 0;
    *category_error_flag = 1;
	dm_add_title((UI_string_type)title, get_image(title_icon));
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

#ifdef __GEMINI__
    if (wgui_cat_list_get_display_more_icon())
    {
        icon_column = 2;
    }
#endif /* __GEMINI__ */
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        1,
        icon_column,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        0,
        0,
        NULL);

    h_flag = set_list_menu_category_history(MMI_CATEGORY262_ID, history_buffer);
    if(!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif/*__MMI_ICON_BAR_SUPPORT__*/
    img = (U8*) GetImage(list_icon);
    gdi_image_get_dimension(img, &w, &h);

    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, w, h);
#ifdef __GEMINI__
    if (wgui_cat_list_get_display_more_icon() && icon_column == 2)
    {
        text_width -= w + 2;
		icon2_x = GUI_ICONTEXT_MENUITEM_TEXT_X + text_width + 2;
		set_fixed_icontext_list_icon_coordinates(1, icon2_x, 0, w, h);
    }
#endif /* __GEMINI__ */
    set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, MMI_MENUITEM_HEIGHT);

    MMI_fixed_icontext_list_menuitem.selected_fonts[0] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);

    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        disable_fixed_list_show_empty();
    }

    wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
    wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);

    wgui_cat_setup_category_default_history(MMI_CATEGORY262_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory262Screen);
    dm_redraw_category_screen();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}


static S32 cat263_flag = MMI_CAT263_DISPLAY_NONE;
#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CAT263_GAP 8
#elif defined(__MMI_MAINLCD_240X400__)
#define WGUI_CAT263_GAP 3
#else
#define WGUI_CAT263_GAP 2
#endif  /* __MMI_MAINLCD_320X480__*/

#define WGUI_CAT263_ICON_GAP_Y	3
#define WGUI_CAT263_TEXT_GAP_Y  3

typedef struct
{
    U16 style;
    U8 t1;
    U8 t2;
} wgui_cat263_item_style_map;

const wgui_cat263_item_style_map cat263_item_map[] = 
{
    {MMI_CAT263_DISPLAY_TIME_SUBJECT, 1, 0},
    {MMI_CAT263_DISPLAY_TIME_SENDER, 1, 2},
    {MMI_CAT263_DISPLAY_SUBJECT_TIME, 0, 1},
    {MMI_CAT263_DISPLAY_SUBJECT_SENDER, 0, 2},
    {MMI_CAT263_DISPLAY_SENDER_TIME, 2, 1},
    {MMI_CAT263_DISPLAY_SENDER_SUBJECT, 2, 0},
};

const S32 cat263_item_map_num = sizeof(cat263_item_map) / sizeof(wgui_cat263_item_style_map);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat263_get_item_index_by_style
 * DESCRIPTION
 *  get item index by style, and this index is the number of cat263_item_map
 * PARAMETERS
 *  type		[IN]	display type for 263/267
 * RETURNS
 *  if find index according to type, return index, or return -1
 *****************************************************************************/
static S32 wgui_cat263_get_item_index_by_style(U16 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cat263_item_map_num; i++)
    {
        if (cat263_item_map[i].style == style)
        {
            return i;
        }
    }
    return -1;
}

void wgui_cat263_set_display_style(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((flag >= MMI_CAT263_DISPLAY_NONE) && (flag <= CAT263_DISPLAY_SENDER_SUBJECT));
    cat263_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory263Screen
 * DESCRIPTION
 *  Exit category 263
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory263Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X64__)
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
#endif /* __MMI_MAINLCD_128X64__ */
	wgui_async_dynamic_list_exit();
    gui_scrolling_text_stop(&scroll_text_cat251);
#if(_EMAIL_ENABLE_SECOND_STR_SCROLL_)
    gui_scrolling_text_stop(&scroll_text_cat251A);
#endif
    wgui_cat_enable_list_menu_empty_lable();
#if defined (__MMI_FTE_SUPPORT__)
    mmi_cat263_show = MMI_FALSE;
#endif /* __MMI_FTE_SUPPORT__ */
    cat263_flag = MMI_CAT263_DISPLAY_NONE;

    if(g_cat_tab_num > 0)
    {
        wgui_close_horizontal_tab_bar();
    }
#ifdef __GEMINI__
    wgui_cat_list_set_display_more_icon(MMI_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate263CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category263 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate263CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gui_asyncdynamic_list_error && MMI_fixed_list_menu.n_items > 0)
    {
        DrawCategory251InfoBox(category_251_info_text1, category_251_info_text2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory263InfoBox
 * DESCRIPTION
 *  Set the info text box strings to be display and redraw category 263
 * PARAMETERS
 *  infoText1       [IN]     infotext 1 to redraw
 *  infoText2       [IN]     infotext 2 to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory263InfoBox(U8 *infoText1, U8 *infoText2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MAINLCD_320X480__)
    RedrawCategory251InfoBox(infoText1, infoText2);
#endif
}

/* Eg:  Sent Folder */
#if !defined(__MMI_MAINLCD_320X480__)
static void mmi_cat263_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem_type *mi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_list_highlight_handler(item_index);
    mi = get_asyncdynamic_item_from_buffer(item_index);
    RedrawCategory251InfoBox((U8*)mi->item_texts[2], (U8*)mi->item_texts[1]);
}
#endif /* __MMI_MAINLCD_320X480__ */

/*****************************************************************************
* FUNCTION
*  mmi_cat263_set_menu_flags
* DESCRIPTION
*  Set cattegory263 flags when support FTE
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_cat263_set_menu_flags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_list_menuitem.flags |= /*UI_MENUITEM_CENTER_ICON_Y | */UI_MENUITEM_TRUNCATE_CONTENT;
    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_TEXT_Y);
    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_ICON_Y);
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
}

static void mmi_cat263_set_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;
    S32 list_height = MMI_content_height;
    S32 gap = MMI_content_height - CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
	S32 x, y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif/*__MMI_ICON_BAR_SUPPORT__*/    
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    if(n_tabs > 0)
    {
        list_height -= gap;
		x = CAT_MMI_CONTENT_X_WITH_H_TAB;
		y = CAT_MMI_CONTENT_Y_WITH_H_TAB;
    }
    else
    {
        x = MMI_content_x;
		y = MMI_content_y;
    }
	wgui_async_list_move_multi_icontext_menu(x, y);
	wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
}


static void mmi_cat263_set_icontext_list_ext(U8 t1, U8 t2, S32 iw, S32 tw, S32 th, S32 tx, S32 icon_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
    S32 icon2_x = 0;
#endif /* __GEMINI__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X + icon_width, WGUI_CAT263_ICON_GAP_Y, iw, MMI_MULTIROW_MENUITEM_HEIGHT - 6); 
#ifdef __GEMINI__
    if(wgui_cat_list_get_display_more_icon())
    {
        icon2_x = tx + tw + WGUI_CAT263_GAP;
        set_fixed_icontext_list_icon_coordinates(1, icon2_x, WGUI_CAT263_ICON_GAP_Y, iw, MMI_MULTIROW_MENUITEM_HEIGHT-6);
    }
#endif /* __GEMINI__ */
    set_fixed_icontext_list_text_coordinates(t1, tx, WGUI_CAT263_GAP, tw, th);
    set_fixed_icontext_list_text_coordinates(t2, tx, th + WGUI_CAT263_GAP, tw, th);
    set_fixed_icontext_list_text_coordinates(3 - t1 - t2, tx, MMI_MULTIROW_MENUITEM_HEIGHT, 0, 0);
    mmi_cat263_set_tab_bar();
}


#ifdef __GEMINI__
static MMI_BOOL g_cat_list_more_icon = MMI_FALSE;
void wgui_cat_list_set_display_more_icon(MMI_BOOL IsIcon)
{
	g_cat_list_more_icon = IsIcon;
}
static MMI_BOOL wgui_cat_list_get_display_more_icon(void)
{
	return g_cat_list_more_icon;
}
#endif


/*****************************************************************************
* FUNCTION
*  wgui_cat263_set_display_all
* DESCRIPTION
*  display category menuitem for MMI_CAT263_DISPLAY_ALL style
* PARAMETERS
*  text_x		[IN]	x of text
*  text_width	[IN] text width
*  icon_width	[IN]	icon width
*  icon1_w	[IN]	icon1 width
*  icon1_h	[IN] icon1 height
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat263_set_display_all(S32 text_x, S32 text_width, S32 icon_width, S32 icon1_w, S32 icon1_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp1[] = L"1234567890/ :";
    U16 temp2[] = L"AM";
    S32 w, h, text_time_width, text_name_width, time_x;
#ifdef __GEMINI__
    S32 icon2_x = 0;
#endif /* __GEMINI__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_small_font);
    mmi_fe_measure_string_by_char_num((U8*)temp1, 6, &w, &h);
    text_time_width = w;
    mmi_fe_measure_string_by_char_num((U8*)temp2, 2, &w, &h);
    text_time_width += w;
    
    text_name_width = text_width - GUI_MENUITEM_TEXT_RIGHT_GAP - text_time_width;
    time_x = text_x + text_name_width + GUI_MENUITEM_TEXT_RIGHT_GAP;
    
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X + icon_width, WGUI_CAT263_ICON_GAP_Y, icon1_w, icon1_h);
#ifdef __GEMINI__
    if(wgui_cat_list_get_display_more_icon())
    {
        icon2_x = text_x + text_width + WGUI_CAT263_GAP;
        set_fixed_icontext_list_icon_coordinates(1, icon2_x, WGUI_CAT263_ICON_GAP_Y, icon1_w, icon1_h);
    }
#endif /* __GEMINI__ */

    set_fixed_icontext_list_text_coordinates(2, text_x, 0, text_name_width, (MMI_MULTIROW_MENUITEM_HEIGHT>>1));   
    set_fixed_icontext_list_text_coordinates(1, time_x, 0, text_time_width, (MMI_MULTIROW_MENUITEM_HEIGHT>>1));
    set_fixed_icontext_list_text_coordinates(0, text_x, (MMI_MULTIROW_MENUITEM_HEIGHT>>1), text_width, (MMI_MULTIROW_MENUITEM_HEIGHT>>1));
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_TRUNCATE_CONTENT | UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_RIGHT_JUSTIFY_COL2;
    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_ICON_Y);
    
    mmi_cat263_set_tab_bar();
}


#ifndef __MMI_MAINLCD_320X480__
/*****************************************************************************
* FUNCTION
*  wgui_cat263_set_display_none
* DESCRIPTION
*  display category menuitem for MMI_CAT263_DISPLAY_NONE style
* PARAMETERS
*  text_x		[IN]	x of text
*  cb_w		[IN]	check box width
*  icon2_x	[IN]	x of icon2
*  icon_w		[IN]	icon width 
*  text_w		[IN] text width
*  list_height	[IN]	list height
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat263_set_display_none(S32 text_x, S32 cb_w, S32 icon2_x, S32 icon_w, S32 text_w, S32 list_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 info_box_height = 0, y = MMI_content_y;
#if defined(__MMI_FTE_SUPPORT__)
    stFontAttribute *f = &MMI_small_font;
#else /* __MMI_FTE_SUPPORT__ */
    stFontAttribute *f = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE);
#endif /* __MMI_FTE_SUPPORT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X + cb_w, 0, icon_w, MMI_MENUITEM_HEIGHT);
#ifdef __GEMINI__
    if(wgui_cat_list_get_display_more_icon())
    {
        set_fixed_icontext_list_icon_coordinates(1, icon2_x, 0, icon_w, MMI_MENUITEM_HEIGHT);
    }
#endif
    set_fixed_icontext_list_text_coordinates(0, text_x, 0, text_w, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(2, text_x, 0, 0, 0);
    set_fixed_icontext_list_text_coordinates(1, text_x, 0, 0, 0);
    
    MMI_fixed_icontext_list_menuitem.selected_fonts[0] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[1] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[2] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;
    if(MMI_fixed_list_menu.n_items > 0)
    {
        info_box_height = Get_CharHeightOfAllLang(f->size) * 2 + 5;
    }
    
    if(g_cat_tab_num > 0)
    {
        y = CAT_MMI_CONTENT_Y_WITH_H_TAB;
    }
	wgui_async_list_move_multi_icontext_menu(MMI_content_x, y + info_box_height);
	wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height - info_box_height);
}
#endif /* __MMI_MAINLCD_320X480__ */


/*****************************************************************************
* FUNCTION
*  wgui_cat263_create_icontext_menu
* DESCRIPTION
*  create category263/267 icontext menu
* PARAMETERS
*  n_items	[IN]	number of items
*  n_icons	[IN]	number of icons
*  get_item_func	[IN]	function of get item
*  get_hint_func	[IN]	function of get hint
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat263_create_icontext_menu(S32 n_items, S32 n_icons, GetAsyncItemFuncPtr get_item_func, GetAsyncHintFuncPtr get_hint_func)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(cat263_flag)
    {
        case MMI_CAT263_DISPLAY_NONE:
        #if defined(__MMI_MAINLCD_320X480__)
            wgui_async_list_create_multi_icontext_menu(
                n_items,
                3,
                n_icons,
                get_item_func,
                get_hint_func,
                WGUI_LIST_INVALID_HIGHLIGHT,
                MMI_MULTIROW_MENUITEM_HEIGHT,
                0,
                0,
                NULL);
		
        #elif defined(__MMI_MAINLCD_128X64__)
            wgui_async_list_create_multi_icontext_menu(
                n_items,
                1,
                1,
                get_item_func,
                get_hint_func,
                WGUI_LIST_INVALID_HIGHLIGHT,
                MMI_MENUITEM_HEIGHT,
                0,
                0,
                NULL);
		    wgui_title_set_no_icon_shct(MMI_FALSE);
        #else /* __MMI_MAINLCD_320X480__ */
            wgui_async_list_create_multi_icontext_menu(
                n_items,
                3,
                n_icons,
                get_item_func,
                get_hint_func,
                WGUI_LIST_INVALID_HIGHLIGHT,
                MMI_MENUITEM_HEIGHT,
                0,
                0,
                NULL);
            wgui_async_list_override_multi_icontext_highlight_handler(mmi_cat263_highlight_handler);
        #endif /* __MMI_MAINLCD_320X480__ */
            break;
        case MMI_CAT263_DISPLAY_ALL:
        case MMI_CAT263_DISPLAY_TIME_SUBJECT:
        case MMI_CAT263_DISPLAY_TIME_SENDER:
        case MMI_CAT263_DISPLAY_SUBJECT_TIME:
        case MMI_CAT263_DISPLAY_SUBJECT_SENDER:
        case MMI_CAT263_DISPLAY_SENDER_TIME:
        case MMI_CAT263_DISPLAY_SENDER_SUBJECT:
            wgui_async_list_create_multi_icontext_menu(
                n_items,
                3,
                n_icons,
                get_item_func,
                get_hint_func,
                WGUI_LIST_INVALID_HIGHLIGHT,
                MMI_MULTIROW_MENUITEM_HEIGHT,
                0,
                0,
                NULL);
            break;
        default:
            MMI_ASSERT(FALSE);
    }
}


extern void wgui_stop_list_menuitem_scrolling(void);

void wgui_cat263_tab_show(
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
         S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width;
    S32 text_x = 0;
    S32 w = 0, h = 0;
    S32 font_height_m;
    U8 h_flag = 0;
    S32 list_height;
#if defined(__MMI_MAINLCD_320X480__)
    S32 font_height_s;
#endif /* __MMI_MAINLCD_320X480__ */
    S8 n_tabs = 0;
    U16 catID = 0;
	S32 icon_column = 1;
#ifdef __GEMINI__
	S32 icon2_x = 0;
#endif /* __GEMINI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_submenu_layout();

	list_height = MMI_content_height;
    
    *category_error_flag = 1;
    gui_asyncdynamic_list_error = 0;
#if defined(__MMI_FTE_SUPPORT__)
    mmi_cat263_show = MMI_TRUE;
#endif /* __MMI_FTE_SUPPORT__ */

    dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_title_set_no_icon_shct(MMI_TRUE);

    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
	g_cat_tab_num = n_tabs;

    if(n_tabs > 0)
    {
        catID = MMI_CAT263_TAB_ID;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
#endif
    }
    else
    {
        dm_add_title((UI_string_type) title, title_icon);
        catID = MMI_CATEGORY263_ID;
    }
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())  /* GEMINI+ project will show addition column icon*/
	{
		icon_column = 2;
	}
#endif

    /* create async dynamic list menu */
    wgui_cat263_create_icontext_menu(number_of_items, icon_column, get_item_func, get_hint_func);

    h_flag = set_list_menu_category_history(catID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }   
    gui_measure_image(list_icon, &w, &h);

    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }

    text_x = GUI_ICONTEXT_MENUITEM_ICON_X + w + WGUI_CAT263_GAP;
    text_width = MMI_content_width - 
                    MMI_fixed_list_menu.vbar.width - 
                    GUI_MENUITEM_X2_GAP - 
                    GUI_MENUITEM_TEXT_RIGHT_GAP - 
                    text_x -
                    GUI_MENUITEM_X1_GAP;
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon() && icon_column == 2)
	{
		text_width -= w + WGUI_CAT263_GAP;
        icon2_x = text_x + text_width + WGUI_CAT263_GAP;
	}
#endif

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif/*__MMI_ICON_BAR_SUPPORT__*/    
    font_height_m = Get_CharHeightOfAllLang(MEDIUM_FONT);
    switch(cat263_flag)
    {
    case MMI_CAT263_DISPLAY_NONE:
#if defined(__MMI_MAINLCD_320X480__)
        font_height_s = Get_CharHeightOfAllLang(SMALL_FONT);
        MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TRUNCATE_CONTENT;
        set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, WGUI_CAT263_ICON_GAP_Y, w, h);
#ifdef __GEMINI__
	    if(wgui_cat_list_get_display_more_icon() && icon_column == 2)
	    {
		    set_fixed_icontext_list_icon_coordinates(1, icon2_x, WGUI_CAT263_ICON_GAP_Y, w, h);
	    }
#endif
        set_fixed_icontext_list_text_coordinates(2, text_x, WGUI_CAT263_TEXT_GAP_Y, text_width, font_height_m);   
        set_fixed_icontext_list_text_coordinates(1, text_x, font_height_m + WGUI_CAT263_TEXT_GAP_Y, text_width, font_height_m);
        set_fixed_icontext_list_text_coordinates(0, text_x, font_height_m*2 + WGUI_CAT263_TEXT_GAP_Y, text_width, font_height_s);
        MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_TEXT_Y);
        MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_bold_font;
        MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
        MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_small_font;
        MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
        MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->multirow_third_line_text_color;
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->multirow_third_line_highlight_text_color;
        MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->multirow_third_line_highlight_text_color;
        MMI_fixed_icontext_list_menuitem.normal_text_colors[2] = *current_MMI_theme->list_normal_text_color;//multirow_first_line_text_color
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[2] = *current_MMI_theme->list_selected_text_color;//
        MMI_fixed_icontext_list_menuitem.selected_text_colors[2] = *current_MMI_theme->list_selected_text_color;//
        MMI_fixed_icontext_list_menuitem.normal_text_colors[1] = *current_MMI_theme->two_line_second_line_text_color;//multirow_second_line_text_color
        MMI_fixed_icontext_list_menuitem.focussed_text_colors[1] = *current_MMI_theme->two_line_second_line_highlight_text_color;//multirow_second_line_highlight_text_color
        MMI_fixed_icontext_list_menuitem.selected_text_colors[1] = *current_MMI_theme->two_line_second_line_highlight_text_color;//multirow_second_line_highlight_text_color

        if(n_tabs > 0)
        {
            wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
        }
        else
        {
            wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        } 
		wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);  
#elif defined(__MMI_MAINLCD_128X64__)
        set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, /*3*/0, w, /*h*/MMI_MENUITEM_HEIGHT);
        set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, MMI_MENUITEM_HEIGHT);
        if(n_tabs > 0)
        {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
            wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
            wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
        }
        else
        {
            wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        }
		wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
#else /* __MMI_MAINLCD_320X480__ */
        {
            S32 icon2_x_offset = 0;

		#if defined(__GEMINI__)
            icon2_x_offset = icon2_x;
		#endif /* __GEMINI__ */
		    wgui_cat263_set_display_none(text_x, 0, icon2_x_offset, w, text_width, list_height);
        }
#endif /* __MMI_MAINLCD_320X480__ */
        break;
        
        case MMI_CAT263_DISPLAY_ALL:
            wgui_cat263_set_display_all(text_x, text_width, 0, w, h);
            break;
        default:
			{
				S32 index;

				index = wgui_cat263_get_item_index_by_style(cat263_flag);
				if (index != -1)
				{
				    mmi_cat263_set_icontext_list_ext(
						cat263_item_map[index].t1, 
						cat263_item_map[index].t2, 
						w, 
						text_width, 
						font_height_m, 
						text_x,
						0);
					mmi_cat263_set_menu_flags();
				}
			}
            break;
    }
    
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

    wgui_icon_bar_register_pause_interactive_UI_callback(wgui_stop_list_menuitem_scrolling);
    wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat268_resume_scroll);

	wgui_cat_setup_category_default_history((S32)catID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory263Screen);
    if(MMI_CAT263_DISPLAY_NONE == cat263_flag)
    {
    #if !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_128X64__)
        dm_register_category_controlled_callback(DrawCate263CategoryControlArea);
    #endif /* __MMI_MAINLCD_320X480__ && __MMI_MAINLCD_128X64__*/
    }
    dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory263Screen_int
 * DESCRIPTION
 *  Show category 263
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  list_icon               [IN]        Icon of list
 *  history_buffer          [IN]        History buffer
 *  category_error_flag     [OUT]       error flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory263Screen_int(
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
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat263_tab_show(
        (WCHAR *)title,
        get_image(title_icon),
        (WCHAR *)get_string(left_softkey),
        (WCHAR *)get_string(right_softkey),
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        (S8)(-1),    
        get_image(list_icon),
        history_buffer,
        category_error_flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat267_scrolling_text_draw_background
 * DESCRIPTION
 *  Draw category 267 scrolling text draw background
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat267_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y11, y22;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y11 = MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT;
    y22 = MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - 1;

    gui_push_clip();
    gui_reset_clip();
    
    gui_set_clip(x1, y11, x2, y22);
#ifdef __MMI_MAINLCD_128X128__
    gdi_draw_solid_rect(
        x1, y11, x2, y22,
        GDI_COLOR_WHITE);
#else /* __MMI_MAINLCD_128X128__ */
    gdi_draw_solid_rect(
        x1, y11, x2, y22,
        GDI_COLOR_TRANSPARENT);
#endif /* __MMI_MAINLCD_128X128__ */

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory267InfoBox
 * DESCRIPTION
 *  Set the info text box strings to be display and redraw category 263
 * PARAMETERS
 *  infoText1       [IN]     infotext 1 to redraw
 *  infoText2       [IN]     infotext 2 to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory267InfoBox(U8 *infoText1, U8 *infoText2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MAINLCD_320X480__)
    RedrawCategory251InfoBox(infoText1, infoText2);
#endif
}


void wgui_cat267_tab_show(
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
         S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width;
    S32 text_x = 0;
    S32 w = 0, h = 0;
    U8 h_flag = 0;
    S8 n_tabs = 0;
    S32 font_height_m;
    U16 catID = 0;
	S32 icon_column = 1;
#ifdef __GEMINI__
	S32 icon2_x = 0;
#endif /* __GEMINI__ */
#if defined(__MMI_MAINLCD_320X480__)
    S32 font_height_s;
#endif /* __MMI_MAINLCD_320X480__ */
    UI_string_type info_msg = NULL;
    S32 list_height = MMI_content_height;
    PU8 check_box_image = NULL;
    S32 check_box_width = 0, check_box_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_submenu_layout();
    
    *category_error_flag = 1;
    gui_asyncdynamic_list_error = 0;
#if defined(__MMI_FTE_SUPPORT__)
    mmi_cat263_show = MMI_TRUE;
#endif /* __MMI_FTE_SUPPORT__ */
    if(MMI_CAT263_DISPLAY_NONE == cat263_flag)
    {
        info_msg = (UI_string_type)info_message;
    }

	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_title_set_no_icon_shct(MMI_TRUE);
    
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
	g_cat_tab_num = n_tabs;

    if(n_tabs > 0)
    {
        catID = MMI_CAT267_TAB_ID;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type) title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type) title, n_tabs, highlighted_tab, MMI_FALSE);
		list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
#endif
    }
    else
    {
        dm_add_title((UI_string_type) title, title_icon);
        catID = MMI_CATEGORY267_ID;    
    }
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())  /* GEMINI+ project will show addition column icon*/
	{
		icon_column = 2;
	}
#endif

    /* create async dynamic list menu */
    wgui_cat263_create_icontext_menu(number_of_items, icon_column, get_item_func, get_hint_func);

    h_flag = set_list_menu_category_history(catID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    if(get_state_func)
    {
        get_state_func(0, &check_box_image);
    }
    if(check_box_image)
    {
        gui_measure_image(check_box_image, &check_box_width, &check_box_height);
    }
    wgui_menuitem_set_icontext_list_checkbox_position(GUI_ICONTEXT_MENUITEM_ICON_X, 0);
    wgui_menuitem_register_icontext_list_checkbox_callback(set_state_func, get_state_func);

    gui_measure_image(list_icon, &w, &h);

    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }

    if(info_msg != NULL)
    {
        dm_add_scroll_text(
            info_msg,
            NULL,
            wgui_cat267_scrolling_text_draw_background,
#ifdef __MMI_MAINLCD_128X128__
            gui_color(0, 0, 0),
            gui_color(255, 255, 255)
#else /* __MMI_MAINLCD_128X128__ */
            *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255)
#endif /* __MMI_MAINLCD_128X128__ */
            );
        list_height -= MMI_MENUITEM_HEIGHT;
    }

    text_x = GUI_ICONTEXT_MENUITEM_ICON_X + w + check_box_width + WGUI_CAT263_GAP*2;
    text_width = MMI_content_width - 
                    MMI_fixed_list_menu.vbar.width - 
                    GUI_MENUITEM_X2_GAP -
                    GUI_MENUITEM_TEXT_RIGHT_GAP -
                    text_x - 
                    GUI_MENUITEM_X1_GAP;
                    
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())
	{
		text_width -= w + WGUI_CAT263_GAP;
        icon2_x = text_x + text_width + WGUI_CAT263_GAP;
	}
#endif

    font_height_m = Get_CharHeightOfAllLang(MEDIUM_FONT);

    switch(cat263_flag)
    {
    case MMI_CAT263_DISPLAY_NONE:
#if defined(__MMI_MAINLCD_320X480__)
        MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TRUNCATE_CONTENT;
        font_height_s = Get_CharHeightOfAllLang(SMALL_FONT);

		wgui_menuitem_set_icontext_list_checkbox_position(GUI_ICONTEXT_MENUITEM_ICON_X, WGUI_CAT263_ICON_GAP_Y);

        set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X + check_box_width + 2, WGUI_CAT263_ICON_GAP_Y, w, h);
#ifdef __GEMINI__
		if(wgui_cat_list_get_display_more_icon())
		{
			set_fixed_icontext_list_icon_coordinates(1, icon2_x, WGUI_CAT263_ICON_GAP_Y, w, h);
		}
#endif  
        set_fixed_icontext_list_text_coordinates(2, text_x, WGUI_CAT263_TEXT_GAP_Y, text_width, font_height_m);   
        set_fixed_icontext_list_text_coordinates(1, text_x, font_height_m + WGUI_CAT263_TEXT_GAP_Y, text_width, font_height_m);
        set_fixed_icontext_list_text_coordinates(0, text_x, font_height_m*2 + WGUI_CAT263_TEXT_GAP_Y, text_width, font_height_s);
        MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_TEXT_Y);
        MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
        
        MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_bold_font;
        MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
        MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_small_font;
        if(n_tabs > 0)
        {
            wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
        }
        else
        {
            wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        }
		wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
#elif defined(__MMI_MAINLCD_128X64__)
        set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X + MMI_ICONTEXT_MENUITEM_HEIGHT, 3, w, h);
        set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X + MMI_ICONTEXT_MENUITEM_HEIGHT + 3, 0, text_width, MMI_MENUITEM_HEIGHT);
        if(n_tabs > 0)
        {
            wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
        }
        else
        {
            wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        }
		wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
#else /* __MMI_MAINLCD_320X480__ */
        {
            S32 icon2_x_offset = 0;

		#if defined(__GEMINI__)
		    icon2_x_offset = icon2_x;
		#endif /* __GEMINI__ */
		    wgui_cat263_set_display_none(text_x, check_box_width, icon2_x_offset, w, text_width, list_height);
        }
#endif /* __MMI_MAINLCD_320X480__ */
        break;

        case MMI_CAT263_DISPLAY_ALL:
            wgui_menuitem_set_icontext_list_checkbox_position(GUI_ICONTEXT_MENUITEM_ICON_X, WGUI_CAT263_ICON_GAP_Y);
            wgui_cat263_set_display_all(text_x, text_width, check_box_width, w, h);
            break;        
        default:
			{
				S32 index;

				index = wgui_cat263_get_item_index_by_style(cat263_flag);
				if (index != -1)
				{
				    
					wgui_menuitem_set_icontext_list_checkbox_position(GUI_ICONTEXT_MENUITEM_ICON_X, WGUI_CAT263_ICON_GAP_Y);
				    mmi_cat263_set_icontext_list_ext(
						cat263_item_map[index].t1, 
						cat263_item_map[index].t2, 
						w, 
						text_width, 
						font_height_m, 
						text_x,
						check_box_width);
					mmi_cat263_set_menu_flags();
				}
			}
		    break;
    }

    if(cat263_flag == MMI_CAT263_DISPLAY_NONE)
    {
        h_flag = set_list_menu_category_history(catID, history_buffer);
        if (!h_flag)
        {
            MMI_fixed_list_menu.highlighted_item = highlighted_item;
        }
        asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    }

    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        disable_fixed_list_show_empty();
    }

    wgui_cat_setup_category_default_history((S32)catID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory263Screen);
    if(MMI_CAT263_DISPLAY_NONE == cat263_flag)
    {
    #if !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_128X64__)
        dm_register_category_controlled_callback(DrawCate263CategoryControlArea);
    #endif /* __MMI_MAINLCD_320X480__ && __MMI_MAINLCD_128X64__*/
    }
    dm_redraw_category_screen();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory267Screen_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [IN] Char array of title
 *  title_icon              [IN] Byte array of title icon
 *  left_softkey            [IN] String ID of left softkey
 *  right_softkey           [IN] String ID of right softkey
 *  number_of_items         [IN] Number of items of list
 *  get_item_func           [IN] Get item function pointer
 *  get_hint_func           [IN] Get hint function pointer
 *  get_state_func          [IN] Get state of check-box function pointer
 *  set_state_func          [IN] Set state of check-box function pointer
 *  info_message            [IN] Char array of information message
 *  highlighted_item        [IN] Currently highlighted item
 *  history_buffer          [IN] History buffer
 *  category_error_flag     [OUT]       error flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory267Screen_int(
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
    S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat267_tab_show(
        (WCHAR *)title,
        title_icon,
        (WCHAR *)left_softkey,
        (WCHAR *)right_softkey,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        (WCHAR *)info_message,
        highlighted_item,
        (S8)(-1),
        get_image(list_icon),
        history_buffer,
        category_error_flag);
}

/*****************************************************************************
 * FUNCTION
 *  ExitCategory268Screen
 * DESCRIPTION
 *  Exit category 268
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory268Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_async_dynamic_list_exit();
    wgui_cat_enable_list_menu_empty_lable();

    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    if(n_tabs > 0)
    {
        wgui_close_horizontal_tab_bar();
    }
#ifdef __GEMINI__
    wgui_cat_list_set_display_more_icon(MMI_FALSE);
#endif
}

static void wgui_cat268_resume_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);

    gdi_layer_lock_frame_buffer();
    show_asyncdynamic_list();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    
    gdi_layer_blt_previous(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.height - 1);
}


void wgui_cat268_with_tab_show(
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
         S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;
    S32 text_width;
    U16 catID = 0;
    S32 w = 0, h = 0;
    S32 list_height = MMI_content_height;
    U8 h_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_submenu_layout();
    
    *category_error_flag = 1;
    gui_asyncdynamic_list_error = 0;
    
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_title_set_no_icon_shct(MMI_TRUE);

    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);

    if(n_tabs)
    {
        catID = MMI_CAT268_TAB_ID;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
#endif
    }
    else
    {
        dm_add_title((UI_string_type) title, title_icon);
        catID = MMI_CATEGORY268_ID;
    }

    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        3,
        1,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE,
        0,
        NULL);
    
    h_flag = set_list_menu_category_history(catID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    
    gui_measure_image(list_icon, &w, &h);
    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }
    
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;
    
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, w, h);
    set_fixed_icontext_list_text_coordinates(2, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, MMI_MENUITEM_HEIGHT);   /* address */
    set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, MMI_MENUITEM_HEIGHT, text_width, MMI_MENUITEM_HEIGHT); /* subject */
    set_fixed_icontext_list_text_coordinates(1, MAIN_LCD_DEVICE_WIDTH, 0, 0, 0); /* subject */

#ifdef __MMI_MAINLCD_320X480__
    MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->two_line_second_line_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.normal_text_colors[2] = *current_MMI_theme->list_normal_text_color;//two_line_first_line_text_color
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
    MMI_fixed_icontext_list_menuitem.selected_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
#endif /* __MMI_MAINLCD_320X480__ */

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_ICONTEXT_LIST_ALL_TEXT_VERTICAL_ALIGN_CENTER;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif/*__MMI_ICON_BAR_SUPPORT__*/
    if(n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
        wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
        wgui_async_list_resize_multi_icontext_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, list_height);
    }
    else
    {
        wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
    }

    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

    wgui_icon_bar_register_pause_interactive_UI_callback(wgui_stop_list_menuitem_scrolling);
    wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat268_resume_scroll);

	wgui_cat_setup_category_default_history((S32)catID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory268Screen);
    dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory268Screen_int
 * DESCRIPTION
 *  Category 268 is an async dynamic list menu category.
 *  It displays text index 1 in the 1st line, and displays text index 0 in the 2nd line when highlighted.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  list_icon               [IN]        Icon of list
 *  history_buffer          [IN]        History buffer
 *  category_error_flag     [OUT]       error flag
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory268Screen_int(
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
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width;
    S32 w = 0, h = 0;
    U8 *img = NULL;
    S32 list_height = MMI_content_height;
    U8 h_flag = 0;
	S32 icon_column = 1;
#ifdef __GEMINI__
	S32 icon2_x = 0;
#endif /* __GEMINI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_submenu_layout();

    /* Set The Application Side Variable To True */
    *category_error_flag = 1;
	dm_add_title((UI_string_type)title, get_image(title_icon));
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())  /* GEMINI+ project will show addition column icon*/
	{
		icon_column = 2;
	}
#endif
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        3,
        icon_column,
        get_item_func,
        get_hint_func,
        /*highlighted_item*/WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE,
        /*MMI_CATEGORY268_ID*/0,
        /*history_buffer*/NULL);

    h_flag = set_list_menu_category_history(MMI_CATEGORY268_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

    img = (U8*) GetImage(list_icon);
    gui_measure_image(img, &w, &h);

    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }

    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())
	{
		text_width -= w + 2;
		icon2_x = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP - w;
	}
#endif
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, w, h);
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())
	{
		set_fixed_icontext_list_icon_coordinates(1, icon2_x, 0, w, h);
	}
#endif
 	  set_fixed_icontext_list_text_coordinates(2, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, MMI_MENUITEM_HEIGHT);   /* address */
	  set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, MMI_MENUITEM_HEIGHT, text_width, MMI_MENUITEM_HEIGHT); /* subject */
    set_fixed_icontext_list_text_coordinates(1, MAIN_LCD_DEVICE_WIDTH, 0, 0, 0); /* subject */

#ifdef __MMI_MAINLCD_320X480__
    MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->two_line_second_line_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.normal_text_colors[2] = *current_MMI_theme->list_normal_text_color;//two_line_first_line_text_color
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
    MMI_fixed_icontext_list_menuitem.selected_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
#endif /* __MMI_MAINLCD_320X480__ */

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_ICONTEXT_LIST_ALL_TEXT_VERTICAL_ALIGN_CENTER;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
    wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

    wgui_icon_bar_register_pause_interactive_UI_callback(wgui_stop_list_menuitem_scrolling);
    wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat268_resume_scroll);

	wgui_cat_setup_category_default_history(MMI_CATEGORY268_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory268Screen);
    dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}


#if defined(__MMI_MAINLCD_320X480__)
#define MMI_CAT1002_TEXT_GAP 5
#elif defined(__MMI_MAINLCD_240X400__)
#define MMI_CAT1002_TEXT_GAP 4
#else
#define MMI_CAT1002_TEXT_GAP 3
#endif
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1002_exit
 * DESCRIPTION
 *  Exit category 1002
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1002_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_async_dynamic_list_exit();

    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    if(n_tabs > 0)
    {
        wgui_close_horizontal_tab_bar();
    }
    wgui_cat_enable_list_menu_empty_lable();
#ifdef __GEMINI__
    wgui_cat_list_set_display_more_icon(MMI_FALSE);
#endif
}


void wgui_cat1002_tab_show(
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
       S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width;
    S32 scroll_height = 0;
    S32 w = 0, h = 0;
    S32 x = 0;
    S32 list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
    U16 catID = 0;
    S8 n_tabs = 0;
    U8 h_flag = 0;
    S32 icon_column = 1;
#ifdef __GEMINI__
	S32 icon2_x = 0;
#endif /* __GEMINI__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
  /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_submenu_layout();
    
    *category_error_flag = 1;
    gui_asyncdynamic_list_error = 0;
    
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);

    if(n_tabs > 0)
    {
        catID = MMI_CAT1002_TAB_ID;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_title_set_no_icon_shct(MMI_TRUE);
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        list_height += MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
        wgui_title_set_no_icon_shct(MMI_TRUE);
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        catID = MMI_CAT1002_TAB_ID;
#endif
    }
    else
    {
        dm_add_title((UI_string_type) title, title_icon);
        catID = MMI_CAT1002_ID;
        list_height = MMI_content_height;
    }
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())  /* GEMINI+ project will show addition column icon*/
	{
		icon_column = 2;
	}
#endif
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        3,
        icon_column,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE,
        0,
        NULL);

    h_flag = set_list_menu_category_history(catID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    wgui_menuitem_set_icontext_list_checkbox_position(1, 0);
    wgui_menuitem_register_icontext_list_checkbox_callback(set_state_func, get_state_func);
    
    gui_measure_image(list_icon, &w, &h);
    
    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }
    
    if(info_message != NULL)
    {
        dm_add_scroll_text(
            info_message,
            NULL,
            wgui_cat267_scrolling_text_draw_background,
#ifdef __MMI_MAINLCD_128X128__
            gui_color(0, 0, 0),
            gui_color(255, 255, 255)
#else /* __MMI_MAINLCD_128X128__ */
            *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255)
#endif /* __MMI_MAINLCD_128X128__ */
            );
        scroll_height = MMI_MENUITEM_HEIGHT;
    }
    
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - MMI_CAT1002_TEXT_GAP - GUI_MENUITEM_X2_GAP - MMI_ICONTEXT_MENUITEM_HEIGHT - GUI_MENUITEM_TEXT_RIGHT_GAP;
    x = GUI_ICONTEXT_MENUITEM_ICON_X + MMI_ICONTEXT_MENUITEM_HEIGHT;
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())
	{
		text_width -= w + 2;
		icon2_x = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP - w;
	}
#endif    
    set_fixed_icontext_list_icon_coordinates(0, x, 0, w, h);
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())
	{
		set_fixed_icontext_list_icon_coordinates(1, icon2_x, 0, w, h);
	}
#endif
    set_fixed_icontext_list_text_coordinates(2, x + MMI_ICONTEXT_MENUITEM_HEIGHT, 0, text_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(0, x + MMI_ICONTEXT_MENUITEM_HEIGHT, MMI_ICONTEXT_MENUITEM_HEIGHT, text_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(1, MAIN_LCD_DEVICE_WIDTH, 0, 0, 0); /* subject */

#ifdef __MMI_MAINLCD_320X480__
    MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->two_line_second_line_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.normal_text_colors[2] = *current_MMI_theme->list_normal_text_color;//two_line_first_line_text_color
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
    MMI_fixed_icontext_list_menuitem.selected_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
#endif /* __MMI_MAINLCD_320X480__ */

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_ICONTEXT_LIST_ALL_TEXT_VERTICAL_ALIGN_CENTER;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;

    if(n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
        wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
        wgui_async_list_resize_multi_icontext_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, list_height - scroll_height);
    }
    else
    {
        wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        wgui_async_list_resize_multi_icontext_menu(MMI_content_width, MMI_content_height - scroll_height);
    }

    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

	wgui_cat_setup_category_default_history((S32)catID, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1002_exit);
    dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1002_show_int
 * DESCRIPTION
 *  Category 1002 is an async dynamic list menu category with checkbox before each item.
 *  It displays text index 0 in the 1st line, and displays text index 1 in the 2nd line when highlighted.
 * PARAMETERS
 *  title                   [IN]    Char array of title
 *  title_icon              [IN]    Byte array of title icon
 *  left_softkey            [IN]    Char array of left softkey
 *  right_softkey           [IN]    Char array of right softkey
 *  number_of_items         [IN]    Number of items of list
 *  get_item_func           [IN]    Get item function pointer
 *  get_hint_func           [IN]    Get hint function pointer
 *  get_state_func          [IN]    Get state of check-box function pointer
 *  set_state_func          [IN]    Set state of check-box function pointer
 *  info_message            [IN]    Char array of information message
 *  highlighted_item        [IN]    Currently highlighted item
 *  list_icon               [IN]    Icon of list
 *  history_buffer          [IN]    History buffer
 *  category_error_flag     [OUT]   error flag
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1002_show_int(
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
      S32 *category_error_flag)
{
  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
    S32 text_width;
    S32 scroll_height = 0;
    S32 w = 0, h = 0;
    S32 x = 0;
    U8 h_flag = 0;
    S32 icon_column = 1;
#ifdef __GEMINI__
	S32 icon2_x = 0;
#endif /* __GEMINI__ */

  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_setup_submenu_layout();

    *category_error_flag = 1;
    gui_asyncdynamic_list_error = 0;
    
    dm_add_title((UI_string_type) title, title_icon);
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())  /* GEMINI+ project will show addition column icon*/
	{
		icon_column = 2;
	}
#endif
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        3,
        icon_column,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE,
        0,
        NULL);
    
    h_flag = set_list_menu_category_history(MMI_CAT1002_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    wgui_menuitem_set_icontext_list_checkbox_position(1, 0);
    wgui_menuitem_register_icontext_list_checkbox_callback(set_state_func, get_state_func);

    gui_measure_image(get_image(list_icon), &w, &h);
    
    if (w == 0)
    {
        w = 15;
    }
    if (h == 0)
    {
        h = 15;
    }
    
    if(info_message != NULL)
    {
        dm_add_scroll_text(
            info_message,
            NULL,
            wgui_cat267_scrolling_text_draw_background,
#ifdef __MMI_MAINLCD_128X128__
            gui_color(0, 0, 0),
            gui_color(255, 255, 255)
#else /* __MMI_MAINLCD_128X128__ */
            *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255)
#endif /* __MMI_MAINLCD_128X128__ */
            );
        scroll_height = MMI_MENUITEM_HEIGHT;
    }
    
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - MMI_CAT1002_TEXT_GAP - GUI_MENUITEM_X2_GAP - MMI_ICONTEXT_MENUITEM_HEIGHT - GUI_MENUITEM_TEXT_RIGHT_GAP;
    x = GUI_ICONTEXT_MENUITEM_ICON_X + MMI_ICONTEXT_MENUITEM_HEIGHT;
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon() && icon_column == 2)
	{
		text_width -= w + 2;
		icon2_x = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP - w;
	}
#endif  
    set_fixed_icontext_list_icon_coordinates(0, x, 0, w, h);
#ifdef __GEMINI__
	if(wgui_cat_list_get_display_more_icon())
	{
		set_fixed_icontext_list_icon_coordinates(1, icon2_x, 0, w, h);
	}
#endif
    set_fixed_icontext_list_text_coordinates(2, x + MMI_ICONTEXT_MENUITEM_HEIGHT, 0, text_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(0, x + MMI_ICONTEXT_MENUITEM_HEIGHT, MMI_ICONTEXT_MENUITEM_HEIGHT, text_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(1, MAIN_LCD_DEVICE_WIDTH, 0, 0, 0); /* subject */
    
#ifdef __MMI_MAINLCD_320X480__
    MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->two_line_second_line_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->two_line_second_line_highlight_text_color;
    MMI_fixed_icontext_list_menuitem.normal_text_colors[2] = *current_MMI_theme->list_normal_text_color;//two_line_first_line_text_color
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
    MMI_fixed_icontext_list_menuitem.selected_text_colors[2] = *current_MMI_theme->list_selected_text_color;//two_line_first_line_highlight_text_color
#endif /* __MMI_MAINLCD_320X480__ */

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_ICONTEXT_LIST_ALL_TEXT_VERTICAL_ALIGN_CENTER;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;

    wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
    wgui_async_list_resize_multi_icontext_menu(MMI_content_width, MMI_content_height - scroll_height);

    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

	wgui_cat_setup_category_default_history(MMI_CAT1002_ID, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1002_exit);
    dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}

