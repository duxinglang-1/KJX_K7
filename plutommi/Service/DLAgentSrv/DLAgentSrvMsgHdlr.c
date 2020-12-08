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
 * BrowserSrvMsgHdlr.c
 *
 * Project:
 * --------
 *   MAUI
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_include.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "kal_general_types.h"
#include "Das_sap.h"
#include "das_struct.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "mmi_frm_queue_gprot.h"
#include "DLAgentSrvIProt.h"
#include "DLAgentSrvProt.h"
#include "DLAgentSrvDef.h"

void srv_da_msg_init (void)
{

    
    SetProtocolEventHandler((PsFuncPtr) srv_da_push_recv_dispatch_file_req, MSG_ID_MMI_DA_DISPATCH_FILE_REQ);
#if defined(BROWSER_SUPPORT)
	SetProtocolEventHandler((PsFuncPtr)srv_da_recv_wap_file_dl_ind, MSG_ID_WAP_MMI_FILE_DL_IND);
    SetProtocolEventHandler((PsFuncPtr)srv_da_recv_wap_file_dl_progress_ind, MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND);
    SetProtocolEventHandler((PsFuncPtr)srv_da_recv_wap_file_stop_rsp, MSG_ID_WAP_MMI_FILE_DL_STOP_RSP);
#endif
    
#ifdef __MMI_DA_PREFETCHING_SCREEN__
    SetProtocolEventHandler((PsFuncPtr)srv_da_http_cancel_prefetch_rsp_hdlr, MSG_ID_WAP_MMI_FILE_DL_CANCEL_PREFETCH_RSP);
    SetProtocolEventHandler((PsFuncPtr)srv_da_http_prefetch_aborted_ind_hdlr, MSG_ID_WAP_MMI_FILE_DL_PREFETCH_ABORTED_IND);	
#endif/* __MMI_DA_PREFETCHING_SCREEN__ */

#if defined(BROWSER_SUPPORT)
    SetProtocolEventHandler((PsFuncPtr) srv_da_recv_wap_notify_ind, MSG_ID_MMI_DA_WAP_NOTIFY_IND);
#endif/* (__MMI_DOWNLOAD_AGENT_MULTI_DL__) (BROWSER_SUPPORT) */

#if defined(BROWSER_SUPPORT)
    SetProtocolEventHandler((PsFuncPtr) srv_da_recv_nw_switch_ind, MSG_ID_WAP_MMI_FILE_DL_NW_SWITCH_IND);
#endif/* (BROWSER_SUPPORT) */
}

/*****************************************************************************
* FUNCTION
*   srv_da_send_ilm
* DESCRIPTION
*   Send ilm
* PARAMETERS
*
* RETURNS
*   void
*****************************************************************************/
void srv_da_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, S32 dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = (oslModuleType)dst_id;
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (local_para_struct *) local_para_ptr;
    Message.oslPeerBuffPtr = (peer_buff_struct *) peer_buff_ptr;

    switch (dst_id)
    {
        case MOD_MMI:
            Message.oslSapId = MMI_MMI_SAP;
            break;
    
        case MOD_WPS:
            Message.oslSapId = WPS_APP_SAP;
            break;

        case MOD_WAP:
        default:
            Message.oslSapId = WAP_MMI_SAP;
            break;
    }

    OslMsgSendExtQueue(&Message);
}



#if defined(BROWSER_SUPPORT)
/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void srv_da_send_wap_file_dl_res(S32 session_id, S32 error, U16* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_res_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (wap_mmi_file_dl_res_struct*) OslConstructDataPtr(sizeof(wap_mmi_file_dl_res_struct));

    msg->session_id = session_id;
    msg->result = error;
    if(filepath)
    {
        memset (msg->file_path, 0, WAP_DL_MAX_FILE_NAME_LEN + 2);
        mmi_ucs2ncpy((S8*)msg->file_path, (S8*)filepath, WAP_DL_MAX_FILE_NAME_LEN);
    }
    else
    {
        msg->file_path[0] = msg->file_path[1] = 0;
    }
    srv_da_send_ilm_to_wap(msg, NULL, MSG_ID_WAP_MMI_FILE_DL_RES);
}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void srv_da_send_wap_file_dl_progress_res(S32 session_id, U32 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_progress_res_struct * msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (wap_mmi_file_dl_progress_res_struct*) OslConstructDataPtr(sizeof(wap_mmi_file_dl_progress_res_struct));
    msg->session_id = session_id;
    msg->seq_num = seq_num;
    srv_da_send_ilm_to_wap(msg, NULL, MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES);
}

void srv_da_recv_wap_notify_ind(void *MsgStruct, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_wap_notify_ind_struct    *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_da_wap_notify_ind_struct*) MsgStruct;

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_RECV_WAP_NOTIFY_IND,
        msg->notify, (U32)(srv_da_get_curr_job_in_setuping_state()));

    switch (msg->notify)
    {
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__)
        case MMI_DA_WAP_NOTIFY_DISPLAY_LIST:
            srv_da_adp_display_job_list(NULL, MMI_TRUE);
            break;
#endif 

        case MMI_DA_WAP_NOTIFY_BROWSER_CLOSED:
            /* TODO: Close all screen */
        #ifdef __MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__
            srv_da_suspend_and_resume_all_downloads_with_browser();
        #else
            srv_da_suspend_all_job(SRV_DA_ERROR_BROWSER_CLOSED);
        #endif /* __MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__ */
            srv_da_adp_close_app ();
        #ifdef MMI_DA_WLAN_PREFER_SUPPORT
            srv_da_wps_reset_account_id ();
        #endif /* MMI_DA_WLAN_PREFER_SUPPORT */
            break;

        case MMI_DA_WAP_NOTIFY_BROWSER_REOPENED:
            /* TODO: Close all screen */
			srv_da_adp_close_app ();
            break;

        default:
            break;
    }
}
#endif

#endif
