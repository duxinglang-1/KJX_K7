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
 * ProvisionigSrvMsgHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file will contain all the msg handlers for PROV.
 *
 * Author:
 * -------
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"


#include "MMI_features.h"
#include "MMIDataType.h"
#include "phs_struct.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGProt.h"
#endif

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__
#include "ProvisioningSrvMain.h"

#ifdef __MMI_PROV_SERVICE_CCA_SUPPORT_ON__
#include "DLAgentSrvDef.h" /* DL Agent SIM ID ENUM */
#include "ProvisioningSrvProt.h"
//#include "SimDetectionHwMapFile.h"      /* IMSI RSP struct */

//------------------------------ suggest Add ------------------------------

#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_common.h"

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"

#include "kal_general_types.h"
#include "fs_errcode.h"
#include "mmi_msg_struct.h"
#include "ProvisioningSrvConfiguringSrc.h"
#include "CcaSrvGprot.h"
#include "CcaSrvProt.h"

//------------------------------ usage ------------------------------



//static void srv_prov_send_primtive(oslModuleType dest_mod_id, oslMsgType msg_id, oslParaType *local_para);


/*****************************************************************************
 * FUNCTION
 *  srv_prov_send_primtive
 * DESCRIPTION
 *  Sends primitive msg_id to the dest_mod_id.
 * PARAMETERS
 *  dest_mod_id             [IN]
 *  msg_id                  [IN]
 *  local_para              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
//static void srv_prov_send_primtive(oslModuleType dest_mod_id, oslMsgType msg_id, oslParaType *local_para)
//{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MYQUEUE ilm;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = dest_mod_id;
    ilm.oslSapId = INVALID_SAP;
    ilm.oslMsgId = msg_id;
    ilm.oslDataPtr = (oslParaType*) local_para;
    ilm.oslPeerBuffPtr = 0;

    OslMsgSendExtQueue(&ilm);
}
*/


#ifdef __MMI_PROV_MESSAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_prov_convert_wap_addr_to_provbox_addr
 * DESCRIPTION
 *  Converts wap_addr to provbox addr.
 *   for wap_phs_add_struct:
 *   As for the string format, it could be (1) OA/SC number pair (2) IPv4 address (3) Text strings, (4) empty
 *   (1) OA/SC number pair: ex. "+886987654323/102361728/", you need to extract OA or SC address by yourself
 *       OA: Originating Address, SC: SMSC
 *   (2) IPv4 address, ex. "172.168.2.1"
 *   (3) Text: we hardly receive such address information, this is left for error handling 
 * PARAMETERS
 *  provbox_addr             [OUT]
 *  wap_addr                 [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prov_convert_wap_addr_to_provbox_addr(mmi_provbox_addr_struct *provbox_addr, wap_phs_addr_struct *wap_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16  *ptr;
    U16   chr = 0;
    S8   temp_addr[MMI_PROVBOX_ADDR_MAX_CHAR_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (provbox_addr == NULL || wap_addr == NULL)
    {
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_WAP_ADDR_NULL);
        return;
    }

    memset(provbox_addr->addr, 0, sizeof(provbox_addr->addr));

    if (WAP_PHS_ADDR_NULL != wap_addr->type)
    {
        memset(temp_addr, 0, sizeof(temp_addr));
        mmi_ucs2_n_to_asc((S8*) temp_addr, (S8*) wap_addr->addr, MMI_PROVBOX_ADDR_MAX_CHAR_LEN);
        MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, 
                  SRV_PROV_TRACE_GRP9, 
                  "[PROVS] Wap ADDR src type = %d, Addr = %s", 
                  wap_addr->type, 
                  (S8*) temp_addr);
    }

    switch(wap_addr->type)
    {
        case  WAP_PHS_ADDR_NULL:
            MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_WAP_ADDR_TYPE_NONE);
            provbox_addr->addr_type = MMI_PROVBOX_ADDR_TYPE_NONE;
            provbox_addr->addr_len = 0;
        break;

        case WAP_PHS_ADDR_PHONE:
            provbox_addr->addr_type = MMI_PROVBOX_ADDR_TYPE_PHONENUM;
            ptr = (U16*)mmi_ucs2chr((const S8*)wap_addr->addr, (U16) WAP_PHS_ADDR_PHONE_SEP);
            if (ptr)
            {
                chr = *ptr;
                *ptr = L'\0';
            }
            provbox_addr->addr_len = mmi_ucs2strlen((const S8 *)wap_addr->addr);
            if (provbox_addr->addr_len > MMI_PROVBOX_ADDR_MAX_CHAR_LEN)
            {
                provbox_addr->addr_len = MMI_PROVBOX_ADDR_MAX_CHAR_LEN;
            }
            memcpy(provbox_addr->addr, wap_addr->addr, provbox_addr->addr_len * ENCODING_LENGTH);
            if (ptr)
            {
                *ptr = chr;
            }
        break;
        
        case WAP_PHS_ADDR_IP:

            provbox_addr->addr_type = MMI_PROVBOX_ADDR_TYPE_IPV4;
            provbox_addr->addr_len = mmi_ucs2strlen((const S8 *)wap_addr->addr);
            if (provbox_addr->addr_len > MMI_PROVBOX_ADDR_MAX_CHAR_LEN)
            {
                provbox_addr->addr_len = MMI_PROVBOX_ADDR_MAX_CHAR_LEN;
            }
            mmi_ucs2ncpy((S8 *)provbox_addr->addr, (const S8 *)wap_addr->addr, provbox_addr->addr_len);
        break;
        
        case WAP_PHS_ADDR_TEXT:
            provbox_addr->addr_type = MMI_PROVBOX_ADDR_TYPE_TEXT;
            provbox_addr->addr_len = mmi_ucs2strlen((const S8 *)wap_addr->addr);
            if (provbox_addr->addr_len > MMI_PROVBOX_ADDR_MAX_CHAR_LEN)
            {
                provbox_addr->addr_len = MMI_PROVBOX_ADDR_MAX_CHAR_LEN;
            }
            memcpy(provbox_addr->addr, wap_addr->addr, provbox_addr->addr_len * ENCODING_LENGTH);
        break;

        default:
            MMI_ASSERT(!"Wrong wap_addr->type");
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_send_provbox_save_msg_req
 * DESCRIPTION
 *  Sends req to provbox to save recieved msg.
 * PARAMETERS
 *  sim_id                      [IN]
 *  filename                    [IN]
 *  mime_type_str_string        [IN]
 *  wap_addr                    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_send_provbox_save_msg_req(U8 sim_id, PU16 filename, PS8 mime_type_str_string, const S8* wap_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    UINT size;
    FS_HANDLE file_handle;
    mmi_provbox_save_msg_req_struct *req_data;
    S8 temp_filename[100];
    static U16 transid = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data =
        (mmi_provbox_save_msg_req_struct*)
        OslConstructDataPtr(sizeof(mmi_provbox_save_msg_req_struct));
    
    if ((++transid) >= 65535)
        transid = 1;

    req_data->trans_id = transid;
    req_data->cmn_info.msg_id = MMI_PROVBOX_INVALID_MSG_ID;
    req_data->cmn_info.timestamp = 0;
    req_data->cmn_info.install_time = 0;
    req_data->cmn_info.src_id = MMI_PROVBOX_SOURCE_ID_WAP;
	req_data->cmn_info.sim_id = MMI_SIM1;
#if (MMI_MAX_SIM_NUM>= 2)    
	switch(sim_id)
{
	case MMI_DA_PUSH_SIM2:
		req_data->cmn_info.sim_id = MMI_SIM2;
            break;
#if (MMI_MAX_SIM_NUM>= 3)
        case MMI_DA_PUSH_SIM3:
		req_data->cmn_info.sim_id =  MMI_SIM3;
            break;
#if (MMI_MAX_SIM_NUM>= 4)
        case MMI_DA_PUSH_SIM4:
		req_data->cmn_info.sim_id = MMI_SIM4; 
            break;
#endif
#endif
        default:
  	    break;
}
#endif
    req_data->cmn_info.box_type = MMI_PROVBOX_BOX_TYPE_UNKNOWN;
    req_data->cmn_info.msg_type = MMI_PROVBOX_MSG_TYPE_OTA;
    req_data->cmn_info.read_status = MMI_PROVBOX_MSG_READ_STATUS_UNREAD;

    req_data->msg_config_status.config_status = MMI_PROVBOX_CONFIG_STATUS_NOT_INSTALLED;
    req_data->msg_config_status.app_num = 0;

    srv_prov_convert_wap_addr_to_provbox_addr(&req_data->cmn_info.sender_addr, (wap_phs_addr_struct*)wap_addr);

    req_data->msg_data.app_data_size = strlen(mime_type_str_string) + 1;
    req_data->msg_data.app_data = srv_prov_mem_alloc(req_data->msg_data.app_data_size);
    MMI_ASSERT(req_data->msg_data.app_data);
    strcpy(req_data->msg_data.app_data, mime_type_str_string);
    req_data->msg_data.prov_data_type = MMI_PROVBOX_SAVE_DATA_TYPE_FILE;
    req_data->msg_data.prov_file = srv_prov_mem_alloc(mmi_ucs2strlen((const S8 *)filename) * ENCODING_LENGTH + 2);
    mmi_ucs2cpy((S8 *) req_data->msg_data.prov_file, (const S8 *)filename);

    file_handle = FS_Open((const WCHAR*)filename, FS_READ_ONLY);
    ASSERT(file_handle >= FS_NO_ERROR);
    /* to avaid 4-byte align issue on target, should use 32 bit paramter in FS_GetFileSize instead of prov_data_size. */
//    ret = FS_GetFileSize(file_handle,  (UINT*)&req_data->msg_data.prov_data_size);
    ret = FS_GetFileSize(file_handle, &size);
    FS_Close(file_handle);
    req_data->msg_data.prov_data_size = size;

    memset(temp_filename, 0, sizeof(temp_filename));
    mmi_ucs2_n_to_asc((S8*) temp_filename, (S8*) filename, 99);

    /* The string is too long to print out, just split it to two parts. */
    MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, 
              SRV_PROV_TRACE_GRP9, 
              "[PROVS] SEND PROVBOX SAVE MSG REQ sim_id = %d, MIME = %s", 
              sim_id, 
              mime_type_str_string);

    MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, 
              SRV_PROV_TRACE_GRP9, 
              "[PROVS] SEND PROVBOX SAVE MSG REQ filename = %s,filesize = %d,size=%d,ret=%d,type=%d", 
              (S8*) temp_filename,
              req_data->msg_data.prov_data_size, size, ret, 
              req_data->msg_data.prov_data_type);

    //srv_prov_send_primtive(MOD_MMI, MSG_ID_MMI_PROVBOX_SAVE_MSG_REQ, (oslParaType*) req_data);
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_PROVBOX_SAVE_MSG_REQ, (oslParaType*) req_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_send_provbox_get_msg_data_req
 * DESCRIPTION
 *  Sends req to provbox to send provisioning data for processing.
 * PARAMETERS
 *  msg_id                      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_send_provbox_get_msg_data_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_get_msg_data_req_struct *req_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_PROVBOX_GET_MSG_DATA_REQ, msg_id);

    req_data =
        (mmi_provbox_get_msg_data_req_struct*)
        OslConstructDataPtr(sizeof(mmi_provbox_get_msg_data_req_struct));

    req_data->trans_id = 10001;
    req_data->msg_id = msg_id;
    req_data->src_id = MMI_PROVBOX_SOURCE_ID_WAP;

    //srv_prov_send_primtive(MOD_MMI, MSG_ID_MMI_PROVBOX_GET_MSG_DATA_REQ, (oslParaType*) req_data);
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_PROVBOX_GET_MSG_DATA_REQ, (oslParaType*) req_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_send_cca_source_install_prov_msg_cnf
 * DESCRIPTION
 *  Sends confirmation message containing result to ProvBox after install provisioning.
 * PARAMETERS
 *  msg_id                      [IN]
 *  trans_id                    [IN]
 *  sim_id                      [IN]
 *  prov_type                   [IN]
 *  prov_flag                   [IN]
 *  status                      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_send_cca_source_install_prov_msg_cnf(U32 msg_id, S32 trans_id, U16 sim_id,
        U8 prov_type, U32 prov_flag, srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_install_prov_msg_cnf_struct *cnf_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(SRV_PROV_TRACE_GRP9, 
              TRC_MMI_PROV_CCA_INSTALL_PROV_MSG_CNF, 
              msg_id, 
              trans_id, 
              sim_id, 
              prov_type, 
              prov_flag,
              status);

    cnf_data =
        (srv_cca_src_install_prov_msg_cnf_struct*)
        OslConstructDataPtr(sizeof(srv_cca_src_install_prov_msg_cnf_struct));
    

    cnf_data->msg_id = msg_id;
    cnf_data->trans_id = trans_id;
    cnf_data->source_id = SRV_CCA_SOURCE_WAP;
    cnf_data->sim_id = sim_id;
    cnf_data->prov_type = prov_type;
    cnf_data->prov_flag = prov_flag;
    cnf_data->status = status;

   // srv_prov_send_primtive(MOD_MMI, MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_CNF, (oslParaType*) cnf_data);
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_CNF, (oslParaType*) cnf_data, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_provbox_save_msg_cnf_hdlr
 * DESCRIPTION
 *  Confirmation message from ProvBox for save msg req.
 * PARAMETERS
 *  msg                         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_prov_provbox_save_msg_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_save_msg_cnf_struct *cnf_data = (mmi_provbox_save_msg_cnf_struct*)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(SRV_PROV_TRACE_GRP9, 
              TRC_MMI_PROV_PROVBOX_SAVE_MSG_CNF, 
              cnf_data->src_id, 
              (U32) cnf_data->app_data,
              (U32) cnf_data->prov_data,
              (U32) cnf_data->prov_file);

    if (cnf_data->src_id != MMI_PROVBOX_SOURCE_ID_WAP)
        return 0;
    
    if (cnf_data->app_data)
        srv_prov_mem_free(cnf_data->app_data);
    if (cnf_data->prov_data)
        srv_prov_mem_free(cnf_data->prov_data);
    if (cnf_data->prov_file)
        srv_prov_mem_free(cnf_data->prov_file);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_provbox_get_msg_data_cnf_hdlr
 * DESCRIPTION
 *  Response of get msg data request for processing.
 * PARAMETERS
 *  msg                         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_prov_provbox_get_msg_data_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_provbox_get_msg_data_cnf_struct *cnf_data;
    srv_prov_retcode_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cnf_data = (mmi_provbox_get_msg_data_cnf_struct*)msg;

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_PROVBOX_GET_MSG_DATA_CNF_HDLR, cnf_data->src_id);

    if (cnf_data->src_id != MMI_PROVBOX_SOURCE_ID_WAP)
        return 0;

    if (SRV_PROVBOX_RESULT_OK != cnf_data->result)
    {
        if (cnf_data->app_data)
        {
            mmi_provbox_free_app_data(cnf_data->app_data);
        }
        if (cnf_data->result == SRV_PROVBOX_RESULT_MEM_FULL || cnf_data->result == SRV_PROVBOX_RESULT_DISK_FULL)
           srv_prov_handle_error(SRV_PROV_MEM_FULL);
        else        
            srv_prov_handle_error(SRV_PROV_GET_MSG_FAILED);
        return 1;
    }

    MMI_ASSERT (cnf_data->app_data);

    result = srv_prov_process_new_provisioning_message((PU16)cnf_data->filename, 
                                                       (S32) g_srv_prov_ctxt.msg_sim_id,
                                                       (PS8)cnf_data->app_data, 
                                                       NULL);

    if (SRV_PROV_OK != result)
    {
        srv_prov_handle_error(result);
    }

    mmi_provbox_free_app_data(cnf_data->app_data);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_source_install_prov_msg_req_hdlr
 * DESCRIPTION
 *  Request to install provisioning.
 * PARAMETERS
 *  msg                         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_source_install_prov_msg_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_install_prov_msg_req_struct *req_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_data = (srv_cca_src_install_prov_msg_req_struct*)msg;

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_INSTALL_PROV_MSG_REQ_HDLR, 
              req_data->msg_id,
              req_data->trans_id,
              req_data->prov_flag,
              req_data->sim_id);

    g_srv_prov_ctxt.msg_id = req_data->msg_id;
    g_srv_prov_ctxt.msg_trans_id = req_data->trans_id;
    g_srv_prov_ctxt.msg_sim_id = req_data->sim_id;
    g_srv_prov_ctxt.msg_prov_type = req_data->prov_type;
    g_srv_prov_ctxt.msg_prov_flag = req_data->prov_flag;
    
    srv_prov_send_provbox_get_msg_data_req(req_data->msg_id);
}


#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_new_doc_ind_req
 * DESCRIPTION
 *  write MSG_ID_SRV_CCA_SRC_NEW_DOC_IND event to mmi task
 * PARAMETERS
 *  hdoc_config     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_new_doc_ind_req(S32 hdoc_config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_new_doc_ind_struct *data;
    srv_prov_queue_data_struct *prov_data_p = *(srv_prov_get_current_queue_data());
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_NEW_DOC_IND_REQ);

/*    g_srv_prov_ctxt.new_doc_rsp_state = SRV_PROV_CCA_DOC_RSP_WAITING; USIM */
    data = (srv_cca_src_new_doc_ind_struct*) OslConstructDataPtr(sizeof(srv_cca_src_new_doc_ind_struct));
    ASSERT(data);
    data->spec_id = SRV_CCA_SPEC_OMA;
    data->hConfig = hdoc_config;
    data->sim_id = prov_data_p->i_sim_id;
    data->source_id = SRV_CCA_SOURCE_WAP;
    data->prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;
    data->prov_flag = 0;    /* USIM */
    data->sec_type = SRV_CCA_SEC_TYPE_NONE;

    switch (g_srv_prov_ctxt.i_sec_value)
    {
        case SRV_PROV_SEC_VALUE_NETWPIN:
            data->sec_type = SRV_CCA_SEC_TYPE_NETWPIN;
        break;

        case SRV_PROV_SEC_VALUE_USERPIN:
            data->sec_type = SRV_CCA_SEC_TYPE_USERPIN;
        break;

        case SRV_PROV_SEC_VALUE_USERNETWPIN:
            data->sec_type = SRV_CCA_SEC_TYPE_USERNETWIN;
        break;

        case SRV_PROV_SEC_VALUE_USERPINMAC:
            data->sec_type = SRV_CCA_SEC_TYPE_USERPINMAC;
        break;

        default:
            data->sec_type = SRV_CCA_SEC_TYPE_NONE;
        break;
    }

    //srv_prov_send_primtive(MOD_MMI, MSG_ID_SRV_CCA_SRC_NEW_DOC_IND, (oslParaType*) data);
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_SRC_NEW_DOC_IND, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_invalid_setting_ind_req
 * DESCRIPTION
 *  write MSG_ID_SRV_CCA_SRC_UI_INVALID_SETTING_IND event to mmi task
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_invalid_setting_ind_req(srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_invalid_setting_ind_struct *data;
#ifndef __MMI_PROV_MESSAGE_SUPPORT__
    srv_prov_queue_data_struct *prov_data_p = *(srv_prov_get_current_queue_data());
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_INVALID_SETTING_IND_REQ);

    data =
        (srv_cca_src_invalid_setting_ind_struct*)
        OslConstructDataPtr(sizeof(srv_cca_src_invalid_setting_ind_struct));
    ASSERT(data);
    /* data->spec_id = CCA_SPEC_OMA; */
    data->status = status;

#ifndef __MMI_PROV_MESSAGE_SUPPORT__
    data->sim_id = prov_data_p->i_sim_id;
#else
    data->sim_id = g_srv_prov_ctxt.msg_sim_id;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

    data->source_id = SRV_CCA_SOURCE_WAP;
    data->prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;

#ifndef __MMI_PROV_MESSAGE_SUPPORT__
    data->trans_id = prov_data_p->trans_id; /* USIM */
#else
    data->trans_id = g_srv_prov_ctxt.msg_trans_id;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

    data->msg_id = SRV_CCA_INVALID_MSG_ID;
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    data->msg_id = g_srv_prov_ctxt.msg_id;
#endif

    //srv_prov_send_primtive(MOD_MMI, MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND, (oslParaType*) data);
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND, (oslParaType*) data, NULL);
}

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_ui_auth_req
 * DESCRIPTION
 *  write MSG_ID_SRV_CCA_SRC_UI_AUTH_IND event to CCA in mmi task.
 *  This request has to be sent after successful PIN to indicate CCA of success.
 *  For first attempt send status = CCA_STATUS_FAIL.
 *  on successful PIN validation send status = CCA_STATUS_OK.
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_ui_auth_req(srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_auth_ind_struct *l_data;
    srv_prov_queue_data_struct *prov_data_p = *(srv_prov_get_current_queue_data()); /* USIM */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_AUTH_REQ, (U32) status);

    l_data = (srv_cca_src_auth_ind_struct*) OslConstructDataPtr(sizeof(srv_cca_src_auth_ind_struct));
    ASSERT(l_data);
    l_data->spec_id = SRV_CCA_SPEC_OMA;
    l_data->source_id = SRV_CCA_SOURCE_WAP;
    l_data->prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;

/*    l_data->trans_id = 1; USIM */
    l_data->trans_id = prov_data_p->trans_id;   /* USIM */
    /* using constant 1 as transid as it has to be same for retires */
    /* As only 1 setting will be parsed at a time hence it can be taken as constant */
    l_data->max_attempts = SRV_PROV_MAX_PIN_RETRIES;
    l_data->status = status;    /* FAIL means previous try was failure, SUCCESS means previous try was success. */

    //srv_prov_send_primtive(MOD_MMI, MSG_ID_SRV_CCA_SRC_AUTH_IND , (oslParaType*) l_data);
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_SRC_AUTH_IND, (oslParaType*) l_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_ui_auth_rsp_hdlr
 * DESCRIPTION
 *  handle MSG_ID_SRV_CCA_SRC_UI_AUTH_RSP events from mmi task
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_ui_auth_rsp_hdlr(srv_cca_src_auth_rsp_struct *l_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] Entered PIN = %s, CCA_STATUS = %d", (S8*) l_data->pin, l_data->status);
    if (SRV_CCA_STATUS_OK == l_data->status)
    {
        //MMI_PRINT(SRV_PROV_TRACE_MOD_INET_APP, SRV_PROV_TRACE_GRP9, "[PROVS] Entered PIN = %s", (S8*) l_data->pin);
        srv_prov_handle_pin((S8*) l_data->pin);
    }
    else
    {
        /* Either max retry count reached or user abort */
       // MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_AUTH_RSP_FAIL);
        srv_prov_delete_queue_entry();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_get_imsi_req
 * DESCRIPTION
 *  Sends request for IMSI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM>= 2)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM>=3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif          
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 


#ifndef __MMI_PROV_MESSAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_new_setting_ind_req
 * DESCRIPTION
 *  write MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND event to mmi task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_new_setting_ind_req(U16 i_sim_id, S32 *trans_id_p)    /* USIM */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_new_setting_ind_struct  *data;
    static S32 transid = 1;     /* USIM */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_NEW_SETTING_IND_REQ_ENTER);

    data =
        (srv_cca_src_new_setting_ind_struct*)
        OslConstructDataPtr(sizeof(srv_cca_src_new_setting_ind_struct));
    ASSERT(data);
    data->spec_id = SRV_CCA_SPEC_OMA;
    data->sim_id = i_sim_id; /* USIM */
    data->source_id = SRV_CCA_SOURCE_WAP;   /* Indicates provisioning from OTA. */
    data->prov_type = SRV_CCA_PROV_TYPE_OTA_PROV;

    transid++;
    if (transid > SRV_PROV_MAX_CCA_NODEID_ITTR)
    {
        transid = 1;
    }
    *trans_id_p = transid;  /* Store transID in queue structure. */ /* USIM */
    data->trans_id = transid;

    //srv_prov_send_primtive(MOD_MMI, MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND, (oslParaType*) data);
	mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_new_setting_rsp_hdlr
 * DESCRIPTION
 *  handle MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP events from CCA
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_new_setting_rsp_hdlr(srv_cca_src_new_setting_rsp_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_NEW_SETTING_RSP_HDLR_ENTER);

    if (data->response == SRV_CCA_STATUS_OK)
    {
        srv_prov_start_setting_parser();
    }
    else    /* Abort response from New Setting screen. */
    {
        MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_NEW_SETTING_USER_ABORT);
        srv_prov_delete_queue_entry();  /* Delete entry from queue */
    }

    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_NEW_SETTING_RSP_HDLR_EXIT);
}
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_prov_cca_new_doc_rsp_hdlr
 * DESCRIPTION
 *  handle MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP events from mmi task
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_cca_new_doc_rsp_hdlr(srv_cca_src_new_doc_rsp_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_CCA_NEW_DOC_RSP);

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    srv_prov_send_cca_source_install_prov_msg_cnf(g_srv_prov_ctxt.msg_id, 
        g_srv_prov_ctxt.msg_trans_id, g_srv_prov_ctxt.msg_sim_id,
        g_srv_prov_ctxt.msg_prov_type, g_srv_prov_ctxt.msg_prov_flag, data->status);
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
}

#endif /* __MMI_PROV_SERVICE_CCA_SUPPORT_ON__ */ 
#endif /* __PROVISIONING_SERVICE_SUPPORT__ */

