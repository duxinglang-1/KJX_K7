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

/*******************************************************************************
 * Filename:
 * ---------
 * MmsMsgHdlrSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
// #include "MMI_include.h"

#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"

#include "kal_trace.h"

//#include "ProtocolEvents.h"
//#include "MMSAppUICommon.h"
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"

#ifdef __MMI_VCARD__
#include "vcard_lib.h"
#endif 
#include "MMSMemoryManagerSrv.h"
// #include "SimDetectionGprot.h"
#include "EngineerModeInetAppGprot.h"
//#include "MMSAppUtil.h"
//#include "MMSAppSrvHdlr.h"
#include "mma_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_ltlcom.h" 
#include "mma_api.h"

#include "kal_public_defs.h" 
#include "mms_adp.h"
#include "UmSrvStruct.h"
#include "mms_sap_struct.h"
#include "UmSrvDefs.h"
#include "mmi_frm_events_gprot.h"
#include "MmsSrvSendRcv.h"
// #include "SimDetectionStruct.h"
#include "WAPProfileSrvType.h"
#include "mms_adp_struct.h"
#include "mmi_cb_mgr_gprot.h"
#include "app_ua.h"
#include "Asciiprot.h"
#include "MMSBGSRSrvProt.h"
BOOL g_is_wap_ready = FALSE;
extern srv_mms_cntx_struct *g_srv_mms_cntx;
extern srv_mms_new_message_cntx_struct *g_srv_new_msg_cntx;

srv_mms_process_data_struct g_srv_immed_send;

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
S32 g_mms_srv_template_xml_file_hdl = 0;
#endif 
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
extern srv_mms_mark_several_struct *g_srv_mark_several_cntx;
#endif 
U8 lite_req_counter = 0;

extern srv_um_msg_box_enum mmi_um_get_current_msg_box_type(void);

/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_get_msg_info_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_MSG_INFO_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mma_get_msg_info_req(srv_mms_process_data_struct *process, srv_mms_mma_get_msg_info_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_info_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_get_msg_info_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_msg_info_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = para->msg_id;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_MSG_INFO_REQ),
        0,
        MSG_ID_WAP_MMA_GET_MSG_INFO_REQ,
        (oslParaType*) req,
        NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_get_msg_info_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_GET_MSG_INFO_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_mma_get_msg_info_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_get_msg_info_rsp_struct *rsp = (wap_mma_get_msg_info_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_mma_get_msg_info_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_content_info_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_CONTENT_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_content_info_req(srv_mms_process_data_struct *process, srv_mms_get_content_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = para->msg_id;
    req->mode = para->mode;
    req->creation_mode = para->creation_mode;
    /* req->buffer_index = 0; */
#if defined (__MMI_MMS_USE_ASM__) && defined (__COSMOS_MMI_PACKAGE__)
if(para->app_id)
{
    srv_mms_mem_mgr_init_asm_for_service_ext(para->app_id);
}
else
{
	srv_mms_mem_mgr_init_asm_for_service();
}
#endif
    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_CONTENT_REQ),
        0,
        MSG_ID_WAP_MMA_GET_CONTENT_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_content_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_GET_CONTENT_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_get_content_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_get_content_rsp_struct *rsp = (wap_mma_get_content_rsp_struct*) msg;
    
    wap_mma_free_content_info_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    if (rsp->result != MMA_RESULT_OK)
    {
        srv_mms_get_content_data_hdlr(process, msg);
        return MMI_FALSE;
    }
    /* cntx = process->cntx; */
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
#endif /* 0 */ 
    srv_mms_get_content_data_hdlr(process, msg);

    req = (wap_mma_free_content_info_struct*) OslConstructDataPtr(sizeof(wap_mma_free_content_info_struct));
    req->req_id = rsp->req_id;
    req->app_id = rsp->app_id;
    req->msg_id = rsp->msg_id;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_FREE_MMS_CONTENT),
        0,
        MSG_ID_WAP_MMA_FREE_MMS_CONTENT,
        (oslParaType*) req,
        NULL);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_num_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_MSG_NUM_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_msg_num_req(srv_mms_process_data_struct *process, srv_mms_get_msg_num_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_num_req_struct *req;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_get_msg_num_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_msg_num_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    for (count = 0; count < MMA_MAX_MSG_NUM_QUERY_NUM; count++)
    {
        req->req_tb[count] = para->req_tb[count];
    }

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_MSG_NUM_REQ),
        0,
        MSG_ID_WAP_MMA_GET_MSG_NUM_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_num_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_GET_MSG_NUM_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_get_msg_num_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_get_msg_num_rsp_struct *rsp = (wap_mma_get_msg_num_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_get_msg_num_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_readmark_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_SET_READMARK_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_readmark_req(srv_mms_process_data_struct *process, srv_mms_set_readmark_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_set_readmark_req_struct*) OslConstructDataPtr(sizeof(*req));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = para->msg_id;
    req->readmark = para->readmark;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SET_READMARK_REQ),
        0,
        MSG_ID_WAP_MMA_SET_READMARK_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_readmark_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_SET_READMARK_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_set_readmark_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_set_readmark_rsp_struct *rsp = (wap_mma_set_readmark_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_set_readmark_data_hdlr(process, msg);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_SAVE_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_save_req(srv_mms_process_data_struct *process, srv_mms_save_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *req;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_save_req_struct*) OslConstructDataPtr(sizeof(wap_mma_save_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->box = para->box;
    req->no_of_msg = para->no_of_msg;

    for (count = 0; count < para->no_of_msg; count++)
    {
        req->msg_id[count] = para->msg_id[count];
    }

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SAVE_REQ),
        0,
        MSG_ID_WAP_MMA_SAVE_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_SAVE_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_save_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_save_rsp_struct *rsp = (wap_mma_save_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* srv_mms_get_number_status_icon(); */
    srv_mms_msg_update_count_and_status_icon();
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_save_data_hdlr(process, msg);
#if !defined (__COSMOS_MMI_PACKAGE__) 
	if(rsp->app_id != MMA_APP_ID_UC)
#endif
    {
        srv_mms_um_refresh_ind_struct req;

        memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
        req.msg_box_type = MMA_FOLDER_ALL;
        req.refresh_type = SRV_UM_REFRESH_NONE;
        srv_mms_um_refresh_msg_list(&req);
    }
    return MMI_FALSE;
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_DELETE_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_req(srv_mms_process_data_struct *process, srv_mms_delete_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *req;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_delete_req_struct*) OslConstructDataPtr(sizeof(wap_mma_delete_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->box = para->box;
    req->no_of_msg = para->no_of_msg;

    for (count = 0; count < para->no_of_msg; count++)
    {
        req->msg_id[count] = para->msg_id[count];
    }

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_DELETE_REQ),
        0,
        MSG_ID_WAP_MMA_DELETE_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_DELETE_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_delete_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_delete_rsp_struct *rsp = (wap_mma_delete_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* srv_mms_get_number_status_icon(); */
    srv_mms_msg_update_count_and_status_icon();
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_delete_data_hdlr(process, msg);
    /* if(rsp->result == MMA_RESULT_OK) */
    {
        srv_mms_um_refresh_ind_struct req;

        memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
        req.msg_box_type = MMA_FOLDER_ALL;
        req.refresh_type = SRV_UM_REFRESH_NONE;
        srv_mms_um_refresh_msg_list(&req);
    }
    return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_unread_msg_list_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_unread_msg_list_req(
        srv_mms_process_data_struct *process,
        srv_mms_get_unread_msg_list_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_unread_msg_list_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req =
        (wap_mma_get_unread_msg_list_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_unread_msg_list_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->start_index = para->start_index;
    req->num_of_msg_requested = para->num_of_msg_requested;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_REQ),
        0,
        MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_unread_msg_list_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_get_unread_msg_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_get_unread_msg_list_rsp_struct *rsp = (wap_mma_get_unread_msg_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_get_unread_msg_list_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_property_list_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_MSG_PROPERTY_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_msg_property_list_req(srv_mms_process_data_struct *process, srv_mms_property_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_property_req_struct *req;
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_get_msg_property_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_msg_property_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->no_of_msg = para->no_of_msg;

    for (count = 0; count < para->no_of_msg; count++)
    {
        req->msg_id[count] = para->msg_id[count];
    }

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_MSG_PROPERTY_REQ),
        0,
        MSG_ID_WAP_MMA_GET_MSG_PROPERTY_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_property_list_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_GET_MSG_PROPERTY_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_get_msg_property_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_get_msg_property_rsp_struct *rsp = (wap_mma_get_msg_property_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_get_msg_property_list_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_recent_evt_list_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_recent_evt_list_req(srv_mms_process_data_struct *process, srv_mms_recent_evt_list_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_recent_evt_list_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req =
        (wap_mma_get_recent_evt_list_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_recent_evt_list_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->num_of_evt_requested = para->num_of_evt_requested;
    req->start_index = para->start_index;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_REQ),
        0,
        MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_recent_evt_list_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_get_recent_evt_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_get_recent_evt_list_rsp_struct *rsp = (wap_mma_get_recent_evt_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_get_recent_evt_list_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_recent_event_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_recent_event_req(srv_mms_process_data_struct *process, srv_mms_delete_recent_evt_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_recent_evt_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_delete_recent_evt_req_struct*) OslConstructDataPtr(sizeof(wap_mma_delete_recent_evt_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = para->msg_id;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ),
        0,
        MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_recent_event_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_DELETE_RECENT_EVT_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_delete_recent_event_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_delete_recent_evt_rsp_struct *rsp = (wap_mma_delete_recent_evt_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_delete_recent_event_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_obj_ind_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_MMS_OBJ_IND to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_obj_ind_req(srv_mms_process_data_struct *process, srv_mms_obj_ind_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_mms_obj_ind_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_mms_obj_ind_struct*) OslConstructDataPtr(sizeof(wap_mma_mms_obj_ind_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_type = para->msg_type;
    req->sim_id = para->sim_id;
    mmi_ucs2ncpy((PS8) req->mms_filepath, (PS8) para->mms_filepath, MMA_MAX_EXTERNAL_FILE_PATH_LEN);

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_MMS_OBJ_IND),
        0,
        MSG_ID_WAP_MMA_MMS_OBJ_IND,
        (oslParaType*) req,
        NULL);

    return;
}

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_immed_send_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process     [?]     
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_immed_send_req(srv_mms_process_data_struct *process, srv_mms_immed_send_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_srv_immed_send, 0, sizeof(srv_mms_process_data_struct));

    g_srv_immed_send.result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_immed_send_rsp_struct));

    memset(g_srv_immed_send.result, 0, sizeof(srv_mms_immed_send_rsp_struct));

    g_srv_immed_send.call_back = para->call_back;
    g_srv_immed_send.user_data = (void*)para->user_data;
    g_srv_immed_send.app_id = para->app_id;

    srv_mms_bgsr_vendor_send_msg_req(para->msg_id, para->sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_vendor_send_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_vendor_send_rsp_callback(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_immed_send_rsp_struct *msg_rsp;
    srv_mms_result_enum vendor_result = SRV_MMS_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMA_RESULT_OK)
    {
        vendor_result = SRV_MMS_RESULT_OK;
    }
    else if (result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE)
    {
        vendor_result = SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    else
    {
        vendor_result = SRV_MMS_RESULT_FAIL;
    }

    msg_rsp = (srv_mms_immed_send_rsp_struct*) g_srv_immed_send.result;
    msg_rsp->result = (MMI_BOOL)result;

    msg_rsp->app_id = g_srv_immed_send.app_id;
    msg_rsp->msg_id = msg_id;

    g_srv_immed_send.call_back(vendor_result, g_srv_immed_send.result, g_srv_immed_send.user_data);

    srv_mms_mem_mgr_app_adm_free(g_srv_immed_send.result);
    memset(&g_srv_immed_send, 0, sizeof(srv_mms_process_data_struct));
}
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_recv_obj_ind_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_MMS_OBJ_RES
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_recv_obj_ind_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_mms_obj_res_struct *rsp = (wap_mma_mms_obj_res_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_obj_ind_rsp_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_create_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_CREATE_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_create_req(srv_mms_process_data_struct *process, srv_mms_create_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *req;
    srv_mms_create_cntx_struct *cntx;

    peer_buff_struct *peer_buff_ptr = NULL;
    U32 read_size = 0;
    U16 peer_buff_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = process->cntx;
    req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = cntx->msg_id = para->msg_id;
    req->mode = para->mode;
    req->sim_id = para->sim_id;
    req->xml_size = para->xml_size;
    req->content_info = para->content_info;
    if (para->xml_size)
    {
        mmi_ucs2ncpy((PS8) req->xml_filepath, (PS8) para->xml_filepath, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    }
    else
    {
        mmi_ucs2ncpy((PS8) req->msg_file_path, (PS8) para->msg_file_path, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    }

    req->buffer_index = 0;

    if (0 == para->xml_size)
    {
        req->buffer_size = 0;
        req->more = KAL_FALSE;
    }
    else if (para->xml_size <= SRV_MMS_MAX_BUFFER_SIZE)
    {
        req->buffer_size = para->xml_size;
        req->more = KAL_FALSE;
    }
    else
    {
        req->buffer_size = SRV_MMS_MAX_BUFFER_SIZE;
        req->more = KAL_TRUE;
    }

    if (para->xml_size)
    {

        cntx->fh = FS_Open(para->xml_filepath, FS_READ_ONLY);
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        g_mms_srv_template_xml_file_hdl = cntx->fh;
    #endif 
        if (cntx->fh < 0)
        {
            para->call_back(SRV_MMS_RESULT_FILE_OPERATION_FAILED, NULL, para->user_data);
            srv_mms_reset_process_data(process);
            return;
        }

        peer_buff_ptr = construct_peer_buff((U16) req->buffer_size, 0, 0, TD_CTRL);
        if (FS_Read(
                cntx->fh,
                get_pdu_ptr(peer_buff_ptr, &peer_buff_len),
                req->buffer_size,
                &read_size) != FS_NO_ERROR || read_size != req->buffer_size)
        {
            /* MMI_TRACE(/, /, read_size, req->buffer_size); */
        }

    }

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_CREATE_REQ),
        0,
        MSG_ID_WAP_MMA_CREATE_REQ,
        (oslParaType*) req,
        peer_buff_ptr);

    return;
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_close_xml_file_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_close_xml_file_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Close(g_mms_srv_template_xml_file_hdl);
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_create_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_CREATE_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_create_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    srv_mms_create_cntx_struct *cntx;
    wap_mma_create_rsp_struct *rsp = (wap_mma_create_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);

    if (!process)
    {
        return MMI_FALSE;
    }
    cntx = process->cntx;
    if (rsp->result == MMA_RESULT_OK)
    {
        if (rsp->msg_id == 0)
        {
            wap_mma_create_req_struct *req;
            peer_buff_struct *peer_buff_ptr;
            U32 read_size = 0;
            S32 remaining_size = 0;
            U16 peer_buff_len = 0;

            req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));

            req->app_id = rsp->app_id;
            req->mode = cntx->mode;
            req->msg_id = cntx->msg_id;

            req->req_id = process->req_id;
            mmi_ucs2ncpy((S8*) req->xml_filepath, (S8*) cntx->xml_filepath, MMA_MAX_INTERNAL_FILENAME_LENGTH);
            req->xml_size = cntx->xml_size;
            req->buffer_index = rsp->buffer_index;

            remaining_size = cntx->xml_size - (req->buffer_index * SRV_MMS_MAX_BUFFER_SIZE);

            if (remaining_size <= SRV_MMS_MAX_BUFFER_SIZE)
            {
                req->buffer_size = remaining_size;
                req->more = KAL_FALSE;
            }
            else
            {
                req->buffer_size = SRV_MMS_MAX_BUFFER_SIZE;
                req->more = KAL_TRUE;
            }

            peer_buff_ptr = construct_peer_buff((kal_uint16) req->buffer_size, 0, 0, TD_CTRL);

            if (FS_Read
                (cntx->fh, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), req->buffer_size,
                 &read_size) != FS_NO_ERROR || read_size != req->buffer_size)
            {

                /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_TEMPLATE_PEER_BUF, read_size, msg_req->buffer_size); */

            }

            srv_mms_send_message(
                MOD_MMI,
                mms_get_service_module(MSG_ID_WAP_MMA_CREATE_REQ),
                0,
                MSG_ID_WAP_MMA_CREATE_REQ,
                (oslParaType*) req,
                peer_buff_ptr);
            return MMI_FALSE;
        }
    }

    FS_Close(cntx->fh);
    srv_mms_create_data_hdlr(process, msg);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_power_off_req
 * DESCRIPTION
 *  Send MSG_ID_MMS_POWEROFF_REQ to MMS
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_power_off_req(srv_mms_process_data_struct *process, srv_mms_power_off_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_poweroff_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_mms_power_off_rsp, MSG_ID_MMS_POWEROFF_RSP);

    req = (mms_poweroff_struct*) OslConstructDataPtr(sizeof(mms_poweroff_struct));

    process->req_id = mma_get_request_id();

    req->request_id = process->req_id;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMS_POWEROFF_REQ),
        0,
        MSG_ID_MMS_POWEROFF_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_power_off_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_MMS_POWEROFF_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_power_off_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    mms_poweroff_struct *rsp = (mms_poweroff_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->request_id);

    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_power_off_data_hdlr(process, msg);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_all_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_UM_DELETE_ALL_IND to UM
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_all_req(srv_mms_process_data_struct *process, srv_mms_delete_all_ind_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_all_ind_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (srv_um_delete_all_ind_struct*) OslConstructDataPtr(sizeof(srv_um_delete_all_ind_struct));

    req->msg_type = para->msg_type;
    req->msg_box_type = para->msg_box_type;

    srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_DELETE_ALL_IND, (oslParaType*) req, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_all_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_MMI_UM_DELETE_ALL_RES
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_delete_all_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_app_id(MMA_APP_ID_MMS_APP);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_delete_all_data_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_folder_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_UM_DELETE_FOLDER_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_folder_req(srv_mms_process_data_struct *process, srv_mms_delete_folder_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (srv_um_delete_folder_req_struct*) OslConstructDataPtr(sizeof(srv_um_delete_folder_req_struct));

    process->req_id = mma_get_request_id();

    req->msg_type = para->msg_type;
    req->msg_box_type = para->msg_box_type;
    req->app_id = para->app_id;
    req->sim_id = SRV_UM_SIM_ALL;
    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_UM_DELETE_FOLDER_REQ),
        0,
        MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_folder_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_MMI_UM_DELETE_FOLDER_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_delete_folder_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    srv_um_delete_folder_rsp_struct *rsp = (srv_um_delete_folder_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_app_id(rsp->app_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_delete_folder_data_hdlr(process, msg);
    return MMI_FALSE;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_mark_several_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_entry_mark_several_req(srv_mms_process_data_struct *process, srv_mms_entry_mark_several_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_entry_mark_several_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (srv_um_entry_mark_several_req_struct*) OslConstructDataPtr(sizeof(srv_um_entry_mark_several_req_struct));

    req->app_id = para->app_id;
    req->msg_type = para->msg_type;
    req->msg_box_type = para->msg_box_type;
    req->msg_id = para->msg_id;

    srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_REQ, (oslParaType*) req, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_mark_several_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_entry_mark_several_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  
     * process = srv_mms_get_process_by_app_id((U8)rsp->app_id);
     * if(!process)
     * {
     * return MMI_FALSE;
     * }
     */
    srv_mms_entry_mark_several_screen_data_hdlr(process, msg);
    return MMI_FALSE;
}

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 

#ifdef __MMI_VCARD__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_vcard_version_req_hdlr
 * DESCRIPTION
 *  Receive MSG_ID_MMI_UMMS_GET_VCARD_VERSION_REQ from MMA
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_vcard_version_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;
    U16 *file_path = NULL;
    vcard_version_enum vcard_ver = VCARD_VERSION_3_0;
    srv_mms_get_vcard_version_rsp_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_get_vcard_version_req_struct *req = (srv_mms_get_vcard_version_req_struct*) msg;

    file_handle = FS_Open(req->filepath, FS_READ_ONLY | FS_OPEN_SHARED);

    if (file_handle > 0)
    {
        file_path = (U16*) srv_mms_mem_mgr_app_adm_alloc(FS_GenVFN_SIZE);
        result = FS_GenVirtualFileName(file_handle, (U16*) file_path, (unsigned int)FS_GenVFN_SIZE, req->offset, req->size);

        if (result < 0)
        {
            result = MMA_RESULT_FAIL;
            /* Write log Here */
        }
        else
        {
            VP_HANDLE vp;

            result = MMA_RESULT_OK;
            vp = vcard_open_parser(file_path, VCARD_PROPERTY_NONE, NULL);
            if (vp)
            {
                if (vcard_parse(vp, NULL) == VCARD_RESULT_FAIL)
                {
                    vcard_close_parser(vp);
                    result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                }
                else
                {
                    vcard_ver = vcard_get_parse_version(vp);
                    vcard_close_parser(vp);
                }
            }
        }
        FS_Close(file_handle);
        srv_mms_mem_mgr_app_adm_free(file_path);
    }
    else
    {
        result = MMA_RESULT_FAIL;
        /* Write Log Here */
    }

    rsp = (srv_mms_get_vcard_version_rsp_struct*) OslConstructDataPtr(sizeof(srv_mms_get_vcard_version_rsp_struct));
    rsp->req_id = req->req_id;
    rsp->result = result;
    rsp->vcard_ver = vcard_ver;

    srv_mms_send_message(MOD_MMI, MOD_MMS, 0, MSG_ID_MMI_UMMS_GET_VCARD_VERSION_RSP, (oslParaType*) rsp, NULL);
    return MMI_FALSE;
}
#endif /* __MMI_VCARD__ */ 

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_multi_op_req_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_multi_op_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_req_struct *req = (srv_um_mark_several_op_req_struct*) msg;
    srv_mms_multi_op_recv_req_struct recv_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req->msg_type != SRV_UM_MSG_MMS)
    {
        return MMI_FALSE;
    }
    recv_req.msg_type = req->msg_type;
    recv_req.app_id = req->app_id;
    recv_req.msg_box_type = req->msg_box_type;
    recv_req.msg_number = req->msg_number;
    recv_req.action_type = req->action_type;
    memcpy(recv_req.msg_id, req->msg_id, sizeof(U32) * SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

    srv_mms_mark_several_list_procress(&recv_req);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_multi_op_send_rsp
 * DESCRIPTION
 *  Response with MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_multi_op_send_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_rsp_struct *rsp;
    srv_mms_multi_op_send_rsp_struct *send_rsp = (srv_mms_multi_op_send_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (srv_um_mark_several_op_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_mark_several_op_rsp_struct));
    rsp->msg_type = send_rsp->msg_type;
    rsp->app_id = send_rsp->app_id;
    rsp->msg_box_type = send_rsp->msg_box_type;
    rsp->msg_number = send_rsp->msg_number;
    rsp->action_type = send_rsp->action_type;
    memcpy(rsp->msg_id, send_rsp->msg_id, sizeof(U32) * SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);
    memcpy(rsp->action_result, send_rsp->action_result, sizeof(MMI_BOOL) * SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

    srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP, (oslParaType*) rsp, NULL);
    return;
}

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_view_msg_ind_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_VIEW_MSG_IND
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_view_msg_ind_hdlr(void *msg)
{
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_storage_full_ind_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_STORAGE_FULL_IND
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_storage_full_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_storage_full_ind_struct *req = (wap_mma_storage_full_ind_struct*) msg;
    srv_mms_storage_full_ind_struct recv_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_req.result = req->result;
    recv_req.min_fs_space_required = req->min_fs_space_required;
    srv_mms_send_events(EVT_ID_SRV_STORAGE_FULL_IND, (void*)(&recv_req));
#ifdef __COSMOS_MMI_PACKAGE__
    {
        srv_mms_mem_status_event_struct event_data;
        U8 prefer_storage_value = 0;

        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_MMS_MEM_FULL);

    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        prefer_storage_value = srv_mms_get_mms_prefer_storage();

        if ((prefer_storage_value == MMA_MSG_STORAGE_CARD1) &&
            (srv_mms_get_mem_card_total_msg() == srv_mms_get_max_mms_num_on_card()))
        {
            event_data.mms_mem_status = SRV_MMS_MEM_STATUS_CARD_COUNT_ALREADY_MAX;
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            event_data.mms_mem_status = SRV_MMS_MEM_STATUS_PHONE_COUNT_ALREADY_MAX;
        }
        MMI_FRM_CB_EMIT_EVENT(&event_data);
    }
#endif /* __COSMOS_MMI_PACKAGE__ */ 

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_terminate_ind_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_TERMINATE_IND
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_terminate_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_cntx->is_srv_ready = MMI_FALSE;
    srv_mms_send_events(EVT_ID_SRV_MMS_MMA_TERMINATE, NULL);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_start_immed_retrieval_ind_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_start_immed_retrieval_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_start_immed_retrieval_ind_struct *ind = (wap_mma_start_immed_retrieval_ind_struct*) msg;
    srv_mms_update_status_struct msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    msg_status.msg_id = ind->msg_id;
    msg_status.status = SRV_MMS_MSG_STATUS_DOWNLOADING;
    srv_mms_send_events_ex(EVT_ID_SRV_MMS_UPDATE_STATUS, (void*)&msg_status);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_stop_immed_retrieval_ind_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_stop_immed_retrieval_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_stop_immed_retrieval_ind_struct *ind = (wap_mma_stop_immed_retrieval_ind_struct*) msg;
    srv_mms_stop_immed_retrieval_ind_struct recv_data;
    srv_mms_update_status_struct msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_data.msg_id = ind->msg_id;
    recv_data.sim_id = ind->sim_id;
    recv_data.result = ind->result;
    recv_data.error_cause = ind->error_cause;
    memcpy(recv_data.response_text, ind->response_text, sizeof(U16) * MMA_MAX_RESPONSE_TEXT_LENGTH);

    msg_status.msg_id = ind->msg_id;
    msg_status.status = SRV_MMS_MSG_STATUS_DOWNLOADING_FAILED;
    srv_mms_send_events_ex(EVT_ID_SRV_MMS_UPDATE_STATUS, (void*)&msg_status);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_ready_ind_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_MMI_UM_READY_IND
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_um_ready_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *ind = (srv_um_ready_ind_struct*) msg;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->result == KAL_TRUE)
    {
        if (ind->msg_type == SRV_UM_MSG_MMS)
        {
            g_srv_mms_cntx->is_srv_ready = MMI_TRUE;
            
            
            srv_mms_ready();
        #if 0
#ifndef __MMI_MMS_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_DUAL_SIM__ */ 
        #endif /* 0 */ 
            srv_mms_emit_ready_event(MMI_TRUE);
        }

    }

    else
    {
        if (ind->msg_type == SRV_UM_MSG_MMS)
        {
            g_srv_mms_cntx->is_srv_ready = MMI_FALSE;
        }
    }
    return MMI_FALSE;
}

/* Rajbir  */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_notify_event_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  InMsg       [?]         [?]
 *  mod_src     [IN]        
 *  ilm_p       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_notify_event_ind(void *InMsg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_notify_event_ind_struct *notify_event_ind;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    notify_event_ind = (wap_mma_notify_event_ind_struct*) InMsg;

    if (notify_event_ind->app_id != MMA_APP_ID_MMS_APP)
    {
        return MMI_FALSE;
    }

    switch (notify_event_ind->event_id)
    {
            /* Start NEW MMS Handling */
        case MMA_EVENT_NEW_MSG:
        {

		#if defined(__MMI_MMS_REPORT_BOX_SUPPORT__) || defined(__MMI_MMS_REPORT_STATUS_SUPPORT__) || !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
			wap_mma_event_new_msg_struct *new_msg_ind;
			kal_uint16 length;
            new_msg_ind = (wap_mma_event_new_msg_struct*) get_pdu_ptr(((ilm_struct*) ilm_p)->peer_buff_ptr, &length);
        #endif
        #if defined(__MMI_MMS_REPORT_BOX_SUPPORT__) || defined(__MMI_MMS_REPORT_STATUS_SUPPORT__)
            if ((new_msg_ind->msg_type == MMA_MSG_TYPE_READ_REPORT) ||
                (new_msg_ind->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT))
            {
                srv_mms_entry_new_report_hndlr(new_msg_ind);
            }
            else
        #endif /* defined(__MMI_MMS_REPORT_BOX_SUPPORT__) || defined(__MMI_MMS_REPORT_STATUS_SUPPORT__) */ 
            {
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
                srv_mms_entry_new_mms_hndlr(
                    new_msg_ind->msg_id,
                    new_msg_ind->folder,
                    new_msg_ind->msg_media_type,
                    new_msg_ind->sim_id);
#else
				srv_mms_send_events_ex(EVT_ID_SRV_MMS_NMGR_ALERT, NULL);
#endif
                srv_mms_show_status_icon();
            }
            break;
        }
        case MMA_EVENT_UM_DELETE_FOLDER_DONE:
        {

            srv_mms_show_status_icon();

        #ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
            srv_mms_notification_list_delete_all(); /* delete from notification list also */

        #endif /* __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__ */ 

            break;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_wap_mma_ready_ind_hdlr
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_READY_IND
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_wap_mma_ready_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_cntx->is_srv_ready = MMI_TRUE;
    g_is_wap_ready = TRUE;
    lite_req_counter = 0;
    srv_mms_read_nvram_settings(KAL_TRUE);
    srv_mms_set_current_mms_profile(KAL_TRUE);
#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
    srv_mms_start_object_indication_timer();
#endif 
#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
    srv_mms_start_notification_timer();
#endif 

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    if (g_srv_new_msg_cntx->nmgr_informed)
    {
        srv_mms_nmgr_get_unread_msg();
    }
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

    srv_mms_msg_update_count_and_status_icon();
    srv_mms_send_events(EVT_ID_SRV_WAP_READY, NULL);
    return MMI_FALSE;
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_MMS_2__)
/* under construction !*/
#ifdef __MMI_MMS_DUAL_SIM__
/* under construction !*/
#endif /* __MMI_MMS_DUAL_SIM__ */
/* under construction !*/
#endif /* defined (__MMI_MMS_2__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_refresh_msg_ind
 * DESCRIPTION
 *  refresh indication to UM module.
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_um_refresh_msg_ind(srv_mms_um_refresh_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *refresh_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refresh_data = (srv_um_refresh_ind_struct*) OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

    refresh_data->msg_type = SRV_UM_MSG_MMS;
    refresh_data->msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(msg->msg_box_type);
    refresh_data->refresh_type = msg->refresh_type;
    refresh_data->msg_id = msg->msg_id;
    refresh_data->addr_number = msg->addr_number;
    if (msg->addr_number == 1)
    {
        refresh_data->addr_type = srv_mms_convert_mma_addr_type_to_um_addr_type(msg->addr_type);
        memset(refresh_data->address, 0, (SRV_UM_MAX_ADDR_LEN + 1) * 2);
        mmi_ucs2ncpy((PS8) refresh_data->address, (PS8) msg->address, SRV_UM_MAX_ADDR_LEN);
    }
    srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) refresh_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_status_icon_unread_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_status_icon_unread_rsp_hdlr(srv_mms_result_enum result, void *msgrsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_msg_num_rsp_struct *msg = (srv_mms_get_msg_num_rsp_struct*) msgrsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_update_total_number_of_messages(msg);

/*********************amit added for a bug fix********************************/
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    srv_mms_send_events(EVT_ID_SRV_UPDATE_TEMPLTAE_DEL_FRM_PSUIT, NULL);
#endif 
    srv_mms_send_events(EVT_ID_SRV_UPDATE_MEM_STATUS, NULL);
    srv_mms_update_status_icon_on_number_rsp();

}


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_get_unread_msg_number_rsp_for_nmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         [?]
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_nmgr_get_unread_msg_number_rsp_for_nmgr(srv_mms_result_enum result, void *msgrsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_set_buffer_for_nmgr(msgrsp);
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_set_settings_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process         [?]     [?]
 *  req_data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mma_set_settings_req(srv_mms_process_data_struct *process, srv_mms_mma_set_settings_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* mma struct */
    wap_mma_set_setting_req_struct *msgSet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgSet = (wap_mma_set_setting_req_struct*) OslConstructDataPtr(sizeof(*msgSet));

    process->req_id = mma_get_request_id();
    msgSet->req_id = process->req_id;
    msgSet->app_id = req_data->app_id;
    msgSet->mms_version = (kal_uint8) applib_inet_get_active_mms_version();

    srv_mms_fill_current_settings_for_mma(msgSet);

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SET_SETTING_REQ),
        0,
        MSG_ID_WAP_MMA_SET_SETTING_REQ,
        (oslParaType*) msgSet,
        NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_set_settings_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_mma_set_settings_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_set_setting_rsp_struct *rsp = (wap_mma_set_setting_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_set_settings_rsp_data_hdlr(process, msg);
    return MMI_FALSE;

}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_get_list_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process         [?]     [?]
 *  req_data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_um_get_list_info_req(srv_mms_process_data_struct *process, srv_mms_get_list_info_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_um_get_msg_list_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (srv_um_get_msg_list_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

#if(MMI_MAX_SIM_NUM >= 2)
    msgReq->sim_id = SRV_UM_SIM_ALL;
#endif 

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    msgReq->list_idx_type = SRV_UM_LIST_IDX_TIMESTAMP;
#endif 

    msgReq->msg_type = SRV_UM_MSG_MMS;
    /* will put a check based uopon template type enum for this */
	process->req_id = mma_get_request_id();
    msgReq->msg_box_type = req_data->template_type; /* SRV_UM_MSG_BOX_USRDEF_TEMPLATES;//req_data->template_type; */
    msgReq->start_entry = 0;
    msgReq->app_id = req_data->app_id;
    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_UM_GET_MSG_LIST_REQ),
        0,
        MSG_ID_MMI_UM_GET_MSG_LIST_REQ,
        (oslParaType*) msgReq,
        NULL);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_get_msg_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_um_get_msg_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_process_data_struct *process;
    srv_um_get_msg_list_rsp_struct *rsp = (srv_um_get_msg_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_app_id((U8) rsp->app_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_get_um_list_info_rsp_data_hdlr(process, msg);
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_get_template_msg_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process         [?]     [?]
 *  req_data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_um_get_template_msg_info_req(
        srv_mms_process_data_struct *process,
        srv_mms_get_msg_info_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    srv_um_get_msg_info_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (srv_um_get_msg_info_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

    msgReq->msg_type = SRV_UM_MSG_MMS;
    msgReq->msg_box_type = req_data->template_type;
    msgReq->app_id = req_data->app_id;
    msgReq->msg_number = req_data->msg_number;
    for (index = 0; index < msgReq->msg_number; index++)
    {
        msgReq->msg_id[index] = req_data->msg_id[index];
    }

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_UM_GET_MSG_INFO_REQ),
        0,
        MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
        (oslParaType*) msgReq,
        NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_get_msg_info_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_um_get_msg_info_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_process_data_struct *process;
    srv_um_get_msg_info_rsp_struct *rsp = (srv_um_get_msg_info_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_app_id((U8) rsp->app_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_get_um_msg_info_rsp_data_hdlr(process, msg);
    return MMI_FALSE;

}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 

void srv_mms_set_current_profile_req_by_data(srv_wap_prof_profile_content_struct *profile_struct, U8 mma_sim_id)
{
    wap_mma_set_profile_req_struct *set_profile;
	if (!srv_mms_is_ready())
    {
		ASSERT(0);
        return;
    }

    set_profile = (wap_mma_set_profile_req_struct *) OslConstructDataPtr(sizeof(*set_profile));

    set_profile->req_id = mma_get_request_id();
    if (srv_mms_get_refresh_profile_flag())
    {
        set_profile->app_id = MMA_APP_ID_MMS_APP;
    }
    else
    {
        set_profile->app_id = MMA_APP_ID_SETTING;
    }
    srv_mms_set_refresh_profile_flag(MMI_FALSE);
    /* reset the refresh profile flag */
    /* set_profile->connection_type = profile_struct->conn_type; */
    set_profile->proxy_port = profile_struct->proxy_port;
#if(MMI_MAX_SIM_NUM >= 2)
    set_profile->sim_id = mma_sim_id;
#else 
    set_profile->sim_id = 0;    /* default sim_id */
#endif 

    switch (profile_struct->conn_type)
    {
   
        case SRV_WAP_PROF_CONN_TYPE_HTTP:
   
        {
            set_profile->connection_type = MMA_CONN_TYPE_HTTP_PROXY;
            break;
        }
    
        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED:
  
        {
            /* if(9200) MMA_CONN_TYPE_WSP_CL; else if(9201) */
            set_profile->connection_type = MMA_CONN_TYPE_WSP_CO;
            break;
        }
    
        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:
   
        {
            /* if(9202) MMA_CONN_TYPE_WSP_SEC_CL: else if(9203) */
            set_profile->connection_type = MMA_CONN_TYPE_WSP_SEC_CO;
            break;
        }

    }

    AsciiStrncpy((S8*)set_profile->proxy_addr, (S8*)profile_struct->proxy_ip, SRV_WAP_PROF_MAX_PROXY_ADDR_LEN + 1);

    mmi_asc_to_ucs2((S8 *) set_profile->homepage_url, (S8 *) profile_struct->url);
    mmi_asc_to_ucs2((S8 *) set_profile->username, (S8 *) profile_struct->username);
    mmi_asc_to_ucs2((S8 *) set_profile->password, (S8 *) profile_struct->password);

    set_profile->data_account = profile_struct->data_account_primary_id;

    srv_mms_send_message(MOD_MMI, mms_get_service_module(MSG_ID_WAP_MMA_SET_PROFILE_REQ), 0,
                         MSG_ID_WAP_MMA_SET_PROFILE_REQ, (oslParaType *) set_profile, NULL);

}

MMI_BOOL srv_mms_get_set_profile_rsp(void *inmsg)
{

    srv_mms_recieved_set_profile_response(inmsg);
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_app_data_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_SET_APP_DATA_REQ to MMA
 * PARAMETERS
 *  process     [?]     [?]
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_app_data_req(srv_mms_process_data_struct *process, srv_mms_set_app_data_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_app_data_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (wap_mma_set_app_data_req_struct*) OslConstructDataPtr(sizeof(wap_mma_set_app_data_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = para->msg_id;
    memcpy(req->app_data, para->app_data, MMA_MAX_APP_DATA_LENGTH);

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_SET_APP_DATA_REQ),
        0,
        MSG_ID_WAP_MMA_SET_APP_DATA_REQ,
        (oslParaType*) req,
        NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_app_data_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_SET_APP_DATA_RSP
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_set_app_data_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_set_app_data_rsp_struct *rsp = (wap_mma_set_app_data_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if (!process)
    {
        return MMI_FALSE;
    }

    srv_mms_set_app_data_rsp_hdlr(process, msg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_cancel_download_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_cancel_download_rsp(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_popup_data popup_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CANCEL_DWNLD_RSP_CALL_BACK, msg_id, result);

    memset(&popup_data, 0, sizeof(srv_mms_bgsr_popup_data));
    popup_data.rsp_type = SRV_MMS_BGSR_RSP_TYPE_CANCEL_DOWNLOAD;
    popup_data.msg_id = msg_id;
    popup_data.result = result;
    srv_mms_send_events(EVT_ID_SRV_SHOW_BGSR_POPUP, (void*)(&popup_data));

    srv_mms_show_status_icon();
    srv_mms_send_events(EVT_ID_SRV_CURR_MSG_SELECT, (void*)(&msg_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_download_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  new_msg_id          [IN]        
 *  result              [IN]        
 *  response_txt        [?]         [?]
 *  quota               [IN]        
 *  flag                [IN]        
 *  sim_id              [IN]        
 *  storage(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_download_rsp(U32 msg_id, U32 new_msg_id, U8 result, U16 *response_txt, U8 quota, U8 flag, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_popup_data popup_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DWNLD_RSP_CALL_BACK, msg_id, result, response_txt, quota, flag, sim_id);
#ifndef __COSMOS_MMI_PACKAGE__
    if (flag)
#endif 
    {
        memset(&popup_data, 0, sizeof(srv_mms_bgsr_popup_data));
        popup_data.rsp_type = SRV_MMS_BGSR_RSP_TYPE_DOWNLOAD;
        popup_data.msg_id = msg_id;
        popup_data.new_msg_id = new_msg_id;
        popup_data.result = result;

        popup_data.response_txt = response_txt;
        popup_data.sim_id = sim_id;
        popup_data.quota = quota;
    #ifndef __COSMOS_MMI_PACKAGE__
        srv_mms_send_events(EVT_ID_SRV_SHOW_BGSR_POPUP, (void*)(&popup_data));
    #else /* __COSMOS_MMI_PACKAGE__ */ 

        srv_mms_send_events_ex(EVT_ID_SRV_SHOW_BGSR_POPUP, (void*)(&popup_data));
    #endif /* __COSMOS_MMI_PACKAGE__ */ 
    }
#ifdef __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__
    if ((result == SRV_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED) ||
        (result == SRV_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT) ||
        (result == SRV_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT))
    {
        srv_mms_get_dwnld_quota_from_bgsr(msg_id, result, quota);
    }
#endif /* __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__ */ 
    if (result == SRV_MMS_BGSR_RESULT_OK)
    {
        srv_mms_um_refresh_ind(MMA_FOLDER_INBOX);
    }
    srv_mms_show_status_icon();
    srv_mms_send_events(EVT_ID_SRV_CURR_MSG_SELECT, (void*)(&msg_id));
    if (result == SRV_MMS_BGSR_RESULT_OK)
    {
        srv_mms_update_status_struct msg_status;

        msg_status.msg_id = msg_id;
        msg_status.status = SRV_MMS_MSG_STATUS_DOWNLOADED;
        srv_mms_send_events_ex(EVT_ID_SRV_MMS_UPDATE_STATUS, (void*)&msg_status);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  result              [IN]        
 *  response_text       [?]         [?]
 *  flag                [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_rsp(kal_uint32 msg_id, kal_uint8 result, kal_uint16 *response_text, kal_uint8 flag, kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_popup_data popup_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SEND_RSP_CALL_BACK, msg_id, result, response_text, flag, sim_id);
#ifndef __COSMOS_MMI_PACKAGE__
    if (flag & SRV_MMS_BGSR_RSP_DISPLAY)
#endif 
    {
        memset(&popup_data, 0, sizeof(srv_mms_bgsr_popup_data));
        popup_data.rsp_type = SRV_MMS_BGSR_RSP_TYPE_SEND;
        popup_data.msg_id = msg_id;
        popup_data.result = result;

        popup_data.response_txt = response_text;
        popup_data.sim_id = sim_id;
    #ifndef __COSMOS_MMI_PACKAGE__
        srv_mms_send_events(EVT_ID_SRV_SHOW_BGSR_POPUP, (void*)(&popup_data));
    #else /* __COSMOS_MMI_PACKAGE__ */ 

        srv_mms_send_events_ex(EVT_ID_SRV_SHOW_BGSR_POPUP, (void*)(&popup_data));
    #endif /* __COSMOS_MMI_PACKAGE__ */ 
    }
    if (result == SRV_MMS_BGSR_RESULT_OK)
    {
        U8 error = 0;
        mma_folder_enum folder_id = mma_get_box(msg_id);

        if ((flag & SRV_MMS_BGSR_RSP_SAVE) && (folder_id == MMA_FOLDER_OUTBOX))
        {
            srv_mms_save_msg(msg_id, MMA_FOLDER_SENT, &error);
        }
    }

    srv_mms_show_status_icon();
    srv_mms_send_events(EVT_ID_SRV_CURR_MSG_SELECT, (void*)(&msg_id));
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    if ((result == SRV_MMS_BGSR_RESULT_OK) || (srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SEND_FAIL))
    {
        srv_mms_um_refresh_ind(MMA_FOLDER_ALL);
    }
#else /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
    if ((result == SRV_MMS_BGSR_RESULT_OK) || (srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SEND_FAIL))
    {
        //srv_mms_um_refresh_ind(MMA_FOLDER_ALL);
    }
#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
    if (result == SRV_MMS_BGSR_RESULT_OK)
    {
        srv_mms_update_status_struct msg_status;

        msg_status.msg_id = msg_id;
        msg_status.status = SRV_MMS_MSG_STATUS_SENT;
        srv_mms_send_events_ex(EVT_ID_SRV_MMS_UPDATE_STATUS, (void*)&msg_status);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_cancel_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_cancel_send_rsp(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_popup_data popup_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CANCEL_SEND_RSP_FROM_BGSR, msg_id, result);

    memset(&popup_data, 0, sizeof(srv_mms_bgsr_popup_data));
    popup_data.rsp_type = SRV_MMS_BGSR_RSP_TYPE_CANCEL_SEND;
    popup_data.msg_id = msg_id;
    popup_data.result = result;
    srv_mms_send_events(EVT_ID_SRV_SHOW_BGSR_POPUP, (void*)(&popup_data));

    srv_mms_show_status_icon();
    srv_mms_send_events(EVT_ID_SRV_CURR_MSG_SELECT, (void*)(&msg_id));

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_folder_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_folder_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_um_refresh_ind_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_UPDATE_FLDR_CALLBACK);
    memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
    req.msg_box_type = MMA_FOLDER_OUTBOX;
    req.refresh_type = SRV_UM_REFRESH_NONE;
    srv_mms_um_refresh_msg_list(&req);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_menu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_menu_callback(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_UPDATE_MENU_CALLBACK, msg_id, result);

    if ((result & SRV_MMS_BGSR_UPDATE_STATUS) == SRV_MMS_BGSR_UPDATE_STATUS)
    {
        srv_mms_update_status_struct msg_status;

        U32 status = srv_mms_bgsr_get_msg_status(msg_id);

        msg_status.msg_id = msg_id;
        msg_status.status = SRV_MMS_MSG_STATUS_NONE;
        if (status == SRV_MMS_BGSR_STATUS_SENDING)
        {
            msg_status.status = SRV_MMS_MSG_STATUS_SENDING;
        }
        else if (status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
        {
            msg_status.status = SRV_MMS_MSG_STATUS_PENDING;
        }
        else if (status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND)
        {
            msg_status.status = SRV_MMS_MSG_STATUS_WAITING;
        }
        else if (status == SRV_MMS_BGSR_STATUS_SEND_FAIL)
        {
            msg_status.status = SRV_MMS_MSG_STATUS_SENDING_FAILED;
        }
        else if (status == SRV_MMS_BGSR_STATUS_DOWNLOADING)
        {
            msg_status.status = SRV_MMS_MSG_STATUS_DOWNLOADING;
        }
        else if (status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD)
        {
            msg_status.status = SRV_MMS_MSG_STATUS_PENDING_DOWNLOAD;
        }
        else if (status == SRV_MMS_BGSR_STATUS_DOWNLOAD_FAIL)
        {
            msg_status.status = SRV_MMS_MSG_STATUS_DOWNLOADING_FAILED;
        }

        srv_mms_send_events_ex(EVT_ID_SRV_MMS_UPDATE_STATUS, (void*)&msg_status);
    }
    srv_mms_send_events(EVT_ID_SRV_CURR_MSG_UPDATE, (void*)(&msg_id));
}

/* memory card   */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_change_storage_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Inmsg       [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_msg_change_storage_rsp(void *Inmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    srv_mms_um_refresh_ind_struct req;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_mma_change_msg_storage_rsp_struct *msg = (wap_mma_change_msg_storage_rsp_struct*) Inmsg;

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    if (g_srv_mark_several_cntx->msg_id[g_srv_mark_several_cntx->curr_index] == msg->msg_id)
    {
        srv_mms_get_msg_change_storage_rsp_hdlr(msg);
    }
    else
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
    {
        srv_mms_send_events_ex(EVT_ID_SRV_CHANGE_STORAGE, (void*)msg);
    }
if(msg->result == MMA_RESULT_OK)
    {
    /* mma_folder = srv_mms_convert_umbox_type_to_mma_folder(mmi_um_get_current_msg_box_type()); */
    memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
    //if (mma_folder == MMA_FOLDER_NONE)
    // {
    req.msg_box_type = mma_get_box(msg->msg_id);
    req.refresh_type = SRV_UM_REFRESH_CREATE_MSG;
    req.msg_id = msg->msg_id;
            if (req.msg_box_type != MMA_FOLDER_NONE)
            {
    srv_mms_um_refresh_msg_list(&req);
            }

    /* }
       else
       {
       req.msg_box_type = mma_folder;
       req.refresh_type = SRV_UM_REFRESH_NONE;
       srv_mms_um_refresh_msg_list(&req);
       } */
    }
    srv_mms_msg_update_count_and_status_icon();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_memory_card_pug_in_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_memory_card_pug_in_response(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mem_card_plug_in_out_res_struct *plug_in_info;

    srv_mms_um_refresh_ind_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plug_in_info = (mms_mem_card_plug_in_out_res_struct*) msg;
    if (plug_in_info->result == MMA_RESULT_OK)
    {
        mma_folder_enum mma_folder = (mma_folder_enum)srv_mms_convert_umbox_type_to_mma_folder(mmi_um_get_current_msg_box_type());

        memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
        if (mma_folder == MMA_FOLDER_NONE)
        {
            req.msg_box_type = MMA_FOLDER_ALL;
            req.refresh_type = SRV_UM_REFRESH_NONE;
            srv_mms_um_refresh_msg_list(&req);
        }
        else
        {
            req.msg_box_type = mma_folder;
            req.refresh_type = SRV_UM_REFRESH_NONE;
            srv_mms_um_refresh_msg_list(&req);
        }
        /* srv_mms_get_number_status_icon(); */
        srv_mms_msg_update_count_and_status_icon();
        srv_mms_bgsr_mem_card_plug_in_notify();
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_memory_card_pug_out_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_memory_card_pug_out_response(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mem_card_plug_in_out_res_struct *plug_out_info;
    srv_mms_um_refresh_ind_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plug_out_info = (mms_mem_card_plug_in_out_res_struct*) msg;
    if (plug_out_info->result == MMA_RESULT_OK)
    {
        mma_folder_enum mma_folder = (mma_folder_enum)srv_mms_convert_umbox_type_to_mma_folder(mmi_um_get_current_msg_box_type());

        memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
        if (mma_folder == MMA_FOLDER_NONE)
        {
            req.msg_box_type = MMA_FOLDER_ALL;
            req.refresh_type = SRV_UM_REFRESH_NONE;
            srv_mms_um_refresh_msg_list(&req);
        }
        else
        {
            req.msg_box_type = mma_folder;
            req.refresh_type = SRV_UM_REFRESH_NONE;
            srv_mms_um_refresh_msg_list(&req);
        }
        /* srv_mms_get_number_status_icon(); */
        srv_mms_msg_update_count_and_status_icon();
    }
    return MMI_FALSE;
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
/* memory card */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_insuf_mem_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mma_insuf_mem_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MMA_INSUF_MEM);
    mmi_frm_cb_emit_event((mmi_event_struct*) & evt);
}

#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_copy_to_archive_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_REQ to MMA
 * PARAMETERS
 *  process     [?]     
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_copy_to_archive_req(srv_mms_process_data_struct *process, srv_mms_copy_to_archive_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cpy_msg_to_archive_folder_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req =
        (wap_mma_cpy_msg_to_archive_folder_req_struct*)
        OslConstructDataPtr(sizeof(wap_mma_cpy_msg_to_archive_folder_req_struct));

    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = para->msg_id;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_REQ),
        0,
        MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_copy_to_archive_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_RSP
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_copy_to_archive_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    wap_mma_cpy_msg_to_archive_folder_rsp_struct *rsp = (wap_mma_cpy_msg_to_archive_folder_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    /* process = srv_mms_get_process_by_app_id(rsp->app_id); */
    if (!process)
    {
        return MMI_FALSE;
    }
    if (rsp->result == MMA_RESULT_OK)
    {
        srv_mms_msg_update_count_and_status_icon();
    }

    srv_mms_copy_to_archive_rsp_hdlr(process, msg);
    return MMI_FALSE;
}
#endif



/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_lite_viewer_data_req
 * DESCRIPTION
 *  Send MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_REQ to MMA
 * PARAMETERS
 *  process
 *  para
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_lite_viewer_data_req(srv_mms_process_data_struct *process, srv_mms_get_lite_viewer_data_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mms_thumbnail_and_attr_info_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
    req = (wap_mma_get_mms_thumbnail_and_attr_info_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_mms_thumbnail_and_attr_info_req_struct));
    
    process->req_id = mma_get_request_id();

    req->req_id = process->req_id;
    req->app_id = para->app_id;
    req->msg_id = para->msg_id;

    lite_req_counter++;
         
    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_REQ),
        0,
        MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_REQ,
        (oslParaType*) req,
        NULL);
    
    return;
}



/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_lite_viewer_data_rsp
 * DESCRIPTION
 *  Call back to MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_RSP 
 * PARAMETERS
 *  msg
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_get_lite_viewer_data_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    mmi_event_struct evt;
    wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct *rsp = (wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct *)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SRV_MMS_MAX_LITE_REQ == lite_req_counter)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_MMS_READY_FOR_LITE_VIEWER);
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }

    lite_req_counter--;
    process = srv_mms_get_process_by_req_id(rsp->req_id);
    if(!process)
    {
        return MMI_FALSE;
    }
    
    srv_mms_get_lite_viewer_data_rsp_hdlr(process, msg);
    return MMI_FALSE;
}


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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_message
 * DESCRIPTION
 *  Send Primitive
 * PARAMETERS
 *  MOD_SRC         [IN]        
 *  MOD_DEST        [IN]        
 *  MSG_SAP         [IN]        
 *  MSG_ID          [IN]        
 *  LOCAL           [?]         [?]
 *  PEER            [?]         [?]
 * LOCAL
 * PEER
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE Message; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Message.oslSrcId = MOD_SRC;
     * Message.oslDestId = MOD_DEST;
     * Message.oslSapId = MSG_SAP;
     * Message.oslMsgId = MSG_ID;
     * Message.oslDataPtr = LOCAL;
     * Message.oslPeerBuffPtr = PEER;
     * OslMsgSendExtQueue(&Message);
     */
    mmi_frm_send_ilm((oslModuleType) MOD_DEST, (oslMsgType) MSG_ID, (oslParaType*) LOCAL, (oslPeerBuffType*) PEER);

}

#endif /* __MMI_MMS_2__ */ 

