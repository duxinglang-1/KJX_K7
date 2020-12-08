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
 *  vfx_adp_os.c
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Operation System Adapatation Layer
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

#ifndef __VFX_ADP_OS_H__
#define __VFX_ADP_OS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For basic types
#include "vfx_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif

// For vrt mutex struct
#include "vrt_mutex.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*
 * Trace defines
 */

/*
 * Following description is about how to add trace log in Venus.
 * 
 * 1) There are 2 types of header files. 
 *  For application / Service / Data / Adaptor:
 *     Please use "trc/vadp_app_trc.h" 
 *  For Venus framework / Visual / CP:
 *     Please use "trc/vadp_sys_trc.h" 
 * 2) Add your message into the above header file:
 *  For example, add following line into vadp_app_trc.h
 * 
 *  TRC_MSG(VAPP_HS_INIT_MSG, "[HS] Home Screen Init")
 * 
 * 3) Write log by following way:
 *  VFX_LOG(VFX_INFO, VAPP_HS_INIT_MSG);
 *  
 *  VFX_LOG is the macro to write log to cather. 
 *  VFX_INFO is the log category, so that you can show/hide categories in cather.
 *  There are total 15 categories, please refer follows define.
 *  You can see, we have 3 levels. 
 *
 *  1'st level is for general log.
 *     You can print important message that can help you to find out an abnormal 
 *     situation. Please don't print verbose message in this level.
 *     That is because we will encourage others to open this level always.
 *  2'nd level is for detail log.
 *     You can add detail message in this level. So that when we meet a issue and 
 *     have no idea what happend. We can open this level to see more detail message,
 *     such as calling sequence or timing related log. That can help us to find out 
 *     root cause.
 *  3'rd level is for developping verbose log.
 *     This level is very verbose message. It usually used in developping stage and 
 *     those logs are not willing to open. Such as pen position, streaming package,
 *     layer informations, etc. Those logs are huge so that it should only be opened 
 *     when 2'nd level cannot help you.
 * 
 * 4) When you use catcher, please turn on MOD_VAPP and MOD_VFX. And defaultly, 
 *  please turn on TRACE_FUNC ~ TRACE_ERROR0. The 2'nd level is TRACE_GROUP_1 ~ TRACE_GROUP_5,
 *  while 3'st level is TRACE_GROUP_6 ~ TRACE_GROUP_10.
 *
 */
 
/*For general trace class and level*/
#define VFX_FUNC                        TRACE_FUNC
#define VFX_STATE                       TRACE_STATE
#define VFX_INFO                        TRACE_INFO
#define VFX_WARNING                     TRACE_WARNING
#define VFX_ERROR                       TRACE_ERROR

/*For detail trace class and level*/
#define VFX_FUNC2                       TRACE_GROUP_1
#define VFX_STATE2                      TRACE_GROUP_2
#define VFX_INFO2                       TRACE_GROUP_3
#define VFX_WARNING2                    TRACE_GROUP_4
#define VFX_ERROR2                      TRACE_GROUP_5

/*For verbose trace class and level*/
#define VFX_FUNC3                       TRACE_GROUP_6
#define VFX_STATE3                      TRACE_GROUP_7
#define VFX_INFO3                       TRACE_GROUP_8
#define VFX_WARNING3                    TRACE_GROUP_9
#define VFX_ERROR3                      TRACE_GROUP_10

/*
 * Venus App uses this macro to log.
 * For example:
 *  VFX_LOG(VFX_INFO, VAPP_HS_INIT_MSG);
 */
#define VFX_LOG                         kal_trace


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/*
 * System types
 */
typedef void (*vfx_sys_callback_funcptr_type)(void *data);

/*
 * Timer types
 */
typedef void *vfx_sys_timer_handle;

/*
 * Font type
 */
typedef struct
{
    VfxU8 size;         /* size: please refer to VfxFontDescSizeEnum of VfxFontDesc */
    VfxU8 attribute;    /* attribute: please refer to font attribute flags define of VfxFontDesc */
    VfxU8 effect;       /* effect: please refer to VfxFontDescEffectEnum of VfxFontDesc */
} vfx_sys_res_font_struct;

/*vfx_sys_mutex_struct represents a mutex struct*/
typedef vrt_mutex_struct vfx_sys_mutex_struct;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern void vfx_adp_os_init(void);

/*
 * MMI Task functions
 */
extern int  vfx_sys_is_mmitask(void);
extern void vfx_sys_notify_mmitask(void);

/* 
 * Memory Mutex Lock, Unlock and Init, internal use.
 */
extern void vfx_sys_mutex_lock(vfx_sys_mutex_struct *mem_mutex);
extern void vfx_sys_mutex_unlock(vfx_sys_mutex_struct *mem_mutex);
extern void vfx_sys_mutex_init(vfx_sys_mutex_struct *mem_mutex);

/* 
 * Post Invoke Lock, internal use.
 */
extern void vfx_sys_acquire_post_lock(void);
extern void vfx_sys_release_post_lock(void);

/* 
 * Obj handle Lock, internal use.
 */
extern void vfx_sys_acquire_obj_hdl_lock(void);
extern void vfx_sys_release_obj_hdl_lock(void);

/* 
 * Weak obj handle lock, internal use.
 */
extern void vfx_sys_acquire_weak_obj_hdl_lock(void);
extern void vfx_sys_release_weak_obj_hdl_lock(void);

/*
 * Timer functions
 */
extern void vfx_sys_timer_start(VfxU32 delay, vfx_sys_callback_funcptr_type callback, void *data);
extern void vfx_sys_timer_stop(void);

/*
 * Resource functions
 */
extern const VfxWChar *vfxSysResGetStr(VfxResId str_id);
extern const VfxU8 *vfx_sys_res_get_binary(VfxResId binary_id, VfxU32 *size);
extern VfxU32 vfx_sys_res_get_color(VfxResId color_id);
extern void vfx_sys_res_get_font(VfxResId font_id, vfx_sys_res_font_struct* font);

/*
 * Debug
 */
extern int vfx_debug_panel_get_enable(void);
extern int vfx_profiling_panel_get_enable(void);
extern void vfx_set_cache_config_size(vrt_u32 cache_size);

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VFX_ADP_OS_H__ */

