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
 *  vapp_mms_setting.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_include.h"
#include "vapp_msg_features.h"
#ifdef __MMI_MMS_2__
#include "mmi_rp_vapp_mms_def.h"
#include "vapp_mms_set_cm.h"
#include "vapp_mms_setting.h"
#include "vapp_mms_setting_prot.h"
#include "vapp_mms_slide_edi.h"
#include "vapp_mms_set_retvl.h"
#include "vapp_mms_set_send.h"

#include "vcp_status_icon_bar.h"
#include "vcp_include.h"
#include "vcp_navi_title_bar.h"
#include "../xml/vfx_xml_loader.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"

 

 extern "C" {
   #include "MmsSrvGprot.h"
	#include "WAPProfileSrvGProt.h"
#include "WAPProfileSrvType.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
	 #include "mms_sap_struct.h"
	 #include "mmi_inet_app_trc.h"   
#include "SimCtrlSrvGprot.h"
#include "vapp_mms_appcore.h"
 }
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

// This is main entry function for our testing
extern void vapp_mms_setting_launch(void);

#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Function
 *****************************************************************************/

VfxBool vapp_mms_app_if_show_edit_profile_screen(void);
//VappMMSSettingScreen *scr;


#ifdef __MMI_MMS_SETTING_PAGE__

extern "C" void vapp_mms_setting_launch(void)
{
    //VfxAppLauncher::launch( 
    //    FW_TEST1,
    //    VFX_OBJ_CLASS_INFO(VappMMSSettingApp),
    //    GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappMMSSettingApp", VappMMSSettingApp, VfxApp);

void VappMMSSettingApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
	VappMMSSettingScreen *scr;
    VFX_OBJ_CREATE(scr, VappMMSSettingScreen, this);
    scr->show();
}

VFX_IMPLEMENT_CLASS("VappMMSSettingScreen", VappMMSSettingScreen, VfxMainScr);

void VappMMSSettingScreen::on1stReady()
{
    VfxMainScr::on1stReady();
	VappMMSSettingPage *mmsSettingPage;
	VfxKeypad::registerHandler(VFX_KEY_CODE_RSK, this);
    // create and display first page
    VFX_OBJ_CREATE(mmsSettingPage, VappMMSSettingPage, this);
    pushPage(0, mmsSettingPage);
							    
}

void VappMMSSettingScreen::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

VfxBool VappMMSSettingScreen:: onKeyInput(VfxKeyEvent& event)
{
	if(event.keyCode == VFX_KEY_CODE_RSK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		popPage();
		return VFX_TRUE;
	}
	return VfxMainScr:: onKeyInput(event);
}
/*****************************************************************************
*Class VappMMSSettingPage
****************************************************************************/
/*
* This class implement main setting page.
*/

VFX_IMPLEMENT_CLASS("VappMMSSettingPage", VappMMSSettingPage, VfxPage);

void VappMMSSettingPage::onInit()
{
    VfxPage::onInit(); // call base class

	

	VFX_OBJ_CREATE(m_listMenuContentProvider, VMMSSettingGroupListMenuContentProvider, this);
	m_listMenuContentProvider->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);

	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING);
	m_groupList = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_groupList")), VcpGroupListMenu);
	m_groupList->setContentProvider(m_listMenuContentProvider);
	m_groupList->setSize(getSize());
	m_groupList->m_signalItemTapped.connect(this, &VappMMSSettingPage::onTapItem);
	m_groupList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
	m_groupList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE,VFX_TRUE);

	m_groupList->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

	VfxXmlLoader::loadEnd();

	m_setUpdate = 0;

}
void VappMMSSettingPage::onDeinit()
{
	VfxBool needReq = VFX_FALSE;

	
	MMI_TRACE(MMI_INET_TRC_G6_MMS,TRC_VAPP_MMS_SETTING_DEINIT);

	if(m_setUpdate & VAPP_COMPOSER_SETTING_UPDATE)
	{
		needReq = VFX_TRUE;
		MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SETTING_COMPOSE);
		srv_mms_write_nvram_compose_settings();
		m_setUpdate &= ~VAPP_COMPOSER_SETTING_UPDATE;
	}

	if(m_setUpdate & VAPP_SENDING_SETTING_UPDATE)
	{
		needReq = VFX_TRUE;
		MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SETTING_SENDING);
		srv_mms_write_nvram_sending_settings();
		m_setUpdate &= ~VAPP_SENDING_SETTING_UPDATE;
	}

	if(m_setUpdate & VAPP_RETRIEVAL_SETTING_UPDATE)
	{
		needReq = VFX_TRUE;
		MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SETTING_RETRIEVAL);
		srv_mms_write_nvram_retrieval_settings();
		m_setUpdate &= ~VAPP_RETRIEVAL_SETTING_UPDATE;
	}

	if(m_setUpdate & VAPP_OPEN_SETTING_UPDATE)
	{
		MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SETTING_OPEN);
		m_setUpdate &= ~VAPP_OPEN_SETTING_UPDATE;
	}
	
	if(needReq == VFX_TRUE)
	{
		srv_mms_mma_set_settings_req_struct set_setting;
		memset(&set_setting, 0, sizeof(srv_mms_mma_set_settings_req_struct));
		set_setting.user_data = 0;
		set_setting.app_id = MMA_APP_ID_SETTING;
		set_setting.call_back = VappMMSSettingPage::setResponseHandler;
		srv_mms_set_setting((void*)&set_setting);
		MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SETTING_DEINIT);
	}
	
	VfxPage::onDeinit(); // call base class
}
void VappMMSSettingPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	
	
	//return param.rotateTo;
	
}

void VappMMSSettingPage::onSettingRefresh(VcpGroupListMenu *menu, VcpMenuPos pos)
{
	MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SETTING_REFRESH, pos.group, pos.pos);

	switch(pos.group)
	{
	case VAPP_LIST_HEADER_COMPOSE_SETTING:
		m_setUpdate |= VAPP_COMPOSER_SETTING_UPDATE;
		break;
	case VAPP_LIST_HEADER_SENDNG_SETTING:
		m_setUpdate |= VAPP_SENDING_SETTING_UPDATE;
		break;
	case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
		m_setUpdate |= VAPP_RETRIEVAL_SETTING_UPDATE;
		break;
 #ifndef __COSMOS_NO_USER_DRIVE__       
	case VAPP_LIST_HEADER_OPEN_GROUP:
		m_setUpdate |= VAPP_OPEN_SETTING_UPDATE;
		break;
 #endif       
	}
#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__

	if((pos.group == VAPP_LIST_HEADER_SENDNG_SETTING)
		&&( pos.pos == VAPP_LIST_SENDING_DELIVERY_REPORT || pos.pos == VAPP_LIST_SENDING_READ_REPORT)
		)
	{
		return;
		//updating in these cases were giving some fetals, so temp avoid updating
	}
#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
	if((pos.group == VAPP_LIST_HEADER_RETRIEVAL_SETTING)
		&&(
		 0
    #ifdef __MMI_MMS_SETTING_ADVERTISEMENT__
		 || pos.pos == VAPP_LIST_RETRIEVAL_ALLOW_ADVERTISEMENT
    #endif		 	 
    #ifdef __MMI_MMS_SETTING_ANONYMOUS__
		 || pos.pos == VAPP_LIST_RETRIEVAL_ALLOW_ANONYMOUS
    #endif	 
            #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
		 		||  pos.pos == VAPP_LIST_RETRIEVAL_DELIVERY_REPORT 
		 		|| pos.pos == VAPP_LIST_RETRIEVAL_READ_REPORT
            #endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
		 )
		)
	{
		return;
		//updating in these cases were giving some fetals, so temp avoid updating
	}

	m_groupList->updateItem(pos);
}

void VappMMSSettingPage::setResponseHandler(srv_mms_result_enum result, void *rsp_data, void* user_data)
{

}
void VappMMSSettingPage::onTapItem(VcpGroupListMenu *listMenu, VcpMenuPos pos)
{
    switch(pos.group)
    {
        case VAPP_LIST_HEADER_COMPOSE_SETTING:
        {
            switch(pos.pos)
            {
            #ifdef __MMI_MMS_SETTING_COMPOSE_SLIDE__
                case VAPP_LIST_COMPOSE_SLIDE_TIME_SETTING:
                {
                    VappMMSSetSlideTimePage  *mmsSlideTimePage;
                    VFX_OBJ_CREATE(mmsSlideTimePage, VappMMSSetSlideTimePage, getMainScr());
                    mmsSlideTimePage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSlideTimePage);
                }
                break;
            #endif  
            
            #ifdef __MMI_MMS_SETTING_COMPOSE_CREATION__
                case VAPP_LIST_COMPOSE_CREATION_SETTING:
                {
                    VappMMSSetCreationPage  *mmsSetCreationPage;
                    VFX_OBJ_CREATE(mmsSetCreationPage, VappMMSSetCreationPage, getMainScr());
                    mmsSetCreationPage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetCreationPage);
                }
                break;
            #endif
            
            #ifdef __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__
                case VAPP_LIST_COMPOSE_PICTURE_RESIZING_SETTING:
                    VappMMSSetPicResizePage  *mmsSetPicResizePage;
                    VFX_OBJ_CREATE(mmsSetPicResizePage, VappMMSSetPicResizePage, getMainScr());
                    mmsSetPicResizePage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetPicResizePage);
                break;
            #endif
            default :
                break;
            }
        }
        break;
        case VAPP_LIST_HEADER_SENDNG_SETTING:
        {
            switch(pos.pos)
            {
            
            #ifdef __MMI_MMS_SETTING_SENDING_PRIORITY__
                case VAPP_LIST_SENDING_PRIORITY:
                    VappMMSSetSendPrioPage  *mmsSetSendPrioPage;
                    VFX_OBJ_CREATE(mmsSetSendPrioPage, VappMMSSetSendPrioPage, getMainScr());
                    mmsSetSendPrioPage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetSendPrioPage);
                break;
            #endif
            
            #ifdef __MMI_MMS_SETTING_SENDING_VALIDITY__               
                case VAPP_LIST_SENDING_VALIDITY_PERIOD:
                    VappMMSSetSendValidPage  *mmsSetSendValidPage;
                    VFX_OBJ_CREATE(mmsSetSendValidPage, VappMMSSetSendValidPage, getMainScr());
                    mmsSetSendValidPage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetSendValidPage);
                break;
            #endif
            
            #ifdef __MMI_MMS_SETTING_DELIVERY_TIME__                
                case VAPP_LIST_SENDING_DELIVERY_TIME:
                    VappMMSSetSendDeliveryPage  *mmsSetSendDeliveryPage;
                    VFX_OBJ_CREATE(mmsSetSendDeliveryPage, VappMMSSetSendDeliveryPage, getMainScr());
                    mmsSetSendDeliveryPage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetSendDeliveryPage);
                break;
            #endif
                default :
                    break;
            }
        }
        break;
 #if defined(__MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__) || defined(__MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__) 
        case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
            switch(pos.pos)
            {
            
            #ifdef __MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__                
                case VAPP_LIST_RETRIEVAL_HOME_NETWORK:
                    VappMMSSetRetvlHomePage  *mmsSetRetvlHomePage;
                    VFX_OBJ_CREATE(mmsSetRetvlHomePage, VappMMSSetRetvlHomePage, getMainScr());
                    mmsSetRetvlHomePage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetRetvlHomePage);
                break;
            #endif

            #ifdef __MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__                
                case VAPP_LIST_RETRIEVAL_ROAMING_NETWORK:
                    VappMMSSetRetvlRoamPage  *mmsSetRetvlRoamPage;
                    VFX_OBJ_CREATE(mmsSetRetvlRoamPage, VappMMSSetRetvlRoamPage, getMainScr());
                    mmsSetRetvlRoamPage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetRetvlRoamPage);
                break;
            #endif
                default:
                break;
            }
        break;
#endif        
 
        case VAPP_LIST_HEADER_OPEN_GROUP:
            switch(pos.pos)
            {
            
            #ifndef __COSMOS_NO_USER_DRIVE__                   
                case VAPP_LIST_OPEN_DEFAULT_STORAGE:

            #ifdef __USB_IN_NORMAL_MODE__
                if (srv_usb_is_in_mass_storage_mode())
                {
                    if (srv_usb_check_path_exported((WCHAR*) L"root"))
                    {
                        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                        balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE));
                        return;
                    }
                }
            #endif /* __USB_IN_NORMAL_MODE__ */
                    VappMMSSetPrefStPage  *mmsSetPrefStPage;
                    VFX_OBJ_CREATE(mmsSetPrefStPage, VappMMSSetPrefStPage, getMainScr());
                    mmsSetPrefStPage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
                    getMainScr()->pushPage(0, mmsSetPrefStPage);
                break;
                
            #endif/* __COSMOS_NO_USER_DRIVE__ */
           #ifdef __MMI_MMS_SETTING_DATA_ACCOUNT__
                case VAPP_LIST_OPEN_DATA_ACCOUNT:
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
                #endif
                    srv_wap_prof_display_profile_list(
                    SRV_WAP_PROF_SIMID_DEFAULT,
                    SRV_WAP_PROF_APPID_MMS,
                    0, 0, getApp()->getGroupId());
                }
                break;
            #endif
            #ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__ 
                case VAPP_LIST_OPEN_MSG_FILTER:
				        VappMMSSetFilterPage  *mmsSetMsgFilterStPage;
						VFX_OBJ_CREATE(mmsSetMsgFilterStPage, VappMMSSetFilterPage, getMainScr());
						mmsSetMsgFilterStPage->m_signalMMSSettingRefresh.connect(this, &VappMMSSettingPage::onSettingRefresh);
						getMainScr()->pushPage(0, mmsSetMsgFilterStPage);
                    break;
            #endif
                default:
                break;
            }
        break;
   
        default :
        break;
   }
}


/*****************************************************************************
*Class VMMSSettingGroupListMenuContentProvider
****************************************************************************/
/*
* Content provider for Group List on page VappMMSSettingPage
*/

VfxBool VMMSSettingGroupListMenuContentProvider::hasGroupHeader(VfxS32 group) const
{

	if(group == VAPP_LIST_HEADER_OPEN_GROUP)
	{
        return VFX_FALSE;
	}
    else        
    if(group == VAPP_LIST_HEADER_RETRIEVAL_SETTING)
    {

    #if (defined(__MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__) || \
        defined(__MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__) || \
        defined(__MMI_MMS_SETTING_ADVERTISEMENT__) || \
        defined(__MMI_MMS_SETTING_ANONYMOUS__) || \
        defined(__MMI_MMS_REPORT_STATUS_SUPPORT__))
        return VFX_TRUE;
    #else
        return VFX_FALSE;
    #endif
    }
    else if(group == VAPP_LIST_HEADER_SENDNG_SETTING)
    {

    #if (defined(__MMI_MMS_SETTING_SENDING_PRIORITY__) || \
        defined(__MMI_MMS_SETTING_SENDING_VALIDITY__) || \
        defined(__MMI_MMS_SETTING_DELIVERY_TIME__) || \
        defined(__MMI_MMS_REPORT_STATUS_SUPPORT__))
        return VFX_TRUE;
    #else
        return VFX_FALSE;
    #endif  	   
    }
    else if(group == VAPP_LIST_HEADER_COMPOSE_SETTING)
    {

    #if (defined(__MMI_MMS_SETTING_COMPOSE_SLIDE__) || \
        defined(__MMI_MMS_SETTING_COMPOSE_CREATION__) || \
        defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__))
        return VFX_TRUE;
    #else
        return VFX_FALSE;
    #endif  	   
    }     
	else
	{
		return VFX_TRUE;
	}
}

VfxU32 VMMSSettingGroupListMenuContentProvider::getCount(VfxU32 group) const
{		
    switch(group)
    {
   
        case VAPP_LIST_HEADER_OPEN_GROUP:
            return VAPP_LIST_OPEN_MAX;            
        case VAPP_LIST_HEADER_COMPOSE_SETTING:
            return VAPP_LIST_COMPOSE_MAX;
        case VAPP_LIST_HEADER_SENDNG_SETTING:
            return VAPP_LIST_SENDING_MAX;
        case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
            return VAPP_LIST_RETRIEVAL_MAX;
    }
    return 0;
}

VfxBool VMMSSettingGroupListMenuContentProvider::getItemIsHighlightable(
    VcpMenuPos pos) const
{
#if defined(__MMI_MMS_REPORT_STATUS_SUPPORT__) || defined(__MMI_MMS_SETTING_ADVERTISEMENT__) || defined(__MMI_MMS_SETTING_ANONYMOUS__)
    switch(pos.group)
    {

    #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
        case VAPP_LIST_HEADER_SENDNG_SETTING:
            switch(pos.pos)
            {
                case VAPP_LIST_SENDING_DELIVERY_REPORT:
                case VAPP_LIST_SENDING_READ_REPORT:
                    return VFX_FALSE;
                default :
                    return VFX_TRUE;
            }
    #endif /*__MMI_MMS_REPORT_STATUS_SUPPORT__*/               
        case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
        #if defined(__MMI_MMS_REPORT_STATUS_SUPPORT__) || defined(__MMI_MMS_SETTING_ADVERTISEMENT__) || defined(__MMI_MMS_SETTING_ANONYMOUS__)
            switch(pos.pos)
            {
            #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
                case VAPP_LIST_RETRIEVAL_DELIVERY_REPORT:
                case VAPP_LIST_RETRIEVAL_READ_REPORT:
                    return VFX_FALSE;
            #endif /*__MMI_MMS_REPORT_STATUS_SUPPORT__*/                    
            
            #ifdef __MMI_MMS_SETTING_ADVERTISEMENT__
                case VAPP_LIST_RETRIEVAL_ALLOW_ADVERTISEMENT:
                    return VFX_FALSE;
            #endif            
            #ifdef __MMI_MMS_SETTING_ANONYMOUS__
                case VAPP_LIST_RETRIEVAL_ALLOW_ANONYMOUS:
                    return VFX_FALSE;
            #endif
                default :
                    return VFX_TRUE;
            }
        #endif

    }
#endif    
    return VFX_TRUE;
}

VfxBool VMMSSettingGroupListMenuContentProvider::getItemIsDisabled(VcpMenuPos pos) const
{
#ifndef __COSMOS_NO_USER_DRIVE__
    if(pos.group == VAPP_LIST_HEADER_OPEN_GROUP)
    {
    
    #ifdef __MMI_MMS_SETTING_DATA_ACCOUNT__
        if(pos.pos == VAPP_LIST_OPEN_DATA_ACCOUNT)
        {
            if (srv_sim_ctrl_get_num_of_inserted())
            {
                return VFX_FALSE;
            }
            else
            {
                return VFX_TRUE;
            }
        }
    #endif
    }
#endif    
    return VFX_FALSE;
}

VfxBool VMMSSettingGroupListMenuContentProvider::getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        switch(pos.group)
        {
        
            case VAPP_LIST_HEADER_OPEN_GROUP:

            #ifndef __COSMOS_NO_USER_DRIVE__            
                if(pos.pos == VAPP_LIST_OPEN_DEFAULT_STORAGE)
                {

                #ifdef __COSMOS_NO_USER_DRIVE__                  
                    srv_mms_prefer_storage_enum mode = E_PREFER_STORAGE_MODE_CARD;
                #else
                    srv_mms_prefer_storage_enum mode = srv_mms_get_mms_prefer_storage_ex();
                #endif /*__COSMOS_NO_USER_DRIVE__*/
                    switch(mode)
                    {
                        case E_PREFER_STORAGE_MODE_PHONE:
                            text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_PHONE);
                        break;
                        case E_PREFER_STORAGE_MODE_CARD:
                            text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_CARD);
                        break;
                        default:
                        return VFX_FALSE;
                    }

                }
             #endif
                     
             #ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__              
                if(pos.pos == VAPP_LIST_OPEN_MSG_FILTER)
                {

                    U8 filter = srv_mms_get_msg_filter();
                    if((filter&E_MSG_FILTER_PHONE) &&(filter&E_MSG_FILTER_CARD))
                    {     
                    
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_PHONE);
                        VfxWString str ;
                        text += VFX_WSTR("\\");
                        str = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_CARD);
                        text += str;
                    }
                    else if(filter&E_MSG_FILTER_PHONE)
                    {
                        
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_PHONE);
                    }
                    else if(filter&E_MSG_FILTER_CARD)
                    {
                        
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_CARD);
                    }                                  
                }
            #endif
            
            #ifdef __MMI_MMS_SETTING_DATA_ACCOUNT__
                if(pos.pos == VAPP_LIST_OPEN_DATA_ACCOUNT)
                {
                    return VFX_FALSE;
                }
            #endif
            
            break;
            
            case VAPP_LIST_HEADER_COMPOSE_SETTING:
            {
                
#if defined(__MMI_MMS_SETTING_COMPOSE_SLIDE__) || \
    defined(__MMI_MMS_SETTING_COMPOSE_CREATION__) || \
    defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__)

                switch(pos.pos)
                {
                
                #ifdef __MMI_MMS_SETTING_COMPOSE_SLIDE__
                    case VAPP_LIST_COMPOSE_SLIDE_TIME_SETTING:
                    {
                        VfxChar tempBuff[30];								
                        VfxChar tempUCS2Buff[30];	
                        m_composeSet = srv_mms_get_nvram_compose_settings();
                        if(m_composeSet->default_slide_time)
                        {
                            sprintf(tempBuff,"%d ",m_composeSet->default_slide_time);
                            mmi_asc_to_ucs2((char*)tempUCS2Buff,(char*)tempBuff);
                            text = VFX_WSTR_MEM((VfxWChar *)tempUCS2Buff);
                            if(m_composeSet->default_slide_time == 1)
                            {
                                text += VFX_WSTR_RES(STR_ID_VAPP_MMS_SECOND);
                            }
                            else
                            {
                                text += VFX_WSTR_RES(STR_ID_VAPP_MMS_SECONDS);
                            }
                        }
                        else
                        {
                            text = VFX_WSTR_RES(STR_GLOBAL_NONE);				
                        }
                    }
                    break;
                #endif

                #ifdef __MMI_MMS_SETTING_COMPOSE_CREATION__
                    case VAPP_LIST_COMPOSE_CREATION_SETTING:
                        switch(m_composeSet->creation_mode)
                        {
                            case E_CREAT_MODE_RESTRICTED:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_RESTRICTED);
                            break;
                            case E_CREAT_MODE_WARNING:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_WARNING);
                            break;
                            case E_CREAT_MODE_FREE:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_FREE);
                            break;
                        }							
                    break;				
                #endif
                
                #ifdef __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__
                    case VAPP_LIST_COMPOSE_PICTURE_RESIZING_SETTING:
                    {
                        VfxWString temp;
                        m_composeSet = srv_mms_get_nvram_compose_settings();
                        switch(m_composeSet->layout)
                        {
                            case E_PICTURE_RESIZE_10KB:
                                temp = VFX_WSTR("10 ");
                                temp += VFX_WSTR("KB");
                                text = temp;
                            break;									
                            case E_PICTURE_RESIZE_50KB:
                                temp = VFX_WSTR("50 ");
                                temp += VFX_WSTR("KB");
                                text = temp;
                            break;	
                            case E_PICTURE_RESIZE_100KB:
                                temp = VFX_WSTR("100 ");
                                temp += VFX_WSTR("KB");
                                text = temp;
                            break;	
                            case E_PICTURE_RESIZE_OFF:
                                text = VFX_WSTR_RES(STR_GLOBAL_OFF);
                            break;
                            default:
                                text = VFX_WSTR("Wrong");
                        }

                    }
                    break;
                #endif
                    default:
                    return VFX_FALSE;
                }
            break;
        #else
            return VFX_FALSE;
        #endif
            }
            
            case VAPP_LIST_HEADER_SENDNG_SETTING:
            {
                m_sendSet = srv_mms_get_nvram_sending_settings();
                switch(pos.pos)
                {
                
                #ifdef __MMI_MMS_SETTING_SENDING_PRIORITY__
                    case VAPP_LIST_SENDING_PRIORITY:
                        switch(m_sendSet->priority)
                        {			
                            case E_PRIORITY_LOW:
                                text = VFX_WSTR_RES(STR_GLOBAL_LOW);
                            break;
                            case E_PRIORITY_NORMAL:
                                text = VFX_WSTR_RES(STR_GLOBAL_NORMAL);
                            break;
                            case E_PRIORITY_HIGH:
                                text = VFX_WSTR_RES(STR_GLOBAL_HIGH);
                            break;
                            default:
                                text = VFX_WSTR("wrong");
                        }
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_SENDING_VALIDITY__                
                    case VAPP_LIST_SENDING_VALIDITY_PERIOD:
                        switch(m_sendSet->validity_period)
                        {
                            case E_VALIDITY_PERIOD_1HR:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_1_HR);
                            break;
                            case E_VALIDITY_PERIOD_6HRS:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_6_HRS);
                            break;
                            case E_VALIDITY_PERIOD_12HRS:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_12_HRS);
                            break;
                            case E_VALIDITY_PERIOD_1DAY:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_1_DAY);
                            break;
                            case E_VALIDITY_PERIOD_1WEEK:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_1_WEEK);
                            break;
                            case E_VALIDITY_PERIOD_MAX:
                                text = VFX_WSTR_RES(STR_GLOBAL_MAXIMUM);
                            break;
                            default:
                                text = VFX_WSTR_NULL;
                            break;
                        }
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_DELIVERY_TIME__                
                    case VAPP_LIST_SENDING_DELIVERY_TIME:
                        switch(m_sendSet->delivery_time)
                        {
                            case E_IMMEDIATE:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_IMMEDIATE);
                            break;
                            case E_1_HR:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_1_HR);
                            break;
                            case E_2_HR:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_2_HR);
                            break;
                            case E_12_HRS:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_12_HRS);
                            break;
                            case E_24_HRS:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELV_24_HRS);
                            break;
                            default:
                                text = VFX_WSTR_NULL;
                            break;
                        }
                        break;
                    #endif
                    default:
                        return VFX_FALSE;
                }
            }
            break;

#if defined(__MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__) || defined(__MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__)            
            case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
            {
                m_retvlSet = srv_mms_get_nvram_retrieval_settings();

                switch(pos.pos)
                {
                
                #ifdef __MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__                
                    case VAPP_LIST_RETRIEVAL_HOME_NETWORK:
                        switch (m_retvlSet->home_network)
                        {
                            case E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_IMMEDIATE);
                            break;
                            case E_HOME_NOETWORK_RETRIEVAL_DEFFERED:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_DEFFERED);
                            break;
                            case E_HOME_NOETWORK_RETRIEVAL_RESTRICTED:
                                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_REJECTIVE);
                            break;
                            default:
                                text = VFX_WSTR_NULL;
                            break;
                        }
                        break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__                
                        case VAPP_LIST_RETRIEVAL_ROAMING_NETWORK:
                            switch(m_retvlSet->roaming)
                            {
                            #if defined(__MMI_MMS_2_RETRIVAL_MODE_SETTING__)
                                case 0:
                                    text = VFX_WSTR_RES(STR_GLOBAL_NO);
                                break;
                                case 1:
                                    text = VFX_WSTR_RES(STR_GLOBAL_YES);
                                break;
                            #else 
                                case E_ROAMING_RETRIEVAL_AS_HOME:
                                    text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_AS_HOME);
                                break;
                                case E_ROAMING_RETRIEVAL_IMMEDAITE:
                                    text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_IMMEDIATE);
                                break;
                                case E_ROAMING_RETRIEVAL_DEFFERED:
                                    text = VFX_WSTR_RES(STR_ID_VAPP_MMS_DEFFERED);
                                break;
                                case E_ROAMING_RETRIEVAL_RESTRICTED:
                                    text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_REJECTIVE);
                                break;
                            #endif /*__MMI_MMS_2_RETRIVAL_MODE_SETTING__*/
                                default:
                                    text = VFX_WSTR_NULL;
                                break;
                            }
                        break;
                #endif
                        default:
                        return VFX_FALSE;
                }
            }
#endif     
        }			
    color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
    {
        switch(pos.group)
        {
            case VAPP_LIST_HEADER_COMPOSE_SETTING:
                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MESSAGE_SETTINGS_COMPOSE);	
            break;
            case VAPP_LIST_HEADER_SENDNG_SETTING:
                text = VFX_WSTR_RES(STR_GLOBAL_SENDING);	
            break;
            case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
                text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MESSAGE_SETTINGS_RETRIEVAL);	
            break;
            default: 
                text = VFX_WSTR("Header");
        }			
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
        switch(pos.group)
        {

            case VAPP_LIST_HEADER_OPEN_GROUP:
                switch(pos.pos)
                {
                #ifndef __COSMOS_NO_USER_DRIVE__
                    case VAPP_LIST_OPEN_DEFAULT_STORAGE:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE);
                    break;
                #endif    
                #ifdef __MMI_MMS_SETTING_DATA_ACCOUNT__
                    case VAPP_LIST_OPEN_DATA_ACCOUNT:
                        text = VFX_WSTR_RES(STR_GLOBAL_DATA_CONN_SETTING);
                    break;
                #endif                    
                #ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__                
                    case VAPP_LIST_OPEN_MSG_FILTER:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MESSAGE_FILTER);
                        break;
                #endif
                    default:
                        text = VFX_WSTR("wrong");
                }
            break;
 
            case VAPP_LIST_HEADER_COMPOSE_SETTING:
            {
                switch(pos.pos)
                {
                
                #ifdef __MMI_MMS_SETTING_COMPOSE_SLIDE__
                    case VAPP_LIST_COMPOSE_SLIDE_TIME_SETTING:							
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DEFAULT_SLIDE_TIMING);
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_COMPOSE_CREATION__
                    case VAPP_LIST_COMPOSE_CREATION_SETTING:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_CREATION_MODES);
                    break;				
                #endif
                
                #ifdef __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__
                    case VAPP_LIST_COMPOSE_PICTURE_RESIZING_SETTING:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_IMAGE_RESIZE);
                    break;
                #endif
                    default:
                        text = VFX_WSTR("wrong");
                }
            }			
            break;
            case VAPP_LIST_HEADER_SENDNG_SETTING:
                switch(pos.pos)
                {

                #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
                    case VAPP_LIST_SENDING_DELIVERY_REPORT:						
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_DELIVERY_REPORT);
                    break;
                    case VAPP_LIST_SENDING_READ_REPORT:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_READ_REPORT);						
                    break;
                #endif  /*__MMI_MMS_REPORT_STATUS_SUPPORT__*/                      
                #ifdef __MMI_MMS_SETTING_SENDING_PRIORITY__                
                    case VAPP_LIST_SENDING_PRIORITY:							
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_PRIORITY);
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_SENDING_VALIDITY__                
                    case VAPP_LIST_SENDING_VALIDITY_PERIOD:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_VALIDITY_PERIOD);
                    break;				
                #endif
                
                #ifdef __MMI_MMS_SETTING_DELIVERY_TIME__                
                    case VAPP_LIST_SENDING_DELIVERY_TIME:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_DELIVERY_TIME);
                    break;
                #endif
                    default:
                        text = VFX_WSTR("wrong");
                }
            break;

#if defined(__MMI_MMS_REPORT_STATUS_SUPPORT__) || \
    defined(__MMI_MMS_SETTING_ANONYMOUS__) || \
    defined(__MMI_MMS_SETTING_ADVERTISEMENT__) || \
    defined(__MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__) || \
    defined(__MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__)

            case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
                switch(pos.pos)
                {
                #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__					
                    case VAPP_LIST_RETRIEVAL_DELIVERY_REPORT:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_RET_DEILIVERY_REPORT);
                    break;
                    case VAPP_LIST_RETRIEVAL_READ_REPORT:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_RET_READ_REPORT);
                    break;
                #endif /*__MMI_MMS_REPORT_STATUS_SUPPORT__*/                       
                
                #ifdef __MMI_MMS_SETTING_ANONYMOUS__
                    case VAPP_LIST_RETRIEVAL_ALLOW_ANONYMOUS:						
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_ANNONYMOUS);
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_ADVERTISEMENT__
                    case VAPP_LIST_RETRIEVAL_ALLOW_ADVERTISEMENT:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_ADVERTISMENT);
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__                
                    case VAPP_LIST_RETRIEVAL_HOME_NETWORK:							
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_HOME_NETWORK);
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__                
                    case VAPP_LIST_RETRIEVAL_ROAMING_NETWORK:
                        text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SETTINGS_ROAMING);
                    break;				
                #endif
                    default:
                        text = VFX_WSTR("wrong");
                }
                break;
#endif                
        }
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    }
    return VFX_TRUE;
}


VfxBool VMMSSettingGroupListMenuContentProvider::getItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
{

//#ifdef __COSMOS_NO_USER_DRIVE__
//    if(VAPP_LIST_OPEN_DEFAULT_STORAGE == pos.pos)
//    {
//        return VFX_TRUE;
//    }
//#endif/*__COSMOS_NO_USER_DRIVE__*/
    if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

    
void VMMSSettingGroupListMenuContentProvider::closeItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType, 
        VfxImageSrc Image               
        ) {}

VcpListMenuItemStateEnum VMMSSettingGroupListMenuContentProvider::getItemState(
        VcpMenuPos pos  
        ) const 
{ 
    if (m_selectedIndex == pos)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

VcpListMenuCellClientBaseFrame *VMMSSettingGroupListMenuContentProvider::getItemCustomContentFrame(
        VcpMenuPos pos,
        VfxFrame *parentFrame
        )
{


        return NULL;

}



VcpListMenuCellBaseControl *VMMSSettingGroupListMenuContentProvider::getItemCustomControl(VcpMenuPos pos, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame)
{
    VappMMSSetSwitchControl* m_switchControl = NULL;

    if(location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
    {
        switch(pos.group)
        {
            case VAPP_LIST_HEADER_SENDNG_SETTING:
            {
            #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
                srv_mms_nvram_sending_settings_struct *sendSetting = srv_mms_get_nvram_sending_settings();
                switch(pos.pos)
                {
                    case VAPP_LIST_SENDING_DELIVERY_REPORT:
                    {
                        VFX_OBJ_CREATE(m_switchControl, VappMMSSetSwitchControl, parentFrame);
                        m_switchControl->setMMSChecked(sendSetting->delivery_report);
                        m_switchControl->m_signalSwitchChanged.connect(this, &VMMSSettingGroupListMenuContentProvider::sendingSetDeliverySwitchSignal);
                    }
                    break;
                    case VAPP_LIST_SENDING_READ_REPORT:
                    {
                        VFX_OBJ_CREATE(m_switchControl, VappMMSSetSwitchControl, parentFrame);
                        m_switchControl->setMMSChecked(sendSetting->read_report);
                        m_switchControl->m_signalSwitchChanged.connect(this, &VMMSSettingGroupListMenuContentProvider::sendingSetReadSwitchSignal);
                    }
                    break;
                    default:
                    break;
                }
            #endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/                    
            }
            break;
            
#if defined(__MMI_MMS_REPORT_STATUS_SUPPORT__) || \
    defined(__MMI_MMS_SETTING_ANONYMOUS__) || \
    defined(__MMI_MMS_SETTING_ADVERTISEMENT__)
                
            case VAPP_LIST_HEADER_RETRIEVAL_SETTING:
            {
                srv_mms_nvram_retrieval_settings_struct *retSetting = srv_mms_get_nvram_retrieval_settings();
                switch(pos.pos)
                {
                #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
                    case VAPP_LIST_RETRIEVAL_DELIVERY_REPORT:
                    {
                        VFX_OBJ_CREATE(m_switchControl, VappMMSSetSwitchControl, parentFrame);
                        m_switchControl->setMMSChecked(retSetting->delivery_report);
                        m_switchControl->m_signalSwitchChanged.connect(this, &VMMSSettingGroupListMenuContentProvider::retrievalSetDeliverySwitchSignal);
                    }
                    break;
                    case VAPP_LIST_RETRIEVAL_READ_REPORT:
                    {
                        VFX_OBJ_CREATE(m_switchControl, VappMMSSetSwitchControl, parentFrame);
                        m_switchControl->setMMSChecked(retSetting->read_report);
                        m_switchControl->m_signalSwitchChanged.connect(this, &VMMSSettingGroupListMenuContentProvider::retrievalSetReadSwitchSignal);
                    }
                    break;
                #endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/                    
                
                #ifdef __MMI_MMS_SETTING_ADVERTISEMENT__
                    case VAPP_LIST_RETRIEVAL_ALLOW_ADVERTISEMENT:
                    {
                        VFX_OBJ_CREATE(m_switchControl, VappMMSSetSwitchControl, parentFrame);
                        m_switchControl->setMMSChecked(!retSetting->advertisement_filter);
                        m_switchControl->m_signalSwitchChanged.connect(this, &VMMSSettingGroupListMenuContentProvider::retrievalSetAdvtSwitchSignal);
                    }
                    break;
                #endif
                
                #ifdef __MMI_MMS_SETTING_ANONYMOUS__
                    case VAPP_LIST_RETRIEVAL_ALLOW_ANONYMOUS:
                    {
                        VFX_OBJ_CREATE(m_switchControl, VappMMSSetSwitchControl, parentFrame);
                        m_switchControl->setMMSChecked(!retSetting->anonymous_filter);
                        m_switchControl->m_signalSwitchChanged.connect(this, &VMMSSettingGroupListMenuContentProvider::retrievalSetAnonmsSwitchSignal);
                    }
                    break;
                #endif
                    default:
                    break;
                }

            }
            break;
#endif
            default:
            break;
        }
    }

    #if 0
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
    #elif defined(__MMI_MAINLCD_480X800__)
/* under construction !*/
    #elif defined(__MMI_MAINLCD_240X400__)
/* under construction !*/
    #elif defined(__MMI_MAINLCD_240X320__)
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
    #endif
    return m_switchControl;

}

#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
void VMMSSettingGroupListMenuContentProvider::sendingSetDeliverySwitchSignal(VfxObject *sw, VfxBool isChecked)
{
	srv_mms_nvram_sending_settings_struct *sendSetting = srv_mms_get_nvram_sending_settings();
	sendSetting->delivery_report =  isChecked;
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_SENDNG_SETTING,VAPP_LIST_SENDING_DELIVERY_REPORT));
}
void VMMSSettingGroupListMenuContentProvider::sendingSetReadSwitchSignal(VfxObject *sw, VfxBool isChecked)
{
	srv_mms_nvram_sending_settings_struct *sendSetting = srv_mms_get_nvram_sending_settings();
	sendSetting->read_report = isChecked;
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_SENDNG_SETTING,VAPP_LIST_SENDING_READ_REPORT));
}
void VMMSSettingGroupListMenuContentProvider::retrievalSetDeliverySwitchSignal(VfxObject *sw, VfxBool isChecked)
{
	srv_mms_nvram_retrieval_settings_struct *retSetting = srv_mms_get_nvram_retrieval_settings();
	retSetting->delivery_report = isChecked;
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_RETRIEVAL_SETTING,VAPP_LIST_RETRIEVAL_DELIVERY_REPORT));

}

void VMMSSettingGroupListMenuContentProvider::retrievalSetReadSwitchSignal(VfxObject *sw, VfxBool isChecked)
{
	srv_mms_nvram_retrieval_settings_struct *retSetting = srv_mms_get_nvram_retrieval_settings();
	retSetting->read_report = isChecked;
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_RETRIEVAL_SETTING,VAPP_LIST_RETRIEVAL_READ_REPORT));

}

#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
#ifdef __MMI_MMS_SETTING_ADVERTISEMENT__
void VMMSSettingGroupListMenuContentProvider::retrievalSetAdvtSwitchSignal(VfxObject *sw, VfxBool isChecked)
{
	srv_mms_nvram_retrieval_settings_struct *retSetting = srv_mms_get_nvram_retrieval_settings();
	retSetting->advertisement_filter = !isChecked;
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_RETRIEVAL_SETTING,VAPP_LIST_RETRIEVAL_ALLOW_ADVERTISEMENT));
}
#endif
#ifdef __MMI_MMS_SETTING_ANONYMOUS__
void VMMSSettingGroupListMenuContentProvider::retrievalSetAnonmsSwitchSignal(VfxObject *sw, VfxBool isChecked)
{
	srv_mms_nvram_retrieval_settings_struct *retSetting = srv_mms_get_nvram_retrieval_settings();
	retSetting->anonymous_filter = !isChecked;
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_RETRIEVAL_SETTING,VAPP_LIST_RETRIEVAL_ALLOW_ANONYMOUS));
}
#endif
/*****************************************************************************
*Class VMMSSettingListMenuCustomContentFrame
****************************************************************************/
/*
* This class provide custom frame to list menu.
*/

void VMMSSettingListMenuCustomContentFrame::onCreateElements()
{
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);

    m_textFrame->setString(VFX_WSTR("This is a custom frame"));

    m_textFrame->setColor(VFX_COLOR_BLACK);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textFrame->setAutoAnimate(VFX_TRUE);
}

    
void VMMSSettingListMenuCustomContentFrame::onLayoutElements()
{
    m_textFrame->setRect(VfxRect(3, 
                                 getRect().getMidY() - m_textFrame->getRect().getHeight() / 2,
                                 getRect().getWidth() - 3 - 3,
                                 m_textFrame->getRect().getHeight()));

    m_textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE);
}




/*****************************************************************************
*Class VappMMSSetPrefStPage
****************************************************************************/
/*
* This class implement preffered storage setting
*/
#ifndef __COSMOS_NO_USER_DRIVE__ 				  

VFX_IMPLEMENT_CLASS("VappMMSSetPrefStPage", VappMMSSetPrefStPage, VfxPage);

void VappMMSSetPrefStPage::onInit()
{
    VfxPage::onInit(); // call base class


	/*Create group list  */

	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_PREF_STORAGE);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);		
	m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
	m_menu->setSize(getSize());
	m_menu->setContentProvider(this);
	m_menu->updateItem(0);
	m_menu->m_signalItemTapped.connect(this, &VappMMSSetPrefStPage::onTapItem);
    m_menu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE);
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
			mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMMSSetPrefStPage::memoryCardPlugOut, this);
			mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappMMSSetPrefStPage::memoryCardPlugIn, this);
        #ifdef __MMI_USB_SUPPORT__
            mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &VappMMSSetPrefStPage::usbMassStorageHdlr, this);
        #endif/*__MMI_USB_SUPPORT__*/

        #endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/

	VfxXmlLoader::loadEnd();

	
}

void VappMMSSetPrefStPage::onDeinit(void)
{
	VfxPage::onDeinit();
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
			mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMMSSetPrefStPage::memoryCardPlugOut, this);
			mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappMMSSetPrefStPage::memoryCardPlugIn, this);
        #ifdef __MMI_USB_SUPPORT__
            mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &VappMMSSetPrefStPage::usbMassStorageHdlr, this);
        #endif/*__MMI_USB_SUPPORT__*/
        #endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
}
mmi_ret VappMMSSetPrefStPage::memoryCardPlugOut(mmi_event_struct *param)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	VappMMSSetPrefStPage *myData = (VappMMSSetPrefStPage *)param->user_data;
	if(myData->isValid() && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetPrefStPage)) )
	{
    	U8 i = 0;
    	U8 drive_counter = 0;
    	srv_fmgr_notification_dev_plug_event_struct *plug_in_info;
	    switch(param->evt_id)
    	{
    		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    			
    			plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)param;

    			for (i = 0; i < plug_in_info->count; i++)
    			{
    				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
    				{
    					drive_counter++;
    				}
    			}
    			if(drive_counter)
    			{
    				myData->m_menu->updateItem(VAPP_LIST_SETTING_PREF_MEMORY_CARD);
    			}
    			
    			break;
    		default:
    			break;
    	}
	}
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
	return MMI_RET_OK;
	
}

mmi_ret VappMMSSetPrefStPage::memoryCardPlugIn(mmi_event_struct *param)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	VappMMSSetPrefStPage *myData = (VappMMSSetPrefStPage *)param->user_data;
	if(myData->isValid() && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetPrefStPage)) )
	{
		U8 i = 0;
		U8 drive_counter = 0;
		srv_fmgr_notification_dev_plug_event_struct *plug_in_info;
		switch(param->evt_id)
		{
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
				
				plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)param;

				for (i = 0; i < plug_in_info->count; i++)
				{
					if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
					{
						drive_counter++;
					}
				}
				if(drive_counter)
				{
					myData->m_menu->updateItem(VAPP_LIST_SETTING_PREF_MEMORY_CARD);
				}
				break;
			default:
				break;
		}
	}
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
	return MMI_RET_OK;
	
}

mmi_ret VappMMSSetPrefStPage::usbMassStorageHdlr(mmi_event_struct *param)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	VappMMSSetPrefStPage *myData = (VappMMSSetPrefStPage *)param->user_data;
	if((myData != NULL) && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetPrefStPage)) )
	{
		VfxMainScr *scr = myData->getMainScr();	
		VfxId id = scr->getTopPageId();

		while(id != 0)
		{
			if((scr->getPage(id))->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetPrefStPage)) && id)
			{
				scr->closePage(id);
			}
			id = scr->getPrevPageId(id);
		}
	
	}
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
	return MMI_RET_OK;
	
}

void VappMMSSetPrefStPage::onQueryRotateEx( VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

VfxU32 VappMMSSetPrefStPage::getCount() const
{
	return VAPP_LIST_SETTING_PREF_MAX;
}

VfxBool VappMMSSetPrefStPage::getItemIsDisabled(
        VfxU32 index       
        ) const
{
	VfxU8 m_prefStorage = srv_mms_get_mms_prefer_storage_ex();

	if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
	{
		if(index == VAPP_LIST_SETTING_PREF_MEMORY_CARD)
		{
			return VFX_TRUE;
		}
	}
	
	return VFX_FALSE;
}

void VappMMSSetPrefStPage::setMenu(VcpListMenu *menu)
{
	m_menu = menu;
	m_selectedIndex = 0;
	m_prefStorage = srv_mms_get_mms_prefer_storage_ex();


	switch(m_prefStorage)
	{
        case E_PREFER_STORAGE_MODE_PHONE:
            m_selectedIndex = VAPP_LIST_SETTING_PREF_PHONE;
			break;
        case E_PREFER_STORAGE_MODE_CARD:
            m_selectedIndex = VAPP_LIST_SETTING_PREF_MEMORY_CARD;
			break;
		default:
			break;
	}

}

VcpListMenuItemStateEnum VappMMSSetPrefStPage::getItemState(
        VfxU32 index   
        ) const
{
	if(index == m_selectedIndex)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetPrefStPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
   
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		
		switch(index)
		{			
			case VAPP_LIST_SETTING_PREF_PHONE:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_PHONE);
				break;									
			case VAPP_LIST_SETTING_PREF_MEMORY_CARD:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_CARD);
				break;	
			default:
				text = VFX_WSTR("Wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
	
}
void VappMMSSetPrefStPage::updateItem(VfxU32 index)
{
	m_menu->setItemState(m_selectedIndex, VCP_LIST_MENU_ITEM_STATE_SELECTED);
}

void VappMMSSetPrefStPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{
    srv_mms_prefer_storage_enum mode = E_PREFER_STORAGE_MODE_PHONE;
    m_selectedIndex = index;		
    switch(m_selectedIndex)
    {			
        case VAPP_LIST_SETTING_PREF_PHONE:
            mode = E_PREFER_STORAGE_MODE_PHONE;
        break;									
        case VAPP_LIST_SETTING_PREF_MEMORY_CARD:
            if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
            {
                VcpConfirmPopup *m_confirmPopup;
                VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
                VfxWString txt(STR_ID_VAPP_MMS_MMS_NO_MEM_CARD);
                m_confirmPopup->setText(txt);
                m_confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
                m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                //m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsUseDetailHandler: nClickOk);
                //m_confirmPopup->m_signalPopupState.connect(this, &VappMmsUseDetailHandler: nEmailTruncated);
                m_confirmPopup->show(VFX_TRUE);
                return;
            }
            mode = E_PREFER_STORAGE_MODE_CARD;
        break;	
        default:
            break;
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    srv_mms_set_prefered_storage((U8) mode, MMI_TRUE);
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/

    m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_OPEN_GROUP,VAPP_LIST_OPEN_DEFAULT_STORAGE));

#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__ 
	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_OPEN_GROUP,VAPP_LIST_OPEN_MSG_FILTER));
    srv_um_refresh_ind_struct *refresh_ind;
    refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
    refresh_ind->msg_type = SRV_UM_MSG_SMS;
    refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
    refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
    mmi_frm_send_ilm((oslModuleType)MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*)refresh_ind,NULL);

#endif

    getMainScr()->popPage();
}
#endif
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__	


VFX_IMPLEMENT_CLASS("VappMMSSetFilterPage", VappMMSSetFilterPage, VfxPage);

void VappMMSSetFilterPage::onInit()
{
    VfxPage::onInit(); // call base class


	/*Create group list  */

	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_MSG_FILTER);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);		
	m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_menu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);
	m_menu->setSize(getSize());
	m_menu->setContentProvider(this);
	//m_menu->updateItem(0);
	//m_menu->m_signalItemTapped.connect(this, &VappMMSSetFilterPage::onTapItem);
	m_menu->m_signalItemSelectionStateChanged.connect(this,&VappMMSSetFilterPage::onSelectChangeed);
    m_menu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE);
    
	VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    
	m_toolBar->m_signalButtonTap.connect(this, &VappMMSSetFilterPage::onButtonClicked);
    m_toolBar->addItem(BUTTON_OK, VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);  
    m_toolBar->addItem(BUTTON_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);  
	setBottomBar(m_toolBar);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
			mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMMSSetFilterPage::memoryCardPlugOut, this);
			mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappMMSSetFilterPage::memoryCardPlugIn, this);
#ifdef __MMI_USB_SUPPORT__
            mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &VappMMSSetFilterPage::usbMassStorageHdlr, this);
#endif

#endif

	VfxXmlLoader::loadEnd();

	
}

void VappMMSSetFilterPage::onDeinit(void)
{
    
	VfxPage::onDeinit();
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
			mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMMSSetFilterPage::memoryCardPlugOut, this);
			mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappMMSSetFilterPage::memoryCardPlugIn, this);
#ifdef __MMI_USB_SUPPORT__
            mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &VappMMSSetFilterPage::usbMassStorageHdlr, this);
#endif
#endif
}
void VappMMSSetFilterPage::onButtonClicked(VfxObject *sender, VfxId bottom_id)
{
    
    U8 filter = srv_mms_get_msg_filter();
    if(bottom_id == BUTTON_OK)
    {      
        if(m_phone_state == FILTER_SELECT)
        {
            filter = filter |  E_MSG_FILTER_PHONE;
            srv_mms_set_msg_filter(filter);
        }
        else if(m_phone_state == FILTER_CANCEL)
        {          
            filter = filter & (~E_MSG_FILTER_PHONE);
            srv_mms_set_msg_filter(filter);
        }
        if(m_memory_card_state == FILTER_SELECT)
        {
            filter = filter |  E_MSG_FILTER_CARD;
            srv_mms_set_msg_filter(filter);
        }
        else if(m_memory_card_state == FILTER_CANCEL)
        {          
            filter = filter & (~E_MSG_FILTER_CARD);
            srv_mms_set_msg_filter(filter);
        }
        m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_OPEN_GROUP,VAPP_LIST_OPEN_MSG_FILTER));
        //m_menu->updateItem(index);
        srv_um_refresh_ind_struct *refresh_ind;
        refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
        refresh_ind->msg_type = SRV_UM_MSG_SMS;
        refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
        refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
        mmi_frm_send_ilm((oslModuleType)MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*)refresh_ind,NULL);
    }   
    getMainScr()->popPage();
}


mmi_ret VappMMSSetFilterPage::memoryCardPlugOut(mmi_event_struct *param)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	VappMMSSetFilterPage *myData = (VappMMSSetFilterPage *)param->user_data;
	if(myData->isValid() && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetFilterPage)) )
	{
    	switch(param->evt_id)
    	{
    		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:		
    			myData->m_menu->updateItem(VAPP_LIST_SETTING_FILTER_MEMORY_CARD);		
    			break;
    		default:
    			break;
    	}
	}
#endif
	return MMI_RET_OK;

}

mmi_ret VappMMSSetFilterPage::memoryCardPlugIn(mmi_event_struct *param)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	VappMMSSetFilterPage *myData = (VappMMSSetFilterPage *)param->user_data;
	if(myData->isValid() && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetFilterPage)) )
	{
		switch(param->evt_id)
		{
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
					myData->m_menu->updateItem(VAPP_LIST_SETTING_FILTER_MEMORY_CARD);
				break;
			default:
				break;
		}
	}
#endif
	return MMI_RET_OK;
	
}
mmi_ret VappMMSSetFilterPage::usbMassStorageHdlr(mmi_event_struct *param)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	VappMMSSetFilterPage *myData = (VappMMSSetFilterPage *)param->user_data;
	if((myData != NULL) && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetFilterPage)) )
	{
		VfxMainScr *scr = myData->getMainScr();	
		VfxId id = scr->getTopPageId();

		while(id != 0)
		{
			if((scr->getPage(id))->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSSetFilterPage)) && id)
			{
				scr->closePage(id);
			}
			id = scr->getPrevPageId(id);
		}
	
	}
#endif
	return MMI_RET_OK;
	
}

void VappMMSSetFilterPage::onQueryRotateEx( VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

VfxU32 VappMMSSetFilterPage::getCount() const
{
	return VAPP_LIST_SETTING_FILTER_MAX;
}

VfxBool VappMMSSetFilterPage::getItemIsDisabled(
        VfxU32 index       
        ) const
{
    srv_mms_prefer_storage_enum m_prefStorage = srv_mms_get_mms_prefer_storage_ex();
    if((index == VAPP_LIST_SETTING_FILTER_PHONE) && (m_prefStorage == E_PREFER_STORAGE_MODE_PHONE))  
    {
        return VFX_TRUE;
    }
    else if((index == VAPP_LIST_SETTING_FILTER_MEMORY_CARD) && 
            ((m_prefStorage == E_PREFER_STORAGE_MODE_CARD) || (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)))
	{
        return VFX_TRUE;
	}
	return VFX_FALSE;
}

void VappMMSSetFilterPage::setMenu(VcpListMenu *menu)
{
	/*m_menu = menu;
	m_selectedIndex = 0;
	m_prefStorage = srv_mms_get_mms_prefer_storage_ex();


	switch(m_prefStorage)
	{
        case E_PREFER_STORAGE_MODE_PHONE:
            m_selectedIndex = VAPP_LIST_SETTING_PREF_PHONE;
			break;
        case E_PREFER_STORAGE_MODE_CARD:
            m_selectedIndex = VAPP_LIST_SETTING_PREF_MEMORY_CARD;
			break;
		default:
			break;
	}*/

}

VcpListMenuItemStateEnum VappMMSSetFilterPage::getItemState(
        VfxU32 index   
        ) const
{

    U8 filter = srv_mms_get_msg_filter();
     if((filter&E_MSG_FILTER_PHONE) && (index == VAPP_LIST_SETTING_FILTER_PHONE))
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else if((index == VAPP_LIST_SETTING_FILTER_MEMORY_CARD) && (filter&E_MSG_FILTER_CARD))
    {
       
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

 

VfxBool VappMMSSetFilterPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{

	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		
		switch(index)
		{			
			case VAPP_LIST_SETTING_FILTER_PHONE:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_PHONE);
				break;									
			case VAPP_LIST_SETTING_FILTER_MEMORY_CARD:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_MMS_PREFER_STORAGE_CARD);
				break;	
			default:
				text = VFX_WSTR("Wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	return VFX_FALSE;
	
}
/*void VappMMSSetFilterPage::updateItem(VfxU32 index)
{
    //set select state and enable state
	m_menu->updateItem();
	
}*/
void VappMMSSetFilterPage::onSelectChangeed(  VcpListMenu * menu, 
        								            VfxU32 index,                     
    									            VcpListMenuItemStateEnum  satte  )
{
    
    switch(index)
    {
        case VAPP_LIST_SETTING_FILTER_PHONE:
            if(satte == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            {
                m_phone_state = FILTER_SELECT;
            }
            else
            {          
                m_phone_state = FILTER_CANCEL;
            }
            break;
        case VAPP_LIST_SETTING_FILTER_MEMORY_CARD:
            if(satte == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            {
                m_memory_card_state = FILTER_SELECT;
            }
            else
            {          
                m_memory_card_state = FILTER_CANCEL;
            }

            break;
        default:
            break;
    }       
}

/*void VappMMSSetFilterPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{
	srv_mms_prefer_storage_enum mode = E_PREFER_STORAGE_MODE_PHONE;
    m_selectedIndex = index;		
	switch(m_selectedIndex)
	{			
			case VAPP_LIST_SETTING_PREF_PHONE:
				mode = E_PREFER_STORAGE_MODE_PHONE;
				break;									
			case VAPP_LIST_SETTING_PREF_MEMORY_CARD:
				  if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
					{
								VcpConfirmPopup *m_confirmPopup;
								VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
								VfxWString txt(STR_ID_VAPP_MMS_MMS_NO_MEM_CARD);
								m_confirmPopup->setText(txt);
								m_confirmPopup->setInfoType(VCP_POPUP_TYPE_INFO);
								m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
								//m_confirmPopup->m_signalButtonClicked.connect(this, &VappMmsUseDetailHandler: nClickOk);
								//m_confirmPopup->m_signalPopupState.connect(this, &VappMmsUseDetailHandler: nEmailTruncated);
								m_confirmPopup->show(VFX_TRUE);
						return;
					}
				mode = E_PREFER_STORAGE_MODE_CARD;
				break;	
		default:
			break;
	}
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    srv_mms_set_prefered_storage((U8) mode, MMI_TRUE);
#endif

	m_signalMMSSettingRefresh.emit(NULL,VcpMenuPos(VAPP_LIST_HEADER_OPEN_GROUP,VAPP_LIST_OPEN_DEFAULT_STORAGE));

	getMainScr()->popPage();
}*/
#endif

/*****************************************************************************
*Class VappMMSSetDataActPage
****************************************************************************/
/*
* This class implement Data Account
*/

VFX_IMPLEMENT_CLASS("VappMMSSetDataActPage", VappMMSSetDataActPage, VfxPage);

void VappMMSSetDataActPage::onInit()
{
    VfxPage::onInit(); // call base class


	/*Create list  */

	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_SETTING_DATA_ACCOUNT);
	m_menu = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_menu")), VcpListMenu);		
	m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE,VFX_TRUE);
	m_menu->setContentProvider(this);
	m_menu->m_signalItemTapped.connect(this, &VappMMSSetDataActPage::onTapItem);
    m_menu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE);
	VfxXmlLoader::loadEnd();

	
}

void VappMMSSetDataActPage::onQueryRotateEx( VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}

VfxU32 VappMMSSetDataActPage::getCount() const
{
	return VAPP_LIST_SETTING_DATA_ACCOUNT_MAX;
}

void VappMMSSetDataActPage::setMenu(VcpListMenu *menu)
{


}
VfxBool VappMMSSetDataActPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
#if(MMI_MAX_SIM_NUM >= 2) 
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
	
		switch(index)
		{			
			case VAPP_LIST_SETTING_DATA_ACCOUNT_SIM1:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SIM1);
				break;									
			case VAPP_LIST_SETTING_DATA_ACCOUNT_SIM2:
				text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SIM2);
				break;	
			default:
				text = VFX_WSTR("Wrong");
		}
		
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;

	}
#endif/*MMI_MAX_SIM_NUM*/
	return VFX_FALSE;
}

void VappMMSSetDataActPage::onTapItem(VcpListMenu *menu,VfxU32 index)
{
		
	switch(index)
	{			
			case VAPP_LIST_SETTING_DATA_ACCOUNT_SIM1:
				srv_wap_prof_display_profile_list(
					SRV_WAP_PROF_SIMID_DEFAULT,
					SRV_WAP_PROF_APPID_MMS,
					0, 0, GRP_ID_ROOT);				
				break;									
			case VAPP_LIST_SETTING_DATA_ACCOUNT_SIM2:
				{
					U8 sim_id = 0;
					#if(MMI_MAX_SIM_NUM >= 2)
						sim_id = SRV_WAP_PROF_SIMID_SIM2;
					#endif /*MMI_MAX_SIM_NUM*/
						srv_wap_prof_display_profile_list((srv_wap_prof_sim_id_enum)sim_id, SRV_WAP_PROF_APPID_MMS, 0, 0, GRP_ID_ROOT);
				}
									
				break;	
		default:
			break;
	}


}


#endif  /* __MMI_MMS_SETTING_PAGE__ */

     

/*****************************************************************************
 * FUNCTION
 *  vapp_mms_app_if_show_edit_profile_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vapp_mms_app_if_show_edit_profile_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check_sim_context */
    /* otherwise call profile api to shwo the profile list */
#if(MMI_MAX_SIM_NUM >= 2)
    if (!((srv_mms_get_sim1_context()) && (srv_mms_get_sim2_context())))
#endif /*MMI_MAX_SIM_NUM*/
    {

    #if(MMI_MAX_SIM_NUM >= 2)
        if ((srv_mms_get_sim1_context()) ||
            ((!srv_mms_get_sim1_context()) && (!srv_mms_get_sim2_context())))
        {
            srv_wap_prof_display_profile_list(
                SRV_WAP_PROF_SIMID_DEFAULT,
                SRV_WAP_PROF_APPID_MMS,
                0, 0, GRP_ID_ROOT);
        }
        else
        {
            srv_wap_prof_display_profile_list(
                SRV_WAP_PROF_SIMID_SIM2,
                SRV_WAP_PROF_APPID_MMS,
                0, 0, GRP_ID_ROOT);
        }
    #else /* #if(MMI_MAX_SIM_NUM >= 2) */ 
        srv_wap_prof_display_profile_list(
            SRV_WAP_PROF_SIMID_DEFAULT,
            SRV_WAP_PROF_APPID_MMS,
            0, 0, GRP_ID_ROOT);
    #endif /* #if(MMI_MAX_SIM_NUM >= 2) */ 

        return VFX_FALSE;
    }

	return VFX_TRUE;
    

}

/*****************************************************************************
*Class VappMMSSetSwitchControl
****************************************************************************/
/*
* Implement custom control for switch button in setting
*/

VFX_IMPLEMENT_CLASS("VappMMSSetSwitchControl", VappMMSSetSwitchControl, VcpListMenuCellBaseControl);

void VappMMSSetSwitchControl::onInit()
{
    VcpListMenuCellBaseControl::onInit();

    VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
    
    m_switch->setChecked(VFX_TRUE, VFX_TRUE);

    setSize(m_switch->getSize());
    m_switch->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                             VFX_FRAME_ALIGNER_MODE_NONE,
                             VFX_FRAME_ALIGNER_MODE_SIDE,
                             VFX_FRAME_ALIGNER_MODE_MID);
   
    m_switch->m_signalSwitchChanged.connect(this, &VappMMSSetSwitchControl::signalMMSSwitchChanged);
}

void VappMMSSetSwitchControl::onDeinit()
{
   
    m_switch->m_signalSwitchChanged.disconnect(this, &VappMMSSetSwitchControl::signalMMSSwitchChanged);
    VFX_OBJ_CLOSE(m_switch);

    VcpListMenuCellBaseControl::onDeinit();
}

void VappMMSSetSwitchControl::signalMMSSwitchChanged(VcpSwitch *sw, VfxBool isChecked)
{
    m_signalSwitchChanged.postEmit(this, isChecked);
}

void VappMMSSetSwitchControl::setMMSChecked(VfxBool checked)
{
    m_switch->setChecked(checked, VFX_TRUE);
}
#endif/*__MMI_MMS_2__*/
