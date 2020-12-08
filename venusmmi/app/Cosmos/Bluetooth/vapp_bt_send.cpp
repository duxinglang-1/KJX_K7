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
 *  vapp_bt_send.cpp
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
extern "C"
{
#include "mmi_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "kal_release.h"
#include "App_mine.h"
#include "USBSrvGprot.h"
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif
#include "MMI_conn_app_trc.h"
#include "mmi_cb_mgr_gprot.h" // for mmi_frm_cb_reg_event
}
#ifdef __MMI_OPP_SUPPORT__
#include "vapp_bt_send.h"
#include "Vfx_datatype.h"
#include "vapp_bt_send_gprot.h"
#include "vcui_bt_gprot.h"
#include "mmi_rp_vapp_bt_main_def.h"
#include "mmi_rp_vapp_bt_send_def.h"
#include "Vcp_global_popup.h"
#include "vapp_bt_main.h"
#include "vcp_status_icon_bar.h"
#include "mmi_rp_vapp_setting_def.h" // for EVT_ID_VAPP_LANGUAGE_CHANGED
#ifdef __MMI_THEMES_APPLICATION__
#include "mmi_rp_vapp_theme_def.h" // for EVT_ID_VAPP_THEME_CHANGED
#endif //__MMI_THEMES_APPLICATION__
/***************************************************************************** 
 * Definition
 *****************************************************************************/
#ifndef __VAPP_BT_DEBUG_INTENAL__
#define __VAPP_BT_DEBUG_INTENAL__
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void vapp_bt_send_obj(vapp_bt_send_app_info *app_info, 
                                 U32 option,
                                 U32 total,
                                 WCHAR** obj_array)
{
	
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDPREAPP_USBPLUGIN);
#endif
    VappBTSendingPara sendingPara;
    mmi_id group_id;
        
    memset(&sendingPara, 0, sizeof(VappBTSendingPara));
    if (VappBTSendPreApp::m_selfInst ||
		VappBTSendApp::m_selfInst ||
		(!srv_oppc_is_idle())||
		VappBTOPPClient::m_inst)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE));
		if(obj_array == NULL && app_info && app_info->callback)
		app_info->callback(NULL, app_info->user_data);
        return;
    }

    sendingPara.m_appData = app_info->user_data;
    sendingPara.m_callback = (void *)app_info->callback;
    sendingPara.m_nameArray = (VfxWChar**)obj_array;
    sendingPara.m_total = total;
    sendingPara.m_option = option;
        
    group_id = VfxAppLauncher::createCui(
        VCUI_BT_SEND_PREPARE, 
        VFX_OBJ_CLASS_INFO(VappBTSendPreApp),
        app_info->group_id,
        &sendingPara,
        sizeof(sendingPara));
    VfxAppLauncher::runCui(group_id);
}

extern "C" mmi_ret vapp_oppc_usb_plugin_hdlr(mmi_event_struct *evt)
{
	//no need trace.
    VappBTSendPreApp::onUsbPlugIn();
    VappBTSendApp::onUsbPlugIn();
    
    return MMI_RET_OK;
}

/*---------------------------------------------------------------------------*
 * Function: cloneNameArray()
 * Description: alloc a new memory from aParent to store the name array.
 *---------------------------------------------------------------------------*/
void VappBTSendingPara::cloneNameArray(VfxObject* aParent, VfxWChar** aNameArray)
{
//local var:
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_CLONE);
#endif
	m_nameArray = NULL;
//func implementation:
	if(aNameArray)
		{
			if(m_total == 1)
			{
					mmi_wcscpy(m_sendFileName, *aNameArray);
			}
			else
			{
				VFX_ALLOC_MEM(m_nameArray, m_total * sizeof(WCHAR*), aParent);
				memset(m_nameArray, 0, m_total * sizeof(WCHAR*));
				for(VfxS32 i = m_total - 1; i >= 0 ; i--)
				{
					VFX_ALLOC_MEM(m_nameArray[i], SRV_FMGR_PATH_MAX_LEN<<1, aParent);
					mmi_wcscpy(m_nameArray[i], aNameArray[i]);
				}
	    }
	}
}

/*---------------------------------------------------------------------------*
 * Function: releaseNameBuf()
 * Description: release name buff if(m_nameArray != NULL)
 *---------------------------------------------------------------------------*/
void VappBTSendingPara::releaseNameBuf()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_RELEASE_NAME);
#endif
//local var:
	
//func implementation:
	if(m_nameArray)
	{
		if(m_total != 1)
		{
			for(VfxS32 i = m_total - 1; i >= 0; i--)
			{
				VFX_FREE_MEM(m_nameArray[i]);
			}
		}
		VFX_FREE_MEM(m_nameArray);
	}
}

/*---------------------------------------------------------------------------*
 * Function: clearTempFile()
 * Description: delete sending file if (m_option == VAPP_BT_SEND_DELETE_FILE)
 *---------------------------------------------------------------------------*/
void VappBTSendingPara::clearTempFile(VfxObject* aOwner)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_CLEAN_TEMP_FILE);
#endif
//local var:
	
//func implementation:
    if (m_option == VAPP_BT_SEND_DELETE_FILE)
    {
        if((m_callback == NULL)&&(m_total == 1))
		    { // delete temp sending file.
            FS_Delete(m_sendFileName);
		    }
    }
}

extern "C" mmi_ret vapp_oppc_language_changed_hdlr(mmi_event_struct *evt)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_LANGUAGE_CHANGED);
#endif

    switch (evt->evt_id)
    {
        case EVT_ID_VAPP_LANGUAGE_CHANGED:
            if (VappBTSendApp::m_selfInst)
            {
				VappBTSendApp::m_selfInst->recreateSendingPopup();
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * Class VappBTSendPreApp
 *****************************************************************************/
VappBTSendPreApp* VappBTSendPreApp::m_selfInst = NULL;

VFX_IMPLEMENT_CLASS("VappBTSendPreApp", VappBTSendPreApp, VfxCui);

void VappBTSendPreApp::onRun(void *args,VfxU32 argSize)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_PRE_RUN);
#endif

    VfxCui::onRun(args, argSize);
	

    VappBTSendingPara* para = (VappBTSendingPara*)args;

	memcpy(&m_sendingPara, para, sizeof(VappBTSendingPara));
	m_sendingPara.cloneNameArray(this, para->m_nameArray);

    // the instance start running
    m_selfInst = this;
	m_needNotifyPhoneBook = (para->m_nameArray == NULL);
    if (srv_oppc_is_idle()&&!selectDevice())
	{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_MMI_FAIL_LINE, __LINE__);
#endif
        errorHandle(BTSEND_NO_AVAIL_PRO);
        return;
	}
}

void VappBTSendPreApp::onDeinit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDPREAPP_DEINIT);
#endif
	if(m_needNotifyPhoneBook)
	{
    	((vapp_bt_send_get_next_obj)(m_sendingPara.m_callback))(NULL, m_sendingPara.m_appData);
    }
	else
	{
		m_sendingPara.clearTempFile(this);
	}
	m_sendingPara.releaseNameBuf();
    m_selfInst = NULL;
    VfxCui::onDeinit();
}

mmi_ret VappBTSendPreApp::onProc(mmi_event_struct *evt)
{
    if (EVT_ID_GROUP_CUI_BT_SELECT_DEVICE == evt->evt_id)
    {
        selectDeviceHdlr(evt);
    }
    return MMI_RET_OK;
}

void VappBTSendPreApp::onUsbPlugIn()
{
    if (VappBTSendPreApp::m_selfInst != NULL)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDPREAPP_USBPLUGIN);
		VappBTSendPreApp::m_selfInst->exit();
    }
}

void VappBTSendPreApp::errorHandle(BTSendResultEnum cod)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDPREAPP_ERROR, cod);

    WCHAR* str;
    switch (cod)
    {
        case BTSEND_NO_INSTANCE:
        case BTSEND_NO_AVAIL_PRO:
        case BTSEND_SELECT_DEVICE_FAIL:
        case BTSEND_SERV_NOT_AVAILABLE:
        default:
            str = (WCHAR*)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE);
            break;
    }
    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        str);
    exit();
}

VfxBool VappBTSendPreApp::selectDevice()
{
    mmi_id devId;
    cui_bt_select_device_struct para;
    
    para.cod_mask = 0;
    para.service_id = SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID; //not used by select dev cui.
 
    devId = vcui_bt_select_device_create(getGroupId(), &para);
    if (devId == GRP_ID_INVALID)
    {
        return VFX_FALSE;
    }
    vcui_bt_select_device_run(devId);
    return VFX_TRUE;
}

void VappBTSendPreApp::selectDeviceHdlr(mmi_event_struct *evt)
{
    cui_bt_select_device_result *sel = (cui_bt_select_device_result *)evt;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDPREAPP_SELECTDEVICEHDLR, sel->result);
    if (sel->result)
    {
	    startSendApp(evt);
		m_needNotifyPhoneBook = VFX_FALSE;
	    vcui_bt_select_device_close(sel->cui_id);
	    m_sendingPara.m_option = VAPP_BT_SEND_NONE;
	}
#ifdef __VAPP_BT_DEBUG_INTENAL__
	else
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_MMI_FAIL_LINE, __LINE__);	
	}
#endif
    exit();
}

void VappBTSendPreApp::startSendApp(mmi_event_struct *evt)
{
    cui_bt_select_device_result *sel = (cui_bt_select_device_result *)evt;

    m_sendingPara.m_addr = sel->dev_info.bd_addr;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDPREAPP_STARTSEND);
    VfxAppLauncher::launch(
        VAPP_BT_SEND,
        VFX_OBJ_CLASS_INFO(VappBTSendApp),
        GRP_ID_ROOT,
        (void*)&m_sendingPara,
        sizeof(VappBTSendingPara)
        );
}


/*****************************************************************************
 * Class VappBTSendApp
 *****************************************************************************/
VappBTSendApp* VappBTSendApp::m_selfInst = NULL;

VFX_IMPLEMENT_CLASS("VappBTSendApp", VappBTSendApp, VfxApp);

void VappBTSendApp::onRun(void *args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
#ifdef __MMI_ASM_OOM_AUTO_KILL__
    
    mmi_frm_asm_set_app_priority(VAPP_BT_SEND, 0);
#endif
    m_selfInst = this;
    VappBTSendingPara *para = (VappBTSendingPara*)args;	
	memcpy(&m_sendingPara, para, sizeof(VappBTSendingPara));
	if(para->m_callback == NULL)
	{
		m_sendObjType = VAPP_OPP_SENDING_OBJ;
		m_sendingPara.cloneNameArray(this, para->m_nameArray);
	}
	else
	{
		m_sendObjType = VAPP_OPP_SENDING_VCARD;
		VFX_ALLOC_MEM(m_filePathAndName, SRV_FMGR_PATH_MAX_LEN<<1, this);
	}
#ifdef __MMI_THEMES_APPLICATION__	
    mmi_frm_cb_reg_event(EVT_ID_VAPP_THEME_CHANGED,  &VappBTSendApp::themeChangeHdr, this);
#endif //__MMI_THEMES_APPLICATION__

    showConnPopup();
    initApp();
}

void VappBTSendApp::onDeinit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_SEND_APP_DEINIT);	
#endif
    m_indPopup = NULL;	
#ifdef __MMI_THEMES_APPLICATION__
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_THEME_CHANGED, &VappBTSendApp::themeChangeHdr, this);
#endif //__MMI_THEMES_APPLICATION__
	if(m_currentFileIndex < m_sendFileCount - 1 && m_sendObjType == VAPP_OPP_SENDING_VCARD)
		((vapp_bt_send_get_next_obj)(m_sendingPara.m_callback))(NULL, m_sendingPara.m_appData);

    m_selfInst = NULL;
	void* freePtr;
	if(m_sendObjType == VAPP_OPP_SENDING_VCARD)
	{
 		freePtr = (void*)m_filePathAndName;
	}
	else
	{
		if(m_sendingPara.m_total != 1)
		{
			for(VfxS32 i = m_sendingPara.m_total - 1; i >= 0; i--)
			{
			VFX_FREE_MEM(m_sendingPara.m_nameArray[i]);
			}
		}
		freePtr = (void*)(m_sendingPara.m_nameArray);
	}
	VFX_FREE_MEM(freePtr);
	removeOngoingCell();
	VappBTOPPClient::m_inst = NULL;
    VfxApp::onDeinit();
}

void VappBTSendApp::showConnPopup()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_SHOW_CONN_POPUP);	
#endif
    VFX_OBJ_CREATE(m_mainScr, VappBTSmallScr, this);

	m_mainScr->addStatusBar();
    m_mainScr->show();
    VFX_OBJ_CREATE(m_waitPopup, VcpIndicatorPopup, m_mainScr);
    m_waitPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_waitPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BT_CONNECTING));
    m_waitPopup->setAutoDestory(VFX_TRUE);  
    m_waitPopup->m_signalCanceled.connect(this, &VappBTSendApp::sendCancel);

    m_waitPopup->show(VFX_TRUE);

}
#ifdef __MMI_THEMES_APPLICATION__
mmi_ret VappBTSendApp::themeChangeHdr(mmi_event_struct *event)
{
	if(m_selfInst)
	{
		m_selfInst->recreateSendingPopup();
	}
	return MMI_RET_OK;
}
#endif // __MMI_THEMES_APPLICATION__

void VappBTSendApp::recreateSendingPopup()
{
	VFX_OBJ_CLOSE(m_indPopup);
    VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, m_mainScr);
    m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_indPopup->setAutoDestory(VFX_TRUE);
		m_indPopup->setIsAnimate(VFX_FALSE);
    m_indPopup->show(VFX_TRUE);
    m_indPopup->m_signalCanceled.connect(this, &VappBTSendApp::sendCancel);
	updateProgress(VFX_TRUE);
}


void VappBTSendApp::onUsbPlugIn()
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDAPP_USBPLUGIN);
	VappBTSendApp::stopSending();
}

VfxAppCloseAnswerEnum VappBTSendApp::onProcessClose(VfxAppCloseOption options)
{
    if (options & VFX_APP_CLOSE_OPTION_BG_FLAG)
    {
        return VFX_APP_CLOSE_ANSWER_BG;
    }

    if (options & VFX_APP_CLOSE_OPTION_NO_FLAG)
    {
        return VFX_APP_CLOSE_ANSWER_NO;
    }

    m_indPopup = NULL;
    m_profInst->sendCancel();

    if (options & VFX_APP_CLOSE_OPTION_LATER_FLAG)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_KILL_BY_OOM);	
#endif
        m_sendOOMExitFlag = VFX_TRUE;
        return VFX_APP_CLOSE_ANSWER_LATER;
    }
    return VFX_APP_CLOSE_ANSWER_YES;
}

void VappBTSendApp::initApp()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDAPP_INITAPP);
    m_connectFail = VFX_FALSE;
    m_sendTransFileBegin = VFX_FALSE;
    m_sendOOMExitFlag = VFX_FALSE;
    m_waitPopup = NULL;
    m_indPopup = NULL;
    m_sendFileCount = m_sendingPara.m_total;
	m_remainCaculCount = m_sendFileCount;
	m_currentFileIndex = -1;// means have not send.
	m_sendedFilesSize = 0;
	m_totalFileSize = 0x7FFFFFFF;
	m_currentPersent = 0;
	m_calculSize = 0;
	m_successSendCount = 0; //neams no file be sended sucessfully.
    VFX_OBJ_CREATE(m_profInst,VappBTOPPClient,this);
    VappBTOPPClient::m_inst = (VappBTOPPClient *)m_profInst;
	m_profInst->m_signal.connect(this,&VappBTSendApp::profSigHandler);
	if(VAPP_OPP_SENDING_OBJ == m_sendObjType && m_sendFileCount > 1)
		calculateSize();

	//start now.
	m_profInst->sendBegin(&(m_sendingPara.m_addr));
}


/*---------------------------------------------------------------------------*
 * Function: notifyOngoingCell()
 * Description: notify sending process cell in NCenter2.0.
 *---------------------------------------------------------------------------*/
void VappBTSendApp::notifyOngoingCell()
{
//local var:
	VsrvNGroupSingleTitle *group = NULL;
//func implementation:
	VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle,(VAPP_BT_SEND));
	group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BLUETOOTH));
	
	VSRV_NOTIFICATION_CREATE_EX(m_notify, VsrvNotificationOngoing,((VsrvNGroup*)group,1));
	m_notify->setIcon(VfxImageSrc(IMG_ID_VAPP_BT_NC_SEND));
	m_notify->setQuestionText(VFX_WSTR_RES(STR_ID_VAPP_BT_DISCARD_SENDING));
	m_notify->setIntentCallback(&VappBTSendApp::notifyOngoingCallback);
	updateOngoingCell(VAPP_OPP_UPDATE_ALL);
}

/*---------------------------------------------------------------------------*
 * Function: notifyOngoingCallback()
 * Description: NCenter2.0 cell clicked callback function.
 *---------------------------------------------------------------------------*/
void VappBTSendApp::notifyOngoingCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
//local var:
	
//func implementation:
    if(m_selfInst)
    {
		if(intent.type == VSRV_NINTENT_TYPE_LAUNCH)
		{
		    if (m_selfInst->getHidden())
		        m_selfInst->setHidden(VFX_FALSE);
		    else
		        m_selfInst->setActive();
		}
		else if(intent.type == VSRV_NINTENT_TYPE_TERMINATE)
		{
	        if (m_selfInst)
	    		m_selfInst->sendCancel(NULL, NULL);
		}
    }
}

/*---------------------------------------------------------------------------*
 * Function: updateOngoingCell()
 * Description: update the sending cell in NCenter.
 *---------------------------------------------------------------------------*/
void VappBTSendApp::updateOngoingCell(VfxU32 aUpdateType)
{
//local var:

//func implementation:
	if(m_notify)
	{
		if(aUpdateType&VAPP_OPP_UPDATE_FILE_NAME)
		{
			m_notify->setMainText(m_fileName);
		}
		else if(aUpdateType&VAPP_OPP_UPDATE_PROCESSING)
		{
			m_notify->setSubText(m_persentStr);
		}
		else
		{
			return;
		}
		m_notify->notify();
	}
}

/*---------------------------------------------------------------------------*
 * Function: removeOngoingCell()
 * Description: remove the sending cell from NCenter.
 *---------------------------------------------------------------------------*/
void VappBTSendApp::removeOngoingCell()
{
//local var:
	VsrvNCenter *nm; 
    VsrvNGroup *ngroup;
//func implementation:
	nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);  
    ngroup = nm->queryNGroup(VAPP_BT_SEND);
	if(ngroup)
		VSRV_NOTIFICATION_CLOSE_EX(ngroup,1);
}

/*---------------------------------------------------------------------------*
 * Function: paraseFileName()
 * Description: get the file name from full path name
 *    @return: the string of file name
 *---------------------------------------------------------------------------*/
VfxWChar *VappBTSendApp::paraseFileName(VfxWChar *aFilePathAndName)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_GEN_NAME_STR);	
#endif

//local var:
	VfxS32 len;
//func implementation:
	len = (VfxS32) mmi_wcslen(aFilePathAndName);
    while (len > 0)
    {
        len--;
        /* This is a Byte Order dependency algorithm
           need to guarantee name is Little Endian */
        if (aFilePathAndName[len] == '\\')
        {
            return aFilePathAndName + (len + 1);
        }
    }
    return aFilePathAndName;
}


inline void VappBTSendApp::sendObj()
{	
	VfxWChar *fileName;
	m_currentFileIndex++;
	if(m_sendObjType == VAPP_OPP_SENDING_OBJ)
	{
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_IS_SEND_VCARD,0);	
#endif
    if (m_sendingPara.m_total == 1)
    	m_filePathAndName = m_sendingPara.m_sendFileName;
    else 
		  m_filePathAndName = m_sendingPara.m_nameArray[m_currentFileIndex];
	}
	else//send vCards.
	{
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_IS_SEND_VCARD,1);	
#endif
		((vapp_bt_send_get_next_obj)(m_sendingPara.m_callback))(m_filePathAndName, m_sendingPara.m_appData);

		if(m_sendFileCount > 1)//more than one vCard to be send, need update progress.
		{
			updateProgress(VFX_TRUE);
		}
	}
	if((VfxS16)(m_filePathAndName[0]) == 0)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_SEND_FILE_NAME_NULL);
		return;
	}
	fileName = paraseFileName(m_filePathAndName);
	m_fileName = VFX_WSTR_MEM(fileName);
	m_profInst->sendObject(m_filePathAndName, fileName);
}

void VappBTSendApp::sendCancel(VfxObject* obj, VfxFloat percent)
{
    if (m_sendTransFileBegin)
    {
        vapp_bt_update_status(BT_NOTIFY_TRANS_END);
		StopTimer(MMI_TIMER_UPDATE_PROGRESS);//FMGR_PROG_UPDATE_TIMER
        m_sendTransFileBegin = VFX_FALSE;
    }

    VcpIndicatorPopup* cancelPopup;
    VFX_OBJ_CREATE(cancelPopup, VcpIndicatorPopup, m_mainScr);
    cancelPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    cancelPopup->setText(VFX_WSTR_RES(STR_GLOBAL_CANCELLING));
    cancelPopup->setAutoDestory(VFX_TRUE);
    cancelPopup->show(VFX_TRUE);

    m_indPopup = NULL;
    m_profInst->sendCancel();

    //exit();
}

void VappBTSendApp::profSigHandler(VfxU32 evt)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDAPP_PROFSIGHDLR, evt);
#endif
	FS_HANDLE fileHandle;
	VfxU32 len;

    switch (evt)
    {
    case BTSEND_PROF_FORBIDDEN:
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_FAIL_FOR_FORBIDDEN, __LINE__);
#endif
        errorHandle(BTSEND_NO_INSTANCE);
        break;
    case BTSEND_PROF_BEGAIN_READY:
        VFX_OBJ_CLOSE(m_waitPopup);
        showSendingPopup();
		if(m_sendObjType == VAPP_OPP_SENDING_OBJ || m_sendFileCount == 1)
			StartTimer(MMI_TIMER_UPDATE_PROGRESS, BTSEND_PROG_UPD_DUR, &VappBTSendApp::handleUpdateTimerEvent);
		
        sendObj();
		notifyOngoingCell();
        vapp_bt_update_status(BT_NOTIFY_TRANS_BEGIN);
        m_sendTransFileBegin = VFX_TRUE;
        break;
    case BTSEND_PROF_CONNECT_FAIL:
        m_connectFail = VFX_TRUE;
        break;
    case BTSEND_PROF_SEND_SUCCESS:
		m_successSendCount++;
        if (m_currentFileIndex < m_sendFileCount - 1)
        {
			// add send file size to m_sendedFilesSize.
		    fileHandle = FS_Open(m_filePathAndName, FS_READ_ONLY);
    		FS_GetFileSize(fileHandle, &len);
    		m_sendedFilesSize += len;
			FS_Close(fileHandle);
		}
		else
		{// showing 100% to user.
			m_currentPersent = 100;
			composeStr();
			m_indPopup->setProgress((VfxFloat)1);
			m_indPopup->setText(m_persentStr);
			updateOngoingCell(VAPP_OPP_UPDATE_PROCESSING);
		}
    case BTSEND_PROF_SEND_FAIL:
    case BTSEND_PROF_BAD_OBJECT:
    case BTSEND_PROF_DRM_PROHIB:
		if (m_sendingPara.m_option == VAPP_BT_SEND_DELETE_FILE)
		{
			FS_Delete(m_filePathAndName);
		}
		if (m_currentFileIndex < m_sendFileCount - 1)
		{
            sendObj();
			updateOngoingCell(VAPP_OPP_UPDATE_FILE_NAME);
		}
		else
        	m_profInst->sendEnd();
        break;
    case BTSEND_PROF_SEND_END:
        if (m_sendingPara.m_option == VAPP_BT_SEND_DELETE_FILE)
		{
			FS_Delete(m_filePathAndName);
		}
        m_profInst->sendEnd();
        break;
    case BTSEND_PROF_USB_UNAVAILABLE:
    case BTSEND_PROF_ABNORMAL_DONE:
        if (m_sendTransFileBegin)
        {
            vapp_bt_update_status(BT_NOTIFY_TRANS_END);
            m_sendTransFileBegin = VFX_FALSE;
        }

        if (m_sendOOMExitFlag)
        {
            m_sendOOMExitFlag = VFX_FALSE;
            continueClose(VFX_APP_CLOSE_ANSWER_YES);
            return;
        }
        exit();
        break;
    case BTSEND_PROF_DONE:
        if (m_sendTransFileBegin)
        {
            vapp_bt_update_status(BT_NOTIFY_TRANS_END);
            m_sendTransFileBegin = VFX_FALSE;
        }

        if (m_sendOOMExitFlag)
        {
            m_sendOOMExitFlag = VFX_FALSE;
            continueClose(VFX_APP_CLOSE_ANSWER_YES);
        }
        else
        {
            errorHandle(BTSEND_RESULT_DONE);
        }
        break;

    default:
        break;
    }
}


void VappBTSendApp::showSendingPopup()
{
    VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, m_mainScr);
    m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_indPopup->setAutoDestory(VFX_TRUE);  
    m_indPopup->setIsAnimate(VFX_FALSE);
	updateProgress(VFX_TRUE);
    m_indPopup->show(VFX_TRUE);
    m_indPopup->m_signalCanceled.connect(this, &VappBTSendApp::sendCancel);
}

void VappBTSendApp::updateProgress(VfxBool aForceUpdate)
{
	VfxU32 totalSendedSize;
    VfxS32 currentPersent;
	VfxFloat persent;
	srv_opp_obj_info_struct sendInfo;
	m_profInst->getCurrentProgess(&sendInfo);
	totalSendedSize = m_sendedFilesSize + sendInfo.total_obj_len - sendInfo.remain_put_len;

	if(m_indPopup)
	{
		if((totalSendedSize == 0&& m_sendObjType==VAPP_OPP_SENDING_OBJ)||m_currentFileIndex < 0)
		{
			m_currentPersent = 0;
			composeStr();
			m_indPopup->setProgress(0);
			m_indPopup->setText(m_persentStr);
				return;
		}

		if(m_sendFileCount == 1)
		{
			m_totalFileSize = sendInfo.total_obj_len;
			persent = (((VfxFloat)totalSendedSize)/m_totalFileSize)* 100;
			currentPersent = (VfxS32)persent;
		}
		else if(m_sendObjType == VAPP_OPP_SENDING_VCARD)
		{
			currentPersent = m_currentFileIndex*100 / m_sendFileCount;
		}
		else
		{
			persent = (((VfxFloat)totalSendedSize)/m_totalFileSize) * 100;
			currentPersent = (VfxS32)persent;
		}
		if(currentPersent != m_currentPersent || aForceUpdate)
		{
			m_currentPersent = currentPersent;
			composeStr();
	        m_indPopup->setProgress(((VfxFloat)m_currentPersent) / 100);
	        m_indPopup->setText(m_persentStr);
			updateOngoingCell(VAPP_OPP_UPDATE_PROCESSING);
		}
	}
}

void VappBTSendApp::composeStr()
{
    VfxWChar buff[20];
	m_persentStr = VFX_WSTR_RES(STR_ID_VAPP_BT_SENDING);
    if (VAPP_OPP_SENDING_OBJ == m_sendObjType || m_sendFileCount == 1)
    {
		kal_wsprintf(&buff[0],"(%d%c)",m_currentPersent,'%');
    }
    else
    {
        kal_wsprintf(&buff[0],"(%d%c%d)", m_currentFileIndex + 1, '/', m_sendFileCount);
    }
    m_persentStr += VFX_WSTR_MEM(buff);
}

void VappBTSendApp::stopSending()
{
    if (m_selfInst == NULL)
        return;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDAPP_STOPSENDING);
    m_selfInst->sendCancel(NULL, NULL);
}

/*---------------------------------------------------------------------------*
 * Function: handleUpdateTimerEvent()
 * Description: update the progress bar, every second. 
 *---------------------------------------------------------------------------*/
void VappBTSendApp::handleUpdateTimerEvent()
{
//local var:
	
//func implementation:
	if(m_selfInst)
	{
		m_selfInst->updateProgress(VFX_FALSE);
		StartTimer(MMI_TIMER_UPDATE_PROGRESS, BTSEND_PROG_UPD_DUR, &VappBTSendApp::handleUpdateTimerEvent);
	}
	else
		StopTimer(MMI_TIMER_UPDATE_PROGRESS);
}


void VappBTSendApp::calculateSize()
{
    FS_HANDLE handle;
    VfxU32 len;
	VfxWChar* fileName;
	if(m_selfInst)
	{
		fileName = m_selfInst->m_sendingPara.m_nameArray[m_selfInst->m_remainCaculCount - 1];
	    handle = FS_Open(fileName, FS_READ_ONLY);
	    if (handle >= FS_NO_ERROR)
	    {
	        FS_GetFileSize(handle, &len);
	        m_selfInst->m_calculSize += len;
	    }
	    FS_Close(handle);
	    
	    m_selfInst->m_remainCaculCount--;
	    if (m_selfInst->m_remainCaculCount > 0)
	    {
	        StartTimer(MMI_TIMER_CACULATE_FILES_SIZE, BTSEND_CALCU_SIZE, &VappBTSendApp::calculateSize);
	    }
		else
		{
#ifdef __VAPP_BT_DEBUG_INTENAL__
			MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SEND_TOTAL_SIZE);	
#endif
	    	StopTimer(MMI_TIMER_CACULATE_FILES_SIZE);//BT_OPP_CACULATE_SENDING_SIZE
			m_selfInst->m_totalFileSize = m_selfInst->m_calculSize;
		}
	}
		
}

void VappBTSendApp::errorHandle(BTSendResultEnum cod)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SENDAPP_ERROR, cod);

    VfxWChar* str = NULL;
    VfxWChar tmp[20];
	VfxResId strId = 0;
    mmi_event_notify_enum type = MMI_EVENT_BLUETOOTH;
    switch (cod)
    {
        case BTSEND_RESULT_DONE:
            if (m_connectFail)
            {
				strId = STR_ID_VAPP_BT_FAIL_CONNECT;
            }
            else  if (m_currentFileIndex < 0)//have not start to send.
            {
				strId = STR_ID_VAPP_BT_FAIL_SEND;//"Failed to send"
                
            }
            else if (m_sendFileCount == 1 && m_successSendCount == 1)
            {
				strId = STR_ID_VAPP_BT_SENT;//"File sent"
            }
            else if (m_successSendCount == m_sendFileCount)
            {
				strId = STR_ID_VAPP_BT_ALL_SENT;//"All files sent"
            }
			if(strId)
			{
				break;
			}
			
            if (m_successSendCount == m_sendFileCount - 1)
            {
				strId = STR_ID_VAPP_BT_ONE_NOT_SENT;
            }
            else
            {
				strId = STR_ID_VAPP_BT_NOT_ALL_SENT;
            }
			kal_wsprintf(&tmp[0],"%d%w", 
                m_sendFileCount - m_successSendCount,
                (WCHAR*)GetString(strId));
			str = tmp;
            break;
        case BTSEND_NO_INSTANCE:
			type = MMI_EVENT_INFO_BALLOON;
			strId = STR_ID_VAPP_BT_NOT_AVAILABLE;
			break;

        default:
        	return;
    }
	if(!str)
		str = (WCHAR *)GetString(strId);
    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
        type,
        MMI_NMGR_BALLOON_TYPE_INFO,
        str);
    exit();
}

/*****************************************************************************
 * Class VappBTSendingProf
 *****************************************************************************/

VfxU32 VappBTSendingProf::objAvailable(VfxU16 * aFile)
{
        
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        if (srv_usb_check_path_exported((WCHAR *)aFile))
        {
#ifdef __VAPP_BT_DEBUG_INTENAL__
			MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SEND_USB_UNAVAILABLE);	
#endif			
            return BTSEND_PROF_USB_UNAVAILABLE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    
    if ((m_reason = FS_Open(aFile, FS_READ_ONLY)) < FS_NO_ERROR)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
			MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_CAN_NOT_OPEN_SENDIND_FILE, m_reason);	
#endif	

        return BTSEND_PROF_BAD_OBJECT;
    }
    FS_Close(m_reason);
    /* DRM check: if allow to forward out */
#if defined(__DRM_SUPPORT__)
    if (!DRM_interdev_movable(0, aFile))
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DRM_FAIL);	
#endif	

        return BTSEND_PROF_DRM_PROHIB;
    }
#endif /* defined(__DRM_SUPPORT__) */
    
    return BTSEND_PROF_SUCCESS;

}

/*****************************************************************************
 * Class VappBTOPPClient
 *****************************************************************************/
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
extern "C" kal_bool jvm_util_is_midlet_msg_file(kal_wchar *midlet_msg_path);
#endif 
VappBTOPPClient* VappBTOPPClient::m_inst = NULL;
VfxBool VappBTOPPClient::sendBegin(srv_bt_cm_bt_addr *addr)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPPCLIENT_SENDBEGIN);

    VfxU32 event_mask;
    VfxS32 result;
    
    m_srvHd = srv_opp_open(SRV_OPP_ROLE_CLIENT);
    if (m_srvHd < 0)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_MMI_FAIL_LINE, __LINE__);	
#endif	
        m_signal.postEmit(BTSEND_PROF_FORBIDDEN);
        return VFX_FALSE;
    }

    //set callback
    event_mask = SRV_OPP_EVENT_CONN_NOTIFY | SRV_OPP_EVENT_SND_NOTIFY | SRV_OPP_EVENT_DISCONN_NOTIFY;
    srv_opp_set_notify(m_srvHd, event_mask, 
        (bt_notify)&VappBTOPPClient::eventHandler);
    
    result = srv_oppc_send_begin(m_srvHd, addr, (U8*)&m_buff, BUF_LENGTH);
    if (result == SRV_OPP_RESULT_OK)
    {
        return VFX_TRUE;
    }
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_MMI_FAIL_LINE, __LINE__);	
#endif
    m_signal.postEmit(BTSEND_PROF_FORBIDDEN);
    return VFX_FALSE;
    
}

void VappBTOPPClient::sendObject(VfxWChar *aFilePathAndName, VfxWChar* aFileName)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPPCLIENT_SENDOBJ);
    VfxU32 retval;

    VFX_ASSERT(aFilePathAndName);
    retval = objAvailable(aFilePathAndName);
    if (retval != BTSEND_PROF_SUCCESS)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_MMI_FAIL_LINE, __LINE__);	
#endif
        m_signal.postEmit(retval);
        return;
    }
    if (m_flag&MMIOPP_MASK_SDP_FORMAT)
    {
        if (isJarFile(aFileName, aFilePathAndName))
        {
            m_flag |= MMIOPP_MASK_FILE_TYPE;
#ifdef __VAPP_BT_DEBUG_INTENAL__
			MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_MMI_FAIL_LINE, __LINE__);	
#endif
            m_signal.postEmit(BTSEND_PROF_SEND_FAIL);
            return;
        }
    }
    srv_oppc_send_obj(m_srvHd, aFilePathAndName, aFileName);
}

void VappBTOPPClient::sendEnd()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPPCLIENT_SENDEND);
    srv_oppc_send_end(m_srvHd);
}

void VappBTOPPClient::sendCancel()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPPCLIENT_SENDCANCEL);
    m_flag |= MMIOPP_MASK_ABORT_PRESS;
    srv_oppc_send_end(m_srvHd);
}

VfxS32 VappBTOPPClient::eventHandler(VfxS32 hd, VfxU32 eventId, void *para)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPPCLIENT_EVENTHDLR, eventId, hd);

    if (hd <= 0 || m_inst == NULL)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    if (hd == m_inst->m_srvHd)
    {
        switch (eventId)
        {
            case SRV_OPP_EVENT_CONN_NOTIFY:
                m_inst->connectIndHandler(para);
                break;

            case SRV_OPP_EVENT_SND_NOTIFY:
                m_inst->sendIndHandler(para);
                break;

           // case SRV_OPP_EVENT_DISCONN_NOTIFY:
           //     m_inst->disconnIndHandler(para);
           //     break;

            default:
                return SRV_OPP_RESULT_INVALID_PARAM;
        }

        return SRV_OPP_RESULT_OK;
    }

    return SRV_OPP_RESULT_INVALID_HANDLE;
}

void VappBTOPPClient::connectIndHandler(void *para)
{
    srv_opp_conn_notify_struct *conn_notify = (srv_opp_conn_notify_struct*) para;
    
    if (conn_notify->type != SRV_OPP_CONN_SUCC)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_CONNECT_FAIL);	
#endif
        m_signal.postEmit(BTSEND_PROF_CONNECT_FAIL);
    }

}

void VappBTOPPClient::sendIndHandler(void *para)
{
    srv_opp_snd_notify_struct *snd_result = (srv_opp_snd_notify_struct*) para;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPPCLIENT_SENDINDHDLR, snd_result->type);
	VfxU32 eventId;
    switch (snd_result->type)
    {
        case SRV_OPP_SND_READY:
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)

                if (snd_result->supported_formats != 0xFF)
                {
                    m_flag |= MMIOPP_MASK_SDP_FORMAT;
                }
#endif /* defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__) */
        case SRV_OPP_SND_SUCC:
        case SRV_OPP_SND_FAIL:
        case SRV_OPP_SND_FAIL_BY_SERVER:
			eventId = BTSEND_PROF_BEGAIN_READY + snd_result->type;
            break;
		case SRV_OPP_SND_DONE:
			if (m_flag & (MMIOPP_MASK_USB_PLUG_IND | MMIOPP_MASK_ABORT_PRESS))
			{
				/* when user press end key or plug in usb, shall not popup "unfinished" */
				eventId = BTSEND_PROF_ABNORMAL_DONE;
			}
			else
			{
				eventId = BTSEND_PROF_DONE;
			}
			break;

/*        case SRV_OPP_SND_PERSENT:
            return;
*/


        default:
            return;

    }
	m_signal.postEmit(eventId);

}


/*---------------------------------------------------------------------------*
 * Function: getCurrentProgess()
 * Description: virtual function from VappBTSendingProf, for supplying sending Progess.
 *---------------------------------------------------------------------------*/
void VappBTOPPClient::getCurrentProgess(srv_opp_obj_info_struct *aObjInfo)
{
//local var:
	
//func implementation:
	srv_oppc_get_obj_info(aObjInfo);
}

VfxBool VappBTOPPClient::isJarFile(VfxU16 *name, VfxU16 *path)
{
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    VfxU16 mimeSubType;
    applib_mime_type_struct *mimeType;
    
    mimeType = applib_mime_get_file_type((kal_wchar*) name);
    mimeSubType = mimeType?mimeType->mime_subtype:MIME_SUBTYPE_NONE;


    if (jvm_util_is_midlet_msg_file(path) ||
        mimeSubType == MIME_SUBTYPE_DRM_CONTENT)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
#else
    return VFX_FALSE;
#endif
}

#endif /*__MMI_OPP_SUPPORT__*/

