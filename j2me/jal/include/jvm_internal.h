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
 *  jvm_internal.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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

#include "jvm_interface.h"

#ifndef _JVM_INTERNAL_H
#define _JVM_INTERNAL_H

/*************************************************************************
* Include Header Files
*************************************************************************/
#ifdef DATACACHE_FBBR_ON
#include "cache_hw.h"
#include "cache_sw.h"
#endif /* defined(__MTK_TARGET__) && defined(MT6228) */ /* CACHE */
#include "stack_timer.h"
//#include "event_shed.h"
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)  
#include "mmu.h"
#include "cp15.h"
#include "cache_sw.h"
#endif 
#include "kal_trace.h"

#include "jvm_trace_interface.h"

/*************************************************************************
* Global Definition
*************************************************************************/

#define VIRTUAL_FILE_TAG                     (0x13579024)
#define NORMAL_FILE_TAG                      (0x09133710)
#define DRM_FILE_TAG                      (0xC580A94B)
#define ENCRYPTED_JAR_FILE							(0xC9A9848D)

typedef struct _virtual_file_struct
{
    kal_uint32 file_tag;
    union
    {
        kal_int32 handler;
        kal_int32 position;
    } h;
	union{
		kal_int32 filesize;
		kal_int32 encrypt_code;
	}f;
    kal_uint8 *filedata;

} vfile_struct, *pvfile;

/* Backward-compatible */

#define getJulianOffsetTimeInMillis             jvm_get_julian_time_ms

/*************************************************************************
* Global Declaration
*************************************************************************/
extern WCHAR WCHARFilename[MAX_WCHAR_FILENAME_LEN];
extern WCHAR WCHARFilename_JAM[MAX_WCHAR_FILENAME_LEN];

extern kal_char *work_dir_path;
extern kal_char *work_sys_dir_path;
extern j2me_custom_file_info_struct* work_info_ptr;

extern kal_char j2me_sys_dir_path[];

#ifdef __SUPPORT_INFUSIO__
extern kal_char eureka_sys_dir_path[];
#endif /* __SUPPORT_INFUSIO__ */
#ifdef SUPPORT_SURFKITCHEN
extern kal_char surfkitchen_sys_dir_path[];
#endif /* SUPPORT_SURFKITCHEN */
#ifdef SUPPORT_MUSICWAV
extern kal_char musicwav_sys_dir_path[];
#endif /* SUPPORT_MUSICWAV */

extern int virtual_file_count;
extern const char *virtual_file_name[];
extern const unsigned char *virtual_file_data[];
extern const int virtual_file_size[];

extern void FBBR_heap_init(void);
extern void FBBR_heap_finalize(void);
extern void *FBBR_invalid_l1_cache_img(void *dst, int x_pos, int y_pos, int width, int height, int dst_width);
extern void *FBBR_invalid_l1_cache(void *dst, int length);

/* Timer */
//extern event_scheduler *jvm_event_scheduler_ptr;
//extern stack_timer_struct jvm_base_timer;
//extern void jvm_start_base_timer(void *base_timer_ptr, kal_uint32 time_out);
//extern void jvm_stop_base_timer(void *base_timer_ptr);
extern void jvm_init_timer(void);

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
extern kal_uint8 jam_get_vk_permission(void);
#endif 

/* Resource management */

typedef struct _resource_mgr_struct
{
    int device_type;
    int handle;
    int (*suspend) (kal_int32 handle);
    int (*resume) (kal_int32 handle);
    int (*close) (kal_int32 handle);
} resource_mgr_struct;

typedef struct _resource_mgr_mvm_struct
{
    int device_type;
    int vm_id;
    int handle;
    int (*suspend) (kal_int32 vm_id, kal_int32 handle);
    int (*resume) (kal_int32 vm_id, kal_int32 handle);
    int (*close) (kal_int32 vm_id, kal_int32 handle);
} resource_mgr_mvm_struct;

#define RESOUCE_ARRAY_SIZE 20

typedef struct _resource_mgr_array_struct
{
    struct _resource_mgr_array_struct *next;
    int next_free_index;    /* next_free_index == -1 means no free entry */
    resource_mgr_struct resouce[RESOUCE_ARRAY_SIZE];
} resource_mgr_array_struct;

typedef struct _jvm_file_aliasTable_node_struct
{
    struct _jvm_file_aliasTable_node_struct *next;
    kal_wchar* alias_name;
}jvm_file_aliasTable_node_struct;

#if defined(__OP01__ ) && defined(J2ME_SUPPORT_BACKGROUND)     

typedef enum
{
    JVM_UTIL_SUCCESS,
    JVM_UTIL_FAIL,
    JVM_UTIL_MISS_INFO,

} jvm_util_OP01_ret_enum;

extern jvm_util_OP01_ret_enum jvm_util_OP01_check_Keep_Background(kal_int32 vm_id);

#endif
////extern int initializeResoueceMgr(void);
////extern void finalizeResoueceMgr(void);
////extern void finalize_net_res(void);
////extern int resouceRegistering(int device_type, int handle, int (*suspend) (int handle),
////                              int (*resume) (int handle), int (*close) (int handle));
////extern int resouceDereg(int device_type, int handle);
////extern int resouceDeregWoCS(int device_type, int handle);
////extern int resouceCloseAndDereg(int device_type, int handle);

extern resource_mgr_array_struct *resource_array;

extern void *jvm_l1_cache_invalidate_and_clean_region_by_line(void *dst, kal_uint32 x_pos, kal_uint32 y_pos, kal_uint32 width, kal_uint32 height, kal_uint32 dst_width, kal_uint32 buffer_size);
extern void *jvm_l1_cache_invalidate_and_clean_region(void *dst, kal_uint32 len, kal_bool clean_flag, kal_bool invalidate_flag, kal_uint8 type_flag);

extern void jvm_file_disk_changed_callback_handler(void);

#endif /* _JVM_INTERNAL_H */ 
