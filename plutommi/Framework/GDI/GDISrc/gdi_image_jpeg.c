/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_jpeg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Jpeg decoder.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "kal_release.h"
#include "setjmp.h"
#include "string.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fsal.h"
#include "lcd_if.h"

#include "gdi_features.h"
#include "gdi_datatype.h"
#include "gdi_mutex.h"

#include "gdi_internal.h"
#include "med_global.h"
#include "med_utility.h"

/* DRM_REPLACE */
#include "drm_gprot.h"
#include "iul_misc.h"   /* for gdi_image_jpeg_get_encode_process */

#include "gdi_bytestream.h"
#include "gdi_image.h"
#include "gdi_image_jpeg.h"
#include "gdi_lfs.h"
#include "gdi_layer.h"

static kal_bool gdi_jpeg_is_background_mode = KAL_FALSE;

/*
 *  Jpeg (MT6238, MT6268) force to use swjpeg when use_swjpeg is true.
 *  Modify for MT6268 VDO Call(VT). 
 *  MPEG4 and hwjpeg share DCT hw engine.
 *  MT6268 VT would always enalbe MPEG4.
 *  Application can't use hw jpeg in this situation.
 */
#if defined(GDI_USING_HW_JPEG_V2)
static kal_bool gdi_jpeg_force_use_sw_jpeg = KAL_FALSE;
#endif

#ifdef GDI_USING_JPEG

#include "gui.h"        /* for timer */
#include "mmi_frm_gprot.h"

#include "med_api.h"
#include "med_main.h"
#include "med_struct.h"

#ifdef GDI_USING_JPEG_EXIF
#include "exif.h"
#endif

/* markers of JPEG standard */
#define JPEG_MARKER_SOF0      0xC0
#define JPEG_MARKER_SOF1      0xC1
#define JPEG_MARKER_SOF2      0xC2
#define JPEG_MARKER_SOF3      0xC3
#define JPEG_MARKER_SOF15     0xCF
#define JPEG_MARKER_SOS       0xDA
#define JPEG_MARKER_DQT       0xDB
#define JPEG_MARKER_DNL       0xDC
#define JPEG_MARKER_DRI       0xDD
#define JPEG_MARKER_DHP       0xDE
#define JPEG_MARKER_EXP       0xDF
#define JPEG_MARKER_APP0      0xE0
#define JPEG_MARKER_APP15     0xEF
#define JPEG_MARKER_COM       0xFE

#define ROUND16(x)   (((x) + 15)&(~0xf))


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_internal
 * DESCRIPTION
 *  get jpeg dimension inetrnal function
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_image_jpeg_get_dimension_internal(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index, index_offset;
    U16 marker_length;

    U8 jpg_byte1, jpg_byte2, tmp_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = 0;
    jpg_byte1 = gdi_bytestream_get_byte();
    jpg_byte2 = gdi_bytestream_get_byte();

    /* check first two byte to see if is valid jpeg file */
    if ((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD8))
    {

        /* parse bytestream */
        do
        {
            if (gdi_bytestream_is_eof() == TRUE)
            {
                break;
            }

            do
            {
                tmp_byte = gdi_bytestream_get_byte();
            } while (tmp_byte != 0xFF);

            jpg_byte1 = 0xFF;
            jpg_byte2 = gdi_bytestream_get_byte();

            switch (jpg_byte2)
            {
                case JPEG_MARKER_SOF0:
                case JPEG_MARKER_SOF2:

                    marker_length = gdi_bytestream_get_byte() << 8;
                    marker_length |= gdi_bytestream_get_byte();
                    marker_length -= 2;

                    gdi_bytestream_get_byte();  /* precision */
                    *height = gdi_bytestream_get_byte() << 8;
                    *height |= gdi_bytestream_get_byte();
                    *width = gdi_bytestream_get_byte() << 8;
                    *width |= gdi_bytestream_get_byte();

                    /* set terminate byte */
                    jpg_byte2 = 0xD9;

                    break;
                case JPEG_MARKER_SOS:
                    break;
                case 0xC8:
                case 0x00:
                    break;
                default:
                    if ((jpg_byte2 == JPEG_MARKER_SOF1) ||
                        ((jpg_byte2 >= JPEG_MARKER_SOF3) && (jpg_byte2 <= JPEG_MARKER_SOF15)) ||
                        (jpg_byte2 == JPEG_MARKER_DQT) || (jpg_byte2 == JPEG_MARKER_DNL) ||
                        (jpg_byte2 == JPEG_MARKER_DRI) || (jpg_byte2 == JPEG_MARKER_DHP) ||
                        (jpg_byte2 == JPEG_MARKER_EXP) || (jpg_byte2 == JPEG_MARKER_COM) ||
                        ((jpg_byte2 >= JPEG_MARKER_APP0) && (jpg_byte2 <= JPEG_MARKER_APP15)))
                    {
                        index_offset = gdi_bytestream_get_byte() << 8;
                        index_offset |= gdi_bytestream_get_byte();
                        index_offset -= 2;
                        gdi_bytestream_flush(index_offset);
                    }
                    break;
            }

        } while (!((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD9)));

        return GDI_SUCCEED;
    }
    else    /* not valid jpeg file */
    {
        return GDI_IMAGE_ERR_INVALID_IMG_TYPE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension
 * DESCRIPTION
 *  get jpeg dimension, source is from memory
 * PARAMETERS
 *  jpeg_src        [IN]        
 *  size            [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension(U8 *jpeg_src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_imgdec_jpeg_get_dimension(jpeg_src, size, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_file
 * DESCRIPTION
 *  get jpeg dimension, source is from file
 * PARAMETERS
 *  image_name      [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension_file(S8 *image_name, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return gdi_imgdec_jpeg_get_dimension(jpeg_src, 0, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_to_buffer
 * DESCRIPTION
 *  draw resized jpeg
 * PARAMETERS
 *  width                   [IN]        
 *  height                  [IN]        
 *  jpeg_src                [IN]        
 *  size                    [IN]        
 *  buf                     [?]         
 *  buf_size                [IN]        
 *  decoded_image_width     [?]         
 *  oy(?)                   [IN]        
 *  resized_width(?)        [IN]        
 *  resized_height(?)       [IN]        
 *  ox(?)                   [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_src,
            U32 size,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
    GDI_RETURN(gdi_image_jpeg_draw_internal(
                0,0,width,height,
                -1,-1,-1,-1,
                jpeg_src,size,
                FALSE,TRUE,TRUE,
                buf,buf_size,decoded_image_width,GDI_COLOR_FORMAT_16));
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_file_to_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width                   [IN]        
 *  height                  [IN]        
 *  jpeg_file               [?]         
 *  buf                     [?]         
 *  buf_size                [IN]        
 *  decoded_image_width     [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_file_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_file,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
    GDI_RETURN(gdi_image_jpeg_draw_internal(
                0,0,width,height,
                -1,-1,-1,-1,
                jpeg_file,0,
                TRUE,TRUE,TRUE,
                buf,buf_size,decoded_image_width,GDI_COLOR_FORMAT_16));
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_draw_to_buffer)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  output_clipx1           [IN]        
 *  output_clipy1           [IN]        
 *  output_clipx2           [IN]        
 *  output_clipy2           [IN]        
 *  src                     [?]         
 *  size                    [IN]        
 *  is_file                 [IN]        
 *  is_resized              [IN]        
 *  dest_buf                [?]         
 *  dest_buf_size           [IN]        
 *  decoded_image_width     [?]         
 *  dest_buf_cf             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            S32 output_clipx1,
            S32 output_clipy1,
            S32 output_clipx2,
            S32 output_clipy2,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_resized,
            BOOL retry_thumbnail,
            U8 *dest_buf,
            S32 dest_buf_size,
            S32 *decoded_image_width,
            gdi_color_format dest_buf_cf)
{
    GDI_RESULT ret;
    gdi_handle act_layer;
    U32 flag;

    GDI_LOCK;
    
    gdi_layer_get_active(&act_layer);
    flag = gdi_image_codec_get_flag();
    
	ret = gdi_image_hwjpeg_draw_internal(
	        act_layer,
            ox,
            oy,
            resized_width,
            resized_height,
            output_clipx1,
            output_clipy1,
            output_clipx2,
            output_clipy2,
            src,
            size,
            is_file,
            is_resized,
            dest_buf,
            dest_buf_size,
            decoded_image_width,
            dest_buf_cf,
            NULL,
            flag);

    GDI_UNLOCK;

    return ret;            
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_exif_info_internal
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_exif_info_internal(S8 *filename, gdi_image_jpeg_exif_info_struct *info)
{
    GDI_RESULT ret = GDI_FAILED;
    #ifdef GDI_USING_JPEG_EXIF
    
    PU8 buf_p = NULL;
    do
    {
        U32 buffer_size;
        EXIF_DEC_RESULT exif_ret;
        buffer_size = exif_open_jpeg_file((void*)filename);
        if(buffer_size==0) break; // open jpeg fail
        

        buf_p = (void *)gdi_alloc_ext_mem(buffer_size);
        GDI_DEBUG_ASSERT(buf_p != NULL);
        exif_ret = exif_parse_jpeg_file((U8*)buf_p, buffer_size);
        if (exif_ret != EXIF_DEC_DONE) break; // parse jpeg fail

        // start to fetch each field.
        #define FIELD_COPY(_A_,_TAG_NAME_)\
        do                                                              \
        {                                                               \
            S8* tmp_p;                                                  \
            tmp_p=exif_get_tag_value(_TAG_NAME_);                       \
            if(tmp_p!=0)                                                \
               strncpy((S8*)info->_A_,tmp_p,sizeof(info->_A_));         \
            else                                                        \
               strcpy((S8*)info->_A_,"");                               \
        }while(0)
        FIELD_COPY(make, exif_tag_Make);
        FIELD_COPY(model, exif_tag_Model);
        FIELD_COPY(orientation, exif_tag_Orientation);
        FIELD_COPY(x_resolution, exif_tag_XResolution);
        FIELD_COPY(y_resolution, exif_tag_YResolution);
        FIELD_COPY(resolution_unit, exif_tag_ResolutionUnit);
        FIELD_COPY(software, exif_tag_Software);
        FIELD_COPY(date_time, exif_tag_DateTime);
        FIELD_COPY(ycbcr_positioning, exif_tag_YCbCrPositioning);
        FIELD_COPY(exif_ifd, exif_tag_ExifIFD);
        FIELD_COPY(exposure_time, exif_tag_ExposureTime);
        FIELD_COPY(fnumber, exif_tag_FNumber);
        FIELD_COPY(exposure_program, exif_tag_ExposureProgram);
        FIELD_COPY(iso_speed_ratings, exif_tag_ISOSpeedRatings);
        FIELD_COPY(exif_version, exif_tag_ExifVersion);
        FIELD_COPY(date_time_original, exif_tag_DateTimeOriginal);
        FIELD_COPY(date_time_digitized, exif_tag_DateTimeDigitized);
        FIELD_COPY(components_config, exif_tag_ComponentsConfig);
        FIELD_COPY(exposure_bias_value, exif_tag_ExposureBiasValue);
        FIELD_COPY(metering_mode, exif_tag_MeteringMode);
        FIELD_COPY(light_source, exif_tag_LightSource);
        FIELD_COPY(flash, exif_tag_Flash);
        FIELD_COPY(maker_note, exif_tag_MakerNote);
        FIELD_COPY(flashpix_version, exif_tag_FlashpixVersion);
        FIELD_COPY(color_space, exif_tag_ColorSpace);
        FIELD_COPY(pixel_x_dimension, exif_tag_PixelXDimension);
        FIELD_COPY(pixel_y_dimension, exif_tag_PixelYDimension);
        FIELD_COPY(exposure_mode, exif_tag_ExposureMode);
        FIELD_COPY(digital_zoom_ratio, exif_tag_DigitalZoomRatio);
        FIELD_COPY(scene_capture_type, exif_tag_SceneCaptureType);
        #undef FIELD_COPY
        ret = GDI_SUCCEED;
    } while(0);
    
    if (buf_p)
    {
        gdi_free_ext_mem(&buf_p);
    }
    exif_close_jpeg_file();
    #endif
    return ret;
}

#elif defined(GDI_USING_HW_JPEG_V2)

#ifdef GDI_USING_JPEG_EXIF
#include "exif.h"
#endif

/* markers of JPEG standard */
#define JPEG_MARKER_SOF0      0xC0
#define JPEG_MARKER_SOF1      0xC1
#define JPEG_MARKER_SOF2      0xC2
#define JPEG_MARKER_SOF3      0xC3
#define JPEG_MARKER_SOF15     0xCF
#define JPEG_MARKER_SOS       0xDA
#define JPEG_MARKER_DQT       0xDB
#define JPEG_MARKER_DNL       0xDC
#define JPEG_MARKER_DRI       0xDD
#define JPEG_MARKER_DHP       0xDE
#define JPEG_MARKER_EXP       0xDF
#define JPEG_MARKER_APP0      0xE0
#define JPEG_MARKER_APP15     0xEF
#define JPEG_MARKER_COM       0xFE

/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_internal
 * DESCRIPTION
 *  get jpeg dimension inetrnal function
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_image_jpeg_get_dimension_internal(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index_offset;
    U16 marker_length;

    U8 jpg_byte1, jpg_byte2, tmp_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jpg_byte1 = gdi_bytestream_get_byte();
    jpg_byte2 = gdi_bytestream_get_byte();

    /* check first two byte to see if is valid jpeg file */
    if ((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD8))
    {

        /* parse bytestream */
        do
        {
            if (gdi_bytestream_is_eof() == TRUE)
            {
                break;
            }

            do
            {
                tmp_byte = gdi_bytestream_get_byte();
            } while (tmp_byte != 0xFF);

            jpg_byte1 = 0xFF;
            jpg_byte2 = gdi_bytestream_get_byte();

            switch (jpg_byte2)
            {
                case JPEG_MARKER_SOF0:
                case JPEG_MARKER_SOF2:

                    marker_length = gdi_bytestream_get_byte() << 8;
                    marker_length |= gdi_bytestream_get_byte();
                    marker_length -= 2;

                    gdi_bytestream_get_byte();  /* precision */
                    *height = gdi_bytestream_get_byte() << 8;
                    *height |= gdi_bytestream_get_byte();
                    *width = gdi_bytestream_get_byte() << 8;
                    *width |= gdi_bytestream_get_byte();

                    /* set terminate byte */
                    jpg_byte2 = 0xD9;

                    break;
                case JPEG_MARKER_SOS:
                    break;
                case 0xC8:
                case 0x00:
                    break;
                default:
                    if ((jpg_byte2 == JPEG_MARKER_SOF1) ||
                        ((jpg_byte2 >= JPEG_MARKER_SOF3) && (jpg_byte2 <= JPEG_MARKER_SOF15)) ||
                        (jpg_byte2 == JPEG_MARKER_DQT) || (jpg_byte2 == JPEG_MARKER_DNL) ||
                        (jpg_byte2 == JPEG_MARKER_DRI) || (jpg_byte2 == JPEG_MARKER_DHP) ||
                        (jpg_byte2 == JPEG_MARKER_EXP) || (jpg_byte2 == JPEG_MARKER_COM) ||
                        ((jpg_byte2 >= JPEG_MARKER_APP0) && (jpg_byte2 <= JPEG_MARKER_APP15)))
                    {
                        index_offset = gdi_bytestream_get_byte() << 8;
                        index_offset |= gdi_bytestream_get_byte();
                        index_offset -= 2;
                        gdi_bytestream_flush(index_offset);
                    }
                    break;
            }

        } while (!((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD9)));

        return GDI_SUCCEED;
    }
    else    /* not valid jpeg file */
    {
        return GDI_IMAGE_ERR_INVALID_IMG_TYPE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension
 * DESCRIPTION
 *  get jpeg dimension, source is from memory
 * PARAMETERS
 *  jpeg_src        [IN]        
 *  size            [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension(U8 *jpeg_src, U32 size, S32 *width, S32 *height)
{
    return gdi_imgdec_jpeg_get_dimension(jpeg_src, size, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_file
 * DESCRIPTION
 *  get jpeg dimension, source is from file
 * PARAMETERS
 *  image_name      [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension_file(S8 *image_name, S32 *width, S32 *height)
{

    return gdi_imgdec_jpeg_get_dimension((U8*)image_name, 0, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_to_buffer
 * DESCRIPTION
 *  draw resized jpeg
 * PARAMETERS
 *  width                   [IN]        
 *  height                  [IN]        
 *  jpeg_src                [IN]        
 *  size                    [IN]        
 *  buf                     [?]         
 *  buf_size                [IN]        
 *  decoded_image_width     [?]         
 *  oy(?)                   [IN]        
 *  resized_width(?)        [IN]        
 *  resized_height(?)       [IN]        
 *  ox(?)                   [IN]        
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_src,
            U32 size,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_jpeg_draw_internal(
                0,0,width,height,
                -1,-1,-1,-1,
                jpeg_src,size,
                FALSE,TRUE,TRUE,
                buf,buf_size,decoded_image_width,GDI_COLOR_FORMAT_16);                
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  output_clipx1           [IN]        
 *  output_clipy1           [IN]        
 *  output_clipx2           [IN]        
 *  output_clipy2           [IN]        
 *  src                     [?]         
 *  size                    [IN]        
 *  is_file                 [IN]        
 *  is_resized              [IN]        
 *  dest_buf                [?]         
 *  dest_buf_size           [IN]        
 *  decoded_image_width     [?]         
 *  dest_buf_cf             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            S32 output_clipx1,
            S32 output_clipy1,
            S32 output_clipx2,
            S32 output_clipy2,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_resized,
            BOOL retry_thumbnail,
            U8 *dest_buf,
            S32 dest_buf_size,
            S32 *decoded_image_width,
            gdi_color_format dest_buf_cf)
{

    GDI_RESULT ret;
    gdi_handle tmp_layer_hdl = GDI_ERROR_HANDLE;
    
    if (dest_buf != NULL)   // hwjpeg_v2 doesn't support draw to buf, so we use the buf to create layer
    {
        if ((ox != 0) || (oy != 0))
        {
            return GDI_FAILED;
        }
        // Check buffer size is enough to decode image or not 
        GDI_ASSERT(dest_buf_size >= gdi_sizeof_pixels(GDI_COLOR_FORMAT_16, resized_width, resized_height));
        
        ret = gdi_layer_create_cf_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                0, 
                0, 
                resized_width, 
                resized_height, 
                &tmp_layer_hdl, 
                dest_buf, dest_buf_size);
        if (ret != GDI_SUCCEED)
        {
            return ret;
        }
        gdi_layer_push_and_set_active(tmp_layer_hdl);
    }

    {    
        gdi_handle act_layer;
        BOOL source_key_enable;
        gdi_color source_key_value;        
        kal_bool is_force_sw;
        U32 flag;
          
        GDI_LOCK;
        
        gdi_layer_get_active(&act_layer);
        gdi_layer_get_source_key(&source_key_enable, &source_key_value);

        flag = gdi_image_codec_get_flag();

        // TODO: this interface should be removed. Use gdi_image_codec_set_flag_begin/end instead.
        gdi_image_jpeg_get_force_use_swjpeg(&is_force_sw);
        if (is_force_sw)
        {
            flag |= GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE;
        }
        
        ret = gdi_image_hwjpeg_v2_draw_internal(
                act_layer,
                ox,
                oy,
                resized_width,
                resized_height,
                src,
                size,
                is_file,
                is_resized,
                decoded_image_width,
                source_key_enable,
                source_key_value,
                NULL,
                0,
                flag,
                TRUE);
                 
        GDI_UNLOCK;                
    }
    
    if (dest_buf != NULL)
    {
        gdi_layer_free(tmp_layer_hdl);
        gdi_layer_pop_and_restore_active();
    }
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_exif_info_internal
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_exif_info_internal(S8 *filename, gdi_image_jpeg_exif_info_struct *info)
{
    GDI_RESULT ret = GDI_FAILED;
    #ifdef GDI_USING_JPEG_EXIF
    
    PU8 buf_p = NULL;
    do
    {
        U32 buffer_size;
        EXIF_DEC_RESULT exif_ret;
        buffer_size = exif_open_jpeg_file((void*)filename);
        if(buffer_size==0) break; // open jpeg fail
        
        buf_p = (void *)gdi_alloc_ext_mem(buffer_size);
        GDI_DEBUG_ASSERT(buf_p != NULL);
        exif_ret = exif_parse_jpeg_file((U8*)buf_p, buffer_size);
        if (exif_ret != EXIF_DEC_DONE) break; // parse jpeg fail

        // start to fetch each field.
        #define FIELD_COPY(_A_,_TAG_NAME_)\
        do                                                              \
        {                                                               \
            S8* tmp_p;                                                  \
            tmp_p=exif_get_tag_value(_TAG_NAME_);                       \
            if(tmp_p!=0)                                                \
               strncpy((S8*)info->_A_,tmp_p,sizeof(info->_A_));         \
            else                                                        \
               strcpy((S8*)info->_A_,"");                               \
        }while(0)
        FIELD_COPY(make, exif_tag_Make);
        FIELD_COPY(model, exif_tag_Model);
        FIELD_COPY(orientation, exif_tag_Orientation);
        FIELD_COPY(x_resolution, exif_tag_XResolution);
        FIELD_COPY(y_resolution, exif_tag_YResolution);
        FIELD_COPY(resolution_unit, exif_tag_ResolutionUnit);
        FIELD_COPY(software, exif_tag_Software);
        FIELD_COPY(date_time, exif_tag_DateTime);
        FIELD_COPY(ycbcr_positioning, exif_tag_YCbCrPositioning);
        FIELD_COPY(exif_ifd, exif_tag_ExifIFD);
        FIELD_COPY(exposure_time, exif_tag_ExposureTime);
        FIELD_COPY(fnumber, exif_tag_FNumber);
        FIELD_COPY(exposure_program, exif_tag_ExposureProgram);
        FIELD_COPY(iso_speed_ratings, exif_tag_ISOSpeedRatings);
        FIELD_COPY(exif_version, exif_tag_ExifVersion);
        FIELD_COPY(date_time_original, exif_tag_DateTimeOriginal);
        FIELD_COPY(date_time_digitized, exif_tag_DateTimeDigitized);
        FIELD_COPY(components_config, exif_tag_ComponentsConfig);
        FIELD_COPY(exposure_bias_value, exif_tag_ExposureBiasValue);
        FIELD_COPY(metering_mode, exif_tag_MeteringMode);
        FIELD_COPY(light_source, exif_tag_LightSource);
        FIELD_COPY(flash, exif_tag_Flash);
        FIELD_COPY(maker_note, exif_tag_MakerNote);
        FIELD_COPY(flashpix_version, exif_tag_FlashpixVersion);
        FIELD_COPY(color_space, exif_tag_ColorSpace);
        FIELD_COPY(pixel_x_dimension, exif_tag_PixelXDimension);
        FIELD_COPY(pixel_y_dimension, exif_tag_PixelYDimension);
        FIELD_COPY(exposure_mode, exif_tag_ExposureMode);
        FIELD_COPY(digital_zoom_ratio, exif_tag_DigitalZoomRatio);
        FIELD_COPY(scene_capture_type, exif_tag_SceneCaptureType);
        #undef FIELD_COPY
        ret = GDI_SUCCEED;
    } while(0);
    
    if (buf_p)
    {
        gdi_free_ext_mem(&buf_p);
    }
    exif_close_jpeg_file();
    #endif
    return ret;
}

#else /* not support jpeg format */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  output_clipx1           [IN]        
 *  output_clipy1           [IN]        
 *  output_clipx2           [IN]        
 *  output_clipy2           [IN]        
 *  src                     [?]         
 *  size                    [IN]        
 *  is_file                 [IN]        
 *  is_resized              [IN]        
 *  dest_buf                [?]         
 *  dest_buf_size           [IN]        
 *  decoded_image_width     [?]         
 *  dest_buf_cf             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            S32 output_clipx1,
            S32 output_clipy1,
            S32 output_clipx2,
            S32 output_clipy2,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_resized,
            BOOL retry_thumbnail,
            U8 *dest_buf,
            S32 dest_buf_size,
            S32 *decoded_image_width,
            gdi_color_format dest_buf_cf)
{
	return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension(U8 *jpeg_src, U32 size, S32 *width, S32 *height)
{
    return GDI_FAILED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_to_buffer
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_src,
            U32 size,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_file_to_buffer
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_file_to_buffer(
            S32 width,
            S32 height,
            U8 *jpeg_file,
            U8 *buf,
            S32 buf_size,
            S32 *decoded_image_width)
{
    return GDI_FAILED;
}
GDI_RESULT gdi_image_jpeg_get_exif_info_internal(S8 *filename, gdi_image_jpeg_exif_info_struct *info)
{
    return GDI_FAILED;
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_jpeg_file
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_is_jpeg_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buf[3];
    U32 len;
    U32 result;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file(
                 (U16*)file_name,
                 FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED,
                 DRM_PERMISSION_DISPLAY);
    if (handle < 0) return GDI_IMAGE_ERR_INVALID_FILE;

    result = DRM_read_file(handle, buf, 3, &len);

    DRM_close_file(handle);

    if (result == FS_NO_ERROR)
        if (len == 3)
            if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff)
            {
                return GDI_SUCCEED;
            }
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_handler
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    #if defined(GDI_USING_JPEG) || defined(GDI_USING_HW_JPEG_V2)
    //#ifdef GDI_USING_JPEG
    BOOL is_resized;
    is_resized = (w == 0 && h == 0) ? FALSE : TRUE ;
    	
    return gdi_image_jpeg_draw_internal(
            x,
            y,
            w,
            h,
            -1,
            -1,
            -1,
            -1,
            data_ptr,
            img_size,
            TOBOOL(flag & GDI_IMAGE_CODEC_FLAG_IS_FILE),
            is_resized,    //viki
            TRUE,
            NULL,
            0,
            NULL,
            0);
    #else
    return GDI_FAILED;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_handler
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    #if defined(GDI_USING_JPEG) || defined(GDI_USING_HW_JPEG_V2)
        if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
        {
            return gdi_image_jpeg_get_dimension_file((S8*) data_ptr, width, height);
        }
        else
        {
            return gdi_image_jpeg_get_dimension(data_ptr, img_size, width, height);
        }
    #else
        return GDI_FAILED;    
    #endif
}

GDI_RESULT gdi_image_jpeg_get_exif_info(S8 *filename, gdi_image_jpeg_exif_info_struct *info)
{
    #ifdef GDI_USING_JPEG_EXIF
        return gdi_image_jpeg_get_exif_info_internal(filename,info);
    #else
        return GDI_FAILED;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_is_progressive
 * DESCRIPTION
 *  used to see if a jpeg file is a progressive format jpeg
 * PARAMETERS
 *  filename             [IN]   file name
 *  is_progressive       [OUT]  is the file a progressive format jpeg
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_is_progressive(S8 *filename, MMI_BOOL *is_progressive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(GDI_USING_JPEG) || defined(GDI_USING_HW_JPEG_V2)
    STFSAL filehd;
    U32 encode_process;
    U32 buffer_size = 1024;
    PU8 buf_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *is_progressive = MMI_FALSE;
    
    if (!gdi_image_is_jpeg_file((U8*)filename))
    {
        return GDI_SUCCEED;
    }
    
    if (FSAL_Open(&filehd, filename, FSAL_READ) != FSAL_OK )
    {
        return GDI_FAILED;
    }
    
    do
    {
        buf_p = (void *)gdi_alloc_ext_mem(buffer_size);
        if ((buf_p == NULL) && (buffer_size > 0))
        {
            buffer_size = buffer_size / 2;
        }
        else
        {
            break;
        }
    } while(1);
    GDI_DEBUG_ASSERT(buf_p != NULL);
    /*
     * The file MUST be provided with a read buffer using the API FSAL_SetBuffer, 
     * otherwise, an assertion will be invoked.
     */
    FSAL_SetBuffer(&filehd, buffer_size, (kal_uint8*)buf_p);
    
    encode_process = iul_img_get_jpeg_encode_process(&filehd);
    if (encode_process == IUL_JPEG_ENCODE_PROCESS_PROGRESSIVE)
    {
        *is_progressive = MMI_TRUE;
    }
    
    if (buf_p)
    {
        gdi_free_ext_mem(&buf_p);
    }
    FSAL_Close(&filehd);
    return GDI_SUCCEED;
    
#else
    return GDI_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_set_background_mode
 * DESCRIPTION
 *  set background mode value
 *  Jpeg (MT6228, MT6229, MT6230) won't use TCM when it's in background mode.
 * PARAMETERS
 *  filename       : [IN]     background mode
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_set_background_mode(kal_bool is_background_mode)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_set_background_mode)

    gdi_jpeg_is_background_mode = is_background_mode;

    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_set_background_mode)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_background_mode
 * DESCRIPTION
 *  get background mode value
 * PARAMETERS
 *  is_background_mode  : [OUT]    return the background mode value
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_background_mode(kal_bool *is_background_mode)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_get_background_mode)
        
    *is_background_mode = gdi_jpeg_is_background_mode;

    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_get_background_mode)
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_set_force_use_swjpeg
 * DESCRIPTION
 *  Jpeg (MT6238, MT6268) force to use swjpeg when use_swjpeg is true.
 *  Modify for MT6268 VDO Call(VT). 
 *  MPEG4 and hwjpeg share DCT hw engine.
 *  MT6268 VT would always enalbe MPEG4.
 *  Application can't use hw jpeg in this situation.
 * PARAMETERS
 *  use_swjpeg      :[IN]     force to use swjpeg when use_swjpeg is true
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_set_force_use_swjpeg(kal_bool use_swjpeg)
{
#if defined(GDI_USING_HW_JPEG_V2)
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_set_force_use_swjpeg)
    gdi_jpeg_force_use_sw_jpeg = use_swjpeg;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_set_force_use_swjpeg)
    return GDI_SUCCEED;
#else
    return GDI_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_force_use_swjpeg
 * DESCRIPTION
 *  get background mode value
 * PARAMETERS
 *  use_swjpeg      : [OUT]    return the gdi_jpeg_force_use_sw_jpeg
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_force_use_swjpeg(kal_bool *use_swjpeg)
{
#if defined(GDI_USING_HW_JPEG_V2)
    GDI_ENTER_CRITICAL_SECTION(gdi_image_jpeg_get_force_use_swjpeg)
    if (use_swjpeg)
    {
        *use_swjpeg = gdi_jpeg_force_use_sw_jpeg;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_jpeg_get_force_use_swjpeg)
    return GDI_SUCCEED;
#else
    if (use_swjpeg)
    {
        *use_swjpeg = KAL_FALSE;
    }
    return GDI_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_jpeg_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  output_layer         [IN]
 *  src_type             [IN]
 *  src                  [IN]
 *  x                    [IN]
 *  y                    [IN]
 *  resized_width        [IN]
 *  resized_height       [IN]
 *  is_aborted           [IN]
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_imgdec_jpeg_draw_internal(gdi_handle output_layer, gdi_image_src_enum src_type, U8 *src, U32 size, S32 x, S32 y, S32 resized_width, S32 resized_height, BOOL *is_aborted, U32 flag, S32 aspect_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    BOOL is_resized;

    gdi_layer_struct *out_layer;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (resized_width || resized_height)
    {
        is_resized = TRUE;
    }
    else
    {
        is_resized = FALSE;
    }

    ret = GDI_FAILED;

    out_layer = (gdi_layer_struct*)output_layer;

    // TODO: use less buf to prevent possible dead lock when freeing VRT temp
    flag |= GDI_IMAGE_CODEC_FLAG_IS_IMGDEC | GDI_IMAGE_CODEC_FLAG_USE_LESS_BUF;

#ifdef GDI_USING_HW_JPEG_V2
    ret = gdi_image_hwjpeg_v2_draw_internal(
            output_layer,
            x,
            y,
            resized_width,
            resized_height,
            src,
            size,
            (BOOL)(src_type == GDI_IMAGE_SRC_FROM_FILE),
            is_resized,
            NULL,
            gdi_layer_info[out_layer->id].source_key_enable,
            gdi_layer_info[out_layer->id].source_key,
            is_aborted,
            flag,
            aspect_flag,
            TRUE);
#elif defined(GDI_USING_JPEG)
    ret = gdi_image_hwjpeg_draw_internal(
            output_layer,
            x,
            y,
            resized_width,
            resized_height,
            -1,
            -1,
            -1,
            -1,
            src,
            size,
            (BOOL)(src_type == GDI_IMAGE_SRC_FROM_FILE),
            is_resized,
            NULL,
            0,
            NULL,
            0,         
            is_aborted,            
            flag);
#endif

    return ret;         
}


#include "gdi_imgdec_bytestream.h"

/* markers of JPEG standard */

#define JPEG_MARKER_SOF0      0xC0
#define JPEG_MARKER_SOF1      0xC1
#define JPEG_MARKER_SOF2      0xC2
#define JPEG_MARKER_SOF3      0xC3
#define JPEG_MARKER_SOF15     0xCF
#define JPEG_MARKER_SOS       0xDA
#define JPEG_MARKER_DQT       0xDB
#define JPEG_MARKER_DNL       0xDC
#define JPEG_MARKER_DRI       0xDD
#define JPEG_MARKER_DHP       0xDE
#define JPEG_MARKER_EXP       0xDF
#define JPEG_MARKER_APP0      0xE0
#define JPEG_MARKER_APP15     0xEF
#define JPEG_MARKER_COM       0xFE

/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_jpeg_get_dimension
 * DESCRIPTION
 *  Gets JPG dimension.
 * PARAMETERS
 *  src          [IN]   image source pointer
 *  size         [IN]   image size
 *  width        [OUT]  width
 *  height       [OUT]  height
 * RETURNS
 *  Error code.
 *****************************************************************************/
GDI_RESULT gdi_imgdec_jpeg_get_dimension(U8 *src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef GDI_USING_HW_JPEG_V2
    gdi_imgdec_bytestream_struct bs;
    GDI_RESULT ret = GDI_FAILED;
    
    U32 index_offset;
    U16 marker_length;
    U8 jpg_byte1, jpg_byte2, tmp_byte;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width)
    {
        *width = 0;
    }

    if (height)
    {
        *height = 0;
    }

    ret = gdi_imgdec_bytestream_init(&bs, src, size);

    ret = gdi_imgdec_bytestream_read(&bs, &jpg_byte1, 1);
    ret = gdi_imgdec_bytestream_read(&bs, &jpg_byte2, 1);
    if (ret != GDI_SUCCEED)
    {
        gdi_imgdec_bytestream_deinit(&bs);
        return GDI_FAILED;
    }

    /* check first two byte to see if is valid jpeg file */
    if ((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD8))
    {
        /* parse bytestream */
        do
        {
            do
            {                
                if ((ret != GDI_SUCCEED) || (gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1) != GDI_SUCCEED))
                {
                    gdi_imgdec_bytestream_deinit(&bs);

                    return GDI_FAILED;
                }
            } while (tmp_byte != 0xFF);

            jpg_byte1 = 0xFF;
            ret = gdi_imgdec_bytestream_read(&bs, &jpg_byte2, 1);

            switch (jpg_byte2)
            {
                case JPEG_MARKER_SOF0:
                case JPEG_MARKER_SOF2:
                    ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                    marker_length = tmp_byte << 8;
                    ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                    marker_length |= tmp_byte;
                    marker_length -= 2;

                    /* precision */
                    ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);

                    ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                    *height = tmp_byte << 8;
                    ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                    *height |= tmp_byte;
                    ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                    *width = tmp_byte << 8;
                    ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                    *width |= tmp_byte;

                    /* set terminate byte */
                    jpg_byte2 = 0xD9;

                    break;
                case JPEG_MARKER_SOS:
                    break;
                case 0xC8:
                case 0x00:
                    break;
                default:
                    if ((jpg_byte2 == JPEG_MARKER_SOF1) ||
                        ((jpg_byte2 >= JPEG_MARKER_SOF3) && (jpg_byte2 <= JPEG_MARKER_SOF15)) ||
                        (jpg_byte2 == JPEG_MARKER_DQT) || (jpg_byte2 == JPEG_MARKER_DNL) ||
                        (jpg_byte2 == JPEG_MARKER_DRI) || (jpg_byte2 == JPEG_MARKER_DHP) ||
                        (jpg_byte2 == JPEG_MARKER_EXP) || (jpg_byte2 == JPEG_MARKER_COM) ||
                        ((jpg_byte2 >= JPEG_MARKER_APP0) && (jpg_byte2 <= JPEG_MARKER_APP15)))
                    {
                        ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                        index_offset = tmp_byte << 8;
                        ret = gdi_imgdec_bytestream_read(&bs, &tmp_byte, 1);
                        index_offset |= tmp_byte;                    

                        index_offset -= 2;
                        ret = gdi_imgdec_bytestream_seek(&bs, index_offset);
                    }
                    break;
            }

        } while (!((jpg_byte1 == 0xFF) && (jpg_byte2 == 0xD9)));

        ret = GDI_SUCCEED;
    }

    gdi_imgdec_bytestream_deinit(&bs);

    return ret;
#else
    return gdi_jpeg_get_dimension_internal(src, size, width, height, TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_draw_no_rotate_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  src                     [IN]         
 *  size                    [IN]        
 *  is_file                 [IN]        
 *  is_resized              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_draw_no_rotate_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_resized)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_layer;
    BOOL source_key_enable;
    gdi_color source_key_value;        
    kal_bool is_force_sw;
    U32 flag;
    GDI_RESULT ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_HW_JPEG_V2

    GDI_LOCK;

    gdi_layer_get_active(&act_layer);
    gdi_layer_get_source_key(&source_key_enable, &source_key_value);

    flag = gdi_image_codec_get_flag();

    // TODO: this interface should be removed. Use gdi_image_codec_set_flag_begin/end instead.
    gdi_image_jpeg_get_force_use_swjpeg(&is_force_sw);
    if (is_force_sw)
    {
        flag |= GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE;
    }

    ret = gdi_image_hwjpeg_v2_draw_internal(
            act_layer,
            ox,
            oy,
            resized_width,
            resized_height,
            src,
            size,
            is_file,
            is_resized,
            NULL,
            source_key_enable,
            source_key_value,
            NULL,
            flag,
            0,
            FALSE);

    GDI_UNLOCK;
#endif /* GDI_USING_HW_JPEG_V2 */

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_jpeg_get_dimension_no_rotate
 * DESCRIPTION
 *  get the JPEG information without rotation info
 * PARAMETERS
 *  src                     [IN]        
 *  size                    [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_jpeg_get_dimension_no_rotate(U8 *src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_HW_JPEG_V2
    ret = gdi_jpeg_get_dimension_internal(src, size, width, height, FALSE);
#endif /* GDI_USING_HW_JPEG_V2 */

    return ret;
}

