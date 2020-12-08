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
 *  gdi_layer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Layer related.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_trc.h"
#include "gdi_internal.h"
/* for MMI_FRM_ADM_ALLOC_FRAMEBUFFER */
#include "mmi_frm_gprot.h"

/* for INT_QueryIsCachedRAM() */
#include "cache_sw.h"

#include "kal_adm.h"

#include "med_api.h"
#include "med_utility.h"

#ifdef GDI_USING_TV_OUTPUT
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* GDI_USING_TV_OUTPUT */ 
#if defined(GDI_USING_ISP)
   /* for visual effect */

#if !defined(DRV_IDP_OLD_DESIGN)
#include "image_effect_post.h"
#endif

#endif /* defined(GDI_USING_ISP) */ 

#include "kal_general_types.h"
#include "kal_release.h"
#include "kal_trace.h"
#include "string.h"
#include "drv_sw_features_display.h"
#include "flatten/flatten_api.h"
#include "stack_config.h"
#include "lcd_if.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"
#include "med_smalloc.h"
#include "image_effect_struct.h"
#include "img_common_enum.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "MMI_fw_trc.h"
#include "mmi_frm_mem_gprot.h"
#include "DebugInitDef_Int.h"

#include "gdi_const.h"
#include "gdi_lcd_config.h"
#include "gdi_layer.h"
#include "gdi_primitive.h"
#include "gdi_features.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gd_include.h"
#include "gdi_mutex.h"
#include "gdi_lcd.h"
#include "gdi_image_dev_bmp.h"

#include "gdi_util.h"

#include "wfc.h"
#include "Owfimage.h"
#include "lcd_exception_api.h"

#include "ui_buffer.h"

#define GDI_GRAY_BOUNDARY 210
/****************************************************************************
* MACRO
*****************************************************************************/

#define LIMIT_BOUND(pos, min_value, max_value) \
   do{                                         \
      if(pos < min_value)                      \
         pos = min_value;                      \
      else if(pos > max_value)                 \
         pos = max_value;                      \
   }while(0)

//warning 

#define LIMIT_BOUND_UNSIGNED(pos, max_value) \
		 do{										 \
			if(pos > max_value)				 \
			   pos = max_value; 					 \
		 }while(0)

///////////////////////////////////////////
// buffer pool 

/* the base layer should be in internal ram */
#ifdef __MTK_TARGET__
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
#endif 
#ifndef __MTK_TARGET__
#define __align(X)
#endif

#if defined(GDI_USE_RGB565_TO_SHOW_BW)
GDI_HANDLE g_gdi_copy_handle;
#endif

#ifdef __MTK_TARGET__
#pragma arm section rwdata , zidata
#endif 

/* others layers should be external ram */
#define GDI_ADM_HEADER_SIZE(POOL_SUM,MAX_BLOCKS) (sizeof(ADM_CB) + POOL_SUM * sizeof(ADM_BL) + MAX_BLOCKS * sizeof(ADM_MB_HEAD))

static U32 *gdi_base_layer_buffer_pool = NULL;
static U32 *gdi_layer_buffer_pool = NULL;

KAL_ADM_ID gdi_layer_buffer_pool_id;

#if defined GDI_SUPPORT_PALETTES
gdi_color gdi_layer_palette[GDI_SUPPORT_PALETTES][256];
#endif 

static BOOL gdi_is_layer_enable = FALSE;
static gdi_handle gdi_layer_stack[GDI_LAYER_ACT_LAYER_STACK_COUNT];
static S32 gdi_layer_stack_index;

gdi_layer_struct GDI_LAYERS[GDI_LAYER_TOTAL_LAYER_COUNT];
gdi_layer_struct *gdi_act_layer;
gd_color_from_rgb_func gdi_act_color_from_rgb;
gd_color_to_rgb_func gdi_act_color_to_rgb;
gd_put_pixel_func gdi_act_put_pixel;
gd_get_pixel_func gdi_act_get_pixel;
gd_replace_src_key_func gdi_act_replace_src_key;

gdi_lcd_layer_struct gdi_layer_info[GDI_LAYER_TOTAL_LAYER_COUNT];   /* this struct is used for output lcd */
gdi_lcd_layer_struct *gdi_act_layer_info;
static int gdi_palette_used;
static BOOL gdi_is_non_block_blt;
static S32 gdi_draw_section_level;
static BOOL gdi_is_blting;

static WFCCtxtRWAttrib gdi_wfc_context_attrib[GDI_LCD_V2_CTX_MAX];


#define GDI_ALPHA_BLENDING_SOURCE_LAYER_STACK_COUNT      (8)
static gdi_handle gdi_alpha_blending_source_layer_stack[GDI_ALPHA_BLENDING_SOURCE_LAYER_STACK_COUNT];
static S32 gdi_alpha_blending_source_layer_stack_index = 0;
static gdi_handle g_alpha_blending_source_layer = GDI_ERROR_HANDLE;

/* BLT with double buffer by GOVL */
#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)

typedef struct _gdi_bltdb_blt_layer_struct
{
    U8* blt_buf_ptr;
    U32 blt_buf_size;
} gdi_bltdb_blt_layer_struct;

/* frame buffer that really blt out when bltdb */
static gdi_bltdb_blt_layer_struct gdi_bltdb_blt_layer[GDI_LAYER_HW_LAYER_COUNT]; 
static U8* gdi_bltdb_blt_buf_ptr[2] = {NULL, NULL}; /* double buffer pointer */

static GDI_BLTDB_ENABLE_ENUM gdi_bltdb_enable_status = GDI_BLTDB_ENABLE_END;
static kal_bool gdi_bltdb_is_started = KAL_FALSE;

#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    #if GDI_BLTDB_BUF_CF != GDI_COLOR_FORMAT_16
        #error "please define GDI_MAINLCD_SCANLINE_ROTATION buffer color format for other color format."
    #endif

    /* double buffer gdi inner buffer */
    #if defined(__MTK_TARGET__)
    #pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
    #endif
        __align(32) static U8 gdi_bltdb_inner_blt_buf[GDI_BLTDB_BUF_SIZE];
    #if defined(__MTK_TARGET__)
    #pragma arm section zidata, rwdata
    #endif
static kal_bool gdi_scanline_force_rotate = KAL_FALSE;
#endif /* defined(GDI_MAINLCD_SCANLINE_ROTATION) */
#endif /* defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__) */

#if defined(GDI_SUBLCD_SCANLINE_ROTATION)
    /* sublcd scanline rotation buffer */
    #if defined(__MTK_TARGET__)
    #pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
    #endif
        __align(32) static U8 gdi_sublcd_scanline_rotation_buf[GDI_SUBLCD_SCANLINE_ROTATION_BUF_SIZE];
    #if defined(__MTK_TARGET__)
    #pragma arm section zidata, rwdata
    #endif
#endif /* defined(GDI_SUBLCD_SCANLINE_ROTATION) */

#if defined(GDI_LCD_SCANLINE_ROTATION)
static WFCRotation gdi_scanline_get_rotate_value(WFCRotation wfc_rotation);
#endif

extern kal_uint8 INT_Exception_Enter;


static kal_bool g_gdi_layer_is_layer_pool_inited = KAL_FALSE;
static void gdi_layer_init_layer_pool(void);

static void (*gdi_layer_blt_finish_callback)(void *param);
static void *gdi_layer_blt_finish_param;
static void gdi_layer_set_blt_finish_callback(
             void (*blt_finish_callback)(void *param),
             void *param);

static volatile struct {
    kal_bool doing_flatten;
    void (*finish_callback)(void *param);
    void *param;
} gdi_layer_flatten_nb_session =
{
    KAL_FALSE,
    NULL,
    NULL
};


static volatile struct
{
    /* Separate bytes rather than flag bits in single byte to avoid racing condition */
#ifndef GDI_GOVL_SUPPORT
    kal_bool flatten_running;
#endif
    kal_bool blt_running;
} gdi_layer_resource_hint =
{
#ifndef GDI_GOVL_SUPPORT
    KAL_FALSE,
#endif
    KAL_FALSE
};


#ifdef GDI_GOVL_SUPPORT

/* Will be initilized in gdi_layer_init(); get the handle by gdi_layer_govl_get_handle() */
static kal_uint32 g_gdi_layer_govl_handle = 0;

#define gdi_layer_govl_get_handle() (g_gdi_layer_govl_handle)

#endif


/****************************************************************************
* Function Pre-declare
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
#endif

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_find_valid_handle
 * DESCRIPTION
 *  Init the Frame Buffer Manager
 *  
 *  Will return handle of a valid layer.
 *  If no valid layer, will retrun GDI_LAYER_ERROR_HANDLE.
 * PARAMETERS
 *  void
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
static gdi_handle gdi_layer_find_valid_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = GDI_LAYER_USER_ALLOCATE_HANDLE_START; i < GDI_LAYER_TOTAL_LAYER_COUNT; i++)
        if (!GDI_LAYER_GET_FLAG(&GDI_LAYERS[i], GDI_LAYER_FLAG_USED))
        {
            return (gdi_handle) & GDI_LAYERS[i];
        }

    return GDI_LAYER_EMPTY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_allocate_buffer
 * DESCRIPTION
 *  assign buffer of the pass in size to a layerr
 *  
 *  return alloacted buffer ptr if succeed, otherwise return NULL
 * PARAMETERS
 *  cf              [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  ret_size        [?]         
 *  size(?)         [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8 *gdi_layer_allocate_buffer(gdi_color_format cf, S32 width, S32 height, S32 *ret_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* buf_ptr;
    
    S32 i;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * workaround for dynamic switchable buffer ZI will be zeroed after 1st stage booting.
     * have to init again here after booted (task inited).
     */
    if (!g_gdi_layer_is_layer_pool_inited)
    {
        gdi_layer_init_layer_pool();
        g_gdi_layer_is_layer_pool_inited = KAL_TRUE;
    }
    
    size = gdi_sizeof_pixels(cf, width, height);

    /* allcoate buffer from pool, align buffer_size to 4 byte alignment */
    size += 3;
    size &= ~3;
    *ret_size = size;

    // try to allocate from pool
    buf_ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(gdi_layer_buffer_pool_id, size);

    // fail, we should free some lazy buffer, and try again 
    if(buf_ptr == NULL)
    {
        // iterate all layer, find last allocated position
        for (i = 0; i < GDI_LAYER_TOTAL_LAYER_COUNT; i++)  // if is used and is lazy and not outside memory
        if((GDI_LAYER_FLAG_USED|GDI_LAYER_FLAG_LAZY_FREE) == GDI_LAYER_GET_FLAG(&GDI_LAYERS[i], GDI_LAYER_FLAG_USED | GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY | GDI_LAYER_FLAG_LAZY_FREE))
        {
            GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_26);
            gdi_layer_free((gdi_handle)&GDI_LAYERS[i]);
        }
        buf_ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(gdi_layer_buffer_pool_id, size);
    }
    GDI_ASSERT(buf_ptr != NULL); // should be enough
    
    return buf_ptr;
}

static gdi_color_format gdi_layer_convert_cf_to_vcf(gdi_color_format cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(cf <GDI_COLOR_FORMAT_STANDARD_END)
    {
        return cf;
    }
    else
    {
        return gdi_get_color_format(gdi_bits_per_pixel(cf));  /* convert to standard color format */
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_create_internal
 * DESCRIPTION
 *  Init a layer.
 *  
 *  Init layer as most basic layer, which does not
 *  support src_key, opacity, etc.
 *  This function will retrun FALSE if it cant allocate buffer.
 * PARAMETERS
 *  handle              [IN]        
 *  offset_x            [IN]        
 *  offset_y            [IN]        
 *  width               [IN]        
 *  height              [IN]        
 *  cf                  [IN]        
 *  is_double_layer     [IN]        
 *  buf_ptr             [?]         
 *  buf_ptr1            [?]         
 *  buf_size            [IN]        
 *  lcd_handle(?)       [IN]        
 * RETURNS
 *  void
 * BOOL
 *  
 *****************************************************************************/
static void gdi_layer_create_internal(
                gdi_handle handle,
                S32 offset_x,
                S32 offset_y,
                S32 width,
                S32 height,
                gdi_color_format cf,
                BOOL is_double_layer,
                U8 *buf_ptr,
                U8 *buf_ptr1,
                U32 buf_size,
                void *creator_lr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*) handle;
    int id = layer->id;
    gdi_lcd_layer_struct *layer_info = &gdi_layer_info[id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_CREATE,
        id, handle, cf,offset_x,offset_y,width,height,is_double_layer,buf_size,buf_ptr,buf_ptr1, (kal_uint32)creator_lr);
    
    memset(layer, 0, sizeof(gdi_layer_struct));
    memset(layer_info, 0, sizeof(gdi_lcd_layer_struct));
    layer->id = id;

    GDI_LAYER_SET_FLAG(layer, GDI_LAYER_FLAG_USED);

    /* 
     * Layer framebuffer can only be obtained in the following five ways:
     * 
     * 1. App-based ASM: applib_mem_ap_alloc_framebuffer()
     * 2. Screen-based ASM: applib_mem_screen_alloc_framebuffer()
     * 3. ADM for framebuffer: MMI_FRM_ADM_ALLOC_FRAMEBUFFER()
     * 4. Media buffer
     * 5. ZI data in "NONCACHEDZI" section
     */
    layer->buf_ptr = buf_ptr;
    GDI_ASSERT(layer->buf_ptr);                            /* buffer available */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    GDI_ASSERT(!INT_QueryIsCachedRAM((kal_uint32)layer->buf_ptr, layer->layer_size));     /* buffer non-cacheable */
#endif
    GDI_ASSERT(((kal_uint32)layer->buf_ptr & 0x03) == 0);              /* buffer 4-byte alignment */
    if (is_double_layer)
    {
        GDI_LAYER_SET_FLAG(layer, GDI_LAYER_FLAG_DOUBLE_LAYER);
        layer->buf_ptr1 = buf_ptr1;
        GDI_ASSERT(layer->buf_ptr1);                            /* buffer available */
    #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
        GDI_ASSERT(!INT_QueryIsCachedRAM((kal_uint32)layer->buf_ptr1, layer->layer_size));     /* buffer non-cacheable */
    #endif 
        GDI_ASSERT(((kal_uint32)layer->buf_ptr1 & 0x03) == 0);              /* buffer 4-byte alignment */
    }
    
    layer->cf = cf;
    layer->vcf = gdi_layer_convert_cf_to_vcf(layer->cf);    /* convert to standard color format */
    if ((GDI_COLOR_FORMAT_32 == layer->cf) ||
        (GDI_COLOR_FORMAT_32_PARGB== layer->cf) ||
        (GDI_COLOR_FORMAT_PARGB6666 == layer->cf))
    {
        layer_info->opacity_enable = KAL_TRUE;
        layer_info->opacity_value = 0xFF;
    }

#ifdef GDI_SUPPORT_PALETTES
    if (layer->cf == GDI_COLOR_FORMAT_8)   /* use index color */
    {
        int i;

        /* we should check there are palette available or not ! */
        for (i = 0; i < GDI_SUPPORT_PALETTES; i++)
            if ((gdi_palette_used & (1 << i)) == 0)
            {
                break;
            }

        if (i >= GDI_SUPPORT_PALETTES)
        {
            i = GDI_SUPPORT_PALETTES - 1;
        }

        gdi_palette_used |= (1 << i);

        layer_info->color_palette_enable = KAL_TRUE;
        layer_info->color_palette_select = i;
    }
#endif /* GDI_SUPPORT_PALETTES */ 

    layer->width = (U16) width;
    layer->height = (U16) height;
    layer->bits_per_pixel = (U8) gdi_bits_per_pixel(cf);
    layer->layer_size = (U32) buf_size;

    layer->offset_x = offset_x;
    layer->offset_y = offset_y;

    /* set color format function */
    GDI_DEBUG_ASSERT(cf < GDI_COLOR_FORMAT_END);

    /* set clipping */
    GDI_LAYER_RESET_CLIPS(layer);
    GDI_LAYER_SET_CLIP(layer, 0, 0, width - 1, height - 1);

    /* set blt region */
    GDI_LAYER_SET_BLT_RECT(layer, 0, 0, width, height);

    // default layer background is WHITE
    //W05.39 Because Hardware only could be set to 24 bit color not labyer color format
    layer->background = gd_color_from_rgb_24(255, 255, 255, 255);

    /* init lcd_layer */
    if (layer->cf == GDI_COLOR_FORMAT_UYVY422)
    {
        layer_info->dither_enable = KAL_TRUE;
    }
    layer_info->frame_buffer_address = (U32) layer->buf_ptr;
    //              layer_info->layer_update_queue          = FALSE;
    //              layer_info->opacity_enable                      = FALSE;
    //              layer_info->opacity_value                       = 0;
#if defined(GDI_USING_LAYER_ROTATE)
    layer_info->rotate_value = LCD_LAYER_ROTATE_NORMAL;
#endif 
    //              layer_info->source_key                          = 0;
    //              layer_info->source_key_enable           = FALSE;

    layer_info->x_offset = (offset_x + GDI_LAYER_OFFSET);
    layer_info->y_offset = (offset_y + GDI_LAYER_OFFSET);

    layer->creator_lr = creator_lr;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_init_layer_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_layer_init_layer_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint32 chunk[2] = {0xffffffff, 0}; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_buffer_pool_id = kal_adm_create(gdi_layer_buffer_pool, ui_buffer_get_size(UI_BUFFER_ID_GDI_SBL), (kal_uint32*)chunk,MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_ui_buffer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_mode       [IN]
 * RETURNS
 *  
 *****************************************************************************/
static ui_buffer_ret_enum gdi_layer_ui_buffer_callback(ui_buffer_mode_enum new_mode, ui_buffer_mode_enum old_mode, kal_uint32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_UNUSED(old_mode);
    GDI_UNUSED(flag);
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_ui_buffer_callback)

    if ((old_mode == UI_BUFFER_MODE_VENUS) && (new_mode == UI_BUFFER_MODE_DEFAULT))
    {
        gdi_layer_init_layer_pool();
    }
    else if ((old_mode == UI_BUFFER_MODE_DEFAULT) && (new_mode == UI_BUFFER_MODE_VENUS))
    {
        S32 i;

        /* free all layers in layer pool, mainly for DM lazy free */
        // TODO: ADD ASSERT
        for (i = GDI_LAYER_USER_ALLOCATE_HANDLE_START; i < GDI_LAYER_TOTAL_LAYER_COUNT; i++)
        {
            gdi_layer_struct *layer = (gdi_layer_struct*)&GDI_LAYERS[i];

            if (GDI_LAYER_GET_FLAG(layer, GDI_LAYER_FLAG_USED) &&
                !GDI_LAYER_GET_FLAG(layer, GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY))
            {                
                gdi_layer_free((gdi_handle)layer);
            }
        }
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_ui_buffer_callback)

    return UI_BUFFER_RET_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_init
 * DESCRIPTION
 *  Init the Frame Buffer Manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_layer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_init)
    gdi_color_format cf;
    int i;

    /* get gdi layer pool address from ui buffer */
    gdi_base_layer_buffer_pool = (U32*)ui_buffer_get_start_addr(UI_BUFFER_ID_GDI_MBL);
    gdi_layer_buffer_pool = (U32*)ui_buffer_get_start_addr(UI_BUFFER_ID_GDI_SBL);

    // initialize the GDI buffer pool
    /* zero it in the first stage because now these buffers are ZIed after nand loading because dynamic cacheable */
    memset(gdi_base_layer_buffer_pool, 0, ui_buffer_get_size(UI_BUFFER_ID_GDI_MBL));
    memset(gdi_layer_buffer_pool, 0, ui_buffer_get_size(UI_BUFFER_ID_GDI_SBL));

    gdi_layer_init_layer_pool();

    /* register ui buffer mode switch callback for layer pool */
    ui_buffer_register_mode_callback(UI_BUFFER_ID_GDI_SBL, gdi_layer_ui_buffer_callback);

    // initialize layer array
    memset(&GDI_LAYERS, 0, sizeof(GDI_LAYERS));
    memset(&gdi_layer_info, 0, sizeof(gdi_layer_info));
    for (i = 0; i < GDI_LAYER_TOTAL_LAYER_COUNT; i++)
    {
        GDI_LAYERS[i].id = i;
    }

    /* init layer stack */
    gdi_layer_stack_index = 0;

    /* non_block blt */
    gdi_is_non_block_blt = FALSE;
    gdi_draw_section_level = 0;
    gdi_is_blting = FALSE;

#ifdef __MMI_SUBLCD__
    {
        U8 *buf_ptr;
        S32 buf_size;
        /* init sub lcd base layer */
        cf = GDI_SUB_BASE_LAYER_FORMAT;
        switch(cf)
        {
        case GDI_COLOR_FORMAT_16:
            if(GDI_SUBLCD_BUFFER_FORMAT(0x12,0x34,0x56) != gd_color_from_rgb_16(0x00,0x12,0x34,0x56))
                cf = GDI_COLOR_FORMAT_SUBLCD;
            break;
        }

        buf_ptr = gdi_layer_allocate_buffer(cf, GDI_SUBLCD_WIDTH, GDI_SUBLCD_HEIGHT, &buf_size);
        gdi_layer_create_internal(
            GDI_LAYER_SUB_BASE_LAYER_HANDLE,
            0,
            0,
            GDI_SUBLCD_WIDTH,
            GDI_SUBLCD_HEIGHT,
            cf,
            FALSE,
            buf_ptr,
            NULL,
            buf_size,
            (void*)&gdi_layer_init);
        gdi_layer_set_active(GDI_LAYER_SUB_BASE_LAYER_HANDLE);
        gdi_layer_clear(DRV_SUBLCD_INIT_COLOR);
    }
#endif /* __MMI_SUBLCD__ */ 

    /* init mian lcd base layer */
    cf = GDI_MAIN_BASE_LAYER_FORMAT;
    switch(cf)
    {
    case GDI_COLOR_FORMAT_16:
        if(GDI_RGB_TO_BUFFER_FORMAT(0x12,0x34,0x56) != gd_color_from_rgb_16(0x00,0x12,0x34,0x56))
            cf = GDI_COLOR_FORMAT_MAINLCD;
        break;
    }
    #if defined(GDI_USE_RGB565_TO_SHOW_BW)
    cf = GDI_COLOR_FORMAT_1;
    #endif
    gdi_layer_create_internal(
        GDI_LAYER_MAIN_BASE_LAYER_HANDLE,
        0,
        0,
        GDI_LCD_WIDTH,
        GDI_LCD_HEIGHT,
        cf,
        FALSE,
        (U8*) gdi_base_layer_buffer_pool,
        NULL,
        ui_buffer_get_size(UI_BUFFER_ID_GDI_MBL),
        (void*)&gdi_layer_init);
    GDI_LAYER_SET_FLAG(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY);
    gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_clear(DRV_MAINLCD_INIT_COLOR);
   
	#if defined(GDI_USE_RGB565_TO_SHOW_BW)
	/* create copy layer */
	gdi_layer_create_cf(
    	GDI_MAIN_BASE_LAYER_FORMAT,
        0,
        0,
        GDI_LCD_WIDTH,
        GDI_LCD_HEIGHT,
        &g_gdi_copy_handle);
	#endif
	
    /* set main LCD active */
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    /* misc, some flags */
    gdi_is_layer_enable = FALSE;

    /* no palette is allocated */
    gdi_palette_used = 0;

#ifdef GDI_GOVL_SUPPORT
    g_gdi_layer_govl_handle = FlattenGetUserHandle();
#endif

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_init)
    return GDI_SUCCEED;
}

/**************************************************************
   Create layer with color format
   INPUT PARAMETERS  :  
      cf
      offset_x
      offset_y
      width
      height
***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_create_cf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cf              [IN]        
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  handle_ptr      [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_create_cf(
            gdi_color_format cf,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            gdi_handle *handle_ptr)
{
    kal_uint32 creator_lr;

    GDI_GET_RETURN_ADDRESS(creator_lr);

    #if defined(GDI_SLIM_COLOR_FORMAT)
    if (cf == GDI_COLOR_FORMAT_24)
    {
        return GDI_FAILED;
    }
    #endif
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_create_cf)
    {
        U8 *buf;
        S32 buf_size;
        gdi_handle handle;

        buf = gdi_layer_allocate_buffer(cf, width, height, &buf_size);
        
        *handle_ptr = handle = gdi_layer_find_valid_handle();
        if (handle == GDI_LAYER_EMPTY_HANDLE)
        {
            
            GDI_ASSERT(0); // cant create layer
            GDI_RETURN(GDI_LAYER_ERR_NO_VALID_LAYER_HANDLE);
        }

        gdi_layer_create_internal(handle, offset_x, offset_y, width, height, cf, FALSE, buf, NULL, buf_size, (void*)creator_lr);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_create_cf)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_create_cf_double
 * DESCRIPTION
 *  Create a layer
 *  
 *  Will return handle of the layer.
 *  If no valid layer, will retrun GDI_LAYER_ERROR_HANDLE.
 * PARAMETERS
 *  cf              [IN]        
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  handle_ptr      [?]         
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
GDI_RESULT gdi_layer_create_cf_double(
            gdi_color_format cf,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            gdi_handle *handle_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handle;
    gdi_result ret;
    kal_uint32 creator_lr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(creator_lr);
    
    #if defined(GDI_SLIM_COLOR_FORMAT)
    if (cf == GDI_COLOR_FORMAT_24)
    {
        return GDI_FAILED;
    }
    #endif
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_create_double)

    *handle_ptr = handle = gdi_layer_find_valid_handle();

    if (handle == GDI_LAYER_EMPTY_HANDLE)
    {
        ret = GDI_LAYER_ERR_NO_VALID_LAYER_HANDLE;
        /* cant create layer */
        GDI_ASSERT(0);
    }
    else
    {
        U8 *buf, *buf1;
        S32 buf_size;

        buf = gdi_layer_allocate_buffer(cf, width, height * 2, &buf_size);
        buf_size /= 2;
        buf1 = buf + buf_size;
        /* buf1 = gdi_layer_allocate_buffer(cf,width,height,&buf_size); */

        gdi_layer_create_internal(handle, offset_x, offset_y, width, height, cf, TRUE, buf, buf1, buf_size, (void*)creator_lr);
        ret = GDI_SUCCEED;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_create_double)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_create_cf_double_using_outside_memory
 * DESCRIPTION
 *  Create a layer
 *  
 *  Will return handle of the layer.
 *  If no valid layer, will retrun GDI_LAYER_ERROR_HANDLE.
 * PARAMETERS
 *  cf                          [IN]        
 *  offset_x                    [IN]        
 *  offset_y                    [IN]        
 *  width                       [IN]        
 *  height                      [IN]        
 *  handle_ptr                  [IN]        
 *  outside_memory1             [?]         
 *  outside_memory_size_1       [IN]        
 *  outside_memory2             [?]         
 *  outside_memory_size_2       [IN]        
 *  outside_memory_size(?)      [IN]        
 *  outside_memory(?)           [IN]        
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
GDI_RESULT gdi_layer_create_cf_double_using_outside_memory(
            gdi_color_format cf,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            gdi_handle *handle_ptr,
            U8 *outside_memory1,
            S32 outside_memory_size_1,
            U8 *outside_memory2,
            S32 outside_memory_size_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handle;
    gdi_result ret;
    kal_uint32 creator_lr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(creator_lr);
    
    #if defined(GDI_SLIM_COLOR_FORMAT)
    if (cf == GDI_COLOR_FORMAT_24)
    {
        return GDI_FAILED;
    }
    #endif
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_create_double_using_outside_memory)

    *handle_ptr = handle = gdi_layer_find_valid_handle();

    if (handle == GDI_LAYER_EMPTY_HANDLE)
    {
        ret = GDI_LAYER_ERR_NO_VALID_LAYER_HANDLE;
        /* cant create layer */
        GDI_ASSERT(0);
    }
    else
    {
        U8 *buf, *buf1;
        S32 buffer_size;

        buffer_size = gdi_sizeof_pixels(cf, width, height);
        /* allcoate buffer from pool, align buffer_size to 4 byte alignment */
        buffer_size += 3;
        buffer_size &= ~3;

        //buf = outside_memory;
        //buf1 = (U8*)&outside_memory[offset];
        buf = outside_memory1;
        buf1 = outside_memory2;

        GDI_ASSERT((buffer_size <= outside_memory_size_1) && (buffer_size <= outside_memory_size_2));

        gdi_layer_create_internal(handle, offset_x, offset_y, width, height, cf, TRUE, buf, buf1, buffer_size, (void*)creator_lr);
        GDI_LAYER_SET_FLAG(handle, GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY);
        ret = GDI_SUCCEED;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_create_double_using_outside_memory)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_create_cf_using_outside_memory
 * DESCRIPTION
 *  Create a layer
 *  
 *  Will return handle of the layer.
 *  If no valid layer, will retrun GDI_LAYER_ERROR_HANDLE.
 * PARAMETERS
 *  cf                      [IN]        
 *  offset_x                [IN]        
 *  offset_y                [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 *  handle_ptr              [?]         
 *  outside_memory          [?]         
 *  outside_memory_size     [IN]        
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
GDI_RESULT gdi_layer_create_cf_using_outside_memory(
            gdi_color_format cf,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            gdi_handle *handle_ptr,
            U8 *outside_memory,
            S32 outside_memory_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handle;
    gdi_result ret;
    kal_uint32 creator_lr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(creator_lr);
    
    #if defined(GDI_SLIM_COLOR_FORMAT)
    if (cf == GDI_COLOR_FORMAT_24)
    {
        return GDI_FAILED;
    }
    #endif
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_create_using_outside_memory)

    *handle_ptr = handle = gdi_layer_find_valid_handle();

    if (handle == GDI_LAYER_EMPTY_HANDLE)
    {
        ret = GDI_LAYER_ERR_NO_VALID_LAYER_HANDLE;
        /* cant create layer */
        GDI_ASSERT(0);
    }
    else
    {
        U8 *buf;
        S32 buffer_size;

        buffer_size = gdi_sizeof_pixels(cf, width, height);
        GDI_ASSERT(buffer_size <= outside_memory_size);

        buf = outside_memory;

        gdi_layer_create_internal(handle, offset_x, offset_y, width, height, cf, FALSE, buf, NULL, outside_memory_size, (void*)creator_lr);
        GDI_LAYER_SET_FLAG(handle, GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY);
        ret = GDI_SUCCEED;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_create_using_outside_memory)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_active
 * DESCRIPTION
 *  Set a layer as active layer.
 *  
 *  Will set some golbal variable, for faster reference.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 * BOOL
 *  
 *****************************************************************************/
void gdi_layer_set_active(gdi_handle handle)
{
    kal_uint32 lr = 0;
    GDI_GET_RETURN_ADDRESS(lr);

    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_active)

    GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_SET_ACTIVE, handle, lr);

    GDI_ASSERT(handle != GDI_NULL_HANDLE);

    gdi_act_layer = (gdi_layer_struct*) handle;
    gdi_act_layer_info = &(gdi_layer_info[gdi_act_layer->id]);

    GDI_ASSERT(GDI_LAYER_GET_FLAG(gdi_act_layer, GDI_LAYER_FLAG_USED));

    gdi_act_color_from_rgb = gd_color_from_rgb[gdi_act_layer->cf];
    gdi_act_color_to_rgb = gd_color_to_rgb[gdi_act_layer->cf];

    gdi_act_put_pixel = gd_put_pixel[gdi_act_layer->cf];
    gdi_act_get_pixel = gd_get_pixel[gdi_act_layer->cf];
    gdi_act_replace_src_key = gd_replace_src_key[gdi_act_layer->cf];

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_active)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_push_and_set_active
 * DESCRIPTION
 *  push current layer into stack and set passin layer active
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_layer_push_and_set_active(gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_PUSH_AND_SET_ACTIVE,
        handle, lr, gdi_layer_stack_index, ((gdi_layer_stack_index == 0) ? '{' : ' '));
    
    GDI_LOCK;
    /* no more stack entry available */
    GDI_ASSERT(gdi_layer_stack_index < GDI_LAYER_ACT_LAYER_STACK_COUNT - 1);

    gdi_layer_stack[gdi_layer_stack_index++] = (gdi_handle) gdi_act_layer;
    gdi_layer_set_active(handle);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_pop_and_restore_active
 * DESCRIPTION
 *  pop the layer in stack and make it active
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_layer_pop_and_restore_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    
    GDI_ASSERT(gdi_layer_stack_index > 0);
    gdi_layer_set_active(gdi_layer_stack[--gdi_layer_stack_index]);
    
    GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_POP_AND_RESTORE_ACTIVE,
        lr, gdi_layer_stack_index, ((gdi_layer_stack_index == 0) ? '}' : ' '));

    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_active
 * DESCRIPTION
 *  get currently active layer handle
 * PARAMETERS
 *  handle_ptr      [OUT]       
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_layer_get_active(gdi_handle *handle_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_active)
    *handle_ptr = (gdi_handle) gdi_act_layer;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_active)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_toggle_double
 * DESCRIPTION
 *  Toggle double buf
 *  
 *  return FALSE if not valid handle.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_toggle_double(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_toggle_double)

    /* active layer should be doubled layer */
    if(GDI_LAYER_GET_FLAG(gdi_act_layer, GDI_LAYER_FLAG_DOUBLE_LAYER))
    {
        U8 *tmp;
        /* swap those two buffer */
        tmp = gdi_act_layer->buf_ptr;
        gdi_act_layer->buf_ptr = gdi_act_layer->buf_ptr1;
        gdi_act_layer->buf_ptr1 = tmp;
        
        gdi_act_layer_info->frame_buffer_address = (U32) gdi_act_layer->buf_ptr;
        
        ret = GDI_SUCCEED;
    }
    else
    {
        ret = GDI_FAILED;
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_toggle_double)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_free
 * DESCRIPTION
 *  Release layer
 *  
 *  return FALSE if not valid handle.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_free(gdi_handle handle)
{
    GDI_TRC_PRINT_LR(GDI_TRC_PAIRED_LAYER);
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_free)
    {
        gdi_layer_struct *layer = (gdi_layer_struct*) handle;

        GDI_DEBUG_ASSERT(handle >= (gdi_handle) & (GDI_LAYERS[GDI_LAYER_USER_ALLOCATE_HANDLE_START]));
        GDI_ASSERT(GDI_LAYER_GET_FLAG(layer, GDI_LAYER_FLAG_USED));

        GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_FREE, handle, layer->id);


        if(layer->lazy_free_callback) layer->lazy_free_callback(handle);

        if (layer->cf == GDI_COLOR_FORMAT_8)   /* free the palette */
            gdi_palette_used &= ~(1 << gdi_layer_info[layer->id].color_palette_select);

        gdi_anim_stop_all_by_layer((gdi_handle)layer);

        // free buffer if not outside memory
        if(GDI_LAYER_GET_FLAG(layer,GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY)==0)
        {
            if ((GDI_LAYER_GET_FLAG(layer, GDI_LAYER_FLAG_DOUBLE_LAYER)!=0) && // is double buffer
                ((U32)layer->buf_ptr1 < (U32)layer->buf_ptr))      
            {
                kal_adm_free(gdi_layer_buffer_pool_id,layer->buf_ptr1);
            }
            else
            {
                kal_adm_free(gdi_layer_buffer_pool_id,layer->buf_ptr);
            }
            //Should not free buf_ptr1, because buf_ptr1 is in the bottom of buf_ptr, they are in the same memory block.
            //if(GDI_LAYER_GET_FLAG(layer,GDI_LAYER_FLAG_DOUBLE_LAYER))
            //    kal_adm_free(gdi_layer_buffer_pool_id,layer->buf_ptr1);
        }
        layer->flag = 0;    /* clear all flag */
        
        //gdi_layer_dump_information();
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_free)
    return GDI_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  gdi_layer_lazy_free
 * DESCRIPTION
 *  Release layer
 *  
 *  return FALSE if not valid handle.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_lazy_free(gdi_handle handle,void (*lazy_free_callback)(gdi_handle handle))
{
    GDI_TRC_PRINT_LR(GDI_TRC_PAIRED_LAYER);
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_lazy_free)
    {
        gdi_layer_struct *layer = (gdi_layer_struct*) handle;

        GDI_DEBUG_ASSERT(handle >= (gdi_handle) & (GDI_LAYERS[GDI_LAYER_USER_ALLOCATE_HANDLE_START]));
        GDI_ASSERT(GDI_LAYER_GET_FLAG(layer, GDI_LAYER_FLAG_USED)); 
        GDI_ASSERT(GDI_LAYER_GET_FLAG(layer, GDI_LAYER_FLAG_USE_OUTSIDE_MEMORY)==0);
        GDI_ASSERT(lazy_free_callback != NULL);

        GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_LAZY_FREE, handle, layer->id);

        GDI_LAYER_SET_FLAG(layer,GDI_LAYER_FLAG_LAZY_FREE);
        layer->lazy_free_callback = lazy_free_callback;

        //gdi_layer_dump_information();
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_lazy_free)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_color_format
 * DESCRIPTION
 *  get layer color format
 * PARAMETERS
 *  cf      [OUT]    active layer color format 
 * RETURNS
 * GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_get_color_format(gdi_color_format *cf)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_color_format)
    *cf = gdi_act_layer->cf;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_color_format)
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_color_format
 * DESCRIPTION
 *  change color format of active layer.
 *  It assert if the layer buffer size is not enough for new color format.
 *  Please noticy that it may change the opacity & color_palette_enable of layer.
 * PARAMETERS
 *  cf      [IN]    new color format 
 * RETURNS
 * GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_set_color_format(gdi_color_format cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size = 0;
    gdi_lcd_layer_struct *layer_info = &gdi_layer_info[gdi_act_layer->id];
    gdi_color_format old_cf = gdi_act_layer->cf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_color_format)

    if (gdi_act_layer->cf == cf)    /* don't have to change cf */
    {
        GDI_RETURN(GDI_SUCCEED);
    }
    
    GDI_DEBUG_ASSERT(GDI_LAYER_GET_FLAG(gdi_act_layer,GDI_LAYER_FLAG_USED));
    GDI_DEBUG_ASSERT(cf < GDI_COLOR_FORMAT_END);

    /* buf size have to be enough for new color format */
    buffer_size = gdi_sizeof_pixels(cf, gdi_act_layer->width, gdi_act_layer->height);
    GDI_ASSERT(buffer_size <= gdi_act_layer->layer_size);

    /* set color format */
    gdi_act_layer->cf = cf;
    gdi_act_layer->vcf = gdi_layer_convert_cf_to_vcf(cf);    /* convert to standard color format */

    /* set layer dithering */
    if (gdi_act_layer->cf == GDI_COLOR_FORMAT_UYVY422)
    {
        layer_info->dither_enable = KAL_TRUE;
    }
    else
    {
        layer_info->dither_enable = KAL_FALSE;
    }
    
    /* set opacity and opacity value */
    if ((GDI_COLOR_FORMAT_32 == gdi_act_layer->cf) ||
        (GDI_COLOR_FORMAT_32_PARGB== gdi_act_layer->cf) ||
        (GDI_COLOR_FORMAT_PARGB6666 == gdi_act_layer->cf))
    {
        layer_info->opacity_enable = KAL_TRUE;
        layer_info->opacity_value = 0xFF;
    }
    else
    {
        layer_info->opacity_enable = KAL_FALSE;
        layer_info->opacity_value = 0;
    }

    /* set palette */
    #ifdef GDI_SUPPORT_PALETTES
    if (gdi_act_layer->cf != old_cf)
    {
        if (old_cf == GDI_COLOR_FORMAT_8)  /* free the palette */
        {
            gdi_palette_used &= ~(1 << gdi_layer_info[gdi_act_layer->id].color_palette_select);
            layer_info->color_palette_enable = KAL_FALSE;
            layer_info->color_palette_select = 0;
        }
        
        if (gdi_act_layer->cf == GDI_COLOR_FORMAT_8)   /* use index color */
        {
            int i;

            /* we should check there are palette available or not ! */
            for (i = 0; i < GDI_SUPPORT_PALETTES; i++)
                if ((gdi_palette_used & (1 << i)) == 0)
                {
                    break;
                }

            if (i >= GDI_SUPPORT_PALETTES)
            {
                i = GDI_SUPPORT_PALETTES - 1;
            }

            gdi_palette_used |= (1 << i);

            layer_info->color_palette_enable = KAL_TRUE;
            layer_info->color_palette_select = i;
        }
    }
    #endif /* GDI_SUPPORT_PALETTES */ 

    /* set bits per pixel */
    gdi_act_layer->bits_per_pixel = (U8) gdi_bits_per_pixel(cf);

    /* set active layer func pointer */
    gdi_act_color_from_rgb = gd_color_from_rgb[cf];
    gdi_act_color_to_rgb = gd_color_to_rgb[cf];

    gdi_act_put_pixel = gd_put_pixel[cf];
    gdi_act_get_pixel = gd_get_pixel[cf];
    gdi_act_replace_src_key = gd_replace_src_key[cf];

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_color_format)
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_position
 * DESCRIPTION
 *  Move the layer to its desired position.
 * PARAMETERS
 *  offset_x            [IN]        
 *  offset_y            [IN]        
 *  gdi_handle(?)       [IN]        Handle
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_layer_set_position(S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_position)
    ret = gdi_layer_set_position_nb_concurrent((gdi_handle)gdi_act_layer, offset_x, offset_y);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_position)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_blt_rect
 * DESCRIPTION
 *  set layer blt region. Display driver will merge blt rect of the layers and
 *  blt roi, so the final blt region may exceed this rect.
 * PARAMETERS
 *  x   [IN]  x coordinate, origin is layer frame buffer
 *  y   [IN]  y coordinate, origin is layer frame buffer
 *  width   [IN] blt rect width
 *  height  [IN] blt rect height
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_layer_set_blt_rect(U16 x, U16 y, U16 width, U16 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    U16 x2, y2, x_max_limit, y_max_limit;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_blt_rect)

    x2 = x + width - 1;
    y2 = y + height - 1;
    x_max_limit = gdi_act_layer->width - 1;
    y_max_limit = gdi_act_layer->height - 1;


    LIMIT_BOUND_UNSIGNED(x,  x_max_limit);
    LIMIT_BOUND_UNSIGNED(y,  y_max_limit);
    LIMIT_BOUND_UNSIGNED(x2, x_max_limit);
    LIMIT_BOUND_UNSIGNED(y2, y_max_limit);

    if (width == 0 || height == 0)
	{
    	GDI_LAYER_SET_BLT_RECT(gdi_act_layer, x, y, 0, 0);
	}
	else
	{
		GDI_LAYER_SET_BLT_RECT(gdi_act_layer, x, y, x2 - x + 1, y2 - y + 1);
	}
    

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_blt_rect)
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_clip
 * DESCRIPTION
 *  Set clip region.
 *  
 *  Will set clip region, use layer's own coordinate.
 * PARAMETERS
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  gdi_handle(?)       [IN]        Handle
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_set_clip(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_max_limit;
    S32 y_max_limit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_clip)

    if (x2 < x1)
    {
        x2 = x1;
    }
    if (y2 < y1)
    {
        y2 = y1;
    }

    x_max_limit = gdi_act_layer->width - 1;
    y_max_limit = gdi_act_layer->height - 1;

    LIMIT_BOUND(x1, 0, x_max_limit);
    LIMIT_BOUND(x2, 0, x_max_limit);
    LIMIT_BOUND(y1, 0, y_max_limit);
    LIMIT_BOUND(y2, 0, y_max_limit);

    GDI_LAYER_SET_CLIP(gdi_act_layer, x1, y1, x2, y2);

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_clip)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_reset_clip
 * DESCRIPTION
 *  Reset clip region to layer size
 *  
 *  Will reset clip region to layer's width/height.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_reset_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_reset_clip)
    GDI_LAYER_SET_CLIP(gdi_act_layer, 0, 0, gdi_act_layer->width - 1, gdi_act_layer->height - 1);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_reset_clip)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_clip
 * DESCRIPTION
 *  Get current clip region of a layer.
 * PARAMETERS
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  gdi_handle(?)       [IN]        Handle
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_get_clip(S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_clip)
    *x1 = gdi_act_layer->clipx1;
    *y1 = gdi_act_layer->clipy1;
    *x2 = gdi_act_layer->clipx2;
    *y2 = gdi_act_layer->clipy2;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_clip)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_push_clip
 * DESCRIPTION
 *  Push current clip region into stack.
 *  
 *  JF's opnion is the merge the clip region
 *  to get final clip region - need more study
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_push_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct *rect;
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    
    GDI_LOCK;
    GDI_ASSERT(gdi_act_layer->clips_top < GDI_LAYER_CLIP_STACK_COUNT);

    GDI_TRACE(GDI_TRC_PAIRED_CLIP, GDI_TRC_LAYER_PUSH_CLIP, lr, gdi_act_layer->clips_top);

    rect = &gdi_act_layer->clips[gdi_act_layer->clips_top];

    rect->x1 = gdi_act_layer->clipx1;
    rect->y1 = gdi_act_layer->clipy1;
    rect->x2 = gdi_act_layer->clipx2;
    rect->y2 = gdi_act_layer->clipy2;

    gdi_act_layer->clips_top++;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_push_and_set_clip
 * DESCRIPTION
  *  Push current clip region into stack and set clip region, use layer's 
  *  own coordinate.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_push_and_set_clip(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRC_PRINT_LR(GDI_TRC_PAIRED_CLIP);
    
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_pop_clip
 * DESCRIPTION
 *  Pop current clip region into stack.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_pop_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct *rect;
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    
    GDI_ASSERT(gdi_act_layer->clips_top > 0);
    rect = &gdi_act_layer->clips[--(gdi_act_layer->clips_top)];

    GDI_TRACE(GDI_TRC_PAIRED_CLIP, GDI_TRC_LAYER_POP_CLIP, lr, gdi_act_layer->clips_top);

    gdi_act_layer->clipx1 = rect->x1;
    gdi_act_layer->clipy1 = rect->y1;
    gdi_act_layer->clipx2 = rect->x2;
    gdi_act_layer->clipy2 = rect->y2;

    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_clip_preset
 * DESCRIPTION
 *  Set clip region.
 *  
 *  Will set clip region, use layer's own coordinate.
 * PARAMETERS
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  gdi_handle(?)       [IN]        Handle
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_set_clip_preset(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_clip_preset)

    if (GDI_LAYER.clipx1 < x1)
    {
        x1 = GDI_LAYER.clipx1;
    }
    if (GDI_LAYER.clipy1 < y1)
    {
        y1 = GDI_LAYER.clipy1;
    }
    if (GDI_LAYER.clipx2 > x2)
    {
        x2 = GDI_LAYER.clipx2;
    }
    if (GDI_LAYER.clipy2 > y2)
    {
        y2 = GDI_LAYER.clipy2;
    }

    if (x2 < x1)
    {
        x2 = x1;
    }
    if (y2 < y1)
    {
        y2 = y1;
    }

    /* the previous clip area is already in lcd area */

    GDI_LAYER_SET_CLIP(gdi_act_layer, x1, y1, x2, y2);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_clip_preset)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_opacity
 * DESCRIPTION
 *  Set opacity value.
 *  
 *  Set opacity.
 * PARAMETERS
 *  opacity_enable      [IN]        
 *  opacity_value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_layer_set_opacity(BOOL opacity_enable, U8 opacity_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_opacity)
    ret = gdi_layer_set_opacity_nb_concurrent((gdi_handle)gdi_act_layer, opacity_enable, opacity_value);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_opacity)
    
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_opacity
 * DESCRIPTION
 *  Set opacity value.
 *  
 *  Set opacity.
 * PARAMETERS
 *  *opacity_enable      [OUT]     
 *  *opacity_value       [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_layer_get_opacity(BOOL *opacity_enable, U8 *opacity_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_opacity)

    *opacity_enable = gdi_act_layer_info->opacity_enable;
    *opacity_value = gdi_act_layer_info->opacity_value;
    
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_opacity)
    return GDI_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_source_key
 * DESCRIPTION
 *  Set opacity value.
 *  
 *  Set opacity.
 * PARAMETERS
 *  source_key_enable       [IN]        
 *  source_key_value        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_layer_set_source_key(BOOL source_key_enable, gdi_color source_key_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_source_key)
    ret = gdi_layer_set_source_key_nb_concurrent((gdi_handle)gdi_act_layer, source_key_enable, source_key_value);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_source_key)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_source_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source_key_enable       [?]     
 *  source_key_value        [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_get_source_key(BOOL *source_key_enable, gdi_color *source_key_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_source_key)
    *source_key_enable = gdi_act_layer_info->source_key_enable;
    *source_key_value = gdi_act_layer_info->source_key;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_source_key)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_lock_frame_buffer
 * DESCRIPTION
 *  Blt layers.
 *  
 *  Lock blt. Avoid other to blt this layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_lock_frame_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    
    GDI_LOCK;
    GDI_LCD->blt_lock++;

    GDI_TRACE(GDI_TRC_PAIRED_CLIP, GDI_TRC_LAYER_LOCK_FRAME_BUFFER, lr, GDI_LCD->blt_lock);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_unlock_frame_buffer
 * DESCRIPTION
 *  Blt layers.
 *  
 *  Unlock layer.
 * PARAMETERS
 *  void
 *  gdi_handle(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_unlock_frame_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    
    /* unlock buffer error */
    GDI_ASSERT(GDI_LCD->blt_lock > 0);
    GDI_LCD->blt_lock--;
    GDI_UNLOCK;

    GDI_TRACE(GDI_TRC_PAIRED_CLIP, GDI_TRC_LAYER_UNLOCK_FRAME_BUFFER, lr, GDI_LCD->blt_lock);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gdi_layer_get_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   U8 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_rotate)
    ret = gdi_act_layer->rotate_value;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_rotate)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_region_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x1                  [?]         
 *  y1                  [?]         
 *  x2                  [?]         
 *  y2                  [?]         
 *  dest_width          [IN]        
 *  dest_height         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_rotate_map_region_internal(
        U8 rotate_value,
        S32 *x1,
        S32 *y1,
        S32 *x2,
        S32 *y2,
        S32 dest_width,
        S32 dest_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 tx1, ty1, tx2, ty2;

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx1 = dest_width - *y2 - 1;
            ty1 = *x1;
            tx2 = dest_width - *y1 - 1;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx1 = dest_width - *x2 - 1;
            ty1 = dest_height - *y2 - 1;
            tx2 = dest_width - *x1 - 1;
            ty2 = dest_height - *y1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx1 = *y1;
            ty1 = dest_height - *x2 - 1;
            tx2 = *y2;
            ty2 = dest_height - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx1 = dest_width - *x2 - 1;
            tx2 = dest_width - *x1 - 1;
            *x1 = tx1;
            *x2 = tx2;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx1 = dest_width - *y2 - 1;
            ty1 = dest_height - *x2 - 1;
            tx2 = dest_width - *y1 - 1;
            ty2 = dest_height - *x1 - 1;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty1 = dest_height - *y2 - 1;
            ty2 = dest_height - *y1 - 1;
            *y1 = ty1;
            *y2 = ty2;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx1 = *y1;
            ty1 = *x1;
            tx2 = *y2;
            ty2 = *x2;
            *x1 = tx1;
            *y1 = ty1;
            *x2 = tx2;
            *y2 = ty2;
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_layer_to_lcd_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x1                  [?]         
 *  y1                  [?]         
 *  x2                  [?]         
 *  y2                  [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_layer_to_lcd_region(U8 rotate_value, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lcd_width, lcd_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    
#if defined(GDI_USING_LCD_ROTATE)
    if (!GDI_LCD->rotate_by_layer)
    {
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    }
    else
#endif /* defined(GDI_USING_LCD_ROTATE) */ 
    {
        lcd_width = GDI_LCD->act_width;
        lcd_height = GDI_LCD->act_height;
    }

    gdi_rotate_map_region_internal(rotate_value, x1, y1, x2, y2, lcd_width, lcd_height);
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_layer_to_lcd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x                   [?]         
 *  y                   [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_layer_to_lcd(U8 rotate_value, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_layer_to_lcd)
    S32 tx, ty;
    S32 lcd_width, lcd_height;

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx = lcd_width - *y - 1;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx = lcd_width - *x - 1;
            ty = lcd_height - *y - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx = *y;
            ty = lcd_height - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx = lcd_width - *x - 1;
            *x = tx;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx = lcd_width - *y - 1;
            ty = lcd_height - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty = lcd_height - *y - 1;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx = *y;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_layer_to_lcd)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_rotate_map_lcd_to_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 *  x                   [?]         
 *  y                   [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_rotate_map_lcd_to_layer(U8 rotate_value, S32 *x, S32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_rotate_map_lcd_to_layer)
    S32 tx, ty;
    S32 lcd_width, lcd_height;

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    switch (rotate_value)
    {
        case GDI_LCD_LAYER_ROTATE_0:
        default:
            break;
        case GDI_LCD_LAYER_ROTATE_90:
            tx = *y;
            ty = lcd_width - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180:
            tx = lcd_width - *x - 1;
            ty = lcd_height - *y - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270:
            tx = lcd_height - *y - 1;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_0_MIRROR:
            tx = lcd_width - *x - 1;
            *x = tx;
            break;
        case GDI_LCD_LAYER_ROTATE_90_MIRROR:
            tx = lcd_width - *y - 1;
            ty = lcd_height - *x - 1;
            *x = tx;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_180_MIRROR:
            ty = lcd_height - *y - 1;
            *y = ty;
            break;
        case GDI_LCD_LAYER_ROTATE_270_MIRROR:
            tx = *y;
            ty = *x;
            *x = tx;
            *y = ty;
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_rotate_map_lcd_to_layer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_waiting_blt_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_waiting_blt_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_time = 0, decode_ms = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * DebugPrint() will call flatten which invokes this to wait for nonblocking blt.
     * Since kal assertion disables IRQ, lcd interface driver has no chance to 
     * set gdi_is_bliting to FALSE. Hence, the infinite loop here makes memory dump impossible.
     */
    if (INT_Exception_Enter)
    {
        return;
    }
    
    do
    {
    /*
        GDI_LCD_LOCK_MUTEX;
        if (gdi_is_blting == FALSE)
        {
            break;
        }
        GDI_LCD_UNLOCK_MUTEX;
        kal_sleep_task(1);
    */
        
        kal_uint32 event;
        GDI_LCD_LOCK_MUTEX;
        if (gdi_is_blting == FALSE)
        {
            kal_set_eg_events(gdi_event_group, ~GDI_BLT_FINISH, KAL_AND);
            break;
        }

        start_time = drv_get_current_time();
        kal_retrieve_eg_events(gdi_event_group, GDI_BLT_FINISH, KAL_OR_CONSUME, &event, KAL_SUSPEND);
        decode_ms = drv_get_duration_ms(start_time);        
    } while (0);
        
    GDI_BRIEF_TRACE(GDI_TRC_LAYER, GDI_LAYER_BLT_WAIT_BLT_FINISH,//[gdi_waiting_blt_finish]: duration:%d
        decode_ms);
        
    GDI_LCD_UNLOCK_MUTEX;    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_flatten_is_ready
 * DESCRIPTION
 *  Check if flatten is available or not.
 *  When multimedia is running, using LCD to flatten is not allowed. 
 *  But we can use GOVL to do it, so it always return true on MT6236.
 * PARAMETERS       
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool gdi_layer_flatten_is_ready(void)
{
#ifdef __MTK_TARGET__
#if defined(GDI_GOVL_SUPPORT)

    return KAL_TRUE;
    
#else
    kal_bool flatten_is_ready;

    flatten_is_ready = (kal_bool)wfcGetContextAttribi(
                                    gdi_lcd_v2_dev, 
                                    gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle, 
                                    WFC_CONTEXT_IS_FLATTEN_READY_MTK);

    return flatten_is_ready;
#endif
#else
    return KAL_TRUE;
#endif
}


static void gdi_layer_flatten_nb_dummy_callback(void *unused_param)
{
    /* Do nothing */
}


void gdi_layer_flatten_nb_wait_for_previous_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GDI_LCD_LOCK_MUTEX;
    
    if (gdi_layer_flatten_nb_session.doing_flatten)
    {
        kal_uint32 event;
        kal_retrieve_eg_events(gdi_event_group, GDI_FLATTEN_FINISH, KAL_OR_CONSUME, &event, KAL_SUSPEND);
    }
    
    GDI_LCD_UNLOCK_MUTEX;

    /* Another non-blocking flatten may start before this function return */
}


static void gdi_layer_flatten_nb_init_state(
    void (*non_blocking_callback)(void *param),
    void *param)
{
    gdi_layer_flatten_nb_session.doing_flatten = KAL_TRUE;
    gdi_layer_flatten_nb_session.finish_callback = non_blocking_callback;
    gdi_layer_flatten_nb_session.param = param;

    /* Clear event flag for another waiting */
    kal_set_eg_events(gdi_event_group, ~((kal_uint32)GDI_FLATTEN_FINISH), KAL_AND);
}


static void gdi_layer_flatten_nb_finish_handler(void* unused_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void (*callback)(void*);
    void *callback_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callback = gdi_layer_flatten_nb_session.finish_callback;
    callback_param = gdi_layer_flatten_nb_session.param;
    gdi_layer_flatten_nb_session.finish_callback = NULL;
    gdi_layer_flatten_nb_session.param = NULL;

    GDI_BRIEF_TRACE(GDI_TRC_LAYER, GDI_LAYER_FLATTEN_NB_CALLBACK, (kal_uint32)callback);

    /*
     * This handler will only run on HISR or GDI task.
     * We assume this callback will not be preempted by VRT or MMI or
     * other lower-priority task who uses GDI. Otherwise, there will be
     * racing.
     */
    gdi_layer_flatten_nb_session.doing_flatten = KAL_FALSE;
    kal_set_eg_events(gdi_event_group, GDI_FLATTEN_FINISH, KAL_OR);
    
    if (callback != NULL)
    {
        callback(callback_param);
    }
}


#ifdef GDI_GOVL_SUPPORT

#ifdef __MTK_TARGET__
#pragma arm
#endif

static FLATTENRotationType gdi_layer_govl_to_drv_roataion_type(kal_uint32 layer_rotation)
{
    FLATTENRotationType drv_rotation = FLATTEN_ROTATION_0;

    switch (layer_rotation)
    {
        case GDI_LAYER_ROTATE_90:
            drv_rotation = FLATTEN_ROTATION_90;
            break;

        case GDI_LAYER_ROTATE_180:
            drv_rotation = FLATTEN_ROTATION_180;
            break;

        case GDI_LAYER_ROTATE_270:
            drv_rotation = FLATTEN_ROTATION_270;
            break;
    
        case GDI_LAYER_ROTATE_0:
        default:
            break;
    }

    return drv_rotation;
}


static void gdi_layer_govl_to_drv_pixel_format(
    kal_uint32 layer_cf,
    FLATTEN_PIXEL_FORMAT *out_format,
    kal_bool *out_premultiplied,
    kal_int32 *out_bytes_per_pixel)
{
    *out_premultiplied = KAL_FALSE;

    switch (layer_cf)
    {
        case GDI_COLOR_FORMAT_8:
            *out_format = FLATTEN_IMAGE_L8;
            *out_bytes_per_pixel = 1;
            break;
            
        case GDI_COLOR_FORMAT_16:
            *out_format = FLATTEN_IMAGE_RGB565;
            *out_bytes_per_pixel = 2;
            break;
            
        case GDI_COLOR_FORMAT_24:
            *out_format = FLATTEN_IMAGE_RGB888;
            *out_bytes_per_pixel = 3;
            break;
            
        case GDI_COLOR_FORMAT_32:
            *out_format = FLATTEN_IMAGE_ARGB8888;
            *out_bytes_per_pixel = 4;
            break;
            
        case GDI_COLOR_FORMAT_32_PARGB:
            *out_format = FLATTEN_IMAGE_ARGB8888;
            *out_bytes_per_pixel = 4;
            *out_premultiplied= KAL_TRUE;
            break;
            
        case GDI_COLOR_FORMAT_UYVY422:
            *out_format = FLATTEN_IMAGE_UYVY;
            *out_bytes_per_pixel = 2;
            break;

        case GDI_COLOR_FORMAT_PARGB6666:
            *out_format = FLATTEN_IMAGE_ARGB6666;
            *out_bytes_per_pixel = 3;
            *out_premultiplied= KAL_TRUE;
            break;

        default:
            /* To avoid build warning */
            *out_format = FLATTEN_IMAGE_NOT_SUPPORTED;
            *out_bytes_per_pixel = 0;
            GDI_ASSERT(0);
            break;
    }
}


static void gdi_layer_govl_config_layer(
    gdi_handle layer_handle,
    FlattenLayerType drv_flatten_layer,
    kal_uint8 output_buf_rotate_value,
    kal_int32 output_buf_offset_x,
    kal_int32 output_buf_offset_y,
    kal_int32 output_buf_w,
    kal_int32 output_buf_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer_struct;
    gdi_lcd_layer_struct *layer_info;
    FlattenLayerStruct drv_layer_param;
    gdi_rect_struct world_rect;
    FlattenResultEnum config_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_struct = (gdi_layer_struct*)layer_handle;
    /* check layer handle */
    GDI_ASSERT(layer_handle >= GDI_LAYER_VALID_HANDLE_START);            /* invalid layer handle value */
    GDI_ASSERT(GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_USED));   /* layer is already freed */
#if !defined(LCD_LAYER_SOURCE_COLOR_PARGB8888)
    GDI_ASSERT(layer_struct->cf != GDI_COLOR_FORMAT_32_PARGB);    /* not support blt PARGB */
#endif
#if !defined(LCD_LAYER_SOURCE_COLOR_UYVY422)
    GDI_ASSERT(layer_struct->cf != GDI_COLOR_FORMAT_UYVY422);     /* not support blt UYVY422 */
#endif
    
    layer_info = &gdi_layer_info[layer_struct->id];

    /* Source rotation */
    layer_info->rotate_value = (U8) ((((GDI_LCD_LAYER_ROTATE_MIRROR_MASK & output_buf_rotate_value) |
                                       (0x04 - (GDI_LCD_LAYER_ROTATE_ANGLE_MASK & output_buf_rotate_value))) +
                                      layer_struct->rotate_value) & GDI_LCD_LAYER_ROTATE_ALL_MASK);

    drv_layer_param.rotationAngle = gdi_layer_govl_to_drv_roataion_type(layer_info->rotate_value);

    drv_layer_param.transparencyType = 0;
    if (layer_info->source_key_enable)
    {
        drv_layer_param.transparencyType |= FLATTEN_TRANSPARENCY_SOURCE_COLOR_KEY;
        drv_layer_param.sourceColorKey = layer_info->source_key;
    }
    if (layer_info->opacity_enable)
    {
        drv_layer_param.transparencyType |= FLATTEN_TRANSPARENCY_GLOBAL_ALPHA;
        drv_layer_param.globalAlpha = layer_info->opacity_value;
    }

    drv_layer_param.enableSpatialDithering =
        (layer_struct->cf == GDI_COLOR_FORMAT_UYVY422) ? KAL_TRUE : KAL_FALSE;

    /* Source rectangle */
    drv_layer_param.sourceRect_x = layer_struct->blt_x;
    drv_layer_param.sourceRect_y = layer_struct->blt_y;
    drv_layer_param.sourceRect_width = layer_struct->blt_width;
    drv_layer_param.sourceRect_height = layer_struct->blt_height;

    world_rect.x1 = layer_struct->offset_x + layer_struct->blt_x;
    world_rect.y1 = layer_struct->offset_y + layer_struct->blt_y;
    world_rect.x2 = world_rect.x1 + layer_struct->blt_width - 1;
    world_rect.y2 = world_rect.y1 + layer_struct->blt_height - 1;
    if (layer_info->rotate_value != GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_rotate_map_region_internal(
            layer_info->rotate_value,
            &world_rect.x1,
            &world_rect.y1,
            &world_rect.x2,
            &world_rect.y2,
            output_buf_w,
            output_buf_h);
    }

    /* Relative position of dest layer
       not consider the rotation of output layer */
    drv_layer_param.destinationRect_x = world_rect.x1 - output_buf_offset_x;
    drv_layer_param.destinationRect_y = world_rect.y1 - output_buf_offset_y;
    drv_layer_param.destinationRect_width = 0;
    drv_layer_param.destinationRect_height = 0;
    layer_info->x_offset = drv_layer_param.destinationRect_x;
    layer_info->y_offset = drv_layer_param.destinationRect_y;

    /* Source image properties */
    drv_layer_param.image_source_width = layer_struct->width;
    drv_layer_param.image_source_height = layer_struct->height;
    gdi_layer_govl_to_drv_pixel_format(
        layer_struct->cf,
        &drv_layer_param.image_source_format_pixelFormat,
        &drv_layer_param.image_source_format_premultiplied,
        &drv_layer_param.image_source_pixelSize);
    drv_layer_param.image_source_stride =
        drv_layer_param.image_source_width * drv_layer_param.image_source_pixelSize;
    drv_layer_param.image_source_format_linear = KAL_FALSE;
    drv_layer_param.image_source_format_rowPadding = 0;
    drv_layer_param.image_source_datamax =
        drv_layer_param.image_source_width * drv_layer_param.image_source_height * drv_layer_param.image_source_pixelSize;
    drv_layer_param.image_source_alpha = 0xff;
    drv_layer_param.image_source_data = layer_struct->buf_ptr;

    drv_layer_param.flip = KAL_FALSE;
    drv_layer_param.isConstantValue = KAL_FALSE;

    config_result = FlattenConfigLayer(
        gdi_layer_govl_get_handle(),
        drv_flatten_layer,
        &drv_layer_param);
    GDI_ASSERT(config_result == FLATTEN_RESULT_OK);
}


static void gdi_layer_govl_config_target_buffer(
    FlattenCtrlStruct *out_flatten_ctrl,
    kal_uint8* output_buf_ptr,
    kal_int32 output_buf_w, 
    kal_int32 output_buf_h,
    kal_uint8 output_buf_cf)
{
    out_flatten_ctrl->memOut_image_width = output_buf_w;
    out_flatten_ctrl->memOut_image_height = output_buf_h;
    gdi_layer_govl_to_drv_pixel_format(
        output_buf_cf,
        &(out_flatten_ctrl->memOut_image_format_pixelFormat),
        &(out_flatten_ctrl->memOut_image_format_premultiplied),
        &(out_flatten_ctrl->memOut_image_pixelSize));
    out_flatten_ctrl->memOut_image_stride =
        out_flatten_ctrl->memOut_image_width * out_flatten_ctrl->memOut_image_pixelSize;
    out_flatten_ctrl->memOut_image_format_linear = KAL_FALSE;
    out_flatten_ctrl->memOut_image_format_rowPadding = 0;
    out_flatten_ctrl->memOut_image_datamax =
        output_buf_w * output_buf_h * out_flatten_ctrl->memOut_image_pixelSize;
    out_flatten_ctrl->memOut_image_alpha = 0xff;
    out_flatten_ctrl->memOut_image_data = output_buf_ptr;
}


static void gdi_layer_govl_nb_finish_hisr_callback(void *unused_cbparam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct* ilm_ptr;
    FlattenResultEnum drv_fla_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_fla_result = FlattenReleaseOwnership(gdi_layer_govl_get_handle());
    GDI_ASSERT(drv_fla_result == FLATTEN_RESULT_OK);

    if (gdi_layer_flatten_nb_session.finish_callback != NULL &&
        gdi_layer_flatten_nb_session.finish_callback != gdi_layer_flatten_nb_dummy_callback)
    {
        ilm_ptr = allocate_ilm(MOD_GDI);
        ilm_ptr->src_mod_id = MOD_GDI;
        ilm_ptr->dest_mod_id = MOD_GDI;
        ilm_ptr->msg_id = MSG_ID_GDI_GOVL_FLATTEN_CALLBACK_IND;
        ilm_ptr->local_para_ptr = NULL;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->sap_id = GDI_SAP;

        /* GDI task will invoke gdi_layer_govl_nb_callback_ind_handler() */
        msg_send_ext_queue(ilm_ptr);
    }
    else
    {
        gdi_layer_flatten_nb_session.doing_flatten = KAL_FALSE;
        kal_set_eg_events(gdi_event_group, GDI_FLATTEN_FINISH, KAL_OR);
    }
}


/* This handler will be invoked by GDI task */
void gdi_layer_govl_nb_callback_ind_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_flatten_nb_finish_handler(NULL);
}


GDI_RESULT gdi_layer_flatten_ext_internal(
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
            void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret_result= GDI_SUCCEED;
    FlattenResultEnum drv_fla_result;
    FLATTENbitfield drv_layer_enabled_bits;
    FlattenCtrlStruct flatten_ctrl;
    kal_uint32 bg_color = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_FLATTEN_ENTER, handle0, handle1, handle2, handle3, handle4, handle5,
        x1, y1, x2, y2, (kal_uint32)non_blocking_callback, 0);
        
    /* check flatten region */
    GDI_CLIP_TWO_RECT(x1, y1, x2, y2, 0, 0, output_buf_w - 1, output_buf_h - 1, GDI_DEBUG_ASSERT(0));

    gdi_layer_flatten_nb_wait_for_previous_finish();

    if (non_blocking_callback != NULL)
    {
        /*
         * Callback will not be triggered here, before the FlattenStart().
         * We can assume following function is atomic.
         */
        gdi_layer_flatten_nb_init_state(non_blocking_callback, param);
    }

    drv_fla_result = FlattenGetOwnership(
        gdi_layer_govl_get_handle(),
        KAL_TRUE,
        KAL_FALSE);
    /* wait = KAL_TRUE, the ownership must be available after FlattenGetOwnership() return */
    GDI_ASSERT(drv_fla_result == FLATTEN_RESULT_OK);

    /* Config layers */
    drv_layer_enabled_bits = 0;
    bg_color = 0;
    
    #define GDI_LAYER_GOVL_CONFIG_LAYER(handle, flatten_layer) \
        do { \
            if (handle != 0) \
            { \
                drv_layer_enabled_bits |= flatten_layer; \
                gdi_layer_govl_config_layer(handle, flatten_layer, \
                    output_buf_rotate_value, output_buf_offset_x, output_buf_offset_y, output_buf_w, output_buf_h); \
                bg_color = ((gdi_layer_struct*)handle)->background; \
            } \
        } while (0)
    {
        /* Later chips only support 4 layers */
        GDI_LAYER_GOVL_CONFIG_LAYER(handle3, FLATTEN_LAYER3);
        GDI_LAYER_GOVL_CONFIG_LAYER(handle2, FLATTEN_LAYER2);
        GDI_LAYER_GOVL_CONFIG_LAYER(handle1, FLATTEN_LAYER1);
        GDI_LAYER_GOVL_CONFIG_LAYER(handle0, FLATTEN_LAYER0);
    }
    #undef GDI_LAYER_GOVL_CONFIG_LAYER


    /* Flatten parameters */
    flatten_ctrl.flatten_enable_layer = drv_layer_enabled_bits;
    flatten_ctrl.rotationAngle = FLATTEN_ROTATION_0; /* Already rotate by layer */
    flatten_ctrl.bgColor = bg_color;
    
    gdi_layer_govl_config_target_buffer(
        &flatten_ctrl,
        output_buf_ptr,
        output_buf_w,
        output_buf_h,
        output_buf_cf);

    flatten_ctrl.enableDithering =
        (flag & GDI_LAYER_FLATTEN_FLAG_RESULT_DITHER) ? KAL_TRUE : KAL_FALSE;

    flatten_ctrl.roiRect_x = x1;
    flatten_ctrl.roiRect_y = y1;
    flatten_ctrl.roiRect_width = x2 - x1 + 1;
    flatten_ctrl.roiRect_height = y2 - y1 + 1;
    
    flatten_ctrl.destinationRect_x = x1;
    flatten_ctrl.destinationRect_y = y1;
    flatten_ctrl.destinationRect_width = flatten_ctrl.roiRect_width;
    flatten_ctrl.destinationRect_height = flatten_ctrl.roiRect_height;

    flatten_ctrl.paletteTable = 0;

    if (non_blocking_callback == NULL)
    {
        flatten_ctrl.blocking_req = KAL_TRUE;
        flatten_ctrl.flatten_nonblocking_callback = NULL;
        flatten_ctrl.cbparam = NULL;
    }
    else
    {
        flatten_ctrl.blocking_req = KAL_FALSE;
        flatten_ctrl.flatten_nonblocking_callback = gdi_layer_govl_nb_finish_hisr_callback;
        flatten_ctrl.cbparam = NULL;
    }

    drv_fla_result = FlattenStart(gdi_layer_govl_get_handle(), &flatten_ctrl);
    if (drv_fla_result != FLATTEN_RESULT_OK)
    {
        gdi_layer_flatten_nb_session.doing_flatten = KAL_FALSE;
        ret_result = GDI_FAILED;
    }

    if (non_blocking_callback == NULL || drv_fla_result != FLATTEN_RESULT_OK)
    {
        /* Blocking flatten or error */
        drv_fla_result = FlattenReleaseOwnership(gdi_layer_govl_get_handle());
        /* Release should not fail */
        GDI_ASSERT(drv_fla_result == FLATTEN_RESULT_OK);
    }
    else
    {
        /* Release ownership by gdi_layer_govl_nb_callback_ind_handler() */
    }

    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_FLATTEN_LEAVE, 0);

    return ret_result;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_finish_handler
 * DESCRIPTION
 *  This function is called by LCD driver HISR.
 *  When using non-blocking blt, use this callback to know the non-blocking blt is already finished.
 * PARAMETERS
 *  event   [IN]
 *  param   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_layer_blt_finish_handler(WFCContextEventTypeMTK event, void* param)
{
    kal_uint32 start_time = 0;
    kal_get_time(&start_time);
    GDI_BRIEF_TRACE(GDI_TRC_LAYER, GDI_LAYER_BLT_WAIT_BLT_CALLBACK,//[gdi_layer_blt_finish_handler]: Blt finish - time:%d
        start_time);
    gdi_is_blting = FALSE;
    gdi_layer_resource_hint.blt_running = KAL_FALSE;
    kal_set_eg_events(gdi_event_group, GDI_BLT_FINISH, KAL_OR);
    
    if (gdi_layer_blt_finish_callback)
    {
        gdi_layer_blt_finish_callback(gdi_layer_blt_finish_param);
        gdi_layer_set_blt_finish_callback(NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_wfc_rotate_value
 * DESCRIPTION
 *  Translate gdi layer rotate value to wfc rotate value
 * PARAMETERS
 *  layer_rotate_value   [IN]   gdi layer rotate value
 * RETURNS
 *  WFCRotation
 *****************************************************************************/
static WFCRotation gdi_layer_get_wfc_rotate_value(U32 layer_rotate_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WFCRotation rotate_value = WFC_ROTATION_0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(layer_rotate_value)
    {
        case GDI_LAYER_ROTATE_0:
            rotate_value = WFC_ROTATION_0;
            break;
        case GDI_LAYER_ROTATE_90:
            rotate_value = WFC_ROTATION_90;
            break;
        case GDI_LAYER_ROTATE_180:
            rotate_value = WFC_ROTATION_180;
            break;
        case GDI_LAYER_ROTATE_270:
            rotate_value = WFC_ROTATION_270;
            break;
        default:
            GDI_ASSERT(0);
    }
    return rotate_value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_config_owf_image
 * DESCRIPTION
 *  fill the OWF_IMAGE structure by layer buffer information.
 * PARAMETERS
 *  buf_color_format    [IN]    buffer color format
 *  buf_ptr             [IN]    buffer pointer
 *  buf_width           [IN]    buffer width
 *  buf_height          [IN]    buffer height
 *  image               [OUT]   OWF_IMAGE structure
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_layer_config_owf_image(
                U8 buf_color_format,
                U8* buf_ptr,
                U32 buf_width,
                U32 buf_height,
                OWF_IMAGE* image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    OWF_PIXEL_FORMAT color_format = OWF_IMAGE_NOT_SUPPORTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    image->format.linear = OWF_FALSE;
    image->format.premultiplied = OWF_FALSE;
    image->format.rowPadding = 0;
    switch(buf_color_format)
    {
        case GDI_COLOR_FORMAT_8:
            color_format = OWF_IMAGE_L8;
            break;
        case GDI_COLOR_FORMAT_16:
            color_format = OWF_IMAGE_RGB565;
            break;
        case GDI_COLOR_FORMAT_24:
            color_format = OWF_IMAGE_RGB888;
            break;
        case GDI_COLOR_FORMAT_32:
            color_format = OWF_IMAGE_ARGB8888;
            break;
        case GDI_COLOR_FORMAT_32_PARGB:
            color_format = OWF_IMAGE_ARGB8888;
            image->format.premultiplied = OWF_TRUE;
            break;
        case GDI_COLOR_FORMAT_UYVY422:
            color_format = OWF_IMAGE_UYVY;
            break;
        case GDI_COLOR_FORMAT_PARGB6666:
            color_format = OWF_IMAGE_ARGB6666;
            image->format.premultiplied = OWF_TRUE;
            break;
        default:
            GDI_ASSERT(0);
    }
    image->format.pixelFormat = color_format;

    /* set Source */
    image->width = buf_width;
    image->height = buf_height;
    image->foreign = OWF_TRUE; // don't care.
    image->alpha = 0xFF;
    image->data = (void*)buf_ptr;
    image->pixelSize = OWF_Image_GetFormatPixelSize(color_format);
    image->dataMax = buf_width * buf_height * image->pixelSize;               /* data buffer max size */
    image->stride = buf_width * OWF_Image_GetFormatPixelSize(color_format);    /* number of bytes per line */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_config_source
 * DESCRIPTION
 *  Each WFCElement has a WFCSource.
 *  When layer is going to blt(flatten) out, config the WFCSource.
 * PARAMETERS
 *  layer           [IN]        the layer sturcture that want to blt out
 *  ctx_handle      [IN]        WFCCoutext handle
 *  src_handle      [IN/OUT]    the 
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_layer_config_source(
                U8 buf_color_format,
                U8* buf_ptr,
                U32 buf_width,
                U32 buf_height,
                WFCContext ctx_handle,
                WFCSource *src_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    OWF_IMAGE image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(src_handle != NULL);
    
    /* set owf image */
    gdi_layer_config_owf_image(
        buf_color_format,
        buf_ptr,
        buf_width,
        buf_height,
        &image);

    /* create wfcSource for each wfcContext */
    *src_handle = wfcDestroyAndCreateSourceFromImage(gdi_lcd_v2_dev,ctx_handle,*src_handle,(WFCHandle)&image,NULL);
}


#if defined(GDI_LCD_SCANLINE_ROTATION)
static WFCRotation gdi_scanline_adjust_rotation_by_lcd_option(WFCRotation layer_rotation)
{
    WFCRotation real_rotation = layer_rotation;

#if defined(GDI_MAINLCD_SCANLINE_ROTATION_270)
    /* The setting we get from Clone is to LCD, we need to convert it to MMI */
    switch (layer_rotation)
    {
        case WFC_ROTATION_0:
            real_rotation = WFC_ROTATION_270;
            break;
        case WFC_ROTATION_90:
            real_rotation = WFC_ROTATION_0;
            break;
        case WFC_ROTATION_180:
            real_rotation = WFC_ROTATION_90;
            break;
        case WFC_ROTATION_270:
            real_rotation = WFC_ROTATION_180;
            break;
        default:
            break;
    }
#elif defined(GDI_MAINLCD_SCANLINE_ROTATION_90)
    switch (layer_rotation)
    {
        case WFC_ROTATION_0:
            real_rotation = WFC_ROTATION_90;
            break;
        case WFC_ROTATION_90:
            real_rotation = WFC_ROTATION_180;
            break;
        case WFC_ROTATION_180:
            real_rotation = WFC_ROTATION_270;
            break;
        case WFC_ROTATION_270:
            real_rotation = WFC_ROTATION_0;
            break;
        default:
            break;
    }
#endif

    return real_rotation;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_config_element
 * DESCRIPTION
 *  config WFCElement from gdi layer sturcture information.
 * PARAMETERS
 *  ctx_index               [IN]    mainlcd or sublcd or flatten
 *  element_index           [IN]    which element to config, 0~GDI_LAYER_HW_LAYER_COUNT
 *  layer_handle            [IN]    the layer needed to set to element
 *  output_rotate_value     [IN]    LCD rotate value. If output_rotate_by_layer is true, have to work around by rotate layer. No used when flatten.
 *  output_rotate_by_layer  [IN]    need to work around LCD rotate by layer rotate or not. No used when flatten.
 *  output_width            [IN]    LCD width when blt. Output buffer width when flatten.
 *  output_height           [IN]    LCD height when blt. Output buffer height when flatten.
 *  output_offset_x         [IN]    Output layer x offset when flatten. Not used when blt.
 *  output_offset_y         [IN]    Output layer y offset when flatten. Not used when blt.
 * RETURNS
 *  kal_bool, return KAL_FALSE when layer_handle is NULL. Means this element won't be blt out.
 *****************************************************************************/
static kal_bool gdi_layer_config_element(
                    gdi_lcd_v2_context_enum ctx_index,
                    U8 element_index, 
                    gdi_handle layer_handle,
                    U8 output_rotate_value,
                    kal_bool output_rotate_by_layer,
                    S32 output_width,
                    S32 output_height,
                    S32 output_offset_x,
                    S32 output_offset_y,
                    kal_bool is_blt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WFCint rect[4] = {0, 0, 0, 0};
    WFCRotation rotate_value = WFC_ROTATION_0;
    WFCbitfield transparency_type = 0;
    gdi_layer_struct *layer_struct = (gdi_layer_struct*)layer_handle;
    gdi_lcd_layer_struct *layer_info = NULL;
    S32 x1, y1, x2, y2, blt_x1, blt_y1, blt_x2, blt_y2;
#if defined(GDI_LCD_SCANLINE_ROTATION)
    GDI_RESULT rotate_result = GDI_FAILED;
#endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
    WFCCtxtRWAttrib *pContextAttrib = NULL;
    WFCElementRWAttrib wfcElementAttrib;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(element_index <= GDI_LAYER_HW_LAYER_COUNT);

    GDI_ASSERT(ctx_index < GDI_LCD_V2_CTX_MAX);
    pContextAttrib = &gdi_wfc_context_attrib[ctx_index];

    /* if layer_handle is null handle, remove element, return. */
    if (layer_handle == GDI_NULL_HANDLE)
    {
        pContextAttrib->_insertedElements[element_index] = WFC_INVALID_HANDLE;
        return KAL_FALSE;
    }

    layer_info = &gdi_layer_info[layer_struct->id];
    /* check layer handle */
    GDI_ASSERT(layer_handle >= GDI_LAYER_VALID_HANDLE_START);            /* invalid layer handle value */
    GDI_ASSERT(GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_USED));   /* layer is already freed */
#if !defined(LCD_LAYER_SOURCE_COLOR_PARGB8888)
    GDI_ASSERT(layer_struct->cf != GDI_COLOR_FORMAT_32_PARGB);    /* not support blt PARGB */
#endif
#if !defined(LCD_LAYER_SOURCE_COLOR_UYVY422)
    GDI_ASSERT(layer_struct->cf != GDI_COLOR_FORMAT_UYVY422);     /* not support blt UYVY422 */
#endif

    /* ======== set layer_info ======== */

    /* set rotate_value of layer_info */
    x1 = layer_struct->offset_x + layer_struct->blt_x;
    y1 = layer_struct->offset_y + layer_struct->blt_y;
    x2 = x1 + layer_struct->blt_width - 1;
    y2 = y1 + layer_struct->blt_height - 1;
    blt_x1 = layer_struct->blt_x;
    blt_y1 = layer_struct->blt_y;
    blt_x2 = blt_x1 + layer_struct->blt_width - 1;
    blt_y2 = blt_y1 + layer_struct->blt_height - 1;

#if defined(GDI_USING_LCD_ROTATE)
    if (!output_rotate_by_layer)
    {
        layer_info->rotate_value = layer_struct->rotate_value;
    }
    else
#endif
#if defined(GDI_USING_LAYER_ROTATE) || defined(GDI_USING_LCD_ROTATE)
    {
        layer_info->rotate_value = (U8) ((((GDI_LCD_LAYER_ROTATE_MIRROR_MASK & output_rotate_value) |
                                           (0x04 - (GDI_LCD_LAYER_ROTATE_ANGLE_MASK & output_rotate_value))) +
                                          layer_struct->rotate_value) & GDI_LCD_LAYER_ROTATE_ALL_MASK);
    }
#endif

    /* set x_offset, y_offset of layer_info */
    gdi_rotate_map_region_internal(layer_info->rotate_value,  &x1, &y1, &x2, &y2, output_width, output_height);

#if defined(GDI_LCD_SCANLINE_ROTATION)
    if (ctx_index != GDI_LCD_V2_CTX_FLATTEN)
    {
        rotate_result = gdi_scanline_rotate_buffer(element_index, &x1, &y1, &x2, &y2, &blt_x1, &blt_y1, &blt_x2, &blt_y2, is_blt);
    }
#endif

    layer_info->x_offset = x1 - output_offset_x;
    layer_info->y_offset = y1 - output_offset_y;

    /* ======== set element ======== */

    /* destination rect */
    rect[0] = layer_info->x_offset;
    rect[1] = layer_info->y_offset;
    rect[2] = 0; /* display driver calculate */
    rect[3] = 0; /* display driver calculate */
    
    if (GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_HW_UPDATE))
    {
        kal_bool hw_update = KAL_TRUE;
        kal_bool to_set_all_attrib = KAL_TRUE;

        gdi_lcd_get_hw_update(&hw_update);
    
        /* We should not modify the attributes of hw-update layer if hw-updating */
        if (hw_update)
        {
		    /*
		     * HW-update element maybe modified the attributes.
		     * As wfcSetElementAttribiv() requires all attributes at a time, we have to
		     * read the attributes back(even we don't care) then overwrite the fields we
		     * are interested in.
		     */
            wfcGetElementAttribiv(
                gdi_lcd_v2_dev,
                gdi_lcd_v2_ctx_array[ctx_index].elm[element_index],
                WFC_ELEMENT_ALL_ATTRIBUTES_MTK,
                sizeof(wfcElementAttrib)/sizeof(WFCint),
                (WFCint*)&wfcElementAttrib);
            
            to_set_all_attrib = KAL_FALSE;
        }
        else if (layer_struct->hw_update_element != 0) /* Not HW-updating but was modified by MDP */
        {
            wfcGetElementAttribiv(
                gdi_lcd_v2_dev,
                layer_struct->hw_update_element,
                WFC_ELEMENT_ALL_ATTRIBUTES_MTK,
                sizeof(wfcElementAttrib)/sizeof(WFCint),
                (WFCint*)&wfcElementAttrib);

        #if defined(GDI_LCD_SCANLINE_ROTATION)
            /* The setting we get from Clone is to LCD, we need to convert it to MMI */
            if (GDI_LCD->scanline_rotation == TRUE && ctx_index == GDI_LCD_V2_CTX_FLATTEN)
            {
                wfcElementAttrib.rotationAngle =
                    gdi_scanline_adjust_rotation_by_lcd_option(wfcElementAttrib.rotationAngle);
            }
        #endif

            to_set_all_attrib = KAL_FALSE;
        }
        else
        {
            /*
             * Not hw-updating nor MDP modified the attributes,
             * means we config the layer at first time; we have to set all attributes.
             */
            to_set_all_attrib = KAL_TRUE;
        }

        wfcElementAttrib.isVideoLayer = WFC_TRUE;

        if (!to_set_all_attrib) /* Some attributes was modified by MDP, we should not change */
        {
            wfcElementAttrib.destinationRect.x = rect[0];
            wfcElementAttrib.destinationRect.y = rect[1];
            wfcElementAttrib.destinationRect.width = rect[2];
            wfcElementAttrib.destinationRect.height = rect[3];
            
            /* set video layer */
            wfcSetElementAttribiv(gdi_lcd_v2_dev,
                gdi_lcd_v2_ctx_array[ctx_index].elm[element_index],
                WFC_ELEMENT_ALL_ATTRIBUTES_MTK,
                sizeof(wfcElementAttrib)/sizeof(WFCint),
                (WFCint*)&wfcElementAttrib);
                
            /* insert element */
            pContextAttrib->_insertedElements[element_index] = gdi_lcd_v2_ctx_array[ctx_index].elm[element_index];

            GDI_TRACE(GDI_TRC_LAYER, GDI_TRC_LAYER_CONFIG_ELEMENT_HW_UPDATE,
                (kal_uint32)layer_handle, hw_update, (kal_uint32)layer_struct->hw_update_element);

            return KAL_TRUE;
        }
    }
    else
    {
        wfcElementAttrib.isVideoLayer = WFC_FALSE;
    }

    wfcElementAttrib.destinationRect.x = rect[0];
    wfcElementAttrib.destinationRect.y = rect[1];
    wfcElementAttrib.destinationRect.width = rect[2];
    wfcElementAttrib.destinationRect.height = rect[3];
    
    /* set rotate value */
    rotate_value = gdi_layer_get_wfc_rotate_value(layer_info->rotate_value);
    wfcElementAttrib.rotationAngle = rotate_value;

    #if defined(GDI_LCD_SCANLINE_ROTATION)
    if (GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_HW_UPDATE))
    {
        wfcElementAttrib.rotationAngle = gdi_scanline_get_rotate_value(rotate_value);
    }
    #endif /* GDI_LCD_SCANLINE_ROTATION */

    /* set source rect */
    rect[0] = blt_x1;
    rect[1] = blt_y1;
    rect[2] = blt_x2 + 1 - blt_x1;
    rect[3] = blt_y2 + 1 - blt_y1;
    wfcElementAttrib.sourceRect.x = rect[0];
    wfcElementAttrib.sourceRect.y = rect[1];
    wfcElementAttrib.sourceRect.width = rect[2];
    wfcElementAttrib.sourceRect.height = rect[3];

    /* set frame buffer information (wfcSource) */
#if defined(GDI_LCD_SCANLINE_ROTATION)
    if (rotate_result == GDI_SUCCEED)
    {
        /* set owf image */
        gdi_layer_config_source(
            layer_struct->cf,
            (PU8)layer_info->frame_buffer_address,
            x2 + 1 - x1,
            y2 + 1 - y1,
            gdi_lcd_v2_ctx_array[ctx_index].ctx_handle,
            &gdi_lcd_v2_ctx_array[ctx_index].src_act[element_index]);
    }
    else
    {
        gdi_layer_config_source(
            layer_struct->cf,
            (PU8)layer_info->frame_buffer_address,
            layer_struct->width,
            layer_struct->height,
            gdi_lcd_v2_ctx_array[ctx_index].ctx_handle,
            &gdi_lcd_v2_ctx_array[ctx_index].src_act[element_index]);
    }
#else
    {
        gdi_layer_config_source(
            layer_struct->cf,
            layer_struct->buf_ptr,
            layer_struct->width,
            layer_struct->height,
            gdi_lcd_v2_ctx_array[ctx_index].ctx_handle,
            &gdi_lcd_v2_ctx_array[ctx_index].src_act[element_index]);
    }
#endif
    wfcElementAttrib.source = gdi_lcd_v2_ctx_array[ctx_index].src_act[element_index];

    /* set source key and opacity */
    if (layer_info->source_key_enable)
    {
        transparency_type |= WFC_TRANSPARENCY_SOURCE_COLOR_KEY_MTK;
        wfcElementAttrib.sourceColorKey = layer_info->source_key;
    }
    if (layer_info->opacity_enable)
    {
        transparency_type |= WFC_TRANSPARENCY_ELEMENT_GLOBAL_ALPHA;
        wfcElementAttrib.globalAlpha = layer_info->opacity_value;
    }
    wfcElementAttrib.transparencyType = transparency_type;

    /* set dithering */
    if (layer_struct->cf == GDI_COLOR_FORMAT_UYVY422)
    {
        wfcElementAttrib.enableSpatialDithering = WFC_TRUE;
    }
    else
    {
        wfcElementAttrib.enableSpatialDithering = WFC_FALSE;
    }

    /* others */
    wfcElementAttrib.flip = WFC_FALSE;

    wfcSetElementAttribiv(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[ctx_index].elm[element_index], WFC_ELEMENT_ALL_ATTRIBUTES_MTK, sizeof(wfcElementAttrib)/sizeof(WFCint), (WFCint *)&wfcElementAttrib);

    /* insert element */
    pContextAttrib->_insertedElements[element_index] = gdi_lcd_v2_ctx_array[ctx_index].elm[element_index];

#if 0 /* Too large amount of logs, to turn on only if necessary */
/* under construction !*/
/* under construction !*/
#endif
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_config_context
 * DESCRIPTION
 *  config WFCContext of blt or flatten
 * PARAMETERS
 *  lcd_context                 [IN]    which WFCContext to be config
 *  bg_color                    [IN]    the background color.
 *  lcd_actual_rotate_value     [IN]    LCD rotate value. 0 when flatten or rotate by layer.
 *  is_blocking                 [IN]    blocking or non-blocking.
 *  dest_x1                     [IN]    destination rect
 *  dest_y1                     [IN]    destination rect
 *  dest_x2                     [IN]    destination rect
 *  dest_y2                     [IN]    destination rect
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_layer_config_context(
                WFCContext lcd_context,
                WFCCtxtRWAttrib *pContextAttrib,
                gdi_color bg_color,
                U8 lcd_actual_rotate_value,
                void (*finish_callback_func)(WFCContextEventTypeMTK, void*),
                S32 dest_x1,
                S32 dest_y1,
                S32 dest_x2,
                S32 dest_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WFCint dest_rect[4] = {0};
    WFCRotation rotate_value = WFC_ROTATION_0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * We have to guarantee all attributes in WFCCtxtRWAttrib are configured
     * The only one exception is enableVsync field, wfcSetContextAttribiv()
     * will ignore this field.
     */
    pContextAttrib->enableVsync = WFC_TRUE;

    /* bg color */
    pContextAttrib->bgColor = bg_color;
    
    /* rotate value */
    rotate_value = gdi_layer_get_wfc_rotate_value(lcd_actual_rotate_value);
    pContextAttrib->rotationAngle = rotate_value;

    /* non-blocking callback */
    if (finish_callback_func != NULL)
    {        
        pContextAttrib->gdiCallbacks[0].cbfunc = finish_callback_func;
        pContextAttrib->gdiCallbacks[0].cbparam = 0;
        pContextAttrib->gdiCallbacks[0].event = WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
    }
    else
    {
        pContextAttrib->gdiCallbacks[0].cbfunc = NULL;
        pContextAttrib->gdiCallbacks[0].cbparam = 0;
        pContextAttrib->gdiCallbacks[0].event = WFC_CONTEXT_EVENT_COMPOSITION_FINISH_MTK;
    }

    /* lcm dest rect */
    dest_rect[0] = dest_x1;
    dest_rect[1] = dest_y1;
    dest_rect[2] = dest_x2 - dest_x1 + 1;   // width
    dest_rect[3] = dest_y2 - dest_y1 + 1;   // height
    pContextAttrib->destinationRect.x = dest_rect[0];
    pContextAttrib->destinationRect.y = dest_rect[1];
    pContextAttrib->destinationRect.width = dest_rect[2];
    pContextAttrib->destinationRect.height = dest_rect[3];

    /* roi dest rect */
#if defined(GDI_USING_LCD_ROTATE)
    dest_rect[2] = dest_x1 + dest_rect[2] - 1;   // x2
    dest_rect[3] = dest_y1 + dest_rect[3] - 1;   // y2
    gdi_rotate_map_absolute_hw_to_lcd_region(lcd_actual_rotate_value, &dest_rect[0], &dest_rect[1], &dest_rect[2], &dest_rect[3]);  // ROI coordinate is based on layer not lcd
    dest_rect[2] = dest_rect[2] - dest_x1 + 1;   // width
    dest_rect[3] = dest_rect[3] - dest_y1 + 1;   // height
#endif
    pContextAttrib->roiRect.x = dest_rect[0];
    pContextAttrib->roiRect.y = dest_rect[1];
    pContextAttrib->roiRect.width = dest_rect[2];
    pContextAttrib->roiRect.height = dest_rect[3];

    wfcSetContextAttribiv(gdi_lcd_v2_dev, lcd_context, WFC_CONTEXT_ALL_ATTRIBUTES_MTK, sizeof(WFCCtxtRWAttrib)/sizeof(WFCint), (WFCint *)pContextAttrib);
}


#ifndef GDI_GOVL_SUPPORT

static void gdi_layer_flatten_ddv2_nb_finish_handler(WFCContextEventTypeMTK event, void* unused_param)
{
    gdi_layer_resource_hint.flatten_running = KAL_FALSE;
    gdi_layer_flatten_nb_finish_handler(unused_param);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_flatten_ext_internal
 * DESCRIPTION
 *  flatten layers to output buf
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_flatten_ext_internal(
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
            void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color bg_color = 0;
    OWF_IMAGE image;
    U32 start_time = 0;
    GDI_RESULT ret = GDI_SUCCEED;
    WFCCtxtRWAttrib *pContextAttrib;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /*
     * NOTICE: Should not take gdi mutex or modify any global variable in this API.
     */

    kal_get_time(&start_time);
    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_FLATTEN_ENTER, handle0, handle1, handle2, handle3, handle4, handle5,
        x1, y1, x2, y2, (kal_uint32)non_blocking_callback, start_time);
        
    /* check flatten region */
    GDI_CLIP_TWO_RECT(x1, y1, x2, y2, 0, 0, output_buf_w - 1, output_buf_h - 1, GDI_DEBUG_ASSERT(0));

    /* Set blt_running to TRUE here for the query during waiting for previous blt/flatten */
    gdi_layer_resource_hint.flatten_running = KAL_TRUE;

#if !defined(GDI_GOVL_SUPPORT)
    /* wait blt finish because flatten is using the same hardware */
    gdi_waiting_blt_finish();
#endif
    gdi_layer_flatten_nb_wait_for_previous_finish();

    /* Non-blocking blt might reset the flag, we set it again */
    gdi_layer_resource_hint.flatten_running = KAL_TRUE;

    if (non_blocking_callback != NULL)
    {
        /*
         * Callback will not be triggered here, before the wfcCompose().
         * We can assume following function is atomic.
         */
        gdi_layer_flatten_nb_init_state(non_blocking_callback, param);
    }

    wfcGetError(gdi_lcd_v2_dev);

    pContextAttrib = &gdi_wfc_context_attrib[GDI_LCD_V2_CTX_FLATTEN];
    
    /* config element and get background color */
#if defined(GDI_6_LAYERS)
    if (gdi_layer_config_element(GDI_LCD_V2_CTX_FLATTEN, 5, handle5, output_buf_rotate_value, KAL_TRUE, output_buf_w, output_buf_h, output_buf_offset_x, output_buf_offset_y, KAL_FALSE))
    {
        bg_color = ((gdi_layer_struct*)handle5)->background;
    }
    if (gdi_layer_config_element(GDI_LCD_V2_CTX_FLATTEN, 4, handle4, output_buf_rotate_value, KAL_TRUE, output_buf_w, output_buf_h, output_buf_offset_x, output_buf_offset_y, KAL_FALSE))
    {
        bg_color = ((gdi_layer_struct*)handle4)->background;
    }
#endif
    if (gdi_layer_config_element(GDI_LCD_V2_CTX_FLATTEN, 3, handle3, output_buf_rotate_value, KAL_TRUE, output_buf_w, output_buf_h, output_buf_offset_x, output_buf_offset_y, KAL_FALSE))
    {
        bg_color = ((gdi_layer_struct*)handle3)->background;
    }
    if (gdi_layer_config_element(GDI_LCD_V2_CTX_FLATTEN, 2, handle2, output_buf_rotate_value, KAL_TRUE, output_buf_w, output_buf_h, output_buf_offset_x, output_buf_offset_y, KAL_FALSE))
    {
        bg_color = ((gdi_layer_struct*)handle2)->background;
    }
    if (gdi_layer_config_element(GDI_LCD_V2_CTX_FLATTEN, 1, handle1, output_buf_rotate_value, KAL_TRUE, output_buf_w, output_buf_h, output_buf_offset_x, output_buf_offset_y, KAL_FALSE))
    {
        bg_color = ((gdi_layer_struct*)handle1)->background;
    }
    if (gdi_layer_config_element(GDI_LCD_V2_CTX_FLATTEN, 0, handle0, output_buf_rotate_value, KAL_TRUE, output_buf_w, output_buf_h, output_buf_offset_x, output_buf_offset_y, KAL_FALSE))
    {
        bg_color = ((gdi_layer_struct*)handle0)->background;
    }

    /* set destination buffer */
    /* set owf image */
    gdi_layer_config_owf_image(
        output_buf_cf, 
        output_buf_ptr,
        output_buf_w,
        output_buf_h,
        &image);

    /* config context */
    gdi_layer_config_context(
        gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle,
        pContextAttrib,
        bg_color, 
        GDI_LAYER_ROTATE_0,
        (non_blocking_callback != NULL) ? gdi_layer_flatten_ddv2_nb_finish_handler : NULL,
        x1,
        y1,
        x2,
        y2);

    /* set flatten output layer */
    wfcSetContextAttribi(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle, WFC_CONTEXT_TARGET_IMAGE_MTK, (WFCHandle)&image);

    kal_get_time(&start_time);
    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_FLATTEN_START,//[gdi_layer_flatten_ext_internal]: Start - time: %d
        start_time);
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
#endif
    /* flatten */
    wfcCommit(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle, WFC_TRUE);
    
    if (wfcGetError(gdi_lcd_v2_dev) != WFC_ERROR_NONE)
    {
        ret = GDI_FAILED;
        gdi_layer_flatten_nb_session.doing_flatten = KAL_FALSE;
    }
    else
    {
        WFCboolean wait_for_composition = (non_blocking_callback == NULL ? WFC_TRUE : WFC_FALSE);
    
        wfcCompose(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[GDI_LCD_V2_CTX_FLATTEN].ctx_handle, wait_for_composition);
        if (wfcGetError(gdi_lcd_v2_dev) != WFC_ERROR_NONE)
        {
            ret = GDI_FAILED;
            gdi_layer_flatten_nb_session.doing_flatten = KAL_FALSE;
        }
    }

    if (!gdi_layer_flatten_nb_session.doing_flatten)
    {
        gdi_layer_resource_hint.flatten_running = KAL_FALSE;
    }
    
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
#endif

    kal_get_time(&start_time);
    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_FLATTEN_LEAVE,//[gdi_layer_flatten_ext_internal]: Leave - time:%d
        start_time);
        
    return ret;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_flatten_ext
 * DESCRIPTION
 *  flatten previous blt layers to base layer
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_flatten_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5)
{
    return gdi_layer_flatten_with_flag_ext(
                handle0,
                handle1,
                handle2,
                handle3,
                handle4,
                handle5,
                0,
                NULL);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_flatten_with_clipping_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_flatten_with_clipping_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2,
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5)
{
    return gdi_layer_flatten_with_flag_ext(
                handle0,
                handle1,
                handle2,
                handle3,
                handle4,
                handle5,
                GDI_LAYER_FLATTEN_FLAG_CLIP,
                NULL);
}


GDI_RESULT gdi_layer_flatten_nb_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5,
            void (*finish_callback)(void *param),
            void *param)
{
    gdi_callback_struct callback;

    if (finish_callback != NULL)
    {
        callback.callback_func = finish_callback;
        callback.user_data = param;
    }
    else
    {
        callback.callback_func = gdi_layer_flatten_nb_dummy_callback;
        callback.user_data = NULL;
    }

    return gdi_layer_flatten_with_flag_ext(
                handle0,
                handle1,
                handle2,
                handle3,
                handle4,
                handle5,
                GDI_LAYER_FLATTEN_FLAG_NON_BLOCKING,
                &callback);
}


GDI_RESULT gdi_layer_flatten_nb_with_clip_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5,
            void (*finish_callback)(void *param),
            void *param)
{
    gdi_callback_struct callback;

    if (finish_callback != NULL)
    {
        callback.callback_func = finish_callback;
        callback.user_data = param;
    }
    else
    {
        callback.callback_func = gdi_layer_flatten_nb_dummy_callback;
        callback.user_data = NULL;
    }

    return gdi_layer_flatten_with_flag_ext(
                handle0,
                handle1,
                handle2,
                handle3,
                handle4,
                handle5,
                GDI_LAYER_FLATTEN_FLAG_NON_BLOCKING | GDI_LAYER_FLATTEN_FLAG_CLIP,
                &callback);
}


GDI_RESULT gdi_layer_flatten_with_flag_ext(
                gdi_handle handle0,
                gdi_handle handle1,
                gdi_handle handle2,
                gdi_handle handle3,
                gdi_handle handle4,
                gdi_handle handle5,
                gdi_layer_flatten_flag_bitset flag,
                const gdi_callback_struct *nb_callback)
{
    GDI_RESULT ret = GDI_SUCCEED;
    void (*non_blocking_callback)(void *param) = NULL;
    void *param = NULL;

    GDI_ENTER_CRITICAL_SECTION(gdi_layer_flatten_with_flag_ext)
    GDI_LCD_LOCK_MUTEX;

    if (flag & GDI_LAYER_FLATTEN_FLAG_NON_BLOCKING)
    {
        if (nb_callback != NULL)
        {
            non_blocking_callback = nb_callback->callback_func;
            param = nb_callback->user_data;
        }
        else
        {
            non_blocking_callback = gdi_layer_flatten_nb_dummy_callback;
            param = NULL;
        }
    }

    if (flag & GDI_LAYER_FLATTEN_FLAG_CLIP)
    {
        ret = gdi_layer_flatten_ext_internal(
                handle0, 
                handle1, 
                handle2, 
                handle3,
                handle4,
                handle5,
                gdi_act_layer->clipx1,
                gdi_act_layer->clipy1,
                gdi_act_layer->clipx2,
                gdi_act_layer->clipy2,
                gdi_act_layer->buf_ptr,
                gdi_act_layer->layer_size,
                gdi_act_layer->width,
                gdi_act_layer->height,
                gdi_act_layer->offset_x,
                gdi_act_layer->offset_y,
                gdi_act_layer->bits_per_pixel,
                gdi_act_layer->cf,
                gdi_act_layer->rotate_value,
                flag,
                non_blocking_callback,
                param);
    }
    else
    {
        ret = gdi_layer_flatten_ext_internal(
                handle0, 
                handle1, 
                handle2, 
                handle3,
                handle4,
                handle5,
                0,
                0,
                gdi_act_layer->width - 1,
                gdi_act_layer->height - 1,
                gdi_act_layer->buf_ptr,
                gdi_act_layer->layer_size,
                gdi_act_layer->width,
                gdi_act_layer->height,
                gdi_act_layer->offset_x,
                gdi_act_layer->offset_y,
                gdi_act_layer->bits_per_pixel,
                gdi_act_layer->cf,
                gdi_act_layer->rotate_value,
                flag,
                non_blocking_callback,
                param);
    }

    GDI_LCD_UNLOCK_MUTEX;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_flatten_with_flag_ext)

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_flatten_get_waiting_hint
 * DESCRIPTION
 *  The hint of flatten user need wait for flatten resource.
 *  VRT may require flatten during non-blocking blt is running.
 *  In this case, VRT will query this API to know whether GDI can perform
 *  flatten request right away. If yes, VRT will invoke GDI flatten;
 *  otherwise, VRT will use its own software flatten function.
 *
 *  [NOTE] The return value is not accurate but only a hint.
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  KAL_TRUE : will wait for flatten resource if request to flatten
 *  KAL_FALSE : NOW flatten resource MAY be available
 *****************************************************************************/
kal_bool gdi_layer_flatten_get_waiting_hint(void)
{
#ifdef GDI_GOVL_SUPPORT

    /* Not implemented, we don't need to improve GOVL case at present */
    return KAL_FALSE;
    
#else

    return (gdi_layer_resource_hint.flatten_running ||
            gdi_layer_resource_hint.blt_running);

#endif
}


#if defined(GDI_LCD_SCANLINE_ROTATION)
/*****************************************************************************
 * FUNCTION
 *  gdi_scanline_get_rotate_value
 * DESCRIPTION
 *  Set the rotate value to HW update layer.
 * PARAMETERS
 *  S32 ctx_index
 * RETURNS
 *  
 *****************************************************************************/
static WFCRotation gdi_scanline_get_rotate_value(WFCRotation wfc_rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WFCRotation real_rotation = WFC_ROTATION_0;
#if defined(GDI_LCD_SCANLINE_ROTATION)
    if (GDI_LCD->scanline_rotation == TRUE)
    {
    #if defined(GDI_MAINLCD_SCANLINE_ROTATION_270)
        switch (wfc_rotation)
        {
            case WFC_ROTATION_0:
                real_rotation = WFC_ROTATION_90;
                break;
            case WFC_ROTATION_90:
                real_rotation = WFC_ROTATION_180;
                break;
            case WFC_ROTATION_180:
                real_rotation = WFC_ROTATION_270;
                break;
            case WFC_ROTATION_270:
                real_rotation = WFC_ROTATION_0;
                break;
            default:
                break;
        }
    #elif defined(GDI_MAINLCD_SCANLINE_ROTATION_90)
        switch (wfc_rotation)
        {
            case WFC_ROTATION_0:
                real_rotation = WFC_ROTATION_270;
                break;
            case WFC_ROTATION_90:
                real_rotation = WFC_ROTATION_0;
                break;
            case WFC_ROTATION_180:
                real_rotation = WFC_ROTATION_90;
                break;
            case WFC_ROTATION_270:
                real_rotation = WFC_ROTATION_180;
                break;
            default:
                break;
        }
    #endif
    }
#endif /* GDI_LCD_SCANLINE_ROTATION */
    return real_rotation;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_scanline_get_buffer
 * DESCRIPTION
 *  To share the scanline GDI buffer with VRT.
 * PARAMETERS
 *  buf_size   [IN/OUT]   The buffer size of shared buffer
 * RETURNS
 *  PU8
 *****************************************************************************/
PU8 gdi_scanline_get_buffer(U32* buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 buf_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *buf_size = 0;

    GDI_ASSERT(GDI_LCD->scanline_rotation == FALSE);
#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    GDI_ASSERT(gdi_bltdb_is_started == KAL_FALSE);
#endif

#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    if (GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        *buf_size = GDI_BLTDB_BUF_SIZE;
        buf_ptr = gdi_bltdb_inner_blt_buf;
    }
#endif
#if defined(GDI_SUBLCD_SCANLINE_ROTATION)
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        *buf_size = GDI_SUBLCD_SCANLINE_ROTATION_BUF_SIZE;
        buf_ptr = gdi_sublcd_scanline_rotation_buf;
    }
#endif
    return buf_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_scanline_set_blt_layer
 * DESCRIPTION
 *  Set Blt layers.
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
static GDI_RESULT gdi_scanline_set_blt_layer(
                   gdi_handle handle0,
                   gdi_handle handle1,
                   gdi_handle handle2,
                   gdi_handle handle3,
                   gdi_handle handle4,
                   gdi_handle handle5)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    gdi_layer_blt_flag_bit_set flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = 0;
    if (gdi_is_non_block_blt)
    {
        flag |= GDI_LAYER_BLT_FLAG_NON_BLOCKING;
    }
    
    ret =  gdi_layer_blt_ext_internal(
               handle0,
               handle1,
               handle2,
               handle3,
               handle4,
               handle5,
               GDI_LCD->blt_rect.x1,
               GDI_LCD->blt_rect.y1,
               GDI_LCD->blt_rect.x2,
               GDI_LCD->blt_rect.y2,
               flag,
               NULL);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_scanline_layer_blt
 * DESCRIPTION
 *  Blt layers.
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
static GDI_RESULT gdi_scanline_layer_blt(
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
                   gdi_layer_blt_flag_bit_set flag,
                   const gdi_callback_struct *nb_finish_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For common UI screen, flatten and rotate the layer */
    gdi_result temp_ret;
    PU8 flatten_buf = NULL, rotate_buf = NULL;
    S32 buf_size = 0;
    U32 bits_per_pixel;
    U8 rotate_angle = GDI_LAYER_ROTATE_0;
    S32 start_time = 0;

    gdi_lcd_v2_context_enum ctx_index = GDI_LCD_V2_CTX_BLT_MAIN_LCD;
    S32 temp_hw_layer_count = 0;
    gdi_handle temp_hw_layer_handle[GDI_LAYER_HW_LAYER_COUNT] = {0};
    U32 temp_hw_layer_element[GDI_LAYER_HW_LAYER_COUNT]= {0};

#ifdef GDI_SUBLCD_SCANLINE_ROTATION
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        flatten_buf = gdi_sublcd_scanline_rotation_buf;
        buf_size = (GDI_SUBLCD_SCANLINE_ROTATION_BUF_SIZE >> 1);
    }
#endif
    if (GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        flatten_buf = gdi_bltdb_inner_blt_buf;
        buf_size = (GDI_BLTDB_BUF_SIZE >> 1);
    }
    bits_per_pixel = gdi_bits_per_pixel(GDI_LCD->cf);
    GDI_ASSERT(buf_size >= (GDI_LCD->act_width * GDI_LCD->act_height * (bits_per_pixel >> 3)));
    rotate_buf = flatten_buf + buf_size;

    kal_get_time(&start_time);
    kal_prompt_trace(MOD_GDI, "gdi_scanline_layer_blt: Enter time %d", start_time);
    temp_ret =  gdi_layer_flatten_ext_internal(
                    handle0,
                    handle1,
                    handle2,
                    handle3,
                    handle4,
                    handle5,
                    0,
                    0,
                    GDI_LCD->act_width - 1,
                    GDI_LCD->act_height - 1,
                    flatten_buf,
                    GDI_LCD->act_width * GDI_LCD->act_height * (bits_per_pixel >> 3),
                    GDI_LCD->act_width,
                    GDI_LCD->act_height,
                    0,
                    0,
                    bits_per_pixel,
                    GDI_LCD->cf,
                    0,
                    0,
                    NULL,
                    NULL);
    GDI_ASSERT(temp_ret == GDI_SUCCEED);
    kal_get_time(&start_time);
    kal_prompt_trace(MOD_GDI, "gdi_scanline_layer_blt: flatten time %d", start_time);

    if (GDI_LCD->scanline_blt_handle == GDI_NULL_HANDLE)
    {
        temp_ret = gdi_layer_create_cf_double_using_outside_memory(
                       GDI_LCD->cf,
                       0,
                       0,
                       GDI_LCD->act_width,
                       GDI_LCD->act_height,
                       &(GDI_LCD->scanline_blt_handle),
                       rotate_buf,
                       GDI_LCD->act_width * GDI_LCD->act_height * (bits_per_pixel >> 3),
                       flatten_buf,
                       GDI_LCD->act_width * GDI_LCD->act_height * (bits_per_pixel >> 3));
        GDI_ASSERT(GDI_LCD->scanline_blt_handle != NULL);
    }
    GDI_ASSERT(temp_ret == GDI_SUCCEED);

    /* If have HW update layer, we need to keep and recover it */
    if ((handle0 != NULL) &&
        (GDI_LAYER_GET_FLAG(handle0, GDI_LAYER_FLAG_HW_UPDATE)))
    {
        gdi_layer_struct* temp_layer = (gdi_layer_struct*)handle0;
        if (temp_layer->hw_update_element != 0)
        {
            temp_hw_layer_handle[0] = handle0;
            temp_hw_layer_count++;
        }
    }
    if ((handle1 != NULL) &&
        (GDI_LAYER_GET_FLAG(handle1, GDI_LAYER_FLAG_HW_UPDATE)))
    {
        gdi_layer_struct* temp_layer = (gdi_layer_struct*)handle1;
        if (temp_layer->hw_update_element != 0)
        {
            temp_hw_layer_handle[1] = handle1;
            temp_hw_layer_count++;
        }
    }
    if ((handle2 != NULL) &&
        (GDI_LAYER_GET_FLAG(handle2, GDI_LAYER_FLAG_HW_UPDATE)))
    {
        gdi_layer_struct* temp_layer = (gdi_layer_struct*)handle2;
        if (temp_layer->hw_update_element != 0)
        {
            temp_hw_layer_handle[2] = handle2;
            temp_hw_layer_count++;
        }
    }
    if ((handle3 != NULL) &&
        (GDI_LAYER_GET_FLAG(handle3, GDI_LAYER_FLAG_HW_UPDATE)))
    {
        gdi_layer_struct* temp_layer = (gdi_layer_struct*)handle3;
        if (temp_layer->hw_update_element != 0)
        {
            temp_hw_layer_handle[3] = handle3;
            temp_hw_layer_count++;
        }
    }
#if (GDI_LAYER_HW_LAYER_COUNT > 4)
    if ((handle4 != NULL) &&
        (GDI_LAYER_GET_FLAG(handle4, GDI_LAYER_FLAG_HW_UPDATE)))
    {
        gdi_layer_struct* temp_layer = (gdi_layer_struct*)handle4;
        if (temp_layer->hw_update_element != 0)
        {
            temp_hw_layer_handle[4] = handle4;
            temp_hw_layer_count++;
        }
    }
    if ((handle5 != NULL) &&
        (GDI_LAYER_GET_FLAG(handle5, GDI_LAYER_FLAG_HW_UPDATE)))
    {
        gdi_layer_struct* temp_layer = (gdi_layer_struct*)handle5;
        if (temp_layer->hw_update_element != 0)
        {
            temp_hw_layer_handle[5] = handle5;
            temp_hw_layer_count++;
        }
    }
#endif /* (GDI_LAYER_HW_LAYER_COUNT > 4) */
    GDI_ASSERT(temp_hw_layer_count <= GDI_LCD_HW_UPDATE_LAYER_MAX);
#if defined( __MMI_SUBLCD__)
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        ctx_index = GDI_LCD_V2_CTX_BLT_SUB_LCD;
    }
#endif

    /* Store the HW update layer setting */
    if (temp_hw_layer_count > 0)
    {
        S32 i;
        for (i = 0; i < GDI_LAYER_HW_LAYER_COUNT; i++)
        {
            if (temp_hw_layer_handle[i] != NULL)
            {
                gdi_layer_struct* temp_layer = (gdi_layer_struct*)(temp_hw_layer_handle[i]);
                /* copy the hw update element to hw layer struct */
                temp_hw_layer_element[i] = temp_layer->hw_update_element;
            }
        }
    }

    ret = gdi_layer_blt_ext_internal(
              GDI_LCD->scanline_blt_handle,
              NULL,
              NULL,
              NULL,
              NULL,
              NULL,
              x1,
              y1,
              x2,
              y2,
              flag,
              nb_finish_callback);
    kal_get_time(&start_time);
    kal_prompt_trace(MOD_GDI, "gdi_scanline_layer_blt: blt time %d", start_time);

    /* Recover the HW update layer setting */
    if (temp_hw_layer_count > 0)
    {
        S32 i;
        for (i = 0; i < GDI_LAYER_HW_LAYER_COUNT; i++)
        {
            if (temp_hw_layer_handle[i] != NULL)
            {
                wfcCloneElementAttribute(
                    gdi_lcd_v2_dev,
                    (WFCHandle)temp_hw_layer_element[i],         // source
                    gdi_lcd_v2_ctx_array[ctx_index].elm[i]);    // destination
            }
        }
    }

    gdi_layer_set_blt_layer_ext_internal(
        handle0,
        handle1,
        handle2,
        handle3,
        handle4,
        handle5);

    kal_get_time(&start_time);
    kal_prompt_trace(MOD_GDI, "gdi_scanline_layer_blt: Leave time %d", start_time);
    return ret;
}


static void gdi_scanline_map_rotate_region(
                   S32 *x1,
                   S32 *y1,
                   S32 *x2,
                   S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rotate_angle = GDI_LAYER_ROTATE_0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
    #if defined(GDI_SUBLCD_SCANLINE_ROTATION_270)
        rotate_angle = GDI_LAYER_ROTATE_90; /* sw rotator rotate clock-wise. */
    #elif defined(GDI_SUBLCD_SCANLINE_ROTATION_90)
        rotate_angle = GDI_LAYER_ROTATE_270;
    #endif
    }
    if (GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
    #if defined(GDI_MAINLCD_SCANLINE_ROTATION_270)
        rotate_angle = GDI_LAYER_ROTATE_90; /* sw rotator rotate clock-wise. */
    #elif defined(GDI_MAINLCD_SCANLINE_ROTATION_90)
        rotate_angle = GDI_LAYER_ROTATE_270;
    #endif
    }
    gdi_rotate_map_region_internal(
        rotate_angle,
        x1,
        y1,
        x2,
        y2,
        GDI_LCD->act_height,
        GDI_LCD->act_width);
}


static GDI_RESULT gdi_scanline_rotate_buffer(
                   U8 index,
                   S32 *x1,
                   S32 *y1,
                   S32 *x2,
                   S32 *y2,
                   S32 *blt_x1,
                   S32 *blt_y1,
                   S32 *blt_x2,
                   S32 *blt_y2,
                   kal_bool need_rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct* blt_layer = GDI_NULL_HANDLE;
    S8 rotate_angle = GDI_LAYER_ROTATE_0;
    S32 output_width, output_height;
    S32 output_x1 = 0, output_y1 = 0, output_x2 = 0, output_y2 = 0;
    GDI_RESULT ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* We not hanlde rotate for Venus */
        if (GDI_LCD->scanline_rotation == FALSE)
        {
            break;
        }

        /* skip null handle */
        if (GDI_LCD->blt_handle[index] == GDI_NULL_HANDLE)
        {
            break;
        }

        blt_layer = (gdi_layer_struct*)GDI_LCD->blt_handle[index];

        /* Only three type layer need to handle rotate:
         * 1. blt layer in common UI screen
         * 2. OSD layer when HW update
         * 3. We need help adjust offset of HW update layer when it update
         * Other layers, we will not handle it
         */
        if (((GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE) &&
            (GDI_LCD->scanline_blt_handle != GDI_LCD->blt_handle[index])) ||
            ((GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE) &&
             (GDI_LCD->scanline_blt_handle != GDI_LCD->blt_handle[index]) &&
             !(GDI_LAYER_GET_FLAG((GDI_LCD->blt_handle[index]), GDI_LAYER_FLAG_HW_UPDATE))
#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
            && (!gdi_bltdb_is_started)
        #endif
             ))
        {
            break;
        }

    /* We not handle SUBLCD, because we not have SUBLCD video feature */
    #if defined(GDI_MAINLCD_SCANLINE_ROTATION_270)
        switch (gdi_layer_info[blt_layer->id].rotate_value)
        {
            case GDI_LAYER_ROTATE_0:
                rotate_angle = GDI_LAYER_ROTATE_90;
                break;
            case GDI_LAYER_ROTATE_180:
                rotate_angle = GDI_LAYER_ROTATE_270;
                break;
            case GDI_LAYER_ROTATE_270:
                rotate_angle = GDI_LAYER_ROTATE_180;
                break;
            case GDI_LAYER_ROTATE_90:
            default:
                break;
        }
    #elif defined(GDI_MAINLCD_SCANLINE_ROTATION_90)
        /* 4 means 360 */
        rotate_angle = 4 - (gdi_layer_info[blt_layer->id].rotate_value + GDI_LAYER_ROTATE_90);
    #endif
    
        /* Calculate the real output buffer's width and height */
        output_x1 = blt_layer->offset_x;
        output_y1 = blt_layer->offset_y;
        output_x2 = output_x1 + blt_layer->width - 1;
        output_y2 = output_y1 + blt_layer->height - 1;
        /* Rotate the layer (x1,y1) (x2,y2) to scanline LCD */
        gdi_rotate_map_region_internal(
            gdi_layer_info[blt_layer->id].rotate_value,
            &output_x1, &output_y1, &output_x2, &output_y2,
            GDI_LCD->act_width, GDI_LCD->act_height);
        gdi_scanline_map_rotate_region(&output_x1, &output_y1, &output_x2, &output_y2);
        output_width = output_x2 + 1 - output_x1;
        output_height = output_y2 + 1 - output_y1;

        gdi_scanline_map_rotate_region(x1, y1, x2, y2);
        /* We only need change the dst_rect of HW update layer */
        if (GDI_LAYER_GET_FLAG((GDI_LCD->blt_handle[index]), GDI_LAYER_FLAG_HW_UPDATE))
        {
            break;
        }

        *blt_x1 = *x1 - output_x1;
        *blt_y1 = *y1 - output_y1;
        *blt_x2 = *x2 - output_x1;
        *blt_y2 = *y2 - output_y1;


        if ((need_rotate == KAL_FALSE)
        #if defined(GDI_MAINLCD_SCANLINE_ROTATION)
            && (gdi_scanline_force_rotate == KAL_FALSE)
        #endif
            )
        {
            break;
        }

        /* set content of blt_buf_ptr */
        /* When GDI_MAINLCD_SCANLINE_ROTATION, 
         * GDI rotate layer content and layer setting
         */
        if ((GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE) ||
            ((GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
        #if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
             && (gdi_bltdb_is_started == KAL_FALSE)
        #endif
           ))
        {
            if (GDI_LCD->scanline_blt_handle == GDI_LCD->blt_handle[index])
            {
                /* Only when we really need blt common UI, then we will rotate the buffer */
                gdi_util_rotator(
                    GDI_ROTATOR_DEFAULT,
                    rotate_angle,
                    blt_layer->buf_ptr1,
                    blt_layer->cf,
                    blt_layer->width,
                    blt_layer->height,
                    0,
                    0,
                    blt_layer->width,
                    blt_layer->height,
                    blt_layer->buf_ptr,
                    blt_layer->cf, 
                    output_width,
                    output_height,
                    0,
                    0,
                    output_width,
                    output_height);
            }
        }
        else
        {
        #if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
            gdi_util_rotator(
                GDI_ROTATOR_DEFAULT,
                rotate_angle,
                blt_layer->buf_ptr,
                blt_layer->cf,
                blt_layer->width,
                blt_layer->height,
                0,
                0,
                blt_layer->width,
                blt_layer->height,
                gdi_bltdb_blt_layer[index].blt_buf_ptr,
                blt_layer->cf, 
                output_width,
                output_height,
                0,
                0,
                output_width,
                output_height);
        #else
            GDI_ASSERT(0);
        #endif /* __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ */
        }
        gdi_layer_info[blt_layer->id].rotate_value = GDI_LAYER_ROTATE_0;
        ret = GDI_SUCCEED;

    } while(0);

    return ret;
}


static kal_bool gdi_scanline_intercept_blt(
    gdi_lcd_cntx_struct* lcd,
    gdi_layer_blt_flag_bit_set flag)
{
    return (lcd->scanline_rotation == TRUE) &&
           (lcd->blt_lock == 0) &&
           ( (lcd->act_handle == GDI_LCD_SUB_LCD_HANDLE) ||
             (    (lcd->act_handle == GDI_LCD_MAIN_LCD_HANDLE)
         #if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
               && (gdi_bltdb_is_started == KAL_FALSE)
         #endif
             )
           );
}

#endif /* GDI_LCD_SCANLINE_ROTATION */


#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
static GDI_RESULT gdi_bltdb_blt_with_double_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    U32 used_blt_buf_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if (!gdi_bltdb_is_started || (GDI_LCD->act_handle != GDI_LCD_MAIN_LCD_HANDLE))
        {
            break;
        }    

        for(i = 0; i < GDI_LAYER_HW_LAYER_COUNT ; i++ )
        {
            gdi_layer_struct* blt_layer = (gdi_layer_struct*)GDI_LCD->blt_handle[i];

            /* skip hw update layer and null handle */
            if ((GDI_LCD->blt_handle[i] == GDI_NULL_HANDLE) ||                          // null handle
                //(GDI_LCD->blt_handle[i] == gdi_layer_hw_update_layer_handle)
                GDI_LAYER_GET_FLAG((GDI_LCD->blt_handle[i]), GDI_LAYER_FLAG_HW_UPDATE))   // hw update layer
            {
                gdi_bltdb_blt_layer[i].blt_buf_ptr = NULL;
                gdi_bltdb_blt_layer[i].blt_buf_size = 0;
                continue;
            }

            /* set blt_buf_ptr, the really buffer blt out */
            if (blt_layer->bltdb_buf_ptr1 && blt_layer->bltdb_buf_ptr2)
            {
                /* if user already set blt buffer for bltdb */
                gdi_bltdb_blt_layer[i].blt_buf_ptr = blt_layer->bltdb_buf_ptr1;
                gdi_bltdb_blt_layer[i].blt_buf_size = blt_layer->layer_size;
            }
            else
            {
                /* if use buffer from gdi_bltdb_blt_buf_ptr */
                gdi_bltdb_blt_layer[i].blt_buf_ptr = gdi_bltdb_blt_buf_ptr[0] + used_blt_buf_size;
                gdi_bltdb_blt_layer[i].blt_buf_size = gdi_sizeof_pixels(blt_layer->cf, blt_layer->width, blt_layer->height);
                
                used_blt_buf_size += gdi_bltdb_blt_layer[i].blt_buf_size;
                ASSERT(used_blt_buf_size <= (GDI_BLTDB_BUF_SIZE >> 1));
            }

            /* set content of blt_buf_ptr */
        #if !defined(GDI_LCD_SCANLINE_ROTATION)
            memcpy(
                gdi_bltdb_blt_layer[i].blt_buf_ptr, 
                blt_layer->buf_ptr, 
                gdi_bltdb_blt_layer[i].blt_buf_size);
        #endif  /* GDI_LCD_SCANLINE_ROTATION */

            /* set frame buffer address */
            gdi_layer_info[blt_layer->id].frame_buffer_address = (U32)gdi_bltdb_blt_layer[i].blt_buf_ptr;
        
        }
    }while(0);

    return GDI_SUCCEED;
}


static void gdi_bltdb_set_blt_layer_frame_buffer_address()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gdi_bltdb_is_started || (GDI_LCD->act_handle != GDI_LCD_MAIN_LCD_HANDLE))
    {
        return;
    }
    
    for(i = 0; i < GDI_LAYER_HW_LAYER_COUNT ; i++ )
    {
        gdi_layer_struct* blt_layer = (gdi_layer_struct*)GDI_LCD->blt_handle[i];

        /* skip hw update layer and null handle */
        if ((GDI_LCD->blt_handle[i] == GDI_NULL_HANDLE) ||                          // null handle
            //(GDI_LCD->blt_handle[i] == gdi_layer_hw_update_layer_handle) || // hw update layer
            GDI_LAYER_GET_FLAG((GDI_LCD->blt_handle[i]), GDI_LAYER_FLAG_HW_UPDATE) ||   // hw update layer
            (gdi_bltdb_blt_layer[i].blt_buf_ptr == NULL))
        {
            continue;
        }

        /* set frame buffer address */
        gdi_layer_info[blt_layer->id].frame_buffer_address = (U32)gdi_bltdb_blt_layer[i].blt_buf_ptr;
    }
}

static void gdi_bltdb_restore_layer_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gdi_bltdb_is_started || (GDI_LCD->act_handle != GDI_LCD_MAIN_LCD_HANDLE))
    {
        return;
    } 
    for(i = 0; i < GDI_LAYER_HW_LAYER_COUNT ; i++ )
    {
        gdi_layer_struct* blt_layer = (gdi_layer_struct*)GDI_LCD->blt_handle[i];

        /* skip hw update layer and null handle */
        if ((GDI_LCD->blt_handle[i] == GDI_NULL_HANDLE) || 
            //(GDI_LCD->blt_handle[i] == gdi_layer_hw_update_layer_handle)
            GDI_LAYER_GET_FLAG((GDI_LCD->blt_handle[i]), GDI_LAYER_FLAG_HW_UPDATE))// hw update layer
        {
            continue;
        }
        
        gdi_layer_info[blt_layer->id].frame_buffer_address = (U32)blt_layer->buf_ptr;
    }
}

    
static void gdi_bltdb_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U8* temp_buf_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gdi_bltdb_is_started || (GDI_LCD->act_handle != GDI_LCD_MAIN_LCD_HANDLE))
    {
        return;
    }

    /* toggle double buffer */
    temp_buf_ptr = gdi_bltdb_blt_buf_ptr[0];
    gdi_bltdb_blt_buf_ptr[0] = gdi_bltdb_blt_buf_ptr[1];
    gdi_bltdb_blt_buf_ptr[1] = temp_buf_ptr;

    for(i = 0; i < GDI_LAYER_HW_LAYER_COUNT ; i++ )
    {
        gdi_layer_struct* blt_layer = (gdi_layer_struct*)GDI_LCD->blt_handle[i];
        
        /* skip hw update layer and null handle */
        if ((GDI_LCD->blt_handle[i] == GDI_NULL_HANDLE) || // hw update layer
            //(GDI_LCD->blt_handle[i] == gdi_layer_hw_update_layer_handle) ||
            GDI_LAYER_GET_FLAG((GDI_LCD->blt_handle[i]), GDI_LAYER_FLAG_HW_UPDATE) ||
            (blt_layer->bltdb_buf_ptr1 == NULL))
        {
            continue;
        }
        /* toggle double buffer */
        temp_buf_ptr = blt_layer->bltdb_buf_ptr1;
        blt_layer->bltdb_buf_ptr1 = blt_layer->bltdb_buf_ptr2;
        blt_layer->bltdb_buf_ptr2 = temp_buf_ptr;
    }
}


static kal_bool gdi_bltdb_check_blt_buf_size_enough(S32 total_blt_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    S32 total_layer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_layer_size = 0;
    for (i = 0 ; i < GDI_LAYER_HW_LAYER_COUNT ; i++)
    {
        S32 layer_size;
        gdi_layer_struct* blt_layer = (gdi_layer_struct*)GDI_LCD->blt_handle[i];

        /* skip hw update layer and null handle */
        if ((GDI_LCD->blt_handle[i] == GDI_NULL_HANDLE) ||                          // null handle
            //(GDI_LCD->blt_handle[i] == gdi_layer_hw_update_layer_handle) || // hw update layer
            GDI_LAYER_GET_FLAG((GDI_LCD->blt_handle[i]), GDI_LAYER_FLAG_HW_UPDATE) ||   // hw udpate layer
            ((blt_layer->bltdb_buf_ptr1 != NULL) && 
             (blt_layer->bltdb_buf_ptr2 != NULL))) // user already set bltdb blt buffer
        {
            continue;
        }
        
        layer_size = gdi_sizeof_pixels(blt_layer->cf, blt_layer->width, blt_layer->height);
        total_layer_size += layer_size;
    }

    if (total_layer_size > total_blt_buf_size)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

static void gdi_bltdb_start()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool blt_buf_enough = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    if (GDI_LCD->scanline_rotation == FALSE)
    {
        return;
    }
#endif
    
    /* set bltdb state */
    if (gdi_bltdb_is_started == KAL_TRUE)
    {
        return;
    }
    gdi_bltdb_is_started = KAL_TRUE;

    /* alloc buffer */
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    gdi_bltdb_blt_buf_ptr[0] = gdi_bltdb_inner_blt_buf;
    gdi_bltdb_blt_buf_ptr[1] = gdi_bltdb_inner_blt_buf + (GDI_BLTDB_BUF_SIZE >> 1);
#else
    gdi_bltdb_blt_buf_ptr[0] = (U8*)gdi_alloc_ext_mem_framebuffer(GDI_BLTDB_BUF_SIZE >> 1);
    gdi_bltdb_blt_buf_ptr[1] = (U8*)gdi_alloc_ext_mem_framebuffer(GDI_BLTDB_BUF_SIZE >> 1);
    ASSERT((gdi_bltdb_blt_buf_ptr[0] != NULL) && (gdi_bltdb_blt_buf_ptr[1] != NULL));
#endif

    /* check memory usage of currently OSD layers is enough */
    blt_buf_enough = gdi_bltdb_check_blt_buf_size_enough(GDI_BLTDB_BUF_SIZE >> 1);
    ASSERT(blt_buf_enough == KAL_TRUE);    /* total layer size should not larger than LCD size */

    /* update lcd frame buffer settings, set to gdi double buffer */
    gdi_bltdb_blt_with_double_buffer();

#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    gdi_scanline_force_rotate = KAL_TRUE;
#endif

#ifdef GDI_6_LAYERS
    gdi_layer_set_blt_layer_ext_internal(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    GDI_LCD->blt_handle[4],
                    GDI_LCD->blt_handle[5]);
#else
    gdi_layer_set_blt_layer_ext_internal(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    0,
                    0);
                #endif 

#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    gdi_scanline_force_rotate = KAL_FALSE;
#endif
}

static void gdi_bltdb_stop()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    if (GDI_LCD->scanline_rotation == FALSE)
    {
        return;
    }
#endif

    /* set bltdb state */
    if (gdi_bltdb_is_started == KAL_FALSE)
    {
        return;
    }
    gdi_bltdb_is_started = KAL_FALSE;

    /* free buffer */
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    gdi_bltdb_blt_buf_ptr[0] = NULL;
    gdi_bltdb_blt_buf_ptr[1] = NULL;
#else
    gdi_free_ext_mem((void**)&(gdi_bltdb_blt_buf_ptr[0]));
    gdi_free_ext_mem((void**)&(gdi_bltdb_blt_buf_ptr[1]));
#endif
}


void gdi_bltdb_hw_update_state_change(kal_bool start_hw_update)
{
    if (start_hw_update)
    {
        if ((gdi_bltdb_enable_status == GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE)
        #if defined(GDI_MAINLCD_SCANLINE_ROTATION)   /* if blt buffer enough, use mode2 automatically */
            || (gdi_bltdb_enable_status == GDI_BLTDB_ENABLE_END)
        #endif
            )
        {
            gdi_bltdb_start();
        }
    }
    else
    {
        /* stop hw update */
        if ((gdi_bltdb_enable_status == GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE)
        #if defined(GDI_MAINLCD_SCANLINE_ROTATION)   /* if blt buffer enough, use mode2 automatically */
            || (gdi_bltdb_enable_status == GDI_BLTDB_ENABLE_END)
        #endif
            )
        {
            gdi_bltdb_stop();
        }
    }
}


GDI_RESULT gdi_bltdb_enable(GDI_BLTDB_ENABLE_ENUM enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_hw_updating = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    ASSERT(enable != GDI_BLTDB_ENABLE_END);
    ASSERT((gdi_bltdb_enable_status == GDI_BLTDB_ENABLE_END) || (gdi_bltdb_enable_status == enable));
    /* if already enable, could only enable again with same parameter. */
    if (gdi_bltdb_enable_status == enable)
    {
        return GDI_SUCCEED;
    }

    gdi_bltdb_enable_status = enable;
    gdi_lcd_get_hw_update(&is_hw_updating);
    if ((enable == GDI_BLTDB_ENABLE_ALWAYS) ||
        ((enable == GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE) && (is_hw_updating)))
    {
        gdi_bltdb_start();
    }
    GDI_LCD_UNLOCK_MUTEX;
    return GDI_SUCCEED;
}


GDI_RESULT gdi_bltdb_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    
    gdi_bltdb_stop();
    
    gdi_bltdb_enable_status = GDI_BLTDB_ENABLE_END;
    
    GDI_LCD_UNLOCK_MUTEX;
    return GDI_SUCCEED;
}

GDI_RESULT gdi_bltdb_set_blt_buffer(
            gdi_handle layer_handle,
            U8* double_buf_ptr1,
            U32 double_buf_size1,
            U8* double_buf_ptr2,
            U32 double_buf_size2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct* layer = (gdi_layer_struct*)layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_bltdb_set_blt_buffer)

    ASSERT(layer_handle != 0);
    ASSERT(GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_USED));
    ASSERT((double_buf_ptr1 != NULL) && (double_buf_ptr2 != NULL));
    ASSERT((S32)double_buf_size1 >= layer->layer_size);
    ASSERT((S32)double_buf_size2 >= layer->layer_size);

    layer->bltdb_buf_ptr1 = double_buf_ptr1;
    layer->bltdb_buf_ptr2 = double_buf_ptr2;
    
    GDI_EXIT_CRITICAL_SECTION(gdi_bltdb_set_blt_buffer)
    return GDI_SUCCEED;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_toggle_lcd_source
 * DESCRIPTION
 *  toggle WFCSource of the context
 * PARAMETERS
 *  ctx_index    [IN]    the context that need to toggle WFCSource
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_toggle_lcd_source(gdi_lcd_v2_context_enum ctx_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WFCSource *tmp = gdi_lcd_v2_ctx_array[ctx_index].src_act;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_v2_ctx_array[ctx_index].src_act = gdi_lcd_v2_ctx_array[ctx_index].src_pre;
    gdi_lcd_v2_ctx_array[ctx_index].src_pre = tmp;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_internal_update_blt_rect
 * DESCRIPTION
 *  update GDI_LCD->blt_rect
 * PARAMETERS
 *  x1   [IN]   blt rect
 *  y1   [IN]   blt rect
 *  x2   [IN]   blt rect
 *  y2   [IN]   blt rect
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_layer_blt_internal_update_blt_rect(S32 x1, S32 y1, S32 x2, S32 y2)
{
    if (!GDI_LCD->blt_rect_is_used)
    {
        GDI_LCD->blt_rect.x1 = x1;
        GDI_LCD->blt_rect.y1 = y1;
        GDI_LCD->blt_rect.x2 = x2;
        GDI_LCD->blt_rect.y2 = y2;
        GDI_LCD->blt_rect_is_used = TRUE;
    }
    else
    {
        if (x1 < GDI_LCD->blt_rect.x1)
        {
            GDI_LCD->blt_rect.x1 = x1;
        }
        if (y1 < GDI_LCD->blt_rect.y1)
        {
            GDI_LCD->blt_rect.y1 = y1;
        }
        if (x2 > GDI_LCD->blt_rect.x2)
        {
            GDI_LCD->blt_rect.x2 = x2;
        }
        if (y2 > GDI_LCD->blt_rect.y2)
        {
            GDI_LCD->blt_rect.y2 = y2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_internal_merge_and_get_blt_rect
 * DESCRIPTION
 *  update GDI_LCD->blt_rect
 * PARAMETERS
 *  x1   [IN]   blt rect
 *  y1   [IN]   blt rect
 *  x2   [IN]   blt rect
 *  y2   [IN]   blt rect
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_layer_blt_internal_merge_and_get_blt_rect(S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    if (*x1 > GDI_LCD->blt_rect.x1)
    {
        *x1 = GDI_LCD->blt_rect.x1;
    }
    if (*y1 > GDI_LCD->blt_rect.y1)
    {
        *y1 = GDI_LCD->blt_rect.y1;
    }
    if (*x2 < GDI_LCD->blt_rect.x2)
    {
        *x2 = GDI_LCD->blt_rect.x2;
    }
    if (*y2 < GDI_LCD->blt_rect.y2)
    {
        *y2 = GDI_LCD->blt_rect.y2;
    }

    GDI_LCD->blt_rect_is_used = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_ext_internal
 * DESCRIPTION
 *  Blt means to update layers to LCD.
 *  The last four parameters are the region which to blt to LCD.
 *  handle0 is the most bottom layer, and handle5 is most top layer.
 *  NOTICE: Should not take gdi mutex or modify any global variable in this API.
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_layer_blt_ext_internal(
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
                    gdi_layer_blt_flag_bit_set flag,
                    const gdi_callback_struct *nb_finish_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result result = GDI_SUCCEED;
    gdi_color bg_color = 0;
    U8 lcd_actural_rotate_value = GDI_LCD_LAYER_ROTATE_0;
    kal_bool need_waiting_blt_finish = KAL_FALSE, is_hw_updating = KAL_FALSE;
    S32 lcd_width = 0, lcd_height = 0;
    gdi_lcd_v2_context_enum ctx_index = GDI_LCD_V2_CTX_BLT_MAIN_LCD;
    U32 start_time = 0;
    WFCCtxtRWAttrib *pContextAttrib = NULL;
    void (*blt_finish_callback)(void *param) = NULL;
    void *param = NULL;
    kal_bool non_blocking = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * NOTICE: Should not take gdi mutex or modify any global variable in this API.
     */
#if defined(GDI_4_LAYERS)
    if ((handle4 != GDI_NULL_HANDLE) ||
        (handle5 != GDI_NULL_HANDLE))
    {
        return GDI_LAYER_ERR_TOO_MANY_LAYER_INPUT;
    }
#endif

    if (nb_finish_callback != NULL)
    {
        blt_finish_callback = nb_finish_callback->callback_func;
        param = nb_finish_callback->user_data;
    }
    else
    {
        blt_finish_callback = NULL;
        param = NULL;
    }

    non_blocking = ((flag & GDI_LAYER_BLT_FLAG_NON_BLOCKING) ? KAL_TRUE : KAL_FALSE);

    kal_get_time(&start_time);
    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_BLT_ENTER, handle0, handle1, handle2, handle3, handle4, handle5,
        x1, y1, x2, y2, (kal_uint32)blt_finish_callback, start_time);
        
    do
    {
    #if defined(GDI_USING_LAYER_ROTATE) || defined(GDI_USING_LCD_ROTATE)
        gdi_rotate_map_lcd_to_absolute_hw_region(GDI_LCD->rotate_value, &x1, &y1, &x2, &y2);
    #endif 

        if (y2 < y1 || x2 < x1 || x1 >= GDI_LCD->act_width || x2 < 0 || y1 >= GDI_LCD->act_height || y2 < 0)
        {
            result = GDI_LAYER_ERR_INVALID_BLT_REGION;
            break;
        }

        /* store current blt layers, for gdi_layer_blt_previous uses */
        GDI_LCD->blt_handle[0] = handle0;
        GDI_LCD->blt_handle[1] = handle1;
        GDI_LCD->blt_handle[2] = handle2;
        GDI_LCD->blt_handle[3] = handle3;
    #ifdef GDI_6_LAYERS
        GDI_LCD->blt_handle[4] = handle4;
        GDI_LCD->blt_handle[5] = handle5;
    #endif /* GDI_6_LAYERS */ 

        /* if the layer is locked and someone call blt. merge the maxium blt region */
        if (!(flag & GDI_LAYER_BLT_FLAG_IGNORE_BLT_LOCK) && (GDI_LCD->blt_lock > 0))
        {
            gdi_layer_blt_internal_update_blt_rect(x1, y1, x2, y2);
            result = GDI_LAYER_DOUBLE_BUFFER_LOCKED;
            
            GDI_TRACE(GDI_TRC_LAYER_I, GDI_TRC_LAYER_BLT_BUFFER_LOCKED, x1, y1, x2, y2, GDI_LCD->blt_lock);
            
            break;
        }

        if (GDI_LCD->blt_rect_is_used)
        {
            /* merge and calculate maxium blt region */
            gdi_layer_blt_internal_merge_and_get_blt_rect(&x1, &y1, &x2, &y2);
        }
        
        /* adjust region to fit valid region */
        if (x1 < 0)
        {
            x1 = 0;
        }
        if (y1 < 0)
        {
            y1 = 0;
        }
        if (x2 > GDI_LCD->act_width - 1)
        {
            x2 = GDI_LCD->act_width - 1;
        }
        if (y2 > GDI_LCD->act_height - 1)
        {
            y2 = GDI_LCD->act_height - 1;
        }

        /* get lcd real rotate value */
    #if defined(GDI_USING_LCD_ROTATE)
        if (!GDI_LCD->rotate_by_layer)
        {
            lcd_actural_rotate_value = GDI_LCD->rotate_value;
        }
    #endif

        /* Set blt_running to TRUE here for the query during waiting for previous blt/flatten */
        gdi_layer_resource_hint.blt_running = KAL_TRUE;

        gdi_waiting_blt_finish(); // wait LCD driver finish blt if non block
        gdi_layer_set_blt_finish_callback(NULL, NULL);
#if !defined(GDI_GOVL_SUPPORT)
        gdi_layer_flatten_nb_wait_for_previous_finish();
#endif

        /* Non-blocking blt might reset the flag, we set it again */
        gdi_layer_resource_hint.blt_running = KAL_TRUE;
        
    #if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_bltdb_blt_with_double_buffer();
    #endif
        
    #if defined( __MMI_SUBLCD__)
        if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
        {
            ctx_index = GDI_LCD_V2_CTX_BLT_SUB_LCD;
        }
    #endif
    
        /* config element and get background color */
    #if defined(GDI_USING_LCD_ROTATE)
        if (!GDI_LCD->rotate_by_layer)
        {
            gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        }
        else
    #endif /* defined(GDI_USING_LCD_ROTATE) */ 
        {
            lcd_width = GDI_LCD->act_width;
            lcd_height = GDI_LCD->act_height;
        }

        GDI_ASSERT(ctx_index < GDI_LCD_V2_CTX_MAX);
        pContextAttrib = &gdi_wfc_context_attrib[ctx_index];

    #if defined(GDI_6_LAYERS)
        if (gdi_layer_config_element(ctx_index, 5, handle5, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_TRUE))
        {
            bg_color = ((gdi_layer_struct*)handle5)->background;
        }
        if (gdi_layer_config_element(ctx_index, 4, handle4, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_TRUE))
        {
            bg_color = ((gdi_layer_struct*)handle4)->background;
        }
    #endif
        if (gdi_layer_config_element(ctx_index, 3, handle3, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_TRUE))
        {
            bg_color = ((gdi_layer_struct*)handle3)->background;
        }
        if (gdi_layer_config_element(ctx_index, 2, handle2, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_TRUE))
        {
            bg_color = ((gdi_layer_struct*)handle2)->background;
        }
        if (gdi_layer_config_element(ctx_index, 1, handle1, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_TRUE))
        {
            bg_color = ((gdi_layer_struct*)handle1)->background;
        }
        if (gdi_layer_config_element(ctx_index, 0, handle0, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_TRUE))
        {
            bg_color = ((gdi_layer_struct*)handle0)->background;
        }

        /* add blt counter, UI engine can use it to know the previous setting ever blt or not */
        GDI_LCD->blt_counter++;

        /* if freezed, then no need to config context and blt */
        if (GDI_LCD->is_freeze || GDI_LCD->is_high_priority_freeze)
        {
            GDI_TRACE(GDI_TRC_LAYER_I, GDI_LAYER_BLT_FREEZED, GDI_LCD->is_freeze, GDI_LCD->is_high_priority_freeze);
        
            wfcSetContextAttribiv(
                gdi_lcd_v2_dev,
                gdi_lcd_v2_ctx_array[ctx_index].ctx_handle,
                WFC_CONTEXT_ALL_ATTRIBUTES_MTK,
                sizeof(WFCCtxtRWAttrib)/sizeof(WFCint),
                (WFCint*)pContextAttrib);
            wfcCommit(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[ctx_index].ctx_handle, WFC_TRUE);

            if (blt_finish_callback != NULL)
            {
                /* No callback if we didn't register callback for waiting_blt_finish() */
                result = GDI_SUCCEED_NO_CALLBACK;
            }

            gdi_layer_resource_hint.blt_running = KAL_FALSE;

            break;
        }

        /* BLOCK BLT */
        gdi_lcd_get_hw_update(&is_hw_updating);
        if (non_blocking || is_hw_updating)
        {
            /* non blocking blt */
            /* ddv2 auto mode is basically similar to non-blocking blt, so we have to register callback func to know blt done. */
            /* we call gdi_waiting_blt_finish after wfcCommit while hw updating to make this API still a blocking API for gdi user. */
            need_waiting_blt_finish = KAL_TRUE;
        }
        else
        {
            need_waiting_blt_finish = KAL_FALSE;
        }

        #if defined(GDI_LCD_SCANLINE_ROTATION)
        /* Map the blt area to the right region */
        {
            gdi_scanline_map_rotate_region(&x1, &y1, &x2, &y2);
        }
        #endif /* GDI_LCD_SCANLINE_ROTATION */

        if (need_waiting_blt_finish)
        {
            gdi_layer_set_blt_finish_callback(blt_finish_callback, param);
            gdi_is_blting = TRUE;
        }

        /* config context */
        gdi_layer_config_context(
            gdi_lcd_v2_ctx_array[ctx_index].ctx_handle,
            pContextAttrib,
            bg_color, 
            lcd_actural_rotate_value,
            (need_waiting_blt_finish ? gdi_layer_blt_finish_handler : NULL),
            x1,
            y1,
            x2,
            y2);

        kal_get_time(&start_time);
        GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_BLT_START, non_blocking, is_hw_updating, start_time);

    #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
    #endif
     
        wfcCommit(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[ctx_index].ctx_handle, WFC_TRUE);
        
        /* when hw updating, the wfcCommit will return after the previous blt buffer already blt to lcd.
           So we can toggle and draw the previous blt buffer after wfcCommit returned. */
        
        if (is_hw_updating)
        {
            /* if is hw updating, toggle the WFCSource for double buffer */
            gdi_layer_toggle_lcd_source(ctx_index);

            if (!non_blocking) /* Blocking blt */
            {
                /* if hw updating, wait until the blt finishing, to make this API a blocking API for gdi user. */
                /* Otherwise, when gdi user using single buffer OSD layer they may modify the layer buf right after blt return, then the buf may be wrong while blting. */
                gdi_waiting_blt_finish();
            }

            /* no need to call compose when hw updating */
        }
        else
        {
            kal_bool wait_for_composition = (non_blocking ? KAL_FALSE : KAL_TRUE);
            /* if not hw updateing, call wfcCompose to blt lcd. */
            wfcCompose(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[ctx_index].ctx_handle, (WFCboolean)(wait_for_composition));
        }

        if (!need_waiting_blt_finish && blt_finish_callback != NULL)
        {
            /* No callback if we didn't register callback for waiting_blt_finish() */
            result = GDI_SUCCEED_NO_CALLBACK;
        }

        /* finish */
    #if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
        gdi_bltdb_toggle();
        gdi_bltdb_restore_layer_setting();
    #endif

        if (!non_blocking)
        {
            gdi_layer_resource_hint.blt_running = KAL_FALSE;
        }
    
    #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
    #endif
    } while(0);

    kal_get_time(&start_time);
    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_BLT_LEAVE, result, start_time);
    
	
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_ext
 * DESCRIPTION
 *  Blt layers.
 *  
 *  The last four parameters are the region which to blt to LCD.
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_blt_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3,
            gdi_handle handle4, 
            gdi_handle handle5,
            S32 x1, 
            S32 y1, 
            S32 x2, 
            S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    gdi_layer_blt_flag_bit_set flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRC_PRINT_LR(GDI_TRC_LAYER);
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_blt)
    GDI_LCD_LOCK_MUTEX;

#if defined(GDI_USE_RGB565_TO_SHOW_BW)
	if (GDI_NULL_HANDLE != handle1 || GDI_NULL_HANDLE != handle2 || GDI_NULL_HANDLE != handle3)
		GDI_ASSERT(0);
    gdi_layer_push_and_set_active(g_gdi_copy_handle);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();
	gdi_layer_copy_1_to_16(handle0, g_gdi_copy_handle);
	handle0 = g_gdi_copy_handle;
#endif /* GDI_USE_RGB565_TO_SHOW_BW */

    flag = 0;
    if (gdi_is_non_block_blt)
    {
        flag |= GDI_LAYER_BLT_FLAG_NON_BLOCKING;
    }
	
#if defined(GDI_LCD_SCANLINE_ROTATION)
    /* For common UI screen, flatten and rotate the layer */
    if (gdi_scanline_intercept_blt(GDI_LCD, flag))
    {
        ret = gdi_scanline_layer_blt(
                  handle0, 
                  handle1, 
                  handle2, 
                  handle3,
                  handle4, 
                  handle5,
                  x1, 
                  y1, 
                  x2, 
                  y2,
                  flag,
                  NULL);
    }
    else
#endif /* GDI_LCD_SCANLINE_ROTATION */
    {
        ret = gdi_layer_blt_ext_internal(
                handle0, 
                handle1, 
                handle2, 
                handle3,
                handle4, 
                handle5,
                x1, 
                y1, 
                x2, 
                y2,
                flag,
                NULL);
    }
    GDI_LCD_UNLOCK_MUTEX;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_blt)

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_nb_concurrent_ext
 * DESCRIPTION
 *  Blt layers.
 *  
 *  The last four parameters are the region which to blt to LCD.
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_blt_nb_concurrent_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3,
            gdi_handle handle4, 
            gdi_handle handle5,
            S32 x1, 
            S32 y1, 
            S32 x2, 
            S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    gdi_layer_blt_flag_bit_set flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRC_PRINT_LR(GDI_TRC_LAYER);
    
    GDI_LCD_LOCK_MUTEX;

    flag = 0;
    if (gdi_is_non_block_blt)
    {
        flag |= GDI_LAYER_BLT_FLAG_NON_BLOCKING;
    }

#if defined(GDI_LCD_SCANLINE_ROTATION)
    /* For common UI screen, flatten and rotate the layer */
    if (gdi_scanline_intercept_blt(GDI_LCD, flag))
    {
        ret = gdi_scanline_layer_blt(
                handle0, 
                handle1, 
                handle2, 
                handle3,
                handle4, 
                handle5,
                x1, 
                y1, 
                x2, 
                y2,
                flag,
                NULL);
    }
    else
#endif /* GDI_LCD_SCANLINE_ROTATION */
    {
        ret = gdi_layer_blt_ext_internal(
                handle0, 
                handle1, 
                handle2, 
                handle3,
                handle4, 
                handle5,
                x1, 
                y1, 
                x2, 
                y2,
                flag,
                NULL);
    }
    GDI_LCD_UNLOCK_MUTEX;

    return ret;
}


GDI_RESULT gdi_layer_blt_with_flag(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3,
            kal_int32 x1, 
            kal_int32 y1, 
            kal_int32 x2, 
            kal_int32 y2,
            gdi_layer_blt_flag_bit_set flag,
            const gdi_callback_struct *nb_finish_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    kal_uint32 lr = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_LAYER, GDI_TRC_LAYER_BLT_WITH_FLAG, flag, lr);

    /* 
     * nb_finish_callback is only reserved for future use.
     * We don't support non-blocking finish callback on this version.
     */
    GDI_ASSERT(nb_finish_callback == NULL);

    if (!(flag & GDI_LAYER_BLT_FLAG_NO_GDI_LOCK))
    {
        GDI_LOCK;
    }
    
    GDI_LCD_LOCK_MUTEX;

#if defined(GDI_LCD_SCANLINE_ROTATION)
    /* For common UI screen, flatten and rotate the layer */
    if (gdi_scanline_intercept_blt(GDI_LCD, flag))
    {
        ret = gdi_scanline_layer_blt(
                  handle0, 
                  handle1, 
                  handle2, 
                  handle3,
                  0, 
                  0,
                  x1, 
                  y1, 
                  x2, 
                  y2,
                  flag,
                  NULL);
    }
    else
#endif /* GDI_LCD_SCANLINE_ROTATION */
    {
        ret = gdi_layer_blt_ext_internal(
                handle0, 
                handle1, 
                handle2, 
                handle3,
                0, 
                0,
                x1, 
                y1, 
                x2, 
                y2,
                flag,
                nb_finish_callback);
    }
    
    GDI_LCD_UNLOCK_MUTEX;

    if (!(flag & GDI_LAYER_BLT_FLAG_NO_GDI_LOCK))
    {
        GDI_UNLOCK;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_blt_layer_ext_internal
 * DESCRIPTION
 *  Set layer to GDI and config driver's setting
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_layer_set_blt_layer_ext_internal(
                    gdi_handle handle0, 
                    gdi_handle handle1, 
                    gdi_handle handle2, 
                    gdi_handle handle3, 
                    gdi_handle handle4, 
                    gdi_handle handle5)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lcd_width = 0, lcd_height = 0;
    gdi_lcd_v2_context_enum ctx_index = GDI_LCD_V2_CTX_BLT_MAIN_LCD;
    kal_bool is_hw_updating = KAL_FALSE;
    WFCCtxtRWAttrib *pContextAttrib = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_4_LAYERS)
    if ((handle4 != GDI_NULL_HANDLE) ||
        (handle5 != GDI_NULL_HANDLE))
    {
        return GDI_LAYER_ERR_TOO_MANY_LAYER_INPUT;
    }
#endif

    GDI_TRACE(GDI_TRC_LAYER, GDI_LAYER_SET_BLT_LAYER,//[gdi_layer_set_blt_layer_ext_internal]: H0:%x H1:%x H2:%x H3:%x H4:%x H5:%x
        handle0, handle1, handle2, handle3, handle4, handle5);
    /* store current blt layers, for gdi_layer_blt_previous uses */
    GDI_LCD->blt_handle[0] = handle0;
    GDI_LCD->blt_handle[1] = handle1;
    GDI_LCD->blt_handle[2] = handle2;
    GDI_LCD->blt_handle[3] = handle3;
#ifdef GDI_6_LAYERS
    GDI_LCD->blt_handle[4] = handle4;
    GDI_LCD->blt_handle[5] = handle5;
#endif /* GDI_6_LAYERS */

#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_bltdb_set_blt_layer_frame_buffer_address();
#endif

#if defined( __MMI_SUBLCD__)
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        ctx_index = GDI_LCD_V2_CTX_BLT_SUB_LCD;
    }
#endif
    
    /* get lcd real rotate value */
#if defined(GDI_USING_LCD_ROTATE)
    if (!GDI_LCD->rotate_by_layer)
    {
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    }
    else
#endif /* defined(GDI_USING_LCD_ROTATE) */ 
    {
        lcd_width = GDI_LCD->act_width;
        lcd_height = GDI_LCD->act_height;
    }
    
    /* wait LCD driver finish blt if non block */
    /* gdi_layer_config_element will destroy wfcsource, so we have to wait the last blt finishing before calling it. */
    /* Otherwise, the wfcsource that wfc is blting might be destroy. */
    gdi_waiting_blt_finish();   
    
    /* config element and get background color */
#if defined(GDI_6_LAYERS)
    gdi_layer_config_element(ctx_index, 5, handle5, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_FALSE);
    gdi_layer_config_element(ctx_index, 4, handle4, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_FALSE);
#endif
    gdi_layer_config_element(ctx_index, 3, handle3, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_FALSE);
    gdi_layer_config_element(ctx_index, 2, handle2, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_FALSE);
    gdi_layer_config_element(ctx_index, 1, handle1, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_FALSE);
    gdi_layer_config_element(ctx_index, 0, handle0, GDI_LCD->rotate_value, (kal_bool)GDI_LCD->rotate_by_layer, lcd_width, lcd_height, 0, 0, KAL_FALSE);

    GDI_ASSERT(ctx_index < GDI_LCD_V2_CTX_MAX);
    pContextAttrib = &gdi_wfc_context_attrib[ctx_index];

    wfcSetContextAttribiv(
        gdi_lcd_v2_dev,
        gdi_lcd_v2_ctx_array[ctx_index].ctx_handle,
        WFC_CONTEXT_ALL_ATTRIBUTES_MTK,
        sizeof(WFCCtxtRWAttrib)/sizeof(WFCint),
        (WFCint*)pContextAttrib);
    wfcCommit(gdi_lcd_v2_dev, gdi_lcd_v2_ctx_array[ctx_index].ctx_handle, WFC_TRUE);

    gdi_lcd_get_hw_update(&is_hw_updating);
    if (is_hw_updating)
    {
        /* if is hw updating, toggle the WFCSource for double buffer */
        gdi_layer_toggle_lcd_source(ctx_index);
    }
#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    gdi_bltdb_restore_layer_setting();
#endif

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_blt_layer_previous
 * DESCRIPTION
 *  config the settings of previous blt layers to LCD driver.
 * PARAMETERS
 *  
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_set_blt_layer_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRC_PRINT_LR(GDI_TRC_LAYER);
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_blt_layer_previous)
    GDI_LCD_LOCK_MUTEX;
    
    if (GDI_LCD->blt_handle[0] || 
        GDI_LCD->blt_handle[1]
#if defined(GDI_6_LAYERS) || defined(GDI_4_LAYERS)    
        || GDI_LCD->blt_handle[2] 
        || GDI_LCD->blt_handle[3]
#endif
#ifdef GDI_6_LAYERS
        || GDI_LCD->blt_handle[4] 
        || GDI_LCD->blt_handle[5]
#endif 
        )
    {
    #ifdef GDI_6_LAYERS
        result = gdi_layer_set_blt_layer_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    GDI_LCD->blt_handle[4],
                    GDI_LCD->blt_handle[5]);
    #else
        result = gdi_layer_set_blt_layer_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    0,
                    0);
                #endif 
    }
    else
    {
        result = gdi_layer_set_blt_layer_ext(GDI_LCD->act_layer_handle, 0, 0, 0, 0, 0);
    }

    GDI_LCD_UNLOCK_MUTEX;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_blt_layer_previous)
    return result;
}
 
/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_blt_layer_ext
 * DESCRIPTION
 *  Set layer to GDI and config driver's setting
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_set_blt_layer_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRC_PRINT_LR(GDI_TRC_LAYER);
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_blt_layer)
    GDI_LCD_LOCK_MUTEX;
    
#if defined(GDI_LCD_SCANLINE_ROTATION) && defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    /* For common UI screen, flatten and rotate the layer */
    if ((GDI_LCD->scanline_rotation == TRUE) &&
        ((GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE) &&
         (gdi_bltdb_is_started == KAL_TRUE)))
    {
        ret = gdi_scanline_set_blt_layer(
                  handle0, 
                  handle1, 
                  handle2, 
                  handle3,
                  handle4, 
                  handle5);
    }
    else
#endif /* GDI_LCD_SCANLINE_ROTATION */
    {
        ret = gdi_layer_set_blt_layer_ext_internal(
                handle0,
                handle1,
                handle2,
                handle3,
                handle4,
                handle5);
    }
    GDI_LCD_UNLOCK_MUTEX;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_blt_layer)

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_blt_layer_nb_concurrent_ext
 * DESCRIPTION
 *  Set layer to GDI and config driver's setting
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_set_blt_layer_nb_concurrent_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRC_PRINT_LR(GDI_TRC_LAYER);
    
    GDI_LCD_LOCK_MUTEX;

#if defined(GDI_LCD_SCANLINE_ROTATION) && defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)
    /* For common UI screen, flatten and rotate the layer */
    if ((GDI_LCD->scanline_rotation == TRUE) &&
        ((GDI_LCD->act_handle == GDI_LCD_MAIN_LCD_HANDLE) &&
         (gdi_bltdb_is_started == KAL_TRUE)))
    {
        ret = gdi_scanline_set_blt_layer(
                  handle0, 
                  handle1, 
                  handle2, 
                  handle3,
                  handle4, 
                  handle5);
    }
    else
#endif /* GDI_LCD_SCANLINE_ROTATION */
    {
        ret = gdi_layer_set_blt_layer_ext_internal(
                  handle0,
                  handle1,
                  handle2,
                  handle3,
                  handle4,
                  handle5);
    }
    GDI_LCD_UNLOCK_MUTEX;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_blt_layer_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [?]     
 *  handle1     [?]     
 *  handle2     [?]     
 *  handle3     [?]     
 *  handle4     [?]     
 *  handle5     [?]     
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_get_blt_layer_ext(
            gdi_handle *handle0, 
            gdi_handle *handle1, 
            gdi_handle *handle2,
            gdi_handle *handle3, 
            gdi_handle *handle4, 
            gdi_handle *handle5)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_blt_layer)
    GDI_LCD_LOCK_MUTEX;
    
    if(handle0) *handle0 = GDI_LCD->blt_handle[0];
    if(handle1) *handle1 = GDI_LCD->blt_handle[1];
#if defined(GDI_6_LAYERS) || defined(GDI_4_LAYERS)
    if(handle2) *handle2 = GDI_LCD->blt_handle[2];
    if(handle3) *handle3 = GDI_LCD->blt_handle[3];
#endif
#ifdef GDI_6_LAYERS
    if(handle4) *handle4 = GDI_LCD->blt_handle[4];
    if(handle5) *handle5 = GDI_LCD->blt_handle[5];
#else
    if(handle4) *handle4 = 0;
    if(handle5) *handle5 = 0;
#endif

    GDI_LCD_UNLOCK_MUTEX;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_blt_layer)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_blt_layer_number
 * DESCRIPTION
 *  get how many layers that hw can blt or flatten at one time.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gdi_layer_get_blt_layer_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_6_LAYERS)
    return 6;
#elif defined(GDI_4_LAYERS)
    return 4;
#elif defined(GDI_2_LAYERS)
    return 2;
#else
    return DRV_LAYER_TOTAL_COUNT;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_base_layer
 * DESCRIPTION
 *  Blt base layer
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_blt_base_layer(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_blt_base_layer)

#ifdef __MMI_SUBLCD__
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        ret = gdi_layer_blt(GDI_LAYER_SUB_BASE_LAYER_HANDLE, 0, 0, 0, x1, y1, x2, y2);
    }
    else
#endif /* __MMI_SUBLCD__ */ 
        ret = gdi_layer_blt(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0, x1, y1, x2, y2);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_blt_base_layer)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_previous
 * DESCRIPTION
 *  Blt previous blt layers.
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_blt_previous(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    kal_uint32 lr = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_LAYER, GDI_TRC_LAYER_BLT_PREVIOUS, x1, y1, x2, y2, lr);
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_blt_previous)
    GDI_LCD_LOCK_MUTEX;

    if (GDI_LCD->blt_handle[0] || GDI_LCD->blt_handle[1]
#if defined(GDI_6_LAYERS) || defined(GDI_4_LAYERS)    
        || GDI_LCD->blt_handle[2] || GDI_LCD->blt_handle[3]
#endif
#ifdef GDI_6_LAYERS
        || GDI_LCD->blt_handle[4] || GDI_LCD->blt_handle[5]
#endif 
        )
    {
    #ifdef GDI_6_LAYERS
        result = gdi_layer_blt_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    GDI_LCD->blt_handle[4], 
                    GDI_LCD->blt_handle[5],
                    x1, 
                    y1, 
                    x2, 
                    y2);
    #else
        result = gdi_layer_blt_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    0, 
                    0,
                    x1, 
                    y1, 
                    x2, 
                    y2);
    #endif 
    }
    else
    {
        result = gdi_layer_blt_ext(GDI_LCD->act_layer_handle, 0, 0, 0, 0, 0, x1, y1, x2, y2);
    }

    GDI_LCD_UNLOCK_MUTEX;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_blt_previous)
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_previous_nb_concurrent
 * DESCRIPTION
 *  Blt previous blt layers.
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_blt_previous_nb_concurrent(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;

    if (GDI_LCD->blt_handle[0] || GDI_LCD->blt_handle[1]
#if defined(GDI_6_LAYERS) || defined(GDI_4_LAYERS)    
        || GDI_LCD->blt_handle[2] || GDI_LCD->blt_handle[3]
#endif
#ifdef GDI_6_LAYERS
        || GDI_LCD->blt_handle[4] || GDI_LCD->blt_handle[5]
#endif 
        )
    {
    #ifdef GDI_6_LAYERS
        result = gdi_layer_blt_nb_concurrent_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    GDI_LCD->blt_handle[4], 
                    GDI_LCD->blt_handle[5],
                    x1, 
                    y1, 
                    x2, 
                    y2);
    #else
        result = gdi_layer_blt_nb_concurrent_ext(
                    GDI_LCD->blt_handle[0],
                    GDI_LCD->blt_handle[1], 
                    GDI_LCD->blt_handle[2], 
                    GDI_LCD->blt_handle[3],
                    0, 
                    0,
                    x1, 
                    y1, 
                    x2, 
                    y2);
    #endif 
    }
    else
    {
        result = gdi_layer_blt_nb_concurrent_ext(GDI_LCD->act_layer_handle, 0, 0, 0, 0, 0, x1, y1, x2, y2);
    }
    GDI_LCD_UNLOCK_MUTEX;
    return result;
    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_multi_layer_enable
 * DESCRIPTION
 *  Enable multi-layer functions
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_multi_layer_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_multi_layer_enable)

#if defined(GDI_USING_LAYER)
    gdi_is_layer_enable = TRUE;
#else 
    GDI_ASSERT(0);  /* 6205B and 6218 should not call multi-layer function */
#endif 

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_multi_layer_enable)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_multi_layer_disable
 * DESCRIPTION
 *  Disable multi-layer functions
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_multi_layer_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_multi_layer_disable)
#if defined(GDI_USING_LAYER)
    gdi_handle lcd_handle;

    gdi_lcd_get_active(&lcd_handle);

    if (lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
    }
#ifdef __MMI_SUBLCD__
    else if (lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        gdi_layer_set_blt_layer(GDI_LAYER_SUB_BASE_LAYER_HANDLE, 0, 0, 0);
    }
#endif /* __MMI_SUBLCD__ */ 
    else
    {
        GDI_ASSERT(0);
        GDI_RETURN(GDI_FAILED);
    }

    gdi_is_layer_enable = FALSE;
#else /* defined(GDI_USING_LAYER) */ 
    GDI_ASSERT(0);  /* 6205B and 6218 should not call multi-layer function */
#endif /* defined(GDI_USING_LAYER) */ 
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_multi_layer_disable)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_is_multi_layer_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_layer_is_multi_layer_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_is_multi_layer_enable)
    ret = gdi_is_layer_enable;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_is_multi_layer_enable)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_base_handle
 * DESCRIPTION
 *  Get handle of base layer.
 * PARAMETERS
 *  handle_ptr      [?]     
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
GDI_RESULT gdi_layer_get_base_handle(gdi_handle *handle_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_base_handle)

#ifdef __MMI_SUBLCD__
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        *handle_ptr = GDI_LAYER_SUB_BASE_LAYER_HANDLE;
    }
    else
#endif /* __MMI_SUBLCD__ */ 
        *handle_ptr = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_base_handle)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_restore_base_active
 * DESCRIPTION
 *  Restore base layer as active layer
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_layer_restore_base_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_restore_base_active)
#ifdef __MMI_SUBLCD__
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        gdi_layer_set_active(GDI_LAYER_SUB_BASE_LAYER_HANDLE);
    }
    /* gdi_act_layer = (gdi_layer_struct*) GDI_LAYER_SUB_BASE_LAYER_HANDLE; */
    else
#endif /* __MMI_SUBLCD__ */ 
        gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_restore_base_active)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_clear
 * DESCRIPTION
 *  draw currently active layer's color
 * PARAMETERS
 *  bg_color        [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_clear(gdi_color bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_clear)

    
    /* UYVY422 is not supported currently, it's workaround */
    if (gdi_act_layer->cf == GDI_COLOR_FORMAT_UYVY422)
    {
        gdi_memset16((U8*) gdi_act_layer->buf_ptr, 0x0080, gdi_act_layer->layer_size);
        GDI_RETURN(GDI_SUCCEED);
    }

    if (GDI_LAYER.bits_per_pixel == 16)
    {
        gdi_memset16((U8*) gdi_act_layer->buf_ptr, (U16) bg_color, gdi_act_layer->layer_size);
    }
#ifdef GDI_PRIMITIVE_24_BIT_SUPPORT
    else if (GDI_LAYER.bits_per_pixel == 24)
    {
        gdi_memset24((U8*) gdi_act_layer->buf_ptr, (U32) bg_color, gdi_act_layer->width * gdi_act_layer->height * 3);
    }
#endif
    else if (GDI_LAYER.bits_per_pixel == 32)
    {
        gdi_memset32((U8*) gdi_act_layer->buf_ptr, (U32) bg_color, gdi_act_layer->layer_size);
    }
    else
    {
        gdi_layer_push_clip();
        gdi_layer_reset_clip();
        gdi_draw_solid_rect(0, 0, gdi_act_layer->width - 1, gdi_act_layer->height - 1, bg_color);
        gdi_layer_pop_clip();
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_clear)
    return GDI_SUCCEED;
}

/**************************************************************

   FUNCTION NAME     : gdi_layer_rotate()

   PURPOSE           : rotate the layer content

   INPUT PARAMETERS  :
                  GDI_LAYER_ROTATE_0         
                  GDI_LAYER_ROTATE_90        
                  GDI_LAYER_ROTATE_180       
                  GDI_LAYER_ROTATE_270    
                  GDI_LAYER_ROTATE_0_MIRROR  
                  GDI_LAYER_ROTATE_90_MIRROR 
                  GDI_LAYER_ROTATE_180_MIRROR
                  GDI_LAYER_ROTATE_270_MIRROR

   OUTPUT PARAMETERS : nil

   RETURNS           : void
***************************************************************/
/*
 * void gdi_layer_rotate(U8 rotate)
 * {
 * GDI_ENTER_CRITICAL_SECTION(gdi_layer_rotate)
 * switch(rotate)
 * {
 * case GDI_LAYER_ROTATE_0: //nothing to do
 * break;
 * case GDI_LAYER_ROTATE_90:
 * }
 * GDI_EXIT_CRITICAL_SECTION(gdi_layer_rotate)
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_buffer_ptr
 * DESCRIPTION
 *  get currently active layer's frame buffer pointer.
 * PARAMETERS
 *  buf_ptr     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_get_buffer_ptr(U8 **buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_buffer_ptr)
    *buf_ptr = gdi_act_layer->buf_ptr;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_buffer_ptr)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_dimension
 * DESCRIPTION
 *  get currently active layer's size.
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_get_dimension(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_dimension)
    *width = gdi_act_layer->width;
    *height = gdi_act_layer->height;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_dimension)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_position
 * DESCRIPTION
 *  get currently active layer's position.
 * PARAMETERS
 *  offset_x        [OUT]       
 *  offset_y        [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_get_position(S32 *offset_x, S32 *offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_position)
    ret = gdi_layer_get_position_nb_concurrent((gdi_handle)gdi_act_layer, offset_x, offset_y);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_position)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_debug_flatten
 * DESCRIPTION
 *  use when ASSERT or Fatal Error happen to flatten all layers to base layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_layer_debug_flatten(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 layer_count = 0;
    lcd_exception_layer_struct exception_layers[GDI_LAYER_HW_LAYER_COUNT];
    S32 x1, y1, x2, y2;
    gdi_handle layer_handle;
    gdi_handle base_handle;
    gdi_layer_struct *layer_struct;
    gdi_lcd_layer_struct *layer_info;
    U8 output_rotate_value;
    gdi_color background = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_debug_flatten)
    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_push_and_set_active(base_handle);

    output_rotate_value = GDI_LCD->rotate_value;
    for (i = 0; i < GDI_LAYER_HW_LAYER_COUNT; i++)
    {
        layer_handle = GDI_LCD->blt_handle[i];
        if (layer_handle == GDI_NULL_HANDLE)
        {
            continue;
        }
        GDI_ASSERT(layer_handle >= GDI_LAYER_VALID_HANDLE_START);
        if (!GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_USED))
        {
            continue;
        }
        if (GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_HW_UPDATE))
        {
            continue;
        }

        layer_struct = (gdi_layer_struct*)layer_handle;
        layer_info = &gdi_layer_info[layer_struct->id];
        /* set rotate_value of layer_info */
        x1 = layer_struct->offset_x;
        y1 = layer_struct->offset_y;
        x2 = layer_struct->offset_x + layer_struct->width - 1;
        y2 = layer_struct->offset_y + layer_struct->height - 1;
    #if defined(GDI_USING_LAYER_ROTATE) || defined(GDI_USING_LCD_ROTATE)
        layer_info->rotate_value = (U8) ((((GDI_LCD_LAYER_ROTATE_MIRROR_MASK & output_rotate_value) |
                                         (0x04 - (GDI_LCD_LAYER_ROTATE_ANGLE_MASK & output_rotate_value))) +
                                          layer_struct->rotate_value) & GDI_LCD_LAYER_ROTATE_ALL_MASK);
    #endif
        /* set x_offset, y_offset of layer_info */
        gdi_rotate_map_region_internal(layer_info->rotate_value,  &x1, &y1, &x2, &y2, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
        layer_info->x_offset = x1;
        layer_info->y_offset = y1;

        /* Rotate value is number, if rotate is 90, just fill 90 */
        exception_layers[layer_count].rotate_angle = (layer_info->rotate_value - GDI_LAYER_ROTATE_0) * 90;

        /* set dst rect */
        exception_layers[layer_count].dst_rect[0] = layer_info->x_offset;
        exception_layers[layer_count].dst_rect[1] = layer_info->y_offset;
        exception_layers[layer_count].dst_rect[2] = layer_struct->width;
        exception_layers[layer_count].dst_rect[3] = layer_struct->height;

        /* set dst rect */
        exception_layers[layer_count].src_rect[0] = 0;
        exception_layers[layer_count].src_rect[1] = 0;
        exception_layers[layer_count].src_rect[2] = layer_struct->width;
        exception_layers[layer_count].src_rect[3] = layer_struct->height;

        switch(layer_struct->cf)
        {
            case GDI_COLOR_FORMAT_8:
                exception_layers[layer_count].color_format = LCD_EXPT_LAYER_FORMAT_8BPP_INDEX;
                break;
            case GDI_COLOR_FORMAT_16:
                exception_layers[layer_count].color_format = LCD_EXPT_LAYER_FORMAT_RGB565;
                break;
            case GDI_COLOR_FORMAT_24:
                exception_layers[layer_count].color_format = LCD_EXPT_LAYER_FORMAT_RGB888;
                break;
            case GDI_COLOR_FORMAT_32:
                exception_layers[layer_count].color_format = LCD_EXPT_LAYER_FORMAT_ARGB8888;
                break;
            case GDI_COLOR_FORMAT_32_PARGB:
                exception_layers[layer_count].color_format = LCD_EXPT_LAYER_FORMAT_PARGB8888;
                break;
            case GDI_COLOR_FORMAT_PARGB6666:
                exception_layers[layer_count].color_format = LCD_EXPT_LAYER_FORMAT_PARGB6666;
                break;
            case GDI_COLOR_FORMAT_UYVY422:
                exception_layers[layer_count].color_format = LCD_EXPT_LAYER_FORMAT_UYVY422;
                break;
            default:
                GDI_ASSERT(0);
        }

        exception_layers[layer_count].mem_pitch = ((layer_struct->width * layer_struct->bits_per_pixel) >> 3);
        exception_layers[layer_count].src_key_en = layer_info->source_key_enable;
        exception_layers[layer_count].dst_key_en = KAL_FALSE;
        exception_layers[layer_count].color_key = layer_info->source_key;
        exception_layers[layer_count].alpha_blend_en = layer_info->opacity_enable;
        exception_layers[layer_count].alpha = layer_info->opacity_value;
        exception_layers[layer_count].flip_en = KAL_FALSE;
        exception_layers[layer_count].swap_en = KAL_FALSE;
        exception_layers[layer_count].dither_en = layer_info->dither_enable;
        exception_layers[layer_count].frame_buffer = layer_info->frame_buffer_address;        

        background = layer_struct->background;

        layer_count++;
    }
    lcd_exception_flatten(
        layer_count,
        exception_layers,
        ((gdi_layer_struct*) base_handle)->buf_ptr,
        background,
        GDI_LCD_WIDTH,
        GDI_LCD_HEIGHT);

    gdi_layer_pop_and_restore_active();
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_debug_flatten)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_debug_blt
 * DESCRIPTION
 *  use when ASSERT or Fatal Error happen to print debug info.
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_layer_debug_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_debug_blt)

    lcd_exception_screen_update(
        ((gdi_layer_struct*) GDI_LAYER_MAIN_BASE_LAYER_HANDLE)->buf_ptr,
        GDI_LCD_WIDTH,
        GDI_LCD_HEIGHT);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_debug_blt)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_flatten_to_base_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_flatten_to_base_ext(
            gdi_handle handle0, 
            gdi_handle handle1, 
            gdi_handle handle2, 
            gdi_handle handle3, 
            gdi_handle handle4, 
            gdi_handle handle5)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    gdi_handle base_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_flatten_to_base)

    gdi_layer_get_base_handle(&base_handle);

    gdi_layer_push_and_set_active(base_handle);
    ret = gdi_layer_flatten_ext(handle0, handle1, handle2, handle3, handle4, handle5);
    gdi_layer_pop_and_restore_active();
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_flatten_to_base)
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_bit_per_pixel
 * DESCRIPTION
 *  get the active layer pixel size (in bits)
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
int gdi_layer_get_bit_per_pixel(void)
{
    return GDI_LAYER.bits_per_pixel;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_flatten_previous_to_base
 * DESCRIPTION
 *  flatten previous blt layers to base layer
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_flatten_previous_to_base(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_flatten_previous_to_base)

#if defined(GDI_USING_LAYER)
#ifdef GDI_6_LAYERS
    result = gdi_layer_flatten_to_base_ext(
                GDI_LCD->blt_handle[0], 
                GDI_LCD->blt_handle[1], 
                GDI_LCD->blt_handle[2],
                GDI_LCD->blt_handle[3], 
                GDI_LCD->blt_handle[4], 
                GDI_LCD->blt_handle[5]);
#else
    result = gdi_layer_flatten_to_base_ext(GDI_LCD->blt_handle[0], GDI_LCD->blt_handle[1], GDI_LCD->blt_handle[2], GDI_LCD->blt_handle[3], 0, 0);
#endif 
#else /* defined(GDI_USING_LAYER) */ 
    result = GDI_SUCCEED;
#endif /* defined(GDI_USING_LAYER) */ 
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_flatten_previous_to_base)
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_save_pbm_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer_handle        [IN]        
 *  file_name           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_save_pbm_file(gdi_handle layer_handle, CHAR *file_name)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    return GDI_FAILED;
}

GDI_RESULT gdi_layer_save_bmp_file(gdi_handle layer_handle, CHAR *file_name)
{
    S32 image_width, image_height;
    PU8 image_ptr;
    gdi_color_format image_cf;
    gdi_result ret;

    GDI_ENTER_CRITICAL_SECTION(gdi_layer_save_bmp_file)

    if (layer_handle == GDI_NULL_HANDLE)
    {
        GDI_RETURN(GDI_FAILED);
    }

    image_width = ((gdi_layer_struct*) layer_handle)->width;
    image_height = ((gdi_layer_struct*) layer_handle)->height;
    image_ptr = ((gdi_layer_struct*) layer_handle)->buf_ptr;
    image_cf = ((gdi_layer_struct*) layer_handle)->cf;

    ret = gdi_image_bmp_encode_file(image_width, image_height, image_cf, image_ptr, file_name);

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_save_bmp_file)
    return ret;
}


#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  gdi_layer_save_raw_data
 * DESCRIPTION
 *  Save the data of layer into file
 * USAGE
 *  gdi_layer_save_raw_data(layer, L"D:\\test");
 *  If the layer in supported format, there will be a raw image file in
 *  D:\test_240x400.6666, as the dimension and format is appended in filename
 *  We can open it on PARGB viewer
 * PARAMETERS
 *  layer_handle    [IN] layer
 *  filepath        [IN] Filepath in UCS2
 * RETURNS
 *  KAL_TRUE if succeed
 *****************************************************************************/
kal_bool gdi_layer_save_raw_data(gdi_handle layer_handle, const WCHAR *filepath)
{
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    WCHAR suffixed_filepath[512];
    const WCHAR *suffix = L"not_support";
    FS_HANDLE fd;

    if (!GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_USED))
    {
        return KAL_FALSE;
    }

    switch (layer->cf)
    {
        case GDI_COLOR_FORMAT_16: suffix = L"565"; break;
        case GDI_COLOR_FORMAT_32_PARGB: suffix = L"p8888"; break;
        case GDI_COLOR_FORMAT_32: suffix = L"8888"; break;
        case GDI_COLOR_FORMAT_PARGB6666: suffix = L"p6666"; break;
    }

    kal_wsprintf(suffixed_filepath, "%w_%dx%d.%w", filepath, layer->width, layer->height, suffix);

    fd = FS_Open(suffixed_filepath, FS_CREATE_ALWAYS);
    if (fd > 0)
    {
        kal_uint32 written;
    
        FS_Write(fd, layer->buf_ptr, layer->layer_size, &written);
        FS_Close(fd);
    }

    return KAL_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_resize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_resize(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_resize)
    gdi_layer_resize_nb_concurrent((gdi_handle)gdi_act_layer, width, height);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_resize)
}

/*****************************************************************************
* DESCRIPTION
*  set the base/active layer rotate value.
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rotate_value        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_set_rotate(U8 rotate_value)
{
#if defined(GDI_USING_LAYER_ROTATE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_rotate)
    gdi_layer_set_rotate_nb_concurrent((gdi_handle)gdi_act_layer, rotate_value);
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_rotate)
#endif /* defined(GDI_USING_LAYER_ROTATE) */ 
}

/*****************************************************************************
* DESCRIPTION
*  copy the active buffer to another buffer
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_copy_double
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_copy_double(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_copy_double)

    /* active layer should be doubled layer */
    GDI_DEBUG_ASSERT(GDI_LAYER_GET_FLAG(gdi_act_layer, GDI_LAYER_FLAG_DOUBLE_LAYER));

    /* swap those two buffer */
    memcpy(gdi_act_layer->buf_ptr, gdi_act_layer->buf_ptr1, gdi_act_layer->layer_size);

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_copy_double)
}

/*****************************************************************************
* DESCRIPTION
*  set the palette
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_select_palette
 * DESCRIPTION
 *  
 * PARAMETERS
 *  palette_number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_select_palette(U8 palette_number)
{
#ifdef GDI_SUPPORT_PALETTES
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_select_palette)
    gdi_act_layer_info->color_palette_select = palette_number;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_select_palette)
#else /* GDI_SUPPORT_PALETTES */ 
    GDI_ASSERT(0);
#endif /* GDI_SUPPORT_PALETTES */ 
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_palette
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_set_palette(U8 index, gdi_color color)
{
#ifdef GDI_SUPPORT_PALETTES
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_palette)
#if DRV_PALETTE_COUNT>0
    /*driver has emptied this api*/
    //set_lcd_color_palette(gdi_act_layer_info->color_palette_select, ((U32*) & color) - index, index, 1);
#endif
    gdi_layer_palette[gdi_act_layer_info->color_palette_select][index] = color;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_palette)
#else /* GDI_SUPPORT_PALETTES */ 
    GDI_ASSERT(0);
#endif /* GDI_SUPPORT_PALETTES */ 
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_palette
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
gdi_color *gdi_layer_get_palette(void)
{
#ifdef GDI_SUPPORT_PALETTES
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color *ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_palette)
    ret = &gdi_layer_palette[gdi_act_layer_info->color_palette_select][0];
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_palette)
    return ret;
#else /* GDI_SUPPORT_PALETTES */ 
    GDI_ASSERT(0);
    return NULL;
#endif /* GDI_SUPPORT_PALETTES */ 
}


void gdi_enable_non_block_blt(void)
{
    /* Deprecated API. Please use gdi_layer_blt_with_flag instead. */
    GDI_LCD_LOCK_MUTEX;
    gdi_is_non_block_blt = TRUE;
    GDI_LCD_UNLOCK_MUTEX;
}


void gdi_disable_non_block_blt(void)
{
    /* Deprecated API. Please use gdi_layer_blt_with_flag instead. */
    gdi_waiting_blt_finish();
    GDI_LCD_LOCK_MUTEX;
    gdi_is_non_block_blt = FALSE;
    GDI_LCD_UNLOCK_MUTEX;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_enable_non_block_blt
 * DESCRIPTION
 *  get gdi_is_non_block_blt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL gdi_layer_get_enable_non_block_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    ret = gdi_is_non_block_blt;
    GDI_LCD_UNLOCK_MUTEX;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_enter_draw_section
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_enter_draw_section(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_waiting_blt_finish();
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_enter_draw_section)
    if (gdi_draw_section_level == 0)
    {
        GDI_LAYER_CLEAR_FLAG(gdi_act_layer, GDI_LAYER_FLAG_FROZEN);
    }
    gdi_draw_section_level++;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_enter_draw_section)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_exit_draw_section
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_exit_draw_section(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_exit_draw_section)
    gdi_draw_section_level--;
    GDI_DEBUG_ASSERT(gdi_draw_section_level >= 0);
    if (gdi_draw_section_level == 0)
    {
        GDI_LAYER_SET_FLAG(gdi_act_layer, GDI_LAYER_FLAG_FROZEN);
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_exit_draw_section)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_layer_set_background(gdi_color color)
{
#ifdef GDI_USING_LAYER_BACKGROUND
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 A, R, G, B;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_background)
    
    /* if UYVY422, background color always BLACK. */
    if (gdi_act_layer->cf == GDI_COLOR_FORMAT_UYVY422)
    {
        gdi_act_layer->background = gd_color_from_rgb_32(255,0,0,0);
        GDI_RETURN(GDI_SUCCEED);
    }
    
    gdi_act_color_to_rgb(&A, &R, &G, &B, color);

    gdi_act_layer->background = gd_color_from_rgb_32(A,R,G,B);

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_background)
    return TRUE;
#else /* GDI_USING_LAYER_BACKGROUND */ 
    return FALSE;
#endif /* GDI_USING_LAYER_BACKGROUND */ 
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
gdi_color gdi_layer_get_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_act_layer->background;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_apply_gray_effect
 * DESCRIPTION
 *  apply gray scale effect to the active layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_apply_gray_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_apply_gray_effect)
#if defined(__MTK_TARGET__)
    if (GDI_COLOR_FORMAT_16 == gdi_act_layer->cf && 
        !(gdi_act_layer->layer_size & 0xf) && !((S32) gdi_act_layer->buf_ptr & 0x3))
    {
        gd_gray_16(gdi_act_layer->buf_ptr, gdi_act_layer->layer_size);
    }
    else
#endif /* defined(__MTK_TARGET__) */ 
    {
        S32 x = 0;
        S32 y = 0;
        gdi_color color;
        U32 a, r, g, b;//, max, min;
        gd_get_pixel_func get_ptr = gd_get_pixel[gdi_act_layer->cf];
        gd_put_pixel_func put_ptr = gd_put_pixel[gdi_act_layer->cf];

        for (y = 0; y < gdi_act_layer->height; y++)
        {
            for (x = 0; x < gdi_act_layer->width; x++)
            {
                color = get_ptr(x,y);
                gdi_act_color_to_rgb(&a,&r,&g,&b,color);
                r = (r + (g << 1) + b)>>2;
                if (r > GDI_GRAY_BOUNDARY)
                {
                    r = GDI_GRAY_BOUNDARY;
                }
                put_ptr(x,y,gdi_act_color_from_rgb(a,r,r,r));
            }
        }
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_apply_gray_effect)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_add_post_adjustment
 * DESCRIPTION
 *  preview fail handler (driver error)
 * PARAMETERS
 *  adjustment_id       [IN]        Adjustment type
 *  value               [IN]        Adjustment value
 *  layer_handle(?)     [IN]        Layer handle
 * RETURNS
 *  void
 *****************************************************************************/
GDI_RESULT gdi_layer_add_post_adjustment(U16 adjustment_id, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(GDI_USING_ISP)
    S32 layer_width;
    S32 layer_height;
    S32 bits_per_pixel;
    PU8 buf_ptr;
    S32 buf_size;
    PU8 work_buf_ptr_1;
    PU8 work_buf_ptr_2;
    U16 drv_adj_id;
    IMAGE_EFFECT_DEC_STRUCT effect_data;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_USING_ISP)
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_add_post_adjustment)

    memset(&effect_data, 0, sizeof(IMAGE_EFFECT_DEC_STRUCT));
    
    drv_adj_id = 0;

#define POST_ADJUSTMENT_MAPPING_SWITCH(__adj__)\
      case GDI_LAYER_ADJUSMENT_##__adj__##:       \
         drv_adj_id = CAM_ADJ_DEC_##__adj__##;    \
         break;                                   \

    switch (drv_adj_id)
    {
            POST_ADJUSTMENT_MAPPING_SWITCH(BRIGHTNESS);
            POST_ADJUSTMENT_MAPPING_SWITCH(CONTRAST);
            POST_ADJUSTMENT_MAPPING_SWITCH(SATURATION);
            POST_ADJUSTMENT_MAPPING_SWITCH(HUE);
            POST_ADJUSTMENT_MAPPING_SWITCH(ADJR);
            POST_ADJUSTMENT_MAPPING_SWITCH(ADJG);
            POST_ADJUSTMENT_MAPPING_SWITCH(ADJB);
        default:
            /* shall not enter here */
            MMI_ASSERT(0);
            break;
    }

    layer_width = gdi_act_layer->width;
    layer_height = gdi_act_layer->height;
    buf_ptr = gdi_act_layer->buf_ptr;
    bits_per_pixel = gdi_act_layer->bits_per_pixel;

    buf_size = (layer_width * layer_height * bits_per_pixel) >> 3;

    /* allocate from media task */
    work_buf_ptr_1 = (PU8)gdi_alloc_ext_mem(((layer_width * layer_height * bits_per_pixel) >> 3));
    work_buf_ptr_2 = (PU8)gdi_alloc_ext_mem(((layer_width * layer_height * bits_per_pixel) >> 3));

    /* TEMP: HW BUGS on MT6219 - source cant be internal SRAM */
    memcpy(work_buf_ptr_2, buf_ptr, buf_size);
    memset(work_buf_ptr_1, 0, buf_size);

    /* TODO: fix when support 888 format */
    switch (gdi_act_layer->cf)
    {
        case GDI_COLOR_FORMAT_16:

#if defined(DRV_IDP_OLD_DESIGN)
            effect_data.data_type = IBR1_TYPE_RGB565;
#else
            effect_data.src_color_fmt = IMG_COLOR_FMT_RGB565;
#endif
            break;
        case GDI_COLOR_FORMAT_24:

#if defined(DRV_IDP_OLD_DESIGN)
            effect_data.data_type = IBR1_TYPE_RGB888;
#else
            effect_data.src_color_fmt = IMG_COLOR_FMT_RGB888;
#endif
            break;
        default:
            GDI_ASSERT(0);
    }

#if defined(DRV_IDP_OLD_DESIGN)
    effect_data.data_order = IBR1_ORDER_BGR888;             /* not used - just give it a value */
#endif
    
    effect_data.source_buffer_address = (kal_uint32) work_buf_ptr_2;
    effect_data.dest1_buffer_address = (kal_uint32) work_buf_ptr_1;
    effect_data.dest2_buffer_address = (kal_uint32) NULL;   /* not used */
    effect_data.image_width = layer_width;
    effect_data.image_height = layer_height;
    effect_data.effect_index = drv_adj_id;
    effect_data.adj_level = value;
    effect_data.image_effect_dec_cb = NULL;                 /* not used */

    image_adj_dec_process(&effect_data);

    /* copy result to soruce layer */
    memcpy(buf_ptr, work_buf_ptr_1, buf_size);

    /* free buffer */
    gdi_free_ext_mem((void **)&work_buf_ptr_1);
    gdi_free_ext_mem((void **)&work_buf_ptr_2);

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_add_post_adjustment)
    return GDI_SUCCEED;
#else /* defined(GDI_USING_ISP) */ 
    return GDI_FAILED;
#endif /* defined(GDI_USING_ISP) */
    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_is_double
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_layer_is_double(gdi_handle layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(GDI_LAYER_GET_FLAG(layer, GDI_LAYER_FLAG_DOUBLE_LAYER))
        return TRUE;
    else
        return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_frame_buffer_lock_count
 * DESCRIPTION
 *  get the frame buffer blt_lock count
 * PARAMETERS
 *  frame_buffer_lock_count [OUT] 
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_layer_get_frame_buffer_lock_count(S32 *frame_buffer_lock_count)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_frame_buffer_lock_count)
    *frame_buffer_lock_count = GDI_LCD->blt_lock;
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_frame_buffer_lock_count)
}

/*****************************************************************************
 * FUNCTION
 *  gdi_set_alpha_blending_source_layer
 * DESCRIPTION
 *  set alpha source blending source layer
 * PARAMETERS
 *  src_layer_handle       [IN] gdi handle of the alpha source layer
 * RETURNS
 *  gdi_handle  old alpha source layer handle
 *****************************************************************************/
gdi_handle gdi_set_alpha_blending_source_layer(gdi_handle src_layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;
    gdi_handle  old_src_layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_SET_ABLEND_SOURCE_LAYER, lr,
        (kal_uint32)g_alpha_blending_source_layer, (kal_uint32)src_layer_handle);
    
    GDI_LOCK;
    
    old_src_layer_handle = g_alpha_blending_source_layer;
    g_alpha_blending_source_layer = src_layer_handle;  
    
    GDI_UNLOCK;

    return old_src_layer_handle;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_get_alpha_blending_source_layer
 * DESCRIPTION
 *  get alpha blending source layer
 * PARAMETERS
 *  src_layer_handle       [OUT] gdi handle of the alpha source layer
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_get_alpha_blending_source_layer(gdi_handle *src_layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    
    *src_layer_handle = g_alpha_blending_source_layer;
    
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_push_and_set_alpha_blending_source_layer
 * DESCRIPTION
 *  push current alpha source layer into stack and set passin layer as alpha source layer
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_push_and_set_alpha_blending_source_layer(gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    
    GDI_LOCK;
    
    GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_PUSH_SOURCE_LAYER,
        lr, gdi_alpha_blending_source_layer_stack_index, (kal_uint32)handle);
    
    /* no more stack entry available */
    GDI_ASSERT(gdi_alpha_blending_source_layer_stack_index <= GDI_ALPHA_BLENDING_SOURCE_LAYER_STACK_COUNT - 1);

    gdi_alpha_blending_source_layer_stack[gdi_alpha_blending_source_layer_stack_index++] = g_alpha_blending_source_layer;
    g_alpha_blending_source_layer = handle;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_pop_and_restore_alpha_blending_source_layer
 * DESCRIPTION
 *  pop the layer in stack and make it as alpha source layer
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT(?)
 *****************************************************************************/
void gdi_pop_and_restore_alpha_blending_source_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    
    GDI_ASSERT(gdi_alpha_blending_source_layer_stack_index > 0);
    g_alpha_blending_source_layer = gdi_alpha_blending_source_layer_stack[--gdi_alpha_blending_source_layer_stack_index];

    GDI_TRACE(GDI_TRC_PAIRED_LAYER, GDI_TRC_LAYER_POP_SOURCE_LAYER,
        lr, gdi_alpha_blending_source_layer_stack_index, (kal_uint32)g_alpha_blending_source_layer);
    
    GDI_UNLOCK;
}

/*
 *  NB Concurrent API
 */
GDI_RESULT gdi_layer_set_position_nb_concurrent(gdi_handle layer_handle, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer->offset_x = offset_x;
    layer->offset_y = offset_y;

    gdi_layer_info[layer->id].x_offset = (offset_x + GDI_LAYER_OFFSET);
    gdi_layer_info[layer->id].y_offset = (offset_y + GDI_LAYER_OFFSET);

    return GDI_SUCCEED;
}


GDI_RESULT gdi_layer_set_rotate_nb_concurrent(gdi_handle layer_handle, U8 rotate_value)
{
#if defined(GDI_USING_LAYER_ROTATE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    layer->rotate_value = rotate_value;
    return GDI_SUCCEED;
#else
    return GDI_FAILED;
#endif /* defined(GDI_USING_LAYER_ROTATE) */ 
}


GDI_RESULT gdi_layer_set_source_key_nb_concurrent(
            gdi_handle layer_handle, 
            BOOL source_key_enable, 
            gdi_color source_key_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(GDI_USE_RGB565_TO_SHOW_BW)
    gdi_layer_info[layer->id].source_key_enable = KAL_FALSE;
    gdi_layer_info[layer->id].source_key = 0;
    #else
    gdi_layer_info[layer->id].source_key_enable = (kal_bool)source_key_enable;
    gdi_layer_info[layer->id].source_key = source_key_value;
    #endif
    return GDI_SUCCEED;
}


GDI_RESULT gdi_layer_set_opacity_nb_concurrent(gdi_handle layer_handle, BOOL opacity_enable, U8 opacity_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    gdi_lcd_layer_struct *layer_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_info = &gdi_layer_info[layer->id];
#if !defined(GDI_LCD_MEMORY_OUTPUT_PARGB8888_SUPPORT)
    if (GDI_COLOR_FORMAT_32 == layer->cf)
    {
        layer_info->opacity_enable = KAL_TRUE;
    #ifdef LCD_MAX_OPACITY
        layer_info->opacity_value = opacity_value * LCD_MAX_OPACITY / 255;  /* shift 3, hw only support 5 bit */
    #else 
        layer_info->opacity_value = opacity_value;
    #endif
        return GDI_SUCCEED;
    }

    if (opacity_enable && opacity_value == 255)
    {
        opacity_enable = FALSE;
    }
#endif

    layer_info->opacity_enable = (kal_bool)opacity_enable;
#ifdef LCD_MAX_OPACITY
    layer_info->opacity_value = opacity_value * LCD_MAX_OPACITY / 255;  /* shift 3, hw only support 5 bit */
#else 
    layer_info->opacity_value = opacity_value;
#endif 

    return GDI_SUCCEED;
}


GDI_RESULT gdi_layer_set_background_nb_concurrent(gdi_handle layer_handle, gdi_color color)
{
#ifdef GDI_USING_LAYER_BACKGROUND
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    U32 A, R, G, B;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gd_color_to_rgb[layer->cf](&A, &R, &G, &B, color);
    layer->background = gd_color_from_rgb_32(A,R,G,B);

    return GDI_SUCCEED;
#else /* GDI_USING_LAYER_BACKGROUND */ 
    return GDI_FAILED;
#endif /* GDI_USING_LAYER_BACKGROUND */
}


GDI_RESULT gdi_layer_resize_nb_concurrent(gdi_handle layer_handle, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    GDI_DEBUG_ASSERT(gdi_sizeof_pixels(layer->cf, width, height) <= layer->layer_size);
    layer->width = (U16) width;
    layer->height = (U16) height;

    GDI_ASSERT(layer->clips_top == 0);

    GDI_LAYER_RESET_CLIPS(layer);
    GDI_LAYER_SET_CLIP(layer, 0, 0, width - 1, height - 1);

    /* reset blt region */
    GDI_LAYER_SET_BLT_RECT(layer_handle, 0, 0, width, height);
    
    return GDI_SUCCEED;
}


GDI_RESULT gdi_layer_clear_nb_concurrent(gdi_handle layer_handle, gdi_color bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (layer->bits_per_pixel == 16)
    {
        if (layer->cf == GDI_COLOR_FORMAT_UYVY422)
        {
            bg_color = 0x0080; /* Only support clear to black */
        }
    
        gdi_memset16((U8*)layer->buf_ptr, (U16) bg_color, layer->layer_size);
    }
#ifdef GDI_PRIMITIVE_24_BIT_SUPPORT
    else if (layer->bits_per_pixel == 24)
    {
        gdi_memset24((U8*)layer->buf_ptr, (U32) bg_color, layer->layer_size);
    }
#endif
    else if (layer->bits_per_pixel == 32)
    {
        gdi_memset32((U8*)layer->buf_ptr, (U32) bg_color, layer->layer_size);
    }
    else
    {
        S32	r_index;
    	for(r_index = 0 ; r_index <= (layer->height - 1); r_index++)
    	{
    		S32	h_index;
            
    		for(h_index = 0; h_index <= (layer->width - 1); h_index++)
    		{
    			gd_put_pixel_to_layer[layer->cf](layer_handle, h_index, r_index, bg_color);
    		}
    	}
    }
    return GDI_SUCCEED;
}


GDI_RESULT gdi_layer_get_dimension_nb_concurrent(gdi_handle layer_handle, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = layer->width;
    *height = layer->height;
    return GDI_SUCCEED;
}


void gdi_draw_solid_rect_nb_concurrent(gdi_handle layer_handle, S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;
    S32	r_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((x1 > x2) || 
       (y1 > y2) || 
       (x2 < layer->clipx1) || 
       (y2 < layer->clipy1) || 
       (x1 > layer->clipx2) || 
       (y1 > layer->clipy2)) 
    { 
        return; 
    }
    else
    {
        if(x1 < layer->clipx1)
        {
            x1 = layer->clipx1;
        }
        if(y1 < layer->clipy1)
        {
            y1 = layer->clipy1;
        }
        if(x2 > layer->clipx2)
        {
            x2 = layer->clipx2;
        }
        if(y2 > layer->clipy2)
        {
            y2 = layer->clipy2;
        }
    }
    
	for(r_index = y1 ; r_index <= y2; r_index++)
	{
		S32	h_index;
        
		for(h_index = x1; h_index <= x2; h_index++)
		{
			gd_put_pixel_to_layer[layer->cf](layer_handle, h_index, r_index, rect_color);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_rotate_nb_concurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gdi_layer_get_rotate_nb_concurrent(gdi_handle layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return layer->rotate_value;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_position
 * DESCRIPTION
 *  get currently active layer's position.
 * PARAMETERS
 *  offset_x        [OUT]       
 *  offset_y        [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_get_position_nb_concurrent(gdi_handle layer_handle, S32 *offset_x, S32 *offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer = (gdi_layer_struct*)layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *offset_x = (S32) layer->offset_x;
    *offset_y = (S32) layer->offset_y;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blend_2_layers
 * DESCRIPTION
 *  put the src layer color to active layer if active layer is transparent color.
 * PARAMETERS
 *  src_layer_handle    [IN]    alpha blending source layer
 *  x1                  [IN]    region on active layer
 *  y1                  [IN]    region on active layer
 *  x2                  [IN]    region on active layer
 *  y2                  [IN]    region on active layer
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_blend_2_layers(
            gdi_handle src_layer_handle, 
            S32 x1, 
            S32 y1, 
            S32 x2, 
            S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_rect_struct dest_clip;
    gdi_layer_struct *src_layer = (gdi_layer_struct*)src_layer_handle;
    BOOL source_key_enable = KAL_FALSE;
    gdi_color source_key_value = 0;
    gdi_img_buf_struct dst_buf, src_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_blend_2_layers)

    /* use flatten if flatten is ready */
    if ((gdi_layer_flatten_is_ready() == KAL_TRUE) &&	/* If multimedia is not using, use flatten */
        (src_layer->cf != GDI_COLOR_FORMAT_32_PARGB) && 
        (gdi_act_layer->cf != GDI_COLOR_FORMAT_32_PARGB))   
    {
        gdi_layer_push_clip();
        do
        {
            /* clip dest region and active layer clip region */
            dest_clip.x1 = x1;
            dest_clip.y1 = y1;
            dest_clip.x2 = x2;
            dest_clip.y2 = y2;
            GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);
            gdi_layer_set_clip(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2);
        }while(0);        
        gdi_layer_flatten_with_clipping(src_layer_handle, (gdi_handle)gdi_act_layer ,0,0);
        gdi_layer_pop_clip();

        GDI_RETURN(GDI_SUCCEED);
    }

    {
        BOOL opacity_enable;
        U8 opacity_value;
        gdi_layer_get_opacity(&opacity_enable, &opacity_value);
        if (opacity_enable)
        {
            GDI_RETURN(GDI_FAILED); /* not support opacity */
        }
    }

    /* use sw to put the src layer point to active layer */
    
    gdi_layer_push_clip();
    do
    {
        /* get active layer source key */
        ret = gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if ((ret < 0) || (source_key_enable != TRUE))
        {
            ret = GDI_SUCCEED;  /* active layer source key disable, return succeed directly */
            break;
        }
        
        do
        {
            ret = GDI_FAILED;
            /* clip dest region and active layer clip region */
            dest_clip.x1 = x1;
            dest_clip.y1 = y1;
            dest_clip.x2 = x2;
            dest_clip.y2 = y2;
            GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);
            gdi_layer_set_clip(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2);

            /* clip with src_layer region */
            dest_clip.x1 = src_layer->offset_x - gdi_act_layer->offset_x;
            dest_clip.y1 = src_layer->offset_y - gdi_act_layer->offset_y;
            dest_clip.x2 = dest_clip.x1 + src_layer->width - 1;
            dest_clip.y2 = dest_clip.y1 + src_layer->height - 1;
            GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);
            gdi_layer_set_clip(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2);

            ret = GDI_SUCCEED;
        }while(0);
        if (ret == GDI_FAILED)  
        {
            ret = GDI_SUCCEED;  /* output of clip, return succeed directly */
            break;
        }

        dst_buf.pitch_bytes = gdi_act_layer->width * (gdi_act_layer->bits_per_pixel >> 3);
        dst_buf.color_format = gdi_img_buf_trans_color_format(gdi_act_layer->cf);
        dst_buf.ptr = gdi_act_layer->buf_ptr;
        dst_buf.ptr += ((dest_clip.y1 * gdi_act_layer->width) + dest_clip.x1) * (gdi_act_layer->bits_per_pixel >> 3);

        src_buf.pitch_bytes = src_layer->width* (src_layer->bits_per_pixel >> 3);
        src_buf.color_format = gdi_img_buf_trans_color_format(src_layer->cf);
        src_buf.ptr = src_layer->buf_ptr;
        src_buf.ptr += (((dest_clip.y1 + gdi_act_layer->offset_y - src_layer->offset_y) * src_layer->width) 
                        + (dest_clip.x1 + gdi_act_layer->offset_x - src_layer->offset_x)) * (src_layer->bits_per_pixel >> 3);
            
        gdi_img_buf_flatten(
            &dst_buf, 
            source_key_value,
            &src_buf,
            dest_clip.x2 - dest_clip.x1 + 1,
            dest_clip.y2 - dest_clip.y1 + 1);

        ret = GDI_SUCCEED;
    }while(0);
    
    gdi_layer_pop_clip();
    
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_blend_2_layers)
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_blt_layer_flag
 * DESCRIPTION
 *  MDI needs to set blt layer flag when they set hw update layer.
 *  So they have to get blt layer flag from gdi.
 *  When "blt with double buffer" is enable, the real blt layer is in gdi_blt_with_double_buf_blt_handle[].
 * PARAMETERS
 *  blt_layer_flag  [OUT]  return the blt_layer_flag
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
gdi_result gdi_layer_get_blt_layer_flag(U32 *blt_layer_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 layer_flag = 0;
    gdi_handle *blt_layer = GDI_LCD->blt_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_get_blt_layer_flag)

#define SET_LAYER_FLAG(ID) \
    if ((blt_layer[ID] >= GDI_LAYER_VALID_HANDLE_START) &&           \
        (GDI_LAYER_GET_FLAG(blt_layer[ID], GDI_LAYER_FLAG_USED)))    \
    {                                                               \
        layer_flag |= LCD_LAYER##ID##_ENABLE;                       \
    }

    SET_LAYER_FLAG(0);
    SET_LAYER_FLAG(1);
    SET_LAYER_FLAG(2);
    SET_LAYER_FLAG(3);
#ifdef GDI_6_LAYERS
    SET_LAYER_FLAG(4);
    SET_LAYER_FLAG(5);
#endif

#undef SET_LAYER_FLAG

    *blt_layer_flag = layer_flag;

    GDI_EXIT_CRITICAL_SECTION(gdi_layer_get_blt_layer_flag);
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_hw_update_layer
 * DESCRIPTION
 *  set the layer as a hw update layer.
 *  hw update layer means the layer content and settings are set by multimedia hw, ex. Camera or video. 
 *  GDI won't set the layer config of hw layer to lcd, except layer offset.
 * PARAMETERS
 *  layer_handle  [IN]  the layer to be set as hw update layer
 *  is_hw_layer   [OUT] the layer is hw layer or not
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_set_hw_update_layer(gdi_handle layer_handle, kal_bool is_hw_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_hw_update = KAL_FALSE;
    gdi_layer_struct *layer_struct;
    kal_uint32 lr = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_GET_RETURN_ADDRESS(lr);
    GDI_TRACE(GDI_TRC_LAYER, GDI_TRC_LAYER_SET_HW_UPDATE_LAYER, (kal_uint32)layer_handle, is_hw_layer, lr);
    
    if ((layer_handle == GDI_NULL_HANDLE) ||
        (!GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_USED)))
    {
        return GDI_FAILED;
    }
    
    GDI_ENTER_CRITICAL_SECTION(gdi_layer_set_hw_update_layer)

    if (is_hw_layer)
    {
        GDI_LAYER_SET_FLAG(layer_handle, GDI_LAYER_FLAG_HW_UPDATE);
    }
    else
    {
        gdi_lcd_get_hw_update(&is_hw_update);

        /* when hw updating, can't set a hw layer as a normal layer */
        ASSERT((!GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_HW_UPDATE)) || (!is_hw_update));
        
        GDI_LAYER_CLEAR_FLAG(layer_handle, GDI_LAYER_FLAG_HW_UPDATE);

        /* If app change the layer to SW layer, the hardward attribute should be discarded */
        layer_struct = (gdi_layer_struct*)layer_handle;
        layer_struct->hw_update_element = 0;
    }
    
    GDI_EXIT_CRITICAL_SECTION(gdi_layer_set_hw_update_layer)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_is_hw_update_layer
 * DESCRIPTION
 *  query if the layer is hw update layer.
 * PARAMETERS
 *  layer_handle  [IN]  the layer to query
 *  is_hw_layer   [OUT] the layer is hw layer or not
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_is_hw_update_layer(gdi_handle layer_handle, kal_bool *is_hw_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((layer_handle == GDI_NULL_HANDLE) ||
        (!GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_USED)) || 
        NULL == is_hw_layer)
    {
        return GDI_FAILED;
    }
    
    *is_hw_layer = (GDI_LAYER_GET_FLAG(layer_handle, GDI_LAYER_FLAG_HW_UPDATE))? KAL_TRUE : KAL_FALSE;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_layer_element
 * DESCRIPTION
 *  return the WFCDevice and WFCContext and WFCElement.
 *  WFCElement and WFCContext handle would be different between MAIN_LCD or SUBLCD.
 *  Remember to set correct active LCD before using this API.
 *
 *  Multimedia APP may need to get layer element, and pass the handle to Multimedia hw.
 *  Becuase Multimedia hw, ex, camera or video, may need to modify the layer element attribute while hw updating.
 * PARAMETERS
 *  blt_layer_index     [IN]    the index of blt layer. GDI_LAYER_ENABLE_LAYER_0~GDI_LAYER_ENABLE_LAYER_5
 *  layer_element       [OUT]   return the WFCElement of the specified layer index
 *  blt_ctx             [OUT]   return the blt contex handle. It's needed when calling wfcCommit
 *  blt_dev             [OUT]   return the blt device handle. It's needed when calling wfcSetElementAttribi
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_layer_get_layer_element(U32 blt_layer_index, kal_uint32 *layer_element, kal_uint32 *blt_ctx, kal_uint32 *blt_dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_lcd_v2_context_enum blt_ctx_idx;
    U8 blt_layer_index_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (blt_layer_index)
    {
        case GDI_LAYER_ENABLE_LAYER_0:
            blt_layer_index_num = 0;
            break;
        case GDI_LAYER_ENABLE_LAYER_1:
            blt_layer_index_num = 1;
            break;
        case GDI_LAYER_ENABLE_LAYER_2:
            blt_layer_index_num = 2;
            break;
        case GDI_LAYER_ENABLE_LAYER_3:
            blt_layer_index_num = 3;
            break;
    #ifdef GDI_6_LAYERS
        case GDI_LAYER_ENABLE_LAYER_4:
            blt_layer_index_num = 4;
            break;
        case GDI_LAYER_ENABLE_LAYER_5:
            blt_layer_index_num = 5;
            break;
    #endif
        default:
            ASSERT(0);
    }

#if defined(__MMI_SUBLCD__)
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        blt_ctx_idx = GDI_LCD_V2_CTX_BLT_SUB_LCD;
    }
    else
#endif
    {
        blt_ctx_idx = GDI_LCD_V2_CTX_BLT_MAIN_LCD;
    }

    if (layer_element)
    {
        *layer_element = (kal_uint32)gdi_lcd_v2_ctx_array[blt_ctx_idx].elm[blt_layer_index_num];
    }

    if (blt_ctx)
    {
        *blt_ctx = (kal_uint32)gdi_lcd_v2_ctx_array[blt_ctx_idx].ctx_handle;
    }

    if (blt_dev)
    {
        *blt_dev = (kal_uint32)gdi_lcd_v2_dev;
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_get_actual_rotate_value
 * DESCRIPTION
 *  return the actual rotate value.
 *  GDI user may use "layer rotate" or "lcd rotate+rotate by layer" to rotate a layer.
 *  ("layer rotate" set by gdi_layer_set_rotate)
 *  ("lcd rotate" set by gdi_lcd_set_rotate, "rotate by layer" set by gdi_lcd_get_rotate_by_layer)
 *  If it simply use "layer rotate", we return the layer rotate value.
 *  But if it use "lcd rotate+rotate by layer", we'll return the final rotate value that gdi set to lcd driver.
 *  In DDV2, while "video seek", the hw layer will not blt to lcd, so it's not set to DDv2 element.
 *  But the video driver still have to know the layer actual rotate value to rotate the video content for MDI.
 *  So GDI provide this API to calculate the layer actual rotate value.
 * PARAMETERS
 *  layer_handle                    [IN]    layer handle
 *  layer_actual_rotate_value       [OUT]   return the actual layer rotate value
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
gdi_result gdi_layer_get_actual_rotate_value(gdi_handle layer_handle, kal_uint8 *layer_actual_rotate_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_struct *layer_struct = (gdi_layer_struct*)layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (layer_actual_rotate_value == NULL)
    {
        return GDI_FAILED;
    }
    else
    {
        *layer_actual_rotate_value = 0;
    }

#if defined(GDI_USING_LCD_ROTATE)
    if (!GDI_LCD->rotate_by_layer)
    {
        *layer_actual_rotate_value = layer_struct->rotate_value;
    }
    else
#endif
#if defined(GDI_USING_LAYER_ROTATE) || defined(GDI_USING_LCD_ROTATE)
    {
        *layer_actual_rotate_value = (U8) ((((GDI_LCD_LAYER_ROTATE_MIRROR_MASK & GDI_LCD->rotate_value) |
                                           (0x04 - (GDI_LCD_LAYER_ROTATE_ANGLE_MASK & GDI_LCD->rotate_value))) +
                                          layer_struct->rotate_value) & GDI_LCD_LAYER_ROTATE_ALL_MASK);
    }
#endif

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_set_blt_finish_callback
 * DESCRIPTION
 *  Set the blt complete callback.
 * PARAMETERS
 *  blt_finish_callback     [IN]    blt finish callback
 *  param                   [IN]    parameter of blt finish callback
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static void gdi_layer_set_blt_finish_callback(
             void (*blt_finish_callback)(void *param),
             void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt_finish_callback = blt_finish_callback;
    gdi_layer_blt_finish_param = param;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_layer_blt_nb_concurrent_no_blt_lock
 * DESCRIPTION
 *  Blt layers without check blt lock.
 *  
 * PARAMETERS
 *  handle0     [IN]        
 *  handle1     [IN]        
 *  handle2     [IN]        
 *  handle3     [IN]        
 *  handle4     [IN]        
 *  handle5     [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
GDI_RESULT gdi_layer_blt_nb_concurrent_no_blt_lock(
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
            void (*blt_finish_callback)(void *param),
            void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret;
    gdi_layer_blt_flag_bit_set flag;
    gdi_callback_struct callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LCD_LOCK_MUTEX;
    
    callback.callback_func = blt_finish_callback;
    callback.user_data = param;

    /*
     * This API is customized for 3D projects.
     * For 3D rendering, VRT don't need checking blt lock.
     */
    flag = GDI_LAYER_BLT_FLAG_IGNORE_BLT_LOCK;

    /* Always non-blocking for this customized API */
    flag |= GDI_LAYER_BLT_FLAG_NON_BLOCKING;

#if defined(GDI_LCD_SCANLINE_ROTATION)
    if (GDI_LCD->scanline_rotation)
    {
        /* Always check blt lock for scanline rotation */
        flag &= (~GDI_LAYER_BLT_FLAG_IGNORE_BLT_LOCK);
    }
    /* For common UI screen, flatten and rotate the layer */
    if (gdi_scanline_intercept_blt(GDI_LCD, 0))
    {
        ret = gdi_scanline_layer_blt(
                  handle0, 
                  handle1, 
                  handle2, 
                  handle3,
                  handle4, 
                  handle5,
                  x1, 
                  y1, 
                  x2, 
                  y2,
                  0,
                  &callback);
    }
    else
#endif /* GDI_LCD_SCANLINE_ROTATION */
    {
        ret = gdi_layer_blt_ext_internal(
                handle0, 
                handle1, 
                handle2, 
                handle3,
                handle4, 
                handle5,
                x1, 
                y1, 
                x2, 
                y2,
                flag,
                &callback);
    }
    GDI_LCD_UNLOCK_MUTEX;

    return ret;
}

