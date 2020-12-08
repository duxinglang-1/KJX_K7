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
 *   jpeg_decode.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Code body of JPEG codec unified interface (decode).
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JPEG_DECODE_INT_H__
#define __JPEG_DECODE_INT_H__

#include "kal_general_types.h"
#include "jpeg_decode_structure.h"
#include "jpeg_enum.h"

/// Common functions.
kal_int32 jpeg_dec_check_handle(JPEG_DECODER_HANDLE handle);
void jpeg_dec_query_working_memory_internal(JPEG_DECODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_dec_set_working_memory_internal(JPEG_DECODER_HANDLE handle);

void jpeg_dec_reset_internal(JPEG_DECODER_HANDLE handle);

kal_int32 jpeg_dec_3bpp_thumbnail(JPEG_DECODER_HANDLE handle);

JPEG_STATUS_ENUM jpeg_dec_internal(JPEG_DECODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_dec_get_decoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_SCENARIO_TYPE_ENUM scenarioType, JPEG_DECODER_HANDLE *handlePtr);
JPEG_STATUS_ENUM jpeg_dec_release_decoder(JPEG_DECODER_HANDLE handle);

/// SW decoder functions.
kal_int32 jpeg_dec_sw_get_mcu_size_bits(kal_uint32 max_sampling_factor);
JPEG_STATUS_ENUM jpeg_dec_post_parsing(JPEG_DECODER_HANDLE handle);

JPEG_STATUS_ENUM jpeg_dec_sw_initialize(JPEG_DECODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_dec_sw_internal(JPEG_DECODER_HANDLE handle);


/// HW decoder functions.
JPEG_STATUS_ENUM jpeg_dec_hw_internal(JPEG_DECODER_HANDLE handle);
JPEG_STATUS_ENUM jpeg_dec_hw_read_data(JPEG_DECODER_HANDLE handle);
void jpeg_dec_hw_config_decoder(JPEG_DECODER_HANDLE handle);
void jpeg_dec_hw_patch_for_HQA00000732(void);
void * jpeg_dec_hw_get_handle(void);
void * jpeg_dec_hw_lock_handle(void);

JPEG_STATUS_ENUM jpeg_dec_hw_hybrid_internal(JPEG_DECODER_HANDLE handle);


#endif
