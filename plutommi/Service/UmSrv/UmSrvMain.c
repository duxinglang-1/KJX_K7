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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
/**********  KAL Layer Header **************/
#include "string.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "app_str.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "custom_wap_config.h"
#include "customer_ps_inc.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "UmSrvDefs.h"
#include "mmi_frm_queue_gprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "mmi_msg_context.h"
#include "Custom_ProvBox.h"
#include "customer_email_num.h"
#include "PhbSrvGprot.h" /* srv_phb_get_name_by_number */

#include "UmSrvGprot.h"
#include "UmSrvprot.h"
#include "smsSrvgprot.h"
#include "mmi_rp_srv_unifiedmessage_def.h"
#ifdef __COSMOS_MMI_PACKAGE__
static mmi_ret srv_um_sms_msg_common_event_proc(mmi_event_struct *evt);
#endif /* __COSMOS_MMI_PACKAGE__ */
/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/

typedef struct
{
    U16 para_size;
    U16 cntx_size;
    U16 result_size;
      S32(*req_handler) (ums_process_struct *);
      S32(*rsp_handler) (ums_process_struct *, void *inMsg);
} ums_process_type_table_struct;

#ifdef __MMI_VUI_SHELL_APP__
#define UMS_MAX_PROCESS 8
#else
#define UMS_MAX_PROCESS 4
#endif

/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/
#undef PROCESS_TYPE_BASIC_DEF
#define PROCESS_TYPE_BASIC_DEF(type, tag)              \
    S32 REQ_HANDLER(tag)(ums_process_struct *process); \
    S32 RSP_HANDLER(tag)(ums_process_struct *process, RSP_STRUCT(tag) *inMsg);

ALL_PROCESS_TYPE_DEF

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
#undef PROCESS_TYPE_BASIC_DEF
#define PROCESS_TYPE_BASIC_DEF(type, tag)                                            \
    {sizeof(PARA_STRUCT(tag)), sizeof(CNTX_STRUCT(tag)), sizeof(RESULT_STRUCT(tag)), \
        REQ_HANDLER(tag), (S32 (*)(ums_process_struct* , void*))RSP_HANDLER(tag)},
static const ums_process_type_table_struct ums_process_type_tbl[UMS_PROCESS_TYPE_MAX] =
{
    ALL_PROCESS_TYPE_DEF
};

static ums_context_struct g_ums_cntx;
ums_context_struct *g_ums_p = &g_ums_cntx;

static ums_process_struct ums_process_tbl[UMS_MAX_PROCESS];

/************************************************************************/
/* Function Definition                                                  */
/************************************************************************/

#define ISINIT(process)         ((process)->status == UMS_PROCESS_STATUS_INIT)
#define ISREADY(process)        ((process)->status & UMS_PROCESS_STATUS_READY)
#define ISRUNNING(process)      ((process)->status & UMS_PROCESS_STATUS_RUNNING)
#define ISWAITING(process)      ((process)->status & UMS_PROCESS_STATUS_WAITING)
#define ISCANCELLING(process)   ((process)->status & UMS_PROCESS_STATUS_CANCELLING)
#define ISRESET(process)        ((process)->status & UMS_PROCESS_STATUS_RESET)
#define ISFINISHED(process)     ((process)->status == UMS_PROCESS_STATUS_FINISHED)

#define SETINIT(process)        ((process)->status = UMS_PROCESS_STATUS_INIT)
#define SETREADY(process)       ((process)->status = UMS_PROCESS_STATUS_READY)
#define SETRUNNING(process)     ((process)->status = ((process)->status & ~UMS_PROCESS_STATUS_WAITING) | UMS_PROCESS_STATUS_RUNNING)
#define SETWAITING(process)     ((process)->status = ((process)->status & ~UMS_PROCESS_STATUS_RUNNING) | UMS_PROCESS_STATUS_WAITING)
#define SETCANCELLING(process)  ((process)->status |= UMS_PROCESS_STATUS_CANCELLING)
#define SETRESET(process)       ((process)->status |= UMS_PROCESS_STATUS_RESET)
#define SETFINISHED(process)    ((process)->status = UMS_PROCESS_STATUS_FINISHED)

#define REMOVEREADY(process)    ((process)->status = ((process)->status & ~UMS_PROCESS_STATUS_READY))

#define CREATE_PID(ticks,index) (((ticks & 0x007FFFFF) << 8) | index)
#define INDEX_OF_PID(pid) (pid & 0xFF)

#define CHECK_PID_VALID(process_pid,__fail_block__)                                                       \
{                                                                                                         \
    S32 __index__;                                                                                        \
    __index__ = INDEX_OF_PID(process_pid);                                                                \
    if (__index__ < 0 || __index__ >= UMS_MAX_PROCESS || ums_process_tbl[__index__].pid != process_pid)   \
    {                                                                                             \
        __fail_block__;                                                                           \
    }                                                                                             \
}


#define CHECK_VALID_FIELD(field_enum, __test_block__, __fail_block__)   \
if (para->field & field_enum)                                           \
{                                                                       \
    if((__test_block__) == 0)                                           \
    {                                                                   \
        __fail_block__;                                                 \
    }                                                                   \
}
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
/*****************************************************************************
 * FUNCTION
 *  srv_um_get_prefer_sim
 * DESCRIPTION
 *
 * PARAMETERS
 *  void        
 * RETURNS
 *  srv_um_sim_enum   preferred SIM, SRV_UM_SIM_UNCLASSIFIED if no prefer sim is set
 *****************************************************************************/
srv_um_sim_enum srv_um_get_prefer_sim(void)
{
    
    S16 error = 0;
    srv_um_sim_enum prefer_sim = SRV_UM_SIM_UNCLASSIFIED;

    ReadValue(NVRAM_UM_PREFER_SIM, &prefer_sim, DS_BYTE, &error);

    if ((prefer_sim == SRV_UM_SIM_UNCLASSIFIED) 
        ||(prefer_sim == SRV_UM_SIM_GSM_SIM1)
        ||(prefer_sim == SRV_UM_SIM_GSM_SIM2)
    #if MMI_MAX_SIM_NUM >= 3
        ||(prefer_sim == SRV_UM_SIM_GSM_SIM3)
    #if MMI_MAX_SIM_NUM >= 4
        ||(prefer_sim == SRV_UM_SIM_GSM_SIM4)
    #endif
    #endif
        )
    {
        return prefer_sim;
    }
    else
    {
        S8 temp_sim = (S8)SRV_UM_SIM_UNCLASSIFIED;
        WriteValue(NVRAM_UM_PREFER_SIM, &temp_sim, DS_BYTE, &error);
        return SRV_UM_SIM_UNCLASSIFIED;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_prefer_sim
 * DESCRIPTION
 *
 * PARAMETERS
 *  srv_um_sim_enum   preferred SIM, SRV_UM_SIM_UNCLASSIFIED if no prefer sim is set
 * RETURNS
 *  MMI_TRUE if save successful
 *  MMI_FALSE if not save failed
 *****************************************************************************/
MMI_BOOL srv_um_set_prefer_sim(srv_um_sim_enum prefer_sim)
{
    S16 error;
    if (!((prefer_sim == SRV_UM_SIM_UNCLASSIFIED) 
                ||(prefer_sim == SRV_UM_SIM_GSM_SIM1)
                ||(prefer_sim == SRV_UM_SIM_GSM_SIM2)
            #if MMI_MAX_SIM_NUM >= 3
                ||(prefer_sim == SRV_UM_SIM_GSM_SIM3)
            #if MMI_MAX_SIM_NUM >= 4
                ||(prefer_sim == SRV_UM_SIM_GSM_SIM4)
            #endif
            #endif
                ))
    {
        MMI_ASSERT(!"Invalid SIM input");
    }
    WriteValue(NVRAM_UM_PREFER_SIM, &prefer_sim, DS_BYTE, &error);
    if (error == NVRAM_WRITE_SUCCESS)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2)) */

/*****************************************************************************
 * FUNCTION
 *  srv_um_tsfr_msg_type_to_idx
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_type        [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 srv_um_tsfr_msg_type_to_idx(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(msg_type >>= 1)
    {
        i++;
    }

    if (i >= SRV_UM_MAX_SUPPORT_MSG_TYPE)
    {
        ASSERT(0);
        return 0;
    }

    return i;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_tsfr_msg_type_to_idx
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_type        [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 srv_um_tsfr_msg_box_to_idx(srv_um_msg_box_enum msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(msg_box >>= 1)
    {
        i++;
    }

    if (i >= SRV_UM_MAX_SUPPORT_MSG_BOX)
    {
        ASSERT(0);
        return 0;
    }

    return i;
}


#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_um_tsfr_msg_type_to_idx
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_type        [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 srv_um_tsfr_idx_type_to_field(srv_um_list_idx_enum idx_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_detail_field_enum field = SRV_UM_DETAIL_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (idx_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
            field |= SRV_UM_DETAIL_TIMESTAMP;
            break;
        case SRV_UM_LIST_IDX_ADDRESS:
            field |= SRV_UM_DETAIL_ADDRESS;
            break;
        case SRV_UM_LIST_IDX_SUBJECT:
            field |= SRV_UM_DETAIL_SUBJECT;
            break;
        case SRV_UM_LIST_IDX_READ_STATUS:
            field |= SRV_UM_DETAIL_READ_STATUS;
            break;
        case SRV_UM_LIST_IDX_MSG_TYPE:
            break;
        case SRV_UM_LIST_IDX_MSG_SIZE:
            field |= SRV_UM_DETAIL_MSG_SIZE;
            break;
        default:
            ASSERT(0);
    }
    return field;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_async_get_thread_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_type        [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 srv_um_async_get_thread_id(srv_um_addr_enum type, U16* ucs2_str, srv_um_sim_enum sim_id, srv_um_thread_id_struct *thread_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_thread_id_req_struct *req;
    U32 retrieved_events;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    req = (srv_um_get_thread_id_req_struct*) OslConstructDataPtr(sizeof(srv_um_get_thread_id_req_struct));

    req->type = type;
    req->sim_id = sim_id;
    req->number = ucs2_str;
    req->thread_id = thread_id;

    srv_um_send_message(SRV_UM_MSG_SMS, MSG_ID_MMI_UM_GET_THREAD_ID_REQ, req, NULL);
    kal_retrieve_eg_events(g_ums_p->event_group, SRV_UM_EG_GET_THREAD_ID, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND);

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_async_lookup_number
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_type        [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 srv_um_async_lookup_number(U16 *number, U16 *name, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_lookup_number_req_struct *req;
    U32 retrieved_events;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    req = (srv_um_lookup_number_req_struct*) OslConstructDataPtr(sizeof(srv_um_lookup_number_req_struct));

    req->number = number;
    req->name = name;
    req->len = len;

    srv_um_send_message(SRV_UM_MSG_SMS, MSG_ID_MMI_UM_LOOKUP_NUMBER_REQ, req, NULL);
    kal_retrieve_eg_events(g_ums_p->event_group, SRV_UM_EG_LOOKUP_NUMBER, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND);

    return SRV_UM_RESULT_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  srv_um_ready_ind
 * DESCRIPTION
 *  Handle ready infication
 * PARAMETERS
 *  ready           [IN]    ready or unready
 *  msg_type        [IN]    From which message service
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_ready_ind(MMI_BOOL ready, srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ready)
    {
        /* Message sends the second ready indicaiton to UM */
        if (srv_um_check_ready_type(msg_type))
        {
            ASSERT(0);
            return SRV_UM_RESULT_OK;
        }

        g_ums_p->ready_type |= msg_type;
    }
    else
    {
        g_ums_p->ready_type &= ~(msg_type);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_READY_IND_NOT_READY_P1, msg_type);
    }

    for (i = UMS_MAX_PROCESS - 1; i >= 0 ; i --)
    {
        srv_um_reset_process(&ums_process_tbl[i]);
    }
    srv_um_cache_clean(msg_type, SRV_UM_MSG_BOX_ALL);
    srv_um_listmgr_clean(SRV_UM_LIST_TYPE_ALL, msg_type, SRV_UM_MSG_BOX_ALL);
    return SRV_UM_RESULT_OK;
}

void srv_um_refresh_ind_interanl(srv_um_refresh_enum refresh_type, srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type)
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        S32 i;
    
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        if (ISRUNNING(g_ums_p->running_process))
        {
            /* I MUST handle refresh indication in response handler,
               because in some situation, I MUST give up the result in response,
               for example: response for 2nd msg list  */
    
            for (i = UMS_MAX_PROCESS - 1; i >= 0 ; i --)
            {
                switch (ums_process_tbl[i].type)
                {
                case UMS_PROCESS_TYPE_GET_MSG_NUM:
                    if (refresh_type != SRV_UM_REFRESH_MSG_STATUS_CHANGED)
                    {
                        srv_um_reset_process(&ums_process_tbl[i]);
                    }
                case UMS_PROCESS_TYPE_GET_MSG_LIST:
                case UMS_PROCESS_TYPE_GET_MSG_INFO:
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
                case UMS_PROCESS_TYPE_GET_THREAD_LIST:
                case UMS_PROCESS_TYPE_GET_THREAD_INFO:
        #endif
                    srv_um_reset_process(&ums_process_tbl[i]);
                    break;
    
        #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
                case UMS_PROCESS_TYPE_MARK_SEVERAL_OP:
        #endif
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
                case UMS_PROCESS_TYPE_TRAVERSE_MSG:
            #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
                case UMS_PROCESS_TYPE_MARK_SEVERAL_THREAD_OP:
            #endif
        #endif
                case UMS_PROCESS_TYPE_DELETE_FOLDER:
                    break;
                default:
                    EXT_ASSERT(0, 0, 0, 0);
                }
            }
        }
    
        if (g_ums_p->peek_msg_pid)
        {
            srv_um_cancel_process(g_ums_p->peek_msg_pid);
        }
    
        srv_um_cache_clean(msg_type, msg_box_type);
    
        if (refresh_type != SRV_UM_REFRESH_MSG_STATUS_CHANGED)
        {
            srv_um_listmgr_clean(SRV_UM_LIST_TYPE_ALL, msg_type, msg_box_type);
        }
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        else
        {
            srv_um_listmgr_clean(SRV_UM_LIST_TYPE_THREAD, msg_type, msg_box_type);
        }
#endif
}
/*****************************************************************************
 * FUNCTION
 *  srv_um_refresh_ind
 * DESCRIPTION
 *  Handle refresh indication
 * PARAMETERS
 *  msg_type            [IN]    type of message service
 *  msg_box_type        [IN]    type of message box
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_refresh_ind(srv_um_refresh_ind_struct* refresh_ind)
{
    srv_um_refresh_ind_interanl(refresh_ind->refresh_type, refresh_ind->msg_type, refresh_ind->msg_box_type);

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_num_rsp
 * DESCRIPTION
 *  Response handler of "Get Message Number"
 * PARAMETERS
 *  process     [IN]    Pointer to the process.
 *  rsp         [IN]    response message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_get_msg_num_rsp(ums_process_struct *process, srv_um_get_msg_num_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_num_cntx_struct *cntx = g_ums_p->running_process->cntx;

    /* ums_get_msg_num_para_struct *para = g_ums_p->running_process->para; */
    srv_um_get_msg_num_result *result = g_ums_p->running_process->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->running_req_type != rsp->msg_type)
    {
        ASSERT(0);
        result->error = SRV_UM_RESULT_UNKNOWN_ERROR;
        cntx->pending_req_type = SRV_UM_MSG_NONE;
	cntx->running_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    if (rsp->result == KAL_FALSE)
    {
        result->error = SRV_UM_RESULT_UNKNOWN_ERROR;
        cntx->pending_req_type = SRV_UM_MSG_NONE;
	cntx->running_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    result->inbox_msg_number += rsp->inbox_unread_msg_number + rsp->inbox_read_msg_number;
    result->inbox_unread_msg_number += rsp->inbox_unread_msg_number;
    result->unsent_msg_number += rsp->unsent_msg_number;
    result->sent_msg_number += rsp->sent_msg_number;
    result->draft_msg_number += rsp->draft_msg_number;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    result->archive_msg_number += rsp->archive_msg_number;
#endif

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (rsp->msg_type == SRV_UM_MSG_SMS)
    {
        result->sim_msg_number += rsp->sim_msg_number;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_REPORT_BOX__
    result->report_msg_number += rsp->report_msg_number;
#endif

    result->msg_type |= rsp->msg_type;

    cntx->pending_req_type &= ~(rsp->msg_type);
    cntx->running_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_um_get_sort_default_order
 * DESCRIPTION
 *  The default sorting order of each sorting type
 * PARAMETERS
 *  sort_type       [IN]        The sorting type
 * RETURNS
 *  return the order of type
 *****************************************************************************/
srv_um_sort_order_enum srv_um_get_sort_default_order(srv_um_list_idx_enum sort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_sort_order_enum order;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sort_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
        {
            order = SRV_UM_SORT_ORDER_DESCENDING;
            break;
        }
        case SRV_UM_LIST_IDX_ADDRESS:
        case SRV_UM_LIST_IDX_SUBJECT:
        case SRV_UM_LIST_IDX_READ_STATUS:
        case SRV_UM_LIST_IDX_MSG_TYPE:
        case SRV_UM_LIST_IDX_MSG_SIZE:
        {
            order = SRV_UM_SORT_ORDER_ASCENDING;
            break;
        }
        default:
        {
            order = SRV_UM_SORT_ORDER_ASCENDING;
            break;
        }
    }

    return order;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_comp_idx_data
 * DESCRIPTION
 *  The compare function to check which data if large
 *  It depends on the idx_type. The different idx_type has different
 *  default order. Caller could take the sort_order into this function
 *  to decide the order of comparison. If caller does not take any sorting
 *  order, it has its default order.
 * PARAMETERS
 *  prev            [IN]        The previous item
 *  next            [IN]        The next item
 *  idx_type        [IN]        The index type
 *  sort_order      [IN]        The sorting order. (has default order)
 * RETURNS
 *  -1: if prev should be in front of next
 *  1: if prev should be in back of next
 *  0: if prev is equal to next
 *  Example:
 *  (1) Sort by timestamp
 *  if prev = 2009/12/02, next = 2009/12/01. Due to the default sorting
 *  order is latest to farthest, the return value will be -1
 *  (2) Sort by sender name
 *  if prev = "def", next = "abc". Due to the default sorting order is
 *  smallest to largest, the return value will be 1
 *****************************************************************************/
S16 srv_um_comp_idx_data(
        srv_um_list_idx_data_union *prev,
        srv_um_list_idx_data_union *next,
        srv_um_list_idx_enum idx_type,
        srv_um_sort_order_enum sort_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 result = 0;
    S32 str_comp_result = 0;
    srv_um_list_idx_data_union *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_PARA_VALID(prev);
    CHECK_PARA_VALID(next);

    /***********************************************
     * exchange the prev and next for descending
     * sorting order
     * because our sorting comparison always use
     * ascending.
     **********************************************/
    if (sort_order == SRV_UM_SORT_ORDER_DESCENDING)
    {
        tmp = prev;
        prev = next;
        next = tmp;
    }

    /* initial */
    result = 0;
    switch (idx_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
        {
            if (prev->timestamp < next->timestamp)
            {
                result = -1;
            }
            else if (prev->timestamp > next->timestamp)
            {
                result = 1;
            }
            break;
        }
        case SRV_UM_LIST_IDX_ADDRESS:
        {
            str_comp_result = mmi_ucs2icmp((CHAR*) prev->address, (CHAR*) next->address);
            if (str_comp_result < 0)
            {
                result = -1;
            }
            else if (str_comp_result > 0)
            {
                result = 1;
            }
            break;
        }

        case SRV_UM_LIST_IDX_SUBJECT:
        {
            str_comp_result = mmi_ucs2icmp((CHAR*) prev->subject, (CHAR*) next->subject);
            if (str_comp_result < 0)
            {
                result = -1;
            }
            else if (str_comp_result > 0)
            {
                result = 1;
            }
            break;
        }

        case SRV_UM_LIST_IDX_READ_STATUS:
        {
            if (prev->read_status < next->read_status)
            {
                result = -1;
            }
            else if (prev->read_status > next->read_status)
            {
                result = 1;
            }
            break;
        }

        case SRV_UM_LIST_IDX_MSG_SIZE:
        {
            if (prev->msg_size < next->msg_size)
            {
                result = -1;
            }
            else if (prev->msg_size > next->msg_size)
            {
                result = 1;
            }
            break;
        }

        case SRV_UM_LIST_IDX_MSG_TYPE:
        {
            if (prev->msg_type < next->msg_type)
            {
                result = -1;
            }
            else if (prev->msg_type > next->msg_type)
            {
                result = 1;
            }
            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_sort_msg_list_by_insertion
 * DESCRIPTION
 *  Insertion sort algorithm
 * PARAMETERS
 *  msg_list                [IN/OUT]        The message list need to be sorted
 *  list_idx_data           [IN]        The sorting index data
 *  msg_number_in_list      [IN]        size of message list
 *  sort_type               [IN]        The sorting type
 *  sort_order              [IN]        The sorting order
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_sort_msg_list_by_insertion(
        srv_um_msg_list_struct msg_list[],
        srv_um_list_idx_data_union list_idx_data[],
        S32 msg_number_in_list,
        srv_um_list_idx_enum sort_type,
        srv_um_sort_order_enum sort_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    srv_um_msg_list_struct *msg_list_node;
    srv_um_list_idx_data_union *idx_data_tmp;
    S16 comp_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_SORT_BY_INSERTION, sort_type, sort_order);

    CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(list_idx_data);
    CHECK_PARA_VALID(msg_number_in_list);

    msg_list_node = (srv_um_msg_list_struct*) get_ctrl_buffer(sizeof(srv_um_msg_list_struct));
    idx_data_tmp = (srv_um_list_idx_data_union*) get_ctrl_buffer(sizeof(srv_um_list_idx_data_union));

    for (i = 0; i < msg_number_in_list; i++)
    {
        for (j = i + 1; j < msg_number_in_list; j++)
        {
            comp_result = srv_um_comp_idx_data(list_idx_data + i,
                                               list_idx_data + j,
                                               sort_type,
                                               sort_order);
            /* need to exchange */
            if ((comp_result == 1) ||
                (comp_result == 0 && (msg_list[i].timestamp < msg_list[j].timestamp)))
            {
                /* exchange the previos and next nodes */
                memcpy(idx_data_tmp, list_idx_data + i, sizeof(srv_um_list_idx_data_union));
                memcpy(list_idx_data + i, list_idx_data + j, sizeof(srv_um_list_idx_data_union));
                memcpy(list_idx_data + j, idx_data_tmp, sizeof(srv_um_list_idx_data_union));

                memcpy(msg_list_node, msg_list + i, sizeof(srv_um_msg_list_struct));
                memcpy(msg_list + i, msg_list + j, sizeof(srv_um_msg_list_struct));
                memcpy(msg_list + j, msg_list_node, sizeof(srv_um_msg_list_struct));
            }
        }
    }

    free_ctrl_buffer(idx_data_tmp);
    free_ctrl_buffer(msg_list_node);

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_sort_message_list
 * DESCRIPTION
 *  Main function of sort message list
 * PARAMETERS
 *  msg_list                [IN/OUT]        The message list need to be sorted
 *  list_idx_data           [IN]        The sorting index data
 *  msg_number_in_list      [IN]        size of message list
 *  sort_type               [IN]        The sorting type
 *  sort_algo               [IN]        The sorting algorithm
 *  sort_order              [IN]        The sorting order
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_sort_msg_list(
        srv_um_msg_list_struct msg_list[],
        srv_um_list_idx_data_union list_idx_data[],
        S32 msg_number_in_list,
        srv_um_list_idx_enum sort_type,
        srv_um_sort_algorithm_enum sort_algo,
        srv_um_sort_order_enum sort_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(list_idx_data);
    CHECK_PARA_VALID(msg_number_in_list);

    if (sort_order == SRV_UM_SORT_ORDER_UNCLASSIFIED)
    {
        sort_order = srv_um_get_sort_default_order(sort_type);
    }

    switch (sort_algo)
    {
        case SRV_UM_SORT_ALGO_INSERTION:
        {
            srv_um_sort_msg_list_by_insertion(msg_list, list_idx_data, msg_number_in_list, sort_type, sort_order);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
    return SRV_UM_RESULT_OK;
}

#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_um_merge_msg_list
 * DESCRIPTION
 *  Merge two sorted message list
 * PARAMETERS
 *  old_list            [IN]    old message list
 *  old_timestamp       [IN]    timestamp of old message list
 *  old_idx_data        [IN]    sorting index data of old message list
 *  old_list_number     [IN]    size of old message list
 *  add_list            [IN]    another message list need to merge into old message list
 *  msg_type            [IN]    message type of another message list
 *  add_idx_data        [IN]    sorting index data of another message list
 *  add_list_number     [IN]    number of another message list
 *  new_list            [OUT]   Final message list
 *  new_timestamp       [OUT]   Final timestampe of message list
 *  new_idx_data        [OUT]   Final sorting index data of message list
 *  sort_type           [IN]    type of sorting
 *  sort_order          [IN]    order of sorting
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_merge_msg_list(
        srv_um_msg_node_struct *old_list,
        U32 *old_timestamp,
        srv_um_list_idx_data_union *old_idx_data,
        S32 old_list_number,
        srv_um_msg_list_struct *add_list,
        srv_um_msg_enum msg_type,
        srv_um_list_idx_data_union *add_idx_data,
        S32 add_list_number,
        srv_um_msg_node_struct *new_list,
        U32 *new_timestamp,
        srv_um_list_idx_data_union *new_idx_data,
        srv_um_list_idx_enum sort_type,
        srv_um_sort_order_enum sort_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 old_list_idx, add_list_idx, new_list_idx;
    S32 new_list_number = old_list_number + add_list_number;
    S16 comp_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_PARA_VALID(old_list);
    CHECK_PARA_VALID(old_timestamp);
    /* CHECK_PARA_VALID(old_list_number); */
    CHECK_PARA_VALID(add_list);
    CHECK_PARA_VALID(add_list_number);
    CHECK_PARA_VALID(new_list);
    CHECK_PARA_VALID(new_timestamp);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    if (sort_type != SRV_UM_LIST_IDX_TIMESTAMP)
    {
        CHECK_PARA_VALID(old_idx_data);
        CHECK_PARA_VALID(add_idx_data);
        CHECK_PARA_VALID(new_idx_data);
    }

    if (sort_order == SRV_UM_SORT_ORDER_UNCLASSIFIED)
    {
        sort_order = srv_um_get_sort_default_order(sort_type);
    }
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

    old_list_idx = add_list_idx = new_list_idx = 0;

    /* then merge two list
       comp_result = -1:  put old list in front of add list
       comp_result = 1: put add list in front of old list  */
    for (; new_list_idx < new_list_number; new_list_idx++)
    {
        comp_result = 0;

        if (add_list_idx >= add_list_number)
        {
            comp_result = -1;
        }
        else if (old_list_idx >= old_list_number)
        {
            comp_result = 1;
        }

    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        if (comp_result == 0 && sort_type != SRV_UM_LIST_IDX_TIMESTAMP)
        {
            comp_result = srv_um_comp_idx_data(
                            old_idx_data + old_list_idx,
                            add_idx_data + add_list_idx,
                            sort_type,
                            sort_order);
        }
    #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

        if (comp_result == 0)
        {
            if (old_timestamp[old_list_idx] >= add_list[add_list_idx].timestamp)
            {
                comp_result = -1;
            }
            else
            {
                comp_result = 1;
            }
        }

        if (comp_result == -1)
        {
            if (old_list_idx >= old_list_number)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }

            /* move old list to the correct position */
            new_timestamp[new_list_idx] = old_timestamp[old_list_idx];
        #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
            memcpy(&new_idx_data[new_list_idx], &old_idx_data[old_list_idx], sizeof(srv_um_list_idx_data_union));
        #endif
            new_list[new_list_idx].msg_id = old_list[old_list_idx].msg_id;
            new_list[new_list_idx].msg_type = old_list[old_list_idx].msg_type;
            old_list_idx++;

        }
        else
        {

            if (add_list_idx >= add_list_number)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }

            /* move add list to the correct position */
            new_timestamp[new_list_idx] = add_list[add_list_idx].timestamp;
        #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
            memcpy(&new_idx_data[new_list_idx], &add_idx_data[add_list_idx], sizeof(srv_um_list_idx_data_union));
        #endif
            new_list[new_list_idx].msg_id = add_list[add_list_idx].msg_id;
            new_list[new_list_idx].msg_type = msg_type;
            add_list_idx++;
        }
    }

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_list_rsp
 * DESCRIPTION
 *  Response handler of "Get Message List"
 * PARAMETERS
 *  process     [IN]    process to get message list
 *  rsp         [IN]    response message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_get_msg_list_rsp(ums_process_struct *process, srv_um_get_msg_list_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_list_cntx_struct *cntx = process->cntx;
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    ums_get_msg_list_para_struct *para = process->para;
#endif
    srv_um_get_msg_list_result *result = process->result;

    U16 offset, max_msg_num;

    /* U16 old_list_idx, add_list_idx, new_list_idx; */
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->running_req_type != rsp->msg_type)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    if (result->n.msg_number != cntx->finish_idx[0] + cntx->finish_idx[1] + cntx->finish_idx[2] + cntx->finish_idx[3] +
        cntx->finish_idx[4] + cntx->finish_idx[5] + cntx->finish_idx[6] + cntx->finish_idx[7])
    {
        EXT_ASSERT(0, 0, 0, 0);
        result->error = SRV_UM_RESULT_INVALID_PARA;
        cntx->pending_req_type = SRV_UM_MSG_NONE;
	cntx->running_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    if (rsp->result == KAL_FALSE)
    {
        ASSERT(0);
        result->error = SRV_UM_RESULT_UNKNOWN_ERROR;
        cntx->pending_req_type = SRV_UM_MSG_NONE;
	cntx->running_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    if (cntx->msg_list_size > SRV_UM_MAX_MSG_NUM)
    {
        max_msg_num = SRV_UM_MAX_MSG_NUM;
    }
    else
    {
        max_msg_num = cntx->msg_list_size;
    }

    if (rsp->msg_number + result->n.msg_number > max_msg_num)
    {
        ASSERT(0);
        result->error = SRV_UM_RESULT_TOO_MANY_MESSAGE;
        cntx->pending_req_type = SRV_UM_MSG_NONE;
	cntx->running_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    if (rsp->msg_number == 0)
    {
        cntx->pending_req_type &= ~rsp->msg_type;
        cntx->running_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    if (para->filter.idx_type == SRV_UM_LIST_IDX_ADDRESS)
    {
        S32 i;
        U16 phb_name[SRV_UM_MAX_LIST_INDEX_LEN + 1];

        for (i = 0; i < rsp->msg_number; i++)
        {
            if (rsp->msg_type == SRV_UM_MSG_SMS || rsp->msg_type == SRV_UM_MSG_MMS || rsp->msg_type == SRV_UM_MSG_UT)
            {
                srv_phb_get_name_by_number((U16*)rsp->list_idx_data[i].address, (U16*)phb_name, SRV_UM_MAX_LIST_INDEX_LEN);

                if (mmi_ucs2strlen((CHAR*)phb_name) != 0)
                {
                      mmi_ucs2ncpy((CHAR*)rsp->list_idx_data[i].address, (CHAR*)phb_name, SRV_UM_MAX_LIST_INDEX_LEN);
                }
            }
        }
    }

    if (para->filter.idx_type != SRV_UM_LIST_IDX_TIMESTAMP)
    {
        if (rsp->msg_number)
        {
            srv_um_sort_msg_list(
                rsp->list_info,
                rsp->list_idx_data,
                rsp->msg_number,
                para->filter.idx_type,
                SRV_UM_SORT_ALGO_INSERTION,
                para->filter.order);
        }
    }
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

    if (result->n.msg_number != 0)
    {
        /* old list is in 1~100,  list size is 300, move the old list to 201~300 */
        offset = max_msg_num - result->n.msg_number;
        for (i = result->n.msg_number - 1; i >= 0; i--)
        {
            memcpy(cntx->msg_list + offset + i, cntx->msg_list + i, sizeof(srv_um_msg_node_struct));
            *(cntx->timestamp_idx_data + offset + i) = *(cntx->timestamp_idx_data + i);
        #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
            memcpy(cntx->list_idx_data + offset + i, cntx->list_idx_data + i, sizeof(srv_um_list_idx_data_union));
        #endif
        }
    }
    else
    {
        offset = max_msg_num;
    }

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    srv_um_merge_msg_list(
        cntx->msg_list + offset,
        cntx->timestamp_idx_data + offset,
        cntx->list_idx_data + offset,
        result->n.msg_number,
        rsp->list_info,
        rsp->msg_type,
        rsp->list_idx_data,
        rsp->msg_number,
        cntx->msg_list,
        cntx->timestamp_idx_data,
        cntx->list_idx_data,
        para->filter.idx_type,
        para->filter.order);
#else
    srv_um_merge_msg_list(
        cntx->msg_list + offset,
        cntx->timestamp_idx_data + offset,
        NULL,
        result->n.msg_number,
        rsp->list_info,
        rsp->msg_type,
        NULL,
        rsp->msg_number,
        cntx->msg_list,
        cntx->timestamp_idx_data,
        NULL,
        SRV_UM_LIST_IDX_TIMESTAMP,
        SRV_UM_SORT_ORDER_UNCLASSIFIED);
#endif

    cntx->finish_idx[srv_um_tsfr_msg_type_to_idx(rsp->msg_type)] += rsp->msg_number;
    result->n.msg_number += rsp->msg_number;

    if (rsp->more == KAL_FALSE)
    {
        cntx->pending_req_type &= ~rsp->msg_type;
    }
    cntx->running_req_type = SRV_UM_MSG_NONE;
    return SRV_UM_RESULT_OK;
}

#ifdef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_info_traverse_func
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  message     [IN]    message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_BUFFER_FULL       :   stop traverse message
 *  SRV_UM_RESULT_OK                :   continue to traverse message
 *****************************************************************************/
S32 srv_um_get_msg_info_traverse_func(S32 pid, srv_um_msg_detail_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process; 
    srv_um_get_msg_info_result *result;
    S32 i ;
    srv_um_msg_info_struct *msg_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_BUFFER_FULL;
    }
 
    result = process->result;

    msg_info = (srv_um_msg_info_struct*) get_ctrl_buffer(sizeof(srv_um_msg_info_struct));
    memset(msg_info, 0, sizeof(srv_um_msg_info_struct));

    msg_info->msg_id = message->msg_id;
    msg_info->timestamp = message->timestamp;
    msg_info->address_type = message->address.type;
    app_ucs2_strncpy((kal_int8*)msg_info->address, (kal_int8*)message->address.addr, SRV_UM_MAX_ADDR_LEN);
    msg_info->address_length = app_ucs2_strlen((kal_int8*)msg_info->address);
    app_ucs2_strncpy((kal_int8*)msg_info->subject, (kal_int8*)message->subject, SRV_UM_MAX_SUBJECT_LEN);
    msg_info->subject_length = app_ucs2_strlen((kal_int8*)msg_info->subject);
    msg_info->address_number = 1;
    msg_info->address_more = KAL_FALSE;

    if (message->address.next)
    {
        srv_um_addr_struct *addr = message->address.next;

        for (i = 0 ;i < SRV_UM_EXTEND_ADDRESS_NUM && addr!=NULL; i++, addr = addr->next)
        {
            msg_info->address_number++;
            app_ucs2_strncpy((kal_int8*)msg_info->address_ext[i], (kal_int8*)addr->addr, SRV_UM_MAX_ADDR_LEN);
        }

        if (addr != NULL)
        {
            msg_info->address_more = KAL_TRUE;
        }
    }

    msg_info->msg_status = message->msg_status;

#ifdef __MMI_DUAL_SIM_MASTER__
    msg_info->sim_id = message->sim_id;
#endif

    srv_um_cache_add(message->msg_type, message->msg_box_type, msg_info, 1);

    result->no_of_success++;

    free_ctrl_buffer(msg_info);

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_info_traverse_cb
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  rsp         [IN]    result
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_get_msg_info_traverse_cb(S32 pid, srv_um_traverse_msg_result* rsp, S32 user_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_msg_info_cntx_struct *cntx;
    ums_get_msg_info_para_struct *para;
    srv_um_get_msg_info_result *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(user_data, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(user_data)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    ASSERT(process->child == pid);

    cntx = process->cntx;
    para = process->para;
    result = process->result;

    result->no_of_fail = para->msg_number - result->no_of_success;

    result->error = rsp->error;

    if (rsp->error != SRV_UM_RESULT_OK)
    {
        ASSERT(0);
        cntx->pending_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    cntx->pending_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_info_rsp
 * DESCRIPTION
 *  Response handler of "Get Message Infomation"
 * PARAMETERS
 *  process     [IN]     Process to get message information
 *  p           [IN]     response message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_get_msg_info_rsp(ums_process_struct *process, srv_um_get_msg_info_rsp_struct *p)
{
#ifndef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_rsp_struct *rsp = (srv_um_get_msg_info_rsp_struct*) p;
    ums_get_msg_info_cntx_struct *cntx = process->cntx;
    ums_get_msg_info_para_struct *para = process->para;
    srv_um_get_msg_info_result *result = process->result;

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->running_req_type != rsp->msg_type)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    if (rsp->msg_number != cntx->running_msg_number)
    {
        ASSERT(0);
        result->error = SRV_UM_RESULT_UNKNOWN_ERROR;
        return SRV_UM_RESULT_OK;
    }

    for (i = 0; i < rsp->msg_number; i++)
    {
        if (!rsp->result[i])
        {
            result->no_of_fail++;
            rsp->msg_info[i].timestamp = 0;
        }
        else
        {
            result->no_of_success++;
        }
    }
    srv_um_cache_add(rsp->msg_type, rsp->msg_box_type, rsp->msg_info, rsp->msg_number);

    if (cntx->finish_idx[srv_um_tsfr_msg_type_to_idx(rsp->msg_type)] >= para->msg_number)
    {
        cntx->pending_req_type &= ~(rsp->msg_type);
    }

    cntx->running_req_type = SRV_UM_MSG_NONE;
    cntx->running_msg_number = 0;
#endif
    return SRV_UM_RESULT_OK;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_mark_several_op_rsp
 * DESCRIPTION
 *  Response handler of "Mark Several Operation"
 * PARAMETERS
 *  process     [IN]    process to do mark several
 *  rsp         [IN]    response message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_mark_several_op_rsp(ums_process_struct *process, srv_um_mark_several_op_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_mark_several_op_cntx_struct *cntx = process->cntx;
    ums_mark_several_op_para_struct *para = process->para;
    srv_um_mark_several_op_result *result = process->result;

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->running_req_type != rsp->msg_type)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    /* compute the action result, update the number of success, fail and undo */
    for (i = 0; i < rsp->msg_number; i++)
    {
        if (rsp->action_result[i] == KAL_TRUE)
        {
            result->no_of_success++;
        }
        else
        {
            result->no_of_fail++;
        }
    }

    if (cntx->finish_idx[srv_um_tsfr_msg_type_to_idx(rsp->msg_type)] >= para->msg_list_size)
    {
        cntx->pending_req_type &= ~(rsp->msg_type);
    }

    cntx->running_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_traverse_msg_req
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  message     [IN]    message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_BUFFER_FULL       :   stop traverse message
 *  SRV_UM_RESULT_OK                :   continue to traverse message
 *****************************************************************************/
S32 srv_um_traverse_base_func(S32 pid, srv_um_msg_detail_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_traverse_msg_cntx_struct *cntx;
    ums_traverse_msg_para_struct *para;
    srv_um_traverse_msg_result *result;
    S32 time_now;
    MMI_BOOL is_malloc = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];
    cntx = process->cntx;
    para = process->para;
    result = process->result;

    if (ISCANCELLING(process) || ISRESET(process))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_TRAVERSE_BASE_FUNC, message->msg_id, SRV_UM_RESULT_CANCELLLED);

        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_BUFFER_FULL;
    }

    kal_get_time((kal_uint32*)&time_now);

#ifdef __MTK_TARGET__
    /* 1 tick = 4.61ms, around 200 ms */
    if (time_now - cntx->start_time > 50 && cntx->counter >= SRV_UM_MAX_TRAVERSE_MSG_NUMBER)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_TRAVERSE_BASE_FUNC, message->msg_id, SRV_UM_RESULT_BUFFER_FULL);

        result->error = SRV_UM_RESULT_BUFFER_FULL;
        return SRV_UM_RESULT_BUFFER_FULL;
    }

    cntx->counter++;

#else

    if (cntx->counter >= SRV_UM_MAX_TRAVERSE_MSG_NUMBER)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_TRAVERSE_BASE_FUNC, message->msg_id, SRV_UM_RESULT_BUFFER_FULL);

        result->error = SRV_UM_RESULT_BUFFER_FULL;
        return SRV_UM_RESULT_BUFFER_FULL;
    }

    cntx->counter++;

#endif

    if (message->msg_type != cntx->running_req_type)
    {
        ASSERT(0);
        return SRV_UM_RESULT_INVALID_PARA;
    }

    CHECK_VALID_FIELD(SRV_UM_DETAIL_MSG_BOX, (message->msg_box_type != SRV_UM_MSG_BOX_NONE), {ASSERT(0); return SRV_UM_RESULT_INVALID_PARA;});

    /* some special case that sms in sim card may be with timstamp = 0  MAUI_02627052 */
    /* corrupted mms may be with timestamp = 0 */
    if (message->msg_type != SRV_UM_MSG_SMS && 
        message->msg_type != SRV_UM_MSG_MMS)
    {
        CHECK_VALID_FIELD(SRV_UM_DETAIL_TIMESTAMP, (message->timestamp != 0), {ASSERT(0);return SRV_UM_RESULT_INVALID_PARA;});
    }

    CHECK_VALID_FIELD(SRV_UM_DETAIL_READ_STATUS, 1, {ASSERT(0);return SRV_UM_RESULT_INVALID_PARA;});
//    for some corrupted MMS, the message size would be zero
//    CHECK_VALID_FIELD(SRV_UM_DETAIL_MSG_SIZE, (message->msg_size != 0), {ASSERT(0);return SRV_UM_RESULT_INVALID_PARA;});
    CHECK_VALID_FIELD(SRV_UM_DETAIL_SUBJECT, (message->subject != NULL), {ASSERT(0);return SRV_UM_RESULT_INVALID_PARA;});
//    CHECK_VALID_FIELD(SRV_UM_DETAIL_ADDRESS, (message->address.addr != NULL), {ASSERT(0);return SRV_UM_RESULT_INVALID_PARA;});
//    CHECK_VALID_FIELD(SRV_UM_DETAIL_MULTI_ADDRESS, (message->address.addr != NULL), {ASSERT(0);return SRV_UM_RESULT_INVALID_PARA;});
#ifdef __MMI_DUAL_SIM_MASTER__
    // In draft folder, the sim id may be unclassified
    //CHECK_VALID_FIELD(SRV_UM_DETAIL_SIM_ID, (message->sim_id != SRV_UM_SIM_UNCLASSIFIED), {ASSERT(0);return SRV_UM_RESULT_INVALID_PARA;});
#endif

    if (para->field & SRV_UM_DETAIL_ADDRESS || para->field & SRV_UM_DETAIL_MULTI_ADDRESS)
    {
        if (message->address.addr == NULL)
        {
            if (message->address.type == SRV_UM_ADDR_EMPTY)
            {
                /* allocate a temp buffer for this special case */
                message->address.addr = (kal_wchar*) get_ctrl_buffer(sizeof(8));

                is_malloc = MMI_TRUE;

                memset(message->address.addr, 0, sizeof(8));

                if (message->msg_box_type == SRV_UM_MSG_BOX_INBOX)
                {
                    message->address.group = SRV_UM_ADDR_GROUP_FROM;
                }
                else
                {
                    message->address.group = SRV_UM_ADDR_GROUP_TO;
                }
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    result->error = para->traverse_func(para->user_data, message);

    if (result->error == SRV_UM_RESULT_OK)
    {
        result->msg_number++;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_TRAVERSE_BASE_FUNC, message->msg_id, SRV_UM_RESULT_OK);


    if (is_malloc)
    {
        free_ctrl_buffer(message->address.addr);
        message->address.addr = NULL;
    }

    return result->error;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_traverse_msg_rsp
 * DESCRIPTION
 *  Response handler of "Get Message List"
 * PARAMETERS
 *  process     [IN]    process to get message list
 *  rsp         [IN]    response message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_traverse_msg_rsp(ums_process_struct *process, srv_um_traverse_msg_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_traverse_msg_cntx_struct *cntx = process->cntx;
    ums_traverse_msg_para_struct *para = process->para;
    srv_um_traverse_msg_result *result = process->result;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->running_req_type != rsp->msg_type)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    /* Use message id array to traverse message*/
    if (para->msg_list)
    {
        /* The message application do not traverse all the messages
            that means something strange , maybe the message is deleted and
            AP do not cancel this request, so we should not assert here */
        if (rsp->result == KAL_FALSE ||
            cntx->counter != cntx->request_number ||
            rsp->msg_number != cntx->request_number)
        {
            result->error = SRV_UM_RESULT_DATA_NOT_FOUND;
            cntx->running_req_box = SRV_UM_MSG_BOX_NONE;
	    cntx->running_req_type = SRV_UM_MSG_NONE;
            cntx->pending_req_type = SRV_UM_MSG_NONE;
            memset(cntx->pending_req_box, 0, sizeof(cntx->pending_req_box));
            return SRV_UM_RESULT_OK;
        }
    }
    else
    {
        if (rsp->result == KAL_FALSE)
        {
            ASSERT(0);
            /* the error code is set in traverse func */
            cntx->running_req_box = SRV_UM_MSG_BOX_NONE;
            cntx->running_req_type = SRV_UM_MSG_NONE;
            memset(cntx->pending_req_box, 0, sizeof(cntx->pending_req_box));
            return SRV_UM_RESULT_OK;
        }

        /* previous response from ap with more = KAL_TRUE, but in this response message
           ap didn't invoke traverse callback function */
        if (result->error == SRV_UM_RESULT_BUFFER_FULL && rsp->msg_number == 0)
        {
            ASSERT(0);
        }
    }

    /* the counter is different from response message */
    if (cntx->counter != rsp->msg_number)
    {
        ASSERT(0);
    }

    i = srv_um_tsfr_msg_type_to_idx(cntx->running_req_type);
    j = srv_um_tsfr_msg_box_to_idx(cntx->running_req_box);

    if (!para->msg_list)
    {
        cntx->finish_idx[i][j] += rsp->msg_number;

        if (para->msg_number == 0 && rsp->more == KAL_FALSE)
        {
            cntx->pending_req_box[i] &= ~(cntx->running_req_box);

            if (!cntx->pending_req_box[i])
            {
                cntx->pending_req_type &= ~(cntx->running_req_type);
            }
        }
    }
    else
    {

        if (cntx->finish_idx[i][0] >= para->msg_number)
        {
            cntx->pending_req_type &= ~(cntx->running_req_type);
        }
    }

    cntx->running_req_type = SRV_UM_MSG_NONE;
    cntx->running_req_box = SRV_UM_MSG_BOX_NONE;

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_sort_thread_list_by_insertion
 * DESCRIPTION
 *  Insertion sort algorithm
 * PARAMETERS
 *  thread_list             [IN/OUT]    The message list need to be sorted
 *  sort_data               [IN]        The sorting index data
 *  msg_number_in_list      [IN]        size of message list
 *  sort_type               [IN]        The sorting type
 *  sort_order              [IN]        The sorting order
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_sort_list_by_insertion(
        srv_um_list_type_enum list_type,
        void * list,
        ums_get_list_sort_idx sort_idx_data[],
        S32 list_size,
        srv_um_list_idx_enum sort_type,
        srv_um_sort_order_enum sort_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    void *list_tmp;
    ums_get_list_sort_idx *sort_idx_data_tmp;
    S16 comp_result;
    S32 item_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_SORT_BY_INSERTION, sort_type, sort_order);

    CHECK_PARA_VALID(list);
    CHECK_PARA_VALID(sort_idx_data);
    CHECK_PARA_VALID(list_size);

    if (list_type == SRV_UM_LIST_TYPE_MSG_NODE)
    {
        item_size = sizeof(srv_um_msg_node_struct);
    }
    else
    {
        item_size = sizeof(srv_um_thread_id_struct);
    }

    list_tmp = (void*) get_ctrl_buffer(item_size);
    sort_idx_data_tmp = (ums_get_list_sort_idx*) get_ctrl_buffer(sizeof(ums_get_list_sort_idx));

    for (i = 0; i < list_size; i++)
    {
        for (j = i + 1; j < list_size; j++)
        {
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            comp_result = srv_um_comp_idx_data(&(sort_idx_data[i].list_idx_data),
                                               &(sort_idx_data[j].list_idx_data),
                                               sort_type,
                                               sort_order);
        #else
            comp_result = 0;
        #endif
            /* need to exchange */
            if ((comp_result == 1) ||
                (comp_result == 0 && (sort_idx_data[i].timestamp < sort_idx_data[j].timestamp)))
            {
                /* exchange the previos and next nodes */
                memcpy(sort_idx_data_tmp, sort_idx_data + i, sizeof(ums_get_list_sort_idx));
                memcpy(sort_idx_data + i, sort_idx_data + j, sizeof(ums_get_list_sort_idx));
                memcpy(sort_idx_data + j, sort_idx_data_tmp, sizeof(ums_get_list_sort_idx));

                memcpy(list_tmp                 , (CHAR*)list + i * item_size, item_size);
                memcpy((CHAR*)list + i * item_size, (CHAR*)list + j * item_size, item_size);
                memcpy((CHAR*)list + j * item_size, list_tmp                 , item_size);
            }
        }
    }

    free_ctrl_buffer(sort_idx_data_tmp);
    free_ctrl_buffer(list_tmp);

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_sort_message_list
 * DESCRIPTION
 *  Main function of sort message list
 * PARAMETERS
 *  msg_list                [IN/OUT]        The message list need to be sorted
 *  list_idx_data           [IN]        The sorting index data
 *  msg_number_in_list      [IN]        size of message list
 *  sort_type               [IN]        The sorting type
 *  sort_algo               [IN]        The sorting algorithm
 *  sort_order              [IN]        The sorting order
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_sort_list(
    srv_um_list_type_enum list_type,
    void *list,
    ums_get_list_sort_idx sort_idx_data[],
    S32 list_size,
    srv_um_list_idx_enum sort_type,
    srv_um_sort_order_enum sort_order,
    srv_um_sort_algorithm_enum sort_algo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_PARA_VALID(list);
    CHECK_PARA_VALID(sort_idx_data);
    CHECK_PARA_VALID(list_size);

    if (sort_order == SRV_UM_SORT_ORDER_UNCLASSIFIED);
    {
        #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
        sort_order = srv_um_get_sort_default_order(sort_type);
        #else
        sort_order = SRV_UM_SORT_ORDER_DESCENDING;
        #endif
    }

    switch (sort_algo)
    {
        case SRV_UM_SORT_ALGO_INSERTION:
        {
            srv_um_sort_list_by_insertion(list_type, list, sort_idx_data, list_size, sort_type, sort_order);
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_list_traverse_func
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  message     [IN]    message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_BUFFER_FULL       :   stop traverse message
 *  SRV_UM_RESULT_OK                :   continue to traverse message
 *****************************************************************************/
S32 srv_um_get_msg_list_traverse_func(S32 pid, srv_um_msg_detail_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_msg_list_cntx_struct *cntx;
    ums_get_msg_list_para_struct *para;
    srv_um_get_msg_list_result *result;

    srv_um_thread_id_struct thread_id;
    srv_um_addr_struct *addr;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_BUFFER_FULL;
    }

    cntx = process->cntx;
    para = process->para;
    result = process->result;

    if (result->n.msg_number >= cntx->msg_list_size)
    {
        result->error = SRV_UM_RESULT_TOO_MANY_MESSAGE;
        return SRV_UM_RESULT_TOO_MANY_MESSAGE;
    }

    /* insert all address into link list */
    for (addr = &message->address; addr != NULL ; addr = addr->next)
    {
        if (addr->group != SRV_UM_ADDR_GROUP_TO && addr->group != SRV_UM_ADDR_GROUP_FROM)
        {
            ASSERT(0);
            continue;
        }

    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        if (message->address.next != NULL)
        {
            srv_um_tsfr_msg_id_to_thread_id(message->msg_type, message->msg_id, &thread_id);
        }
        else
    #endif
        if (stack_get_active_module_id() == MOD_MMI)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_async_get_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_async_get_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }

        /* got it */
        if (thread_id.type == para->filter.thread_id.type
            && thread_id.value == para->filter.thread_id.value
        #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
            && thread_id.sim_id == para->filter.thread_id.sim_id
        #endif
            )
        {
            index = result->n.msg_number;
            result->n.msg_number ++;
            cntx->msg_list[index].msg_type = message->msg_type;
            cntx->msg_list[index].msg_id = message->msg_id;
            cntx->sort_idx_data[index].timestamp = message->timestamp;

        #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
            switch(para->filter.idx_type)
            {
                case SRV_UM_LIST_IDX_TIMESTAMP:
                    break;
                case SRV_UM_LIST_IDX_ADDRESS:
                    /* use the first address to sorting */
                    if (stack_get_active_module_id() == MOD_MMI)
                    {
                        srv_phb_get_name_by_number(message->address.addr, cntx->sort_idx_data[index].list_idx_data.address, SRV_UM_MAX_LIST_INDEX_LEN);
                    }
                    else
                    {
                        srv_um_async_lookup_number(message->address.addr, cntx->sort_idx_data[index].list_idx_data.address, SRV_UM_MAX_LIST_INDEX_LEN);
                    }

                    if (mmi_ucs2strlen((CHAR*)cntx->sort_idx_data[index].list_idx_data.address) == 0)
                    {
                          mmi_ucs2ncpy((CHAR*)cntx->sort_idx_data[index].list_idx_data.address, (CHAR*)message->address.addr, SRV_UM_MAX_LIST_INDEX_LEN);
                    }

                    break;
                case SRV_UM_LIST_IDX_SUBJECT:
                    mmi_ucs2ncpy((CHAR*)cntx->sort_idx_data[index].list_idx_data.subject, (CHAR*)message->subject, SRV_UM_MAX_LIST_INDEX_LEN);
                    break;
                case SRV_UM_LIST_IDX_READ_STATUS:
                    cntx->sort_idx_data[index].list_idx_data.read_status = message->read_status;
                    break;
                case SRV_UM_LIST_IDX_MSG_TYPE:
                    cntx->sort_idx_data[index].list_idx_data.msg_type = message->msg_type;
                    break;
                case SRV_UM_LIST_IDX_MSG_SIZE:
                    cntx->sort_idx_data[index].list_idx_data.msg_size = message->msg_size;
                    break;
            }
        #endif

            /* also update the thread info */
            cntx->thread_info.total_msg_number++;

            if (!message->read_status)
            {
                cntx->thread_info.unread_msg_number++;
            }


            /* the default timestamp of thread_head is zero
               if the first message's timestamp is zero too, we need to replace it */
            if (cntx->thread_head_timestamp < message->timestamp || cntx->thread_info.list_head.msg_type == SRV_UM_MSG_NONE)
            {
                cntx->thread_info.list_head.msg_type = message->msg_type;
                cntx->thread_info.list_head.msg_id = message->msg_id;
                cntx->thread_head_timestamp = message->timestamp;
            }

            break;
        }

    /* only handle first address */
    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        break;
    #endif
    }

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_list_traverse_cb
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  rsp         [IN]    result
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_get_msg_list_traverse_cb(S32 pid, srv_um_traverse_msg_result* rsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_msg_list_cntx_struct *cntx;
    ums_get_msg_list_para_struct *para;
    srv_um_get_msg_list_result *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(user_data, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(user_data)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    ASSERT(process->child == pid);

    cntx = process->cntx;
    para = process->para;
    result = process->result;

    result->error = rsp->error;

    if (rsp->error != SRV_UM_RESULT_OK)
    {
        ASSERT(0);
        cntx->pending_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    if (result->n.msg_number)
    {
        srv_um_sort_list(
            SRV_UM_LIST_TYPE_MSG_NODE,
            cntx->msg_list,
            cntx->sort_idx_data,
            result->n.msg_number,
            para->filter.idx_type,
            SRV_UM_SORT_ORDER_UNCLASSIFIED,
            SRV_UM_SORT_ALGO_INSERTION);
    }

    cntx->pending_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_list_traverse_func
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  message     [IN]    message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_BUFFER_FULL       :   stop traverse message
 *  SRV_UM_RESULT_OK                :   continue to traverse message
 *****************************************************************************/
S32 srv_um_get_thread_list_traverse_func(S32 pid, srv_um_msg_detail_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_thread_list_cntx_struct *cntx;
    srv_um_get_thread_list_result *result;

    srv_um_thread_id_struct thread_id;
    srv_um_addr_struct *addr;
    srv_um_thread_info_struct *thread_info;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_BUFFER_FULL;
    }

    cntx = process->cntx;
    result = process->result;

    /* find all address in the message */
    for (addr = &message->address; addr != NULL ; addr = addr->next)
    {
        MMI_BOOL replace = MMI_FALSE;

        if (addr->group != SRV_UM_ADDR_GROUP_TO && addr->group != SRV_UM_ADDR_GROUP_FROM)
        {
            ASSERT(0);
            continue;
        }

        if (message->msg_box_type == SRV_UM_MSG_BOX_INBOX)
        {
            if (addr->group != SRV_UM_ADDR_GROUP_FROM)
            {
                ASSERT(0);
                continue;
            }
        }
        else
        {
            if (addr->group != SRV_UM_ADDR_GROUP_TO)
            {
                ASSERT(0);
                continue;
            }
        }

    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        if (message->address.next != NULL)
        {
            srv_um_tsfr_msg_id_to_thread_id(message->msg_type, message->msg_id, &thread_id);
        }
        else
    #endif
        if (stack_get_active_module_id() == MOD_MMI)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_async_get_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_async_get_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }

        /* search if the index exist or not */
        for (index = result->n.thread_number; index >=0; index--)
        {
            if (cntx->thread_list[index].type == thread_id.type
                && cntx->thread_list[index].value == thread_id.value
            #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
                && cntx->thread_list[index].sim_id == thread_id.sim_id
            #endif
                )
            {
                break;
            }
        }

        /* not exist */
        if (index < 0)
        {
            index = result->n.thread_number;

            if (index >= SRV_UM_MAX_MSG_NUM)
            {
                result->error = SRV_UM_RESULT_TOO_MANY_THREAD;
                return SRV_UM_RESULT_TOO_MANY_THREAD;
            }

            memcpy(&cntx->thread_list[index], &thread_id, sizeof(srv_um_thread_id_struct));

            thread_info = srv_um_thread_info_set_by_index(index, thread_id);

            result->n.thread_number++;

            replace = MMI_TRUE;
        }
        else
        {
            thread_info = srv_um_thread_info_get_by_index(index);
            /* replace */
            if (cntx->sort_idx_data[index].timestamp < message->timestamp)
            {
                replace = MMI_TRUE;
            }
        }

        if (replace)
        {
            thread_info->list_head.msg_type = message->msg_type;
            thread_info->list_head.msg_id = message->msg_id;
            cntx->sort_idx_data[index].timestamp = message->timestamp;

        #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
            switch(para->filter.idx_type)
            {
                case SRV_UM_LIST_IDX_TIMESTAMP:
                    break;
                case SRV_UM_LIST_IDX_ADDRESS:

                    if (stack_get_active_module_id() == MOD_MMI)
                    {
                        srv_phb_get_name_by_number(addr->addr, cntx->sort_idx_data[index].list_idx_data.address, SRV_UM_MAX_LIST_INDEX_LEN);
                    }
                    else
                    {
                        srv_um_async_lookup_number(addr->addr, cntx->sort_idx_data[index].list_idx_data.address, SRV_UM_MAX_LIST_INDEX_LEN);
                    }

                    if (mmi_ucs2strlen((CHAR*)cntx->sort_idx_data[index].list_idx_data.address) == 0)
                    {
                          mmi_ucs2ncpy((CHAR*)cntx->sort_idx_data[index].list_idx_data.address, (CHAR*)addr->addr, SRV_UM_MAX_LIST_INDEX_LEN);
                    }

                    break;
                case SRV_UM_LIST_IDX_SUBJECT:
                    mmi_ucs2ncpy((CHAR*)cntx->sort_idx_data[index].list_idx_data.subject, (CHAR*)message->subject, SRV_UM_MAX_LIST_INDEX_LEN);
                    break;
                case SRV_UM_LIST_IDX_READ_STATUS:
                    cntx->sort_idx_data[index].list_idx_data.read_status = message->read_status;
                    break;
                case SRV_UM_LIST_IDX_MSG_TYPE:
                    cntx->sort_idx_data[index].list_idx_data.msg_type = message->msg_type;
                    break;
                case SRV_UM_LIST_IDX_MSG_SIZE:
                    cntx->sort_idx_data[index].list_idx_data.msg_size = message->msg_size;
                    break;
            }
        #endif
        }

        thread_info->total_msg_number++;

        if (!message->read_status)
        {
            thread_info->unread_msg_number++;
        }

    /* only handle first address */
    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        break;
    #endif
    }

    return SRV_UM_RESULT_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_list_traverse_cb
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  rsp         [IN]    result
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_get_thread_list_traverse_cb(S32 pid, srv_um_traverse_msg_result* rsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_thread_list_cntx_struct *cntx;
    ums_get_thread_list_para_struct *para;
    srv_um_get_thread_list_result *result;
//    S32 error;

//    srv_um_thread_id_struct thread_id;
//    srv_um_addr_struct *addr;
//    srv_um_thread_info_struct *thread_info;
//    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(user_data, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(user_data)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    ASSERT(process->child == pid);

    cntx = process->cntx;
    para = process->para;
    result = process->result;

    result->error = rsp->error;

    if (rsp->error != SRV_UM_RESULT_OK)
    {
        ASSERT(0);
        cntx->pending_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    if (result->n.thread_number)
    {
        srv_um_sort_list(
            SRV_UM_LIST_TYPE_THREAD,
            cntx->thread_list,
            cntx->sort_idx_data,
            result->n.thread_number,
            para->filter.idx_type,
            SRV_UM_SORT_ORDER_UNCLASSIFIED,
            SRV_UM_SORT_ALGO_INSERTION);
    }

    cntx->pending_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_list_rsp
 * DESCRIPTION
 *  Dummy Function
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_get_thread_list_rsp(ums_process_struct *process, srv_um_get_thread_list_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_info_traverse_func
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  message     [IN]    message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_BUFFER_FULL       :   stop traverse message
 *  SRV_UM_RESULT_OK                :   continue to traverse message
 *****************************************************************************/
S32 srv_um_get_thread_info_traverse_func(S32 pid, srv_um_msg_detail_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_thread_info_cntx_struct *cntx;
    ums_get_thread_info_para_struct *para;
    srv_um_get_thread_info_result *result;

    srv_um_thread_id_struct thread_id;
    srv_um_addr_struct *addr;
//    srv_um_thread_info_struct *thread_info;
//    S32 index;

    // TODO :

    S32 i, j;
    srv_um_msg_info_struct *msg_info;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_BUFFER_FULL;
    }

    cntx = process->cntx;
    para = process->para;
    result = process->result;

    msg_info = (srv_um_msg_info_struct*) get_ctrl_buffer(sizeof(srv_um_msg_info_struct));

    /* find all address in the message */
    for (addr = &message->address; addr != NULL ; addr = addr->next)
    {
        if (addr->group != SRV_UM_ADDR_GROUP_TO && addr->group != SRV_UM_ADDR_GROUP_FROM)
        {
            ASSERT(0);
            continue;
        }

    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        if (message->address.next != NULL)
        {
            srv_um_tsfr_msg_id_to_thread_id(message->msg_type, message->msg_id, &thread_id);
        }
        else
    #endif
        if (stack_get_active_module_id() == MOD_MMI)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_async_get_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_async_get_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }

        for (i = para->thread_number - 1; i >= 0 ; i--)
        {
            if (para->thread_list[i].type == thread_id.type
                && para->thread_list[i].value == thread_id.value
            #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
                && para->thread_list[i].sim_id == thread_id.sim_id
            #endif
                && cntx->msg_list[i].msg_type == message->msg_type
                && cntx->msg_list[i].msg_id == message->msg_id)
            {

                msg_info->msg_id = message->msg_id;
                msg_info->timestamp = message->timestamp;
                msg_info->address_type = addr->type;
                app_ucs2_strncpy((kal_int8*)msg_info->address, (kal_int8*)addr->addr, SRV_UM_MAX_ADDR_LEN);
                msg_info->address_length = app_ucs2_strlen((kal_int8*)msg_info->address);
                app_ucs2_strncpy((kal_int8*)msg_info->subject, (kal_int8*)message->subject, SRV_UM_MAX_SUBJECT_LEN);
                msg_info->subject_length = app_ucs2_strlen((kal_int8*)msg_info->subject);
                msg_info->thread_id.type = thread_id.type;
                msg_info->thread_id.value = thread_id.value;
            #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
                msg_info->thread_id.sim_id = thread_id.sim_id;
            #endif
            #ifdef __MMI_DUAL_SIM_MASTER__
                msg_info->sim_id = message->sim_id;
            #endif
                msg_info->msg_status = message->msg_status;

            #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
                msg_info->address_number = 1;
                msg_info->address_more = KAL_FALSE;

                if (message->address.next)
                {
                    srv_um_addr_struct *addr = message->address.next;

                    for (j = 0 ;j < SRV_UM_EXTEND_ADDRESS_NUM && addr!=NULL; j++, addr = addr->next)
                    {
                        msg_info->address_number++;
                        app_ucs2_strncpy((kal_int8*)msg_info->address_ext[j], (kal_int8*)addr->addr, SRV_UM_MAX_ADDR_LEN);
                    }

                    if (addr != NULL)
                    {
                        msg_info->address_more = KAL_TRUE;
                    }
                }
            #endif

                srv_um_cache_add(message->msg_type, message->msg_box_type, msg_info, 1);

                result->no_of_success++;

                memset(&cntx->msg_list[i], 0, sizeof(srv_um_msg_node_struct));

                break;
            }
        }

    /* only handle first address */
    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        break;
    #endif

    }

    free_ctrl_buffer(msg_info);

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_list_traverse_cb
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  rsp         [IN]    result
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_get_thread_info_traverse_cb(S32 pid, srv_um_traverse_msg_result* rsp, S32 user_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_thread_info_cntx_struct *cntx;
    ums_get_thread_info_para_struct *para;
    srv_um_get_thread_info_result *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(user_data, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(user_data)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    ASSERT(process->child == pid);

    cntx = process->cntx;
    para = process->para;
    result = process->result;

    result->no_of_fail = para->thread_number - result->no_of_success;

    result->error = rsp->error;

    if (rsp->error != SRV_UM_RESULT_OK)
    {
        ASSERT(0);
        cntx->pending_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    cntx->pending_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_list_msg_info_cb
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  rsp         [IN]    result
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_get_thread_info_msg_info_cb(S32 pid, srv_um_get_msg_info_result* rsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_thread_info_cntx_struct *cntx;
    srv_um_get_thread_info_result *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(user_data, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(user_data)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    ASSERT(process->child == pid);

    cntx = process->cntx;
    result = process->result;

    result->error = rsp->error;
    result->no_of_success = rsp->no_of_success;
    result->no_of_fail = rsp->no_of_fail;

    cntx->pending_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_info_rsp
 * DESCRIPTION
 *  Dummy Function
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_get_thread_info_rsp(ums_process_struct *process, srv_um_get_thread_info_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_UM_RESULT_OK;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_ms_thread_op_traverse_func
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  message     [IN]    message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_BUFFER_FULL       :   stop traverse message
 *  SRV_UM_RESULT_OK                :   continue to traverse message
 *****************************************************************************/
S32 srv_um_ms_thread_op_traverse_func(S32 pid, srv_um_msg_detail_struct* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_mark_several_thread_op_cntx_struct *cntx;
    ums_mark_several_thread_op_para_struct *para;

    srv_um_addr_struct *addr;
    srv_um_thread_id_struct thread_id;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_BUFFER_FULL;
    }

    cntx = process->cntx;
    para = process->para;

    /* insert all address into link list */
    for (addr = &message->address; addr != NULL ; addr = addr->next)
    {
    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        if (message->address.next != NULL)
        {
            srv_um_tsfr_msg_id_to_thread_id(message->msg_type, message->msg_id, &thread_id);
        }
        else
    #endif
        if (stack_get_active_module_id() == MOD_MMI)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_tsfr_address_to_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            srv_um_async_get_thread_id(addr->type, addr->addr, message->sim_id, &thread_id);
        #else
            srv_um_async_get_thread_id(addr->type, addr->addr, SRV_UM_SIM_UNCLASSIFIED, &thread_id);
        #endif
        }

        for (i = para->thread_list_size - 1 ; i >=0 ; i--)
        {
            U32 idx = i >> 5;
            U32 bit = 1 << (~i & 0x1F);

            if ((para->mark_status[idx] & bit) &&
                para->thread_list[i].type == thread_id.type
                && para->thread_list[i].value == thread_id.value
            #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
                && para->thread_list[i].sim_id == thread_id.sim_id
            #endif
                )
            {
                cntx->msg_list[cntx->msg_number].msg_type = message->msg_type;
                cntx->msg_list[cntx->msg_number].msg_id = message->msg_id;
				cntx->msg_number++;
                return SRV_UM_RESULT_OK;
            }
        }

    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        break;
    #endif

    }

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_ms_thread_op_traverse_cb
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  rsp         [IN]    result
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_ms_thread_op_traverse_cb(S32 pid, srv_um_traverse_msg_result* rsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    ums_get_msg_list_cntx_struct *cntx;
    srv_um_get_msg_list_result *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(user_data, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(user_data)];

    if (ISCANCELLING(process) || ISRESET(process))
    {
        return SRV_UM_RESULT_OK;
    }

    ASSERT(process->child == pid);

    cntx = process->cntx;
    result = process->result;

    result->error = rsp->error;

    if (rsp->error != SRV_UM_RESULT_OK)
    {
        ASSERT(0);
        cntx->pending_req_type = SRV_UM_MSG_NONE;
        return SRV_UM_RESULT_OK;
    }

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_ms_thread_op_traverse_cb
 * DESCRIPTION
 * PARAMETERS
 *  pid         [IN]    process id
 *  rsp         [IN]    result
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_ms_thread_op_ms_cb(S32 pid, srv_um_mark_several_op_result* rsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;
    srv_um_mark_several_op_result *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(user_data, {ASSERT(0); return SRV_UM_RESULT_OK;});

    process = &ums_process_tbl[INDEX_OF_PID(user_data)];

    ASSERT(process->child == pid);

    result = process->result;

    result->error = rsp->error;
    result->no_of_success = rsp->no_of_success;
    result->no_of_fail = rsp->no_of_fail;

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_mark_several_thread_op_rsp
 * DESCRIPTION
 *  Dummy Function
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_mark_several_thread_op_rsp(ums_process_struct *process, srv_um_mark_several_thread_op_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_UM_RESULT_OK;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_um_delete_folder_rsp
 * DESCRIPTION
 *  Response handler of "Delete Folder"
 * PARAMETERS
 *  process     [IN]    process to delete folder
 *  rsp         [IN]    response message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_delete_folder_rsp(ums_process_struct *process, srv_um_delete_folder_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_delete_folder_cntx_struct *cntx = process->cntx;

    /* ums_delete_folder_para_struct *para = process->para; */
    srv_um_delete_folder_result *result = process->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->running_req_type != rsp->msg_type)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    if (!rsp->result)
    {
        result->error = SRV_UM_RESULT_PARTIAL_READY;
        result->msg_box.msg_type &= ~(rsp->msg_type);
    }

    cntx->pending_req_type &= ~(rsp->msg_type);
    cntx->running_req_type = SRV_UM_MSG_NONE;

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_response_handler
 * DESCRIPTION
 *  The main function of response handler
 * PARAMETERS
 *  type        [IN]    type of process
 *  inMsg       [IN]    response message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_response_handler(ums_process_type_enum type, void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ums_p->running_process->type != type)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    /* give up the result if this action is been reset */
    if (!ISRESET(g_ums_p->running_process))
    {
        result = ums_process_type_tbl[type].rsp_handler(g_ums_p->running_process, inMsg);
    }
    else
    {
        result = SRV_UM_RESULT_OK;
    }

    MMI_TRACE(
        MMI_COMMON_TRC_G6_MSG,
        TRC_SRV_UM_RSP_HANDLER,
        g_ums_p->running_process->pid,
        g_ums_p->running_process->status,
        g_ums_p->running_process->type,
        result);

    if (result == SRV_UM_RESULT_OK)
    {
        SETWAITING(g_ums_p->running_process);
    }
    else
    {
        ASSERT(0);
        /* wrong response message or wrong response handler, just skip it */
        return result;
    }

    srv_um_scheduler();

    return SRV_UM_RESULT_OK;
}




/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_num_req
 * DESCRIPTION
 *  Request handler of "Get Message Number"
 * PARAMETERS
 *  process     [IN]    process to get message number
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_get_msg_num_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_num_cntx_struct *cntx = process->cntx;
    ums_get_msg_num_para_struct *para = process->para;
    srv_um_get_msg_num_result *result = process->result;

    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        cntx->pending_req_type = para->msg_type;
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
        result->sim_id = para->sim_id;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    for (i = 0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++)
    {	
	    srv_um_msg_enum msg_type = (srv_um_msg_enum)(1 << i);
        if ((cntx->pending_req_type & msg_type) && srv_um_check_ready_type(msg_type))
        {
            srv_um_get_msg_num_req_struct *req;

            req = (srv_um_get_msg_num_req_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_num_req_struct));

            req->msg_type = msg_type;
            req->app_id = 0;
        #ifdef __MMI_DUAL_SIM_MASTER__
            req->sim_id = para->sim_id;
        #endif

            cntx->running_req_type = msg_type;

            srv_um_send_message(msg_type, MSG_ID_MMI_UM_GET_MSG_NUM_REQ, req, NULL);
            return SRV_UM_RESULT_PROCESS_BUSY;
        }
    }

    /* there is pending request type, but the type is not ready */
    result->error = SRV_UM_RESULT_PARTIAL_READY;
    return SRV_UM_RESULT_PROCESS_FINISH;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_list_req
 * DESCRIPTION
 *  Request handler of "Get Message List"
 * PARAMETERS
 *  process     [IN]    process to get message list
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_get_msg_list_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_list_cntx_struct *cntx = process->cntx;
    ums_get_msg_list_para_struct *para = process->para;
    srv_um_get_msg_list_result *result = process->result;

    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        if (!ISREADY(process))
        {
            srv_um_cache_memory_return(process->pid);
            srv_um_listmgr_delete(cntx->list_cntx_id);
        }
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {

        if (para->msg_box.msg_box_type == SRV_UM_MSG_BOX_SIM)
        {
            cntx->pending_req_type = SRV_UM_MSG_SMS;
        }
        else
        {
            cntx->pending_req_type = para->msg_box.msg_type;
        }

        cntx->list_cntx_id = srv_um_listmgr_create(SRV_UM_LIST_TYPE_MSG_NODE, (void **)&cntx->msg_list);
        cntx->msg_list_size = SRV_UM_MAX_MSG_NUM;

    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        if (para->filter.thread_id.type != SRV_UM_HASH_NONE)
        {
            cntx->thread_info.thread_id = para->filter.thread_id;
            cntx->sort_idx_data = srv_um_cache_memory_borrow(process->pid , SRV_UM_LIST_SORT_MEMORY);
            memset(cntx->sort_idx_data, 0, SRV_UM_LIST_SORT_MEMORY);
        }
        else
    #endif
        {
            U8 *tmp;
            tmp = srv_um_cache_memory_borrow(process->pid , SRV_UM_LIST_SORT_MEMORY);
            cntx->timestamp_idx_data = (U32 *)tmp;
        #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
            cntx->list_idx_data = (srv_um_list_idx_data_union *)(tmp + SRV_UM_LIST_TIMESTAMP_MEMORY);
        #endif
            memset(cntx->timestamp_idx_data, 0, SRV_UM_LIST_SORT_MEMORY);
        }
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
        if (result->error != SRV_UM_RESULT_OK)
        {
            srv_um_listmgr_delete(cntx->list_cntx_id);
        }
        else
        {
            srv_um_listmgr_update_cntx(cntx->list_cntx_id, result->n.msg_number, para->msg_box, &(para->filter));
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
            if (para->filter.thread_id.type != SRV_UM_HASH_NONE)
            {
                srv_um_thread_info_update(&cntx->thread_info);
            }
        #endif
        }
        srv_um_cache_memory_return(process->pid);
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    if (para->filter.thread_id.type != SRV_UM_HASH_NONE)
    {
        srv_um_detail_field_enum field = SRV_UM_DETAIL_NONE;

    #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
        field |= srv_um_tsfr_idx_type_to_field(para->filter.idx_type);
    #endif
        field |= SRV_UM_DETAIL_MULTI_ADDRESS | SRV_UM_DETAIL_MSG_BOX | SRV_UM_DETAIL_TIMESTAMP | SRV_UM_DETAIL_READ_STATUS | SRV_UM_DETAIL_SIM_ID;
        field &= ~SRV_UM_DETAIL_ADDRESS; /* cannot use with SRV_UM_DETAIL_MULTI_ADDRESS */

        process->child = srv_um_traverse_msg(para->msg_box, NULL, 0, srv_um_get_msg_list_traverse_func,
            field, srv_um_get_msg_list_traverse_cb, process->pid);

        srv_um_set_process_priority(process->child, (ums_process_priority_enum)(process->priority - 1));

        return SRV_UM_RESULT_PROCESS_WAITING;
    }
    else
#endif
    {
        for (i=0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++)
        {
		    srv_um_msg_enum msg_type = (srv_um_msg_enum)(1 << i);
            if ((cntx->pending_req_type & msg_type) && srv_um_check_ready_type(msg_type))
            {
                srv_um_get_msg_list_req_struct *req;

                req = (srv_um_get_msg_list_req_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_list_req_struct));

                req->msg_type = msg_type;
                req->app_id = 0;
                req->msg_box_type = para->msg_box.msg_box_type;
                req->start_entry = cntx->finish_idx[i];
            #ifdef __MMI_DUAL_SIM_MASTER__
                req->sim_id = para->msg_box.sim_id;
            #endif

            #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
                req->list_idx_type = para->filter.idx_type;
            #endif

                cntx->running_req_type = msg_type;

                srv_um_send_message(msg_type, MSG_ID_MMI_UM_GET_MSG_LIST_REQ, req, NULL);
                return SRV_UM_RESULT_PROCESS_BUSY;
            }
        }
    }

    /* there is pending request type, but the type is not ready */
    result->error = SRV_UM_RESULT_PARTIAL_READY;
    srv_um_cache_memory_return(process->pid);
    srv_um_listmgr_delete(cntx->list_cntx_id);
    return SRV_UM_RESULT_PROCESS_FINISH;
}

#ifdef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_info_req
 * DESCRIPTION
 *  Request handler of "Get Message Information"
 * PARAMETERS
 *  process     [IN]    process to get message information
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_get_msg_info_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_info_cntx_struct *cntx = process->cntx;
    ums_get_msg_info_para_struct *para = process->para;
    srv_um_get_msg_info_result *result = process->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        cntx->pending_req_type = srv_um_support_msg_type();
        cntx->req_msg_number = 0;
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
         return SRV_UM_RESULT_PROCESS_FINISH;
    }

    process->child = srv_um_traverse_msg(
                        para->msg_box, 
                        para->msg_list, 
                        para->msg_number, 
                        srv_um_get_msg_info_traverse_func, 
                    #ifdef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
                        (srv_um_detail_field_enum)(SRV_UM_DETAIL_ALL ^ SRV_UM_DETAIL_ADDRESS), 
                    #else
                        (srv_um_detail_field_enum)(SRV_UM_DETAIL_ALL ^ SRV_UM_DETAIL_MULTI_ADDRESS), 
                    #endif
                        srv_um_get_msg_info_traverse_cb, process->pid);

    srv_um_set_process_priority(process->child, (ums_process_priority_enum)(process->priority - 1));

    return SRV_UM_RESULT_PROCESS_WAITING;
}

#else /* __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__ */

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_info_req
 * DESCRIPTION
 *  Request handler of "Get Message Information"
 * PARAMETERS
 *  process     [IN]    process to get message information
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_get_msg_info_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_info_cntx_struct *cntx = process->cntx;
    ums_get_msg_info_para_struct *para = process->para;
    srv_um_get_msg_info_result *result = process->result;

    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        cntx->pending_req_type = srv_um_support_msg_type();
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    for (i=0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++)
    {
	    srv_um_msg_enum msg_type = (srv_um_msg_enum)(1 << i);
        if ((cntx->pending_req_type & msg_type) && srv_um_check_ready_type(msg_type))
        {
            /* Old solution */
            srv_um_get_msg_info_req_struct *req;

            req = (srv_um_get_msg_info_req_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_info_req_struct));
            req->msg_type = msg_type;
            req->app_id = 0;
            req->msg_box_type = para->msg_box.msg_box_type;
            req->msg_number = 0;

            /* find next 5 msg to get msg info */
            for (j = cntx->finish_idx[i]; j < para->msg_number; j++)
            {
                if (para->msg_list[j].msg_type == msg_type)
                {
                    /* find it in cache first, and we only use fast search here to enhance performance */
                    if (!srv_um_cache_search(SRV_UM_LIST_TYPE_MSG_NODE, &para->msg_list[j], MMI_TRUE))
                    {
                        req->msg_id[req->msg_number++] = para->msg_list[j].msg_id;

                        if (req->msg_number >= SRV_UM_MAX_GET_MSG_INFO_NUMBER)
                        {
                            j++;
                            break;
                        }
                    }
                    else
                    {
                        result->no_of_success++;
                    }
                }
            }
            cntx->finish_idx[i] = j;
            cntx->running_msg_number = req->msg_number;

            if (req->msg_number == 0)
            {
                OslFreeDataPtr(req);
                cntx->pending_req_type &= ~msg_type;
            }
            else
            {
                cntx->running_req_type = msg_type;
                srv_um_send_message(msg_type, MSG_ID_MMI_UM_GET_MSG_INFO_REQ, req, NULL);
                return SRV_UM_RESULT_PROCESS_BUSY;
            }
        }
    }

    if (cntx->pending_req_type)
    {
        result->error = SRV_UM_RESULT_PARTIAL_READY;
    }

    return SRV_UM_RESULT_PROCESS_FINISH;
}
#endif  /* __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__ */

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_mark_several_op_req
 * DESCRIPTION
 *  Request handler of "Mark Several Operation"
 * PARAMETERS
 *  process     [IN]    process to do mark several operation
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_mark_several_op_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_mark_several_op_cntx_struct *cntx = process->cntx;
    ums_mark_several_op_para_struct *para = process->para;
    srv_um_mark_several_op_result *result = process->result;

    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->no_of_fail  = cntx->total_mark_item - result->no_of_success;
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        cntx->pending_req_type = srv_um_support_msg_type();

    #if 0   /* TODO in the future */
/* under construction !*/
/* under construction !*/
    #else /* 0 */
        srv_um_cache_clean(SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL);
    #endif /* 0 */

        for (i = para->msg_list_size - 1; i >=0 ; i--)
        {
            U32 idx = i >> 5;
            U32 bit = 1 << (~i & 0x1F);

            if (para->mark_status[idx] & bit)
            {
                cntx->total_mark_item++;
            }
        }
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    for (i = 0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++)
    {
	    srv_um_msg_enum msg_type = (srv_um_msg_enum)(1 << i);
        if ((cntx->pending_req_type & msg_type) &&
            srv_um_check_ready_type(msg_type) && cntx->finish_idx[i] < para->msg_list_size)
        {
            srv_um_mark_several_op_req_struct *req;

            req = (srv_um_mark_several_op_req_struct*) OslConstructDataPtr(sizeof(srv_um_mark_several_op_req_struct));

            req->msg_type = msg_type;
            req->app_id = 0;
            req->msg_box_type = para->msg_box.msg_box_type;
            req->action_type = para->action_type;
            req->msg_number = 0;

            /* find next 5 msg to get msg info */
            for (j = cntx->finish_idx[i]; j < para->msg_list_size; j++)
            {
                U32 idx = j >> 5;
                U32 bit = 1 << (~j & 0x1F);

                if (para->msg_list[j].msg_type == msg_type && (para->mark_status[idx] & bit))
                {

                    /*********************************************************************
                     * in "move to phone" case, if some messages belong to MMS, it should fail
                     * but we won't send primitive message to MMS now.
                     * special handling now
                     *******************************************************************/
                    if (para->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM ||
                        para->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE ||
                        para->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM ||
                        para->action_type == SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM)
                    {
                        if (msg_type != SRV_UM_MSG_SMS)
                        {
                            result->no_of_fail++;
                            continue;
                        }
                    }

                    req->msg_id[req->msg_number++] = para->msg_list[j].msg_id;

                    if (req->msg_number >= SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP)
                    {
                        j++;
                        break;
                    }
                }
            }

            cntx->finish_idx[i] = j;

            if (req->msg_number == 0)
            {
                OslFreeDataPtr(req);
                cntx->pending_req_type &= ~msg_type;
            }
            else
            {
                cntx->running_req_type = msg_type;
                srv_um_send_message(msg_type, MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ, req, NULL);
                return SRV_UM_RESULT_PROCESS_BUSY;
            }
        }
    }

    if (cntx->pending_req_type)
    {
        result->no_of_fail  = cntx->total_mark_item - result->no_of_success;
        /* there is pending request type, but the type is not ready */
        result->error = SRV_UM_RESULT_PARTIAL_READY;
    }

    return SRV_UM_RESULT_PROCESS_FINISH;
}
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_traverse_msg_req
 * DESCRIPTION
 * PARAMETERS
 *  process     [IN]    process to traverse message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_traverse_msg_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_traverse_msg_cntx_struct *cntx = process->cntx;
    ums_traverse_msg_para_struct *para = process->para;
    srv_um_traverse_msg_result *result = process->result;
    S32 i = 0, j = 0;

    srv_um_msg_enum msg_type;
    srv_um_msg_box_enum msg_box;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        if (para->msg_box.msg_box_type == SRV_UM_MSG_BOX_SIM)
        {
           cntx->pending_req_type = SRV_UM_MSG_SMS;
        }
        else
        {
            cntx->pending_req_type = para->msg_box.msg_type;
        }

        for (i = 0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++)
        {
            msg_type = (srv_um_msg_enum)(1 << i);
            if (cntx->pending_req_type & msg_type)
            {
                cntx->pending_req_box[i] = para->msg_box.msg_box_type;
            }
        }
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    if (para->msg_list != NULL)
    {
        goto index_traverse;
    }

    for (i = 0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++)
    {
        for (j = 0; j < SRV_UM_MAX_SUPPORT_MSG_BOX; j++)
        {
            msg_type = (srv_um_msg_enum)(1 << i);
            msg_box = (srv_um_msg_box_enum)(1 << j);
            if (cntx->pending_req_box[i] & msg_box)
            {
                srv_um_traverse_msg_req_struct *req;

                req = (srv_um_traverse_msg_req_struct*) OslConstructDataPtr(sizeof(srv_um_traverse_msg_req_struct));

                req->app_id = 0;
                req->msg_type = msg_type;
                req->start_entry = cntx->finish_idx[i][j];
                req->msg_box_type = msg_box;
                req->field = para->field;
                req->traverse_func = (srv_um_traverse_func)srv_um_traverse_base_func;
                req->user_data = process->pid;

                kal_get_time((kal_uint32*)&cntx->start_time);
                cntx->counter = 0;
                cntx->running_req_type = msg_type;
                cntx->running_req_box = msg_box;

                result->error = SRV_UM_RESULT_OK;

                srv_um_send_message(cntx->running_req_type, MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, req, NULL);
                return SRV_UM_RESULT_PROCESS_BUSY;
            }
        }

    }

    if (cntx->pending_req_type)
    {
        result->error = SRV_UM_RESULT_PARTIAL_READY;
    }

    return SRV_UM_RESULT_PROCESS_FINISH;

index_traverse:

    for (i = 0; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++)
    {
    	msg_type = (srv_um_msg_enum)(1 << i);
        if (cntx->pending_req_type & msg_type)
        {

            srv_um_traverse_msg_req_struct *req;

            req = (srv_um_traverse_msg_req_struct*) OslConstructDataPtr(sizeof(srv_um_traverse_msg_req_struct));

            req->app_id = 0;
            req->msg_type = msg_type;
            req->start_entry = -1;
            req->msg_box_type = para->msg_box.msg_box_type;
            req->field = para->field;
            req->traverse_func = (srv_um_traverse_func)srv_um_traverse_base_func;
            req->user_data = process->pid;
            req->msg_number = 0;

            /* find next 5 msg to get msg info */
            for (j = cntx->finish_idx[i][0]; j < para->msg_number; j++)
            {
                if (para->msg_list[j].msg_type == msg_type)
                {
                    req->msg_id[req->msg_number++] = para->msg_list[j].msg_id;

                    if (req->msg_number >= SRV_UM_MAX_TRAVERSE_MSG_NUMBER)
                    {
                        j++;
                        break;
                    }
                }
            }


            cntx->finish_idx[i][0] = j;

            if (req->msg_number == 0)
            {
                OslFreeDataPtr(req);
                cntx->pending_req_type &= ~msg_type;
            }
            else
            {
                cntx->request_number = req->msg_number;
                cntx->counter = 0;
                cntx->running_req_type = msg_type;
                kal_get_time((kal_uint32*)&cntx->start_time);

                result->error = SRV_UM_RESULT_OK;

                srv_um_send_message(cntx->running_req_type, MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, req, NULL);
                return SRV_UM_RESULT_PROCESS_BUSY;
            }
        }
    }

    if (cntx->pending_req_type)
    {
        result->error = SRV_UM_RESULT_PARTIAL_READY;
    }

    return SRV_UM_RESULT_PROCESS_FINISH;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_list_req
 * DESCRIPTION
 *  Request handler of "Get Message List"
 * PARAMETERS
 *  process     [IN]    process to get message list
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_get_thread_list_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_thread_list_cntx_struct *cntx = process->cntx;
    ums_get_thread_list_para_struct *para = process->para;
    srv_um_get_thread_list_result *result = process->result;

    srv_um_detail_field_enum field = SRV_UM_DETAIL_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        if (!ISREADY(process))
        {
            srv_um_listmgr_delete(cntx->list_cntx_id);
            srv_um_cache_memory_return(process->pid);
        }
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        cntx->pending_req_type = para->msg_box.msg_type;
        cntx->list_cntx_id = srv_um_listmgr_create(SRV_UM_LIST_TYPE_THREAD, (void**)&cntx->thread_list);
        cntx->thread_list_size = SRV_UM_MAX_MSG_NUM;
        cntx->sort_idx_data = srv_um_cache_memory_borrow(process->pid , SRV_UM_LIST_SORT_MEMORY);
        memset(cntx->sort_idx_data, 0, SRV_UM_LIST_SORT_MEMORY);
        srv_um_thread_info_init();
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
        if (result->error != SRV_UM_RESULT_OK)
        {
            srv_um_listmgr_delete(cntx->list_cntx_id);
        }
        else
        {
            srv_um_listmgr_update_cntx(cntx->list_cntx_id, result->n.msg_number, para->msg_box, &(para->filter));
        }
        srv_um_cache_memory_return(process->pid);
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    field |= srv_um_tsfr_idx_type_to_field(para->filter.idx_type);
#endif

    field |= SRV_UM_DETAIL_MULTI_ADDRESS | SRV_UM_DETAIL_MSG_BOX | SRV_UM_DETAIL_TIMESTAMP | SRV_UM_DETAIL_READ_STATUS | SRV_UM_DETAIL_SIM_ID;
    field &= ~SRV_UM_DETAIL_ADDRESS; /* cannot use with SRV_UM_DETAIL_MULTI_ADDRESS */

    process->child = srv_um_traverse_msg(para->msg_box, NULL, 0, srv_um_get_thread_list_traverse_func,
        field, srv_um_get_thread_list_traverse_cb, process->pid);

    srv_um_set_process_priority(process->child, (ums_process_priority_enum)(process->priority - 1));

    return SRV_UM_RESULT_PROCESS_WAITING;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_thread_info_req
 * DESCRIPTION
 *  Request handler of "Get Message Information"
 * PARAMETERS
 *  process     [IN]    process to get message information
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_get_thread_info_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_thread_info_cntx_struct *cntx = process->cntx;
    ums_get_thread_info_para_struct *para = process->para;
    srv_um_get_thread_info_result *result = process->result;
    S32 i, j;
    srv_um_detail_field_enum field = SRV_UM_DETAIL_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        cntx->pending_req_type = srv_um_support_msg_type();
        memset(cntx->msg_list, 0, sizeof(cntx->msg_list));
        memset(cntx->req_msg_list, 0, sizeof(cntx->req_msg_list));
        cntx->req_msg_number = 0;
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
         return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* generate the message list */
    for (i = 0; i < para->thread_number ; i++)
    {
        MMI_BOOL duplicated = MMI_FALSE;

        memcpy(&(cntx->msg_list[i]), &(srv_um_thread_info_search(para->thread_list[i])->list_head), sizeof(srv_um_msg_node_struct));
        /* search if duplicated */
        for (j = 0 ; j < cntx->req_msg_number; j++)
        {
            if (cntx->msg_list[i].msg_type == cntx->req_msg_list[j].msg_type &&
                cntx->msg_list[i].msg_id == cntx->req_msg_list[j].msg_id)
            {
                duplicated = MMI_TRUE;
                break;
            }
        }

        if (!duplicated)
        {
            memcpy(&cntx->req_msg_list[cntx->req_msg_number], &cntx->msg_list[i], sizeof(srv_um_msg_node_struct));
            cntx->req_msg_number++;
        }
    }

    field = (srv_um_detail_field_enum)(SRV_UM_DETAIL_MSG_BOX | SRV_UM_DETAIL_TIMESTAMP | SRV_UM_DETAIL_MULTI_ADDRESS | SRV_UM_DETAIL_SUBJECT | SRV_UM_DETAIL_SIM_ID | SRV_UM_DETAIL_MSG_STATUS);

    process->child = srv_um_traverse_msg(para->msg_box, cntx->req_msg_list, cntx->req_msg_number, srv_um_get_thread_info_traverse_func,
        field, srv_um_get_thread_info_traverse_cb, process->pid);

    srv_um_set_process_priority(process->child, (ums_process_priority_enum)(process->priority - 1));

    return SRV_UM_RESULT_PROCESS_WAITING;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_mark_several_thread_op_req
 * DESCRIPTION
 *  Request handler of "Mark Several Operation"
 * PARAMETERS
 *  process     [IN]    process to do mark several operation
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_mark_several_thread_op_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_mark_several_thread_op_cntx_struct *cntx = process->cntx;
    ums_mark_several_thread_op_para_struct *para = process->para;
    srv_um_mark_several_thread_op_result *result = process->result;
    srv_um_detail_field_enum field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        srv_um_listmgr_delete(cntx->msg_list_cid);
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        srv_um_cache_clean(SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL);
        cntx->msg_list_cid = srv_um_listmgr_create(SRV_UM_LIST_TYPE_MSG_NODE, (void **)&cntx->msg_list);
        cntx->msg_list_size = SRV_UM_MAX_MSG_NUM;
    }

    /* Finished */
    if (cntx->mark_status[0] == 0xFFFFFFFF)
    {
        srv_um_listmgr_delete(cntx->msg_list_cid);
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    if (cntx->start_timestamp == 0)
    {
        kal_get_time(&cntx->start_timestamp);
        field = (srv_um_detail_field_enum)(SRV_UM_DETAIL_MULTI_ADDRESS | SRV_UM_DETAIL_MSG_BOX | SRV_UM_DETAIL_TIMESTAMP | SRV_UM_DETAIL_SIM_ID);

        process->child = srv_um_traverse_msg(para->msg_box, NULL, 0, srv_um_ms_thread_op_traverse_func,
            field, srv_um_ms_thread_op_traverse_cb, process->pid);

        srv_um_set_process_priority(process->child, (ums_process_priority_enum)(process->priority - 1));
        return SRV_UM_RESULT_PROCESS_WAITING;
    }
    else
    {
        /* finish to get message list, now we use mark several op to delete or do something */
        memset(cntx->mark_status, 0xFF, sizeof(cntx->mark_status));

        process->child = srv_um_mark_several_op(para->msg_box, cntx->msg_list, cntx->msg_number,
            cntx->mark_status, para->action_type, srv_um_ms_thread_op_ms_cb, process->pid);

        srv_um_set_process_priority(process->child, (ums_process_priority_enum)(process->priority - 1));
        return SRV_UM_RESULT_PROCESS_WAITING;
    }
}
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_um_delete_folder_req
 * DESCRIPTION
 *  Request handler of "Delete Folder"
 * PARAMETERS
 *  process     [IN]    process to delete folder
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_delete_folder_req(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_delete_folder_cntx_struct *cntx = process->cntx;
    ums_delete_folder_para_struct *para = process->para;
    srv_um_delete_folder_result *result = process->result;

    S32 i = 0;
    srv_um_msg_enum msg_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISCANCELLING(process) || ISRESET(process))
    {
        result->error = SRV_UM_RESULT_CANCELLLED;
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    /* first enter */
    if (ISREADY(process))
    {
        if (para->msg_box.msg_box_type == SRV_UM_MSG_BOX_SIM)
        {
            cntx->pending_req_type = SRV_UM_MSG_SMS;
        }
        else
        {
            cntx->pending_req_type = para->msg_box.msg_type;
        }

        result->msg_box = para->msg_box;

        /* we need to clean the cache due to the data may be out of date */
        srv_um_cache_clean(SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL);
    }

    /* Finished */
    if (!cntx->pending_req_type)
    {
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    for (i = 0, msg_type = SRV_UM_MSG_SMS; i < SRV_UM_MAX_SUPPORT_MSG_TYPE; i++, msg_type <<= 1)
    {
        if ((cntx->pending_req_type & msg_type) && srv_um_check_ready_type(msg_type))
        {
            srv_um_delete_folder_req_struct *req;

            req = (srv_um_delete_folder_req_struct*) OslConstructDataPtr(sizeof(srv_um_delete_folder_req_struct));

            req->msg_type = msg_type;
            req->app_id = 0;
            req->msg_box_type = para->msg_box.msg_box_type;
            req->sim_id = para->msg_box.sim_id;

            cntx->running_req_type = msg_type;

            srv_um_send_message(msg_type, MSG_ID_MMI_UM_DELETE_FOLDER_REQ, req, NULL);
            return SRV_UM_RESULT_PROCESS_BUSY;
        }
    }

    /* there is pending request type, but the type is not ready */
    result->error = SRV_UM_RESULT_PARTIAL_READY;
    return SRV_UM_RESULT_PROCESS_FINISH;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_request_handler
 * DESCRIPTION
 *  The main function of request handler
 * PARAMETERS
 *  process     [IN]    the request process
 * RETURN VALUES
 *  SRV_UM_RESULT_PROCESS_FINISH    :   The process is finished.
 *  SRV_UM_RESULT_PROCESS_BUSY      :   The process is processing.
 *****************************************************************************/
S32 srv_um_request_handler(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (process->cntx == NULL || process->para == NULL || process->result == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
        SETFINISHED(process);
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    if (process->type >= UMS_PROCESS_TYPE_MAX)
    {
        EXT_ASSERT(0, 0, 0, 0);
        SETFINISHED(process);
        return SRV_UM_RESULT_PROCESS_FINISH;
    }

    SETRUNNING(process);

    if (ISREADY(process))
    {
        memset(process->cntx, 0, ums_process_type_tbl[process->type].cntx_size);
        memset(process->result, 0, ums_process_type_tbl[process->type].result_size);
    }

    result = ums_process_type_tbl[process->type].req_handler(process);

    if (ISRESET(process) && !ISCANCELLING(process))
    {
        memset(process->cntx, 0, ums_process_type_tbl[process->type].cntx_size);
        memset(process->result, 0, ums_process_type_tbl[process->type].result_size);
        SETREADY(process);
        SETRUNNING(process);
        result = ums_process_type_tbl[process->type].req_handler(process);
    }

    REMOVEREADY(process);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_REQ_HANDLER, process->pid, result);

    if (result == SRV_UM_RESULT_PROCESS_FINISH)
    {
        ums_general_para_struct *para = process->para;

        /* to prevent AP add new process in callback function */
        if (para->cb_func)
        {
            para->cb_func(process->pid, process->result, para->user_data);
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
#endif
        SETFINISHED(process);
    }
    else if (result == SRV_UM_RESULT_PROCESS_WAITING)
    {
        SETWAITING(process);
    }
//    else if (result == SRV_UM_RESULT_PROCESS_BUSY)
//    {
//        SETRUNNING(process);
//    }

    return result;
}

#define UMS_PROCESS


/*****************************************************************************
 * FUNCTION
 *  srv_um_clear_process
 * DESCRIPTION
 *  Clear process entry in process table
 * PARAMETERS
 *  process     [IN]    the process need to be cleaned
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_clear_process(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (process->cntx)
        free_ctrl_buffer(process->cntx);
    if (process->para)
        free_ctrl_buffer(process->para);
    if (process->result)
        free_ctrl_buffer(process->result);

    memset(process, 0, sizeof(ums_process_struct));

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_scheduler
 * DESCRIPTION
 *  The main function to control the execution of each process.  Maintain the process
 *  queue
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_scheduler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    ums_process_struct *process = NULL;
    srv_um_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

  reschedule:

    if (ISRUNNING(g_ums_p->running_process))
    {
        /* someone is running, no need reschedule now */
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_SCHEDULER_1);

        return SRV_UM_RESULT_OK;
    }

    /* find the highest priority process first */
    process = NULL;

    for (i = UMS_MAX_PROCESS - 1; i >= 0; i--)
    {
        if (ums_process_tbl[i].pid > 0)
        {
            if (process == NULL)
            {
                process = &ums_process_tbl[i];
            }
            /* this task priority is lower than original one, skip */
            else if (ums_process_tbl[i].priority > process->priority)
            {
                continue;
            }
            /* this task priority higher than original one */
            else if (ums_process_tbl[i].priority < process->priority)
            {
                process = &ums_process_tbl[i];
            }
            /* priority the same, but this process status is waiting */
            else if (ISWAITING(&ums_process_tbl[i]) && !ISWAITING(process))
            {
                process = &ums_process_tbl[i];
            }
            /* both process status is the same, check which one add into process first */
            else if (ums_process_tbl[i].status == process->status && ums_process_tbl[i].pid < process->pid)
            {
                process = &ums_process_tbl[i];
            }

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_SCHEDULER_2, i, ums_process_tbl[i].pid, ums_process_tbl[i].type);
        }
    }

    /* there is no process need to handle, enter idle mode */
    if (process == NULL)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_SCHEDULER_DONE);

        g_ums_p->running_process = &ums_process_tbl[0];
        return SRV_UM_RESULT_OK;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_SCHEDULER, process->pid, process->status, process->type);

    /* the process is running, record it into global context to handle the response message */
    g_ums_p->running_process = process;

    /* handle the process, but if we finish the process in the handler
       we need to find next process */
    result = (srv_um_result_enum)srv_um_request_handler(process);

    if (result == SRV_UM_RESULT_PROCESS_FINISH)
    {
        if (g_ums_p->is_create_process)
        {
            /* if first enter and then fail. may cause some serious problem in ap side */
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_REQ_HANDLER_FIRST_ENTER_FAIL, (S32)(((ums_general_para_struct *)process->para)->cb_func));
        }

        ASSERT(ISFINISHED(process));

        srv_um_clear_process(process);

        g_ums_p->is_create_process = MMI_FALSE;

        goto reschedule;
    }
    else if (result == SRV_UM_RESULT_PROCESS_WAITING)
    {
        g_ums_p->is_create_process = MMI_FALSE;

        goto reschedule;
    }

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_create_process
 * DESCRIPTION
 *  Find a empty entry in process table and initiate it.
 * PARAMETERS
 *  type        [IN]    type of process
 *  para        [OUT]   pointer of parameter buffer
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  >0: process id
 *  <0: error
 *****************************************************************************/
S32 srv_um_create_process(ums_process_type_enum type, void **para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 ticks;
    ums_process_struct *process = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < UMS_MAX_PROCESS; i++)
    {
        if (ums_process_tbl[i].pid == 0 && ISINIT(&ums_process_tbl[i]))
        {
            process = &ums_process_tbl[i];

            memset(process, 0, sizeof(ums_process_struct));

            kal_get_time(&ticks);
            process->pid = CREATE_PID(ticks, i);
            process->type = type;
            process->para = get_ctrl_buffer(ums_process_type_tbl[type].para_size);
            process->cntx = get_ctrl_buffer(ums_process_type_tbl[type].cntx_size);
            process->result = get_ctrl_buffer(ums_process_type_tbl[type].result_size);
            process->priority = UMS_PROCESS_PRIORITY_DEFAULT;

            memset(process->para, 0, ums_process_type_tbl[type].para_size);
            memset(process->cntx, 0, ums_process_type_tbl[type].cntx_size);
            memset(process->result, 0, ums_process_type_tbl[type].result_size);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CREATE_PROCESS, process->pid, process->type);

            break;
        }
    }

    if (process == NULL)
    {
        ASSERT(0);
        return SRV_UM_RESULT_TOO_MANY_PROCESS;
    }

    *para = process->para;

    return process->pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_start_process
 * DESCRIPTION
 *  Set the process to ready status and enter scheduler.
 * PARAMETERS
 *  pid     [IN]    process id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_start_process(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_INVALID_PID;});

    SETREADY(&ums_process_tbl[INDEX_OF_PID(pid)]);

    g_ums_p->is_create_process = MMI_TRUE;

    result = srv_um_scheduler();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_START_PROCESS, result);

    g_ums_p->is_create_process = MMI_FALSE;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cancel_process
 * DESCRIPTION
 *  Cancel a process
 * PARAMETERS
 *  pid     [IN]    process id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cancel_process(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_INVALID_PID;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    if (ISFINISHED(process) || ISINIT(process))
    {
        ASSERT(0);
        return SRV_UM_RESULT_INVALID_PID;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CANCEL_PROCESS, process->pid, process->status);

    SETCANCELLING(process);

    if (process->child)
    {
        srv_um_cancel_process(process->child);
    }

    /* if the process is in ready status, we can clean it eariler */
    if (ISREADY(process))
    {
        if (srv_um_request_handler(process) == SRV_UM_RESULT_PROCESS_FINISH)
        {
            srv_um_clear_process(process);
        }
        else
        {
            /* Impossible case */
            EXT_ASSERT(0,0,0,0);
        }
    }

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_reset_process
 * DESCRIPTION
 *  Reset a process
 * PARAMETERS
 *  pid     [IN]    process id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_reset_process(ums_process_struct *process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ISFINISHED(process) || ISINIT(process))
    {
        return SRV_UM_RESULT_INVALID_PID;
    }

    if (!ISREADY(process))
    {
        SETRESET(process);

        if (process->child)
        {
            srv_um_cancel_process(process->child);
        }
    }

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_process_status
 * DESCRIPTION
 *  To get the status of a specific process
 * PARAMETERS
 *  pid     [IN]    process id
 * RETURNS
 *  The status of process, ums_process_status_enum
 * RETURN VALUES
 *  UMS_PROCESS_STATUS_INIT
 *****************************************************************************/
S32 srv_um_get_process_status(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_INVALID_PID;});

    return ums_process_tbl[INDEX_OF_PID(pid)].status;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_set_process_priotiy
 * DESCRIPTION
 *  Set new prority to proces
 * PARAMETERS
 *  pid        [IN]     process id
 *  priority   [IN]     new priority
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK: success
 *  other: fail
 *****************************************************************************/
S32 srv_um_set_process_priority(S32 pid, ums_process_priority_enum priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_INVALID_PID;});

    if (priority > UMS_PROCESS_PRIORITY_LOWEST || priority <= UMS_PROCESS_PRIORITY_NONE)
    {
        ASSERT(0);
        return SRV_UM_RESULT_INVALID_PARA;
    }

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    process->priority = priority;

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_process_progress
 * DESCRIPTION
 *  get the progress of the process
 * PARAMETERS
 *  pid             [IN]    process id
 *  finish_number   [OUT]   number of finish item
 *  total_number    [OUT]   number of total item
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_get_process_progress(S32 pid, S32 *finish_number, S32 *total_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_process_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CHECK_PID_VALID(pid, {ASSERT(0); return SRV_UM_RESULT_INVALID_PID;});

    process = &ums_process_tbl[INDEX_OF_PID(pid)];

    if (ISFINISHED(process) || ISINIT(process))
    {
        ASSERT(0);
        return SRV_UM_RESULT_INVALID_PID;
    }

    switch(process->type)
    {
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    case UMS_PROCESS_TYPE_MARK_SEVERAL_OP:
    {
        ums_mark_several_op_cntx_struct *cntx = process->cntx;
        srv_um_mark_several_op_result *result = process->result;

        *finish_number = result->no_of_fail + result->no_of_success;
        *total_number = cntx->total_mark_item;
    }
    break;
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    case UMS_PROCESS_TYPE_TRAVERSE_MSG:
    {
        *finish_number = *total_number = 0;
    }
    break;

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    case UMS_PROCESS_TYPE_MARK_SEVERAL_THREAD_OP:
    {
        if (process->child)
        {
            srv_um_get_process_progress(process->child, finish_number, total_number);
        }
        else
        {
            *finish_number = *total_number = 0;
        }
    }
    break;
#endif
#endif

    default:
        EXT_ASSERT(0,0,0,0);
    }

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_service_init
 * DESCRIPTION
 *  To initiate the unified message service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void srv_um_service_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ums_p, 0, sizeof(g_ums_p));
    memset(&g_ums_cntx, 0, sizeof(ums_context_struct));
    memset(ums_process_tbl, 0, sizeof(ums_process_tbl));

    srv_um_set_protocol_event_handler();

    g_ums_p->running_process = &ums_process_tbl[0]; /* idle mode */

    #ifndef __SRV_UM_UT__
    g_ums_p->support_type = SRV_UM_MSG_SMS
                        #ifdef __MMI_MMS_IN_UM__
                            | SRV_UM_MSG_MMS
                        #endif
                        #ifdef __MMI_PUSH_IN_UM__
                            | SRV_UM_MSG_WAP_PUSH
                        #endif
                        #ifdef __MMI_PROV_IN_UM__
                            | SRV_UM_MSG_PROV
                        #endif
                            ;
    #else
    g_ums_p->support_type = SRV_UM_MSG_UT;
    g_ums_p->ready_type = SRV_UM_MSG_UT;
    #endif

    srv_um_cache_init();
    srv_um_listmgr_init();

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    srv_um_thread_info_init();
#endif

    g_ums_p->event_group = kal_create_event_group("MMI UM");

    g_ums_p->is_create_process = MMI_FALSE;
    
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_MSG, srv_um_sms_msg_common_event_proc, NULL);
#endif
}

#ifdef __COSMOS_MMI_PACKAGE__
typedef struct 
{
    srv_sms_box_enum sms_box;
    srv_um_msg_box_enum um_box;
}srv_um_sms_box_pair;

static const srv_um_sms_box_pair srv_um_sms_box_map[] = 
{
    {SRV_SMS_BOX_INBOX, SRV_UM_MSG_BOX_INBOX},
    {SRV_SMS_BOX_UNSENT, SRV_UM_MSG_BOX_UNSENT},
    {SRV_SMS_BOX_OUTBOX, SRV_UM_MSG_BOX_SENT},
    {SRV_SMS_BOX_DRAFTS, SRV_UM_MSG_BOX_DRAFT},
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__  
    {SRV_SMS_BOX_ARCHIVE, SRV_UM_MSG_BOX_ARCHIVE},
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    {SRV_SMS_BOX_SIM, SRV_UM_MSG_BOX_SIM},
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        
#ifdef __MMI_UM_REPORT_BOX__
    {SRV_SMS_BOX_REPORT, SRV_UM_MSG_BOX_REPORT},
#endif /* __MMI_UM_REPORT_BOX__ */
    {SRV_SMS_BOX_NONE, SRV_UM_MSG_BOX_NONE}
};


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_sms_box_to_um
 * DESCRIPTION
 *  convert the SMS box type to UM type
 * PARAMETERS
 *  msg_box_type        [IN]  	sms app box type      
 * RETURNS
 *  void
 *****************************************************************************/
srv_um_msg_box_enum srv_um_sms_box_to_um(srv_sms_box_enum sms_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S32 total = sizeof(srv_um_sms_box_map) / sizeof(srv_um_sms_box_pair);
    for (; index < total; ++index)
    {
        if (sms_box_type == srv_um_sms_box_map[index].sms_box)
        {
            break;
        }
    }
    MMI_ASSERT(index <= total);
    return srv_um_sms_box_map[index].um_box;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_sms_msg_common_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret srv_um_sms_msg_common_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready())
    {
        switch(event_data->evt_id)
        {
            case EVT_ID_SRV_SMS_UPDATE_MSG:
            {
                srv_sms_event_update_struct *event_info;
                srv_um_msg_box_enum src_box_type;
                srv_um_msg_box_enum dest_box_type;

                event_info = (srv_sms_event_update_struct*)event_data->event_info;      

                src_box_type = srv_um_sms_box_to_um(srv_sms_get_list_type(
                                    event_info->old_msg_info.status,
                                    event_info->old_msg_info.storage_type,
                                    event_info->old_msg_info.folder_id));

                dest_box_type = srv_um_sms_box_to_um(srv_sms_get_list_type(
                                    event_info->new_msg_info.status,
                                    event_info->new_msg_info.storage_type,
                                    event_info->new_msg_info.folder_id));

                if ((event_info->change_para_flag == SRV_SMS_PARA_STATUS) && 
                    ((event_info->old_msg_info.status & SRV_SMS_STATUS_UNREAD) ||
                     (event_info->old_msg_info.status & SRV_SMS_STATUS_READ)))
                {
					srv_um_notify_refresh_evt_struct evt;
                    srv_um_refresh_ind_interanl(SRV_UM_REFRESH_MSG_STATUS_CHANGED, SRV_UM_MSG_SMS, (srv_um_msg_box_enum)(src_box_type | dest_box_type));
                    /* new solution for callback manager. */
					MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UM_NOTIFY_REFRESH);
					evt.msg_box_type = (srv_um_msg_box_enum)(src_box_type | dest_box_type);
					evt.msg_type = SRV_UM_MSG_SMS;
					evt.msg_id = event_info->msg_id;
					evt.refresh_type = SRV_UM_REFRESH_MSG_STATUS_CHANGED;
					MMI_FRM_CB_EMIT_POST_EVENT(&evt);
				}
                break;
            }

        }
    }

    return MMI_RET_OK;
}
#endif /* __COSMOS_MMI_PACKAGE__ */
