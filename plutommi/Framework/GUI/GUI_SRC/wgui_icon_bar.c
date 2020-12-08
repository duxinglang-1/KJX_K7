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
 *  wgui_icon_bar.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Source
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"

#include "MMI_trc_Int.h"
/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "gui_icon_bar.h"
#include "wgui_icon_bar.h"
#ifdef __MMI_FTE_SUPPORT__
#include "wgui_categories_util.h"
#endif

#include "gui_switch.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "mmi_frm_input_gprot.h"

#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * Static Declaration
 ****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */
static gui_icon_bar_struct wgui_icon_bar;
#ifdef __MMI_FTE_SUPPORT__
static MMI_BOOL wgui_icon_bar_created = MMI_FALSE;
#endif
/*****************************************************************************
 * Global Variable
 ****************************************************************************/
/* Write your global variable here */


/*****************************************************************************
 * Local Function
 ****************************************************************************/

/*****************************************************************************
 * Global Function
 ****************************************************************************/
/* Write your global function here */
/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_setup_by_resource
 * DESCRIPTION
 *  Set items' content to icon bar.
 * PARAMETERS
 *  item_count              [IN]    count of items that need display
 *  resource_array          [IN]    item's content image
 *  callback                [IN]    callback function when item pressed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_setup_by_resource(
      S32 item_count,
      gui_icon_bar_item_resource_struct *resource_array,
      GUIIconbarItemCallback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    PU8 content_icon[WGUI_ICONBAR_MAX_COUNT];
    PU8 disabled_content_icon[WGUI_ICONBAR_MAX_COUNT];
    PU8 string[WGUI_ICONBAR_MAX_COUNT];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_count >= 0 && item_count <= WGUI_ICONBAR_MAX_COUNT);
    if (item_count == 0)
    {
        wgui_icon_bar_setup_ex(
            item_count,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            callback,
            MMI_FALSE,
            MMI_FALSE);
    }
    else
    {
        for (i = 0; i < item_count; i++)
        {
            content_icon[i] = resource_array[i].content_icon;
            disabled_content_icon[i] = resource_array[i].disabled_content_icon;
            string[i] = resource_array[i].text_of_description;
        }
        wgui_icon_bar_setup_ex(
            item_count,
            NULL,
            NULL,
            content_icon,
            disabled_content_icon,
            string,
            callback,
            MMI_FALSE,
            MMI_FALSE);
    }
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_setup
 * DESCRIPTION
 *  Set up an idle icon bar component content.
 * PARAMETERS
 *  item_count          [IN]    count of items that need display
 *  content_icon            [IN]    item's content image
 *  disabled_content_icon   [IN]    item's content image of its disabled state
 *  string                  [IN]    description of item
 *  callback                [IN]    callback function when item pressed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_setup(
          S32 item_count,
          PU8* content_icon,
          PU8* disabled_content_icon,
          PU8* string,
          GUIIconbarItemCallback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_icon_bar_setup_ex(
        item_count,
        NULL,
        NULL,
        content_icon,
        disabled_content_icon,
        string,
        callback,
        MMI_FALSE,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_setup_ex
 * DESCRIPTION
 *  Set up an idle icon bar component content. It is the extend API of
 *  wgui_icon_bar_setup.
 * PARAMETERS
 *  item_count              [IN]    count of items that need display
 *  normal_icon         [IN]    up image of item
 *  down_icon           [IN]    down image of item
 *  content_icon            [IN]    item's content image
 *  disabled_content_icon   [IN]    item's content image of its disabled state
 *  string              [IN]    description of item
 *  callback            [IN]    callback function when item pressed
 *  enable_key_event    [IN]    enable the left/right key event or not
 *  hint_use_double_buffer  [IN]    use double buffer to display hint
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_setup_ex(
          S32 item_count,
          PU8* normal_icon,
          PU8* down_icon,
          PU8* content_icon,
          PU8* disabled_content_icon,
          PU8* string,
          GUIIconbarItemCallback callback,
          MMI_BOOL enable_key_event,
          MMI_BOOL hint_use_double_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL use_default_background = MMI_FALSE;
    S32 i;
    S32 fixed_width = 0;
    PU8 normal_image = NULL, down_image = NULL;
    MMI_BOOL use_double_buffer = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_count >= 0 && item_count <= WGUI_ICONBAR_MAX_COUNT);
    if (item_count > 0)
    {
        /* the content icon, string and callback array should not be NULL */
        MMI_ASSERT((content_icon != NULL) &&
                   (disabled_content_icon != NULL) &&
                   (string != NULL) &&
                   (callback != NULL));
    }
    /* First close the current icon bar */
    if (wgui_icon_bar_created == MMI_TRUE)
    {
        gui_icon_bar_close(&wgui_icon_bar);
        wgui_icon_bar_created = MMI_FALSE;
    }
    if (item_count == 0)
    {
        return;
    }

    if (hint_use_double_buffer == MMI_TRUE && item_count > 1)
    {
        use_double_buffer = MMI_TRUE;
    }
    
    result = gui_icon_bar_create(
                 &wgui_icon_bar,
                 0,
                 UI_device_height - MMI_SOFTKEY_BAR_HEIGHT - MMI_ICON_BAR_HEIGHT,
                 UI_device_width,
                 MMI_ICON_BAR_HEIGHT,
                 item_count,
                 enable_key_event,
                 use_double_buffer);
    if (result == MMI_FALSE)
    {
        MMI_ASSERT(0);
    }

    if (normal_icon == NULL || down_icon == NULL)
    {
        use_default_background = MMI_TRUE;
    }
    for (i = 0; i < item_count; i++)
    {
        if (use_default_background == MMI_TRUE)
        {
            if (i == 0 && item_count == 1)
            {
                normal_image = current_MMI_theme->icon_bar_item_normal_left_right_background;
                down_image = current_MMI_theme->icon_bar_item_pressed_left_right_background;
            }
            else if (i == 0)
            {
                normal_image = current_MMI_theme->icon_bar_item_normal_left_background;
                down_image = current_MMI_theme->icon_bar_item_pressed_left_background;
            }
            else if (i == item_count - 1)
            {
                normal_image = current_MMI_theme->icon_bar_item_normal_right_background;
                down_image = current_MMI_theme->icon_bar_item_pressed_right_background;
            }
            else
            {
                normal_image = current_MMI_theme->icon_bar_item_normal_center_background;
                down_image = current_MMI_theme->icon_bar_item_pressed_center_background;
            }
            gui_icon_bar_set_item(
                &wgui_icon_bar,
                i,
                normal_image, // need change to the default normal background
                down_image, // need change to the default down background
                content_icon[i],
                disabled_content_icon[i],
                string[i],
                callback);
            gui_icon_bar_set_align(&wgui_icon_bar, GUI_ICON_BAR_ALIGN_BY_CENTER);
            if (item_count == 1)
            {
                fixed_width = WGUI_ICONBAR_ITEM_WIDTH_1;
            }
            else if (item_count == 2)
            {
                fixed_width = WGUI_ICONBAR_ITEM_WIDTH_2;
            }
            else if (item_count == 3)
            {
                fixed_width = WGUI_ICONBAR_ITEM_WIDTH_3;
            }
            else
            {
                fixed_width = WGUI_ICONBAR_ITEM_WIDTH_4;
            }
            gui_icon_bar_set_fixed_position_info(
                &wgui_icon_bar,
                fixed_width,
                WGUI_ICONBAR_ITEM_HEIGHT,
                WGUI_ICONBAR_ITEM_GAP);
        }
        else
        {
            gui_icon_bar_set_item(
                &wgui_icon_bar,
                i,
                normal_icon[i],
                down_icon[i],
                content_icon[i],
                disabled_content_icon[i],
                string[i],
                callback);
        }
    }

    if (item_count > 1)
    {
        gui_icon_bar_set_flags_on(&wgui_icon_bar, GUI_ICON_BAR_FLAG_ENABLE_HINT);
    }
    if (item_count == 1)
    {
        gui_icon_bar_set_flags_on(&wgui_icon_bar, GUI_ICON_BAR_FLAG_DRAW_HINT_AS_TEXT);
    }

    wgui_icon_bar_created = MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_item_state
 * DESCRIPTION
 *  Set the item enable or disable state of the icon bar.
 * PARAMETERS
 *  index                  [IN]    item's index
 *  state                  [IN]    item's enable or disable state
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_item_enable_state(
      S32 index,
      MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if (wgui_icon_bar_created == MMI_TRUE)
    {
#endif /* __MMI_FTE_SUPPORT__ */
        gui_icon_bar_set_item_enable_state(
            &wgui_icon_bar,
            index,
            state);
#ifdef __MMI_FTE_SUPPORT__
    }
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_update
 * DESCRIPTION
 *  Update icon bar. The API is provided for APP to refresh icon bar after they
 *  setup the new item count of icon bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    if (wgui_icon_bar_created == MMI_TRUE)
    {
#endif /* __MMI_FTE_SUPPORT__ */
        gui_icon_bar_show(&wgui_icon_bar);
        gdi_layer_blt_previous(
            wgui_icon_bar.x,
            wgui_icon_bar.y,
            wgui_icon_bar.x + wgui_icon_bar.width - 1,
            wgui_icon_bar.y + wgui_icon_bar.height - 1);
#ifdef __MMI_FTE_SUPPORT__
    }
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_is_created
 * DESCRIPTION
 *  Get the status of whether icon bar is created.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_icon_bar_is_created(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    return wgui_icon_bar_created;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_create
 * DESCRIPTION
 *  create an idle icon_bar component
 * PARAMETERS
 *  x               [IN]    x pos of icon_bar component
 *  y               [IN]    y pos of icon_bar component
 *  width           [IN]    x dimension of icon_bar component
 *  height          [IN]    y dimension of icon_bar component
 *  item_count      [IN]    count of items that need display
 *  background      [IN]    background of icon_bar component
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_icon_bar_create(
          S32 x,
          S32 y,
          S32 width,
          S32 height,
          S32 item_count,
          MMI_BOOL enable_key_event,
          MMI_BOOL hint_use_double_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_icon_bar_create(
               &wgui_icon_bar,
               x,
               y,
               width,
               height,
               item_count,
               enable_key_event,
               hint_use_double_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_close
 * DESCRIPTION
 *  close a icon_bar component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_close(&wgui_icon_bar);
#ifdef __MMI_FTE_SUPPORT__
    wgui_icon_bar_created = MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_get_history
 * DESCRIPTION
 *  get the history of icon_bar
 * PARAMETERS
 *  history     [OUT]   store icon_bar history
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_get_history(wgui_icon_bar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history->first_displayed_item = wgui_icon_bar.first_displayed_item;
    history->focused_item = wgui_icon_bar.focused_item;
    history->active = wgui_icon_bar.active;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_get_history_size
 * DESCRIPTION
 *  get the history size of icon_bar
 * PARAMETERS
 *  viod
 * RETURNS
 *  S32
 *****************************************************************************/
S32 wgui_icon_bar_get_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(wgui_icon_bar_history_struct));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_history
 * DESCRIPTION
 *  set the history of icon_bar
 * PARAMETERS
 *  history     [IN] history of icon_bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_history(wgui_icon_bar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_icon_bar.first_displayed_item = history->first_displayed_item;
    wgui_icon_bar.focused_item = history->focused_item;
    wgui_icon_bar.active = history->active;
    gui_icon_bar_resize(
        &wgui_icon_bar,
        wgui_icon_bar.width,
        wgui_icon_bar.height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_item
 * DESCRIPTION
 *  set one item of icon_bar
 * PARAMETERS
 *  index               [IN]    index of item
 *  normal_icon         [IN]    up image of item
 *  down_icon           [IN]    down image of item
 *  content_icon            [IN]    content icon of item
 *  disabled_content_icon   [IN]    disabled content icon of item
 *  text_of_description [IN]    hint
 *  callback            [IN]    callback func when key pressed
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_item(
      U32 index,
      U8 *normal_icon,
      U8 *down_icon,
      U8 *content_icon,
      U8 *disabled_content_icon,
      U8 *text_of_description,
      GUIIconbarItemCallback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_item(
        &wgui_icon_bar,
        index,
        normal_icon,
        down_icon,
        content_icon,
        disabled_content_icon,
        text_of_description,
        callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_arrow_icon
 * DESCRIPTION
 *  set arrow icon of icon_bar
 * PARAMETERS
 *  arrow               [IN]    left arrow or right arrow
 *  normal_icon         [IN]    up image of item
 *  down_icon           [IN]    down image of item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_arrow_icon(
      gui_icon_bar_arrow_enum arrow,
      U8 *normal_icon,
      U8 *down_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_arrow_icon(
        &wgui_icon_bar,
        arrow,
        normal_icon,
        down_icon);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_highlight_icon
 * DESCRIPTION
 *  set highlight icon of icon_bar
 * PARAMETERS
 *  highlignt_icon            [IN]    highlight icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_highlight_icon(U8 *highlight_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_highlight_icon(
        &wgui_icon_bar,
        highlight_icon);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_register_update_handler
 * DESCRIPTION
 *  register the update handler
 * PARAMETERS
 *  dynamic_update_handler         [IN]    index of start item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_register_update_handler(
      MMI_BOOL (*dynamic_update_handler)(
                 U32 start_index,
                 U32 item_count,
                 PU8 *normal_icon,
                 PU8 *down_icon,
                 PU8 *content_icon,
                 PU8 *disabled_content_icon,
                 PU8 *text_of_description))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_register_update_handler(
        &wgui_icon_bar,
        dynamic_update_handler);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_show
 * DESCRIPTION
 *  show icon_bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_show(&wgui_icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_move
 * DESCRIPTION
 *  move icon_bar
 * PARAMETERS
 *  x       [IN]
 *  y       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_move(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_move(&wgui_icon_bar, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_resize
 * DESCRIPTION
 *  resize icon_bar
 * PARAMETERS
 *  width       [IN]
 *  height      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_resize(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_resize(&wgui_icon_bar, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_align
 * DESCRIPTION
 *  set icon_bar's align type
 * PARAMETERS
 *  align_type       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_align(gui_icon_bar_align_enum align_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_align(&wgui_icon_bar, align_type);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_target_layer
 * DESCRIPTION
 *  set icon_bar's target layer
 * PARAMETERS
 *  target_layer       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_target_layer(GDI_HANDLE target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_target_layer(&wgui_icon_bar, target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_abm_layer
 * DESCRIPTION
 *  set icon_bar's abm layer
 * PARAMETERS
 *  abm_layer       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_abm_layer(GDI_HANDLE abm_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_abm_layer(&wgui_icon_bar, abm_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_fixed_position_info
 * DESCRIPTION
 *  Set fixed position information to icon bar.
 * PARAMETERS
 *  item_width          [IN]
 *  item_height         [IN]
 *  item_gap            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_fixed_position_info(
      S32 item_width,
      S32 item_height,
      S32 item_gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_fixed_position_info(
        &wgui_icon_bar,
        item_width,
        item_height,
        item_gap);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_is_active
 * DESCRIPTION
 *  set icon_bar's abm layer
 * PARAMETERS
 *  abm_layer       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_icon_bar_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_icon_bar_is_active(&wgui_icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_register_highlight_handler
 * DESCRIPTION
 *  set icon_bar's highlight handler
 * PARAMETERS
 *  f       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_register_highlight_handler(void (*f)(S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_register_highlight_handler(&wgui_icon_bar, f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_register_idle_display_handler
 * DESCRIPTION
 *  set icon_bar's idle display handler
 * PARAMETERS
 *  f       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_register_idle_display_handler(void (*f)(S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_register_idle_display_handler(&wgui_icon_bar, f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_register_hide_function
 * DESCRIPTION
 *  set the hide callback function of the icon_bar
 * PARAMETERS
 *  f               [IN]        New hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_register_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_register_hide_function(&wgui_icon_bar, f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_active
 * DESCRIPTION
 *  active icon_bar component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_active(&wgui_icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_deactive
 * DESCRIPTION
 *  deactive icon_bar component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_deactive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_deactive(&wgui_icon_bar);
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_translate_pen_event
 * DESCRIPTION
 *  translate icon_bar's pen event
 * PARAMETERS
 *  pen_event               [IN]
 *  x                       [IN]
 *  y                       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL wgui_icon_bar_translate_pen_event(
          mmi_pen_point_struct point,
          mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_icon_bar_translate_pen_event(
               &wgui_icon_bar,
               pen_event,
               point.x,
               point.y);
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_flags_on
 * DESCRIPTION
 *  Turn on flag of icon bar.
 * PARAMETERS
 *  flag                    [IN]    flag of icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_flags_on(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_flags_on(&wgui_icon_bar, flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_flags_off
 * DESCRIPTION
 *  Turn off flag of icon bar.
 * PARAMETERS
 *  flag                    [IN]    flag of icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_flags_off(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_flags_off(&wgui_icon_bar, flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_get_hint_layer_handle
 * DESCRIPTION
 *  Get the hint layer handle
 * PARAMETERS
 *  void
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
gdi_handle wgui_icon_bar_get_hint_layer_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_icon_bar_get_hint_layer_handle(&wgui_icon_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_set_display_direction
 * DESCRIPTION
 *  set icon_bar's display direction.
 * PARAMETERS
 *  direction           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_set_display_direction(
      gui_icon_bar_display_direction_enum direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_set_display_direction(&wgui_icon_bar, direction);
}


#ifdef __MMI_FTE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_register_pause_interactive_UI_callback
 * DESCRIPTION
 *  set icon_bar's callback to pause interactive UI
 * PARAMETERS
 *  f                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_register_pause_interactive_UI_callback(
      void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_register_pause_interactive_UI_callback(&wgui_icon_bar, f);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_register_resume_interactive_UI_callback
 * DESCRIPTION
 *  set icon_bar's callback to resume interactive UI
 * PARAMETERS
 *  f               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_register_resume_interactive_UI_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_register_resume_interactive_UI_callback(&wgui_icon_bar, f);
}
#endif

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_reset_pen_state
 * DESCRIPTION
 *  reset icon bar's pen state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_reset_pen_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_reset_pen_state(&wgui_icon_bar);
}
#else
/* here an empty function for SNS app which is released as library */
void wgui_icon_bar_reset_pen_state(void)
{
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_register_item_refresh_callback
 * DESCRIPTION
 *  set the refresh callback function of the icon_bar
 * PARAMETERS
 *  f               [IN] refresh callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_icon_bar_register_item_refresh_callback(MMI_BOOL (*f) (S32 index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_icon_bar_register_item_refresh_callback(&wgui_icon_bar, f);
}

#endif//__MMI_ICON_BAR_SUPPORT__
