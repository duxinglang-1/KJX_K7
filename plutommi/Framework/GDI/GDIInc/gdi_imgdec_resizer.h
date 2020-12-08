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
 *  gdi_imgdec_resizer.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  IMGDEC resizer header
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

#ifndef __GDI_IMGDEC_RESIZER_H__
#define __GDI_IMGDEC_RESIZER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "gdi_datatype.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
struct _gdi_imgdec_resizer_struct
{
    U8 *dest;
    S32 bitsperpixels;
    S32 src_height_range;   /* Source */
    S32 dest_height_range;  /* Destination */
    S32 offset_dx;
    S32 offset_dy;

    S32 want_dx1, want_dx2; /* wanted rendering area */
    S32 want_dy1, want_dy2;

    S32 want_sx;    /* current wanted point (want_x,want_y) */
    S32 want_sy;

    S16 *want_sx_table;
    S16 *want_sx_table_end;
    S16 *next_want_sx;
    S32 next_want_dy;

    S32 dir_x;
    S32 dir_y;

    /* for non resize used */
    S32 want_start_sx, want_start_sy;
    S32 want_end_sx, want_end_sy;
    S32 dest_pitch_jump;

    gdi_handle out_layer;
    void (*put_func)(struct _gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw);
};

typedef struct _gdi_imgdec_resizer_struct gdi_imgdec_resizer_struct;

typedef void (*gdi_imgdec_resizer_put_func)(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw);

#define IS_GDI_IMGDEC_RESIZER_WANT_DRAW(resizer, SX,SY)   ((SX == (resizer)->want_sx) && (SY == (resizer)->want_sy))

#define GDI_IMGDEC_NON_RESIZER_PUT_X(resizer, COLOR,WANT_DRAW)    \
   do                                                             \
   {                                                              \
      if(WANT_DRAW)                                               \
         GDI_IMGDEC_RESIZER_PUT_PIXEL(COLOR);                     \
      GDI_IMGDEC_RESIZER_INCREASE_DEST;                           \
      if(resizer->want_sx == resizer->want_end_sx)          \
      {                                                           \
         if(resizer->want_sy == resizer->want_end_sy)       \
         {                                                        \
            resizer->want_sx = 0x0fffffff;/* very large number */\
         }                                                        \
         else/* move to next line begin */                         \
         {                                                        \
            resizer->want_sx = resizer->want_start_sx;      \
            resizer->want_sy += resizer->dir_y;             \
            resizer->dest += resizer->dest_pitch_jump;      \
         }                                                        \
      }                                                           \
      else                                                        \
      {                                                           \
         resizer->want_sx += resizer->dir_x;                \
      }                                                           \
   }while(0)

extern S32 gdi_imgdec_resizer_init(
                gdi_imgdec_resizer_struct *resizer,
                gdi_handle out_layer,
                S32 src_width,
                S32 src_height,
                S32 src_clipx1,
                S32 src_clipy1,
                S32 src_clipx2,
                S32 src_clipy2,
                S32 dest_x1,
                S32 dest_y1,
                S32 dest_x2,
                S32 dest_y2);

extern void gdi_imgdec_resizer_deinit(gdi_imgdec_resizer_struct *resizer);

#define gdi_imgdec_resizer_put(resizer, c, want_draw) (resizer)->put_func(resizer, c, want_draw)

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* __GDI_IMGDEC_RESIZER_H__ */



