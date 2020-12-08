/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_v2p_status_icon_bar.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to 
 *  the Pluto Inputbox components
 *
 *      Venus ---> v2p adaptor ---> Pluto 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Pluto headers */
#include "MMI_features.h"
#include "MMI_include.h"
#include "wgui_status_icon_bar.h"
#include "gui_typedef.h"

/* Venus headers */
#include "vadp_v2p_status_icon_bar.h"

#include "MMIDataType.h"
#include "wgui_categories_util.h"
#include "gdi_datatype.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "kal_general_types.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "gui_switch.h"
#include "wgui.h"




/**********************************************************************
 * Global Functions
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_show_icon
 * DESCRIPTION
 *  Adaption api of show an icon with icon ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void 
 *****************************************************************************/
void vadp_v2p_show_icon(S32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_show_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_blink_icon
 * DESCRIPTION
 *  Adaption api of blink an icon with icon ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_blink_icon(S32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_bar_blink_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_animate_icon
 * DESCRIPTION
 *  Adaption api of animate an icon with icon ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_animate_icon(S32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_animate_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_change_icon_level
 * DESCRIPTION
 *  Adaption api of change an icon level with icon ID and level percentage
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_change_icon_level(S32 iconId, U8 level_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_change_icon_level(iconId, level_percentage);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_change_icon_image
 * DESCRIPTION
 *  Adaption api of change an icon image with icon ID and image ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_change_icon_image(S32 iconId, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_change_icon_image(iconId, image_id);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_create_status_icon_bar
 * DESCRIPTION
 *  Adaption api of initialize the update callback for c => c++
 * PARAMETERS
 *  update_screen_callback  [IN]    update callback for plutoMMI
 *  update_screen_handle    [IN]    update handle for plutoMMI
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_icon_bar_set_layer(gdi_handle display_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, display_layer);
    wgui_status_icon_bar_set_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR, display_layer);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_show_status_icon_bar
 * DESCRIPTION
 *  Adaption api of show status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_show_status_icon_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_show(WGUI_STATUS_ICON_BAR_H_BAR);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_get_prefered_size
 * DESCRIPTION
 *  Adaption api of get prefered size
 * PARAMETERS
 *  width   [OUT]   width of size
 *  height  [OUT]   height of size
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_get_prefered_size(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *width = MAIN_LCD_DEVICE_WIDTH;
    *height = MMI_STATUS_BAR_HEIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_icon_bar_set_backgroud
 * DESCRIPTION
 *  Adaption api of enable background or not
 * PARAMETERS
 *  enable   [IN]    Enable background or not
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_icon_bar_set_backgroud(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(enable)
    {
        wgui_status_icon_bar_set_background(WGUI_STATUS_ICON_BAR_H_BAR);
    }
    else
    {
        wgui_status_icon_bar_reset_background(WGUI_STATUS_ICON_BAR_H_BAR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_icon_bar_close_clock
 * DESCRIPTION
 *  Adaption api of close clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_icon_bar_close_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_close_clock();
}



/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_hide_events
 * DESCRIPTION
 *  Adaption api of close clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_hide_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_hide_events();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_show_events
 * DESCRIPTION
 *  Adaption api of close clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_show_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_show_events();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_show_events
 * DESCRIPTION
 *  Adaption api of close clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_register_tap_proc(FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_register_tap_proc(handler);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_show_events
 * DESCRIPTION
 *  Adaption api of close clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_translate_pen_event(mmi_pen_event_type_enum type, S32 x, S32 y)
{
#ifdef __MMI_TOUCH_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id;
    wgui_status_icon_bar_pen_enum event_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_translate_pen_event(
        type,
        x,
        y,
        &icon_id,
        &event_type);

    if (event_type == WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON)      /* select an icon */
    {
        wgui_status_icon_bar_execute_pen_event_handler(icon_id, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON);
    }
    return;
#else
    return;
#endif
}


void vadp_v2p_set_status_translucent()
{

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_set_special_style(WGUI_STATUS_ICON_BAR_H_BAR, MMI_TRUE);
#endif
}


void vadp_v2p_reset_status_translucent()
{
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_reset_special_style(WGUI_STATUS_ICON_BAR_H_BAR);
#endif
}

void vadp_v2p_set_statusbar_BG(S32 id)
{
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_set_background_id(WGUI_STATUS_ICON_BAR_H_BAR, id);
#endif
}


MMI_BOOL vadp_v2p_status_is_in_ncenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    return wgui_status_icon_bar_is_in_ncenter();
#else
    return MMI_FALSE;
#endif
}

void vadp_v2p_hide_statusbar(MMI_BOOL bHide)
{
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_hide_bar(bHide);
#endif
}

void vadp_v2p_set_statusbar_freeze(MMI_BOOL bFreeze)
{
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_freeze_animate(bFreeze);
#endif
}

void vadp_v2p_status_icon_bar_add_instance(status_icon_bar_chain_node_struct* chain_node)
{
#ifdef __MMI_VUI_ENGINE__
    wgui_status_icon_bar_add_instance(WGUI_STATUS_ICON_BAR_H_BAR, chain_node);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
#endif
}

void vadp_v2p_status_icon_bar_del_instance(status_icon_bar_chain_node_struct* chain_node)
{
#ifdef __MMI_VUI_ENGINE__
    wgui_status_icon_bar_del_instance(WGUI_STATUS_ICON_BAR_H_BAR, chain_node);
#endif
}

void vadp_v2p_statusbar_abort_enter_ncenter(void)
{
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    wgui_status_icon_bar_abort_enter_ncenter();
#endif
}

