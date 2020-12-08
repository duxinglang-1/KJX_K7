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
 *   jui_virtual_keypad.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__J2ME__)
#if defined(__SUPPORT_JAVA_VIRTUAL_KEYPAD__)
/*************************************************************************
 * Include header files
 *************************************************************************/
#include "mmi_include.h"
#include "gdi_include.h"
#include "PixcomFontEngine.h"
#include "gui.h"
#include "keypad_sw.h"
#include "kal_trace.h"
#include "j2me_trace.h"
#include "jvm_trace_interface.h"
#include "jam_mvm_manager.h"
#include "jui_interface.h"
#include "jui_internal.h"
#include "jvm_adaptor.h"
#include "mmi_rp_app_java_def.h"
#include "gui_touch_feedback.h"

/*************************************************************************
 * External Function
 *************************************************************************/

/*************************************************************************
 * External Variable
 *************************************************************************/
extern kal_uint16 *jui_vk_lcd_buffer;
extern kal_int32 jui_vk_lcd_buffer_size;
extern gdi_handle jui_vk_layer_handle;
extern kal_int32 jui_title_offset;

#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT

extern GDI_HANDLE jui_layer_handle;
extern GDI_HANDLE jui_soft_button_layer_handle;
extern kal_int32 jui_ui_device_width;
extern kal_int32 jui_ui_device_height;
extern kal_int32 jui_ui_button_height;

#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */

/*************************************************************************
 * Global Variable
 *************************************************************************/
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
#define JUI_VIRTUAL_KEYPAD_NAVIGATION_SIZE (8)
#define JUI_VIRTUAL_KEYPAD_NUMERIC_SIZE (16)

#define JUI_VIRTUAL_KEYPAD_KEY_123 (KEY_INVALID + 1)
#define JUI_VIRTUAL_KEYPAD_KEY_NAVI (KEY_INVALID + 2)
#else
#define JUI_VIRTUAL_KEYPAD_NAVIGATION_SIZE (2)
#endif

static kal_int32 jui_vk_key_down_index = -1;
kal_int32 jui_vk_display_id = INVALIDE_VM_ID;
static kal_int32 jui_vk_display_id_last = INVALIDE_VM_ID;
static kal_uint8 jui_vk_current_type = JUI_VK_TYPE_END;

#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
static jui_vk_coordinate_struct navigation_keypad[JUI_VIRTUAL_KEYPAD_NAVIGATION_SIZE] = {
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_SOFTKEY_WIDTH,
     KEY_LSK,
     IMG_ID_JAVA_VK_LSK,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_SOFTKEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_UP_ARROW,
     IMG_ID_JAVA_VK_NAV_UP,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_SOFTKEY_WIDTH + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING * 2,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_SOFTKEY_WIDTH,
     KEY_RSK,
     IMG_ID_JAVA_VK_RSK,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     JUI_VIRTUAL_KEYPAD_KEY_123,
     0,
     STR_JAVA_VK_123,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_LEFT_ARROW,
     IMG_ID_JAVA_VK_NAV_LEFT,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH * 2 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 2,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_DOWN_ARROW,
     IMG_ID_JAVA_VK_NAV_DOWN,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH * 3 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 3,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_RIGHT_ARROW,
     IMG_ID_JAVA_VK_NAV_RIGHT,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH * 4 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 4,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_ENTER,
     0,
     STR_GLOBAL_OK,
     JUI_VK_CONTENT_TYPE_STRING}};
	
static jui_vk_coordinate_struct numeric_keypad[JUI_VIRTUAL_KEYPAD_NUMERIC_SIZE] = {
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_LSK,
     IMG_ID_JAVA_VK_LSK,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_1,
     0,
     STR_GLOBAL_1,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING * 2,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_2,
     0,
     STR_GLOBAL_2,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 2 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 3,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_3,
     0,
     STR_GLOBAL_3,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 3 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 4,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_4,
     0,
     STR_GLOBAL_4,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 4 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 5,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_5,
     0,
     STR_GLOBAL_5,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 5 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 6,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_6,
     0,
     STR_GLOBAL_6,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 6 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 7,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_RSK,
     IMG_ID_JAVA_VK_RSK,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     JUI_VIRTUAL_KEYPAD_KEY_NAVI,
     IMG_ID_JAVA_VK_NAVIGATION,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_7,
     0,
     STR_GLOBAL_7,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING * 2,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_8,
     0,
     STR_GLOBAL_8,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 2 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 3,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_9,
     0,
     STR_GLOBAL_9,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 3 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 4,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_0,
     0,
     STR_GLOBAL_0,
     JUI_VK_CONTENT_TYPE_STRING},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 4 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 5,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_STAR,
     IMG_ID_JAVA_VK_STAR,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 5 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 6,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH,
     KEY_POUND,
     IMG_ID_JAVA_VK_POUND,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH + JUI_VIRTUAL_KEYPAD_NUM_KEY_WIDTH * 6 + JUI_VIRTUAL_KEYPAD_COL_SPACING * 7,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT + JUI_VIRTUAL_KEYPAD_ROW_SPACING,
     JUI_VIRTUAL_KEYPAD_ARROW_KEY_WIDTH,
     KEY_ENTER,
     0,
     STR_GLOBAL_OK,
     JUI_VK_CONTENT_TYPE_STRING}};
#else
static jui_vk_coordinate_struct navigation_keypad[JUI_VIRTUAL_KEYPAD_NAVIGATION_SIZE] = {
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_SOFTKEY_WIDTH,
     KEY_LSK,
     IMG_ID_JAVA_VK_LSK,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE},
    {JUI_VIRTUAL_KEYPAD_HORIZONTAL_INDENT + JUI_VIRTUAL_KEYPAD_SOFTKEY_WIDTH + JUI_VIRTUAL_KEYPAD_COL_SPACING,
     JUI_VIRTUAL_KEYPAD_VERTICAL_INDENT,
     JUI_VIRTUAL_KEYPAD_SOFTKEY_WIDTH,
     KEY_RSK,
     IMG_ID_JAVA_VK_RSK,
     0,
     JUI_VK_CONTENT_TYPE_IMAGE}};
#endif


#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
/*****************************************************************************
 * FUNCTION
 *  jui_vk_prepare_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_prepare_blt(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI,
              FUNC_J2ME_JUI_VK_PREPARE_BLT,
                    jui_layer_handle,
                    g_jui_screen_data[display_id].screen_mode,
                    g_jui_screen_data[display_id].is_show_logo_screen,
                    jui_widget_obj_show_status(JUI_OBJ_STATUS_BAR, display_id),
              display_id);

#ifdef  __JUI_VK_SLIM__
    if (jui_vk_layer_handle == NULL) /*VK layer is only available when registered LCD for SLIM projects*/
        return;
#endif

    if (jam_mvm_get_current_vm_id()!= display_id)
    {
        return;
    }

    if (g_jui_screen_data[display_id].screen_mode == JUI_SCREEN_MODE_NORMAL 
        &&  g_jui_screen_data[display_id].is_show_logo_screen == KAL_FALSE)
    {
        jui_lcd_mutex_lock();
        if (jui_soft_button_layer_handle != GDI_LAYER_EMPTY_HANDLE
            /*&& jui_widget_obj_show_status(JUI_OBJ_BUTTON_BAR, display_id)*/)
        {
            gdi_layer_push_and_set_active(jui_soft_button_layer_handle);
            gdi_bitblt_resized(
                jui_vk_layer_handle,
                0,
                0,
                jui_ui_device_width - 1,
                JUI_VIRTUAL_KEYPAD_HEIGHT - 1,
                0,
                0,
                jui_ui_device_width - 1,
                JUI_VIRTUAL_KEYPAD_HEIGHT - 1);
            gdi_layer_pop_and_restore_active();
        }
        /*else if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_push_and_set_active(jui_layer_handle);
            gdi_bitblt_resized(
                jui_vk_layer_handle,
                0,
                0,
                jui_ui_device_width - 1,
                JUI_VIRTUAL_KEYPAD_HEIGHT - 1,
                0,
                jui_ui_device_height - jui_ui_button_height - jui_title_offset,
                jui_ui_device_width - 1,
                jui_ui_device_height - jui_ui_button_height - jui_title_offset + JUI_VIRTUAL_KEYPAD_HEIGHT - 1);
            gdi_layer_pop_and_restore_active();
        }*/
        jui_lcd_mutex_unlock();
    }


}

#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */


/*****************************************************************************
 * FUNCTION
 *  jui_vk_refresh_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_refresh_keypad(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_REFRESH_KEYPAD, jui_vk_display_id);
    
    if (jui_vk_display_id < 0 || jui_vk_display_id >= JUI_MVM_SUPPORT_VM_NUM)
    {
        return;
    }
	
    if (jui_widget_mvm_get_screen_mode(jui_vk_display_id) == JUI_SCREEN_MODE_NORMAL)
    {
#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
        jui_vk_prepare_blt(jui_vk_display_id);
#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */

        jui_widget_mvm_refresh_lcd(0,
                                   jui_widget_get_display_height() - jui_widget_get_button_bar_height(),
                                   jui_widget_get_display_width() - 1,
                                   jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - jui_widget_get_button_bar_height() - 1,
                                   jui_vk_display_id);
    }
    else if (jui_widget_mvm_get_screen_mode(jui_vk_display_id) == JUI_SCREEN_MODE_FULL)
    {
        jui_widget_mvm_refresh_lcd(0,
                                   jui_widget_get_display_height(),
                                   jui_widget_get_display_width() - 1,
                                   jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - 1,
                                   jui_vk_display_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_draw_navigation_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_draw_navigation_keypad(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/
	int i = 0;
    int width = 0;
    int height = 0;
    stFontAttribute font = {0};
    gdi_handle org_src_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_DRAW_NAVIGATION_KEYPAD);

#ifdef  __JUI_VK_SLIM__
    if (jui_vk_layer_handle == NULL) /*VK layer is only available when registered LCD for SLIM projects*/
        return;
    jui_is_vm_drawing_lcd = KAL_TRUE;
#endif

    gdi_get_alpha_blending_source_layer(&org_src_layer_handle);
	
    gdi_layer_push_and_set_active(jui_vk_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_clear(GDI_COLOR_WHITE);

    gdi_set_alpha_blending_source_layer(jui_vk_layer_handle);
	
    gdi_image_draw_resized_id(0, 0, UI_device_width, JUI_VIRTUAL_KEYPAD_HEIGHT, IMG_ID_JAVA_VK_BG);
	
    for (; i < JUI_VIRTUAL_KEYPAD_NAVIGATION_SIZE; i++)
    {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
        if (navigation_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_123)
        {
            gdi_image_draw_resized_id(navigation_keypad[i].x,
                                      navigation_keypad[i].y,
                                      navigation_keypad[i].width,
                                      JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                      IMG_ID_JAVA_VK_DARK_GRAY_UP);
        }
        else
#endif
        {
            gdi_image_draw_resized_id(navigation_keypad[i].x,
                                      navigation_keypad[i].y,
                                      navigation_keypad[i].width,
                                      JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                      IMG_ID_JAVA_VK_LIGHT_GRAY_UP);
        }

        if (navigation_keypad[i].content_type == JUI_VK_CONTENT_TYPE_IMAGE)
        {
            gdi_image_get_dimension_id(navigation_keypad[i].content_img_id, &width, &height);
            gdi_image_draw_id(navigation_keypad[i].x + ((navigation_keypad[i].width - width) / 2),
                              navigation_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2),
                              navigation_keypad[i].content_img_id);
        }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
        else if (navigation_keypad[i].content_type == JUI_VK_CONTENT_TYPE_STRING)
        {
            font.size = FONT_PIXEL_SIZE(JUI_VIRTUAL_KEYPAD_OK_CHAR_SIZE);
            font.type = 1;
            gui_set_font(&font);
			
            gui_measure_string((UI_string_type) GetString(navigation_keypad[i].content_str_id), &width, &height);
            if(r2lMMIFlag == 1)
            {
                width += navigation_keypad[i].x + ((navigation_keypad[i].width - width) / 2);
            }
			else
		    {
		        width = navigation_keypad[i].x + ((navigation_keypad[i].width - width) / 2);
			}
            height = navigation_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2);
            if (navigation_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_123)
            {
                width -= JUI_VIRTUAL_KEYPAD_CHAR_1_OFFSET;
            }
            gui_move_text_cursor(width, height);
            if (navigation_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_123)
            {
                gui_set_text_color(gui_color(255, 255, 255));
            }
            else
            {
                gui_set_text_color(gui_color(0, 0, 0));
            }
            gui_print_text((UI_string_type) GetString(navigation_keypad[i].content_str_id));
        }
#endif
    }
	
    gdi_layer_pop_and_restore_active();

    gdi_set_alpha_blending_source_layer(org_src_layer_handle);
	
    jui_vk_current_type = JUI_VK_TYPE_NAVIGATION;
    jui_vk_key_down_index = -1;

#ifdef  __JUI_VK_SLIM__
    jui_is_vm_drawing_lcd = KAL_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_draw_navigation_keypad_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_draw_navigation_keypad_highlight(kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/
    int i = 0;
    int width = 0;
    int height = 0;
    stFontAttribute font = {0};
    gdi_handle org_src_layer_handle;
	
    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_DRAW_NAVIGATION_KEYPAD_HIGHLIGHT, jui_vk_key_down_index, index);
	
#ifdef  __JUI_VK_SLIM__
    if (jui_vk_layer_handle == NULL) /*VK layer is only available when registered LCD for SLIM projects*/
        return;
    jui_is_vm_drawing_lcd = KAL_TRUE;
#endif

    if (jui_vk_key_down_index == index)
    {
        return;
    }

    gdi_get_alpha_blending_source_layer(&org_src_layer_handle);
	
    gdi_layer_push_and_set_active(jui_vk_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_clear(GDI_COLOR_WHITE);

    gdi_set_alpha_blending_source_layer(jui_vk_layer_handle);
	
    gdi_image_draw_resized_id(0, 0, UI_device_width, JUI_VIRTUAL_KEYPAD_HEIGHT, IMG_ID_JAVA_VK_BG);
	
    for (; i < JUI_VIRTUAL_KEYPAD_NAVIGATION_SIZE; i++)
    {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
        if (navigation_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_123)
        {
            if (index == i)
            {
                gdi_image_draw_resized_id(navigation_keypad[i].x,
                                          navigation_keypad[i].y,
                                          navigation_keypad[i].width,
                                          JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                          IMG_ID_JAVA_VK_DARK_GRAY_DOWN);
            }
            else
            {
                gdi_image_draw_resized_id(navigation_keypad[i].x,
                                          navigation_keypad[i].y,
                                          navigation_keypad[i].width,
                                          JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                          IMG_ID_JAVA_VK_DARK_GRAY_UP);
            }
        }
        else
#endif
        {
            if (index == i)
            {
                gdi_image_draw_resized_id(navigation_keypad[i].x,
                                          navigation_keypad[i].y,
                                          navigation_keypad[i].width,
                                          JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                          IMG_ID_JAVA_VK_LIGHT_GRAY_DOWN);
            }
            else
            {
               gdi_image_draw_resized_id(navigation_keypad[i].x,
                                         navigation_keypad[i].y,
                                         navigation_keypad[i].width,
                                         JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                         IMG_ID_JAVA_VK_LIGHT_GRAY_UP);
            }
        }

        if (navigation_keypad[i].content_type == JUI_VK_CONTENT_TYPE_IMAGE)
        {
            gdi_image_get_dimension_id(navigation_keypad[i].content_img_id, &width, &height);
            gdi_image_draw_id(navigation_keypad[i].x + ((navigation_keypad[i].width - width) / 2),
                              navigation_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2),
                              navigation_keypad[i].content_img_id);
        }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
        else if (navigation_keypad[i].content_type == JUI_VK_CONTENT_TYPE_STRING)
        {
            font.size = FONT_PIXEL_SIZE(JUI_VIRTUAL_KEYPAD_OK_CHAR_SIZE);
            font.type = 1;
            gui_set_font(&font);
			
            gui_measure_string((UI_string_type) GetString(navigation_keypad[i].content_str_id), &width, &height);
			if(r2lMMIFlag == 1)
            {
                width += navigation_keypad[i].x + ((navigation_keypad[i].width - width) / 2);
            }
			else
		    {
                width = navigation_keypad[i].x + ((navigation_keypad[i].width - width) / 2);
		    }
            height = navigation_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2);
            if (navigation_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_123)
            {
                width -= JUI_VIRTUAL_KEYPAD_CHAR_1_OFFSET;
            }
            gui_move_text_cursor(width, height);
            if (navigation_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_123)
            {
                gui_set_text_color(gui_color(255, 255, 255));
            }
            else
            {
                gui_set_text_color(gui_color(0, 0, 0));
            }
            gui_print_text((UI_string_type) GetString(navigation_keypad[i].content_str_id));
        }
#endif
    }

    jui_vk_key_down_index = index;
	
    gdi_layer_pop_and_restore_active();

    gdi_set_alpha_blending_source_layer(org_src_layer_handle);

    jui_vk_refresh_keypad();

#ifdef  __JUI_VK_SLIM__
    jui_is_vm_drawing_lcd = KAL_FALSE;
#endif
}

#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
/*****************************************************************************
 * FUNCTION
 *  jui_vk_draw_numeric_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_draw_numeric_keypad(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/
	int i = 0;
    int width = 0;
    int height = 0;
    stFontAttribute font = {0};
    gdi_handle org_src_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_DRAW_NUMERIC_KEYPAD);

#ifdef  __JUI_VK_SLIM__
    if (jui_vk_layer_handle == NULL) /*VK layer is only available when registered LCD for SLIM projects*/
        return;
    jui_is_vm_drawing_lcd = KAL_TRUE;
#endif

    gdi_get_alpha_blending_source_layer(&org_src_layer_handle);
	
    gdi_layer_push_and_set_active(jui_vk_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_clear(GDI_COLOR_WHITE);

    gdi_set_alpha_blending_source_layer(jui_vk_layer_handle);

    gdi_image_draw_resized_id(0, 0, UI_device_width, JUI_VIRTUAL_KEYPAD_HEIGHT, IMG_ID_JAVA_VK_BG);
	
    for (; i < JUI_VIRTUAL_KEYPAD_NUMERIC_SIZE; i++)
    {
        if (numeric_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_NAVI)
        {
            gdi_image_draw_resized_id(numeric_keypad[i].x,
                                      numeric_keypad[i].y,
                                      numeric_keypad[i].width,
                                      JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                      IMG_ID_JAVA_VK_DARK_GRAY_UP);
        }
        else
        {
            gdi_image_draw_resized_id(numeric_keypad[i].x,
                                      numeric_keypad[i].y,
                                      numeric_keypad[i].width,
                                      JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                      IMG_ID_JAVA_VK_LIGHT_GRAY_UP);
        }

        if (numeric_keypad[i].content_type == JUI_VK_CONTENT_TYPE_IMAGE)
        {
            gdi_image_get_dimension_id(numeric_keypad[i].content_img_id, &width, &height);
            gdi_image_draw_id(numeric_keypad[i].x + ((numeric_keypad[i].width - width) / 2),
                              numeric_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2),
                              numeric_keypad[i].content_img_id);
        }
        else if (numeric_keypad[i].content_type == JUI_VK_CONTENT_TYPE_STRING)
        {
            if (numeric_keypad[i].key_code == KEY_ENTER)
            {
                font.size = FONT_PIXEL_SIZE(JUI_VIRTUAL_KEYPAD_OK_CHAR_SIZE);
            }
            else
            {
                font.size = FONT_PIXEL_SIZE(JUI_VIRTUAL_KEYPAD_NUM_CHAR_SIZE);
            }
            font.type = 1;
            gui_set_font(&font);
			
            gui_measure_string((UI_string_type) GetString(numeric_keypad[i].content_str_id), &width, &height);
            if(r2lMMIFlag == 1)
            {
                width += numeric_keypad[i].x + ((numeric_keypad[i].width - width) / 2);
            }
			else
		    {
		        width = numeric_keypad[i].x + ((numeric_keypad[i].width - width) / 2);
		    }			
            height = numeric_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2);
            if (numeric_keypad[i].key_code == KEY_1)
            {
                width -= JUI_VIRTUAL_KEYPAD_CHAR_1_OFFSET;
            }
            gui_move_text_cursor(width, height);
            gui_set_text_color(gui_color(0, 0, 0));
            gui_print_text((UI_string_type) GetString(numeric_keypad[i].content_str_id));
        }
    }
	
    gdi_layer_pop_and_restore_active();

    gdi_set_alpha_blending_source_layer(org_src_layer_handle);

    jui_vk_current_type = JUI_VK_TYPE_NUMERIC;
    jui_vk_key_down_index = -1;

#ifdef  __JUI_VK_SLIM__
    jui_is_vm_drawing_lcd = KAL_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_draw_numeric_keypad_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_draw_numeric_keypad_highlight(kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/
    int i = 0;
    int width = 0;
    int height = 0;
    stFontAttribute font = {0};
    gdi_handle org_src_layer_handle;
	
    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_DRAW_NUMERIC_KEYPAD_HIGHLIGHT, jui_vk_key_down_index, index);
	
#ifdef  __JUI_VK_SLIM__
    if (jui_vk_layer_handle == NULL) /*VK layer is only available when registered LCD for SLIM projects*/
        return;
    jui_is_vm_drawing_lcd = KAL_TRUE;
#endif

    if (jui_vk_key_down_index == index)
    {
        return;
    }

    gdi_get_alpha_blending_source_layer(&org_src_layer_handle);
	
    gdi_layer_push_and_set_active(jui_vk_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_clear(GDI_COLOR_WHITE);

    gdi_set_alpha_blending_source_layer(jui_vk_layer_handle);

    gdi_image_draw_resized_id(0, 0, UI_device_width, JUI_VIRTUAL_KEYPAD_HEIGHT, IMG_ID_JAVA_VK_BG);
	
    for (; i < JUI_VIRTUAL_KEYPAD_NUMERIC_SIZE; i++)
    {
        if (numeric_keypad[i].key_code == JUI_VIRTUAL_KEYPAD_KEY_NAVI)
        {
            if (index == i)
            {
                gdi_image_draw_resized_id(numeric_keypad[i].x,
                                          numeric_keypad[i].y,
                                          numeric_keypad[i].width,
                                          JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                          IMG_ID_JAVA_VK_DARK_GRAY_DOWN);
            }
            else
            {
                gdi_image_draw_resized_id(numeric_keypad[i].x,
                                          numeric_keypad[i].y,
                                          numeric_keypad[i].width,
                                          JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                          IMG_ID_JAVA_VK_DARK_GRAY_UP);
            }
        }
        else
        {
            if (index == i)
            {
                gdi_image_draw_resized_id(numeric_keypad[i].x,
                                          numeric_keypad[i].y,
                                          numeric_keypad[i].width,
                                          JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                          IMG_ID_JAVA_VK_LIGHT_GRAY_DOWN);
            }
            else
            {
                gdi_image_draw_resized_id(numeric_keypad[i].x,
                                          numeric_keypad[i].y,
                                          numeric_keypad[i].width,
                                          JUI_VIRTUAL_KEYPAD_KEY_HEIGHT,
                                          IMG_ID_JAVA_VK_LIGHT_GRAY_UP);
            }
        }

        if (numeric_keypad[i].content_type == JUI_VK_CONTENT_TYPE_IMAGE)
        {
            gdi_image_get_dimension_id(numeric_keypad[i].content_img_id, &width, &height);
            gdi_image_draw_id(numeric_keypad[i].x + ((numeric_keypad[i].width - width) / 2),
                              numeric_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2),
                              numeric_keypad[i].content_img_id);
        }
        else if (numeric_keypad[i].content_type == JUI_VK_CONTENT_TYPE_STRING)
        {
            if (numeric_keypad[i].key_code == KEY_ENTER)
            {
                font.size = FONT_PIXEL_SIZE(JUI_VIRTUAL_KEYPAD_OK_CHAR_SIZE);
            }
            else
            {
                font.size = FONT_PIXEL_SIZE(JUI_VIRTUAL_KEYPAD_NUM_CHAR_SIZE);
            }
            font.type = 1;
            gui_set_font(&font);
			
            gui_measure_string((UI_string_type) GetString(numeric_keypad[i].content_str_id), &width, &height);
			if(r2lMMIFlag == 1)
            {
                width += numeric_keypad[i].x + ((numeric_keypad[i].width - width) / 2);
            }
			else
		    {
                width = numeric_keypad[i].x + ((numeric_keypad[i].width - width) / 2);
			}
            height = numeric_keypad[i].y + ((JUI_VIRTUAL_KEYPAD_KEY_HEIGHT - JUI_VIRTUAL_KEYPAD_KEY_BOTTOM_SHADOW_HEIGHT - height) / 2);
            if (numeric_keypad[i].key_code == KEY_1)
            {
                width -= JUI_VIRTUAL_KEYPAD_CHAR_1_OFFSET;
            }
            gui_move_text_cursor(width, height);
            gui_set_text_color(gui_color(0, 0, 0));
            gui_print_text((UI_string_type) GetString(numeric_keypad[i].content_str_id));
        }
    }

    jui_vk_key_down_index = index;
	
    gdi_layer_pop_and_restore_active();

    gdi_set_alpha_blending_source_layer(org_src_layer_handle);

    jui_vk_refresh_keypad();

#ifdef  __JUI_VK_SLIM__
    jui_is_vm_drawing_lcd = KAL_FALSE;
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jui_vk_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_init(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_INIT, display_id, jui_vk_display_id, jui_vk_current_type);

    if(display_id < 0)
    {
        return;
    }
    jui_vk_display_id = display_id;

#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
    if (jui_vk_display_id_last == jui_vk_display_id && jui_vk_current_type == JUI_VK_TYPE_NUMERIC)
    {
        jui_vk_draw_numeric_keypad();
    }
    else
#endif
    {
        jui_vk_draw_navigation_keypad();
    }

#ifdef SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT
    jui_vk_prepare_blt(display_id);
#endif /* SUPPORT_JUI_VIRTUAL_KEYPAD_ENHANCEMENT */
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_deinit(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_DEINIT, display_id, jui_vk_display_id, jui_vk_current_type);
     if(display_id < 0)
    {
        return;
    }
    
    if (display_id != jui_vk_display_id)
    {
        return;
    }

    jui_vk_display_id_last = jui_vk_display_id;
    jui_vk_display_id = INVALIDE_VM_ID;
    jui_vk_key_down_index = -1;
    jui_ui_device_height = 0;
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_clear(kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_CLEAR, display_id, jui_vk_display_id);
	
    if (display_id != jui_vk_display_id_last)
    {
        return;
    }

    jui_vk_display_id_last = -1;
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_get_display_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_vk_get_display_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    return jui_vk_display_id;
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_keypad_highlight_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_keypad_highlight_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_KEYPAD_HIGHLIGHT_CLEAR, jui_vk_key_down_index, jui_vk_current_type);
	
    if (jui_vk_key_down_index == -1)
    {
        return;
    }

    if (jui_vk_current_type == JUI_VK_TYPE_NAVIGATION)
    {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
        if (navigation_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
        {
            jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
        }
        jui_vk_draw_navigation_keypad();
        jui_vk_refresh_keypad();
    }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
    else if (jui_vk_current_type == JUI_VK_TYPE_NUMERIC)
    {
        if (numeric_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
        {
            jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
        }
        jui_vk_draw_numeric_keypad();
        jui_vk_refresh_keypad();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_pen_down_hdlr(kal_int16 x, kal_int16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/
	int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_PEN_DOWN_HDLR, jui_vk_key_down_index, jui_vk_current_type, x, y);
	
    if (jui_vk_current_type == JUI_VK_TYPE_NAVIGATION)
    {
        for (; i < JUI_VIRTUAL_KEYPAD_NAVIGATION_SIZE; i++)
        {
            if ((x >= navigation_keypad[i].x && x < navigation_keypad[i].x + navigation_keypad[i].width) &&
                (y >= navigation_keypad[i].y && y < navigation_keypad[i].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
            {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
                if (navigation_keypad[i].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
                {
                    jvm_keypad_insert(navigation_keypad[i].key_code, KEY_EVENT_DOWN);
                }
                if (i != jui_vk_key_down_index)
                {
                    jui_vk_draw_navigation_keypad_highlight(i);
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                }
                return;
            }
        }
        if (jui_vk_key_down_index != -1)
        {
            jui_vk_draw_navigation_keypad();
            jui_vk_refresh_keypad();
        }
    }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
    else if (jui_vk_current_type == JUI_VK_TYPE_NUMERIC)
    {
        for (; i < JUI_VIRTUAL_KEYPAD_NUMERIC_SIZE; i++)
        {
            if ((x >= numeric_keypad[i].x && x < numeric_keypad[i].x + numeric_keypad[i].width) &&
                (y >= numeric_keypad[i].y && y < numeric_keypad[i].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
            {
                if (numeric_keypad[i].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
                {
                    jvm_keypad_insert(numeric_keypad[i].key_code, KEY_EVENT_DOWN);
                }
                if (i != jui_vk_key_down_index)
                {
                    jui_vk_draw_numeric_keypad_highlight(i);
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                }
                return;
            }
        }
        if (jui_vk_key_down_index != -1)
        {
            jui_vk_draw_numeric_keypad();
            jui_vk_refresh_keypad();
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_pen_up_hdlr(kal_int16 x, kal_int16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_PEN_UP_HDLR, jui_vk_key_down_index, jui_vk_current_type, x, y);
	
    if (jui_vk_key_down_index == -1)
    {
        return;
    }
	
    if (jui_vk_current_type == JUI_VK_TYPE_NAVIGATION)
    {
        if ((x >= navigation_keypad[jui_vk_key_down_index].x && x < navigation_keypad[jui_vk_key_down_index].x + navigation_keypad[jui_vk_key_down_index].width) &&
            (y >= navigation_keypad[jui_vk_key_down_index].y && y < navigation_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
        {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
            if (navigation_keypad[jui_vk_key_down_index].key_code == JUI_VIRTUAL_KEYPAD_KEY_123)
            {
                jui_vk_draw_numeric_keypad();
                jui_vk_refresh_keypad();
            }
            else
#endif
            {
                jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
                jui_vk_draw_navigation_keypad();
                jui_vk_refresh_keypad();
            }
        }
        else
        {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
            if (navigation_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
            {
                jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_navigation_keypad();
            jui_vk_refresh_keypad();
        }
    }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
    else if (jui_vk_current_type == JUI_VK_TYPE_NUMERIC)
    {
        if ((x >= numeric_keypad[jui_vk_key_down_index].x && x < numeric_keypad[jui_vk_key_down_index].x + numeric_keypad[jui_vk_key_down_index].width) &&
            (y >= numeric_keypad[jui_vk_key_down_index].y && y < numeric_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
        {
            if (numeric_keypad[jui_vk_key_down_index].key_code == JUI_VIRTUAL_KEYPAD_KEY_NAVI)
            {
                jui_vk_draw_navigation_keypad();
                jui_vk_refresh_keypad();
            }
            else
            {
                jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
                jui_vk_draw_numeric_keypad();
                jui_vk_refresh_keypad();
            }
        }
        else
        {
            if (numeric_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
            {
                jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_numeric_keypad();
            jui_vk_refresh_keypad();
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_pen_repeat_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_pen_repeat_hdlr(kal_int16 x, kal_int16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_PEN_REPEAT_HDLR, jui_vk_key_down_index, jui_vk_current_type, x, y);
	
    if (jui_vk_key_down_index == -1)
    {
        return;
    }
	
    if (jui_vk_current_type == JUI_VK_TYPE_NAVIGATION)
    {
        if ((x >= navigation_keypad[jui_vk_key_down_index].x && x < navigation_keypad[jui_vk_key_down_index].x + navigation_keypad[jui_vk_key_down_index].width) &&
            (y >= navigation_keypad[jui_vk_key_down_index].y && y < navigation_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
        {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
            if (navigation_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
            {
                jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_REPEAT);
            }
        }
        else
        {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
            if (navigation_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
            {
                jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_navigation_keypad();
            jui_vk_refresh_keypad();
            jui_vk_pen_down_hdlr(x, y);
        }
    }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
    else if (jui_vk_current_type == JUI_VK_TYPE_NUMERIC)
    {
        if ((x >= numeric_keypad[jui_vk_key_down_index].x && x < numeric_keypad[jui_vk_key_down_index].x + numeric_keypad[jui_vk_key_down_index].width) &&
            (y >= numeric_keypad[jui_vk_key_down_index].y && y < numeric_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
        {
            if (numeric_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
            {
                jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_REPEAT);
            }
        }
        else
        {
            if (numeric_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
            {
                jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_numeric_keypad();
            jui_vk_refresh_keypad();
            jui_vk_pen_down_hdlr(x, y);
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_pen_long_tp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_pen_long_tp_hdlr(kal_int16 x, kal_int16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_PEN_LONG_TP_HDLR, jui_vk_key_down_index, jui_vk_current_type, x, y);
	
    if (jui_vk_key_down_index == -1)
    {
        return;
    }
	
    if (jui_vk_current_type == JUI_VK_TYPE_NAVIGATION)
    {
        if ((x >= navigation_keypad[jui_vk_key_down_index].x && x < navigation_keypad[jui_vk_key_down_index].x + navigation_keypad[jui_vk_key_down_index].width) &&
            (y >= navigation_keypad[jui_vk_key_down_index].y && y < navigation_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
        {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
            if (navigation_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
            {
                jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_LONG_PRESS);
            }
        }
        else
        {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
            if (navigation_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
            {
                jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_navigation_keypad();
            jui_vk_refresh_keypad();
            jui_vk_pen_down_hdlr(x, y);
        }
    }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
    else if (jui_vk_current_type == JUI_VK_TYPE_NUMERIC)
    {
        if ((x >= numeric_keypad[jui_vk_key_down_index].x && x < numeric_keypad[jui_vk_key_down_index].x + numeric_keypad[jui_vk_key_down_index].width) &&
            (y >= numeric_keypad[jui_vk_key_down_index].y && y < numeric_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT))
        {
            if (numeric_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
            {
                jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_LONG_PRESS);
            }
        }
        else
        {
            if (numeric_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
            {
                jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_numeric_keypad();
            jui_vk_refresh_keypad();
            jui_vk_pen_down_hdlr(x, y);
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jui_vk_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void jui_vk_pen_move_hdlr(kal_int16 x, kal_int16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												          */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body														    */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_VK_PEN_MOVE_HDLR, jui_vk_key_down_index, jui_vk_current_type, x, y);
	
    if (jui_vk_key_down_index == -1)
    {
        return;
    }
	
    if (jui_vk_current_type == JUI_VK_TYPE_NAVIGATION)
    {
        if (!((x >= navigation_keypad[jui_vk_key_down_index].x && x < navigation_keypad[jui_vk_key_down_index].x + navigation_keypad[jui_vk_key_down_index].width) &&
            (y >= navigation_keypad[jui_vk_key_down_index].y && y < navigation_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT)))
        {
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
            if (navigation_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_123)
#endif
            {
                jvm_keypad_insert(navigation_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_navigation_keypad();
            jui_vk_refresh_keypad();
            jui_vk_pen_down_hdlr(x, y);
        }
    }
#ifndef __SUPPORT_JAVA_COSMOS_REDUCE_VIRTUAL_KEYPAD__
    else if (jui_vk_current_type == JUI_VK_TYPE_NUMERIC)
    {
        if (!((x >= numeric_keypad[jui_vk_key_down_index].x && x < numeric_keypad[jui_vk_key_down_index].x + numeric_keypad[jui_vk_key_down_index].width) &&
            (y >= numeric_keypad[jui_vk_key_down_index].y && y < numeric_keypad[jui_vk_key_down_index].y + JUI_VIRTUAL_KEYPAD_KEY_HEIGHT)))
        {
            if (numeric_keypad[jui_vk_key_down_index].key_code != JUI_VIRTUAL_KEYPAD_KEY_NAVI)
            {
                jvm_keypad_insert(numeric_keypad[jui_vk_key_down_index].key_code, KEY_EVENT_UP);
            }
            jui_vk_draw_numeric_keypad();
            jui_vk_refresh_keypad();
            jui_vk_pen_down_hdlr(x, y);
        }
    }
#endif
}

#endif /* __SUPPORT_JAVA_VIRTUAL_KEYPAD__ */
#endif /* __J2ME__ */
