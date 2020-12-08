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
 *  gui_title.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  title related funtions
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "wgui.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "Wgui_title.h"
#include "gui_title.h"
#include "wgui_include.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

#ifdef __MMI_UI_TITLE_TRANSITION__
#define GUI_TITLE_TRANSITION_R2L_COUNT 5        /* UI_device_width; */
#define GUI_TITLE_TRANSITION_L2R_COUNT 5        /* UI_device_width; */
#endif /* __MMI_UI_TITLE_TRANSITION__ */

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
#define GUI_TITLE_EFFECT_TYPE__(A)   MMI_UI_TITLE_IMAGE_ANIMATE_##A
#define GUI_TITLE_EFFECT_TYPE_(A)    GUI_TITLE_EFFECT_TYPE__(A)
#define GUI_TITLE_EFFECT_TYPE(A)     GUI_TITLE_EFFECT_TYPE_(A)

#define GUI_TITLE_IMAGE_ANIMATION_TIMER 50
#define SHIFT_TITLE_IMAGE 5
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */


/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Variable
 *****************************************************************************/
UI_window_title_theme *current_window_title_theme = NULL;
UI_window_title_theme *current_thick_title_theme = NULL;
U16 title_bg_id = 0;    /* added for customized title background image */



static MMI_BOOL g_gui_title_is_in_wap = MMI_FALSE;

#ifdef __MMI_UI_TITLE_TRANSITION__
S32 g_title_prev_menu_shortcut = -1;
S32 g_title_temp_last_shortcut = -1;
static bitmap g_title_bitmap_for_transition;
static U8 bitmap_data_for_title_transition[LCD_WIDTH * MAX_TITLE_AREA_HEIGHT_FOR_TRANSITION * __MMI_MAIN_BASE_LAYER_FORMAT__]; /* for 16 bit */
    #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
        static S32 transition_required = 0;
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
#endif /* __MMI_UI_TITLE_TRANSITION__ */

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
static gui_title_struct *g_gui_title_current_animation_target;
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */

/*****************************************************************************
 * Local Function
 *****************************************************************************/

S32 (*gui_title_show_normal) (gui_title_struct *, U32) = NULL;
void (*gui_title_show_background) (gui_title_struct *, S32, S32, S32, S32) = NULL;
void (*gui_title_measure)(gui_title_struct *t, U32 part, S32 *x1, S32 *x2, S32 *h) = NULL;

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
void (*gui_title_show_status_icon)(gui_title_struct * t) = NULL;
#endif

#ifdef __MMI_UI_TITLE_TRANSITION__
static void gui_title_get_bitmap_for_transition(gui_title_struct *t);
static MMI_BOOL gui_title_pre_show(gui_title_struct *t);
static gui_title_struct *g_gui_title_transition_target;
    #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
        #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
        static void gui_title_show_previous_for_transition(gui_title_struct *t);
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
        static void gui_title_show_transition_non_blocking(void);
    #else /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
        static void gui_title_show_transition(gui_title_struct *t);
    #endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);
#endif /* __MMI_UI_TITLE_TRANSITION__ */

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
static void gui_title_animate_image(void);
static void gui_title_show_animate_image(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2);
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */


/*****************************************************************************
 * Local funciton
 *****************************************************************************/

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  gui_title_animate_image
 * DESCRIPTION
 *  Call draw title & set reset the next frame variable to check, Internal & external call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_animate_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_title_current_animation_target->next_frame = MMI_TRUE;
    gui_lock_double_buffer();
    if (g_gui_title_current_animation_target)
    {
        gui_title_show(g_gui_title_current_animation_target, GUI_TITLE_PART_ALL);
        /* wgui_title_show(GUI_TITLE_PART_ALL); */
    }
    gui_unlock_double_buffer();
#ifdef __MMI_VUI_ENGINE__
    if(g_gui_title_current_animation_target->venus_update_screen_callback)
    {
        g_gui_title_current_animation_target->venus_update_screen_callback(g_gui_title_current_animation_target->venus_update_screen_handle);
    }
    else
    {
#endif
        gdi_layer_blt_previous(
            g_gui_title_current_animation_target->x,
            g_gui_title_current_animation_target->y,
            g_gui_title_current_animation_target->x + g_gui_title_current_animation_target->width - 1,
            g_gui_title_current_animation_target->y + g_gui_title_current_animation_target->height - 1);
#ifdef __MMI_VUI_ENGINE__
    }
#endif
    g_gui_title_current_animation_target->next_frame = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_animate_image
 * DESCRIPTION
 *  Displays the moving image for moving title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x1      [IN]
 *  y1      [IN]
 *  x2      [IN]
 *  y2      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_animate_image(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, no_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(t);
    gui_measure_image(get_image(IMG_TITLE_SCROLL), &iwidth, &iheight);
    if (iheight < y2 - y1)
    {
        y1 = y1 + (((y2 - y1 + 1) - iheight) >> 1);
    }
    no_frame = gui_image_n_frames(get_image(IMG_TITLE_SCROLL));
    if (no_frame == 1)
    {
        gui_show_image(x1 + t->animate_move, y1, get_image(IMG_TITLE_SCROLL));
        if ((t->animate_move >= x2) && t->animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_CONTINOUS)
        {
            t->animate_move = t->animate_move - x2 - iwidth;
        }
        else
        {
            t->animate_move = t->animate_move + SHIFT_TITLE_IMAGE;
        }
        gui_start_timer(GUI_TITLE_IMAGE_ANIMATION_TIMER, gui_title_animate_image);
    }
    else
    {
        gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), 0);
        if (t->current_frame_count != 0)
        {
            gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), (S16) t->current_frame_count);   /* Show frame by frame no. */
        }
        if (t->current_frame_count == no_frame)
        {
            t->current_frame_count = -1;
        }
        gui_start_timer(GUI_TITLE_IMAGE_ANIMATION_TIMER, gui_title_animate_image);
        if (t->animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_ONCE && t->current_frame_count == -1)
        {
            return;
        }
        t->current_frame_count++;
    }
    t->backup_frame_count = t->current_frame_count;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_animate_image_frame_0
 * DESCRIPTION
 *  Displays the first frame of moving image for moving title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x1      [IN]
 *  y1      [IN]
 *  x2      [IN]
 *  y2      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_show_animate_image_frame_0(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, no_frame;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(t);
    UI_UNUSED_PARAMETER(x2);

    old_lcd_handle = gui_title_setup_target_lcd_and_layer(t);
    gui_measure_image(get_image(IMG_TITLE_SCROLL), &iwidth, &iheight);
    if (iheight < y2 - y1)
    {
        y1 = y1 + (((y2 - y1 + 1) - iheight) >> 1);
    }
    no_frame = gui_image_n_frames(get_image(IMG_TITLE_SCROLL));
    if (no_frame == 1)
    {
        gui_show_image(x1 + t->animate_move, y1, get_image(IMG_TITLE_SCROLL));
    }
    else if (no_frame > 1)
    {
        gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), 0);
        if (t->current_frame_count != -1 && (t->backup_frame_count != -1 && t->backup_frame_count != 0))
        {
            gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), (S16) (t->backup_frame_count - 1));
        }
    }

    gui_title_restore_target_lcd_and_layer(t, old_lcd_handle);
}
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */


#ifdef __MMI_UI_TITLE_TRANSITION__

/*****************************************************************************
 * FUNCTION
 *  gui_title_set_transition_enable
 * DESCRIPTION
 *  enable transition
 * PARAMETERS
 *  t               [IN/OUT]        Is the struct of title
 *  enable          [IN]
  * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_transition_enable(gui_title_struct *t, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->enable_transition = enable;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_transition_enable
 * DESCRIPTION
 *  is title transition enalbed
 * PARAMETERS
 *  t               [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_is_transition_enable(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->enable_transition;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_bitmap_for_transition
 * DESCRIPTION
 *  This functions is for getting the bitmap for previous title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_get_bitmap_for_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_title_bitmap_for_transition.data = bitmap_data_for_title_transition;
    _get_bitmap(
        t->prev_title_x,
        MMI_title_y,
        t->prev_title_x + MMI_title_width - 1,
        MMI_title_y + MMI_title_height - 1,
        &g_title_bitmap_for_transition);
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_pre_show
 * DESCRIPTION
 *  Do something before show title in transition
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *****************************************************************************/
static MMI_BOOL gui_title_pre_show(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bitblt = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_title_transition_target = t;
#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
    if (t->enable_transition && is_in_nonblocking_title_transition() == 0)
    {
        if (t->prev_icon || mmi_ucs2strlen((const s8*)t->prev_text) == 0)
        {
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
            gui_title_get_bitmap_for_transition(t);
        #endif
        }
    }
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    if (is_in_nonblocking_title_transition() == 0 && g_title_bitmap_for_transition.data != NULL)
#else
    if (is_in_nonblocking_title_transition() == 0 && transition_required == 1)
#endif
    {
#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
        if (t->transition_style && t->check_for_transition)
        {
            if (t->transition_on_keys)
            {
                U16 keyCode, keyType;

                GetkeyInfo(&keyCode, &keyType);
                if (keyCode == KEY_RIGHT_ARROW)
                {
                    set_title_transition(WGUI_TRANSITION_R2L);

                    t->check_for_transition = 0;
                #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
                    disable_animated_title_effect();
                #endif
                #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
                    gui_title_show_transition_non_blocking();
                #else
                    gui_title_show_transition(t);
                #endif
                #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
                    enable_animated_title_effect();
                #endif
                    t->check_for_transition = 1;
                }
                else if (keyCode == KEY_LEFT_ARROW)
                {
                    set_title_transition(WGUI_TRANSITION_L2R);
                    t->check_for_transition = 0;
                #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
                    gui_title_show_transition_non_blocking();
                #else
                    gui_title_show_transition(t);
                #endif
                    t->check_for_transition = 1;
                }
                else
                {
                    bitblt = MMI_FALSE;
                }
            }
            else
            {
                t->check_for_transition = 0;
            #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
                gui_title_show_transition_non_blocking();
            #else
                gui_title_show_transition(t);
            #endif
                t->check_for_transition = 1;
            }
        }
    #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
    }
    else
    {
    #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
        if (g_title_bitmap_for_transition.data == NULL && is_in_nonblocking_title_transition() == 0 &&
            (t->check_for_transition && t->transition_style))
    #else /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
        if (is_in_nonblocking_title_transition() == 0 && transition_required == 0 &&
            (t->check_for_transition && t->transition_style))
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
        {
            bitblt = MMI_FALSE;
        }
    }
    #endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
    return bitblt;
}


#if(!TITLE_TRANSITION_STYLE_NON_BLOCKING)
/*****************************************************************************
 * FUNCTION
 *  gui_title_show_transition
 * DESCRIPTION
 *  This functions draws the transition title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (t->transition_style)
    {
        case WGUI_TRANSITION_R2L:
        {
            S32 prev_x = t->x;
            S32 prev_width = t->width;
            S32 i, transition_count;
            S32 transition_resolution;

            i = transition_count = GUI_TITLE_TRANSITION_R2L_COUNT;
            transition_resolution = t->width / transition_count;
            t->x = t->x + t->width - 1;
            while (i - 1)
            {
                t->x -= transition_resolution;

                gui_title_show(t, GUI_TITLE_PART_ALL);
                i--;
            }
            t->width = prev_width;
            t->x = prev_x;

        }
            break;
        case WGUI_TRANSITION_L2R:
        {
            S32 prev_x = t->x;
            S32 prev_width = t->width;
            S32 i, transition_count;
            S32 transition_resolution;

            i = transition_count = GUI_TITLE_TRANSITION_L2R_COUNT;
            transition_resolution = t->width / transition_count;
            t->x -= t->width;
            while (i - 1)
            {
                t->x += transition_resolution;
                gui_title_show(t, GUI_TITLE_PART_ALL);
                i--;
            }
            t->width = prev_width;
            t->x = prev_x;

        }
            break;
    }
}
#endif /* !TITLE_TRANSITION_STYLE_NON_BLOCKING */


/*****************************************************************************
 * FUNCTION
 *  gui_title_in_transition_blocking
 * DESCRIPTION
 *  is title transition in non block
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_in_transition_blocking(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->in_blocking;
}

#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)


/*****************************************************************************
 * FUNCTION
 *  gui_title_stop_transition_non_blocking
 * DESCRIPTION
 *  This functions draws the transition title with timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_stop_transition_non_blocking(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    S32 temp_menu_shortcut;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(gui_title_show_transition_non_blocking);
    t->check_for_transition = 1;
    if (is_in_nonblocking_title_transition() == 1)
    {
        t->x = t->prev_title_x;
        gui_lock_double_buffer();
    #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
        if (g_title_prev_menu_shortcut != -1)
        {
            temp_menu_shortcut = t->sc.number;
            t->sc.number = g_title_prev_menu_shortcut;
            gui_title_show(t, GUI_TITLE_PART_ALL);
            t->sc.number = temp_menu_shortcut;
        }
        else
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
        {
            gui_title_show(t, GUI_TITLE_PART_ALL);
        }
        gui_unlock_double_buffer();
        t->in_blocking = 0;
    }
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    g_title_bitmap_for_transition.data = NULL;
#else
    transition_required = 0;
#endif
}


#ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/*****************************************************************************
 * FUNCTION
 *  gui_title_show_previous_for_transition
 * DESCRIPTION
 *  Show the previous title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_previous_for_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_no = -1;
    U8 temp_title_string[GUI_TITLE_BUFFER_SIZE];
    PU8 temp_title_icon = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_no = t->sc.number;
    t->sc.number = g_title_temp_last_shortcut;

    mmi_ucs2ncpy((S8*)temp_title_string, (S8*)t->text, GUI_TITLE_MAX_LENGTH);
    temp_title_icon = t->icon;
    mmi_ucs2ncpy((S8*)t->text, (const S8*)t->prev_text, GUI_TITLE_MAX_LENGTH);
    t->icon = t->prev_icon;

    gui_title_show(t, GUI_TITLE_PART_ALL);

    t->sc.number = temp_no;
    mmi_ucs2ncpy((S8*)t->text, (const S8*)temp_title_string, GUI_TITLE_MAX_LENGTH);
    t->icon = temp_title_icon;
}
#endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_transition_non_blocking
 * DESCRIPTION
 *  This functions draws the transition title with timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_transition_non_blocking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 transition_count;
    static S32 transition_resolution;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    g_title_bitmap_for_transition.data = bitmap_data_for_title_transition;
#endif
    switch (g_gui_title_transition_target->transition_style)
    {
        case WGUI_TRANSITION_R2L:
        {
            transition_count = GUI_TITLE_TRANSITION_R2L_COUNT;
            if (is_in_nonblocking_title_transition() == 0)
            {
                g_gui_title_transition_target->in_blocking = MMI_TRUE;
            #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                gui_title_show_previous_for_transition(t);
            #endif
                transition_resolution = g_gui_title_transition_target->width / transition_count;
                g_gui_title_transition_target->x =
                    g_gui_title_transition_target->x + g_gui_title_transition_target->width - 1;
                gui_add_pre_cleanup_hook(wgui_title_tranisition_abort_cleanup_function);
            }
            g_gui_title_transition_target->x -= transition_resolution;
            move_menu_shortcut_handler(
                g_gui_title_transition_target->x + g_gui_title_transition_target->width - MMI_menu_shortcut_box.width,
                g_gui_title_transition_target->y);
            gui_lock_double_buffer();
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
            _show_bitmap(
                (g_gui_title_transition_target->x - g_gui_title_transition_target->width),
                g_gui_title_transition_target->y,
                &g_title_bitmap_for_transition);
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
            gui_title_show(g_gui_title_transition_target, GUI_TITLE_PART_ALL);
            gui_unlock_double_buffer();
        #ifdef __MMI_VUI_ENGINE__
            if(g_gui_title_transition_target->venus_update_screen_callback)
            {
                g_gui_title_transition_target->venus_update_screen_callback(g_gui_title_transition_target->venus_update_screen_handle);
            }
            else
            {
        #endif
                gdi_layer_blt_previous(
                    g_gui_title_transition_target->prev_title_x,
                    g_gui_title_transition_target->y,
                    g_gui_title_transition_target->prev_title_x + g_gui_title_transition_target->width,
                    g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
        #ifdef __MMI_VUI_ENGINE__
            }
        #endif
            if ((g_gui_title_transition_target->x - transition_resolution) > 0)
            {
                gui_start_timer(TITLE_TRANSITION_NON_BLOCKING_TIMER, gui_title_show_transition_non_blocking);
            }
            else
            {
                move_menu_shortcut_handler(
                    g_gui_title_transition_target->width - MMI_menu_shortcut_box.width,
                    g_gui_title_transition_target->y);
            #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                if (g_title_prev_menu_shortcut != -1)
                {
                    g_title_prev_menu_shortcut = -1;
                }
            #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
                gui_title_stop_transition_non_blocking(g_gui_title_transition_target);
            #ifdef __MMI_VUI_ENGINE__
                if(g_gui_title_transition_target->venus_update_screen_callback)
                {
                    g_gui_title_transition_target->venus_update_screen_callback(g_gui_title_transition_target->venus_update_screen_handle);
                }
                else
                {
            #endif
                    gdi_layer_blt_previous(
                        g_gui_title_transition_target->x,
                        g_gui_title_transition_target->y,
                        g_gui_title_transition_target->x + g_gui_title_transition_target->width,
                        g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
            #ifdef __MMI_VUI_ENGINE__
                }
            #endif
            }
            break;
        }
        case WGUI_TRANSITION_L2R:
        {
            transition_count = GUI_TITLE_TRANSITION_L2R_COUNT;
            if (is_in_nonblocking_title_transition() == 0)
            {
                g_gui_title_transition_target->in_blocking = MMI_TRUE;
            #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                gui_title_show_previous_for_transition(t);
            #endif
                transition_resolution = g_gui_title_transition_target->width / transition_count;
                g_gui_title_transition_target->x -= g_gui_title_transition_target->width + 1;
                gui_add_pre_cleanup_hook(wgui_title_tranisition_abort_cleanup_function);
            }

            g_gui_title_transition_target->x += transition_resolution;
            gui_lock_double_buffer();
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
            _show_bitmap(
                (g_gui_title_transition_target->x + g_gui_title_transition_target->width),
                g_gui_title_transition_target->y,
                &g_title_bitmap_for_transition);
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
            gui_title_show(g_gui_title_transition_target, GUI_TITLE_PART_ALL);
            gui_unlock_double_buffer();
        #ifdef __MMI_VUI_ENGINE__
            if(g_gui_title_transition_target->venus_update_screen_callback)
            {
                g_gui_title_transition_target->venus_update_screen_callback(g_gui_title_transition_target->venus_update_screen_handle);
            }
            else
            {
        #endif
                gdi_layer_blt_previous(
                    g_gui_title_transition_target->prev_title_x,
                    g_gui_title_transition_target->y,
                    g_gui_title_transition_target->prev_title_x + g_gui_title_transition_target->width,
                    g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
        #ifdef __MMI_VUI_ENGINE__
            }
        #endif
            if ((g_gui_title_transition_target->x + transition_resolution) < 0)
            {
                gui_start_timer(TITLE_TRANSITION_NON_BLOCKING_TIMER, gui_title_show_transition_non_blocking);
            }
            else
            {
            #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                if (g_title_prev_menu_shortcut != -1)
                {
                    g_title_prev_menu_shortcut = -1;
                }
            #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
                gui_title_stop_transition_non_blocking(g_gui_title_transition_target);
            #ifdef __MMI_VUI_ENGINE__
                if(g_gui_title_transition_target->venus_update_screen_callback)
                {
                    g_gui_title_transition_target->venus_update_screen_callback(g_gui_title_transition_target->venus_update_screen_handle);
                }
                else
                {
            #endif
                    gdi_layer_blt_previous(
                        g_gui_title_transition_target->x,
                        g_gui_title_transition_target->y,
                        g_gui_title_transition_target->x + g_gui_title_transition_target->width,
                        g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
            #ifdef __MMI_VUI_ENGINE__
                }
            #endif
            }
            break;
        }
    }

}

#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */

#endif /* __MMI_UI_TITLE_TRANSITION__ */


/*****************************************************************************
 * Extern Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_title_show
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  part        [IN]            Part ID of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_show(gui_title_struct *t, U32 part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bitblt = MMI_TRUE;
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)     
    stFontAttribute title_font_attribute;
    UI_font_type title_font;
#endif /* __MMI_FTE_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__) 
    title_font = t->normal_font;
    title_font_attribute = *title_font;
    if (t->hide_callback)
    {
        title_font_attribute.smallCaps = 2;
    }
    t->normal_font = &title_font_attribute;
#endif /* __MMI_FTE_SUPPORT__ */

    if(part & GUI_TITLE_PART_TEXT)
    {
        t->show_text = MMI_TRUE;
    }
    t->has_title = MMI_TRUE;
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    if (t->next_frame == MMI_FALSE && gui_title_is_animation_enabled(t))
    {
        gui_title_stop_animation(t);
    }
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */

    bitblt = (MMI_BOOL)gui_title_show_normal(t, part);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
    t->normal_font = title_font;
#endif /* __MMI_FTE_SUPPORT__ */
    return bitblt;

}


#ifdef __MMI_SCREEN_SWITCH_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  gui_title_get_text_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  t       [IN/OUT]

 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_get_text_info(gui_title_struct *t, S32 *text_width, S32 *text_height, PU8 *text_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 area1_width = 0, area1_height = 0, area2_width = 0, area2_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_DBG_ASSERT(t != NULL);

    *text_content = t->text;
    *text_width = 0;
    *text_height = t->height;

    if (t->style & GUI_TITLE_STYLE_SCROLLING)   /*  */
    {

    }
    else
    {
        gui_title_measure_area1(t, &area1_width, &area1_height);
        gui_title_measure_area2(t, &area2_width, &area2_height);

        *text_width = t->width - area1_width - area2_width;
    }
}
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */


/*****************************************************************************
 * FUNCTION
 *  gui_title_move
 * DESCRIPTION
 *  move title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x       [IN]
 *  y       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_move(gui_title_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->x = x;
    t->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_resize
 * DESCRIPTION
 *  resize title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  width       [IN]
 *  height      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_resize(gui_title_struct *t, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->width = width;
    t->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_change
 * DESCRIPTION
 *  change title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  icon        [IN]            Left icon
 *  icon2       [IN]            Right icon
 *  text        [IN]            Text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_change(gui_title_struct *t, PU8 icon, PU8 icon2, U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_TITLE_TRANSITION__
    t->prev_icon = t->icon;
    mmi_ucs2ncpy((S8*) t->prev_text, (S8*) t->text, GUI_TITLE_MAX_LENGTH);
#endif /* __MMI_UI_TITLE_TRANSITION__ */
    if (text)
    {
        mmi_ucs2ncpy((S8*) t->text, (S8*) text, GUI_TITLE_MAX_LENGTH);
    }
    else
    {
        t->text[0] = 0;
        t->text[1] = 0;
    }
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
    t->icon = icon;
    t->icon2 = icon2;
#endif
    if (t->style & GUI_TITLE_STYLE_SCROLLING)
    {
        gui_scrolling_text_stop(&(t->scrolling_text));
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_create_ex
 * DESCRIPTION
 *  create title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  x                   [IN]            the x coordinate of title
 *  y                   [IN]            the y coordinate of title
 *  wdith               [IN]            the width of title
 *  height              [IN]            the height of title
 *  target_lcd          [IN]            Is the target of lcd title
 *  target_layer        [IN]            Is the target layer of title
 *  alpha_blend_layer   [IN]            Is the alpha blend layer of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_create_ex(
        gui_title_struct *t,
        S32 x,
        S32 y,
        S32 wdith,
        S32 height,
        gdi_handle target_lcd,
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->x = x;
    t->y = y;
    t->width = wdith;
    t->height = height;
    t->target_lcd = target_lcd;
    t->target_layer = target_layer;
    t->alpha_blend_layer = alpha_blend_layer;
    t->hide_callback = NULL;
    t->style = GUI_TITLE_STYLE_NORMAL;
    t->has_title = MMI_FALSE;
    gui_title_set_current_theme(t);
    gui_title_show_normal = gui_title_oem_show_normal;
    gui_title_show_background = gui_title_oem_show_background;
    gui_title_measure = gui_title_measure_oem;
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    gui_title_show_status_icon = gui_title_show_status_icon_oem;
#endif

#ifdef __MMI_TITLE_BAR_NO_ICON_SHCT__
#ifdef __MMI_TITLE_BAR_NO_ICON_SHCT__
	    t->no_icon_shct = MMI_FALSE;
#else /*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
	    t->no_icon_shct = MMI_TRUE;
#endif  /*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
#endif

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    gui_title_enable_animation(t, MMI_TRUE);
    g_gui_title_current_animation_target = t;
    t->animated_style = GUI_TITLE_EFFECT_TYPE(__MMI_UI_ANIMATED_TITLE_EFFECT__);
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */

#ifdef __MMI_UI_TITLE_MINI_INDICATOR__
    t->display_indicator = MMI_FALSE;
    t->number_of_indicator = 0;
    t->highlight_of_indicator = -1;
#endif /* __MMI_UI_TITLE_MINI_INDICATOR__ */

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_create
 * DESCRIPTION
 *  create title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  x           [IN]            the x coordinate of title
 *  y           [IN]            the y coordinate of title
 *  wdith       [IN]            the width of title
 *  height      [IN]            the height of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_create(gui_title_struct *t, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_title_create_ex(t, x, y, width, height,GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_style
 * DESCRIPTION
 *  set title style
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_style(gui_title_struct *t, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->style = t->style | style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_unset_style
 * DESCRIPTION
 *  set title style for show icon
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_unset_style(gui_title_struct *t, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->style = t->style & ~style;
    if (style == GUI_TITLE_STYLE_SCROLLING)
    {
        gui_scrolling_text_stop(&(t->scrolling_text));
    }
}

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
/*****************************************************************************
 * FUNCTION
 *  gui_title_set_no_icon_shct
 * DESCRIPTION
 *  set title style for show icon
 * PARAMETERS
 *  t                   [IN/OUT]        Is the struct of title
 *  no_icon_shct        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_no_icon_shct(gui_title_struct *t, MMI_BOOL no_icon_shct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->no_icon_shct = no_icon_shct;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_title_set_theme
 * DESCRIPTION
 *  set the specify theme
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  th      [IN]            Specify theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_theme(gui_title_struct *t, UI_window_title_theme *th)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        t->active_filler = current_MMI_theme->rotated_title_filler;
    }
    else
#endif
    {
        t->active_filler = th->active_filler;
    }
    t->normal_font = th->text_font;
    t->active_font = th->text_font;
    t->text_color = th->active_text_color;
    t->text_border_color = th->text_border_color;
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    t->sc.normal_text_color = th->shortcut_text_color;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_current_theme
 * DESCRIPTION
 *  set current theme
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_current_theme(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_title_set_theme(t, current_window_title_theme);

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_register_callback
 * DESCRIPTION
 *  register the callback function of pre_goto and goto
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  pre_goto_funcptr        [IN]
 *  goto_funcptr            [IN]
 *  flag                    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_register_callback(
        gui_title_struct *t,
        void (*pre_goto_funcptr) (S32 i),
        void (*goto_funcptr) (S32 i),
        U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & WGUI_TITLE_SHORTCUT_CHANGE_PRE_GOTO)
    {
        t->pre_goto_callback = pre_goto_funcptr;
    }
    if (flag & WGUI_TITLE_SHORTCUT_CHANGE_GOTO)
    {
        t->goto_callback = goto_funcptr;
    }

}


void gui_title_register_hide_callback(
        gui_title_struct *t,
        void (*hide_callback)(S32 x, S32 y, S32 w, S32 h))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hide_callback != NULL)
    {
        t->hide_callback = hide_callback;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_hide_callback
 * DESCRIPTION
 *  reset the hide callback function of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_hide_callback(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->hide_callback = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  gui_title_set_alpha_layer
 * DESCRIPTION
 *  set alpha layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  alpha_layer             [IN]            Is the alpha layer of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_alpha_blend_layer(gui_title_struct *t, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_alpha_blend_layer
 * DESCRIPTION
 *  set alpha layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  title's alpha blend layer
 *****************************************************************************/
gdi_handle gui_title_get_alpha_blend_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_alpha_layer
 * DESCRIPTION
 *  reset alpha layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_alpha_blend_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_target_lcd
 * DESCRIPTION
 *  set target lcd of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  target_lcd              [IN]            Is the target_lcd of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_target_lcd(gui_title_struct *t, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_target_lcd
 * DESCRIPTION
 *  get target lcd of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  title's target lcd
 *****************************************************************************/
gdi_handle gui_title_get_target_lcd(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_target_lcd
 * DESCRIPTION
 *  reset target lcd of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_target_lcd(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_target_layer
 * DESCRIPTION
 *  set target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  target_layer            [IN]            Is the target_layer of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_target_layer(gui_title_struct *t, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_target_layer
 * DESCRIPTION
 *  get target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  title's target layer
 *****************************************************************************/
gdi_handle gui_title_get_target_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_target_layer
 * DESCRIPTION
 *  reset target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_target_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_in_wap
 * DESCRIPTION
 *  reset target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_in_wap(MMI_BOOL in_wap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_title_is_in_wap = in_wap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_in_wap
 * DESCRIPTION
 *  reset target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_get_in_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gui_title_is_in_wap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_close
 * DESCRIPTION
 *  close title, init the title struct date
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_close(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_close(&(t->sc));
    t->hide_callback = NULL;
	
#ifndef __MMI_SUBLCD__	
    t->target_lcd = GDI_NULL_HANDLE;
#endif

    t->target_layer = GDI_NULL_HANDLE;
    t->alpha_blend_layer = GDI_NULL_HANDLE;
	
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    t->show_text = MMI_FALSE;
    t->icon = NULL;
    t->icon2 = NULL;
#endif	
    t->has_title = MMI_FALSE;
    g_gui_title_is_in_wap = MMI_FALSE;
    
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    t->offset_x = 0;
    t->offset_y = 0;
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

    if (t->style & GUI_TITLE_STYLE_SCROLLING)
    {
        gui_title_unset_style(t,GUI_TITLE_STYLE_SCROLLING);
    }
	
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
    if (t->icon_ani_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(t->icon_ani_handle);
        t->icon_ani_handle = GDI_ERROR_HANDLE;
    }

    if (t->icon2_ani_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(t->icon2_ani_handle);
        t->icon2_ani_handle = GDI_ERROR_HANDLE;
    }
#endif

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    gui_title_stop_animation(t);
#endif

#ifdef __MMI_VUI_ENGINE__
    t->venus_update_screen_callback = NULL;
    t->venus_update_screen_handle = NULL;
#endif
}


#ifdef __MMI_VUI_ENGINE__

/*****************************************************************************
 * FUNCTION
 *  gui_title_register_venus_update_screen
 * DESCRIPTION
 *  Register the venus update screen callback function and handle
 * PARAMETERS
 *  t                               [IN/OUT]        Is the struct of title
 *  venus_update_screen_callback    [IN]            The callback of update screen in venus
 *  venus_update_screen_handle      [IN]            The pointer of title object in venus
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_register_venus_update_screen(
        gui_title_struct *t,
        void(*venus_update_screen_callback)(void *handle),
        void *venus_update_screen_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->venus_update_screen_callback = venus_update_screen_callback;
    t->venus_update_screen_handle = venus_update_screen_handle;
}

#endif /* __MMI_VUI_ENGINE__ */

#ifdef __MMI_UI_TITLE_TRANSITION__

/*****************************************************************************
 * FUNCTION
 *  gui_title_set_transition
 * DESCRIPTION
 *  This functions sets the transition style for title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]            The style in which the title should transiate R2L or L2R
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_transition(gui_title_struct *t, gui_title_transition_enum style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->transition_style = style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_transition
 * DESCRIPTION
 *  This functions get the transition style for title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  the style of title transition
 *****************************************************************************/
gui_title_transition_enum gui_title_get_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->transition_style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_transition_on_keys
 * DESCRIPTION
 *  This functions sets the transition style for title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  onkey       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_transition_on_keys(gui_title_struct *t, MMI_BOOL onkey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->transition_on_keys = onkey;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_transition_on_keys
 * DESCRIPTION
 *  This functions gets the transition style for title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_get_transition_on_keys(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->transition_on_keys;
}

#endif /* __MMI_UI_TITLE_TRANSITION__ */


#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__


/*****************************************************************************
 * FUNCTION
 *  gui_title_start_animation
 * DESCRIPTION
 *  start timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_start_animation(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(GUI_TITLE_IMAGE_ANIMATION_TIMER, gui_title_animate_image);
    g_gui_title_current_animation_target = t;

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_stop_animation
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_stop_animation(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(t);
    t->animate_move = 0;
    t->backup_frame_count = t->current_frame_count;
    t->current_frame_count = 0;
    gui_cancel_timer(gui_title_animate_image);

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_enable_animation
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  enable_animation        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_enable_animation(gui_title_struct *t, MMI_BOOL enable_animation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->enable_animtion = enable_animation;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_animation_enabled
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_is_animation_enabled(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->enable_animtion;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_unset_animation_style
 * DESCRIPTION
 *  unset animation style
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_unset_animation_style(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->animated_style = GUI_TITLE_EFFECT_TYPE(__MMI_UI_ANIMATED_TITLE_EFFECT__);
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_animation_style
 * DESCRIPTION
 *  unset animation style
 * PARAMETERS
 *  t                   [IN/OUT]        Is the struct of title
 *  animated_style      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_animation_style(gui_title_struct *t, gui_title_effect_styles animated_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->animated_style = animated_style;
}

#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */



