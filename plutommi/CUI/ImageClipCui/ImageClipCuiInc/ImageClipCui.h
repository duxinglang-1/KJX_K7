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
 *  ImageClipCui.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Clip Cui head file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#ifndef IMAGECLIPCUI_H
#define IMAGECLIPCUI_H
#include "MMI_features.h"

#ifdef __MMI_IMAGE_CLIP_CUI__

#include "MMIDataType.h"
#include "gdi_include.h"

#include "ImageClipCuiGprot.h"

#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define IMAGE_CLIP_BITS_PER_PIXEL       (24)
#define IMAGE_CLIP_CURRENT_COLOR_FORMAT (GDI_COLOR_FORMAT_24)
#else
#define IMAGE_CLIP_BITS_PER_PIXEL       (GDI_MAINLCD_BIT_PER_PIXEL)
#define IMAGE_CLIP_CURRENT_COLOR_FORMAT (GDI_COLOR_FORMAT_16)
#endif

#define IMAGE_CLIP_DECODE_LAYER_MEM_SIZE ((IMAGE_CLIP_BITS_PER_PIXEL * GDI_LCD_WIDTH * GDI_LCD_HEIGHT)>>3)
#define IMAGE_CLIP_STATUS_BAR_LAYER_MEM_SIZE ((IMAGE_CLIP_BITS_PER_PIXEL * GDI_LCD_WIDTH * MMI_STATUS_BAR_HEIGHT)>>3)
#define IMAGE_CLIP_SOFT_KEY_BAR_LAYER_MEM_SIZE ((IMAGE_CLIP_BITS_PER_PIXEL * GDI_LCD_WIDTH * MMI_SOFTKEY_BAR_HEIGHT)>>3)

#define CUI_IMAGE_CLIP_FULL_FILE_PATH_LEN SRV_FMGR_PATH_BUFFER_SIZE

#define IMAGE_CLIP_MIN_LENGTH (30)

#define IMAGE_CLIP_BALL_TOUCH_ADJUST (5)

#define IMAGE_CLIP_ZOOM_STEP_PERCENT (2)

#define IMAGE_CLIP_MOVE_STEP (3)

#define IMAGE_CLIP_INIT_FRAME_PERCENT (50)

#define IMAGE_CLIP_NOMAL_COUNT (3)
#define IMAGE_CLIP_ZOOM_TIME_DURATION (140)
#define IMAGE_CLIP_FAST_ZOOM_TIME_DURATION (70)

#define IMAGE_CLIP_NOMAL_MOVE_DURATION (140)
#define IMAGE_CLIP_FAST_MOVE_DURATION (70)


#define IMAGE_CLIP_DEFAULT_PATH     L":\\Photos\\"
#define IMAGE_CLIP_FILE_JPG        L".jpg"
#define IMAGE_CLIP_FILE_PNG        L".png"
#define IMAGE_CLIP_FILE_GIF        L".gif"
#define IMAGE_CLIP_FILE_BMP        L".bmp"

#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
    #define IMAGE_CLIP_ZIN_BG_IMG (current_MMI_theme->icon_bar_item_normal_left_background)
    #define IMAGE_CLIP_ZIN_BG_IMG_PRESSED (current_MMI_theme->icon_bar_item_pressed_left_background)

    #define IMAGE_CLIP_ZOUT_BG_IMG (current_MMI_theme->icon_bar_item_normal_right_background)
    #define IMAGE_CLIP_ZOUT_BG_IMG_PRESSED (current_MMI_theme->icon_bar_item_pressed_right_background)
#else /* __MMI_ICON_BAR_SUPPORT__ */
    #define IMAGE_CLIP_ZIN_BG_IMG ((PU8)GetImage(IMG_ID_IMAGE_CLIP_ZOOM_IN_BG))
    #define IMAGE_CLIP_ZIN_BG_IMG_PRESSED ((PU8)GetImage(IMG_ID_IMAGE_CLIP_ZOOM_IN_BG_PRESSED))

    #define IMAGE_CLIP_ZOUT_BG_IMG ((PU8)GetImage(IMG_ID_IMAGE_CLIP_ZOOM_OUT_BG))
    #define IMAGE_CLIP_ZOUT_BG_IMG_PRESSED ((PU8)GetImage(IMG_ID_IMAGE_CLIP_ZOOM_OUT_BG_PRESSED))
#endif /* __MMI_ICON_BAR_SUPPORT__*/
#endif /* __MMI_FTE_SUPPORT__ */

#define MMI_IMAGE_CLIP_MSG_TRACE(VAL) \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMAGE_CLIP_CUI_MSG_TRC, __LINE__, VAL)
    
#define LT_EDGE_CALCULATE(x, offset, edge) \
        (x)-(offset)>=edge ? (x)-(offset):edge

#define RB_EDGE_CALCULATE(x, w, edge) \
        (x)+(w) <=edge ? (x) :(edge)-(w)
        
typedef enum
{
    IMGCLP_BUTTON_NONE,
    IMGCLP_BUTTON_ZOOM_IN,
    IMGCLP_BUTTON_ZOOM_OUT,
    IMGCLP_BUTTON_LT_BALL,
    IMGCLP_BUTTON_RT_BALL,
    IMGCLP_BUTTON_LB_BALL,
    IMGCLP_BUTTON_RB_BALL,
    IMGCLP_BUTTON_FRAME,
    IMGCLP_BUTTON_LSK,
    IMGCLP_BUTTON_RSK,
    IMGCLP_BUTTON_COUNT
} cui_image_clip_button_enum;

typedef enum
{
    IMGCLP_STATE_LOAD,
    IMGCLP_STATE_EDIT,
    IMGCLP_STATE_SAVE,
    IMGCLP_STATE_PREVIEW
} cui_image_clip_state_enum;

typedef enum
{
    IMGCLP_DIRECT_CENTER,
    IMGCLP_DIRECT_LT,
    IMGCLP_DIRECT_RT,
    IMGCLP_DIRECT_LB,
    IMGCLP_DIRECT_RB
} cui_image_clip_zoom_direct;

typedef struct
{
    S16 x;
    S16 y;
} cui_image_clip_pos_struct;

typedef struct
{
    U16 width;
    U16 height;
} cui_image_clip_size_struct;

typedef struct
{
    S16 x;
    S16 y;
    U16 w;
    U16 h;
} cui_image_clip_rect_struct;

typedef enum
{
    IMGCLP_BUTTON_UP,
    IMGCLP_BUTTON_DOWN,
    IMGCLP_BUTTON_DISABLE
} cui_image_clip_button_state_enum;

typedef struct
{
    cui_image_clip_rect_struct rect;
    cui_image_clip_button_state_enum state;
#ifdef __MMI_TOUCH_SCREEN__
    cui_image_clip_rect_struct touch_rect;
#endif
} cui_image_clip_btn_struct;

typedef struct
{
    cui_image_clip_btn_struct btn_bg;
    cui_image_clip_pos_struct btn_content;
} cui_image_clip_zoom_btn_struct;

typedef struct
{
    mmi_id cui_gid;

    void * cui_mem_ptr;

    void * user_data;

    gdi_handle decode_layer;
    gdi_handle save_layer;
    gdi_handle clip_layer;
    gdi_handle status_bar_layer;
    gdi_handle soft_key_layer;
    gdi_handle img_decode_handle;

    gdi_handle anim_layer;
    gdi_handle anim_handle;

    cui_image_clip_size_struct dest_size;
    cui_image_clip_size_struct source_size;

    cui_image_clip_size_struct real_save_size;

    MMI_BOOL is_run;
    MMI_BOOL is_in_main;
    MMI_BOOL is_decoding;
    MMI_BOOL is_resized;
    MMI_BOOL is_osd_valid;
    MMI_BOOL is_align_to_w;

    cui_image_clip_btn_struct btn_lt_ball;
    cui_image_clip_btn_struct btn_rt_ball;
    cui_image_clip_btn_struct btn_lb_ball;
    cui_image_clip_btn_struct btn_rb_ball;

    cui_image_clip_zoom_btn_struct btn_zin;
    cui_image_clip_zoom_btn_struct btn_zout;

    U16 frame_percent;
    U16 max_percent;
    U16 min_percent;
    U16 w_ratio;
    U16 h_ratio;

    U16 adjust_count;

    cui_image_clip_btn_struct btn_frame;
    cui_image_clip_rect_struct last_frame;

    cui_image_clip_pos_struct last_point;

    WCHAR* source_file;
    WCHAR* dest_file;

    U8* decode_layer_buf_ptr;
    U8* save_layer_buf_ptr;

    U8* fg_buf_ptr;
    
    cui_image_clip_button_enum selected_obj;
    cui_image_clip_state_enum clip_state;

    cui_image_clip_rect_struct img_rect;
} cui_image_clip_context_struct;

#define IMAGE_CLIP_MEM_SIZE (IMAGE_CLIP_DECODE_LAYER_MEM_SIZE * 2 + \
                             CUI_IMAGE_CLIP_FULL_FILE_PATH_LEN * 2 + \
                             sizeof(cui_image_clip_context_struct))

extern mmi_ret cui_image_clip_fmgr_notify_handler(mmi_event_struct* evt);
#endif /* __MMI_IMAGE_CLIP_CUI__ */

#endif /* IMAGECLIPCUI_H */
