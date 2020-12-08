/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * jsatas_apdu.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifdef SUPPORT_JSR_177
/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "stack_common.h"
#include "stack_ltlcom.h"
#include "kal_general_types.h"
#include "sim_public_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "jsatsa_interface.h"
#include "jsatsa_internal.h"
#include "jvm_trace_interface.h"
#include "jvm_mem.h"
#include "jam_interface.h"


static kal_bool jsatsa_apdu_locker = KAL_FALSE;
static kal_uint8 *jsatsa_apdu_response_data = NULL;
static kal_int32 jsatsa_apdu_response_data_length = 0;
static jsatsa_apdu_state_enum jsatsa_apdu_state = JSATSA_APDU_STATE_IDLE;

/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_is_locked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jsatsa_apdu_is_locked(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jsatsa_apdu_locker)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_sim_get_atr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jsatsa_apdu_sim_get_atr(kal_int32 slot, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    sim_jsr177_atr_req_struct *dataPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr(), enter j2me_apdu_sim_get_atr_req()   %d\n", __LINE__);  
    if (jsatsa_apdu_state != JSATSA_APDU_STATE_IDLE)
    {
        return KAL_FALSE;
    }
 
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr(), set message information to transive to card	  %d\n", __LINE__);  
    Message = allocate_ilm(MOD_JASYN_D);
    Message->oslSrcId = MOD_JASYN_D;
    if (slot == 0)
    {
        Message->oslDestId = MOD_SIM;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (slot == 1)
    {
        Message->oslDestId = MOD_SIM_2;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    else if (slot == 2)
    {
        Message->oslDestId = MOD_SIM_3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (slot == 3)
    {
        Message->oslDestId = MOD_SIM_4;
    }
#endif

    Message->oslMsgId = MSG_ID_SIM_JSR177_ATR_REQ;
    Message->sap_id = INVALID_SAP;
    dataPtr = (sim_jsr177_atr_req_struct *) OslConstructDataPtr(sizeof(sim_jsr177_atr_req_struct));
    dataPtr->src_id = MOD_JASYN_D;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;

    jsatsa_apdu_locker = KAL_TRUE;
    jsatsa_apdu_state = JSATSA_APDU_STATE_GET_ATR;
	
    msg_send_ext_queue(Message);
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr(), leave j2me_apdu_sim_get_atr_req()   %d\n", __LINE__);  
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_sim_get_atr_rsp_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_struct
 * RETURNS
 *  void
 *****************************************************************************/
void jsatsa_apdu_sim_get_atr_rsp_handler(ilm_struct *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    sim_jsr177_atr_cnf_struct *getATRCnf = (sim_jsr177_atr_cnf_struct *) msgPtr->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, enter SimGetATRCnf() \n", __LINE__);
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, result:%x\n", __LINE__, msgPtr);
	 
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, response length of ATR: %d\n", __LINE__,getATRCnf->atr_len);
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, ATR of card:\n", __LINE__);
    for(i=0;i<getATRCnf->atr_len;i++)
    {
        jvm_trace_debug("%x ",getATRCnf->atr[i]);
    }
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, response status of ATR: %x\n", __LINE__,getATRCnf ->result);
    if (getATRCnf->result == 0x00)//Success
    {	 
        jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, getATR success %d\n", __LINE__); 	 
	 
        jsatsa_apdu_response_data_length = getATRCnf->atr_len;
		
        jsatsa_apdu_response_data = (kal_uint8 *)jvm_malloc(getATRCnf->atr_len);
        memset(jsatsa_apdu_response_data, 0, getATRCnf->atr_len);
	 
        for(i = 0; i < jsatsa_apdu_response_data_length; i++)
        {
            jsatsa_apdu_response_data[i] = getATRCnf->atr[i];			 
        }
    }
    else
    {
        jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, getATR fail %d\n", __LINE__);
        jsatsa_apdu_response_data_length = 0;		 
    }
    jsatsa_apdu_locker = KAL_FALSE;
    jvm_trace_debug("[jsatsa_apdu].jsatsa_apdu_sim_get_atr_rsp_handler(), %d, leave SimGetATRCnf() \n", __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_send_apdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_uint8
 *  kal_int32
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jsatsa_apdu_send_apdu(kal_uint8 *data, kal_int32 length, kal_int32 slot, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    sim_jsr177_apdu_req_struct *dataPtr;
    int jj;
    int le_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	 
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu(), %d\n", __LINE__);

    if (jsatsa_apdu_state != JSATSA_APDU_STATE_IDLE)
    {
        return KAL_FALSE;
    }
		 
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu(), %d,apdu_req\n", __LINE__); 	 
    for(jj=0;jj<length;jj++)
        jvm_trace_debug("%x  ",data[jj]);
	 
    jvm_trace_debug("\n");
	
    Message = allocate_ilm(MOD_JASYN_D);
    Message->oslSrcId = MOD_JASYN_D;
    if (slot == 0)
    {
        Message->oslDestId = MOD_SIM;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (slot == 1)
    {
        Message->oslDestId = MOD_SIM_2;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    else if (slot == 2)
    {
        Message->oslDestId = MOD_SIM_3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (slot == 3)
    {
        Message->oslDestId = MOD_SIM_4;
    }
#endif
    Message->oslMsgId = MSG_ID_SIM_JSR177_APDU_REQ;
    Message->sap_id = INVALID_SAP;
    dataPtr= (sim_jsr177_apdu_req_struct *) OslConstructDataPtr(sizeof(sim_jsr177_apdu_req_struct));
	 
    memset(dataPtr->apdu_req, 0, 261);
    memcpy(dataPtr->apdu_req, data, length);
		 
    dataPtr->src_id = 0;
    dataPtr->transport_protocol_type = 0;
    dataPtr->apdu_req_len = length;
    if(dataPtr->apdu_req[1] == 0xc0 || dataPtr->apdu_req[1] == 0xC0)
    {
        dataPtr->expected_rsp_len = dataPtr->apdu_req[4];
    }
    else if(dataPtr->apdu_req[1] == 0x70)
    { // open channel expected response length
        dataPtr->expected_rsp_len = 1;
    }
    else
    {
        dataPtr->expected_rsp_len = 0;
    }
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu(), %d, expected_rsp_len: %d\n", __LINE__, dataPtr->expected_rsp_len);  
	 /*
		 le_index=dataPtr->apdu_req[4]+5;//get Le value
		 if(dataPtr->apdu_req[1]==0x70 && dataPtr->apdu_req[2]==0x00){
			 jvm_trace_debug("jsr177apdunatives_impl.c jsatsa_apdu_send_apdu(), %d, dataPtr->expected_rsp_len=1\n", __LINE__ );
			 dataPtr->expected_rsp_len=1;
		 }
		 else if(dataPtr->apdu_req[5]==0x00 && dataPtr->apdu_req[6]==0x00){
			 jvm_trace_debug("jsr177apdunatives_impl.c jsatsa_apdu_send_apdu(), %d, dataPtr->apdu_req[le_index]:%d\n", __LINE__ , dataPtr->apdu_req[le_index]);
			 dataPtr->expected_rsp_len=dataPtr->apdu_req[4];
		 }
		 else if(dataPtr->apdu_req[5]!=0x00 && dataPtr->apdu_req[6]!=0x00){
			 jvm_trace_debug("jsr177apdunatives_impl.c jsatsa_apdu_send_apdu(), %d, dataPtr->apdu_req[le_index]:%d\n", __LINE__ , dataPtr->apdu_req[le_index]);
			 dataPtr->expected_rsp_len=0;
		 }
	 */
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;

    jsatsa_apdu_locker = KAL_TRUE;
    jsatsa_apdu_state = JSATSA_APDU_STATE_SEND_APDU;
	
    msg_send_ext_queue(Message);
	 
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu(), %d, end....\n", __LINE__); 	 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_send_apdu_rsp_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_struct
 * RETURNS
 *  void
 *****************************************************************************/
void jsatsa_apdu_send_apdu_rsp_handler(ilm_struct *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    sim_jsr177_apdu_cnf_struct *sendApduPreCnf = (sim_jsr177_apdu_cnf_struct *) msgPtr->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, RENEW AGAIN \n", __LINE__);
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, result:%x\n", __LINE__, msgPtr);
	 
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, endApduPreCnf->apdu_rsp_len:%d\n", __LINE__,sendApduPreCnf->apdu_rsp_len);
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, sendApduPreCnf->apdu_rsp:\n", __LINE__);
	 
    for(i=0;i<sendApduPreCnf->apdu_rsp_len;i++)
        jvm_trace_debug("%x ",sendApduPreCnf->apdu_rsp[i]);
	 
    jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, sendApduPreCnf ->result:%d\n", __LINE__,sendApduPreCnf->result);
    if (sendApduPreCnf->result == 0x00)//Success
    {	 
        jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, apdu set 1:%d\n", __LINE__, jsatsa_apdu_locker);		 
	 
        jsatsa_apdu_response_data_length = sendApduPreCnf->apdu_rsp_len + 1;

        jsatsa_apdu_response_data = (kal_uint8 *)jvm_malloc(sendApduPreCnf->apdu_rsp_len + 1);
        memset(jsatsa_apdu_response_data, 0, sendApduPreCnf->apdu_rsp_len + 1);
			 
        for(i = 0; i < jsatsa_apdu_response_data_length; i++)
        {
            if(i == 0)
            {
                jsatsa_apdu_response_data[i] = sendApduPreCnf->result;
            }
            else
            {
                jsatsa_apdu_response_data[i] = sendApduPreCnf->apdu_rsp[i - 1];
            }
            jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, grx_buffer:%x\n", __LINE__, jsatsa_apdu_response_data[i]);		 
        }

        jvm_trace_debug("jsatsa_apdu.c jsatsa_apdu_send_apdu_rsp_handler(), %d, CNF end\n", __LINE__);		  
    }

    jsatsa_apdu_locker = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_is_locked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8*
 *****************************************************************************/
kal_uint8* jsatsa_apdu_get_response_data(kal_int32 *length, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *response_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jsatsa_apdu_response_data_length > 0)
    {
        response_data = jsatsa_apdu_response_data;
        jsatsa_apdu_response_data = NULL;
        *length = jsatsa_apdu_response_data_length;
        jsatsa_apdu_response_data_length = 0;
    }

    jsatsa_apdu_state = JSATSA_APDU_STATE_IDLE;
	
    return response_data;
}


/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_mvm_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jsatsa_apdu_mvm_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jsatsa_apdu_response_data)
    {
        jvm_free(jsatsa_apdu_response_data);
        jsatsa_apdu_response_data = NULL;
        jsatsa_apdu_response_data_length = 0;
    }

    jsatsa_apdu_state = JSATSA_APDU_STATE_IDLE;
	
    return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jsatsa_apdu_mvm_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jsatsa_apdu_mvm_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jsatsa_apdu_response_data)
    {
        jvm_free(jsatsa_apdu_response_data);
        jsatsa_apdu_response_data = NULL;
        jsatsa_apdu_response_data_length = 0;
    }

    jsatsa_apdu_state = JSATSA_APDU_STATE_IDLE;
	
    return J2ME_NO_ERROR;
}
#endif /* SUPPORT_JSR_177 */

