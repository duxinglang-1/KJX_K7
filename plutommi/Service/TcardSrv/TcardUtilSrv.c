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
 *  TcardUtilSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  T Card service int prototype define
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
*****************************************************************************/

#include "MMI_features.h"
#ifdef __SRV_TCARD_DATA_STORE__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "Fs_gprot.h"
#include "TcardUtilSrv.h"
#include "TcardSrvprot.h"
#include "TcardSrvGprot.h"
#include "Mmi_frm_mem_gprot.h"









/**************************************************************
* MARCO
**************************************************************/
#define    SRV_TCARD_MAX_HANDLE 10


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    void *cntx;
} tcard_handle_node_struct;
/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static tcard_handle_node_struct handle_node_list[SRV_TCARD_MAX_HANDLE];


/**************************************************************
* Static Function Declaration
**************************************************************/
static tcard_handle_node_struct* srv_tcard_find_cntx_node(void* cntx);


/**************************************************************
* Function Defination
**************************************************************/
void srv_tcard_handle_asyc(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_async_struct *async_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_cntx = (srv_tcard_async_struct*)arg;
    srv_tcard_async_callback(
        async_cntx->action,
        async_cntx->result,
        async_cntx->action_data,
        async_cntx->data_size,
        async_cntx->user_data,
        async_cntx->callback_func);
    OslMfree(async_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_tcard_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_tcard_async_callback(
        srv_tcard_op_enum action,
        S32 result,
        void *action_data,
        U32 data_size,
        void *user_data,
        SrvTcardCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (callback_func != NULL)
    {
        srv_tcard_evt_callback_struct post_evt;                               
                                                                                            \
        MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_TCARD_ASYNC_CALLBACK);                                         \
        post_evt.callback_func = callback_func;                                  
        post_evt.callback_data.result = result;                                                     \
        post_evt.callback_data.action = action;                            
        post_evt.callback_data.data_size = data_size;                         
        post_evt.callback_data.user_data = user_data;                       
        MMI_FRM_POST_EVENT(&post_evt, srv_tcard_async_callback_proc, NULL);   

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_tcard_async_callback_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_tcard_async_callback_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_evt_callback_struct *event_data = (srv_tcard_evt_callback_struct*)param;
    srv_tcard_callback_struct *callback_data = &event_data->callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    event_data->callback_func(callback_data);

    return MMI_RET_OK;


}


/*****************************************************************************
 * FUNCTION
 *  srv_tcard_get_app_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/

S32 srv_tcard_get_app_index(srv_tcard_file_index_enum file_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_file_entry_struct *record;
    S32 i;
    U32 total;
    srv_tcard_app_index_enum app_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total = sizeof(tcard_file_mgr_common_table)/sizeof(srv_tcard_file_entry_struct);
    for(i = 0; i < total; i++)
    {
        record = &tcard_file_mgr_common_table[i];
        if(record->file_index == file_index)
        {
            app_index = record->app_index;
            break;
        }
    }

    if(i == total)
    {
        app_index = SRV_TCARD_OP_INVALID_INDEX;
    }

    return app_index;   
}


/*****************************************************************************
 * FUNCTION
 *  srv_tcard_get_table_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/

U32 srv_tcard_get_table_index(srv_tcard_file_index_enum file_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_file_entry_struct *record;
    S32 i;
    U32 total;
    U32 index;
    srv_tcard_app_index_enum app_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total = sizeof(tcard_file_mgr_common_table)/sizeof(srv_tcard_file_entry_struct);
    for(i = 0; i < total; i++)
    {
        record = &tcard_file_mgr_common_table[i];
        if(record->file_index == file_index)
        {
            index = i;
			break;
        }
    }

    if(i == total)
    {
        index = SRV_TCARD_OP_INVALID_INDEX;
    }

    return index;   
}

/*****************************************************************************
 * FUNCTION
 *  srv_tcard_check_op_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/

MMI_BOOL srv_tcard_check_op_para(srv_tcard_op_struct *op_cntx, srv_tcard_file_entry_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 total;
    U32 index;
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((op_cntx->start_record_id >= 0) && (op_cntx->start_record_id != SRV_TCARD_OP_INVALID_INDEX)) && op_cntx->record_num >0)
    {
        if((op_cntx->start_record_id >= record->record_number) || (op_cntx->start_record_id + op_cntx->record_num) > record->record_number)
        {
            result = MMI_FALSE; 
        }
        else
        {
            result = MMI_TRUE;
        }
    }
    else
    {
        result = MMI_FALSE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_tcard_find_cntx_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/

static tcard_handle_node_struct* srv_tcard_find_cntx_node(void* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tcard_handle_node_struct *node = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_TCARD_MAX_HANDLE; i++)
    {
        if (handle_node_list[i].cntx == cntx)
        {
            node = &handle_node_list[i];
        }
    }
    return node;
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
static tcard_handle_node_struct* srv_tcard_get_unused_cntx_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tcard_find_cntx_node(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_tcard_alloc_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void* srv_tcard_alloc_cntx(
        U32 size,
        srv_tcard_op_enum action,
        SrvTcardCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tcard_handle_node_struct *cntx_node;
    srv_tcard_handle_struct *cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    MMI_ASSERT(size >= sizeof(srv_tcard_handle_struct));

    cntx_node = srv_tcard_get_unused_cntx_node();

    if (cntx_node != NULL)
    {
        cntx = (srv_tcard_handle_struct*)OslMalloc(size);

        cntx->action = action;
        cntx->is_abort = MMI_FALSE;
        cntx->callback_func = callback_func;
        cntx->user_data = user_data;

        cntx_node->cntx = cntx;
    }

    return cntx;
}


void srv_tcard_free_cntx(void* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tcard_handle_node_struct *cntx_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cntx_node = srv_tcard_find_cntx_node(cntx);

    if (cntx_node != NULL)
    {
        cntx_node->cntx = NULL;
        OslMfree(cntx);
    }
}

void srv_tcard_emit_event(U32 event_id, void* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_event_struct event_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI,"srv_tcard_emit_event :tcard ready");
    MMI_FRM_INIT_EVENT(&event_data, event_id);
    event_data.event_info = event_info;

    MMI_FRM_CB_EMIT_EVENT(&event_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_tcard_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_tcard_callback(
        srv_tcard_op_enum action,
        MMI_BOOL result,
        srv_tcard_op_result_enum cause,
        void *action_data,
        void *user_data,
        SrvTcardCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    if (callback_func != NULL)
    {
        srv_tcard_callback_struct callback_data;

        callback_data.result = result;

        callback_data.action = action;
        callback_data.user_data = user_data;

        callback_func(&callback_data);
    }
}
#endif/*__SRV_TCARD_DATA_STORE__*/ 


