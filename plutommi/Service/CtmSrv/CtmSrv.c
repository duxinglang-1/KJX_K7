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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   CtmSrv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Cellular Text telephone Modem Service
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifdef __CTM_SUPPORT__

#include "mdi_audio.h" /* mmi_evt_mdi_audio_speech_ind_struct, MDI_AUDIO_SPH_POST_SPEECH_ON */

#include "Aud_defs.h" /* aud_ctm_interface_enum */

#include "CallSetSrvGprot.h" /* srv_callset_ctm_get_mode */
#include "GpioSrvGprot.h" /* EVT_ID_GPIO_EARPHONE_PLUG */
#include "UcmSrvGprot.h"

#include "CtmSrvGprot.h"
#include "CtmSrvProt.h"

#include "string.h"
#include "kal_non_specific_general_types.h"
#include "MMIDataType.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_cb_mgr_gprot.h"
#include "Unicodexdcl.h"
#include "med_struct.h"
#include "mmi_msg_struct.h"
#include "kal_release.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "mmi_frm_input_gprot.h"

#include "BthScoPathSrvGProt.h"/*avoid ctm and bt same open*/

static srv_ctm_cntxt_struct g_srv_ctm_cntxt;
srv_ctm_cntxt_struct *srv_ctm_p = &g_srv_ctm_cntxt;


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_init
 * DESCRIPTION
 *  To Initialize the CTM Call service
 *  
 *  This function sets up the handlers required for event flow and
 *  application management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_ctm_p, 0, sizeof(srv_ctm_cntxt_struct));

    SetProtocolEventHandler(srv_ctm_phdlr_connect_ind, MSG_ID_MEDIA_CTM_CONNECTED_IND);
    SetProtocolEventHandler(srv_ctm_phdlr_receive_text_ind, MSG_ID_MEDIA_CTM_RECV_TEXT_IND);

    /* always send false first for ctm status */
    srv_ctm_p->ctm_call_mode = MMI_FALSE;
    srv_ctm_l4c_set_ctm_status_req(MMI_FALSE);

}



/*****************************************************************************
 * FUNCTION
 *  srv_ctm_prmt_connect
 * DESCRIPTION
 *  Check if ctm can connect
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means ctm is able to connect now.
 *  FALSE means user can't connect ctm now.
 *****************************************************************************/
MMI_BOOL srv_ctm_prmt_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ctm_is_opened_as_manual_mode() == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PRMT_CONNECT_ALLOW); 
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PRMT_CONNECT_DISALLOW); 
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_is_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_ctm_is_opened_as_manual_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ctm_p->state == SRV_CTM_STATE_OPENED && srv_ctm_p->mode_activated == AUD_CTM_DIRECT_MODE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_IS_OPENED_AS_MANUAL_MODE_YES);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_IS_OPENED_AS_MANUAL_MODE_NO);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_rsp_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_phdlr_close_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_SRV_PHDLR_CTM_CLOSE_RSP);

    ClearProtocolEventHandler(MSG_ID_MEDIA_CTM_CLOSE_CNF);

    /* open_req may be sent before the previous close_rsp is received, thus only
        clear the state when the current state is still closing */
    if (srv_ctm_p->state == SRV_CTM_STATE_CLOSING)
    {
        srv_ctm_p->state = SRV_CTM_STATE_IDLE;

        /* clear all the operation when close is completed */
        srv_ctm_p->rsp_cb = NULL;
        srv_ctm_p->curr_act = SRV_CTM_ACT_IDLE;
        srv_ctm_p->mode_opening = 0;
    }

    srv_ctm_p->mode_activated = 0;

    srv_ctm_send_ind(SRV_CTM_IND_CLOSE, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_send_indication
 * DESCRIPTION
 *  The function to send indication
 * PARAMETERS
 *  ind_op:          [IN]        Indication op-code
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_send_ind(srv_ctm_ind_enum op, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ctm_ind_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_SEND_IND, op);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CTM_INDICATION);
    evt.ind = op;
    evt.ptr = ptr;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_act_req
 * DESCRIPTION
 *  CTM action request
 * PARAMETERS
 *  opcode : [IN]  request opcode
 *  info : [IN]  parameter for request
 *  callback : [IN] callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_act_req(srv_ctm_act_op_enum opcode, void* info, srv_ctm_rsp_cb_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ctm_rsp_struct rsp;
    MMI_BOOL result = MMI_FALSE;
    srv_ctm_act_op_enum ori_act;
    srv_ctm_rsp_cb_func_ptr ori_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_ACT_REQ, opcode, srv_ctm_p->curr_act);

    ori_act = srv_ctm_p->curr_act;
    ori_cb = srv_ctm_p->rsp_cb;

    srv_ctm_p->curr_act = opcode;
    srv_ctm_p->rsp_cb = callback;

    if (ori_act == SRV_CTM_ACT_IDLE)
    {
        switch (opcode)
        {
            case SRV_CTM_ACT_CONNECT:
                srv_ctm_act_connect();
                result = MMI_TRUE;
                break;

            case SRV_CTM_ACT_SEND_TEXT:
                result = srv_ctm_act_send_text(info);
                break;

            default:
                break;
        }
    }

    /* CTM service is busy, op fails, or unsupport op */
    if (result != MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_ACT_REQ_ERR);

        if (callback)
        {
            /* restore before callback */
            srv_ctm_p->curr_act = ori_act;
            srv_ctm_p->rsp_cb = ori_cb;

            rsp.result = MMI_FALSE;
            (*callback)(&rsp);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_act_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_act_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ctm_p->state = SRV_CTM_STATE_CONNECTING;

    srv_ctm_med_connect_req();

}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_act_send_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_ctm_act_send_text(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ctm_send_text_req_struct *msg = (srv_ctm_send_text_req_struct*)info;
    srv_ctm_rsp_struct rsp;
    U8 length;
    srv_ctm_rsp_cb_func_ptr cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    length = (U8)mmi_ucs2strlen((CHAR*)msg->text);

    if (!info || !msg->text || !length
        || (length > CTM_SEND_TEXT_CHAR_MAX_NUM))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_ACT_SEND_TEXT_ERR);

        cb = srv_ctm_p->rsp_cb;
        srv_ctm_p->rsp_cb = NULL;
        srv_ctm_p->curr_act = SRV_CTM_ACT_IDLE;

        /* send rsp to ctm app */
        if(cb)
        {
            rsp.result = MMI_FALSE;
            (*cb)(&rsp);
        }
        return MMI_FALSE;
    }

    srv_ctm_p->state = SRV_CTM_STATE_SENDING;

    srv_ctm_med_send_text_req((CHAR*)msg->text);

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_connect_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_phdlr_connect_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_ctm_rsp_struct rsp;
    srv_ctm_rsp_cb_func_ptr cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(MSG_ID_MEDIA_CTM_CONNECT_CNF);

#ifndef __CTM_DEBUG
    result = (((media_ctm_connect_cnf_struct*)info)->result == MED_RES_OK) ? MMI_TRUE : MMI_FALSE;
#endif /* __CTM_DEBUG */ 

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PHDLR_CONNECT_RSP, result, srv_ctm_p->state);
    
    if (srv_ctm_p->state == SRV_CTM_STATE_CONNECTING)
    {
         srv_ctm_p->state = result ? SRV_CTM_STATE_CONNECTED : SRV_CTM_STATE_OPENED;
    }

    cb = srv_ctm_p->rsp_cb;
    srv_ctm_p->rsp_cb = NULL;
    srv_ctm_p->curr_act = SRV_CTM_ACT_IDLE;

    /* send rsp to ctm app */
    if(cb)
    {
        rsp.result = result;
        (*cb)(&rsp);
    }

    
#ifdef __CTM_DEBUG
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) srv_ctm_phdlr_receive_text_ind);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_phdlr_send_text_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_phdlr_send_text_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_ctm_rsp_struct rsp;
    srv_ctm_rsp_cb_func_ptr cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(MSG_ID_MEDIA_CTM_SEND_TEXT_CNF);

#ifndef __CTM_DEBUG
    result = (((media_ctm_send_text_cnf_struct*)info)->result == MED_RES_OK) ? MMI_TRUE : MMI_FALSE;
#endif /* __CTM_DEBUG */ 

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PHDLR_SEND_TEXT_RSP, result, srv_ctm_p->state);

    if (srv_ctm_p->state == SRV_CTM_STATE_SENDING)
    {
        srv_ctm_p->state = SRV_CTM_STATE_CONNECTED;
    }

    cb = srv_ctm_p->rsp_cb;
    srv_ctm_p->rsp_cb = NULL;
    srv_ctm_p->curr_act = SRV_CTM_ACT_IDLE;

    /* send rsp to ctm app */
    if(cb)
    {
        rsp.result = result;
        (*cb)(&rsp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_phdlr_connect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_phdlr_connect_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

  
    if (srv_ctm_p->state == SRV_CTM_STATE_OPENED || srv_ctm_p->state == SRV_CTM_STATE_CONNECTING)
    {
        srv_ctm_p->state = SRV_CTM_STATE_CONNECTED;

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PHDLR_CONNECT_IND);
        
        srv_ctm_send_ind(SRV_CTM_IND_CONNECT, NULL);
        
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PHDLR_CONNECT_IND_IGNORE, srv_ctm_p->state);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_phdlr_open_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_phdlr_open_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(MSG_ID_MEDIA_CTM_OPEN_CNF);

    if ((srv_ctm_p->state != SRV_CTM_STATE_OPENING)
        && (srv_ctm_p->state != SRV_CTM_STATE_IDLE))
    {
        /* ignore if ctm is not opening */
        /* the state may be idle if close rsp arrives before open rsp (switch tty status) */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PHDLR_OPEN_RSP_IGNORE, srv_ctm_p->state);
        return;
    }


    if (((media_ctm_open_cnf_struct*)info)->result == MED_RES_OK)
    {
        /* open OK */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PHDLR_OPEN_RSP_SUC);

        srv_ctm_p->state = SRV_CTM_STATE_OPENED;
        srv_ctm_p->mode_activated = srv_ctm_p->mode_opening;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_PHDLR_OPEN_RSP_FAIL);

        srv_ctm_p->state = SRV_CTM_STATE_IDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_speech_status_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_ctm_speech_status_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct *msg = (mmi_evt_mdi_audio_speech_ind_struct*)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if ((msg->status != MDI_AUDIO_SPH_POST_SPEECH_ON)
        && (msg->status != MDI_AUDIO_SPH_PRE_SPEECH_OFF))
    {
        return MMI_RET_OK; 
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_SPEECH_STATUS_IND_HDLR, msg->status);

    if (msg->status == MDI_AUDIO_SPH_POST_SPEECH_ON)
    {
        srv_ctm_speech_on_hdlr();
    }
    else
    {
        srv_ctm_speech_off_hdlr();
    }

    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_speech_on_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_speech_on_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) != 1)
    {
        return; 
    }

    if ((srv_ctm_p->state == SRV_CTM_STATE_IDLE)
        || (srv_ctm_p->state == SRV_CTM_STATE_CLOSING))
    {
        srv_ctm_open(MMI_TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_speech_off_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_speech_off_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if ((srv_ctm_p->state != SRV_CTM_STATE_IDLE)
        && (srv_ctm_p->state != SRV_CTM_STATE_CLOSING))
    {
        srv_ctm_open(MMI_FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_open(MMI_BOOL ctm_open)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctm_open == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_OPEN_YES);
        
        /* open ctm after turn on speech */
        if ((srv_callset_ctm_get_mode() == MMI_TRUE)
            && ((srv_ctm_p->state == SRV_CTM_STATE_IDLE)
                || (srv_ctm_p->state == SRV_CTM_STATE_CLOSING)))
        {
            mode = srv_ctm_derive_mode();

            if (mode != 0xff)
            {
                srv_ctm_p->state = SRV_CTM_STATE_OPENING;
                srv_ctm_p->mode_opening = mode;
                srv_ctm_med_open_req(mode);
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_OPEN_NO);
       
        /* close ctm before turn off speech */
        if (srv_ctm_p->state == SRV_CTM_STATE_OPENING ||
            srv_ctm_p->state == SRV_CTM_STATE_OPENED ||
            srv_ctm_p->state == SRV_CTM_STATE_CONNECTING ||
            srv_ctm_p->state == SRV_CTM_STATE_CONNECTED ||
            srv_ctm_p->state == SRV_CTM_STATE_SENDING)
        {
            srv_ctm_p->state = SRV_CTM_STATE_CLOSING;
            srv_ctm_med_close_req();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ctm_derive_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_ctm_derive_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode = 0xff;
    U8 setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting = srv_callset_ctm_get_setting();

    MMI_ASSERT(setting < SRV_CALLSET_CTM_SETTING_UNKNOWN);

    if (srv_ctm_p->tty_status == MMI_TRUE)
    {
        /* with TTY, open as TTY */
        switch (setting)
        {
            case SRV_CALLSET_CTM_SETTING_HCO:
                mode = AUD_CTM_HCO_MODE;
                break;
            case SRV_CALLSET_CTM_SETTING_VCO:
                mode = AUD_CTM_VCO_MODE;
                break;
            case SRV_CALLSET_CTM_SETTING_BAUDOT:
                mode = AUD_CTM_BAUDOT_MODE;
                break;
            default:
                /* CTM ON, earphone in, direct mode => keep open as direct mode, take it as earphone */
                mode = AUD_CTM_DIRECT_MODE;
                break;
        }
    }
    else
    {
        switch (setting)
        {
            case SRV_CALLSET_CTM_SETTING_AUTO_DIRECT:
            case SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT:
                /* no TTY, open as direct */
                mode = AUD_CTM_DIRECT_MODE;
                break;

            default:
                /* no TTY */
                break;
        }
    }

    return mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_get_tty_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_ctm_get_tty_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_ctm_p->tty_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_phdlr_receive_text_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_phdlr_receive_text_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len;
    PU16 text;
    srv_ctm_receive_text_ind_struct data;

#ifdef __CTM_DEBUG
    U16 temp[] = L"abc12345def\n";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = 12;
    text = temp;
#else /* __CTM_DEBUG */ 
    media_ctm_recv_text_ind_struct *ind;

    ind = (media_ctm_recv_text_ind_struct*)info;
    len = ind->num_of_char;
    text = ind->text;
#endif /* __CTM_DEBUG */ 

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_SRV_CTM_PHDLR_RECEIVE_TEXT_IND);

    len = srv_ctm_skip_unicode_char(text, len, 0x0008);


    memset(&data, 0, sizeof(srv_ctm_receive_text_ind_struct));
    data.text = text;
    data.text_len = len;
    srv_ctm_send_ind(SRV_CTM_IND_RECEIVE_TEXT, &data);


#ifdef __CTM_DEBUG
    StartTimer(CM_AUTOANSWER_NOTIFYDURATION_TIMER, 2000, (FuncPtr) mmi_ctm_recv_text_ind_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_skip_unicode_char
 * DESCRIPTION
 *  Deal with the backspace character (0x08)
 * PARAMETERS
 *  str         [IN]        
 *  len         [IN]        
 *  ch          [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_ctm_skip_unicode_char(PU16 str, U16 len, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = len;
    for (i = 0; i < length; i++)
    {
        if (str[i] == ch)
        {
            mmi_ucs2cpy((CHAR*) & str[i], (CHAR*) & str[i + 1]);
            str[length] = 0;
            length--;
        }
    }
    return length;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_l4c_set_ctm_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_l4c_set_ctm_status_req(MMI_BOOL is_ctm_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ctm_set_status_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    param = OslAllocDataPtr(mmi_ctm_set_status_req_struct);
    param->mode = (U8)is_ctm_on;

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_CTM_SET_STATUS_REQ, (oslParaType*)param, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_med_close_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_med_close_req(void)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_SRV_CTM_MED_CLOSE_REQ);
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_CTM); 
#endif
    

    SetProtocolEventHandler(srv_ctm_phdlr_close_rsp, MSG_ID_MEDIA_CTM_CLOSE_CNF);
    mmi_frm_send_ilm(MOD_MED, MSG_ID_MEDIA_CTM_CLOSE_REQ, NULL, NULL);

#else /* __CTM_DEBUG */ 
    StartTimer(CM_CTM_ALERT_NOTIFYDURATION_TIMER, 2000, (FuncPtr) srv_ctm_phdlr_close_rsp);
#endif /* __CTM_DEBUG */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_med_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_med_connect_req(void)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_SRV_CTM_MED_CONNECT_REQ);
    
    ClearInputEventHandler(MMI_DEVICE_ALL);

    SetProtocolEventHandler(srv_ctm_phdlr_connect_rsp, MSG_ID_MEDIA_CTM_CONNECT_CNF);
    mmi_frm_send_ilm(MOD_MED, MSG_ID_MEDIA_CTM_CONNECT_REQ, NULL, NULL);

#else /* __CTM_DEBUG */ 
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) srv_ctm_phdlr_connect_rsp);
#endif /* __CTM_DEBUG */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_med_open_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_med_open_req(U8 mode)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_open_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_SRV_CTM_MED_OPEN_REQ);

#ifdef __MMI_BT_AUDIO_VIA_SCO__ 
    /* Disconnect SCO if connect to A2DP */
    srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_CTM);   
#endif
    
    param = OslAllocDataPtr(media_ctm_open_req_struct);
    param->ctm_interface = mode;

    /* volume, don't need to be set by user for now */
    param->ctm_param.input_vol = 0x80;
    param->ctm_param.output_vol = 0x80;

    SetProtocolEventHandler(srv_ctm_phdlr_open_rsp, MSG_ID_MEDIA_CTM_OPEN_CNF);
    mmi_frm_send_ilm(MOD_MED, MSG_ID_MEDIA_CTM_OPEN_REQ, (oslParaType*)param, NULL);

#else /* __CTM_DEBUG */ 
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) srv_ctm_phdlr_open_rsp);
#endif /* __CTM_DEBUG */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_med_send_text_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_med_send_text_req(CHAR* text)
{
#ifndef __CTM_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_send_text_req_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, FUNC_SRV_CTM_MED_SEND_TEXT_REQ);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    param = OslAllocDataPtr(media_ctm_send_text_req_struct);
    param->num_of_char = mmi_ucs2strlen(text);
    mmi_ucs2ncpy((CHAR*)param->text, text, CTM_SEND_TEXT_CHAR_MAX_NUM);

    SetProtocolEventHandler(srv_ctm_phdlr_send_text_rsp, MSG_ID_MEDIA_CTM_SEND_TEXT_CNF);
    mmi_frm_send_ilm(MOD_MED, MSG_ID_MEDIA_CTM_SEND_TEXT_REQ, (oslParaType*)param, NULL);

#else /* __CTM_DEBUG */ 
    StartTimer(CM_NOTIFYDURATION_TIMER, 2000, (FuncPtr) srv_ctm_phdlr_send_text_rsp);
#endif /* __CTM_DEBUG */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_set_tty_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_present      [IN]        
 *  void(?)         [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_set_tty_status(MMI_BOOL is_present)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_callset_ctm_get_mode())
    {
        srv_ctm_p->tty_status = is_present;
    }
    else
    {
        srv_ctm_p->tty_status = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_SET_TTY_STATUS, srv_ctm_p->tty_status);

}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_switch_tty_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_present      [IN]        
 *  void(?)         [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ctm_switch_tty_status(MMI_BOOL switch_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode, setting;
    S32 call_count;
    srv_ctm_tty_device_status_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    call_count = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL);

    setting = srv_callset_ctm_get_setting();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CTM_SWITCH_TTY_STATUS, srv_ctm_p->state, 
        srv_ctm_p->mode_activated, setting);

    if (switch_on)
    {
        if (srv_callset_ctm_get_mode())
        {
            /* CTM on, take as TTY */
            srv_ctm_p->tty_status = MMI_TRUE;
            if ((srv_ctm_p->state != SRV_CTM_STATE_IDLE &&
                    srv_ctm_p->mode_activated == AUD_CTM_DIRECT_MODE)
                || (srv_ctm_p->state == SRV_CTM_STATE_IDLE && call_count >= 1))
            {
                /* plug in, open again */
                if (srv_ctm_p->state != SRV_CTM_STATE_IDLE)
                {
                    srv_ctm_p->state = SRV_CTM_STATE_CLOSING;
                    srv_ctm_med_close_req();
                }

                mode = srv_ctm_derive_mode();

                if (mode != 0xff)
                {
                    srv_ctm_p->state = SRV_CTM_STATE_OPENING;
                    srv_ctm_p->mode_opening = mode;
                    srv_ctm_med_open_req(mode);
                }
            }

            evt.is_plug_in = MMI_TRUE;
            srv_ctm_send_ind(SRV_CTM_IND_TTY_DEVICE_STATUS, &evt);

            if (!srv_ctm_p->ctm_call_mode)
            {
                srv_ctm_p->ctm_call_mode = MMI_TRUE;
                srv_ctm_l4c_set_ctm_status_req(MMI_TRUE);
            }

        }
        else
        {
            /* CTM off, take as headset */
            srv_ctm_p->tty_status = MMI_FALSE;
        }
    }
    else
    {
        srv_ctm_p->tty_status = MMI_FALSE;
        if (srv_callset_ctm_get_mode())
        {
            /* CTM on, TTY to direct */
            if (srv_ctm_p->state != SRV_CTM_STATE_IDLE)
            {
                srv_ctm_p->state = SRV_CTM_STATE_CLOSING;
                srv_ctm_med_close_req();
            }

            if (((setting == SRV_CALLSET_CTM_SETTING_AUTO_DIRECT
                        || setting == SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT)
                    && (srv_ctm_p->mode_activated != AUD_CTM_DIRECT_MODE
                        || srv_ctm_p->state == SRV_CTM_STATE_CLOSING))
                || (srv_ctm_p->state == SRV_CTM_STATE_IDLE && call_count >= 1))
            {
                /* plug out, open again */
                srv_ctm_p->state = SRV_CTM_STATE_OPENING;
                srv_ctm_p->mode_opening = AUD_CTM_DIRECT_MODE;
                srv_ctm_med_open_req(AUD_CTM_DIRECT_MODE);
            }

            evt.is_plug_in = MMI_FALSE;
            srv_ctm_send_ind(SRV_CTM_IND_TTY_DEVICE_STATUS, &evt);

            if (srv_callset_ctm_is_tty_on())
            {
                srv_ctm_p->ctm_call_mode = MMI_FALSE;
                srv_ctm_l4c_set_ctm_status_req(MMI_FALSE);
            }

        }
        else
        {
            /* CTM off, do nothing */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_is_connected
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_ctm_is_connected()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ctm_p->state == SRV_CTM_STATE_CONNECTED ||
        srv_ctm_p->state == SRV_CTM_STATE_CONNECTING ||
        srv_ctm_p->state == SRV_CTM_STATE_SENDING)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, SRV_CTM_IS_CONNECTED_YES);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, SRV_CTM_IS_CONNECTED_NO);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_hdlr_earphone_plug_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
mmi_ret srv_ctm_hdlr_earphone_plug_in(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_ctm_is_tty_on() && !srv_ctm_get_tty_status())
    {
        srv_ctm_switch_tty_status(MMI_TRUE);
        return 1;
    }
    else
    {
        return MMI_RET_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_hdlr_earphone_plug_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
mmi_ret srv_ctm_hdlr_earphone_plug_out(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_ctm_is_tty_on() && srv_ctm_get_tty_status())
    {
        srv_ctm_switch_tty_status(MMI_FALSE);
        return 1;
    }
    else
    {
        return MMI_RET_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_hdlr_earphone_query_ctrl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  result
 *****************************************************************************/
mmi_ret srv_ctm_hdlr_earphone_query_ctrl(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ctm_get_tty_status())
    {
        return 1;
    }
    else
    {
        return MMI_RET_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_hdlr_ctm_setting_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_ctm_hdlr_ctm_setting_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct earphone_evt;
    U8 setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_callset_ctm_is_tty_on() && !srv_ctm_get_tty_status() && srv_earphone_is_plug_in())
    {
        /* send plug out event before switch tty status */
        /* earphone plug out */
        MMI_FRM_INIT_EVENT(&earphone_evt, EVT_ID_GPIO_EARPHONE_PLUG_OUT);
        MMI_FRM_CB_EMIT_EVENT(&earphone_evt);

        /* tty device plug in */
        srv_ctm_switch_tty_status(MMI_TRUE);
    }
    else if (!srv_callset_ctm_is_tty_on() && srv_ctm_get_tty_status())
    {
        /* tty device plug out */
        srv_ctm_switch_tty_status(MMI_FALSE);

        /* send plug in event after switch tty status */
        /* earphone plug in */
        MMI_FRM_INIT_EVENT(&earphone_evt, EVT_ID_GPIO_EARPHONE_PLUG_IN);
        MMI_FRM_CB_EMIT_EVENT(&earphone_evt);
    }

    setting = srv_callset_ctm_get_setting();
    if (!srv_callset_ctm_get_mode())
    {
        /* off */
        if (srv_ctm_p->ctm_call_mode)
        {
            srv_ctm_p->ctm_call_mode = MMI_FALSE;
            srv_ctm_l4c_set_ctm_status_req(MMI_FALSE);
        }
    }
    else if (setting == SRV_CALLSET_CTM_SETTING_AUTO_DIRECT ||
        setting == SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT)
    {
        /* direct mode */
        if (srv_callset_ctm_get_mode() && !srv_ctm_p->ctm_call_mode)
        {
            srv_ctm_p->ctm_call_mode = MMI_TRUE;
            srv_ctm_l4c_set_ctm_status_req(MMI_TRUE);
        }
    }
    else
    {
        /* other modes */
        if (!srv_ctm_get_tty_status() && srv_ctm_p->ctm_call_mode)
        {
            /* doesn't switch tty status, ex. change from direct mode to tty mode without tty device */
            srv_ctm_p->ctm_call_mode = MMI_FALSE;
            srv_ctm_l4c_set_ctm_status_req(MMI_FALSE);
        }
    }

    if ((srv_ctm_p->state == SRV_CTM_STATE_OPENING) || 
        (srv_ctm_p->state == SRV_CTM_STATE_OPENED))
    {
        /* re-open as the changed setting */
        srv_ctm_open(MMI_FALSE);
        srv_ctm_open(MMI_TRUE);
    }

    return MMI_RET_OK;
}
#endif /* __CTM_SUPPORT__ */

