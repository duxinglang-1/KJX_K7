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
 *  vfx_adp_clib.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_adp_clib.h"

#include <math.h>           /* For sqrt */
#include <string.h>
#include <wchar.h>
#include <stdarg.h>

#include "vrt_datatype.h"
#include "vrt_math.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "Unicodexdcl.h"   /* For mmi ucs2 */


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_SYS_FILE_FSH_TO_HANDLE(fsh) ((vfx_sys_file_handle)((fsh) | 0x80000000))
#define VFX_SYS_FILE_HANDLE_TO_FSH(h)   (((FS_HANDLE)(h)) & ~0x80000000)


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vfx_sys_strlen
 * DESCRIPTION
 *  caculate string length without zero-terminal
 * PARAMETERS
 *  str         [IN]    string to caculate
 * RETURNS
 *  return the string length
 *****************************************************************************/
VfxU32 vfx_sys_strlen(const VfxChar *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxU32)strlen((const char *)str);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_strcmp
 * DESCRIPTION
 *  Compare two string
 * PARAMETERS
 *  str1        [IN]    first string to compare
 *  str2        [IN]    second string to compare
 * RETURNS
 *  return 0 if two strings are equeal
 *****************************************************************************/
VfxS32 vfx_sys_strcmp(const VfxChar *str1, const VfxChar *str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxS32)strcmp((const char *)str1, (const char *)str2);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_wcscpy
 * DESCRIPTION
 *  Copy a string to given buffer
 * PARAMETERS
 *  dest        [IN]    destination buffer to copy
 *  str         [IN]    the string to be copied
 * RETURNS
 *  pointer to dest buffer
 *****************************************************************************/
VfxChar *vfx_sys_strcpy(VfxChar *dest, const VfxChar *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxChar *)strcpy((char *)dest, (const char *)str);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_wcslen
 * DESCRIPTION
 *  caculate wide-string length without zero-terminal
 * PARAMETERS
 *  str         [IN]    string to caculate
 * RETURNS
 *  return the string length
 *****************************************************************************/
VfxU32 vfx_sys_wcslen(const VfxWChar *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return (VfxU32)wcslen((const wchar_t *)str);
    return (VfxU32)mmi_ucs2strlen((const CHAR *)str);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_wcscmp
 * DESCRIPTION
 *  Compare two wide-string
 * PARAMETERS
 *  str1        [IN]    first string to compare
 *  str2        [IN]    second string to compare
 * RETURNS
 *  return 0 if two strings are equeal
 *****************************************************************************/
VfxS32 vfx_sys_wcscmp(const VfxWChar *str1, const VfxWChar *str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return (VfxS32)wcscmp((const wchar_t *)str1, (const wchar_t *)str2); 
    return (VfxS32)mmi_ucs2cmp((const CHAR *)str1, (const CHAR *)str2); 
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_wcscmp
 * DESCRIPTION
 *  Compare two wide-string
 * PARAMETERS
 *  str1        [IN]    first string to compare
 *  str2        [IN]    second string to compare
 *  n           [IN]    max number of character to compare
 * RETURNS
 *  return 0 if two strings are equeal
 *****************************************************************************/
VfxS32 vfx_sys_wcsncmp(const VfxWChar *str1, const VfxWChar *str2, VfxU32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return (VfxS32)wcsncmp((const wchar_t *)str1, (const wchar_t *)str2, n); 
    return (VfxS32)mmi_ucs2ncmp((const CHAR *)str1, (const CHAR *)str2, n);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_wcscpy
 * DESCRIPTION
 *  Copy a wide-string to given buffer
 * PARAMETERS
 *  dest        [IN]    destination buffer to copy
 *  str         [IN]    the string to be copied
 * RETURNS
 *  pointer to dest buffer
 *****************************************************************************/
VfxWChar *vfx_sys_wcscpy(VfxWChar *dest, const VfxWChar *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return (VfxWChar *)wcscpy((wchar_t *)dest, (const wchar_t *)str); 
    return (VfxWChar *)mmi_ucs2cpy((CHAR *)dest, (const CHAR *)str);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_wcsncpy
 * DESCRIPTION
 *  Copy a wide-string to given buffer
 * PARAMETERS
 *  dest        [IN]    destination buffer to copy
 *  str         [IN]    the string to be copied
 *  n           [IN]    max number of character to copy
 * RETURNS
 *  pointer to dest buffer
 *****************************************************************************/
VfxWChar *vfx_sys_wcsncpy(VfxWChar *dest, const VfxWChar *str, VfxU32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return (VfxWChar *)wcsncpy((wchar_t *)dest, (const wchar_t *)str, n); 
    return (VfxWChar *)mmi_ucs2ncpy((CHAR *)dest, (const CHAR *)str, n);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_vswprintf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf         [OUT]
 *  max_len     [IN]
 *  format      [IN]
 *  args        [IN]
 * RETURNS
 *  
 *****************************************************************************/
VfxS32 vfx_sys_vswprintf(VfxWChar *buf, VfxU32 max_len, const VfxWChar *format, va_list args)
{
    return vswprintf((wchar_t *)buf, (size_t)max_len, (const wchar_t *)format, args);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mbstowcs
 * DESCRIPTION
 *  Convert a multibyte character string to a wide character string.
 * PARAMETERS
 *  wcstr       [OUT]   The buffer of output wide character string
 *  mbstr       [IN]    The multibyte character string to be converted
 *  count       [IN]    The number of multibyte characters to convert
 * RETURNS
 *  The number of converted multibyte characters
 *****************************************************************************/
VfxU32 vfx_sys_mbstowcs(VfxWChar *wcstr, const VfxChar *mbstr, VfxU32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return (VfxS32)mbstowcs((wchar_t *)wcstr, (const char *)mbstr, (size_t)count);
    if (count == 0)
    {
        /* Do nothing */
        return 0;
    }

    /* The mmi_asc_n_to_ucs2 return value is output bytes, included zero-terminated */
    return (VfxU32)mmi_asc_n_to_ucs2(
        (CHAR *)wcstr, 
        (CHAR *)mbstr, 
        (U32)count) / 2 - 1;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_file_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
vfx_sys_file_handle vfx_sys_file_open(const VfxWChar *filename, vfx_sys_file_open_mode mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    U32 flag = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(mode != 0);
    
    if (mode == VFX_UC_SYS_FILE_OPEN_MODE_READ)
    {
        flag = FS_READ_ONLY;
    }
    else
    {
        flag = FS_READ_WRITE;
    }
    
    if (mode & VFX_UC_SYS_FILE_OPEN_MODE_CREATE)
    {
        flag |= FS_CREATE_ALWAYS;
    }

    fs_ret = FS_Open((const WCHAR *)filename, flag);
    if (fs_ret < FS_NO_ERROR)
    {
        return NULL;
    }

    return VFX_SYS_FILE_FSH_TO_HANDLE(fs_ret);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_file_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vfx_sys_file_close(vfx_sys_file_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fsh = VFX_SYS_FILE_HANDLE_TO_FSH(handle);
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(fsh >= 0);

    FS_Close(fsh);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_file_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  If successful, returns a zero value. Otherwise, returns nonzero value.
 *****************************************************************************/
VfxS32 vfx_sys_file_seek(vfx_sys_file_handle handle, VfxS32 offset, vfx_sys_file_seek_origin_enum origin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fsh = VFX_SYS_FILE_HANDLE_TO_FSH(handle);
    S32 fs_origin = 0;
    S32 fs_ret;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(fsh >= 0);

    switch (origin)
    {
        case VFX_UC_SYS_FILE_SEEK_ORIGIN_BEGIN:
            fs_origin = FS_FILE_BEGIN;
            break;
            
        case VFX_UC_SYS_FILE_SEEK_ORIGIN_CURRENT:
            fs_origin = FS_FILE_CURRENT;
            break;
            
        case VFX_UC_SYS_FILE_SEEK_ORIGIN_END:
            fs_origin = FS_FILE_END;
            break;
            
        default:
            VFX_ASSERT(0);
    };

    fs_ret = FS_Seek(fsh, (S32)offset, fs_origin);
    if (fs_ret < FS_NO_ERROR)
    {
        return -1;
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_file_get_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxU32 vfx_sys_file_get_pos(vfx_sys_file_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fsh = VFX_SYS_FILE_HANDLE_TO_FSH(handle);
    U32 fs_pos;
    S32 fs_ret;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(fsh >= 0);

    fs_ret = FS_GetFilePosition(fsh, &fs_pos);
    if (fs_ret < FS_NO_ERROR)
    {
        return 0;
    }
    
    return (VfxU32)fs_pos;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_file_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxU32 vfx_sys_file_read(vfx_sys_file_handle handle, VfxU8 *buf, VfxU32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fsh = VFX_SYS_FILE_HANDLE_TO_FSH(handle);
    S32 fs_ret;
    U32 fs_read_size = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(fsh >= 0);

    fs_ret = FS_Read(fsh, buf, size, &fs_read_size);
    if (fs_ret < FS_NO_ERROR)
    {
        return 0;
    }

    return (VfxU32)fs_read_size;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_file_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxU32 vfx_sys_file_write(vfx_sys_file_handle handle, const VfxU8 *buf, VfxU32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fsh = VFX_SYS_FILE_HANDLE_TO_FSH(handle);
    S32 fs_ret;
    U32 fs_write_size = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(fsh >= 0);

    fs_ret = FS_Write(fsh, (void *)buf, size, &fs_write_size);
    if (fs_ret < FS_NO_ERROR)
    {
        return 0;
    }

    return (VfxU32)fs_write_size;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_cos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxFloat vfx_sys_cos(VfxFloat rad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vrt_cos(rad);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_sin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxFloat vfx_sys_sin(VfxFloat rad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vrt_sin(rad);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_sin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxFloat vfx_sys_sqrt(VfxFloat x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sqrtf(x);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_floor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxFloat vfx_sys_floor(VfxFloat x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return floorf(x);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_ceil
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
VfxFloat vfx_sys_ceil(VfxFloat x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return ceilf(x);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_zero
 * DESCRIPTION
 *  Clear a given buffer to zero
 * PARAMETERS
 *  ptr         [IN]    pointer to the buffer to be clear
 *  size        [IN]    the buffer size
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_zero(void *ptr, VfxU32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(ptr != NULL);

    if (size > 0)
    {
        memset(ptr, 0, (size_t)size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mem_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]   the destination buffer to copy to
 *  src         [IN]   the source buffer to be copied
 *  size        [IN]   the size to be copied
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mem_copy(void *dst, const void *src, VfxU32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(dst != NULL);
    VFX_ASSERT(src != NULL);

    if (size > 0)
    {
        memcpy(dst, src, (size_t)size);
    }
}

