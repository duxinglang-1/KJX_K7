
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
 *  drm_memory.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef DRM_MEMORY_H
#define DRM_MEMORY_H
#ifdef __DRM_SUPPORT__

#include "kal_general_types.h"
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* !defined(__MTK_INTERNAL__) */ 
#define drmt_mem_alloc(size)    drmt_mem_alloc_ext(size, "", 0)
#define drmt_mem_free(memblock)    drmt_mem_free_ext(memblock, "", 0)
#define drmt_mem_realloc(memblock, size) drmt_mem_realloc_ext(memblock, size, "", 0)
#endif /* !defined(__MTK_INTERNAL__) */ 

extern void drmt_mem_init(void);
extern kal_uint32 drmt_mem_total_left_size(void);
extern void drmt_mem_check_corruption(void);
extern void *drmt_mem_alloc_ext(int size, const char *file, int line);
extern void *drmt_mem_realloc_ext(void *memblock, int size, const char *file, int line);
extern void drmt_mem_free_ext(void *memblock, const char *file, int line);
extern kal_bool drmt_mem_valid(kal_uint32 address);
extern kal_bool drmt_mem_virtual(void);

extern void drmt_mem_set_start_eval(const kal_char *file, kal_int32 line);
extern void drmt_mem_set_end_eval(const kal_char *file, kal_int32 line);
extern void drmt_mem_show_eval(kal_bool show_log, const kal_char *file, kal_int32 line);

#define DRM_MEM_START_EVAL                                   \
{                                                            \
    drmt_mem_set_start_eval(basename(__FILE__), __LINE__);   \
}

#define DRM_MEM_END_EVAL                                                           \
{                                                                                  \
    drmt_mem_set_end_eval(basename(__FILE__), __LINE__);                           \
    drmt_mem_show_eval(KAL_TRUE, basename(__FILE__), __LINE__);                    \
}

#endif /* __DRM_SUPPORT__ */ 
#endif /* DRM_MEMORY_H */ 

