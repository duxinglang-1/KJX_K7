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
 *   mtv_bits.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "stack_common.h"

#include "med_global.h"

#if defined(__MED_MTV_MOD__)

#include "mtv_bits.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"

kal_uint32 mtv_bits_show(mtv_bits_t* self, kal_uint32 n)
{
    ASSERT(self->bits >= n);

    /* cache:
     *
     *  -------- -------- ---- bits
     * |********|********|****####|########|
     *  ---- n
     *      ---- -------- -------- -------- (32 - n)
     */
    return self->cache >> (32 - n);
}

static void mtv_flush_bits(mtv_bits_t* self, kal_uint32 n)
{
    ASSERT(self->bits >= n);

    if (n < 32)
        self->cache <<= n;
    else
        self->cache = 0;

    self->bits -= n;
    while (self->bits <= 24)
    {
        if (self->read + 4 <= self->end)
        {
            kal_uint32 bits = self->bits;

            do
            {
                /* cache:
                 *
                 *  -------- -------- ---- bits
                 * |********|********|****####|########|
                 *                        ---- (24 - bits)
                 */
                self->cache |= *self->read++ << (24 - bits);
                bits += 8;
            }
            while (bits <= 24);

            self->bits = bits;
        }
        else
        {
            do
            {
                /* extra boundary checking here */
                if (self->read >= self->end)
                {
                    kal_uint32 bytes;

                    if (!self->fill) {
                        return;
                    }

                    bytes = self->fill(self->param, self->buf, self->buf_len);
                    if (bytes == 0) {
                        return;
                    }

                    self->read = self->buf;
                    self->end = self->read + bytes;
                }

                self->cache |= *self->read++ << (24 - self->bits);
                self->bits += 8;
            }
            while (self->bits <= 24);
        }
    }
}

void mtv_bits_refill(mtv_bits_t* self, kal_uint32 min_bytes)
{
    kal_uint32 cached_bytes = (self->bits + 7) / 8;
    kal_uint32 remaining = self->end - self->read;
    kal_uint8* cached_pos = self->read - cached_bytes;

    if ((self->end - self->read) + cached_bytes > min_bytes) {
        return; /* long enough */
    }

    /* move content to the beginnin of buffer */
    if (cached_pos > self->buf)
    {
        memmove(self->buf, cached_pos, remaining + cached_bytes);

        self->read = self->buf + cached_bytes;
        self->end = self->read + remaining;
    }

    /* fill empty space */
    if (self->buf_len > remaining + cached_bytes)
    {
        kal_uint32 bytes;

        bytes = self->fill(self->param, self->end, self->buf_len - remaining - cached_bytes);
        self->end += bytes;
    }
}

void mtv_bits_get_block(mtv_bits_t* self, kal_uint8* buf, kal_uint32 bytes)
{
    kal_uint32 cached_bytes = self->bits / 8;
    kal_uint32 remaining = self->end - self->read;

	ASSERT(self->bits % 8 == 0);

    if (bytes <= cached_bytes)
    {
        kal_uint32 i;
        for (i = 0; i < bytes; i++) {
            buf[i] = mtv_bits_get_byte(self);
        }
        return;
    }
    else
    {
        if (cached_bytes >= 1) {
            buf[0] = (self->cache & 0xFF000000) >> 24;
        }
        if (cached_bytes >= 2) {
            buf[1] = (self->cache & 0x00FF0000) >> 16;
        }
        if (cached_bytes >= 3) {
            buf[2] = (self->cache & 0x0000FF00) >> 8;
        }
        if (cached_bytes >= 4) {
            buf[3] = (self->cache & 0x000000FF);
        }

        buf += cached_bytes;
        bytes -= cached_bytes;

        self->bits = 0;
        self->cache = 0;
    }

    /* move content to the beginnin of buffer */
    if (bytes <= remaining)
    {
        kal_mem_cpy(buf, self->read, bytes);
        self->read += bytes;
    }
    else if (self->fill)
    {
    	kal_mem_cpy(buf, self->read, remaining);
    	bytes = self->fill(self->param, buf + remaining, bytes - remaining);
    	self->read = self->end;
    }
    else {
        ASSERT(0);
    }

    mtv_flush_bits(self, 0);
}

kal_uint8* mtv_bits_head(mtv_bits_t* self)
{
    ASSERT(self->bits % 8 == 0);
    return self->read - (self->bits / 8);
}

void mtv_bits_discard(mtv_bits_t* self, kal_uint32 bytes)
{
    kal_uint8* pos = self->read - (self->bits / 8) + bytes;

    ASSERT(self->bits % 8 == 0);

    if (pos <= self->end)
    {
        self->read = pos;
        self->bits = 0;
        self->cache = 0;
        mtv_flush_bits(self, 0);
    }
    else
    {
        kal_uint32 i;

        for (i = 0; i < bytes; i++) {
            mtv_bits_get_byte(self);
        }
    }
}

kal_uint32 mtv_bits_get(mtv_bits_t* self, kal_uint32 n)
{
    kal_uint32 val;

    val = mtv_bits_show(self, n);
    mtv_flush_bits(self, n);
    return val;
}

kal_uint32 mtv_bits_get_byte(mtv_bits_t* self)
{
    ASSERT(self->bits >= 8 && self->bits % 8 == 0);
    return mtv_bits_get(self, 8);
}

kal_uint32 mtv_bits_get_bytes(mtv_bits_t* self, kal_uint32 n)
{
    ASSERT(self->bits >= 8 && self->bits % 8 == 0);
    ASSERT(n <= 4);
    return mtv_bits_get(self, 8 * n);
}

void mtv_bits_init(mtv_bits_t* self, kal_uint8* buf, kal_uint32 bytes, mtv_bits_fill_t fill, void* param)
{
    ASSERT(bytes > 0 && buf != NULL);

    self->fill = fill;
    self->param = param;
    self->buf = buf;
    self->buf_len = bytes;

    self->read = buf;
    self->end = buf + bytes;
    self->bits = 0;
    self->cache = 0;

    mtv_flush_bits(self, 0);
}

#endif /* defined(__MED_MTV_MOD__) */
