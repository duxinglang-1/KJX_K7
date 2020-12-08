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
 *  SMSSenderSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * SMS service sender handler Core Codes
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "kal_general_types.h"
#include "string.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "stack_timer.h"        /* stack_timer_struct */
#include "l4a.h"                /* L4 data type */
#include "mmi_msg_struct.h"
#include "MMI_trc_Int.h"
#include "custom_mmi_default_value.h"

#include "SmsSrvGprot.h"
#include "SmsProtSrv.h"
#include "SMSSenderSrv.h"
#include "SmsQueueSrv.h"
#include "SmsDispatchSrv.h"
#include "SmsUtilSrv.h"
#include "SmsConverterSrv.h"
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
#include "SmsSendfromStorageSrv.h"
#endif
#include "SmsStorageSrv.h"
#include "SmsEmsSrv.h"
#include "SmsStatusReportSrv.h"
#include "MMI_trc_Int.h"
#include "custom_mmi_default_value.h"


/**************************************************************
* MARCO
**************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
#define SRV_MAX_FG_SENDING_ACTION_NUM     0
#elif defined(__LOW_COST_SUPPORT_COMMON__)
#define SRV_MAX_FG_SENDING_ACTION_NUM     1
#else
#define SRV_MAX_FG_SENDING_ACTION_NUM     2
#endif

#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
#define SRV_MAX_BG_SAVE_SEND_ACTION_NUM   1
#else
#define SRV_MAX_BG_SAVE_SEND_ACTION_NUM   0
#endif

#define SRV_MAX_BG_SENDING_ACTION_NUM     1

#define SRV_MAX_SEND_PDU_LIST_POOL_NUM   (SRV_MAX_FG_SENDING_ACTION_NUM + SRV_MAX_BG_SAVE_SEND_ACTION_NUM + SRV_MAX_BG_SENDING_ACTION_NUM)


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    MMI_BOOL valid_flag;
    U8 pdu_data[(SRV_SMS_MAX_PDU_SIZE) *SRV_SMS_MAX_SEG];
} srv_sms_send_pdu_list_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/ 

/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static S16 sending_action_num = 0;
static U8 bg_sending_action_num = 0;

static srv_sms_send_pdu_list_struct pdu_list_pool[SRV_MAX_SEND_PDU_LIST_POOL_NUM];

/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_notify_start_sending_icon(SMS_HANDLE sms_handle);
static void srv_sms_notify_stop_sending_icon(MMI_BOOL is_stop, srv_sms_sim_enum sim_id);
static void srv_sms_pre_send_sms(SMS_HANDLE sms_handle);
static void srv_sms_fg_send(SMS_HANDLE sms_handle);
static void srv_sms_bg_send(SMS_HANDLE sms_handle);
static void srv_sms_send_sms_rsp(srv_sms_disp_cb_struct* cb_data);
static void srv_sms_counter_plus_one(srv_sms_send_handle_struct *handle_data);
static void srv_sms_fg_send_get_msg_rp_rsp(srv_sms_callback_struct *callback_data);
static void srv_sms_send_sms_seg(SMS_HANDLE sms_handle);

/**************************************************************
* Function Defination
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_sms_malloc_ems_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_sms_malloc_pdu_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pdu_data = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_MAX_SEND_PDU_LIST_POOL_NUM; i++)
    {
        if (pdu_list_pool[i].valid_flag == MMI_FALSE)
        {
            pdu_data = pdu_list_pool[i].pdu_data;
            break;
        }
    }

    return pdu_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_ems_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_free_pdu_data(U8 *pdu_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_MAX_SEND_PDU_LIST_POOL_NUM; i++)
    {
        if ((pdu_list_pool[i].pdu_data == pdu_data) &&
            (pdu_list_pool[i].valid_flag == MMI_TRUE))
        {
            pdu_list_pool[i].valid_flag = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_reset_ems_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_reset_pdu_data(U8 *pdu_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) pdu_data, 0, (SRV_SMS_MAX_PDU_SIZE) *SRV_SMS_MAX_SEG);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_ucs2_text_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2_content        [?]         
 *  ucs2_number         [?]         
 *  sim_id              [IN]        
 *  callback_func       [IN]        
 *  user_data           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_ucs2_text_msg(
        char *ucs2_content,
        char *ucs2_number,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handle;
    U16 content_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_handle = srv_sms_get_send_handle();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_UCS2_TEXT_MSG, sms_handle);

    srv_sms_set_address(sms_handle, ucs2_number);

    srv_sms_set_sim_id(sms_handle, sim_id);

    srv_sms_set_content_dcs(sms_handle, SRV_SMS_DCS_UCS2);

    content_size = mmi_ucs2strlen(ucs2_content) *ENCODING_LENGTH;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_UCS2_TEXT_MSG_1, content_size);
    srv_sms_set_content(sms_handle, ucs2_content, content_size);

    srv_sms_send_msg(sms_handle, callback_func, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_asc_text_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  asc_content     [?]         
 *  asc_number      [?]         
 *  sim_id          [IN]        
 *  callback_func   [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_asc_text_msg(
        char *asc_content,
        char *asc_number,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_size;
    S8 ucs2_number[(SRV_SMS_MAX_ADDR_LEN + 1)*ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) srv_sms_get_send_handle();
    srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_ASC_TEXT_MSG, sms_hd);

    mmi_asc_n_to_ucs2((S8*)ucs2_number, (S8*)asc_number, SRV_SMS_MAX_ADDR_LEN);
    srv_sms_set_address((SMS_HANDLE)sms_hd, ucs2_number);

    srv_sms_set_sim_id((SMS_HANDLE)sms_hd, sim_id);

    content_size = strlen((S8*) asc_content);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_ASC_TEXT_MSG_1, content_size);

    srv_sms_set_content((SMS_HANDLE)sms_hd, asc_content, (U16)content_size);

    srv_sms_set_content_asc(MMI_TRUE, &(send_hd->msg_data));

    srv_sms_send_msg((SMS_HANDLE)sms_hd, callback_func, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_data_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  send_data       [?]         
 *  callback_func   [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_data_msg(srv_sms_send_port_data_struct *send_data, SrvSmsCallbackFunc callback_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_handle = srv_sms_get_send_handle();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_DATA_MSG, sms_handle);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_DATA_MSG_1, send_data->content_size);

    srv_sms_set_address(sms_handle, send_data->number);

    srv_sms_set_data_port(sms_handle, send_data->src_port, send_data->dest_port);

    srv_sms_set_sim_id(sms_handle, send_data->sim_id);

    srv_sms_set_content_dcs(sms_handle, SRV_SMS_DCS_8BIT);

    if (send_data->content_file_path != NULL)
    {
        srv_sms_set_content_file(sms_handle, send_data->content_file_path);
    }
    else if (send_data->content_size > 0)
    {
        srv_sms_set_content(sms_handle, send_data->content_buff, send_data->content_size);
    }

    srv_sms_send_msg(sms_handle, callback_func, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_send_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_get_send_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_handle;
    srv_sms_send_handle_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd_data = OslMalloc(sizeof(srv_sms_send_handle_struct));

    memset((S8*) hd_data, 0, sizeof(srv_sms_send_handle_struct));

    memset((S8*) &(hd_data->msg_data), 0, sizeof(srv_sms_int_msg_data_struct));

    hd_data->reply_msg_id = SRV_SMS_INVALID_MSG_ID;
    hd_data->msg_id = SRV_SMS_INVALID_MSG_ID;
    hd_data->action_id = SRV_SMS_ACTION_INVALID_ID;
    hd_data->sim_id = SRV_SMS_SIM_1;
    hd_data->send_type = SRV_SMS_BG_SEND;

    hd_data->msg_data.sim_id = SRV_SMS_SIM_1;
    hd_data->msg_data.is_allow_num_emtpy = MMI_FALSE;
    hd_data->msg_data.is_allow_sc_emtpy = MMI_FALSE;
    hd_data->msg_data.is_asc_content = MMI_FALSE;
    hd_data->msg_data.status = SRV_SMS_STATUS_UNSENT;
#ifdef __SRV_SMS_MULTI_ADDR__
    hd_data->msg_data.addr_num = 0;
#endif

    hd_data->is_abort = MMI_FALSE;
    hd_data->is_use_action = MMI_FALSE;

#ifdef __SRV_SMS_DELIVERY_STATUS__
    hd_data->report_id = SRV_SMS_INVALID_MSG_ID;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

    sms_handle = OslMalloc(sizeof(srv_sms_handle_struct));
    sms_handle->action = SRV_SMS_ACTION_SEND;
    sms_handle->hd_data = (void*) hd_data;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_GET_SEND_HANDLE, sms_handle);

    return (SMS_HANDLE)sms_handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_send_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_free_send_handle(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    srv_sms_handle_struct *send_hd;
    srv_sms_send_handle_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FREE_SEND_HANDLE, sms_handle);

    MMI_ASSERT(sms_handle != NULL);

    send_hd = (srv_sms_handle_struct*) sms_handle;
    hd_data = (srv_sms_send_handle_struct*)send_hd->hd_data;

    MMI_ASSERT(hd_data != NULL);

    if (hd_data->send_type == SRV_SMS_FG_SEND)
    {
        if ((sending_action_num > 0) && hd_data->is_use_action)
        {
            sending_action_num--;
        }
    }
    else if (hd_data->send_type == SRV_SMS_BG_SEND)
    {
        srv_sms_queue_delete_action(SRV_SMS_QUEUE_BG, hd_data->action_id);

        if ((bg_sending_action_num > 0) && hd_data->is_use_action)
        {
            bg_sending_action_num--;
        }
    }

    if(hd_data->pdu_list[0] != NULL)
    {
        srv_sms_free_pdu_data(hd_data->pdu_list[0]);
    }
    hd_data->pdu_list[0] = NULL;

    OslMfree(hd_data);
    hd_data = NULL;

    OslMfree(send_hd);
    send_hd = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  send_data       [?]         
 *  callback_func        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_msg(SMS_HANDLE sms_handle, SrvSmsCallbackFunc callback_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd;
    srv_sms_send_handle_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_SRV_SEND_MSG);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_SRV_SEND_MSG_1, sms_handle);

    sms_hd = (srv_sms_handle_struct*) sms_handle;

    hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    hd_data->callback_func = callback_func;
    hd_data->user_data = user_data;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_SRV_SEND_MSG_2, hd_data->send_type);

#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    if (hd_data->send_type == SRV_SMS_BG_SAVE_SEND)
    {
        srv_sms_send_from_storage_save_req(sms_handle);
    }
    else
#endif /* #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
    {
        if (((hd_data->send_type == SRV_SMS_BG_SEND) && (srv_sms_is_bg_send_action_busy() == MMI_TRUE))
            || ((hd_data->send_type == SRV_SMS_FG_SEND) && (srv_sms_is_send_action_busy() == MMI_TRUE)))
        {
            srv_sms_send_msg_callback(sms_handle, MMI_FALSE, SRV_SMS_CAUSE_SEND_BUSY);
        }
        else
        {
            if ((hd_data->send_type == SRV_SMS_FG_SEND) && (hd_data->reply_msg_id != SRV_SMS_INVALID_MSG_ID))
            {
                srv_sms_get_msg_reply_path(hd_data->reply_msg_id, srv_sms_fg_send_get_msg_rp_rsp, sms_handle);
            }
            else
            {
                srv_sms_pre_send_sms(sms_handle);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_fg_send_get_msg_rp_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_fg_send_get_msg_rp_rsp(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd_data->reply_msg_id = SRV_SMS_INVALID_MSG_ID;

    if (callback_data->result)
    {
        srv_sms_get_msg_reply_path_cb_struct *rp_data = (srv_sms_get_msg_reply_path_cb_struct*)callback_data->action_data;

        if (rp_data->reply_path)
        {
            U16 sc_addr[SRV_SMS_MAX_ADDR_LEN + 1];
            U16 addr_len;

            addr_len = mmi_asc_n_to_ucs2((S8*)sc_addr, (S8*)rp_data->sc_addr, SRV_SMS_MAX_ADDR_LEN);
            sc_addr[addr_len / ENCODING_LENGTH] = '\0';

            srv_sms_set_sc_address(sms_hd, (S8*)sc_addr);
        }
    }

    if ((hd_data->spec_para & SRV_SMS_SPEC_SEND_ABORT)
        || hd_data->is_abort)
    {
        srv_sms_sim_enum sim_id = hd_data->sim_id;
        MMI_BOOL is_stop = MMI_FALSE;

        if ((hd_data->spec_para & SRV_SMS_SPEC_SEND_WITHOUT_ICON) != SRV_SMS_SPEC_SEND_WITHOUT_ICON)
        {
            is_stop = MMI_TRUE;
        }

        srv_sms_send_msg_callback((SMS_HANDLE)sms_hd, MMI_FALSE, SRV_SMS_CAUSE_SEND_ABORT);

        /* check notify UI stop display sending icon */
        srv_sms_notify_stop_sending_icon(is_stop, sim_id);
    }
    else
    {
        srv_sms_pre_send_sms((SMS_HANDLE)sms_hd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_not_allow_empty_sc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sms_handle       [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_not_allow_empty_sc(SMS_HANDLE sms_handle)
{
    //will be removed, phase out 
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_no_sending_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sms_handle       [IN]               
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_no_sending_icon(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_SET_NO_SENDING_ICON, sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_WITHOUT_ICON;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_counter_without_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sms_handle       [IN]               
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_counter_without_change(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_SET_COUNTER_WITHOUT_CHANGE, sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_COUNTER_WITHOUT_CHANGE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_abort_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_abort_send(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd;
    srv_sms_send_handle_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_ABORT_SEND, sms_handle);
    if (sms_handle == NULL)
    {
        return;
    }

    sms_hd = (srv_sms_handle_struct*) sms_handle;

    hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

    hd_data->is_abort = MMI_TRUE;

    if ((hd_data->send_type != SRV_SMS_FG_SEND) || (hd_data->reply_msg_id == SRV_SMS_INVALID_MSG_ID))
    {
        srv_sms_abort_sendig_sms((void*)sms_handle, hd_data->sim_id, srv_sms_send_sms_rsp, (void*)sms_handle);
    }
    else
    {
        hd_data->spec_para |= SRV_SMS_SPEC_SEND_ABORT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_send_callback
 * DESCRIPTION
 *  clear Ap's callback function, then if abort, will not callback any result to AP
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_clear_send_callback(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd;
    srv_sms_send_handle_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_CLEAR_SEND_CALLBACK, sms_handle);

    sms_hd = (srv_sms_handle_struct*) sms_handle;
    hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

    hd_data->callback_func = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_send_action_busy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type       [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_is_send_action_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sending_action_num >= SRV_MAX_FG_SENDING_ACTION_NUM)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_IS_FG_SEND_BUSY, MMI_TRUE);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_IS_FG_SEND_BUSY, MMI_FALSE);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_bg_send_action_busy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_is_bg_send_action_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bg_sending_action_num >= SRV_MAX_BG_SENDING_ACTION_NUM)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_IS_BG_SEND_BUSY, MMI_TRUE);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_IS_BG_SEND_BUSY, MMI_FALSE);
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_send_action_pending
 * DESCRIPTION
 *  check if SMS send busy
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_check_send_action_pending(srv_sms_send_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_CHECK_SEND_ACTION_PENDING, type);

    if (type == SRV_SMS_BG_SEND)
    {
        return srv_sms_is_bg_send_action_busy();
    }
    else if (type == SRV_SMS_BG_SAVE_SEND)
    {
        return MMI_FALSE;
    }
    else if (type == SRV_SMS_FG_SEND)
    {
        return srv_sms_is_send_action_busy();
    }
    else
    {
        MMI_ASSERT(0);
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_notify_start_sending_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_notify_start_sending_icon(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;
    srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_NOTIFY_START_SENDING_ICON);

    if ((send_hd->spec_para & SRV_SMS_SPEC_SEND_WITHOUT_ICON) != SRV_SMS_SPEC_SEND_WITHOUT_ICON)
    {
        srv_sms_event_update_sending_icon_struct *event_info;
 
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_NOTIFY_START_SENDING_ICON_1);

        event_info = OslMalloc(sizeof(srv_sms_event_update_sending_icon_struct));
        event_info->sim_id = send_hd->sim_id;
        event_info->is_show = MMI_TRUE;

        srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_SENDING_ICON, event_info);
        OslMfree(event_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_notify_stop_sending_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_notify_stop_sending_icon(MMI_BOOL is_stop, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_NOTIFY_STOP_SENDING_ICON);

    if (is_stop)
    {
        srv_sms_event_update_sending_icon_struct *event_info;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_NOTIFY_STOP_SENDING_ICON_1);

        event_info = OslMalloc(sizeof(srv_sms_event_update_sending_icon_struct));
        event_info->sim_id = sim_id;
        event_info->is_show = MMI_FALSE;

        srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_SENDING_ICON, event_info);
        OslMfree(event_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pre_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_pre_send_sms(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) sms_handle;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    S8* sc_addr = hd_data->msg_data.sc_address;
    S8* number = hd_data->msg_data.number;
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_PRE_SEND_SMS, sms_handle);

    srv_sms_update_send_msg_profile(hd_data);

    if ((sc_addr[0] == '\0') && (sc_addr[1] == '\0'))
    {
        cause = SRV_SMS_CAUSE_SC_EMPTY;
    }
    else if (srv_sms_check_ucs2_number(sc_addr) == MMI_FALSE)
    {
        cause = SRV_SMS_CAUSE_SC_INVALID;
    }
    else if ((number[0] == '\0') && (number[1] == '\0'))
    {
        cause = SRV_SMS_CAUSE_NUMBER_EMPTY;
    }
    else if (srv_sms_check_ucs2_number(number) == MMI_FALSE)
    {
        cause = SRV_SMS_CAUSE_NUMBER_INVALID;
    }
    else if (srv_sms_is_sms_valid() == MMI_FALSE)
    {  
        cause = SRV_SMS_CAUSE_NOT_READY;
    }

    if (cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_send_msg_callback(sms_handle, MMI_FALSE, cause);
    }
    else if (hd_data->send_type == SRV_SMS_FG_SEND)
    {
        srv_sms_fg_send(sms_handle);
    }
    else if (hd_data->send_type == SRV_SMS_BG_SEND)
    {
        srv_sms_bg_send(sms_handle);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_fg_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_fg_send(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) sms_handle;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    U8 *pdu_data = srv_sms_malloc_pdu_data();
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FG_SEND_SMS, sms_handle);

    MMI_ASSERT(pdu_data != NULL);

    sending_action_num++;
    hd_data->is_use_action = MMI_TRUE;

    /* Notify UI start dispaly sending icon */
    srv_sms_notify_start_sending_icon(sms_handle);

    /* pack PDU ???*/
    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        hd_data->pdu_list[i] = &pdu_data[i * SRV_SMS_MAX_PDU_SIZE];
    }

    error_cause = srv_sms_convert_msg_data_to_pdu(
        hd_data->pdu_list,
        hd_data->pdu_len_list,
        &(hd_data->total_segment),
        NULL,
        &(hd_data->msg_data),
        SRV_SMS_PACK_DEFAULT,
        hd_data->sim_id);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_sim_enum sim_id = hd_data->sim_id;
        MMI_BOOL is_stop = MMI_FALSE;
        if ((hd_data->spec_para & SRV_SMS_SPEC_SEND_WITHOUT_ICON) != SRV_SMS_SPEC_SEND_WITHOUT_ICON)
        {
            is_stop = MMI_TRUE;
        }

        srv_sms_send_msg_callback(sms_handle, MMI_FALSE, error_cause);
        srv_sms_notify_stop_sending_icon(is_stop, sim_id);
        return;
    }

    hd_data->ref_num = srv_sms_get_curr_concat_ref_num();
    hd_data->is_tp_srr = srv_sms_is_delivery_report_setting(hd_data->sim_id);

    srv_sms_send_sms_seg(sms_handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_bg_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_bg_send(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) sms_handle;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    U8 *pdu_data = srv_sms_malloc_pdu_data();
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_BG_SEND_SMS, sms_handle);

    MMI_ASSERT(pdu_data != NULL);

    bg_sending_action_num++;
    hd_data->is_use_action = MMI_TRUE;

    /* pack PDU ??? */
    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        hd_data->pdu_list[i] = &pdu_data[i * SRV_SMS_MAX_PDU_SIZE];
    }

    error_cause = srv_sms_convert_msg_data_to_pdu(
        hd_data->pdu_list,
        hd_data->pdu_len_list,
        &(hd_data->total_segment),
        NULL,
        &(hd_data->msg_data),
        SRV_SMS_PACK_DEFAULT,
        hd_data->sim_id);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_send_msg_callback(sms_handle, MMI_FALSE, error_cause);
        return;
    }

    hd_data->ref_num = srv_sms_get_curr_concat_ref_num();
    hd_data->is_tp_srr = srv_sms_is_delivery_report_setting(hd_data->sim_id);

    srv_sms_write_send_bg_action(SRV_SMS_BG_SEND, srv_sms_bg_send_req, sms_handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_bg_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_bg_send_req(srv_sms_queue_data_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sms_hd->action == SRV_SMS_ACTION_SEND);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_BG_SEND_SMS_REQ, sms_hd);

    srv_sms_send_sms_seg((SMS_HANDLE)sms_hd);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_queue_write_bg_send_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_write_send_bg_action(srv_sms_send_type_enum type, SrvSmsqueueCallbackFunc callback_func, SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_WRITE_BG_SEND_ACTION, type);

    if ((type == SRV_SMS_BG_SEND) || (type == SRV_SMS_BG_SAVE_SEND))
    {
        srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) sms_handle;
        srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

        action_id = srv_sms_queue_write_action(SRV_SMS_QUEUE_BG, callback_func, (void*)sms_handle);

        hd_data->action_id = action_id;

        srv_sms_notify_start_sending_icon(sms_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_send_msg_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_update_send_msg_profile(srv_sms_send_handle_struct *handle_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const srv_sms_setting_struct *default_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_UPDATE_MSG_PROFILE, handle_data->sim_id);

    default_setting = srv_sms_get_default_setting(handle_data->sim_id);

    if ((handle_data->msg_data.sc_address[0] == '\0') && (handle_data->msg_data.sc_address[1] == '\0'))
    {
        U16 addr_len;
        addr_len = mmi_asc_n_to_ucs2((S8*)handle_data->msg_data.sc_address, (S8*)default_setting->sc_addr, SRV_SMS_MAX_ADDR_LEN);

        if (addr_len > SRV_SMS_MAX_ADDR_LEN *ENCODING_LENGTH)
        {
            addr_len = SRV_SMS_MAX_ADDR_LEN *ENCODING_LENGTH;
        }
        handle_data->msg_data.sc_address[addr_len] = '\0';
        handle_data->msg_data.sc_address[addr_len + 1] = '\0';
        handle_data->msg_data.para_flag |= SRV_SMS_PARA_SCA;
        handle_data->spec_para |= SRV_SMS_SPEC_SEND_SCA;
    }

    if ((handle_data->spec_para & SRV_SMS_SPEC_SEND_VP) != SRV_SMS_SPEC_SEND_VP)
    {
        handle_data->msg_data.vp = default_setting->vp;
        handle_data->msg_data.para_flag |= SRV_SMS_PARA_VP;
        handle_data->spec_para |= SRV_SMS_SPEC_SEND_VP;
    }

    if (!(((handle_data->msg_data.para_flag & SRV_SMS_PARA_PID) == SRV_SMS_PARA_PID)
            && (handle_data->msg_data.pid == SRV_SMS_PID_EMAIL)))
    {
        handle_data->msg_data.pid = default_setting->pid;
        handle_data->msg_data.para_flag |= SRV_SMS_PARA_PID;
    }

    if ((handle_data->spec_para & SRV_SMS_SPEC_SEND_STATUS_REPORT) != SRV_SMS_SPEC_SEND_STATUS_REPORT)
    {
        handle_data->msg_data.status_report= default_setting->status_report;
        handle_data->msg_data.para_flag |= SRV_SMS_PARA_STATUS_REPORT;
        handle_data->spec_para |= SRV_SMS_SPEC_SEND_STATUS_REPORT;
    }

    if ((handle_data->spec_para & SRV_SMS_SPEC_SEND_REPLY_PATH) != SRV_SMS_SPEC_SEND_REPLY_PATH)
    {
        handle_data->msg_data.reply_path= default_setting->reply_path;
        handle_data->msg_data.para_flag |= SRV_SMS_PARA_REPLY_PATH;
        handle_data->spec_para |= SRV_SMS_SPEC_SEND_REPLY_PATH;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_sms_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_sms_seg(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_send_pdu_msg_req_struct msg_req;
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) sms_handle;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_START_SEND_SEG, sms_handle);
    MMI_ASSERT(sms_handle != NULL);
    MMI_ASSERT(hd_data != NULL);
    MMI_ASSERT(sms_hd->action == SRV_SMS_ACTION_SEND);

    memcpy(msg_req.pdu, hd_data->pdu_list[hd_data->present_seg], 175);

    msg_req.length = hd_data->pdu_len_list[hd_data->present_seg];

    if ((hd_data->present_seg + 1) < hd_data->total_segment)
    {
        msg_req.mms_mode = MMI_TRUE;
    }
    else
    {
        msg_req.mms_mode = MMI_FALSE;
    }

    srv_sms_send_sms((void*)&msg_req, hd_data->sim_id, srv_sms_send_sms_rsp, (void*)sms_handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_start_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_sms_rsp(srv_sms_disp_cb_struct* cb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_send_pdu_msg_rsp_struct *msg_rsp = (mmi_sms_send_pdu_msg_rsp_struct*)cb_data->data;
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) cb_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    U8 curr_seg = hd_data->present_seg;
    U8 total_seg = hd_data->total_segment;
    MMI_BOOL is_done = MMI_TRUE;
    MMI_BOOL result;
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_SEND_SMS_RSP, sms_hd);

    MMI_ASSERT(sms_hd != NULL);
    MMI_ASSERT(hd_data != NULL);

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    if (hd_data->is_tp_srr)
    {
        U16 report_id = hd_data->report_id;

        if (hd_data->is_abort || (!msg_rsp->result))
        {
            if (curr_seg > 0)
            {
                srv_sms_sr_del_report(report_id);
            }
        }
        else
        {
            U8 total_seg = hd_data->total_segment;

            if (curr_seg == 0)
            {
                srv_sms_sr_add_struct report_data;

                mmi_ucs2_to_asc((S8*)report_data.number, hd_data->msg_data.number);
                report_data.total_seg = total_seg;
                report_data.curr_seg = 0;
                report_data.curr_msg_ref = msg_rsp->mr;
                report_data.curr_status = SRV_SMS_SRS_PENDING;
                report_data.sim_id = hd_data->sim_id;

                if (total_seg == 1)
                {
                    report_data.is_hidden = MMI_FALSE;
                }
                else
                {
                    report_data.is_hidden = MMI_TRUE;
                }

                report_id = srv_sms_sr_add_report(&report_data);

                hd_data->report_id = report_id;
            }
            else
            {
                U32 timestamp = srv_sms_get_local_sec();
            
                srv_sms_sr_update_report(
                    report_id,
                    curr_seg,
                    msg_rsp->mr,
                    timestamp,
                    SRV_SMS_SRS_PENDING);

                if ((curr_seg + 1) == total_seg)
                {
                    hd_data->report_id = srv_sms_sr_unhide_report(report_id);
                }
            }
        }
    }
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

    if (hd_data->is_abort)
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_SEND_ABORT;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_ABORT_SEND_ACTION, sms_hd);

        if (hd_data->send_type != SRV_SMS_FG_SEND)
        {
            if (hd_data->action_id != SRV_SMS_ACTION_INVALID_ID)
            {
                srv_sms_queue_delete_action(SRV_SMS_QUEUE_BG, hd_data->action_id);
            }
        }
    }
    else
    {
        result = (MMI_BOOL)msg_rsp->result;

        if (result)
        {
            error_cause = SRV_SMS_CAUSE_NO_ERROR;

            /* counter++ */
            srv_sms_counter_plus_one(hd_data);

            hd_data->msg_ref[curr_seg] = msg_rsp->mr;

            if ((curr_seg + 1) < total_seg)
            {
                is_done = MMI_FALSE;

                hd_data->present_seg++;

                srv_sms_send_sms_seg((SMS_HANDLE)sms_hd);
            }
        }
        else
        {
            error_cause = (srv_sms_cause_enum)msg_rsp->cause;
        }
    }

    if (is_done)
    {
        srv_sms_sim_enum sim_id = hd_data->sim_id;
        MMI_BOOL is_stop = MMI_FALSE;

        if ((hd_data->spec_para & SRV_SMS_SPEC_SEND_WITHOUT_ICON) != SRV_SMS_SPEC_SEND_WITHOUT_ICON)
        {
            is_stop = MMI_TRUE;
        }

        srv_sms_send_msg_callback((SMS_HANDLE)sms_hd, result, error_cause);

        /* check notify UI stop display sending icon */
        srv_sms_notify_stop_sending_icon(is_stop, sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_counter_plus_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_counter_plus_one(srv_sms_send_handle_struct *handle_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_COUNTER_PLUS_ONE);

    if ((handle_data->spec_para & SRV_SMS_SPEC_SEND_COUNTER_WITHOUT_CHANGE)
        != SRV_SMS_SPEC_SEND_COUNTER_WITHOUT_CHANGE)
    {
        srv_sms_update_sms_counter(handle_data->sim_id, SRV_SMS_COUNT_SENT); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sms_send_msg_callback(SMS_HANDLE sms_handle, MMI_BOOL result, srv_sms_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) sms_handle;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    SrvSmsCallbackFunc callback_func = hd_data->callback_func;
    srv_sms_callback_struct callback_data;
    srv_sms_send_msg_cb_struct send_cb_data;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_CALLBACK, cause);

    send_cb_data.report_id = hd_data->report_id;
    send_cb_data.total_seg = hd_data->total_segment;

    for (i = 0; i < hd_data->total_segment; i++)
    {
        send_cb_data.msg_ref[i] = hd_data->msg_ref[i];
    }

    callback_data.result = result;
    callback_data.cause = cause;
    callback_data.action = SRV_SMS_ACTION_SEND;
    callback_data.user_data = hd_data->user_data;
    callback_data.action_data = &send_cb_data;

    if (hd_data->send_type != SRV_SMS_BG_SAVE_SEND)
    {
        srv_sms_free_send_handle(sms_handle);
    }

    if (callback_func != NULL)
    {
        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_pdu_callback(SMS_HANDLE sms_handle, MMI_BOOL result, srv_sms_cause_enum cause)
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
 *  srv_sms_get_unsent_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_send_status_enum srv_sms_get_unsent_msg_status(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status = SRV_SMS_SEND_INVALID;
    srv_sms_status_enum curr_msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_msg_status = srv_sms_get_msg_status(msg_id);

    if (curr_msg_status & SRV_SMS_STATUS_UNSENT)
    {
        status = srv_sms_get_msg_ext_status(msg_id);

        if (status == SRV_SMS_STATUS_NONE)
        {
            status = SRV_SMS_SEND_INVALID;
        }
    }

    return (srv_sms_send_status_enum)status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_event_api_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_event_api_send_msg(srv_sms_event_api_send_msg_struct *msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_api_send_msg_struct *event_info = OslMalloc(sizeof(srv_sms_event_api_send_msg_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(event_info, msg_data, sizeof(srv_sms_event_api_send_msg_struct));

    srv_sms_emit_event(EVT_ID_SRV_SMS_API_SEND_MSG, event_info);

    OslMfree(event_info);
}


#endif /* __MOD_SMSAL__ */

