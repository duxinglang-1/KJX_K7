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
#include "kal_public_api.h"
#include "kal_trace.h"

#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"

#include "fmt_trc.h"

#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "FileMgrSrvGProt.h"

/****************************************************************************
* Define
*****************************************************************************/


/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/

const static WCHAR g_srv_fmgr_invalid_chars[] = L"/\\:*?\"<>|\n\r\xFFFF";

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
extern S32 srv_fmgri_async_pre_processing(srv_fmgr_notification_adv_action_event_struct * evt);


#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

WCHAR* srv_fmgr_path_get_filename_ptr(WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = srv_fmgr_path_get_filename_pos(path);
    if(pos < 0)
        return NULL;

    return path + pos;
}

const WCHAR* srv_fmgr_path_get_filename_const_ptr(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = srv_fmgr_path_get_filename_pos(path);
    if(pos < 0)
        return NULL;

    return path + pos;
}

S32 srv_fmgr_path_get_filename_pos(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path || !path[0])
        return -1;

    for(i = mmi_wcslen(path) - 2; i >= 0; i--)
    {
        if(path[i] == '\\')
        {
            i++;
            break;
        }
    }
    if(i < 0)
        i = 0;

    if (i == 0)
    {
        while(path[i] == ' ')
            i++;
    }

    return i;
}

WCHAR* srv_fmgr_path_get_extension_ptr(WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = srv_fmgr_path_get_extension_pos(path);
    if(pos < 0)
        return NULL;

    return path + pos;
}

const WCHAR* srv_fmgr_path_get_extension_const_ptr(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = srv_fmgr_path_get_extension_pos(path);
    if(pos < 0)
        return NULL;

    return path + pos;
}

S32 srv_fmgr_path_get_extension_pos(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path)
        return -1;

    f = srv_fmgr_path_get_filename_pos(path);
    if(f < 0)
        return f;
    i = mmi_wcslen(path) - 1;
    if(path[i] == '\\') /* treat as folder */
        return -1;
    for(; i >= f; i--)
    {
        if(path[i] == '.')
        {
            return i+1;
        }
    }
    return -1;
}

MMI_BOOL srv_fmgr_path_is_filename_valid(const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!filename)
        return MMI_FALSE;
    
    if (FS_CheckFileName((WCHAR*)filename) == FS_NO_ERROR)
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

const WCHAR* srv_fmgr_path_get_invalid_chars(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_fmgr_invalid_chars;
}

MMI_BOOL srv_fmgr_path_append(WCHAR* dest_path, S32 dest_path_size, const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_fmgr_path_append_ex(dest_path, dest_path_size, filename, MMI_FALSE);
}

MMI_BOOL srv_fmgr_path_append_ex(WCHAR* dest_path, S32 dest_path_size, const WCHAR* filename, MMI_BOOL add_slash)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dlen, slen, tlen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!dest_path || !filename)
        return MMI_FALSE;
    
    dlen = mmi_wcslen(dest_path);
    slen = mmi_wcslen(filename);
    tlen = dlen + slen;
    if(dest_path[dlen-1] != '\\')
        tlen++;
    if(add_slash && filename[slen-1] != '\\')
        tlen++;

    if((tlen + 1)*2 > dest_path_size)
        return MMI_FALSE;
    
    if(dest_path[dlen-1] != '\\')
    {
        dest_path[dlen] = '\\';
        dlen++;        
    }
    mmi_wcsncpy(dest_path + dlen, filename, slen);
    if(add_slash && dest_path[tlen-1] != '\\')
    {
        dest_path[tlen-1] = '\\';
        dest_path[tlen] = 0;
    }
    return MMI_TRUE;
}


WCHAR* srv_fmgr_path_skip_leading_space(WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path)
        return NULL;
    while(*path)
    {
        if(*path != ' ')
            break;
        path++;
    }
    return path;
}

const WCHAR* srv_fmgr_path_skip_leading_space_const(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path)
        return NULL;
    while(*path)
    {
        if(*path != ' ')
            break;
        path++;
    }
    return path;
}

WCHAR* srv_fmgr_path_remove_filename(WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = srv_fmgr_path_get_filename_ptr(path);
    if(ptr)
        *ptr = 0;
    return path;
}

WCHAR* srv_fmgr_path_remove_slash(WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path)
        return NULL;

    len = mmi_wcslen(path);
    if(path[len-1] == '\\')
        path[len-1] = 0;
    
    return path;
}

MMI_BOOL srv_fmgr_path_hide_extension(WCHAR* path)
{
#if !defined(__MMI_SHOW_FILE_EXT__) || !defined(__MMI_SHOW_DAF_FILE_EXT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR  *ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext = srv_fmgr_path_get_extension_ptr(path);
    if(!ext)
        return MMI_FALSE;

    ext--; /* move to dot */
    
#if !defined(__MMI_SHOW_FILE_EXT__)
    /* Hide all extension */
    *ext = 0;
    return MMI_TRUE;
#endif

#if !defined(__MMI_SHOW_DAF_FILE_EXT__)
    {
        filetypes_file_type_enum filetype;

        filetype = srv_fmgr_types_find_type_by_extension_str(ext+1);

        /* Hide DAF/MP2 ext */
        if(filetype == FMGR_TYPE_DAF ||
            filetype == FMGR_TYPE_MP2)
        {
            *ext = 0;
            return MMI_FALSE;
        }
    }
#endif

#endif
    return MMI_FALSE;
}

S32 srv_fmgr_fs_path_get_display_name(const WCHAR* path, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    SRV_FMGR_FILEINFO_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    handle = 0;
    do {
        fs_ret = srv_fmgr_fileinfo_create(path, &handle);
        if(fs_ret < 0)
            break;

        fs_ret = srv_fmgr_fileinfo_get_display_name(handle, buffer, buffer_size);
        if(fs_ret < 0)
            break;

    } while(0);

    if(handle)
        srv_fmgr_fileinfo_destroy(handle);

    return fs_ret;    
}

S32 srv_fmgr_fs_path_get_fileinfo(const WCHAR* path, srv_fmgr_fileinfo_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    SRV_FMGR_FILEINFO_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    handle = 0;
    do {
        fs_ret = srv_fmgr_fileinfo_create(path, &handle);
        if(fs_ret < 0)
            break;

        srv_fmgr_fileinfo_get_info(handle, info);
        fs_ret = 0;

    } while(0);

    if(handle)
        srv_fmgr_fileinfo_destroy(handle);

    return fs_ret;    
}

S32 srv_fmgr_fs_path_exist(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path)
        return FS_PARAM_ERROR;

    do {
        if(mmi_wcslen(path) <= 3)   /* Drive */
        {
            fs_ret = FS_GetDevType(path);
        }
        else
        {
            fs_ret = FS_GetAttributes(path);
        }
        if(fs_ret < 0)
            break;
        fs_ret = 0;
    } while(0);
    return fs_ret;
}

S32 srv_fmgr_fs_create_folder(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* buf_path;
    S32 fs_ret = FS_NO_ERROR;
    S32 str_len;
    S32 i;
    srv_fmgr_notification_adv_action_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!path)
        return FS_PARAM_ERROR;

    if(srv_fmgr_fs_path_exist(path) >= 0)
        return FS_NO_ERROR;

    str_len = mmi_wcslen(path);
    if(path[str_len-1] != '\\')
        str_len++;
        
    if(str_len > SRV_FMGR_PATH_MAX_LEN)
    {
        return FS_PATH_OVER_LEN_ERROR;
    }

    /* create directory if it is not there */
    buf_path = OslMalloc((str_len + 1) * ENCODING_LENGTH);

    /* skip drive. "C:\" */
    for (i = 3; i < str_len; i ++)
    {
        if (path[i] != '\\' && path[i] != 0)
            continue;

        /* create dir */
        mmi_wcsncpy(buf_path, path, i);
        buf_path[i] = 0;

        if(srv_fmgr_fs_path_exist(buf_path) == 0)
            continue;

        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER;
        evt.src_filepath = buf_path;
        evt.src_fileinfo.attribute = FS_ATTR_DIR;
        evt.src_fileinfo.type = FMGR_TYPE_FOLDER;

		if((fs_ret = srv_fmgri_async_pre_processing(&evt)) < 0)
        {
            break;
        }

        fs_ret = FS_CreateDir((WCHAR*)buf_path);
        
        evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        evt.result = fs_ret;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt);
        
        if(fs_ret == FS_FILE_EXISTS)
            fs_ret = 0;
        if(fs_ret < 0)
            break;
    }

    OslMfree(buf_path);
    return fs_ret;
}

S32 srv_fmgr_fs_path_is_not_empty(const WCHAR* path, const FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_FMGR_DRVLIST_HANDLE hdrvlist;
    FS_HANDLE   file_handle;
    S32         result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        /* root case */
        if (!mmi_wcscmp(path, SRV_FMGR_PATH_ROOT))
        {
            hdrvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
            if(srv_fmgr_drivelist_count(hdrvlist) > 0)
                result = 1; /* not empty */
            else
                result = 0;

            srv_fmgr_drivelist_destroy(hdrvlist);
            break;
        }
        // TODO: [FileMgrSrv][Path] DRM 2.0 multi part


        /* folder case */
        result = srv_fmgri_find_first(path, filter, 0, NULL, 0, NULL, &file_handle);
        if(result == 0)
        {
            srv_fmgri_find_close(file_handle);
            result = 1;
        }
        else if(result == FS_NO_MORE_FILES)
            result = 0;

    } while(0);

    return result;
}

S32 srv_fmgri_path_check_folderpath(const WCHAR* folderpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!folderpath)
        return FS_PARAM_ERROR;

    len = mmi_wcslen(folderpath);
    if(len < 3)
        return FS_PARAM_ERROR;
    if(len > SRV_FMGR_PATH_MAX_LEN || (folderpath[len-1] != '\\' && len+1 > SRV_FMGR_PATH_MAX_LEN))
        return FS_PATH_OVER_LEN_ERROR;

    return len;
}

#define LOCAL_FUNCTION




