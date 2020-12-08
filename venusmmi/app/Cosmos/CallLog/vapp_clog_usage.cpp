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
 *  vapp_clogusage.cpp
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
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vdat_systime.h"
#include "vfx_app_scr.h"

#include "vcui_secset_gprot.h"
#include "vapp_sim_setting_gprot.h"

#include "Vapp_clog_usage.h"
#include "vapp_clog_data_provider.h"
#include "mmi_rp_vapp_calllog_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "GlobalResdef.h"
#include "mmi_features.h"
#include "MMI_common_app_trc.h"
#include "mmi_frm_utility_gprot.h"
#include "SmsSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"

#ifdef __cplusplus
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
#if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))

extern "C" void vapp_clog_usage_launch(VfxMainScr * scr)
{
    VfxS32 i;
    VfxS32 sim_count = srv_sim_ctrl_get_num_of_inserted();
    if (sim_count == 1)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
            {
                VappClogUsagePage *usage;
                VFX_OBJ_CREATE_EX(usage, VappClogUsagePage,scr, (mmi_frm_index_to_sim(i)));
                scr->pushPage(0, usage);
                return;
            }
        }
    }
    else if (sim_count == 0)
    {
        // hide SIM usage menu in setting config
    }
    else
    {
        VappClogUsageSIMPage *page;
        VFX_OBJ_CREATE(page, VappClogUsageSIMPage, scr);
        scr->pushPage(0, page);
    }
}


extern "C" mmi_ret vapp_clog_usage_init(mmi_event_struct *evt)
{
    VappClogUsageMain *createObj = VFX_OBJ_GET_INSTANCE(VappClogUsageMain);
    return MMI_RET_OK;
}


VfxBool vapp_clog_usage_checking_hdlr(void)
{
    // Do not displayed when no SIM
    return (srv_sim_ctrl_get_num_of_inserted() == 0 ? VFX_FALSE : VFX_TRUE);
}
#endif

#if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))

/*****************************************************************************
 * Class VappClogUsageMain
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappClogUsageMain);

VappClogUsageMain::VappClogUsageMain()
{
    checkResetUsage();

    // register DateTime auto change signal and user change signal
    // Connect signal to refresh usage data.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappClogUsageMain::onTimeChanged);
}


void VappClogUsageMain::checkResetUsage()
{
    VfxS16 sError;
    VfxU16 storeDate = 0; // storeDate = Year * 12 + Month
    ReadValue(NVRAM_VAPP_CLOG_USAGE_MONTH, &storeDate, DS_SHORT, &sError);

    VfxU32 storeYear = (storeDate - 1) / 12;
    VfxU32 storeMonth = storeDate - (storeYear * 12);

    VfxDateTime currTime;
	currTime.setCurrentTime();
    if (storeYear != currTime.getYear() || storeMonth != currTime.getMonth())
    {
        // reset all SIM usage to 0, becuase month is diff
    #ifdef __MMI_CLOG_CALL_TIME__
        srv_clog_ctime_reset_data((mmi_sim_enum)MMI_SIM_ALL, 
            SRV_CLOG_CALL_TYPE_ALL, 
            SRV_CLOG_CTIME_FIELD_ALL);
    #endif /* __MMI_CLOG_CALL_TIME__ */

    #ifdef __MMI_CLOG_SMS_COUNT__
        srv_sms_reset_sms_counter(SRV_SMS_SIM_1, SRV_SMS_COUNT_SENT);
        srv_sms_reset_sms_counter(SRV_SMS_SIM_1, SRV_SMS_COUNT_RECV);
    #if (MMI_MAX_SIM_NUM >= 2)
        srv_sms_reset_sms_counter(SRV_SMS_SIM_2, SRV_SMS_COUNT_SENT);
        srv_sms_reset_sms_counter(SRV_SMS_SIM_2, SRV_SMS_COUNT_RECV);
    #if (MMI_MAX_SIM_NUM >= 3)
        srv_sms_reset_sms_counter(SRV_SMS_SIM_3, SRV_SMS_COUNT_SENT);
        srv_sms_reset_sms_counter(SRV_SMS_SIM_3, SRV_SMS_COUNT_RECV);
    #if (MMI_MAX_SIM_NUM >= 4)
        srv_sms_reset_sms_counter(SRV_SMS_SIM_4, SRV_SMS_COUNT_SENT);
        srv_sms_reset_sms_counter(SRV_SMS_SIM_4, SRV_SMS_COUNT_RECV);
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    #endif /* __MMI_CLOG_SMS_COUNT__ */

    #ifdef __MMI_CLOG_GPRS_COUNT__
        srv_clog_gprs_reset_req_struct req_data;
        req_data.sim_id = (mmi_sim_enum)MMI_SIM_ALL;
        req_data.fields = SRV_CLOG_GPRS_FIELD_ALL;
        srv_clog_gprs_reset_data(
            (const srv_clog_gprs_reset_req_struct *)&req_data, 
            this, 
            resetGPRScb);
    #else
        onUpdateUsage();
    #endif /* __MMI_CLOG_GPRS_COUNT__ */
    
        // store current date to NVRAM Cache
        storeDate = (currTime.getYear() * 12) + currTime.getMonth();
        WriteValue(NVRAM_VAPP_CLOG_USAGE_MONTH, &storeDate, DS_SHORT, &sError);
    }

}


#ifdef __MMI_CLOG_GPRS_COUNT__
VfxS32 VappClogUsageMain::resetGPRScb (void *user_data,
                       srv_clog_gprs_reset_req_struct *req_data,
                       MMI_BOOL more, srv_clog_ret_enum ret)
{
    VappClogUsageMain *obj = (VappClogUsageMain *)user_data;
    if (more == MMI_FALSE)
    {
        obj->onUpdateUsage();
    }

	return SRV_CLOG_RET_OK;
}
#endif /* __MMI_CLOG_GPRS_COUNT__ */


void VappClogUsageMain::onTimeChanged(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_MONTH)
    { 
        checkResetUsage();
    }
}

void VappClogUsageMain::onUpdateUsage()
{
    m_signalUpdateUsage.postEmit();
}
#endif

#if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))


/*****************************************************************************
* Class VappClogUsageSIMPage
*****************************************************************************/ 
VappClogUsageSIMPage::VappClogUsageSIMPage() :
        m_form(NULL)
{
}


void VappClogUsageSIMPage::onInit()
{
    VfxPage::onInit(); // call base class

    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE));    // set title text
    setTopBar(titleBar);
    
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VfxS32 i;
    mmi_sim_enum sim;
    VfxWString sim_name;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_inserted(sim))
        { 
            VcpFormItemLauncherCell *simcell;
            VFX_OBJ_CREATE(simcell, VcpFormItemLauncherCell, m_form);
            sim_name = vapp_sim_settings_get_sim_name_with_sim_id(sim);
            simcell->setMainText(sim_name);
            simcell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            simcell->m_signalTap.connect(this, &VappClogUsageSIMPage::onItemTapped);
            m_form->addItem(simcell, i); // note: i will mapping with LIST_SIMi
        }
    }
}


void VappClogUsageSIMPage::onItemTapped(VcpFormItemCell* cell, VfxId index)
{
    mmi_sim_enum currSIMID;
    currSIMID = mmi_frm_index_to_sim(index);
    VappClogUsagePage *usage;
    VFX_OBJ_CREATE_EX(usage, VappClogUsagePage, getMainScr(), (currSIMID));
    getMainScr()->pushPage(0, usage);
}
#endif

/*****************************************************************************
* Class VappClogUsagePage
*****************************************************************************/
#if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))

VappClogUsagePage::VappClogUsagePage() :
    m_form(NULL),
    m_simID(MMI_SIM1),
    m_focusFormCellId(0)
{
#ifdef __MMI_CLOG_CALL_COST__
    m_maxCost = 0;
    m_price[0] = 0;
    m_unit[0] = 0;
#endif
}

VappClogUsagePage::VappClogUsagePage(mmi_sim_enum simID) :
    m_form(NULL),
    m_simID(simID),
    m_focusFormCellId(0)
{
#ifdef __MMI_CLOG_CALL_COST__
    m_maxCost = 0;
    m_price[0] = 0;
    m_unit[0] = 0;
#endif
}


void VappClogUsagePage::onInit()
{
    VfxPage::onInit(); // call base class

    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        VfxWString sim_name = vapp_sim_settings_get_sim_name_with_sim_id(m_simID);
        titleBar->setTitle(sim_name);
    }
    else
    {
        titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE));
    }
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);   

#ifdef __MMI_CLOG_GPRS_COUNT__
    createGPRSCountForm();
#endif

#ifdef __MMI_CLOG_SMS_COUNT__
    createSMSCountForm();
#endif

#ifdef __MMI_CLOG_CALL_TIME__
    createCallTimeForm();
#endif

#ifdef __MMI_CLOG_CALL_COST__
    createCallCostForm();
#endif

    VappClogUsageMain *mainObj = VFX_OBJ_GET_INSTANCE(VappClogUsageMain);
    mainObj->m_signalUpdateUsage.connect(this, &VappClogUsagePage::updateUsageData);
}


void VappClogUsagePage::onEnter(VfxBool isBackward)
{
    updateUsageData();
    VappClogUsageMain *mainObj = VFX_OBJ_GET_INSTANCE(VappClogUsageMain);
    mainObj->m_signalUpdateUsage.connect(this, &VappClogUsagePage::updateUsageData);
    
#ifdef __MMI_CLOG_SMS_COUNT__
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_COUNTER, VappClogUsagePage::listener, (void *)this);
#endif

#ifdef __MMI_CLOG_CALL_TIME__
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappClogUsagePage::listener, (void *)this);
#endif
}


void VappClogUsagePage::onExit(VfxBool isBackward)
{
    VappClogUsageMain *mainObj = VFX_OBJ_GET_INSTANCE(VappClogUsageMain);
    mainObj->m_signalUpdateUsage.disconnect(this, &VappClogUsagePage::updateUsageData);

#ifdef __MMI_CLOG_SMS_COUNT__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_UPDATE_COUNTER, VappClogUsagePage::listener, (void *)this);
#endif

#ifdef __MMI_CLOG_CALL_TIME__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappClogUsagePage::listener, (void *)this);
#endif
}


mmi_ret VappClogUsagePage::listener(mmi_event_struct* evt)
{
    VappClogUsagePage *obj = (VappClogUsagePage *)(evt->user_data);
    switch (evt->evt_id)
    {
    #ifdef __MMI_CLOG_SMS_COUNT__
        case EVT_ID_SRV_SMS_UPDATE_COUNTER:
            obj->getSMSCountData();
            break;
    #endif      

    #ifdef __MMI_CLOG_CALL_TIME__
        case EVT_ID_SRV_CLOG_UPDATE_LOG:
            obj->getCallTimeData();
            break;
    #endif

        default:
            break;
    }

    return MMI_RET_OK;
}

void VappClogUsagePage::updateUsageData()
{
#ifdef __MMI_CLOG_GPRS_COUNT__ 
    getGPRSCountData();
#endif

#ifdef __MMI_CLOG_SMS_COUNT__
    getSMSCountData();
#endif

#ifdef __MMI_CLOG_CALL_TIME__
    getCallTimeData();
#endif

#ifdef __MMI_CLOG_CALL_COST__
    getCallCostData();
#endif
}


#ifdef __MMI_CLOG_GPRS_COUNT__

void VappClogUsagePage::createGPRSCountForm()
{
    
    m_form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_GPRS), ID_GPRS_CAPTION);

    VappClogUsageCell *monthly_all;
    VFX_OBJ_CREATE(monthly_all, VappClogUsageCell, m_form);
    monthly_all->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_MONTHLY_ALL));
    monthly_all->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(monthly_all, ID_GPRS_MONTHLY_ALL);

    VappClogUsageCell *monthly_received;
    VFX_OBJ_CREATE(monthly_received, VappClogUsageCell, m_form);
    monthly_received->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_MONTHLY_RECEIVED));
    monthly_received->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(monthly_received, ID_GPRS_MONTHLY_RECEIVE);

    VappClogUsageCell *monthly_sent;
    VFX_OBJ_CREATE(monthly_sent, VappClogUsageCell, m_form);
    monthly_sent->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_MONTHLY_SENT));
    monthly_sent->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(monthly_sent, ID_GPRS_MONTHLY_SENT);
}


void VappClogUsagePage::getGPRSCountData()
{
    srv_clog_gprs_get_req_struct req;
    req.sim_id = m_simID;

    //Todo, Add Trace here
    MMI_TRACE(MMI_COMMON_TRC_G4_CLOG, TRC_VCLOG_GPRS_GET_DATA, 1, req.sim_id);
    srv_clog_gprs_get_data((const srv_clog_gprs_get_req_struct*)&req, (void *)this, getGPRSCountDataCbk);
}


VfxS32 VappClogUsagePage::getGPRSCountDataCbk(void *user_data,
                                     srv_clog_gprs_get_req_struct *req_data,
                                     const srv_clog_gprs_data_struct *gprs_data,
                                     MMI_BOOL more, srv_clog_ret_enum ret)
{
    MMI_TRACE(
        MMI_COMMON_TRC_G4_CLOG,
        TRC_VCLOG_GPRS_GET_DATA_CB,
        req_data->sim_id,
        gprs_data->last_recved,
        gprs_data->last_sent,
        gprs_data->total_recved,
        gprs_data->total_sent); 
    
    if (ret == SRV_CLOG_RET_OK)
    {
        VappClogUsagePage *gprsItem = (VappClogUsagePage *)user_data;
        if (VFX_FALSE == gprsItem->isValid())
            return SRV_CLOG_RET_OK;
        
        VfxWString received;
        gprsItem->convertGPRSCount(gprs_data->total_recved, received);
        ((VappClogUsageCell *)gprsItem->m_form->getItem(ID_GPRS_MONTHLY_RECEIVE))->setHintText(received);

        VfxWString sent;
        gprsItem->convertGPRSCount(gprs_data->total_sent, sent);
        ((VappClogUsageCell *)gprsItem->m_form->getItem(ID_GPRS_MONTHLY_SENT))->setHintText(sent);

        VfxWString all; //Todo, maybe 1.1 + 3.3 = 4.3
        gprsItem->convertGPRSCount(gprs_data->total_recved + gprs_data->total_sent, all);
        ((VappClogUsageCell *)gprsItem->m_form->getItem(ID_GPRS_MONTHLY_ALL))->setHintText(all);

        //Need get GPRS thershold and onOff flag
    }
	return SRV_CLOG_RET_OK;
}


void VappClogUsagePage::convertGPRSCount(VfxU64 count, VfxWString & str)
{
    if (count == 0) // 0 byte
    {
        str.format("0 KB");
    }
    else if (count < 103) // less than 0.1KB
    {
        str.format("0.1 KB");
    }
    else if (count < 1024 * 1024) // less than 1MB
    {
        str.format("%.1f KB", (VfxFloat)count / 1024);
    }
    else
    {
        str.format("%.1f MB", (VfxFloat)count / (1024 * 1024));
    }
}

#endif /* __MMI_CLOG_GPRS_COUNT__ */


#ifdef __MMI_CLOG_SMS_COUNT__

void VappClogUsagePage::createSMSCountForm()
{
    m_form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_SMS), ID_SMS_CAPTION);

    VappClogUsageCell *monthly_received;
    VFX_OBJ_CREATE(monthly_received, VappClogUsageCell, m_form);
    monthly_received->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_MONTHLY_INCOMING));
    monthly_received->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(monthly_received, ID_SMS_MONTHLY_RECEIVE);

    VappClogUsageCell *monthly_sent;
    VFX_OBJ_CREATE(monthly_sent, VappClogUsageCell, m_form);
    monthly_sent->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_MONTHLY_OUTGOING));
    monthly_sent->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(monthly_sent, ID_SMS_MONTHLY_SENT);
}


void VappClogUsagePage::getSMSCountData()
{
    srv_sms_sim_enum currSIMType;
    if (MMI_SIM1 == m_simID)
        currSIMType = SRV_SMS_SIM_1;
    else if (MMI_SIM2 == m_simID)
        currSIMType = SRV_SMS_SIM_2;
#if (MMI_MAX_SIM_NUM >= 3)
    else if (MMI_SIM3 == m_simID)
        currSIMType = SRV_SMS_SIM_3;
#if (MMI_MAX_SIM_NUM >= 4)
    else if (MMI_SIM4 == m_simID)
        currSIMType = SRV_SMS_SIM_4;
#endif
#endif /*  (MMI_MAX_SIM_NUM >= 3) */
    else
    {
        VFX_ASSERT(0);
        currSIMType = SRV_SMS_SIM_1;
    }
    //Todo, maybe need add unit, such as "2 messages"
    VfxU16 sent = srv_sms_get_sms_counter(currSIMType, SRV_SMS_COUNT_SENT);
    VfxWString sent_str;
    sent_str.format("%d", sent);
    ((VappClogUsageCell *)m_form->getItem(ID_SMS_MONTHLY_SENT))->setHintText(sent_str);

    VfxU16 recv = srv_sms_get_sms_counter(currSIMType, SRV_SMS_COUNT_RECV);
    VfxWString recv_str;
    recv_str.format("%d", recv);
    ((VappClogUsageCell *)m_form->getItem(ID_SMS_MONTHLY_RECEIVE))->setHintText(recv_str);
}
#endif /* __MMI_CLOG_SMS_COUNT__ */


#ifdef __MMI_CLOG_CALL_TIME__

void VappClogUsagePage::createCallTimeForm()
{
    m_form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_CALL_TIME), ID_CT_CAPTION);

    VappClogUsageCell *monthly_out;
    VFX_OBJ_CREATE(monthly_out, VappClogUsageCell, m_form);
    monthly_out->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_CT_MONTHLY_OUTGOING));
    monthly_out->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(monthly_out, ID_CT_MONTHLY_OUTGOING);

    VappClogUsageCell *monthly_in;
    VFX_OBJ_CREATE(monthly_in, VappClogUsageCell, m_form);
    monthly_in->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_CT_MONTHLY_INCOMING));
    monthly_in->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(monthly_in, ID_CT_MONTHLY_INCOMING);
}


void VappClogUsagePage::getCallTimeData()
{
    srv_clog_ctime_data_struct data;
    srv_clog_ctime_get_data(m_simID, SRV_CLOG_CALL_TYPE_ALL, SRV_CLOG_CTIME_OP_TYPE_SINGLE, &data, 1);

    VappCLogUtils utils;
    
    VfxWString out_str;
    utils.convertUTC2Duration(data.total_dialed, out_str, 0);
    ((VappClogUsageCell *)m_form->getItem(ID_CT_MONTHLY_OUTGOING))->setHintText(out_str);

    VfxWString in_str;
    utils.convertUTC2Duration(data.total_recved, in_str, 0);
    ((VappClogUsageCell *)m_form->getItem(ID_CT_MONTHLY_INCOMING))->setHintText(in_str);
}
#endif /* __MMI_CLOG_CALL_TIME__ */


#ifdef __MMI_CLOG_CALL_COST__

void VappClogUsagePage::createCallCostForm()
{
    if(!srv_nw_usab_is_usable(m_simID))
        return;
    
    m_form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_CALL_COST), ID_CC_CAPTION);

    VappClogUsageCell *last_call_cost;
    VFX_OBJ_CREATE(last_call_cost, VappClogUsageCell, m_form);
    last_call_cost->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_LAST_CALL_COST));
    last_call_cost->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(last_call_cost, ID_CC_LAST_CALL_COST);

    VappClogUsageCell *total_cost;
    VFX_OBJ_CREATE(total_cost, VappClogUsageCell, m_form);
    total_cost->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_TOTAL_COST));
    total_cost->setHintText(VFX_WSTR_EMPTY);
    m_form->addItem(total_cost, ID_CC_TOTAL_COST);

    VcpFormItemLauncherCell *clear_total_cost;
    VFX_OBJ_CREATE(clear_total_cost, VcpFormItemLauncherCell, m_form);
    clear_total_cost->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_CLEAR_COST));
    clear_total_cost->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    clear_total_cost->m_signalTap.connect(this, &VappClogUsagePage::onFormClick);
    m_form->addItem(clear_total_cost, ID_CC_CLEAR_COST);

    VcpFormItemLauncherCell *set_max_cost;
    VFX_OBJ_CREATE(set_max_cost, VcpFormItemLauncherCell, m_form);
    set_max_cost->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_MAX_COST));
    set_max_cost->setHintText(VFX_WSTR_EMPTY);
    set_max_cost->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    set_max_cost->m_signalTap.connect(this, &VappClogUsagePage::onFormClick);
    m_form->addItem(set_max_cost, ID_CC_SET_MAX_COST);

    VcpFormItemLauncherCell *set_ppu;
    VFX_OBJ_CREATE(set_ppu, VcpFormItemLauncherCell, m_form);
    set_ppu->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_PPU));
    set_ppu->setHintText(VFX_WSTR_EMPTY);
    set_ppu->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    set_ppu->m_signalTap.connect(this, &VappClogUsagePage::onFormClick);
    m_form->addItem(set_ppu, ID_CC_SET_PPU);
}


void VappClogUsagePage::getCallCostData()
{
    if(!srv_nw_usab_is_usable(m_simID))
        return;
    
    //Todo, Add Trace here
    srv_clog_ccost_get_data(m_simID, SRV_CLOG_CCOST_FIELD_ALL, (void *)this, getCallCostDataCbk);
}


VfxS32 VappClogUsagePage::getCallCostDataCbk(void *user_data, mmi_sim_enum sim_id, U32 fields,
                                     const srv_clog_ccost_data_struct *data, MMI_BOOL more, srv_clog_ret_enum ret)
{
    VappClogUsagePage *ccItem = (VappClogUsagePage *)user_data;
    if (VFX_FALSE == ccItem->isValid())
        return SRV_CLOG_RET_OK;
        
    if (ret == SRV_CLOG_RET_OK)
    {
        VfxWString last_cost;
        last_cost.format("%d", data->last);
        if ((data->last % 1000) != 0)
            last_cost.format("%u.%u", data->last / 1000, data->last % 1000);
        else
            last_cost.format("%u", data->last / 1000);

        ((VappClogUsageCell *)ccItem->m_form->getItem(ID_CC_LAST_CALL_COST))->setHintText(last_cost);

        VfxWString total_cost;
        total_cost.format("%d", data->total);
        ((VappClogUsageCell *)ccItem->m_form->getItem(ID_CC_TOTAL_COST))->setHintText(total_cost);

        VfxWString max_cost;
        max_cost.format("%d", data->max);
        ccItem->m_maxCost = data->max;
        ((VcpFormItemLauncherCell *)ccItem->m_form->getItem(ID_CC_SET_MAX_COST))->setHintText(max_cost);

        VfxWString ppu;
        vfx_sys_wcscpy(ccItem->m_price, (const VfxWChar *)data->ppu);
        vfx_sys_wcscpy(ccItem->m_unit, (const VfxWChar *)data->currency);
        ppu = VFX_WSTR_MEM(data->ppu);
        if (data->currency[0] != 0)
        {
            ppu += VFX_WSTR(" ");
            ppu += VFX_WSTR_MEM(data->currency);
        }
        ((VcpFormItemLauncherCell *)ccItem->m_form->getItem(ID_CC_SET_PPU))->setHintText(ppu);
    }
    else // get data fial, will remove callcost item if already exist
    {
        if( NULL != ccItem->m_form->getItem(ID_CC_CAPTION))
        {
            ccItem->m_form->removeItem(ID_CC_CAPTION);
            ccItem->m_form->removeItem(ID_CC_LAST_CALL_COST);
            ccItem->m_form->removeItem(ID_CC_TOTAL_COST);
            ccItem->m_form->removeItem(ID_CC_CLEAR_COST);
            ccItem->m_form->removeItem(ID_CC_SET_MAX_COST);
            ccItem->m_form->removeItem(ID_CC_SET_PPU);
        }
    }
	return SRV_CLOG_RET_OK;
}


void VappClogUsagePage::onCCPassPin2Cb()
{
    if (VFX_FALSE == isValid())
        return;
        
    if (ID_CC_CLEAR_COST == m_focusFormCellId)
    {
    }
    else if (ID_CC_SET_MAX_COST == m_focusFormCellId)
    {
        VappClogUsageCCMaxPage *ccMax;
        VFX_OBJ_CREATE_EX(ccMax, VappClogUsageCCMaxPage, getMainScr(), (m_simID, m_maxCost));
        getMainScr()->pushPage(0, ccMax);
    }
    else if (ID_CC_SET_PPU == m_focusFormCellId)
    {
        VappClogUsageCCPPUPage *ccPPU;
        VFX_OBJ_CREATE_EX(ccPPU, VappClogUsageCCPPUPage, getMainScr(), (m_simID, m_price, m_unit));
        getMainScr()->pushPage(0, ccPPU);
    }
}

#endif /* __MMI_CLOG_CALL_COST__ */


void VappClogUsagePage::onFormClick(VcpFormItemCell* cell, VfxId cell_id)
{
    m_focusFormCellId = cell_id;
    switch (cell_id)
    {
    #ifdef __MMI_CLOG_CALL_COST__
        case ID_CC_CLEAR_COST:
        case ID_CC_SET_MAX_COST:
        case ID_CC_SET_PPU:
        {
            if(!srv_nw_usab_is_usable(m_simID))
            {
                VcpConfirmPopup *cnfPopup;
                VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, this);                    
                cnfPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                cnfPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
                cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                cnfPopup->show(VFX_TRUE);
                return;
            }
            mmi_sim_enum sim;
            if (srv_sim_ctrl_pwd_is_enabled(m_simID, SRV_SIM_CTRL_PWD_TYPE_CHV2))
            {
                sim = m_simID;
            }
            else
            {
                onCCPassPin2Cb();
                return;
            }
            mmi_id pin2_cui = vcui_verify_create(getApp()->getGroupId(), VCUI_VERIFY_TYPE_CHV2);
            vcui_verify_set_sim(pin2_cui, sim);
            vcui_verify_run(pin2_cui);
            vfxSetCuiCallerScr(pin2_cui, getMainScr());//VfxAppScr * scr
            break;
        }
    #endif /* __MMI_CLOG_CALL_COST__ */
    
        default :
            break;
    }
    
}


mmi_ret VappClogUsagePage::onProc(mmi_event_struct *evt)
{
    mmi_ret result = MMI_RET_OK;
    
    switch (evt->evt_id)
    {
    #ifdef __MMI_CLOG_CALL_COST__    
        /* PIN2 input screen event start */
        case EVT_ID_VCUI_VERIFY_RESULT:
        {
            vcui_verify_result_evt_struct *result_evt;
            result_evt = (vcui_verify_result_evt_struct*) evt;
        
            if (result_evt->success)
            {
                onCCPassPin2Cb();
            }            
            vcui_verify_close(result_evt->sender_id);
            break;
        }
        case EVT_ID_VCUI_VERIFY_CANCEL:
        case EVT_ID_VCUI_VERIFY_PASSIVE_CLOSING:
        {
            vcui_verify_close(((mmi_group_event_struct*) evt)->sender_id);
            break;
        }
    #endif /* __MMI_CLOG_CALL_COST__ */

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }
	return result;
}
#endif

#ifdef __MMI_CLOG_CALL_COST__

/*****************************************************************************
* Class VappClogUsageCCMaxPage
*****************************************************************************/ 
VappClogUsageCCMaxPage::VappClogUsageCCMaxPage() :
    m_form(NULL),
    m_simID(MMI_SIM1),
    m_maxCost(0)
{
}


VappClogUsageCCMaxPage::VappClogUsageCCMaxPage(mmi_sim_enum simID, VfxU32 maxCost) :
    m_form(NULL),
    m_simID(simID),
    m_maxCost(maxCost)
{
}


void VappClogUsageCCMaxPage::onInit()
{
    VfxPage::onInit(); // call base class

    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_MAX_COST));    // set title text
    setTopBar(titleBar);

    // create bottom bar
    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem('Save', VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem('Canc', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappClogUsageCCMaxPage::onToolBarClick);
    setBottomBar(toolBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    VcpFormItemTextInput *value;
    VFX_OBJ_CREATE(value, VcpFormItemTextInput, m_form);
    //VfxWString max_str;
    //max_str.format("%d", m_maxCost);
    //value->setText(max_str);
    VfxWChar inputBuf[MAX_COST_STR_LENGTH + 1];
    kal_wsprintf((WCHAR *)inputBuf, "%d", m_maxCost);
    value->getTextBox()->setText(inputBuf, MAX_COST_STR_LENGTH);
    value->getTextBox()->setIME(IMM_INPUT_TYPE_NUMERIC);
    value->getTextBox()->setAutoActivated(VFX_TRUE);
    value->getTextBox()->setAutoDeactivated(VFX_TRUE);
    m_form->addItem(value, 'VALU');

    VcpFunctionBar *m_funcBar;
    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem('Save', VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_funcBar->setItemSpecial('Save');
	m_funcBar->m_signalButtonTap.connect(this,&VappClogUsageCCMaxPage::onToolBarClick);
    value->getTextBox()->setFunctionBar(m_funcBar);    
}


void VappClogUsageCCMaxPage::onToolBarClick(VfxObject* sender, VfxId btnID)
{
    switch (btnID)
    {
        case 'Save':
            saveCCMax();
            break;

        case 'Canc':
            getMainScr()->popPage();
            break;

        default :
            break;
    }
}


void VappClogUsageCCMaxPage::saveCCMax()
{
    VcpFormItemTextInput *value = 
        (VcpFormItemTextInput *)(m_form->getItem('VALU'));
    VfxBool is_valid_input = VFX_TRUE;
    VfxU32 int_max;
    
    VfxChar char_max[MAX_COST_STR_LENGTH + 1];
    mmi_ucs2_to_asc(char_max, (VfxChar *)value->getTextBox()->getText());

    if (char_max[0] == 0) // means length is 0, input nothing
        is_valid_input = VFX_FALSE;
    else
    {
        int_max = atoi((CHAR *)char_max);
        if (int_max > MAX_COST_VALUE)
            is_valid_input = VFX_FALSE;
    }

    if (is_valid_input == VFX_FALSE)// popup invalid input
    {
        VcpFormItemTextInput *ccmax;
        ccmax = (VcpFormItemTextInput *)m_form->getItem('VALU');
        ccmax->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_INVALID_INPUT));
        return;
    }
    else // save hdlr
    {
        srv_clog_ccost_data_struct req_data;
        req_data.max = int_max;
        srv_clog_ccost_set_data(
            m_simID,
            (U32) SRV_CLOG_CCOST_FIELD_MAX,
            (const srv_clog_ccost_data_struct *) &req_data,
            NULL,
            (const void *) this,
            saveCCMaxCbk);
    }
}


VfxS32 VappClogUsageCCMaxPage::saveCCMaxCbk(void *user_data,
            mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret)
{
    VappClogUsageCCMaxPage *obj = (VappClogUsageCCMaxPage *)user_data;
    if (VFX_FALSE == obj->isValid())
        return SRV_CLOG_RET_OK;

    if (ret != SRV_CLOG_RET_OK)
    {        
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(
            VCP_INFO_BALLOON_TYPE_FAILURE,
            VFX_WSTR_RES(STR_GLOBAL_UNFINISHED));
    }
    obj->getMainScr()->popPage();

	return SRV_CLOG_RET_OK;
}


/*****************************************************************************
* Class VappClogUsageCCPPUPage
*****************************************************************************/ 
VappClogUsageCCPPUPage::VappClogUsageCCPPUPage(mmi_sim_enum simID, 
    VfxWChar *price, VfxWChar *unit) :
    m_form(NULL),
    m_simID(simID),
    m_price(price),
    m_unit(unit)
{
}

void VappClogUsageCCPPUPage::onInit()
{
    VfxPage::onInit(); // call base class

    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_PPU));    // set title text
    setTopBar(titleBar);

    // create bottom bar
    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem('Save', VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem('Canc', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappClogUsageCCPPUPage::onToolBarClick);
    setBottomBar(toolBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_priceCell, VcpFormItemTextInput, m_form);
    m_priceCell->setLabelPosition(VCPFORM_TOP_LEFT);
    m_priceCell->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_PRICE));
    m_priceCell->getTextBox()->setText(m_price, 20);
    m_priceCell->getTextBox()->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC);
    m_priceCell->getTextBox()->setAutoDeactivated(VFX_TRUE);
    m_form->addItem(m_priceCell, 'PRIC');

    VFX_OBJ_CREATE(m_unitCell, VcpFormItemTextInput, m_form);
    m_unitCell->setLabelPosition(VCPFORM_TOP_LEFT);
    m_unitCell->setLabelText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_UNIT));
    m_unitCell->getTextBox()->setText(m_unit, 3);
    m_unitCell->getTextBox()->setIME(IMM_INPUT_TYPE_ENGLISH_SENTENCE);
    m_unitCell->getTextBox()->setAutoDeactivated(VFX_TRUE);
    m_form->addItem(m_unitCell, 'UNIT');

    
    VcpFunctionBar *m_pricefuncBar;
    VFX_OBJ_CREATE(m_pricefuncBar, VcpFunctionBar, this);
    m_pricefuncBar->addItem('Prev', VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_PREV));
    m_pricefuncBar->setDisableItem('Prev', VFX_TRUE);
    m_pricefuncBar->addItem('Next', VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_NEXT));
    m_pricefuncBar->addItem('Save', VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_pricefuncBar->setItemSpecial('Save');
    m_pricefuncBar->m_signalButtonTap.connect(this,&VappClogUsageCCPPUPage::onToolBarClick);
    m_priceCell->getTextBox()->setFunctionBar(m_pricefuncBar);

    VcpFunctionBar *m_unitfuncBar;
    VFX_OBJ_CREATE(m_unitfuncBar, VcpFunctionBar, this);
    m_unitfuncBar->addItem('Prev', VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_PREV));
    m_unitfuncBar->addItem('Next', VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_NEXT));    
    m_unitfuncBar->setDisableItem('Next', VFX_TRUE);
    m_unitfuncBar->addItem('Save', VFX_WSTR_RES(STR_GLOBAL_SAVE));
    m_unitfuncBar->setItemSpecial('Save');
    m_unitfuncBar->m_signalButtonTap.connect(this,&VappClogUsageCCPPUPage::onToolBarClick);
    m_unitCell->getTextBox()->setFunctionBar(m_unitfuncBar);
    
}


void VappClogUsageCCPPUPage::onToolBarClick(VfxObject* sender, VfxId btnID)
{
    switch (btnID)
    {
        case 'Save':
            saveCCPPU();
            break;

        case 'Canc':
            getMainScr()->popPage();
            break;

        case 'Prev':
            m_priceCell->getTextBox()->activate();
            m_unitCell->getTextBox()->deactivate();
            break;

        case 'Next':
            m_priceCell->getTextBox()->deactivate();
            m_unitCell->getTextBox()->activate();
            break;

        default :
            break;
    }
}


void VappClogUsageCCPPUPage::saveCCPPU()
{
    VfxU8 count = 0, num = 0;
    VfxChar temp_ppu[40];
    VfxBool is_valid_str = VFX_TRUE;
    VfxBool is_valid_unit_str = VFX_TRUE;
    VfxChar first_four_digit_ppu[5];
    VfxU32 first_four_digit_value;

    VcpFormItemTextInput *price = 
        (VcpFormItemTextInput *)(m_form->getItem('PRIC'));
    VfxWChar *price_p = price->getTextBox()->getText();

    VcpFormItemTextInput *unit = 
        (VcpFormItemTextInput *)(m_form->getItem('UNIT'));
    VfxWChar *unit_p = unit->getTextBox()->getText();

    VcpFormItemTextInput *price_editor;
    price_editor = (VcpFormItemTextInput *)m_form->getItem('PRIC');    
    VcpFormItemTextInput *unit_editor;
    unit_editor = (VcpFormItemTextInput *)m_form->getItem('UNIT');
    
    mmi_ucs2_to_asc(temp_ppu, (VfxChar *)price_p);

    while (count < 40 && temp_ppu[count] != 0)
    {
        if (temp_ppu[count] <= '9' && temp_ppu[count] >= '0')
        {
            num++;
        }
        if (temp_ppu[count++] == '.')
        {
            break;
        }
    }
    /* overflow */
    if ((count > 11 && num > 11) || count == 0)
    {
        is_valid_str = MMI_FALSE;
    }
    else if (num == 11)
    {
        memset(first_four_digit_ppu, 0x00, 5);
        for (count = 0; count < 4; count++)
        {
            first_four_digit_ppu[count] = temp_ppu[count];
        }
        first_four_digit_value = atoi((CHAR*) first_four_digit_ppu);
        /* according to spec 11.11, max value of first four digit will be 4095 = 2^11 + 2^10 + ... _ 2^0 */
        if (first_four_digit_value > 4095)
        {
            is_valid_str = MMI_FALSE;
        }
    }    
    if (!is_valid_str)
    {        
        price_editor->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_INVALID_INPUT));
    }
    else
    {
        price_editor->setWarningText(VFX_WSTR_EMPTY);
    }

    /* check price unit */
    for (count = 0; count < 3; count++)
    {
        if (unit_p[count] == '\0')
        {
            break;
        }
        if ((unit_p[count] == '.') || (unit_p[count] == ',') ||
            (unit_p[count] == '-') || (unit_p[count] == '?') ||
            (unit_p[count] == '!') || (unit_p[count] == '\'') ||
            (unit_p[count] == '@') || (unit_p[count] == ':') ||
            (unit_p[count] == '#') || (unit_p[count] == '/') ||
            (unit_p[count] == '_') || ((unit_p[count] >= '0') && (unit_p[count] <= '9')))
        {
            is_valid_str = MMI_FALSE;
            is_valid_unit_str = MMI_FALSE;
            break;
        }
    }
    if (!is_valid_unit_str)
    {        
        unit_editor->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_USAGE_INVALID_INPUT));
    }
    else
    {
        unit_editor->setWarningText(VFX_WSTR_EMPTY);
    }

    if (is_valid_str)
    {
        srv_clog_ccost_data_struct req_data;
        vfx_sys_wcscpy(req_data.ppu, price_p);
        vfx_sys_wcscpy(req_data.currency, unit_p);
        srv_clog_ccost_set_data(
            m_simID,
            (U32) SRV_CLOG_CCOST_FIELD_PUC,
            (const srv_clog_ccost_data_struct *) &req_data,
            NULL,
            (const void *) this,
            saveCCPPUCbk);
    }
}


VfxS32 VappClogUsageCCPPUPage::saveCCPPUCbk(void *user_data,
            mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret)
{
    VappClogUsageCCPPUPage *obj = (VappClogUsageCCPPUPage *)user_data;
    if (VFX_FALSE == obj->isValid())
        return SRV_CLOG_RET_OK;

    if (ret != SRV_CLOG_RET_OK)
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(
            VCP_INFO_BALLOON_TYPE_FAILURE,
            VFX_WSTR_RES(STR_GLOBAL_UNFINISHED));
    }
    obj->getMainScr()->popPage();

	return SRV_CLOG_RET_OK;
}

#endif /* __MMI_CLOG_CALL_COST__ */


/***************************************************************************** 
* Class VappClogUsageCell
*****************************************************************************/
VfxBool VappClogUsageCell::onPenInput(VfxPenEvent &event)
{
    // do nothing
    return VfxControl::onPenInput(event);
}


void VappClogUsageCell::onCellTap(VfxPenEvent &event)
{
    // do nothing
}



