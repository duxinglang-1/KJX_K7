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
 *  SmsUtilSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Utility
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "mmi_cb_mgr_gprot.h"
#include "kal_trace.h"

#include "ps_public_struct.h"
#include "l4c2abm_struct.h"
#include "ps_public_enum.h"
#include "mmi_msg_context.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "Csmcc_enums.h"
#include "nvram_common_defs.h"
#include "ProtocolEvents.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "SmsBtMapCSrvGProt.h"
#include "SmsBtMapCSrvUtil.h"
#include "SmsBtMapCsrvStorage.h"
#include "ems.h"
#include "gui_data_types.h"
#include "Gsm7BitNationalLang.h"
#include "mmi_rp_srv_sms_btmapc_def.h"
#include "ps_public_enum.h"
#include "MMI_trc_Int.h"
#include "common_nvram_editor_data_item.h"
#include "App_usedetails.h"
#include "ModeSwitchSrvGprot.h"

#ifdef __SMS_R8_NATION_LANGUAGE__
#include "SSCStringHandle.h"
#include "Lang_interface.h"
#endif
#include "PhbSrvGprot.h"

#ifdef __SRV_SMS_BTMAPC__
/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_MAX_INT_EVENT_NUM       15
#define SRV_SMS_MAX_HANDLE              20

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U16 event_id;
    SrvSmsEventFunc int_event_func;
    void *user_data;
} srv_sms_btmapc_int_event_struct;


typedef struct
{
    void *cntx;
} sms_btmapc_handle_node_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 

/**************************************************************
* Extern Function Declaration
**************************************************************/
#ifdef __SMS_R8_NATION_LANGUAGE__
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
#endif /* __SMS_R8_NATION_LANGUAGE__ */
extern EMSTATUS EMSCalculateSegEx(kal_uint8   dcs,
                                  EMSNationalLanguage *lang,
                                  kal_uint16  num_byte,
                                  kal_uint8   *usedSegment);
extern EMSTATUS EMSCalculateLastSegRemainingChar(kal_uint8   dcs,
                                                 EMSNationalLanguage *lang,
                                                 kal_uint16  num_byte,
                                                 kal_uint8   *last_seg_remaining);
extern kal_uint16 EMSUsableTextLenEx(kal_uint8 dcs, EMSNationalLanguage *lang);


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_btmapc_int_event_struct srv_sms_int_event_list[SRV_SMS_MAX_INT_EVENT_NUM];
static U8 curr_int_event_num; 

static sms_btmapc_handle_node_struct handle_node_list[SRV_SMS_MAX_HANDLE];

/**************************************************************
* Static Function Declaration
**************************************************************/
static sms_btmapc_handle_node_struct* srv_sms_btmapc_get_unused_cntx_node(void);
static sms_btmapc_handle_node_struct* srv_sms_btmapc_find_cntx_node(void* cntx);


/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_ucs2_number
 * DESCRIPTION
 *  check if the number is valid
 * PARAMETERS
 *  ucs2_num         [IN]       number (UCS2 Format)
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_check_ucs2_number(char* ucs2_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *asc_num;
    U32 len = 0;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((const CHAR *)ucs2_num);
    asc_num = OslMalloc(len + 1);
    mmi_ucs2_to_asc((CHAR *)asc_num, (CHAR *)ucs2_num);
    result = srv_sms_btmapc_check_dst_number((U8 *)asc_num, (U8)len);
    OslMfree(asc_num);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_read_msg_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_read_cntx_struct *read_cntx;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    MMI_BOOL result = callback_data->result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_cntx = (srv_sms_btmapc_read_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_CALLBACK, callback_data->result, read_cntx->curr_index);

    if (CNTX_IS_ABORT(read_cntx))
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }
    
    if (result)
    {
        srv_sms_btmapc_read_msg_succ_hdlr(read_cntx);
    }
    else
    {
        srv_sms_btmapc_read_msg_error_hdlr(read_cntx, error_cause);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_succ_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_read_msg_succ_hdlr(srv_sms_btmapc_read_cntx_struct* read_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_read_msg_cb_struct read_msg_cb_data;
    U16 msg_id = read_cntx->msg_id;
    MMI_BOOL is_update_succ = read_cntx->change_status;
    MMI_BOOL int_result = MMI_FALSE;
    srv_sms_event_update_struct *event_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_SUCC_HDLR);


    read_cntx->msg_data->status = srv_sms_btmapc_get_msg_status(msg_id);
    read_cntx->msg_data->folder_id = SRV_SMS_FOLDER_DEFAULT;

    read_msg_cb_data.msg_data = read_cntx->msg_data;    

    if (is_update_succ == MMI_TRUE)
    {
        srv_sms_btmapc_msg_node_struct *msg_node;
        event_data = OslMalloc(sizeof(srv_sms_event_update_struct));
        
        /* Get Old Msg Info */
        srv_sms_btmapc_get_msg_info(&event_data->old_msg_info, msg_id);
        msg_node = srv_sms_btmapc_get_msg_node(msg_id);
        /* Change Msg Status to READ */
        msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | SRV_SMS_STATUS_READ;            

        event_data->msg_id = msg_id;
        event_data->change_para_flag = SRV_SMS_PARA_STATUS;
        srv_sms_btmapc_get_msg_info(&event_data->new_msg_info, msg_id);

        int_result = srv_sms_btmapc_exec_interrupt_event(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, event_data);
    }
    srv_sms_btmapc_cntx_callback(
        read_cntx,
        result,
        error_cause,
        &read_msg_cb_data);

    if ((is_update_succ == MMI_TRUE) && (int_result == MMI_FALSE))
    {
        srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_UPDATE_MSG, event_data);
    }

    if (event_data != NULL)
    {
        OslMfree(event_data);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_read_msg_error_hdlr(
                srv_sms_btmapc_read_cntx_struct* read_cntx,
                srv_sms_cause_enum error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct read_msg_cb_data;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_ERROR_HDLR);

    read_msg_cb_data.msg_data = read_cntx->msg_data;    
    if (CNTX_IS_ABORT(read_cntx))
    {
        result = MMI_TRUE;
    }
    
    srv_sms_btmapc_cntx_callback(
        read_cntx,
        result,
        error_cause,
        &read_msg_cb_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_check_sms_handle(SMS_HANDLE sms_handle, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *handle = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->action == action)
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
 *  srv_sms_btmapc_alloc_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void* srv_sms_btmapc_alloc_cntx(
        U32 size,
        srv_sms_action_enum action,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_btmapc_handle_node_struct *cntx_node;
    srv_sms_btmapc_handle_struct *cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ALLOC_CNTX, size, action, callback_func, user_data);

    MMI_ASSERT(size >= sizeof(srv_sms_btmapc_handle_struct));

    cntx_node = srv_sms_btmapc_get_unused_cntx_node();

    if (cntx_node != NULL)
    {
        cntx = (srv_sms_btmapc_handle_struct*)OslMalloc(size);

        cntx->action = action;
        cntx->is_abort = MMI_FALSE;
        cntx->hd_data = NULL;
        cntx->abort_func = NULL;
        cntx->abort_user_data = NULL;
        cntx->callback_func = callback_func;
        cntx->user_data = user_data;
        cntx->sub_handle = NULL;
        cntx->sub_abort_func = NULL;
        cntx->sub_user_data = NULL;

        cntx_node->cntx = cntx;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ALLOC_CNTX_1, cntx);

    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_free_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_free_cntx(void* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_btmapc_handle_node_struct *cntx_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FREE_CNTX, cntx);

    cntx_node = srv_sms_btmapc_find_cntx_node(cntx);

    if (cntx_node != NULL)
    {
        cntx_node->cntx = NULL;
        OslMfree(cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_cntx_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static sms_btmapc_handle_node_struct* srv_sms_btmapc_get_unused_cntx_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_btmapc_find_cntx_node(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_find_cntx_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static sms_btmapc_handle_node_struct* srv_sms_btmapc_find_cntx_node(void* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_btmapc_handle_node_struct *node = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SMS_MAX_HANDLE; i++)
    {
        if (handle_node_list[i].cntx == cntx)
        {
            node = &handle_node_list[i];
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_CNTX_NODE, node);

    return node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_abort
 * DESCRIPTION
 *  1. Abort an action (Read/Send/Save, etc); 
 *     In current version, it is only can abort a read action.
 *  2. The abort is a async operation, and it may be failed. The result is returned
 *     in the callback function of the aborted action(ex. Read).
 *     If the result is FALSE, and the cause is SRV_SMS_CAUSE_ABORT. it means the
 *     abort is success. Otherwise, the abort is failed.
 *  3. The callback function of the aborted action (Read/Send/Save, etc) will be called even if abort it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_abort(
        SMS_HANDLE handle,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ABORT, handle, callback_func, user_data);

    if ((handle != SRV_SMS_INVALID_HANDLE) && 
        (handle != SRV_SMS_RESERVED_HANDLE))
    {
        sms_btmapc_handle_node_struct *cntx_node;
        srv_sms_btmapc_handle_struct *cntx = (srv_sms_btmapc_handle_struct*)handle;

        cntx_node = srv_sms_btmapc_find_cntx_node(cntx);

        if (cntx_node != NULL)
        {
            cntx->is_abort = MMI_TRUE;
            cntx->abort_func = callback_func;
            cntx->abort_user_data = user_data;
            if (cntx->sub_handle != SRV_SMS_INVALID_HANDLE)
            {
                srv_sms_btmapc_abort(
                    cntx->sub_handle,
                    cntx->sub_abort_func,
                    cntx->sub_user_data);
            }
        }
    }
    else
    {
        srv_sms_btmapc_async_callback(
            SRV_SMS_ACTION_NONE,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            NULL,
            0,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_user_data
 * DESCRIPTION
 *  Get a Handle's user data of an action
 * PARAMETERS
 *  handle      [IN]        SMS_HANDLE
 * RETURNS
 *  void*
 *****************************************************************************/
void* srv_sms_btmapc_get_user_data(SMS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((handle != SRV_SMS_INVALID_HANDLE) && 
        (handle != SRV_SMS_RESERVED_HANDLE))
    {
        srv_sms_btmapc_handle_struct *cntx = (srv_sms_btmapc_handle_struct*)handle;

        user_data = cntx->user_data;
    }

    return user_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_cntx_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_cntx_callback(
        void *cntx,
        MMI_BOOL result,
        srv_sms_cause_enum cause,
        void *action_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_cntx = (srv_sms_btmapc_handle_struct*)cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CNTX_CALLBACK, cntx, result, cause);

    if (sms_cntx)
    {
        SrvSmsCallbackFunc callback_func;
        srv_sms_action_enum action = sms_cntx->action;
        void *user_data;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CNTX_CALLBACK_1, sms_cntx->is_abort);

        if (sms_cntx->is_abort)
        {
            callback_func = sms_cntx->abort_func;
            user_data = sms_cntx->abort_user_data;
        }
        else
        {
            callback_func = sms_cntx->callback_func;
            user_data = sms_cntx->user_data;
        }

        srv_sms_btmapc_free_cntx(sms_cntx);

        if (callback_func)
        {
            srv_sms_callback_struct cb_data;

            cb_data.result = result;
            cb_data.cause = cause;
            cb_data.action_data = action_data;
            cb_data.action = action;
            cb_data.user_data = user_data;

            callback_func(&cb_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_int_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_btmapc_int_msg_data_struct* srv_sms_btmapc_get_int_msg_data(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sms_hd->action)
    {
        case SRV_SMS_ACTION_SEND:
        {
            srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;

            int_msg_data = &send_hd->msg_data;
            break;
        }

        case SRV_SMS_ACTION_UPDATE:
        case SRV_SMS_ACTION_SAVE:
        {
            int_msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);
            break;
        }

        default:
            break;
    }

    return int_msg_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_alloc_int_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_btmapc_int_msg_data_struct* srv_sms_btmapc_alloc_int_msg_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = OslMalloc(sizeof(srv_sms_btmapc_int_msg_data_struct));

    memset(msg_data, 0, sizeof(srv_sms_btmapc_int_msg_data_struct));

    msg_data->sim_id = SRV_SMS_SIM_1;
    msg_data->status = SRV_SMS_STATUS_DRAFT;
    msg_data->storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    msg_data->is_allow_num_emtpy = MMI_TRUE;
    msg_data->is_allow_sc_emtpy = MMI_TRUE;

    return msg_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_free_int_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/

void srv_sms_btmapc_free_int_msg_data(srv_sms_btmapc_int_msg_data_struct *msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    OslMfree(msg_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sms_handle       [IN]               
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_status(SMS_HANDLE sms_handle, srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((sms_hd->action == SRV_SMS_ACTION_SAVE) ||
        (sms_hd->action == SRV_SMS_ACTION_UPDATE))
    {
        srv_sms_btmapc_int_msg_data_struct *msg_data;

        msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);

        msg_data->status = status;
        msg_data->para_flag |= SRV_SMS_PARA_STATUS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_set_address(SMS_HANDLE sms_handle, char *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_NUM;

        mmi_ucs2ncpy(int_msg_data->number, ucs2_addr, SRV_SMS_MAX_ADDR_LEN);
    #ifdef __SRV_SMS_MULTI_ADDR__
        int_msg_data->addr_num++;
    #endif /* __SRV_SMS_MULTI_ADDR__ */
    }

    len = mmi_ucs2strlen(ucs2_addr);

    if ((len == 0) || (len > SRV_SMS_MAX_ADDR_LEN))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_append_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_append_address(
        SMS_HANDLE sms_handle,
        WCHAR* ucs2_addr,
        srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_set_address(sms_handle, (S8*)ucs2_addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content
 * DESCRIPTION
 *  set content.
 *  The default content will consider as unicode text; 
 *  And its default DCS is GSM Default 7Bit.
 *  If you want the specify the DCS, you need to call API srv_sms_set_content_dcs()
 *  to set the DCS. 
 *  For the 8Bit DCS (SRV_SMS_DCS_8BIT), the content will consider as binary Data.
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_content(SMS_HANDLE sms_handle, char *content_buff, U16 content_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;
        int_msg_data->content_buff = content_buff;
        int_msg_data->content_buff_size = content_size;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_dcs
 * DESCRIPTION
 *  IF send content is UCS2 or 8BIT character, need set DCS. 7BIT character content no need set.
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_content_dcs(SMS_HANDLE sms_handle, srv_sms_dcs_enum dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_DCS;
        int_msg_data->dcs = dcs;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_file
 * DESCRIPTION
 *  set content file path,file path dcs is UCS2, but file content default is 7BIT characters. 
 *  If content is UCS2 or 8BIT characters, must use srv_sms_set_content_dcs() set DCS, 
 *  otherwise no need set DCS.
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_content_file(SMS_HANDLE sms_handle, char *content_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CONTENT_FILE;
        int_msg_data->content_file_path = content_file_path;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_ems
 * DESCRIPTION
 *  Only for SMS internal use to send SMS
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_content_ems(SMS_HANDLE sms_handle, void *content_ems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CONTENT_EMS;
        int_msg_data->content_ems = (EMSData*)content_ems;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_data_port
 * DESCRIPTION
 *  Set port number
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_data_port(SMS_HANDLE sms_handle, U16 src_port, U16 dest_port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->src_port = src_port;
        int_msg_data->dest_port = dest_port;
        int_msg_data->para_flag |= SRV_SMS_PARA_PORT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_sim_id(SMS_HANDLE sms_handle, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sms_hd->action)
    {
        case SRV_SMS_ACTION_SEND:
        {
            srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;

            send_hd->sim_id = sim_id;
            break;
        }

        case SRV_SMS_ACTION_SAVE:
        case SRV_SMS_ACTION_UPDATE:
        {
            srv_sms_btmapc_int_msg_data_struct *msg_data;

            msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);
            msg_data->sim_id = sim_id;
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_status_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_status_report(SMS_HANDLE sms_handle, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_STATUS_REPORT;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_STATUS_REPORT;
        int_msg_data->status_report = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sc_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_set_sc_address(SMS_HANDLE sms_handle, char* sc_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_SCA;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_SCA;

        mmi_ucs2ncpy(int_msg_data->sc_address, sc_addr, SRV_SMS_MAX_ADDR_LEN);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_pid(SMS_HANDLE sms_handle, srv_sms_pid_enum pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_PID;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_PID;
        int_msg_data->pid = pid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_vp
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_vp(SMS_HANDLE sms_handle, srv_sms_vp_enum vp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_VP;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_VP;
        int_msg_data->vp = vp;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_class_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_class_type(SMS_HANDLE sms_handle, srv_sms_class_enum class_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CLASS;
        int_msg_data->class = class_type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_mms
 * DESCRIPTION
 *  Set more message to send para
 * PARAMETERS
 *  is_set          [IN]        
 *  sms_handle     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_mms(SMS_HANDLE sms_handle, MMI_BOOL is_mms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->is_mms = is_mms;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_reply_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_set          [IN]        
 *  sms_handle     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_reply_path(SMS_HANDLE sms_handle, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_REPLY_PATH;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
        int_msg_data->status_report = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_reply_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_reply_msg_id(SMS_HANDLE sms_handle, U16 reply_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->reply_msg_id = reply_msg_id;
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_sms_set_send_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_send_type(SMS_HANDLE sms_handle, srv_sms_send_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_btmapc_send_handle_struct *send_hd = (srv_sms_btmapc_send_handle_struct*)sms_hd->hd_data;
        send_hd->send_type = type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_save_timestamp
 * DESCRIPTION
 *  Only for Save message
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_set_save_timestamp(SMS_HANDLE sms_handle, MYTIME* timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        memcpy(&(int_msg_data->timestamp), timestamp, sizeof(MYTIME));
        
        int_msg_data->para_flag |= SRV_SMS_PARA_TIMESTAMP;
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_sms_set_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_msg_data(SMS_HANDLE sms_handle, srv_sms_btmapc_int_msg_data_struct *msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        memcpy(int_msg_data, msg_data, sizeof(srv_sms_btmapc_int_msg_data_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_storage_type
 * DESCRIPTION
 *  Set Storage Type, only for Save or Update Message
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_storage_type(SMS_HANDLE sms_handle, srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sms_hd->action)
    {
        case SRV_SMS_ACTION_SAVE:
        {
            srv_sms_btmapc_int_msg_data_struct *msg_data;

            msg_data = (srv_sms_btmapc_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);
            msg_data->storage_type = storage_type;
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_ref
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_msg_ref(SMS_HANDLE sms_handle, U8 msg_ref[], U8 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *msg_data;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (msg_data)
    {
        for (i = 0; i < total; i++)
        {
            msg_data->msg_ref[i] = msg_ref[i];
        }

        msg_data->total_seg = total;
        msg_data->para_flag |= SRV_SMS_PARA_MSG_REF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_delivery_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_delivery_status(SMS_HANDLE sms_handle, U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_int_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = srv_sms_btmapc_get_int_msg_data(sms_handle);

    if (msg_data)
    {
        msg_data->report_id = report_id;
        msg_data->para_flag |= SRV_SMS_PARA_DELIVERY_STATUS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_data_num_empty
 * DESCRIPTION
 *
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_number_empty_flag(MMI_BOOL is_allow_emtpy, srv_sms_btmapc_int_msg_data_struct *int_msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        int_msg_data->is_allow_num_emtpy = is_allow_emtpy;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sc_addr_empty_flag
 * DESCRIPTION
 *
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_sc_addr_empty_flag(MMI_BOOL is_allow_emtpy, srv_sms_btmapc_int_msg_data_struct *int_msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        int_msg_data->is_allow_sc_emtpy = is_allow_emtpy;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_asc
 * DESCRIPTION
 *
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_content_asc(MMI_BOOL is_asc_content, srv_sms_btmapc_int_msg_data_struct *int_msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        int_msg_data->is_asc_content = is_asc_content;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_callback(
        srv_sms_action_enum action,
        MMI_BOOL result,
        srv_sms_cause_enum cause,
        void *action_data,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CALLBACK, action, result, cause, callback_func);

    if (callback_func != NULL)
    {
        srv_sms_callback_struct callback_data;

        callback_data.result = result;
        callback_data.cause = cause;
        callback_data.action = action;
        callback_data.action_data = action_data;
        callback_data.user_data = user_data;

        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_succ_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_succ_callback(
        srv_sms_action_enum action,
        void *action_data,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_callback_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SUCC_CALLBACK, action, callback_func);

    callback_data.result = MMI_TRUE;
    callback_data.cause = SRV_SMS_CAUSE_NO_ERROR;
    callback_data.action = action;
    callback_data.action_data = action_data;
    callback_data.user_data = user_data;

    if (callback_func != NULL)
    {
        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_error_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_error_callback(
        srv_sms_action_enum action,
        srv_sms_cause_enum cause,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_callback_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ERROR_CALLBACK, action, cause, callback_func);

    callback_data.result = MMI_FALSE;
    callback_data.cause = cause;
    callback_data.action = action;
    callback_data.action_data = NULL;
    callback_data.user_data = user_data;

    if (callback_func != NULL)
    {
        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_async_callback(
        srv_sms_action_enum action,
        MMI_BOOL result,
        srv_sms_cause_enum cause,
        void *action_data,
        U32 action_data_size,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ASYNC_CALLBACK, action_data_size, callback_func);

    if (callback_func != NULL)
    {
        void *temp_data = NULL;

        if ((action_data != NULL) & (action_data_size > 0))
        {
            temp_data = OslMalloc(action_data_size);
            memcpy(temp_data, action_data, action_data_size);
        }

        SRV_SMS_BTMAPC_POST_CALLBACK(
            action,
            result,
            cause,
            temp_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_async_callback_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_sms_btmapc_async_callback_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_evt_callback_struct *event_data = (srv_sms_btmapc_evt_callback_struct*)param;
    srv_sms_callback_struct *callback_data = &event_data->callback_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ASYNC_CALLBACK_PROC);
    event_data->callback_func(callback_data);

    if (callback_data->action_data != NULL)
    {
        if (event_data->free_func)
        {
            event_data->free_func(callback_data->action_data);
        }
        else
        {
            OslMfree(callback_data->action_data);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_interrupt_event_handler
 * DESCRIPTION
 *  Set Interrupt Event Handler of the Event
 * PARAMETERS
 *  event_id        [IN]        Event ID
 *  event_func      [IN]        Event Handler Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_interrupt_event_handler(
        U16 event_id,
        SrvSmsEventFunc event_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SET_INTERRUPT_EVENT_HANDLER, event_id, event_func, curr_int_event_num);

    MMI_ASSERT(curr_int_event_num < SRV_SMS_MAX_INT_EVENT_NUM);

    srv_sms_int_event_list[curr_int_event_num].event_id = event_id;
    srv_sms_int_event_list[curr_int_event_num].int_event_func = event_func;
    srv_sms_int_event_list[curr_int_event_num].user_data = user_data;
    curr_int_event_num++;
}
                    

/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_interrupt_event_handler
 * DESCRIPTION
 *  Clear Interrupt Event Handler of the Event
 * PARAMETERS
 *  event_id        [IN]        Event ID
 *  event_func      [IN]        Event Handler Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_clear_interrupt_event_handler(
        U16 event_id,
        SrvSmsEventFunc event_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CLEAR_INTERRUPT_EVENT_HANDLER, event_id, event_func, curr_int_event_num);

    for (i = 0; i < curr_int_event_num; i++)
    {
        srv_sms_btmapc_int_event_struct *event_node = &srv_sms_int_event_list[i];
    
        if ((event_node->event_id == event_id) &&
            (event_node->int_event_func == event_func) &&
            (event_node->user_data == user_data))
        {
            U8 j;

            for (j = (i + 1); j < curr_int_event_num; j++)
            {
                memcpy(
                    &srv_sms_int_event_list[j - 1],
                    &srv_sms_int_event_list[j],
                    sizeof(srv_sms_btmapc_int_event_struct));
            }

            memset(
                &srv_sms_int_event_list[curr_int_event_num - 1],
                0,
                sizeof(srv_sms_btmapc_int_event_struct));

            curr_int_event_num--;

            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_exec_interrupt_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_exec_interrupt_event(
            U16 event_id,
            void* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_EXEC_INTERRUPT_EVENT, event_id, curr_int_event_num);

    for (i = 0; i < curr_int_event_num; i++)
    {
        srv_sms_btmapc_int_event_struct *event_node = &srv_sms_int_event_list[i];
    
        if (event_node->event_id == event_id)
        {
            srv_sms_event_struct event_data;

            event_data.evt_id = event_id;
            event_data.size = sizeof(srv_sms_event_struct);
            event_data.user_data = event_node->user_data;
            event_data.event_info = event_info;

            if (event_node->int_event_func != NULL)
            {
                result = event_node->int_event_func(&event_data);

                if (result == MMI_TRUE)
                {
                    break;
                }
            }
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_dst_number
 * DESCRIPTION
 *  check if the number is valid
 * PARAMETERS
 *  num         [IN]        Dst number
 *  numLen      [IN]        Number length
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_check_dst_number(U8 *num, U8 numLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *number = num;
    U8 numberlen;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((numLen == 0) || (numLen > (SRV_SMS_MAX_ADDR_LEN)))
    {
        return MMI_FALSE;
    }

    if((applib_is_valid_number((kal_uint8 *)num) != APPLIB_INVALID_NUMBER))
    {
        if (number[0] == '+')
        {
            numberlen = numLen - 1;
            number++;
        }
        else
        {
            numberlen = numLen;
        }
        if ((numberlen == 0) || (numberlen > (SRV_SMS_MAX_ADDR_LEN - 1)))
        {
            return MMI_FALSE;
        }
        for (i = 0; i < numberlen; i++)
        {
            U8 digit = number[i];
        
            if ((digit < '0' || digit > '9') && digit != '*' && digit != '#')
            {
                return MMI_FALSE;
            }
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
 *  srv_sms_sms_get_bitmap_index
 * DESCRIPTION
 *  get sms index from bitmap
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_btmapc_get_bitmap_index(U16 start_index, U8 *bitmap, U16 bitmap_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_byte_idx;
    U8 start_bit_idx;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_byte_idx = (start_index >> 3);
    start_bit_idx = (start_index & 0x7);

    for (i = start_byte_idx; i < bitmap_size; i++)
    {
        U8 mapping_byte;
        U8 j;

        mapping_byte = bitmap[i];

        for (j = start_bit_idx; j < 8; j++)
        {
            if (((mapping_byte >> j) & 0x01) == 0x01)
            {
                return (i * 8 + j);
            }
        }

        start_bit_idx = 0;
    }

    return SRV_SMS_INVALID_BITMAP_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_bitmap_index
 * DESCRIPTION
 *  set bitmap from index
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_set_bitmap_index(U16 index, U8 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_index;
    U8 bit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_index = (index >> 3);
    bit_index = (index & 0x7);
    bitmap[byte_index] |= (0x01 << bit_index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_bitmap_index
 * DESCRIPTION
 *  set bitmap from index
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_clear_bitmap_index(U16 index, U8 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_index;
    U8 bit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_index = (index >> 3);
    bit_index = (index & 0x7);
    bitmap[byte_index] &= (~(0x01 << bit_index));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_bitmap_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_check_bitmap_index(U16 index, U8 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_idx;
    U8 bit_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_idx = (index >> 3);
    bit_idx = (index & 0x7);

    if (bitmap[byte_idx] & (0x01 << bit_idx))
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
 *  srv_sms_emit_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_emit_event(U32 event_id, void* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct event_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_EMIT_EVENT, event_id);

    MMI_FRM_INIT_EVENT(&event_data, event_id);
    event_data.event_info = event_info;

    MMI_FRM_CB_EMIT_EVENT(&event_data);
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sms_segment_number
 * DESCRIPTION
 *  This function is used to get number of segments of SMS message.
 * PARAMETERS
 *  UCS2_count                  [IN]        UCS2 character number
 *  char_count                  [IN]        Character (GSM-7Bit and UCS2) total number
 *  extension_char_count        [IN]        GSM-7Bit extension character number      
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_sms_btmapc_get_sms_segment_number(U16 UCS2_count, U16 char_count, U16 extension_char_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage sys_lang;
    U8 segment = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguageType curr_lang_type;                
    EMSNationalLanguageType sys_lang_type;

    curr_lang_type = mmi_7bit_get_national_lang();

    sys_lang_type = srv_sms_btmapc_get_system_ems_lang_type();

    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(sys_lang_type);
    }

    mmi_7bit_get_national_lang_table(&sys_lang);
    
    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(curr_lang_type);
    } 
#else /* __SMS_R8_NATION_LANGUAGE__ */
    sys_lang.locking_shift = EMS_NL_DEFAULT;
    sys_lang.single_shift = EMS_NL_DEFAULT;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    if (UCS2_count)
    {
        if (EMSCalculateSegEx(SMSAL_UCS2_DCS, &sys_lang, (U16) (char_count * 2), &segment) == EMS_OK)
        {
            return segment;
        }
    }
    else
    {
        if (EMSCalculateSegEx(SMSAL_DEFAULT_DCS, &sys_lang, (U16) ((char_count + extension_char_count) * 2), &segment)
            == EMS_OK)
        {
            return segment;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_last_segment_remaining
 * DESCRIPTION
 *  This function is used to get number of remaining characters of last segment.
 * PARAMETERS
 *  UCS2_count                  [IN]        UCS2 character number
 *  char_count                  [IN]        Character (GSM-7Bit and UCS2) total number
 *  extension_char_count        [IN]        GSM-7Bit extension character number
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_sms_btmapc_get_last_segment_remaining(U16 UCS2_count, U16 char_count, U16 extension_char_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage sys_lang;
    U8 remain_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguageType curr_lang_type;                
    EMSNationalLanguageType sys_lang_type;

    curr_lang_type = mmi_7bit_get_national_lang();

    sys_lang_type = srv_sms_btmapc_get_system_ems_lang_type();

    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(sys_lang_type);
    }

    mmi_7bit_get_national_lang_table(&sys_lang);
    
    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(curr_lang_type);
    }  
#else /* __SMS_R8_NATION_LANGUAGE__ */
    sys_lang.locking_shift = EMS_NL_DEFAULT;
    sys_lang.single_shift = EMS_NL_DEFAULT;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    if (UCS2_count)
    {
        if (EMSCalculateLastSegRemainingChar(SMSAL_UCS2_DCS, &sys_lang, (U16) (char_count * 2), &remain_count)
            == EMS_OK)
        {
            return ((U8) (remain_count / 2));
        }
    }
    else
    {
        if (EMSCalculateLastSegRemainingChar
            (SMSAL_DEFAULT_DCS, &sys_lang, (U16) ((char_count + extension_char_count) * 2), &remain_count) == EMS_OK)
        {
            return remain_count;
        }
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_sms_get_usable_text_len
* DESCRIPTION
*  This function is used to get number of max characters of SMS message.
* PARAMETERS
*  dcs            [IN]
* RETURNS
*  number of max characters
*****************************************************************************/
U16 srv_sms_btmapc_get_usable_text_len(U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage sys_lang;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguageType curr_lang_type;                
    EMSNationalLanguageType sys_lang_type;
    
    curr_lang_type = mmi_7bit_get_national_lang();
    
    sys_lang_type = srv_sms_btmapc_get_system_ems_lang_type();
    
    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(sys_lang_type);
    }
    
    mmi_7bit_get_national_lang_table(&sys_lang);

    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(curr_lang_type);
    }  
#else /* __SMS_R8_NATION_LANGUAGE__ */
    sys_lang.locking_shift = EMS_NL_DEFAULT;
    sys_lang.single_shift = EMS_NL_DEFAULT;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    return ((U16) EMSUsableTextLenEx(dcs, &sys_lang));
}


#ifdef __SMS_R8_NATION_LANGUAGE__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_system_ems_lang_type
 * DESCRIPTION
 *  Get System EMS Language Type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
EMSNationalLanguageType srv_sms_btmapc_get_system_ems_lang_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguageType lang;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TURKISH) == 0)
    {
        lang = EMS_NL_TURKISH;
    }
    else if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SPANISH) == 0)
    {
        lang = EMS_NL_SPANISH;
    }
    else if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_PORTUGUESE) == 0)
    {
        lang = EMS_NL_PORTUGUESE;
    }
    else
    {
        lang = EMS_NL_DEFAULT;
    }

    return lang;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_local_sec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_sms_btmapc_get_local_sec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME local_time;
    U32 local_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&local_time);

    local_sec =  mmi_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);

    return local_sec;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_cmp_asc_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_cmp_asc_num(char* dest, char* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR src_addr[SRV_SMS_MAX_ADDR_LEN + 1];
    WCHAR dest_addr[SRV_SMS_MAX_ADDR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_wcs(src_addr, (CHAR*)src, SRV_SMS_MAX_ADDR_LEN);
    mmi_asc_n_to_wcs(dest_addr, (CHAR*)dest, SRV_SMS_MAX_ADDR_LEN);

    return srv_phb_compare_number(src_addr, dest_addr);
}


MMI_BOOL srv_sms_btmapc_file_exist(const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = FS_Open((const WCHAR*)filename, FS_READ_ONLY);
    if (fp >= FS_NO_ERROR)
    {
        FS_Close(fp);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#endif /* __SRV_SMS_BTMAPC__ */
#endif /* __MOD_SMSAL__ */

