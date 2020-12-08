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
 * 
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _VAPP_WAP_PUSH_PROV_CPP_
#define _VAPP_WAP_PUSH_PROV_CPP_

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
#include "vapp_wap_push_prov.h"
#include "vapp_cca_gprot.h"
#include "mmi_rp_vapp_cca_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_wap_push_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "GlobalResDef.h"
#include "vapp_wap_push_interface.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "WAPPushSrvProts.h"
#include "WAPPushSrvTypes.h"
#include "CcaSrvGprot.h"
#ifdef __cplusplus
}
#endif


static mmi_id g_cui_id;

extern "C" mmi_id vcui_push_prov_setting_display_create(void)
{

    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_WAP_PUSH_PROV,
                                        VFX_OBJ_CLASS_INFO(VappPushProvSettingDisplay),
                                        vapp_cca_get_parent_id());
	vfxSetCuiCallerScr(cui_id, vapp_cca_get_parent_screen());
    return cui_id;
}

/* Execute CUI*/
extern "C" void vcui_push_prov_setting_display_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

extern "C" void vcui_push_prov_setting_redisplay(VfxU16 trustlist_count, mmi_id cui_id)
{

	if (trustlist_count > 0)
        {                
		   VappPushProvSettingDisplay *pagecui 
			   = ((VappPushProvSettingDisplay *)VfxAppLauncher::getObject(cui_id));
		   if ((pagecui->m_scr->m_OTAListpage).isValid())
			   pagecui->m_scr->popPage();
		   pagecui->m_scr->redrawPage();

        }
        else
        {
			VfxAppLauncher::terminate(cui_id);   
        }


}

/* Close CUI */
extern "C" void  vcui_push_prov_setting_display_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);

}

extern "C" mmi_ret onPushProvSettingCreate(mmi_event_struct *evt)
	{ 
		g_cui_id = vcui_push_prov_setting_display_create();
		vcui_push_prov_setting_display_run(g_cui_id);
                return  MMI_RET_OK;
	}

extern "C" mmi_ret onPushProvSettingRedisplay(mmi_event_struct *evt)
	{
		vcui_push_prov_setting_redisplay(g_srv_wap_push_ota_cntxt.total_trustlist_count, g_cui_id);
		return  MMI_RET_OK;
	}


/***************************************************************************** 
 * Class VappPushProvSettingDisplay
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappPushProvSettingDisplay", VappPushProvSettingDisplay, VfxCui);

void VappPushProvSettingDisplay::onRun(void * arg,VfxU32 argSize)
{   
    VFX_OBJ_CREATE_EX(m_scr, VappPushProvSettingScr, this, (m_groupId));
    m_scr->show();
}

mmi_ret VappPushProvSettingDisplay::onProc(mmi_event_struct * evt)
{
    return MMI_RET_OK;
}


void VappPushProvSettingDisplay::onInit()
{
    VfxCui::onInit();
}


void VappPushProvSettingDisplay::onDeinit()
{
    VfxCui::onDeinit();
}


/***************************************************************************** 
 * Class VappProvSettingScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappPushProvSettingScr", VappPushProvSettingScr, VfxMainScr);

void VappPushProvSettingScr::onInit()
{
    VfxMainScr::onInit();

}

void VappPushProvSettingScr::onDeinit()
{

	((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_OTAlistEntry.disconnect(this , &VappPushProvSettingScr::onOTAListEntry);
    VfxMainScr::onDeinit();
}

void VappPushProvSettingScr::on1stReady()
{
    VfxMainScr::on1stReady();

	((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_OTAlistEntry.connect(this , &VappPushProvSettingScr::onOTAListEntry);
   
	VFX_OBJ_CREATE(m_page, VappPushProvSettingPage, this);
	pushPage(0, m_page);	

 
}

void VappPushProvSettingScr::onOTAListEntry()
{
 	VFX_OBJ_CREATE(m_OTAListpage, VappWapPushOTAWhiteListPage, this);
	pushPage(0, m_OTAListpage.get());	

}

void VappPushProvSettingScr::redrawPage()
{
	m_page->createDisplayInfo(); 
    m_page->m_bodyTextView->setText(m_page->m_bodyText, NULL);
}
/***************************************************************************** 
 * Class VappPushProvSettingPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappPushProvSettingPage", VappPushProvSettingPage, VfxPage);

void VappPushProvSettingPage::onInit()
{
    VfxPage::onInit(); // call base class

	setBgColor(VFX_COLOR_WHITE);
	
	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
	m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CCA_INSTALL_SETTING);
	setTopBar(m_titleBar); 
	VFX_ALLOC_MEM(m_bodyText, 1024, this);
    
	 //srv_wap_prov_create_display_info((VfxU8*)m_bodyText, 1024);
     
	 VFX_OBJ_CREATE(m_bodyTextView, VcpTextView, this);

	createDisplayInfo();

     m_bodyTextView->setPos(LEFT_GAPS, TOP_GAPS);
     m_bodyTextView->setSize(
        getSize().width - LEFT_GAPS - RIGHT_GAPS, 
        getSize().height - TOP_GAPS - BOTTOM_GAPS);
     m_bodyTextView->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

     m_bodyTextView->setText(m_bodyText);
     m_bodyTextView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
     

	
	
	VFX_OBJ_CREATE(m_tool_bar,VcpToolBar,this);
    m_tool_bar->m_signalButtonTap.connect(this, &VappPushProvSettingPage::onPushProvSettingPageTBClick);
    setBottomBar(m_tool_bar);

    m_tool_bar->addItem(PUSH_PROV_SETTING_VIEWER_INSTALL, (VfxResId)VCP_STR_TOOL_BAR_INSTALL,IMG_ID_VAPP_CCA_INSTALL);
    m_tool_bar->addItem(PUSH_PROV_SETTING_VIEWER_SKIP, (VfxResId)STR_ID_VAPP_CCA_SKIP,IMG_ID_VAPP_CCA_SKIP);





}

void VappPushProvSettingPage::onDeinit()
{
     VFX_OBJ_CLOSE(m_titleBar);
     VFX_OBJ_CLOSE(m_tool_bar);
     VFX_FREE_MEM(m_bodyText);

	 if (!g_srv_wap_push_ota_cntxt.cca_status_sent)
	 {
		srv_wap_push_ota_mem_free_trustlist();
		g_srv_wap_push_ota_cntxt.installed_result = CCA_STATUS_ENDKEY_PRESSED;
		g_srv_wap_push_ota_cntxt.cca_status_sent = MMI_TRUE;

		srv_wap_push_ota_send_cca_response(g_srv_wap_push_ota_cntxt.installed_result);

	 }
	 VfxPage::onDeinit();

}

void VappPushProvSettingPage::onPushProvSettingPageTBClick(VfxObject* sender, VfxId id)
    {
	 switch(id)
		{
			case PUSH_PROV_SETTING_VIEWER_INSTALL:
				srv_wap_push_ota_install_trustlist();
				
			   break;
				
			case PUSH_PROV_SETTING_VIEWER_SKIP:
					srv_wap_push_ota_skip_whitelist_hdlr();
				break;
		   default:
			   break;
		}
    }


void VappPushProvSettingPage::createDisplayInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS8 single_space_char_ucs2[3 * ENCODING_LENGTH];
    VfxS8 *colon_char_ucs2;
    VfxU8 new_line_info[4];
    VfxS8 buffer[((SRV_WAP_PUSH_OTA_PROXY_ID_LEN + 1) * ENCODING_LENGTH)];
    VfxS8 ascii_buffer[SRV_WAP_PUSH_OTA_PROXY_ID_LEN + 2];

    VfxS8 *address = (VfxS8*)g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.crnt_trustlist_index]->addr;
    VfxU16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(m_bodyText, 0, 1024);
    mmi_asc_to_ucs2((VfxChar*) new_line_info, (VfxChar*) "\n");
    mmi_asc_to_ucs2((VfxChar*) single_space_char_ucs2, (VfxChar*) " ");

    colon_char_ucs2 = (VfxS8*) GetString(STR_ID_VAPP_PUSH_COLON_CHAR);
				
    mmi_ucs2cpy((VfxChar*) m_bodyText, (VfxChar*) GetString(STR_ID_VAPP_CCA_PUSH));
    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) new_line_info);

    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) GetString(STR_ID_VAPP_PUSH_WHITE_LIST));
    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) colon_char_ucs2);
    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*)single_space_char_ucs2);

    memset(buffer, 0, sizeof(buffer));
    memset(ascii_buffer, 0, sizeof(ascii_buffer));

    sprintf(
        (VfxChar*) ascii_buffer,
        (VfxChar*) "%d/%d",
        g_srv_wap_push_ota_cntxt.crnt_trustlist_index + 1,
        g_srv_wap_push_ota_cntxt.crnt_trustlist_index + g_srv_wap_push_ota_cntxt.total_trustlist_count);

    mmi_asc_to_ucs2((VfxChar*) buffer, (S8*) ascii_buffer);
    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) buffer);
    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) new_line_info);

    switch (g_srv_wap_push_ota_cntxt.trustlist[g_srv_wap_push_ota_cntxt.crnt_trustlist_index]->addr_type)
    {
        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_IP:    /* IP address */
            mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) GetString(STR_ID_VAPP_PUSH_INBOX_TRUST_LIST_IP_ADDRESS));
				break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SENDER:    /* SENDER_ADD */
            mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) GetString(STR_ID_VAPP_PUSH_SENDER_ADDRESS));
            break;

        case SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SMSC:  /* SMSC_ADD */
            mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) GetString(STR_ID_VAPP_PUSH_SMSC_ADDR));
				break;
		}
    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) colon_char_ucs2);
    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*)single_space_char_ucs2);

    length = strlen ((const VfxChar*)address);

    if (length > MMI_PHB_NUMBER_LENGTH)
    {
        if (*(address + 0) == '+')
        {
            length = MMI_PHB_NUMBER_LENGTH + 1;
        }
        else
        {
            length = MMI_PHB_NUMBER_LENGTH;
    }
    }

    memset(buffer, 0, sizeof(buffer));
    mmi_asc_n_to_ucs2(
        (VfxChar*) buffer,
        (VfxChar*) address,
        length);

    mmi_ucs2cat((VfxChar*) m_bodyText, (VfxChar*) buffer);
    }

void VappPushProvSettingPage::onBack()
{
	VcpConfirmPopup *m_confirmPopup;
    VfxWString confirmString;
    confirmString.loadFromRes(STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM);
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setText(confirmString);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    m_confirmPopup->show(VFX_TRUE);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappPushProvSettingPage::onBackHandler);

}

void VappPushProvSettingPage::onBackHandler(VfxObject* obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
		VfxAppLauncher::terminate(((VappPushProvSettingScr*)getMainScr())->getCuiId()); 

	}
}

#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__*/
#endif /* _VAPP_WAP_PUSH_PROV_CPP_ */



