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
 * UMSrvCacheMgr.c
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

/**********  KAL Layer Header **************/
#include "string.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "lcd_sw_inc.h"
#include "customer_ps_inc.h"
#include "custom_wap_config.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Gui_Setting.h"
#include "wgui.h"
#include "gui_data_types.h"
#include "gui_switch.h"
#include "mmi_msg_context.h"
#include "Custom_ProvBox.h"

#include "UmSrvGprot.h"
#include "UmSrvProt.h"

typedef struct
{
    srv_um_msg_enum msg_type;
    srv_um_msg_box_enum msg_box_type;
    /* for the best solution, we should merge thread_id info msg_info
       howevery, it may influence too much people, so i decide put thread_id outside */
//    srv_um_thread_id_struct thread_id;
    srv_um_msg_info_struct msg_info;
} srv_um_cache_struct;

typedef union
{
    U8 cache_memory[SRV_UM_MIN_MSG_DETAIL_NUM * sizeof(srv_um_cache_struct)];
    U8 list_sort_memory[SRV_UM_LIST_SORT_MEMORY];
} srv_um_mem_pool_union;

#define SRV_UM_MSG_DETAIL_NUM (sizeof(srv_um_mem_pool_union)/sizeof(srv_um_cache_struct) + 1)

static S32 msg_detail_idx[SRV_UM_MSG_DETAIL_NUM];
static srv_um_cache_struct msg_detail_pool[SRV_UM_MSG_DETAIL_NUM];

static S32 memory_borrow_app_id = 0;

#define MEMORY_IS_BORROW_OUT (memory_borrow_app_id != 0)

typedef struct
{
    S32 list_cid;
    srv_um_list_cntx_struct list_cntx;
    srv_um_notify_list_handler cb_func;
    S32 user_data;
} srv_um_list_pool_struct;

#if (defined( __MMI_VUI_SHELL_APP__ )|| defined( __COSMOS_MMI_PACKAGE__ ))
#define SRV_UM_MSG_LIST_POOL_SIZE    3
#else
#define SRV_UM_MSG_LIST_POOL_SIZE    2
#endif
static srv_um_msg_node_struct msg_node_buffer[SRV_UM_MAX_MSG_NUM];    /* Data list */

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
static srv_um_thread_id_struct thread_id_buffer[SRV_UM_MAX_MSG_NUM];    /* Data list */
static srv_um_thread_info_struct thread_info_pool[SRV_UM_MAX_MSG_NUM];
#endif

static srv_um_list_pool_struct msg_list_pool[SRV_UM_MSG_LIST_POOL_SIZE];

/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_defrag
 * DESCRIPTION
 *  Find all the empty entry in cache. In order to avoid fragmentation in cache pool
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cache_defrag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MEMORY_IS_BORROW_OUT)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    j = SRV_UM_MSG_DETAIL_NUM - 1;

    /* move all items with value to the newest side */
    for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
    {
        if (msg_detail_pool[msg_detail_idx[i]].msg_type != 0)
        {
            msg_detail_idx[j] = msg_detail_idx[i];
            j--;
        }
    }

    /* assign all empty items to the oldest side */
    for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
    {
        if (msg_detail_pool[i].msg_type == 0)
        {
            msg_detail_idx[j] = i;
            j--;
        }
    }

    if (j != -1)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_add
 * DESCRIPTION
 *  add one or more message info into cache
 * PARAMETERS
 *  msg_type        [IN]    type of message
 *  msg_list        [IN]    list of message info
 *  msg_number      [IN]    size of message list
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cache_add(srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type, srv_um_msg_info_struct msg_list[], S32 msg_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    s32 i;
    S32 *tmp_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MEMORY_IS_BORROW_OUT)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    tmp_idx = get_ctrl_buffer(sizeof(S32) * msg_number);

    /* replace the oldest message with the new message */
    for (i = 0; i < msg_number; i++)
    {
        msg_detail_pool[msg_detail_idx[i]].msg_type = msg_type;
        msg_detail_pool[msg_detail_idx[i]].msg_box_type = msg_box_type;
        memcpy(&msg_detail_pool[msg_detail_idx[i]].msg_info, &msg_list[i], sizeof(srv_um_msg_info_struct));
        tmp_idx[i] = msg_detail_idx[i];

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_ADD, tmp_idx[i], msg_list[i].msg_id, msg_type, msg_box_type);
    }

    /* shift the message, remove the oldest message */
    for (i = 0; i < ((S32)SRV_UM_MSG_DETAIL_NUM - msg_number); i++)
    {
        msg_detail_idx[i] = msg_detail_idx[i + msg_number];
    }

    /* place newest message to the right side */
    for (i = 0; i < msg_number; i++)
    {
        msg_detail_idx[SRV_UM_MSG_DETAIL_NUM - msg_number + i] = tmp_idx[i];
    }

    free_ctrl_buffer(tmp_idx);

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_delete
 * DESCRIPTION
 *  Delete a message info from cache. Depends on message type and message id.
 * PARAMETERS
 *  msg_list        [IN]    list of message node which need to be deleted
 *  msg_number      [IN]    size of the list
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cache_delete(srv_um_msg_node_struct msg_list[], S32 msg_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MEMORY_IS_BORROW_OUT)
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
    {
        for (j = msg_number - 1; j >= 0; j--)
        {
            if (msg_list[j].msg_id == msg_detail_pool[i].msg_info.msg_id &&
                msg_list[j].msg_type == msg_detail_pool[i].msg_type)
            {
                memset(&msg_detail_pool[i], 0, sizeof(srv_um_cache_struct));

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_DELETE, i, msg_list[j].msg_id, msg_list[j].msg_type);
            }
        }
    }

    srv_um_cache_defrag();

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_clean
 * DESCRIPTION
 *  Clean the cache and initiate the index
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cache_clean(srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MEMORY_IS_BORROW_OUT)
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    if (msg_type == SRV_UM_MSG_ALL && msg_box_type == SRV_UM_MSG_BOX_ALL)
    {
        memset(msg_detail_pool, 0, sizeof(msg_detail_pool));
        for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
        {
            msg_detail_idx[i] = i;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_CLEAN);
    }
    else
    {
        for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= 0; i--)
        {
            if ((msg_detail_pool[i].msg_type & msg_type) &&
                (msg_detail_pool[i].msg_box_type & msg_box_type))
            {
                memset(&msg_detail_pool[i], 0, sizeof(srv_um_cache_struct));

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_CLEAN_1, i, msg_detail_pool[i].msg_info.msg_id, msg_detail_pool[i].msg_box_type);
            }
        }
        srv_um_cache_defrag();
    }

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_search
 * DESCRIPTION
 *  Search a message in cache. Depends on the message type and message id.
 * PARAMETERS
 *  msg_list        [IN]    The message basic information, includes message type and id
 *  fast_search     [IN]    If only search in the first page or not.
 * RETURNS
 *  the pointer of message info
 * RETURN VALUES
 *  NULL:   Not found
 *  Other:  the pointer of message info
 *****************************************************************************/
srv_um_msg_info_struct *srv_um_cache_search(srv_um_list_type_enum list_type, void *list, MMI_BOOL fast_search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, end;
    srv_um_msg_info_struct *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MEMORY_IS_BORROW_OUT)
    {
        return NULL;
    }

    if (list_type == SRV_UM_LIST_TYPE_MSG_NODE &&
        ((srv_um_msg_node_struct*)list)->msg_id == 0 && ((srv_um_msg_node_struct*)list)->msg_type == 0)
    {
        ASSERT(0);
        return NULL;
    }
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    else if (list_type == SRV_UM_LIST_TYPE_THREAD &&
        ((srv_um_thread_id_struct*)list)->type == 0 && ((srv_um_thread_id_struct*)list)->value == 0)
    {
        ASSERT(0);
        return NULL;
    }
#endif

    if (fast_search)
    {
        end = SRV_UM_MSG_DETAIL_NUM - SRV_UM_MAX_MSG_PER_PAGE;
    }
    else
    {
        end = 0;
    }

    for (i = SRV_UM_MSG_DETAIL_NUM - 1; i >= end; i--)
    {
        MMI_BOOL match = MMI_FALSE;

        /* very special case MAUI_02216896
           before get thread list and get thread info, phonebook is not ready
           after service get the data back, the phonebook is ready !
           so the thread id in cache table is old, not updated */

    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        if (list_type == SRV_UM_LIST_TYPE_THREAD)
        {
            srv_um_update_thread_id(&msg_detail_pool[msg_detail_idx[i]].msg_info.thread_id);
        }
    #endif

        if (list_type == SRV_UM_LIST_TYPE_MSG_NODE
           && ((srv_um_msg_node_struct*)list)->msg_id == msg_detail_pool[msg_detail_idx[i]].msg_info.msg_id
           && ((srv_um_msg_node_struct*)list)->msg_type == msg_detail_pool[msg_detail_idx[i]].msg_type
        #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
           && msg_detail_pool[msg_detail_idx[i]].msg_info.thread_id.type == SRV_UM_HASH_NONE
        #endif
            )
        {
            match = MMI_TRUE;
        }
    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        else if (list_type == SRV_UM_LIST_TYPE_THREAD
             && ((srv_um_thread_id_struct*)list)->type == msg_detail_pool[msg_detail_idx[i]].msg_info.thread_id.type
             && ((srv_um_thread_id_struct*)list)->value == msg_detail_pool[msg_detail_idx[i]].msg_info.thread_id.value
        #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
             && ((srv_um_thread_id_struct*)list)->sim_id == msg_detail_pool[msg_detail_idx[i]].msg_info.thread_id.sim_id
        #endif
             )
        {
            match = MMI_TRUE;
        }
    #endif

        if (match)
        {
            result = &(msg_detail_pool[msg_detail_idx[i]].msg_info);

            /* this item should move the newer side if the idx is too old */
            if (i < SRV_UM_MSG_DETAIL_NUM - SRV_UM_MAX_MSG_PER_PAGE)
            {
                S32 tmp_idx = msg_detail_idx[i];

                for (j = i; j < SRV_UM_MSG_DETAIL_NUM - 1; j++)
                {
                    msg_detail_idx[j] = msg_detail_idx[j + 1];
                }
                msg_detail_idx[SRV_UM_MSG_DETAIL_NUM - 1] = tmp_idx;
            }
            return result;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_init
 * DESCRIPTION
 *  initiate the cache
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cache_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_INIT);

    if (MEMORY_IS_BORROW_OUT)
    {
        return SRV_UM_RESULT_OK;
    }

    srv_um_cache_clean(SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL);

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_memory_borrow
 * DESCRIPTION
 *  borrow cache memory
 * PARAMETERS
 *  app_id      [IN]    application id
 *  size        [IN]    how much memory need to be borrowed
 * RETURNS
 *  The pointer of memory
 * RETURN VALUES
 *  NULL:   error
 *  Other:  pointer of memory
 *****************************************************************************/
void *srv_um_cache_memory_borrow(S32 app_id, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id == 0)
    {
        ASSERT(0);
        return NULL;
    }

    if (size > sizeof(msg_detail_pool))
    {
        ASSERT(0);
        return NULL;
    }

    memory_borrow_app_id = app_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_MEMORY_BORROW);

    return &msg_detail_pool;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cache_memory_return
 * DESCRIPTION
 *  return the cache memory
 * PARAMETERS
 *  app_id      [IN]    application id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cache_memory_return(S32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memory_borrow_app_id != app_id)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    memory_borrow_app_id = 0;

    srv_um_cache_init();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_MEMORY_RETURN);

    return SRV_UM_RESULT_OK;
}

#define INDEX_OF_LISTCID(cid) ((cid) & 0xFF)

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
static void srv_um_listmgr_reset(S32 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_cid = msg_list_pool[list_index].list_cid;
    srv_um_notify_list_handler cb_func = msg_list_pool[list_index].cb_func;
    S32 user_data = msg_list_pool[list_index].user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg_list_pool[list_index], 0, sizeof(srv_um_list_pool_struct));

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_CLEAN_CALLBACK);

    if (cb_func != NULL)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_CLEAN_CALLBACK);
        cb_func(SRV_UM_NOTIFY_LIST_RELEASED_IND, list_cid, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
static MMI_BOOL srv_um_listmgr_is_invalid(S32 list_cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((list_index >= SRV_UM_MSG_LIST_POOL_SIZE)
        || (msg_list_pool[list_index].list_cid != list_cid)
        )
    {
        ASSERT(0);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_listmgr_create(srv_um_list_type_enum list_type, void **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 new_list_index = -1;
    U32 ticks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0 ; i < SRV_UM_MSG_LIST_POOL_SIZE ; i++)
    {
        /* Empty*/
        if (msg_list_pool[i].list_cid == 0)
        {
            new_list_index = i;
            break;
        }
        /* Not Empty but no owner */
        else if (msg_list_pool[i].cb_func == NULL)
        {
            new_list_index = i;
        }
    }

    if (new_list_index < 0)
    {
        ASSERT(0);
        return SRV_UM_RESULT_TOO_MANY_LIST;
    }

    /* we only have one msg_node_buffer and one thread_id_buffer now
       so we need to check if any list use this two buffer now */
    for (i = 0; i < SRV_UM_MSG_LIST_POOL_SIZE ; i ++)
    {
        MMI_BOOL reset_list = MMI_FALSE;

        if (list_type == SRV_UM_LIST_TYPE_MSG_NODE && msg_list_pool[i].list_cntx.list == msg_node_buffer)
        {
            reset_list = MMI_TRUE;
        }
    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        else if (list_type == SRV_UM_LIST_TYPE_THREAD && msg_list_pool[i].list_cntx.list == thread_id_buffer)
        {
            reset_list = MMI_TRUE;
        }
    #endif

        if (reset_list)
        {
            srv_um_listmgr_reset(i);
        }
    }

    kal_get_time(&ticks);

    msg_list_pool[new_list_index].list_cid = ((ticks & 0x7FFFFF00) | new_list_index);

    msg_list_pool[new_list_index].list_cntx.list_type = list_type;

    if (list_type == SRV_UM_LIST_TYPE_MSG_NODE)
    {
        msg_list_pool[new_list_index].list_cntx.list = (void*)msg_node_buffer;
        memset(msg_list_pool[new_list_index].list_cntx.list, 0, sizeof(srv_um_msg_node_struct) * SRV_UM_MAX_MSG_NUM);
    }
    else
    {
    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        msg_list_pool[new_list_index].list_cntx.list = (void*)thread_id_buffer;
        memset(msg_list_pool[new_list_index].list_cntx.list, 0, sizeof(srv_um_thread_id_struct) * SRV_UM_MAX_MSG_NUM);
    #else
        EXT_ASSERT(0,0,0,0);
    #endif
    }

    msg_list_pool[new_list_index].cb_func = NULL;
    msg_list_pool[new_list_index].user_data = 0;

    *list = msg_list_pool[new_list_index].list_cntx.list;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_CREATE, msg_list_pool[new_list_index].list_cid);

    return msg_list_pool[new_list_index].list_cid;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_listmgr_delete(S32 list_cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_um_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_DELETE, list_cid);

    memset(&msg_list_pool[list_index], 0, sizeof(srv_um_list_pool_struct));

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_listmgr_clean(srv_um_list_type_enum list_type, srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < SRV_UM_MSG_LIST_POOL_SIZE ; i++)
    {
        if (list_type != SRV_UM_LIST_TYPE_ALL && msg_list_pool[i].list_cntx.list_type != list_type)
        {
            continue;
        }

        if ((msg_list_pool[i].list_cntx.msg_box.msg_type & msg_type) &&
            (msg_list_pool[i].list_cntx.msg_box.msg_box_type & msg_box_type))
        {
            srv_um_listmgr_reset(i);
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_CLEAN, msg_type, msg_box_type);

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_listmgr_register
 * DESCRIPTION
 *  register owner to specific list
 * PARAMETERS
 *  list_cid    [IN]    the cid of list
 *  cb_func     [IN]    the callback function
 *  user_data     [IN]    the parameter in callback function
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  = 0: success (SRV_UM_RESULT_OK)
 *  < 0: fail
 *****************************************************************************/
S32 srv_um_listmgr_register(S32 list_cid, srv_um_notify_list_handler cb_func, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_um_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    /* notify old owner */
    if (msg_list_pool[list_index].cb_func != NULL)
    {
        msg_list_pool[list_index].cb_func(SRV_UM_NOTIFY_LIST_RELEASED_IND, list_cid, msg_list_pool[list_index].user_data);
        
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_REGISTER);
    }

    msg_list_pool[list_index].cb_func = cb_func;
    msg_list_pool[list_index].user_data = user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_REGISTER_1, list_cid);

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_listmgr_unregister(S32 list_cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_um_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    msg_list_pool[list_index].cb_func = NULL;
    msg_list_pool[list_index].user_data = 0;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_UNREGISTER, list_cid);

    return SRV_UM_RESULT_OK;
}


static MMI_BOOL srv_um_listmgr_cmp_msg_box(srv_um_box_identity_struct src_msg_box, srv_um_box_identity_struct dest_msg_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src_msg_box.msg_type == dest_msg_box.msg_type)
        && (src_msg_box.msg_box_type == dest_msg_box.msg_box_type)
        && (src_msg_box.sim_id == dest_msg_box.sim_id)
        )
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


static MMI_BOOL srv_um_listmgr_cmp_msg_filter(srv_um_list_filter_struct src_filter, srv_um_list_filter_struct dest_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src_filter.idx_type == dest_filter.idx_type)
        && (src_filter.order == dest_filter.order)  
    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        && (src_filter.thread_id.type == dest_filter.thread_id.type)
        && (src_filter.thread_id.value == dest_filter.thread_id.value)
    #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        && (src_filter.thread_id.sim_id == dest_filter.thread_id.sim_id)
    #endif
    #endif
        )
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
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_listmgr_search(
    srv_um_list_type_enum list_type,
    srv_um_box_identity_struct msg_box,
    srv_um_list_filter_struct *filter,
    srv_um_list_cntx_struct **list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0 ; i < SRV_UM_MSG_LIST_POOL_SIZE ; i++)
    {
        if (srv_um_listmgr_cmp_msg_box(msg_list_pool[i].list_cntx.msg_box, msg_box) &&
            srv_um_listmgr_cmp_msg_filter(msg_list_pool[i].list_cntx.filter, *filter) &&
            msg_list_pool[i].list_cntx.list_type == list_type)
        {
            if (list_cntx)
            {
                *list_cntx = &(msg_list_pool[i].list_cntx);
            }
            return msg_list_pool[i].list_cid;
        }
    }

    if (list_cntx)
    {
        *list_cntx = NULL;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_SEARCH, list_type, msg_box.msg_type, msg_box.msg_box_type);

    return SRV_UM_RESULT_DATA_NOT_FOUND;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_listmgr_update_cntx(S32 list_cid, S32 msg_number, srv_um_box_identity_struct msg_box, srv_um_list_filter_struct *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_index = INDEX_OF_LISTCID(list_cid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_um_listmgr_is_invalid(list_cid))
    {
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    msg_list_pool[list_index].list_cntx.msg_number = msg_number;

    msg_list_pool[list_index].list_cntx.msg_box = msg_box;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_UPDATE_CNTX, list_cid, msg_number, msg_box.msg_type, msg_box.msg_box_type);

    if (filter)
    {
        memcpy(&msg_list_pool[list_index].list_cntx.filter, filter, sizeof(srv_um_list_filter_struct));

    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_LISTMGR_UPDATE_CNTX_1, filter->thread_id.type, (U32)((U64)filter->thread_id.value>>32), (U32)filter->thread_id.value);
    #endif
    }
    else
    {
        memset(&msg_list_pool[list_index].list_cntx.filter, 0, sizeof(srv_um_list_filter_struct));
    }

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_listmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(msg_list_pool, 0, sizeof(msg_list_pool));

    return SRV_UM_RESULT_OK;
}

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
srv_um_thread_info_struct *srv_um_thread_info_search(srv_um_thread_id_struct thread_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (thread_id.type == SRV_UM_HASH_NONE)
    {
        ASSERT(0);
        return NULL;
    }

    for (i = 0; i < SRV_UM_MAX_MSG_NUM ;i++)
    {
        srv_um_update_thread_id(&thread_info_pool[i].thread_id);

        if (thread_info_pool[i].thread_id.type  == thread_id.type
            && thread_info_pool[i].thread_id.value == thread_id.value
        #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
            && thread_info_pool[i].thread_id.sim_id == thread_id.sim_id
        #endif
            )
        {
            return &thread_info_pool[i];
        }
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
srv_um_thread_info_struct *srv_um_thread_info_get_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (index < 0 || index > SRV_UM_MAX_MSG_NUM)
    {
        ASSERT(0);
        return NULL;
    }

    return &thread_info_pool[index];
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
srv_um_thread_info_struct *srv_um_thread_info_set_by_index(S32 index, srv_um_thread_id_struct thread_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (thread_info_pool[index].thread_id.type == SRV_UM_HASH_NONE)
    {
        memcpy(&thread_info_pool[index].thread_id, &thread_id, sizeof(srv_um_thread_id_struct));
        return &thread_info_pool[index];
    }
    else
    {
        ASSERT(0);
        return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_thread_info_update(srv_um_thread_info_struct *thread_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!thread_info || thread_info->thread_id.type == SRV_UM_HASH_NONE)
    {
        ASSERT(0);
        return SRV_UM_RESULT_UNKNOWN_ERROR;
    }

    for (i = 0; i < SRV_UM_MAX_MSG_NUM ;i++)
    {
        srv_um_update_thread_id(&thread_info_pool[i].thread_id);

        if (thread_info_pool[i].thread_id.type  == thread_info->thread_id.type
            && thread_info_pool[i].thread_id.value == thread_info->thread_id.value
        #ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
            && thread_info_pool[i].thread_id.sim_id == thread_info->thread_id.sim_id
        #endif
            )
        {
            memcpy(&thread_info_pool[i], thread_info, sizeof(srv_um_thread_info_struct));
            return SRV_UM_RESULT_OK;
        }
    }

    return SRV_UM_RESULT_DATA_NOT_FOUND;
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
S32 srv_um_thread_info_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(thread_info_pool, 0, sizeof(thread_info_pool));

    return SRV_UM_RESULT_OK;
}
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
