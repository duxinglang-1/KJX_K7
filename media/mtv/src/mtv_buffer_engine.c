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
 *   mtv_buffer_engine.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "med_global.h"

#if defined(__MED_MTV_MOD__) || defined(__STREAM_REC_SUPPORT__)

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "med_utility.h"
#include "med_trc.h"
#include "mtv_buffer_engine.h"
#include "mtv_output_mp4.h"
#include "mtv_output_mp2.h"
#include "mtv_output_wav.h"
#include "mtv_concealment.h"

#if defined(__MTK_TARGET__)
#include "SST_sla.h"
#endif

#include "kal_general_types.h"
#include "mtv_control.h"
#include "mtv_error.h"
#include "mtv_comm.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mtv_cached_io.h"
#include "mtv_codec.h"
#include "kal_trace.h"
#include "mtv_custom.h"
#include "mtv_src_stat.h"
#include "jpeg_mem.h"

#define STREAM_TO_SAMPLE_RATIO  4
#define H264_NALU_LENGTH_SIZE   4

#define BE_MIN_BUFFER_MS        2000
#define BE_LIVE_BACK_OFF_MS     2000

/**
  * The maximum size of a media sample.
  */
#define MTV_MAX_MEDIA_SAMPLE_SIZE       (32*1024)

/* conversions between milliseconds and track time */
#define MS_TO_TT(ms, si) ((kal_uint32)((kal_uint64)(ms) * si->info.dec_config.timestamp_resolution / 1000))
#define TT_TO_MS(tt, si) ((kal_uint32)((kal_uint64)(tt) * 1000 / si->info.dec_config.timestamp_resolution))

typedef struct
{
    kal_int32 head;
    kal_int32 tail;

} mtv_region_t;

typedef struct
{
    kal_int32 num_rgn;   /**< the number of invalidated regions */
    mtv_region_t rgn[2]; /**< the regions to invalidate */

    kal_int32 pos;       /**< where the sample is written */
    kal_uint32 size;     /**< number of bytes written */

} ss_sample_location_t;

/* forward declarations */

static mtv_result_t mtv_be_timeshift_get_buffer_status_ex(mtv_control_timeshift_t* control, kal_uint32* max_delay, kal_uint32* buffer_duration, kal_int32* dominant_track);

/* helper functions */

kal_wchar* mtv_filename_dup(const kal_wchar* from)
{
    return mtv_str_dup(from, MAX_FILE_NAME_LEN, MAKE_FOURCC('F','L','N','M'));
}

kal_wchar* mtv_generate_new_filename(const kal_wchar* dir, const kal_wchar* basename, const kal_wchar* extname)
{
    kal_uint32 i;
    kal_wchar* fname;
    kal_wchar serial_num[7];

    fname = mtv_alloc_filename();
    for (i = 0; i < 10000; i++)
    {
        if (i == 0)
        {
            kal_wstrncpy(fname, dir, MAX_FILE_NAME_LEN - 1);
            kal_wstrcat(fname, basename);
            kal_wstrcat(fname, extname);
        }
        else
        {
            kal_wstrncpy(fname, dir, MAX_FILE_NAME_LEN - 1);
            kal_wstrcat(fname, basename);
            kal_wsprintf(serial_num, "(%d)", i);
            kal_wstrcat(fname, serial_num);
            kal_wstrcat(fname, extname);
        }

        if (FS_GetAttributes(fname) < 0) {
            return fname; /* this file does not exist! */
        }
    }

    return NULL;
}

kal_uint32 mtv_process_files(const kal_wchar* dir, const kal_wchar* pattern, mtv_process_file_callback process_file, void* callback_param)
{
    FS_HANDLE ff;
    FS_DOSDirEntry fi;
    kal_uint32 processed = 0;
    kal_wchar* to_find = mtv_alloc_filename();
    kal_wchar* filename = mtv_alloc_filename();
    kal_wchar* to_process = mtv_alloc_filename();

    kal_wstrncpy(to_find, dir, MAX_FILE_NAME_LEN - 1);
    kal_wstrcat(to_find, pattern);
    if ((ff = FS_FindFirst(to_find, 0, 0, &fi, filename, FS_MAX_PATH)) >= 0)
    {
        do
        {
            if (!(fi.Attributes & FS_ATTR_DIR))
            {
                kal_wstrncpy(to_process, dir, MAX_FILE_NAME_LEN - 1);
                kal_wstrcat(to_process, filename);

                processed++;

                if (process_file && !process_file(callback_param, to_process)) {
                    break;
                }
            }
        } while ((FS_FindNext(ff, &fi, filename, FS_MAX_PATH) == FS_NO_ERROR));

        FS_FindClose(ff);
    }

    mtv_free_ext_mem((void**) &filename);
    mtv_free_ext_mem((void**) &to_process);
    mtv_free_ext_mem((void**) &to_find);

    return processed;
}

static kal_int32 mtv_close_file(FS_HANDLE fh, kal_bool delete_it)
{
    kal_int32 ret;

    if (delete_it)
    {
        FS_FileInfo fi;

        ret = FS_GetFileInfo(fh, &fi);
        if (ret >= 0)
        {
            kal_wchar* fname = mtv_filename_dup((kal_wchar*)fi.FullName);

            ret = FS_Close(fh);
            if (ret >= 0)
            {
                ret = FS_Delete(fname);
            }

            mtv_free_ext_mem((void**)&fname);
        }
    }
    else {
        ret = FS_Close(fh);
    }

	return mtv_error_from_fs(ret);
}

#define COPY_REGION_BUFFER_SIZE 4096

static mtv_result_t copy_file_region(FS_HANDLE dst, cached_io_t* cio_src, kal_int32 start_pos, kal_int32 size)
{
    kal_int32 ret;
    kal_uint8* buf;
	kal_uint32 remaining;
    kal_uint32 pos;

    buf = (kal_uint8*) mtv_alloc_ext_mem(COPY_REGION_BUFFER_SIZE, MAKE_FOURCC('C','P','R','B'));

    pos = start_pos;

    ASSERT(size > 0);
    remaining = (kal_uint32) size;

    do
    {
        kal_uint32 read_bytes = remaining < COPY_REGION_BUFFER_SIZE ? remaining : COPY_REGION_BUFFER_SIZE;
        kal_uint32 written_bytes;

        ret = cached_io_read_pos(cio_src, pos, buf, read_bytes);
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            goto copy_region_cleanup;
        }

        ret = FS_Write(dst, buf, read_bytes, &written_bytes);
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            goto copy_region_cleanup;
        }
        ASSERT(read_bytes == written_bytes);

        remaining -= written_bytes;
        pos += read_bytes;

    } while (remaining != 0);

copy_region_cleanup:

    mtv_free_ext_mem((void**)&buf);
    return (mtv_result_t)ret;
}

void mtv_copy_dec_config_extra(mtv_dec_config_t* dst, mtv_dec_config_t* src)
{
    UNUSED(dst);
    UNUSED(src);
}

void mtv_free_dec_config_extra(mtv_dec_config_t* cfg)
{
    UNUSED(cfg);
}

/* sample stream operations */

static void ss_reset(mtv_sample_stream_t* self)
{
    ASSERT(self->stream_h >= 0);
    self->num_rgn =0;
}

static kal_int32 ss_calc_offset(mtv_sample_stream_t* self, kal_int32 pos)
{
    kal_int32 i;
    kal_int32 pos_so_far = 0;

    /* iterate each region in order to calculate the offset */
    for (i = 0; i < self->num_rgn; i++)
    {
        if (pos >= self->head[i] && pos < self->tail[i]) {
            return pos_so_far + pos - self->head[i];
        }

        pos_so_far += self->tail[i] - self->head[i];
    }

    return -1;  /* the pos is not in regions */
}

static void ss_sanity_check(mtv_sample_stream_t* self)
{
    kal_int32 i, j;

    ASSERT(self->stream_h >= 0);
    ASSERT(self->max_stream_size > 0);

    ASSERT(self->num_rgn >= 0 && self->num_rgn <= ARRAY_SIZE(self->head));
    for (i = 0; i < self->num_rgn; i++)
    {
        ASSERT(self->head[i] >= 0 && self->head[i] <= self->max_stream_size);
        ASSERT(self->tail[i] >= 0 && self->tail[i] <= self->max_stream_size);
        ASSERT(self->head[i] <= self->tail[i]);

        if (i == 1)
        {
            ASSERT(self->head[i] == 0);
        }

        /* check overlaping */
        for (j = 0; j < self->num_rgn; j++)
        {
            if (j != i)
            {
                ASSERT(self->head[i] < self->head[j] || self->head[i] >= self->tail[j]);
                ASSERT(self->tail[i] <= self->head[j] || self->tail[i] >= self->tail[j]);
            }
        }
    }
}

static void ss_check_read_pos(mtv_sample_stream_t* self, kal_int32 pos)
{
    ASSERT(ss_calc_offset(self, pos) >= 0);
}

mtv_result_t ss_close_ex(mtv_sample_stream_t* self, mtv_sample_stream_closed_t* closed_state)
{
    kal_int32 ret;
    FS_FileInfo fi;

    closed_state->filename = NULL;
    closed_state->size = 0;

    if (self->stream_h < 0) {
        return MTV_E_FAIL;
    }

    ret = cached_io_detach(&self->cio);
    if (ret >= 0)
    {
        ret = FS_GetFileInfo(self->stream_h, &fi);
        if (ret >= 0)
        {
            closed_state->filename = mtv_filename_dup((kal_wchar*)fi.FullName);
            ASSERT(closed_state->filename);

            ret = FS_GetFileSize(self->stream_h, &closed_state->size);
            if (ret >= 0)
            {
                ret = FS_Close(self->stream_h);
            }
        }

        self->stream_h = -1;
    }

    return (mtv_result_t)mtv_error_from_fs(ret);
}

/**
  * Create a new sample stream with the same filename.
  */
mtv_result_t ss_reopen(mtv_sample_stream_t* self, mtv_sample_stream_closed_t* closed_state)
{
    kal_int32 ret;

    ASSERT(self->stream_h < 0);
    ret = FS_Open(closed_state->filename, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
    if (ret < 0) {
        return (mtv_result_t)mtv_error_from_fs(ret);
    }
    else
    {
        self->stream_h = ret;

        ret = cached_io_attach(&self->cio, self->stream_h);
        if (ret < 0)
        {
            FS_Close(self->stream_h);
            return (mtv_result_t)mtv_error_from_fs(ret);
        }
    }

    cached_io_set_async(&self->cio);

    return MTV_S_OK;
}

#define SS_PADDING_BLOCK_SIZE   1024

static mtv_result_t ss_write_padding(mtv_sample_stream_t* self, kal_uint32 pos, kal_uint32 padding_bytes)
{
    kal_int32 ret;
    kal_uint8* zeros;
    kal_uint32 written;

    zeros = (kal_uint8*) mtv_alloc_ext_mem(SS_PADDING_BLOCK_SIZE, MAKE_FOURCC('B','P','A','D'));
    kal_mem_set(zeros, 0, SS_PADDING_BLOCK_SIZE);

    cached_io_seek(&self->cio, pos);
    for (written = 0; written < padding_bytes; )
    {
        if (written + SS_PADDING_BLOCK_SIZE <= padding_bytes)
        {
            ret = cached_io_write(&self->cio, zeros, SS_PADDING_BLOCK_SIZE);
            written += SS_PADDING_BLOCK_SIZE;
        }
        else
        {
            ret = cached_io_write(&self->cio, zeros, padding_bytes - written);
            written = padding_bytes;
        }

        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            mtv_free_ext_mem((void**) &zeros);
            return (mtv_result_t)mtv_error_from_fs(ret);
        }
    }

    mtv_free_ext_mem((void**) &zeros);
    return MTV_S_OK;
}

static mtv_result_t ss_write_buffer(mtv_sample_stream_t* self, kal_int32 num_parts, mtv_packet_t* parts, ss_sample_location_t* location)
{
    kal_int32 ret;
    kal_int32 i;
    kal_uint32 stream_rgn;
    kal_int32 inv_rgn = 0;
    kal_uint32 size = 0;
    kal_uint32 io_status;

    ASSERT(num_parts >= 1);
    for (i = 0; i < num_parts; i++) {
        size += parts[i].size;
    }

    if (size == 0 || (kal_int32) size > self->max_stream_size)
    {
        SHOULD_NOT_HAPPEN("Invalid buffer size!");
        return MTV_E_INVALID_PARAM;
    }

    ss_sanity_check(self);

    if (self->num_rgn == 0)
    {
        self->num_rgn++;
        self->head[0] = 0;
        self->tail[0] = 0;
    }

    stream_rgn = self->num_rgn - 1;    /* write to the last region by default */

    if ((self->tail[stream_rgn] + (kal_int32) size) <= self->max_stream_size)
    {
        /*
         *
         * |==============|+++++++++++++++++|-----------|
         *               tail            new_tail   max_stream_size
         */
        cached_io_seek(&self->cio, self->tail[stream_rgn]);
        for (i = 0; i < num_parts; i++)
        {
            ret = cached_io_write(&self->cio, parts[i].data, parts[i].size);
            if (ret < 0)
            {
                MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
                return (mtv_result_t)mtv_error_from_fs(ret);
            }
        }

        location->pos = location->rgn[0].head = self->tail[stream_rgn];
        location->rgn[0].tail = self->tail[stream_rgn] + size;

        if (self->num_rgn == 2)
        {
            if (location->rgn[0].tail > self->head[0] && location->rgn[0].tail <= self->tail[0])
            {
                /*
                 *                                    new tail
                 *                              ++++++++|
                 * |===========================|---|=============|
                 *                            tail           max_stream_size
                 */

                /* adjust the head position of partially overwritten region */
                self->head[0] = location->rgn[0].tail;

                if (self->head[0] == self->tail[0])
                {
                    /* the previous region is completely overwritten */
                    self->num_rgn = 1;
                    self->head[0] = 0;
                    stream_rgn = 0;
                }
            }
        }

        self->tail[stream_rgn] = location->rgn[0].tail;

        ss_sanity_check(self);
    }
    else
    {
        kal_int32 padding_bytes;

        if (!self->allow_wrap_around) {
            return MTV_E_OVER_LIMIT;
        }

        /*
         *    size                        padding_bytes
         * |++++++++++++++|------------|00000000000000000|
         *             new_tail       tail           max_stream_size
         */
        padding_bytes = self->max_stream_size - self->tail[stream_rgn];
        ASSERT(padding_bytes >= 0);
        if (padding_bytes > 0)
        {
            ret = ss_write_padding(self, self->tail[stream_rgn], padding_bytes);
            if (ret < 0) {
                return (mtv_result_t)ret;
            }

            /*
             * although we don't overwrite the padding area, we still need to invalidate
             * this region so that samples in this area can be invalidated
             */
            location->rgn[0].head = self->tail[stream_rgn];
            location->rgn[0].tail = self->tail[stream_rgn] + padding_bytes;
            inv_rgn++;
        }

        /* write the buffer in second region entirely */
        ASSERT(size > 0);
        cached_io_seek(&self->cio, 0);
        for (i = 0; i < num_parts; i++)
        {
            ret = cached_io_write(&self->cio, parts[i].data, parts[i].size);
            if (ret < 0)
            {
                MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
                return (mtv_result_t)mtv_error_from_fs(ret);
            }
        }

        location->pos = location->rgn[inv_rgn].head = 0;
        location->rgn[inv_rgn].tail = size;

        if (self->num_rgn == 1)
        {
            /* extend current region */
            self->tail[stream_rgn] = self->max_stream_size;

            if (location->rgn[inv_rgn].tail >= self->head[stream_rgn] &&
                location->rgn[inv_rgn].tail < self->tail[stream_rgn])
            {
                /*
                 *               wr[inv_rgn].tail
                 *  +++++++++++++++++++++|                 ++++++
                 * |----------------|=====================|------|
                 *                                           max_stream_size
                 */
                self->head[stream_rgn] = location->rgn[inv_rgn].tail;
            }

            /* add new region */
			self->num_rgn++;
            self->head[1] = 0;
            self->tail[1] = location->rgn[inv_rgn].tail;
        }
        else if (self->num_rgn == 2)
        {
            /*
             *   wr[inv_rgn].tail
             * ++++|                        +++++++++++++++++
             * |===========================|---|=============|
             *                            tail           max_stream_size
             */
            self->head[0] = location->rgn[inv_rgn].tail;
            self->tail[0] = self->max_stream_size;
            self->head[1] = 0;
            self->tail[1] = location->rgn[inv_rgn].tail;
        }
        else
        {
            NOT_REACHED("Impossible region number?!");
        }

        ss_sanity_check(self);
    }

    location->num_rgn = inv_rgn + 1;
    location->size = size;
    ASSERT(location->num_rgn == 1 || location->num_rgn == 2);

    /* after all writing is done, check slow status */
    io_status = cached_io_get_status(&self->cio);
    if (io_status & CACHED_IO_STATUS_SLOW_WRITING) {
        return MTV_S_SLOW;
    }

    return MTV_S_OK;
}

static mtv_result_t ss_read_sample(mtv_sample_stream_t* self, kal_int32 pos, kal_uint8* buf, kal_uint32 size)
{
    kal_int32 ret;
    kal_int32 rgn;

    ss_sanity_check(self);
    ss_check_read_pos(self, pos);

    /* find the region where the read position belongs to*/
    for (rgn = 0; rgn < self->num_rgn; rgn++)
    {
        if (pos >= self->head[rgn] && pos < self->tail[rgn]) {
            break;
        }
    }
    if (rgn == self->num_rgn)
    {
        NOT_REACHED("Invalid pos is given!?");
        return MTV_E_INVALID_PARAM;
    }

    if (pos + (kal_int32) size <= self->tail[rgn])
    {
        ret = cached_io_read_pos(&self->cio, pos, buf, size);
        if (ret < 0) {
            return (mtv_result_t)mtv_error_from_fs(ret);
        }
    }
    else
    {
        kal_int32 padding_bytes;

        if (!self->allow_wrap_around) {
            return MTV_E_OVER_LIMIT;
        }

        if (rgn == self->num_rgn - 1) {
            return MTV_E_OVER_LIMIT;
        }

        /*
         *        size                    padding_bytes
         * |==============|------------|00000000000000000|
         *                            pos          max_stream_size
         */
        padding_bytes = self->tail[rgn] - pos;
        ASSERT(padding_bytes >= 0);

        /* just read the sample from the second region */
        ASSERT(self->head[rgn + 1] + (kal_int32) size <= self->tail[rgn + 1]);
        ret = cached_io_read_pos(&self->cio, self->head[rgn + 1], buf, size);
        if (ret < 0) {
            return (mtv_result_t)mtv_error_from_fs(ret);
        }
    }

    return MTV_S_OK;
}

__inline kal_int32 ss_get_maximum_size(mtv_sample_stream_t* self)
{
    return self->max_stream_size;
}

mtv_result_t ss_set_maximum_size(mtv_sample_stream_t* self, kal_int32 max_stream_size)
{
    /* only allow increasing */
    if (max_stream_size <= self->max_stream_size || max_stream_size == 0) {
        return MTV_E_INVALID_PARAM;
    }

    if (self->num_rgn <= 1)
    {
        /*
         * |-------|==========================|------|################|
         * 0      head                       tail      increased part
         *  ^^^^^^^ head empty space
         */

        /*
         * simply increase the maximum size and assume the head empty space is small and
         * will not waste too much space.
         */
    }
    else if (self->num_rgn == 2)
    {
        /*
         * |======*=======|------------|======*======|################|
         * 0     pos     tail         head   pos   max_stream_size
         *                 ^^^^^^^^^^^^ empty space
         */

        kal_int32 new_region = self->num_rgn++;

        /*
         * create a new region because we assume the empty space is small and
         * will not waste too much space.
         */
        self->head[new_region] = self->max_stream_size;
        self->tail[new_region] = self->max_stream_size;

        /* wrap around need to be turned off */
        self->allow_wrap_around = KAL_FALSE;
    }
	else if (self->num_rgn == 3)
	{
        ASSERT(self->tail[2] < max_stream_size);
        ASSERT(self->allow_wrap_around == KAL_FALSE);
	}
    else
    {
        NOT_REACHED("Impossible region number!?");
        return MTV_E_FAIL;
    }

    self->max_stream_size = max_stream_size;

    return MTV_S_OK;
}

kal_uint32 ss_get_size(mtv_sample_stream_t* self)
{
    kal_uint32 bytes = 0;
    kal_int32 i;

    for (i = 0; i < self->num_rgn; i++) {
        bytes += (self->tail[i] - self->head[i]);
    }

    return bytes;
}

static mtv_result_t ss_wrap_around_now(mtv_sample_stream_t* self)
{
    if (!self->allow_wrap_around || self->num_rgn > 2) {
        return MTV_E_FAIL;
    }

    if (self->num_rgn == 2) {
        return MTV_S_FALSE;
    }

    self->max_stream_size = self->tail[0];
    return MTV_S_OK;
}

static void ss_disable_wrap_around(mtv_sample_stream_t* self)
{
    self->allow_wrap_around = KAL_FALSE;
}

static kal_uint32 ss_get_stream_size(mtv_sample_stream_t* self)
{
    if (self->stream_h < 0) {
        return 0;
    }

    return self->cio.file_size;
}

static mtv_result_t ss_open_from_file_handle(mtv_sample_stream_t* self, FS_HANDLE stream_h, kal_uint32 max_stream_size, kal_bool allow_wrap_around, kal_bool use_async_io)
{
    ASSERT(max_stream_size >= MIN_SAMPLE_STREAM_SIZE);

    ASSERT(stream_h >= 0);
    self->stream_h = stream_h;
    if (cached_io_attach(&self->cio, self->stream_h) < 0)
    {
        FS_Close(self->stream_h);
        return (mtv_result_t)mtv_error_from_fs(self->stream_h);
    }
    if (use_async_io) {
        cached_io_set_async(&self->cio);
    }

    self->max_stream_size = max_stream_size;
    self->allow_wrap_around = allow_wrap_around;

    ss_reset(self);

    self->close_ex = ss_close_ex;
    self->reopen = ss_reopen;
    self->read_sample = ss_read_sample;
    self->get_stream_size = ss_get_stream_size;

    return MTV_S_OK;
}

static mtv_result_t ss_open(mtv_sample_stream_t* self, kal_wchar* file, kal_uint32 max_stream_size, kal_uint32 engine_flags)
{
    kal_bool allow_wrap_around = (engine_flags & MTV_BE_BUFFER_WRAPAROUND) ? KAL_TRUE : KAL_FALSE;
    kal_bool use_async_io = (engine_flags & MTV_BE_NO_ASYNC_IO) ? KAL_FALSE : KAL_TRUE;
    FS_HANDLE stream_h;

    stream_h = FS_Open(file, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
    if (stream_h < 0) {
        return (mtv_result_t)mtv_error_from_fs(stream_h);
    }

    return ss_open_from_file_handle(self, stream_h, max_stream_size, allow_wrap_around, use_async_io);
}

typedef struct mtv_be_ss_checkpoint_t
{
    kal_int32 max_stream_size;

    kal_int32 num_rgn;
    kal_int32 head[3];
    kal_int32 tail[3];

    kal_wchar filename[MAX_FILE_NAME_LEN];

} mtv_be_ss_checkpoint_t;

mtv_result_t ss_save_checkpoint(mtv_sample_stream_t* self, cached_io_t* cp_h)
{
    mtv_be_ss_checkpoint_t* ss_cp = NULL;
    FS_FileInfo fi;
    kal_int32 ret;

    /* flush all cached content */
    ret = cached_io_flush(&self->cio);
    if (ret < 0) {
        goto cleanup;
    }

    ss_cp = (mtv_be_ss_checkpoint_t*) mtv_alloc_ext_mem(sizeof(*ss_cp), MAKE_FOURCC('S','S','C','K'));

    ss_cp->max_stream_size = self->max_stream_size;
    ss_cp->num_rgn = self->num_rgn;

    ASSERT(sizeof(ss_cp->head) == sizeof(self->head));
    kal_mem_cpy(ss_cp->head, self->head, sizeof(self->head));
    ASSERT(sizeof(ss_cp->tail) == sizeof(self->tail));
    kal_mem_cpy(ss_cp->tail, self->tail, sizeof(self->tail));

    ret = FS_GetFileInfo(self->stream_h, &fi);
    if (ret < 0) {
        goto cleanup;
    }
    kal_wstrncpy(ss_cp->filename, (kal_wchar*) fi.FullName, ARRAY_SIZE(ss_cp->filename) - 1);

    ret = cached_io_write(cp_h, ss_cp, sizeof(*ss_cp));
    if (ret < 0) {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
    }

cleanup:

    mtv_free_ext_mem((void**) &ss_cp);
    return (mtv_result_t)mtv_error_from_fs(ret);
}

static mtv_result_t ss_open_from_checkpoint(mtv_sample_stream_t* self, cached_io_t* cp_h)
{
    mtv_be_ss_checkpoint_t* ss_cp = NULL;
    FS_HANDLE stream_h = -1;
    kal_int32 ret;

    ss_cp = (mtv_be_ss_checkpoint_t*) mtv_alloc_ext_mem(sizeof(*ss_cp), MAKE_FOURCC('S','S','C','K'));

    ret = cached_io_read(cp_h, ss_cp, sizeof(*ss_cp));
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    stream_h = FS_Open(ss_cp->filename, FS_READ_ONLY);
    if (stream_h < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, stream_h, __LINE__);
        ret = mtv_error_from_fs(stream_h);
        goto cleanup;
    }

    ret = ss_open_from_file_handle(self, stream_h, ss_cp->max_stream_size, KAL_FALSE, KAL_FALSE);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    self->num_rgn = ss_cp->num_rgn;

    ASSERT(sizeof(ss_cp->head) == sizeof(self->head));
    kal_mem_cpy(self->head, ss_cp->head, sizeof(self->head));
    ASSERT(sizeof(ss_cp->tail) == sizeof(self->tail));
    kal_mem_cpy(self->tail, ss_cp->tail, sizeof(self->tail));

cleanup:

    if (ret < 0 && stream_h >= 0)
    {
        if (FS_Close(stream_h) >= 0) {
            FS_Delete(ss_cp->filename);
        }
    }

    mtv_free_ext_mem((void**) &ss_cp);
    return (mtv_result_t)ret;
}

static mtv_result_t ss_close(mtv_sample_stream_t* self, kal_bool discard_files)
{
    if (self->stream_h >= 0)
    {
        cached_io_detach(&self->cio);

        mtv_close_file(self->stream_h, discard_files);
        self->stream_h = -1;
    }

    return MTV_S_OK;
}

/* index stream operations */

#define POS_OK              0
#define POS_INVALID         -1
#define POS_OUT_OF_BOUND    -2

static kal_int32 si_check_pos(mtv_sample_index_t* self, kal_int32 pos)
{
    if (pos < 0 || pos >= self->max_index_size) {
        return POS_OUT_OF_BOUND;
    }

    if (self->head < self->tail)
    {
        if (pos < self->head) {
            return POS_INVALID; /* fall behind? */
        }
        else if (pos > self->tail) {
            return POS_INVALID; /* too fast? */
        }

        return POS_OK;   /* in correct range */
    }
    else if (self->head > self->tail)
    {
        if (pos > self->tail && pos < self->head) {
            return POS_INVALID; /* fall behind or too fast */
        }

        return POS_OK;  /* in correct range */
    }
    else /* self->head == self->tail */
    {
        if (pos != self->head) {
            return POS_INVALID;
        }

        return 0;
    }
}

static void si_sanity_check(mtv_sample_index_t* self)
{
    ASSERT(self->index_h >= 0);
    ASSERT(self->max_index_size > 0);
    ASSERT(self->head >= 0 && self->head < self->max_index_size);
    ASSERT(self->tail >= 0 && self->tail < self->max_index_size);
	ASSERT(si_check_pos(self, self->next) == POS_OK);
}

static kal_int32 si_get_entry_count(mtv_sample_index_t* self)
{
    if (self->head <= self->tail) {
        return  self->tail - self->head;
    }
    else {
        return self->max_index_size - self->head + self->tail;
    }
}

static mtv_result_t si_peek_entry_by_pos(mtv_sample_index_t* self, mtv_sample_index_entry_t* entry, kal_int32 pos)
{
    kal_int32 ret;

    if (pos == self->tail) {
        return MTV_E_NO_MORE_DATA;  /* invalid position */
    }
    else if (si_check_pos(self, pos) != POS_OK) {
        return MTV_E_FAIL;
    }

	si_sanity_check(self);

    ret = cached_io_read_pos(&self->cio, pos * sizeof(*entry), entry, sizeof(*entry));
    return (mtv_result_t)mtv_error_from_fs(ret);
}

static mtv_result_t si_peek_entry_by_index(mtv_sample_index_t* self, mtv_sample_index_entry_t* entry, kal_int32 index)
{
    kal_int32 target = (self->head + index) % self->max_index_size;
    return si_peek_entry_by_pos(self, entry, target);
}

static mtv_result_t si_peek_entry(mtv_sample_index_t* self, mtv_sample_index_entry_t* entry)
{
    return si_peek_entry_by_pos(self, entry, self->next);
}

static mtv_result_t si_get_first_timestamp(mtv_sample_index_t* self, kal_uint32* first_timestamp)
{
    kal_uint32 saved_next;
    mtv_sample_index_entry_t entry;
    mtv_result_t ret;

    if (self->head == self->tail) {
        return MTV_E_INVALID_PARAM;
    }

    saved_next = self->next;

    self->next = self->head;
    ret = si_peek_entry(self, &entry);
    if (ret < 0) {
        return ret;
    }

    self->next = saved_next;

    *first_timestamp = entry.timestamp;
    return MTV_S_OK;
}

static mtv_result_t si_get_last_timestamp(mtv_sample_index_t* self, kal_int32 offset, kal_uint32* last_timestamp)
{
    kal_uint32 saved_next;
    mtv_sample_index_entry_t entry;
    mtv_result_t ret;

    if (self->head == self->tail) {
        return MTV_E_INVALID_PARAM;
    }

    saved_next = self->next;

    self->next = self->tail - offset;
    if (self->next < 0) {
        self->next += self->max_index_size;
    }
    ret = si_peek_entry(self, &entry);
    if (ret < 0) {
        return ret;
    }

    self->next = saved_next;

    *last_timestamp = entry.timestamp;
    return MTV_S_OK;
}

static kal_uint32 si_get_duration(mtv_sample_index_t* self)
{
    mtv_result_t ret;
    kal_uint32 first_ts, last_ts, last_two_ts = 0;
    kal_uint32 duration;

    ret = si_get_last_timestamp(self, 1, &last_ts);
    if (ret < 0) {
        return 0;   /* zero length if any error happened */
    }

    ret = si_get_last_timestamp(self, 2, &last_two_ts);
    if (ret < 0) {
        return 0;   /* zero length if any error happened */
    }

    ret = si_get_first_timestamp(self, &first_ts);
    if (ret < 0) {
        return 0;   /* zero length if any error happened */
    }

    duration = last_ts - first_ts + (last_ts - last_two_ts);

    return duration;
}

static mtv_result_t si_move_to_time(mtv_sample_index_t* self, kal_uint32 time, kal_uint32 required_flags, kal_uint32* seeked_time)
{
    mtv_result_t ret;
    kal_int32 low, high, probe, i, inc;
    mtv_sample_index_entry_t entry;
	kal_int32 num_entries;

	/*
	 * Although we assume the reading rate is equal to the writing rate,
	 * the beginning of the buffer still can be easily overwritten depending
	 * on the implemtation of the reading part. Therefore, we keep some minimum
	 * distance from the beginning for safety.
	 */
	num_entries = si_get_entry_count(self);
	low = 0;
    high = num_entries - 1;

    if (low >= num_entries) {
        return MTV_E_FAIL;
    }

    /* get current time */
    ret = si_peek_entry(self, &entry);
    if (ret == MTV_E_NO_MORE_DATA) {
        ret = si_peek_entry_by_index(self, &entry, high);
    }
    if (ret < 0) {
        return ret;
    }
    inc = entry.timestamp > time ? -1 : 1;

    /* use binary search to speed-up the seeking */
	ASSERT(high >= low);
    probe = low + (high - low) / 2;
    while (low <= high)
    {
        ret = si_peek_entry_by_index(self, &entry, probe);
        if (ret < 0) {
            return ret;
        }

        if (entry.timestamp > time) {
            high = probe - 1;
        }
        else if (entry.timestamp < time) {
            low = probe + 1;
        }
        else {
            break;  /* exact match */
        }
        probe = low + (high - low) / 2;
    }

    /* for non-exact match, move a little far away according to seek direction */
    if (entry.timestamp > time && inc < 0 && probe >= 1) {
        probe--;
    }
    else if (entry.timestamp < time && inc > 0 && probe < num_entries - 1) {
        probe++;
    }

    if (required_flags != 0)
    {
        /* search for required sample flags */
        for (i = probe; i >= 0 && i < num_entries; i += inc)
        {
            ret = si_peek_entry_by_index(self, &entry, i);
            if (ret < 0) {
                return ret;
            }

            if ((entry.flags & required_flags) == required_flags)
            {
                probe = i;
                break;
            }
        }

        if (i < 0 || i >= num_entries)
        {
            /* try searching in opposite direction */
            for (i = probe - inc; i >= 0 && i < num_entries; i -= inc)
            {
                ret = si_peek_entry_by_index(self, &entry, i);
                if (ret < 0) {
                    return ret;
                }

                if ((entry.flags & required_flags) == required_flags)
                {
                    break;
                }
            }
        }

        if (i < 0 || i >= num_entries) {
            return MTV_E_FAIL;
        }

        probe = i;
        if (seeked_time) {
            *seeked_time = entry.timestamp;
        }
    }

    /* move to the last probe position */
    self->next = (self->head + probe) % self->max_index_size;
	si_sanity_check(self);

    return MTV_S_OK;
}

static mtv_result_t si_add_entry(mtv_sample_index_t* self, mtv_sample_index_entry_t* entry)
{
    kal_int32 ret;

    ret = cached_io_write_pos(&self->cio, self->tail * sizeof(mtv_sample_index_entry_t), entry, sizeof(*entry));
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        return (mtv_result_t)mtv_error_from_fs(ret);
    }

    self->num_written++;

    if (++self->tail >= self->max_index_size) {
        self->tail = 0;
    }
    ASSERT(self->head != self->tail); /* not allow to be full */
    si_sanity_check(self);

    return (mtv_result_t)mtv_error_from_fs(ret);
}

static void si_move_to_head(mtv_sample_index_t* self)
{
    self->next = self->head;
    si_sanity_check(self);
}

static void si_move_to_tail(mtv_sample_index_t* self)
{
    self->next = self->tail;
    si_sanity_check(self);
}

static void si_move_to_next_entry(mtv_sample_index_t* self)
{
    ASSERT(self->max_index_size > 0);

    if (++self->next >= self->max_index_size)
    {
        self->next = 0;
    }

    si_sanity_check(self);
}

static mtv_result_t si_discard_samples(mtv_sample_index_t* self, kal_int32 begin, kal_int32 end, kal_uint32* events)
{
    kal_int32 ret;

	ASSERT(begin <= end);

    *events = 0;

    while (self->head != self->tail)  /* until empty */
    {
        kal_int32 entry_pos;
        mtv_sample_index_entry_t entry;

        entry_pos = self->head * sizeof(mtv_sample_index_entry_t);
        ret = cached_io_read_pos(&self->cio, entry_pos, &entry, sizeof(entry));
        if (ret < 0) {
            return (mtv_result_t)mtv_error_from_fs(ret);
        }

        if (entry.pos < (kal_uint32) begin || entry.pos >= (kal_uint32) end) {
            break;
        }

        if (++self->head >= self->max_index_size) {
            self->head = 0;
        }

		if (si_check_pos(self, self->next) != POS_OK)
		{
            si_move_to_head(self); /* to pass sanity check */

			/*
			 * The writing rate is bigger than the reading rate. We can do
			 * nothing but discarding some samples that will be soonly
			 * overwritten to keep smooth playback for a while.
			 */
			ret = si_move_to_time(self, entry.timestamp + MS_TO_TT(BE_MIN_BUFFER_MS, self), 0, NULL);
            if (ret < 0) {
                return (mtv_result_t)ret;
            }
            ASSERT(si_check_pos(self, self->next) == POS_OK);

            *events |= MTV_BE_EVENT_BOC; /* return this event to the caller */
		}

        si_sanity_check(self);
    }

	return MTV_S_OK;
}

static mtv_result_t si_discard_samples_until(mtv_sample_index_t* self, kal_uint32 target_time)
{
    kal_int32 ret = 0;
    kal_uint32 discarded;
    kal_int32 entry_pos;
    mtv_sample_index_entry_t entry;

    for (discarded = 0; self->head != self->tail; discarded++)  /* until empty */
    {
        entry_pos = self->head * sizeof(mtv_sample_index_entry_t);
        ret = cached_io_read_pos(&self->cio, entry_pos, &entry, sizeof(entry));
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            break;
        }
        else {
            ret = MTV_S_OK;
        }

        if (entry.timestamp >= target_time) {
            break;
        }

        if (++self->head >= self->max_index_size) {
            self->head = 0;
        }
    }

    if (si_check_pos(self, self->next) != POS_OK) {
        si_move_to_head(self); /* to pass sanity check */
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
    }
    si_sanity_check(self);

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_DISCARD_SAMPLES_UNTIL, target_time, entry.timestamp, discarded);

    return (mtv_result_t)ret;
}

static mtv_result_t si_get_first_random_access_point(mtv_sample_index_t* self, mtv_sample_index_entry_t* entry)
{
    kal_uint32 saved_next;
    mtv_result_t ret;

    if (self->head == self->tail) {
        return MTV_E_INVALID_PARAM;
    }

    saved_next = self->next;
    self->next = self->head;

    for (;;)
    {
        ret = si_peek_entry(self, entry);
        if (ret < 0) {
            break;
        }

        if (entry->flags & MTV_PACKET_WITH_RANDOM_ACCESS_POINT) {
            break;
        }

        si_move_to_next_entry(self);
    }

    self->next = saved_next;

    return ret;
}

static void si_reset(mtv_sample_index_t* self)
{
    self->head = 0;
    self->tail = 0;
    self->next = 0;
    self->num_written = 0;

    self->last_timestamp = 0;

    si_sanity_check(self);

	/* it is not necessary to recreate the index file because all pointer are reset */
}

static mtv_result_t si_open_from_file_handle(mtv_sample_index_t* self, FS_HANDLE index_h, mtv_stream_info_t* stream_info, kal_int32 max_index_size, kal_bool use_async_io)
{
    ASSERT(self->index_h >= 0);
    self->index_h = index_h;
    if (cached_io_attach(&self->cio, self->index_h) < 0)
    {
        FS_Close(self->index_h);
        return (mtv_result_t)mtv_error_from_fs(self->index_h);
    }
    if (use_async_io) {
        cached_io_set_async(&self->cio);
    }

    max_index_size /= sizeof(mtv_sample_index_entry_t);
    ASSERT(max_index_size > 0);
    self->max_index_size = max_index_size;

    self->info = *stream_info;
    mtv_copy_dec_config_extra(&self->info.dec_config, &stream_info->dec_config);

    self->get_entry_count = si_get_entry_count;
    self->get_duration = si_get_duration;
    self->move_to_next_entry = si_move_to_next_entry;
    self->peek_entry = si_peek_entry;
    self->move_to_head = si_move_to_head;

    si_reset(self);

    return MTV_S_OK;
}

static mtv_result_t si_open(mtv_sample_index_t* self, kal_wchar* file, mtv_stream_info_t* stream_info, kal_int32 max_index_size, kal_uint32 engine_flags)
{
    kal_bool use_async_io = (engine_flags & MTV_BE_NO_ASYNC_IO) ? KAL_FALSE : KAL_TRUE;
    FS_HANDLE index_h;

    index_h = FS_Open(file, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
    if (index_h < 0) {
        return (mtv_result_t)mtv_error_from_fs(index_h);
    }

    return si_open_from_file_handle(self, index_h, stream_info, max_index_size, use_async_io);
}

static mtv_result_t si_get_info(mtv_sample_index_t* self, mtv_stream_info_t* stream_info)
{
    *stream_info = self->info;

    return MTV_S_OK;
}

static mtv_result_t si_update_info(mtv_sample_index_t* self, mtv_stream_info_t* stream_info)
{
    self->info = *stream_info;

    return MTV_S_OK;
}

typedef struct mtv_be_si_checkpoint_t
{
    kal_int32 head, tail;
    mtv_stream_info_t info;
    kal_int32 max_index_size;

    kal_wchar filename[MAX_FILE_NAME_LEN];

} mtv_be_si_checkpoint_t;

mtv_result_t si_save_checkpoint(mtv_sample_index_t* self, cached_io_t* cp_h)
{
    mtv_be_si_checkpoint_t* si_cp = NULL;
    FS_FileInfo fi;
    kal_int32 ret;

    /* flush all cached content */
    ret = cached_io_flush(&self->cio);
    if (ret < 0) {
        goto cleanup;
    }

    si_cp = (mtv_be_si_checkpoint_t*) mtv_alloc_ext_mem(sizeof(*si_cp), MAKE_FOURCC('S','I','C','P'));

    si_cp->head = self->head;
    si_cp->tail = self->tail;
    si_cp->max_index_size = self->max_index_size;
    si_cp->info = self->info;

    ret = FS_GetFileInfo(self->index_h, &fi);
    if (ret < 0) {
        goto cleanup;
    }
    kal_wstrncpy(si_cp->filename, (kal_wchar*) fi.FullName, ARRAY_SIZE(si_cp->filename) - 1);

    ret = cached_io_write(cp_h, si_cp, sizeof(*si_cp));
    if (ret < 0) {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
    }

cleanup:

    mtv_free_ext_mem((void**) &si_cp);
    return (mtv_result_t)mtv_error_from_fs(ret);
}

static mtv_result_t si_open_from_checkpoint(mtv_sample_index_t* self, cached_io_t* cp_h)
{
    mtv_be_si_checkpoint_t* si_cp = NULL;
    FS_HANDLE index_h = -1;
    kal_int32 ret;

    si_cp = (mtv_be_si_checkpoint_t*) mtv_alloc_ext_mem(sizeof(*si_cp), MAKE_FOURCC('S','I','C','P'));

    ret = cached_io_read(cp_h, si_cp, sizeof(*si_cp));
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    index_h = FS_Open(si_cp->filename, FS_READ_ONLY);
    if (index_h < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, index_h, __LINE__);
        ret = mtv_error_from_fs(index_h);
        goto cleanup;
    }

    ret = si_open_from_file_handle(self, index_h, &si_cp->info, si_cp->max_index_size * sizeof(mtv_sample_index_entry_t), KAL_FALSE);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    self->head = si_cp->head;
    self->tail = si_cp->tail;
    self->next = self->head;

cleanup:

    if (ret < 0 && index_h >= 0)
    {
        if (FS_Close(index_h) >= 0) {
            FS_Delete(si_cp->filename);
        }
    }

    mtv_free_ext_mem((void**) &si_cp);
    return (mtv_result_t)ret;
}

static FS_HANDLE si_create_new_index_file(mtv_sample_index_t* self)
{
    kal_int32 ret;
    FS_FileInfo fi;

    ret = FS_GetFileInfo(self->index_h, &fi);
    if (ret >= 0)
    {
        /* generate a new filename */
        kal_wchar* index_fname = kal_wstrcat(mtv_filename_dup((kal_wchar*)fi.FullName), L"~");
        FS_HANDLE index_h;

        index_h = FS_Open(index_fname, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
        mtv_free_ext_mem((void**)&index_fname);

        return index_h;
    }

    return -1;
}

/**
  * Remove empty space in stream index file.
  */
static mtv_result_t si_compact(mtv_sample_index_t* self)
{
    kal_int32 ret;
    kal_int32 entry_count = si_get_entry_count(self);
    kal_int32 next = self->next >= self->head ? self->next - self->head : self->max_index_size - self->head + self->next;
    FS_HANDLE index_h;

    ASSERT(self->head > self->tail);

    index_h = si_create_new_index_file(self);
    if (index_h < 0) {
        return (mtv_result_t)mtv_error_from_fs(index_h);
    }

    /*
     * |======*=======|------------|=============|
     * 0     next    tail         head     max_index_size
     *
     * becomes
     *
     * |==================*========|-------------|
     * head              next     tail
     */

    ret = copy_file_region(index_h, &self->cio,
		self->head * sizeof(mtv_sample_index_entry_t),
		(self->max_index_size - self->head) * sizeof(mtv_sample_index_entry_t));
    if (ret < 0)
    {
        mtv_close_file(index_h, KAL_TRUE);
        return (mtv_result_t)ret;
    }

    ret = copy_file_region(index_h, &self->cio,
		0, self->tail * sizeof(mtv_sample_index_entry_t));
    if (ret < 0)
    {
        mtv_close_file(index_h, KAL_TRUE);
        return (mtv_result_t)ret;
    }

    ret = cached_io_detach(&self->cio);
    if (ret < 0) {
        return (mtv_result_t)mtv_error_from_fs(ret);
    }

    mtv_close_file(self->index_h, KAL_TRUE);

    self->index_h = index_h;
    self->head = 0;
    self->tail = entry_count;
    self->next = next;

    ret = cached_io_attach(&self->cio, self->index_h);
    if (ret < 0)
    {
        mtv_close_file(self->index_h, KAL_TRUE);
        return (mtv_result_t)mtv_error_from_fs(ret);
    }

    cached_io_set_async(&self->cio);

	si_sanity_check(self);

    return MTV_S_OK;
}

static mtv_result_t si_set_maximum_size(mtv_sample_index_t* self, kal_int32 max_index_size)
{
	mtv_result_t ret;

    max_index_size /= sizeof(mtv_sample_index_entry_t);

    /* only allow increasing */
    if (max_index_size <= self->max_index_size) {
        return MTV_E_INVALID_PARAM;
    }

    if (self->head <= self->tail)
    {
        /*
         * |-------|==========================|------|################|
         * 0      head                       tail      increased part
         *  ^^^^^^^ head empty space
         */

        /*
         * simply increase the maximum size and assume the head empty space is small and
         * will not waste too much space.
         */
    }
    else
    {
        /*
         * |==============|------------|=============|################|
         * 0             tail         head         max_index_size
         */
        ret = si_compact(self);
        if (ret < 0) {
            return ret;
        }
    }

    self->max_index_size = max_index_size;

    return MTV_S_OK;
}

static mtv_result_t si_close(mtv_sample_index_t* self, kal_bool discard_files)
{
    if (self->index_h >= 0)
    {
        cached_io_detach(&self->cio);

        mtv_close_file(self->index_h, discard_files);
        self->index_h = -1;

        mtv_free_dec_config_extra(&self->info.dec_config);
    }

    return MTV_S_OK;
}

/* buffer engine operations */

static void mtv_be_set_read_state(mtv_buffer_engine_t* self, mtv_buffer_engine_read_state_t read_state)
{
    if (self->read_state != read_state)
    {
        mtv_buffer_engine_read_state_t old_state = self->read_state;

        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_STATE, read_state);
        self->read_state = read_state;

        if (self->client) {
            self->client->on_read_state_change(self->client, old_state, self->read_state);
        }
    }
}

static kal_uint32 mtv_be_calc_free_space_kb(const kal_wchar* dir)
{
    FS_DiskInfo di;
    kal_int32 ret;

    /* get disk free space */
    ret = FS_GetDiskInfo(dir, &di, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
    if (ret < 0) {
        return 0;
    }

    return (kal_uint32)((kal_uint64) di.FreeClusters * di.SectorsPerCluster * di.BytesPerSector / 1024);
}

#define SS_PORTION_NUM 7
#define SS_PORTION_DEN 16

static kal_uint32 mtv_be_calc_stream_buffer_kb(kal_uint32 free_kb)
{
    return free_kb * SS_PORTION_NUM / SS_PORTION_DEN;
}

static mtv_result_t mtv_be_check_min_space_requirement(kal_uint32 free_kb, kal_uint32 bitrate, kal_uint32 seconds)
{
    kal_uint32 required_kb, min_ss_kb;

    required_kb = bitrate * seconds / 8;
    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_CHECK_DISK_SPACE, required_kb, free_kb);

    /* check with estimated bitrate and required duration */
    if (free_kb < required_kb) {
        return MTV_E_FAIL;
    }

    /* check minimum size limitation of sample stream buffer */
    min_ss_kb = mtv_be_calc_stream_buffer_kb(free_kb);
    if (min_ss_kb < MIN_SAMPLE_STREAM_SIZE / 1024) {
        return MTV_E_FAIL;
    }

    return MTV_S_OK;
}

static kal_uint32 mtv_be_calc_free_space_check_interval(kal_uint32 free_kb)
{
    if (free_kb >= 16 * 1024) /* 16 MB */ {
        return 1 * 1024 * 1024; /* 1 MB */
    }
    else if (free_kb >= 4 * 1024) /* 4 MB */ {
        return 512 * 1024; /* 512 KB */
    }
    else if (free_kb >= 2 * 1024) /* 2 MB */ {
        return 256 * 1024;  /* 256 KB */
    }
    else {
        return 128 * 1024;  /* 128 KB */
    }
}

static mtv_result_t mtv_be_open(mtv_buffer_engine_t* self, mtv_buffer_engine_client_t* client, mtv_buffer_engine_config_t* config)
{
    mtv_result_t ret;
    kal_wchar* stream_path;
    kal_uint32 free_kb;
    kal_uint32 max_ss_kb;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_OPEN);

    free_kb = mtv_be_calc_free_space_kb(config->storing_dir);

    /* the free disk space should at least allows specified duration of recording */
    if (mtv_be_check_min_space_requirement(free_kb, config->estimated_bitrate, MTV_MIN_DURATION_FOR_TIMESHIFT * 2) < 0)
    {
        ret = MTV_IO_E_DISK_FULL;
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        return ret;
    }
    else
    {
        self->free_space_check_interval = mtv_be_calc_free_space_check_interval(free_kb);
    }

    /* the time-shift buffer size should be bounded by available disk space */
    max_ss_kb = mtv_be_calc_stream_buffer_kb(free_kb);
    if (config->max_buffer_kb < max_ss_kb) {
        max_ss_kb = config->max_buffer_kb;
    }

    self->client = client;
	self->engine_flags = config->flags;
    self->estimated_bitrate = config->estimated_bitrate;
    self->discard_policy = MTV_BE_DISCARD_FILES_AFTER_CLOSE;

    kal_wstrncpy(self->storing_dir, config->storing_dir, ARRAY_SIZE(self->storing_dir) - 1);

    /* create sample stream */
    stream_path = mtv_generate_new_filename(config->storing_dir, AV_STREAM_PREFIX, L"");
    ret = ss_open(&self->ss, stream_path, max_ss_kb * 1024, self->engine_flags);
    mtv_free_ext_mem((void**)&stream_path);
    if (ret < 0) {
        return ret;
    }

    self->num_incoming = 0;
    self->bytes_read = self->bytes_written = self->last_space_check = 0;

    self->packet_buffer_size = 0;
    self->packet_buffer = NULL;

    mtv_be_set_read_state(self, MTV_BE_READ_LIVE);
    self->delay_ms = 0;

    self->validation_info.signature = MAKE_FOURCC('S', 'E', 'N', 'D');

    return MTV_S_OK;
}

static mtv_result_t mtv_be_add_stream(mtv_buffer_engine_t* self, mtv_stream_info_t* stream_info)
{
    mtv_result_t ret;
    kal_wchar* index_path;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_ADD_STREAM, stream_info->type);

    if (self->num_streams >= ARRAY_SIZE(self->si))
    {
        SHOULD_NOT_HAPPEN("Too many buffered streams!");
        return  MTV_E_RESOURCE_CONFLICT;
    }

    if (stream_info->type == MTV_STREAM_AUDIO) {
        index_path = mtv_generate_new_filename(self->storing_dir, AUDIO_INDEX_PREFIX, L"");
    }
    else if (stream_info->type == MTV_STREAM_VIDEO) {
        index_path = mtv_generate_new_filename(self->storing_dir, VIDEO_INDEX_PREFIX, L"");
    }
    else
    {
        NOT_REACHED("Unhandled stream type!");
        return MTV_E_FAIL;
    }

    /* create sample index */
    ret = si_open(&self->si[self->num_streams], index_path, stream_info, ss_get_maximum_size(&self->ss) / STREAM_TO_SAMPLE_RATIO, self->engine_flags);
    if (ret >= 0) {
        self->num_streams++;
    }

    mtv_free_ext_mem((void**)&index_path);

    return ret;
}

static mtv_result_t mtv_be_get_stream_info(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_stream_info_t* stream_info)
{
    mtv_result_t ret;
    mtv_sample_index_t *si;

    ASSERT(stream_index <= self->num_streams);

    si = &self->si[stream_index];

    ret = si_get_info(si, stream_info);

    return ret;
}

static mtv_result_t mtv_be_update_stream_info(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_stream_info_t* stream_info)
{
    mtv_result_t ret;
    mtv_sample_index_t *si;


    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_UPDATE_STREAM_INFO, stream_index, stream_info->type);

    ASSERT(stream_index <= self->num_streams);

    si = &self->si[stream_index];

    ASSERT(si->info.type == stream_info->type);

    ret = si_update_info(si, stream_info);

    return ret;
}

static mtv_result_t mtv_discard_written_ranges(mtv_buffer_engine_t* self, kal_int32 num_rgn, mtv_region_t* rgn, kal_uint32* events)
{
	mtv_result_t ret = MTV_S_OK;
	kal_int32 i, j;
    kal_int32 errors = 0;

    *events = 0;

	/* check each stream to discard overwritten samples */
    for (i = 0; i < self->num_streams; i++)
    {
        for (j = 0; j < num_rgn; j++)
        {
            kal_uint32 si_events;
			ret = si_discard_samples(&self->si[i], rgn[j].head, rgn[j].tail, &si_events);
            if (ret < 0) {
                errors++;
            }

            *events |= si_events;
        }
    }

	return errors == 0 ? MTV_S_OK : MTV_E_FAIL;
}

static void* mtv_be_get_packet_buffer(mtv_buffer_engine_t* self, kal_uint32 size)
{
    if (size > MTV_MAX_MEDIA_SAMPLE_SIZE) {
        return NULL;
    }

    if (size > self->packet_buffer_size)
    {
        mtv_free_ext_mem(&self->packet_buffer);
        self->packet_buffer = mtv_alloc_ext_mem(size, MAKE_FOURCC('B','E','P','B'));

        self->packet_buffer_size = size;
    }

    return self->packet_buffer;
}

typedef struct
{
    kal_int32 num_parts;
    mtv_packet_t parts[3];
    kal_uint32 flags;

} mtv_be_wrapped_packet_t;

/**
  * Wrap the packet data into the format to be written to buffer stream. The output will be
  * byte stream consisting of one or more parts (packets). When wrapped data is read from
  * buffer stream, mtv_be_unwrap_packet will be called to unwrap the data.
  *
  * @param si [in] sample index
  * @param packet [in] the input packet
  * @param num_parts [out] the part count of wrapped data
  * @param parts [out] the array for parts pf wrapped data
  */
static mtv_result_t mtv_be_wrap_packet(mtv_buffer_engine_t* self, mtv_sample_index_t* si, mtv_packet_t* packet, mtv_be_wrapped_packet_t* wp)
{
    ASSERT(packet->size > 0);

    wp->flags = packet->flags;

    if (si->info.dec_config.codec == MTV_CODEC_H264)
    {
        /*
         * append NALU length according to 14496-15 5.2.3
         *
         * +------------+-----------------------------+------------+-----------------+
         * | 4-byte len | ...                         | 4-byte len | ...             |
         * +------------+-----------------------------+------------+-----------------+
         */

        /* use packet_buffer temporarily for storage of packet header */
        kal_uint32* nalu_size = (kal_uint32*) mtv_be_get_packet_buffer(self, 4);

        if (packet->flags & MTV_PACKET_AGGREGATION)
        {
            wp->num_parts = 1;
            wp->parts[0].data = packet->data;
            wp->parts[0].size = packet->size;
        }
        else if (packet->flags & MTV_PACKET_WITH_H264_START_CODE)
        {
            /*
             * Cyberlink demux will always append H.264 start code in the packet. However,
             * the start code is not needed for time-shifting buffer and MP4 recording.
             * Therefore, skip the start code.
             */
            *nalu_size = packet->size - 4;

            wp->parts[1].data = packet->data + 4;
            wp->parts[1].size = *nalu_size;

            *nalu_size = ENDIAN_FLIP(*nalu_size);
            wp->parts[0].data = (kal_uint8*) nalu_size;
            wp->parts[0].size = H264_NALU_LENGTH_SIZE;

            wp->num_parts = 2;
        }
        else
        {
            /* write 4-byte NALU length before the NALU */
            *nalu_size = ENDIAN_FLIP(packet->size);
            wp->parts[0].data = (kal_uint8*) nalu_size;
            wp->parts[0].size = H264_NALU_LENGTH_SIZE;

            wp->parts[1].data = packet->data;
            wp->parts[1].size = packet->size;

            wp->num_parts = 2;
        }
    }
    else if (si->info.type == MTV_STREAM_AUDIO)
    {
        if (si->info.dec_config.codec == MTV_CODEC_DRA)
        {
            kal_uint32 i;

            /* use packet_buffer temporarily for storage of sync byte */
            kal_uint8* dra_data = (kal_uint8*) mtv_be_get_packet_buffer(self, packet->size);

            /* swap byte order for file storage */
            for (i = 0; i < packet->size; i += 2)
            {
                dra_data[i] = packet->data[i + 1];
                dra_data[i + 1] = packet->data[i];
            }

            wp->parts[0].data = dra_data;
            wp->parts[0].size = packet->size;

            /* assume every audio packet is a random access point */
            packet->flags |= MTV_PACKET_WITH_RANDOM_ACCESS_POINT;

            wp->num_parts = 1;
        }
        else
        {
            wp->parts[0].data = packet->data;
            wp->parts[0].size = packet->size;

            /* assume every audio packet is a random access point */
            packet->flags |= MTV_PACKET_WITH_RANDOM_ACCESS_POINT;

            wp->num_parts = 1;
        }
    }
    else
    {
        wp->parts[0].data = packet->data;
        wp->parts[0].size = packet->size;

        wp->num_parts = 1;
    }

    if (self->engine_flags & MTV_BE_VALIDATE_PACKET)
    {
        wp->parts[wp->num_parts].data = (kal_uint8*) &self->validation_info;
        wp->parts[wp->num_parts].size = sizeof(self->validation_info);
        wp->num_parts++;

        packet->flags |= MTV_SAMPLE_INDEX_ENTRY_HAS_VALIDATION_INFO;
    }

    return MTV_S_OK;
}

/**
  * Unwrap packet data read from buffer stream.
  *
  * @param si [in] the sample index for packet data
  * @param packet [in][out] the unwrap will be done in-place
  */
static mtv_result_t mtv_be_unwrap_packet(mtv_buffer_engine_t* self, mtv_sample_index_t* si, mtv_packet_t* packet)
{
    if (si->info.dec_config.codec == MTV_CODEC_H264)
    {
        if (packet->flags & MTV_PACKET_WITH_H264_START_CODE)
        {
            /* patch the NALU length back to H.264 start code */
            packet->data[0] = 0; packet->data[1] = 0; packet->data[2] = 0; packet->data[3] = 1;
        }
    }
    else if (si->info.type == MTV_STREAM_AUDIO)
    {
        if (si->info.dec_config.codec == MTV_CODEC_DRA)
        {
            kal_uint32 i;
            kal_uint8 temp;
            kal_uint8* dra_data = packet->data;

            /* swap byte order for playback */
            for (i = 0; i < packet->size; i += 2)
            {
                temp = dra_data[i];
                dra_data[i] = dra_data[i + 1];
                dra_data[i + 1] = temp;
            }
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        return MTV_E_FAIL;  /* unsupported format */
    }

    if (packet->flags & MTV_SAMPLE_INDEX_ENTRY_HAS_VALIDATION_INFO)
    {
        if (self->engine_flags & MTV_BE_VALIDATE_PACKET)
        {
            kal_uint8* to_check = packet->data + packet->size - sizeof(self->validation_info);
            ASSERT(kal_mem_cmp(to_check, &self->validation_info, sizeof(self->validation_info)) == 0);
        }

        packet->size -= sizeof(self->validation_info);
    }

    return MTV_S_OK;
}

static void mtv_be_start_congestion_control(mtv_buffer_engine_t* self)
{
    self->throttle = 256 * 1024;
    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_START_CONGESTION_CONTROL, self->throttle);
}

static mtv_result_t mtv_be_write_packet_core(mtv_buffer_engine_t* self, mtv_sample_index_t* si, mtv_packet_t* packet, kal_uint32 timestamp, kal_uint32* events)
{
    mtv_result_t ret;
    ss_sample_location_t location;
    mtv_be_wrapped_packet_t wp;
    kal_bool slow_writing;

    /* wrap the packet to be the format saved in buffer stream */
    ret = mtv_be_wrap_packet(self, si, packet, &wp);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        return ret;
    }

	/* write sample to AV stream */
    while (1)
    {
        ret = ss_write_buffer(&self->ss, wp.num_parts, wp.parts, &location);
        if (ret < 0)
        {
            if (ret == mtv_error_from_fs(FS_OUT_OF_BUFFERS))
            {
#ifdef __MTK_TARGET__
                mtv_be_start_congestion_control(self);
                self->num_dropped++;
                return MTV_S_FALSE;
#else
                kal_sleep_task(10);
                continue;
#endif
            }

            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            return ret;
        }

        slow_writing = (ret == MTV_S_SLOW) ? KAL_TRUE : KAL_FALSE;
        break;
    }

	/* check each stream to discard overwritten samples */
    ASSERT(location.num_rgn > 0);
	ret = mtv_discard_written_ranges(self, location.num_rgn, location.rgn, events);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        return ret;
    }

    if (slow_writing) {
#ifdef __MTK_TARGET__
        mtv_be_start_congestion_control(self);
#endif
    }

    switch (self->read_state)
    {
    case MTV_BE_READ_LIVE:
        si_move_to_tail(si);
        break;

    case MTV_BE_READ_PAUSED:
    case MTV_BE_READ_DELAYED:
    case MTV_BE_READ_PREBUFFERING:
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }

   	/* update sample index */
   	{
        mtv_sample_index_entry_t entry;

        entry.pos = location.pos;

        /* note that sample_size may not be equal to packet->size
           if some additional info is added such as NALU length for
           H.264 bitstream. */
        entry.size = location.size;
        self->bytes_written += location.size;

        entry.timestamp = timestamp;
        entry.flags = wp.flags;

        ret = si_add_entry(si, &entry);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            return ret;
        }
   	}

    return ret;
}

typedef struct mtv_be_write_packet_context_t
{
    mtv_buffer_engine_t* be;
    mtv_sample_index_t* si;
    mtv_packet_t* packet;
    mtv_source_stat_t* src_stat;
    kal_uint32* events;

} mtv_be_write_packet_context_t;

static void mtv_be_deliver_concealment_callback(void* param, mtv_packet_t* au)
{
    mtv_be_write_packet_context_t* ctx = (mtv_be_write_packet_context_t*) param;
    kal_uint32 timestamp;

    /*
     * (normalized)                 au->timestamp           src_stat->max_timestamp
     * last_timestamp                     |                           |
     *        |=============|*************|*************|*************|=============|
     *        |                                                       |
     *        |<----------------------- delta ----------------------->|
     */
    timestamp = ctx->si->last_timestamp + (ctx->src_stat->delta) - (ctx->src_stat->max_timestamp - au->timestamp);

    mtv_be_write_packet_core(ctx->be, ctx->si, au, timestamp, ctx->events);
}

static mtv_result_t mtv_be_write_packet(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_packet_t* packet, kal_uint32* events, mtv_source_stat_t* src_stat)
{
    mtv_result_t ret;
    kal_uint32 timestamp;
    mtv_sample_index_t* si = &self->si[stream_index];

    ASSERT(stream_index < (kal_uint32) self->num_streams);

    *events = 0;

    self->num_incoming++;

    if (self->throttle > 0 &&
        /* don't discard video I-frame to reduce visual defects */
        (si->info.type != MTV_STREAM_VIDEO || !(packet->flags & MTV_PACKET_WITH_RANDOM_ACCESS_POINT)))
    {
        self->num_dropped++;

        self->throttle -= packet->size;
        if (self->throttle <= 0) {
            MTV_TRACE(TRACE_INFO, MTV_TRC_BE_TOTOAL_DROP, self->num_dropped);
        }
        return MTV_S_FALSE;
    }
    else if (self->bytes_written - self->last_space_check >= self->free_space_check_interval)
    {
        kal_uint32 free_kb = mtv_be_calc_free_space_kb(self->storing_dir);

        self->last_space_check = self->bytes_written;

        if ((self->engine_flags & MTV_BE_SEQUENTIAL_OUTPUT) != 0 && self->ss.num_rgn >= 3)
        {
            kal_uint32 stream_kb = ss_get_size(&self->ss) / 1024;

            if (stream_kb * SS_PORTION_DEN >= free_kb * SS_PORTION_NUM)
            {
                /* try to prevent using more disk space */
                if (ss_wrap_around_now(&self->ss) < 0) {
                    return MTV_IO_E_DISK_FULL;
                }
            }
        }
        else
        {
            /* abort the writing if the free space is not enough */
            if (mtv_be_check_min_space_requirement(free_kb, self->estimated_bitrate, MTV_MIN_DURATION_FOR_TIMESHIFT) < 0)
            {
                /* try to prevent using more disk space */
                if (ss_wrap_around_now(&self->ss) < 0) {
                    return MTV_IO_E_DISK_FULL;
                }
            }
        }

        self->free_space_check_interval = mtv_be_calc_free_space_check_interval(free_kb);
    }

    if (src_stat->loss > 0 &&
        /* only do concealment for loss under predefined threshold */
        src_stat->loss * src_stat->au_duration < MTV_AUDIO_CONCEALMENT_THRESHOLD * si->info.dec_config.timestamp_resolution)
    {
        mtv_be_write_packet_context_t ctx;

        ctx.be = self;
        ctx.si = si;
        ctx.packet = packet;
        ctx.events = events;
        ctx.src_stat = src_stat;
        mtv_deliver_audio_concealment(src_stat, &si->info.dec_config, mtv_be_deliver_concealment_callback, &ctx);
    }

    timestamp = (si->num_written == 0) ? 0 : si->last_timestamp + src_stat->delta;
    ret = mtv_be_write_packet_core(self, si, packet, timestamp, events);
    if (ret == MTV_S_OK)
    {
        /* add the delta as the the next sample timestamp */
        si->last_timestamp = timestamp;
    }

    return ret;
}

static mtv_result_t mtv_be_read_next_index_entry(mtv_buffer_engine_t* self, kal_uint32* stream_index, mtv_sample_index_entry_t* entry)
{
    mtv_result_t ret;
    kal_int32 i;
    kal_int32 stream = -1;
    kal_int32 min_offset = 0x7fffffff;

    /* find the stream that contains this sample */
    for (i = 0; i < self->num_streams; i++)
    {
        mtv_sample_index_entry_t en;

retry_next_entry:
        ret = si_peek_entry(&self->si[i], &en);
		if (ret >= 0)
		{
			kal_int32 offset = ss_calc_offset(&self->ss, en.pos);
            if (offset < 0)
            {
                /* it looks like entry content is corrupted. skip it!*/
                si_move_to_next_entry(&self->si[i]);
                goto retry_next_entry;
            }

			if (offset <= min_offset)
			{
				min_offset = offset;
				*entry = en;
				stream = i;
			}
		}
    }

    if (stream < 0) {
        return MTV_E_FAIL;  /* no packet is available */
    }

    *stream_index = stream;
    si_move_to_next_entry(&self->si[stream]);

    return MTV_S_OK;
}

static mtv_result_t mtv_be_read_packet(mtv_buffer_engine_t* self, kal_uint32* stream_index, mtv_packet_t* packet)
{
    mtv_result_t ret;
	mtv_sample_index_entry_t entry;
    kal_uint8* packet_buffer;

    if (self->read_state != MTV_BE_READ_DELAYED && self->read_state != MTV_BE_READ_PREBUFFERING)
    {
        return MTV_E_FAIL;
    }

    for (;;)
    {
        ret = mtv_be_read_next_index_entry(self, stream_index, &entry);
        if (ret < 0) {
            break;
        }

        ASSERT(*stream_index < (kal_uint32) self->num_streams);

        /* read the sample into packet buffer */
        packet_buffer = mtv_be_get_packet_buffer(self, entry.size);
        if (packet_buffer == NULL || entry.size == 0)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_BE_INVALID_SAMPLE_ENTRY, *stream_index, entry.size);
            continue;
        }

        ret = ss_read_sample(&self->ss, entry.pos, packet_buffer, entry.size);
        if (ret >= 0)
        {
            packet->data = packet_buffer;
            packet->flags = entry.flags;
            packet->size = entry.size;
            packet->timestamp = entry.timestamp;

            self->bytes_read += entry.size;

            ret = mtv_be_unwrap_packet(self, &self->si[*stream_index], packet);
        }

        break;
    }

    return ret;
}

static mtv_result_t mtv_be_read_packet_from_stream(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_packet_t* packet)
{
    mtv_result_t ret;
	mtv_sample_index_entry_t entry;
    mtv_sample_index_t* si = &self->si[stream_index];
    kal_uint8* packet_buffer;

    ASSERT(stream_index < (kal_uint32) self->num_streams);

    for (;;)
    {
        ret = si_peek_entry(si, &entry);
        if (ret < 0) {
            break;
        }
        si_move_to_next_entry(si);

        /* read the sample into packet buffer */
        packet_buffer = mtv_be_get_packet_buffer(self, entry.size);
        if (packet_buffer == NULL || entry.size == 0)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_BE_INVALID_SAMPLE_ENTRY, stream_index, entry.size);
            continue; /* skip this entry */
        }

        ret = ss_read_sample(&self->ss, entry.pos, packet_buffer, entry.size);
        if (ret >= 0)
        {
            packet->data = packet_buffer;
            packet->flags = entry.flags;
            packet->size = entry.size;
            packet->timestamp = entry.timestamp;

            ret = mtv_be_unwrap_packet(self, si, packet);
        }

        break;
    }

    return ret;
}

static mtv_result_t mtv_be_translate_to_stream_time(mtv_buffer_engine_t* self, kal_uint32 stream_index, mtv_source_stat_t* src_stat, kal_uint32* timestamp)
{
    mtv_sample_index_t* si = &self->si[stream_index];

    ASSERT(stream_index < (kal_uint32) self->num_streams);

    *timestamp = src_stat->max_timestamp - (si->last_timestamp - *timestamp);

    return MTV_S_OK;
}

static mtv_result_t mtv_be_discard_all(mtv_buffer_engine_t* self)
{
	kal_int32 i;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_DISCARD_ALL);

    ss_reset(&self->ss);

    for (i = 0; i < self->num_streams; i++) {
        si_reset(&self->si[i]);
    }

    switch (self->read_state)
    {
    case MTV_BE_READ_DELAYED:
    case MTV_BE_READ_PAUSED:
    case MTV_BE_READ_PREBUFFERING:
        /* switch to live mode because there is no buffered content */
        mtv_be_set_read_state(self, MTV_BE_READ_LIVE);
        break;

    case MTV_BE_READ_LIVE:
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_set_discard_policy(mtv_buffer_engine_t* self, mtv_buffer_engine_discard_policy_t policy)
{
    self->discard_policy = policy;
    return MTV_S_OK;
}

static mtv_result_t mtv_be_disable_wrap_around(mtv_buffer_engine_t* self)
{
    ss_disable_wrap_around(&self->ss);
    return MTV_S_OK;
}

static mtv_result_t mtv_be_close_core(mtv_buffer_engine_t* self, kal_bool discard_files)
{
	mtv_result_t ret;
	kal_int32 i;
    kal_int32 errors = 0;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_CLOSE, discard_files);

    ret = ss_close(&self->ss, discard_files);
    if (ret < 0) {
        errors++;
    }

    for (i = 0; i < self->num_streams; i++)
    {
        ret = si_close(&self->si[i], discard_files);
        if (ret < 0) {
            errors++;
        }
    }
    self->num_streams = 0;

    mtv_free_ext_mem(&self->packet_buffer);
    self->packet_buffer_size = 0;

    return MTV_S_OK; /* return OK even when errors happened */
}

static mtv_result_t mtv_be_close(mtv_buffer_engine_t* self)
{
    return mtv_be_close_core(self, (kal_bool)(self->discard_policy == MTV_BE_DISCARD_FILES_AFTER_CLOSE));
}

static mtv_result_t mtv_be_prepare_saving(mtv_buffer_engine_t * self)
{
    kal_int32 i, j;
    mtv_result_t ret;
    mtv_sample_index_entry_t rap;

    for (i = 0; i < self->num_streams; i++)
    {
        if (self->si[i].info.type == MTV_STREAM_VIDEO)
        {
            mtv_sample_index_t* video_track = &self->si[i];

            /* find the first video random access point */
            ret = si_get_first_random_access_point(video_track, &rap);
            if (ret < 0)
            {
                MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
                return ret;
            }

            /*
             * Discard all samples before the point so that the first video frame is RAP
             * and audio samples can sync with it.
             */
            for (j = 0; j < self->num_streams; j++)
            {
                mtv_sample_index_t* si = &self->si[j];
                kal_uint32 first_timestamp = rap.timestamp;

                if (si != video_track) {
                    first_timestamp = (kal_uint32)((kal_uint64) first_timestamp *
                                                   si->info.dec_config.timestamp_resolution /
                                                   video_track->info.dec_config.timestamp_resolution);
                }

                MTV_TRACE(TRACE_INFO, MTV_TRC_BE_DISCARD_SAMPLES_IN_STREAM, j, first_timestamp);
                //mtv_prompt_trace(MOD_MED, "[MTV][BE] discard samples in stream #%d until %u", j, first_timestamp);
                ret = si_discard_samples_until(si, first_timestamp);
                if (ret < 0)
                {
                    MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
                    return ret;
                }
            }

            break;
        }
    }

    return MTV_S_OK;
}

kal_bool mtv_be_is_recoverable_error(mtv_result_t error)
{
    switch (error)
    {
    case MTV_IO_E_DISK_FULL:
    case MTV_IO_E_ROOT_DIR_FULL:
    case MTV_E_ABORTED:
        return KAL_TRUE;

    default:
        return KAL_FALSE;
    }
}

static mtv_result_t mtv_be_save(mtv_buffer_engine_t* self, mtv_recording_format_t format, kal_wchar* output_file, volatile kal_bool* aborted, kal_uint32 flags)
{
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SAVING);

    /* need to adjust each stream before it can be saved */
    ret = mtv_be_prepare_saving(self);
    if (ret < 0) {
        return ret;
    }

    if (format == MTV_RECORDING_FORMAT_MP4 || format == MTV_RECORDING_FORMAT_3GP)
    {
        kal_uint32 mp4_output_flags = 0;

        if (flags & MTV_BE_ADD_DRM_HEADER_FOOTER) {
            mp4_output_flags |= MP4_OUTPUT_ADD_DRM_HEADER_FOOTER;
        }

        if (flags & MTV_BE_HIDE_OUTPUT_FILE) {
            mp4_output_flags |= MP4_OUTPUT_AS_HIDDEN_FILE;
        }

        if (flags & MTV_BE_AAC_SBR_ENABLED) {
            mp4_output_flags |= MP4_OUTPUT_AAC_SBR_ENABLED;
        }

        ret = mtv_convert_to_mp4(output_file, self->num_streams, self->si, &self->ss, mp4_output_flags, aborted);
    }
    else if (format == MTV_RECORDING_FORMAT_MP2)
    {
        ASSERT(self->num_streams == 1);
        ret = mtv_convert_to_mp2(output_file, &self->si[0], &self->ss, aborted);
    }
    else if (format == MTV_RECORDING_FORMAT_WAV)
    {
        ASSERT(self->num_streams == 1);
        ret = mtv_convert_to_wav(output_file, &self->si[0], &self->ss, aborted);
    }
    else
    {
        NOT_REACHED("Invalid recording format is specified?!");
        ret = MTV_E_INVALID_PARAM;
    }

    if (mtv_be_is_recoverable_error(ret))
    {
        /* we may still have chance to recover it again */
        mtv_be_close_core(self, KAL_FALSE);
    }
    else
    {
        /* close itself because its bufffer file has gone and can't be used anymore */
        mtv_be_close_core(self, KAL_TRUE);
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SAVED);
    return ret;
}

static mtv_result_t mtv_be_get_control(mtv_buffer_engine_t* self, mtv_control_t control_id, void** control)
{
    if (control_id == MTV_CONTROL_TIMESHIFT)
    {
        *control = &self->timeshift_ctrl;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t mtv_be_seek_by_time(mtv_buffer_engine_t* self, kal_uint32 target_time)
{
    kal_int32 i;
    mtv_result_t ret;
    kal_int32 moved = 0;
    kal_int32 seeked_stream = -1;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SEEK_BY_TIME, target_time);

    /* seek in video stream first */
    for (i = 0; i < self->num_streams; i++)
    {
        if (self->si[i].info.type == MTV_STREAM_VIDEO)
        {
            ret = si_move_to_time(&self->si[i], target_time, MTV_PACKET_WITH_RANDOM_ACCESS_POINT, &target_time);
            if (ret >= 0)
            {
                seeked_stream = i;
                moved++;
            }

            break;
        }
    }

    /* and then other streams */
    for (i = 0; i < self->num_streams; i++)
    {
        if (i != seeked_stream)
        {
            ret = si_move_to_time(&self->si[i], target_time, 0, NULL);
            if (ret >= 0) {
                moved++;
            }
        }
    }

    if (moved <= 0)
    {
        /* no stream contains the specified target time */
        return MTV_E_INVALID_PARAM;
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_set_prebuffering(mtv_control_timeshift_t* control, kal_bool change_state)
{
    mtv_buffer_engine_t* self = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);
    mtv_result_t ret;
    kal_uint32 max_delay_ms = 0;
    kal_uint32 target_time;
    kal_int32 dominant_track;
    mtv_sample_index_t* si;

    if (self->num_streams < 1) {
        return MTV_E_FAIL;
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SET_PREBUFFERING);

    ret = mtv_be_timeshift_get_buffer_status_ex(control, &max_delay_ms, NULL, &dominant_track);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
        goto set_prebuffering_cleanup;
    }

    /* Use timestamp information of dominate (longest) track */
    ASSERT(dominant_track >= 0 && dominant_track < self->num_streams);
    si = &self->si[dominant_track];

    /*
     * To reduce the duration of decoder stop from DELAYED to LIVE, we need to back off for
     * a little time so that decoder buffers can be filled quickly and therefore playback
     * can be started in short time.
     *
     * However, the back-off time cannot large than the capacity of decoder buffer so that
     * we can drian the stream buffer and go to real LIVE mode.
     */

    if (max_delay_ms <= BE_LIVE_BACK_OFF_MS)
    {
        /* go to beginning if there is not enough back-off distance */
        ret = si_get_first_timestamp(si, &target_time);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
            goto set_prebuffering_cleanup;
        }
    }
    else
    {
        kal_uint32 last_timestamp;

        ret = si_get_last_timestamp(si, 1, &last_timestamp);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
            goto set_prebuffering_cleanup;
        }

        target_time = last_timestamp - MS_TO_TT(BE_LIVE_BACK_OFF_MS, si);
    }

    ret = mtv_be_seek_by_time(self, target_time);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
        goto set_prebuffering_cleanup;
    }

    if (change_state)
    {
        mtv_be_set_read_state(self, MTV_BE_READ_PREBUFFERING);
    }

set_prebuffering_cleanup:

    return ret;
}

static mtv_result_t mtv_be_timeshift_set_delay(mtv_control_timeshift_t* control, kal_uint32 delay_ms)
{
    mtv_buffer_engine_t* self = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);
    mtv_result_t ret;
    kal_uint32 max_delay_ms = 0;
    kal_uint32 applied_delay_ms = delay_ms;
    kal_uint32 target_time;
    kal_int32 dominant_track;
    mtv_sample_index_t* si;

    if (self->num_streams < 1) {
        return MTV_E_FAIL;
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SET_DELAY, delay_ms);

    ret = mtv_be_timeshift_get_buffer_status_ex(control, &max_delay_ms, NULL, &dominant_track);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
        goto set_delay_cleanup;
    }

    /* Use timestamp information of dominate (longest) track */
    ASSERT(dominant_track >= 0 && dominant_track < self->num_streams);
    si = &self->si[dominant_track];

    if (delay_ms != 0) /* delayed playback */
    {
        kal_uint32 last_timestamp;

        if (max_delay_ms < BE_MIN_BUFFER_MS)
        {
            /*
             * not allow to seek if there are too few content in the buffer.
             * this checking is used to guarantee the delay time can be calculated correctly.
             */
            ret = MTV_E_FAIL;
            MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
            goto set_delay_cleanup;
        }

        /* check if very close to live? */
        if (delay_ms < BE_LIVE_BACK_OFF_MS)
        {
            /* prevent waiting for live signal, start by backoff position */
            applied_delay_ms = BE_LIVE_BACK_OFF_MS;

            ret = mtv_be_timeshift_set_prebuffering(control, KAL_FALSE);
            if (ret < 0)
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
                goto set_delay_cleanup;
            }
            else if (self->client)
            {
                target_time = MS_TO_TT(BE_LIVE_BACK_OFF_MS, si);
                self->client->on_read_seek(self->client, target_time, delay_ms);
            }
            else
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
            }
            mtv_be_set_read_state(self, MTV_BE_READ_PREBUFFERING);
        }
        else
        {
            /* target_time = last_timestamp - delay */
            if (delay_ms == MTV_TIMESHIFT_DELAY_MAX)
            {
                ret = si_get_first_timestamp(si, &target_time);
                if (ret < 0)
                {
                    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
                    goto set_delay_cleanup;
                }
                applied_delay_ms = max_delay_ms;
            }
            else
            {
                ret = si_get_last_timestamp(si, 1, &last_timestamp);
                if (ret < 0)
                {
                    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
                    goto set_delay_cleanup;
                }
                target_time = last_timestamp - (delay_ms > max_delay_ms ? MS_TO_TT(max_delay_ms, si) : MS_TO_TT(delay_ms, si));
            }

            ret = mtv_be_seek_by_time(self, target_time);
            if (ret < 0)
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
                goto set_delay_cleanup;
            }
            else if (self->client) {
                self->client->on_read_seek(self->client, target_time, delay_ms);
            }

            switch (self->read_state)
            {
            case MTV_BE_READ_LIVE:
            case MTV_BE_READ_PREBUFFERING:
                mtv_be_set_read_state(self, MTV_BE_READ_DELAYED);
                break;

            case MTV_BE_READ_DELAYED:
            case MTV_BE_READ_PAUSED:
                /* keep in the same state */
                break;

            default:
                NOT_REACHED("Unknown read state?!");
                break;
            }
        }
    }
    else /* live playback */
    {
        switch (self->read_state)
        {
        case MTV_BE_READ_LIVE:
            /* do not seek in live mode */
            break;

        case MTV_BE_READ_PAUSED:
        case MTV_BE_READ_DELAYED:

            ret = mtv_be_timeshift_set_prebuffering(control, KAL_FALSE);
            if (ret < 0)
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
                goto set_delay_cleanup;
            }
            else if (self->client)
            {
                target_time = MS_TO_TT(BE_LIVE_BACK_OFF_MS, si);
                self->client->on_read_seek(self->client, target_time, delay_ms);
            }
            else
            {
                MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_SET_DELAY, ret, __LINE__);
            }
            mtv_be_set_read_state(self, MTV_BE_READ_PREBUFFERING);
            break;

        case MTV_BE_READ_PREBUFFERING:

            mtv_be_set_read_state(self, MTV_BE_READ_LIVE);
            break;

        default:
            NOT_REACHED("Unknown read state?!");
            break;
        }
    }

    self->delay_ms = applied_delay_ms;

set_delay_cleanup:

    return ret;
}

static mtv_result_t mtv_be_timeshift_calc_dominant_track(mtv_buffer_engine_t* self, kal_uint32* max_delay_ms, kal_int32* dominant_track)
{
    kal_int32 i;

    /* find the max stream duration */
    for (i = 0; i < self->num_streams; i++)
    {
        mtv_sample_index_t* si = &self->si[i];
        kal_uint32 ms;

        ms = TT_TO_MS(si_get_duration(si), si);
        if (ms >= *max_delay_ms)
        {
            *max_delay_ms = ms;
            if (dominant_track != NULL) {
                *dominant_track = i;
            }
        }
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_calculate_delay(mtv_buffer_engine_t* self, kal_uint32* delay)
{
    mtv_sample_index_t* si;
    mtv_sample_index_entry_t entry;
    kal_uint32 last_timestamp;
    mtv_result_t ret;
    kal_uint32 max_delay_ms = 0;
    kal_int32 dominant_track = 0;

    mtv_be_timeshift_calc_dominant_track(self, &max_delay_ms, &dominant_track);
    si = &self->si[dominant_track];

    ret = si_peek_entry(si, &entry);
    if (ret == MTV_E_NO_MORE_DATA)
    {
        /*
         * If there is no data coming in during play/pause (the signal is lost), it is possible
         * that we run out of buffer content. In this case, return zero delay.
         */
        *delay = 0;
        return MTV_S_OK;
    }
    else if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        return ret; /* other file I/O errors */
    }

    ret = si_get_last_timestamp(si, 1, &last_timestamp);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        return ret;
    }

    /* returns the offset between recording and playback position */
    *delay = TT_TO_MS(last_timestamp - entry.timestamp, si);
    return MTV_S_OK;
}

#define DELAY_OFFSET(a,b) ((a) > (b) ? ((a)-(b)) : ((b)-(a)))

static mtv_result_t mtv_be_timeshift_get_delay(mtv_control_timeshift_t* control, kal_uint32* delay_ms)
{
    mtv_result_t ret;
    mtv_buffer_engine_t* self = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);

    if (self->num_streams < 1) {
        return MTV_E_FAIL;
    }

    switch (self->read_state)
    {
    case MTV_BE_READ_LIVE:
    case MTV_BE_READ_PREBUFFERING:
        *delay_ms = 0;
        break;

    case MTV_BE_READ_PAUSED:
        /* the delay will increase with time and we have to calculate it dynamically */
        ret = mtv_be_timeshift_calculate_delay(self, delay_ms);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            return ret;
        }
        break;

    case MTV_BE_READ_DELAYED:
        /*
         * In theory, the incoming data rate should be the same as the consuming
         * data rate. However, in the real world, the data may not come (bad reception)
         * or come in a little slower/faster rate. To compensate the possible delay drift,
         * we need to decide whether to return the real delay or the assumed delay.
         */
        ret = mtv_be_timeshift_calculate_delay(self, delay_ms);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            return ret;
        }
        if (DELAY_OFFSET(*delay_ms, self->delay_ms) < 3000)
        {
            /*
             * If the offfset is less than 3 seconds, return constant delay
             * to prevent delay drifting.
             */
            *delay_ms = self->delay_ms;
        }
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_get_buffer_status_ex(mtv_control_timeshift_t* control, kal_uint32* max_delay, kal_uint32* buffer_duration, kal_int32* dominant_track)
{
    mtv_buffer_engine_t* self = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);
    kal_uint32 delay = 0;
    kal_uint32 max_delay_ms = 0;

    /* find the max stream duration */
    mtv_be_timeshift_calc_dominant_track(self, &max_delay_ms, dominant_track);

    mtv_be_timeshift_get_delay(control, &delay);

    if (max_delay_ms < BE_MIN_BUFFER_MS)
    {
        ASSERT(delay == 0);
        *max_delay = 0;
    }
    else
    {
        /*
         * Don't report the 'real' max delay because the content at max delay position may get
         * overwritten very soon if the buffer is full. It is better to back off for a few
         * seconds for safety.
         */
        *max_delay = MAXOF(max_delay_ms - BE_MIN_BUFFER_MS, delay);
    }

    if (buffer_duration != NULL)
    {
        kal_uint32 current_stream_size = ss_get_stream_size(&self->ss);

        if (current_stream_size != 0)
        {
            /* estimated buffer duration = max_delay * max_stream_size / current_stream_size */
            *buffer_duration = (kal_uint32)
                ((kal_uint64)(*max_delay) * ss_get_maximum_size(&self->ss) / current_stream_size);
        }
        else
        {
            /* calculate the buffer duration using average bitrate: video = 384kb, audio = 128kb */
            *buffer_duration = (kal_uint32)((kal_uint64) ss_get_maximum_size(&self->ss) * 1000 / (64 * 1024));
        }

        /* ensure buffer duration is larger than max delay */
        if (*buffer_duration < *max_delay) {
            *buffer_duration = *max_delay;
        }
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_get_buffer_status(mtv_control_timeshift_t* control, kal_uint32* max_delay, kal_uint32* buffer_duration)
{
    return mtv_be_timeshift_get_buffer_status_ex(control, max_delay, buffer_duration, NULL);
}

static mtv_result_t mtv_be_timeshift_set_pause(mtv_control_timeshift_t* control, kal_bool pause)
{
    mtv_buffer_engine_t* self = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);
    kal_uint32 max_delay_ms = 0;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SET_PAUSE, pause);

    if (pause)
    {
        ret = control->get_buffer_status(control, &max_delay_ms, NULL);
        if (ret < 0 || max_delay_ms < BE_MIN_BUFFER_MS)
        {
            /*
             * not allow to pause if there are too few content in the buffer.
             * this checking is used to guarantee the delay time can be calculated correctly.
             */
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            return MTV_E_FAIL;
        }

        switch (self->read_state)
        {
        case MTV_BE_READ_PAUSED:
            return MTV_S_FALSE;

        case MTV_BE_READ_LIVE:
        case MTV_BE_READ_DELAYED:
        case MTV_BE_READ_PREBUFFERING:
            mtv_be_set_read_state(self, MTV_BE_READ_PAUSED);
            return MTV_S_OK;

        default:
            NOT_REACHED("Unknown read state?!");
            return MTV_E_WRONG_STATE;
        }
    }
    else
    {
        switch (self->read_state)
        {
        case MTV_BE_READ_PAUSED:

            /* we need to update delay value when going back to DELAYED mode */
            ret = mtv_be_timeshift_calculate_delay(self, &self->delay_ms);
            if (ret < 0)
            {
                MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
                return ret;
            }

            if (self->delay_ms == 0)
            {
                /*
                 * Two cases:
                 * 1) There is no data coming in during play/pause (the signal is lost)
                 * 2) Unpause at the position very near by live point
                 *
                 * Switch to live state in these cases.
                 */
                mtv_be_timeshift_set_delay(control, 0);
            }
            else {
                mtv_be_set_read_state(self, MTV_BE_READ_DELAYED);
            }
            return MTV_S_OK;

        case MTV_BE_READ_LIVE:
        case MTV_BE_READ_DELAYED:
        case MTV_BE_READ_PREBUFFERING:
            return MTV_S_FALSE;

        default:
            NOT_REACHED("Unknown read state?!");
            return MTV_E_WRONG_STATE;
        }
    }
}

static mtv_result_t mtv_be_timeshift_get_pause(mtv_control_timeshift_t* control, kal_bool* pause)
{
    mtv_buffer_engine_t* self = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);

    *pause = (kal_bool)(self->read_state == MTV_BE_READ_PAUSED);

    return MTV_S_OK;
}

static mtv_buffer_engine_read_state_t mtv_be_get_read_state(mtv_buffer_engine_t* self)
{
    return self->read_state;
}

mtv_result_t mtv_be_set_max_buffer_size(mtv_buffer_engine_t* self, kal_uint32 max_buffer_kb)
{
    mtv_result_t ret;
    kal_int32 max_size = max_buffer_kb * 1024;
	kal_int32 i;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SETTING_MAX_SIZE, max_buffer_kb);

    /*
     * try increasing the maximum size of index stream first in case that
     * there is not enough disc space.
     */
    for (i = 0; i < self->num_streams; i++)
    {
        ret = si_set_maximum_size(&self->si[i], max_size / STREAM_TO_SAMPLE_RATIO);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            return ret;
        }
    }

    ret = ss_set_maximum_size(&self->ss, max_size);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        return ret;
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_MAX_SIZE_APPLIED, max_buffer_kb);
    return MTV_S_OK;
}

typedef struct
{
    kal_uint32 signature;
    kal_uint32 ver;

} mtv_be_checkpoint_header_t;

#define MTV_BE_CHECKPOINT_HEADER_SIG MAKE_FOURCC('B', 'E', 'C', 'K')
#define MTV_BE_CHECKPOINT_HEADER_VER 0x03

mtv_result_t mtv_be_save_checkpoint(mtv_buffer_engine_t* self, cached_io_t* cp_h)
{
    kal_int32 ret;
    kal_int32 i;
    mtv_be_checkpoint_header_t header = { MTV_BE_CHECKPOINT_HEADER_SIG, MTV_BE_CHECKPOINT_HEADER_VER };

    ret = cached_io_write(cp_h, &header, sizeof(header));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    ret = cached_io_write(cp_h, &self->engine_flags, sizeof(self->engine_flags));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    ret = cached_io_write(cp_h, self->storing_dir, sizeof(self->storing_dir));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    ret = cached_io_write(cp_h, &self->num_streams, sizeof(self->num_streams));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    for (i = 0; i < self->num_streams; i++)
    {
        ret = si_save_checkpoint(&self->si[i], cp_h);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            goto cleanup;
        }
    }

    ret = ss_save_checkpoint(&self->ss, cp_h);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

cleanup:

    return (mtv_result_t)ret;
}

mtv_result_t mtv_be_recover_from_checkpoint(mtv_buffer_engine_t* self, cached_io_t* cp_h)
{
    kal_int32 ret;
    kal_int32 i;
    mtv_be_checkpoint_header_t header;

    ret = cached_io_read(cp_h, &header, sizeof(header));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    if (header.signature != MTV_BE_CHECKPOINT_HEADER_SIG || header.ver != MTV_BE_CHECKPOINT_HEADER_VER)
    {
        ret = MTV_E_CORRUPTED_DATA;
        MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_RECOVERING_FAILED, ret, __LINE__);
        goto cleanup;
    }

    ret = cached_io_read(cp_h, &self->engine_flags, sizeof(self->engine_flags));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    ret = cached_io_read(cp_h, self->storing_dir, sizeof(self->storing_dir));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    ASSERT(self->num_streams == 0);
    ret = cached_io_read(cp_h, &self->num_streams, sizeof(self->num_streams));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

    for (i = 0; i < self->num_streams; i++)
    {
        ret = si_open_from_checkpoint(&self->si[i], cp_h);
        if (ret < 0)
        {
            MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
            goto cleanup;
        }
    }

    ret = ss_open_from_checkpoint(&self->ss, cp_h);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_ERROR, MTV_TRC_BE_INTERNAL_ERROR, ret, __LINE__);
        goto cleanup;
    }

cleanup:

    if (ret < 0)
    {
        /* close self to cleanup allocated resources */
        mtv_be_close(self);

        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_FAILED_TO_RECOVER_FROM_CP, ret);
    }
    return (mtv_result_t)ret;
}

void mtv_be_destroy(mtv_buffer_engine_t* self)
{
    mtv_free_ext_mem((void**) &self);
}

mtv_buffer_engine_t* construct_mtv_buffer_engine()
{
    mtv_buffer_engine_t* self = (mtv_buffer_engine_t*) mtv_alloc_ext_mem(sizeof(mtv_buffer_engine_t), MAKE_FOURCC('B','E','N','G'));

    kal_mem_set(self, 0, sizeof(*self));

    self->open = mtv_be_open;
    self->get_control = mtv_be_get_control;
    self->add_stream = mtv_be_add_stream;
    self->get_stream_info = mtv_be_get_stream_info;
    self->update_stream_info = mtv_be_update_stream_info;
    self->write_packet = mtv_be_write_packet;
    self->read_packet = mtv_be_read_packet;
    self->read_packet_from_stream = mtv_be_read_packet_from_stream;
    self->translate_to_stream_time = mtv_be_translate_to_stream_time;
    self->save = mtv_be_save;
    self->discard_all = mtv_be_discard_all;
    self->set_discard_policy = mtv_be_set_discard_policy;
    self->disable_wrap_around = mtv_be_disable_wrap_around;
    self->get_read_state = mtv_be_get_read_state;
    self->set_max_buffer_size = mtv_be_set_max_buffer_size;
    self->save_checkpoint = mtv_be_save_checkpoint;
    self->recover_from_checkpoint = mtv_be_recover_from_checkpoint;
    self->close = mtv_be_close;
    self->destroy = mtv_be_destroy;

    self->timeshift_ctrl.set_pause = mtv_be_timeshift_set_pause;
    self->timeshift_ctrl.get_pause = mtv_be_timeshift_get_pause;
    self->timeshift_ctrl.set_delay = mtv_be_timeshift_set_delay;
    self->timeshift_ctrl.get_delay = mtv_be_timeshift_get_delay;
    self->timeshift_ctrl.get_buffer_status = mtv_be_timeshift_get_buffer_status;
    self->timeshift_ctrl.set_prebuffering = mtv_be_timeshift_set_prebuffering;

    return self;
}

static kal_bool delete_found_file(void* param, const kal_wchar* filename)
{
    UNUSED(param);

    FS_Delete(filename);
    return KAL_TRUE;    /* continue the searching */
}

void mtv_be_discard_unsaved_buffers(const kal_wchar* dir)
{
    kal_wchar* pattern;

    pattern = (kal_wchar*) mtv_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar), MAKE_FOURCC('T','E','M','P'));

    kal_wstrcpy(pattern, AV_STREAM_PREFIX);
    kal_wstrcat(pattern, L"*");
    mtv_process_files(dir, pattern, delete_found_file, NULL);

    kal_wstrcpy(pattern, AUDIO_INDEX_PREFIX);
    kal_wstrcat(pattern, L"*");
    mtv_process_files(dir, pattern, delete_found_file, NULL);

    kal_wstrcpy(pattern, VIDEO_INDEX_PREFIX);
    kal_wstrcat(pattern, L"*");
    mtv_process_files(dir, pattern, delete_found_file, NULL);

    mtv_free_ext_mem((void**) &pattern);
}

#endif /* defined(__MED_MTV_MOD__) || defined(__STREAM_REC_SUPPORT__) */

