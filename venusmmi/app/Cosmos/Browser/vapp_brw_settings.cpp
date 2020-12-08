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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BrowserUIPlugIn.c
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _VAPP_BRW_SETTINGS_CPP_
#define _VAPP_BRW_SETTINGS_CPP_

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __MMI_BROWSER_2__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "mmi_rp_vapp_browser_def.h"
#ifdef __cplusplus
extern "C"
{
#endif 
#include "BrowserSrvInterface.h"
#include "BrowserSrvProts.h"
#include "SimCtrlSrvGprot.h"

/*#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif*/

extern int bam_registry_check_cache_status(void);
extern int bam_registry_check_cookie_status(void);
extern int bam_registry_check_auth_status(void);
#ifdef __cplusplus
}
#endif

#include "vapp_brw_interface.h"
#include "vapp_brw_main.h"
#include "vapp_brw_settings.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define BRW_MENU_ITEM_TRUNC_STR
#define VAPP_BRW_MAX_CERT_DISP_BUFF 1024

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
//#pragma arm section code = "DYNAMIC_CODE_BROWSER_ROCODE", rodata = "DYNAMIC_CODE_BROWSER_RODATA"

VfxSignal3<S32, U32, void *> VfxAppBrowserSettingsInterface::m_dispatchCallback;

/***************************************************************************** 
 * Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappStaticListPage", VappStaticListPage, VfxPage);

/***************************************************************************** 
 * class VappStaticListPage
 *****************************************************************************/

//Init method. Called when object is created for the class
void VappStaticListPage::onInit()
{
	VcpTitleBar *titleBar;
	
	VfxPage::onInit(); // call base class
	
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	
	VappStaticListPage::m_updateStaticListTitle(titleBar); //update title bar
	VappStaticListPage::m_updateStaticListToolBar(); // update bottom bar
	setTopBar(titleBar); 
	m_list->setPos(0,0);
	m_updateStaticListSize();                 
	m_updateStaticListStyle(); //update page style as per the page tye
	m_updateContentProvider(); //associate a content provider
	UpdateStaticListSelectedItems();
	
	//Event handler functions
    m_list->m_signalItemTapped.connect(this, &VappStaticListPage::m_signalListItemTapped);
	m_list->m_signalItemSelectionStateChanged.connect(this, &VappStaticListPage::m_signalListItemSelected);
	m_list->m_signalFocusChanged.connect(this, &VappStaticListPage::m_signalListFocusChanged);

}

//Return : Rotate type supported by the page, currently Landscape and Portrait


void VappStaticListPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
	{
				
	}
	else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	}

}

//Get index of selected item on the page
void VappStaticListPage::UpdateStaticListSelectedItems()
{
	if(m_list_type == BRW_STATIC_LIST_TYPE_TIMEOUT)
	{
		// update m_id acc. to timeout value from service
	}
#ifndef __GOOGLE_SEARCH_SUPPORT__
	else if(m_list_type == BRW_STATIC_LIST_TYPE_SEARCH_ENGINE)
	{
		if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_BAIDU)
			m_id = 0;
		else if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_GOOGLE)
			m_id = 1;
		else if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_YAHOO)
			m_id = 2;
		else if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_BING)
			m_id = 3;
	}
#endif
	else if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
	{
		set_private_mode_setting((U8) g_srv_brw_cntx.private_mode_setting);
		if(g_srv_brw_cntx.history_setting)
			m_sel_ids[0] = VFX_TRUE;
		else
			m_sel_ids[0] = VFX_FALSE;
		if(g_srv_brw_cntx.cache_status)
			m_sel_ids[1] = VFX_TRUE;
		else
			m_sel_ids[1] = VFX_FALSE;
		if(g_srv_brw_cntx.cookie_status)
			m_sel_ids[2] = VFX_TRUE;
		else
			m_sel_ids[2] = VFX_FALSE;
	}
}

//Set page size as per page type
void VappStaticListPage::m_updateStaticListSize(void)
{
	VfxRect page_rect = getRect();
	if(m_list_type == BRW_STATIC_LIST_TYPE_TIMEOUT)
		m_list->setRect(0, 0, page_rect.size.width, page_rect.size.height );
#ifndef __GOOGLE_SEARCH_SUPPORT__
	else if(m_list_type == BRW_STATIC_LIST_TYPE_SEARCH_ENGINE)
		m_list->setRect(0, 0, page_rect.size.width, page_rect.size.height );
#endif	
	
	else if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
		m_list->setRect(0, 0, page_rect.size.width, page_rect.size.height );
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	else if(m_list_type == BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES)
		m_list->setRect(0, 0, page_rect.size.width, page_rect.size.height );
#endif
	m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
}

//Set page style as per page type
void VappStaticListPage::m_updateStaticListStyle(void)
{
	if(m_list_type == BRW_STATIC_LIST_TYPE_TIMEOUT)
	{
		m_list->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE); 
		m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	}
#ifndef __GOOGLE_SEARCH_SUPPORT__
	else if(m_list_type == BRW_STATIC_LIST_TYPE_SEARCH_ENGINE)
	{
		m_list->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE); 
		m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	}
#endif
	else if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
	{
		m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_FALSE); 
		m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	}
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	else if(m_list_type == BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES)
	{		
		m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	}
#endif
}

//Associate content provider
void VappStaticListPage::m_updateContentProvider(void)
{
	if(m_list_type == BRW_STATIC_LIST_TYPE_TIMEOUT)
	{
		VappTimeOutListcontentprovider *content_provider;
		VFX_OBJ_CREATE(content_provider, VappTimeOutListcontentprovider, this);
		m_list->setContentProvider(content_provider);
	}
#ifndef __GOOGLE_SEARCH_SUPPORT__
	else if(m_list_type == BRW_STATIC_LIST_TYPE_SEARCH_ENGINE)
	{
		VappSearchEnginecontentprovider *content_provider;
		VFX_OBJ_CREATE(content_provider, VappSearchEnginecontentprovider, this);
		m_list->setContentProvider(content_provider);		
	}
#endif
	else if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
	{
		VappPrivateModecontentprovider *content_provider;
		VFX_OBJ_CREATE(content_provider, VappPrivateModecontentprovider, this);
		m_list->setContentProvider(content_provider);
	}
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	else if(m_list_type == BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES)
	{
		VappTrustedCertificatescontentprovider *content_provider;
		VFX_OBJ_CREATE(content_provider, VappTrustedCertificatescontentprovider, this);
		m_list->setContentProvider(content_provider);
	}
#endif
}

void VappStaticListPage::m_updateStaticListToolBar(void)
{
	if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
	{
		VcpToolBar *toolbar;
		VFX_OBJ_CREATE(toolbar, VcpToolBar,this);
		toolbar->m_signalButtonTap.connect(this, &VappStaticListPage::onStaticListToolBarClick);
		setBottomBar(toolbar);
		toolbar->addItem(0, VFX_WSTR_RES(STR_GLOBAL_SAVE),VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
		toolbar->addItem(1, VFX_WSTR_RES(STR_GLOBAL_CANCEL),VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	}
}

void VappStaticListPage::m_updateStaticListTitle(VcpTitleBar *titleBar)
{
	if(m_list_type == BRW_STATIC_LIST_TYPE_TIMEOUT)
		titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_TIMEOUT));
#ifndef __GOOGLE_SEARCH_SUPPORT__
	else if(m_list_type == BRW_STATIC_LIST_TYPE_SEARCH_ENGINE)
		titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_SEARCH_ENGINE));
#endif
	else if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
		titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_PRIVATE_MODE));
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	else if(m_list_type == BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES)
		titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_TRUSTED_CERTIFICATES));
#endif
}

void VappStaticListPage::set_private_mode_setting(U8 setting_id)
{
	m_private_mode_setting = setting_id;
}

U8 VappStaticListPage::get_private_mode_setting(void)
{
	return m_private_mode_setting;
}
void VappStaticListPage::onDeinit()
{
    VFX_OBJ_CLOSE(m_list);
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
    if(m_list_type == BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES)
    {
        if(g_srv_brw_cntx.brw_instance_id > 0)
        {
            srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
        }
    }
#endif
    VfxPage::onDeinit(); 
}

void VappStaticListPage::onEnter(VfxBool isBackward)
{
#if (defined  (WAP_SEC_SUPPORT)	 && !defined (__LOW_COST_SUPPORT_COMMON__))
    if((m_list_type == BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES) && isBackward)
    {       
		m_list->updateAllItems();
    }
#endif
}

void VappStaticListPage::switchCallback(VcpSwitch *abc, VfxBool status)
{
	if(status == VFX_TRUE)
		m_private_mode_setting = 1;
	else if(status == VFX_FALSE)
		m_private_mode_setting = 0;
	m_list->updateAllItems();
}

void VappStaticListPage::onStaticListToolBarClick(VfxObject* sender, VfxId id)
{
	if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
	{
		switch(id)
		{
			case BRW_LIST_TOOLBAR_BUTTON_SAVE:
				{
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
/* under construction !*/
#endif //0
					{
					#ifndef __MMI_BRW_SLIM__
						if(m_sel_ids[0] == VFX_TRUE)
						{
							g_srv_brw_cntx.history_setting = VFX_TRUE;
						}
						else
						{
							g_srv_brw_cntx.history_setting = VFX_FALSE;
						}
					#else
						// dont save history data 
						g_srv_brw_cntx.history_setting = VFX_FALSE;
					#endif
						srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_HISTORY);// send request to clear history
					
					#ifndef SLIM_WAP_MMS	
						if(m_sel_ids[1] == VFX_TRUE)
						{
							g_srv_brw_cntx.cache_status = VFX_TRUE;						
						}
						else
						{
							g_srv_brw_cntx.cache_status = VFX_FALSE;
						}
					#else
						g_srv_brw_cntx.cache_status = VFX_FALSE;
					#endif
						srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_CACHE);	
					
						if(m_sel_ids[2] == VFX_TRUE)
						{
							g_srv_brw_cntx.cookie_status = VFX_TRUE;						
						}
						else
							g_srv_brw_cntx.cookie_status = VFX_FALSE;
						srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_COOKIE);
					}
					g_srv_brw_cntx.private_mode_setting = m_private_mode_setting;
					srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_PRIVATE_MODE);
					
					srv_wap_prof_profile_content_struct *profile_content_p;
					srv_brw_act_req_struct obj = {0};
					srv_brw_set_profile_req_struct prof;
					srv_brw_get_profile_content((void **)&profile_content_p);
					prof.currprof = profile_content_p;
					prof.setting_id = wap_bam_setting_type_settings;
					VfxAppBrowserSettingsInterface::m_dispatchCallback.connect(this , &VappStaticListPage::PrivateModeRspcallback);
					obj.rsp_callback = VfxAppBrowserSettingsInterface::OnServiceRspCallback;
					obj.req_data = (void*)&prof;
					srv_brw_set_profile_req_by_data(&obj);
                    OslMfree(profile_content_p);
				}
			   break;
			case BRW_LIST_TOOLBAR_BUTTON_CANCEL:
				m_private_mode_setting = g_srv_brw_cntx.private_mode_setting;
				getMainScr()->popPage();	
				break;
		   default:
				break;
		}
	}
}

void VappStaticListPage::m_signalListItemTapped(VcpListMenu *listmenu, VfxU32 id)
{
	m_id = id;
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	if(m_list_type == BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES)
	{
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		VFX_OBJ_CREATE_EX(m_brwApp->scr->m_TrustedCertViewerPage, VappBrwTrustedCertViewerPage, m_brwApp->scr, (m_id));
		m_brwApp->scr->pushPage(7, m_brwApp->scr->m_TrustedCertViewerPage);
	}
#endif
	if(m_list_type == BRW_STATIC_LIST_TYPE_SEARCH_ENGINE || m_list_type == BRW_STATIC_LIST_TYPE_TIMEOUT)
		getMainScr()->popPage();
}
void VappStaticListPage::m_signalListItemSelected(VcpListMenu *listmenu, VfxU32 id, VcpListMenuItemStateEnum state)
{
	if(m_list_type == BRW_STATIC_LIST_TYPE_PRIVATE_MODE)
	{
		VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		if(m_brwApp->scr->m_StaticListPage->m_private_mode_setting == 0) // when the private mode is off
		{
			VfxU32 UOffset = 0;
			#ifdef __MMI_BRW_SLIM__ // no history
				UOffset++;
				#ifdef SLIM_WAP_MMS	// no cache
					UOffset++;
				#endif
			#else // exist history
				#ifdef SLIM_WAP_MMS // no cache
					if(id == 2)
						UOffset++;
				#endif
			#endif
			
			id+=UOffset;	
			MMI_ASSERT(id<=3);
			if(id == 1) // for history item
			{
				if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
					m_sel_ids[0] = VFX_TRUE;
				else
					m_sel_ids[0] = VFX_FALSE;
			}
			else if(id == 2) // for cache item
			{
				if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
					m_sel_ids[1] = VFX_TRUE;
				else
					m_sel_ids[1] = VFX_FALSE;
			}
			else if(id == 3) // for cookie item
			{
				if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
					m_sel_ids[2] = VFX_TRUE;
				else
					m_sel_ids[2] = VFX_FALSE;
			}
		}
	}
#ifndef __GOOGLE_SEARCH_SUPPORT__
	else if(m_list_type == BRW_STATIC_LIST_TYPE_SEARCH_ENGINE)
	{
		if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
		{
			g_srv_brw_cntx.sel_search_engine = (srv_brw_search_engines_enum)id;
			srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_SEARCH_ENGINE);
			VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
			m_brwApp->scr->m_settings->UpdateHintText((m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_SEARCH_ENGINE]), BRW_SETTINGS_DATA_ITEM_SEARCH_ENGINE);
			//getMainScr()->popPage();
		}
	}
#endif
	else if(m_list_type == BRW_STATIC_LIST_TYPE_TIMEOUT)
	{
		if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
		{
			if(id == VAPP_BRW_TIMEOUT_VALUE_30_SEC)
				g_srv_brw_cntx.timeout_value = 30;
			else if(id == VAPP_BRW_TIMEOUT_VALUE_60_SEC)
				g_srv_brw_cntx.timeout_value = 60;
			else if(id == VAPP_BRW_TIMEOUT_VALUE_120_SEC)
				g_srv_brw_cntx.timeout_value = 120;
			else if(id == VAPP_BRW_TIMEOUT_VALUE_180_SEC)
				g_srv_brw_cntx.timeout_value = 180;
			else if(id == VAPP_BRW_TIMEOUT_VALUE_240_SEC)
				g_srv_brw_cntx.timeout_value = 240;
			else if(id == VAPP_BRW_TIMEOUT_VALUE_300_SEC)
				g_srv_brw_cntx.timeout_value = 300;
			srv_brw_update_settings_data(SRV_BRW_NVRAM_TIMEOUT_VALUE);
			VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
			m_brwApp->scr->m_settings->UpdateHintText((m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_TIME_OUT]), BRW_SETTINGS_DATA_ITEM_TIME_OUT);
			//getMainScr()->popPage();
		}
	}
}

/***************************************************************************** 
 * class VappTimeOutListcontentprovider
 *****************************************************************************/
VfxBool VappTimeOutListcontentprovider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        ) 
{
	if(index == 0)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_30_SEC);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}
	else if(index == 1)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{				
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_60_SEC);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}

	else if(index == 2)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{				 
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_2_MINS);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}


	else if(index == 3)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{				
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_3_MINS);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}

	else if(index == 4)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{				 
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_4_MINS);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}
	else if(index == 5)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_5_MINS);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}
	return VFX_TRUE;
}

VcpListMenuItemStateEnum VappTimeOutListcontentprovider::getItemState(VfxU32 index) const
{
	U16 sel_index =0;
	if(g_srv_brw_cntx.timeout_value == 30)
		sel_index = VAPP_BRW_TIMEOUT_VALUE_30_SEC;
	else if(g_srv_brw_cntx.timeout_value == 60)
		sel_index = VAPP_BRW_TIMEOUT_VALUE_60_SEC;
	else if(g_srv_brw_cntx.timeout_value == 120)
		sel_index = VAPP_BRW_TIMEOUT_VALUE_120_SEC;
	else if(g_srv_brw_cntx.timeout_value == 180)
		sel_index = VAPP_BRW_TIMEOUT_VALUE_180_SEC;
	else if(g_srv_brw_cntx.timeout_value == 240)
		sel_index = VAPP_BRW_TIMEOUT_VALUE_240_SEC;
	else if(g_srv_brw_cntx.timeout_value == 300)
		sel_index = VAPP_BRW_TIMEOUT_VALUE_300_SEC;
	if(sel_index == (U16)index) 
	{
		/* the follow code fixs MAUI_03102806 */
		VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		m_brwApp->scr->m_StaticListPage->m_list->setVisibleMenuRegion(-1, index, VFX_FALSE);
		/* end */
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
	else
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


//VFX_IMPLEMENT_CLASS("VappSettingsPage", VappSettingsPage, VfxPage);


VfxBool VappTimeOutListcontentprovider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
{
		return VFX_FALSE;
}

/***************************************************************************** 
 * class VappSearchEnginecontentprovider
 *****************************************************************************/

VfxBool VappSearchEnginecontentprovider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        ) 
{

	if(index == 0)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{					
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_BAIDU);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}
	else if(index == 1)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{					
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_GOOGLE);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}
	return VFX_TRUE;
}


VfxBool VappSearchEnginecontentprovider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
{
	return VFX_FALSE;
}

void VappSearchEnginecontentprovider::m_signalListSearchItemTapped(VcpListMenu *listmenu, VfxU32 id)
{
}

/***************************************************************************** 
 * class VappPrivateModecontentprovider
 *****************************************************************************/

VfxBool VappPrivateModecontentprovider::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        ) 
{

	VfxU32 UOffset = 0;
	#ifdef __MMI_BRW_SLIM__ // no history
		UOffset++;
		#ifdef SLIM_WAP_MMS	// no cache
			UOffset++;
		#endif
	#else // exist history
		#ifdef SLIM_WAP_MMS // no cache
			if(index == 2)
				UOffset++;
		#endif
	#endif
	
	index+=UOffset;	
	MMI_ASSERT(index<=3);

	if(index == 1)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{			
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_ENABLE_HISTORY);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}
	else if(index == 2)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{			
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_ENABLE_CACHE);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}

	else if(index == 3)
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{	
			text = VFX_WSTR_RES(STR_ID_VAPP_BRW_ENABLE_COOKIES);
			//color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		}
	}

	return VFX_TRUE;
}

VfxBool VappPrivateModecontentprovider::getItemIsHighlightable(VfxU32 index)const
{
	if(index == 0)
		return VFX_FALSE;
	else
		return VFX_TRUE;
}

VcpListMenuItemStateEnum VappPrivateModecontentprovider:: getItemState(
        VfxU32 index   // [IN] index of the item
		) const
{
	if(index == 0)
		return VCP_LIST_MENU_ITEM_STATE_NONE;
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

	VfxU32 UOffset = 0;
	#ifdef __MMI_BRW_SLIM__ // no history
		UOffset++;
		#ifdef SLIM_WAP_MMS	// no cache
			UOffset++;
		#endif
	#else // exist history
		#ifdef SLIM_WAP_MMS // no cache
			if(index == 2)
				UOffset++;
		#endif
	#endif
	
	index+=UOffset;	
	MMI_ASSERT(index<=3);

		if(index == 1)
		{
		if(m_brwApp->scr->m_StaticListPage->m_sel_ids[0] == TRUE) // m_sel_ids[0]--history
				return VCP_LIST_MENU_ITEM_STATE_SELECTED;
			else
				return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
		}
		else if(index == 2)
		{
		if(m_brwApp->scr->m_StaticListPage->m_sel_ids[1] == TRUE) // m_sel_ids[1]--cache
				return VCP_LIST_MENU_ITEM_STATE_SELECTED;
			else
				return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
		}
		else if(index == 3)
		{
		if(m_brwApp->scr->m_StaticListPage->m_sel_ids[2] == TRUE) // m_sel_ids[2]--cookies
				return VCP_LIST_MENU_ITEM_STATE_SELECTED;
			else
				return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
		}
	
	return VCP_LIST_MENU_ITEM_STATE_NONE;
}

VfxBool VappPrivateModecontentprovider::getItemIsDisabled(
	VfxU32 index       // [IN] the index of item
	) const
{
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	if(index == 0)
		return VFX_FALSE;
	if(m_brwApp->scr->m_StaticListPage->m_private_mode_setting == 0)
	{
		if(index == 1 || index == 2 || index == 3)
		{
			return VFX_FALSE;
	}
	}
	else if(index == 1 || index == 2 || index == 3)
	{
			return VFX_TRUE;
}
	return VFX_FALSE;
}

VfxBool VappPrivateModecontentprovider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
{
		return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappPrivateModecontentprovider::getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        )
{
	if(index == 0)
	{
		VappBrwPrivateModeCustomFrame *m_private_mode_custom;
		VfxTextFrame *m_text;
		VFX_OBJ_CREATE(m_private_mode_custom, VappBrwPrivateModeCustomFrame, parentFrame);
		VFX_OBJ_CREATE(m_text, VfxTextFrame, m_private_mode_custom);
#if (defined(__MMI_MAINLCD_240X400__)) || (defined(__MMI_MAINLCD_240X320__))
        m_private_mode_custom->setBounds(VfxRect(0,0, LCD_WIDTH, 45));
#else
        m_private_mode_custom->setBounds(VfxRect(0,0, LCD_WIDTH, 51));
#endif 
		VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_BRW_PRIVATE_MODE));
		m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
		//m_text->setBounds(50, 100, 170, 165);
		m_text->setPos(parentFrame->getRect().getX() + 5, parentFrame->getRect().getY() + 13);
#if (defined(__MMI_MAINLCD_240X400__)) || (defined(__MMI_MAINLCD_240X320__))
		m_text->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
#endif 
		m_text->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
		VFX_OBJ_CREATE(m_brwApp->scr->m_StaticListPage->m_switch, VcpSwitch, m_private_mode_custom);
		m_brwApp->scr->m_StaticListPage->m_switch->setAnchor(1.0F, 0.5F);
#if (defined(__MMI_MAINLCD_240X400__)) || (defined(__MMI_MAINLCD_240X320__))
		//m_brwApp->scr->m_StaticListPage->m_switch->setPos(LCD_WIDTH - 49, 24);
        m_brwApp->scr->m_StaticListPage->m_switch->setPos(m_private_mode_custom->getRect().getWidth() - 5, (m_private_mode_custom->getRect().getHeight()) / 2);
#else
		m_brwApp->scr->m_StaticListPage->m_switch->setPos(m_private_mode_custom->getRect().getWidth() - 8, (m_private_mode_custom->getRect().getHeight()) / 2);
#endif 
		//m_switch->setPos(m_private_mode_custom->getRect().getWidth() - 10, (parentFrame->getRect().getHeight()) / 2);
		
		if(m_brwApp->scr->m_StaticListPage->m_private_mode_setting == TRUE) 
			m_brwApp->scr->m_StaticListPage->m_switch->setChecked(VFX_TRUE);
		else
			m_brwApp->scr->m_StaticListPage->m_switch->setChecked(VFX_FALSE);		
		m_brwApp->scr->m_StaticListPage->m_switch->m_signalSwitchChanged.connect(m_brwApp->scr->m_StaticListPage, &VappStaticListPage::switchCallback);
        m_brwApp->scr->m_StaticListPage->m_switch->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
		m_private_mode_custom->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
		return m_private_mode_custom;
	}
	return NULL;
}

void VappPrivateModecontentprovider::closeItemCustomContentFrame(VfxU32 index,  VcpListMenuCellClientBaseFrame *cell)
{
    if (cell) 
    {
        VFX_OBJ_CLOSE(cell);
    }
}

/***************************************************************************** 
 * class VappSettingsPage
 *****************************************************************************/
void VappSettingsPage::onInit()
{
        VfxPage::onInit();
		
        VcpTitleBar *bar;
        VFX_OBJ_CREATE(bar, VcpTitleBar, this);
        bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_SETTINGS));
        setTopBar(bar);

        VFX_OBJ_CREATE(m_form, VcpForm, this);

		VfxRect page_rect = getRect();
		
		m_form->setPos(0,0);
		m_form->setBounds(VfxRect(0,0,page_rect.size.width, page_rect.size.height));
		m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
		

		VFX_OBJ_CREATE(m_setting_header[0], VcpFormItemCaption, m_form);
    	m_setting_header[0]->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PREFERENCES));
        m_form->addItem(m_setting_header[0], BRW_SETTINGS_HEADER_ITEM_PREFERENCES); //, VCPFRM_ITEMTYPE_LAUNCHER_CELL);

#ifndef __GOOGLE_SEARCH_SUPPORT__
    	VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_SEARCH_ENGINE], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_SEARCH_ENGINE]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_SEARCH_ENGINE));
		UpdateHintText(m_setting[BRW_SETTINGS_SEARCH_ENGINE], BRW_SETTINGS_DATA_ITEM_SEARCH_ENGINE);
    	m_setting[BRW_SETTINGS_SEARCH_ENGINE]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[BRW_SETTINGS_SEARCH_ENGINE]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_SEARCH_ENGINE], BRW_SETTINGS_DATA_ITEM_SEARCH_ENGINE);//, VCPFRM_ITEMTYPE_LAUNCHER_CELL);
#endif

        VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_TIME_OUT], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_TIME_OUT]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_TIMEOUT));
		UpdateHintText(m_setting[BRW_SETTINGS_TIME_OUT], BRW_SETTINGS_DATA_ITEM_TIME_OUT);
    	
    	m_setting[BRW_SETTINGS_TIME_OUT]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[BRW_SETTINGS_TIME_OUT]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_TIME_OUT], BRW_SETTINGS_DATA_ITEM_TIME_OUT); //, VCPFRM_ITEMTYPE_LAUNCHER_CELL);

#ifdef __BAIDU_TRANSCODING_SUPPORT__		
    	VFX_OBJ_CREATE(m_switchTypeBaiduProxySetting, VcpFormItemSwitchCell, m_form);
    	m_switchTypeBaiduProxySetting->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_USE_BAIDU_PROXY));
        m_switchTypeBaiduProxySetting->setIsDisabled((VfxBool)(!g_srv_brw_cntx.is_http_conn));
		if(g_srv_brw_cntx.baidu_proxy_status == 1)
		{
    		m_switchTypeBaiduProxySetting->setSwitchStatus(VFX_TRUE);
		}
		else
		{
			m_switchTypeBaiduProxySetting->setSwitchStatus(VFX_FALSE);
		}
		m_UseBaiduProxyTemp = g_srv_brw_cntx.baidu_proxy_status;
    	m_resetBaiduProxysetting = 0;
		m_switchTypeBaiduProxySetting->m_signalSwitchChangeReq.connect(this, &VappSettingsPage::SwitchChangeReq);
    	m_switchTypeBaiduProxySetting->setIsTappable(VFX_FALSE);
        m_form->addItem(m_switchTypeBaiduProxySetting, BRW_SETTINGS_SELECT_ITEM_USE_BAIDU_PROXY);//VCPFRM_ITEMTYPE_SWITCH_CELL);
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
        VFX_OBJ_CREATE(m_switchTypeSetting, VcpFormItemSwitchCell, m_form);
    	m_switchTypeSetting->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_LOAD_IMAGES));
		if(g_srv_brw_cntx.show_images_status == 0)
		{
    		m_switchTypeSetting->setSwitchStatus(VFX_TRUE);
		}
		else
		{
			m_switchTypeSetting->setSwitchStatus(VFX_FALSE);
		}
		m_ShowImagesTemp = g_srv_brw_cntx.show_images_status;
    	
		m_switchTypeSetting->m_signalSwitchChangeReq.connect(this, &VappSettingsPage::SwitchChangeReq);
    	        m_switchTypeSetting->setIsTappable(VFX_FALSE);
        m_form->addItem(m_switchTypeSetting, BRW_SETTINGS_SELECT_ITEM_LOAD_IMAGES);//VCPFRM_ITEMTYPE_SWITCH_CELL);

		VFX_OBJ_CREATE(m_setting_header[1], VcpFormItemCaption, m_form);
    	m_setting_header[1]->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PRIVACY_OPTIONS));
        m_form->addItem(m_setting_header[1],BRW_SETTINGS_HEADER_ITEM_PRIVACY_OPTIONS); //, VCPFRM_ITEMTYPE_LAUNCHER_CELL);

        VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_PRIVATE_MODE], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_PRIVATE_MODE]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PRIVATE_MODE)); //change to STR_ID
		UpdateHintText(m_setting[BRW_SETTINGS_PRIVATE_MODE], BRW_SETTINGS_DATA_ITEM_PRIVATE_MODE);
    	m_setting[BRW_SETTINGS_PRIVATE_MODE]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[BRW_SETTINGS_PRIVATE_MODE]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_PRIVATE_MODE], BRW_SETTINGS_DATA_ITEM_PRIVATE_MODE);//VCPFRM_ITEMTYPE_LAUNCHER_CELL);
#ifndef __MMI_BRW_SLIM__
        VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_CLEAR_HISTORY], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_CLEAR_HISTORY]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_HISTORY)); //change to STR_ID
    
        m_setting[BRW_SETTINGS_CLEAR_HISTORY]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_CLEAR_HISTORY], BRW_SETTINGS_DATA_ITEM_CLEAR_HISTORY);//VCPFRM_ITEMTYPE_LAUNCHER_CELL);
#endif
       
#ifndef SLIM_WAP_MMS
        VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_CLEAR_CACHE], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_CLEAR_CACHE]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_CACHE));
    
        m_setting[BRW_SETTINGS_CLEAR_CACHE]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_CLEAR_CACHE], BRW_SETTINGS_DATA_ITEM_CLEAR_CACHE);// VCPFRM_ITEMTYPE_LAUNCHER_CELL);
        m_setting[BRW_SETTINGS_CLEAR_CACHE]->setIsDisabled((VfxBool)bam_registry_check_cache_status());
#endif // ? SLIM_WAP_MMS

        VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_CLEAR_COOKIES], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_CLEAR_COOKIES]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_COOKIE));
    
        m_setting[BRW_SETTINGS_CLEAR_COOKIES]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_CLEAR_COOKIES], BRW_SETTINGS_DATA_ITEM_CLEAR_COOKIES); //VCPFRM_ITEMTYPE_LAUNCHER_CELL);
        m_setting[BRW_SETTINGS_CLEAR_COOKIES]->setIsDisabled((VfxBool)bam_registry_check_cookie_status());
		

		VFX_OBJ_CREATE(m_setting_header[2], VcpFormItemCaption, m_form);
    	m_setting_header[2]->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_ACCOUNT_OPTIONS));
        m_form->addItem(m_setting_header[2], BRW_SETTINGS_HEADER_ITEM_ACCOUNT_OPTIONS); //, VCPFRM_ITEMTYPE_LAUNCHER_CELL);

		/****************Wi fi setting **********************************/
#if 0
#ifdef __MMI_WLAN_FEATURES__
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
#endif /* __MMI_WLAN_FEATURES__ */
#endif //0
        VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_DATA_ACCOUNT], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_DATA_ACCOUNT]->setMainText(VFX_WSTR_RES(STR_GLOBAL_DATA_CONN_SETTING));
		UpdateHintText(m_setting[BRW_SETTINGS_DATA_ACCOUNT], BRW_SETTINGS_DATA_ITEM_DATA_ACCOUNT);
    	m_setting[BRW_SETTINGS_DATA_ACCOUNT]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[BRW_SETTINGS_DATA_ACCOUNT]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_DATA_ACCOUNT], BRW_SETTINGS_DATA_ITEM_DATA_ACCOUNT);//VCPFRM_ITEMTYPE_LAUNCHER_CELL);
		m_setting[BRW_SETTINGS_DATA_ACCOUNT]->setIsDisabled((VfxBool)(!srv_sim_ctrl_any_sim_is_available()));
		
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))		
		VFX_OBJ_CREATE(m_setting_header[3], VcpFormItemCaption, m_form);
    	m_setting_header[3]->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_SECURITY));
        m_form->addItem(m_setting_header[3], BRW_SETTINGS_HEADER_ITEM_SECURITY); //, VCPFRM_ITEMTYPE_LAUNCHER_CELL);

		VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_VIEW_TRUSTED_CERTIFICATES], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_VIEW_TRUSTED_CERTIFICATES]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_VIEW_TRUSTED_CERTIFICATES));

    	m_setting[BRW_SETTINGS_VIEW_TRUSTED_CERTIFICATES]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[BRW_SETTINGS_VIEW_TRUSTED_CERTIFICATES]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_VIEW_TRUSTED_CERTIFICATES], BRW_SETTINGS_DATA_ITEM_VIEW_TRUSTED_CERTIFICATES);// VCPFRM_ITEMTYPE_LAUNCHER_CELL);


		VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_AUTH_INFO));
        m_setting[BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO], BRW_SETTINGS_DATA_ITEM_CLEAR_AUTHENTICATION_INFO);// VCPFRM_ITEMTYPE_LAUNCHER_CELL);
         m_setting[BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO]->setIsDisabled((VfxBool)bam_registry_check_auth_status());
#endif


		VFX_OBJ_CREATE(m_setting_header[4], VcpFormItemCaption, m_form);
    	m_setting_header[4]->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_RESTORE_SETTINGS));
        m_form->addItem(m_setting_header[4], BRW_SETTINGS_HEADER_ITEM_RESTORE_SETTINGS); //, VCPFRM_ITEMTYPE_LAUNCHER_CELL);

		VFX_OBJ_CREATE(m_setting[BRW_SETTINGS_RESTORE_DEFAULT_SETTINGS], VcpFormItemLauncherCell, m_form);
    	m_setting[BRW_SETTINGS_RESTORE_DEFAULT_SETTINGS]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_BRW_RESTORE_DEFAULT_SETTINGS));
  
        m_setting[BRW_SETTINGS_RESTORE_DEFAULT_SETTINGS]->m_signalTap.connect(this, &VappSettingsPage::onButtonClicked);
        m_form->addItem(m_setting[BRW_SETTINGS_RESTORE_DEFAULT_SETTINGS], BRW_SETTINGS_DATA_ITEM_RESTORE_DEFAULT_SETTINGS);// VCPFRM_ITEMTYPE_LAUNCHER_CELL);

}

void VappSettingsPage::onEnter(VfxBool isBackward)
{
    if(isBackward)
    {
#ifdef __BAIDU_TRANSCODING_SUPPORT__		
        m_switchTypeBaiduProxySetting->setIsDisabled((VfxBool)(!g_srv_brw_cntx.is_http_conn));
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
#endif //0
    	m_resetBaiduProxysetting = 0;
#endif //__BAIDU_TRANSCODING_SUPPORT__
    }
}


void VappSettingsPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
	{
				
	}
	else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	}

}


void VappSettingsPage::onRotate(const VfxScreenRotateParam &param)
{
}


void VappSettingsPage::onDeinit(void)
{
	VFX_OBJ_CLOSE(m_setting_header[0]);
#ifndef __GOOGLE_SEARCH_SUPPORT__
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_SEARCH_ENGINE]);
#endif
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_TIME_OUT]);
	VFX_OBJ_CLOSE(m_switchTypeSetting);
	VFX_OBJ_CLOSE(m_setting_header[1]);
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_PRIVATE_MODE]);
	#ifndef __MMI_BRW_SLIM__
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_CLEAR_HISTORY]);
	#endif
#ifndef SLIM_WAP_MMS
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_CLEAR_CACHE]);
#endif // ? SLIM_WAP_MMS
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_CLEAR_COOKIES]);
	VFX_OBJ_CLOSE(m_setting_header[2]);
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_DATA_ACCOUNT]);
#if (defined (WAP_SEC_SUPPORT) && !defined (__LOW_COST_SUPPORT_COMMON__))
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_VIEW_TRUSTED_CERTIFICATES]);
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO]);
	VFX_OBJ_CLOSE(m_setting_header[3]);
#endif
	VFX_OBJ_CLOSE(m_setting[BRW_SETTINGS_RESTORE_DEFAULT_SETTINGS]);
	VFX_OBJ_CLOSE(m_setting_header[4]);
	VFX_OBJ_CLOSE(m_form);
	if(g_srv_brw_cntx.show_images_status != m_ShowImagesTemp)
	{
		g_srv_brw_cntx.show_images_status = m_ShowImagesTemp;
		srv_brw_update_settings_data(SRV_BRW_NVRAM_SHOW_IMAGE_MODE);
		srv_brw_change_setting_value_req(
			wap_bam_setting_value_type_int,
			wap_bam_setting_id_images,
			g_srv_brw_cntx.show_images_status,
			NULL);
	}
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    if(g_srv_brw_cntx.baidu_proxy_status != m_UseBaiduProxyTemp)
	{
        if(!m_resetBaiduProxysetting)
        {
	        g_srv_brw_cntx.baidu_proxy_status = m_UseBaiduProxyTemp;
	        srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY);
	        srv_brw_change_setting_value_req(
		        wap_bam_setting_value_type_int,
		        wap_bam_setting_id_transcode_proxy,
		        g_srv_brw_cntx.baidu_proxy_status,
		        NULL);
            m_resetBaiduProxysetting = 0;
        }
	}
#endif /* #ifdef __BAIDU_TRANSCODING_SUPPORT__ */

#if 0
#ifdef __MMI_WLAN_FEATURES__
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
		#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#else
/* under construction !*/
		#endif /*#if (MMI_MAX_SIM_NUM >= 2) */ 
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
#endif /* __MMI_WLAN_FEATURES__ */
#endif //0
	VfxPage::onDeinit();
}
	
void VappSettingsPage::UpdateHintText(VcpFormItemLauncherCell* item, VfxId id)
{
	if(id == BRW_SETTINGS_DATA_ITEM_TIME_OUT)
	{
		if(g_srv_brw_cntx.timeout_value == 30)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_30_SEC));
		else if(g_srv_brw_cntx.timeout_value == 60)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_60_SEC));
		else if(g_srv_brw_cntx.timeout_value == 120)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_2_MINS));
		else if(g_srv_brw_cntx.timeout_value == 180)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_3_MINS));
		else if(g_srv_brw_cntx.timeout_value == 240)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_4_MINS));
		else if(g_srv_brw_cntx.timeout_value == 300)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_5_MINS));
	}
#ifndef __GOOGLE_SEARCH_SUPPORT__
	else if(id == BRW_SETTINGS_DATA_ITEM_SEARCH_ENGINE)
	{
		if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_BAIDU)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_BAIDU)); // change this
		else if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_GOOGLE)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_GOOGLE));
		else if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_YAHOO)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_YAHOO));
		else if(g_srv_brw_cntx.sel_search_engine == SRV_BRW_SEARCH_ENGINE_BING)
			item->setHintText(VFX_WSTR_RES(STR_ID_VAPP_BRW_BING));
	}
#endif
	else if(id == BRW_SETTINGS_DATA_ITEM_PRIVATE_MODE)
	{
		if(g_srv_brw_cntx.private_mode_setting == 1)
			item->setHintText(VFX_WSTR_RES(STR_GLOBAL_ON));
		else
			item->setHintText(VFX_WSTR_RES(STR_GLOBAL_OFF));
	}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	else if(id == 12)
	{
	}

}
void VappSettingsPage::SwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
	if(id == BRW_SETTINGS_SELECT_ITEM_LOAD_IMAGES)
	{		
		if(newStatus == VFX_TRUE)
			m_ShowImagesTemp = 0;
		else
			m_ShowImagesTemp = 2;
		item->setSwitchStatus(newStatus);
	}
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    else if(id == BRW_SETTINGS_SELECT_ITEM_USE_BAIDU_PROXY)
	{
		if(newStatus == VFX_TRUE)
		{
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		    VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, m_brwApp->scr->m_settings);
    		
		    m_confirm->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_USE_BAIDU_PROXY_CONFIRM));
		    m_confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);

		    m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		    m_confirm->setCustomButton(
			    VFX_WSTR_RES(STR_GLOBAL_YES),
			    VFX_WSTR_RES(STR_GLOBAL_NO),
			    VCP_POPUP_BUTTON_TYPE_NORMAL,
			    VCP_POPUP_BUTTON_TYPE_CANCEL);

		    m_confirm->m_signalButtonClicked.connect(this, &VappSettingsPage::onBaiduProxyConfirm);
		    m_confirm->show(VFX_TRUE);
			//m_UseBaiduProxyTemp = 1;
		}
			
		else
		{
			m_UseBaiduProxyTemp = 0;
		}
			
		item->setSwitchStatus(newStatus);
	} 
#endif /* #ifdef __BAIDU_TRANSCODING_SUPPORT__ */

}

#ifndef __MMI_BRW_SLIM__
void VappSettingsPage::onClearHistory(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
		VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);
		#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
		srv_brw_address_list_delete_all_items();
		srv_brw_search_list_delete_all_items();
        srv_brw_read_address_list_data();
        srv_brw_read_search_item_list_data();
		#endif
		srv_brw_act_req_struct obj = {0};
		obj.rsp_callback = VappSettingsPage::OnDataClearCallback;
		srv_brw_delete_all_recent_pages_req(&obj);
    }
}
#endif
void VappSettingsPage::OnDataClearCallback(S32 user_data, U32 result, void *obj)
{
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	m_brwApp->scr->m_settings->m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_brwApp->scr->m_settings->m_popup);
	VappBrowserUtility::displayPopup(
            STR_GLOBAL_DONE,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
			MMI_EVENT_INFO_BALLOON);
#ifndef SLIM_WAP_MMS
    m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_CLEAR_CACHE]->setIsDisabled((VfxBool)bam_registry_check_cache_status());
#endif // ? SLIM_WAP_MMS
    m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_CLEAR_COOKIES]->setIsDisabled((VfxBool)bam_registry_check_cookie_status());
	#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
    m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_CLEAR_AUTHENTICATION_INFO]->setIsDisabled((VfxBool)bam_registry_check_auth_status());
	#endif
}

#ifndef SLIM_WAP_MMS
void VappSettingsPage::onClearCache(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);
        srv_brw_act_req_struct obj = {0};
		obj.rsp_callback = VappSettingsPage::OnDataClearCallback;
		srv_brw_list_element_req_struct data;
		data.index = WPS_CLEAR_CACHE_ALL;
		obj.req_data = (void*)&data;
		srv_brw_settings_clear_data_req(&obj);
    }
}
#endif // ? SLIM_WAP_MMS
#ifdef __BAIDU_TRANSCODING_SUPPORT__
void VappSettingsPage::onBaiduProxyConfirm(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_UseBaiduProxyTemp = 1;
        m_switchTypeBaiduProxySetting->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        m_UseBaiduProxyTemp = 0;
        m_switchTypeBaiduProxySetting->setSwitchStatus(VFX_FALSE);
    }
}
#endif /* #ifdef __BAIDU_TRANSCODING_SUPPORT__ */

void VappSettingsPage::onClearCookies(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);
        srv_brw_act_req_struct obj = {0};
		obj.rsp_callback = VappSettingsPage::OnDataClearCallback;
		srv_brw_list_element_req_struct data;
		data.index = WPS_CLEAR_COOKIES_ALL;
		obj.req_data = (void*)&data;
		srv_brw_settings_clear_data_req(&obj); 
    }
}

void VappSettingsPage::onClearAuthenticationInfo(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);
        srv_brw_act_req_struct obj = {0};
		obj.rsp_callback = VappSettingsPage::OnDataClearCallback;
		srv_brw_list_element_req_struct data;
		data.index = WPS_CLEAR_AUTH_ALL;
		obj.req_data = (void*)&data;
		srv_brw_settings_clear_data_req(&obj);
    }
}

void VappSettingsPage::onRestoreBrowserSettings(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);
		srv_brw_settings_restore_data();
        srv_brw_settings_update_all_data();
		m_ShowImagesTemp = g_srv_brw_cntx.show_images_status;
#ifdef __BAIDU_TRANSCODING_SUPPORT__
        m_UseBaiduProxyTemp = g_srv_brw_cntx.baidu_proxy_status; 
#endif /* #ifdef __BAIDU_TRANSCODING_SUPPORT__ */
		srv_wap_prof_profile_content_struct *profile_content_p;
        srv_brw_act_req_struct obj = {0};
		srv_brw_set_profile_req_struct prof;
		srv_brw_get_profile_content((void **)&profile_content_p);
		prof.currprof = profile_content_p;
		prof.setting_id = wap_bam_setting_type_settings;
		VfxAppBrowserSettingsInterface::m_dispatchCallback.connect(this , &VappSettingsPage::RestoreProfileRspcallback);
		obj.rsp_callback = VfxAppBrowserSettingsInterface::OnServiceRspCallback;
		obj.req_data = (void*)&prof;
		srv_brw_set_profile_req_by_data(&obj);
        OslMfree(profile_content_p);
    }
}


void VappSettingsPage::RestoreProfileRspcallback(S32 user_data , U32 result, void* rsp_data)
{
	VfxAppBrowserSettingsInterface::m_dispatchCallback.disconnect(this , &VappSettingsPage::RestoreProfileRspcallback);
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	m_brwApp->scr->m_settings->m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_brwApp->scr->m_settings->m_popup);
	VappBrowserUtility::displayPopup(
            STR_GLOBAL_DONE,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
			MMI_EVENT_INFO_BALLOON);
	m_brwApp->scr->m_settings->UpdateHintText((m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_PRIVATE_MODE]), BRW_SETTINGS_DATA_ITEM_PRIVATE_MODE);
#ifndef __GOOGLE_SEARCH_SUPPORT__
	m_brwApp->scr->m_settings->UpdateHintText((m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_SEARCH_ENGINE]), BRW_SETTINGS_DATA_ITEM_SEARCH_ENGINE);
#endif
	m_brwApp->scr->m_settings->UpdateHintText((m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_TIME_OUT]), BRW_SETTINGS_DATA_ITEM_TIME_OUT);
	if(g_srv_brw_cntx.show_images_status == 0)
	{
		m_switchTypeSetting->setSwitchStatus(VFX_TRUE);
	}
	else
	{
		m_switchTypeSetting->setSwitchStatus(VFX_FALSE);
	}
#ifdef __BAIDU_TRANSCODING_SUPPORT__
     m_switchTypeBaiduProxySetting->setIsDisabled((VfxBool)(!g_srv_brw_cntx.is_http_conn));
	if(g_srv_brw_cntx.baidu_proxy_status == 1)
	{
		m_switchTypeBaiduProxySetting->setSwitchStatus(VFX_TRUE);
	}
	else
	{
		m_switchTypeBaiduProxySetting->setSwitchStatus(VFX_FALSE);
	}
#endif //#ifdef __BAIDU_TRANSCODING_SUPPORT__

#if 0
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WLAN_FEATURES__ */
#endif //0
}

void VappStaticListPage::PrivateModeRspcallback(S32 user_data , U32 result, void* rsp_data)
{
	VfxAppBrowserSettingsInterface::m_dispatchCallback.disconnect(this , &VappStaticListPage::PrivateModeRspcallback);
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	m_brwApp->scr->m_settings->UpdateHintText((m_brwApp->scr->m_settings->m_setting[BRW_SETTINGS_PRIVATE_MODE]), BRW_SETTINGS_DATA_ITEM_PRIVATE_MODE);
	m_brwApp->scr->popPage();
}


void VappStaticListPage::onRotate(const VfxScreenRotateParam &param)
{
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
/* under construction !*/
/* under construction !*/
#endif //0
}
void VappSettingsPage::onButtonClicked(VcpFormItemCell* sender, VfxId Id)
{
	switch(Id)
	{
#ifndef __GOOGLE_SEARCH_SUPPORT__
	    case BRW_SETTINGS_DATA_ITEM_SEARCH_ENGINE:
	    {
            VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		    VFX_OBJ_CREATE_EX(m_brwApp->scr->m_StaticListPage, VappStaticListPage, m_brwApp->scr, (BRW_STATIC_LIST_TYPE_SEARCH_ENGINE));
		    m_brwApp->scr->pushPage(VFX_ID_NULL, m_brwApp->scr->m_StaticListPage);
	    }

		break;
#endif
	case BRW_SETTINGS_DATA_ITEM_TIME_OUT:
	{
		
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		VFX_OBJ_CREATE_EX(m_brwApp->scr->m_StaticListPage, VappStaticListPage, m_brwApp->scr, (BRW_STATIC_LIST_TYPE_TIMEOUT));
		m_brwApp->scr->pushPage(3, m_brwApp->scr->m_StaticListPage);
	}
		break;
	case BRW_SETTINGS_DATA_ITEM_PRIVATE_MODE:
	{
		
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		VFX_OBJ_CREATE_EX(m_brwApp->scr->m_StaticListPage, VappStaticListPage, m_brwApp->scr, (BRW_STATIC_LIST_TYPE_PRIVATE_MODE));
		m_brwApp->scr->pushPage(4, m_brwApp->scr->m_StaticListPage);
	}
		break;
#ifndef __MMI_BRW_SLIM__
	case BRW_SETTINGS_DATA_ITEM_CLEAR_HISTORY:
	{
		
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		//VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, m_brwApp->scr->m_settings);
        m_confirm = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
            VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_ALL_CONFIRMATION),
            VFX_WSTR_RES(STR_GLOBAL_CLEAR));
        m_confirm->m_signalButtonClicked.connect(this, &VappSettingsPage::onClearHistory);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	}
		break;
#endif
#ifndef SLIM_WAP_MMS
	case BRW_SETTINGS_DATA_ITEM_CLEAR_CACHE:
	{
		
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		//VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, m_brwApp->scr->m_settings);
		m_confirm = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
            VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_COMPLETE_CACHE_CONFIRM),
            VFX_WSTR_RES(STR_GLOBAL_CLEAR));
        m_confirm->m_signalButtonClicked.connect(this, &VappSettingsPage::onClearCache);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	}
		break;
#endif // ? SLIM_WAP_MMS
	case BRW_SETTINGS_DATA_ITEM_CLEAR_COOKIES:
	{
	
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		//VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, m_brwApp->scr->m_settings);	
		m_confirm = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
            VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_ALL_COOKIES_CONFIRM),
            VFX_WSTR_RES(STR_GLOBAL_CLEAR));
        m_confirm->m_signalButtonClicked.connect(this, &VappSettingsPage::onClearCookies);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	}
		break;
	case BRW_SETTINGS_DATA_ITEM_DATA_ACCOUNT:
	{
		srv_wap_prof_display_profile_list(
			SRV_WAP_PROF_SIMID_SIM1,
			SRV_WAP_PROF_APPID_BRW,
			0, // To DO :Handle icon problem
			0,
			m_browserAppID);
	}
		break;
#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
	case BRW_SETTINGS_DATA_ITEM_VIEW_TRUSTED_CERTIFICATES:
	{
		
		VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);
		srv_brw_act_req_struct obj = {0};
		obj.rsp_callback = VappBrwServiceInterface :: getTrustedCertificateListHdlr;
		srv_brw_get_trusted_certificate_ids_req(&obj);
	}
		break;
#endif
	case BRW_SETTINGS_DATA_ITEM_CLEAR_AUTHENTICATION_INFO:
	{
		//VcpConfirmPopup *deleteConfirm;
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		//VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, m_brwApp->scr->m_settings);
		
		m_confirm = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
            VFX_WSTR_RES(STR_ID_VAPP_BRW_CLEAR_AUTH_INFO_CONFIRM),
            VFX_WSTR_RES(STR_GLOBAL_CLEAR));
        m_confirm->m_signalButtonClicked.connect(this, &VappSettingsPage::onClearAuthenticationInfo);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	}
		break;
	case BRW_SETTINGS_DATA_ITEM_RESTORE_DEFAULT_SETTINGS:
	{
        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
		//VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, m_brwApp->scr->m_settings);
        
        m_confirm = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
            VFX_WSTR_RES(STR_ID_VAPP_BRW_CONFIRM_RESTORE_SETTINGS),
            VFX_WSTR_RES(STR_ID_VAPP_BRW_RESTORE));
        m_confirm->m_signalButtonClicked.connect(this, &VappSettingsPage::onRestoreBrowserSettings);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	}
		break;
	default:
		break;
	}
}

#if (defined (WAP_SEC_SUPPORT)  && !defined (__LOW_COST_SUPPORT_COMMON__))
void VappBrwServiceInterface :: getTrustedCertificateListHdlr(
        S32 user_data,       // [IN] the user data provided to the service by the application
        U32 result,              // [IN] the result of the get trusted certificate list operation
        void *obj)                 // [IN] the void pointer containing the data if needed by application)
{
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	m_brwApp->scr->m_settings->m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_brwApp->scr->m_settings->m_popup);
	VFX_OBJ_CREATE_EX(m_brwApp->scr->m_StaticListPage, VappStaticListPage, m_brwApp->scr, (BRW_STATIC_LIST_TYPE_TRUSTED_CERTFICATES));
	m_brwApp->scr->pushPage(6, m_brwApp->scr->m_StaticListPage);
}


/***************************************************************************** 
 * class VappBrwTrustedCertViewerPage
 *****************************************************************************/

void VappBrwTrustedCertViewerPage::ViewCertcallback(S32 user_data, U32 result, void *obj)
{
    VfxAppBrowserSettingsInterface::m_dispatchCallback.disconnect(this , &VappBrwTrustedCertViewerPage::ViewCertcallback);
    wps_sec_get_cert_rsp_struct *data = (wps_sec_get_cert_rsp_struct*)obj;
    if (result || (data->cert_id != (U32)user_data))
    {
        VappBrowserUtility::displayPopup(
        STR_ID_VAPP_BRW_REQUEST_FAILED,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        MMI_EVENT_INFO_BALLOON);

        VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
        m_brwApp->scr->m_TrustedCertViewerPage->m_popup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(m_brwApp->scr->m_TrustedCertViewerPage->m_popup);
        return;
    }
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    m_brwApp->scr->m_TrustedCertViewerPage->m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_brwApp->scr->m_TrustedCertViewerPage->m_popup);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_CERTIFICATE_DETAILS));
    setTopBar(bar);
    VFX_OBJ_CREATE(m_tool_bar,VcpToolBar,this);
    setBottomBar(m_tool_bar);
    m_tool_bar->addItem(0, VFX_WSTR_EMPTY,VFX_IMAGE_SRC_TYPE_NULL);
    m_tool_bar->addItem(1, VFX_WSTR_RES(STR_GLOBAL_DELETE),VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

    m_tool_bar->m_signalButtonTap.connect(this, &VappBrwTrustedCertViewerPage::onCertViewerToolBarClick);

    m_trusted_cert_p = (mmi_brw_certificate_content_struct*)VappBrowserASMMemoryMgmt::allocMemory((sizeof(mmi_brw_certificate_content_struct)));
    memset(m_trusted_cert_p, 0, sizeof(mmi_brw_certificate_content_struct));
    CopyTrustedCertViewerData(m_trusted_cert_p, &data->cert);

    VFX_OBJ_CREATE(m_text, VcpTextView, this);

    VfxRect page_rect = getRect();
    VfxRect rect(0, 0, page_rect.size.width, page_rect.size.height);
    m_text->setRect(rect);

    //m_text->setBgColor(VFX_COLOR_WHITE);

    m_text->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    m_bufPtr = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((VAPP_BRW_MAX_CERT_DISP_BUFF + 1 ) * ENCODING_LENGTH);
    memset(m_bufPtr, 0, (VAPP_BRW_MAX_CERT_DISP_BUFF + 1 ) * ENCODING_LENGTH);
    m_text->setText((VfxWChar*)m_bufPtr, VFX_TRUE);
    m_text->setMargins(BRW_DETAILS_MARGIN, BRW_DETAILS_MARGIN, BRW_DETAILS_MARGIN, BRW_DETAILS_MARGIN);
    VfxWString issuer;
    /***********************************ISSUER ********************************/
    if(m_trusted_cert_p->issuer)
    {
        VfxWString nameHeading;
        nameHeading.loadFromRes(STR_ID_VAPP_BRW_NAME_HEADING);
        nameHeading += VFX_WSTR("\n");
        m_text->addDetail(nameHeading, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);
        VfxWChar *IssuerPtr = issuer.lockBuf((data->cert.issuer_len + 1) * ENCODING_LENGTH);
        mmi_asc_to_ucs2((VfxChar *) IssuerPtr, (VfxChar *) m_trusted_cert_p->issuer);
        issuer.unlockBuf();
        issuer += VFX_WSTR("\n");
        m_text->addDetail(issuer, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);
    }

    VfxWString activated;
    activated.loadFromRes(STR_ID_VAPP_BRW_ACTIVATED);
    activated += VFX_WSTR("\n");
    m_text->addDetail(activated, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);
    S32 local_time_in_sec;
    VfxWString time_active;
    applib_time_struct time_obj;
    local_time_in_sec = applib_dt_sec_utc_to_local(m_trusted_cert_p->not_before);
    applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
    VfxDateTime date_time;
    date_time.setDate(time_obj.nYear, time_obj.nMonth, time_obj.nDay);
    time_active = date_time.getDateTimeString(VFX_DATE_TIME_DATE_YEAR|VFX_DATE_TIME_DATE_MONTH|VFX_DATE_TIME_DATE_DAY);
    time_active += VFX_WSTR("\n");
    m_text->addDetail(time_active, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);

    VfxWString expires;
    expires.loadFromRes(STR_ID_VAPP_BRW_EXPIRES);
    expires += VFX_WSTR("\n");
    m_text->addDetail(expires, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);
    VfxWString time_expires;
    local_time_in_sec = applib_dt_sec_utc_to_local(m_trusted_cert_p->not_after);
    applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
    date_time.setDate(time_obj.nYear, time_obj.nMonth, time_obj.nDay);
    time_expires = date_time.getDateTimeString(VFX_DATE_TIME_DATE_YEAR|VFX_DATE_TIME_DATE_MONTH|VFX_DATE_TIME_DATE_DAY);
    time_expires += VFX_WSTR("\n");
    m_text->addDetail(time_expires, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);

    if(m_trusted_cert_p->subject)
    {
        VfxWString subjectHeading;
        subjectHeading.loadFromRes(STR_ID_VAPP_BRW_SUBJECT);
        subjectHeading += VFX_WSTR("\n");
        m_text->addDetail(subjectHeading, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);

        VfxWString subject;
        VfxWChar *subjectPtr = subject.lockBuf((data->cert.subject_len + 1) * ENCODING_LENGTH);
        mmi_asc_to_ucs2((VfxChar *) subjectPtr, (VfxChar *) m_trusted_cert_p->subject);
        subject.unlockBuf();
        subject += VFX_WSTR("\n");
        m_text->addDetail(subject, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);
    }
    U8* temp_str;
    if(m_trusted_cert_p->serial_num_len)
    {
        VfxWString serial_no;
        U16 serial_num_len = m_trusted_cert_p->serial_num_len;
        U8* serial_num_hex_p = (U8*)mmi_frm_temp_alloc((serial_num_len * 3) + 1);
        temp_str = (U8*)mmi_frm_temp_alloc(VAPP_BRW_MAX_CERT_DISP_BUFF + 1);
        for (U16 pos = 0; pos < serial_num_len; pos++)
        {
            sprintf((CHAR*) temp_str, "%x ", m_trusted_cert_p->serial_num[pos]);
            if (strlen((CHAR*) temp_str) < 3)
            {
                sprintf((CHAR*) temp_str, "0%x ", m_trusted_cert_p->serial_num[pos]);
            }
            if (pos == 0)
            {
                strcpy((CHAR*) serial_num_hex_p, (CHAR*) temp_str);
            }
            else
            {
                strcat((CHAR*) serial_num_hex_p, (CHAR*) temp_str);
            }
        }
        VfxWString serialNum;
        serialNum.loadFromRes(STR_ID_VAPP_BRW_SERIAL_NUM);
        serialNum += VFX_WSTR("\n");
        m_text->addDetail(serialNum, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);

        VfxWChar *serialNumPtr = serial_no.lockBuf((m_trusted_cert_p->serial_num_len + 1) * 3);
        mmi_asc_to_ucs2((VfxChar *) serialNumPtr, (VfxChar *) serial_num_hex_p);
        serial_no.unlockBuf();
        serial_no += VFX_WSTR("\n");
        m_text->addDetail(serial_no, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);
        mmi_frm_temp_free(serial_num_hex_p);
        serial_num_hex_p = NULL;
        mmi_frm_temp_free(temp_str);
        temp_str = NULL;
    }

    if(m_trusted_cert_p->sig_alg_name)
    {
        VfxWString signature;
        signature.loadFromRes(STR_ID_VAPP_BRW_SIGNATURE);
        signature += VFX_WSTR("\n");
        m_text->addDetail(signature, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);
        VfxWString sig_algo;
        sig_algo.format("%s", m_trusted_cert_p->sig_alg_name);
        sig_algo += VFX_WSTR("\n");
        m_text->addDetail(sig_algo, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);
    }
    VfxWString type;
    type.loadFromRes(STR_ID_VAPP_BRW_TYPE);
    type += VFX_WSTR("\n");
    m_text->addDetail(type, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);
    VfxWString cert_type;
    temp_str = (U8*)mmi_frm_temp_alloc(VAPP_BRW_MAX_CERT_DISP_BUFF + 1);
    sprintf((CHAR*) temp_str, "%d", m_trusted_cert_p->type);
    cert_type.format("%s", temp_str);
    cert_type += VFX_WSTR("\n");
    m_text->addDetail(cert_type, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);
    mmi_frm_temp_free(temp_str);
    temp_str = NULL;

    VfxWString version;
    version.loadFromRes(STR_ID_VAPP_BRW_VERSION);
    version += VFX_WSTR("\n");
    m_text->addDetail(version, VCP_TEXT_DETAIL_TITLE, VAPP_BRW_MAX_CERT_DISP_BUFF);
    VfxWString version_type;
    temp_str = (U8*)mmi_frm_temp_alloc(VAPP_BRW_MAX_CERT_DISP_BUFF + 1);
    sprintf((CHAR*) temp_str, "%d", m_trusted_cert_p->version);
    version_type.format("%s", temp_str);
    version_type += VFX_WSTR("\n");
    m_text->addDetail(version_type, VCP_TEXT_DETAIL_CONTENT, VAPP_BRW_MAX_CERT_DISP_BUFF);
    mmi_frm_temp_free(temp_str);
    temp_str = NULL;

}


void VappBrwTrustedCertViewerPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
	{
				
	}
	else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}

}


void VappBrwTrustedCertViewerPage::onDeinit(void)
{

	VFX_OBJ_CLOSE(m_tool_bar);
	VFX_OBJ_CLOSE(m_text);
	VappBrowserASMMemoryMgmt::freeMemory(m_trusted_cert_p);
	m_trusted_cert_p = NULL;
	VappBrowserASMMemoryMgmt::freeMemory(m_bufPtr);
	m_bufPtr = NULL;
	VfxPage::onDeinit();
}

void VappBrwTrustedCertViewerPage::onInit(void)
{
	VfxPage::onInit();
	
	VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->show(VFX_TRUE);
    srv_brw_act_req_struct obj = {0};
	srv_brw_list_element_req_struct data;
	data.index = srv_brw_trusted_certificate_get_actual_id(m_index);
	obj.req_data = (void*)&data;
	obj.user_data = data.index;
	VfxAppBrowserSettingsInterface::m_dispatchCallback.connect(this , &VappBrwTrustedCertViewerPage::ViewCertcallback);
	obj.rsp_callback = VfxAppBrowserSettingsInterface::OnServiceRspCallback;
	srv_brw_get_trusted_certificate_req(&obj);
	g_srv_brw_cntx.srv_brw_dynamic_cntx_p->view_cert_flag = MMI_TRUE;  
}

void VappBrwTrustedCertViewerPage::CopyTrustedCertViewerData(
        mmi_brw_certificate_content_struct *dest_p,
        wps_sec_cert_content_struct *src_p)
{
	memcpy(dest_p->issuer, src_p->issuer, src_p->issuer_len + 1);
    dest_p->not_after = src_p->not_after;
    dest_p->not_before = src_p->not_before;
    memcpy(dest_p->serial_num, src_p->serial_num, src_p->serial_num_len + 1);
    dest_p->serial_num_len = src_p->serial_num_len;
    memcpy(dest_p->sig_alg_name, src_p->sig_alg_name, src_p->sig_alg_name_len + 1);
    memcpy(dest_p->subject, src_p->subject, src_p->subject_len + 1);
    dest_p->type = src_p->type;
    dest_p->version = src_p->version;
}

void VappBrwTrustedCertViewerPage::onCertViewerToolBarClick(VfxObject* sender, VfxId id)
{
	switch(id)
	{
		case 0:
			break;
		case 1:
			{
                VcpConfirmPopup *confirmPopup;
                confirmPopup = VappBrowserUtility::displayDeleteConfirmPopup(this, VCP_POPUP_TYPE_WARNING,
                    VFX_WSTR_RES(STR_ID_VAPP_BRW_DELETE_CERTIFICATE_CONFIRM),
                    VFX_WSTR_RES(STR_GLOBAL_DELETE));
                confirmPopup->m_signalButtonClicked.connect(this, &VappBrwTrustedCertViewerPage::certificateDeleteHandler);
			}	
			break;
	   default:
			break;
	}
}

void VappBrwTrustedCertViewerPage::certificateDeleteHandler(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
		m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
		m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_BRW_PLEASE_WAIT));
		m_popup->setAutoDestory(VFX_FALSE);
		m_popup->show(VFX_TRUE);
		srv_brw_act_req_struct obj = {0};
		srv_brw_list_element_req_struct data;
		data.index = srv_brw_trusted_certificate_get_actual_id(m_index);
		obj.req_data = (void*)&data;
		obj.user_data = data.index;
		//VfxAppBrowserSettingsInterface::m_dispatchCallback.disconnect(this , &VappBrwTrustedCertViewerPage::ViewCertcallback);
		VfxAppBrowserSettingsInterface::m_dispatchCallback.connect(this , &VappBrwTrustedCertViewerPage::DeleteCertcallback);
		obj.rsp_callback = VfxAppBrowserSettingsInterface::OnServiceRspCallback;
		srv_brw_trusted_certificates_delete_req(&obj);
    }
}

void VappBrwTrustedCertViewerPage::UpdatedCertListcallback(S32 user_data, U32 result, void *obj)
{
	VfxAppBrowserSettingsInterface::m_dispatchCallback.disconnect(this , &VappBrwTrustedCertViewerPage::UpdatedCertListcallback);
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	m_brwApp->scr->m_TrustedCertViewerPage->m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_brwApp->scr->m_TrustedCertViewerPage->m_popup);
	m_brwApp->scr->popPage();
}
void VappBrwTrustedCertViewerPage::DeleteCertcallback(S32 user_data, U32 result, void *obj)
{
    VfxAppBrowserSettingsInterface::m_dispatchCallback.disconnect(this , &VappBrwTrustedCertViewerPage::DeleteCertcallback);
    if (result == WPS_OK)
    {
        VappBrowserUtility::displayPopup(
            STR_GLOBAL_DELETED,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
            MMI_EVENT_INFO_BALLOON);
    }
    else
    {
        VappBrowserUtility::displayPopup(
            STR_ID_VAPP_BRW_REQUEST_FAILED,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            MMI_EVENT_INFO_BALLOON);
    }
        VfxAppBrowserSettingsInterface::m_dispatchCallback.connect(this , &VappBrwTrustedCertViewerPage::UpdatedCertListcallback);
        srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
        srv_brw_act_req_struct obj1 = {0};
        obj1.rsp_callback = VfxAppBrowserSettingsInterface::OnServiceRspCallback;
        srv_brw_get_trusted_certificate_ids_req(&obj1);
}
#endif
//#pragma arm section code, rodata

#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_SETTINGS_CPP_ */
