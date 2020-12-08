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
 *  vadp_v2p_widget_photo.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Venus APP ---> v2p adaptor ---> Pluto APP
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/ 
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
/* Pluto headers: */
#include "FileMgrSrvGProt.h"
#include "FileMgrGProt.h"
#include "fs_errcode.h"
#include "GpioSrvGprot.h"
#include "CommonScreens.h"
#include "drm_gprot.h"
#include "FileMgrCUIGProt.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif 
#include "med_utility.h"
/* Venus headers: */
#include "HomeScreen\vadp_v2p_widget_photo.h"
#include "HomeScreen\vadp_p2v_widget_photo.h"
#include "vapp_hs_res.h"
#include "HomeScreen\vapp_hs_def.h"
#include "vadp_v2p_widget_photo.h"
#include "vapp_hs_def.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"
#include "gdi_const.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_media_app_trc.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_venus_homescreen_wg_photo_def.h"
#include "FileMgrServiceResDef.h"
#if !defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_filemanager_def.h"
#else
#include "FileMgrResDef.h"
#endif

#include "lcd_sw_rnd.h"
#include "lcd_sw_inc.h"
#include "med_smalloc.h"
#include "CommonScreensResDef.h"
#include "string.h"
#include "gui.h"
#include "fs_type.h"
#include "wgui_categories_util.h"
#include "fs_func.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "FileMgrType.h"
#include "mmi_rp_file_type_def.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define VAPP_WIDGET_PHOTO_TRANSCODE_BUFFER_SIZE ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3)

#define VAPP_WIDGET_PHOTO_POPUP_AND_BACK        ((void*)NULL)
#define VAPP_WIDGET_PHOTO_POPUP_AND_SELECT      ((void*)1)

typedef struct
{
    WCHAR       filepath[SRV_FMGR_PATH_MAX_LEN + 1];
    WCHAR       transcode_img_path[VAPP_WIDGET_PHOTO_DEFAULT_FILEPATH_LENGTH + 1];
    gdi_handle  transcode_layer_h;
    gdi_handle  nb_decode_handle;
    PU8         transcode_layer_buf_p;
    MMI_BOOL    is_decoding;
    gdi_handle  amin_handle;
    MMI_ID      gid;
} vadp_v2p_widget_photo_context;

/****************************************************************************
 * Global variables:
 ****************************************************************************/
static vadp_v2p_widget_photo_context g_vapp_widget_photo_cntx;

/*****************************************************************************
* Local Function 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_decode_done_callback
 * DESCRIPTION
 *  decode done callback function called by gdi
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_photo_decode_done_callback(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id;
    S16 error = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vapp_widget_photo_cntx.is_decoding = MMI_FALSE;
    g_vapp_widget_photo_cntx.nb_decode_handle = NULL;
    
    if (result >= 0)
    {
        result = gdi_image_encode_layer_to_jpeg(
            g_vapp_widget_photo_cntx.transcode_layer_h, 
            (CHAR*)g_vapp_widget_photo_cntx.transcode_img_path);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_PHOTO_TRANSCODE, result);

        if (result >= 0)
        {
            WriteRecord(
                NVRAM_EF_VENUS_PHOTO_FILEPATH_LID, 
                1, 
                (void*)g_vapp_widget_photo_cntx.filepath, 
                NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE, 
                &error);

            mmi_frm_group_close(g_vapp_widget_photo_cntx.gid);
        }
        else
        {
            if (result == GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH ||
                result == GDI_IMAGE_ENCODER_ERR_DISK_FULL)
            {
                string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            }
            else if (result == GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION)
            {
                string_id = FMGR_FS_WRITE_PROTECTION_TEXT;
            }
        #if !defined(__MMI_SLIM_FILE_MANAGER__)
            else if (result == GDI_IMAGE_ENCODER_ERR_NO_DISK)
            {
                string_id = FMGR_FS_MSDC_NOT_PRESENT_TEXT;
            }
        #endif
            else if (result == GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL)
            {
                string_id = FMGR_FS_ROOT_DIR_FULL_TEXT;
            }
            else
            {
                string_id = STR_GLOBAL_ERROR;
            }
            
            mmi_popup_display_simple(
                (WCHAR*)GetString(string_id), 
                MMI_EVENT_FAILURE, 
                g_vapp_widget_photo_cntx.gid, 
                VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
        }
    }
    else
    {
        if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
        {
            string_id = STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE;
        }
        else if (result == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
        {
            string_id = STR_GLOBAL_INVALID_FORMAT;
        }
        else if (result == GDI_JPEG_ERR_DECODE_TIME_OUT)
        {
            string_id = STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE;
        }
        else if (result == GDI_IMAGE_ERR_INVALID_IMG_TYPE)
        {
            string_id = STR_GLOBAL_INVALID_FORMAT;
        }
        else if (result == GDI_IMAGE_ERR_UNSUPPORTED_FORMAT)
        {
            string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
        }
        else
        {
            string_id = STR_GLOBAL_INVALID_FORMAT;
        }
        
        ReadRecord(
            NVRAM_EF_VENUS_PHOTO_FILEPATH_LID, 
            1, (void*)g_vapp_widget_photo_cntx.filepath, 
            NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE, 
            &error); 

        mmi_popup_display_simple(
            (WCHAR*)GetString(string_id), 
            MMI_EVENT_FAILURE, 
            g_vapp_widget_photo_cntx.gid, 
            VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
    }

    med_free_ext_mem((void**)&g_vapp_widget_photo_cntx.transcode_layer_buf_p);
    g_vapp_widget_photo_cntx.transcode_layer_buf_p = NULL;

    if (g_vapp_widget_photo_cntx.transcode_layer_h)
    {
        gdi_layer_free(g_vapp_widget_photo_cntx.transcode_layer_h);
        g_vapp_widget_photo_cntx.transcode_layer_h = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_decode
 * DESCRIPTION
 *  Decode the selected image to a layer
 * PARAMETERS
 *  void
 * RETURNS
 *  result      decode result
 *****************************************************************************/
GDI_RESULT vadp_v2p_photo_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    S32 image_width = 0;
    S32 image_height = 0;   
    S32 resize_image_width = 0;
    S32 resize_image_height = 0;    
    S32 resize_image_offset_x = 0;
    S32 resize_image_offset_y = 0; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_nb_set_done_callback(vadp_v2p_photo_decode_done_callback);
    gdi_nb_set_blt(MMI_FALSE,MMI_FALSE);
    
    result = gdi_image_get_dimension_file(
                (CHAR*)g_vapp_widget_photo_cntx.filepath,
                &image_width,
                &image_height);

    if (result < 0)
    {
        return result;
    }

    gdi_util_fit_box(
        GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
        VAPP_WIDGET_PHOTO_MAX_WIDTH,
        VAPP_WIDGET_PHOTO_MAX_HEIGHT,
        image_width,
        image_height,
        &resize_image_offset_x,
        &resize_image_offset_y,
        &resize_image_width,
        &resize_image_height);

    gdi_layer_push_and_set_active(g_vapp_widget_photo_cntx.transcode_layer_h);
    gdi_layer_reset_clip();
    gdi_layer_resize(resize_image_width, resize_image_height);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_push_and_set_alpha_blending_source_layer(g_vapp_widget_photo_cntx.transcode_layer_h);

    g_vapp_widget_photo_cntx.nb_decode_handle = gdi_image_nb_draw_resized_file(
                                                    0, 
                                                    0, 
                                                    resize_image_width, 
                                                    resize_image_height, 
                                                    g_vapp_widget_photo_cntx.filepath);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_PHOTO_DECODE, result);
    
    return result;
}

    
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_widget_photo_transcode
 * DESCRIPTION
 *  Transcode the image to the jpeg type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_widget_photo_transcode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    MMI_ID_TYPE string_id;
    S16 error = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vapp_widget_photo_cntx.transcode_layer_buf_p = NULL;
    g_vapp_widget_photo_cntx.transcode_layer_h = NULL;

    g_vapp_widget_photo_cntx.transcode_layer_buf_p = (PU8)med_alloc_ext_mem_framebuffer(VAPP_WIDGET_PHOTO_TRANSCODE_BUFFER_SIZE);

    if (g_vapp_widget_photo_cntx.transcode_layer_buf_p == NULL)
    {
        string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;

        mmi_popup_display_simple(
            (WCHAR*)GetString(string_id), 
            MMI_EVENT_FAILURE, 
            g_vapp_widget_photo_cntx.gid, 
            VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
        
        return;
    }

    gdi_layer_create_using_outside_memory(
        0,
        0,
        VAPP_WIDGET_PHOTO_MAX_WIDTH,
        VAPP_WIDGET_PHOTO_MAX_HEIGHT,
        &g_vapp_widget_photo_cntx.transcode_layer_h,
        (PU8) g_vapp_widget_photo_cntx.transcode_layer_buf_p,
        VAPP_WIDGET_PHOTO_TRANSCODE_BUFFER_SIZE);

    result = vadp_v2p_photo_decode();
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_PHOTO_DECODE, result);
    
    if (result < 0)
    {
        ReadRecord(
            NVRAM_EF_VENUS_PHOTO_FILEPATH_LID, 
            1, (void*)g_vapp_widget_photo_cntx.filepath, 
            NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE, 
            &error);
        
        med_free_ext_mem((void**)&g_vapp_widget_photo_cntx.transcode_layer_buf_p);
        g_vapp_widget_photo_cntx.transcode_layer_buf_p = NULL;

        if (g_vapp_widget_photo_cntx.transcode_layer_h)
        {
            gdi_layer_free(g_vapp_widget_photo_cntx.transcode_layer_h);
            g_vapp_widget_photo_cntx.transcode_layer_h = NULL;
        }
    
        if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
        {
            string_id = STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE;
        }
        else if (result == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
        {
            string_id = STR_GLOBAL_INVALID_FORMAT;
        }
        else if (result == GDI_JPEG_ERR_DECODE_TIME_OUT)
        {
            string_id = STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE;
        }
        else if (result == GDI_IMAGE_ERR_INVALID_IMG_TYPE)
        {
            string_id = STR_GLOBAL_INVALID_FORMAT;
        }
        else if (result == GDI_IMAGE_ERR_UNSUPPORTED_FORMAT)
        {
            string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
        }
        else
        {
            string_id = STR_GLOBAL_INVALID_FORMAT;
        }

        mmi_popup_display_simple(
            (WCHAR*)GetString(string_id), 
            MMI_EVENT_FAILURE, 
            g_vapp_widget_photo_cntx.gid, 
            VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
    }
    else
    {
        g_vapp_widget_photo_cntx.is_decoding = MMI_TRUE;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_start_draw_processing_img
 * DESCRIPTION
 *  Draw the processing animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_photo_start_draw_processing_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle  base_layer_handle;
    S32 width = 0;
    S32 height = 0;
    S32 resized_image_offset_x = 0;
    S32 resized_image_offset_y = 0; 
    S32 resized_image_width = 0;
    S32 resized_image_height =0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() != VAPP_HS_SCR_PHOTO_PROCESSING)
    {
        return;
    }

    gdi_layer_get_base_handle(&base_layer_handle);

    gdi_image_get_dimension_id(VAPP_HS_IMG_WG_PHOTO_PROCESS, &width, &height);

    gdi_util_fit_box(
        GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
        LCD_WIDTH,
        LCD_HEIGHT,
        width,
        height,
        &resized_image_offset_x,
        &resized_image_offset_y,
        &resized_image_width,
        &resized_image_height);
    
    gdi_layer_push_and_set_active(base_layer_handle);
    gdi_layer_reset_clip();
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_set_opacity(FALSE, 255);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_anim_draw_id(resized_image_offset_x, resized_image_offset_y, VAPP_HS_IMG_WG_PHOTO_PROCESS, &g_vapp_widget_photo_cntx.amin_handle);            

    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(base_layer_handle, 0, 0, 0);
    gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
   
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_stop_draw_processing_img
 * DESCRIPTION
 *  Stop the processing animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_photo_stop_draw_processing_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vapp_widget_photo_cntx.amin_handle != NULL)
    {
        gdi_image_stop_animation(g_vapp_widget_photo_cntx.amin_handle);
        g_vapp_widget_photo_cntx.amin_handle = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_proc
 * DESCRIPTION
 *  proc function
 * PARAMETERS
 *  event   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret vadp_v2p_photo_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            mmi_event_popoupcallback_result_struct *popup = (mmi_event_popoupcallback_result_struct*)evt;

            if (VAPP_WIDGET_PHOTO_POPUP_AND_SELECT == popup->user_tag)
            {
                /* To make sure the fmgr file seletor screen will be shown */
                mmi_frm_scrn_close(g_vapp_widget_photo_cntx.gid, VAPP_HS_SCR_PHOTO_PROCESSING);
            }
            else
            {
                mmi_frm_group_close(g_vapp_widget_photo_cntx.gid);
            }

            break;
        }

        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_result = (cui_file_selector_result_event_struct*)evt;

            if (sel_result->result == 0)
            {
                mmi_frm_group_close(g_vapp_widget_photo_cntx.gid);
            }
            else if (sel_result->result < 0)
            {
            #ifdef __USB_IN_NORMAL_MODE__
                if (!srv_usb_is_in_mass_storage_mode())
            #endif        
                {
                    mmi_popup_display_simple(
                        (WCHAR*)GetString(srv_fmgr_fs_error_get_string(sel_result->result)), 
                        MMI_EVENT_FAILURE, 
                        g_vapp_widget_photo_cntx.gid, 
                        VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
                }
            }
            else
            {
                cui_file_selector_get_selected_filepath(
                    sel_result->sender_id,
                    &file_info, 
                    (WCHAR*)g_vapp_widget_photo_cntx.filepath, 
                    SRV_FMGR_PATH_BUFFER_SIZE);
                
                vadp_v2p_photo_processing();
            }

            break;
        }
        
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_exit_processing_scr
 * DESCRIPTION
 *  Exit photo processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_photo_exit_processing_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle  base_layer_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(vadp_v2p_widget_photo_transcode);
    
    gdi_layer_get_base_handle(&base_layer_handle);
    
    gdi_layer_push_and_set_active(base_layer_handle);
    gdi_layer_reset_clip();
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_set_opacity(FALSE, 255);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    vadp_v2p_photo_stop_draw_processing_img();

    if (g_vapp_widget_photo_cntx.is_decoding)
    {
        gdi_image_nb_stop(g_vapp_widget_photo_cntx.nb_decode_handle);
        g_vapp_widget_photo_cntx.is_decoding = MMI_FALSE;
        g_vapp_widget_photo_cntx.nb_decode_handle = NULL;

        med_free_ext_mem((void**)&g_vapp_widget_photo_cntx.transcode_layer_buf_p);
        g_vapp_widget_photo_cntx.transcode_layer_buf_p = NULL;

        if (g_vapp_widget_photo_cntx.transcode_layer_h)
        {
            gdi_layer_free(g_vapp_widget_photo_cntx.transcode_layer_h);
            g_vapp_widget_photo_cntx.transcode_layer_h = NULL;
        }
    }        
    srv_backlight_turn_off();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_entry_processing_scr
 * DESCRIPTION
 *  Entry photo processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_photo_entry_processing_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR       buf_filepath[SRV_FMGR_PATH_MAX_LEN + 1];
    S32         fs_ret = FS_NO_ERROR;
    FS_HANDLE   file_handle;
    GDI_RESULT  result;
    S32         image_width = 0;
    S32         image_height = 0;
    S16         error = 0;
    U16         str_id = VFX_RES_ID_NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            g_vapp_widget_photo_cntx.gid, 
            VAPP_HS_SCR_PHOTO_PROCESSING, 
            vadp_v2p_photo_exit_processing_scr,
            vadp_v2p_photo_entry_processing_scr, 
            MMI_FRM_FULL_SCRN) == 
            MMI_FALSE)
    {
        return;
    }
    entry_full_screen();

    /* stop MMI sleep */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    result = gdi_image_get_dimension_file(
                (CHAR*)g_vapp_widget_photo_cntx.filepath,
                &image_width,
                &image_height);

    if (result >= 0 && 
        (image_width < VAPP_WIDGET_PHOTO_MIN_WIDTH && 
         image_height < VAPP_WIDGET_PHOTO_MIN_HEIGHT))
    {
        str_id = VAPP_HS_STR_PHOTO_IMG_SMALL;
    }
    else
    {
        S32 resize_image_width = 0;
        S32 resize_image_height = 0;
        S32 resize_image_offset_x = 0;
        S32 resize_image_offset_y = 0;

        gdi_util_fit_box(
            GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
            VAPP_WIDGET_PHOTO_MAX_WIDTH,
            VAPP_WIDGET_PHOTO_MAX_HEIGHT,
            image_width,
            image_height,
            &resize_image_offset_x,
            &resize_image_offset_y,
            &resize_image_width,
            &resize_image_height);

        if (resize_image_width < VAPP_WIDGET_PHOTO_MIN_WIDTH ||
            resize_image_height < VAPP_WIDGET_PHOTO_MIN_WIDTH)
        {
            str_id = VAPP_HS_STR_PHOTO_IMG_RATIO_IMPROPER;
        }

    }

    if (VFX_RES_ID_NULL != str_id)
    {
        ReadRecord(
            NVRAM_EF_VENUS_PHOTO_FILEPATH_LID, 
            1, (void*)g_vapp_widget_photo_cntx.filepath, 
            NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE, 
            &error);

        mmi_popup_display_simple(
            (WCHAR*)GetString(str_id),
            MMI_EVENT_FAILURE, 
            g_vapp_widget_photo_cntx.gid, 
            VAPP_WIDGET_PHOTO_POPUP_AND_SELECT);
                
        return;
    }
    
    vadp_v2p_photo_start_draw_processing_img();

    kal_wsprintf(buf_filepath, "%c:\\%w\\", VAPP_WIDGET_PHOTO_DEFAULT_DRV, VAPP_WIDGET_PHOTO_DEFAULT_FOLDER);
    file_handle = FS_Open(buf_filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    else
    {
        /* create directory if it is not there */
        fs_ret = FS_CreateDir(buf_filepath);

        if (fs_ret < 0)
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(srv_fmgr_fs_error_get_string(fs_ret)), 
                MMI_EVENT_FAILURE, 
                g_vapp_widget_photo_cntx.gid, 
                VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
        
            return;
        }
    }
    
    gui_start_timer(100, vadp_v2p_widget_photo_transcode);  
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_processing
 * DESCRIPTION
 *  Start photo frame processing
 * PARAMETERS
 *  path        [IN]        image path
 *  isShort    [IN]        file name is short or not
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_photo_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     ret;
    S32     is_prohibited = 0;
    S16     error = 0;
    CHAR    *error_str_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vadp_v2p_photo_is_original_file_exist(&is_prohibited);

    if (ret <= 0)
    {
        ReadRecord(
            NVRAM_EF_VENUS_PHOTO_FILEPATH_LID, 
            1, (void*)g_vapp_widget_photo_cntx.filepath, 
            NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE, 
            &error);
        
        if (is_prohibited)
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(STR_GLOBAL_DRM_PROHIBITED), 
                MMI_EVENT_FAILURE, 
                g_vapp_widget_photo_cntx.gid, 
                VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
        }
        else if (ret < FS_NO_ERROR)
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(srv_fmgr_fs_error_get_string(ret)), 
                MMI_EVENT_FAILURE, 
                g_vapp_widget_photo_cntx.gid, 
                VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
        }
        else
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(STR_GLOBAL_ERROR), 
                MMI_EVENT_FAILURE, 
                g_vapp_widget_photo_cntx.gid, 
                VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
        }
        return;
    }
    else
    {
        if (!mmi_fmgr_util_file_limit_check(
                FMGR_LIMIT_IMAGE_VIEWER, 
                (CHAR*)g_vapp_widget_photo_cntx.filepath,
                &error_str_ptr))
        {
            mmi_popup_display_simple(
                (WCHAR*)error_str_ptr, 
                MMI_EVENT_FAILURE, 
                g_vapp_widget_photo_cntx.gid, 
                VAPP_WIDGET_PHOTO_POPUP_AND_BACK);

            return;
        }
    }
        
    vadp_v2p_photo_entry_processing_scr();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_launch_filemanager
 * DESCRIPTION
 *  Call file manager browser to select a file 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_photo_launch_filemanager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    MMI_ID      selector_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET_IMAGE(&filter);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
        
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

    if ((g_vapp_widget_photo_cntx.gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vadp_v2p_photo_proc, NULL)) == GRP_ID_INVALID)
        return;

    mmi_frm_group_enter(g_vapp_widget_photo_cntx.gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    selector_id = cui_file_selector_create(
                    g_vapp_widget_photo_cntx.gid,
                    (const WCHAR*) L"root",
                    &filter,
                    CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                    CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);

    if(!selector_id)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_ERROR), 
            MMI_EVENT_FAILURE, 
            g_vapp_widget_photo_cntx.gid, 
            VAPP_WIDGET_PHOTO_POPUP_AND_BACK);
            
        return;
    }

    cui_file_selector_run(selector_id);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_is_cache_file_exist
 * DESCRIPTION
 *  Check if the cache photo exists or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE        exist
 *  FALSE       doesn't exist
 *****************************************************************************/
S32 vadp_v2p_photo_is_cache_file_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_GetAttributes((U16*) g_vapp_widget_photo_cntx.transcode_img_path);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_PHOTO_CACHE_CHECK_RESULT, file_handle);
    
    if (file_handle >= 0)
    {
        /* file exist */
        return TRUE;
    }
    else
    {
        /* file not exist */     
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_is_original_file_exist
 * DESCRIPTION
 *  Check if the original photo exists or not.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  TRUE        exist
 *  FALSE       doesn't exist
 *****************************************************************************/
S32 vadp_v2p_photo_is_original_file_exist(S32* is_prohibited_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 ret = TRUE;
#ifdef __DRM_SUPPORT__
    drm_method_enum method;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *is_prohibited_ptr = FALSE;
    
    file_handle = DRM_open_file((PU16)g_vapp_widget_photo_cntx.filepath, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
    if (file_handle >= FS_NO_ERROR)
    {
        /* file exist */
    #ifdef __DRM_SUPPORT__
        method = (drm_method_enum)DRM_get_object_method(file_handle, NULL);
        if (method == DRM_METHOD_FORWARD_LOCK)
        { 
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_PHOTO_DRM_FILE);
            ret = TRUE;
        }
        else if (method == DRM_METHOD_NONE)
        {
            ret = TRUE;
        }
        else
        {
            *is_prohibited_ptr = TRUE;
            ret = FALSE;
        }
    #endif /* __DRM_SUPPORT__ */
        DRM_close_file(file_handle);       
    }
    else
    {
        /* file not exist */     
        ret = file_handle;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_PHOTO_FILE_CHECK_RESULT, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_get_transcode_image_path
 * DESCRIPTION
 *  Get the photo path
 * PARAMETERS
 *  void
 * RETURNS
 *  file path
 *****************************************************************************/
WCHAR* vadp_v2p_photo_get_transcode_image_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == g_vapp_widget_photo_cntx.transcode_img_path[0])
    {
        kal_wsprintf(
            g_vapp_widget_photo_cntx.transcode_img_path,
            "%c:\\%w\\%w",
            VAPP_WIDGET_PHOTO_DEFAULT_DRV,
            VAPP_WIDGET_PHOTO_DEFAULT_FOLDER,
            VAPP_WIDGET_PHOTO_DEFAULT_FILENAME);
    }
    return g_vapp_widget_photo_cntx.transcode_img_path;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_photo_get_original_image_path
 * DESCRIPTION
 *  Get the photo path
 * PARAMETERS
 *  void
 * RETURNS
 *  file path
 *****************************************************************************/
WCHAR* vadp_v2p_photo_get_original_image_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == g_vapp_widget_photo_cntx.filepath[0])
    {
        ReadRecord(
            NVRAM_EF_VENUS_PHOTO_FILEPATH_LID, 
            1, (void*)g_vapp_widget_photo_cntx.filepath, 
            NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE, 
            &error);
    }
    return g_vapp_widget_photo_cntx.filepath;
}

#endif /* __MMI_VUI_HOMESCREEN_PHOTO__ */
