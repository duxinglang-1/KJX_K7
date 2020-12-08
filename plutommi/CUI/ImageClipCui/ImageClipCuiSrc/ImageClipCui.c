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
 *  ImageClipCui.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Clip Cui main file
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_IMAGE_CLIP_CUI__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "MMI_media_app_trc.h"
#include "Filemgrsrvgprot.h"
#include "wgui_include.h"
#include "GlobalResDef.h"
#include "mmi_rp_cui_image_clip_def.h"
#include "ImageClipCui.h"
#include "ImageClipCuiOSD.h"
#include "ImageClipCuiGprot.h"
#include "gui_font_size.h"
#include "gdi_primitive.h"

static cui_image_clip_context_struct *g_imgclp = NULL;

static void cui_image_clip_LSK_down(void);
static void cui_image_clip_LSK_up(void);
static void cui_image_clip_RSK_down(void);
static void cui_image_clip_RSK_up(void);
static void cui_image_clip_draw_soft_key(void);
static void cui_image_clip_back_to_edit(void);

#define _IMAGE_CLIP_LAYERS
/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_layers_mem
* DESCRIPTION
*  create and clear layers
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_layers_mem(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_create_cf_using_outside_memory(IMAGE_CLIP_CURRENT_COLOR_FORMAT,
                                             0,
                                             0,
                                             GDI_LCD_WIDTH,
                                             GDI_LCD_HEIGHT,
                                             &g_imgclp->decode_layer,
                                             g_imgclp->decode_layer_buf_ptr,
                                             IMAGE_CLIP_DECODE_LAYER_MEM_SIZE);

    gdi_layer_push_and_set_active(g_imgclp->decode_layer);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_layers_active
* DESCRIPTION
*  create and clear status and soft key layers
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_layers_active(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 width, height;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_create_cf(IMAGE_CLIP_CURRENT_COLOR_FORMAT,
                        0,
                        0, //MMI_STATUS_BAR_HEIGHT,
                        GDI_LCD_WIDTH,
                        GDI_LCD_HEIGHT,// - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT,
                        &g_imgclp->clip_layer);

    gdi_layer_push_and_set_active(g_imgclp->clip_layer);
    gdi_layer_clear(gdi_act_color_from_rgb(255, g_clip_skin_struct.clip_bg_color.color_r, g_clip_skin_struct.clip_bg_color.color_g, g_clip_skin_struct.clip_bg_color.color_b));
    gdi_layer_pop_and_restore_active();

    gdi_layer_create_cf_using_outside_memory(IMAGE_CLIP_CURRENT_COLOR_FORMAT,
                                             0,
                                             0,
                                             GDI_LCD_WIDTH,
                                             MMI_STATUS_BAR_HEIGHT,
                                             &g_imgclp->status_bar_layer,
                                             g_imgclp->fg_buf_ptr,
                                             IMAGE_CLIP_STATUS_BAR_LAYER_MEM_SIZE);

    gdi_layer_push_and_set_active(g_imgclp->status_bar_layer);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_create_cf_using_outside_memory(IMAGE_CLIP_CURRENT_COLOR_FORMAT,
                                             0,
                                             GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT,
                                             GDI_LCD_WIDTH,
                                             MMI_SOFTKEY_BAR_HEIGHT,
                                             &g_imgclp->soft_key_layer,
                                             g_imgclp->fg_buf_ptr + IMAGE_CLIP_STATUS_BAR_LAYER_MEM_SIZE,
                                             IMAGE_CLIP_SOFT_KEY_BAR_LAYER_MEM_SIZE);
    gdi_layer_push_and_set_active(g_imgclp->soft_key_layer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    #ifdef __MMI_FTE_SUPPORT__
         gdi_layer_create_cf_using_outside_memory(IMAGE_CLIP_CURRENT_COLOR_FORMAT,
                                                 g_clip_skin_struct.anim_bg.x,
                                                 g_clip_skin_struct.anim_bg.y,
                                                 g_clip_skin_struct.anim_bg.w,
                                                 g_clip_skin_struct.anim_bg.h,
                                                 &g_imgclp->anim_layer,
                                                 g_imgclp->fg_buf_ptr + IMAGE_CLIP_STATUS_BAR_LAYER_MEM_SIZE + IMAGE_CLIP_SOFT_KEY_BAR_LAYER_MEM_SIZE,
                                                 gdi_sizeof_pixels(IMAGE_CLIP_CURRENT_COLOR_FORMAT,g_clip_skin_struct.anim_bg.w, g_clip_skin_struct.anim_bg.h));
    #else
        gdi_image_get_dimension_id(IMG_ID_IMAGE_CLIP_BUSY_ANIM, &width, &height);
        g_clip_skin_struct.anim.x = (GDI_LCD_WIDTH - width) / 2;
        
        gdi_layer_create_cf_using_outside_memory(IMAGE_CLIP_CURRENT_COLOR_FORMAT,
                                                 g_clip_skin_struct.anim.x,
                                                 g_clip_skin_struct.anim.y,
                                                 width,
                                                 height,
                                                 &g_imgclp->anim_layer,
                                                 g_imgclp->fg_buf_ptr + IMAGE_CLIP_STATUS_BAR_LAYER_MEM_SIZE + IMAGE_CLIP_SOFT_KEY_BAR_LAYER_MEM_SIZE,
                                                 gdi_sizeof_pixels(IMAGE_CLIP_CURRENT_COLOR_FORMAT,width, height));
    #endif
    
    gdi_layer_push_and_set_active(g_imgclp->anim_layer);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_imgclp->clip_layer,
                            g_imgclp->status_bar_layer,
                            g_imgclp->soft_key_layer,
                            0);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_save_layer
* DESCRIPTION
*  create and clear save layer with white color
* PARAMETERS
*  width     :  [IN]save layer width
*  height    :  [IN]save layer height
*  save_layer_buf_size  :  [IN]used save buf size
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_save_layer(S32 width, S32 height, S32 save_buf_size)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->real_save_size.width = width;
    g_imgclp->real_save_size.height = height;

    gdi_layer_create_cf_using_outside_memory(IMAGE_CLIP_CURRENT_COLOR_FORMAT,
                                             0,
                                             0,
                                             width,
                                             height,
                                             &g_imgclp->save_layer,
                                             g_imgclp->save_layer_buf_ptr,
                                             save_buf_size);

    gdi_layer_push_and_set_active(g_imgclp->save_layer);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_free_layers
* DESCRIPTION
*  free layers that created from asm
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_free_layers_mem(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_free(g_imgclp->decode_layer);
    g_imgclp->decode_layer = GDI_NULL_HANDLE;
    
    if(g_imgclp->save_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_imgclp->save_layer);
        g_imgclp->save_layer = GDI_NULL_HANDLE;
    }

}


#define _IMAGE_CLIP_MEMORY
/*****************************************************************************
* FUNCTION
*  cui_image_clip_prepare_mem
* DESCRIPTION
*  apply asm for cui
* PARAMETERS
*  cui_gid    :  [IN]use group id to apply
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_prepare_mem(mmi_id cui_gid)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_PREPARE_MEM, __LINE__);

    if(NULL == g_imgclp)
    {
        g_imgclp = (cui_image_clip_context_struct *)mmi_frm_asm_alloc_nc_r(cui_gid, IMAGE_CLIP_MEM_SIZE);

        MMI_ASSERT(g_imgclp != NULL);
    }

    memset(g_imgclp, 0, sizeof(cui_image_clip_context_struct));

    g_imgclp->cui_mem_ptr = (CHAR*)g_imgclp + sizeof(cui_image_clip_context_struct);

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_alloc_mem
* DESCRIPTION
*  alloc memory for layers and struct
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_alloc_mem(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_ALLOC_MEM, __LINE__);

    g_imgclp->decode_layer_buf_ptr = (U8 *)g_imgclp->cui_mem_ptr;

    g_imgclp->source_file = (WCHAR *)((U8 *)g_imgclp->cui_mem_ptr + IMAGE_CLIP_DECODE_LAYER_MEM_SIZE);

    g_imgclp->dest_file = (WCHAR *)((U8 *)g_imgclp->cui_mem_ptr + 
                                    IMAGE_CLIP_DECODE_LAYER_MEM_SIZE + CUI_IMAGE_CLIP_FULL_FILE_PATH_LEN);

    *(g_imgclp->dest_file) = 0;
    
    g_imgclp->save_layer_buf_ptr = (U8 *)g_imgclp->cui_mem_ptr + 
                                    IMAGE_CLIP_DECODE_LAYER_MEM_SIZE + CUI_IMAGE_CLIP_FULL_FILE_PATH_LEN * 2;

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_get_layer_buf_active
* DESCRIPTION
*  apply layer buf when screen is active
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_get_layer_buf_active(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->fg_buf_ptr = mmi_frm_asm_alloc_nc_r(g_imgclp->cui_gid, IMAGE_CLIP_DECODE_LAYER_MEM_SIZE);

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_free_layer_buf_inactive
* DESCRIPTION
*  free layer buf when screen is inactive
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_free_layer_buf_inactive(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_SCRN_INACTIVE, __LINE__);
    switch(g_imgclp->clip_state)
    {
        case IMGCLP_STATE_LOAD:
        case IMGCLP_STATE_SAVE:
            gdi_layer_flatten_to_base(g_imgclp->clip_layer, g_imgclp->anim_layer, g_imgclp->status_bar_layer, g_imgclp->soft_key_layer);
            break;
        case IMGCLP_STATE_EDIT:
            gdi_layer_flatten_to_base(g_imgclp->clip_layer, g_imgclp->status_bar_layer, g_imgclp->soft_key_layer, 0);
            break;
        case IMGCLP_STATE_PREVIEW:
            gdi_layer_flatten_to_base(g_imgclp->clip_layer, g_imgclp->save_layer, g_imgclp->status_bar_layer, g_imgclp->soft_key_layer);
            break;
        default:
            break;
    }

    if(GDI_NULL_HANDLE != g_imgclp->clip_layer)
    {
        gdi_layer_free(g_imgclp->clip_layer);
        g_imgclp->clip_layer = GDI_NULL_HANDLE;
    }

    if(GDI_NULL_HANDLE != g_imgclp->status_bar_layer)
    {
        gdi_layer_free(g_imgclp->status_bar_layer);
        g_imgclp->status_bar_layer = GDI_NULL_HANDLE;
    }

    if(GDI_NULL_HANDLE != g_imgclp->soft_key_layer)
    {
        gdi_layer_free(g_imgclp->soft_key_layer);
        g_imgclp->soft_key_layer = GDI_NULL_HANDLE;
    }

    if(GDI_NULL_HANDLE != g_imgclp->anim_layer)
    {
        gdi_layer_free(g_imgclp->anim_layer);
        g_imgclp->anim_layer = GDI_NULL_HANDLE;
    }
    
    if (g_imgclp->fg_buf_ptr!= NULL)
    {
        /* free app-based memory */
        mmi_frm_asm_free_r(g_imgclp->cui_gid, (void *)g_imgclp->fg_buf_ptr);
        g_imgclp->fg_buf_ptr = NULL;
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_free_mem
* DESCRIPTION
*  free asm
* PARAMETERS
*  void
* RETURNS
*  BOOL
*****************************************************************************/
static MMI_BOOL cui_image_clip_free_mem(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    mmi_id cui_gid;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_FREE_MEM, __LINE__);

    cui_gid = g_imgclp->cui_gid;

    if (g_imgclp != NULL)
    {
        /* free app-based memory */
        mmi_frm_asm_free_r(cui_gid, (void *)g_imgclp);
        g_imgclp = NULL;
    }

    return MMI_TRUE;
}

#define _IMAGE_CLIP_DRAW_ANIMATION

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_animation_start
* DESCRIPTION
*  start to draw animation for busy state
* PARAMETERS
*  is_loading    :   [IN] show loading animation or other
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_animation_start(MMI_BOOL is_loading)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 width, height;
    UI_string_type print_str;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_DRAW_ANIM, __LINE__);

    if(g_imgclp->anim_handle == GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(g_imgclp->anim_layer);
        gdi_push_and_set_alpha_blending_source_layer(g_imgclp->clip_layer);

    #ifdef __MMI_FTE_SUPPORT__
        gdi_image_draw_resized_id(0,
                                  0,
                                  g_clip_skin_struct.anim_bg.w,
                                  g_clip_skin_struct.anim_bg.h,
                                  IMG_ID_IMAGE_CLIP_BUSY_ANIM_BG);

        if(MMI_TRUE == is_loading)
        {
            print_str = (UI_string_type)GetString(STR_GLOBAL_LOADING);
        }
        else
        {
            print_str = (UI_string_type)GetString(STR_GLOBAL_PLEASE_WAIT);
        }

        gui_measure_string(print_str, &width, &height);
        g_clip_skin_struct.anim_str.x = (GDI_LCD_WIDTH - width) / 2 - g_clip_skin_struct.anim_bg.x;
        g_clip_skin_struct.anim_str.y = 10;
        gui_move_text_cursor(g_clip_skin_struct.anim_str.x, g_clip_skin_struct.anim_str.y);
        gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));
        gui_set_text_color(gui_color(g_clip_skin_struct.anim_str_color.color_r, g_clip_skin_struct.anim_str_color.color_g, g_clip_skin_struct.anim_str_color.color_b));
        
        gui_print_text(print_str);

		gdi_image_draw_animation_id(g_clip_skin_struct.anim.x - g_clip_skin_struct.anim_bg.x,
                                    g_clip_skin_struct.anim.y - g_clip_skin_struct.anim_bg.y,
                                    IMG_ID_IMAGE_CLIP_BUSY_ANIM,
                                    &g_imgclp->anim_handle);
    #else
		gdi_image_draw_animation_id(0,
                                    0,
                                    IMG_ID_IMAGE_CLIP_BUSY_ANIM,
                                    &g_imgclp->anim_handle);

    #endif /* __MMI_FTE_SUPPORT__ */


        gdi_pop_and_restore_alpha_blending_source_layer();
        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(g_imgclp->clip_layer,
                                g_imgclp->anim_layer,
                                g_imgclp->status_bar_layer,
                                g_imgclp->soft_key_layer
                                );

    #ifdef __MMI_FTE_SUPPORT__
        gdi_layer_blt_previous(g_clip_skin_struct.anim_bg.x,
                               g_clip_skin_struct.anim_bg.y,
                               g_clip_skin_struct.anim_bg.x+g_clip_skin_struct.anim_bg.w,
                               g_clip_skin_struct.anim_bg.y+g_clip_skin_struct.anim_bg.h);
    #else /* __MMI_FTE_SUPPORT__ */
        gdi_layer_blt_previous(0,
                               0,
                               GDI_LCD_WIDTH - 1,
                               GDI_LCD_HEIGHT - 1);
    #endif /* __MMI_FTE_SUPPORT__ */
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_animation_stop
* DESCRIPTION
*  stop to draw animation for busy state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_animation_stop(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_STOP_ANIM, __LINE__);

    gdi_layer_set_blt_layer(g_imgclp->clip_layer,
                            g_imgclp->status_bar_layer,
                            g_imgclp->soft_key_layer,
                            0
                            );
    
    if(g_imgclp->anim_handle != GDI_NULL_HANDLE)
    {
        gdi_image_stop_animation(g_imgclp->anim_handle);
        g_imgclp->anim_handle = GDI_NULL_HANDLE;
    }
}

#define _IMAGE_CLIP_FRAME_AND_BALL_UPDATE

/*****************************************************************************
* FUNCTION
*  cui_image_clip_get_len_from_ratio
* DESCRIPTION
*  get length from ratio
* PARAMETERS
*  w           :   [IN] first edge length
*  w_ratio   :   [IN] first edge ratio
*  h_ratio    :   [IN] second edge ratio
* RETURNS
*  h            :   second edge lengh
*****************************************************************************/
static U16 cui_image_clip_get_len_from_ratio(U16 w, U16 w_ratio, U16 h_ratio)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    U32 result;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    result = w * h_ratio * 100 / w_ratio;

    return (U16)(result/100);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_get_frame_wh_from_percent
* DESCRIPTION
*  get frame width and height from percent
* PARAMETERS
*  percent    :   [IN] frame percent vs LCD
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_get_frame_wh_from_percent(U16 percent)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(MMI_TRUE == g_imgclp->is_align_to_w)
    {
        if(g_imgclp->frame_percent == g_imgclp->max_percent)
        {
            g_imgclp->btn_frame.rect.w = g_imgclp->img_rect.w;
        }
        else
        {
            g_imgclp->btn_frame.rect.w = (U16)(GDI_LCD_WIDTH * percent / 100);
        }
        
        g_imgclp->btn_frame.rect.h = (U16)cui_image_clip_get_len_from_ratio(g_imgclp->btn_frame.rect.w,
                                                                            g_imgclp->w_ratio,
                                                                            g_imgclp->h_ratio
                                                                            );
    }
    else
    {
        if(g_imgclp->frame_percent == g_imgclp->max_percent)
        {
            g_imgclp->btn_frame.rect.h = g_imgclp->img_rect.h;
        }
        else
        {
            g_imgclp->btn_frame.rect.h = (U16)(GDI_LCD_HEIGHT * percent / 100);
        }
        
        g_imgclp->btn_frame.rect.w = (U16)cui_image_clip_get_len_from_ratio(g_imgclp->btn_frame.rect.h,
                                                                            g_imgclp->h_ratio,
                                                                            g_imgclp->w_ratio
                                                                            );
    }

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_get_last_frame
* DESCRIPTION
*  hold the frame position
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_get_last_frame(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->last_frame.x = g_imgclp->btn_frame.rect.x;
    g_imgclp->last_frame.y = g_imgclp->btn_frame.rect.y;
    g_imgclp->last_frame.w = g_imgclp->btn_frame.rect.w;
    g_imgclp->last_frame.h = g_imgclp->btn_frame.rect.h;
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_frame_info
* DESCRIPTION
*  init frame position and percent
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_frame_info(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    U32 min_w, min_h;
    U16 w_ratio = g_imgclp->w_ratio;
    U16 h_ratio = g_imgclp->h_ratio;
    cui_image_clip_rect_struct *img_rect = &g_imgclp->img_rect;
    MMI_BOOL min_align_w;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(GDI_LCD_WIDTH <= GDI_LCD_HEIGHT)
    {
        min_w = IMAGE_CLIP_MIN_LENGTH;
        min_h = cui_image_clip_get_len_from_ratio(min_w, w_ratio, h_ratio);
        min_align_w = MMI_TRUE;
    }
    else
    {
        min_h = IMAGE_CLIP_MIN_LENGTH;
        min_w = cui_image_clip_get_len_from_ratio(min_h, h_ratio, w_ratio);
        min_align_w = MMI_FALSE;
    }

    if(img_rect->w < min_w || img_rect->h < min_h)
    {
        g_imgclp->is_osd_valid = MMI_FALSE;
        return;
    }

    g_imgclp->is_osd_valid = MMI_TRUE;

    if(img_rect->w <= cui_image_clip_get_len_from_ratio(img_rect->h, h_ratio, w_ratio))
    {
        g_imgclp->is_align_to_w = MMI_TRUE;
    }

    if(MMI_TRUE == g_imgclp->is_align_to_w)
    {
        g_imgclp->max_percent = img_rect->w * 100 / GDI_LCD_WIDTH;
    }
    else
    {
        g_imgclp->max_percent = img_rect->h * 100 / GDI_LCD_HEIGHT;
    }

    if(MMI_TRUE == min_align_w)
    {
        g_imgclp->min_percent = IMAGE_CLIP_MIN_LENGTH * 100 / GDI_LCD_WIDTH;
    }
    else
    {
        g_imgclp->min_percent = IMAGE_CLIP_MIN_LENGTH * 100 / GDI_LCD_HEIGHT;
    }

    g_imgclp->frame_percent = IMAGE_CLIP_INIT_FRAME_PERCENT;

    if(g_imgclp->frame_percent >= g_imgclp->max_percent)
    {
        g_imgclp->frame_percent = g_imgclp->max_percent;
        g_imgclp->btn_zin.btn_bg.state = IMGCLP_BUTTON_DISABLE;
    }

    cui_image_clip_get_frame_wh_from_percent(g_imgclp->frame_percent);

    g_imgclp->btn_frame.rect.x = (g_imgclp->img_rect.w - g_imgclp->btn_frame.rect.w) / 2 + g_imgclp->img_rect.x;
    g_imgclp->btn_frame.rect.y = (g_imgclp->img_rect.h - g_imgclp->btn_frame.rect.h) / 2 + g_imgclp->img_rect.y;

    cui_image_clip_get_last_frame();

}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  cui_image_clip_update_frame_touch_rect
* DESCRIPTION
*  get frame touch rect from frame postion
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_update_frame_touch_rect(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->btn_frame.touch_rect.x = 1;
    g_imgclp->btn_frame.touch_rect.y = 1;

    g_imgclp->btn_frame.touch_rect.w = g_imgclp->btn_frame.rect.w - 1;
    g_imgclp->btn_frame.touch_rect.h = g_imgclp->btn_frame.rect.h - 1;
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_update_balls_touch_rect
* DESCRIPTION
*  get balls touch rect from ball position
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_update_balls_touch_rect(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 b_width, b_height;
/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_IMAGE_CLIP_BALL, &b_width, &b_height);

    g_imgclp->btn_lt_ball.touch_rect.x = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_lt_ball.touch_rect.y = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_lt_ball.touch_rect.w = b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;
    g_imgclp->btn_lt_ball.touch_rect.h = b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;

    g_imgclp->btn_rt_ball.touch_rect.x = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_rt_ball.touch_rect.y = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_rt_ball.touch_rect.w = b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;
    g_imgclp->btn_rt_ball.touch_rect.h = b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;

    g_imgclp->btn_lb_ball.touch_rect.x = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_lb_ball.touch_rect.y = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_lb_ball.touch_rect.w = b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;
    g_imgclp->btn_lb_ball.touch_rect.h = b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;

    g_imgclp->btn_rb_ball.touch_rect.x = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_rb_ball.touch_rect.y = - IMAGE_CLIP_BALL_TOUCH_ADJUST;
    g_imgclp->btn_rb_ball.touch_rect.w = b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;
    g_imgclp->btn_rb_ball.touch_rect.h = b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;

    if(g_imgclp->btn_frame.rect.w < b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2)
    {
        g_imgclp->btn_lt_ball.touch_rect.x = - IMAGE_CLIP_BALL_TOUCH_ADJUST * 2; 

        g_imgclp->btn_rt_ball.touch_rect.x =  0;
    }

    if(g_imgclp->btn_lt_ball.rect.x + g_imgclp->btn_lt_ball.touch_rect.x < 0)
    {
        g_imgclp->btn_lt_ball.touch_rect.x = -g_imgclp->btn_lt_ball.rect.x;
        g_imgclp->btn_lt_ball.touch_rect.w =  g_imgclp->btn_lt_ball.touch_rect.w > (g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w / 2) ?
                      b_width : (b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2);
    }

    if (g_imgclp->btn_rt_ball.rect.x + g_imgclp->btn_rt_ball.touch_rect.x + b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2 > GDI_LCD_WIDTH)
    {
        g_imgclp->btn_rt_ball.touch_rect.x = (g_imgclp->btn_rt_ball.touch_rect.x + g_imgclp->btn_rt_ball.rect.x) > (g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w / 2) ?
                                             (GDI_LCD_WIDTH - b_width - IMAGE_CLIP_BALL_TOUCH_ADJUST * 2 - g_imgclp->btn_rt_ball.rect.x) : 0;
        g_imgclp->btn_rt_ball.touch_rect.w = (g_imgclp->btn_rt_ball.touch_rect.x + g_imgclp->btn_rt_ball.rect.x) > (g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w / 2) ?
                                             (b_width + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2) : b_width;
    }

    g_imgclp->btn_lb_ball.touch_rect.x = g_imgclp->btn_lt_ball.touch_rect.x;
    g_imgclp->btn_rb_ball.touch_rect.x = g_imgclp->btn_rt_ball.touch_rect.x;
    g_imgclp->btn_lb_ball.touch_rect.w = g_imgclp->btn_lt_ball.touch_rect.w;
    g_imgclp->btn_rb_ball.touch_rect.w = g_imgclp->btn_rt_ball.touch_rect.w;

    if(g_imgclp->btn_frame.rect.h < b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2)
    {
        g_imgclp->btn_lt_ball.touch_rect.y = - IMAGE_CLIP_BALL_TOUCH_ADJUST * 2;

        g_imgclp->btn_lb_ball.touch_rect.y =  0;
    }

    if(g_imgclp->btn_lt_ball.rect.y + g_imgclp->btn_lt_ball.touch_rect.y < g_clip_skin_struct.work_rect.y)
    {
        g_imgclp->btn_lt_ball.touch_rect.y = g_clip_skin_struct.work_rect.y - g_imgclp->btn_lt_ball.rect.y;
        g_imgclp->btn_lt_ball.touch_rect.h =  g_imgclp->btn_lt_ball.touch_rect.h > (g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h / 2) ?
                                              b_height : (b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2);
    }

    if (g_imgclp->btn_lb_ball.rect.y + g_imgclp->btn_lb_ball.touch_rect.y + b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2 > (g_clip_skin_struct.work_rect.y + g_clip_skin_struct.work_rect.h))
    {
        g_imgclp->btn_lb_ball.touch_rect.y = (g_imgclp->btn_lb_ball.touch_rect.y + g_imgclp->btn_lb_ball.rect.y) > (g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h / 2) ?
                                             ((g_clip_skin_struct.work_rect.y + g_clip_skin_struct.work_rect.h) - b_width - IMAGE_CLIP_BALL_TOUCH_ADJUST * 2 - g_imgclp->btn_lb_ball.rect.y) : 0;
        g_imgclp->btn_lb_ball.touch_rect.h = (g_imgclp->btn_lb_ball.touch_rect.y + g_imgclp->btn_lb_ball.rect.y) > (g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h / 2) ?
                                             (b_height + IMAGE_CLIP_BALL_TOUCH_ADJUST * 2) : b_height;
    }

    g_imgclp->btn_rt_ball.touch_rect.y = g_imgclp->btn_lt_ball.touch_rect.y;
    g_imgclp->btn_rb_ball.touch_rect.y = g_imgclp->btn_lb_ball.touch_rect.y;
    g_imgclp->btn_rt_ball.touch_rect.w = g_imgclp->btn_lt_ball.touch_rect.w;
    g_imgclp->btn_rb_ball.touch_rect.w = g_imgclp->btn_lb_ball.touch_rect.w;
}

#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_in_calculate_frame_wh
* DESCRIPTION
*  get frame width and height when zoom in
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_in_calculate_frame_wh(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if ((g_imgclp->frame_percent + IMAGE_CLIP_ZOOM_STEP_PERCENT) < g_imgclp->max_percent)
    {
        g_imgclp->frame_percent += IMAGE_CLIP_ZOOM_STEP_PERCENT;
    }
    else
    {
        g_imgclp->frame_percent = g_imgclp->max_percent;
        g_imgclp->btn_zin.btn_bg.state = IMGCLP_BUTTON_DISABLE;
    }

    if(MMI_TRUE == g_imgclp->is_align_to_w)
    {
        if(g_imgclp->frame_percent == g_imgclp->max_percent)
        {
            g_imgclp->btn_frame.rect.w = g_imgclp->img_rect.w;
        }
        else
        {
            g_imgclp->btn_frame.rect.w = (U16)(GDI_LCD_WIDTH * g_imgclp->frame_percent / 100);
        }

        g_imgclp->btn_frame.rect.h = (U16)cui_image_clip_get_len_from_ratio(g_imgclp->btn_frame.rect.w,
                                                                            g_imgclp->w_ratio,
                                                                            g_imgclp->h_ratio
                                                                            );
    }
    else
    {
        if(g_imgclp->frame_percent == g_imgclp->max_percent)
        {
            g_imgclp->btn_frame.rect.h = g_imgclp->img_rect.h;
        }
        else
        {
            g_imgclp->btn_frame.rect.h = (U16)(GDI_LCD_HEIGHT* g_imgclp->frame_percent / 100);
        }

        g_imgclp->btn_frame.rect.w = (U16)cui_image_clip_get_len_from_ratio(g_imgclp->btn_frame.rect.h,
                                                                            g_imgclp->h_ratio,
                                                                            g_imgclp->w_ratio
                                                                            );
    }

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_in_calculate_frame_wh
* DESCRIPTION
*  get frame width and height when zoom out
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_out_calculate_frame_wh(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if ((g_imgclp->frame_percent - IMAGE_CLIP_ZOOM_STEP_PERCENT) > g_imgclp->min_percent)
    {
        g_imgclp->frame_percent -= IMAGE_CLIP_ZOOM_STEP_PERCENT;
    }
    else
    {
        g_imgclp->frame_percent = g_imgclp->min_percent;
        g_imgclp->btn_zout.btn_bg.state = IMGCLP_BUTTON_DISABLE;
    }

    if(MMI_TRUE == g_imgclp->is_align_to_w)
    {
        g_imgclp->btn_frame.rect.w = (U16)(GDI_LCD_WIDTH * g_imgclp->frame_percent / 100);
        g_imgclp->btn_frame.rect.h = (U16)cui_image_clip_get_len_from_ratio(g_imgclp->btn_frame.rect.w,
                                                                            g_imgclp->w_ratio,
                                                                            g_imgclp->h_ratio
                                                                            );
    }
    else
    {
        g_imgclp->btn_frame.rect.h = (U16)(GDI_LCD_HEIGHT* g_imgclp->frame_percent / 100);
        g_imgclp->btn_frame.rect.w = (U16)cui_image_clip_get_len_from_ratio(g_imgclp->btn_frame.rect.h,
                                                                            g_imgclp->h_ratio,
                                                                            g_imgclp->w_ratio
                                                                            );
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_get_zoom_frame_pos
* DESCRIPTION
*  get frame position depend on zoom direction
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_get_zoom_frame_pos(cui_image_clip_zoom_direct direct)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S16 cw, ch;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cw = g_imgclp->btn_frame.rect.w - g_imgclp->last_frame.w;
    ch = g_imgclp->btn_frame.rect.h - g_imgclp->last_frame.h;

    if(cw < 0)
    {
        g_imgclp->btn_zin.btn_bg.state = IMGCLP_BUTTON_UP;
    }
    else if (cw > 0)
    {
        g_imgclp->btn_zout.btn_bg.state = IMGCLP_BUTTON_UP;
    }

    switch(direct)
    {
        case IMGCLP_DIRECT_CENTER:
            g_imgclp->btn_frame.rect.x = LT_EDGE_CALCULATE(g_imgclp->btn_frame.rect.x, cw/2, g_imgclp->img_rect.x);
            g_imgclp->btn_frame.rect.y = LT_EDGE_CALCULATE(g_imgclp->btn_frame.rect.y, ch/2, g_imgclp->img_rect.y);

            break;
        case IMGCLP_DIRECT_LT:
            g_imgclp->btn_frame.rect.x = LT_EDGE_CALCULATE(g_imgclp->btn_frame.rect.x,
                                                           cw,
                                                           g_imgclp->img_rect.x);
            g_imgclp->btn_frame.rect.y = LT_EDGE_CALCULATE(g_imgclp->btn_frame.rect.y,
                                                           ch,
                                                           g_imgclp->img_rect.y);
            break;
        case IMGCLP_DIRECT_RT:
            g_imgclp->btn_frame.rect.y = LT_EDGE_CALCULATE(g_imgclp->btn_frame.rect.y,
                                                           ch,
                                                           g_imgclp->img_rect.y);
            break;
        case IMGCLP_DIRECT_LB:
            g_imgclp->btn_frame.rect.x = LT_EDGE_CALCULATE(g_imgclp->btn_frame.rect.x,
                                                           cw,
                                                           g_imgclp->img_rect.x);
            break;
        case IMGCLP_DIRECT_RB:
            break;
        default:
            break;
    }

    g_imgclp->btn_frame.rect.x = RB_EDGE_CALCULATE(g_imgclp->btn_frame.rect.x,
                                                   g_imgclp->btn_frame.rect.w,
                                                   g_imgclp->img_rect.x + g_imgclp->img_rect.w
                                                   );

    g_imgclp->btn_frame.rect.y = RB_EDGE_CALCULATE(g_imgclp->btn_frame.rect.y,
                                                   g_imgclp->btn_frame.rect.h,
                                                   g_imgclp->img_rect.y + g_imgclp->img_rect.h
                                                   );

    if(g_imgclp->frame_percent == g_imgclp->max_percent)
    {
        if(MMI_TRUE == g_imgclp->is_align_to_w)
        {
            g_imgclp->btn_frame.rect.x = g_imgclp->img_rect.x;
        }
        else
        {
            g_imgclp->btn_frame.rect.y = g_imgclp->img_rect.y;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_erase_last_frame
* DESCRIPTION
*  erase last frame and balls
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_erase_last_frame(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 b_width, b_height;
    cui_image_clip_rect_struct erase_rect;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/    
    gdi_image_get_dimension_id(IMG_ID_IMAGE_CLIP_BALL, &b_width, &b_height);

    erase_rect.x = g_imgclp->last_frame.x - b_width;
    erase_rect.y = g_imgclp->last_frame.y - b_height;

    erase_rect.w = g_imgclp->last_frame.w + b_width * 2;
    erase_rect.h = g_imgclp->last_frame.h + b_height * 2;

    gdi_push_and_set_alpha_blending_source_layer(g_imgclp->decode_layer);

    gdi_draw_solid_rect(erase_rect.x,
                        erase_rect.y,
                        erase_rect.x + erase_rect.w,
                        erase_rect.y + erase_rect.h,
                        gdi_act_color_from_rgb(255, g_clip_skin_struct.clip_bg_color.color_r, g_clip_skin_struct.clip_bg_color.color_g, g_clip_skin_struct.clip_bg_color.color_b));

    gdi_layer_push_and_set_clip(g_imgclp->img_rect.x,
                                g_imgclp->img_rect.y,
                                g_imgclp->img_rect.x + g_imgclp->img_rect.w,
                                g_imgclp->img_rect.y + g_imgclp->img_rect.h); 
    gdi_image_draw_resized_id(erase_rect.x,
                              erase_rect.y,
                              erase_rect.w + 1,
                              erase_rect.h + 1,
                              IMG_ID_IMAGE_CLIP_MASK);
    gdi_layer_pop_clip(); 

    gdi_pop_and_restore_alpha_blending_source_layer();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_get_ball_pos
* DESCRIPTION
*  get ball postion from frame postion
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_get_ball_pos(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 b_width, b_height;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_IMAGE_CLIP_BALL, &b_width, &b_height);

    g_imgclp->btn_lt_ball.rect.x = g_imgclp->btn_frame.rect.x - b_width/2;
    g_imgclp->btn_lt_ball.rect.y = g_imgclp->btn_frame.rect.y - b_height/2;

    g_imgclp->btn_rt_ball.rect.x = g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w - b_width/2;
    g_imgclp->btn_rt_ball.rect.y = g_imgclp->btn_frame.rect.y - b_height/2;

    g_imgclp->btn_lb_ball.rect.x = g_imgclp->btn_frame.rect.x - b_width/2;
    g_imgclp->btn_lb_ball.rect.y = g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h - b_height/2;

    g_imgclp->btn_rb_ball.rect.x = g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w - b_width/2;
    g_imgclp->btn_rb_ball.rect.y = g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h - b_height/2;
}


#define _IMAGE_CLIP_DRAW_BASIC_FUNCTIONS

/*****************************************************************************
* FUNCTION
*  cui_image_clip_check_file_exist
* DESCRIPTION
*  to judge file is exist
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL cui_image_clip_check_file_exist(WCHAR *path)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    FS_HANDLE handle;
    U32 file_size = 0;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    handle = FS_Open(path, FS_READ_ONLY);

    if (handle >= FS_NO_ERROR)
    {
        FS_GetFileSize(handle,&file_size);
        FS_Close(handle);

        #if defined (__MTK_TARGET__)     
        if(file_size == 0)
        {
            FS_Delete((const WCHAR*)path);            
            return MMI_FALSE;  
        }
        else
        #endif
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_image_clip_gen_file_name
* DESCRIPTION
*  generate file name if caller don't give a dest path
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_gen_file_name(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T rtc_time;
    DCL_HANDLE rtc_handler = 0;
    U8 count = 0;
    U16 *p = NULL;
    WCHAR file_name[20];

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_GEN_FILE_NAME, __LINE__);

    rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *) &rtc_time);
    DclRTC_Close(rtc_handler);

    p = (U16*) mmi_wcsrchr(g_imgclp->source_file, (U16) '\\');

    for(count = 0; count <= 99; count ++)
    {
        kal_wsprintf((WCHAR *)file_name,
                     "IMGCLP_%02d%02d%02d%02d.jpg",
                     rtc_time.u1Hour,
                     rtc_time.u1Min,
                     rtc_time.u1Sec,
                     count);
        
        mmi_wcsncpy(g_imgclp->dest_file, g_imgclp->source_file, (p - (U16*)g_imgclp->source_file + 1));
        mmi_wcscat(g_imgclp->dest_file, (WCHAR *)file_name);

        if(!cui_image_clip_check_file_exist(g_imgclp->dest_file))
        {
            break;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_get_image_rect
* DESCRIPTION
*  estimate image rect postion
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_get_image_rect(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 width, height;
    S32 resized_x, resized_y, resized_w, resized_h;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_image_get_dimension_file((U8 *)g_imgclp->source_file,
                                  &width,
                                  &height);

    g_imgclp->source_size.width = width;
    g_imgclp->source_size.height = height;

    if(g_clip_skin_struct.work_rect.w < width || 
       g_clip_skin_struct.work_rect.h < height)
    {
        g_imgclp->is_resized = MMI_TRUE;
    }

    gdi_util_fit_box(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                     GDI_LCD_WIDTH,
                     GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT,
                     width,
                     height,
                     &resized_x,
                     &resized_y,
                     &resized_w,
                     &resized_h);

    g_imgclp->img_rect.x = (S16)resized_x;
    g_imgclp->img_rect.y = (S16)resized_y + MMI_STATUS_BAR_HEIGHT;
    g_imgclp->img_rect.w = (S16)resized_w;
    g_imgclp->img_rect.h = (S16)resized_h;
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_clip_image
* DESCRIPTION
*  draw image on clip layer
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_clip_image(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    cui_image_clip_rect_struct *img_rect = &g_imgclp->img_rect;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(MMI_TRUE == g_imgclp->is_osd_valid)
    {
        gdi_push_and_set_alpha_blending_source_layer(g_imgclp->decode_layer);

    gdi_image_draw_resized_id(img_rect->x,
                              img_rect->y,
                              img_rect->w,
                              img_rect->h,
                              IMG_ID_IMAGE_CLIP_MASK);

        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    else
    {
        gdi_layer_push_and_set_clip(g_imgclp->img_rect.x,
                                    g_imgclp->img_rect.y,
                                    g_imgclp->img_rect.x + g_imgclp->img_rect.w,
                                    g_imgclp->img_rect.y + g_imgclp->img_rect.h);

        gdi_layer_flatten_with_clipping(g_imgclp->clip_layer,
                                        g_imgclp->decode_layer,
                                        0,
                                        0);

        gdi_layer_pop_clip();
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_image_bound
* DESCRIPTION
*  draw image bound for image rect
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_image_bound(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    cui_image_clip_rect_struct *img_rect = &g_imgclp->img_rect;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(img_rect->w < GDI_LCD_WIDTH)
    {
        gdi_draw_line(img_rect->x-1, 
                      img_rect->y-1, 
                      img_rect->x-1,
                      img_rect->y+img_rect->h,
                      gdi_act_color_from_rgb(255, g_clip_skin_struct.bound_color.color_r, g_clip_skin_struct.bound_color.color_g, g_clip_skin_struct.bound_color.color_b));
        gdi_draw_line(img_rect->x+img_rect->w,
                      img_rect->y-1,
                      img_rect->x+img_rect->w,
                      img_rect->y+img_rect->h,
                      gdi_act_color_from_rgb(255, g_clip_skin_struct.bound_color.color_r, g_clip_skin_struct.bound_color.color_g, g_clip_skin_struct.bound_color.color_b));
    }

    if(img_rect->h < (GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT))
    {
        gdi_draw_line(img_rect->x-1,
                      img_rect->y-1,
                      img_rect->x+img_rect->w,
                      img_rect->y-1,
                      gdi_act_color_from_rgb(255, g_clip_skin_struct.bound_color.color_r, g_clip_skin_struct.bound_color.color_g, g_clip_skin_struct.bound_color.color_b));
        gdi_draw_line(img_rect->x-1,
                      img_rect->y+img_rect->h,
                      img_rect->x+img_rect->w,
                      img_rect->y+img_rect->h,
                      gdi_act_color_from_rgb(255, g_clip_skin_struct.bound_color.color_r, g_clip_skin_struct.bound_color.color_g, g_clip_skin_struct.bound_color.color_b));
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_redraw_frame
* DESCRIPTION
*  redraw frame
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_redraw_frame(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/


/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_push_and_set_alpha_blending_source_layer(g_imgclp->decode_layer);

    gdi_image_draw_resized_id(g_imgclp->btn_frame.rect.x,
                              g_imgclp->btn_frame.rect.y,
                              g_imgclp->btn_frame.rect.w,
                              g_imgclp->btn_frame.rect.h,
                              IMG_ID_IMAGE_CLIP_FRAME);

    gdi_pop_and_restore_alpha_blending_source_layer();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_ball
* DESCRIPTION
*  x , y       :      [IN] ball postion
*  state      :      [IN] ball state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_ball(S16 x, S16 y, cui_image_clip_button_state_enum state)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    switch(state)
    {
        case IMGCLP_BUTTON_UP:
            gdi_image_draw_id(x, y, IMG_ID_IMAGE_CLIP_BALL);
            break;
        case IMGCLP_BUTTON_DOWN:
            gdi_image_draw_id(x, y, IMG_ID_IMAGE_CLIP_BALL_DOWN);
            break;
        default:
            gdi_image_draw_id(x, y, IMG_ID_IMAGE_CLIP_BALL);
            break;
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_redraw_balls
* DESCRIPTION
*  redraw all balls
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_redraw_balls(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_push_and_set_alpha_blending_source_layer(g_imgclp->clip_layer);

    cui_image_clip_draw_ball(g_imgclp->btn_lt_ball.rect.x,
                             g_imgclp->btn_lt_ball.rect.y,
                             g_imgclp->btn_lt_ball.state);
    cui_image_clip_draw_ball(g_imgclp->btn_rt_ball.rect.x,
                             g_imgclp->btn_rt_ball.rect.y,
                             g_imgclp->btn_rt_ball.state);
    cui_image_clip_draw_ball(g_imgclp->btn_lb_ball.rect.x,
                             g_imgclp->btn_lb_ball.rect.y,
                             g_imgclp->btn_lb_ball.state);
    cui_image_clip_draw_ball(g_imgclp->btn_rb_ball.rect.x,
                             g_imgclp->btn_rb_ball.rect.y,
                             g_imgclp->btn_rb_ball.state);

    gdi_pop_and_restore_alpha_blending_source_layer();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_redraw_zoom_btn
* DESCRIPTION
*  redraw zoom in and zoom out button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_redraw_zoom_btn(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_push_and_set_alpha_blending_source_layer(g_imgclp->clip_layer);

    switch(g_imgclp->btn_zin.btn_bg.state)
    {
        case IMGCLP_BUTTON_UP:
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(g_imgclp->btn_zin.btn_bg.rect.x,
                                   g_imgclp->btn_zin.btn_bg.rect.y,
                                   g_imgclp->btn_zin.btn_bg.rect.w,
                                   g_imgclp->btn_zin.btn_bg.rect.h,
                                   IMAGE_CLIP_ZIN_BG_IMG);
            gdi_image_draw_id(g_imgclp->btn_zin.btn_content.x,
                              g_imgclp->btn_zin.btn_content.y,
                              IMG_ID_IMAGE_CLIP_ZOOM_IN);
        #else /* __MMI_FTE_SUPPORT__ */
            gdi_image_draw_resized_id(g_imgclp->btn_zin.btn_bg.rect.x,
                                   g_imgclp->btn_zin.btn_bg.rect.y,
                                   g_imgclp->btn_zin.btn_bg.rect.w,
                                   g_imgclp->btn_zin.btn_bg.rect.h,
                                   IMG_ID_IMAGE_CLIP_ZOOM_IN);
        #endif
            break;
        case IMGCLP_BUTTON_DOWN:
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(g_imgclp->btn_zin.btn_bg.rect.x,
                                   g_imgclp->btn_zin.btn_bg.rect.y,
                                   g_imgclp->btn_zin.btn_bg.rect.w,
                                   g_imgclp->btn_zin.btn_bg.rect.h,
                                   IMAGE_CLIP_ZIN_BG_IMG_PRESSED);
            gdi_image_draw_id(g_imgclp->btn_zin.btn_content.x,
                              g_imgclp->btn_zin.btn_content.y,
                              IMG_ID_IMAGE_CLIP_ZOOM_IN);
        #else /* __MMI_FTE_SUPPORT__ */
            gdi_image_draw_resized_id(g_imgclp->btn_zin.btn_bg.rect.x,
                                   g_imgclp->btn_zin.btn_bg.rect.y,
                                   g_imgclp->btn_zin.btn_bg.rect.w,
                                   g_imgclp->btn_zin.btn_bg.rect.h,
                                   IMG_ID_IMAGE_CLIP_ZOOM_IN_DOWN);
        #endif
            break;
        case IMGCLP_BUTTON_DISABLE:
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(g_imgclp->btn_zin.btn_bg.rect.x,
                                   g_imgclp->btn_zin.btn_bg.rect.y,
                                   g_imgclp->btn_zin.btn_bg.rect.w,
                                   g_imgclp->btn_zin.btn_bg.rect.h,
                                   IMAGE_CLIP_ZIN_BG_IMG);
            gdi_image_draw_id(g_imgclp->btn_zin.btn_content.x,
                              g_imgclp->btn_zin.btn_content.y,
                              IMG_ID_IMAGE_CLIP_ZOOM_IN_DISABLE);
        #else /* __MMI_FTE_SUPPORT__ */
            gdi_image_draw_resized_id(g_imgclp->btn_zin.btn_bg.rect.x,
                                   g_imgclp->btn_zin.btn_bg.rect.y,
                                   g_imgclp->btn_zin.btn_bg.rect.w,
                                   g_imgclp->btn_zin.btn_bg.rect.h,
                                   IMG_ID_IMAGE_CLIP_ZOOM_IN_DISABLE);
        #endif
            break;
        default:
            break;
    }

    switch(g_imgclp->btn_zout.btn_bg.state)
    {
        case IMGCLP_BUTTON_UP:
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(g_imgclp->btn_zout.btn_bg.rect.x,
                                   g_imgclp->btn_zout.btn_bg.rect.y,
                                   g_imgclp->btn_zout.btn_bg.rect.w,
                                   g_imgclp->btn_zout.btn_bg.rect.h,
                                   IMAGE_CLIP_ZOUT_BG_IMG);
            gdi_image_draw_id(g_imgclp->btn_zout.btn_content.x,
                              g_imgclp->btn_zout.btn_content.y,
                              IMG_ID_IMAGE_CLIP_ZOOM_OUT);
        #else /* __MMI_FTE_SUPPORT__ */
            gdi_image_draw_resized_id(g_imgclp->btn_zout.btn_bg.rect.x,
                                   g_imgclp->btn_zout.btn_bg.rect.y,
                                   g_imgclp->btn_zout.btn_bg.rect.w,
                                   g_imgclp->btn_zout.btn_bg.rect.h,
                                   IMG_ID_IMAGE_CLIP_ZOOM_OUT);
        #endif
            break;
        case IMGCLP_BUTTON_DOWN:
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(g_imgclp->btn_zout.btn_bg.rect.x,
                                   g_imgclp->btn_zout.btn_bg.rect.y,
                                   g_imgclp->btn_zout.btn_bg.rect.w,
                                   g_imgclp->btn_zout.btn_bg.rect.h,
                                   IMAGE_CLIP_ZOUT_BG_IMG_PRESSED);
            gdi_image_draw_id(g_imgclp->btn_zout.btn_content.x,
                              g_imgclp->btn_zout.btn_content.y,
                              IMG_ID_IMAGE_CLIP_ZOOM_OUT);
        #else /* __MMI_FTE_SUPPORT__ */
            gdi_image_draw_resized_id(g_imgclp->btn_zout.btn_bg.rect.x,
                                   g_imgclp->btn_zout.btn_bg.rect.y,
                                   g_imgclp->btn_zout.btn_bg.rect.w,
                                   g_imgclp->btn_zout.btn_bg.rect.h,
                                   IMG_ID_IMAGE_CLIP_ZOOM_OUT_DOWN);
        #endif
            break;
        case IMGCLP_BUTTON_DISABLE:
        #ifdef __MMI_FTE_SUPPORT__
            gdi_image_draw_resized(g_imgclp->btn_zout.btn_bg.rect.x,
                                   g_imgclp->btn_zout.btn_bg.rect.y,
                                   g_imgclp->btn_zout.btn_bg.rect.w,
                                   g_imgclp->btn_zout.btn_bg.rect.h,
                                   IMAGE_CLIP_ZOUT_BG_IMG);
            gdi_image_draw_id(g_imgclp->btn_zout.btn_content.x,
                              g_imgclp->btn_zout.btn_content.y,
                              IMG_ID_IMAGE_CLIP_ZOOM_OUT_DISABLE);
        #else /* __MMI_FTE_SUPPORT__ */
            gdi_image_draw_resized_id(g_imgclp->btn_zout.btn_bg.rect.x,
                                   g_imgclp->btn_zout.btn_bg.rect.y,
                                   g_imgclp->btn_zout.btn_bg.rect.w,
                                   g_imgclp->btn_zout.btn_bg.rect.h,
                                   IMG_ID_IMAGE_CLIP_ZOOM_OUT_DISABLE);
        #endif
            break;
        default:
            break;
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_clip_layer
* DESCRIPTION
*  redraw zoom in and zoom out button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_clip_layer(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgclp->clip_layer);
    gdi_layer_clear(gdi_act_color_from_rgb(255, g_clip_skin_struct.clip_bg_color.color_r, g_clip_skin_struct.clip_bg_color.color_g, g_clip_skin_struct.clip_bg_color.color_b));

    gdi_layer_push_and_set_clip(g_clip_skin_struct.work_rect.x,
                                g_clip_skin_struct.work_rect.y,
                                g_clip_skin_struct.work_rect.x + g_clip_skin_struct.work_rect.w,
                                g_clip_skin_struct.work_rect.y + g_clip_skin_struct.work_rect.h);
    
    cui_image_clip_draw_clip_image();
    cui_image_clip_draw_image_bound();

    if(MMI_TRUE == g_imgclp->is_osd_valid)
    {
    cui_image_clip_redraw_frame();
    cui_image_clip_redraw_balls();
    cui_image_clip_redraw_zoom_btn();
    }

    gdi_layer_pop_clip();
    
    gdi_layer_pop_and_restore_active();

    gdi_layer_blt_previous(0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_redraw_clip
* DESCRIPTION
*  redraw clip layer
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_redraw_clip(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgclp->clip_layer);

    cui_image_clip_erase_last_frame();

    gdi_layer_push_and_set_clip(g_clip_skin_struct.work_rect.x,
                                g_clip_skin_struct.work_rect.y,
                                g_clip_skin_struct.work_rect.x + g_clip_skin_struct.work_rect.w,
                                g_clip_skin_struct.work_rect.y + g_clip_skin_struct.work_rect.h);

    cui_image_clip_draw_image_bound();

    if(MMI_TRUE == g_imgclp->is_osd_valid)
    {
        cui_image_clip_redraw_frame();
        cui_image_clip_redraw_balls();
        cui_image_clip_redraw_zoom_btn();
    }

    gdi_layer_pop_clip();

    gdi_layer_pop_and_restore_active();

    gdi_layer_blt_previous(0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_calculate_save_coordinate
* DESCRIPTION
*  calculate coordinate for save in source img file
* PARAMETERS
*  x        :       [OUT] x position against save layer
*  y        :       [OUT] y position against save layer
*  w       :       [OUT] w of resized source file
*  h        :       [OUT] h of resized source file
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_calculate_save_coordinate(S32* x, S32* y, S32* w, S32* h)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 width, height;
    S32 save_buf_size;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(MMI_FALSE == g_imgclp->is_osd_valid)
    {
        S32 resized_x, resized_y, resized_w, resized_h;
        
        gdi_util_fit_box(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                     g_imgclp->dest_size.width,
                     g_imgclp->dest_size.height,
                     g_imgclp->source_size.width,
                     g_imgclp->source_size.height,
                     &resized_x,
                     &resized_y,
                     &resized_w,
                     &resized_h);

        *x = 0;
        *y = 0;
        *w = resized_w;
        *h = resized_h;

        save_buf_size = (resized_w * resized_h * IMAGE_CLIP_BITS_PER_PIXEL) >> 3;

        cui_image_clip_init_save_layer(resized_w, resized_h, save_buf_size);

        return;
    }

    width = g_imgclp->source_size.width * 100 * 
             g_imgclp->btn_frame.rect.w / g_imgclp->img_rect.w;
    height = g_imgclp->source_size.height * 100 *
             g_imgclp->btn_frame.rect.h / g_imgclp->img_rect.h;

    *x = (g_imgclp->btn_frame.rect.x - g_imgclp->img_rect.x) * 
              width / g_imgclp->btn_frame.rect.w;
    *y = (g_imgclp->btn_frame.rect.y - g_imgclp->img_rect.y) *
              height / g_imgclp->btn_frame.rect.h;

    *x = - *x/100;
    *y = - *y/100;

    if(width <= (g_imgclp->dest_size.width * 100) &&
       height <= (g_imgclp->dest_size.height * 100))
    {
        width = width / 100;
        height = height / 100;
        
        save_buf_size = (width * height * IMAGE_CLIP_BITS_PER_PIXEL) >> 3;

        *w = g_imgclp->source_size.width;
        *h = g_imgclp->source_size.height;

        cui_image_clip_init_save_layer(width, height, save_buf_size);
    }
    else
    {
        save_buf_size = (g_imgclp->dest_size.width * 
                         g_imgclp->dest_size.height *
                         IMAGE_CLIP_BITS_PER_PIXEL) >> 3;
        
        width = width / 100;
        height = height / 100;


        *x = *x * g_imgclp->dest_size.width * 100 / width;
        *y = *y * g_imgclp->dest_size.height * 100 / height;

        *w = g_imgclp->source_size.width * g_imgclp->dest_size.width * 100 / width;
        *h = g_imgclp->source_size.height * g_imgclp->dest_size.height * 100 / height;

        *x = *x / 100;
        *y = *y / 100;
        *w = *w / 100;
        *h = *h / 100;

        cui_image_clip_init_save_layer(g_imgclp->dest_size.width, g_imgclp->dest_size.height, save_buf_size);
    }

    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_send_result
* DESCRIPTION
*  send result to parent
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_send_result(MMI_BOOL succeed)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    cui_image_clip_evt_struct evt;
/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_SEND_RESULT, __LINE__, succeed);

    if(MMI_TRUE == succeed)
    {
        evt.evt_id = EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS;
        evt.save_file_path = g_imgclp->dest_file;
    }
    else
    {
        evt.evt_id = EVT_ID_CUI_IMAGE_CLIP_RESULT_FAILED;
    }    

    evt.size = sizeof(cui_image_clip_evt_struct);

    evt.sender_id = g_imgclp->cui_gid;

    evt.user_data = g_imgclp->user_data;

    mmi_frm_group_post_to_parent(g_imgclp->cui_gid, (mmi_group_event_struct*) &evt);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_send_exit_req
* DESCRIPTION
*  send close self to parent
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_send_exit_req(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    cui_image_clip_evt_struct evt;
/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_SEND_EXIT, __LINE__);

    evt.evt_id = EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST;

    evt.size = sizeof(cui_image_clip_evt_struct);

    evt.sender_id = g_imgclp->cui_gid;

    mmi_frm_group_post_to_parent(g_imgclp->cui_gid, (mmi_group_event_struct*) &evt);

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_check_and_create_dir
* DESCRIPTION
*  check if dir is exist, if not, create
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_check_and_create_dir(WCHAR *path)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 ret = FS_NO_ERROR;
    WCHAR *p;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    memset(g_imgclp->source_file, 0, CUI_IMAGE_CLIP_FULL_FILE_PATH_LEN);

    p = mmi_wcschr(g_imgclp->dest_file, L'\\');

    p = mmi_wcschr(p+1, L'\\');

    while(p!=NULL)
    {
        mmi_wcsncpy(g_imgclp->source_file, g_imgclp->dest_file, (p-g_imgclp->dest_file + 1));

        handle = FS_Open(g_imgclp->source_file, FS_OPEN_DIR | FS_READ_ONLY);

        if (handle >= FS_NO_ERROR)
        {
            FS_Close(handle);
        }
        else
        {
            ret = FS_CreateDir(g_imgclp->source_file);

            if (ret < 0)
            {
                mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, NULL);
                cui_image_clip_send_result(MMI_FALSE);
                cui_image_clip_send_exit_req();            
            }
        }

        p=mmi_wcschr(p+1, L'\\');
    }

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_send_suceed_msg
* DESCRIPTION
*  send succeed message to parent
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_done_and_send_succeed_msg(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    GDI_RESULT ret;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
   if(0 == *(g_imgclp->dest_file))
    {
        cui_image_clip_gen_file_name();
    }

    cui_image_clip_check_and_create_dir(g_imgclp->dest_file);

    ret = gdi_image_encode_layer_to_jpeg(g_imgclp->save_layer,(PS8)g_imgclp->dest_file);

    if(GDI_SUCCEED == ret)
    {
        cui_image_clip_send_result(MMI_TRUE);
    }
    else
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE, NULL);
        cui_image_clip_send_result(MMI_FALSE);
    }

    cui_image_clip_send_exit_req();
}


/*****************************************************************************
* FUNCTION
*  cui_image_clip_register_key_handler_by_state
* DESCRIPTION
*  register key handlers
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_register_key_handler_by_state(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    switch(g_imgclp->clip_state)
    {
        case IMGCLP_STATE_LOAD:
                set_left_softkey_label(L"");
                set_right_softkey_label((UI_string_type)GetString(STR_GLOBAL_BACK));

                SetLeftSoftkeyFunction(UI_dummy_function,KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(UI_dummy_function,KEY_EVENT_UP);

                SetRightSoftkeyFunction(cui_image_clip_RSK_down, KEY_EVENT_DOWN);
                SetRightSoftkeyFunction(cui_image_clip_RSK_up, KEY_EVENT_UP);
            break;
         case IMGCLP_STATE_SAVE:
		 	    set_left_softkey_label(L"");
                set_right_softkey_label((UI_string_type)GetString(STR_GLOBAL_BACK));

                SetLeftSoftkeyFunction(UI_dummy_function,KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(UI_dummy_function,KEY_EVENT_UP);

                SetRightSoftkeyFunction(cui_image_clip_RSK_down, KEY_EVENT_DOWN);
                SetRightSoftkeyFunction(cui_image_clip_back_to_edit, KEY_EVENT_UP);
            break;
         case IMGCLP_STATE_PREVIEW:
                set_left_softkey_label((UI_string_type)GetString(STR_GLOBAL_OK));
                set_right_softkey_label((UI_string_type)GetString(STR_GLOBAL_BACK));

                SetLeftSoftkeyFunction(cui_image_clip_LSK_down,KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(cui_image_clip_done_and_send_succeed_msg,KEY_EVENT_UP);

                SetRightSoftkeyFunction(cui_image_clip_RSK_down, KEY_EVENT_DOWN);
                SetRightSoftkeyFunction(cui_image_clip_back_to_edit, KEY_EVENT_UP);
            break;
        case IMGCLP_STATE_EDIT:
                set_left_softkey_label((UI_string_type)GetString(STR_GLOBAL_PREVIEW));
                set_right_softkey_label((UI_string_type)GetString(STR_GLOBAL_BACK));

                SetLeftSoftkeyFunction(cui_image_clip_LSK_down,KEY_EVENT_DOWN);
                SetLeftSoftkeyFunction(cui_image_clip_LSK_up,KEY_EVENT_UP);

                SetRightSoftkeyFunction(cui_image_clip_RSK_down, KEY_EVENT_DOWN);
                SetRightSoftkeyFunction(cui_image_clip_RSK_up, KEY_EVENT_UP);

            break;
        default:
            break;
    }

}



/*****************************************************************************
* FUNCTION
*  cui_image_clip_preview
* DESCRIPTION
*  preview clip image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_preview(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->clip_state = IMGCLP_STATE_PREVIEW;

    cui_image_clip_register_key_handler_by_state();
    cui_image_clip_draw_soft_key();
    
    if(g_imgclp->real_save_size.height > g_clip_skin_struct.work_rect.h)
    {
        gdi_layer_push_and_set_active(g_imgclp->status_bar_layer);
        gdi_layer_set_opacity(MMI_TRUE, 100);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(g_imgclp->soft_key_layer);
        gdi_layer_set_opacity(MMI_TRUE, 100);
        gdi_layer_pop_and_restore_active();
    }

    gdi_layer_blt_previous(0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_preview_draw
* DESCRIPTION
*  draw preview layer
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_preview_draw(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/   
    S32 x,y;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgclp->clip_layer);
    gdi_layer_clear(gdi_act_color_from_rgb(255, g_clip_skin_struct.clip_bg_color.color_r, g_clip_skin_struct.clip_bg_color.color_g, g_clip_skin_struct.clip_bg_color.color_b));
    gdi_layer_pop_and_restore_active();

    if(g_imgclp->real_save_size.height > g_clip_skin_struct.work_rect.h)
    {
        x = (GDI_LCD_WIDTH - g_imgclp->real_save_size.width) / 2;
        y = (GDI_LCD_HEIGHT - g_imgclp->real_save_size.height) / 2;

        gdi_layer_push_and_set_active(g_imgclp->save_layer);
        gdi_layer_set_position(x, y);
        gdi_layer_pop_and_restore_active();        
    }
    else
    {
        x = (g_clip_skin_struct.work_rect.w - g_imgclp->real_save_size.width) / 2;
        y = (g_clip_skin_struct.work_rect.h - g_imgclp->real_save_size.height) / 2 ;

        gdi_layer_push_and_set_active(g_imgclp->save_layer);
        gdi_layer_set_position(x, y + g_clip_skin_struct.work_rect.y);
        gdi_layer_pop_and_restore_active();
    }

    gdi_layer_set_blt_layer(g_imgclp->clip_layer,
                            g_imgclp->save_layer,
                            g_imgclp->status_bar_layer,
                            g_imgclp->soft_key_layer);

    gdi_layer_blt_previous(0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
}

#define _IMAGE_CLIP_STATUS_ICON_BAR_AND_SOFT_KEY

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_soft_key
* DESCRIPTION
*  draw soft key
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_soft_key(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    wgui_softkey_set_target_layer(g_imgclp->soft_key_layer);

    move_softkey(0, 0, MMI_LEFT_SOFTKEY);
    move_softkey(MMI_SOFTKEY_WIDTH, 0, MMI_CENTER_SOFTKEY);
    move_softkey((GDI_LCD_WIDTH - MMI_SOFTKEY_WIDTH), 0, MMI_RIGHT_SOFTKEY);

    register_default_hide_softkeys();

    show_softkey_background();
    redraw_softkey(MMI_LEFT_SOFTKEY);
    redraw_softkey(MMI_CENTER_SOFTKEY);
    redraw_softkey(MMI_RIGHT_SOFTKEY);

    gdi_layer_blt_previous(0, GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT, GDI_LCD_WIDTH-1, GDI_LCD_HEIGHT - 1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_redraw_status_icon
* DESCRIPTION
*  redraw status icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_redraw_status_icon(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgclp->status_bar_layer);

    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR,
                                  &cx1,
                                  &cy1,
                                  &cx2,
                                  &cy2);
    gdi_layer_push_and_set_clip(cx1, cy1, cx2, cy2);
    gdi_draw_solid_rect(cx1, cy1, cx2, cy2, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_draw_status_icon_bar
* DESCRIPTION
*  draw status icon bar
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_draw_status_icon_bar(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    wgui_status_icon_bar_register_hide_callback(WGUI_STATUS_ICON_BAR_H_BAR,
                                                cui_image_clip_redraw_status_icon);
    
    wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, g_imgclp->status_bar_layer);
    wgui_status_icon_bar_set_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR,
                                               g_imgclp->clip_layer);

    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
}

#define _IMAGE_CLIP_IMAGE_DECODE_AND_INFO

/*****************************************************************************
* FUNCTION
*  cui_image_clip_decode_image_callback
* DESCRIPTION
*  decode image call back
* PARAMETERS
*  result    :    [IN]
*  handle   :    [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_decode_image_callback(GDI_RESULT result, gdi_handle handle)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_DECODE_IMAGE_DONE, __LINE__);

    if(NULL == (void *)g_imgclp)
    {
         return;
    }

    // GDI_IMAGE_ERR_DECODE_TIME_OUT
    if(result == GDI_SUCCEED)
    {
        g_imgclp->is_decoding = MMI_FALSE;
        g_imgclp->clip_state = IMGCLP_STATE_EDIT;

        g_imgclp->img_decode_handle = GDI_NULL_HANDLE;

        if(MMI_TRUE == g_imgclp->is_in_main)
        {
            cui_image_clip_draw_animation_stop();
            cui_image_clip_draw_clip_layer();
            cui_image_clip_draw_status_icon_bar();
            cui_image_clip_register_key_handler_by_state();
            cui_image_clip_draw_soft_key();
        }
    }
    else
    {
        if(MMI_TRUE == g_imgclp->is_in_main)
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_IMAGE_CLIP_IMAGE_DECODE_FAILED), MMI_EVENT_FAILURE, NULL);
            cui_image_clip_send_result(MMI_FALSE);
            cui_image_clip_send_exit_req();
        }
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_decode_image
* DESCRIPTION
*  start to decode image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_decode_image(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgclp->decode_layer);

    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_push_and_set_alpha_blending_source_layer(g_imgclp->decode_layer);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_DECODE_IMAGE, __LINE__);

    g_imgclp->is_decoding = MMI_TRUE;
    g_imgclp->img_decode_handle = gdi_imgdec_nb_draw_resized_file(g_imgclp->decode_layer,
                                                                  g_imgclp->img_rect.x,
                                                                  g_imgclp->img_rect.y,
                                                                  g_imgclp->img_rect.w,
                                                                  g_imgclp->img_rect.h,
                                                                  (U8 *)g_imgclp->source_file,
                                                                  cui_image_clip_decode_image_callback
                                                                  );

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_decode_save_img_callback
* DESCRIPTION
*  decode image save call back
* PARAMETERS
*  result    :    [IN]
*  handle   :    [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_decode_save_img_callback(GDI_RESULT result, gdi_handle handle)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_SAVE_DECODE_DONE, __LINE__);
	
    if(result == GDI_SUCCEED)
    {
        g_imgclp->img_decode_handle = GDI_NULL_HANDLE;

        if(MMI_TRUE == g_imgclp->is_in_main)
        {
            cui_image_clip_draw_animation_stop();

            cui_image_clip_preview_draw();

            cui_image_clip_preview();
        }        
    }
    else
    {
        if(MMI_TRUE == g_imgclp->is_in_main)
        {
            mmi_popup_display((WCHAR*)GetString(STR_ID_IMAGE_CLIP_IMAGE_DECODE_FAILED), MMI_EVENT_FAILURE, NULL);
            cui_image_clip_send_result(MMI_FALSE);
            cui_image_clip_send_exit_req();
        }
    }

}

#define _IMAGE_CLIP_HANDLER

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_in
* DESCRIPTION
*  zoom in clip frame
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_in(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_get_last_frame();

    cui_image_clip_zoom_in_calculate_frame_wh();
    cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_CENTER);
    cui_image_clip_get_ball_pos();
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_update_frame_touch_rect();
    cui_image_clip_update_balls_touch_rect();
#endif
    cui_image_clip_redraw_clip();

    if((g_imgclp->adjust_count++) < IMAGE_CLIP_NOMAL_COUNT)
    {
        gui_start_timer(IMAGE_CLIP_ZOOM_TIME_DURATION,
                    cui_image_clip_zoom_in);
    }
    else
    {
        gui_start_timer(IMAGE_CLIP_FAST_ZOOM_TIME_DURATION,
                    cui_image_clip_zoom_in);
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_out
* DESCRIPTION
*  zoom out clip frame
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_out(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_get_last_frame();

    cui_image_clip_zoom_out_calculate_frame_wh();
    cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_CENTER);
    cui_image_clip_get_ball_pos();
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_update_frame_touch_rect();
    cui_image_clip_update_balls_touch_rect();
#endif
    cui_image_clip_redraw_clip();

    if((g_imgclp->adjust_count++) < IMAGE_CLIP_NOMAL_COUNT)
    {
        gui_start_timer(IMAGE_CLIP_ZOOM_TIME_DURATION,
                    cui_image_clip_zoom_out);
    }
    else
    {
        gui_start_timer(IMAGE_CLIP_FAST_ZOOM_TIME_DURATION,
                    cui_image_clip_zoom_out);
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_frame_move_left
* DESCRIPTION
*  move clip frame left
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_frame_move_left(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                    */
/*----------------------------------------------------------------*/
    U16 move_step;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_get_last_frame();

    if(g_imgclp->adjust_count < IMAGE_CLIP_NOMAL_COUNT)
    {
        move_step = IMAGE_CLIP_MOVE_STEP;
    }
    else
    {
        move_step = IMAGE_CLIP_MOVE_STEP * 2;
    }
    
    if(g_imgclp->btn_frame.rect.x - move_step>= g_imgclp->img_rect.x)
    {
        g_imgclp->btn_frame.rect.x -= move_step;
    }
    else
    {
        g_imgclp->btn_frame.rect.x = g_imgclp->img_rect.x;
    }

    cui_image_clip_get_ball_pos();
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_update_frame_touch_rect();
    cui_image_clip_update_balls_touch_rect();
#endif

    cui_image_clip_redraw_clip();

    if((g_imgclp->adjust_count++) < IMAGE_CLIP_NOMAL_COUNT)
    {
        gui_start_timer(IMAGE_CLIP_NOMAL_MOVE_DURATION,
                    cui_image_clip_frame_move_left);
    }
    else
    {
        gui_start_timer(IMAGE_CLIP_FAST_MOVE_DURATION,
                    cui_image_clip_frame_move_left);
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_frame_move_right
* DESCRIPTION
*  move clip frame right
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_frame_move_right(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                    */
/*----------------------------------------------------------------*/
    U16 move_step;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_get_last_frame();

    if(g_imgclp->adjust_count < IMAGE_CLIP_NOMAL_COUNT)
    {
        move_step = IMAGE_CLIP_MOVE_STEP;
    }
    else
    {
        move_step = IMAGE_CLIP_MOVE_STEP * 2;
    }
    
    if(g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w + move_step <= (g_imgclp->img_rect.x + g_imgclp->img_rect.w))
    {
        g_imgclp->btn_frame.rect.x += move_step;
    }
    else
    {
        g_imgclp->btn_frame.rect.x = (g_imgclp->img_rect.x + g_imgclp->img_rect.w) - g_imgclp->btn_frame.rect.w;
    }

    cui_image_clip_get_ball_pos();
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_update_frame_touch_rect();
    cui_image_clip_update_balls_touch_rect();
#endif

    cui_image_clip_redraw_clip();

    if((g_imgclp->adjust_count++) < IMAGE_CLIP_NOMAL_COUNT)
    {
        gui_start_timer(IMAGE_CLIP_NOMAL_MOVE_DURATION,
                    cui_image_clip_frame_move_right);
    }
    else
    {
        gui_start_timer(IMAGE_CLIP_FAST_MOVE_DURATION,
                    cui_image_clip_frame_move_right);
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_frame_move_up
* DESCRIPTION
*  move clip frame up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_frame_move_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                    */
/*----------------------------------------------------------------*/
    U16 move_step;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_get_last_frame();

    if(g_imgclp->adjust_count < IMAGE_CLIP_NOMAL_COUNT)
    {
        move_step = IMAGE_CLIP_MOVE_STEP;
    }
    else
    {
        move_step = IMAGE_CLIP_MOVE_STEP * 2;
    }
    
    if(g_imgclp->btn_frame.rect.y - move_step >= g_imgclp->img_rect.y)
    {
        g_imgclp->btn_frame.rect.y -= move_step;
    }
    else
    {
        g_imgclp->btn_frame.rect.y = g_imgclp->img_rect.y;
    }

    cui_image_clip_get_ball_pos();
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_update_frame_touch_rect();
    cui_image_clip_update_balls_touch_rect();
#endif

    cui_image_clip_redraw_clip();

    if((g_imgclp->adjust_count++) < IMAGE_CLIP_NOMAL_COUNT)
    {
        gui_start_timer(IMAGE_CLIP_NOMAL_MOVE_DURATION,
                    cui_image_clip_frame_move_up);
    }
    else
    {
        gui_start_timer(IMAGE_CLIP_FAST_MOVE_DURATION,
                    cui_image_clip_frame_move_up);
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_frame_move_down
* DESCRIPTION
*  move clip frame down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_frame_move_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                    */
/*----------------------------------------------------------------*/
    U16 move_step;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_get_last_frame();

    if(g_imgclp->adjust_count < IMAGE_CLIP_NOMAL_COUNT)
    {
        move_step = IMAGE_CLIP_MOVE_STEP;
    }
    else
    {
        move_step = IMAGE_CLIP_MOVE_STEP * 2;
    }
    
    if(g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h + move_step <= (g_imgclp->img_rect.y + g_imgclp->img_rect.h))
    {
        g_imgclp->btn_frame.rect.y += move_step;
    }
    else
    {
        g_imgclp->btn_frame.rect.y = (g_imgclp->img_rect.y + g_imgclp->img_rect.h) - g_imgclp->btn_frame.rect.h;
    }

    cui_image_clip_get_ball_pos();
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_update_frame_touch_rect();
    cui_image_clip_update_balls_touch_rect();
#endif

    cui_image_clip_redraw_clip();

    if((g_imgclp->adjust_count++) < IMAGE_CLIP_NOMAL_COUNT)
    {
        gui_start_timer(IMAGE_CLIP_NOMAL_MOVE_DURATION,
                    cui_image_clip_frame_move_down);
    }
    else
    {
        gui_start_timer(IMAGE_CLIP_FAST_MOVE_DURATION,
                    cui_image_clip_frame_move_down);
    }
    
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_in_btn_down
* DESCRIPTION
*  zoom in btn down handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_in_btn_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(g_imgclp->btn_zin.btn_bg.state == IMGCLP_BUTTON_DISABLE)
    {
        return;
    }
    
    g_imgclp->selected_obj = IMGCLP_BUTTON_ZOOM_IN;
    g_imgclp->btn_zin.btn_bg.state = IMGCLP_BUTTON_DOWN;

    g_imgclp->adjust_count = 0;
    
    cui_image_clip_zoom_in();

}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_in_btn_up
* DESCRIPTION
*  zoom in button up handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_in_btn_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
	gui_cancel_timer(cui_image_clip_zoom_in);

    if(g_imgclp->btn_zin.btn_bg.state == IMGCLP_BUTTON_DISABLE)
    {
        return;
    }

    g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    g_imgclp->btn_zin.btn_bg.state = IMGCLP_BUTTON_UP;

    if(MMI_TRUE == g_imgclp->is_in_main)
    {
        cui_image_clip_redraw_clip();
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_out_btn_down
* DESCRIPTION
*  zoom out button down handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_out_btn_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(g_imgclp->btn_zout.btn_bg.state == IMGCLP_BUTTON_DISABLE)
    {
        return;
    }

    g_imgclp->selected_obj = IMGCLP_BUTTON_ZOOM_OUT;
    g_imgclp->btn_zout.btn_bg.state = IMGCLP_BUTTON_DOWN;

    g_imgclp->adjust_count = 0;
    
    cui_image_clip_zoom_out();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_zoom_out_btn_up
* DESCRIPTION
*  zoom out button up handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_zoom_out_btn_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
	gui_cancel_timer(cui_image_clip_zoom_out);

    if(g_imgclp->btn_zout.btn_bg.state == IMGCLP_BUTTON_DISABLE)
    {
        return;
    }

    g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    g_imgclp->btn_zout.btn_bg.state = IMGCLP_BUTTON_UP;

    if(MMI_TRUE == g_imgclp->is_in_main)
    {
        cui_image_clip_redraw_clip();
    }
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  cui_image_clip_lt_ball_down
* DESCRIPTION
*  lt ball down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_lt_ball_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_LT_BALL;
    g_imgclp->btn_lt_ball.state = IMGCLP_BUTTON_DOWN;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_rt_ball_down
* DESCRIPTION
*  rt ball down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_rt_ball_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_RT_BALL;
    g_imgclp->btn_rt_ball.state = IMGCLP_BUTTON_DOWN;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_lb_ball_down
* DESCRIPTION
*  lb ball down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_lb_ball_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_LB_BALL;
    g_imgclp->btn_lb_ball.state = IMGCLP_BUTTON_DOWN;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_rb_ball_down
* DESCRIPTION
*  rb ball down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_rb_ball_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_RB_BALL;
    g_imgclp->btn_rb_ball.state = IMGCLP_BUTTON_DOWN;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_lt_ball_up
* DESCRIPTION
*  lt ball up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_lt_ball_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    g_imgclp->btn_lt_ball.state = IMGCLP_BUTTON_UP;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_rt_ball_up
* DESCRIPTION
*  lt ball up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_rt_ball_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    g_imgclp->btn_rt_ball.state = IMGCLP_BUTTON_UP;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_lb_ball_up
* DESCRIPTION
*  lb ball up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_lb_ball_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    g_imgclp->btn_lb_ball.state = IMGCLP_BUTTON_UP;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_rb_ball_up
* DESCRIPTION
*  rb ball up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_rb_ball_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    g_imgclp->btn_rb_ball.state = IMGCLP_BUTTON_UP;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_frame_btn_down
* DESCRIPTION
*  frame button down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_frame_btn_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_FRAME;
    g_imgclp->btn_frame.state = IMGCLP_BUTTON_DOWN;

    cui_image_clip_redraw_clip();
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_frame_btn_up
* DESCRIPTION
*  frame button up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_frame_btn_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    g_imgclp->btn_frame.state = IMGCLP_BUTTON_UP;

    cui_image_clip_redraw_clip();
}

#endif /* __MMI_TOUCH_SCREEN__ */
/*****************************************************************************
* FUNCTION
*  cui_image_clip_LSK_down
* DESCRIPTION
*  LSK down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_LSK_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    redraw_softkey(MMI_LEFT_SOFTKEY);

    gdi_layer_blt_previous(0, GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT -1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_RSK_down
* DESCRIPTION
*  RSK down
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_RSK_down(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    redraw_softkey(MMI_RIGHT_SOFTKEY);

    gdi_layer_blt_previous(0, GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT -1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_LSK_up
* DESCRIPTION
*  LSK up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_LSK_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    S32 x, y, w,h;
/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->clip_state = IMGCLP_STATE_SAVE;

    cui_image_clip_calculate_save_coordinate(&x, &y, &w, &h);

    cui_image_clip_draw_animation_start(MMI_FALSE);

    g_imgclp->img_decode_handle = gdi_imgdec_nb_draw_resized_file(g_imgclp->save_layer,
                                                                  x,
                                                                  y,
                                                                  w,
                                                                  h,
                                                                 (U8 *)g_imgclp->source_file,
                                                                  cui_image_clip_decode_save_img_callback
                                                                  );

    redraw_softkey(MMI_LEFT_SOFTKEY);

    cui_image_clip_register_key_handler_by_state();
    cui_image_clip_draw_soft_key();

    gdi_layer_blt_previous(0, GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT -1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_RSK_up
* DESCRIPTION
*  RSK up
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_RSK_up(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_send_exit_req();

    redraw_softkey(MMI_RIGHT_SOFTKEY);

    gdi_layer_blt_previous(0, GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT -1);
}


#define _IMAGE_CLIP_TOUCH_FUNCTIONS

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  cui_image_softkey_touch_pen_down_hdlr
* DESCRIPTION
*  soft key pen down hdlr
* PARAMETERS
*  pos    :   [IN] current pen position
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL cui_image_softkey_touch_pen_down_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_button_pen_enum button_event;
    mmi_pen_point_struct t_pos;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    t_pos.x = pos.x;
    t_pos.y = pos.y - (GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT);

    ret = translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_DOWN, t_pos.x, t_pos.y, &button_event);

    if(MMI_TRUE == ret)
    {
        g_imgclp->selected_obj = IMGCLP_BUTTON_LSK;

        if(GUI_BUTTON_PEN_DOWN == button_event)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
        }

        return ret;
    }

    ret = translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_DOWN, t_pos.x, t_pos.y, &button_event);

    if(MMI_TRUE == ret)
    {
        g_imgclp->selected_obj = IMGCLP_BUTTON_RSK;

        if(GUI_BUTTON_PEN_DOWN == button_event)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
        }
        return ret;
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  cui_image_softkey_touch_pen_up_hdlr
* DESCRIPTION
*  soft key pen up hdlr
* PARAMETERS
*  pos    :   [IN] current pen position
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL cui_image_softkey_touch_pen_up_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    mmi_pen_point_struct t_pos;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
	t_pos.x = pos.x;
    t_pos.y = pos.y - (GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT);


    switch(g_imgclp->selected_obj)
    {
        case IMGCLP_BUTTON_LSK:
            translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_UP, t_pos.x, t_pos.y, &button_event);
            if(GUI_BUTTON_PEN_UP_INSIDE == button_event)
            {
                execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
                g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
                return MMI_TRUE;
            }
            break;
        case IMGCLP_BUTTON_RSK:
            translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_UP, t_pos.x, t_pos.y, &button_event);
            if(GUI_BUTTON_PEN_UP_INSIDE == button_event)
            {
                execute_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
                g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
                return MMI_TRUE;
            }
            break;
        default:
            break;
    }

    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  cui_image_softkey_touch_pen_move_hdlr
* DESCRIPTION
*  soft key pen move hdlr
* PARAMETERS
*  pos    :   [IN] current pen position
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL cui_image_softkey_touch_pen_move_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    mmi_pen_point_struct t_pos;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    t_pos.x = pos.x;
    t_pos.y = pos.y - (GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT);

    switch(g_imgclp->selected_obj)
    {
        case IMGCLP_BUTTON_LSK:
            translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_MOVE, t_pos.x, t_pos.y, &button_event);
            show_left_softkey();
            gdi_layer_blt_previous(0, GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT -1);
            return MMI_TRUE;
            break;
        case IMGCLP_BUTTON_RSK:
            translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_MOVE, t_pos.x, t_pos.y, &button_event);
            show_right_softkey();
            gdi_layer_blt_previous(0, GDI_LCD_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT -1);
            return MMI_TRUE;
            break;
        default:
            break;
    }

    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_is_pos_in_rect
* DESCRIPTION
*  pen move hdlr
* PARAMETERS
*  pos    :   [IN] current pen position
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL cui_image_clip_is_pos_in_rect(cui_image_clip_rect_struct rect, mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/

    if(pos.x >= rect.x && pos.x <= (rect.x + rect.w) && 
       pos.y >= rect.y && pos.y <= (rect.y + rect.h))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_hit_object_test
* DESCRIPTION
*  test if obj was touched
* PARAMETERS
*  pos    :   [IN] current pen position
*  obj     :   [IN] clip button obj
* RETURNS
*  TRUE  : current obj was hit
*****************************************************************************/
static MMI_BOOL cui_image_clip_hit_object_test(cui_image_clip_button_enum obj, mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/

    mmi_pen_point_struct t_pos;

    switch(obj)
    {
        case IMGCLP_BUTTON_ZOOM_IN:
            t_pos.x = pos.x - g_imgclp->btn_zin.btn_bg.rect.x;
            t_pos.y = pos.y - g_imgclp->btn_zin.btn_bg.rect.y;
            if(cui_image_clip_is_pos_in_rect(g_imgclp->btn_zin.btn_bg.touch_rect, t_pos))
            {
                return MMI_TRUE;
            }
            break;
        case IMGCLP_BUTTON_ZOOM_OUT:
            t_pos.x = pos.x - g_imgclp->btn_zout.btn_bg.rect.x;
            t_pos.y = pos.y - g_imgclp->btn_zout.btn_bg.rect.y;

            if(cui_image_clip_is_pos_in_rect(g_imgclp->btn_zout.btn_bg.touch_rect, t_pos))
            {
                return MMI_TRUE;
            }
            break;
        case IMGCLP_BUTTON_LT_BALL:
            t_pos.x = pos.x - g_imgclp->btn_lt_ball.rect.x;
            t_pos.y = pos.y - g_imgclp->btn_lt_ball.rect.y;

            if(cui_image_clip_is_pos_in_rect(g_imgclp->btn_lt_ball.touch_rect, t_pos))
            {
                return MMI_TRUE;
            }
            break;
        case IMGCLP_BUTTON_RT_BALL:
            t_pos.x = pos.x - g_imgclp->btn_rt_ball.rect.x;
            t_pos.y = pos.y - g_imgclp->btn_rt_ball.rect.y;

            if(cui_image_clip_is_pos_in_rect(g_imgclp->btn_rt_ball.touch_rect, t_pos))
            {
               return MMI_TRUE;
            }
            break;
        case IMGCLP_BUTTON_LB_BALL:
            t_pos.x = pos.x - g_imgclp->btn_lb_ball.rect.x;
            t_pos.y = pos.y - g_imgclp->btn_lb_ball.rect.y;

            if(cui_image_clip_is_pos_in_rect(g_imgclp->btn_lb_ball.touch_rect, t_pos))
            {
               return MMI_TRUE;
            }
            break;
        case IMGCLP_BUTTON_RB_BALL:
            t_pos.x = pos.x - g_imgclp->btn_rb_ball.rect.x;
            t_pos.y = pos.y - g_imgclp->btn_rb_ball.rect.y;

            if(cui_image_clip_is_pos_in_rect(g_imgclp->btn_rb_ball.touch_rect, t_pos))
            {
               return MMI_TRUE;
            }
            break;
        case IMGCLP_BUTTON_FRAME:
            t_pos.x = pos.x - g_imgclp->btn_frame.rect.x;
            t_pos.y = pos.y - g_imgclp->btn_frame.rect.y;

            if(cui_image_clip_is_pos_in_rect(g_imgclp->btn_frame.touch_rect, t_pos))
            {
               return MMI_TRUE;
            }
            break;

        default:
            break;
    }

    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_pen_down_hdlr
* DESCRIPTION
*  test if obj was touched
* PARAMETERS
*  pos    :   [IN] current pen position
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_pen_down_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL is_find = MMI_FALSE;
    MMI_BOOL ret;

    S32 icon_id;
    wgui_status_icon_bar_pen_enum event_type;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    ret = wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_DOWN,
                                                   pos.x,
                                                   pos.y,
                                                   &icon_id,
                                                   &event_type
                                                   );
    if(MMI_TRUE == ret)
    {
        return;
    }
    
    ret = cui_image_softkey_touch_pen_down_hdlr(pos);
    if(MMI_TRUE == ret)
    {
        return;
    }

    if(MMI_FALSE == g_imgclp->is_osd_valid)
    {
        return;
    }

	if(IMGCLP_STATE_EDIT != g_imgclp->clip_state)
	{
	    return;
	}

    g_imgclp->last_point.x = pos.x;
    g_imgclp->last_point.y = pos.y;

    for(i = IMGCLP_BUTTON_ZOOM_IN; i < IMGCLP_BUTTON_COUNT; i++)
    {
        switch(i)
        {
            case IMGCLP_BUTTON_ZOOM_IN:
                if(cui_image_clip_hit_object_test(IMGCLP_BUTTON_ZOOM_IN, pos))
                {
                    cui_image_clip_zoom_in_btn_down();
                    is_find = MMI_TRUE;
                }
                break;
            case IMGCLP_BUTTON_ZOOM_OUT:
                if(cui_image_clip_hit_object_test(IMGCLP_BUTTON_ZOOM_OUT, pos))
                {
                    cui_image_clip_zoom_out_btn_down();
                    is_find = MMI_TRUE;
                }
                break;
            case IMGCLP_BUTTON_LT_BALL:
                if(cui_image_clip_hit_object_test(IMGCLP_BUTTON_LT_BALL, pos))
                {
                    cui_image_clip_lt_ball_down();
                    is_find = MMI_TRUE;
                }
                break;
            case IMGCLP_BUTTON_RT_BALL:
                if(cui_image_clip_hit_object_test(IMGCLP_BUTTON_RT_BALL, pos))
                {
                    cui_image_clip_rt_ball_down();
                    is_find = MMI_TRUE;
                }
                break;

            case IMGCLP_BUTTON_LB_BALL:
                if(cui_image_clip_hit_object_test(IMGCLP_BUTTON_LB_BALL, pos))
                {
                    cui_image_clip_lb_ball_down();
                    is_find = MMI_TRUE;
                }
                break;
            case IMGCLP_BUTTON_RB_BALL:
                if(cui_image_clip_hit_object_test(IMGCLP_BUTTON_RB_BALL, pos))
                {
                    cui_image_clip_rb_ball_down();
                    is_find = MMI_TRUE;
                }
                break;
            case IMGCLP_BUTTON_FRAME:
                if(cui_image_clip_hit_object_test(IMGCLP_BUTTON_FRAME, pos))
                {
                    cui_image_clip_frame_btn_down();
                    is_find = MMI_TRUE;
                }
                break;
            default:
                break;
        }
        if(is_find == MMI_TRUE)
           break;
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_pen_up_hdlr
* DESCRIPTION
*  pen up handler
* PARAMETERS
*  pos    :   [IN] current pen position
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_pen_up_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 icon_id;
    wgui_status_icon_bar_pen_enum event_type;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    ret = wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_UP,
                                                   pos.x,
                                                   pos.y,
                                                   &icon_id,
                                                   &event_type
                                                   );
    if(MMI_TRUE == ret)
    {
        return;
    }
    
    ret = cui_image_softkey_touch_pen_up_hdlr(pos);
    if(MMI_TRUE == ret)
    {
        return;
    }

    if(MMI_FALSE == g_imgclp->is_osd_valid)
    {
        return;
    }

    if(IMGCLP_STATE_EDIT != g_imgclp->clip_state)
    {
        return;
    }

    switch(g_imgclp->selected_obj)
    {
        case IMGCLP_BUTTON_ZOOM_IN:
            cui_image_clip_zoom_in_btn_up();
            break;
       case IMGCLP_BUTTON_ZOOM_OUT:
            cui_image_clip_zoom_out_btn_up();
            break;
       case IMGCLP_BUTTON_LT_BALL:
            cui_image_clip_lt_ball_up();
            break;
       case IMGCLP_BUTTON_RT_BALL:
            cui_image_clip_rt_ball_up();
            break;
       case IMGCLP_BUTTON_LB_BALL:
            cui_image_clip_lb_ball_up();
            break;
       case IMGCLP_BUTTON_RB_BALL:
            cui_image_clip_rb_ball_up();
            break;
       case IMGCLP_BUTTON_FRAME:
            cui_image_clip_frame_btn_up();
            break;
       default:
            break;
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_pen_move_hdlr
* DESCRIPTION
*  pen move handler
* PARAMETERS
*  pos    :   [IN] current pen position
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_pen_move_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 icon_id;
    wgui_status_icon_bar_pen_enum event_type;
    
/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    ret = wgui_status_icon_bar_translate_pen_event(MMI_PEN_EVENT_MOVE,
                                                   pos.x,
                                                   pos.y,
                                                   &icon_id,
                                                   &event_type
                                                   );
    if(MMI_TRUE == ret)
    {
        return;
    }
    
    ret = cui_image_softkey_touch_pen_move_hdlr(pos);
    if(MMI_TRUE == ret)
    {
        return;
    }

    if(MMI_FALSE == g_imgclp->is_osd_valid)
    {
        return;
    }

    if(IMGCLP_STATE_EDIT != g_imgclp->clip_state)
    {
        return;
    }

    switch(g_imgclp->selected_obj)
    {
        case IMGCLP_BUTTON_FRAME:
            cui_image_clip_get_last_frame();
            if((g_imgclp->btn_frame.rect.x + (pos.x - g_imgclp->last_point.x)) <= g_imgclp->img_rect.x)
                
            {
                g_imgclp->btn_frame.rect.x = g_imgclp->img_rect.x;
            }
            else if((g_imgclp->btn_frame.rect.x + (pos.x - g_imgclp->last_point.x) + g_imgclp->btn_frame.rect.w) >= (g_imgclp->img_rect.x + g_imgclp->img_rect.w))
            {
                g_imgclp->btn_frame.rect.x = g_imgclp->img_rect.x + g_imgclp->img_rect.w - g_imgclp->btn_frame.rect.w;
            }
            else
            {
                g_imgclp->btn_frame.rect.x += (pos.x - g_imgclp->last_point.x);
            }

            if((g_imgclp->btn_frame.rect.y + (pos.y - g_imgclp->last_point.y)) < g_imgclp->img_rect.y)
            {
                g_imgclp->btn_frame.rect.y = g_imgclp->img_rect.y;
            }
            else if((g_imgclp->btn_frame.rect.y + (pos.y - g_imgclp->last_point.y) + g_imgclp->btn_frame.rect.h) >= (g_imgclp->img_rect.y + g_imgclp->img_rect.h))
            {
                g_imgclp->btn_frame.rect.y = g_imgclp->img_rect.y + g_imgclp->img_rect.h - g_imgclp->btn_frame.rect.h;
            }
            else
            {
                g_imgclp->btn_frame.rect.y += (pos.y - g_imgclp->last_point.y);
            }
            
            g_imgclp->last_point.x = pos.x;
            g_imgclp->last_point.y = pos.y;

            cui_image_clip_update_frame_touch_rect();
            cui_image_clip_get_ball_pos();
            cui_image_clip_update_balls_touch_rect();

            cui_image_clip_redraw_clip();
            break;
        case IMGCLP_BUTTON_LT_BALL:
            if(pos.x < g_imgclp->btn_frame.rect.x && pos.y < g_imgclp->btn_frame.rect.y)
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_in_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_LT);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            else if(pos.x > g_imgclp->btn_frame.rect.x && pos.y > g_imgclp->btn_frame.rect.y)
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_out_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_LT);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            break;
        case IMGCLP_BUTTON_RT_BALL:
            if(pos.x > (g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w) &&
               pos.y < g_imgclp->btn_frame.rect.y)
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_in_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_RT);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            else if(pos.x < (g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w) &&
                    pos.y > g_imgclp->btn_frame.rect.y)
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_out_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_RT);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            break;
        case IMGCLP_BUTTON_LB_BALL:
            if(pos.x < g_imgclp->btn_frame.rect.x &&
               pos.y > (g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h))
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_in_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_LB);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            else if(pos.x > g_imgclp->btn_frame.rect.x &&
                    pos.y < (g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h))
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_out_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_LB);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            break;
        case IMGCLP_BUTTON_RB_BALL:
            if(pos.x > (g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w) &&
               pos.y > (g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h))
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_in_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_RB);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            else if(pos.x < (g_imgclp->btn_frame.rect.x + g_imgclp->btn_frame.rect.w) &&
                    pos.y < (g_imgclp->btn_frame.rect.y + g_imgclp->btn_frame.rect.h))
            {
                cui_image_clip_get_last_frame();
                cui_image_clip_zoom_out_calculate_frame_wh();
                cui_image_clip_get_zoom_frame_pos(IMGCLP_DIRECT_RB);
                cui_image_clip_update_frame_touch_rect();
                cui_image_clip_get_ball_pos();
                cui_image_clip_update_balls_touch_rect();
                cui_image_clip_redraw_clip();
            }
            break;
        default:
            break;
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */

#define _IMAGE_CLIP_LOGIC_FUNCTION

/*****************************************************************************
* FUNCTION
*  cui_image_clip_reset_button_state_and_cancel_timers
* DESCRIPTION
*  reset button state if is pressed and cacel timers
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void cui_image_clip_reset_button_state_and_cancel_timers(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/   

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
    if(g_imgclp->selected_obj != IMGCLP_BUTTON_NONE)
    {
        g_imgclp->selected_obj = IMGCLP_BUTTON_NONE;
    }

    if(IMGCLP_BUTTON_DOWN == g_imgclp->btn_frame.state)
    {
        g_imgclp->btn_frame.state = IMGCLP_BUTTON_UP;
    }

    if(IMGCLP_BUTTON_DOWN == g_imgclp->btn_lt_ball.state)
    {
        g_imgclp->btn_lt_ball.state = IMGCLP_BUTTON_UP;
    }

    if(IMGCLP_BUTTON_DOWN == g_imgclp->btn_rt_ball.state)
    {
        g_imgclp->btn_rt_ball.state = IMGCLP_BUTTON_UP;
    }

    if(IMGCLP_BUTTON_DOWN == g_imgclp->btn_lb_ball.state)
    {
        g_imgclp->btn_lb_ball.state = IMGCLP_BUTTON_UP;
    }

    if(IMGCLP_BUTTON_DOWN == g_imgclp->btn_rb_ball.state)
    {
        g_imgclp->btn_rb_ball.state = IMGCLP_BUTTON_UP;
    }

    if(IMGCLP_BUTTON_DOWN == g_imgclp->btn_zin.btn_bg.state)
    {
        g_imgclp->btn_zin.btn_bg.state = IMGCLP_BUTTON_UP;
    }

    if(IMGCLP_BUTTON_DOWN == g_imgclp->btn_zout.btn_bg.state)
    {
        g_imgclp->btn_zout.btn_bg.state = IMGCLP_BUTTON_UP;
    }

    {
        gui_cancel_timer(cui_image_clip_zoom_in);
        gui_cancel_timer(cui_image_clip_zoom_out);
        gui_cancel_timer(cui_image_clip_frame_move_left);
        gui_cancel_timer(cui_image_clip_frame_move_right);
        gui_cancel_timer(cui_image_clip_frame_move_up);
        gui_cancel_timer(cui_image_clip_frame_move_down);
    }

    restore_softkeys();
}


/*****************************************************************************
* FUNCTION
*  cui_image_clip_fmgr_notify_handler
* DESCRIPTION
*  receive card plug out message
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret cui_image_clip_fmgr_notify_handler(mmi_event_struct* evt)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/   
    U16 *p;

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
    if(NULL == g_imgclp)
    {
        return MMI_RET_OK;
    }

    switch(evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            p = (U16*) mmi_wcschr(g_imgclp->source_file, (U16) ':');
            if(SRV_FMGR_CARD_DRV == *(p-1))
            {
                cui_image_clip_send_result(MMI_FALSE);
                cui_image_clip_send_exit_req();
            }
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  cui_image_clip_back_to_edit
* DESCRIPTION
*  back to edit screen from preview
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_back_to_edit(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/   

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
    if(IMGCLP_STATE_SAVE == g_imgclp->clip_state)
    {
        if(NULL != g_imgclp->anim_handle)
        {
            gdi_image_stop_animation(g_imgclp->anim_handle);
            g_imgclp->anim_handle = GDI_NULL_HANDLE;
        }

        if(IMGCLP_STATE_SAVE == g_imgclp->clip_state)
        {
            gdi_imgdec_nb_stop(g_imgclp->img_decode_handle);
            g_imgclp->img_decode_handle = GDI_NULL_HANDLE;
        }
    }

    g_imgclp->clip_state = IMGCLP_STATE_EDIT;

    if(g_imgclp->save_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_imgclp->save_layer);
        g_imgclp->save_layer = GDI_NULL_HANDLE;
    }

    gdi_layer_set_blt_layer(g_imgclp->clip_layer,
                            g_imgclp->status_bar_layer,
                            g_imgclp->soft_key_layer,
                            0);

    cui_image_clip_draw_clip_layer();

    if(g_imgclp->real_save_size.height > g_clip_skin_struct.work_rect.h)
    {
        gdi_layer_push_and_set_active(g_imgclp->status_bar_layer);
        gdi_layer_set_opacity(MMI_TRUE, 255);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(g_imgclp->soft_key_layer);
        gdi_layer_set_opacity(MMI_TRUE, 255);
        gdi_layer_pop_and_restore_active();
    }

    cui_image_clip_draw_status_icon_bar();

    cui_image_clip_register_key_handler_by_state();
    cui_image_clip_draw_soft_key();
   
    gdi_layer_blt_previous(0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_check_file_type
* DESCRIPTION
*  check if current file equal to test file type
* PARAMETERS
*  file     :    [IN] file path
*  strtype  :  [IN] file type str
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL cui_image_clip_check_file_type(const U16 *file, const U16 *strtype)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/
    U16 *ext;

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
    ext = (U16*) mmi_wcsrchr(file, (U16) '.');

    if (ext)
    {
        if (0 == mmi_wcsicmp(ext, strtype))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_context
* DESCRIPTION
*  init basic functions for image clip
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_context(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    g_imgclp->is_decoding = MMI_FALSE;
    g_imgclp->is_osd_valid = MMI_FALSE;
    g_imgclp->is_resized = MMI_FALSE;
    g_imgclp->is_run = MMI_FALSE;

    g_imgclp->img_decode_handle = GDI_NULL_HANDLE;

    g_imgclp->is_in_main = MMI_FALSE;

    g_imgclp->adjust_count = 0;

    g_imgclp->clip_state = IMGCLP_STATE_LOAD;
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_zoom_btn
* DESCRIPTION
*  init zoom button info
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_zoom_btn(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    g_imgclp->btn_zin.btn_bg.rect.x = g_clip_skin_struct.zin_btn_bg.x;
    g_imgclp->btn_zin.btn_bg.rect.y = g_clip_skin_struct.zin_btn_bg.y;

    g_imgclp->btn_zin.btn_bg.rect.w = g_clip_skin_struct.zin_btn_bg.w;
    g_imgclp->btn_zin.btn_bg.rect.h = g_clip_skin_struct.zin_btn_bg.h;

    g_imgclp->btn_zin.btn_content.x = g_clip_skin_struct.zin_btn_content.x;
    g_imgclp->btn_zin.btn_content.y = g_clip_skin_struct.zin_btn_content.y;

    g_imgclp->btn_zout.btn_bg.rect.x = g_clip_skin_struct.zout_btn_bg.x;
    g_imgclp->btn_zout.btn_bg.rect.y = g_clip_skin_struct.zout_btn_bg.y;

    g_imgclp->btn_zout.btn_bg.rect.w = g_clip_skin_struct.zout_btn_bg.w;
    g_imgclp->btn_zout.btn_bg.rect.h = g_clip_skin_struct.zout_btn_bg.h;

    g_imgclp->btn_zout.btn_content.x = g_clip_skin_struct.zout_btn_content.x;
    g_imgclp->btn_zout.btn_content.y = g_clip_skin_struct.zout_btn_content.y;

#else /* __MMI_FTE_SUPPORT__ */
    g_imgclp->btn_zin.btn_bg.rect.x = g_clip_skin_struct.zin_btn.x;
    g_imgclp->btn_zin.btn_bg.rect.y = g_clip_skin_struct.zin_btn.y;

    g_imgclp->btn_zin.btn_bg.rect.w = g_clip_skin_struct.zin_btn.w;
    g_imgclp->btn_zin.btn_bg.rect.h = g_clip_skin_struct.zin_btn.h;

    g_imgclp->btn_zout.btn_bg.rect.x = g_clip_skin_struct.zout_btn.x;
    g_imgclp->btn_zout.btn_bg.rect.y = g_clip_skin_struct.zout_btn.y;

    g_imgclp->btn_zout.btn_bg.rect.w = g_clip_skin_struct.zout_btn.w;
    g_imgclp->btn_zout.btn_bg.rect.h = g_clip_skin_struct.zout_btn.h;
#endif /* __MMI_FTE_SUPPORT__ */


#ifdef __MMI_TOUCH_SCREEN__
    g_imgclp->btn_zin.btn_bg.touch_rect.x = 1;
    g_imgclp->btn_zin.btn_bg.touch_rect.y = 1;
    g_imgclp->btn_zin.btn_bg.touch_rect.w = g_imgclp->btn_zin.btn_bg.rect.w - 1;
    g_imgclp->btn_zin.btn_bg.touch_rect.h = g_imgclp->btn_zin.btn_bg.rect.h - 1;

    g_imgclp->btn_zout.btn_bg.touch_rect.x = 1;
    g_imgclp->btn_zout.btn_bg.touch_rect.y = 1;
    g_imgclp->btn_zout.btn_bg.touch_rect.w = g_imgclp->btn_zout.btn_bg.rect.w - 1;
    g_imgclp->btn_zout.btn_bg.touch_rect.h = g_imgclp->btn_zout.btn_bg.rect.h - 1;
#endif
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_clip_layer_layout
* DESCRIPTION
*  init clip layer layout
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_clip_layer_layout(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_get_image_rect();
    cui_image_clip_init_frame_info();
    cui_image_clip_get_ball_pos();
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_update_frame_touch_rect();
    cui_image_clip_update_balls_touch_rect();
#endif
    cui_image_clip_init_zoom_btn();
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_init_entry
* DESCRIPTION
*  init entry functions
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_init_entry(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    cui_image_clip_init_layers_mem();
    cui_image_clip_init_clip_layer_layout();
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_entry_screen_active
* DESCRIPTION
*  screen active function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_entry_screen_active(void)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_SCRN_ACTIVE, __LINE__);

    g_imgclp->is_in_main = MMI_TRUE;

    cui_image_clip_draw_status_icon_bar();

    cui_image_clip_register_key_handler_by_state();
    cui_image_clip_draw_soft_key();
    
    switch(g_imgclp->clip_state)
    {
        case IMGCLP_STATE_LOAD:
            cui_image_clip_draw_animation_start(MMI_TRUE);
            if(g_imgclp->is_decoding != MMI_TRUE)
            {
                cui_image_clip_decode_image();
            }            
            break;
        case IMGCLP_STATE_EDIT:
            cui_image_clip_draw_clip_layer();
            break;
        case IMGCLP_STATE_PREVIEW:
            cui_image_clip_preview_draw();
            cui_image_clip_preview();
            break;
        default:
            break;
    }

    gdi_layer_blt_previous(0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(cui_image_clip_pen_down_hdlr);
    mmi_pen_register_up_handler(cui_image_clip_pen_up_hdlr);
    mmi_pen_register_move_handler(cui_image_clip_pen_move_hdlr);
#endif
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_key_proc
* DESCRIPTION
*  main screen key proc function
* PARAMETERS
*  p_key    :  [IN] key_event
* RETURNS
*  void
*****************************************************************************/

static mmi_ret cui_image_clip_key_proc(mmi_frm_key_evt_struct* p_key)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_IMAGE_CLIP_MSG_TRACE(p_key->key_code);

    if((p_key->key_type == KEY_EVENT_UP) && 
       (p_key->key_code == KEY_ENTER) && 
       (IMGCLP_STATE_PREVIEW == g_imgclp->clip_state))
    {
        cui_image_clip_done_and_send_succeed_msg();
        return MMI_RET_OK;
    }

    if(IMGCLP_STATE_EDIT != g_imgclp->clip_state)
    {
        return MMI_RET_OK;
    }

    if(p_key->key_type == KEY_EVENT_UP)
    {
        switch(p_key->key_code)
        {
            case KEY_1:
                cui_image_clip_zoom_in_btn_up();
                break;
            case KEY_3:
                cui_image_clip_zoom_out_btn_up();
                break;
            case KEY_LEFT_ARROW:
                gui_cancel_timer(cui_image_clip_frame_move_left);
                break;
            case KEY_RIGHT_ARROW:
                gui_cancel_timer(cui_image_clip_frame_move_right);
                break;
            case KEY_UP_ARROW:
                gui_cancel_timer(cui_image_clip_frame_move_up);
                break;
            case KEY_DOWN_ARROW:
                gui_cancel_timer(cui_image_clip_frame_move_down);
                break;
            case KEY_ENTER:
                cui_image_clip_LSK_up();
                break;
            default:
                break;
        }
    }
    else if(p_key->key_type == KEY_EVENT_DOWN)
    {
        switch(p_key->key_code)
        {
            case KEY_1:
                cui_image_clip_zoom_in_btn_down();
                break;
            case KEY_3:
                cui_image_clip_zoom_out_btn_down();
                break;
            case KEY_LEFT_ARROW:
                g_imgclp->adjust_count = 0;
                cui_image_clip_frame_move_left();
                break;
            case KEY_RIGHT_ARROW:
                g_imgclp->adjust_count = 0;
                cui_image_clip_frame_move_right();
                break;
            case KEY_UP_ARROW:
                g_imgclp->adjust_count = 0;
                cui_image_clip_frame_move_up();
                break;
            case KEY_DOWN_ARROW:
                g_imgclp->adjust_count = 0;
                cui_image_clip_frame_move_down();
                break;
            default:
                break;
        }
    }

    return MMI_RET_OK;
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_scrn_proc
* DESCRIPTION
*  main screen proc function
* PARAMETERS
*  evt   :  [IN] event structure
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_image_clip_scrn_proc(mmi_event_struct* evt)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_INIT:
            cui_image_clip_init_entry();
            break;
        case EVT_ID_SCRN_ACTIVE:
            cui_image_clip_get_layer_buf_active();
            cui_image_clip_init_layers_active();
            cui_image_clip_entry_screen_active();
        #ifdef __MMI_TOUCH_SCREEN__
            mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
        #endif
            break;
        case EVT_ID_SCRN_INACTIVE:
            g_imgclp->is_in_main = MMI_FALSE;

        #ifdef __MMI_TOUCH_SCREEN__
            mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
        #endif

            if(NULL != g_imgclp->anim_handle)
            {
                gdi_image_stop_animation(g_imgclp->anim_handle);
                g_imgclp->anim_handle = GDI_NULL_HANDLE;
            }

            if(IMGCLP_STATE_SAVE == g_imgclp->clip_state)
            {
                gdi_imgdec_nb_stop(g_imgclp->img_decode_handle);
                g_imgclp->img_decode_handle = GDI_NULL_HANDLE;

                g_imgclp->clip_state = IMGCLP_STATE_EDIT;
            }

            cui_image_clip_reset_button_state_and_cancel_timers();

            cui_image_clip_free_layer_buf_inactive();
            break;
        case EVT_ID_SCRN_DEINIT:
            if(g_imgclp->img_decode_handle != GDI_NULL_HANDLE)
            {
                gdi_imgdec_nb_stop(g_imgclp->img_decode_handle);
                g_imgclp->img_decode_handle = GDI_NULL_HANDLE;
            }
            cui_image_clip_free_layers_mem();
            break;
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct* p_key = (mmi_frm_key_evt_struct*) evt;

            return cui_image_clip_key_proc(p_key);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_entry_screen
* DESCRIPTION
*  entry screen function
* PARAMETERS
*  parent_id   :  [IN] parent group id
* RETURNS
*  void
*****************************************************************************/
static void cui_image_clip_entry_screen(mmi_id parent_id)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    mmi_frm_scrn_create(parent_id,
                        SCR_ID_IMAGE_CLIP_MAIN,
                        cui_image_clip_scrn_proc,
                        NULL);
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_group_proc
* DESCRIPTION
*  group proc
* PARAMETERS
*  evt   :  [IN] event structure
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_image_clip_group_proc(mmi_event_struct* evt)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            cui_image_clip_free_mem();
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

#define _IMAGE_CLIP_MAIN_FUNCTIONS
/*****************************************************************************
* FUNCTION
*  cui_image_clip_create
* DESCRIPTION
*  create image clip cui
* PARAMETERS
*  parent_id    :   [IN] parent group id for image clip cui
*  setting       :   [IN] basic setting for image clip cui
*  user_data   :   [IN] data address that needed save by image clip cui
* RETURNS
*  image clip cui group id
*****************************************************************************/
mmi_id cui_image_clip_create(mmi_id parent_id, WCHAR *source_file, void *user_data)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    MMI_ID cui_gid;

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_CREATE, __LINE__); 

    if(MMI_FALSE == cui_image_clip_is_file_format_supported(source_file))
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), MMI_EVENT_FAILURE, NULL);
        return GRP_ID_INVALID;
    }

    if(NULL != g_imgclp)
    {
        mmi_popup_display((WCHAR*)GetString(STR_ID_IMAGE_CLIP_PLEASE_CLOSE_ANOTHER), MMI_EVENT_FAILURE, NULL);
        return GRP_ID_INVALID;
    }
 
    cui_gid = mmi_frm_group_create_ex(parent_id,
                                      GRP_ID_AUTO_GEN,
                                      cui_image_clip_group_proc,
                                      NULL,
                                      MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if(GRP_ID_INVALID == cui_gid)
    {
        return GRP_ID_INVALID;
    }

    cui_image_clip_prepare_mem(cui_gid);
    cui_image_clip_alloc_mem();


    MMI_IMAGE_CLIP_MSG_TRACE(cui_gid);

    g_imgclp->cui_gid = cui_gid;
    wcscpy(g_imgclp->source_file, source_file);
    g_imgclp->user_data = user_data;

    cui_image_clip_init_context();

    return cui_gid;
}
/*****************************************************************************
* FUNCTION
*   cui_image_clip_set_dest_file_path
* DESCRIPTION
*   set expected file path to save file, should be called before cui_image_cip_run(); if this function
*   was not called, image clip cui will generate a file for caller and return with event
* PARAMETERS
*   cui_gid      :   [IN] group id of image clip cui
*   filepath     :    [IN] file path
* RETURNS
*  void
*****************************************************************************/

void cui_image_clip_set_dest_file_path(mmi_id cui_id, WCHAR* filepath)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if((g_imgclp->cui_gid == cui_id) && (MMI_FALSE == g_imgclp->is_run))
    {
        wcscpy(g_imgclp->dest_file, filepath);
    }
}
/*****************************************************************************
* FUNCTION
*   cui_image_clip_set_dest_size
* DESCRIPTION
*   set expected saved file size, should be called before cui_image_clip_run(); this function must
*   be called
* PARAMETERS
*   cui_gid      :   [IN] group id of image clip cui
*   width        :   [IN] expected file width
*   height       :   [IN] expected file height
* RETURNS
*  void
*****************************************************************************/

void cui_image_clip_set_dest_size(mmi_id cui_id, U16 width, U16 height)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_SET_DEST_SIZE, __LINE__, width, height);
    
    if((g_imgclp->cui_gid == cui_id) && (MMI_FALSE == g_imgclp->is_run))
    {
    g_imgclp->dest_size.width = width;
    g_imgclp->dest_size.height = height;

    g_imgclp->w_ratio = width;
    g_imgclp->h_ratio = height;
    }
}

/*****************************************************************************
* FUNCTION
*  cui_image_clip_run
* DESCRIPTION
*  start to run image clip cui
* PARAMETERS
*  cui_gid      :   [IN] group id of image clip cui
* RETURNS
*  void
*****************************************************************************/

void cui_image_clip_run(mmi_id cui_gid)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_RUN, __LINE__);

    MMI_ASSERT((g_imgclp->dest_size.width != 0) && (g_imgclp->dest_size.height != 0));

    g_imgclp->is_run = MMI_TRUE;
    
    cui_image_clip_entry_screen(cui_gid);
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_close
* DESCRIPTION
*  caller can close cui when received EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST
* PARAMETERS
*  cui_gid      :   [IN] group id of image clip cui
* RETURNS
*  void
*****************************************************************************/

void cui_image_clip_close(mmi_id cui_gid)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_CLOSE, __LINE__);

    mmi_frm_group_close(cui_gid);
}
/*****************************************************************************
* FUNCTION
*  cui_image_clip_is_file_format_supported
* DESCRIPTION
*  check if support the image format
* PARAMETERS
*  filepath         [IN]
* RETURNS
*  support or not
*****************************************************************************/
MMI_BOOL cui_image_clip_is_file_format_supported(WCHAR *filepath)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                                                     */
/*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
/*----------------------------------------------------------------*/
/* Code Body                                                                                           */
/*----------------------------------------------------------------*/
    if(MMI_TRUE == cui_image_clip_check_file_type(filepath,IMAGE_CLIP_FILE_JPG))
    {
        return MMI_TRUE;
    }

    if(MMI_TRUE == cui_image_clip_check_file_type(filepath,IMAGE_CLIP_FILE_PNG))
    {
        return MMI_TRUE;
    }

    if(MMI_TRUE == cui_image_clip_check_file_type(filepath,IMAGE_CLIP_FILE_GIF))
    {
        return MMI_TRUE;
    }

    if(MMI_TRUE == cui_image_clip_check_file_type(filepath,IMAGE_CLIP_FILE_BMP))
    {
        return MMI_TRUE;
    }

    return ret;
}

#endif /* __MMI_IMAGE_CLIP_CUI__ */
