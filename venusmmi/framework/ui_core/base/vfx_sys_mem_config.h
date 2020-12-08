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
 *  vfx_sys_mem_config.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Engine Memory Relative Configure
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
#ifndef __VFX_SYS_MEM_CONFIG_H__
#define __VFX_SYS_MEM_CONFIG_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For basic types
#include "vfx_datatype.h"
// For vrt_mem_provider_handle
#include "vrt_system.h"
// For vrt_allocator_handle
#include "vrt_base_allocator.h"

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

// Share APP context pool for VRT context pool (only for VFX_SYS_USE_GLOBAL_VRT_CONTEXT defined)
#define VFX_SYS_MEM_CONFIG_FLAG_SHARE_APP_CONTEXT_FOR_VRT   (1 << 0)
// Forbid VRT to use the GDI 2nd layer pool as temp memory
#define VFX_SYS_MEM_CONFIG_FLAG_FORBID_GDI_LAYER            (1 << 1)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef struct
{
    vrt_allocator_handle app_allocator;
    VfxFlag flags;
} vfx_sys_mem_config_param_struct;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern void vfx_sys_mem_config_entry(const vfx_sys_mem_config_param_struct *param);
extern void vfx_sys_mem_config_leave(void);
extern void vfx_sys_mem_config_screen_entered(void);

extern VfxU32 vfx_sys_mem_config_is_vrt_able_to_run(VfxU32 app_size);

extern vrt_allocator_handle vfx_sys_mem_get_global_allocator(void);
extern vrt_allocator_handle vfx_sys_get_vrt_context_allocator(void);

extern vrt_mem_provider_handle vfx_sys_get_vrt_mem_provider(void);

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VFX_SYS_MEM_CONFIG_H__ */

