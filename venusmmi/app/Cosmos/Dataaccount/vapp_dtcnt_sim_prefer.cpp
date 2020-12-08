/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_dtcnt_sim_prefer.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file define the class to select sim prefer
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
     // vcp control
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_dtcnt_def.h"
#include "mmi_rp_vapp_dtcnt_sim_prefer_def.h"
#include "vapp_dtcnt_sim_prefer.h"
#include "vapp_dtcnt.h"
#include "vtst_rt_main.h"
#include "GlobalResDef.h"
#include "vapp_sim_setting_gprot.h"
#include "mmi_cb_mgr_gprot.h"

extern "C"
{
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "SimCtrlSrvGprot.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "ModeSwitchSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "PnSrvGprot.h"
}


/***************************************************************************** 
 * static function
 *****************************************************************************/

mmi_id vcui_dtcnt_sim_prefer_create(mmi_id parent_gid, void *user_data)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VAPP_DTCNT_SIM_PREFER,
                                        VFX_OBJ_CLASS_INFO(VappDtcntSimPreferApp),
                                        parent_gid,
                                        user_data,
                                        sizeof(user_data));
    return cui_id;
}


void vcui_dtcnt_sim_prefer_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}


/***************************************************************************** 
 * Class VappDtcntSimPreferApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDtcntSimPreferApp", VappDtcntSimPreferApp, VfxCui);

void VappDtcntSimPreferApp::onRun(void * args,VfxU32 argSize)
{   
    VfxCui::onRun(args, argSize);

    VfxMainScrEx *scr;
    VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
    scr->show();
}

void VappDtcntSimPreferApp::onScr1stReady(VfxMainScrEx *scr)
{
    VappDtcntSimPreferPage *page;

    VFX_OBJ_CREATE(page, VappDtcntSimPreferPage, scr);
    scr->pushPageHandler(0, page);
}


/***************************************************************************** 
 * Class VappDtcntSimPreferPage
 *****************************************************************************/

void VappDtcntSimPreferPage::onPageInit(VfxPageEx *page)
{
    VfxPageHandler::onPageInit(page);
    // get currenct sim type
    MMI_BOOL ret;
    ret = srv_dtcnt_get_sim_preference(&m_simType);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, m_simType, ret);
    vapp_dtcnt_set_titlebar(STR_ID_VAPP_DTCNT_SIM_PREFER, page);
 
    VFX_OBJ_CREATE(m_menu, VcpListMenu, page);
    m_menu->setContentProvider(this);
    m_menu->m_signalItemTapped.connect(this, &VappDtcntSimPreferPage::onListItemTapped);
    m_menu->setSize(page->getSize());
    setListMenuFormat(m_menu, VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT, VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VCP_LIST_MENU_CONTROL_MODE_NORMAL);
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntSimPreferPage::onSimChangeEvt);
#endif
}

void VappDtcntSimPreferPage::onListItemTapped(
    VcpListMenu *sender, // Sender
    VfxU32 index        // List item index
)
{
    MMI_BOOL ret;
    VfxU32 simIndex;
    VfxPageEx *page = getPage();
    simIndex = VappDtcntSimAvailableInfo::getAvailableSimIndex(index);
    if (m_simType == (srv_dtcnt_sim_type_enum)(simIndex + SRV_DTCNT_SIM_TYPE_1))
    {
        page->getMainScr()->popPage();
        return;
    }
    else
    {
        // check any account in use
        VfxU32 num = 0;
        AccountInUseNum(num);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ACCT_IN_USE, num);
        if (num > 1)
        {
            // popup
            showAcctInUseConfirm();
            return;
        }
        else if(num == 1)
        {
#ifdef __MMI_PNS__        
            if(srv_pns_force_close_connection(&VappDtcntSimPreferPage::updatePage, getObjHandle()) == MMI_TRUE)
            {
                //show popup
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ACCT_WAITING_CLOSE_CONN);
                m_simType = (srv_dtcnt_sim_type_enum)(simIndex + SRV_DTCNT_SIM_TYPE_1);
                VcpIndicatorPopup *waitingPopup;
                VFX_OBJ_CREATE(waitingPopup, VcpIndicatorPopup, page);
                waitingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
                waitingPopup->setText(STR_ID_VAPP_DTCNT_SWITCHING);
                waitingPopup->show(VFX_TRUE);
                m_indicatorPopupPtr = waitingPopup;
            }
            else
#endif /* #ifdef __MMI_PNS__ */                
            {
                showAcctInUseConfirm();
                return;
            }
        }
        else
        {
            ret = srv_dtcnt_set_sim_preference((srv_dtcnt_sim_type_enum)(simIndex + SRV_DTCNT_SIM_TYPE_1));
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_SET_SIM_PREFERENCE, (simIndex + 1), ret);

            mmi_group_event_struct event;
            page->getMainScr()->getApp()->sendToCaller(&event);
            //VappDtcntAcctValidity::syncInvalidInfowithSrv();
            page->getMainScr()->popPage();
            return;
        }
    }
}


void VappDtcntSimPreferPage::showAcctInUseConfirm()
{
    VcpConfirmPopup *confirmPopup;                
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getPage());
    confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    VfxWString str1, str2;
    str1 = getSimName((VfxU32)(m_simType - 1));
    str1 += str2.loadFromRes(STR_ID_VAPP_DTCNT_SIM_PREFER_NOT_ALLOW_CHANGED);
    confirmPopup->setText(str1);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_FALSE);
    confirmPopup->show(VFX_FALSE);                
    confirmPopup->m_signalButtonClicked.connect(this, &VappDtcntSimPreferPage::onNotChangedConfirm);
}

#ifdef __MMI_PNS__
mmi_ret VappDtcntSimPreferPage::updatePage(mmi_event_struct *evt)
{
    srv_pns_force_close_rsp_event_struct *closedEvt = 
        (srv_pns_force_close_rsp_event_struct *)evt;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ACCT_CLOSE_CONN_CB, closedEvt->error);
    VappDtcntSimPreferPage *simPreferPage = 
        (VappDtcntSimPreferPage*)VfxObject::handleToObject((VfxObjHandle)closedEvt->user_data);

    if (simPreferPage)
    {
        if(simPreferPage->m_indicatorPopupPtr.isValid())
        {
            VFX_OBJ_CLOSE(simPreferPage->m_indicatorPopupPtr);
        }
        if(simPreferPage->isAnyAccountInUse())
        {
            //show popup
            simPreferPage->showAcctInUseConfirm();
        }
        else
        {
            MMI_BOOL ret;
            ret = srv_dtcnt_set_sim_preference(simPreferPage->m_simType);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_SET_SIM_PREFERENCE, (simPreferPage->m_simType), ret);
            VfxMainScr *mainScr = simPreferPage->getPage()->getMainScr();
                
            mmi_group_event_struct event;
            mainScr->getApp()->sendToCaller(&event);
            mainScr->popPage();            
        }
    }
    srv_pns_resume_connection();
    return MMI_OK;
}
#endif  


void VappDtcntSimPreferPage::onNotChangedConfirm(
    VfxObject* sender,     // sender 
    VfxId id          // id
) 
{
    getPage()->getMainScr()->popPage();
}


VfxBool VappDtcntSimPreferPage::isAnyAccountInUse()
{
    VfxU32 acctNum, i;    
    acctNum = VappDtcntDispItemList::getAcctNum();
    VappDtcntDispItem* dispItem;
    VfxU32 acctId;
    for (i = 0; i < acctNum; i++)
    {
        dispItem = VappDtcntDispItemList::getAccountItem(i);
        acctId = dispItem->getProfileId();
        if (VappDtcntDispItemList::isAccountInUse(acctId))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


void VappDtcntSimPreferPage::AccountInUseNum(VfxU32 &num)
{
    num = 0;
    VfxU32 acctNum, i;    
    acctNum = VappDtcntDispItemList::getAcctNum();
    VappDtcntDispItem* dispItem;
    VfxU32 acctId;
    for (i = 0; i < acctNum; i++)
    {
        dispItem = VappDtcntDispItemList::getAccountItem(i);
        acctId = dispItem->getProfileId();
        if (VappDtcntDispItemList::isAccountInUse(acctId))
        {
            num++;
        }
    }
}


VfxWString VappDtcntSimPreferPage::getSimName(VfxU32 simIndex)
{
    VfxWString str;
    VfxU16 resIdTable[4] = {STR_GLOBAL_SIM_1, STR_GLOBAL_SIM_2,
                            STR_GLOBAL_SIM_3, STR_GLOBAL_SIM_4};
    VfxU16 resId = resIdTable[simIndex];
    str.loadFromRes(resId);
    return str;
}


VfxBool VappDtcntSimPreferPage::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    VfxWString str;
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        mmi_sim_enum simEnum = MMI_SIM1;
        simEnum = VappDtcntSimAvailableInfo::getAvailableSimEnum(index);
        text = vapp_sim_settings_get_sim_name_with_sim_id(simEnum);
    }
    return VFX_TRUE;
}


VfxU32 VappDtcntSimPreferPage::getCount() const
{
    return VappDtcntSimAvailableInfo::getAvailableSimNum();
}


VcpListMenuItemStateEnum VappDtcntSimPreferPage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
    MMI_BOOL ret;
    ret = srv_dtcnt_get_sim_preference(&simType);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, simType, ret);
    
    VfxU32 simIndex;
    simIndex = VappDtcntSimAvailableInfo::getAvailableSimIndex(index);
    if (simType == (SRV_DTCNT_SIM_TYPE_1 + simIndex))
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
    
    
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntSimPreferPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
    VfxU32 availSim;
    availSim = VappDtcntSimAvailableInfo::getAvailableSimNum();
	
    if(availSim > 1)
    {
	m_menu->resetAllItems();
    }
    else
    {
        getPage()->getMainScr()->closePage(getPage()->getId());
    }
}
#endif

// setting framework
/***************************************************************************** 
 * Class VappDtcntSimPreferCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDtcntSimPreferCell", VappDtcntSimPreferCell, VcpFormItemLauncherCell);

void VappDtcntSimPreferCell::onInit()
{
    VcpFormItemLauncherCell::onInit();

    setMainText(STR_ID_VAPP_DTCNT_SIM_PREFER);
    srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
    srv_dtcnt_get_sim_preference(&simType);
    setHintText(VappDtcntDispItemList::getSimName((VfxU32)(simType -1)));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappDtcntSimPreferCell::onTap);
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntSimPreferCell::onSimChangeEvt);	
#endif
}


void VappDtcntSimPreferCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VfxMainScr *mainScr;
    mmi_id cuiId;
    mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
    {
        VfxApp *app = mainScr->getApp();
        cuiId = vcui_dtcnt_sim_prefer_create(app->getGroupId(), NULL);
        mmi_frm_group_set_caller_proc(
            cuiId, 
            &VappDtcntSimPreferCell::staticSimPreferProc, 
            (void*)this);
        vcui_dtcnt_sim_prefer_run(cuiId);
    }
}


void VappDtcntSimPreferCell::updateCell()
{
    srv_dtcnt_sim_type_enum simType;
    srv_dtcnt_get_sim_preference(&simType);
	
    VfxWString str;
    str = VappDtcntDispItemList::getSimName((VfxU32)(simType -1));
    setHintText(str);
}


mmi_ret VappDtcntSimPreferCell::staticSimPreferProc(mmi_event_struct *evt)
{
    VappDtcntSimPreferCell *simPreferCell = (VappDtcntSimPreferCell*)evt->user_data;
    simPreferCell->updateCell();
    return MMI_RET_OK;
}


VfxBool VappDtcntSimPreferCell::isSimPreferCellHideHdlr()
{
    VfxU32 availSim;
    availSim = VappDtcntSimAvailableInfo::getAvailableSimNum();
    if (availSim > 1)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntSimPreferCell::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
    if(VFX_FALSE == flag)//remove sim
    {
	updateCell();
    }
    if(2 > VappDtcntSimAvailableInfo::getAvailableSimNum())
    {
	setIsHidden(VFX_TRUE);
    }
    else
    {
	setIsHidden(VFX_FALSE);
    }
}
#endif


#endif
