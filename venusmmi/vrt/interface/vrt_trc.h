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
 *  vrt_trc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  VRT trace
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __VRT_TRC_H__
#define __VRT_TRC_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GEN_FOR_PC
   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before vrt_trc.h"
   #endif
#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before vrt_trc.h"
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "vrt_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
#include "vrt_system.h"


BEGIN_TRACE_MAP(MOD_VRT)

    /* VRT render */
    TRC_MSG(VRT_RENDER_DRAW_FRAME_BEGIN, "[VRT] frame index %d cmd num %d tl num %d")
    TRC_MSG(VRT_RENDER_DRAW_FRAME_END,   "[VRT] frame elapse time %d ms")
    TRC_MSG(VRT_RENDER_FRAME_FREEZE,     "[VRT] frame freeze scenario %d")
    TRC_MSG(VRT_RENDER_BLT_CONTROL,     "[VRT] blt control %d -> %d")
    TRC_MSG(VRT_RENDER_BUFFER_MODE,     "[VRT] forbid double buffer %d")
    TRC_MSG(VRT_RENDER_TRIPLE_BUF_FAIL,     "[VRT] prepare triple buf fail")
    TRC_MSG(VRT_RENDER_BUFFER_FROM_CACHE_FAIL,     "[VRT] lcd buffer from cache fail")

    /* VRT render device */
    TRC_MSG(VRT_RENDER_DEVICE_INIT,             "[VRT] render device init %d %d")
    TRC_MSG(VRT_RENDER_DEVICE_DEINIT,           "[VRT] render device deinit %d %d")
    TRC_MSG(VRT_RENDER_CHANGE_FRAME_BUFFER,     "[VRT] render device change frame buffer w %d h %d cf %d")
    TRC_MSG(VRT_RENDER_DEVICE_SWAP_FAIL,        "[VRT] swap buffer fail")
    TRC_MSG(VRT_RENDER_ABNORMAL_BLT,            "[VRT] blt fail for freeze")

    /* VRT frame sync */
    TRC_MSG(VRT_EVENT_FRAME_COMPLETE_TIMEOUT,   "[VRT] wait frame complete timeout %d %d")
    TRC_MSG(VRT_EVENT_FRAME_COMPLETE,           "[VRT] frame complete %d %d")
    TRC_MSG(VRT_EVENT_GPU_COMPLETE,             "[VRT] gpu complete %d %d")
    TRC_MSG(VRT_EVENT_LCD_COMPLETE,             "[VRT] lcd complete %d %d")
    TRC_MSG(VRT_WAIT_FRAME_COMPLETE_BEGIN,      "[VRT] begin wait for frame complete")
    TRC_MSG(VRT_WAIT_FRAME_COMPLETE_END,        "[VRT] end wait for frame complete")

    /* VRT cache */
    TRC_MSG(VRT_CACHE_ALLOCATOR_OOM,            "[VRT] vrt_cache_alloc_ex OOM size %d flag %d")
    TRC_MSG(VRT_CACHE_ALLOCATOR_REALLOC_OOM,    "[VRT] vrt_cache_realloc OOM ptr %x size %d flag %d")
    TRC_MSG(VRT_CACHE_ALLOCATOR_ALLOC_NC,       "[VRT] vrt cache alloc NC ptr %x size %d")
    TRC_MSG(VRT_CACHE_ALLOCATOR_FREE_NC,        "[VRT] vrt cache free NC ptr %x")

    /* VRT canvas */
    TRC_MSG(VRT_CANVAS_INIT,        "[VRT Canvas] vrt_canvas_init()")
    TRC_MSG(VRT_CANVAS_ENTRY,       "[VRT Canvas] vrt_canvas_entry()")
    TRC_MSG(VRT_CANVAS_LEAVE,       "[VRT Canvas] vrt_canvas_leave()")
    TRC_MSG(VRT_CANVAS_SUSPEND,     "[VRT Canvas] vrt_canvas_suspend()")
    TRC_MSG(VRT_CANVAS_RESUME,      "[VRT Canvas] vrt_canvas_resume()")
    TRC_MSG(VRT_CANVAS_POWER_OFF,   "[VRT Canvas] vrt_canvas_power_off()")
    TRC_MSG(VRT_CANVAS_POWER_ON,    "[VRT Canvas] vrt_canvas_power_on()")

    TRC_MSG(VRT_CANVAS_FRAME_COMMIT_BEGIN,          "[VRT Canvas] vrt_frame_commit_beign()")
    TRC_MSG(VRT_CANVAS_FRAME_COMMIT_END,            "[VRT Canvas] vrt_frame_commit_end() need_commit=%d")
    TRC_MSG(VRT_CANVAS_FRAME_COMMIT_SUSPEND_WAIT,   "[VRT Canvas] vrt_frame_commit_beign() : wait suspend")
    TRC_MSG(VRT_CANVAS_FRAME_COMMIT_SUSPEND_DONE,   "[VRT Canvas] vrt_frame_commit_beign() : done suspend")
    TRC_MSG(VRT_CANVAS_FRAME_COMMIT_RESUME_WAIT,    "[VRT Canvas] vrt_frame_commit_end() : wait resume")
    TRC_MSG(VRT_CANVAS_FRAME_COMMIT_RESUME_DONE,    "[VRT Canvas] vrt_frame_commit_end() : done resume")

    TRC_MSG(VRT_CANVAS_COMMIT_BEGIN,    "[VRT Canvas] vrt_frame_commit() : begin")
    TRC_MSG(VRT_CANVAS_COMMIT_END,      "[VRT Canvas] vrt_frame_commit() : end")

    /* VRT timer */
    TRC_MSG(VRT_TIMER_FREEZE_BEGIN, "[VRT Timer] vrt_canvas_freeze_begin() level=%d")
    TRC_MSG(VRT_TIMER_FREEZE_END,   "[VRT Timer] vrt_canvas_freeze_end() level=%d to=%d")

    TRC_MSG(VRT_TEMP_MEMORY_OOM, "[VRT Temp] out of memory size = %d")
    TRC_MSG(VRT_TEMP_MEMORY_ALLOC_ANONYMOUS_ASM, "[VRT Temp] alloc ASM addr %x size %d")
    TRC_MSG(VRT_TEMP_MEMORY_FREE_ANONYMOUS_ASM, "[VRT Temp] free ASM addr %x")
    
    TRC_MSG(VRT_TEMP_FRAME_OOM, "[VRT Frame] out of memory dimension %d x %d cf %d")
    

    TRC_MSG(VRT_RENDER_PRESENT,             "[VRT] present rotate %d")

    TRC_MSG(VRT_RENDER_FREE_ALL_DISCARDABLE_CACHE, "[VRT] free all discardable %d")

    /* VFX response time utility logs */
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_OTHER,                   "[VFX Response Time] Other info : %u")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PD_NA,                   "[VFX Response Time] Pen down -> BLT : N/A")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PFM_NA,                  "[VFX Response Time] Pen first move -> BLT : N/A")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PU_NA,                   "[VFX Response Time] Pen up -> BLT : N/A")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_KD_NA,                   "[VFX Response Time] Key down -> BLT : N/A")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_KU_NA,                   "[VFX Response Time] Key up -> BLT : N/A")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_SCR_ENTRY,               "[VFX Response Time] Screen entry -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_BLT,                     "[VFX Response Time] BLT at [%u]")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PEN_DOWN_BLT,            "[VFX Response Time] Pen down -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PEN_FIRST_MOVE_BLT,      "[VFX Response Time] Pen first move -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PEN_UP_BLT,              "[VFX Response Time] Pen up -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_KEY_DOWN_BLT,            "[VFX Response Time] Key down -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_KEY_UP_BLT,              "[VFX Response Time] Key up -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PD_SCR_BLT,              "[VFX Response Time] Previous pen down -> Screen entry -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PFM_SCR_BLT,             "[VFX Response Time] Previous pen first move -> Screen entry -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_PU_SCR_BLT,              "[VFX Response Time] Previous pen up -> Screen entry -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_KD_SCR_BLT,              "[VFX Response Time] Previous key down -> Screen entry -> BLT : %u ms")
    TRC_MSG(TRC_VRT_LOG_RSP_TIME_EVENT_KU_SCR_BLT,              "[VFX Response Time] Previous key up -> Screen entry -> BLT : %u ms")

    
    /* ADD BEFORE ME */
    TRC_MSG(VRT_RENDER_END_OF_TRACE, "")

    /* VRT canvas */
END_TRACE_MAP(MOD_VRT)

#ifdef __cplusplus
}
#endif

#endif /* __VRT_TRC_H__ */

