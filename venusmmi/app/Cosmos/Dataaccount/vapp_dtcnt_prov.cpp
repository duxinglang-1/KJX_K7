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
 *  vapp_dtcnt_prov.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file is used to implement for data account provisioning
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __TCPIP__

//#ifdef __CCA_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vapp_dtcnt_prov.h"
#include "vapp_dtcnt.h"
#include "mmi_rp_vapp_dtcnt_def.h"
//#include "mmi_rp_app_cca_def.h"
#include "mmi_rp_vapp_cca_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "GlobalResDef.h"

extern "C"
{
#include "cbm_api.h"
#include "cbm_consts.h"
#include "MMI_conn_app_trc.h"
#include "SimCtrlSrvGprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "TetheringSrvGprot.h"
}

#ifdef __COSMOS_DTCNT_CCA_SUPPORT__

/***************************************************************************** 
 * Class VappDtcntProvReplacePage
 *****************************************************************************/

void VappDtcntProvReplacePage::onInit()
{
    VfxPage::onInit();
    // prepare data for list
    VFX_OBJ_CREATE(m_listCntx, VappDtcntListDisplayContext, this);
    m_listCntx->prepareListInfo(m_provEvt->sim_info, VAPP_DTCNT_LIST_PREPARE_TYPE_PROVISIONING);
    vapp_dtcnt_set_titlebar(STR_ID_VAPP_CCA_REPLACE_SETTING, this);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem(REPLACE_PAGE_ID_TOOLBAR_REPLACE, STR_GLOBAL_REPLACE, IMG_ID_VAPP_CCA_REPLACE);
    toolBar->addItem(REPLACE_PAGE_ID_TOOLBAR_CANCEL, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappDtcntProvReplacePage::onToolbarTapped);          // connect tool bar signal
    setBottomBar(toolBar); 

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappDtcntProvReplacePage::onItemStateChanged);
    m_listMenu->setSize(getSize());
    setListMenuFormat(m_listMenu, VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT, VCP_LIST_MENU_MODE_SINGLE_SELECTION, VCP_LIST_MENU_CONTROL_MODE_NORMAL);
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.connect(this, &VappDtcntProvReplacePage::onSimChangeEvt);
#endif
}


void VappDtcntProvReplacePage::onDeinit()
{
    VfxPage::onDeinit();
}

void VappDtcntProvReplacePage::onBack()
{
    VcpConfirmPopup *confirmPopup;
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    confirmPopup->setText(STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappDtcntProvReplacePage::onExitInstallConfirm);
}

void VappDtcntProvReplacePage::onExitInstallConfirm(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        if (m_provEvt->cnf_callback)
        {
            provCallback(SRV_DTCNT_PROV_CNF_ABORT, m_provEvt->cur_prof_idx);
        }
    }
}

void VappDtcntProvReplacePage::provCallback(srv_dtcnt_prov_cnf_enum provType, VfxU8 idx)
{
    m_provEvt->cnf_callback(provType, idx);
    VappDtcntProvScr *mainScr;
    mainScr = (VappDtcntProvScr*)getMainScr();
    VappDtcntProvCui *provCui;
    provCui = (VappDtcntProvCui*)VfxApp::getObject(mainScr->getCuiId());
    provCui->setNeedAbortFlag(VFX_FALSE);
}

VfxBool VappDtcntProvReplacePage::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
)
{
    VappDtcntDisplayItemInfo *itemInfo;
    itemInfo = m_listCntx->getListInfo(index);
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.loadFromMem(itemInfo->getName());
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text.loadFromMem(itemInfo->getAddress());
    }
    return VFX_TRUE;
}


VfxU32 VappDtcntProvReplacePage::getCount() const
{
    return m_listCntx->getListItemNumber();
}


VcpListMenuItemStateEnum VappDtcntProvReplacePage::getItemState(
    VfxU32 index   // [IN] index of the item
) const
{
    if (index == m_replaceIndex)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


void VappDtcntProvReplacePage::onItemStateChanged(
    VcpListMenu *sender, 
    VfxU32 index, 
    VcpListMenuItemStateEnum newState
)
{
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_replaceIndex = index;
    }
}


void VappDtcntProvReplacePage::onToolbarTapped(
    VfxObject* sender,  // sender
    VfxId id            // id
)
{
    if(REPLACE_PAGE_ID_TOOLBAR_REPLACE == id)
    {
        VappDtcntDisplayItemInfo *itemInfo;
        itemInfo = m_listCntx->getListInfo(m_replaceIndex);
        VfxU32 acctId;
        acctId = itemInfo->getProfileId();
        if (VappDtcntDispItemList::isAccountInUse(acctId) || (acctId == VappDtcntDispItemList::getCurrEditProfileId()))
        {
            VcpConfirmPopup *confirmPopup; 
            VfxWString str;
            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            str.loadFromRes(STR_ID_VAPP_CCA_PROFILE_IN_USE);
            confirmPopup->setText(str);
            //confirmPopup->setText(VFX_WSTR("Profile in use"));
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            confirmPopup->show(VFX_FALSE);
            return;
        }
        provReplaceRSP();
    }
    else
    {
        getMainScr()->popPage();
    }
}


void VappDtcntProvReplacePage::provReplaceRSP()
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROV_SELECT_REPLACE, m_provEvt->cnf_callback);
    if (m_provEvt->cnf_callback)
    {
        VappDtcntDisplayItemInfo *itemInfo;
        itemInfo = m_listCntx->getListInfo(m_replaceIndex);
        provCallback(SRV_DTCNT_PROV_CNF_REPLACE, itemInfo->getProfileId());
        VfxAppLauncher::terminate(((VappDtcntProvScr *)getMainScr())->getCuiId());    
    }
}

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__ 
void VappDtcntProvReplacePage::onSimChangeEvt(VfxBool flag, mmi_sim_enum sim)
{
    VfxU32 simIndex = 0;
    simIndex = mmi_frm_sim_to_index(sim);
    
    if(flag == VFX_FALSE)
    {
	if(simIndex == (VfxU32)(m_provEvt->sim_info - 1))
	{
	    //reset default sim
	    getMainScr()->popPage();
	}
    }
}
#endif


/***************************************************************************** 
 * Class VappDtcntProvInstallPage
 *****************************************************************************/

void VappDtcntProvInstallPage::onInit()
{
    VfxPage::onInit();    
    vapp_dtcnt_set_titlebar(STR_ID_VAPP_CCA_INSTALL_SETTING, this);

    VcpTextView *textView;
    VFX_OBJ_CREATE(textView, VcpTextView, this);

    textView->setPos(LEFT_GAPS, TOP_GAPS);
    textView->setSize(getSize().width - LEFT_GAPS - RIGHT_GAPS, 
                      getSize().height - TOP_GAPS - BOTTOM_GAPS);
    textView->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VfxWChar *text;
    VFX_ALLOC_MEM(text, 512, this);
    memset(text, 0x00, 512);
    prepareProfInfo(text);
    textView->setText(text);
    textView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    VFX_FREE_MEM(text);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);   
    toolBar->addItem(INSTALL_PAGE_ID_TOOLBAR_INSTALL, STR_GLOBAL_INSTALL, IMG_ID_VAPP_CCA_INSTALL);
    toolBar->addItem(INSTALL_PAGE_ID_TOOLBAR_SKIP, STR_ID_VAPP_CCA_SKIP, IMG_ID_VAPP_CCA_SKIP);
    toolBar->m_signalButtonTap.connect(this, &VappDtcntProvInstallPage::onToolbarTapped);
    setBottomBar(toolBar);
}


void VappDtcntProvInstallPage::prepareProfInfo(VfxWChar *info)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROV_PREPARE_PROF_INFO);
    srv_dtcnt_prov_csd_gprs_ind_struct *provAcct = (srv_dtcnt_prov_csd_gprs_ind_struct *)(m_provEvt->prof_data);    
    
    if (provAcct == NULL)
    {
        return;
    }

    /* APP Name: Data Account */
    mmi_ucs2cpy((CHAR*)info, (CHAR*)GetString(STR_GLOBAL_DATA_ACCOUNT));
    mmi_ucs2cat((CHAR*)info, (CHAR*) L"\n"); 

    /* Data Account Profile num */
    mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_CCA_PROFILE)); 
    mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_DTCNT_COLON)); 
    mmi_ucs2cat((CHAR*)info, (S8 *)L" ");

    VfxChar* numAsciiStr;
    VFX_ALLOC_MEM(numAsciiStr, MMI_DTCNT_GENERAL_STRING_LEN, this);
    memset(numAsciiStr, 0x00, MMI_DTCNT_GENERAL_STRING_LEN);
    VfxWChar* numUnicodeStr;
    VFX_ALLOC_MEM(numUnicodeStr, MMI_DTCNT_GENERAL_STRING_LEN, this);    
    memset(numUnicodeStr, 0x00, MMI_DTCNT_GENERAL_STRING_LEN);

    sprintf((S8 *)numAsciiStr, "%d/%d", m_provEvt->cur_prof_idx, m_provEvt->num_profs);

    mmi_asc_to_ucs2((CHAR*)numUnicodeStr, (CHAR*)numAsciiStr);
    mmi_ucs2cat((CHAR*)info, (CHAR*)numUnicodeStr);
    mmi_ucs2cat((CHAR*)info, (CHAR*)L"\n");

    VFX_FREE_MEM(numAsciiStr);
    VFX_FREE_MEM(numUnicodeStr);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (m_provEvt->prov_type == SRV_DTCNT_PROV_TYPE_UPDATE)
    {
        mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_CCA_UPDATE_PROFILE));
        mmi_ucs2cat((CHAR*)info, (CHAR*)L"\n");
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    mmi_ucs2cat((CHAR*)info, (CHAR*)L"\n");

    /* Data Account Name */
    mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_DTCNT_RENAME));
    mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_DTCNT_COLON)); 
    mmi_ucs2cat((CHAR*)info, (CHAR*)L" ");


    VfxWChar* tempBufUnicode;
    VFX_ALLOC_MEM(tempBufUnicode, MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH, this);    
    memset(tempBufUnicode, 0x00, MMI_DTCNT_GENERAL_STRING_LEN);   

    mmi_ucs2cpy((CHAR*)tempBufUnicode, (CHAR*)provAcct->AccountName);
    
    mmi_ucs2cat((CHAR*)info, (CHAR*)tempBufUnicode);
    mmi_ucs2cat((CHAR*)info, (CHAR*)L"\n");

    VfxS32 subLen = 0, copyLen = 0;
    subLen = strlen((const char *)provAcct->Address);
    copyLen = (subLen > (MAX_DTCNT_LIST_ADDR_LEN - 1) ? (MAX_DTCNT_LIST_ADDR_LEN - 1) : subLen);
    memset(tempBufUnicode, 0, MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH);

    /* Dial Number or APN */
#ifdef __TCPIP_OVER_CSD__
    if(m_provEvt->prov_ind == SRV_DTCNT_PROV_IND_CSD)
    {
        mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_DTCNT_DIAL_NUMBER));
        mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_DTCNT_COLON)); 
        mmi_ucs2cat((CHAR*)info, (CHAR*)L" ");        
        mmi_asc_n_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)provAcct->Address, copyLen);
        mmi_ucs2cat((CHAR*)info, (CHAR*)tempBufUnicode);
        mmi_ucs2cat((CHAR*)info, (CHAR*)L"\n");
    }
#endif
#ifdef __MMI_GPRS_FEATURES__
    if(m_provEvt->prov_ind == SRV_DTCNT_PROV_IND_GPRS)
    {
        mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_DTCNT_GPRS_APN));
        mmi_ucs2cat((CHAR*)info, (CHAR*)GetString(STR_ID_VAPP_DTCNT_COLON)); 
        mmi_ucs2cat((CHAR*)info, (CHAR*)L" ");
        mmi_asc_n_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)provAcct->Address, copyLen);
        mmi_ucs2cat((CHAR*)info, (CHAR*)tempBufUnicode);
        mmi_ucs2cat((CHAR*)info, (CHAR*)L"\n");
    }
#endif
    /* release buffers */
    VFX_FREE_MEM(tempBufUnicode);
}


void VappDtcntProvInstallPage::onDeinit()
{
    VfxPage::onDeinit();
}


void VappDtcntProvInstallPage::onBack()
{
    // do nothing, can't go back
    VcpConfirmPopup *confirmPopup;
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
    confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    confirmPopup->setText(STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappDtcntProvInstallPage::onExitInstallConfirm);
}

void VappDtcntProvInstallPage::onExitInstallConfirm(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        if (m_provEvt->cnf_callback)
        {
            provCallback(SRV_DTCNT_PROV_CNF_ABORT, m_provEvt->cur_prof_idx);
        }
    }
}

void VappDtcntProvInstallPage::provCallback(srv_dtcnt_prov_cnf_enum provType, VfxU8 idx)
{
    m_provEvt->cnf_callback(provType, idx);
    VappDtcntProvScr *mainScr;
    mainScr = (VappDtcntProvScr*)getMainScr();
    VappDtcntProvCui *provCui;
    provCui = (VappDtcntProvCui*)VfxApp::getObject(mainScr->getCuiId());
    provCui->setNeedAbortFlag(VFX_FALSE);
}

void VappDtcntProvInstallPage::provInstallRSP()
{    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROV_INSTALL_RSP, m_provEvt->cnf_callback);
    if (m_provEvt->cnf_callback)
    {
        provCallback(SRV_DTCNT_PROV_CNF_INSTALL, m_provEvt->cur_prof_idx);
        VfxAppLauncher::terminate(((VappDtcntProvScr *)getMainScr())->getCuiId());
    }
}

void VappDtcntProvInstallPage::provSkipRSP()
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROV_OTA_CCA_RSP_HANDLER, m_provEvt->cnf_callback);
    if (m_provEvt->cnf_callback)
    {
        provCallback(SRV_DTCNT_PROV_CNF_SKIP, m_provEvt->cur_prof_idx);
        VfxAppLauncher::terminate(((VappDtcntProvScr *)getMainScr())->getCuiId());
    }
}

void VappDtcntProvInstallPage::onToolbarTapped(
    VfxObject* sender,  // sender
    VfxId id            // id
)
{
    if(INSTALL_PAGE_ID_TOOLBAR_INSTALL == id)
    {
        if (m_provEvt->prov_type == SRV_DTCNT_PROV_TYPE_REPLACE)
        {
            // entry replace
            VappDtcntProvReplacePage *replacePage;
            VFX_OBJ_CREATE_EX(replacePage, VappDtcntProvReplacePage, this, (m_provEvt));
            getMainScr()->pushPage(0, replacePage);
        }
        else
        {
            provInstallRSP();
        }
    }
    else
    {
        provSkipRSP();
    }
}

/***************************************************************************** 
 * Class VappDtcntProvScr
 *****************************************************************************/

void VappDtcntProvScr::onInit()
{
    VfxMainScr::onInit();
}


void VappDtcntProvScr::onDeinit()
{
    VfxMainScr::onDeinit();
}


void VappDtcntProvScr::on1stReady()
{
    VappDtcntProvInstallPage *installPage;
    VFX_OBJ_CREATE_EX(installPage, VappDtcntProvInstallPage, this, (m_provEvt));
    pushPage(0, installPage);
}

/***************************************************************************** 
 * Class VappDtcntProvCui
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDtcntProvCui", VappDtcntProvCui, VfxCui);

void VappDtcntProvCui::onRun(
    void *arg,          // parameter
    VfxU32 argSize      // parameter size  
)
{
    // set provisioning ind evt
    VFX_ALLOC_MEM(m_provEvt, sizeof(srv_dtcnt_prov_ind_evt_struct), this);
    memcpy(m_provEvt, arg, sizeof(srv_dtcnt_prov_ind_evt_struct));

    // create mainsrc and pass m_cuiId and m_provEvt
    VFX_OBJ_CREATE_EX(m_mainScr, VappDtcntProvScr, this, (m_groupId, m_provEvt));
    m_mainScr->show();
}


mmi_ret VappDtcntProvCui::onProc(mmi_event_struct * evt)
{
    return MMI_RET_OK;
}


void VappDtcntProvCui::onInit()
{
    VfxCui::onInit();
}


void VappDtcntProvCui::onDeinit()
{
    if (m_provEvt)
    {
        // send abort rsp to srv
        if (m_needAbortFlag)
        {
            provAbortRSP();
        }
        VFX_FREE_MEM(m_provEvt);
    }
    VfxCui::onDeinit();
}

VfxAppCloseAnswerEnum VappDtcntProvCui::onProcessClose(VfxAppCloseOption options)
{
    VFX_UNUSED(options);
    m_needAbortFlag = VFX_TRUE;
    return VFX_APP_CLOSE_ANSWER_YES;
}

void VappDtcntProvCui::provAbortRSP()
{    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_OTA_INTALL_ABORT);
    if (m_provEvt->cnf_callback)
    {
        m_provEvt->cnf_callback(SRV_DTCNT_PROV_CNF_ABORT, m_provEvt->cur_prof_idx);
    }
}

#endif /* __CCA_SUPPORT__ */

#endif /* __TCPIP__ */
