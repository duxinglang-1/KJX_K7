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
 *  vapp_sync_remote_cui.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  CUI for sync
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_include.h"
#include "GlobalResDef.h"
#include "custom_mmi_default_value.h"
#include "common_nvram_editor_data_item.h"

#include "SyncSrvGprot.h"
#include "CcaSrvGprot.h"

#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_cca_def.h"
#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_sync_def.h"

#include "vfx_app.h"
#include "vfx_app_launcher.h"
#include "vfx_app_scr.h"

#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_confirm_popup.h"

#include "vapp_cca_gprot.h"

#include "vapp_sync.h"
#include "vapp_sync_remote_accnt_edit.h"
#include "vcui_sync_gprot.h"
#include "vcui_sync_remote_ota.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
mmi_id vcui_sync_remote_evt_hdlr(mmi_event_struct *evt)
{
	if (evt->evt_id != EVT_ID_SRV_SYNC_OTA_IND)
	{
		return MMI_RET_OK;
	}
	
    mmi_id parentId = vapp_cca_get_parent_id();

	if (parentId == GRP_ID_INVALID)
    {
    	// finish install at this stage.
    	return MMI_RET_OK;
	}

	mmi_id cuiId = vcui_sync_otap_create(parentId, NULL);
	vfxSetCuiCallerScr(cuiId, vapp_cca_get_parent_screen());

	if (cuiId != GRP_ID_INVALID)
	{
		srv_sync_ota_ind_evt_struct *ota_evt = (srv_sync_ota_ind_evt_struct *)evt;
		
		vcui_sync_otap_set_total(cuiId, ota_evt->total);
		
    	vcui_sync_otap_run(cuiId);
	}
	
	return MMI_RET_OK;
}

mmi_id vcui_sync_otap_create(mmi_id parent_id, void *usr_data)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
				        VCUI_SYNC_PROV,
				        VFX_OBJ_CLASS_INFO(VcuiSyncRemoteOta),
				        parent_id,
				        NULL,
				        0);	
    return cui_id;
}

void vcui_sync_otap_set_total(mmi_id cui_id, U16 total)
{
    VcuiSyncRemoteOta *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSyncRemoteOta);
    VFX_ASSERT(obj != NULL);
    
    obj->setTotal(total);
}

void vcui_sync_otap_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

void vcui_sync_otap_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}

/***************************************************************************** 
 * classs VcuiSyncRemoteOta
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcuiSyncRemoteOta", VcuiSyncRemoteOta, VfxCui);

void VcuiSyncRemoteOta::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);

	VcuiSyncRemoteOtaScr *scr;
	VFX_OBJ_CREATE_EX(scr, VcuiSyncRemoteOtaScr, this, (m_total));
	
	scr->show();
}

VfxAppCloseAnswerEnum VcuiSyncRemoteOta::onProcessClose(VfxAppCloseOption options)
{
	return VFX_APP_CLOSE_ANSWER_YES;
}

/***************************************************************************** 
 * Class VcuiSyncRemoteOtaScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcuiSyncRemoteOtaScr", VcuiSyncRemoteOtaScr, VfxMainScr);
void VcuiSyncRemoteOtaScr::on1stReady(void)
{
    VcuiSyncRemoteOtaInstallPage *page;
	
    VFX_OBJ_CREATE_EX(page, VcuiSyncRemoteOtaInstallPage, this, (m_total));
    pushPage(0, page);
}


/***************************************************************************** 
 * Class VcuiSyncRemoteOtaInstallPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcuiSyncRemoteOtaInstallPage", VcuiSyncRemoteOtaInstallPage, VfxPage);
VcuiSyncRemoteOtaInstallPage::VcuiSyncRemoteOtaInstallPage() 
	: m_text(NULL), 
	  m_total(0),
	  m_isSelfClose(VFX_FALSE)
{
}
VcuiSyncRemoteOtaInstallPage::VcuiSyncRemoteOtaInstallPage(const VfxU16 &total) : m_text(NULL), m_total(total)
{
}

void VcuiSyncRemoteOtaInstallPage::onInit()
{
    VfxPage::onInit();
	
    // title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);    
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_CCA_INSTALL_SETTING);
    titleBar->setTitle(str);
    setTopBar(titleBar);

    VcpToolBar *toolBar;
	
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->m_signalButtonTap.connect(this, &VcuiSyncRemoteOtaInstallPage::onToolBarClick);
    toolBar->addItem('INST', VFX_WSTR_RES(STR_GLOBAL_INSTALL), IMG_ID_VAPP_CCA_INSTALL);
    toolBar->addItem('SKIP', VFX_WSTR_RES(STR_ID_VAPP_CCA_SKIP), IMG_ID_VAPP_CCA_SKIP);
	
    setBottomBar(toolBar);

    VFX_OBJ_CREATE(m_text, VcpTextView, this);
	m_text->setSize(getSize());
    m_text->setMargins(TEXT_MARGIN, TEXT_MARGIN, TEXT_MARGIN, TEXT_MARGIN);
	
    m_text->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
	
    m_text->setLineMode(VCP_TEXT_LINE_MODE_MULTI);

	m_curr = 0;
	m_isSelfClose = VFX_FALSE;
 	fillTextInfo();
}

void VcuiSyncRemoteOtaInstallPage::onDeinit(void)
{
	// Close by HomeKey or by other app, such as CCA, UM
	if (!m_isSelfClose)
	{
		srv_sync_ota_install_new_accnt(0xFF, SRV_CCA_STATUS_ENDKEY_PRESSED);
		srv_sync_ota_finish();
	}
	
	VfxPage::onDeinit();
}

void VcuiSyncRemoteOtaInstallPage::onBackConfirm(VfxObject* obj, VfxId id)
{
   if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
    	m_isSelfClose = VFX_TRUE;
		
		srv_sync_ota_install_new_accnt(0xFF, SRV_CCA_STATUS_ENDKEY_PRESSED);
	srv_sync_ota_finish();
    }
}

void VcuiSyncRemoteOtaInstallPage::onBack(void)
{
	VcpConfirmPopup *confirmPopup;
	VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
	confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
	confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM));
	/*confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);*/
	confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
   /* confirmPopup->setCustomButton(
        VFX_WSTR_RES(STR_GLOBAL_YES),
        VFX_WSTR_RES(STR_GLOBAL_NO),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);*/
	
	confirmPopup->show(VFX_TRUE);
	confirmPopup->m_signalButtonClicked.connect(this, &VcuiSyncRemoteOtaInstallPage::onBackConfirm);
}

VfxScrRotateTypeEnum VcuiSyncRemoteOtaInstallPage::onQueryRotate(const VfxScreenRotateParam &param)
{
    return param.rotateTo;
}

void VcuiSyncRemoteOtaInstallPage::onToolBarClick(VfxObject *obj, VfxId id)
{
	switch(id)
	{
		case 'INST':
		{
			if (m_bUpdate)
			{
				install(m_dest, CCA_STATUS_SETTING_UPDATED);
			}
			else
			{
				VfxS8 slot = findEmptySlot();
				if (slot >= 0)
				{
					install(slot, SRV_CCA_STATUS_OK);	
				}
				else
				{
					VcuiSyncRemoteOtapAcctListPage *page;
					VFX_OBJ_CREATE(page, VcuiSyncRemoteOtapAcctListPage, this);

					page->m_signalSelect.connect(this, &VcuiSyncRemoteOtaInstallPage::onSelectCallback);
					page->m_signalQuitAsk.connect(this, &VcuiSyncRemoteOtaInstallPage::onQuitAskCallback);
					
					getMainScr()->pushPage(VFX_ID_NULL, page);
				}
			}			
			
			break;
		}
		
		case 'SKIP':
		{
			install(0xFF, SRV_CCA_STATUS_SETTING_SKIPPED);
			break;
		}

		default:
			break;
	}
}

void VcuiSyncRemoteOtaInstallPage::onQuitAskCallback(void)
{
	onBack();
}

void VcuiSyncRemoteOtaInstallPage::onSelectCallback(VfxU8 index)
{
	getMainScr()->popPage();
	
	install(index, SRV_CCA_STATUS_OK);
}

VfxS8 VcuiSyncRemoteOtaInstallPage::findEmptySlot(void)
{
	for (VfxU32 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		if (srv_sync_ota_is_empty_accnt(i))
		{
			return i;
		}
	}

	return -1;
}

void VcuiSyncRemoteOtaInstallPage::closeActiveAccnt(VfxU32 index)
{
	if (index < MAX_SYNCML_SV_PROFILES)
	{
		// Close the current edit account
		VfxApp *app = VfxAppLauncher::findApp(VAPP_SYNC, VFX_OBJ_CLASS_INFO(VappSyncApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
		if (app != NULL)
		{
			VappSyncApp *syncApp = (VappSyncApp *)app;
			VappSyncMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(syncApp->getCurrScr(), VappSyncMainScr);
			if (mainScr != NULL)
			{
				VappSyncRemoteAccntEditPage *page ;
				page = (VappSyncRemoteAccntEditPage *)mainScr->getPage(VAPP_SYNC_PAGE_ID(ACCNT_EDIT));
		
				if ((page != NULL) && (index == page->getCurrAccntID()))
				{
					page->closeRelativePage();
				}
			}		
		}
	}
}

void VcuiSyncRemoteOtaInstallPage::install(VfxU8 index, U16 status)
{
	closeActiveAccnt(index);
	
	srv_sync_ota_install_new_accnt(index, status);

	VfxS32 next = srv_sync_ota_next_accnt();
	
	if (next >= 0)
	{
		m_curr++;
		fillTextInfo();
	}
	else
	{
		m_isSelfClose = VFX_TRUE;
		srv_sync_ota_finish();

		vcui_sync_otap_close(getMainScr()->getGroupId());
	}
}

void VcuiSyncRemoteOtaInstallPage::fillTextInfo(void)
{
	VfxChar *info;
	VfxChar *tmp;
	VfxS8 tmpnum[4 * ENCODING_LENGTH];
	
	VFX_ALLOC_MEM(info, 2048, this);
	VFX_ALLOC_MEM(tmp, (MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH), this);
    
	/*--------------------------
	 *		Install Setting    |	 
	 *--------------------------
	 * Synchronization
	 * Account: 1/3
	 *	Update existing profile
	 *	
	 * Account name:Account 1
	 *
	 * Server address:http://www.mobical.net/...
	 *
	 * Database address:contact
	 *
	 * Database address:calendar
	 *
	 *--------------------------
	 * Install |		| Skip |
	 *--------------------------
	 */
	 
	/* APP NAME */
	mmi_ucs2cpy(info, GetString(STR_ID_VAPP_CCA_SYNCMLDS));
	mmi_ucs2cat(info, (CHAR *)L"\n");
	
	/* Current profile num */
	mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_ACCNTS));
	mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_COLON)); 
	mmi_ucs2cat(info, (CHAR *)L" ");	 
	sprintf((CHAR *)&tmpnum,"%d", (m_curr + 1));
	memset(tmp, 0, (MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH));
	mmi_asc_n_to_ucs2(
				(CHAR *) tmp,
				(CHAR *) tmpnum,
				strlen((CHAR *)&tmpnum));
	mmi_ucs2cat(info, (CHAR *)tmp);
	mmi_ucs2cat(info, (CHAR *)L"/");
	sprintf((CHAR *)&tmpnum, "%d", m_total);

	memset(tmp, 0, (MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH));
	mmi_asc_n_to_ucs2(
				(CHAR *) tmp,
				(CHAR *) tmpnum,
				strlen((CHAR *)&tmpnum));
	mmi_ucs2cat(info, (CHAR *)tmp); 

	srv_sync_ota_accnt_info_struct ota_info;
	VFX_ASSERT(srv_sync_ota_get_info(&ota_info, m_curr));

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__  
	if (ota_info.updateble)
	{
		/* Show Update infomation */
		mmi_ucs2cat(info, (CHAR *)L"\n");
		mmi_ucs2cat(info, GetString(STR_ID_VAPP_CCA_UPDATE_PROFILE));
		m_dest = ota_info.dest_idx;
		m_bUpdate = VFX_TRUE;
	}
	else
	{
		m_bUpdate = VFX_FALSE;
	}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

	nvram_ef_syncml_account_struct *prof = (nvram_ef_syncml_account_struct *)ota_info.accnt;;

	mmi_ucs2cat(info, (CHAR *)L"\n\n"); 
	mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_ACCNT_NAME));
	mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_COLON));
	mmi_ucs2cat(info, (CHAR *)L" "); 
	mmi_ucs2cat(info, (CHAR *)prof->account_name);
	
	/* Server address */
	mmi_ucs2cat(info, (CHAR *)L"\n\n");
	mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_SERVER_ADDR));
	memset(tmp, 0, (MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH));
	mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_COLON));
	mmi_ucs2cat(info, (CHAR *)L" "); 
	mmi_asc_n_to_ucs2(
			(CHAR *) tmp,
			(CHAR *) prof->server_address,
			strlen((CHAR *)prof->server_address));
	mmi_ucs2cat(info, (CHAR *)tmp); 

	for (VfxU32 i = 0; i < VAPP_SYNC_TOTAL_DATABASE; i++)
	{
		if (prof->app_to_sync & VAPP_SYNC_GET_DB_MASK(i))
		{
			memset(tmp, 0, MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);
			mmi_asc_n_to_ucs2(
					(CHAR *)tmp,
					(CHAR *)prof->database_address[VAPP_SYNC_GET_ID(i)],
					strlen((CHAR *)prof->database_address[VAPP_SYNC_GET_ID(i)]));
			
			mmi_ucs2cat(info, (CHAR *)L"\n\n");
			mmi_ucs2cat(info, GetString(VAPP_SYNC_GET_DB_RESID(i)));
			mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_SPACE));
			mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_DB_ADDR));
			mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_COLON));
			mmi_ucs2cat(info, GetString(STR_ID_VAPP_SYNC_SPACE));
			mmi_ucs2cat(info, (CHAR *)tmp);
		}
	}
   
	m_text->setText((const VfxWChar*)info);
	
	VFX_FREE_MEM(tmp);
	VFX_FREE_MEM(info);
}

/***************************************************************************** 
 * Class VcuiSyncRemoteOtapAcctListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcuiSyncRemoteOtapAcctListPage", VcuiSyncRemoteOtapAcctListPage, VfxPage);
VcuiSyncRemoteOtapAcctListPage::VcuiSyncRemoteOtapAcctListPage()
	: m_menu(NULL),
	  m_selectedIndex(0),
	  m_total(0)
{
}

void VcuiSyncRemoteOtapAcctListPage::onInit()
{
    VfxPage::onInit();

    // title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);    
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CCA_REPLACE_SETTING));
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);

    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_TRUE);
    m_menu->m_signalItemSelectionStateChanged.connect(this, &VcuiSyncRemoteOtapAcctListPage::onItemStateChanged);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->m_signalButtonTap.connect(this, &VcuiSyncRemoteOtapAcctListPage::onToolBarClick);
    toolBar->addItem('RPLC', VFX_WSTR_RES(STR_GLOBAL_REPLACE), IMG_ID_VAPP_CCA_REPLACE);
    toolBar->addItem('CNCL', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	
    setBottomBar(toolBar);

	getTotalAccnt();
}

void VcuiSyncRemoteOtapAcctListPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    
    switch(id)
    {
        case 'RPLC':
        {
			if (srv_sync_is_synchronizing())
			{
				srv_sync_enum sync;
				VfxU8 index;
				
				if (srv_sync_active_sync_info(&sync, &index) &&
					(sync == SRV_SYNC_REMOTE) &&
					(index == m_arrIdx[m_selectedIndex]))
				{
					mmi_frm_nmgr_balloon(
						MMI_SCENARIO_ID_GENERAL,
						MMI_EVENT_INFO_BALLOON,
						MMI_NMGR_BALLOON_TYPE_INFO,
						(WCHAR *)GetString(STR_GLOBAL_BUSY_TRY_LATER));

				    break;
			    }
			
			}
			
 			m_signalSelect.postEmit(m_arrIdx[m_selectedIndex]);
            break;
        }
        case 'CNCL':
        {
			getMainScr()->popPage();
            break;
        }
    }
}

void VcuiSyncRemoteOtapAcctListPage::onEnter(VfxBool isBackward)
{
	getTotalAccnt();

	if (m_total != 0)
	{
    m_menu->updateAllItems();
}
	else
	{
		exit();
	}
}

void VcuiSyncRemoteOtapAcctListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    
}

void VcuiSyncRemoteOtapAcctListPage::onBack(void)
{
	m_signalQuitAsk.postEmit();
}


VfxBool VcuiSyncRemoteOtapAcctListPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
		nvram_ef_syncml_account_struct *accnt;
	
		VFX_ALLOC_MEM(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, this);
	
		srv_sync_read_accnt_buffer(
				accnt,
				NVRAM_EF_SYNCML_ACCOUNT_SIZE,
				SRV_SYNC_REMOTE,
				m_arrIdx[index]);
		
		text = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name);
		
		VFX_FREE_MEM(accnt);
	}

	return VFX_TRUE;
}

VfxU32 VcuiSyncRemoteOtapAcctListPage::getTotalAccnt(void)
{
	m_total = 0;
	
	nvram_ef_syncml_account_struct *accnt;

	VFX_ALLOC_MEM(accnt, sizeof(nvram_ef_syncml_account_struct), this);
	
	for (VfxU32 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		if (!srv_sync_read_accnt_buffer(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, i) ||
			accnt->timestamp == 0)
		{
			continue;
		}
	
		if (srv_sync_is_synchronizing())
		{
			srv_sync_enum sync;
			VfxU8 index;
			
			if (srv_sync_active_sync_info(&sync, &index) && 
				(sync == SRV_SYNC_REMOTE) && 
				(index == i))
			{
				continue;
			}
			
			m_arrIdx[m_total] = i;
			m_total++;
		}
		else
		{
			m_arrIdx[m_total] = i;
			m_total++;
		}
	}
	
	VFX_FREE_MEM(accnt);
	
	return (m_total + 1);
}

VcpListMenuItemStateEnum VcuiSyncRemoteOtapAcctListPage::getItemState(VfxU32 index) const
{
	if (index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
	else
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}

void VcuiSyncRemoteOtapAcctListPage::onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_selectedIndex = index;
    }
}

