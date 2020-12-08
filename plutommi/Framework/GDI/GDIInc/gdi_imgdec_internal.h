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
 *  gdi_imgdec_internal.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  IMGDEC interface for GDI internal usage
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_IMGDEC_INTERNAL_H__
#define __GDI_IMGDEC_INTERNAL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "setjmp.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"

#ifdef __MTK_INTERNAL__
/* under construction !*/
#if defined(__GDI_IMGDEC_SWLA__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GDI_IMGDEC_SWLA__) && defined(__MTK_TARGET__) */
/* under construction !*/
#endif /* __MTK_INTERNAL__ */

#ifndef GDI_IMGDEC_DBG_LABEL_BEGIN
#define GDI_IMGDEC_DBG_LABEL_BEGIN(label)
#endif 

#ifndef GDI_IMGDEC_DBG_LABEL_END
#define GDI_IMGDEC_DBG_LABEL_END(label)
#endif 

#ifndef GDI_IMGDEC_DBG_LABEL
#define GDI_IMGDEC_DBG_LABEL(label)
#endif 

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define GDI_IMGDEC_RAISE(h, ret_code)   longjmp(h->jmpbuf, ret_code)

#define GDI_IMGDEC_TRY(h)                     \
   {                                           \
      int jmpret;                              \
      /* GDI_ASSERT(!gdi_jmpbuf_is_used); */   \
      /* gdi_jmpbuf_is_used = TRUE; */         \
      jmpret = setjmp(h->jmpbuf/*dec_handle->gdi_jmpbuf*/);\
      if (jmpret == 0 )                        \
      {

#define GDI_IMGDEC_CATCH_BEGIN(h)                     \
      }                                     \
      else                                  \
      {                                     \
         {

#define GDI_IMGDEC_CATCH_END(h)            \
         }                       \
      }                          \
      /* gdi_jmpbuf_is_used = FALSE; */ \
   }

#define GDI_IMGDEC_CATCH(h, N) if (jmpret == N)

/* clip test utility */
#define GDI_IMGDEC_LAYER_CLIP_RECT_TEST(layer, X1, Y1, X2, Y2, NULL_ACTION)    \
{                                                         \
   if (X1 > X2) { NULL_ACTION; }                          \
   else if (Y1 > Y2)  { NULL_ACTION; }                    \
   else if (X2 < (layer)->clipx1) { NULL_ACTION; }        \
   else if (Y2 < (layer)->clipy1) { NULL_ACTION; }        \
   else if (X1 > (layer)->clipx2) { NULL_ACTION; }        \
   else if (Y1 > (layer)->clipy2) { NULL_ACTION; }        \
   else                                                   \
   {                                                      \
      if (X1 < (layer)->clipx1) { X1 = (layer)->clipx1; } \
      if (Y1 < (layer)->clipy1) { Y1 = (layer)->clipy1; } \
      if (X2 > (layer)->clipx2) { X2 = (layer)->clipx2; } \
      if (Y2 > (layer)->clipy2) { Y2 = (layer)->clipy2; } \
   }                                                      \
}

/* IMGDEC lock */
#define GDI_IMGDEC_HW_LOCK      gdi_imgdec_hw_dec_mutex_take
#define GDI_IMGDEC_HW_UNLOCK    gdi_imgdec_hw_dec_mutex_give

#define GDI_IMGDEC_IS_ABORTED(h)    ((h)->is_aborted && *((h)->is_aborted))

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define GDI_IMGDEC_BASE_STRUCT \
    jmp_buf     jmpbuf; \
    gdi_handle  out_layer; \
    U32         flag; \
    BOOL        *is_aborted;


typedef struct 
{
    GDI_IMGDEC_BASE_STRUCT
} gdi_imgdec_struct;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void gdi_imgdec_init(void);
extern void gdi_imgdec_hw_dec_mutex_take(void);
extern void gdi_imgdec_hw_dec_mutex_give(void);

#endif /* __GDI_IMGDEC_INTERNAL_H__ */



