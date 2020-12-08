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
 *  vapp_dtcnt_select_cui.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file define the class to select dtcnt
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

#include "vapp_dtcnt_select_cui.h"
#include "vapp_dtcnt_def.h"
#include "vapp_dtcnt_gprot.h"

#include "vapp_dtcnt.h"
#include "vcp_menu_popup.h"

extern "C"
{
#include "abm_api.h"
#include "cbm_api.h"
#include "SimCtrlSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
}
#include "mmi_rp_vapp_dtcnt_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "GlobalResDef.h"
#include "mmi_frm_utility_gprot.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/***************************************************************************** 
 * Class VappDtcntSelectCfmPop
 *****************************************************************************/

#define VAPP_DTCNT_SELECT_CFM_POP_BACK 'BKEY'
VfxBool VappDtcntSelectCfmPop::onKeyInput(VfxKeyEvent & event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        m_signalButtonClicked.emit(this, VAPP_DTCNT_SELECT_CFM_POP_BACK);
        return VFX_TRUE;
    }

    return VcpConfirmPopup::onKeyInput(event);
}


/***************************************************************************** 
 * Class VappDtcntSelectParam
 *****************************************************************************/

VappDtcntSelectParam::VappDtcntSelectParam() :
    m_bearers(DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS),
    m_appId(0),
    m_options(CUI_DTCNT_SELECT_DEFAULT),
    m_simSelection(CUI_DTCNT_SELECT_SIM_ALL),
    m_selectType(CUI_DTCNT_SELECT_TYPE_NORMAL)
{
    VfxU32 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        m_simAccountId[i] = VAPP_DTCNT_AUTOMATIC_ID;
    }
}


void VappDtcntSelectParam::onInit()
{
    VfxObject::onInit();
}


void VappDtcntSelectParam::onDeinit()
{
    VfxObject::onDeinit();
}


/***************************************************************************** 
 * Class VappDtcntSelect
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDtcntSelect", VappDtcntSelect, VfxCui);

void VappDtcntSelect::onRun(void * arg,VfxU32 argSize)
{   
    VFX_OBJ_CREATE_EX(m_scr, VappDtcntSelectScr, this, (m_groupId));
    m_scr->show();
}

mmi_ret VappDtcntSelect::onProc(mmi_event_struct * evt)
{
    return MMI_RET_OK;
}

VfxAppCloseAnswerEnum VappDtcntSelect::onProcessClose(VfxAppCloseOption options)
{
    VFX_UNUSED(options);
    cui_dtcnt_select_event_result_struct evt;
    MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_CLOSE, m_groupId);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, m_groupId);
    sendToCaller((mmi_group_event_struct*)&evt);
    return VFX_APP_CLOSE_ANSWER_YES;
}

void VappDtcntSelect::createDtcntParamObject()
{
    VFX_OBJ_CREATE(m_param, VappDtcntSelectParam, this);
}

void VappDtcntSelect::onInit()
{
    VfxCui::onInit();
}


void VappDtcntSelect::onDeinit()
{
    VfxCui::onDeinit();
}

/***************************************************************************** 
 * Class VappDtcntSelectPage
 *****************************************************************************/

void VappDtcntSelectPage::onInit()
{
    VfxPage::onInit();

    VfxU32 simIndex;
    simIndex = mmi_frm_sim_to_index(m_sim);
    if (m_scrPageNum == 1)
    {
	vapp_dtcnt_set_titlebar(STR_GLOBAL_DATA_CONN_SETTING, this);
    }
    else
    {
       	vapp_dtcnt_set_titlebar(VappDtcntDispItemList::getSimName((VfxU32)(simIndex)), this);
    }
    
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &VappDtcntSelectPage::onItemTapped);
    m_listMenu->setSize(getSize());
    setListMenuFormat(m_listMenu, VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT, VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VCP_LIST_MENU_CONTROL_MODE_NORMAL);

    VfxU32 acctId;
    acctId = m_dispContext->getSimAccountId(simIndex);
    acctId = getRealAccountId(acctId);
    kal_bool isAlwaysAsk;
    VfxU32 oriAcctId;
    cbm_decode_data_account_id(acctId, NULL, NULL, &isAlwaysAsk, (kal_uint32*)&oriAcctId);
    VappDtcntSelectItemInfo *itemInfo;
    VfxU32 index, acctNum;
    acctNum = m_dispContext->getListItemNumber();
    VfxBool flag = VFX_FALSE;
    for (index = 0; index < acctNum; index++)
    {
        itemInfo = m_dispContext->getListInfo(index);    
        switch (itemInfo->getItemType())
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_CBM_ALWAYS_ASK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #endif
            case VAPP_DTCNT_SELECT_ITEM_CSD:
            case VAPP_DTCNT_SELECT_ITEM_GPRS:
                if (oriAcctId == itemInfo->getProfileId() && !isAlwaysAsk)
                {
                    flag = VFX_TRUE;
                }
                break;
        }
        if (flag)
        {
            m_currIndex = index;
            break;
        }
    }
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntSelectPage::onSimChangeEvt);
#endif
}

void VappDtcntSelectPage::onBack()
{
    if (m_scrPageNum == 1)
    {
        // single select cui post evt when select item
        VappDtcntSelectScr *mainScr;
        mainScr = (VappDtcntSelectScr*)getMainScr();
        cui_dtcnt_select_event_result_struct evt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL, mainScr->getCuiId());
        VappDtcntSelect *dtcntSelectInstance;
        dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(mainScr->getCuiId()); // get cui instance
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, mainScr->getCuiId());
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&evt);
    }
    else
    {
        getMainScr()->popPage();
    }
}

void VappDtcntSelectPage::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
        VappDtcntSelectScr *mainScr;
        mainScr = (VappDtcntSelectScr*)getMainScr(); // get Main screen
        mmi_id cuiId;
        cuiId = mainScr->getCuiId(); // get group id
        VappDtcntSelect *dtcntSelectInstance;
        VappDtcntSelectParam *dtcntSelectParam;
        dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cuiId); // get cui instance
        dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI
        VfxU32 acctId;
        kal_bool isAlwaysAsk;
        VfxU32 oriAcctId;
        VfxU8 appId;
        VfxU32 simIndex;
        simIndex = mmi_frm_sim_to_index(m_sim);
        m_dispContext->prepareListInfo(
            dtcntSelectParam,
            m_sim,
            VFX_TRUE);
        acctId = m_dispContext->getSimAccountId(simIndex);
        //change to Automatic if change to CSD but app don't support CSD:
        cbm_decode_data_account_id(acctId, NULL, &appId, &isAlwaysAsk, (kal_uint32*)&oriAcctId);
        if (!isAlwaysAsk && (oriAcctId != CBM_DEFAULT_ACCT_ID))
        {
            srv_dtcnt_bearer_enum bearer = srv_dtcnt_get_bearer_type(oriAcctId, SRV_DTCNT_ACCOUNT_PRIMARY);
            if (bearer == SRV_DTCNT_BEARER_CSD && 
                !(dtcntSelectParam->getBearers() & DATA_ACCOUNT_BEARER_CSD))
            {
                acctId = cbm_encode_data_account_id(
                                 CBM_DEFAULT_ACCT_ID,
                                 (cbm_sim_id_enum)simIndex, 
                                 appId, 
                                 KAL_FALSE);
                m_dispContext->setSimAccountId(simIndex, acctId);
            }
        }
        acctId = getRealAccountId(acctId);
        cbm_decode_data_account_id(acctId, NULL, NULL, &isAlwaysAsk, (kal_uint32*)&oriAcctId);
        VappDtcntSelectItemInfo *itemInfo;
        VfxU32 index, acctNum;
        acctNum = m_dispContext->getListItemNumber();
        VfxBool flag = VFX_FALSE;
        for (index = 0; index < acctNum; index++)
        {
            itemInfo = m_dispContext->getListInfo(index);    
            switch (itemInfo->getItemType())
            {
                case VAPP_DTCNT_SELECT_ITEM_CSD:
                case VAPP_DTCNT_SELECT_ITEM_GPRS:
                    if (oriAcctId == itemInfo->getProfileId() && !isAlwaysAsk)
                    {
                        flag = VFX_TRUE;
                    }
                    break;
            }
            if (flag)
            {
                m_currIndex = index;
                break;
            }
        }
        m_listMenu->updateAllItems();
        m_listMenu->setVisibleMenuItem(m_currIndex);
    }
    else
    {
        m_listMenu->setVisibleMenuItem(m_currIndex);
    }
    return;
}


void VappDtcntSelectPage::onDeinit()
{
    VfxPage::onDeinit();
}


void VappDtcntSelectPage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{   
    m_dispContext->setSelectedFlag(VFX_TRUE); // any time tapped this flag change to vfx_true
    VappDtcntSelectScr *mainScr;
    mainScr = (VappDtcntSelectScr*)getMainScr();
    mmi_id cuiId;
    cuiId = mainScr->getCuiId(); // get group id
    VappDtcntSelect *dtcntSelectInstance;
    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cuiId); // get cui instance
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI

    // one encode account need appId, sim id, always ask info and pure account id
    VfxU8 appId = dtcntSelectParam->getAppId();
    cbm_sim_id_enum cbmSimId;
    VfxU32 simIndex;
    simIndex = mmi_frm_sim_to_index(m_sim);
    cbmSimId = (cbm_sim_id_enum)simIndex;

    VfxBool isAlwaysAsk = VFX_FALSE;
    VfxU32 acctId = CBM_INVALID_NWK_ACCT_ID;
    
    VappDtcntSelectItemInfo *listInfo;
    listInfo = m_dispContext->getListInfo(index);
    switch(listInfo->getItemType())
    {
        case VAPP_DTCNT_SELECT_ITEM_CSD:
        case VAPP_DTCNT_SELECT_ITEM_GPRS:
            acctId = listInfo->getProfileId();
            break;
    }

    VfxU32 encodeAccountId;
    encodeAccountId = cbm_encode_data_account_id(acctId, cbmSimId, appId, (kal_bool)isAlwaysAsk);

    if (m_scrPageNum == 1)
    {
        // single select cui post evt when select item
        cui_dtcnt_select_event_any_sim_selected_struct evt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED, mainScr->getCuiId());

        evt.selectSim = (cui_dtcnt_sim_enum)simIndex;
        evt.accountId = encodeAccountId;
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITH_ACCOUNT_ID, 
            mainScr->getCuiId(),
            evt.selectSim,
            evt.accountId);
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&evt);

        cui_dtcnt_select_event_result_struct resultEvt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&resultEvt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, mainScr->getCuiId());
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, mainScr->getCuiId());
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&resultEvt);
    }
    else
    {
        // dual sim select cui update first and second account id
        m_dispContext->setSimAccountId(simIndex, encodeAccountId);

        // send CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED evt
        cui_dtcnt_select_event_any_sim_selected_struct evt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED, mainScr->getCuiId());

        evt.selectSim = (cui_dtcnt_sim_enum)simIndex;
        evt.accountId = encodeAccountId;
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITH_ACCOUNT_ID, 
            mainScr->getCuiId(),
            evt.selectSim,
            evt.accountId);
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&evt);
        getMainScr()->popPage();
    }
}


VfxBool VappDtcntSelectPage::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    VappDtcntSelectItemInfo *itemInfo;
    itemInfo = m_dispContext->getListInfo(index);
    if (itemInfo->getItemType() != VAPP_DTCNT_SELECT_ITEM_CSD && 
        itemInfo->getItemType() != VAPP_DTCNT_SELECT_ITEM_GPRS)
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            VfxWString str;
            text = str.loadFromRes((VfxResId)(itemInfo->getItemStrId()));
        }
    }
    else
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text.loadFromMem(itemInfo->getName());
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            text.loadFromMem(itemInfo->getAddress());
        }
    }
    return VFX_TRUE;
}

VfxBool VappDtcntSelectPage::getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    text.loadFromRes(STR_ID_VAPP_DTCNT_EMPTY_LIST);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}


VcpListMenuItemStateEnum VappDtcntSelectPage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const 
{
    VappDtcntSelectItemInfo *itemInfo;
    itemInfo = m_dispContext->getListInfo(index);
    VfxU32 acctId;
    VfxU32 simIndex;
    simIndex = mmi_frm_sim_to_index(m_sim);
    acctId = m_dispContext->getSimAccountId(simIndex);
    acctId = getRealAccountId(acctId);

    kal_bool isAlwaysAsk;
    VfxU32 oriAcctId;
    cbm_decode_data_account_id(acctId, NULL, NULL, &isAlwaysAsk, (kal_uint32*)&oriAcctId);
    switch (itemInfo->getItemType())
    {
        case VAPP_DTCNT_SELECT_ITEM_CSD:
        case VAPP_DTCNT_SELECT_ITEM_GPRS:
            if (oriAcctId == itemInfo->getProfileId() && !isAlwaysAsk)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            break;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


VcpListMenuCellClientBaseFrame *VappDtcntSelectPage::getItemCustomContentFrame(
    VfxU32 index,        // [IN] index of the item
    VfxFrame *parentFrame // [IN] parent frame of the custom content frame
    )
{
    VappDtcntSelectItemInfo *itemInfo;
    itemInfo = m_dispContext->getListInfo(index);
    if (itemInfo->getItemType() != VAPP_DTCNT_SELECT_ITEM_CSD &&
        itemInfo->getItemType() != VAPP_DTCNT_SELECT_ITEM_GPRS)
    {
        VcpListMenuCellSingleTextFrame *singleTextFrame;
        VFX_OBJ_CREATE(singleTextFrame, VcpListMenuCellSingleTextFrame, parentFrame);
        return singleTextFrame;
    }
    return NULL;
}

VfxU32 VappDtcntSelectPage::getCount() const
{
    return m_dispContext->getListItemNumber();
}


VfxU32 VappDtcntSelectPage::getRealAccountId(VfxU32 acctId) const
{
    VappDtcntSelectScr *mainScr;
    mainScr = (VappDtcntSelectScr*)getMainScr();
    mmi_id cuiId;
    cuiId = mainScr->getCuiId(); // get group id
    VappDtcntSelect *dtcntSelectInstance;
    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cuiId); // get cui instance
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI
    // one encode account need appId, sim id, always ask info and pure account id
    VfxU8 appId = dtcntSelectParam->getAppId();
    cbm_sim_id_enum simId = CBM_SIM_ID_SIM1;
    simId = (cbm_sim_id_enum)mmi_frm_sim_to_index(m_sim);

    VfxU32 encodeAcctId, outAcctId;
    encodeAcctId = cbm_encode_data_account_id(
        acctId,
        simId,
        appId,
        KAL_FALSE);
    srv_dtcnt_get_auto_acc_id(encodeAcctId, &outAcctId);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_GET_AUTO_ACCT_ID, encodeAcctId, outAcctId);
    return outAcctId;
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntSelectPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
	if(VFX_FALSE == flag)
	{
		if(VappDtcntSimAvailableInfo::getAvailableSimNum() == 1)
		{
			m_scrPageNum = 1;
		}
		if(m_sim == sim)
		{
			getMainScr()->closePage(getId());
		}
	}
}
#endif

/***************************************************************************** 
 * Class VappDtcntDualSIMSelectPage
 *****************************************************************************/

void VappDtcntDualSIMSelectPage::onInit()
{
    VfxPage::onInit();
    vapp_dtcnt_set_titlebar(STR_GLOBAL_DATA_CONN_SETTING, this);
 
    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->m_signalItemTapped.connect(this, &VappDtcntDualSIMSelectPage::onDualItemTapped);
    m_menu->setSize(getSize());
    setListMenuFormat(m_menu, VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT, VCP_LIST_MENU_MODE_NORMAL, VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);        
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntDualSIMSelectPage::onSimChangeEvt);
#endif
}


void VappDtcntDualSIMSelectPage::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
        VappDtcntSelectScr *mainScr;
        mainScr = (VappDtcntSelectScr*)getMainScr(); // get Main screen
        mmi_id cuiId;
        cuiId = mainScr->getCuiId(); // get group id
        VappDtcntSelect *dtcntSelectInstance;
        VappDtcntSelectParam *dtcntSelectParam;
        dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cuiId); // get cui instance
        dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI
        VfxU32 acctId;
        kal_bool isAlwaysAsk;
        VfxU32 oriAcctId;
        VfxU8 appId;
        VfxU32 index;
        for (index = 0; index < MMI_SIM_TOTAL; index++)
        {
            acctId = m_dispContext->getSimAccountId(index);
            //change to Automatic if change to CSD but app don't support CSD:
            cbm_decode_data_account_id(acctId, NULL, &appId, &isAlwaysAsk, (kal_uint32*)&oriAcctId);
            if (!isAlwaysAsk && (oriAcctId != CBM_DEFAULT_ACCT_ID))
            {
                srv_dtcnt_bearer_enum bearer = srv_dtcnt_get_bearer_type(oriAcctId, SRV_DTCNT_ACCOUNT_PRIMARY);
                if (bearer == SRV_DTCNT_BEARER_CSD && 
                    !(dtcntSelectParam->getBearers() & DATA_ACCOUNT_BEARER_CSD))
                {
                    acctId = cbm_encode_data_account_id(
                                     CBM_DEFAULT_ACCT_ID,
                                     (cbm_sim_id_enum)index, 
                                     appId, 
                                     KAL_FALSE);
                    m_dispContext->setSimAccountId(index, acctId);
                }
            }
        }

        VfxWChar *accountName;
        VFX_ALLOC_MEM(accountName, (MAX_DATA_ACCOUNT_NAME_LEN + 1) * sizeof(VfxWChar), this);
        srv_dtcnt_prof_str_info_qry_struct acctData;
        MMI_BOOL ret;

        for (index = 0; index < MMI_SIM_TOTAL; index++)
        {
            acctData.dest_len = (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH;
            acctData.dest = (char*)accountName;
            ret = srv_dtcnt_get_account_name(
                m_dispContext->getSimAccountId(index),
                &acctData,
                SRV_DTCNT_ACCOUNT_PRIMARY);
            if (!ret)
            {
                mmi_wcsncpy((WCHAR*)accountName, (WCHAR*)GetString(STR_ID_VAPP_DTCNT_NO_AVAILABLE_ACCOUNT), (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH);
            }
            m_dispContext->setSimAccountName(index, accountName);
        }
        VFX_FREE_MEM(accountName);
        updateList();
    }
}


void VappDtcntDualSIMSelectPage::onBack()
{
    VappDtcntSelectScr *mainScr;
    mainScr = (VappDtcntSelectScr*)getMainScr();
    mmi_id cuiId;
    cuiId = mainScr->getCuiId(); // get group id
    VappDtcntSelect *dtcntSelectInstance;
    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cuiId); // get cui instance
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI

    cui_dtcnt_select_event_result_struct evt;
    if (m_dispContext->getSelectedFlag())
    {
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, mainScr->getCuiId());
    }
    else
    {
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL, mainScr->getCuiId());
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, mainScr->getCuiId());
    dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&evt);
}

void VappDtcntDualSIMSelectPage::onDeinit()
{
    VfxPage::onDeinit();
}


void VappDtcntDualSIMSelectPage::onDualItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VappDtcntSelectScr *mainScr;
    mainScr = (VappDtcntSelectScr*)getMainScr(); // get Main screen
    mmi_id cuiId;
    cuiId = mainScr->getCuiId(); // get group id
    VappDtcntSelect *dtcntSelectInstance;
    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cuiId); // get cui instance
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI
    //index -> mmi_sim_enum
    mmi_sim_enum simEnum = MMI_SIM1;
    simEnum = VappDtcntSimAvailableInfo::getAvailableSimEnum(index);
    m_dispContext->prepareListInfo(
        dtcntSelectParam,
        simEnum,
        VFX_TRUE);
    // push page
    VappDtcntSelectPage *selectPage;
    VFX_OBJ_CREATE_EX(selectPage, VappDtcntSelectPage, getMainScr(), (m_scrPageNum, simEnum, m_dispContext));
    getMainScr()->pushPage(0, selectPage);
}


VfxBool VappDtcntDualSIMSelectPage::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    VfxWString str;
    VfxU32 simIndex;
    simIndex = VappDtcntSimAvailableInfo::getAvailableSimIndex(index);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        str = VappDtcntDispItemList::getSimName(simIndex);
        text = str;
    }
    else
    {
        text.loadFromMem(m_dispContext->getSimAccountName(simIndex));
    }

    return VFX_TRUE;
}


VfxU32 VappDtcntDualSIMSelectPage::getCount() const
{
    return VappDtcntSimAvailableInfo::getAvailableSimNum();
}


VfxBool VappDtcntDualSIMSelectPage::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    ) 
{
    if (VCP_LIST_MENU_FIELD_DISCLOSURE_IMG == fieldType)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
    }
    else if (VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG == fieldType)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
    }
    return VFX_TRUE;
}

void VappDtcntDualSIMSelectPage::updateList()
{
    m_menu->resetAllItems();
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntDualSIMSelectPage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
	if(VappDtcntSimAvailableInfo::getAvailableSimNum() > 1)
	{
		 m_menu->resetAllItems();
	}
	else
	{
		m_scrPageNum = 1;
	}
}
#endif

/***************************************************************************** 
 * Class VappDtcntSelectScr
 *****************************************************************************/

VappDtcntSelectScr::VappDtcntSelectScr() : 
    m_cuiId(GRP_ID_INVALID),
    m_pageNum(1),
    m_dispContext(NULL),
    m_sim(MMI_SIM_NONE)
{
}


VappDtcntSelectScr::VappDtcntSelectScr(mmi_id cuiId) : 
    m_cuiId(cuiId),
    m_pageNum(1),
    m_dispContext(NULL),
    m_sim(MMI_SIM_NONE)
{
#ifdef __MMI_CBM_ALWAYS_ASK__
    VappDtcntSelect *dtcntSelectInstance;
    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(m_cuiId); // get cui instance
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI

    cui_dtcnt_select_type_enum selectType;
    selectType = dtcntSelectParam->getSelectType();
    if (selectType == CUI_DTCNT_SELECT_TYPE_CBM)
    {
        setIsSmallScreen();
    }
#endif
}


void VappDtcntSelectScr::on1stReady()
{
    VfxMainScr::on1stReady();
	update();
}


void VappDtcntSelectScr::update()
{
    VappDtcntSelect *dtcntSelectInstance;
    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(m_cuiId); // get cui instance
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI

    VFX_OBJ_CREATE(m_dispContext, VappDtcntSelectDispContext, this);

    VfxU32 acctId, i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        acctId = dtcntSelectParam->getSimAccountID(i);
        m_dispContext->setSimAccountId(i, acctId);
    }

    cui_dtcnt_select_type_enum selectType;
    selectType = dtcntSelectParam->getSelectType();

    srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
    cui_dtcnt_select_sim_enum selectSim = CUI_DTCNT_SELECT_SIM1;
    mmi_sim_enum simEnum = MMI_SIM1; // this variable used to prepare data

    VfxU32 availSim = 0;
    if(VappDtcntReadyCheck::getIsDtcntReady() && srv_sim_ctrl_get_one_available_sim())
    {
        availSim = VappDtcntSimAvailableInfo::getAvailableSimNum();
    }
    MMI_BOOL ret;
    ret = srv_dtcnt_get_sim_preference(&simType); // data connection sim
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, simType, ret);

    switch (selectType)
    {
        case CUI_DTCNT_SELECT_TYPE_NORMAL:
            selectSim = dtcntSelectParam->getSimSelection();
            if (availSim > 1 && selectSim == CUI_DTCNT_SELECT_SIM_ALL)
            {
                m_pageNum = 2; // only this case have two page
                VfxWChar *accountName;
                srv_dtcnt_prof_str_info_qry_struct acctData;
                VFX_ALLOC_MEM(accountName, (MAX_DATA_ACCOUNT_NAME_LEN + 1) * sizeof(VfxWChar), this);

                for (i = 0; i < MMI_SIM_TOTAL; i++)
                {
                    acctData.dest_len = (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH;
                    acctData.dest = (char*)accountName;
                    ret = srv_dtcnt_get_account_name(
                        m_dispContext->getSimAccountId(i),
                        &acctData,
                        SRV_DTCNT_ACCOUNT_PRIMARY);
                    if (!ret)
                    {
                        mmi_wcsncpy((WCHAR*)accountName, (WCHAR*)GetString(STR_ID_VAPP_DTCNT_NO_AVAILABLE_ACCOUNT), (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH);
                    }
                    //VappDtcntDispItemList::getFullAccountName(
                    //    m_dispContext->getSimAccountId(i),
                    //    accountName,
                    //    MAX_DATA_ACCOUNT_NAME_LEN + 1,
                    //    VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                    m_dispContext->setSimAccountName(i, accountName);
                }
                VFX_FREE_MEM(accountName);
                // push page
                VappDtcntDualSIMSelectPage *dualSelectPage;
                VFX_OBJ_CREATE_EX(dualSelectPage, VappDtcntDualSIMSelectPage, this, (m_pageNum, m_dispContext));
                pushPage(0, dualSelectPage);
            }
            else
            {
                m_pageNum = 1;
                if (selectSim == CUI_DTCNT_SELECT_SIM_ALL)
                {
                    if (availSim == 1)
                    {
                        simEnum = mmi_frm_index_to_sim((simType - 1));
                    }
                }
                else
                {
                    VfxU32 index;
                    index = mmi_frm_sim_to_index((mmi_sim_enum)selectSim);
                    VFX_ASSERT(index < MMI_SIM_TOTAL);
                    simEnum = (mmi_sim_enum)selectSim;
                }
                m_dispContext->prepareListInfo(
                    dtcntSelectParam,
                    simEnum,
                    VFX_TRUE);
                // push page
                VappDtcntSelectPage *selectPage;
                VFX_OBJ_CREATE_EX(selectPage, VappDtcntSelectPage, this, (m_pageNum, simEnum, m_dispContext));
                pushPage(0, selectPage);
            }
            break;
    #ifdef __MMI_CBM_ALWAYS_ASK__
        case CUI_DTCNT_SELECT_TYPE_CBM:
            if (simType != SRV_DTCNT_SIM_TYPE_NONE)
            {
                simEnum = mmi_frm_index_to_sim((simType - 1));
            }
            m_dispContext->prepareListInfo(
                dtcntSelectParam,
                simEnum,
                VFX_FALSE);

            // display popup
            setBgColor(VFX_COLOR_TRANSPARENT);
            setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
            //setIsSmallScreen();
            if (m_dispContext->getListItemNumber())
            {
                VcpMenuPopup *menuPopup;
                VcpMenuPopupItem *menuItem;
                VFX_OBJ_CREATE(menuPopup, VcpMenuPopup, this);
                VfxWString str;
                str.loadFromRes(STR_ID_VCUI_DTCNT_ALWAYS_ASK_TITLE);
                menuPopup->setTitle(str);

                VfxU32 i;
                VappDtcntSelectItemInfo *itemInfo;    
                for (i = 0; i < m_dispContext->getListItemNumber(); i++)
                {
                    itemInfo = m_dispContext->getListInfo(i);
                    menuItem = menuPopup->createMenuItem(i, str.loadFromMem(itemInfo->getName()));
                    menuPopup->insertItem(NULL, NULL, menuItem);
                }
                menuPopup->setIsAutoCancel(VFX_FALSE);
                menuPopup->show(VFX_FALSE);
                menuPopup->m_signalMenuCallback.connect(this, &VappDtcntSelectScr::onAlwaysAskListSelect);
            }
            else
            {
                VappDtcntSelectCfmPop *confirmPopup;
                VFX_OBJ_CREATE(confirmPopup, VappDtcntSelectCfmPop, this);
                confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                VfxWString string;
                string.loadFromRes(STR_ID_VCUI_DTCNT_ALWAYS_ASK_EMPTY_LIST);
                confirmPopup->setText(string);
                confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                confirmPopup->m_signalButtonClicked.connect(this, &VappDtcntSelectScr::onAlwaysAskConfirmPopup);
                confirmPopup->show(VFX_FALSE);
            }
            break;
    #endif
        default:
            break;
    }
}

#ifdef __MMI_CBM_ALWAYS_ASK__
void VappDtcntSelectScr::onAlwaysAskListSelect(
        VcpMenuPopup *sender, // sender
        VcpMenuPopupEventEnum evt, //evt
        VcpMenuPopupItem *item // item
    )
{
    VappDtcntSelect *dtcntSelectInstance;
    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(m_cuiId); // get cui instance
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI

    if (VCP_MENU_POPUP_EVENT_ITEM_SELECTED == evt)
    {
        // one encode account need appId, sim id, always ask info and pure account id
        VfxU8 appId = dtcntSelectParam->getAppId();
        cbm_sim_id_enum cbmSimId = CBM_SIM_ID_SIM1;
        MMI_BOOL ret;
        srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
        ret = srv_dtcnt_get_sim_preference(&simType);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, simType, ret);
        if (simType != SRV_DTCNT_SIM_TYPE_NONE)
        {
            cbmSimId = (cbm_sim_id_enum)(simType - 1);
        }            

        VfxBool isAlwaysAsk = VFX_FALSE;
        VfxU32 acctId;

        VfxId i;
        i = item->getId();
        VappDtcntSelectItemInfo *listInfo;
        listInfo = m_dispContext->getListInfo(i);

        acctId = listInfo->getProfileId();

        VfxU32 encodeAccountId;
        encodeAccountId = cbm_encode_data_account_id(acctId, cbmSimId, appId, (kal_bool)isAlwaysAsk);

        // send account selected event
        cui_dtcnt_select_event_any_sim_selected_struct simSelectedEvt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&simSelectedEvt, CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED, m_cuiId);

        simSelectedEvt.selectSim = (cui_dtcnt_sim_enum)cbmSimId;
        simSelectedEvt.accountId = encodeAccountId;
        
        MMI_TRACE(
            MMI_CONN_TRC_G6_DTCNT, 
            TRC_VCUI_DTCNT_SEND_EVENT_WITH_ACCOUNT_ID, 
            m_cuiId,
            simSelectedEvt.selectSim,
            simSelectedEvt.accountId);
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&simSelectedEvt);

        // send OK event
        cui_dtcnt_select_event_result_struct resultEvt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&resultEvt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, m_cuiId);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, m_cuiId);
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&resultEvt);
    }
    else if (VCP_MENU_POPUP_EVENT_MENU_CANCEL == evt)
    {        
        cui_dtcnt_select_event_result_struct resultEvt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&resultEvt, CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL, m_cuiId);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, m_cuiId);
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&resultEvt);
    }
}
#endif


#ifdef __MMI_CBM_ALWAYS_ASK__
void VappDtcntSelectScr::onAlwaysAskConfirmPopup(
    VfxObject *obj, // sender
    VfxId id 
    )
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_OK || id == VAPP_DTCNT_SELECT_CFM_POP_BACK)
    {
        VappDtcntSelect *dtcntSelectInstance;
        VappDtcntSelectParam *dtcntSelectParam;
        dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(m_cuiId); // get cui instance
        cui_dtcnt_select_event_result_struct evt;
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL, m_cuiId);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, m_cuiId);
        dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&evt);
    }
}
#endif


void VappDtcntSelectScr::onInit()
{
    VfxMainScr::onInit();
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntSelectScr::onSimChangeEvt);
#endif
}


void VappDtcntSelectScr::onDeinit()
{
    //VFX_TRACE((""));
    VFX_TRACE(("VappDtcntSelectScr::onDeinit"));
    VfxMainScr::onDeinit();
}

void VappDtcntSelectScr::setSimType(mmi_sim_enum simType)
{
    m_sim = simType;
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntSelectScr::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
    if(VappDtcntSimAvailableInfo::getAvailableSimNum() < 2)
    {
	VappDtcntSelect *dtcntSelectInstance;
        dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(m_cuiId);
	cui_dtcnt_select_event_result_struct evt;
    	MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_CLOSE, m_cuiId);
    	MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SEND_EVENT_WITHOUT_ACCOUNT_ID, m_cuiId);
    	dtcntSelectInstance->sendToCaller((mmi_group_event_struct*)&evt);
    }
}
#endif

/***************************************************************************** 
 * Class VappConverterContext
 *****************************************************************************/

void VappDtcntSelectItemInfo::onInit()
{
     VfxObject::onInit();
}

void VappDtcntSelectItemInfo::onDeinit()
{
     VfxObject::onDeinit();
}


VappDtcntSelectDispContext::VappDtcntSelectDispContext() : 
    m_listItemNumber(0),
    m_selectedFlag(VFX_FALSE)
{
    VfxU32 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        m_simAccountId[i] = VAPP_DTCNT_AUTOMATIC_ID;
        mmi_wcscpy((WCHAR*)m_simAccountName[i],(WCHAR*)L"");
    }
    for (i = 0; i < (VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_DATA_ACCOUN_CUI_FIX_ITEM); i++)
    {
        VFX_OBJ_CREATE(m_listInfo[i], VappDtcntSelectItemInfo, this);
    }
}


void VappDtcntSelectDispContext::swapListInfo(VappDtcntSelectItemInfo *ListInfo1, VappDtcntSelectItemInfo *ListInfo2)
{
    VfxU32 tempProfileId;
    VfxU16 tempItemStrId;
    VappDtcntSelectAcctType tempAccountType;
    VappDtcntSelectItemType tempItemType;
    VfxWChar tempName[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    VfxWChar tempAddress[MAX_DTCNT_LIST_ADDR_LEN];

    // get temp data
    tempProfileId = ListInfo1->getProfileId();
    tempItemStrId = ListInfo1->getItemStrId();
    tempAccountType = ListInfo1->getAccountType();
    tempItemType = ListInfo1->getItemType();
    mmi_wcscpy((WCHAR*)tempName, (WCHAR*)ListInfo1->getName());
    mmi_wcscpy((WCHAR*)tempAddress, (WCHAR*)ListInfo1->getAddress());

    // set listInfo1
    ListInfo1->setProfileId(ListInfo2->getProfileId());
    ListInfo1->setItemStrId(ListInfo2->getItemStrId());
    ListInfo1->setAccountType(ListInfo2->getAccountType());
    ListInfo1->setItemType(ListInfo2->getItemType());
    ListInfo1->setName(ListInfo2->getName());
    ListInfo1->setAddress(ListInfo2->getAddress());

    // set listinfo2
    ListInfo2->setProfileId(tempProfileId);
    ListInfo2->setItemStrId(tempItemStrId);
    ListInfo2->setAccountType(tempAccountType);
    ListInfo2->setItemType(tempItemType);
    ListInfo2->setName(tempName);
    ListInfo2->setAddress(tempAddress);
}


void VappDtcntSelectDispContext::arrangeAcctListInfo(VappDtcntSelectItemInfo **ListInfo, VfxU32 start, VfxU32 end)
{
    if (end <= (start + 1))
    {
        return;
    }
    // because not include end index
    VfxU32 i, j;
    VfxBool flag;
    for (i = start; i < end - 1; i++)
    {
        flag = VFX_FALSE;
        for (j = start; j < (end + start - 1 - i); j++)
        {
            if (mmi_wcscmp((WCHAR*)ListInfo[j]->getName(), (WCHAR*)ListInfo[j + 1]->getName()) > 0)
            {
                swapListInfo(ListInfo[j], ListInfo[j + 1]);
                flag = VFX_TRUE;
            }                
        }
        if (!flag)
        {
            break;
        }
    }
}


void VappDtcntSelectDispContext::prepareListInfo(VappDtcntSelectParam *param, mmi_sim_enum simEnum, VfxBool isSingleSelect)
{
    VfxU32 listNum = 0;
    VfxS32 start = 0;
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
    #ifdef __MMI_CBM_ALWAYS_ASK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_CBM_ALWAYS_ASK__ */
/* under construction !*/
#endif    
    VfxU32 i;
    VfxU32 acctNum;
    acctNum = VappDtcntDispItemList::getAcctNum();
    VappDtcntDispItem* selectItem;
    VfxU8 simInfo;
    simInfo = (U8)(mmi_frm_sim_to_index(simEnum) + 1);
    // user define factory config account
    start = listNum;
    for (i = 0; i < acctNum; i++)
    {
    	if (!srv_sim_ctrl_any_sim_is_available())
        {
            break;
        }
        selectItem = VappDtcntDispItemList::getAccountItem(i);
        if (param->getBearers() & selectItem->getBearerType()) // bearer
        {
            if (selectItem->getAccountType() == SRV_DTCNT_PROF_TYPE_USER_CONF ||
             selectItem->getAccountType() == SRV_DTCNT_PROF_TYPE_OTA_CONF) // configure type
            {
                if ((param->getOptions() & CUI_DTCNT_SELECT_WITH_PROXY_ONLY) && 
                    !(VappDtcntDispItemList::isAccountUseProxy(selectItem->getProfileId())))
                {
                    continue;
                }
                if ((param->getOptions() & CUI_DTCNT_SELECT_WITHOUT_PROXY_ONLY) && 
                    (VappDtcntDispItemList::isAccountUseProxy(selectItem->getProfileId())))
                {
                    continue;
                }
                if (selectItem->getSimInfo() == simInfo)                
                {
                    if (((param->getOptions() & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && (selectItem->getConnectionType() == 1)) || 
                        ((param->getOptions() & CUI_DTCNT_SELECT_CONNTYPE_WAP_ONLY) && (selectItem->getConnectionType() == 0)) ||
                        ((param->getOptions() & (CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY | CUI_DTCNT_SELECT_CONNTYPE_WAP_ONLY)) == 0))
                    {
                        if (selectItem->getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
                        {
                            m_listInfo[listNum]->setItemType(VAPP_DTCNT_SELECT_ITEM_GPRS);
                        }
                        else if (selectItem->getBearerType() == DATA_ACCOUNT_BEARER_CSD)
                        {
                            m_listInfo[listNum]->setItemType(VAPP_DTCNT_SELECT_ITEM_CSD);
                        }
                        m_listInfo[listNum]->setAccountType(VAPP_DTCNT_SELECT_ACCT_USER_DEFINED);
                        m_listInfo[listNum]->setProfileId(selectItem->getProfileId());

                        srv_dtcnt_prof_str_info_qry_struct acctData;
                        acctData.dest_len = (MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH;
                        VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
                        srv_dtcnt_get_account_name(selectItem->getProfileId(),
                                      &acctData,
                                      SRV_DTCNT_ACCOUNT_PRIMARY);
                        //mmi_wcscat((WCHAR*)acct_data.dest, (WCHAR*)L"(SIM2)");
                        m_listInfo[listNum]->setName((VfxWChar*)acctData.dest);
                        VFX_FREE_MEM(acctData.dest);

                        acctData.dest_len = (MAX_DTCNT_LIST_ADDR_LEN) * ENCODING_LENGTH;
                        VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
                        if (selectItem->getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
                        {
                            srv_dtcnt_get_apn(
                                selectItem->getProfileId(),
                                &acctData,
                                SRV_DTCNT_ACCOUNT_PRIMARY);
                        }
                        else
                        {
                            srv_dtcnt_get_csd_number(
                                selectItem->getProfileId(),
                                &acctData,
                                SRV_DTCNT_ACCOUNT_PRIMARY);
                        }
                        m_listInfo[listNum]->setAddress((VfxWChar*)acctData.dest);
                        VFX_FREE_MEM(acctData.dest);

                        listNum++;
                    }
                }                
            }
        }
    }
    arrangeAcctListInfo(m_listInfo, start, listNum);

    //cui_dtcnt_select_sim_enum sim;
    //sim = param->getSimSelection();

    //VfxU32 availSimNum;
    //availSimNum = VappDtcntSimAvailableInfo::getAvailableSimNum();
    // sim factory config account
    start = listNum;
    for (i = 0; i < acctNum; i++)
    {
        // factory config account will check sim card
        if (!srv_sim_ctrl_is_available(simEnum)) // sim1 doesn't exist
        {
            break;
        }

        selectItem = VappDtcntDispItemList::getAccountItem(i);
        if (param->getBearers() & selectItem->getBearerType()) // bearer
        {
            if (selectItem->getAccountType() == SRV_DTCNT_PROF_TYPE_FACTORY_CONF ||
             (selectItem->getAccountType() == SRV_DTCNT_PROF_TYPE_SIM_PROF && 
             (param->getOptions() & CUI_DTCNT_SELECT_SIM_PROFILE))) // configure type
            {
                if ((param->getOptions() & CUI_DTCNT_SELECT_WITH_PROXY_ONLY) && 
                    !(VappDtcntDispItemList::isAccountUseProxy(selectItem->getProfileId())))
                {
                    continue;
                }
                if ((param->getOptions() & CUI_DTCNT_SELECT_WITHOUT_PROXY_ONLY) && 
                    (VappDtcntDispItemList::isAccountUseProxy(selectItem->getProfileId())))
                {
                    continue;
                }
                if (selectItem->getSimInfo() == simInfo)
                {
                    if (((param->getOptions() & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && (selectItem->getConnectionType() == 1)) || 
                        ((param->getOptions() & CUI_DTCNT_SELECT_CONNTYPE_WAP_ONLY) && (selectItem->getConnectionType() == 0)) ||
                        ((param->getOptions() & (CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY | CUI_DTCNT_SELECT_CONNTYPE_WAP_ONLY)) == 0))
                    {
                        if (selectItem->getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
                        {
                            m_listInfo[listNum]->setItemType(VAPP_DTCNT_SELECT_ITEM_GPRS);
                        }
                        else if (selectItem->getBearerType() == DATA_ACCOUNT_BEARER_CSD)
                        {
                            m_listInfo[listNum]->setItemType(VAPP_DTCNT_SELECT_ITEM_CSD);
                        }
                        m_listInfo[listNum]->setAccountType(VAPP_DTCNT_SELECT_ACCT_DEFAULT);
                        m_listInfo[listNum]->setProfileId(selectItem->getProfileId());

                        srv_dtcnt_prof_str_info_qry_struct acctData;
                        acctData.dest_len = (MAX_DATA_ACCOUNT_NAME_LEN + 1) * ENCODING_LENGTH;
                        VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
                        srv_dtcnt_get_account_name(selectItem->getProfileId(),
                                      &acctData,
                                      SRV_DTCNT_ACCOUNT_PRIMARY);
                        //if (availSimNum > 1)
                        //{
                        //    WCHAR temp[DATA_ACCOUNT_NAME_SUFFIX_LEN + 1];
                        //    kal_wsprintf(temp, "(SIM%d)", simInfo);
                        //    mmi_wcscat((WCHAR*)acctData.dest, temp);
                        //}
                        m_listInfo[listNum]->setName((VfxWChar*)acctData.dest);
                        VFX_FREE_MEM(acctData.dest);

                        acctData.dest_len = (MAX_DTCNT_LIST_ADDR_LEN) * ENCODING_LENGTH;
                        VFX_ALLOC_MEM(acctData.dest, acctData.dest_len, this);
                        if (selectItem->getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
                        {
                            srv_dtcnt_get_apn(
                                selectItem->getProfileId(),
                                &acctData,
                                SRV_DTCNT_ACCOUNT_PRIMARY);
                        }
                        else
                        {
                            srv_dtcnt_get_csd_number(
                                selectItem->getProfileId(),
                                &acctData,
                                SRV_DTCNT_ACCOUNT_PRIMARY);
                        }
                        m_listInfo[listNum]->setAddress((VfxWChar*)acctData.dest);
                        VFX_FREE_MEM(acctData.dest);

                        listNum++;
                    }
                }                
            }
        }
    }
    arrangeAcctListInfo(m_listInfo, start, listNum);
    m_listItemNumber = listNum;
}


void VappDtcntSelectDispContext::onInit()
{
     VfxObject::onInit();
}


void VappDtcntSelectDispContext::onDeinit()
{
     VfxObject::onDeinit();
}
#endif

/*******************************************************************************
* Export API 
*******************************************************************************/
/* Create select CUI, data account CUI will support multi-instance */
extern "C" mmi_id vcui_dtcnt_select_create(mmi_id parent_id)
{
#ifdef __TCPIP__
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_DTCNT,
                                        VFX_OBJ_CLASS_INFO(VappDtcntSelect),
                                        parent_id);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SELECT_CREATE, parent_id, cui_id);
    return cui_id;
#else
    return GRP_ID_INVALID;
#endif
}

/* Initialize CUI */
extern "C" void vcui_dtcnt_select_set_param(mmi_id cui_id, cui_dtcnt_select_run_struct *p_args)
{
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SELECT_SET_PARAM, 
        cui_id,
        p_args->bearers,
        p_args->app_id,
        p_args->sim_account_id[0],
        0,
        p_args->option,
        p_args->sim_selection,
        p_args->type);
    VappDtcntSelect *dtcntSelectInstance;
    VfxU32 i;
    VfxU32 encodeAcctid;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cui_id); // get cui instance
    dtcntSelectInstance->createDtcntParamObject();

    VappDtcntSelectParam *dtcntSelectParam;
    dtcntSelectInstance->getDtcntParam(&dtcntSelectParam); // get Param for this CUI

    dtcntSelectParam->setBearers(p_args->bearers);
    dtcntSelectParam->setAppId(p_args->app_id);
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
    		encodeAcctid = cbm_set_app_id(p_args->sim_account_id[i], p_args->app_id);
        dtcntSelectParam->setSimAccountID(i, encodeAcctid);
    }
    dtcntSelectParam->setOptions((cui_dtcnt_select_option_enum)p_args->option);
    dtcntSelectParam->setSimSelection(p_args->sim_selection);
    dtcntSelectParam->setSelectType(p_args->type);
#endif
}


/* Execute CUI*/
extern "C" void vcui_dtcnt_select_run(mmi_id cui_id)
{
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SELECT_RUN, cui_id);
    VfxAppLauncher::runCui(cui_id);
#endif
}

/* Close CUI */
extern "C" void  vcui_dtcnt_select_close(mmi_id cui_id)
{
#ifdef __TCPIP__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VCUI_DTCNT_SELECT_CLOSE, cui_id);
    VfxAppLauncher::terminate(cui_id);
#endif
}


extern "C" void vcui_dtcnt_select_set_account_id(mmi_id cui_id, cui_dtcnt_sim_enum sim, U32 accountId)
{
#ifdef __TCPIP__
    VappDtcntSelect *dtcntSelectInstance;
    dtcntSelectInstance = (VappDtcntSelect *)VfxApp::getObject(cui_id); // get cui instance

    VappDtcntSelectScr *mainScr;
    mainScr = dtcntSelectInstance->getScr();
    if (!mainScr)
    {
        return;
    }
    VappDtcntSelectDispContext *dispContext;
    dispContext = mainScr->getDispContext();
    if (!dispContext)
    {
        return;
    }
    if (sim >= MMI_SIM_TOTAL)
    {
        ASSERT(0);
    }
    dispContext->setSimAccountId((VfxU32)sim, accountId);
#endif
}


