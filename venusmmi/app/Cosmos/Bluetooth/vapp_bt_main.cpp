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
 *  vapp_bt_main.cpp
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h" 
#ifdef __MMI_BT_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Vcp_include.h"
extern "C"
{
#include "gui_typedef.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "wgui_categories_util.h"
#include "BtcmSrvGprot.h"
#include "conversions.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "BTMMISIMAPGprots.h"
#include "GlobalResDef.h"
#include "MMI_conn_app_trc.h"
#include "BthScoPathSrvGProt.h"
}

#include "vcp_form.h"
#include "vapp_bt_device.h"
#include "vapp_bt_main.h"
#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_storage.h"
#include "vcp_text_editor.h"
#include "vfx_object.h"
#include "vapp_bt_manager.h"
#include "vcui_bt_gprot.h"
#include "vapp_bt_cui.h"
#include "vapp_ncenter_gprot.h" // for vapp_ncenter_disable_leave

/***************************************************************************** 
 * Define
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


//for vapp_bt_exit_usb_ms_hdlr and vapp_bt_enter_usb_ms_hdlr ... can't be removed.
VappBtSettingPage* VappBtSettingPage::m_btSettingPageSelf = NULL; 

void VappBtSettingPage::btSettingEventHandle(U32 event, void* para)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGPAGE_BTSETTINGEVENTHANDLE,
        event,
        VappBtSettingPage::m_btSettingPageSelf);
#endif  // __VAPP_BT_DEBUG_INTENAL__
	VappBtSettingPage* page = (VappBtSettingPage*)VfxObject::handleToObject(((srv_bt_cm_set_visibility_struct*)para)->user_data);

    if (page)
    {
        //srv_bt_cm_set_visibility_struct* res = (srv_bt_cm_set_visibility_struct*)para;
        
        switch (event)
        {
            case SRV_BT_CM_EVENT_SET_VISIBILITY:
                page->m_visibility->setSwitchStatus(
                    srv_bt_cm_get_visibility() != SRV_BT_CM_VISIBILITY_OFF);
                break;

            case SRV_BT_CM_EVENT_SET_NAME:
            {
                page->m_hostNameString = page->getHostName();
                page->m_hostname->setHintText(page->m_hostNameString);
                break;
            }

            // #ifdef __MMI_SIMAP_SUPPORT__
            //             case SRV_BT_CM_EVENT_SET_SIMAP:
            //                 page->m_simap->setSwitchStatus(
            //                     srv_bt_cm_is_simap_activate() ?
            //                     VFX_TRUE :
            //                     VFX_FALSE);
            //                 break;
            // #endif  // __MMI_SIMAP_SUPPORT__
        }
    }
}


void VappBtSettingPage::storageCellUpdate()
{
	if(m_btSettingPageSelf && m_btSettingPageSelf->m_storage)
	{
		VfxChar drive;
		VfxS32 accessibleOlnyDevCount;
		SRV_FMGR_DRVLIST_HANDLE drvListHd;
		drvListHd = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
		accessibleOlnyDevCount = srv_fmgr_drivelist_count(drvListHd);
		if(0 == accessibleOlnyDevCount)
		{
	    	m_btSettingPageSelf->m_storage->setIsDisabled(VFX_TRUE);
		}
		else if(1 == accessibleOlnyDevCount)
		{
			drive = (VfxChar)srv_fmgr_drivelist_get_drv_letter(drvListHd, 0);
			if(drive == VbtStorageSetting::get().m_drive)
		    	m_btSettingPageSelf->m_storage->setIsDisabled(VFX_TRUE);
			else 
		    	m_btSettingPageSelf->m_storage->setIsDisabled(VFX_FALSE);
		}
		else
			m_btSettingPageSelf->m_storage->setIsDisabled(VFX_FALSE);
		srv_fmgr_drivelist_destroy(drvListHd);
	}
}

void VappBtSettingPage::onInit()
{
	VfxS32 allDevCount;
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGPAGE_ONINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setBounds(VfxRect(VfxPoint(0, 0), getSize()));
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_visibility, VcpFormItemSwitchCell, m_form);
    m_visibility->setIsTappable(VFX_FALSE);
    m_visibility->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BT_VISIBILITY));
    m_visibility->setSwitchStatus(
        (srv_bt_cm_get_visibility() != SRV_BT_CM_VISIBILITY_OFF)); 
	
    m_visibility->m_signalSwitchChangeReq.connect(this, &VappBtSettingPage::onSwitchVisibility);
    m_form->addItem(m_visibility, 0);

    VFX_OBJ_CREATE(m_hostname, VcpFormItemLauncherCell, m_form);
    m_hostname->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BT_MY_DEVICE_NAME));

	m_hostNameString = getHostName();
    m_hostname->setHintText(m_hostNameString);
    m_hostname->m_signalTap.connect(this, &VappBtSettingPage::onButtonClick);
    m_form->addItem(m_hostname, 1);

	allDevCount = getDriveCount(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
	m_storage = NULL;
	//kal_prompt_trace(MOD_MMI, "[BT NAME]allDevCount = %d", allDevCount);
	if(allDevCount > 1)
	{	
		VfxChar drive;
		VfxS32 accessibleOlnyDevCount;
		SRV_FMGR_DRVLIST_HANDLE drvListHd;
	    VFX_OBJ_CREATE(m_storage, VcpFormItemLauncherCell, m_form);
	    m_storage->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BT_STORAGE));
	    VbtStorage storage = VbtStorageSetting::get();
	    m_storage->setHintText(VFX_WSTR_RES(srv_fmgr_drv_get_string((VfxU8)storage.m_drive)));
	    m_storage->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	    m_storage->m_signalTap.connect(this, &VappBtSettingPage::onButtonClick);
	    m_form->addItem(m_storage, 2);
		drvListHd = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
		accessibleOlnyDevCount = srv_fmgr_drivelist_count(drvListHd);
		if(0 == accessibleOlnyDevCount)
		{
	    	m_storage->setIsDisabled(VFX_TRUE);
		}
		else if(1 == accessibleOlnyDevCount)
		{
			drive = (VfxChar)srv_fmgr_drivelist_get_drv_letter(drvListHd, 0);
			if(drive == storage.m_drive)
		    	m_storage->setIsDisabled(VFX_TRUE);
		}
		srv_fmgr_drivelist_destroy(drvListHd);
	}
    m_cmSrvHd = srv_bt_cm_set_notify(
        &VappBtSettingPage::btSettingEventHandle,
        SRV_BT_CM_EVENT_SET_VISIBILITY | SRV_BT_CM_EVENT_SET_NAME,
        getObjHandle());
    VappBtSettingPage::m_btSettingPageSelf = this;
}

/*---------------------------------------------------------------------------*
 * Function: on2ndInit()
 * Description: be called by VfxMainScr::on2ndReady(), to load some data.
 *---------------------------------------------------------------------------*/
void VappBtSettingPage::on2ndInit()
{
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*---------------------------------------------------------------------------*
 * Function: getDriveCount()
 * Description: get the count of the phone driver.
 *    @return: return the count of the phone driver.
 *---------------------------------------------------------------------------*/
VfxU32 VappBtSettingPage::getDriveCount(srv_fmgr_drivelist_type_enum type)
{
//local var:
	SRV_FMGR_DRVLIST_HANDLE drvListHd;
	VfxU32 count;
//func implementation:
	drvListHd = srv_fmgr_drivelist_create(type);
    count = srv_fmgr_drivelist_count(drvListHd);
    srv_fmgr_drivelist_destroy(drvListHd);
	return count;
}

/*---------------------------------------------------------------------------*
 * Function: getHostName()
 * Description: remove duplicate codes.
 *    @return: return the host dev name string.
 *---------------------------------------------------------------------------*/
VfxWString VappBtSettingPage::getHostName()
{
//local var:
	VfxWChar name[SRV_BT_CM_BD_UCS2_NAME_LEN];
//func implementation:
    srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_host_dev_info();
    mmi_chset_utf8_to_ucs2_string((kal_uint8*)name, (SRV_BT_CM_BD_UCS2_NAME_LEN * 2), (kal_uint8*)dev_info->name);
    return VFX_WSTR_MEM(name);
}

void VappBtSettingPage::onDeinit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGPAGE_ONDEINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (m_cmSrvHd > 0)
    {
        srv_bt_cm_reset_notify(m_cmSrvHd);
        m_cmSrvHd = -1;
    }
    VappBtSettingPage::m_btSettingPageSelf = NULL;
    VfxPage::onDeinit();
}

void VappBtSettingPage::onSwitchVisibility(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
	srv_bt_cm_visibility_type setToType;
	setToType = status ? SRV_BT_CM_VISIBILITY_ON : SRV_BT_CM_VISIBILITY_OFF;
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGPAGE_ONSWITCHVISIBILITY,
        setToType);
#endif  // __VAPP_BT_DEBUG_INTENAL__
	srv_bt_cm_set_visibility(setToType);
}


void VappBtSettingPage::onSetDevNameHdlr(VfxObject* sender, VcpInputPopupButtonEnum res)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGPAGE_ONSETDEVNAMEHDLR,
        res);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (res)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VfxWString inputText;

            inputText = ((VcpInputPopup*)sender)->getText();
            const VfxWChar* name_ucs2 = inputText.getBuf();
            VfxU8 name_utf8[SRV_BT_CM_BD_FNAME_LEN];
            mmi_chset_ucs2_to_utf8_string(
                (kal_uint8*)name_utf8,
                SRV_BT_CM_BD_FNAME_LEN,
                (kal_uint8*)name_ucs2);
            srv_bt_cm_set_host_dev_name(name_utf8);
            //break; remove break to close the Popup.
        }
        case VCP_INPUT_POPUP_BTN_CANCEL:
            VFX_OBJ_CLOSE(sender);
            break;

        case VCP_POPUP_BUTTON_NO_PRESSED:
        default:
            break;
    }
}


void VappBtSettingPage::onEnter(VfxBool isBackward)
{
	if(isBackward&&m_storage)
	{
	    VbtStorage storage = VbtStorageSetting::get();
	    m_storage->setHintText(VFX_WSTR_RES(srv_fmgr_drv_get_string((VfxU8)storage.m_drive)));
	}
}



void VappBtSettingPage::onButtonClick(VcpFormItemCell*, VfxId Id)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGPAGE_ONBUTTONCLICK,
        Id);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (Id)
    {
        case 1: //click host name.
        {
            VcpInputPopup* inputPopup;
            VFX_OBJ_CREATE(inputPopup, VcpInputPopup, this);
            inputPopup->setAutoDestory(VFX_FALSE);
            inputPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BT_MY_DEVICE_NAME));
            inputPopup->setHintText(VFX_WSTR(""));

            inputPopup->setText(m_hostNameString, SRV_BT_CM_BD_UCS2_NAME_LEN - 1);

            inputPopup->setIME(IMM_INPUT_TYPE_SENTENCE);

            VcpTextEditor *textEditor = inputPopup->getInputbox();
            textEditor->setHighlight(0, m_hostNameString.getLength());

            inputPopup->m_signalButtonClicked.connect(this, &VappBtSettingPage::onSetDevNameHdlr);
            inputPopup->show(VFX_TRUE);
            break;
        }

        case 2: // click strage.
        {
            VbtStoragePage *storagePage;
            VFX_OBJ_CREATE(storagePage, VbtStoragePage, getMainScr());
            getMainScr()->pushPage(0, storagePage);
            break;
        }
        
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#endif

        // #ifdef __MMI_SIMAP_SUPPORT__
        //         case 3:
        //         {
        //             VfxBool state;
        //             srv_bt_cm_profile_struct simap_prof = {
        //                 SRV_BT_CM_SIM_ACCESS_PROFILE_UUID,
        //                 NULL,//mmi_bt_simap_activate,
        //                 NULL,//mmi_bt_simap_deactivate,
        //                 NULL //mmi_bt_simap_disconnect
        //             };
        //             if (srv_bt_cm_is_simap_activate())
        //             {
        //                 //simap_prof.deactivater = mmi_bt_simap_deactivate;
        //                 state = MMI_FALSE;
        //             }
        //             else
        //             {
        //                 //simap_prof.activater = mmi_bt_simap_activate;
        //                 state = MMI_TRUE;
        //             }
        //             srv_bt_cm_profile_register(&simap_prof);
        //             srv_bt_cm_set_simap((kal_bool)state);
        //         }
        //         break;
        // #endif  // __MMI_SIMAP_SUPPORT__

        default:
            VfxAppLauncher::terminate(getMainScr()->getGroupId());
            break;
    }
}


void VappBtSettingPage::onEnterMSHdlr(void)
{
	if(m_storage)
	{
	    m_storage->setHintText(VFX_WSTR(""));
	    m_storage->setIsDisabled(VFX_TRUE);
	}
}


void VappBtSettingPage::onExitMSHdlr(void)
{
	if(m_storage)
	{
	    VbtStorage storage = VbtStorageSetting::get();
	    m_storage->setHintText(VFX_WSTR_RES(srv_fmgr_drv_get_string((VfxU8)storage.m_drive)));
	    m_storage->setIsDisabled(VFX_FALSE);
	}
}



VFX_IMPLEMENT_CLASS("VappBtSettingApp", VappBtSettingApp, VfxCui);
void VappBtSettingApp::onRun(void* args, VfxU32 argSize)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGAPP_ONRUN);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VfxCui::onRun(args, argSize);
    VfxMainScrEx *screen;
	m_serviceHandle = srv_bt_cm_set_notify(&VappBtSettingApp::offEventsNotify, SRV_BT_CM_EVENT_DEACTIVATE, getObjHandle());
    VFX_OBJ_CREATE_EX(screen, VfxMainScrEx, this, (this));
    screen->show();
}


/*---------------------------------------------------------------------------*
 * Function: offEventsNotify()
 * Description: callback function, be called when BT is turn off.
 *---------------------------------------------------------------------------*/
void VappBtSettingApp::offEventsNotify(VfxU32 event, void* para)
{
//local var:
	VappBtSettingApp* selfApp;
	
//func implementation:
	selfApp = (VappBtSettingApp*)VfxObject::handleToObject(((srv_bt_cm_activate_struct*)para)->user_data);

	if(selfApp)
	{
		vapp_ncenter_disable_leave();
		selfApp->exit();
	}	
}

VfxPage* VappBtTabCtrlPage::onCreateTabPage(VfxId tabId)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTTABCTRLPAGE_ONCREATETABPAGE,
        tabId);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if(2 == tabId)
    {
        VappBTPairedListPage *page;
        VFX_OBJ_CREATE(page, VappBTPairedListPage, this);
        return page;
    }    
    return NULL;
}


/*---------------------------------------------------------------------------*
 * Function: onScr1stReady()
 * Description: virtual function from IVfxMainScrHandler, call back when the scr is ready.
 *---------------------------------------------------------------------------*/
void VappBtSettingApp::onScr1stReady(VfxMainScrEx *scr)
{
//local var:
    VappBtTabCtrlPage *pageTb;
	
//func implementation:
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGSCREEN_ON1STREADY);
#endif  // __VAPP_BT_DEBUG_INTENAL__
    VFX_OBJ_CREATE(pageTb, VappBtTabCtrlPage, scr);
	VFX_OBJ_CREATE(m_settingPage, VappBtSettingPage, pageTb);

    pageTb->addTab(1, VFX_WSTR_RES(STR_ID_VAPP_BLUETOOTH), VcpStateImage(IMG_ID_VAPP_BT_TAB_MAIN), m_settingPage);
    pageTb->addTab(2, VFX_WSTR_RES(STR_ID_VAPP_BT_PAIRED_DEVICE), VcpStateImage(IMG_ID_VAPP_BT_TAB_DEVICE));
    pageTb->setCurrTab(0);

    scr->pushPage(0, pageTb);
}

/*---------------------------------------------------------------------------*
 * Function: onScr2ndReady()
 * Description: virtual function from IVfxMainScrHandler, call back when the scr is 2nd ready.
 *---------------------------------------------------------------------------*/
void VappBtSettingApp::onScr2ndReady(VfxMainScrEx * scr)
{
//local var:
	
//func implementation:
	m_settingPage->on2ndInit();
}

/*---------------------------------------------------------------------------*
 * Function: onDeinit()
 * Description: 
 *---------------------------------------------------------------------------*/
void VappBtSettingApp::onDeinit()
{
//local var:
	
//func implementation:
	if(m_serviceHandle > 0)
	{
		//release old notifier.
        srv_bt_cm_reset_notify(m_serviceHandle);
		m_serviceHandle = 0;
	}	
}

// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
//VFX_IMPLEMENT_CLASS("VappBtCm", VappBtCm, VfxObject);
VfxS32 VappBtCm::m_cmSrvHd = -1;
VfxU8 VappBtCm::m_cmSetting = 0;
VfxBool VappBtCm::m_initPowerState = VFX_FALSE;
VfxSignal2 <VfxS32, VfxS32> VappBtCm::m_signalBtCm;

void VappBtCm::initCM(void* para)
{
    VfxU32 eventMask;
    eventMask = SRV_BT_CM_EVENT_ACTIVATE |
        SRV_BT_CM_EVENT_DEACTIVATE |
        SRV_BT_CM_EVENT_CONNECT_RES |
        SRV_BT_CM_EVENT_DISCONNECT_IND |
        SRV_BT_CM_EVENT_RELEASE_ALL_CONN |
        SRV_BT_CM_EVENT_PANIC_IND;
	
    VappBtCm::m_cmSrvHd = srv_bt_cm_set_notify((srv_bt_cm_notifier)&VappBtCm::btCmEventHandle, eventMask, NULL);
    VappBtCm::m_initPowerState = VFX_FALSE;

#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTCM_ONINIT,
        VappBtCm::m_cmSrvHd);
#endif  // __VAPP_BT_DEBUG_INTENAL__

}


void VappBtCm::onInitPower(void)
{
    VfxBool flight_mode;
    VfxS16 err;
    
    flight_mode = !(srv_mode_switch_is_network_service_available());
    ReadValue(NVRAM_BT_SETTING, &VappBtCm::m_cmSetting, DS_BYTE, &err);
    VappBtCm::m_cmSetting &= MMI_BT_MASK_ON;

#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTCM_ONINITPOWER,
        flight_mode,
        VappBtCm::m_cmSetting);
#endif  // __VAPP_BT_DEBUG_INTENAL__


    if (VappBtCm::m_cmSetting && !flight_mode)
    {
        srv_bt_cm_switch_on();
    }
    VappBtCm::m_initPowerState = VFX_TRUE;
    VappBtCm::m_signalBtCm.postEmit(VAPP_BT_EVENT_INIT_POWER, VFX_TRUE);
}


VfxBool VappBtCm::getInitPowerStatus(void)
{
    return VappBtCm::m_initPowerState;
}


void VappBtCm::btCmEventHandle(U32 event, void* para)
{
    VfxS16 err;

#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTCM_BTCMEVENTHANDLE,
        event);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (event)
    {
        case SRV_BT_CM_EVENT_ACTIVATE:
            if (VappBtCm::m_cmSetting & MMI_BT_MASK_OFF_BY_FLIGHT_MODE)
            {
                srv_bt_cm_switch_off();
                VappBtCm::m_cmSetting |= MMI_BT_MASK_ON;
            }
            else if (VappBtCm::m_cmSetting & MMI_BT_MASK_ON_BY_FLIGHT_MODE)
            {
                VappBtCm::m_cmSetting &= ~MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                
                srv_mode_switch_update_cb_func();
                /* deal with the case:
                 * 1. power on BT
                 * 2. swith from flight mode to normal mode
                 * so, to ensure all the profiles(like DUN, fax that will not be activated in flight mode) 
                 */
                srv_bt_cm_activate_profile();
            }
            else
            {
                VappBtCm::m_cmSetting |= MMI_BT_MASK_ON;
                if (VappBtCm::m_cmSetting & MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE)
                {
                    VappBtCm::m_cmSetting &= ~MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE;
                    srv_mode_switch_update_cb_func();
                }

            }
            WriteValue(NVRAM_BT_SETTING, &VappBtCm::m_cmSetting, DS_BYTE, &err);
			vapp_bt_update_status(BT_NOTIFY_ON);
            break;

        case SRV_BT_CM_EVENT_DEACTIVATE:
            if (VappBtCm::m_cmSetting & MMI_BT_MASK_OFF_BY_FLIGHT_MODE)
            {
                VappBtCm::m_cmSetting &= ~MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
                srv_mode_switch_update_cb_func();
			}
            else
            {
                if (VappBtCm::m_cmSetting & MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE)
                {
                    VappBtCm::m_cmSetting &= ~MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE;
                    srv_mode_switch_update_cb_func();
                }
                VappBtCm::m_cmSetting &= ~MMI_BT_MASK_ON;
            }
            vapp_bt_update_status(BT_NOTIFY_OFF);
            WriteValue(NVRAM_BT_SETTING, &VappBtCm::m_cmSetting, DS_BYTE, &err);
            break;

        case SRV_BT_CM_EVENT_CONNECT_RES:
            vapp_bt_update_status(BT_NOTIFY_CONN_UP);
            break;

        case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
        case SRV_BT_CM_EVENT_DISCONNECT_IND:
            if (srv_bt_cm_get_existed_conn_num() == 0)
            {
                vapp_bt_update_status(BT_NOTIFY_CONN_DOWN);
            }
            break;
			
		case SRV_BT_CM_EVENT_PANIC_IND:
#ifdef __MMI_BT_AUDIO_SUPPORT__
			srv_btsco_reset(&VappBtCm::btCmPanicHandle);
#else
			VappBtCm::btCmPanicHandle();
#endif
			break;

        default:
            break;
    }
}

void VappBtCm::btCmPanicHandle(void)
{
    srv_bt_cm_recover_panic_req();

    if (VappBtSettingPage::m_btSettingPageSelf)
    {
        VfxAppLauncher::terminate(VappBtSettingPage::m_btSettingPageSelf->getMainScr()->getGroupId());
    }

    if (VappBtPowerOnCui::m_btPowerOnCuiId != GRP_ID_INVALID)
    {
        vcui_bt_power_on_close(VappBtPowerOnCui::m_btPowerOnCuiId);
    }

    if (VappBtSelDevCui::m_btSelDevCuiId)
    {
        vcui_bt_select_device_close(VappBtSelDevCui::m_btSelDevCuiId);
    }

    vapp_bt_deinit();

    mmi_event_struct evt;
    vapp_bt_init(&evt);

    VappBtCm::m_initPowerState = VFX_TRUE;

    if (VappBtPowerSwitchCell::m_btPowerSwitchCellSelf)
    {
        VappBtPowerSwitchCell::m_btPowerSwitchCellSelf->btCmPanicHandle();
    }

    if (VappBtSettingCell::m_btSettingSelf)
    {
        VappBtSettingCell::m_btSettingSelf->btCmPanicHandle();
    }

    vapp_bt_update_status(BT_NOTIFY_OFF);
}

extern "C"
MMI_RET vapp_bt_init_power(mmi_event_struct *evt)
{
    VappBtCm::onInitPower();
    return MMI_RET_OK;
}

extern "C"
MMI_RET vapp_bt_flight_mode_ind_handle(mmi_event_struct *para)
{
    VfxS16 err;

    if (EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY == para->evt_id)
    {
        srv_mode_switch_notify_struct* msg = (srv_mode_switch_notify_struct*)para;

#ifdef __VAPP_BT_DEBUG_INTENAL__
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            MMI_VAPP_BT_FLIGHT_MODE_IND_HANDLE,
            msg->select_flight_mode);
#endif  // __VAPP_BT_DEBUG_INTENAL__

        switch (srv_bt_cm_get_power_status())
        {
            case SRV_BT_CM_POWER_ON:
            {
				if (SRV_MODE_SWITCH_ON == msg->select_flight_mode)
				{
                    VappBtCm::m_cmSetting |= MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
                	srv_bt_cm_switch_off();
				}
                else
                {
					VappBtCm::m_cmSetting |= MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                    srv_bt_cm_activate_profile();
                }
				break;
            }
            case SRV_BT_CM_POWER_OFF:
				if ((SRV_MODE_SWITCH_ON == msg->select_flight_mode) ||
					!(VappBtCm::m_cmSetting & MMI_BT_MASK_ON))
				{
                	srv_mode_switch_update_cb_func();
				}
				else
				{
                    VappBtCm::m_cmSetting |= MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                    WriteValue(NVRAM_BT_SETTING, &VappBtCm::m_cmSetting, DS_BYTE, &err);
                    srv_bt_cm_switch_on();
            	}
                break;

            case SRV_BT_CM_POWER_SWITCHING_ON:
				if (SRV_MODE_SWITCH_ON == msg->select_flight_mode)
				{
                	VappBtCm::m_cmSetting |= MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
				}
                else
                {
                    VappBtCm::m_cmSetting &= ~MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
                    VappBtCm::m_cmSetting |= MMI_BT_MASK_ON_BY_FLIGHT_MODE;
                }
                break;

            case SRV_BT_CM_POWER_SWITCHING_OFF:
                VappBtCm::m_cmSetting |= MMI_BT_MASK_JUST_NOTIFY_FLIGHT_MODE;
				if (SRV_MODE_SWITCH_ON != msg->select_flight_mode)
				{
                    VappBtCm::m_cmSetting &= ~MMI_BT_MASK_OFF_BY_FLIGHT_MODE;
                    VappBtCm::m_cmSetting &= ~MMI_BT_MASK_ON_BY_FLIGHT_MODE;
				}
                break;
        }
 
        VappBtCm::m_signalBtCm.postEmit(VAPP_BT_EVENT_SWITCHH_FLIGHT_MODE, VFX_TRUE);
    }

    return MMI_RET_OK;
}


extern "C"
MMI_RET vapp_bt_enter_usb_ms_hdlr(mmi_event_struct *para)
{
    if (VappBtSettingPage::m_btSettingPageSelf)
    {
        VappBtSettingPage::m_btSettingPageSelf->onEnterMSHdlr();
    }

    VbtStoragePage* storagePage = VbtStoragePage::getInstance();
    if (storagePage)
    {
        storagePage->invokeProc(para);
    }

    return MMI_RET_OK;
}


extern "C"
MMI_RET vapp_bt_exit_usb_ms_hdlr(mmi_event_struct *para)
{
    if (VappBtSettingPage::m_btSettingPageSelf)
    {
        VappBtSettingPage::m_btSettingPageSelf->onExitMSHdlr();
    }

    return MMI_RET_OK;
}


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
VFX_IMPLEMENT_CLASS("VappBtPowerSwitchCell", VappBtPowerSwitchCell, VcpFormItemSwitchCell);
VappBtPowerSwitchCell* VappBtPowerSwitchCell::m_btPowerSwitchCellSelf = NULL;

void VappBtPowerSwitchCell::onInit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERSWITCHCELL_ONINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VcpFormItemSwitchCell::onInit();

    setIsTappable(VFX_FALSE);
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_BLUETOOTH));
    m_signalSwitchChangeReq.connect(this, &VappBtPowerSwitchCell::onSwitch);
	srv_bt_cm_power_status_enum btPowerStatus = srv_bt_cm_get_power_status();
	setSwitchStatus(SRV_BT_CM_POWER_ON == btPowerStatus);
	if(btPowerStatus&0x2)//SRV_BT_CM_POWER_SWITCHING_ON or SRV_BT_CM_POWER_SWITCHING_OFF
	{
        showProcessInd();
	}
	
    if (!VappBtCm::getInitPowerStatus())
    {
        setIsDisabled(VFX_TRUE);
    }

    VappBtCm::m_signalBtCm.connect(this, &VappBtPowerSwitchCell::onReceiveBtCmEvent);
    m_cmSrvHd = srv_bt_cm_set_notify(
        &VappBtPowerSwitchCell::btPowerSwitchEventHandle,
        SRV_BT_CM_EVENT_ACTIVATE | SRV_BT_CM_EVENT_DEACTIVATE | SRV_BT_CM_EVENT_RELEASE_ALL_CONN,
        getObjHandle());
    m_confirmFlag = 0;
    m_confirmPopup = NULL;
	m_btPowerSwitchCellSelf = this;
}


void VappBtPowerSwitchCell::onDeinit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERSWITCHCELL_ONDEINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VcpFormItemSwitchCell::onDeinit();
    if (m_cmSrvHd > 0)
    {
        srv_bt_cm_reset_notify(m_cmSrvHd);
        m_cmSrvHd = -1;
    }

    m_confirmFlag = 0;
	m_btPowerSwitchCellSelf = NULL;
}


void VappBtPowerSwitchCell::onReceiveBtCmEvent(VfxS32 event, VfxS32 result)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERSWITCHCELL_ONRECEIVEBTCMEVENT,
        event,
        result);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (event)
    {
        case VAPP_BT_EVENT_INIT_POWER:
            setIsDisabled(VFX_FALSE);
            break;

        case VAPP_BT_EVENT_SWITCHH_FLIGHT_MODE:
			{
				srv_bt_cm_power_status_enum powerStatus = srv_bt_cm_get_power_status();
            	if (powerStatus == SRV_BT_CM_POWER_SWITCHING_ON 
                	|| SRV_BT_CM_POWER_SWITCHING_OFF == powerStatus)
            	{
                    showProcessInd();
            	}
        	}
            break;
        default:
            break;
    }
}


void VappBtPowerSwitchCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERSWITCHCELL_ONSWITCH,
        status);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (srv_mode_switch_is_switching())
    {
        return;
    }

    if (VappBtCm::getInitPowerStatus())
    {
        switch (srv_bt_cm_get_power_status())
        {
            case SRV_BT_CM_POWER_OFF:
                if (!srv_mode_switch_is_network_service_available()) // ZHY: if in flight mode
                {
#ifdef __MMI_BT_IN_FLIGHT_MODE__
                    m_confirmFlag = VAPP_BT_POWER_ON_CONFIRM;
                    showConfirmScreen();
#else
					mmi_frm_nmgr_balloon(
					    MMI_SCENARIO_ID_DEFAULT,
					    MMI_EVENT_INFO_BALLOON,
					    MMI_NMGR_BALLOON_TYPE_INFO,
						(WCHAR *)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE)
					    );
#endif  //__MMI_BT_IN_FLIGHT_MODE__
                }
                else
                {
                    showProcessInd();
                    srv_bt_cm_switch_on();
                    //setIsDisabled(VFX_TRUE);
                }
                break;

            case SRV_BT_CM_POWER_ON:
                if (srv_bt_cm_get_existed_conn_num() > 0)
                {
                    m_confirmFlag = VAPP_BT_POWER_OFF_CONFIRM;
                    showConfirmScreen();
                }
                else
                {
                    showProcessInd();
                    VappBtSettingCell::onSwitchUpdateCell(VFX_TRUE);
                    srv_bt_cm_switch_off();
                    //setIsDisabled(VFX_TRUE);
                }
                break;
        }
    }
}


void VappBtPowerSwitchCell::showConfirmScreen(void)
{
	VfxResId strId, butStrId;
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERSWITCHCELL_SHOWCONFIRMSCREEN,
        m_confirmFlag);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    if (VAPP_BT_POWER_ON_CONFIRM == m_confirmFlag)
    {
		strId = STR_ID_VAPP_BT_IN_FLIGHT_MODE_ASK;
		butStrId = STR_ID_VAPP_BT_TURN_ON;

    }
	else
	{
		strId = STR_ID_VAPP_BT_TURN_OFF_WITH_CONNECTION_CONFIRM;
		butStrId = STR_ID_VAPP_BT_TURN_OFF;
    }
	m_confirmPopup->setText(VFX_WSTR_RES(strId));
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(
    VFX_WSTR_RES(butStrId),
    VFX_WSTR_RES(STR_GLOBAL_CANCEL),
    VCP_POPUP_BUTTON_TYPE_WARNING,
    VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappBtPowerSwitchCell::onButtonClick);
    m_confirmPopup->show(VFX_TRUE);
}


void VappBtPowerSwitchCell::onButtonClick(VfxObject* sender, VfxU32 id)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERSWITCHCELL_ONBUTTONCLICK,
        id);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        switch (m_confirmFlag)
        {
            case VAPP_BT_POWER_ON_CONFIRM:
                if (srv_bt_cm_switch_on() == SRV_BT_CM_RESULT_SUCCESS)
                {
                    showProcessInd();
                }
                break;

            case VAPP_BT_POWER_OFF_CONFIRM:
                if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
                {
                    showProcessInd();
                    VappBtSettingCell::onSwitchUpdateCell(VFX_TRUE);
                    srv_bt_cm_switch_off();
                }
                break;
        }
        m_confirmFlag = 0;
    }

    m_confirmPopup = NULL;
}
        
void VappBtPowerSwitchCell::btCmPanicHandle(void)
{
    m_cmSrvHd = srv_bt_cm_set_notify(
        &VappBtPowerSwitchCell::btPowerSwitchEventHandle,
        SRV_BT_CM_EVENT_ACTIVATE | SRV_BT_CM_EVENT_DEACTIVATE | SRV_BT_CM_EVENT_RELEASE_ALL_CONN,
        getObjHandle());
    setSwitchStatus(VFX_FALSE);
}

void VappBtPowerSwitchCell::btPowerSwitchEventHandle(U32 event, void* para)
{
	VappBtPowerSwitchCell* self = (VappBtPowerSwitchCell*) VfxObject::handleToObject(
		((srv_bt_cm_activate_struct*)para)->user_data);
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERSWITCHCELL_BTPOWERSWITCHEVENTHANDLE,
        event, self);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (self)
    {
        switch (event)
        {
            case SRV_BT_CM_EVENT_ACTIVATE:
            case SRV_BT_CM_EVENT_DEACTIVATE:
				srv_bt_cm_activate_struct* res = (srv_bt_cm_activate_struct*)para;
                self->setIsDisabled(VFX_FALSE);
				self->setSwitchStatus(res->result && (event ==SRV_BT_CM_EVENT_ACTIVATE));
                break;
        }
        VFX_OBJ_CLOSE(self->m_confirmPopup);
    }
}


// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
VFX_IMPLEMENT_CLASS("VAPPBtSettingCell", VappBtSettingCell, VcpFormItemLauncherCell);
VappBtSettingCell* VappBtSettingCell::m_btSettingSelf = NULL;
void VappBtSettingCell::onInit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGCELL_ONINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VcpFormItemLauncherCell::onInit();
    
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_BT_MAIN));
    setHintText(VFX_WSTR_RES(STR_ID_VAPP_BT_SETTING_HINT));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappBtSettingCell::onTap);
    setIsDisabled(
        (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON) ?
        VFX_FALSE :
        VFX_TRUE);
	VappBtCm::m_signalBtCm.connect(this, &VappBtSettingCell::onReceiveBtCmEvent);
                  
   m_cmSrvHd = srv_bt_cm_set_notify(
        &VappBtSettingCell::btSettingEventHandle,
        SRV_BT_CM_EVENT_ACTIVATE | SRV_BT_CM_EVENT_DEACTIVATE,
        this);
    VappBtSettingCell::m_btSettingSelf = this;
	
}


void VappBtSettingCell::onDeinit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGCELL_ONDEINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VcpFormItemLauncherCell::onDeinit();
    if (m_cmSrvHd > 0)
    {
        srv_bt_cm_reset_notify(m_cmSrvHd);
        m_cmSrvHd = -1;
    }
    VappBtSettingCell::m_btSettingSelf = NULL;
}

void VappBtSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGCELL_ONTAP);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (srv_mode_switch_is_switching())
    {
        return;
    }

    VfxMainScr* mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
    {
        if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
        {
            mmi_id tmp = VfxAppLauncher::createCui(
                VAPP_BT_MAIN,
                VFX_OBJ_CLASS_INFO(VappBtSettingApp),
                mainScr->getGroupId());
            VfxAppLauncher::runCui(tmp);
        }
    }
}

void VappBtSettingCell::btCmPanicHandle(void)
{
    m_cmSrvHd = srv_bt_cm_set_notify(
        &VappBtSettingCell::btSettingEventHandle,
        SRV_BT_CM_EVENT_ACTIVATE | SRV_BT_CM_EVENT_DEACTIVATE,
        this);
    setIsDisabled(VFX_TRUE);
}

void VappBtSettingCell::btSettingEventHandle(U32 event, void* para)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGCELL_BTSETTINGEVENTHANDLE,
        event,
        VappBtSettingCell::m_btSettingSelf);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (VappBtSettingCell::m_btSettingSelf)
    {
        VappBtSettingCell* cell = VappBtSettingCell::m_btSettingSelf;
        switch (event)
        {
            case SRV_BT_CM_EVENT_ACTIVATE:
            case SRV_BT_CM_EVENT_DEACTIVATE:
                cell->setIsDisabled(srv_bt_cm_get_power_status() != SRV_BT_CM_POWER_ON);
                break;
        }
    }
}


void VappBtSettingCell::onReceiveBtCmEvent(VfxS32 event, VfxS32 result)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSETTINGCELL_ONRECEIVEBTCMEVENT,
        event,
        result);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (event)
    {
        case VAPP_BT_EVENT_SWITCHH_FLIGHT_MODE:
            setIsDisabled(
                (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON) ?
                VFX_FALSE :
                VFX_TRUE);
            break;
    }
}

void VappBtSettingCell::onSwitchUpdateCell(VfxBool disableState)
{
    if (VappBtSettingCell::m_btSettingSelf)
    {
        VappBtSettingCell* cell = VappBtSettingCell::m_btSettingSelf;
        cell->setIsDisabled(disableState);
    }
}


struct BtStatusCntx {
    VfxU32 status;
    VfxU32 refCount;
};
enum BtState {
    BT_STATE_OFF,
    BT_STATE_ON,
    BT_STATE_CONN,
    BT_STATE_TRANS
};

static BtStatusCntx statusCntx;

void vapp_bt_update_status(BtStatusNotify status)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPP_BT_UPDATE_STATUS,
        status);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (status)
    {
        case BT_NOTIFY_ON:
            if (statusCntx.status == BT_STATE_OFF)
            {
                wgui_status_icon_bar_show_icon(STATUS_ICON_BT);
                statusCntx.status = BT_STATE_ON;
            }
            break;
        
        case BT_NOTIFY_OFF:
            statusCntx.refCount = 0;
            statusCntx.status = BT_STATE_OFF;
            wgui_status_icon_bar_reset_icon_animate(STATUS_ICON_BT);
            wgui_status_icon_bar_change_icon_image(STATUS_ICON_BT, IMG_SI_BT);
            wgui_status_icon_bar_hide_icon(STATUS_ICON_BT);
            break;
        
        case BT_NOTIFY_CONN_UP:
            if (statusCntx.status == BT_STATE_ON)
            {
                wgui_status_icon_bar_change_icon_image(STATUS_ICON_BT, IMG_SI_BT_CON);
                statusCntx.status = BT_STATE_CONN;
            }
            break;
        
        case BT_NOTIFY_CONN_DOWN:
            if (statusCntx.status == BT_STATE_CONN)
            {
                wgui_status_icon_bar_change_icon_image(STATUS_ICON_BT, IMG_SI_BT);
                statusCntx.status = BT_STATE_ON;
            }
            else if (statusCntx.status == BT_STATE_TRANS)
            {
                wgui_status_icon_bar_reset_icon_animate(STATUS_ICON_BT);
                wgui_status_icon_bar_change_icon_image(STATUS_ICON_BT, IMG_SI_BT);
                statusCntx.status = BT_STATE_ON;
                statusCntx.refCount = 0;
            }
            break;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__        
        case BT_NOTIFY_TRANS_BEGIN:
            if (statusCntx.status == BT_STATE_CONN)
            {
                wgui_status_icon_bar_change_icon_image(STATUS_ICON_BT, IMG_SI_BT_TRANSFERRING);
                wgui_status_icon_bar_animate_icon(STATUS_ICON_BT);
                statusCntx.status = BT_STATE_TRANS;
                statusCntx.refCount = 0;
            }

            if (statusCntx.status == BT_STATE_TRANS)
            {
                statusCntx.refCount++;
            }
            break;
        
        case BT_NOTIFY_TRANS_END:
            if (statusCntx.status == BT_STATE_TRANS)
            {
                statusCntx.refCount--;
                if (statusCntx.refCount == 0)
                {
                    wgui_status_icon_bar_reset_icon_animate(STATUS_ICON_BT);
                    wgui_status_icon_bar_change_icon_image(STATUS_ICON_BT, IMG_SI_BT_CON);
                    statusCntx.status = BT_STATE_CONN;
                }
            }
            break;
#endif //__MMI_COSMOS_STATUS_BAR_SLIM__
    }
}

#endif  // __MMI_BT_SUPPORT__
