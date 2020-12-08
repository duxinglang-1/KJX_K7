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
 *   gui_virtual_keyboard.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Virtual keyboard - UI component
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "wgui_categories_util.h"       /* get_image() */


#if defined(__MMI_VIRTUAL_KEYBOARD__)
    #include "mmi_rp_app_uiframework_def.h" 
    #include "kal_non_specific_general_types.h"
    #include "MMIDataType.h"
    #include "gui_virtual_keyboard_language_type.h"
    #include "gui_data_types.h"
    #include "mmi_frm_input_gprot.h"
    #include "gdi_datatype.h"
    #include "gdi_const.h"
    #include "gdi_include.h"
    #include "gui.h"
    #include "gui_theme_struct.h"
    #include "kal_release.h"
    #include "DebugInitDef_Int.h"
    #include "gdi_lcd_config.h"
    #include "lcd_sw_inc.h"
    #include "mmi_frm_mem_gprot.h"
    #include "CustThemesRes.h"
    #include "PixcomFontEngine.h"
    #include "string.h"
    #include "wgui_inputs.h"
    #include "CustDataRes.h"
    #include "mmi_rp_srv_virtual_keyboard_misc_def.h"
    #include "Unicodexdcl.h"
#if defined(__MMI_VUI_ENGINE__)
    #include "Framework\vadp_p2v_uc.h"
    #include "ime\vadp_p2v_input_server_interface.h"
#endif /* __MMI_VUI_ENGINE__ */

#define VKBD_DIFF_HALF_EXT(a, b) ((a) >= (b) ? (((a)-(b))>>1) : (-(((b)-(a))>>1)))

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
/*****************************************************************************
 * Following code is for VK V1
 ****************************************************************************/

#include "gui_virtual_keyboard.h"
#include "wgui_virtual_keyboard.h"
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_categories_defs.h"
#if defined(__MMI_INDIC_VK__)
#include  "IndicEngineGprot.h"
#endif 

#if defined(__MMI_TOUCH_SCREEN__)
/*
 * FIXME.
 *
 * 1. Currently we only support one matrix layout per keyboard.
 * 2. Use static memory to avoid out-of-memory in control buffer
 *
 */

extern BOOL r2lMMIFlag;

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define VKBD_DIFF_HALF(a, b)  ((a) >= (b) ? (((a) - (b)) - (((a)-(b))>>1)) : 0)
#else
#define VKBD_DIFF_HALF(a, b)  ((a) >= (b) ? (((a)-(b))>>1) : 0)
#endif
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __MMI_VK_POPUP_HINT__
static gui_virtual_keyboard_need_to_recache = MMI_FALSE;
#endif /* __MMI_VK_POPUP_HINT__ */
/***************************************************************************** 
* Local Function
*****************************************************************************/
#ifdef __MMI_VK_POPUP_HINT__
static void gui_virtual_keyboard_cache_and_show_selected_key_for_large_icon(
             virtual_keyboard *v);
static void gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon(
             virtual_keyboard *v);
static MMI_BOOL gui_virtual_keyboard_dummy_hide_cursor_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2);
#else /* __MMI_VK_POPUP_HINT__ */
static void gui_virtual_keyboard_cache_and_show_selected_key(virtual_keyboard *v);
static void gui_virtual_keyboard_show_unselect_key_from_cache(virtual_keyboard *v);
#endif /* __MMI_VK_POPUP_HINT__ */

static void gui_virtual_keyboard_default_hide_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2);
static void gui_virtual_keyboard_default_display_callback_function(
             gui_vkbd_display_callback_type_enum *flag,
             PU8 *content);
static void gui_virtual_keyboard_show_selected_key(virtual_keyboard *v);
extern void gui_virtual_keyboard_show_popup(virtual_keyboard *v, MMI_BOOL cache);

#ifdef __MMI_VK_POPUP_HINT__
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_dummy_hide_cursor_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_dummy_hide_cursor_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x1);
    UI_UNUSED_PARAMETER(y1);
    UI_UNUSED_PARAMETER(x2);
    UI_UNUSED_PARAMETER(y2);
}
#endif /* __MMI_VK_POPUP_HINT__ */


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
__inline static gui_virtual_keyboard_show_image(virtual_keyboard* v, S32 x, S32 y, PU8 img, gdi_handle source_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if ((v->is_venus_vk))
    {
        gdi_image_draw_blend2layers(x, y, img);
    }
    else
#endif 
    {
        gdi_push_and_set_alpha_blending_source_layer(source_layer);
        gui_show_image(x, y, img);         
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

}

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_clear_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_clear_selected_key(virtual_keyboard_selection_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->matrix_index = -1;
    s->matrix_column = -1;
    s->matrix_row = -1;
    s->custom_key_index = -1;
    s->key_width = 0;
    s->key_height = 0;
    s->key_x = 0;
    s->key_y = 0;
#ifdef __MMI_VK_POPUP_HINT__
    s->enlarged_key_x = 0;
    s->enlarged_key_y = 0;
    s->enlarged_key_width = 0;
    s->enlarged_key_height = 0;
    s->is_enlarging = MMI_FALSE;
#endif /* __MMI_VK_POPUP_HINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_check_dead_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static BOOL gui_virtual_keyboard_check_dead_key(virtual_keyboard *v, UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ch)
    {
        case 0x60:  /* ` */
        case 0xB4:
        case 0x5E:  /* ^ */
        case 0xA8:
        case 0x7E:  /* ~ */
        case 0x02C7:
        case 0x0385:
        case 0x0384:
        case 0x00B8:
        case 0x02DB:
        case 0x030a:
        case 0x0303:
        case 0x0301:
        case 0x030c:
        case 0x0300:
        case 0x0307:    
            return MMI_TRUE;
        case 0x00B0:
            if (v->lang_type == GUI_VIRTUAL_KEYBOARD_LATVIAN ||
                v->lang_type == GUI_VIRTUAL_KEYBOARD_LATVIAN_UPPERCASE)    
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_char_center_align
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch                  [IN]        
 *  key_x               [IN]        
 *  key_y               [IN]        
 *  key_width           [IN]        
 *  key_height          [IN]        
 *  glyph_width         [OUT]         
 *  glyph_height        [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_show_char_center_align(
                UI_character_type ch,
                S32 key_x,
                S32 key_y,
                S32 key_width,
                S32 key_height,
                S32 *glyph_width,
                S32 *glyph_height,
                UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == 0) 
        return;
#ifdef __MMI_SCRIPT_EASY__
    if ((ch == (UI_character_type)'_') || (ch == (UI_character_type)(0x0e3a)))
    {
        int     char_x, char_y;
        gui_measure_character(ch, glyph_width, glyph_height);
        char_x = key_x + VKBD_DIFF_HALF(key_width, *glyph_width);
        char_y = key_y + VKBD_DIFF_HALF(key_width, *glyph_height);
        gui_print_character_at_xy(ch, char_x, char_y);
    }
    else
    {
        extern void se_mtk_draw_char_center_align(unsigned short ch, int x, int y, int width, int height);
        gui_measure_character(ch, glyph_width, glyph_height);
        se_mtk_draw_char_center_align(ch, key_x, key_y, key_width, key_height);
    }
#else /* __MMI_SCRIPT_EASY__ */

    if (ch == (UI_character_type)'_' || ch == 0x0e3a)
    {
        mmi_fe_show_char_with_bounding_box(key_x, key_y, key_width, key_height, ch, MMI_FE_ALIGN_BOTTOM, *font);
    }
#if defined(__MMI_INDIC_VK__)
    else if (IRE_INDIC_CHARACTER_UCS2_RANGE(ch))
    {
    	gui_measure_character(ch, glyph_width, glyph_height);
        if (key_height > (*glyph_height))
        {
    	    mmi_fe_show_char_with_bounding_box(key_x, key_y, key_width, key_height, ch, MMI_FE_ALIGN_TOP, *font);
        }
        else
        {
            mmi_fe_show_char_with_bounding_box(key_x, key_y, key_width, key_height, ch, MMI_FE_ALIGN_CENTER, *font);
        }
    }
#endif
    else
    {
        mmi_fe_show_char_with_bounding_box(key_x, key_y, key_width, key_height, ch, MMI_FE_ALIGN_CENTER, *font);
    }
#endif /* __MMI_SCRIPT_EASY__  */
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_convert_custom_img
 * DESCRIPTION
 *  Convert some image ID of custom key because some images are displayed 
 *  differently in multi-block handwriting
 * PARAMETERS 
 *  v           [IN/OUT]         
 *  id          [IN]        image ID of custom key
 * RETURNS
 *  Converted image id
 *****************************************************************************/
static MMI_ID_TYPE gui_virtual_keyboard_convert_custom_img(virtual_keyboard *v, MMI_ID_TYPE id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Phone number keyboard layout coexist with multi-block but it has IMG_VKBD_CUSTOM_HIDE key */
    if (!(v->flags & GUI_VKBD_FLAG_MULTI_BLOCK_MODE) ||
        v->lang_type == GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER ||
        v->lang_type == GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER_WILDCHAR)
    {
        if (id == IMG_VKBD_CUSTOM_HIDE_SMALL)
        {
            return IMG_VKBD_CUSTOM_HIDE;
        }
        else if (id == IMG_VKBD_CUSTOM_HIDE)
        {
            #if defined(__MMI_HANDWRITING_MULTI_BLOCK__) && !defined(__NO_HANDWRITING__)
            if (v->lang_type == GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER ||
                v->lang_type == GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER_WILDCHAR)
            {
                return IMG_VKBD_CUSTOM_SWITCH_HANDWRITING;
            }
            else
            #endif /* defined(__MMI_HANDWRITING_MULTI_BLOCK__) && #if !defined(__NO_HANDWRITING__) */
            {
                return id;
            }
        }
        else
        {
            return id;
        }
    }
    else if (id == IMG_VKBD_CUSTOM_HIDE)
    {
         if (v->lang_type == GUI_VIRTUAL_KEYBOARD_ARABIC)
	 {
		return IMG_VKBD_CUSTOM_HIDE_SMALL;
	}
	else 
	{
            return IMG_VKBD_CUSTOM_SWITCH_HANDWRITING;
        }
    }
    else if (id == IMG_VKBD_CUSTOM_SHOW)
    {
        return IMG_VKBD_CUSTOM_SWITCH_KEYBOARD;
    }
    else
    {
        return id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_is_key_disabled
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v           [IN/OUT]         
 *  event       [IN]        
 *  ch          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_key_disabled(
                    virtual_keyboard *v,
                    gui_virtual_keyboard_pen_enum event,
                    UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->allowed_characters)
    {
        MMI_BOOL disabled = MMI_TRUE;
	S32 i;

        /* gui_set_virtual_keyboard_allowed_characters() and 
           gui_set_virtual_board_disable_list() are mutually-exclusive */
	MMI_DBG_ASSERT(v->disabled_chars[0] == 0);
	/* we will allow IME to disable special symbols even allowed_characters has content */
	for (i = 0;  i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
	{
	    if (v->disabled_symbols[i] == GUI_VKBD_PEN_NONE)
	    {
	        break;
	    }
	    MMI_DBG_ASSERT(v->disabled_symbols[i] == GUI_VKBD_PEN_HIDE ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_SHOW ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_CAPSLOCK ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_SYMBPICKER ||
                           v->disabled_symbols[i] == GUI_VKBD_PEN_DISPLAY_CALLBACK ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_BAKSPACE ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_NEWLINE ||
			   v->disabled_symbols[i] == GUI_VKBD_PEN_SPACE);
	}

        switch (event)
        {
                // TODO: GUI_VKBD_PEN_EUROSYMB is not supported
            case GUI_VKBD_PEN_HIDE:
            case GUI_VKBD_PEN_SHOW:
            case GUI_VKBD_PEN_CAPSLOCK:
			case GUI_VKBD_PEN_SYMBPICKER:
            case GUI_VKBD_PEN_DISPLAY_CALLBACK:
            case GUI_VKBD_PEN_BAKSPACE:
		 {
		     disabled = MMI_FALSE;
		     for (i = 0;  i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
		     {
			  if (v->disabled_symbols[i] == GUI_VKBD_PEN_NONE)
			  {
			      break;
			  }
			  if (v->disabled_symbols[i] == event)
			  {
			      disabled = MMI_TRUE;
			      break;
			  }
		     }
		 }
		 break;

            case GUI_VKBD_PEN_DISPLAY_AREA:
                /* GUI_VKBD_PEN_DISPLAY_AREA is always enabled because it's display only */
                disabled = MMI_FALSE;
                break;

            case GUI_VKBD_PEN_NEWLINE:
                ch = (UI_character_type) '\n';
                event = GUI_VKBD_PEN_CHAR_I;
                break;

            case GUI_VKBD_PEN_SPACE:
                ch = (UI_character_type) ' ';
                event = GUI_VKBD_PEN_CHAR_I;
                break;

        }

        if (event == GUI_VKBD_PEN_CHAR_I)
        {
            const UI_character_type *pch = v->allowed_characters;
            S32 idx;

            for (idx = 0; pch[idx]; idx++)
            {
                UI_character_type tmp = pch[idx];

                if (tmp == (UI_character_type) '-' && idx > 0 && pch[idx + 1])
                {
                    if (ch >= pch[idx - 1] && ch <= pch[idx + 1])
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                    idx++;
                }
                else
                {
                    if (tmp == (UI_character_type) '\\' && pch[idx + 1])
                    {
                        tmp = pch[++idx];
                    }

                    if (tmp == ch)
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                }
            }
        }

        return disabled;
    }
    else
    {
        if (event == GUI_VKBD_PEN_CHAR_I)
        {
            UI_character_type *ptr = v->disabled_chars, tmp;

            if (ch == 0)
            {
                return MMI_TRUE;
            }
            #if defined(__MMI_INDIC_VK__)

                if (!ire_vk_get_grey() && IRE_INDIC_LANGUAGE_RANGE(ch) && ire_IsValidInput(&ch, 2) == MMI_FALSE)
                {
                    return MMI_TRUE;
                }
            #endif /* defined(__MMI_INDIC_VK__) */ 

            while ((tmp = *ptr++) != 0)
            {
                if (tmp == ch)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
        else if (event == GUI_VKBD_PEN_NONE)
        {
            return MMI_TRUE;
        }
        else
        {
            gui_virtual_keyboard_pen_enum *ptr = v->disabled_symbols, tmp;

            while ((tmp = *ptr++) != GUI_VKBD_PEN_NONE)
            {
                if (tmp == event)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_default_hide_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]
 *  y1      [IN]
 *  x2      [IN]
 *  y2      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_default_hide_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_default_display_callback_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_default_display_callback_function(
             gui_vkbd_display_callback_type_enum *flag,
             PU8 *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *flag = GUI_VKBD_DISPLAY_CALLBACK_START;
    *content = NULL;
}

/* Return > 0 if dead key sequence is completed */


/*****************************************************************************
 * FUNCTION
 *  gui_get_dead_key_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_type           [IN]        
 *  input_string        [IN]         
 *  input_len           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_get_dead_key_symbol(
                    gui_virtual_keyboard_language_enum lang_type,
                    U16 *input_string,
                    S32 input_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 n_entry;
    const gui_keyboard_language_struct *lang;
    const gui_dead_key_map_struct *t;
    const gui_dead_key_symbol_struct *d;
    gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(lang_type);
    lang = vk_item->virtual_keyboard_language;

    if (!lang->enable_dead_key)
    {
        return 0;
    }

    t = wgui_get_virtual_keyboard_dead_key_setting(lang_type);

    n_entry = t->nentry;

    d = &t->dead_key_symbol[0];
    for (i = 0; i < n_entry; i++)
    {
        if (input_len != d->nInputLen)
        {
            continue;
        }

        if (memcmp(d->input_char, input_string, d->nInputLen * 2) == 0)
        {
            return d->output_char;
        }
        d++;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 *  s       [IN]  
 *  ch      [OUT]     
 *  evt     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static BOOL gui_virtual_keyboard_get_selected_key(
                virtual_keyboard *v,
                virtual_keyboard_selection_struct *s,
                UI_character_type *ch,
                gui_virtual_keyboard_pen_enum *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_language_struct *lang;

    gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    *ch = 0;
    *evt = GUI_VKBD_PEN_NONE;

    lang = vk_item->virtual_keyboard_language;

    if (s->matrix_index < 0 && s->custom_key_index < 0)
    {
        return MMI_FALSE;
    }

    if (s->matrix_index >= 0)
    {
        MMI_DBG_ASSERT(s->matrix_column >= 0 && s->matrix_row >= 0);
        *evt = GUI_VKBD_PEN_CHAR_I;
        *ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else
    {
        *evt = lang->custom_key_type[s->custom_key_index];
        *ch = lang->custom_string[s->custom_key_index];
    }

    MMI_DBG_ASSERT(!*ch || *evt == GUI_VKBD_PEN_CHAR_I);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_dead_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 *  ch      [IN/OUT]     
 *  evt     [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_translate_dead_key(
                virtual_keyboard *v,
                UI_character_type *ch,
                gui_virtual_keyboard_pen_enum *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_language_struct *lang;

    gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    lang = vk_item->virtual_keyboard_language;

    if (lang->enable_dead_key)
    {
        if (*evt == GUI_VKBD_PEN_CHAR_I)
        {
            if (gui_virtual_keyboard_check_dead_key(v, *ch))
            {
                v->dead_key_input[0] = *ch;
                *ch = 0;
                *evt = GUI_VKBD_PEN_DEAD_KEY;
            }
            else if (v->dead_key_input[0])
            {
                /* Only two key combination is currently supported */
                UI_character_type ret;

                v->dead_key_input[1] = *ch;
                if ((ret = gui_get_dead_key_symbol(v->lang_type, v->dead_key_input, 2)) != 0)
                {
                    *ch = ret;
                }
                /* Otherwise, use the original key */

                v->dead_key_input[0] = 0;
            }
        }
        else
        {
            v->dead_key_input[0] = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_clear_dead_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_clear_dead_key(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->dead_key_input[0] = 0;
}


#ifndef __MMI_VK_POPUP_HINT__
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_cache_and_show_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_cache_and_show_selected_key(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    S32 glyph_width, glyph_height;
    virtual_keyboard_selection_struct *s;
    const gui_keyboard_language_struct *lang;
    UI_character_type ch = 0;
    PU8 img = NULL;
    U8 *dynamic_content = NULL;
    gui_vkbd_display_callback_type_enum flag;
    S16 dynamic_content_x;
    gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    lang = vk_item->virtual_keyboard_language;
    s = &v->selected_key;

    MMI_DBG_ASSERT(s->custom_key_index >= 0 || s->matrix_index >= 0);

    if (s->custom_key_index >= 0 && lang->custom_key_type[s->custom_key_index] == GUI_VKBD_PEN_DISPLAY_AREA)
    {
        /* We do not select Display Area. Furthermore, it costs too much memory to cache the area */
        return;
    }

    x1 = s->key_x;
    y1 = s->key_y;
    x2 = x1 + s->key_width - 1;
    y2 = y1 + s->key_height - 1;

    /* Use a fixed size to avoid running out of certain control buffer bucket size */
    MMI_DBG_ASSERT((((S32) s->key_width * s->key_height * gdi_layer_get_bit_per_pixel() + 7) >> 3) <=
                   MMI_virtual_keyboard_bitmap_cache_size);
    v->selected_key_cached = MMI_TRUE;
#if 1
    {
        /* Workaround. We might not be able allocate large control buffer */
        #if defined(__MMI_MAINLCD_320X240__)
            #if (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_32) //|| defined(__MMI_VUI_ENGINE__)
                    static char bitmap_buffer[6400];    
            #elif (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_24)
                    static char bitmap_buffer[4800];   
            #else
                    static char bitmap_buffer[3200];
            #endif
        #elif defined(__MMI_MAINLCD_320X480__)
            #if (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_32)//|| defined(__MMI_VUI_ENGINE__)
                    static char bitmap_buffer[25000];    
            #elif (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_24)
                    static char bitmap_buffer[19000];   
            #else
                    static char bitmap_buffer[18200];
            #endif        
        #else /* __MMI_MAINLCD_320X240__ */ 
            #if (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_32)//|| defined(__MMI_VUI_ENGINE__)
                    static char bitmap_buffer[5000];    
            #elif (__MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_24)
                    static char bitmap_buffer[3750];   
            #else
                    static char bitmap_buffer[2500];
            #endif
        #endif /*__MMI_MAINLCD_320X240__*/

        MMI_ASSERT(MMI_virtual_keyboard_bitmap_cache_size < sizeof(bitmap_buffer));
        v->selected_key_bitmap.buf_ptr = (U8*) bitmap_buffer;
    }
#else /* 1 */ 
/* under construction !*/
#endif /* 1 */ 

#if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
#endif
    {
    gui_lock_double_buffer();
    }
    gdi_layer_push_clip();

    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->selected_key_bitmap);

    /* Under 128x160 resolution, we draw highlight to be filled whole cell because the character may touch the four edges of cell */
#ifdef __MMI_MAINLCD_128X160__ 
    gui_draw_filled_area(x1, y1, x2, y2, v->keyboard_theme->key_down_filler);
#elif defined(__MMI_MAINLCD_320X480__)
    gdi_draw_round_rect(
        x1 + 1,
        y1 + 1,
        x2,
        y2,
        gdi_act_color_from_rgb(
            150,
            (v->keyboard_theme->key_down_filler)->c.r,
            (v->keyboard_theme->key_down_filler)->c.g,
            (v->keyboard_theme->key_down_filler)->c.b),
        gdi_act_color_from_rgb(
            255,
            (v->keyboard_theme->key_down_filler)->c.r,
            (v->keyboard_theme->key_down_filler)->c.g,
            (v->keyboard_theme->key_down_filler)->c.b),
            1);
#else /* __MMI_MAINLCD_128X160__ */
    gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, v->keyboard_theme->key_down_filler);
#endif /* __MMI_MAINLCD_128X160__ */

    if (s->matrix_index >= 0)
    {
        ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else if (s->custom_key_index >= 0 && lang->custom_string[s->custom_key_index])
    {
        ch = lang->custom_string[s->custom_key_index];
    }
    else if (lang->custom_key_type[s->custom_key_index] ==
             GUI_VKBD_PEN_DISPLAY_CALLBACK)
    {
        if (v->display_callback != NULL)
        {
            v->display_callback(&flag, &dynamic_content);
        }
    }
    else
    {
        img = get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[s->custom_key_index]));
    }

    if (ch)
    {
        gui_set_font(v->keyboard_theme->text_font);
        gui_set_text_color(v->keyboard_theme->key_down_text_color);
		if (lang->enable_dead_key && gui_virtual_keyboard_check_dead_key(v, ch))
		{
			gui_set_text_color(v->keyboard_theme->dead_key_down_text_color);
		}

        gui_virtual_keyboard_show_char_center_align(
            ch,
            s->key_x + GUI_VKBD_KEY_TEXT_OFFSET,
            s->key_y,
            s->key_width - 2 * GUI_VKBD_KEY_TEXT_OFFSET,
            s->key_height,
            &glyph_width,
            &glyph_height,
            v->keyboard_theme->text_font);
    }

    if (dynamic_content)
    {
        if (flag == GUI_VKBD_DISPLAY_CALLBACK_IMG)
        {
            gdi_image_get_dimension(dynamic_content, &glyph_width, &glyph_height);
            gui_virtual_keyboard_show_image(
                v, 
                s->key_x + VKBD_DIFF_HALF(s->key_width, glyph_width),
                s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height),
                dynamic_content,
                (gdi_handle)gdi_act_layer);            
        }
        if (flag == GUI_VKBD_DISPLAY_CALLBACK_TEXT)
        {
            gui_set_font(v->keyboard_theme->text_font);
            gui_set_text_color(v->keyboard_theme->key_down_text_color);
            gui_measure_string((UI_string_type)dynamic_content, &glyph_width, &glyph_height);
            dynamic_content_x = s->key_x + ((s->key_width - glyph_width) >> 1);
            if (mmi_fe_get_r2l_state())
            {
                dynamic_content_x += glyph_width;
            }        
            gui_move_text_cursor(dynamic_content_x, s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height));
        #if defined(__MMI_VUI_ENGINE__)
            if (v->is_venus_vk)
            {
                gui_print_text((UI_string_type)dynamic_content);            
            }
            else
        #endif
            {
            gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
            gui_print_text((UI_string_type)dynamic_content);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
    }
    }

    if (img)
    {
        gui_measure_image(img, &glyph_width, &glyph_height);
        gui_virtual_keyboard_show_image(
            v, 
            s->key_x + VKBD_DIFF_HALF(s->key_width, glyph_width),
            s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height),
            img, 
            (gdi_handle)gdi_act_layer);
    }

    gdi_layer_pop_clip();
#if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
#endif
    {
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
}
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_unselect_key_from_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_show_unselect_key_from_cache(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key_cached == MMI_FALSE)
    {
        return;
    }

    x1 = v->selected_key.key_x;
    y1 = v->selected_key.key_y;
    x2 = x1 + v->selected_key.key_width - 1;
    y2 = y1 + v->selected_key.key_height - 1;

    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_draw(x1, y1, &v->selected_key_bitmap);
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);

    /* gui_free(v->selected_key_bitmap.buf_ptr); */
    v->selected_key_bitmap.buf_ptr = NULL;
    v->selected_key_cached = MMI_FALSE;
}

#else /* __MMI_VK_POPUP_HINT__ */
#if defined(__MMI_MAINLCD_320X480__)
extern stFontAttribute MMI_virtual_keyboard_hint_font;
#endif
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_cache_and_show_selected_key_for_large_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_cache_and_show_selected_key_for_large_icon(
             virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    S32 glyph_width, glyph_height;

    virtual_keyboard_selection_struct *s;
    const gui_keyboard_language_struct *lang;
    UI_character_type ch = 0;
    PU8 img = NULL;
    U8 *dynamic_content = NULL;
    gui_vkbd_display_callback_type_enum flag;
    S16 dynamic_content_x;

    gui_keyboard_lang_map_struct_p vk_item;
    S32 cache_buf_size;
   // gdi_handle active_layer = GDI_NULL_HANDLE;
   // gdi_handle abm_layer = GDI_NULL_HANDLE;

   // PU8 zoom_img = NULL;

    PU8 temp_img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    lang = vk_item->virtual_keyboard_language;
    s = &v->selected_key;

    MMI_DBG_ASSERT(s->custom_key_index >= 0 || s->matrix_index >= 0);

    if (s->custom_key_index >= 0 && lang->custom_key_type[s->custom_key_index] == GUI_VKBD_PEN_DISPLAY_AREA)
    {
        /* We do not select Display Area. Furthermore, it costs too much memory to cache the area */
        return;
    }

    x1 = s->key_x;
    y1 = s->key_y;
    x2 = x1 + s->key_width - 1;
    y2 = y1 + s->key_height - 1;

    if (s->matrix_index >= 0)
    {
        ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else if (s->custom_key_index >= 0 && lang->custom_string[s->custom_key_index])
    {
        ch = lang->custom_string[s->custom_key_index];
    }
    else if (lang->custom_key_type[s->custom_key_index] ==
             GUI_VKBD_PEN_DISPLAY_CALLBACK)
    {
        if (v->display_callback != NULL)
        {
            v->display_callback(&flag, &dynamic_content);
        }
    }
    else
    {
        img = get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[s->custom_key_index]));
    }

    if (v->keyboard_theme->popup_hint_left_image != NULL &&
        v->keyboard_theme->popup_hint_right_image != NULL)
    {
        temp_img = v->keyboard_theme->popup_hint_left_image;
    }
    
    if (dynamic_content)
    {
    #if defined(__MMI_VUI_ENGINE__)
        if (v->is_venus_vk)
    #endif
        {        
        gui_lock_double_buffer();
        }       
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        cache_buf_size = (s->key_width * s->key_height * (gdi_act_layer->bits_per_pixel)) >> 3;
        /* if the buf is not NULL, first free the buffer */
        if (v->selected_key_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(v->selected_key_bitmap.buf_ptr);
            v->selected_key_bitmap.buf_ptr = NULL;
            v->selected_key_cached = MMI_FALSE;
        }
        v->selected_key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size);
        MMI_DBG_ASSERT(v->selected_key_bitmap.buf_ptr != NULL);

        gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->selected_key_bitmap);
        v->selected_key_cached = MMI_TRUE;

        /* Under 128x160 resolution, we draw highlight to be filled whole cell because the character may touch the four edges of cell */
        #if defined(__MMI_MAINLCD_128X160__)
            gui_draw_filled_area(x1, y1, x2, y2, v->keyboard_theme->key_down_filler);
        #elif defined(__MMI_MAINLCD_320X480__)
            gdi_draw_round_rect(
                x1 + 1,
                y1 + 1,
                x2,
                y2,
                gdi_act_color_from_rgb(
                    150,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                gdi_act_color_from_rgb(
                    255,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                1);
        #else /* __MMI_MAINLCD_128X160__ */
            gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, v->keyboard_theme->key_down_filler);
        #endif /* __MMI_MAINLCD_128X160__ */

        if (flag == GUI_VKBD_DISPLAY_CALLBACK_TEXT)
        {
            gui_set_font(v->keyboard_theme->text_font);
            gui_set_text_color(v->keyboard_theme->key_down_text_color);
            gui_measure_string((UI_string_type)dynamic_content, &glyph_width, &glyph_height);
            dynamic_content_x = s->key_x + ((s->key_width - glyph_width) >> 1);
            if (mmi_fe_get_r2l_state())
            {
                dynamic_content_x += glyph_width;
            }        
            gui_move_text_cursor(dynamic_content_x, s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height));
            gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
            gui_print_text((UI_string_type)dynamic_content);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        if (flag == GUI_VKBD_DISPLAY_CALLBACK_IMG)
        {
            gdi_image_get_dimension(dynamic_content, &glyph_width, &glyph_height);
            gui_virtual_keyboard_show_image(
                v,
                s->key_x + VKBD_DIFF_HALF(s->key_width, glyph_width),
                s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height),
                dynamic_content,
                (gdi_handle)gdi_act_layer);
        }

        gdi_layer_pop_clip();
    #if defined(__MMI_VUI_ENGINE__)
        if (v->is_venus_vk)
    #endif
        {           
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }
    }

    if ((img != NULL) || (ch && temp_img == NULL))
    {
        gui_lock_double_buffer();
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        ///TODO: ailsa
        //cache_buf_size = (s->key_width * s->key_height * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL) >> 3;
        cache_buf_size = (s->key_width * s->key_height * (gdi_act_layer->bits_per_pixel)) >> 3;
        /* if the buf is not NULL, first free the buffer */
        if (v->selected_key_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(v->selected_key_bitmap.buf_ptr);
            v->selected_key_bitmap.buf_ptr = NULL;
            v->selected_key_cached = MMI_FALSE;
        }
        v->selected_key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size);
        MMI_DBG_ASSERT(v->selected_key_bitmap.buf_ptr != NULL);

        gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->selected_key_bitmap);
        v->selected_key_cached = MMI_TRUE;

        /* Under 128x160 resolution, we draw highlight to be filled whole cell because the character may touch the four edges of cell */
        #if defined(__MMI_MAINLCD_128X160__)
            gui_draw_filled_area(x1, y1, x2, y2, v->keyboard_theme->key_down_filler);
        #elif defined(__MMI_MAINLCD_320X480__)
            gdi_draw_round_rect(
                x1 + 1,
                y1 + 1,
                x2,
                y2,
                gdi_act_color_from_rgb(
                    150,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                gdi_act_color_from_rgb(
                    255,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                1);
        #else /* __MMI_MAINLCD_128X160__ */
            gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, v->keyboard_theme->key_down_filler);
        #endif /* __MMI_MAINLCD_128X160__ */

        if (img)
        {
            gui_measure_image(img, &glyph_width, &glyph_height);
            gui_virtual_keyboard_show_image(
                v,
                s->key_x + VKBD_DIFF_HALF(s->key_width, glyph_width),
                s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height),
                img,
                (gdi_handle)gdi_act_layer);
        }
        else
        {
            gui_set_font(v->keyboard_theme->text_font);
            gui_set_text_color(v->keyboard_theme->key_down_text_color);
            if (lang->enable_dead_key && gui_virtual_keyboard_check_dead_key(v, ch))
            {
                gui_set_text_color(v->keyboard_theme->dead_key_down_text_color);
            }

            gui_virtual_keyboard_show_char_center_align(
                ch,
                s->key_x + GUI_VKBD_KEY_TEXT_OFFSET,
                s->key_y,
                s->key_width - 2 * GUI_VKBD_KEY_TEXT_OFFSET,
                s->key_height,
                &glyph_width,
                &glyph_height,
                v->keyboard_theme->text_font);
        }
        gdi_layer_pop_clip();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }

    if (ch && temp_img != NULL)
    {
///TODO: ailsa
        /* cache current displayed content */
        cache_buf_size = (s->key_width * s->key_height *
                          (gdi_act_layer->bits_per_pixel)) >> 3;

        MMI_DBG_ASSERT(cache_buf_size  <=
                       GUI_VKBD_LARGE_ICON_CACHE_SIZE);

        gdi_layer_push_clip();

        /* cache selected key */
        gdi_layer_set_clip(x1, y1, x2, y2);
        /* if the buf is not NULL, first free the buffer */
        if (v->selected_key_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(v->selected_key_bitmap.buf_ptr);
            v->selected_key_bitmap.buf_ptr = NULL;
            v->selected_key_cached = MMI_FALSE;
        }
        v->selected_key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size);
        MMI_DBG_ASSERT(v->selected_key_bitmap.buf_ptr != NULL);
        gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->selected_key_bitmap);
        v->selected_key_cached = MMI_TRUE;


        gui_lock_double_buffer();

        /* highlight selected key */
        gui_set_font(v->keyboard_theme->text_font);
        gui_set_text_color(v->keyboard_theme->key_down_text_color);

    #if defined(__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__)
        gui_draw_filled_area(
            x1 + 1,
            y1 + 1,
            x2 - 1,
            y2 - 1,
            v->keyboard_theme->key_down_filler);
    #elif defined(__MMI_MAINLCD_320X480__)
        gdi_draw_round_rect(
            x1 + 1,
            y1 + 1,
            x2,
            y2,
            gdi_act_color_from_rgb(
                150,
                (v->keyboard_theme->key_down_filler)->c.r,
                (v->keyboard_theme->key_down_filler)->c.g,
                (v->keyboard_theme->key_down_filler)->c.b),
            gdi_act_color_from_rgb(
                255,
                (v->keyboard_theme->key_down_filler)->c.r,
                (v->keyboard_theme->key_down_filler)->c.g,
                (v->keyboard_theme->key_down_filler)->c.b),
            1);
    #else
        gui_draw_filled_area(
            x1 + 1,
            y1 + 1,
            x2 - 1,
            y2 - 1,
            v->keyboard_theme->key_down_filler);
    #endif /* defined(__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) */

        if (lang->enable_dead_key && gui_virtual_keyboard_check_dead_key(v, ch))
        {
            gui_set_text_color(v->keyboard_theme->dead_key_down_text_color);
        }

        gui_virtual_keyboard_show_char_center_align(
            ch,
            s->key_x + GUI_VKBD_KEY_TEXT_OFFSET,
            s->key_y,
            s->key_width - 2 * GUI_VKBD_KEY_TEXT_OFFSET,
            s->key_height,
            &glyph_width,
            &glyph_height,
            v->keyboard_theme->text_font);
        gui_virtual_keyboard_show_popup(v, MMI_TRUE);
        gui_unlock_double_buffer();
        gdi_layer_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon(
             virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key_cached == MMI_FALSE)
    {
        return;
    }

    gui_lock_double_buffer();
    gdi_layer_push_clip();

#if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        //vadp_p2v_close_virtual_keyboard_popup();
    }
    else    
#endif
    {
        if (v->selected_key.is_enlarging == MMI_TRUE && v->selected_key_enlarged_bitmap.buf_ptr)
        {
            x1 = v->selected_key.enlarged_key_x;
            y1 = v->selected_key.enlarged_key_y;
            x2 = x1 + v->selected_key.enlarged_key_width - 1;
            y2 = y1 + v->selected_key.enlarged_key_height - 1;
            gdi_layer_set_clip(x1, y1, x2, y2);
            gdi_image_cache_bmp_draw(x1, y1, &v->selected_key_enlarged_bitmap);
            mmi_frm_scrmem_free(v->selected_key_enlarged_bitmap.buf_ptr);
            v->selected_key_enlarged_bitmap.buf_ptr = NULL;
        }
    }

    x1 = v->selected_key.key_x;
    y1 = v->selected_key.key_y;
    x2 = x1 + v->selected_key.key_width - 1;
    y2 = y1 + v->selected_key.key_height - 1;

    gdi_layer_set_clip(x1, y1, x2, y2);
    if (v->selected_key_bitmap.buf_ptr)
        gdi_image_cache_bmp_draw(x1, y1, &v->selected_key_bitmap);
    mmi_frm_scrmem_free(v->selected_key_bitmap.buf_ptr);
    v->selected_key_bitmap.buf_ptr = NULL;

    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
#if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
#endif
    {        
        if (v->selected_key.is_enlarging == MMI_TRUE)
        {
            if (x1 >= v->selected_key.enlarged_key_x)
            {
                x1 = v->selected_key.enlarged_key_x;
            }
            y1 = v->selected_key.enlarged_key_y;
            if (x2 < v->selected_key.enlarged_key_x + v->selected_key.enlarged_key_width - 1)
            {
                x2 = v->selected_key.enlarged_key_x + v->selected_key.enlarged_key_width - 1;
            }
        }

        gui_BLT_double_buffer(x1, y1, x2, y2);
    }

    v->selected_key_cached = MMI_FALSE;
    v->selected_key.is_enlarging = MMI_FALSE;
    if (v->blink_cursor_callback != NULL)
    {
        v->blink_cursor_callback();
    }
}


#endif /* __MMI_VK_POPUP_HINT__ */

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]         
 *  x       [IN]        
 *  y       [IN]        
 *  s       [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static BOOL gui_virtual_keyboard_translate_pen_position(
                virtual_keyboard *v,
                S16 x,
                S16 y,
                virtual_keyboard_selection_struct *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_layout_struct *layout;
    S32 i;

    gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    layout = vk_item->virtual_keyboard_layout;

    gui_virtual_keyboard_clear_selected_key(s);

    for (i = 0; i < layout->n_matrix_key_layout; i++)
    {
        const gui_matrix_key_layout_struct *matrix;
        S32 matrix_x, matrix_y;

        matrix = &layout->matrix_layout[i];
        matrix_x = v->x + matrix->x;
        matrix_y = v->y + matrix->y;
        if (PEN_CHECK_BOUND(x, y, matrix_x, matrix_y, matrix->width, matrix->height))
        {
            s->matrix_index = i;

            s->matrix_column = (x - matrix_x) / (matrix->key_width + matrix->horizontal_key_gap);
            if (s->matrix_column >= matrix->n_columns)
            {
                s->matrix_column = matrix->n_columns - 1;
            }

            s->matrix_row = (y - matrix_y) / (matrix->key_height + matrix->vertical_key_gap);
            if (s->matrix_row >= matrix->n_rows)
            {
                s->matrix_row = matrix->n_rows - 1;
            }

            s->key_width = matrix->key_width;
            s->key_height = matrix->key_height;
            s->key_x = matrix_x + s->matrix_column * (matrix->key_width + matrix->horizontal_key_gap);
            s->key_y = matrix_y + s->matrix_row * (matrix->key_height + matrix->vertical_key_gap);
            if (PEN_CHECK_BOUND(x, y, s->key_x, s->key_y, s->key_width, s->key_height))
			{
				return MMI_TRUE;
			}
			else
			{
				return MMI_FALSE;
			}
        }
    }

    for (i = 0; i < layout->n_custom_keys; i++)
    {
        const gui_custom_key_layout_struct *custom_key;
        S32 custom_key_x, custom_key_y;

        custom_key = &layout->custom_keys[i];
        custom_key_x = v->x + custom_key->x;
        custom_key_y = v->y + custom_key->y;

        if (PEN_CHECK_BOUND(x, y, custom_key_x, custom_key_y, custom_key->key_width, custom_key->key_height))
        {
            s->custom_key_index = i;

            s->key_width = custom_key->key_width;
            s->key_height = custom_key->key_height;
            s->key_x = custom_key_x;
            s->key_y = custom_key_y;
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/***************************************************************************** 
 * FUNCTION
 *  gui_virtual_keyboard_show_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static void gui_virtual_keyboard_show_selected_key(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    S32 glyph_width, glyph_height;
    const gui_keyboard_language_struct *lang;
    virtual_keyboard_selection_struct *s;
    UI_character_type ch = 0;
    PU8 img = NULL;
    gui_keyboard_lang_map_struct_p vk_item;
    S32 dynamic_content_x;
    PU8 dynamic_content = NULL;
    gui_vkbd_display_callback_type_enum flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key_cached == MMI_FALSE)
    {
        return;
    }

    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    lang = vk_item->virtual_keyboard_language;
    s = &v->selected_key;

    MMI_DBG_ASSERT(s->custom_key_index >= 0 || s->matrix_index >= 0);

    x1 = s->key_x;
    y1 = s->key_y;
    x2 = x1 + s->key_width - 1;
    y2 = y1 + s->key_height - 1;

    if (s->matrix_index >= 0)
    {
        ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else if (s->custom_key_index >= 0 && lang->custom_string[s->custom_key_index])
    {
        ch = lang->custom_string[s->custom_key_index];
    }
    else if (lang->custom_key_type[s->custom_key_index] ==
             GUI_VKBD_PEN_DISPLAY_CALLBACK)
    {
        if (v->display_callback != NULL)
        {
            v->display_callback(&flag, &dynamic_content);
            if (dynamic_content)
            {
                if (flag == GUI_VKBD_DISPLAY_CALLBACK_IMG)
                {
                    img = dynamic_content;
                }
            }
        }
    }
    else
    {
        img = get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[s->custom_key_index]));
    }

    if (img)
    {
        gui_lock_double_buffer();
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        /* Under 128x160 resolution, we draw highlight to be filled whole cell because the character may touch the four edges of cell */
        #if defined(__MMI_MAINLCD_128X160__) 
            gui_draw_filled_area(x1, y1, x2, y2, v->keyboard_theme->key_down_filler);
        #elif defined(__MMI_MAINLCD_320X480__)
            gdi_draw_round_rect(
                x1 + 1,
                y1 + 1,
                x2,
                y2,
                gdi_act_color_from_rgb(
                    150,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                gdi_act_color_from_rgb(
                    255,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                1);
        #else /* __MMI_MAINLCD_128X160__ */
            gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, v->keyboard_theme->key_down_filler);
        #endif /* __MMI_MAINLCD_128X160__ */

        gui_measure_image(img, &glyph_width, &glyph_height);
        gui_virtual_keyboard_show_image(
            v, 
            s->key_x + VKBD_DIFF_HALF(s->key_width, glyph_width),
            s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height),
            img,
            (gdi_handle)gdi_act_layer);
        gdi_layer_pop_clip();
        gui_unlock_double_buffer();
    }

    if (dynamic_content)
    {
        gui_lock_double_buffer();
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        /* Under 128x160 resolution, we draw highlight to be filled whole cell because the character may touch the four edges of cell */
        #if defined(__MMI_MAINLCD_128X160__) 
            gui_draw_filled_area(x1, y1, x2, y2, v->keyboard_theme->key_down_filler);
        #elif defined(__MMI_MAINLCD_320X480__)
            gdi_draw_round_rect(
                x1 + 1,
                y1 + 1,
                x2,
                y2,
                gdi_act_color_from_rgb(
                    150,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                gdi_act_color_from_rgb(
                    255,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                1);
        #else /* __MMI_MAINLCD_128X160__ */
             gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, v->keyboard_theme->key_down_filler);
        #endif /* __MMI_MAINLCD_128X160__ */

        if (flag == GUI_VKBD_DISPLAY_CALLBACK_TEXT)
        {
            gui_set_font(v->keyboard_theme->text_font);
            gui_set_text_color(v->keyboard_theme->key_down_text_color);
            gui_measure_string((UI_string_type)dynamic_content, &glyph_width, &glyph_height);
            dynamic_content_x = s->key_x + ((s->key_width - glyph_width) >> 1);
            if (mmi_fe_get_r2l_state())
            {
                dynamic_content_x += glyph_width;
            }        
            gui_move_text_cursor(dynamic_content_x, s->key_y + VKBD_DIFF_HALF(s->key_height, glyph_height));
            gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
            gui_print_text((UI_string_type)dynamic_content);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        gdi_layer_pop_clip();
        gui_unlock_double_buffer();
    }

    if (ch)
    {
        gui_lock_double_buffer();

        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        /* Under 128x160 resolution, we draw highlight to be filled whole cell because the character may touch the four edges of cell */
        #if defined(__MMI_MAINLCD_128X160__) 
            gui_draw_filled_area(x1, y1, x2, y2, v->keyboard_theme->key_down_filler);
        #elif defined(__MMI_MAINLCD_320X480__)
            gdi_draw_round_rect(
                x1 + 1,
                y1 + 1,
                x2,
                y2,
                gdi_act_color_from_rgb(
                    150,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                gdi_act_color_from_rgb(
                    255,
                    (v->keyboard_theme->key_down_filler)->c.r,
                    (v->keyboard_theme->key_down_filler)->c.g,
                    (v->keyboard_theme->key_down_filler)->c.b),
                1);
        #else /* __MMI_MAINLCD_128X160__ */
            gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, v->keyboard_theme->key_down_filler);
        #endif /* __MMI_MAINLCD_128X160__ */

        gui_set_font(v->keyboard_theme->text_font);
        gui_set_text_color(v->keyboard_theme->key_down_text_color);
        if (lang->enable_dead_key && gui_virtual_keyboard_check_dead_key(v, ch))
        {
            gui_set_text_color(v->keyboard_theme->dead_key_down_text_color);
        }

        gui_virtual_keyboard_show_char_center_align(
            ch,
            s->key_x + GUI_VKBD_KEY_TEXT_OFFSET,
            s->key_y,
            s->key_width - 2 * GUI_VKBD_KEY_TEXT_OFFSET,
            s->key_height,
            &glyph_width,
            &glyph_height,
            v->keyboard_theme->text_font);
        gdi_layer_pop_clip();

    #ifdef __MMI_VK_POPUP_HINT__
        if (v->selected_key.is_enlarging == MMI_TRUE)
        {
                gui_virtual_keyboard_show_popup(v, MMI_TRUE);
        }
    #endif /* __MMI_VK_POPUP_HINT__ */
        gui_unlock_double_buffer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_cache_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_cache_img(virtual_keyboard *v, S32 x, S32 y, S32 width, S32 height, PU8 bitmap_ptr, S32 cache_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


#if defined(__MMI_VK_POPUP_HINT__)

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_popup_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_virtual_keyboard_show_popup_content(virtual_keyboard *v, S32 x, S32 y, S32 width, S32 height, PU8 bgimg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_language_struct *lang;
    UI_character_type ch=0;
    S32 glyph_width, glyph_height;
    virtual_keyboard_selection_struct* s = &v->selected_key;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lang = (wgui_get_virtual_keyboard(v->lang_type))->virtual_keyboard_language;

    if (s->matrix_index >= 0)
    {
        ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else if (s->custom_key_index >= 0 && lang->custom_string[s->custom_key_index])
    {
        ch = lang->custom_string[s->custom_key_index];
    }

    if (ch)
    {
        gui_virtual_keyboard_show_image(
            v, 
            x,
            y, 
            bgimg, 
            (gdi_handle)gdi_act_layer);
        
        /* show large icon */
        gui_set_text_color(v->keyboard_theme->key_up_text_color);
        gui_set_font(&MMI_virtual_keyboard_hint_font);
        
        gui_virtual_keyboard_show_char_center_align(
            ch,
            x + GUI_VKBD_LARGE_ICON_TEXT_OFFSET,
            y,
            width - 2 * GUI_VKBD_LARGE_ICON_TEXT_OFFSET,
            height - GUI_VKBD_LARGE_ICON_ZOOM_ARROW_Y_OFFSET,
            &glyph_width,
            &glyph_height,
            &MMI_virtual_keyboard_hint_font);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_show_popup(virtual_keyboard *v, MMI_BOOL cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    virtual_keyboard_selection_struct* s = &v->selected_key;
    UI_character_type ch = 0;
    const gui_keyboard_language_struct *lang;
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    gdi_handle h0, h1, h2, h3;
    PU8 zoom_img = NULL;
    S32 large_icon_width = 0, large_icon_height = 0, large_icon_x, large_icon_y;
    S32 cache_buf_size_large_icon;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Popup only display if 
     *    1. the popup hint indicator (left and right) are available.
     *    2. key down accept 
     */
    if (v->keyboard_theme->popup_hint_left_image == NULL ||
        v->keyboard_theme->popup_hint_right_image == NULL ||
        !v->key_down_accepted)
    {
        return;
    }
    
    lang = (wgui_get_virtual_keyboard(v->lang_type))->virtual_keyboard_language;

    if (s->matrix_index >= 0)
    {
        ch = lang->matrix_string[s->matrix_row][s->matrix_column];
    }
    else if (s->custom_key_index >= 0 && lang->custom_string[s->custom_key_index])
    {
        ch = lang->custom_string[s->custom_key_index];
    }

    /*
     * Poup is only for character
     */
    if (!ch)
        return;

    x1 = s->key_x;
    y1 = s->key_y;
    x2 = x1 + s->key_width - 1;
    y2 = y1 + s->key_height - 1;

    v->selected_key.is_enlarging = MMI_TRUE;
    //if (v->selected_key.is_enlarging == MMI_TRUE)
    {
        if ((x1 - v->x) >= (v->width / 2)) /* we need use right arrow */
        {
            zoom_img = v->keyboard_theme->popup_hint_right_image;
        }
        else /* use left arrow */
        {
            zoom_img = v->keyboard_theme->popup_hint_left_image;
        }

        gdi_image_get_dimension(
            zoom_img,
            &large_icon_width,
            &large_icon_height);
        
        /* caluclate large icon's position */
        if ((x1 - v->x) >= (v->width / 2)) /* we need use right arrow */
        {
            large_icon_x = x1 + GUI_VKBD_LARGE_ICON_ZOOM_ARROW_X_OFFSET -
                           large_icon_width;
            v->selected_key.enlarged_key_x = large_icon_x;
            zoom_img = v->keyboard_theme->popup_hint_right_image;
        }
        else /* use left arrow */
        {
            large_icon_x = x2 - GUI_VKBD_LARGE_ICON_ZOOM_ARROW_X_OFFSET;
            v->selected_key.enlarged_key_x = large_icon_x;
            zoom_img = v->keyboard_theme->popup_hint_left_image;
        }
        large_icon_y = y1 + GUI_VKBD_LARGE_ICON_ZOOM_ARROW_Y_OFFSET - large_icon_height;
            v->selected_key.enlarged_key_width = large_icon_width;
            v->selected_key.enlarged_key_height = large_icon_height;
        
        v->selected_key.enlarged_key_y = large_icon_y;
        v->selected_key.enlarged_bg = zoom_img;

        /* cache */
        cache_buf_size_large_icon = (large_icon_width *
                                     large_icon_height *
                                     (gdi_act_layer->bits_per_pixel)) >> 3;
        MMI_DBG_ASSERT(cache_buf_size_large_icon <= GUI_VKBD_LARGE_ICON_CACHE_SIZE);

        /* stop cursor */
        if (v->hide_cursor_callback != NULL)
        {
            v->is_cursor_stop = v->hide_cursor_callback(
                v->selected_key.enlarged_key_x,
                v->selected_key.enlarged_key_y,
                v->selected_key.enlarged_key_x + v->selected_key.enlarged_key_width - 1,
                v->selected_key.enlarged_key_y + v->selected_key.enlarged_key_height - 1);
        }


    #if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
        if (v->is_venus_vk)
        {
            //vadp_p2v_virtual_keyboard_popup_move();
            //vadp_p2v_start_virtual_keyboard_popup((void*)v);
            //vadp_p2v_redraw_virtual_keyboard_popup((void*)v);
        }
        else
    #endif
        {
            gdi_layer_push_clip();
            gdi_layer_set_clip(
                large_icon_x,
                large_icon_y,
                large_icon_x + large_icon_width - 1,
                large_icon_y + large_icon_height - 1);

            if (cache)
            {
                /* if the buf is not NULL, first free the buffer */
                if (v->selected_key_enlarged_bitmap.buf_ptr != NULL)
                {
                    gdi_image_cache_bmp_draw(
                        large_icon_x,
                        large_icon_y,
                        &v->selected_key_enlarged_bitmap);
                    mmi_frm_scrmem_free(v->selected_key_enlarged_bitmap.buf_ptr);
                    v->selected_key_enlarged_bitmap.buf_ptr = NULL;
                    v->selected_key.is_enlarging = MMI_FALSE;
                }
                v->selected_key_enlarged_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size_large_icon);
                MMI_DBG_ASSERT(v->selected_key_enlarged_bitmap.buf_ptr != NULL);
                gdi_image_cache_bmp_get(
                    large_icon_x,
                    large_icon_y,
                    large_icon_x + large_icon_width - 1,
                    large_icon_y + large_icon_height - 1,
                    &v->selected_key_enlarged_bitmap);
                v->selected_key.is_enlarging = MMI_TRUE;

            }
            
            
            /* if large icon is out of VK background, we need flatten 
             * wallpaper to active layer
             */
            if (v->selected_key.enlarged_key_y < v->y)
            {
                gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
                gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
            }
            gui_virtual_keyboard_show_popup_content(v, large_icon_x, large_icon_y, large_icon_width, large_icon_height, zoom_img);
            gdi_layer_pop_clip();
            gui_BLT_double_buffer(
                x1 < large_icon_x ? x1 : large_icon_x,
                large_icon_y,
                x2 < (large_icon_x + large_icon_width - 1) ? (large_icon_x + large_icon_width - 1) : x2,
                y2);
        }
    }
}
#endif /* __MMI_VK_POPUP_HINT__ */


/***************************************************************************** 
* Global Variable
*****************************************************************************/
UI_virtual_keyboard_theme *current_virtual_keyboard_theme = NULL;

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_current_theme
 * DESCRIPTION
 *  Applies the current theme for virtual keyboard.
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_current_theme(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(current_virtual_keyboard_theme);
    v->keyboard_theme = current_virtual_keyboard_theme;
    v->keyboard_theme->flags |= current_virtual_keyboard_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_theme
 * DESCRIPTION
 *  Applies the current theme for virtual keyboard.
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 *  t       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_theme(virtual_keyboard *v, UI_virtual_keyboard_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(t);
    v->keyboard_theme = t;
    v->keyboard_theme->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_virtual_keyboard
 * DESCRIPTION
 *  Create virtual keyboard object
 * PARAMETERS
 *  v               [IN/OUT]    Is the virtual keyboard object
 *  x               [IN]        Is the left-top cornerd
 *  y               [IN]        Is the left-top cornerd
 *  lang_type       [IN]        Is language type to be used for the keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_virtual_keyboard(virtual_keyboard *v, S16 x, S16 y, gui_virtual_keyboard_language_enum lang_type, MMI_BOOL is_venus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(lang_type);
    v->x = x;
    v->y = y;
    v->width = vk_item->virtual_keyboard_layout->width;
    v->height = vk_item->virtual_keyboard_layout->height;
    v->lang_type = lang_type;
    v->flags = 0;
    v->allowed_characters = NULL;
    v->disp_area_text[0] = (UI_character_type) '\0';
    v->disabled_chars[0] = (UI_character_type) '\0';
    v->disabled_symbols[0] = GUI_VKBD_PEN_NONE;
#if defined(__MMI_VUI_ENGINE__)
    v->is_venus_vk = is_venus;
#endif /* defined(__MMI_VUI_ENGINE__) */
    gui_set_virtual_keyboard_current_theme(v);

    memset(v->dead_key_input, 0, sizeof(v->dead_key_input));

    gui_virtual_keyboard_clear_selected_key(&v->selected_key);
    v->selected_key_cached = MMI_FALSE;
    v->hide_callback = gui_virtual_keyboard_default_hide_function;
    v->display_callback = gui_virtual_keyboard_default_display_callback_function;
#ifdef __MMI_VK_POPUP_HINT__
    v->hide_cursor_callback = gui_virtual_keyboard_dummy_hide_cursor_function;
    v->blink_cursor_callback = UI_dummy_function;
    v->is_cursor_stop = MMI_FALSE;
    if (v->active == MMI_TRUE)
    {
        if (v->selected_key_enlarged_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(v->selected_key_enlarged_bitmap.buf_ptr);
        }
        if (v->selected_key_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(v->selected_key_bitmap.buf_ptr);
        }
    }
    v->selected_key_enlarged_bitmap.buf_ptr = NULL;
    v->selected_key.is_enlarging = MMI_FALSE;
    v->selected_key_bitmap.buf_ptr = NULL;
    v->active = MMI_TRUE;
#else /* __MMI_VK_POPUP_HINT__ */
    v->selected_key_bitmap.buf_ptr = NULL;
#endif /* __MMI_VK_POPUP_HINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_close_virtual_keyboard
 * DESCRIPTION
 *  Release the resource used by virtual keyboard object
 * PARAMETERS
 *  v               [IN/OUT]    Is the virtual keyboard object
 * RETURNS
 *  void
 * REMARKS
 *  Used in exit function or exit category function
 *****************************************************************************/
void gui_close_virtual_keyboard(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VK_POPUP_HINT__
    if (v->active == MMI_TRUE)
    {
        if (v->selected_key_enlarged_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(v->selected_key_enlarged_bitmap.buf_ptr);
            v->selected_key_enlarged_bitmap.buf_ptr = NULL;
            v->selected_key.is_enlarging = MMI_FALSE;
        }
        if (v->selected_key_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(v->selected_key_bitmap.buf_ptr);
            v->selected_key_bitmap.buf_ptr = NULL;
            v->selected_key_cached = MMI_FALSE;
        }
        v->hide_cursor_callback = NULL;
        v->blink_cursor_callback = NULL;
        v->active = MMI_FALSE;
        v->is_cursor_stop = MMI_FALSE;
    }
#endif /* __MMI_VK_POPUP_HINT__ */
}


#ifdef __MMI_VK_POPUP_HINT__
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_hide_cursor_callback
 * DESCRIPTION
 *  Register hide cursor callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the hide cursor callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_hide_cursor_callback(
      virtual_keyboard *v,
      MMI_BOOL (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->hide_cursor_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_blink_cursor_callback
 * DESCRIPTION
 *  Register blink cursor callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the hide cursor callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_blink_cursor_callback(
      virtual_keyboard *v,
      void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->blink_cursor_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_recover_covered_area
 * DESCRIPTION
 *  recover area that popup hint covered
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_recover_covered_area(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        /* 
         *  Because Venus would not cache the popup hint covered area.
         *  Hence, we don't have to recover it.
        */
        return;
    }
#endif

    if (v->key_down_accepted == MMI_TRUE)
    {
        if (v->selected_key.is_enlarging == MMI_TRUE)
        {
            MMI_DBG_ASSERT(v->selected_key_enlarged_bitmap.buf_ptr != NULL);
            gdi_layer_push_clip();
            gdi_layer_set_clip(
                v->selected_key.enlarged_key_x,
                v->selected_key.enlarged_key_y,
                v->selected_key.enlarged_key_x + v->selected_key.enlarged_key_width - 1,
                v->selected_key.enlarged_key_y + v->selected_key.enlarged_key_height - 1);
            if (v->selected_key_enlarged_bitmap.buf_ptr)
            {
                gdi_image_cache_bmp_draw(
                    v->selected_key.enlarged_key_x,
                    v->selected_key.enlarged_key_y,
                    &v->selected_key_enlarged_bitmap);
            }
            gdi_layer_pop_clip();
        }
    }
}

#endif /* __MMI_VK_POPUP_HINT__ */


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_recache
 * DESCRIPTION
 * PARAMETERS
 *  v               [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_recache(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_VK_POPUP_HINT__
    #if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        return;
    }
    #endif

    if (v->key_down_accepted == MMI_TRUE)
    {
        if (gui_virtual_keyboard_need_to_recache == MMI_TRUE)
        {
            /* redo the cache and printing of popup and key */
            gui_virtual_keyboard_cache_and_show_selected_key_for_large_icon(v);
            gui_virtual_keyboard_need_to_recache = MMI_FALSE;
        }
    }
#endif /* __MMI_VK_POPUP_HINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_draw_from_cache
 * DESCRIPTION
 * PARAMETERS
 *  v               [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_draw_from_cache(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_VK_POPUP_HINT__
    gui_virtual_keyboard_need_to_recache = MMI_FALSE;
    if (v->selected_key_cached == MMI_FALSE)
    {
        return;
    }

    #if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        return;
    }
    #endif

    if (v->key_down_accepted == MMI_TRUE)
    {
        if (v->selected_key.is_enlarging == MMI_TRUE)
        {
            gui_virtual_keyboard_need_to_recache = MMI_TRUE;
            /* unselect the previous selected key for large icon */
            gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon(v);
        }
    }
#endif /* __MMI_VK_POPUP_HINT__ */
}

/*****************************************************************************
 * FUNCTION
 *  gui_move_virtual_keyboard
 * DESCRIPTION
 *  Move the virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  x       [IN]        Is the left-top cornerd
 *  y       [IN]        Is the left-top cornerd
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_virtual_keyboard(virtual_keyboard *v, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_virtual_keyboard
 * DESCRIPTION
 *  Show the virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_virtual_keyboard(virtual_keyboard *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    S32 glyph_width, glyph_height;
    UI_character_type key_char;
    S16 key_width, key_height;
    S16 key_x, key_y;
    const gui_keyboard_layout_struct *layout;
    const gui_keyboard_language_struct *lang;
    S16 i, j, k;
    BOOL enable_dead_key;
    gdi_handle old_src_layer,act_layer;
    gui_keyboard_lang_map_struct_p vk_item;
    U8 *dynamic_content = NULL;
    S16 dynamic_content_x;
    gui_vkbd_display_callback_type_enum flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    x1 = v->x;
    y1 = v->y;
    x2 = v->x + v->width - 1;
    y2 = v->y + v->height - 1;

    layout = vk_item->virtual_keyboard_layout;
    lang = vk_item->virtual_keyboard_language;

    enable_dead_key = lang->enable_dead_key;

#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
#if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
#endif        
    {
    if (!wgui_is_wallpaper_on_bottom())
    {
        gdi_get_alpha_blending_source_layer(&old_src_layer);
        gdi_layer_get_active(&act_layer);
        gdi_set_alpha_blending_source_layer(act_layer);
    }
    }
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 

    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);

    if (v->hide_callback != NULL)
    {
        v->hide_callback(x1, y1, x2, y2);
    }

    gui_show_image(x1, y1, (PU8) get_image(layout->ImageId));

    for (k = 0; k < layout->n_matrix_key_layout; k++)
    {
        S16 horizontal_text_gap, vertical_text_gap;
        S16 n_matrix_column, n_matrix_row;
        const gui_matrix_key_layout_struct *matrix;
        const UI_character_type *matrix_string;

        matrix = &layout->matrix_layout[k];
        horizontal_text_gap = matrix->horizontal_key_gap;
        vertical_text_gap = matrix->vertical_key_gap;

        n_matrix_column = matrix->n_columns;
        n_matrix_row = matrix->n_rows;

        key_x = v->x + matrix->x;
        key_y = v->y + matrix->y;
        key_width = matrix->key_width;
        key_height = matrix->key_height;

        gui_set_font(v->keyboard_theme->text_font);
        gui_set_text_color(v->keyboard_theme->key_up_text_color);

        for (i = 0; i < n_matrix_row; i++)
        {
            matrix_string = lang->matrix_string[i];
            for (j = 0; j < n_matrix_column; j++)
            {
                BOOL restore_text_color = MMI_FALSE;

                key_char = matrix_string[j];
                if (enable_dead_key && gui_virtual_keyboard_check_dead_key(v, key_char))
                {
                    gui_set_text_color(v->keyboard_theme->dead_key_up_text_color);
                    restore_text_color = MMI_TRUE;
                }
                if (gui_virtual_keyboard_is_key_disabled(v, GUI_VKBD_PEN_CHAR_I, key_char))
                {
                #if defined(__MMI_MAINLCD_320X480__)
                    gdi_draw_round_rect(
                        key_x + 1,
                        key_y + 1,
                        key_x + key_width - 1,
                        key_y + key_height - 1,
                        gdi_act_color_from_rgb(
                            150,
                            v->keyboard_theme->key_disable_bg_color.r,
                            v->keyboard_theme->key_disable_bg_color.g,
                            v->keyboard_theme->key_disable_bg_color.b),
                        gdi_act_color_from_rgb(
                            255,
                            v->keyboard_theme->key_disable_bg_color.r,
                            v->keyboard_theme->key_disable_bg_color.g,
                            v->keyboard_theme->key_disable_bg_color.b),
                            1);
                #else /* __MMI_MAINLCD_320X480__ */
                    gdi_effect_alpha_blending_rect(
                        (gdi_handle)gdi_act_layer, 
                        key_x + 1,
                        key_y + 1,
                        key_x + key_width - 2,
                        key_y + key_height - 2,
                        150,
                        v->keyboard_theme->key_disable_bg_color.r,
                        v->keyboard_theme->key_disable_bg_color.g,
                        v->keyboard_theme->key_disable_bg_color.b);
                #endif /* __MMI_MAINLCD_320X480__ */
                    gui_set_text_color(v->keyboard_theme->key_disable_text_color);
                    restore_text_color = MMI_TRUE;
                }
                gui_virtual_keyboard_show_char_center_align(
                    key_char,
                    key_x + GUI_VKBD_KEY_TEXT_OFFSET,
                    key_y,
                    key_width - 2 * GUI_VKBD_KEY_TEXT_OFFSET,
                    key_height,
                    &glyph_width,
                    &glyph_height,
                    v->keyboard_theme->text_font);
                if (restore_text_color)
                {
                    gui_set_text_color(v->keyboard_theme->key_up_text_color);
                }
                key_x += horizontal_text_gap + key_width;
            }
            key_x = v->x + matrix->x;
            key_y += vertical_text_gap + key_height;
        }
    }

    for (i = 0; i < layout->n_custom_keys; i++)
    {
        PU8 custom_image;

        key_x = v->x + layout->custom_keys[i].x;
        key_y = v->y + layout->custom_keys[i].y;
        key_width = layout->custom_keys[i].key_width;
        key_height = layout->custom_keys[i].key_height;
        key_char = lang->custom_string[i];

        if (lang->custom_key_type[i] == GUI_VKBD_PEN_DISPLAY_AREA)
        {
            gui_set_text_color(v->keyboard_theme->disp_area_text_color);
            gui_measure_string((UI_string_type) v->disp_area_text, &glyph_width, &glyph_height);
            if (mmi_fe_get_r2l_state())
	    {
	        gui_move_text_cursor(
		    key_x + key_width - 1 - VKBD_DIFF_HALF(key_width, glyph_width),
		    key_y + VKBD_DIFF_HALF(key_height, glyph_height));
	    }	
	    else
	    {
                gui_move_text_cursor(
                    key_x + VKBD_DIFF_HALF(key_width, glyph_width),
                    key_y + VKBD_DIFF_HALF(key_height, glyph_height));
	    }	
            gui_print_text((UI_string_type) v->disp_area_text);

            /* Restore text color */
            gui_set_text_color(v->keyboard_theme->key_up_text_color);
        }
        else if (lang->custom_key_type[i] == GUI_VKBD_PEN_DISPLAY_CALLBACK)
        {
            if (v->display_callback != NULL)
            {
                v->display_callback(&flag, &dynamic_content);
            }
            if (dynamic_content != NULL)
            {
            
                if (gui_virtual_keyboard_is_key_disabled(v, lang->custom_key_type[i], key_char))
                {
                 #if defined(__MMI_MAINLCD_320X480__)
                     gdi_draw_round_rect(
                         key_x + 1,
                         key_y + 1,
                         key_x + key_width - 1,
                         key_y + key_height - 1,
                         gdi_act_color_from_rgb(
                              150,
                              v->keyboard_theme->key_disable_bg_color.r,
                              v->keyboard_theme->key_disable_bg_color.g,
                              v->keyboard_theme->key_disable_bg_color.b),
                          gdi_act_color_from_rgb(
                              255,
                              v->keyboard_theme->key_disable_bg_color.r,
                              v->keyboard_theme->key_disable_bg_color.g,
                              v->keyboard_theme->key_disable_bg_color.b),
                              1);
                #else /* __MMI_MAINLCD_320X480__ */
                    gdi_effect_alpha_blending_rect(
                        (gdi_handle)gdi_act_layer, 
                        key_x + 1,
                        key_y + 1,
                        key_x + key_width - 2,
                        key_y + key_height - 2,
                        150,
                        v->keyboard_theme->key_disable_bg_color.r,
                        v->keyboard_theme->key_disable_bg_color.g,
                        v->keyboard_theme->key_disable_bg_color.b);
                 #endif /* __MMI_MAINLCD_320X480__ */
                }
                if (flag == GUI_VKBD_DISPLAY_CALLBACK_IMG)
                {
                    gdi_image_get_dimension(dynamic_content, &glyph_width, &glyph_height);
                    gui_virtual_keyboard_show_image(
                        v, 
                        key_x + VKBD_DIFF_HALF(key_width, glyph_width),
                        key_y + VKBD_DIFF_HALF(key_height, glyph_height),
                        dynamic_content,
                        (gdi_handle)gdi_act_layer);                                                            
                }
                if (flag == GUI_VKBD_DISPLAY_CALLBACK_TEXT)
                {
                    gui_measure_string((UI_string_type)dynamic_content, &glyph_width, &glyph_height);
                    dynamic_content_x = key_x + ((key_width - glyph_width) >> 1);
                    if (mmi_fe_get_r2l_state())
                    {
                        dynamic_content_x += glyph_width;
                    }        
                    gui_move_text_cursor(dynamic_content_x, key_y + VKBD_DIFF_HALF(key_height, glyph_height));
                #if defined(__MMI_VUI_ENGINE__)
                    if (v->is_venus_vk)
                    {
                        gui_print_text((UI_string_type)dynamic_content);
                    }
                    else
                #endif
                    {
                    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
                    gui_print_text((UI_string_type)dynamic_content);
                    gdi_pop_and_restore_alpha_blending_source_layer();
                }
            }
        }
        }
        else if (!key_char)
        {
            custom_image = get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[i]));
            gui_measure_image(custom_image, &glyph_width, &glyph_height);

            if (gui_virtual_keyboard_is_key_disabled(v, lang->custom_key_type[i], key_char))
            {
            #if defined(__MMI_MAINLCD_320X480__)
                    gdi_draw_round_rect(
                        key_x + 1,
                        key_y + 1,
                        key_x + key_width - 1,
                        key_y + key_height - 1,
                        gdi_act_color_from_rgb(
                            150,
                            v->keyboard_theme->key_disable_bg_color.r,
                            v->keyboard_theme->key_disable_bg_color.g,
                            v->keyboard_theme->key_disable_bg_color.b),
                        gdi_act_color_from_rgb(
                            255,
                            v->keyboard_theme->key_disable_bg_color.r,
                            v->keyboard_theme->key_disable_bg_color.g,
                            v->keyboard_theme->key_disable_bg_color.b),
                            1);
            #else /* __MMI_MAINLCD_320X480__ */
                gdi_effect_alpha_blending_rect(
                    (gdi_handle)gdi_act_layer, 
                    key_x + 1,
                    key_y + 1,
                    key_x + key_width - 2,
                    key_y + key_height - 2,
                    150,
                    v->keyboard_theme->key_disable_bg_color.r,
                    v->keyboard_theme->key_disable_bg_color.g,
                    v->keyboard_theme->key_disable_bg_color.b);
            #endif /* __MMI_MAINLCD_320X480__ */
            }
            gui_virtual_keyboard_show_image(
                v, 
                key_x + VKBD_DIFF_HALF(key_width, glyph_width),
                key_y + VKBD_DIFF_HALF(key_height, glyph_height),
                custom_image,
                (gdi_handle)gdi_act_layer);
        }
        else
        {
            BOOL restore_text_color = MMI_FALSE;

            if (enable_dead_key && gui_virtual_keyboard_check_dead_key(v, key_char))
            {
                gui_set_text_color(v->keyboard_theme->dead_key_up_text_color);
                restore_text_color = MMI_TRUE;
            }

            if (gui_virtual_keyboard_is_key_disabled(v, lang->custom_key_type[i], key_char))
            {
            #if defined(__MMI_MAINLCD_320X480__)
                    gdi_draw_round_rect(
                        key_x + 1,
                        key_y + 1,
                        key_x + key_width - 1,
                        key_y + key_height - 1,
                        gdi_act_color_from_rgb(
                            150,
                            v->keyboard_theme->key_disable_bg_color.r,
                            v->keyboard_theme->key_disable_bg_color.g,
                            v->keyboard_theme->key_disable_bg_color.b),
                        gdi_act_color_from_rgb(
                            255,
                            v->keyboard_theme->key_disable_bg_color.r,
                            v->keyboard_theme->key_disable_bg_color.g,
                            v->keyboard_theme->key_disable_bg_color.b),
                            1);
            #else /* __MMI_MAINLCD_320X480__ */
                gdi_effect_alpha_blending_rect(
                    (gdi_handle)gdi_act_layer, 
                    key_x + 1,
                    key_y + 1,
                    key_x + key_width - 2,
                    key_y + key_height - 2,
                    150,
                    v->keyboard_theme->key_disable_bg_color.r,
                    v->keyboard_theme->key_disable_bg_color.g,
                    v->keyboard_theme->key_disable_bg_color.b);
            #endif /* __MMI_MAINLCD_320X480__ */
                gui_set_text_color(v->keyboard_theme->key_disable_text_color);
                restore_text_color = MMI_TRUE;
            }

            gui_virtual_keyboard_show_char_center_align(
                key_char,
                key_x + GUI_VKBD_KEY_TEXT_OFFSET,
                key_y,
                key_width - 2 * GUI_VKBD_KEY_TEXT_OFFSET,
                key_height,
                &glyph_width,
                &glyph_height,
                v->keyboard_theme->text_font);
            if (restore_text_color)
            {
                gui_set_text_color(v->keyboard_theme->key_up_text_color);
            }
        }
    }

    if (v->key_down_accepted == MMI_TRUE)
    {
        gui_virtual_keyboard_show_selected_key(v);
    }

    gui_pop_clip();
    gui_pop_text_clip();
    
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
#if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
#endif
    {
    if (!wgui_is_wallpaper_on_bottom())
    {
        gdi_set_alpha_blending_source_layer(old_src_layer);
    }
    }
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_display_area
 * DESCRIPTION
 *  Update text displayed on display area
 * PARAMETERS
 *  v           [IN/OUT]        
 *  string      [IN]        String to be displayed in display area
 *  redraw      [IN]        Whether to redraw the keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_display_area(virtual_keyboard *v, const U8 *string, BOOL redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_layout_struct *layout;
    const gui_keyboard_language_struct *lang;
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0, glyph_width, glyph_height;
    S32 i;
    gdi_handle abm_src_layer, act_layer;

    gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vk_item = wgui_get_virtual_keyboard(v->lang_type);
    gdi_get_alpha_blending_source_layer(&abm_src_layer);
    gdi_layer_get_active(&act_layer);
    mmi_ucs2ncpy((S8*) v->disp_area_text, (const S8*)string, MMI_VKBD_MAX_DISPLAY_AREA_TEXT_LEN);

    /* redraw the area only */
    if (redraw)
    {
        layout = vk_item->virtual_keyboard_layout;
        lang = vk_item->virtual_keyboard_language;

        gui_set_font(v->keyboard_theme->text_font);
        for (i = 0; i < layout->n_custom_keys; i++)
        {
            if (lang->custom_key_type[i] == GUI_VKBD_PEN_DISPLAY_AREA)
            {
                const gui_custom_key_layout_struct *custom_key = &layout->custom_keys[i];

                x1 = v->x + custom_key->x;
                y1 = v->y + custom_key->y;
                x2 = x1 + custom_key->key_width - 1;
                y2 = y1 + custom_key->key_height - 1;

                gui_lock_double_buffer();
                gui_push_clip();
                gui_push_text_clip();
                gui_set_clip(x1, y1, x2, y2);
                gui_set_text_clip(x1, y1, x2, y2);

                if (abm_src_layer ==  act_layer)
                {
                    if (v->hide_callback != NULL)
                    {
                        v->hide_callback(x1, y1, x2, y2);
                    }
                }

                gui_show_image(x1, y1, get_image(gui_virtual_keyboard_convert_custom_img(v, lang->custom_key_image[i])));
                gui_set_text_color(v->keyboard_theme->disp_area_text_color);
                gui_measure_string((UI_string_type) v->disp_area_text, &glyph_width, &glyph_height);
                gui_move_text_cursor(
                    x1 + VKBD_DIFF_HALF(custom_key->key_width, glyph_width),
                    y1 + VKBD_DIFF_HALF(custom_key->key_height, glyph_height));
                gui_print_text((UI_string_type) v->disp_area_text);

                gui_pop_clip();
                gui_pop_text_clip();
                gui_unlock_double_buffer();
                gui_BLT_double_buffer(x1, y1, x2, y2);

                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_multi_block_mode
 * DESCRIPTION
 *  Enter or leave multi-block handwriting mode. 
 *
 *  In multi-block handwriting mode, some keyboard icons are displayed differently.
 * PARAMETERS
 *  v           [IN/OUT]        
 *  enabled     [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_multi_block_mode(virtual_keyboard *v, MMI_BOOL enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enabled)
    {
        v->flags |= GUI_VKBD_FLAG_MULTI_BLOCK_MODE;
    }
    else
    {
        v->flags &= ~GUI_VKBD_FLAG_MULTI_BLOCK_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_keyboard_allowed_characters
 * DESCRIPTION
 *  Only the allowd characters can be input on keyboard.
 *  This function and gui_set_virtual_board_disable_list() are mutually-exclusive.
 *  
 *  Control keys such as GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_SHOW... are enabled because
 *  they are not related to character insertion.
 *  
 *  `allowed_characters' may contain '-' for consecutive characters
 *  (Ex. 'a-z' for characters from a to z.)
 *  If we want to accept "-", please write it as '\-'.
 *  For example, '\-0-9.' represents "-0123456789."
 *  
 *  Example of valid characters in email addresss:
 *  wgui_set_virtual_keyboard_allowed_characters((const UI_character_type *) L"+_\\-.@A-Za-z0-9");
 *  (it is not a complete list of all characters allowed in RFC, but it satisfies almost all cases)
 * PARAMETERS
 *  v                   [IN/OUT]    Virtual keyboard
 *  allowed_chars       [IN]        Allowed characters
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_keyboard_allowed_characters(virtual_keyboard *v, const UI_character_type *allowed_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->allowed_characters = allowed_chars;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_virtual_board_disable_list
 * DESCRIPTION
 *  Disable some keys on keyboard.
 *  This function and gui_set_virtual_keyboard_allowed_characters() are mutually-exclusive.
 * PARAMETERS
 *  v                       [IN/OUT]    Virtual keyboard
 *  disabled_chars          [IN]        Null-terminated array of disabled unicode characters
 *  disabled_symbols        [IN]        Ended by GUI_VKBD_PEN_NONE
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_virtual_board_disable_list(
        virtual_keyboard *v,
        const UI_character_type *disabled_chars,
        const gui_virtual_keyboard_pen_enum *disabled_symbols)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setup v->disabled_chars[] */
    for (i = 0; i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
    {
        if (!disabled_chars[i])
        {
            break;
        }

        v->disabled_chars[i] = disabled_chars[i];
    }

    MMI_DBG_ASSERT(i < MMI_VKBD_MAX_DISABLED_KEYS || !disabled_chars[i]);
    v->disabled_chars[i] = 0;

    /* Setup v->disabled_symbols[] */
    for (i = 0; i < MMI_VKBD_MAX_DISABLED_KEYS; i++)
    {
        if (disabled_symbols[i] == GUI_VKBD_PEN_NONE)
        {
            break;
        }

        v->disabled_symbols[i] = disabled_symbols[i];
    }

    MMI_DBG_ASSERT(i < MMI_VKBD_MAX_DISABLED_KEYS || (disabled_symbols[i] == GUI_VKBD_PEN_NONE));
    v->disabled_symbols[i] = GUI_VKBD_PEN_NONE;
}



/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v               [IN/OUT]         
 *  x               [IN]        
 *  y               [IN]        
 *  pen_event       [IN]        
 *  vkbd_event      [OUT]         
 *  vkbd_param      [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_virtual_keyboard_translate_pen_event(
        virtual_keyboard *v,
        S16 x,
        S16 y,
        mmi_pen_event_type_enum pen_event,
        gui_virtual_keyboard_pen_enum *vkbd_event,
        gui_pen_event_param_struct *vkbd_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    // const gui_keyboard_language_struct *lang;
    UI_character_type ch;
    gui_virtual_keyboard_pen_enum evt;
   // gui_keyboard_lang_map_struct_p vk_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // vk_item = wgui_get_virtual_keyboard(v->lang_type);
    *vkbd_event = GUI_VKBD_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(vkbd_param);

   // lang = vk_item->virtual_keyboard_language;

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            v->key_down_accepted = MMI_FALSE;

            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
            {
                if (gui_virtual_keyboard_translate_pen_position(v, x, y, &v->selected_key))
                {
                   gui_virtual_keyboard_get_selected_key(v, &v->selected_key, &ch, &evt);
                   if ((evt == GUI_VKBD_PEN_NONE) || gui_virtual_keyboard_is_key_disabled(v, evt, ch))
                   {
                       /* Do nothing */
                   }
                   else
                   {
                        v->key_down_accepted = MMI_TRUE;

                    #ifdef __MMI_VK_POPUP_HINT__
                        gui_virtual_keyboard_cache_and_show_selected_key_for_large_icon(v);
                    #else
                        gui_virtual_keyboard_cache_and_show_selected_key(v);
                    #endif
                        /* 
                         * If Pen Down and Pen Up comes together, we should temporarily suspend MMI task. 
                         * Otherwise, user can not see pen down due to delayed LCM update.
                         */
                        kal_sleep_task(kal_milli_secs_to_ticks(30));
                    }
                }
            }
            else
            {
                return MMI_FALSE;
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (v->key_down_accepted)
            {
                virtual_keyboard_selection_struct s;
            #ifdef __MMI_VK_POPUP_HINT__
                if (v->selected_key.is_enlarging == MMI_TRUE &&
                    PEN_CHECK_BOUND(
                        x,
                        y,
                        v->selected_key.key_x,
                        v->selected_key.key_y,
                        v->selected_key.key_width,
                        v->selected_key.key_height))
                {
                    /* if is in enlarged icon, do nothing */
                    break;
                }
                else
                {
                    if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) &&
                        gui_virtual_keyboard_translate_pen_position(v, x, y, &s))
                    {
                        if (memcmp(&v->selected_key, &s, sizeof(s)))
                        {
                            #if defined(__MMI_VUI_ENGINE__)
                            if (!v->is_venus_vk)
                            #endif
                            {
                                gui_lock_double_buffer();
                            }
                            
                            gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon(v);
                            memcpy(&v->selected_key, &s, sizeof(s));
                            gui_virtual_keyboard_get_selected_key(v, &v->selected_key, &ch, &evt);
                            if (!((evt == GUI_VKBD_PEN_NONE) ||
                                  gui_virtual_keyboard_is_key_disabled(v, evt, ch)))
                            {
                                gui_virtual_keyboard_cache_and_show_selected_key_for_large_icon(v);
                            }
                            
                            #if defined(__MMI_VUI_ENGINE__)
                            if (!v->is_venus_vk)
                            #endif
                            {
                                gui_unlock_double_buffer();
                            }
                        }
                    }
                    else
                    {
                        gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon(v);
                        gui_virtual_keyboard_clear_selected_key(&v->selected_key);
                    }
                }
            #else /* __MMI_VK_POPUP_HINT__ */                    
                if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) &&
                    gui_virtual_keyboard_translate_pen_position(v, x, y, &s))
                {
                    if (memcmp(&v->selected_key, &s, sizeof(s)))
                    {
                        gui_virtual_keyboard_show_unselect_key_from_cache(v);
                        memcpy(&v->selected_key, &s, sizeof(s));
                        gui_virtual_keyboard_get_selected_key(v, &v->selected_key, &ch, &evt);
                        if (!((evt == GUI_VKBD_PEN_NONE) ||
                            gui_virtual_keyboard_is_key_disabled(v, evt, ch)))
                        {
                            gui_virtual_keyboard_cache_and_show_selected_key(v);
                        }
                    }
                }
                else
                {
                    gui_virtual_keyboard_show_unselect_key_from_cache(v);
                    gui_virtual_keyboard_clear_selected_key(&v->selected_key);
                }
            #endif /* __MMI_VK_POPUP_HINT__ */
            }

            break;

        case MMI_PEN_EVENT_UP:
            if (v->key_down_accepted)
            {
            #ifdef __MMI_VK_POPUP_HINT__
                gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon(v);
            #else /* __MMI_VK_POPUP_HINT__ */
                gui_virtual_keyboard_show_unselect_key_from_cache(v);
            #endif /* __MMI_VK_POPUP_HINT__ */

                if (gui_virtual_keyboard_get_selected_key(v, &v->selected_key, &ch, &evt))
                {
                    if (gui_virtual_keyboard_is_key_disabled(v, evt, ch))
                    {
                        /*Do nothing*/
                    }
                    else
                    {
                        gui_virtual_keyboard_translate_dead_key(v, &ch, &evt);

                        if (evt == GUI_VKBD_PEN_SPACE)
                        {
                            evt = GUI_VKBD_PEN_CHAR_I;
                            ch = (UI_character_type) ' ';
                        }
                        else if (evt == GUI_VKBD_PEN_DEAD_KEY)
                        {
                            evt = GUI_VKBD_PEN_NONE;
                        }
                        *vkbd_event = evt;
                        if (evt == GUI_VKBD_PEN_CHAR_I)
                        {
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(vkbd_param, (int)ch);
                        }
                    }
                }
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            #ifdef __MMI_VK_POPUP_HINT__
                gui_virtual_keyboard_show_unselect_key_from_cache_for_large_icon(v);
            #else /* __MMI_VK_POPUP_HINT__ */
                gui_virtual_keyboard_show_unselect_key_from_cache(v);
            #endif /* __MMI_VK_POPUP_HINT__ */
            gui_virtual_keyboard_clear_dead_key(v);
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            if (v->key_down_accepted)
            {
                if (gui_virtual_keyboard_get_selected_key(v, &v->selected_key, &ch, &evt))
                {
                    if (gui_virtual_keyboard_is_key_disabled(v, evt, ch))
                    {
                        /*Do nothing*/
                    }
                    else
                    {
                        if (evt == GUI_VKBD_PEN_SPACE)
                        {
                            evt = GUI_VKBD_PEN_CHAR_I;
                            ch = (UI_character_type) ' ';
                        }
                        else if (evt == GUI_VKBD_PEN_DEAD_KEY)
                        {
                            evt = GUI_VKBD_PEN_NONE;
                        }

                        *vkbd_event = evt;
                        if (evt == GUI_VKBD_PEN_CHAR_I)
                        {
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(vkbd_param, (int)ch);
                        }
                    }
                }
            }
            break;

        case MMI_PEN_EVENT_REPEAT:
			if (v->key_down_accepted)
			{
			   if (gui_virtual_keyboard_get_selected_key(v, &v->selected_key, &ch, &evt))
				{
				   if (gui_virtual_keyboard_is_key_disabled(v, evt, ch))
					{
						/*Do nothing*/
					}
					else
					{
						if (evt == GUI_VKBD_PEN_BAKSPACE)
						{
							*vkbd_event = evt ;
						}
						else
						{
							/*Do Nothing*/
						}
					}
			   }
			}
			break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_current_character
 * DESCRIPTION
 *  This API is only provided for category to get character before IME.
 *  It will only return that character of pen's position
 * PARAMETERS
 *  v               [IN/OUT]         
 *  x               [IN]        
 *  y               [IN]        
 *  ch              [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_virtual_keyboard_get_current_character(
          virtual_keyboard *v,
          S16 x,
          S16 y,
          UI_character_type *ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_keyboard_language_struct *lang;
    gui_keyboard_lang_map_struct_p vk_item;
    virtual_keyboard_selection_struct s;
    UI_character_type temp;
    gui_virtual_keyboard_pen_enum evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
    {
        if (MMI_TRUE == gui_virtual_keyboard_translate_pen_position(v, x, y, &s))
        {
            vk_item = wgui_get_virtual_keyboard(v->lang_type);
            lang = vk_item->virtual_keyboard_language;
            gui_virtual_keyboard_get_selected_key(v, &s, &temp, &evt);
            if (!((evt == GUI_VKBD_PEN_NONE) || gui_virtual_keyboard_is_key_disabled(v, evt, temp)))
            {
                if (s.custom_key_index >= 0 && lang->custom_key_type[s.custom_key_index] == GUI_VKBD_PEN_DISPLAY_AREA)
                {
                    return MMI_FALSE;
                }

                if (s.matrix_index >= 0)
                {
                    *ch = lang->matrix_string[s.matrix_row][s.matrix_column];
                    return MMI_TRUE;
                }
                else if (s.custom_key_index >= 0 && lang->custom_string[s.custom_key_index])
                {
                    *ch = lang->custom_string[s.custom_key_index];
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_hide_callback
 * DESCRIPTION
 *  Register hide callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the hide callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_hide_callback(
      virtual_keyboard *v,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        v->hide_callback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_display_callback
 * DESCRIPTION
 *  Register display callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the display callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_display_callback(
      virtual_keyboard *v,
      void (*f) (gui_vkbd_display_callback_type_enum *flag, PU8 *text))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->display_callback = f;
}

#endif /* defined(__MMI_TOUCH_SCREEN__) */

#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__ */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
/*****************************************************************************
 * Following code is for VK V2
 ****************************************************************************/

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
/********************************************************************************
* Filename:
* ---------
*	gui_virtual_keyboard.c
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	Virtual Keyboard - UI Component
*
* Version:
* ------------
*	Helena Li (mbj07028)
*
*******************************************************************************/
/******************************************************************************
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
*******************************************************************************/
/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "gui_virtual_keyboard.h"
#include "wgui_categories_util.h"
#include "gui_font_size.h"
#include "math.h"
#include "gui_virtual_keyboard_misc_res.h"
#include "Gui_touch_feedback.h"
#if defined(__MMI_INDIC_VK__)
#include  "IndicEngineGprot.h"
#endif 
#include "imc.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define GUI_VK_CHAR_MASK        0xffff
#define GUI_VK_GET_KEY_CHAR(x)  ((x) >GUI_VK_CHAR_MASK? 0:  (x))
#define GUI_VK_GET_KEY_EVENT(x) ((x) >GUI_VK_CHAR_MASK? (x) :  0)
#define GUI_VK_LONG_TAP_TIMER   600

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define GUI_VK_POPUP_ICON_MIN_WIDTH 58
    #define GUI_VK_POPUP_ICON_MIN_HEIGHT 58
#elif defined(__MMI_MAINLCD_320X480__)
    #define GUI_VK_POPUP_ICON_MIN_WIDTH 66
    #define GUI_VK_POPUP_ICON_MIN_HEIGHT 66
#elif defined(__MMI_MAINLCD_480X800__)
    #define GUI_VK_POPUP_ICON_MIN_WIDTH 88
    #define GUI_VK_POPUP_ICON_MIN_HEIGHT 88
#else
    #error "non supported lcd resolution"
#endif
static MMI_BOOL is_backspace_down_state = MMI_FALSE ;
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static gui_virtual_keyboard_get_vk_callback_func_ptr gui_get_virtual_keyboard_callback;
static MMI_BOOL gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
static gui_virtual_keyboard_need_to_recache = MMI_FALSE;
extern MMI_BOOL need_to_emit_signal;
/***************************************************************************** 
* Local Function
*****************************************************************************/
#ifdef __MMI_VK_POPUP_HINT__
static MMI_BOOL gui_virtual_keyboard_hide_cursor_dummy_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2);
#endif /* __MMI_VK_POPUP_HINT__ */
extern void gui_vk_longtap_timer_handler(void);
static void gui_virtual_keyboard_clear_selected_key(
             gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_draw_key(
             gui_virtual_keyboard_struct *v,
             U16 index);
static void gui_virtual_keyboard_default_hide_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2);
static void gui_virtual_keyboard_default_display_callback_function(
             gui_virtual_keyboard_pen_enum pen_symbol,
             gui_virtual_keyboard_display_callback_type_enum *flag,
             PU8 *text,
             PU8 *image, 
             gui_virtual_keyboard_key_state_enum key_state);
static void gui_virtual_keyboard_show_content_by_align(
            gui_virtual_keyboard_struct *v,
             UI_character_type ch,
             PU8 text,
             PU8 image,
             S32 key_x,
             S32 key_y,
             S32 key_width,
             S32 key_height,
             S32 *glyph_width,
             S32 *glyph_height,
             gui_virtual_keyboard_text_align_enum align);
static MMI_BOOL gui_virtual_keyboard_is_disabled_key(
                 gui_virtual_keyboard_struct *v,
                    U16 index);
static MMI_BOOL gui_virtual_keyboard_is_kept_down_key(
                 gui_virtual_keyboard_struct *v,
                    U16 index);
static MMI_BOOL gui_virtual_keyboard_is_selected_key(
                 gui_virtual_keyboard_struct *v,
                 U16 index);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
static MMI_BOOL gui_virtual_keyboard_translate_pen_position(
                 gui_virtual_keyboard_struct *v,
                 S16 x,
                 S16 y,
                 S16 *index);
static MMI_BOOL gui_virtual_keyboard_get_selected_key(
                 gui_virtual_keyboard_struct *v,
                 S16 index,
                 UI_character_type *key_char,
                 gui_virtual_keyboard_pen_enum *key_event);
static void gui_virtual_keyboard_redraw_popup_hint(
             gui_virtual_keyboard_struct *v,
             MMI_BOOL cache);
static void gui_virtual_keyboard_draw_key_shape(
             gui_virtual_keyboard_struct *v,
             S32 x,
             S32 y,
             S32 width,
             S32 height,
             color frame_color,
             color fill_color);
#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_480X800__)
static color gui_virtual_keyboard_get_gradient_color(
              color src_color,
              S16 value,
              S16 start_value,
              S16 end_value,
              MMI_BOOL is_ascend);
#endif 
/* 
static U8 gui_virtual_keyboard_get_num_of_popup_characters(
            gui_virtual_keyboard_struct *v); */ 

static void gui_virtual_keyboard_show_unselect_key_from_cache(
                gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_cache_and_show_selected_key(
                gui_virtual_keyboard_struct *v);

MMI_BOOL gui_virtual_keyboard_Check_alphanumeric_vk_0_to_9_key(
          gui_virtual_keyboard_struct *v,
          S16 x,
          S16 y);				

#ifdef __MMI_VK_POPUP_HINT__
static void gui_virtual_keyboard_clear_normal_popup_from_cache(
             gui_virtual_keyboard_struct *v);

#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
static void gui_virtual_keyboard_handle_long_tap_popup(
            gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_cache_and_show_longtap_popup(
             gui_virtual_keyboard_struct *v);
static MMI_BOOL gui_virtual_keyboard_initilize_longtap_popup_hint(
            gui_virtual_keyboard_struct *v);
/* 
static void gui_virtual_keyboard_handle_highlighter_on_longtap_popup_at_index(
             gui_virtual_keyboard_struct *v, 
             S16 index,
             MMI_BOOL cache);
*/ 
/* 
static gui_virtual_keyboard_key_struct_p 
            gui_virtual_keyboard_get_lontap_popup_char_at_index(
             gui_virtual_keyboard_struct *v, 
             S16 higlited_index); */ 
static U8 gui_virtual_keyboard_get_num_of_popup_chars(
            gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_set_long_tap_popup_deactive(
                gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_set_long_tap_popup_active(
                gui_virtual_keyboard_struct *v);
/* static void gui_virtual_keyboard_deactivate_highlighter_on_longtap_popup(
             gui_virtual_keyboard_struct *v); */ 
static void gui_virtual_keyboard_print_longtap_popup_characters(
             gui_virtual_keyboard_struct *v);
static S16 gui_virtual_keyboard_get_longtap_popup_index_for_highlighling(
            gui_virtual_keyboard_struct *v, 
            S16 x, 
            S16 y);
static void gui_virtual_keyboard_longtap_popup_translate_pen_event(
            gui_virtual_keyboard_struct *v, 
            S16 x, 
            S16 y,
            mmi_pen_event_type_enum pen_event);
/* static S16 gui_virtual_keyboard_get_longtap_popup_actaual_key_index(
            gui_virtual_keyboard_struct *v,
            S16 highlight_index); */ 
#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */


#endif /* __MMI_VK_POPUP_HINT__ */

#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_480X800__)
/***************************************************************************** 
 * FUNCTION
 *  gui_virtual_keyboard_get_gradient_color
 * DESCRIPTION
 *  Get the gradient color of a given value
 * PARAMETERS
 *  src_color       [IN] source color
 *  value           [IN] value that want to calculate the gradient color
 *  start_value     [IN] the start value of color range
 *  end_value       [IN] the end value of color range
 *  is_ascend       [IN] is ascend or decend
 * RETURNS
 *  color
 *****************************************************************************/
static color gui_virtual_keyboard_get_gradient_color(
              color src_color,
              S16 value,
              S16 start_value,
              S16 end_value,
              MMI_BOOL is_ascend)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color temp_color;
    S16 temp_alpha;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_color = src_color;
    temp_alpha = GUI_VIRTUAL_KEYBOARD_GRADIENT_ALPHA_PERCENT * 255 / 100;

    if (is_ascend == MMI_TRUE)
    {
        if (src_color.alpha + temp_alpha > 255)
        {
            temp_alpha = 255 - src_color.alpha;
        }
        temp_color.alpha = (float)(value - start_value) * temp_alpha / (end_value - start_value) + src_color.alpha;        
    }
    else
    {
        if (src_color.alpha < temp_alpha)
        {
            temp_alpha = src_color.alpha;
        }
        temp_color.alpha = src_color.alpha -
                           (float)(value - start_value) * temp_alpha / (end_value - start_value);
    }

    return temp_color;
}

#endif 


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
__inline static gui_virtual_keyboard_show_image(gui_virtual_keyboard_struct* v, S32 x, S32 y, PU8 img, gdi_handle source_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if ((v->is_venus_vk))
    {
        gdi_image_draw_blend2layers(x, y, img);
    }
    else
#endif 
    {
        gdi_push_and_set_alpha_blending_source_layer(source_layer);
        gui_show_image(x, y, img);         
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_image_with_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
__inline static gui_virtual_keyboard_show_image_with_dimension(gui_virtual_keyboard_struct* v, S32 x, S32 y, S32 width, S32 height, PU8 img, gdi_handle source_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if ((v->is_venus_vk))
    {
        gdi_image_draw_resized_blend2layers(x, y, width, height, img);
    }
    else
#endif 
    {
        gdi_push_and_set_alpha_blending_source_layer(source_layer);
        gdi_image_draw_resized(x, y, width, height, img);         
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

}

MMI_BOOL gui_virtual_keyboard_Check_alphanumeric_vk_0_to_9_key(
          gui_virtual_keyboard_struct *v,
          S16 x,
          S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
   // UI_character_type key_char;
    gui_virtual_keyboard_pen_enum key_event;
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
    {
        if (MMI_TRUE == gui_virtual_keyboard_translate_pen_position(v, x, y, &index))
        {
            key = v->key_list[index];

           // if (!gui_virtual_keyboard_is_disabled_key(v, index))
            {
                /* parse the key content from content */
                key_event = GUI_VK_GET_KEY_EVENT(key.content);
                if (key_event >= GUI_VKBD_PEN_ALPHANUMERIC_KEY_0 && key_event <=GUI_VKBD_PEN_ALPHANUMERIC_KEY_9)
                {
                   
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}

#ifdef __MMI_VK_POPUP_HINT__
/***************************************************************************** 
 * FUNCTION
 *  gui_virtual_keyboard_redraw_popup_hint_content
 * DESCRIPTION
 *  Redraw the key's popup hint content
 * PARAMETERS
 *  v       [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
void gui_virtual_keyboard_redraw_popup_hint_content(
             gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct* key_p;
    S32 hint_x, hint_y;
    S32 width, height;
    PU8 img_ptr = NULL; 
    gdi_handle h0, h1, h2, h3;
    gui_virtual_keyboard_display_callback_type_enum flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_END;
    PU8 text = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->key_list[v->selected_key.index].popup_index == -1)
        return;
    if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE)
        return;
    
#if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        hint_x = 0;
        hint_y = 0;
    }
    else
#endif
    {
        hint_x = v->popup_hint.x;
        hint_y = v->popup_hint.y;    
    }

    key_p = &v->key_list[v->key_list[v->selected_key.index].popup_index];

    if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
    {
        S32 i = 0;
        while (i < v->popup_hint.multitap_event && key_p->popup_index != -1)
        {
            key_p = &v->key_list[key_p->popup_index];
        }
    }

    /* stop cursor before printing the pop-up*/
    if (v->popup_hint.hide_cursor_callback != NULL)
    {
        /* No need to stop the cursor if it is already stopped */
        //if (!gui_virtual_keyboard_is_cursor_stopped_by_vk)
        if (!v->popup_hint.is_cursor_stop)
        {
            v->popup_hint.is_cursor_stop = v->popup_hint.hide_cursor_callback(
                                                v->popup_hint.x,
                                                v->popup_hint.y,
                                                v->popup_hint.x + v->popup_hint.width - 1,
                                                v->popup_hint.y + v->popup_hint.height - 1);
            if (v->popup_hint.is_cursor_stop)
            {
                gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_TRUE;
            }
        }
    }
    
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);        
    /* 
     * if popup hint is out of VK background, we need flatten 
     * wallpaper to active layer
     */
    #if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
    #endif /* defined(__MMI_VUI_ENGINE__) */
    {
        if (v->popup_hint.y < v->y)
        {
            gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
            gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
        }
    }
    
    /* get the image from display callback first */
    if (v->display_callback != NULL)
    {
        v->display_callback(key_p->content, &flag, &text, &img_ptr, GUI_VK_KEY_STATE_POPUP);
    }

    if ((flag == GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG) || (flag == GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG_TEXT))
    {
        gdi_image_get_dimension(img_ptr, &width, &height);
        gui_virtual_keyboard_show_image_with_dimension(
            v, 
            hint_x,
            hint_y, 
            v->popup_hint.width,
            v->popup_hint.height,
            v->popup_hint.popup_background, 
            (gdi_handle)gdi_act_layer);

        gdi_layer_push_clip();
        
        gdi_layer_set_clip(
            hint_x,
            hint_y,
            hint_x + v->popup_hint.width,
            hint_y + v->popup_hint.height);
        
        /* show large icon content */
        gui_virtual_keyboard_show_image(
            v, 
            hint_x + VKBD_DIFF_HALF_EXT(v->popup_hint.width, width),
            hint_y + VKBD_DIFF_HALF_EXT(v->popup_hint.height, height),  
            img_ptr, 
            (gdi_handle)gdi_act_layer);

        gdi_layer_pop_clip();
    }
    else
    {
        /* some character key may be provided a image to show */
        if (key_p->content_highlight_id != NULL)
        {
            img_ptr = (PU8)get_image(key_p->content_highlight_id);
            gdi_image_get_dimension(img_ptr, &width, &height);
            gui_virtual_keyboard_show_image_with_dimension(
                v, 
                hint_x,
                hint_y, 
                v->popup_hint.width,
                v->popup_hint.height,
                v->popup_hint.popup_background, 
                (gdi_handle)gdi_act_layer);

            gdi_layer_push_clip();
            
            gdi_layer_set_clip(
                hint_x,
                hint_y,
                hint_x + v->popup_hint.width,
                hint_y + v->popup_hint.height);
            
            /* show large icon content */
            gui_virtual_keyboard_show_image(
                v, 
                hint_x + VKBD_DIFF_HALF_EXT(v->popup_hint.width, width),
                hint_y + VKBD_DIFF_HALF_EXT(v->popup_hint.height, height),  
                img_ptr, 
                (gdi_handle)gdi_act_layer);

            gdi_layer_pop_clip();
        }
        else
        {
            gui_virtual_keyboard_show_image(
                v, 
                hint_x,
                hint_y, 
                v->popup_hint.popup_background, 
                (gdi_handle)gdi_act_layer);
            gui_set_text_color(v->theme->key_up_text_color);
            gui_set_font(gui_font_get_type(GUI_FONT_SIZE_VK_LARGE_ICON));
            gui_print_character_at_xy(
                (U16)GUI_VK_GET_KEY_CHAR(key_p->content), 
                hint_x + v->popup_hint.char_x, 
                hint_y + v->popup_hint.char_y);
        }
    }
    gdi_pop_and_restore_alpha_blending_source_layer();
}

/***************************************************************************** 
 * FUNCTION
 *  gui_virtual_keyboard_redraw_popup_hint
 * DESCRIPTION
 *  Redraw the key's popup hint
 * PARAMETERS
 *  v       [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static void gui_virtual_keyboard_redraw_popup_hint(
             gui_virtual_keyboard_struct *v,
             MMI_BOOL cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    U16 key_char;
    //gui_virtual_keyboard_pen_enum key_event;

    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    gdi_handle h0, h1, h2, h3;
    S32 cache_buf_size_popup_hint;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    if (v->selected_key.index < 0 || v->selected_key.index > v->key_count)
    {
        return;
    }
    if (v->selected_key.is_key_cached == MMI_FALSE/* ||
        v->popup_hint.is_key_cached == MMI_FALSE*/)
    {
        return;
    }    

    if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE)
        return;
    
    /* get selected key content */
    key = v->key_list[v->selected_key.index];
    /* parse the key content from content */
    key_char = (U16)GUI_VK_GET_KEY_CHAR(key.content);
   // key_event = GUI_VK_GET_KEY_EVENT(key.content);
    MMI_DBG_ASSERT(key_char != 0);

    x1 = key.x;
    y1 = key.y;
    x2 = x1 + key.width - 1;
    y2 = y1 + key.height - 1;

#if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        //vadp_p2v_start_virtual_keyboard_popup((void*)v);
        //vadp_p2v_virtual_keyboard_popup_move();
        //vadp_p2v_redraw_virtual_keyboard_popup((void*)v);
    }
    else
#endif
    {
        if (key.popup_index != -1) /* there is popup content */ 
        {
            gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
            gui_lock_double_buffer();
            gdi_layer_push_clip();

            if (v->popup_hint.is_key_cached == MMI_FALSE && cache)
            {
                cache_buf_size_popup_hint = ((v->popup_hint.width)*(v->popup_hint.height) *(gdi_act_layer->bits_per_pixel)) >> 3;
                MMI_DBG_ASSERT(cache_buf_size_popup_hint <= GUI_VIRTUAL_KEYBOARD_CELL_CACHE_SIZE);
				if (v->popup_hint.key_bitmap.buf_ptr != NULL)
				{
					mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr); 
				}
                v->popup_hint.key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size_popup_hint);
                MMI_DBG_ASSERT(v->popup_hint.key_bitmap.buf_ptr != NULL);

                v->popup_hint.is_key_cached = MMI_TRUE;
            }
            else if (v->popup_hint.is_key_cached)
            {
                MMI_DBG_ASSERT(v->popup_hint.key_bitmap.buf_ptr != NULL);
                gui_lock_double_buffer();
                gdi_layer_push_clip();
                gdi_layer_set_clip(
                    v->popup_hint.x,
                    v->popup_hint.y,
                    v->popup_hint.x + v->popup_hint.width - 1,
                    v->popup_hint.y + v->popup_hint.height - 1);
                
                /* 
                 * if popup hint is out of VK background, we need flatten 
                 * wallpaper to active layer
                 */
                #if defined(__MMI_VUI_ENGINE__)
                if (!v->is_venus_vk)
                #endif /* defined(__MMI_VUI_ENGINE__) */
                {
                    if (v->popup_hint.y < v->y)
                    {
                        gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
                        gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
                    }
                }
        

                gdi_image_cache_bmp_draw(
                    v->popup_hint.x,
                    v->popup_hint.y,
                    &v->popup_hint.key_bitmap);

                if (v->popup_hint.is_cursor_stop == MMI_TRUE)
                {
                    v->popup_hint.blink_cursor_callback();
                    v->popup_hint.is_cursor_stop = MMI_FALSE;
                }

                gdi_layer_pop_clip();
                gui_unlock_double_buffer();
             }

        gdi_pop_and_restore_alpha_blending_source_layer();

        gdi_layer_set_clip(
            v->popup_hint.x,
            v->popup_hint.y,
            v->popup_hint.x + v->popup_hint.width - 1,
            v->popup_hint.y + v->popup_hint.height - 1);
            MMI_DBG_ASSERT(v->popup_hint.key_bitmap.buf_ptr != NULL);
            if (cache)
            {
                gdi_image_cache_bmp_get(
                    v->popup_hint.x,
                    v->popup_hint.y,
                    v->popup_hint.x + v->popup_hint.width - 1,
                    v->popup_hint.y + v->popup_hint.height - 1,
                    &v->popup_hint.key_bitmap);
            }

        /* 
         * if popup hint is out of VK background, we need flatten 
         * wallpaper to active layer
         */
        #if defined(__MMI_VUI_ENGINE__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
        #endif /* defined(__MMI_VUI_ENGINE__) */

            gui_virtual_keyboard_redraw_popup_hint_content(v);
            //gdi_pop_and_restore_alpha_blending_source_layer();

            gdi_layer_pop_clip();
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(
                x1 < v->popup_hint.x ? x1 : v->popup_hint.x,
                v->popup_hint.y,
                x2 < (v->popup_hint.x + v->popup_hint.width - 1) ? (v->popup_hint.x + v->popup_hint.width - 1) : x2,
                v->y + y2);
        }
    }
}
#endif /* __MMI_VK_POPUP_HINT__ */

/*****************************************************************************
 * FUNCTION
 *  gui_vk_clear_cache
 * DESCRIPTION
 *  This function clears the cache in gui_virtual_keyboard_show. We need this fuction becuase in MAUI_02652563 the vk is updated late so it picks wrong cache
 *   
 *  image for cache.
 * PARAMETERS
 *  v       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_vk_clear_cache(gui_virtual_keyboard_struct *v)
{
    if (v->selected_key.key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->selected_key.key_bitmap.buf_ptr);
        v->selected_key.key_bitmap.buf_ptr = NULL;
    }
   // v->selected_key.is_key_cached = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_clear_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_clear_selected_key(
             gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->selected_key.index = -1;
    v->selected_key.x = 0;
    v->selected_key.y = 0;
    v->selected_key.width = 0;
    v->selected_key.height = 0;
    if (v->selected_key.key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->selected_key.key_bitmap.buf_ptr);
        v->selected_key.key_bitmap.buf_ptr = NULL;
    }
    v->selected_key.is_key_cached = MMI_FALSE;
#ifdef __MMI_VK_POPUP_HINT__
    v->popup_hint.x = 0;
    v->popup_hint.y = 0;
    v->popup_hint.width = 0;
    v->popup_hint.height = 0;
    v->popup_hint.char_x = 0;
    v->popup_hint.char_y = 0;
    if (v->popup_hint.key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr);
        v->popup_hint.key_bitmap.buf_ptr = NULL;
    }
    v->popup_hint.is_key_cached = MMI_FALSE;
#endif /* __MMI_VK_POPUP_HINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_draw_key_shape
 * DESCRIPTION
 *  draw shape of a key
 * PARAMETERS
 *  v               [IN/OUT]    Is the virtual keyboard object
 *  x               [IN]        key's x pos
 *  y               [IN]        key's y pos
 *  width           [IN]        key's width
 *  height          [IN]        key's height
 * RETURNS
 *  
 *****************************************************************************/
static void gui_virtual_keyboard_draw_key_shape(
             gui_virtual_keyboard_struct *v,
             S32 x,
             S32 y,
             S32 width,
             S32 height,
             color frame_color,
             color fill_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle abm_src_layer;
    //To do: add key's frame color and rect color to theme
    U16 frame_width, round_radius = 0;
    S32 axis_x, axis_y;
    S32 offset_x, offset_y, temp_radius;
    double temp_y;
    S32 temp_height;
    color temp_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(width > 0 && height > 0);
    gdi_layer_get_active(&abm_src_layer);
    //To do: add key's frame color and rect color to theme

    if (v->key_attribute.is_round_rect == MMI_TRUE)
    {
        if (width > height)
        {
            round_radius = (height >> 2);
        }
        else
        {
            round_radius = (width >> 2);
        }
    }

    frame_width = GUI_VIRTUAL_KEYBOARD_KEY_FRAME_WIDTH;
    /* is a normal rect */
    if (v->key_attribute.is_round_rect == MMI_FALSE || round_radius <= 1)
    {
        /*
         * draw frame: we suppose to style for frame
         * 1. not draw the corner
         * 2. fill corner, as a notmal framed rect
         */
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        /* following is style 1 */
        /* draw top frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + frame_width,
            y,
            x + width - 1 - frame_width,
            y + frame_width - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* draw bottom frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + frame_width,
            y + height - frame_width,
            x + width - 1 - frame_width,
            y + height - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
    #else /* __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__ */
        /* following is style 2 */
        /* draw top frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x,
            y,
            x + width - 1,
            y + frame_width - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* draw bottom frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x,
            y + height - frame_width,
            x + width - 1,
            y + height - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
    #endif /* __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__ */

        /* draw left frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x,
            y + frame_width,
            x + frame_width - 1,
            y + height - 1 - frame_width,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* draw right frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + width - frame_width,
            y + frame_width,
            x + width - 1,
            y + height - 1 - frame_width,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* fill rect */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + frame_width,
            y + frame_width,
            x + width - 1 - frame_width,
            y + height - 1 - frame_width,
            fill_color.alpha,
            fill_color.r,
            fill_color.g,
            fill_color.b);
    }
    else
    {
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
        gui_push_clip();
        temp_radius = round_radius - frame_width;

        /* left top round corner */
        axis_x = x + round_radius - 1;
        axis_y = y + round_radius - 1;
        gui_set_clip(x, y, axis_x, axis_y);
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y + 1 - temp_height,
                axis_x - offset_x,
                axis_y,
                fill_color.alpha,
                fill_color.r,
                fill_color.g,
                fill_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y + 1 - offset_y - temp_height,
                axis_x - offset_x,
                axis_y + 1 - offset_y - 1,
                frame_color.alpha,
                frame_color.r,
                frame_color.g,
                frame_color.b);
        }

        /* left bottom round corner */
        axis_y = y + height - round_radius;
        gui_set_clip(x, axis_y, axis_x, y + height - 1);
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y,
                axis_x - offset_x,
                axis_y + temp_height - 1,
                fill_color.alpha,
                fill_color.r,
                fill_color.g,
                fill_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y + offset_y,
                axis_x - offset_x,
                axis_y + offset_y + temp_height - 1,
                frame_color.alpha,
                frame_color.r,
                frame_color.g,
                frame_color.b);
        }
        /* rect between two round corner */
        gui_set_clip(x, y + round_radius, axis_x, axis_y - 1);
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x,
            y + round_radius,
            x + frame_width - 1,
            axis_y - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* fill rect */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + frame_width,
            y + round_radius,
            axis_x,
            axis_y - 1,
            fill_color.alpha,
            fill_color.r,
            fill_color.g,
            fill_color.b);

        /* draw the rect in middle */
        gui_set_clip(
            x + round_radius,
            y,
            x + width - round_radius - 1,
            y + height - 1);
        /* top frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + round_radius,
            y,
            x + width - round_radius - 1,
            y + frame_width - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* bottom frame */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + round_radius,
            y + height - frame_width,
            x + width - round_radius - 1,
            y + height - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* fill rect */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + round_radius,
            y + frame_width,
            x + width - round_radius - 1,
            y + height - 1 - frame_width,
            fill_color.alpha,
            fill_color.r,
            fill_color.g,
            fill_color.b);

        /* right top round corner */
        axis_x = x + width - round_radius;
        axis_y = y + round_radius - 1;
        gui_set_clip(axis_x, y, x + width - 1, axis_y);        
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y + 1 - temp_height,
                axis_x + offset_x,
                axis_y,
                fill_color.alpha,
                fill_color.r,
                fill_color.g,
                fill_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y + 1 - offset_y - temp_height,
                axis_x + offset_x,
                axis_y + 1 - offset_y - 1,
                frame_color.alpha,
                frame_color.r,
                frame_color.g,
                frame_color.b);
        }

        /* right bottom round corner */
        axis_y = y + height - round_radius;
        gui_set_clip(axis_x, axis_y, x + width - 1, y + height - 1);
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y,
                axis_x + offset_x,
                axis_y + temp_height - 1,
                fill_color.alpha,
                fill_color.r,
                fill_color.g,
                fill_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y + offset_y,
                axis_x + offset_x,
                axis_y + offset_y + temp_height - 1,
                frame_color.alpha,
                frame_color.r,
                frame_color.g,
                frame_color.b);
        }
        /* rect between two round corner */
        gui_set_clip(axis_x, y + round_radius, x + width - 1, axis_y - 1);
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + width - frame_width,
            y + round_radius,
            x + width - 1,
            axis_y - 1,
            frame_color.alpha,
            frame_color.r,
            frame_color.g,
            frame_color.b);
        /* fill rect */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            axis_x,
            y + round_radius,
            x + width - 1 - frame_width,
            axis_y - 1,
            fill_color.alpha,
            fill_color.r,
            fill_color.g,
            fill_color.b);

        gui_pop_clip();
    #else /* __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__ */
        gui_push_clip();
        temp_radius = round_radius - frame_width;

        /* left top round corner */
        axis_x = x + round_radius - 1;
        axis_y = y + round_radius - 1;
        gui_set_clip(x, y, axis_x, axis_y);
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }

            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             fill_color,
                             axis_x - offset_x, /* value */
                             x + frame_width, /* begin point */
                             x + width - 1 - frame_width, /* end point */
                             MMI_TRUE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y + 1 - temp_height,
                axis_x - offset_x,
                axis_y,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             frame_color,
                             axis_x - offset_x, /* value */
                             x, /* begin point */
                             x + width - 1, /* end point */
                             MMI_FALSE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y + 1 - offset_y - temp_height,
                axis_x - offset_x,
                axis_y + 1 - offset_y - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
        }

        /* left bottom round corner */
        axis_y = y + height - round_radius;
        gui_set_clip(x, axis_y, axis_x, y + height - 1);
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }

            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             fill_color,
                             axis_x - offset_x, /* value */
                             x + frame_width, /* begin point */
                             x + width - 1 - frame_width, /* end point */
                             MMI_TRUE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y,
                axis_x - offset_x,
                axis_y + temp_height - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             frame_color,
                             axis_x - offset_x, /* value */
                             x, /* begin point */
                             x + width - 1, /* end point */
                             MMI_FALSE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x - offset_x,
                axis_y + offset_y,
                axis_x - offset_x,
                axis_y + offset_y + temp_height - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
        }
        /* rect between two round corner */
        gui_set_clip(x, y + round_radius, axis_x, axis_y - 1);
        /* get current column's color */
        temp_color = gui_virtual_keyboard_get_gradient_color(
                         frame_color,
                         x, /* value */
                         x, /* begin point */
                         x + width - 1, /* end point */
                         MMI_FALSE); /* ascend */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x,
            y + round_radius,
            x + frame_width - 1,
            axis_y - 1,
            temp_color.alpha,
            temp_color.r,
            temp_color.g,
            temp_color.b);

        for (offset_x = frame_width; offset_x < round_radius; offset_x++)
        {
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             fill_color,
                             x + offset_x, /* value */
                             x + frame_width, /* begin point */
                             x + width - 1 - frame_width, /* end point */
                             MMI_TRUE); /* ascend */
            /* fill rect */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                x + offset_x,
                y + round_radius,
                x + offset_x,
                axis_y - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
        }

        /* draw the rect in middle */
        gui_set_clip(
            x + round_radius,
            y,
            x + width - round_radius - 1,
            y + height - 1);
        for (offset_x = round_radius; offset_x < width - round_radius; offset_x++)
        {
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             frame_color,
                             x + offset_x, /* value */
                             x, /* begin point */
                             x + width - 1, /* end point */
                             MMI_FALSE); /* ascend */
            /* top frame */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                x + offset_x,
                y,
                x + offset_x,
                y + frame_width - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
            /* bottom frame */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                x + offset_x,
                y + height - frame_width,
                x + offset_x,
                y + height - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);

            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             fill_color,
                             x + offset_x, /* value */
                             x + frame_width, /* begin point */
                             x + width - 1 - frame_width, /* end point */
                             MMI_TRUE); /* ascend */
            /* fill rect */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                x + offset_x,
                y + frame_width,
                x + offset_x,
                y + height - 1 - frame_width,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
        }

        /* right top round corner */
        axis_x = x + width - round_radius;
        axis_y = y + round_radius - 1;
        gui_set_clip(axis_x, y, x + width - 1, axis_y);        
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             fill_color,
                             axis_x + offset_x, /* value */
                             x + frame_width, /* begin point */
                             x + width - 1 - frame_width, /* end point */
                             MMI_TRUE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y + 1 - temp_height,
                axis_x + offset_x,
                axis_y,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             frame_color,
                             axis_x + offset_x, /* value */
                             x, /* begin point */
                             x + width - 1, /* end point */
                             MMI_FALSE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y + 1 - offset_y - temp_height,
                axis_x + offset_x,
                axis_y + 1 - offset_y - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
        }

        /* right bottom round corner */
        axis_y = y + height - round_radius;
        gui_set_clip(axis_x, axis_y, x + width - 1, y + height - 1);
        for (offset_x = 0; offset_x < round_radius; offset_x++)
        {
            temp_y = sqrt((double)(temp_radius * temp_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1);
            }
            else
            {
                temp_height = floor(temp_y);
            }
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             fill_color,
                             axis_x + offset_x, /* value */
                             x + frame_width, /* begin point */
                             x + width - 1 - frame_width, /* end point */
                             MMI_TRUE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y,
                axis_x + offset_x,
                axis_y + temp_height - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);

            offset_y = temp_height;
            temp_y = sqrt((double)(round_radius * round_radius - offset_x * offset_x));
            if (temp_y - floor(temp_y) > 0.5)
            {
                temp_height = floor(temp_y + 1) - temp_height;
            }
            else
            {
                temp_height = floor(temp_y) - temp_height;
            }
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             frame_color,
                             axis_x + offset_x, /* value */
                             x, /* begin point */
                             x + width - 1, /* end point */
                             MMI_FALSE); /* ascend */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                axis_y + offset_y,
                axis_x + offset_x,
                axis_y + offset_y + temp_height - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
        }
        /* rect between two round corner */
        gui_set_clip(axis_x, y + round_radius, x + width - 1, axis_y - 1);
        /* get current column's color */
        temp_color = gui_virtual_keyboard_get_gradient_color(
                         frame_color,
                         x + width - frame_width, /* value */
                         x, /* begin point */
                         x + width - 1, /* end point */
                         MMI_FALSE); /* ascend */
        gdi_effect_alpha_blending_rect(
            abm_src_layer,
            x + width - frame_width,
            y + round_radius,
            x + width - 1,
            axis_y - 1,
            temp_color.alpha,
            temp_color.r,
            temp_color.g,
            temp_color.b);
        for (offset_x = 0; offset_x < round_radius - frame_width; offset_x++)
        {
            /* get current column's color */
            temp_color = gui_virtual_keyboard_get_gradient_color(
                             fill_color,
                             axis_x + offset_x, /* value */
                             x + frame_width, /* begin point */
                             x + width - 1 - frame_width, /* end point */
                             MMI_TRUE); /* ascend */
            /* fill rect */
            gdi_effect_alpha_blending_rect(
                abm_src_layer,
                axis_x + offset_x,
                y + round_radius,
                axis_x + offset_x,
                axis_y - 1,
                temp_color.alpha,
                temp_color.r,
                temp_color.g,
                temp_color.b);
        }

        gui_pop_clip();
    #endif /* __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__ */
    }
    UI_UNUSED_PARAMETER(temp_color);
}
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_is_dead_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v           [IN/OUT]    Virtual Keyboard object
 *  index       [IN]        index of key in key list
 * RETURNS
 *  
 *****************************************************************************/
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

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_is_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v           [IN/OUT]    Virtual Keyboard object
 *  index       [IN]        index of key in key list
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_selected_key(
                 gui_virtual_keyboard_struct *v,
                 U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(index < v->key_count);
    if (v->key_down_accepted == MMI_TRUE)
    {
        if ((v->selected_key.is_key_cached == MMI_TRUE) &&
            (v->selected_key.index == index))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_is_kept_down_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v           [IN/OUT]    Virtual Keyboard object
 *  index       [IN]        index of key in key list
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_kept_down_key(
                 gui_virtual_keyboard_struct *v,
                 U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(index < v->key_count);
    if ((v->kept_key.is_down_kept == MMI_TRUE) &&
        (v->kept_key.index == index))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_is_disabled_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v           [IN/OUT]    Virtual Keyboard object
 *  index       [IN]        index of key in key list
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_disabled_key(
                 gui_virtual_keyboard_struct *v,
                 U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    U16 key_char;
    UI_character_type ch = 0, tmp;
    const UI_character_type *pch;
    gui_virtual_keyboard_pen_enum key_event;
    gui_virtual_keyboard_pen_enum *ptr, tmp_event;
    MMI_BOOL disabled = MMI_TRUE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(index < v->key_count);
    /* get the key from key list by index */
    key = v->key_list[index];
    /* parse the key content from content */
    key_char = (U16)GUI_VK_GET_KEY_CHAR(key.content);
    key_event = GUI_VK_GET_KEY_EVENT(key.content);
    MMI_DBG_ASSERT(!((key_char != 0) &&
                     ((key_event >= GUI_VKBD_PEN_NONE) &&
                      (key_event < GUI_VKBD_PEN_MAX))));
    ch = (UI_character_type)key_char;

    if (v->disable_keys.allowed_chars)
    {
        /* gui_virtual_keyboard_set_allowed_characters() and 
           gui_virtual_board_set_disable_list() are mutually-exclusive */
        MMI_DBG_ASSERT(v->disable_keys.disabled_chars[0] == 0);

        /* we will allow IME to enable special symbols even allowed_characters has content */
        for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
        {
            if (v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_NONE)
            {
                break;
            }
            MMI_DBG_ASSERT(
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_HIDE ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_SHOW ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_CAPSLOCK ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_SYMBPICKER ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_DISPLAY_CALLBACK);
        }

        switch (key_event)
        {
            case GUI_VKBD_PEN_HIDE:
            case GUI_VKBD_PEN_SHOW:
            case GUI_VKBD_PEN_CAPSLOCK:
            case GUI_VKBD_PEN_SYMBPICKER:
            case GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
            case GUI_VKBD_PEN_DISPLAY_CALLBACK:
            case GUI_VKBD_PEN_CHANGE_MODE:
            case GUI_VKBD_PEN_NUM_AND_SYM:
                {
                    disabled = MMI_FALSE;
                    for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
                    {
                        if (v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_NONE)
                        {
                            break;
                        }
                        if (v->disable_keys.disabled_symbols[i] == key_event)
                        {
                            disabled = MMI_TRUE;
                            break;
                        }
                    }
                }
                break;

            case GUI_VKBD_PEN_BAKSPACE:
            case GUI_VKBD_PEN_DISPLAY_AREA:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
            case GUI_VKBD_PEN_BACK_TO_LANG:
            /* GUI_VKBD_PEN_DISPLAY_AREA is always enabled because it's display only */
                disabled = MMI_FALSE;
                break;
                
            case GUI_VKBD_PEN_HANDWRITING:
            case GUI_VKBD_PEN_DOT_COM:
            case GUI_VKBD_PEN_DOT_ORG:
            case GUI_VKBD_PEN_DOT_NET:
            case GUI_VKBD_PEN_DOT_GOV:
            case GUI_VKBD_PEN_DOT_EDU:
            case GUI_VKBD_PEN_DOT_MIL:
                 disabled = MMI_FALSE;
                break;

            case GUI_VKBD_PEN_NEWLINE:
            case GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE:
                ch = (UI_character_type)'\n';
                key_event = GUI_VKBD_PEN_CHAR_I;
                break;

            case GUI_VKBD_PEN_SPACE:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
                ch = (UI_character_type)' ';
                key_event = GUI_VKBD_PEN_CHAR_I;
                break;
            /* matrix key event is allowed. */    
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
            case GUI_VKBD_PEN_ALPHANUMERIC_SYM_LOCK:
            case GUI_VKBD_PEN_ALPHANUMERIC_SYM_PREV_PAGE:
            case GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE:
            case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
            case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
            case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            /* Dialer Events For VK*/
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
			//case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
			case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
			case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
                disabled = MMI_FALSE;
			if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE)
			{
				if (key_event == GUI_VKBD_PEN_ALPHANUMERIC_SYM_PREV_PAGE)
					disabled=MMI_TRUE;
			}
			else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE)
			{
				if (key_event == GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE)
					disabled=MMI_TRUE;
			}
                break;

            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
			disabled = MMI_FALSE;
			for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
			{
				if (v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1)
				{
					disabled = MMI_TRUE;
					break;
				}
			}
				break ;
            case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
			disabled = MMI_FALSE;
			for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
			{
				if (v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2)
				{
					disabled = MMI_TRUE;
					break;
				}
			}
                break; 
			case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
			disabled = MMI_FALSE;
			for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
			{
				if (v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL)
				{
					disabled = MMI_TRUE;
					break;
				}
			}
				break ;
        }

        if (ch)
        {
            pch = v->disable_keys.allowed_chars;

            for (i = 0; pch[i] != 0; i++)
            {
                tmp = pch[i];

                /* Is the char in consecutive characters */
                if ((tmp == (UI_character_type)'-') && (i > 0) && pch[i + 1])
                {
                    if (ch >= pch[i - 1] && ch <= pch[i + 1])
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                    i++;
                }
                else
                {
                    if (tmp == ((UI_character_type)'\\') && pch[i + 1])
                    {
                        tmp = pch[++i];
                    }

                    if (tmp == ch)
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                }
            }
        }

        return disabled;
    }
    else /* disabled chars & symbols */
    {
        /* if key's content is a char, we need give it a GUI_VKBD_PEN_CHAR_I event */
        if (key_char != 0)
        {
            key_event = GUI_VKBD_PEN_CHAR_I;
        }

        if (key_event == GUI_VKBD_PEN_CHAR_I)
        {
            pch = v->disable_keys.disabled_chars;

            if (ch == 0)
            {
                return MMI_TRUE;
            }

        #if defined(__MMI_INDIC_VK__)
            if (!ire_vk_get_grey() &&
                IRE_INDIC_LANGUAGE_RANGE(ch) &&
                ire_IsValidInput(&ch, 2) == MMI_FALSE)
            {
                return MMI_TRUE;
            }
        #endif /* defined(__MMI_INDIC_VK__) */ 

            while ((tmp = *pch++) != 0)
            {
                if (tmp == ch)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
        else if (key_event == GUI_VKBD_PEN_NONE)
        {
            return MMI_TRUE;
        }
        else
        {
            ptr = v->disable_keys.disabled_symbols;

            while ((tmp_event = *ptr++) != GUI_VKBD_PEN_NONE)
            {
                if (tmp_event == key_event)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_draw_key
 * DESCRIPTION
 *  draw one key of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard object
 *  i       [IN]            index of the key need draw
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_draw_key_int(
             gui_virtual_keyboard_struct *v,
             S16 index,
             S16 x,
             S16 y,
             gui_virtual_keyboard_key_state_enum key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct_p key = &v->key_list[index];
//    gui_virtual_keyboard_pen_enum key_event;
    U16 key_char = 0;
    PU8 img = NULL;
    PU8 text = NULL;
    gui_virtual_keyboard_display_callback_type_enum flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_END;
    S32 glyph_width, glyph_height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* parse the key content from content */
    key_char = (U16)GUI_VK_GET_KEY_CHAR(key->content);
   // key_event = GUI_VK_GET_KEY_EVENT(key->content);


    if (key_state == GUI_VK_KEY_STATE_DISABLE)
    {
        if (key->disable_id != NULL)
        {
            /* For handling 9 slice images */
            gui_virtual_keyboard_show_image_with_dimension(
            	v, 
            	(S32)x, 
            	(S32)y, 
            	(S32)key->width,
                (S32)key->height,
            	(PU8)get_image(key->disable_id), 
            	(gdi_handle)gdi_act_layer);
        }
        else
        {
            gui_virtual_keyboard_draw_key_shape(
                v,
                x,
                y,
                key->width,
                key->height,
                v->theme->key_disable_text_color,
                v->theme->key_disable_bg_color);
        }
        
        if (v->display_callback != NULL)
        {
            v->display_callback(key->content, &flag, &text, &img, GUI_VK_KEY_STATE_DISABLE);
        }

        if ((flag != GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG) && (flag != GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG_TEXT))
        {
            /* show image as key content */
            if (key->content_id != NULL)
            {
                img = get_image(key->content_disable_id);
            }
            else 
            {
                MMI_ASSERT(0);
            }
        }
    }
    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
    {
        if (key->highlight_id != NULL)
        {
            /* For handling 9 slice images */
            gui_virtual_keyboard_show_image_with_dimension(
            	v, 
            	(S32)x, 
            	(S32)y, 
            	(S32)key->width,
                (S32)key->height,
            	(PU8)get_image(key->highlight_id), 
            	(gdi_handle)gdi_act_layer);
        }
        else
        {
            gui_virtual_keyboard_draw_key_shape(
                v,
                x,
                y,
                key->width,
                key->height,
                v->theme->key_down_text_color,
                v->theme->key_down_filler->c);

        }

        if (v->display_callback != NULL)
        {
            v->display_callback(key->content, &flag, &text, &img, GUI_VK_KEY_STATE_HIGHLIGHT);
        }

        if ((flag != GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG) && (flag != GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG_TEXT))
        {
            /* show image as key content */
            if (key->content_highlight_id != NULL)
            {
                img = get_image(key->content_highlight_id);
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
    }
    else
    {
        if (key->bg_id != NULL)
        {
            /* For handling 9 slice images */
            gui_virtual_keyboard_show_image_with_dimension(
            	v, 
            	(S32)x, 
            	(S32)y, 
            	(S32)key->width,
                (S32)key->height,
            	(PU8)get_image(key->bg_id), 
            	(gdi_handle)gdi_act_layer);
        }
        else
        {
            gui_virtual_keyboard_draw_key_shape(
                v,
                x,
                y,
                key->width,
                key->height,
                v->theme->key_down_text_color,
                v->theme->key_up_text_color);
        }

        if (v->display_callback != NULL)
        {
            v->display_callback(key->content, &flag, &text, &img, GUI_VK_KEY_STATE_NORMAL);
        }

        if ((flag != GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG) && (flag != GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_IMG_TEXT))
        {
            /* show image as key content */
            if (key->content_id != NULL)
            {
                img = get_image(key->content_id);
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
    }
        
    gui_set_font(v->theme->text_font);
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if ((key->font_size >0) && (key_char != 0) && img== NULL)
    {
        /* Using key structure to draw the fonts */
        stFontAttribute font;
        memcpy(&font, v->theme->text_font, sizeof(stFontAttribute));
        font.size = FONT_PIXEL_SIZE(key->font_size);
        gui_set_font(&font);

        gui_print_character_at_xy(key_char, x + key->text_offset_x, y + key->text_offset_y);
        return;
    }
    else
#endif 
    {
        gui_virtual_keyboard_show_content_by_align(
            v,
            key_char,
            text,
            img,
            x,
            y,
            key->width,
            key->height,
            &glyph_width,
            &glyph_height,
            GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_CENTER);
    }

}

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_draw_key
 * DESCRIPTION
 *  draw one key of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard object
 *  i       [IN]            index of the key need draw
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_draw_key(
             gui_virtual_keyboard_struct *v,
             U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    gui_virtual_keyboard_pen_enum key_event;
    U16 key_char = 0;
//    PU8 img = NULL;
//   PU8 text = NULL;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(index < v->key_count);

    /* get the key from key list by index */
    key = v->key_list[index];
    x1 = v->x + key.x;
    y1 = v->y + key.y;
    x2 = x1 + key.width - 1;
    y2 = y1 + key.height - 1;

    /* parse the key content from content */
    key_char = (U16)GUI_VK_GET_KEY_CHAR(key.content);
    key_event = GUI_VK_GET_KEY_EVENT(key.content);

    /* assert this key's content is not NULL */
    MMI_DBG_ASSERT(!((key_char == 0) &&
                     (key_event == GUI_VKBD_PEN_NONE ||
                      key_event >= GUI_VKBD_PEN_MAX)));

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);

    if (gui_virtual_keyboard_is_disabled_key(v, index))
    {
        gui_virtual_keyboard_draw_key_int(
            v, 
            index, 
            x1, 
            y1, 
            GUI_VK_KEY_STATE_DISABLE);
    }
    else if (gui_virtual_keyboard_is_kept_down_key(v, index) || gui_virtual_keyboard_is_selected_key(v, index))
    {
        gui_virtual_keyboard_draw_key_int(
            v, 
            index, 
            x1, 
            y1, 
            GUI_VK_KEY_STATE_HIGHLIGHT);

    }
	else if (is_backspace_down_state && key_event == GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE)
	{
        gui_virtual_keyboard_draw_key_int(
            v, 
            index, 
            x1, 
            y1, 
            GUI_VK_KEY_STATE_HIGHLIGHT);
	}
    else
    {
        gui_virtual_keyboard_draw_key_int(
            v, 
            index, 
            x1, 
            y1, 
            GUI_VK_KEY_STATE_NORMAL);

    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gui_pop_clip();

}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_default_hide_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]
 *  y1      [IN]
 *  x2      [IN]
 *  y2      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_default_hide_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle abm_src_layer;
    color bg_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wgui_is_wallpaper_on_bottom())
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
    }
    else
    {
        gdi_get_alpha_blending_source_layer(&abm_src_layer);
        //To do: add default background to theme
        bg_color.alpha = 40;
        bg_color.r = 0;
        bg_color.g = 0;
        bg_color.b = 0;

        gdi_effect_alpha_blending_rect(
            abm_src_layer, 
            x1,
            y1,
            x2,
            y2, 
            bg_color.alpha,
            bg_color.r,
            bg_color.g,
            bg_color.b);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_default_display_callback_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_default_display_callback_function(
             gui_virtual_keyboard_pen_enum pen_symbol,
             gui_virtual_keyboard_display_callback_type_enum *flag,
             PU8 *text,
             PU8 *image,
             gui_virtual_keyboard_key_state_enum key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(pen_symbol > GUI_VKBD_PEN_NONE &&
                   pen_symbol < GUI_VKBD_PEN_MAX);
    *flag = GUI_VIRTUAL_KEYBOARD_DISPLAY_CALLBACK_START;
    *text = NULL;
    *image = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_content_by_align
 * DESCRIPTION
 *  The function display the key's content
 * PARAMETERS
 *  ch                  [IN]    character to be displayed
 *  text                [IN]    text to be displayed
 *  image               [IN]    image to be displayed
 *  key_x               [IN]    start x point of key
 *  key_y               [IN]    start y point of key
 *  key_width           [IN]    width of key
 *  key_height          [IN]    height of key
 *  glyph_width         [OUT]   content width
 *  glyph_height        [OUT]   content height
 *  align               [IN]    align type of key
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_show_content_by_align(
             gui_virtual_keyboard_struct* v,
             UI_character_type ch,
             PU8 text,
             PU8 image,
             S32 key_x,
             S32 key_y,
             S32 key_width,
             S32 key_height,
             S32 *glyph_width,
             S32 *glyph_height,
             gui_virtual_keyboard_text_align_enum align)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bbox_x, bbox_y, bbox_width, bbox_height;
    S32 content_x, content_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == 0 && text == NULL && image == NULL)
    {
        return;
    }

    /* image has higher priority */
    if ((ch != 0) && (image != NULL))
    {
        gui_measure_image(image, glyph_width, glyph_height);

        if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_LEFT)
        {
            content_x = key_x + GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP;
        }
        else if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_RIGHT)
        {
            content_x = key_x + key_width - GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP - *glyph_width;
        }
        else
        {
            //content_x = key_x + VKBD_DIFF_HALF_EXT(key_width, *glyph_width);
            content_x = key_x + (key_width - *glyph_width) / 2;
        }
        //content_y = key_y + VKBD_DIFF_HALF(key_height, *glyph_height);
        content_y = key_y + (key_height - *glyph_height) / 2;
        gui_virtual_keyboard_show_image(v, content_x, content_y, image, (gdi_handle)gdi_act_layer);

    }
    else if (ch != 0)
    {
        /*
         * '_' is special because it will get confused with '-';
         * 0x0e3a is also a special char in Thai
         */
        if (ch == (UI_character_type)'_')
        {
            gui_measure_character(ch, glyph_width, glyph_height);
            content_x = key_x + VKBD_DIFF_HALF(key_width, *glyph_width);

        #if defined(__MMI_VECTOR_FONT_SUPPORT__)
            /* this char is special in VFont, it's ascent:-3, descent:4 & height:1
             * since it is only a char, not a string, so it is hard to align it
             * by baseline. So we use a trick of show it in 3/4 position of the key
             */
            content_y = key_y + (key_height >> 1) + (((key_height >> 1) - *glyph_height) >> 1);
        #else /* __MMI_VECTOR_FONT_SUPPORT__ */
            content_y = key_y + VKBD_DIFF_HALF(key_height, *glyph_height);
        #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
        }
        else if (ch == (UI_character_type)(0x0e3a))
        {
            gui_measure_character(ch, glyph_width, glyph_height);
            content_x = key_x + VKBD_DIFF_HALF(key_width, *glyph_width);
            content_y = key_y + VKBD_DIFF_HALF(key_height, *glyph_height);
        }
        else
        {
            Get_CharBoundingBox(
                ch,
                glyph_width,
                glyph_height,
                &bbox_x,
                &bbox_y,
                &bbox_width,
                &bbox_height);

            if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_LEFT)
            {
                content_x = key_x + GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP;
            }
            else if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_RIGHT)
            {
                content_x = key_x + key_width - GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP - bbox_width;
            }
            else
            {
                content_x = key_x + VKBD_DIFF_HALF(key_width, bbox_width) - bbox_x;
            }
            content_y = key_y + VKBD_DIFF_HALF(key_height, bbox_height) - bbox_y;

            /* HACK. the number of remaing pixels is odd. */
            /* It is not always correct depending on the baseline of the font database */
            /* The magic number bbox_y + "1" can be modified */
            if (((key_height - bbox_height) & 1) && (bbox_y > *glyph_height - bbox_height - bbox_y))
            {
                content_y++;
            }

        }
        gui_print_character_at_xy(ch, content_x, content_y);
    }
    else
    {
        if (text == NULL ) /* only has image */
        {
            gui_measure_image(image, glyph_width, glyph_height);

            if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_LEFT)
            {
                content_x = key_x + GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP;
            }
            else if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_RIGHT)
            {
                content_x = key_x + key_width - GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP - *glyph_width;
            }
            else
            {
                //content_x = key_x + VKBD_DIFF_HALF_EXT(key_width, *glyph_width);
                content_x = key_x + (key_width - *glyph_width) / 2;
            }
            //content_y = key_y + VKBD_DIFF_HALF(key_height, *glyph_height);
            content_y = key_y + (key_height - *glyph_height) / 2;
            gui_virtual_keyboard_show_image(v, content_x, content_y, image, (gdi_handle)gdi_act_layer);
            //gui_show_image(content_x, content_y, image);
        }
        else if (image == NULL)
        {
            gui_measure_string(
                (UI_string_type)text,
                glyph_width,
                glyph_height);
            if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_LEFT)
            {
                content_x = key_x + GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP;
            }
            else if (align == GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_RIGHT)
            {
                content_x = key_x + key_width - GUI_VIRTUAL_KEYBOARD_CONTENT_BORDER_GAP - *glyph_width;
            }
            else
            {
                content_x = key_x + VKBD_DIFF_HALF(key_width, *glyph_width);
            }
            if (mmi_fe_get_r2l_state())
            {
                content_x = content_x + *glyph_width - 1;
            }
            content_y = key_y + VKBD_DIFF_HALF(key_height, *glyph_height);
            gui_move_text_cursor(content_x, content_y);
            gui_print_text((UI_string_type)text);
        }
        else
        {
            gui_measure_image(image, glyph_width, glyph_height);
            gui_measure_string(
                (UI_string_type)text,
                &bbox_width,
                &bbox_height);
            if (align == GUI_VIRTUAL_KEYBOARD_ICON_TEXT_VERTICAL_ALIGN)
            {
                content_x = key_x + VKBD_DIFF_HALF(key_width, *glyph_width);
                content_y = key_y +
                            VKBD_DIFF_HALF(
                                key_height,
                                (*glyph_height + bbox_height + GUI_VIRTUAL_KEYBOARD_CONTENT_ITEM_GAP));
                gui_virtual_keyboard_show_image(v, content_x, content_y, image, (gdi_handle)gdi_act_layer);
                content_x = key_x + VKBD_DIFF_HALF(key_width, bbox_width);
                content_y = content_y + *glyph_height + GUI_VIRTUAL_KEYBOARD_CONTENT_ITEM_GAP;
                if (mmi_fe_get_r2l_state())
                {
                    content_x = content_x + bbox_width - 1;
                }
                gui_move_text_cursor(content_x, content_y);
                gui_print_text((UI_string_type)text);
            }
            else
            {
                content_x = key_x +
                            VKBD_DIFF_HALF(
                                key_width,
                                (*glyph_width + bbox_width + GUI_VIRTUAL_KEYBOARD_CONTENT_ITEM_GAP));
                content_y = key_y + VKBD_DIFF_HALF(key_height, *glyph_height);
                gui_virtual_keyboard_show_image(v, content_x, content_y, image, (gdi_handle)gdi_act_layer);
                content_x = content_x + *glyph_width + GUI_VIRTUAL_KEYBOARD_CONTENT_ITEM_GAP;
                content_y = key_y + VKBD_DIFF_HALF(key_height, bbox_height);
                if (mmi_fe_get_r2l_state())
                {
                    content_x = content_x + bbox_width - 1;
                }
                gui_move_text_cursor(content_x, content_y);
                gui_print_text((UI_string_type)text);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]         
 *  x       [IN]        
 *  y       [IN]        
 *  s       [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_translate_pen_position(
                 gui_virtual_keyboard_struct *v,
                 S16 x,
                 S16 y,
                 S16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    gui_virtual_keyboard_key_struct key;
    S32 key_x, key_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    *index = -1;

    for (i = 0; i < v->key_count; i++)
    {
        key = v->key_list[i];
        /* not check popup or large key */
        if (key.y < 0)
            continue;

        key_x = v->x + key.x;
        key_y = v->y + key.y;
        if (PEN_CHECK_BOUND(x, y, key_x, key_y, key.width, key.height))
        {
            *index = i;
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 *  s       [IN]  
 *  ch      [OUT]     
 *  evt     [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_get_selected_key(
                 gui_virtual_keyboard_struct *v,
                 S16 index,
                 UI_character_type *key_char,
                 gui_virtual_keyboard_pen_enum *key_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    UI_character_type temp_char;
    gui_virtual_keyboard_pen_enum temp_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    *key_char = 0;
    *key_event = GUI_VKBD_PEN_NONE;

    if (index < 0 || index >= v->key_count)
    {
        return MMI_FALSE;
    }

    key = v->key_list[index];

    /* parse the key content from content */
    temp_char = (UI_character_type)GUI_VK_GET_KEY_CHAR(key.content);
    temp_event = GUI_VK_GET_KEY_EVENT(key.content);

    /* assert this key's content is not NULL */
    MMI_DBG_ASSERT(!((temp_char == 0) &&
                     (temp_event == GUI_VKBD_PEN_NONE ||
                      temp_event >= GUI_VKBD_PEN_MAX)));

    v->selected_key.index = index;
    v->selected_key.x = v->x + key.x;
    v->selected_key.y = v->y + key.y;
    v->selected_key.width = key.width;
    v->selected_key.height = key.height;

    *key_char = temp_char;
    *key_event = temp_event;
    if (temp_char > 0)
    {
        MMI_DBG_ASSERT(temp_event == GUI_VKBD_PEN_NONE);
        *key_event = GUI_VKBD_PEN_CHAR_I;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_cache_and_show_selected_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_cache_and_show_selected_key(
             gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    gui_virtual_keyboard_key_struct* popup_key;
//    U16 key_char = 0;
    gui_virtual_keyboard_pen_enum key_event;

    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    S32 glyph_width, glyph_height;
#ifdef __MMI_VK_POPUP_HINT__
    S32 popup_hint_x, popup_hint_y, popup_hint_width, popup_hint_height;
    S32 char_x, char_y;
    S32 box_x, box_y, box_width, box_height;
    PU8 zoom_img = NULL;
    //S32 cache_buf_size_popup_hint;
#endif /* __MMI_VK_POPUP_HINT__ */

  //  PU8 img = NULL; /* if key use an image */
//    PU8 text = NULL;
    //gui_virtual_keyboard_display_callback_type_enum flag;

    S32 cache_buf_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    if (v->selected_key.index < 0 || v->selected_key.index > v->key_count)
    {
        return;
    }

    /* get selected key content */
    key = v->key_list[v->selected_key.index];
    /* parse the key content from content */
    //key_char = (U16)GUI_VK_GET_KEY_CHAR(key.content);
    key_event = GUI_VK_GET_KEY_EVENT(key.content);

    if (key_event == GUI_VKBD_PEN_DISPLAY_AREA)
    {
        /*
         * We do not select Display Area. Furthermore, it costs too
         * much memory to cache the area
         */
        return;
    }

    x1 = v->x + key.x;
    y1 = v->y + key.y;
    x2 = x1 + key.width - 1;
    y2 = y1 + key.height - 1;

    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);


    /* cache the current key content to selected key's key_bitmap */
    cache_buf_size = (key.width * key.height * (gdi_act_layer->bits_per_pixel)) >> 3;
	if ( v->selected_key.key_bitmap.buf_ptr !=NULL)
	{
	    mmi_frm_scrmem_free( v->selected_key.key_bitmap.buf_ptr); 
	}
    v->selected_key.key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size);
    MMI_DBG_ASSERT(v->selected_key.key_bitmap.buf_ptr != NULL);
    MMI_DBG_ASSERT(cache_buf_size <= GUI_VIRTUAL_KEYBOARD_CELL_CACHE_SIZE);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->selected_key.key_bitmap);
    v->selected_key.is_key_cached = MMI_TRUE;

    /* show selected key's highlight key */
    if (v->hide_callback != NULL)
    {
        v->hide_callback(x1, y1, x2, y2);
    }
    if (v->bg_id != NULL)
    {
        gui_show_image(v->x, v->y, (PU8)get_image(v->bg_id));
    }


    /* show key's content */
    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
    

    gui_virtual_keyboard_draw_key_int(v, v->selected_key.index, x1, y1, GUI_VK_KEY_STATE_HIGHLIGHT);
    
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();

#ifndef __MMI_VK_POPUP_HINT__
    gui_BLT_double_buffer(x1, y1, x2, y2);
#else

    if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE)
        return;

    /* if not have popup hint image, blt the selected key & return */
    if (!(v->theme->popup_hint_left_image != NULL &&
        v->theme->popup_hint_right_image != NULL))
    {
        gui_BLT_double_buffer(x1, y1, x2, y2);
        return;
    }

    if (key.popup_index != -1) /* there is popup content */        
    {
        zoom_img = (PU8)GetImage(IMG_ID_VKBD_CUSTOM_LARGE_ICON);
        gdi_image_get_dimension(
            (U8*)zoom_img,
            &popup_hint_width,
            &popup_hint_height);

        if (popup_hint_width < GUI_VK_POPUP_ICON_MIN_WIDTH)
            popup_hint_width = GUI_VK_POPUP_ICON_MIN_WIDTH;
        if (popup_hint_height < GUI_VK_POPUP_ICON_MIN_HEIGHT)
            popup_hint_height = GUI_VK_POPUP_ICON_MIN_HEIGHT;

        /* caluclate popup hint's position */
        popup_hint_x = x1 + (key.width >> 1) - (popup_hint_width >> 1);
        if (popup_hint_x < v->x)
            popup_hint_x = v->x;
        if (popup_hint_x + popup_hint_width > (v->x + v->width))
            popup_hint_x = (v->x + v->width) - popup_hint_width;
        
        v->popup_hint.x = popup_hint_x;
        popup_hint_y = y1 /*+ GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_Y_OFFSET*/ - popup_hint_height;
        v->popup_hint.width = popup_hint_width;
        v->popup_hint.height = popup_hint_height;
        v->popup_hint.y = popup_hint_y;
        v->popup_hint.popup_background = zoom_img;

        popup_key = &v->key_list[key.popup_index];

        if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
        {
            S32 i = 0;
            while (i < v->popup_hint.multitap_event && popup_key->popup_index != -1)
            {
                popup_key = &v->key_list[popup_key->popup_index];
            }
        }
        
        /* some character key may be provided a image to show */
        if (popup_key->content_highlight_id == NULL)
        {
            /* show large icon content */
            gui_set_text_color(v->theme->key_up_text_color);
            gui_set_font(gui_font_get_type(GUI_FONT_SIZE_VK_LARGE_ICON));
            Get_CharBoundingBox(
                popup_key->content,
                &glyph_width,
                &glyph_height,
                &box_x,
                &box_y,
                &box_width,
                &box_height);

            char_x = /* popup_hint_x + */
                     VKBD_DIFF_HALF(popup_hint_width, box_width) -
                     box_x;
            char_y =  /* popup_hint_y + */
                     VKBD_DIFF_HALF(
                      (popup_hint_height - GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_Y_OFFSET),
                      box_height) -
                     box_y;
        }
        else
        {

            gdi_image_get_dimension(
                (U8*)GetImage(popup_key->content_highlight_id),
                &glyph_width,
                &glyph_height);
            
            char_x = 0;
            char_y = 0;

        }
        v->popup_hint.char_x = char_x;
        v->popup_hint.char_y = char_y;
        gui_virtual_keyboard_redraw_popup_hint(v, MMI_TRUE);
    }
    else
    {
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }
#endif /* __MMI_VK_POPUP_HINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_unselect_key_from_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_show_unselect_key_from_cache(
             gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key.is_key_cached == MMI_FALSE)
    {
        return;
    }

#ifdef __MMI_VK_POPUP_HINT__
    gui_virtual_keyboard_clear_normal_popup_from_cache(v);
#endif /* __MMI_VK_POPUP_HINT__ */
    x1 = v->selected_key.x;
    y1 = v->selected_key.y;
    x2 = x1 + v->selected_key.width - 1;
    y2 = y1 + v->selected_key.height - 1;

    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    if (v->selected_key.key_bitmap.buf_ptr != NULL)
    {
        gdi_image_cache_bmp_draw(x1, y1, &v->selected_key.key_bitmap);
        mmi_frm_scrmem_free(v->selected_key.key_bitmap.buf_ptr);
        v->selected_key.key_bitmap.buf_ptr = NULL;
    }

    gdi_layer_pop_clip();
    gui_unlock_double_buffer();

#ifdef __MMI_VK_POPUP_HINT__
    if (v->popup_hint.is_key_cached == MMI_TRUE)
    {
        if (x1 >= v->popup_hint.x)
        {
            x1 = v->popup_hint.x;
        }
        y1 = v->popup_hint.y;
        if (x2 < v->popup_hint.x + v->popup_hint.width - 1)
        {
            x2 = v->popup_hint.x + v->popup_hint.width - 1;
        }
    }
#endif /* __MMI_VK_POPUP_HINT__ */
    gui_BLT_double_buffer(x1, y1, x2, y2);

    v->selected_key.is_key_cached = MMI_FALSE;
}


#ifdef __MMI_VK_POPUP_HINT__
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_hide_cursor_dummy_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [IN]
 *  y1          [IN]
 *  x2          [IN]
 *  y2          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_hide_cursor_dummy_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x1);
    UI_UNUSED_PARAMETER(y1);
    UI_UNUSED_PARAMETER(x2);
    UI_UNUSED_PARAMETER(y2);
}
#endif /* __MMI_VK_POPUP_HINT__ */
/***************************************************************************** 
* Global Variable
*****************************************************************************/
UI_virtual_keyboard_theme *current_virtual_keyboard_theme = NULL;

/***************************************************************************** 
* Global Function
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_flags_on
 * DESCRIPTION
 *  turn on flag of virtual keyboard
 * PARAMETERS
 *  v           [IN]    pointer of virtual keyboard
 *  flag        [IN]    flag to bet set on
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_flags_on(gui_virtual_keyboard_struct *v, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->flags |= flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_flags_off
 * DESCRIPTION
 *  turn off flag of virtual keyboard
 * PARAMETERS
 *  v           [IN]    pointer of virtual keyboard
 *  flag        [IN]    flag to bet set on
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_flags_off(gui_virtual_keyboard_struct *v, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->flags &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_virtual_keyboard
 * DESCRIPTION
 *  Create virtual keyboard object
 * PARAMETERS
 *  v               [IN/OUT]    Is the virtual keyboard object
 *  x               [IN]        Is the left-top cornerd
 *  y               [IN]        Is the left-top cornerd
 *  lang_type       [IN]        Is language type to be used for the keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_create(
      gui_virtual_keyboard_struct *v,
      S32 x,
      S32 y,
      S32 width,
      S32 height,
      U16 key_count,
      gui_virtual_keyboard_key_struct_p key_list,
      MMI_BOOL is_venus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    U16 key_char;
    gui_virtual_keyboard_pen_enum key_event;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;
    v->flags = 0;
    v->key_count = key_count;
    v->key_list = key_list;

    v->bg_id = NULL;
    v->key_attribute.text_align = GUI_VIRTUAL_KEYBOARD_TEXT_ALIGN_CENTER;
    v->key_attribute.is_round_rect = MMI_FALSE;
	v->key_down_accepted = MMI_FALSE; 
	#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
        v->longtap_popup_state = MMI_FALSE; 
    #endif 
	#ifdef __MMI_VK_POPUP_HINT__
       v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_START;
    #endif 

#if defined(__MMI_VUI_ENGINE__)
    v->is_venus_vk = is_venus;
#endif
    v->key_down_accepted = MMI_FALSE;
    gui_virtual_keyboard_clear_selected_key(v);
#ifdef __MMI_VK_POPUP_HINT__
    v->popup_hint.hide_cursor_callback = gui_virtual_keyboard_hide_cursor_dummy_function;
    v->popup_hint.blink_cursor_callback = UI_dummy_function;
    v->popup_hint.is_cursor_stop = MMI_FALSE;
#endif

    /* clear all info of disable_key, dead_key & kept_key */
    memset(&v->disable_keys, 0, sizeof(v->disable_keys));
    memset(&v->dead_keys, 0, sizeof(v->dead_keys));
    v->disable_keys.disabled_symbols[0] = GUI_VKBD_PEN_NONE;
    

    /* reset kept key */
    v->kept_key.is_down_kept = MMI_FALSE;
    v->kept_key.index = GUI_VIRTUAL_KEYBOARD_INVALID_KEY_INDEX;

    /* reset display area */
    memset(&v->display_area, 0, sizeof(v->display_area));
    v->display_area.index = GUI_VIRTUAL_KEYBOARD_INVALID_KEY_INDEX;

    gui_virtual_keyboard_set_current_theme(v);    

    v->hide_callback = gui_virtual_keyboard_default_hide_function;
    v->display_callback = gui_virtual_keyboard_default_display_callback_function;
    gui_virtual_keyboard_set_flags_on(v, GUI_VIRTUAL_KEYBOARD_STATE_ACTIVE);
    
    /*
     * if we find one key not have normal background image, we will
     * not set GUI_VIRTUAL_KEYBOARD_DRAW_KEY_BY_IMAGE and use code
     * to draw every key's shape
     */
    gui_virtual_keyboard_set_flags_on(v, GUI_VIRTUAL_KEYBOARD_DRAW_KEY_BY_IMAGE);
    for (i = 0; i < v->key_count; i++)
    {
        key = v->key_list[i];
        /* parse the key content from content */
        key_char = (U16)GUI_VK_GET_KEY_CHAR(key.content);
        key_event = GUI_VK_GET_KEY_EVENT(key.content);

        /* assert this key's content is not NULL */
        MMI_DBG_ASSERT(!((key_char == 0) &&
                         (key_event == GUI_VKBD_PEN_NONE ||
                          key_event >= GUI_VKBD_PEN_MAX)));
        /* find GUI_VKBD_PEN_DISPLAY_AREA key's index */
        if (key_event == GUI_VKBD_PEN_DISPLAY_AREA)
        {
            v->display_area.index = i;
        }

        if (key.bg_id == NULL)
        {
            gui_virtual_keyboard_set_flags_off(
                v,
                GUI_VIRTUAL_KEYBOARD_DRAW_KEY_BY_IMAGE);
        }
    }
#if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        
    }
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_close
 * DESCRIPTION
 *  Release the resource used by virtual keyboard object
 * PARAMETERS
 *  v               [IN/OUT]    Is the virtual keyboard object
 * RETURNS
 *  void
 * REMARKS
 *  Used in exit function or exit category function
 *****************************************************************************/
void gui_virtual_keyboard_close(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    if (v->flags & GUI_VIRTUAL_KEYBOARD_STATE_ACTIVE)
    {
        gui_virtual_keyboard_clear_selected_key(v);
    #ifdef __MMI_VK_POPUP_HINT__
        v->popup_hint.hide_cursor_callback = gui_virtual_keyboard_hide_cursor_dummy_function;
        v->popup_hint.blink_cursor_callback = UI_dummy_function;
        v->popup_hint.is_cursor_stop = MMI_FALSE;
    #endif

        gui_virtual_keyboard_set_flags_off(v, GUI_VIRTUAL_KEYBOARD_STATE_ACTIVE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_move
 * DESCRIPTION
 *  Move the virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  x       [IN]        Is the left-top cornerd x position
 *  y       [IN]        Is the left-top cornerd y position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_move(gui_virtual_keyboard_struct *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->x = x;
    v->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show
 * DESCRIPTION
 *  Show the virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_show(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    x1 = v->x;
    y1 = v->y;
    x2 = v->x + v->width - 1;
    y2 = v->y + v->height - 1;

 
 
  //  gui_vk_clear_cache(v);  /* Because the vk type is updated between pen down and pen up event so need to discard cache in between MAUI_02652563 */ 
    

#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
#if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
#endif
    {
        if (!wgui_is_wallpaper_on_bottom())
        {
            gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
        }
    }
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    if (v->hide_callback != NULL)
    {
        v->hide_callback(x1, y1, x2, y2);
    }

    /* show background */
    if (v->bg_id != NULL)
    {
        gui_virtual_keyboard_show_image(v, (S32)v->x, (S32)v->y, (PU8)get_image(v->bg_id), (gdi_handle)gdi_act_layer);
    }

    /* display keys on virtual keyboard */
    for (i = 0; i < v->key_count; i++)
    {
        /* when y <0, it is the popup and longtap popup key. */
        if (v->key_list[i].y >= 0)
        gui_virtual_keyboard_draw_key(v, i);
    }

#ifdef __MMI_VK_POPUP_HINT__
#if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {

    }
    else
#endif
    {
    if (v->key_down_accepted == MMI_TRUE)
    {
        #if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                gui_virtual_keyboard_print_longtap_popup_characters(v);
            }
            else
        #endif
            {
                gui_virtual_keyboard_redraw_popup_hint(v, MMI_TRUE);
            }
        
        }
    }
#endif /* __MMI_VK_POPUP_HINT__ */

    gui_pop_clip();

#if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
#endif
    {
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    if (!wgui_is_wallpaper_on_bottom())
    {
            gdi_pop_and_restore_alpha_blending_source_layer();
    }
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
}
}



/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  v               [IN/OUT]        Is the virtual keyboard object
 *  x               [IN]            x pos of pen
 *  y               [IN]            y pos of pen
 *  pen_event       [IN]            pen event
 *  key_event       [OUT]           key event of virtual keyboard
 *  key_param       [OUT]           key parameter
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_virtual_keyboard_translate_pen_event(
          gui_virtual_keyboard_struct *v,
          S16 x,
          S16 y,
          mmi_pen_event_type_enum pen_event,
          gui_virtual_keyboard_pen_enum *key_event,
          gui_pen_event_param_struct *key_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    UI_character_type temp_char;
    gui_virtual_keyboard_pen_enum temp_event = GUI_VKBD_PEN_NONE;
    S16 key_index = 0;
    gui_virtual_keyboard_event_enum event = GUI_VIRTUAL_KEYBOARD_EVENT_START;
    U32 event_ret;
    gui_virtual_keyboard_key_struct key;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *key_event = GUI_VKBD_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(key_param);

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            v->key_down_accepted = MMI_FALSE;

            #ifdef __MMI_VK_LONGTAP_POPUP_HINT__
            /* set the long tap pop-up state as inactive */
            gui_virtual_keyboard_set_long_tap_popup_deactive(v);
            #endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */

            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
            {
                if (gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
                {
                    /* get the selected key */
                    gui_virtual_keyboard_get_selected_key(v, key_index, &temp_char, &temp_event);
                    if ((temp_event == GUI_VKBD_PEN_NONE) ||
                        gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index))
                    {
                        /* Do nothing */
                    }
                    else
                    {
                        v->key_down_accepted = MMI_TRUE;
                        
                        /* Providing the touch feedback for down event */
                        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                        
                        gui_start_timer(GUI_VK_LONG_TAP_TIMER, gui_vk_longtap_timer_handler);

                        if (temp_event == GUI_VKBD_PEN_SPACE)
                        {
                            temp_event = GUI_VKBD_PEN_CHAR_I;
                            temp_char = (UI_character_type) ' ';
                        }
                        else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                        {
                            temp_event = GUI_VKBD_PEN_NONE;
                        }

                        *key_event = temp_event;

                        if (v->event_callback)
                        {
                            event = v->event_callback(temp_event, (S32)temp_char, (U32)&event_ret);                            
                        }

                    #if defined(__MMI_VK_POPUP_HINT__)
                        if (event == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                        {
                            v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE;
                            v->popup_hint.multitap_event = event_ret;
                        }
                        if (event == GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE)
                        {
                            v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE;
                            /* set longtap pop-up active */
                            //gui_virtual_keyboard_set_long_tap_popup_active(v);
                        }
                    #endif /* defined(__MMI_VK_POPUP_HINT__) */
                        gui_virtual_keyboard_cache_and_show_selected_key(v);


                        if (*key_event == GUI_VKBD_PEN_CHAR_I)
                        {
                            MMI_DBG_ASSERT(temp_char != 0);
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                        }
                        /* 
                         * If Pen Down and Pen Up comes together, we should temporarily suspend MMI task. 
                         * Otherwise, user can not see pen down due to delayed LCM update.
                         */
                    #if defined(__MMI_VUI_ENGINE__)
                        if (!v->is_venus_vk)
                    #endif
                        {
                            //kal_sleep_task(kal_milli_secs_to_ticks(30));
                        }
                    }
                }
            }
            else
            {
                return MMI_FALSE;
            }
            break;

        case MMI_PEN_EVENT_MOVE:
            if (v->key_down_accepted)
            {
            #ifdef __MMI_VK_LONGTAP_POPUP_HINT__
                if (gui_virtual_keyboard_get_long_tap_popup_state(v))
                {
                    gui_cancel_timer(gui_vk_longtap_timer_handler);
                    
                    #if defined(__MMI_VUI_ENGINE__)
                    if (!v->is_venus_vk)
                    #endif
                    {
                        gui_lock_double_buffer();
                    }
                    
                    /* stop cursor */
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
                    #endif
                    
                    gui_virtual_keyboard_longtap_popup_translate_pen_event(v, x, y, pen_event);
                    
                    #if defined(__MMI_VUI_ENGINE__)
                    if (!v->is_venus_vk)
                    #endif
                    {
                        gui_unlock_double_buffer();
                    }
                }
                else
            #endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */
                {
                    /* if pen is in selected key's area, do nothing */
                    if (v->selected_key.is_key_cached == MMI_TRUE &&
                        PEN_CHECK_BOUND(
                            x,
                            y,
                            v->selected_key.x,
                            v->selected_key.y,
                            v->selected_key.width,
                            v->selected_key.height))
                    {
                        /* if is in enlarged icon, do nothing */
                        break;
                    }
                    else
                    {
                        gui_cancel_timer(gui_vk_longtap_timer_handler);
                        if (v->vk_attr & MMI_VK_TYPE_ALPHANUMERIC)
                        {
                        }
                        else
                        {
                            if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) &&
                                gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
                            {
                                if (key_index != v->selected_key.index)
                                {
                                    #if defined(__MMI_VUI_ENGINE__)
                                    if (!v->is_venus_vk)
                                    #endif
                                    {
                                        gui_lock_double_buffer();
                                    }

                                    gui_virtual_keyboard_show_unselect_key_from_cache(v);
                                    gui_virtual_keyboard_get_selected_key(v, key_index, &temp_char, &temp_event);
                                    if (!((temp_event == GUI_VKBD_PEN_NONE) ||
                                          gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index)))
                                    {
                                        gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
                                        #if defined(__MMI_VK_POPUP_HINT__)
                                        v->popup_hint.is_cursor_stop = MMI_FALSE;
                                        #endif /* defined(__MMI_VK_POPUP_HINT__) */
                                        gui_virtual_keyboard_cache_and_show_selected_key(v);
                                    }

                                    #if defined(__MMI_VUI_ENGINE__)
                                    if (!v->is_venus_vk)
                                    #endif
                                    {
                                        gui_unlock_double_buffer();
                                    }
                                }
                            }
                            else
                            {
                                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                                gui_virtual_keyboard_clear_selected_key(v);
                            }
                        }
                    }
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
        #ifdef __MMI_VK_LONGTAP_POPUP_HINT__
            gui_cancel_timer(gui_vk_longtap_timer_handler);
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                if ((v->popup_hint.longtap_hint_details.highlighted_index >= 0) &&
                    (v->popup_hint.longtap_hint_details.highlighted_index <= v->popup_hint.longtap_hint_details.num - 1))
                {
                    S16 actual_key_index = v->popup_hint.longtap_hint_details.key_index_array[v->popup_hint.longtap_hint_details.highlighted_index];/*gui_virtual_keyboard_get_longtap_popup_actaual_key_index(
                                            v,
                                            v->popup_hint.longtap_hint_details.highlighted_index);*/

                    gui_virtual_keyboard_selected_key_struct backup_selected_key = v->selected_key;

                    if (gui_virtual_keyboard_is_disabled_key(v, actual_key_index))
                    {
                        /*Do nothing*/
                    }
                    else
                    {
                        gui_virtual_keyboard_get_selected_key(
                            v, 
                            actual_key_index, 
                            &temp_char, 
                            &temp_event);

                        if (temp_event == GUI_VKBD_PEN_SPACE)
                        {
                            temp_event = GUI_VKBD_PEN_CHAR_I;
                            temp_char = (UI_character_type) ' ';
                        }
                        else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                        {
                            temp_event = GUI_VKBD_PEN_NONE;
                        }

                        *key_event = temp_event;

                        if (*key_event == GUI_VKBD_PEN_CHAR_I)
                        {
                            MMI_DBG_ASSERT(temp_char != 0);
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                        }

                        if (v->event_callback != NULL)
                        {
                            event = v->event_callback(temp_event, (S32)temp_char, (U32)&event_ret);
                        }
                        v->selected_key = backup_selected_key;
                    }
                }

            #if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
                if (v->is_venus_vk)
                {
                    //vadp_p2v_close_virtual_keyboard_popup();
                }
            #endif

                gui_lock_double_buffer();
                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                gui_virtual_keyboard_clear_selected_key(v);
                gui_virtual_keyboard_set_long_tap_popup_deactive(v);
                gui_unlock_double_buffer();
                gdi_lcd_repaint_all();
            }
            else
        #endif
            {
                if (v->key_down_accepted)
                {
                    if ((gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index)) ||
                        (v->vk_attr & MMI_VK_TYPE_ALPHANUMERIC))
                    {
                        if (v->vk_attr & MMI_VK_TYPE_ALPHANUMERIC|MMI_VK_TYPE_QWERTY)
                        {
                            key_index = v->selected_key.index; 
                        }
                    
                        MMI_DBG_ASSERT(key_index == v->selected_key.index);
                        if (v->selected_key.index == -1 || gui_virtual_keyboard_is_disabled_key(v, key_index))
                        {
                            /*Do nothing*/
							gui_virtual_keyboard_show_unselect_key_from_cache(v);
                            gui_virtual_keyboard_clear_selected_key(v);
                        }
                        else
                        {
                            if (key_index != v->selected_key.index)
                            {
                               gui_virtual_keyboard_show_unselect_key_from_cache(v);
                               gui_virtual_keyboard_clear_selected_key(v);
                            }
                            gui_virtual_keyboard_get_selected_key(v, key_index, &temp_char, &temp_event);
                            if (temp_event == GUI_VKBD_PEN_SPACE)
                            {
                                temp_event = GUI_VKBD_PEN_CHAR_I;
                                temp_char = (UI_character_type) ' ';
                            }
                            else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                            {
                                temp_event = GUI_VKBD_PEN_NONE;
                            }

                            *key_event = temp_event;

                            if (*key_event == GUI_VKBD_PEN_CHAR_I)
                            {
                                MMI_DBG_ASSERT(temp_char != 0);
                                GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                            }

                            if (v->event_callback != NULL)
                            {
                                event = v->event_callback(temp_event, (S32)temp_char, (U32)&event_ret);
                            }
                            if (event == GUI_VIRTUAL_KEYBOARD_EVENT_KEEP_DOWN_STATE)
                            {
                                MMI_DBG_ASSERT(v->kept_key.is_down_kept == MMI_FALSE);
                                v->kept_key.index = key_index;
                                v->kept_key.is_down_kept = MMI_TRUE;
                                gui_lock_double_buffer();
                                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                                gui_virtual_keyboard_draw_key(v, key_index);
                                gui_unlock_double_buffer();
                                gui_BLT_double_buffer(
                                    v->x + v->key_list[key_index].x,
                                    v->y + v->key_list[key_index].y,
                                    v->x + v->key_list[key_index].x + v->key_list[key_index].width - 1,
                                    v->y + v->key_list[key_index].y + v->key_list[key_index].height - 1);
                                break;
                            }
                            else if (event == GUI_VIRTUAL_KEYBOARD_EVENT_CLEAR_DOWN_STATE)
                            {
                                MMI_DBG_ASSERT(v->kept_key.is_down_kept == MMI_TRUE);
                                v->kept_key.index = GUI_VIRTUAL_KEYBOARD_INVALID_KEY_INDEX;
                                v->kept_key.is_down_kept = MMI_FALSE;
                                gui_lock_double_buffer();
                                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                                gui_virtual_keyboard_draw_key(v, key_index);
                                gui_unlock_double_buffer();
                                gui_BLT_double_buffer(
                                    v->x + v->key_list[key_index].x,
                                    v->y + v->key_list[key_index].y,
                                    v->x + v->key_list[key_index].x + v->key_list[key_index].width - 1,
                                    v->y + v->key_list[key_index].y + v->key_list[key_index].height - 1);
                                break;
                            }
                        }
                    }
                    gui_virtual_keyboard_show_unselect_key_from_cache(v);
                gui_virtual_keyboard_clear_selected_key(v);
                }
            }

        #if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
            if (v->is_venus_vk)
            {
                //vadp_p2v_close_virtual_keyboard_popup();
            }
        #endif
        #if defined(__MMI_VK_POPUP_HINT__)
            v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_START;
            v->popup_hint.multitap_event = 0;
            
            if (v->popup_hint.blink_cursor_callback != NULL)
            {
                if ((gui_virtual_keyboard_is_cursor_stopped_by_vk) &&
                    (v->popup_hint.is_cursor_stop == MMI_TRUE))
                {
                    v->popup_hint.blink_cursor_callback();
                    gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
                    v->popup_hint.is_cursor_stop = MMI_FALSE;
                }
            }

        #endif /* defined(__MMI_VK_POPUP_HINT__) */
            v->key_down_accepted = MMI_FALSE;
			need_to_emit_signal = MMI_FALSE ;
			is_backspace_down_state = MMI_FALSE ;
            break;

        case MMI_PEN_EVENT_ABORT:
            gui_virtual_keyboard_show_unselect_key_from_cache(v);
        #if defined(__MMI_VK_POPUP_HINT__)
            v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_START;
            v->popup_hint.multitap_event = 0;
        #endif /* defined(__MMI_VK_POPUP_HINT__) */

        #if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
            if (v->is_venus_vk)
            {
            //vadp_p2v_close_virtual_keyboard_popup();
            }
        #endif
            v->key_down_accepted = MMI_FALSE;
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index);
            key = v->key_list[key_index];

            /* parse the key content from content */
            temp_char = (UI_character_type)GUI_VK_GET_KEY_CHAR(key.content);
            temp_event = GUI_VK_GET_KEY_EVENT(key.content);

            if (v->key_down_accepted)
            {
                gui_cancel_timer(gui_vk_longtap_timer_handler);
                
                if (gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
                {
                    if (v->vk_attr & MMI_VK_TYPE_ALPHANUMERIC)
                    {
                        key_index = v->selected_key.index; 
                    }

                   /*  gui_virtual_keyboard_get_selected_key(v, key_index, &temp_char, &temp_event); */
                    if (temp_event == GUI_VKBD_PEN_SPACE)
                    {
                        temp_event = GUI_VKBD_PEN_CHAR_I;
                        temp_char = (UI_character_type) ' ';
                    }
                    else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                    {
                        temp_event = GUI_VKBD_PEN_NONE;
                    }

                    *key_event = temp_event;

                    if (*key_event == GUI_VKBD_PEN_CHAR_I)
                    {
                        MMI_DBG_ASSERT(temp_char != 0);
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                    }
                }

            #if defined(__MMI_VK_POPUP_HINT__)
                if (v->popup_hint.popup_state != GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                {
                #ifdef __MMI_VK_LONGTAP_POPUP_HINT__
                    U8 num = 0;

                    /* set longtap pop-up deactive */
                    gui_virtual_keyboard_set_long_tap_popup_deactive(v);
                    num = gui_virtual_keyboard_get_num_of_popup_chars(v);
                    if (num >= 1)
                    {
                            /* Providing the touch feedback for long tap event */
                            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
                            
						gui_virtual_keyboard_handle_long_tap_popup(v);
					}
                #endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */
                }
            #endif /* defined(__MMI_VK_POPUP_HINT__) */
            }
            break;
        case MMI_PEN_EVENT_REPEAT:
            if (v->key_down_accepted)
            {
            #ifdef __MMI_VK_LONGTAP_POPUP_HINT__
                if (gui_virtual_keyboard_get_long_tap_popup_state(v))
                {
                    gui_cancel_timer(gui_vk_longtap_timer_handler);
                    /* stop cursor */
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
                    #endif /* 0 */
                    
                    //gui_virtual_keyboard_longtap_popup_translate_pen_event(v, x, y, pen_event);
                }
                else
            #endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */
                {
                    if (gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
                    {
                        gui_virtual_keyboard_selected_key_struct backup_selected_key = v->selected_key;

                        if (v->vk_attr & MMI_VK_TYPE_ALPHANUMERIC)
                        {
                            key_index = v->selected_key.index; 
                        }

                        gui_virtual_keyboard_get_selected_key(v, key_index, &temp_char, &temp_event);
                        if (temp_event == GUI_VKBD_PEN_SPACE)
                        {
                            temp_event = GUI_VKBD_PEN_CHAR_I;
                            temp_char = (UI_character_type) ' ';
                        }
                        else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                        {
                            temp_event = GUI_VKBD_PEN_NONE;
                        }

                        *key_event = temp_event;

                        if (*key_event == GUI_VKBD_PEN_CHAR_I)
                        {
                            MMI_DBG_ASSERT(temp_char != 0);
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                        }

                        if (v->event_callback)
                        {
                            event = v->event_callback(temp_event, (S32)temp_char, (U32)&event_ret);                            
                        }
                    
                    #if defined(__MMI_VK_POPUP_HINT__)
                        if (event == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                        {
                            v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE;
                            v->popup_hint.multitap_event = event_ret;
                        }

                    
                        if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                        {
                            //void (*backup_blink_cursor_callback) (void);
                            //void (*backup_hide_cursor_callback) (void);
                            
                            /* backing up the callback for restoration later on */
                            //backup_blink_cursor_callback = v->popup_hint.blink_cursor_callback;
                            //backup_hide_cursor_callback = v->popup_hint.hide_cursor_callback;
            
                            /* To avoid blinking of cursor while we are in between the
                             * cache ignoring and recaching
                             */
                            //v->popup_hint.blink_cursor_callback = NULL;
                            //v->popup_hint.hide_cursor_callback = NULL;

                            #if defined(__MMI_VUI_ENGINE__)
                            if (!v->is_venus_vk)
                            #endif
                            {
                                gui_lock_double_buffer();
                            }
                            gui_virtual_keyboard_show_unselect_key_from_cache(v);
                            gui_virtual_keyboard_cache_and_show_selected_key(v);
                            
                            #if defined(__MMI_VUI_ENGINE__)
                            if (!v->is_venus_vk)
                            #endif
                            {
                                gui_unlock_double_buffer();
                            }
                            
                            /* restoring the blink cursor callback */
                            //v->popup_hint.blink_cursor_callback = backup_blink_cursor_callback;
                            //uv->popup_hint.hide_cursor_callback = backup_hide_cursor_callback;
                        }
                    #endif /* defined(__MMI_VK_POPUP_HINT__) */

                        v->selected_key = backup_selected_key;

                        
                    }
                }
            }            /* Do nothing */
			else
			{
				if (need_to_emit_signal == MMI_TRUE) 
				{
					//need_to_emit_signal = MMI_FALSE ;
					gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index);
					gui_virtual_keyboard_get_selected_key(v, key_index, &temp_char, &temp_event);
					if (((temp_event == GUI_VKBD_PEN_BAKSPACE) ||(temp_event == GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE ))&& !(gui_virtual_keyboard_is_disabled_key(v, key_index)))
					{
						*key_event = temp_event;
					}
				}
			}
			if (((temp_event == GUI_VKBD_PEN_BAKSPACE) ||(temp_event == GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE ))&& !(gui_virtual_keyboard_is_disabled_key(v, key_index)))
			{
				is_backspace_down_state = MMI_TRUE ;
			}
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_current_character
 * DESCRIPTION
 *  This API is only provided for category to get character before IME.
 *  It will only return that character of pen's position
 * PARAMETERS
 *  v               [IN/OUT]         
 *  x               [IN]        
 *  y               [IN]        
 *  ch              [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_virtual_keyboard_get_current_character(
          gui_virtual_keyboard_struct *v,
          S16 x,
          S16 y,
          UI_character_type *ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    UI_character_type key_char;
    gui_virtual_keyboard_pen_enum key_event;
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
    {
        if (MMI_TRUE == gui_virtual_keyboard_translate_pen_position(v, x, y, &index))
        {
            key = v->key_list[index];

            if (!gui_virtual_keyboard_is_disabled_key(v, index))
            {
                /* parse the key content from content */
                key_char = (UI_character_type)GUI_VK_GET_KEY_CHAR(key.content);
                key_event = GUI_VK_GET_KEY_EVENT(key.content);
                if (key_char != 0 && key_event == 0)
                {
                    *ch = key_char;
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_theme
 * DESCRIPTION
 *  Applies the current theme for virtual keyboard.
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 *  t       [IN]            theme pointer of virtual keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_theme(
      gui_virtual_keyboard_struct *v,
      UI_virtual_keyboard_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(t != NULL);
    v->theme = t;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_current_theme
 * DESCRIPTION
 *  Applies the current theme for virtual keyboard.
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_current_theme(
             gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(current_virtual_keyboard_theme != NULL);
    v->theme = current_virtual_keyboard_theme;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_bg
 * DESCRIPTION
 *  set the background of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 *  bg_id   [IN]            background image id of the virtual keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_bg(gui_virtual_keyboard_struct *v, U16 bg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->bg_id = bg_id;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_key_attribute
 * DESCRIPTION
 *  set text align of a key of virtual keyboard
 * PARAMETERS
 *  v               [IN/OUT]        Is the virtual keyboard pointer
 *  key_attribute   [IN]            attribute of key
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_key_attribute(
      gui_virtual_keyboard_struct *v,
      gui_virtual_keyboard_key_attribute key_attribute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->key_attribute = key_attribute;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_dead_keys
 * DESCRIPTION
 *  set dead characters of one specific language's virtual keyboard
 * PARAMETERS
 *  v               [IN/OUT]        Is the virtual keyboard pointer
 *  dead_chars      [IN]            dead characters of one language
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_dead_keys(
      gui_virtual_keyboard_struct *v,
      const UI_character_type *dead_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    gui_virtual_keyboard_key_struct key;
    UI_character_type key_char;
    v->dead_keys.count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    for (i = 0; dead_chars[i] != NULL; i++)
    {
        MMI_DBG_ASSERT(i < GUI_VIRTUAL_KEYBOARD_MAX_DEAD_KEYS);
        for (j = 0; j < v->key_count; j++)
        {
            /* find the dead key in key_list and record it's index */
            key = v->key_list[j];
            key_char = (UI_character_type)GUI_VK_GET_KEY_CHAR(key.content);
            if (key_char == dead_chars[i])
            {
                v->dead_keys.index[v->dead_keys.count] = j;
                v->dead_keys.count++;
                break;
            }
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_allowed_characters
 * DESCRIPTION
 *  Only the allowd characters can be input on keyboard.
 *  This function and gui_virtual_board_set_disable_list() are mutually-exclusive.
 *  
 *  Control keys such as GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_SHOW... are enabled because
 *  they are not related to character insertion.
 *  
 *  `allowed_characters' may contain '-' for consecutive characters
 *  (Ex. 'a-z' for characters from a to z.)
 *  If we want to accept "-", please write it as '\-'.
 *  For example, '\-0-9.' represents "-0123456789."
 *  
 *  Example of valid characters in email addresss:
 *  wgui_virtual_keyboard_set_allowed_characters((const UI_character_type *) L"+_\\-.@A-Za-z0-9");
 *  (it is not a complete list of all characters allowed in RFC, but it satisfies almost all cases)
 * PARAMETERS
 *  v                   [IN/OUT]    Virtual keyboard
 *  allowed_chars       [IN]        Allowed characters
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_allowed_characters(
      gui_virtual_keyboard_struct *v,
      const UI_character_type *allowed_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->disable_keys.allowed_chars = allowed_chars;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_disable_list
 * DESCRIPTION
 *  Disable some keys on keyboard.
 *  This function and gui_virtual_keyboard_set_allowed_characters()
 *  are mutually-exclusive.
 * PARAMETERS
 *  v                   [IN/OUT]    Virtual keyboard
 *  disabled_chars      [IN]        Null-terminated array of disabled unicode chars
 *  disabled_symbols    [IN]        Ended by GUI_VKBD_PEN_NONE
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_disable_list(
      gui_virtual_keyboard_struct *v,
      const UI_character_type *disabled_chars,
      const gui_virtual_keyboard_pen_enum *disabled_symbols)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    /* Setup v->disable_keys.disabled_chars[] */
    for (i = 0; i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
    {
        if (!disabled_chars[i])
        {
            break;
        }

        v->disable_keys.disabled_chars[i] = disabled_chars[i];
    }

    MMI_DBG_ASSERT(i <= GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS ||
                   !disabled_chars[i]);
    v->disable_keys.disabled_chars[i] = 0;

    /* Setup v->disable_keys.disabled_symbols[] */
    for (i = 0; i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
    {
        if (disabled_symbols[i] == GUI_VKBD_PEN_NONE)
        {
            break;
        }

        v->disable_keys.disabled_symbols[i] = disabled_symbols[i];
    }

    MMI_DBG_ASSERT(i <= GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS ||
                   (disabled_symbols[i] == GUI_VKBD_PEN_NONE));
    v->disable_keys.disabled_symbols[i] = GUI_VKBD_PEN_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_display_area
 * DESCRIPTION
 *  Update text displayed on display area
 * PARAMETERS
 *  v           [IN/OUT]        
 *  string      [IN]        String to be displayed in display area
 *  redraw      [IN]        Whether to redraw the keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_set_display_area(
      gui_virtual_keyboard_struct *v,
      const U8 *string,
      MMI_BOOL redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0, glyph_width, glyph_height;
    gdi_handle abm_src_layer, act_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    if (v->display_area.index >= 0 && v->display_area.index < v->key_count)
    {
        key = v->key_list[v->display_area.index];
        MMI_DBG_ASSERT((U16)(key.content >> 16) == GUI_VKBD_PEN_DISPLAY_AREA);
        mmi_ucs2ncpy(
            (S8*)v->display_area.text,
            (const S8*)string,
            GUI_VIRTUAL_KEYBOARD_MAX_DISPLAY_AREA_TEXT_LEN);
    }

    /* redraw the area only */
    if (redraw)
    {
        gdi_get_alpha_blending_source_layer(&abm_src_layer);
        gdi_layer_get_active(&act_layer);

        x1 = v->x + key.x;
        y1 = v->y + key.y;
        x2 = x1 + key.width - 1;
        y2 = y1 + key.height - 1;
        gui_set_font(v->theme->text_font);

        gui_lock_double_buffer();
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);

        if (abm_src_layer ==  act_layer)
        {
            if (v->hide_callback != NULL)
            {
                v->hide_callback(x1, y1, x2, y2);
            }
        }

        /* if use image to draw key's background */
        if (v->flags & GUI_VIRTUAL_KEYBOARD_DRAW_KEY_BY_IMAGE)
        {
            gui_show_image(x1, y1, (PU8)get_image(key.bg_id));
        }
        else /* draw key's shape by code */
        {
            gui_virtual_keyboard_draw_key_shape(
                v,
                x1,
                y1,
                key.width,
                key.height,
                v->theme->key_down_filler->c,
                v->theme->key_down_text_color);
        }
        gui_set_text_color(v->theme->disp_area_text_color);
        gui_measure_string(
            (UI_string_type)v->display_area.text,
            &glyph_width,
            &glyph_height);
        gui_move_text_cursor(
            x1 + VKBD_DIFF_HALF(key.width, glyph_width),
            y1 + VKBD_DIFF_HALF(key.height, glyph_height));
        gui_print_text((UI_string_type)v->display_area.text);

        gui_pop_clip();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_hide_callback
 * DESCRIPTION
 *  Register hide callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the hide callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_hide_callback(
      gui_virtual_keyboard_struct *v,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    if (f != NULL)
    {
        v->hide_callback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_display_callback
 * DESCRIPTION
 *  Register display callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the display callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_display_callback(
      gui_virtual_keyboard_struct *v,
      gui_virtual_keyboard_display_callback_func_ptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->display_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_event_callback
 * DESCRIPTION
 *  Register event callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the event callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_event_callback(
      gui_virtual_keyboard_struct *v,
      gui_virtual_keyboard_event_callback_func_ptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->event_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_key_info
 * DESCRIPTION
 *  Get key position info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_get_key_info(gui_virtual_keyboard_struct *v, gui_virtual_keyboard_key_pos_info_struct_p info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < v->key_count; i++)
    {
        /* when y <0, it is the popup and longtap popup key. */
        if ((v->key_list[i].content == info->key_value) && (v->key_list[i].y >= 0))
        {
            info->x = v->key_list[i].x + v->x;
            info->y = v->key_list[i].y + v->y;
            info->width = v->key_list[i].width;
            info->height = v->key_list[i].height;            
            break;
        }
    }
    

}

#ifdef __MMI_VK_POPUP_HINT__
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_hide_cursor_callback
 * DESCRIPTION
 *  Register hide cursor callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the hide cursor callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_hide_cursor_callback(
      gui_virtual_keyboard_struct *v,
      MMI_BOOL (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->popup_hint.hide_cursor_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_blink_cursor_callback
 * DESCRIPTION
 *  Register blink cursor callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the hide cursor callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_blink_cursor_callback(
      gui_virtual_keyboard_struct *v,
      void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->popup_hint.blink_cursor_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_recover_covered_area
 * DESCRIPTION
 *  recover area that popup hint covered. It may happen that the other 
 *  components may be redrawn, so we should not take the pop-up from cache
 *  Instead we should redraw the region and retake the cahche.
 * PARAMETERS
 *  v               [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_recover_covered_area(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key.is_key_cached == MMI_FALSE)
    {
        return;
    }

#if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        return;
    }
#endif

    if (v->key_down_accepted == MMI_TRUE)
    {
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
        #endif
    
        if (v->popup_hint.is_key_cached == MMI_TRUE)
        {
            //void (*backup_blink_cursor_callback) (void);
            //void (*backup_hide_cursor_callback) (void);
            
            /* backing up the callback for restoration later on */
            //backup_blink_cursor_callback = v->popup_hint.blink_cursor_callback;
            //backup_hide_cursor_callback = v->popup_hint.hide_cursor_callback;
            
            /* To avoid blinking of cursor while we are in between the
             * cache ignoring and recaching
             */
            //v->popup_hint.blink_cursor_callback = NULL;
            //v->popup_hint.hide_cursor_callback = NULL;
            
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                S16 backup_highlighted_index = v->popup_hint.longtap_hint_details.highlighted_index;
                /* unselect the key and pop up */
                gui_virtual_keyboard_show_unselect_key_from_cache(v);
    
                /* redo the cache and printing of key*/
                gui_virtual_keyboard_cache_and_show_selected_key(v);
                
                /* remove the previous longtap pop-up */
                gui_virtual_keyboard_clear_normal_popup_from_cache(v);

                /* show and cache long tap pop up */
                gui_virtual_keyboard_cache_and_show_longtap_popup(v);

                v->popup_hint.longtap_hint_details.highlighted_index = backup_highlighted_index;
            }
            else
            {
                /* discard the previous pop-up cache */
                /*mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr);
                v->popup_hint.key_bitmap.buf_ptr = NULL;
                v->popup_hint.is_key_cached = MMI_FALSE;*/

                /* unselect the previous selected key */
                
                gui_virtual_keyboard_show_unselect_key_from_cache(v);
    
                /* redo the cache and printing of popup and key */
                
                gui_virtual_keyboard_cache_and_show_selected_key(v);
                
            }
            
            /* restoring the blink cursor callback */
            //v->popup_hint.blink_cursor_callback = backup_blink_cursor_callback;
            //v->popup_hint.hide_cursor_callback = backup_hide_cursor_callback;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_discard_cache_and_recache
 * DESCRIPTION
 *  recover area that popup hint covered. It may happen that the other 
 *  components may be redrawn, so we should not take the pop-up from cache
 *  Instead we should redraw the region and retake the cahche.
 * PARAMETERS
 *  v               [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/

void gui_virtual_keyboard_discard_cache_and_recache(gui_virtual_keyboard_struct *v)
{
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
#if defined(__MMI_VUI_ENGINE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_recache
 * DESCRIPTION
 * PARAMETERS
 *  v               [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_recache(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        return;
    }
#endif

    if (v->key_down_accepted == MMI_TRUE)
    {
        if ((gui_virtual_keyboard_get_long_tap_popup_state(v)) || 
            (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE))
        {
            /* do nothing */
        }
        else
        {
            gui_virtual_keyboard_key_struct key;
            /* get selected key content */
            key = v->key_list[v->selected_key.index];

            /* there is popup content */
            if ((key.popup_index != -1) && 
                gui_virtual_keyboard_need_to_recache)
            {
                /* redo the cache and printing of popup and key */
                gui_virtual_keyboard_cache_and_show_selected_key(v);

                gui_virtual_keyboard_need_to_recache = MMI_FALSE;
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_draw_from_cache
 * DESCRIPTION
 * PARAMETERS
 *  v               [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_draw_from_cache(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key.is_key_cached == MMI_FALSE)
    {
        return;
    }

#if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        return;
    }
#endif

    if (v->key_down_accepted == MMI_TRUE)
    {
        if (v->popup_hint.is_key_cached == MMI_TRUE)
        {
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                /* do nothing */
            }
            else
            {
                /* discard the previous pop-up cache */

                gui_virtual_keyboard_clear_normal_popup_from_cache(v);

                /* unselect the previous selected key */

                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                gui_virtual_keyboard_need_to_recache = MMI_TRUE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_clear_normal_popup_from_cache
 * DESCRIPTION
 *  The function clears the normal pop-up from cache on encountering the 
 *  longtap pen event
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_clear_normal_popup_from_cache(
             gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        //vadp_p2v_close_virtual_keyboard_popup();
    }
#endif


#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
    if (v->popup_hint.longtap_hint_details.key_bitmap.buf_ptr)
    {
        mmi_frm_scrmem_free(v->popup_hint.longtap_hint_details.key_bitmap.buf_ptr);        
        v->popup_hint.longtap_hint_details.key_bitmap.buf_ptr = NULL;
    }
#endif


    /* Logic for showing the unselected pop-up from cache */
    if (v->selected_key.is_key_cached == MMI_FALSE)
    {
        return;
    }

    gui_lock_double_buffer();
    gdi_layer_push_clip();
    if (v->popup_hint.is_key_cached == MMI_TRUE)
    {
        x1 = v->popup_hint.x;
        y1 = v->popup_hint.y;
        x2 = x1 + v->popup_hint.width - 1;
        y2 = y1 + v->popup_hint.height - 1;
        gdi_layer_set_clip(x1, y1, x2, y2);
        gdi_image_cache_bmp_draw(x1, y1, &v->popup_hint.key_bitmap);
        mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr);
        v->popup_hint.key_bitmap.buf_ptr = NULL;
    }
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
    
    v->popup_hint.is_key_cached = MMI_FALSE;
    if (v->popup_hint.blink_cursor_callback != NULL)
    {
        if ((gui_virtual_keyboard_is_cursor_stopped_by_vk)  &&
            (v->popup_hint.is_cursor_stop == MMI_TRUE))
        {
            v->popup_hint.blink_cursor_callback();
            gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
            v->popup_hint.is_cursor_stop = MMI_FALSE;
        }
    }
}

#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_num_of_popup_chars
 * DESCRIPTION
 *  The function returns the number of pop up characters to be shown on
 *  longtap pop-up
 * PARAMETERS
 *  v               [IN/OUT]        Is the virtual keyboard pointer
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 gui_virtual_keyboard_get_num_of_popup_chars(
            gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 1;
    S16 index = 0;
    gui_virtual_keyboard_key_struct key;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    if (v == NULL)
    {
        return 0;
    }
    
    /* get selected key content */
    key = v->key_list[v->selected_key.index];

    index = key.popup_index;
    
    /* no normal popup */
    if (index == -1)
    {
        return 0;
    }

    if (v->popup_hint.popup_state != GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE)
    {
        index = v->key_list[index].popup_index;
    }
    
    /* no longtap popup */
    if (index == -1)
    {
        return 0;
    }

    while (v->key_list[index].popup_index != -1)
    {
        MMI_DBG_ASSERT(v->key_list[index].popup_index < v->key_count);
        index = v->key_list[index].popup_index;
        count++;
    }
    return count;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_initilize_longtap_popup_hint
 * DESCRIPTION
 *  The function initializes the longtap popup hint and returns the 
 *  number of pop up characters to be shown on longtap pop-up
 * PARAMETERS
 *  v               [IN/OUT]        Is the virtual keyboard pointer
 * RETURNS
 *  MMI_BOOL success or not
 *****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_initilize_longtap_popup_hint(
            gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v == NULL)
        return MMI_FALSE;

    /* number of longtap popup character */
    v->popup_hint.longtap_hint_details.num = gui_virtual_keyboard_get_num_of_popup_chars(v);
    /* highlighted character index on longtap popup */
    v->popup_hint.longtap_hint_details.highlighted_index = 0;
    /* no. of rows for showing the charcers on the long-tap popup */             
    v->popup_hint.longtap_hint_details.rows = 1;
    /* number of longtap popup character in each row */
    v->popup_hint.longtap_hint_details.chars_per_row = v->popup_hint.longtap_hint_details.num;

    /* initial the position and size */
    v->popup_hint.longtap_hint_details.x = 0;
    v->popup_hint.longtap_hint_details.y = 0;
    v->popup_hint.longtap_hint_details.width = 0;
    v->popup_hint.longtap_hint_details.height = 0;

    /* initial the popup key list index */
    if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE)
    {
        v->popup_hint.longtap_hint_details.key_index = v->key_list[v->selected_key.index].popup_index;    
    }
    else
    {
        v->popup_hint.longtap_hint_details.key_index = v->key_list[v->key_list[v->selected_key.index].popup_index].popup_index;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_cache_and_show_longtap_popup
 * DESCRIPTION
 *  The function caches and shows the longtap pop-up
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_cache_and_show_longtap_popup(
             gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_key_struct key;
    S32 x1 = 0, x2 = 0, y1 = 0, y2 = 0;
//    PU8 img = NULL; /* if key use an image */
//    PU8 text = NULL;
#ifdef __MMI_VK_POPUP_HINT__
    S32 cache_buf_size_popup_hint = 0;
//    gdi_handle active_layer = GDI_NULL_HANDLE;
//    gdi_handle abm_layer = GDI_NULL_HANDLE;
    gdi_handle h0, h1, h2, h3; /* use to record blt layers */
#endif /* __MMI_VK_POPUP_HINT__ */
    S16 i = 0, rows = 0;
    S32 longtap_index = 0;
    S16 x_left, x_right;
    gui_virtual_keyboard_longtap_popup_hint_struct* longtap_popup_ptr;
    S16 longtap_key_height;
    S16 bounds_x1, bounds_x2;
    S16 key_offset;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    
    if (v->selected_key.index < 0 || v->selected_key.index > v->key_count)
    {
        return;
    }

    /* get selected key content */
    key = v->key_list[v->selected_key.index];
    /* parse the key content from content */

    x1 = v->x + key.x;
    y1 = v->y + key.y;
    x2 = x1 + key.width - 1;
    y2 = y1 + key.height - 1;

    
    if ((longtap_index = key.popup_index) == -1)
    {
        /* no normal popup key. return */
        return;
    }

    if (v->popup_hint.popup_state != GUI_VIRTUAL_KEYBOARD_EVENT_ONLY_LONGTAP_STATE)
    {    
        longtap_index = v->key_list[longtap_index].popup_index;
    }
    
    /*** initilize longtap popup information ***/
    if (longtap_index >= 0 && gui_virtual_keyboard_initilize_longtap_popup_hint(v))
    {
        
        longtap_popup_ptr = &(v->popup_hint.longtap_hint_details);
        /* we assume that each popup key have the same height. */
        longtap_key_height = v->key_list[longtap_index].height;
        /* the key is on the left side */
        if (key.x < (v->width >> 1))
        {
            longtap_popup_ptr->x = key.x - GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;
            
            if (longtap_popup_ptr->x < v->x)
                longtap_popup_ptr->x = v->x;

            /* the x duration to draw the popup */
            bounds_x1 = longtap_popup_ptr->x + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;
            bounds_x2 = v->x + v->width - 1 - GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;

            if (longtap_popup_ptr->x < v->x)
                longtap_popup_ptr->x = v->x;
            x_left = bounds_x1;

            /* If at the beginning of the vk, pop-up bg image and the 
             * first index's image are both to be drawn at the same point
             */
            /*if (longtap_popup_ptr->x == x_left)
            {
                bound_x1 = x_left = x_left + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;
            }*/

            key_offset = 0;
            /* layout the key from left to right */
            do
            {
                if ((x_left + v->key_list[longtap_index].width + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET) > (v->x + v->width - 1))
                {
                    x_left = bounds_x1;
                    rows ++;
                }
                
                /* we assuem that the space in x is enough for at least one key. */
                longtap_popup_ptr->image_cordinate[i].x = x_left;
                longtap_popup_ptr->image_cordinate[i].y = /*rows;*/(longtap_key_height + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP)*rows + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_Y_OFFSET;
                longtap_popup_ptr->key_index_array[i] = longtap_index;
               
                if (longtap_popup_ptr->image_cordinate[i].x + v->key_list[longtap_index].width - 1 > key_offset)
                    key_offset = longtap_popup_ptr->image_cordinate[i].x + v->key_list[longtap_index].width;
                
                x_left += v->key_list[longtap_index].width + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP;

                longtap_index = v->key_list[longtap_index].popup_index;

                i ++;
            } while (longtap_index > 0);

            /* check background width */
            longtap_popup_ptr->width = (key_offset - bounds_x1 + 1) + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET*2;
            
        }
        else
        {

            bounds_x2 = key.x + key.width - 1 + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;
            if (bounds_x2 > v->x + v->width - 1)
                bounds_x2 = v->x + v->width - 1;
            bounds_x2 -= GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;

            bounds_x1 = v->x + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;
            
            x_right = bounds_x2;
            key_offset = 0x7fff;
            /* layout the key from right to left */
            do
            {
                if (x_right - v->key_list[longtap_index].width - GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET < bounds_x1)
                {
                    x_right = bounds_x2;
                    rows++;
                }
                
                /* we assuem that the space in x is enough for at least one key. */
                longtap_popup_ptr->image_cordinate[i].x = x_right - v->key_list[longtap_index].width + 1;
                longtap_popup_ptr->image_cordinate[i].y = (longtap_key_height + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP)*rows + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_Y_OFFSET;
                longtap_popup_ptr->key_index_array[i] = longtap_index;

                if (longtap_popup_ptr->image_cordinate[i].x < key_offset)
                    key_offset = longtap_popup_ptr->image_cordinate[i].x;
                    
                x_right -= (GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP + v->key_list[longtap_index].width);
                longtap_index = v->key_list[longtap_index].popup_index;

                i ++;

            } while (longtap_index > 0);
            
            /* check background x position & width */
            longtap_popup_ptr->width = (bounds_x2 - key_offset  + 1) + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET*2;
            longtap_popup_ptr->x = key_offset - GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;

            /* The following piece of code will maintain the sync. between the images
             * and pop-up bg when we shift the pop-up bg x
             */
            if (longtap_popup_ptr->x < 0)
            {
                longtap_index = v->key_list[key.popup_index].popup_index;
                i = 0;
        
                do
        {
                    longtap_popup_ptr->image_cordinate[i].x += (-longtap_popup_ptr->x);
                    longtap_index = v->key_list[longtap_index].popup_index;
                    i++;
                }
                while (longtap_index > 0);

                longtap_popup_ptr->x = 0;
            }
        }

        if (longtap_popup_ptr->x < 0)
            longtap_popup_ptr->x = 0;
        longtap_popup_ptr->height = (rows + 1) * longtap_key_height + rows*GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP + 2*GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_Y_OFFSET;
        longtap_popup_ptr->rows = rows;
        longtap_popup_ptr->y = key.y - /*GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_Y_OFFSET -*/ longtap_popup_ptr->height;

        #if defined(__MMI_VUI_ENGINE__)
        if (v->is_venus_vk)
        {
                longtap_index = v->key_list[key.popup_index].popup_index;
                i = 0;
        
                do
                {
                    longtap_popup_ptr->image_cordinate[i].x -= longtap_popup_ptr->x;
                    longtap_index = v->key_list[longtap_index].popup_index;
                    i++;
                }
                while (longtap_index > 0);
        }
        #endif

        /* stop cursor */
        if (v->popup_hint.hide_cursor_callback != NULL)
        {
            /* No need to stop the cursor if it is already stopped */
            if (!gui_virtual_keyboard_is_cursor_stopped_by_vk)
            {
                v->popup_hint.is_cursor_stop = v->popup_hint.hide_cursor_callback(
                                                        v->x + longtap_popup_ptr->x,
                                                        v->y + longtap_popup_ptr->y,
                                                        v->x + longtap_popup_ptr->x + longtap_popup_ptr->width - 1,
                                                        v->y + longtap_popup_ptr->y + longtap_popup_ptr->height - 1);
                if (v->popup_hint.is_cursor_stop)
                {
                    gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_TRUE;
                }
            }
        }

        /*** cache the background for longtap popup ***/
        #if defined(__MMI_VUI_ENGINE__)
        if (!v->is_venus_vk)
        #endif
        {

            /* cache current content that will be covered by popup hint */
            cache_buf_size_popup_hint = (longtap_popup_ptr->width*longtap_popup_ptr->height *(gdi_act_layer->bits_per_pixel)) >> 3;
            MMI_DBG_ASSERT(cache_buf_size_popup_hint <= GUI_VIRTUAL_KEYBOARD_POPUP_HINT_CACHE_SIZE);
			if (v->popup_hint.key_bitmap.buf_ptr != NULL)
			{
				mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr); 
			}
            v->popup_hint.key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size_popup_hint);
            MMI_DBG_ASSERT(v->popup_hint.key_bitmap.buf_ptr != NULL);
            
            #if defined(__MMI_VUI_ENGINE__)
            if (!v->is_venus_vk)
            #endif
            {
                /*** prepare the background for longtap popup ***/
                gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
            }

            gui_lock_double_buffer();
            gdi_layer_push_clip();
        
            /* cache large icon */
            gdi_layer_set_clip(
                v->x + longtap_popup_ptr->x,
                v->y + longtap_popup_ptr->y,
                v->x + longtap_popup_ptr->x + longtap_popup_ptr->width - 1,
                v->y + longtap_popup_ptr->y + longtap_popup_ptr->height - 1);

            /* if popup hint is out of VK background, we need flatten 
             * wallpaper to active layer
             *-------------------------------------------------------
             * (v->y + longtap_popup_ptr->y) < v->y)
             *-------------------------------------------------------
             */
            if (longtap_popup_ptr->y < 0)
            {
                gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
                gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
            }

            gdi_image_cache_bmp_get(
                v->x + longtap_popup_ptr->x,
                v->y + longtap_popup_ptr->y,
                v->x + longtap_popup_ptr->x + longtap_popup_ptr->width - 1,
                v->y + longtap_popup_ptr->y + longtap_popup_ptr->height - 1,
                &v->popup_hint.key_bitmap);
            v->popup_hint.is_key_cached = MMI_TRUE;
            
            v->popup_hint.x = longtap_popup_ptr->x + v->x ;
            v->popup_hint.y = longtap_popup_ptr->y + v->y ;
            v->popup_hint.width = longtap_popup_ptr->width;
            v->popup_hint.height = longtap_popup_ptr->height;

            /*** blt the result and recover gdi parameter ***/
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        
        
        v->popup_hint.longtap_hint_details.highlighted_index = 0;//-1;
        
        /*** print longtap popup key ***/
        gui_virtual_keyboard_print_longtap_popup_characters(v);
        /* cache longtap popup highlight backgroud */
        #if defined(__MMI_VUI_ENGINE__)
        if (!v->is_venus_vk)
        #endif
        {
            //gui_virtual_keyboard_handle_highlighter_on_longtap_popup_at_index(v, 0, MMI_TRUE);
        }
        #if defined(__MMI_VUI_ENGINE__)
        else
        {
            //gui_virtual_keyboard_handle_highlighter_on_longtap_popup_at_index(v, 0, MMI_FALSE);        
        }
        #endif


        #if defined(__MMI_VUI_ENGINE__)
        if (!v->is_venus_vk)
        #endif
        {
            gdi_layer_pop_clip();
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(
                longtap_popup_ptr->x,
                longtap_popup_ptr->y,
                longtap_popup_ptr->x + longtap_popup_ptr->width - 1,
                longtap_popup_ptr->y + longtap_popup_ptr->height - 1);        
        }
    }
    else
    {
        gui_BLT_double_buffer(x1, y1, x2, y2);
    }
}

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
/* under construction !*/
#endif 

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
#endif  

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_long_tap_popup_deactive
 * DESCRIPTION
 *  The function sets the longtap pop-up state as deactive
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_set_long_tap_popup_deactive(
                    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->longtap_popup_state = MMI_FALSE;        
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_set_long_tap_popup_active
 * DESCRIPTION
 *  The function sets the longtap pop-up state as active
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer 
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_set_long_tap_popup_active(
                    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->longtap_popup_state = MMI_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_long_tap_popup_state
 * DESCRIPTION
 *  The function returns the longtap pop-up state
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_virtual_keyboard_get_long_tap_popup_state(
                    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return v->longtap_popup_state;
}

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

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_print_longtap_popup_characters
 * DESCRIPTION
 *  The function prints the longtap pop-up characters on the longtap pop-up
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer  
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_virtual_keyboard_print_longtap_popup_characters(
            gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // gui_virtual_keyboard_key_struct key;
   // gui_virtual_keyboard_key_struct_p highlight_key_p;
   // S32 offset_x, offset_y;
    S16 num = 0;
    U8 i = 0;
   // PU8 img = NULL;
  //  PU8 text = NULL;
    S16 longtap_index = -1;
    gdi_handle h0, h1, h2, h3;
    S32 hint_x, hint_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    /* stop cursor before printing the pop-up*/
    if (v->popup_hint.hide_cursor_callback != NULL)
    {
        //if (!gui_virtual_keyboard_is_cursor_stopped_by_vk)
        {
            v->popup_hint.is_cursor_stop = v->popup_hint.hide_cursor_callback(
                                                    v->popup_hint.x,
                                                    v->popup_hint.y,
                                                    v->popup_hint.x + v->popup_hint.width - 1,
                                                    v->popup_hint.y + v->popup_hint.height - 1);
            if (v->popup_hint.is_cursor_stop)
            {
                gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_TRUE;
            }
        }
    }

    
    

    #if defined(__MMI_VK_POPUP_HINT__) && defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        //vadp_p2v_start_virtual_keyboard_popup((void*)v);
        //vadp_p2v_virtual_keyboard_popup_move();
        //vadp_p2v_redraw_virtual_keyboard_popup((void*)v);
    }
    #endif
    #if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
    #endif
    {
        gui_lock_double_buffer();
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            v->popup_hint.x,
            v->popup_hint.y,
            v->popup_hint.x + v->popup_hint.width - 1,
            v->popup_hint.y+ v->popup_hint.height - 1);
        
        #if defined(__MMI_VUI_ENGINE__)
        if (!v->is_venus_vk)
        #endif
        {
            gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
            if (v->popup_hint.y < v->y)
            {
                gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
                gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
            }
        }
    }

    #if defined(__MMI_VUI_ENGINE__)
    if (v->is_venus_vk)
    {
        hint_x = 0;
        hint_y = 0;
    }
    else
    #endif
    {
        hint_x = v->x + v->popup_hint.longtap_hint_details.x;
        hint_y = v->y + v->popup_hint.longtap_hint_details.y;    
    }
    
    #if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
    #endif
    {
        /* As in move we need to draw over the previous background image */
        if (v->popup_hint.key_bitmap.buf_ptr != NULL)
        {
            gdi_image_cache_bmp_draw(
                        v->popup_hint.x,
                        v->popup_hint.y,
                        &v->popup_hint.key_bitmap);
        }
        
        {
            gdi_image_cache_bmp_get(
                v->popup_hint.x,
                v->popup_hint.y,
                v->popup_hint.x + v->popup_hint.width - 1,
                v->popup_hint.y + v->popup_hint.height - 1,
                &v->popup_hint.key_bitmap);
        }

    }

    /*** draw longtap popup background image ***/
    gui_virtual_keyboard_show_image_with_dimension(
        v, 
        hint_x,
        hint_y,
        v->popup_hint.longtap_hint_details.width,
        v->popup_hint.longtap_hint_details.height,
        (PU8)GetImage(IMG_ID_VKBD_CUSTOM_LONGTAP_POPUP_BG),
        (gdi_handle)gdi_act_layer);

    
    /* get selected key content */
    //key = v->key_list[v->selected_key.index];
    

    /* show large icon content */
    gui_set_text_color(v->theme->key_up_text_color);
    gui_set_font(v->theme->text_font);
    
    /* offset from beginning of subimage5 from where the key will 
     * be drawn on pop-up 
     *----------------------------------------------------------------
     * The shape of key is being drawn at the center of the subimage5
     */
//    offset_x = VKBD_DIFF_HALF(v->popup_hint.longtap_hint_details.image_width, key.width);
//    offset_y = VKBD_DIFF_HALF(v->popup_hint.longtap_hint_details.image_height, key.height);
    ///TODO: ailsa test
    //offset_x = hint_x;
   // offset_y = hint_y;
    num = v->popup_hint.longtap_hint_details.num;
    longtap_index =v->popup_hint.longtap_hint_details.key_index;
    
    for (i = 0; i < num; i++)
    {
        /* print characters from last */
       // highlight_key_p = gui_virtual_keyboard_get_lontap_popup_char_at_index(v, i);
        if (i == v->popup_hint.longtap_hint_details.highlighted_index)
        {
            gui_virtual_keyboard_draw_key_int(
                v, 
                longtap_index,  
                v->popup_hint.longtap_hint_details.image_cordinate[i].x /*+ offset_x*/,
                v->popup_hint.longtap_hint_details.image_cordinate[i].y + hint_y,
                GUI_VK_KEY_STATE_HIGHLIGHT);

        }
        else if (gui_virtual_keyboard_is_disabled_key(v, longtap_index))
        {
            gui_virtual_keyboard_draw_key_int(
                v, 
                longtap_index,  
                v->popup_hint.longtap_hint_details.image_cordinate[i].x /*+ offset_x*/,
                v->popup_hint.longtap_hint_details.image_cordinate[i].y + hint_y,
                GUI_VK_KEY_STATE_DISABLE);        
        }
        else
        {
            gui_virtual_keyboard_draw_key_int(
                v, 
                longtap_index,  
                v->popup_hint.longtap_hint_details.image_cordinate[i].x /*+ offset_x*/,
                v->popup_hint.longtap_hint_details.image_cordinate[i].y + hint_y,
                GUI_VK_KEY_STATE_NORMAL);

        }
        longtap_index = v->key_list[longtap_index].popup_index;
    }
    
    #if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
    #endif
    {
        gdi_layer_pop_clip();
        gdi_pop_and_restore_alpha_blending_source_layer();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            v->popup_hint.x,
            v->popup_hint.y,
            v->popup_hint.x + v->popup_hint.width - 1,
            v->popup_hint.y+ v->popup_hint.height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_get_longtap_popup_index_for_highlighling
 * DESCRIPTION
 *  The function returns the index of the character to be highlighted on the 
 *  longtap pop-up. The API does not sets the highlighted index of the 
 *  longtap pop-up to the index being returned as the highlighter has not yet 
 *  been drawn
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer
 *  x       [IN]            x coordinate of pen position
 *  y       [IN]            y coordinate of pen position
 * RETURNS
 *  U16
 *****************************************************************************/
static S16 gui_virtual_keyboard_get_longtap_popup_index_for_highlighling(
            gui_virtual_keyboard_struct *v, 
            S16 x, 
            S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = -1;
    S16 num = 0;
    S16 i = 0;
    //S16 key_height_offset;
    S16 hint_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_y = v->popup_hint.y;    
    
    num = v->popup_hint.longtap_hint_details.num;
    #if defined(__MMI_VUI_ENGINE__)
    if (!v->is_venus_vk)
    #endif
    {
        if (v->popup_hint.longtap_hint_details.rows == 0)
        {
            S16 y1 = 0, y2 = 0;
            //key_height_offset = GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;

            y1 = (v->popup_hint.y < v->y) ? v->popup_hint.y : v->y;

            y2 = ((v->y + v->key_list[v->selected_key.index].y + v->key_list[v->selected_key.index].height) >
                    (v->popup_hint.y + v->popup_hint.height)) ?
                 (v->y + v->key_list[v->selected_key.index].y + v->key_list[v->selected_key.index].height - 1) :
                 (v->popup_hint.y + v->popup_hint.height - 1);

            for (i = 0; i < num; i++)
            {
                if (PEN_CHECK_BOUND(
                        x, 
                        y, 
                        v->x + v->popup_hint.longtap_hint_details.image_cordinate[i].x  - GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP/2 , 
                        y1, 
                        v->key_list[v->popup_hint.longtap_hint_details.key_index_array[i]].width + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP, 
                        y2 - y1 + 1))
                {
                    index = i;
                    break;
                }
            }
        }
        else
        {
           // key_height_offset = GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP/2;
        
        for (i = 0; i < num; i++)
        {
            if (PEN_CHECK_BOUND(
                    x, 
                    y, 
                        v->x + v->popup_hint.longtap_hint_details.image_cordinate[i].x  - GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP/2, 
                        v->popup_hint.y + v->popup_hint.longtap_hint_details.image_cordinate[i].y - GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP/2, 
                        v->key_list[v->popup_hint.longtap_hint_details.key_index_array[i]].width + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP, 
                        v->key_list[v->popup_hint.longtap_hint_details.key_index_array[i]].height + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP))
            {
                    index = i;
                    break;
            }
        }
        }
    }
    #if defined(__MMI_VUI_ENGINE__)
    else
    {
        if (v->popup_hint.longtap_hint_details.rows == 0)
        {
            S16 y1 = 0, y2 = 0;
          //  key_height_offset = GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_X_OFFSET;

            y1 = (hint_y < v->y) ? hint_y : v->y;

            y2 = ((v->y + v->key_list[v->selected_key.index].y + v->key_list[v->selected_key.index].height) >
                    (hint_y + v->popup_hint.height)) ?
                 (v->y + v->key_list[v->selected_key.index].y + v->key_list[v->selected_key.index].height - 1) :
                 (hint_y + v->popup_hint.height - 1);

            for (i = 0; i < num; i++)
            {
                if (PEN_CHECK_BOUND(
                        x, 
                        y, 
                        v->x + v->popup_hint.longtap_hint_details.image_cordinate[i].x  - GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP/2 + v->popup_hint.longtap_hint_details.x, 
                        y1, 
                        v->key_list[v->popup_hint.longtap_hint_details.key_index_array[i]].width + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP, 
                        y2 - y1 + 1))
                {
                    index = i;
                    break;
                }
            }
        }
        else
        {
          //  key_height_offset = GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP/2;
        
            for (i = 0; i < num; i++)
            {
                if (PEN_CHECK_BOUND(
                        x, 
                        y, 
                            v->x + v->popup_hint.longtap_hint_details.image_cordinate[i].x  - GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP/2 + v->popup_hint.longtap_hint_details.x, 
                            hint_y + v->popup_hint.longtap_hint_details.image_cordinate[i].y - GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP/2 - (v->key_list[0].height + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP)*v->popup_hint.longtap_hint_details.rows, 
                            v->key_list[v->popup_hint.longtap_hint_details.key_index_array[i]].width + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_X_GAP, 
                            v->key_list[v->popup_hint.longtap_hint_details.key_index_array[i]].height + GUI_VIRTUAL_KEYBOARD_LONGTAP_POPUP_Y_GAP))
                {
                        index = i;
                        break;
                }
            }
        }
    }
    #endif
        
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_longtap_popup_translate_pen_event
 * DESCRIPTION
 *  translate pen event in longtap popup
 * PARAMETERS
 *
 * RETURNS
 *
 * REMARKS
 *
 *****************************************************************************/
static void gui_virtual_keyboard_longtap_popup_translate_pen_event(
            gui_virtual_keyboard_struct *v, 
            S16 x, 
            S16 y,
            mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, y1, width, height;
    S16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gui_virtual_keyboard_get_long_tap_popup_state(v))
        return;
    
    x1 = v->popup_hint.longtap_hint_details.x + v->x;
    y1 = v->popup_hint.longtap_hint_details.y + v->y;
    width = v->popup_hint.longtap_hint_details.width;
    /* allow more error in y positions */
    if (v->popup_hint.longtap_hint_details.rows == 0)
    {
        S16 y2 = 0;
        y2 = ((v->y + v->key_list[v->selected_key.index].y + v->key_list[v->selected_key.index].height) >
              (v->popup_hint.y + v->popup_hint.height)) ?
             (v->y + v->key_list[v->selected_key.index].y + v->key_list[v->selected_key.index].height - 1) :
             (v->popup_hint.y + v->popup_hint.height - 1);
        height = y2 - y1 + 1;
    }
    else
    {
        height = v->popup_hint.longtap_hint_details.height + GUI_VIRTUAL_KEYBOARD_POPUP_HINT_ARROW_Y_OFFSET*2;
    }

    if (PEN_CHECK_BOUND(x, y, x1, y1, width, height))
    {
        if ((index = gui_virtual_keyboard_get_longtap_popup_index_for_highlighling(v, x, y)) != -1)
        {
            /* highlight change */
            if (index != v->popup_hint.longtap_hint_details.highlighted_index)
            {

                #if defined(__MMI_VUI_ENGINE__)
                if (!v->is_venus_vk)
                #endif
                {
                gui_lock_double_buffer();
                }
/*                gui_virtual_keyboard_draw_key_int(
                    v, 
                    v->popup_hint.longtap_hint_details.key_index_array[v->popup_hint.longtap_hint_details.highlighted_index], 
                    v->x + v->popup_hint.longtap_hint_details.image_cordinate[v->popup_hint.longtap_hint_details.highlighted_index].x, 
                    v->y + v->popup_hint.longtap_hint_details.image_cordinate[v->popup_hint.longtap_hint_details.highlighted_index].y, 
                    GUI_VK_KEY_STATE_NORMAL);
                gui_virtual_keyboard_draw_key_int(
                    v, 
                    v->popup_hint.longtap_hint_details.key_index_array[index], 
                    v->x + v->popup_hint.longtap_hint_details.image_cordinate[index].x, 
                    v->y + v->popup_hint.longtap_hint_details.image_cordinate[index].y, 
                    GUI_VK_KEY_STATE_HIGHLIGHT);*/
                v->popup_hint.longtap_hint_details.highlighted_index = index;
                gui_virtual_keyboard_print_longtap_popup_characters(v);    
                #if defined(__MMI_VUI_ENGINE__)
                if (!v->is_venus_vk)
                #endif
                {
                gui_unlock_double_buffer();
                }
                gui_BLT_double_buffer(
                    v->x + v->popup_hint.longtap_hint_details.x,
                    v->y + v->popup_hint.longtap_hint_details.y,
                    v->x + v->popup_hint.longtap_hint_details.x + v->popup_hint.longtap_hint_details.width - 1,
                    v->x + v->popup_hint.longtap_hint_details.x + v->popup_hint.longtap_hint_details.height - 1);
            }
        }
        else
        {
            /* currently, no pen down in valid region, keep the previous key as the index */
            gdi_layer_lock_frame_buffer();
            v->popup_hint.longtap_hint_details.highlighted_index = -1;
            //gui_virtual_keyboard_set_long_tap_popup_deactive(v);
            //gui_virtual_keyboard_recover_covered_area(v);
            gui_virtual_keyboard_print_longtap_popup_characters(v);    
            gdi_layer_unlock_frame_buffer();
            gui_BLT_double_buffer(
                v->x + v->popup_hint.longtap_hint_details.x,
                v->y + v->popup_hint.longtap_hint_details.y,
                v->x + v->popup_hint.longtap_hint_details.x + v->popup_hint.longtap_hint_details.width - 1,
                v->x + v->popup_hint.longtap_hint_details.x + v->popup_hint.longtap_hint_details.height - 1);
        }
    }
    else
    {
        gdi_layer_lock_frame_buffer();
        v->popup_hint.longtap_hint_details.highlighted_index = -1;
        //gui_virtual_keyboard_set_long_tap_popup_deactive(v);
        //gui_virtual_keyboard_recover_covered_area(v);
        gui_virtual_keyboard_print_longtap_popup_characters(v);    
        gdi_layer_unlock_frame_buffer();
        gui_BLT_double_buffer(
            v->x + v->popup_hint.longtap_hint_details.x,
            v->y + v->popup_hint.longtap_hint_details.y,
            v->x + v->popup_hint.longtap_hint_details.x + v->popup_hint.longtap_hint_details.width - 1,
            v->x + v->popup_hint.longtap_hint_details.x + v->popup_hint.longtap_hint_details.height - 1);
    }

}
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
#endif 
#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */


#endif /* __MMI_VK_POPUP_HINT__ */


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_show_popup
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void gui_virtual_keyboard_show_popup(gui_virtual_keyboard_struct* v, MMI_BOOL cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (v->key_list[v->selected_key.index].popup_index == -1)
        return;
    
#ifdef __MMI_VK_POPUP_HINT__
#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)    
    if (gui_virtual_keyboard_get_long_tap_popup_state(v))
    {
        gui_virtual_keyboard_print_longtap_popup_characters(v);
    }
    else
#endif
    {
        gui_virtual_keyboard_redraw_popup_hint_content(v);
    }
#endif /* __MMI_VK_POPUP_HINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_register_get_vk_callback
 * DESCRIPTION
 *  Register event callback of virtual keyboard
 * PARAMETERS
 *  v       [IN/OUT]    Is the virtual keyboard object
 *  f       [IN]        Is the event callback
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_register_get_vk_callback(
      gui_virtual_keyboard_get_vk_callback_func_ptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_get_virtual_keyboard_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_vk_longtap_timer_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void gui_vk_longtap_timer_handler(
            void/*,
            S16 x,
            S16 y,
            mmi_pen_event_type_enum pen_event*/)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_struct *v = (*gui_get_virtual_keyboard_callback)();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_VK_LONGTAP_POPUP_HINT__
    //if (pen_event != PEN_EVENT_UP)
    	#if defined __MMI_XT9__
		if ( !((mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN)))
	#endif
    {
        if (v->key_down_accepted)
        {
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                /* do nothing */
                gui_cancel_timer(gui_vk_longtap_timer_handler);
            }
            else
            {
                /* if pen is in selected key's area, do nothing */
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
                {
                    if (v->popup_hint.popup_state != GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                    {
                
                        U8 num = 0;

                        /* set longtap pop-up deactive */
                        gui_virtual_keyboard_set_long_tap_popup_deactive(v);
                        num = gui_virtual_keyboard_get_num_of_popup_chars(v);
                        if (num >= 1)
                        {
                                /* set longtap pop-up active */
                                gui_virtual_keyboard_set_long_tap_popup_active(v);

                                #if defined(__MMI_VUI_ENGINE__)
                                if (!(v->is_venus_vk))
                                #endif
                                {
									gui_virtual_keyboard_handle_long_tap_popup(v);
                                }
                        }
                        gui_cancel_timer(gui_vk_longtap_timer_handler);
                    }         
                }
            }
        }
    }
    #endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */
}


#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_handle_long_tap_popup
 * DESCRIPTION
 * PARAMETERS
 *	gui_virtual_keyboard_struct
 * RETURNS
*	void
 *****************************************************************************/
static void gui_virtual_keyboard_handle_long_tap_popup(
            gui_virtual_keyboard_struct *v)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
			//void (*backup_blink_cursor_callback) (void);
                                                        
            /* backing up the callback for restoration later on */
            //backup_blink_cursor_callback = v->popup_hint.blink_cursor_callback;

            /* To avoid blinking of cursor while we are in between the
             * cache ignoring and recaching
             */
            //v->popup_hint.blink_cursor_callback = NULL;

            #if defined __MMI_XT9__
		        if (!((mmi_imm_is_current_mode_smart())   && (mmi_imm_get_curr_input_mode() != IMM_INPUT_MODE_SM_PINYIN)))
	    #endif
            {
            #if defined(__MMI_VUI_ENGINE__)
            if (!(v->is_venus_vk))
            #endif
            {
                gdi_layer_lock_frame_buffer();
            }

            /* set longtap pop-up active */
            gui_virtual_keyboard_set_long_tap_popup_active(v);
            /* remove normal pop-up from cache */
            gui_virtual_keyboard_clear_normal_popup_from_cache(v);	                
            
            /* hide cursor callback to be effectd for long tap pop-up */
            gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
            v->popup_hint.is_cursor_stop = MMI_FALSE;

            /* cache and show long tap pop-up */
            gui_virtual_keyboard_cache_and_show_longtap_popup(v);
            
			#if defined(__MMI_VUI_ENGINE__)
            if (!(v->is_venus_vk))
            #endif
            {
                gdi_layer_unlock_frame_buffer();
            }

			gui_BLT_double_buffer(
                v->popup_hint.longtap_hint_details.x,
                v->popup_hint.longtap_hint_details.y,
                v->popup_hint.longtap_hint_details.x + v->popup_hint.longtap_hint_details.width - 1,
                v->popup_hint.longtap_hint_details.y + v->popup_hint.longtap_hint_details.height - 1); 
            
            /* restoring the blink cursor callback */
            //v->popup_hint.blink_cursor_callback = backup_blink_cursor_callback;
}
}
#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */

/*****************************************************************************
 * FUNCTION
 *  gui_virtual_keyboard_clear_cache_on_imc_disconnect
 * DESCRIPTION 
 *  The function clears the cache when imc disconnects 
 * PARAMETERS
 *  v       [IN/OUT]        Is the virtual keyboard pointer     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_virtual_keyboard_clear_cache_on_imc_disconnect(gui_virtual_keyboard_struct *v)
{

 if (v->selected_key.key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->selected_key.key_bitmap.buf_ptr);
        v->selected_key.key_bitmap.buf_ptr = NULL;
        v->selected_key.is_key_cached = MMI_FALSE;
    }

#if defined(__MMI_VK_POPUP_HINT__)
if (v->popup_hint.key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr);
        v->popup_hint.is_key_cached = MMI_FALSE;
        v->popup_hint.key_bitmap.buf_ptr = NULL;
    }
#endif 

#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
    if (v->popup_hint.longtap_hint_details.key_bitmap.buf_ptr)
    {
        mmi_frm_scrmem_free(v->popup_hint.longtap_hint_details.key_bitmap.buf_ptr);        
        v->popup_hint.longtap_hint_details.key_bitmap.buf_ptr = NULL;
    }
#endif

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_clear_cache_on_imc_disconnect
* DESCRIPTION 
*  The function clears the cache when imc disconnects 
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer     
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_clear_state_on_imc_disconnect(gui_virtual_keyboard_struct *v)
{
}
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */


#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
/*****************************************************************************
 * Following code is for VK V2
 ****************************************************************************/

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
/********************************************************************************
* Filename:
* ---------
*	gui_virtual_keyboard.c
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	Virtual Keyboard - UI Component
*
* Version:
* ------------
*	Helena Li (mbj07028)
*
*******************************************************************************/
/******************************************************************************
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
*******************************************************************************/
/*****************************************************************************
 * include
 ****************************************************************************/
/* Write your #include header file here */
#include "BIDIDef.h"
#include "gui_virtual_keyboard.h"
#include "wgui_virtual_keyboard.h"
#include "wgui_categories_util.h"
#include "gui_font_size.h"
#include "math.h"
#include "gui_virtual_keyboard_misc_res.h"
#include "Gui_touch_feedback.h"
#include "ProfilesSrvGprot.h"
#if defined(__MMI_INDIC_ALG__)
#include  "IndicEngineGprot.h"
#endif 
#if defined(__MMI_LANG_THAI__)
#include "ThaiGProt.h"
#endif
#include "IMERes.h"
#include "ImmProt.h"
#include "imc.h"
#include "imui.h"
#include "imc_pen.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define GUI_VK_CHAR_MASK        0xffff
#define GUI_VK_GET_KEY_CHAR(x)  ((x) >GUI_VK_CHAR_MASK? 0:  (x))
#define GUI_VK_GET_KEY_EVENT(x) ((x) >GUI_VK_CHAR_MASK? (x) :  0)
#define GUI_VK_LONG_TAP_TIMER   600

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)
    #define GUI_VK_POPUP_ICON_MIN_WIDTH 58
    #define GUI_VK_POPUP_ICON_MIN_HEIGHT 58
#elif defined(__MMI_MAINLCD_320X480__)
    #define GUI_VK_POPUP_ICON_MIN_WIDTH 66
    #define GUI_VK_POPUP_ICON_MIN_HEIGHT 66
#elif defined(__MMI_MAINLCD_480X800__)
    #define GUI_VK_POPUP_ICON_MIN_WIDTH 88
    #define GUI_VK_POPUP_ICON_MIN_HEIGHT 88
#else
    #error "non supported lcd resolution"
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static gui_virtual_keyboard_get_vk_callback_func_ptr gui_get_virtual_keyboard_callback;
static MMI_BOOL gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
static MMI_BOOL gui_virtual_keyboard_need_to_recache = MMI_FALSE;
static UI_character_type gui_virtual_keyboard_main_label = 0;
static get_multitap_string get_multi_tap_engine_string = NULL;
UI_virtual_keyboard_theme *current_virtual_keyboard_theme = NULL;
/***************************************************************************** 
* Local Function
*****************************************************************************/
#ifdef __MMI_VK_POPUP_HINT__
static MMI_BOOL gui_virtual_keyboard_hide_cursor_dummy_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2);
#endif /* __MMI_VK_POPUP_HINT__ */
extern void gui_vk_longtap_timer_handler(void);
static void gui_virtual_keyboard_clear_selected_key(
             gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_draw_key(
             gui_virtual_keyboard_struct *v,
             const gui_virtual_keyboard_key_struct* index);
static void gui_virtual_keyboard_default_hide_function(
             S32 x1,
             S32 y1,
             S32 x2,
             S32 y2);
static void gui_virtual_keyboard_default_display_callback_function(
             gui_virtual_keyboard_pen_enum pen_symbol);
static void gui_virtual_keyboard_show_content_by_align(
            gui_virtual_keyboard_struct *v,
             UI_character_type ch,
             PU8 text,
             PU8 image,
             S32 key_x,
             S32 key_y,
             S32 key_width,
             S32 key_height,
             S32 *glyph_width,
             S32 *glyph_height);
static MMI_BOOL gui_virtual_keyboard_is_disabled_key(
                 gui_virtual_keyboard_struct *v,
                 const gui_virtual_keyboard_key_struct* index);
static MMI_BOOL gui_virtual_keyboard_is_kept_down_key(
                 gui_virtual_keyboard_struct *v,
                 const gui_virtual_keyboard_key_struct* index);
static MMI_BOOL gui_virtual_keyboard_is_selected_key(
                 gui_virtual_keyboard_struct *v,
                 const gui_virtual_keyboard_key_struct* index);
static MMI_BOOL gui_virtual_keyboard_get_current_key_toggle_state(
                gui_virtual_keyboard_struct* v,
                const gui_virtual_keyboard_key_struct* key,
                const gui_virtual_keyboard_key_struct ** toggle_key);
static void gui_virtual_keyboard_discard_cache_and_recache_mini_keyboard(
            gui_virtual_keyboard_struct * v);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
static MMI_BOOL gui_virtual_keyboard_translate_pen_position(
                 gui_virtual_keyboard_struct *v,
                 S16 x,
                 S16 y,
                 const gui_virtual_keyboard_key_struct** index);
static MMI_BOOL gui_virtual_keyboard_get_selected_key_int(
                 gui_virtual_keyboard_struct *v,
                 const gui_virtual_keyboard_key_struct* index,
                 mmi_pen_event_type_enum pen_event,
                 UI_character_type *key_char,
                 gui_virtual_keyboard_pen_enum *key_event);
static MMI_BOOL gui_virtual_keyboard_get_selected_key(
                 gui_virtual_keyboard_struct *v,
                 const gui_virtual_keyboard_key_struct* index,
                 mmi_pen_event_type_enum pen_event,
                 UI_character_type *key_char,
                 gui_virtual_keyboard_pen_enum *key_event);
static void gui_virtual_keyboard_redraw_popup_hint(
             gui_virtual_keyboard_struct *v,
             MMI_BOOL cache);
static void gui_virtual_keyboard_draw_key_shape(
             gui_virtual_keyboard_struct *v,
             S32 x,
             S32 y,
             S32 width,
             S32 height,
             color frame_color,
             color fill_color);
static void gui_virtual_keyboard_discard_cache_and_recache_normal_key(
            gui_virtual_keyboard_struct_p v);
#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_480X800__)
static color gui_virtual_keyboard_get_gradient_color(
              color src_color,
              S16 value,
              S16 start_value,
              S16 end_value,
              MMI_BOOL is_ascend);
#endif 
/* 
static U8 gui_virtual_keyboard_get_num_of_popup_characters(
            gui_virtual_keyboard_struct *v); */ 

static void gui_virtual_keyboard_show_unselect_key_from_cache(
                gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_cache_and_show_selected_key(
                gui_virtual_keyboard_struct *v);

MMI_BOOL gui_virtual_keyboard_Check_alphanumeric_vk_0_to_9_key(
              gui_virtual_keyboard_struct *v,
              S16 x,
              S16 y);               
static MMI_BOOL gui_virtual_keyboard_is_key_down_accept(
    gui_virtual_keyboard_struct *v);
static MMI_BOOL gui_virtual_keyboard_is_mini_keyboard_state(
    gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_set_mini_keyboard_state(
    gui_virtual_keyboard_struct *v,
    MMI_BOOL flag);
static MMI_BOOL gui_virtual_keyboard_is_multitap_state(
    gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_set_multitap_state(
    gui_virtual_keyboard_struct *v,
    MMI_BOOL flag);
static void gui_virtual_keyboard_get_key_hint_size_ratio(
    gui_virtual_keyboard_struct_p v,
    const gui_virtual_keyboard_key_struct* key,
    float * ratio_width,
    float * ratio_height);

static MMI_BOOL gui_virtual_keyboard_is_active_row_id(
        gui_virtual_keyboard_struct* v, 
        U16 row);
static color gui_virtual_keyboard_main_label_color_from_theme(
     gui_virtual_keyboard_key_state_enum key_state);
static color gui_virtual_keyboard_aux_label_color_from_theme(
    gui_virtual_keyboard_key_state_enum key_state);

#ifdef __MMI_VK_POPUP_HINT__
static void gui_virtual_keyboard_stop_cursor_blink(S32 x1, S32 y1, S32 x2, S32 y2);

static void gui_virtual_keyboard_start_cursor_blink(void);

static void gui_virtual_keyboard_clear_normal_popup_from_cache(
     gui_virtual_keyboard_struct *v);

static void gui_virtual_keyboard_show_popup_hint(
 gui_virtual_keyboard_struct* v, 
 gui_virtual_keyboard_key_state_enum key_state,
 MMI_BOOL cache);


#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
static void gui_virtual_keyboard_resume_from_longtap_state(
            gui_virtual_keyboard_struct * v);

static MMI_BOOL gui_virtual_keyboard_create_and_enter_mini_keyboard(
            gui_virtual_keyboard_struct *v);

static void gui_virtual_keyboard_handle_long_tap_popup(
            gui_virtual_keyboard_struct *v);
static void gui_virtual_keyboard_cache_and_show_longtap_popup(
            gui_virtual_keyboard_struct *v);
static MMI_BOOL gui_virtual_keyboard_is_label_get_from_vendor(
            gui_virtual_keyboard_struct_p v, UI_character_type label_ch);
/* 
static void gui_virtual_keyboard_handle_highlighter_on_longtap_popup_at_index(
             gui_virtual_keyboard_struct *v, 
             S16 index,
             MMI_BOOL cache);
*/ 
/* 
static gui_virtual_keyboard_key_struct_p 
            gui_virtual_keyboard_get_lontap_popup_char_at_index(
             gui_virtual_keyboard_struct *v, 
             S16 higlited_index); */ 


/* static void gui_virtual_keyboard_deactivate_highlighter_on_longtap_popup(
             gui_virtual_keyboard_struct *v); */ 
static void gui_virtual_keyboard_print_longtap_popup_characters(
             gui_virtual_keyboard_struct *v);
static S16 gui_virtual_keyboard_get_longtap_popup_index_for_highlighling(
            gui_virtual_keyboard_struct *v, 
            S16 x, 
            S16 y);
static void gui_virtual_keyboard_longtap_popup_translate_pen_event(
            gui_virtual_keyboard_struct *v, 
            S16 x, 
            S16 y,
            mmi_pen_event_type_enum pen_event,
            gui_virtual_keyboard_pen_enum *key_event,
            gui_pen_event_param_struct *key_param);
/* static S16 gui_virtual_keyboard_get_longtap_popup_actaual_key_index(
            gui_virtual_keyboard_struct *v,
            S16 highlight_index); */ 
#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */


#endif /* __MMI_VK_POPUP_HINT__ */

        
#if !defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_480X800__)
/***************************************************************************** 
 * FUNCTION
 *  gui_virtual_keyboard_get_gradient_color
 * DESCRIPTION
 *  Get the gradient color of a given value
 * PARAMETERS
 *  src_color       [IN] source color
 *  value           [IN] value that want to calculate the gradient color
 *  start_value     [IN] the start value of color range
 *  end_value       [IN] the end value of color range
 *  is_ascend       [IN] is ascend or decend
 * RETURNS
 *  color
 *****************************************************************************/
static color gui_virtual_keyboard_get_gradient_color(
              color src_color,
              S16 value,
              S16 start_value,
              S16 end_value,
              MMI_BOOL is_ascend)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color temp_color;
    return temp_color;
}        
#endif 


void gui_virtual_keyboard_set_get_string_func(get_multitap_string f)
{
    get_multi_tap_engine_string = f;
}


void gui_virtual_keyboard_get_popup_vk_layout(
                 const gui_virtual_keyboard_key_struct* key,
                 void** layout_p)
{
    const gui_virtual_keyboard_key_struct* toggle_key;
    MMI_BOOL ret = MMI_FALSE;

    MMI_ASSERT(key != NULL);

    ret = gui_virtual_keyboard_get_current_key_toggle_state( gui_get_virtual_keyboard_callback(), key, &toggle_key);
    if (ret)
        {
            *layout_p = (void*)toggle_key->popup_vk;
        }
    else
        {
             *layout_p = (void*)key->popup_vk;
        }
}


static void gui_virtual_keyboard_draw_key_by_index(U32 index)
{
    const gui_virtual_keyboard_key_struct* key;
    MMI_ASSERT(index <= wgui_virtual_keyboard_get_button_count());

    gui_virtual_keyboard_translate_index_to_pointer( index, & key);

    gui_virtual_keyboard_draw_key(gui_get_virtual_keyboard_callback(),key);
}


MMI_BOOL gui_virtual_keyboard_is_mini_keyboard_state(
    gui_virtual_keyboard_struct *v)
{
    return v->is_mini_keyboard_state;
}


static MMI_BOOL gui_virtual_keyboard_is_multitap_state(
    gui_virtual_keyboard_struct *v)
{
    return MMI_FALSE;
}


static void gui_virtual_keyboard_set_multitap_state(
    gui_virtual_keyboard_struct *v,
    MMI_BOOL flag)
{
    return ;
}


static void gui_virtual_keyboard_set_mini_keyboard_state(
            gui_virtual_keyboard_struct *v,
            MMI_BOOL flag)
{
    v->is_mini_keyboard_state = flag;
}


static void gui_virtual_keyboard_discard_cache_and_recache_normal_key(
        gui_virtual_keyboard_struct_p v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_virtual_keyboard_key_struct* key;
    U16 x1,y1,x2,y2;
    U32 cache_buf_size;
    
    /*----------------------------------------------------------------*/
    /* code body                                                   */
    /*----------------------------------------------------------------*/

    if( v->selected_key.is_key_cached == MMI_TRUE)
    {
        return;
    }
    key = v->selected_key.index;
    x1 = v->x + key->pos_x;
    y1 = v->y + key->pos_y;
    x2 = x1 + key->width - 1;
    y2 = y1 + key->height - 1;
    
    gui_lock_double_buffer();
    /* cache the current key content to selected key's key_bitmap */
    cache_buf_size = (key->width * key->height * (gdi_act_layer->bits_per_pixel)) >> 3;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
  
    v->selected_key.key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size);
    MMI_DBG_ASSERT(v->selected_key.key_bitmap.buf_ptr != NULL);
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_VK_CACHE_STORE, x1,y1);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->selected_key.key_bitmap);
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
    v->selected_key.is_key_cached = MMI_TRUE;

}


MMI_BOOL gui_virtual_keyboard_is_key_down_accept(
    gui_virtual_keyboard_struct *v)
{
    return v->key_down_accepted;
}


void gui_virtual_keyboard_get_label_int(
        gui_virtual_keyboard_struct_p v,
        const gui_virtual_keyboard_key_struct* key,
        gui_virtual_keyboard_key_label_info_struct_p label,
        gui_virtual_keyboard_key_state_enum state,
        U32 index)
{
    const gui_virtual_keyboard_keytype_struct* keytype_list;
    const gui_virtual_keyboard_key_struct* toggle_key;
    //U32 toggle_state_index;
    float ratio_width,ratio_height;
    MMI_BOOL ret;
    S32 i;
    
    keytype_list = v->keytype_list + key->keytype;
    MMI_ASSERT(key != NULL && label != NULL);
    MMI_ASSERT(key != NULL && label != NULL);
    memset(label, 0, sizeof(gui_virtual_keyboard_key_label_info_struct));

    gui_virtual_keyboard_get_key_hint_size_ratio( v, key, &ratio_width, &ratio_height);
    if (index == 0)
    {
        label->label = key->label_string;
        label->label_icon= key->lable_icon;
        label->color = keytype_list->text1_color;
        label->bias_loc_x = (S16) ((float) keytype_list->text1_loc_biasx / 100 * key->width);
        label->bias_loc_y = (S16) ((float) keytype_list->text1_loc_biasy / 100 * key->height);
        label->size = keytype_list->text1_size;
    }
    else if (index == 1)
    {
        label->label = key->label_string_aux;
        label->label_icon = key->lable_icon_aux;
        label->color = keytype_list->text2_color;
        label->bias_loc_x = (S16) ((float) keytype_list->text2_loc_biasx / 100 * key->width );
        label->bias_loc_y = (S16) ((float) keytype_list->text2_loc_biasy / 100 * key->height);
        label->size = keytype_list->text2_size;

    }
    if (index == 0)
    {
        switch(state)
        {
        case GUI_VK_KEY_STATE_NORMAL:
        case GUI_VK_KEY_STATE_DISABLE:
            label->color = keytype_list->text1_color;
            label->size = keytype_list->text1_size;
            break;
        case GUI_VK_KEY_STATE_HIGHLIGHT:
            label->color = keytype_list->hl_text1_color;
            label->size = keytype_list->hltext1_size;
            break;
        case GUI_VK_KEY_STATE_POPUP:
            if (key->label_balloon_icon != 0 || key->label_balloon_string != NULL)
            {
                if (key->label_balloon_string != NULL)
                {
                    label->label = key->label_balloon_string;
                    label->color = keytype_list->bl_text1_color;
                    label->size = keytype_list->bltext1_size;
                }
                else
                {
                    label->label_icon = key->label_balloon_icon;
                }
                label->bias_loc_x =  0;
                label->bias_loc_y =  0;
            }
            else
            {
                label->bias_loc_x = (S16) (label->bias_loc_x * ratio_width);
                label->bias_loc_y = (S16) (label->bias_loc_y * ratio_height);
                label->color = keytype_list->bl_text1_color;
                ///TODO: revise this code after check what's the font size means.
                label->size = keytype_list->bltext1_size;
            }
            break;

        case GUI_VK_KEY_STATE_LONGTAP_POPUP:
            if (key->label_balloon_longpress_icon != 0 || key->lable_balloon_longpress != NULL)
            {
                if (key->label_balloon_string != NULL)
                {
                    label->label = key->lable_balloon_longpress;
                    label->color = keytype_list->bl_text1_color;
                    label->size = keytype_list->bltext1_size;
                }
                else
                {
                    label->label_icon = key->label_balloon_longpress_icon;
                }
                label->bias_loc_x = 0;
                label->bias_loc_y = 0;
            }
            else
            {
                label->bias_loc_x = (S16) (label->bias_loc_x * ratio_width);
                label->bias_loc_y = (S16) (label->bias_loc_y * ratio_height);
                label->color = keytype_list->bl_text1_color;
                ///TODO: revise this code after check what's the font size means.
                label->size = keytype_list->bltext1_size;
            }
            break;

        default:
            break;
        }

    }
    else if (index == 1)
    {
        switch(state)
        {
        case GUI_VK_KEY_STATE_NORMAL:
        case GUI_VK_KEY_STATE_DISABLE:
            label->color = keytype_list->text2_color;
            label->size = keytype_list->text2_size;
            break;
        case GUI_VK_KEY_STATE_HIGHLIGHT:
            label->color = keytype_list->hl_text2_color;
            label->size = keytype_list->hltext2_size;
            break;
        case GUI_VK_KEY_STATE_POPUP:
            if (key->label_balloon_icon != 0 || key->label_balloon_string != NULL)
            {
				//means only show main label if has balloon
                label->label = NULL;
                label->label_icon = 0;
                break;
            }
            else
            {
                label->bias_loc_x = (S16) (label->bias_loc_x * ratio_width);
                label->bias_loc_y = (S16) (label->bias_loc_y * ratio_height);
                label->color = keytype_list->bl_text1_color;
                ///TODO: revise this code after check what's the font size means.
                label->size = keytype_list->bltext1_size;
            }
            break;

        case GUI_VK_KEY_STATE_LONGTAP_POPUP:
            if (key->label_balloon_longpress_icon != 0 || key->lable_balloon_longpress != NULL)
            {
				//means only show main label if has balloon
                label->label = NULL;
                label->label_icon = 0;
                break;
            }
            else
            {
                label->bias_loc_x = (S16) (label->bias_loc_x * ratio_width);
                label->bias_loc_y = (S16) (label->bias_loc_y * ratio_height);
                label->color = keytype_list->bl_text1_color;
                ///TODO: revise this code after check what's the font size means.
                label->size = keytype_list->bltext1_size;
            }
            break;

        default:
            break;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    ret = gui_virtual_keyboard_get_current_key_toggle_state(
            v,
            key,
            &toggle_key);
        
    if (ret)
    {
        //toggle_key = key->toggle_state->toggle_state_key_list[toggle_state_index];
        keytype_list = v->keytype_list + toggle_key->keytype;
        if (index == 0)
        {
            if (toggle_key->label_string != NULL || toggle_key->lable_icon != 0)
            {
                label->label = toggle_key->label_string;
                label->label_icon= toggle_key->lable_icon;
                label->bias_loc_x = (S16) ((float) keytype_list->text1_loc_biasx / 100 * key->width) ;
                label->bias_loc_y = (S16) ((float) keytype_list->text1_loc_biasy / 100 * key->height);
            }
        }
        else if (index == 1)
        {
            if (toggle_key->label_string_aux != NULL || toggle_key->lable_icon_aux != 0)
            {
                label->label = toggle_key->label_string_aux;
                label->label_icon = toggle_key->lable_icon_aux;
                label->bias_loc_x = (S16) ((float) keytype_list->text2_loc_biasx / 100 * key->width) ;
                label->bias_loc_y = (S16) ((float) keytype_list->text2_loc_biasy / 100 * key->height);
            }
        }
        if (index == 0)
        {
            switch(state)
            {
            case GUI_VK_KEY_STATE_NORMAL:
            case GUI_VK_KEY_STATE_DISABLE:
                label->color = keytype_list->text1_color;
                label->size = keytype_list->text1_size;
                if (toggle_key->lable_icon != 0 || toggle_key->label_string != NULL)
                {
                    label->label_icon = toggle_key->lable_icon;
                    label->label = toggle_key->label_string;
                }

                break;
            case GUI_VK_KEY_STATE_HIGHLIGHT:
                label->color = keytype_list->hl_text1_color;
                label->size = keytype_list->hltext1_size;
                if (toggle_key->lable_icon_hl != 0 || toggle_key->label_string != NULL)
                {
                    label->label_icon = toggle_key->lable_icon_hl;
                    label->label = toggle_key->label_string;
                }
                break;
            case GUI_VK_KEY_STATE_POPUP:
                label->color = keytype_list->bl_text1_color;
                label->size = keytype_list->bltext1_size;
                if (toggle_key->label_balloon_icon != 0 || toggle_key->label_balloon_string != NULL)
                {
                    label->label_icon = toggle_key->label_balloon_icon;
                    label->label = toggle_key->label_balloon_string;
                    label->bias_loc_x =  0;
                    label->bias_loc_y =  0;
                }
                else
                {
                    label->bias_loc_x =  (S16) (label->bias_loc_x  * ratio_width);
                    label->bias_loc_y =  (S16) (ratio_height * label->bias_loc_y);
                }

                break;
            case GUI_VK_KEY_STATE_LONGTAP_POPUP:
                label->color = keytype_list->bl_text1_color;
                label->size = keytype_list->bltext1_size;
                if (toggle_key->label_balloon_longpress_icon != 0 || toggle_key->lable_balloon_longpress != NULL)
                {
                    label->label_icon = toggle_key->label_balloon_longpress_icon;
                    label->label = toggle_key->lable_balloon_longpress;
                    label->bias_loc_x =  0;
                    label->bias_loc_y =  0;
                }
                else
                {
                    label->bias_loc_x =  (S16) (label->bias_loc_x  * ratio_width);
                    label->bias_loc_y =  (S16) (ratio_height * label->bias_loc_y);
                }
                break;
            default:
                break;
            }

        }
        else if (index == 1)
        {
            switch(state)
            {
            case GUI_VK_KEY_STATE_NORMAL:
            case GUI_VK_KEY_STATE_DISABLE:
                label->color = keytype_list->text2_color;
                label->size = keytype_list->text2_size;
                if (toggle_key->lable_icon_aux != 0 || toggle_key->label_string_aux != NULL)
                {
                    label->label_icon = toggle_key->lable_icon_aux;
                    label->label = toggle_key->label_string_aux;
                }

                break;
            case GUI_VK_KEY_STATE_HIGHLIGHT:
                label->color = keytype_list->hl_text2_color;
                label->size = keytype_list->hltext2_size;
                if (toggle_key->lable_icon_aux_hl != 0 || toggle_key->label_string_aux != NULL)
                {
                    label->label_icon = toggle_key->lable_icon_aux_hl;
                    label->label = toggle_key->label_string_aux;
                }
                break;
            case GUI_VK_KEY_STATE_POPUP:                
                if (toggle_key->label_balloon_icon != 0 || toggle_key->label_balloon_string != NULL)
                {
					//means only show main label if has balloon 
					label->label = NULL;
                    label->label_icon = 0;
                    break;
                }
                else
                {
                    label->bias_loc_x =  (S16) (label->bias_loc_x  * ratio_width);
                    label->bias_loc_y =  (S16) (ratio_height * label->bias_loc_y);
                    label->color = keytype_list->bl_text2_color;
                    label->size = keytype_list->bltext2_size;
                }
                break;
            case GUI_VK_KEY_STATE_LONGTAP_POPUP:
                if (toggle_key->label_balloon_longpress_icon != 0 || toggle_key->lable_balloon_longpress != NULL)
                {
					//means only show main label if has balloon
                    label->label = NULL;
                    label->label_icon = 0;
                    break;
                }
                else
                {
                    label->bias_loc_x =  (S16) (label->bias_loc_x  * ratio_width);
                    label->bias_loc_y =  (S16) (ratio_height * label->bias_loc_y);
					label->color = keytype_list->bl_text2_color;
                    label->size = keytype_list->bltext2_size;
                }
                break;
            default:
                break;
            }

        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    memset(v->string_buffer,0,sizeof(UI_character_type)*40);

    if (index == 1 && key->label_string != NULL)
    {
        memset(v->string_buffer,0,sizeof(v->string_buffer));
        if (gui_virtual_keyboard_is_label_get_from_vendor(v, key->label_string[0])
            && get_multi_tap_engine_string != NULL)
        {
            S32 length = 0;
            S32 i = 0, j = 0;
            ///TODO: get label from multi-tap engine and caculate co-ordinate
            label->label = get_multi_tap_engine_string(*key->label_string - '0');
            length = mmi_ucs2strlen((const S8 *) label->label);
            for(i = 0; i < length; i++)
            {
                if (label->label[i] != key->label_string[0])
                    v->string_buffer[j++] = label->label[i];
            }
            if (*key->label_string == '1')
            {
                v->string_buffer[3] = '\0';
            }
            else if (j > 4 || g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_ARABIC)
            {
                //v->string_buffer[0] = label->label[0];
                v->string_buffer[1] = '-';
                v->string_buffer[2] = v->string_buffer[j - 1];
                v->string_buffer[3] = '\0';
            }
            label->label = v->string_buffer;
        }
    }
    if (label->label != NULL)
    {
        if (!gui_virtual_keyboard_is_symbol_vk(g_wgui_virtual_keyboard_lang_type))
        {
            if (gui_virtual_keyboard_is_shift_state(v))
            {
                for(i = 0; i < mmi_ucs2strlen((const S8 *) label->label); i++)
                {
                    v->string_buffer[i] = mmi_towupper(label->label[i]);
                }
            }
            else
            {
                for(i = 0; i < mmi_ucs2strlen((const S8 *) label->label); i++)
                {
                    v->string_buffer[i] = mmi_towlower(label->label[i]);
                }
            }
            v->string_buffer[i] = 0;
            label->label = v->string_buffer;
        }
    }
}
MMI_BOOL gui_virtual_keyboard_is_alphanumeric_vk(void)
{
    if(g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_EN_DIALER || (gui_get_virtual_keyboard_callback()->vk_attribute == 2))
    {
        return MMI_TRUE;
    }
        
    return MMI_FALSE;
}

MMI_BOOL gui_virtual_keyboard_is_symbol_vk(gui_virtual_keyboard_language_enum vk_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (vk_type)
    {
    case GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL:
    case GUI_VIRTUAL_KEYBOARD_SYMBOL:
#if defined(__MMI_LANG_THAI__)
    case GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL:
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) 
#if defined(__MMI_LANG_SPANISH__)
    case GUI_VIRTUAL_KEYBOARD_SPANISH_SYMBOL:
#endif
        //#if defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)         
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_1:
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_2:
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_3:
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_SYMBOL_PAGE_4:
    case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE:
    case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_TWO:
    case GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE:
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_1:
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_2:
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_3:
    case GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_CH_SYMBOL_PAGE_4:
        //#endif
#endif
#ifdef __MMI_LANG_PERSIAN__
    case GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL:
#endif /* __MMI_LANG_PERSIAN__ */     

#ifdef __MMI_LANG_ARABIC__
    case GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS:
#endif /* __MMI_LANG_ARABIC__ */

#ifdef __MMI_LANG_URDU__
    case GUI_VIRTUAL_KEYBOARD_URDU_SYMBOLS:
#endif /* __MMI_LANG_URDU__ */

#ifdef __MMI_INDIC_VK_HINDI__
    case GUI_VIRTUAL_KEYBOARD_HINDI_SYMBOLS :
#endif /* __MMI_INDIC_VK_HINDI__ */

#ifdef __MMI_INDIC_VK_TAMIL__
    case GUI_VIRTUAL_KEYBOARD_TAMIL_SYMBOLS:
#endif /* __MMI_INDIC_VK_TAMIL__ */

#ifdef __MMI_INDIC_VK_BENGALI__
    case GUI_VIRTUAL_KEYBOARD_BENGALI_SYMBOLS:
#endif /* __MMI_INDIC_VK_BENGALI__ */
#ifdef __MMI_INDIC_VK_ASSAMESE__
    case GUI_VIRTUAL_KEYBOARD_ASSAMESE_SYMBOLS:
#endif /* __MMI_INDIC_VK_ASSAMESE__ */
#ifdef __MMI_INDIC_VK_PUNJABI__
    case GUI_VIRTUAL_KEYBOARD_PUNJABI_SYMBOLS:
#endif /* __MMI_INDIC_VK_PUNJABI__ */

#ifdef __MMI_INDIC_VK_MARATHI__
    case GUI_VIRTUAL_KEYBOARD_MARATHI_SYMBOLS:
#endif /* __MMI_INDIC_VK_MARATHI__ */

#ifdef __MMI_INDIC_VK_GUJARATI__
    case GUI_VIRTUAL_KEYBOARD_GUJARATI_SYMBOLS:
#endif /* __MMI_INDIC_VK_GUJARATI__ */

#ifdef __MMI_INDIC_VK_KANNADA__
    case GUI_VIRTUAL_KEYBOARD_KANNADA_SYMBOLS:
#endif /* __MMI_INDIC_VK_KANNADA__ */

#ifdef __MMI_INDIC_VK_ORIYA__
    case GUI_VIRTUAL_KEYBOARD_ORIYA_SYMBOLS:
#endif /* __MMI_INDIC_VK_ORIYA__ */

#ifdef __MMI_INDIC_VK_MALAYALAM__
    case GUI_VIRTUAL_KEYBOARD_MALAYALAM_SYMBOLS:
#endif /* __MMI_INDIC_VK_MALAYALAM__ */

#ifdef __MMI_INDIC_VK_TELUGU__
    case GUI_VIRTUAL_KEYBOARD_TELUGU_SYMBOLS:
#endif /* __MMI_INDIC_VK_TELUGU__ */

#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
    case GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS:
#endif 
        /* below check is so that the control doesnot go to the xt9 in case of tray VK*/
        /*  #ifdef __MMI_XT9__
        case GUI_VIRTUAL_KEYBOARD_TRAY:
        #endif*/
    case GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_1:
    case GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_2:
    case GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_3:
    case GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_1:
    case GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_2:
    case GUI_VIRTUAL_KEYBOARD_ZH_SYMBOL_3:
    case GUI_VIRTUAL_KEYBOARD_EN_PHONE_SYMBOL:
    case GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_1:
    case GUI_VIRTUAL_KEYBOARD_EN_SYMBOL_CUSTOM_2:
        ret = MMI_TRUE;
        break;
    default:
        ret = MMI_FALSE;
        break;
    }

    return ret;
}

static MMI_BOOL gui_virtual_keyboard_is_main_label_from_0_9(UI_character_type label_ch)
{
    if (label_ch >= '1' && label_ch <= '9')
        return MMI_TRUE;
    else
        return MMI_FALSE;
}

static MMI_BOOL gui_virtual_keyboard_is_phonetic_vk()
{
    const sIMEModeDetails* mode_detail;
    mode_detail = mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode());
    if (mode_detail->Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC
        || mode_detail->Lang_Special_Attrib & IME_LANG_ATTR_STROKE
        || mode_detail->Lang_Special_Attrib & IME_LANG_ATTR_SYMBOLIC
        || mode_detail->Lang_Special_Attrib & IME_LANG_ATTR_NUMBERIC)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

static MMI_BOOL gui_virtual_keyboard_is_label_get_from_vendor(
            gui_virtual_keyboard_struct_p v, UI_character_type label_ch)
{
    if (gui_virtual_keyboard_is_alphanumeric_vk() 
        && !gui_virtual_keyboard_is_symbol_vk(g_wgui_virtual_keyboard_lang_type)
        && !gui_virtual_keyboard_is_phonetic_vk())
    {
        if (gui_virtual_keyboard_is_main_label_from_0_9(label_ch))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}

void gui_virtual_keyboard_get_key_main_label(
    gui_virtual_keyboard_struct_p v,
    const gui_virtual_keyboard_key_struct* key,
    gui_virtual_keyboard_key_label_info_struct_p label,
    gui_virtual_keyboard_key_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type ch;
    gui_virtual_keyboard_rect_struct rect;

    gui_virtual_keyboard_main_label = 0;
    gui_virtual_keyboard_get_label_int(
        v,
        key,
        label,
        state,
        0);
    if (label->label != NULL && gui_virtual_keyboard_is_alphanumeric_vk())
    {
        ch = *label->label;
        if (ch >= '0' && ch <= '9')
        {
            gui_virtual_keyboard_get_key_rect(key, &rect);
            //                label->bias_loc_x = rect.width * GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_KEY_MAIN_LABEL_BIAOS_X;
            //                label->bias_loc_y = rect.height * GUI_VIRTUAL_KEYBOARD_ALPHANUMERIC_KEY_MAIN_LABEL_BIAOS_y;
        }
    }
    if (state == GUI_VK_KEY_STATE_DISABLE)
    {
        label->fomat_color = gui_virtual_keyboard_main_label_color_from_theme(state);
    }
}


void gui_virtual_keyboard_get_key_aux_label(
    gui_virtual_keyboard_struct_p v,
    const gui_virtual_keyboard_key_struct* key,
    gui_virtual_keyboard_key_label_info_struct_p label,
    gui_virtual_keyboard_key_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //UI_character_type* ch;
    //gui_virtual_keyboard_rect_struct rect;
    //U32 length;

    //gui_virtual_keyboard_get_key_rect(key, &rect);
    gui_virtual_keyboard_get_label_int(
        v,
        key,
        label,
        state,
        1);
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
	label->bias_loc_y += 2;
#endif
    if (state == GUI_VK_KEY_STATE_DISABLE)
    {
        label->fomat_color = gui_virtual_keyboard_main_label_color_from_theme(state);
    }
}


static void gui_virtual_keyboard_show_label(
    gui_virtual_keyboard_key_label_info_struct label_string,
    gui_virtual_keyboard_rect_struct rect,
    gui_virtual_keyboard_key_state_enum key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type* label = NULL;
    U32 label_color = label_string.color;
    U16 label_icon = label_string.label_icon;
    U8 font_size = label_string.size;
    S16 bias_loc_x = label_string.bias_loc_x, bias_loc_y = label_string.bias_loc_y;

    label = label_string.label;

#if 1
    //defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (label_string.label != NULL)
    {
        S32 string_width, string_height, baseline = 0, ascent = 0, descent = 0,start_x,start_y;
		stFontAttribute font = {0};

#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
		mmi_fe_get_string_info_param_struct query = {0};
		query.String = (U8*)label;
		query.n = mmi_ucs2strlen((const char*)label);

        /* Using key structure to draw the fonts */


			font.size = font_size;
#else
			font.size = FONT_PIXEL_SIZE(font_size);
#endif
        gui_set_font(&font);///TODO: change to gdi function
        if (key_state == GUI_VK_KEY_STATE_DISABLE)
        {
            gui_set_text_color(label_string.fomat_color);  
        }

        else
        {
            gui_set_text_color(gui_color32((U8)(label_color>>16),
                (U8)(label_color>>8), 
                (U8)label_color, 
                (U8)(label_color>>24)));
        }

#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
        mmi_fe_get_string_widthheight(&query);
		ascent = query.baseline;
		string_width = query.pWidth;
		string_height = query.pHeight;
#else
		string_width = gui_get_string_width(label);
        string_height = gui_get_string_height(label);
        mmi_fe_get_char_info_of_all_lang(font.size,&string_height,&ascent,&descent);
#endif

        start_y = rect.y + VKBD_DIFF_HALF(rect.height, string_height) + bias_loc_y;

        //gui_print_character_at_xy(key_char, x + (bg_width - char_width)/2, y + (bg_height - char_height)/2);
        if (!mmi_fe_get_r2l_state())
        {
            start_x = rect.x + VKBD_DIFF_HALF(rect.width, string_width) + bias_loc_x;
        }
        else
        {
            start_x = rect.x + VKBD_DIFF_HALF(rect.width, string_width) + bias_loc_x + string_width;
        }

        mmi_fe_show_string_baseline(start_x,
            start_y,
            (PU8)label, ascent,BIDI_L);
    }
    else
#endif /* __MMI_VECTOR_FONT_SUPPORT__*/
        if (label_icon != 0)
        {
            S32 glyph_width,glyph_height;
            //gdi_color act_color;
            gui_measure_image((PU8)GetImage(label_icon), &glyph_width, &glyph_height);

            gdi_image_draw_blend2layers(rect.x + VKBD_DIFF_HALF(rect.width, glyph_width) + label_string.bias_loc_x,
                rect.y + VKBD_DIFF_HALF(rect.height, glyph_height) + label_string.bias_loc_y,
                (PU8)GetImage(label_icon));

            /*
            act_color = gdi_act_color_from_rgb(icon_color.alpha,icon_color.r,icon_color.g,icon_color.b);
            gdi_image_ab2_draw_with_color(
            (PU8) GetImage(label_icon),
            0,
            act_color,
            rect.x + VKBD_DIFF_HALF(rect.width, glyph_width) + label_string.bias_loc_x,
            rect.y + VKBD_DIFF_HALF(rect.height, glyph_height) + label_string.bias_loc_y,
            glyph_width,
            glyph_height,
            0);
            */
        }
}


void gui_virtual_keyboard_get_key_rect(
    const gui_virtual_keyboard_key_struct* key,
    gui_virtual_keyboard_rect_struct_p rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(key!=NULL && rect!= NULL);
    rect->x = key->pos_x;
    rect->y = key->pos_y;
    rect->height = key->height;
    rect->width = key->width;
}


void gui_virtual_keyboard_translate_index_to_pointer(
    U32 index, 
    const gui_virtual_keyboard_key_struct** key)
{
    int i,ret = 0;
    gui_virtual_keyboard_struct_p v = gui_get_virtual_keyboard_callback();

    *key = NULL;
    for(i = 0; i < v->row_num; i++)
    {
        if (gui_virtual_keyboard_is_active_row_id(v,i))
        {
            ret += v->row_list[i].key_count;
            if ((S32) index >= ret)
                continue;
            ret -= v->row_list[i].key_count;
            *key = &v->row_list[i].key_list[index - ret];
            return;
        }
    }
    MMI_ASSERT(*key != NULL);

}


U32 gui_virtual_keyboard_get_button_count(
    gui_virtual_keyboard_struct_p v)
{
    U32 i,ret = 0;
    for(i = 0; i < v->row_num; i++)
    {
        if (gui_virtual_keyboard_is_active_row_id(v,i))
            ret += v->row_list[i].key_count;
    }
    return ret;
}


void gui_virtual_keyboard_get_key_bg_img(
    gui_virtual_keyboard_struct_p v,
    const gui_virtual_keyboard_key_struct* key,
    PU16 img_id,
    gui_virtual_keyboard_key_state_enum state)
{
    const gui_virtual_keyboard_key_struct * toggle_key;
    const gui_virtual_keyboard_keytype_struct * key_type;
    MMI_BOOL ret;

    ret = gui_virtual_keyboard_get_current_key_toggle_state(
        v,
        key,
        &toggle_key);
    if (ret)
    {
        key_type = &v->keytype_list[toggle_key->keytype];
    }
    else
    {
        key_type = &v->keytype_list[key->keytype];
    }

    switch(state)
    {
    case GUI_VK_KEY_STATE_NORMAL:
    case GUI_VK_KEY_STATE_DISABLE:
        *img_id = key_type->bg;
        break;
    case GUI_VK_KEY_STATE_HIGHLIGHT:
        *img_id = key_type->hlbg;
        break;
    case GUI_VK_KEY_STATE_POPUP:
    case GUI_VK_KEY_STATE_LONGTAP_POPUP:
        *img_id =  key_type->balloonbg;
    }
}


static void gui_virtual_keyboard_get_key_hint_size_ratio(
    gui_virtual_keyboard_struct_p v,
    const gui_virtual_keyboard_key_struct* key,
    float * ratio_width,
    float * ratio_height)
{
    *ratio_width = v->keytype_list[key->keytype].balloon_width_ratio;
    *ratio_height = v->keytype_list[key->keytype].balloon_height_ratio;
}


void gui_virtual_keyboard_get_key_hint_rect(
    gui_virtual_keyboard_struct_p v,
    const gui_virtual_keyboard_key_struct* key,
    gui_virtual_keyboard_rect_struct_p rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float ratio_width,ratio_height;
    U16 offset;
    /*----------------------------------------------------------------*/
    /* code body                                                    */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(key!=NULL && rect!= NULL);

    gui_virtual_keyboard_get_key_rect(key,rect);
    gui_virtual_keyboard_get_key_hint_size_ratio(v,key,&ratio_width,&ratio_height);

    rect->height = (U16)(ratio_height * rect->height);
    rect->width = (U16)(ratio_width * rect->width);

    // check the boder of screen and keyboard
    offset = VKBD_DIFF_HALF(rect->width,key->width);
    if (key->pos_x <= offset)
        rect->x = v->x;
    else if (key->pos_x + key->width + offset >= v->width)
        rect->x = v->width + v->x - rect->width ;
    else
        rect->x = key->pos_x + v->x - offset;
    rect->y = key->pos_y + v->y - rect->height;

}


void gui_virtual_keyboard_set_active_row(gui_virtual_keyboard_struct* v,S16 row_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    v->active_row = (S8) row_id;
}

static MMI_BOOL gui_virtual_keyboard_is_active_row_id(gui_virtual_keyboard_struct* v, U16 row)
{
    MMI_ASSERT(v->row_num > row);
    if (v->row_list[row].row_id == -1 || v->row_list[row].row_id == v->active_row)
        return MMI_TRUE;

    return MMI_FALSE;
}


static MMI_BOOL gui_virtual_keyboard_get_current_key_toggle_state(
    gui_virtual_keyboard_struct* v,
    const gui_virtual_keyboard_key_struct* key,
    const gui_virtual_keyboard_key_struct ** toggle_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i,j;
    S32 toggle_state_num;
    const U8* toggle_state_list;
    if (key->toggle_state == NULL)
        return MMI_FALSE;
    if (key->toggle_state->state_num == 0 ||  key->toggle_state->state_id_list == 0)
        return MMI_FALSE;
    toggle_state_num = key->toggle_state->state_num;
    toggle_state_list = key->toggle_state->state_id_list;
    for(i = 0; i < toggle_state_num; i++)
        for(j = 0; j < GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_END; j++)
            if (v->toggle_state_ids[j] == toggle_state_list[i])
            {
                *toggle_key = &((*key->toggle_state->toggle_state_key_list)[i]);
                MMI_ASSERT(key->toggle_state->toggle_state_key_list[i] != NULL);
                return MMI_TRUE;
            }
            return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_show_image
* DESCRIPTION
*  
* PARAMETERS
*     
* RETURNS
*  void
*****************************************************************************/
__inline static gui_virtual_keyboard_show_image(gui_virtual_keyboard_struct* v, S32 x, S32 y, PU8 img, gdi_handle source_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    {
        gdi_push_and_set_alpha_blending_source_layer(source_layer);
        gui_show_image(x, y, img);//this function can do what         
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

}


__inline void get_glyph_resize(
                               U16 x,U16 y,U16 width,U16 height,
                               U16 glyph_width,U16 glyph_height,
                               PU16 x1,PU16 x2,PU16 y1,PU16 y2,
                               PU16 resize_x, PU16 resize_y, PU16 resize_width, PU16 resize_height ,S32 i)
{
    U16 clip_x[4], clip_y[4];
    U32 row,column;
    row = i/3;
    column = i%3;

    clip_x[0] = x;
    clip_y[0] = y;
    clip_x[1] = x + glyph_width/3;
    clip_y[1] = y + glyph_height/3;
    clip_x[2] = x + width - glyph_width/3;
    clip_y[2] = y + height - glyph_height/3;
    clip_x[3] =  x + width;
    clip_y[3] =  y + height;

    *x1 = clip_x[column];
    *x2 = clip_x[column + 1];
    *y1 = clip_y[row];
    *y2 = clip_y[row +1];

    switch(i)
    {
    case 0:
    case 2:
    case 6:
    case 8: 
        *resize_width = glyph_width;
        *resize_height = glyph_height;
        break;
    case 1:
    case 7:
        *resize_width = width;
        *resize_height = glyph_height;
        break;
    case 3:
    case 5:
        *resize_width = glyph_width;
        *resize_height = height;
        break;
    case 4:
        *resize_width = width;
        *resize_height = height;
        break;
    default:
        MMI_ASSERT(0);
    }
    switch(i)
    {
    case 0:
    case 3: 
    case 4:
    case 1:
        *resize_x = clip_x[0];
        *resize_y = clip_y[0];
        break;
    case 2:
    case 5:
        *resize_x = clip_x[3] - glyph_width;
        *resize_y = clip_y[0];
        break;
    case 6:
    case 7:
        *resize_x = clip_x[0];
        *resize_y = clip_y[0] - glyph_height;
        break;
    case 8:
        *resize_x = clip_x[0] - glyph_width ;
        *resize_y = clip_y[0] - glyph_height; 
        break;
    default:
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_show_image_with_dimension
* DESCRIPTION
*  
* PARAMETERS
*     
* RETURNS
*  void
*****************************************************************************/
__inline static gui_virtual_keyboard_show_image_with_dimension(gui_virtual_keyboard_struct* v, S32 x, S32 y, S32 width, S32 height, PU8 img, gdi_handle source_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 x1,x2,y1,y2,resize_x,resize_y,resize_width,resize_height;
    S32 glyph_width,glyph_height;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/




    /* TODO: make sure the function gdi_image_draw_resized is woke fine for 9-slice
    */

    gui_measure_image(img, &glyph_width, &glyph_height);

    x1 = x;
    x2 = x + width -1;
    y1 = y;
    y2 = y + height -1;
    for(i = 0; i < 9; i++)
    {
        get_glyph_resize(
            x,
            y,
            width,
            height,
            (U16) glyph_width,
            (U16) glyph_height,
            &x1,
            &x2,
            &y1,
            &y2,
            &resize_x, 
            &resize_y, 
            &resize_width, 
            &resize_height,
            i);

        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);

        gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);

        gdi_image_draw_resized(
            resize_x,
            resize_y,
            resize_width,
            resize_height,
            img); 

        gdi_pop_and_restore_alpha_blending_source_layer();

        gui_pop_clip();
    }

}


MMI_BOOL gui_virtual_keyboard_Check_alphanumeric_vk_0_to_9_key(
    gui_virtual_keyboard_struct *v,
    S16 x,
    S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}


#ifdef __MMI_VK_POPUP_HINT__
/***************************************************************************** 
* FUNCTION
*  gui_virtual_keyboard_redraw_popup_hint_content
* DESCRIPTION
*  Redraw the key's popup hint content
* PARAMETERS
*  v       [IN/OUT]         
* RETURNS
*  
*****************************************************************************/
void gui_virtual_keyboard_redraw_popup_hint_content(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}


MMI_BOOL gui_virtual_keyboard_is_popup_can_be_shown(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct *key)
{
    MMI_BOOL ret = MMI_FALSE;
    MMI_ASSERT(v != NULL && key != NULL);
    if (v->keytype_list[key->keytype].balloonbg != 0)
    {
        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }
    return ret;
}


/***************************************************************************** 
* FUNCTION
*  gui_virtual_keyboard_redraw_popup_hint
* DESCRIPTION
*  Redraw the key's popup hint
* PARAMETERS
*  v       [IN/OUT]         
* RETURNS
*  
*****************************************************************************/
static void gui_virtual_keyboard_redraw_popup_hint(
    gui_virtual_keyboard_struct *v,
    MMI_BOOL cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_show_popup_hint(v,GUI_VK_KEY_STATE_POPUP,cache);
}
#endif /* __MMI_VK_POPUP_HINT__ */


/*****************************************************************************
* FUNCTION
*  gui_vk_clear_cache
* DESCRIPTION
*  This function clears the cache in gui_virtual_keyboard_show. We need this fuction becuase in MAUI_02652563 the vk is updated late so it picks wrong cache
*   
*  image for cache.
* PARAMETERS
*  v       [IN]     
* RETURNS
*  void
*****************************************************************************/
void gui_vk_clear_cache(gui_virtual_keyboard_struct *v)
{

    // v->selected_key.is_key_cached = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_clear_selected_key
* DESCRIPTION
*  
* PARAMETERS
*  v       [IN]     
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_clear_selected_key(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT( v!= NULL);

    if (v->selected_key.is_key_cached == MMI_TRUE)
    {
        mmi_frm_scrmem_free(v->selected_key.key_bitmap.buf_ptr);
        v->selected_key.key_bitmap.buf_ptr = NULL;
    }

    v->selected_key.index = NULL;
    v->key_down_accepted = MMI_FALSE;
    v->selected_key.is_key_cached = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_draw_key_shape
* DESCRIPTION
*  draw shape of a key
* PARAMETERS
*  v               [IN/OUT]    Is the virtual keyboard object
*  x               [IN]        key's x pos
*  y               [IN]        key's y pos
*  width           [IN]        key's width
*  height          [IN]        key's height
* RETURNS
*  
*****************************************************************************/
static void gui_virtual_keyboard_draw_key_shape(
    gui_virtual_keyboard_struct *v,
    S32 x,
    S32 y,
    S32 width,
    S32 height,
    color frame_color,
    color fill_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_is_selected_key
* DESCRIPTION
*  
* PARAMETERS
*  v           [IN/OUT]    Virtual Keyboard object
*  index       [IN]        index of key in key list
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_selected_key(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(v != NULL);
    if (index == v->selected_key.index)
        return MMI_TRUE;

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_is_kept_down_key
* DESCRIPTION
*  
* PARAMETERS
*  v           [IN/OUT]    Virtual Keyboard object
*  index       [IN]        index of key in key list
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_kept_down_key(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_is_disabled_key
* DESCRIPTION
*  
* PARAMETERS
*  v           [IN/OUT]    Virtual Keyboard object
*  index       [IN]        index of key in key list
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_is_disabled_key(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_virtual_keyboard_key_struct* key;
    U16 key_char;
    UI_character_type ch = 0, tmp;
    const UI_character_type *pch;
    gui_virtual_keyboard_pen_enum key_event;
    gui_virtual_keyboard_pen_enum *ptr, tmp_event;
    MMI_BOOL disabled = MMI_TRUE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(index < v->key_count);
    /* get the key from key list by index */
    key = index;
    /* parse the key content from content */
    gui_virtual_keyboard_get_selected_key_int(
        v,
        key,
        MMI_PEN_EVENT_UP,
        &key_char,
        &key_event);
    MMI_DBG_ASSERT(!((key_char != 0) &&
        ((key_event >= GUI_VKBD_PEN_NONE) &&
        (key_event < GUI_VKBD_PEN_MAX))));
    ch = (UI_character_type)key_char;
#if defined(__MMI_INDIC_ALG__)
    if (IRE_INDIC_LANGUAGE_RANGE(ch) 
        && ire_IsValidInput(&ch, 2) == MMI_FALSE)
    {
        return MMI_TRUE;
    }
#endif
#if defined(__MMI_LANG_THAI__)
    if (THAI_CHAR_RANGE(ch) 
        && is_thai_valid_input(&ch, 2) == MMI_FALSE)
    {
        return MMI_TRUE;
    }
#endif

    if (v->disable_keys.allowed_chars)
    {
        /* gui_virtual_keyboard_set_allowed_characters() and 
        gui_virtual_board_set_disable_list() are mutually-exclusive */
        MMI_DBG_ASSERT(v->disable_keys.disabled_chars[0] == 0);

        /* we will allow IME to enable special symbols even allowed_characters has content */
        for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
        {
            if (v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_NONE)
            {
                break;
            }
            MMI_DBG_ASSERT(
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_HIDE ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_SHOW ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_CAPSLOCK ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_SYMBPICKER ||
                v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_DISPLAY_CALLBACK);
        }

        switch (key_event)
        {
        case GUI_VKBD_PEN_HIDE:
        case GUI_VKBD_PEN_SHOW:
        case GUI_VKBD_PEN_CAPSLOCK:
        case GUI_VKBD_PEN_SYMBPICKER:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYMBPICKER:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_CAPS_LOCK:
        case GUI_VKBD_PEN_DISPLAY_CALLBACK:
        case GUI_VKBD_PEN_CHANGE_MODE:
        case GUI_VKBD_PEN_NUM_AND_SYM:
            {
                disabled = MMI_FALSE;
                for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
                {
                    if (v->disable_keys.disabled_symbols[i] == GUI_VKBD_PEN_NONE)
                    {
                        break;
                    }
                    if (v->disable_keys.disabled_symbols[i] == key_event)
                    {
                        disabled = MMI_TRUE;
                        break;
                    }
                }
            }
            break;

        case GUI_VKBD_PEN_BAKSPACE:
        case GUI_VKBD_PEN_DISPLAY_AREA:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE:
        case GUI_VKBD_PEN_BACK_TO_LANG:
        case GUI_VKBD_PEN_V3_SYMBOLE_SWITCH:
        case GUI_VKBD_PEN_V3_CHAR_I_STRING:
        case GUI_VKBD_PEN_V3_SYMBOL_PAGE1:
        case GUI_VKBD_PEN_V3_SYMBOL_PAGE2:
        case GUI_VKBD_PEN_V3_SYMBOL_PAGE3:
        case GUI_VKBD_PEN_V3_CUSTOM_SYMBOLE_SWITCH:
        case GUI_VKBD_PEN_V3_CUSTOM_SYMBOL_PAGE1:
        case GUI_VKBD_PEN_V3_CUSTOM_SYMBOL_PAGE2:
            /* GUI_VKBD_PEN_DISPLAY_AREA is always enabled because it's display only */
            disabled = MMI_FALSE;
            break;
        case GUI_VKBD_PEN_V3_MOVE_LEFT:
        case GUI_VKBD_PEN_V3_MOVE_RIGHT:
			disabled = MMI_FALSE;
            for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
            {
                if (v->disable_keys.disabled_symbols[i] == key_event)
                {
                    disabled = MMI_TRUE;
                    break;
                }
            }
            break;

        case GUI_VKBD_PEN_HANDWRITING:
        case GUI_VKBD_PEN_DOT_COM:
        case GUI_VKBD_PEN_DOT_ORG:
        case GUI_VKBD_PEN_DOT_NET:
        case GUI_VKBD_PEN_DOT_GOV:
        case GUI_VKBD_PEN_DOT_EDU:
        case GUI_VKBD_PEN_DOT_MIL:
		case GUI_VKBD_PEN_V3_DOT_ORG:
		case GUI_VKBD_PEN_V3_DOT_NET:
		case GUI_VKBD_PEN_V3_DOT_EDU:
            disabled = MMI_FALSE;
            break;

        case GUI_VKBD_PEN_NEWLINE:
        case GUI_VKBD_PEN_ALPHANUMERIC_NEWLINE:
            ch = (UI_character_type)'\n';
            key_event = GUI_VKBD_PEN_CHAR_I;
            break;

        case GUI_VKBD_PEN_SPACE:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE:
            ch = (UI_character_type)' ';
            key_event = GUI_VKBD_PEN_CHAR_I;
            break;
            /* matrix key event is allowed. */    
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_0:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_STAR:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_POUND:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HANDWRITING:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_NUM:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYM_LOCK:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYM_PREV_PAGE:
        case GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE:
        case GUI_VKBD_PEN_ALPHANUMERIC_CHANGE_MODE:
        case GUI_VKBD_PEN_ALPHANUMERIC_DOT_COM:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_BACK_TO_LANG:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_HIDE:
            /* Dialer Events For VK*/
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_2:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_3:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_4:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_5:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_6:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_7:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_8:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_9:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND:
            //case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
            disabled = MMI_FALSE;
            if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_ONE)
            {
                if (key_event == GUI_VKBD_PEN_ALPHANUMERIC_SYM_PREV_PAGE)
                    disabled=MMI_TRUE;
            }
            else if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_INTERNET_SYM_PAGE_THREE)
            {
                if (key_event == GUI_VKBD_PEN_ALPHANUMERIC_SYM_NEXT_PAGE)
                    disabled=MMI_TRUE;
            }
            break;

        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL1:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_CALL2:
        case GUI_VKBD_PEN_ALPHANUMERIC_KEY_VIDEO_CALL:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_N_CALL:
        case GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_E_CALL:
            disabled = MMI_FALSE;
            for (i = 0;  i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
            {
                if (v->disable_keys.disabled_symbols[i] == key_event)
                {
                    disabled = MMI_TRUE;
                    break;
                }
            }
            break ;                
        }

        if (ch)
        {
            pch = v->disable_keys.allowed_chars;

            for (i = 0; pch[i] != 0; i++)
            {
                tmp = pch[i];

                /* Is the char in consecutive characters */
                if ((tmp == (UI_character_type)'-') && (i > 0) && pch[i + 1])
                {
                    if (ch >= pch[i - 1] && ch <= pch[i + 1])
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                    i++;
                }
                else
                {
                    if (tmp == ((UI_character_type)'\\') && pch[i + 1])
                    {
                        tmp = pch[++i];
                    }

                    if (tmp == ch)
                    {
                        disabled = MMI_FALSE;
                        break;
                    }
                }
            }
        }

        return disabled;
    }
    else /* disabled chars & symbols */
    {
        /* if key's content is a char, we need give it a GUI_VKBD_PEN_CHAR_I event */
        if (key_char != 0)
        {
            key_event = GUI_VKBD_PEN_CHAR_I;
        }

        if (key_event == GUI_VKBD_PEN_CHAR_I)
        {
            pch = v->disable_keys.disabled_chars;

            if (ch == 0)
            {
                return MMI_TRUE;
            }

#if defined(__MMI_INDIC_VK__)
            if (!ire_vk_get_grey() &&
                IRE_INDIC_LANGUAGE_RANGE(ch) &&
                ire_IsValidInput(&ch, 2) == MMI_FALSE)
            {
                return MMI_TRUE;
            }
#endif /* defined(__MMI_INDIC_VK__) */ 

            while ((tmp = *pch++) != 0)
            {
                if (tmp == ch)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
        else if (key_event == GUI_VKBD_PEN_NONE)
        {
            return MMI_TRUE;
        }
        else
        {
            ptr = v->disable_keys.disabled_symbols;

            while ((tmp_event = *ptr++) != GUI_VKBD_PEN_NONE)
            {
                if (tmp_event == key_event)
                {
                    return MMI_TRUE;
                }
            }

            return MMI_FALSE;
        }
    }

}


static color gui_virtual_keyboard_get_theme_color(
    gui_virtual_keyboard_struct *v,
    gui_virtual_keyboard_key_state_enum key_state,
    S32 main_or_aux)
{
    color result;

    memset(&result, 0, sizeof(result));
    if (main_or_aux) // main label color
    {
        switch(key_state)
        {
        case GUI_VK_KEY_STATE_NORMAL:
            //COVERT_DWORD_TO_COLOR(result,0xFF000000);
            result = v->theme->key_up_text_color;
            break;
        case GUI_VK_KEY_STATE_HIGHLIGHT:
        case GUI_VK_KEY_STATE_POPUP:
            //COVERT_DWORD_TO_COLOR(result,0xFFFFFFFF);
            result = v->theme->key_down_text_color;
            break;
        case GUI_VK_KEY_STATE_DISABLE:
            //COVERT_DWORD_TO_COLOR(result,0xFFF0F0F0);
            result = v->theme->key_disable_text_color;
            break;
        }
    }
    else  
    {
        switch(key_state)
        {
        case GUI_VK_KEY_STATE_NORMAL:
            //COVERT_DWORD_TO_COLOR(result,0xFF000000);
            result = v->theme->key_up_text_color;
            break;
        case GUI_VK_KEY_STATE_HIGHLIGHT:
        case GUI_VK_KEY_STATE_POPUP:
            //COVERT_DWORD_TO_COLOR(result,0xFFFFFFFF);
            result = v->theme->key_down_text_color;
            break;
        case GUI_VK_KEY_STATE_DISABLE:
            //COVERT_DWORD_TO_COLOR(result,0xFFF0F0F0);
            result = v->theme->key_disable_text_color;
            break;
        }
    }
    return result;
}

static color gui_virtual_keyboard_main_label_color_from_theme(
    gui_virtual_keyboard_key_state_enum key_state)
{
    gui_virtual_keyboard_struct* v = gui_get_virtual_keyboard_callback();
    return gui_virtual_keyboard_get_theme_color(v,key_state,0);
}


static color gui_virtual_keyboard_aux_label_color_from_theme(
    gui_virtual_keyboard_key_state_enum key_state)
{
    gui_virtual_keyboard_struct* v = gui_get_virtual_keyboard_callback();
    return gui_virtual_keyboard_get_theme_color(v,key_state,1);
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_draw_key
* DESCRIPTION
*  draw one key of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard object
*  i       [IN]            index of the key need draw
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_draw_key_int(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct* index,
    S16 x,
    S16 y,
    gui_virtual_keyboard_key_state_enum key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_virtual_keyboard_key_struct* key = index;
    gui_virtual_keyboard_rect_struct rect;

    U16 img_id = NULL;
    U16 start_x,start_y,width,height;
    gui_virtual_keyboard_key_label_info_struct main_label, aux_label;
    S32 baseline = 0, ascent = 0, descent = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_get_key_bg_img(v,key,&img_id,key_state);
    gui_virtual_keyboard_get_key_rect(key,&rect);

    /* parse the key infomation from service or from layout */

    start_x = rect.x + v->margin_x + v->x;
    start_y = rect.y + v->margin_y + v->y;
    width = rect.width - 2*v->margin_x;
    height = rect.height - 2*v->margin_y;
    rect.x += v->x;
    rect.y += v->y;



    if (key_state == GUI_VK_KEY_STATE_DISABLE)
    {
        gdi_image_draw_resized_blend2layers(
            (S32)start_x, 
            (S32)start_y, 
            (S32)width,
            (S32)height,
            (PU8)get_image(img_id));
    }
    else if (key_state == GUI_VK_KEY_STATE_HIGHLIGHT)
    {
        /* For handling 9 slice images */
        gdi_image_draw_resized_blend2layers(
            (S32)start_x, 
            (S32)start_y, 
            (S32)width,
            (S32)height,
            (PU8)get_image(img_id));
    }
    else
    {
        gdi_image_draw_resized_blend2layers(
            (S32)start_x, 
            (S32)start_y, 
            (S32)width,
            (S32)height,
            (PU8)get_image(img_id));
    }            
    gui_set_font(v->theme->text_font);
    gui_virtual_keyboard_get_key_main_label(v,key,&main_label,key_state);
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
	main_label.size = VIRTUAL_KEYBOARD_FONT;
#endif
    gui_virtual_keyboard_show_label(main_label, rect, key_state);

    gui_virtual_keyboard_get_key_aux_label(v,key,&aux_label,key_state);
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
	aux_label.size = VIRTUAL_KEYBOARD_FONT;
#endif
    gui_virtual_keyboard_show_label(aux_label,rect, key_state);

    if (key_state == GUI_VK_KEY_STATE_DISABLE)
    {
        gdi_effect_alpha_blending_rect(
            (gdi_handle)gdi_act_layer,
            start_x,
            start_y,
            start_x + width - 1,
            start_y + height - 1,
            50,
            127,
            127,
            127);
    }
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_draw_key
* DESCRIPTION
*  draw one key of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard object
*  i       [IN]            index of the key need draw
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_draw_key(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_virtual_keyboard_key_struct* key;
    gui_virtual_keyboard_pen_enum key_event;
    U16 key_char = 0;
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    U32 ind = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(index < v->key_count);

    /* get the key from key list by index */
    key = index;

    x1 = v->x + key->pos_x;
    y1 = v->y + key->pos_y;
    x2 = x1 + key->width - 1;
    y2 = y1 + key->height - 1;

    /* parse the key content from content */
    key_char = (U16)GUI_VK_GET_KEY_CHAR(key->code);
    key_event = (gui_virtual_keyboard_pen_enum) GUI_VK_GET_KEY_EVENT(key->code);

    /* assert this key's content is not NULL */
    MMI_DBG_ASSERT(!((key_char == 0) &&
        (key_event == GUI_VKBD_PEN_NONE ||
        key_event >= GUI_VKBD_PEN_MAX)));
    x1 = x1 + v->margin_x;
    y1 = y1 + v->margin_y;
    x2 = x2 - v->margin_x;
    y2 = y2 - v->margin_y;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);


    if (gui_virtual_keyboard_is_disabled_key(v, key))
    {
        gui_virtual_keyboard_draw_key_int(
            v, 
            key, 
            x1, 
            y1, 
            GUI_VK_KEY_STATE_DISABLE);
    }
    else if (gui_virtual_keyboard_is_kept_down_key(v, key) || gui_virtual_keyboard_is_selected_key(v, key))
    {
        if (gui_virtual_keyboard_is_selected_key(v, key))
        {
            if (gui_virtual_keyboard_need_to_recache)
            {
                gui_virtual_keyboard_draw_key_int(
                    v, 
                    key, 
                    x1, 
                    y1, 
                    GUI_VK_KEY_STATE_NORMAL);
                gui_virtual_keyboard_discard_cache_and_recache_normal_key(v);
                gui_virtual_keyboard_need_to_recache = MMI_FALSE;
            }
        }
        gui_virtual_keyboard_draw_key_int(
            v, 
            key, 
            x1, 
            y1, 
            GUI_VK_KEY_STATE_HIGHLIGHT);

    }
    else
    {
        gui_virtual_keyboard_draw_key_int(
            v, 
            key, 
            x1, 
            y1, 
            GUI_VK_KEY_STATE_NORMAL);

    }

    gui_pop_clip();

}



/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_default_hide_function
* DESCRIPTION
*  
* PARAMETERS
*  x1      [IN]
*  y1      [IN]
*  x2      [IN]
*  y2      [IN]
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_default_hide_function(
    S32 x1,
    S32 y1,
    S32 x2,
    S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_default_display_callback_function
* DESCRIPTION
*  
* PARAMETERS
*  text      [IN]
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_default_display_callback_function(
    gui_virtual_keyboard_pen_enum pen_symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_show_content_by_align
* DESCRIPTION
*  The function display the key's content
* PARAMETERS
*  ch                  [IN]    character to be displayed
*  text                [IN]    text to be displayed
*  image               [IN]    image to be displayed
*  key_x               [IN]    start x point of key
*  key_y               [IN]    start y point of key
*  key_width           [IN]    width of key
*  key_height          [IN]    height of key
*  glyph_width         [OUT]   content width
*  glyph_height        [OUT]   content height
*  align               [IN]    align type of key
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_show_content_by_align(
    gui_virtual_keyboard_struct* v,
    UI_character_type ch,
    PU8 text,
    PU8 image,
    S32 key_x,
    S32 key_y,
    S32 key_width,
    S32 key_height,
    S32 *glyph_width,
    S32 *glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_translate_pen_position
* DESCRIPTION
*  
* PARAMETERS
*  v       [IN/OUT]         
*  x       [IN]        
*  y       [IN]        
*  s       [OUT]         
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_translate_pen_position(
    gui_virtual_keyboard_struct *v,
    S16 x,
    S16 y,
    const gui_virtual_keyboard_key_struct** index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i,j;
    S32 key_x, key_y;
    S32 key_x_pre, key_y_pre;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    *index = NULL;

    if (y < v->y + v->row_list[0].key_list[0].pos_y)
        return MMI_FALSE;

    for (i = 0; i < v->row_num; i++)
    {
        if (!gui_virtual_keyboard_is_active_row_id(v,i))
            continue;
        key_y_pre = v->y + v->row_list[i].key_list[0].pos_y;
        key_y = v->y + v->row_list[i].key_list[0].pos_y + v->row_list[i].key_list[0].height;
        if (y < key_y && y > key_y_pre)
        {
            for(j = 0; j < v->row_list[i].key_count; j++)
            {
                key_x_pre= v->x + v->row_list[i].key_list[j].pos_x;
                key_x = v->x + v->row_list[i].key_list[j].pos_x + v->row_list[i].key_list[j].width;
                if ( x < key_x && x > key_x_pre)
                {
                    (*index) = v->row_list[i].key_list + j;
                    return MMI_TRUE;
                }
            }
            break;
        }
    }

    return MMI_FALSE;
}


static gui_virtual_keyboard_pen_enum gui_virtual_keyboard_translate_key_code_to_vk_event(U32 ch)
{
    gui_virtual_keyboard_pen_enum ret = GUI_VKBD_PEN_CHAR_I;
    if (!gui_virtual_keyboard_is_symbol_vk(MMI_VIRTUAL_KEYBOARD_LANG))
    {
        if (gui_virtual_keyboard_is_alphanumeric_vk())
        {
			if (g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_INTERNET && ch == '0')
			{
				//ret = ch;
			}
			else if (ch >= '0' && ch <= '9')
            {
                {
                    ret = (gui_virtual_keyboard_pen_enum) (ch - '0' + GUI_VKBD_PEN_ALPHANUMERIC_KEY_0);
                }
            }
        }

        if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_EN_DIALER)
        {
            if (ch >= '0' && ch <= '9')  
            {
                ret = (gui_virtual_keyboard_pen_enum) (ch - '0' + GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_0);
            }
            switch(ch)
            {
            case '*':
                ret = GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_STAR;
                break;
            case '#':
                ret = GUI_VKBD_PEN_ALPHANUMERIC_DIALER_KEY_POUND;
                break;
            }
        }
    }
    return ret;
}

static gui_virtual_keyboard_pen_enum mmi_imc_gui_virtual_keyboard_translate_v3_event_to_v2_event(gui_virtual_keyboard_pen_enum event)
{
    gui_virtual_keyboard_pen_enum ret_event = GUI_VKBD_PEN_NONE;

    switch(event)
    {            
    case GUI_VKBD_PEN_V3_SHIFT:
        ret_event = GUI_VKBD_PEN_CAPSLOCK;
        break;

    case GUI_VKBD_PEN_V3_SPACE:
        ret_event = GUI_VKBD_PEN_ALPHANUMERIC_KEY_SPACE;
        break;

    case GUI_VKBD_PEN_V3_DELETE:
        ret_event = GUI_VKBD_PEN_ALPHANUMERIC_KEY_DELETE;
        break;

    default:
        ret_event = event;
        break;




    }
    return ret_event;
}

/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_get_selected_key
* DESCRIPTION
*  
* PARAMETERS
*  v       [IN/OUT]     
*  s       [IN]  
*  ch      [OUT]     
*  evt     [OUT]     
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_get_selected_key(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct* key,
    mmi_pen_event_type_enum pen_event,
    UI_character_type *key_char,
    gui_virtual_keyboard_pen_enum *key_event)
{
    v->selected_key.index= key;
    v->selected_key.x = v->x + key->pos_x;
    v->selected_key.y = v->y + key->pos_y;
    v->selected_key.width = key->width;
    v->selected_key.height = key->height;
    return gui_virtual_keyboard_get_selected_key_int(v,key,pen_event,key_char,key_event);

}

/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_get_selected_key_int
* DESCRIPTION
*  
* PARAMETERS
*  v       [IN/OUT]     
*  s       [IN]  
*  ch      [OUT]     
*  evt     [OUT]     
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_get_selected_key_int(
    gui_virtual_keyboard_struct *v,
    const gui_virtual_keyboard_key_struct* key,
    mmi_pen_event_type_enum pen_event,
    UI_character_type *key_char,
    gui_virtual_keyboard_pen_enum *key_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_char;
    gui_virtual_keyboard_pen_enum temp_event;
    U32 key_code = 0;
    const gui_virtual_keyboard_key_struct* toggle_key = NULL;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    *key_char = 0;
    *key_event = GUI_VKBD_PEN_NONE;

    if (key == NULL)
    {
        return MMI_FALSE;
    }

    ret = gui_virtual_keyboard_get_current_key_toggle_state(
        v,
        key,
        &toggle_key);

    if (ret)
    {
        if (pen_event == MMI_PEN_EVENT_LONG_TAP)
        {
            key_code = toggle_key->code_long_press ;
        }
        if(key_code == 0)
        {
            if (toggle_key->code)
            {
                key_code = toggle_key->code;
            }
            else
            {
                key_code = key->code;
            }
        }
    }
    else
    {
        if (pen_event == MMI_PEN_EVENT_LONG_TAP)
        {
            key_code = key->code_long_press ;
        }
        if (key_code == 0)
        {
            key_code = key->code;
        }
    }

    /* parse the key content from content */
    temp_char = (UI_character_type)GUI_VK_GET_KEY_CHAR(key_code);
    temp_event = (gui_virtual_keyboard_pen_enum) GUI_VK_GET_KEY_EVENT(key_code);


    /* assert this key's content is not NULL */
    if (pen_event != MMI_PEN_EVENT_LONG_TAP)
    {
        MMI_DBG_ASSERT(!((temp_char == 0) &&
            (temp_event == GUI_VKBD_PEN_NONE ||
            temp_event >= GUI_VKBD_PEN_MAX)));
    }

    *key_char = temp_char;
    *key_event = temp_event;
    if (temp_char > 0)
    {
        MMI_DBG_ASSERT(temp_event == GUI_VKBD_PEN_NONE);
        *key_event = GUI_VKBD_PEN_CHAR_I;
    }
    if (temp_event == GUI_VKBD_PEN_DEFAULT_VALUE)
    {
        *key_event = GUI_VKBD_PEN_CHAR_I;
        *key_char = *key->label_string;
    }

    if (temp_event == GUI_VKBD_PEN_SPACE)
    {
        *key_event = GUI_VKBD_PEN_CHAR_I;
        *key_char = 0X20;
    }
    if (gui_virtual_keyboard_is_alphanumeric_vk() || g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_EN_DIALER)
    {
        if (*key_event == GUI_VKBD_PEN_CHAR_I)
        {
            *key_event = gui_virtual_keyboard_translate_key_code_to_vk_event(*key_char);
        }
        else
        {
            *key_event = mmi_imc_gui_virtual_keyboard_translate_v3_event_to_v2_event(*key_event);
        }
    }

    if (gui_virtual_keyboard_is_shift_state(v))
    {
        *key_char = mmi_towupper(*key_char);
    }
    else
    {
        *key_char = mmi_towlower(*key_char);
    }
    return MMI_TRUE;
}



/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_cache_and_show_selected_key
* DESCRIPTION
*  
* PARAMETERS
*  v       [IN/OUT]     
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_cache_and_show_selected_key(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
                MMI_BOOL is_dither;

#endif  
    kal_prompt_trace(MOD_XDM,"gui_virtual_keyboard_cache_and_show_selected_key. v->key_down_accepted = %d",v->key_down_accepted);
    if (v->key_down_accepted == MMI_FALSE)
        return;

    //    gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);

#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
    if (!gui_virtual_keyboard_get_long_tap_popup_state(v))
#endif
    {
#ifdef __MMI_VK_POPUP_HINT__
        if (gui_virtual_keyboard_is_popup_can_be_shown(v,v->selected_key.index))
            gui_virtual_keyboard_show_popup_hint(v,(gui_virtual_keyboard_key_state_enum) v->popup_hint.popup_state, MMI_TRUE);
#endif        
    }
    gui_virtual_keyboard_discard_cache_and_recache_normal_key(v);
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
    is_dither = gdi_image_9slice_get_dither();
    gdi_image_9slice_set_dither(MMI_FALSE);
#endif  

    gui_virtual_keyboard_draw_key(v, v->selected_key.index);
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)  
    gdi_image_9slice_set_dither(is_dither);
#endif

    //   gdi_pop_and_restore_alpha_blending_source_layer(); 


    gdi_layer_blt_previous(v->selected_key.x,v->selected_key.y,v->selected_key.x + v->selected_key.width - 1, v->selected_key.y + v->selected_key.height - 1);
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_show_unselect_key_from_cache
* DESCRIPTION
*  
* PARAMETERS
*  v       [IN/OUT]     
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_show_unselect_key_from_cache(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key.is_key_cached == MMI_FALSE)
    {
        return;
    }

    gdi_push_and_set_alpha_blending_source_layer((gdi_handle) gdi_act_layer);

    x1 = v->selected_key.x;
    y1 = v->selected_key.y;
    x2 = x1 + v->selected_key.width - 1;
    y2 = y1 + v->selected_key.height - 1;

    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    if (v->selected_key.key_bitmap.buf_ptr != NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_VK_CACHE_LOAD, x1,y1);
        gdi_image_cache_bmp_draw(x1, y1, &v->selected_key.key_bitmap);
        mmi_frm_scrmem_free(v->selected_key.key_bitmap.buf_ptr);
        v->selected_key.key_bitmap.buf_ptr = NULL;
    }

    gdi_layer_pop_clip();
    gui_unlock_double_buffer();

#ifdef __MMI_VK_POPUP_HINT__
    if (v->popup_hint.is_key_cached == MMI_TRUE)
    {
        gui_virtual_keyboard_clear_normal_popup_from_cache(v);
        if (x1 >= v->popup_hint.x)
        {
            x1 = v->popup_hint.x;
        }
        y1 = v->popup_hint.y;
        if (x2 < v->popup_hint.x + v->popup_hint.width - 1)
        {
            x2 = v->popup_hint.x + v->popup_hint.width - 1;
        }
    }
#endif /* __MMI_VK_POPUP_HINT__ */

    v->selected_key.is_key_cached = MMI_FALSE;

    gdi_layer_blt_previous(x1,y1,x2,y2);
    gdi_pop_and_restore_alpha_blending_source_layer();

}


#ifdef __MMI_VK_POPUP_HINT__
/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_hide_cursor_dummy_function
* DESCRIPTION
*  
* PARAMETERS
*  x1          [IN]
*  y1          [IN]
*  x2          [IN]
*  y2          [IN]
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL gui_virtual_keyboard_hide_cursor_dummy_function(
    S32 x1,
    S32 y1,
    S32 x2,
    S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x1);
    UI_UNUSED_PARAMETER(y1);
    UI_UNUSED_PARAMETER(x2);
    UI_UNUSED_PARAMETER(y2);
    return MMI_TRUE;
}
#endif /* __MMI_VK_POPUP_HINT__ */
/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/
/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_flags_on
* DESCRIPTION
*  turn on flag of virtual keyboard
* PARAMETERS
*  v           [IN]    pointer of virtual keyboard
*  flag        [IN]    flag to bet set on
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_flags_on(gui_virtual_keyboard_struct *v, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->flag |= flag;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_flags_off
* DESCRIPTION
*  turn off flag of virtual keyboard
* PARAMETERS
*  v           [IN]    pointer of virtual keyboard
*  flag        [IN]    flag to bet set on
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_flags_off(gui_virtual_keyboard_struct *v, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    v->flag &= (~flag);
}


/*****************************************************************************
* FUNCTION
*  gui_create_virtual_keyboard
* DESCRIPTION
*  Create virtual keyboard object
* PARAMETERS
*  v               [IN/OUT]    Is the virtual keyboard object
*  x               [IN]        Is the left-top cornerd
*  y               [IN]        Is the left-top cornerd
*  lang_type       [IN]        Is language type to be used for the keyboard
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_create(
     void* layout,
     gui_virtual_keyboard_struct *v,
     S32 x,
     S32 y,
     S32 width,
     S32 height,
     U16 row_count,
     const gui_virtual_keyboard_row_struct* row_list,
     const gui_virtual_keyboard_keytype_struct* keytype_list,
     U16 margin_x,
     U16 margin_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    v->x = x;
    v->y = y;
    v->width = width;
    v->height = height;

    //MMI_ASSERT(row_count != 0);
    //MMI_ASSERT(row_list != NULL);
    //MMI_ASSERT(keytype_list);
    v->keytype_list = keytype_list;
    v->row_num = row_count;
    v->row_list = row_list;


    v->bg_id = NULL;
    v->margin_x = margin_x;
    v->margin_y = margin_y;


    gui_virtual_keyboard_get_button_count(v);

#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
    if (!gui_virtual_keyboard_is_mini_keyboard_state(v))
    {
        v->vk_layout_backup = layout;
    }
    else
    {
        return;
    }
#endif


    /* clear all info of disable_key, dead_key & kept_key */
    memset(&v->disable_keys, 0, sizeof(v->disable_keys));
    memset(&v->dead_keys, 0, sizeof(v->dead_keys));
    v->disable_keys.disabled_symbols[0] = GUI_VKBD_PEN_NONE;

    gui_virtual_keyboard_set_current_theme(v);    

    v->hide_callback = gui_virtual_keyboard_default_hide_function;

    gui_virtual_keyboard_set_flags_on(v, GUI_VIRTUAL_KEYBOARD_STATE_ACTIVE);

    /*
    * if we find one key not have normal background image, we will
    * not set GUI_VIRTUAL_KEYBOARD_DRAW_KEY_BY_IMAGE and use code
    * to draw every key's shape
    */
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_close
* DESCRIPTION
*  Release the resource used by virtual keyboard object
* PARAMETERS
*  v               [IN/OUT]    Is the virtual keyboard object
* RETURNS
*  void
* REMARKS
*  Used in exit function or exit category function
*****************************************************************************/
void gui_virtual_keyboard_close(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_move
* DESCRIPTION
*  Move the virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  x       [IN]        Is the left-top cornerd x position
*  y       [IN]        Is the left-top cornerd y position
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_move(gui_virtual_keyboard_struct *v, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //v->x = x;
    //v->y = y;
}


static void gui_virtual_keyboard_process_data_before_shown(void)
{
    wgui_setup_virtual_keyboard_by_layout(gui_get_virtual_keyboard_callback()->vk_layout_backup);
}


static  void gui_virtual_keyboard_process_data_after_shown(void)
{
    wgui_setup_virtual_keyboard_by_layout(gui_get_virtual_keyboard_callback()->popup_vk_layout_p);
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_show
* DESCRIPTION
*  Show the virtual keyboard
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard object
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_show(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    U16 i;
    U32 key_count;
    mmi_pen_handwriting_area_struct hw_area;
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
    MMI_BOOL is_dither;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
    is_dither = gdi_image_9slice_get_dither();
    gdi_image_9slice_set_dither(MMI_FALSE);
#endif     

    if (gui_virtual_keyboard_is_mini_keyboard_state( v))
    {
        gui_virtual_keyboard_process_data_before_shown();
    }
    x1 = v->x;
    y1 = v->y;
    x2 = v->x + v->width - 1;
    y2 = v->y + v->height - 1;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    if (v->hide_callback != NULL)
    {
        v->hide_callback(x1, y1, x2, y2);
    }
    key_count = wgui_virtual_keyboard_get_button_count();

    if (v->bg_id!= NULL && v->bg_id != 65535)
    {
        gdi_image_draw_resized((S32)v->x, (S32)v->y, (S32)v->width, (S32)v->height, (PU8)get_image(v->bg_id));
    }

    for(i = 0; i < key_count; i++)
    {
        gui_virtual_keyboard_draw_key_by_index(i);
    }
    gui_pop_clip();


#if !defined(__NO_HANDWRITING__)
    mmi_imui_get_handwriting_area(&hw_area);
    if (g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_TRAY)
    {
		U16 img_id;
#if defined(__COSMOS_MMI__)
		img_id = VADP_IMG_IME_CAND_HW_BG;
#else
		img_id = MMI_IMUI_IMG_HANDWRITING_AREA;
#endif
		gui_push_clip();
        gui_set_clip(hw_area.x1, hw_area.y1, hw_area.x2, hw_area.y2);
        gdi_image_draw_resized_blend2layers(hw_area.x1,hw_area.y1,hw_area.x2 - hw_area.x1,hw_area.y2 - hw_area.y1 + 1, (PU8)get_image(img_id));
        gui_pop_clip();
    }    
#endif

    if (gui_virtual_keyboard_is_mini_keyboard_state( v))
    {
        gui_virtual_keyboard_process_data_after_shown();
        x1 = v->x;
        y1 = v->y;
        x2 = v->x + v->width - 1;
        y2 = v->y + v->height - 1;
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);

        key_count = wgui_virtual_keyboard_get_button_count();

        if (v->bg_id!= NULL && v->bg_id != 65535)
        {
            gdi_image_draw_resized_blend2layers((S32)v->x, (S32)v->y, (S32)v->width, (S32)v->height, (PU8)get_image(v->bg_id));
        }

        for(i = 0; i < key_count; i++)
        {
            gui_virtual_keyboard_draw_key_by_index(i);
        }
        gui_pop_clip();
    }

    if (v->key_down_accepted == MMI_TRUE)
    {
        if (gui_virtual_keyboard_is_popup_can_be_shown(v,v->selected_key.index) && gui_virtual_keyboard_need_to_recache)
        {
            gui_virtual_keyboard_cache_and_show_selected_key(v);
            gui_virtual_keyboard_need_to_recache = MMI_FALSE;
        }
    }

    gdi_layer_blt_previous(x1,y2,x2,y2);

#ifdef __MMI_VK_POPUP_HINT__

#endif /* __MMI_VK_POPUP_HINT__ */
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)  
    gdi_image_9slice_set_dither(is_dither);
#endif

    //               gdi_pop_and_restore_alpha_blending_source_layer();

}        



/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_translate_pen_event
* DESCRIPTION
*  
* PARAMETERS
*  v               [IN/OUT]        Is the virtual keyboard object
*  x               [IN]            x pos of pen
*  y               [IN]            y pos of pen
*  pen_event       [IN]            pen event
*  key_event       [OUT]           key event of virtual keyboard
*  key_param       [OUT]           key parameter
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL gui_virtual_keyboard_translate_pen_event(
    gui_virtual_keyboard_struct *v,
    S16 x,
    S16 y,
    mmi_pen_event_type_enum pen_event,
    gui_virtual_keyboard_pen_enum *key_event,
    gui_pen_event_param_struct *key_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    UI_character_type temp_char = 0;
    UI_string_type temp_string = NULL;
    gui_virtual_keyboard_pen_enum temp_event = GUI_VKBD_PEN_NONE;
    const gui_virtual_keyboard_key_struct* key_index = NULL;
    gui_virtual_keyboard_event_enum event = GUI_VIRTUAL_KEYBOARD_EVENT_START;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *key_event = GUI_VKBD_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(key_param);
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_VK_PEN_EV, pen_event,x,y);

    switch (pen_event)
    {
    case MMI_PEN_EVENT_DOWN:
        v->key_down_accepted = MMI_FALSE;
        MMI_ASSERT(v->is_mini_keyboard_state == MMI_FALSE);

        if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height))
        {
            if (gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
            {
                /* get the selected key */
                gui_virtual_keyboard_get_selected_key(v, key_index,pen_event, &temp_char, &temp_event);
                if ((temp_event == GUI_VKBD_PEN_NONE) ||
                    gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index))
                {
                    /* Do nothing */
                }
                else
                {
                    v->key_down_accepted = MMI_TRUE;
                    v->popup_hint.popup_state = GUI_VK_KEY_STATE_POPUP;

                    /* Providing the touch feedback for down event */
                    if (mmi_imm_is_sound_feedback_enabled_for_ime())
                    {
                        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                    }
                    if (mmi_imm_is_vibration_enabled())
                    {
                        //play vibration
                        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN_VIBRATE);
                    }

                    gui_start_timer(GUI_VK_LONG_TAP_TIMER, gui_vk_longtap_timer_handler);



                    if (temp_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
                    {
                        MMI_BOOL toggle_state_exit;
                        const gui_virtual_keyboard_key_struct* toggle_key;
                        toggle_state_exit = gui_virtual_keyboard_get_current_key_toggle_state(
                            v,
                            v->selected_key.index,
                            &toggle_key);
                        if(toggle_state_exit)
                        {
                            temp_string = toggle_key->label_string;
                        }
                        else
                        {
                            temp_string = v->selected_key.index->label_string;
                        }
                    }

                    *key_event = temp_event;

                    gui_virtual_keyboard_cache_and_show_selected_key(v);


                    if (*key_event == GUI_VKBD_PEN_CHAR_I)
                    {
                        MMI_DBG_ASSERT(temp_char != 0);
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                        if (temp_char == 13)
                        {
                            *key_event = GUI_VKBD_PEN_V3_ENTER;
                        }
                        if (temp_char == 8)
                        {
                            *key_event = GUI_VKBD_PEN_V3_DELETE;
                        }
                    }
                    else if (*key_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
                    {
                        MMI_DBG_ASSERT(temp_string != NULL);
                        GUI_PEN_EVENT_PARAM_SET_POINTER(key_param, (void*)temp_string);
                    }
                    /* 
                    * If Pen Down and Pen Up comes together, we should temporarily suspend MMI task. 
                    * Otherwise, user can not see pen down due to delayed LCM update.
                    */
                    {
                        //kal_sleep_task(kal_milli_secs_to_ticks(30));
                    }
                }
            }
            else
            {
                *key_event = GUI_VKBD_PEN_NONE;
            }
        }
        else
        {
            ret = MMI_FALSE;
        }

        break;

    case MMI_PEN_EVENT_MOVE:
        if (gui_virtual_keyboard_is_key_down_accept(v))
        {
            // the code between __MMI_VK_LONGTAP_POPUP_HINT__ need to revise
#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                gui_cancel_timer(gui_vk_longtap_timer_handler);

                gui_virtual_keyboard_longtap_popup_translate_pen_event(v, x, y, pen_event,key_event,key_param); 
            }
            else
#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */
            {
                /* if pen is in selected key's area, do nothing */
                if (v->selected_key.is_key_cached == MMI_TRUE &&
                    PEN_CHECK_BOUND(
                    x,
                    y,
                    v->selected_key.x,
                    v->selected_key.y,
                    v->selected_key.width,
                    v->selected_key.height))
                {
                    /* if is in enlarged icon, do nothing */
                    break;
                }
                else
                {
                    //moved to other key
                    v->popup_hint.popup_state = GUI_VK_KEY_STATE_POPUP;
                    gui_cancel_timer(gui_vk_longtap_timer_handler);
                    if (gui_virtual_keyboard_is_alphanumeric_vk() || g_wgui_virtual_keyboard_lang_type == GUI_VIRTUAL_KEYBOARD_EN_DIALER)
                    {
                    }
                    else
                    {
                        if (PEN_CHECK_BOUND(x, y, v->x, v->y, v->width, v->height) &&
                            gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
                        {
                            if (key_index != v->selected_key.index)
                            {
                                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                                gui_virtual_keyboard_get_selected_key(v, key_index,pen_event, &temp_char, &temp_event);
                                if (!((temp_event == GUI_VKBD_PEN_NONE) ||
                                    gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index)))
                                {
                                    gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
#if defined(__MMI_VK_POPUP_HINT__)
                                    v->is_cursor_stop = MMI_FALSE;
#endif /* defined(__MMI_VK_POPUP_HINT__) */
                                    gui_virtual_keyboard_cache_and_show_selected_key(v); 
                                } 
                            }
                        }
                        else
                        {
                            gui_virtual_keyboard_show_unselect_key_from_cache(v);
                            gui_virtual_keyboard_clear_selected_key(v);
                        }
                    }
                }
            }
        }
        break;

    case MMI_PEN_EVENT_UP:
        v->popup_hint.popup_state = GUI_VK_KEY_STATE_NONE;
        // the code between __MMI_VK_LONGTAP_POPUP_HINT__ need to revise
#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
        gui_cancel_timer(gui_vk_longtap_timer_handler);
        if (gui_virtual_keyboard_get_long_tap_popup_state(v))
        {
            gui_virtual_keyboard_longtap_popup_translate_pen_event(v, x, y, pen_event,key_event,key_param);
        }
        else
#endif /*  __MMI_VK_LONGTAP_POPUP_HINT__*/
        {
            if (gui_virtual_keyboard_is_key_down_accept(v))
            {
                if (gui_virtual_keyboard_is_alphanumeric_vk())//special for MMI_VK_TYPE_ALPHANUMERIC
                {
                    key_index = v->selected_key.index; 
                }

                MMI_DBG_ASSERT(key_index == v->selected_key.index);
                if (v->selected_key.index == NULL || gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index))
                {
                    /*Do nothing*/
                    gui_virtual_keyboard_show_unselect_key_from_cache(v);
                }
                else
                {
                    gui_virtual_keyboard_show_unselect_key_from_cache(v);
                    gui_virtual_keyboard_get_selected_key(v, v->selected_key.index, pen_event, &temp_char, &temp_event);
                    if (temp_event == GUI_VKBD_PEN_SPACE)
                    {
                        temp_event = GUI_VKBD_PEN_CHAR_I;
                        temp_char = (UI_character_type) ' ';
                    }
                    else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                    {
                        temp_event = GUI_VKBD_PEN_NONE;
                    }

                    *key_event = temp_event;

                    if (*key_event == GUI_VKBD_PEN_CHAR_I)
                    {
                        MMI_DBG_ASSERT(temp_char != 0);
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                        if (temp_char == 13)
                        {
                            *key_event = GUI_VKBD_PEN_V3_ENTER;
                        }
                        if (temp_char == 8)
                        {
                            *key_event = GUI_VKBD_PEN_V3_DELETE;
                        }
                    }
                    else if (*key_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
                    {
                        MMI_BOOL toggle_state_exit;
                        const gui_virtual_keyboard_key_struct* toggle_key;
                        toggle_state_exit = gui_virtual_keyboard_get_current_key_toggle_state(
                            v,
                            v->selected_key.index,
                            &toggle_key);
                        if(toggle_state_exit)
                        {
                            temp_string = toggle_key->label_string;
                        }
                        else
                        {
                            temp_string = v->selected_key.index->label_string;
                        }
                        MMI_DBG_ASSERT(temp_string != NULL);
                        GUI_PEN_EVENT_PARAM_SET_POINTER(key_param, (void*)temp_string);
                    }
                }
                gui_virtual_keyboard_clear_selected_key(v);
            }
        }

#if defined(__MMI_VK_POPUP_HINT__)
        v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_START;


        if (v->blink_cursor_callback != NULL)
        {
            if ((gui_virtual_keyboard_is_cursor_stopped_by_vk) &&
                (v->is_cursor_stop == MMI_TRUE))
            {
                v->blink_cursor_callback();
                gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
                v->is_cursor_stop = MMI_FALSE;
            }
        }

#endif /* defined(__MMI_VK_POPUP_HINT__) */
        v->key_down_accepted = MMI_FALSE;
        gui_virtual_keyboard_clear_selected_key(v);
        kal_prompt_trace(MOD_XDM,"pen up event was finished");
        break;

    case MMI_PEN_EVENT_ABORT:
        if (gui_virtual_keyboard_is_key_down_accept(v))
        {
            if (v->selected_key.index == NULL || gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index))
            {
                /*Do nothing*/
            }
            else
            {
                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                gui_virtual_keyboard_get_selected_key(v, v->selected_key.index, pen_event, &temp_char, &temp_event);
                if (temp_event == GUI_VKBD_PEN_SPACE)
                {
                    temp_event = GUI_VKBD_PEN_CHAR_I;
                    temp_char = (UI_character_type) ' ';
                }
                else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                {
                    temp_event = GUI_VKBD_PEN_NONE;
                }

                *key_event = temp_event;

                if (*key_event == GUI_VKBD_PEN_CHAR_I)
                {
                    MMI_DBG_ASSERT(temp_char != 0);
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                    if (temp_char == 13)
                    {
                        *key_event = GUI_VKBD_PEN_V3_ENTER;
                    }
                    if (temp_char == 8)
                    {
                        *key_event = GUI_VKBD_PEN_V3_DELETE;
                    }
                }
                else if (*key_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
                {
                    temp_string = v->selected_key.index->label_string;
                    MMI_DBG_ASSERT(temp_string != NULL);
                    GUI_PEN_EVENT_PARAM_SET_POINTER(key_param, (void*)temp_string);
                }
            }
        }
        gui_virtual_keyboard_clear_selected_key(v);
        break;

    case MMI_PEN_EVENT_LONG_TAP:

#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
        if (gui_virtual_keyboard_get_long_tap_popup_state(v))
        {
            //do nothing
        }
        else
#endif
        {
            gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index);

            /* parse the key content from content */

            if (gui_virtual_keyboard_is_key_down_accept(v))
            {
                v->popup_hint.popup_state = GUI_VK_KEY_STATE_LONGTAP_POPUP;
                gui_cancel_timer(gui_vk_longtap_timer_handler);
                /* Providing the touch feedback for long tap event */
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);

#if defined(__MMI_VK_POPUP_HINT__)
                if (v->popup_hint.popup_state != GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                {
#ifdef __MMI_VK_LONGTAP_POPUP_HINT__

                    gui_virtual_keyboard_get_popup_vk_layout(v->selected_key.index,&v->popup_vk_layout_p);

                    if (v->popup_vk_layout_p != NULL)
                    {
                        /* set longtap pop-up deactive */
                        gui_virtual_keyboard_set_long_tap_popup_deactive(v);

                        gui_virtual_keyboard_create_and_enter_mini_keyboard(v);
                        gui_virtual_keyboard_longtap_popup_translate_pen_event(
                            v,
                            x,
                            y,
                            pen_event,
                            key_event,
                            key_param);
                    }
#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */
                }
#endif /* defined(__MMI_VK_POPUP_HINT__) */
                if (gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
                {
                    key_index = v->selected_key.index; 
                    gui_virtual_keyboard_get_selected_key(v, key_index, pen_event, &temp_char, &temp_event); 
                    /*
                    if (v->selected_key.index->label_balloon_string != NULL
                    || v->selected_key.index->label_balloon_longpress_icon != 0)
                    {
                    gui_virtual_keyboard_show_unselect_key_from_cache(v);
                    gui_virtual_keyboard_cache_and_show_longtap_popup(v);
                    }
                    */
                    if(temp_event == GUI_VKBD_PEN_V3_CHANGE_MODE_BETWEEN_SMART_AND_MULTITAP)
                    {
#if defined(__MMI_VK_POPUP_HINT__)
                        gui_virtual_keyboard_clear_normal_popup_from_cache(v);
#endif 					
                    }

                    if (temp_event == GUI_VKBD_PEN_SPACE)
                    {
                        temp_event = GUI_VKBD_PEN_CHAR_I;
                        temp_char = (UI_character_type) ' ';
                    }
                    else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                    {
                        temp_event = GUI_VKBD_PEN_NONE;
                    }
                    else if (*key_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
                    {
                        MMI_DBG_ASSERT(temp_string != NULL);
                        GUI_PEN_EVENT_PARAM_SET_POINTER(key_param, (void*)temp_string);
                    }

                    *key_event = temp_event;

                    if (*key_event == GUI_VKBD_PEN_CHAR_I)
                    {
                        MMI_DBG_ASSERT(temp_char != 0);
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                        if (temp_char == 13)
                        {
                            *key_event = GUI_VKBD_PEN_V3_ENTER;
                        }
                        if (temp_char == 8)
                        {
                            *key_event = GUI_VKBD_PEN_V3_DELETE;
                        }
                    }

                }
            }
        }
        break;
    case MMI_PEN_EVENT_REPEAT:
        if (gui_virtual_keyboard_is_key_down_accept(v))
        {
#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                gui_cancel_timer(gui_vk_longtap_timer_handler);

                gui_virtual_keyboard_longtap_popup_translate_pen_event(
                    v,
                    x,
                    y,
                    pen_event,
                    key_event,
                    key_param);

            }
            else
#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */
            {
                if (gui_virtual_keyboard_translate_pen_position(v, x, y, &key_index))
                {
                    gui_virtual_keyboard_selected_key_struct backup_selected_key = v->selected_key;

                    key_index = v->selected_key.index; 

                    gui_virtual_keyboard_get_selected_key(v, key_index, pen_event, &temp_char, &temp_event);
                    if ((temp_event == GUI_VKBD_PEN_NONE) ||
                        gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index))
                    {
                        break;
                    }
                    if (temp_event == GUI_VKBD_PEN_SPACE)
                    {
                        temp_event = GUI_VKBD_PEN_CHAR_I;
                        temp_char = (UI_character_type) ' ';
                    }
                    else if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
                    {
                        temp_event = GUI_VKBD_PEN_NONE;
                    }

                    *key_event = temp_event;

                    if (*key_event == GUI_VKBD_PEN_CHAR_I)
                    {
                        MMI_DBG_ASSERT(temp_char != 0);
                        GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                    }

#if defined(__MMI_VK_POPUP_HINT__)
                    if (event == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                    {
                        v->popup_hint.popup_state = GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE;
                    }

                    if (v->popup_hint.popup_state == GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE)
                    {
                        gui_lock_double_buffer();
                        gui_virtual_keyboard_show_unselect_key_from_cache(v);
                        gui_virtual_keyboard_cache_and_show_selected_key(v);
                        gui_unlock_double_buffer();
                    }
#endif /* defined(__MMI_VK_POPUP_HINT__) */
                    v->selected_key = backup_selected_key;
                }
            }
        }
        break;
    }

    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_VK_PEN_RET_VALUE, pen_event,*key_event,key_param->_u.i);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_get_current_character
* DESCRIPTION
*  This API is only provided for category to get character before IME.
*  It will only return that character of pen's position
* PARAMETERS
*  v               [IN/OUT]         
*  x               [IN]        
*  y               [IN]        
*  ch              [IN]        
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL gui_virtual_keyboard_get_current_character(
    gui_virtual_keyboard_struct *v,
    S16 x,
    S16 y,
    UI_character_type *ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_theme
* DESCRIPTION
*  Applies the current theme for virtual keyboard.
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer
*  t       [IN]            theme pointer of virtual keyboard
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_theme(
    gui_virtual_keyboard_struct *v,
    UI_virtual_keyboard_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(t != NULL);
    v->theme = t;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_current_theme
* DESCRIPTION
*  Applies the current theme for virtual keyboard.
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_current_theme(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    MMI_DBG_ASSERT(current_virtual_keyboard_theme != NULL);
    v->theme = current_virtual_keyboard_theme;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_bg
* DESCRIPTION
*  set the background of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer
*  bg_id   [IN]            background image id of the virtual keyboard
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_bg(gui_virtual_keyboard_struct *v, U16 bg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    MMI_ASSERT(v != NULL);
    v->bg_id = bg_id;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_dead_keys
* DESCRIPTION
*  set dead characters of one specific language's virtual keyboard
* PARAMETERS
*  v               [IN/OUT]        Is the virtual keyboard pointer
*  dead_chars      [IN]            dead characters of one language
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_dead_keys(
    gui_virtual_keyboard_struct *v,
    const UI_character_type *dead_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j,k;
    const gui_virtual_keyboard_key_struct* key;
    UI_character_type key_char;
    v->dead_keys.count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    for (i = 0; dead_chars[i] != NULL; i++)
    {
        MMI_DBG_ASSERT(i < GUI_VIRTUAL_KEYBOARD_MAX_DEAD_KEYS);
        for (j = 0; j < v->row_num; j++)
        {
            /* find the dead key in key_list and record it's index */
            for(k = 0; k < v->row_list[j].key_count; k++)
            {
                key = v->row_list[j].key_list + k;
                key_char = (UI_character_type)GUI_VK_GET_KEY_CHAR(key->code);
                if (key_char == dead_chars[i])
                {
                    v->dead_keys.index[v->dead_keys.count] = key;
                    v->dead_keys.count++;
                    break;
                }
            }
        }
    }   
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_allowed_characters
* DESCRIPTION
*  Only the allowd characters can be input on keyboard.
*  This function and gui_virtual_board_set_disable_list() are mutually-exclusive.
*  
*  Control keys such as GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_SHOW... are enabled because
*  they are not related to character insertion.
*  
*  `allowed_characters' may contain '-' for consecutive characters
*  (Ex. 'a-z' for characters from a to z.)
*  If we want to accept "-", please write it as '\-'.
*  For example, '\-0-9.' represents "-0123456789."
*  
*  Example of valid characters in email addresss:
*  wgui_virtual_keyboard_set_allowed_characters((const UI_character_type *) L"+_\\-.@A-Za-z0-9");
*  (it is not a complete list of all characters allowed in RFC, but it satisfies almost all cases)
* PARAMETERS
*  v                   [IN/OUT]    Virtual keyboard
*  allowed_chars       [IN]        Allowed characters
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_allowed_characters(
    gui_virtual_keyboard_struct *v,
    const UI_character_type *allowed_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->disable_keys.allowed_chars = allowed_chars;

}


MMI_BOOL gui_virtual_keyboard_add_toggle_state_key(
    toggle_state_key_index_enum toggle_key_index,
    toggle_state_id_mapping_enum state_id)
{
    gui_virtual_keyboard_struct* v = gui_get_virtual_keyboard_callback();
    MMI_ASSERT(toggle_key_index < GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_END);

    v->toggle_state_ids[toggle_key_index] = state_id;
    return MMI_TRUE;
}


MMI_BOOL gui_virtual_keyboard_remove_toggle_state_key(
    toggle_state_key_index_enum toggle_key_index)

{
    gui_get_virtual_keyboard_callback()->toggle_state_ids[toggle_key_index] = 0;
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_disable_list
* DESCRIPTION
*  Disable some keys on keyboard.
*  This function and gui_virtual_keyboard_set_allowed_characters()
*  are mutually-exclusive.
* PARAMETERS
*  v                   [IN/OUT]    Virtual keyboard
*  disabled_chars      [IN]        Null-terminated array of disabled unicode chars
*  disabled_symbols    [IN]        Ended by GUI_VKBD_PEN_NONE
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_disable_list(
    gui_virtual_keyboard_struct *v,
    const UI_character_type *disabled_chars,
    const gui_virtual_keyboard_pen_enum *disabled_symbols)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);

    /* Setup v->disable_keys.disabled_chars[] */
    for (i = 0; i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
    {
        if (!disabled_chars[i])
        {
            break;
        }

        v->disable_keys.disabled_chars[i] = disabled_chars[i];
    }

    MMI_DBG_ASSERT(i <= GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS ||
        !disabled_chars[i]);
    v->disable_keys.disabled_chars[i] = 0;

    /* Setup v->disable_keys.disabled_symbols[] */
    for (i = 0; i < GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS; i++)
    {
        if (disabled_symbols[i] == GUI_VKBD_PEN_NONE)
        {
            break;
        }

        v->disable_keys.disabled_symbols[i] = disabled_symbols[i];
    }

    MMI_DBG_ASSERT(i <= GUI_VIRTUAL_KEYBOARD_MAX_DISABLED_KEYS ||
        (disabled_symbols[i] == GUI_VKBD_PEN_NONE));
    v->disable_keys.disabled_symbols[i] = GUI_VKBD_PEN_NONE;

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_display_area
* DESCRIPTION
*  Update text displayed on display area
* PARAMETERS
*  v           [IN/OUT]        
*  string      [IN]        String to be displayed in display area
*  redraw      [IN]        Whether to redraw the keyboard
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_display_area(
    gui_virtual_keyboard_struct *v,
    const U8 *string,
    MMI_BOOL redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_register_hide_callback
* DESCRIPTION
*  Register hide callback of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  f       [IN]        Is the hide callback
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_register_hide_callback(
    gui_virtual_keyboard_struct *v,
    void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(v != NULL);
    v->hide_callback = f;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_register_display_callback
* DESCRIPTION
*  Register display callback of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  f       [IN]        Is the display callback
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_register_display_callback(
    gui_virtual_keyboard_struct *v,
    gui_virtual_keyboard_display_callback_func_ptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_register_event_callback
* DESCRIPTION
*  Register event callback of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  f       [IN]        Is the event callback
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_register_event_callback(
    gui_virtual_keyboard_struct *v,
    gui_virtual_keyboard_event_callback_func_ptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_get_key_info
* DESCRIPTION
*  Get key position info
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_get_key_info(gui_virtual_keyboard_struct *v, gui_virtual_keyboard_key_pos_info_struct_p info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_draw_from_cache
* DESCRIPTION
* PARAMETERS
*  v               [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_draw_from_cache(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->selected_key.is_key_cached == MMI_FALSE)
    {
        return;
    }


    if (v->key_down_accepted == MMI_TRUE)
    {
#ifdef __MMI_VK_POPUP_HINT__
        if (v->popup_hint.is_key_cached == MMI_TRUE)
        {             
            if (gui_virtual_keyboard_get_long_tap_popup_state(v))
            {
                /* do nothing */
            }
            else
            {
                /* discard the previous pop-up cache */
                gui_virtual_keyboard_clear_normal_popup_from_cache(v);

                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                gui_virtual_keyboard_need_to_recache = MMI_TRUE;
            }
        }
#else
        gui_virtual_keyboard_show_unselect_key_from_cache(v);
#endif

    }

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_initilize
* DESCRIPTION
*  The function initializes the longtap popup hint item 
*  
* PARAMETERS
*  v               [IN/OUT]        Is the virtual keyboard pointer
* RETURNS
*  
*****************************************************************************/
void gui_virtual_keyboard_initilize(
                                    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(v != NULL);
#if defined(__MMI_VUI_ENGINE__)
    if (!(vadp_p2v_uc_is_in_venus() || vadp_p2v_is_venus_ime_connected()))
#endif
    {
        memset(v,0,sizeof(v[0]));
    }

    v->is_mini_keyboard_state = MMI_FALSE;
    v->popup_hint.key_bitmap.buf_ptr = NULL;
    /*
    * clear all toggle state   
    */
    memset(&v->toggle_state_ids, 0, sizeof(v->toggle_state_ids));

}


MMI_BOOL gui_virtual_keyboard_is_shift_state( 
    gui_virtual_keyboard_struct* v)
{
    MMI_ASSERT(v != NULL);
    if (v->toggle_state_ids[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SHIFT] == GUI_VIRTUAL_KEYBOARD_SHIFT_KEY_UP_ONCE
        || v->toggle_state_ids[GUI_VIRTUAL_KEYBOARD_TOGGLE_KEY_SHIFT] == GUI_VIRTUAL_KEYBOARD_SHIFT_KEY_UP_STABLE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void gui_virtual_keyboard_set_shift_state(
    gui_virtual_keyboard_struct* v,
    U32 flag)
{
    U32 mask = VK_SHIFT_STATE_UP_ONCE | VK_SHIFT_STATE_UP_STABLE | VK_SHIFT_STATE_LOWER;
    if (!gui_virtual_keyboard_is_shift_support(v))
    {
        return;
    }
    v->flag = (v->flag & (~mask));
    v->flag = v->flag | flag;
}
static void gui_virtual_keyboard_convert_up_low_form_shift_state(
    gui_virtual_keyboard_struct *v,
    const UI_string_type src,
    UI_string_type det)
{
    UI_character_type ch;
    UI_character_type* src_p, *det_p;

    src_p = (UI_character_type*) src;
    det_p = (UI_character_type*) det;
    ch = *src;
    if (gui_virtual_keyboard_is_shift_state(v))
    {
        if (ch >= 'a' && ch <= 'z')
        {
            while(*src_p != '\0')
            {
                *det_p = *src_p + ('A' - 'a');

                det_p++;
                src_p++;
            }
        }
    }

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_get_button_code
* DESCRIPTION
*  Register hide cursor callback of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  f       [IN]        Is the hide cursor callback
* RETURNS
*  void
*****************************************************************************/
S32 gui_virtual_keyboard_get_button_code(  
    U32 index,mmi_pen_event_type_enum pen_event)
{
    const gui_virtual_keyboard_key_struct* key;
    gui_virtual_keyboard_key_struct_p toggle_key = NULL;
    MMI_BOOL ret = MMI_FALSE;
    UI_character_type key_char;
    gui_virtual_keyboard_pen_enum key_event;
    gui_virtual_keyboard_struct* v = gui_get_virtual_keyboard_callback();

    /*****************************************
    * code body
    *******************************************/
    gui_virtual_keyboard_translate_index_to_pointer(index,&key);
    gui_virtual_keyboard_get_selected_key_int(v,key,pen_event, &key_char, &key_event);

    if (key_event == GUI_VKBD_PEN_CHAR_I)
    {
        return key_char;
    }
    else
    {
        return key_event;
    }
}


U32 gui_virtual_keyboard_get_button_type(U32 index ,mmi_pen_event_type_enum pen_event)
{
    U32 key_code;
    U32 temp_char;
    U32 temp_event;

    key_code = gui_virtual_keyboard_get_button_code(index, pen_event);
    temp_char = (UI_character_type)GUI_VK_GET_KEY_CHAR(key_code);
    temp_event = GUI_VK_GET_KEY_EVENT(key_code);
    if (temp_event == 0)
        temp_event = GUI_VKBD_PEN_CHAR_I;
    return temp_event;
}


#ifdef __MMI_VK_POPUP_HINT__
/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_register_hide_cursor_callback
* DESCRIPTION
*  Register hide cursor callback of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  f       [IN]        Is the hide cursor callback
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_register_hide_cursor_callback(
    gui_virtual_keyboard_struct *v,
    MMI_BOOL (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    MMI_DBG_ASSERT(v != NULL);
    v->hide_cursor_callback = f;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_register_blink_cursor_callback
* DESCRIPTION
*  Register blink cursor callback of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  f       [IN]        Is the hide cursor callback
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_register_blink_cursor_callback(
    gui_virtual_keyboard_struct *v,
    void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    v->blink_cursor_callback = f;
}


static void gui_virtual_keyboard_stop_cursor_blink(S32 x1, S32 y1, S32 x2, S32 y2)
{
    gui_virtual_keyboard_struct* v = gui_get_virtual_keyboard_callback();
    if (v->hide_cursor_callback != NULL)
    {
        if (!gui_virtual_keyboard_is_cursor_stopped_by_vk)
        {
            v->hide_cursor_callback(x1,y1,x2,y2);
            gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_TRUE;
        }
    }
}


static void gui_virtual_keyboard_start_cursor_blink(void)
{
    gui_virtual_keyboard_struct* v = gui_get_virtual_keyboard_callback();
    if (v->blink_cursor_callback != NULL)
    {
        if (gui_virtual_keyboard_is_cursor_stopped_by_vk)
        {
            v->blink_cursor_callback();
            gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
        }
    }

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_recover_covered_area
* DESCRIPTION
*  recover area that popup hint covered. It may happen that the other 
*  components may be redrawn, so we should not take the pop-up from cache
*  Instead we should redraw the region and retake the cahche.
* PARAMETERS
*  v               [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_recover_covered_area(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */

    if (gui_virtual_keyboard_is_key_down_accept(v))
    {
        gui_virtual_keyboard_show_unselect_key_from_cache(v);
        gui_virtual_keyboard_cache_and_show_selected_key(v);
    }
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_discard_cache_and_recache
* DESCRIPTION
*  recover area that popup hint covered. It may happen that the other 
*  components may be redrawn, so we should not take the pop-up from cache
*  Instead we should redraw the region and retake the cahche.
* PARAMETERS
*  v               [IN/OUT]
* RETURNS
*  void
*****************************************************************************/ 
void gui_virtual_keyboard_discard_cache_and_recache_hint(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_virtual_keyboard_key_struct* key;
    gui_virtual_keyboard_rect_struct rect;
    U16 x1,y1,x2,y2;
    U32 cache_buf_size;

    /*----------------------------------------------------------------*/
    /* code body                                                   */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_XDM,"gui_virtual_keyboard_discard_cache_and_recache_hint.");

    if (!gui_virtual_keyboard_is_key_down_accept(v))
        return;

    key = v->selected_key.index;
    gui_virtual_keyboard_get_key_hint_rect(v,key,&rect);
    x1 = rect.x;
    x2 = rect.x + rect.width -1;
    y1 = rect.y;
    y2 = rect.y + rect.height -1;
    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);


    /* cache the current key content to selected key's key_bitmap */
    cache_buf_size = ( ((U32)rect.width) * rect.height * (gdi_act_layer->bits_per_pixel >> 3));
    if ( v->popup_hint.key_bitmap.buf_ptr !=NULL)
    {
        mmi_frm_scrmem_free( v->popup_hint.key_bitmap.buf_ptr); 
        v->popup_hint.key_bitmap.buf_ptr = NULL;
    }
    v->popup_hint.key_bitmap.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_buf_size);
    MMI_DBG_ASSERT(v->popup_hint.key_bitmap.buf_ptr != NULL);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->popup_hint.key_bitmap);
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
    
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_VK_CACHE_STORE_POPUP,rect.x,rect.y);

    v->popup_hint.is_key_cached = MMI_TRUE;
    v->popup_hint.x = rect.x;
    v->popup_hint.y = rect.y;
    v->popup_hint.height = rect.height;
    v->popup_hint.width = rect.width;

}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_recache
* DESCRIPTION
* PARAMETERS
*  v               [IN/OUT]
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_recache(gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (v->key_down_accepted == MMI_TRUE)
    {
        {
            if ((gui_virtual_keyboard_get_long_tap_popup_state(v)) )
            {
                /* do nothing */
            }
            else
            {
                const gui_virtual_keyboard_key_struct* key;
                /* get selected key content */
                key = v->selected_key.index;

                /* there is popup content  */
                if (gui_virtual_keyboard_need_to_recache)
                {
                    /* redo the cache and printing of popup and key */

                    //gui_virtual_keyboard_discard_cache_and_recache_hint(v);
                    //gui_virtual_keyboard_discard_cache_and_recache_normal_key(v);
                    gui_virtual_keyboard_cache_and_show_selected_key(v);
                    gui_virtual_keyboard_need_to_recache = MMI_FALSE;
                }

            }

        }

    }
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_clear_normal_popup_from_cache
* DESCRIPTION
*  The function clears the normal pop-up from cache on encountering the 
*  longtap pen event
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer     
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_clear_normal_popup_from_cache(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_XDM,"gui_virtual_keyboard_clear_normal_popup_from_cache. v->popup_hint.is_key_cached = %d",v->popup_hint.is_key_cached);

    /* Logic for showing the unselected pop-up from cache */
    if (v->selected_key.is_key_cached == MMI_FALSE)
    {
        return;
    }

    gui_lock_double_buffer();

    if (v->popup_hint.is_key_cached == MMI_TRUE)
    {
        gdi_layer_push_clip();
        x1 = v->popup_hint.x;
        y1 = v->popup_hint.y;
        x2 = x1 + v->popup_hint.width - 1;
        y2 = y1 + v->popup_hint.height - 1;
        gdi_layer_set_clip(x1, y1, x2, y2);
        MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_VK_CACHE_LOAD_POPUP, x1,y1);
        gdi_image_cache_bmp_draw(x1, y1, &v->popup_hint.key_bitmap);
        mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr);
        v->popup_hint.key_bitmap.buf_ptr = NULL;
        gdi_layer_pop_clip();
    }

    gui_unlock_double_buffer();

    gdi_layer_blt_previous(x1, y1, x2, y2);
    gui_virtual_keyboard_start_cursor_blink();
    v->popup_hint.is_key_cached = MMI_FALSE;
    if (v->blink_cursor_callback != NULL)
    {
        if ((gui_virtual_keyboard_is_cursor_stopped_by_vk)  &&
            (v->is_cursor_stop == MMI_TRUE))
        {
            v->blink_cursor_callback();
            gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
            v->is_cursor_stop = MMI_FALSE;
        }
    }
}


#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
static MMI_BOOL gui_virtual_keyboard_create_and_enter_mini_keyboard(
    gui_virtual_keyboard_struct *v)
{
    gui_virtual_keyboard_pen_enum key_event;
    gui_pen_event_param_struct key_param;
    S16 x,y;
    MMI_BOOL ret = MMI_FALSE;
    BOOL lcd_freeze;

    kal_prompt_trace(MOD_XDM,"gui_virtual_keyboard_create_and_enter_mini_keyboard.");

    x = v->selected_key.index->pos_x + v->x + (v->selected_key.index->width >> 2);
    y = v->selected_key.index->pos_y + v->y + (v->selected_key.index->height >> 2);

    gui_virtual_keyboard_get_popup_vk_layout(v->selected_key.index,&v->popup_vk_layout_p);

    if (v->popup_vk_layout_p == NULL)
    {
        return ret; //this key has no pop up VK.
    }
    v->popup_key = v->selected_key.index;
    gui_virtual_keyboard_set_mini_keyboard_state(v,MMI_TRUE);
    gui_virtual_keyboard_set_long_tap_popup_active(v);

    wgui_virtual_keyboard_create_keyboard_from_layout(
        v,
        (struct wgui_virtual_keyboard_layout_struct *)v->popup_vk_layout_p);

	lcd_freeze = gdi_lcd_get_freeze();
	gdi_lcd_freeze(MMI_TRUE); 

	gui_virtual_keyboard_show_unselect_key_from_cache(v);
	gui_virtual_keyboard_clear_selected_key(v);
    gui_virtual_keyboard_discard_cache_and_recache_mini_keyboard(v);
    gui_virtual_keyboard_stop_cursor_blink(v->x,v->y,v->x + v->width -1,v->y + v->height -1);

    gui_virtual_keyboard_show(v);

    gui_BLT_double_buffer(
        v->x,
        v->y,
        v->x + v->width - 1,
        v->y + v->height - 1);
    v->key_down_accepted = MMI_TRUE;

    gui_virtual_keyboard_longtap_popup_translate_pen_event(v, x, y, MMI_PEN_EVENT_MOVE, &key_event, &key_param);

    gdi_lcd_freeze(lcd_freeze);
    gdi_lcd_repaint_all();
    ret = MMI_TRUE;
    return ret;
}


void gui_virtual_keyboard_recover_mini_keyboard_from_cache(
    gui_virtual_keyboard_struct* v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 x1,x2,y1,y2;

    x1 = v->x;
    y1 = v->y;
    x2 = v->x + v->width - 1;
    y2 = v->y + v->height - 1;

    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    if (v->mini_keyboard_bitmap.buf_ptr != NULL)
    {
        gdi_image_cache_bmp_draw(x1, y1, &v->mini_keyboard_bitmap);
        mmi_frm_scrmem_free(v->mini_keyboard_bitmap.buf_ptr);
        v->mini_keyboard_bitmap.buf_ptr = NULL;
    }

    gdi_layer_pop_clip();
    gui_unlock_double_buffer();

    gdi_layer_blt_previous(x1,y2,x2,y2);
    gui_virtual_keyboard_start_cursor_blink();
}


static void gui_virtual_keyboard_resume_from_longtap_state(
    gui_virtual_keyboard_struct * v)
{
    MMI_ASSERT(v->vk_layout_backup != NULL);

    gui_virtual_keyboard_recover_mini_keyboard_from_cache(v);

    wgui_virtual_keyboard_create_keyboard_from_layout(
        v,
        (struct wgui_virtual_keyboard_layout_struct *)v->vk_layout_backup);
    v->popup_vk_layout_p = NULL;
    v->popup_key = NULL;
    gui_virtual_keyboard_set_long_tap_popup_deactive(v);
    gui_virtual_keyboard_clear_selected_key(v);
}


static void gui_virtual_keyboard_discard_cache_and_recache_mini_keyboard(
    gui_virtual_keyboard_struct * v)
{
    U32  cache_buf_size;
    U16 x1, y1, x2, y2;

    if (gui_virtual_keyboard_is_mini_keyboard_state(v) == MMI_FALSE)
    {
        //this function need be called before mini keyboard was createc.
        return;
    }

    x1 = v->x;
    x2 = v->x + v->width -1;
    y1 = v->y;
    y2 = v->y + v->height - 1;

    cache_buf_size = ((U32)v->width * v->height * (gdi_act_layer->bits_per_pixel)) >> 3 ;
    gui_lock_double_buffer();
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    if (v->mini_keyboard_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->mini_keyboard_bitmap.buf_ptr);
        v->mini_keyboard_bitmap.buf_ptr = NULL;
    }
    v->mini_keyboard_bitmap.buf_ptr = mmi_frm_scrmem_alloc(cache_buf_size);

    MMI_DBG_ASSERT(v->mini_keyboard_bitmap.buf_ptr != NULL);

    gdi_image_cache_bmp_get(x1, y1, x2, y2, &v->mini_keyboard_bitmap);
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();

    gdi_layer_blt_previous( x1, y1, x2, y2);

}



/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_cache_and_show_longtap_popup
* DESCRIPTION
*  The function caches and shows the longtap pop-up
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer     
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_cache_and_show_longtap_popup(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_XDM,"gui_virtual_keyboard_cache_and_show_selected_key. v->key_down_accepted = %d",v->key_down_accepted);
    if (v->key_down_accepted == MMI_FALSE)
        return;
    //        gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);

#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
    if (!gui_virtual_keyboard_get_long_tap_popup_state(v))
#endif
    {
#ifdef __MMI_VK_POPUP_HINT__
        if (gui_virtual_keyboard_is_popup_can_be_shown(v, v->selected_key.index))
            gui_virtual_keyboard_show_popup_hint(v,GUI_VK_KEY_STATE_LONGTAP_POPUP,MMI_TRUE);
#endif        
    }

    gui_virtual_keyboard_discard_cache_and_recache_normal_key(v);
    gui_virtual_keyboard_draw_key(v, v->selected_key.index);

    //        gdi_pop_and_restore_alpha_blending_source_layer();
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_VK_CACHE_STORE_LONGTAP_POPUP, v->selected_key.x,v->selected_key.y);
    gdi_layer_blt_previous(v->selected_key.x,v->selected_key.y,v->selected_key.x + v->selected_key.width - 1, v->selected_key.y + v->selected_key.height - 1);
}



/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_long_tap_popup_deactive
* DESCRIPTION
*  The function sets the longtap pop-up state as deactive
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_long_tap_popup_deactive(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    v->is_mini_keyboard_state = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_set_long_tap_popup_active
* DESCRIPTION
*  The function sets the longtap pop-up state as active
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer 
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_set_long_tap_popup_active(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v->is_mini_keyboard_state = MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_get_long_tap_popup_state
* DESCRIPTION
*  The function returns the longtap pop-up state
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer 
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL gui_virtual_keyboard_get_long_tap_popup_state(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
    return v->is_mini_keyboard_state;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_print_longtap_popup_characters
* DESCRIPTION
*  The function prints the longtap pop-up characters on the longtap pop-up
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer  
* RETURNS
*  void
*****************************************************************************/
static void gui_virtual_keyboard_print_longtap_popup_characters(
    gui_virtual_keyboard_struct *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_get_longtap_popup_index_for_highlighling
* DESCRIPTION
*  The function returns the index of the character to be highlighted on the 
*  longtap pop-up. The API does not sets the highlighted index of the 
*  longtap pop-up to the index being returned as the highlighter has not yet 
*  been drawn
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer
*  x       [IN]            x coordinate of pen position
*  y       [IN]            y coordinate of pen position
* RETURNS
*  U16
*****************************************************************************/
static S16 gui_virtual_keyboard_get_longtap_popup_index_for_highlighling(
    gui_virtual_keyboard_struct *v, 
    S16 x, 
    S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return 1;
}


static MMI_BOOL gui_virtual_keyboard_mini_keyboard_translate_pen_position(
    gui_virtual_keyboard_struct *v, 
    S16 x, 
    S16 y,
    const gui_virtual_keyboard_key_struct** key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i,j = 0;
    S32 key_x, key_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(v != NULL);
    *key = NULL;

    if (y < v->y + v->row_list[0].key_list[0].pos_y)
        return MMI_FALSE;

    for (i = 0; i < v->row_num; i++)
    {
        if (!gui_virtual_keyboard_is_active_row_id(v,i))
            continue;
        key_y = v->y + v->row_list[i].key_list[0].pos_y + v->row_list[i].key_list[0].height;
        if (y > key_y && v->row_num > i + 1)
            continue;
        for(; j < v->row_list[i].key_count; j++)
        {
            key_x = v->x + v->row_list[i].key_list[j].pos_x + v->row_list[i].key_list[j].width;
            if ( x > key_x)
            {
                continue;
            }
            else if (x > v->x)
            {
                (*key) = v->row_list[i].key_list + j;
                return MMI_TRUE;
            }
        }
        break;
    }

    if (x < v->x + v->width)
    {
        (*key) = v->row_list[i].key_list + j - 1;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_longtap_popup_translate_pen_event
* DESCRIPTION
*  translate pen event in longtap popup
* PARAMETERS
*
* RETURNS
*
* REMARKS
*
*****************************************************************************/
static void gui_virtual_keyboard_longtap_popup_translate_pen_event(
    gui_virtual_keyboard_struct *v, 
    S16 x, 
    S16 y,
    mmi_pen_event_type_enum pen_event,
    gui_virtual_keyboard_pen_enum *key_event,
    gui_pen_event_param_struct *key_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const gui_virtual_keyboard_key_struct* key_index;
    UI_character_type temp_char = 0;
    gui_virtual_keyboard_pen_enum temp_event = GUI_VKBD_PEN_NONE;
    UI_string_type temp_string = NULL;

    kal_prompt_trace(MOD_XDM,"gui_virtual_keyboard_longtap_popup_translate_pen_event. pen_event = %d",pen_event);
    if (!gui_virtual_keyboard_get_long_tap_popup_state(v))
        return;
    switch( pen_event )
    {
    case MMI_PEN_EVENT_MOVE:

        if (gui_virtual_keyboard_mini_keyboard_translate_pen_position(v, x, y, &key_index))
        {
            if (key_index != v->selected_key.index)
            {

                gui_virtual_keyboard_show_unselect_key_from_cache(v);
                gui_virtual_keyboard_get_selected_key(v, key_index, pen_event, &temp_char, &temp_event);
                if (!((temp_event == GUI_VKBD_PEN_NONE) ||
                    gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index)))
                {
                    gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
#if defined(__MMI_VK_POPUP_HINT__)
                    v->is_cursor_stop = MMI_FALSE;
#endif /* defined(__MMI_VK_POPUP_HINT__) */
                    gui_virtual_keyboard_cache_and_show_selected_key(v); 
                }


                if (temp_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
                {
                    temp_string = v->selected_key.index->label_string;
                }
                if (temp_event == GUI_VKBD_PEN_CHAR_I)
                {
                    MMI_DBG_ASSERT(temp_char != 0);
                    *key_event = temp_event;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
                }
                else if (temp_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
                {
                    MMI_DBG_ASSERT(temp_string != NULL);
                    *key_event = temp_event;
                    GUI_PEN_EVENT_PARAM_SET_POINTER(key_param, (void*)temp_string);
                }

            }
        }
        else
        {
            //return to nomal keybord
            //v->key_down_accepted = MMI_FALSE;
        } 
        break;

    case MMI_PEN_EVENT_UP:

        if (gui_virtual_keyboard_mini_keyboard_translate_pen_position(v, x, y, &key_index))
        {
            if (key_index != v->selected_key.index)
            {
                key_index = v->selected_key.index;
            }
            ///TODO: check whether need to show selected key.
            gui_virtual_keyboard_show_unselect_key_from_cache(v);
            gui_virtual_keyboard_get_selected_key(v, key_index, pen_event, &temp_char, &temp_event);
            *key_event = temp_event;
            if (temp_event == GUI_VKBD_PEN_DEAD_KEY)
            {
                temp_event = GUI_VKBD_PEN_NONE;
            }
            if (temp_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
            {
                temp_string = v->selected_key.index->label_string;
            }
            if (temp_event == GUI_VKBD_PEN_CHAR_I)
            {
                MMI_DBG_ASSERT(temp_char != 0);
                *key_event = temp_event;
                GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
            }
            else if (temp_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
            {
                MMI_DBG_ASSERT(temp_string != NULL);
                *key_event = temp_event;
                GUI_PEN_EVENT_PARAM_SET_POINTER(key_param, (void*)temp_string);
            }
            if (!((temp_event == GUI_VKBD_PEN_NONE) ||
                gui_virtual_keyboard_is_disabled_key(v, v->selected_key.index)))
            {
                gui_virtual_keyboard_is_cursor_stopped_by_vk = MMI_FALSE;
                gui_virtual_keyboard_cache_and_show_selected_key(v); 
            }
	    else
	    {
	        *key_event = GUI_VKBD_PEN_NONE;
		GUI_PEN_EVENT_PARAM_SET_VOID(key_param);
	    }

            gui_virtual_keyboard_resume_from_longtap_state(v);

        }
        else
        {
            //return to nomal keybord
            gui_virtual_keyboard_resume_from_longtap_state(v);
        } 

        break;
    default:
        break;
    }
    if (temp_event == GUI_VKBD_PEN_CHAR_I)
    {
        MMI_DBG_ASSERT(temp_char != 0);
        GUI_PEN_EVENT_PARAM_SET_INTEGER(key_param, (int)temp_char);
    }
    else if (*key_event == GUI_VKBD_PEN_V3_CHAR_I_STRING)
    {
        MMI_DBG_ASSERT(temp_string != NULL);
        GUI_PEN_EVENT_PARAM_SET_POINTER(key_param, (void*)temp_string);
    }
}

#endif /* __MMI_VK_LONGTAP_POPUP_HINT__ */


#endif /* __MMI_VK_POPUP_HINT__ */

#ifdef __MMI_VK_POPUP_HINT__        
/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_show_popup
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void gui_virtual_keyboard_show_popup_hint(
    gui_virtual_keyboard_struct* v,
    gui_virtual_keyboard_key_state_enum key_state, 
    MMI_BOOL cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float ratio_x = 0, ratio_y = 0;
    U16 img_id;
    gui_virtual_keyboard_key_label_info_struct main_label, aux_label;
    gui_virtual_keyboard_rect_struct key_pos_rect;
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)  			
    MMI_BOOL is_dither;
#endif            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(v);
    if (!gui_virtual_keyboard_is_key_down_accept(v))
        return;

    if (cache == MMI_TRUE)
    {
        gui_virtual_keyboard_discard_cache_and_recache_hint(v);
    }
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)  
    is_dither = gdi_image_9slice_get_dither();
    gdi_image_9slice_set_dither(MMI_FALSE);
#endif
    //calculate the position of the key's hint
    gui_virtual_keyboard_get_key_hint_rect(v,v->selected_key.index,&key_pos_rect);
    gui_virtual_keyboard_stop_cursor_blink(key_pos_rect.x,key_pos_rect.y,key_pos_rect.x + key_pos_rect.width - 1,key_pos_rect.y + key_pos_rect.height - 1);
    gui_push_clip();
    gui_set_clip(key_pos_rect.x,key_pos_rect.y,key_pos_rect.x + key_pos_rect.width - 1,key_pos_rect.y + key_pos_rect.height - 1);

    gui_virtual_keyboard_get_key_bg_img(v,v->selected_key.index,&img_id, GUI_VK_KEY_STATE_POPUP);
    ///TODO: show label
    if (img_id != 0)
    {
        gdi_image_draw_resized_blend2layers(
            key_pos_rect.x,
            key_pos_rect.y,
            key_pos_rect.width ,
            key_pos_rect.height,
            (PU8)get_image(img_id));
    }
    gui_virtual_keyboard_get_key_main_label(v,
        v->selected_key.index,
        &main_label, 
        key_state);
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    main_label.size = VIRTUAL_KEYBOARD_FONT;
#endif
    gui_virtual_keyboard_show_label(main_label,key_pos_rect,key_state);
    gui_virtual_keyboard_get_key_aux_label(v,
        v->selected_key.index,
        &aux_label, 
        key_state);
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    aux_label.size = VIRTUAL_KEYBOARD_FONT;
#endif
    gui_virtual_keyboard_show_label(aux_label,key_pos_rect,key_state);
#if !defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)  		   
    gdi_image_9slice_set_dither(is_dither);
#endif
    gui_pop_clip();

    gdi_layer_blt_previous(key_pos_rect.x,key_pos_rect.y,key_pos_rect.x + key_pos_rect.width - 1,key_pos_rect.y + key_pos_rect.height - 1);

}
#endif /* __MMI_VK_POPUP_HINT__ */        

/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_register_get_vk_callback
* DESCRIPTION
*  Register event callback of virtual keyboard
* PARAMETERS
*  v       [IN/OUT]    Is the virtual keyboard object
*  f       [IN]        Is the event callback
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_register_get_vk_callback(
    gui_virtual_keyboard_get_vk_callback_func_ptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_get_virtual_keyboard_callback = f;
}


/*****************************************************************************
* FUNCTION
*  gui_vk_longtap_timer_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void gui_vk_longtap_timer_handler(
                                  void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VK_LONGTAP_POPUP_HINT__
    gui_virtual_keyboard_struct_p v = gui_get_virtual_keyboard_callback();
    kal_prompt_trace(MOD_XDM,"gui_vk_longtap_timer_handler.");

    if (gui_virtual_keyboard_is_key_down_accept(v))
    {
        if (gui_virtual_keyboard_is_mini_keyboard_state(v))
        {
            gui_cancel_timer(gui_vk_longtap_timer_handler);
            return;
        }
        gui_cancel_timer(gui_vk_longtap_timer_handler);

        if (gui_virtual_keyboard_create_and_enter_mini_keyboard(v))
            return;
    }

#endif
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_clear_cache_on_imc_disconnect
* DESCRIPTION 
*  The function clears the cache when imc disconnects 
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer     
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_clear_cache_on_imc_disconnect(gui_virtual_keyboard_struct *v)
{
    if (v->selected_key.key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->selected_key.key_bitmap.buf_ptr);
        v->selected_key.key_bitmap.buf_ptr = NULL;
        v->selected_key.is_key_cached = MMI_FALSE;
    }

#if defined(__MMI_VK_POPUP_HINT__)
    if (v->popup_hint.key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->popup_hint.key_bitmap.buf_ptr);
        v->popup_hint.is_key_cached = MMI_FALSE;
        v->popup_hint.key_bitmap.buf_ptr = NULL;
    }
#endif 

#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
    if (v->mini_keyboard_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(v->mini_keyboard_bitmap.buf_ptr);        
        v->mini_keyboard_bitmap.buf_ptr = NULL;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  gui_virtual_keyboard_clear_cache_on_imc_disconnect
* DESCRIPTION 
*  The function clears the cache when imc disconnects 
* PARAMETERS
*  v       [IN/OUT]        Is the virtual keyboard pointer     
* RETURNS
*  void
*****************************************************************************/
void gui_virtual_keyboard_clear_state_on_imc_disconnect(gui_virtual_keyboard_struct *v)
{
#if defined(__MMI_VK_LONGTAP_POPUP_HINT__) 
    v->is_mini_keyboard_state = MMI_FALSE;
    v->popup_vk_layout_p = NULL;   //this is for pop up virtual keyboard
    v->vk_layout_backup = NULL;    //this is for resume the virtual keyboard
    v->popup_key = NULL;
#endif
    gui_virtual_keyboard_clear_selected_key(v);
}


U32 gui_virtual_keyboard_get_vk_width(void)
{
    gui_virtual_keyboard_struct *v;
    v = gui_get_virtual_keyboard_callback();
#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
    if(gui_virtual_keyboard_is_mini_keyboard_state(v))
    {
        return ((wgui_virtual_keyboard_layout_struct*)v->vk_layout_backup)->width;
    }
    else
#endif
    {
        return v->width;
    }

}


U32 gui_virtual_keyboard_get_vk_height(void)
{
    gui_virtual_keyboard_struct *v;
    v = gui_get_virtual_keyboard_callback();
#if defined(__MMI_VK_LONGTAP_POPUP_HINT__)
    if(gui_virtual_keyboard_is_mini_keyboard_state(v))
    {
        return ((wgui_virtual_keyboard_layout_struct*)v->vk_layout_backup)->height;
    }
    else
#endif
    {
        return v->height;
    }
}


U32 gui_virtual_keyboard_return_floating_composition_box_width(void)
{
    gui_virtual_keyboard_rect_struct rect;
    const gui_virtual_keyboard_key_struct * key;

    if (!gui_virtual_keyboard_is_alphanumeric_vk())
        return 0;

    gui_virtual_keyboard_translate_index_to_pointer(0, &key);

    gui_virtual_keyboard_get_key_rect(key, &rect);

    return rect.width + key->pos_x;
}


MMI_BOOL gui_virtual_keyboard_is_rotate_vk(void)
{
    return gui_get_virtual_keyboard_callback()->is_rotate;
}


MMI_BOOL gui_virtual_keyboard_is_cached(void)
{
    return MMI_FALSE;
}


MMI_BOOL gui_virtual_keyboard_is_shift_support(
    gui_virtual_keyboard_struct* v)
{
    MMI_ASSERT(v != NULL);
    return MMI_TRUE;
}
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__ */
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */

