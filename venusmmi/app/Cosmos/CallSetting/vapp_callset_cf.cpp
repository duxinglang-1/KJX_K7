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
 *  vapp_callset_cf.cpp
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
#include "Custom_phb_config.h" /* MMI_PHB_NUMBER_PLUS_LENGTH */
#include "NotificationGprot.h"
}

#include "Mmi_rp_vapp_callset_def.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"

#include "App_str.h" /* app_ucs2_itoa */

#include "vfx_signal.h"
#include "vfx_text_frame.h"

#include "vcp_confirm_popup.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"
#include "vcp_function_bar.h"


#include "Vcui_phb_gprot.h"

#include "vapp_callset_cf.h"

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
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappCallSetPageCf Implementation
 *****************************************************************************/
const VfxResId VappCallSetPageCf::s_callTypeRes[SRV_SS_ALL_CALL] = 
{
	STR_ID_VAPP_CALLSET_VOICE,
#ifdef __MMI_VIDEO_TELEPHONY__
	STR_ID_VAPP_CALLSET_VIDEO,
#else
	0,
#endif
	STR_ID_VAPP_CALLSET_DATA
};

VappCallSetPageCf::VappCallSetPageCf()
	: m_cfu(NULL),
	  m_cfnrc(NULL),
	  m_cfnry(NULL),
	  m_cfnryTime(NULL),
	  m_cfb(NULL),
	  m_waitState(STATE_NONE)
{

}
void VappCallSetPageCf::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VappCallSetPageCf::s_callTypeRes[callset_p->m_inCallType]);
    setTopBar(bar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(getSize());
    form->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);

	VFX_OBJ_CREATE(m_cfu, VcpFormItemSwitchCell, form);
	m_cfu->setMainText(STR_ID_VAPP_CALLSET_CFU);
	m_cfu->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCf::onSwitch);
	form->addItem(m_cfu, 1);

    if ((callset_p->m_inCallType == SRV_SS_VIDEO_CALL) ||
		(callset_p->m_inCallType == SRV_SS_VOICE_CALL))
    {
        VFX_OBJ_CREATE(m_cfnrc, VcpFormItemSwitchCell, form);
        m_cfnrc->setMainText(STR_ID_VAPP_CALLSET_CFNRC);
        m_cfnrc->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCf::onSwitch);
        form->addItem(m_cfnrc, 2);

        VFX_OBJ_CREATE(m_cfnry, VcpFormItemSwitchCell, form);
        m_cfnry->setMainText(STR_ID_VAPP_CALLSET_CFNRY);
        m_cfnry->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCf::onSwitch);
        form->addItem(m_cfnry, 3);

        VFX_OBJ_CREATE(m_cfnryTime, VcpFormItemLauncherCell, form);
        m_cfnryTime->setMainText(STR_ID_VAPP_CALLSET_CFNRY_TIME);
        m_cfnryTime->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_cfnryTime->m_signalTap.connect(this, &VappCallSetPageCf::onItemTap);
        form->addItem(m_cfnryTime, 4);

        VFX_OBJ_CREATE(m_cfb, VcpFormItemSwitchCell, form);
        m_cfb->setMainText(STR_ID_VAPP_CALLSET_CFB);
        m_cfb->m_signalSwitchChangeReq.connect(this, &VappCallSetPageCf::onSwitch);
        form->addItem(m_cfb, 5);
	}


    VcpToolBar *toolbar;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    toolbar->addItem(1, STR_ID_VAPP_CALLSET_CF_EDIT, VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
    toolbar->m_signalButtonTap.connect(this, &VappCallSetPageCf::onToolBarTapped);
    setBottomBar(toolbar);

}

void VappCallSetPageCf::onEnter(VfxBool isBackward)
{
    VappCallSetAsyncPage::onEnter(isBackward);

    queryData();
}

void VappCallSetPageCf::onExit(VfxBool isBackward)
{
    if (getCurrState() != STATE_NONE)
    {
        setCurrState(STATE_NONE);
        onResult(NULL);
    }

    VappCallSetAsyncPage::onExit(isBackward);
}

void VappCallSetPageCf::queryData(void)
{  
    /* reset all */
	disableSwitchItem(m_cfu, callset_p->m_cfuNum);
	
    if ((callset_p->m_inCallType == SRV_SS_VOICE_CALL) ||
		(callset_p->m_inCallType == SRV_SS_VIDEO_CALL))
    {			
		disableSwitchItem(m_cfnrc, callset_p->m_cfnrcNum);
		disableSwitchItem(m_cfnry, callset_p->m_cfnryNum);	

		VfxWString tmpStr;
		callset_p->m_cfnryTime = 5;
		tmpStr.format("%d", callset_p->m_cfnryTime);
        tmpStr += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_SECS);
        m_cfnryTime->setHintText(tmpStr);
        m_cfnryTime->setIsDisabled(VFX_TRUE);

		disableSwitchItem(m_cfb, callset_p->m_cfbNum);	
    }	

    /* keep the info for onResult */
    callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFU;
    callset_p->m_inActType = SRV_SS_ACTION_TYPE_QUERY;

	VappCallSetPageCf::sendSSReq(
		callset_p->m_inActType,
		NULL,
		0);

    setCurrState(STATE_GET_CFU);

}

VfxU32 VappCallSetPageCf::nextState(VfxU32 currState)
{
	// Data call only has the first state
	if ((currState <= STATE_GET_CFNRY) &&
		(callset_p->m_inCallType != SRV_SS_DATA_CALL))
	{
		return (currState + 1);
	}

	return STATE_NONE;
}

void VappCallSetPageCf::nextQuery(VfxU32 state)
{
	srv_ss_call_forward_type_enum fwdType[] = 
    {
		SRV_SS_CALL_FORWARD_TYPE_UNKNOWN, /* STATE_NONE  = 0 */
		SRV_SS_CALL_FORWARD_CFU,		  /* STATE_GET_CFU  = 1 */
		SRV_SS_CALL_FORWARD_CFNRC,		  /* STATE_GET_CFNRC  = 2 */
		SRV_SS_CALL_FORWARD_CFNRY,		  /* STATE_GET_CFNRY  = 3 */
		SRV_SS_CALL_FORWARD_CFB			  /* STATE_GET_CFB  = 4 */
	};
            
	callset_p->m_inCfType = fwdType[state];

    /* next query */
    if ((state >= STATE_GET_CFU) && (state <= STATE_GET_CFB))
    {
		VappCallSetPageCf::sendSSReq(SRV_SS_ACTION_TYPE_QUERY, NULL, 0);
    }
}

VfxBool VappCallSetPageCf::checkWaitState(void)
{
    /* decide next move */
    VfxU32 next = nextState(getCurrState());

    switch (m_waitState)
    {
        case STATE_SET_CFU:
        case STATE_SET_CFNRC:
        case STATE_SET_CFNRY:
        case STATE_SET_CFB:
            /* since number and no_reply_time is not changed, don't need to carry to the network in deactivate scenarios */

			VappCallSetPageCf::sendSSReq(callset_p->m_inActType, NULL, 0);
			
            setCurrState(m_waitState);

            /* keep the original next move */
            m_waitState = next;
            
            if (m_waitState == STATE_NONE)
            {
                /* since only one waiting op is allowed, 
                    recover the disable state of all items only when there is no next waiting op */
                enableItems();
            }
            return VFX_TRUE;

        case STATE_GET_CFU:
        case STATE_GET_CFNRC:
        case STATE_GET_CFNRY:
        case STATE_GET_CFB:
            next = m_waitState;
            m_waitState = STATE_NONE;
            break;
    }

    /* take the next move when there is no waiting action */
    setCurrState(next);

	return VFX_FALSE;
}

void VappCallSetPageCf::onResult(mmi_event_struct *info)
{
    if (getCurrState() >= STATE_INVALID)
    {
    	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_CALLSET_CF_ONRESULT_RET, __LINE__);    	
        /* abnomal */
        return;
    }

    srv_ss_rsp_evt_struct *evt = (srv_ss_rsp_evt_struct*)info;
	
    if ((evt != NULL) && evt->rsp.result == SRV_SS_RESULT_ABORT)
    {
    	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_CALLSET_CF_ONRESULT_RET, __LINE__);
        /* ignore abort rsp before checking current state */
        return;
    }
	
    if (getCurrState() == STATE_NONE)
    {
        /* canceled, evt is NULL */
		VappCallSetPageAdditional::sendAbortSS();

        m_waitState = STATE_NONE;
        return;
    }

    if (!evt || evt->rsp.opcode != SRV_SS_ACT_CALL_FORWARD)
    {
    	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_CALLSET_CF_ONRESULT_RET, __LINE__);   
        /* abnormal*/
        /* ignore */
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, 
			  VAPP_CALLSET_CF_ONRESULT, 
			  getCurrState(),
			  m_waitState,
			  evt->rsp.result,
			  evt->rsp.opcode);
    
    /* update item */
    VcpFormItemSwitchCell *swh = NULL;
    VfxU32 *time = NULL;
    srv_ss_call_forward_type_enum oriCfType = callset_p->m_inCfType;
    /* CfType may be changed by the waiting operation, restore it for deriveRes() */
    switch (getCurrState())
    {
        case STATE_GET_CFU:
        case STATE_SET_CFU:
            swh = m_cfu;
            callset_p->m_inCfNum = &(callset_p->m_cfuNum);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFU;
            break;
    
        case STATE_GET_CFNRC:
        case STATE_SET_CFNRC:
            swh = m_cfnrc;
            callset_p->m_inCfNum = &(callset_p->m_cfnrcNum);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFNRC;
            break;
    
        case STATE_GET_CFNRY:
        case STATE_SET_CFNRY:
            swh = m_cfnry;
            callset_p->m_inCfNum = &(callset_p->m_cfnryNum);
            time = &(callset_p->m_cfnryTime);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFNRY;
            break;
    
        case STATE_GET_CFB:
        case STATE_SET_CFB:
            swh = m_cfb;
            callset_p->m_inCfNum = &(callset_p->m_cfbNum);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFB;
            break;
			
        default:
            /* abnormal */
            return;
    }

    swh->hideProcessInd();
    if (evt->rsp.result != SRV_SS_RESULT_OK)
    {
        swh->setSwitchStatus(VFX_FALSE);
        swh->setHintText(STR_ID_VAPP_CALLSET_UNKNOWN);
    }
    else
    {
        /* update the item */
        deriveRes((srv_ss_call_forward_rsp_struct*)(evt->rsp.data), swh, time);
    }
    callset_p->m_inCfType = oriCfType;

	// Handle waiting operation
	if (checkWaitState())
	{
		MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_CALLSET_CF_ONRESULT_RET, __LINE__);   
		return;
	}
	
    /* since only one waiting op is allowed, 
        recover the disable state of all items only when there is no next waiting op */
    enableItems();

	nextQuery(getCurrState());
}

void VappCallSetPageCf::deriveRes(srv_ss_call_forward_rsp_struct *rsp, VcpFormItemSwitchCell *swh, VfxU32 *time)
{
    if (!rsp || !swh ||
        (callset_p->m_inCfType != rsp->type))
    {
        return;
    }

    /* derive status */
    VfxBool isOn;
    if (!rsp->result_list_count)
    {
        isOn = VFX_FALSE;
    }
    else
    {
        switch (rsp->result_list[0].status)
        {
            case SRV_SS_STATUS_ACTIVATED:
            case SRV_SS_STATUS_ACTIVATED_PERMANTLY:
            case SRV_SS_STATUS_ACTIVATED_BY_DEFAULT:
            case SRV_SS_STATUS_PROVIDED:
                isOn = VFX_TRUE;
                break;
        
            default:
                isOn = VFX_FALSE;
                break;
        }
    }

    /* derive time */
    if (time)
    {
        if (rsp->result_list[0].no_reply_timer)
        {
            *time = rsp->result_list[0].no_reply_timer;
        }
        else
        {
            *time = 5;
        }

        VfxWString tmpStr;

		tmpStr.format("%d", *time);
        tmpStr += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_SECS);

        if (callset_p->m_inCallType == SRV_SS_VOICE_CALL ||
			callset_p->m_inCallType == SRV_SS_VIDEO_CALL)
        {
            m_cfnryTime->setHintText(tmpStr);
        }
    }

    /* derive number */
    if (callset_p->m_inCfNum)
    {
        *(callset_p->m_inCfNum) = VFX_WSTR_MEM(rsp->result_list[0].number);
    }

    /* update item */
    swh->setSwitchStatus(isOn);
    swh->setHintText(isOn ?
           *(callset_p->m_inCfNum) : VFX_WSTR_RES(STR_ID_VAPP_CALLSET_DEACTIVATED));

}

void VappCallSetPageCf::enableItems(void)
{
    switch (callset_p->m_inCallType)
    {
        case SRV_SS_VOICE_CALL:
		case SRV_SS_VIDEO_CALL:
        {
            if (m_cfnrc->getHintText() != VFX_WSTR_RES(STR_ID_VAPP_CALLSET_UNKNOWN))
            {
                m_cfnrc->setIsDisabled(VFX_FALSE);
            }
            if (m_cfnry->getHintText() != VFX_WSTR_RES(STR_ID_VAPP_CALLSET_UNKNOWN))
            {
                m_cfnry->setIsDisabled(VFX_FALSE);
                m_cfnryTime->setIsDisabled(VFX_FALSE);
            }
            if (m_cfb->getHintText() != VFX_WSTR_RES(STR_ID_VAPP_CALLSET_UNKNOWN))
            {
                m_cfb->setIsDisabled(VFX_FALSE);
            }
        }
    
    	// go through
        case SRV_SS_DATA_CALL:
        {
            if (m_cfu->getHintText() != VFX_WSTR_RES(STR_ID_VAPP_CALLSET_UNKNOWN))
            {
                m_cfu->setIsDisabled(VFX_FALSE);
            }
            break;
        }
    }
}

void VappCallSetPageCf::disableSwitchItem(VcpFormItemSwitchCell *cell, VfxWString &text)
{
	cell->setSwitchStatus(VFX_FALSE);
	cell->setHintText(STR_ID_VAPP_CALLSET_UNKNOWN);
	cell->setIsDisabled(VFX_TRUE);
	cell->showProcessInd();
	
	text.setEmpty();
}

void VappCallSetPageCf::onItemTap(VcpFormItemCell *item, VfxId id)
{
    callset_p->m_inActType = SRV_SS_ACTION_TYPE_TOTAL;

    if (id == 4)
    {
		callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFNRY;
		callset_p->m_inCfNum = &(callset_p->m_cfnryNum);
    }
	else
	{
		return;
	}

    VappCallSetPageCfnryTime *pageCfnryTime;
    VFX_OBJ_CREATE(pageCfnryTime, VappCallSetPageCfnryTime, getMainScr());
    getMainScr()->pushPage(VFX_ID_NULL, pageCfnryTime);

}

void VappCallSetPageCf::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    callset_p->m_inActType = state ? SRV_SS_ACTION_TYPE_ACTIVATE : SRV_SS_ACTION_TYPE_DEACTIVATE;

    VfxU32 next;
    switch (id)
    {
        case 1:
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFU;
            callset_p->m_inCfNum = &(callset_p->m_cfuNum);
            next = STATE_SET_CFU;
            break;

        case 2:
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFNRC;
            callset_p->m_inCfNum = &(callset_p->m_cfnrcNum);
            next = STATE_SET_CFNRC;
            break;

        case 3:
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFNRY;
            callset_p->m_inCfNum = &(callset_p->m_cfnryNum);
            next = STATE_SET_CFNRY;
            break;

        case 5:
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFB;
            callset_p->m_inCfNum = &(callset_p->m_cfbNum);
            next = STATE_SET_CFB;
            break;

        default:
            return;
    }

    /* disable all items */
    switch (callset_p->m_inCallType)
    {
        case SRV_SS_VOICE_CALL:
		case SRV_SS_VIDEO_CALL:
        {
            m_cfnrc->setIsDisabled(VFX_TRUE);
            m_cfnry->setIsDisabled(VFX_TRUE);
            m_cfnryTime->setIsDisabled(VFX_TRUE);
            m_cfb->setIsDisabled(VFX_TRUE);
        }
		// go thru to next case
        case SRV_SS_DATA_CALL:
        {
            m_cfu->setIsDisabled(VFX_TRUE);
            break;
        }
    }

    item->setSwitchStatus(VFX_FALSE);
    item->setHintText(STR_ID_VAPP_CALLSET_UNKNOWN);
    item->showProcessInd();

    if (callset_p->m_inActType == SRV_SS_ACTION_TYPE_ACTIVATE)
    {
        VappCallSetPageCfNumEdit *pageCfNum;
        VFX_OBJ_CREATE(pageCfNum, VappCallSetPageCfNumEdit, getMainScr());
        getMainScr()->pushPage(VFX_ID_NULL, pageCfNum);
    }
    else if (getCurrState() != STATE_NONE)
    {
        m_waitState = next;
        /* wait for the current op to finish */
        /* don't abort the current op to prevent from the race condition of rsp */
    }
    else
    {
        item->setIsDisabled(VFX_TRUE);
        item->showProcessInd();
		
		VappCallSetPageCf::sendSSReq(callset_p->m_inActType, NULL, 0);
        /* since number and no_reply_time is not changed, don't need to carry to the network in deactivate scenarios */
        setCurrState(next);
    }
}

void VappCallSetPageCf::onToolBarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 1:
            callset_p->m_inActType = SRV_SS_ACTION_TYPE_TOTAL;
            VappCallSetPageCfNum *pageCfNum;
            VFX_OBJ_CREATE(pageCfNum, VappCallSetPageCfNum, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCfNum);
            break;
    }
}

void VappCallSetPageCf::sendSSReq(srv_ss_action_type_enum action, const VfxWChar *numPtr, VfxU32 noReplyTime)
{
	srv_ss_call_forward_req_struct req;

	req.sim = callset_p->m_sim;
	req.source = SRV_SS_SRC_CALLSET;
	req.type = callset_p->m_inCfType;
	req.call_type = callset_p->m_inCallType;
	req.action = action;

	if (callset_p->m_inCfType == SRV_SS_CALL_FORWARD_CFNRY)
	{
		req.no_reply_timer = noReplyTime;
	}
	else
	{
	req.no_reply_timer = 0;
}

	if (action == SRV_SS_ACTION_TYPE_ACTIVATE)
	{
		mmi_wcsncpy(req.forward_number, numPtr,	SRV_SS_MAX_FWD_ADDR_LEN);
	}
	else
	{
		req.forward_number[0] = req.forward_number[1] = 0;
	}	

    srv_ss_act_req(
	    SRV_SS_ACT_CALL_FORWARD, 
    	&req, 
    	vapp_callset_hdlr_rsp, 
    	NULL);
}


/***************************************************************************** 
 * Class VappCallSetPageCfNum Implementation
 *****************************************************************************/
void VappCallSetPageCfNum::onInit()
{
    VfxPage::onInit(); // call base class

    m_form = NULL;
    updateForm();
}

void VappCallSetPageCfNum::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (isBackward)
    {
        updateForm();
    }
}

void VappCallSetPageCfNum::updateForm(void)
{
    if (m_form)
    {
        VFX_OBJ_CLOSE(m_form);
    }

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    VfxWString tmp_str;
    switch (callset_p->m_inCallType)
    {
        case SRV_SS_VOICE_CALL:
            tmp_str.loadFromRes(STR_ID_VAPP_CALLSET_VOICE_2);
            break;

    #ifdef __MMI_VIDEO_TELEPHONY__
        case SRV_SS_VIDEO_CALL:
            tmp_str.loadFromRes(STR_ID_VAPP_CALLSET_VIDEO_2);
            break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */

        case SRV_SS_DATA_CALL:
            tmp_str.loadFromRes(STR_ID_VAPP_CALLSET_DATA_2);
            break;
    }
    tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CF_NUM);

    bar->setTitle(tmp_str);
    setTopBar(bar);


    VcpFormItemLauncherCell *launch;

    switch (callset_p->m_inCallType)
    {
        case SRV_SS_VOICE_CALL:
		case SRV_SS_VIDEO_CALL:
        {            
            VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
            launch->setMainText(STR_ID_VAPP_CALLSET_CFNRC);
            launch->setHintText(
                callset_p->m_cfnrcNum.getLength() ? 
                    callset_p->m_cfnrcNum : VFX_WSTR_RES(STR_GLOBAL_NONE));
            launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            launch->m_signalTap.connect(this, &VappCallSetPageCfNum::onItemTap);
            m_form->addItem(launch, 2);
            
            VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
            launch->setMainText(STR_ID_VAPP_CALLSET_CFNRY);
            launch->setHintText(
                callset_p->m_cfnryNum.getLength() ? 
                    callset_p->m_cfnryNum : VFX_WSTR_RES(STR_GLOBAL_NONE));
            launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            launch->m_signalTap.connect(this, &VappCallSetPageCfNum::onItemTap);
            m_form->addItem(launch, 3);
            
            VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
            launch->setMainText(STR_ID_VAPP_CALLSET_CFB);
            launch->setHintText(
                callset_p->m_cfbNum.getLength() ? 
                    callset_p->m_cfbNum : VFX_WSTR_RES(STR_GLOBAL_NONE));
            launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            launch->m_signalTap.connect(this, &VappCallSetPageCfNum::onItemTap);
            m_form->addItem(launch, 4);
        }
		// go thru
        case SRV_SS_DATA_CALL:
        {
            VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
            launch->setMainText(STR_ID_VAPP_CALLSET_CFU);
            launch->setHintText(
                callset_p->m_cfuNum.getLength() ? 
                    callset_p->m_cfuNum : VFX_WSTR_RES(STR_GLOBAL_NONE));
            launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            launch->m_signalTap.connect(this, &VappCallSetPageCfNum::onItemTap);
            m_form->addItem(launch, 1);

            break;
        }
    }

}

void VappCallSetPageCfNum::onItemTap(VcpFormItemCell *item, VfxId id)
{
    callset_p->m_inActType = SRV_SS_ACTION_TYPE_TOTAL;

    switch (id)
    {
        case 1:
            callset_p->m_inCfNum = &(callset_p->m_cfuNum);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFU;
            break;

        case 2:
            callset_p->m_inCfNum = &(callset_p->m_cfnrcNum);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFNRC;
            break;

        case 3:
            callset_p->m_inCfNum = &(callset_p->m_cfnryNum);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFNRY;
            break;

        case 4:
            callset_p->m_inCfNum = &(callset_p->m_cfbNum);
            callset_p->m_inCfType = SRV_SS_CALL_FORWARD_CFB;
            break;


        default:
            return;
    }

    VappCallSetPageCfNumEdit *pageCfNumEdit;
    VFX_OBJ_CREATE(pageCfNumEdit, VappCallSetPageCfNumEdit, getMainScr());
    getMainScr()->pushPage(VFX_ID_NULL, pageCfNumEdit);
}



void VappCallSetPageCfNumEdit::onInit()
{
    VFX_ASSERT(callset_p->m_inCfNum);

    m_phbId = NULL;

    VappCallSetPageCommonInputAsync::onInit(); // call base class

    m_titleBar->setTitle(STR_ID_VAPP_CALLSET_CF_INPUT_NUM);

    m_mainText->setString(STR_ID_VAPP_CALLSET_CF_TO);
    
    m_textInput->setIME(IMM_INPUT_TYPE_SIM_NUMERIC, IME_PLUS_CHAR_HANDLING);
    setInputBuf(SRV_SS_MAX_FWD_ADDR_LEN - 1, *(callset_p->m_inCfNum));

    m_funcBar->m_signalButtonTap.connect(this, &VappCallSetPageCfNumEdit::onFuncBtnClicked);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageCfNumEdit::onFuncBtnClicked);

    VcpButton *btn;
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setRect(m_textInput->getPos().x, 
                 m_textInput->getPos().y + m_textInput->getSize().height + 10, 
                 m_textInput->getSize().width, m_textInput->getSize().height);
    btn->setText(STR_ID_VAPP_CALLSET_SEL_PHB);
    btn->setId(VAPP_CALLSET_FUNC_SEL_FROM_PHB);
    btn->m_signalClicked.connect(this, &VappCallSetPageCfNumEdit::onFuncBtnClicked);
    
}

void VappCallSetPageCfNumEdit::onExit(VfxBool isBackward)
{
    if (getCurrState() != STATE_NONE)
    {
        setCurrState(STATE_NONE);
        onResult(NULL);
    }

    VappCallSetPageCommonInputAsync::onExit(isBackward);
}

mmi_ret VappCallSetPageCfNumEdit::onProc(mmi_event_struct *evt)
{
    vcui_phb_list_result_event_struct *res = (vcui_phb_list_result_event_struct*)evt;

	if (evt->evt_id !=EVT_ID_CUI_PHB_LIST_RESULT)
	{
		return VfxPage::onProc(evt);
	}
	
    if (!res->result ||(res->select_count != 1))
    {
        /* ignore */
        vcui_phb_list_close(m_phbId);
        m_phbId = GRP_ID_INVALID;  
        return VfxPage::onProc(evt);
    }

    WCHAR num[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    vcui_phb_list_get_selected_contact_data(m_phbId, num, MMI_PHB_NUMBER_PLUS_LENGTH);

    if (!srv_ss_is_valid_call_forward_number(callset_p->m_sim, (U8)mmi_wcslen(num), num))
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             (WCHAR*)GetString(STR_GLOBAL_INVALID_FORMAT));
    }
    else
    {
        m_textInput->setText(num, SRV_SS_MAX_FWD_ADDR_LEN - 1);
        vcui_phb_list_close(m_phbId);
        m_phbId = GRP_ID_INVALID;
    }

    return MMI_RET_OK;

}

void VappCallSetPageCfNumEdit::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    if (id == VAPP_CALLSET_FUNC_OK)
    {
        if (srv_ss_is_valid_call_forward_number(
                callset_p->m_sim, 
                (U8)mmi_ucs2strlen((CHAR *)m_textInput->getText()), 
                (WCHAR*)m_textInput->getText()))
        {
            if (callset_p->m_inActType != SRV_SS_ACTION_TYPE_ACTIVATE)
            {
                if (!mmi_ucs2cmp((CHAR *)callset_p->m_inCfNum, (CHAR *)m_textInput->getText()))
                {
                    /* not in activation flow and number is not changed */
                    return;
                }

                /* not in activation flow but not sure of the status, need to query again */
                callset_p->m_inActType = SRV_SS_ACTION_TYPE_QUERY;
                setCurrState(STATE_GET);
            }
            else
            {
                setCurrState(STATE_SET);
            }
			
			VappCallSetPageCf::sendSSReq(callset_p->m_inActType, m_textInput->getText(), callset_p->m_cfnryTime);

            showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_TRUE);
        }
        else
        {
            VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(STR_GLOBAL_INVALID_NUMBER));
        }
    }
    else if (id == VAPP_CALLSET_FUNC_SEL_FROM_PHB)
    {
        m_phbId = vcui_phb_list_create(getApp()->getGroupId());
        if (m_phbId != GRP_ID_INVALID)
        {
            vfxSetCuiCallerScr(m_phbId, getMainScr());
            vcui_phb_list_set_req_type(m_phbId, VAPP_PHB_LIST_SINGLE_SELECTOR);
            vcui_phb_list_set_req_field(m_phbId, MMI_PHB_CONTACT_FIELD_NUMBER);
            vcui_phb_list_run(m_phbId);
        }
    }
    else
    {
        return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }
}

void VappCallSetPageCfNumEdit::onResult(mmi_event_struct *info)
{
    if (getCurrState() >= STATE_INVALID)
    {
        /* abnormal */
        return;
    }

    srv_ss_rsp_evt_struct *evt = (srv_ss_rsp_evt_struct*)info;
    if (evt && evt->rsp.result == SRV_SS_RESULT_ABORT)
    {
        /* ignore abort rsp before checking current state */
        return;
    }

    if (getCurrState() == STATE_NONE)
    {
        /* canceled */
		VappCallSetPageAdditional::sendAbortSS();

        callset_p->m_inActType = SRV_SS_ACTION_TYPE_TOTAL;

        leaveWaitPopup();
        return;
    }

    if (!evt || evt->rsp.opcode != SRV_SS_ACT_CALL_FORWARD)
    {
        /* abnormal*/
        /* ignore */
        return;
    }

    if (evt->rsp.result != SRV_SS_RESULT_OK)
    {
        leaveWaitPopup();
        VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_ss_get_result_string(evt->rsp.result)));
        setCurrState(STATE_NONE);
    }
    else if (getCurrState() == STATE_GET)
    {
        srv_ss_call_forward_rsp_struct *rsp = (srv_ss_call_forward_rsp_struct*)(evt->rsp.data);
        VfxBool isOn;
        if (!rsp->result_list_count)
        {
            isOn = VFX_FALSE;
        }
        else
        {
            switch (rsp->result_list[0].status)
            {
                case SRV_SS_STATUS_ACTIVATED:
                case SRV_SS_STATUS_ACTIVATED_PERMANTLY:
                case SRV_SS_STATUS_ACTIVATED_BY_DEFAULT:
                case SRV_SS_STATUS_PROVIDED:
                    isOn = VFX_TRUE;
                    break;
            
                default:
                    isOn = VFX_FALSE;
                    break;
            }
        }

        if (isOn)
        {
            /* number is changed, activate again */
            callset_p->m_inActType = SRV_SS_ACTION_TYPE_ACTIVATE;
            setCurrState(STATE_SET);
            
			VappCallSetPageCf::sendSSReq(callset_p->m_inActType, m_textInput->getText(), callset_p->m_cfnryTime);
        }
        else
        {
            leaveWaitPopup();

            VcpConfirmPopup *cnf;
            VFX_OBJ_CREATE(cnf, VcpConfirmPopup, this);
            cnf->setInfoType(VCP_POPUP_TYPE_QUESTION);
            cnf->setText(STR_ID_VAPP_CALLSET_ACTIVATE_CNF);
            cnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            cnf->setCustomButton(STR_GLOBAL_ACTIVATE, STR_GLOBAL_CANCEL,
                                    VCP_POPUP_BUTTON_TYPE_RECOMMEND, VCP_POPUP_BUTTON_TYPE_CANCEL);
            cnf->m_signalButtonClicked.connect(this, &VappCallSetPageCfNumEdit::onConfirmClicked);
            cnf->setAutoDestory(VFX_TRUE);
            cnf->show(VFX_TRUE);

            setCurrState(STATE_NONE);
        }
    }
    else
    {
        leaveWaitPopup();
        *(callset_p->m_inCfNum) = VFX_WSTR_MEM(m_textInput->getText());
        setCurrState(STATE_NONE);

        getMainScr()->popPage();
    }

}

void VappCallSetPageCfNumEdit::onConfirmClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
            if (mmi_wcslen(m_textInput->getText()))
            {
                callset_p->m_inActType = SRV_SS_ACTION_TYPE_ACTIVATE;
				
				VappCallSetPageCf::sendSSReq(callset_p->m_inActType, m_textInput->getText(), callset_p->m_cfnryTime);
				
                setCurrState(STATE_SET);
                showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_TRUE);
            }
            else
            {
                VappCallSetPageCfNumEdit *pageCfNumEdit;
                VFX_OBJ_CREATE(pageCfNumEdit, VappCallSetPageCfNumEdit, getMainScr());
                getMainScr()->pushPage(VFX_ID_NULL, pageCfNumEdit);

                exit();
            }
            break;

        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
            break;
    }
}




void VappCallSetPageCfnryTime::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    VfxWString tmp_str = VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CFNRY_TIME);
    tmp_str += VFX_WSTR(" ");
    tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_LEFT_PARENTHESIS);
    tmp_str += VFX_WSTR_RES(VappCallSetPageCf::s_callTypeRes[callset_p->m_inCallType]);
    tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_RIGHT_PARENTHESIS);
    bar->setTitle(tmp_str);
    setTopBar(bar);

    m_count = 6;

    VfxU32 time = 5;
    switch (callset_p->m_inCallType)
    {
        case SRV_SS_VOICE_CALL:
		case SRV_SS_VIDEO_CALL:
            time = callset_p->m_cfnryTime;
            break;
    }

	m_activateIndex = (time / 5) - 1;    

    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);
    menu->setSize(getSize());
    menu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setContentProvider(this);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    menu->m_signalItemSelectionStateChanged.connect(this, &VappCallSetPageCfnryTime::onSelect);
}

void VappCallSetPageCfnryTime::onExit(VfxBool isBackward)
{
    if (getCurrState() != STATE_NONE)
    {
        setCurrState(STATE_NONE);
        onResult(NULL);
    }

    VappCallSetAsyncPage::onExit(isBackward);
}

VfxBool VappCallSetPageCfnryTime::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	text.loadFromRes(STR_ID_VAPP_CALLSET_CFNRY_5_SEC + index);

    return VFX_TRUE;
}

VfxU32 VappCallSetPageCfnryTime::getCount() const {return m_count;}

VcpListMenuItemStateEnum VappCallSetPageCfnryTime::getItemState(
    VfxU32 index   
    ) const 
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappCallSetPageCfnryTime::onSelect(
    VcpListMenu* menu, 
    VfxU32 index, 
    VcpListMenuItemStateEnum state
    )
{
    if (state != VCP_LIST_MENU_ITEM_STATE_SELECTED
        || index >= m_count)
    {
        return;
    }

    m_activateIndex = index;

    VfxU32 *time = &(callset_p->m_cfnryTime);

    *time = (m_activateIndex + 1) * 5;

    callset_p->m_inActType = SRV_SS_ACTION_TYPE_QUERY;
	
	VappCallSetPageCf::sendSSReq(
		callset_p->m_inActType,
		NULL,
		((m_activateIndex + 1) * 5));
	
    setCurrState(STATE_GET);
    showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_TRUE);

}

void VappCallSetPageCfnryTime::onResult(mmi_event_struct *info)
{
    if (getCurrState() >= STATE_INVALID)
    {
        /* abnormal */
        return;
    }

    srv_ss_rsp_evt_struct *evt = (srv_ss_rsp_evt_struct*)info;
    if (evt && evt->rsp.result == SRV_SS_RESULT_ABORT)
    {
        /* ignore abort rsp before checking current state */
        return;
    }

    if (getCurrState() == STATE_NONE)
    {
        /* canceled */
		VappCallSetPageAdditional::sendAbortSS();

        leaveWaitPopup();
        getMainScr()->popPage();
        return;
    }

    if (!evt || evt->rsp.opcode != SRV_SS_ACT_CALL_FORWARD)
    {
        /* abnormal*/
        /* ignore */
        return;
    }

    if (evt->rsp.result != SRV_SS_RESULT_OK)
    {
        leaveWaitPopup();
        VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_ss_get_result_string(evt->rsp.result)));
        setCurrState(STATE_NONE);

        getMainScr()->popPage();
    }
    else if (getCurrState() == STATE_GET)
    {
        srv_ss_call_forward_rsp_struct *rsp = (srv_ss_call_forward_rsp_struct*)(evt->rsp.data);
        VfxBool isOn;
        if (!rsp->result_list_count)
        {
            isOn = VFX_FALSE;
            *(callset_p->m_inCfNum) = VFX_WSTR_EMPTY;
        }
        else
        {
            switch (rsp->result_list[0].status)
            {
                case SRV_SS_STATUS_ACTIVATED:
                case SRV_SS_STATUS_ACTIVATED_PERMANTLY:
                case SRV_SS_STATUS_ACTIVATED_BY_DEFAULT:
                case SRV_SS_STATUS_PROVIDED:
                    isOn = VFX_TRUE;
                    break;
            
                default:
                    isOn = VFX_FALSE;
                    break;
            }
            *(callset_p->m_inCfNum) = VFX_WSTR_MEM(rsp->result_list[0].number);
        }

        if (isOn)
        {
            callset_p->m_inActType = SRV_SS_ACTION_TYPE_ACTIVATE;
			
			VappCallSetPageCf::sendSSReq(
				callset_p->m_inActType,
				callset_p->m_inCfNum->getBuf(),
				((m_activateIndex + 1) * 5));
			
            setCurrState(STATE_SET);
        }
        else
        {
            leaveWaitPopup();
            setCurrState(STATE_NONE);

            if (callset_p->m_inCfNum->isEmpty())
            {
                VappCallSetPageCfNumEdit *pageCfNumEdit;
                VFX_OBJ_CREATE(pageCfNumEdit, VappCallSetPageCfNumEdit, getMainScr());
                getMainScr()->pushPage(VFX_ID_NULL, pageCfNumEdit);

                exit();
            }
            else
            {
                VcpConfirmPopup *cnf;
                VFX_OBJ_CREATE(cnf, VcpConfirmPopup, this);
                cnf->setInfoType(VCP_POPUP_TYPE_QUESTION);
                cnf->setText(STR_ID_VAPP_CALLSET_ACTIVATE_CNF);
                cnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
                cnf->setCustomButton(STR_GLOBAL_ACTIVATE, STR_GLOBAL_CANCEL,
                                        VCP_POPUP_BUTTON_TYPE_RECOMMEND, VCP_POPUP_BUTTON_TYPE_CANCEL);
                cnf->m_signalButtonClicked.connect(this, &VappCallSetPageCfnryTime::onConfirmClicked);
                cnf->setAutoDestory(VFX_TRUE);
                cnf->show(VFX_TRUE);
            }
        }
    }
    else
    {
        /* change cfnry time successfully */
        leaveWaitPopup();
        setCurrState(STATE_NONE);

        getMainScr()->popPage();
    }

}

void VappCallSetPageCfnryTime::onConfirmClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
			
            callset_p->m_inActType = SRV_SS_ACTION_TYPE_ACTIVATE;
			
			VappCallSetPageCf::sendSSReq(
				callset_p->m_inActType,
				callset_p->m_inCfNum->getBuf(),
				((m_activateIndex + 1) * 5));
			
            setCurrState(STATE_SET);
            showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_TRUE);
            break;

        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
            callset_p->m_inActType = SRV_SS_ACTION_TYPE_TOTAL;
            getMainScr()->popPage();
            break;
    }

}

#pragma arm section code, rodata
