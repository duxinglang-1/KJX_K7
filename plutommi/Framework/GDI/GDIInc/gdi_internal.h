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
 *  gdi_internal.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  internal Include file for full set GDI function.
 *
 * Author:
 * -------
 * -------
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
#ifndef _GDI_INTERNAL_H_
#define _GDI_INTERNAL_H_

#define GDI_VERSION              0x06B
#undef  GDI_USING_LFS

/* for PC_SIMULATOR to pass some system call */
#define __NEWSIMULATOR

#include "intrCtrl.h"   /* GET_RETURN_ADDRESS() */
#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "MMI_features.h"
#include "MMIDataType.h"

#include "mmi_frm_gprot.h"
#include "TimerEvents.h"

#if defined(DRV_DISPLAY_DRIVER_V2)
#define GDI_DDV2
#endif

#include "gdi_features.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "mmi_rp_srv_gdi_def.h"

////////////////////////////////////////////////////
// GDI animator ,  how many animating at the same time ( include main lcd / sub lcd )
#define GDI_ANIM_COUNT                                4
/* ////////////////////////////////////////////////// */
enum
{
    GDI_TIMER_ANIM_BASE = GDI_TIMER_BASE,
    GDI_TIMER_ANIM_END = GDI_TIMER_ANIM_BASE + GDI_ANIM_COUNT - 1,

    GDI_TIMER_ANIM_CALLBACK_BASE = GDI_TIMER_ANIM_BASE + GDI_ANIM_COUNT,
    GDI_TIMER_ANIM_CALLBACK_END = GDI_TIMER_ANIM_CALLBACK_BASE + GDI_ANIM_COUNT - 1,

    GDI_TIMER_ESD_RECOVERY = GDI_TIMER_ANIM_CALLBACK_BASE + GDI_ANIM_COUNT,
    GDI_TIMER_ANIM_DUMMY
};

#if defined(GDI_SLIM_SUPPORT) && !defined(GDI_USING_DITHERING) && !(defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24))
#define GDI_SLIM_COLOR_FORMAT
#endif

#if defined(__MMI_MAIN_BASE_LAYER_FORMAT__)
#define GDI_MAIN_BASE_LAYER_FORMAT __MMI_MAIN_BASE_LAYER_FORMAT__
#else
#define GDI_MAIN_BASE_LAYER_FORMAT GDI_COLOR_FORMAT_MAINLCD
#endif

#if defined(__MMI_MAIN_BASE_LAYER_FORMAT__)
#define GDI_SUB_BASE_LAYER_FORMAT __MMI_SUB_BASE_LAYER_FORMAT__
#else
#define GDI_SUB_BASE_LAYER_FORMAT GDI_COLOR_FORMAT_SUBLCD
#endif


typedef enum
{
    GDI_INT_MEMORY_TYPE,
    GDI_EXT_MEMORY_TYPE_NONCACHEABLE,
    GDI_EXT_MEMORY_TYPE_CACHEABLE,
    GDI_EXT_MEMORY_TYPE_FRAMEBUFFER,
    GDI_EXT_MEMORY_TYPE_COUNT
} gdi_memory_type_enum;

#ifdef GDI_SLIM_SUPPORT
    extern void *gdi_alloc_ext_mem_ext(kal_int32 size, kal_uint8 location);
    extern void gdi_free_ext_mem_ext(void **pointer);
    #define gdi_alloc_ext_mem(size)                 gdi_alloc_ext_mem_ext(size,GDI_EXT_MEMORY_TYPE_NONCACHEABLE)
    #define gdi_alloc_ext_mem_cacheable(size)       gdi_alloc_ext_mem_ext(size,GDI_EXT_MEMORY_TYPE_CACHEABLE)
    #define gdi_alloc_ext_mem_framebuffer(size)     gdi_alloc_ext_mem_ext(size,GDI_EXT_MEMORY_TYPE_FRAMEBUFFER)
    #define gdi_free_ext_mem(pointer)               gdi_free_ext_mem_ext(pointer)
#else /* GDI_SLIM_SUPPORT */
    extern void *gdi_alloc_ext_mem_ext(kal_int32 size, kal_uint8 location, char* file_p, long line_p);
    extern void gdi_free_ext_mem_ext(void **pointer,char* file_p, long line_p);
#define gdi_alloc_ext_mem(size)                 gdi_alloc_ext_mem_ext(size,GDI_EXT_MEMORY_TYPE_NONCACHEABLE,__FILE__,__LINE__)
#define gdi_alloc_ext_mem_cacheable(size)       gdi_alloc_ext_mem_ext(size,GDI_EXT_MEMORY_TYPE_CACHEABLE,__FILE__,__LINE__)
#define gdi_alloc_ext_mem_framebuffer(size)     gdi_alloc_ext_mem_ext(size,GDI_EXT_MEMORY_TYPE_FRAMEBUFFER,__FILE__,__LINE__)
#define gdi_free_ext_mem(pointer)               gdi_free_ext_mem_ext(pointer,__FILE__,__LINE__)
#endif /* GDI_SLIM_SUPPORT */



#include "gdi_trc.h"
#include "gdi_lfs.h"

#include "gdi_mutex.h"
#include "gdi_primitive.h"
#include "gdi_lcd.h"

#include "gdi_layer.h"
#include "gdi_util.h"



#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif 

#if defined(__MTK_INTERNAL__) && defined(__MMI_INTERACTIVE_PROFILNG__)
/* under construction !*/
#endif 

#if defined(GDI_MUTEX_DEBUG) && defined(GDI_USING_MUTEX)
#define GDI_RETURN_TYPE(T,X)     do{T x=X;GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN(X)      do{GDI_RESULT x=X;GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN_VOID do{GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);GDI_UNLOCK; return ;}while(0)
#define GDI_ENTER_CRITICAL_SECTION(func)  GDI_LOCK; do {int gdi_mutex_level = gdi_mutex.cnt;
#define GDI_EXIT_CRITICAL_SECTION(func)      GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);}while(0); GDI_UNLOCK;
#else /* defined(GDI_MUTEX_DEBUG) && defined(GDI_USING_MUTEX) */ 
#define GDI_RETURN_TYPE(T,X)                 do{T x=X;GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN(X)                  do{GDI_RESULT x=X;GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN_VOID             do{GDI_UNLOCK; return ;}while(0)
#define GDI_ENTER_CRITICAL_SECTION(func)  GDI_LOCK; do{
#define GDI_EXIT_CRITICAL_SECTION(func)   }while(0); GDI_UNLOCK;
#endif /* defined(GDI_MUTEX_DEBUG) && defined(GDI_USING_MUTEX) */ 

#define TOBOOL(X) (BOOL)(((X)?MMI_TRUE:MMI_FALSE))
#define GDI_ABS(x)   ((x)<0?-(x):(x))

/*
 * Important/abnormal case trace. QA will turn on by default
 */
#define GDI_TRC_CODEC_I     TRACE_GROUP_1
#define GDI_TRC_LAYER_I     TRACE_GROUP_2
#define GDI_TRC_PRIMI_I     TRACE_GROUP_3

/*
 * Detail trace. Will be turned on for further analysis
 */
#define GDI_TRC_LAYER       TRACE_GROUP_4
#define GDI_TRC_DECODE      TRACE_GROUP_5
#define GDI_TRC_ENCODE      TRACE_GROUP_6
#define GDI_TRC_G2D         TRACE_GROUP_6
#define GDI_TRC_RR          TRACE_GROUP_6
#define GDI_TRC             TRACE_GROUP_7
#define GDC_TRC             TRACE_GROUP_5

#define GDI_TRC_PAIRED_CLIP   TRACE_GROUP_8
#define GDI_TRC_PAIRED_LAYER  TRACE_GROUP_9
#define GDI_TRC_MEM         TRACE_GROUP_10


#define GDI_TRACE           MMI_TRACE
#define GDI_BRIEF_TRACE     kal_brief_trace

#ifndef GDI_SLIM_SUPPORT
    #define GDI_PRINT           MMI_PRINT
#else
    #define GDI_PRINT(...)
#endif

///////////////////////////////////////////////////
// GDI DEBUG FLAG
extern void gdi_debug_handler(S32 index,U8* string);

#define GDI_DEBUG_FLAG_IMAGE_DUMP      1

extern U32 GDI_DEBUG_FLAG;
extern U32 GDI_DEBUG_CNT;
extern U8 GDI_DEBUG_ARG[];

extern kal_eventgrpid gdi_event_group;



//// for compile warning
#define GDI_UNUSED(x)       (void)x


#ifdef __MTK_TARGET__
#define GDI_TRC_PRINT_LR(trace_group) \
    do { \
        kal_uint32 addr = 0; \
        GET_RETURN_ADDRESS(addr); \
        GDI_TRACE(trace_group, GDI_TRC_PRINT_LR_VALUE, addr); \
    } while (0)

#define GDI_GET_RETURN_ADDRESS(addr) GET_RETURN_ADDRESS(addr)
#else
#define GDI_TRC_PRINT_LR(trace_group)
#define GDI_GET_RETURN_ADDRESS(addr) do { addr = 0; } while (0)
#endif


#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define GDI_SLA_START(_symbol_)
#define GDI_SLA_STOP(_symbol_)
#endif


#endif /* _GDI_INTERNAL_H_ */ 


