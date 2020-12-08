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
 *   mtv_codec.h
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_CODEC_H
#define _MTV_CODEC_H

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#include "kal_general_types.h"
#include "mtv_error.h"

/**
  * MPEG-4 stream type (ISO/IEC 14496-1:2002 Table 7).
  */
typedef enum
{
    MPEG4_STREAM_SCENE_DESCRIPTION = 0x03,
    MPEG4_STREAM_VISUAL = 0x04,
    MPEG4_STREAM_AUDIO = 0x05

} mpeg4_stream_type_t;

/**
  * MPEG-4 object type indication (ETSI TS 102 428 Table 1).
  */
typedef enum
{
    MPEG4_OBJECT_TYPE_SYSTEM_14496_1 = 0x02,    /**< MPEG-4 video */
    MPEG4_OBJECT_TYPE_VISUAL_14496_2 = 0x20,    /**< MPEG-4 video */
    MPEG4_OBJECT_TYPE_VISUAL_14496_10 = 0x21,   /**< H.264 */
    MPEG4_OBJECT_TYPE_AUDIO_14496_3 = 0x40,     /**< MPEG-4 audio */
    MPEG4_OBJECT_TYPE_VISUAL_10918_1 = 0x6c,    /**< JPEG */
    MPEG4_OBJECT_TYPE_AUDIO_DAB = 0xc0,         /**< User private: DAB */
    MPEG4_OBJECT_TYPE_VISUAL_VC1 = 0xa3,        /**< VC-1 */
    MPEG4_OBJECT_TYPE_AUDIO_DRA = 0xa7          /**< DRA */

} mpeg4_object_type_indication_t;

#define MOBILE_AUDIO_INTERNETWORKING_PROFILE_L4 0x23

/**
  * Codec type.
  */
typedef enum
{
    MTV_CODEC_NONE,

    MTV_CODEC_H264,
    MTV_CODEC_MP4V,
    MTV_CODEC_VC1,
    MTV_CODEC_AVS,
    MTV_CODEC_H263,

    MTV_CODEC_BSAC,
    MTV_CODEC_AAC,
    MTV_CODEC_AAC_PLUS,
    MTV_CODEC_AAC_PLUS_V2,
    MTV_CODEC_MUSICAM,
    MTV_CODEC_AMR,
    MTV_CODEC_AMR_WB,
    MTV_CODEC_AMR_WB_PLUS,
    MTV_CODEC_DRA,
    MTV_CODEC_I2S,
    MTV_CODEC_LINEIN,

    MTV_CODEC_BIFS,

    MTV_CODEC_MOT,
    MTV_CODEC_TPEG

} mtv_codec_type_t;

/* H.264 constant */

#define H264_START_CODE     0x01000000
#define MAX_H264_SPS_LEN    64
#define MAX_H264_PPS_LEN    64

#define NALU_TYPE_CODED_SLICE_OF_IDR_PIC 5
#define NALU_TYPE_SPS           7
#define NALU_TYPE_PPS           8
#define NALU_TYPE_FILLER_DATA   12
#define NALU_TYPE_STAP_A        24
#define NALU_TYPE_STAP_B        25
#define NALU_TYPE_MTAP16        26
#define NALU_TYPE_MTAP24        27
#define NALU_TYPE_FU_A          28
#define NALU_TYPE_FU_B          29

/**
  * H.264 decoder configuration.
  */
typedef struct mtv_h264_dec_config_t
{
	kal_uint32 configuration_version;
	kal_uint32 avc_profile_indication;
	kal_uint32 profile_compatibility;
	kal_uint32 avc_level_indication;
	kal_uint32 length_size_minus_one;

    kal_int32 sps_count;                /**< number of SPS */
    kal_int32 sps_len[1];               /**< array of SPS length */
    kal_uint8 sps[1][MAX_H264_SPS_LEN]; /**< array of SPS */

    kal_int32 pps_count;                /**< number of PPS */
    kal_int32 pps_len[1];               /**< array of PPS length */
    kal_uint8 pps[1][MAX_H264_PPS_LEN]; /**< array of PPS */

} mtv_h264_dec_config_t;

/**
  * MPEG-4 audio (including AAC and BSAC) decoder configuration.
  */
typedef struct mtv_m4a_dec_config_t
{
    kal_uint32 buffer_size_db;      /**< DecoderConfigDescriptor.bufferSizeDB */
    kal_uint32 max_bitrate;         /**< DecoderConfigDescriptor.maxBitrate */
    kal_uint32 avg_bitrate;         /**< DecoderConfigDescriptor.avgBitrate */

	kal_uint8 audio_object_type;
	kal_uint8 sampling_frequency_index;
	kal_uint8 channel_configuration;
    kal_uint8 ep_config;

    kal_uint8 num_of_sub_frame;     /**< BSAC specific */
    kal_uint16 layer_length;        /**< BSAC specific */

} mtv_m4a_dec_config_t;

/**
  * Musicam decoder configuration.
  */
typedef struct mtv_musicam_dec_config_t
{
    kal_uint16 channels;            /**< number of channels */
    kal_uint16 bits_per_sample;     /**< bits per sample */
    kal_uint32 sample_rate;         /**< sample rate, in samples per second */
    kal_uint32 bitrate;             /**< in kbits/s */

} mtv_musicam_dec_config_t;

/**
  * DRA decoder configuration.
  */
typedef struct mtv_dra_dec_config_t
{
    kal_uint32 sample_rate;         /**< sample rate, in samples per second */
    kal_uint32 bitrate;             /**< in kbits/s */

} mtv_dra_dec_config_t;


/**
  * MP4V decoder configuration.
  */
typedef struct mtv_m4v_dec_config_t
{
    kal_uint32 buffer_size_db;      /**< DecoderConfigDescriptor.bufferSizeDB */
    kal_uint32 max_bitrate;         /**< DecoderConfigDescriptor.maxBitrate */
    kal_uint32 avg_bitrate;         /**< DecoderConfigDescriptor.avgBitrate */

    kal_uint8 vos[64];
    kal_uint32 vos_len;

} mtv_m4v_dec_config_t;

/**
  * H.263 decoder configuration.
  */
typedef struct mtv_h263_dec_config_t
{
    kal_uint32 width;               /**< Maximum width, in pixels of the stream */
    kal_uint32 height;              /**< Maximum height, in pixels of the stream */

    kal_uint32 vendor;              /**< four character code of the manufacturer of the codec, e.g. 'VXYZ'. */
 	kal_uint32 decoder_version;     /**< version of the vendor's decoder which can decode the encoded stream in the best (i.e. optimal) way. */
    kal_uint32 h263_level;          /**< based on the MIME media type video/H263-2000 */
    kal_uint32 h263_profile;        /**< based on the MIME media type video/H263-2000 */

    kal_uint32 avg_bitrate;         /**< the average bitrate in bits per second of this elementary stream. For streams with variable bitrate this value shall be set to zero. */
 	kal_uint32 max_bitrate;         /**< the maximum bitrate in bits per second of this elementary stream in any time window of one second duration. */

} mtv_h263_dec_config_t;

/**
  * AMR decoder configuration.
  */
typedef struct mtv_amr_dec_config_t
{
    kal_uint32 vendor;              /**< four character code of the manufacturer of the codec, e.g. 'VXYZ'. */
 	kal_uint32 decoder_version;     /**< version of the vendor's decoder which can decode the encoded stream in the best (i.e. optimal) way. */
    kal_uint32 mode_set;            /**< the active codec modes. */
    kal_uint32 mode_change_period;  /**< defines a number N, which restricts the mode changes only at a multiple of N frames. */
    kal_uint32 frames_per_sample;   /**< defines the number of frames to be considered as 'one sample' */

} mtv_amr_dec_config_t;

/**
  * I2S digital bus configuration.
  */
typedef struct mtv_i2s_dec_config_t
{
    kal_uint16 channels;            /**< number of channels */
    kal_uint16 bits_per_sample;     /**< bits per sample */
    kal_uint32 sample_rate;         /**< sample rate, in samples per second */

} mtv_i2s_dec_config_t;

/**
  * LINEIN analog bus configuration.
  */
typedef struct mtv_linein_dec_config_t
{
    kal_uint16 channels;            /**< number of channels */
    kal_uint16 bits_per_sample;     /**< bits per sample */
    kal_uint32 sample_rate;         /**< sample rate, in samples per second */

} mtv_linein_dec_config_t;

/**
  * Generic decoder configuration that is used to initialize decoder object.
  */
typedef struct
{
    mtv_codec_type_t codec;                 /**< codec type */

#if defined(__ATV_SUPPORT__)

    union
    {
        mtv_i2s_dec_config_t i2s;
        mtv_linein_dec_config_t linein;
    } u;

#else

    kal_uint32 timestamp_resolution;        /**< timestamp resolution */

    union
    {
        mtv_h264_dec_config_t h264;
        mtv_m4a_dec_config_t m4a;
        mtv_musicam_dec_config_t musicam;
        mtv_dra_dec_config_t dra;
        mtv_m4v_dec_config_t m4v;
        mtv_h263_dec_config_t h263;
        mtv_amr_dec_config_t amr;
        mtv_i2s_dec_config_t i2s;
        mtv_linein_dec_config_t linein;
    } u;

    void* private_init; /**< opaque data for decoder initialization */

#endif

} mtv_dec_config_t;

/* helper functions for mtv_dec_config_t */

extern void mtv_copy_dec_config_extra(mtv_dec_config_t* dst, mtv_dec_config_t* src);
extern void mtv_free_dec_config_extra(mtv_dec_config_t* cfg);
extern kal_uint32 mtv_dec_config_get_audio_sample_rate(mtv_dec_config_t* cfg);
extern kal_uint32 mtv_dec_config_get_audio_samples_per_frame(mtv_dec_config_t* dec_config);

/**
  * Decoder parameters.
  */
typedef enum
{
    MTV_CODEC_PARAM_VIDEO_OUTPUT,   /* opaque video output paramters */

    MTV_CODEC_PARAM_AUDIO_OUTPUT,   /* opaque audio output paramters */
    MTV_CODEC_PARAM_MUTE,           /* audio mute */
    MTV_CODEC_PARAM_VOLUME          /* audio volume */

} mtv_codec_param_t;


typedef struct mtv_dec_t mtv_dec_t;

/**
  * The interface for decoding pipeline. Currently we assume the AU sent to this interface will be displayed
  * to output device direcrly. Therefore, some display settings need to be specified by calling set_param.
  */
struct mtv_dec_t
{
    /**
      * Open the decoder with specified configuration.
      * @param config [in] decoder configuration
      */
    mtv_result_t (*open)(mtv_dec_t* dec, mtv_dec_config_t* config);

    /**
      * Send an access unit to the decoder.
      * @param au [in] the access unit. The AU does not guarantee to be valid after the call-back returns.
      */
    mtv_result_t (*send)(mtv_dec_t* dec, mtv_packet_t* au);

    /**
      * Set decoder parameter
      * @param id [in] paramter ID
      * @param value [in] parameter value
      * @see mtv_codec_param_t
      */
    mtv_result_t (*set_param)(mtv_dec_t* dec, kal_uint32 id, kal_uint32 value);

    /**
      * Get decoder parameter
      * @param id [in] paramter ID
      * @param value [in] returned parameter value
      * @see mtv_codec_param_t
      */
    mtv_result_t (*get_param)(mtv_dec_t* dec, kal_uint32 id, kal_uint32* value);

    /**
      * Reset the decoder and flush all queued data.
      */
    mtv_result_t (*reset)(mtv_dec_t* dec);

    /**
      * Close the decoder.
      */
    mtv_result_t (*close)(mtv_dec_t* dec);

};

/**
  * Stream type.
  */
typedef enum
{
    MTV_STREAM_INVALID,
    MTV_STREAM_AUDIO,
    MTV_STREAM_VIDEO,
    MTV_STREAM_DATA

} mtv_stream_type_t;

/**
  * Generic audio format.
  */
typedef struct
{
    kal_uint16 channels;            /**< number of channels */
    kal_uint16 bits_per_sample;     /**< bits per sample */
    kal_uint32 sample_rate;         /**< sample rate, in samples per second */

} mtv_audio_format_t;

/**
  * Generic video format.
  */
typedef struct
{
    kal_uint16 width, height;       /**< picture width/height */
    kal_uint32 time_scale;          /**< time scale in hertz */

} mtv_video_format_t;

/**
  * Media stream information.
  */
typedef struct
{
    mtv_stream_type_t type;         /**< stream type */

    union
    {
        mtv_audio_format_t audio;
        mtv_video_format_t video;

    } format;   /**< format-specific info */

    mtv_dec_config_t dec_config;

} mtv_stream_info_t;

/* public helpers */

extern kal_uint32 mp4a_get_sample_rate_from_index(kal_uint32 index);
extern kal_int32 mp4a_get_sample_rate_index(kal_uint32 sample_rate);
extern mtv_result_t mtv_check_h264_dec_config(mtv_h264_dec_config_t* h264);

#endif /* _MTV_CODEC_H */
