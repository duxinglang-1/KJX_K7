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
 *  UpgradeSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Upgrade service main implementation
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
 * removed!
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
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "UpgradeSrvGprot.h"
#include "UpgradeSrvUtil.h"

#if defined __MMI_VPP_UPGRADE__

#include "cbm_consts.h"
#include "cbm_api.h"
#include "DtcntSrvGprot.h"
#include "InetSrvGprot.h"
#include "DLAgentSrvGProt.h"
#include "wps_struct.h"
#include "string.h"
#include "stdio.h"
#include "UpgradeSrvGprot.h"
#include "UpgradeSrvUtil.h"
#include "vmenv.h"
#include "vmcert_sdk.h"
#include "vmgettag_sdk.h"
#include "app_str.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "fs_gprot.h"
#include "MMI_inet_app_trc.h"
#include "mmi_rp_srv_upgrade_def.h"
#include "USBSrvGprot.h"

srv_upgrade_contex_struct *g_srv_upgrade_cntx_ptr = NULL;

MMI_BOOL srv_upgrade_check_version(srv_upgrade_req_info_struct *req);

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_init
 * DESCRIPTION
 *  Initialize upgrade service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_upgrade_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    MMI_BOOL ret = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_INIT);

    upgrade_util_init_mem();
    
    g_srv_upgrade_cntx_ptr = (srv_upgrade_contex_struct *) upgrade_util_alloc(sizeof(srv_upgrade_contex_struct));
    memset(g_srv_upgrade_cntx_ptr, 0, sizeof(srv_upgrade_contex_struct));

#if defined(__FS_CARD_SUPPORT__)
    g_srv_upgrade_cntx_ptr->default_drive = SRV_FMGR_CARD_DRV;
#else
    g_srv_upgrade_cntx_ptr->default_drive = SRV_FMGR_PUBLIC_DRV;
#endif

    if (upgrade_util_create_default_folder(g_srv_upgrade_cntx_ptr->default_drive) == MMI_FALSE)
    {
        g_srv_upgrade_cntx_ptr->is_ready = MMI_FALSE;
        return MMI_FALSE;
    }
    
    g_srv_upgrade_cntx_ptr->is_ready = MMI_TRUE;
    g_srv_upgrade_cntx_ptr->downloaded_vpps = upgrade_util_find_downloaded_vpps(g_srv_upgrade_cntx_ptr->default_drive);
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_replace_status
 * DESCRIPTION
 *  Replace vpp check status
 * PARAMETERS
 *  req                  [IN]    request pointer
 *  old_status           [IN]    original status
 *  new_status           [IN]    new status
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_replace_status(srv_upgrade_req_info_struct *req, srv_upgrage_status_enum old_status, srv_upgrage_status_enum new_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_vpp_info_struct *temp = req->vpp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp)
    {
        if (temp->status == old_status || old_status == SRV_UPGRADE_STATUS_ALL)
        {
            temp->status = new_status;
        }
        temp = temp->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_replace_state
 * DESCRIPTION
 *  Replace all requests' state
 * PARAMETERS
 *  old_state                  [IN]    old state
 *  new_state                  [IN]    new state
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_replace_state(srv_upgrade_reqest_state_enum old_state, srv_upgrade_reqest_state_enum new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_req_info_struct *temp = g_srv_upgrade_cntx_ptr->requests;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp)
    {
        if (temp->state == old_state)
        {
            if (temp->state == SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION)
            {
                // free download info
                upgrade_util_free(temp->download_info);
                temp->download_info = NULL;
            }
            temp->state = new_state;
        }
        temp = temp->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_find_vpp_info_by_status
 * DESCRIPTION
 *  Find vpp information by its status
 * PARAMETERS
 *  req                  [IN]    request pointer
 *  status               [IN]    target status
 * RETURNS
 *  First vpp info pointer found
 *****************************************************************************/
srv_upgrade_vpp_info_struct *srv_upgrade_find_vpp_info_by_status(srv_upgrade_req_info_struct *req, srv_upgrage_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_vpp_info_struct *vpp_info = req->vpp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(vpp_info)
    {
        if (vpp_info->status == status)
        {
            break;
        }
        vpp_info = vpp_info->next;
    }

    return vpp_info;
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_find_first_req_by_state
 * DESCRIPTION
 *  Find request by its state
 * PARAMETERS
 *  state                [IN]    target state
 * RETURNS
 *  First request found
 *****************************************************************************/
srv_upgrade_req_info_struct *srv_upgrade_find_first_req_by_state(srv_upgrade_reqest_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_req_info_struct *temp = g_srv_upgrade_cntx_ptr->requests;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp)
    {
        if (temp->state == state)
        {
            break;
        }
        temp = temp->next;
    }

    return temp;
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_find_req_by_originator
 * DESCRIPTION
 *  Find request by its originator
 * PARAMETERS
 *  originator           [IN]    originator of the request
 * RETURNS
 * Request found 
 *****************************************************************************/
srv_upgrade_req_info_struct *srv_upgrade_find_req_by_originator(srv_upgrage_originator_enum originator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_req_info_struct *temp = g_srv_upgrade_cntx_ptr->requests;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp)
    {
        if (temp->originator == originator)
        {
            break;
        }
        temp = temp->next;
    }

    return temp;
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_remove_req
 * DESCRIPTION
 *  Remove request from list
 * PARAMETERS
 *  req                  [IN]    reqeust pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_remove_req(srv_upgrade_req_info_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_req_info_struct *temp = g_srv_upgrade_cntx_ptr->requests, *next = NULL, *prev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_upgrade_cntx_ptr->requests == req)
    {
        g_srv_upgrade_cntx_ptr->requests = req->next;
    }
    else
    {
        while(temp)
        {
            if (temp == req)
            {
                prev->next = req->next;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // free request
    upgrade_util_free_req_info(req);
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_notify_result
 * DESCRIPTION
 *  Call app's callback function to notify finished
 * PARAMETERS
 *  req                  [IN]    request pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_notify_result(srv_upgrade_req_info_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 i = 0;
    srv_upgrade_result_struct *results = NULL, *temp = NULL;
    srv_upgrade_vpp_info_struct *vpps = req->vpp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < req->count; i ++)
    {
        temp = (srv_upgrade_result_struct *) upgrade_util_alloc(sizeof(srv_upgrade_result_struct));
        memset(temp, 0, sizeof(srv_upgrade_result_struct));

        temp->provider = vpps->provider;
        temp->status = vpps->status;
        if (vpps->status == SRV_UPGRADE_STATUS_DOWNLOADED)
        {
            // check if file exists again
            if (FS_GetAttributes(vpps->path) > 0)
            {
                temp->path = (WCHAR *) upgrade_util_alloc(app_ucs2_strlen((const kal_int8 *) vpps->path) * 2 + 1);
                ASSERT(temp->path);
                if (temp->path == NULL)
                {
                    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_ALLOC_MEM, __FILE__, __LINE__);
                    vpps->status = SRV_UPGRADE_STATUS_FAILED;
                }
                else
                {
                    memset(temp->path, 0, app_ucs2_strlen((const kal_int8 *) vpps->path) * 2 + 1);
                    app_ucs2_strcpy((kal_int8 *) temp->path, (const kal_int8 *) vpps->path);
                }
            }
            else
            {
                vpps->status = SRV_UPGRADE_STATUS_FAILED;
            }
        }

        if (results == NULL)
        {
            results = temp;
        }
        else
        {
            temp->next = results;
            results = temp;
        }
		vpps = vpps->next;
    }

    req->cb(req->originator, results);

    upgrade_util_free_results(results);
    srv_upgrade_remove_req(req);
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_post_notify_result
 * DESCRIPTION
 *  Post event to notify result in async way
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_post_notify_result()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_srv_upgrade_cntx_ptr->notify_result_sent == MMI_FALSE)
    {
        srv_upgrade_evt_notify_result_ind_struct ind;		
        
        MMI_FRM_INIT_EVENT(&ind, EVT_ID_SRV_UPGRADE_NOTIFY_RESULT_IND);
        MMI_FRM_CB_EMIT_POST_EVENT(&ind);
        
        g_srv_upgrade_cntx_ptr->notify_result_sent = MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_da_progress_callback
 * DESCRIPTION
 *  Download agent's progree callback
 * PARAMETERS
 *  report_struct        [IN]    report of download progress
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_da_progress_callback(srv_da_download_progress_struct *report_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_vpp_info_struct *downloading = srv_upgrade_find_vpp_info_by_status(g_srv_upgrade_cntx_ptr->downloading_req , SRV_UPGRADE_STATUS_DOWNLOADING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_DA_PROGRESS_CALLBACK, downloading->app_id, report_struct->status, report_struct->cause);
    
    if (report_struct->status == WPS_DL_STATUS_ABORT)
    {
        // failed
//        if (report_struct->cause == WPS_ERROR_REQ_ABORT)
  //      {
            srv_upgrade_evt_download_app_done_ind_struct ind;

            downloading->status = SRV_UPGRADE_STATUS_FAILED;

            MMI_FRM_INIT_EVENT(&ind, EVT_ID_SRV_UPGRADE_DOWNLOAD_APP_DONE_IND);
            MMI_FRM_CB_EMIT_POST_EVENT(&ind);
    //    }
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_da_setting_callback
 * DESCRIPTION
 *  Download agent's setting callback
 * PARAMETERS
 *  ...
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_da_setting_callback(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, U32 filesize, S8  *url, S8  *mime_type_string, U32 content_len, S8  *content, srv_da_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_da_dispatch_hdlr
 * DESCRIPTION
 *  Downlaod agent's dispatch callback
 * PARAMETERS
 *  src                  [IN]    source module
 *  dst                  [IN]    distination module
 *  msg_id               [IN]    message id
 *  *local_param_ptr     [IN]    local parameter
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_da_dispatch_hdlr(S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, U16 *filepath, S8  *url, S8  *mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_evt_download_app_done_ind_struct ind;
    srv_upgrade_vpp_info_struct *downloading = srv_upgrade_find_vpp_info_by_status(g_srv_upgrade_cntx_ptr->downloading_req , SRV_UPGRADE_STATUS_DOWNLOADING);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_DA_DISPATCH_CALLBACK, downloading->app_id, filepath);

    if (downloading->path)
    {
        upgrade_util_free(downloading->path);
    }
    
    downloading->path = (WCHAR *) upgrade_util_alloc((app_ucs2_strlen((const kal_int8 *) filepath) + 1) * sizeof(U16));
    if (downloading->path)
    {
        memset(downloading->path, 0, (app_ucs2_strlen((const kal_int8 *) filepath) + 1) * sizeof(U16));
        app_ucs2_strcpy((kal_int8 *) downloading->path, (const kal_int8 *) filepath);
    }
    else
    {
        downloading->status = SRV_UPGRADE_STATUS_FAILED;
        MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_ALLOC_MEM, __FILE__, __LINE__);
    }
    downloading->status = SRV_UPGRADE_STATUS_DOWNLOADED;

    MMI_FRM_INIT_EVENT(&ind, EVT_ID_SRV_UPGRADE_DOWNLOAD_APP_DONE_IND);
    MMI_FRM_CB_EMIT_POST_EVENT(&ind);
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_process_download_request
 * DESCRIPTION
 *  Process download request
 * PARAMETERS
 *  req                  [IN]    request pointer
 * RETURNS
 *  MMI_TRUE if a download request is processing
 *****************************************************************************/
MMI_BOOL srv_upgrade_process_download_request(srv_upgrade_req_info_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_vpp_info_struct *first_download = srv_upgrade_find_vpp_info_by_status(req, SRV_UPGRADE_STATUS_HAS_NEW_VERSION);
    WCHAR *name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (first_download)
    {
        memset(g_srv_upgrade_cntx_ptr->da_info->filepath, 0, SRV_UPGRADE_MAX_PATH_LEN);
        memset(g_srv_upgrade_cntx_ptr->da_info->url, 0, SRV_UPGRADE_MAX_PATH_LEN);

        app_asc_str_to_ucs2_str((kal_int8 *) g_srv_upgrade_cntx_ptr->da_info->url, (kal_int8 *) first_download->download_url);
        //memcpy(g_srv_upgrade_cntx_ptr->da_info->url, first_download->download_url, app_ucs2_strlen(first_download->download_url));
        name = upgrade_util_get_filename(g_srv_upgrade_cntx_ptr->da_info->url);
        kal_wsprintf(g_srv_upgrade_cntx_ptr->da_info->filepath, "%c:\\%w\\%w", g_srv_upgrade_cntx_ptr->default_drive, DEFAULT_FOLDER, name);

        first_download->status = SRV_UPGRADE_STATUS_DOWNLOADING;
        req->da_hdlr = srv_da_start_http_download(g_srv_upgrade_cntx_ptr->da_info);

        MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_PROCESS_DOWNLOAD_REQUEST, req->originator, first_download->app_id, req->da_hdlr);
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

/******************************************************************************
 * FUNCTION
 *    srv_upgrade_download
 * DESCRIPTION
 *    API for Upgrade APP to notify user agree to download new version
 * PARAMETERS
 *    originator  [IN]    source of the request
 * RETURNS
 *    void
 ******************************************************************************/
void srv_upgrade_download(srv_upgrage_originator_enum originator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_req_info_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_CONFRIM_DOWNLOAD, originator);

    if (originator == SRV_UPGRADE_ORIGINATOR_ALL)
    {
        req = srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION);
        srv_upgrade_replace_state(SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION, SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD);
    }
    else
    {
        req = srv_upgrade_find_req_by_originator(originator);
        ASSERT(req && req->state == SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION);
        req->state = SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD;
        // free download info
        upgrade_util_free(req->download_info);
        req->download_info = NULL;
    }

    if (g_srv_upgrade_cntx_ptr->downloading_req == NULL)
    {
        // check if downloading first        
        if (g_srv_upgrade_cntx_ptr->da_info == NULL && g_srv_upgrade_cntx_ptr->is_ready == MMI_TRUE)
        {
            srv_da_start_download_struct *download = (srv_da_start_download_struct *) upgrade_util_alloc(sizeof(srv_da_start_download_struct));

            if (download)
            {
                memset(download, 0, sizeof(srv_da_start_download_struct));
                download->show_confirm = MMI_FALSE;
                download->filepath = (WCHAR *) upgrade_util_alloc(SRV_UPGRADE_MAX_PATH_LEN * sizeof(U16));
                download->url = (WCHAR *) upgrade_util_alloc(SRV_UPGRADE_MAX_PATH_LEN * sizeof(U16));
                download->dl_progress = srv_upgrade_da_progress_callback;
                download->dispatch_callback = srv_upgrade_da_dispatch_hdlr;
                download->setting_hdlr = srv_da_bypass_setting;
                download->acc_id = g_srv_upgrade_cntx_ptr->cbm_account_id;

                if(download->url == NULL || download->filepath == NULL)
                {
                    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_ALLOC_MEM, __FILE__, __LINE__);
                    upgrade_util_free_da_info(download);
                    download = NULL;
                }
                else
                {
                    g_srv_upgrade_cntx_ptr->da_info = download;
                }
            }
        }
        
        if (g_srv_upgrade_cntx_ptr->da_info && g_srv_upgrade_cntx_ptr->is_ready == MMI_TRUE)
        {
            ASSERT(srv_upgrade_process_download_request(req) == MMI_TRUE);
            req->state = SRV_UPGRADE_REQUEST_STATE_DOWNLOADING;
            g_srv_upgrade_cntx_ptr->downloading_req = req;
        }
        else
        {
            req = srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD);

            while(req)
            {
                if (req->state == SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD)
                {
                    srv_upgrade_replace_status(req, SRV_UPGRADE_STATUS_HAS_NEW_VERSION, SRV_UPGRADE_STATUS_FAILED);
                    req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;

                }
                req = req->next;   
            }

            srv_upgrade_post_notify_result();
            MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_ALLOC_MEM, __FILE__, __LINE__);
        }
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_ALREADY_DOWNLOADING_OTHER_REQUEST);
    }
}

/******************************************************************************
 * FUNCTION
 *    srv_upgrade_cancel
 * DESCRIPTION
 *    API for Upgrade APP to notify user do not want to download new version
 * PARAMETERS
 *    originator  [IN]    source of the request
 * RETURNS
 *    void
 ******************************************************************************/
void srv_upgrade_cancel(srv_upgrage_originator_enum originator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_req_info_struct *req = NULL, *temp = NULL;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_REJECT_DOWNLOAD, originator);
    
    if (originator == SRV_UPGRADE_ORIGINATOR_ALL)
    {
        req = srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION);

        temp = req;
        while(temp)
        {
            if (temp->state == SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION)
            {
                srv_upgrade_replace_status(temp, SRV_UPGRADE_STATUS_HAS_NEW_VERSION, SRV_UPGRADE_STATUS_CANCELLED);
                temp->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;

            }
            temp = temp->next;   
        }
    }
    else
    {
        req = srv_upgrade_find_req_by_originator(originator);
        ASSERT(req && req->state == SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION);
        req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;
        srv_upgrade_replace_status(req, SRV_UPGRADE_STATUS_HAS_NEW_VERSION, SRV_UPGRADE_STATUS_CANCELLED);
        // free download info
        upgrade_util_free(req->download_info);
        req->download_info = NULL;
    } 

    // notify result
    srv_upgrade_post_notify_result();
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_event_hdlr
 * DESCRIPTION
 *  for sns task to send message
 * PARAMETERS
 *  param                [IN]    event pointer
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_upgrade_event_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            // memory card plugged out
            if (g_srv_upgrade_cntx_ptr && g_srv_upgrade_cntx_ptr->default_drive == SRV_FMGR_CARD_DRV)
            {
                g_srv_upgrade_cntx_ptr->is_ready = MMI_FALSE;
                upgrade_util_remove_vpp_info_list(g_srv_upgrade_cntx_ptr->downloaded_vpps);
                g_srv_upgrade_cntx_ptr->downloaded_vpps = NULL;
            }          
            break;
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
            // memory card plugged in
            if (g_srv_upgrade_cntx_ptr && g_srv_upgrade_cntx_ptr->default_drive == SRV_FMGR_CARD_DRV)
            {
                g_srv_upgrade_cntx_ptr->is_ready = upgrade_util_create_default_folder(g_srv_upgrade_cntx_ptr->default_drive);
                if (g_srv_upgrade_cntx_ptr->is_ready == MMI_TRUE)
                {
                    g_srv_upgrade_cntx_ptr->downloaded_vpps = upgrade_util_find_downloaded_vpps(g_srv_upgrade_cntx_ptr->default_drive);
                }
            }         
            break;
#ifdef __MMI_USB_SUPPORT__                
        case EVT_ID_USB_EXIT_MS_MODE:
            // exit ms mode
            if (g_srv_upgrade_cntx_ptr)
            {
                g_srv_upgrade_cntx_ptr->is_ready = upgrade_util_create_default_folder(g_srv_upgrade_cntx_ptr->default_drive);
                if (g_srv_upgrade_cntx_ptr->is_ready == MMI_TRUE)
                {
                    g_srv_upgrade_cntx_ptr->downloaded_vpps = upgrade_util_find_downloaded_vpps(g_srv_upgrade_cntx_ptr->default_drive);
                }
            }
            break;
        case EVT_ID_USB_ENTER_MS_MODE:
            // enter ms mode set ready = false
            if (g_srv_upgrade_cntx_ptr)
            {
                g_srv_upgrade_cntx_ptr->is_ready = MMI_FALSE;
                upgrade_util_remove_vpp_info_list(g_srv_upgrade_cntx_ptr->downloaded_vpps);
                g_srv_upgrade_cntx_ptr->downloaded_vpps = NULL;
            }
            break;
#endif            
        case EVT_ID_SRV_UPGRADE_CHECK_VERSION_DONE_IND:
        {
            srv_upgrade_req_info_struct *req = g_srv_upgrade_cntx_ptr->checking_req, *temp = NULL;
            srv_upgrade_vpp_info_struct *vpp = req->checking_vpp;

            if(vpp->next == NULL || srv_upgrade_check_version(req) == MMI_FALSE)
            {
                req->checking_vpp = NULL;
                g_srv_upgrade_cntx_ptr->checking_req = NULL;

                if (req->download_count > 0)
                {
                    if (g_srv_upgrade_cntx_ptr->is_ready == MMI_TRUE)
                    {
                        // post event
                        srv_upgrade_evt_download_req_struct evt;
                        srv_upgrade_download_info_struct *info = NULL;
                        srv_upgrade_vpp_info_struct *temp = req->vpp_info, *head = NULL;

                        info = (srv_upgrade_download_info_struct *) upgrade_util_alloc(sizeof(srv_upgrade_download_info_struct));

                        if (info)
                        {
                            memset(info, 0, sizeof(srv_upgrade_download_info_struct));
                            req->state = SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION;

                            info->count = req->download_count;
                            info->originator = req->originator;
                            info->vpp_info = req->vpp_info;

                            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UPGRADE_DOWNLOAD_REQ);
                            evt.info = info;
                            
                            MMI_FRM_CB_EMIT_POST_EVENT(&evt);

                            ASSERT(req->download_info == NULL);
                            req->download_info = info;
                            MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_POST_DOWNLOAD_REQ, req->originator, req->download_count);
                        }
                        else
                        {
                            // reset vpp status to failed
                            MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_ALLOC_MEM, __FILE__, __LINE__);
                            srv_upgrade_replace_status(req, SRV_UPGRADE_STATUS_ALL, SRV_UPGRADE_STATUS_FAILED);
                            req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;
                            srv_upgrade_post_notify_result();
                        }
                    }
                    else
                    {
                        srv_upgrade_replace_status(req, SRV_UPGRADE_STATUS_ALL, SRV_UPGRADE_STATUS_FAILED);
                        req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;
                        srv_upgrade_post_notify_result();
                    }
                }
                else
                {
                    // call app's callback
                    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_NO_NEW_VERSION);
                    req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;
                    srv_upgrade_post_notify_result();
                }

                req->checking_vpp = NULL;
                temp = req->next;

                while(temp != NULL && srv_upgrade_check_version(temp) == MMI_FALSE)
                {
                    temp = temp->next;
                }

                if (temp == NULL && srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_CHECK_NEW_VERSION) == NULL)
                {
                    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_CLOSE_SESSION);
                    srv_inet_session_close(g_srv_upgrade_cntx_ptr->session);
                    g_srv_upgrade_cntx_ptr->session = 0;
                }
            }
            
            break;
        }
        case EVT_ID_SRV_UPGRADE_DOWNLOAD_APP_DONE_IND:
        {
            srv_upgrade_req_info_struct *req = g_srv_upgrade_cntx_ptr->downloading_req, *next = NULL;

            if (g_srv_upgrade_cntx_ptr->is_ready == MMI_TRUE)
            {
                if (srv_upgrade_process_download_request(req) == MMI_FALSE)
                {
                    req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;
                    srv_upgrade_post_notify_result(req);
                    g_srv_upgrade_cntx_ptr->downloading_req = NULL;

                    next = srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD);
                    if (next)
                    {
                        ASSERT(srv_upgrade_process_download_request(next) == MMI_TRUE);
                        next->state = SRV_UPGRADE_REQUEST_STATE_DOWNLOADING;
                        g_srv_upgrade_cntx_ptr->downloading_req = next;
                    }
                    else
                    {
                        g_srv_upgrade_cntx_ptr->downloading_req = NULL;
                        upgrade_util_free_da_info(g_srv_upgrade_cntx_ptr->da_info);
                        g_srv_upgrade_cntx_ptr->da_info = NULL;
                    }
                }
            }
            else
            {
                // stop vpp download
                req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;
                srv_upgrade_replace_status(req, SRV_UPGRADE_STATUS_HAS_NEW_VERSION, SRV_UPGRADE_STATUS_FAILED);
                g_srv_upgrade_cntx_ptr->downloading_req = NULL;

                req = srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD);

                while(req)
                {
                    if (req->state == SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD)
                    {
                        srv_upgrade_replace_status(req, SRV_UPGRADE_STATUS_HAS_NEW_VERSION, SRV_UPGRADE_STATUS_FAILED);
                        req->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;

                    }
                    req = req->next;   
                }
                
                srv_upgrade_post_notify_result();
            }
            break;
        }
        case EVT_ID_SRV_UPGRADE_NOTIFY_RESULT_IND:
        {
            srv_upgrade_req_info_struct *req = srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_FINISHED);
            
            g_srv_upgrade_cntx_ptr->notify_result_sent = MMI_FALSE;

            while (req)
            {
                srv_upgrade_notify_result(req);
                req = srv_upgrade_find_first_req_by_state(SRV_UPGRADE_REQUEST_STATE_FINISHED);
            }
            break;
        }
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_inet_alloc
 * DESCRIPTION
 *  Inet service's memory allocate function
 * PARAMETERS
 *  size                 [IN]    allocate size
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_upgrade_inet_alloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    return upgrade_util_alloc(size);
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_inet_free
 * DESCRIPTION
 *  Inet service's memory free function
 * PARAMETERS
 *  ptr                  [IN]    memory pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_inet_free(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    upgrade_util_free(ptr);
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_inet_req_callback
 * DESCRIPTION
 *  for sns task to send message
 * PARAMETERS
 *  req_handle           [IN]    request handle
 *  evt                  [IN]    event data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_inet_req_callback(U32 req_handle, srv_inet_event_notify_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_evt_check_version_done_ind_struct ind;
	srv_upgrade_vpp_info_struct *temp = g_srv_upgrade_cntx_ptr->checking_req->checking_vpp;
    srv_inet_http_rsp_struct* rsp = (srv_inet_http_rsp_struct *) evt->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_srv_upgrade_cntx_ptr->checking_req->http_req_hdlr > 0);

    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_INET_CALLBACK, req_handle, evt->event_id, rsp->result, rsp->status, rsp->response_segment);

    if (g_srv_upgrade_cntx_ptr->checking_req->http_req_hdlr != req_handle)
    {
        return;
    }
    
    // do not send another request in this callback
    switch (evt->event_id)
    {
        case SRV_INET_EVENT_RESONSE_RECEIVED:
        {
            if (rsp->result == SRV_INET_OK)
            {
                if (rsp->status == 200)
				{					
                    if (rsp->more > 0 || (rsp->more == 0 && rsp->response_segment && app_strnicmp((kal_char *) rsp->response_segment, (kal_char *) "http", 4) != 0))
                    {
                        if (temp)
                        {
                            temp->status = SRV_UPGRADE_STATUS_FAILED;
                        }
                        
                        if (rsp->more)
                        {
                            srv_inet_http_req_cancel_req(g_srv_upgrade_cntx_ptr->session, g_srv_upgrade_cntx_ptr->checking_req->http_req_hdlr);
                            srv_inet_session_close(g_srv_upgrade_cntx_ptr->session);
                            g_srv_upgrade_cntx_ptr->session = 0;
                        }
                    }
                    else
                    {
                        if (rsp->response_segment_len > 0)
                        {
                            // has new version
                            temp->download_url = (CHAR *) upgrade_util_alloc(rsp->response_segment_len + 1);
                            if (temp->download_url)
                            {
                                memset(temp->download_url, 0, rsp->response_segment_len + 1);
                                strcpy(temp->download_url, rsp->response_segment);
                                temp->status = SRV_UPGRADE_STATUS_HAS_NEW_VERSION;
                                g_srv_upgrade_cntx_ptr->checking_req->download_count++;
                            }                           
                        }
                    }
                }
                else if (rsp->status == 404)
				{
                    // do not have new version
                    temp->status = SRV_UPGRADE_STATUS_NO_UPGRADE;
                }
                else
                {
                    // failed
					temp->status = SRV_UPGRADE_STATUS_FAILED;
                }
            }
            else
            {
                // failed
                temp->status = SRV_UPGRADE_STATUS_FAILED;
            }
        }
            break;
        case SRV_INET_EVENT_ABORTED:
            // Inet service will close the session itself
            g_srv_upgrade_cntx_ptr->session = 0;
            temp->status = SRV_UPGRADE_STATUS_FAILED;
            break;
        default:
            ASSERT(0);
            break;
    }

    MMI_FRM_INIT_EVENT(&ind, EVT_ID_SRV_UPGRADE_CHECK_VERSION_DONE_IND);
    MMI_FRM_CB_EMIT_POST_EVENT(&ind);
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_get_default_data_account
 * DESCRIPTION
 *  Get default data account of upgrade service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_get_default_data_account()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    cbm_app_info_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info.app_type = DTCNT_APPTYPE_SKIP_CSD | DTCNT_APPTYPE_NO_PX;
    if (cbm_register_app_id_with_app_info(&info, (kal_uint8 *) &g_srv_upgrade_cntx_ptr->cbm_app_id) == CBM_OK)
    {
        srv_dtcnt_sim_type_enum sim_type;
        cbm_sim_id_enum sim_id = CBM_SIM_ID_SIM1;

        srv_dtcnt_get_sim_preference(&sim_type);

        if (sim_type > SRV_DTCNT_SIM_TYPE_NONE && sim_type < SRV_DTCNT_SIM_TYPE_TOTAL)
        {
            sim_id = (sim_type - SRV_DTCNT_SIM_TYPE_1) + CBM_SIM_ID_SIM1;
        }
        
        g_srv_upgrade_cntx_ptr->cbm_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, sim_id, g_srv_upgrade_cntx_ptr->cbm_app_id, KAL_FALSE);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_GET_DATA_ACCOUNT);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_check_version
 * DESCRIPTION
 *  Check if there is a new version from server
 * PARAMETERS
 *  req                  [IN]    request pointer
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_upgrade_check_version(srv_upgrade_req_info_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 ret = 0;
    MMI_BOOL processing = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(g_srv_upgrade_cntx_ptr->checking_req == NULL || g_srv_upgrade_cntx_ptr->checking_req == req);

    if (g_srv_upgrade_cntx_ptr->session == 0)
    {
        g_srv_upgrade_cntx_ptr->session = srv_inet_session_new(srv_upgrade_inet_alloc, srv_upgrade_inet_free);
		srv_upgrade_get_default_data_account();
        srv_inet_session_set_config_param(g_srv_upgrade_cntx_ptr->session, NULL, g_srv_upgrade_cntx_ptr->cbm_account_id, 90 * 1000);
    }
    if(g_srv_upgrade_cntx_ptr->session <= 0)
    {
        // failed
        MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_INIT_SESSION);
    }
    else
    {
        srv_upgrade_vpp_info_struct *temp = req->vpp_info;

        while(temp)
        {
            if (temp->status == SRV_UPGRADE_STATUS_WAITING_TO_CHECK)
            {
                CHAR *url =upgrade_util_prepare_url(temp);

                if(url)
                {
                    req->http_req_hdlr = srv_inet_http_req_new(g_srv_upgrade_cntx_ptr->session, SRV_INET_HTTP_METHOD_GET, SRV_INET_HTTP_OPTION_NO_CACHE, url);
                    if (req->http_req_hdlr > 0)
                    {
                        ret = srv_inet_http_send_request(g_srv_upgrade_cntx_ptr->session, 
									   req->http_req_hdlr,
									   "Content-Type: application/x-www-form-urlencoded;charset=UTF-8",
									   NULL,
									   0,
                                       NULL,
									   srv_upgrade_inet_req_callback);

                        upgrade_util_free(url);
                        req->checking_vpp= temp;
                        temp->status = SRV_UPGRADE_STATUS_CHECKING;
                        processing = MMI_TRUE;
                        break;
                    }
                    else
                    {
                        // log error
                        MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FAILED_TO_NEW_HTTP_REQ);
                        temp->status = SRV_UPGRADE_STATUS_FAILED;
                    }
                    
                    upgrade_util_free(url);
                }
                else
                {
                    if (temp->status != SRV_UPGRADE_STATUS_NOT_SUPPORT)
                    {
                        temp->status = SRV_UPGRADE_STATUS_FAILED;
                    }
                }
            }
            temp = temp->next;
        }
        if (temp)
        {
            MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_CURRENT_CHECKING, temp->app_id);
            g_srv_upgrade_cntx_ptr->checking_req = req;
            req->state = SRV_UPGRADE_REQUEST_STATE_CHECK_NEW_VERSION;
        }
    }
    return processing;
}

/*****************************************************************************
 * FUNCTION
 *  rv_upgrade_check_new_verson_exists
 * DESCRIPTION
 *  Check if there is a downloaded new version
 * PARAMETERS
 *  vpp_info             [IN]    vpp list
 * RETURNS
 *  void
 *****************************************************************************/
void srv_upgrade_check_new_verson_exists(srv_upgrade_vpp_info_struct *vpp_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_vpp_info_struct *temp = vpp_info, *downloaded = g_srv_upgrade_cntx_ptr->downloaded_vpps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (downloaded == NULL)
    {
        return;
    }

    while (temp)
    {
		downloaded = g_srv_upgrade_cntx_ptr->downloaded_vpps;
        while(downloaded)
        {
            if (temp->app_id == downloaded->app_id && temp->version < downloaded->version)
            {
                MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_FOUND_DONWNLOADED_VERSION, downloaded->app_id, downloaded->version, downloaded->path);
                
                temp->path = (WCHAR *) upgrade_util_alloc(app_ucs2_strlen((const kal_int8 *) downloaded->path) * 2 + 1);
                if (temp->path)
                {
                    app_ucs2_strcpy((kal_int8 *) temp->path, (const kal_int8 *) downloaded->path);
                    temp->status = SRV_UPGRADE_STATUS_DOWNLOADED;
                }
                else
                {
                    temp->status = SRV_UPGRADE_STATUS_FAILED;
                }
                break;
            }
            downloaded = downloaded->next;
        }
        temp = temp->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_check_update
 * DESCRIPTION
 *  Check if there is a new version for a list of vpp
 * PARAMETERS
 *  vpp_info             [IN]    vpp information list
 *  count                [IN]    vpp number
 *  originator           [IN]    app enum
 *  cb                   [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_upgrade_check_update(srv_upgrade_req_struct *vpp_info, U8 count, srv_upgrage_originator_enum originator, srv_vpp_upgrade_result_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_req_info_struct *info = NULL;
    srv_upgrade_req_struct *vpp = vpp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_CHECK_UPDATE, originator, count);

    if (upgrade_util_check_compile_option(originator) == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    
    if (g_srv_upgrade_cntx_ptr == NULL)
    {
        if (srv_upgrade_init() == MMI_FALSE)
        {
            return MMI_FALSE;
        }
    }

    if (g_srv_upgrade_cntx_ptr->is_ready == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    ASSERT(vpp_info != NULL);

    info = (srv_upgrade_req_info_struct *) upgrade_util_alloc(sizeof(srv_upgrade_req_info_struct));
    memset(info, 0, sizeof(srv_upgrade_req_info_struct));

    info->originator = originator;
    info->cb = cb;
    info->count = count;

    while(vpp)
    {
        U32 path_len = 0, ver = 0;
        S32 buf_size = 4;
            
        srv_upgrade_vpp_info_struct *temp = (srv_upgrade_vpp_info_struct *) upgrade_util_alloc(sizeof(srv_upgrade_vpp_info_struct));
        memset(temp, 0, sizeof(srv_upgrade_vpp_info_struct));

        temp->provider = vpp->provider;
        
        ASSERT(vpp->path);

        path_len = app_ucs2_strlen((const kal_int8 *) vpp->path);
        temp->path = (WCHAR *) upgrade_util_alloc(2 * (path_len) + 1);
        memset(temp->path, 0, 2 * path_len + 1);
        app_ucs2_strcpy((kal_int8 *) temp->path, (const kal_int8 *) vpp->path);

        if (GET_TAG_TRUE != vm_get_vm_tag((short *) temp->path, VM_CE_INFO_VER, &temp->version, &buf_size))
        {
            temp->status = SRV_UPGRADE_STATUS_NOT_SUPPORT;
        }
        else
        {            
            if (GET_TAG_TRUE != vm_get_vm_tag((short *) temp->path, VM_CE_INFO_APP_ID, &temp->app_id, &buf_size))
            {
                temp->status = SRV_UPGRADE_STATUS_NOT_SUPPORT;
            }         
        }

        MMI_TRACE(MMI_INET_TRC_G7_UPGRADE, SRV_UPGRADE_CHECK_VPP, vpp->provider, temp->app_id, temp->version, temp->status, temp->path);

        if (info->vpp_info == NULL)
        {
            info->vpp_info = temp;
        }
        else
        {
            temp->next = info->vpp_info;
            info->vpp_info = temp;
        }
        
        vpp = vpp->next;
    }

    // insert request to head
    if (g_srv_upgrade_cntx_ptr->requests == NULL)
    {
        g_srv_upgrade_cntx_ptr->requests = info;
    }
    else
    {
        info->next = g_srv_upgrade_cntx_ptr->requests;
        g_srv_upgrade_cntx_ptr->requests = info;
    }

    srv_upgrade_check_new_verson_exists(info->vpp_info);

    if (g_srv_upgrade_cntx_ptr->checking_req == NULL)
    {
        if (srv_upgrade_check_version(info) == MMI_FALSE)
        {
            info->state = SRV_UPGRADE_REQUEST_STATE_FINISHED;
            srv_upgrade_post_notify_result();
        }
    }

    return MMI_TRUE;
}

#else
/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_check_update
 * DESCRIPTION
 *  Check if there is a new version for a list of vpp
 * PARAMETERS
 *  vpp_info             [IN]    vpp information list
 *  count                [IN]    vpp number
 *  originator           [IN]    app enum
 *  cb                   [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_upgrade_check_update(srv_upgrade_req_struct* vpp_info, U8 count, srv_upgrage_originator_enum originator, srv_vpp_upgrade_result_callback cb)
{
    return MMI_FALSE;
}

/******************************************************************************
 * FUNCTION
 *  srv_upgrade_download
 * DESCRIPTION
 *  API for Upgrade APP to notify user agree to download new version
 * PARAMETERS
 *  originator  [IN]    source of the request
 * RETURNS
 *  void
 ******************************************************************************/
void srv_upgrade_download(srv_upgrage_originator_enum originator)
{
    return;
}

/******************************************************************************
 * FUNCTION
 *  srv_upgrade_cancel
 * DESCRIPTION
 *  API for Upgrade APP to notify user do not want to download new version
 * PARAMETERS
 *  originator  [IN]    source of the request
 * RETURNS
 *  void
 ******************************************************************************/
void srv_upgrade_cancel(srv_upgrage_originator_enum originator)
{
    return;
}

#endif
