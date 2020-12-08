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
 *  vapp_clog_action.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vfx_datatype.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMI_include.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "GlobalResdef.h"
#include "mmi_frm_utility_gprot.h"

#include "Custom_phb_config.h"
#include "Phbsrvgprot.h"
#include "vapp_phb_gprot.h"
#include "UcmSrvGprot.h"
#include "NWUsabSrvGprot.h"
#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcSrvGprot.h"
#endif
#include "CalllogSrvGprot.h"
}
#endif

#include "Vapp_uc_gprot.h"
#include "vcui_phb_gprot.h"
#include "vapp_dialer_cui.h" //temp
#include "vapp_launcher_gprot.h"

#if defined(__MMI_CM_BLACK_LIST__) && defined(__OP01__)
#include "vapp_callset.h"
#endif
#ifdef __MMI_SMS_COMPOSER__
#include "vcui_sms_composer_gprot.h"
#endif

#include "vapp_clog_config.h"
#include "vapp_clog_action.h"
#include "vapp_clog_ui.h"
#include "mmi_rp_vapp_calllog_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * Class VappCLogList
 *****************************************************************************/
VcpIndicatorPopup* VppCLogAction::m_indicator = NULL; 

VppCLogAction::VppCLogAction(srv_clog_log_struct & log) :
    m_dataSrv(NULL)
{
    //VFX_ASSERT(log.cate == SRV_CLOG_CATE_CALL);
   // memcpy(&m_clogItem, &log, sizeof(srv_clog_log_struct));
    setLog(log);
    
}


void VppCLogAction::setLog(const srv_clog_log_struct & log)
{
    VFX_ASSERT(log.cate == SRV_CLOG_CATE_CALL);
    memcpy(&m_clogItem, &log, sizeof(srv_clog_log_struct));
}

void VppCLogAction::setGroupId(mmi_id gid)
{
    m_groupId = gid;
}

void VppCLogAction::setAppScr(VfxAppScr *scr)
{
    m_scr = scr;
}


void VppCLogAction::onButtonClicked(VfxObject* sender, VfxId btnID)
{
    VFX_UNUSED(sender);
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_ACTION_BTN_CLICKED, btnID);
    switch (btnID)
    {
        case VAPP_CLOG_BTN_CALL_VOICE_SIM1:
            makeCall(SRV_UCM_VOICE_CALL_TYPE);
            break;
#if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_CLOG_BTN_CALL_VOICE_SIM2:
            makeCall(SRV_UCM_VOICE_CALL_TYPE_SIM2);
            break;
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_CLOG_BTN_CALL_VOICE_SIM3:
            makeCall(SRV_UCM_VOICE_CALL_TYPE_SIM3);
            break;
#endif           

#if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_CLOG_BTN_CALL_VOICE_SIM4:
            makeCall(SRV_UCM_VOICE_CALL_TYPE_SIM4);
            break;
#endif 

        case VAPP_CLOG_BTN_CALL_SELECT:
            break;    

        case VAPP_CLOG_BTN_CALL_VIDEO:
            makeCall(SRV_UCM_VIDEO_CALL_TYPE);
            break;

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
        case VAPP_CLOG_BTN_SEND_MSG:
            sendMSG(SRV_UC_SIM_ID_GSM_SIM1);
            break;
#if (MMI_MAX_SIM_NUM >= 2)

        case VAPP_CLOG_BTN_SEND_MSG_SIM2:
            sendMSG(SRV_UC_SIM_ID_GSM_SIM2);
            break;
#endif  
#if (MMI_MAX_SIM_NUM >= 3)

        case VAPP_CLOG_BTN_SEND_MSG_SIM3:
            sendMSG(SRV_UC_SIM_ID_GSM_SIM3);
            break;
#endif
#if (MMI_MAX_SIM_NUM >= 4)

        case VAPP_CLOG_BTN_SEND_MSG_SIM4:
            sendMSG(SRV_UC_SIM_ID_GSM_SIM4);
            break;
#endif
        case VAPP_CLOG_BTN_SEND_MSG_SELECT:
            break;

        case VAPP_CLOG_BTN_SEND_MSG_NO_SIM: // no sim to prefer
            sendMSG(SRV_UC_SIM_ID_UNCLASSIFIED);
            break;
#endif
#ifdef __MMI_SMS_COMPOSER__
        case VAPP_CLOG_BTN_SEND_MSG:
            sendMSG(MMI_SIM1);
            break;
#if (MMI_MAX_SIM_NUM >= 2)
        
        case VAPP_CLOG_BTN_SEND_MSG_SIM2:
             sendMSG(MMI_SIM2);
             break;
#endif  
#if (MMI_MAX_SIM_NUM >= 3)
        
        case VAPP_CLOG_BTN_SEND_MSG_SIM3:
             sendMSG(MMI_SIM3);
             break;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        
        case VAPP_CLOG_BTN_SEND_MSG_SIM4:
             sendMSG(MMI_SIM4);
             break;
#endif
       case VAPP_CLOG_BTN_SEND_MSG_SELECT:
            break;
        
        case VAPP_CLOG_BTN_SEND_MSG_NO_SIM: // no sim to prefer
             sendMSG(MMI_SIM_NONE);
             break;

#endif

        case VAPP_CLOG_BTN_VIEW_CONTACT:
            viewContact();
            break;

        case VAPP_CLOG_BTN_SAVE_TO_CONTACT:
            saveContact();
            break;

        case VAPP_CLOG_BTN_EDIT_BEFORE_CALL:
            editBeforeCall();
            break;

        case VAPP_CLOG_BTN_DELETE:
            deleteConfrim(DELETE_ITEM);
            break;
    #ifdef __MMI_PHB_VIEW_CALLOG__
        case VAPP_CLOG_BTN_DELETE_FOR_ONE_CONTACT:
            deleteConfrim(DELETE_LOGS_FOR_ONE_CONTACT);
            break;
    #endif
    #if defined(__MMI_CM_BLACK_LIST__) && defined(__OP01__)
        case VAPP_CLOG_BTN_VIEW_BLACK_LIST:
            viewBlackList();
            break;
    #endif

        default :
            break;
    }
}


void VppCLogAction::makeCall(srv_ucm_call_type_enum type)
{
    mmi_ucm_make_call_para_struct call_para;
    void *phb_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&call_para);
    call_para.dial_type = type;
    call_para.ucs2_num_uri = (U16*)m_clogItem.data.call_log.cid;
    call_para.adv_para.after_make_call_callback = makeCallCb;

    if(srv_phb_check_number_id(m_clogItem.data.call_log.phb_id))
        phb_data = srv_phb_create_cm_user_data_by_id(m_clogItem.data.call_log.phb_id);
    else if(m_clogItem.data.call_log.name[0] != 0) // have name string
        phb_data = srv_phb_create_cm_user_data((U16 *)m_clogItem.data.call_log.name, 0, SRV_PHB_INVALID_INDEX);
    else
       phb_data = NULL;

    call_para.adv_para.after_callback_user_data = phb_data;
    call_para.adv_para.phb_data = phb_data;
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_ACTION_MAKE_CALL, call_para.dial_type, phb_data);
    mmi_ucm_call_launch(GRP_ID_ROOT, &call_para);

}



void VppCLogAction::makeCallCb(mmi_ucm_after_make_call_cb_struct* cb_para)
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_ACTION_MAKE_CALL_CB, cb_para->user_data);
    if((cb_para != NULL) && (cb_para->user_data))
		srv_phb_destory_cm_user_data(cb_para->user_data);
}
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

void VppCLogAction::sendMSG(srv_uc_sim_id specify_sim)
{
    VappUcEntryStruct entry;
    memset(&entry, 0, sizeof(VappUcEntryStruct));
    if (specify_sim != SRV_UC_SIM_ID_UNCLASSIFIED)
    {
        entry.launch_mode = UC_LAUNCH_MODE_NORMAL;
        entry.sim_id = specify_sim;
    }
    entry.type = SRV_UC_STATE_WRITE_NEW_MSG;
#ifdef __MMI_VIDEO_TELEPHONY__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL))
    {
        entry.msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;	
    }
    else
#endif
    {
    entry.msg_type = SRV_UC_MSG_TYPE_DEFAULT;
    }
    entry.addr_num = 1;

    srv_uc_addr_struct uc_addr;
    memset(&uc_addr, 0, sizeof(srv_uc_addr_struct));
    uc_addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
    uc_addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;

    //VfxChar cid[SRV_CLOG_CID_MAX_LEN + 1] = {0};
    //mmi_wcs_n_to_asc(cid, m_clogItem.data.call_log.cid, SRV_CLOG_CID_MAX_LEN);
    uc_addr.addr = (kal_uint8 *)m_clogItem.data.call_log.cid;

    entry.addr = &uc_addr;
#ifdef __MMI_PHB_NEED_SERIALZE__
    if (m_groupId == mmi_frm_get_root_app(m_groupId))
    {
        VfxBool pre_check = vappUcAppLauncherPreCheck(&entry, VFX_TRUE);
        if(pre_check)
        {
            VfxU32 expUsedSize = mmi_res_get_app_heap_size(m_groupId);
            mmi_frm_asm_base_shrink_size(m_groupId, expUsedSize);
           // kal_prompt_trace(MOD_MMI, "mmi_frm_asm_base_shrink_size :m_groupId= %d , expUsedSize = %d ", m_groupId, expUsedSize);
            //vappUcAppLauncher(&entry);
        }
    }
#endif
    vappUcAppLauncher(&entry);
}
#endif
#ifdef __MMI_SMS_COMPOSER__

void VppCLogAction::sendMSG(mmi_sim_enum sim_id)
{

    mmi_id smsComposerCui = 0;
    VcuiSmsComposerEntryStruct *entryData;
    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );

    // set address
    VcuiSmsComposerAddrStruct address;
    address.next = NULL;
    address.previous = NULL;
    address.type = VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER;
    address.addr = (VfxWChar*)(m_clogItem.data.call_log.cid);  
    entryData->addr_num = 1;
    entryData->addr = &address;
    entryData->sim_id = sim_id;

    smsComposerCui = vcui_sms_composer_create(m_groupId);
    if(smsComposerCui !=  GRP_ID_INVALID)
    {
        vcui_sms_composer_set_entry_data(smsComposerCui, entryData);        
        vfxSetCuiCallerScr(smsComposerCui, m_scr);
        vcui_sms_composer_run(smsComposerCui);
    }
    VFX_FREE_MEM(entryData);

}   
#endif /* __MMI_SMS_COMPOSER__ */


void VppCLogAction::viewContact()
{
    mmi_id cui_id = vcui_phb_contact_viewer_create(m_groupId);
    if (cui_id == GRP_ID_INVALID)
        return;
    
    vcui_phb_contact_viewer_set_sub_app(cui_id, VAPP_PHB_VIEWER_PROFILE);

    srv_clog_call_log_struct *calllog = &(m_clogItem.data.call_log);
    mmi_phb_contact_id contact_id;
    //srv_phb_get_store_index_by_number(calllog->cid, &contact_id);
    contact_id = srv_phb_get_store_index_by_number_id(calllog->phb_id);
    vcui_phb_contact_viewer_set_contact_id(cui_id, contact_id);
    
    vcui_phb_contact_viewer_run(cui_id);
    vfxSetCuiCallerScr(cui_id, m_scr);
}


void VppCLogAction::saveContact()
{
    mmi_id cui_id = vcui_phb_contact_saver_create(m_groupId);    
    if (cui_id == GRP_ID_INVALID)
        return;

    vcui_phb_contact_saver_set_type(cui_id, VAPP_PHB_SAVE_CONTACT_DEFAULT);

    srv_clog_call_log_struct *calllog = &(m_clogItem.data.call_log);
    
    if (calllog->name[0] != '\0')
    {
        vcui_phb_contact_saver_set_name(cui_id, calllog->name, vfx_sys_wcslen((const VfxWChar *) calllog->name));
    }
    vcui_phb_contact_saver_set_number(cui_id, calllog->cid, vfx_sys_wcslen((const VfxWChar *) calllog->cid));
    
    vcui_phb_contact_saver_run(cui_id);
    //vfxSetCuiCallerScr(cui_id, m_scr);
    mmi_frm_group_set_caller_proc(cui_id, &VppCLogAction :: listener, getObjHandle());
}


mmi_ret VppCLogAction :: listener(mmi_event_struct * evt)
{
	VppCLogAction * obj = (VppCLogAction *)evt;
    if(obj)
    {
        return obj->onProc(evt);
    }
}


void VppCLogAction::editBeforeCall()
{
    mmi_id cui_id = vcui_dialer_create(m_groupId);
    if (cui_id == GRP_ID_INVALID)
        return;

    srv_clog_call_log_struct *calllog = &(m_clogItem.data.call_log);
    VfxWString str;
    //str = VFX_WSTR_MEM(calllog->cid);
    str.loadFromMem(calllog->cid);
    vcui_dialer_set_dial_string(cui_id, str);

    void * user_data;
    if (srv_phb_check_number_id(calllog->phb_id))
        user_data = srv_phb_create_cm_user_data_by_id(calllog->phb_id);
    else if (calllog->name[0] != '\0')
        user_data = srv_phb_create_cm_user_data(calllog->name, 0, SRV_PHB_INVALID_INDEX);
    else
        user_data = NULL;
    vcui_dialer_set_phb_data(cui_id, user_data);
    
    vcui_dialer_run(cui_id);
    vfxSetCuiCallerScr(cui_id, m_scr);
}


mmi_ret VppCLogAction::onProc(mmi_event_struct *evt)
{
    mmi_ret result = MMI_RET_OK;
    
    mmi_id sender_id = ((mmi_group_event_struct*) evt)->sender_id;
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_PHB_SAVE_RESULT:
        {
            vcui_phb_contact_saver_close(sender_id);
            break;
        }
        case EVT_ID_CUI_PHB_VIEW_RESULT:
        {
            vcui_phb_contact_viewer_close(sender_id);
            break;
        }

        case EVT_ID_CUI_DIALER_CLOSE_REQ:
		{
            vcui_dialer_close(sender_id);
            break;
		}

        case EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED:
		{
            VfxWString str = vcui_dialer_get_dial_string(sender_id);
            if (!(str.isEmpty()))
            {
                VfxBool ret = srv_phb_compare_number((U16 *)(str.getBuf()), m_clogItem.data.call_log.cid);
                if (ret)
                    return MMI_RET_OK;
            }
			void *udata = vcui_dialer_get_phb_data(sender_id);
            if (!udata)
                return MMI_RET_OK;
            srv_phb_destory_cm_user_data(udata);
            vcui_dialer_set_phb_data(sender_id, NULL);
            break;
		}

        case EVT_ID_CUI_DIALER_CLOSED_IND:
		{
            void *udata = vcui_dialer_get_phb_data(sender_id);
            if (!udata)
                return MMI_RET_OK;
            srv_phb_destory_cm_user_data(udata);
            vcui_dialer_set_phb_data(sender_id, NULL);
            break;
		}
#ifdef __MMI_SMS_COMPOSER__
        case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
        {
            /* just close it */
            VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct *)evt;
            vcui_sms_composer_close(ucEvt->sender_id);        
            break;
        }
#endif       
        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


void VppCLogAction::deleteConfrim(deleteTypeEnum type)
{
    VcpConfirmPopup *cnfPopup;
    VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);//getMainScr());
        
    cnfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_deleteType = type;
    VfxU16 firstBtnStr = STR_GLOBAL_CLEAR;
    switch (type)
    {
        case DELETE_ITEM:
            //cnfPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_DELETE_THE_CALL_LOG_QUERY));
            cnfPopup->setText(STR_ID_VAPP_CLOG_DELETE_THE_CALL_LOG_QUERY);
            firstBtnStr = STR_GLOBAL_DELETE;
            break;

        case DELETE_MISSED:
            //cnfPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_CLEAR_THE_MISSED_CALL_QUERY));
            cnfPopup->setText(STR_ID_VAPP_CLOG_CLEAR_THE_MISSED_CALL_QUERY);
            break;

        case DELETE_ALL:
#ifdef __MMI_PHB_VIEW_CALLOG__
        case DELETE_LOGS_FOR_ONE_CONTACT:
#endif
            //cnfPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_CLEAR_THE_CALL_LOG_QUERY));
            cnfPopup->setText(STR_ID_VAPP_CLOG_CLEAR_THE_CALL_LOG_QUERY);
            break;

        default :
            cnfPopup->setText(VFX_WSTR_EMPTY);
            break;
    }
    cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    cnfPopup->setCustomButton(
        //VFX_WSTR_RES(firstBtnStr),
        firstBtnStr,
        //VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    cnfPopup->show(VFX_TRUE);
    cnfPopup->m_signalButtonClicked.connect(this, &VppCLogAction::onDelelteConfrimButtonClicked);

}


void VppCLogAction::onDelelteConfrimButtonClicked(VfxObject* sender, VfxId buttonId)
{
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == buttonId)
    {
        //deleting(); // need close m_indicator after done, and note same contact
        deleteClog(onDeleteCbk);
    }
}


/*void VppCLogAction::deleting()
{
    VFX_OBJ_CREATE(m_indicator, VcpIndicatorPopup, this);
    m_indicator->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    switch (m_deleteType)
    {
        case DELETE_ITEM:
            m_indicator->setText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_CLEARING));
            break;

        case DELETE_MISSED:
            m_indicator->setText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_CLEARING));
            break;

        case DELETE_ALL:
            m_indicator->setText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_CLEARING));
            break;

        default :
            m_indicator->setText(VFX_WSTR_EMPTY);
            break;
    }
    m_indicator->show(VFX_TRUE);
}*/


void VppCLogAction::deleteClog(SRV_CLOG_BASE_CB cbk)
{
    switch (m_deleteType)
    {
        case DELETE_ITEM:
            srv_clog_delete_log_by_id(0, 0, m_clogItem.data.call_log.log_id, cbk);
            break;

        case DELETE_MISSED:
            srv_clog_del_all_logs_req_struct delMissedReq;
            srv_clog_init_para(SRV_CLOG_PARA_DEL_ALL_LOGS_REQ, &delMissedReq);
            delMissedReq.log_type = SRV_CLOG_CLT_MISSED;
            srv_clog_delete_all_logs(0, 0, &delMissedReq, cbk);
            break;

        case DELETE_ALL:
            srv_clog_del_all_logs_req_struct delAllReq;
            srv_clog_init_para(SRV_CLOG_PARA_DEL_ALL_LOGS_REQ, &delAllReq);
            delAllReq.log_type = SRV_CLOG_CLT_ALL;
            srv_clog_delete_all_logs(0, 0, &delAllReq, cbk);
            break;
#ifdef __MMI_PHB_VIEW_CALLOG__

        case DELETE_LOGS_FOR_ONE_CONTACT:
            m_dataSrv->deregListener(); // prevent list reveive too many srv event
            deleteClogsForSamePHB(NULL, 0);
            break;
#endif
        default :
            break;
    }    
}


VfxS32 VppCLogAction::onDeleteCbk(SRV_CLOG_HANDLE handle, VfxS32 pid,
                                void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret)
{
    return SRV_CLOG_RET_OK;
}


void VppCLogAction::closeMyself()
{
    VfxObject *obj = (VfxObject *)this;
    VFX_OBJ_CLOSE(obj);
}


#ifdef __MMI_PHB_VIEW_CALLOG__
void VppCLogAction::deleteClogsForSamePHB(VfxObject* obj, VfxId id)
{   
    VFX_UNUSED(obj);
    VFX_UNUSED(id);
    if ((NULL != m_dataSrv) && 
        (m_dataSrv->m_logIDs[m_dataSrv->m_deletingIndex] != SRV_CLOG_INVALID_ELM) && 
        (m_dataSrv->m_currPageType == VAPP_CLOG_PAGE_FOR_CONTACT))
    {
        SRV_CLOG_HANDLE hdlr;       
        VfxU32 sim_id = MMI_SIM_ALL;
    	srv_clog_create_struct rc_create;
        rc_create.identity.cate = SRV_CLOG_CATE_CALL;
        rc_create.identity.sim_id = sim_id;
        rc_create.identity.log_type = SRV_CLOG_CLT_ALL;
        rc_create.identity.sub_type = SRV_CLOG_CALL_TYPE_ALL;
        rc_create.user_data = (void *)this;

        hdlr = srv_clog_create((const srv_clog_create_struct *)&rc_create);
        
        srv_clog_delete_log_by_id(hdlr, 0, m_dataSrv->m_logIDs[m_dataSrv->m_deletingIndex], deleteClogsForSamePHBCb);
    }
    else
    {
        m_dataSrv->m_deletingIndex = 0;
        m_dataSrv->regListener();
    }
}


VfxS32 VppCLogAction::deleteClogsForSamePHBCb(SRV_CLOG_HANDLE handle, VfxS32 pid,
                                void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret)
{
    VppCLogAction *obj = (VppCLogAction *)srv_clog_get_user_data(handle);
    
    if (obj->isValid() && (ret == SRV_CLOG_RET_OK))
    {
        obj->m_dataSrv->m_logIDs[obj->m_dataSrv->m_deletingIndex] = SRV_CLOG_INVALID_ELM;
        obj->m_dataSrv->m_deletingIndex++;
        obj->m_dataSrv->m_index--;
        srv_clog_destroy(handle);
        obj->deleteClogsForSamePHB(NULL, 0);
    }
	return SRV_CLOG_RET_OK;
}
#endif

#if defined(__MMI_CM_BLACK_LIST__) && defined(__OP01__)
void VppCLogAction::viewBlackList()
{
	VappCallSetPageBL *pageBL;
	VFX_OBJ_CREATE(pageBL, VappCallSetPageBL, (VfxMainScr*)m_scr);
	((VfxMainScr*)m_scr)->pushPage(VFX_ID_NULL, pageBL);
}
#endif /*  __MMI_CM_BLACK_LIST__ && __OP01__  */


static void vapp_clog_make_call_cbk(mmi_ucm_after_make_call_cb_struct* cb_para)
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_ACTION_MAKE_CALL_CB, cb_para->user_data);
    if((cb_para != NULL) && (cb_para->user_data))
		srv_phb_destory_cm_user_data(cb_para->user_data);
}


// respond hook key in earphone, if in idle and no active all, will dial the last calllog
extern "C" mmi_ret vapp_clog_gpio_hookkey_hdlr(mmi_event_struct *evt)
{
    if (vapp_launcher_is_active() &&
        0 == srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        U8 sim_id = MMI_SIM_NONE;
        if (srv_nw_usab_is_usable(MMI_SIM1))
            sim_id |= MMI_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        if (srv_nw_usab_is_usable(MMI_SIM2))
            sim_id |= MMI_SIM2;
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        if (srv_nw_usab_is_usable(MMI_SIM3))
            sim_id |= MMI_SIM3;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (srv_nw_usab_is_usable(MMI_SIM4))
            sim_id |= MMI_SIM4;
    #endif

        if (MMI_SIM_NONE != sim_id)
        {
            srv_clog_get_last_log_req_struct req_data;
            srv_clog_get_last_log_cnf_struct cnf_data;
            srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ, &req_data);
            srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF, &cnf_data);
            req_data.fields = SRV_CLOG_LOG_FIELD_ALL;
            SRV_CLOG_INIT_IDT(
                (srv_clog_log_identifier_struct*) & req_data,
                SRV_CLOG_CATE_CALL,
                sim_id,
                SRV_CLOG_CLT_DIALED,
                SRV_CLOG_CALL_TYPE_ALL);
            
            S32 ret = srv_clog_get_last_log(0,
                        (const srv_clog_get_last_log_req_struct *) &req_data, &cnf_data);
            if (SRV_CLOG_RET_OK != ret)
                return MMI_RET_ERR; // don't ask other APP to handle this event again

            // start to make call
            srv_clog_call_log_struct *log = &(cnf_data.log.data.call_log);
            mmi_ucm_make_call_para_struct call_para;
            void *phb_data;
            mmi_ucm_init_call_para(&call_para);
           /* if (MMI_SIM1 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
            else if (MMI_SIM2 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
            else if (MMI_SIM3 == log->sim_id)
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
            else// MMI_SIM4
                call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;*/
            call_para.dial_type = srv_ucm_query_voice_type_by_sim((mmi_sim_enum)log->sim_id);
            
            call_para.ucs2_num_uri = (U16*)log->cid;
            call_para.adv_para.after_make_call_callback = vapp_clog_make_call_cbk;

            if(srv_phb_check_number_id(log->phb_id))
                phb_data = srv_phb_create_cm_user_data_by_id(log->phb_id);
            else if(log->name[0] != 0) // have name string
                phb_data = srv_phb_create_cm_user_data((U16 *)log->name, 0, SRV_PHB_INVALID_INDEX);
            else
               phb_data = NULL;

            call_para.adv_para.after_callback_user_data = phb_data;
            call_para.adv_para.phb_data = phb_data;
            MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_ACTION_MAKE_CALL, call_para.dial_type, phb_data);
            mmi_ucm_call_launch(GRP_ID_ROOT, &call_para);
        }
        return MMI_RET_ERR; // don't ask other APP to handle this event again
    }          
    return MMI_RET_OK; // ask other APP to handle this event again
}
