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
 *   mtv_concealment.h
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_CONCEALMENT_H
#define _MTV_CONCEALMENT_H

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#ifndef _MTV_SRC_STAT_H
#include "mtv_src_stat.h"
#endif

#ifndef _MTV_CODEC_H
#include "mtv_codec.h"
#endif

#ifndef L1AUDIO_H
#include "l1audio.h"
#endif

#include "mtv_error.h"
#include "kal_general_types.h"

typedef void (*mtv_deliver_concealment_t)(void* param, mtv_packet_t* au);

/**
  * Deliver audio concealment according source statistics and decoder configuration.
  *
  * @param src_stat [IN] source statistics
  * @param dec_config [IN] decoder configuration
  * @param deliver_concealment [IN] callback function to receive concealment
  * @param param [IN] opaque parameter for callback
  */
extern mtv_result_t mtv_deliver_audio_concealment(
    mtv_source_stat_t* src_stat,
    mtv_dec_config_t* dec_config,
    mtv_deliver_concealment_t deliver_concealment,
    void* param);

/**
  * Helper to fill ADTS header.
  *
  * @param h [IN] pointer to header. the buffer size should be at least LEN_ADTS_HEADER.
  */
extern void mtv_fill_adts_header(kal_uint8* h, kal_uint32 sampling_frequency_index, kal_uint32 channel_configuration, kal_uint32 payload_length);

extern mtv_result_t mtv_get_audio_media_format(mtv_codec_type_t mtv_codec_type, Media_Format *audio_media_format);
extern mtv_result_t mtv_audio_add_silence(mtv_dec_config_t* dec_config,
                                        kal_uint32 start_ts, kal_uint32 au_count, kal_uint32 au_duration,
                                        mtv_deliver_concealment_t deliver_concealment, void* param);
/* memory stream helper */

typedef struct
{
    kal_uint8* buffer;
    kal_uint32 buffer_len;
    kal_uint32 len;

} mtv_memory_stream_t;

extern void mtv_memory_stream_init(mtv_memory_stream_t* stm);
extern void mtv_memory_stream_uninit(mtv_memory_stream_t* stm);
extern void mtv_memory_stream_write_byte(mtv_memory_stream_t* stm, kal_uint32 value);
extern void mtv_memory_stream_write(mtv_memory_stream_t* stm, void* buf, kal_uint32 size);
extern void mtv_memory_stream_write_be16(mtv_memory_stream_t* stm, kal_uint32 value);

extern void mtv_put_bits(kal_uint8* in, kal_uint32* bitcnt, kal_uint32 data, kal_uint32 data_length);

#endif /* _MTV_CONCEALMENT_H */
