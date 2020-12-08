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
 *  SmsBtMapCSrvStorageCore.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage Manager core codes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__

/**************************************************************
* Header Files Include
**************************************************************/
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "SmsBtMapCSrvUtil.h"
#include "SmsBtMapCSrvConverter.h"
#include "FileMgrSrvGProt.h"
#include "SmsBtMapCSrvStorage.h"
#include "Unicodexdcl.h"
#include "Conversions.h"
#include "MMI_trc_Int.h"
#include "MMI_common_app_trc.h"
#ifdef __SRV_SMS_BTMAPC__

/**************************************************************
* MARCO
**************************************************************/


srv_sms_btmapc_msg_node_struct srv_sms_btmapc_msg_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
srv_sms_btmapc_pdu_node_struct srv_sms_btmapc_pdu_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
U8 srv_sms_btmapc_pdu_detail[SRV_SMS_BTMAPC_MAX_SMS_ENTRY][SRV_SMS_BTMAPC_MAX_SPDU_SIZE];

srv_sms_btmapc_msg_index_struct srv_sms_btmapc_handle_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
sms_btmapc_storage_manager_cntx_struct sms_btmapc_storage_cntx;

srv_sms_btmapc_file_entry_struct sms_btmapc_file_mgr_common_table[SRV_SMS_BTMAPC_MAX_FILE_SUPPORT] =
{
    {
        SRV_SMS_BTMAPC_FILE_INDEX_SMS_INFO,
        sizeof(srv_sms_btmapc_msg_node_struct),
        SRV_SMS_BTMAPC_MAX_SMS_ENTRY
    },
    {
        SRV_SMS_BTMAPC_FILE_INDEX_SMS_PDU_INDEX,
        sizeof(srv_sms_btmapc_pdu_node_struct),
        SRV_SMS_BTMAPC_MAX_SMS_ENTRY
    },
    {
        SRV_SMS_BTMAPC_FILE_INDEX_SMS_PDU,
        sizeof(SRV_SMS_BTMAPC_MAX_SPDU_SIZE),
        SRV_SMS_BTMAPC_MAX_SMS_ENTRY,
    },
    {
        SRV_SMS_BTMAPC_FILE_INDEX_SMS_HD_INDEX,
        sizeof(srv_sms_btmapc_msg_index_struct),
        SRV_SMS_BTMAPC_MAX_SMS_ENTRY,
    }
};

extern srv_sms_btmapc_pdu_node_struct srv_sms_btmapc_pdu_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
extern srv_sms_btmapc_msg_node_struct srv_sms_btmapc_msg_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];

/**************************************************************
* Static Function Declaration
**************************************************************/
static U16 srv_sms_btmapc_get_unused_msg_id(void);
MMI_BOOL srv_sms_btmapc_check_msg_flag(U16 msg_id, srv_sms_btmapc_node_flag_enum flag);

/**************************************************************
* Function Defination
**************************************************************/
MMI_BOOL custom_sms_btmapc_using_card_memory(void)
{
    return MMI_FALSE;
}


void srv_sms_btmapc_storage_init_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 read_size = 0;
    U32 real_size;
    FS_HANDLE fd = -1;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_get_file_name(SRV_SMS_BTMAPC_FILE_CNTX_INFO, MMI_FALSE, file_name);
    fd = FS_Open(file_name, FS_READ_ONLY);
    if(fd > 0)
    {
        read_size = sizeof(sms_btmapc_storage_manager_cntx_struct);
        FS_Read(fd, &sms_btmapc_storage_cntx, sizeof(sms_btmapc_storage_manager_cntx_struct), &real_size);
        if(read_size != real_size)
        {
            memset(&sms_btmapc_storage_cntx, 0, sizeof(sms_btmapc_storage_manager_cntx_struct));
        }
        FS_Close(fd);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_NO_FIIE, 1);
        memset(&sms_btmapc_storage_cntx, 0, sizeof(sms_btmapc_storage_manager_cntx_struct));
    }
    
    if(sms_btmapc_storage_cntx.total_msg_num > 0)
    {
        read_size = sizeof(srv_sms_btmapc_msg_node_struct) * SRV_SMS_BTMAPC_MAX_SMS_ENTRY;
        srv_sms_btmapc_get_file_name(SRV_SMS_BTMAPC_FILE_INDEX_SMS_INFO, MMI_FALSE, file_name);
        fd = FS_Open(file_name, FS_READ_ONLY);

        if(fd > 0)
        {
            FS_Read(fd, srv_sms_btmapc_msg_list, read_size, &real_size);
            if(read_size != real_size)
            {
                for (i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
                {
                    srv_sms_btmapc_msg_list[i].status = SRV_SMS_STATUS_NONE;
                    srv_sms_btmapc_msg_list[i].is_download= MMI_FALSE;
                    srv_sms_btmapc_msg_list[i].msg_id = SRV_SMS_INVALID_MSG_ID;
                }
            }
            FS_Close(fd);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_NO_FIIE, 2);
            for (i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
            {
                srv_sms_btmapc_msg_list[i].status = SRV_SMS_STATUS_NONE;
                srv_sms_btmapc_msg_list[i].is_download= MMI_FALSE;
                srv_sms_btmapc_msg_list[i].msg_id = SRV_SMS_INVALID_MSG_ID;
            }
        }
    }
    else
    {
        for (i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
        {
            srv_sms_btmapc_msg_list[i].status = SRV_SMS_STATUS_NONE;
            srv_sms_btmapc_msg_list[i].is_download= MMI_FALSE;
            srv_sms_btmapc_msg_list[i].msg_id = SRV_SMS_INVALID_MSG_ID;
        }
    }
}


void srv_sms_btmapc_storage_save_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    U16 read_size = 0;
    U32 real_size;
    FS_HANDLE fd = -1;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_get_file_name(SRV_SMS_BTMAPC_FILE_CNTX_INFO, MMI_FALSE, file_name);
    fd = FS_Open(file_name, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if(fd > 0)
    {
        read_size = sizeof(sms_btmapc_storage_manager_cntx_struct);
        result = FS_Write(fd, &sms_btmapc_storage_cntx, read_size, &real_size);
        FS_Close(fd);
    }
    if(result < 0)
    {
        FS_Delete(file_name);
        //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_WRITE_FAIL, 1);
        result = 0;
    }
    
    read_size = sizeof(srv_sms_btmapc_msg_node_struct) * SRV_SMS_BTMAPC_MAX_SMS_ENTRY;
    srv_sms_btmapc_get_file_name(SRV_SMS_BTMAPC_FILE_INDEX_SMS_INFO, MMI_FALSE, file_name);
    fd = FS_Open(file_name, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if(fd > 0)
    {
        result = FS_Write(fd, srv_sms_btmapc_msg_list, read_size, &real_size);
        FS_Close(fd);
    }
    if(result < 0)
    {
        FS_Delete(file_name);
        //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_WRITE_FAIL, 2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_storage_reset_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_storage_reset_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STORAGE_RESET_DATA);
    srv_sms_btmapc_get_file_name(SRV_SMS_BTMAPC_FILE_CNTX_INFO, MMI_FALSE, file_name);
    FS_Delete(file_name);
    
    srv_sms_btmapc_get_file_name(SRV_SMS_BTMAPC_FILE_INDEX_SMS_INFO, MMI_FALSE, file_name);
    FS_Delete(file_name);
    
    for (i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
    {
        srv_sms_btmapc_msg_list[i].status = SRV_SMS_STATUS_NONE;
        srv_sms_btmapc_msg_list[i].is_download= MMI_FALSE;
        srv_sms_btmapc_msg_list[i].msg_id = SRV_SMS_INVALID_MSG_ID;
    }
    memset(&sms_btmapc_storage_cntx, 0, sizeof(sms_btmapc_storage_manager_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_msg_id
 * DESCRIPTION
 *  Get unused message ID
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 (Unused Message ID)
 *****************************************************************************/
static U16 srv_sms_btmapc_get_unused_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    U16 start_msg_id = sms_btmapc_storage_cntx.unused_msg_head_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = start_msg_id; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
    {
        /* If the status is invalid, this msg node is not used */
        if (srv_sms_btmapc_msg_list[i].status == SRV_SMS_STATUS_NONE)
        {
            msg_id = i;
            break;
        }
    }
    return msg_id;
}


MMI_BOOL srv_sms_btmapc_is_msg_download(U16 msg_id)
{
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    
    if(srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, file_name);
        if(srv_sms_btmapc_file_exist(file_name) == MMI_TRUE)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


void srv_sms_btmapc_set_msg_download(U16 msg_id)
{    
    if(srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        srv_sms_btmapc_msg_list[msg_id].is_download = MMI_TRUE;
    }
}


U8* srv_sms_btmapc_get_msg_handle(U16 msg_id)
{
    if(srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
    {
        return srv_sms_btmapc_msg_list[msg_id].msg_handle;
    }
    return NULL;
}


U16 srv_sms_btmapc_get_msg_id_by_handle(U8 *handle)
{
    int i = 0;
    WCHAR msg_handle_temp[SRV_BT_MAP_MAX_HANDLE_STR_LEN + 1] = {0};

    mmi_asc_to_ucs2((CHAR *)msg_handle_temp, (CHAR *)handle);
    for(i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
    {
        if((srv_sms_btmapc_msg_list[i].msg_id != SRV_SMS_INVALID_MSG_ID) &&
            (kal_wstrcmp((WCHAR *)srv_sms_btmapc_msg_list[i].msg_handle, msg_handle_temp) == 0))
        {
            return srv_sms_btmapc_msg_list[i].msg_id;
        }
    }
    return SRV_SMS_INVALID_MSG_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_node
 * DESCRIPTION
 *  Add a Message Node
 * PARAMETERS
 *  msg_node        [IN] message node data
 * RETURNS
 *  U16 (the new Added Message ID)
 *****************************************************************************/
U16 srv_sms_btmapc_add_msg_node(srv_sms_btmapc_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unused_msg_id = srv_sms_btmapc_get_unused_msg_id();

    if (unused_msg_id != SRV_SMS_INVALID_MSG_ID)
    {
        msg_node->msg_id = unused_msg_id;
        memcpy(&srv_sms_btmapc_msg_list[unused_msg_id], msg_node, sizeof(srv_sms_btmapc_msg_node_struct));

        sms_btmapc_storage_cntx.total_msg_num++;

        /* unused_msg_id is the first unused msg, so its next msg is the new unused msg */
        if (sms_btmapc_storage_cntx.unused_msg_head_id < SRV_SMS_BTMAPC_MAX_SMS_ENTRY)
        {
            sms_btmapc_storage_cntx.unused_msg_head_id = unused_msg_id + 1;
        }
        
        if (unused_msg_id > sms_btmapc_storage_cntx.used_msg_tail_id)
        {
            sms_btmapc_storage_cntx.used_msg_tail_id = unused_msg_id;
        }
    }
    return unused_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_delete_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id < SRV_SMS_BTMAPC_MAX_SMS_ENTRY);

    if (srv_sms_btmapc_msg_list[msg_id].status != SRV_SMS_STATUS_NONE)
    {
        /* Reset Msg Node to unused;
         * If the status is NONE, the start_pdu_id must be Invalid */
        srv_sms_btmapc_msg_list[msg_id].status = SRV_SMS_STATUS_NONE;
        srv_sms_btmapc_msg_list[msg_id].is_download = MMI_FALSE;
        srv_sms_btmapc_msg_list[msg_id].msg_id = SRV_SMS_INVALID_MSG_ID;
        /* Decrement Total Msg Number */
        sms_btmapc_storage_cntx.total_msg_num--;

        /* Adjust remind (Unused Header, and Used Tail) index */
        if (sms_btmapc_storage_cntx.unused_msg_head_id > msg_id)
        {
            sms_btmapc_storage_cntx.unused_msg_head_id = msg_id;
        }
        /* If it is the last used msg, decrement the count */
        if ((msg_id == sms_btmapc_storage_cntx.used_msg_tail_id) && 
                 (sms_btmapc_storage_cntx.used_msg_tail_id > 0))
        {
            sms_btmapc_storage_cntx.used_msg_tail_id--;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_update_msg_node(
        U16 msg_id,
        srv_sms_btmapc_msg_node_struct *msg_node,
        U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_msg_node_struct *curr_msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id < SRV_SMS_BTMAPC_MAX_SMS_ENTRY);

    curr_msg_node = &srv_sms_btmapc_msg_list[msg_id];

    if ((curr_msg_node->status & SRV_SMS_STATUS_READ) &&
        (msg_node->status & SRV_SMS_STATUS_UNREAD))
    {
        //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_NODE_1);
        curr_msg_node->status &= SRV_SMS_STATUS_UNSUPPORTED;
        curr_msg_node->status |= SRV_SMS_STATUS_UNREAD;
    }

    if (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        curr_msg_node->status |= SRV_SMS_STATUS_UNSUPPORTED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_btmapc_msg_node_struct* srv_sms_btmapc_get_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &srv_sms_btmapc_msg_list[msg_id];
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_get_msg_info(srv_sms_msg_info_struct* msg_info, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_msg_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_INFO, msg_id);
    MMI_ASSERT(msg_id < SRV_SMS_BTMAPC_MAX_SMS_ENTRY);
    msg_node = &srv_sms_btmapc_msg_list[msg_id];

    srv_sms_btmapc_msg_node_to_msg_info(msg_info, msg_node);
    msg_info->sr_status = SRV_SMS_SRS_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_msg_op_conflict
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_check_msg_op_conflict(U16 msg_id, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_MSG_OP_CONFLICT_1, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_me_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_read_me_sms(U16 msg_id, SrvSmsCallbackFunc callback_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    U8 *utf_buff;
    U16 read_size = 0;
    U32 real_size;
    S32 result;
    srv_sms_btmapc_read_cntx_struct *read_cntx = (srv_sms_btmapc_read_cntx_struct *)user_data;
    srv_sms_msg_data_struct *msg_data = read_cntx->msg_data;
    FS_HANDLE hd = -1;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_READ_MSG, msg_id);
    srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, file_name);
    read_size = msg_data->content_buff_size;
        
    hd = FS_Open(file_name, FS_READ_ONLY);
    if(hd > 0)
    {
        utf_buff = (U8 *)OslMalloc(read_size + 1);
        result = FS_Read(hd, utf_buff, read_size, &real_size);
        FS_Close(hd);
        if(result < 0)
        {
            SMS_BTMAPC_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_READ,
                SRV_SMS_CAUSE_FS_ERROR,
                user_data,
                callback_func);
        }
        else
        {
            read_size = real_size;
            msg_data->content_size = (read_size + 1) * ENCODING_LENGTH;
            mmi_chset_utf8_to_ucs2_string((U8 *)msg_data->content_buff, msg_data->content_size, utf_buff);
            srv_sms_btmapc_async_callback(
                SRV_SMS_ACTION_READ,
                MMI_TRUE,
                SRV_SMS_CAUSE_NO_ERROR,
                NULL,
                0,
                user_data,
                callback_func);
        }
        OslMfree(utf_buff);
    }
    else
    {
        SMS_BTMAPC_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_READ,
            SRV_SMS_BTMAPC_OP_FAIL,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_me_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_write_me_sms(
            U16 msg_id,
            CHAR *content,
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    U16 read_size = 0;
    U32 real_size;
    FS_HANDLE hd = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_WRITE_MSG, msg_id);
    srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, file_name);
    read_size = srv_sms_btmapc_get_msg_size(msg_id);
        
    hd = FS_Open(file_name, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if(hd > 0)
    {
        result = FS_Write(hd, content, read_size, &real_size);
        FS_Close(hd);
        if(result >= 0)
        {
            srv_sms_btmapc_async_callback(
                SRV_SMS_ACTION_SAVE,
                MMI_TRUE,
                SRV_SMS_CAUSE_NO_ERROR,
                NULL,
                0,
                user_data,
                callback_func);
        }
        else
        {
            SMS_BTMAPC_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_SAVE,
                SRV_SMS_BTMAPC_OP_FAIL,
                user_data,
                callback_func);
        }
    }
    else
    {
        SMS_BTMAPC_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_SAVE,
            SRV_SMS_BTMAPC_OP_FAIL,
            user_data,
            callback_func);
    }
}


void srv_sms_btmapc_get_msg_name(
                U16 msg_id,
                MMI_BOOL is_backup,
                WCHAR* ucs2_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR file_path[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    CHAR drive = (CHAR)custom_sms_btmapc_using_card_memory() ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/

    sprintf(
        file_path, 
        "%c:%s%d%s", 
        drive, 
        SRV_SMS_BTMAPC_SERVICE_FOLDER_NAME,
        msg_id,
        SRV_SMS_BTMAPC_ORIGINAL_FILE_EXT_NAME);
    mmi_asc_to_ucs2((CHAR*)ucs2_buff, file_path);
}


void srv_sms_btmapc_get_file_name(
                srv_sms_btmapc_file_index_enum file_index,
                MMI_BOOL is_backup,
                WCHAR* ucs2_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR file_path[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    CHAR drive = (CHAR)custom_sms_btmapc_using_card_memory() ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    if(file_index == SRV_SMS_BTMAPC_FILE_CNTX_INFO)
    {
        sprintf(
            file_path, 
            "%c:%s%s%s", 
            drive, 
            SRV_SMS_BTMAPC_SERVICE_FOLDER_NAME,
            SRV_SMS_BTMAPC_MSG_BTMAPC_CNTX_NAME,
            SRV_SMS_BTMAPC_ORIGINAL_FILE_EXT_NAME);
    }
    else if(file_index == SRV_SMS_BTMAPC_FILE_INDEX_SMS_INFO)
    {
        sprintf(
                file_path, 
                "%c:%s%s%s", 
                drive, 
                SRV_SMS_BTMAPC_SERVICE_FOLDER_NAME,
                SRV_SMS_BTMAPC_MSG_BTMAPC_NODE_NAME,
                SRV_SMS_BTMAPC_ORIGINAL_FILE_EXT_NAME);
    }
    mmi_asc_to_ucs2((CHAR*)ucs2_buff, file_path);
}


void srv_sms_btmapc_get_root_name(WCHAR* ucs2_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR file_path[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    CHAR drive = (CHAR)custom_sms_btmapc_using_card_memory() ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    sprintf(
        file_path, 
        "%c:%s", 
        drive, 
        SRV_SMS_BTMAPC_SERVICE_FOLDER_NAME);

    mmi_asc_to_ucs2((CHAR*)ucs2_buff, file_path);
}

#endif /* __SRV_SMS_BTMAPC__ */
#endif /* __MOD_SMSAL__ */
