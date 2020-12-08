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
 *  gdi_imgdec.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GDI IMGDEC decoder kernel
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gdi_features.h"
#include "gdi_imgdec.h"
#include "gdi_imgdec_bytestream.h"

#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "string.h"
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_internal.h"
#include "gdi_include.h"
#include "gdi_image.h"
#include "gdi_primitive.h"
#include "gdi_trc.h"
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
#include "gdi_image_mav.h"
#endif

/* currently support PNG, BMP, JPG, GIF, WBMP formats */
#define GDI_IMGDEC_FILE_FORMAT_NUM  6
#define GDI_IMGDEC_CODEC_WAITING_TIME   6000       /* ms */
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* single instance IMGDEC decoder mutex (ex: HW) */
static kal_semid g_gdi_imgdec_hw_dec_mutex;
static kal_timerid g_imgdec_timer;
kal_bool g_imgdec_timer_timeout_flag = KAL_FALSE;

/*
 * file type related structure
 */
typedef struct
{
    S8 *magic;      /* magic number */
    U8 magic_len;   /* magic number length */
    U8 file_type;   /* GDI image file type */
    U8 mem_type;    /* GDI image mem type */
} gdi_imgdec_file_type_struct;

/* file type map */
static const gdi_imgdec_file_type_struct g_gdi_imgdec_file_type_map[GDI_IMGDEC_FILE_FORMAT_NUM] =
{
    {"\xFF\xD8\xFF", 3, GDI_IMAGE_TYPE_JPG_FILE, GDI_IMAGE_TYPE_JPG}, /* JPEG */
    {"BM", 2, GDI_IMAGE_TYPE_BMP_FILE, GDI_IMAGE_TYPE_BMP_MEM}, /* BMP */
    {"GIF", 3, GDI_IMAGE_TYPE_GIF_FILE, GDI_IMAGE_TYPE_GIF}, /* GIF */
    {"\x89PNG\x0D\x0A\x1A\x0A", 8, GDI_IMAGE_TYPE_PNG_FILE, GDI_IMAGE_TYPE_PNG}, /* PNG */
    {"\x00\x00", 2, GDI_IMAGE_TYPE_WBMP_FILE, GDI_IMAGE_TYPE_WBMP}, /* WBMP */
    {"\x00\x00\x00\x00\x56\x41\x4D\x00", 8, GDI_IMAGE_TYPE_MAV_FILE, GDI_IMAGE_TYPE_MAV}, /* MAV */
};


/*
 * IMGDEC decoder interfaces
 */
extern GDI_RESULT gdi_imgdec_jpeg_draw_internal(gdi_handle output_layer, gdi_image_src_enum src_type, U8 *src, U32 size, S32 x, S32 y, S32 resized_width, S32 resized_height, BOOL *is_aborted, U32 flag, S32 aspect_flag);
extern GDI_RESULT gdi_imgdec_bmp_draw_handler(gdi_handle out_layer, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size, BOOL *is_aborted, U32 flag, S32 aspect_flag);
extern GDI_RESULT gdi_imgdec_wbmp_draw_handler(gdi_handle out_layer, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size, BOOL *is_aborted, U32 flag, S32 aspect_flag);
extern GDI_RESULT gdi_imgdec_gif_draw_handler(gdi_handle out_layer, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size, BOOL *is_aborted, U32 flag, S32 aspect_flag);

#ifdef GDI_USING_PNG
extern GDI_RESULT gdi_imgdec_png_draw_internal(gdi_handle output_layer_handle, gdi_handle src_layer_handle, S32 ox, S32 oy, S32 resized_width, S32 resized_height, U8 *src, U32 size, BOOL is_file, BOOL *is_aborted, U32 flag, S32 aspect_flag);
#endif

extern GDI_RESULT gdi_imgdec_jpeg_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);
extern GDI_RESULT gdi_imgdec_bmp_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);
extern GDI_RESULT gdi_imgdec_gif_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);
extern GDI_RESULT gdi_imgdec_png_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);
extern GDI_RESULT gdi_imgdec_wbmp_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);

//warning
extern kal_uint32 drv_get_current_time(void);



/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_hw_dec_mutex_create
 * DESCRIPTION
 *  Creates image codec
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_hw_dec_mutex_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gdi_imgdec_hw_dec_mutex = kal_create_sem("IMGDEC HW MUTEX", 1);
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_hw_dec_mutex_take
 * DESCRIPTION
 *  Takes IMGDEC mutex.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_hw_dec_mutex_take(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_query_systemInit() == KAL_FALSE)
    {
    #ifndef __MTK_TARGET__
        while (kal_take_sem(g_gdi_imgdec_hw_dec_mutex, KAL_NO_WAIT) != KAL_SUCCESS)
        {
            /* sleep a tick to suspend the MMI task */
            kal_sleep_task(1);
        }
    #else /* __MTK_TARGET__ */
        kal_take_sem(g_gdi_imgdec_hw_dec_mutex, KAL_INFINITE_WAIT);
    #endif /* __MTK_TARGET__ */
    }        
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_hw_dec_mutex_give
 * DESCRIPTION
 *  Releases IMGDEC mutex.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_hw_dec_mutex_give(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_query_systemInit() == KAL_FALSE)
    {
        kal_give_sem(g_gdi_imgdec_hw_dec_mutex);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_init
 * DESCRIPTION
 *  IMGDEC bootup initialization routine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_imgdec_hw_dec_mutex_create();
    g_imgdec_timer = kal_create_timer("GDIMGDEC");
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_get_type
 * DESCRIPTION
 *  Gets image type.
 * PARAMETERS
 *  src             [IN]    src pointer
 *  size            [IN]    image src size
 * RETURNS
 *  Image type.
 *****************************************************************************/
static U8 gdi_imgdec_get_type(U8* src, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U8 type = GDI_IMAGE_TYPE_INVALID;    
    gdi_imgdec_bytestream_struct bs;
    U8 buf[16];
    BOOL is_file;

    S32 i;
    const gdi_imgdec_file_type_struct *ft;
    GDI_RESULT result = GDI_FAILED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_file = (size == 0);

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
    /* Decide whether it is MAV */
    if (is_file)
    {
        result = gdi_image_is_mav_file(src);
        type = GDI_IMAGE_TYPE_MAV_FILE;
    }
    else
    {
        result = gdi_image_is_mav_mem(src, size);
        type = GDI_IMAGE_TYPE_MAV;
    }
#endif
    
    if (result == GDI_SUCCEED)
    {
        return type;
    }
    
    type = GDI_IMAGE_TYPE_INVALID;
    if (gdi_imgdec_bytestream_init(&bs, src, size) != GDI_SUCCEED)
    {
        return GDI_IMAGE_TYPE_INVALID;
    }

    memset(buf, 0, 16);
    /* do not recognize file size 0 or 1 with WBMP */
    buf[0] = 1;
    gdi_imgdec_bytestream_read(&bs, buf, 8);

    /* search through all file types */
    for (i = 0; i < GDI_IMGDEC_FILE_FORMAT_NUM; i++)
    {
        ft = &g_gdi_imgdec_file_type_map[i];

        if (!memcmp(buf, ft->magic, (U32)ft->magic_len))
        {
            if (is_file)
            {
                type = ft->file_type;
            }
            else
            {
                type = ft->mem_type;
            }

            break;
        }
    }

    gdi_imgdec_bytestream_deinit(&bs);

    return type;    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_get_type_from_file
 * DESCRIPTION
 *  Gets image type from file.
 * PARAMETERS
 *  filename       [IN] filename
 * RETURNS
 *  Image type.
 *****************************************************************************/
U8 gdi_imgdec_get_type_from_file(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        return GDI_IMAGE_TYPE_INVALID;
    }

    return gdi_imgdec_get_type((U8*)filename, 0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_timeout_handler
 * DESCRIPTION
 *  Time out handler of IMGDEC
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_timeout_handler(void *param)
{
    g_imgdec_timer_timeout_flag = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_draw_internal
 * DESCRIPTION
 *  IMGDEC main draw function
 * PARAMETERS
 *  output_layer       [IN] output layer handle
 *  source_layer       [IN] source layer handle
 *  src_type           [IN] image source type
 *  img_src            [IN] image pointer
 *  img_size           [IN] image size 
 *  x                  [IN] x
 *  y                  [IN] y
 *  width              [IN] resized width
 *  height             [IN] resized height
 *  is_aborted         [IN] is aborted flag, used by nonblocking decoding
 *  flag               [IN] flag
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_draw_internal(
            gdi_handle output_layer,
            gdi_handle source_layer,
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,            
            S32 img_size,
            S32 x,
            S32 y,
            U32 resize_width,
            U32 resize_height,
            U32 frame_pos,
            BOOL *is_aborted,
            U32 flag,
            U32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;   
    U8 image_type = GDI_IMAGE_TYPE_INVALID;
    U32 image_size = 0;
    S32 start_time = 0, decode_ms = 0;
    gdi_layer_struct *layer_struct = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRACE(GDC_TRC, GDI_IMGDEC_ENTER,//[gdi_imgdec_draw_internal]: Enter - src_type:%d x:%d y:%d w:%d h:%d
        src_type, x, y, resize_width, resize_height);

    GDI_ASSERT(output_layer != NULL);
    layer_struct = (gdi_layer_struct*)output_layer;
    if ((x > layer_struct->clipx2) || (y > layer_struct->clipy2))
    {
        GDI_TRACE(GDC_TRC, GDI_IMGDEC_LEAVE,//[gdi_imgdec_draw_internal]: Leave - ret:%d decode_ms:%d
        0, 0);
        return GDI_SUCCEED;
    }

    if (flag & GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT)
    {
        /* App need give  */
        if (resize_width == 0 || resize_height == 0)
        {
            flag &= ~GDI_IMAGE_CODEC_FLAG_ADJUST_ASPECT;
        }
    }

    if (src_type == GDI_IMAGE_SRC_FROM_RESOURCE)
    {
        image_type = img_src[0];
        image_size = (U32)(img_src[2] | (img_src[3] << 8) | (img_src[4] << 16));
        img_src += 8;
    }
    else if (src_type == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        image_type = img_type;
        image_size = (U32)img_size;
        flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;        
    }
    else if (src_type == GDI_IMAGE_SRC_FROM_FILE)
    {
        image_type = gdi_imgdec_get_type_from_file((S8*)img_src);
        image_size = 0;
        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;        
    }

    flag |= GDI_IMAGE_CODEC_FLAG_IS_IMGDEC;

    GDI_TRACE(GDC_TRC, GDI_IMGDEC_INFO,//[gdi_imgdec_draw_internal]: out_layer:%d src_layer:%d img_type:%d img_size:%d frame_pos:%d flag:%d
        output_layer, source_layer, image_type, img_size, frame_pos, flag);
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
#endif
    start_time = drv_get_current_time();

    g_imgdec_timer_timeout_flag = KAL_FALSE;
    kal_set_timer(
        g_imgdec_timer,
        gdi_imgdec_timeout_handler,
        (void*)0,
        KAL_TICKS_100_MSEC * (GDI_IMGDEC_CODEC_WAITING_TIME / 100),
        0);
    switch (image_type)
    {
        case GDI_IMAGE_TYPE_JPG_FILE:
        case GDI_IMAGE_TYPE_JPG:
            ret = gdi_imgdec_jpeg_draw_internal(output_layer, src_type, (U8*)img_src, image_size, x, y, resize_width, resize_height, is_aborted, flag, aspect_flag);
            break;

        case GDI_IMAGE_TYPE_BMP:
        case GDI_IMAGE_TYPE_BMP_MEM:        
        case GDI_IMAGE_TYPE_BMP_FILE:
            if (image_type == GDI_IMAGE_TYPE_BMP_MEM)
            {
                flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
            }
            ret = gdi_imgdec_bmp_draw_handler(output_layer, 0, x, y, resize_width, resize_height, (U8*)img_src, image_size, is_aborted, flag, aspect_flag);
            break;

        case GDI_IMAGE_TYPE_WBMP:
        case GDI_IMAGE_TYPE_WBMP_FILE:
            ret = gdi_imgdec_wbmp_draw_handler(output_layer, 0, x, y, resize_width, resize_height, (U8*)img_src, image_size, is_aborted, flag, aspect_flag);
            break;
           
        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
            ret = gdi_imgdec_gif_draw_handler(output_layer, frame_pos, x, y, resize_width, resize_height, (U8*)img_src, image_size, is_aborted, flag, aspect_flag);
            break;

        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
        #ifdef GDI_USING_PNG
            ret = gdi_imgdec_png_draw_internal(
                    output_layer,
                    output_layer,
                    x, 
                    y, 
                    resize_width, 
                    resize_height, 
                    (U8*)img_src, 
                    image_size, 
                    (BOOL)(src_type == GDI_IMAGE_SRC_FROM_FILE), 
                    is_aborted,
                    flag,
                    aspect_flag);
        #endif /* GDI_USING_PNG */                
            break;

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
        case GDI_IMAGE_TYPE_MAV_FILE:
        case GDI_IMAGE_TYPE_MAV:
            ret = gdi_imgdec_mav_draw_internal(output_layer, x, y, resize_width, resize_height, frame_pos, (U8*)img_src, image_size, is_aborted, flag, aspect_flag);
            break;
#endif

        default:
            ret = GDI_FAILED;
            break;
    }
    kal_cancel_timer(g_imgdec_timer);
    g_imgdec_timer_timeout_flag = KAL_FALSE;

    decode_ms = drv_get_duration_ms(start_time);
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GDI_DEBUG_MEASURE__)
/* under construction !*/
#endif
    GDI_TRACE(GDC_TRC, GDI_IMGDEC_LEAVE,//[gdi_imgdec_draw_internal]: Leave - ret:%d decode_ms:%d
        ret, decode_ms);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_get_dimension_internal
 * DESCRIPTION
 *  Gets image dimension.
 * PARAMETERS
 *  src_type       [IN] image type
 *  img_src        [IN] image pointer   
 *  img_size       [IN] image size
 *  width          [OUT] width
 *  height         [OUT] height
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_get_dimension_internal(gdi_image_src_enum src_type, U8 *img_src, U8 img_type, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;       
    U32 flag = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_type == GDI_IMAGE_SRC_FROM_RESOURCE)
    {
    	U8 *data_ptr;
    	S32 img_size;
    	S32 frame_number;
    
        gdi_image_parse_resource_internal(img_src, &data_ptr, &img_type, &img_size, &frame_number, width, height);

        ret = GDI_SUCCEED;
    }
    else if ((src_type == GDI_IMAGE_SRC_FROM_FILE) || (src_type == GDI_IMAGE_SRC_FROM_MEMORY))
    {
        flag = GDI_IMAGE_CODEC_FLAG_IS_MEM;
        if (src_type == GDI_IMAGE_SRC_FROM_FILE)
        {
            flag = GDI_IMAGE_CODEC_FLAG_IS_FILE;
            img_type = gdi_imgdec_get_type_from_file((S8*)img_src);
        }            

        switch (img_type)
        {
            case GDI_IMAGE_TYPE_JPG:
            case GDI_IMAGE_TYPE_JPG_FILE:
                ret = gdi_imgdec_jpeg_get_dimension(img_src, img_size, width, height);
                break;
        
            case GDI_IMAGE_TYPE_BMP:
            case GDI_IMAGE_TYPE_BMP_MEM:        
            case GDI_IMAGE_TYPE_BMP_FILE:
                ret = gdi_imgdec_bmp_get_dimension(img_src, img_size, width, height);
                break;

            case GDI_IMAGE_TYPE_GIF:
            case GDI_IMAGE_TYPE_GIF_FILE:
                ret = gdi_imgdec_gif_get_dimension(img_src, img_size, width, height);
                break;

            case GDI_IMAGE_TYPE_PNG:
            case GDI_IMAGE_TYPE_PNG_FILE:
                ret = gdi_imgdec_png_get_dimension(img_src, img_size, width, height);
                break;

            case GDI_IMAGE_TYPE_WBMP:
            case GDI_IMAGE_TYPE_WBMP_FILE:
                ret = gdi_imgdec_wbmp_get_dimension(img_src, img_size, width, height);
                break;

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
            case GDI_IMAGE_TYPE_MAV:
            case GDI_IMAGE_TYPE_MAV_FILE:
                ret = gdi_image_mav_get_dimension_handler(flag, img_src, img_size, width, height);
                break;
#endif

            default:
                break;
        }                  
    }
    else
    {
        GDI_ASSERT(0);
    }

    return ret;
}



