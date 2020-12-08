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
*  ProvBoxMsgList.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file implements all kinds of message list operations.
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#include "Conversions.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "Custom_ProvBox.h"
#include "kal_trace.h"
#include "fs_func.h"
#include "fs_type.h"
#include "stack_config.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "fs_errcode.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_inet_app_trc.h"
#include "UmSrvDefs.h"
#include "ProvBoxSrvConfig.h"
#include "ProvBoxSrvProt.h"
#include "ProvBoxSrvGProt.h"
 
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_PROVBOX_MSG_SET_FLAG_MAX_MSG_NUM        (0xFF)      /* the max message number which can be set the same flag. */
/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);

static srv_provbox_result_enum srv_provbox_msg_get_store_msg_config_status(
                                srv_provbox_store_msg_config_status_struct *src_msg_config_status,
                                srv_provbox_msg_config_status_struct *dst_msg_config_status);

static srv_provbox_cmp_result_enum srv_provbox_msg_find_msg_node_by_id(
                                    srv_provbox_msg_node_struct *msg_node,
                                    U32 msg_id);

static srv_provbox_cmp_result_enum srv_provbox_msg_sort_node_by_timestamp(void *src, void *dst);

static srv_provbox_cmp_result_enum srv_provbox_msg_sort_node_by_msg_id(void *src, void *dst);

static SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC srv_provbox_msg_get_sort_func_by_type(
                                            srv_provbox_msg_sort_type_enum sort_type);

static srv_provbox_msg_node_struct *srv_provbox_msg_create_msg_node(srv_provbox_msg_node_type_enum node_type);

static void srv_provbox_msg_free_msg_node(srv_provbox_msg_node_struct *msg_node);

static srv_provbox_result_enum srv_provbox_msg_format_msg_node_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                srv_provbox_msg_node_type_enum format_node_type,
                                MMI_BOOL format_all);

static srv_provbox_result_enum srv_provbox_msg_info_base_to_sort(
                                srv_provbox_msg_base_info_struct *base_info,
                                srv_provbox_msg_sort_info_struct *sort_info,
                                srv_provbox_msg_sort_type_enum sort_type);

static srv_provbox_result_enum srv_provbox_msg_info_base_to_cmn(
                                srv_provbox_msg_base_info_struct *base_info,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_box_type_enum box_type);

static srv_provbox_result_enum srv_provbox_msg_info_base_to_store(
                                srv_provbox_msg_base_info_struct *base_info,
                                srv_provbox_msg_store_info_struct *store_info);

static srv_provbox_result_enum srv_provbox_msg_info_std_to_base(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_base_info_struct *base_info);

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
static srv_provbox_result_enum srv_provbox_msg_info_std_to_sort(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_sort_info_struct *sort_info,
                                srv_provbox_msg_sort_type_enum sort_type);
#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

static srv_provbox_result_enum srv_provbox_msg_info_std_to_cmn(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_box_type_enum box_type);

static srv_provbox_result_enum srv_provbox_msg_info_std_to_store(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_store_info_struct *store_info);

static srv_provbox_result_enum srv_provbox_msg_info_full_to_base(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_base_info_struct *base_info);

static srv_provbox_result_enum srv_provbox_msg_info_full_to_std(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_std_info_struct *std_info);

static srv_provbox_result_enum srv_provbox_msg_info_full_to_store(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_store_info_struct *store_info);

static srv_provbox_result_enum srv_provbox_msg_info_full_to_read(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_msg_pin_status_enum *pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status,
                                srv_provbox_box_type_enum box_type);

static srv_provbox_result_enum srv_provbox_msg_info_store_to_base(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_msg_base_info_struct *base_info);
static srv_provbox_result_enum srv_provbox_msg_info_store_to_std(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_msg_std_info_struct *std_info);

static srv_provbox_result_enum srv_provbox_msg_info_store_to_full(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_msg_full_info_struct *full_info);

static srv_provbox_result_enum srv_provbox_msg_info_store_to_mem(
                                srv_provbox_msg_store_info_struct *store_node,
                                srv_provbox_msg_node_struct *mem_node,
                                srv_provbox_msg_node_type_enum node_type);

static srv_provbox_result_enum srv_provbox_msg_info_new_msg_to_full(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_save_msg_req_struct *new_msg);

static srv_provbox_result_enum srv_provbox_msg_info_new_msg_to_store(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_save_msg_req_struct *new_msg);

static srv_provbox_result_enum srv_provbox_msg_check_store_info(srv_provbox_msg_store_info_struct *store_info);

static srv_provbox_result_enum srv_provbox_msg_parse_and_add_new_to_list(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_store_info_struct *store_info,
                                U32 *index);

static srv_provbox_msg_node_struct *srv_provbox_msg_new_node_from_store_info(
                                        srv_provbox_msg_store_info_struct *store_info,
                                        srv_provbox_msg_node_type_enum node_type);

static srv_provbox_result_enum srv_provbox_msg_load_info_to_list(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                srv_provbox_msg_node_type_enum load_node_type);

static srv_provbox_result_enum srv_provbox_msg_preprocess_new_msg(srv_provbox_save_msg_req_struct *new_msg);

static srv_provbox_result_enum srv_provbox_msg_check_new_msg(srv_provbox_save_msg_req_struct *new_msg);

static srv_provbox_result_enum srv_provbox_msg_delete_dirty_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 save_info_data,
                                U8 save_app_data,
                                U8 save_prov_data);

static srv_provbox_result_enum srv_provbox_msg_save_app_prov_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                srv_provbox_msg_data_struct *msg_data,
                                U8 *save_app_data,
                                U8 *save_prov_data);

static srv_provbox_result_enum srv_provbox_msg_save_new_msg_info_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 *save_info_data,
                                U32 *index);

static srv_provbox_result_enum srv_provbox_msg_save_msg_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 *save_info_data,
                                U8 *save_app_data,
                                U8 *save_prov_data);

static srv_provbox_result_enum srv_provbox_msg_save_extra_msg_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_full_info_struct *full_info,
                                U8 *save_info_data,
                                U8 *save_app_data,
                                U8 *save_prov_data);

static srv_provbox_result_enum srv_provbox_msg_save_msg_data_to_mem(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 save_prov_data,
                                U8 save_app_data,
                                U8 save_info_data);

static srv_provbox_result_enum srv_provbox_msg_copy_prov_data_to_mem(
                                srv_provbox_msg_data_struct *dst_data,
                                srv_provbox_msg_data_struct *src_data);

static srv_provbox_result_enum srv_provbox_msg_copy_app_data_to_mem(
                                srv_provbox_msg_data_struct *dst_data,
                                srv_provbox_msg_data_struct *src_data);

static srv_provbox_result_enum srv_provbox_msg_node_child_to_parent(
                                srv_provbox_msg_node_struct *child_node,
                                srv_provbox_msg_node_struct *parent_node);

static MMI_BOOL srv_provbox_msg_is_child_node_type(
                    srv_provbox_msg_node_type_enum src_node_type,
                    srv_provbox_msg_node_type_enum dst_node_type);

static srv_provbox_result_enum srv_provbox_msg_update_full_info_field(
                                srv_provbox_msg_full_info_struct *full_info,
                                U32 info_mask,
                                U32 install_time,
                                srv_provbox_msg_read_status_enum read_status,
                                srv_provbox_msg_pin_status_enum pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status);

static srv_provbox_result_enum srv_provbox_msg_save_full_info(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_full_info_struct *full_info,
                                MMI_BOOL create);

static srv_provbox_result_enum srv_provbox_msg_delete_prov_data_file(srv_provbox_box_type_enum box_type, U32 msg_id);

static srv_provbox_result_enum srv_provbox_msg_copy_prov_data_file(
                                U32 msg_id,
                                srv_provbox_box_type_enum src_box_type,
                                srv_provbox_box_type_enum dst_box_type);

static U32 srv_provbox_msg_get_undeletable_msg_num(srv_provbox_msg_list_struct *msg_list);

static srv_provbox_result_enum srv_provbox_msg_reset_sim_msg_stat(srv_provbox_sim_msg_stat_struct *sim_msg_stat);

static srv_provbox_result_enum srv_provbox_msg_stat_msg_list(srv_provbox_msg_list_struct *msg_list);

static srv_provbox_result_enum srv_provbox_msg_sim_msg_stat_add(
                                srv_provbox_sim_msg_stat_struct *sim_msg_stat,
                                U8 sim_id,
                                srv_provbox_msg_type_enum msg_type,
                                srv_provbox_msg_read_status_enum read_status);

static srv_provbox_result_enum srv_provbox_msg_sim_msg_stat_delete(
                                srv_provbox_sim_msg_stat_struct *sim_msg_stat,
                                U8 sim_id,
                                srv_provbox_msg_type_enum msg_type,
                                srv_provbox_msg_read_status_enum read_status);

static srv_provbox_result_enum srv_provbox_msg_sim_msg_status_read(
                                srv_provbox_sim_msg_stat_struct *sim_msg_stat,
                                U8 sim_id,
                                srv_provbox_msg_read_status_enum read_status);

static srv_provbox_result_enum srv_provbox_msg_is_deletable_msg(srv_provbox_msg_base_info_struct *base_info);

static srv_provbox_result_enum srv_provbox_msg_delete_all_deletable_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                S32 max_del_num);

static srv_provbox_result_enum srv_provbox_msg_delete_all_msg_for_each(
                                srv_provbox_msg_list_struct *msg_list,
                                S32 max_del_num, mmi_sim_enum sim_id);

static srv_provbox_result_enum srv_provbox_msg_load_msg_app_data_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index);

static srv_provbox_result_enum srv_provbox_msg_delete_msg_list(srv_provbox_msg_list_struct *msg_list, S32 max_del_num);

static srv_provbox_result_enum srv_provbox_msg_force_delete_msg_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index);

static srv_provbox_result_enum srv_provbox_msg_force_delete_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                U32 index,
                                MMI_BOOL in_list);

static srv_provbox_result_enum srv_provbox_msg_can_move_msg(
                                srv_provbox_msg_list_struct *cur_msg_list,
                                srv_provbox_msg_list_struct *new_msg_list,
                                U32 cur_index);

/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_is_sim_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_provbox_msg_is_sim_message(srv_provbox_msg_type_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == SRV_PROVBOX_MSG_TYPE_SIM_MMSICP)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_create_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type                [IN]        
 *  sort_type               [IN]        
 *  init_node_type          [IN]        
 *  init_msg_list_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_msg_list_struct *srv_provbox_msg_create_list(
                                srv_provbox_box_type_enum box_type,
                                srv_provbox_msg_sort_type_enum sort_type,
                                srv_provbox_msg_node_type_enum init_node_type,
                                S32 init_msg_list_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 max_rec_num;
    srv_provbox_file_id_enum file_id;
    srv_provbox_msg_list_struct *msg_list;


    #define SRV_PROVBOX_MSG_NODE_RECORD_SIZE        (sizeof(srv_provbox_msg_store_info_struct) + SRV_PROVBOX_FILE_REC_PACK_SIZE)
    #define SPV_PROVBOX_MSG_INFO_INIT_SIZE          (SRV_PROVBOX_FILE_INIT_MSG_NODE_NUM     * SRV_PROVBOX_MSG_NODE_RECORD_SIZE)
    #define SRV_PROVBOX_MSG_INFO_DEFRAG_SIZE        (SRV_PROVBOX_FILE_DEFRAG_MSG_NODE_NUM   * SRV_PROVBOX_MSG_NODE_RECORD_SIZE)
    #define SRV_PROVBOX_MSG_INFO_INC_SIZE           (SRV_PROVBOX_FILE_INC_MSG_NODE_NUM      * SRV_PROVBOX_MSG_NODE_RECORD_SIZE)

    #define  SRV_PROVBOX_MSG_APP_INIT_SIZE          (SRV_PROVBOX_FILE_INIT_MSG_NODE_NUM     * SRV_PROVBOX_FILE_COMMON_APP_DATA_SIZE)
    #define  SRV_PROVBOX_MSG_APP_DEFRAG_SIZE        (SRV_PROVBOX_FILE_DEFRAG_MSG_NODE_NUM   * SRV_PROVBOX_FILE_COMMON_APP_DATA_SIZE)
    #define  SRV_PROVBOX_MSG_APP_INC_SIZE           (SRV_PROVBOX_FILE_INC_MSG_NODE_NUM      * SRV_PROVBOX_FILE_COMMON_APP_DATA_SIZE)


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = SRV_PROVBOX_ALLOC_TYPE(srv_provbox_msg_list_struct);

    MMI_ASSERT(msg_list != NULL);

    if (msg_list == NULL)
        return NULL;

    msg_list->flag_stat.msg_flag = 0;
    for (i = 0; i < SRV_PROVBOX_MAX_U8_BIT_MASK_NUM; i++)
    {
        msg_list->flag_stat.flag_num[i] = 0;
    }
    srv_provbox_msg_reset_sim_msg_stat(&msg_list->sim_msg_stat);

    msg_list->box_type = box_type;
    msg_list->sort_type = sort_type;
    msg_list->init_node_type = init_node_type;
    msg_list->cursor = 0;

    if (box_type == SRV_PROVBOX_BOX_TYPE_INBOX)
    {
        max_rec_num = SRV_PROVBOX_MAX_INBOX_MSG_NUM;
    }
    
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__     
    else if (box_type == SRV_PROVBOX_BOX_TYPE_ARCHIVE)
    {
        max_rec_num = SRV_PROVBOX_MAX_ARCHIVE_MSG_NUM;
    }
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    else
    {
        /* the max number of extra message, the scenario are: the max number of common messages are received,
           then receives all sim message. */
        max_rec_num = SRV_PROVBOX_MAX_INBOX_MSG_NUM + SRV_PROVBOX_MAX_EXT_MSG_NUM + SRV_PROVBOX_MAX_SIM_MSG_NUM;

#if 0 //slim
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
    }
    file_id = srv_provbox_file_get_info_file_id_by_box_type(box_type);
    msg_list->info_fh = srv_provbox_file_new_handle(
                            SPV_PROVBOX_MSG_INFO_INIT_SIZE,
                            SRV_PROVBOX_MSG_INFO_DEFRAG_SIZE,
                            SRV_PROVBOX_MSG_INFO_INC_SIZE,
                            file_id,
                            max_rec_num);

    file_id = srv_provbox_file_get_app_file_id_by_box_type(box_type);
    msg_list->app_fh = srv_provbox_file_new_handle(
                            SRV_PROVBOX_MSG_APP_INIT_SIZE,
                            SRV_PROVBOX_MSG_APP_DEFRAG_SIZE,
                            SRV_PROVBOX_MSG_APP_INC_SIZE,
                            file_id,
                            max_rec_num);

    msg_list->msg_ah = srv_provbox_dpary_new(
                        init_msg_list_size > 0 ? init_msg_list_size : SRV_PROVBOX_MSG_LIST_INIT_SIZE,
                        SRV_PROVBOX_MSG_LIST_INC_SIZE,
                        SRV_PROVBOX_MSG_LIST_DEC_SIZE,
                        srv_provbox_app_alloc,
                        srv_provbox_app_free);

    MMI_ASSERT(msg_list->info_fh != 0 && msg_list->app_fh != 0 && msg_list->msg_ah != 0);

    return msg_list;
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  sim_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_msg_get_msg_num(srv_provbox_msg_list_struct *msg_list, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;
    U8 i;
    srv_provbox_sim_msg_stat_struct * sim_msg_stat_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return 0;

    sim_msg_stat_p = &msg_list->sim_msg_stat;
    /* if sim_id is multi-sim_id, this function still support this case */
    for (i = 0; sim_id != 0; i++)
    {
        if (SRV_PROVBOX_GET_VAILD_SIM_ID(sim_id, i) > 0)
        {
            msg_num += sim_msg_stat_p->sim_read_num[i] + sim_msg_stat_p->sim_unread_num[i];
            SRV_PROVBOX_RESET_BIT_VALUE(sim_id, i);
        }
    } /*  Gemini_Plus */

    return msg_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_sim_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  sim_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_msg_get_sim_msg_num(srv_provbox_msg_list_struct *msg_list, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return 0;

    /* if sim_id is multi-sim_id, this function still support this case */
    for (i = 0; sim_id != 0; i++)
    {
        if (SRV_PROVBOX_GET_VAILD_SIM_ID(sim_id, i) > 0)
        {
            msg_num += msg_list->sim_msg_stat.sim_sim_msg_num[i];
            SRV_PROVBOX_RESET_BIT_VALUE(sim_id, i);
        }
    }

    return msg_num;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_sim_id_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  index           [IN]        
 *  sim_id          [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_sim_id_by_index(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 index,
                            U8 *sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    *sim_id = MMI_SIM1;
    if (msg_list == NULL || msg_list->msg_ah == 0 || 0 == (msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah)) ||
        index >= msg_num)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);
    if (base_info == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    *sim_id = SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info));
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_msg_node_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  index           [IN]        
 *  msg_node        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_msg_node_by_index(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 index,
                            srv_provbox_msg_node_struct **msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_node == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    *msg_node = NULL;
    if (msg_list == NULL || msg_list->msg_ah == 0 || 0 == (msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah)) ||
        index >= msg_num)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)msg_node);
    return SRV_PROVBOX_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_format_msg_list_section
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  start_index     [IN]        
 *  op_msg_num      [IN]        
 *  format_all      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_format_msg_list_section(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 start_index,
                            U32 op_msg_num,
                            MMI_BOOL format_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 msg_num;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_OK;
    msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah);

    for (i = start_index; i < start_index + op_msg_num; i++)
    {
        if (i >= msg_num)
            break;
        result = srv_provbox_msg_format_msg_node_by_index(msg_list, i, (srv_provbox_msg_node_type_enum)msg_list->init_node_type, format_all);
        if (result != SRV_PROVBOX_RESULT_OK)
            break;
    }
    return SRV_PROVBOX_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_format_msg_list_except
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list                [IN]        
 *  except_box_type         [IN]        
 *  except_start_index      [IN]        
 *  except_msg_num          [IN]        
 *  format_all              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_format_msg_list_except(
                            srv_provbox_msg_list_struct *msg_list,
                            srv_provbox_box_type_enum except_box_type,
                            U32 except_start_index,
                            U32 except_msg_num,
                            MMI_BOOL format_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_OK;
    msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah);
    if (msg_list->box_type == except_box_type)
    {
        srv_provbox_msg_format_msg_list_section(msg_list, 0, except_start_index, format_all);
        srv_provbox_msg_format_msg_list_section(
            msg_list,
            except_start_index + except_msg_num,
            msg_num - except_start_index - except_msg_num,
            format_all);
    }
    else
        srv_provbox_msg_format_msg_list_section(msg_list, 0, msg_num, format_all);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_init_multi_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  load_msg_num        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_init_multi_msg_node(srv_provbox_msg_list_struct *msg_list, S32 load_msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 msg_id;
    MMI_BOOL ret;
    S32 data_size;
    U32 max_rec_num;
    int cur_load_num = 0;
    srv_provbox_result_enum result;
    srv_provbox_result_enum result2;
    srv_provbox_check_info_struct check_info;
    srv_provbox_msg_store_info_struct store_info;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_OK;

    MMI_ASSERT(msg_list->info_fh != 0 && msg_list->app_fh != 0);

    max_rec_num = srv_provbox_file_get_record_num(msg_list->info_fh);
    if (max_rec_num == 0)
        return SRV_PROVBOX_RESULT_OK;

    if (msg_list->cursor >= max_rec_num)    /* check if too many messages are found. */
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_INIT_NULTI_MSG_NODE_CHECK,
            msg_list->box_type,
            max_rec_num,
            msg_list->cursor);
        return SRV_PROVBOX_RESULT_OK;
    }

    result = srv_provbox_file_cursor_read_index_record(
                msg_list->info_fh,
                &msg_id,
                &store_info,
                sizeof(srv_provbox_msg_store_info_struct),
                &data_size,
                msg_list->cursor);

    while (msg_list->cursor < max_rec_num)
    {
        if (result == SRV_PROVBOX_RESULT_OK)    /* if read record ok, try to parse it. */
        {
            result = srv_provbox_msg_parse_and_add_new_to_list(msg_list, &store_info, &index);

            MMI_ASSERT(data_size == sizeof(srv_provbox_msg_store_info_struct));

            if (result == SRV_PROVBOX_RESULT_OK)    /* if parse ok. */
            {
                /* check if load extra message, if so, set flag to indicate it's already saved to file. */
                if (msg_list->box_type == SRV_PROVBOX_BOX_TYPE_EXTRA)
                {
                    ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);
                    if (ret == MMI_TRUE && base_info)
                        SRV_PROVBOX_SET_FLAG(base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_NEW_MSG_SAVED);
                }
            }

        }
        /* check if need to stop here, may need to add other error code. */
        if (result == SRV_PROVBOX_RESULT_MEM_FULL || result == SRV_PROVBOX_RESULT_NOT_FOUND ||
            result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND || result == SRV_PROVBOX_RESULT_FILE_OP_FAIL ||
            result == SRV_PROVBOX_RESULT_FILE_ERR_SIZE)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_INIT_MULTI_MSG_NODE_INFO,
                msg_list->box_type,
                msg_list->cursor,
                msg_id,
                store_info.bit_prop,
                result);
            break;
        }
        /* if read record error or parse record error, just to check the content of this record, if error, delete this message and try to load next one. */
        else if (result != SRV_PROVBOX_RESULT_OK)   /* mainly SRV_PROVBOX_RESULT_PARSE_ERROR here. */
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_INIT_MULTI_MSG_NODE_INFO,
                msg_list->box_type,
                msg_list->cursor,
                msg_id,
                store_info.bit_prop,
                result);

            srv_provbox_file_set_check_info(
                &check_info,
                SRV_PROVBOX_CHECK_TYPE_DELETE,
                msg_list->box_type,
                msg_id, /* it's better to use msg_id install of store_info.msg_id. */
                0,
                0,
                -1,
                -1);

            /* write check file, if write fail, shall check this next time to initialize the mesage list. */
            result2 = srv_provbox_file_write_check_file(&check_info);
            if (result2 != SRV_PROVBOX_RESULT_OK)
                break;
        }

        msg_list->cursor++; /* begin to read next record even parse error. */
        cur_load_num++;
        if (msg_list->cursor >= max_rec_num)
        {
            result = SRV_PROVBOX_RESULT_OK;
            break;
        }
        if (cur_load_num >= load_msg_num)
        {
            result = SRV_PROVBOX_RESULT_CONTINUE;
            break;
        }

        result = srv_provbox_file_cursor_read_next_record(
                    msg_list->info_fh,
                    &msg_id,
                    &store_info,
                    sizeof(srv_provbox_msg_store_info_struct),
                    &data_size);
    }

    if (result != SRV_PROVBOX_RESULT_CONTINUE)
        msg_list->cursor = 0;

    /* if continue to async, or stop. */
    srv_provbox_file_cursor_read_record_close(msg_list->info_fh, NULL);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_ext_msg_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_save_ext_msg_by_index(srv_provbox_msg_list_struct *msg_list, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 save_app_data = 0;
    U8 save_info_data = 0;
    U8 save_prov_data = 0;
    srv_provbox_result_enum result;
    srv_provbox_msg_full_info_struct *full_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&full_info);
    if (full_info == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    /*  check if this extra message is already save to file. */
    if (SRV_PROVBOX_CHECK_FLAG(full_info->msg_flag, SRV_PROVBOX_MSG_FLAG_NEW_MSG_SAVED))
        return SRV_PROVBOX_RESULT_OK;

    MMI_ASSERT(SRV_PROVBOX_MSG_GET_NODE_TYPE(full_info) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);

    result = srv_provbox_msg_save_extra_msg_data_to_file(
                msg_list,
                full_info,
                &save_info_data,
                &save_app_data,
                &save_prov_data);

    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    /* now, prov_data, app_data and info_data are all saved to file, set the saved flag. */
    MMI_ASSERT(save_info_data && save_app_data && save_prov_data);
    SRV_PROVBOX_SET_FLAG(full_info->msg_flag, SRV_PROVBOX_MSG_FLAG_NEW_MSG_SAVED);
    srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_SAVE_NEW, full_info->msg_id);

    srv_provbox_msg_format_msg_node_by_index(msg_list, index, (srv_provbox_msg_node_type_enum)msg_list->init_node_type, MMI_TRUE);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  new_msg         [IN]        
 *  save_type       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_save_msg(
                            srv_provbox_msg_list_struct *msg_list,
                            srv_provbox_save_msg_req_struct *new_msg,
                            srv_provbox_save_data_type_enum *save_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 save_app_data = 0;
    U8 save_info_data = 0;
    U8 save_prov_data = 0;
    srv_provbox_result_enum result;
    srv_provbox_check_info_struct check_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || new_msg == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    if (save_type)
        *save_type = SRV_PROVBOX_SAVE_DATA_TYPE_NONE;

    srv_provbox_msg_preprocess_new_msg(new_msg);
    result = srv_provbox_msg_check_new_msg(new_msg);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_SAVE_MSG_CHECK, new_msg->cmn_info.msg_id, result);
        return result;
    }

    srv_provbox_file_set_check_info(
        &check_info,
        SRV_PROVBOX_CHECK_TYPE_SAVE_NEW,
        msg_list->box_type,
        new_msg->cmn_info.msg_id,
        0,
        0,
        new_msg->msg_data.app_data_size,
        new_msg->msg_data.prov_data_size);

    result = srv_provbox_file_write_check_file(&check_info);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    result = srv_provbox_msg_save_msg_data_to_file(msg_list, new_msg, &save_info_data, &save_app_data, &save_prov_data);

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MSG_SAVE_MSG_TO_FILE,
        result,
        msg_list->box_type,
        new_msg->cmn_info.msg_id,
        save_info_data,
        save_app_data,
        save_prov_data);

    /* if return ok, prov_data, app_data, info_data are all saved to file, and msg info is inserted to message list. */
    if (result == SRV_PROVBOX_RESULT_OK)
    {
        MMI_ASSERT(save_info_data && save_app_data && save_prov_data);
        if (save_type)
            *save_type = SRV_PROVBOX_SAVE_DATA_TYPE_FILE;
        srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_SAVE_NEW, new_msg->cmn_info.msg_id);
        return SRV_PROVBOX_RESULT_OK;
    }
    /* unluckily, not return ok, at least the message info is not inserted to message list, or some data is not saved. */
    /* if memory full, do not try to save it to memory, force to delete it, may not add to message list */
    if (result == SRV_PROVBOX_RESULT_MEM_FULL)
    {
        /* the message info may not be insert to message list. */
        srv_provbox_msg_delete_dirty_msg(msg_list, new_msg, save_info_data, save_app_data, save_prov_data);
        return SRV_PROVBOX_RESULT_MEM_FULL;
    }
    result = srv_provbox_msg_save_msg_data_to_mem(msg_list, new_msg, save_prov_data, save_app_data, save_info_data);

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MSG_SAVE_MSG_TO_MEMORY,
        result,
        msg_list->box_type,
        new_msg->cmn_info.msg_id);

    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_msg_delete_dirty_msg(msg_list, new_msg, save_info_data, save_app_data, save_prov_data);
        return result;
    }
    /* do not delete check file because this message is still saved in memory. */

    if (save_type)
        *save_type = SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA;

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_max_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_msg_get_max_msg_id(srv_provbox_msg_list_struct *msg_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 app_id;
    U32 info_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return 0;
    info_id = srv_provbox_file_get_max_use_rec_id(msg_list->info_fh);
    app_id = srv_provbox_file_get_max_use_rec_id(msg_list->app_fh);
    if (info_id != app_id)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_GET_MAX_MSG_ID, msg_list->box_type, info_id, app_id);
    }

    return SRV_PROVBOX_GET_MAX_VALUE(info_id, app_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_list_index_by_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  msg_id          [IN]        
 *  index           [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_list_index_by_msg_id(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 msg_id,
                            U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    if (MMI_FALSE == srv_provbox_dpary_get_index_by_data(
                        msg_list->msg_ah,
                        (void*)msg_id,
                        (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_find_msg_node_by_id,
                        index))
    {
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    }
    else
    {
        return SRV_PROVBOX_RESULT_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_list_index_by_id_and_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  msg_id          [IN]        
 *  index           [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_list_index_by_id_and_box(
                            srv_provbox_cntx_struct *cntx,
                            srv_provbox_box_type_enum box_type,
                            U32 msg_id,
                            srv_provbox_msg_list_struct **msg_list,
                            U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_box_type_enum valid_box_type;
    srv_provbox_msg_list_struct *cur_msg_list = NULL;
	U32 box_type_enum = (U32)box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (box_type_enum)
    {
        valid_box_type = (srv_provbox_box_type_enum)SRV_PROVBOX_GET_SIMPLE_BOX_TYPE(box_type_enum, i);
        if (valid_box_type 
#ifndef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__   /* Should skip archive if not support */
            && valid_box_type != SRV_PROVBOX_BOX_TYPE_ARCHIVE
#endif            
            )
        {
            cur_msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, valid_box_type, NULL);
            result = srv_provbox_msg_get_list_index_by_msg_id(cur_msg_list, msg_id, index);
            if (SRV_PROVBOX_RESULT_OK == result)
            {
                *msg_list = cur_msg_list;
                break;
            }
        }
        SRV_PROVBOX_RET_BOX_TYPE(box_type_enum, i);
        i++;
    }
    
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_msg_data_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  index               [IN]        
 *  sim_id              [OUT]       
 *  app_data            [IN]        
 *  app_data_size       [OUT]       
 *  filename            [OUT]       
 *  name_len            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_msg_data_by_index(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 index,
                            U8 *sim_id,
                            void **app_data,
                            S16 *app_data_size,
                            U16 *filename,
                            S32 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fd;
    MMI_BOOL ret;
    S32 read_data_size;
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *msg_node;
    srv_provbox_msg_full_info_struct *full_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || sim_id == NULL || app_data_size == NULL ||
        app_data == NULL || filename == NULL || name_len <= 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    *sim_id = MMI_SIM1;
    *app_data = NULL;
    *app_data_size = -1;

    ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&msg_node);
    if (!ret)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(msg_node) != SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
    {
        result = srv_provbox_msg_load_info_to_list(msg_list, index, SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);
        if (result != SRV_PROVBOX_RESULT_OK)
            return result;
    }
    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&full_info);

    MMI_ASSERT(full_info != NULL);

    *sim_id = SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(full_info));
    if (full_info->msg_data.app_data_size <= 0)
    {
        *app_data = NULL;
        *app_data_size = -1;
    }
    else
    {
        MMI_ASSERT(msg_list->app_fh);
        *app_data_size = full_info->msg_data.app_data_size;
        *app_data = SRV_PROVBOX_MALLOC(*app_data_size);
        if (*app_data == NULL)
            return SRV_PROVBOX_RESULT_MEM_FULL;

        result = srv_provbox_file_read_record(
                    msg_list->app_fh,
                    full_info->msg_id,
                    *app_data,
                    *app_data_size,
                    &read_data_size);
        if (result != SRV_PROVBOX_RESULT_OK || read_data_size != *app_data_size)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_GET_MSG_DATA_BY_INDEX_READ_APP_DATA,
                full_info->msg_id,
                full_info->msg_data.app_data_size,
                full_info->msg_data.prov_data_size,
                result);

            SRV_PROVBOX_FREE(*app_data);
            *app_data_size = -1;
            if (result == SRV_PROVBOX_RESULT_OK)
                result = SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
            return result;
        }
        MMI_ASSERT(read_data_size == *app_data_size);
    }
    if (full_info->msg_data.prov_data_size < 0) /* the file size may be zero. */
    {
        filename[0] = '\0';
        return SRV_PROVBOX_RESULT_OK;
    }
    else
    {
        srv_provbox_file_get_prov_data_filename((srv_provbox_box_type_enum)msg_list->box_type, full_info->msg_id, filename, name_len);
        fd = FS_Open((const WCHAR*)filename, (UINT) FS_READ_ONLY);
        if (fd >= 0)
        {
            FS_Close(fd);
            return SRV_PROVBOX_RESULT_OK;
        }
        result = srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, fd);
        return result;
    }
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_msg_num_stat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  box_type            [IN]        
 *  sim_id              [IN]        
 *  box_msg_stat        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_msg_num_stat(
                            srv_provbox_msg_list_struct *msg_list,
                            srv_provbox_box_type_enum box_type,
                            U8 sim_id,
                            srv_provbox_box_msg_stat_struct *box_msg_stat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (box_msg_stat == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (msg_list == NULL)
    {
        if (box_type == SRV_PROVBOX_BOX_TYPE_INBOX)
            srv_provbox_msg_reset_sim_msg_stat(&box_msg_stat->imsg_stat);


#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        else if (box_type == SRV_PROVBOX_BOX_TYPE_ARCHIVE)
            srv_provbox_msg_reset_sim_msg_stat(&box_msg_stat->amsg_stat);
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        return SRV_PROVBOX_RESULT_OK;
    }

    switch (msg_list->box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
            srv_provbox_msg_copy_sim_msg_stat_by_sim_id(&box_msg_stat->imsg_stat, &msg_list->sim_msg_stat, sim_id);
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
            srv_provbox_msg_copy_sim_msg_stat_by_sim_id(&box_msg_stat->amsg_stat, &msg_list->sim_msg_stat, sim_id);
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_BOX_TYPE_EXTRA:
        default:
            MMI_ASSERT(0);
            break;
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_sort_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  sort_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_sort_msg_list(
                            srv_provbox_msg_list_struct *msg_list,
                            srv_provbox_msg_sort_type_enum sort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (msg_list->sort_type == sort_type)
        return SRV_PROVBOX_RESULT_OK;
    MMI_ASSERT(sort_type < SRV_PROVBOX_MSG_SORT_TYPE_MAX_ITEM);
    msg_list->sort_type = sort_type;
    srv_provbox_dpary_sort(msg_list->msg_ah, srv_provbox_msg_get_sort_func_by_type(sort_type));

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_sort_info_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  sim_id          [IN]        
 *  index           [IN]        
 *  sort_info       [OUT]       
 *  next_index      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_sort_info_by_index(
                            srv_provbox_msg_list_struct *msg_list,
                            U8 sim_id,
                             srv_provbox_msg_sort_type_enum sort_type,
                            U32 index,
                            srv_provbox_msg_sort_info_struct *sort_info,
                            U32 *next_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;
    srv_provbox_msg_base_info_struct *base_info;
#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
    srv_provbox_msg_std_info_struct *std_info;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || sort_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (next_index)
        *next_index = 0;

    if (msg_list->msg_ah == 0 || 0 == (msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah)) || index >= msg_num)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    if (next_index && index + 1 < msg_num)
        *next_index = index + 1;

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);

#ifndef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
    srv_provbox_msg_info_base_to_sort(base_info, sort_info, sort_type);

#else /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

    if (sort_type == SRV_PROVBOX_MSG_SORT_TYPE_MSG_TYPE || sort_type == SRV_PROVBOX_MSG_SORT_TYPE_READ_STATUS)
        srv_provbox_msg_info_base_to_sort(base_info, sort_info, sort_type);
    else
    {
        if (SRV_PROVBOX_MSG_GET_NODE_TYPE(base_info) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO)
           srv_provbox_msg_load_info_to_list(msg_list, index, SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO);
        srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&std_info);
        srv_provbox_msg_info_std_to_sort(std_info, sort_info, sort_type);
    }
#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_list_info_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  sim_id          [IN]        
 *  index           [IN]        
 *  cmn_info        [OUT]       
 *  next_index      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_list_info_by_index(
                            srv_provbox_msg_list_struct *msg_list,
                            U8 sim_id,
                            U32 index,
                            S16 *msg_size,
                            srv_provbox_msg_cmn_info_struct *cmn_info,
                            U32 *next_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;
    srv_provbox_result_enum result;
    srv_provbox_msg_base_info_struct *base_info;
    srv_provbox_msg_std_info_struct *std_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || cmn_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (next_index)
        *next_index = SRV_PROVBOX_INVALID_NEXT_INDEX;

    if (msg_list->msg_ah == 0 || 0 == (msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah)) || index >= msg_num)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);

    MMI_ASSERT(base_info != NULL);

    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(base_info) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO)
    {
        result = srv_provbox_msg_load_info_to_list(msg_list, index, SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO);
        if (result != SRV_PROVBOX_RESULT_OK)
        {
            srv_provbox_msg_info_base_to_cmn(base_info, cmn_info, (srv_provbox_box_type_enum)msg_list->box_type);
            return result;
        }
    }
    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&std_info);

    if (NULL != msg_size)
    {
#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
        *msg_size = std_info->msg_size;
#else
        *msg_size = 0;
#endif
    }

    result = srv_provbox_msg_info_std_to_cmn(std_info, cmn_info, (srv_provbox_box_type_enum)msg_list->box_type);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    if (next_index && index + 1 < msg_num)
        *next_index = index + 1;


/* Temp solution:  the sort feature may be turned off on Cosmos Slim project but Cosmos MMI still want to get the size info */
#if (!defined(__MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__))
    {
        srv_provbox_msg_full_info_struct *full_info;


        if (NULL != msg_size) 
        {
            if (SRV_PROVBOX_MSG_GET_NODE_TYPE(base_info) != SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
            {
                result = srv_provbox_msg_load_info_to_list(msg_list, index, SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);
                if (result != SRV_PROVBOX_RESULT_OK)
                   return result;
            }
            srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&full_info);

            *msg_size = full_info->msg_data.prov_data_size;

        }
    }
#endif /* (!defined(__MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)) */


    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_list_info_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  sim_id          [IN]        
 *  msg_id          [IN]        
 *  cmn_info        [OUT]       
 *  next_msg_id     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_list_info_by_id(
                            srv_provbox_msg_list_struct *msg_list,
                            U8 sim_id,
                            U32 msg_id,
                            S16 *msg_size,
                            srv_provbox_msg_cmn_info_struct *cmn_info,
                            U32 *next_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    MMI_BOOL ret;
    U32 next_index;
    srv_provbox_result_enum result;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || cmn_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (next_msg_id)
        *next_msg_id = SRV_PROVBOX_INVALID_MSG_ID;

    if (msg_list->msg_ah == 0 || 0 == srv_provbox_dpary_get_num(msg_list->msg_ah))
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    if (MMI_FALSE == srv_provbox_dpary_get_index_by_data(
                        msg_list->msg_ah,
                        (void*)msg_id,
                        (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_find_msg_node_by_id,
                        &index))
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    result = srv_provbox_msg_get_list_info_by_index(msg_list, sim_id, index, msg_size, cmn_info, &next_index);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    if (next_msg_id && next_index != SRV_PROVBOX_INVALID_NEXT_INDEX)
    {
        ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, next_index, (void **)&base_info);
        if (ret != MMI_FALSE)
            *next_msg_id = base_info->msg_id;
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_msg_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_delete_msg_by_index(srv_provbox_msg_list_struct *msg_list, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id;
    srv_provbox_check_info_struct check_info;
    srv_provbox_msg_base_info_struct *base_info;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_result_enum result1 = SRV_PROVBOX_RESULT_OK;
    srv_provbox_result_enum result2 = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* try not to malloc memory, to avoid delete fail if memory is fail. */
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (MMI_FALSE == srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info))
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    msg_id = base_info->msg_id; /* save msg_id before delete it */

    result = srv_provbox_msg_is_deletable_msg(base_info);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_DELETE_MSG_BY_INDEX_UNDELETE,
            msg_id,
            msg_list->box_type,
            result);
        return result;
    }

    srv_provbox_file_set_check_info(
        &check_info,
        SRV_PROVBOX_CHECK_TYPE_DELETE,
        msg_list->box_type,
        msg_id,
        0,
        0,
        -1,
        -1);

    result = srv_provbox_file_write_check_file(&check_info);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    result = srv_provbox_file_delete_record(msg_list->info_fh, msg_id);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_DELETE_MSG_BY_INDEX_DEL_INFO,
            msg_id,
            msg_list->box_type,
            result);

        srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_DELETE, msg_id);
        return result;
    }

    srv_provbox_msg_sim_msg_stat_delete(
        &msg_list->sim_msg_stat,
        SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info)),
        (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info),
        (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(base_info));

    srv_provbox_dpary_delete_elm_by_index(
        &msg_list->msg_ah,
        index,
        (SRV_PROVBOX_DPARY_FREE_ELM_FUNC) srv_provbox_msg_free_msg_node);

    /* base_info is not valid now, so please msg_id just stored before to free the message node. */
    result1 = srv_provbox_msg_delete_prov_data_file((srv_provbox_box_type_enum)msg_list->box_type, msg_id);

    result2 = srv_provbox_file_delete_record(msg_list->app_fh, msg_id);

    if ((result1 == SRV_PROVBOX_RESULT_OK || result1 == SRV_PROVBOX_RESULT_FILE_NOT_FOUND) &&
        (result2 == SRV_PROVBOX_RESULT_OK || result2 == SRV_PROVBOX_RESULT_NOT_FOUND))
        srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_DELETE, msg_id);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_msg_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_delete_msg_by_id(srv_provbox_msg_list_struct *msg_list, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (MMI_FALSE == srv_provbox_dpary_get_elm_by_data(
                        msg_list->msg_ah,
                        (void*)msg_id,
                        (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_find_msg_node_by_id,
                        (void **)&msg_node,
                        &index))
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    result = srv_provbox_msg_delete_msg_by_index(msg_list, index);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_force_delete_msg_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_force_delete_msg_by_id(srv_provbox_msg_list_struct *msg_list, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    void *elm = NULL;
    MMI_BOOL in_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    in_list = srv_provbox_dpary_get_elm_by_data(
                msg_list->msg_ah,
                (void*)msg_id,
                (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_find_msg_node_by_id,
                (void **)&elm,
                &index);

    return srv_provbox_msg_force_delete_msg(msg_list, msg_id, index, in_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_force_delete_sim_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  msg_type_list       [IN]        
 *  list_num            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_force_delete_sim_msg(
                            srv_provbox_msg_list_struct *msg_list,
                            srv_provbox_msg_type_enum *msg_type_list,
                            int list_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U32 index;
    U32 msg_num;
    MMI_BOOL ret;
    srv_provbox_msg_type_enum msg_type;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || msg_type_list == NULL || list_num <= 0)
        return SRV_PROVBOX_RESULT_OK;

    if (0 == srv_provbox_msg_get_sim_msg_num(msg_list, MMI_SIM_ALL))
        return SRV_PROVBOX_RESULT_OK;

    msg_num = srv_provbox_msg_get_msg_num(msg_list, MMI_SIM_ALL);

    for (index = 0; index < msg_num; index++)
    {
        ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);
        if (ret == MMI_FALSE)
            continue;

        msg_type = (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info);
        for (i = 0; i < list_num; i++)
        {
            if (msg_type == msg_type_list[i])
                break;
        }
        if (i == list_num)
            continue;

        srv_provbox_msg_force_delete_msg_by_index(msg_list, index);
        index--;    /* should decrease the index, because this element is deleted. */
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_all_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]            
 *  mode            [IN/OUT]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_delete_all_msg(
                            srv_provbox_msg_list_struct *msg_list,
                            srv_provbox_del_all_msg_mode_enum *mode, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;
#ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__
    U32 sim_num;
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */
    S32 un_del_num;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || mode == NULL)
        return SRV_PROVBOX_RESULT_OK;

    if (*mode == SRV_PROVBOX_DEL_ALL_MSG_MODE_UNDEFINED)
    {
        /* Check if has deletable message */
        msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah);
        un_del_num = srv_provbox_msg_get_undeletable_msg_num(msg_list);
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_DELETE_ALL_MSG_CHECK,
            msg_list->box_type,
            msg_num,
            un_del_num);

        if (msg_num == (U32) un_del_num)
            return SRV_PROVBOX_RESULT_READING;

        msg_list->cursor = 0;   /* use for mode deletable. */
        *mode = un_del_num == 0 ? SRV_PROVBOX_DEL_ALL_MSG_MODE_RESET : SRV_PROVBOX_DEL_ALL_MSG_MODE_DELETABLE;

#ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__
       sim_num = srv_provbox_msg_get_msg_num(msg_list, sim_id);
        if (sim_num == 0)
            return SRV_PROVBOX_RESULT_OK;
        
        if (sim_num < msg_num)
            *mode = SRV_PROVBOX_DEL_ALL_MSG_MODE_FOR_EACH;
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

    }

    if (*mode == SRV_PROVBOX_DEL_ALL_MSG_MODE_RESET)
    {
        result = srv_provbox_msg_delete_msg_list(msg_list, SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM);
        if (result != SRV_PROVBOX_RESULT_CONTINUE && result != SRV_PROVBOX_RESULT_OK)
            *mode = SRV_PROVBOX_DEL_ALL_MSG_MODE_DELETABLE;
    }

    if (*mode == SRV_PROVBOX_DEL_ALL_MSG_MODE_DELETABLE)
    {
        result = srv_provbox_msg_delete_all_deletable_msg(msg_list, SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM);
        if (result != SRV_PROVBOX_RESULT_CONTINUE && result != SRV_PROVBOX_RESULT_OK)
            *mode = SRV_PROVBOX_DEL_ALL_MSG_MODE_FOR_EACH;
    }

    if (*mode == SRV_PROVBOX_DEL_ALL_MSG_MODE_FOR_EACH)
    {
        result = srv_provbox_msg_delete_all_msg_for_each(msg_list, SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM, sim_id);
    }
  
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
        return SRV_PROVBOX_RESULT_CONTINUE;

    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    un_del_num = srv_provbox_msg_get_undeletable_msg_num(msg_list);
    if (un_del_num > 0)
        return SRV_PROVBOX_RESULT_PARTIAL_DELETED;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_set_msg_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  msg_id          [IN]        
 *  op              [IN]        
 *  msg_flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_set_msg_flag(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 msg_id,
                            srv_provbox_msg_flag_op_enum op,
                            U32 msg_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    S32 flag_index;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    flag_index = srv_provbox_get_flag_index(msg_flag, SRV_PROVBOX_MAX_U8_BIT_MASK_NUM);
    if (flag_index < 0 || flag_index >= SRV_PROVBOX_MAX_U8_BIT_MASK_NUM)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (MMI_FALSE == srv_provbox_dpary_get_elm_by_data(
                        msg_list->msg_ah,
                        (void*)msg_id,
                        (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_find_msg_node_by_id,
                        (void **)&base_info,
                        &index))
        return SRV_PROVBOX_RESULT_NOT_FOUND;
/*
    MMI_PRINT(
        MOD_MMI_INET_APP,
        SRV_PROVBOX_TRC_INFO,
        "[ProvBox]srv_provbox_msg_set_msg_flag(msg_id=%d,msg_flag=%d,bit_prop=%d)",
        msg_id,
        base_info->msg_flag,
        SRV_PROVBOX_MSG_GET_BIT_PROPERTY(base_info));
*/
    MMI_ASSERT(op == SRV_PROVBOX_MSG_FLAG_OP_SET &&
               !SRV_PROVBOX_CHECK_FLAG(base_info->msg_flag, msg_flag) ||
               op == SRV_PROVBOX_MSG_FLAG_OP_CLEAR && SRV_PROVBOX_CHECK_FLAG(base_info->msg_flag, msg_flag));

    if (op == SRV_PROVBOX_MSG_FLAG_OP_SET)
    {
        SRV_PROVBOX_SET_FLAG(base_info->msg_flag, msg_flag);
        if (msg_list->flag_stat.flag_num[flag_index] == 0)
            SRV_PROVBOX_SET_FLAG(msg_list->flag_stat.msg_flag, msg_flag);

        MMI_ASSERT(msg_list->flag_stat.flag_num[flag_index] < (U8) (SRV_PROVBOX_MSG_SET_FLAG_MAX_MSG_NUM));
        msg_list->flag_stat.flag_num[flag_index]++;
    }
    else if (op == SRV_PROVBOX_MSG_FLAG_OP_CLEAR)
    {
        SRV_PPOVBOX_CLEAR_FLAG(base_info->msg_flag, msg_flag);

        MMI_ASSERT(msg_list->flag_stat.flag_num[flag_index] > 0);
        msg_list->flag_stat.flag_num[flag_index]--;
        if (msg_list->flag_stat.flag_num[flag_index] == 0)
            SRV_PPOVBOX_CLEAR_FLAG(msg_list->flag_stat.msg_flag, msg_flag);
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_read_info_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list                [IN]        
 *  index                   [IN]        
 *  cmn_info                [OUT]       
 *  pin_status              [OUT]       
 *  msg_config_status       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_read_info_by_index(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 index,
                            srv_provbox_msg_cmn_info_struct *cmn_info,
                            srv_provbox_msg_pin_status_enum *pin_status,
                            srv_provbox_msg_config_status_struct *msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *msg_node;
    srv_provbox_msg_full_info_struct *full_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || cmn_info == NULL || pin_status == NULL || msg_config_status == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (MMI_FALSE == srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&msg_node))
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    MMI_ASSERT(msg_node != NULL);

    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(msg_node) != SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
    {
        result = srv_provbox_msg_load_info_to_list(msg_list, index, SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);
        if (result != SRV_PROVBOX_RESULT_OK)
            return result;
    }
    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&full_info);

    result = srv_provbox_msg_info_full_to_read(
                 full_info, cmn_info, pin_status, msg_config_status, 
                 (srv_provbox_box_type_enum)msg_list->box_type);
    return result;

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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_update_read_info_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list                [IN]        
 *  index                   [IN]        
 *  info_mask               [IN]        
 *  install_time            [IN]        
 *  read_status             [IN]        
 *  pin_status              [IN]        
 *  msg_config_status       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_update_read_info_by_index(
                            srv_provbox_msg_list_struct *msg_list,
                            U32 index,
                            U32 info_mask,
                            U32 install_time,
                            srv_provbox_msg_read_status_enum read_status,
                            srv_provbox_msg_pin_status_enum pin_status,
                            srv_provbox_msg_config_status_struct *msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *msg_node;
    srv_provbox_msg_full_info_struct *full_info;
    srv_provbox_msg_full_info_struct bak_full_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&msg_node);
    if (ret == MMI_FALSE)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    MMI_ASSERT(msg_node != NULL);

    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(msg_node) != SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
    {
        result = srv_provbox_msg_load_info_to_list(msg_list, index, SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);
        if (result != SRV_PROVBOX_RESULT_OK)
            return result;
    }

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&full_info);
    if(!full_info) /* MMI_ASSERT(full_info); */
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    memcpy(&bak_full_info, full_info, sizeof(srv_provbox_msg_full_info_struct));

    srv_provbox_msg_update_full_info_field(
        full_info,
        info_mask,
        install_time,
        read_status,
        pin_status,
        msg_config_status);

    result = srv_provbox_msg_save_full_info(msg_list, full_info, MMI_FALSE);
    if (result == SRV_PROVBOX_RESULT_OK)
    {
        if (SRV_PROVBOX_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_READ_STATUS))
        {
            if (SRV_PROVBOX_MSG_GET_READ_STATUS(&bak_full_info) == SRV_PROVBOX_MSG_READ_STATUS_UNREAD &&
                read_status == SRV_PROVBOX_MSG_READ_STATUS_READ)
            {
                srv_provbox_msg_sim_msg_status_read(
                    &msg_list->sim_msg_stat,
                    SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(full_info)),
                    (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(full_info));
            }
        }
    }
    else
    {
        /* restore */
        memcpy(full_info, &bak_full_info, sizeof(srv_provbox_msg_full_info_struct));
    }
    return result;
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_move_to_box_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur_msg_list        [IN]        
 *  new_msg_list        [IN]        
 *  cur_index           [IN]        
 *  new_index           [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_move_to_box_by_index(
                            srv_provbox_msg_list_struct *cur_msg_list,
                            srv_provbox_msg_list_struct *new_msg_list,
                            U32 cur_index,
                            U32 *new_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id;
    MMI_BOOL ret;
    U32 new_list_index = 0;
    srv_provbox_check_info_struct check_info;
    srv_provbox_msg_base_info_struct *base_info;
    srv_provbox_msg_full_info_struct *cur_full_info;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_result_enum result2 = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cur_msg_list == NULL || new_msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (new_index)
        *new_index = 0;
    else
        new_index = &new_list_index;

    /* first to check if can move or not. */
    result = srv_provbox_msg_can_move_msg(cur_msg_list, new_msg_list, cur_index);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    /* load message full info and app data to message list. */
    result = srv_provbox_msg_load_msg_app_data_by_index(cur_msg_list, cur_index);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_MOVE_TO_BOX_LOAD_APP_DATA, result);
        return result;
    }
    srv_provbox_dpary_get_elm_by_index(cur_msg_list->msg_ah, cur_index, (void **)&cur_full_info);

    /* copy msg_id and use it as bellow forever. */
    if (!cur_full_info) /* MMI_ASSERT(cur_full_info); */
         return SRV_PROVBOX_RESULT_NOT_FOUND;
    msg_id = cur_full_info->msg_id;
    MMI_ASSERT(msg_id != SRV_PROVBOX_INVALID_MSG_ID);

    /*
     * revise timestamp again, so the is message seems to be received just now 
     * even if it is received before and user changes the local time. 
     * and it's ok to get timestamp again here even move fail.
     */
    if (cur_msg_list->box_type == SRV_PROVBOX_BOX_TYPE_EXTRA && new_msg_list->box_type == SRV_PROVBOX_BOX_TYPE_INBOX)
    {
        cur_full_info->timestamp = srv_provbox_get_curr_time();
    }

    /* prepare the new message node to be inserted to the new_msg_list. */
    base_info =
        (srv_provbox_msg_base_info_struct*) srv_provbox_msg_create_msg_node(SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO);
    if (base_info == NULL)
    {
        /* try release some memory, may be fail. */
        srv_provbox_msg_format_msg_node_by_index(cur_msg_list, cur_index, (srv_provbox_msg_node_type_enum)cur_msg_list->init_node_type, MMI_TRUE);
        return SRV_PROVBOX_RESULT_MEM_FULL;
    }
    srv_provbox_msg_node_child_to_parent(
        (srv_provbox_msg_node_struct*) cur_full_info,
        (srv_provbox_msg_node_struct*) base_info);

    /* should first to check if save message to new message list ok. */
    srv_provbox_file_set_check_info(
        &check_info,
        SRV_PROVBOX_CHECK_TYPE_MOVE,
        new_msg_list->box_type, /* should be new_msg_list. */
        msg_id,
        0,
        0,
        -1,
        -1);
    result = srv_provbox_file_write_check_file(&check_info);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        SRV_PROVBOX_FREE(base_info);
        /* try release some memory, may be fail. */
        srv_provbox_msg_format_msg_node_by_index(cur_msg_list, cur_index, (srv_provbox_msg_node_type_enum)cur_msg_list->init_node_type, MMI_TRUE);
        return result;
    }

    result = srv_provbox_msg_save_full_info(new_msg_list, cur_full_info, MMI_TRUE);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_MOVE, msg_id);
        SRV_PROVBOX_FREE(base_info);
        /* try release some memory, may be fail. */
        srv_provbox_msg_format_msg_node_by_index(cur_msg_list, cur_index, (srv_provbox_msg_node_type_enum)cur_msg_list->init_node_type, MMI_TRUE);
        return result;
    }

    /* insert the base_info to the new_msg_list and get the new_index. */
    SRV_PPOVBOX_CLEAR_FLAG(base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_NEW_MSG_SAVED);

    ret = srv_provbox_dpary_insert_sorted(
            &new_msg_list->msg_ah,
            (void*)base_info,
            srv_provbox_msg_get_sort_func_by_type((srv_provbox_msg_sort_type_enum)(new_msg_list->sort_type)),
            new_index);

    if (ret == MMI_TRUE)
    {
        srv_provbox_msg_sim_msg_stat_add(
            &new_msg_list->sim_msg_stat,
            SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info)),
            (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info),
            (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(base_info));
    }

    /* try to save app_data. */
    if (cur_full_info->msg_data.app_data != NULL && cur_full_info->msg_data.app_data_size > 0)
    {
        result = srv_provbox_file_write_record(
                    new_msg_list->app_fh,
                    msg_id,
                    cur_full_info->msg_data.app_data,
                    cur_full_info->msg_data.app_data_size);

        SRV_PROVBOX_FREE(cur_full_info->msg_data.app_data); /* it's ok even save fail. */
    }

    /* should copy here to handle the scenario of writing file fail. */
    if (cur_full_info->msg_data.prov_data_size > 0)
        result2 = srv_provbox_msg_copy_prov_data_file(msg_id, (srv_provbox_box_type_enum)cur_msg_list->box_type, (srv_provbox_box_type_enum)new_msg_list->box_type);
/*
    MMI_PRINT(
        MOD_MMI_INET_APP,
        SRV_PROVBOX_TRC_INFO,
        "[ProvBox]srv_provbox_msg_move_to_box_by_index:cur_full_info(msg_id=%d,msg_flag=%d,bit_prop=%d,sim_id=%d,src_id=%d,timestamp=%d)",
        msg_id,
        cur_full_info->msg_flag,
        SRV_PROVBOX_MSG_GET_BIT_PROPERTY(cur_full_info),
        SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(cur_full_info)),
        SRV_PROVBOX_MSG_GET_SRC_ID(cur_full_info),
        cur_full_info->timestamp);

    MMI_PRINT(
        MOD_MMI_INET_APP,
        SRV_PROVBOX_TRC_INFO,
        "[ProvBox]srv_provbox_msg_move_to_box_by_index:cur_full_info(msg_type=%d,read_status=%d,pin_status=%d,addr_type=%d)",
        SRV_PROVBOX_MSG_GET_MSG_TYPE(cur_full_info),
        SRV_PROVBOX_MSG_GET_READ_STATUS(cur_full_info),
        SRV_PROVBOX_MSG_GET_PIN_STATUS(cur_full_info),
        SRV_PROVBOX_MSG_GET_ADDR_TYPE(cur_full_info));
*/
    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MSG_MOVE_TO_BOX_BY_INDEX_RESULT,
        msg_id,
        new_msg_list->box_type,
        ret,
        result,
        result2);

    if (ret == MMI_TRUE && result == SRV_PROVBOX_RESULT_OK && result2 == SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_MOVE_TO_BOX_BY_INDEX_RESULT,
            msg_id,
            new_msg_list->box_type,
            ret,
            result,
            result2);

        srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_MOVE, msg_id);

        srv_provbox_file_set_check_info(
            &check_info,
            SRV_PROVBOX_CHECK_TYPE_DELETE,
            cur_msg_list->box_type, /* should be cur_msg_list. */
            msg_id,
            0,
            0,
            -1,
            -1);
        /* must delete success, at least remove it from the message list, so force to delete it. */
        result = srv_provbox_msg_force_delete_msg_by_id(cur_msg_list, msg_id);
        if (result == SRV_PROVBOX_RESULT_OK)
            srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_DELETE, msg_id);
        return SRV_PROVBOX_RESULT_OK;
    }
    else
    {
        *new_index = 0;

        /* if base_info is inserted in the new_msg_list, also delete it. */
        result = srv_provbox_msg_force_delete_msg_by_id(new_msg_list, msg_id);
        if (result == SRV_PROVBOX_RESULT_OK)
            srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_MOVE, msg_id);

        /* to free memory. */
        srv_provbox_msg_format_msg_node_by_index(cur_msg_list, cur_index, (srv_provbox_msg_node_type_enum)cur_msg_list->init_node_type, MMI_TRUE);
        return SRV_PROVBOX_RESULT_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_move_to_box_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur_msg_list        [IN]        
 *  new_msg_list        [IN]        
 *  msg_id              [IN]        
 *  new_index           [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_move_to_box_by_id(
                            srv_provbox_msg_list_struct *cur_msg_list,
                            srv_provbox_msg_list_struct *new_msg_list,
                            U32 msg_id,
                            U32 *new_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U32 cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cur_msg_list == NULL || new_msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    ret = srv_provbox_dpary_get_index_by_data(
            cur_msg_list->msg_ah,
            (void*)msg_id,
            (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_find_msg_node_by_id,
            &cur_index);
    if (ret == MMI_FALSE)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_MOVE_TO_BOX_BY_ID,
            cur_msg_list->box_type,
            new_msg_list->box_type,
            msg_id);
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    }
    return srv_provbox_msg_move_to_box_by_index(cur_msg_list, new_msg_list, cur_index, new_index);
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
#endif /* 0 */


/*----------------------------------------------------------------------------*/
/* Static Function Defines                                                    */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_find_msg_node_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_node        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_msg_find_msg_node_by_id(
                                    srv_provbox_msg_node_struct *msg_node,
                                    U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_base_info_struct *base_info = (srv_provbox_msg_base_info_struct*) msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (base_info->msg_id == msg_id)
        return SRV_PROVBOX_CMP_RESULT_EQUAL;
    else
        return SRV_PROVBOX_CMP_RESULT_UNEQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_sort_node_by_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 *  dst     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_msg_sort_node_by_timestamp(void *src, void *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_base_info_struct *src_node = (srv_provbox_msg_base_info_struct*) src;
    srv_provbox_msg_base_info_struct *dst_node = (srv_provbox_msg_base_info_struct*) dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(src != NULL && dst != NULL);

    /* if the timestamp is same, just sort it accroding the received time. */

    if (src_node->timestamp < dst_node->timestamp)
        return SRV_PROVBOX_CMP_RESULT_AFTER;
    else if (src_node->timestamp == dst_node->timestamp)
        return srv_provbox_msg_sort_node_by_msg_id(src, dst);
    else
        return SRV_PROVBOX_CMP_RESULT_BEFORE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_sort_node_by_msg_id
 * DESCRIPTION
 *  more larger more fronter.
 * PARAMETERS
 *  src     [IN]        
 *  dst     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_msg_sort_node_by_msg_id(void *src, void *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_base_info_struct *src_node = (srv_provbox_msg_base_info_struct*) src;
    srv_provbox_msg_base_info_struct *dst_node = (srv_provbox_msg_base_info_struct*) dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(src != NULL && dst != NULL);
    /* check if src_node is located before or after the dst_node. */
    if (src_node->msg_id < dst_node->msg_id)
        return SRV_PROVBOX_CMP_RESULT_AFTER;
    else if (src_node->msg_id == dst_node->msg_id)
        return SRV_PROVBOX_CMP_RESULT_EQUAL;
    else
        return SRV_PROVBOX_CMP_RESULT_BEFORE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_sort_func_by_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sort_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC srv_provbox_msg_get_sort_func_by_type(
                                            srv_provbox_msg_sort_type_enum sort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC sort_func = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sort_type)
    {
        case SRV_PROVBOX_MSG_SORT_TYPE_TIMESTAMP:
            sort_func = (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_sort_node_by_timestamp;
            break;

        case SRV_PROVBOX_MSG_SORT_TYPE_MSG_ID:
            sort_func = (SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) srv_provbox_msg_sort_node_by_msg_id;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return sort_func;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_create_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_msg_node_struct *srv_provbox_msg_create_msg_node(srv_provbox_msg_node_type_enum node_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 node_size = 0;
    srv_provbox_msg_node_struct *msg_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_type)
    {
        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO:
            node_size = sizeof(srv_provbox_msg_base_info_struct);
            break;

        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO:
            node_size = sizeof(srv_provbox_msg_std_info_struct);
            break;

        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO:
            node_size = sizeof(srv_provbox_msg_full_info_struct);
            break;

        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_STORE_INFO:
            node_size = sizeof(srv_provbox_msg_store_info_struct);
            break;

        default:
            break;
    }

    msg_node = SRV_PROVBOX_MALLOC(node_size);
    if (msg_node == NULL)
        return NULL;
    memset(msg_node, 0x0, node_size);
    SRV_PROVBOX_MSG_SET_NODE_TYPE(msg_node, node_type);
    return msg_node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_free_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_node        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_msg_free_msg_node(srv_provbox_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_std_info_struct *std_info;
    srv_provbox_msg_full_info_struct *full_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_node == NULL)
        return;
    switch (SRV_PROVBOX_MSG_GET_NODE_TYPE(msg_node))
    {
        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO:
            std_info = (srv_provbox_msg_std_info_struct*) msg_node;
            SRV_PROVBOX_FREE(std_info->addr);
            break;
        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO:
            full_info = (srv_provbox_msg_full_info_struct*) msg_node;
            SRV_PROVBOX_FREE(full_info->addr);
            SRV_PROVBOX_FREE(full_info->msg_data.app_data);
            SRV_PROVBOX_FREE(full_info->msg_data.prov_data);
            break;

        default:
            break;
    }
    SRV_PROVBOX_FREE(msg_node);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_format_msg_node_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list                [IN]        
 *  index                   [IN]        
 *  format_node_type        [IN]        
 *  format_all              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_format_msg_node_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                srv_provbox_msg_node_type_enum format_node_type,
                                MMI_BOOL format_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL lock_format;
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *msg_node;
    srv_provbox_msg_node_struct *new_node;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&msg_node);
    if (msg_node == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    base_info = (srv_provbox_msg_base_info_struct*) msg_node;
    lock_format = (MMI_BOOL)SRV_PROVBOX_CHECK_FLAG(base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_LOCK_RECLAIM_MEM);

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MSG_FORMAT_MSG_NODE_BY_INDEX,
        base_info->msg_id,
        msg_list->box_type,
        format_all,
        lock_format);

    if (MMI_FALSE == format_all)
    {
        if (lock_format)
            return SRV_PROVBOX_RESULT_OK;
    }
    else
    {
        if (lock_format == MMI_TRUE)
            SRV_PPOVBOX_CLEAR_FLAG(base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_LOCK_RECLAIM_MEM);
    }
    if (MMI_FALSE == srv_provbox_msg_is_child_node_type(format_node_type,(srv_provbox_msg_node_type_enum)SRV_PROVBOX_MSG_GET_NODE_TYPE(msg_node)))
        return SRV_PROVBOX_RESULT_OK;

    new_node = (srv_provbox_msg_node_struct*) srv_provbox_msg_create_msg_node(format_node_type);
    if (new_node == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;
    result = srv_provbox_msg_node_child_to_parent(msg_node, new_node);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        SRV_PROVBOX_FREE(new_node);
        return result;
    }
    srv_provbox_dpary_replace_elm_by_index(msg_list->msg_ah, index, (void*)new_node, (void **)&msg_node);
    srv_provbox_msg_free_msg_node(msg_node);

    return SRV_PROVBOX_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_copy_msg_config_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_msg_config_status       [IN]        
 *  dst_msg_config_status       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_copy_msg_config_status(
                            srv_provbox_msg_config_status_struct *src_msg_config_status,
                            srv_provbox_msg_config_status_struct *dst_msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_msg_config_status == NULL || dst_msg_config_status == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    dst_msg_config_status->app_num = src_msg_config_status->app_num;
    dst_msg_config_status->config_status = src_msg_config_status->config_status;
    for (i = 0; i < SRV_PROVBOX_MAX_APP_INFO_NUM; i++)
    {
        dst_msg_config_status->app_config_status[i].config_id = src_msg_config_status->app_config_status[i].config_id;
        dst_msg_config_status->app_config_status[i].status = src_msg_config_status->app_config_status[i].status;
    }
    return SRV_PROVBOX_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_store_msg_config_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_msg_config_status     [OUT]       
 *  msg_config_status           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_get_store_msg_config_status(
                                srv_provbox_store_msg_config_status_struct *store_msg_config_status,
                                srv_provbox_msg_config_status_struct *msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_msg_config_status == NULL || msg_config_status == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    store_msg_config_status->app_num = msg_config_status->app_num;
    store_msg_config_status->config_status = msg_config_status->config_status;
    for (i = 0; i < SRV_PROVBOX_MAX_APP_INFO_NUM; i++)
    {
        store_msg_config_status->app_config_status[i].config_id = msg_config_status->app_config_status[i].config_id;
        store_msg_config_status->app_config_status[i].status = msg_config_status->app_config_status[i].status;
    }
    return SRV_PROVBOX_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_base_to_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_info       [IN]        
 *  sort_info       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_base_to_sort(
                                srv_provbox_msg_base_info_struct *base_info,
                                srv_provbox_msg_sort_info_struct *sort_info,
                                srv_provbox_msg_sort_type_enum sort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (base_info == NULL || sort_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    sort_info->msg_id = base_info->msg_id;
    sort_info->timestamp = base_info->timestamp;
    sort_info->sim_id = SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info));

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
    if (sort_type == SRV_PROVBOX_MSG_SORT_TYPE_MSG_TYPE)
        sort_info->sort_data.msg_type = SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info);
    else if (sort_type == SRV_PROVBOX_MSG_SORT_TYPE_READ_STATUS)
        sort_info->sort_data.read_status = SRV_PROVBOX_MSG_GET_READ_STATUS(base_info);
#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_base_to_cmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_info       [IN]        
 *  cmn_info        [OUT]       
 *  box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_base_to_cmn(
                                srv_provbox_msg_base_info_struct *base_info,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (base_info == NULL || cmn_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    cmn_info->msg_id = base_info->msg_id;
    cmn_info->timestamp = base_info->timestamp;
    cmn_info->install_time = 0;
    cmn_info->src_id = (srv_provbox_source_id_enum)SRV_PROVBOX_MSG_GET_SRC_ID(base_info);
    cmn_info->sim_id = SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info));
    cmn_info->box_type = box_type;
    cmn_info->msg_type = (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info);
    cmn_info->read_status = (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(base_info);
    cmn_info->sender_addr.addr_type = SRV_PROVBOX_ADDR_TYPE_NONE;
    cmn_info->sender_addr.addr_len = 0;
    cmn_info->sender_addr.addr[0] = '\0';
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_base_to_store
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_info       [IN]        
 *  store_info      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_base_to_store(
                                srv_provbox_msg_base_info_struct *base_info,
                                srv_provbox_msg_store_info_struct *store_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (base_info == NULL || store_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    SRV_PROVBOX_MSG_SET_NODE_TYPE(store_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_STORE_INFO);
    store_info->msg_flag = 0;
    store_info->bit_prop = SRV_PROVBOX_MSG_GET_BIT_PROPERTY(base_info);

    store_info->sim_id = (U8) SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info));
    store_info->src_id = SRV_PROVBOX_MSG_GET_SRC_ID(base_info);
    store_info->msg_type = SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info);
    store_info->read_status = SRV_PROVBOX_MSG_GET_READ_STATUS(base_info);
    store_info->addr_type = SRV_PROVBOX_MSG_GET_ADDR_TYPE(base_info);
    store_info->pin_status = SRV_PROVBOX_MSG_GET_PIN_STATUS(base_info);

    store_info->msg_id = base_info->msg_id;
    store_info->timestamp = base_info->timestamp;

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_std_to_base
 * DESCRIPTION
 *  
 * PARAMETERS
 *  std_info        [IN]        
 *  base_info       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_std_to_base(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_base_info_struct *base_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (base_info == NULL || std_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    SRV_PROVBOX_MSG_SET_NODE_TYPE(base_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO);
    base_info->msg_flag = std_info->msg_flag;
    SRV_PROVBOX_MSG_SET_BIT_PROPERTY(base_info, SRV_PROVBOX_MSG_GET_BIT_PROPERTY(std_info));
    base_info->msg_id = std_info->msg_id;
    base_info->timestamp = std_info->timestamp;
    return SRV_PROVBOX_RESULT_OK;
}


#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_std_to_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  std_info        [IN]        
 *  cmn_info        [OUT]       
 *  box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_std_to_sort(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_sort_info_struct *sort_info,
                                srv_provbox_msg_sort_type_enum sort_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 addr_len;
    U16 ucs_addr[SRV_PROVBOX_ADDR_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sort_info == NULL || std_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    
    srv_provbox_msg_info_base_to_sort((srv_provbox_msg_base_info_struct *)std_info, sort_info, sort_type);

    switch(sort_type)
    {
        case SRV_PROVBOX_MSG_SORT_TYPE_MSG_SIZE:
            sort_info->sort_data.msg_size = std_info->msg_size;
            break;

        case SRV_PROVBOX_MSG_SORT_TYPE_ADDRESS:
            if (std_info->addr == NULL)
            {
                sort_info->sort_data.addr[0] = '\0';
            }
            else
            {
                addr_len = mmi_chset_utf8_strlen((const kal_uint8*)std_info->addr);
                MMI_ASSERT(addr_len <= SRV_PROVBOX_ADDR_MAX_CHAR_LEN);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) ucs_addr,
                    SRV_PROVBOX_ADDR_MAX_BUFF_SIZE,
                    (kal_uint8*) std_info->addr);
                srv_provbox_ucs2_copy(
                            (CHAR *)sort_info->sort_data.addr, 
                            (SRV_PROVBOX_SORT_ADDR_MAX_CHAR_LEN + 1) * ENCODING_LENGTH, 
                            (const CHAR *)ucs_addr);
            }
            break;

      default:
        break;
    }

    return SRV_PROVBOX_RESULT_OK;

}


#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_std_to_cmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  std_info        [IN]        
 *  cmn_info        [OUT]       
 *  box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_std_to_cmn(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cmn_info == NULL || std_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    cmn_info->msg_id = std_info->msg_id;
    cmn_info->timestamp = std_info->timestamp;
    cmn_info->install_time = std_info->install_time;
    cmn_info->src_id = (srv_provbox_source_id_enum)SRV_PROVBOX_MSG_GET_SRC_ID(std_info);
    cmn_info->sim_id = SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(std_info));
    cmn_info->box_type = box_type;
    cmn_info->msg_type = (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(std_info);
    cmn_info->read_status = (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(std_info);
    cmn_info->sender_addr.addr_type = (srv_provbox_addr_type_enum)SRV_PROVBOX_MSG_GET_ADDR_TYPE(std_info);
    if (std_info->addr == NULL)
    {
        cmn_info->sender_addr.addr_len = 0;
        cmn_info->sender_addr.addr[0] = '\0';   /* U16 array */
    }
    else
    {
        cmn_info->sender_addr.addr_len = mmi_chset_utf8_strlen((const kal_uint8*)std_info->addr);
        MMI_ASSERT(cmn_info->sender_addr.addr_len <= SRV_PROVBOX_ADDR_MAX_CHAR_LEN);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) cmn_info->sender_addr.addr,
            SRV_PROVBOX_ADDR_MAX_BUFF_SIZE,
            (kal_uint8*) std_info->addr);
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_std_to_store
 * DESCRIPTION
 *  
 * PARAMETERS
 *  std_info        [IN]        
 *  store_info      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_std_to_store(
                                srv_provbox_msg_std_info_struct *std_info,
                                srv_provbox_msg_store_info_struct *store_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int utf8_len;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_msg_info_base_to_store((srv_provbox_msg_base_info_struct*) std_info, store_info);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    store_info->install_time = std_info->install_time;

    /* full fill zero to addr buffer, to save full zero to file */
    memset(&store_info->addr, 0x0, SRV_PROVBOX_ADDR_MAX_BUFF_SIZE);
    if (std_info->addr == NULL)
    {
        store_info->addr_len = 0;
    }
    else
    {
        utf8_len = mmi_chset_utf8_strlen((const kal_uint8*)std_info->addr);

        MMI_ASSERT(utf8_len <= SRV_PROVBOX_ADDR_MAX_CHAR_LEN);

        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) store_info->addr,
            SRV_PROVBOX_ADDR_MAX_BUFF_SIZE,
            (kal_uint8*) std_info->addr);
        store_info->addr_len = utf8_len;
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_full_to_base
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_info       [IN]        
 *  base_info       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_full_to_base(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_base_info_struct *base_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_provbox_msg_info_std_to_base((srv_provbox_msg_std_info_struct*) full_info, base_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_full_to_std
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_info       [IN]        
 *  std_info        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_full_to_std(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_std_info_struct *std_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (full_info == NULL || std_info == NULL)
        return SRV_PROVBOX_RESULT_OK;

    srv_provbox_msg_info_full_to_base(full_info, (srv_provbox_msg_base_info_struct*) std_info);
    SRV_PROVBOX_MSG_SET_NODE_TYPE(std_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO);

    std_info->install_time = full_info->install_time;

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
    std_info->msg_size = full_info->msg_size;
#endif

    if (full_info->addr == NULL)
        std_info->addr = NULL;
    else
        std_info->addr = srv_provbox_utf8_strdup((const CHAR*)full_info->addr);
    
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_full_to_store
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_info       [IN]        
 *  store_info      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_full_to_store(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_store_info_struct *store_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (full_info == NULL || store_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* to make sure the checksum is right */
    memset(store_info, 0x0, sizeof(srv_provbox_msg_store_info_struct));

    result = srv_provbox_msg_info_std_to_store((srv_provbox_msg_std_info_struct*) full_info, store_info);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    srv_provbox_msg_get_store_msg_config_status(&store_info->msg_config_status, &full_info->msg_config_status);

    store_info->app_data_size = full_info->msg_data.app_data_size;
    store_info->prov_data_size = full_info->msg_data.prov_data_size;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_full_to_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_info               [IN]        
 *  cmn_info                [OUT]       
 *  pin_status              [OUT]       
 *  msg_config_status       [OUT]       
 *  box_type                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_full_to_read(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_msg_pin_status_enum *pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status,
                                srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (full_info == NULL || cmn_info == NULL || pin_status == NULL || msg_config_status == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    result = srv_provbox_msg_info_std_to_cmn((srv_provbox_msg_std_info_struct*) full_info, cmn_info, box_type);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    *pin_status = (srv_provbox_msg_pin_status_enum)SRV_PROVBOX_MSG_GET_PIN_STATUS(full_info);

    srv_provbox_msg_copy_msg_config_status(&full_info->msg_config_status, msg_config_status);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_store_to_base
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_info      [IN]        
 *  base_info       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_store_to_base(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_msg_base_info_struct *base_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (base_info == NULL || store_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    SRV_PROVBOX_MSG_SET_NODE_TYPE(base_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO);
    SRV_PROVBOX_MSG_SET_SIM_ID(base_info, srv_provbox_change_sim_id(store_info->sim_id));
    SRV_PROVBOX_MSG_SET_SRC_ID(base_info, store_info->src_id);
    SRV_PROVBOX_MSG_SET_MSG_TYPE(base_info, store_info->msg_type);
    SRV_PROVBOX_MSG_SET_READ_STATUS(base_info, store_info->read_status);
    SRV_PROVBOX_MSG_SET_ADDR_TYPE(base_info, store_info->addr_type);
    SRV_PROVBOX_MSG_SET_PIN_STATUS(base_info, store_info->pin_status);

    MMI_ASSERT(SRV_PROVBOX_MSG_GET_BIT_PROPERTY(base_info) == store_info->bit_prop);

    base_info->msg_flag = 0;
    base_info->msg_id = store_info->msg_id;
    base_info->timestamp = store_info->timestamp;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_store_to_std
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_info      [IN]        
 *  std_info        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_store_to_std(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_msg_std_info_struct *std_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int utf8_len;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_msg_info_store_to_base(store_info, (srv_provbox_msg_base_info_struct*) std_info);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    SRV_PROVBOX_MSG_SET_NODE_TYPE(std_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO);
    std_info->install_time = store_info->install_time;

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
         std_info->msg_size = store_info->prov_data_size;
#endif

    utf8_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)store_info->addr);
    if (utf8_len <= 0)
        std_info->addr = 0;
    else
    {
        std_info->addr = SRV_PROVBOX_MALLOC(utf8_len + 1);
        if (std_info->addr == NULL)
            return SRV_PROVBOX_RESULT_MEM_FULL;
        mmi_chset_ucs2_to_utf8_string((kal_uint8*) std_info->addr, utf8_len + 1, (kal_uint8*) store_info->addr);
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_store_to_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_info      [IN]        
 *  full_info       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_store_to_full(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_msg_full_info_struct *full_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    srv_provbox_result_enum result;
    srv_provbox_msg_data_struct *msg_data;
    srv_provbox_msg_config_status_struct *f_msg_config_status;
    srv_provbox_store_msg_config_status_struct *s_msg_config_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_msg_info_store_to_std(store_info, (srv_provbox_msg_std_info_struct*) full_info);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    msg_data = &full_info->msg_data;
    f_msg_config_status = &full_info->msg_config_status;
    s_msg_config_status = &store_info->msg_config_status;
    
    SRV_PROVBOX_MSG_SET_NODE_TYPE(full_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);
    msg_data->app_data_size = store_info->app_data_size;
    msg_data->app_data = NULL;

    if (store_info->prov_data_size >= 0)
        msg_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_FILE;
    else
        msg_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_NONE;
    msg_data->prov_data_size = store_info->prov_data_size;
    msg_data->prov_data = NULL;
    msg_data->prov_file = NULL;

    for (i = 0; i < SRV_PROVBOX_MAX_APP_INFO_NUM; i++)
    {
        f_msg_config_status->app_config_status[i].config_id =
            (srv_provbox_config_id_enum) s_msg_config_status->app_config_status[i].config_id;
        f_msg_config_status->app_config_status[i].status =
            (srv_provbox_config_status_enum) s_msg_config_status->app_config_status[i].status;

    }
    f_msg_config_status->app_num = s_msg_config_status->app_num;
    f_msg_config_status->config_status = (srv_provbox_config_status_enum)(s_msg_config_status->config_status);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_store_to_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_node      [IN]        
 *  mem_node        [OUT]       
 *  node_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_store_to_mem(
                                srv_provbox_msg_store_info_struct *store_node,
                                srv_provbox_msg_node_struct *mem_node,
                                srv_provbox_msg_node_type_enum node_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_node == NULL || mem_node == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (node_type != SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO &&
        node_type != SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO && node_type != SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
        return SRV_PROVBOX_RESULT_FAIL;

    switch (node_type)
    {
        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO:
            result = srv_provbox_msg_info_store_to_base(store_node, (srv_provbox_msg_base_info_struct*) mem_node);
            break;

        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO:
            result = srv_provbox_msg_info_store_to_std(store_node, (srv_provbox_msg_std_info_struct*) mem_node);
            break;

        case SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO:
            result = srv_provbox_msg_info_store_to_full(store_node, (srv_provbox_msg_full_info_struct*) mem_node);
            break;

        default:
            MMI_ASSERT(0);
            result = SRV_PROVBOX_RESULT_INVALID_PARAM;
            break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_new_msg_to_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_info       [OUT]       
 *  new_msg         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_new_msg_to_full(
                                srv_provbox_msg_full_info_struct *full_info,
                                srv_provbox_save_msg_req_struct *new_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int utf8_len;
    srv_provbox_msg_cmn_info_struct *cmn_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (full_info == NULL || new_msg == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    SRV_PROVBOX_MSG_SET_NODE_TYPE(full_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);

    cmn_info = &new_msg->cmn_info;
    full_info->msg_flag = 0;
    SRV_PROVBOX_MSG_SET_SIM_ID(full_info, srv_provbox_change_sim_id(cmn_info->sim_id));
    SRV_PROVBOX_MSG_SET_SRC_ID(full_info, cmn_info->src_id);
    SRV_PROVBOX_MSG_SET_MSG_TYPE(full_info, cmn_info->msg_type);
    SRV_PROVBOX_MSG_SET_READ_STATUS(full_info, cmn_info->read_status);
    SRV_PROVBOX_MSG_SET_ADDR_TYPE(full_info, cmn_info->sender_addr.addr_type);
    SRV_PROVBOX_MSG_SET_PIN_STATUS(full_info, SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED);

    full_info->msg_id = cmn_info->msg_id;
    full_info->timestamp = cmn_info->timestamp;
    full_info->install_time = cmn_info->install_time;

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
    full_info->msg_size = new_msg->msg_data.prov_data_size;
#endif

    utf8_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)cmn_info->sender_addr.addr);
    if (utf8_len <= 0)
        full_info->addr = NULL;
    else
    {
        full_info->addr = SRV_PROVBOX_MALLOC(utf8_len + 1);
        if (full_info->addr == NULL)
            return SRV_PROVBOX_RESULT_MEM_FULL;
        mmi_chset_ucs2_to_utf8_string(
            (kal_uint8*) full_info->addr,
            utf8_len + 1,
            (kal_uint8*) cmn_info->sender_addr.addr);
    }
    full_info->msg_data.app_data_size = new_msg->msg_data.app_data_size;
    full_info->msg_data.prov_data_size = new_msg->msg_data.prov_data_size;
    /* do not set msg_data.app_data and msg_data.prov_data, they are copied on other place. */

    srv_provbox_msg_copy_msg_config_status(&full_info->msg_config_status, &new_msg->msg_config_status);
    /* Only copy info, do not copy message data */

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_info_new_msg_to_store
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_info      [OUT]       
 *  new_msg         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_info_new_msg_to_store(
                                srv_provbox_msg_store_info_struct *store_info,
                                srv_provbox_save_msg_req_struct *new_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_cmn_info_struct *cmn_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_info == NULL || new_msg == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    cmn_info= &new_msg->cmn_info;

    memset(store_info, 0x0, sizeof(srv_provbox_msg_store_info_struct));

    SRV_PROVBOX_MSG_SET_NODE_TYPE(store_info, SRV_PROVBOX_MSG_NODE_TYPE_MSG_STORE_INFO);

    SRV_PROVBOX_MSG_SET_SIM_ID(store_info, srv_provbox_change_sim_id(cmn_info->sim_id));
    SRV_PROVBOX_MSG_SET_SRC_ID(store_info, cmn_info->src_id);
    SRV_PROVBOX_MSG_SET_MSG_TYPE(store_info, cmn_info->msg_type);
    SRV_PROVBOX_MSG_SET_READ_STATUS(store_info, cmn_info->read_status);
    SRV_PROVBOX_MSG_SET_ADDR_TYPE(store_info, cmn_info->sender_addr.addr_type);
    SRV_PROVBOX_MSG_SET_PIN_STATUS(store_info, SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED);

    store_info->sim_id = cmn_info->sim_id;
    store_info->src_id = (U8) cmn_info->src_id;
    store_info->msg_type = (U8) cmn_info->msg_type;
    store_info->read_status = (U8) cmn_info->read_status;
    store_info->addr_type = (U8) cmn_info->sender_addr.addr_type;
    store_info->pin_status = SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED;

    store_info->msg_id = cmn_info->msg_id;
    store_info->timestamp = cmn_info->timestamp;
    store_info->install_time = cmn_info->install_time;

    store_info->addr_len = cmn_info->sender_addr.addr_len;
    mmi_ucs2cpy((CHAR*) store_info->addr, (const CHAR*)cmn_info->sender_addr.addr);
    store_info->pin_status = SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED;
    store_info->app_data_size = new_msg->msg_data.app_data_size;
    store_info->prov_data_size = new_msg->msg_data.prov_data_size;

    srv_provbox_msg_get_store_msg_config_status(&store_info->msg_config_status, &new_msg->msg_config_status);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_check_store_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_info      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_check_store_info(srv_provbox_msg_store_info_struct *store_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    srv_provbox_store_msg_config_status_struct *msg_config_status;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(store_info) != SRV_PROVBOX_MSG_NODE_TYPE_MSG_STORE_INFO)
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (/*store_info->sim_id != MMI_SIM1 &&
        store_info->sim_id != MMI_SIM2 &&
        store_info->sim_id != MMI_SIM3 &&
        store_info->sim_id != MMI_SIM4 */
        store_info->sim_id & MMI_SIM_ALL == 0 || 
        store_info->sim_id != SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(store_info)))
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->src_id >= SRV_PROVBOX_SOURCE_ID_MAX_ITEM ||
        store_info->src_id != SRV_PROVBOX_MSG_GET_SRC_ID(store_info))
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->msg_type >= SRV_PROVBOX_MSG_TYPE_MAX_ITEM ||
        store_info->msg_type != SRV_PROVBOX_MSG_GET_MSG_TYPE(store_info))
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->read_status >= SRV_PROVBOX_MSG_READ_STATUS_MAX_ITEM ||
        store_info->read_status != SRV_PROVBOX_MSG_GET_READ_STATUS(store_info))
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->pin_status >= SRV_PROVBOX_MSG_PIN_STATUS_MAX_ITEM ||
        store_info->pin_status != SRV_PROVBOX_MSG_GET_PIN_STATUS(store_info))
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->addr_type >= SRV_PROVBOX_ADDR_TYPE_MAX_ITEM ||
        store_info->addr_type != SRV_PROVBOX_MSG_GET_ADDR_TYPE(store_info))
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->addr_len != mmi_ucs2strlen((const CHAR*)store_info->addr))
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->app_data_size < -1 || store_info->prov_data_size < -1)
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    if (store_info->app_data_size > SRV_PROVBOX_MAX_APP_DATA_SIZE ||
        store_info->prov_data_size > SRV_PROVBOX_MAX_PROV_DATA_SIZE)
        return SRV_PROVBOX_RESULT_PARSE_ERR;


    msg_config_status = &store_info->msg_config_status;
    
    if (msg_config_status->app_num > SRV_PROVBOX_MAX_APP_INFO_NUM)
        return SRV_PROVBOX_RESULT_PARSE_ERR;

    for (i = 0; i < SRV_PROVBOX_MAX_APP_INFO_NUM; i++)
    {
        if (msg_config_status->app_config_status[i].config_id >= SRV_PROVBOX_CONFIG_ID_MAX_ITEM)
            return SRV_PROVBOX_RESULT_PARSE_ERR;
        if (msg_config_status->app_config_status[i].status >= SRV_PROVBOX_CONFIG_STATUS_MAX_ITEM)
            return SRV_PROVBOX_RESULT_PARSE_ERR;
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_parse_and_add_new_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  store_info      [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_parse_and_add_new_to_list(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_store_info_struct *store_info,
                                U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    result = srv_provbox_msg_check_store_info(store_info);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_PARSE_AND_ADD_NEW_TO_LIST,
            store_info->msg_id,
            msg_list->box_type,
            store_info->bit_prop,
            result);

        return SRV_PROVBOX_RESULT_PARSE_ERR;
    }
    msg_node = srv_provbox_msg_new_node_from_store_info(store_info, (srv_provbox_msg_node_type_enum)msg_list->init_node_type);
    if (msg_node == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;

    ret = srv_provbox_dpary_insert_sorted(
            &msg_list->msg_ah,
            msg_node,
            srv_provbox_msg_get_sort_func_by_type((srv_provbox_msg_sort_type_enum)(msg_list->sort_type)),
            index);
    if (ret == MMI_FALSE)
    {
        srv_provbox_msg_free_msg_node(msg_node);
        return SRV_PROVBOX_RESULT_MEM_FULL;
    }
    srv_provbox_msg_sim_msg_stat_add(
        &msg_list->sim_msg_stat,
        store_info->sim_id,
        (srv_provbox_msg_type_enum)store_info->msg_type,
        (srv_provbox_msg_read_status_enum)store_info->read_status);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_new_node_from_store_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_info      [IN]        
 *  node_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_msg_node_struct *srv_provbox_msg_new_node_from_store_info(
                                        srv_provbox_msg_store_info_struct *store_info,
                                        srv_provbox_msg_node_type_enum node_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_node = srv_provbox_msg_create_msg_node(node_type);
    if (msg_node == NULL)
        return NULL;
    result = srv_provbox_msg_info_store_to_mem(store_info, msg_node, node_type);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        SRV_PROVBOX_FREE(msg_node);
        return NULL;
    }
    return msg_node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_load_info_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  index               [IN]        
 *  load_node_type      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_load_info_to_list(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                srv_provbox_msg_node_type_enum load_node_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data_size;
    srv_provbox_result_enum result;
    srv_provbox_msg_node_struct *cur_node;
    srv_provbox_msg_node_struct *new_node;
    srv_provbox_msg_base_info_struct *base_info;
    srv_provbox_msg_store_info_struct store_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == 0 || index >= srv_provbox_dpary_get_num(msg_list->msg_ah))
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&cur_node);
    MMI_ASSERT(cur_node != NULL);

    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(cur_node) == load_node_type)
        return SRV_PROVBOX_RESULT_OK;

    new_node = srv_provbox_msg_create_msg_node(load_node_type);
    if (new_node == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;
    if (MMI_FALSE != srv_provbox_msg_is_child_node_type(
                        (srv_provbox_msg_node_type_enum)SRV_PROVBOX_MSG_GET_NODE_TYPE(new_node),
                        (srv_provbox_msg_node_type_enum)SRV_PROVBOX_MSG_GET_NODE_TYPE(cur_node)))
    {

        result = srv_provbox_msg_node_child_to_parent(cur_node, new_node);
    }
    else
    {
        result = srv_provbox_file_read_record(
                    msg_list->info_fh,
                    ((srv_provbox_msg_base_info_struct*) cur_node)->msg_id,
                    (void*)&store_info,
                    sizeof(srv_provbox_msg_store_info_struct),
                    &data_size);

        if (result != SRV_PROVBOX_RESULT_OK || data_size != sizeof(srv_provbox_msg_store_info_struct))
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_LOAD_INFO_TO_LIST_READ_RECORD,
                ((srv_provbox_msg_base_info_struct*) cur_node)->msg_id,
                msg_list->box_type,
                result);

            srv_provbox_msg_free_msg_node(new_node);
            if (result == SRV_PROVBOX_RESULT_OK)
                result = SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
            return result;
        }

        result = srv_provbox_msg_check_store_info(&store_info);

        MMI_ASSERT(result == SRV_PROVBOX_RESULT_OK);

        if (result == SRV_PROVBOX_RESULT_OK)
        {
            result = srv_provbox_msg_info_store_to_mem(
                        &store_info,
                        (srv_provbox_msg_node_struct*) new_node,
                        (srv_provbox_msg_node_type_enum)SRV_PROVBOX_MSG_GET_NODE_TYPE(new_node));
        }
    }
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_LOAD_INFO_TO_LIST_RESULT,
            ((srv_provbox_msg_base_info_struct*) cur_node)->msg_id,
            msg_list->box_type,
            result);
        srv_provbox_msg_free_msg_node(new_node);
        return result;
    }

    /* copy msg_flag to new new node and add new flag */
    base_info = (srv_provbox_msg_base_info_struct*) new_node;
    base_info->msg_flag = ((srv_provbox_msg_base_info_struct*) cur_node)->msg_flag;
    SRV_PROVBOX_SET_FLAG(base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_LOCK_RECLAIM_MEM);

    srv_provbox_dpary_replace_elm_by_index(msg_list->msg_ah, index, new_node, (void **)&cur_node);
    srv_provbox_msg_free_msg_node(cur_node);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_preprocess_new_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_msg     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_preprocess_new_msg(srv_provbox_save_msg_req_struct *new_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size = 0;
    srv_provbox_msg_cmn_info_struct *cmn_info;
    srv_provbox_msg_data_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_msg == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    cmn_info = & new_msg->cmn_info;
    msg_data = &new_msg->msg_data;
    
    /* Get msg_id, timestamp, install_time */
    if (cmn_info->timestamp == 0)
        cmn_info->timestamp = (U32) srv_provbox_get_curr_time();
    if (cmn_info->install_time == 0)
    {
        /* check if installed or not, if so, get current time */
        if (new_msg->msg_config_status.config_status != SRV_PROVBOX_CONFIG_STATUS_NOT_INSTALLED)
            cmn_info->install_time = (U32) srv_provbox_get_curr_time();
    }
    /* parse address : PRS and DM is prefer to do this */

    /* Set box type */
    cmn_info->box_type = SRV_PROVBOX_BOX_TYPE_EXTRA;

    /* get prov data size */
    if (msg_data->prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_FILE)
    {
        if (msg_data->prov_file == NULL)
        {
            MMI_ASSERT(0);
            msg_data->prov_data_size = -1;
            msg_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_NONE;
        }
        else if (msg_data->prov_data_size < 0)  /* the file size may be zero. */
        {
            /* to avaid 4-byte align issue on target, use size instead of prov_data_size to get data. */
            srv_provbox_file_get_file_size(msg_data->prov_file, &size);
            msg_data->prov_data_size = size;

/*
            MMI_PRINT(
                MOD_MMI_INET_APP,
                SRV_PROVBOX_TRC_INFO,
                "[ProvBox]srv_provbox_msg_preprocess_new_msg:check size(msg_id=%d,app_data_size=%d,prov_data_type=%d,prov_data_size=%d,size=%d)",
                new_msg->cmn_info.msg_id,
                new_msg->msg_data.app_data_size,
                new_msg->msg_data.prov_data_type,
                new_msg->msg_data.prov_data_size,
                size);
*/                
            if (size < 0)   /* the file size may be zero. */
            {
                MMI_ASSERT(0);
                msg_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_NONE;
            }
        }

    }
    else if (msg_data->prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA)
    {
        if (msg_data->prov_data == NULL || msg_data->prov_data_size <= 0)
        {
            MMI_ASSERT(0);
            msg_data->prov_data_size = -1;
            msg_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_NONE;
        }
    }
    else
    {
        msg_data->prov_data = NULL;
        msg_data->prov_data_size = -1;
    }

    if (msg_data->app_data == NULL && msg_data->app_data_size == 0)
        msg_data->app_data_size = -1;

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MSG_PREPROCESS_NEW_MSG,
        cmn_info->msg_id,
        cmn_info->timestamp,
        msg_data->app_data_size,
        msg_data->prov_data_size);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_check_new_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_msg     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_check_new_msg(srv_provbox_save_msg_req_struct *new_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_store_info_struct store_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_msg == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    srv_provbox_msg_info_new_msg_to_store(&store_info, new_msg);
    return srv_provbox_msg_check_store_info(&store_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_dirty_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  new_msg             [IN]        
 *  save_info_data      [IN]        
 *  save_app_data       [IN]        
 *  save_prov_data      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_delete_dirty_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 save_info_data,
                                U8 save_app_data,
                                U8 save_prov_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result1 = SRV_PROVBOX_RESULT_OK;
    srv_provbox_result_enum result2 = SRV_PROVBOX_RESULT_OK;
    srv_provbox_result_enum result3 = SRV_PROVBOX_RESULT_OK;
    srv_provbox_msg_cmn_info_struct *cmn_info;
    srv_provbox_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || new_msg == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    
    cmn_info = & new_msg->cmn_info;
    msg_data = &new_msg->msg_data;

    if (save_info_data)
        result1 = srv_provbox_file_delete_record(msg_list->info_fh, cmn_info->msg_id);
    if (save_app_data && msg_data->app_data_size > 0 && msg_data->app_data != NULL)
        result2 = srv_provbox_file_delete_record(msg_list->app_fh, cmn_info->msg_id);
    if (save_prov_data && msg_data->prov_data_size > 0)
        result3 = srv_provbox_msg_delete_prov_data_file((srv_provbox_box_type_enum)msg_list->box_type, cmn_info->msg_id);

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MSG_DELETE_DIRTY_MSG_RESULT,
        cmn_info->msg_id,
        msg_list->box_type,
        save_info_data,
        save_app_data,
        save_prov_data,
        result1,
        result2,
        result3);

    if ((result1 == SRV_PROVBOX_RESULT_OK || result1 == SRV_PROVBOX_RESULT_NOT_FOUND) &&
        (result2 == SRV_PROVBOX_RESULT_OK || result2 == SRV_PROVBOX_RESULT_NOT_FOUND) &&
        (result3 == SRV_PROVBOX_RESULT_OK || result3 == SRV_PROVBOX_RESULT_FILE_NOT_FOUND))
    {
        /* temp to use DELETE type to get the right check file name. */
        srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_DELETE, new_msg->cmn_info.msg_id);
        return SRV_PROVBOX_RESULT_OK;
    }
    return SRV_PROVBOX_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_app_prov_data_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  msg_id              [IN]        
 *  msg_data            [IN]        
 *  save_app_data       [OUT]       
 *  save_prov_data      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_save_app_prov_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                srv_provbox_msg_data_struct *msg_data,
                                U8 *save_app_data,
                                U8 *save_prov_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U16 prov_file[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if any delete all before, can not save it immediately */
    if (msg_list == NULL || msg_data == NULL || save_prov_data == NULL || save_app_data == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    *save_prov_data = 0;
    *save_app_data = 0;

/*
    MMI_PRINT(
        MOD_MMI_INET_APP,
        SRV_PROVBOX_TRC_INFO,
        "[ProvBox]srv_provbox_msg_save_app_prov_data_to_file(msg_id=%d,app_data_size=%d,prov_data_type=%d,prov_data_size=%d)",
        msg_id,
        msg_data->app_data_size,
        msg_data->prov_data_type,
        msg_data->prov_data_size);
*/
    if (msg_data->prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_FILE)
    {
        MMI_ASSERT(msg_data->prov_file);

        srv_provbox_file_get_prov_data_filename((srv_provbox_box_type_enum)msg_list->box_type, msg_id, prov_file, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
        /* 
         * try delete before move, just to avoid if any message are damaged and its message id is reused again. 
         * use FS_MOVE_KILL can improve the speed if the dst_name are the src_name are in the same driver.
         * the original file is deleted by FS_Move.
         */
        ret = FS_Delete((const WCHAR*)prov_file);
        ret = FS_Move((const WCHAR*)msg_data->prov_file, (const WCHAR*)prov_file, FS_MOVE_KILL, NULL, NULL, 0);
        if (ret != FS_NO_ERROR)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_SAVE_APP_PROV_DATA_TO_FILE_MOVE,
                msg_id,
                msg_list->box_type,
                msg_data->prov_data_size,
                ret);

            return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_MOVE, ret);
        }
    }
    else if (msg_data->prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA)
    {
        MMI_ASSERT(msg_data->prov_data != NULL && msg_data->prov_data_size > 0);

        result = srv_provbox_file_save_prov_data(
                    (srv_provbox_box_type_enum)msg_list->box_type,
                    msg_id,
                    msg_data->prov_data,
                    msg_data->prov_data_size);

        if (result != SRV_PROVBOX_RESULT_OK)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_SAVE_APP_PROV_DATA_TO_FILE_SAVE_PROV_DATA,
                msg_id,
                msg_list->box_type,
                msg_data->prov_data_size,
                result);

            return result;
        }
    }

    *save_prov_data = 1;

    if (msg_data->app_data != NULL && msg_data->app_data_size > 0)
    {
        result = srv_provbox_file_write_record(msg_list->app_fh, msg_id, msg_data->app_data, msg_data->app_data_size);
        if (result != SRV_PROVBOX_RESULT_OK)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_SAVE_APP_PROV_DATA_TO_FILE_SAVE_APP_DATA,
                msg_id,
                msg_list->box_type,
                msg_data->app_data_size,
                result);
            return result;
        }
    }

    *save_app_data = 1;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_new_msg_info_data_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  new_msg             [IN]        
 *  save_info_data      [OUT]       
 *  index               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_save_new_msg_info_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 *save_info_data,
                                U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_msg_store_info_struct store_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || new_msg == NULL || save_info_data == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    srv_provbox_msg_info_new_msg_to_store(&store_info, new_msg);

    result = srv_provbox_file_write_record(
                msg_list->info_fh,
                store_info.msg_id,
                &store_info,
                sizeof(srv_provbox_msg_store_info_struct));
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_SAVE_NEW_MSG_INFO_DATA,
            store_info.msg_id,
            SRV_PROVBOX_BOX_TYPE_EXTRA,
            store_info.bit_prop,
            result);
        return result;
    }

    *save_info_data = 1;    /* only means save to file not, do not care if add message info to message list. */
    result = srv_provbox_msg_parse_and_add_new_to_list(msg_list, &store_info, index);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_msg_data_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  new_msg             [IN]        
 *  save_info_data      [OUT]       
 *  save_app_data       [OUT]       
 *  save_prov_data      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_save_msg_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 *save_info_data,
                                U8 *save_app_data,
                                U8 *save_prov_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    MMI_BOOL ret;
    srv_provbox_result_enum result;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || new_msg == NULL ||
        save_prov_data == NULL || save_app_data == NULL || save_info_data == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    result = srv_provbox_msg_save_app_prov_data_to_file(
                msg_list,
                new_msg->cmn_info.msg_id,
                &new_msg->msg_data,
                save_app_data,
                save_prov_data);

    /* check if both prov_data and app_data are saved, if any fail, return and try save them to memory.  */
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_SAVE_MSG_DATA_TO_FILE, new_msg->cmn_info.msg_id, result, 0);
        return result;
    }
    /* save message info to file, but may be app_data is not saved yet. */
    result = srv_provbox_msg_save_new_msg_info_data_to_file(msg_list, new_msg, save_info_data, &index);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_SAVE_MSG_DATA_TO_FILE, new_msg->cmn_info.msg_id, result, 1);
        return result;
    }

    /* return ok only if prov_data, app_data, info_data are both save ok and add to message info list. */
    /* prov_data, app_data, info_data are all saved to file till now. */
    ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);
    if (ret == MMI_TRUE && base_info)
        SRV_PROVBOX_SET_FLAG(base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_NEW_MSG_SAVED);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_extra_msg_data_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  full_info           [IN]        
 *  save_info_data      [OUT]       
 *  save_app_data       [OUT]       
 *  save_prov_data      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_save_extra_msg_data_to_file(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_full_info_struct *full_info,
                                U8 *save_info_data,
                                U8 *save_app_data,
                                U8 *save_prov_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if any delete all before, can not save it immediately */
    if (msg_list == NULL || full_info == NULL ||
        save_prov_data == NULL || save_app_data == NULL || save_info_data == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    msg_data = &full_info->msg_data;
    
    /* check if has prov data and already saved to file. */
    if (msg_data->prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA)
    {
        if (msg_data->prov_data != NULL && msg_data->prov_data_size > 0)
        {
            result = srv_provbox_file_save_prov_data(
                        (srv_provbox_box_type_enum)msg_list->box_type,
                        full_info->msg_id,
                        msg_data->prov_data,
                        msg_data->prov_data_size);
            if (result != SRV_PROVBOX_RESULT_OK)
            {
                MMI_TRACE(
                    SRV_PROVBOX_TRC_INFO,
                    SRV_PROVBOX_TRC_MSG_SAVE_EXTRA_MSG_DATA_PROV_DATA,
                    full_info->msg_id,
                    SRV_PROVBOX_MSG_GET_BIT_PROPERTY(full_info),
                    msg_data->prov_data_size,
                    result);
                return result;
            }
            SRV_PROVBOX_FREE(msg_data->prov_data);
            msg_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_FILE;
        }
    }

    *save_prov_data = 1;

    /* check if has app data and already saved to file. */
    if (msg_data->app_data != NULL && msg_data->app_data_size > 0)
    {
        result = srv_provbox_file_write_record(
                    msg_list->app_fh,
                    full_info->msg_id,
                    msg_data->app_data,
                    msg_data->app_data_size);
        if (result != SRV_PROVBOX_RESULT_OK)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_SAVE_EXTRA_MSG_DATA_APP_DATA,
                full_info->msg_id,
                SRV_PROVBOX_MSG_GET_BIT_PROPERTY(full_info),
                msg_data->app_data_size,
                result);
            return result;
        }
        SRV_PROVBOX_FREE(msg_data->app_data);
    }
    *save_app_data = 1;

    /* please note, the message info may already be saved to file when to save new message. */
    result = srv_provbox_msg_save_full_info(msg_list, full_info, MMI_TRUE);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_SAVE_EXTRA_MSG_DATA_INFO_DATA,
            full_info->msg_id,
            SRV_PROVBOX_MSG_GET_BIT_PROPERTY(full_info),
            result);
        return result;
    }
    *save_info_data = 1;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_msg_data_to_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list            [IN]        
 *  new_msg             [IN]        
 *  save_prov_data      [IN]        
 *  save_app_data       [IN]        
 *  save_info_data      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_save_msg_data_to_mem(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                U8 save_prov_data,
                                U8 save_app_data,
                                U8 save_info_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    srv_provbox_result_enum result;
    srv_provbox_msg_full_info_struct *full_info;
    srv_provbox_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || new_msg == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MSG_SAVE_MSG_DATA_TO_MEM,
        new_msg->cmn_info.msg_id,
        new_msg->msg_data.app_data_size,
        new_msg->msg_data.prov_data_size);

    full_info =
        (srv_provbox_msg_full_info_struct*) srv_provbox_msg_create_msg_node(SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);
    if (full_info == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;

    msg_data = &full_info->msg_data;

    /* try to save prov_data. */
    if (save_prov_data == 0)
    {
        result = srv_provbox_msg_copy_prov_data_to_mem(msg_data, &new_msg->msg_data);
        if (result != SRV_PROVBOX_RESULT_OK)
        {
            srv_provbox_msg_free_msg_node((srv_provbox_msg_node_struct*) full_info);
            return result;
        }
    }
    /* try to save app_data. */
    if (save_app_data == 0)
    {
        result = srv_provbox_msg_copy_app_data_to_mem(msg_data, &new_msg->msg_data);
        if (result != SRV_PROVBOX_RESULT_OK)
        {
            SRV_PROVBOX_FREE(msg_data->prov_data);
            srv_provbox_msg_free_msg_node((srv_provbox_msg_node_struct*) full_info);
            return result;
        }
    }

    result = srv_provbox_msg_info_new_msg_to_full(full_info, new_msg);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        SRV_PROVBOX_FREE(msg_data->prov_data);
        SRV_PROVBOX_FREE(msg_data->app_data);
        srv_provbox_msg_free_msg_node((srv_provbox_msg_node_struct*) full_info);
        return SRV_PROVBOX_RESULT_MEM_FULL;
    }

    /* new message is saved to extra box only by message_id, and more larger more fronter. */
    ret = srv_provbox_dpary_insert_sorted(
            &msg_list->msg_ah,
            (void*)full_info,
            srv_provbox_msg_get_sort_func_by_type((srv_provbox_msg_sort_type_enum)(msg_list->sort_type)),
            NULL);

    if (ret == MMI_FALSE)
    {
        SRV_PROVBOX_FREE(msg_data->prov_data);
        SRV_PROVBOX_FREE(msg_data->app_data);
        srv_provbox_msg_free_msg_node((srv_provbox_msg_node_struct*) full_info);
        return SRV_PROVBOX_RESULT_MEM_FULL;
    }
    /* increase the stat number. */
    srv_provbox_msg_sim_msg_stat_add(
        &msg_list->sim_msg_stat,
        SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(full_info)),
        (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(full_info),
        (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(full_info));

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_copy_prov_data_to_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_data        [OUT]       
 *  src_data        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_copy_prov_data_to_mem(
                                srv_provbox_msg_data_struct *dst_data,
                                srv_provbox_msg_data_struct *src_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data_size;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dst_data == NULL || src_data == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    dst_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_NONE;
    dst_data->prov_data = NULL;
    dst_data->prov_data_size = src_data->prov_data_size;
    dst_data->prov_file = NULL;

    if (src_data->prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_NONE)
        return SRV_PROVBOX_RESULT_OK;

    MMI_ASSERT((src_data->prov_data != NULL || src_data->prov_file != NULL) && dst_data->prov_data_size > 0);

    dst_data->prov_data = SRV_PROVBOX_MALLOC(dst_data->prov_data_size);
    if (dst_data->prov_data == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;

    if (src_data->prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_FILE)
    {
        /* to avoid 4-byte aligh issue on target, prov_data_size is S16 type, but use S32* here. */
        data_size = dst_data->prov_data_size;
        result = srv_provbox_file_read_file((U16*) src_data->prov_file, dst_data->prov_data, (S32*) & data_size);
        if (result != SRV_PROVBOX_RESULT_OK)
        {
            SRV_PROVBOX_FREE(dst_data->prov_data);
            return result;
        }
    }
    else
    {
        memcpy(dst_data->prov_data, src_data->prov_data, dst_data->prov_data_size);
    }

    dst_data->prov_data_type = SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_copy_app_data_to_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_data        [OUT]       
 *  src_data        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_copy_app_data_to_mem(
                                srv_provbox_msg_data_struct *dst_data,
                                srv_provbox_msg_data_struct *src_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dst_data == NULL || src_data == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    dst_data->app_data = NULL;
    dst_data->app_data_size = -1;

    if (src_data->app_data == NULL || src_data->app_data_size <= 0)
        return SRV_PROVBOX_RESULT_OK;

    dst_data->app_data_size = src_data->app_data_size;
    dst_data->app_data = SRV_PROVBOX_MALLOC(dst_data->app_data_size);
    if (dst_data->app_data == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;

    memcpy(dst_data->app_data, src_data->app_data, dst_data->app_data_size);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_node_child_to_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  child_node      [IN]        
 *  parent_node     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_node_child_to_parent(
                                srv_provbox_msg_node_struct *child_node,
                                srv_provbox_msg_node_struct *parent_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_node == NULL || child_node == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(parent_node) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO &&
        SRV_PROVBOX_MSG_GET_NODE_TYPE(child_node) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO)
    {
        result = srv_provbox_msg_info_std_to_base(
                    (srv_provbox_msg_std_info_struct*) child_node,
                    (srv_provbox_msg_base_info_struct*) parent_node);
    }
    else if (SRV_PROVBOX_MSG_GET_NODE_TYPE(parent_node) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO &&
             SRV_PROVBOX_MSG_GET_NODE_TYPE(child_node) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
    {
        result = srv_provbox_msg_info_full_to_base(
                    (srv_provbox_msg_full_info_struct*) child_node,
                    (srv_provbox_msg_base_info_struct*) parent_node);
    }
    if (SRV_PROVBOX_MSG_GET_NODE_TYPE(parent_node) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO &&
        SRV_PROVBOX_MSG_GET_NODE_TYPE(child_node) == SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
    {
        result = srv_provbox_msg_info_full_to_std(
                    (srv_provbox_msg_full_info_struct*) child_node,
                    (srv_provbox_msg_std_info_struct*) parent_node);

    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_is_child_node_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_node_type       [IN]        
 *  dst_node_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_provbox_msg_is_child_node_type(
                    srv_provbox_msg_node_type_enum src_node_type,
                    srv_provbox_msg_node_type_enum dst_node_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_node_type == SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO &&
        (dst_node_type == SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO ||
         dst_node_type == SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO))
        return MMI_TRUE;

    if (src_node_type == SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO &&
        dst_node_type == SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO)
        return MMI_TRUE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_update_full_info_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_info               [IN]        
 *  info_mask               [IN]        
 *  install_time            [IN]        
 *  read_status             [IN]        
 *  pin_status              [IN]        
 *  msg_config_status       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_update_full_info_field(
                                srv_provbox_msg_full_info_struct *full_info,
                                U32 info_mask,
                                U32 install_time,
                                srv_provbox_msg_read_status_enum read_status,
                                srv_provbox_msg_pin_status_enum pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (full_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (SRV_PROVBOX_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_INSTALL_TIME))
    {
        full_info->install_time = srv_provbox_get_curr_time();
    }

    if (SRV_PROVBOX_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_READ_STATUS))
    {
        SRV_PROVBOX_MSG_SET_READ_STATUS(full_info, read_status);
    }

    if (SRV_PROVBOX_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_PIN_STATUS))
    {
        SRV_PROVBOX_MSG_SET_PIN_STATUS(full_info, pin_status);
    }
    if (SRV_PROVBOX_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_INSTALL_STATUS) ||
        SRV_PROVBOX_CHECK_FLAG(info_mask, SRV_PROVBOX_MSG_INFO_MASK_APP_INSTALL_STATUS))
    {
        srv_provbox_msg_copy_msg_config_status(msg_config_status, &full_info->msg_config_status);
    }
    return SRV_PROVBOX_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_save_full_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  full_info       [IN]        
 *  create          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_save_full_info(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_full_info_struct *full_info,
                                MMI_BOOL create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_msg_store_info_struct store_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || full_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    result = srv_provbox_msg_info_full_to_store(full_info, &store_info);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    result = srv_provbox_file_update_record(
                msg_list->info_fh,
                full_info->msg_id,
                &store_info,
                sizeof(srv_provbox_msg_store_info_struct));
    if (result == SRV_PROVBOX_RESULT_NOT_FOUND && create == MMI_TRUE)
    {
        result = srv_provbox_file_write_record(
                    msg_list->info_fh,
                    full_info->msg_id,
                    &store_info,
                    sizeof(srv_provbox_msg_store_info_struct));
    }

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_SAVE_FULL_INFO, store_info.msg_id, store_info.bit_prop, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_prov_data_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_delete_prov_data_file(srv_provbox_box_type_enum box_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    srv_provbox_result_enum result;
    U16 prov_data_file[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_file_get_prov_data_filename(box_type, msg_id, (U16*) prov_data_file, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);

    ret = FS_Delete((const WCHAR*)prov_data_file);
    result = srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_DELETE, ret);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_DELETE_PROV_DATA_FILE, msg_id, box_type, ret);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_copy_prov_data_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  src_box_type        [IN]        
 *  dst_box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_copy_prov_data_file(
                                U32 msg_id,
                                srv_provbox_box_type_enum src_box_type,
                                srv_provbox_box_type_enum dst_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U16 src_name[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];
    U16 dst_name[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_file_get_prov_data_filename(src_box_type, msg_id, (U16*) src_name, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
    srv_provbox_file_get_prov_data_filename(dst_box_type, msg_id, (U16*) dst_name, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);

    /*
     * Should use FS_MOVE_COPY here for error handling 
     * try delete before move, just to avoid if any message are damaged and its message id is reused again.
     */
    ret = FS_Delete((const WCHAR*)dst_name);
    ret = FS_Move((const WCHAR*)src_name, (const WCHAR*)dst_name, FS_MOVE_COPY, NULL, NULL, 0);
    if (ret == FS_NO_ERROR)
        return SRV_PROVBOX_RESULT_OK;

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_COPY_PROV_DATA_FILE, msg_id, src_box_type, dst_box_type, ret);

    return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_MOVE, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_reset_sim_msg_stat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_msg_stat        [IN/OUT]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_reset_sim_msg_stat(srv_provbox_sim_msg_stat_struct *sim_msg_stat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_msg_stat == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    memset(sim_msg_stat, 0x0, sizeof(srv_provbox_sim_msg_stat_struct));

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_copy_sim_msg_stat_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_sim_msg_stat        [OUT]       
 *  src_sim_msg_stat        [IN]        
 *  sim_id                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_copy_sim_msg_stat_by_sim_id(
                            srv_provbox_sim_msg_stat_struct *dst_sim_msg_stat,
                            srv_provbox_sim_msg_stat_struct *src_sim_msg_stat,
                            U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dst_sim_msg_stat == NULL || src_sim_msg_stat == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    srv_provbox_msg_reset_sim_msg_stat(dst_sim_msg_stat);

    /* if sim_id is multi-sim_id, this function still support this case */
    for (i = 0; sim_id != 0; i++)
    {
        if (SRV_PROVBOX_GET_VAILD_SIM_ID(sim_id, i) > 0)
        {
            dst_sim_msg_stat->sim_read_num[i] = src_sim_msg_stat->sim_read_num[i];
            dst_sim_msg_stat->sim_unread_num[i] = src_sim_msg_stat->sim_unread_num[i];
            dst_sim_msg_stat->sim_sim_msg_num[i] = src_sim_msg_stat->sim_sim_msg_num[i];
            SRV_PROVBOX_RESET_BIT_VALUE(sim_id, i);
        }
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_stat_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_stat_msg_list(srv_provbox_msg_list_struct *msg_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 msg_num;
    srv_provbox_msg_base_info_struct *base_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    srv_provbox_msg_reset_sim_msg_stat(&msg_list->sim_msg_stat);
    msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah);
    for (i = 0; i < msg_num; i++)
    {
        srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, i, (void **)&base_info);
        srv_provbox_msg_sim_msg_stat_add(
            &msg_list->sim_msg_stat,
            SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info)),
            (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info),
            (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(base_info));
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_sim_msg_stat_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_msg_stat        [IN/OUT]        
 *  sim_id              [IN]            
 *  msg_type            [IN]            
 *  read_status         [IN]            
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_sim_msg_stat_add(
                                srv_provbox_sim_msg_stat_struct *sim_msg_stat,
                                U8 sim_id,
                                srv_provbox_msg_type_enum msg_type,
                                srv_provbox_msg_read_status_enum read_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_msg_stat == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* if sim_id is multi-sim_id, this function still support this case */
    for (i = 0; sim_id != 0; i++)
    {
        if (SRV_PROVBOX_GET_VAILD_SIM_ID(sim_id, i) > 0)
        {
            if (read_status == SRV_PROVBOX_MSG_READ_STATUS_READ)
                sim_msg_stat->sim_read_num[i]++;
            else
                sim_msg_stat->sim_unread_num[i]++;

            if (MMI_FALSE != srv_provbox_msg_is_sim_message(msg_type))
                sim_msg_stat->sim_sim_msg_num[i]++;
            SRV_PROVBOX_RESET_BIT_VALUE(sim_id, i);
        }
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_sim_msg_stat_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_msg_stat        [IN/OUT]        
 *  sim_id              [IN]            
 *  msg_type            [IN]            
 *  read_status         [IN]            
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_sim_msg_stat_delete(
                                srv_provbox_sim_msg_stat_struct *sim_msg_stat,
                                U8 sim_id,
                                srv_provbox_msg_type_enum msg_type,
                                srv_provbox_msg_read_status_enum read_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_msg_stat == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* if sim_id is multi-sim_id, this function still support this case */
    for (i = 0; sim_id != 0; i++)
    {
        if (SRV_PROVBOX_GET_VAILD_SIM_ID(sim_id, i) > 0)
        {
            if (read_status == SRV_PROVBOX_MSG_READ_STATUS_READ)
                (sim_msg_stat->sim_read_num[i] > 0) ? sim_msg_stat->sim_read_num[i]-- : 0;
            else
                (sim_msg_stat->sim_unread_num[i] > 0) ? sim_msg_stat->sim_unread_num[i]-- : 0;

            if (MMI_FALSE != srv_provbox_msg_is_sim_message(msg_type))
                (sim_msg_stat->sim_sim_msg_num[i] > 0) ? sim_msg_stat->sim_sim_msg_num[i]-- : 0;
            SRV_PROVBOX_RESET_BIT_VALUE(sim_id, i);
        }
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_sim_msg_status_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_msg_stat        [IN/OUT]        
 *  sim_id              [IN]            
 *  read_status         [IN]            
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_sim_msg_status_read(
                                srv_provbox_sim_msg_stat_struct *sim_msg_stat,
                                U8 sim_id,
                                srv_provbox_msg_read_status_enum read_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_msg_stat == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* if sim_id is multi-sim_id, this function still support this case */
    for (i = 0; sim_id != 0; i++)
    {
        if (SRV_PROVBOX_GET_VAILD_SIM_ID(sim_id, i) > 0)
        {
            if (read_status == SRV_PROVBOX_MSG_READ_STATUS_READ)
            {
                sim_msg_stat->sim_unread_num[i]--;
                sim_msg_stat->sim_read_num[i]++;
            }
            SRV_PROVBOX_RESET_BIT_VALUE(sim_id, i);
        }
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_undeletable_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_provbox_msg_get_undeletable_msg_num(srv_provbox_msg_list_struct *msg_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flag_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return 0;
    if (!SRV_PROVBOX_CHECK_FLAG(msg_list->flag_stat.msg_flag, SRV_PROVBOX_MSG_FLAG_READING))
        return 0;

    flag_index = srv_provbox_get_flag_index((U32) msg_list->flag_stat.msg_flag, SRV_PROVBOX_MAX_U8_BIT_MASK_NUM);
    if (flag_index < 0 || flag_index >= SRV_PROVBOX_MAX_U8_BIT_MASK_NUM)
        return 0;
    return (U32) msg_list->flag_stat.flag_num[flag_index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_is_deletable_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_info       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_is_deletable_msg(srv_provbox_msg_base_info_struct *base_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (base_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    base_info = (srv_provbox_msg_base_info_struct*) base_info;

    if (SRV_PROVBOX_CHECK_FLAG(base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_READING))
        return SRV_PROVBOX_RESULT_READING;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_all_deletable_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  max_del_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_delete_all_deletable_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                S32 max_del_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;
    MMI_BOOL ret;
    U32 first_idx = 0;
    S32 total_del_num = 0;
    srv_provbox_msg_full_info_struct *full_info;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_msg_data_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL || 0 == (msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah)))
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    /* first, delete prov_data file for all deletable messages, and load app_data for others. */
    /* msg_list->cursor should be 0 if first call this. */
    while (msg_list->cursor < msg_num)
    {
        if (total_del_num >= max_del_num)
            return SRV_PROVBOX_RESULT_CONTINUE;

        ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, msg_list->cursor, (void **)&full_info);
        if (ret == MMI_FALSE || full_info == NULL)
            break;

        result = srv_provbox_msg_is_deletable_msg((srv_provbox_msg_base_info_struct*) full_info);
        if (result == SRV_PROVBOX_RESULT_OK)
        {
            /* treat delete file always succeed. */
            srv_provbox_msg_delete_prov_data_file((srv_provbox_box_type_enum)msg_list->box_type, full_info->msg_id);
            total_del_num++;
        }
        else
        {
            result = srv_provbox_msg_load_msg_app_data_by_index(msg_list, msg_list->cursor);
            if (result != SRV_PROVBOX_RESULT_OK)
            {
                return result;
            }
            total_del_num += 2; /* treat 1 read = 2 delete. */
        }
        msg_list->cursor++;
    }

    /* 2: delete the record file and free 2 record lists. */
    srv_provbox_file_delete_record_list(msg_list->info_fh);
    srv_provbox_file_delete_record_list(msg_list->app_fh);

    /* 3: save the message stored in memory and delete all other message nodes. */
    while (1)
    {
        /* full info is ok now. */
        ret = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, first_idx, (void **)&full_info);
        if (ret == MMI_FALSE || full_info == NULL)
            break;
        
        msg_data = &full_info->msg_data;
        
        result = srv_provbox_msg_is_deletable_msg((srv_provbox_msg_base_info_struct*) full_info);
        if (result == SRV_PROVBOX_RESULT_OK)
        {
            srv_provbox_dpary_delete_elm_by_index(
                &msg_list->msg_ah,
                first_idx,
                (SRV_PROVBOX_DPARY_FREE_ELM_FUNC) srv_provbox_msg_free_msg_node);
        }
        else
        {
            result = srv_provbox_msg_save_full_info(msg_list, full_info, MMI_TRUE);

            if (msg_data->app_data != NULL && msg_data->app_data_size > 0)
            {
                result = srv_provbox_file_write_record(
                            msg_list->app_fh,
                            full_info->msg_id,
                            msg_data->app_data,
                            msg_data->app_data_size);
                SRV_PROVBOX_FREE(msg_data->app_data);
            }
            first_idx++;
        }
    }

    srv_provbox_msg_stat_msg_list(msg_list);
    msg_list->cursor = 0;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_all_msg_for_each
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  max_del_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_delete_all_msg_for_each(
                                srv_provbox_msg_list_struct *msg_list,
                                S32 max_del_num, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 index;
    U32 msg_num;
    srv_provbox_result_enum result;
#ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__
    mmi_sim_enum msg_sim_id;
    srv_provbox_msg_base_info_struct *base_info;
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    msg_num = srv_provbox_dpary_get_num(msg_list->msg_ah);
    for (i = 0, index = 0; i < msg_num; i++)
    {
#ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__
        /* Filter by sim_Id */
        srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);
        if (!base_info)
            break;
        msg_sim_id = SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info));
        if (!SRV_PROVBOX_CHECK_FLAG(msg_sim_id, sim_id))
        {
            index++;
            continue;
         }
        
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

        result = srv_provbox_msg_delete_msg_by_index(msg_list, index);
        if (result != SRV_PROVBOX_RESULT_OK)
            index++;
        if ((S32) (i + 1 - index) * 2 >= max_del_num)
            return SRV_PROVBOX_RESULT_CONTINUE;
    }

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MSG_DELETE_ALL_MSG_ONE_BY_ONE, msg_list->box_type, msg_num, index);

    /* the number of those messages un-deletable is calculated every time this function is called. */
    if (index != 0)
        return SRV_PROVBOX_RESULT_PARTIAL_DELETED;

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_load_msg_app_data_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_load_msg_app_data_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 read_size;
    srv_provbox_result_enum result;
    srv_provbox_msg_full_info_struct *full_info;
    srv_provbox_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    result = srv_provbox_msg_load_info_to_list(msg_list, index, SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&full_info);
    if (full_info == NULL)
        return SRV_PROVBOX_RESULT_OK;
        
    msg_data = &full_info->msg_data;    
    if (msg_data->app_data_size > 0 && msg_data->app_data == NULL)
    {
        msg_data->app_data = SRV_PROVBOX_MALLOC(msg_data->app_data_size);
        if (msg_data->app_data == NULL)
            return SRV_PROVBOX_RESULT_MEM_FULL;

        result = srv_provbox_file_read_record(
                    msg_list->app_fh,
                    full_info->msg_id,
                    msg_data->app_data,
                    msg_data->app_data_size,
                    &read_size);
        if (result != SRV_PROVBOX_RESULT_OK || read_size != msg_data->app_data_size)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_MSG_LOAD_MSG_APP_DATA_BY_INDEX_READ_RECORD,
                full_info->msg_id,
                msg_list->box_type,
                msg_data->app_data_size,
                result);

            SRV_PROVBOX_FREE(msg_data->app_data);
            if (result == SRV_PROVBOX_RESULT_OK)
                result = SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
            return result;
        }
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  max_del_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_delete_msg_list(srv_provbox_msg_list_struct *msg_list, S32 max_del_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    S32 total_del_num = 0;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    result = srv_provbox_clean_folder_by_box_type((srv_provbox_box_type_enum)msg_list->box_type, max_del_num, &total_del_num);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
        return SRV_PROVBOX_RESULT_CONTINUE;

    srv_provbox_file_delete_record_list(msg_list->info_fh);
    srv_provbox_file_delete_record_list(msg_list->app_fh);
    msg_list->msg_ah = srv_provbox_dpary_delete_all(
                           msg_list->msg_ah,
                           (SRV_PROVBOX_DPARY_FREE_ELM_FUNC) srv_provbox_msg_free_msg_node);
    srv_provbox_msg_reset_sim_msg_stat(&msg_list->sim_msg_stat);

    msg_list->flag_stat.msg_flag = 0;
    for (i = 0; i < SRV_PROVBOX_MAX_U8_BIT_MASK_NUM; i++)
    {
        msg_list->flag_stat.flag_num[i] = 0;
    }
    msg_list->cursor = 0;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_force_delete_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  msg_id          [IN]        
 *  index           [IN]        
 *  in_list         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_force_delete_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                U32 index,
                                MMI_BOOL in_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result1;
    srv_provbox_result_enum result2;
    srv_provbox_result_enum result3;
    srv_provbox_msg_base_info_struct *base_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (in_list)
    {
        srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);

        MMI_ASSERT(base_info != NULL);

        srv_provbox_msg_sim_msg_stat_delete(
            &msg_list->sim_msg_stat,
            SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info)),
            (srv_provbox_msg_type_enum)SRV_PROVBOX_MSG_GET_MSG_TYPE(base_info),
            (srv_provbox_msg_read_status_enum)SRV_PROVBOX_MSG_GET_READ_STATUS(base_info));

        srv_provbox_dpary_delete_elm_by_index(
            &msg_list->msg_ah,
            index,
            (SRV_PROVBOX_DPARY_FREE_ELM_FUNC) srv_provbox_msg_free_msg_node);
    }
    if (msg_id != SRV_PROVBOX_INVALID_MSG_ID)
    {
        result1 = srv_provbox_msg_delete_prov_data_file((srv_provbox_box_type_enum)msg_list->box_type, msg_id);
        result2 = srv_provbox_file_delete_record(msg_list->info_fh, msg_id);
        result3 = srv_provbox_file_delete_record(msg_list->app_fh, msg_id);

        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_FORCE_DELETE_MSG_BY_ID,
            msg_list->box_type,
            msg_id,
            in_list,
            result1,
            result2,
            result3);

        if (result1 == SRV_PROVBOX_RESULT_FILE_NOT_FOUND &&
            result2 == SRV_PROVBOX_RESULT_NOT_FOUND && result3 == SRV_PROVBOX_RESULT_NOT_FOUND)
            return SRV_PROVBOX_RESULT_NOT_FOUND;

        if ((result1 == SRV_PROVBOX_RESULT_OK || result1 == SRV_PROVBOX_RESULT_FILE_NOT_FOUND) &&
            (result2 == SRV_PROVBOX_RESULT_OK || result2 == SRV_PROVBOX_RESULT_NOT_FOUND) &&
            (result3 == SRV_PROVBOX_RESULT_OK || result3 == SRV_PROVBOX_RESULT_NOT_FOUND))
            return SRV_PROVBOX_RESULT_OK;

        return SRV_PROVBOX_RESULT_FAIL;
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_force_delete_msg_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_list        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_force_delete_msg_by_index(srv_provbox_msg_list_struct *msg_list, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL in_list;
    U32 msg_id = SRV_PROVBOX_INVALID_MSG_ID;
    srv_provbox_msg_base_info_struct *base_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    in_list = srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, index, (void **)&base_info);
    if (in_list && base_info)
        msg_id = base_info->msg_id;
    return srv_provbox_msg_force_delete_msg(msg_list, msg_id, index, in_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_can_move_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur_msg_list        [IN]        
 *  new_msg_list        [IN]        
 *  cur_index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_msg_can_move_msg(
                                srv_provbox_msg_list_struct *cur_msg_list,
                                srv_provbox_msg_list_struct *new_msg_list,
                                U32 cur_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;
    srv_provbox_msg_base_info_struct *cur_base_info;
///    U32 archive_msg_num = SRV_PROVBOX_MAX_ARCHIVE_MSG_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cur_msg_list == NULL || new_msg_list == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* Check the index */
    if (cur_index > (msg_num = srv_provbox_dpary_get_num(cur_msg_list->msg_ah)))
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_CAN_MOVE_MSG_WRONG_INDEX,
            cur_msg_list->box_type,
            new_msg_list->box_type,
            cur_index,
            msg_num);
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    }
    /* check if already saved, if not, do not move it. */
    srv_provbox_dpary_get_elm_by_index(cur_msg_list->msg_ah, cur_index, (void **)&cur_base_info);
    if (cur_base_info && cur_msg_list->box_type == SRV_PROVBOX_BOX_TYPE_EXTRA &&
        !SRV_PROVBOX_CHECK_FLAG(cur_base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_NEW_MSG_SAVED))
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_CAN_MOVE_MSG_NOT_SAVED,
            cur_msg_list->box_type,
            new_msg_list->box_type,
            cur_base_info->msg_id,
            cur_base_info->msg_flag,
            SRV_PROVBOX_MSG_GET_BIT_PROPERTY(cur_base_info));
        return SRV_PROVBOX_RESULT_NOT_SAVED;
    }
    /* Check if in reading */
    if (cur_base_info && cur_msg_list->box_type != SRV_PROVBOX_BOX_TYPE_EXTRA &&
        SRV_PROVBOX_CHECK_FLAG(cur_base_info->msg_flag, SRV_PROVBOX_MSG_FLAG_READING))
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MSG_CAN_MOVE_MSG_READING,
            cur_msg_list->box_type,
            new_msg_list->box_type,
            cur_base_info->msg_id,
            cur_base_info->msg_flag,
            SRV_PROVBOX_MSG_GET_BIT_PROPERTY(cur_base_info));
        return SRV_PROVBOX_RESULT_READING;
    }

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    /* Check if want to move from inbox to archive box and archive box is full */
    if (new_msg_list->box_type == SRV_PROVBOX_BOX_TYPE_ARCHIVE)
    {
        msg_num = srv_provbox_dpary_get_num(new_msg_list->msg_ah);
        if (msg_num >= SRV_PROVBOX_MAX_ARCHIVE_MSG_NUM)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_CAN_MOVE_MSG_ARCHIVE_FULL,
                cur_msg_list->box_type,
                new_msg_list->box_type,
                cur_base_info->msg_id,
                cur_base_info->msg_flag,
                SRV_PROVBOX_MSG_GET_BIT_PROPERTY(cur_base_info));

            return SRV_PROVBOX_RESULT_BOX_FULL;
        }
    }

#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    /* Check if want to move from extra box to inbox and inbox is full */
    if (new_msg_list->box_type == SRV_PROVBOX_BOX_TYPE_INBOX)
    {
        msg_num = srv_provbox_dpary_get_num(new_msg_list->msg_ah);
        if (msg_num >= SRV_PROVBOX_MAX_INBOX_MSG_NUM)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_CAN_MOVE_MSG_INBOX_FULL,
                cur_msg_list->box_type,
                new_msg_list->box_type,
                cur_base_info->msg_id,
                cur_base_info->msg_flag,
                SRV_PROVBOX_MSG_GET_BIT_PROPERTY(cur_base_info));

            return SRV_PROVBOX_RESULT_BOX_FULL;
        }
    }

    return SRV_PROVBOX_RESULT_OK;
}

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 




