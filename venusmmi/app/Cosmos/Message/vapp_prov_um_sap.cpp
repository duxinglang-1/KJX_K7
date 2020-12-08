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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH¡ä?
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
 *  vapp_prov_um_sap.cpp
 *
 * Project:
 * --------
 *  venusmmi
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vcp_include.h"

#ifdef __MMI_PROV_IN_UM__ 
/*****************************************************************************
 * Include
 *****************************************************************************/
#ifdef __cplusplus
extern "C" 
#endif
{
#include "MMIDataType.h"

#include "UMSrvDefs.h"

#include "wgui_categories_util.h"

#include "ccasrvgprot.h"

#include "ProvBoxSrvIProt.h"
}

#include "mmi_rp_vapp_prov_msg_def.h"

#include "vapp_prov_util.h"

#include "vapp_nmgr_gprot.h"

#include "vapp_prov_viewer.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
#ifdef __cplusplus
extern "C" 
#endif
{
//static void vapp_prov_evt_hdlr_um_set_msg_info_ind(mmi_event_struct *para);

static void vapp_prov_evt_hdlr_um_set_sort_info_ind(mmi_event_struct *para);

static void vapp_prov_evt_hdlr_um_set_traverse_process_msg_deatil_ind(mmi_event_struct *evt);

static void vapp_prov_evt_hdlr_um_notify_ind(mmi_event_struct *evt);

static void vapp_prov_evt_hdlr_um_set_msg_state_ready_ind(mmi_event_struct *evt);

static void vapp_prov_um_set_msg_info(srv_um_msg_info_struct *um_msg_info, srv_provbox_msg_cmn_info_struct *cmn_info);

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
static void vapp_prov_um_set_sort_info(
                srv_um_list_idx_data_union *list_data, 
                const srv_provbox_msg_cmn_info_struct* msg_info,
                const S16 msg_size,
                U8 list_idx_type);
#endif

#ifdef __MMI_UM_CONVERSATION_BOX__
static S32 vapp_prov_um_traverse_process_msg_detail(
                srv_provbox_msg_cmn_info_struct *info, 
                S16 msg_size,
                U32 um_user_data,
                srv_um_detail_field_enum um_detail_field,
                srv_um_traverse_func um_traverse_callback);
#endif

}
/*****************************************************************************
 * Local function
 *****************************************************************************/
#ifdef __cplusplus
extern "C" 
#endif
{
MMI_RET vapp_prov_um_event_hdlr_proc(mmi_event_struct *evt)
{
    //srv_provbox_event_struct *evt_ind = (srv_provbox_event_struct*)evt;
	srv_provbox_evt_msg_info_struct *msg_info_evt = (srv_provbox_evt_msg_info_struct*)evt;
    
    
    switch (msg_info_evt->evt_type)
    {
        case SRV_PROVBOX_EVT_TYPE_BOX_FULL_IND:
        {
            vapp_prov_evt_hdlr_um_notify_ind(evt);
            break;
        }

        case SRV_PROVBOX_EVT_TYPE_SET_MSG_INFO_IND:
        {
			vapp_prov_um_set_msg_info(msg_info_evt->um_msg_info, msg_info_evt->msg_info);
            break;
        }

        case SRV_PROVBOX_EVT_TYPE_SET_SORT_INFO_IND:
        {
            vapp_prov_evt_hdlr_um_set_sort_info_ind(evt);
            break;
        }

        case SRV_PROVBOX_EVT_TYPE_SET_MSG_DETAIL_IND:
        {
            vapp_prov_evt_hdlr_um_set_traverse_process_msg_deatil_ind(evt);
            break;
        }
 
        case SRV_PROVBOX_EVT_TYPE_SET_MSG_STATE_READY_IND:
        {
            vapp_prov_evt_hdlr_um_set_msg_state_ready_ind(evt);
            break;
        }

        default:
           break;
    }
    return MMI_RET_OK;
}


static void vapp_prov_evt_hdlr_um_set_sort_info_ind(mmi_event_struct *para)
{
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    srv_provbox_evt_sort_info_struct* sort_info_evt = (srv_provbox_evt_sort_info_struct*)para;
    
    
    vapp_prov_um_set_sort_info(
        sort_info_evt->list_data,
        sort_info_evt->msg_info,
        sort_info_evt->msg_size,
        sort_info_evt->list_idx_type);
#endif
}

static void vapp_prov_evt_hdlr_um_set_traverse_process_msg_deatil_ind(mmi_event_struct *evt)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    srv_provbox_evt_msg_detail_struct *msg_detail_evt = (srv_provbox_evt_msg_detail_struct *)evt;
    
    
    if (NULL == msg_detail_evt)
    {
        return;
    }

    msg_detail_evt->traverse_ret = vapp_prov_um_traverse_process_msg_detail(
                                       msg_detail_evt->info,
                                       msg_detail_evt->msg_size,
                                       msg_detail_evt->um_user_data,
                                       msg_detail_evt->um_detail_field,
                                       msg_detail_evt->um_traverse_callback);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}

static void vapp_prov_evt_hdlr_um_set_msg_state_ready_ind(mmi_event_struct *evt)
{
    srv_provbox_evt_msg_msg_ready_struct *event = (srv_provbox_evt_msg_msg_ready_struct*)evt;

    
    if(event->um_set_ready_callback == NULL || event->user_data == NULL)
    {
        VFX_ASSERT(0);
    }

    (*(event->um_set_ready_callback))(event->set_ready_result, (void*)event->user_data);
}

static void vapp_prov_evt_hdlr_um_notify_ind(mmi_event_struct *evt)
{
    srv_provbox_evt_notify_struct *notify = (srv_provbox_evt_notify_struct *)evt;

    
    if (SRV_PROVBOX_NOTIFY_TYPE_MEM_FULL == notify->type)
    {
        vapp_nmgr_global_popup_show_confirm_one_button_id(
            MMI_SCENARIO_ID_PROVISIOING,
            VCP_POPUP_TYPE_WARNING,
            STR_ID_VAPP_PROV_INSUFFICIENT_MEMORY,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);
     }
}

void vapp_prov_msg_sent_install_req(U32 msg_id, S32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_process_prov_msg_req_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_process_prov_msg_req_struct*) OslConstructDataPtr(sizeof(srv_cca_process_prov_msg_req_struct));

    data->trans_id = trans_id;
    data->msg_id = (U32)msg_id;

    mmi_frm_send_ilm(MOD_MMI, 
        MSG_ID_MMI_CCA_PROCESS_PROV_MSG_REQ,
        (oslParaType*) data, 0);

}


U8 vapp_prov_msg_handle_install_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappOperateCell *obj = NULL;
    srv_cca_process_prov_msg_cnf_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_process_prov_msg_cnf_struct*) msg;

    if (data->trans_id != VAPP_PROV_TRANS_ID_CCA_PROCESS_MSG_EXT)
    {
        return MMI_RET_OK;
    }

    // Because install is ansyc process, obj may be not vailable.
    if (VFX_FALSE == VappOperateCell::onGetCell(&obj))
    {
        return MMI_RET_OK;
    }

    if (obj->m_pCbFunc)
    {
        (*obj->m_pCbFunc)(obj->m_userData);
    }

    VappOperateCell::onResetCell();

    /* Register event handler function */
    mmi_frm_clear_protocol_event_handler(
        MSG_ID_MMI_CCA_PROCESS_PROV_MSG_CNF,
        (PsIntFuncPtr) vapp_prov_msg_handle_install_cnf);

    return MMI_RET_OK;
}

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
static void vapp_prov_um_set_sort_info(
                srv_um_list_idx_data_union *list_data, 
                const srv_provbox_msg_cmn_info_struct* msg_info,
                const S16 msg_size,
                U8 list_idx_type)
{

    srv_um_list_idx_enum list_sort_type = (srv_um_list_idx_enum)list_idx_type;


    switch (list_sort_type)
    {
        case SRV_UM_LIST_IDX_MSG_SIZE:
            list_data->msg_size = msg_size;
            break;
            
        case SRV_UM_LIST_IDX_ADDRESS:
            mmi_wcsncpy(
                (WCHAR*)list_data->address, 
                (WCHAR*)msg_info->sender_addr.addr, 
                SRV_UM_MAX_LIST_INDEX_LEN);
            break;
            
        case SRV_UM_LIST_IDX_READ_STATUS:
            list_data->read_status = (kal_bool)(msg_info->read_status == SRV_PROVBOX_MSG_READ_STATUS_READ);
            break;
            
        case SRV_UM_LIST_IDX_MSG_TYPE:
            list_data->msg_type = SRV_UM_MSG_PROV;
            break;
            
        case SRV_UM_LIST_IDX_SUBJECT:
            mmi_wcsncpy(
                 (WCHAR *)list_data->subject, 
                 (WCHAR *)get_string(vapp_prov_get_sim_msg_title(mmi_frm_sim_to_index((mmi_sim_enum)msg_info->sim_id))), 
                 SRV_UM_MAX_LIST_INDEX_LEN);
            break;
        
        default:
            memset((void *)list_data, 0, sizeof(srv_um_list_idx_data_union));
            break;
    }
}
#endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  srv_provbox_um_traverse_process_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 vapp_prov_um_traverse_process_msg_detail(
                srv_provbox_msg_cmn_info_struct *info, 
                S16 msg_size,
                U32 um_user_data,
                srv_um_detail_field_enum um_detail_field,
                srv_um_traverse_func um_traverse_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_detail_struct detail;
    S32 traverse_reulst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void *)&detail, 0, sizeof(srv_um_msg_detail_struct));
    detail.msg_id   = info->msg_id;
    detail.msg_type = SRV_UM_MSG_PROV;
    detail.timestamp= info->timestamp;
    detail.msg_box_type = vapp_prov_box_type_pbox2um(info->box_type);
    detail.read_status = (kal_bool)vapp_prov_read_status_pbox2um(info->read_status);
    detail.msg_size = msg_size;
    vapp_prov_add_address(
            &detail, (WCHAR *)info->sender_addr.addr, 
            vapp_prov_addr_type_pbox2um(info->sender_addr.addr_type),
            SRV_UM_ADDR_GROUP_FROM);
    detail.subject = (WCHAR*)get_string(STR_ID_VAPP_PROV_MSG_LIST_ITEM_NAME);
#if (MMI_MAX_SIM_NUM >= 2)
    detail.sim_id = vapp_prov_sim_pbox2um((mmi_sim_enum)info->sim_id);
#endif

    traverse_reulst = um_traverse_callback(um_user_data, (srv_um_msg_detail_struct*)&detail);

    //vapp_prov_remove_address(&detail);

    return traverse_reulst;
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


static void vapp_prov_um_set_msg_info(srv_um_msg_info_struct *um_msg_info, srv_provbox_msg_cmn_info_struct *cmn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *name = NULL;
    S32 name_len;
    WCHAR msg_addr[VAPP_PROV_ADDR_MAX_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == um_msg_info || NULL == cmn_info)
    {
        return;
    }
    
    um_msg_info->msg_id = cmn_info->msg_id;
    um_msg_info->timestamp = cmn_info->timestamp;
    um_msg_info->address_type = vapp_prov_addr_type_pbox2um(cmn_info->sender_addr.addr_type);    
    vapp_prov_get_msg_address(
        msg_addr, (mmi_sim_enum)cmn_info->sim_id ,
        cmn_info->msg_type, &cmn_info->sender_addr);
    name_len = mmi_wcslen((const WCHAR*)msg_addr);
	mmi_wcscpy((WCHAR*)um_msg_info->address, msg_addr);
    um_msg_info->address_length = name_len;

    if (um_msg_info->address_type == SRV_UM_ADDR_IP_ADDRESS && !vapp_prov_ip_addr_is_validate((U16*)msg_addr, name_len))
    {
        um_msg_info->address_type = SRV_UM_ADDR_PLAIN_TEXT;
    }
	
    name = (WCHAR *)get_string(STR_ID_VAPP_PROV_MSG_LIST_ITEM_NAME);
    mmi_wcscpy((WCHAR*) um_msg_info->subject, (const WCHAR *)name);
    um_msg_info->subject_length = mmi_wcslen((const WCHAR *)name);
}

}

#endif /* __MMI_PROV_IN_UM__ */
