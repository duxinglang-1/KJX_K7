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
 *  vapp_bt_pair.cpp
 *
 * Project:
 * --------
 *  Cosmos
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
extern "C" {
#include "mmi_features.h"
}

#ifdef __MMI_BT_SUPPORT__
extern "C" {
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "BTcmSrvGprot.h"
#include "Conversions.h"
#include "MMI_conn_app_trc.h"
}

#include "mmi_rp_vapp_bt_main_def.h"
#include "vcp_include.h"
#include "vapp_bt_pair.h"
#include "vapp_bt_server.h"
#include "vcp_status_icon_bar.h"
#include "vfx_renderer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
//#define MAX_SECURITY_PASSKEY_LENGTH                     6        
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VfxS32 VappBTPasskeyApp::passkey_srv_handle = -1;
VappBTPasskeyApp* VappBTPasskeyApp::btPasskeyApp = NULL;
mmi_id VappBTPasskeyApp::gid = GRP_ID_INVALID;
VappPasskey* VappBTPasskeyApp::m_passkeyPara = NULL;


/***************************************************************************** 
 * Function
 *****************************************************************************/
void VappBTPasskeyLaunch(VappPasskey *arg, VfxU32 argSize)
{
	VappBTPasskeyApp::gid = VfxAppLauncher::launch( 
                        		VAPP_BT_PASSKEY_NOTIFY,
                        		VFX_OBJ_CLASS_INFO(VappBTPasskeyApp),
                        		GRP_ID_ROOT, arg, argSize);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_LAUNCHER, VappBTPasskeyApp::gid);
}


void VappBTPasskeyTerminate(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_TERMINATE);

    VfxAppLauncher::terminate(VappBTPasskeyApp::gid);
}



VFX_IMPLEMENT_CLASS("VappBTPasskeyApp", VappBTPasskeyApp, VfxApp);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappBTPasskeyApp::initialize(void *param)
{
    VfxU32 event_mask = SRV_BT_CM_EVENT_PAIR_IND |
#ifdef __MMI_BT_SIMPLE_PAIR__        
                        SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM |
                        SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY |
                        SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY |
#endif                        
						SRV_BT_CM_EVENT_PAIR_RES ;
                
    VappBTPasskeyApp::passkey_srv_handle = srv_bt_cm_set_notify(&VappBTPasskeyApp::btPasskeyEventNotify, event_mask, NULL);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_INIT, VappBTPasskeyApp::passkey_srv_handle);
}

//VFX_IMPLEMENT_CLASS("VappBTPasskeyScreen", VappBTPasskeyScreen, VfxAppScr);

void VappBTPasskeyApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
    
	btPasskeyApp = this;
    
	VappBTPasskeyScreen *scr;
	VFX_OBJ_CREATE_EX(scr, VappBTPasskeyScreen, this, (args, argSize));
	scr->show();
    
    switch(scr->passKey.event)
    {
        case SRV_BT_CM_EVENT_PAIR_IND:
            scr->displayPasskeyInput((void *)&(scr->passKey.u.passkeyInput));
			break;
#ifdef __MMI_BT_SIMPLE_PAIR__				
		case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
            scr->displayUserConfirm((void *)&(scr->passKey.u.userConfirm));
			break;
			
		case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
            scr->displayPasskeyNotify((void *) &(scr->passKey.u.securityPasskey));
			break;
			
		case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
			break;
#endif
		default:
			break;
    }
}


void VappBTPasskeyApp::onDeinit()
{
    mmi_frm_nmgr_cancel_deferred_scenario(
        MMI_SCENARIO_ID_BT_ACCESS_REQ,
        (mmi_noti_scrn_func_ptr)&VappBTPasskeyApp::nmgrHandler,
        (void*)VappBTPasskeyApp::m_passkeyPara);

    VFX_SYS_FREE_MEM(m_passkeyPara);
      
    btPasskeyApp = NULL;
    gid = GRP_ID_INVALID;

    VfxApp::onDeinit();
}

void VappBTPasskeyApp::onGroupActive()
{
    VfxApp::onGroupActive();
    mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
}

void VappBTPasskeyApp::onGroupInactive()
{
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
    VfxApp::onGroupInactive();
}

void VappBTPasskeyApp::btPasskeyEventNotify(VfxU32 event, void *para)
{   
	if (passkey_srv_handle > 0)
	{		
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_EVENT, event);
		switch(event)
		{
			case SRV_BT_CM_EVENT_PAIR_IND:
				//app have not started...alloc 40 byte system memory,  free when app exit.
				VFX_SYS_ALLOC_MEM(m_passkeyPara, sizeof(VappPasskey));
				m_passkeyPara->event = event;
				memcpy(&(m_passkeyPara->u.passkeyInput), para, sizeof(srv_bt_cm_pair_ind_struct));
				
				mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BT_ACCESS_REQ,
					MMI_EVENT_INFO,
					(mmi_noti_scrn_func_ptr)&VappBTPasskeyApp::nmgrHandler,
					(void*)m_passkeyPara);	 

				break;
#ifdef __MMI_BT_SIMPLE_PAIR__				
			case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
				//app have not started...alloc 40 byte system memory,  free when app exit.
				VFX_SYS_ALLOC_MEM(m_passkeyPara, sizeof(VappPasskey));
				m_passkeyPara->event = event;
				memcpy(&(m_passkeyPara->u.userConfirm), para, sizeof(srv_bt_cm_security_user_confirm_struct));
				
				memcpy(
					m_passkeyPara->passcode, 
					((srv_bt_cm_security_user_confirm_struct *)para)->passcode, 
					MAX_SECURITY_PASSKEY_LENGTH);

				m_passkeyPara->u.userConfirm.passcode = m_passkeyPara->passcode;
				
				mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BT_ACCESS_REQ,
					MMI_EVENT_INFO,
					(mmi_noti_scrn_func_ptr)&VappBTPasskeyApp::nmgrHandler,
					(void*)m_passkeyPara);	
				
				break;
				
			case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
				//app have not started...alloc 40 byte system memory,  free when app exit.
				VFX_SYS_ALLOC_MEM(m_passkeyPara, sizeof(VappPasskey));
				m_passkeyPara->event = event;
				memcpy(&(m_passkeyPara->u.securityPasskey), para, sizeof(srv_bt_cm_security_passkey_struct));
				
				memcpy(
					m_passkeyPara->passcode, 
					((srv_bt_cm_security_passkey_struct *)para)->passcode, 
					MAX_SECURITY_PASSKEY_LENGTH);
				
				m_passkeyPara->u.securityPasskey.passcode = m_passkeyPara->passcode;
				mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BT_ACCESS_REQ,
					MMI_EVENT_INFO,
					(mmi_noti_scrn_func_ptr)&VappBTPasskeyApp::nmgrHandler,
					(void*)m_passkeyPara);	
				
				break;
				
			case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
				//app have not started...alloc 40 byte system memory,  free when app exit.
				VFX_SYS_ALLOC_MEM(m_passkeyPara,(sizeof(srv_bt_cm_security_keypress_struct) + 8));
				
				m_passkeyPara->event = event;
				memcpy(&(m_passkeyPara->u.keyPress), para, sizeof(srv_bt_cm_security_keypress_struct));
				
				mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BT_ACCESS_REQ,
					MMI_EVENT_INFO,
					(mmi_noti_scrn_func_ptr)&VappBTPasskeyApp::nmgrHandler,
					(void*)m_passkeyPara);	
				
				break;
#endif
			case SRV_BT_CM_EVENT_BOND_RES:
				//bondResult(para);
				break;

			case SRV_BT_CM_EVENT_PAIR_RES:
				pairResult(para);
				break;
						
			default:
				break;
		}
	}			
}

VfxBool VappBTPasskeyApp::nmgrHandler(mmi_scenario_id scenarioId, void* arg)
{
    VappPasskey *passkeyPara = (VappPasskey *)arg;
    switch (passkeyPara->event)
    {
#ifdef __MMI_BT_SIMPLE_PAIR__				
		case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
		case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
		case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
#endif
		case SRV_BT_CM_EVENT_PAIR_IND:     
            VappBTPasskeyLaunch(passkeyPara, sizeof(VappPasskey));
			break;
        default:
            break;
    }
    return MMI_TRUE;
}


void VappBTPasskeyApp::pairResult(void *para)
{
    if (btPasskeyApp)
    {
        srv_bt_cm_pair_res_struct *event = (srv_bt_cm_pair_res_struct *)para;
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_RESULT, event->result);
        if (event->result == SRV_BT_CM_RESULT_FAILED)
        {
            VappBTPasskeyTerminate();
        }
    }
    else
    {
        mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ, 
            (mmi_noti_scrn_func_ptr)&VappBTPasskeyApp::nmgrHandler, 
            (void*)VappBTPasskeyApp::m_passkeyPara);
    }
}


void VappBTPasskeyScreen::onInit()
{
    VfxAppScr::onInit();
	m_statusBar = NULL;

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    m_direction = renderer->getPreScreenRotateType();
    m_pairRspFlag = VFX_FALSE;
}


void VappBTPasskeyScreen::onDeinit()
{
    if (!m_pairRspFlag)
    {
        switch(passKey.event)
        {
            case SRV_BT_CM_EVENT_PAIR_IND:
            {
                U8 asc_pin_buf[32] = {0};
                srv_bt_cm_send_passkey(&m_devAddr, asc_pin_buf, MMI_FALSE);
                break;
            }
                
#ifdef __MMI_BT_SIMPLE_PAIR__
            case SRV_BT_CM_EVENT_SECURITY_USER_CONFIRM:
            case SRV_BT_CM_EVENT_SECURITY_PASSKEY_NOTIFY:
                srv_bt_cm_security_numeric_confirm(&m_devAddr, MMI_FALSE);
                break;
                
            case SRV_BT_CM_EVENT_SECURITY_KEYPRESS_NOTIFY:
                break;
#endif  // __MMI_BT_SIMPLE_PAIR__
        }
    }
    
    VfxAppScr::onDeinit();
}


void VappBTPasskeyScreen::onQueryRotateEx(VfxScreenRotateParam &param)
{
	param.rotateTo = m_direction;
}


void VappBTPasskeyScreen::onRotate(const VfxScreenRotateParam &param)
{
    VfxAppScr::onRotate(param);
	if(m_statusBar)
	{
    m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
	}
}

extern "C" void vapp_ncenter_disable_leave(void);

void VappBTPasskeyScreen::onEnter(VfxBool isBackward)
{
    VfxScreen::onEnter(isBackward);
    vapp_ncenter_disable_leave();
}

void VappBTPasskeyScreen::onEntered(VfxBool isBackward)
{
    VfxScreen::onEntered(isBackward);
	VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
	m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
    m_statusBar->setPos(0, 0);
}


void VappBTPasskeyScreen::onExit(VfxBool isBackward)
{
    if (isBackward)
    {
        vapp_ncenter_disable_leave();
    }
	VFX_OBJ_CLOSE(m_statusBar);

    VfxScreen::onExit(isBackward);
}

void VappBTPasskeyScreen::displayPasskeyInput(void *para)
{
	srv_bt_cm_pair_ind_struct *event = (srv_bt_cm_pair_ind_struct *)para;
    m_devAddr = event->dev_addr;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_PASSKEY_INPUT, m_devAddr.lap, m_devAddr.uap, m_devAddr.nap);
	VcpInputPopup *passkeyInputPopup;
	VFX_OBJ_CREATE(passkeyInputPopup, VcpInputPopup, this);

    //VfxWString text(VFX_WSTR_RES(STR_ID_VAPP_BT_INPUT_PASSCODE));
    //text += VFX_WSTR("(");

    VfxWString devName;
    VfxWChar *buff = devName.lockBuf(SRV_BT_CM_BD_NAME_UCS2_LEN);
    mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buff, SRV_BT_CM_BD_NAME_UCS2_LEN, event->dev_name);
    devName.unlockBuf();
    //text += devName;
    //text += VFX_WSTR(")");
    //text += VFX_WSTR(":");

	
	passkeyInputPopup->setTitle(devName);
    //passkeyInputPopup->setHintText(VFX_WSTR(" "));

    VcpTextEditor *editor = passkeyInputPopup->getInputbox(0);
    VFX_ASSERT(editor);
    
    VsrvInputBinding inputBinding(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 0, 0, editor->m_editing);

    inputBinding.m_appDesiredFirstInputMode = IMM_INPUT_MODE_123_SYMBOLS;
    
    passkeyInputPopup->getInputbox(0)->setIME(inputBinding);
    passkeyInputPopup->setAutoDestory(VFX_FALSE);
    passkeyInputPopup->setText(VFX_WSTR_EMPTY, MAX_INPUT_PASSKEY_LENGHT);
	passkeyInputPopup->m_signalButtonClicked.connect(this, &VappBTPasskeyScreen::onPasskeyInputBarClick);
	passkeyInputPopup->show(VFX_TRUE);

}

void VappBTPasskeyScreen::onPasskeyInputBarClick(VfxObject *sender, VcpInputPopupButtonEnum Id)
{
    VfxWString inputText;
	MMI_BOOL pressOK = MMI_FALSE;
    U8 asc_pin_buf[32] = {0};
    switch(Id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
            inputText = ((VcpInputPopup *)sender)->getText();
            mmi_ucs2_to_asc((CHAR*)asc_pin_buf, (CHAR*)inputText.getBuf());
			pressOK = MMI_TRUE;
            break;

        case VCP_INPUT_POPUP_BTN_CANCEL:
        case VCP_POPUP_BUTTON_NO_PRESSED:
			pressOK = MMI_FALSE;
            break;
    }
	srv_bt_cm_send_passkey(&m_devAddr, asc_pin_buf, pressOK);
    m_pairRspFlag = VFX_TRUE;
    //((VcpInputPopup *)sender)->exit(VFX_TRUE);
    VappBTPasskeyTerminate();
}

#ifdef __MMI_BT_SIMPLE_PAIR__
void VappBTPasskeyScreen::displayUserConfirm(void *para)
{
    srv_bt_cm_security_user_confirm_struct *event = (srv_bt_cm_security_user_confirm_struct *)para;
    m_devAddr = event->dev_addr;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_PASSKEY_MATCH, m_devAddr.lap, m_devAddr.uap, m_devAddr.nap, event->display_numeric);
    VcpConfirmPopup *passkeyConfirm;
    VFX_OBJ_CREATE(passkeyConfirm, VcpConfirmPopup, this);

    if (event->display_numeric)
    {
        VfxWString text(VFX_WSTR_RES(STR_ID_VAPP_BT_NUMERIC_COMPARISON));
		displayText(text, (VfxChar*)(event->passcode), (VfxChar*)(event->dev_name));
	    passkeyConfirm->setText(text);

        /* Passcode matched? */
        /*     123456        */
        /*       xxx         */
        
    }
    else
    {
		VfxWString text;
		VfxWChar* textArray;		
		VfxWChar buff[SRV_BT_CM_BD_NAME_UCS2_LEN+1];
		
		mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buff, SRV_BT_CM_BD_NAME_UCS2_LEN, event->dev_name);

		textArray = text.lockBuf(80);
		mmi_wsprintf(textArray,80,STR_ID_VAPP_BT_ACCEPT_PAIRING,buff);		
		text.unlockBuf();
        passkeyConfirm->setText(text);
    }

    passkeyConfirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    //passkeyConfirm->setTextAlignMode( VfxTextFrame::ALIGN_MODE_CENTER);
    passkeyConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    passkeyConfirm->setCustomButton(
        VFX_WSTR_RES(STR_GLOBAL_YES),
        VFX_WSTR_RES(STR_GLOBAL_NO),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);

    passkeyConfirm->setAutoDestory(VFX_FALSE);
    passkeyConfirm->show(VFX_TRUE);
    passkeyConfirm->m_signalButtonClicked.connect(this, &VappBTPasskeyScreen::onPasskeyNotifyBarClick);
}

/*---------------------------------------------------------------------------*
 * Function: displayText()
 * Description: gen a string, for duplicate codes.
 *---------------------------------------------------------------------------*/
void VappBTPasskeyScreen::displayText(VfxWString &text, VfxChar* aPassCode, VfxChar* aDevName)
{
//local var:
	
//func implementation:
    text += VFX_WSTR("\n");

    VfxWString pinCode;
    VfxWChar *pin_buff = pinCode.lockBuf(MAX_SECURITY_PASSKEY_LENGTH + 1);
    U16 lenth = mmi_asc_n_to_ucs2((CHAR *)pin_buff, aPassCode, MAX_SECURITY_PASSKEY_LENGTH);
    pin_buff[lenth/2] = 0;
    pinCode.unlockBuf();
    
    //pinCode.format("%s", tmp_buf);
    text += pinCode;
    text += VFX_WSTR("\n");
	VfxWString devName;
	VfxWChar *buff = devName.lockBuf(SRV_BT_CM_BD_NAME_UCS2_LEN);
	mmi_chset_utf8_to_ucs2_string((kal_uint8 *)buff, SRV_BT_CM_BD_NAME_UCS2_LEN, (kal_uint8 *)aDevName);
	devName.unlockBuf();
    text += devName;
}

void VappBTPasskeyScreen::displayPasskeyNotify(void *para)
{
    srv_bt_cm_security_passkey_struct *event = (srv_bt_cm_security_passkey_struct *)para;
    m_devAddr = event->dev_addr;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PAIR_PASSKEY_NOTIFY, m_devAddr.lap, m_devAddr.uap, m_devAddr.nap);
    VcpConfirmPopup *passkeyNotify;
    VFX_OBJ_CREATE(passkeyNotify, VcpConfirmPopup, this);

    VfxWString text(VFX_WSTR_RES(STR_ID_VAPP_BT_INPUT_PASSCODE));
    displayText(text, (VfxChar*)(event->passcode), (VfxChar*)(event->dev_name));
    /* Input passcode */
    /*    123456      */
    /*   from XXX     */

    passkeyNotify->setInfoType(VCP_POPUP_TYPE_QUESTION);
    passkeyNotify->setText(text);
    //passkeyNotify->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    passkeyNotify->setButtonSet(VCP_CONFIRM_BUTTON_SET_CANCEL);

    passkeyNotify->setAutoDestory(VFX_FALSE);
    passkeyNotify->show(VFX_TRUE);
    passkeyNotify->m_signalButtonClicked.connect(this, &VappBTPasskeyScreen::onPasskeyNotifyBarClick);
}


void VappBTPasskeyScreen::onPasskeyNotifyBarClick(VfxObject *sender, VfxId Id)
{
	MMI_BOOL pressOK = MMI_FALSE;
    if (Id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
		pressOK = MMI_TRUE;
    }
	srv_bt_cm_security_numeric_confirm(&(m_devAddr),pressOK);
    m_pairRspFlag = VFX_TRUE;
    //((VcpConfirmPopup *)sender)->exit(VFX_TRUE);
    VappBTPasskeyTerminate();
}


#endif // __MMI_BT_SIMPLE_PAIR__
#endif // __MMI_BT_SUPPORT__

