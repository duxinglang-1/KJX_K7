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
 *  gdi_trc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI catcher log 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_TRC_H_
#define _GDI_TRC_H_

#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "gdi_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

BEGIN_TRACE_MAP(MOD_GDI)

    /* GDI */
    TRC_MSG(GDI_TRC_PRINT_LR_VALUE, "[GDI] Caller Address: 0x%x")
    
    TRC_MSG(GDI_TRC_1,"******* gdi_image_codec_draw PRE type=%d src=%x size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d")
    TRC_MSG(GDI_TRC_2,"gdi_image_codec_draw image type=%d src=%x size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d")
    TRC_MSG(GDI_TRC_3,"------- decode time=%d delay time=%d ret=%d")
    TRC_MSG(GDI_TRC_5,"gdi_image_gif_draw(hw) src=%x,size=%d,x=%d,y=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_6,"gdi_image_gif_draw(sw) src=%x,size=%d,x=%d,y=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_7,"gdi_image_gif_draw_resized(hw) src=%x,size=%d,x=%d,y=%d,rw=%d,rh=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_8,"gdi_image_gif_draw_resized(sw) src=%x,size=%d,x=%d,y=%d,rw=%d,rh=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_9,"gdi_image_gif_draw_with_background_color(hw) src=%x,size=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_10,"gdi_image_gif_draw_with_background_color(sw) src=%x,size=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_11,"gdi_image_gif_draw_file(hw) id=%x,x=%d,y=%d,frame_number=%d cached_by_hw=%d ret=%d")
    TRC_MSG(GDI_TRC_12,"gdi_image_gif_draw_file(sw) id=%x,x=%d,y=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_13,"gdi_image_gif_draw_resized_file(sw) id=%x,x=%d,y=%d,rw=%d,rh=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_14,"sw disposal method: restore background(%d,%d)-(%d,%d) clip=(%d,%d)-(%d,%d) color=%x")
    TRC_MSG(GDI_TRC_15,"GDI_HW_JPG set_ext_memory size=%d")
    TRC_MSG(GDI_TRC_16,"GDI_HW_JPG set_source_image file mem_size=%d")
    TRC_MSG(GDI_TRC_17,"try gdi_image_hwjpeg_enlarge_file_buffer ")
    TRC_MSG(GDI_TRC_18,"gdi_image_hwjpeg_enlarge_file_buffer size=%d")
    TRC_MSG(GDI_TRC_19,"---- GDI_HW_JPG INIT BEGIN----")
    TRC_MSG(GDI_TRC_20,"---- GDI_HW_JPG INIT END ret=%d----")
    TRC_MSG(GDI_TRC_21,"gdi_image_hwjpeg_msg_handler cause=%d")
    TRC_MSG(GDI_TRC_22,"---- GDI_HW_JPG decode BEGIN ----")
    TRC_MSG(GDI_TRC_23,"jpeg_decode_process cause=%d")
    TRC_MSG(GDI_TRC_24,"---- GDI_HW_JPG decode END ----")
    TRC_MSG(GDI_TRC_25,"[%d] LAYER[%x] %x cf=%x (%d,%d) wh(%d,%d) size=%d ptr=%x ptr1=%x R%d")
    TRC_MSG(GDI_TRC_26,"-- GDI free lazy layer --")
    TRC_MSG(GDI_TRC_30,"GDI_RAISE gdi_bytestream_get_byte_mem %d/%d")
    TRC_MSG(GDI_TRC_31,"GDI_RAISE gdi_bytestream_peek_byte_mem %d/%d")
    TRC_MSG(GDI_TRC_32,"GDI_RAISE gdi_bytestream_peek_byte_n_mem %d/%d")
    TRC_MSG(GDI_TRC_33,"GDI_RAISE gdi_bytestream_get_word_mem %d/%d")
    TRC_MSG(GDI_TRC_34,"GDI_RAISE gdi_bytestream_get_3bytes_mem %d/%d")
    TRC_MSG(GDI_TRC_35,"GDI_RAISE gdi_bytestream_get_dword_mem %d/%d")
    TRC_MSG(GDI_TRC_36,"GDI_RAISE gdi_bytestream_get_array_mem %d/%d")
    TRC_MSG(GDI_TRC_37,"GDI_RAISE gdi_bytestream_flush_mem %d/%d")
    TRC_MSG(GDI_TRC_38,"GDI_RAISE gdi_bytestream_seek_mem %d/%d")
    TRC_MSG(GDI_TRC_39,"GDI_RAISE gdi_bytestream_buffer_load_file %d/%d")
    TRC_MSG(GDI_TRC_40,"GDI_RAISE gdi_bytestream_seek_file %d/%d")
    TRC_MSG(GDI_TRC_41,"GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP")
    TRC_MSG(GDI_TRC_42,"GDI_RAISE GDI_IMAGE_GIF_CODEC %d")
    TRC_MSG(GDI_TRC_43,"GDI_RAISE gdi_image_gif_progress_callback")
    TRC_MSG(GDI_TRC_44,"GDI_RAISE y <= src_clipy2")
    TRC_MSG(GDI_TRC_45,"GIF(sw) hit cache fn=%d, lcd=%d, frame_count = %d, offset = %d")
    TRC_MSG(GDI_TRC_46,"GIF(sw) NOT hit cache background color (%d,%d) =%x")
    TRC_MSG(GDI_TRC_47,"resized width x height = %dx %d")
    TRC_MSG(GDI_TRC_48,"jpeg spatial dithering buffer size = %d")
    TRC_MSG(GDI_TRC_49,"jpeg spatial dithering enable")
    TRC_MSG(GDI_TRC_50,"jpeg spatial dithering disable")
    TRC_MSG(GDI_TRC_51,"jpeg spatial_dithering888_565 [%x -> %x] , (%d,%d)  (%d x %d)")
    TRC_MSG(GDI_TRC_52,"FORCE ABORT!!")
    TRC_MSG(GDI_TRC_53,"gdi_image_codec set timeout = %d seconds")
    TRC_MSG(GDI_TRC_54,"gdi_image_codec clean timeout")
    TRC_MSG(GDI_TRC_55,"FORCE ABORT SUCCEED")
    TRC_MSG(GDI_TRC_56,"gdi_image_set_update_area %d %d %d %d")

    /* GDI-SVG */
    TRC_MSG(GDI_SVG_TRC_SVG_RAISE_ERROR,"[SVG] SVG_RAISE Error %d")
    TRC_MSG(GDI_SVG_TRC_PARSER_ELEMENT,"[SVG] Parser : Valid SVG_PARSER_TABLE element index = %d")
    TRC_MSG(GDI_SVG_TRC_PARSER_ELEMENT_UNKNOWN,"[SVG] Parser : Unknown SVG_PARSER_TABLE element")
    TRC_MSG(GDI_SVG_TRC_PARSER_ELEMENT_UNKNOWN_INDEX,"[SVG] Parser : Unknown SVG_PARSER_TABLE element index = %d")
    TRC_MSG(GDI_SVG_TRC_STACK_OVERFLOW,"[SVG] Stack will overflow.")

    /* GDI Memory */
    TRC_MSG(GDI_MEM_ALLOC_START,    "[GDI][ALLOC] size=%d, from: %s, %d")
    TRC_MSG(GDI_MEM_ALLOC_END,      "[GDI][ALLOC] ptr=%x")
    TRC_MSG(GDI_MEM_ALLOC_FAIL,     "[GDI][ALLOC] alloc fail")
    TRC_MSG(GDI_MEM_FREE,           "[GDI][FREE]  ptr=%x, from: %s, %d")

    TRC_MSG(GDI_GIF_ENTER,"[gdi_imgdec_gif_draw_internal]: Enter - out_layer:%x x:%d y:%d w:%d h:%d src:%x is_file:%d")
    TRC_MSG(GDI_GIF_START,"[gdi_imgdec_gif_draw_internal]: Start - decoder:%d frame:%d status:%d")
    TRC_MSG(GDI_GIF_LEAVE,"[gdi_imgdec_gif_draw_internal]: Leave - ret:%d")
    TRC_MSG(GDI_GIF_HW_TIMEOUT,"[gdi_image_hwgif_timeout_handler]:Time out")
    TRC_MSG(GDI_GIF_HW_MSG,"[gdi_image_hwgif_msg_handler]: gif_state:%d decode_result:%d g_gif_state:%d")
    TRC_MSG(GDI_GIF_DECODE_FAIL,"[gdi_image_gif_fail]: gif_state:%d decode_result:%d decode_type:%d is_file:%d x:%d y:%d w:%d h:%d")

    TRC_MSG(GDI_JPG_ENTER,"[gdi_image_hwjpeg_v2_draw_internal]: Enter - out_layer:%x x:%d y:%d w:%d h:%d src:%x is_file:%d")
    TRC_MSG(GDI_JPG_START,"[gdi_image_hwjpeg_v2_draw_internal]: Start - decoder:%d status:%d")
    TRC_MSG(GDI_JPG_LEAVE,"[gdi_image_hwjpeg_v2_draw_internal]: Leave - ret:%d")
    TRC_MSG(GDI_JPG_CALLBACK,"[gdi_image_hwjpeg_v2_callback]: decoder:%d state:%d")
    TRC_MSG(GDI_JPG_TIMEOUT,"[gdi_image_hwjpeg_v2_timeout_handler]: decoder:%d")
    TRC_MSG(GDI_JPG_HW_MSG,"[gdi_image_hwjpeg_v2_msg_handler]: interrupt_value:%d")
    TRC_MSG(GDI_JPG_DECODE_FAIL,"[gdi_image_jpg_fail]: jpg_state:%d decode_result:%d decode_type:%d is_file:%d x:%d y:%d w:%d h:%d")

    TRC_MSG(GDI_PNG_ENTER,"[gdi_imgdec_png_draw_internal]: Enter - out_layer:%x src_layer:%x x:%d y:%d w:%d h:%d src:%x is_file:%d")
    TRC_MSG(GDI_PNG_START,"[gdi_imgdec_png_draw_internal]: Start - decoder:%d status:%d")
    TRC_MSG(GDI_PNG_LEAVE,"[gdi_imgdec_png_draw_internal]: Leave - ret:%d")
    TRC_MSG(GDI_PNG_HW_TIMEOUT,"[gdi_image_hwpng_timeout_handler]:Time out")
    TRC_MSG(GDI_PNG_HW_MSG,"[gdi_image_hwpng_msg_handler]: g_png_status:%d interrupt_value:%d")
    TRC_MSG(GDI_PNG_DECODE_FAIL,"[gdi_image_png_fail]: png_state:%d decode_result:%d decode_type:%d is_file:%d x:%d y:%d w:%d h:%d")

    TRC_MSG(GDI_ABM_LAYER_PUSH,"[gdi_push_and_set_alpha_blending_source_layer_ext]: File:%s Line:%d stack_index:%d")
    TRC_MSG(GDI_ABM_LAYER_POP,"[gdi_pop_and_restore_alpha_blending_source_layer_ext]: File:%s Line:%d stack_index:%d")
    TRC_MSG(GDI_LAYER_PUSH,"[gdi_layer_push_and_set_active_ext]: File:%s Line:%d stack_index:%d")
    TRC_MSG(GDI_LAYER_POP,"[gdi_layer_pop_and_restore_active]: File:%s Line:%d stack_index:%d")
    TRC_MSG(GDI_CLIP_PUSH,"[gdi_layer_push_clip]: File:%s Line:%d gdi_act_layer->clips_top:%d")
    TRC_MSG(GDI_CLIP_POP,"[gdi_layer_pop_clip]: File:%s Line:%d gdi_act_layer->clips_top:%d")
    TRC_MSG(GDI_FRAME_BUFFER_LOCK,"[gdi_layer_lock_frame_buffer]: File:%s Line:%d GDI_LCD->blt_lock:%d")
    TRC_MSG(GDI_FRAME_BUFFER_UNLOCK,"[gdi_layer_unlock_frame_buffer]: File:%s Line:%d GDI_LCD->blt_lock:%d")

    TRC_MSG(GDI_ENCODE_BUFFER_ENTER,"[gdi_image_encode_buffer_to_jpeg_with_exp_size]: Enter - version:%d buf:%x encode_size:%d")
    TRC_MSG(GDI_ENCODE_BUFFER_FS_OPEN_ERROR,"[gdi_image_encode_buffer_to_jpeg_with_exp_size]: FS open error:%d")
    TRC_MSG(GDI_ENCODE_BUFFER_FS_WRITE_ERROR,"[gdi_image_encode_buffer_to_jpeg_with_exp_size]: FS write error:%d")
    TRC_MSG(GDI_ENCODE_BUFFER_LEAVE,"[gdi_image_encode_buffer_to_jpeg_with_exp_size]: Leave - ret:%d decode_ms:%d encode_size:%d")
    TRC_MSG(GDI_ENCODE_MEM_ENTER,"[gdi_image_encode_buffer_to_jpeg_in_memroy_V2]: Enter - codec_type:%d src-size:%d w:%d h:%d dst-ptr:%x size:%d")
    TRC_MSG(GDI_ENCODE_MEM_LEAVE,"[gdi_image_encode_buffer_to_jpeg_in_memroy_V2]: Leave - ret:%d decode_ms:%d encode_size:%d")
    TRC_MSG(GDI_ENCODE_MEM_START,"[gdi_image_encode_buffer_to_jpeg_in_memroy_V2]: Start - status:%d")

    TRC_MSG(GDI_G2D_LT_ENTER,"[gdi_2d_linear_transfrom]: Enter - src-layer:%x x:%d y:%d w:%d h:%d dst-x:%d y:%d w:%d h:%d")
    TRC_MSG(GDI_G2D_LT_START,"[gdi_2d_linear_transfrom]: Start - type:%d")
    TRC_MSG(GDI_G2D_LT_LEAVE,"[gdi_2d_linear_transfrom]: Leave - ret:%d decode_ms:%d status:%d")
    TRC_MSG(GDI_G2D_LT_HW_FAIL_FORCE_TO_SW, "[GDI][LT] gdi_2d_linear_transfrom: force to sw, g2d_status = %d, #%d")

    TRC_MSG(GDI_G2D_TILT_FONT_ENTER,"[gdi_2d_draw_font_v3]: Enter - dst-layer:%x x:%d y:%d w:%d h:%d is_tilt:%d")
    TRC_MSG(GDI_G2D_TILT_FONT_GET_HANDLE,"[gdi_2d_draw_font_v3]: Get Handle - status:%d")
    TRC_MSG(GDI_G2D_TILT_FONT_LEAVE,"[gdi_2d_draw_font_v3]: Leave - ret:%d")

    TRC_MSG(GDI_G2D_AA_FONT_ENTER,"[gdi_2d_draw_AA_font]: Enter - src-layer:%x dst-layer:%x x:%d y:%d w:%d h:%d")
    TRC_MSG(GDI_G2D_AA_FONT_GET_HANDLE,"[gdi_2d_draw_AA_font]: Get Handle - status:%d")
    TRC_MSG(GDI_G2D_AA_FONT_LEAVE,"[gdi_2d_draw_AA_font]: Leave - ret:%d")

    TRC_MSG(GDI_TRC_LCD_FREEZE,     "[GDI][LCD] gdi_lcd_freeze(%d): Caller Address: 0x%x")
    TRC_MSG(GDI_TRC_LCD_HIGH_PRIORITY_FREEZE, "[GDI][LCD] gdi_lcd_set_high_priority_freeze(%d): Caller Address: 0x%x")
    TRC_MSG(GDI_TRC_LCD_SET_HW_UPDATE, "[GDI][LCD] gdi_lcd_set_hw_update(%d): Caller Address: 0x%x, original_hw_update = %d")
    TRC_MSG(GDI_TRC_LAYER_CREATE,   "[GDI][layer] gdi_layer_create_internal [%d] 0x%x: cf=%x (%d,%d,w%d,h%d) is_double(%d) size=%d ptr=0x%x ptr1=0x%x, lr=0x%x")
    TRC_MSG(GDI_TRC_LAYER_FREE,     "[GDI][layer] gdi_layer_free(0x%x) [%d]")
    TRC_MSG(GDI_TRC_LAYER_LAZY_FREE,"[GDI][layer] gdi_layer_lazy_free(0x%x) [%d]")
    TRC_MSG(GDI_TRC_LAYER_CONFIG_ELEMENT_HW_UPDATE, "[GDI][layer] gdi_layer_config_element(0x%x): hw_updating = %d, hw_update_element = 0x%x")
    TRC_MSG(GDI_TRC_LAYER_CONFIG_ELEMENT, "[GDI][layer] gdi_layer_config_element(0x%x): flag = 0x%x, cf = %d, buf_ptr = 0x%x")
    TRC_MSG(GDI_LAYER_SET_BLT_LAYER, "[GDI][layer] gdi_layer_set_blt_layer_ext_internal(0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x)")
    TRC_MSG(GDI_TRC_LAYER_PUSH_AND_SET_ACTIVE, "[GDI][layer] gdi_layer_push_and_set_active(0x%x): Caller Address: 0x%x , [%d++], %c")
    TRC_MSG(GDI_TRC_LAYER_POP_AND_RESTORE_ACTIVE, "[GDI][layer] gdi_layer_pop_and_restore_active(): Caller Address: 0x%x , stack index-> %d, %c")
    TRC_MSG(GDI_TRC_LAYER_SET_ACTIVE, "[GDI][layer] gdi_layer_set_active(0x%x): Caller Address: 0x%x")
    TRC_MSG(GDI_TRC_LAYER_SET_ABLEND_SOURCE_LAYER, "[GDI][layer] gdi_set_alpha_blending_source_layer(): Caller Address: 0x%x , 0x%x -> 0x%x")
    TRC_MSG(GDI_TRC_LAYER_PUSH_SOURCE_LAYER, "[GDI][layer] gdi_push_and_set_alpha_blending_source_layer(): Caller Address: 0x%x, [%d++] = 0x%x")
    TRC_MSG(GDI_TRC_LAYER_POP_SOURCE_LAYER,  "[GDI][layer] gdi_pop_and_restore_alpha_blending_source_layer(): Caller Address: 0x%x , stack index -> %d, 0x%x popped")
    TRC_MSG(GDI_TRC_LAYER_PUSH_CLIP, "[GDI][layer] gdi_layer_push_clip(), Caller Address: 0x%x, [%d++] = clip")
    TRC_MSG(GDI_TRC_LAYER_POP_CLIP,  "[GDI][layer] gdi_layer_pop_clip(), Caller Address: 0x%x, clip = [%d]")
    TRC_MSG(GDI_TRC_LAYER_LOCK_FRAME_BUFFER, "[GDI][layer] gdi_layer_lock_frame_buffer(), Caller Address: 0x%x, #lock -> %d")
    TRC_MSG(GDI_TRC_LAYER_UNLOCK_FRAME_BUFFER, "[GDI][layer] gdi_layer_unlock_frame_buffer(), Caller Address: 0x%x, #lock -> %d")
    TRC_MSG(GDI_TRC_LAYER_SET_HW_UPDATE_LAYER,  "[GDI][layer] gdi_layer_set_hw_update_layer(0x%x, %d), Caller Address: 0x%x")
    TRC_MSG(GDI_TRC_LAYER_BLT_BUFFER_LOCKED,  "[GDI][layer] gdi_layer_blt_ext_internal(): Frame buffer locked (%d, %d, %d, %d) blt_lock = %d")
    TRC_MSG(GDI_TRC_LAYER_BLT_WITH_FLAG,  "[GDI][layer] gdi_layer_blt_with_flag(flag = 0x%x), Caller Address: 0x%x")
    TRC_MSG(GDI_TRC_LAYER_BLT_PREVIOUS,  "[GDI][layer] gdi_layer_blt_previous(%d, %d, %d, %d), Caller Address: 0x%x")

    TRC_MSG(GDI_LAYER_BLT_ENTER,   "[GDI][layer] gdi_layer_blt_ext_internal(0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, (%d, %d, %d, %d), cb = 0x%x, start = %d)")
    TRC_MSG(GDI_LAYER_BLT_FREEZED, "[GDI][layer] gdi_layer_blt_ext_internal: freeze = %d, high_priority_freeze = %d")
    TRC_MSG(GDI_LAYER_BLT_START,   "[GDI][layer] gdi_layer_blt_ext_internal: compose start, non_block = %d, hw_update = %d, time: %d")
    TRC_MSG(GDI_LAYER_BLT_LEAVE,   "[GDI][layer] gdi_layer_blt_ext_internal: return %d, time: %d")
    
    TRC_MSG(GDI_LAYER_FLATTEN_ENTER, "[GDI][layer] gdi_layer_flatten_ext_internal(0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, (%d, %d, %d, %d), cb = 0x%x, start = %d")
    TRC_MSG(GDI_LAYER_FLATTEN_START, "[GDI][layer] gdi_layer_flatten_ext_internal: compose start time: %d")
    TRC_MSG(GDI_LAYER_FLATTEN_LEAVE, "[GDI][layer] gdi_layer_flatten_ext_internal: return %d, time: %d")
    TRC_MSG(GDI_LAYER_FLATTEN_NB_CALLBACK, "[GDI][layer] gdi_layer_flatten_nb_finish_handler, callback = 0x%x")

    TRC_MSG(GDI_LAYER_BLT_WAIT_BLT_FINISH,   "[GDI][layer] gdi_waiting_blt_finish: duration: %d")
    TRC_MSG(GDI_LAYER_BLT_WAIT_BLT_CALLBACK, "[GDI][layer] gdi_layer_blt_finish_handler: time: %d")

    TRC_MSG(GDI_LAYER_ROTATOR_ENTER,"[gdi_util_rotator]: Enter - type:%d angle:%d Src-cf:%d P:%d H:%d x:%d y:%d w:%d h:%d Dst-cf:%d P:%d H:%d x:%d y:%d w:%d h:%d")
    TRC_MSG(GDI_LAYER_ROTATOR_LEAVE,"[gdi_util_rotator]: Leave - ret:%d duration:%d")
    TRC_MSG(GDI_UTIL_ROTATOR_FAIL, "[GDI][Rotator] gdi_util_rotator: Failed, rotator_status = %d, type = %d, #%d")

    TRC_MSG(GDI_LAYER_RESIZER_ENTER,"[gdi_bitblt_resized_with_resizer_ext_internal]: Enter - mode:%d quality:%d Src-layer:%x x1:%d y1:%d x2:%d y2:%d Dst-x1:%d y1:%d x2:%d y2:%d")
    TRC_MSG(GDI_LAYER_RESIZER_LEAVE,"[gdi_bitblt_resized_with_resizer_ext_internal]: Leave - ret:%d duration:%d")
    TRC_MSG(GDI_UTIL_RESIZER_FAIL,"[GDI][Resizer] gdi_bitblt_resized_with_resizer_ext_internal: Failed, status = %d, #%d")

    TRC_MSG(GDI_IMGDEC_ENTER,"[gdi_imgdec_draw_internal]: Enter - src_type:%d x:%d y:%d w:%d h:%d")
    TRC_MSG(GDI_IMGDEC_INFO,"[gdi_imgdec_draw_internal]: out_layer:%d src_layer:%x img_type:%d img_size:%d frame_pos:%d flag:%d")
    TRC_MSG(GDI_IMGDEC_LEAVE,"[gdi_imgdec_draw_internal]: Leave - ret:%d decode_ms:%d")
    TRC_MSG(GDI_IMGDEC_ABORT,"[gdc_imgdec_delete_job_internal]: Abort")
    
    TRC_MSG(GDI_TRC_57,"CABC set: mode:%d, result: %d")

    TRC_MSG(GDI_TRC_AB2_PALETTE_ALLOC_ERR,"[GDI][AB2_internal]: From %d-bits res, alloc ext mem size:%d FAILED, to cf=%d layer")
    TRC_MSG(GDI_TRC_9SLICE_SOURCE_INFO, "[GDI][9slice]:Source layer image decode failed (due to insufficient memory)")
    TRC_MSG(GDI_TRC_9SLICE_MARGIN_ERROR_1,"[GDI][9slice]:Margin Error1- L:%d T:%d R:%d B:%d Mid_W:%d Mid_H:%d")
    TRC_MSG(GDI_TRC_9SLICE_MARGIN_ERROR_2,"[GDI][9slice]:Margin Error2- L:%d T:%d R:%d B:%d Dest_W:%d Dest_H:%d")
    TRC_MSG(GDI_TRC_9SLICE_MARGIN_INFO,"[GDI][9slice]:Margin Info Img_W:%d Img_H:%d L:%d T:%d R:%d B:%d Dest_W:%d Dest_H:%d")
    TRC_MSG(GDI_TRC_9SLICE_DRAW_ORIGINAL,"[GDI][9slice]:Draw Original Dest_W:%d Dest_H:%d Img_W:%d Img_H:%d L:%d T:%d R:%d B:%d")
    TRC_MSG(GDI_TRC_AB2_ONE_COLOR_PALETTE_ALLOC_ERR,"[GDI][AB2_internal]: From %d-bits res, Color %d, alloc ext mem size:%d FAILED, to cf=%d layer")
    TRC_MSG(GDI_TRC_AB2_ALL_ALPHA_BLENDING_CF_ERR,"[GDI][AB2]All alpha blending Color Format not support. Src_CF=%d, Dst_CF=%d")

    TRC_MSG(GDI_2D_LT_NB_CALLBACK, "[GDI][g2d] gdi_2d_LT_nb_finish_callback")
    TRC_MSG(GDI_2D_LT_NB_WAIT_FOR_PREVIOUS_FINISH, "[GDI][g2d] gdi_2d_LT_nb_wait_for_previous_finish")
    TRC_MSG(GDI_2D_LT_NB_WAIT_FOR_CURRENT_FINISH, "[GDI][g2d] gdi_2d_LT_nb_wait_for_current_finish")
    TRC_MSG(GDI_2D_LT_NB_INIT_STATE, "[GDI][g2d] gdi_2d_LT_nb_init_state")
    TRC_MSG(GDI_2D_LT_NB_RELEASE_G2D_HANDLE, "[GDI][g2d] gdi_2d_LT_nb_release_g2d_handle")
    TRC_MSG(GDI_2D_LT_NB_GET_G2D_HANDLE, "[GDI][g2d] gdi_2d_LT_nb_get_g2d_handle")
    TRC_MSG(GDI_2D_LT_NB_RELEASE_LT_EVENT, "[GDI][g2d] gdi_2d_LT_nb_release_LT_event")
    
    TRC_MSG(GDI_TRC_2D_FILL_RECT_RESULT, "[GDI][g2d] gdi_2d_fill_rect(): g2d_status = %d, ret = %d")
    TRC_MSG(GDI_TRC_2D_FILL_RECT_CALLBACK, "[GDI][g2d] gdi_2d_fill_rect_callback_ind_handler(): callback = 0x%x")

END_TRACE_MAP(MOD_GDI)

BEGIN_TRACE_MAP(MOD_GDC)
END_TRACE_MAP(MOD_GDC)

#endif /* _GDI_TRC_H_ */

