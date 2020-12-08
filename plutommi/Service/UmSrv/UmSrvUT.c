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
 * UMSrvMain.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"

/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
#include "UmSrvGprot.h"
#include "UmSrvprot.h"
#include "app_str.h"
#include "app_buff_alloc.h"

#ifdef __SRV_UM_UT__

/*****************************************************************************
 * FUNCTION
 *  srv_um_send_message
 * DESCRIPTION
 *  Send message
 * PARAMETERS
 *  msg_type            [IN]    message type
 *  msg_id              [IN]    message id
 *  local_para_ptr      [IN]    local parameter
 *  peer_buff_ptr       [IN]    peer buffer
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_ut_send_message(module_type dest_module, S32 msg_id, void *local_para_ptr, void *peer_buff_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = stack_get_active_module_id();
    Message.oslDestId = dest_module;
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = (local_para_struct*) local_para_ptr;
    Message.oslPeerBuffPtr = (peer_buff_struct*) peer_buff_ptr;

    switch (Message.oslDestId)
    {
        case MOD_WPS:
            Message.oslSapId = WPS_APP_SAP;
            break;
        case MOD_MMI:
            Message.oslSapId = MMI_MMI_SAP;
            break;
        case MOD_MMS:
            Message.oslSapId = MMI_WAP_SAP;
        default:
            Message.oslSapId = INVALID_SAP;
            break;
    }

    OslMsgSendExtQueue(&Message);
}

#define SRV_UM_UT_INBOX_UNREAD_MSG_NUMBER 2
#define SRV_UM_UT_INBOX_READ_MSG_NUMBER 3
#define SRV_UM_UT_INBOX_MSG_NUMBER (SRV_UM_UT_INBOX_UNREAD_MSG_NUMBER + SRV_UM_UT_INBOX_READ_MSG_NUMBER)
#define SRV_UM_UT_UNSENT_MSG_NUMBER 0
#define SRV_UM_UT_SENT_MSG_NUMBER 5
#define SRV_UM_UT_DEAFT_MSG_NUMBER 0
#define SRV_UM_UT_REPORT_MSG_NUMBER 0
#define SRV_UM_UT_TOTAL_MSG_NUMBER (SRV_UM_UT_INBOX_MSG_NUMBER + SRV_UM_UT_UNSENT_MSG_NUMBER + SRV_UM_UT_SENT_MSG_NUMBER + SRV_UM_UT_DEAFT_MSG_NUMBER + SRV_UM_UT_REPORT_MSG_NUMBER)

static kal_uint32 ut_timestamp[SRV_UM_UT_TOTAL_MSG_NUMBER] =
{
    10000000, 9999999, 9999998, 9999997,
     9999996, 9999995, 9999994, 9999993,
     9999992, 9999991
};

static kal_bool ut_read_status[SRV_UM_UT_TOTAL_MSG_NUMBER] =
{
    KAL_TRUE, KAL_FALSE, KAL_TRUE, KAL_FALSE,
    KAL_TRUE, KAL_FALSE, KAL_TRUE, KAL_FALSE,
    KAL_TRUE, KAL_FALSE
};

static kal_uint32 ut_msg_size[SRV_UM_UT_TOTAL_MSG_NUMBER] =
{
    100, 98,  23, 56,
     78, 66,  85, 24,
     05, 33
};

static kal_wchar ut_subject[SRV_UM_UT_TOTAL_MSG_NUMBER][SRV_UM_MAX_SUBJECT_LEN] =
{
    L"Subject 1 aaaaabbbbb",    //100   93 92 91
    L"Subject 1 aaaaaccccc",    //99    98 100 99 97 96 95 94
    L"Subject 1 aaaaaaaaaa",    //98
    L"Subject 1 bbbbb",         //97
    L"Subject 1 ccccc",         //96
    L"Subject 1 ddddd",         //95
    L"Subject 1 eeeee",         //94
    L"Subject 1 11111",         //93
    L"Subject 1 22222",         //92
    L"Subject 1 @@@@@"          //91
};

static kal_wchar ut_address[SRV_UM_UT_TOTAL_MSG_NUMBER][3][SRV_UM_MAX_ADDR_LEN] =
{
    {L"0915715470",        L"0915715470",       L"0915715470"       },        //100   fuu             95 91 94 92
    {L"+886915715470",     L"+886915715470",    L"+886915715470"    },        //99    fuu             100 99 96 93 98 97
    {L"0226309980",        L"0226309980",       L"0226309980"       },        //98    pjack
    {L"26309980",          L"26309980",         L"26309980"	        },        //97    pjack
    {L"26598088",          L"26598088",         L"26598088"         },        //96    mediatek
    {L"09123456789",       L"09123456789",      L"09123456789"      },        //95    09123
    {L"09987654321",       L"09987654321",      L"09987654321"      },        //94    09987
    {L"26598088p123",      L"26598088p123",     L"0915715470"       },        //93    mediatek
    {L"26598088e456",      L"0915715470",       L"26598088e456"     },        //92    26598
    {L"0939241958",        L"0939241958",       L"0939241958"       }         //91    09392
};


/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void *srv_um_ut_alloc(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return get_ctrl_buffer(size);
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void srv_um_ut_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_ctrl_buffer(p);
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
MMI_BOOL srv_um_ut_recv_get_msg_num_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_num_req_struct *req = (srv_um_get_msg_num_req_struct*) inMsg;
    srv_um_get_msg_num_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (req->msg_type != SRV_UM_MSG_UT)
    {
        return MMI_FALSE;
    }

    rsp = (srv_um_get_msg_num_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_num_rsp_struct));

    rsp->app_id = 0;
    rsp->msg_type = SRV_UM_MSG_UT;
    rsp->result = KAL_TRUE;
    rsp->inbox_unread_msg_number = SRV_UM_UT_INBOX_UNREAD_MSG_NUMBER;
    rsp->inbox_read_msg_number = SRV_UM_UT_INBOX_READ_MSG_NUMBER;
    rsp->unsent_msg_number = SRV_UM_UT_UNSENT_MSG_NUMBER;
    rsp->sent_msg_number = SRV_UM_UT_SENT_MSG_NUMBER;
    rsp->draft_msg_number = SRV_UM_UT_DEAFT_MSG_NUMBER;
    rsp->report_msg_number = SRV_UM_UT_REPORT_MSG_NUMBER;

    srv_um_ut_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_NUM_RSP, rsp, NULL);


	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
MMI_BOOL srv_um_ut_recv_get_msg_list_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_list_req_struct *req = (srv_um_get_msg_list_req_struct*) inMsg;
    srv_um_get_msg_list_rsp_struct *rsp;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (req->msg_type != SRV_UM_MSG_UT)
    {
        return MMI_FALSE;
    }

    rsp = (srv_um_get_msg_list_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_list_rsp_struct));

    rsp->app_id = 0;
    rsp->msg_type = SRV_UM_MSG_UT;
    rsp->result = KAL_TRUE;
    rsp->msg_box_type = req->msg_box_type;
    rsp->start_entry = req->start_entry;

    if (SRV_UM_MAX_GET_MSG_LIST_NUMBER > SRV_UM_UT_TOTAL_MSG_NUMBER - req->start_entry)
    {
        rsp->msg_number = SRV_UM_UT_TOTAL_MSG_NUMBER - req->start_entry;
        rsp->more = KAL_FALSE;
    }
    else
    {
        rsp->msg_number = SRV_UM_MAX_GET_MSG_LIST_NUMBER;
        rsp->more = KAL_TRUE;
    }

    for (i = 0; i < rsp->msg_number ; i++)
    {
        rsp->list_info[i].msg_id = req->start_entry + i + 1;
        rsp->list_info[i].timestamp = ut_timestamp[req->start_entry + i];
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
        switch (req->list_idx_type)
        {
        case SRV_UM_LIST_IDX_TIMESTAMP:
            rsp->list_idx_data[i].timestamp = ut_timestamp[req->start_entry + i];
            break;
        case SRV_UM_LIST_IDX_ADDRESS:
            app_ucs2_strncpy((kal_int8*)rsp->list_idx_data[i].address, (kal_int8*)ut_address[req->start_entry + i][0], SRV_UM_MAX_LIST_INDEX_LEN);
            break;
        case SRV_UM_LIST_IDX_SUBJECT:
            app_ucs2_strncpy((kal_int8*)rsp->list_idx_data[i].subject, (kal_int8*)ut_subject[req->start_entry + i][0], SRV_UM_MAX_LIST_INDEX_LEN);
            break;
        case SRV_UM_LIST_IDX_READ_STATUS:
            rsp->list_idx_data[i].read_status = ut_read_status[req->start_entry + i];
            break;
        case SRV_UM_LIST_IDX_MSG_TYPE:
            rsp->list_idx_data[i].msg_type = SRV_UM_MSG_UT;
            break;
        case SRV_UM_LIST_IDX_MSG_SIZE:
            rsp->list_idx_data[i].msg_size = ut_msg_size[req->start_entry + i];
            break;
        default:
            ASSERT(0);
        }
#endif
    }

    srv_um_ut_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_LIST_RSP, rsp, NULL);

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
MMI_BOOL srv_um_ut_recv_get_msg_info_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *req = (srv_um_get_msg_info_req_struct*) inMsg;
    srv_um_get_msg_info_rsp_struct *rsp;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (req->msg_type != SRV_UM_MSG_UT)
    {
        return MMI_FALSE;
    }

    rsp = (srv_um_get_msg_info_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_info_rsp_struct));

    rsp->app_id = 0;
    rsp->msg_type = SRV_UM_MSG_UT;
    rsp->msg_box_type = req->msg_box_type;
    rsp->msg_number = req->msg_number;

    for(i = 0 ; i < req->msg_number; i++)
    {
        rsp->msg_id[i] = req->msg_id[i];

        if (req->msg_id[i] == 0 || req->msg_id[i] > SRV_UM_UT_TOTAL_MSG_NUMBER)
        {
            rsp->result[i] = KAL_FALSE;
        }
        else
        {
            srv_um_msg_info_struct *msg_info = &rsp->msg_info[i];
            S32 index = req->msg_id[i] - 1;

            rsp->result[i] = KAL_TRUE;

            msg_info->msg_id = req->msg_id[i];
            msg_info->timestamp = ut_timestamp[index];
            msg_info->address_type = SRV_UM_ADDR_PHONE_NUMBER;
            msg_info->address_length = app_ucs2_strlen((kal_int8*)ut_address[index][0]);
            app_ucs2_strncpy((kal_int8*)msg_info->address, (kal_int8*)ut_address[index][0], SRV_UM_MAX_ADDR_LEN);
            msg_info->subject_length = app_ucs2_strlen((kal_int8*)ut_subject[index]);
            app_ucs2_strncpy((kal_int8*)msg_info->subject, (kal_int8*)ut_subject[index], SRV_UM_MAX_SUBJECT_LEN);
        }
    }

    srv_um_ut_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, rsp, NULL);

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
MMI_BOOL srv_um_ut_recv_mark_several_op_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_req_struct *req = (srv_um_mark_several_op_req_struct*) inMsg;
    srv_um_mark_several_op_rsp_struct *rsp;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    rsp = (srv_um_mark_several_op_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_mark_several_op_rsp_struct));

    rsp->app_id = 0;
    rsp->msg_type = SRV_UM_MSG_UT;
    rsp->msg_box_type = req->msg_box_type;
    rsp->action_type = req->action_type;
    rsp->msg_number = req->msg_number;

    switch(req->action_type)
    {
    case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
    case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE:
    case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM:
    case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE:
    case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM:
    case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE:
        {
            for( i = 0 ; i < req->msg_number; i++)
            {
                if (req->msg_id[i] == 0 || req->msg_id[i] > SRV_UM_UT_TOTAL_MSG_NUMBER)
                {
                    rsp->msg_id[i] = 0;
                    rsp->action_result[i] = KAL_FALSE;
                }
                else
                {
                    app_ucs2_strcpy((kal_int8*)ut_subject[req->msg_id[i] - 1], (kal_int8*)L"Marked");
                    rsp->msg_id[i] = req->msg_id[i];
                    rsp->action_result[i] = KAL_TRUE;
                }
            }
        }
    }

    srv_um_ut_send_message(MOD_MMI, MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP, rsp, NULL);

    return MMI_TRUE;


}


/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void srv_um_ut_fill_in_data(kal_int32 index, srv_um_detail_field_enum field, srv_um_msg_box_enum msg_box_type, srv_um_msg_detail_struct *msg_detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(msg_detail, 0, sizeof(srv_um_msg_detail_struct));

    msg_detail->msg_type = SRV_UM_MSG_UT;
    msg_detail->msg_id = index + 1;

    if (field & SRV_UM_DETAIL_MSG_BOX)
    {
        msg_detail->msg_box_type = msg_box_type;
    }

    if (field & SRV_UM_DETAIL_TIMESTAMP)
    {
        msg_detail->timestamp = ut_timestamp[index];
    }

    if (field & SRV_UM_DETAIL_READ_STATUS)
    {
        msg_detail->read_status = ut_read_status[index];
    }

    if (field & SRV_UM_DETAIL_MSG_SIZE)
    {
        msg_detail->msg_size = ut_msg_size[index];
    }

    if (field & SRV_UM_DETAIL_SUBJECT)
    {
        msg_detail->subject = ut_subject[index];
    }

    if (field & SRV_UM_DETAIL_MULTI_ADDRESS)
    {
        for (i = 0 ;i < 3;i++)
        {
            if (msg_box_type == SRV_UM_MSG_BOX_INBOX)
            {
                srv_um_add_address(msg_detail, ut_address[index][i], SRV_UM_ADDR_PHONE_NUMBER, SRV_UM_ADDR_GROUP_FROM, (srv_um_mem_alloc_fn)srv_um_ut_alloc);
            }
            else
            {
                srv_um_add_address(msg_detail, ut_address[index][i], SRV_UM_ADDR_PHONE_NUMBER, SRV_UM_ADDR_GROUP_TO, (srv_um_mem_alloc_fn)srv_um_ut_alloc);
            }
        }
    }
    else if (field & SRV_UM_DETAIL_ADDRESS)
    {
        msg_detail->address.addr = ut_address[index][0];
        msg_detail->address.type = SRV_UM_ADDR_PHONE_NUMBER;
        if (msg_box_type == SRV_UM_MSG_BOX_INBOX)
        {
            msg_detail->address.group = SRV_UM_ADDR_GROUP_FROM;
        }
        else
        {
            msg_detail->address.group = SRV_UM_ADDR_GROUP_TO;
        }
        msg_detail->address.next = msg_detail->address.previous = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
MMI_BOOL srv_um_ut_recv_traverse_msg_req(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_req_struct *req = (srv_um_traverse_msg_req_struct*) inMsg;
    srv_um_traverse_msg_rsp_struct *rsp;
    S32 i, j;
    srv_um_msg_detail_struct *msg_detail;
    S32 error = SRV_UM_RESULT_OK;
    S32 end_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (req->msg_type != SRV_UM_MSG_UT)
    {
        return MMI_FALSE;
    }

    rsp = (srv_um_traverse_msg_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_traverse_msg_rsp_struct));

    rsp->app_id = 0;
    rsp->msg_type = SRV_UM_MSG_UT;

    msg_detail = (srv_um_msg_detail_struct*)get_ctrl_buffer(sizeof(srv_um_msg_detail_struct));

    if (req->start_entry < 0)
    {
        goto match_index;
    }

    if (req->msg_box_type == SRV_UM_MSG_BOX_SENT)
    {
        req->start_entry += SRV_UM_UT_INBOX_MSG_NUMBER;
        end_entry = SRV_UM_UT_TOTAL_MSG_NUMBER;
    }
    else
    {
        end_entry = SRV_UM_UT_INBOX_MSG_NUMBER;
    }

    for (i = req->start_entry; i < end_entry ; i++)
    {
        srv_um_ut_fill_in_data(i, req->field, req->msg_box_type, msg_detail);

        error = req->traverse_func(req->user_data, msg_detail);

        if (req->field & SRV_UM_DETAIL_MULTI_ADDRESS)
        {
            /* because ut_address is static addres, we set the last parameter as FALSE */
            srv_um_free_address_list(msg_detail, (srv_um_mem_free_fn) srv_um_ut_free, KAL_FALSE);
        }

        if (error != SRV_UM_RESULT_OK)
        {
            break;
        }
    }

    rsp->msg_number = i - req->start_entry;

    goto final;

    return MMI_TRUE;

match_index:

    for (i = 0; i < SRV_UM_MAX_TRAVERSE_MSG_NUMBER ; i++)
    {
        if (req->msg_id[i] == 0)
        {
            break;
        }
        srv_um_ut_fill_in_data(req->msg_id[i] - 1, req->field, req->msg_box_type, msg_detail);

        error = req->traverse_func(req->user_data, msg_detail);

        if (req->field & SRV_UM_DETAIL_MULTI_ADDRESS)
        {
            /* because ut_address is static addres, we set the last parameter as FALSE */
            srv_um_free_address_list(msg_detail, (srv_um_mem_free_fn) srv_um_ut_free, KAL_FALSE);
        }

        if (error != SRV_UM_RESULT_OK)
        {
            break;
        }
    }

    rsp->msg_number = i;

final:

    if (error != SRV_UM_RESULT_OK)
    {
        rsp->more = KAL_TRUE;
    }
    else
    {
        rsp->more = KAL_FALSE;
    }

    rsp->result = KAL_TRUE;

    srv_um_ut_send_message(MOD_MMI, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, rsp, NULL);

    free_ctrl_buffer(msg_detail);

    return MMI_TRUE;

}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void srv_um_ut_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (PsIntFuncPtr)srv_um_ut_recv_get_msg_num_req, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_LIST_REQ, (PsIntFuncPtr)srv_um_ut_recv_get_msg_list_req, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_INFO_REQ, (PsIntFuncPtr)srv_um_ut_recv_get_msg_info_req, MMI_TRUE);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ, (PsIntFuncPtr)srv_um_ut_recv_mark_several_op_req, MMI_TRUE);
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, (PsIntFuncPtr)srv_um_ut_recv_traverse_msg_req, MMI_TRUE);
#endif

}

#endif
