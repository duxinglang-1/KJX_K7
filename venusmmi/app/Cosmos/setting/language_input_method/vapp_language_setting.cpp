/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  Vapp_Setting_LanguageSetting.cpp
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_language_setting.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_setting_framework_gprot.h"
#include "vcp_global_popup.h"
#include "vapp_launcher_gprot.h"


extern "C"
{
#include "CustDataRes.h"
//#include "PhoneSetupGprots.h"
#include "GeneralSettingSrvGprot.h"
#include "GlobalResDef.h"
#include "ShutdownSrvGprot.h"
#include "AlarmSrvGprot.h"
#include "UcmSrvGprot.h"
#include "mmi_rp_srv_editor_def.h"
#include "lang_interface.h"

}


#if defined(__MMI_IME_V3__)
 void VappIMEv3LanguageSetting(VfxMainScr * scr)
{
    VappLanguageSettingPage *main_page;

   VFX_OBJ_CREATE(main_page, VappLanguageSettingPage, scr);
   scr->pushPage(0,main_page);
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
mmi_id cui_language_setting_create(mmi_id parent_gid, U8* langSSC)
{   
    U8 currentLangSSC[SSC_SIZE] = {0};

    srv_setting_get_language(currentLangSSC);
    
    if ((strcmp((char*)currentLangSSC, (char*)langSSC) == 0))
    {
        return 0;
    }
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_LANGUAGE_SETTING,
                                        VFX_OBJ_CLASS_INFO(VappLanguageSettingCui),
                                        parent_gid,
                                        langSSC,
                                        sizeof(VappLanguageSettingCui));
    return cui_id;
}
#else
mmi_id cui_language_setting_create(mmi_id parent_gid, VfxU8 selectIdx)
{
    if (selectIdx == srv_setting_get_language())
    {
        return 0;
    }
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_LANGUAGE_SETTING,
                                        VFX_OBJ_CLASS_INFO(VappLanguageSettingCui),
                                        parent_gid,
                                        &selectIdx,
                                        sizeof(VappLanguageSettingCui));
    return cui_id;
}
#endif



void cui_language_setting_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

void cui_language_setting_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}



#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
void vapp_setting_language_hdl_for_sat(U8* langSSC)
{
    U8 currentLangSSC[SSC_SIZE] = {0};
    srv_setting_get_language(currentLangSSC);
  
    if ((strcmp((char*)currentLangSSC, (char*)langSSC) != 0))
    {
        if (srv_setting_set_language(langSSC))
        {
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_LANGUAGE_CHANGED);
	    MMI_FRM_CB_EMIT_EVENT(&evt);  
            vapp_launcher_restart();
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_SUCCESS, 
                VFX_WSTR_RES(STR_ID_VAPP_SETTING_SUCCESSFUL).getBuf());
        }
        else
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                VFX_WSTR_RES(STR_ID_VAPP_SETTING_FAILURE).getBuf());        
        }
    }
}
#else
void vapp_setting_language_hdl_for_sat(VfxU8 languageIdx)
{
    if (languageIdx != srv_setting_get_language())
    {
        if (srv_setting_set_language(languageIdx))
        {
	    mmi_event_struct evt;
	    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_LANGUAGE_CHANGED);
	    MMI_FRM_CB_EMIT_EVENT(&evt);  
            vapp_launcher_restart();
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_SUCCESS, 
                VFX_WSTR_RES(STR_ID_VAPP_SETTING_SUCCESSFUL).getBuf());
        }
        else
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                VFX_WSTR_RES(STR_ID_VAPP_SETTING_FAILURE).getBuf());        
        }
    }
}
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappLanguageSettingCell
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA" 

VFX_IMPLEMENT_CLASS("VappLanguageSettingCell", VappLanguageSettingCell, VcpFormItemLauncherCell);
void VappLanguageSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_LANGUAGE);
    VfxWString hintString = getHint();
    if (!hintString.isNull())
	{
	    setHintText(hintString);
	}
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappLanguageSettingCell::onTap);
}

VfxWString VappLanguageSettingCell::getHint()
{
    VfxWChar *currentLanguage = NULL;
    
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    U8 currentLangSSC[SSC_SIZE] = {0};
    srv_setting_get_language(currentLangSSC);
    currentLanguage = srv_setting_get_language_string(currentLangSSC);
#else
    currentLanguage = srv_setting_get_language_string(srv_setting_get_language());
#endif

    
    if (currentLanguage)
	{
	    return VFX_WSTR_MEM(currentLanguage);
	}
    return VFX_WSTR_NULL;
}

void VappLanguageSettingCell::updateCell()
{
    VfxWString hintString = getHint();
    if (!hintString.isNull())
	{
	    setHintText(hintString);
	}
}

void VappLanguageSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VappLanguageSettingPage *settingPage;
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
	{
		VFX_OBJ_CREATE(settingPage, VappLanguageSettingPage, mainScr);
        settingPage->m_signalUpdate.connect(this, &VappLanguageSettingCell::updateCell);
		mainScr->pushPage(0, settingPage);	
	}        
}
/***************************************************************************** 
 * VappLanguageSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappLanguageSettingPage", VappLanguageSettingPage, VfxPage);
void VappLanguageSettingPage::onInit()
{
    VfxPage::onInit();
    
    // Get total number and language string array of language
    m_count = GetLanguages(&m_languageStringArray);
    
    // Get select index
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    srv_setting_get_language(m_currentLangSSC);
    VfxU8 *tempLangSSC;
    for (VfxU32 i=0; i<m_count; i++)
    {
        mmi_li_get_ssc_by_langname((U8*)m_languageStringArray[i], (U8**)&tempLangSSC);
        if (strcmp((char *)tempLangSSC,(char *)m_currentLangSSC) == 0)
        {
            m_selectIdx = i;
            break;
        }        
    }
#else    
    m_currentSetting = srv_setting_get_language();
    m_selectIdx = m_currentSetting;
#endif /* __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__ */
    
#ifdef __MMI_AUTO_LANG_EN__
    if (m_selectIdx == 0xFF)   /* Auto Language set */
    {
        m_selectIdx = 0;
    }
    else
    {
        m_selectIdx += 1;
    }
#endif /* __MMI_AUTO_LANG_EN__ */

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
#ifdef __MMI_IME_V3__
	m_titleBar->setTitle(STR_ID_SYSTEM_LANGUAGE);
#else
    m_titleBar->setTitle(STR_ID_VAPP_SETTING_LANGUAGE);
#endif
    setTopBar(m_titleBar);  

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(0, STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem(1, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappLanguageSettingPage::onToolBarTap);
    setBottomBar(m_toolBar);

	VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setContentProvider(this);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_TRUE);    
//	m_listMenu->setRect(0, m_titleBar->getBounds().getMaxY(), LCD_WIDTH, (LCD_HEIGHT - m_titleBar->getBounds().getMaxY() -  m_toolBar->getBounds().getMaxY()));		 
	m_listMenu->setSize(getSize());		 
	m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VappLanguageSettingPage::onSelectItem); 
}


VfxBool VappLanguageSettingPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (index < (VfxU32)getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
            #ifdef __MMI_AUTO_LANG_EN__
            if (index == 0)
        	{
        	    text.loadFromRes(STR_GLOBAL_AUTOMATIC);
        	}
            else
            {
                text.loadFromMem((WCHAR*)m_languageStringArray[index]);
            }
            #else
            text.loadFromMem((WCHAR*)m_languageStringArray[index]);
            #endif /* __MMI_AUTO_LANG_EN__ */
		    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		    return VFX_TRUE;
		}
	}
	return VFX_FALSE;        
}

void VappLanguageSettingPage::onToolBarTap(VfxObject* sender, VfxId senderId)
{
    if (senderId == 0)
    {
    	VfxU8 selectIdx = m_selectIdx;
    	#ifdef __MMI_AUTO_LANG_EN__
    	if (m_selectIdx == 0)
    	{
            selectIdx = 0xFF;
	}
        #endif

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
        VfxU8 *selectLangSSC;
        mmi_li_get_ssc_by_langname((U8*)m_languageStringArray[selectIdx], (U8**)&selectLangSSC);
        if(strcmp((char *)selectLangSSC,(char *)m_currentLangSSC) == 0)
        {
            getMainScr()->popPage();	 
                return;
        }      
        m_languageSettingCuiId = cui_language_setting_create(getApp()->getGroupId(), (U8 *)selectLangSSC);
#else        
    	if (selectIdx == srv_setting_get_language())
        {
            getMainScr()->popPage();	 
                return;
        }
            //vapp_setting_language_hdl(selectIdx, getApp()->getGroupId());
        m_languageSettingCuiId = cui_language_setting_create(getApp()->getGroupId(), selectIdx);
#endif  /*__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__*/    

    	cui_language_setting_run(m_languageSettingCuiId);
    }
    else
    {
        getMainScr()->popPage();
    }
}

mmi_ret VappLanguageSettingPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_LANGUAGE_SETTING_SAME_AS_CURRENT_LANGUAGE:
        	getMainScr()->popPage();
        	cui_language_setting_close(m_languageSettingCuiId);        
            break;

        case EVT_ID_CUI_LANGUAGE_SETTING_CANCEL:
        	cui_language_setting_close(m_languageSettingCuiId);        
        	break;

        default:
    	    break;
    }
    return MMI_RET_OK;
}
#pragma arm section code, rodata

/***************************************************************************** 
 * VappLanguageSettingCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappLanguageSettingCui", VappLanguageSettingCui, VfxCui);
void VappLanguageSettingCui::onRun(void* args, VfxU32 argSize)
{
    if (!args)
    {
        sendLanguageSettingResult(EVT_ID_CUI_LANGUAGE_SETTING_INVALID_INPUT);
        return;
    }

/*
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    strcpy((char *)m_langSSC, (char *)args);
    U8 currentLangSSC[SSC_SIZE] = {0};
    srv_setting_get_language(currentLangSSC);
    if (!strcmp((char*)m_langSSC, (char*)currentLangSSC))
    {
        sendLanguageSettingResult(EVT_ID_CUI_LANGUAGE_SETTING_SAME_AS_CURRENT_LANGUAGE);	 
        return;
    }
else
    VfxU8 *languageId = (VfxU8*)args;
    m_languageIdx = *languageId;
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Language setting] CUI onRun language ID %d", m_languageIdx);
    if (m_languageIdx == srv_setting_get_language())
    {
        sendLanguageSettingResult(EVT_ID_CUI_LANGUAGE_SETTING_SAME_AS_CURRENT_LANGUAGE);	 
        return;
    }
#endif
*/

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    strcpy((char *)m_langSSC, (char *)args);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Language setting] CUI onRun language SSC %s", m_langSSC);
#else
    VfxU8 *languageId = (VfxU8*)args;
    m_languageIdx = *languageId;
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Language setting] CUI onRun language ID %d", m_languageIdx);
#endif

    VFX_OBJ_CREATE(m_scr, VappLanguageSettingMainScr, this);
    m_scr->show();

    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, m_scr);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    confirm->setText(STR_ID_VAPP_SETTING_LANGUAGE_STOP_APP_CONFIRM);
    //confirm->setIsPlayTone(VFX_FALSE);
    confirm->setCustomButton(
                            STR_GLOBAL_CONTINUE, 
                            STR_GLOBAL_CANCEL, 
                            VCP_POPUP_BUTTON_TYPE_WARNING,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappLanguageSettingCui::onPopupBtnTap);
    //mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    confirm->show(VFX_FALSE);
}

void VappLanguageSettingCui::sendLanguageSettingResult(cui_language_setting_enum evtId)
{
    mmi_group_event_struct groupEvt;
    MMI_FRM_INIT_GROUP_EVENT(&groupEvt, evtId, m_groupId);
    sendToCaller(&groupEvt);
}

void VappLanguageSettingCui::onOk()
{
    VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup, m_scr);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT);
    m_popup->setText(STR_ID_VAPP_SETTING_LANGUAGE_SWITCHING);
    m_popup->setAutoDestory(VFX_TRUE);
    m_popup->setIsAnimate(VFX_FALSE);
    m_popup->m_signalPopupState.connect(this, &VappLanguageSettingCui::setLanProc);
    //mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    m_popup->show(VFX_FALSE);

    //srv_setting_set_language(m_languageIdx);
    //sendLanguageSettingResult(EVT_ID_CUI_LANGUAGE_SETTING_DONE);
    //srv_alm_normal_reset(MMI_TRUE, 3);
}

void VappLanguageSettingCui::onCancel()
{
    sendLanguageSettingResult(EVT_ID_CUI_LANGUAGE_SETTING_CANCEL);
}

void VappLanguageSettingCui::onPopupBtnTap(VfxObject *obj, VfxId id)
{
    if (id == 'USR1')
    {
        VcpConfirmPopup* confirm = VFX_OBJ_DYNAMIC_CAST(obj,VcpConfirmPopup);
        VFX_OBJ_CLOSE(confirm);
        onOk();
    }    
    else
    {
	    onCancel();
    }
}

void VappLanguageSettingCui::setLanProc(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{
    if(state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
        (VFX_OBJ_GET_INSTANCE(VfxRenderer))->suspendUntilCommit();
        
        #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
        if (MMI_FALSE == srv_setting_set_language(m_langSSC))
        #else
        if (MMI_FALSE == srv_setting_set_language(m_languageIdx))
        #endif    
        {
            VFX_OBJ_CLOSE(m_popup);
            sendLanguageSettingResult(EVT_ID_CUI_LANGUAGE_SETTING_CANCEL);
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                VFX_WSTR_RES(STR_ID_VAPP_SETTING_FAILURE).getBuf()); 

            return;
        }

	mmi_event_struct evt;
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_LANGUAGE_CHANGED);
	MMI_FRM_CB_EMIT_EVENT(&evt);  
        sendLanguageSettingResult(EVT_ID_CUI_LANGUAGE_SETTING_DONE);
        vapp_launcher_restart();
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_SUCCESS, 
            VFX_WSTR_RES(STR_ID_VAPP_SETTING_SUCCESSFUL).getBuf()); 
    }
}
