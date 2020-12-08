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
 *  gdi_layer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Layer header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _GDI_LAYER_H_
#define _GDI_LAYER_H_

#include "lcd_if.h"
#include "MMIDataType.h"
#include "gdi_features.h"
#include "gdi_datatype.h"
#include "gdi_const.h"

/* this data structure is defined in lcd_if.h, but will not include when build on older platform */
/* we should add by ourself */

#ifdef GDI_6_LAYERS
#define GDI_LAYER_ENABLE_LAYER_ALL        (LCD_LAYER0_ENABLE|LCD_LAYER1_ENABLE\
                                 |LCD_LAYER2_ENABLE|LCD_LAYER3_ENABLE         \
                                 |LCD_LAYER4_ENABLE|LCD_LAYER5_ENABLE         \
                                 )
#elif defined(GDI_4_LAYERS)
#define GDI_LAYER_ENABLE_LAYER_ALL        (LCD_LAYER0_ENABLE|LCD_LAYER1_ENABLE\
                                 |LCD_LAYER2_ENABLE|LCD_LAYER3_ENABLE         \
                                 )
#else
#define GDI_LAYER_ENABLE_LAYER_ALL        (LCD_LAYER0_ENABLE|LCD_LAYER1_ENABLE)
#endif

/* user define handle */
#ifndef __MMI_SUBLCD__
#define GDI_LAYER_USER_ALLOCATE_HANDLE_START (1)
#else 
#define GDI_LAYER_USER_ALLOCATE_HANDLE_START (2)
#endif 
#define GDI_LAYER_USER_ALLOCATE_HANDLE_END   (GDI_LAYER_TOTAL_LAYER_COUNT-1)

#define GDI_LAYER_VALID_HANDLE_START            ((gdi_handle)&GDI_LAYERS[0])
/****************************************************************************
* Struct / Typedef                                                                 
*****************************************************************************/

// TODO: merge this struct to gdi_layer_struct*, remove duplicate variable between this two structures.
typedef struct
{
   kal_uint8   rotate_value;           /* (keep)rotate select for specified layer */
   kal_uint8   opacity_value;          /* (keep)opacity value for specified layer */
   kal_bool    opacity_enable;         /* (keep)enable/disable opacity for specified layer */
   kal_bool    source_key_enable;      /* (keep)enable/disable source key for specified layer */
   kal_uint32  source_key;             /* (keep)source key color in RGB565 format for specified layer */
   kal_int32   x_offset;               /* (keep)x axis offset from main window for specified layer, should only refrence by lcd */
   kal_int32   y_offset;               /* (keep)y axis offset from main widnow for specified layer, should only refrence by lcd */
   kal_uint32  frame_buffer_address;   /* frame buffer start address of specified layer */
   kal_bool    dither_enable;          /* (keep)enable/disable source key for specified layer */

   kal_bool    color_palette_enable;   /* enable/disable color palette for specified layer */
   kal_uint8   color_palette_select;   /* selection of color palette table */
   kal_uint8   source_color_format;    /* color format of the specified layer */   
} gdi_lcd_layer_struct;

extern gdi_lcd_layer_struct gdi_layer_info[GDI_LAYER_TOTAL_LAYER_COUNT];    /* this struct is used for output lcd */
extern gdi_lcd_layer_struct *gdi_act_layer_info;

#define GDI_LAYER_FLAG_USED               (1<<0)
#define GDI_LAYER_FLAG_DOUBLE_LAYER       (1<<1)
#define GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY (1<<2)
#define GDI_LAYER_FLAG_FROZEN             (1<<3)
#define GDI_LAYER_FLAG_LAZY_FREE          (1<<4)
#define GDI_LAYER_FLAG_HW_UPDATE          (1<<5)

#define GDI_LAYER_CLEAR_FLAG(HANDLE,FLAG)    ((gdi_layer_struct*)HANDLE)->flag  &= ~(U32)(FLAG)
#define GDI_LAYER_SET_FLAG(HANDLE,FLAG)      ((gdi_layer_struct*)HANDLE)->flag  |= (FLAG)
#define GDI_LAYER_GET_FLAG(HANDLE,FLAG)      (((gdi_layer_struct*)HANDLE)->flag  & (FLAG))

#define GDI_LAYER_SET_CLIP(HANDLE,X1,Y1,X2,Y2)  \
   do                                           \
   {                                            \
      ((gdi_layer_struct*)HANDLE)->clipx1=X1;   \
      ((gdi_layer_struct*)HANDLE)->clipy1=Y1;   \
      ((gdi_layer_struct*)HANDLE)->clipx2=X2;   \
      ((gdi_layer_struct*)HANDLE)->clipy2=Y2;   \
   }while(0)

#define GDI_LAYER_RESET_CLIPS(HANDLE)  ((gdi_layer_struct*)HANDLE)->clips_top = 0

#define GDI_LAYER_SET_BLT_RECT(HANDLE,X,Y,W,H)  \
   do                                           \
   {                                            \
      ((gdi_layer_struct*)HANDLE)->blt_x=X;   \
      ((gdi_layer_struct*)HANDLE)->blt_y=Y;   \
      ((gdi_layer_struct*)HANDLE)->blt_width=W;   \
      ((gdi_layer_struct*)HANDLE)->blt_height=H;   \
   }while(0)

#define GDI_LAYER_MAX_WIDTH ((LCD_LAYER_MAX_WIDTH < FLATTEN_LAYER_MAX_WIDTH)? LCD_LAYER_MAX_WIDTH: FLATTEN_LAYER_MAX_WIDTH)
#define GDI_LAYER_MAX_HEIGHT ((LCD_LAYER_MAX_HEIGHT < FLATTEN_LAYER_MAX_HEIGHT)? LCD_LAYER_MAX_HEIGHT: FLATTEN_LAYER_MAX_HEIGHT)              
#define GDI_LAYER_MAX_OFFSETX ((LCD_LAYER_MAX_OFFSETX < FLATTEN_LAYER_MAX_OFFSETX)? LCD_LAYER_MAX_OFFSETX: FLATTEN_LAYER_MAX_OFFSETX)
#define GDI_LAYER_MAX_OFFSETY ((LCD_LAYER_MAX_OFFSETY< FLATTEN_LAYER_MAX_OFFSETY)? LCD_LAYER_MAX_OFFSETY: FLATTEN_LAYER_MAX_OFFSETY)

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define GDI_LAYER_START_LOGGING(_symbol_)
#define GDI_LAYER_STOP_LOGGING(_symbol_)
#endif

#ifdef GDI_USING_LCD_WORK_BUFFER
extern gdi_handle gdi_work_buffer_handle;
#endif

extern gd_replace_src_key_func gdi_act_replace_src_key;

/***************************************************************************** 
* Function 
*****************************************************************************/
/* layers related */
extern GDI_RESULT gdi_layer_init(void);

extern GDI_RESULT gdi_layer_blend_2_layers(
                    gdi_handle src_layer_handle, 
                    S32 x1, 
                    S32 y1, 
                    S32 x2, 
                    S32 y2);

extern GDI_RESULT gdi_layer_flatten_ext_internal(
                    gdi_handle handle0, 
                    gdi_handle handle1, 
                    gdi_handle handle2, 
                    gdi_handle handle3,
                    gdi_handle handle4,
                    gdi_handle handle5,
                    S32 x1,
                    S32 y1,
                    S32 x2,
                    S32 y2,
                    U8* output_buf_ptr,
                    S32 output_buf_size,
                    U16 output_buf_w, 
                    U16 output_buf_h,
                    S32 output_buf_offset_x,
                    S32 output_buf_offset_y,
                    U8 output_buf_bits_per_pixel,
                    U8 output_buf_cf,
                    U8 output_buf_rotate_value,
                    gdi_layer_flatten_flag_bitset flag,
                    void (*non_blocking_callback)(void *param),
                    void *param);

#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
extern void gdi_bltdb_hw_update_state_change(kal_bool start_hw_update);
#endif

typedef enum
{
    GDI_LCD_V2_CTX_FLATTEN = 0,
    GDI_LCD_V2_CTX_BLT_MAIN_LCD = 1,
#if defined(__MMI_SUBLCD__)
    GDI_LCD_V2_CTX_BLT_SUB_LCD = 2,
#endif
    GDI_LCD_V2_CTX_MAX,
}gdi_lcd_v2_context_enum;

extern void gdi_layer_toggle_lcd_source(gdi_lcd_v2_context_enum ctx_index);

#ifdef GDI_GOVL_SUPPORT
extern void gdi_layer_govl_nb_callback_ind_handler(void);
#endif

#ifdef __MTK_TARGET__
#define gdi_layer_save_raw_data(layer_handle, filepath) (KAL_FALSE) /* Not support */
#else
extern kal_bool gdi_layer_save_raw_data(gdi_handle layer_handle, const WCHAR *filepath);
#endif

#endif /* _GDI_LAYER_H_ */ 


