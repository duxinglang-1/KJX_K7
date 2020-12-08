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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _FMGR_INTERNAL_SOURCE_C_
#define _FMGR_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
// by RHR //#include "MMI_include.h"

#include "FileMgrSrvProt.h"

#include "string.h"
#include "kal_general_types.h"

#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"

#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "mmi_rp_file_type_def.h"
#include "custom_mmi_default_value.h"

/****************************************************************************
* Define
*****************************************************************************/

#define FILEINFO_FLAG_TYPE 0x01
#define FILEINFO_FLAG_SIZE 0x02
#define FILEINFO_FLAG_TIME 0x04
#define FILEINFO_FLAG_ATTR 0x08

#define FILEINFO_FLAG_ALL  0xFF

/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/


/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
static void srv_fmgri_fileinfo_get_info(SRV_FMGR_FILEINFO_HANDLE handle, srv_fmgr_fileinfo_struct* fileinfo, U32 flags);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

S32 srv_fmgr_fileinfo_create(const WCHAR* path, SRV_FMGR_FILEINFO_HANDLE* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    WCHAR *filepath;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!handle)
        return FS_PARAM_ERROR;

    len = mmi_wcslen(path);
    if(len > SRV_FMGR_PATH_MAX_LEN)
        return FS_PATH_OVER_LEN_ERROR;

    if(path[len-1] == '\\' && len > 3)
    {
        len--;
        filepath = srv_fmgri_alloc_path_buffer();
        mmi_wcsncpy(filepath, path, len);
        fh = FS_Open(filepath, FS_READ_ONLY | FS_OPEN_SHARED);
        srv_fmgri_free_path_buffer(filepath);
    }
    else
    {
        fh = FS_Open(path, FS_READ_ONLY | FS_OPEN_SHARED);
    }
    
    if(fh < 0)
        return fh;

    *handle = fh;
    return 0;
}

void srv_fmgr_fileinfo_destroy(SRV_FMGR_FILEINFO_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Close(handle);
}

S32 srv_fmgr_fileinfo_get_name(SRV_FMGR_FILEINFO_HANDLE handle, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret, len;
    WCHAR* filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    filename = srv_fmgri_alloc_path_buffer();

    do {
        
        fs_ret = FS_MakeFileName(handle, FS_LONGNAME_ATTR, filename, SRV_FMGR_PATH_BUFFER_SIZE);
        if(fs_ret == FS_PARAM_ERROR)
            fs_ret = FS_MakeFileName(handle, 0, filename, SRV_FMGR_PATH_BUFFER_SIZE);
        if(fs_ret < 0)
            break;
        
        len = mmi_wcslen(filename);

        if(!buffer)
        {
            fs_ret = len;
            break;
        }
        
        if((len+1)*ENCODING_LENGTH > buffer_size)
        {
            fs_ret = FS_STRING_BUFFER_TOO_SMALL;
            break;
        }

        fs_ret = 0;
        mmi_wcsncpy(buffer, filename, len);
    
    } while(0);    

    srv_fmgri_free_path_buffer(filename);
    return fs_ret;
}

S32 srv_fmgr_fileinfo_get_extension(SRV_FMGR_FILEINFO_HANDLE handle, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret, len;
    WCHAR* filename;
    WCHAR* extension;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    filename = srv_fmgri_alloc_path_buffer();

    do {
        
        fs_ret = FS_MakeFileName(handle, FS_LONGNAME_ATTR, filename, SRV_FMGR_PATH_BUFFER_SIZE);
        if(fs_ret == FS_PARAM_ERROR)
            fs_ret = FS_MakeFileName(handle, 0, filename, SRV_FMGR_PATH_BUFFER_SIZE);
        if(fs_ret < 0)
            break;

        extension = srv_fmgr_path_get_extension_ptr(filename);
        if(extension)
            len = mmi_wcslen(extension);
        else
            len = 0;

        if(len > SRV_FMGR_PATH_MAX_FILE_EXT_LEN)
            len = SRV_FMGR_PATH_MAX_FILE_EXT_LEN;
        
        if(!buffer)
        {
            fs_ret = len;
            break;
        }
        
        if((len+1)*ENCODING_LENGTH > buffer_size)
        {
            fs_ret = FS_STRING_BUFFER_TOO_SMALL;
            break;
        }

        fs_ret = 0;
        if(extension)
            mmi_wcsncpy(buffer, extension, len);
        else
            buffer[0] = 0;
    
    } while(0);    

    srv_fmgri_free_path_buffer(filename);
    return fs_ret;
}

void srv_fmgr_fileinfo_get_info(SRV_FMGR_FILEINFO_HANDLE handle, srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgri_fileinfo_get_info(handle, fileinfo, FILEINFO_FLAG_ALL);
}

filetypes_file_type_enum srv_fmgr_fileinfo_get_type(SRV_FMGR_FILEINFO_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct fileinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgri_fileinfo_get_info(handle, &fileinfo, FILEINFO_FLAG_TYPE);
    return (filetypes_file_type_enum)fileinfo.type;
}

U32 srv_fmgr_fileinfo_get_size(SRV_FMGR_FILEINFO_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct fileinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgri_fileinfo_get_info(handle, &fileinfo, FILEINFO_FLAG_SIZE);
    return (filetypes_file_type_enum)fileinfo.size;
}

void srv_fmgr_fileinfo_get_datetime(SRV_FMGR_FILEINFO_HANDLE handle, MYTIME* datetime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct fileinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!datetime)
        return;
    srv_fmgri_fileinfo_get_info(handle, &fileinfo, FILEINFO_FLAG_TIME);
    *datetime = fileinfo.datetime;
}

U32 srv_fmgr_fileinfo_get_attribute(SRV_FMGR_FILEINFO_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct fileinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgri_fileinfo_get_info(handle, &fileinfo, FILEINFO_FLAG_ATTR);
    return fileinfo.attribute;
}

MMI_BOOL srv_fmgr_fileinfo_is_folder(SRV_FMGR_FILEINFO_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(srv_fmgr_fileinfo_get_attribute(handle) & FS_ATTR_DIR);
}

MMI_BOOL srv_fmgr_fileinfo_is_in_archive(SRV_FMGR_FILEINFO_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: [FileMgrSrv] DRM 2.0 
    return MMI_FALSE;
}

S32 srv_fmgr_fileinfo_get_display_name(SRV_FMGR_FILEINFO_HANDLE handle, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret, len;
    WCHAR* filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    filename = srv_fmgri_alloc_path_buffer();

    do {
        
        fs_ret = FS_MakeFileName(handle, FS_LONGNAME_ATTR, filename, SRV_FMGR_PATH_BUFFER_SIZE);
        if(fs_ret == FS_PARAM_ERROR)
            fs_ret = FS_MakeFileName(handle, 0, filename, SRV_FMGR_PATH_BUFFER_SIZE);
        if(fs_ret < 0)
            break;
        
        len = mmi_wcslen(filename);

        if(!buffer)
        {
            fs_ret = len;
            break;
        }
        
        fs_ret = 0;
        if((len+1)*ENCODING_LENGTH > buffer_size)
        {
            len = (buffer_size / ENCODING_LENGTH) - 1;
            mmi_wcsncpy(buffer, filename, len);
            buffer[len-1] = 0x2026;
        }
        else
        {
            mmi_wcsncpy(buffer, filename, len);
        }
    
    } while(0);    

    srv_fmgri_free_path_buffer(filename);
    return fs_ret;
}

#define LOCAL_FUNCTION

static void srv_fmgri_fileinfo_get_info(SRV_FMGR_FILEINFO_HANDLE handle, srv_fmgr_fileinfo_struct* fileinfo, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    FS_FileInfo fs_info;
    WCHAR extension[SRV_FMGR_PATH_MAX_FILE_EXT_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!fileinfo)
        return;

    memset(&fs_info, 0, sizeof(fs_info));
    memset(fileinfo, 0, sizeof(srv_fmgr_fileinfo_struct));
    fs_ret = FS_GetFileInfoEx(handle, &fs_info, FS_FI_BASIC_INFO);
    if(fs_ret < 0)
        return;
    if(!fs_info.DirEntry)
        return;

    if(flags & FILEINFO_FLAG_ATTR)
        fileinfo->attribute = fs_info.DirEntry->Attributes;

    if(flags & FILEINFO_FLAG_TIME)
    {
        fileinfo->datetime.nYear = fs_info.DirEntry->DateTime.Year1980 + 1980;
        fileinfo->datetime.nMonth = fs_info.DirEntry->DateTime.Month;
        fileinfo->datetime.nDay = fs_info.DirEntry->DateTime.Day;
        fileinfo->datetime.nHour = fs_info.DirEntry->DateTime.Hour;
        fileinfo->datetime.nMin = fs_info.DirEntry->DateTime.Minute;
        fileinfo->datetime.nSec = fs_info.DirEntry->DateTime.Second2;

        fileinfo->created_datetime.nYear = fs_info.DirEntry->CreateDateTime.Year1980 + 1980;
        fileinfo->created_datetime.nMonth = fs_info.DirEntry->CreateDateTime.Month;
        fileinfo->created_datetime.nDay = fs_info.DirEntry->CreateDateTime.Day;
        fileinfo->created_datetime.nHour = fs_info.DirEntry->CreateDateTime.Hour;
        fileinfo->created_datetime.nMin = fs_info.DirEntry->CreateDateTime.Minute;
        fileinfo->created_datetime.nSec = fs_info.DirEntry->CreateDateTime.Second2;
    }
    
    if(flags & FILEINFO_FLAG_SIZE)
    {
        if(fileinfo->attribute & FS_ATTR_DIR)
            fileinfo->size = 0;
        else
            fileinfo->size = fs_info.DirEntry->FileSize;
    }

    if(flags & FILEINFO_FLAG_TYPE)
    {
        if(fileinfo->attribute & FS_ATTR_DIR)
        {
            fileinfo->type = FMGR_TYPE_FOLDER;
        }
        else
        {
            fs_ret = srv_fmgr_fileinfo_get_extension(handle, extension, sizeof(extension));
            if(fs_ret == 0)
            {
                fileinfo->type = srv_fmgr_types_find_type_by_extension_str(extension);
                // TODO: [FileMgrSrv] check DRM 2.0 (use drm_open_file instead of FS_Open)
            }
        }
    }
}

