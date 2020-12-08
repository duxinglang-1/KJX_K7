/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_gallery_util.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_GALLERY_UTIL_H__
#define __VAPP_GALLERY_UTIL_H__
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_file_type_def.h"
#include "vapp_gallery_gprot.h"

static const VfxMsec MSEC_PER_SEC = 1000;


/***************************************************************************** 
 * SWLA & Logging
 *****************************************************************************/
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
#ifdef __cplusplus
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __cplusplus
/* under construction !*/
#endif
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
#else
#define GALLERY_MEASURE_TIME_START(_symbol_)
#define GALLERY_MEASURE_TIME_STOP(_symbol_)
#define GALLERY_MEASURE_TIME(_symbol_)
#define GALLERY_MEASURE_TIME_LABEL(_symbol_)
#endif // defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__) && defined(__MAUI_SOFTWARE_LA__)
/***************************************************************************** 
 * Gallery internal debug util
 *****************************************************************************/
static kal_uint32 g_u32_start_time;
static kal_uint32 g_u32_end_time;
static kal_uint32 g_u32_duration;
#define _START(_trace_) \
        do{\
            kal_get_time(&g_u32_start_time);\
        }while(0)
#define _STOP(_trace_)\
        do{\
            kal_get_time(&g_u32_end_time);\
            g_u32_duration = kal_ticks_to_milli_secs(g_u32_end_time - g_u32_start_time);\
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,_trace_, g_u32_duration,__LINE__);\
        }while(0)


//#define __VAPP_GALLERY_INTERNAL_DEBUG__

/***************************************************************************** 
 * Color format configurations (RGB565 <---> RGB888)
 *****************************************************************************/
#if (VAPP_GALLERY_IMG_VIEWER_BPP == 3)
#define GALLERY_GDI_CF_VIEWER (GDI_COLOR_FORMAT_24)
#define GALLERY_VRT_CF_VIEWER (VRT_COLOR_TYPE_RGB888)
#else
#define GALLERY_GDI_CF_VIEWER (GDI_COLOR_FORMAT_16)
#define GALLERY_VRT_CF_VIEWER (VRT_COLOR_TYPE_RGB565)
#endif

#if (VAPP_GALLERY_THUMB_BPP == 3)
#define GALLERY_GDI_CF_THUMB (GDI_COLOR_FORMAT_24)
#define GALLERY_VRT_CF_THUMB (VRT_COLOR_TYPE_RGB888)
#else
#define GALLERY_GDI_CF_THUMB (GDI_COLOR_FORMAT_16)
#define GALLERY_VRT_CF_THUMB (VRT_COLOR_TYPE_RGB565)
#endif

/***************************************************************************** 
 * Utility functions
 *****************************************************************************/
int getBytePerPixel(vrt_color_type_enum cf);

gdi_color_format convertCF_VRT2GDI(vrt_color_type_enum cf);

vrt_color_type_enum convertCF_GDI2VRT(gdi_color_format cf);

U64 msecToSec(U64 timeMsec);

// format miliseconds into "HH:MM:SS" format.
// if hideHourIfZero is VFX_TRUE, then "MM:SS" is used when the time is less than 1 hour.
void formatTimeText(VfxWString &timeText, U64 timeMsec, VfxBool hideHourIfZero = VFX_TRUE);

void formatSizeText(VfxWString &sizeText, VfxU32 sizeInBytes);


VfxId convertItemIdFromMenuPos(const VcpMenuPos &pos);

mmi_id findRootAppId(VfxObject *obj);

VfxBool isAnyParentHidden(VfxFrame *frame);

void hideFrameAnimated(VfxFrame *frame);

void showFrameImmediately(VfxFrame *frame);

void intersectFmgrFilter(FMGR_FILTER &dst, const FMGR_FILTER &src);

void copyFmgrFilter(FMGR_FILTER *pdst, const FMGR_FILTER &src);

VfxBool is3DRedBlueImage(const WCHAR* path, U16 gdiImgFileTypeHint = GDI_IMAGE_TYPE_INVALID);

#endif // __VAPP_GALLERY_UTIL_H__
