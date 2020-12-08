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
 * widget_key_handler.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget key handling
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*
 * In direct paint mode, paintbox will HDIa_widgetSetInFocus to an input or menu gadget only if 
 * it want to edit it. In other words, a input gadget might be selected (rounded by border) but not focused.
 *
 * In MsfForm, widget call HDIa_widgetSetInFocus when the cursor is on any gadgets (input/image/...), 
 * and it enter full-screen editor only if WGUI_CTX->in_form == FALSE
 *
 */

#include "widget_linklist.h"
#include "widget.h"

/* Declaration of static functions */
static void widget_form_scroll_up(void);
static void widget_form_scroll_down(void);
static void widget_form_scroll_right(void);
static void widget_form_scroll_left(void);


/*****************************************************************************
 * FUNCTION
 *  widget_general_keyboard_handler
 * DESCRIPTION
 *  Dispatch an incoming keypad event.
 * PARAMETERS
 *  Keycode     [IN]        
 *  Keytype     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_general_keyboard_handler(kal_uint16 Keycode, kal_uint16 Keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (WGUI_CTX->is_menu_item_index_selection_process == 1)
    {
        /*
         * In MsfMenu case, the users press number keys to select the menu item. 
         * The GUI component, menu list, will start the timer to select the index one,
         * and we need to avoid the user press LSK or MsfYes at the same time.
         */
        if (Keycode == KEY_LSK || Keycode == KEY_ENTER)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENEREAL_KEYBOARD_HANDLER_DROP_KEY);
            if (Keytype == KEY_EVENT_UP)
            {
                WGUI_CTX->is_menu_item_index_selection_process = 0;
            }
            return;
        }
    }

    if (widget_key_ind_handler(Keycode, Keytype))
    {
        if (WGUI_CTX->in_paintbox)  /* Reason? */
        {
        #ifdef __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __WIDGET_SCROLLBAR_INDICATION_IN_BROWSER__ */
        #ifndef __MMI_VECTOR_FONT_SUPPORT__  /* MAUI_01596459 string gets painted twice so bold */             
                widget_set_current_focus(_H(WGUI_CTX->current_focused_paintbox), KAL_TRUE);
        #endif
        }

        /* If MMI animation is not stopped immediately, it might animate before widget_paint_hdlr,
           even though widget_clear_all_handler also stop these MMI animation. */
        // XXX. It's already handled in widget_on_window_focus_changed().
        // widget_clear_animator_on_key_accepted();
    }
#ifdef WIDGET_UNIT_TEST
    else if (Keytype == KEY_EVENT_UP && Keycode == KEY_STAR)
    {
        widget_start_unit_test();
    }
#endif /* WIDGET_UNIT_TEST */ 
#ifdef WIDGET_TEST_OUT_OF_MEMORY
    else if (Keytype == KEY_EVENT_UP && Keycode == KEY_POUND)
    {
        widget_simulate_out_of_memory();
    }
#endif /* WIDGET_TEST_OUT_OF_MEMORY */ 
    else if (Keytype == KEY_EVENT_UP)
    {
        if (WGUI_CTX->current_dialog == 0)
        {
            /* No support scroll and change focus in the dialog  */
            switch (Keycode)
            {
                case KEY_VOL_UP:
                    /* 
                     * If playing the audio in MMS viewer, "VolUp" is used for control volume.
                     * If there is no audio or the audio stop, "VolUp" is used for scroll MMS viewer.
                     */
                    if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
#ifdef WIDGET_SUPPORT_SOUND
                        if (WGUI_CTX->current_window->property_mask & MSF_WINDOW_PROPERTY_EXT_VOLUME_KEY &&
                            ((WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END) || widget_check_in_playing_video()))
                        {
                            widget_press_inc_volume();
                        }
                        else                    
                        {
#endif /*  WIDGET_SUPPORT_SOUND */
                            widget_form_scroll_up();
#ifdef  WIDGET_SUPPORT_SOUND
                        }
#endif /* WIDGET_SUPPORT_SOUND */
                    }
                    break;
                case KEY_UP_ARROW:
				if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_up();
                    }
                    break;
                case KEY_VOL_DOWN:
                    /* 
                     * If playing the audio in MMS viewer, "VolDn" is used for control volume.
                     * If there is no audio or the audio stop, "VolDn" is used for scroll MMS viewer.
                     */
                    if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
#ifdef WIDGET_SUPPORT_SOUND
                        if (WGUI_CTX->current_window->property_mask & MSF_WINDOW_PROPERTY_EXT_VOLUME_KEY &&
                            ((WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END) || widget_check_in_playing_video()))
                        {
                            widget_press_dec_volume();
                        }
                        else                    
                        {
#endif /* WIDGET_SUPPORT_SOUND */ 
                            widget_form_scroll_down();
#ifdef WIDGET_SUPPORT_SOUND
                        }
#endif /* WIDGET_SUPPORT_SOUND */
                    }
                    break;
                case KEY_DOWN_ARROW:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_down();
                    }
                    break;
                case KEY_LEFT_ARROW:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_left();
                    }
                    break;
                case KEY_RIGHT_ARROW:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_form_scroll_right();
                    }
                    break;
                case KEY_SEND:
                if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window)
                    {
                        widget_choice_focus();
                    }
                    break;
                case KEY_0:
                case KEY_1:
                case KEY_2:
                case KEY_3:
                case KEY_4:
                case KEY_5:
                case KEY_6:
                case KEY_7:
                case KEY_8:
                case KEY_9:
                case KEY_STAR:
                case KEY_POUND:
                    /* Automatically focus input gadget when pressing anykey.
                       If access keys is set. It will not reach here. */
                    if (WGUI_CTX->in_paintbox)
                    {
                        if (WGUI_CTX->selected_input_in_paintbox != 0)
                        {
                            widget_key_ind_handler(KEY_SEND, KEY_EVENT_UP);
                        }
                    }
                else if ((WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) != WGUI_CTX->current_window) &&
                             WGUI_CTX->current_focused_gadget &&
                             IS_GADGET_INPUT_TYPE2(WGUI_CTX->current_focused_gadget))
                    {
                        /* In MsfForm case */
                        widget_choice_focus();
                    }
                    else if (WGUI_CTX->in_form && _W(WGUI_CTX->current_menu) == WGUI_CTX->current_window)
                    {
                        /*
                         * In MsfMenu case, the users press number keys to select the menu item. 
                         * The GUI component, menu list, will start the timer to select the index one,
                         * and we need to avoid the user press LSK or MsfYes at the same time.
                         */
                        WGUI_CTX->is_menu_item_index_selection_process = 1;
                    }

                    break;
            }
        }
    }

    if (Keytype == KEY_EVENT_UP)    /* Handle Key Down and Key Up together */
    {
        widget_send_update_event_to_wap();
    }
}

/* Used by menu (option group) to select the next item */


/*****************************************************************************
 * FUNCTION
 *  widget_goto_prev_keyfocus_keyboard_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_goto_prev_keyfocus_keyboard_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->in_paintbox)
    {
        HDIa_widgetSetInFocus((MSF_UINT32) WGUI_CTX->current_focused_paintbox, 1);
    }
    else
    {
        WGUI_CTX->in_form = 1;
        widget_form_scroll_up();
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_goto_next_keyfocus_keyboard_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_goto_next_keyfocus_keyboard_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->in_paintbox)
    {
        HDIa_widgetSetInFocus((MSF_UINT32) WGUI_CTX->current_focused_paintbox, 1);
    }
    else
    {
        WGUI_CTX->in_form = 1;
        widget_form_scroll_down();

    }

    return KAL_TRUE;
}

// TODO: move to widget_form.c (maybe renamed as widget_form_choose )


/*****************************************************************************
 * FUNCTION
 *  widget_choice_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_choice_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!WGUI_CTX->in_paintbox && WGUI_CTX->current_focused_gadget)
    {
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldy = WGUI_CTX->current_pos.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for BRS, it manage scrollbar by itself */
	if(WGUI_CTX->in_paintbox || !WGUI_CTX->in_form) 
    {
        return;
    }

    /* do not scroll before repaint, because we need repaint to update the region of the widgets */
    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint(); // TODO: It let SMIL redraw slow.
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    if (widget_prev_keyfocus
        && WGUI_CTX->display_pos.x <= widget_prev_widget_position.x
        && WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width >= widget_prev_widget_position.x)
    {
        if (WGUI_CTX->display_pos.y <= widget_prev_widget_position.y)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) widget_prev_keyfocus, 1);
            return;
        }
        else if (WGUI_CTX->display_pos.y <= widget_prev_widget_position.y + WIDGET_SCROLL_UP_SIZE)
        {
            WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) widget_prev_keyfocus, 1);

            /* update scrollbar if WGUI_CTX->current_pos is changed */
            if (WGUI_CTX->current_vertical_scrollbar)
            {
                WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
            }
            widget_paint();

            return;
        }
    }

    /* 
     * After scrolling outside of SMIL textbox (MTR or SMTR), it will delete user events.
     * We need to send MsfNotifyFocus again for it to add user events again.
     */
    // TODO: this is temp fix.
    widget_notify(WGUI_CTX->current_focused_gadget, MsfNotifyFocus);

    WGUI_CTX->current_pos.y += WIDGET_SCROLL_UP_SIZE;

    /* the top limit */
    if (WGUI_CTX->current_pos.y > WGUI_CTX->display_pos.y)
    {
        WGUI_CTX->current_pos.y = WGUI_CTX->display_pos.y;
    }

    /* update scrollbar if WGUI_CTX->current_pos is changed */
    if (WGUI_CTX->current_vertical_scrollbar)
    {
        WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
    }

    widget_paint();
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldy = WGUI_CTX->current_pos.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(WGUI_CTX->in_paintbox || !WGUI_CTX->in_form) 
    {
        return;
    }

    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint(); // TODO: It let SMIL redraw slow.
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    /* if next widget is visible */
    if (widget_next_keyfocus
        && WGUI_CTX->display_pos.x <= widget_next_widget_position.x
        && WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width >= widget_next_widget_position.x)
    {
        if (WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height >
            widget_next_widget_position.y + widget_next_widget_size.height)
        {
            HDIa_widgetSetInFocus((MSF_UINT32) widget_next_keyfocus, 1);
            return;
        }
        else if (WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height >
                 widget_next_widget_position.y + widget_next_widget_size.height - WIDGET_SCROLL_DOWN_SIZE)
        {
            WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;
            HDIa_widgetSetInFocus((MSF_UINT32) widget_next_keyfocus, 1);
            /* update scrollbar if WGUI_CTX->current_pos is changed */
            if (WGUI_CTX->current_vertical_scrollbar)
            {
                WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
            }
            widget_paint();
            return;
        }
    }

    /* 
     * After scrolling outside of SMIL textbox (MTR or SMTR), it will delete user events.
     * We need to send MsfNotifyFocus again for it to add user events again.
     */
    widget_notify(WGUI_CTX->current_focused_gadget, MsfNotifyFocus);

    /* If there is nothing below the screen, we will not allow to scroll down. */
    if (widget_max_y <= WGUI_CTX->display_pos.y + WGUI_CTX->display_size.height + 1)
    {
        return;
    }

    WGUI_CTX->current_pos.y -= WIDGET_SCROLL_DOWN_SIZE;

    /* Update scrollbar if WGUI_CTX->current_pos is changed */
    if (WGUI_CTX->current_vertical_scrollbar)
    {
        WGUI_CTX->current_vertical_scrollbar->value += (oldy - WGUI_CTX->current_pos.y);
    }
    widget_paint();
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_left
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldx = WGUI_CTX->current_pos.x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (WGUI_CTX->in_paintbox || !WGUI_CTX->in_form)
    {
        return;
    }

    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint();
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    WGUI_CTX->current_pos.x += WIDGET_SCROLL_LEFT_SIZE;

    if (WGUI_CTX->current_pos.x > WGUI_CTX->display_pos.x)
    {
        WGUI_CTX->current_pos.x = WGUI_CTX->display_pos.x;
    }

    /* update scrollbar */
    if (WGUI_CTX->current_horizontal_scrollbar)
    {
        WGUI_CTX->current_horizontal_scrollbar->value += (oldx - WGUI_CTX->current_pos.x);
    }

    widget_paint();
}


/*****************************************************************************
 * FUNCTION
 *  widget_form_scroll_right
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_form_scroll_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int oldx = WGUI_CTX->current_pos.x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (WGUI_CTX->in_paintbox || !WGUI_CTX->in_form)
    {
        return;
    }

    if (WGUI_CTX->paint_seqnum_on_form_scroll == WGUI_CTX->paint_seqnum)
    {
        widget_paint();
        return;
    }
    WGUI_CTX->paint_seqnum_on_form_scroll = WGUI_CTX->paint_seqnum;

    /* if there is nothing int the right side of the screen, we will not allow to scroll right. */
    if (widget_max_x <= WGUI_CTX->display_pos.x + WGUI_CTX->display_size.width + 1)
    {
        return;
    }

    WGUI_CTX->current_pos.x -= WIDGET_SCROLL_RIGHT_SIZE;

    /* update scrollbar */
    if (WGUI_CTX->current_horizontal_scrollbar)
    {
        WGUI_CTX->current_horizontal_scrollbar->value += (oldx - WGUI_CTX->current_pos.x);
    }

    widget_paint();
}

