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
 *   mtv_async_io.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include <stdio.h>
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_timer.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "mtv_comm.h"
#include "mtv_main.h"
#include "med_struct.h"
#include "med_utility.h"
#include "med_trc.h"

#if defined(__MED_MTV_MOD__) || defined(__STREAM_REC_SUPPORT__)

#include "mtv_async_io.h"
#include "drv_comm.h"

#include "mtv_custom.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "med_global.h"
#include "kal_trace.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "stack_config.h"

#define MTV_ASYNC_IO_LOCKS_PER_FILE  1
#define MTV_ASYNC_IO_LOCKS_FOR_BE    (3*MTV_ASYNC_IO_LOCKS_PER_FILE)
#define MTV_ASYNC_IO_LOCKS_FOR_CP    MTV_ASYNC_IO_LOCKS_PER_FILE
#ifdef __VIDEO_ARCHI_V2__
#define MTV_ASYNC_IO_LOCKS_FOR_V2_BUF 1
#else
#define MTV_ASYNC_IO_LOCKS_FOR_V2_BUF 0
#endif

#define MTV_ASYNC_IO_LOCK_COUNT      (2 + 3 + (MTV_MAX_MULTIPLE_SERVICES*(2*MTV_ASYNC_IO_LOCKS_FOR_BE + MTV_ASYNC_IO_LOCKS_FOR_CP)) + MTV_ASYNC_IO_LOCKS_FOR_V2_BUF)
#define MTV_ASYNC_IO_MAX_BLOCKS      36

/*
 * Use a small sleep duration may cause strange side effect on MoDIS.
 * Therefore, use a reasonal value for both target and MoDIS.
 */
#define MTV_ASYNC_IO_WAIT_INTERVAL      (KAL_TICKS_1_SEC / 4)

typedef struct
{
    kal_mutexid pool_lock;
    kal_mutexid locks[MTV_ASYNC_IO_LOCK_COUNT];

    async_io_block_queue_t write_q;
    async_io_block_queue_t free_q;
    kal_uint32 block_count;

    async_io_notification_t notifications[8];

} mtv_aio_context_t;

static mtv_aio_context_t g_mtv_aio_context;

static kal_mutexid mtv_get_lock_unprotected(void)
{
    kal_uint32 i;
    kal_mutexid lock = 0;

    for (i = 0; i < ARRAY_SIZE(g_mtv_aio_context.locks); i++)
    {
        if (g_mtv_aio_context.locks[i] != NULL)
        {
            lock = g_mtv_aio_context.locks[i];
            g_mtv_aio_context.locks[i] = NULL;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_mtv_aio_context.locks));

    return lock;
}

kal_mutexid mtv_get_lock(void)
{
    kal_mutexid lock = 0;

    kal_take_mutex(g_mtv_aio_context.pool_lock);

    lock = mtv_get_lock_unprotected();

    kal_give_mutex(g_mtv_aio_context.pool_lock);

    return lock;
}

void mtv_return_lock(kal_mutexid lock)
{
    kal_uint32 i;

    kal_take_mutex(g_mtv_aio_context.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_mtv_aio_context.locks); i++)
    {
        if (g_mtv_aio_context.locks[i] == NULL)
        {
            g_mtv_aio_context.locks[i] = lock;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_mtv_aio_context.locks));

    kal_give_mutex(g_mtv_aio_context.pool_lock);
}

static void async_io_init_queue(async_io_block_queue_t* q, kal_mutexid lock)
{
    q->head = NULL;
    q->lock = lock;
    q->size = 0;
}

static async_io_block_t* async_io_queue_head(async_io_block_queue_t* q)
{
    return q->head;
}

static async_io_block_t* async_io_dequeue_block_unprotected(async_io_block_queue_t* q)
{
    async_io_block_t* head;

    head = q->head;
    if (head)
    {
        q->head = head->next;
        if (q->head) {
            q->head->prev = head->prev;
        }

        head->next = head->prev = NULL;

        q->size--;
        ASSERT((q->head == NULL && q->size == 0) || (q->head != NULL && q->size != 0));
    }

    return head;
}

static async_io_block_t* async_io_dequeue_block(async_io_block_queue_t* q)
{
    async_io_block_t* block;

    kal_take_mutex(q->lock);

    block = async_io_dequeue_block_unprotected(q);

    kal_give_mutex(q->lock);

    return block;
}

/**
  * Enqueue an item.
  *
  * @return the item number in the queue.
  */
static kal_uint32 async_io_enqueue_block(async_io_block_queue_t* q, async_io_block_t* block)
{
    kal_int32 q_size;

    ASSERT(block != NULL);

    kal_take_mutex(q->lock);

    block->next = NULL;

    if (q->head != NULL)
    {
        async_io_block_t* tail = q->head->prev;
        tail->next = block;
        block->prev = tail;
        q->head->prev = block;
    }
    else
    {
        q->head = block;
        block->prev = block;
    }

    q_size = ++q->size;
    ASSERT(q->head != NULL && q->size != 0);

    kal_give_mutex(q->lock);

    return q_size;
}

/* wait for the completion of block writing */
static void async_io_wait_completion(async_io_t* io)
{
    async_io_block_queue_t* q = &g_mtv_aio_context.write_q;
    async_io_block_t* b;
    kal_uint32 wait_time;
    kal_bool busy;

    for (wait_time = 0; ; wait_time += MTV_ASYNC_IO_WAIT_INTERVAL)
    {
        busy = KAL_FALSE;

        kal_take_mutex(q->lock);

        for (b = q->head; b != NULL; b = b->next)
        {
            if (b->owner == io)
            {
                busy = KAL_TRUE;
                break;
            }
        }

        kal_give_mutex(q->lock);

        if (!busy) {
            break;
        }

        /* sleep for a while and check again */
        kal_sleep_task(MTV_ASYNC_IO_WAIT_INTERVAL);
    }
}

static void async_io_free_blocks(async_io_block_queue_t* q)
{
    async_io_block_t* block;

    /* free all blocks in free queue */
    while ((block = async_io_dequeue_block(q)) != NULL)
    {
        mtv_free_ext_mem((void**)&block->buffer);
        mtv_free_ext_mem((void**)&block);
    }
    q->head = NULL;
}

static void async_io_read_block_in_write_queue(async_io_t* io, kal_uint32 block_no, void* buffer, kal_uint32* read_bytes)
{
    async_io_block_queue_t* q = &g_mtv_aio_context.write_q;

    kal_take_mutex(q->lock);

    *read_bytes = 0;

    if (q->head != NULL)
    {
        async_io_block_t* tail = q->head->prev;
        async_io_block_t* b = tail;

        do
        {
            if (b->owner == io && block_no == b->block_no)
            {
                kal_mem_cpy(buffer, (kal_uint8*) b->buffer, b->size);
                *read_bytes = b->size;
                break;
            }

            b = b->prev;
        } while (b != tail);
    }

    kal_give_mutex(q->lock);
}

static void async_io_return_to_free_q(async_io_block_t* block)
{
    async_io_enqueue_block(&g_mtv_aio_context.free_q, block);
}

static kal_bool async_io_add_free_block(async_io_t* io)
{
    async_io_block_t* block;

    /* create a new block object */
    block = (async_io_block_t*) mtv_alloc_ext_mem(sizeof(async_io_block_t), MAKE_FOURCC('A','I','O','O'));
    kal_mem_set(block, 0, sizeof(*block));

    /* create block buffer */
    block->state = ASYNC_IO_BLOCK_STATE_FREE;
    block->buffer = mtv_alloc_ext_mem(io->block_size, MAKE_FOURCC('A','I','O','B'));

    g_mtv_aio_context.block_count++;

    async_io_return_to_free_q(block);

    return KAL_TRUE;
}

/* get one block from free queue */
static async_io_block_t* async_io_get_free_block(async_io_t* io)
{
    async_io_block_t* block;

    block = async_io_dequeue_block(&g_mtv_aio_context.free_q);
    if (block == NULL && g_mtv_aio_context.block_count < MTV_ASYNC_IO_MAX_BLOCKS)
    {
        async_io_add_free_block(io);
        block = async_io_dequeue_block(&g_mtv_aio_context.free_q);
    }

    if (block)
    {
        block->owner = io;
    }

    ASSERT(block == NULL || block->state == ASYNC_IO_BLOCK_STATE_FREE);
    return block;
}

kal_bool async_io_is_writing_slow(async_io_t* io)
{
    kal_bool ret = KAL_FALSE;

    if (g_mtv_aio_context.write_q.size >= (MTV_ASYNC_IO_MAX_BLOCKS - 1))
    {
        ret = KAL_TRUE;
    }

    return ret;
}

kal_int32 async_io_attach(async_io_t* io, FS_HANDLE file_h, kal_uint32 block_size)
{
    io->file_h = file_h;
    ASSERT(io->file_h >= 0);

    io->file_lock = mtv_get_lock();

    ASSERT(block_size == MTV_CACHE_BLOCK_SIZE);
    io->block_size = block_size;

    io->errors = 0;
    io->last_error = FS_NO_ERROR;
    io->cleanup = NULL;
    io->cleanup_param = NULL;

    return io->file_h;
}

static void async_io_write_block(async_io_t* io, async_io_block_t* block)
{
    kal_int32 ret = 0;

    kal_take_mutex(io->file_lock);

    ret = FS_Seek(io->file_h, block->block_no * io->block_size, FS_FILE_BEGIN);
    if (ret >= 0)
    {
        /* write the block */
        kal_uint32 written;
        kal_uint32 pos;

        ret = FS_Write(io->file_h, block->buffer, block->size, &written);

        if (ret >= 0)
        {
            if (written != block->size)
            {
                io->errors++;
                io->last_error = FS_DISK_FULL;
                MTV_TRACE(TRACE_ERROR, MTV_TRC_AIO_WRITE_ERROR, ret, __LINE__);
            }

            ret = FS_GetFilePosition(io->file_h, &pos);
            if (ret < 0)
            {
                io->errors++;
                io->last_error = ret;
                MTV_TRACE(TRACE_ERROR, MTV_TRC_AIO_WRITE_ERROR, ret, __LINE__);
            }
            else if (pos != (block->block_no * io->block_size + written))
            {
                io->errors++;
                io->last_error = FS_INVALID_FILE_POS;
                MTV_TRACE(TRACE_ERROR, MTV_TRC_AIO_WRITE_ERROR, ret, __LINE__);
            }
        }
        else
        {
            io->errors++;
            io->last_error = ret;
            MTV_TRACE(TRACE_ERROR, MTV_TRC_AIO_WRITE_ERROR, ret, __LINE__);
        }
    }
    else
    {
        io->errors++;
        io->last_error = ret;
        MTV_TRACE(TRACE_ERROR, MTV_TRC_AIO_WRITE_ERROR, ret, __LINE__);
    }

    kal_give_mutex(io->file_lock);
}

static async_io_notification_t* async_io_alloc_notification(void)
{
    kal_uint32 i;

    for (i = 0; i < ARRAY_SIZE(g_mtv_aio_context.notifications); i++)
    {
        if (g_mtv_aio_context.notifications[i].func == NULL)
        {
            return &g_mtv_aio_context.notifications[i];
        }
    }

    NOT_REACHED("Run out of AIO notifications!");
    return NULL;
}

static void async_io_free_notification(async_io_notification_t* ntf)
{
    ntf->func = NULL;
}

void async_io_register_notification(async_io_notification_func func, void* param)
{
    async_io_block_queue_t* q = &g_mtv_aio_context.write_q;

    kal_take_mutex(q->lock);

    if (q->head)
    {
        /* append notification to the last block */

        async_io_block_t* tail = q->head->prev;
        async_io_notification_t* ntf = tail->notifications;
        async_io_notification_t* new_ntf = async_io_alloc_notification();

        new_ntf->func = func;
        new_ntf->param = param;
        new_ntf->next = NULL;

        if (ntf == NULL)
        {
            tail->notifications = new_ntf;
        }
        else
        {
            /* find the last notification */
            while (ntf->next != NULL) {
                ntf = ntf->next;
            }
            ntf->next = new_ntf;
        }
    }
    else
    {
        /* enqueue a callback message directly */
        mtv_call_async(MTV_ASYNC_IO_MOD, func, param);
    }

    kal_give_mutex(q->lock);
}

static void async_io_execute_notifications(async_io_block_t* block)
{
    async_io_notification_t *ntf, *next_ntf;

    /* execute registered notifications of this block */
    for (ntf = block->notifications; ntf != NULL; ntf = next_ntf)
    {
        ntf->func(ntf->param);

        next_ntf = ntf->next;
        async_io_free_notification(ntf);
    }

    block->notifications = NULL;
}

kal_int32 async_io_process_writing(void* io_param)
{
    async_io_block_queue_t* q = &g_mtv_aio_context.write_q;
    async_io_block_t* block;
    kal_uint32 processed = 0;

    UNUSED(io_param);

    while ((block = async_io_queue_head(q)) != NULL)
    {
        async_io_t* io;
        async_io_block_t* dequeued;

        if (processed >= 4) /* prevent blocking for too long */
        {
            CONSTRUCT_LOCAL_PARAM(media_mtv_async_write_req_struct, req);
            mtv_send_outgoing_ilm(MTV_ASYNC_IO_MOD, MSG_ID_MEDIA_MTV_ASYNC_WRITE_REQ, req);

            break;
        }

        io = (async_io_t*) block->owner;

        block->state = ASYNC_IO_BLOCK_STATE_WRITING;

        async_io_write_block(io, block);

        block->state = ASYNC_IO_BLOCK_STATE_FREE;
        processed++;

        kal_take_mutex(q->lock);
        {
            /* execute registered notifications of this block */
            async_io_execute_notifications(block);

            /* then dequeue the block so that async_io_wait_completion can work correctly */
            dequeued = async_io_dequeue_block_unprotected(q);
            ASSERT(dequeued == block);
        }
        kal_give_mutex(q->lock);

        /* move the block back to free queue */
        async_io_return_to_free_q(block);
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_AIO_PROCESSED_BLOCKS, processed);
    return 0;
}

kal_int32 async_io_write(async_io_t* io, kal_uint32 block_no, void* buffer, kal_uint32 buf_size)
{
    async_io_block_t* block;

    ASSERT(buffer != NULL);
    ASSERT(io->block_size > 0 && io->block_size >= buf_size);
    ASSERT(io->file_h >= 0);

    if (io->errors > 0)
    {
        /* some errors has happened. reject subsequent writing. */
        return io->last_error;
    }

    block = async_io_get_free_block(io);
    if (block == NULL) /* unable to alloc free block in maximum allowable time */
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_AIO_FAILED_TO_GET_FREE_BLOCK);
        return FS_OUT_OF_BUFFERS;
    }

    /* initialize write block */
    block->block_no = block_no;
    block->size = buf_size;
    block->state = ASYNC_IO_BLOCK_STATE_WAITING;

    /* copy the data buffer */
    kal_mem_cpy(block->buffer, buffer, buf_size);

    /* add the block to write queue */

    if (async_io_enqueue_block(&g_mtv_aio_context.write_q, block) == 1)
    {
        CONSTRUCT_LOCAL_PARAM(media_mtv_async_write_req_struct, req);
        mtv_send_outgoing_ilm(MTV_ASYNC_IO_MOD, MSG_ID_MEDIA_MTV_ASYNC_WRITE_REQ, req);
    }

    return 0;
}

kal_int32 async_io_read(async_io_t* io, kal_uint32 block_no, void* buffer, kal_uint32* read_bytes)
{
    kal_int32 ret;

    if (io->errors > 0)
    {
        /* some errors has happened. reject subsequent read. */
        return io->last_error;
    }

    async_io_read_block_in_write_queue(io, block_no, buffer, read_bytes);
    if (*read_bytes == 0)
    {
        kal_uint32 read_pos = block_no * io->block_size;
        kal_uint32 pos;

        kal_take_mutex(io->file_lock);

        /* read from file directly */
        ret = FS_Seek(io->file_h, read_pos, FS_FILE_BEGIN);
        if (ret < 0)
        {
            kal_give_mutex(io->file_lock);
            return ret;
        }

        ret = FS_Read(io->file_h, buffer, io->block_size, read_bytes);
        if (ret < 0)
        {
            kal_give_mutex(io->file_lock);
            return ret;
        }

        ret = FS_GetFilePosition(io->file_h, &pos);
        if (ret < 0)
        {
            kal_give_mutex(io->file_lock);
            return ret;
        }
        else {
            ASSERT(pos == (read_pos + *read_bytes));
        }

        kal_give_mutex(io->file_lock);
    }

    return 0;
}

static void async_io_detach_callback(void* param)
{
    async_io_t* io = (async_io_t*) param;

    mtv_return_lock(io->file_lock);

    io->file_h = FS_INVALID_FILE_HANDLE;

    /* invoke client-supplied callback */
    ASSERT(io->cleanup != NULL);
    io->cleanup(io->cleanup_param);
}

kal_int32 async_io_detach(async_io_t* io, async_io_cleanup_t cleanup, void* cleanup_param)
{
    if (cleanup == NULL)
    {
        async_io_wait_completion(io);

        mtv_return_lock(io->file_lock);

        io->file_h = -1;
    }
    else
    {
        io->cleanup = cleanup;
        io->cleanup_param = cleanup_param;
        async_io_register_notification(async_io_detach_callback, io);
    }

    return 0;
}

void mtv_init_aio(void)
{
    kal_uint32 i;
    kal_char lock_name[16];

    /* init lock pool */
    for (i = 0; i < ARRAY_SIZE(g_mtv_aio_context.locks); i++)
    {
        sprintf(lock_name, "MTVLK%d", i);
        g_mtv_aio_context.locks[i] = kal_create_mutex(lock_name);
    }

    /* shared lock for lock pool */
    g_mtv_aio_context.pool_lock = mtv_get_lock_unprotected();

    g_mtv_aio_context.block_count = 0;

    /* init global write/free queue */
    async_io_init_queue(&g_mtv_aio_context.write_q, mtv_get_lock_unprotected());
    async_io_init_queue(&g_mtv_aio_context.free_q, mtv_get_lock_unprotected());
}

void mtv_free_aio_resource(void)
{
    async_io_free_blocks(&g_mtv_aio_context.write_q);
    async_io_free_blocks(&g_mtv_aio_context.free_q);

    g_mtv_aio_context.block_count = 0;
}

#endif  /* defined(__MED_MTV_MOD__) */
