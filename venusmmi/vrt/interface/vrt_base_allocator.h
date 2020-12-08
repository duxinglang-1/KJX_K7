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
 *  vrt_base_allocator.h
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  Container Classes
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_BASE_ALLOCATOR__
#define __VRT_BASE_ALLOCATOR__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

/* Default allocate flag */
#define VRT_ALLOCATOR_ALLOC_FLAG_NONE   (0)
/* Allocate for frame buffer */
#define VRT_ALLOCATOR_ALLOC_FLAG_FB     (1 << 0)

#define vrt_allocator_alloc(_allocator, _alloc_size, _flags) \
    vrt_allocator_alloc_int(_allocator, _alloc_size, _flags, NULL, 0)

#ifndef __MTK_TARGET__ 
/* MODIS */
#define VRT_ALLOCATOR_FILL_FILENAME_LINE(filename, line) \
    do \
    { \
        filename = __FILE__ ; \
        line = __LINE__; \
    } while(0)
#elif defined (__RVCT__)
/* RVCT */
#define VRT_ALLOCATOR_FILL_FILENAME_LINE(filename, line) \
    do \
    { \
        /* link address rather than filename string */ \
        filename =  (const vrt_char *)__current_pc(); \
        line = __LINE__; \
    } while(0)
#else 
/* ADS */
#define VRT_ALLOCATOR_FILL_FILENAME_LINE(filename, line) \
    do \
    { \
        /* link address rather than filename string */ \
        __asm { mov filename, pc; } \
        line = __LINE__; \
    } while(0)
#endif    

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef void (*vrt_allocator_release_user_data_funcptr_type)(
    void *user_data);

typedef void *(*vrt_allocator_alloc_funcptr_type)(
    vrt_size alloc_size,
    void *user_data,
    vrt_flag_type flags,
    const vrt_char *file,
    vrt_u32 line);

typedef void (*vrt_allocator_free_funcptr_type)(
    void *ptr,
    void *user_data);

typedef struct
{
    void *user_data;
    vrt_allocator_release_user_data_funcptr_type release_user_data_callback;
    vrt_allocator_alloc_funcptr_type alloc_callback;
    vrt_allocator_free_funcptr_type free_callback;
} vrt_allocator_info_struct;

typedef struct vrt_allocator_struct *vrt_allocator_handle;


/***************************************************************************** 
 * Global variable
 *****************************************************************************/

extern const vrt_allocator_handle g_vrt_null_allocator;


/***************************************************************************** 
 * Global function
 *****************************************************************************/

extern vrt_allocator_handle vrt_allocator_create(
    vrt_allocator_handle allocator,
    const vrt_allocator_info_struct *info
    );

extern void vrt_allocator_release(
    vrt_allocator_handle allocator
    );

extern void vrt_allocator_set_chain_allocator(
    vrt_allocator_handle allocator,
    vrt_allocator_handle chain_allocator
    );

extern const vrt_allocator_info_struct *vrt_allocator_get_info(
    vrt_allocator_handle allocator
    );

void *vrt_allocator_alloc_int(
    vrt_allocator_handle allocator,
    vrt_size alloc_size,
    vrt_flag_type flags,
    const vrt_char *file,
    vrt_u32 line);

extern void vrt_allocator_free(
    void *ptr
    );

extern vrt_allocator_handle vrt_allocator_get_owner(
    void *ptr
    );


extern vrt_u32 vrt_allocator_get_mem_header_size(
    void
    );
#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /* __VRT_BASE_ALLOCATOR__ */

