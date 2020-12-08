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
 *   jui_util.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Font adaption APIs
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*************************************************************************
 * Include header files
 *************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "jal.h"
#include "jui_internal.h"
#include "gdi_const.h"
#include "MMI_features.h"
#include "jma_internal.h"
#include "gdi_image_gif.h"
#include "gdi_image_bmp.h"
#include "gdi_image_wbmp.h"
#include "mmu.h"
#include "cp15.h"
#include "cache_sw.h"



extern unsigned int j2me_get_transparent_color_key(void);


/*****************************************************************************
 * FUNCTION
 *  jui_util_msg_handler
 * DESCRIPTION
 *  handle incoming messages for jui
 * PARAMETERS
 *  ilm_ptr     [IN]        Incoming message
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jui_util_msg_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
       //// case MSG_ID_MMI_JAVA_UI_JAVA_STATUS_ICON_UPDATE_REQ:
       ////     jui_widget_update_fullscreen_status_icons(NULL);
       ////     break;

        default:
            return KAL_FALSE;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jui_set_device_bmp_header
 * DESCRIPTION
 *  set header of image device bmp format
 * PARAMETERS
 *  kal_int32 pixel_size
 *  kal_int32 width
 *  kal_int32 height
 *  kal_char* icon_mmi_fmt
 * RETURNS
 *  kal_in32  the size of the image device bmp header.
 *****************************************************************************/
kal_int32 jui_set_device_bmp_header(kal_int32 pixel_size, kal_int32 width, kal_int32 height, kal_char* icon_mmi_fmt)
{
    kal_int32 header_size = 0;
    icon_mmi_fmt[0] = GDI_IMAGE_TYPE_DEVICE_BITMAP;
    icon_mmi_fmt[1] = 1;

    /* total size */
    icon_mmi_fmt[2] = ((pixel_size << 1) + 13) & 0xff;
    icon_mmi_fmt[3] = (((pixel_size << 1) + 13) >> 8) & 0xff;
    icon_mmi_fmt[4] = (((pixel_size << 1) + 13) >> 16) & 0xff;

    /* width, height */
    icon_mmi_fmt[5] = width & 0xff;
    icon_mmi_fmt[6] = ((width & 0xf00) >> 8) + ((height & 0xf) << 4);
    icon_mmi_fmt[7] = (height >> 4) & 0xff;


    gdi_image_device_bmp_write_header((kal_uint8*)icon_mmi_fmt+8,(kal_int8*)&header_size,GDI_COLOR_FORMAT_16,width,height);
    return (8 + header_size);
}

/*****************************************************************************
 * FUNCTION
 *  jui_mvm_decode_jpeg_image
 * DESCRIPTION
 *  The API is used to decode a JPEG image data.
 * PARAMETERS
 *  buffer                  [IN]        The JPEG raw data to be decoded
 *  length                  [IN]        The length of the raw data in buffer
 *  get_image               [IN]        The function pointer to get a new Java 
 *                                       image for drawing JPEG decoded image (must be 565 format).
 *  errThrowClassName       [OUT]       The class name to be thrown to Java level. If the pointer 
 *                                       of the variable is modified as non-NULL pointer, it represents error.
 * RETURNS
 *  Return a non-NULL the image buffer if the decoding is successful. 
 *  Return NULL if decoding is failed.
 *****************************************************************************/
kal_char*
jui_mvm_decode_jpeg_image(
    kal_char *buffer,
    kal_int32 length,
    kal_int32(*get_image) (kal_int32 width, kal_int32 height, kal_char **dst),
    kal_char **errThrowClassName,kal_int32 display_id)
{
#if defined(GDI_USING_HW_JPEG) || defined(GDI_USING_HW_JPEG_V2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 width, height;
    kal_char *dst = NULL;
    kal_int32 orgwidth, orgheight;
    kal_char *tempBuffer;
#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) ||defined(__MMI_CAMCORDER__))
    kal_bool is_pause_camera = KAL_FALSE;
#endif
    kal_char *srcBuffer;
    kal_char *dstBuffer;
    kal_int32 i = 0;
         
    kal_uint32 *invalidPtr;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 /*add for 128+32*/
//#if defined( J2ME_SHARE_MED_EXT_MEM )
//	*errThrowClassName = "java/lang/IllegalArgumentException";
//	return NULL;
//#endif 
/*add for 128+32*/
 
#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))
    /* Stop camera preview */
    if (jma_media_enable[display_id] && 
        video_player[display_id].device_type == JAVA_MEDIA_CAM_PLAYER_DEVICE &&
        video_player[display_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        jma_cam_player_preview_stop_keep_layer(display_id);
        is_pause_camera = KAL_TRUE;        
    }
#endif

#if DATACACHE_FBBR_ON
    /* this function is only workable when DATACACHE_FBBR_ON is 1 */
    buffer = (char*)FBBR_invalid_l1_cache(buffer, length);
#endif /* DATACACHE_FBBR_ON */ 

	*errThrowClassName = NULL;
	
    j2me_lcd_mutex_lock();
    gdi_image_jpeg_get_dimension((U8*) buffer, length, (S32*) & width, (S32*) & height);
    if (width <= 0 || height <= 0)
    {
        *errThrowClassName = "java/lang/IllegalArgumentException";
        j2me_lcd_mutex_unlock();        
    
    #if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))
    
        /* Resume camera preview */
        if (is_pause_camera)
        {
            jma_mvm_cam_player_preview_start(display_id, MMA_TYPE_CAM, video_player[display_id].id);   
        }
    #endif    
        return NULL;
    }
    orgwidth = width;
    orgheight = height;
    tempBuffer = jvm_malloc(width * height * 2 + 32);

    if (tempBuffer == NULL)
    {
    	//add for 128+32
#ifndef SUPPORT_JSR_135_VIDEO
    //	kal_prompt_trace(MOD_J2ME,"[decode jpg]throw illegalArgumentException");
	*errThrowClassName = "java/lang/IllegalArgumentException";
#else
	//	  kal_prompt_trace(MOD_J2ME,"[decode jpg]throw out of memeory error");
        *errThrowClassName = "java/lang/OutOfMemoryError";
#endif    
      //add for 128+32 end
        j2me_lcd_mutex_unlock();
    
    #if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))
        /* Resume camera preview */
        if (is_pause_camera)
        {
            jma_mvm_cam_player_preview_start(display_id, MMA_TYPE_CAM, video_player[display_id].id);   
        }
    #endif    
        return NULL;
    }
    invalidPtr = (kal_uint32*) tempBuffer;
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)   
    invalidPtr = jvm_l1_cache_invalidate_and_clean_region(tempBuffer, (width * height * 2 + 32), KAL_TRUE, KAL_TRUE, 1);     
#endif
    if (gdi_image_jpeg_draw_to_buffer(
            orgwidth,
            orgheight,
            (U8*) buffer,
            length,
            (U8*) invalidPtr,
            (S32) (width * height * 2),
            (S32*) & width) != GDI_JPEG_SUCCEED)
    {
        jvm_free(tempBuffer);
        *errThrowClassName = "java/lang/IllegalArgumentException";
        j2me_lcd_mutex_unlock();
        /* Resume camera preview */    
    #if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))
        if (is_pause_camera)
        {
            jma_mvm_cam_player_preview_start(display_id, MMA_TYPE_CAM, video_player[display_id].id);   
        }
    #endif
        return NULL;
    }

    j2me_lcd_mutex_unlock();

    if (get_image(orgwidth, orgheight, &dst) < 0)
    {
        jvm_free(tempBuffer);
        *errThrowClassName = "java/lang/OutOfMemoryError";    
    #if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))
        /* Resume camera preview */
        if (is_pause_camera)
        {
            jma_mvm_cam_player_preview_start(display_id, MMA_TYPE_CAM, video_player[display_id].id);   
        }
    #endif
        return NULL;
    }
    srcBuffer = (kal_char *)invalidPtr;
    dstBuffer = (char*)dst;

    for (i = 0; i < orgheight; i++)
    {
        memcpy(dstBuffer, srcBuffer, orgwidth << 1);
        srcBuffer += width << 1;
        dstBuffer += orgwidth << 1;
    }

    jvm_free(tempBuffer);
    
#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))

    if (is_pause_camera)
    {
        jma_mvm_cam_player_preview_start(display_id, MMA_TYPE_CAM, video_player[display_id].id);   
    }
#endif   
    return dst;
#else /* defined(GDI_USING_HW_JPEG) || defined(GDI_USING_HW_JPEG_V2) */ 
    *errThrowClassName = "java/lang/IllegalArgumentException";
    return NULL;
#endif /* defined(GDI_USING_HW_JPEG) || defined(GDI_USING_HW_JPEG_V2) */ 
}

/*****************************************************************************
 * FUNCTION
 *  jui_decode_jpeg_image
 * DESCRIPTION
 *  The API is used to decode a JPEG image data.
 * PARAMETERS
 *  buffer                  [IN]        The JPEG raw data to be decoded
 *  length                  [IN]        The length of the raw data in buffer
 *  get_image               [IN]        The function pointer to get a new Java 
 *                                       image for drawing JPEG decoded image (must be 565 format).
 *  errThrowClassName       [OUT]       The class name to be thrown to Java level. If the pointer 
 *                                       of the variable is modified as non-NULL pointer, it represents error.
 * RETURNS
 *  Return a non-NULL the image buffer if the decoding is successful. 
 *  Return NULL if decoding is failed.
 *****************************************************************************/
kal_char*
jui_decode_jpeg_image(
    kal_char *buffer,
    kal_int32 length,
    kal_int32(*get_image) (kal_int32 width, kal_int32 height, kal_char **dst),
    kal_char **errThrowClassName)
{
    return jui_mvm_decode_jpeg_image(buffer,length,get_image,errThrowClassName,JUI_WIDGET_DEFAULT_DISPLAY_ID);
}

/*****************************************************************************
 * FUNCTION
 *  jui_decode_gif_image
 * DESCRIPTION
 *  The API is used to decode a GIF image data.
 * PARAMETERS
 *  buffer                  [IN]        The JPEG raw data to be decoded
 *  length                  [IN]        The length of the raw data in buffer
 *  is_transparent          [OUT]       The function pointer to get a new Java image for 
 *                                       drawing GIF decoded image (must be 565 format).
 *  get_image               [IN]        The function pointer to get a new Java 
 *                                       image for drawing JPEG decoded image (must be 565 format).
 *  errThrowClassName       [OUT]       The class name to be thrown to Java level. If the pointer 
 *                                       of the variable is modified as non-NULL pointer, it represents error.
 * RETURNS
 *  Return a non-NULL the image buffer if the decoding is successful. 
 *  Return NULL if decoding is failed.
 *  
 *****************************************************************************/
kal_char*
jui_decode_gif_image(
    char *buffer,
    int length,
    kal_bool *is_transparent,
    kal_int32(*get_image) (kal_int32 width, kal_int32 height, kal_char **dst),
    char **errThrowClassName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int width, height;
    GDI_RESULT gdi_result;
    gdi_handle gif_handle;
    char *dst = NULL;
    kal_bool use_sw_gif_decoder = KAL_FALSE;
    kal_uint32 *invalidPtr;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *is_transparent = KAL_FALSE;
    *errThrowClassName = NULL;
 #if defined(__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
 #endif /*__MMI_EM_MISC_JUI_DEBUG__*/
 
    /* errorMsg = NULL; */
#if DATACACHE_FBBR_ON
    /* this function is only workable when DATACACHE_FBBR_ON is 1 */
    buffer = (char*)FBBR_invalid_l1_cache(buffer, length);
#endif /* DATACACHE_FBBR_ON */ 
    j2me_lcd_mutex_lock();
    gdi_image_gif_get_dimension((unsigned char*)buffer, (S32*) & width, (S32*) & height);

    if (width <= 0 || height <= 0)
    {
        *errThrowClassName = "java/lang/IllegalArgumentException";
        j2me_lcd_mutex_unlock();
        return NULL;
    }

    if (get_image(width, height, &dst) < 0)
    {
        *errThrowClassName = "java/lang/OutOfMemoryError";
        j2me_lcd_mutex_unlock();
        return NULL;
    }
    invalidPtr = (kal_uint32*)dst; 
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)  
    invalidPtr = jvm_l1_cache_invalidate_and_clean_region(dst, (width * height * 2), KAL_TRUE, KAL_TRUE, 0);          
#endif
#if DATACACHE_FBBR_ON
    /* this function is only workable when DATACACHE_FBBR_ON is 1 */
    invalidPtr = (kal_uint32 *)FBBR_invalid_l1_cache_img(dst, 0, 0, width, height, width);
#endif /* DATACACHE_FBBR_ON */ 

    gdi_layer_create_using_outside_memory(
        0,
        0,
        width,
        height,
        &gif_handle,
        (U8*) invalidPtr,
        (S32) (width * height * 2));
    gdi_layer_push_and_set_active(gif_handle);

    if(width > jui_widget_get_display_width() || height > jui_widget_get_display_height())
    {
        gdi_image_codec_set_flag_begin(GDI_IMAGE_CODEC_FLAG_USE_SW_DECODE);
        use_sw_gif_decoder = KAL_TRUE;
    }

    gdi_result = gdi_image_gif_draw_java((U8 *)buffer, length, 0, j2me_get_transparent_color_key(), (BOOL *)is_transparent);

    if(use_sw_gif_decoder)
    {
        gdi_image_codec_set_flag_end();
    }

    gdi_layer_pop_and_restore_active();
    gdi_layer_free(gif_handle);

    j2me_lcd_mutex_unlock();
    if (gdi_result != GDI_GIF_SUCCEED && gdi_result != GDI_GIF_LAST_FRAME)
    {
        *errThrowClassName = "java/lang/IllegalArgumentException";
        return NULL;
    }

    return dst;
}

/*****************************************************************************
 * FUNCTION
 *  jui_decode_bmp_image
 * DESCRIPTION
 *  The API is used to decode a BMP image data.
 * PARAMETERS
 *  buffer                  [IN]        The BMP raw data to be decoded
 *  length                  [IN]        The length of the raw data in buffer
 *  get_image               [IN]        The function pointer to get a new Java 
 *                                       image for drawing BMP decoded image (must be 565 format).
 *  errThrowClassName       [OUT]       The class name to be thrown to Java level. If the pointer 
 *                                       of the variable is modified as non-NULL pointer, it represents error.
 * RETURNS
 *  Return a non-NULL the image buffer if the decoding is successful. 
 *  Return NULL if decoding is failed.
 *  
 *****************************************************************************/
kal_char*
jui_decode_bmp_image(
    char *buffer,
    int length,
    kal_int32(*get_image) (kal_int32 width, kal_int32 height, kal_char **dst),
    char **errThrowClassName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int width, height;
    GDI_RESULT gdi_result;
    gdi_handle gif_handle;
    char *dst = NULL;
    kal_uint32 *invalidPtr;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *errThrowClassName = NULL;
    /* errorMsg = NULL; */
 #if defined(__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
 #endif /*__MMI_EM_MISC_JUI_DEBUG__*/
 
#if DATACACHE_FBBR_ON
    /* this function is only workable when DATACACHE_FBBR_ON is 1 */
    buffer = (char*)FBBR_invalid_l1_cache(buffer, length);
#endif /* DATACACHE_FBBR_ON */ 
    j2me_lcd_mutex_lock();
    gdi_image_bmp_get_dimension((unsigned char*)buffer, (S32*) & width, (S32*) & height);

    if (width <= 0 || height <= 0)
    {
        *errThrowClassName = "java/lang/IllegalArgumentException";
        j2me_lcd_mutex_unlock();
        return NULL;
    }

    if (get_image(width, height, &dst) < 0)
    {
        *errThrowClassName = "java/lang/OutOfMemoryError";
        j2me_lcd_mutex_unlock();
        return NULL;
    }

    invalidPtr = (kal_uint32*)dst; 
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)  
    invalidPtr = jvm_l1_cache_invalidate_and_clean_region(dst, (width * height * 2), KAL_TRUE, KAL_TRUE, 0);                
#endif
#if DATACACHE_FBBR_ON
    /* this function is only workable when DATACACHE_FBBR_ON is 1 */
    invalidPtr = (kal_uint32 *)FBBR_invalid_l1_cache_img(dst, 0, 0, width, height, width);
#endif /* DATACACHE_FBBR_ON */ 

    gdi_layer_create_using_outside_memory(
        0,
        0,
        width,
        height,
        &gif_handle,
        (U8*) invalidPtr,
        (S32) (width * height * 2));
    gdi_layer_push_and_set_active(gif_handle);

    gdi_result = gdi_image_bmp_draw(0, 0, (U8 *)buffer, length);

    gdi_layer_pop_and_restore_active();
    gdi_layer_free(gif_handle);

    j2me_lcd_mutex_unlock();
    if (gdi_result != GDI_GIF_SUCCEED && gdi_result != GDI_GIF_LAST_FRAME)
    {
        *errThrowClassName = "java/lang/IllegalArgumentException";
        return NULL;
    }

    return dst;
}



/*****************************************************************************
 * FUNCTION
 *  jui_decode_wbmp_image
 * DESCRIPTION
 *  The API is used to decode a WBMP image data.
 * PARAMETERS
 *  buffer                  [IN]        The WBMP raw data to be decoded
 *  length                  [IN]        The length of the raw data in buffer
 *  get_image               [IN]        The function pointer to get a new Java 
 *                                       image for drawing WBMP decoded image (must be 565 format).
 *  errThrowClassName       [OUT]       The class name to be thrown to Java level. If the pointer 
 *                                       of the variable is modified as non-NULL pointer, it represents error.
 * RETURNS
 *  Return a non-NULL the image buffer if the decoding is successful. 
 *  Return NULL if decoding is failed.
 *  
 *****************************************************************************/
kal_char*
jui_decode_wbmp_image(
    char *buffer,
    int length,
    kal_int32(*get_image) (kal_int32 width, kal_int32 height, kal_char **dst),
    char **errThrowClassName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int width, height;
    GDI_RESULT gdi_result;
    gdi_handle gif_handle;
    char *dst = NULL;
    kal_uint32 *invalidPtr;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *errThrowClassName = NULL;
    /* errorMsg = NULL; */
 #if defined(__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
 #endif /*__MMI_EM_MISC_JUI_DEBUG__*/
 
#if DATACACHE_FBBR_ON
    /* this function is only workable when DATACACHE_FBBR_ON is 1 */
    buffer = (char*)FBBR_invalid_l1_cache(buffer, length);
#endif /* DATACACHE_FBBR_ON */ 
    j2me_lcd_mutex_lock();
    gdi_image_wbmp_get_dimension((unsigned char*)buffer, (S32*) & width, (S32*) & height);

    if (width <= 0 || height <= 0)
    {
        *errThrowClassName = "java/lang/IllegalArgumentException";
        j2me_lcd_mutex_unlock();
        return NULL;
    }

    if (get_image(width, height, &dst) < 0)
    {
        *errThrowClassName = "java/lang/OutOfMemoryError";
        j2me_lcd_mutex_unlock();
        return NULL;
    }

    invalidPtr = (kal_uint32*)dst; 
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)  
    invalidPtr = jvm_l1_cache_invalidate_and_clean_region(dst, (width * height * 2), KAL_TRUE, KAL_TRUE, 0);          
#endif
#if DATACACHE_FBBR_ON
    /* this function is only workable when DATACACHE_FBBR_ON is 1 */
    invalidPtr = (kal_uint32 *)FBBR_invalid_l1_cache_img(dst, 0, 0, width, height, width);
#endif /* DATACACHE_FBBR_ON */ 

    gdi_layer_create_using_outside_memory(
        0,
        0,
        width,
        height,
        &gif_handle,
        (U8*) invalidPtr,
        (S32) (width * height * 2));
    gdi_layer_push_and_set_active(gif_handle);

    gdi_result = gdi_image_wbmp_draw(0, 0, (U8 *)buffer, length);

    gdi_layer_pop_and_restore_active();
    gdi_layer_free(gif_handle);

    j2me_lcd_mutex_unlock();
    if (gdi_result != GDI_GIF_SUCCEED && gdi_result != GDI_GIF_LAST_FRAME)
    {
        *errThrowClassName = "java/lang/IllegalArgumentException";
        return NULL;
    }

    return dst;
}


