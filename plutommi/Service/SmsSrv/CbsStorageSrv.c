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
 *  CbsMsgSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CBS(Cell Broadcast Service) Service Storage Handler
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __SRV_CBS_SUPPORT__

#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "string.h"
#include "ps_public_enum.h"
#include "Unicodexdcl.h"

#include "ProtocolEvents.h"
#include "mmi_common_app_trc.h"
#include "SmsSrvGProt.h"
#include "CbsSrvGProt.h"
#include "CbsProtSrv.h"
#include "SmsUtilSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "Gsm7BitNationalLang.h"


/**************************************************************
* MARCO
**************************************************************/
#define SRV_CBS_INVALID_PAGE_ID                 0xFFFF

#define CBS_READ_MSG_NODE_NUM                   (2048 / sizeof(srv_cbs_msg_node_struct))
#define CBS_WRITE_MSG_NODE_NUM                  5
#define CBS_READ_PAGE_NUM                       (2048 / sizeof(srv_cbs_page_struct))

#ifdef __SRV_SMS_MULTI_SIM__
#define CBS_CURR_SIM_ID                         (srv_cbs_sim_id)
#else /* __SRV_SMS_MULTI_SIM__ */
#define CBS_CURR_SIM_ID                         (SRV_SMS_SIM_1)
#endif /* __SRV_SMS_MULTI_SIM__ */


/**************************************************************
* Structure Declaration
**************************************************************/
/* Make sure the structure is same as nvram_ef_srv_cbs_page_struct */
typedef struct
{
    U16 next_page_id;
    U8 content[SRV_CBS_PAGE_CONTENT_LEN];
} srv_cbs_page_struct;

typedef struct
{
    MMI_BOOL is_done;
    U16 curr_index;
    U16 remain;
} srv_cbs_op_multi_struct;

typedef struct
{
    srv_sms_sim_enum sim_id;
    srv_cbs_op_multi_struct msg_info;
    srv_cbs_op_multi_struct page_info;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} storage_init_cntx_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    storage_init_cntx_struct *init_cntx;
} srv_cbs_evt_init_op_ind_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_cbs_cntx_struct *srv_cbs_cntx;
static srv_sms_sim_enum srv_cbs_sim_id;


/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_cbs_init_read_msg_hdlr(storage_init_cntx_struct *init_cntx);
static void srv_cbs_init_read_page_hdlr(storage_init_cntx_struct *init_cntx);
static mmi_ret srv_cbs_init_read_msg_callback(mmi_event_struct *param);
static mmi_ret srv_cbs_init_read_page_callback(mmi_event_struct *param);
static void srv_cbs_stroage_init_done_hdlr(storage_init_cntx_struct *init_cntx);
static MMI_BOOL srv_cbs_create_msg_list(void);
static void srv_cbs_init_reset_msg_hdlr(storage_init_cntx_struct *init_cntx);
static mmi_ret srv_cbs_init_reset_msg_callback(mmi_event_struct *param);

static void srv_cbs_add_msg_content(
                U8* msg_content,
                U32 msg_len,
                U8 msg_dcs,
                U16 page_id_list[],
                U8 total_page);
static MMI_BOOL srv_cbs_delete_msg_int(U16 msg_id);

static MMI_BOOL srv_cbs_is_msg_valid(U16 msg_id);
static MMI_BOOL srv_cbs_is_msg_mode_valid(srv_cbs_msg_node_struct* msg_node);
static void srv_cbs_add_msg_node(U16 msg_id, srv_cbs_msg_node_struct* msg_node);
static void srv_cbs_del_msg_node(U16 msg_id);
static void srv_cbs_reset_msg_node(srv_cbs_msg_node_struct* msg_node);
static void srv_cbs_add_msg_into_list(U16 msg_id);
static void srv_cbs_del_msg_from_list(U16 msg_id);
static U16 srv_cbs_get_unused_msg_id(void);
static U16 srv_cbs_get_unused_space(U16 page_id_list[], U8 total_page);
static U8 srv_cbs_count_total_page(U32 msg_len);
static U8 srv_cbs_get_msg_page_id(U16 msg_id, U16 page_id_list[]);
static void srv_cbs_add_page(U16 page_id, U8* page_content, U16 next_page_id);
static void srv_cbs_del_page(U16 page_id);
static void srv_cbs_read_page(U16 page_id, srv_cbs_page_struct* page_data);
static MMI_BOOL srv_cbs_get_unused_page_id(U16 page_id_list[], U8 total_page);
static U32 srv_cbs_remove_fill_bit(WCHAR* buffer, U32 buff_len);

static void srv_cbs_write_msg_node_record(U16 msg_id, srv_cbs_msg_node_struct* msg_node);

static void srv_cbs_set_curr_cntx(srv_sms_sim_enum sim_id);
static void srv_cbs_reset_storage_data(void);

static U16 srv_cbs_get_msg_node_record_index(U16 msg_id, srv_sms_sim_enum sim_id);
static U16 srv_cbs_get_page_record_index(U16 page_id, srv_sms_sim_enum sim_id);

/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_cbs_storage_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_storage_init(
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    storage_init_cntx_struct *init_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_STORAGE_INIT);

    init_cntx = OslMalloc(sizeof(storage_init_cntx_struct));

    init_cntx->sim_id = sim_id;
    init_cntx->callback_func = callback_func;
    init_cntx->user_data = user_data;

    init_cntx->msg_info.curr_index = 0;
    init_cntx->msg_info.remain = SRV_CBS_MAX_MSG_NUM;
    init_cntx->msg_info.is_done = MMI_FALSE;

    init_cntx->page_info.curr_index = 0;
    init_cntx->page_info.remain = SRV_CBS_MAX_PAGE_NUM;
    init_cntx->page_info.is_done = MMI_FALSE;

    srv_cbs_init_read_msg_hdlr(init_cntx);
    srv_cbs_init_read_page_hdlr(init_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_read_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cbs_read_msg(
            U16 msg_id,
            srv_sms_sim_enum sim_id,
            WCHAR* content_buff,
            U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    
    /*backup sim cntx*/
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_READ_MSG, msg_id, sim_id, content_buff, buff_len);
    srv_cbs_set_curr_cntx(sim_id);

    if ((buff_len > 0) && (srv_cbs_is_msg_valid(msg_id) == MMI_TRUE))
    {
        U16 page_id_list[SRV_CBS_MAX_PAGE_PRE_MSG];
        U8 total_page;
        U8 i = 0;
        srv_cbs_page_struct *page_data;
        WCHAR *tmp_content = content_buff;
        U32 remain_len = buff_len - 1;
        U32 used_len;
        srv_sms_dcs_enum msg_dcs = (srv_sms_dcs_enum)srv_cbs_cntx->msg_node[msg_id].msg_dcs;

        page_data = OslMalloc(sizeof(srv_cbs_page_struct));

        total_page = srv_cbs_get_msg_page_id(msg_id, page_id_list);

        while ((i < total_page) && (remain_len > 0))
        {
            U16 page_id = page_id_list[i];
        
            srv_cbs_read_page(page_id, page_data);

            srv_cbs_convert_content_for_display(
                tmp_content,
                &used_len,
                remain_len,
                page_data->content,
                SRV_CBS_PAGE_CONTENT_LEN,
                msg_dcs);

            tmp_content += used_len;
            remain_len -= used_len;
            i++;
        }       

        used_len = buff_len - 1 - remain_len;
        content_buff[used_len] = '\0';

        OslMfree(page_data);
    }
    else
    {
        result = MMI_FALSE;
    }

    /*restore sim cntx*/
    srv_cbs_set_curr_cntx(previous_sim_id);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_time
 * DESCRIPTION
 *  Set whether subscribe CBS service. Set the receive mode.
 * PARAMETERS
 *  is_subsrcibe    [IN]        Subscribe or not
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern U32 srv_cbs_get_msg_time(
                U16 msg_id,
                srv_sms_sim_enum sim_id)
{
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;
    U32 time = 0;
    srv_cbs_set_curr_cntx(sim_id);
    if (srv_cbs_is_msg_valid(msg_id) == MMI_TRUE)
    {
        time = srv_cbs_cntx->msg_node[msg_id].timestamp;
    }
    srv_cbs_set_curr_cntx(previous_sim_id );
    return time;
}

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_delete_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cbs_delete_msg(U16 msg_id, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DELETE_MSG, msg_id, sim_id);

    srv_cbs_set_curr_cntx(sim_id);

    result = srv_cbs_delete_msg_int(msg_id);
    
    srv_cbs_set_curr_cntx(previous_sim_id );
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_cbs_get_msg_num(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;
    S32 msg_nubmer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cbs_set_curr_cntx(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_MSG_NUM, sim_id, srv_cbs_cntx->msg_list_size);
    msg_nubmer = srv_cbs_cntx->msg_list_size;
    srv_cbs_set_curr_cntx(previous_sim_id );

    return msg_nubmer;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_chnl_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_cbs_get_msg_chnl_id(U16 msg_id, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 chnl_id = SRV_CBS_UNUSED_CBMI;
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_cbs_set_curr_cntx(sim_id);

    if (srv_cbs_is_msg_valid(msg_id))
    {
        chnl_id = srv_cbs_cntx->msg_node[msg_id].mi;
    }
    else
    {
        chnl_id = SRV_CBS_UNUSED_CBMI;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_MSG_CHNL_ID, msg_id, sim_id, chnl_id);
    srv_cbs_set_curr_cntx(previous_sim_id);
    return chnl_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_cbs_get_msg_id(U16 list_index, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cbs_set_curr_cntx(sim_id);

    if (list_index < srv_cbs_cntx->msg_list_size)
    {
        msg_id = srv_cbs_cntx->msg_list[list_index];
    }
    else
    {
        msg_id = SRV_CBS_INVALID_MSG_ID;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_MSG_ID, list_index, sim_id, msg_id);
    srv_cbs_set_curr_cntx(previous_sim_id );

    return msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_cbs_get_list_index(U16 msg_id, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cbs_set_curr_cntx(sim_id);

    for (i = 0; i < srv_cbs_cntx->msg_list_size; i++)
    {
        if (srv_cbs_cntx->msg_list[i] == msg_id)
        {
            break;
        }
    }
    
    srv_cbs_set_curr_cntx(previous_sim_id );
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_read_msg_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_init_read_msg_hdlr(storage_init_cntx_struct *init_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_op_multi_struct *read_info = &init_cntx->msg_info;
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_INIT_READ_MSG_HDLR, init_cntx->sim_id, read_info->remain);

    if (read_info->remain > 0)
    {
        srv_cbs_evt_init_op_ind_struct post_evt;
        U16 amount;
        U16 record_index;
        U8 *buffer;
        U16 buff_size;
        S16 error_code;
        S32 result;

        record_index = srv_cbs_get_msg_node_record_index(
                            read_info->curr_index,
                            init_cntx->sim_id);

        if (read_info->remain > CBS_READ_MSG_NODE_NUM)
        {
            amount = CBS_READ_MSG_NODE_NUM;
            read_info->remain -= CBS_READ_MSG_NODE_NUM;
        }
        else
        {
            amount = read_info->remain;
            read_info->remain = 0;
        }

        srv_cbs_set_curr_cntx(init_cntx->sim_id);

        buffer = (U8*)&srv_cbs_cntx->msg_node[read_info->curr_index];
        buff_size = sizeof(srv_cbs_msg_node_struct) * amount;

        result = ReadMultiRecord(
                    NVRAM_EF_SRV_CBS_MSG_NODE_LID,
                    record_index,
                    buffer,
                    buff_size,
                    amount,
                    &error_code);

        if (result < 0)
        {
            memset(buffer, 0, buff_size);
        }

        read_info->curr_index += amount;

        MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_CBS_INIT_OP_IND);
        post_evt.init_cntx= init_cntx;
        MMI_FRM_POST_EVENT(&post_evt, srv_cbs_init_read_msg_callback, NULL);
    }
    else
    {
        read_info->is_done = MMI_TRUE;
        srv_cbs_stroage_init_done_hdlr(init_cntx);
    }
    
    srv_cbs_set_curr_cntx(previous_sim_id );
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_read_page_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_init_read_page_hdlr(storage_init_cntx_struct *init_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_op_multi_struct *read_info = &init_cntx->page_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_INIT_READ_PAGE_HDLR, init_cntx->sim_id, read_info->remain);

    if (read_info->remain > 0)
    {
        srv_cbs_evt_init_op_ind_struct post_evt;
        U16 amount;
        U16 record_index;
        U8 *buffer;
        U16 buff_size;
        S16 error_code;
        S32 result;

        record_index = srv_cbs_get_page_record_index(
                            read_info->curr_index,
                            init_cntx->sim_id);

        if (read_info->remain > CBS_READ_PAGE_NUM)
        {
            amount = CBS_READ_PAGE_NUM;
            read_info->remain -= CBS_READ_PAGE_NUM;
        }
        else
        {
            amount = read_info->remain;
            read_info->remain = 0;
        }

        buff_size = sizeof(srv_cbs_page_struct) * amount;

        buffer = OslMalloc(buff_size);

        result = ReadMultiRecord(
                    NVRAM_EF_SRV_CBS_PAGE_LID,
                    record_index,
                    buffer,
                    buff_size,
                    amount,
                    &error_code);

        if (result >= 0)
        {
            U32 i;
            srv_cbs_page_struct *page_record;
            srv_cbs_page_node_struct *page_node;
            srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;

            srv_cbs_set_curr_cntx(init_cntx->sim_id);

            page_record = (srv_cbs_page_struct*)buffer;
            page_node = &srv_cbs_cntx->page_node[read_info->curr_index];

            for (i = 0; i < (U32)amount; i++)
            {
                page_node[i].next_page_id = page_record[i].next_page_id;
            }
            
            srv_cbs_set_curr_cntx(previous_sim_id );
        }

        read_info->curr_index += amount;

        OslMfree(buffer);

        MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_CBS_INIT_OP_IND);
        post_evt.init_cntx = init_cntx;
        MMI_FRM_POST_EVENT(&post_evt, srv_cbs_init_read_page_callback, NULL);
    }
    else
    {
        read_info->is_done = MMI_TRUE;

        srv_cbs_stroage_init_done_hdlr(init_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_read_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret srv_cbs_init_read_msg_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_evt_init_op_ind_struct *event_data = (srv_cbs_evt_init_op_ind_struct*)param;
    storage_init_cntx_struct *init_cntx = event_data->init_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_INIT_READ_MSG_CALLBACK);

    srv_cbs_init_read_msg_hdlr(init_cntx);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_read_page_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret srv_cbs_init_read_page_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_evt_init_op_ind_struct *event_data = (srv_cbs_evt_init_op_ind_struct*)param;
    storage_init_cntx_struct *init_cntx = event_data->init_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_INIT_READ_PAGE_CALLBACK);

    srv_cbs_init_read_page_hdlr(init_cntx);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_stroage_init_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cbs_stroage_init_done_hdlr(storage_init_cntx_struct *init_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_STARTUP_INIT_DONE_HDLR);

    if (init_cntx->msg_info.is_done && init_cntx->page_info.is_done)
    {
        srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;
        srv_cbs_set_curr_cntx(init_cntx->sim_id);

        if (srv_cbs_create_msg_list() == MMI_TRUE)
        {
            SrvSmsCallbackFunc callback_func = init_cntx->callback_func;
            void *user_data = init_cntx->user_data;

            OslMfree(init_cntx);

            srv_sms_succ_callback(
                SRV_SMS_ACTION_NONE,
                NULL,
                user_data,
                callback_func);
        }
        else
        {
            srv_cbs_reset_storage_data();

            init_cntx->msg_info.curr_index = 0;
            init_cntx->msg_info.remain = SRV_CBS_MAX_MSG_NUM;

            srv_cbs_init_reset_msg_hdlr(init_cntx);
        }
        srv_cbs_set_curr_cntx(previous_sim_id );
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_create_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cbs_create_msg_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_CREATE_MSG_LIST);

    for (i = 0; i < SRV_CBS_MAX_MSG_NUM; i++)
    {
        srv_cbs_msg_node_struct *msg_node = &srv_cbs_cntx->msg_node[i];
    
        if (srv_cbs_is_msg_mode_valid(msg_node) == MMI_TRUE)
        {
            U16 next_page_id = msg_node->start_page_id;
            U8 page_count = 0;
            srv_cbs_page_node_struct *page_node = srv_cbs_cntx->page_node;

            while ((next_page_id < SRV_CBS_MAX_PAGE_NUM) && 
                   (page_node[next_page_id].used_flag == MMI_FALSE))
            {
                /* If the next_page_id is used, it means there are more than
                 * one msg pointed to the same page */

                page_count++;

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_CREATE_MSG_LIST_1, next_page_id);

                next_page_id = page_node[next_page_id].next_page_id;
            }

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_CREATE_MSG_LIST_2, msg_node->page_num);

            if ((page_count == msg_node->page_num) &&
                (next_page_id == SRV_CBS_INVALID_PAGE_ID))
            {
                next_page_id = msg_node->start_page_id;

                do
                {
                    page_node[next_page_id].used_flag = MMI_TRUE;
                    next_page_id = page_node[next_page_id].next_page_id;
                } while (next_page_id < SRV_CBS_MAX_PAGE_NUM);

                srv_cbs_add_msg_into_list(i);
            }
            else
            {
                result = MMI_FALSE;
                break;
            }
        }
        else
        {
            srv_cbs_reset_msg_node(msg_node);
        }
    }

    if (result)
    {
        U16 count = 0;

        for (i = 0; i < SRV_CBS_MAX_PAGE_NUM; i++)
        {
            if (srv_cbs_cntx->page_node[i].used_flag)
            {
                count++;
            }
        }

        srv_cbs_cntx->used_page_num = count;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_read_msg_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_init_reset_msg_hdlr(storage_init_cntx_struct *init_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_op_multi_struct *write_info = &init_cntx->msg_info;
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_INIT_RESET_MSG_HDLR, write_info->remain);

    if (write_info->remain > 0)
    {
        srv_cbs_evt_init_op_ind_struct post_evt;
        U16 amount;
        U16 record_index;
        U32 i;
        S16 error_code;

        record_index = srv_cbs_get_msg_node_record_index(
                            write_info->curr_index,
                            init_cntx->sim_id);

        if (write_info->remain > CBS_WRITE_MSG_NODE_NUM)
        {
            amount = CBS_WRITE_MSG_NODE_NUM;
            write_info->remain -= CBS_WRITE_MSG_NODE_NUM;
        }
        else
        {
            amount = write_info->remain;
            write_info->remain = 0;
        }

        srv_cbs_set_curr_cntx(init_cntx->sim_id);

        for (i = 0; i < (U32)amount; i++)
        {
            U8 *buffer = (U8*)&srv_cbs_cntx->msg_node[write_info->curr_index];

            WriteRecord(
                NVRAM_EF_SRV_CBS_MSG_NODE_LID,
                record_index,
                buffer,
                sizeof(srv_cbs_msg_node_struct),
                &error_code);

            record_index++;
        }

        write_info->curr_index += amount;

        MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_CBS_INIT_OP_IND);
        post_evt.init_cntx = init_cntx;
        MMI_FRM_POST_EVENT(&post_evt, srv_cbs_init_reset_msg_callback, NULL);
    }
    else
    {
        SrvSmsCallbackFunc callback_func = init_cntx->callback_func;
        void *user_data = init_cntx->user_data;

        srv_cbs_set_curr_cntx(init_cntx->sim_id);

        srv_cbs_cntx->is_ready = MMI_TRUE;

        OslMfree(init_cntx);

        srv_sms_succ_callback(
            SRV_SMS_ACTION_NONE,
            NULL,
            user_data,
            callback_func);
    }
    
    srv_cbs_set_curr_cntx(previous_sim_id );
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_reset_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret srv_cbs_init_reset_msg_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_evt_init_op_ind_struct *event_data = (srv_cbs_evt_init_op_ind_struct*)param;
    storage_init_cntx_struct *init_cntx = event_data->init_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_INIT_RESET_MSG_CALLBACK);

    srv_cbs_init_reset_msg_hdlr(init_cntx);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_cbs_add_msg(
        srv_cbs_msg_node_struct *msg_node,
        U8 *msg_content,
        U32 msg_len,
        srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_add_msg_event_struct event_data;
    U16 msg_id;
    U8 total_page;
    U16 page_id_list[SRV_CBS_MAX_PAGE_PRE_MSG];
    U8 *real_msg_content = msg_content;
    U32 real_msg_len = msg_len;
    srv_sms_sim_enum previous_sim_id = srv_cbs_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_MSG);

    srv_cbs_set_curr_cntx(sim_id);

    total_page = srv_cbs_count_total_page(msg_len);

    msg_id = srv_cbs_get_unused_space(page_id_list, total_page);

    MMI_ASSERT(msg_id != SRV_SMS_INVALID_MSG_ID);

    msg_node->page_num = total_page;
    msg_node->start_page_id = page_id_list[0];

    srv_cbs_add_msg_content(
        real_msg_content,
        real_msg_len,
        msg_node->msg_dcs,
        page_id_list,
        total_page);

    srv_cbs_add_msg_node(msg_id, msg_node);

    MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_ADD_MSG);
    event_data.sim_id = sim_id;
    event_data.msg_id = msg_id;
    MMI_FRM_CB_EMIT_EVENT(&event_data);
    
    srv_cbs_set_curr_cntx(previous_sim_id );
    return msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_msg_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_add_msg_content(
                U8* msg_content,
                U32 msg_len,
                U8 msg_dcs,
                U16 page_id_list[],
                U8 total_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 remain_len = msg_len;
    U8 i = 0;
    U8 *page_content = msg_content;
    U8 *temp_content;
    U16 curr_page_id;
    U16 next_page_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_MSG_CONTENT, msg_len, msg_dcs, total_page);

    while (remain_len > SRV_CBS_PAGE_CONTENT_LEN)
    {
        curr_page_id = page_id_list[i];
        next_page_id = page_id_list[i + 1];

        srv_cbs_add_page(curr_page_id, page_content, next_page_id);

        page_content += SRV_CBS_PAGE_CONTENT_LEN;
        remain_len -= SRV_CBS_PAGE_CONTENT_LEN;

        i++;

        MMI_ASSERT(i < total_page);
    }

    temp_content = OslMalloc(SRV_CBS_PAGE_CONTENT_LEN);

    memcpy(temp_content, page_content, remain_len);

    switch (msg_dcs)
    {
        case SRV_SMS_DCS_7BIT:
        case SRV_SMS_DCS_RESERVED:
            memset(
                temp_content + remain_len,
                0x0D,
                SRV_CBS_PAGE_CONTENT_LEN - remain_len);
            break;

        case SMSAL_8BIT_DCS:
        case SMSAL_UCS2_DCS:
            memset(
                temp_content + remain_len,
                0x00,
                SRV_CBS_PAGE_CONTENT_LEN - remain_len);
            break;
    }

    curr_page_id = page_id_list[i];

    srv_cbs_add_page(curr_page_id, temp_content, SRV_CBS_INVALID_PAGE_ID);

    OslMfree(temp_content);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_is_msg_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cbs_is_msg_valid(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((msg_id < SRV_CBS_MAX_MSG_NUM) &&
        (srv_cbs_cntx->msg_node[msg_id].page_num > 0))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_IS_MSG_VALID, msg_id, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_delete_msg_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cbs_delete_msg_int(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DELETE_MSG_INT, msg_id);

    if (srv_cbs_is_msg_valid(msg_id) == MMI_TRUE)
    {
        srv_cbs_del_msg_event_struct event_data;
        U16 page_id_list[SRV_CBS_MAX_PAGE_PRE_MSG];
        U8 total_page;
        U8 i;

        total_page = srv_cbs_get_msg_page_id(msg_id, page_id_list);

        for (i = 0; i < total_page; i++)
        {
            srv_cbs_del_page(page_id_list[i]);
        }

        srv_cbs_del_msg_node(msg_id);

        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_DEL_MSG);
        event_data.sim_id = CBS_CURR_SIM_ID;
        event_data.msg_id = msg_id;
        MMI_FRM_CB_EMIT_EVENT(&event_data);
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}





/*****************************************************************************
 * FUNCTION
 *  srv_cbs_is_msg_mode_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cbs_is_msg_mode_valid(srv_cbs_msg_node_struct* msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_IS_MSG_MODE_VALID, msg_node->page_num, msg_node->start_page_id);

    if (((msg_node->page_num > 0) && (msg_node->page_num <= SRV_CBS_MAX_PAGE_PRE_MSG)) &&
        (msg_node->start_page_id < SRV_CBS_MAX_PAGE_NUM))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_add_msg_node(U16 msg_id, srv_cbs_msg_node_struct* msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_MSG_NODE, msg_id);

    MMI_ASSERT(msg_id < SRV_CBS_MAX_MSG_NUM);

    memcpy(&srv_cbs_cntx->msg_node[msg_id], msg_node, sizeof(srv_cbs_msg_node_struct));

    srv_cbs_write_msg_node_record(msg_id, msg_node);

    srv_cbs_add_msg_into_list(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_del_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_del_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_msg_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DEL_MSG_NODE, msg_id);

    MMI_ASSERT(msg_id < SRV_CBS_MAX_MSG_NUM);

    msg_node = &srv_cbs_cntx->msg_node[msg_id];

    srv_cbs_reset_msg_node(msg_node);

    srv_cbs_write_msg_node_record(msg_id, msg_node);

    srv_cbs_del_msg_from_list(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_reset_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_reset_msg_node(srv_cbs_msg_node_struct* msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_node->page_num = 0;
    msg_node->msg_dcs = SRV_CBS_UNUSED_DCS;
    msg_node->mi = SRV_CBS_UNUSED_CBMI;
    msg_node->timestamp = 0;
    msg_node->start_page_id = SRV_CBS_INVALID_PAGE_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_msg_into_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_add_msg_into_list(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp;
    U32 list_size = srv_cbs_cntx->msg_list_size;
    U16 *msg_list = srv_cbs_cntx->msg_list;
    U32 i;
    U32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_MSG_INTO_LIST, msg_id, list_size);

    MMI_ASSERT(msg_id < SRV_CBS_MAX_MSG_NUM);
    MMI_ASSERT(srv_cbs_cntx->msg_list_size < SRV_CBS_MAX_MSG_NUM);

    timestamp = srv_cbs_cntx->msg_node[msg_id].timestamp;

    for (i = 0; i < list_size; i++)
    {
        U16 cmp_msg_id = msg_list[i];
        U32 cmp_timestamp = srv_cbs_cntx->msg_node[cmp_msg_id].timestamp;

        if (timestamp >= cmp_timestamp)
        {
            break;
        }
    }

    for (j = list_size; j > i; j--)
    {
        msg_list[j] = msg_list[j - 1];
    }

    msg_list[i] = msg_id;

    srv_cbs_cntx->msg_list_size++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_del_msg_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_del_msg_from_list(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 list_size = srv_cbs_cntx->msg_list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DEL_MSG_FROM_LIST, msg_id, list_size);

    if (list_size > 0)
    {
        U32 i;
        U16 *msg_list = srv_cbs_cntx->msg_list;

        for (i = 0; i < list_size; i++)
        {
            if (msg_list[i] == msg_id)
            {
                U32 j;

                for (j = i; j < (list_size - 1); j++)
                {
                    msg_list[j] = msg_list[j + 1];
                }

                msg_list[list_size - 1] = SRV_CBS_INVALID_MSG_ID;

                srv_cbs_cntx->msg_list_size--;
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_unused_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_cbs_get_unused_msg_id(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    U16 unused_msg_id = SRV_CBS_INVALID_MSG_ID;
    U8 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CBS_MAX_MSG_NUM; i++)
    {
        if (srv_cbs_cntx->msg_node[i].page_num == 0)
        {
            unused_msg_id = i;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_UNUSED_MSG_ID, unused_msg_id);

    return unused_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_unused_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_cbs_get_unused_space(U16 page_id_list[], U8 total_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_msg_id = SRV_CBS_INVALID_MSG_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_UNUSED_SPACE);

    do
    {
        MMI_BOOL del_result;
        U16 oldest_msg_id;
        U32 list_size = srv_cbs_cntx->msg_list_size;
        U16 *msg_list = srv_cbs_cntx->msg_list;

        MMI_BOOL result;

        result = srv_cbs_get_unused_page_id(page_id_list, total_page);

        if (result == MMI_TRUE)
        {
            unused_msg_id = srv_cbs_get_unused_msg_id();

            if (unused_msg_id == SRV_CBS_INVALID_MSG_ID)
            {
                MMI_ASSERT(list_size > 0);

                oldest_msg_id = msg_list[list_size - 1];
        
                del_result = srv_cbs_delete_msg_int(oldest_msg_id);

                MMI_ASSERT(del_result == MMI_TRUE);

                unused_msg_id = oldest_msg_id;
            }
            break;
        }
        else
        {
            MMI_ASSERT(list_size > 0);
        
            oldest_msg_id = msg_list[list_size - 1];
        
            del_result = srv_cbs_delete_msg_int(oldest_msg_id);

            MMI_ASSERT(del_result == MMI_TRUE);
        }
    } while (1);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_UNUSED_SPACE_1, unused_msg_id);

    return unused_msg_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_count_total_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_cbs_count_total_page(U32 msg_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (msg_len == 0)
    {
        total_page = 1;
    }
    else
    {
        total_page = (msg_len + SRV_CBS_PAGE_CONTENT_LEN - 1) / SRV_CBS_PAGE_CONTENT_LEN;

        if (total_page > SRV_CBS_MAX_PAGE_PRE_MSG)
        {
            total_page = SRV_CBS_MAX_PAGE_PRE_MSG;
        }
    }

    return total_page;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_page_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_cbs_get_msg_page_id(U16 msg_id, U16 page_id_list[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U16 next_page_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_ASSERT(msg_id < SRV_CBS_MAX_MSG_NUM);

    next_page_id = srv_cbs_cntx->msg_node[msg_id].start_page_id;

    while (next_page_id != SRV_CBS_INVALID_PAGE_ID)
    {
        MMI_ASSERT(count < SRV_CBS_MAX_PAGE_PRE_MSG);

        page_id_list[count++] = next_page_id;
        next_page_id = srv_cbs_cntx->page_node[next_page_id].next_page_id;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_MSG_PAGE_ID, msg_id, count);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_add_page(U16 page_id, U8* page_content, U16 next_page_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_page_struct page_data;
    U16 record_index;
    S16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_PAGE, page_id, next_page_id);

    page_data.next_page_id = next_page_id;
    memcpy(page_data.content, page_content, SRV_CBS_PAGE_CONTENT_LEN);

    record_index = srv_cbs_get_page_record_index(page_id, CBS_CURR_SIM_ID);

    WriteRecord(
        NVRAM_EF_SRV_CBS_PAGE_LID,
        record_index,
        &page_data,
        sizeof(srv_cbs_page_struct),
        &error_code);
    
    srv_cbs_cntx->page_node[page_id].used_flag = MMI_TRUE;
    srv_cbs_cntx->page_node[page_id].next_page_id = next_page_id;

    srv_cbs_cntx->used_page_num++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_del_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_del_page(U16 page_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DEL_PAGE, page_id);

    MMI_ASSERT(page_id < SRV_CBS_MAX_PAGE_NUM);

    if (srv_cbs_cntx->page_node[page_id].used_flag == MMI_TRUE)
    {
        srv_cbs_cntx->page_node[page_id].used_flag = MMI_FALSE;
        srv_cbs_cntx->page_node[page_id].next_page_id = SRV_CBS_INVALID_PAGE_ID;

        srv_cbs_cntx->used_page_num--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_read_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_read_page(U16 page_id, srv_cbs_page_struct* page_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index;
    S16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_READ_PAGE, page_id);

    record_index = srv_cbs_get_page_record_index(page_id, CBS_CURR_SIM_ID);

    ReadRecord(
        NVRAM_EF_SRV_CBS_PAGE_LID,
        record_index,
        page_data,
        sizeof(srv_cbs_page_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_unused_page_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cbs_get_unused_page_id(U16 page_id_list[], U8 total_page)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_UNUSED_PAGE_ID, total_page);

    if (total_page > (SRV_CBS_MAX_PAGE_NUM - srv_cbs_cntx->used_page_num))
    {
        result = MMI_FALSE;
    }
    else
    {
        U8 count = 0;
        U8 i = 0;

        while ((i < SRV_CBS_MAX_PAGE_NUM) && (count < total_page))
        {
            if (srv_cbs_cntx->page_node[i].used_flag == MMI_FALSE)
            {
                page_id_list[count++] = i;
            }

            i++;
        }

        MMI_ASSERT(count == total_page);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_decode_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_cbs_lang_enum srv_cbs_decode_lang(U8 char1, U8 char2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_lang_enum lang_type = SRV_CBS_LANG_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DECODE_LANG, char1, char2);

	if ((char1 == '?') && (char2 == '?'))
	{
		return SRV_CBS_LANG_2_OTHER;
	}

    lang_type = SRV_CBS_LANG_INVALID;

    switch (char1)
    {
        case 'a':
            switch (char2)
            {
                case 'r':
                    lang_type = SRV_CBS_LANG_2_AR;
                    break;
            }
            break;
            
    
        case 'c':
            switch (char2)
            {
                case 's':
                    lang_type = SRV_CBS_LANG_2_CS;
                    break;
            }
            break;
        case 'd':
            switch (char2)
            {
                case 'a':
                    lang_type = SRV_CBS_LANG_2_DA;
                    break;
                case 'e':
                    lang_type = SRV_CBS_LANG_2_DE;
                    break;
            }
            break;
        case 'e':
            switch (char2)
            {
                case 'l':
                    lang_type = SRV_CBS_LANG_2_EL;
                    break;
                case 'n':
                    lang_type = SRV_CBS_LANG_2_EN;
                    break;
                case 's':
                    lang_type = SRV_CBS_LANG_2_ES;
                    break;
            }
            break;
        case 'f':
            switch (char2)
            {
                case 'r':
                    lang_type = SRV_CBS_LANG_2_FR;
                    break;
                case 'i':
                    lang_type = SRV_CBS_LANG_2_FI;
                    break;
            }
            break;
        
        case 'h':
            switch (char2)
            {
                case 'e':
                    lang_type = SRV_CBS_LANG_2_HE;
                    break;
                case 'u':
                    lang_type = SRV_CBS_LANG_2_HU;
                    break;
            }
            break;
        case 'i':
            switch (char2)
            {
                case 's':
                    lang_type = SRV_CBS_LANG_2_IS;
                    break;
                case 't':
                    lang_type = SRV_CBS_LANG_2_IT;
                    break;
             }
            break;

        case 'n':
            switch (char2)
            {
                case 'l':
                    lang_type = SRV_CBS_LANG_2_NL;
                    break;
                case 'o':
                    lang_type = SRV_CBS_LANG_2_NO;
                    break;
            }
            break;
        case 'p':
            switch (char2)
            {
                case 'l':
                    lang_type = SRV_CBS_LANG_2_PL;
                    break;
                case 't':
                    lang_type = SRV_CBS_LANG_2_PT;
                    break;
            }
            break;
        case 'r':
            switch (char2)
            {
                case 'u':
                    lang_type = SRV_CBS_LANG_2_RU;
                    break;
            }
            break;
        case 's':
            switch (char2)
            {
                case 'v':
                    lang_type = SRV_CBS_LANG_2_SV;
                    break;
            }
            break;
        case 't':
            switch (char2)
            {
                case 'r':
                    lang_type = SRV_CBS_LANG_2_TR;
                    break;
            }
            break;
    }

    return lang_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_decode_dcs
 * DESCRIPTION
 *  Decode Cb DCS
 * PARAMETERS
 *
 * RETURNS
 *  skip character
 *****************************************************************************/
U32 srv_cbs_decode_dcs(
        U8 dcs,
        U8* msg_content,
        U32 msg_len,
        srv_cbs_lang_enum* lang_type,
        srv_sms_dcs_enum* msg_dcs,
        srv_sms_class_enum *msg_class,
        MMI_BOOL* is_compress,
        MMI_BOOL* is_reserved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 coding_group = (dcs >> 4);
    U8 coding_bits = (dcs & 0x0f);
    U32 skip_char = 0;
    U8 char1;
    U8 char2;
    U8 char3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DECODE_DCS, dcs);

    *lang_type = SRV_CBS_LANG_0_UNSPECIFIED;
    *msg_dcs = SRV_SMS_DCS_7BIT;
    *msg_class = SRV_SMS_CLASS_UNSPECIFIED;

    *is_compress = MMI_FALSE;
    *is_reserved = MMI_FALSE;

    switch (coding_group)
    {
        case 0x00:
            *lang_type = (srv_cbs_lang_enum)coding_bits;
            break;

        case 0x01:
            /* 
             * GSM7: PS side already unpack 
             * UCS2: PS side didn't unpack 
             */
            if (coding_bits == 0)   /* GSM7 */
            {
                if (msg_len >= 3)
                {
                    char1 = msg_content[0];
                    char2 = msg_content[1];
                    char3 = msg_content[2];

                    if (char3 == 0x0d)  /* CR */
                    { 
                        *lang_type = srv_cbs_decode_lang(char1, char2);
                        skip_char = 3;
                    }
                }
                else
                {
                    skip_char = msg_len;
                }
            }
            else if (coding_bits == 1)  /* UCS2 */
            {
                if (msg_len >= 2)
                {
                    char1 = msg_content[0];
                    char2 = msg_content[1];

                    *msg_dcs = SRV_SMS_DCS_UCS2;
                    *lang_type = srv_cbs_decode_lang((U8)(char1 & 0x7f), (U8)(((char2 & 0x3f) << 1) | ((char1 & 0x80) >> 7)));
                    skip_char = 2;
                }
                else
                {
                    skip_char = msg_len;
                }
            }
            /* MTK end */
            else
            {
                *is_reserved = MMI_TRUE;
            }
            break;
        case 0x02:
            if (coding_bits < 0x05)
            {
                *lang_type = (srv_cbs_lang_enum)(16 + coding_bits);
            }
            else
            {
                *is_reserved = MMI_TRUE;
            }
            break;

        case 0x03:
            *is_reserved = MMI_TRUE;
            break;

        case 0x04:  /* General Data Coding Scheme */
        case 0x05:
        case 0x06:
        case 0x07:
            if ((coding_group & 0x02) != 0)
            {
                *is_compress = MMI_TRUE;
            }
            if ((coding_group & 0x01) == 0x01)
            {
                *msg_class = (srv_sms_class_enum)(dcs & 0x03);
            }

            *msg_dcs = (srv_sms_dcs_enum)(dcs & 0x0C);
            break;

        case 0x08:  /* Reserved */
            *is_reserved = MMI_TRUE;
            break;

        case 0x09:  /* Message with User Data Header (UDH) structure */
            *msg_class = (srv_sms_class_enum)(dcs & 0x03);
            *msg_dcs = (srv_sms_dcs_enum)(dcs & 0x0C);
            break;

        case 0x0a:  /* 0x0a - 0x0d: Reserved */
        case 0x0b:
        case 0x0c:
        case 0x0d:
            *is_reserved = MMI_TRUE;
            break;

        case 0x0e:  /* defined by WAP forum */
            break;

        case 0x0f:  /* Data Coding/Message Class */
            *msg_dcs = (srv_sms_dcs_enum) (dcs & 0x04);

            /* If bit0-1 is 0, No message class*/
            if ((dcs & 0x03) > 0)
            {
                *msg_class = (srv_sms_class_enum) (dcs & 0x03);
            }
            break;

        default:
            break;
    }

    return skip_char;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_convert_content_for_display
 * DESCRIPTION
 *  Convert CB message for display, according to its DCS
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cbs_convert_content_for_display(
        WCHAR *out_data,
        U32*real_out_len,
        U32 out_data_len,
        U8 *in_data,
        U32 in_data_size,
        srv_sms_dcs_enum msg_dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tmp_out_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_CONVERT_CONTENT_FOR_DISPLAY, in_data_size, msg_dcs);

    if (in_data_size > 0)
    {
        U32 skip_char_num;

        switch (msg_dcs)
        {
            case SRV_SMS_DCS_8BIT:
            {
                if (out_data_len < in_data_size)
                {
                    tmp_out_len = out_data_len;
                }
                else
                {
                    tmp_out_len = in_data_size;
                }

                mmi_asc_n_to_wcs(out_data, (CHAR*)in_data, tmp_out_len);
                break;
            }

            case SRV_SMS_DCS_UCS2:
            {
                WCHAR *ucs2_out_data = out_data;
                WCHAR *ucs2_in_data = (WCHAR*)in_data;
                U32 tmp_in_len = in_data_size / ENCODING_LENGTH;
                U32 i;

                if (out_data_len < tmp_in_len)
                {
                    tmp_out_len = out_data_len;
                }
                else
                {
                    tmp_out_len = tmp_in_len;
                }

                /* If the DCS is UCS2, the content from Network (Protocol Stack) is Big-Endian;
                 *  ex. For 'a' --> 0x00 0x61   (0x6100)
                 * But in the target or Modis, it is Little-Endian, need to swap.
                 *  ex. For 'a' --> 0x61 0x00   (0x0061)
                 */
                for (i = 0; i < tmp_out_len; i++)
                {
                    *ucs2_out_data = *(WCHAR*)SwapEndian((void*)ucs2_in_data, sizeof(WCHAR));
                    ucs2_out_data++;
                    ucs2_in_data++;
                }
                break;
            }

            case SRV_SMS_DCS_7BIT:
            default:
            {
                U32 tmp_in_size;
            #ifdef __SMS_R8_NATION_LANGUAGE__
                EMSNationalLanguage old_l, new_l;
            #endif /* __SMS_R8_NATION_LANGUAGE__ */

            #ifdef __SMS_R8_NATION_LANGUAGE__
                new_l.locking_shift = EMS_NL_DEFAULT;
                new_l.single_shift = EMS_NL_DEFAULT;

                mmi_7bit_get_national_lang_table(&old_l);
                mmi_7bit_set_national_lang_table(&new_l);
            #endif /* __SMS_R8_NATION_LANGUAGE__ */

                if (out_data_len < in_data_size)
                {
                    tmp_in_size = out_data_len;
                }
                else
                {
                    tmp_in_size = in_data_size;
                }

                tmp_out_len = tmp_in_size + 1;

                mmi_7bit_gsm_to_ucs2_string(
                    in_data,
                    (U8*)out_data,
                    tmp_in_size,
                    &tmp_out_len,
                    0x20,
                    NULL,
                    0);

            #ifdef __SMS_R8_NATION_LANGUAGE__
                mmi_7bit_set_national_lang_table(&old_l);
            #endif /* __SMS_R8_NATION_LANGUAGE__ */
                break;
            }
        }

        skip_char_num = srv_cbs_remove_fill_bit(out_data, tmp_out_len);

        tmp_out_len -= skip_char_num;

        out_data[tmp_out_len] = '\0';
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_CONVERT_CONTENT_FOR_DISPLAY_1, tmp_out_len);

    if (real_out_len)
    {
        *real_out_len = tmp_out_len;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_cb_remove_fill_bit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_cbs_remove_fill_bit(WCHAR* buffer, U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	WCHAR* in = (U16*)buffer;
	WCHAR* out = (U16*)buffer;
	WCHAR curr_char = *in;
	WCHAR pre_char = '\0';
	U32 len = buff_len;
	U32 skip_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_REMOVE_FILL_BIT);

	while ((curr_char != '\0') && (len > 0))
   	{	
   		//If Only save a CR ('\n') char
		if ((pre_char == 0x0D) && (curr_char == 0x0D))
		{
			skip_count++;
		}
		else
		{
			*out = *in;
			out++;
		}

		in++;
		len--;
		
		pre_char = curr_char;
		curr_char = *in;
	}

    return skip_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_write_msg_node_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_write_msg_node_record(U16 msg_id, srv_cbs_msg_node_struct* msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index;
    S16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_WRITE_MSG_NODE_RECORD, msg_id);

    record_index = srv_cbs_get_msg_node_record_index(msg_id, CBS_CURR_SIM_ID);

    WriteRecord(
        NVRAM_EF_SRV_CBS_MSG_NODE_LID,
        record_index,
        msg_node,
        sizeof(srv_cbs_msg_node_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_reset_storage_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_set_curr_cntx(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx = srv_cbs_get_cntx(sim_id);
    srv_cbs_sim_id = sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_reset_storage_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_reset_storage_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_RESET_STORAGE_DATA);

    for (i = 0; i < SRV_CBS_MAX_MSG_NUM; i++)
    {
        srv_cbs_msg_node_struct *msg_node = &srv_cbs_cntx->msg_node[i];
    
        srv_cbs_reset_msg_node(msg_node);
    }

    for (i = 0; i < SRV_CBS_MAX_PAGE_NUM; i++)
    {
        srv_cbs_page_node_struct *page_node = &srv_cbs_cntx->page_node[i];

        page_node->used_flag = MMI_FALSE;
    }

    memset(srv_cbs_cntx->msg_list, SRV_CBS_INVALID_MSG_ID, sizeof(U16) * SRV_CBS_MAX_MSG_NUM);
    srv_cbs_cntx->msg_list_size = 0;
    srv_cbs_cntx->used_page_num = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_node_record_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_cbs_get_msg_node_record_index(U16 msg_id, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = msg_id + 1;
#ifdef __SRV_SMS_MULTI_SIM__
    U32 index;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    for (i = 0; i < index; i++)
    {
        record_index += SRV_CBS_MAX_MSG_NUM;
    }
#endif /* __SRV_SMS_MULTI_SIM__ */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_MSG_NODE_RECORD_INDEX, msg_id, sim_id);

    return record_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_page_record_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_cbs_get_page_record_index(U16 page_id, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = page_id + 1;
#ifdef __SRV_SMS_MULTI_SIM__
    U32 index;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    for (i = 0; i < index; i++)
    {
        record_index += SRV_CBS_MAX_PAGE_NUM;
    }
#endif /* __SRV_SMS_MULTI_SIM__ */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_PAGE_RECORD_INDEX, page_id, sim_id);

    return record_index;
}
#endif /* __MOD_SMSAL__ */
#endif /*__SRV_CBS_SUPPORT__*/
