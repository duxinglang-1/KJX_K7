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
 *  vadp_p2v_input_server_interface.h
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *  Venus input server p2v interfaces
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_P2V_INPUT_SERVER_INTERFACE_H__
#define __VADP_P2V_INPUT_SERVER_INTERFACE_H__

#ifdef __cplusplus
extern "C"
{
#endif

    #include "MMI_features.h"
    #include "ImeGprot.h"
    #include "MMIDataType.h"
    #include "wgui.h"
    #include "gui_typedef.h"
    #include "wgui_categories_list.h"
    #include "mmi_frm_input_gprot.h"
	#include "Imui.h"


/**********************************************************************
 * External Interfaces:
 **********************************************************************/
extern void vadp_p2v_close_ime_popup();
extern void vadp_p2v_redraw_imui_controls(U32 imuiSet);
extern void vadp_p2v_get_pos_from_fixed_control(S16* x, S16* y);
extern void vadp_p2v_set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
extern void vadp_p2v_set_key_handler(FuncPtr funcPtr, U16 keyCode, U16 keyType);
extern FuncPtr vadp_p2v_get_key_handler(U16 keyCode, U16 keyType);
extern void vadp_p2v_clear_key_handler(U16 keyCode, U16 keyType);
extern void vadp_p2v_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType);
extern void vadp_p2v_set_default_imui_parameters(mmi_imui_param_struct *param);
extern void vadp_p2v_get_current_key_info(U16 *keyCode, U16 *keyType);
extern MMI_BOOL vadp_p2v_send_imui_message(mmi_imui_message_struct_p msg_ptr, U32 *ret);
extern MMI_BOOL vadp_p2v_is_venus_ime_connected(void);

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
extern void vadp_p2v_start_capture_stroke(
                    U32 max_points,
                    mmi_pen_point_struct *point_array,
                    U32 num_regions,
                    const mmi_pen_handwriting_area_struct *region_array,
                    const mmi_pen_handwriting_area_struct *ext_region);
extern void vadp_p2v_stop_capture_stroke(void);
extern void vadp_p2v_begin_strokes_of_character(void);
extern void vadp_p2v_end_strokes_of_character(void);
extern void vadp_p2v_change_handwriting_area(U32 num_regions, const mmi_pen_handwriting_area_struct *region_array, const mmi_pen_handwriting_area_struct *ext_region);
extern void vadp_p2v_change_handwriting_area_ex(U32 num_regions, const mmi_pen_handwriting_area_struct *region_array, const mmi_pen_handwriting_area_struct *ext_region);

#endif

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) || defined(__MMI_IME_V3__)

extern void vadp_p2v_show_popup_list(
                    S32 x, 
                    S32 y, 
                    S32 number_of_items,
                    U16 *list_of_items,
                    S32 highlighted_item,
                    FuncPtr confirm_callback, 
                    FuncPtr cancel_callback);

typedef void (*Vadp_p2v_input_method_popup_cb) (S32);
typedef void (*Vadp_p2v_input_method_popup_cbExt) (void);

extern void vadp_p2v_show_ime_popup(
                U16 title_str_id,
                U16 *item_str_id_array,
                S32 item_count,
                S32 hilite_item,
                Vadp_p2v_input_method_popup_cb cb_func1,
				Vadp_p2v_input_method_popup_cbExt cb_func2,
				MMI_BOOL show_button);

extern void vadp_p2v_show_ime_popup_by_mem(
                U16 title_str_id,
                VfxWChar *item_str_array[],
                S32 item_count,
                S32 hilite_item,
                Vadp_p2v_input_method_popup_cb cb_func,
				Vadp_p2v_input_method_popup_cbExt cb_func2,
				MMI_BOOL show_button);

#endif

#if defined(__MMI_IME_USER_DATABASE__)
extern void vadp_p2v_show_new_word_editor(void);
#endif /* #if defined(__MMI_IME_USER_DATABASE__) */

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
extern void vadp_p2v_show_no_hw_data_popup(void);//show popup when no correct hw data
#endif

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __VADP_P2V_INPUT_SERVER_INTERFACE_H__ */

