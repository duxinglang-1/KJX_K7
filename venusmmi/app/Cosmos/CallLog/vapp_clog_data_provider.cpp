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
 *  vapp_clog_data_provider.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_clog_config.h"
#include "vapp_clog_ui.h" 
#include "vapp_clog_data_provider.h"
#include "vapp_phb_gprot.h"
#include "mmi_rp_app_usbsrv_def.h"

#ifdef __cplusplus
extern "C"
{
#include "MMI_common_app_trc.h"
#include "mmi_frm_utility_gprot.h"
#include "PhbSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "FileMgrSrvGProt.h"

}
#endif

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

/*VappCLogDataProvider::VappCLogDataProvider() :
    m_currPageType(VAPP_CLOG_PAGE_BASIC),
    m_index(0),
    m_deletingIndex(0)
{
    for (VfxU32 i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        m_logIDs[i] = SRV_CLOG_INVALID_ELM;
    }
}
*/

VappCLogDataProvider::VappCLogDataProvider(VfxU8 pageType) :
    m_currPageType(pageType),
    m_index(0),
    m_deletingIndex(0)
{
    for (VfxU32 i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        m_logIDs[i] = SRV_CLOG_INVALID_ELM;
    }
}


void VappCLogDataProvider::onInit()
{
    regListener();
}


void VappCLogDataProvider::onDeinit()
{
    deregListener();
}


VfxU32 VappCLogDataProvider::getClogCount(VfxId which_list)
{
    if ((VAPP_CLOG_PAGE_BASIC == m_currPageType) ||
        (VAPP_CLOG_PAGE_FOR_DIALER == m_currPageType))
    {
        srv_clog_log_identity_struct req = {0};
        req.log_type = (which_list == VAPP_CLOG_LIST_ID_ALL_CALL) ? SRV_CLOG_CLT_ALL : SRV_CLOG_CLT_MISSED;

        srv_clog_num_info_struct array = {0};
        VfxS32 flag = VFX_TRUE;    
        flag = srv_clog_get_list_num_info(0, 
                                     (const srv_clog_log_identity_struct *)&req, 
                                     &array);

        if (flag != SRV_CLOG_RET_OK)
        {
            return 0;
        }

        VfxU32 itemcount = array.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS];
        return itemcount;
    }
    else // VappCLogList::CLOG_PAGE_FOR_CONTACT
    {
        return m_index;
    }
}



void VappCLogDataProvider::getClogIDs(VfxId which_list)
{
    m_currPageType = VAPP_CLOG_PAGE_BASIC;    

    srv_clog_get_list_log_ids_req_struct req = {0};
    srv_clog_get_list_log_ids_cnf_struct cnf = {0};
    req.log_type = (which_list == VAPP_CLOG_LIST_ID_ALL_CALL) ? SRV_CLOG_CLT_ALL : SRV_CLOG_CLT_MISSED;
    req.start_by = SRV_CLOG_BY_ID;
    req.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM; //getClogCount(which_list);
    VfxU32 idxOffset = 0;

    //SRV_CLOG_HANDLE hdlr;       
    //createCLogInstance(which_list, hdlr);
    while(1)
    {
        req.start_elm = cnf.next_start_elm;
        if (srv_clog_get_list_log_ids(0, &req, &cnf) != SRV_CLOG_RET_OK)
            break;
        
        memcpy(
            m_logIDs + idxOffset,
            cnf.log_ids,
            cnf.log_num * sizeof(SRV_CLOG_ID));
        idxOffset += cnf.log_num;

        if (cnf.next_start_elm == SRV_CLOG_INVALID_ELM)
            break;        
    }

    //srv_clog_destroy(hdlr);
}


#ifdef __MMI_CLOG_MARK_SEVERAL__
SRV_CLOG_ID VappCLogDataProvider::getClogIDByIdx(VfxU32 index)
{
    return m_logIDs[index];
}
#endif


VfxS32 VappCLogDataProvider::getClogByID(SRV_CLOG_ID log_id, srv_clog_log_struct &log)
{
    VfxS32 ret;
    ret = srv_clog_get_log_by_id(0, log_id, SRV_CLOG_LOG_FIELD_ALL, &log);
    
    if (SRV_CLOG_RET_OK != ret)//don't get success
    {
        MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_DATA_PROVIDER_GET_CLOG_BY_ID, 1);
        return ret;
    }

    // if one of following case happen, we will show this log as unsave in phb, so we need hide name and PHB_ID
    // case 1: this contact is saved in storage(NVRAM/SIM1/SIMx), but this storage is hide
    // case 2: this contact is FDN
    // case 3: this log have PHB_ID, but the number of log is not same to contact, e.g. save "A""123" to PHB SIM1,
    // then move SIM1 to other phone and modify to "A""456", then back insert to origal phone (already handle in
    // srv_clog_si_log_si2cmn_call())
    if (0 == vapp_clog_check_phb_id(log.data.call_log.phb_id.contact_index)) 
    {
        memset(log.data.call_log.name, 0, sizeof(WCHAR) * (SRV_CLOG_NAME_MAX_LEN + 1));
        srv_phb_set_invalid_number_id(&(log.data.call_log.phb_id));
    }

    // if one of following case happen, we will sync log name to contact name
    // case 1: this log have PHB_ID, but the name of log is not same to contact, e.g. save "A""123" to PHB SIM1,
    // then move SIM1 to other phone and modify to "B""123", then back insert to origal phone (already handle in
    // srv_clog_si_log_si2cmn_call())

    return ret;
}


SRV_CLOG_ID VappCLogDataProvider::getClogByIdx(VfxU32 idx, srv_clog_log_struct &log, VfxS32 &get_ret)
{
    get_ret = getClogByID(m_logIDs[idx], log);
    return m_logIDs[idx];
}


#ifdef __MMI_PHB_VIEW_CALLOG__
void VappCLogDataProvider::getClogIDsWithSamePHB(VfxU16 storeIndex)
{
    m_currPageType = VAPP_CLOG_PAGE_FOR_CONTACT;
    for (VfxU32 i = 0; i < SRV_CLOG_LOG_MAX_NUM; i++)
    {
        m_logIDs[i] = SRV_CLOG_INVALID_ELM;
    }
    
    SRV_CLOG_HANDLE hdlr;       
    createCLogInstance(VAPP_CLOG_LIST_ID_ALL_CALL, hdlr);

    srv_clog_search_list_log_ids_req_struct req;
    srv_clog_init_para(SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_REQ, &req);
    req.start_by = SRV_CLOG_BY_ID;
    req.search_fields = SRV_CLOG_LOG_FIELD_PHB_IDXS;
    req.start_elm = 0;
    req.phb_idx_num = 1;
    req.phb_idx[0] = storeIndex;
    m_index = 0;  
    m_isUpdating = VFX_TRUE;
    srv_clog_search_list_log_ids(
        hdlr,
        0,
        &req,
        getClogIDsWithSamePHBCb);
}


VfxS32 VappCLogDataProvider::getClogIDsWithSamePHBCb(
            SRV_CLOG_HANDLE handle,
            VfxS32 pid, 
            void *req_data,
            void* cnf_data, 
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    VappCLogDataProvider *obj = (VappCLogDataProvider *)srv_clog_get_user_data(handle);
    if (VFX_FALSE == obj->isValid())
        return SRV_CLOG_RET_STOP;
    
    srv_clog_search_list_log_ids_cnf_struct *cnf = (srv_clog_search_list_log_ids_cnf_struct *) cnf_data;

    if (ret == SRV_CLOG_RET_OK)
    {
        for (VfxU16 index = 0; index < cnf->id_num; index++)
        {
            obj->m_logIDs[(obj->m_index)++] = cnf->log_ids[index];
        }
    }
    else
    {
        //getClogDone();
        srv_clog_destroy(handle);
        return SRV_CLOG_RET_STOP;
    }
    
    if (more)
    {
        srv_clog_search_list_log_ids_req_struct *req = (srv_clog_search_list_log_ids_req_struct*)req_data;
        req->start_elm = cnf->next_elm;
            
        srv_clog_search_list_log_ids(
            handle,
            pid,
            req,
            getClogIDsWithSamePHBCb);
    }
    else
    {
        srv_clog_destroy(handle);
        obj->m_isUpdating = VFX_FALSE;
        obj->m_signalGetClogCbDone.emit();
    }

    return SRV_CLOG_RET_OK;
}


void VappCLogDataProvider::createCLogInstance(VfxId which_list, SRV_CLOG_HANDLE &hdlr) const
{
    VfxU32 sim_id = MMI_SIM_ALL;
	srv_clog_create_struct rc_create;
    rc_create.identity.cate = SRV_CLOG_CATE_CALL;
    rc_create.identity.sim_id = sim_id;
    rc_create.identity.log_type = (which_list == VAPP_CLOG_LIST_ID_ALL_CALL) ? SRV_CLOG_CLT_ALL : SRV_CLOG_CLT_MISSED;
    rc_create.identity.sub_type = SRV_CLOG_CALL_TYPE_ALL;
    rc_create.user_data = (void *)this;

    hdlr = srv_clog_create((const srv_clog_create_struct *)&rc_create);
}
#endif

void VappCLogDataProvider::regListener()
{    
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_ADD_LOG, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_ALL, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_LOG, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_ALL, VappCLogDataProvider::listener, (void *)this);
	mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_READY, VappCLogDataProvider::listener, (void *)this);

    mmi_frm_cb_reg_event(EVT_ID_PHB_READY, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_reg_event(EVT_ID_PHB_STORAGE_CHANGE, VappCLogDataProvider::listener, (void *)this);

    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappCLogDataProvider::listener, (void *)this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappCLogDataProvider::listener,(void *)this);
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, VappCLogDataProvider::listener, (void *)this);
#endif
}


void VappCLogDataProvider::deregListener()
{    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_ADD_LOG, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_ALL, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_LOG, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_ALL, VappCLogDataProvider::listener, (void *)this);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_READY, VappCLogDataProvider::listener, (void *)this);

    mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_STORAGE_CHANGE, VappCLogDataProvider::listener, (void *)this);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappCLogDataProvider::listener, (void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappCLogDataProvider::listener, (void *)this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, VappCLogDataProvider::listener,(void *)this);
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, VappCLogDataProvider::listener, (void *)this);
#endif
}


mmi_ret VappCLogDataProvider::listener(mmi_event_struct* evt)
{
    VappCLogDataProvider *obj = (VappCLogDataProvider *)evt->user_data;
    obj->processClogChanged(evt);
    return MMI_RET_OK;
}


void VappCLogDataProvider::processClogChanged() const
{
    m_signalGetClogCbDone.emit();
}


void VappCLogDataProvider::processClogChanged(void *evt) const
{
    if (((mmi_event_struct*) evt)->evt_id == EVT_ID_PHB_READY)
    {        
        srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;
        if (ready->phb_ready == MMI_FALSE) /* just care PHB ready event */
            return;
    }
    m_signalClogUpdated.emit(evt);
}


void VappCLogDataProvider::clearUnreadMissedCount() const
{
    if (srv_clog_get_unread_missed_call_num() == 0)
    {
        return;
    }
    if ((VAPP_CLOG_PAGE_BASIC == m_currPageType) ||
        (VAPP_CLOG_PAGE_FOR_DIALER == m_currPageType))
    {
        srv_clog_update_all_logs_req_struct req;
        srv_clog_init_para(SRV_CLOG_PARA_UPDATE_ALL_LOGS_REQ, &req);
        
    	req.log_type = SRV_CLOG_CLT_MISSED;
    	req.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
    	req.read = MMI_TRUE;
    	srv_clog_update_all_logs(0, 0,
    		(const srv_clog_update_all_logs_req_struct *)&req,
            NULL);
    }
    
#ifdef __MMI_PHB_VIEW_CALLOG__
    else if (VAPP_CLOG_PAGE_FOR_CONTACT == m_currPageType)
    {
        srv_clog_log_struct log;
        srv_clog_update_log_req_struct req;    
        VfxS32 result;

        for (VfxU32 i = 0; i < m_index; i++)
        {
            result = srv_clog_get_log_by_id(
                        0,
                        m_logIDs[i],
                        SRV_CLOG_LOG_FIELD_UNREAD_NUM,
                        &log);

            if (result != SRV_CLOG_RET_OK)
                break;

            if (log.data.call_log.unread_num > 0)
            {
                srv_clog_init_para(SRV_CLOG_PARA_UPDATE_LOG_REQ, &req);

                req.log_data.cate = SRV_CLOG_CATE_CALL;
                req.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
                req.log_data.data.call_log.log_id = log.data.call_log.log_id;
                req.log_data.data.call_log.unread_num = 0;

                srv_clog_update_log(
                    0,
                    0,
                    &req,
                    NULL);
             }
        }
    }
#endif
}




