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
 *   mtv_cached_io.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_CACHED_IO_H
#define _MTV_CACHED_IO_H

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

#ifndef _MTV_ASYNC_IO_H
#include "mtv_async_io.h"
#endif

#include "kal_general_types.h"
#include "fs_type.h"

typedef enum
{
    BLOCK_STATE_INVALID,
    BLOCK_STATE_VALID,
    BLOCK_STATE_DIRTY

} cache_block_state_t;

typedef struct
{
    cache_block_state_t state;
    kal_uint32 block_no;
    kal_uint8* buffer;
    kal_uint32 bytes;           /**< available bytes in the block */

#ifdef _DEBUG
    kal_uint32 read_hits;
    kal_uint32 write_hits;
#endif

} cached_block_t;

typedef enum
{
    CACHED_IO_STATUS_SLOW_WRITING = 0x01

} cached_io_status_t;

typedef void (*cached_io_cleanup_t)(void* param);

/**
  * Helper to provide cached file read/write operations. It is designed specifically so that
  * reading and writing can be done at the same time efficiently.
  */
typedef struct
{
    FS_HANDLE file_h;
    kal_uint32 pos;             /**< current read/write pos */
    kal_uint32 file_size;       /**< cached file size to prevent unnecessary file read */

    kal_uint32 block_size;
    cached_block_t blocks[2];

    async_io_t* aio;            /**< could be NULL if asynchronous I/O is not desired */

    cached_io_cleanup_t cleanup;    /**< user-supplied cleanup callback */
    void* cleanup_param;

    kal_uint32 status;          /**< current I/O status. @see cached_io_status_t */

} cached_io_t;

typedef struct
{
    kal_wchar* filename;
    kal_uint32 size;

} cached_io_file_state_t;

/* public function interface */

extern kal_int32 cached_io_open(cached_io_t* io, const kal_wchar* filename, kal_uint32 flags);
extern kal_int32 cached_io_set_async(cached_io_t* io);
extern kal_int32 cached_io_attach(cached_io_t* io, FS_HANDLE file_h);

extern void cached_io_seek(cached_io_t* io, kal_uint32 pos);
extern kal_uint32 cached_io_tell(cached_io_t* io);
extern kal_uint32 cached_io_get_status(cached_io_t* io);

extern kal_int32 cached_io_flush(cached_io_t* io);
extern kal_int32 cached_io_get_state(FS_HANDLE fh, cached_io_file_state_t* state);

extern kal_int32 cached_io_read(cached_io_t* io, void* buf, kal_uint32 size);
extern kal_int32 cached_io_write(cached_io_t* io, void* buf, kal_uint32 size);
extern kal_int32 cached_io_read_pos(cached_io_t* io, kal_uint32 pos, void* buf, kal_uint32 size);
extern kal_int32 cached_io_write_pos(cached_io_t* io, kal_uint32 pos, void* buf, kal_uint32 size);

extern kal_int32 cached_io_detach(cached_io_t* io);

extern kal_int32 cached_io_close(cached_io_t* io);
extern kal_int32 cached_io_get_state_and_close(cached_io_t* io, cached_io_file_state_t* state);

extern kal_int32 cached_io_close_async(cached_io_t* io, cached_io_cleanup_t cleanup, void* cleanup_param);

#endif /* _MTV_CACHED_IO_H */
