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
 *  FileMgrSrvAsyncFS.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AsyncFS service
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
// by RHR //#include "MMI_include.h"

#include "FileMgrSrvProt.h"

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "stack_config.h"

#include "fs_type.h"
#include "fs_errcode.h"

#include "fmt_def.h"
#include "fmt_struct.h"
#include "fmt_main.h"
#include "fmt_trc.h"

// by RHR //#include "mdi_datatype.h"   /* for MDI_AUD_SUSPEND_BG_FMGR */
#include "mdi_audio.h"

#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"

#include "FileMgrSrvGProt.h"
#include "UCMSrvGProt.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"


/****************************************************************************
* Setting
*****************************************************************************/

#ifndef __RF_DESENSE_TEST__
#define FMGR_WORKAROUND_SUSPEND_BG_AUDIO
#define FMGR_WORKAROUND_ABORT_COPY
#endif

// For Cosmos, disable the workaround
#ifdef __COSMOS_MMI_PACKAGE__
#ifdef FMGR_WORKAROUND_SUSPEND_BG_AUDIO
#undef FMGR_WORKAROUND_SUSPEND_BG_AUDIO
#endif
#endif

/****************************************************************************
* Define
*****************************************************************************/

#ifdef FMGR_WORKAROUND_SUSPEND_BG_AUDIO
#define FMGR_BG_AUDIO_SUSPEND   mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_FMGR)
#define FMGR_BG_AUDIO_RESUME    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_FMGR)
#else
#define FMGR_BG_AUDIO_SUSPEND
#define FMGR_BG_AUDIO_RESUME
#endif

#define MAX_CONCURRENT_JOB  20

#define FMGR_JOB_ID_FORMAT  FMT_ADV_JOB_MAX+1
#define FMGR_JOB_ID_CHKDRV  FMT_ADV_JOB_MAX+2


#define BITMASK_SET(tbl,idx)    do { ((tbl)[idx/32]) |= ( (((unsigned int)1)<<(idx%32))); } while(0)
#define BITMASK_CLEAR(tbl,idx)  do { ((tbl)[idx/32]) &= (~(((unsigned int)1)<<(idx%32))); } while(0)
#define BITMASK_IS_SET(tbl,idx) ( ((tbl)[idx/32]) &  (((unsigned int)1)<<(idx%32)) )


typedef struct {

    S32 jobs[MAX_CONCURRENT_JOB];
    U32 jobs_cancel[(MAX_CONCURRENT_JOB+31)/32];

} srv_fmgri_async_context;

typedef struct {

    void* user_data;    /* client's user_data */
    srv_fmgr_fileinfo_struct src_info, dest_info;
    FMGR_FILTER filter;

} srv_fmgri_async_userdata_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/

static srv_fmgri_async_context g_srv_fmgri_async_ctxt;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

/* job list API */
static void srv_fmgri_async_job_insert(S32 job_id);
static MMI_BOOL srv_fmgri_async_job_remove(S32 job_id);
static MMI_BOOL srv_fmgri_async_job_exist(S32 job_id);
static U32  srv_fmgri_async_job_count(void);
static MMI_BOOL srv_fmgri_async_job_cancel_rsp(S32 job_id);
static MMI_BOOL srv_fmgri_async_job_is_cancel(S32 job_id);

/* helper */
static S32 srv_fmgri_async_copy(const WCHAR* src_path, const WCHAR* dest_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data, U32 fs_flag);
S32 srv_fmgri_async_pre_processing(srv_fmgr_notification_adv_action_event_struct* evt);
static void srv_fmgri_async_evt_emit(U16 evt_id, S32 job_id, S32 result, void* callback, void* user_data);

/* primitive handler */
static void srv_fmgri_async_copy_rsp_hdlr(void *info);
static void srv_fmgri_async_delete_rsp_hdlr(void *info);
static void srv_fmgri_async_create_folder_rsp_hdlr(void *info);
#ifndef __MMI_SLIM_FILE_MANAGER__
static void srv_fmgri_async_get_folder_size_rsp_hdlr(void *info);
static void srv_fmgri_async_get_folder_size_ind_hdlr(void *info);
#endif
static void srv_fmgri_async_format_rsp_hdlr(void *info);
#ifdef __FS_CHECKDRIVE_SUPPORT__
static void srv_fmgri_async_chkdrv_rsp_hdlr(void *info);
#endif

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

void srv_fmgr_async_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&g_srv_fmgri_async_ctxt, 0, sizeof(g_srv_fmgri_async_ctxt));
}

S32 srv_fmgr_async_copy(const WCHAR* src_path, const WCHAR* dest_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_061FDAD3C75F4B26A4808175B9FC5C5D, 
        "[SRV_FMGR] > Async > copy(%d,%x,%x)", flag, user_proc, user_data);
    
    ret = srv_fmgri_async_copy(src_path, dest_path, flag, user_proc, user_data, FS_MOVE_COPY);

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_56BA6784570E42AE805DD015E956E0DF, 
        "[SRV_FMGR] > Async > return: %d", ret);
    return ret;
}

S32 srv_fmgr_async_move(const WCHAR* src_path, const WCHAR* dest_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_C3A7ED94557A485F91479979435DEFDD, 
        "[SRV_FMGR] > Async > move(%d,%x,%x)", flag, user_proc, user_data);

    ret = srv_fmgri_async_copy(src_path, dest_path, flag, user_proc, user_data, FS_MOVE_KILL);
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_56BA6784570E42AE805DD015E956E0DF, 
        "[SRV_FMGR] > Async > return: %d", ret);
    return ret;
}

S32 srv_fmgr_async_delete(const WCHAR* src_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_delete_req_struct   *msg_req;
    S32                         job_id, fs_ret;

    srv_fmgr_fileinfo_struct    info;

    srv_fmgri_async_userdata_struct *async_data;
    srv_fmgr_notification_adv_action_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_9583BC7D91B84EA18A94BEB525B3F9ED, 
        "[SRV_FMGR] > Async > delete(%d,%x,%x)", flag, user_proc, user_data);

    do {
        if(!src_path || !src_path[0] || !user_proc)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }
        
        if(mmi_wcslen(src_path) > SRV_FMGR_PATH_MAX_LEN)
        {
            fs_ret = FS_PATH_OVER_LEN_ERROR;
            break;
        }

        // TODO: temporary solution when FS not support multi request
        if(srv_fmgri_async_job_count())
        {
            fs_ret = FS_DEVICE_BUSY;
            break;
        }

        fs_ret = srv_fmgr_fs_path_get_fileinfo(src_path, &info);
        if(fs_ret < 0)
            break;

        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = SRV_FMGR_NOTIFICATION_ACTION_DELETE;
        evt.src_filepath = src_path;
        evt.src_fileinfo = info;

        if ((fs_ret = srv_fmgri_async_pre_processing(&evt)) < 0)
        {
            break;
        }

        FMGR_BG_AUDIO_SUSPEND;

        async_data = OslMalloc(sizeof(srv_fmgri_async_userdata_struct));
        memset(async_data, 0, sizeof(srv_fmgri_async_userdata_struct));
        async_data->user_data = user_data;
        async_data->src_info = info;

        msg_req = (fmt_adv_delete_req_struct*) OslConstructDataPtr(sizeof(fmt_adv_delete_req_struct));

        msg_req->user_data = (U32)async_data;
        msg_req->callback_ptr = (void*)user_proc;

        if(info.attribute & FS_ATTR_DIR)
            msg_req->flag = FMT_DELETE_FOLDER;
        else
            msg_req->flag = FMT_DELETE_SINGLE;

        msg_req->buffer = NULL;
        msg_req->buffer_size = 0;

        msg_req->filter_count = 0;
        msg_req->filter_array = NULL;

        kal_wstrcpy(msg_req->path, src_path);

        SetProtocolEventHandler(srv_fmgri_async_delete_rsp_hdlr, MSG_ID_FMT_ADV_DELETE_RSP);

        job_id = (U32)fmt_adv_send_message(MSG_ID_FMT_ADV_DELETE_REQ, (local_para_struct*)msg_req, NULL);
        FMGR_ASSERT(job_id);
        srv_fmgri_async_job_insert(job_id);

        fs_ret = job_id;
    }while(0);

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_56BA6784570E42AE805DD015E956E0DF, 
        "[SRV_FMGR] > Async > return: %d", fs_ret);
    return fs_ret;
}

S32 srv_fmgr_async_delete_all(const WCHAR* src_path, const FMGR_FILTER *filter, S32 flag, 
                                mmi_proc_func user_proc, void* user_data)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_delete_req_struct   *msg_req;
    peer_buff_struct            *peer_buff_ptr;
    U16                         len;
    S32                         job_id, fs_ret;

    srv_fmgr_fileinfo_struct    info;

    srv_fmgri_async_userdata_struct *async_data;
    srv_fmgr_notification_adv_action_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_DA97D5C24639449CAE1EDB737D385889, 
        "[SRV_FMGR] > Async > delete all(%d,%x,%x)", flag, user_proc, user_data);

    do {
        if(!src_path || !src_path[0] || !user_proc)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }
        
        if(mmi_wcslen(src_path) > SRV_FMGR_PATH_MAX_LEN)
        {
            fs_ret = FS_PATH_OVER_LEN_ERROR;
            break;
        }

        // TODO: temporary solution when FS not support multi request
        if(srv_fmgri_async_job_count())
        {
            fs_ret = FS_DEVICE_BUSY;
            break;
        }

        fs_ret = srv_fmgr_fs_path_get_fileinfo(src_path, &info);
        if(fs_ret < 0)
            break;

        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL;
        evt.src_filepath = src_path;
        evt.src_fileinfo = info;
        evt.filter = filter;

        if ((fs_ret = srv_fmgri_async_pre_processing(&evt)) < 0)
        {
            break;
        }

        FMGR_BG_AUDIO_SUSPEND;

        async_data = OslMalloc(sizeof(srv_fmgri_async_userdata_struct));
        memset(async_data, 0, sizeof(srv_fmgri_async_userdata_struct));
        async_data->user_data = user_data;
        async_data->src_info = info;
        async_data->filter = *filter;

        msg_req = (fmt_adv_delete_req_struct*) OslConstructDataPtr(sizeof(fmt_adv_delete_req_struct));

        msg_req->user_data = (U32)async_data;
        msg_req->callback_ptr = (void*)user_proc;

        msg_req->flag = FMT_DELETE_ALL;

        msg_req->buffer = NULL;
        msg_req->buffer_size = 0;

        msg_req->filter_count = 0;
        msg_req->filter_array = NULL;

        kal_wstrcpy(msg_req->path, src_path);

        if(filter)
        {
            msg_req->filter_count = srv_fmgri_construct_filter_pattern(filter, NULL, 0);

            if(msg_req->filter_count)
            {
                msg_req->flag = FMT_DELETE_ALL_BY_FILTER;
                
                peer_buff_ptr = construct_peer_buff((U16)(msg_req->filter_count * sizeof(FS_Pattern_Struct)), 0, 0, TD_RESET);
                msg_req->filter_array = (FS_Pattern_Struct*)get_pdu_ptr(peer_buff_ptr, &len);
                srv_fmgri_construct_filter_pattern(filter, msg_req->filter_array, msg_req->filter_count);
            }
        }

        SetProtocolEventHandler(srv_fmgri_async_delete_rsp_hdlr, MSG_ID_FMT_ADV_DELETE_RSP);

        job_id = (U32)fmt_adv_send_message(MSG_ID_FMT_ADV_DELETE_REQ, (local_para_struct*)msg_req, NULL);
        FMGR_ASSERT(job_id);
        srv_fmgri_async_job_insert(job_id);

        fs_ret = job_id;
    } while(0);

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_56BA6784570E42AE805DD015E956E0DF, 
        "[SRV_FMGR] > Async > return: %d", fs_ret);
    return fs_ret;
#else
    return FS_ERROR_RESERVED;
#endif
}


S32 srv_fmgr_async_create_folder(const WCHAR* folder_path, S32 flag, 
                                 mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#if (!defined(__MMI_SLIM_FILE_MANAGER__) || defined(__COSMOS_MMI_PACKAGE__)) 

    fmt_adv_create_folder_req_struct    *msg_req;
    S32                         job_id, fs_ret;

    srv_fmgr_notification_adv_action_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //FMGR_TRACE3(TGL1, TRC_SRV_FMGR_9583BC7D91B84EA18A94BEB525B3F9ED, 
    //    "[SRV_FMGR] > Async > delete(%d,%x,%x)", flag, user_proc, user_data);

    do {
        if(!folder_path || !folder_path[0] || !user_proc)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        fs_ret = srv_fmgri_path_check_folderpath(folder_path);
        if(fs_ret < 0)
            break;

        fs_ret = srv_fmgr_fs_path_exist(folder_path);
        if(fs_ret >= 0) /* already exist */
        {
            fs_ret = FS_FILE_EXISTS;
            break;
        }
        
        // TODO: temporary solution when FS not support multi request
        if(srv_fmgri_async_job_count())
        {
            fs_ret = FS_DEVICE_BUSY;
            break;
        }

        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        evt.action = SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER;
        evt.src_filepath = folder_path;
        evt.src_fileinfo.attribute = FS_ATTR_DIR;
        evt.src_fileinfo.type = FMGR_TYPE_FOLDER;

        if ((fs_ret = srv_fmgri_async_pre_processing(&evt)) < 0)
        {
            break;
        }

        msg_req = (fmt_adv_create_folder_req_struct*) OslConstructDataPtr(sizeof(fmt_adv_create_folder_req_struct));

        msg_req->user_data = (kal_uint32)user_data;
        msg_req->callback_ptr = (void*)user_proc;

        kal_wstrcpy(msg_req->path, folder_path);

        SetProtocolEventHandler(srv_fmgri_async_create_folder_rsp_hdlr, MSG_ID_FMT_ADV_CREATE_FOLDER_RSP);

        job_id = (U32)fmt_adv_send_message(MSG_ID_FMT_ADV_CREATE_FOLDER_REQ, (local_para_struct*)msg_req, NULL);
        FMGR_ASSERT(job_id);
        srv_fmgri_async_job_insert(job_id);

        fs_ret = job_id;
    }while(0);

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_56BA6784570E42AE805DD015E956E0DF, 
        "[SRV_FMGR] > Async > return: %d", fs_ret);
    return fs_ret;
//#else
	//return FS_ERROR_RESERVED;
//#endif

}

S32 srv_fmgr_async_get_folder_size(const WCHAR* folder_path, S32 flag, 
                                   mmi_proc_func user_proc, void* user_data)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_get_folder_size_req_struct *msg_req;
    S32                         job_id, fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //FMGR_TRACE3(TGL1, TRC_SRV_FMGR_9583BC7D91B84EA18A94BEB525B3F9ED, 
    //    "[SRV_FMGR] > Async > delete(%d,%x,%x)", flag, user_proc, user_data);

    do {
        if(!folder_path || !folder_path[0] || !user_proc)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        fs_ret = srv_fmgri_path_check_folderpath(folder_path);
        if(fs_ret < 0)
            break;

        // TODO: temporary solution when FS not support multi request
        if(srv_fmgri_async_job_count())
        {
            fs_ret = FS_DEVICE_BUSY;
            break;
        }

        fs_ret = srv_fmgr_fs_path_exist(folder_path);
        if(fs_ret < 0)
            break;

        msg_req = (fmt_adv_get_folder_size_req_struct*) OslConstructDataPtr(sizeof(fmt_adv_get_folder_size_req_struct));

        msg_req->user_data = (kal_uint32)user_data;
        msg_req->callback_ptr = (void*)user_proc;

        kal_wstrcpy(msg_req->path, folder_path);

        SetProtocolEventHandler(srv_fmgri_async_get_folder_size_rsp_hdlr, MSG_ID_FMT_ADV_GET_FOLDER_SIZE_RSP);
        SetProtocolEventHandler(srv_fmgri_async_get_folder_size_ind_hdlr, MSG_ID_FMT_ADV_GET_FOLDER_SIZE_IND);

        job_id = (U32)fmt_adv_send_message(MSG_ID_FMT_ADV_GET_FOLDER_SIZE_REQ, (local_para_struct*)msg_req, NULL);
        FMGR_ASSERT(job_id);
        srv_fmgri_async_job_insert(job_id);

        fs_ret = job_id;
    }while(0);

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_56BA6784570E42AE805DD015E956E0DF, 
        "[SRV_FMGR] > Async > return: %d", fs_ret);
    return fs_ret;    
#else
    return FS_ERROR_RESERVED;
#endif
}

MMI_BOOL srv_fmgr_async_abort(S32 job_id, MMI_BOOL cancel_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        if(!srv_fmgri_async_job_exist(job_id))
        {
            ret = MMI_FALSE;
            break;
        }

        if(job_id > FMT_ADV_JOB_MAX)
        {
            ret = MMI_FALSE;
            break;
        }

        ret = (MMI_BOOL)fmt_adv_abort_message((U32)job_id, KAL_FALSE, KAL_FALSE);

        if(cancel_event)
        {
            srv_fmgri_async_job_cancel_rsp(job_id);
            ret = MMI_TRUE;
        }
        
    } while(0);

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_1D2CF7771CF04B9895872660EC46C876, 
        "[SRV_FMGR] > Async > abort(%d,%d): %d", job_id, cancel_event, ret);
    return ret;
}

srv_fmgr_async_state_enum srv_fmgr_async_get_state(S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_seq_state_enum state;
    srv_fmgr_async_state_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        if(!srv_fmgri_async_job_exist(job_id))
        {
            ret = SRV_FMGR_ASYNC_STATE_INVALID;
            break;
        }

        if(job_id > FMT_ADV_JOB_MAX)
        {
            ret = SRV_FMGR_ASYNC_STATE_IN_PROGRESS;
            break;
        }

        state = fmt_adv_get_message_state((U32)job_id);
        switch(state)
        {
        case FMT_SEQ_ONGOING:
        case FMT_SEQ_IN_QUEUE:
            ret = SRV_FMGR_ASYNC_STATE_IN_PROGRESS;
            break;

        case FMT_SEQ_ABORTING:
        case FMT_SEQ_DISCARDING:
            ret = SRV_FMGR_ASYNC_STATE_ABORTING;
            break;

        case FMT_SEQ_NOT_EXIST:
        default:
            ret = SRV_FMGR_ASYNC_STATE_DONE;
            break;
        }
    } while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_E7E7C625620F4051A532F7781F182E9B, 
        "[SRV_FMGR] > Async > state(%d): %d", job_id, ret);
    return ret;
}

MMI_BOOL srv_fmgr_async_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_fmgri_async_job_count() ? MMI_TRUE : MMI_FALSE;
}

S32 srv_fmgr_async_format(U8 drv, S32 flag, 
                                mmi_proc_func user_proc, void* user_data)
{
#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_req_strcut *msgReq;
    srv_fmgr_notification_format_event_struct evt;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_20D88A8C38814B5BB3BA5E297F66C944, 
        "[SRV_FMGR] > Async > format(%d,%x,%x)", flag, user_proc, user_data);
    
    do {
        /* check if drv exist */
        if(!srv_fmgr_drv_is_accessible(drv))
        {
            fs_ret = FS_DRIVE_NOT_READY;
            break;
        }

        if(srv_fmgri_async_job_exist(FMGR_JOB_ID_FORMAT))
        {
            fs_ret = FS_DEVICE_BUSY;
            break;
        }
        
        // TODO: temporary solution when FS not support multi request
        if(srv_fmgri_async_job_count())
        {
            fs_ret = FS_DEVICE_BUSY;
            break;
        }

        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT;
        evt.size = sizeof(evt);

        evt.drv_letter = drv;
// TODO: Need to verify!! SLIM SRV 
		//if(fs_ret = srv_fmgri_async_pre_processing(((mmi_event_struct*)&evt) < 0)) // ???? 
		//{
		//	break;
		//}

        evt.state = SRV_FMGR_NOTIFICATION_STATE_QUERY;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.drv_letter);
        if(MMI_RET_ERR == mmi_frm_cb_emit_event((mmi_event_struct*)&evt))
        {
            fs_ret = FS_ACCESS_DENIED;
            break;
        }

        evt.state = SRV_FMGR_NOTIFICATION_STATE_BEFORE;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", evt.evt_id, evt.state, evt.drv_letter);
        mmi_frm_cb_emit_event((mmi_event_struct*)&evt);

        /* suspend audio */    
        FMGR_BG_AUDIO_SUSPEND;

        /* send format request */
        SetProtocolEventHandler(srv_fmgri_async_format_rsp_hdlr, MSG_ID_MMI_FMT_FORMAT_RSP);

        msgReq = OslAllocDataPtr(mmi_fmt_format_req_strcut);

        msgReq->level = FS_FORMAT_HIGH;
        msgReq->drive = drv;
        msgReq->callback = (void*)user_proc;
        msgReq->user_data = (U32)user_data;

        /*
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_FMT;
        Message.oslMsgId = MSG_ID_MMI_FMT_FORMAT_REQ;
        Message.oslDataPtr = (oslParaType*) msgReq;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        */

        mmi_frm_send_ilm(MOD_FMT, MSG_ID_MMI_FMT_FORMAT_REQ, (oslParaType*) msgReq, NULL);
        
        srv_fmgri_async_job_insert(FMGR_JOB_ID_FORMAT);

        fs_ret = FMGR_JOB_ID_FORMAT;
    } while(0);

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_56BA6784570E42AE805DD015E956E0DF, 
        "[SRV_FMGR] > Async > return: %d", fs_ret);
    
    return fs_ret;
#else
	return FS_PARAM_ERROR;
#endif
}

S32 srv_fmgr_async_checkdrive(U8 drv, S32 flag, 
                                mmi_proc_func user_proc, void* user_data)
{
#ifdef __FS_CHECKDRIVE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_check_drive_req_strcut *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check if drv exist */
    if(!srv_fmgr_drv_is_accessible(drv))
        return FS_DRIVE_NOT_READY;

    if(srv_fmgri_async_job_exist(FMGR_JOB_ID_CHKDRV))
        return FS_DEVICE_BUSY;
    
    // TODO: temporary solution when FS not support multi request
    if(srv_fmgri_async_job_count())
        return FS_DEVICE_BUSY;

    /* suspend audio */    
    FMGR_BG_AUDIO_SUSPEND;

    /* send format request */
    SetProtocolEventHandler(srv_fmgri_async_chkdrv_rsp_hdlr, MSG_ID_MMI_FMT_CHECK_DRIVE_RSP);

    msgReq = OslAllocDataPtr(mmi_fmt_check_drive_req_strcut);
    
    msgReq->drive = drv;
    msgReq->callback = (void*)user_proc;
    msgReq->user_data = (U32)user_data;

    /*
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = MSG_ID_MMI_FMT_CHECK_DRIVE_REQ;
    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    */

    mmi_frm_send_ilm(MOD_FMT, MSG_ID_MMI_FMT_CHECK_DRIVE_REQ, (oslParaType*) msgReq, NULL);
    
    srv_fmgri_async_job_insert(FMGR_JOB_ID_CHKDRV);

    return FMGR_JOB_ID_CHKDRV;
#else
    return FS_PARAM_ERROR;
#endif
}


#define LOCAL_FUNCTION

#ifdef FMGR_WORKAROUND_ABORT_COPY
static mmi_ret srv_fmgri_async_job_proc(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        srv_fmgr_async_abort((S32)param->user_data, MMI_FALSE);
    }

    return MMI_RET_OK;
}
#endif

static void srv_fmgri_async_job_insert(S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0;i<MAX_CONCURRENT_JOB;i++)
    {
        if(!g_srv_fmgri_async_ctxt.jobs[i])
        {
            g_srv_fmgri_async_ctxt.jobs[i] = job_id;
            BITMASK_CLEAR(g_srv_fmgri_async_ctxt.jobs_cancel, i);

#ifdef FMGR_WORKAROUND_ABORT_COPY
            mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, srv_fmgri_async_job_proc, (void*)job_id);
#endif
            return;
        }
    }
    FMGR_ASSERT(0);
}

static MMI_BOOL srv_fmgri_async_job_remove(S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(job_id);
    for(i=0;i<MAX_CONCURRENT_JOB;i++)
    {
        if(g_srv_fmgri_async_ctxt.jobs[i] == job_id)
        {
#ifdef FMGR_WORKAROUND_ABORT_COPY
            mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, srv_fmgri_async_job_proc, (void*)job_id);
#endif
            g_srv_fmgri_async_ctxt.jobs[i] = 0;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;

}

static MMI_BOOL srv_fmgri_async_job_exist(S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<MAX_CONCURRENT_JOB;i++)
    {
        if(g_srv_fmgri_async_ctxt.jobs[i] == job_id)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

static U32 srv_fmgri_async_job_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0, count=0;i<MAX_CONCURRENT_JOB;i++)
    {
        if(g_srv_fmgri_async_ctxt.jobs[i])
        {
            count++;
        }
    }
    return count;
}

static MMI_BOOL srv_fmgri_async_job_cancel_rsp(S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<MAX_CONCURRENT_JOB;i++)
    {
        if(g_srv_fmgri_async_ctxt.jobs[i] == job_id)
        {
            BITMASK_SET(g_srv_fmgri_async_ctxt.jobs_cancel, i);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

static MMI_BOOL srv_fmgri_async_job_is_cancel(S32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<MAX_CONCURRENT_JOB;i++)
    {
        if(g_srv_fmgri_async_ctxt.jobs[i] == job_id)
        {
            return (MMI_BOOL)(BITMASK_IS_SET(g_srv_fmgri_async_ctxt.jobs_cancel, (U32)i));
        }
    }
    return MMI_FALSE;
}

static S32 srv_fmgri_async_copy(const WCHAR* src_path, const WCHAR* dest_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data, U32 fs_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_copy_req_struct     *msg_req;
    peer_buff_struct            *peer_buff_ptr;
    U16                         len;
    S32                         job_id, fs_ret;

    srv_fmgr_fileinfo_struct    src_info, dest_info;

    srv_fmgri_async_userdata_struct *async_data;
    srv_fmgr_notification_adv_action_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!src_path || !src_path[0] || !dest_path || !dest_path[0] || !user_proc)
        return FS_PARAM_ERROR;

    // TODO: temporary solution when FS not support multi request
    if(srv_fmgri_async_job_count())
        return FS_DEVICE_BUSY;

    fs_ret = srv_fmgr_fs_path_get_fileinfo(src_path, &src_info);
    if(fs_ret < 0)
        return fs_ret;

    len = mmi_wcslen(dest_path);
    if(len > SRV_FMGR_PATH_MAX_LEN)
        return FS_PATH_OVER_LEN_ERROR;

    if(dest_path[len-1] != '\\')
    {
        /* destination is a file */
        dest_info = src_info;
    }
    else
    {
        /* destination is a path */
        fs_ret = srv_fmgr_fs_path_get_fileinfo(dest_path, &dest_info);
        if(fs_ret < 0)
            return fs_ret;
    }

    do {
        memset(&evt, 0, sizeof(evt));
        evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        evt.size = sizeof(evt);

        if(fs_flag == FS_MOVE_COPY)
            evt.action = SRV_FMGR_NOTIFICATION_ACTION_COPY;
        else
            evt.action = SRV_FMGR_NOTIFICATION_ACTION_MOVE;
        evt.src_filepath = src_path;
        evt.src_fileinfo = src_info;
        evt.dest_filepath = dest_path;
        evt.dest_fileinfo = dest_info;

        if (srv_fmgri_async_pre_processing(&evt) < 0)
        {
            return FS_ACCESS_DENIED;
        }
    } while(0);

    FMGR_BG_AUDIO_SUSPEND;

    async_data = OslMalloc(sizeof(srv_fmgri_async_userdata_struct));
    memset(async_data, 0, sizeof(srv_fmgri_async_userdata_struct));
    async_data->user_data = user_data;
    async_data->src_info = src_info;
    async_data->dest_info = dest_info;
        
    len = mmi_wcslen(src_path);
    msg_req = (fmt_adv_copy_req_struct*) OslConstructDataPtr(sizeof(fmt_adv_copy_req_struct));

    msg_req->user_data = (U32)async_data;
    msg_req->callback_ptr = (void*)user_proc;
    
    msg_req->flag = fs_flag;

    msg_req->buffer = NULL;
    msg_req->buffer_size = 0;

    peer_buff_ptr = construct_peer_buff((kal_uint16)((len+1)*2), 0, 0, TD_RESET);
    msg_req->src_path = (WCHAR*)get_pdu_ptr(peer_buff_ptr, &len);
    kal_wstrcpy(msg_req->src_path, src_path);
    kal_wstrcpy(msg_req->dest_path, dest_path);

    SetProtocolEventHandler(srv_fmgri_async_copy_rsp_hdlr, MSG_ID_FMT_ADV_COPY_RSP);
    
    job_id = (U32)fmt_adv_send_message(MSG_ID_FMT_ADV_COPY_REQ, (local_para_struct*)msg_req, peer_buff_ptr);
    FMGR_ASSERT(job_id);
    srv_fmgri_async_job_insert(job_id);
    return job_id;

}

static void srv_fmgri_async_copy_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_copy_rsp_struct     *msg_rsp;
    //srv_fmgr_async_done_event_struct evt;
    srv_fmgr_notification_adv_action_event_struct notify_evt;

    srv_fmgri_async_userdata_struct *async_data;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (fmt_adv_copy_rsp_struct*)info;

    FMGR_BG_AUDIO_RESUME;

    async_data = (srv_fmgri_async_userdata_struct*)msg_rsp->user_data;
    user_data = async_data->user_data;

    if(msg_rsp->result > 0)
        msg_rsp->result = 0;
    
    do {
        memset(&notify_evt, 0, sizeof(notify_evt));
        notify_evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        notify_evt.size = sizeof(notify_evt);

        if(msg_rsp->flag == FS_MOVE_COPY)
            notify_evt.action = SRV_FMGR_NOTIFICATION_ACTION_COPY;
        else
            notify_evt.action = SRV_FMGR_NOTIFICATION_ACTION_MOVE;
        notify_evt.src_filepath = msg_rsp->src_path;
        notify_evt.src_fileinfo = async_data->src_info;
        notify_evt.dest_filepath = msg_rsp->dest_path;
        notify_evt.dest_fileinfo = async_data->dest_info;
        
        notify_evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        notify_evt.result = msg_rsp->result;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", notify_evt.evt_id, notify_evt.state, notify_evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&notify_evt);
        
    } while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_AD5EC14217064354B8EE2539D8631A63, 
        "[SRV_FMGR] > Async > copy response(%d,%d)", msg_rsp->req_seq, msg_rsp->result);

    OslMfree(async_data);
    async_data = NULL;

 	srv_fmgri_async_evt_emit(EVT_ID_SRV_FMGR_ASYNC_DONE, msg_rsp->req_seq, msg_rsp->result, msg_rsp->callback_ptr, user_data);   
    
}

static void srv_fmgri_async_delete_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_delete_rsp_struct     *msg_rsp;
    //srv_fmgr_async_done_event_struct evt;

    srv_fmgr_notification_adv_action_event_struct notify_evt;
    srv_fmgri_async_userdata_struct *async_data;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (fmt_adv_delete_rsp_struct*)info;

    FMGR_BG_AUDIO_RESUME;

    async_data = (srv_fmgri_async_userdata_struct*)msg_rsp->user_data;
    user_data = async_data->user_data;

    if(msg_rsp->result > 0)
        msg_rsp->result = 0;

    do {
        memset(&notify_evt, 0, sizeof(notify_evt));
        notify_evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        notify_evt.size = sizeof(notify_evt);

        switch(msg_rsp->flag)
        {
        case FMT_DELETE_FOLDER:
        case FMT_DELETE_SINGLE:
            notify_evt.action = SRV_FMGR_NOTIFICATION_ACTION_DELETE;
            break;
        case FMT_DELETE_ALL:
        case FMT_DELETE_ALL_BY_FILTER:
            notify_evt.action = SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL;
            notify_evt.filter = &async_data->filter;
            break;
        }
        notify_evt.src_filepath = msg_rsp->path;
        notify_evt.src_fileinfo = async_data->src_info;

        notify_evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        notify_evt.result = msg_rsp->result;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", notify_evt.evt_id, notify_evt.state, notify_evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&notify_evt);

    } while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_116FEF69E5C34AC3A314C60CB8E697FB, 
        "[SRV_FMGR] > Async > del response(%d,%d)", msg_rsp->req_seq, msg_rsp->result);

    OslMfree(async_data);
    async_data = NULL;

	srv_fmgri_async_evt_emit(EVT_ID_SRV_FMGR_ASYNC_DONE, msg_rsp->req_seq, msg_rsp->result, msg_rsp->callback_ptr, user_data);
   
}

static void srv_fmgri_async_create_folder_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_create_folder_rsp_struct     *msg_rsp;
    //srv_fmgr_async_done_event_struct evt;

    srv_fmgr_notification_adv_action_event_struct notify_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (fmt_adv_create_folder_rsp_struct*)info;

    if(msg_rsp->result > 0)
        msg_rsp->result = 0;

    do {
        memset(&notify_evt, 0, sizeof(notify_evt));
        notify_evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION;
        notify_evt.size = sizeof(notify_evt);

        notify_evt.action = SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER;
        notify_evt.src_filepath = msg_rsp->path;
        notify_evt.src_fileinfo.attribute = FS_ATTR_DIR;
        notify_evt.src_fileinfo.type = FMGR_TYPE_FOLDER;

        notify_evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        notify_evt.result = msg_rsp->result;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", notify_evt.evt_id, notify_evt.state, notify_evt.action);
        mmi_frm_cb_emit_event((mmi_event_struct*)&notify_evt);

    } while(0);

    //FMGR_TRACE2(TGL1, TRC_SRV_FMGR_116FEF69E5C34AC3A314C60CB8E697FB, 
    //    "[SRV_FMGR] > Async > del response(%d,%d)", msg_rsp->req_seq, msg_rsp->result);

	srv_fmgri_async_evt_emit(EVT_ID_SRV_FMGR_ASYNC_DONE, msg_rsp->req_seq, msg_rsp->result, msg_rsp->callback_ptr, (void *)msg_rsp->user_data);

}

#ifndef __MMI_SLIM_FILE_MANAGER__
static void srv_fmgri_async_get_folder_size_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_get_folder_size_rsp_struct *msg_rsp;
    srv_fmgr_async_folder_size_result_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (fmt_adv_get_folder_size_rsp_struct*)info;

    if(msg_rsp->result > 0)
        msg_rsp->result = 0;

    //FMGR_TRACE2(TGL1, TRC_SRV_FMGR_116FEF69E5C34AC3A314C60CB8E697FB, 
    //    "[SRV_FMGR] > Async > del response(%d,%d)", msg_rsp->req_seq, msg_rsp->result);

    if(srv_fmgri_async_job_is_cancel(msg_rsp->req_seq))
    {
        FMGR_ASSERT(srv_fmgri_async_job_remove(msg_rsp->req_seq));
        return;
    }
    FMGR_ASSERT(srv_fmgri_async_job_remove(msg_rsp->req_seq));

    evt.evt_id = EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_RESULT;
    evt.size = sizeof(evt);
    evt.user_data = NULL;

    evt.job_id = msg_rsp->req_seq;
    evt.result = msg_rsp->result;
    evt.folder_size = msg_rsp->size;

    MMI_FRM_SEND_EVENT(&evt, msg_rsp->callback_ptr, msg_rsp->user_data);
}

static void srv_fmgri_async_get_folder_size_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_get_folder_size_ind_struct *msg_rsp;
    srv_fmgr_async_folder_size_progress_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (fmt_adv_get_folder_size_ind_struct*)info;

    //FMGR_TRACE2(TGL1, TRC_SRV_FMGR_116FEF69E5C34AC3A314C60CB8E697FB, 
    //    "[SRV_FMGR] > Async > del response(%d,%d)", msg_rsp->req_seq, msg_rsp->result);

    if(srv_fmgri_async_job_is_cancel(msg_rsp->req_seq))
        return;

    evt.evt_id = EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING;
    evt.size = sizeof(evt);
    evt.user_data = NULL;

    evt.job_id = msg_rsp->req_seq;
    evt.folder_size = msg_rsp->size;

    MMI_FRM_SEND_EVENT(&evt, msg_rsp->callback_ptr, msg_rsp->user_data);
}
#endif
static void srv_fmgri_async_format_rsp_hdlr(void *info)
{
#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_rsp_strcut   *msg_rsp;
    U8 drv;
    //srv_fmgr_async_done_event_struct evt;
    srv_fmgr_notification_format_event_struct notify_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (mmi_fmt_format_rsp_strcut*) info;

    drv = (U8)msg_rsp->data;
    
    FMGR_BG_AUDIO_RESUME;

    if(msg_rsp->result > 0)
        msg_rsp->result = 0;
    
    do {
        memset(&notify_evt, 0, sizeof(notify_evt));
        notify_evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT;
        notify_evt.size = sizeof(notify_evt);

        notify_evt.drv_letter = drv;
        notify_evt.result = msg_rsp->result;

        notify_evt.state = SRV_FMGR_NOTIFICATION_STATE_AFTER;
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
            "[SRV_FMGR] > Notify (%d,%d,%d)", notify_evt.evt_id, notify_evt.state, notify_evt.drv_letter);
        mmi_frm_cb_emit_event((mmi_event_struct*)&notify_evt);
    } while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_29CF2A77D3EE45A3A0A2C95ADCF3F3C4, 
        "[SRV_FMGR] > Async > format response(%d,%d)", FMGR_JOB_ID_FORMAT, msg_rsp->result);

	srv_fmgri_async_evt_emit(EVT_ID_SRV_FMGR_ASYNC_DONE, FMGR_JOB_ID_FORMAT, msg_rsp->result, msg_rsp->callback, (void *)msg_rsp->user_data);
#endif
}

#ifdef __FS_CHECKDRIVE_SUPPORT__
static void srv_fmgri_async_chkdrv_rsp_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_check_drive_rsp_strcut   *msg_rsp;
    U8 drv;
    //srv_fmgr_async_done_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (mmi_fmt_check_drive_rsp_strcut*) info;

    drv = (U8)msg_rsp->data;
    
    FMGR_BG_AUDIO_RESUME;

	srv_fmgri_async_evt_emit(EVT_ID_SRV_FMGR_ASYNC_DONE, FMGR_JOB_ID_CHKDRV, msg_rsp->result, msg_rsp->callback, (void *)msg_rsp->user_data);

}
#endif

static void srv_fmgri_async_evt_emit(U16 evt_id, S32 job_id, S32 result, void* callback, void* user_data)
    {
	srv_fmgr_async_done_event_struct evt;

    if(srv_fmgri_async_job_is_cancel(job_id))
    {
        FMGR_ASSERT(srv_fmgri_async_job_remove(job_id));
        return;
    }
    FMGR_ASSERT(srv_fmgri_async_job_remove(job_id));
	evt.evt_id = evt_id;
    evt.size = sizeof(evt);
    evt.user_data = NULL;

    evt.job_id = job_id;
    evt.result = result;

    mmi_frm_send_event((mmi_event_struct *)(&evt), (mmi_proc_func)(callback), (void *)(user_data));	

}

S32 srv_fmgri_async_pre_processing(srv_fmgr_notification_adv_action_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt->state = SRV_FMGR_NOTIFICATION_STATE_QUERY;
    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
        "[SRV_FMGR] > Notify (%d,%d,%d)", evt->evt_id, evt->state, evt->action);
    if(MMI_RET_ERR == mmi_frm_cb_emit_event((mmi_event_struct*)evt))
    {
        return FS_ACCESS_DENIED;
    }

    evt->state = SRV_FMGR_NOTIFICATION_STATE_BEFORE;
    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_530ED494B9994C82A514EE2F0D0964B2, 
        "[SRV_FMGR] > Notify (%d,%d,%d)", evt->evt_id, evt->state, evt->action);
    mmi_frm_cb_emit_event((mmi_event_struct*)evt);

    return 0;
}
