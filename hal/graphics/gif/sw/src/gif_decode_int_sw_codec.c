/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This c file is created from ImageMagick gif.c to decode a gif image. The    %
% We will add the following comments to note ImageMagick code segment.        %
%                                                                             %
%  // ImageMagick Open Source Code Segment Start  //                          %
%  // ImageMagick Open Source Code Segment   End  //                          %
%                                                                             %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                             GGGG  IIIII  FFFFF                              %
%                            G        I    F                                  %
%                            G  GG    I    FFF                                %
%                            G   G    I    F                                  %
%                             GGG   IIIII  F                                  %
%                                                                             %
%            Read/Write Compuserv Graphics Interchange Format.                %
%                                                                             %
%                              Software Design                                %
%                                John Cristy                                  %
%                                 July 1992                                   %
%                                                                             %
%  Copyright 1999-2005 ImageMagick Studio LLC, a non-profit organization      %
%  dedicated to making software imaging solutions freely available.           %
%                                                                             %
%  You may not use this file except in compliance with the License.  You may  %
%  obtain a copy of the License at                                            %
%                                                                             %
%    http://www.imagemagick.org/script/license.php                            %
%                                                                             %
%  Unless required by applicable law or agreed to in writing, software        %
%  distributed under the License is distributed on an "AS IS" BASIS,          %
%  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   %
%  See the License for the specific language governing permissions and        %
%  limitations under the License.                                             %
%                                                                             %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
*/

/*******************************************************************************
 * Filename:
 * ---------
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Gif related.
 *
 * Author:
 * -------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/****************************************************************************
* Include
*****************************************************************************/
#ifndef GIF_WIN32
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "fsal.h"
#include "kal_public_api.h"
#include "wchar.h"
#include "setjmp.h"
#include "string.h"
#include "drv_gfx_stack_switch_manager.h"
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
#endif

#include "gif_decode_int_sw.h"
#include "gif_decode_int_sw_util.h"
#include "gif_parse.h"
#ifndef SWGIF_VC_PROJ
#include "lcd_sw_rnd.h"
#else
#include "swgif_wrapper.h"
#endif

#if defined(__MTK_TARGET__)
#pragma Otime
#endif /* defined(__MTK_TARGET__) */

/* The cacheable pragma can be be removed after MAUI set all buffer default cacheable */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "CACHEDZI",  rwdata = "CACHEDRW"
#endif

#if defined(__GFX_SLIM_THUMB_SWITCH__)
	#pragma thumb
#else
	#pragma arm
#endif	

#define INIT_SRC(INPUT,SIZE) FSAL_Seek(pfsal_handle, 0)
#define PEEK_U8(X)           (X = _gif_fsal_peek_u8(pfsal_handle))
#define PEEK_U8_N(X,OFFSET)  (X = _gif_fsal_peek_u8_n(pfsal_handle, OFFSET))

#define GETS(POINTER,ARRAY,N)             \
{                                         \
   POINTER = ARRAY;                       \
   _gif_fsal_gets(pfsal_handle, ARRAY, N);\
}


#define FLUSH(X)      FSAL_Skip_Bytes(pfsal_handle, X)
#define SEEK(OFFSET)  FSAL_Seek(pfsal_handle, OFFSET)
#define IS_EOF()      _gif_fsal_is_eof(pfsal_handle)
extern KAL_ADM_ID     g_gif_sw_disposal_pool_id;
extern kal_bool       g_gif_sw_using_disposal;

extern STFSAL*        pfsal_handle;
extern kal_int16      *g_gif_sw_stack;

extern kal_int32      *g_gif_sw_tree_buffer;
extern gif_sw_color   *g_gif_sw_local_palette;
extern kal_uint16     g_gif_sw_transparent_index;
extern kal_uint16     g_gif_sw_palette_size;

extern gif_sw_image_struct  g_gif_sw_cache[GIF_SW_CACHE_COUNT];
extern kal_int16      g_gif_sw_cache_last_index;

extern kal_bool       g_gif_sw_dest_source_key_enable;
extern kal_uint32     g_gif_sw_dest_source_key;

//extern kal_int16      *g_gif_sw_resizer_buffer;
//extern kal_int32      g_gif_sw_resizer_buffer_elements_cnt;

extern gif_sw_bitblt_func            g_gif_sw_bitblt;
extern gif_sw_layer_set_palette_func g_gif_sw_layer_set_palette;
extern gif_sw_anim_set_delay_func    g_gif_sw_anim_set_delay;
extern gif_sw_image_progress_callback_func g_gif_sw_image_progress_callback;

extern gif_sw_color   *g_gif_sw_current_palette;
extern kal_bool       g_gif_sw_decoder_is_bypass_color;
extern gif_sw_color   g_gif_sw_decoder_bypass_color;
extern gif_sw_color   g_gif_sw_background_color;
extern gif_sw_color_from_rgb_func   g_gif_sw_act_color_from_rgb;
extern gif_sw_get_pixel_func        g_gif_sw_act_get_pixel;
extern void* (*g_gif_malloc)(kal_uint32 size);

extern gif_sw_resizer_update_wantxy gif_sw_resizer_update_wanty;
//extern gif_sw_image_struct  *pcurrent_match_gif_sw_cache;

/****************************************************************************
* Global Variable
*****************************************************************************/
/* destination layer information */

#define GIF_SUPPORT_SET_PALETTE_FORMAT

/****************************************************************************
* Static Declaration
*****************************************************************************/
typedef enum
{
   FSAL_ACCESS_U8 = 1,
   FSAL_ACCESS_U16 = 2,
   FSAL_ACCESS_U24 = 3,
   FSAL_ACCESS_U32 = 4
}FSAL_ACCESS_SIZE_ENUM;

kal_uint32 _get_data(FSAL_ACCESS_SIZE_ENUM byteNum, STFSAL* handle)
{
   kal_uint32 val = 0;

   if (FSAL_OK != FSAL_Read_Bytes(handle, (kal_uint8*)&val, byteNum))
   {
      _gif_error_raise();
   }
   return val;
}


__inline static void put_pixel_with_transparent_disable(kal_int32* want_sx, gif_sw_color c, kal_bool want_draw)
{
   gif_sw_resizer_put(want_sx, c, KAL_TRUE);
}

__inline static void put_pixel_with_transparent_enable(kal_int32* want_sx, gif_sw_color c,kal_bool want_draw)
{
   gif_sw_resizer_put(want_sx,c, want_draw);
}


/*****************************************************************************
 * FUNCTION
 *  GIF_SW_CODEC
 * DESCRIPTION
 *  decode data of one frame of gif image
 * PARAMETERS
 *  GIF_ox                   [IN]   Position at which the GIF image is to be displayed
 *  GIF_oy                   [IN]   Position at which the GIF image is to be displayed
 *  resized_width            [IN]   resize image to this width
 *  resized_height           [IN]   resize image to this height
 *  transparent_index        [IN]   transparent color index
 *  cache                    [IN]   cache struct of this frame
 *  frame_counter            [IN]   the max frame index that is able to draw succeefully in the gif animation
 *  transparent_enable       [IN]   enable background transparent
 * RETURNS
 *  void
 *****************************************************************************/


void _gif_sw_codec(
                kal_int32 GIF_ox,
                kal_int32 GIF_oy,
                kal_int32 resized_width,
                kal_int32 resized_height,
                kal_uint16 transparent_index,
                gif_sw_image_struct *cache,
                kal_int32 frame_counter,
                kal_bool transparent_enable,
                kal_bool isResized,
                GIF_COLOR_FORMAT_ENUM gif_color_format,
                GIF_COLOR_FORMAT_ENUM palette_format)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 src_clipx1, src_clipy1, src_clipx2, src_clipy2;
   int image_rows;
   int image_cols;
   kal_bool is_interlace;
   GIF_STATUS_ENUM status;
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   //kal_uint32 start, end;
   //start = drv_get_current_time();
   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_codec(): Enter. GIF(ox,oy)=(%d,%d), resized_width=%d, resized_height=%d\n", GIF_ox, GIF_oy, resized_width, resized_height);

   src_clipx1 = _get_data(FSAL_ACCESS_U16, pfsal_handle); /* X */
   src_clipy1 = _get_data(FSAL_ACCESS_U16, pfsal_handle); /* Y */

   image_cols = _get_data(FSAL_ACCESS_U16, pfsal_handle); /* W */
   image_rows = _get_data(FSAL_ACCESS_U16, pfsal_handle); /* H */

   src_clipx2 = src_clipx1 + image_cols - 1;
   src_clipy2 = src_clipy1 + image_rows - 1;

   // If need not to draw, still need to decode to get correct next frame position
   status = gif_sw_resizer_init(
           cache->image_width,
           cache->image_height,
           src_clipx1,
           src_clipy1,
           src_clipx2,
           src_clipy2,
           GIF_ox,
           GIF_oy,
           GIF_ox + resized_width - 1,
           GIF_oy + resized_height - 1,
           gif_color_format);

   if (status != GIF_STATUS_OK)   
   {
      /* decode limitation, output width too large */
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_codec() Fail: output width too large \n");
      //GIF_SW_RAISE(1);
      GIF_SW_RAISE(status);
   }

   cache->last_frame_x1 = (kal_int16) GIF_SW_RESIZER.want_dx1 - GIF_ox;
   cache->last_frame_y1 = (kal_int16) GIF_SW_RESIZER.want_dy1 - GIF_oy;
   cache->last_frame_x2 = (kal_int16) GIF_SW_RESIZER.want_dx2 - GIF_ox;
   cache->last_frame_y2 = (kal_int16) GIF_SW_RESIZER.want_dy2 - GIF_oy;

   {
      kal_int32 n;

      n = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;

      /* W05.39 Fix n value will be changed and the interlace attribute may be incorrect */
      if (n & 0x40)
      {
         is_interlace = KAL_TRUE;
      }
      else
      {
         is_interlace = KAL_FALSE;
      }
      if (n & 0x80)
      {
         gif_sw_color_from_rgb_func palette_color_from_rgb;
         kal_int32 i;

         n = 1 << ((n & 0x7) + 1);

         g_gif_sw_current_palette = g_gif_sw_local_palette;

         if (gif_color_format == GIF_SW_COLOR_FORMAT_8)
         {
#if defined(GIF_SUPPORT_SET_PALETTE_FORMAT)
            palette_color_from_rgb = gif_sw_color_from_rgb_array[palette_format];
#else
            palette_color_from_rgb = GIF_SW_PALETTE_COLOR_FROM_RGB;
#endif
         }
         else
         {
            palette_color_from_rgb = g_gif_sw_act_color_from_rgb;
         }

         /* Read the local color palette */
         if (n)
         {
            g_gif_sw_palette_size = n;
         }

         for (i = 0; i < n; i++)
         {
            kal_uint8 R, G, B;

            R = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
            G = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
            B = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;

            g_gif_sw_current_palette[i] = palette_color_from_rgb(0xFF, R, G, B);
            if ((g_gif_sw_dest_source_key_enable && g_gif_sw_current_palette[i] == g_gif_sw_dest_source_key)
                || (g_gif_sw_decoder_is_bypass_color && g_gif_sw_current_palette[i] == g_gif_sw_decoder_bypass_color))
            {
               g_gif_sw_current_palette[i] ^= 1;
            }
         }

         /* current layer is index color layer */
         if (gif_color_format == GIF_SW_COLOR_FORMAT_8)
         {
            for (i = 0; i < (kal_int32) n; i++)
            {
               if(g_gif_sw_layer_set_palette)
               {
                  (*g_gif_sw_layer_set_palette)((kal_uint8) i, g_gif_sw_current_palette[i]);
               }
               g_gif_sw_current_palette[i] = i;
            }
         }
      }
      else    /* use global palette */
      {
         g_gif_sw_current_palette = cache->palette;
      }
   }

   {
#define MaxStackSize  4096
#define NullCode  (~0)

      int offset, y;
      register int x = 0;
      register unsigned char *c;
      register unsigned int datum;
      kal_uint32 consump_byte_cnt = 0;
      kal_uint32 read_byte_cnt = 0;
      kal_uint32 data_block_start_addr = 0;

      short *prefix;
      int count;
      unsigned char *packet, *pixel_stack, *suffix, *top_stack;
      unsigned int available, bits, clear, code, code_mask, code_size,
                   data_size, first, end_of_information, in_code, old_code, pass;
      void (*put_pixel)(kal_int32* want_sx,gif_sw_color c,kal_bool want_draw);
      kal_int32 wantx = 0;
      kal_int32 wantx0 = 0;
      wantx0 = GIF_SW_RESIZER.want_start_sx;//(kal_int16)((((GIF_SW_RESIZER.want_start_dx - GIF_ox) * GIF_SW_RESIZER.src_width_range << 1) + GIF_SW_RESIZER.dest_width_range) / (GIF_SW_RESIZER.dest_width_range << 1));

      put_pixel = put_pixel_with_transparent_enable;
      if (!transparent_enable)
      {
         put_pixel = put_pixel_with_transparent_disable;
      }


      /* allocate decoder tables */
      {
         kal_uint8 *mem = (kal_uint8*) g_gif_sw_tree_buffer;

         prefix = (short*)mem;
         mem += MaxStackSize * sizeof(*prefix);
         suffix = (unsigned char*)mem;
         mem += MaxStackSize;
         pixel_stack = (unsigned char*)mem;  /* use MaxStackSize+1  bytes; */
      }

      /* Initialize GIF data stream decoder. */

      data_size = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
      if (data_size > 8)
      {
         SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_codec() Fail: CorruptImage \n");
         //GIF_SW_RAISE(1);   /* CorruptImage */
         GIF_SW_RAISE(GIF_STATUS_DEC_ERROR_INVALID_FILE);   /* CorruptImage */
      }

      clear = 1 << data_size;
      end_of_information = clear + 1;
      available = clear + 2;
      old_code = NullCode;
      code_size = data_size + 1;
      code_mask = (1 << code_size) - 1;
      for (code = 0; code < clear; code++)
      {
         prefix[code] = 0;
         suffix[code] = (unsigned char)code;
      }

      /* decode gif pixel stream */
      datum = 0;
      bits = 0;
      c = 0;
      count = 0;
      first = 0;
      offset = 0;
      pass = 0;
      top_stack = pixel_stack;
      data_block_start_addr =  _gif_fsal_tell(pfsal_handle);

      for (y = src_clipy1; y <= src_clipy2; y++)
      {
         if(g_gif_sw_image_progress_callback)
         {
            if(!(*g_gif_sw_image_progress_callback)())
            {
                SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_codec() Fail: GIF_SW_RET_DECODE_TIME_OUT. x=%d, y=%d \n", x, y);
                //GIF_SW_RAISE(GIF_SW_RET_DECODE_TIME_OUT);
                GIF_SW_RAISE(GIF_STATUS_DECODE_TIME_OUT);
            }
         }

         /* move to 0,offset */
         wantx = wantx0; 
         for (x = src_clipx1; x <= src_clipx2;)
         {
             kal_int32 decoded_pixel_count = 0;
             kal_int32 next_dst_data_distance = 0;

             /* ImageMagick Open Source Code Segment Start  */
             if (top_stack == pixel_stack)
             {
                if (bits < code_size)
                {
                   /* Load bytes until there is enough bits for a code. */
                   if (count == 0)
                   {
                       /* Read a new data block. */
                       count = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
                       read_byte_cnt += count;
                       if (count == 0)
                       {
                          break;
                       }
                       packet = (unsigned char*)g_gif_sw_stack;    /* this will only use 256 bytes */
                       GETS(c, packet, count);
                   }
                   datum += ((unsigned int)(*c)) << bits;
                   bits += 8;
                   c++;
                   count--;
                   continue;
                }

                /* Get the next code. */
                code = datum & code_mask;
                datum >>= code_size;
                bits -= code_size;

                /* Interpret the code */
                if ((code > available) || (code == end_of_information))
                {
                   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_codec() Fail: Interpret the code \n");
                   FLUSH(count);
                   while (!IS_EOF()) // skip he remaining data blocks of the frame.
                   {
                      count = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
                      if(count == 0)
                      {
                         break;
                      }
                      FLUSH(count);
                   }
                   return;
                }

                if (code == clear)
                {
                   /* Reset decoder. */
                   code_size = data_size + 1;
                   code_mask = (1 << code_size) - 1;
                   available = clear + 2;
                   old_code = NullCode;
                   continue;
                }

                if (old_code == NullCode)
                {
                   *top_stack++ = suffix[code];
                   old_code = code;
                   first = code;
                   continue;
                }
                in_code = code;
                if (code >= available)
                {
                   *top_stack++ = (unsigned char)first;
                   code = old_code;
                }

                while (code >= clear)
                {
                   if ((top_stack - pixel_stack) >= MaxStackSize)
                   {
                      break;
                   }
                   *top_stack++ = suffix[code];
                   code = (unsigned int)prefix[code];
                }
                first = (unsigned int)suffix[code];
                /* Add a new string to the string table, */

                if ((top_stack - pixel_stack) >= MaxStackSize)
                {
                   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_codec() Fail: (top_stack - pixel_stack) >= MaxStackSize)\n");
                   break;
                }

                if (available >= MaxStackSize)
                {
                   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_codec() Fail: available >= MaxStackSize\n");
                   break;
                }

                *top_stack++ = (unsigned char)first;
                prefix[available] = (short)old_code;
                suffix[available] = (unsigned char)first;
                available++;
                if (((available & code_mask) == 0) && (available < MaxStackSize))
                {
                   code_size++;
                   code_mask += available;
                }
                old_code = in_code;
             }

             top_stack--;
             /* ImageMagick Open Source Code Segment   End  */

             /* Pop a pixel off the pixel stack. */
             if (isResized)
             {
                decoded_pixel_count = top_stack - pixel_stack; //how many decoded pixels
                if ((src_clipy1 + offset) == GIF_SW_RESIZER.want_sy)
                {
                   if (wantx >= x)
                   {
                      next_dst_data_distance = wantx - x;// how long the distance including x
                   }
                   else
                   {
                      next_dst_data_distance = src_clipx2 - x;
                   }

                   if (decoded_pixel_count < next_dst_data_distance)
                   {
                      //it means all the decoded data this time shall be discarded.
                      x += decoded_pixel_count;
                      top_stack -= (decoded_pixel_count);
                   }
                   else
                   {
                      //some pixels in the decoded pixels shall be output to the dst image.
                      x += next_dst_data_distance;//GIF_SW_RESIZER.want_sx;
                      top_stack -= (next_dst_data_distance);
                   }
                }
                else
                {
                   //The source lineY shall be discarded for the resized image.
                   //wantx shall be GIF_SW_RESIZER.want_sx_table for all x (no need to update wantx)
                   if ((x + decoded_pixel_count) > src_clipx2)
                   {
                      next_dst_data_distance = src_clipx2 - x;
                   }
                   else
                   {
                      next_dst_data_distance = decoded_pixel_count;
                   }
                   x += next_dst_data_distance;//GIF_SW_RESIZER.want_sx;
                   top_stack -= (next_dst_data_distance);
                }
             }

             if ((x == wantx) && ((src_clipy1 + offset) == GIF_SW_RESIZER.want_sy))
             {
                kal_uint32 index = (kal_uint32) *top_stack;
                put_pixel(&wantx, ((gif_sw_color) g_gif_sw_current_palette[index]), ((kal_bool) (transparent_index != index)));
             }
             x++;
         }   /* x loop */
         gif_sw_resizer_update_wanty(&wantx, is_interlace);

         if (!is_interlace)
         {
            offset++;
         }
         else
         {
            switch (pass)
            {
               case 0:
               default:
               {
                   offset += 8;
                   if (offset >= image_rows)
                   {
                      pass++;
                      offset = 4;
                   }
                   break;
               }
               case 1:
               {
                  offset += 8;
                  if (offset >= image_rows)
                  {
                     pass++;
                     offset = 2;
                  }
                  break;
               }
               case 2:
               {
                  offset += 4;
                  if (offset >= image_rows)
                  {
                     pass++;
                     offset = 1;
                  }
                  break;
               }
               case 3:
               {
                  offset += 2;
                  break;
               }
            }
            gif_sw_resizer_update_interlaced_want_sy(isResized, &wantx, src_clipy1 + offset);
         }
         if (x <= src_clipx2)
         {
            //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_codec() Fail: x:%d <= src_clipx2:%d \n", x, src_clipx2);
            break;
         }
      }   /* y loop */
      if (y <= src_clipy2)
      {
          //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_codec() Fail:y:%d <= src_clipy2:%d \n", y, src_clipy2);
          //GIF_SW_RAISE(1);
          GIF_SW_RAISE(GIF_STATUS_DEC_ERROR_PARSE);
      }

      //if (1)
      {
         kal_uint8 val;
         kal_int32 remaining_cnt;
         kal_uint32 len, curpos;

         curpos = _gif_fsal_tell(pfsal_handle);
         remaining_cnt = (data_block_start_addr + read_byte_cnt) - curpos;
         if (remaining_cnt > 0)
         {
            //kal_uint32 dbg_idx = 0;
            //for (dbg_idx = 0; dbg_idx < (remaining_cnt); dbg_idx++)
            //{
            //  val = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
            //  printf("Flush The Remaining %dth Byte = %d.\n", dbg_idx, val);
            //}
            FLUSH(remaining_cnt);
            //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_codec(): Flush1 %d bytes.\n", remaining_cnt);
         }
      }

      //if (1)
      {
         kal_uint32 len, curpos;
         kal_uint8 val;
         len = 0;
         //Flush the remaining data.

         while (1) // skip data blocks
         {
            count = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
            curpos = _gif_fsal_tell(pfsal_handle);
         
            len += count;
            if (count == 0) //Block Terminator
            {
               //printf("Count = 0, Flush %d data.\n", len);
               break;
            }
         
            FLUSH(count);
            //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_codec(): Flush2 %d bytes.\n", count);
            //if (count > 0)
            //{
            //   kal_uint32 dbg_idx = 0;
            //   for (dbg_idx = 0; dbg_idx < len; dbg_idx++)
            //   {
            //      val = _get_data(FSAL_ACCESS_U8, pfsal_handle) & 0xFF;
            //      printf("Flush %dth byte = %d.\n", curpos+dbg_idx, val);
            //   }
            //}
         }
      }
   }   /* codec block */

   //end = drv_get_current_time();
   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_codec() End. %d ticks \n", drv_get_duration_tick(start, end));
   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_codec(): Leave. FileCurPos = %d\n", _gif_fsal_tell(pfsal_handle));
}



/*****************************************************************************
 * FUNCTION
 *  GIF_DRAW_INTERNAL
 * DESCRIPTION
 *  Displays a given frame of the GIF file
 * PARAMETERS
 *  ox                      [IN]        Position at which the GIF image is to be displayed
 *  oy                      [IN]        Position at which the GIF image is to be displayed
 *  is_resized              [IN]        need to resize or not
 *  resized_width           [IN]        resize image to this width
 *  resized_height          [IN]        resize image to this width
 *  src                     [IN]        src address if source from mem
 *  size                    [IN]        src size if source from mem
 *  cache_id                [IN]        cache id of this gif frame
 *  frame_number            [IN]        Frame number to load for animated GIF.
 *  use_disposal_method     [IN]        enable disposal feature
 *  transparent_enable      [IN]        enable background transparent
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/

kal_int32 _gif_sw_draw_internal(
            kal_int32 ox,
            kal_int32 oy,
            kal_bool is_resized,
            kal_int32 resized_width,
            kal_int32 resized_height,
            kal_uint8 *src,
            kal_uint32 size,
            kal_uint32 cache_id,
            kal_uint16 frame_number,
            kal_bool use_disposal_method,
            kal_bool transparent_enable,
            GIF_COLOR_FORMAT_ENUM gif_color_format,
            GIF_COLOR_FORMAT_ENUM palette_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 gif_done;
    kal_int32 frame_counter = 0;
    kal_uint16 transparent_index = 256;
    kal_uint16 temp_width, temp_height;
    kal_int32 n;
    kal_int16 lcd_idx;
    kal_int8 gif_is_hit_cache = 0;
    gif_sw_image_struct *cache;
    //kal_uint32 start, end;
    //kal_uint32 start_after_decode, end_after_decode;
    //start = drv_get_current_time();

    //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal(): Enter.\n");

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    INIT_SRC(src, size);

    // try to hit the cache and initialize the cache item
    {
       kal_int32 offset;

       /* If the frame_counter<frame_number, gif will decode from frame_counter to frame_number. */
       if (gif_sw_gif_hit_cache(cache_id, ox,oy, KAL_FALSE, frame_number, &lcd_idx, &frame_counter, &offset, KAL_TRUE))
       {
          gif_is_hit_cache = 1;
          SEEK(offset);
       }
       cache = &g_gif_sw_cache[lcd_idx];
       //pcurrent_match_gif_sw_cache = cache;
    }

    g_gif_sw_palette_size = 0;

    // /////////////////////////////////////////////////////////
    // read the GIF file signature
    if (frame_counter == 0)
    {
       kal_uint32 header;
       kal_uint32 bg_color_idx = 0;

       header = _get_data(FSAL_ACCESS_U24, pfsal_handle); //GET_U24(header);

       if (header != 0x464947) /* 'GIF' */
       {
          return GIF_SW_RET_FAILED;
       }

       ///////////////////////////////////////////////////////////
       // read the GIF dimension
       FLUSH(3);
       temp_width = _get_data(FSAL_ACCESS_U16, pfsal_handle); //GET_U16(temp_width);
       temp_height = _get_data(FSAL_ACCESS_U16, pfsal_handle); //GET_U16(temp_height);

       cache->image_width = temp_width;
       cache->image_height = temp_height;

       /*
        * Check the validity of clipping
        */
       if (ox > g_gif_sw_dest_clipx2 || oy > g_gif_sw_dest_clipy2 ||
           ox + temp_width - 1 < g_gif_sw_dest_clipx1 || oy + temp_height - 1 < g_gif_sw_dest_clipy1)
       {
          return GIF_SW_RET_SUCCEED;
       }

       /* ///////////////////////////////////////////////////////// */
       /*
        * Read the global color palette
        */
       n = _get_data(FSAL_ACCESS_U8, pfsal_handle); //GET_U8(n);

       bg_color_idx = _get_data(FSAL_ACCESS_U8, pfsal_handle);
       FLUSH(1);

       cache->has_gct = ((n & 0x80) > 0) ? 1 : 0;

       if (cache->has_gct)
       {
          kal_int32 i;
          gif_sw_color_from_rgb_func palette_color_from_rgb;

          n = 1 << ((n & 0x7) + 1);

          if (gif_color_format == GIF_SW_COLOR_FORMAT_8)
          {
#if defined(GIF_SUPPORT_SET_PALETTE_FORMAT)
             palette_color_from_rgb = gif_sw_color_from_rgb_array[palette_format];
#else
             palette_color_from_rgb = GIF_SW_PALETTE_COLOR_FROM_RGB;
#endif
          }
          else
          {
             palette_color_from_rgb = g_gif_sw_act_color_from_rgb;
          }

          /* Read the global color palette */
          if (n)
          {
             g_gif_sw_palette_size = n;
          }

          for (i = 0; i < n; i++)
          {
             kal_uint8 R, G, B;

             R = _get_data(FSAL_ACCESS_U8, pfsal_handle);
             G = _get_data(FSAL_ACCESS_U8, pfsal_handle);
             B = _get_data(FSAL_ACCESS_U8, pfsal_handle);
             cache->palette[i] = palette_color_from_rgb(0xFF, R, G, B);
             if ((g_gif_sw_dest_source_key_enable && cache->palette[i] == g_gif_sw_dest_source_key)
             ||  (g_gif_sw_decoder_is_bypass_color && cache->palette[i] == g_gif_sw_decoder_bypass_color))
             {
                cache->palette[i] ^= 1;
             }
          }

          /* current layer is index color layer */
          if (gif_color_format == GIF_SW_COLOR_FORMAT_8)
          {
             for (i = 0; i < (kal_int32) n; i++)
             {
                if(g_gif_sw_layer_set_palette)
                   (*g_gif_sw_layer_set_palette)((kal_uint8) i, cache->palette[i]);
                {
                   cache->palette[i] = i;
                }
             }
          }
       }
       //_gif_sw_set_background_color((gif_sw_color) cache->palette[bg_color_idx]);
       //MAUI_03107299
       g_gif_sw_cache[lcd_idx].original_background = g_gif_sw_background_color;
    }

    /* If resized width > original width or resized height > original height, do not resize */
    if (!is_resized
        || resized_width > cache->image_width
        || resized_height > cache->image_height)
    {
       resized_width = cache->image_width;
       resized_height = cache->image_height;
    }
    /* don't process resized_width/resized_height == 0*/
    if (resized_width == 0 || resized_height == 0)
    {
        return (GIF_SW_RET_SUCCEED);
    }

    /* first draw , we should keep 1 pixels background color for later used. */
    if (!gif_is_hit_cache)
    {
       ////MAUI_03107299
       //g_gif_sw_cache[lcd_idx].original_background = g_gif_sw_background_color;

       {
          kal_int32 x1;
          kal_int32 y1;
          x1 = ox;
          y1 = oy;

          if (x1 < g_gif_sw_dest_clipx1)
          {
             x1 = g_gif_sw_dest_clipx1;
          }
           if (y1 < g_gif_sw_dest_clipy1)
          {
             y1 = g_gif_sw_dest_clipy1;
          }

          /* If using disposal, alloc a memory to save the origianl background. */
          /* If memory is not enougn, use the 1 pixel background color to redraw the background. */
          /* Currently, only support "restore to background", not support "restore to previous". */
          if (g_gif_sw_using_disposal)
          {
             g_gif_sw_cache[lcd_idx].disposal_bg_buf_size = (resized_width * resized_height * DRV_MAINLCD_BIT_PER_PIXEL) >> 3;
             g_gif_sw_cache[lcd_idx].disposal_bg_buf = (kal_uint8 *)g_gif_malloc(g_gif_sw_cache[lcd_idx].disposal_bg_buf_size);

             //SW_GIF_TRACE(MOD_MMI, "[gif_hal_dbg] - _gif_sw_draw_internal() g_gif_sw_using_disposal=KAL_TRUE \n");
             if (g_gif_sw_cache[lcd_idx].disposal_bg_buf)
             {
                gif_sw_rect_struct dest_clip;

                dest_clip.x1 = 0;
                dest_clip.y1 = 0;
                dest_clip.x2 = resized_width - 1;
                dest_clip.y2 = resized_height - 1;

                /* copy the content of original background */
                if(g_gif_sw_bitblt)
                {
                   (*g_gif_sw_bitblt)(
                       g_gif_sw_dest_buf_ptr,  //dst
                       g_gif_sw_dest_buf_width,
                       x1,
                       y1,
                       resized_width,
                       resized_height,
                       cache->disposal_bg_buf, //src
                       resized_width,
                       0,
                       0,
                       dest_clip,
                       DRV_MAINLCD_BIT_PER_PIXEL);
                   //SW_GIF_TRACE(MOD_MMI, "[gif_hal_dbg] - _gif_sw_draw_internal() g_gif_sw_bitblt=KAL_TRUE \n");
                }
             }
          }
       }
    }
    // /////////////////////////////////////////////////////////
    // start decoding
    gif_done = 0;
    if(g_gif_sw_anim_set_delay)
    {
        (*g_gif_sw_anim_set_delay)(100); // default 100 ms
    }

    //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() Before Do-loop. CurPos=%d \n", _gif_fsal_tell(pfsal_handle));

    do
    {
       kal_uint8 tag;
       tag = _get_data(FSAL_ACCESS_U8, pfsal_handle); ///GET_U8(tag);
       switch (tag)
       {
          case '!':   /* Process the GIF extension block */
             //printf("extension block \n");
             //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() GIF extension block. CurPos=%d \n", _gif_fsal_tell(pfsal_handle));
             //GET_U8(tag);
             tag = _get_data(FSAL_ACCESS_U8, pfsal_handle);
             if (tag == 0xf9)
             {
                kal_uint8 byte_1, byte_2, byte_3, byte_4;
                kal_uint32 a;

                FLUSH(1);
                byte_1 = _get_data(FSAL_ACCESS_U8, pfsal_handle);
                byte_2 = _get_data(FSAL_ACCESS_U8, pfsal_handle);
                byte_3 = _get_data(FSAL_ACCESS_U8, pfsal_handle);
                byte_4 = _get_data(FSAL_ACCESS_U8, pfsal_handle);

                /*
                 * if diposal method is 2 (restore bg) or 3 (restore previous) and has gct,
                 * we will set restore bg flag on.
                 * We do not has enought memory to implement method 3, sepc recommand us to
                 * use method 2 to replace method 3.
                 */

                a = (kal_uint32)((byte_1 >> 2) & 0x03);
                if(a==2 || a==3)
                {
                    cache->disposal_method = a;
                }
                else
                {
                    cache->disposal_method = 0;
                }

                if (byte_1 & 0x01)
                {
                   transparent_index = byte_4;
                   g_gif_sw_transparent_index = transparent_index;
                }
                a = (((kal_uint32) (byte_3 << 8)) | (kal_uint32) (byte_2)) * 10; // delay time
                if(a == 0 ) a = 100; // use 100 ms as default time.
                if(g_gif_sw_anim_set_delay)
                {
                   (*g_gif_sw_anim_set_delay)(a);
                }
                FLUSH(1);
             }
             else
             {
                kal_int32 offset;

                while (1)
                {
                   //GET_U8(offset);
                   offset = _get_data(FSAL_ACCESS_U8, pfsal_handle);
                   if (offset == 0)
                   {
                      break;
                   }
                   FLUSH(offset);
                }
             }
             break;
          case ',':   /* Image descriptor (0x2C) */
             //printf("image descriptor \n");
             //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() Image descriptor. CurPos=%d \n", _gif_fsal_tell(pfsal_handle));
             /* restore background color */
             if (use_disposal_method)
             {
                if (gif_is_hit_cache)
                {
                   kal_int32 last_frame = ((kal_int32)frame_counter) - 1;
                   if ((last_frame < 0) && (cache->final_frame_index > 0))
                   {
                      last_frame = cache->final_frame_index;
                   }

                   /* apply last_disposal_method only when the the disposal_frame is the last frame. */
                   if(cache->last_disposal_method &&
                      (cache->disposal_frame == last_frame))
                   {
                      if (g_gif_sw_using_disposal && cache->disposal_bg_buf)
                      {
                         gif_sw_rect_struct dest_clip;

                         dest_clip.x1 = g_gif_sw_dest_clipx1;
                         dest_clip.y1 = g_gif_sw_dest_clipy1;
                         dest_clip.x2 = g_gif_sw_dest_clipx2;
                         dest_clip.y2 = g_gif_sw_dest_clipy2;
                         if(g_gif_sw_bitblt)
                         (*g_gif_sw_bitblt)(
                             cache->disposal_bg_buf,
                             resized_width,
                             cache->last_frame_x1,
                             cache->last_frame_y1,
                             cache->last_frame_x2 - cache->last_frame_x1 + 1,
                             cache->last_frame_y2 - cache->last_frame_y1 + 1,
                             g_gif_sw_dest_buf_ptr,
                             g_gif_sw_dest_buf_width,
                             ox + cache->last_frame_x1,
                             oy + cache->last_frame_y1,
                             dest_clip,
                             DRV_MAINLCD_BIT_PER_PIXEL);
                         //SW_GIF_TRACE(MOD_MMI, "[gif_hal_dbg] - _gif_sw_draw_internal() g_gif_sw_bitblt:A \n");
                      }
                      else
                      {
                         /* If not using disposal or memory is not enough,
                            use background color to redraw the background. */
                         gif_sw_draw_solid_rect(
                             ox + cache->last_frame_x1,
                             oy + cache->last_frame_y1,
                             ox + cache->last_frame_x2,
                             oy + cache->last_frame_y2,
                             cache->original_background);
                      }
                      //SW_GIF_TRACE(MOD_MMI, "[gif_hal_dbg] - _gif_sw_draw_internal() g_gif_sw_bitblt:B \n");
                   }
                   else if ((frame_number == 0) && (cache->final_frame_index > 0))
                   {
                      if (g_gif_sw_using_disposal)
                      {
                         /* clear the background when replay to the first frame */
                         if (cache->disposal_bg_buf)
                         {
                            gif_sw_rect_struct dest_clip;

                            dest_clip.x1 = g_gif_sw_dest_clipx1;
                            dest_clip.y1 = g_gif_sw_dest_clipy1;
                            dest_clip.x2 = g_gif_sw_dest_clipx2;
                            dest_clip.y2 = g_gif_sw_dest_clipy2;
                            if(g_gif_sw_bitblt)
                            (*g_gif_sw_bitblt)(
                                cache->disposal_bg_buf,
                                resized_width,
                                0,
                                0,
                                resized_width,
                                resized_height,
                                g_gif_sw_dest_buf_ptr,
                                g_gif_sw_dest_buf_width,
                                ox,
                                oy,
                                dest_clip,
                                DRV_MAINLCD_BIT_PER_PIXEL);
                             //SW_GIF_TRACE(MOD_MMI, "[gif_hal_dbg] - _gif_sw_draw_internal() g_gif_sw_bitblt:C \n");
                         }
                         else
                         {
                            gif_sw_draw_solid_rect(
                            ox,
                            oy,
                            ox + resized_width - 1,
                            oy + resized_height - 1,
                            cache->original_background);
                            //SW_GIF_TRACE(MOD_MMI, "[gif_hal_dbg] - _gif_sw_draw_internal() g_gif_sw_bitblt:D \n");
                         }
                      }
                   }
                } //if (gif_is_hit_cache)
             } //if (use_disposal_method)
             _gif_sw_codec(
                 ox,
                 oy,
                 resized_width,
                 resized_height,
                 transparent_index,
                 cache,
                 frame_counter,
                 transparent_enable,
                 is_resized,
                 gif_color_format,
                 palette_format);
             //start_after_decode = drv_get_current_time();
             //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() _gif_sw_codec done.\n");

             if (frame_counter > cache->final_frame_index)
             {
                cache->final_frame_index = frame_counter;
             }
             cache->disposal_frame = frame_counter;

             /* frame_counter should not larger than frame_number, if they are equal, gif_done=1 */
             if (frame_counter >= frame_number)
             {
                gif_done = 1;
             }

             gif_is_hit_cache = KAL_TRUE; // second pass should be in cache
             frame_counter++;
             if (frame_counter < MAX_GIF_FRAME_SUM)
             {
                cache->cache[frame_counter] = _gif_fsal_tell(pfsal_handle);//TELL();
                if (GIF_SW_RET_SUCCEED != gif_sw_get_next_frame_disposal_method(pfsal_handle, (GIF_DISPOSAL_METHOD_ENUM*)(&cache->frame_disposal_method[frame_counter])))
                {
                   _gif_error_raise();
                }
             }
             else
             {
                cache->cache[MAX_GIF_FRAME_SUM] = _gif_fsal_tell(pfsal_handle);//TELL();
                cache->latest_frame = frame_counter;
                if (GIF_SW_RET_SUCCEED != gif_sw_get_next_frame_disposal_method(pfsal_handle, (GIF_DISPOSAL_METHOD_ENUM*)(&cache->frame_disposal_method[MAX_GIF_FRAME_SUM])))
                {
                   _gif_error_raise();
                }

                if (FSAL_OK != FSAL_Seek(pfsal_handle, cache->cache[MAX_GIF_FRAME_SUM]))
                {
                  _gif_error_raise();
                }

             }
             cache->last_disposal_method = cache->disposal_method;

             /* peek if is last frame */
             if(!IS_EOF())
             {
                kal_uint8 a, b;
                PEEK_U8(a);
                PEEK_U8_N(b, 1);
                if (a == '\0' && b == ';')
                {
                   if (gif_done)
                   {
                      //end of file
                      return GIF_SW_RET_SUCCEED;
                   }
                   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_draw_internal() FailA. \n");
                   return GIF_SW_RET_FAILED;
                }
             }
             break;

          case '\0':
             //printf("end of file \n");
             //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() end of file. CurPos=%d \n", _gif_fsal_tell(pfsal_handle));
             if (IS_EOF())   /* Some pictures do not have trailer */
             {
                if (gif_done)   /* had rendered this frame */
                {
                   //end of file
                   return GIF_SW_RET_SUCCEED;
                   //return GIF_SW_RET_SUCCEED_END;
                }
                else
                {
                   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_draw_internal() FailB. \n");
                   return GIF_SW_RET_FAILED;
                }
             }
             break;

          case ';':   /* Trailer */
          {
             //printf("trailer \n");
             //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() Trailer. CurPos=%d \n", _gif_fsal_tell(pfsal_handle));
             if (gif_done)   /* had rendered this frame */
             {
                return GIF_SW_RET_SUCCEED;
             }
             else
             {
                SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_draw_internal() FailC. \n");
                return GIF_SW_RET_FAILED;
             }
             //break;
          }

         default:
         {
            SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_draw_internal() Invalid File. \n");
            return GIF_SW_RET_FAILED;
         }
       }
    }
    while (!gif_done && !IS_EOF());

    //end = drv_get_current_time();
    //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() End. %d ticks \n", drv_get_duration_tick(start, end));
    //end_after_decode = drv_get_current_time();
    //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal() DecodeDone_End. %d ticks \n", drv_get_duration_tick(start_after_decode, end_after_decode));

    if (gif_done)
    {
       return GIF_SW_RET_SUCCEED;
    }
    else
    {
       SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_draw_internal() FailD. \n");
       return GIF_SW_RET_FAILED;
    }
    //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_sw_draw_internal(): Leave.\n");
}



/*****************************************************************************
 * FUNCTION
 *  GIF_SW_GET_DIMENSION_INTERNAL
 * DESCRIPTION
 *  get dimension of gif image
 * PARAMETERS
 *  src          [IN]        src address if source from mem
 *  size         [IN]        src size if source from mem
 *  width        [OUT]       return widht of gif image
 *  height       [OUT]       return height of gif image
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
kal_int32 _gif_sw_get_dimension_internal(kal_uint8 *src, kal_uint32 size, kal_int32 *width, kal_int32 *height)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint32 header;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   INIT_SRC(src, size);

   //GET_U24(header);
   header = _get_data(FSAL_ACCESS_U24, pfsal_handle);

   if (header != 0x464947) /* 'GIF' */
   {
      *width = 0;
      *height = 0;
      return GIF_SW_RET_FAILED;
   }
   /*
    * read the GIF dimention
    */
   FLUSH(3);
   *width = _get_data(FSAL_ACCESS_U16, pfsal_handle); ///GET_U16(*width);
   *height = _get_data(FSAL_ACCESS_U16, pfsal_handle); ///GET_U16(*height);

   return GIF_SW_RET_SUCCEED;
}


