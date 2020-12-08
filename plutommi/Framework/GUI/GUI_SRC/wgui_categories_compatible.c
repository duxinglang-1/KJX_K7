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
 *   wgui_categories_compatible.c
 *
 * Project:
 * --------
 *   MAUI_Software
 *
 * Description:
 * ------------
 *   Backward compatible for the new categories interface.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_list.h"
#include "wgui_categories_email.h"
#include "wgui_categories_cm.h"
#include "wgui_categories.h"
#include "wgui_categories_text_viewer.h"
#include "wgui.h"
#include "wgui_categories_idlescreen.h"
#include "wgui_categories_search.h"




/***************************************************************************** 
 * wgui_categories.c
 *****************************************************************************/
#undef ShowCategory88Screen
void ShowCategory88Screen(
            U16 title, 
            U16 title_icon, 
            U16 left_softkey, 
            U16 left_softkey_icon, 
            U16 right_softkey,
            U16 right_softkey_icon, 
            U16 bg_image_id, 
            U16 n_items, 
            U8 **string_list,
            S32 *lower_limit, 
            S32 *upper_limit, 
            S32 **current_value, 
            void (**cb_func) (S32 value),
            U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory88Screen_int(
            title, 
            title_icon, 
            left_softkey, 
            right_softkey,
            bg_image_id, 
            n_items, 
            string_list,
            lower_limit, 
            upper_limit, 
            current_value, 
            cb_func,
            history_buffer);
}


#undef ShowCategory87Screen
void ShowCategory87Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 l_limit,
                    S32 u_limit,
                    S32 *current_value,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory87Screen_int(
                    title,
                    title_icon,
                    left_softkey,
                    right_softkey,
                    l_limit,
                    u_limit,
                    current_value,
                    history_buffer);
}

/***************************************************************************** 
 * wgui_categories_calendar.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_clock.c
 *****************************************************************************/

/***************************************************************************** 
 * wgui_categories_CM.c
 *****************************************************************************/
#if defined(__MMI_CAT116_SUPPORT__)
#undef wgui_cat116_set_right_softkey_function
void wgui_cat116_set_right_softkey_function(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}
#endif /* __MMI_CAT116_SUPPORT__ */


#undef ShowCategory16Screen
void ShowCategory16Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *Buffer,
                U32 BufferLength,
                U8 *history_buffer)
{
    ShowCategory16Screen_int(
		    left_softkey,
		    right_softkey,
		    Buffer,
		    BufferLength,
		    history_buffer);
}


#undef ShowCategory17Screen
void ShowCategory17Screen(
                U16 title_id,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 NotificationStringId,
                PU8 NameOrNumber,
                PU8 IP_Number,
                U16 CallLine,
                U16 default_image_id,
                U16 resource_id,
                CHAR* resource_filename,
                wgui_cate_momt_res_type_enum resource_type,
                U16 repeat_count,
                BOOL is_visaul_update,
                BOOL is_aud_enable,
                BOOL is_play_aud_when_start,
                PU8 history_buffer)
{
    ShowCategory17Screen_int(
		    title_id,
		    left_softkey,
		    right_softkey,
		    NotificationStringId,
		    NameOrNumber,
		    IP_Number,
		    CallLine,
		    default_image_id,
		    resource_id,
		    resource_filename,
		    resource_type,
		    repeat_count,
		    is_visaul_update,
		    is_aud_enable,
		    is_play_aud_when_start,
		    history_buffer);
}


#undef ShowCategory20Screen
void ShowCategory20Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *CallType,
                U8 *NameOrNumber,
                MYTIME *CurrCallTime,
                U16 CallLine,
                U16 CallState,
                WGUI_CATCALL_CALLER_MEDIA_INFO *CallerMedia,
                MMI_BOOL isDisconnecting,
                U8 *history_buffer)
{
    ShowCategory20Screen_int(
		    left_softkey,
		    right_softkey,
		    CallType,
		    NameOrNumber,
		    CurrCallTime,
		    CallLine,
		    CallState,
		    CallerMedia,
		    isDisconnecting,
		    history_buffer);
}


#undef ShowCategory403Screen
void ShowCategory403Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items,
                MYTIME *CallDuration,
                U16 duration_icon,
                U8 **list_of_items,
                U16 *list_of_icons,
                S32 number_of_items,
                U16 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory403Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    n_tabs,
		    highlighted_tab,
		    tab_items,
		    CallDuration,
		    duration_icon,
		    list_of_items,
		    list_of_icons,
		    number_of_items,
		    highlighted_item,
		    history_buffer);
}

/***************************************************************************** 
 * wgui_categories_common.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_dialer.c
 *****************************************************************************/

 /***************************************************************************** 
 * wgui_categories_email.c
 *****************************************************************************/
#undef ShowCategory263Screen
void ShowCategory263Screen(
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
    ShowCategory263Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    get_item_func,
		    get_hint_func,
		    highlighted_item,
		    list_icon,
		    history_buffer,
		    category_error_flag);
}


#undef ShowCategory267Screen
void ShowCategory267Screen(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
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
    ShowCategory267Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    get_item_func,
		    get_hint_func,
		    get_state_func,
		    set_state_func,
		    info_message,
		    highlighted_item,
		    list_icon,
		    history_buffer,
		    category_error_flag);
}


#undef ShowCategory268Screen
void ShowCategory268Screen(
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
    ShowCategory268Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    get_item_func,
		    get_hint_func,
		    highlighted_item,
		    list_icon,
		    history_buffer,
		    category_error_flag);
}


#undef wgui_cat1002_show
void wgui_cat1002_show(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
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
    wgui_cat1002_show_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    get_item_func,
		    get_hint_func,
		    get_state_func,
		    set_state_func,
		    info_message,
		    highlighted_item,
		    list_icon,
		    history_buffer,
		    category_error_flag);
}

/***************************************************************************** 
 * wgui_categories_ems.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_fmgr.c
 *****************************************************************************/

 /***************************************************************************** 
 * wgui_categories_idlescreen.c
 *****************************************************************************/
 
#undef ShowCategory33Screen
void ShowCategory33Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory33Screen_int(
        left_softkey,
        right_softkey,
        history_buffer);
}

#undef ShowCategory33Screen_ext
void ShowCategory33Screen_ext(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory33Screen_ext_int(
        left_softkey,
        right_softkey,
        history_buffer);
}

 
/***************************************************************************** 
 * wgui_categories_IMPS.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_inputs.c
 *****************************************************************************/
#undef ShowCategory5Screen_ext
void ShowCategory5Screen_ext(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer,
                S16 input_ext_type,
                mmi_imm_input_mode_enum *required_input_mode_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory5Screen_ext_int(
                    title,
                    title_icon,
                    left_softkey,
                    right_softkey,
                    input_type,
                    buffer,
                    buffer_size,
                    history_buffer,
                    input_ext_type,
                    required_input_mode_set);
}


#undef ShowCategory5Screen_ext2
void ShowCategory5Screen_ext2(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer,
        S16 input_ext_type,
        mmi_imm_input_mode_enum *required_input_mode_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory5Screen_ext2_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        input_type,
        buffer,
        buffer_size,
        history_buffer,
        input_ext_type,
        required_input_mode_set);
}


#ifdef __J2ME__
#undef wgui_cat2002_show
void wgui_cat2002_show(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,      
        U8 *ticker_text,
        U8 *buffer,
        S32 buffer_size,
        U32 input_type,
        mmi_imm_input_mode_enum *required_input_mode_set,
        MMI_BOOL is_active_editor,
        S16 input_ext_type,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat2002_show_int(
            title,
            title_icon,
            left_softkey,
            right_softkey,   
            ticker_text,
            buffer,
            buffer_size,
            input_type,
            required_input_mode_set,
            is_active_editor,
            input_ext_type,
            history_buffer);
}
#endif /* __J2ME__ */


#ifdef UI_SMALL_CATEGORY_EDITOR
#undef ShowCategory100Screen
void ShowCategory100Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer,
                S16 input_ext_type,
                mmi_imm_input_mode_enum *required_input_mode_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory100Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                input_type,
                buffer,
                buffer_size,
                history_buffer,
                input_ext_type,
                required_input_mode_set);
}
#endif /* UI_SMALL_CATEGORY_EDITOR */


#undef ShowCategory171Screen
void ShowCategory171Screen(
                U8 *left_softkey,
                PU8 left_softkey_icon,
                U8 *right_softkey,
                PU8 right_softkey_icon,
                U8 *message,
                PU8 message_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory171Screen_int(
                left_softkey,
                right_softkey,
                message,
                message_icon,
                input_type,
                buffer,
                buffer_size,
                history_buffer);
}


#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
#undef ShowCategory115Screen_ext
void ShowCategory115Screen_ext(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *buffer,
                S32 buffer_size,
                U8 *input_format,
                U8 input_required,
                U32 input_type,
                U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory115Screen_ext_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                buffer,
                buffer_size,
                input_format,
                input_required,
                input_type,
                history_buffer);
}


#undef ShowCategory115ScreenEx
void ShowCategory115ScreenEx(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *buffer,
        S32 buffer_size,
        S16 *predefined_pos,
        void (*cursor_move_callback)(S32 cursor_offset),
        MMI_BOOL (*change_event_handler)(gui_multi_line_input_box_change_event_enum event,U16 c),
        U32 input_type,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory115ScreenEx_int(
            title,
            title_icon,
            left_softkey,
            right_softkey,
            buffer,
            buffer_size,
            predefined_pos,
            cursor_move_callback,
            change_event_handler,
            input_type,
            history_buffer);
}
#endif /* __MMI_WCSS_INPUT_FORMAT_SUPPORT__ */


#undef ShowCategory215Screen
void ShowCategory215Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory215Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        input_type,
        buffer,
        buffer_size,
        history_buffer);
}


#undef ShowCategory215Screen_ext
void ShowCategory215Screen_ext(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory215Screen_ext_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        input_type,
        buffer,
        buffer_size,
        history_buffer);
}


#undef ShowCategory415Screen
void ShowCategory415Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 message,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory415Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        message,
        input_type,
        buffer,
        buffer_size,
        history_buffer);
}


#undef ShowCategory69Screen
void ShowCategory69Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message,
                    U32 input_type,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory69Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                input_type,
                buffer,
                buffer_size,
                history_buffer);
}


#ifdef UI_SMALL_PIN_EDITOR_SCREEN
#undef ShowCategory112Screen
void ShowCategory112Screen(
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U32 input_type,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *message2,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory112Screen_int(
                left_softkey,
                right_softkey,
                message,
                input_type,
                buffer,
                buffer_size,
                message2,
                history_buffer);
}
#endif /* UI_SMALL_PIN_EDITOR_SCREEN */


#undef ShowCategory111Screen
void ShowCategory111Screen(
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message,
                    U32 input_type,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *message2,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory111Screen_int(
                    left_softkey,
                    right_softkey,
                    message,
                    input_type,
                    buffer,
                    buffer_size,
                    message2,
                    history_buffer);
}


#undef ShowCategory111Screen_ext
void ShowCategory111Screen_ext(
                      U16 left_softkey, 
                      U16 left_softkey_icon, 
                      U16 right_softkey, 
                      U16 right_softkey_icon, 
                      U8 *message, 
                      U32 input_type, 
                      U8 *buffer, 
                      S32 buffer_size, 
                      U8 *message2, 
                      S32 duration, 
                      U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory111Screen_ext_int(
                  left_softkey, 
                  right_softkey, 
                  message, 
                  input_type, 
                  buffer, 
                  buffer_size, 
                  message2, 
                  duration, 
                  history_buffer);
}


#ifdef __MMI_SEARCH_WEB__
#undef wgui_cat2001_show
void wgui_cat2001_show(
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer,
        mmi_imm_input_mode_enum *required_input_mode_set,
        U32 category_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat2001_show_int(
        title_icon,
        left_softkey,
        right_softkey,
        input_type,
        buffer,
        buffer_size,
        history_buffer,
        required_input_mode_set,
        category_flags);
}
#endif /* __MMI_SEARCH_WEB__ */


#undef wgui_cat2003_show
void wgui_cat2003_show(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        UI_string_type message,
        UI_buffer_type input_buffer,
        S32 input_buffer_size,
        U32 input_type,
        UI_buffer_type history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat2003_show_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        message,
        input_buffer,
        input_buffer_size,
        input_type,
        history_buffer);
}


#undef SetCategory5RightSoftkeyFunction
void SetCategory5RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


#undef SetCategory171RightSoftkeyFunction
void SetCategory171RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


#undef SetCategory415RightSoftkeyFunction
void SetCategory415RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


#undef SetCategory111RightSoftkeyFunction
void SetCategory111RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
 }


#undef SetCategory69RightSoftkeyFunction
void SetCategory69RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


#ifdef __MMI_SEARCH_WEB__
#undef wgui_cat2001_set_rsk_function
void wgui_cat2001_set_rsk_function(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}
#endif /* __MMI_SEARCH_WEB__ */


 /***************************************************************************** 
 * wgui_categories_list.c
 *****************************************************************************/
#undef ShowCategory85Screen
void ShowCategory85Screen(
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
                U16 left_icon,
                U16 right_icon_1,
                U16 right_icon_2,
                U8 *history_buffer)
{
	ShowCategory85Screen_int(
    		title,
    		title_icon,
    		left_softkey,
    		right_softkey,
    		number_of_items,
    		get_item_func,
    		get_hint_func,
    		highlighted_item,
    		left_icon,
    		right_icon_1,
    		right_icon_2,
    		history_buffer);
}

#undef ShowCategory427Screen
void ShowCategory427Screen(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory427Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    get_item_func,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory802Screen_ext
void ShowCategory802Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                S32 current_cm_level,
                S32 max_cm_level,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory802Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    current_cm_level,
		    max_cm_level,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory801Screen
void ShowCategory801Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_icons,
                U8 *list_of_flags,
                S32 current_cm_level,
                S32 max_cm_level,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory801Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    list_of_flags,
		    current_cm_level,
		    max_cm_level,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory801Screen_ext
void ShowCategory801Screen_ext(
    	         U8* title,
    	         U8* title_icon,
    	         U8* left_softkey,
    	         U8* left_softkey_icon,
    	         U8* right_softkey,
    	         U8* right_softkey_icon,
    	         S32 number_of_items,
    	         U8 **list_of_items,
    	         U8 **list_of_icons,
    	         U8 *list_of_flags,
    	         S32 current_cm_level,
    	         S32 max_cm_level,
    	         S32 highlighted_item,
    	         U8 *history_buffer)
{
    ShowCategory801Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    list_of_flags,
		    current_cm_level,
		    max_cm_level,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory800Screen
void ShowCategory800Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                S32 current_cm_level,
                S32 max_cm_level,
                U16 cm_menu_id,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory800Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    current_cm_level,
		    max_cm_level,
		    cm_menu_id,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory1Screen
void ShowCategory1Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory1Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory6Screen
void ShowCategory6Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory6Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_descriptions,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory6Screen_ext
void ShowCategory6Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory6Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_descriptions,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory55Screen
void ShowCategory55Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory55Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_descriptions,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory52Screen
void ShowCategory52Screen(
                  U16 title,
                  U16 title_icon,
                  U16 left_softkey,
                  U16 left_softkey_icon,
                  U16 right_softkey,
                  U16 right_softkey_icon,
                  S32 number_of_items,
                  U16 *list_of_items,
                  U16 *list_of_icons,
                  U8 **list_of_descriptions,
                  S32 flags,
                  S32 highlighted_item,
                  U8 *history_buffer)
{
    ShowCategory52Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    list_of_descriptions,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory53Screen
void ShowCategory53Screen(
                  U16 title,
                  U16 title_icon,
                  U16 left_softkey,
                  U16 left_softkey_icon,
                  U16 right_softkey,
                  U16 right_softkey_icon,
                  S32 number_of_items,
                  U8 **list_of_items,
                  U16 *list_of_icons,
                  U8 **list_of_descriptions,
                  S32 flags,
                  S32 highlighted_item,
                  U8 *history_buffer)
{
    ShowCategory53Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    list_of_descriptions,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory353Screen
void ShowCategory353Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons,
                U8 **list_of_descriptions,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory353Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    list_of_descriptions,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory353Screen_ext
void ShowCategory353Screen_ext(
                U8 *title,
                U8 *title_icon,
                U8 *left_softkey,
                U8 *left_softkey_icon,
                U8 *right_softkey,
                U8 *right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons,
                U8 **list_of_descriptions,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory353Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    list_of_descriptions,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory11Screen
void ShowCategory11Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory11Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory36Screen
void ShowCategory36Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory36Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory36Screen_ext
void ShowCategory36Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory36Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory12Screen
void ShowCategory12Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 *list_of_states,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory12Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_states,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory12Screen_ext
void ShowCategory12Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 *list_of_states,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory12Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_states,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory13Screen
void ShowCategory13Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U8 *list_of_states,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory13Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_states,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory15Screen
void ShowCategory15Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory15Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory170Screen
void ShowCategory170Screen(
                U8 *title,
                PU8 title_icon,
                U8 *left_softkey,
                PU8 left_softkey_icon,
                U8 *right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                PU8 *list_of_icons,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory170Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory172Screen
void ShowCategory172Screen(
                   U8 *title,
                   PU8 title_icon,
                   U8 *left_softkey,
                   PU8 left_softkey_icon,
                   U8 *right_softkey,
                   PU8 right_softkey_icon,
                   S32 number_of_items,
                   U8 **list_of_items,
                   S32 flags,
                   S32 highlighted_item,
                   U8 *history_buffer)
{
    ShowCategory172Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory174Screen
void ShowCategory174Screen(
                   U8 *title,
                   PU8 title_icon,
                   U8 *left_softkey,
                   PU8 left_softkey_icon,
                   U8 *right_softkey,
                   PU8 right_softkey_icon,
                   S32 number_of_items,
                   U8 **list_of_items,
                   PU8 *list_of_icons,
                   U8 **list_of_descriptions,
                   S32 flags,
                   S32 highlighted_item,
                   U8 *history_buffer)
{
    ShowCategory174Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    list_of_descriptions,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory109Screen
void ShowCategory109Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory109Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_descriptions,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory109Screen_ext
void ShowCategory109Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory109Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_descriptions,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory89Screen
void ShowCategory89Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_descriptions,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory89Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_descriptions,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory89Screen_ext
void ShowCategory89Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_descriptions,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory89Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_descriptions,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory155Screen
void ShowCategory155Screen(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                U16 paraent_id, 
                U16 *item_icons,
                U8 **item_popups,
                S32 flag,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory155Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    paraent_id,
		    item_icons,
		    item_popups,
		    flag,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory73ScreenExt
void ShowCategory73ScreenExt(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons1,
                U16 *list_of_icons2,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer,
                U8 u8display_flag)
{
    ShowCategory73ScreenExt_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons1,
		    list_of_icons2,
		    list_of_descriptions,
		    highlighted_item,
		    history_buffer,
		    u8display_flag);
}


#undef ShowCategory73Screen
void ShowCategory73Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons1,
                U16 *list_of_icons2,
                S32 highlighted_item,
                U8 *history_buffer,
                U8 u8display_flag)
{
    ShowCategory73Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons1,
		    list_of_icons2,
		    highlighted_item,
		    history_buffer,
		    u8display_flag);
}


#undef ShowCategory73Screen_ext
void ShowCategory73Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons1,
                U16 *list_of_icons2,
                S32 highlighted_item,
                U8 *history_buffer,
                U8 u8display_flag)
{
    ShowCategory73Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons1,
		    list_of_icons2,
		    highlighted_item,
		    history_buffer,
		    u8display_flag);
}


#undef ShowCategory354Screen
void ShowCategory354Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U8 **list_of_items2,
                U16 *list_of_icons,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory354Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items1,
		    list_of_items2,
		    list_of_icons,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory354Screen_ext
void ShowCategory354Screen_ext(
                U8 *title,
                U8 *title_icon,
                U8 *left_softkey,
                U8 *left_softkey_icon,
                U8 *right_softkey,
                U8 *right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U8 **list_of_items2,
                U16 *list_of_icons,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory354Screen_ext_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items1,
		    list_of_items2,
		    list_of_icons,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory84Screen
void ShowCategory84Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory84Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    number_of_items,
		    list_of_items,
		    list_of_icons,
		    flags,
		    highlighted_item,
		    history_buffer);
}


#undef ShowCategory22Screen
void ShowCategory22Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_symbols,
                U8 **MMI_symbols,
                S32 highlighted_item,
                U8 *history_buffer)
{
    ShowCategory22Screen_int(
		    title,
		    title_icon,
		    left_softkey,
		    right_softkey,
		    num_of_symbols,
		    MMI_symbols,
		    highlighted_item,
		    history_buffer);
}

/***************************************************************************** 
 * wgui_categories_memory.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_MM.c
 *****************************************************************************/

 /***************************************************************************** 
 * wgui_categories_MMS.c
 *****************************************************************************/
#undef SetCategory275RightSoftkeyFunction
void SetCategory275RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


/***************************************************************************** 
 * wgui_categories_MMS_viewer.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_multimedia.c
 *****************************************************************************/
#undef ShowCategory221Screen
void ShowCategory221Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    gdi_color background_color,
                    FuncPtr redraw_content_callback)
{
    ShowCategory221Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        background_color,
        redraw_content_callback);
}

#undef ShowCategory222ScreenInternal
void ShowCategory222ScreenInternal(
                 UI_string_type title,
                 PU8 title_icon,
                 UI_string_type left_softkey,
                 PU8 left_softkey_icon,
                 UI_string_type right_softkey,
                 PU8 right_softkey_icon,
                 gdi_color background_color,
                 S8 *button_string,
                 S8 *file_name_ptr,
                 BOOL is_short_filename,
                 void (*decode_result_callback) (GDI_RESULT),
                 gdi_image_src_enum src_type)
{
    ShowCategory222ScreenInternal_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        background_color,
        button_string,
        file_name_ptr,
        is_short_filename,
        decode_result_callback,
        src_type);
}

#undef ShowCategory222Screen
 void ShowCategory222Screen(
                 U16 title,
                 U16 title_icon,
                 U16 left_softkey,
                 U16 left_softkey_icon,
                 U16 right_softkey,
                 U16 right_softkey_icon,
                 gdi_color background_color,
                 S8 *button_string,
                 S8 *file_name_ptr, 
                 BOOL is_short, 
                 void (*decode_result_callback) (S32),
                 gdi_image_src_enum src_type)
{
    ShowCategory222Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        background_color,
        button_string,
        file_name_ptr,
        is_short,
        decode_result_callback,
        src_type);
}

#undef ShowCategory223Screen
 void ShowCategory223Screen(
                 U16 title,
                 U16 title_icon,
                 U16 left_softkey,
                 U16 left_softkey_icon,
                 U16 right_softkey,
                 U16 right_softkey_icon,
                 U16 message_icon,
                 U16 flag,
                 U32 duration,
                 U8 *history_buffer)
{
    ShowCategory223Screen_int(
                    title,
                    title_icon,
                    left_softkey,
                    right_softkey,
                    message_icon,
                    flag,
                    duration,
                    history_buffer);
}
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#undef ShowCategory225Screen
void ShowCategory225Screen(U16 title_str,
                                  U16 title_icon,
                                  U16 lsk_str,
                                  U16 lsk_icon,
                                  U16 rsk_str,
                                  U16 rsk_icon,
                                  U16 video_id,
                                  PS8 video_filename,
                                  U16 repeat_count,
                                  BOOL is_visual_update,
                                  BOOL is_play_audio,
                                  BOOL is_lcd_no_sleep,
                                  GDI_COLOR bg_color, void (*play_finish_callback) (S32), void *gui_buffer)
{
    ShowCategory225Screen_int(
        title_str,
        title_icon,
        lsk_str,
        rsk_str,
        video_id,
        video_filename,
        repeat_count,
        is_visual_update,
        is_play_audio,
        is_lcd_no_sleep,
        bg_color,
        play_finish_callback,
        gui_buffer);
}

#endif

#if defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
#undef ShowCategory334Screen
 void ShowCategory334Screen(
             UI_string_type title,
             PU8 title_icon,
             UI_string_type left_softkey,
             PU8 left_softkey_icon,
             UI_string_type right_softkey,
             PU8 right_softkey_icon,
             wgui_cat334_info_struct* cat_info,
             U8* history_buffer)
{
    ShowCategory334Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        cat_info,
        history_buffer);
}
#endif

#undef ShowCategory129Screen
 void ShowCategory129Screen(
                     U8 *title,
                     U16 title_icon,
                     U16 left_softkey,
                     U16 left_softkey_icon,
                     U16 right_softkey,
                     U16 right_softkey_icon,
                     U16 message_icon,
                     U8 *history_buffer)
{
    ShowCategory129Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        message_icon,
        history_buffer);
}

#undef ShowCategory132Screen
 void ShowCategory132Screen(
                    U8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message_icon,
                    U8 *history_buffer)
{
    ShowCategory132Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        message_icon,
        history_buffer);
}

#undef ShowCategory227Screen
 void ShowCategory227Screen(U8 *title_string,
                                   U16 title_icon,
                                   U16 left_softkey,
                                   U16 left_softkey_icon,
                                   U16 right_softkey,
                                   U16 right_softkey_icon, void (*display_call_back) (dm_coordinates *coordinate),
                                   MMI_BOOL (*pen_all_call_back)(mmi_pen_event_type_enum pen_event,mmi_pen_point_struct point))
{
    ShowCategory227Screen_int(
        title_string,
        title_icon,
        left_softkey,
        right_softkey,
        display_call_back,
        pen_all_call_back);
}

 /***************************************************************************** 
 * wgui_categories_notification.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_op.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_panel.c
 *****************************************************************************/

 /***************************************************************************** 
 * wgui_categories_PE.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_popup.c
 *****************************************************************************/
 #undef ShowCategory8Screen
void ShowCategory8Screen(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            U16 message,
            U16 message_icon,
            U8 *history_buffer)
{
    ShowCategory8Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                message_icon,
                history_buffer);
}
 
#undef ShowCategory66Screen
void ShowCategory66Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U16 message_icon,
                    U8 *history_buffer)
{
    ShowCategory66Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                message_icon,
                history_buffer);
}

#undef ShowCategory121Screen
void ShowCategory121Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *message,
                U16 message_icon,
                U8 *history_buffer,
                U8 flag)
{
    ShowCategory121Screen_int(
        left_softkey,
        right_softkey,
        message,
        message_icon,
        history_buffer,
        flag);
}
 
#undef ShowCategory123Screen
void ShowCategory123Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 message,
                U16 message_icon,
                U8 *history_buffer)
{
    ShowCategory123Screen_int(
                    title,
                    title_icon,
                    left_softkey,
                    right_softkey,
                    message,
                    message_icon,
                    history_buffer);
}

#undef ShowCategory124Screen
void ShowCategory124Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *message,
                U16 message_icon,
                U8 *history_buffer)
{
    ShowCategory124Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                message_icon,
                history_buffer);
}

#undef ShowCategory151Screen
void ShowCategory151Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *message,
                U8 *message_icon,
                U8 *history_buffer)
{
    ShowCategory151Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                message_icon,
                history_buffer);
}

#undef ShowCategory163Screen
void ShowCategory163Screen(
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer)
{
    ShowCategory163Screen_int(
        left_softkey,
        right_softkey,
        message,
        message_icon,
        history_buffer);
}

#undef ShowCategory164Screen
void ShowCategory164Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 message,
                U16 message_icon,
                U8 *history_buffer)
{
    ShowCategory164Screen_int(
                left_softkey,
                right_softkey,
                message,
                message_icon,
                history_buffer);
}

#undef ShowCategory165Screen
void ShowCategory165Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer)
{
    ShowCategory165Screen_int(
                left_softkey,
                right_softkey,
                message,
                message_icon,
                history_buffer);
}

#undef ShowCategory165Screen_ext
void ShowCategory165Screen_ext(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                S32 duration,
                U8 *history_buffer)
{
    ShowCategory165Screen_ext_int(
                left_softkey,
                right_softkey,
                message,
                message_icon,
                duration,
                history_buffer);
}

#undef ShowCategory208Screen
void ShowCategory208Screen(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            S8 *message,
            U16 message_icon,
            U8 *history_buffer)
{
    ShowCategory208Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                message_icon,
                history_buffer);
}
 
/***************************************************************************** 
 * wgui_categories_search.c
 *****************************************************************************/
#ifdef __MMI_CAT103_SUPPORT__
#undef ShowCategory103Screen
void ShowCategory103Screen(
            UI_string_type title,
            PU8 title_icon,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S32 number_of_items,
            S32 highlighted_item,
            GetItemFuncPtr get_item_func,
            GetHintFuncPtr get_hint_func,
            S32(*search_func) (UI_buffer_type),
            U8 *input_buffer,
            S32 input_buffer_max_length,
            U32 input_type,
            U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory103Screen_int(
            title,
            title_icon,
            left_softkey,
            right_softkey,
            number_of_items,
            highlighted_item,
            get_item_func,
            get_hint_func,
            search_func,
            input_buffer,
            input_buffer_max_length,
            input_type,
            history_buffer);
}
#endif /* __MMI_CAT103_SUPPORT__ */


#undef ShowCategory199Screen
void ShowCategory199Screen(
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S8 highlighted_tab,
            UI_string_type tab_title,
            UI_string_type info_message,
            S32 number_of_items,
            GetItemFuncPtr get_item_func,
            GetHintFuncPtr get_hint_func,
            checkbox_get_image_funcptr_type get_state_func,
            checkbox_clicked_funcptr_type set_state_func,
            S32 highlighted_item,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory199Screen_int(
        left_softkey,
        right_softkey,
        highlighted_tab,
        tab_title,
        info_message,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        highlighted_item,
        buffer,
        buffer_max_length,
        history_buffer);
}


#undef ShowCategory199Screen_ext
void ShowCategory199Screen_ext(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S8 highlighted_tab,
        UI_string_type tab_title,
        UI_string_type info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        PU8 left_icon,
        PU8 right_icon,
        U8 *buffer,
        S32 buffer_max_length,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory199Screen_ext_int(
        left_softkey,
        right_softkey,
        highlighted_tab,
        tab_title,
        info_message,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        highlighted_item,
        left_icon,
        right_icon,
        buffer,
        buffer_max_length,
        history_buffer);
}


#undef ShowCategory200Screen
void ShowCategory200Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    GetItemFuncPtr get_item_func,
                    GetHintFuncPtr get_hint_func,
                    S32 highlighted_item,
                    U16 search_image,
                    U8 *buffer,
                    S32 buffer_max_length,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory200Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                number_of_items,
                get_item_func,
                get_hint_func,
                highlighted_item,
                search_image,
                buffer,
                buffer_max_length,
                history_buffer);
}


#undef ShowCategory200Screen_ext
void ShowCategory200Screen_ext(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            S32 number_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            S32 highlighted_item,
            U16 search_image,
            PU8 left_icon,
            PU8 right_icon,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory200Screen_ext_int(
            title,
            title_icon,
            left_softkey,
            right_softkey,
            number_of_items,
            get_item_func,
            get_hint_func,
            highlighted_item,
            search_image,
            left_icon,
            right_icon,
            buffer,
            buffer_max_length,
            history_buffer);
}


#undef ShowCategory202Screen
void ShowCategory202Screen(
                           U16 title,
                           U16 title_icon,
                           U16 left_softkey,
                           U16 left_softkey_icon,
                           U16 right_softkey,
                           U16 right_softkey_icon,
                           U8* info_message,
                           S32 number_of_items,
                           GetItemFuncPtr get_item_func,
                           GetHintFuncPtr get_hint_func,
                           checkbox_get_image_funcptr_type get_state_func,
                           checkbox_clicked_funcptr_type set_state_func,        
                           S32 highlighted_item,
                           U16 search_image,
                           U8 *buffer,
                           S32 buffer_max_length,
                           U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory202Screen_int(
                           title,
                           title_icon,
                           left_softkey,
                           right_softkey,
                           info_message,
                           number_of_items,
                           get_item_func,
                           get_hint_func,
                           get_state_func,
                           set_state_func,        
                           highlighted_item,
                           search_image,
                           buffer,
                           buffer_max_length,
                           history_buffer);
}


#undef ShowCategory202Screen_ext
void ShowCategory202Screen_ext(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            U8* info_message,
            S32 number_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            checkbox_get_image_funcptr_type get_state_func,
            checkbox_clicked_funcptr_type set_state_func,        
            S32 highlighted_item,
            U16 search_image,
            PU8 left_icon,
            PU8 right_icon,
            U8 *buffer,
            S32 buffer_max_length,
            U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory202Screen_ext_int(
            title,
            title_icon,
            left_softkey,
            right_softkey,
            info_message,
            number_of_items,
            get_item_func,
            get_hint_func,
            get_state_func,
            set_state_func,        
            highlighted_item,
            search_image,
            left_icon,
            right_icon,
            buffer,
            buffer_max_length,
            history_buffer);
}


#undef ShowCategory201Screen
void ShowCategory201Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    GetItemFuncPtr get_item_func,
                    GetHintFuncPtr get_hint_func,
                    S32 highlighted_item,
                    U16 search_image,
                    U8 *buffer,
                    S32 buffer_max_length,
                    U32 input_type,
                    U8 *history_buffer,
                    mmi_imm_input_mode_enum * required_input_mode_set)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory201Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                number_of_items,
                get_item_func,
                get_hint_func,
                highlighted_item,
                search_image,
                buffer,
                buffer_max_length,
                input_type,
                history_buffer,
                required_input_mode_set);
}


#ifdef __MMI_CAT203_SUPPORT__
#undef wgui_cat203_set_right_softkey_function
void wgui_cat203_set_right_softkey_function(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}
#endif /* __MMI_CAT203_SUPPORT__ */


#undef SetCategory200RightSoftkeyFunction
void SetCategory200RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


#undef wgui_cat201_set_right_softkey_function
void wgui_cat201_set_right_softkey_function(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


 /***************************************************************************** 
 * wgui_categories_sim.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_stopwatch.c
 *****************************************************************************/
 
/*****************************************************************************
 * wgui_categories_sublcd.c
 *****************************************************************************/

 /***************************************************************************** 
 * wgui_categories_tab.c
 *****************************************************************************/
 
/***************************************************************************** 
 * wgui_categories_text_viewer.c
 *****************************************************************************/
#undef ShowCategory21Screen
void ShowCategory21Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory21Screen_int(
                   title,
                   title_icon,
                   left_softkey,
                   right_softkey,
                   message,
                   history_buffer);
}


#undef ShowCategory74Screen
void ShowCategory74Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *buffer,
                    S32 buffer_length,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory74Screen_int(
                    title,
                    title_icon,
                    left_softkey,
                    right_softkey,
                    buffer,
                    buffer_length,
                    history_buffer);
}


#undef wgui_cat3001_show
void wgui_cat3001_show(
            UI_string_type tab_title,
            UI_string_type left_softkey,
            PU8 left_softkey_icon,
            UI_string_type right_softkey,
            PU8 right_softkey_icon,
            S8 highlighted_tab,
            MMI_BOOL need_scrollbar,
            UI_buffer_type buffer,
            S32 buffer_length,
            UI_buffer_type history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat3001_show_int(
            tab_title,
            left_softkey,
            right_softkey,
            highlighted_tab,
            need_scrollbar,
            buffer,
            buffer_length,
            history_buffer);
}


#undef ShowCategory78Screen
void ShowCategory78Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    multi_line_input_box_icon_hdlr icon_callback,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory78Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                icon_callback,
                buffer,
                buffer_size,
                history_buffer);
}


#undef ShowCategory152Screen
void ShowCategory152Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory152Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                history_buffer);
}


#undef ShowCategory7Screen
void ShowCategory7Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory7Screen_int(
                title,
                title_icon,
                left_softkey,
                right_softkey,
                message,
                history_buffer);
}


/***************************************************************************** 
 * wgui_categories_UCE.c
 *****************************************************************************/
#undef SetCategory280RightSoftkeyFunction
void SetCategory280RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_category_set_rsk_func(f);
}


 /***************************************************************************** 
 * wgui_categories_util.c
 *****************************************************************************/


 
/*****************************************************************************
 *  ChangeLeftSoftkey
 *****************************************************************************/
#undef ChangeLeftSoftkey
void ChangeLeftSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkeyExt(s);
}

/*****************************************************************************
 *  ChangeLeftSoftkey
 *****************************************************************************/
#undef ChangeRightSoftkey
void ChangeRightSoftkey(U16 s, U16 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkeyExt(s);
}

