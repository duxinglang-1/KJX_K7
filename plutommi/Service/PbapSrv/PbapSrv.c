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
 *  PhoneBookPBAP.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  phonebook access profile
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__
#if defined(__MMI_PBAP_SUPPORT__)


#include "Conversions.h"
#include "BtcmSrvGprot.h"

#include "BTMMIScr.h"
#include "Bluetooth_struct.h"
#include "Bluetooth_bm_struct.h"

#include "PhoneBookPbap.h"
#include "PbapSrvGprot.h"
#include "PbapSrv.h"

#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_queue_gprot.h"
//#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "kal_public_api.h"
#include "stack_config.h"
//#include "stack_ltlcom.h"
#include "stack_common.h"
#include "kal_general_types.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"
#include "Unicodexdcl.h"
#include "custom_phb_config.h"
#include "PhbSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
//#include "app_buff_alloc.h"
#include "stdio.h"
#include "vCard.h"

static void srv_pbap_set_event_hdlr(void);
static void srv_pbap_cntx_init(void);
static void srv_pbap_connection_terminated(void);
static void srv_pbap_activate_cnf_hdlr(void *ilm_ptr);
static U8 srv_pbap_sdp_register_cnf_hdlr(void *msg);
static void srv_pbap_deactivate_cnf_hdlr(void *ilm_ptr);
static U8 srv_pbap_sdp_deregister_cnf_hdlr(void *msg);
static void srv_pbap_setpath_ind_hdlr(void *ilm_ptr);
static void srv_pbap_readentry_ind_hdlr(void *ilm_ptr);
static void srv_pbap_readfolder_ind_hdlr(void *ilm_ptr);
static void srv_pbap_readlist_ind_hdlr(void *ilm_ptr);
static void srv_pbap_connect_ind_hdlr(void *ilm_ptr);
static void srv_pbap_connect_rsp_hdlr(U8 result);
static void srv_pbap_disconnect_ind_hdlr(void *ilm_ptr);
static void srv_pbap_abort_ind_hdlr(void *ilm_ptr);
static void srv_pbap_authrize_ind_hdlr(void *ilm_ptr);
static void srv_pbap_authrize_rsp(U8 rsp_code);

//static void srv_pbap_authrize_scr_hdlr(void);
static void srv_pbap_authrize_rsp(U8 rsp_code);
//static void srv_pbap_auth_confirm(void);
static void srv_pbap_auth_ind_hdlr(void *ilm_ptr);
static void srv_pbap_authentication_rsp(U8 *password);
static void srv_pbap_provide_entry(void);
static void srv_pbap_write_entry_cbk(mmi_phb_vcard_error_struct* error_info);
static void srv_pabp_provide_folder(void);
static void srv_pbap_get_folder_array_cbk(mmi_phb_vcard_error_struct* error_info, U16* array, U16 array_size);
static void srv_pbap_write_folder_entry_cbk(mmi_phb_vcard_error_struct* error_info);
static void srv_pbap_get_fodler_size_cbk(mmi_phb_vcard_error_struct *error_info, U16 size);
static void srv_pbap_get_folder_mcsize_cbk(mmi_phb_vcard_error_struct *error_info, U16 size);
static void srv_pabp_provide_list(void);
static void srv_pbap_get_list_array_cbk(mmi_phb_vcard_error_struct* error_info, U16* array, U16 array_size);
static void srv_pbap_get_info_cbk(mmi_phb_vcard_error_struct* error_info, S8* name, S8* number);
static PbStatus srv_pbap_compose_list_header(void);
static PbStatus srv_pbap_compose_list_middle(U16 index, PbPullVcardListingOp vcard_listing, const U16* pb_name_str, const U16* pb_number_str);
static PbStatus srv_pbap_compose_list_element(U16 hdlr, S8 *name);
static PbStatus srv_pbap_compose_list_tail(void);
static void srv_pbap_get_list_size_cbk(mmi_phb_vcard_error_struct *error_info, U16 size);
static void srv_pbap_get_list_mcsize_cbk(mmi_phb_vcard_error_struct *error_info, U16 size);
//static void srv_pbap_get_dev_name(U8 *name_buf);
static mmi_ret srv_pbap_post_proc(mmi_event_struct* para);
static void srv_pbap_send_msg(U32 msg_id, void *p_local_para);
static S8 srv_pbap_get_pbtype(S8 *path, S8 *sub_folder);
static PbPathFlags srv_pbap_get_path_flag(S8 *path);
static mmi_phb_storage_enum srv_pbap_flag2type(PbPathFlags pathFlags);
static void srv_pbap_string_swapcpy(PU8 dest_str, const PU8 src_str);
static void srv_pbap_get_phb_filter(PU8 pb_filter, const PU8 pbap_filter);
static void srv_pbap_get_phb_format(PU8 pb_format, PbapVcardFormat pbap_format);
static U8 srv_pbap_get_phb_order(U8 pbap_order);
static U8 srv_pbap_get_phb_err_code(mmi_phb_vcard_error_struct* error_info);
static void srv_pbap_send_msg_self(U32 msg_id, void *p_local_para);
static void srv_pbap_get_new_missed_calls(
    U16 size, 
    mmi_phb_get_storage_size_funcptr_type cbk_build_entry);
static void srv_pbap_write_one_entry(
    U16 index, 
    U8 storage, 
    U16 *path,
    const PU8 pbap_filter_str, 
    PbapVcardFormat pbap_format,
    MMI_BOOL is_append,
    mmi_phb_build_vcard_funcptr_type cbk_build_entry);
static U16 srv_pbap_check_folder(S8 *path);
static S8 srv_pbap_backup_folder(S8 *path);
static void srv_pbap_notify_app(U32 event_id, void *para);
static srv_pbap_handle_struct *srv_pbap_get_inst_from_srv_hd(S32 srv_hd);


srv_pbap_context_struct srv_pbap_cntx;
srv_pbap_context_struct *srv_pbap_p = &srv_pbap_cntx;

#define SRV_PBAP_EXTERNAL_API
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pbap_init
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_pbap_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < SRV_PBAP_MAX_HANDLE_NUM; i++)
    {
        if (srv_pbap_p->app_hd[i].srv_hd == 0)
        {
            srv_pbap_p->app_hd[i].srv_hd = i + 1;
            srv_pbap_p->app_hd[i].pbap_cntx = &srv_pbap_p->pbap_cntx;
            return i + 1;
        }
    }

    return SRV_PBAP_RESULT_INVALID_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pbap_init
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_pbap_close(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = srv_pbap_get_inst_from_srv_hd(srv_hd);

    if (inst != NULL)

    inst->srv_hd = 0;
    inst = NULL;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_set_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  event_mask      [IN]        
 *  notifier        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_pbap_set_notify(S32 srv_hd, U32 event_mask, bt_notify notifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
     
    inst = srv_pbap_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_PBAP_RESULT_INVALID_HANDLE;

    if (notifier == NULL)
        return SRV_PBAP_RESULT_INVALID_PARAMETERS;

    inst->event_mask = event_mask;
    inst->notifier = notifier;


    return SRV_PBAP_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pbap_init
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_pbap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_profile_struct profile_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_INIT);
    
    srv_pbap_cntx_init();
    srv_pbap_set_event_hdlr();

	profile_info_p.profile_id = SRV_BT_CM_OBEX_PBA_PROFILE_UUID;
	profile_info_p.activater = srv_pbap_activate;
	profile_info_p.deactivater = srv_pbap_deactivate;
	profile_info_p.disconnector = srv_pbap_disconnect_client;
	srv_bt_cm_profile_register((const srv_bt_cm_profile_struct *)&profile_info_p);

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_deinit
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_pbap_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_DEINIT);

    srv_pbap_cntx_init();

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_activate
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_pbap_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 security_level = 0x03;   /* BSM_SEC_LEVEL_2; */
    bt_pbap_register_req_struct *req;
    //U8 Register_flag = 0;  //eric, can be remove
    //srv_pbap_handle_struct *inst;
    srv_pbap_event_struct event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_ACTIVATE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
    switch(srv_pbap_p->pbap_cntx.state)
    {
        case SRV_PBAP_STATE_IDLE:
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_REGISTERING);
            req = (bt_pbap_register_req_struct*) OslConstructDataPtr(sizeof(bt_pbap_register_req_struct));

            req->security_level = security_level;

            srv_pbap_send_msg(MSG_ID_BT_PBAP_REGISTER_REQ, req);
            break;
            
        case SRV_PBAP_STATE_REGISTERING:
            break;
            
        default:
            MMI_FRM_INIT_EVENT(&event, SRV_PBAP_EVENT_REG);

            srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_UUID);
            
            event.event_id= SRV_PBAP_EVENT_START;
            event.data = NULL;
            
            mmi_frm_post_event((mmi_event_struct *)&event, srv_pbap_post_proc, NULL);
            break;
    }
    
    //return SRV_PBAP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_deactivate
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_pbap_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_req_struct *req;
    //srv_pbap_handle_struct *inst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_DEACTIVATE);
    SRV_PBAP_LOG_STATE();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
    /* check all connections state */
    switch (srv_pbap_p->pbap_cntx.state)
    {
        case SRV_PBAP_STATE_REGISTERING:    /* activating -> deactivating */
            MMI_ASSERT(0);
            break;
        case SRV_PBAP_STATE_IDLE:           /* unactivated */
            break;
		case SRV_PBAP_STATE_AUTHORIZING:
			srv_pbap_authrize_rsp(PBAP_CNF_FAILED);
			srv_pbap_connection_terminated();
        default:                            /* other activated states */
            SRV_PBAP_LOG(SRV_PBAP_SERVER_SDP_DEREGISTER_REQ);
            /* send SDP deregister primitive */
            req = (bt_sdpdb_deregister_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_deregister_req_struct));

            req->uuid = SRV_BT_CM_OBEX_PBA_PROFILE_UUID;

            /* send req to bt */
            {
				srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SDPDB_DEREGISTER_REQ, (void*)req, NULL);
            }

            break;
    }

    //return SRV_PBAP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_accept_conn
 * DESCRIPTION
 *  This function is to accept rfcomm channel.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_pbap_accept_conn(S32 srv_hd, U8 *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    inst = srv_pbap_get_inst_from_srv_hd(srv_hd);
    
    if (inst == NULL)
        return SRV_PBAP_RESULT_INVALID_HANDLE;


    if (inst->pbap_cntx->state == SRV_PBAP_STATE_AUTHORIZING)
    {
        /* Send success connect response to OBEX task */
        srv_pbap_authrize_rsp(PBAP_CNF_SUCCESS);
    }
    else
    {
        srv_pbap_authentication_rsp(password);
    }

    return SRV_PBAP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_reject_conn
 * DESCRIPTION
 *  This function is to reject rfcomm channel.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_pbap_reject_conn(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = srv_pbap_get_inst_from_srv_hd(srv_hd);
    
    if (inst == NULL)
        return SRV_PBAP_RESULT_INVALID_HANDLE;


    if (inst->pbap_cntx->state == SRV_PBAP_STATE_AUTHORIZING)
    {
        /* Send failed connect response to OBEX task */
        srv_pbap_authrize_rsp(PBAP_CNF_FAILED);
    }
    else
    {
        srv_pbap_authentication_rsp(NULL);
    }

    return SRV_PBAP_RESULT_OK;
}



#define MMI_PBAP_INIT

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_set_event_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_set_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SET_EVENT_HDLR);
    
    SetProtocolEventHandler((PsFuncPtr) srv_pbap_setpath_ind_hdlr, MSG_ID_BT_PBAP_SET_PATH_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_readentry_ind_hdlr, MSG_ID_BT_PBAP_READ_ENTRY_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_readfolder_ind_hdlr, MSG_ID_BT_PBAP_READ_FOLDER_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_readlist_ind_hdlr, MSG_ID_BT_PBAP_READ_LIST_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_activate_cnf_hdlr, MSG_ID_BT_PBAP_REGISTER_RSP);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_deactivate_cnf_hdlr, MSG_ID_BT_PBAP_DEREGISTER_RSP);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_connect_ind_hdlr, MSG_ID_BT_PBAP_CLIENT_CONNECT_IND);

    SetProtocolEventHandler((PsFuncPtr)srv_pbap_auth_ind_hdlr, MSG_ID_BT_PBAP_CLIENT_AUTH_CHALLENGE_IND);

    /* SetProtocolEventHandler((PsFuncPtr)srv_pbap_continue_ind_hdlr, MSG_ID_BT_PBAP_CONTINUE_IND); */

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_disconnect_ind_hdlr, MSG_ID_BT_PBAP_CLIENT_DISCONNECT_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_abort_ind_hdlr, MSG_ID_BT_PBAP_ABORT_REQ);

    SetProtocolEventHandler((PsFuncPtr) srv_pbap_authrize_ind_hdlr, MSG_ID_BT_PBAP_AUTHORIZE_IND);

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_REGISTER_CNF, (PsIntFuncPtr)srv_pbap_sdp_register_cnf_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_DEREGISTER_CNF, (PsIntFuncPtr)srv_pbap_sdp_deregister_cnf_hdlr, MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_cntx_init
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_CNTX_INIT);
    
    memset(&srv_pbap_p->pbap_cntx, 0, sizeof(srv_pbap_p->pbap_cntx));
    srv_pbap_p->pbap_cntx.cm_conn_id = MMI_PBAP_INVALID_CONN_ID;
    srv_pbap_p->pbap_cntx.state = SRV_PBAP_STATE_IDLE;

    srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
    srv_pbap_p->pbap_cntx.pb_size = 0;

    memset(&srv_pbap_p->app_hd, 0, sizeof (srv_pbap_p->app_hd));
}





/*****************************************************************************
 * FUNCTION
 *  srv_pbap_activate_cnf_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_activate_cnf_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_register_rsp_struct *cnf = (bt_pbap_register_rsp_struct*) ilm_ptr;
    bt_sdpdb_register_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_ACTIVATE_CNF);

    if (cnf->register_result != PBAP_CNF_SUCCESS)
    {
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_IDLE);
        return;
    }
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_REGISTERING)
    {
        SRV_PBAP_LOG_STATE();
        return;
    }

    SRV_PBAP_LOG(SRV_PBAP_SERVER_SDP_REGISTER);
    /* Send SDP Register primitive */
    req = (bt_sdpdb_register_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_register_req_struct));

    req->uuid = (U32) SRV_BT_CM_OBEX_PBA_PROFILE_UUID;
    {
        /*ilm_struct *ilm_send;

        ilm_send = allocate_ilm(MOD_MMI);
        ilm_send->src_mod_id = MOD_MMI;
        ilm_send->dest_mod_id = MOD_BT;
        ilm_send->sap_id = BT_APP_SAP;
        ilm_send->msg_id = (U16) MSG_ID_BT_SDPDB_REGISTER_REQ;
        ilm_send->local_para_ptr = (local_para_struct*) req;
        ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

        msg_send_ext_queue(ilm_send);*/
		srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SDPDB_REGISTER_REQ, (void*)req, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_sdp_register_cnf_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_pbap_sdp_register_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_cnf_struct *cnf = (bt_sdpdb_register_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_SDP_REGISTER_CNF);

    if (cnf->uuid != SRV_BT_CM_OBEX_PBA_PROFILE_UUID)
        return MMI_FALSE;
    /* SDP register success */
    if (cnf->result == 0x00)
    {
        
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_ACTIVE);
        srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_UUID);
        srv_pbap_notify_app(SRV_PBAP_EVENT_START, NULL);

        return MMI_TRUE;

    }
    /* SDP register failed */
    else
    {
        SRV_PBAP_LOG1(SRV_PBAP_SERVER_SDP_REGISTER_FAIL_RESULT, cnf->result);
        MMI_ASSERT(0);
    }

    return MMI_FALSE;
}


#define MMI_PBAP_DEINIT

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_connection_terminated
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_pbap_disconn_notify_struct disconn_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_CONN_TERMINATED);

    disconn_notify.conn_id = srv_pbap_p->pbap_cntx.cm_conn_id;

    disconn_notify.bt_addr = srv_pbap_p->pbap_cntx.bt_device;

    if (srv_pbap_p->pbap_cntx.disconnect_from_cm)
        disconn_notify.disconnect_from_cm = MMI_TRUE;
    else
        disconn_notify.disconnect_from_cm = MMI_FALSE;
    srv_pbap_p->pbap_cntx.disconnect_from_cm = MMI_FALSE;

    srv_bt_cm_stop_conn(srv_pbap_p->pbap_cntx.conn_id);

    srv_pbap_notify_app(SRV_PBAP_EVENT_DISCONN_NOTIFY, (void *)&disconn_notify);

    srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
    srv_pbap_p->pbap_cntx.pb_size = 0;
    srv_pbap_p->pbap_cntx.conn_id = 0;
    
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_ACTIVE);
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_deactivate_cnf_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_deactivate_cnf_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_DEACTIVATE_CNF);
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_IDLE);
    srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_UUID);
    srv_pbap_notify_app(SRV_PBAP_EVENT_STOP, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_sdp_deregister_cnf_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_pbap_sdp_deregister_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_cnf_struct *cnf = (bt_sdpdb_deregister_cnf_struct*) msg;
    bt_pbap_deregister_req_struct *req;
    bt_pbap_disconnect_req_struct *dis_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_SDP_DEREGISTER_CNF);
    SRV_PBAP_LOG_STATE();
    
    if (cnf->uuid != SRV_BT_CM_OBEX_PBA_PROFILE_UUID)
        return MMI_FALSE;
    
    if (cnf->result != 0x00)
    {
        SRV_PBAP_LOG1(SRV_PBAP_SERVER_SDP_DEREGISTR_FAIL_RESULT, cnf->result);
        /* SDP register Failed */
        ASSERT(0);
    }

    switch (srv_pbap_p->pbap_cntx.state)
    {
        case SRV_PBAP_STATE_DEACTIVATING:
            ASSERT(0);
            break;

        case SRV_PBAP_STATE_DISCONNECTING:
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_DEACTIVATING);
            break;

        case SRV_PBAP_STATE_BUILDING_LIST:
            if (srv_pbap_p->pbap_cntx.vcard_listing.listing_fh > FS_NO_ERROR)
            {
                FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
                srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = (FS_HANDLE) NULL;
            }
        case SRV_PBAP_STATE_CONNECTED:
        case SRV_PBAP_STATE_AUTHORIZED:
        case SRV_PBAP_STATE_BUILDING_FOLDER:
        case SRV_PBAP_STATE_BUILDING_ENTRY:
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_DEACTIVATING);

            dis_req = (bt_pbap_disconnect_req_struct*) OslConstructDataPtr(sizeof(bt_pbap_disconnect_req_struct));
            dis_req->cm_conn_id = srv_pbap_p->pbap_cntx.cm_conn_id;
            srv_pbap_send_msg(MSG_ID_BT_PBAP_DISCONNECT_REQ, dis_req);
            break;

        case SRV_PBAP_STATE_IDLE:
            return MMI_TRUE;

        case SRV_PBAP_STATE_ACTIVE:
        default:
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_DEACTIVATING);
            req = (bt_pbap_deregister_req_struct*) OslConstructDataPtr(sizeof(bt_pbap_deregister_req_struct));

            srv_pbap_send_msg(MSG_ID_BT_PBAP_DEREGISTER_REQ, req);
            break;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_disconnect_client
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  bd_addr     [IN]        
 *  conn_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_pbap_disconnect_client(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_DISCONNECT_CLIENT);
    SRV_PBAP_LOG_STATE();
	srv_pbap_p->pbap_cntx.disconnect_from_cm = MMI_TRUE;
    
    switch (srv_pbap_p->pbap_cntx.state)
    {
        case SRV_PBAP_STATE_DISCONNECTING:
            return;

        case SRV_PBAP_STATE_BUILDING_LIST:
        if (srv_pbap_p->pbap_cntx.vcard_listing.listing_fh > FS_NO_ERROR)
        {
            FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
            srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = (FS_HANDLE) NULL;
        }
        case SRV_PBAP_STATE_CONNECTED:
        case SRV_PBAP_STATE_AUTHORIZED:
        case SRV_PBAP_STATE_BUILDING_FOLDER:
        case SRV_PBAP_STATE_BUILDING_ENTRY:
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_DISCONNECTING);
        case SRV_PBAP_STATE_DEACTIVATING:

            req = (bt_pbap_disconnect_req_struct*) OslConstructDataPtr(sizeof(bt_pbap_disconnect_req_struct));
            req->cm_conn_id = srv_pbap_p->pbap_cntx.cm_conn_id;

            srv_pbap_send_msg(MSG_ID_BT_PBAP_DISCONNECT_REQ, req);
            return;
        default:                
            return;
    }
}


#define MMI_PBAP_EVENT_HDLR
/*****************************************************************************
 * FUNCTION
 *  srv_pbap_setpath_ind_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_setpath_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_set_path_ind_struct *ind = (bt_pbap_set_path_ind_struct*) ilm_ptr;
    bt_pbap_set_path_rsp_struct *rsp =
        (bt_pbap_set_path_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_set_path_rsp_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_SETPATH_HDLR);
    SRV_PBAP_LOG_STATE();

    switch (ind->type)
    {
        case PBAP_ROOT_FOLDER:
            memset(srv_pbap_p->pbap_cntx.currentPath, 0, PBAP_MAX_NAME_LEN + 1);
            rsp->result = MMI_TRUE;
            break;
            
        case PBAP_BACK_FOLDER:
                srv_pbap_backup_folder(srv_pbap_p->pbap_cntx.currentPath);
                        rsp->result = MMI_TRUE;
                        break;

        case PBAP_FORWARD_FOLDER:
            {
                U8 asc_name[PBAP_MAX_NAME_LEN/ENCODING_LENGTH + 1];

                srv_pbap_string_swapcpy((PU8) ind->name, (PU8) ind->name);
                mmi_ucs2_to_asc((S8 *) asc_name, (S8 *) ind->name);
                strcat((char*)srv_pbap_p->pbap_cntx.currentPath, (char*)asc_name);
                strcat((char*)srv_pbap_p->pbap_cntx.currentPath, "\\");
                rsp->result = MMI_TRUE;

                /*folder check*/                
                if (srv_pbap_check_folder(srv_pbap_p->pbap_cntx.currentPath) == 0)
                {
                    srv_pbap_backup_folder(srv_pbap_p->pbap_cntx.currentPath);
                    rsp->result = MMI_FALSE;
                }
            }
            break;

        default:
            rsp->result = MMI_FALSE;
            break;
    }
    srv_pbap_send_msg(MSG_ID_BT_PBAP_SET_PATH_RSP, rsp);        

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_readentry_ind_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_readentry_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_entry_ind_struct *ind = (bt_pbap_read_entry_ind_struct*) ilm_ptr;
    S32 index_num, read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_READ_ENTRY_HDLR);
    SRV_PBAP_LOG_STATE();

    /*save info*/
    srv_pbap_string_swapcpy((PU8) ind->objectName, (PU8) ind->objectName);   
    mmi_ucs2toi((S8*) ind->objectName, &index_num, &read_len);
    srv_pbap_p->pbap_cntx.vcard_entry.entry_index = (U16)index_num;
    
    memcpy(srv_pbap_p->pbap_cntx.vcard_entry.filter.byte, ind->filter.byte, PBAP_FILTER_SIZE);
    srv_pbap_p->pbap_cntx.vcard_entry.format = ind->format;

    /*check the storage*/
    srv_pbap_p->pbap_cntx.pb_storage = srv_pbap_get_pbtype(srv_pbap_p->pbap_cntx.currentPath, NULL);
    if (srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_TOTAL) //< 0)
    {
        bt_pbap_read_entry_rsp_struct *rsp =
            (bt_pbap_read_entry_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_entry_rsp_struct));

        rsp->result = PB_STATUS_NOT_SUPPORTED;
        srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_ENTRY_RSP, rsp);
        return;
    }

    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_BUILDING_ENTRY);
    srv_pbap_provide_entry();

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_readfolder_ind_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_readfolder_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_folder_ind_struct *ind = (bt_pbap_read_folder_ind_struct*) ilm_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_READ_FOLDER_HDLR);
    SRV_PBAP_LOG_STATE();

    if (ind->to_self && srv_pbap_p->pbap_cntx.state == SRV_PBAP_STATE_BUILDING_FOLDER)
    {
        srv_pbap_write_one_entry(
            srv_pbap_p->pbap_cntx.g_index_list[srv_pbap_p->pbap_cntx.vcard_folder.new_index],
            srv_pbap_p->pbap_cntx.pb_storage,
            PBAP_ADP_FOLDER_FILE,
            srv_pbap_p->pbap_cntx.vcard_folder.filter.byte,
            srv_pbap_p->pbap_cntx.vcard_folder.format,
            MMI_TRUE,
            srv_pbap_write_folder_entry_cbk);
        return;
    }

    srv_pbap_string_swapcpy((PU8) ind->pbName, (PU8) ind->pbName);
    mmi_ucs2_to_asc((S8 *) srv_pbap_p->pbap_cntx.vcard_folder.folderName, (S8 *) ind->pbName);

    memcpy(srv_pbap_p->pbap_cntx.vcard_folder.filter.byte, ind->filter.byte, PBAP_FILTER_SIZE);
    srv_pbap_p->pbap_cntx.vcard_folder.format = ind->format;
    srv_pbap_p->pbap_cntx.vcard_folder.maxListCount = ind->maxListCount;
    srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset = ind->listStartOffset;
    
    srv_pbap_p->pbap_cntx.pb_storage = srv_pbap_get_pbtype((S8*)srv_pbap_p->pbap_cntx.vcard_folder.folderName, NULL);
    if (srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_TOTAL)
    {
        bt_pbap_read_folder_rsp_struct *rsp =
            (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));

        rsp->result = PB_STATUS_NOT_FOUND;
        srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);
        return;
    }

    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_BUILDING_FOLDER);
    if (ind->maxListCount == 0)
    {
        mmi_phb_get_storage_size(srv_pbap_p->pbap_cntx.pb_storage, srv_pbap_get_fodler_size_cbk);
    }
    else
    {
        srv_pabp_provide_folder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_readlist_ind_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_readlist_ind_hdlr(void *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs_folder_name[PBAP_MAX_NAME_LEN + 1];
    bt_pbap_read_list_ind_struct *ind = (bt_pbap_read_list_ind_struct*) ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_READ_LIST_HDLR);
    SRV_PBAP_LOG_STATE();
    
/*
    1. save  info
    2. check storage
    3. provide size or data
*/
    if (ind->to_self && srv_pbap_p->pbap_cntx.state == SRV_PBAP_STATE_BUILDING_LIST)
    {
        if (srv_pbap_p->pbap_cntx.vcard_listing.curr_index < MMI_PHB_PHONE_ENTRIES - 1)
        {
            mmi_phb_get_info_by_index(
                srv_pbap_p->pbap_cntx.g_index_list[srv_pbap_p->pbap_cntx.vcard_listing.curr_index + 1],
                srv_pbap_p->pbap_cntx.pb_storage,
                srv_pbap_get_info_cbk);
        }
        

        return; 
    }
    /*save  info*/
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*) srv_pbap_p->pbap_cntx.vcard_listing.searchValue,
        (MAX_PBAP_SEARCH_VALUE_LENGTH + 1) * ENCODING_LENGTH,
        (kal_uint8*) ind->searchValue);

    srv_pbap_p->pbap_cntx.vcard_listing.searchValueLength = 
        (ind->searchValueLength >= MAX_PBAP_SEARCH_VALUE_LENGTH)? MAX_PBAP_SEARCH_VALUE_LENGTH : ind->searchValueLength;
    srv_pbap_p->pbap_cntx.vcard_listing.searchAttribute = ind->searchAttribute;
    srv_pbap_p->pbap_cntx.vcard_listing.order = ind->order;
    srv_pbap_p->pbap_cntx.vcard_listing.maxListCount = ind->maxListCount;
    srv_pbap_p->pbap_cntx.vcard_listing.listStartOffset = ind->listStartOffset;

    /*check storage*/
    srv_pbap_string_swapcpy((PU8) ucs_folder_name, (PU8) ind->folderName);
    mmi_ucs2_to_asc((S8 *) srv_pbap_p->pbap_cntx.vcard_listing.folderName, (S8 *) ucs_folder_name);

    srv_pbap_p->pbap_cntx.pb_storage = srv_pbap_get_pbtype((S8*)srv_pbap_p->pbap_cntx.currentPath, (S8*)srv_pbap_p->pbap_cntx.vcard_listing.folderName);
    if (srv_pbap_p->pbap_cntx.pb_storage ==  PHB_STORAGE_TOTAL) //< 0)
    {
        bt_pbap_read_list_rsp_struct *rsp =
            (bt_pbap_read_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct));

        rsp->result = PB_STATUS_NOT_FOUND;
        srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);
        return;
    }

    /*provide size or data*/
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_BUILDING_LIST);
    if (ind->maxListCount == 0)
    {
        mmi_phb_get_storage_size(srv_pbap_p->pbap_cntx.pb_storage, srv_pbap_get_list_size_cbk);
    }
    else
    {
        srv_pabp_provide_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_connect_ind_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_connect_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_connect_ind_struct *ind = (bt_pbap_connect_ind_struct*) ilm_ptr;
    srv_pbap_conn_notify_struct conn_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_CONNECT_IND_HDLR);
    SRV_PBAP_LOG_STATE();
    
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_AUTHORIZED)
    {
        SRV_PBAP_LOG(SRV_PBAP_CONNECT_IND_STATE_ERROR);
        srv_pbap_connect_rsp_hdlr(PBAP_CNF_FAILED);
        return;
    }

    srv_pbap_p->pbap_cntx.cm_conn_id = ind->cm_conn_id;

    memset(srv_pbap_p->pbap_cntx.currentPath, 0, PBAP_MAX_NAME_LEN + 1);

 
    srv_pbap_connect_rsp_hdlr(PBAP_CNF_SUCCESS);

    srv_bt_cm_connect_ind(srv_pbap_p->pbap_cntx.conn_id);

    conn_notify.conn_id = ind->cm_conn_id;
    conn_notify.bt_addr.lap = ind->bd_addr.lap;
    conn_notify.bt_addr.uap = ind->bd_addr.uap;
    conn_notify.bt_addr.nap = ind->bd_addr.nap;
    //strcpy((S8*)conn_notify.dev_name,(S8*) srv_pbap_p->pbap_cntx.pbap_dev_name);

    srv_pbap_notify_app(SRV_PBAP_EVENT_CONN_NOTIFY, (void *) &conn_notify);
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_connect_rsp_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_connect_rsp_hdlr(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_connect_rsp_struct *rsp =
        (bt_pbap_connect_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_connect_rsp_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG1(SRV_PBAP_SERVER_CONNECT_RSP_HDLR, rsp->cnf_code);
    
    rsp->cnf_code = result;
    rsp->cm_conn_id = srv_pbap_p->pbap_cntx.cm_conn_id;

    srv_pbap_send_msg(MSG_ID_BT_PBAP_CLIENT_CONNECT_RSP, rsp);

    if (result == PBAP_CNF_SUCCESS)
    {
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    }
    else
    {
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_ACTIVE);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_disconnect_ind_hdlr
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_disconnect_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_deregister_req_struct *req;
    //srv_pbap_disconn_notify_struct disconn_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_DISCONNECT_IND_HDLR);
    SRV_PBAP_LOG_STATE();

    switch (srv_pbap_p->pbap_cntx.state)
    {
		case SRV_PBAP_STATE_AUTHORIZING:
        case SRV_PBAP_STATE_AUTHORIZED:
			srv_pbap_p->pbap_cntx.disconnect_from_cm = MMI_TRUE;
        case SRV_PBAP_STATE_DEACTIVATING:
            /* send DEACTIVATE_REQ to BT */
            req = (bt_pbap_deregister_req_struct*) OslConstructDataPtr(sizeof(bt_pbap_deregister_req_struct));
            srv_pbap_send_msg(MSG_ID_BT_PBAP_DEREGISTER_REQ, req);

            srv_pbap_connection_terminated();

            return;


        case SRV_PBAP_STATE_BUILDING_LIST:
            if (srv_pbap_p->pbap_cntx.vcard_listing.listing_fh > FS_NO_ERROR)
            {
                FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
                srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = (FS_HANDLE) NULL;
            }
        case SRV_PBAP_STATE_BUILDING_ENTRY:
        case SRV_PBAP_STATE_BUILDING_FOLDER:
        case SRV_PBAP_STATE_CONNECTED:
        case SRV_PBAP_STATE_DISCONNECTING:
            /* reset context */
            srv_pbap_connection_terminated();
            return;
            /* not connected yet */
        default:
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_auth_ind_hdlr
 * DESCRIPTION
 *  auth indication hdlr
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_auth_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_auth_ind_struct *ind = (bt_pbap_auth_ind_struct*) ilm_ptr;
    srv_pbap_authentication_notify_struct authentication_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_SERVER_AUTH_IND_HDLR);
    SRV_PBAP_LOG_STATE();

    //strcpy((S8*) srv_pbap_p->pbap_cntx.pbap_dev_name, (S8*) ind->dev_name);

    strcpy((S8*) authentication_notify.dev_name, (S8*) ind->dev_name);

    srv_pbap_notify_app(SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY, (void *)&authentication_notify);
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_abort_ind_hdlr
 * DESCRIPTION
 *  abort indication hdlr
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_abort_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_pbap_p->pbap_cntx.state == SRV_PBAP_STATE_BUILDING_LIST)
    {
        if (srv_pbap_p->pbap_cntx.vcard_listing.listing_fh > FS_NO_ERROR)
        {
            FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
            srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = (FS_HANDLE) NULL;
        }
    }

    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
}

#define MMI_PBAP_AUTH
/*****************************************************************************
 * FUNCTION
 *  srv_pbap_auth_send
 * DESCRIPTION
 *  This function is to send a authentication response to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_authentication_rsp(U8 *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_auth_cnf_struct * rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    rsp = (bt_pbap_auth_cnf_struct*)OslConstructDataPtr(sizeof(bt_pbap_auth_cnf_struct));

    if (password != NULL)
    {
        strcpy((S8*)rsp->password, (S8*)password);
        rsp->cancel = MMI_FALSE;
    }
    else
    {
        rsp->cancel = MMI_TRUE;
    }
    //memcpy(rsp->password, tmp_ascii_buf, passwd_len);
    
    /* send authentication response to BT */
    srv_pbap_send_msg(MSG_ID_BT_PBAP_CLIENT_AUTH_CHALLENGE_CNF, rsp); 
}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_authrize_ind_hdlr(void *ilm_ptr)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_authorize_ind_struct *ind = (bt_pbap_authorize_ind_struct*) ilm_ptr;
    srv_pbap_auth_notify_struct auth_notify;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_AUTHRIZE_IND_HDLR);
    SRV_PBAP_LOG_STATE();
    
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_ACTIVE)
    {
        SRV_PBAP_LOG(SRV_PBAP_AUTHRIZE_IND_STATE_ERROR);
        srv_pbap_authrize_rsp(PBAP_CNF_FAILED);
        return;
    }

    memcpy(&srv_pbap_p->pbap_cntx.bt_device, &ind->bd_addr, sizeof(srv_bt_cm_bt_addr));

    srv_pbap_p->pbap_cntx.conn_id = srv_bt_cm_start_conn(
                                        MMI_FALSE,
                                        SRV_BT_CM_OBEX_PBA_PROFILE_UUID,
                                        (srv_bt_cm_bt_addr*)&ind->bd_addr,
                                        ind->dev_name);
    if (srv_pbap_p->pbap_cntx.conn_id > 0)
    {
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_AUTHORIZING);
    
    auth_notify.bt_addr = srv_pbap_p->pbap_cntx.bt_device;
    strcpy((S8*)auth_notify.dev_name,(S8*) ind->dev_name);
    
    srv_pbap_notify_app(SRV_PBAP_EVENT_AUTHORIZE_NOTIFY, (void *)&auth_notify);
    }
    else
    {
        srv_pbap_authrize_rsp(PBAP_CNF_FAILED);
    }
}



static void srv_pbap_authrize_rsp(U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_authorize_rsp_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send response */
    res = (bt_pbap_authorize_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_authorize_rsp_struct));
    res->cnf_code = rsp_code;

    srv_pbap_send_msg(MSG_ID_BT_PBAP_AUTHORIZE_RSP, res);

    if (rsp_code == PBAP_CNF_SUCCESS)
    {
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_AUTHORIZED);
    }
    else
    {
		srv_bt_cm_stop_conn(srv_pbap_p->pbap_cntx.conn_id);
		srv_pbap_p->pbap_cntx.conn_id = 0;
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_ACTIVE);		
    }

}


#define MMI_PBAP_BUILD_ENTRY


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *      1. error check
    2. get the first data

 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_provide_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_entry_rsp_struct *rsp;
    FS_HANDLE fh;
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_PROVIDE_ENTRY);
    /*get the first entry info*/
    fh = FS_Open((U16*) PBAP_ADP_ENTRY_FILE, FS_READ_WRITE |FS_CREATE_ALWAYS);
    SRV_PBAP_LOG1(SRV_PBAP_PROVIDE_ENTRY_FS_OPEN, fh);
    if (fh < FS_NO_ERROR)
    {
        ret = PB_STATUS_FAILED;
        goto ERROR;
    }
    FS_Close(fh);

    srv_pbap_write_one_entry(
        srv_pbap_p->pbap_cntx.vcard_entry.entry_index,
        srv_pbap_p->pbap_cntx.pb_storage,
        PBAP_ADP_ENTRY_FILE,
        srv_pbap_p->pbap_cntx.vcard_entry.filter.byte,
        srv_pbap_p->pbap_cntx.vcard_entry.format,
        MMI_FALSE,
        srv_pbap_write_entry_cbk);
    return;

ERROR:
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    rsp = (bt_pbap_read_entry_rsp_struct *) OslConstructDataPtr(sizeof(bt_pbap_read_entry_rsp_struct ));
    rsp->result = ret;

    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_ENTRY_RSP, rsp);    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_write_entry_cbk(mmi_phb_vcard_error_struct* error_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_entry_rsp_struct *rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG2(SRV_PBAP_WRITE_ENTRY_CBK, error_info->error_code, error_info->fs_error);
/*
    error check
*/
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_ENTRY)
    {
        return;
    }

    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    rsp = (bt_pbap_read_entry_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_entry_rsp_struct));
    rsp->result = srv_pbap_get_phb_err_code(error_info);
    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_ENTRY_RSP, rsp);    
}


#define MMI_PBAP_BUILD_FOLDER


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_build_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pabp_provide_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_PROVIDE_FOLDER);
    if(!srv_pbap_p->pbap_cntx.index_array_got || 
        srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset == 0)
    {
        mmi_phb_get_index_array(
            srv_pbap_p->pbap_cntx.pb_storage,
            PHB_SORT_ORDER_NONE, 
            srv_pbap_p->pbap_cntx.g_index_list, 
            MMI_PHB_PHONE_ENTRIES*2,
            srv_pbap_get_folder_array_cbk);
    }
    else
    {
        srv_pbap_p->pbap_cntx.completed_count = 0;

        if (srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset > srv_pbap_p->pbap_cntx.pb_size - 1 ||
            srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset > MMI_PHB_PHONE_ENTRIES - 1)
        {
            bt_pbap_read_folder_rsp_struct *rsp;

            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
            rsp = (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));
            rsp->result = PB_STATUS_NOT_FOUND;
            srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);    
            return;
        }
        else
        {
            srv_pbap_write_one_entry(
                srv_pbap_p->pbap_cntx.g_index_list[srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset],
                srv_pbap_p->pbap_cntx.pb_storage,
                PBAP_ADP_FOLDER_FILE,
                srv_pbap_p->pbap_cntx.vcard_folder.filter.byte,
                srv_pbap_p->pbap_cntx.vcard_folder.format,
                MMI_FALSE,
                srv_pbap_write_folder_entry_cbk);
        }
        
    }

}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_folder_array_cbk(mmi_phb_vcard_error_struct* error_info, U16* array, U16 array_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_folder_rsp_struct *rsp;
    U16 start_index = srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset;
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG3(SRV_PBAP_GET_FOLDER_ARRAY_CBK, error_info->error_code, error_info->fs_error, array_size);
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_FOLDER)
    {
        return;
    }

    if (error_info->error_code == PHB_VCARD_NO_ERROR
        && array_size > 0)
    {
        fh = FS_Open((U16*) PBAP_ADP_FOLDER_FILE, FS_READ_WRITE |FS_CREATE_ALWAYS);
        SRV_PBAP_LOG1(SRV_PBAP_GET_FOLDER_ARRAY_CBK_FS_OPEN, fh);
        if (fh < FS_NO_ERROR)
        {
            error_info->error_code = PHB_VCARD_IN_USE;
            goto ERROR;
        }
        FS_Close(fh);

        srv_pbap_p->pbap_cntx.index_array_got = MMI_TRUE;
        srv_pbap_p->pbap_cntx.completed_count = 0;
        srv_pbap_p->pbap_cntx.pb_size = array_size;

        if (start_index > array_size - 1)
        {
            error_info->error_code = PHB_VCARD_NOT_FOUND;
            goto ERROR;
        }
        srv_pbap_write_one_entry(
            srv_pbap_p->pbap_cntx.g_index_list[start_index],
            srv_pbap_p->pbap_cntx.pb_storage,
            PBAP_ADP_FOLDER_FILE,
            srv_pbap_p->pbap_cntx.vcard_folder.filter.byte,
            srv_pbap_p->pbap_cntx.vcard_folder.format,
            MMI_FALSE,
            srv_pbap_write_folder_entry_cbk);
    }
    else
    {
        if (array_size == 0)
        {
            error_info->error_code = PHB_VCARD_NOT_FOUND;
        }
        goto ERROR;
    }
    return;

ERROR:
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    rsp = (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));
    rsp->result = srv_pbap_get_phb_err_code(error_info);
    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);    

}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_write_folder_entry_cbk(mmi_phb_vcard_error_struct* error_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_folder_rsp_struct *rsp;
    U16 block_count = 
        (srv_pbap_p->pbap_cntx.pb_size - srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset < srv_pbap_p->pbap_cntx.vcard_folder.maxListCount) 
        ? srv_pbap_p->pbap_cntx.pb_size - srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset
        : srv_pbap_p->pbap_cntx.vcard_folder.maxListCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG2(SRV_PBAP_WRITE_FOLDER_ENTRY_CBK, error_info->error_code, error_info->fs_error);
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_FOLDER)
    {
        srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
        return;
    }

    srv_pbap_p->pbap_cntx.completed_count++;

    if (error_info->error_code == PHB_VCARD_IN_USE
        || error_info->error_code == PHB_VCARD_FS_ERROR)
    {
        srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
        goto ERROR;
    }
    else if (srv_pbap_p->pbap_cntx.completed_count < block_count)
    {
        /*next control*/
        bt_pbap_read_folder_ind_struct *ind;
        srv_pbap_p->pbap_cntx.vcard_folder.new_index = srv_pbap_p->pbap_cntx.vcard_folder.listStartOffset + srv_pbap_p->pbap_cntx.completed_count;

        if (srv_pbap_p->pbap_cntx.vcard_folder.new_index > srv_pbap_p->pbap_cntx.pb_size - 1)
        {
            error_info->error_code = PHB_VCARD_NOT_FOUND;
            goto ERROR;
        }
        //send msg to self
        ind = (bt_pbap_read_folder_ind_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_ind_struct));
        ind->to_self = 1;
        srv_pbap_send_msg_self(MSG_ID_BT_PBAP_READ_FOLDER_IND, ind);
        return;
    }
    else
    {
        /*complete*/
         srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
 
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        {
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);

            rsp = (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));
            rsp->result = PB_STATUS_SUCCESS;
            rsp->phoneBookSize = 0xFFFF;
            rsp->newMissedCalls = 0xFFFF;
            srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);    
        }
    }
    return ;

ERROR:
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    rsp = (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));
    rsp->result = srv_pbap_get_phb_err_code(error_info);
    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);    

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_build_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_fodler_size_cbk(mmi_phb_vcard_error_struct* error_info, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_folder_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG3(SRV_PBAP_GET_FOLDER_SIZE_CBK, error_info->error_code, error_info->fs_error, size);
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_FOLDER)
    {
        return;
    }
    
    if (error_info->error_code == PHB_VCARD_NO_ERROR)
    {
        srv_pbap_p->pbap_cntx.pb_size = size;

        if (srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_SIM1_MCH 
            || srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_NVRAM_MCH)
        {
            srv_pbap_get_new_missed_calls(srv_pbap_p->pbap_cntx.pb_size, srv_pbap_get_folder_mcsize_cbk);
        }
        else
        {
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
            rsp = (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));
            rsp->phoneBookSize = size;
            rsp->newMissedCalls = 0xFFFF;
            rsp->result = PB_STATUS_SUCCESS;
            srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);
        }
    }
    else
    {
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
        rsp = (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));
        rsp->result = srv_pbap_get_phb_err_code(error_info);
        srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);    
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_build_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_folder_mcsize_cbk(mmi_phb_vcard_error_struct* error_info, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_folder_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG3(SRV_PBAP_GET_FOLDER_MCSIZE_CBK, error_info->error_code, error_info->fs_error, size);
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_FOLDER)
    {
        return;
    }

    rsp = (bt_pbap_read_folder_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_folder_rsp_struct));
    if (error_info->error_code == PHB_VCARD_NO_ERROR)
    {
        rsp->phoneBookSize = size;
        //rsp->newMissedCalls = size;
        rsp->newMissedCalls = 0xFFFF;
        rsp->result = PB_STATUS_SUCCESS;
    }
    else
    {
        rsp->result = srv_pbap_get_phb_err_code(error_info);
    }

    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_FOLDER_RSP, rsp);    

}

#define MMI_PBAP_BUILD_LIST
/*****************************************************************************
 * FUNCTION
 *  srv_pbap_build_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pabp_provide_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_PROVIDE_LIST);
    /*get list or read data*/
    if(!srv_pbap_p->pbap_cntx.index_array_got || 
        srv_pbap_p->pbap_cntx.vcard_listing.listStartOffset == 0)
    {
        U8 sort_order;

        sort_order = srv_pbap_get_phb_order(srv_pbap_p->pbap_cntx.vcard_listing.order);
        mmi_phb_get_index_array(
            srv_pbap_p->pbap_cntx.pb_storage,
            sort_order, 
            srv_pbap_p->pbap_cntx.g_index_list, 
            MMI_PHB_PHONE_ENTRIES*2,
            srv_pbap_get_list_array_cbk);
    }
    else
    {
        srv_pbap_p->pbap_cntx.completed_count = 0;
        
        if (srv_pbap_p->pbap_cntx.vcard_listing.listStartOffset > srv_pbap_p->pbap_cntx.pb_size - 1 ||
            srv_pbap_p->pbap_cntx.vcard_listing.listStartOffset > MMI_PHB_PHONE_ENTRIES - 1)
        {
            bt_pbap_read_folder_rsp_struct *rsp;

            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
            rsp = (bt_pbap_read_list_rsp_struct *) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct ));
            rsp->result = PB_STATUS_NOT_FOUND;
            srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);    

            return;
        }
        else
        {
            mmi_phb_get_info_by_index(
                srv_pbap_p->pbap_cntx.g_index_list[srv_pbap_p->pbap_cntx.vcard_listing.listStartOffset],
                srv_pbap_p->pbap_cntx.pb_storage,
                srv_pbap_get_info_cbk);
        }
        
    }

}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_list_array_cbk(mmi_phb_vcard_error_struct* error_info, U16* array, U16 array_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_list_rsp_struct *rsp;
    U16 start_index = srv_pbap_p->pbap_cntx.vcard_listing.listStartOffset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG3(SRV_PBAP_GET_LIST_ARRAY_CBK, error_info->error_code, error_info->fs_error, array_size);

/*
    1. error check
    2. get the first data
*/
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_LIST)
    {
        return;
    }

    /*error check*/
    MMI_ASSERT(array == srv_pbap_p->pbap_cntx.g_index_list);
    
    if (error_info->error_code == PHB_VCARD_NO_ERROR
        && array_size > 0)
    {
        /*create file and write the header*/
        if(srv_pbap_compose_list_header() != PB_STATUS_SUCCESS)
        {
            error_info->error_code = PHB_VCARD_IN_USE;
            goto ERROR;
        }

        /*get the first entry info*/
        srv_pbap_p->pbap_cntx.index_array_got = MMI_TRUE;
        srv_pbap_p->pbap_cntx.completed_count = 0;
        srv_pbap_p->pbap_cntx.pb_size = array_size;

        mmi_phb_get_info_by_index(
            srv_pbap_p->pbap_cntx.g_index_list[start_index],
            srv_pbap_p->pbap_cntx.pb_storage,
            srv_pbap_get_info_cbk);
    }
    else
    {
        if (array_size == 0)
        {
            error_info->error_code = PHB_VCARD_NOT_FOUND;
        }
        goto ERROR;
    }
    return;

ERROR:
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    rsp = (bt_pbap_read_list_rsp_struct *) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct ));
    rsp->result = srv_pbap_get_phb_err_code(error_info);
    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);    
}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_info_cbk(mmi_phb_vcard_error_struct* error_info, S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_list_rsp_struct *rsp;
    U16 block_count = 
        (srv_pbap_p->pbap_cntx.pb_size < srv_pbap_p->pbap_cntx.vcard_listing.maxListCount) 
        ? srv_pbap_p->pbap_cntx.pb_size
        : srv_pbap_p->pbap_cntx.vcard_listing.maxListCount;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG2(SRV_PBAP_GET_INFO_CBK, error_info->error_code, error_info->fs_error);
/*
    1.error check
    2.data check and write to file
    3.get the next entry info
*/
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_LIST)
    {
        srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
        return;
    }
    
    /*error check*/
    MMI_ASSERT(error_info->error_code != PHB_VCARD_IN_USE);

//in use, not found ,run
    if (error_info->error_code != PHB_VCARD_NO_ERROR)
    {
        goto ERROR;
    }

    /*data check and write to file*/
    srv_pbap_p->pbap_cntx.vcard_listing.curr_index = srv_pbap_p->pbap_cntx.vcard_listing.listStartOffset + srv_pbap_p->pbap_cntx.completed_count;
    if (PB_STATUS_SUCCESS != srv_pbap_compose_list_middle(
                                                    srv_pbap_p->pbap_cntx.g_index_list[srv_pbap_p->pbap_cntx.vcard_listing.curr_index], 
                                                    srv_pbap_p->pbap_cntx.vcard_listing,
                                                    (U16*)name, 
                                                    (U16*)number))
    {
        error_info->error_code = PHB_VCARD_IN_USE;
        goto ERROR;
    }

    /*next control*/
    srv_pbap_p->pbap_cntx.completed_count++;
    if (srv_pbap_p->pbap_cntx.completed_count < block_count)
    {
        bt_pbap_read_list_ind_struct *ind;
        /*send msg to myself*/
        ind = (bt_pbap_read_list_ind_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_list_ind_struct));
        ind->to_self = 1;
        srv_pbap_send_msg_self(MSG_ID_BT_PBAP_READ_LIST_IND, ind);
        return;
    }
    else
    {
        srv_pbap_compose_list_tail();
        srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;

        if (srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_NVRAM_MCH
            || srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_SIM1_MCH)
        {
            srv_pbap_get_new_missed_calls(srv_pbap_p->pbap_cntx.pb_size, srv_pbap_get_list_mcsize_cbk);
        }
        else
        {
            srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);

            rsp = (bt_pbap_read_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct));
            rsp->result = PB_STATUS_SUCCESS;
            rsp->phoneBookSize = 0xFFFF;
            rsp->newMissedCalls = 0xFFFF;
            srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);    
        }
    }
    return;

ERROR:
    if (srv_pbap_p->pbap_cntx.vcard_listing.listing_fh > FS_NO_ERROR)
    {
        FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
        srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = (FS_HANDLE) NULL;
    }

    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    srv_pbap_p->pbap_cntx.index_array_got = MMI_FALSE;
    rsp = (bt_pbap_read_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct));
    rsp->result = srv_pbap_get_phb_err_code(error_info);
    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_build_list_handler_header
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static PbStatus srv_pbap_compose_list_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_len;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_COMPOSE_LIST_HEADER);
/*
   1.create file
   2.write the header
   3. 
    */

    /*create file and write heade to file*/
    srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = FS_Open((U16*) PBAP_ADP_LIST_FILE, FS_CREATE_ALWAYS|FS_READ_WRITE);

    if (srv_pbap_p->pbap_cntx.vcard_listing.listing_fh >= FS_NO_ERROR)
    {
        result = FS_Write(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh, 
                          BEGIN_XML_DECL, strlen(BEGIN_XML_DECL), 
                          (U32*) & write_len);
        if (result >= FS_NO_ERROR)
        {
            result = FS_Write(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh, 
                          BEGIN_FOLDER_DECL, strlen(BEGIN_FOLDER_DECL), 
                          (U32*) & write_len);
        }


        if (result < FS_NO_ERROR)
        {
            FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
            srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = (FS_HANDLE) NULL;
            return PB_STATUS_FAILED;
        }
        return PB_STATUS_SUCCESS;
    }
    else
    {
        return PB_STATUS_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_compose_list_middle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static PbStatus srv_pbap_compose_list_middle(
                    U16 index,
                    PbPullVcardListingOp vcard_listing,
                    const U16* pb_name, 
                    const U16* pb_number_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PbStatus result;
    MMI_BOOL compare_ret = MMI_FALSE;
    const U16 * pb_name_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_COMPOSE_LIST_MIDDLE);
/*
    pre: header has been writed to file
    1. compare the data and write to file
*/
    /*if no name, use number directly*/
    pb_name_str = pb_name;
    if (pb_name_str == NULL || *pb_name_str == 0)
    {
        pb_name_str = pb_number_str;
    }

    if (pb_name_str == NULL || *pb_name_str == 0)
    {
        pb_name_str = L"Myself";
    }

    /*data check*/
    switch(vcard_listing.searchAttribute)
    {
        case PBAP_SEARCH_ATTRIB_NAME:
            
            if (mmi_ucs2cmp((S8 *)vcard_listing.searchValue, (S8 *)pb_name_str) == 0
                || vcard_listing.searchValueLength == 0)
            {
                compare_ret = MMI_TRUE;
            }
            break;

        case PBAP_SEARCH_ATTRIB_NUMBER:
            {
                //S8 original_num[MAX_PBAP_SEARCH_VALUE_LENGTH + 1];
                //S8 phb_num[MAX_PBAP_SEARCH_VALUE_LENGTH + 1];
                if (pb_number_str != NULL)
                {
                    //mmi_ucs2_to_asc(original_num, (S8*)(vcard_listing.searchValue));
                    //mmi_ucs2_to_asc(phb_num, (S8*)pb_number_str);

                    if(srv_phb_compare_number((U16 *)pb_number_str, (U16 *)vcard_listing.searchValue))
                    {
                        compare_ret = MMI_TRUE;
                    }
                }
            }
            break;

        case PBAP_SEARCH_ATTRIB_SOUND:
            compare_ret = MMI_FALSE; /*None data*/
            break;
    }

    /*write to file*/
    if (compare_ret)
    {
        result = srv_pbap_compose_list_element(index, (S8*)pb_name_str);
    }
    else
    {
        result = PB_STATUS_SUCCESS;
    }
    return result;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_build_list_handler_middle
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  hdlr        [IN]        
 *  name        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static PbStatus srv_pbap_compose_list_element(U16 hdlr, S8 *name)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_len;
    U32 object_len;
    S8 *object;
    S32 result;
    U8 temp_buff[MMI_PHB_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_COMPOSE_LIST_ELEMENT);
    object = OslMalloc(PBAP_BUILD_LIST_BUFFER);
    
    /* Header */
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    mmi_chset_ucs2_to_utf8_string((U8*)temp_buff, MMI_PHB_NAME_LENGTH + 1, (U8*)name);

    sprintf(object, "%s%i%s%s%s", 
            BEGIN_HANDLE,
            hdlr,
            MIDDLE_HANDLE,
            temp_buff,
            END_HANDLE);
#endif

    object_len = strlen(object);
    result = FS_Write(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh, object, object_len, (U32*) & write_len);
    SRV_PBAP_LOG1(SRV_PBAP_COMPOSE_LIST_ELEMENT_FS_WRITE, result);
    OslMfree(object);

    if (result < FS_NO_ERROR)
    {
        FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
        srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = (FS_HANDLE) NULL;
        return PB_STATUS_FAILED;
    }

    return PB_STATUS_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_build_list_handler_tail
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static PbStatus srv_pbap_compose_list_tail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_len;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG(SRV_PBAP_COMPOSE_LIST_LIST_TAIL);
    result = FS_Write(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh, 
                      END_FOLDER_DECL, strlen(END_FOLDER_DECL), 
                      (U32*) & write_len);
    SRV_PBAP_LOG1(SRV_PBAP_COMPOSE_LIST_LIST_TAIL_FS_WRITE, result);    
    FS_Close(srv_pbap_p->pbap_cntx.vcard_listing.listing_fh);
     srv_pbap_p->pbap_cntx.vcard_listing.listing_fh = 0;

    return PB_STATUS_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_build_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_list_size_cbk(mmi_phb_vcard_error_struct* error_info, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_list_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG3(SRV_PBAP_GET_LIST_SIZE_CBK, error_info->error_code, error_info->fs_error, size);
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_LIST)
    {
        return;
    }

    if (error_info->error_code == PHB_VCARD_NO_ERROR)
    {
        /*success*/
        srv_pbap_p->pbap_cntx.pb_size = size;

        if (srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_SIM1_MCH 
            || srv_pbap_p->pbap_cntx.pb_storage == PHB_STORAGE_NVRAM_MCH)
        {
            srv_pbap_get_new_missed_calls(srv_pbap_p->pbap_cntx.pb_size, srv_pbap_get_list_mcsize_cbk);
        }
        else
        {
            SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
            rsp = (bt_pbap_read_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct));
            rsp->phoneBookSize = size;
            rsp->newMissedCalls = 0xFFFF;
            rsp->result = PB_STATUS_SUCCESS;
            srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);
        }
    }
    else
    {
        /*error*/
        SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
        rsp = (bt_pbap_read_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct));
        rsp->result = srv_pbap_get_phb_err_code(error_info);
        srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);    
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_build_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_list_mcsize_cbk(mmi_phb_vcard_error_struct* error_info, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbap_read_list_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG3(SRV_PBAP_GET_LIST_MCSIZE_CBK, error_info->error_code, error_info->fs_error, size);
    if (srv_pbap_p->pbap_cntx.state != SRV_PBAP_STATE_BUILDING_LIST)
    {
        return;
    }

    rsp = (bt_pbap_read_list_rsp_struct*) OslConstructDataPtr(sizeof(bt_pbap_read_list_rsp_struct));
    if (error_info->error_code == PHB_VCARD_NO_ERROR)
    {
        rsp->phoneBookSize = 0xFFFF;
        rsp->newMissedCalls = size;
        rsp->result = PB_STATUS_SUCCESS;
    }
    else
    {
        rsp->result = srv_pbap_get_phb_err_code(error_info);
    }
    SRV_PBAP_STATE_TRANS(SRV_PBAP_STATE_CONNECTED);
    srv_pbap_send_msg(MSG_ID_BT_PBAP_READ_LIST_RSP, rsp);    

}


#define MMI_PBAP_UTILS

/*****************************************************************************
 * FUNCTION
 *  srv_oppc_post_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 *  para            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_pbap_post_proc(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_event_struct *evt = (srv_pbap_event_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_pbap_notify_app(evt->event_id, NULL);

    if (evt->data != NULL)
    {
        OslMfree(evt->data);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_send_msg(U32 msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*ilm_struct *ilm_send;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*ilm_send = allocate_ilm(MOD_MMI);
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = MOD_BT;
    ilm_send->sap_id = BT_PBAP_SAP;
    ilm_send->msg_id = (kal_uint16) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_send);*/
	srv_bt_cm_send_msg(MOD_BT, BT_PBAP_SAP, msg_id, (void*)p_local_para, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_send_msg_self
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_send_msg_self(U32 msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_bt_cm_send_msg(MOD_MMI, BT_PBAP_SAP, msg_id, (void*)p_local_para, NULL);
}




/*****************************************************************************
 * FUNCTION
 *  srv_pbap_get_pbtype
 * DESCRIPTION
 *  This function is used to get the storage of phonebook.
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  S8 *sub_folder: ASCII encoding, if have no sub_folder, give a NULL pointer or empty string
 * RETURNS
 *  void
 *****************************************************************************/
static S8 srv_pbap_get_pbtype(S8 *path, S8 *sub_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 absolute_path[PBAP_MAX_NAME_LEN + 1];
    mmi_phb_storage_enum pb_storage = PHB_STORAGE_TOTAL; //PHB_STORAGE_ERROR;
    PbPathFlags pathFlags = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path);

    memset(absolute_path, 0, PBAP_MAX_NAME_LEN+1);    
    strcpy(absolute_path, path);
    if(sub_folder)
    {
        strcat(absolute_path, sub_folder);
    }

    /*get the path flag, and then get type*/
    pathFlags = srv_pbap_get_path_flag(absolute_path);
    pb_storage = srv_pbap_flag2type(pathFlags);

    SRV_PBAP_LOG1(SRV_PBAP_SERVER_VERIFY_PATH_RESULT, pb_storage);
    return pb_storage;
}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static PbPathFlags srv_pbap_get_path_flag(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *curPos;
    U16 i, strLen;
    PbPathFlags pathFlags = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path);

    i = 0;
    curPos = path;
    strLen = strlen(path);
    if ((path[i] != '\\') || (path[i] != '/'))
    {
        if (memcmp(curPos, "telecom", 7) == 0)
        {
            pathFlags |= PB_PATH_TELECOM;
        }
        else if (memcmp(curPos, "SIM1", 4) == 0)
        {
            pathFlags |= PB_PATH_SIM;
        }
        else if (memcmp(curPos, "pb", 2) == 0)
        {
            pathFlags |= PB_PATH_PHONEBOOK;
        }
        else if (memcmp(curPos, "ich", 3) == 0)
        {
            pathFlags |= PB_PATH_INCOMING;
        }
        else if (memcmp(curPos, "och", 3) == 0)
        {
            pathFlags |= PB_PATH_OUTGOING;
        }
        else if (memcmp(curPos, "mch", 3) == 0)
        {
            pathFlags |= PB_PATH_MISSED;
        }
        else if (memcmp(curPos, "cch", 3) == 0)
        {
            pathFlags |= PB_PATH_COMBINED;
        }
    }

    /*Get the path flag*/
    while (i <= strLen)
    {
        if ((path[i] == '\\') || (path[i] == '/'))
        {
            if (memcmp(path + i + 1, "telecom", 7) == 0)
            {
                pathFlags |= PB_PATH_TELECOM;
            }
            else if (memcmp(path + i + 1, "SIM1", 4) == 0)
            {
                pathFlags |= PB_PATH_SIM;
            }
            else if (memcmp(path + i + 1, "pb", 2) == 0)
            {
                pathFlags |= PB_PATH_PHONEBOOK;
            }
            else if (memcmp(path + i + 1, "ich", 3) == 0)
            {
                pathFlags |= PB_PATH_INCOMING;
            }
            else if (memcmp(path + i + 1, "och", 3) == 0)
            {
                pathFlags |= PB_PATH_OUTGOING;
            }
            else if (memcmp(path + i + 1, "mch", 3) == 0)
            {
                pathFlags |= PB_PATH_MISSED;
            }
            else if (memcmp(path + i + 1, "cch", 3) == 0)
            {
                pathFlags |= PB_PATH_COMBINED;
            }

            /*move to the char after \\ */
        }
        i++;
    }
    return pathFlags;
}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_phb_storage_enum srv_pbap_flag2type(PbPathFlags pathFlags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_storage_enum pb_storage = PHB_STORAGE_TOTAL; //PHB_STORAGE_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*according to the path flag, get the pb type*/
    if (pathFlags & PB_PATH_SIM)
    {
        if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_PHONEBOOK))
        {
            pb_storage = PHB_STORAGE_SIM1_PB;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_INCOMING))
        {
            pb_storage = PHB_STORAGE_SIM1_ICH;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_OUTGOING))
        {
            pb_storage = PHB_STORAGE_SIM1_OCH;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_MISSED))
        {
            pb_storage = PHB_STORAGE_SIM1_MCH;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_COMBINED))
        {
            pb_storage = PHB_STORAGE_SIM1_CCH;
        }
    }
    else
    {
        if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_PHONEBOOK))
        {
            pb_storage = PHB_STORAGE_NVRAM_PB;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_INCOMING))
        {
            pb_storage = PHB_STORAGE_NVRAM_ICH;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_OUTGOING))
        {
            pb_storage = PHB_STORAGE_NVRAM_OCH;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_MISSED))
        {
            pb_storage = PHB_STORAGE_NVRAM_MCH;
        }
        else if((pathFlags & PB_PATH_TELECOM) && (pathFlags & PB_PATH_COMBINED))
        {
            pb_storage = PHB_STORAGE_NVRAM_CCH;
        }
    }
    return pb_storage;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_obj_name_swapcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_str        [IN]        null terminated
 *  dest_str        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_string_swapcpy(PU8 dest_str, const PU8 src_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 bytes_len = mmi_ucs2strlen((PS8) src_str) * 2;
    U8 t;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < bytes_len; i += 2)    /* includes null temination */
    {
        /* dest_str pointer may be same as src_str*/
        t = src_str[i];
        dest_str[i] = src_str[i + 1];
        dest_str[i + 1] = t;
    }

    dest_str[bytes_len] = 0;
    dest_str[bytes_len + 1] = 0;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_ftp_obj_name_swapcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_str        [IN]        null terminated
 *  dest_str        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_phb_filter(PU8 pb_filter, const PU8 pbap_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//    SRV_PBAP_LOG1(SRV_PBAP_GET_PHB_FILTER, *((U32*)pbap_filter));
    /*need to optimize*/
    memcpy(pb_filter, pbap_filter, PBAP_FILTER_SIZE); 
    
    /*
    switch (*pbap_filter)
    {
        case PBAP_VCARD_FILTER_VER:
            pb_filter[VCARD_FILTER_VER/8] |= (1 << (VCARD_FILTER_VER%8 - 1));
            break;

        case PBAP_VCARD_FILTER_FN:
            pb_filter[VCARD_FILTER_FN/8] |= (1 << (VCARD_FILTER_FN%8 - 1));
            break;

        case PBAP_VCARD_FILTER_N:
            pb_filter[VCARD_FILTER_N/8] |= (1 << (VCARD_FILTER_N%8 - 1));
            break;

        case PBAP_VCARD_FILTER_PHOTO:
            pb_filter[VCARD_FILTER_PHOTO/8] |= (1 << (VCARD_FILTER_PHOTO%8 - 1));
            break;

        case PBAP_VCARD_FILTER_BDAY:
            pb_filter[VCARD_FILTER_BDAY/8] |= (1 << (VCARD_FILTER_BDAY%8 - 1));
            break;

        case PBAP_VCARD_FILTER_ADR:
            pb_filter[VCARD_FILTER_ADR/8] |= (1 << (VCARD_FILTER_ADR%8 - 1));
            break;

        case PBAP_VCARD_FILTER_LABEL:
            pb_filter[VCARD_FILTER_LABEL/8] |= (1 << (VCARD_FILTER_LABEL%8 - 1));
            break;

        case PBAP_VCARD_FILTER_TEL:
            pb_filter[VCARD_FILTER_TEL/8] |= (1 << (VCARD_FILTER_TEL%8 - 1));
            break;

        case PBAP_VCARD_FILTER_EMAIL:
            pb_filter[VCARD_FILTER_EMAIL/8] |= (1 << (VCARD_FILTER_EMAIL%8 - 1));
            break;

        case PBAP_VCARD_FILTER_MAILER:
            pb_filter[VCARD_FILTER_MAILER/8] |= (1 << (VCARD_FILTER_MAILER%8 - 1));
            break;

        case PBAP_VCARD_FILTER_TZ:
            pb_filter[VCARD_FILTER_TZ/8] |= (1 << (VCARD_FILTER_TZ%8 - 1));
            break;

        case PBAP_VCARD_FILTER_GEO:
            pb_filter[VCARD_FILTER_GEO/8] |= (1 << (VCARD_FILTER_GEO%8 - 1));
            break;

        case PBAP_VCARD_FILTER_TITLE:
            pb_filter[VCARD_FILTER_TITLE/8] |= (1 << (VCARD_FILTER_TITLE%8 - 1));
            break;

        case PBAP_VCARD_FILTER_ROLE:
            pb_filter[VCARD_FILTER_ROLE/8] |= (1 << (VCARD_FILTER_ROLE%8 - 1));
            break;

        case PBAP_VCARD_FILTER_LOGO:
            pb_filter[VCARD_FILTER_LOGO/8] |= (1 << (VCARD_FILTER_LOGO%8 - 1));
            break;

        case PBAP_VCARD_FILTER_AGENT:
            pb_filter[VCARD_FILTER_AGENT/8] |= (1 << (VCARD_FILTER_AGENT%8 - 1));
            break;

        case PBAP_VCARD_FILTER_ORG:
            pb_filter[VCARD_FILTER_ORG/8] |= (1 << (VCARD_FILTER_ORG%8 - 1));
            break;

        case PBAP_VCARD_FILTER_NOTE:
            pb_filter[VCARD_FILTER_NOTE/8] |= (1 << (VCARD_FILTER_NOTE%8 - 1));
            break;

        case PBAP_VCARD_FILTER_REV:
            pb_filter[VCARD_FILTER_REV/8] |= (1 << (VCARD_FILTER_REV%8 - 1));
            break;

        case PBAP_VCARD_FILTER_SOUND:
            pb_filter[VCARD_FILTER_SOUND/8] |= (1 << (VCARD_FILTER_SOUND%8 - 1));
            break;

        case PBAP_VCARD_FILTER_URL:
            pb_filter[VCARD_FILTER_URL/8] |= (1 << (VCARD_FILTER_URL%8 - 1));
            break;

        case PBAP_VCARD_FILTER_UID:
            pb_filter[VCARD_FILTER_UID/8] |= (1 << (VCARD_FILTER_UID%8 - 1));
            break;

        case PBAP_VCARD_FILTER_KEY:
            pb_filter[VCARD_FILTER_KEY/8] |= (1 << (VCARD_FILTER_KEY%8 - 1));
            break;

        case PBAP_VCARD_FILTER_NICK:
            pb_filter[VCARD_FILTER_NICK/8] |= (1 << (VCARD_FILTER_NICK%8 - 1));
            break;

        case PBAP_VCARD_FILTER_CAT:
            pb_filter[VCARD_FILTER_CAT/8] |= (1 << (VCARD_FILTER_CAT%8 - 1));
            break;

        case PBAP_VCARD_FILTER_PRODID:
            pb_filter[VCARD_FILTER_PRODID/8] |= (1 << (VCARD_FILTER_PRODID%8 - 1));
            break;

        case PBAP_VCARD_FILTER_CLASS:
            pb_filter[VCARD_FILTER_CLASS/8] |= (1 << (VCARD_FILTER_CLASS%8 - 1));
            break;

        case PBAP_VCARD_FILTER_SORT_STR:
            pb_filter[VCARD_FILTER_SORT_STR/8] |= (1 << (VCARD_FILTER_SORT_STR%8 - 1));
            break;

        case PBAP_VCARD_FILTER_TIMESTAMP:
            pb_filter[VCARD_FILTER_TIMESTAMP/8] |= (1 << (VCARD_FILTER_TIMESTAMP%8 - 1));
            break;
    }*/
    
}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_phb_format(PU8 pb_format, PbapVcardFormat pbap_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG1(SRV_PBAP_GET_PHB_FORMAT, pbap_format);

    switch (pbap_format)
    {
        case VCARD_FORMAT_21:
            *pb_format = MMI_VCARD_VERSION_21;
            break;

        case VCARD_FORMAT_30:
            *pb_format = MMI_VCARD_VERSION_30;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_pbap_get_phb_order(U8 pbap_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dest_order;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PBAP_LOG1(SRV_PBAP_GET_PHB_ORDER, pbap_order);

    if (pbap_order == PBAP_SORT_ORDER_INDEXED)
    {
        dest_order = PHB_SORT_ORDER_INDEX;
    }
    else if (pbap_order == PBAP_SORT_ORDER_ALPHA)
    {
        dest_order = PHB_SORT_ORDER_NAME;
    }
    else
    {
        dest_order = PHB_SORT_ORDER_NONE;
    }

    return dest_order;
}


/*****************************************************************************
 * FUNCTION
 * srv_pbap_authrize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_pbap_get_phb_err_code(mmi_phb_vcard_error_struct* error_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(error_info->error_code)
    {
        case PHB_VCARD_IN_USE:
            return PB_STATUS_INUSE;

        case PHB_VCARD_NOT_FOUND:
            return PB_STATUS_NOT_FOUND;

        case PHB_VCARD_FS_ERROR:
            return PB_STATUS_FAILED;

        case PHB_VCARD_NO_ERROR:
            return PB_STATUS_SUCCESS;

        default:
            return PB_STATUS_NOT_SUPPORTED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_send_msg
 * DESCRIPTION
 *  convert the pbap para to phoebook para, and call the build func
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_pbap_write_one_entry(
    U16 index, 
    U8 storage, 
    U16 *path,
    const PU8 pbap_filter_str, 
    PbapVcardFormat pbap_format,
    MMI_BOOL is_append,
    mmi_phb_build_vcard_funcptr_type cbk_build_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_object_struct vcard_object;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_object.index_hdlr = index;
    vcard_object.vcard_storage = storage;
    srv_pbap_get_phb_filter(vcard_object.vcard_filter, pbap_filter_str);
    srv_pbap_get_phb_format(&vcard_object.vcard_format, pbap_format);

    mmi_phb_build_vcard(
        path,
        &vcard_object,
        is_append,
        cbk_build_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_get_new_missed_calls
 * DESCRIPTION
 *  convert the pbap para to phoebook para, and call the build func
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_get_new_missed_calls(
    U16 size, 
    mmi_phb_get_storage_size_funcptr_type new_mcalls_cbk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_vcard_error_struct error_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*we use pb_size directly for new_missed_calls when mch is encouted*/
    error_info.error_code = PHB_VCARD_NO_ERROR;
    new_mcalls_cbk(&error_info, size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_check_folder
 * DESCRIPTION
 *  check whether the path is a legal sub-path
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_pbap_check_folder(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, str_len;
    PbPathFlags pathFlags = 0;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    str_len = strlen(path);
    for (i = 0; i < str_len; i++)
    {
        if (!memcmp(path + i, "SIM1", 4) && path[i+4] == '\\')
        {
            pathFlags |= PB_PATH_SIM;
        }    
        else if ((memcmp(path + i, "telecom", 7) == 0) && path[i+7] == '\\')
        {
            pathFlags |= PB_PATH_TELECOM;
        }
        else if((memcmp(path + i, "pb", 2) == 0) && path[i+2] == '\\' && (pathFlags & PB_PATH_TELECOM))
        {
            pathFlags |= PB_PATH_PHONEBOOK;
        }
        else if((memcmp(path + i, "ich", 3) == 0) && path[i+3] == '\\' && (pathFlags & PB_PATH_TELECOM))
        {
            pathFlags |= PB_PATH_INCOMING;
        }
        else if((memcmp(path + i, "och", 3) == 0) && path[i+3] == '\\' && (pathFlags & PB_PATH_TELECOM))
        {
            pathFlags |= PB_PATH_OUTGOING;
        }
        else if((memcmp(path + i, "mch", 3) == 0) && path[i+3] == '\\' && (pathFlags & PB_PATH_TELECOM))
        {
            pathFlags |= PB_PATH_MISSED;
        }
        else if((memcmp(path + i, "cch", 3) == 0) && path[i+3] == '\\' && (pathFlags & PB_PATH_TELECOM))
        {
            pathFlags |= PB_PATH_COMBINED;
        }
    }
    return pathFlags;

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_backup_folder
 * DESCRIPTION
 *  backup a folder one level
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static S8 srv_pbap_backup_folder(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i,len;
    S8 error_code = 0;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(path);
    for(i = len-2; i >= 0; i--)
    {
        if (path[i] == '\\')
        {
            break;
        }
    }
    
    if (i == 0)
    {
        path[0] = '\0';
    }
    else
    {
        path[i+1] = '\0';
    }
    return error_code;

}


/*****************************************************************************
 * FUNCTION
 *  srv_pbap_notify_app
 * DESCRIPTION
 *  notify app the event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_pbap_notify_app(U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < SRV_PBAP_MAX_HANDLE_NUM; i ++)
    {
        if (srv_pbap_p->app_hd[i].srv_hd > 0)
        {
            if (srv_pbap_p->app_hd[i].event_mask & event_id)
            {
                srv_pbap_p->app_hd[i].notifier(srv_pbap_p->app_hd[i].srv_hd, event_id, para);
            }
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_pbap_get_inst_from_srv_hd
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_pbap_handle_struct *srv_pbap_get_inst_from_srv_hd(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbap_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_hd <= 0)
        return NULL;

    if (srv_hd > 0)
    {
        inst = &srv_pbap_p->app_hd[srv_hd - 1];
    }
    
    return inst;
}
#endif /* __MMI_PBAP_NEW_SUPPORT__ */
#endif /* __srv_MTK_SUPPORT__ */ 

