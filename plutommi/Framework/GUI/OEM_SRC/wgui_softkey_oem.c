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
 *  wgui_softkey_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Extract the codes related drawing into this file for oem
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
#include "MMI_features.h"
#include "lcd_sw_inc.h"
#include "gdi_include.h"
#include "CustDataRes.h"
#include "ScreenRotationGprot.h"
#include "mmi_rp_app_uiframework_def.h"
#include "Gui_Setting.h"
#include "gui_config.h"
#include "gui_buttons.h"
#include "gui.h"
#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "wgui.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "wgui_softkeys_pre_oem.h"
#include "wgui_softkeys.h"
#include "wgui_softkeys_post_oem.h"

static void show_softkey_background_with_clipping(S32 x1, S32 y1, S32 x2, S32 y2);



/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_oem_show
 * DESCRIPTION
 *  show sofutkey
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_oem_show(WGUI_SOFTKEY_ENUM key)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	//GDI_HANDLE target_layer, abm_layer;
   	//baiwenlin 20130830
#if defined(__OLED_BW_MMI__)
    return;
#endif /* __OLED_BW_MMI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	setSoftkeyTargetLayer(MMI_FALSE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
    gui_show_icontext_button(&MMI_softkeys[(WGUI_SOFTKEY_ENUM)key]);

    restoreSoftkeyTargetLayer();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  wgui_softkey_oem_hide
 * DESCRIPTION
 *  show sofutkey
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_softkey_oem_hide(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern S32 MMI_softkey_height;
    icontext_button b;
    //GDI_HANDLE target_layer, abm_layer;
   // MMI_BOOL enable_double_buffer = MMI_FALSE;
    S32 offset_x = 0, offset_y = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((WGUI_SOFTKEY_ENUM)key < WGUI_MAX_SOFTKEYS)
    {
        b = MMI_softkeys[key];
		if(b.width <= 0 || b.height <= 0)
		{
		    return;
		}
    }
   //target_layer = wgui_softkey_get_target_layer();
	
	setSoftkeyTargetLayer(MMI_FALSE);
	if(wgui_softkey_get_target_layer()!= GDI_NULL_HANDLE)
		 gdi_layer_get_position(&offset_x, &offset_y);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
    if ((WGUI_SOFTKEY_ENUM)key == WGUI_MAX_SOFTKEYS)
    {
    #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
        #ifndef __COSMOS_MMI__
            show_softkey_background_with_clipping(
                MMI_ROTATED_BUTTON_BAR_X + 1 - offset_x /* TEMP FIX */ ,
                MMI_ROTATED_BUTTON_BAR_Y - offset_y,
                MMI_ROTATED_BUTTON_BAR_X + MMI_ROTATED_BUTTON_BAR_WIDTH - 1 - offset_x,
                MMI_ROTATED_BUTTON_BAR_Y + MMI_ROTATED_BUTTON_BAR_HEIGHT - 1 - offset_y);
        #else
            show_softkey_background_with_clipping(
                0 - offset_x,
                UI_device_height - MMI_softkey_height - offset_y,
                UI_device_width - 1 - offset_x,
                UI_device_height - 1 - offset_y);
        #endif
        }
        else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
            show_softkey_background_with_clipping(
                0 - offset_x,
                UI_device_height - MMI_softkey_height - offset_y,
                UI_device_width - 1 - offset_x,
                UI_device_height - 1 - offset_y);
    }
    else if ((WGUI_SOFTKEY_ENUM)key<WGUI_MAX_SOFTKEYS )//((WGUI_SOFTKEY_ENUM)key == MMI_LEFT_SOFTKEY)//
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)       /* 041205 Calvin modieid */
        if (!(b.flags & UI_BUTTON_NO_UNDER_BAR))
    #else
        if (!(b.flags & UI_BUTTON_DISABLE_BACKGND_DISPLAY))
    #endif
            {
    #ifdef __MMI_SCREEN_ROTATE__
                if (mmi_frm_is_screen_width_height_swapped())
                {
                #ifndef __MMI_FTE_SUPPORT__
                    show_softkey_background_with_clipping(
                        b.x - offset_x,
                        b.y - offset_y,
                        b.x + b.width - offset_x,
                        b.y + b.height - offset_y);
                #else
                    show_softkey_background_with_clipping(
                        b.x - offset_x,
                        b.y - offset_y,
                        b.x + b.width - 1 - offset_x,
                        b.y + b.height - 1 - offset_y);
                #endif
                }
                else
    #endif /* __MMI_SCREEN_ROTATE__ */ 
                #ifndef __MMI_FTE_SUPPORT__
                    show_softkey_background_with_clipping(
                        b.x - offset_x,
                        UI_device_height - MMI_softkey_height - offset_y,
                        b.x + b.width - offset_x,
                        UI_device_height - 1 - offset_y);
                #else
                    show_softkey_background_with_clipping(
                        b.x - offset_x,
                        UI_device_height - MMI_softkey_height - offset_y,
                        b.x + b.width - 1 - offset_x,
                        UI_device_height - 1 - offset_y);
                #endif
            }
    }
#if 0	
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)       /* 041205 Calvin modieid */
/* under construction !*/
    #else 
/* under construction !*/
    #endif 
/* under construction !*/
    #ifdef __MMI_SCREEN_ROTATE__
/* under construction !*/
/* under construction !*/
                #ifndef __MMI_FTE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SCREEN_ROTATE__ */ 
                #ifndef __MMI_FTE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)       /* 041205 Calvin modieid */
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
    #ifdef __MMI_SCREEN_ROTATE__
/* under construction !*/
/* under construction !*/
                #ifndef __MMI_FTE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                 #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SCREEN_ROTATE__ */ 
                #ifndef __MMI_FTE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
#endif
    restoreSoftkeyTargetLayer();
 #if 0  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}

/*****************************************************************************
 * FUNCTION
 *  show_softkey_background_with_clipping
 * DESCRIPTION
 *  Draws a background behind the softkeys with clipping
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_softkey_background_with_clipping(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern S32 MMI_softkey_height;
    S32 offset_x = 0, offset_y = 0;
  //  MMI_BOOL enable_double_buffer = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  enable_double_buffer = wgui_softkey_get_double_buffer_enable();
//    if (enable_double_buffer == MMI_TRUE)
    {
        gdi_layer_get_position(&offset_x, &offset_y);
    }

#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        gui_push_clip();
        gui_reset_clip();
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    #ifdef __COSMOS_MMI__
        //gdi_image_draw_resized_id(x1, y1, x2 - x1 + 1, y2 - y1 + 1, IMG_SOFTKEY_BAR);
           gui_draw_filled_area(
                0, 
                UI_device_height - MMI_softkey_height - offset_y,
                UI_device_width - 1,
                UI_device_height - 1,
                current_MMI_theme->popup_softkey_bar_filler);        
    #endif
        gui_pop_clip();
        return;
    }
#endif /* __MMI_SCREEN_ROTATE__ */ 

    //gui_push_clip();
    gui_push_and_set_clip(x1, y1, x2, y2);
#if defined( __MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__) || defined (__MMI_MAINLCD_480X800__)
    if (wgui_softkey_is_in_popup())// == MMI_TRUE
    {
    #if (defined( __MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)) && !defined(__MMI_FTE_SUPPORT__)
        gui_pop_clip();
        return;
    #else /* __MMI_MAINLCD_320X480__ */
	   
        //if (MMI_softkey_filler_disabled)
        //{
        //    gdi_image_draw_resized_id(0, UI_device_height - MMI_softkey_height - offset_y, UI_device_width, MMI_softkey_height, IMG_SOFTKEY_BAR);
        //}
        //else if (current_MMI_theme->popup_softkey_bar_filler)
        // if (current_MMI_theme->popup_softkey_bar_filler)
        //{
           gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT); 
           gui_draw_filled_area(
                0, 
                UI_device_height - MMI_softkey_height - offset_y,
                UI_device_width - 1,
                UI_device_height - 1,
                current_MMI_theme->softkey_bar_bkg_filler);  
       // }
        //else
       // {
         //   gdi_image_draw_resized_id(0, UI_device_height - MMI_softkey_height - offset_y, UI_device_width, MMI_softkey_height, IMG_SOFTKEY_BAR);
        //}
		
    #endif /* __MMI_MAINLCD_320X480__ */
    }
    else //if (wgui_is_wallpaper_on_bottom())// == MMI_TRUE
    {
        //if (MMI_softkey_filler_disabled)
        //{
        //    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        //}
		//else if (current_MMI_theme->softkey_bar_bkg_filler)
		 if (current_MMI_theme->softkey_bar_bkg_filler)
		{
		/*gui_draw_filled_area(x1, y1, x2, y2, current_MMI_theme->softkey_bar_bkg_filler);*/
			    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
	    /*        gui_draw_filled_area(
	                0, 
	                UI_device_height - MMI_softkey_height - offset_y,
	                UI_device_width - 1,
	                UI_device_height - 1,
	                current_MMI_theme->softkey_bar_bkg_filler);
	         */
	      gui_draw_filled_area(x1, y1, x2, y2, current_MMI_theme->softkey_bar_bkg_filler);   
		}
		else
		{
			gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
		}
    }
    //else
    //{
    //        gdi_image_draw_resized_id(0, UI_device_height - MMI_softkey_height - offset_y, UI_device_width, MMI_softkey_height, IMG_SOFTKEY_BAR);
    //}
#else 
//    gui_fill_rectangle(x1, y1, x2, y2, c);
    /*gui_draw_filled_area(x1, y1, x2, y2, current_MMI_theme->softkey_bar_bkg_filler);*/
    if (current_MMI_theme->softkey_bar_bkg_filler)
	{
            gui_draw_filled_area(
            0, 
            UI_device_height - MMI_softkey_height - offset_y,
            UI_device_width - 1,
            UI_device_height - 1,
            current_MMI_theme->softkey_bar_bkg_filler);
	}
	else
	{
		gdi_draw_solid_rect(
			0, 
			UI_device_height - MMI_softkey_height - offset_y,
			UI_device_width - 1,
			UI_device_height - 1,
			GDI_COLOR_WHITE);
	}
#endif 

    gui_pop_clip();
}



