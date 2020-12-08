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
 *  gif_parse.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  parse utility for gif decoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
//#include "gif_parse.h"
#include "fsal.h"
#include "kal_general_types.h"
#ifndef SWGIF_VC_PROJ
#include "kal_public_api.h"
#endif
#include "gif_decode_int_sw_util.h"
#include "gif_parse.h"

void _gif_error_raise(void)
{
   if (gif_sw_jmpbuf_is_used == KAL_TRUE)
   {
      //GIF_SW_RAISE(1);
      GIF_SW_RAISE(GIF_STATUS_DEC_ERROR_PARSE);
      return;
   }
}

#if defined(GIF_FSAL_RD_PERF_LOG)
#define gif_fsal_block_read_entry_cnt 512
kal_uint32 gif_fsal_block_read[gif_fsal_block_read_entry_cnt];
kal_uint32 gif_fsal_block_read_idx = 0;
kal_uint32 gif_fsal_block_read_avg;
kal_uint32 gif_fsal_block_read_size = 255;
kal_bool gif_fsal_read_block_perf_log = 0;

void _gif_fsal_gets (STFSAL *h, kal_uint8* array, kal_uint16 n)
{
   kal_uint32 cur_position, filesize, rtn;
   kal_uint32 start, end;

   start = drv_get_current_time();
   rtn = FSAL_Read(h, array, n);
   if (FSAL_OK == rtn)
   {
      if ((gif_fsal_read_block_perf_log) && (n > 50))
      {
         end = drv_get_current_time();
         gif_fsal_block_read[gif_fsal_block_read_idx++] = drv_get_duration_tick(start, end);
         //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_fsal_gets() FSAL_Read=>%d size = %dticks. \n", n, drv_get_duration_tick(start, end));
         if (gif_fsal_block_read_idx == gif_fsal_block_read_entry_cnt)
         {
            kal_uint32 i = 0;
            gif_fsal_block_read_avg = 0;
            for (i = 0; i < gif_fsal_block_read_entry_cnt; i++)
            {
               gif_fsal_block_read_avg += gif_fsal_block_read[i];
            }   
            gif_fsal_block_read_avg /= gif_fsal_block_read_entry_cnt;
         }
         gif_fsal_block_read_idx &= (gif_fsal_block_read_entry_cnt - 1);
      }
      return;
   }
   else if (FSAL_SEEK_OVER_EOF == rtn)
   {
      //if read size over than filesize, read residue
      rtn = FSAL_Direct_GetCurPos(h, &cur_position);
      rtn = FSAL_Direct_GetFileSize(h, &filesize);
      rtn = FSAL_Read(h, array, (filesize - cur_position));
      if ((gif_fsal_read_block_perf_log) && (n > 50))
      {
         end = drv_get_current_time();
         gif_fsal_block_read[gif_fsal_block_read_idx++] = drv_get_duration_tick(start, end);
         //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_fsal_gets() FSAL_Direct=>%d size = %dticks. \n", n, drv_get_duration_tick(start, end));
         if (gif_fsal_block_read_idx == gif_fsal_block_read_entry_cnt)
         {
            kal_uint32 i = 0;
            gif_fsal_block_read_avg = 0;
            for (i = 0; i < gif_fsal_block_read_entry_cnt; i++)
            gif_fsal_block_read_avg += gif_fsal_block_read[i];
            gif_fsal_block_read_avg /= gif_fsal_block_read_entry_cnt;
         }
         gif_fsal_block_read_idx &= (gif_fsal_block_read_entry_cnt - 1);
      }
   }
   else
   {
      _gif_error_raise();
   }
}
#else //GIF_FSAL_RD_PERF_LOG
void _gif_fsal_gets (STFSAL *h, kal_uint8* array, kal_uint16 n)
{
   kal_uint32 cur_position, filesize, rtn;

   rtn = FSAL_Read(h, array, n);
   if (FSAL_OK == rtn)
   {
      return;
   }
   else if (FSAL_SEEK_OVER_EOF == rtn)
   {
      //if read size over than filesize, read residue
      rtn = FSAL_Direct_GetCurPos(h, &cur_position);
      rtn = FSAL_Direct_GetFileSize(h, &filesize);
      rtn = FSAL_Read(h, array, (filesize - cur_position));
   }
   else
   {
      _gif_error_raise();
   }
}
#endif //GIF_FSAL_RD_PERF_LOG


kal_uint32 _gif_fsal_tell (STFSAL *h)
{
   kal_uint32 cur_position = 0;

   if (FSAL_OK != FSAL_GetCurPos(h, &cur_position))
   {
      _gif_error_raise();
   }
   return cur_position;
}



kal_bool _gif_fsal_is_eof (STFSAL* h)
{
   kal_uint32 cur_position = 0, cur_filesize = 0;

   FSAL_GetFileSize(h, &cur_filesize);
   FSAL_GetCurPos(h, &cur_position);

   if ((cur_filesize-1) <= cur_position)
   {
     return KAL_TRUE;
   }
   else
   {
      return KAL_FALSE;
   }
}


kal_uint8 _gif_fsal_get_u8(STFSAL* h)
{
   kal_uint8 output = 0;

   if (FSAL_OK != FSAL_Read_Bytes(h, &output, 1))
   {
      _gif_error_raise();
   }
   return output;
}


kal_uint8 _gif_fsal_peek_u8 (STFSAL* h)
{
   kal_uint8 output = 0;

   if (FSAL_OK != FSAL_Peek_Bytes(h, &output, 1))
   {
      _gif_error_raise();
   }
   return output;
}



kal_uint8 _gif_fsal_peek_u8_n (STFSAL* h, kal_uint32 offset)
{
   kal_uint8 output = 0;
   kal_uint32 cur_position;

   FSAL_GetCurPos(h, &cur_position);
   if (FSAL_OK != FSAL_Seek(h, (cur_position+offset)))
   {
     _gif_error_raise();
   }

   if (FSAL_OK != FSAL_Read_Bytes(h, &output, 1))
   {
      _gif_error_raise();
   }
   FSAL_Seek(h, cur_position);

   return output;
}



kal_uint16 _gif_fsal_get_u16 (STFSAL* h)
{
   kal_uint16 output = 0;

   if (FSAL_OK != FSAL_Read_Bytes(h, (kal_uint8*)&output,2))
   {
      _gif_error_raise();
   }
   return output;
}



kal_uint32 _gif_fsal_get_u24 (STFSAL* h)
{
   kal_uint32 output = 0;

   if (FSAL_OK != FSAL_Read_Bytes(h, (kal_uint8*)&output,3))
   {
     _gif_error_raise();
   }
   return output;
}



#if defined(GIF_FSAL_RD_PERF_LOG)
#define gifv2_fsal_block_read_entry_cnt 512
kal_uint32 gifv2_fsal_block_read[gif_fsal_block_read_entry_cnt];
kal_uint32 gifv2_fsal_block_read_idx = 0;
kal_uint32 gifv2_fsal_block_read_avg;
kal_uint32 gifv2_fsal_block_read_size = 255;
kal_bool gifv2_fsal_read_block_perf_log = 0;

GIF_FSAL_STATUS_ENUM _gifv2_fsal_gets (STFSAL *h, kal_uint8* array, kal_uint16 n)
{
   kal_uint32 cur_position, filesize, rtn;
   kal_uint32 start, end;

   start = drv_get_current_time();
   rtn = FSAL_Read(h, array, n);
   if (FSAL_OK == rtn)
   {
      if ((gifv2_fsal_read_block_perf_log) && (n > 50))
      {
         end = drv_get_current_time();
         gifv2_fsal_block_read[gif_fsal_block_read_idx++] = drv_get_duration_tick(start, end);
         //SW_GIF_TRACE(MOD_MMI, "[gif] - _gifv2_fsal_gets() FSAL_Read=>%d size = %dticks. \n", n, drv_get_duration_tick(start, end));
         if (gifv2_fsal_block_read_idx == gifv2_fsal_block_read_entry_cnt)
         {
            kal_uint32 i = 0;
            gifv2_fsal_block_read_avg = 0;
            for (i = 0; i < gifv2_fsal_block_read_entry_cnt; i++)
            {
               gifv2_fsal_block_read_avg += gifv2_fsal_block_read[i];
            }   
            gifv2_fsal_block_read_avg /= gifv2_fsal_block_read_entry_cnt;
         }
         gifv2_fsal_block_read_idx &= (gifv2_fsal_block_read_entry_cnt - 1);
      }
      return GIF_FSAL_OK;
   }
   else if (FSAL_SEEK_OVER_EOF == rtn)
   {
      //if read size over than filesize, read residue
      rtn = FSAL_Direct_GetCurPos(h, &cur_position);
      rtn = FSAL_Direct_GetFileSize(h, &filesize);
      rtn = FSAL_Read(h, array, (filesize - cur_position));
      if ((gifv2_fsal_read_block_perf_log) && (n > 50))
      {
         end = drv_get_current_time();
         gifv2_fsal_block_read[gif_fsal_block_read_idx++] = drv_get_duration_tick(start, end);
         //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_fsal_gets() FSAL_Direct=>%d size = %dticks. \n", n, drv_get_duration_tick(start, end));
         if (gif_fsal_block_read_idx == gifv2_fsal_block_read_entry_cnt)
         {
            kal_uint32 i = 0;
            gifv2_fsal_block_read_avg = 0;
            for (i = 0; i < gifv2_fsal_block_read_entry_cnt; i++)
                gifv2_fsal_block_read_avg += gif_fsal_block_read[i];
            gifv2_fsal_block_read_avg /= gifv2_fsal_block_read_entry_cnt;
         }
         gifv2_fsal_block_read_idx &= (gifv2_fsal_block_read_entry_cnt - 1);
      }
      return GIF_FSAL_OK;
   }
   else
   {
      return GIF_FSAL_FAIL;
   }
}
#else //GIF_FSAL_RD_PERF_LOG
GIF_FSAL_STATUS_ENUM _gifv2_fsal_gets (STFSAL *h, kal_uint8* array, kal_uint16 n)
{
   kal_uint32 cur_position, filesize, rtn;

   rtn = FSAL_Read(h, array, n);
   if (FSAL_OK == rtn)
   {
      return GIF_FSAL_OK;
   }
   else if (FSAL_SEEK_OVER_EOF == rtn)
   {
      //if read size over than filesize, read residue
      rtn = FSAL_Direct_GetCurPos(h, &cur_position);
      rtn = FSAL_Direct_GetFileSize(h, &filesize);
      rtn = FSAL_Read(h, array, (filesize - cur_position));
      return GIF_FSAL_OK;
   }
   else
   {
      return GIF_FSAL_FAIL;
   }
}
#endif //GIF_FSAL_RD_PERF_LOG


GIF_FSAL_STATUS_ENUM _gifv2_fsal_tell (STFSAL *h, kal_uint32 *cur_position)
{
   if (FSAL_OK != FSAL_GetCurPos(h, cur_position))
   {
      return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;;
}



GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_size(STFSAL* h, kal_uint32 *cur_filesize)
{
   if (FSAL_OK != FSAL_GetFileSize(h, cur_filesize))
   {
     return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;;
}


GIF_FSAL_STATUS_ENUM _gifv2_fsal_is_eof (STFSAL* h, kal_bool *isEof)
{
   kal_uint32 cur_position = 0, cur_filesize = 0;

   if (FSAL_OK != FSAL_GetFileSize(h, &cur_filesize))
   {
     return GIF_FSAL_FAIL;
   }

   if (FSAL_OK != FSAL_GetCurPos(h, &cur_position))
   {
     return GIF_FSAL_FAIL;
   }

   if ((cur_filesize-1) <= cur_position)
   {
     *isEof = KAL_TRUE;
   }
   else
   {
     *isEof = KAL_FALSE;
   }
   return GIF_FSAL_OK;;
}



GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_u8(STFSAL* h, kal_uint8* val)
{
   if (FSAL_OK != FSAL_Read_Bytes(h, val, 1))
   {
      return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;
}


GIF_FSAL_STATUS_ENUM _gifv2_fsal_peek_u8 (STFSAL* h, kal_uint8* val)
{
   kal_uint8 output = 0;

   if (FSAL_OK != FSAL_Peek_Bytes(h, val, 1))
   {
      return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;
}


GIF_FSAL_STATUS_ENUM _gifv2_fsal_peek_u8_n (STFSAL* h, kal_uint32 offset, kal_uint8* val)
{
   kal_uint32 cur_position;

   FSAL_GetCurPos(h, &cur_position);
   if (FSAL_OK != FSAL_Seek(h, (cur_position+offset)))
   {
     return GIF_FSAL_FAIL;
   }

   if (FSAL_OK != FSAL_Read_Bytes(h, val, 1))
   {
      return GIF_FSAL_FAIL;
   }
   FSAL_Seek(h, cur_position);

   return GIF_FSAL_OK;
}


GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_u16 (STFSAL* h, kal_uint16 *output)
{
   if (FSAL_OK != FSAL_Read_Bytes(h, (kal_uint8*)output,2))
   {
      return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;
}



GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_u24 (STFSAL* h, kal_uint32 *output)
{
   if (FSAL_OK != FSAL_Read_Bytes(h, (kal_uint8*)output, 3))
   {
     return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;
}


GIF_FSAL_STATUS_ENUM _gifv2_fsal_flush (STFSAL* h, kal_uint32 count)
{
   if (FSAL_OK != FSAL_Skip_Bytes(h, count))
   {
     return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;
}


GIF_FSAL_STATUS_ENUM _gifv2_fsal_seek(STFSAL* h, kal_uint32 offset)
{
   if (FSAL_OK != FSAL_Seek(h, offset))
   {
     return GIF_FSAL_FAIL;
   }
   return GIF_FSAL_OK;
}



