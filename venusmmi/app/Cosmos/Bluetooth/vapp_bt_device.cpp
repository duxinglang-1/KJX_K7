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
 *  vapp_bt_device.cpp
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
#include "MMI_features.h" 
}

#ifdef __MMI_BT_SUPPORT__

extern "C" {
#include "GlobalResDef.h"
#include "BTcmSrvGprot.h"
#include "BtAudioSrvGprot.h"
#include "Conversions.h"
#include "MMI_conn_app_trc.h"
#include "SimCtrlSrvGprot.h" // for srv_sim_ctrl_get_num_of_inserted

}

#include "mmi_rp_vapp_bt_main_def.h"
#include "Vapp_bt_main.h"
#include "Vapp_bt_search.h"
#include "Vapp_bt_pair.h"
#include "vapp_bt_device.h"
#include "vapp_sim_setting_gprot.h"
#include "vcp_question_popup.h" // for VcpQuestionPopup
#if 0
/* under construction !*/
#else
#define VFX_LOG_FUNC
#define VFX_LOG_FUNC1(fmt, p1)
#define VFX_LOG_FUNC2(fmt, p1, p2)
#define VFX_LOG_STATIC_FUNC
#define VFX_LOG_STATIC_FUNC1(fmt, p1)
#define VFX_LOG_STATIC_FUNC2(fmt, p1, p2)
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_BT_SEARCH_BUTTON           (0)

#define VAPP_BT_MYDEV_OPT_CONN          (1)
#define VAPP_BT_MYDEV_OPT_DISCONN       (2)
#define VAPP_BT_MYDEV_OPT_RENAME        (3)
#define VAPP_BT_MYDEV_OPT_ATTHORIZE     (4)
#define VAPP_BT_MYDEV_OPT_DELETE        (5)
#define VAPP_BT_MYDEV_OPT_CANCEL        (6)

#define VAPP_BT_MYDEV_OPT_PREFER_SIM 7
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/



/***************************************************************************** 
 * Function
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappBTPairedListPage", VappBTPairedListPage, VappBTPageBase);

void VappBTPairedListPage::onDeinit()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_DESTRUCT, m_state);
    if (m_state == VBT_PAIRED_STATE_CONNECTING)
    {
        srv_btaud_abort(m_audSrvHd);
    }
    srv_btaud_close(m_audSrvHd);
	VappBTPageBase::onDeinit();
}

void VappBTPairedListPage::onInit()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_ONINIT);
	VappBTPageBase::onInit();
	initDevLis();
	VfxU32 event_mask = SRV_BT_CM_EVENT_PAIR_RES |
                        SRV_BT_CM_EVENT_CONNECT_RES |
                        SRV_BT_CM_EVENT_DISCONNECT_IND|
						SRV_BT_CM_EVENT_RELEASE_ALL_CONN |
						SRV_BT_CM_EVENT_SET_AUTHORIZE |
						SRV_BT_CM_EVENT_MYDEV_DEL ;
	setNotifyEvents(event_mask);
	VfxU32 audEvents =  BTAUD_EV_ATTACH_IND |
                        BTAUD_EV_ATTACH_FAIL;
    m_audSrvHd = srv_btaud_open(BTAUD_LEVEL_ADMIN, BTAUD_CHNL_ANY);
	
	srv_btaud_set_notify(
			m_audSrvHd, audEvents,
			&VappBTPairedListPage::audioSrvNotify,
			getObjHandle());

	setSearchBottombar();
	updateDevList(SRV_BT_CM_PAIRED_DEV);
}


/*---------------------------------------------------------------------------*
 * Function: handleBtEvents()
 * Description: virtual function from VappBTPageBase, call back when a BT event arised.
 *---------------------------------------------------------------------------*/
void VappBTPairedListPage::handleBtEvents(VfxU32 event, void* para)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_HANDLE_BT_EVENTS, event);
//local var:
	
//func implementation:
	switch(event)
	{
		case SRV_BT_CM_EVENT_CONNECT_RES:
			connectComplete(para);
			break;
			
		case SRV_BT_CM_EVENT_DISCONNECT_IND:
			disconnInd(para);
			break;
			
		case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
			disconComplete(para);
			break;
							
		case SRV_BT_CM_EVENT_SET_AUTHORIZE:
		case SRV_BT_CM_EVENT_PAIR_RES:
		case SRV_BT_CM_EVENT_MYDEV_DEL:
			break;
		default:
			return;

	}
	updateDevList(SRV_BT_CM_PAIRED_DEV);
}

void VappBTPairedListPage::connectComplete(void *para)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_CONNECT_COMPLETE,m_state);
    srv_bt_cm_conn_res_struct *event = (srv_bt_cm_conn_res_struct *)para;
    if (event->profile_id == SRV_BT_CM_HFG_PROFILE_UUID)
    {
		m_state &= 0x2; // if (m_state == VBT_PAIRED_STATE_CONNECTING) m_state = VBT_PAIRED_STATE_IDLE;
	}  
}


void VappBTPairedListPage::disconComplete(void *para)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_DISCONNECT_COMPLETE,m_state, m_disconnPopup);
    
  // srv_bt_cm_release_all_struct *event = (srv_bt_cm_release_all_struct *)para;
    if (m_disconnPopup)
    {
        m_disconnPopup->exit(VFX_FALSE);
        m_disconnPopup = NULL;
    }
    m_state = VBT_PAIRED_STATE_IDLE;
}

void VappBTPairedListPage::disconnInd(void *para)
{    
    srv_bt_cm_disconnect_ind_struct *event = (srv_bt_cm_disconnect_ind_struct *)para;

    if (event->profile_id == SRV_BT_CM_HFG_PROFILE_UUID)
    {
		m_state = VBT_PAIRED_STATE_IDLE;
    }
}

 /*---------------------------------------------------------------------------*
  * Function: getMenuEmptyText()
  * Description: virtual functoin from IVcpListMenuContentProvider. 
  *                    Get the empty text resource for the text when list menu is empty
  *    @return: VFX_TURE is success
  *---------------------------------------------------------------------------*/
VfxBool VappBTPairedListPage::getMenuEmptyText(VfxWString &text,VcpListMenuTextColorEnum &color)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
    text = VFX_WSTR_RES(STR_ID_VAPP_BT_PAIRED_DEV_EMPTY);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
} 
 
 /*---------------------------------------------------------------------------*
  * Function: onEnter()
  * Description: virtual function from VfxPage, call back While entering the page to be active.
  *---------------------------------------------------------------------------*/
 void VappBTPairedListPage::onEnter(VfxBool isBackward)
 {
	 VFX_LOG_FUNC;
 //local var:
	 
 //func implementation:
	 if(isBackward)
	 {
		 updateDevList(SRV_BT_CM_PAIRED_DEV);
	 }
 }

/*---------------------------------------------------------------------------*
 * Function: onClickedDev()
 * Description: virtual function from VappBTPageBase, call back when a dev in the list being clicked.
 *---------------------------------------------------------------------------*/
void VappBTPairedListPage::onClickedDev(VfxU32 /* index */, const srv_bt_cm_dev_struct* dev_Info)
{
	VFX_LOG_FUNC;
//local var:
	VfxS32 retVal;
    btaud_device_info info;
    VcpCommandPopup *optionMenu;
//func implementation:
	m_devClicked_addr = dev_Info->bd_addr;
    srv_bt_cm_get_dev_ucs2_name(&m_devClicked_addr, SRV_BT_CM_BD_UCS2_NAME_LEN, m_devClickedName);

	VFX_OBJ_CREATE(optionMenu, VcpCommandPopup, this);

	optionMenu->setInfoType(VCP_POPUP_TYPE_INFO);
    optionMenu->setText(VFX_WSTR_MEM(m_devClickedName));
	
    if ((dev_Info->cod)& SRV_BT_AUDIO_MAJOR_SERVICE_MASK)
    {
    	retVal = srv_btaud_get_active_device(BTAUD_CHNL_ANY, &info);
        if (info.addr.lap != m_devClicked_addr.lap ||
			info.addr.uap != m_devClicked_addr.uap ||
			info.addr.nap != m_devClicked_addr.nap)
        {
    		optionMenu->addItem(VAPP_BT_MYDEV_OPT_CONN, VFX_WSTR_RES(STR_GLOBAL_CONNECT), VCP_POPUP_BUTTON_TYPE_RECOMMEND);
			if(retVal || m_state == VBT_PAIRED_STATE_CONNECTING)
            	optionMenu->disableItem(VAPP_BT_MYDEV_OPT_CONN);
	    }
    }
	
	retVal = srv_bt_cm_is_dev_conn_active (&m_devClicked_addr);
	if (retVal)
	{
		optionMenu->addItem(VAPP_BT_MYDEV_OPT_DISCONN, VFX_WSTR_RES(STR_GLOBAL_DISCONNECT), VCP_POPUP_BUTTON_TYPE_RECOMMEND);

        if (m_state == VBT_PAIRED_STATE_DISCONNECTING)
        {
            optionMenu->disableItem(VAPP_BT_MYDEV_OPT_DISCONN);
        }
	}
	
    optionMenu->addItem(VAPP_BT_MYDEV_OPT_RENAME, VFX_WSTR_RES(STR_GLOBAL_RENAME), VCP_POPUP_BUTTON_TYPE_RECOMMEND);
#ifdef __MMI_BT_AUTHORIZE__
    optionMenu->addItem(VAPP_BT_MYDEV_OPT_ATTHORIZE, VFX_WSTR_RES(STR_ID_VAPP_BT_AUTHORIZE), VCP_POPUP_BUTTON_TYPE_RECOMMEND);
#endif  // __MMI_BT_AUTHORIZE__
#ifdef __GEMINI__ //prefer SIM card.
{
	mmi_sim_enum tempSIM;
	VfxU32 availableCount = 0;
	for(VfxU32 i = 0; i < MMI_SIM_TOTAL; i++)
	{
		tempSIM = mmi_frm_index_to_sim(i);
		if(MMI_TRUE == srv_sim_ctrl_is_available(tempSIM))
		{
			availableCount++;
		}
	}

	if((availableCount> 1)&&((dev_Info->cod)& SRV_BT_AUDIO_MAJOR_SERVICE_MASK))
		optionMenu->addItem(VAPP_BT_MYDEV_OPT_PREFER_SIM, VFX_WSTR_RES(STR_ID_VAPP_BT_PREFER_SIM), VCP_POPUP_BUTTON_TYPE_RECOMMEND);
}
#endif //__GEMINI__
    optionMenu->addItem(VAPP_BT_MYDEV_OPT_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_POPUP_BUTTON_TYPE_RECOMMEND);

    if (retVal)
    {
        optionMenu->disableItem(VAPP_BT_MYDEV_OPT_DELETE);
    }
	optionMenu->addItem(VAPP_BT_MYDEV_OPT_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    optionMenu->show(VFX_TRUE);
	optionMenu->m_signalButtonClicked.connect(this, &VappBTPairedListPage::onOptionMenuClick);

	
}
/*---------------------------------------------------------------------------*
 * Function: onUserSelectSIM()
 * Description: call back function,  be called when user select a prefer sim card.
 *---------------------------------------------------------------------------*/
void VappBTPairedListPage::onUserSelectSIM(VfxObject* item, VfxId id)
{
#ifdef __GEMINI__
	if(id != 0 && 0 == (id&(id-1)))
	{
		srv_bt_cm_set_prefer_sim(&m_devClicked_addr, (mmi_sim_enum)id);
	}
#endif //__GEMINI__
}

void VappBTPairedListPage::onOptionMenuClick(VfxObject *sender, VfxId Id)
{	
	switch(Id)
	{
		case VAPP_BT_MYDEV_OPT_CONN:
			connect();
			break;
			
		case VAPP_BT_MYDEV_OPT_DISCONN:
			disconnect();
			break;
			
		case VAPP_BT_MYDEV_OPT_RENAME:
			rename();
			break;
			
#ifdef __MMI_BT_AUTHORIZE__
        case VAPP_BT_MYDEV_OPT_ATTHORIZE:
            authorize();
            break;
#endif  // __MMI_BT_AUTHORIZE__

#ifdef __GEMINI__
		case VAPP_BT_MYDEV_OPT_PREFER_SIM:
		{
			mmi_sim_enum preferSim = srv_bt_cm_get_prefer_sim(&m_devClicked_addr);
			if(preferSim != MMI_SIM_NONE && MMI_TRUE == srv_sim_ctrl_is_available(preferSim))
			{
			    VappBTPreferSIMPage *pereferPage;
			    VFX_OBJ_CREATE_EX(pereferPage, 
						VappBTPreferSIMPage, 
						getMainScr(),
						(m_devClicked_addr)
						);
			    getMainScr()->pushPage(0,pereferPage);
			}
			else
			{
				mmi_sim_enum optionSIM;
				VcpQuestionPopup* questionPopup;
				VfxResId simResId[4] = {STR_GLOBAL_SIM_1, STR_GLOBAL_SIM_2, STR_GLOBAL_SIM_3, STR_GLOBAL_SIM_4};
				VfxWChar buff[20];
				VfxWString text;
				
				VFX_OBJ_CREATE(questionPopup, VcpQuestionPopup, this);
				questionPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BT_PREFER_SIM_NOT_AVAILIABLE));

				for(VfxU32 i = 0; i < MMI_SIM_TOTAL; i++)
				{
					optionSIM = mmi_frm_index_to_sim(i);
					if(MMI_TRUE == srv_sim_ctrl_is_available(optionSIM))
					{
						text = VFX_WSTR_RES(simResId[mmi_frm_sim_to_index(optionSIM)]);
						VfxWString simName = vapp_sim_settings_get_sim_name(optionSIM);
						if(!simName.isEmpty())
						{
							kal_wsprintf(&buff[0],"(%w)", simName.getBuf());
							text += VFX_WSTR_MEM(buff);
						}
						
						questionPopup->addItem((VfxU32)optionSIM, text,VCP_POPUP_BUTTON_TYPE_NORMAL);
					}
				}
				questionPopup->addItem(0, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
				questionPopup->m_signalButtonClicked.connect(this, 
												&VappBTPairedListPage::onUserSelectSIM);
				questionPopup->show(VFX_TRUE);
					
			}
			break;
		}
#endif //__GEMINI__
		case VAPP_BT_MYDEV_OPT_DELETE:
			delte();
			break;
/*			
		case VAPP_BT_MYDEV_OPT_CANCEL:
			//VFX_OBJ_CLOSE(sender);
			return;
			*/
		default:
			break;
	}	
}


void VappBTPairedListPage::audioSrvNotify(BtAudEvent evt, U32 arg, void *userData)
{
    VcpConfirmPopup *connectFailPopup;
    VappBTPairedListPage *page = (VappBTPairedListPage*)VfxObject::handleToObject(userData);
    VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_BT_FAIL_CONNECT);

    page->m_btDevListMenu->resetAllItems();
    page->m_state = VBT_PAIRED_STATE_IDLE;

	if (page->m_connPopup)
	{
		page->m_connPopup->exit(VFX_FALSE);
		page->m_connPopup = NULL;
		if(BTAUD_EV_ATTACH_FAIL == evt)
		{
            VFX_OBJ_CREATE(connectFailPopup, VcpConfirmPopup, page->getMainScr());
            connectFailPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BT_FAIL_CONNECT));
            connectFailPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            connectFailPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            connectFailPopup->show(VFX_TRUE);
		}
	}
}

void VappBTPairedListPage::connect()
{
	btaud_device_info devInfo;
    if (srv_btaud_get_active_device(BTAUD_CHNL_ANY, &devInfo))
    {
        return;
    }
    if (srv_btaud_attach(m_audSrvHd, &m_devClicked_addr)) 
    {
        VFX_OBJ_CREATE(m_connPopup, VcpIndicatorPopup, getMainScr());
        
        m_connPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CONNECTING));
        m_connPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        m_connPopup->m_signalCanceled.connect(this, &VappBTPairedListPage::onConnCancelClick);
        m_connPopup->show(VFX_FALSE);

        m_state = VBT_PAIRED_STATE_CONNECTING;
    }
    else
    {
		popupBalloonMsg(STR_ID_VAPP_BT_FAIL_CONNECT);
    }
}

void VappBTPairedListPage::onConnCancelClick(VfxObject* sender, VfxFloat curr_progress)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_CONNECT_CANCEL, m_state);
    srv_btaud_abort(m_audSrvHd);
    m_connPopup = NULL;
}


void VappBTPairedListPage::disconnect()
{

	
	VfxS32 result = srv_bt_cm_release_dev_conn(&m_devClicked_addr);
    switch (result)
    {
        case SRV_BT_CM_RESULT_SUCCESS:
            VFX_OBJ_CREATE(m_disconnPopup, VcpIndicatorPopup, getMainScr());

            m_disconnPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_disconnPopup->setText(VFX_WSTR_RES(STR_GLOBAL_DISCONNECTING));
            m_disconnPopup->show(VFX_FALSE);
            m_state = VBT_PAIRED_STATE_DISCONNECTING;
            break;

        case SRV_BT_CM_RESULT_NO_CONNECTION:
            break;

        case SRV_BT_CM_RESULT_FAILED:
        default:
			popupBalloonMsg(STR_ID_VAPP_BT_NOT_AVAILABLE);
	        break;
    }

}

void VappBTPairedListPage::rename()
{
	VcpInputPopup *rename;
	VFX_OBJ_CREATE(rename, VcpInputPopup, getMainScr());

    rename->setTitle(VFX_WSTR_RES(STR_GLOBAL_RENAME));
    rename->setText(VFX_WSTR_MEM(m_devClickedName), SRV_BT_CM_BD_UCS2_NAME_LEN - 1);
	rename->setIME(IMM_INPUT_TYPE_SENTENCE);
    rename->setAutoDestory(VFX_FALSE);

    VcpTextEditor *text = rename->getInputbox();
    text->setHighlight(0, text->getLength());
    
	rename->m_signalButtonClicked.connect(this, &VappBTPairedListPage::onRenamePopupBarClick);
	rename->show(VFX_TRUE);

}

void VappBTPairedListPage::onRenamePopupBarClick(VfxObject *sender, VcpInputPopupButtonEnum chosen)
{	
	VfxWString inputText;
    U8 name_buf[SRV_BT_CM_BD_FNAME_LEN];
	VcpInputPopup * pPopup;

	pPopup = (VcpInputPopup *)sender;
	
	if ( VCP_INPUT_POPUP_BTN_OK == chosen)
	{
		inputText = pPopup->getText();
        
		mmi_chset_ucs2_to_utf8_string(
	        (kal_uint8*) name_buf,
	        SRV_BT_CM_BD_FNAME_LEN,
	        (kal_uint8*) inputText.getBuf());

		if (srv_bt_cm_set_dev_name(&m_devClicked_addr, name_buf) == SRV_BT_CM_RESULT_SUCCESS)
        {
            m_btDevListMenu->updateAllItems();
        }         

	}
    pPopup->exit(VFX_TRUE);
	
}


void VappBTPairedListPage::delte()
{
	VcpConfirmPopup *delte;
	VFX_OBJ_CREATE(delte,VcpConfirmPopup,getMainScr());
    
	delte->setText(VFX_WSTR_RES(STR_ID_VAPP_BT_DELETE_ASK));
	delte->setInfoType(VCP_POPUP_TYPE_WARNING);
	delte->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	delte->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE), 
						 VFX_WSTR_RES(STR_GLOBAL_CANCEL),
						 VCP_POPUP_BUTTON_TYPE_WARNING,
						 VCP_POPUP_BUTTON_TYPE_CANCEL);

	delte->m_signalButtonClicked.connect(this, &VappBTPairedListPage::onDeletePopupBarClick);
	delte->show(VFX_TRUE);
}


void VappBTPairedListPage::onDeletePopupBarClick(VfxObject *sender,VfxId chosen)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_DELECT_BUTTON_SELECT, chosen);
 
    if (chosen == VCP_CONFIRM_POPUP_BUTTON_USER_1) /*press Yes*/
    {
        if ( srv_bt_cm_is_dev_conn_active (&m_devClicked_addr))
        {
			popupBalloonMsg(STR_BT_VAPP_BT_DISCONN_DEV_CONN);
            return;
        }
		
        if (srv_bt_cm_dev_del(&m_devClicked_addr) != SRV_BT_CM_RESULT_SUCCESS)
        {
			popupBalloonMsg(STR_ID_VAPP_BT_NOT_AVAILABLE);
        }
    }
}


void VappBTPairedListPage::setSearchBottombar()
{
	VcpToolBar *bottomBar;
	
	VFX_OBJ_CREATE(bottomBar, VcpToolBar, this);
	bottomBar->addItem(VAPP_BT_SEARCH_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SEARCH), IMG_ID_VAPP_BT_DEV_SEARCHING);
    
	bottomBar->m_signalButtonTap.connect(this, &VappBTPairedListPage::onSearchBarClick);
	setBottomBar(bottomBar);
}


void VappBTPairedListPage::onSearchBarClick(VfxObject* sender, VfxId Id)
{
   
    if (SRV_BT_CM_RESULT_SUCCESS ==
        srv_bt_cm_search(
            SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST,
            MAX_INQUIRY_DURATION, 
            SRV_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK, 
            MMI_TRUE))
    {
	    VappBTSearchDevPage *searchPage;
		VFX_OBJ_CREATE(searchPage, VappBTSearchDevPage, getMainScr());
        
		getMainScr()->pushPage(0, searchPage);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DEVICE_SEARCH_FAIL);
		popupBalloonMsg(STR_ID_VAPP_BT_NOT_AVAILABLE);
    }

}

#ifdef __MMI_BT_AUTHORIZE__



void VappBTPairedListPage::authorize()
{
    VappBTAuthorizePage *authorizePage;
	
    VFX_OBJ_CREATE_EX(authorizePage, VappBTAuthorizePage, getMainScr(),(m_devClicked_addr));
    getMainScr()->pushPage(0,authorizePage);

}
#endif  // __MMI_BT_AUTHORIZE__


#ifdef __MMI_BT_AUTHORIZE__

//////////////////////////////////////////////////////////////////////////////////////
// VappBTAuthorizePage implementation.
//////////////////////////////////////////////////////////////////////////////////////
void VappBTAuthorizePage::onInit()
{
    VfxPage::onInit();
    VcpTitleBar *authorizeTitle;

	VFX_OBJ_CREATE(authorizeTitle,VcpTitleBar,this);
	authorizeTitle->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BT_AUTHORIZE));
	setTopBar(authorizeTitle);

    VFX_OBJ_CREATE(m_listMenu,VcpListMenu, this);
	m_listMenu->setContentProvider(this);
	m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VappBTAuthorizePage::onItemSelect);
	m_alwaysAskStatus = srv_bt_cm_get_authorize(&m_DevAddress);
}


void VappBTAuthorizePage::onItemSelect(VcpListMenu *menuList, VfxU32 item_id)
{
	setAlwaysAskStatus((srv_bt_cm_authorize_type)item_id);
    getMainScr()->popPage();
}

/*---------------------------------------------------------------------------*
 * Function: setAlwaysAskStatus()
 * Description: set the status of m_alwaysAskStatus
 *---------------------------------------------------------------------------*/
void VappBTAuthorizePage::setAlwaysAskStatus(srv_bt_cm_authorize_type aAlwaysAsk)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	m_alwaysAskStatus = aAlwaysAsk;
	if (srv_bt_cm_set_authorize(&m_DevAddress, m_alwaysAskStatus) != SRV_BT_CM_RESULT_SUCCESS)
	{
	    mmi_frm_nmgr_balloon(
		    MMI_SCENARIO_ID_DEFAULT,
		    MMI_EVENT_INFO_BALLOON,
		    MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE)
		    );
	}
	m_listMenu->updateAllItems();
}

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Description: the count of list items .
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
VfxU32 VappBTAuthorizePage::getCount() const
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	return 2;
}


/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Description: virtual function from IVcpListMenuContentProvider, give image of list items.
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
VfxBool VappBTAuthorizePage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:    
	if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_BT_ALWAYS_ASK - index);
		return VFX_TRUE;
    }
	return VFX_FALSE;
}

/*---------------------------------------------------------------------------*
 * Function: getItemState()
 * Description: virtual from IVcpListMenuContentProvider, give the item status.
 *    @return: item status.
 *---------------------------------------------------------------------------*/
VcpListMenuItemStateEnum VappBTAuthorizePage::getItemState(VfxU32 index) const
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	if(index == m_alwaysAskStatus)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
	else
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}

#endif  // __MMI_BT_AUTHORIZE__

#ifdef __GEMINI__

//////////////////////////////////////////////////////////////////////////////////////
// VappBTPreferSIMPage implementation.
//////////////////////////////////////////////////////////////////////////////////////
void VappBTPreferSIMPage::onInit()
{
    VcpTitleBar *authorizeTitle;
	mmi_sim_enum tempSIM;
	m_availableSIMCount = 0;
    VfxPage::onInit();

	VFX_OBJ_CREATE(authorizeTitle,VcpTitleBar,this);
	authorizeTitle->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BT_PREFER_SIM));
	setTopBar(authorizeTitle);

    VFX_OBJ_CREATE(m_listMenu,VcpListMenu, this);
	m_listMenu->setContentProvider(this);
	m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VappBTPreferSIMPage::onItemSelect);

	m_selectSIM = srv_bt_cm_get_prefer_sim(&m_DevAddress);
	for(VfxU32 i = 0; i < MMI_SIM_TOTAL; i++)
	{
		tempSIM = mmi_frm_index_to_sim(i);
		m_insertSimEnum[i] = MMI_SIM_NONE;
		if(MMI_TRUE == srv_sim_ctrl_is_available(tempSIM))
		{
			m_insertSimEnum[m_availableSIMCount] = tempSIM;
			m_availableSIMCount++;
		}
	}
}


void VappBTPreferSIMPage::onItemSelect(VcpListMenu *menuList, VfxU32 item_id)
{	
	m_selectSIM = m_insertSimEnum[item_id];
	srv_bt_cm_set_prefer_sim(&m_DevAddress, m_selectSIM);
  getMainScr()->popPage();
}

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Description: the count of list items .
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
VfxU32 VappBTPreferSIMPage::getCount() const
{
//local var:
	
//func implementation:
	return m_availableSIMCount;
}


/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Description: virtual function from IVcpListMenuContentProvider, give image of list items.
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
VfxBool VappBTPreferSIMPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
//local var:
	mmi_sim_enum SIM;
	VfxWChar buff[20];
	VfxResId simResId[4] = {STR_GLOBAL_SIM_1, STR_GLOBAL_SIM_2, STR_GLOBAL_SIM_3, STR_GLOBAL_SIM_4};
//func implementation:

	if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
		SIM = m_insertSimEnum[index]; 
		text = VFX_WSTR_RES(simResId[mmi_frm_sim_to_index(SIM)]);
		VfxWString simName = vapp_sim_settings_get_sim_name(SIM);
		if(!simName.isEmpty())
		{
			kal_wsprintf(&buff[0],"(%w)", simName.getBuf());
			text += VFX_WSTR_MEM(buff);
		}
		return VFX_TRUE;
    }
	return VFX_FALSE;
}

/*---------------------------------------------------------------------------*
 * Function: getItemState()
 * Description: virtual from IVcpListMenuContentProvider, give the item status.
 *    @return: item status.
 *---------------------------------------------------------------------------*/
VcpListMenuItemStateEnum VappBTPreferSIMPage::getItemState(VfxU32 index) const
{
//local var:
//func implementation:
	if(m_selectSIM == m_insertSimEnum[index])
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
	else
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}

#endif  // __GEMINI__


#endif // __MMI_BT_SUPPORT__
