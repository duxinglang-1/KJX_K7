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
 *   SbcSink.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   SBC driver, for Bluetooth A2DP
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__BT_A2DP_PROFILE__) && defined(__AUDIO_COMPONENT_SUPPORT__)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "dcmgr.h"
#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "l1sp_trc.h"
#include "am.h"
#include "apm_util.h"
#include "sbc.h"
#include "audlp2_drv.h"
#include "dcl.h"
#include "pcmsink.h"

#if defined(__BTMTK__)
extern void a2dp_set_br_init_internal(kal_uint32 bit_rate_cur);
extern kal_uint32 a2dp_set_br_internal(kal_uint8 qos, kal_uint32 bit_rate_prev, kal_uint32 (*SetCodecBitRate)(kal_uint32));
#endif
extern kal_uint16 BT_A2DP_MAX_BIT_RATE;

//#define _SBC_DEBUG_NO_QOS_ // QOS indication wouldn't affect current bit rate
#define SBC_INIT_MEM_SIZE           (288)
#define SBC_FRAME_SUBBAND_DATA_SIZE (sbc.frame_state.subbands * sbc.frame_state.blocks)  //  8 * 16
#define SBC_WAV_FORMAT              ((Media_Format)-1)
#define MCU_MIN_SB_BUFFER_SIZE      (256)
#define SBC_PCM_BUFFER_SIZE         (1024*24)

const bt_a2dp_sbc_codec_cap_struct sbc_cap[1] = {
   { // joint-stereo, 44.1, 32, 16Ksps
      25, // min_bit_pool
      75, // max_bit_pool
      0x1, // block_len: 16 only
      0x1, // subband_num: 8 only
      SBC_ALLOCATION_SUPPORT,
      0xf, // sample_rate: all
      0xf, // channel_mode: all
   }
};

typedef enum {
  SBC_STATE_IDLE = 0,
  SBC_STATE_RUNING,
} SBC_STATE;

#pragma arm section code="SECONDARY_ROCODE"

struct {
   kal_uint8          *pBuffer;
   kal_uint16         uAudID;
   A2DP_codec_struct  a2dp_codec_hdl;
   A2DP_Callback      callback;
   kal_bool           waiting;
   Media_Format       aud_fmt;
   SBC_Encoder_State  *subband_analyzer_state;
   
   /* APM Information. Swap buffer for upsampling */
   kal_int32          src_sample_rate;   
   kal_int32          rampGain;
   kal_int32          rampFormat;
   kal_int16          preSample[22];     

   /* MCU ring buffer for subband sample */
   kal_int16          *subband_buffer;
   kal_uint16         subband_buffer_read;
   kal_uint16         subband_buffer_write;
   
   /* MCU ring buffer for SBC frame */
   kal_uint8          *frame_buffer;
   kal_uint32         frame_buffer_read;
   kal_uint32         frame_buffer_write;   
   kal_uint32         frame_buffer_length;
   kal_uint32         frame_buffer_unfilled_pos;

   kal_uint32         min_bit_rate;
   kal_uint32         current_bit_rate;
   kal_uint32         current_frame_size;
   kal_uint32         total_payload_size;

   kal_uint8          *fragment_start;
   kal_bool           fragment_flag;
   kal_uint8          fragment_left; // 1~15
   kal_uint16         fragment_left_bytes;
   kal_uint16         fragment_size;
   
   SBC_Frame_State    frame_state;
   kal_uint8          min_bit_pool;
   kal_uint8          max_bit_pool;

   kal_uint32         frame_produced;
   kal_uint32         frame_consumed;
   kal_uint32         frame_dropped;
   kal_uint32         max_sbc_bit_rate;

   kal_uint32         gpt;
   AUD_RB_INFO        PCM;
   SBC_STATE          uState;
   kal_bool           fIsDcmLoad;
} sbc;

static kal_uint32 sbc_initiate_bit_rate( kal_uint8 channel_mode, kal_uint8 sample_rate, Media_Format aud_fmt )
{
   kal_uint32 bit_rate;
   bit_rate = sbc.max_sbc_bit_rate;
   return bit_rate;
}

static kal_uint32 sbc_calc_bitrate_from_bitpool( kal_uint32 bitpool, kal_uint8 nrof_subbands, kal_uint8 nrof_blocks, kal_uint8 channel_mode, kal_uint32 fs, kal_uint32 *frame_length )
{   
   kal_uint8 nrof_channels, join;
   kal_uint32 frame_length_t, bitrate;

   nrof_channels = ( channel_mode==SBC_CM_MONO )? 1: 2;
   join = ( channel_mode==SBC_CM_JOINT_STEREO)? 1: 0;

   frame_length_t = 4 + ( 4 * nrof_subbands * nrof_channels ) / 8;
   if( channel_mode==SBC_CM_MONO || channel_mode==SBC_CM_DUAL_CHANNEL )
      frame_length_t += (nrof_blocks * nrof_channels * bitpool) / 8;
   else if( channel_mode==SBC_CM_STEREO || channel_mode==SBC_CM_JOINT_STEREO )
      frame_length_t += ( join * nrof_subbands + nrof_blocks * bitpool ) / 8;
   else
   {
      EXT_ASSERT( 0, channel_mode, 0, 0 );
      return( 0 );
   }

   bitrate = ( 8 * frame_length_t * fs ) / ( nrof_subbands * nrof_blocks );
   bitrate = (bitrate + 999) / 1000; // in kb/s with rounding

   if( frame_length!=NULL )
      *frame_length = frame_length_t;
   return( bitrate );
}

static kal_uint32 sbc_calc_bitpool_from_bitrate( kal_uint32 bitrate, kal_uint8 nrof_subbands, kal_uint8 nrof_blocks, kal_uint8 channel_mode, kal_uint32 fs, kal_uint32 *frame_length )
{
   kal_uint8 nrof_channels, join;
   kal_uint32 bitpool;
   kal_int32 frame_length_t;

   nrof_channels = ( channel_mode==SBC_CM_MONO )? 1: 2;
   join = ( channel_mode==SBC_CM_JOINT_STEREO)? 1: 0;

   frame_length_t = ( bitrate * 1000 * nrof_subbands * nrof_blocks ) / ( 8 * fs );
    if( frame_length!=NULL )
       *frame_length = frame_length_t;

   frame_length_t -= 4 + ( 4 * nrof_subbands * nrof_channels ) / 8;
   if( frame_length_t<=0 )
      return 0;
   if( channel_mode==SBC_CM_MONO || channel_mode==SBC_CM_DUAL_CHANNEL )
      bitpool = ( 8 * frame_length_t ) / ( nrof_blocks * nrof_channels );
   else if( channel_mode==SBC_CM_STEREO || channel_mode==SBC_CM_JOINT_STEREO )
      bitpool = ( 8 * frame_length_t - join * nrof_subbands ) / nrof_blocks;
   else
   {
      EXT_ASSERT( 0, channel_mode, 0, 0 );
      return 0;
   }

   return ( bitpool );
}

static kal_uint32 sbc_config(bt_a2dp_sbc_codec_cap_struct *sbc_config_data, kal_uint32 bit_rate)
{
   kal_uint8 bitpool_t;
   kal_uint32 frame_length_t, savedMask;
   
   if( sbc_config_data!=NULL )
   {
      kal_uint8 header_data = 0;
      
      if( sbc_config_data->block_len==1 )
      {
         sbc.frame_state.blocks = 16;
         header_data = SBC_NB_16<<4;
      }
      else if( sbc_config_data->block_len==2 )
      {
         sbc.frame_state.blocks = 12;
         header_data = SBC_NB_12<<4;
      }
      else if( sbc_config_data->block_len==4 )
      {
         sbc.frame_state.blocks = 8;
         header_data = SBC_NB_8<<4;
      }
      else if( sbc_config_data->block_len==8 )
      {
         sbc.frame_state.blocks = 4;
         header_data = SBC_NB_4<<4;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->block_len, 0, 0);
      }

      if( sbc_config_data->subband_num==1 )
      {
         sbc.frame_state.subbands = 8;
         header_data |= SBC_SB_8;
      }
      else if( sbc_config_data->subband_num==2 )
      {
         sbc.frame_state.subbands = 4;
         header_data |= SBC_SB_4;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->subband_num, 0, 0);
      }

      if( sbc_config_data->alloc_method==1 )
      {
         sbc.frame_state.allocation_method = SBC_AM_LOUDNESS;
         header_data |= SBC_AM_LOUDNESS<<1;
      }
      else if( sbc_config_data->alloc_method==2 )
      {
         sbc.frame_state.allocation_method = SBC_AM_SNR;
         header_data |= SBC_AM_SNR<<1;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->alloc_method, 0, 0);
      }

      if( sbc_config_data->sample_rate==1 )
      {
         sbc.frame_state.sampling_frequency = 48000;
         header_data |= SBC_FS_48<<6;
      }
      else if( sbc_config_data->sample_rate==2 )
      {
         sbc.frame_state.sampling_frequency = 44100;
         header_data |= SBC_FS_44<<6;
      }
      else if( sbc_config_data->sample_rate==4 )
      {
         sbc.frame_state.sampling_frequency = 32000;
         header_data |= SBC_FS_32<<6;
      }
      else if( sbc_config_data->sample_rate==8 )
      {
         sbc.frame_state.sampling_frequency = 16000;
         header_data |= SBC_FS_16<<6;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->sample_rate, 0, 0);
      }

      if( sbc_config_data->channel_mode==1 )
      {
         sbc.frame_state.channel_mode = SBC_CM_JOINT_STEREO;
         header_data |= SBC_CM_JOINT_STEREO<<2;
      }
      else if( sbc_config_data->channel_mode==2 )
      {
         sbc.frame_state.channel_mode = SBC_CM_STEREO;
         header_data |= SBC_CM_STEREO<<2;
      }
      else if( sbc_config_data->channel_mode==4 )
      {
         sbc.frame_state.channel_mode = SBC_CM_DUAL_CHANNEL;
         header_data |= SBC_CM_DUAL_CHANNEL<<2;
      }
      else if( sbc_config_data->channel_mode==8 )
      {
         sbc.frame_state.channel_mode = SBC_CM_MONO;
         header_data |= SBC_CM_MONO<<2;
      }
      else
      {
         EXT_ASSERT(0, sbc_config_data->channel_mode, 0, 0);
      }

      if( sbc.frame_state.channel_mode==SBC_CM_MONO )
         sbc.frame_state.channels = 1;
      else
         sbc.frame_state.channels = 2;

      sbc.frame_state.sbc_frame_header_data = header_data;

      sbc.max_bit_pool = sbc_config_data->max_bit_pool;
      sbc.min_bit_pool = sbc_config_data->min_bit_pool;
   }
   
   bitpool_t = (unsigned char)sbc_calc_bitpool_from_bitrate( bit_rate, sbc.frame_state.subbands, sbc.frame_state.blocks, sbc.frame_state.channel_mode, sbc.frame_state.sampling_frequency, NULL );
   if( bitpool_t<sbc.min_bit_pool )
   {
      bitpool_t = sbc.min_bit_pool;
   }
   else if( bitpool_t>sbc.max_bit_pool )
   {
      bitpool_t = sbc.max_bit_pool;
   }

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
#endif

   bit_rate = sbc_calc_bitrate_from_bitpool( bitpool_t, sbc.frame_state.subbands, sbc.frame_state.blocks, sbc.frame_state.channel_mode, sbc.frame_state.sampling_frequency, &frame_length_t );
   {
      kal_uint32 min_frame_length_t;
      sbc.min_bit_rate = sbc_calc_bitrate_from_bitpool( sbc.min_bit_pool, sbc.frame_state.subbands, sbc.frame_state.blocks, sbc.frame_state.channel_mode, sbc.frame_state.sampling_frequency, &min_frame_length_t );
   }
   
savedMask = SaveAndSetIRQMask();
   sbc.frame_state.bitpool = bitpool_t;
   sbc.current_frame_size = frame_length_t;
RestoreIRQMask(savedMask);

   kal_brief_trace( TRACE_INFO, L1SBC_CONFIG_REPORT, 
      sbc.frame_state.sampling_frequency, sbc.frame_state.channel_mode, 
      sbc.min_bit_pool, sbc.frame_state.bitpool, sbc.max_bit_pool );

   return( bit_rate );
}

static kal_uint32 sbc_SetBitRate(kal_uint32 bit_rate)
{
   if( bit_rate>sbc.max_sbc_bit_rate ) bit_rate = sbc.max_sbc_bit_rate;

   bit_rate = sbc_config( NULL, bit_rate );
   return( bit_rate );
}

static kal_uint32 sbc_AdjustBitRateFromQos(kal_uint8 qos) // return adjusted bit rate
{
   kal_uint32 bit_rate_prev = sbc.current_bit_rate;;

///   kal_brief_trace( TRACE_FUNC, L1SBC_ENTER_SBC_ADJUSTBITRATEFROMQOS );

#if defined(__BTMTK__) && !defined(_SBC_DEBUG_NO_QOS_)
   sbc.current_bit_rate = a2dp_set_br_internal( qos, sbc.current_bit_rate, sbc_SetBitRate );
#endif

   kal_brief_trace( TRACE_INFO, L1SBC_QOS_REPORT, 
      qos, bit_rate_prev, sbc.current_bit_rate );

   return( sbc.current_bit_rate );
}

static void sbc_QueryPayloadSize(uint32 *min, uint32 *total)
{
   kal_brief_trace( TRACE_GROUP_SBC, L1SBC_ENTER_SBC_QUERYPAYLOADSIZE );
   if( sbc.subband_buffer==0 || sbc.total_payload_size == 0) // sbc is closed or no data
   {
      *min = *total = 0;
      return;
   }
   {
      if( sbc.fragment_flag==KAL_TRUE )
      {
         *min = *total = 1 + (sbc.fragment_size>sbc.fragment_left_bytes)? 
                              sbc.fragment_left_bytes: 
                              sbc.fragment_size; // fixed payload size, 1 is for payload header
      }
      else
      {
         if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos && 
             sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
            sbc.frame_buffer_read = 0;
         *min = 1 + sbc.frame_buffer[sbc.frame_buffer_read];  // 1 is for payload header
         *total = 1 + sbc.total_payload_size;
      }
   }
}

static uint32 sbc_GetPayload(uint8 *buf , uint32 buf_len, uint32 *sample_cnt)
{
   register kal_uint8 *ptr_src, *ptr_des;
   int data_cnt, frame_cnt;
   int req_buf_len;
   kal_uint32 savedMask;

///   kal_brief_trace( TRACE_GROUP_SBC, L1SBC_ENTER_SBC_GETPAYLOAD );
   if( ( sbc.uAudID == INVALID_AUDIO_ID ) || 
       (sbc.subband_buffer == 0) || 
       (sbc.total_payload_size == 0) || 
       (sbc.frame_buffer_write == sbc.frame_buffer_read)) // sbc is closed or no data
   {
      *sample_cnt = 0;
      sbc.waiting = KAL_FALSE;
      return 0;
   }
   req_buf_len = buf_len;
   ptr_des = buf+1;
   buf_len -= 1; // reserved for payload header
   
   data_cnt = 0;
   frame_cnt = 0;
   *sample_cnt = 0;

   {
      if( sbc.fragment_flag==KAL_TRUE )
      { // continue and end fragment
         int payload_len;
         
         if(sbc.fragment_left_bytes >= sbc.fragment_size)
            payload_len = sbc.fragment_size;
         else
            payload_len = sbc.fragment_left_bytes;
      
         if(buf_len >= payload_len)
         {
            int I;
            
            ptr_src = sbc.fragment_start;
            sbc.fragment_left --;
            
            for( I=payload_len; --I>=0; )
               ptr_des[I] = ptr_src[I];
            ptr_des += payload_len;
            ptr_src += payload_len;
      
            sbc.fragment_start = ptr_src;
            sbc.fragment_left_bytes -= payload_len;
            data_cnt = payload_len;
savedMask = SaveAndSetIRQMask();
            sbc.total_payload_size -= data_cnt;
RestoreIRQMask(savedMask);
            sbc.frame_buffer_read += payload_len;
            
            if(sbc.fragment_left == 1)
            {
               if( sbc.fragment_left_bytes!=0 )
               {
                  ASSERT( 0 ); // there should be no data left
               }
               if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos &&
                   sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
                  sbc.frame_buffer_read = 0;
               if( sbc.frame_buffer_read>sbc.frame_buffer_unfilled_pos )
               {
                  ASSERT( 0 ); // read ptr shall not exceed unfilled_pos
               }
               
               sbc.fragment_flag = KAL_FALSE;
               
               *buf = 0xA0 + sbc.fragment_left;
               *sample_cnt = SBC_FRAME_SUBBAND_DATA_SIZE;
               frame_cnt = 1; // consume 1 frame  
               sbc.frame_consumed ++;
            }
            else
            {
               *buf = 0x80 + sbc.fragment_left;
               *sample_cnt = 0;
            }
      
         }
         else
         {
            ASSERT(0); // request not enough buf_len
         }
      }
      else
      {
         kal_bool bAllowFragment;
         int frame_len;
      
         bAllowFragment = KAL_TRUE;
         while(1)
         {
            if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos &&
                sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
               sbc.frame_buffer_read = 0;
            ptr_src = sbc.frame_buffer + sbc.frame_buffer_read;
            frame_len = *ptr_src++;

            EXT_ASSERT(*ptr_src == 0x9c, *ptr_src, frame_len, sbc.total_payload_size);
            if(buf_len >= frame_len)
            {
               int I;
               
               bAllowFragment = KAL_FALSE;
               
               for( I=frame_len; --I>=0; )
                  ptr_des[I] = ptr_src[I];
               ptr_des += frame_len;
               ptr_src += frame_len;
      
               buf_len -= frame_len;
               data_cnt += frame_len;
savedMask = SaveAndSetIRQMask();
               sbc.total_payload_size -= frame_len;
               if((sbc.frame_buffer_write == sbc.frame_buffer_read) && 
                  (sbc.total_payload_size != 0))
               {
                  //kal_prompt_trace(MOD_L1SP, "SBC WARN: r=w=%d, plsz=%d", sbc.frame_buffer_write, sbc.total_payload_size);
                  sbc.total_payload_size = 0;
               }
RestoreIRQMask(savedMask);
               sbc.frame_buffer_read += 1 + frame_len;
               if( sbc.frame_buffer_read==sbc.frame_buffer_unfilled_pos && 
                   sbc.frame_buffer_write<sbc.frame_buffer_unfilled_pos )
                  sbc.frame_buffer_read = 0;
               if( sbc.frame_buffer_read>sbc.frame_buffer_unfilled_pos )
               {
                  EXT_ASSERT( sbc.frame_buffer_read <= sbc.frame_buffer_unfilled_pos,
                              sbc.frame_buffer_read, sbc.frame_buffer_unfilled_pos, frame_len); // read ptr shall not exceed unfilled_pos
               }
               
               frame_cnt += 1;
               sbc.frame_consumed ++;
               
               if( (frame_cnt == 15) || 
                   (sbc.total_payload_size == 0))
               { // last frame
                  *buf = frame_cnt; // store payload header
                  *sample_cnt = frame_cnt * SBC_FRAME_SUBBAND_DATA_SIZE;
                  break;
               }
            }
            else
            {
               if( bAllowFragment==KAL_TRUE )
               { // start fragment
                  if( (buf_len*15) >= frame_len)
                  {
                     int I;
                     
                     ASSERT( *ptr_src == 0x9C ); // check SBC frame header
                     sbc.fragment_flag = KAL_TRUE;
                     sbc.fragment_size = buf_len;
                     sbc.fragment_left = (kal_uint8)((frame_len + buf_len - 1)/buf_len);
                     
                     for( I=buf_len; --I>=0; )
                        ptr_des[I] = ptr_src[I];
                     ptr_des += buf_len;
                     ptr_src += buf_len;
      
                     sbc.fragment_start = ptr_src;
                     sbc.fragment_left_bytes = frame_len - sbc.fragment_size;
      
                     data_cnt = buf_len; // it shall be equivalent to sbc.fragment_size here
savedMask = SaveAndSetIRQMask();
                     sbc.total_payload_size -= data_cnt;
RestoreIRQMask(savedMask);
                     sbc.frame_buffer_read += 1 + buf_len;
                     
                     *buf = 0xC0 + sbc.fragment_left;
                     *sample_cnt = 0;
                  }
                  else
                  {
                     ASSERT(0); // request less data than minimum
                  }
               }
               else
               { // last frame
                  *buf = frame_cnt; // store payload header
                  *sample_cnt = frame_cnt * SBC_FRAME_SUBBAND_DATA_SIZE;
               }
               break;
            }
         }
      }
      
      if(data_cnt != 0)
      {
         data_cnt += 1;
      }
   }

   kal_brief_trace( TRACE_GROUP_SBC, L1SBC_PAYLOAD_REPORT, req_buf_len, data_cnt, frame_cnt , sbc.total_payload_size );

   // sbc.waiting = KAL_FALSE;
   return( data_cnt );
}

static void sbc_GetPayloadDone()
{
   sbc.waiting = KAL_FALSE;
}

/* SBC driver interface */

void SBC_InitiateBitPool(kal_uint8 channel_mode, kal_uint8 sample_rate, kal_uint8 *min, kal_uint8 *max )
{
   kal_brief_trace( TRACE_FUNC, L1SBC_ENTER_SBC_INITIATEBITPOOL );
   if( min!=NULL ) *min = sbc_cap[0].min_bit_pool;
   if( max!=NULL ) *max = sbc_cap[0].max_bit_pool;
}

void SBC_AdjustBitpool( kal_uint8 max_bitpool, kal_uint8 min_bitpool )
{
   kal_brief_trace( TRACE_FUNC, L1SBC_ENTER_SBC_ADJUSTBITPOOL );
   EXT_ASSERT( sbc.uAudID != INVALID_AUDIO_ID, sbc.uAudID, 0, 0 ); // SBC shall be opened first
   if( min_bitpool<sbc_cap[0].min_bit_pool )
      min_bitpool = sbc_cap[0].min_bit_pool;
   if( min_bitpool>sbc_cap[0].max_bit_pool )
      min_bitpool = sbc_cap[0].max_bit_pool;
      
   if( max_bitpool>sbc_cap[0].max_bit_pool )
      max_bitpool = sbc_cap[0].max_bit_pool;
   if( max_bitpool<min_bitpool )
      max_bitpool = min_bitpool;
   
   sbc.min_bit_pool = min_bitpool;
   sbc.max_bit_pool = max_bitpool;
}

kal_uint32 SBC_SetQualityLevel(kal_uint32 level)
{
   kal_uint32 result_level = 0;
   switch(level)
   {
      case SBC_BEST_QUALITY:
#if defined(MT6256) 
         {
            sbc.max_sbc_bit_rate = 478;
            result_level = SBC_BEST_QUALITY;
            break;
         }
#endif
      case SBC_HIGH_QUALITY:
         {
            sbc.max_sbc_bit_rate = 328;
            result_level = SBC_HIGH_QUALITY;
            break;
         }
      case SBC_MID_QUALITY:
         sbc.max_sbc_bit_rate = 232;
         result_level = SBC_MID_QUALITY;
         break;
      default:
         EXT_ASSERT(0, level, 0, 0);
         break;
   }
   if( sbc.max_sbc_bit_rate>BT_A2DP_MAX_BIT_RATE ) sbc.max_sbc_bit_rate = BT_A2DP_MAX_BIT_RATE;
   return result_level;
}

void SBC_Init()
{
   memset( &sbc, 0, sizeof(sbc) );
   sbc.uAudID = INVALID_AUDIO_ID;
   sbc.current_bit_rate = 520;
   SBC_SetQualityLevel(SBC_BEST_QUALITY);
   sbc.gpt = DclSGPT_Open(DCL_GPT_CB,0);
}

kal_uint32 SBC_GetMemReq(void)
{
   return 8*1024; // recommended minimum sbc frame buffer length , it is adjustable
}

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
#endif

static void SBC_Process()
{
   kal_uint32 savedMask;
   kal_uint32 uLoopCnt=0;
   int NUM_FRAME_DATA;
   int UP_SAMPLING_RATE, NUM_UNSAMPLE_DATA;

   //kal_prompt_trace(MOD_L1SP,"[wn]SBC_Process, sbc.uState: %d", sbc.uState);
   if(sbc.uState != SBC_STATE_RUNING)
   {
      return;
   }

   UP_SAMPLING_RATE = sbc.frame_state.sampling_frequency / sbc.src_sample_rate;
   ASSERT(UP_SAMPLING_RATE == 1 || UP_SAMPLING_RATE == 2 || UP_SAMPLING_RATE == 4);
   NUM_UNSAMPLE_DATA = NUM_FRAME_DATA = SBC_FRAME_SUBBAND_DATA_SIZE*2;
   
   if (UP_SAMPLING_RATE == 2) 
   {
      NUM_UNSAMPLE_DATA = NUM_FRAME_DATA >> 1;
   } 
   else if (UP_SAMPLING_RATE == 4) 
   {
      NUM_UNSAMPLE_DATA = NUM_FRAME_DATA >> 2;
   }

   while(uLoopCnt++<2)
   {
      kal_int32 drop_frames=0, usedLen=0, data_count=0, frame_len=0;
      kal_uint32 uInDataByte = 0, write_end=0;
      kal_int16 *pInBuf;
      kal_uint8 *pPcmBuffer, *sbc_frame_ptr;
      rbGetReadBuffer(&sbc.PCM, &pPcmBuffer, &uInDataByte);
      data_count = (uInDataByte >> 1) * UP_SAMPLING_RATE;
      pInBuf = (kal_int16 *)pPcmBuffer;
      while( data_count>=NUM_FRAME_DATA )
      {
         write_end = sbc.frame_buffer_write + (sbc.current_frame_size+1);
         if( sbc.frame_buffer_write>=sbc.frame_buffer_read )
         {
            if( write_end >= sbc.frame_buffer_length )
            {
               if( sbc.frame_buffer_read<=(sbc.current_frame_size+1) )
               {
                  //kal_brief_trace( TRACE_WARNING, L1SBC_FRAME_BUFFER_UNDERRUN );
                  //drop_frames = data_count / NUM_FRAME_DATA;
                  //usedLen += drop_frames*NUM_UNSAMPLE_DATA;
                  //sbc.frame_dropped += drop_frames;
                  break;
               }
               else
               {  // update unfille_pos as write pointer, set write pointer to 0
                  sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_write;
                  sbc.frame_buffer_write = 0;
               }
            }
         }
         else
         {
            if( write_end>=sbc.frame_buffer_read )
            {
               //kal_brief_trace( TRACE_WARNING, L1SBC_FRAME_BUFFER_UNDERRUN );
               //drop_frames = data_count / NUM_FRAME_DATA;
               //usedLen += drop_frames*NUM_UNSAMPLE_DATA;
               //sbc.frame_dropped += drop_frames;
               break;
            }
         }
         if (UP_SAMPLING_RATE == 1) 
         {
            memcpy(sbc.subband_buffer, pInBuf, MCU_MIN_SB_BUFFER_SIZE*sizeof(kal_int16));
         }
         else
         {               
            apm_UpsampleStereo(pInBuf, sbc.subband_buffer, sbc.preSample, (NUM_UNSAMPLE_DATA>>1), UP_SAMPLING_RATE);
         }
         sbc_RampUpSignal(sbc.subband_buffer, sbc.rampFormat, MCU_MIN_SB_BUFFER_SIZE, &sbc.rampGain, 2);
         sbc_analyze_audio( 2, sbc.subband_analyzer_state, &sbc.frame_state, sbc.subband_buffer );
         sbc_frame_ptr = (kal_uint8 *)sbc.frame_buffer + sbc.frame_buffer_write;
         *sbc_frame_ptr++ = (kal_uint8)sbc.current_frame_size;
         sbc_pack_frame(&sbc.frame_state, sbc_frame_ptr, &frame_len, sbc.current_frame_size);
         ASSERT(frame_len==sbc.current_frame_size);
         sbc.frame_buffer_write += frame_len+1;
savedMask = SaveAndSetIRQMask();
         sbc.total_payload_size += frame_len;
RestoreIRQMask(savedMask);
         ASSERT(sbc.total_payload_size <= sbc.frame_buffer_length);
         if( sbc.frame_buffer_unfilled_pos<sbc.frame_buffer_write )
         {
            sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_write;
         }
         if( sbc.frame_buffer_write==sbc.frame_buffer_length )
         {
            sbc.frame_buffer_write = 0;
         }
         sbc.frame_produced ++;
         data_count -= NUM_FRAME_DATA;
         pInBuf += NUM_UNSAMPLE_DATA;
         usedLen += NUM_UNSAMPLE_DATA;
      }
      rbReadDataDone(&sbc.PCM, usedLen<<1);
   }
   if( sbc.total_payload_size>1024 && sbc.waiting==KAL_FALSE )
   {
      sbc.waiting = KAL_TRUE;
      sbc.callback(A2DP_DATA_NOTIFY, (void*)&sbc.a2dp_codec_hdl);
   }
   return;
}

A2DP_codec_struct *SBC_Open(
   Media_Format aud_fmt, 
   A2DP_Callback pHandler, 
   bt_a2dp_sbc_codec_cap_struct *sbc_config_data, 
   kal_uint8 *buf, 
   kal_uint32 buf_len )
{
   kal_uint8 *pAllocBuffer;
   kal_uint32 uTotalBufferSize = 0, bit_rate = 0;
#if !defined( MED_MODEM ) && defined(__AUDIO_COMPONENT_SUPPORT__)
   if(!PcmSink_IsAudioRuning() && !PcmSink_IsMixerRuning()) //if audio and midi is running, do not terminate
   {
      PcmSink_TerminateSound();
   }
#endif
#if defined(__DCM_WITH_COMPRESSION_AUDIO_BT__)
   if(sbc.fIsDcmLoad == KAL_FALSE)
   {
      DCM_Load(DYNAMIC_CODE_COMPRESS_SBC, 0, 0);
      sbc.fIsDcmLoad = KAL_TRUE;
   }
#endif
   ASSERT( buf_len>=SBC_GetMemReq() );
   ASSERT(sbc.uState == SBC_STATE_IDLE);
   //alloc memory
   uTotalBufferSize += MCU_MIN_SB_BUFFER_SIZE*2; //SBC_INIT_MEM_SIZE;
   uTotalBufferSize += 16*2*8*2;
   uTotalBufferSize += (sizeof(SBC_Encoder_State)+3) & ~3;
   uTotalBufferSize += SBC_INIT_MEM_SIZE;
   uTotalBufferSize += SBC_PCM_BUFFER_SIZE;

   sbc.pBuffer = pAllocBuffer = (kal_uint8 *)audio_alloc_mem_cacheable(uTotalBufferSize);                 
   ASSERT(pAllocBuffer);
   sbc.PCM.rb_base = pAllocBuffer;
   sbc.PCM.rb_size = SBC_PCM_BUFFER_SIZE;
   pAllocBuffer += SBC_PCM_BUFFER_SIZE;
   sbc.subband_buffer = (kal_uint16*)pAllocBuffer;
   pAllocBuffer += MCU_MIN_SB_BUFFER_SIZE*2;
   sbc.frame_state.sb_sample = (kal_uint16*)pAllocBuffer;
   pAllocBuffer += 16*2*8*2;
   sbc.subband_analyzer_state = (SBC_Encoder_State *)pAllocBuffer;
   pAllocBuffer += (sizeof(SBC_Encoder_State)+3) & ~3;
   if( sbc_Init_Ptr((kal_int16*)pAllocBuffer) > SBC_INIT_MEM_SIZE )
   {
      ASSERT(0);
   }

   //init structure
   sbc.a2dp_codec_hdl.GetPayload = sbc_GetPayload;
   sbc.a2dp_codec_hdl.GetPayloadDone = sbc_GetPayloadDone;
   sbc.a2dp_codec_hdl.QueryPayloadSize = sbc_QueryPayloadSize;
   sbc.a2dp_codec_hdl.AdjustBitRateFromQos = sbc_AdjustBitRateFromQos;
   sbc.a2dp_codec_hdl.SetBitRate = sbc_SetBitRate;
   sbc.callback = pHandler;
   sbc.waiting = KAL_FALSE;
   sbc.subband_buffer_read = 0;
   sbc.subband_buffer_write = 0;
   sbc.frame_buffer = buf;
   sbc.frame_buffer_write = 0;
   sbc.frame_buffer_read = 0;
   sbc.frame_buffer_length = buf_len;
   sbc.frame_buffer_unfilled_pos = sbc.frame_buffer_length;
   memset(sbc.preSample, 0, 8*sizeof(kal_int16));

   bit_rate = sbc_initiate_bit_rate( sbc_config_data->channel_mode, sbc_config_data->sample_rate, aud_fmt );
   // take previous status as reference
   if( sbc.frame_state.sampling_frequency >= 44100 && sbc.frame_state.channels == 2 && sbc.current_bit_rate < bit_rate && sbc.aud_fmt != SBC_WAV_FORMAT )
   {
      bit_rate = sbc.current_bit_rate;
   }

   sbc.a2dp_codec_hdl.state = 0;
   sbc.aud_fmt = aud_fmt;
   sbc.current_bit_rate = sbc_config( sbc_config_data, bit_rate ); // sbc.current_frame_size shall be set here
#if defined(__BTMTK__) && !defined(_SBC_DEBUG_NO_QOS_)
      a2dp_set_br_init_internal( sbc.current_bit_rate );
#endif
      
   sbc.total_payload_size = 0;
   sbc.fragment_flag = KAL_FALSE;
   sbc.fragment_start = NULL;
   sbc.fragment_left = 0;
   sbc.fragment_left_bytes = 0;
   sbc.fragment_size = 0;
   sbc.frame_produced = 0;
   sbc.frame_consumed = 0;
   sbc.frame_dropped = 0;

   sbc.uAudID = L1Audio_GetAudioID();
   L1Audio_SetFlag( sbc.uAudID ); // disable sleep mode
   L1Audio_SetEventHandler( sbc.uAudID, SBC_Process );

   sbc_Init_ZI();
   sbc.rampGain = 0;
   if (sbc.frame_state.sampling_frequency >= 32000) 
   {
      sbc.rampFormat = 15;
   } 
   else if ((sbc.frame_state.sampling_frequency >= 16000)) 
   {
      sbc.rampFormat = 14;
   }
   else 
   {
      sbc.rampFormat = 13;
   }

   sbc.PCM.write   = 0;
   sbc.PCM.read    = 0;
   memset(sbc.preSample, 0, 8*sizeof(short));
   sbc.uState = SBC_STATE_RUNING;
   PcmSink_StartBT(PCMSINK_BT_SBC);
#if defined(__AUDIO_DSP_LOWPOWER_V2__)
   AUDLP_SetDSPBufferThreshold_Short(KAL_TRUE);
#endif
   //SBC_Timer( NULL );
   return &sbc.a2dp_codec_hdl;
}


void SBC_Close(void)
{
   PcmSink_StopBT(PCMSINK_BT_SBC);
   if(sbc.uState == SBC_STATE_RUNING)
   {
      sbc.uState = SBC_STATE_IDLE;
      audio_free_mem( (void **) &sbc.pBuffer);
      sbc.pBuffer = NULL;
      L1Audio_ClearFlag( sbc.uAudID ); //enable sleep mode  
      L1Audio_FreeAudioID(sbc.uAudID);
      sbc.uAudID = INVALID_AUDIO_ID;
#if defined(__AUDIO_DSP_LOWPOWER_V2__)
      AUDLP_SetDSPBufferThreshold_Short(KAL_FALSE);
#endif
   }

#if defined(__DCM_WITH_COMPRESSION_AUDIO_BT__)
   if(sbc.fIsDcmLoad)
   {
      DCM_Unload(DYNAMIC_CODE_COMPRESS_SBC);
      sbc.fIsDcmLoad = KAL_FALSE;
   }
#endif

}

kal_bool SBC_IsOn()
{
   if(sbc.uAudID==INVALID_AUDIO_ID )
   {
      return KAL_FALSE;
   }
   return KAL_TRUE;
}

void SBC_QueryInfo(bt_a2dp_sbc_codec_info_struct *info)
{
   info->min_bit_rate = sbc.min_bit_rate;
}


void SBC_SetInfo(kal_uint16 uSampleRate, kal_uint8 uChannelNumber)
{
   sbc.src_sample_rate = uSampleRate;
}

kal_uint32 SBC_WriteSilence(kal_uint32 uSampleCount)
{
   kal_uint32 uCopyWord=0, uOutByte=0, i, j, uOrigSrcWord, uChannelNumber, uOutWord;
   kal_uint8 *pDst;
   if(sbc.uState != SBC_STATE_RUNING)
   {
      return 0;
   }
   uOrigSrcWord = uSampleCount;
   for(i=0;i<2;i++)
   {
      kal_int16 *pBuf;
      rbGetWriteBuffer(&sbc.PCM, &pDst, &uOutByte);  
      uOutWord = uOutByte >> 1;
      if(uOutWord > uSampleCount)
      {
         uOutWord = uSampleCount;
      }
      memset( pDst, 0, uOutWord*sizeof(kal_uint16) );
      rbWriteDataDone(&sbc.PCM, uOutWord<<1);
      uCopyWord    += uOutWord;
      uSampleCount -= uOutWord;
   }
   L1Audio_SetEvent( sbc.uAudID, NULL );
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_ZERO, uOrigSrcWord, uCopyWord, uOrigSrcWord-uCopyWord);
   return uCopyWord;
}

kal_uint32 SBC_WriteData(kal_uint16 *pSrc16, kal_uint32 uSrcWord, kal_bool fMono2Stereo)
{
   kal_uint32 uCopyWord=0, uOutByte=0, i, j, uOrigSrcWord=0, uOutWord=0;
   kal_uint8 *pDst;
   if(sbc.uState != SBC_STATE_RUNING)
   {
      return 0;
   }
   uOrigSrcWord = uSrcWord;
   for(i=0;i<2;i++)
   {
      kal_uint16 *pDst16;
      rbGetWriteBuffer(&sbc.PCM, &pDst, &uOutByte);  
      pDst16 = (kal_uint16*)pDst;
      uOutWord = uOutByte >> 1;
      if(fMono2Stereo)
      {
         uOutWord = uOutWord >> 1;
         if(uOutWord > uSrcWord)
         {
            uOutWord = uSrcWord;
         }
         for(j=0;j<uOutWord;j++)
         {
            *pDst16++ = *pSrc16;
            *pDst16++ = *pSrc16++;
         }
         uSrcWord -= uOutWord;
         rbWriteDataDone(&sbc.PCM, uOutWord<<2);
      }
      else
      {
         if(uOutWord > uSrcWord)
         {
            uOutWord = uSrcWord;
         }
         memcpy(pDst16, pSrc16, uOutWord*sizeof(kal_uint16));
         pSrc16   += uOutWord;
         uSrcWord -= uOutWord;
         rbWriteDataDone(&sbc.PCM, uOutWord<<1);
      }
      uCopyWord += uOutWord;
   }

   L1Audio_SetEvent( sbc.uAudID, NULL );
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_AUDIO_DATA, uOrigSrcWord, uCopyWord, uOrigSrcWord-uCopyWord, fMono2Stereo);
   return uCopyWord;
}

#pragma arm section 

#endif 

