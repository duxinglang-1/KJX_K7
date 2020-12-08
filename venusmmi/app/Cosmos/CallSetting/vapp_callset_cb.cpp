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
 *  vapp_callset.cpp
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

extern "C" 
{
#include "GlobalResDef.h"
#include "CallSetSrvGprot.h"
#include "SsSrvGprot.h" /* srv_ss_act_req */
#include "SsSrvIprot.h"
#include "NotificationGprot.h"
}

#include "mmi_rp_vapp_secset_def.h"
#include "Mmi_rp_vapp_callset_def.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vfx_signal.h"
#include "vfx_text_frame.h"

#include "vcp_confirm_popup.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"
#include "vcp_function_bar.h"

#include "vapp_callset.h"
#include "vapp_callset_cb.h"

#pragma arm section code = "DYNAMIC_CODE_CALLSET_ROCODE", rodata = "DYNAMIC_CODE_CALLSET_RODATA" 
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
 * VappCallSetPageCb
 *****************************************************************************/

void VappCallSetPageCb::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(getSize());
    form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_CALLSET_CALL_BAR);
    setTopBar(bar);

    VcpFormItemCaption *cap;
    VFX_OBJ_CREATE(cap, VcpFormItemCaption, form);
    cap->setText(STR_ID_VAPP_CALLSET_CB_OUT);
    form->addItem(cap);

    VFX_OBJ_CREATE(m_baoc, VcpFormItemSwitchCell, form);
    m_baoc->setMainText(STR_ID_VAPP_CALLSET_CB_OUT_BAOC);
    m_baoc->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCb::onSwitch);
    form->addItem(m_baoc, SRV_SS_CALL_BAR_BAOC);

    VFX_OBJ_CREATE(m_boic, VcpFormItemSwitchCell, form);
    m_boic->setMainText(STR_ID_VAPP_CALLSET_CB_OUT_BOIC);
    m_boic->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCb::onSwitch);
    form->addItem(m_boic, SRV_SS_CALL_BAR_BOIC);

    VFX_OBJ_CREATE(m_boicExHc, VcpFormItemSwitchCell, form);
    m_boicExHc->setMainText(STR_ID_VAPP_CALLSET_CB_OUT_BOICEXHC);
    m_boicExHc->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCb::onSwitch);
    form->addItem(m_boicExHc, SRV_SS_CALL_BAR_BOICEXHC);

    VFX_OBJ_CREATE(cap, VcpFormItemCaption, form);
    cap->setText(STR_ID_VAPP_CALLSET_CB_IN);
    form->addItem(cap);

    VFX_OBJ_CREATE(m_baic, VcpFormItemSwitchCell, form);
    m_baic->setMainText(STR_ID_VAPP_CALLSET_CB_IN_BAIC);
    m_baic->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCb::onSwitch);
    form->addItem(m_baic, SRV_SS_CALL_BAR_BAIC);

    VFX_OBJ_CREATE(m_baicRoam, VcpFormItemSwitchCell, form);
    m_baicRoam->setMainText(STR_ID_VAPP_CALLSET_CB_IN_BAICROAM);
    m_baicRoam->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCb::onSwitch);
    form->addItem(m_baicRoam, SRV_SS_CALL_BAR_BAICROAM);

    VcpToolBar *toolbar;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    toolbar->addItem(1, STR_ID_VAPP_CALLSET_CB_CHANGEPASS, IMG_ID_CALLSET_CHANGE_PASSWD);
    toolbar->m_signalButtonTap.connect(this, &VappCallSetPageCb::onToolBarTapped);
    setBottomBar(toolbar);

}

void VappCallSetPageCb::onEnter(VfxBool isBackward)
{
    VappCallSetAsyncPage::onEnter(isBackward);

	disableAll();
    queryData();
}

void VappCallSetPageCb::onExit(VfxBool isBackward)
{
    if (getCurrState() != STATE_NONE)
    {
        setCurrState(STATE_NONE);
        onResult(NULL);
    }

    VappCallSetAsyncPage::onExit(isBackward);

}

void VappCallSetPageCb::disableAll(void)
{
    m_baoc->setSwitchStatus(VFX_FALSE);
    m_baoc->setIsDisabled(VFX_TRUE);
    m_baoc->showProcessInd();

    m_boic->setSwitchStatus(VFX_FALSE);
    m_boic->setIsDisabled(VFX_TRUE);
    m_boic->showProcessInd();

    m_boicExHc->setSwitchStatus(VFX_FALSE);
    m_boicExHc->setIsDisabled(VFX_TRUE);
    m_boicExHc->showProcessInd();

    m_baic->setSwitchStatus(VFX_FALSE);
    m_baic->setIsDisabled(VFX_TRUE);
    m_baic->showProcessInd();

    m_baicRoam->setSwitchStatus(VFX_FALSE);
    m_baicRoam->setIsDisabled(VFX_TRUE);
    m_baicRoam->showProcessInd();
}

void VappCallSetPageCb::queryData(void)
{
    /* keep info for onResult */
    callset_p->m_inCbType = SRV_SS_CALL_BAR_BAOC;
    callset_p->m_inActType = SRV_SS_ACTION_TYPE_QUERY;

    srv_ss_call_bar_req_struct req;

    memset(&req, 0, sizeof(srv_ss_call_bar_req_struct));

    req.sim = callset_p->m_sim;
    req.source = SRV_SS_SRC_CALLSET;
    req.type = callset_p->m_inCbType;
    req.action = callset_p->m_inActType;
	
	// Only query voice call if network may can't support calltype for CB query
#ifdef	__MMI_CB_CALLTYPE_SUPPORT__
	req.call_type = SRV_SS_ALL_CALL;
#else
	req.call_type = SRV_SS_VOICE_CALL;
#endif

	
    srv_ss_act_req(
        SRV_SS_ACT_CALL_BAR, 
        &req, vapp_callset_hdlr_rsp, NULL);

    setCurrState(STATE_GET_BAOC);

}

void VappCallSetPageCb::onResult(mmi_event_struct *info)
{
    if (getCurrState() >= STATE_INVALID)
    {
        /* abnomal */
        return;
    }

    srv_ss_rsp_evt_struct *evt = (srv_ss_rsp_evt_struct*)info;
    if (evt && evt->rsp.result == SRV_SS_RESULT_ABORT)
    {
        /* abort rsp for the previous page */
        /* ignore abort rsp before checking current state */
        return;
    }

    if (getCurrState() == STATE_NONE)
    {
        /* canceled */
		VappCallSetPageAdditional::sendAbortSS();
        return;
    }

    if (!evt || evt->rsp.opcode != SRV_SS_ACT_CALL_BAR)
    {
        /* abnormal */
        /* ignore */
        return;
    }

    /* update item */
    VcpFormItemSwitchCell *swh = NULL;
    switch (getCurrState())
    {
        case STATE_GET_BAOC:
        case STATE_SET_BAOC:
            swh = m_baoc;
            break;
    
        case STATE_GET_BOIC:
        case STATE_SET_BOIC:
            swh = m_boic;
            break;
    
        case STATE_GET_BOICEXHC:
        case STATE_SET_BOICEXHC:
            swh = m_boicExHc;
            break;
    
        case STATE_GET_BAIC:
        case STATE_SET_BAIC:
            swh = m_baic;
            break;
    
        case STATE_GET_BAICROAM:
        case STATE_SET_BAICROAM:
            swh = m_baicRoam;
            break;
        
        default:
            /* abnormal */
            return;
    }

    swh->hideProcessInd();
    if (evt->rsp.result != SRV_SS_RESULT_OK)
    {
        swh->setSwitchStatus(VFX_FALSE);
    }
    else
    {
        srv_ss_call_bar_rsp_struct *cbRsp = (srv_ss_call_bar_rsp_struct*)(evt->rsp.data);

        if (!cbRsp)
        {
            return;
        }

        swh->setSwitchStatus(isOn(callset_p->m_inCbType, callset_p->m_inCallType, cbRsp));
        swh->setIsDisabled(VFX_FALSE);
    }

	// Next query
	setCurrState(nextState(getCurrState()));

	if (getCurrState() >= STATE_GET_BAOC && getCurrState()<= STATE_GET_BAICROAM)
    {
		callset_p->m_inCbType = (srv_ss_call_bar_type_enum)(SRV_SS_CALL_BAR_BAOC + (getCurrState() - STATE_GET_BAOC));

            srv_ss_call_bar_req_struct req;
            memset(&req, 0, sizeof(srv_ss_call_bar_req_struct));
            req.sim = callset_p->m_sim;
            req.source = SRV_SS_SRC_CALLSET;
            req.type = callset_p->m_inCbType;
            req.action = SRV_SS_ACTION_TYPE_QUERY;
		#ifdef	__MMI_CB_CALLTYPE_SUPPORT__
			req.call_type = SRV_SS_ALL_CALL;
		#else
			req.call_type = SRV_SS_VOICE_CALL;
		#endif
			
            srv_ss_act_req(
                SRV_SS_ACT_CALL_BAR, 
            &req, 
            vapp_callset_hdlr_rsp, 
            NULL);
	}
    }

VfxU32 VappCallSetPageCb::nextState(VfxU32 currState)
{
	return ((currState + 1) <= STATE_GET_BAICROAM) ? (currState + 1) : STATE_NONE;
}

VfxBool VappCallSetPageCb::isOn(srv_ss_call_bar_type_enum type, 
								  srv_ss_call_type_enum call_type, 
								  srv_ss_call_bar_rsp_struct *rsp)
{
    if (type != rsp->type)
    {
        return VFX_FALSE;
    }

#ifdef	__MMI_CB_CALLTYPE_SUPPORT__
	for (VfxU32 i = 0; i < rsp->result_list_count; i++)
	{
		if (srv_ss_check_call_type(callset_p->m_sim, rsp->result_list[i].bs_code, call_type))
		{
			switch (rsp->result_list[i].status)
			{
				case SRV_SS_STATUS_ACTIVATED:
				case SRV_SS_STATUS_ACTIVATED_PERMANTLY:
				case SRV_SS_STATUS_ACTIVATED_BY_DEFAULT:
				case SRV_SS_STATUS_PROVIDED:
					return VFX_TRUE;
			
				default:
					break;
			} 
		}
	}

	return VFX_FALSE;
#else /* __MMI_CB_CALLTYPE_SUPPORT__ */
	if (rsp->result_list_count == 0)
	{
		return VFX_FALSE;
	}

	switch (rsp->result_list[0].status)
	{
		case SRV_SS_STATUS_ACTIVATED:
		case SRV_SS_STATUS_ACTIVATED_PERMANTLY:
		case SRV_SS_STATUS_ACTIVATED_BY_DEFAULT:
		case SRV_SS_STATUS_PROVIDED:
			return VFX_TRUE;

		default:
			return VFX_FALSE;
	}
#endif /* __MMI_CB_CALLTYPE_SUPPORT__ */
}

void VappCallSetPageCb::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    callset_p->m_inActType = state ? SRV_SS_ACTION_TYPE_ACTIVATE : SRV_SS_ACTION_TYPE_DEACTIVATE;
    callset_p->m_inCbType = (srv_ss_call_bar_type_enum)id;

    VappCallSetPageCbPasswd *pageCbPasswd;
    VFX_OBJ_CREATE(pageCbPasswd, VappCallSetPageCbPasswd, getMainScr());
    getMainScr()->pushPage(VFX_ID_NULL, pageCbPasswd);
}

void VappCallSetPageCb::onToolBarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 1:
            callset_p->m_inActType = SRV_SS_ACTION_TYPE_TOTAL;
            VappCallSetPageCbChangePasswd *pageCbChangePasswd;
            VFX_OBJ_CREATE(pageCbChangePasswd, VappCallSetPageCbChangePasswd, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCbChangePasswd);
            break;
    }
}



void VappCallSetPageCbPasswd::onInit()
{
    VappCallSetPageCommonInputAsync::onInit(); // call base class

    m_titleBar->setTitle(STR_ID_VAPP_CALLSET_CB_INPUT_PASSWD);

    m_mainText->setString(STR_ID_VAPP_CALLSET_CB_PASSWD);
    
    m_textInput->setIME(IMM_INPUT_TYPE_NUMERIC_PASSWORD);

    setInputBuf(SRV_SS_PASSWORD_MAX_LENTH, VFX_WSTR_EMPTY);    
}


void VappCallSetPageCbPasswd::onExit(VfxBool isBackward)
{
    if (getCurrState() == STATE_ACT)
    {
        setCurrState(STATE_NONE);
        onResult(NULL);
    }

    VappCallSetPageCommonInputAsync::onExit(isBackward);

}

void VappCallSetPageCbPasswd::onTextChanged(VcpTextEditor* editor)
{
    if (mmi_ucs2strlen((CHAR *)m_textInput->getText()) != SRV_SS_PASSWORD_MAX_LENTH)
    {
        m_funcBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
        m_toolBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
    }
    else
    {
        m_funcBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
        m_toolBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
    }
}

void VappCallSetPageCbPasswd::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_OK:
        {
            srv_ss_call_bar_req_struct req;
            memset(&req, 0, sizeof(srv_ss_call_bar_req_struct));
            req.sim = callset_p->m_sim;
            req.source = SRV_SS_SRC_CALLSET;
            req.type = callset_p->m_inCbType;
            req.action = callset_p->m_inActType;
			req.call_type = callset_p->m_inCallType ;
            mmi_ucs2ncpy((CHAR *)req.password_old, (CHAR *)m_textInput->getText(),
                SRV_SS_PASSWORD_MAX_LENTH);
            srv_ss_act_req(
                SRV_SS_ACT_CALL_BAR, 
                &req, vapp_callset_hdlr_rsp, NULL);
            setCurrState(STATE_ACT);
            showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_TRUE);
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }

}

void VappCallSetPageCbPasswd::onResult(mmi_event_struct *info)
{
    if (getCurrState() >= STATE_INVALID)
    {
        /* abnormal */
        return;
    }

    srv_ss_rsp_evt_struct *evt = (srv_ss_rsp_evt_struct*)info;
    if (evt && evt->rsp.result == SRV_SS_RESULT_ABORT)
    {
        /* abort rsp for the previous page */
        /* ignore abort rsp before checking current state */
        return;
    }

    if (getCurrState() == STATE_NONE)
    {
        /* canceled */
		VappCallSetPageAdditional::sendAbortSS();
        leaveWaitPopup();
        return;
    }

    if (!evt || evt->rsp.opcode != SRV_SS_ACT_CALL_BAR)
    {
        /* abnormal*/
        /* ignore */
        return;
    }

    if (evt->rsp.result != SRV_SS_RESULT_OK)
    {
        VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_ss_get_result_string(evt->rsp.result)));
    }

    leaveWaitPopup();
    setCurrState(STATE_NONE);

    if (evt->rsp.result == SRV_SS_RESULT_OK)
    {
        getMainScr()->popPage();
    }
}



void VappCallSetPageCbChangePasswd::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    m_stateEdit = STATE_EDIT_INVALID;

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_CALLSET_CB_CHANGEPASS);
    setTopBar(titleBar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(getSize());
    form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    /* toolbar shall be created before editor in order to setDisable in onTextChanged */
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(VAPP_CALLSET_FUNC_OK, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem(VAPP_CALLSET_FUNC_CANCEL, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageCbChangePasswd::onFuncBtnClicked);
    setBottomBar(m_toolBar);

    VcpFormItemTextInput *textInput;
    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    textInput->setLabelText(STR_ID_VAPP_CALLSET_CB_PASSWD_OLD);
    m_oldPass = textInput->getTextBox();

    VFX_OBJ_CREATE(m_oldFb, VcpFunctionBar, m_oldPass);
    m_oldFb->addItem((VfxResId)STR_GLOBAL_OK, (VfxId)VAPP_CALLSET_FUNC_OK);
    m_oldFb->addItem((VfxResId)STR_ID_VAPP_CALLSET_PREV, (VfxId)VAPP_CALLSET_FUNC_PREV);
    m_oldFb->addItem((VfxResId)STR_ID_VAPP_CALLSET_NEXT, (VfxId)VAPP_CALLSET_FUNC_NEXT);
    m_oldFb->setItemSpecial(VAPP_CALLSET_FUNC_OK);
    m_oldFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
    m_oldFb->setDisableItem(VAPP_CALLSET_FUNC_PREV, VFX_TRUE);
    m_oldFb->m_signalButtonTap.connect(this, &VappCallSetPageCbChangePasswd::onFuncBtnClicked);
    m_oldPass->setFunctionBar(m_oldFb);

    form->addItem(textInput, 1);


    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    textInput->setLabelText(STR_ID_VAPP_CALLSET_CB_PASSWD_NEW);
    m_newPass = textInput->getTextBox();

    VFX_OBJ_CREATE(m_newFb, VcpFunctionBar, m_newPass);
    m_newFb->addItem((VfxResId)STR_GLOBAL_OK, (VfxId)VAPP_CALLSET_FUNC_OK);
    m_newFb->addItem((VfxResId)STR_ID_VAPP_CALLSET_PREV, (VfxId)VAPP_CALLSET_FUNC_PREV);
    m_newFb->addItem((VfxResId)STR_ID_VAPP_CALLSET_NEXT, (VfxId)VAPP_CALLSET_FUNC_NEXT);
    m_newFb->setItemSpecial(VAPP_CALLSET_FUNC_OK);
    m_newFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
    m_newFb->m_signalButtonTap.connect(this, &VappCallSetPageCbChangePasswd::onFuncBtnClicked);
    m_newPass->setFunctionBar(m_newFb);

    form->addItem(textInput, 2);


    VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, form);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);
    textInput->setLabelText(STR_ID_VAPP_CALLSET_CB_PASSWD_CNF);
    m_cnfPass = textInput->getTextBox();

    VFX_OBJ_CREATE(m_cnfFb, VcpFunctionBar, m_cnfPass);
    m_cnfFb->addItem((VfxResId)STR_GLOBAL_OK, (VfxId)VAPP_CALLSET_FUNC_OK);
    m_cnfFb->addItem((VfxResId)STR_ID_VAPP_CALLSET_PREV, (VfxId)VAPP_CALLSET_FUNC_PREV);
    m_cnfFb->addItem((VfxResId)STR_ID_VAPP_CALLSET_NEXT, (VfxId)VAPP_CALLSET_FUNC_NEXT);
    m_cnfFb->setItemSpecial(VAPP_CALLSET_FUNC_OK);
    m_cnfFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
    m_cnfFb->setDisableItem(VAPP_CALLSET_FUNC_NEXT, VFX_TRUE);
    m_cnfFb->m_signalButtonTap.connect(this, &VappCallSetPageCbChangePasswd::onFuncBtnClicked);
    m_cnfPass->setFunctionBar(m_cnfFb);

    form->addItem(textInput, 3);

    m_oldPass->m_signalTextChanged.connect(this, &VappCallSetPageCbChangePasswd::onTextChanged); 
    m_oldPass->setIME(IMM_INPUT_TYPE_NUMERIC_PASSWORD);

    m_newPass->m_signalTextChanged.connect(this, &VappCallSetPageCbChangePasswd::onTextChanged); 
    m_newPass->setIME(IMM_INPUT_TYPE_NUMERIC_PASSWORD);

    m_cnfPass->m_signalTextChanged.connect(this, &VappCallSetPageCbChangePasswd::onTextChanged); 
    m_cnfPass->setIME(IMM_INPUT_TYPE_NUMERIC_PASSWORD);

	clearInput();
}

void VappCallSetPageCbChangePasswd::onExit(VfxBool isBackward)
{
    if (getCurrState() == STATE_ACT)
    {
        setCurrState(STATE_NONE);
        onResult(NULL);
    }

    VappCallSetAsyncPage::onExit(isBackward);

}

void VappCallSetPageCbChangePasswd::onTextChanged(VcpTextEditor* editor)
{
    if (mmi_wcslen(editor->getText()) != SRV_SS_PASSWORD_MAX_LENTH)
    {
        if (editor == m_oldPass)
        {
            m_stateEdit &= ~STATE_EDIT_VALID_1;
        }
        else if (editor == m_newPass)
        {
            m_stateEdit &= ~STATE_EDIT_VALID_2;
        }
        else if (editor == m_cnfPass)
        {
            m_stateEdit &= ~STATE_EDIT_VALID_3;
        }

        m_oldFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
        m_newFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
        m_cnfFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
        m_toolBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
    }
    else
    {
        if (editor == m_oldPass)
        {
            m_stateEdit |= STATE_EDIT_VALID_1;
        }
        else if (editor == m_newPass)
        {
            m_stateEdit |= STATE_EDIT_VALID_2;
        }
        else if (editor == m_cnfPass)
        {
            m_stateEdit |= STATE_EDIT_VALID_3;
        }

        if (m_stateEdit == STATE_EDIT_VALID_ALL)
        {
            m_oldFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
            m_newFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
            m_cnfFb->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
            m_toolBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
        }
    }
}

void VappCallSetPageCbChangePasswd::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_CANCEL:
            getMainScr()->popPage();
            break;

        case VAPP_CALLSET_FUNC_OK:
        {
			if (!checkPwd())
			{
				break;
			}
			
            srv_ss_call_bar_req_struct req;
            //memset(&req, 0, sizeof(srv_ss_call_bar_req_struct));
			
            req.sim = callset_p->m_sim;
            req.source = SRV_SS_SRC_CALLSET;
            req.type = SRV_SS_CALL_BAR_BAC;
            req.action = SRV_SS_ACTION_TYPE_CHANGE_PASSWD;
            mmi_ucs2ncpy((CHAR *)req.password_old, (CHAR *)m_oldPass->getText(),
                SRV_SS_PASSWORD_MAX_LENTH);
            mmi_ucs2ncpy((CHAR *)req.password_new, (CHAR *)m_newPass->getText(),
                SRV_SS_PASSWORD_MAX_LENTH);
            mmi_ucs2ncpy((CHAR *)req.password_cnf, (CHAR *)m_cnfPass->getText(),
                SRV_SS_PASSWORD_MAX_LENTH);
			req.call_type = callset_p->m_inCallType ;
			
            srv_ss_act_req(
                SRV_SS_ACT_CALL_BAR, 
                &req, vapp_callset_hdlr_rsp, NULL);
            setCurrState(STATE_ACT);
            showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_TRUE);
            break;
        }

        case VAPP_CALLSET_FUNC_PREV:
        {
            if (sender == m_newFb)
            {
                m_newPass->deactivate();
                m_oldPass->activate();
            }
            else if (sender == m_cnfFb)
            {
                m_cnfPass->deactivate();
                m_newPass->activate();
            }
            break;
        }

        case VAPP_CALLSET_FUNC_NEXT:
        {
            if (sender == m_oldFb)
            {
                m_oldPass->deactivate();
                m_newPass->activate();
            }
            else if (sender == m_newFb)
            {
                m_newPass->deactivate();
                m_cnfPass->activate();
            }
            break;
        }
    }
}


VfxBool VappCallSetPageCbChangePasswd::checkPwd(void)
{
	if (vfx_sys_wcscmp(m_newPass->getText(), m_cnfPass->getText()) != 0)
	{
		VcpConfirmPopup *cnfPop;
		VFX_OBJ_CREATE(cnfPop, VcpConfirmPopup, this);
		cnfPop->setInfoType(VCP_POPUP_TYPE_FAILURE);
		cnfPop->setText(STR_ID_VAPP_SECSET_DIFF_NEW_PHONE_PASSWORD);
		cnfPop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		cnfPop->show(VFX_TRUE);
		cnfPop->m_signalButtonClicked.connect(this, &VappCallSetPageCbChangePasswd::onDiffInputConfirmed);

		return VFX_FALSE;
	}

	return VFX_TRUE;
}

void VappCallSetPageCbChangePasswd::onDiffInputConfirmed(VfxObject *obj, VfxId id)
{
    m_newPass->setText(VFX_WSTR_EMPTY, SRV_SS_PASSWORD_MAX_LENTH);
    m_cnfPass->setText(VFX_WSTR_EMPTY, SRV_SS_PASSWORD_MAX_LENTH);
	m_newPass->activate(VFX_TRUE);
}

void VappCallSetPageCbChangePasswd::clearInput(void)
{
    m_oldPass->setText(VFX_WSTR_EMPTY, SRV_SS_PASSWORD_MAX_LENTH);
    m_newPass->setText(VFX_WSTR_EMPTY, SRV_SS_PASSWORD_MAX_LENTH);
    m_cnfPass->setText(VFX_WSTR_EMPTY, SRV_SS_PASSWORD_MAX_LENTH);
}

void VappCallSetPageCbChangePasswd::onResult(mmi_event_struct *info)
{
    if (getCurrState() >= STATE_INVALID)
    {
        /* abnormal */
        return;
    }

    srv_ss_rsp_evt_struct *evt = (srv_ss_rsp_evt_struct*)info;
    if (evt && evt->rsp.result == SRV_SS_RESULT_ABORT)
    {
        /* abort rsp for the previous page */
        /* ignore abort rsp before checking current state */
        return;
    }

    if (getCurrState() == STATE_NONE)
    {
        /* canceled */
		VappCallSetPageAdditional::sendAbortSS();
        leaveWaitPopup();
        return;
    }

    if (!evt || evt->rsp.opcode != SRV_SS_ACT_CALL_BAR)
    {
        /* abnormal*/
        /* ignore */
        return;
    }

    if (evt->rsp.result != SRV_SS_RESULT_OK)
    {
        VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_ss_get_result_string(evt->rsp.result)));
    }

    leaveWaitPopup();
    setCurrState(STATE_NONE);

    if (evt->rsp.result == SRV_SS_RESULT_OK)
    {
        getMainScr()->popPage();
    }
}

#pragma arm section code, rodata
