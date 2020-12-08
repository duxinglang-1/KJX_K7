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
 *   gui_font_size.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Adaptation layer of vector font
 *
 *   
 *
 * Author:
 * -------
 * -------
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
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "gui_font_size.h"
#include "gui_font_oem.h"
#include "mmi_frm_gprot.h"

extern MMI_theme *current_MMI_theme;
extern stFontAttribute wgui_dialer_box_f1;
extern stFontAttribute wgui_dialer_box_f2;

/*****************************************************************************
 * FUNCTION
 *  gui_font_get_type
 * DESCRIPTION
 *  Get the font type
 * PARAMETERS
 *  index       [IN]        index
 * RETURNS
 *  UI_font_type 
 *****************************************************************************/
/*const */UI_font_type gui_font_get_type(gui_font_size_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X64__)
    switch(index)
    {
        case GUI_FONT_SIZE_DIALER_LARGE:
            return &wgui_dialer_box_f1;
        case GUI_FONT_SIZE_DIALER_SMALL:
            return &wgui_dialer_box_f2;
        case GUI_FONT_SIZE_LIST:
            return &MMI_medium_font;
		case GUI_FONT_SIZE_LIST_HIGHLIGHT:
			return &MMI_medium_font;
        default:
            return &MMI_small_font;
    }
//#endif
#else/*__MMI_MAINLCD_128X64__*/

#ifdef __MMI_VECTOR_FONT_SUPPORT__
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (mmi_tm_get_curr_theme_type() == THEME_TYPE_SYSTEM)
#endif
    {
        return gui_font_oem_get_type(index);
    }
#else//#endif /* __MMI_VECTOR_FONT_SUPPORT__ */

    switch(index)
    {

    case GUI_FONT_SIZE_BUTTON:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_MULTITAP:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_INPUTBOX:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_LIST:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_MATRIX:
        
#if (defined(__MMI_MAINLCD_240X320__) && defined(__MMI_TOUCH_SCREEN__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X480__))
        return &MMI_small_font;
#else
        return &MMI_medium_font;
#endif

    case GUI_FONT_SIZE_MENUBAR_INDEX:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_MENUBAR_ITEM:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_SHORTCUT:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_TITLE:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_DROPDOWN:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_LIST_MAINMENU:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_MATRIX_MAINMENU:
#if (defined(__MMI_MAINLCD_240X320__) && defined(__MMI_TOUCH_SCREEN__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X480__))
        return &MMI_small_font;
#else
        return &MMI_medium_font;
#endif

    case GUI_FONT_SIZE_VIRTUAL_KEYBOARD:
        return &MMI_virtual_keyboard_font;

    case GUI_FONT_SIZE_DATE:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_TIME:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_SUB_DATE:
        return &MMI_small_font;

    case GUI_FONT_SIZE_SUB_TIME:
        return &MMI_small_font;

    case GUI_FONT_SIZE_TAB_TITLE:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_CALENDAR_INFOBOX:
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X320__)
        return &MMI_small_font;
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
        return &MMI_medium_font;
#else
        return &MMI_small_font;
#endif

    case GUI_FONT_SIZE_CALENDAR_HORIZONTAL_STRING:
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
        return &MMI_sublcd_font;
#else
        return &MMI_small_font;
#endif

    case GUI_FONT_SIZE_CALENDAR_CELL:
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_96X64__)
        return &MMI_sublcd_font;
#elif defined(__MMI_MAINLCD_320X480__)
		return &MMI_small_font;	
#else
        return &MMI_small_font;
#endif

    case GUI_FONT_SIZE_IDLE_CALENDAR_HORIZONTAL:
    #if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
        return &MMI_sublcd_font;
    #elif defined(__MMI_MAINLCD_320X480__)
		return &MMI_small_font;
    #else
        return &MMI_sublcd_font;
    #endif


    case GUI_FONT_SIZE_IDLE_CALENDAR_CELL:
    #if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
        return &MMI_sublcd_font;
    #elif defined(__MMI_MAINLCD_320X480__)
        return &MMI_small_font;
    #else
        return &MMI_sublcd_font;
    #endif

    case GUI_FONT_SIZE_DCD_IDLE:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_IME_TEXT:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_IME_LABEL:
        return &MMI_small_font;
        
    case GUI_FONT_SIZE_DURATION:
        return &MMI_large_font;

    case GUI_FONT_SIZE_DOW_SELECT:
        return &MMI_medium_font;


    case GUI_FONT_SIZE_DAY:
            #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
                return &MMI_medium_font;
            #else
                return &MMI_small_font;
            #endif /* __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__ */

    case GUI_FONT_SIZE_DATE_IDLESCREEN1:
            #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)&& (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
                return &MMI_large_font;
            #elif defined(__MMI_UI_DALMATIAN_IDLESCREEN__)
                return &MMI_medium_font;
            #else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
                #if defined  (__MMI_MAINLCD_128X160__)
                    return &MMI_small_font;
                #else
                    return &MMI_medium_font;
                #endif /* __MMI_MAINLCD_128X160__ */
            #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

    case GUI_FONT_SIZE_TIME_IDLESCREEN1:
            #if defined(__MMI_UI_DALMATIAN_IDLESCREEN__)
                return &MMI_medium_font;
            #elif defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
                return &MMI_medium_font;
            #else /* __MMI_UI_DALMATIAN_IDLESCREEN__ */
                #if defined(__MMI_MAINLCD_128X160__)
                    return &MMI_medium_font;
                #else
                    return &MMI_large_font;
                #endif /* __MMI_MAINLCD_128X160__ */
            #endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */

    #ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
        case GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM:
                return &MMI_small_font;
    #endif /* __MMI_UI_STATUS_BAR_AT_BOTTOM__ */

    case GUI_FONT_SIZE_TIME_NETWORK_SEARCH:
            return &MMI_large_font;

    case GUI_FONT_SIZE_DURATION_ACTIVE_CALL:
            return &MMI_small_font;

    case GUI_FONT_SIZE_DURATION_CONF_CALL:
            return &MMI_medium_font;
       

#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
    case GUI_FONT_SIZE_SUB_LARGE_DATE:
            return &MMI_large_font;
#endif /* __MMI_SUBLCD_DATE_LARGE_FONT__ */

#ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
    case GUI_FONT_SIZE_SUB_LARGE_TIME:
            return &MMI_large_font;

    case GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3:
            return &MMI_sublcd_font;
#endif /* __MMI_SUBLCD_TIME_LARGE_FONT__ */

    case GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4:
            return &MMI_medium_font;

    case GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4:
            return &MMI_sublcd_font;

    case GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC:
            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                return &MMI_medium_font;
            #else
                return &MMI_large_font;
            #endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */

    case GUI_FONT_SIZE_DURATION_AUDIO_PLAY:
            #ifdef __MMI_UI_DALMATIAN_IDLESCREEN__
                return &MMI_medium_font;
            #else
                return &MMI_large_font;
            #endif /* GUI_FONT_SIZE_DURATION_AUDIO_PLAY */

    case GUI_FONT_SIZE_IDLE_NETWORK_NAME:
        #if (defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
            return &MMI_large_font;
        #else
            return &MMI_medium_font;
        #endif
        
    case GUI_FONT_SIZE_IDLE_NETWORK_STATUS:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_IDLE_DATE:
        #if defined  (__MMI_MAINLCD_128X160__)
            return &MMI_small_font;
        #else
            return &MMI_medium_font;
        #endif

    case GUI_FONT_SIZE_DIALER:
        return &MMI_default_font;

    case GUI_FONT_SIZE_INFOBOX:
        return &MMI_small_font;

    case GUI_FONT_SIZE_DEFAULT:
        return &MMI_default_font;

    case GUI_FONT_SIZE_DIALER_LARGE:
        return &wgui_dialer_box_f1;

    case GUI_FONT_SIZE_DIALER_SMALL:
        return &wgui_dialer_box_f2;
        
    case GUI_FONT_SIZE_CALENDAR_TITLE:
    #ifndef __MMI_FTE_SUPPORT__
        return &MMI_medium_font;
    #else
        return &MMI_small_font;
    #endif

    case GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_CALENDAR_POPUP:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DAY:
        #if defined  (__MMI_MAINLCD_320X480__)
            return &MMI_medium_font;
        #else
            return &MMI_large_font;
        #endif

    case GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DATE:
        #if defined  (__MMI_MAINLCD_320X480__)
			return &wgui_dialer_box_f1;
        #else
            return &MMI_large_font;
        #endif

    case GUI_FONT_SIZE_CALENDAR_VERTICAL_SELECT:
#if defined  (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__)
        return &MMI_sublcd_font;
#elif defined (__MMI_MAINLCD_320X480__)
		return &MMI_small_font;
#else
        return &MMI_small_font;
#endif

    case GUI_FONT_SIZE_CALENDAR_CURRENT:
#if defined  (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_96X64__)
        return &MMI_sublcd_font;
#elif defined (__MMI_MAINLCD_320X480__)
		return &MMI_medium_font;
#elif defined (__MMI_MAINLCD_176X220__)
        return &MMI_medium_font;
#else
        return &MMI_small_font;
#endif

    case GUI_FONT_SIZE_ICONBAR_HINT:
#ifndef __MMI_FTE_SUPPORT__
        return &MMI_sublcd_font;
#else
        return &MMI_medium_font;
#endif


    case GUI_FONT_SIZE_VK_LARGE_ICON:
        return &MMI_medium_font;
        
    case GUI_FONT_SIZE_STATUS_BAR_TIME:
        return &MMI_sublcd_font;
        
    case GUI_FONT_SIZE_POPUP_EMBEDDED_SOFTKEY:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_LIST_HIGHLIGHT:
        return &MMI_medium_font;
        
    case GUI_FONT_SIZE_STOPWATCH_DURATION:
#if defined (__MMI_MAINLCD_320X480__)
        return &wgui_dialer_box_f1;
#elif defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) 
        return &MMI_large_font;
#else 
        return &MMI_small_font;
#endif 


    case GUI_FONT_SIZE_STOPWATCH_NWAY_TIME:
#if defined (__MMI_MAINLCD_320X480__)
        return &MMI_medium_font;
#else
        return &MMI_small_font;
#endif

    case GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE:
#if defined (__MMI_MAINLCD_320X480__)
        return &MMI_large_font;
#else
        return &MMI_small_font;
#endif

    case GUI_FONT_SIZE_ICONBAR_ITEM_TEXT:
        return &MMI_medium_font;

    case GUI_FONT_SIZE_IDLE_CALENDAR_TITLE:
#ifndef __MMI_VUI_HOMESCREEN__
        return &MMI_sublcd_font;
#else
        return &MMI_sublcd_font;
#endif

    default:
        return &MMI_default_font;
    }
#endif/*__MMI_VECTOR_FONT_SUPPORT__*/
#endif /*__MMI_MAINLCD_128X64__*/
}

