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
 *  gdi_imgdec_bmp_codec.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GDI IMGDEC BMP kernel
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_IMGDEC_BMP_CODEC_H_
#define _GDI_IMGDEC_BMP_CODEC_H_

#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_trace.h"

#include "setjmp.h"
#include "lcd_if.h"
#include "iul_rng.h"
#include "iul_spatial_dithering.h"
#include "drv_comm.h"

#include "MMIDataType.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"

#include "med_smalloc.h"
#include "med_utility.h"

#include "gdi_imgdec_resizer.h"
#include "gdi_imgdec_bytestream.h"
#include "gdi_internal.h"
#include "gdi_image_bmp.h"
#include "gdi_imgdec_internal.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_primitive.h"
#include "gdi_features.h"
#include "gdi_layer.h"
#include "gd_include.h"

#include "gdi_imgdec_bmp.h"

typedef struct
{
    U16 bfType;
    U32 bfSize;
    U16 bfReserved1;
    U16 bfReserved2;
    U32 bfOffBits;
} bitmap_file_header;

typedef struct
{
    U32 biSize;
    U32 biWidth;
    U32 biHeight;
    U16 biPlanes;
    U16 biBitCount;
    U32 biCompression;
    U32 biSizeImage;
    U32 biXPelsPerMeter;
    U32 biYPelsPerMeter;
    U32 biClrUsed;
    U32 biClrImportant;
} bitmap_info_header;

typedef struct
{
    U32 biSize;
    U16 biWidth;
    U16 biHeight;
    U16 biPlanes;
    U16 biBitCount;
} bitmap_core_header;

#define GDI_BI_RGB  0
#define GDI_BI_RLE8  1
#define GDI_BI_RLE4  2
#define GDI_BI_BITFIELDS  3
#define GDI_BMP_BYTESTREM_BUF_SIZE 4096



#undef GDI_RESIZER_PUT
#undef GDI_RESIZER_PUT_PIXEL
#undef GDI_RESIZER_INCREASE_DEST

#if 0
/* under construction !*/
#if GDI_IMAGE_BMP_CODEC_COLOR_FORMAT == GDI_COLOR_FORMAT_8
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_16
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_24
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_32
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_MAINLCD
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif GDI_IMAGE_BMP_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_SUBLCD
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
#else /* GDI_IMAGE_BMP_USING_RESIZER */ 
#define GDI_IMGDEC_RESIZER_PUT(COLOR,WANT_DRAW)     gdi_imgdec_resizer_put(&dec->resizer, COLOR, WANT_DRAW)
#endif /* GDI_IMAGE_BMP_USING_RESIZER */ 

#undef MY_GET_U8
#undef MY_FLUSH

#define SUPPORT_BMP_COMPRESSION



#endif
