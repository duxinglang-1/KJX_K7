/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * MMSJSRSrvSndRcv.c
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

#include "MMI_features.h"
#ifdef __MMI_MMS_2__

/*  Include: MMI header file */
#if defined(MMS_SUPPORT)
#ifdef __MMI_UMMS_JSR205__
#include "MMSJsrSrvTypes.h"
#include "MMSJsrSrvProts.h"     /* Already Include Basic data types header files MMIDataType */
#include "MMSJSRSrvSndRcv.h"
/* Stack related header files */
#include "kal_public_defs.h"  /* All the primitives declaration */
/* send primitive related header files */
#include "stack_ltlcom.h"       /* allocate_ilm, msg_send_ext_queue */
       /* MMI_L4C_SAP, J2ME_WAP_SAP */
 /* ilm_struct, TD_CTRL */
#include "mmi_frm_queue_gprot.h"        /* MYQUEUE, OslConstructDataPtr */
#include "string.h"     /* strlen .. */
#include "Unicodexdcl.h"        /* mmi_ucs2XXX */

/* File system related header */
#include "fs_func.h"    /* FS_Open... */
#include "fs_type.h"    /* FS_HANDLE, FS_DIR_TYPE .. */
#include "fs_errcode.h" /* FS_PATH_NOT_FOUND */
#include "FileMgrSrvGProt.h"    /* SRV_FMGR_PUBLIC_DRV, srv_fmgr_async_XXX  */

/* MMC related header files */
#include "mmc_struct.h"
#include "mma_api.h"    /* MODE, folder_id, storage type, get_box, Get_home_dir */
#include "mmi_msg_struct.h"     /* Upload, Read, Delete operation structure */
#include "mma_struct.h"
#include "mms_sap_struct.h"     /* MMA_APP_ID_JSR */
#include "mms_adp.h"    /* mms_get_service_module */

/* Catcher log related Header files */
#include "MMI_inet_app_trc.h"   /* MMI_INET_TRC_G6_MMS, MMI_JSR_XXXX */
#include "DebugInitDef_Int.h"   /* MMI_TRACE */
#include "kal_trace.h"  /* TRACE_GROUP_6, kal_trace */

/* UCM related header files */
#include "UcmSrvGprot.h"        /* SRV_UCM_XXX  */

/* Memory manager related Header */
#include "MMSMemoryManagerSrv.h"        /* srv_mms_mem_mgr_app_adm_alloc/free */

/* XML Header file for Objects */
#include "MmsSrvGprot.h"        /* get content RSP. this file will check for the EVT_ID too  */
#include "MmsXMLDefSrv.h"
#include "wgui_categories_MMS_viewer.h" /* wgui_mv_slide_struct */

/* Applib header files */
#include "app_asyncfile.h"      /* applib_get_file_size */

/* BGSR header file */
#include "mmsbgsrsrvProt.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
#define JSR_MMS_POPUP_TIME    UI_POPUP_NOTIFYDURATION_TIME_2000
#endif 
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mma_mms_description_struct *g_jsr_mms_msg_detail;
static MMI_BOOL mma_is_ready = MMI_FALSE;

static U8 convert_jsr_priority_to_mma(U8 priority);
extern mma_setting_size_limit_enum srv_mms_sending_mms_size_limit(void);

/***************************************************************************** 
* Local Function
*****************************************************************************/
void srv_mms_jsr_fill_header(wap_mmc_recv_appmms_rsp_struct *resp, S8 **buffer, U32 *buf_size);
void srv_mms_jsr_reset_object_struct_msg(mma_mms_object_struct *object);

/*****************************************************************************
* Global Variable
*****************************************************************************/
/* jsr_context_struct jsr_cntx; */
extern jsr_context_struct *jsr_cntx_p;
extern jsr_appid_msgid_list *g_jsr_appid_object_list;

MMI_BOOL srv_mms_jsr_generate_recv_msg_body_part(
            U32 msgId,
            U8 *bdy_part_no,
            U8 total_objects,
            wap_mmc_read_appmms_msg_part_rsp_struct *response);
/*****************************************************************************
* Global Function
*****************************************************************************/
extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);
extern mma_folder_enum mma_get_box(kal_uint32 msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_mma_ready_ind_hdlr
 * DESCRIPTION
 *  This function will tell that mma is ready and we can send a primitive to MMA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_jsr_mma_ready_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_is_ready = MMI_TRUE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_mma_terminate_ind_hdlr
 * DESCRIPTION
 *  This function will tell that mma is not ready and we can't send a primitive to MMA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_mma_terminate_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_is_ready = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_translate_mmc_sim_id_to_mma
 * DESCRIPTION
 *  This function convert mmc sim enum to mma enum.
 * PARAMETERS
 *  sim_id      [IN]        
 *  kal_uint8(?)
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 srv_mms_jsr_translate_mmc_sim_id_to_mma(kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case MMC_SIM_CARD_SIM1:
            return MMA_SIM_ID_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMC_SIM_CARD_SIM2:
            return MMA_SIM_ID_SIM2;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMC_SIM_CARD_SIM3:
            return MMA_SIM_ID_SIM3;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMC_SIM_CARD_SIM4:
            return MMA_SIM_ID_SIM4;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
        default:
            return MMA_SIM_ID_SIM1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_check_jsr_in_sending_state
 * DESCRIPTION
 *  This function will tell that JSR is sending a mms of the input sim_ID.
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  kal_bool TRUE -- Sending a java mms
 *****************************************************************************/
kal_bool srv_mms_jsr_check_jsr_in_sending_state(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_HDR) || (JSR_CNTX->state == JSR_STATE_PROCESS_SEND_MSG_BDY) ||
         (JSR_CNTX->state == JSR_STATE_SEND_MSG)) && (JSR_CNTX->sim_Id == sim_id))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/* [START Send/Receive functioanlity] */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_send_appmms_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_SEND_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg             [?]         [?]         [?]         [?]         [?]         [?]
 *  not_used        [IN]        
 *  ilm_p           [?]         [?]         [?]         [?]
 *  mod_src(?)      [IN](?)(?)(?)
 *  peerBuf     [?]         [?](?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_send_appmms_req_hldr(void *msg, int not_used, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_send_appmms_req_struct *Message;
    U16 buffer_length = 0;
    U8 *pdu = NULL;
    peer_buff_struct *peer_ptr = ((ilm_struct*) ilm_p)->peer_buff_ptr;
    mmc_result_enum result;

    /* temp vaiable to count the multiple call */
    U8 total_call = 0;
    U8 csd_call = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = (wap_mmc_send_appmms_req_struct*) msg;

    if (JSR_CNTX->state != JSR_STATE_IDLE)
    {
        srv_mms_jsr_send_appmms_rsp(MMC_RESULT_BUSY, (int)((ilm_struct*) ilm_p)->src_mod_id);
    }
    else if (mma_is_ready == MMI_FALSE)
    {
        srv_mms_jsr_send_appmms_rsp(MMC_RESULT_MMS_NO_READY, (int)((ilm_struct*) ilm_p)->src_mod_id);
    }
    else
    {
        /* temp vaiable to count the multiple call */
        total_call = (U8) srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);
        csd_call = (U8) srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL);

        if ((total_call - csd_call) > 0)
        {
            /* there is no CSD call going on. Can't send the mms */
            srv_mms_jsr_send_appmms_rsp(MMC_RESULT_ACCESS_DENY, (int)((ilm_struct*) ilm_p)->src_mod_id);
        }
        else
        {
            JsrCleanContext();  /* clean context first */
            g_jsr_mms_msg_detail =
                (mma_mms_description_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_description_struct));
            ASSERT(g_jsr_mms_msg_detail);
            memset(g_jsr_mms_msg_detail, 0, sizeof(g_jsr_mms_msg_detail));      /* reset global buff for MMS data */

            g_jsr_mms_msg_detail->header =
                (mma_mms_description_header_struct*)
                srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_description_header_struct));
            ASSERT(g_jsr_mms_msg_detail->header);
            memset(g_jsr_mms_msg_detail->header, 0, sizeof(mma_mms_description_header_struct));

            g_jsr_mms_msg_detail->header->header =
                (mma_mms_header_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_header_struct));
            ASSERT(g_jsr_mms_msg_detail->header->header);
            memset(g_jsr_mms_msg_detail->header->header, 0, sizeof(mma_mms_header_struct));

            g_jsr_mms_msg_detail->body =
                (mma_mms_description_body_struct*)
                srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_description_body_struct));
            ASSERT(g_jsr_mms_msg_detail->body);
            memset(g_jsr_mms_msg_detail->body, 0, sizeof(mma_mms_description_body_struct));

            srv_mms_init_jsr_folder();

            JSR_CNTX->op = JSR_OP_SEND_MSG;
            JSR_CNTX->state = JSR_STATE_PROCESS_SEND_MSG_HDR;
            JSR_CNTX->total_media_obj_no = Message->bdy_part_no;
            JSR_CNTX->curr_media_obj_no = 0;
            JSR_CNTX->sim_Id = srv_mms_jsr_translate_mmc_sim_id_to_mma(Message->simId);
            JSR_CNTX->dest_mod_id = (int)((ilm_struct*) ilm_p)->src_mod_id;
            pdu = (U8*) get_pdu_ptr(peer_ptr, &buffer_length); /* system call */
            result = srv_mms_jsr_decode_mms_header(Message, pdu);       /* retrive header info */
            /* to create the XML */
            if (result != MMC_RESULT_OK)
            {
                srv_mms_jsr_send_appmms_rsp(MMC_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR, JSR_CNTX->dest_mod_id);
            }
            else
            {
                if ((JSR_CNTX->curr_media_obj_no) < (JSR_CNTX->total_media_obj_no))
                {
                    JSR_CNTX->state = JSR_STATE_PROCESS_SEND_MSG_BDY;
                    srv_mms_jsr_send_post_appmms_msg_part_ind(MMC_RESULT_OK, JSR_CNTX->dest_mod_id);
                }
                else
                {
                    srv_mms_jsr_create_mms_req();   /* send request to MMA to create MMS */
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_send_appmms_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_SEND_APPMMS_RSP primitive to Java
 * PARAMETERS
 *  result      [IN]        
 *  mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_send_appmms_rsp(mmc_result_enum result, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_send_appmms_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_send_appmms_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_send_appmms_rsp_struct));

    myMsgPtr->result = (U8) result;

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = (module_type)mod_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_SEND_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);

    if ((result != MMC_RESULT_BUSY) || (result != MMC_RESULT_MMS_NO_READY))
    {
        JsrCleanContext();  /* Clean the Jsr Context */
        srv_mms_jsr_reset_xml_struct_msg();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_send_post_appmms_msg_part_ind
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND primitive to Java
 * PARAMETERS
 *  result      [IN]        
 *  mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_send_post_appmms_msg_part_ind(mmc_result_enum result, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mmc_post_appmms_msg_part_ind_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_post_appmms_msg_part_ind_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_post_appmms_msg_part_ind_struct));
    myMsgPtr->result = (U8) result;

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = (module_type)mod_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_send_post_appmms_msg_part_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES primitive to Java
 * PARAMETERS
 *  msg         [?]         [?]     [?]     [?]     [?]     [?]
 *  mod_id      [IN]        
 *  U8 result(?)(?)(?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_send_post_appmms_msg_part_rsp(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_result_enum result = MMC_RESULT_OK;
    wap_mmc_post_appmms_msg_part_res_struct *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JSR_CNTX->state != JSR_STATE_PROCESS_SEND_MSG_BDY)
    {
        srv_mms_jsr_send_appmms_rsp(MMC_RESULT_ACCESS_DENY, mod_id);
        return;
    }
    Message = (wap_mmc_post_appmms_msg_part_res_struct*) msg;
    result = (mmc_result_enum)srv_mms_jsr_add_media_object(Message); /* add media object to MMS message */
    if (result != MMC_RESULT_OK)
    {
        srv_mms_jsr_send_appmms_rsp(result, mod_id);
        return;
    }

    /* increment current media object by 1 */
    JSR_CNTX->curr_media_obj_no = JSR_CNTX->curr_media_obj_no + 1;
    if ((JSR_CNTX->curr_media_obj_no) < (JSR_CNTX->total_media_obj_no))
    {
        JSR_CNTX->state = JSR_STATE_PROCESS_SEND_MSG_BDY;
        srv_mms_jsr_send_post_appmms_msg_part_ind(MMC_RESULT_OK, mod_id);
    }
    else
    {
        srv_mms_jsr_create_mms_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_create_mms_req
 * DESCRIPTION
 *  This function send the request to MMA to generate MMS, for which it sends the content of MMS in XML
 *  format.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_create_mms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *msg_req;

    // peer_buff_struct *peer_buff_ptr;
    //U32 read_size;
    //U16 peer_buff_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));
    msg_req->req_id = mma_get_request_id();
    JSR_CNTX->req_id = msg_req->req_id;

    msg_req->mode = MMA_MODE_RAW;
    msg_req->msg_id = 0;
    msg_req->app_id = MMA_APP_ID_JSR;
    msg_req->buffer_index = 0;
    msg_req->xml_size = 0;
    msg_req->more = MMI_FALSE;
    msg_req->content_info = g_jsr_mms_msg_detail;

    srv_mms_jsr_post_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_CREATE_REQ),
        0,
        MSG_ID_WAP_MMA_CREATE_REQ,
        (oslParaType*) msg_req,
        NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_create_for_send_mms_rsp
 * DESCRIPTION
 *  This function is response handler for create request
 * PARAMETERS
 *  inMsg       [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_create_for_send_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_is_ready == MMI_FALSE)
    {
        /* MMA is terminated. Abort request is already sent to Java */
        return;
    }
    MMI_ASSERT(msg_rsp->req_id == JSR_CNTX->req_id);

    if (JSR_CNTX->op != JSR_OP_SEND_MSG)
    {
        if (msg_rsp->msg_id != 0)
        {
            srv_mms_jsr_delete_msg_req(0, msg_rsp->msg_id);
        }
        return;
    }
    if (msg_rsp->result != MMA_RESULT_OK)
    {
    #ifndef __COSMOS_MMI_PACKAGE__
    #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
        if (msg_rsp->result == MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED)
        {
            /* send an event to Application to show the Pop Up. */
            srv_mms_send_events(EVT_ID_SRV_JSR_JAVA_MMS_SEND_ERROR, NULL);
        }
    #endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
    #endif /* __COSMOS_MMI_PACKAGE__ */ 
        srv_mms_jsr_send_appmms_rsp(MMC_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM, JSR_CNTX->dest_mod_id);
    }
    else
    {
        if (msg_rsp->msg_id == 0)
        {   /* No message id and hence more XML content needs to send */
            wap_mma_create_req_struct *msg_req;
            peer_buff_struct *peer_buff_ptr;
            U32 read_size;
            S32 remaining_size;
            U16 peer_buff_len = 0;

            MMI_ASSERT(msg_rsp->buffer_index == (JSR_CNTX->buffer_index + 1));
            msg_req = (wap_mma_create_req_struct*) OslConstructDataPtr(sizeof(wap_mma_create_req_struct));
            msg_req->req_id = JSR_CNTX->req_id;
            msg_req->app_id = MMA_APP_ID_JSR;

            /* reset */
            msg_req->mode = MMA_MODE_RAW;
            msg_req->msg_id = 0;

            MAKE_JSR_XML_FILE(msg_req->xml_filepath);
            msg_req->xml_size = JSR_CNTX->xml_file_size;

            JSR_CNTX->buffer_index++;
            msg_req->buffer_index = JSR_CNTX->buffer_index;

            remaining_size = JSR_CNTX->xml_file_size - (msg_req->buffer_index * SRV_MMS_MAX_XML_SIZE_IN_PEER_BUFFER);

            if (remaining_size <= SRV_MMS_MAX_XML_SIZE_IN_PEER_BUFFER)
            {
                msg_req->buffer_size = remaining_size;
                msg_req->more = KAL_FALSE;
            }
            else
            {
                msg_req->buffer_size = SRV_MMS_MAX_XML_SIZE_IN_PEER_BUFFER;
                msg_req->more = KAL_TRUE;
            }

            peer_buff_ptr = construct_peer_buff((kal_uint16) msg_req->buffer_size, 0, 0, TD_CTRL);

            if (FS_Read
                (JSR_CNTX->file_handle, get_pdu_ptr(peer_buff_ptr, &peer_buff_len), msg_req->buffer_size,
                 &read_size) != FS_NO_ERROR || read_size != msg_req->buffer_size)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_JSR_SEND_CREATE_RSP, read_size, msg_req->buffer_size);
                srv_mms_jsr_send_appmms_rsp(MMC_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM, JSR_CNTX->dest_mod_id);
                return;
            }

            srv_mms_jsr_post_message(
                MOD_MMI,
                mms_get_service_module(MSG_ID_WAP_MMA_CREATE_REQ),
                0,
                MSG_ID_WAP_MMA_CREATE_REQ,
                (oslParaType*) msg_req,
                peer_buff_ptr);
        }
        /* sending XML content completes */
        else
        {
            FS_Close(JSR_CNTX->file_handle);
            JSR_CNTX->file_handle = 0;
            JSR_CNTX->msgId = msg_rsp->msg_id;
            /* free the memory now */
            srv_mms_jsr_reset_xml_struct_msg();
            srv_mms_jsr_send_msg_req((U32) JSR_CNTX->msgId);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_send_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_send_msg_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JSR_CNTX->state = JSR_STATE_SEND_MSG;
    if (JSR_CNTX->sim_Id == 0)
    {
        JSR_CNTX->sim_Id = MMA_SIM_ID_SIM1;
    }
    srv_mms_bgsr_send_java_msg_req((U32) msg_id, JSR_CNTX->sim_Id);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_update_send_msg_icon
 * DESCRIPTION
 *  To update the sending mms Icon shown by UM
 * PARAMETERS
 *  msg_id      [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_update_send_msg_icon(U32 msg_id, U32 status)
{
#ifdef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_update_status_struct msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_status.msg_id = msg_id;
    if (status == SRV_MMS_BGSR_STATUS_SENDING)
    {
        msg_status.status = SRV_MMS_MSG_STATUS_SENDING;
    }
    else if (status == SRV_MMS_BGSR_STATUS_SEND_FAIL)
    {
        msg_status.status = SRV_MMS_MSG_STATUS_SENDING_FAILED;
    }
    else
    {
        msg_status.status = SRV_MMS_MSG_STATUS_SENT;
    }
    srv_mms_send_events_ex(EVT_ID_SRV_MMS_UPDATE_STATUS, (void*)&msg_status);
    return;
#endif /* __COSMOS_MMI_PACKAGE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_send_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 *  inMsg       [?]     [?]     [?]     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_send_msg_rsp(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_is_ready == MMI_FALSE)
    {
        /* MMA is terminated. Abort request is already sent to Java */
        return;
    }
    if (JSR_CNTX->op == JSR_OP_IDLE)
    {
        /* JSR context get De-initialized */
        srv_mms_jsr_reset_xml_struct_msg();
        return;
    }
    if (JSR_CNTX->is_abort_get_req)
    {
        JsrCleanContext();  /* Clean the Jsr Context */
        /* srv_mms_jsr_reset_xml_struct_msg(); */
    }
    else if (srv_mms_jsr_translate_bgsr_to_mmc_result(result) != MMC_RESULT_OK)
    {
        srv_mms_jsr_send_appmms_rsp(MMC_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM, JSR_CNTX->dest_mod_id);
    }
    else
    {
        srv_mms_jsr_send_appmms_rsp(MMC_RESULT_OK, JSR_CNTX->dest_mod_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_decode_mms_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [?]     [?]     [?]     [?]     [?]     [?]     [?]
 *  buffer      [?]     [?]     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
mmc_result_enum srv_mms_jsr_decode_mms_header(wap_mmc_send_appmms_req_struct *message, U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 datalen = 0;
    mmc_result_enum eRet = MMC_RESULT_OK;

    S8 *address = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jsr_mms_msg_detail->body->bgColor = SRV_MMS_JSR_DEFAULT_BG_COLOR;
    g_jsr_mms_msg_detail->body->fgColor = SRV_MMS_JSR_DEFAULT_FG_COLOR;
    //g_jsr_mms_xml_msg.to_num = message->to_addr_no;
    //g_jsr_mms_xml_msg.cc_num = message->cc_addr_no;
    //g_jsr_mms_xml_msg.bcc_num = message->bcc_addr_no;
    g_jsr_mms_msg_detail->body->obj_no = message->bdy_part_no;
    g_jsr_mms_msg_detail->body->slide_no = 0;   /* g_jsr_mms_xml_msg.total_object_num; */
    g_jsr_mms_msg_detail->header->header->priority = convert_jsr_priority_to_mma(message->priority);
    g_jsr_mms_msg_detail->header->header->delivery_time = message->delivery_time;

    datalen = strlen((const char *)message->app_id);
    if (datalen > 0)
    {
        if (datalen > 100)
        {
            datalen = 100;
        }
        g_jsr_mms_msg_detail->header->header->app_id = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(datalen + 1);
        ASSERT(g_jsr_mms_msg_detail->header->header->app_id);
        memset(g_jsr_mms_msg_detail->header->header->app_id, 0x00, datalen + 1);
        strncpy((PS8) g_jsr_mms_msg_detail->header->header->app_id, (PS8) message->app_id, datalen);
    }
    datalen = strlen((const char *)message->reply_app_id);
    if (datalen > 0)
    {
        if (datalen > 100)
        {
            datalen = 100;
        }
        g_jsr_mms_msg_detail->header->header->reply_app_id = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(datalen + 1);
        ASSERT(g_jsr_mms_msg_detail->header->header->reply_app_id);
        memset(g_jsr_mms_msg_detail->header->header->reply_app_id, 0x00, datalen + 1);
        strncpy((PS8) g_jsr_mms_msg_detail->header->header->reply_app_id, (PS8) message->reply_app_id, datalen);
    }

    g_jsr_mms_msg_detail->header->header->to = NULL;
    g_jsr_mms_msg_detail->header->header->cc = NULL;
    g_jsr_mms_msg_detail->header->header->bcc = NULL;
    /* g_jsr_mms_msg_detail->header->header->from = NULL; */

    g_jsr_mms_msg_detail->header->header->read_reply = SRV_MMS_JSR_DEFAULT_READ_REPORT_DURING_SENDING;
    g_jsr_mms_msg_detail->header->header->delivery_report = SRV_MMS_JSR_DEFAULT_DELIVERY_REPORT_DURING_SENDING;

    g_jsr_mms_msg_detail->header->header->expiry_time = SRV_MMS_JSR_DEFAULT_EXPIRY_TIME;
    g_jsr_mms_msg_detail->header->header->visibility = SRV_MMS_JSR_DEFAULT_SENDER_VISIBILTY;

    if (buffer != NULL)
    {   /* Retrieve Subject */
        {
            U32 subject_len = *(U32*) buffer;

            if (subject_len > 0)
            {   /* there is some subject, cal length and then copy it after converting */
                g_jsr_mms_msg_detail->header->header->subject.text =
                    (S8*) srv_mms_mem_mgr_app_adm_alloc(subject_len + 1);
                if (NULL == g_jsr_mms_msg_detail->header->header->subject.text)
                {
                    eRet = MMC_RESULT_INSUFFICIENT_MEMORY;
                    goto END;
                }
                memset(g_jsr_mms_msg_detail->header->header->subject.text, 0x00, subject_len + 1);
                memcpy(g_jsr_mms_msg_detail->header->header->subject.text, buffer + 8, subject_len);
                datalen = subject_len + 8;
            }
            else
            {
                datalen = 4;
            }
        }

        /* Retrieve to addresses */
        while (message->to_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            /* currently XML encoder support only these two address types */
            if ((addrType != SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER) && (addrType != SRV_MMS_ADDRESS_TYPE_EMAIL))
            {
                eRet = MMC_RESULT_INVALID_PARAMETER;
                goto END;
            }
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

            address = (S8*) srv_mms_mem_mgr_app_adm_alloc(address_len + 1);
            if (NULL == address)
            {
                eRet = MMC_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }
            memset(address, 0, address_len + 1);

            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            ret = srv_mms_jsr_add_address_in_addresse_list(address, (srv_mms_address_type_enum)addrType, SRV_MMS_ADDRESS_GROUP_TYPE_TO);
            if (ret != 0)
            {
                eRet = MMC_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            if (address != NULL)
            {
                srv_mms_mem_mgr_app_adm_free(address);
                address = NULL;
            }
            message->to_addr_no--;
        }

        /* Retrieve cc addresses */
        while (message->cc_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            /* currently XML encoder support only these two address types */
            if ((addrType != SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER) && (addrType != SRV_MMS_ADDRESS_TYPE_EMAIL))
            {
                eRet = MMC_RESULT_INVALID_PARAMETER;
                goto END;
            }
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

            address = (S8*) srv_mms_mem_mgr_app_adm_alloc(address_len + 1);
            if (NULL == address)
            {
                eRet = MMC_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }
            memset(address, 0, address_len + 1);
            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            ret = srv_mms_jsr_add_address_in_addresse_list(address, (srv_mms_address_type_enum)addrType, SRV_MMS_ADDRESS_GROUP_TYPE_CC);
            if (ret != 0)
            {
                eRet = MMC_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }

            if (address != NULL)
            {
                srv_mms_mem_mgr_app_adm_free(address);
                address = NULL;
            }
            message->cc_addr_no--;
        }

        /* Retrieve bcc addresses */
        while (message->bcc_addr_no > 0)
        {
            U32 address_len = 0;
            U32 addrType = 0;
            U8 ret = 0;

            memcpy(&addrType, (char*)(buffer + datalen), 4);
            /* currently XML encoder support only these two address types */
            if ((addrType != SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER) && (addrType != SRV_MMS_ADDRESS_TYPE_EMAIL))
            {
                eRet = MMC_RESULT_INVALID_PARAMETER;
                goto END;
            }
            memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

            address = (S8*) srv_mms_mem_mgr_app_adm_alloc(address_len + 1);
            if (address == NULL)
            {
                eRet = MMC_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }
            memset(address, 0, address_len + 1);
            memcpy(address, buffer + datalen + 8, address_len);
            datalen += address_len + 8;

            ret = srv_mms_jsr_add_address_in_addresse_list(address, (srv_mms_address_type_enum)addrType, SRV_MMS_ADDRESS_GROUP_TYPE_BCC);
            if (ret != 0)
            {
                eRet = MMC_RESULT_INSUFFICIENT_MEMORY;
                goto END;
            }
            if (address != NULL)
            {
                srv_mms_mem_mgr_app_adm_free(address);
                address = NULL;
            }
            message->bcc_addr_no--;
        }
    }

  END:
    if (address != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(address);
        address = NULL;
    }
    return eRet;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_add_address_in_addresse_list
 * DESCRIPTION
 *  Add the input address in address list
 * PARAMETERS
 *  address     [?]         [?]         [?]         [?]         [?]         [?]     [?]
 *  type        [IN]        
 *  group       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mms_jsr_add_address_in_addresse_list(
    S8 *address,
    srv_mms_address_type_enum type,
    srv_mms_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_addr_list_struct *address_temp_p, *address_node;
    U8 addr_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    address_node = (mma_mms_addr_list_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_addr_list_struct));
    if (address_node == NULL)
    {
        return MMC_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(address_node, 0, sizeof(mma_mms_addr_list_struct));
    addr_len = strlen(address);

    address_node->address = (kal_char *) srv_mms_mem_mgr_app_adm_alloc(addr_len + 1);
    if (address_node->address == NULL)
    {
        return MMC_RESULT_INSUFFICIENT_MEMORY;
    }

    address_node->addr_type = type;

    if (address_node->addr_type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
    {
        strncpy((PS8) address_node->address, (PS8) address, addr_len);
        address_node->addr_type = MMA_ADDR_TYPE_PHONE_NUMBER;
    }
    else
    {
        strncpy((PS8) address_node->address, address, addr_len);
        address_node->addr_type = MMA_ADDR_TYPE_EMAIL;
    }

    address_node->group = group;

    address_node->next = NULL;

    if (group == SRV_MMS_ADDRESS_GROUP_TYPE_TO)
    {
        if (g_jsr_mms_msg_detail->header->header->to == NULL)
        {
            address_node->prev = address_node;
            g_jsr_mms_msg_detail->header->header->to = address_node;
        }
        else
        {
            address_temp_p = g_jsr_mms_msg_detail->header->header->to;

            while (address_temp_p->next != NULL)
            {
                address_temp_p = address_temp_p->next;
            }

            address_node->prev = address_temp_p;
            address_temp_p->next = address_node;

        }
    }
    else if (group == SRV_MMS_ADDRESS_GROUP_TYPE_CC)
    {
        if (g_jsr_mms_msg_detail->header->header->cc == NULL)
        {
            address_node->prev = address_node;
            g_jsr_mms_msg_detail->header->header->cc = address_node;
        }
        else
        {
            address_temp_p = g_jsr_mms_msg_detail->header->header->cc;

            while (address_temp_p->next != NULL)
            {
                address_temp_p = address_temp_p->next;
            }

            address_node->prev = address_temp_p;
            address_temp_p->next = address_node;

        }
    }
    else if (group == SRV_MMS_ADDRESS_GROUP_TYPE_BCC)
    {
        if (g_jsr_mms_msg_detail->header->header->bcc == NULL)
        {
            address_node->prev = address_node;
            g_jsr_mms_msg_detail->header->header->bcc = address_node;
        }
        else
        {
            address_temp_p = g_jsr_mms_msg_detail->header->header->bcc;

            while (address_temp_p->next != NULL)
            {
                address_temp_p = address_temp_p->next;
            }

            address_node->prev = address_temp_p;
            address_temp_p->next = address_node;

        }
    }
    return MMC_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_add_media_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_jsr_add_media_object(wap_mmc_post_appmms_msg_part_res_struct *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *media_buffer_p = NULL;
    U8 *temp_buffer_p = NULL;
    FS_HANDLE file_handle = -1;
    U32 file_size;
    U32 read_cnt;
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((message == NULL)
        || (message->filepath_len == 0)
        || (message->content_type_len == 0) || (message->content_id_len == 0 && message->content_location_len == 0))
    {
        return MMC_RESULT_ERROR_MSG_CORRUPTED;
    }
    if (strstr((S8*) message->content_type, "text/plain") != NULL)
    {
        if (message->encoding_scheme == MMC_UNKNOWN_CHARSET)
        {
            result = srv_mms_jsr_insert_object(message, SRV_MMS_OBJECT_TYPE_TEXT);
            if (result != MMC_RESULT_OK)
            {
                goto ERROR_HANDLE;
            }
        }
        else
        {
            file_handle = FS_Open((U16*) message->filepath, FS_READ_ONLY);

            if (file_handle < 0)
            {
                return MMC_RESULT_ERROR_MSG_CORRUPTED;
            }

            FS_GetFileSize(file_handle, &file_size);
            if (file_size > 0)
            {
                temp_buffer_p = (U8*) srv_mms_mem_mgr_app_adm_alloc((file_size + 1));
                if (temp_buffer_p == NULL)
                {
                    result = MMC_RESULT_INSUFFICIENT_MEMORY;
                    return result;
                }
                memset(temp_buffer_p, 0, file_size + 1);
                media_buffer_p = (U8*) srv_mms_mem_mgr_app_adm_alloc(ENCODING_LENGTH * (file_size + 1));
                if (media_buffer_p == NULL)
                {
                    result = MMC_RESULT_INSUFFICIENT_MEMORY;
                    goto ERROR_HANDLE;
                }
                memset(media_buffer_p, 0, ENCODING_LENGTH * (file_size + 1));

                if (FS_Read(file_handle, temp_buffer_p, file_size, &read_cnt) != FS_NO_ERROR || file_size != read_cnt)
                {
                    result = MMC_RESULT_ERROR_MSG_CORRUPTED;
                    goto ERROR_HANDLE;
                }
                if (message->encoding_scheme == MMC_US_ASCII)
                {
                    mmi_asc_to_ucs2((S8*) media_buffer_p, (S8*) temp_buffer_p);
                }
                else if (message->encoding_scheme == MMC_UTF8)
                {
                    mmi_chset_utf8_to_ucs2_string(
                        (U8*) media_buffer_p,
                        (U32) ENCODING_LENGTH * (file_size + 1),
                        (U8*) temp_buffer_p);
                }
                else
                {
                    result = MMC_RESULT_INVALID_MESSAGE;
                    goto ERROR_HANDLE;
                }
                result = srv_mms_jsr_insert_text_object(message, media_buffer_p);
                if (result != MMC_RESULT_OK)
                {
                    goto ERROR_HANDLE;
                }
            }
		    else
		    {
			    result = MMC_RESULT_OK;
		    }

            FS_Close(file_handle);
            file_handle = -1;
        }
    }
    else if (strstr((S8*) message->content_type, "audio/") != NULL)
    {
        result = srv_mms_jsr_insert_object(message, SRV_MMS_OBJECT_TYPE_AUDIO);
        if (result != MMC_RESULT_OK)
        {
            goto ERROR_HANDLE;
        }
    }
    else if (strstr((S8*) message->content_type, "video/") != NULL)
    {
        result = srv_mms_jsr_insert_object(message, SRV_MMS_OBJECT_TYPE_VIDEO);
        if (result != MMC_RESULT_OK)
        {
            goto ERROR_HANDLE;
        }
    }
    else if (strstr((S8*) message->content_type, "image/") != NULL)
    {
        result = srv_mms_jsr_insert_object(message, SRV_MMS_OBJECT_TYPE_IMAGE);
        if (result != MMC_RESULT_OK)
        {
            goto ERROR_HANDLE;
        }
    }
    else
    {
        result = srv_mms_jsr_insert_object(message, SRV_MMS_OBJECT_TYPE_UNKNOWN);
        if (result != MMC_RESULT_OK)
        {
            goto ERROR_HANDLE;
        }
    }

  ERROR_HANDLE:

    if (temp_buffer_p != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(temp_buffer_p);
    }
    if (media_buffer_p != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(media_buffer_p);
    }
    if(file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_insert_text_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message             [?]     [?]
 *  media_buffer_p      [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_jsr_insert_text_object(wap_mmc_post_appmms_msg_part_res_struct *message, U8 *media_buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *text_obj;
    U8 result = MMC_RESULT_INSUFFICIENT_MEMORY;
    U32 file_name_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_obj = (mma_mms_object_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_object_struct));
    if (text_obj == NULL)
    {
        return result;
    }
    memset(text_obj, 0, sizeof(mma_mms_object_struct));

    text_obj->file_path_ucs =
        (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH + 2);
    text_obj->file_path = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1);
    if ((text_obj->file_path_ucs == NULL) || (text_obj->file_path == NULL))
    {
        goto END;
    }
    text_obj->file_name_ucs =
        (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH + 2);
    text_obj->file_name = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1);
    if ((text_obj->file_name_ucs == NULL) || (text_obj->file_name == NULL))
    {
        goto END;
    }

    MAKE_JSR_XML_TEXT_FILE(text_obj->file_path_ucs, JSR_CNTX->counter);
    /* mmi_ucs2cpy((S8*) text_obj->file_name_ucs, (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*)text_obj->file_path_ucs)); */
    mmi_ucs2_to_asc((S8*) text_obj->file_path, (S8*) text_obj->file_path_ucs);
    mmi_ucs2_to_asc(
        (S8*) text_obj->file_name,
        (S8*) srv_fmgr_path_get_filename_ptr((WCHAR*) text_obj->file_path_ucs));

    text_obj->mime_str = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(message->content_type_len + 1);
    if (text_obj->mime_str == NULL)
    {
        goto END;
    }
    memset(text_obj->mime_str, 0, message->content_type_len + 1);
    strncpy((S8*) text_obj->mime_str, (S8*) message->content_type, message->content_type_len);
    text_obj->content_id = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(message->content_id_len + 1);
    if (text_obj->content_id == NULL)
    {
        goto END;
    }
    memset(text_obj->content_id, 0, (message->content_id_len + 1) * ENCODING_LENGTH);
    strncpy((S8*) text_obj->content_id, (S8*) message->content_id, message->content_id_len);

    file_name_len = strlen((S8*) text_obj->file_name);
    text_obj->content_location = (kal_char *) srv_mms_mem_mgr_app_adm_alloc(file_name_len + 1);
    if (text_obj->content_location == NULL)
    {
        goto END;
    }
    strncpy((S8*) text_obj->content_location, (S8*) text_obj->file_name, file_name_len);

    result = srv_mms_jsr_fill_text_data(text_obj->file_path_ucs, (U16*) media_buffer_p);
    if (result != MMC_RESULT_OK)
    {
        goto END;
    }

    text_obj->size = applib_get_file_size((kal_wchar*) text_obj->file_path_ucs);
    text_obj->encoding_scheme = message->encoding_scheme;

    /* put text data in a file */
    text_obj->id = JSR_CNTX->counter++;
    text_obj->reference_count = 1;
    text_obj->type = SRV_MMS_OBJECT_TYPE_TEXT;
    text_obj->drm_type = MMA_DRM_NONE;
    text_obj->is_virtual_file = KAL_FALSE;
    text_obj->next = NULL;

    /* Ashok ToDo: write code for new flow */
    if (g_jsr_mms_msg_detail->body->objects == NULL)
    {
        text_obj->prev = text_obj;
        g_jsr_mms_msg_detail->body->objects = text_obj;
    }
    else
    {
        mma_mms_object_struct *temp_p;

        temp_p = g_jsr_mms_msg_detail->body->objects;

        while (temp_p->next != NULL)
        {
            temp_p = temp_p->next;
        }

        text_obj->prev = temp_p;
        temp_p->next = text_obj;
    }
    return MMC_RESULT_OK;
  END:
    if (text_obj && text_obj->file_path_ucs)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj->file_path_ucs);
        text_obj->file_path_ucs = NULL;
    }
    if (text_obj && text_obj->file_path)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj->file_path);
        text_obj->file_path = NULL;
    }
    if (text_obj && text_obj->file_name_ucs)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj->file_name_ucs);
        text_obj->file_name_ucs = NULL;
    }
    if (text_obj && text_obj->file_name)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj->file_name);
        text_obj->file_name = NULL;
    }
    if (text_obj && text_obj->mime_str)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj->mime_str);
        text_obj->mime_str = NULL;
    }
    if (text_obj && text_obj->content_id)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj->content_id);
        text_obj->content_id = NULL;
    }
    if (text_obj && text_obj->content_location)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj->content_location);
        text_obj->content_location = NULL;
    }
    if (text_obj)
    {
        srv_mms_mem_mgr_app_adm_free(text_obj);
        text_obj = NULL;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_insert_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message     [?]         [?]         [?]         [?]         [?]
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_jsr_insert_object(wap_mmc_post_appmms_msg_part_res_struct *message, srv_mms_viewer_object_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *temp_obj = NULL;
    U8 file_name[MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH];
    U8 result = MMC_RESULT_INSUFFICIENT_MEMORY;
    S32 fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_obj = (mma_mms_object_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_mms_object_struct));
    if (temp_obj == NULL)
    {
        return result;
    }
    memset(temp_obj, 0, sizeof(mma_mms_object_struct));

    temp_obj->size = applib_get_file_size((kal_wchar*) message->filepath);
    if(temp_obj->size)
    {
        MAKE_JSR_MEDIA_FILE(file_name, JSR_CNTX->counter);
        fh = (S32) FS_Move(message->filepath, (U16*) file_name, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0);
        if (fh < 0)
        {
            srv_mms_mem_mgr_app_adm_free(temp_obj);
            return (U8) fh;
        }

        temp_obj->file_path_ucs =
            (kal_wchar*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH + 2);
        temp_obj->file_path = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1);
        if ((temp_obj->file_path_ucs == NULL) || (temp_obj->file_path == NULL))
        {
            goto END;
        }
        mmi_ucs2cpy((S8*) temp_obj->file_path_ucs, (S8*) file_name);
        mmi_ucs2_to_asc((S8*) temp_obj->file_path, (S8*) file_name);

        temp_obj->file_name = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1);
        if (temp_obj->file_name == NULL)
        {
            goto END;
        }
        mmi_ucs2_to_asc(
            (S8*) temp_obj->file_name,
            (S8*) srv_fmgr_path_get_filename_ptr((WCHAR*) temp_obj->file_path_ucs));
        srv_mms_mem_mgr_app_adm_free(temp_obj->file_path_ucs);
        temp_obj->file_path_ucs = NULL;

        temp_obj->mime_str = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(message->content_type_len + 1);
        if (temp_obj->mime_str == NULL)
        {
            goto END;
        }
        memset(temp_obj->mime_str, 0, message->content_type_len + 1);
        strncpy((S8*) temp_obj->mime_str, (S8*) message->content_type, message->content_type_len);

        temp_obj->content_id = (kal_char*) srv_mms_mem_mgr_app_adm_alloc(message->content_id_len + 1);
        if (temp_obj->content_id == NULL)
        {
            goto END;
        }
        memset(temp_obj->content_id, 0, message->content_id_len + 1);
        strncpy((S8*) temp_obj->content_id, (S8*) message->content_id, message->content_id_len);

        temp_obj->content_location = (kal_char *) srv_mms_mem_mgr_app_adm_alloc(message->content_location_len + 1);
        if (temp_obj->content_location == NULL)
        {
            goto END;
        }
        memset(temp_obj->content_location, 0, message->content_location_len + 1);
        strncpy((S8*) temp_obj->content_location, (S8*) message->content_location, message->content_location_len);

        temp_obj->offset = 0;
        temp_obj->type = type;
        temp_obj->drm_type = MMA_DRM_NONE;
        temp_obj->is_virtual_file = KAL_FALSE;
        temp_obj->reference_count = 1;
        temp_obj->id = JSR_CNTX->counter++;
        temp_obj->next = NULL;
        temp_obj->prev = NULL;

        /* Ashok ToDo: write code for new flow */
        if (g_jsr_mms_msg_detail->body->objects == NULL)
        {
            temp_obj->prev = temp_obj;
            g_jsr_mms_msg_detail->body->objects = temp_obj;
        }
        else
        {
            mma_mms_object_struct *temp_p;

            temp_p = g_jsr_mms_msg_detail->body->objects;

            while (temp_p->next != NULL)
            {
                temp_p = temp_p->next;
            }

            temp_obj->prev = temp_p;
            temp_p->next = temp_obj;
        }
        return MMC_RESULT_OK;
    }
    else
    {
        /* return OK result but did not add this object in mms pdu */
        result = MMC_RESULT_OK;
    }
  END:
    if (temp_obj && temp_obj->file_path_ucs)
    {
        srv_mms_mem_mgr_app_adm_free(temp_obj->file_path_ucs);
        temp_obj->file_path_ucs = NULL;
    }
    if (temp_obj && temp_obj->file_path)
    {
        srv_mms_mem_mgr_app_adm_free(temp_obj->file_path);
        temp_obj->file_path = NULL;
    }
    if (temp_obj && temp_obj->file_name)
    {
        srv_mms_mem_mgr_app_adm_free(temp_obj->file_name);
        temp_obj->file_name = NULL;
    }
    if (temp_obj && temp_obj->mime_str)
    {
        srv_mms_mem_mgr_app_adm_free(temp_obj->mime_str);
        temp_obj->mime_str = NULL;
    }
    if (temp_obj && temp_obj->content_id)
    {
        srv_mms_mem_mgr_app_adm_free(temp_obj->content_id);
        temp_obj->content_id = NULL;
    }
    if (temp_obj && temp_obj->content_location)
    {
        srv_mms_mem_mgr_app_adm_free(temp_obj->content_location);
        temp_obj->content_location = NULL;
    }
    if (temp_obj)
    {
        srv_mms_mem_mgr_app_adm_free(temp_obj);
        temp_obj = NULL;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_reset_object_struct_msg
 * DESCRIPTION
 *  This functions reset the resourses held by object.
 * PARAMETERS
 *  object      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_reset_object_struct_msg(mma_mms_object_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *temp_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (object)
    {
        temp_object = object;
        object = object->next;

        if (temp_object == NULL)
        {
            break;
        }
        if (temp_object->mime_str)
        {
            srv_mms_mem_mgr_app_adm_free(temp_object->mime_str);
        }
        if (temp_object->file_path)
        {
            srv_mms_mem_mgr_app_adm_free(temp_object->file_path);
        }
        if (temp_object->file_name)
        {
            srv_mms_mem_mgr_app_adm_free(temp_object->file_name);
        }
        if (temp_object->file_path_ucs)
        {
            FS_Delete(temp_object->file_path_ucs);
            srv_mms_mem_mgr_app_adm_free(temp_object->file_path_ucs);
        }
        if (temp_object->file_name_ucs)
        {
            srv_mms_mem_mgr_app_adm_free(temp_object->file_name_ucs);
        }
        if (temp_object->content_id)
        {
            srv_mms_mem_mgr_app_adm_free(temp_object->content_id);
        }
        if (temp_object->content_location)
        {
            srv_mms_mem_mgr_app_adm_free(temp_object->content_location);
        }
        if (temp_object->content_type)
        {
            srv_mms_mem_mgr_app_adm_free(temp_object->content_type);
        }
        srv_mms_mem_mgr_app_adm_free(temp_object);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_reset_xml_struct_msg
 * DESCRIPTION
 *  This functions reset the resourses held by xml generation process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_reset_xml_struct_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_slide_struct *slide = NULL, *curr_slide = NULL;
    mma_mms_addr_list_struct *to, *curr_to;
    mma_mms_addr_list_struct *cc, *curr_cc;
    mma_mms_addr_list_struct *bcc, *curr_bcc;
    mma_mms_addr_list_struct *from;
    mma_mms_attachment_info_struct *attachment = NULL, *curr_attachment = NULL;
    mma_mms_object_struct *object_head = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    to = curr_to = cc = curr_cc = bcc = curr_bcc = from = NULL;
    if (!g_jsr_mms_msg_detail)
    {
        return;
    }
    if (g_jsr_mms_msg_detail->header && g_jsr_mms_msg_detail->header->header)
    {
        to = g_jsr_mms_msg_detail->header->header->to;
        cc = g_jsr_mms_msg_detail->header->header->cc;
        bcc = g_jsr_mms_msg_detail->header->header->bcc;
        from = g_jsr_mms_msg_detail->header->header->from;
    }
    if (g_jsr_mms_msg_detail->body)
    {
        slide = g_jsr_mms_msg_detail->body->slides;
        attachment = g_jsr_mms_msg_detail->body->attachment;
        object_head = g_jsr_mms_msg_detail->body->objects;
    }

    while (slide)
    {
        /* free the Text object */
        if (slide->txt.alt)
        {
            srv_mms_mem_mgr_app_adm_free(slide->txt.alt);
        }
        if (slide->txt.region_area)
        {
            srv_mms_mem_mgr_app_adm_free(slide->txt.region_area);
        }
        if (slide->txt.object)
        {
            srv_mms_jsr_reset_object_struct_msg(slide->txt.object);
        }

        /* free the image context */
        if (slide->img.alt)
        {
            srv_mms_mem_mgr_app_adm_free(slide->img.alt);
        }
        if (slide->img.region_area)
        {
            srv_mms_mem_mgr_app_adm_free(slide->img.region_area);
        }
        if (slide->img.object)
        {
            srv_mms_jsr_reset_object_struct_msg(slide->img.object);
        }
        /* free the Audio context */
        if (slide->aud.alt)
        {
            srv_mms_mem_mgr_app_adm_free(slide->aud.alt);
        }
        if (slide->aud.region_area)
        {
            srv_mms_mem_mgr_app_adm_free(slide->aud.region_area);
        }
        if (slide->aud.object)
        {
            srv_mms_jsr_reset_object_struct_msg(slide->aud.object);
        }
        /* free the video context */
        if (slide->vid.alt)
        {
            srv_mms_mem_mgr_app_adm_free(slide->vid.alt);
        }
        if (slide->vid.region_area)
        {
            srv_mms_mem_mgr_app_adm_free(slide->vid.region_area);
        }
        if (slide->vid.object)
        {
            srv_mms_jsr_reset_object_struct_msg(slide->vid.object);
        }
        curr_slide = slide;
        slide = slide->next;
        srv_mms_mem_mgr_app_adm_free(curr_slide);
    }
    while (to)
    {
        if (to->address)
        {
            srv_mms_mem_mgr_app_adm_free(to->address);
            to->address = NULL;
        }
        curr_to = to;
        to = to->next;
        srv_mms_mem_mgr_app_adm_free(curr_to);
    }
    while (cc)
    {
        if (cc->address)
        {
            srv_mms_mem_mgr_app_adm_free(cc->address);
            cc->address = NULL;
        }
        curr_cc = cc;
        cc = cc->next;
        srv_mms_mem_mgr_app_adm_free(curr_cc);
    }
    while (bcc)
    {
        if (bcc->address)
        {
            srv_mms_mem_mgr_app_adm_free(bcc->address);
            bcc->address = NULL;
        }
        curr_bcc = bcc;
        bcc = bcc->next;
        srv_mms_mem_mgr_app_adm_free(curr_bcc);
    }
    if (from)
    {
        if (from->address)
        {
            srv_mms_mem_mgr_app_adm_free(from->address);
            from->address = NULL;
        }
        srv_mms_mem_mgr_app_adm_free(from);
    }
    while (attachment)
    {
        if (attachment->object)
        {
            srv_mms_jsr_reset_object_struct_msg(attachment->object);
        }
        curr_attachment = attachment;
        attachment = attachment->next;
        srv_mms_mem_mgr_app_adm_free(curr_attachment);
    }

    /* free memory of object head */
    srv_mms_jsr_reset_object_struct_msg(object_head);
    /* free the context */
    if (g_jsr_mms_msg_detail->header)
    {
        if (g_jsr_mms_msg_detail->header->header)
        {
            if (g_jsr_mms_msg_detail->header->header->app_id)
            {
                srv_mms_mem_mgr_app_adm_free(g_jsr_mms_msg_detail->header->header->app_id);
            }
            if (g_jsr_mms_msg_detail->header->header->reply_app_id)
            {
                srv_mms_mem_mgr_app_adm_free(g_jsr_mms_msg_detail->header->header->reply_app_id);
            }
            srv_mms_mem_mgr_app_adm_free(g_jsr_mms_msg_detail->header->header);
            g_jsr_mms_msg_detail->header->header = NULL;
        }
        srv_mms_mem_mgr_app_adm_free(g_jsr_mms_msg_detail->header);
        g_jsr_mms_msg_detail->header = NULL;
    }
    if (g_jsr_mms_msg_detail->body)
    {
        srv_mms_mem_mgr_app_adm_free(g_jsr_mms_msg_detail->body);
        g_jsr_mms_msg_detail->body = NULL;
    }
    srv_mms_mem_mgr_app_adm_free(g_jsr_mms_msg_detail);
    g_jsr_mms_msg_detail = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_reset_get_content_struct_mem
 * DESCRIPTION
 *  This function free the MMA memory in the get content RSP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_reset_get_content_struct_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_free_content_info_struct *free_content_mem = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_content_mem =
        (wap_mma_free_content_info_struct*) OslConstructDataPtr(sizeof(wap_mma_free_content_info_struct));
    free_content_mem->req_id = JSR_CNTX->req_id;
    free_content_mem->app_id = MMA_APP_ID_JSR;
    free_content_mem->msg_id = JSR_CNTX->msgId;

    srv_mms_jsr_post_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_FREE_MMS_CONTENT),
        0,
        MSG_ID_WAP_MMA_FREE_MMS_CONTENT,
        (oslParaType*) free_content_mem,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_fill_text_data
 * DESCRIPTION
 *  This function fills the text data in a file.
 * PARAMETERS
 *  file_path       [?]     [?]     [?]     [?]     [?]
 *  subject         [?]     [?]     [?]     [?]     [?]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_jsr_fill_text_data(U16 *file_path, U16 *subject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 write_len = 0;
    U32 utf8_buffer_size = (mmi_ucs2strlen((S8*) subject) * 3 + ENCODING_LENGTH);
    U8 *utf8_buffer = NULL;
    U32 utf8_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_buffer = (U8*) srv_mms_mem_mgr_app_adm_alloc(utf8_buffer_size);
    if (utf8_buffer == NULL)
    {
        return MMC_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(utf8_buffer, 0, utf8_buffer_size);
    utf8_len = mmi_chset_ucs2_to_utf8_string(utf8_buffer, utf8_buffer_size, (U8*) subject);

    file_handle = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (file_handle < 0)
    {
        srv_mms_mem_mgr_app_adm_free(utf8_buffer);
        return (U8) file_handle;
    }
    else
    {
        FS_Write(
            file_handle,
            utf8_buffer,
            utf8_len - 1,   /* null terminator */
            &write_len);
        srv_mms_mem_mgr_app_adm_free(utf8_buffer);
        FS_Close(file_handle);
    }
    return MMC_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_receive_appmms_req_hldr
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_RECV_APPMMS_REQ primitive to Java
 * PARAMETERS
 *  msg         [?]         [?]     [?]     [?]     [?]     [?]
 *  mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_receive_appmms_req_hldr(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_recv_appmms_req_struct *Message = NULL;
    wap_mmc_recv_appmms_rsp_struct response;
    jsr_appid_msgid_list *appid_list = NULL;
    jsr_msg_info *msg_list;
    S8 *appId = NULL;
    U32 msgId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&response, 0, sizeof(wap_mmc_recv_appmms_rsp_struct));

    if (JSR_CNTX->state != JSR_STATE_IDLE)
    {
        response.result = MMC_RESULT_BUSY;
        srv_mms_jsr_receive_appmms_rsp(&response, NULL, 0, mod_id);
        return;
    }
    else if (mma_is_ready == MMI_FALSE)
    {
        response.result = MMC_RESULT_MMS_NO_READY;
        srv_mms_jsr_receive_appmms_rsp(&response, NULL, 0, mod_id);
        return;
    }
    JsrCleanContext();  /* clean context first */
    srv_mms_init_jsr_folder();

    Message = (wap_mmc_recv_appmms_req_struct*) msg;
    *(Message->app_id + Message->app_id_len) = '\0';

    appId = (S8*) Message->app_id;
    JSR_CNTX->op = JSR_OP_RECV_MSG;
    JSR_CNTX->state = JSR_STATE_RECV_MSG_HDR;
    JSR_CNTX->dest_mod_id = mod_id;

    if (appId == NULL)
    {
        response.result = MMC_RESULT_INVALID_PARAMETER;
        srv_mms_jsr_receive_appmms_rsp(&response, NULL, 0, mod_id);
        JsrCleanContext();
        return;
    }
    else if (g_jsr_appid_object_list == NULL)
    {
        srv_mms_jsr_read_object_list_from_file();
    }

    appid_list = g_jsr_appid_object_list;

    while (appid_list)
    {
        if ((appid_list->appId) && (strcmp((S8*) appid_list->appId, (S8*) appId) == 0))
        {
            ASSERT(appid_list->msgs);
            /* JSR_CNTX->msg_list = appid_list->msgs; */
            /* msgId = appid_list->msgs->msgId; */
            msg_list = appid_list->msgs;
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
        #endif /* 0 */ 
            while (msg_list)
            {
                msgId = msg_list->msgId;
                if ((mma_get_box(msgId)) != MMA_FOLDER_NONE)
                {
                    break;
                }
                msg_list = msg_list->next;
                srv_mms_jsr_remove_msgId_from_appId_list(msgId);
            }
            if (msg_list)
            {
                JSR_CNTX->msgId = msgId;
                JSR_CNTX->counter = 0;  /* reset the count */
                JSR_CNTX->req_id = mma_get_request_id();
                if (msg_list->next)
                {
                    JSR_CNTX->is_more_msg = MMI_TRUE;
                }
                srv_mms_jsr_get_msg_content_req();
            }
            else
            {
                response.result = MMC_RESULT_MESSAGE_ID_NOT_FOUND;
                srv_mms_jsr_receive_appmms_rsp(&response, NULL, 0, mod_id);
                JsrCleanContext();
            }
            /* JSR_CNTX->msg_list = JSR_CNTX->msg_list->next; */
            return;
        }
        appid_list = appid_list->next;
    }

    response.result = MMC_RESULT_NO_MSG_FOR_JAVA;
    srv_mms_jsr_receive_appmms_rsp(&response, NULL, 0, mod_id);
    JsrCleanContext();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_get_msg_content_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  buffer_size(?)      [IN](?)(?)(?)(?)
 *  resp            [?](?)(?)(?)(?)(?)
 *  buffer          [?](?)(?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_get_msg_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_get_content_req_struct *msgcnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgcnt = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(*msgcnt));

    msgcnt->app_id = MMA_APP_ID_JSR;
    msgcnt->req_id = JSR_CNTX->req_id;  /* mma_get_request_id(); */
    msgcnt->msg_id = JSR_CNTX->msgId;
    msgcnt->mode = MMA_MODE_RAW;
    msgcnt->creation_mode = MMA_CREATION_MODE_FREE;
    /* send request for message list */

    srv_mms_jsr_post_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_GET_CONTENT_REQ),
        0,
        MSG_ID_WAP_MMA_GET_CONTENT_REQ,
        (oslParaType*) msgcnt,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_get_msg_content_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgRsp      [?]     
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_jsr_get_msg_content_rsp(void *msgRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_recv_appmms_rsp_struct response;
    S8 *buffer = NULL;
    U32 buffer_size = 0;
    wap_mma_get_content_rsp_struct *msgCnt = (wap_mma_get_content_rsp_struct*) msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgCnt->app_id == MMA_APP_ID_JSR)
    {
        if (mma_is_ready == MMI_FALSE)
        {
            /* MMA is terminated. Abort request is already sent to Java */
            return MMI_TRUE;
        }
        memset(&response, 0, sizeof(wap_mmc_recv_appmms_rsp_struct));

        if (JSR_CNTX->op != JSR_OP_RECV_MSG)
        {
            return MMI_TRUE;
        }
        g_jsr_mms_msg_detail = msgCnt->content_info;
        if (msgCnt->result != MMC_RESULT_OK)
        {
            srv_mms_jsr_remove_msgId_from_appId_list(JSR_CNTX->msgId);
            response.result = MMC_RESULT_ERROR_MSG_CORRUPTED;
            srv_mms_jsr_receive_appmms_rsp(&response, NULL, 0, JSR_CNTX->dest_mod_id);
            JsrCleanContext();
            return MMI_TRUE;
        }
        else
        {
            /* fill header info and send srv_mms_jsr_receive_appmms_rsp; */
            srv_mms_jsr_fill_header(&response, (S8 **) & buffer, &buffer_size);
            /* srv_mms_jsr_receive_appmms_rsp(&response, buffer, buffer_size); */
            srv_mms_jsr_receive_appmms_post_req_hldr(&response, buffer, buffer_size, JSR_CNTX->dest_mod_id);
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_receive_appmms_post_req_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resp            [?]         [?]         [?]         [?]         [?]         [?]
 *  buffer          [?]         [?]         [?]         [?]         [?]         [?]
 *  buffer_size     [IN]        
 *  mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_receive_appmms_post_req_hldr(void *resp, S8 *buffer, U32 buffer_size, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mmc_recv_appmms_rsp_struct *response = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    response = (wap_mmc_recv_appmms_rsp_struct*) resp;
    if (response->result == MMC_RESULT_INSUFFICIENT_MEMORY)
    {
        /* only pass the header information */
        response->bdy_part_no = 0;
    }
    response->result = MMC_RESULT_OK;
    srv_mms_jsr_receive_appmms_rsp(response, buffer, buffer_size, mod_id);

    if (response->bdy_part_no != 0)
    {
        JSR_CNTX->total_media_obj_no = response->bdy_part_no;
        JSR_CNTX->curr_media_obj_no = 1;
        JSR_CNTX->state = JSR_STATE_RECV_MSG_BDY;
    }
    else
    {
        srv_mms_jsr_remove_msgId_from_appId_list(JSR_CNTX->msgId);
        srv_mms_jsr_delete_msg_req(0, JSR_CNTX->msgId);
    }
    if (buffer != NULL)
    {
        srv_mms_mem_mgr_app_adm_free((void*)buffer);
        buffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_receive_appmms_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_RECV_APPMMS_RSP primitive to Java
 * PARAMETERS
 *  response_struct     [?]         [?]         [?]         [?]         [?]         [?]
 *  buffer              [?]         [?]         [?]         [?]         [?]         [?]
 *  buffer_size         [IN]        
 *  mod_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_receive_appmms_rsp(
        wap_mmc_recv_appmms_rsp_struct *response_struct,
        S8 *buffer,
        U32 buffer_size,
        int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_recv_appmms_rsp_struct *myMsgPtr = NULL;
    ilm_struct *ilm_ptr = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 peer_pdu_len = 0;
    U8 *peer_pdu = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_recv_appmms_rsp_struct*) OslConstructDataPtr(sizeof(wap_mmc_recv_appmms_rsp_struct));

    memset((S8*) (myMsgPtr) + 4, 0, (sizeof(wap_mmc_recv_appmms_rsp_struct) - 4));

    myMsgPtr->result = response_struct->result;
    myMsgPtr->priority = response_struct->priority;
    myMsgPtr->date = response_struct->date;
    myMsgPtr->from_addr_no = response_struct->from_addr_no;
    myMsgPtr->to_addr_no = response_struct->to_addr_no;
    myMsgPtr->cc_addr_no = response_struct->cc_addr_no;
    myMsgPtr->bdy_part_no = response_struct->bdy_part_no;
    myMsgPtr->is_more_msg = JSR_CNTX->is_more_msg;
    myMsgPtr->start_cnt_id_len = response_struct->start_cnt_id_len;
    memset(myMsgPtr->start_cnt_id, 0, 100);
    memcpy(myMsgPtr->start_cnt_id, response_struct->start_cnt_id, 100);
    myMsgPtr->reply_app_id_len = response_struct->reply_app_id_len;
    memset(myMsgPtr->reply_app_id, 0, 100);
    memcpy(myMsgPtr->reply_app_id, response_struct->reply_app_id, 100);

    if (buffer)
    {
        peer_buff_ptr = (peer_buff_struct*) construct_peer_buff((U16) buffer_size, 0, 0, TD_CTRL);
        peer_pdu = (U8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
        if (peer_pdu)
        {
            memcpy(peer_pdu, buffer, buffer_size);
        }
    }

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = (module_type)mod_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_RECV_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_read_appmms_msg_part_req
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ primitive to Java
 * PARAMETERS
 *  msg         [?]         [?]     [?]     [?]
 *  mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_read_appmms_msg_part_req(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_appmms_msg_part_rsp_struct response;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
    if (JSR_CNTX->state != JSR_STATE_RECV_MSG_BDY)
    {
        memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
        response.result = MMC_RESULT_ACCESS_DENY;
        srv_mms_jsr_read_appmms_msg_part_rsp(&response, mod_id);
    }
    else
    {
        if (srv_mms_jsr_generate_recv_msg_body_part(
                JSR_CNTX->msgId,
                &(JSR_CNTX->curr_media_obj_no),
                (JSR_CNTX->total_media_obj_no),
                &response))
        {
            srv_mms_jsr_read_appmms_msg_part_rsp(&response, mod_id);
            /* JSR_CNTX->curr_media_obj_no = JSR_CNTX->curr_media_obj_no + 1; */
            if (JSR_CNTX->curr_media_obj_no > JSR_CNTX->total_media_obj_no)
            {
                srv_mms_jsr_remove_msgId_from_appId_list(JSR_CNTX->msgId);
                srv_mms_jsr_delete_msg_req(0, JSR_CNTX->msgId);
            }
        }
        else
        {
            memset(&response, 0, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
            response.result = MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
            srv_mms_jsr_read_appmms_msg_part_rsp(&response, mod_id);
            srv_mms_jsr_reset_get_content_struct_mem();
            JsrCleanContext();
            /* srv_mms_jsr_reset_xml_struct_msg(); */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_read_appmms_msg_part_rsp
 * DESCRIPTION
 *  Create a MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP primitive to Java
 * PARAMETERS
 *  response        [?]         [?]     [?]     [?]     [?]     [?]
 *  mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_read_appmms_msg_part_rsp(wap_mmc_read_appmms_msg_part_rsp_struct *response, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_appmms_msg_part_rsp_struct *myMsgPtr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_mmc_read_appmms_msg_part_rsp_struct*)
        OslConstructDataPtr(sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));

    memset((S8*) (myMsgPtr) + 4, 0, (sizeof(wap_mmc_read_appmms_msg_part_rsp_struct) - 4));

    myMsgPtr->result = response->result;
    myMsgPtr->encoding_scheme = response->encoding_scheme;
    /* Content-Type */
    myMsgPtr->content_type_value = response->content_type_value;
    myMsgPtr->content_type_len = response->content_type_len;
    memcpy(myMsgPtr->content_type, response->content_type, 100);
    /* Content-Id */
    myMsgPtr->content_id_len = response->content_id_len;
    memcpy(myMsgPtr->content_id, response->content_id, 100);
    /* Content-Location */
    myMsgPtr->content_location_len = response->content_location_len;
    memcpy(myMsgPtr->content_location, response->content_location, 100);
    /* Media object filepath */
    myMsgPtr->filepath_len = response->filepath_len;
    memcpy(myMsgPtr->filepath, response->filepath, 100);

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = J2ME_WAP_SAP;
    ilm_ptr->dest_mod_id = (module_type)mod_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_fill_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resp            [?]         [?]         [?]         [?]         [?]
 *  buffer          [IN]        
 *  buf_size        [?]         [?]         [?]         [?]         [?]
 *  eRet(?)         [IN](?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_jsr_fill_header(wap_mmc_recv_appmms_rsp_struct *resp, S8 **buffer, U32 *buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* S8 *content_type = NULL; */
    U32 subject_len = 0;
    mma_mms_addr_list_struct *to_list;
    mma_mms_addr_list_struct *cc_list;

    /* srv_mms_addr_struct *bcc_list; */
    U32 address_len = 0;
    S8 *buf = NULL;
    U16 datalen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (resp == NULL)
    {
        return;
    }
    if (g_jsr_mms_msg_detail == NULL)
    {
        ASSERT(0);
        return;
    }
    resp->result = MMC_RESULT_ERROR;    /* fill default as Error */

    /* set priority */
    resp->priority = g_jsr_mms_msg_detail->header->header->priority;    /* eMM1MessagePriority; */

    /* Date */
    resp->date = g_jsr_mms_msg_detail->header->header->date;

    /* set total number of objects */
    resp->bdy_part_no = (U8) g_jsr_mms_msg_detail->body->obj_no;
    if (g_jsr_mms_msg_detail->header->header->reply_app_id)
    {
        strcpy((S8*) resp->reply_app_id, (S8*) g_jsr_mms_msg_detail->header->header->reply_app_id);
        resp->reply_app_id_len = strlen((S8*) resp->reply_app_id);
    }

    /* subject */
    *buf_size += 4; /* subject_data_len 4bytes; */
    subject_len = strlen((const char *) (g_jsr_mms_msg_detail->header->header->subject.text));
    if (subject_len /* g_jsr_mms_xml_msg.subject */ )
    {
        *buf_size += 4; /* subject_encode_type 4bytes */

        *buf_size += subject_len;
    }

    /* from address  ///from address can be one only */
    resp->from_addr_no = 0;
    if (g_jsr_mms_msg_detail->header->header->from->address != NULL)
    {

        resp->from_addr_no = 1;
        address_len = strlen((S8*) (g_jsr_mms_msg_detail->header->header->from->address));
        *buf_size += (8 + address_len);
    }

    /* to address */
    resp->to_addr_no = 0;
    if (g_jsr_mms_msg_detail->header->header->to != NULL)
    {
        to_list = g_jsr_mms_msg_detail->header->header->to;

        while (to_list)
        {
            if (to_list->address)
            {
                resp->to_addr_no += 1;
                address_len = strlen((S8*) (to_list->address));
                *buf_size += (8 + address_len);
            }
            to_list = to_list->next;
        }
    }

    /* cc address */
    resp->cc_addr_no = 0;
    if (g_jsr_mms_msg_detail->header->header->cc != NULL)
    {
        cc_list = g_jsr_mms_msg_detail->header->header->cc;

        while (cc_list)
        {
            if (cc_list->address)
            {
                resp->cc_addr_no += 1;
                address_len = strlen((S8*) (cc_list->address));
                *buf_size += (8 + address_len);
            }
            cc_list = cc_list->next;
        }
    }

    buf = (S8*) srv_mms_mem_mgr_app_adm_alloc(*buf_size + 1);
    if (buf == NULL)
    {

        resp->result = MMC_RESULT_INSUFFICIENT_MEMORY;
        goto END;

    }

    /* Pack subject */
    if (subject_len /* g_jsr_mms_xml_msg.subject */ )
    {
        *(U32*) buf = subject_len;
        *(U32*) (buf + 4) = SRV_MMS_JSR_SUBJECT_ENCODED_VALUE; /* /MMC_UTF8. Note::: Encoded value used is as given in mms_def.h file */
        memcpy(buf + 8, g_jsr_mms_msg_detail->header->header->subject.text, subject_len);
        datalen += (8 + subject_len);
    }
    else
    {
        *(U32*) buf = 0;    /* subject_data_len=0 */
        datalen += 4;
    }
    /* Pack from address field */
    if (resp->from_addr_no == 1)
    {

        U32 address_len;
        U32 address_type;

        address_len = strlen((S8*) (g_jsr_mms_msg_detail->header->header->from->address));
        address_type = g_jsr_mms_msg_detail->header->header->from->addr_type;
        memcpy((char*)(buf + datalen), &address_type, 4);
        memcpy((char*)(buf + datalen + 4), &address_len, 4);
        memcpy((char*)(buf + datalen + 8), g_jsr_mms_msg_detail->header->header->from->address, address_len);
        datalen += (8 + address_len);
    }

    /* /Pack to address field */
    if (g_jsr_mms_msg_detail->header->header->to)
    {
        to_list = g_jsr_mms_msg_detail->header->header->to;

        while (to_list)
        {
            if (to_list->address)
            {
                U32 address_len;
                U32 address_type;

                address_len = strlen((S8*) (to_list->address));
                address_type = to_list->addr_type;
                memcpy((char*)(buf + datalen), &address_type, 4);
                memcpy((char*)(buf + datalen + 4), &address_len, 4);
                memcpy((char*)(buf + datalen + 8), to_list->address, address_len);
                datalen += (8 + address_len);
            }
            to_list = to_list->next;
        }
    }
    /* Pack cc address field */
    if (g_jsr_mms_msg_detail->header->header->cc)
    {
        cc_list = g_jsr_mms_msg_detail->header->header->cc;

        while (cc_list)
        {
            if (cc_list->address)
            {
                U32 address_len;
                U32 address_type;

                address_len = strlen((S8*) (cc_list->address));
                address_type = cc_list->addr_type;
                memcpy((char*)(buf + datalen), &address_type, 4);
                memcpy((char*)(buf + datalen + 4), &address_len, 4);
                memcpy((char*)(buf + datalen + 8), cc_list->address, address_len);
                datalen += (8 + address_len);
            }
            cc_list = cc_list->next;
        }
    }
    /* amit to check bcc feild */
    *buffer = buf;
    resp->result = MMC_RESULT_OK;
  END:
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_jsr_generate_recv_msg_body_part
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgId               [IN]        
 *  bdy_part_no         [?]         [?]         [?]         [?]         [?]         [?]         [?]
 *  total_objects       [IN]        
 *  response            [?]         [?]         [?]         [?]         [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_jsr_generate_recv_msg_body_part(
            U32 msgId,
            U8 *bdy_part_no,
            U8 total_objects,
            wap_mmc_read_appmms_msg_part_rsp_struct *response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int read_handle = -1;
    int write_handle = -1;
    U32 bytes_written = 0;
    U8 part_no = 0;
    mma_mms_object_struct *object = NULL;

    /* applib_mime_type_struct *mime_info = NULL; */
    kal_wchar wrtfile[JSR_FILENAME_LEN_MMA];
    U8 media_buffer_p[FILE_BUF_SIZE];
    U32 curr_pos = 0, datalen = 0, read_size = 0;
    U16 obj_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    part_no = (*bdy_part_no /* amit to check- 1 */ );
    object = g_jsr_mms_msg_detail->body->objects;
    /* Ashok ToDo: Check if the 0th location concept get changed */
    for (obj_count = 1; obj_count <= g_jsr_mms_msg_detail->body->obj_no; obj_count++)
    {
        if (object && object->id == part_no)
        {
            break;
        }
        object = object->next;
    }
    /* if (NULL == object[obj_count]->id) */
    {
        /* return FALSE; */
    }
    if (object == NULL)
    {
        return MMI_FALSE;
    }
    *bdy_part_no += 1;
    response->result = MMC_RESULT_OK;

    /* For encoding scheme: */
    response->encoding_scheme = object->encoding_scheme;

    /* content type */
    if (object->mime_str)
    {
        response->content_type_len = strlen((S8*) object->mime_str);
        if (response->content_type_len > 255)
        {
            response->content_type_len = 255;
        }
        strncpy((S8*) response->content_type, (S8*) object->mime_str, response->content_type_len);
    }

    /* For encoding scheme: */
    /* response->encoding_scheme = MMC_UTF8; */
    /* for content id: */
    /* response->content_id_len = ; */
    if (object->content_id)
    {
        response->content_id_len = strlen((S8*) object->content_id);
        if (response->content_id_len >= 100)
        {
            response->content_id_len = 99;
        }
        strncpy((S8*) response->content_id, (S8*) object->content_id, response->content_id_len);
    }

    if (object->content_location)
    {
        response->content_location_len = strlen((S8*) object->content_location);
        if (response->content_location_len >= 100)
        {
            response->content_location_len = 99;
        }
        strncpy((S8*) response->content_location, (S8*) object->content_location, response->content_location_len);
    }

    /* create media file start */
    {
        memset(wrtfile, 0, JSR_FILENAME_LEN_MMA);
        MAKE_JSR_MEDIA_OBJECT_FILE(wrtfile);

        FS_Delete((U16*) wrtfile);

        write_handle = FS_Open((U16*) (wrtfile), FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (write_handle < 0)
        {
            response->result = MMC_RESULT_FILE_OPERATION_ERROR;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_JSR_GEN_PART_WRITE_HANDLE, __LINE__);
            return MMI_FALSE;
        }

        read_handle = FS_Open((U16*) (object->file_path_ucs), FS_READ_WRITE);
        if (read_handle < 0)
        {
            response->result = MMC_RESULT_FILE_OPERATION_ERROR;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_JSR_GEN_PART_READ_HANDLE, __LINE__);
            return MMI_FALSE;
        }

        curr_pos = object->offset;
        FS_Seek(read_handle, curr_pos, FS_FILE_BEGIN);

        while (curr_pos < (object->offset + object->size))
        {
            datalen = (object->offset + object->size - curr_pos);
            if (datalen > FILE_BUF_SIZE)
            {
                datalen = FILE_BUF_SIZE;
            }
            /* read data from jsr mms message */
            if (FS_Read(read_handle, &media_buffer_p, datalen, &read_size) != FS_NO_ERROR || (read_size != datalen))
            {
                FS_Close(write_handle);
                FS_Close(read_handle);

                response->result = MMC_RESULT_FILE_OPERATION_ERROR;
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_JSR_GEN_PART_FS_READ, __LINE__);
                return MMI_FALSE;
            }
            /* write data to jsr media object */
            if (FS_Write(write_handle, &media_buffer_p, datalen, &bytes_written) < 0)
            {
                response->result = MMC_RESULT_FILE_OPERATION_ERROR;
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_JSR_GEN_PART_FS_WRITE, __LINE__);
                return MMI_FALSE;
            }

            curr_pos += datalen;
        }

        FS_Close(write_handle);
        FS_Close(read_handle);

        response->filepath_len = mmi_ucs2strlen((S8*) wrtfile);
        memset(response->filepath, 0, ((response->filepath_len + 1) * 2));
        mmi_ucs2cpy((S8*) response->filepath, (S8*) wrtfile);
    }
    /* create media file end */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  convert_jsr_priority_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  priority        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 convert_jsr_priority_to_mma(U8 priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return priority + 1;
}
#endif /* __MMI_UMMS_JSR205__ */ 
#endif /* defined(MMS_SUPPORT) */ 

#endif /* __MMI_MMS_2__ */ 

