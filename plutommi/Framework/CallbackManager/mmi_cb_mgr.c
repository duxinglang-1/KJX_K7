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
 * mmi_cb_mgr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Callback manager which centrally control events and corresponding callback functions
 *   between caller appliction and callee application. This module will decouple the 
 *   relationship between applications.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#define MMI_CB_MGR_C


#include "mmi_frm_prot.h"
#include "fix_size_mem.h"
#include "string.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "GlobalRESDef.h"
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct _mmi_cb_dynamic_node
{
    mmi_proc_func cb;
    void *user_data;
    struct _mmi_cb_dynamic_node *next;
} mmi_cb_dynamic_node;

typedef struct
{
    U16 evt_id;
    mmi_proc_func *static_table;
    mmi_cb_dynamic_node *header;
} mmi_cb_map_struct;

typedef S32 (*cb_proc_type)(U16 evt_id, U32 tbl_idx, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data);

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U16 evtid;
    mmi_proc_func callback;
    void *userdata;
} mmi_evt_post_dereg_cb_struct;

typedef struct _mmi_evt_cur_exc_info
{
    U16 evt_id;
    mmi_proc_func callback;
    void *userdata;
    struct _mmi_evt_cur_exc_info* next;
} mmi_evt_cur_exc_info;

extern mmi_cb_map_struct mmi_cb_table_map[];

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Definition for search position of dynamic callback link list */
#define PREV_POS    1
#define POST_POS    2
#define END_POS     3

/***************************************************************************** 
 * Local variable
 *****************************************************************************/
//static mmi_proc_func cur_exec_cb = NULL;
//static void *cur_exec_cb_user_data = NULL;
//static  U16 cur_exec_evt_id;
static mmi_evt_cur_exc_info* cur_exec_node;
static mmi_evt_cur_exc_info* cur_exec_node_header;
static U8 emit_reentry_cnt = 0;
static MMI_BOOL mmi_frm_cb_find_current_execute_callback(U16 evt_id, mmi_proc_func call_back, void *user_data);
/***************************************************************************** 
 * Internal Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  find_cb_list_position
 * DESCRIPTION
 *  Find designated node position of callback link list.
 * PARAMETERS
 *  header         [IN]  link list header pointer.
 *  call_back      [IN]  call back function.
 *  user_data      [IN]  user data pointer.
 *  is_reg         [IN]  if callback with designated user data has been registered.
 *  flag           [IN]  search type.
 * RETURNS
 *  Return node pointer if found;
 *  return NULL if can't found designated node.
 *****************************************************************************/
static mmi_cb_dynamic_node *find_cb_list_position(mmi_cb_dynamic_node *header, mmi_proc_func call_back, void *user_data, MMI_BOOL *is_reg, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cb_dynamic_node *p, *prev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(header != NULL);

    *is_reg = MMI_FALSE;
    
    for (prev_p = header, p = prev_p->next;
         p != NULL;
         prev_p = prev_p->next, p = prev_p->next)
    {
        if (prev_p->next->cb == call_back && prev_p->next->user_data == user_data)
        {
            *is_reg = MMI_TRUE;
            /* Has been registered */
            break;
        }
    }
    if (flag == END_POS)
    {
        return *is_reg ? NULL : prev_p;
    }
    else if (flag == PREV_POS || flag == POST_POS)
    {
        if (prev_p->next != NULL)
        {
            return (flag == PREV_POS) ? prev_p : prev_p->next->next;
        }
        else
        {/* Can't find target node */
            return NULL;
        }
    }
    else
    {
        MMI_ASSERT(0);
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  process_cb_table
 * DESCRIPTION
 *  Process callback static table and dynamic link list with designated process funciton.
 * PARAMETERS
 *  evt_id       [IN]  event id.
 *  cb_proc      [IN]  call back process function.
 *  evt          [IN]  event structure pointer.
 *  call_back    [IN]  callback.
 *  user_data    [IN]  user data pointer.
 * RETURNS
 *  Return result of process function.
 *****************************************************************************/
static S32 process_cb_table(U16 evt_id, cb_proc_type cb_proc, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; ; i++)
    {
		if (mmi_cb_table_map[i].static_table == NULL)
		{/* End of map table */
			return MMI_RET_ERR_CANT_FIND_EVT;
		}
		else if (mmi_cb_table_map[i].evt_id == evt_id)
		{
            return cb_proc(evt_id, i, evt, call_back, user_data);
        }
    }
}

static void mmi_frm_free_cur_exec_node(U16 id)
{
    if(cur_exec_node)
    {
        mmi_evt_cur_exc_info* temp_node = cur_exec_node_header;
        mmi_evt_cur_exc_info* pre_node = cur_exec_node_header;
        if(cur_exec_node == cur_exec_node_header)
        {
            mmi_frm_free(cur_exec_node_header);
            cur_exec_node_header = cur_exec_node = NULL;
        }
        else
        {
            //free current nde
            while(temp_node)
            {
                if(temp_node == cur_exec_node)
                {
                    pre_node->next = temp_node->next;
                    mmi_frm_free(temp_node);
					cur_exec_node = pre_node;
                    break;
                }
                pre_node = temp_node;
                temp_node = temp_node->next;
                
            }
        }
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  execute_evt_cb
 * DESCRIPTION
 *  Execute event callback function by designated execution type.
 * PARAMETERS
 *  tbl_idx         [IN]  event table index.
 *  evt             [IN]  event structure pointer.
 * RETURNS
 *  Return MMI_RET_OK if execute all callback;
 *  return result value of callback and stop invoking cb process if it isn't MMI_RET_OK;
 *  return MMI_RET_ERR_NO_REG_CB if neither static nor dynamic callback is registered.
 *****************************************************************************/
static S32 execute_evt_cb(U32 tbl_idx, mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    mmi_cb_map_struct *map_p = &mmi_cb_table_map[tbl_idx];
	mmi_cb_dynamic_node *tmp_p;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* One event map one static table and one dynamic link list */
    ret = MMI_RET_OK;

    /* Execute static callback */
    for (i = 0; ; i++)
    {
        if (map_p->static_table[i] == NULL)
        {/* End of static callback table */
            if (i == 0)
            {
                ret= MMI_RET_ERR_NO_REG_CB;
            }
            break;
        }
        ret = map_p->static_table[i](evt);
        if (ret != MMI_RET_OK)
        {
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_EMIT_EVENT_STOP_PROC_STATIC, map_p->static_table[i], ret);
            return ret;
        }
    }
    /* Execute dynamic callback */
    if (map_p->header)
    {
        mmi_evt_cur_exc_info* temp_node;
        temp_node = mmi_frm_malloc(sizeof(mmi_evt_cur_exc_info));
        temp_node->evt_id = evt->evt_id;
        //temp_node->userdata = tmp_p->user_data;
        //temp_node->callback = tmp_p->cb;
        temp_node->next = NULL;
        if (cur_exec_node == NULL)
        {
            cur_exec_node_header = cur_exec_node = temp_node;
        }
        else if (cur_exec_node->next == NULL)
        {
            cur_exec_node->next = temp_node;
            cur_exec_node = temp_node;
        }
        for (tmp_p = map_p->header->next; tmp_p != NULL; tmp_p = tmp_p->next)
        {
            
            cur_exec_node->userdata = tmp_p->user_data;
            cur_exec_node->callback = tmp_p->cb;
            evt->user_data = tmp_p->user_data;
            ret = tmp_p->cb(evt);

            if (ret != MMI_RET_OK)
            {
                MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_EMIT_EVENT_STOP_PROC_DYNAMIC, tmp_p->cb, ret);
                mmi_frm_free_cur_exec_node(evt->evt_id);
                return ret;
            }
        }
        mmi_frm_free_cur_exec_node(evt->evt_id);
    }
	/* 
	 * if (!map_p->header && i == 0)  ret == MMI_RET_ERR_NO_REG_CB;
	 * Neither static nor dynamic callback is registered!
	 */
    return ret;
}

static S32 query_register_count(U16 evt_id, U32 tbl_idx, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    mmi_cb_map_struct *map_p = &mmi_cb_table_map[tbl_idx];
    S32 count = 0;
    mmi_cb_dynamic_node *tmp_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; ; i++)
    {
        if (map_p->static_table[i] == NULL)
        {
            break;
        }
        else
        {
            count++;
        }
        
    }


    if(map_p->header)
    {
		tmp_p = map_p->header->next;
        while(tmp_p)
        {
            count++;
			tmp_p = tmp_p->next;
        }
    }
    return count;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_register_receiver_count
 * DESCRIPTION
 *  Query the register receiver count, including static and dynamic. Please pay
 *  attention it is different with the execute receiver count.
 * PARAMETERS
 *  evt_id    : [IN] the event id you want to query.
 * RETURNS
 *  MMI_RET_ERR_CANT_FIND_EVT or the number of register receiver count
 *****************************************************************************/
S32 mmi_frm_cb_register_receiver_count(U16 evt_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = process_cb_table(evt_id, query_register_count, NULL, NULL, NULL);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  emit_evt_cb
 * DESCRIPTION
 *  Execute all event callback.
 * PARAMETERS
 *  evt_id       [IN]  callback execution type.
 *  tbl_idx      [IN]  event table index.
 *  evt          [IN]  event structure pointer.
 *  call_back    [IN]  no use in this interface.
 *  user_data    [IN]  no use in this interface.
 * RETURNS
 *  Return result of execute_evt_cb.
 *****************************************************************************/
static S32 emit_evt_cb(U16 evt_id, U32 tbl_idx, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && call_back == NULL && user_data == NULL);
    
    return execute_evt_cb(tbl_idx, evt);
}


/*****************************************************************************
 * FUNCTION
 *  register_evt_cb
 * DESCRIPTION
 *  Register event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id       [IN]  callback execution type.
 *  tbl_idx      [IN]  event table index.
 *  evt          [IN]  event structure pointer.
 *  call_back    [IN]  callback function.
 *  user_data    [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered.
 *****************************************************************************/
static S32 register_evt_cb(U16 evt_id, U32 tbl_idx, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cb_dynamic_node *p, *position;
    MMI_BOOL is_reg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt == NULL && call_back != NULL);

    if (mmi_cb_table_map[tbl_idx].header == NULL)
    {/* First time to register cb, create header whithout element */
        p = mmi_frm_malloc(sizeof(mmi_cb_dynamic_node));
        memset(p, 0, sizeof(mmi_cb_dynamic_node));
		mmi_cb_table_map[tbl_idx].header = p;
    }

    position = find_cb_list_position(mmi_cb_table_map[tbl_idx].header, call_back, user_data, &is_reg, END_POS);
    p = mmi_frm_malloc(sizeof(mmi_cb_dynamic_node));
    p->cb = call_back;
    p->user_data = user_data;
    p->next = NULL;
    
    if (is_reg && position == NULL)
    {
        mmi_frm_free(p);
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_REG_EVENT_BEEN_REGISTERED_IN_REG_API);
        return MMI_RET_ERR_HAS_BEEN_REGISTERED;
    }
    else
    {
        position->next = p;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  deregister_evt_cb
 * DESCRIPTION
 *  Deregister event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id       [IN]  callback execution type.
 *  tbl_idx      [IN]  event table index.
 *  evt          [IN]  event structure pointer.
 *  call_back    [IN]  callback function.
 *  user_data    [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to deregister callback with designated user data;
 *  return MMI_RET_ERR_NO_CB_AND_DATA if the designated callback with 
 *  designated user data hasn't been registered;
 *****************************************************************************/
static S32 deregister_evt_cb(U16 evt_id, U32 tbl_idx, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cb_dynamic_node *p, *position;
    MMI_BOOL is_reg;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(evt == NULL && call_back != NULL);

    if (mmi_cb_table_map[tbl_idx].header == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEREG_EVENT_NULL_HEADER);
        return MMI_RET_ERR_NO_CB_AND_DATA;
    }
    else
    {/* Remove middle node or footer, find_cb_list_position make sure position->next != NULL */
        position = find_cb_list_position(mmi_cb_table_map[tbl_idx].header, call_back, user_data, &is_reg, PREV_POS);
        if (position == NULL)
        {
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEREG_EVENT_NO_CB_AND_DATA);
            return MMI_RET_ERR_NO_CB_AND_DATA;
        }
        else
        {
            p = position->next;
            position->next = p->next;
            mmi_frm_free(p);
            }
        }

    if (mmi_cb_table_map[tbl_idx].header->next == NULL)
    {/* No node in list */
        mmi_frm_free(mmi_cb_table_map[tbl_idx].header);
        mmi_cb_table_map[tbl_idx].header = NULL;
    }
    return MMI_RET_OK;
}


/***************************************************************************** 
 * FUNCTION
 *  has_evt_registered
 * DESCRIPTION
 *  Check if callback with user data has been registered for designated event.
 * PARAMETERS
 *  evt_id       [IN]  callback execution type.
 *  tbl_idx      [IN]  event table index.
 *  evt          [IN]  event structure pointer.
 *  call_back    [IN]  callback function.
 *  user_data    [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_ERR_HAS_NOT_BEEN_REGISTERED if has not been registered;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered.
 *****************************************************************************/
static S32 has_evt_registered(U16 evt_id, U32 tbl_idx, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cb_dynamic_node *position;
    MMI_BOOL is_reg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt == NULL && call_back != NULL);

    if (mmi_cb_table_map[tbl_idx].header == NULL)
    {
        return MMI_RET_ERR_HAS_NOT_BEEN_REGISTERED;
    }

    position = find_cb_list_position(mmi_cb_table_map[tbl_idx].header, call_back, user_data, &is_reg, END_POS);
    
    if (is_reg && position == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_REG_EVENT_BEEN_REGISTERED);
        return MMI_RET_ERR_HAS_BEEN_REGISTERED;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_REG_EVENT_NOT_BEEN_REGISTERED);
        return MMI_RET_ERR_HAS_NOT_BEEN_REGISTERED;
    }
}


/***************************************************************************** 
 * External Function
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_emit_event
 * DESCRIPTION
 *  Emit event to all callee callback, if callback return MMI_RET_OK, 
 *  continue to execute the rest of callback funtions, 
 *¡¡otherwise, stop execution and return result of the current callback.
 *  caller and callee app should decide the meaning of the return value.
 * PARAMETERS
 *  evt :            [IN]  event structure pointer.
 * RETURNS
 *  Return MMI_RET_ERR_WRONG_PARA if evt pointer if NULL;
 *  otherwise, return MMI_RET_OK.
 *****************************************************************************/
mmi_ret mmi_frm_cb_emit_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_EMIT_EVENT, evt->evt_id, evt->size);
    if (evt == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_EMIT_EVENT_WRONG_PARA);
        return MMI_RET_ERR_WRONG_PARA;
    }

    emit_reentry_cnt++;
    ret = process_cb_table(evt->evt_id, emit_evt_cb, evt, NULL, NULL);
    /* Event sender must register event in mmi_Frm_cb_cfg.h, then the event could be registered dynamically. */
    MMI_ASSERT(ret != MMI_RET_ERR_CANT_FIND_EVT);
    emit_reentry_cnt--;

    if (emit_reentry_cnt == 0)
    {
        MMI_ASSERT(!cur_exec_node_header);
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_EMIT_EVENT_END, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_emit_post_event
 * DESCRIPTION
 *  Emit post events, the callback of this event will be invoked after current 
 *  function flow and before next input event like key, pen, timer, primitive.
 * PARAMETERS
 *  evt :      [IN]  post event structure pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_cb_emit_post_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL);
    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_EMIT_POST_EVT, evt, evt->evt_id);
    /* Copy event struct and push into post evt queue */
    p = mmi_frm_malloc(evt->size);
    memcpy(p, evt, evt->size);
    enqueue_post_evt(p, POST_CB_EVT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_emit_post_event_ex
 * DESCRIPTION
 *  Emit post events, the callback of this events will be invoked after current 
 *  function flow, this extension api support reveiver feedback result value back to
 *  sender through result_cb.
 *  And result callback will be invoked with EVT_ID_POST_CB_RST and result_cb_user_data to
 *  notify sender the result.
 * PARAMETERS
 *  evt :                 [IN]    event structure pointer;
 *  result_cb :           [IN]    result callback;
 *  result_cb_user_data : [IN]    result callback user data;
 * RETURNS
 *  Return MMI_RET_OK if success;
 *****************************************************************************/
void mmi_frm_cb_emit_post_event_ex(mmi_event_struct *evt, mmi_post_event_result_proc_func result_cb, void *result_cb_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_ex_struct *evt_ex_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_EMIT_POST_EVT_EX, evt, evt->evt_id, result_cb, result_cb_user_data);
    /* Copy event struct and push into post evt queue */
    evt_ex_p = mmi_frm_malloc(sizeof(mmi_post_evt_ex_struct));
    evt_ex_p->evt_p = mmi_frm_malloc(evt->size);
    memcpy(evt_ex_p->evt_p, evt, evt->size);
    evt_ex_p->result_cb = result_cb;
    evt_ex_p->result_cb_user_data = result_cb_user_data;
    enqueue_post_evt((void *)evt_ex_p, POST_CB_EVT_EX);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_has_event_reg
 * DESCRIPTION
 *  Check if callback with user data has been registered for designated event.
 * PARAMETERS
 *  evt_id       [IN]  callback execution type.
 *  call_back    [IN]  callback function.
 *  user_data    [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered;
 *  return MMI_RET_ERR_WRONG_PARA if call_back is NULL.
 *****************************************************************************/
MMI_BOOL mmi_frm_cb_has_event_reg(U16 evt_id, mmi_proc_func call_back, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_HAS_EVENT_REG, evt_id, call_back, user_data);

    if (call_back == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_REG_EVENT_WRONG_PARA);
        return MMI_FALSE;
    }
    ret = process_cb_table(evt_id, has_evt_registered, NULL, call_back, user_data);
    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_REG_EVENT_END, ret);

    return (ret == MMI_RET_ERR_HAS_NOT_BEEN_REGISTERED) ? MMI_FALSE : MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_reg_event
 * DESCRIPTION
 *  Register event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  call_back :   [IN]  callback function.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered;
 *  return MMI_RET_ERR_WRONG_PARA if call_back is NULL.
 *****************************************************************************/
mmi_ret mmi_frm_cb_reg_event(U16 evt_id, mmi_proc_func call_back, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_REG_EVENT, evt_id, call_back, user_data);

    if (call_back == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_REG_EVENT_WRONG_PARA);
        return MMI_RET_ERR_WRONG_PARA;
    }
    ret = process_cb_table(evt_id, register_evt_cb, NULL, call_back, user_data);
    /* Event sender must register event in mmi_Frm_cb_cfg.h, then the event could be registered dynamically. */
    MMI_ASSERT(ret != MMI_RET_ERR_CANT_FIND_EVT);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_REG_EVENT_END, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  post_dereg_cb_proc
 * DESCRIPTION
 *  Process handler for posted action of dereg callback.
 * PARAMETERS
 *  param       [IN]  event struct.
 * RETURNS
 *  Return MMI_RET_OK.
 *****************************************************************************/
static mmi_ret post_dereg_cb_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_post_dereg_cb_struct *evt = (mmi_evt_post_dereg_cb_struct *)param;
    S32 rst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rst = mmi_frm_cb_dereg_event(evt->evtid, evt->callback, evt->userdata);

    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_POST_DEREG_RESULT, rst);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_dereg_event
 * DESCRIPTION
 *  Deregister event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  call_back :   [IN]  callback function.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to deregister callback with designated user data;
 *  return MMI_RET_ERR_NO_CB_AND_DATA if the designated callback with 
 *  designated user data hasn't been registered;
 *  return MMI_RET_ERR_WRONG_PARA if call_back is NULL.
 *****************************************************************************/
mmi_ret mmi_frm_cb_dereg_event(U16 evt_id, mmi_proc_func call_back, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_DEREG_EVENT, evt_id, call_back, user_data);

    if (call_back == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEREG_EVENT_WRONG_PARA);
        return MMI_RET_ERR_WRONG_PARA;
    }

    if ((emit_reentry_cnt > 0) && mmi_frm_cb_find_current_execute_callback(evt_id, call_back, user_data))
    {
        mmi_evt_post_dereg_cb_struct evt;
        
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_POST_DEREG_CB);
        evt.evtid = evt_id;
        evt.callback = call_back;
        evt.userdata = user_data;
        MMI_FRM_POST_EVENT(&evt, post_dereg_cb_proc, NULL);

        return MMI_RET_ERR_POST_DEREG_CB;
    }

    ret = process_cb_table(evt_id, deregister_evt_cb, NULL, call_back, user_data);
    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_DEREG_EVENT_END, ret);
    return ret;
}


MMI_BOOL mmi_frm_cb_find_current_execute_callback(U16 evt_id, mmi_proc_func call_back, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_cur_exc_info* temp_node = cur_exec_node_header;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while(temp_node)
    {
        
        if ((temp_node->evt_id == evt_id) && (temp_node->callback == call_back) && (temp_node->userdata == user_data))
        {
            return MMI_TRUE;
        }
        temp_node = temp_node->next;
    }

    return MMI_FALSE;







}

#ifdef MMI_CB_MGR_UT
/***************************************************************************** 
 * Unit test Function
 *****************************************************************************/
#define CB_UT_A     0x0001
#define CB_UT_B     0x0002
#define CB_UT_C     0x0004
#define CB_UT_D     0x0008
#define CB_UT_E     0x0010
#define CB_UT_F     0x0020
#define CB_UT_G     0x0040
#define CB_UT_H     0x0080
#define CB_UT_I     0x0100
#define CB_UT_J     0x0200
#define CB_UT_K_1   0x0400
#define CB_UT_K_2   0x0800
#define CB_UT_K_3   0x1000
#define CB_UT_L     0x2000
#define CB_UT_M     0x4000
#define CB_UT_N     0x8000

static U32 g_test_case_invoke_flag = 0x00000000;

static MMI_BOOL has_dereg = MMI_FALSE;

#define SET_CB_UT_INVOKED(_x)       (g_test_case_invoke_flag |= CB_UT_##_x)
#define CHECK_CB_UT_INVOKED(_x)     ((g_test_case_invoke_flag & CB_UT_##_x) == CB_UT_##_x)
#define RESET_CB_UT_INVOKED(_x)     (g_test_case_invoke_flag &= ~CB_UT_##_x)
#define RESET_CB_UT_INVOKED_ALL     g_test_case_invoke_flag = 0;

typedef struct
{
    U8 instance;
} mmi_cbmgr_ut_instance_struct;

static S32 display_cb(U16 evt_id, U32 tbl_idx, mmi_event_struct *evt, mmi_proc_func call_back, void *user_data)
{
    mmi_cb_dynamic_node *p;
    U32 i = 0;
    if (mmi_cb_table_map[tbl_idx].header == NULL)
    {
        kal_prompt_trace(MOD_MMI, "list is empty");
        return MMI_RET_OK;
    }
    p = mmi_cb_table_map[tbl_idx].header->next;
    while (p)
    {
        kal_prompt_trace(MOD_MMI, "[%d]cb = 0x%08x, user_data = 0x%08x", i, p->cb, p->user_data);
        i++;
        p = p->next;
    }
    return MMI_RET_OK;
}

void mmi_cb_ut_display_dyn_cb(U16 id)
{
    kal_prompt_trace(MOD_MMI, "event is %d", id);
    process_cb_table(id, display_cb, NULL, NULL, NULL);
}


mmi_ret mmi_cb_ut_static_a(mmi_event_struct *arg)
{
    SET_CB_UT_INVOKED(A);

	return MMI_RET_OK;
}
mmi_ret mmi_cb_ut_static_b(mmi_event_struct *arg)
{
    SET_CB_UT_INVOKED(B);

	return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_static_c(mmi_event_struct *arg)
{
    SET_CB_UT_INVOKED(C);

	return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_static_d(mmi_event_struct *arg)
{
    SET_CB_UT_INVOKED(D);

	return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_static_e(mmi_event_struct *arg)
{
    SET_CB_UT_INVOKED(E);

	return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_static_f(mmi_event_struct *arg)
{
    SET_CB_UT_INVOKED(F);

	return MMI_RET_ERR_WRONG_PARA;
}

mmi_ret mmi_cb_ut_static_g(mmi_event_struct *arg)
{
    void *data = NULL;
    SET_CB_UT_INVOKED(G);

    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data);
	return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_static_h(mmi_event_struct *arg)
{
    void *data = NULL;
    S32 ret;
    SET_CB_UT_INVOKED(H);

    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data);
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_b, data);
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_c, data);

    return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_static_i(mmi_event_struct *arg)
{
    void *data = NULL;
    S32 ret;

    SET_CB_UT_INVOKED(I);
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_i, data);
    //MMI_ASSERT(ret == MMI_RET_ERR_POST_DEREG_CB);

    return MMI_RET_OK;
}

/* Post event cb */
mmi_ret mmi_cb_ut_static_j(mmi_event_struct *arg)
{
    mmi_idle_evt_stuct *idle_evt_p = (mmi_idle_evt_stuct *)arg;

    
    MMI_ASSERT(idle_evt_p->idle_type == 3);
    MMI_ASSERT(strcmp(idle_evt_p->buffer, "Hello world!") == 0);

    idle_evt_p->idle_type = 2;

    SET_CB_UT_INVOKED(J);
    return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_dynamic_k_1(mmi_event_struct *arg)
{
    void *user_data;
    mmi_ret rst;
    mmi_fmgr_evt_stuct fmgr_evt;

    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_STEP_2);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    user_data = mmi_frm_get_evt_user_data(arg);
    rst = mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dynamic_k_1, user_data);
    //MMI_ASSERT(rst == MMI_RET_ERR_POST_DEREG_CB);

    //MMI_ASSERT(mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dynamic_k_1, user_data));
    SET_CB_UT_INVOKED(K_1);
	return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_dynamic_k_2(mmi_event_struct *arg)
{
    void *user_data;
    mmi_ret rst;
    mmi_fmgr_evt_stuct fmgr_evt;

    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_STEP_3);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    user_data = mmi_frm_get_evt_user_data(arg);
    rst = mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_2, mmi_cb_ut_dynamic_k_2, user_data);
    //MMI_ASSERT(rst == MMI_RET_ERR_POST_DEREG_CB);

    //MMI_ASSERT(mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_2, mmi_cb_ut_dynamic_k_2, user_data));
    SET_CB_UT_INVOKED(K_2);
	return MMI_RET_OK;
}

mmi_ret mmi_cb_ut_dynamic_k_3(mmi_event_struct *arg)
{
    void *user_data;
    mmi_ret rst;

    user_data = mmi_frm_get_evt_user_data(arg);
    rst = mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_k_3, user_data);
    //MMI_ASSERT(rst == MMI_RET_ERR_POST_DEREG_CB);

    //MMI_ASSERT(mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_k_3, user_data));
    SET_CB_UT_INVOKED(K_3);
	return MMI_RET_OK;
}


mmi_ret mmi_cb_ut_dynamic_l(mmi_event_struct *arg) // in the callback dereg current event
{
    if (!has_dereg)
    {
        mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);
        has_dereg = MMI_TRUE;
    }
    else
    {
        mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_n, NULL);
    }
    SET_CB_UT_INVOKED(L);
}


mmi_ret mmi_cb_ut_dynamic_m(mmi_event_struct *arg) // in the callback dereg the previous event
{
    if (!has_dereg)
    {
        mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);
        has_dereg = MMI_TRUE;
    }
    SET_CB_UT_INVOKED(M);
}

mmi_ret mmi_cb_ut_dynamic_n(mmi_event_struct *arg) // in the callback dereg next event
{

    SET_CB_UT_INVOKED(N);
}
/***************************************************************************** 
 * Static callback
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_static
 * DESCRIPTION
 *  Unit test for static-registered callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_static(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_evt_stuct evt;
    S32 ret;
	void *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_XXX);
    
	/***************************************************************************** 
	 * execute all static cb
	 *****************************************************************************/
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(C));
    RESET_CB_UT_INVOKED_ALL;

	/***************************************************************************** 
	 * execute cb by val, cb_f will return error
	 *****************************************************************************/
    mmi_frm_cb_reg_event(EVT_ID_IDLE_XXX, mmi_cb_ut_static_d, data);
    mmi_frm_cb_reg_event(EVT_ID_IDLE_XXX, mmi_cb_ut_static_f, data);
    mmi_frm_cb_reg_event(EVT_ID_IDLE_XXX, mmi_cb_ut_static_e, data);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(C) &&
               CHECK_CB_UT_INVOKED(D) && CHECK_CB_UT_INVOKED(F) && !CHECK_CB_UT_INVOKED(E));
	RESET_CB_UT_INVOKED_ALL;
	
	ret = mmi_frm_cb_dereg_event(EVT_ID_IDLE_XXX, mmi_cb_ut_static_d, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    ret = mmi_frm_cb_dereg_event(EVT_ID_IDLE_XXX, mmi_cb_ut_static_f, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(C) &&
               !CHECK_CB_UT_INVOKED(D) && !CHECK_CB_UT_INVOKED(F) && CHECK_CB_UT_INVOKED(E));

    ret = mmi_frm_cb_dereg_event(EVT_ID_IDLE_XXX, mmi_cb_ut_static_e, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    ret = mmi_frm_cb_dereg_event(EVT_ID_IDLE_XXX, mmi_cb_ut_static_e, data);
    MMI_ASSERT(ret == MMI_RET_ERR_NO_CB_AND_DATA);
    RESET_CB_UT_INVOKED_ALL;

	return MMI_TRUE;
}


/***************************************************************************** 
 * Dynamic callback
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_dynamic
 * DESCRIPTION
 *  Unit test for dynamic-registered callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_dynamic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    void *data = NULL;
    void *data1 = (void *)&ret;
    mmi_fmgr_evt_stuct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/***************************************************************************** 
	 * register, 1.header, 2.one more node
	 *****************************************************************************/
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_b, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_c, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_d, data);

    ret = mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_d, data);
    MMI_ASSERT(ret == MMI_RET_ERR_HAS_BEEN_REGISTERED);
	/* Change data */
    ret = mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_d, data1);
    MMI_ASSERT(ret == MMI_RET_OK);

    ret = mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, NULL, data);
    MMI_ASSERT(ret == MMI_RET_ERR_WRONG_PARA);

    ret = mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, NULL, NULL);
    MMI_ASSERT(ret == MMI_RET_ERR_WRONG_PARA);

    /* Execute event callback */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_FMGR_COPY);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(C) && CHECK_CB_UT_INVOKED(D));
    // !!!make sure cb_d data & data1 all invoked!!!
    RESET_CB_UT_INVOKED_ALL;

	/***************************************************************************** 
	 * deregister, 1.middle node, 2.header node 3.footer node
	 *****************************************************************************/
    /* Make sure middle node -> cb_c has been removed */
	data = NULL;
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_c, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && !CHECK_CB_UT_INVOKED(C) && CHECK_CB_UT_INVOKED(D));
    RESET_CB_UT_INVOKED_ALL;

    /* Make sure can't remove cb_c again */
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_c, data);
    MMI_ASSERT(ret == MMI_RET_ERR_NO_CB_AND_DATA);

    /* Make sure cb function and data should all match target */
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_b, data1);
    MMI_ASSERT(ret == MMI_RET_ERR_NO_CB_AND_DATA);

	/* Make sure header node -> cb_a has been removed */
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    /* Make sure cb_d with data1 still be invoked */
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_d, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(D));
    RESET_CB_UT_INVOKED_ALL;

	/* Make sure footer node cb_d with &ret has been removed */
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_d, data1);
    MMI_ASSERT(ret == MMI_RET_OK);
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_b, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(B) && !CHECK_CB_UT_INVOKED(D));
    RESET_CB_UT_INVOKED_ALL;

	/***************************************************************************** 
	 * execute by value, cb_f is in static table and will return error
	 *****************************************************************************/
    mmi_frm_cb_reg_event(EVT_ID_FMGR_PASTE, mmi_cb_ut_static_a, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_PASTE, mmi_cb_ut_static_b, data);

	MMI_FRM_INIT_EVENT(&evt, EVT_ID_FMGR_PASTE);
    MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(A) && !CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(F));
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_PASTE, mmi_cb_ut_static_a, data);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_PASTE, mmi_cb_ut_static_b, data);
    RESET_CB_UT_INVOKED_ALL;

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_dynamic_reg_unreg
 * DESCRIPTION
 *  Unit test for dynamic-register & dynamic-deregister action.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_dynamic_reg_unreg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    void *data = NULL;
    mmi_idle_evt_stuct idle_evt;
    mmi_fmgr_evt_stuct fmgr_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&idle_evt, EVT_ID_IDLE_XXX);
    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_COPY);
	/***************************************************************************** 
	 * register cb in static cb
	 *****************************************************************************/
	/* reg cb_a in cb_g */
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_g, data);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(G));
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_g, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    RESET_CB_UT_INVOKED_ALL;

    /* unreg cb_a, cb_b, cb_c in cb_h */
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_h, data);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(H));
    mmi_frm_invoke_post_event();
	ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data);
    MMI_ASSERT(ret == MMI_RET_ERR_NO_CB_AND_DATA);
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_h, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    RESET_CB_UT_INVOKED_ALL;

    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_b, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_h, data);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_c, data);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(H));
    mmi_frm_invoke_post_event();
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_COPY, mmi_cb_ut_static_a, data));
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_COPY, mmi_cb_ut_static_b, data));
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_COPY, mmi_cb_ut_static_c, data));

    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_h, data);
    MMI_ASSERT(ret == MMI_RET_OK);
    RESET_CB_UT_INVOKED_ALL;

    /* unreg itself : cb_i in cb_i */
    mmi_frm_cb_reg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_i, data);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(I));
    mmi_frm_invoke_post_event();
    ret = mmi_frm_cb_dereg_event(EVT_ID_FMGR_COPY, mmi_cb_ut_static_i, data);
    MMI_ASSERT(ret == MMI_RET_ERR_NO_CB_AND_DATA);
    RESET_CB_UT_INVOKED_ALL;

    /* Check test event has no registered callback */
    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_NO_REG);
    ret = MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    MMI_ASSERT(ret == MMI_RET_ERR_NO_REG_CB);

    RESET_CB_UT_INVOKED_ALL;

	return MMI_TRUE;
}



MMI_BOOL mmi_cbmgr_ut_dereg_in_emit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_event_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_FMGR_STEP_3);
    //Dereg the current callback
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_m, NULL);
    
    ret = MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(M) && CHECK_CB_UT_INVOKED(L));
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL));
    RESET_CB_UT_INVOKED_ALL;
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_m, NULL);
   
    has_dereg = MMI_FALSE;

    
    //dereg the next callback proc
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_m, NULL);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);

    ret = MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(M));
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL));
    RESET_CB_UT_INVOKED_ALL;
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_m, NULL);

    has_dereg = MMI_FALSE;

    //dereg the prevous callback proc
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_n, NULL);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);
    ret = MMI_FRM_CB_EMIT_EVENT(&evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(L) && CHECK_CB_UT_INVOKED(N));
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_n, NULL));
    RESET_CB_UT_INVOKED_ALL;
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_l, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_n, NULL);
    has_dereg = MMI_FALSE;
   
    return MMI_TRUE;
}

MMI_BOOL mmi_cbmgr_ut_IT_app(void)
{
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
#endif
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_post_evt_q
 * DESCRIPTION
 *  Unit test for operating queue of post events.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_post_evt_q(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evt1, evt2, evt3;
    mmi_event_struct evt_arr[10];
    U8 i;
    U8 evt_flag;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt1, EVT_ID_FMGR_STEP_1);
    MMI_FRM_INIT_EVENT(&evt2, EVT_ID_FMGR_STEP_2);
    MMI_FRM_INIT_EVENT(&evt3, EVT_ID_FMGR_STEP_3);
    
    enqueue_post_evt(&evt1, POST_CB_EVT);
    MMI_ASSERT(mmi_frm_is_event_posted(&evt1) && mmi_frm_get_post_evt_num() == 1);
    enqueue_post_evt(&evt2, POST_CB_EVT);
    MMI_ASSERT(mmi_frm_is_event_posted(&evt2) && mmi_frm_get_post_evt_num() == 2);
    enqueue_post_evt(&evt3, POST_CB_EVT);
    MMI_ASSERT(mmi_frm_is_event_posted(&evt3) && mmi_frm_get_post_evt_num() == 3);
    
    dequeue_post_evt(&evt_flag);
    MMI_ASSERT(!mmi_frm_is_event_posted(&evt1) && mmi_frm_get_post_evt_num() == 2);
    dequeue_post_evt(&evt_flag);
    MMI_ASSERT(!mmi_frm_is_event_posted(&evt2) && mmi_frm_get_post_evt_num() == 1);
    dequeue_post_evt(&evt_flag);
    MMI_ASSERT(!mmi_frm_is_event_posted(&evt3) && mmi_frm_get_post_evt_num() == 0);

    for (i = 0; i < 10; i++)
    {
		MMI_FRM_INIT_EVENT(&(evt_arr[i]), EVT_ID_FMGR_STEP_1 + i);
        enqueue_post_evt(&(evt_arr[i]), POST_CB_EVT);
        MMI_ASSERT(mmi_frm_is_event_posted(&(evt_arr[i])) && mmi_frm_get_post_evt_num() == (U32)(i+1));
    }

    for (i = 0; i < 10; i++)
    {
        dequeue_post_evt(&evt_flag);
        MMI_ASSERT(evt_flag == POST_CB_EVT);
        MMI_ASSERT(!mmi_frm_is_event_posted(&(evt_arr[i])) && mmi_frm_get_post_evt_num() == (U32)(10-i-1));
    }

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_emit_post_evt
 * DESCRIPTION
 *  Unit test emiting post events.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_emit_post_evt(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_evt_stuct idle_evt;
    mmi_fmgr_evt_stuct fmgr_evt;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&idle_evt, EVT_ID_IDLE_XXX);
	MMI_ASSERT(idle_evt.size = sizeof(mmi_idle_evt_stuct));
    MMI_FRM_CB_EMIT_POST_EVENT(&idle_evt);

    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_PASTE);
    MMI_ASSERT(fmgr_evt.size = sizeof(mmi_fmgr_evt_stuct));
    MMI_FRM_CB_EMIT_POST_EVENT(&fmgr_evt);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(A) && !CHECK_CB_UT_INVOKED(B) && !CHECK_CB_UT_INVOKED(C) && !CHECK_CB_UT_INVOKED(F));

    mmi_frm_invoke_post_event();
    MMI_ASSERT(CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(C) && CHECK_CB_UT_INVOKED(F));

    RESET_CB_UT_INVOKED_ALL;
	
	return MMI_TRUE;
}


static S32 mmi_cbmgr_ut_rst_cb(mmi_post_result_event_struct *rst_evt)
{
    mmi_idle_evt_stuct *idle_evt_p = (mmi_idle_evt_stuct *)rst_evt->evt_p;

    MMI_ASSERT(rst_evt->result == MMI_RET_OK && rst_evt->evt_id == EVT_ID_POST_CB_RST && rst_evt->user_data == NULL);
    MMI_ASSERT(idle_evt_p->idle_type == 2);
    MMI_ASSERT(strcmp(idle_evt_p->buffer, "Hello world!") == 0);
    OslMfree(idle_evt_p->buffer);

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_emit_post_evt_ex
 * DESCRIPTION
 *  Unit test for emiting post extended events.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_emit_post_evt_ex(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_evt_stuct idle_evt;
        
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&idle_evt, EVT_ID_IDLE_YYY);
    idle_evt.buffer = OslMalloc(256);
    strcpy(idle_evt.buffer, "Hello world!");
    idle_evt.idle_type = 3;
    MMI_FRM_CB_EMIT_POST_EVENT_EX(&idle_evt, mmi_cbmgr_ut_rst_cb, NULL);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(J));

    mmi_frm_invoke_post_event();
    MMI_ASSERT(CHECK_CB_UT_INVOKED(J));
    RESET_CB_UT_INVOKED_ALL;
	
	return MMI_TRUE;
}


static S32 mmi_cbmgr_ut_post_evt_proc(mmi_event_struct *rst_evt)
{
    mmi_cbmgr_ut_instance_struct *user_data = rst_evt->user_data;
    mmi_idle_evt_stuct *idle_evt = (mmi_idle_evt_stuct *)rst_evt;

    if (user_data->instance == 1)
    {
        MMI_ASSERT(idle_evt->idle_type == 8);
        SET_CB_UT_INVOKED(A);
        
        return MMI_RET_OK;
    }
    else if (user_data->instance == 2)
    {
        MMI_ASSERT(idle_evt->idle_type == 9);
        SET_CB_UT_INVOKED(B);

        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR_UNKNOWN_EVT_FLAG;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_post_evt
 * DESCRIPTION
 *  Unit test for posting events of event mechanism.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_post_evt(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_evt_stuct idle_evt;
    mmi_cbmgr_ut_instance_struct *user_data;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&idle_evt, EVT_ID_IDLE_YYY);
    idle_evt.idle_type= 8;
    user_data = OslMalloc(sizeof(mmi_cbmgr_ut_instance_struct));
    user_data->instance = 1;
    
    MMI_FRM_POST_EVENT(&idle_evt, mmi_cbmgr_ut_post_evt_proc, user_data);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(A));

    MMI_ASSERT(mmi_frm_invoke_post_event() == MMI_RET_OK);
    OslMfree(user_data);
	MMI_ASSERT(CHECK_CB_UT_INVOKED(A));
	RESET_CB_UT_INVOKED(A);
	
	return MMI_TRUE;
}


static mmi_ret mmi_cbmgr_ut_post_evt_rst_cb(mmi_post_result_event_struct *rst_evt)
{
    mmi_cbmgr_ut_instance_struct *user_data = (mmi_cbmgr_ut_instance_struct *)rst_evt->user_data;

    MMI_ASSERT(rst_evt->result == MMI_RET_OK && rst_evt->evt_id == EVT_ID_POST_CB_RST && user_data != NULL);

    if (user_data->instance == 2)
    {
        SET_CB_UT_INVOKED(J);
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR_UNKNOWN_EVT_FLAG;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_post_evt_ex
 * DESCRIPTION
 *  Unit test for posting extended events of event mechanism.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_post_evt_ex(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_evt_stuct idle_evt;
    mmi_cbmgr_ut_instance_struct *user_data;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&idle_evt, EVT_ID_IDLE_YYY);
    idle_evt.idle_type= 9;
    user_data = OslMalloc(sizeof(mmi_cbmgr_ut_instance_struct));
    user_data->instance = 2;
    
    MMI_FRM_POST_EVENT_EX(&idle_evt, mmi_cbmgr_ut_post_evt_proc, user_data, mmi_cbmgr_ut_post_evt_rst_cb, user_data);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(A) && !CHECK_CB_UT_INVOKED(B) && !CHECK_CB_UT_INVOKED(J));

    MMI_ASSERT(mmi_frm_invoke_post_event() == MMI_RET_OK);
    OslMfree(user_data);
    MMI_ASSERT(!CHECK_CB_UT_INVOKED(A) && CHECK_CB_UT_INVOKED(B) && CHECK_CB_UT_INVOKED(J));
	RESET_CB_UT_INVOKED(B);
	RESET_CB_UT_INVOKED(J);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_reentry
 * DESCRIPTION
 *  Unit test for reentry of deregistering callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_reentry(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmgr_evt_stuct fmgr_evt;
    U32 data1, data2, data3;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dynamic_k_1, (void *)&data1);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_2, mmi_cb_ut_dynamic_k_2, (void *)&data2);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_k_3, (void *)&data3);

    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_STEP_1);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    MMI_ASSERT(CHECK_CB_UT_INVOKED(K_1) && CHECK_CB_UT_INVOKED(K_2) && CHECK_CB_UT_INVOKED(K_3));

    //MMI_ASSERT(mmi_frm_invoke_post_event() == MMI_RET_OK);

    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dynamic_k_1, (void *)&data1));
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_2, mmi_cb_ut_dynamic_k_2, (void *)&data2));
    MMI_ASSERT(!mmi_frm_cb_has_event_reg(EVT_ID_FMGR_STEP_3, mmi_cb_ut_dynamic_k_3, (void *)&data3));

    RESET_CB_UT_INVOKED(K_1);
    RESET_CB_UT_INVOKED(K_2);
    RESET_CB_UT_INVOKED(K_3);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbmgr_ut_non_register
 * DESCRIPTION
 *  Unit test for non register event in mmi_frm_cb_cfg.h, should assert for action of reg & emit.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success, otherwise assert!
 *****************************************************************************/
MMI_BOOL mmi_cbmgr_ut_non_register(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmgr_evt_stuct fmgr_evt;
    U32 data1;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_cb_reg_event(EVT_ID_NON_REG, mmi_cb_ut_dynamic_k_1, (void *)&data1);

    //MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_NON_REG);
    //MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);

    return MMI_TRUE;
}
mmi_ret mmi_cb_ut_dy_cb_deg_1(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}
mmi_ret mmi_cb_ut_dy_cb_deg_3(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}
mmi_ret mmi_cb_ut_dy_cb_deg_2(mmi_event_struct *evt)
{
	mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_2, NULL);
    mmi_cb_ut_display_dyn_cb(EVT_ID_FMGR_STEP_1);
	return MMI_RET_OK;
}
MMI_BOOL mmi_cbmgr_ut_degreg_test(void)
{
	mmi_fmgr_evt_stuct fmgr_evt;
	mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_1, NULL);
	mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_2, NULL);
	mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_3, NULL);
	MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_STEP_1);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_1, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_3, NULL);

    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_2, NULL);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_1, NULL);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_3, NULL);
    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_STEP_1);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_1, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_3, NULL);
    
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_1, NULL);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_3, NULL);
    mmi_frm_cb_reg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_2, NULL);
    MMI_FRM_INIT_EVENT(&fmgr_evt, EVT_ID_FMGR_STEP_1);
    MMI_FRM_CB_EMIT_EVENT(&fmgr_evt);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_1, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_FMGR_STEP_1, mmi_cb_ut_dy_cb_deg_3, NULL);

	return MMI_TRUE;
}


void mmi_cbmgr_ut_stress(void)
{
    while (1)
    {
        mmi_cb_manager_ut_entry(0);
    }
}

/*****************************************************************************  
 * Function for test case driven engine
 *****************************************************************************/
typedef MMI_BOOL (*history_test_case_fp)(void);
typedef struct
{
    S8 index;
    history_test_case_fp test_case_func;
} _cbmgr_test_case_struct;

static const _cbmgr_test_case_struct cbmgr_test_case_db[] =
{
    /* Test all cases */
    {0, NULL},
	{1, mmi_cbmgr_ut_static},
	{2, mmi_cbmgr_ut_dynamic},
	{3, mmi_cbmgr_ut_dynamic_reg_unreg},
	{4, mmi_cbmgr_ut_IT_app},
	{5, mmi_cbmgr_ut_post_evt_q},
	{6, mmi_cbmgr_ut_emit_post_evt},
	{7, mmi_cbmgr_ut_emit_post_evt_ex},
	{8, mmi_cbmgr_ut_post_evt},
	{9, mmi_cbmgr_ut_post_evt_ex},
	{10, mmi_cbmgr_ut_reentry},
	{11, mmi_cbmgr_ut_non_register},
	{12, mmi_cbmgr_ut_degreg_test},
	{12, mmi_cbmgr_ut_dereg_in_emit},
    {-1, NULL}
};


/*****************************************************************************
 * FUNCTION
 *  mmi_cb_manager_ut_entry
 * DESCRIPTION
 * Callback manager test case entry function, could be invoked by catcher inject string
 * in mmi_proc_inject_string (events.c).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cb_manager_ut_entry(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == index)
    {
        /* Test all cases */
        U8 i = 1;
        while (cbmgr_test_case_db[i].index > 0 && cbmgr_test_case_db[i].test_case_func)
        {
            cbmgr_test_case_db[i].test_case_func();
            i++;
        }
    }
    else if (255 == index)
    {
        mmi_cbmgr_ut_stress();
    }
    else
    {
        cbmgr_test_case_db[index].test_case_func();
    }
}
#endif /* MMI_CB_MGR_UT */


