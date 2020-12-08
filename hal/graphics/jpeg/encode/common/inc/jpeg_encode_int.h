/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   jpeg_encode_int.h
 *
 * Project:
 * --------
 *   Maui
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_ENCODE_INT_H__
#define __JPEG_ENCODE_INT_H__

#include "kal_general_types.h"

#include "jpeg_enum.h"
#include "jpeg_enum_int.h"
#include "jpeg_encode_structure.h"

/// jpeg_encode_int.c
kal_uint32 jpeg_enc_jfxx_write_header_3bpp_tn(kal_uint8 *jpegFilePtr, kal_uint32 tnWidth, kal_uint32 tnHeight, void **tnPtr);
kal_int32 jpeg_enc_thumbnail_calc_resolution(JPEG_ENCODER_HANDLE handle, kal_uint32* width, kal_uint32* height);
void jpeg_enc_jfxx_get_total_size(JPEG_ENCODER_HANDLE handle, kal_uint32* size);

void jpeg_enc_hw_get_handle(JPEG_ENCODER_HANDLE *handle);
void jpeg_enc_sw_get_handle(JPEG_ENCODER_HANDLE *handle);
void jpeg_enc_hw_return_cur_handle(JPEG_ENCODER **handle);
kal_int32 jpeg_enc_check_handle(JPEG_ENCODER_HANDLE handle);

JPEG_STATUS_ENUM jpeg_enc_query_working_memory(JPEG_ENCODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_enc_set_working_memory(JPEG_ENCODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_enc_get_encoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_ENCODER_HANDLE *handlePtr);
JPEG_STATUS_ENUM jpeg_enc_release_encoder(JPEG_ENCODER_HANDLE handle);

/// jpeg_encode_int_hw.c
void jpeg_enc_patch_for_HQA00000392(kal_uint8 *jpeg_buffer_head, kal_uint8 *jpeg_buffer_tail);

/// jpeg_encode_int_hw.c
void jpeg_enc_update_app_nine_content(JPEG_APP_NINE_INFO_TYPE_ENUM app_nine_info_type, kal_uint8 *app_nine_ptr, void *app_nine_info);

kal_bool idp_jpeg_encode_open_wrapper(kal_uint32 *key);
kal_bool idp_jpeg_encode_config_wrapper(void *encHandle);
kal_bool idp_dummy_open(kal_uint32 *key);
kal_bool idp_dummy_others(kal_uint32 key);
kal_bool idp_dummy_config(void *handle);

JPEG_STATUS_ENUM jpeg_enc_hw_internal(JPEG_ENCODER_HANDLE handle);

/// jpeg_encode_int_sw.c
JPEG_STATUS_ENUM jpeg_enc_sw_init_gereral(JPEG_ENCODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_enc_sw_write_frame_header(JPEG_ENCODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_enc_sw_write_scan_header(JPEG_ENCODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_enc_sw_internal(JPEG_ENCODER_HANDLE handle);


#endif
