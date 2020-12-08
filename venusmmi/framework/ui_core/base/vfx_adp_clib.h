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
 *  vfx_adp_clib.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Standard C Libary Adapatation Layer
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

#ifndef __VFX_ADP_CLIB_H__
#define __VFX_ADP_CLIB_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For basic types
#include "vfx_datatype.h"

#include <stdarg.h>


#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*
 * File operator defines
 */
#define VFX_UC_SYS_FILE_OPEN_MODE_READ   0x00000001
#define VFX_UC_SYS_FILE_OPEN_MODE_WRITE  0x00000002
#define VFX_UC_SYS_FILE_OPEN_MODE_CREATE 0x00000004


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/*
 * File operator types
 */
typedef VfxFlag vfx_sys_file_open_mode;

typedef enum
{
    VFX_UC_SYS_FILE_SEEK_ORIGIN_BEGIN,
    VFX_UC_SYS_FILE_SEEK_ORIGIN_CURRENT,
    VFX_UC_SYS_FILE_SEEK_ORIGIN_END,
    VFX_UC_SYS_FILE_SEEK_ORIGIN_END_OF_ENUM
} vfx_sys_file_seek_origin_enum;

typedef void *vfx_sys_file_handle;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/* 
 * String operator functions 
 */
extern VfxU32 vfx_sys_strlen(const VfxChar *str); 
extern VfxS32 vfx_sys_strcmp(const VfxChar *str1, const VfxChar *str2); 
extern VfxChar *vfx_sys_strcpy(VfxChar *str1, const VfxChar *str2); 
extern VfxU32 vfx_sys_wcslen(const VfxWChar *str);
extern VfxS32 vfx_sys_wcscmp(const VfxWChar *str1, const VfxWChar *str2); 
extern VfxS32 vfx_sys_wcsncmp(const VfxWChar *str1, const VfxWChar *str2, VfxU32 n); 
extern VfxWChar *vfx_sys_wcscpy(VfxWChar *dest, const VfxWChar *str); 
extern VfxWChar *vfx_sys_wcsncpy(VfxWChar *dest, const VfxWChar *str, VfxU32 n); 
extern VfxS32 vfx_sys_vswprintf(VfxWChar *buf, VfxU32 max_len, const VfxWChar *format, va_list args);
extern VfxU32 vfx_sys_mbstowcs(VfxWChar *wcstr, const VfxChar *mbstr, VfxU32 count);

/*
 * File operator functions
 */
extern vfx_sys_file_handle vfx_sys_file_open(const VfxWChar *filename, vfx_sys_file_open_mode mode);
extern void vfx_sys_file_close(vfx_sys_file_handle handle);
extern VfxS32 vfx_sys_file_seek(vfx_sys_file_handle handle, VfxS32 offset, vfx_sys_file_seek_origin_enum origin);
extern VfxU32 vfx_sys_file_get_pos(vfx_sys_file_handle handle);
extern VfxU32 vfx_sys_file_read(vfx_sys_file_handle handle, VfxU8 *buf, VfxU32 size);
extern VfxU32 vfx_sys_file_write(vfx_sys_file_handle handle, const VfxU8 *buf, VfxU32 size);

/*
 * Math functions
 */
extern VfxFloat vfx_sys_sin(VfxFloat rad);
extern VfxFloat vfx_sys_cos(VfxFloat rad);
extern VfxFloat vfx_sys_sqrt(VfxFloat x);
extern VfxFloat vfx_sys_floor(VfxFloat x);
extern VfxFloat vfx_sys_ceil(VfxFloat x);

/*
 * Memory functions
 */
extern void vfx_sys_mem_zero(void *ptr, VfxU32 size);
extern void vfx_sys_mem_copy(void *dst, const void *src, VfxU32 size);

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VFX_ADP_CLIB_H__ */

