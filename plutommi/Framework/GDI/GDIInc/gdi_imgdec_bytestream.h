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

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_imgdec_bytestream.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  IMGDEC bytesteam reader header
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "fs_type.h"
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

#ifndef _GDI_IMGDEC_BYTESTREAM_H_
#define _GDI_IMGDEC_BYTESTREAM_H_

#define GDI_IMGDEC_BYTESTREAM_BUFFER_SIZE      2048 /* size of file buffer cache */

typedef struct
{
    FS_HANDLE file_handle;
    int file_size;
    int buffer_content_size;
    int file_offset;
    U8 *buffer_reader;
    // TODO: use a pointer instead of array?
    U8 *buffer;

    U8 *buffer_ptr;
    U32 buffer_ptr_size;

    void *jmpbuf;
    kal_bool is_from_memory;
} gdi_imgdec_bytestream_struct;


extern GDI_RESULT gdi_imgdec_bytestream_init_file(gdi_imgdec_bytestream_struct *handle, const S8 *file_name);
extern GDI_RESULT gdi_imgdec_bytestream_init_file_ext(
                        gdi_imgdec_bytestream_struct *handle,
                        const S8 *file_name, 
                        U8 *file_buf, 
                        U32 file_buf_size,
                        void *jmpbuf);

extern GDI_RESULT gdi_imgdec_bytestream_init(gdi_imgdec_bytestream_struct *handle, U8* src, U32 size);
extern GDI_RESULT gdi_imgdec_bytestream_deinit(gdi_imgdec_bytestream_struct *handle);

extern GDI_RESULT gdi_imgdec_bytestream_read(gdi_imgdec_bytestream_struct *handle, void *ptr, U32 size);
extern GDI_RESULT gdi_imgdec_bytestream_seek(gdi_imgdec_bytestream_struct *handle, S32 offset);

extern void gdi_imgdec_bytestream_buffer_load_file(gdi_imgdec_bytestream_struct *handle, int at_least);
extern void gdi_imgdec_bytestream_seek_file(gdi_imgdec_bytestream_struct *handle, S32 offset);

#define     GDI_IMGDEC_BYTESTREAM_PEEK_BYTE_FILE(h, X)       \
         {                                         \
            if (!h->buffer_content_size) \
               gdi_imgdec_bytestream_buffer_load_file(h, 1); \
            X = *(h->buffer_reader);     \
         }

#define     GDI_IMGDEC_BYTESTREAM_PEEK_BYTE_N_FILE(h, X,OFFSET)    \
         {                                               \
            if (h->buffer_content_size < OFFSET) \
               gdi_imgdec_bytestream_buffer_load_file(h, OFFSET);  \
            X = h->buffer_reader[OFFSET];    \
         }

#define     GDI_IMGDEC_BYTESTREAM_GET_BYTE_FILE(h, X)          \
         {                                           \
            if (!(h->buffer_content_size)) \
               gdi_imgdec_bytestream_buffer_load_file(h, 1);   \
            h->buffer_content_size--;    \
            h->file_offset++;            \
            X = *(h->buffer_reader)++;     \
         }                                           

#define     GDI_IMGDEC_BYTESTREAM_GET_WORD_FILE(h, X)             \
         {                                              \
            if (h->buffer_content_size < 2)    \
               gdi_imgdec_bytestream_buffer_load_file(h, 2);      \
            h->buffer_content_size -= 2;      \
            h->file_offset += 2;              \
            X = *(h->buffer_reader)++;        \
            X |= (*(h->buffer_reader)++) << 8; \
         }                                              

#define     GDI_IMGDEC_BYTESTREAM_GET_3BYTES_FILE(h, X)            \
         {                                               \
            if (h->buffer_content_size < 3)     \
               gdi_imgdec_bytestream_buffer_load_file(h, 3);       \
            h->buffer_content_size -= 3;       \
            h->file_offset += 3;               \
            X = *(h->buffer_reader)++;         \
            X |= (*(h->buffer_reader)++) << 8; \
            X |= (*(h->buffer_reader)++) << 16;\
         }                                               

#define     GDI_IMGDEC_BYTESTREAM_GET_DWORD_FILE(h, X)             \
         {                                               \
            if (h->buffer_content_size < 4)     \
               gdi_imgdec_bytestream_buffer_load_file(h, 4);       \
            h->buffer_content_size -= 4;       \
            h->file_offset += 4;               \
            X = *(h->buffer_reader)++;         \
            X |= (*(h->buffer_reader)++) << 8; \
            X |= (*(h->buffer_reader)++) << 16;\
            X |= (*(h->buffer_reader)++) << 24;\
         }                                               

#define GDI_IMGDEC_BYTESTREAM_FLUSH_FILE(h, COUNT)                          \
         {                                                           \
            int count = COUNT;                                       \
            h->file_offset += count;                     \
            if(count >= (int)h->buffer_ptr_size)              \
               gdi_imgdec_bytestream_seek_file(h, h->file_offset); \
            else                                                     \
            {                                                        \
               while(count)                                          \
               {                                                     \
                  if (h->buffer_content_size < (int)count) \
                  {                                                  \
                     count -= h->buffer_content_size;    \
                     h->buffer_content_size=0;           \
                     gdi_imgdec_bytestream_buffer_load_file(h, 1);             \
                  }                                                  \
                  else                                               \
                  {                                                  \
                     h->buffer_content_size -= count;      \
                     h->buffer_reader += count;           \
                     count = 0;                                        \
                  }                                                  \
               }                                                     \
            }                                                        \
         }                                                           

#define GDI_IMGDEC_BYTESTREAM_TELL_FILE(h)       (h->file_offset)

#define GDI_IMGDEC_BYTESTREAM_GET_ARRAY_FILE(h, ARRAY_POINTER,SIZE)     \
   {                                                          \
      int size = SIZE;                                        \
      while (size > 0)                                           \
      {                                                       \
         int n;                                               \
         if (h->buffer_content_size == 0)          \
            gdi_imgdec_bytestream_buffer_load_file(h, 1);               \
         n= GDI_MIN(size, h->buffer_content_size); \
         memcpy(ARRAY_POINTER, h->buffer_reader, n); \
         ARRAY_POINTER += n;                                    \
         h->buffer_content_size -= n;              \
         size -= n;                                           \
         h->file_offset += n;                       \
         h->buffer_reader += n;                     \
      }                                                       \
   }

#endif /* _GDI_IMGDEC_BYTESTREAM_H_ */ 


