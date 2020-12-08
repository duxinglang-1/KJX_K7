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
 *   mtv_buffer_engine.h
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

#ifndef _MTV_BUFFER_ENGINE_H
#define _MTV_BUFFER_ENGINE_H

#ifndef _MTV_CODEC_H
#include "mtv_codec.h"
#endif

#ifndef _MTV_CONTROL_H
#include "mtv_control.h"
#endif

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

#ifndef _MTV_CACHED_IO_H
#include "mtv_cached_io.h"
#endif

#ifndef _MTV_SRC_STAT_H
#include "mtv_src_stat.h"
#endif

#include "kal_general_types.h"
#include "mtv_error.h"
#include "fs_type.h"
#include "mtv_comm.h"
#include "med_global.h"

#define MAX_SAMPLE_STREAM_SIZE 0x7fffffff

typedef struct
{
    kal_wchar* filename;
    kal_uint32 size;

} mtv_sample_stream_closed_t;

typedef struct mtv_sample_stream_t mtv_sample_stream_t;

/**
  * The stream that contains audio and video samples in the order they are output by demux.
  */
struct mtv_sample_stream_t
{
	/* public methods for recording */
    mtv_result_t (*read_sample)(mtv_sample_stream_t* self, kal_int32 pos, kal_uint8* buf, kal_uint32 size);
    mtv_result_t (*close_ex)(mtv_sample_stream_t* self, mtv_sample_stream_closed_t* closed_state);
    mtv_result_t (*reopen)(mtv_sample_stream_t* self, mtv_sample_stream_closed_t* closed_state);
    kal_uint32 (*get_stream_size)(mtv_sample_stream_t* self);

    FS_HANDLE stream_h;         /**< file handle for sample stream */
    cached_io_t cio;

    kal_bool allow_wrap_around; /**< indicates whether buffer wrap around is allowed */
    kal_int32 max_stream_size;  /**< the maximum sample stream size in bytes */

    kal_int32 num_rgn;          /**< number of regions */
    kal_int32 head[3];			/**< the head position of each region */
    kal_int32 tail[3];			/**< the tail position of each region */
};

/* sample index operations */

typedef enum
{
    /**
      * Indicates that this sample has been discarded.
      */
    MTV_SAMPLE_INDEX_ENTRY_DISCARDED = 0x10000000,

    /**
      * Indicates that the sample data is followed by validation info.
      * Note that this flag SHOULD NOT be turned on for official load
      * because it is for debugging only. Otherwise, the recorded file
      * will be corrupted.
      */
    MTV_SAMPLE_INDEX_ENTRY_HAS_VALIDATION_INFO = 0x20000000

} mtv_sample_index_entry_flags_t;

/**
  * The index entry that can help to find the position of audio/video samples in sample stream.
  */
typedef struct
{
    kal_uint32 pos;         /**< sample position in bytes */
    kal_uint32 size;        /**< sample size in bytes */
    kal_uint32 timestamp;   /**< sample timestamp */
    kal_uint32 flags;       /**< sample flags */

} mtv_sample_index_entry_t;

typedef struct mtv_sample_index_t mtv_sample_index_t;

/**
  * The stream that contains index to find the position of audio/video samples in sample stream.
  */
struct mtv_sample_index_t
{
    kal_int32 (*get_entry_count)(mtv_sample_index_t* self);
    kal_uint32 (*get_duration)(mtv_sample_index_t* self);
    void (*move_to_next_entry)(mtv_sample_index_t* self);
    mtv_result_t (*peek_entry)(mtv_sample_index_t* self, mtv_sample_index_entry_t* entry);
    void (*move_to_head)(mtv_sample_index_t* self);

    FS_HANDLE index_h;          /**< file handle for index stream */
    cached_io_t cio;

    kal_int32 max_index_size;   /**< the maximum index stream size in bytes */
    kal_int32 head, tail;       /**< the head and tail position in unit of entry number */
    kal_int32 next;             /**< the offset of next entry to read */

    mtv_stream_info_t info;     /**< the media stream information */

    kal_uint32 last_timestamp;  /**< normalized timestamp of last packet */
    kal_uint32 num_written;     /**< number of packets has written */
};

typedef struct mtv_sample_validation_info_t
{
    kal_uint32 signature;

} mtv_sample_validation_info_t;

/**
  * The format to save TV recording.
  */
typedef enum
{
    MTV_RECORDING_FORMAT_INVALID,   /**< Invalid format */
    MTV_RECORDING_FORMAT_MP4,       /**< MP4 format according to ISO/IEC 14496-12 */
    MTV_RECORDING_FORMAT_3GP,       /**< 3GPP format */
    MTV_RECORDING_FORMAT_MP2,       /**< MPEG-1 layer 2 audio */
    MTV_RECORDING_FORMAT_WAV,       /**< Windows WAV file */
    MTV_RECORDING_FORMAT_AVI        /**< Windows AVI file */

} mtv_recording_format_t;

/**
  * Various flags to control the behavior of buffer engine.
  */
typedef enum
{
    MTV_BE_BUFFER_WRAPAROUND = 0x01,     /**< allow the buffer to wrap around (overwriting old content) */
    MTV_BE_VALIDATE_PACKET   = 0x02,     /**< validate packet read from file buffer is correct */
    MTV_BE_SEQUENTIAL_OUTPUT = 0x04,     /**< the output stream need to be in time order */
    MTV_BE_NO_ASYNC_IO       = 0x08      /**< don't use async I/O */

} mtv_buffer_engine_flags_t;

/**
  * Various flags to control the behavior of buffer saving.
  */
typedef enum
{
    MTV_BE_ADD_DRM_HEADER_FOOTER = 0x01,  /**< add DRM header and footer to output file */
    MTV_BE_HIDE_OUTPUT_FILE      = 0x02,  /**< generate output as hidden file */
    MTV_BE_AAC_SBR_ENABLED       = 0x04   /**< indicate output AAC contains SBR */

} mtv_buffer_engine_save_flags_t;

/**
  * The read state of buffer engine.
  */
typedef enum
{
    MTV_BE_READ_INVALID,
    MTV_BE_READ_LIVE,
    MTV_BE_READ_PAUSED,
    MTV_BE_READ_DELAYED,
    MTV_BE_READ_PREBUFFERING /**< the intermediate state from DELAYED to LIVE */

} mtv_buffer_engine_read_state_t;

typedef struct mtv_buffer_engine_client_t mtv_buffer_engine_client_t;

/**
  * Client interface of buffer engine.
  */
struct mtv_buffer_engine_client_t
{
    /**
      * To notify the client about the read state change.
      */
    void (*on_read_state_change)(
        mtv_buffer_engine_client_t* client,
        mtv_buffer_engine_read_state_t old_state,
        mtv_buffer_engine_read_state_t new_state);

    /**
      * To notify the client about the seek.
      *
      * @param delay_ms [in] the delay value in milliseconds
      */
    void (*on_read_seek)(mtv_buffer_engine_client_t* client, kal_uint32 target_time, kal_uint32 delay_ms);
};

/**
  * Buffer engine configuration.
  */
typedef struct
{
    const kal_wchar* storing_dir;   /**< the directory to store buffer file */
    kal_uint32 max_buffer_kb;       /**< the maximum buffer size in KB */
    kal_uint32 estimated_bitrate;   /**< bitrate that is used to check disk space requirement */
    kal_uint32 flags;               /**< @see mtv_buffer_engine_flags_t */

} mtv_buffer_engine_config_t;

/**
  * Events happened during buffer engine operation.
  */
typedef enum
{
    MTV_BE_EVENT_BOC = 0x01  /**< Beginning of content has been reached */

} mtv_buffer_engine_events_t;

/**
  * File discard policy of buffer engine.
  */
typedef enum
{
    MTV_BE_DISCARD_FILES_AFTER_CLOSE,
    MTV_BE_KEEP_FILES_AFTER_CLOSE

} mtv_buffer_engine_discard_policy_t;

/* buffer engine */

typedef struct mtv_buffer_engine_t mtv_buffer_engine_t;

/**
  * The main purpose of buffer engine is to provide time-shifting funcationality for mobile TV aplication.
  * Therefore, you can write data into it and then read it back later. However, if the reading part is not
  * used, the buffer engine can serve as a simple MP4/WAV generator for audio/video recording application.
  */
struct mtv_buffer_engine_t
{
    /**
      * Open the buffer engine with specified configuration.
      *
      * @param client [in] the client interface
      * @param config [in] buffer engine configuration
      *
      * @retval MTV_S_* if succeeded.
      * @retval MTV_IO_E_DISK_FULL if there is not enough storage space.
      */
    mtv_result_t (*open)(mtv_buffer_engine_t* self, mtv_buffer_engine_client_t* client, mtv_buffer_engine_config_t* config);

    /**
      * Query specified control interface.
      *
      * @param control_id [in] the ID of requested control
      * @param control [out] to receive requested control
      */
    mtv_result_t (*get_control)(mtv_buffer_engine_t* self, mtv_control_t control_id, void** control);

    /**
      * Add a stream. Note that you can add at most one audio stream and one video stream currently.
      *
      * @param stream [in] stream info.
      */
    mtv_result_t (*add_stream)(mtv_buffer_engine_t* self, mtv_stream_info_t* stream);

    /**
      * Get a stream info. Note that you can only get a exist stream.
      *
      * @param stream [in] stream info.
      */
    mtv_result_t (*get_stream_info)(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_stream_info_t* stream);

    /**
      * Update a stream. Note that you can only update a exist stream.
      *
      * @param stream [in] stream info.
      */
    mtv_result_t (*update_stream_info)(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_stream_info_t* stream);

    /**
      * Write a packet to specified stream.
      *
      * @param stream_index [in] the stream index to write to
      * @param packet [in] the packet to write
      * @param events [out] to return various events happened during the writing. @see mtv_buffer_engine_events_t
      * @param src_stat [in] source statistics. It should be initialized with mtv_source_stat_init and updated with mtv_source_stat_update
      *     before it is passed to write_packet.
      */
    mtv_result_t (*write_packet)(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_packet_t* packet, kal_uint32* events, mtv_source_stat_t* src_stat);

    /**
      * Read next packet that may come from any stream. Note that you can only read packet in MTV_BE_READ_DELAYED
      * state. In other states, the read request will be rejected with error returned.
      *
      * @param stream_index [out] the stream index that this packet belongs to
      * @param packet [out] the packet to read
      *
      * @see get_read_state
      */
    mtv_result_t (*read_packet)(mtv_buffer_engine_t* self, kal_uint32* stream_index, mtv_packet_t* packet);

    /**
      * Read a packet from specified stream. Note that you can only read packet in MTV_BE_READ_DELAYED
      * state. In other states, the read request will be rejected with error returned.
      *
      * @param stream_index [in] the stream index to read from
      * @param packet [out] the packet to read
      *
      * @see get_read_state
      */
    mtv_result_t (*read_packet_from_stream)(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_packet_t* packet);

    /**
      * Translate AU time in buffer engine to stream time.
      *
      * @param stream_index [in] the stream index of AU
      * @param src_stat [in] source statistics
      * @param timestamp [in,out] the timestamp to translate
      */
    mtv_result_t (*translate_to_stream_time)(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_source_stat_t* src_stat, kal_uint32* timestamp);

    /**
      * Save the buffered data to a file in specified file format. The buffer engine will
      * be closed automatically after the file is saved.
      *
      * @param format [in] recording file format
      * @param file [in] recording file path
      * @param aborted [in] abort trigger
      * @param flags [in] various flags to tweak output result
      */
    mtv_result_t (*save)(mtv_buffer_engine_t* self, mtv_recording_format_t format, kal_wchar* file, volatile kal_bool* aborted, kal_uint32 flags);

    /**
      * Discard all buffered data.
      */
    mtv_result_t (*discard_all)(mtv_buffer_engine_t* self);

    /**
      * Specify the policy about how buffer files should be discarded.
      *
      * @param policy [in] the policy to specify
      */
    mtv_result_t (*set_discard_policy)(mtv_buffer_engine_t* self, mtv_buffer_engine_discard_policy_t policy);

    /**
      * To disable wrap around for recording.
      */
    mtv_result_t (*disable_wrap_around)(mtv_buffer_engine_t* self);

    /**
      * Returns whether the read is delayed.
      */
    mtv_buffer_engine_read_state_t (*get_read_state)(mtv_buffer_engine_t* self);

    /**
      * Set new maximum buffer size.
      */
    mtv_result_t (*set_max_buffer_size)(mtv_buffer_engine_t* self, kal_uint32 max_buffer_kb);

    /**
      * Save buffer checkpoint so that it can be recovered after abnormal stopping.
      *
      * @param cp_h [in] the cached I/O object that checkpoint content should be written to
      */
    mtv_result_t (*save_checkpoint)(mtv_buffer_engine_t* self, cached_io_t* cp_h);

    /**
      * Recover recording from checkpoint.
      *
      * @param cp_h [in] the cached I/O object that checkpoint content should be read from
      */
    mtv_result_t (*recover_from_checkpoint)(mtv_buffer_engine_t* self, cached_io_t* cp_h);

    /**
      * Close the buffer engine and remove all temporary files.
      */
    mtv_result_t (*close)(mtv_buffer_engine_t* self);

    /**
      * Destroy the instance.
      */
    void (*destroy)(mtv_buffer_engine_t* self);

/* private data */

    mtv_buffer_engine_client_t* client;
    mtv_control_timeshift_t timeshift_ctrl;

    kal_uint32 engine_flags;
    kal_wchar storing_dir[MAX_FILE_NAME_LEN];
    mtv_buffer_engine_discard_policy_t discard_policy;
    kal_uint32 estimated_bitrate;

    kal_int32 num_streams;      /**< number of streams. typical value is 1 or 2. */
    mtv_sample_stream_t ss;     /**< sample stream */
    mtv_sample_index_t si[2];   /**< sample indice */

    kal_int32 throttle;         /**< throttle for buffer writing */
    kal_uint32 num_dropped;     /**< number of dropped packets */
    kal_uint32 num_incoming;    /**< number of incoming packets */
    kal_uint64 bytes_read;      /**< number of bytes read from BE */
    kal_uint64 bytes_written;   /**< number of bytes written to BE */

    kal_uint64 last_space_check;            /**< the number of bytes written when disk space checking is done */
    kal_uint32 free_space_check_interval;   /**< the interval to perform free space checking */

    void* packet_buffer;            /**< packet buffer */
    kal_uint32 packet_buffer_size;  /**< size of packet buffer */

    mtv_buffer_engine_read_state_t read_state;  /**< current read state */
    kal_uint32 delay_ms;                        /**< target delay time in milliseconds */

    mtv_sample_validation_info_t validation_info;
};

extern mtv_buffer_engine_t* construct_mtv_buffer_engine(void);
extern void mtv_be_discard_unsaved_buffers(const kal_wchar* dir);
extern kal_bool mtv_be_is_recoverable_error(mtv_result_t error);

/**
  * Initialize Buffer Engine Service.
  */
extern kal_bool mtv_bes_init(void);

/**
  * Start Buffer Engine Service.
  */
extern mtv_result_t mtv_bes_start(void);

/**
  * Stop Buffer Engine Service.
  */
extern mtv_result_t mtv_bes_stop(void);

#endif /* _MTV_BUFFER_ENGINE_H */

