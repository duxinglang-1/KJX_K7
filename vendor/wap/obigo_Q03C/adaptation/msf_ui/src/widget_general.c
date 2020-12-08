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
 * widget_general.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Basic widget manipulation 
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"
#include "widget.h"
#include "widget_struct.h"
#include "widget_linklist.h"
#include "WguiCategoryGprot.h"
//#include "simDetectionDef.h"
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
#include "gdi_util.h"
#endif /*  __MMI_WAP_MOUSE_POINTER_SUPPORT__ */

/* 
 * About the current memory management of WAP widget
 * 1. HDIa_memAlloc and HDIa_memFree must be paired with the same module ID; otherwise it
 * might produce memory corruption with Obigo's memory allocator.
 *
 * 2. In widget_malloc_mem & widget_free_mem, we always use the owner module to allocate its memory
 *
 * 3. Sometimes we use MSF_MODID_WIDGET to allocate data like drawing operations. Because 
 *  MSF_MEM_FREE_ALL(MSF_MODID_WIDGET) is always executed after MSF_MODID_WIDGET_RELEASE_ALL
 *  on other modules, it is safe from releasing memory of a widget object before MSF_WIDGET_RELEASE it.
 *
 *(FIXED issue of MSF_WIDGET_RELEASE_ALL on 2004.04.13 w04.13 
 * widget_malloc always use HDIa_getModuleID() to insert a block into widget free list.
 * If MEA calls a BRA function to allocate a string, the string will be inserted into MEA's widget free list
 * If we HDIa_widgetReleaseAll(MSF_MODID_MEA) before terminating BRA UI, the string will be released twice.)
 */

/****************************************************************
  Widget General
 ***************************************************************/
#ifdef OBIGO_Q03C_BROWSER
extern MMI_BOOL mmi_brw_is_temp_busy_screen_active(void);
#endif /* OBIGO_Q03C_BROWSER */
extern void widget_deinit_structure(void);
/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDeviceGetProperties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  theDeviceProperties     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetDeviceGetProperties(MsfDeviceProperties *theDeviceProperties)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    theDeviceProperties->displaySize.width = WGUI_CTX->display_size.width;
    theDeviceProperties->displaySize.height = WGUI_CTX->display_size.height;

    theDeviceProperties->isTouchScreen = WIDGET_HAVE_TOUCH_SCREEN;
    theDeviceProperties->hasDragAbility = WIDGET_HAVE_DRAG_ABILITY;
    theDeviceProperties->isColorDisplay = (DEVICE_COLOR_DEPTH != 1);
    theDeviceProperties->numberOfColors = 2 << DEVICE_COLOR_DEPTH;
    theDeviceProperties->supportedMsfEvents = 0xffffffff;   /* default support all event */

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetDeviceSetProperties
 * DESCRIPTION
 *  
 * PARAMETERS
 *  theDeviceProperties     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
void HDIa_widgetDeviceSetProperties(
        U32 x,
        U32 y,
        U32 w,
        U32 h,
        GDI_HANDLE category_lyr_a_hndl,
        GDI_HANDLE category_lyr_b_hndl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	WGUI_CTX->display_pos.x = x;
	WGUI_CTX->display_pos.y = y;
    WGUI_CTX->display_size.width = w;
    WGUI_CTX->display_size.height = h;   
#ifdef __COSMOS_MMI_PACKAGE__
	WGUI_CTX->default_display_size.height = h;
	WGUI_CTX->default_display_size.width = w;
#endif
    return;
}



/*****************************************************************************
 * FUNCTION
 *  widget_disable_multi_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_disable_multi_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reference: UI_common_screen_exit() */

    /* For cache of GUI menu background image */
    gui_free_multilayer_screen();
    gui_set_entry_new_screen(MMI_TRUE);

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    wgui_reset_wallpaper_on_bottom();
#endif 

    /* For menu background image cache */
#ifdef WIDGET_PRECACHE_IMAGE
    widget_MMI_free_precached_image_if_any();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_on_window_focus_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_on_window_focus_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->is_widget_screen)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        widget_MMI_reset_pen_on_screen_switch();
    #endif 
        gui_cleanup();

        widget_disable_multi_layer();

//        widget_enable_clear_all_handler();
//        widget_clear_all_handler();

    #if defined (WIDGET_RESIDENT_STATUS_ICON) && defined (__MMI_WALLPAPER_ON_BOTTOM__)
    
        {
            /*
             * Here is very tricky. 
             * The widget handles status icon bars by itself (WAP task controls), 
             * but sometimes MMI task will updates at the same time. (ex. have blinking icons).
             * It causes the background of the status bar is white color not the wallpaper image.
             * We will hide status icon when the window changed focus and draw the status bar in widget_paint.
             */
/*
            if ((widget_browserv2_check_version() == WIDGET_BROWSER_V1) || (widget_browserv2_check_version() == WIDGET_BROWSER_V2_WITH_MMSV01_CALLER_MMS))
            {
                wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
            }
*/
        }
    #endif /* WIDGET_RESIDENT_STATUS_ICON && __MMI_WALLPAPER_ON_BOTTOM__ */ 

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_enable_integrated(MMI_FALSE);
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  widget_common_exit
 * DESCRIPTION
 *  This function is called every time when we exit from widget screen or window.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_common_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ctk_tone_id toneid;
    //ctk_image_id imageid;
    //kal_bool image_bottom;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Used to reset old alpha layer when exit from widget screen or window */
    if(g_old_alpha_layer)
    {
        gdi_set_alpha_blending_source_layer(g_old_alpha_layer);
        g_old_alpha_layer = 0;
    }
	if(WGUI_CTX->current_dialog && (_H(WGUI_CTX->current_window) == _H(WGUI_CTX->current_dialog)))
	{
		 HDIa_widgetExtStopDialogTone();
	}


#if defined(__MMI_MAINLCD_320X480__)
    wgui_popup_reset_softkey_flag();
    wgui_popup_reset_softkey_theme();
    enable_softkey_background();   
    if(WGUI_CTX->current_dialog)
    {
	move_softkey(0, UI_device_height-MMI_BUTTON_BAR_HEIGHT, MMI_LEFT_SOFTKEY);
	move_softkey(UI_device_width-MMI_SOFTKEY_WIDTH, UI_device_height-MMI_BUTTON_BAR_HEIGHT, MMI_RIGHT_SOFTKEY);
	resize_softkey(MMI_SOFTKEY_WIDTH, MMI_SOFTKEY_HEIGHT, MMI_LEFT_SOFTKEY);
	resize_softkey(MMI_SOFTKEY_WIDTH, MMI_SOFTKEY_HEIGHT, MMI_RIGHT_SOFTKEY);
    }
	
#endif

}

/*****************************************************************************
 * FUNCTION
 *  widget_on_window_focus_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_on_window_focus_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ON_WINDOW_FOCUS_CHANGED);

    if (WGUI_CTX->is_widget_screen)
    {
        widget_common_exit(); /* call common exit function when we exit from widget screen or window */
    #ifdef WIDGET_RESIDENT_STATUS_ICON
        if (WGUI_CTX->dialog_with_hatch_background)
        {
            WGUI_CTX->dialog_with_hatch_background = 0;
        }
    #endif /* WIDGET_RESIDENT_STATUS_ICON */ 

        widget_restore_menu_background_if_required();

        /*
         * For example, the user might stay in menu *after*  it is switched to another MsfWindow (e.g. SMIL player) and 
         * * before widget_paint_hdlr() is executed. If we do not clear all keys, it might invoke gui_show_list_menu
         * * by pressing KeyUp/KeyDown, which allocates GDI layer again.
         */
        widget_init_key_queue();    /* flush key queue */

        if (WIPC_CTX->MMI_is_waiting)
        {
            /* MMI is blocking wait. */
            widget_MMI_on_window_focus_changed();
        }
        else
        {
            widget_execute_MMI(widget_MMI_on_window_focus_changed, KAL_TRUE);
        }

        /* NOTE: WGUI_CTX->is_widget_screen might be FALSE at this point after RPC request! */
    }
#ifdef WIDGET_SUPPORT_SOUND
    WAP_DBG_ASSERT(!widget_is_sound_playing()); /* Non-fatal, but sound playing should be stopped before switching MsfWindow */
#endif /* WIDGET_SUPPORT_SOUND */
    widget_stop_all_paint_command();
#ifdef MSF_CFG_BRW_BLINKING_TEXT_SUPPORT
    widget_stop_all_blinking();
#endif
#ifdef MSF_CFG_BRW_MARQUEE_SUPPORT
    widget_stop_all_marquee();
#endif

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_stop_all_image_nb_draw();
#endif
    widget_init_fullscreen_menu();              /* Tricky. The parent of ChoiceMenu (fullscreen menu) must be focused to provide MsfActions. */

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ON_WINDOW_FOCUS_CHANGED_END);

    // TODO: stop animation
    // TODO: WEDITOR_CTX->current_state = FULLSCREEN_EDITOR_RETURN_NONE
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_window_gadget_displayed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfHandle       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_is_window_gadget_displayed(MSF_UINT32 msfHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msfHandle == 0)
    {
        return KAL_FALSE;
    }

    if (IS_GADGET_TYPE(msfHandle))
    {
        h = _H(msfHandle)->parent;
    }
    else if (IS_WINDOW_TYPE(msfHandle))
    {
        h = _H(msfHandle);
    }
    else
    {
        return KAL_FALSE;
    }

    if (h == NULL)
    {
        return KAL_FALSE;
    }

    if (h == (widget_header_struct*) WGUI_CTX->current_window)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_current_window_type
 * DESCRIPTION
 *  Is the current "focused" MsfWindow (not necessarily displayed) in this type?
 * PARAMETERS
 *  type        [IN]        Widget type
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool widget_is_current_window_type(widget_data_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We do not use WGUI_CTX->current_window because WGUI_CTX->current_window is displayed */
    widget_header_struct *screen, *window;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_get_active_childs(screen, &WGUI_CTX->widget_root);
    if (!screen)
    {
        return KAL_FALSE;
    }
    widget_get_active_childs(window, screen);
    if (!window)
    {
        return KAL_FALSE;
    }
    return IS_DATA_TYPE(window, type) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_get_current_focused_window
 * DESCRIPTION
 *  Get the current focused window
 *  
 *  NOTE: WGUI_CTX->current_window is current "painted" window, and it might be NULL
 *  even if some MsfWindow is focused.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
widget_window_struct *widget_get_current_focused_window(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *screen, *window;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_get_active_childs(screen, &WGUI_CTX->widget_root);
    if (!screen)
    {
        return NULL;
    }
    widget_get_active_childs(window, screen);
    if (!window)
    {
        return NULL;
    }
    return _W(window);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetInFocus
 * DESCRIPTION
 *  
 *  
 *  In integration manual: all widgets involved that have the notification functionality enabled
 *  must be notified of the focus change
 *  
 *  However, in some cases (e.g. Send MsfNotifyFocus to another gadget when removing an text input gadget)
 *  BRS might think that use pointer device to click on another gadget.. and it might enter infinite loop.
 *  
 *  If paintbox window is in focus, we should prepare a clear screen
 *  for paintbox use. (this cannot be moved to widget_paint
 *  because BRS use low-level API to draw on the paintbox,
 *  where widget_paint only draw buttons, outside-look, ...
 * PARAMETERS
 *  handle      [IN]        
 *  focus       [IN]        (Hack: not to send notification)
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetInFocus(MSF_UINT32 handle, int focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *p;
    widget_header_struct *a;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle)
    {
        return 0;
    }

    p = _H(handle)->parent;
    if (!p)
    {
        return 0;
    }

    widget_get_active_childs(a, p);
    ///////////////////////////////////////////////////////////
    // get focus
    if (focus == 1)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SET_IN_FOCUS_TRUE, handle, a);

        if (a != _H(handle))
        {
            if (!IS_GADGET_TYPE(handle))    /* Any screen or window */
            {
                WGUI_CTX->is_painted_after_first_focus_changed = 0;
                widget_on_window_focus_changed();
             #ifdef __MMI_WAP_MOUSE_POINTER_SUPPORT__
		if ((IS_DIALOG_TYPE(handle)) && (focus == 1))
		    WGUI_CTX->is_dialog_focused = 1;
             #endif /* __MMI_WAP_MOUSE_POINTER_SUPPORT__ */
            }

            widget_set_active_childs(p, _H(handle));

            /*
             * In paintbox, MsfNotifyFocus and MsfNotifyLostFocus usually represents a mouse event. 
             * * It might cause unexpected side effects.
             */
            if (a != NULL)
            {
                if (!IS_PAINTBOX_TYPE(p))
                {
                    widget_notify(_H(a), MsfNotifyLostFocus);
                }
            }

            // TODO: If we set focus to another "screen", should we set MsfNotifyLostFocus to the old "window"?

            if (IS_SCREEN_TYPE(handle))
            {
                widget_header_struct *child;

                widget_get_active_childs(child, handle);

                if (child)
                {
                    kal_bool clear_screen_flag = KAL_FALSE;

                    if (WGUI_CTX->is_back_history)
                    {
                        /* If in goback history procedure, we will clear the screen */
                        clear_screen_flag = KAL_TRUE;
                    }
                    if (clear_screen_flag)
                    {
						if (!WGUI_CTX->current_window && IS_DIALOG_TYPE(child))
						{
                           /*
                            * If show MSfWindow in widget screen and it is MsfDialog,
                            * we will clear all screen
                            */
							widget_clear_screen();
						}
						else
						{
							/* If change screen, we should clear screen first. */
							widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);
						}
                    }

                    HDIa_widgetSetInFocus((MSF_UINT32) child, 1);
                }
            }
        }

        /* If we send notification here. It might enter infinite loop in BRS */
        /* widget_notify(_H(handle),MsfNotifyFocus); */

        /* Tell BRS to update paintbox content */
        if (IS_PAINTBOX_TYPE(handle))
        {
            /*
             * Widget focuses the paintbox but doesn't draw and blt to the screen yet.
             * We want to clear all screen first if paintbox will be shown.
             * Sometimes the application will focus the paintbox and than focus to other,
             * and it cause the paintbox doesn't need to be shown.
             */
            WGUI_CTX->focus_paintbox_without_painting = 1;
            widget_notify(_H(handle), MsfNotifyStateChange);
        }
        else if (IS_FORM_TYPE(handle))
        {
            widget_form_on_focused(_H(handle));
        }
#ifdef OBIGO_Q03C_BROWSER
    if ((IS_GADGET_INPUT_TYPE(handle) || IS_GADGET_SELECT_GROUP_TYPE(handle)) && mmi_brw_is_temp_busy_screen_active())
		{
			WGUI_CTX->is_widget_screen = (kal_bool)1;
			WGUI_CTX->resume_rendering = (kal_bool)1;
		}
#endif /* OBIGO_Q03C_BROWSER */

        widget_send_update_event_to_wap();

        widget_set_current_object(_H(handle));
        widget_set_current_focus(_H(handle), KAL_TRUE);

        widget_paint();
    }
    /////////////////////////////////////////////////////////
    // lose focus
    else    /* focus == 0 || focus == -1 */
    {
        // TODO: Defocusing a gadget and a window/screen is different
        if (a == _H(handle))    /* handle is the active child */
        {
            if (!IS_GADGET_TYPE(handle))    /* Any screen or window */
            {
                WGUI_CTX->is_painted_after_first_focus_changed = 0;
                widget_on_window_focus_changed();
            }
            // It might cause problems
            //                      widget_notify(_H(handle),MsfNotifyLostFocus);

            widget_get_next_active_childs(a, p);
            if (a != NULL)  /* Focus to next node */
            {
                widget_hide_active_childs(p, handle);

                if (focus != -1)    /* Maybe we should always send notification */
                {
                    /*
                     * In paintbox, MsfNotifyFocus and MsfNotifyLostFocus usually represents a mouse event. 
                     * * It might cause unexpected side effects.
                     */
                    if (!IS_PAINTBOX_TYPE(p))
                    {
                        widget_notify(_H(a), MsfNotifyFocus);
                    }
                }

                /* e.g. A SEC screen disappear, BRS screen is focused, the paintbox should also be focused */
                if (IS_SCREEN_TYPE(a))
                {
                    widget_header_struct *child;

                    widget_get_active_childs(child, a);

                    if (child)
                    {
                        kal_bool clear_screen_flag = KAL_FALSE;

                        if (WGUI_CTX->is_back_history)
                        {
                            /* If in goback history procedure, we will clear the screen */
                            clear_screen_flag = KAL_TRUE;
                        }
                        if (clear_screen_flag)
                        {
                            /* If change screen, we should clear screen first. */
                            widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);
                        }

                        HDIa_widgetSetInFocus((MSF_UINT32) child, 1);
                    }
                }
                else if (IS_FORM_TYPE(a))   /* For example. Remove another window and the focus is changed to a form */
                {
                    widget_form_on_focused(_H(a));
                }
                else if (IS_PAINTBOX_TYPE(a))
                {
                    /*
                     * Widget focuses the paintbox but doesn't draw and blt to the screen yet.
                     * We want to clear all screen first if paintbox will be shown.
                     * Sometimes the application will focus the paintbox and than focus to other,
                     * and it cause the paintbox doesn't need to be shown.
                     */
                    WGUI_CTX->focus_paintbox_without_painting = 1;
                    widget_clear(&WGUI_CTX->default_display_size, &WGUI_CTX->display_pos);

                    /* let BRS to update paintbox content */
                    widget_notify(_H(a), MsfNotifyStateChange);
                }

                widget_set_current_object(_H(a));

            }

            widget_send_update_event_to_wap();
            widget_paint();
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetHasFocus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetHasFocus(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *node;
    widget_header_struct *w = _H(handle);
    widget_header_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (w && w->parent)
    {
        p = w->parent;
        widget_get_active_childs(node, p);
        if (node != w)
        {
            return 0;
        }
        if (IS_SCREEN_TYPE(node))
        {
            return 1;
        }

        w = p;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetRelease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetRelease(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_header_struct *node;
    int var_to_check = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle)
    {
        return 0;
    }
    if (IS_FLAG_STATIC(handle))
    {
        return 0;
    }

#ifdef MSF_CFG_BRW_ACCESSKEY_SUPPORT
    if (IS_ACCESSKEY_TYPE(handle))
    {
        return 0;
    }
#endif /* MSF_CFG_BRW_ACCESSKEY_SUPPORT */

#ifdef __MMI_WAP_MOUSE_POINTER_SUPPORT__
    if (IS_DIALOG_TYPE(handle))
    {
        WGUI_CTX->is_dialog_focused = 0;
    }
#endif /* __MMI_WAP_MOUSE_POINTER_SUPPORT__ */
    /*
     * Prevent HDIa_widgetRelease the same widgets for more than one time
     * (Teleca code might HDIa_widgetRelease the same widget twice.)
     *
     * Note: this only reduce the chance of memory corruption, but not eliminate it.
     * It is possible to allocate another widget at the same memory address, which is HDIa_widgetRelease()-ed
     * for the previous widget.
     *
     */
    if (_H(handle)->data_type == WIDGET_MAX_TYPE)
    {
        return 1;
    }

    /* a screen and window only have one parent */
    if (IS_SCREEN_TYPE(handle) || IS_WINDOW_TYPE(handle))
    {
        NO_REF(handle);
    }
    DEC_REF(handle);
    if (HAS_REF(handle))
    {
        return 1;
    }

    widget_pause_paint();

    // TODO: should we do this in widget_free?
    foreach_childs(handle, node,
                   {
                   if (!IS_FLAG_STATIC(node)) widget_remove_childs(_H(handle), node);}
    );

	if (IS_SCREEN_TYPE(handle) || IS_WINDOW_TYPE(handle))
		var_to_check = 1;

    widget_free(_H(handle));

    widget_resume_paint();

    /*
     * Sometimes the window is released first, and the child gadgets 
     * * are released later. We should not call widget_prepare_to_leave_screen
     * * when releasing a gadget
     * * FIXME. move to HDIa_widgetRemove
     */
//    if (IS_SCREEN_TYPE(handle) || IS_WINDOW_TYPE(handle))
	if (var_to_check)
    {
        if (widget_ready_to_leave_screen())
        {
            widget_prepare_to_leave_screen();
        }
    }
    return 1;
}

extern void widget_paintbox_free_doubble_buffer(void);
/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetReleaseAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetReleaseAll(MSF_UINT8 modId)
{
#ifdef WPS_TASK_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * With WPS support, STK module belongs to WPS task, but we should not use
     * * widget data structure in WPS task.
     * * We patched STK module such that it does not use any widget functions.
     */
    if (modId == MSF_MODID_STK)
    {
        WAP_DBG_ASSERT(WSYS_CTX->free_obj_list[MSF_MODID_STK] == NULL);
        return 1;
    }
#endif /* WPS_TASK_SUPPORT */ 
#ifdef BROWSER_SUPPORT
    if (modId == MSF_MODID_BRS)
    {
        widget_reset_image_delay_parameters();
        WGUI_CTX->is_paintbox_created = KAL_FALSE;
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
        if (WGUI_CTX->gdi_layer_handle)
        {
            gdi_handle h0, h1, h2, h3;
            gdi_layer_free(WGUI_CTX->gdi_layer_handle);
            gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
            if (h1 == WGUI_CTX->gdi_layer_handle)
            {
                gdi_layer_set_blt_layer(h0,0,h2,h3);
            }
            WGUI_CTX->gdi_layer_handle = 0;
        }
        if (WGUI_CTX->layer_memory_handle)
        {
        #ifdef WIDGET_MALLOC_IN_OWNER_MODULE
            widget_free_mem(MSF_MODID_WIDGET, (void *)WGUI_CTX->layer_memory_handle);
        #else /* WIDGET_MALLOC_IN_OWNER_MODULE */ 
            widget_free_mem((void *)WGUI_CTX->layer_memory_handle);
        #endif /* WIDGET_MALLOC_IN_OWNER_MODULE */ 
        }
        if (WGUI_CTX->mouse_pointer_handle)
        {
        widget_free((widget_header_struct *)WGUI_CTX->mouse_pointer_handle);
        }
        if (WGUI_CTX->link_select_tool_handle)
        {
            widget_free((widget_header_struct *)WGUI_CTX->link_select_tool_handle);
        }
        WGUI_CTX->mouse_pointer_handle = 0;
        WGUI_CTX->layer_memory_handle = 0;
        WGUI_CTX->mouse_position.x = 0;
        WGUI_CTX->mouse_position.y = 0;
        WGUI_CTX->link_select_tool_handle = 0;
        WGUI_CTX->is_link_select_image = 0;
	WGUI_CTX->is_dialog_focused = 0;
#endif  /*  __MMI_WAP_MOUSE_POINTER_SUPPORT__ */
	    widget_deinit_structure();
    }
#endif
    widget_pause_paint();

    /* WAP does not always HDIa_widgetRemove before invoking  HDIa_widgetReleaseAll */
    widget_release_all(modId);

    widget_resume_paint();


    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetCopy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT32 HDIa_widgetCopy(MSF_UINT8 modId, MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_STRING_TYPE(handle) || IS_PRE_STRING_TYPE(handle))
    {
        MsfStringHandle str = widget_copy_string(modId, (MsfStringHandle) handle);

        return str;
    }
    else
    {
        WAP_RST_ASSERT(0);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetRemove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle                  [IN]        
 *  handleToBeRemoved       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetRemove(MSF_UINT32 handle, MSF_UINT32 handleToBeRemoved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = -1;
    int cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!handle || !handleToBeRemoved)
    {
        return -1;
    }
    WAP_DBG_ASSERT(widget_check_object_validity(_H(handle)) && widget_check_object_validity(_H(handleToBeRemoved)));

    if (IS_FLAG_STATIC(handleToBeRemoved))
    {
        return -1;
    }
#ifdef __MMI_WAP_MOUSE_POINTER_SUPPORT__
	if (IS_DIALOG_TYPE(handleToBeRemoved))
	    WGUI_CTX->is_dialog_focused = 0;
#endif /* __MMI_WAP_MOUSE_POINTER_SUPPORT__ */
    widget_pause_paint();

    if (IS_SCREEN_TYPE(handleToBeRemoved))
    {
        handle = (MSF_UINT32) & WGUI_CTX->widget_root;
    }
    if (_H(handle) == _H(WGUI_CTX->current_window) &&
        (IS_GADGET_INPUT_TYPE(handleToBeRemoved) | IS_MENU_TYPE(handleToBeRemoved)))
    {
        /* When the paintbox content is changed by network, there might be no keypad event or window focus change  */
        widget_clear_animator_on_key_accepted();
    }

#ifdef __MMI_TOUCH_SCREEN__
    widget_MMI_remove_pen_handler_if_necessary(_H(handleToBeRemoved));
#endif 

    /* Check existence and remove it */
    widget_index_childs(cnt, _H(handle), _H(handleToBeRemoved));

    if (cnt != -1)
    {
        /*
         * The parameter -1 tell HDIa_widgetSetInFocus not to send MsfNotifyLostFocus notification 
         * * because BRS will enter an infinite loop when it remove an input gadget.
         */
        HDIa_widgetSetInFocus((MSF_UINT32) handleToBeRemoved, -1);
        /* Index is not 'cnt' here */
        widget_remove_childs(_H(handle), _H(handleToBeRemoved));
        result = 1;
    }

    if (IS_GADGET_BAR_TYPE(handleToBeRemoved))
    {
        widget_gadget_bar_struct *w;
        w = (widget_gadget_bar_struct *)handleToBeRemoved;
        if (w->bar_type == MsfHorizontalScrollBar)
        {
            WGUI_CTX->current_horizontal_scrollbar = NULL;
        }
/* 2449917 */
        if (w->bar_type == MsfVerticalScrollBar)
        {
            WGUI_CTX->current_vertical_scrollbar = NULL;
        }
/* 2449917 */
    }

    WAP_DBG_ASSERT(result);

    /* Upate action mask */
    if (IS_ACTION_TYPE(handleToBeRemoved))
    {
        widget_update_action_total_mask(_W(handle));
    }

    widget_resume_paint();
    widget_paint();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetTitle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  title       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetTitle(MSF_UINT32 handle, MsfStringHandle title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStringHandle copystr;    /* if handle and title belongs to different task */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!title)
    {
        copystr = 0;
    }
    if (title && IS_FLAG_STATIC(title))
    {
        copystr = title;
    }
    else
    {
        copystr = widget_copy_string(_H(handle)->module_id, title);
    }

    if (_H(handle)->flag & WIDGET_FLAG_WINDOW)
    {
        widget_set_attrib(_W(handle), title, copystr);
        if (copystr && !IS_FLAG_STATIC(copystr))
        {
            DEC_REF(copystr);
        }
        if (!IS_GADGET_TYPE(handle))
        {
            widget_paint();
        }
    }
    else if (IS_ACTION_TYPE(handle))
    {
        widget_set_attrib(_ACTION(handle), text, copystr);
        if (copystr && !IS_FLAG_STATIC(copystr))
        {
            DEC_REF(copystr);
        }
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetBorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  borderStyle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetBorder(MSF_UINT32 handle, MsfLineStyle borderStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef WIDGET_COMPACT_RUNTIME_STRUCT

    if (_H(handle)->flag & WIDGET_FLAG_WINDOW)
    {
        _W(handle)->border_style = borderStyle;
    }

#endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  position        [IN]         
 *  alignment       [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetPosition(MSF_UINT32 handle, MsfPosition *position, MsfAlignment *alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (_H(handle)->flag & WIDGET_FLAG_WINDOW)
    {
        if (position)
        {
            _W(handle)->position = *position;
        }
    #ifndef WIDGET_COMPACT_RUNTIME_STRUCT
        if (alignment)
        {
            _W(handle)->alignment = *alignment;
        }
    #endif /* WIDGET_COMPACT_RUNTIME_STRUCT */ 
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetSize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  size        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSetSize(MSF_UINT32 handle, MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (IS_WINDOW_TYPE(handle))
    {
        _W(handle)->size = *size;
    }
    else if (IS_GADGET_TYPE(handle))
    {
        /* gui multiline inputbox will handle the situation when the width is too small */
        _W(handle)->size = *size;
    }
    else if (IS_IMAGE_TYPE(handle))
    {
        /*
         * By BRS marquee. We cannot handle this because we always get the actual 
         * dimension from the image itself.
         */
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetGetPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  position        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetGetPosition(MSF_UINT32 handle, MsfPosition *position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *position = _W(handle)->position;
    return 1;
}


///////////////////////////////////////////////////////////
// Widget Extension
///////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetResetRenderingFlags
 * DESCRIPTION
 *  An interface to Application to reset rendering flags.      
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetResetRenderingFlags()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_widget_context) 															//MAUI_03325866
	{
    WGUI_CTX->is_widget_screen = (kal_bool)0;
    WGUI_CTX->resume_rendering = (kal_bool)0;
	}
    
}



/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSetRenderingFlags
 * DESCRIPTION
 *  An interface to Application to reset rendering flags.      
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetSetRenderingFlags()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WGUI_CTX->is_widget_screen = (kal_bool)1;
    WGUI_CTX->resume_rendering = (kal_bool)1;
}


#ifdef WIDGET_USE_FUNCTIONS_TO_MACRO
void widget_insert_array_func(int MODID, void ***ARRAY, kal_uint16 *SIZE, kal_uint16 *MAXSIZE, void *ITEM, int INDEX)
{
  if(*SIZE==*MAXSIZE) /* need to resize array */
  {
     widget_header_struct** new_array;
     widget_header_struct** old_array;
     WAP_DBG_ASSERT(*MAXSIZE<(0xFFFF-WIDGET_BASIC_LINK_SIZE)) /* max_childs_sum is kal_uint16 */
     *MAXSIZE = *MAXSIZE+WIDGET_BASIC_LINK_SIZE;
     new_array = widget_linklist_malloc(MODID, (*MAXSIZE) * sizeof(void*));
     if(INDEX>0)
        memcpy(new_array,*ARRAY,(INDEX)*sizeof(void*));
     if(*SIZE - INDEX>0)
        memcpy(
           new_array + INDEX+1,
           (widget_header_struct*)(*ARRAY)+INDEX,
           (*SIZE - INDEX)*sizeof(void*));
     old_array = (widget_header_struct**) *ARRAY;
     *ARRAY = (void**)new_array;
     if(old_array) widget_linklist_free(MODID, old_array);
  }
  else
  {
     kal_uint16 _dest;
     for(_dest = *SIZE;_dest>INDEX;_dest--)
     {
        (*ARRAY)[_dest] = (*ARRAY)[_dest-1];
     }
  }
  (*ARRAY)[INDEX] = ITEM;
  WAP_DBG_ASSERT(*SIZE<0xFFFF) /* childs_sum is kal_uint16 */
  (*SIZE)++;
}                                                                          


void widget_index_childs_func(int *CNT, MSF_UINT32 PARENT, void *CHILD)
{
  ASSERT(!IS_FLAG_STATIC(CHILD));

  for(*CNT=0;*CNT<_H(PARENT)->childs_sum;(*CNT)++)
  {
     if(_H(PARENT)->childs[*CNT] == _H(CHILD))
         break;
  }
  if(*CNT == _H(PARENT)->childs_sum)
      *CNT=-1;
}


void widget_set_active_childs_by_index_func(MSF_UINT32 PARENT, int INDEX)
{
  kal_uint32 i;
  widget_header_struct *tmp = _H(PARENT)->childs[INDEX];
  for(i=INDEX;i>0;i--)
     _H(PARENT)->childs[i] = _H(PARENT)->childs[i-1];
  _H(PARENT)->childs[0] = tmp;
}


void widget_get_active_childs_func(widget_header_struct **NODE, MSF_UINT32 PARENT)
{
  kal_uint32 cnt;
  widget_header_struct *_p = _H(PARENT);

  *NODE=NULL;
  for(cnt=0;cnt<_p->childs_sum;cnt++)
     if((_p->childs[cnt]->flag & WIDGET_FLAG_WINDOW)
     || IS_SCREEN_TYPE(_p->childs[cnt]))
     {
        widget_set_active_childs_by_index((MSF_UINT32) _p,cnt);
        *NODE = _p->childs[0];
        break;
     }
}


void widget_set_attrib_func(void *PARENT, MSF_UINT32 *ATTRIB, MSF_UINT32 NODE)
{
  if (*ATTRIB != NODE)
  {
     if (*ATTRIB && !IS_FLAG_STATIC(*ATTRIB))
     {
        widget_remove_childs(PARENT, *ATTRIB);
     }

     *ATTRIB = NODE;
     if(*ATTRIB && !IS_FLAG_STATIC(*ATTRIB))
        widget_insert_last_childs((MSF_UINT32) PARENT, NODE);
  }
}


void widget_set_attrib_ptr_func(void *PARENT, MSF_UINT32 **ATTRIB, MSF_UINT32 *NODE)
{
  if (*ATTRIB != NODE)
  {
     if (*ATTRIB && !IS_FLAG_STATIC(*ATTRIB))
     {
        widget_remove_childs(PARENT, *ATTRIB);
     }

     *ATTRIB = NODE;
     if(*ATTRIB && !IS_FLAG_STATIC(*ATTRIB))
        widget_insert_last_childs((MSF_UINT32) PARENT, NODE);
  }
}


void widget_remove_childs_by_index_func(MSF_UINT32 PARENT, int INDEX)
{
  if(INDEX!=-1 && INDEX <_H(PARENT)->childs_sum)
  {
     kal_uint32 i;
     DEC_REF(_H(PARENT)->childs[INDEX]);
     if(!HAS_REF(_H(PARENT)->childs[INDEX]))
        widget_release(_H(PARENT)->childs[INDEX]);

     _H(PARENT)->childs_sum--;
     for(i=INDEX;i<_H(PARENT)->childs_sum;i++)
        _H(PARENT)->childs[i] = _H(PARENT)->childs[i+1];
     _H(PARENT)->childs[i] = NULL;
  }
}
#endif /* WIDGET_USE_FUNCTIONS_TO_MACRO */
