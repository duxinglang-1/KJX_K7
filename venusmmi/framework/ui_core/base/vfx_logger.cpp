/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vfx_logger.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Log helper
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_logger.h"

#ifdef VFX_LOGGER_ENABLE

/***************************************************************************** 
 * Include
 *****************************************************************************/

extern "C"
{
#include "fs_type.h"
#include "fs_func.h"
#include "app_str.h"    // for string conversion
#include "FileMgrSrvGProt.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_LOG_FS_NAME       "C:\\@vfx\\venus_vfx.log"
#define VFX_LOG_FILE_NAME     "T:\\venus_vfx.log"

#define VFX_LOG_MEM_RECENT_COUNT    2048

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef struct 
{
    const VfxChar   *funcPtr;
    VfxU32          depth;
} vfx_logger_mem_entry_struct;

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

static FS_HANDLE    g_vfx_logger_fp_target = NULL;
#if !defined(__MTK_TARGET__)
static FILE         *g_vfx_logger_fp_modis = NULL;
#endif

static VfxU32       g_vfx_logger_depth = 0;
static VfxBool      g_vfx_logger_enable = 
#ifdef __MTK_TARGET__
    VFX_FALSE
#else
    VFX_TRUE
#endif
    ;

static VfxFuncLogger *g_vfx_logger_parent = NULL;

static vfx_logger_mem_entry_struct g_vfx_logger_mem_recent_array[VFX_LOG_MEM_RECENT_COUNT] = {0};
static VfxU32 g_vfx_logger_mem_recent_index = 0;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

void vfx_logger_enable_log(VfxBool on)
{
    g_vfx_logger_enable = on;
    if(!g_vfx_logger_enable)
    {
        if(g_vfx_logger_fp_target > 0)
        {
            FS_Close(g_vfx_logger_fp_target);
            g_vfx_logger_fp_target = 0;
        }
    }
#if !defined(__MTK_TARGET__)
    g_vfx_logger_enable = VFX_TRUE;
#endif
}

VfxBool vfx_logger_is_enable_log(void)
{
    return g_vfx_logger_enable;
}

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

static void vfx_logger_write_target(const VfxChar *fmt, ...)
{
    static VfxChar logBuffer[512];
    if (!g_vfx_logger_enable)
        return;
        
    if (g_vfx_logger_fp_target == NULL)
    {
        app_asc_str_to_ucs2_str((kal_int8*)logBuffer, (kal_int8*)VFX_LOG_FS_NAME);
        logBuffer[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        srv_fmgr_path_remove_filename((WCHAR*)logBuffer);
        srv_fmgr_fs_create_folder((WCHAR*)logBuffer);
        FS_SetAttributes((WCHAR*)logBuffer, FS_GetAttributes((WCHAR*)logBuffer) | FS_ATTR_HIDDEN);
    
        app_asc_str_to_ucs2_str((kal_int8*)logBuffer, (kal_int8*)VFX_LOG_FS_NAME);
        logBuffer[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        g_vfx_logger_fp_target = FS_Open((WCHAR*)logBuffer, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if(g_vfx_logger_fp_target < 0)
        {
            g_vfx_logger_enable = VFX_FALSE;
            g_vfx_logger_fp_target = NULL;
            return;
        }
    }
    
    if (g_vfx_logger_fp_target > 0)
    {
        VfxU32 written;

        // space
        VFX_ASSERT(g_vfx_logger_depth*2 < 512);
        kal_mem_set(logBuffer, ' ', g_vfx_logger_depth*2);
        FS_Write(g_vfx_logger_fp_target, logBuffer, g_vfx_logger_depth*2, &written);

        // args
        va_list args;
        va_start(args, fmt);
        written = vsprintf(logBuffer, fmt, args);
        VFX_ASSERT(written < 512);
        va_end(args);
        FS_Write(g_vfx_logger_fp_target, logBuffer, written, &written);

        // lineend
        logBuffer[0] = 0x0D;
        logBuffer[1] = 0x0A;
        FS_Write(g_vfx_logger_fp_target, logBuffer, 2, &written);

        // flush
        FS_Commit(g_vfx_logger_fp_target);
    }
}

#if !defined(__MTK_TARGET__)
static void vfx_logger_write_modis(const VfxChar *fmt, ...)
{
    if (!g_vfx_logger_enable)
        return;

    if (g_vfx_logger_fp_modis == NULL)
    {
        g_vfx_logger_fp_modis = fopen(VFX_LOG_FILE_NAME, "w+t");
    }
    
    if (g_vfx_logger_fp_modis != NULL)
    {
        // space
        VfxU32 depth = g_vfx_logger_depth;
        while(depth)
        {
            fprintf(g_vfx_logger_fp_modis, "  ");
            depth--;
        }

        // args
        va_list args;
        va_start(args, fmt);
        vfprintf(g_vfx_logger_fp_modis, fmt, args);
        va_end(args);

        // lineend
        fprintf(g_vfx_logger_fp_modis, "\n");
        
        // flush
        fflush(g_vfx_logger_fp_modis);
    }
}
#endif

#if defined(__MTK_TARGET__)
#define vfx_logger_write    vfx_logger_write_target
#else
#define vfx_logger_write    vfx_logger_write_modis
#endif

static void vfx_logger_write_mem_entry(const VfxChar *namePtr)
{
    vfx_logger_mem_entry_struct *entry = g_vfx_logger_mem_recent_array + g_vfx_logger_mem_recent_index;
    g_vfx_logger_mem_recent_index++;
    if(g_vfx_logger_mem_recent_index >= VFX_LOG_MEM_RECENT_COUNT)
        g_vfx_logger_mem_recent_index = 0;

    entry->funcPtr = (const VfxChar*)namePtr;
    entry->depth = g_vfx_logger_depth;
}


/***************************************************************************** 
 * class VfxFuncLogger
 *****************************************************************************/

VfxFuncLogger::VfxFuncLogger(void* thisPtr, const VfxChar *namePtr) :
    m_hasChildFunc(VFX_FALSE)
{
    if(g_vfx_logger_parent)
        g_vfx_logger_parent->enableChildFunc();

    vfx_logger_write_mem_entry(namePtr);
    if(thisPtr)
        vfx_logger_write("%s <%08X>", namePtr, thisPtr);
    else
        vfx_logger_write("%s", namePtr);
    g_vfx_logger_parent = this;
}

VfxFuncLogger::VfxFuncLogger(void* thisPtr, const VfxChar *namePtr, const VfxChar *fmt, ...) :
    m_hasChildFunc(VFX_FALSE)
{
    if(g_vfx_logger_parent)
        g_vfx_logger_parent->enableChildFunc();

    VfxChar *logBuffer;
    VfxU32 written;
    va_list args;
    va_start(args, fmt);
    VFX_SYS_ALLOC_MEM(logBuffer, 256);
    written = vsprintf(logBuffer, fmt, args);
    VFX_ASSERT(written < 256);
    va_end(args);

    vfx_logger_write_mem_entry(namePtr);
    if(thisPtr)
        vfx_logger_write("%s <%08X>= %s", namePtr, thisPtr, logBuffer);
    else
        vfx_logger_write("%s = %s", namePtr, logBuffer);

    VFX_SYS_FREE_MEM(logBuffer);        
    g_vfx_logger_parent = this;
}

VfxFuncLogger::~VfxFuncLogger()
{
    if(g_vfx_logger_parent == this)
        g_vfx_logger_parent = NULL;

    if(m_hasChildFunc)
    {
        g_vfx_logger_depth--;
        vfx_logger_write("}");
    }
}

void VfxFuncLogger::enableChildFunc()
{
    vfx_logger_write("{");
    g_vfx_logger_depth++;
    m_hasChildFunc = VFX_TRUE;
}

#else

void vfx_logger_enable_log(VfxBool on)
{
    VFX_UNUSED(on);
}

VfxBool vfx_logger_is_enable_log(void)
{
    return VFX_FALSE;
}

#endif // VFX_LOGGER_ENABLE
