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
 *   mtv_concealment.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "med_global.h"

#include "med_trc.h"
#include "mtv_concealment.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mtv_comm.h"
#include "l1audio.h"
#include "mtv_codec.h"
#include "mtv_error.h"
#include "kal_trace.h"
#include "mtv_src_stat.h"

#if defined(__MED_MTV_MOD__) || defined(__STREAM_REC_SUPPORT__)

/* audio concealment */

/* copied from mp4_parser_audio.c */
void mtv_put_bits(kal_uint8* in, kal_uint32* bitcnt, kal_uint32 data, kal_uint32 data_length)
{
    kal_uint32 t, count;

    ASSERT(data_length>0 && data_length<=16);

    t = *bitcnt;

    if ((t & 0x7) == 0)
        in[t>>3] = 0;

    if ((t & 0x7) + data_length <= 8)
        in[(t>>3)] |= (data << (8-((t&0x7) + data_length)));
    else
    {
        count = (t&7) + data_length;
        in[(t>>3)] |= (data >> (data_length - 8 + (t&7)));
        count -= 8;

        if(count > 8) {
            in[(t>>3)+1] = (unsigned char)((data >> (count-8))&0xFF);
            in[(t>>3)+2] = (unsigned char)((data << (16-count))&0xFF);
        } else {
            in[(t>>3)+1] = (unsigned char)((data << (8-count))&0xFF);
        }
    }
    *bitcnt += data_length;
}

void mtv_fill_adts_header(kal_uint8* h, kal_uint32 sampling_frequency_index, kal_uint32 channel_configuration, kal_uint32 payload_length)
{
    kal_uint32 bit_count = 0;

    /* adts_fixed_header */
    mtv_put_bits(h, &bit_count, 0xFFF, 12); // syncword
    mtv_put_bits(h, &bit_count, 0, 1);      // ID
    mtv_put_bits(h, &bit_count, 0, 2);      // Layer
    mtv_put_bits(h, &bit_count, 1, 1);      // Protection absent
    mtv_put_bits(h, &bit_count, 1, 2);      // Profile
    mtv_put_bits(h, &bit_count, sampling_frequency_index, 4); // sample_frequency_index
    mtv_put_bits(h, &bit_count, 0, 1);      // private_bit
    mtv_put_bits(h, &bit_count, channel_configuration, 3); // Channel_configuration
    mtv_put_bits(h, &bit_count, 1, 1);      // original_copy
    mtv_put_bits(h, &bit_count, 0, 1);      // Home

    /* adts_variable_header */
    mtv_put_bits(h, &bit_count, 0, 1);      // copy_identification_bit
    mtv_put_bits(h, &bit_count, 0, 1);      // copy_identification_byte
    mtv_put_bits(h, &bit_count, payload_length + LEN_ADTS_HEADER, 13); // length
    mtv_put_bits(h, &bit_count, 0x7FF, 11); // buffer_fullness
    mtv_put_bits(h, &bit_count, 0, 2);      // no_raw_data_blocks_in_frame

    ASSERT(bit_count == LEN_ADTS_HEADER * 8);
}

mtv_result_t mtv_get_audio_media_format(mtv_codec_type_t mtv_codec_type, Media_Format *audio_media_format)
{
    mtv_result_t ret = MTV_S_OK;

    switch (mtv_codec_type)
    {
    case MTV_CODEC_BSAC:
        *audio_media_format = MEDIA_FORMAT_BSAC;
        break;
    case MTV_CODEC_AAC:
        *audio_media_format = MEDIA_FORMAT_AAC;
        break;
    case MTV_CODEC_AAC_PLUS:
        *audio_media_format = MEDIA_FORMAT_AAC_PLUS;
        break;
    case MTV_CODEC_AAC_PLUS_V2:
        *audio_media_format = MEDIA_FORMAT_AAC_PLUS_V2;
        break;
    case MTV_CODEC_MUSICAM:
        *audio_media_format = MEDIA_FORMAT_MUSICAM;
        break;
    case MTV_CODEC_AMR:
        *audio_media_format = MEDIA_FORMAT_AMR;
        break;
    case MTV_CODEC_DRA:
        *audio_media_format = MEDIA_FORMAT_DRA;
        break;
    default:
        *audio_media_format = MEDIA_FORMAT_UNKNOWN;
        ret = MTV_E_FAIL;
        MTV_TRACE(TRACE_ERROR, MTV_TRC_AUDIO_UNSUPPORTED_MEDIA_TYPE, mtv_codec_type);
        break;
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_CHECK_MEDIA_TYPE, mtv_codec_type, *audio_media_format);

    return ret;
}

mtv_result_t mtv_deliver_silence_frame(kal_uint32 timestamp, mtv_deliver_concealment_t deliver_concealment,
                                        void* param, kal_uint8* silence_frame_p, kal_uint32 silence_frame_len)
{
    mtv_memory_stream_t frame;
    mtv_packet_t au;

    mtv_memory_stream_init(&frame);

    mtv_memory_stream_write(&frame, silence_frame_p, silence_frame_len);

    au.data = frame.buffer;
    au.size = frame.len;
    au.flags = MTV_PACKET_WITH_ADTS_HEADER | MTV_PACKET_WITH_RANDOM_ACCESS_POINT | MTV_PACKET_IS_CONCEALMENT;
    au.timestamp = timestamp;
    deliver_concealment(param, &au);

    mtv_memory_stream_uninit(&frame);

    return MTV_S_OK;
}

mtv_result_t mtv_audio_add_silence(mtv_dec_config_t* dec_config,
                                        kal_uint32 start_ts, kal_uint32 au_count, kal_uint32 au_duration,
                                        mtv_deliver_concealment_t deliver_concealment, void* param)
{
    kal_uint32 i, len, sampling_rate;
    mtv_result_t ret = MTV_S_OK;
    Media_Format audio_media_format;
    kal_uint8 *silence_frame_p;
    Media_Status media_status;

    if (mtv_get_audio_media_format(dec_config->codec, &audio_media_format) == MTV_S_OK)
    {
        sampling_rate = mp4a_get_sample_rate_from_index(dec_config->u.m4a.sampling_frequency_index);

        media_status = Media_GetSilenceLength(audio_media_format, dec_config->u.m4a.channel_configuration,
                               sampling_rate, dec_config->u.m4a.num_of_sub_frame, &len);
        if (media_status == MEDIA_SUCCESS)
{
            MTV_TRACE(TRACE_INFO, MTV_TRC_AUDIO_ADD_SILENCE_FRAMES, audio_media_format, dec_config->u.m4a.channel_configuration, sampling_rate, dec_config->u.m4a.num_of_sub_frame,
                                                                    start_ts, au_count, au_duration);

            silence_frame_p = (kal_uint8*) mtv_alloc_ext_mem(len, MAKE_FOURCC('M','S','F','P'));

            media_status = Media_GetSilencePattern(audio_media_format, dec_config->u.m4a.channel_configuration,
                                    sampling_rate, dec_config->u.m4a.num_of_sub_frame, silence_frame_p);
            ASSERT(media_status == MEDIA_SUCCESS);

            for (i = 0; i < au_count; i++)
    {
                ret = mtv_deliver_silence_frame(start_ts, deliver_concealment, param,
                                                silence_frame_p, len);
                start_ts += au_duration;
        }
            mtv_free_ext_mem((void**) &silence_frame_p);
    }
        else
    {
            ret = MTV_S_FALSE;
        }
    }
    else
    {
        ret = MTV_S_FALSE;
    }

    return ret;
}

mtv_result_t mtv_deliver_audio_concealment(mtv_source_stat_t* src_stat, mtv_dec_config_t* dec_config, mtv_deliver_concealment_t deliver_concealment, void* param)
{
    mtv_result_t ret;
    kal_uint32 timestamp;

    if (!src_stat || !dec_config || !deliver_concealment) {
        return MTV_E_INVALID_PARAM;
    }

    timestamp = src_stat->max_timestamp - src_stat->loss * src_stat->au_duration;

    ret = mtv_audio_add_silence(dec_config, timestamp, src_stat->loss, src_stat->au_duration,
                                deliver_concealment, param);

    return ret;
}

/* memory stream */

void mtv_memory_stream_init(mtv_memory_stream_t* stm)
{
    stm->buffer_len = 32;
    stm->buffer = (kal_uint8*) mtv_alloc_ext_mem(stm->buffer_len, MAKE_FOURCC('M','S','T','M'));
    ASSERT(stm->buffer);
    stm->len = 0;
}

void mtv_memory_stream_uninit(mtv_memory_stream_t* stm)
{
    stm->buffer_len = 0;
    stm->len = 0;
    mtv_free_ext_mem((void**) &stm->buffer);
}

static void mtv_memory_stream_grow_if_necessary(mtv_memory_stream_t* stm, kal_uint32 size)
{
    if (stm->buffer_len - stm->len < size)
    {
        kal_uint32 new_size = stm->buffer_len * 2;
        kal_uint8* new_copy;

        if (stm->len + size > new_size) {
            new_size = stm->len + size;
        }

        new_copy = mtv_alloc_ext_mem(new_size, MAKE_FOURCC('M','S','T','M'));
        ASSERT(new_copy);
        kal_mem_cpy(new_copy, stm->buffer, stm->buffer_len);

        stm->buffer_len = new_size;
        mtv_free_ext_mem((void**) &stm->buffer);
        stm->buffer = new_copy;
    }
}

void mtv_memory_stream_write_byte(mtv_memory_stream_t* stm, kal_uint32 value)
{
    mtv_memory_stream_grow_if_necessary(stm, 1);

    stm->buffer[stm->len++] = (kal_uint8) value;
}

void mtv_memory_stream_write_be16(mtv_memory_stream_t* stm, kal_uint32 value)
{
    mtv_memory_stream_grow_if_necessary(stm, 2);

    stm->buffer[stm->len++] = (kal_uint8) ((value & 0x0000ff00) >> 8);
    stm->buffer[stm->len++] = (kal_uint8) (value & 0x000000ff);
}

void mtv_memory_stream_write(mtv_memory_stream_t* stm, void* buf, kal_uint32 size)
{
    mtv_memory_stream_grow_if_necessary(stm, size);

    kal_mem_cpy(stm->buffer + stm->len, buf, size);
    stm->len += size;
}

#endif /* defined(__MED_MTV_MOD__) */
