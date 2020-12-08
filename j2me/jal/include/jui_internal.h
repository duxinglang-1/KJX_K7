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
 *  jui_internal.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _JUI_INTERNAL_H
#define _JUI_INTERNAL_H

#include "MMI_features.h"
#include "MMI_include.h"
#include "lcd_sw_inc.h"
#include "gdi_include.h"

#define __JUI_USE_DOUBLE_BUFFER_LAYER__

#if defined (J2ME_SLIM_MEMORY_SUPPORT) && defined (__SUPPORT_JAVA_VIRTUAL_KEYPAD__)
#define __JUI_VK_SLIM__
#endif

typedef enum
{
    JUI_ALERT_INFO = 1,
    JUI_ALERT_WARNING,
    JUI_ALERT_ERROR,
    JUI_ALERT_ALARM,
    JUI_ALERT_CONFIRMATION
} jui_alert_type_enum;

typedef enum
{
    JUI_OBJ_STATUS_BAR,
    JUI_OBJ_TITLE_BAR,
    JUI_OBJ_BUTTON_BAR,
    JUI_OBJ_MAX
} jui_obj_type_enum;

typedef struct
{
    kal_bool show_status_bar;
    kal_bool show_title_bar;
    kal_bool show_button_bar;
} jui_mode_struct;

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
typedef struct
{
    kal_int32 x;
    kal_int32 y;
    kal_int32 width;
    kal_uint16 key_code;
    kal_uint16 content_img_id;
    kal_uint16 content_str_id;
    kal_uint8 content_type;
} jui_vk_coordinate_struct;

typedef enum
{
    JUI_VK_TYPE_NAVIGATION,
    JUI_VK_TYPE_NUMERIC,
    JUI_VK_TYPE_END
} jui_vk_type_enum;

typedef enum
{
    JUI_VK_CONTENT_TYPE_IMAGE,
    JUI_VK_CONTENT_TYPE_STRING,
    JUI_VK_CONTENT_TYPE_END
} jui_vk_content_type_enum;
#endif

extern kal_bool jui_widget_obj_show_status(jui_obj_type_enum obj, kal_int32 display_id);

extern void jui_widget_set_hardware_layer(gdi_handle handle, U32 bltindex, U32* bltflag);
extern void jui_widget_update_fullscreen_status_icons(void *MsgStruct);
extern void jui_widget_draw_alpha_blending_fullscreen_status_icons(void);
extern void jui_widget_mvm_reset_base_layer(kal_int32 display_id);
extern void jui_widget_mvm_clear_base_layer(kal_int32 display_id);
extern void jui_widget_mvm_textbox_show_internal(module_type src_module,module_type dst_module,kal_int32 display_id);
extern void jui_widget_mvm_textbox_backup_text(kal_int32 display_id);
extern void jui_widget_config_blt_layer(void);
extern void jui_widget_update_fullscreen_status_icons_cb(void);
extern void jui_widget_free_layers(void);
extern void jui_widget_layer_set_position(GDI_HANDLE act_layer);
extern void jui_widget_draw_status_bar0(void);
extern void jui_widget_draw_status_bar0_background(void);
extern void jui_widget_init_data(kal_int32 data_index);
extern void jui_widget_init_datas(void);
extern void jui_widget_init_title_offset(void);
extern void jui_widget_init_java_status_icon_buffer(void);
extern void jui_widget_deinit_java_status_icon_buffer(void);
extern kal_bool jui_widget_is_status_icon_changed(void);
extern kal_bool jui_widget_override_mode_setting(jui_obj_type_enum obj, kal_bool display_status, kal_int32 display_id);
extern kal_int32 jui_widget_convert_jui_type_2_mmi_type(kal_int32 input_type);

static void jui_widget_get_displayable_area(
                kal_int32 *ret_x,
                kal_int32 *ret_y,
                kal_int32 *ret_width,
                kal_int32 *ret_height);
extern void jui_widget_update_vm_bg_status_audio_icon(kal_bool is_java_bg_audio, kal_int32 display_id);
extern void jui_widget_reset_vm_bg_status_audio_icon(void);

extern void jui_widget_register_extra_symbol_callback(void);
extern void jui_widget_deregister_extra_symbol_callback(void);

#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
extern void jui_vk_init(kal_int32 display_id);
extern void jui_vk_deinit(kal_int32 display_id);
extern void jui_vk_clear(kal_int32 display_id);
extern void jui_vk_pen_down_hdlr(kal_int16 x, kal_int16 y);
extern void jui_vk_pen_up_hdlr(kal_int16 x, kal_int16 y);
extern void jui_vk_pen_repeat_hdlr(kal_int16 x, kal_int16 y);
extern void jui_vk_pen_long_tp_hdlr(kal_int16 x, kal_int16 y);
extern void jui_vk_pen_move_hdlr(kal_int16 x, kal_int16 y);
extern void jui_vk_keypad_highlight_clear(void);
extern kal_int32 jui_vk_get_display_id(void);
#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
extern void jui_vk_prepare_blt(kal_int32 display_id);
#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */

#endif

extern kal_int32 jui_ui_device_width;
extern kal_int32 jui_ui_device_height;

#if defined(__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_EM_MISC_JUI_DEBUG__*/
#endif /* _JUI_INTERNAL_H */ 

