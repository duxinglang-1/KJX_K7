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
 *  vapp_media_center_util.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  MediaCenter uitility
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __VAPP_MEDIA_CENTER_UTIL_H__
#define __VAPP_MEDIA_CENTER_UTIL_H__

#include "MMI_features.h"
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
/***************************************************************************** 
 * Performance uitility
*****************************************************************************/
// kal calculate time 
static kal_uint32 g_u32_start_time;
static kal_uint32 g_u32_end_time;
static kal_uint32 g_u32_duration;
#define MEDIA_CENTER_START(_trace_) \
        do{\
            kal_get_time(&g_u32_start_time);\
        }while(0)
#define MEDIA_CENTER_STOP(_trace_)\
        do{\
            kal_get_time(&g_u32_end_time);\
            g_u32_duration = kal_ticks_to_milli_secs(g_u32_end_time - g_u32_start_time);\
            kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,_trace_, g_u32_duration,__LINE__);\
        }while(0)

// SWLA
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MEDIA_CENTER_MEASURE_TIME_START(_symbol_)
#define MEDIA_CENTER_MEASURE_TIME_STOP(_symbol_)
#endif

// debug utility
#define __MEDIA_CENTER_INTERNAL_DEBUG__

#if defined(__MTK_INTERNAL__) && defined(__MEDIA_CENTER_INTERNAL_DEBUG__)
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
#define _ME_TRACE(_trace_) 
#define _ME_TRACE_1(_trace_, _var1_) 
#define _ME_TRACE_2(_trace_, _var1_, _var2_) 
#define _ME_TRACE_3(_trace_, _var1_, _var2_, _var3_) 
#define _ME_TRACE_4(_trace_, _var1_, _var2_, _var3_, _var4_) 
#endif

/***************************************************************************** 
 * Define
*****************************************************************************/
// degree to radians 
#define DEGREES_TO_RADIANS(D) D * VFX_PI / 180.f
#define RADIANS_TO_DEGREES(R) 180.f * R / VFX_PI

// log
#define MEDIA_CENTER_LOG(_trace_, _var_) MMI_TRACE(TRACE_GROUP_2, _trace_, _var_);


#endif // __COSMOS_3D_MEDIA_CENTER__
#endif // __VAPP_MEDIA_CENTER_UTIL_H__ 


