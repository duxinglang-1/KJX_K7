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
 *  FileMgrSrvNotification
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Notification part of FileMgr service
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
#include "kal_trace.h"

#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"

#include "fmt_trc.h"

#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_cb_mgr_gprot.h"
#include "Unicodexdcl.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrSrvIProt.h"

/****************************************************************************
* Define
*****************************************************************************/


/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/


/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
#ifndef 	__MMI_SLIM_FILE_MANAGER__
static S32 srv_fmgri_fs_move(const WCHAR* src_path, const WCHAR* dest_path, srv_fmgr_notification_action_enum action);
static S32 srv_fmgri_fs_delete_by_filter(const WCHAR* folderpath, const FMGR_FILTER* filter);
#endif
extern S32 srv_fmgri_async_pre_processing(srv_fmgr_notification_adv_action_event_struct * evt);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

S32 srv_fmgr_fs_copy(const WCHAR* src_path, const WCHAR* dest_path)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE0(TGL1, TRC_SRV_FMGR_55652A536B364D35B23A943A955A51F8, "[SRV_FMGR] > Sync > copy");
    ret = srv_fmgri_fs_move(src_path, dest_path, SRV_FMGR_NOTIFICATION_ACTION_COPY);
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_9366DD9B50504793A2EC7EC3BDFBDCDC, "[SRV_FMGR] > Sync > return: %d", ret);
    return ret;
#else
    return FS_ERROR_RESERVED;
#endif
}

S32 srv_fmgr_fs_move(const WCHAR* src_path, const WCHAR* dest_path)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE0(TGL1, TRC_SRV_FMGR_FCE9DEA7D6D348AD963712D8D739C684, "[SRV_FMGR] > Sync > move");
    ret = srv_fmgri_fs_move(src_path, dest_path, SRV_FMGR_NOTIFICATION_ACTION_MOVE);
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_9366DD9B50504793A2EC7EC3BDFBDCDC, "[SRV_FMGR] > Sync > return: %d", ret);
    return ret;
#else
    return FS_ERROR_RESERVED;
#endif
}

S32 srv_fmgr_fs_rename(const WCHAR* src_path, const WCHAR* dest_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_adv_action_event_struct evt;
    S32 fs_ret;
    srv_fmgr_fileinfo_struct    info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE0(TGL1, TRC_SRV_FMGR_4391AAA3EDD643EFAD0610590D6F54CD, "[SRV_FMGR] > Sync > rename");

    do {
        if(!src_path || !dest_path)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        fs_ret = srv_fmgr_fs_path_get_fileinfo(src_path, &info);
        if(fs_ret < 0)
            break;
        
        if(info.attribute & FS_ATTR_DIR)
        {
            fs_ret = srv_fmgri_path_check_folderpath(dest_path);
            if(fs_ret < 0)
                break;
        }

        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = SRV_FMGR_NOTIFICATION_ACTION_RENAME;
        evt.src_filepath = src_path;
        evt.src_fileinfo = info;
        evt.dest_filepath = dest_path;
        evt.dest_fileinfo = info;

		if((fs_ret = srv_fmgri_async_pre_processing(&evt)) < 0)
        {
            break;
        }

        fs_ret = FS_Rename(src_path, dest_path);

        evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        evt.result = fs_ret;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt);
        
    } while(0);
    
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_9366DD9B50504793A2EC7EC3BDFBDCDC, "[SRV_FMGR] > Sync > return: %d", fs_ret);
    return fs_ret;
}

S32 srv_fmgr_fs_delete(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_adv_action_event_struct evt;
    S32 fs_ret;
    srv_fmgr_fileinfo_struct info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE0(TGL1, TRC_SRV_FMGR_AC55CB534B9E4462A097A3C8C8EAD672, "[SRV_FMGR] > Sync > delete");

    do {
        if(!path)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        fs_ret = srv_fmgr_fs_path_get_fileinfo(path, &info);
        if(fs_ret < 0)
            return fs_ret;

        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = SRV_FMGR_NOTIFICATION_ACTION_DELETE;
        evt.src_filepath = path;
        evt.src_fileinfo = info;


		if((fs_ret = srv_fmgri_async_pre_processing(&evt)) < 0)
        {
            break;
        }

        if(info.attribute & FS_ATTR_DIR)
            fs_ret = FS_XDelete(path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
        else
            fs_ret = FS_Delete(path);

        evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        evt.result = fs_ret;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt);
        
    } while(0);
    
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_9366DD9B50504793A2EC7EC3BDFBDCDC, "[SRV_FMGR] > Sync > return: %d", fs_ret);
    return fs_ret;
}

S32 srv_fmgr_fs_delete_all(const WCHAR* folderpath, const FMGR_FILTER* filter)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_adv_action_event_struct evt;
    S32 fs_ret;
    srv_fmgr_fileinfo_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE0(TGL1, TRC_SRV_FMGR_FB1CF1CCB4394BDD9CACE38CBB9CDEF9, "[SRV_FMGR] > Sync > delete all");
    
    do {
        if(!folderpath)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }
        fs_ret = srv_fmgr_fs_path_get_fileinfo(folderpath, &info);
        if(fs_ret < 0)
            return fs_ret;
        
        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = SRV_FMGR_NOTIFICATION_ACTION_DELETE;
        evt.src_filepath = folderpath;
        evt.src_fileinfo = info;
        evt.filter = filter;


		if(fs_ret = srv_fmgri_async_pre_processing(&evt) < 0)
        {
            break;
        }

        if(filter && !FMGR_FILTER_IS_SET(filter, FMGR_TYPE_ALL))
        {
            fs_ret = srv_fmgri_fs_delete_by_filter(folderpath, filter);
        }
        else
        {
            fs_ret = FS_XDelete(folderpath, FS_FILE_TYPE, NULL, 0);
        }

        evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        evt.result = fs_ret;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt);
        
    } while(0);
    
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_9366DD9B50504793A2EC7EC3BDFBDCDC, "[SRV_FMGR] > Sync > return: %d", fs_ret);
    return fs_ret;
#else
    return FS_ERROR_RESERVED;
#endif
}

S32 srv_fmgr_fs_soft_unmount(U8 drv_letter)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_soft_mount_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&evt, 0, sizeof(evt));
    evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT;
    evt.size = sizeof(evt);
    evt.drv_letter = drv_letter;
    evt.mount = MMI_FALSE;

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
        "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.mount, evt.drv_letter);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt);

    return FS_SwitchDriveMode(drv_letter, FS_DRIVE_SOFT_UNMOUNT);
#else
    return FS_ERROR_RESERVED;
#endif
}

S32 srv_fmgr_fs_soft_mount(U8 drv_letter)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_soft_mount_event_struct evt;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&evt, 0, sizeof(evt));
    evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT;
    evt.size = sizeof(evt);
    evt.drv_letter = drv_letter;
    evt.mount = MMI_TRUE;

    fs_ret = FS_SwitchDriveMode(drv_letter, FS_DRIVE_SOFT_MOUNT);

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
        "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.mount, evt.drv_letter);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt);
    
    return fs_ret;
#else
    return FS_ERROR_RESERVED;
#endif
}

void srv_fmgri_notify_device_plug_event(srv_fmgri_plug_status_enum in, const U8* drv_table, U8 drv_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_plug_event_struct evt;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI__)
    memset(&evt, 0, sizeof(evt));
    switch (in)
    {
        case SRV_FMGRI_PLUG_IN:
            evt.evt_id = EVT_ID_SRV_FMGRI_CARD_PLUG_IN;
            break;
        case SRV_FMGRI_PLUG_OUT:
            evt.evt_id = EVT_ID_SRV_FMGRI_CARD_PLUG_OUT;
            break;
        case SRV_FMGRI_PLUG_DISPLAY_MOUNTING:
            evt.evt_id = EVT_ID_SRV_FMGRI_CARD_DISPLAY_MOUNTING;
            break;
    }
    evt.size = sizeof(evt);

    evt.count = drv_count;
    for(i=0;i < drv_count;i++)
        evt.drv_letters[i] = drv_table[i];

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
        "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.count, evt.drv_letters[0]);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt);

    if (in == SRV_FMGRI_PLUG_DISPLAY_MOUNTING)
    {
        /* Just to display mounting */
        return;
    }
#endif

    memset(&evt, 0, sizeof(evt));
    switch (in)
    {
        case SRV_FMGRI_PLUG_IN:
            evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN;
            break;
        case SRV_FMGRI_PLUG_OUT:
            evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT;
            break;
    }
    evt.size = sizeof(evt);

    evt.count = drv_count;
    for(i=0;i < drv_count;i++)
        evt.drv_letters[i] = drv_table[i];

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
        "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.count, evt.drv_letters[0]);
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt);

}

S32 srv_fmgri_notify_def_storage_event(U8 drv_letter)
{
#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__) && !defined(__MMI_SLIM_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_set_def_storage_event_struct evt;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE;
        evt.size = sizeof(evt);

        evt.drv_letter = drv_letter;

        evt.state = SRV_FMGR_NOTIFICATION_STATE_QUERY;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.drv_letter);
        if(MMI_RET_ERR == mmi_frm_cb_emit_event((mmi_event_struct*)&evt))
        {
            fs_ret = FS_DEVICE_BUSY;
            break;
        }

        evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.drv_letter);
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt);
        fs_ret = 0;
    } while(0);
    
    return fs_ret;
#else
    return FS_ERROR_RESERVED;
#endif
}



#define LOCAL_FUNCTION

#ifndef __MMI_SLIM_FILE_MANAGER__
static S32 srv_fmgri_fs_move(const WCHAR* src_path, const WCHAR* dest_path, srv_fmgr_notification_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_adv_action_event_struct evt;
    S32 fs_ret;
    srv_fmgr_fileinfo_struct src_info, dest_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        if(!src_path || !dest_path)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        if(action != SRV_FMGR_NOTIFICATION_ACTION_COPY &&
            action != SRV_FMGR_NOTIFICATION_ACTION_MOVE)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        srv_fmgr_fs_path_get_fileinfo(src_path, &src_info);
        srv_fmgr_fs_path_get_fileinfo(dest_path, &dest_info);
        
        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = action;
        evt.src_filepath = src_path;
        evt.src_fileinfo = src_info;
        evt.dest_filepath = dest_path;
        evt.dest_fileinfo = dest_info;

		if(fs_ret = srv_fmgri_async_pre_processing(&evt) < 0)
        {
            break;
        }

        // TODO: [FileMgrSrv][Common] copy buffer
        if(action == SRV_FMGR_NOTIFICATION_ACTION_COPY)
            fs_ret = FS_Move(src_path, dest_path, FS_MOVE_COPY, NULL, NULL, 0);
        else
            fs_ret = FS_Move(src_path, dest_path, FS_MOVE_KILL, NULL, NULL, 0);

        evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        evt.result = fs_ret;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt);
        
    } while(0);
    
    return fs_ret;
}

static S32 srv_fmgri_fs_delete_by_filter(const WCHAR* folderpath, const FMGR_FILTER* filter)
{
#ifndef __MMI_SLIM_FILE_MANAGER__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    WCHAR name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    S32 fs_ret, len;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!folderpath)
        return FS_PARAM_ERROR;

    len = mmi_wcslen(folderpath);
    if(!len)
        return FS_PARAM_ERROR;

    if(len > SRV_FMGR_PATH_MAX_LEN || (folderpath[len-1] != '\\' && len+1 > SRV_FMGR_PATH_MAX_LEN))
        return FS_PATH_OVER_LEN_ERROR;

    fs_ret = srv_fmgri_find_first(folderpath, filter, 0, name, sizeof(name), NULL, &fh);
    if(fs_ret < 0)
        return fs_ret;

    path = srv_fmgri_alloc_path_buffer();
    mmi_wcsncpy(path, folderpath, len);
    
    if(path[len-1] != '\\')
    {
        path[len++] = '\\';
        path[len] = 0;
    }
    
    do {
        if(mmi_wcslen(name) + len < SRV_FMGR_PATH_MAX_LEN)
        {
            mmi_wcscpy(path + len, name);
            fs_ret = FS_Delete(path);
            if(fs_ret < 0)
                break;
        }

        fs_ret = srv_fmgri_find_next(fh, filter, name, sizeof(name), NULL);

    } while(fs_ret >= 0);

    srv_fmgri_free_path_buffer(path);
    srv_fmgri_find_close(fh);

    return fs_ret;    
#else 
	return FS_ERROR_RESERVED;
#endif
}
#endif /* __MMI_SLIM_FILE_MANAGER__ */


