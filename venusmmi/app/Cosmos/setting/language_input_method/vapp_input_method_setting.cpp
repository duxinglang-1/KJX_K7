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
 *  vapp_input_method_setting.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  The source file of the setting for input method
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_setting_input_method_setting.h"
#include "vapp_input_method_setting.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#if defined(__MMI_IME_V3__)
//#include "mmi_rp_vapp_notes_def.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_srv_venus_component_menu_popup_def.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif
#endif

extern "C"
{
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "ImeGprot.h"
    #include "mmi_rp_srv_editor_def.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "IMERes.h"
	#include "ImmProt.h"
    extern const sIMEModeDetails *gIMEModeArray;
}


#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
extern "C"
{
    extern ime_writing_lang_struct g_ime_writing_lang_array[MAX_WRITING_LANG];
    extern U16 g_mmi_imm_enabled_writing_language;
}
#endif
#if defined(__MMI_IME_V3__)

#if defined(__MMI_IME_FUZZY_PINYIN__)
extern "C"
{
    extern ime_fuzzy_pinyin_struct g_ime_fuzzy_pinyin_array[MAX_FUZZY_PINYIN];
    extern U32 g_mmi_imm_enabled_fuzzy_pinyin;
}
#endif
//VfxBool isHWsettingEnable = VFX_TRUE ;
VfxBool temp_isVibrationEnable = VFX_TRUE ;
VfxBool temp_isSoundFeedbackEnable = VFX_TRUE ;
//U16 g_HWpenColor = 0 ;
U16 LanguageFollowKeybrd = 0 ;
VappIMEv3FollowKeyboardPage *g_FollowKeyBrdPage ;
VfxBool g_FollowKeyboard = 0 ;
#if !defined(__MMI_NO_HANDWRITING__)

VappIMEv3HWSettingPage *g_HWSettingPage ;
static UI_string_type g_hw_lang_str[MAX_WRITING_LANG] ;
U16 HWpenColor = 0 ;
#define	IME_HW_COLOR_MAX_ITEM_COUNT 4
#define IME_HW_PEN_MIN_PIXEL_RANGE 1
#define IME_HW_PEN_MAX_PIXEL_RANGE 5
#define IME_HW_MAX_STEP_ON_PEN 4

#endif

#endif
/***************************************************************************** 
 * Defination
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VAPP_IME_SETTING_PEN_SPEED_ITEM_HEIGHT 51
    #else
        #define VAPP_IME_SETTING_PEN_SPEED_ITEM_HEIGHT 65
    #endif
//Need to define color text and rect param
#define COLOR_TEXT_X 10
#define COLOR_TEXT_Y 16
#define COLOR_RECT_X 190
#define COLOR_RECT_Y 7
#define COLOR_RECT_WIDTH 80
#define COLOR_RECT_HEIGHT 35
#elif defined(__MMI_MAINLCD_480X800__)
    #define VAPP_IME_SETTING_PEN_SPEED_ITEM_HEIGHT 86
#define COLOR_TEXT_X 10
#define COLOR_TEXT_Y 23
#define COLOR_RECT_X 270
#define COLOR_RECT_Y 10
#define COLOR_RECT_WIDTH  110
#define COLOR_RECT_HEIGHT 67
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    #define VAPP_IME_SETTING_PEN_SPEED_ITEM_HEIGHT 45
#define COLOR_TEXT_X 10
#define COLOR_TEXT_Y 13
#define COLOR_RECT_X 130
#define COLOR_RECT_Y 5
#define COLOR_RECT_WIDTH 60
#define COLOR_RECT_HEIGHT 30
#else /* Shell: QVGA / WQVGA */
    #define VAPP_IME_SETTING_PEN_SPEED_ITEM_HEIGHT 57
//Need to define color text and rect param
#define COLOR_TEXT_X 10
#define COLOR_TEXT_Y 13
#define COLOR_RECT_X 130
#define COLOR_RECT_Y 5
#define COLOR_RECT_WIDTH 60
#define COLOR_RECT_HEIGHT 30
#endif
#define MAX_COLOR_ALPHA 255


#if defined(__MMI_IME_V3__)

void VappIMEInputMethodSetting(VfxMainScr * scr)
{
    VappIMEv3SettingMainPage *mainPage;
    if (scr != NULL)
    {
        VFX_OBJ_CREATE(mainPage, VappIMEv3SettingMainPage, scr);
//#if defined(__MMI_IME_USER_DATABASE__)
		VcpInputPopup* activPopup = NULL ;
		VfxU32 i = 0 ;
		while(1)
		{
			VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
			//activPopup = dynamic_cast<VcpInputPopup*>(topLevel->getActivePopup());
			activPopup = VFX_OBJ_DYNAMIC_CAST(topLevel->getActivePopup() , VcpInputPopup);
			if(activPopup != NULL)
			{
				mainPage->m_ActivePopup[i] = activPopup ;
				mainPage->m_ActivePopup[i]->hide(VFX_FALSE);
			}
			//activPopup = dynamic_cast<VcpInputPopup*>(topLevel->getActivePopup());
			activPopup = VFX_OBJ_DYNAMIC_CAST(topLevel->getActivePopup() , VcpInputPopup);
			if(activPopup)
			{
				i++ ;
				continue ;
			}
			else
			{
				break ;
			}
		}
//#endif
        scr->pushPage(VFX_ID_NULL, mainPage);
    }

}


VFX_IMPLEMENT_CLASS("VappIMEv3SettingMainPage", VappIMEv3SettingMainPage, VfxPage);

VappIMEv3SettingMainPage::VappIMEv3SettingMainPage()
{
	for(VfxU32 i = 0 ; i < MAX_INPUT_POPUP ; i++)
	{
		m_ActivePopup[i] = NULL ;
	}
}

void VappIMEv3SettingMainPage::onInit(void)
{
    VfxPage::onInit();
    drawMainPage();
}

VfxBool VappIMEv3SettingMainPage::onKeyInput(VfxKeyEvent& event)
{
	//#if defined(__MMI_IME_USER_DATABASE__)
	if(event.keyCode == VFX_KEY_CODE_BACK &&
	   event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		VfxS32 i = MAX_INPUT_POPUP - 1 ;
		while(i >= 0)
		{
			if(m_ActivePopup[i] != NULL)
			{
				m_ActivePopup[i]->show(VFX_FALSE);
				m_ActivePopup[i] = NULL ;
			}
			i-- ;
		}
	}
	//#endif
	return VfxPage::onKeyInput(event);
}

void VappIMEv3SettingMainPage::onExit(VfxBool isBackward)
{
    //Do handling once needed
    VfxPage::onExit(isBackward);
}

void VappIMEv3SettingMainPage::drawMainPage(void)
{
    VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
    m_tiltebar->setTitle(VFX_WSTR_RES(STR_IME_NEW_SETTING));

    setTopBar(m_tiltebar);
    VFX_OBJ_CREATE(m_form, VcpForm, this);

    m_form->setSize(getSize());
    m_form->setPos(0,0);
    m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

	//Multilanguage Setting
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    VcpFormItemLauncherCell *InputMethodTypeLauncherCell;
    VFX_OBJ_CREATE(InputMethodTypeLauncherCell, VcpFormItemLauncherCell, m_form);
    InputMethodTypeLauncherCell->setMainText(VFX_WSTR_RES(STR_ID_ML_SETTING));
	InputMethodTypeLauncherCell->m_signalTap.connect(this, &VappIMEv3SettingMainPage::onTapMenuHandler);
    InputMethodTypeLauncherCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	m_form->addItem(InputMethodTypeLauncherCell, INPUT_ML_SETTING);
#endif
	//Advance Setting

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
    if (mmi_imm_memory_card_is_auto_capitalization_enabled() || mmi_imm_memory_card_is_auto_space_enabled())
    {
        VcpFormItemLauncherCell *GeneralSettingLauncherCell;
        VFX_OBJ_CREATE(GeneralSettingLauncherCell, VcpFormItemLauncherCell, m_form);
        GeneralSettingLauncherCell->setMainText(VFX_WSTR_RES(STR_ID_AD_SETTING));
	    GeneralSettingLauncherCell->m_signalTap.connect(this, &VappIMEv3SettingMainPage::onTapMenuHandler);
        GeneralSettingLauncherCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	    m_form->addItem(GeneralSettingLauncherCell, INPUT_AD_SETTING);
    }
#endif

	//Handwriting Setting
#if !defined(__MMI_NO_HANDWRITING__)
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
	if(::mmi_imm_get_handwriting_setting()/*!::mmi_imc_is_handwriting_disabled()*/)
#endif
	{
		VcpFormItemLauncherCell *EnglishSettingLauncherCell;
		VFX_TRACE(("[HW Setting][Memory Card] VappIMEv3SettingMainPage::drawMainPage(), disable hw setting"));
	    VFX_OBJ_CREATE(EnglishSettingLauncherCell, VcpFormItemLauncherCell, m_form);
	    EnglishSettingLauncherCell->setMainText(VFX_WSTR_RES(STR_ID_HW_SETTING));
		EnglishSettingLauncherCell->m_signalTap.connect(this, &VappIMEv3SettingMainPage::onTapMenuHandler);
	    EnglishSettingLauncherCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
		m_form->addItem(EnglishSettingLauncherCell, INPUT_HW_SETTING);
	}
#endif

}


void VappIMEv3SettingMainPage::onTapMenuHandler(VcpFormItemCell* sender, VfxId id)
{
	switch(id)
	{
		#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
		case INPUT_ML_SETTING:
			{
					VappIMESettingWritingLangPage *langPage;
					VFX_OBJ_CREATE_EX(langPage, VappIMESettingWritingLangPage, getMainScr(), (getMainScr()));
					getMainScr()->pushPage(VFX_ID_NULL, langPage);
			}
			break;
		#endif
		case INPUT_AD_SETTING:
			{
				VappIMEv3AdvanceSettingPage *AdvanceSettingPage;
				VFX_OBJ_CREATE(AdvanceSettingPage, VappIMEv3AdvanceSettingPage, getMainScr());
				getMainScr()->pushPage(0, AdvanceSettingPage);
			}
			break;
		#if !defined(__MMI_NO_HANDWRITING__) 
		case INPUT_HW_SETTING:
			{
				VappIMEv3HWSettingPage *HWSettingPage;
				VFX_OBJ_CREATE(HWSettingPage, VappIMEv3HWSettingPage, getMainScr());
				g_HWSettingPage = HWSettingPage ;
				getMainScr()->pushPage(0, HWSettingPage);
			}
			break;
		#endif
	}
}

/*****************************************************************************
*Class VappIMEv3AdvanceSettingPage
****************************************************************************/

VFX_IMPLEMENT_CLASS("VappIMEv3AdvanceSettingPage", VappIMEv3AdvanceSettingPage, VfxPage);


void VappIMEv3AdvanceSettingPage::onInit()
{
    VfxPage::onInit(); // call base class

	// Set the Title Bar
	VcpTitleBar *m_tiltebar ;
	VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
	m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_AD_SETTING));
	setTopBar(m_tiltebar);

	VcpForm *form;
	VFX_OBJ_CREATE(form, VcpForm, this);
	form->setAutoAnimate(VFX_TRUE);
	form->setSize(getSize());
	form->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

	//Auto Space
	VcpFormItemSwitchCell *auto_space;
    VFX_OBJ_CREATE(auto_space, VcpFormItemSwitchCell, this);
    auto_space->setAutoAnimate(VFX_TRUE);
    auto_space->setMainText(VFX_WSTR_RES(STR_ID_IME_AUTO_SPACE));
    auto_space->setIsTappable(VFX_FALSE);
	if (::mmi_imm_is_auto_space_enabled())
	{
		auto_space->setSwitchStatus(VFX_TRUE);
	}
	else
	{
		auto_space->setSwitchStatus(VFX_FALSE);
	}
	auto_space->m_signalSwitchChangeReq.connect(this, &VappIMEv3AdvanceSettingPage::onAutoSpaceSettingChanged);
	form->addItem(auto_space, VIME_AUTO_SPACE);

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
	//Auto Cap
	if (mmi_imm_memory_card_is_auto_capitalization_enabled())
	{
	VcpFormItemSwitchCell *Auto_cap;
    VFX_OBJ_CREATE(Auto_cap, VcpFormItemSwitchCell, this);
    Auto_cap->setAutoAnimate(VFX_TRUE);
    Auto_cap->setMainText(VFX_WSTR_RES(STR_INPUT_METHOD_AUTO_CAPITALIZATION));
    Auto_cap->setIsTappable(VFX_FALSE);
	if (::mmi_imm_is_auto_capitalization_enabled())
	{
		Auto_cap->setSwitchStatus(VFX_TRUE);
	}
	else
	{
		Auto_cap->setSwitchStatus(VFX_FALSE);
	}
	Auto_cap->m_signalSwitchChangeReq.connect(this, &VappIMEv3AdvanceSettingPage::onAutoCapSettingChanged);
	form->addItem(Auto_cap, VIME_AUTO_CAP);
	}
#endif

#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
	//Association
	VcpFormItemSwitchCell *association;
    VFX_OBJ_CREATE(association, VcpFormItemSwitchCell, this);
    association->setAutoAnimate(VFX_TRUE);
    association->setMainText(VFX_WSTR_RES(STR_ID_IME_ASSOCIATION));
    association->setIsTappable(VFX_FALSE);
	if (::mmi_imm_is_chinese_word_prediction_enabled())
	{
		association->setSwitchStatus(VFX_TRUE);
	}
	else
	{
		association->setSwitchStatus(VFX_FALSE);
	}
	association->m_signalSwitchChangeReq.connect(this, &VappIMEv3AdvanceSettingPage::onAssociationSettingChanged);
	form->addItem(association, VIME_ASSOCIATION);
#endif

#if defined(__MMI_IME_FUZZY_PINYIN__)
	//Fuzzy pinyin    
	VcpFormItemLauncherCell *fuzzy_pinyin;
	VFX_OBJ_CREATE(fuzzy_pinyin, VcpFormItemLauncherCell, this);
	fuzzy_pinyin->setAutoAnimate(VFX_TRUE);
	fuzzy_pinyin->setMainText(VFX_WSTR_RES(STR_ID_FUZZY_PINYIN));
	fuzzy_pinyin->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	fuzzy_pinyin->m_signalTap.connect(this, &VappIMEv3AdvanceSettingPage::onFuzzyCellTapped);
	form->addItem(fuzzy_pinyin, VIME_FUZZY_PINYIN);
#endif

	//if needed touch feedback here

}

void VappIMEv3AdvanceSettingPage::onAutoSpaceSettingChanged(VcpFormItemSwitchCell * cell, VfxId id, VfxBool isOn)
{
	cell->setSwitchStatus(isOn);
	::mmi_imm_config_auto_space((MMI_BOOL)isOn);
}

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
void VappIMEv3AdvanceSettingPage::onAutoCapSettingChanged(VcpFormItemSwitchCell * cell, VfxId id, VfxBool isOn)
{
	if (mmi_imm_memory_card_is_auto_capitalization_enabled())
	{
	cell->setSwitchStatus(isOn);
	if (isOn == VFX_TRUE)
	{
		::mmi_imm_config_auto_capitalization(MMI_TRUE);
	}
	else
	{
		::mmi_imm_config_auto_capitalization(MMI_FALSE);

		if ((::mmi_imm_get_input_mode_array_item(::mmi_imm_get_prefer_input_mode()))->Mode_Special_Attrib &
		IME_MODE_ATTR_TITLECASE)
		{
			mmi_imm_input_mode_enum inputModeList[IMM_INPUT_MODE_MAX_NUM];
			::mmi_imm_get_prefer_input_mode_list(inputModeList, IMM_INPUT_MODE_MAX_NUM);
			::mmi_imm_set_prefer_input_mode(inputModeList[0]);
			::mmi_imm_write_prefered_input_method_to_nvram(::mmi_imm_get_prefer_input_mode());
		}
	}
}
}
#endif

#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
void VappIMEv3AdvanceSettingPage::onAssociationSettingChanged(VcpFormItemSwitchCell * cell, VfxId id, VfxBool isOn)
{
	cell->setSwitchStatus(isOn);
	::mmi_imm_config_chinese_word_prediction((MMI_BOOL)isOn);
}
#endif

#if defined(__MMI_IME_FUZZY_PINYIN__)
void VappIMEv3AdvanceSettingPage::onFuzzyCellTapped(VcpFormItemCell * cell, VfxId id)
{
	VappIMEv3FuzzyPinyinPage  *PinyinSettingPage;
	VFX_OBJ_CREATE_EX(PinyinSettingPage, VappIMEv3FuzzyPinyinPage, getMainScr(),(getMainScr()));
	getMainScr()->pushPage(0, PinyinSettingPage);
	return ;
}
#endif

#if !defined(__MMI_NO_HANDWRITING__) 

VFX_IMPLEMENT_CLASS("VappIMEv3HWSettingPage", VappIMEv3HWSettingPage, VfxPage);

VappIMEv3HandwritingSettingEnum VappIMEv3HWSettingContentProvider::getMenuItembyIndex(VfxS32 list_index)
{
	VFX_ASSERT(list_index >= 0) ;
	VfxS32 array_index = 0 ;
	VfxS32 temp = 0 ;
	for(array_index ; array_index < VAPP_IME_MENU_ITEM_HANDWRITING_SETTING_MAX_COUNT; array_index++)
	{
		if(m_itemIndexArray[array_index] == 1)
		{
			if(list_index == temp)
			{
				break;
			}
			else
			{
				temp++ ;
			}
		}
	}
    if (array_index >= VAPP_IME_MENU_ITEM_HANDWRITING_SETTING_MAX_COUNT)
    {
        VFX_ASSERT(0);
    }
    return (VappIMEv3HandwritingSettingEnum)array_index ;
}

void VappIMEv3HWSettingPage::onInit()
{
    VfxPage::onInit(); // call base class

	// Set the Title Bar
	VcpTitleBar *m_tiltebar ;
	VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
	m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_HW_SETTING));
	setTopBar(m_tiltebar);

	VFX_OBJ_CREATE(m_listMenuContentProvider, VappIMEv3HWSettingContentProvider, this);
	
	VFX_OBJ_CREATE(m_groupList, VcpGroupListMenu, this);
	m_groupList->setContentProvider(m_listMenuContentProvider);
	m_groupList->setPos(0,0);
	m_groupList->setSize(getSize());
	m_groupList->setCellStyle(/*VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT*/VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
	m_groupList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE,VFX_TRUE);
	m_groupList->m_signalItemTapped.connect(this, &VappIMEv3HWSettingPage::onItemTap);
	m_groupList->m_signalCmdButtonClicked.connect(this, &VappIMEv3HWSettingPage::onItemTapExt);

	m_groupList->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

}

void VappIMEv3HWSettingPage::onItemTap(VcpGroupListMenu *sender, VcpMenuPos pos)
{
	switch(pos.pos)
	{
	case 0:
		{
			VappIMEv3StrokeColorPage  *StrokeColorPage;
			VFX_OBJ_CREATE_EX(StrokeColorPage, VappIMEv3StrokeColorPage,getMainScr(),(getMainScr()));
			getMainScr()->pushPage(0, StrokeColorPage);
			break;
		}
	case 1:
		{
			VappIMESettingPenSpeedPage *penSpeedPage;
			VFX_OBJ_CREATE(penSpeedPage, VappIMESettingPenSpeedPage,getMainScr());
			getMainScr()->pushPage(0, penSpeedPage);
			break;
		}
	case 2:
		{
			//VappIMEv3StrokewidthPage  *StrokewidthPage;
			//VFX_OBJ_CREATE(StrokewidthPage, VappIMEv3StrokewidthPage, getMainScr());
			//getMainScr()->pushPage(0, StrokewidthPage);
			ShowStrokewitdhPopup();
			break;
		}
	case 3:
		//when HW over VK support need to open this code
#if defined (HANDWRITING_OVER_VK)
			VappIMEv3FollowKeyboardPage  *LangFollowKeyBoardPage;
			VFX_OBJ_CREATE_EX(LangFollowKeyBoardPage, VappIMEv3FollowKeyboardPage, getMainScr(),(getMainScr()));
			g_FollowKeyBrdPage = LangFollowKeyBoardPage ;
			getMainScr()->pushPage(0, LangFollowKeyBoardPage);
#else
		VappIMEv3LangFollowKbrdPage  *LangFollowKbrdPage;
		VFX_OBJ_CREATE_EX(LangFollowKbrdPage, VappIMEv3LangFollowKbrdPage, getMainScr(),(getMainScr()));
		getMainScr()->pushPage(0, LangFollowKbrdPage);
#endif
	default :
		break;
	}
}

VappIMEv3LangFollowKbrdPage::VappIMEv3LangFollowKbrdPage(VfxMainScr *mainScreen):
    m_mainScreen(mainScreen)
{
		m_count = ::mmi_imm_get_handwriting_language_strings(g_hw_lang_str );
}

VappIMEv3FollowKeyboardPage::VappIMEv3FollowKeyboardPage(VfxMainScr *mainScreen):
    m_mainScreen(mainScreen)
{
    g_FollowKeyboard = ::mmi_imm_handwriting_is_follow_vk() ? VFX_TRUE : VFX_FALSE;
}

VcpListMenuItemStateEnum VappIMEv3LangFollowKbrdPage::getItemState(
        VfxU32 index    // [IN] index of the item
        ) const 
{
    if (index < (VfxU32)m_count)
    {
			if(mmi_ucs2cmp((char*)g_hw_lang_str[index], (char*)(mmi_imm_get_handwriting_language())) == 0)
			{
				return VCP_LIST_MENU_ITEM_STATE_SELECTED;
			}
			else
			{
				return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
			}
		}

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	
}

VfxBool VappIMEv3LangFollowKbrdPage::getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        )
{
    if ((index < (VfxU32)m_count) && (fieldType == VCP_LIST_MENU_FIELD_TEXT))
    {	
		text = VFX_WSTR_MEM((VfxWChar *)g_hw_lang_str[index]);
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
    
	return VFX_FALSE;
}

VfxBool VappIMEv3FollowKeyboardPage::getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        )
{
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{
		if(index == 0)
		{
			text = VFX_WSTR_RES(STR_ID_IME_FOLLOW_KEYBOARD);
		}
		else if(index == 1)
		{
			text = VFX_WSTR_RES(STR_ID_KEYBRD_LANG);
		}
		return VFX_TRUE;
		}
		else
		{
		text = VFX_WSTR_NULL;
		}
	return VFX_FALSE;
	}
    
  VfxBool VappIMEv3LangFollowKbrdPage::getItemIsDisabled(
         VfxU32 index   // [IN] position of the item
        ) const
 {
	return VFX_FALSE;
}

  VfxBool VappIMEv3FollowKeyboardPage::getItemIsDisabled(
         VfxU32 index   // [IN] position of the item
        ) const
 {
	 if(index == 0 )
	 {
		 return VFX_FALSE ;
	 }
	 return (!g_FollowKeyboard) ; 
 }

VfxU32 VappIMEv3LangFollowKbrdPage::getCount() const
{
	return (VfxU32)m_count ;
}

VfxU32 VappIMEv3FollowKeyboardPage::getCount() const
{
	return (VfxU32)2 ;
}

void VappIMEv3LangFollowKbrdPage::onInit()
{
    VfxPage::onInit(); // call base class

	// Set the Title Bar
	VcpTitleBar *m_tiltebar ;
    VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
#if defined (HANDRITING_OVER_VK)
    m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_IME_KEYBOARD_LANGUAGE));
#else
	m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_KEYBRD_LANG));
#endif
	setTopBar(m_tiltebar);
	

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem((VfxId)0, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem((VfxId)1, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappIMEv3LangFollowKbrdPage::processButtonClicked);
    setBottomBar(toolBar);

	//VFX_OBJ_CREATE(m_listMenuContentProvider, VappIMEv3EnglishSettingContentProvider, this);
	
	VFX_OBJ_CREATE(m_List, VcpListMenu, this);
	m_List->setContentProvider(this);
	m_List->setPos(0,0);
	m_List->setSize(getSize());
	m_List->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_List->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_TRUE);
	m_List->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_TRUE);
	m_List->m_signalItemSelectionStateChanged.connect(this, &VappIMEv3LangFollowKbrdPage::onLangFollowSettingChanged);
	m_List->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

}

void VappIMEv3FollowKeyboardPage::onInit()
{
    VfxPage::onInit(); // call base class

	// Set the Title Bar
	VcpTitleBar *m_tiltebar ;
    VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
    m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_IME_FOLLOW_KEYBOARD));
	setTopBar(m_tiltebar);
	
	
	VFX_OBJ_CREATE(m_List, VcpListMenu, this);
	m_List->setContentProvider(this);
	m_List->setPos(0,0);
	m_List->setSize(getSize());
	m_List->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_List->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_TRUE);
	m_List->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
	m_List->m_signalItemTapped.connect(this, &VappIMEv3FollowKeyboardPage::onFollowKeyboardTap);
	m_List->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

}


void VappIMEv3LangFollowKbrdPage::processButtonClicked(VfxObject *sender, VfxId buttonId)
{
    if (buttonId == (VfxId)0)
    {
		// ::mmi_imm_handwriting_set_follow_vk_lang((MMI_BOOL)g_FollowKeyboard);
		// ::mmi_imm_handwriting_set_language(LanguageFollowKeybrd-1);
		::mmi_imm_config_handwriting_language(g_hw_lang_str[LanguageFollowKeybrd]);
	}
        m_mainScreen->popPage();

}

void VappIMEv3LangFollowKbrdPage::onLangFollowSettingChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if (index < (VfxU32)m_count)
    {
		if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            LanguageFollowKeybrd = index ;
        }
    }
}

void VappIMEv3FollowKeyboardPage::onFollowKeyboardTap(VcpListMenu *sender, VfxU32 index)
{
    if (index == 1)
	{		
		VappIMEv3LangFollowKbrdPage  *LangFollowKbrdPage;
		VFX_OBJ_CREATE_EX(LangFollowKbrdPage, VappIMEv3LangFollowKbrdPage, getMainScr(),(getMainScr()));
		getMainScr()->pushPage(0, LangFollowKbrdPage);
    }
}

void VappIMEv3LangFollowKbrdPage::setMenu(VcpListMenu *menu)
{

}

void VappIMEv3FollowKeyboardPage::updateItems(void)
 {
	m_List->updateAllItems();
 }

VcpListMenuCellBaseControl *VappIMEv3FollowKeyboardPage::getItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame)
 {
	VappIMEswitchControl* m_switchControl = NULL;
	if(location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
	{
		switch(index)
		{
			case 0:
				VFX_OBJ_CREATE(m_switchControl, VappIMEswitchControl, parentFrame);
				m_switchControl->m_signalSwitchChange.connect(g_FollowKeyBrdPage , &VappIMEv3FollowKeyboardPage::updateItems);
				m_switchControl->m_switch->m_signalSwitchChanged.connect(m_switchControl, &VappIMEswitchControl::emitSignal_Ext);
				if (g_FollowKeyboard)
                {
                    m_switchControl->m_switch->setChecked(VFX_TRUE, VFX_TRUE);
                }
                else
                {
                    m_switchControl->m_switch->setChecked(VFX_FALSE, VFX_TRUE);
                }
				break ;
			default:
			break;
		}
	}
	return m_switchControl;
 }
VFX_IMPLEMENT_CLASS("VappSetHWstrokeWidthPopup", VappSetHWstrokeWidthPopup, VfxBasePopup);

void VappIMEv3HWSettingPage::ShowStrokewitdhPopup(void)
{
	VappSetHWstrokeWidthPopup* HWstrokePopup;
	VFX_OBJ_CREATE(HWstrokePopup, VappSetHWstrokeWidthPopup, this);
	HWstrokePopup->setTitle(VFX_WSTR_RES(STR_ID_IME_TRACE_WIDTH));
	//HWstrokePopup->m_signalBtnClicked.connect(this,&VappFontSettingsOptionsPage::onPriButtonClicked);
	HWstrokePopup->show(VFX_TRUE);
}

void VappSetHWstrokeWidthPopup::onInit(void)
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);
    setBounds(0, 0, POPUP_WIDTH, POPUP_HEIGHT);

    VfxFrame* background_top;
    VFX_OBJ_CREATE(background_top, VfxFrame, this);
    background_top->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_TITLE_BG));
    background_top->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    background_top->setPos(0, 0);
    background_top->setSize(POPUP_WIDTH, UP_HEIGHT);

    VfxFrame* background_bot;
    VFX_OBJ_CREATE(background_bot, VfxFrame, this);
    background_bot->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_BG));
    background_bot->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    background_bot->setPos(0, UP_HEIGHT);
    background_bot->setSize(POPUP_WIDTH, POPUP_HEIGHT - UP_HEIGHT);

    //priority text
    VFX_OBJ_CREATE(m_HWstrokeText, VfxTextFrame, background_top);
    m_HWstrokeText->setAutoResized(VFX_FALSE);
    m_HWstrokeText->setSize(POPUP_WIDTH, UP_HEIGHT);
    m_HWstrokeText->setPos(0,0);
    m_HWstrokeText->setString(VFX_WSTR_RES(STR_GLOBAL_VOLUME));
    m_HWstrokeText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FNT_SIZE)));
    m_HWstrokeText->setVerticalToCenter(VFX_TRUE);
    m_HWstrokeText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    //icon
    VfxWChar pri_str_ucs2[4];
    VfxU8 pri_str[4];
    memset(pri_str_ucs2, 0, 8);
    memset(pri_str, 0, 4);
    sprintf((char*)pri_str, "%2d", m_width);
    mmi_asc_to_ucs2((char*) pri_str_ucs2, (char*) pri_str);
	mmi_ucs2cat((char*)pri_str_ucs2, (char*)L"X");	
    VFX_OBJ_CREATE(hw_icon,VfxTextFrame,this);
	hw_icon->setAutoResized(VFX_TRUE);
	hw_icon->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    hw_icon->setString(VFX_WSTR_MEM((const VfxWChar*)pri_str_ucs2));
    hw_icon->setPos(ICON_X,ICON_Y);

    //Slider
    VFX_OBJ_CREATE(m_slider, VcpSlider, this);
    m_slider->setPos(BAR_X, BAR_Y);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setLength(BAR_LENGTH);
    m_slider->setMaxValue(m_max);
    m_slider->setMinValue(m_min);
    m_slider->setTotalDiscreteStepsForPen(m_max - m_min);
    m_slider->setCurrentValue(m_width);

    m_slider->m_signalUserChangedValue.connect(this, &VappSetHWstrokeWidthPopup::onSliderMoved);

    VcpButton* btn;
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setText(VFX_WSTR_RES(STR_GLOBAL_OK));
    btn->setPos(BTN_X,BTN_Y);
    btn->setSize(BTN_WIDTH,BTN_HEIGHT);
    btn->m_signalClicked.connect(this,&VappSetHWstrokeWidthPopup::onButtonClicked);
}


VappSetHWstrokeWidthPopup::VappSetHWstrokeWidthPopup(void):
    m_HWstrokeText(NULL),
	m_max(IME_HW_PEN_MAX_PIXEL_RANGE),
	m_min(IME_HW_PEN_MIN_PIXEL_RANGE),
    hw_icon(NULL),
	m_slider(NULL)

{
	m_width = 	::mmi_imm_handwriting_get_stroke_width(); 
}



void VappSetHWstrokeWidthPopup::onDeinit(void)
{
	VfxBasePopup::onDeinit();
}

VfxBool VappSetHWstrokeWidthPopup::onKeyInput(VfxKeyEvent &event)
{
	switch(event.keyCode)
	{
		case VFX_KEY_CODE_BACK:
        {
			leave(VFX_TRUE);
            return VFX_TRUE;
        }
		default :
			break;
	}
	return VfxBasePopup::onKeyInput(event);
}

void VappSetHWstrokeWidthPopup::onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval)
{
    if(m_width == (VfxU8)newval)
    {
        return ;
    }

    m_width = (VfxU8)newval;

    VfxWChar pri_str_ucs2[4];
    VfxU8 pri_str[4];
    memset(pri_str_ucs2, 0, 8);
    memset(pri_str, 0, 4);
    sprintf((char*)pri_str, "%2d", m_width);
    mmi_asc_to_ucs2((char*) pri_str_ucs2, (char*) pri_str);
	mmi_ucs2cat((char*)pri_str_ucs2, (char*)L"X");
    hw_icon->setString(VFX_WSTR_MEM((const VfxWChar*)pri_str_ucs2));
}

void VappSetHWstrokeWidthPopup::onButtonClicked(VfxObject *sender, VfxId id)
{
    //m_signalBtnClicked.postEmit(m_width);
	::mmi_imm_handwriting_set_width(m_width);

    leave(VFX_TRUE);
}

void VappSetHWstrokeWidthPopup::setTitle(VfxWString id)
{
    m_HWstrokeText->setString(id);
}

VcpListMenuItemStateEnum VappIMEv3HWSettingPage::getItemState(
        VcpMenuPos pos  // [IN]  The position of the item
        ) const
{

		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
}

void VappIMEv3HWSettingPage::onItemTapExt(VcpGroupListMenu *sender, VcpMenuPos pos)
{

}

void VappIMEv3HWSettingPage::onDeinit()
{
	VfxPage::onDeinit(); // call base class
}

VfxScrRotateTypeEnum VappIMEv3HWSettingPage::onQueryRotate(const VfxScreenRotateParam &param)
{
	return param.rotateTo;	
}

 void VappIMEv3HWSettingPage::updateItems(void)
 {
	m_groupList->updateAllItems();
 }

 
VfxBool VappIMEv3HWSettingContentProvider::getItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        )
{
	if(fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG )
	{
		image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
	return VFX_TRUE ;
	}
	return VFX_FALSE ;
}

  VfxBool VappIMEv3HWSettingContentProvider::getItemIsDisabled(
         VcpMenuPos pos   // [IN] position of the item
        ) const
 {
	/* if(pos.pos == 0 )
	 {
		 return VFX_FALSE ;
	 } */
	 //return (!(::mmi_imm_handwriting_is_enable())) ;
	 return VFX_FALSE ;
 }


VfxU32 VappIMEv3HWSettingContentProvider::getCount(VfxU32 group) const
{		

	return (VfxU32)m_itemCount;
}

VcpListMenuCellClientBaseFrame *VappIMEv3HWSettingContentProvider::getItemCustomContentFrame(
        VcpMenuPos pos,
        VfxFrame *parentFrame
        )
{
   return NULL;
}

VfxBool VappIMEv3HWSettingContentProvider::getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
 {
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		switch(getMenuItembyIndex(pos.pos))
		{
			case VAPP_IME_MENU_ITEM_STROKE_COLOR_SETTING:
			text = VFX_WSTR_RES(STR_ID_IME_TRACE_COLOR);
				return VFX_TRUE ;
			case VAPP_IME_MENU_ITEM_HANDWRITING_SPEED_SETTING:
			text = VFX_WSTR_RES(STR_ID_IME_HW_SPEED);
				return VFX_TRUE ;
			case VAPP_IME_MENU_ITEM_HANDWRITING_TRACE_WIDTH_SETTING:
			text = VFX_WSTR_RES(STR_ID_IME_TRACE_WIDTH);
				return VFX_TRUE ;
			case VAPP_IME_MENU_ITEM_HANDWRITING_LANGUAGE_SETTING:
		{
#if defined(HANDWRITING_OVER_VK)
			text = VFX_WSTR_RES(STR_ID_IME_FOLLOW_KEYBOARD);
#else
			text = VFX_WSTR_RES(STR_ID_KEYBRD_LANG);
#endif
		return VFX_TRUE;
	}
			default :
				return VFX_FALSE ;
		}
	}
	else
	{
		text = VFX_WSTR_NULL;
	}	
	 return VFX_FALSE;
}

 VcpListMenuItemStateEnum VappIMEv3HWSettingContentProvider::getItemState(
        VcpMenuPos pos  
        ) const 
{ 
	if(::mmi_imm_handwriting_is_enable())
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
	else
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED ;
	}
}

VcpListMenuCellBaseControl *VappIMEv3HWSettingContentProvider::getItemCustomControl(VcpMenuPos pos, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame)
 {
	VappIMEswitchControl* m_switchControl = NULL;
	if(location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
	{
		switch(getMenuItembyIndex(pos.pos))
                {
			case VAPP_IME_MENU_ITEM_STROKE_COLOR_SETTING:
				break ;
			case VAPP_IME_MENU_ITEM_HANDWRITING_SPEED_SETTING:
				break ;
			case VAPP_IME_MENU_ITEM_HANDWRITING_TRACE_WIDTH_SETTING:
				break ;
			case VAPP_IME_MENU_ITEM_HANDWRITING_LANGUAGE_SETTING:
				break ;
				/*VFX_OBJ_CREATE(m_switchControl, VappIMEswitchControl, parentFrame);
				m_switchControl->m_switch->m_signalSwitchChanged.connect(this , &VappIMEswitchControl::signalLangFollowKeybrdChanged); */
			default:
			break;
		}
	}
	return m_switchControl;
 }

#endif


//VFX_IMPLEMENT_CLASS("VappIMEv3StrokeColorPage", VappIMEv3StrokeColorPage, VfxPage);
//VFX_IMPLEMENT_CLASS("VappIMEv3StrokeColorCell", VappIMEv3StrokeColorCell, VcpFormItemCell);
#if !defined(__MMI_NO_HANDWRITING__)
	//VFX_IMPLEMENT_CLASS("VappIMEv3StrokewidthPage", VappIMEv3StrokewidthPage, VfxPage);
VFX_IMPLEMENT_CLASS("VappIMEv3HWwidthCell", VappIMEv3HWwidthCell, VcpFormItemCell);

VappIMEv3StrokeColorPage::VappIMEv3StrokeColorPage(VfxMainScr *mainScreen):
    m_count(IME_HW_COLOR_MAX_ITEM_COUNT), m_mainScreen(mainScreen)
{
	HwColor = (color *)mmi_imm_handwriting_get_color_list();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VcpListMenuItemStateEnum VappIMEv3StrokeColorPage::getItemState(
        VfxU32 index    // [IN] index of the item
        ) const 
{
	if(::mmi_imm_handwriting_get_current_color_id() == index)
	{
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
	else
	{
	    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;	
    }
}
/*
VfxBool VappIMEv3StrokeColorPage::getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        )
{
    
	const char* strokecolortext[1][4] ={"White", "Red","Yellow", "Green"};
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		VfxChar tempBuff[100];
		mmi_asc_to_ucs2((char*)tempBuff, (char*)strokecolortext[0][index]);
		text = VFX_WSTR_MEM((VfxWChar *)tempBuff);
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
	else
	{
		text = VFX_WSTR_NULL;
	}	
	 return VFX_FALSE;
}
*/

VfxU32 VappIMEv3StrokeColorPage::getCount() const
{
	return (VfxU32)(::mmi_imm_handwriting_get_color_number()) ;
}

void VappIMEv3StrokeColorPage::onInit()
{
    VfxPage::onInit(); // call base class

	// Set the Title Bar
	VcpTitleBar *m_tiltebar ;
    VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
    m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_IME_TRACE_COLOR));
	setTopBar(m_tiltebar);
	

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem((VfxId)0, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem((VfxId)1, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappIMEv3StrokeColorPage::processButtonClicked);
    setBottomBar(toolBar);

	//VFX_OBJ_CREATE(m_listMenuContentProvider, VappIMEv3EnglishSettingContentProvider, this);
	
	VFX_OBJ_CREATE(m_List, VcpListMenu, this);
	m_List->setContentProvider(this);
	m_List->setPos(0,0);
	m_List->setSize(getSize());
	m_List->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
	m_List->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_TRUE);
	m_List->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_TRUE);
	m_List->m_signalItemSelectionStateChanged.connect(this, &VappIMEv3StrokeColorPage::onStrokeColorSettingChanged);
	HWpenColor = mmi_imm_handwriting_get_current_color_id() ;
	m_List->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

}

VcpListMenuCellClientBaseFrame *VappIMEv3StrokeColorPage::getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        )
{
	VappIMEstrokeColorFrame *StrokeColorFrame ;
	VfxFrame *ColorFrame ;
	VfxTextFrame *ColorText;
	VFX_OBJ_CREATE(StrokeColorFrame, VappIMEstrokeColorFrame, parentFrame);
	VFX_OBJ_CREATE(ColorFrame, VfxFrame, StrokeColorFrame);
	VFX_OBJ_CREATE(ColorText, VfxTextFrame, StrokeColorFrame);

	//get the color list
	 
	StrokeColorFrame->setBounds(parentFrame->getRect());

	//ColorText->setString(VFX_WSTR("Red"));
	ColorText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER_WITHIN_MARGIN);
	ColorText->setPos( COLOR_TEXT_X, COLOR_TEXT_Y); 
	ColorText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));

	ColorFrame->setRect(COLOR_RECT_X, COLOR_RECT_Y ,COLOR_RECT_WIDTH,COLOR_RECT_HEIGHT);
	ColorFrame->setPos(COLOR_RECT_X,COLOR_RECT_Y);
	ColorFrame->setBgColor(VfxColor(MAX_COLOR_ALPHA,HwColor[index].r,HwColor[index].g,HwColor[index].b));
	StrokeColorFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
	VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

	return StrokeColorFrame ;
}

void VappIMEstrokeColorFrame::onLayoutElements(void)
{

}
/*
VcpListMenuCellBaseControl* VappIMEv3StrokeColorPage::getItemCustomControl( VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame)
{
	
	if(location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
	{
		VappIMEv3ColorCell *colorBaseControl ;
		VFX_OBJ_CREATE(colorBaseControl, VappIMEv3ColorCell, parentFrame);
		colorBaseControl->cellColorFrame->setRect(72,80,337,200);
		colorBaseControl->cellColorFrame->setPos(getSize().width / 2, getSize().height / 2);
		colorBaseControl->cellColorFrame->setBgColor(VfxColor(255,100,100,100));
		return colorBaseControl;
	}
	else
	{
		return NULL ;
	}
	
}
*/
void VappIMEv3StrokeColorPage::processButtonClicked(VfxObject *sender, VfxId buttonId)
{
	if (buttonId == (VfxId)0)
    {
		//g_HWpenColor = HWpenColor ;
		mmi_imm_handwriting_set_current_stroke_color((U8)HWpenColor);
	}
	getMainScr()->popPage();
}

VfxBool VappIMEv3StrokeColorPage::getItemTextFrameFormat(
    VfxU32 index,                   // [IN] the index of item
    VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
    VfxTextFrame *frame             // [OUT] the text frame
    ) 
{
       // frame->setMargins(200,0,0,0);
        return VFX_TRUE;

}

void VappIMEv3StrokeColorPage::onStrokeColorSettingChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	if(newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
	{
		HWpenColor = index ;
	}
}
VfxScrRotateTypeEnum VappIMEv3StrokeColorPage::onQueryRotate(const VfxScreenRotateParam &param)
{
	return param.rotateTo;
	
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
#endif
VappIMEv3TouchfeedBackPage::VappIMEv3TouchfeedBackPage(VfxMainScr *mainScreen):
    m_mainScreen(mainScreen)
{

}

void VappIMEv3TouchfeedBackPage::onTouchfeedBackSettingChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	if(index == 0)
	{
		if(newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
		{
			temp_isVibrationEnable  = VFX_FALSE ;
		}
		else
		{
			temp_isVibrationEnable  = VFX_TRUE ;
		}
	}
	else if(index == 1)
	{
		if(newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
		{
			temp_isSoundFeedbackEnable  = VFX_FALSE ;
		}
		else
		{
			temp_isSoundFeedbackEnable  = VFX_TRUE ;
		}
	}
	else
	{

	}

}

void VappIMEv3TouchfeedBackPage::processButtonClicked(VfxObject *sender, VfxId buttonId)
{
    if (buttonId == (VfxId)0)
    {
		::mmi_imm_config_vibration((MMI_BOOL)temp_isVibrationEnable);
		::mmi_imm_config_sound_feedback((MMI_BOOL)temp_isSoundFeedbackEnable );
	}
	getMainScr()->popPage();
}


void VappIMEv3TouchfeedBackPage::onInit()
{
    VfxPage::onInit(); // call base class

	// Set the Title Bar
	VcpTitleBar *m_tiltebar ;
    VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
    m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_TOUCH_FEEDBACK));
	setTopBar(m_tiltebar);
	

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem((VfxId)0, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem((VfxId)1, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappIMEv3TouchfeedBackPage::processButtonClicked);
    setBottomBar(toolBar);

	//VFX_OBJ_CREATE(m_listMenuContentProvider, VappIMEv3EnglishSettingContentProvider, this);
	
	VFX_OBJ_CREATE(m_List, VcpListMenu, this);
	m_List->setContentProvider(this);
	m_List->setPos(0,0);
	m_List->setSize(getSize());
	m_List->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_List->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_TRUE);
	m_List->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
	m_List->m_signalItemSelectionStateChanged.connect(this, &VappIMEv3TouchfeedBackPage::onTouchfeedBackSettingChanged);
	m_List->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

}

VfxBool VappIMEv3TouchfeedBackPage::getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        )
{
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {								
		if(index == 0)
		{
			text = VFX_WSTR_RES(STR_ID_IME_VIBRATION);
		}
		else if (index == 1)
		{
			text = VFX_WSTR_RES(STR_ID_IME_SOUND_FEEDBACK);
		}
		return VFX_TRUE;
	}
	else
	{
		text = VFX_WSTR_NULL;
	}	
	 return VFX_FALSE;
}

VcpListMenuItemStateEnum VappIMEv3TouchfeedBackPage::getItemState(
        VfxU32 index    // [IN] index of the item
        ) const 
{
	if(index == 0)
	{
		if(::mmi_imm_is_vibration_enabled())
		{
			return VCP_LIST_MENU_ITEM_STATE_SELECTED ;
		}
		else
		{
			return VCP_LIST_MENU_ITEM_STATE_UNSELECTED ;
		}
	}
	else if(index == 1)
	{
		if(::mmi_imm_is_sound_feedback_enabled())
		{
			return VCP_LIST_MENU_ITEM_STATE_SELECTED ;
		}
		else
		{
			return VCP_LIST_MENU_ITEM_STATE_UNSELECTED ;
		}
	}
	else
	{
	return VCP_LIST_MENU_ITEM_STATE_SELECTED;
}
}

#if defined(__MMI_IME_FUZZY_PINYIN__)
VappIMEv3FuzzyPinyinPage::VappIMEv3FuzzyPinyinPage(VfxMainScr *mainScreen):
    m_mainScreen(mainScreen),m_count(IME_FUZZY_PINYIN_MAX)
{
	temp_mmi_imm_enabled_fuzzy_pinyin = g_mmi_imm_enabled_fuzzy_pinyin ;
}


VcpListMenuItemStateEnum VappIMEv3FuzzyPinyinPage::getItemState(
        VfxU32 index    // [IN] index of the item
        ) const 
{
    if (index < (VfxU32)m_count)
    {
       
        if(temp_mmi_imm_enabled_fuzzy_pinyin & g_ime_fuzzy_pinyin_array[index].fuzzy_id)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
	        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	
}


VfxBool VappIMEv3FuzzyPinyinPage::getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        )
{
    if ((index < (VfxU32)m_count) && (fieldType == VCP_LIST_MENU_FIELD_TEXT))
    {								
		VfxChar tempBuff[20];
		mmi_asc_to_ucs2((char*)tempBuff, (char*)(::g_ime_fuzzy_pinyin_array[index].fuzzy_str_ptr));
		text = VFX_WSTR_MEM((VfxWChar *)tempBuff);
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		return VFX_TRUE;
	}
    
	return VFX_FALSE;
}



  VfxBool VappIMEv3FuzzyPinyinPage::getItemIsDisabled(
         VfxU32 index   // [IN] position of the item
        ) const
 {
	 VfxBool isDisable = VFX_FALSE ;
    // isDisable = ::g_mmi_imm_enabled_fuzzy_pinyin & g_ime_fuzzy_pinyin_array[index].fuzzy_id ;
	return isDisable ; 
 }
VfxU32 VappIMEv3FuzzyPinyinPage::getCount() const
{
	return (VfxU32)m_count ;
}


//VFX_IMPLEMENT_CLASS("VappIMEv3FuzzyPinyinPage", VappIMEv3FuzzyPinyinPage, VfxPage);
void VappIMEv3FuzzyPinyinPage::onInit()
{
    VfxPage::onInit(); // call base class

	// Set the Title Bar
	VcpTitleBar *m_tiltebar ;
    VFX_OBJ_CREATE(m_tiltebar, VcpTitleBar, this);
    m_tiltebar->setTitle(VFX_WSTR_RES(STR_ID_FUZZY_PINYIN));
	setTopBar(m_tiltebar);
	

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem((VfxId)0, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem((VfxId)1, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappIMEv3FuzzyPinyinPage::processButtonClicked);
    setBottomBar(toolBar);

	//VFX_OBJ_CREATE(m_listMenuContentProvider, VappIMEv3EnglishSettingContentProvider, this);
	
	VFX_OBJ_CREATE(m_List, VcpListMenu, this);
	m_List->setContentProvider(this);
	m_List->setPos(0,0);
	m_List->setSize(getSize());
	m_List->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
	m_List->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_TRUE);
	m_List->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
	m_List->m_signalItemSelectionStateChanged.connect(this, &VappIMEv3FuzzyPinyinPage::onPinyinSettingChanged);
	m_List->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);

}




void VappIMEv3FuzzyPinyinPage::processButtonClicked(VfxObject *sender, VfxId buttonId)
{
    if (buttonId == (VfxId)0)
    {
		g_mmi_imm_enabled_fuzzy_pinyin = temp_mmi_imm_enabled_fuzzy_pinyin ;
        VfxU32 data = ::g_mmi_imm_enabled_fuzzy_pinyin;
        VfxS16 error;
        WriteValue((U16)NVRAM_SETTING_ENABLED_FUZZY_PINYIN, (void*)&data, (U8)DS_SHORT, (S16*)&error);
	}
        m_mainScreen->popPage();

}


void VappIMEv3FuzzyPinyinPage::onPinyinSettingChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if (index < (VfxU32)m_count)
    {
        if (newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            temp_mmi_imm_enabled_fuzzy_pinyin &= ~g_ime_fuzzy_pinyin_array[index].fuzzy_id;
        }
        else if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
			temp_mmi_imm_enabled_fuzzy_pinyin |= (g_ime_fuzzy_pinyin_array[index].fuzzy_id);
        }
    }
}



VfxScrRotateTypeEnum VappIMEv3FuzzyPinyinPage::onQueryRotate(const VfxScreenRotateParam &param)
{
	return param.rotateTo;
	
}
void VappIMEv3FuzzyPinyinPage::setMenu(VcpListMenu *menu)
{

}

#endif /*__MMI_IME_FUZZY_PINYIN__*/


void VappIMEv3AdvanceSettingPage::onDeinit()
{
	VfxPage::onDeinit(); // call base class
}



VfxScrRotateTypeEnum VappIMEv3AdvanceSettingPage::onQueryRotate(const VfxScreenRotateParam &param)
{
	return param.rotateTo;	
}

 /*****************************************************************************
*Class VappIMEswitchControl
****************************************************************************/
/*
* Implement custom control for switch button in setting
*/

VFX_IMPLEMENT_CLASS("VappIMEswitchControl", VappIMEswitchControl, VcpListMenuCellBaseControl);

void VappIMEswitchControl::onInit()
{
    VcpListMenuCellBaseControl::onInit();

    VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
    
    //m_switch->setChecked(isHWsettingEnable, VFX_TRUE);

    setSize(m_switch->getSize());
    m_switch->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                             VFX_FRAME_ALIGNER_MODE_NONE,
                             VFX_FRAME_ALIGNER_MODE_SIDE,
                             VFX_FRAME_ALIGNER_MODE_MID);
   

}

void VappIMEswitchControl::signalTouchFeedBackChanged(VcpSwitch *sw, VfxBool isChecked)
{
	//Do the handling here for Touch feedback change here
}

void VappIMEswitchControl::signalAutoSpaceChanged(VcpSwitch *sw, VfxBool isChecked)
{
	//Do the handling here for Touch feedback change here
	::mmi_imm_config_auto_space((MMI_BOOL)isChecked);
}

void VappIMEswitchControl::signalAutoCapChanged(VcpSwitch *sw, VfxBool isChecked)
{
	//Do the handling here for Touch feedback change here
	
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
	if (mmi_imm_memory_card_is_auto_capitalization_enabled())
	{

    if (isChecked == VFX_TRUE)
    {
        ::mmi_imm_config_auto_capitalization(MMI_TRUE);
    }
    else
    {
        ::mmi_imm_config_auto_capitalization(MMI_FALSE);

        if ((::mmi_imm_get_input_mode_array_item(::mmi_imm_get_prefer_input_mode()))->Mode_Special_Attrib &
            IME_MODE_ATTR_TITLECASE)
        {
            mmi_imm_input_mode_enum inputModeList[IMM_INPUT_MODE_MAX_NUM];
            ::mmi_imm_get_prefer_input_mode_list(inputModeList, IMM_INPUT_MODE_MAX_NUM);
            ::mmi_imm_set_prefer_input_mode(inputModeList[0]);
            ::mmi_imm_write_prefered_input_method_to_nvram(::mmi_imm_get_prefer_input_mode());
        }
    }
	}
#endif
}

void VappIMEswitchControl::signalAssiciationChanged(VcpSwitch *sw, VfxBool isChecked)
{
#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
    if (isChecked == VFX_TRUE)
    {
        ::mmi_imm_config_chinese_word_prediction(MMI_TRUE);
    }
    else
    {
        ::mmi_imm_config_chinese_word_prediction(MMI_FALSE);
    }
#endif
}

void VappIMEswitchControl::signalLangFollowKeybrdChanged(VcpSwitch *sw, VfxBool isChecked)
{
	//Do the handling here for Touch feedback change here
	//::mmi_imm_set_hw_follow_vk_lang((MMI_BOOL)isChecked);	
}
 
//void VappIMEswitchControl::signalHWswttingChanged(VcpSwitch *sw, VfxBool isChecked)
//{
//	isHWsettingEnable = isChecked ;
//	//VcpGroupListMenu *list = (VcpGroupListMenu*)getParentFrame()->getParentFrame();
//	////Do the handling here for Touch feedback change here
//	////VappIMEv3HWSettingPage* main_page = dynamic_cast<VappIMEv3HWSettingPage*>(VfxMainScr::findMainScr((VfxFrame*)getParent()));
//	//list->updateAllItems();
//	m_signalSwitchChanged.emit
//}

void VappIMEswitchControl::onDeinit()
{

    VFX_OBJ_CLOSE(m_switch);

    VcpListMenuCellBaseControl::onDeinit();
}


void VappIMEswitchControl::emitSignal(VcpSwitch *sender, VfxBool state)
{
#if !defined(__MMI_NO_HANDWRITING__) 
	::mmi_imm_handwriting_enable((MMI_BOOL)state);
#endif
    m_signalSwitchChange.postEmit();
}

void VappIMEswitchControl::emitSignal_Ext(VcpSwitch *sender, VfxBool state)
{
#if !defined(__MMI_NO_HANDWRITING__) 
	g_FollowKeyboard = state ;
	::mmi_imm_handwriting_set_follow_vk_lang((MMI_BOOL)g_FollowKeyboard);
#endif
    m_signalSwitchChange.postEmit();
}
#endif
/***************************************************************************** 
 * External Interfaces
 *****************************************************************************/
void VappSettingInputMethodEntry(VfxMainScr* screen)
{
    VappIMESettingMainPage *mainPage;
    if (screen != NULL)
    {
        VFX_OBJ_CREATE_EX(mainPage, VappIMESettingMainPage, screen, (screen));
        screen->pushPage(VFX_ID_NULL, mainPage);
    }
}


/***************************************************************************** 
 * Class VappIMESettingSwitch
 *****************************************************************************/
void VappIMESettingSwitch::setChecked(VfxBool checked, VfxBool isAnimated)
{
    m_switch->setChecked(checked, isAnimated);
}


void VappIMESettingSwitch::show()
{
    setHidden(VFX_FALSE);
    m_switch->setHidden(VFX_FALSE);
}

   
void VappIMESettingSwitch::hide()
{
    m_switch->setHidden(VFX_TRUE);
    setHidden(VFX_TRUE);
}


void VappIMESettingSwitch::onInit()
{
    VcpListMenuCellBaseControl::onInit();
    
    VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
    m_switch->setAnchor((VfxFloat)0.5, (VfxFloat)0.5);
    
    setSize(m_switch->getSize());
    
    m_switch->m_signalSwitchChanged.connect(this, &VappIMESettingSwitch::emitSignal);
}


void VappIMESettingSwitch::setBounds(const VfxRect &value)
{
    VcpListMenuCellBaseControl::setBounds(value);
    
    m_switch->setPos(getSize().width / 2, getSize().height / 2);
}


void VappIMESettingSwitch::emitSignal(VcpSwitch *sender, VfxBool state)
{
    m_signalSwitchChanged.emit(this, state);
}


/***************************************************************************** 
 * Class VappIMESettingMainPage
 *****************************************************************************/
VappIMESettingMainPage::VappIMESettingMainPage(VfxMainScr *mainScreen) :
    m_mainScreen(mainScreen),
    m_listMenu(NULL)
{
    // init the index array
    for (VfxS32 i = 0; i < VAPP_IME_SETTING_MAIN_MENU_ITEM_MAX_COUNT; i++)
    {
        m_itemIndexArray[i] = -1;
    }

    VfxS32 count = 0;
    VfxS32 index = 0;
    
    // conside the setting of prefered input method
#if defined(__MMI_PREFER_INPUT_METHOD__)
    mmi_imm_input_mode_enum noUse[IMM_INPUT_MODE_MAX_NUM];
    if (::mmi_imm_get_prefer_input_mode_list(noUse, IMM_INPUT_MODE_MAX_NUM) > 1)
    {
        m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD] = count;
        count++;
    }
#endif
    
    // conside the setting of writing language
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    index = 0;
    while (::g_ime_writing_lang_array[index].lang_id != IME_WRITING_LANG_123)
    {
        index++;
    }
    if (index > 1)
    {
        m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_WRITING_LANG] = count;
        count++;
    }
#endif

    // conside the setting of mixed language
#if defined(__MMI_MIXED_LANG_SUPPORT__)
    index = 0;
    while (::g_ime_writing_lang_array[index].lang_id != IME_WRITING_LANG_123)
    {
        index++;
    }
    if (index > 1)
    {
        m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG] = count;
        count++;
        m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG] = count;
        count++;
    }
#endif

    // conside the setting of the switch of smart input method
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
    m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_SMART_SWITCH] = count;
    count++;
#endif

    // consider the setting of speed of handwriting
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
    m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED] = count;
    count++;
#endif

    // conside the setting of advanced setting
#if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
    #if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__) || \
        defined (__MMI_IME_AUTO_COMPLETION_SETTING__) || \
        defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__) || \
        defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
    m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_ADVANCED] = count;
    count++;
    #endif
	#if defined (__MMI_QWERTY_KEYPAD_SUPPORT__) && \
		 defined (__MMI_COSMOS_KEYPAD_BAR__) && \
		 defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__) && \
        !defined (__MMI_IME_AUTO_COMPLETION_SETTING__) && \
        !defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__) && \
        !defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
       m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_ADVANCED] = -1;
       count--;
   #endif
#endif

    m_count = count;
}


VfxBool VappIMESettingMainPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD:
        #if defined(__MMI_PREFER_INPUT_METHOD__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_PREFERED_INPUT_METHOD);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                mmi_imm_input_mode_enum mode = ::mmi_imm_get_prefer_input_mode();
                VFX_ASSERT((mode > IMM_INPUT_MODE_NONE) && (mode < IMM_INPUT_MODE_MAX_NUM));
                for (VfxS32 index = 0; ::gIMEModeArray[index].imm_mode_id < IMM_INPUT_MODE_MAX_NUM; index++)
                {
                    if (::gIMEModeArray[index].imm_mode_id == mode)
                    {
                        text.loadFromRes(::gIMEModeArray[index].menuitem_string_id); 
                        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                        return VFX_TRUE;
                    }
                }
            }
        #endif
            break;
        
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_WRITING_LANG:
        #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_WRITING_LANGUAGE);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG:
        #if defined(__MMI_MIXED_LANG_SUPPORT__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_WRITING_LANGUAGE_MAIN);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                mmi_imm_support_writing_lang_enum lang = ::mmi_imm_get_main_lang();
                VFX_ASSERT((lang > IME_WRITING_LANG_NONE) && (lang < IME_WRITING_LANG_TOTAL));
                for (VfxS32 index = 0; ::g_ime_writing_lang_array[index].lang_id != IME_WRITING_LANG_NONE; index++)
                {
                    if (::g_ime_writing_lang_array[index].lang_id == lang)
                    {
                        text = VFX_WSTR_STATIC(::g_ime_writing_lang_array[index].lang_str_ptr); 
                        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                        return VFX_TRUE;
                    }
                }
            }
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG:
        #if defined(__MMI_MIXED_LANG_SUPPORT__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_WRITING_LANGUAGE_SUB);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                mmi_imm_support_writing_lang_enum lang = ::mmi_imm_get_sub_lang();
                VFX_ASSERT((lang >= IME_WRITING_LANG_NONE) && (lang < IME_WRITING_LANG_TOTAL));
                if (lang == IME_WRITING_LANG_NONE)
                {
                    text = VFX_WSTR_RES(STR_GLOBAL_NONE);
                    color = VCP_LIST_MENU_TEXT_COLOR_DISABLED;
                    return VFX_TRUE;
                }
                else
                {
                    for (VfxS32 index = 0; ::g_ime_writing_lang_array[index].lang_id != IME_WRITING_LANG_NONE; index++)
                    {
                        if (::g_ime_writing_lang_array[index].lang_id == lang)
                        {
                            text = VFX_WSTR_STATIC(::g_ime_writing_lang_array[index].lang_str_ptr); 
                            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                            return VFX_TRUE;
                        }
                    }
                }
            }
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SMART_SWITCH:
        #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            #if defined(__MMI_ZI__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_MENU_SET_ZI);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            #elif defined(__MMI_T9__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_MENU_SET_T9);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            } 
            #elif defined(__MMI_CSTAR__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_MENU_SET_CSTAR);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
             #elif defined(__MMI_GUOBI__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromMem((const VfxWChar*)L"Set Guobi");
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            #endif
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_ADVANCED:
        #if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_ADVANCED_OPTIONS);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED:
        #if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_HANDWRITING_SPEED);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                switch (::mmi_imm_get_pen_speed())
                {
                    case MMI_IMM_PEN_SPEED_SLOW:
                        text.loadFromRes(STR_GLOBAL_SLOW);
                        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                        return VFX_TRUE;

                        
                    case MMI_IMM_PEN_SPEED_MEDIUM:
                        text.loadFromRes(STR_GLOBAL_MEDIUM);
                        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                        return VFX_TRUE;

                        
                    case MMI_IMM_PEN_SPEED_FAST:
                        text.loadFromRes(STR_GLOBAL_FAST);
                        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                        return VFX_TRUE;

                }
            }
        #endif
            break;
    }

    return VFX_FALSE;
}


VfxU32 VappIMESettingMainPage::getCount() const
{
    return (VfxU32)m_count;
}


VcpListMenuCellBaseControl *VappIMESettingMainPage::getItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame)
{
    // construct the control for switch of smart input method
    if ((getMenuItem(index) == VAPP_IME_SETTING_MAIN_MENU_ITEM_SMART_SWITCH) &&
        (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL))
    {
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
        VappIMESettingSwitch *switchButton;
        VFX_OBJ_CREATE(switchButton, VappIMESettingSwitch, parentFrame);
        // connect the signal
        switchButton->m_signalSwitchChanged.connect(this, &VappIMESettingMainPage::changeSmartMethodState);

        // get the state of switch of smart input method
        if (::mmi_imm_is_smart_alphabetic_input_modes_enabled())
        {
            switchButton->setChecked(VFX_TRUE);
        }
        else
        {
            switchButton->setChecked(VFX_FALSE);
        }

        return switchButton;
    #endif
    }
    
    return NULL;
}


void VappIMESettingMainPage::closeItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VcpListMenuCellBaseControl *cellControl)
{
    if ((getMenuItem(index) == VAPP_IME_SETTING_MAIN_MENU_ITEM_SMART_SWITCH) &&
        (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL))
    {
        VFX_OBJ_CLOSE(cellControl);
    }
}


VcpListMenuCellClientBaseFrame *VappIMESettingMainPage::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    // construct the frame for the menu item of the one which need two lines
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED:
            VcpListMenuCellMultiTextFrame *frame;
            VFX_OBJ_CREATE(frame, VcpListMenuCellMultiTextFrame, parentFrame);
            return frame;
    }
    
    return NULL;
}


void VappIMESettingMainPage::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *cell)
{
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED:
           VFX_OBJ_CLOSE(cell);
           break;
    }
}


VfxBool VappIMESettingMainPage::getItemIsDisabled(VfxU32 index) const
{
    if (getMenuItem(index) == VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG)
    {
    #if defined(__MMI_MIXED_LANG_SUPPORT__)
        // if the main language does not support mixed language, disable the menu item of sub language
        mmi_imm_support_writing_lang_enum mainLang = ::mmi_imm_get_main_lang();
        VFX_ASSERT((mainLang > IME_WRITING_LANG_NONE) && (mainLang < IME_WRITING_LANG_TOTAL));

        VfxS32 i = 0;
        while (::g_ime_writing_lang_array[i].lang_id != mainLang)
        {
            i++;
        }

        if (::g_ime_writing_lang_array[i].mixed_lang_support)
        {
            return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }
    #else
        return VFX_TRUE;
    #endif
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappIMESettingMainPage::getItemIsHighlightable(VfxU32 index) const
{
    if (getMenuItem(index) == VAPP_IME_SETTING_MAIN_MENU_ITEM_SMART_SWITCH)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


VfxBool VappIMESettingMainPage::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_WRITING_LANG:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_ADVANCED:
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED:
            if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
            {
                image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
                return VFX_TRUE;
            }
            break; 
    }
    
    return VFX_FALSE;
}


void VappIMESettingMainPage::onInit()
{
    VfxPage::onInit();

    // show the state bar
    setStatusBar(VFX_TRUE);

    // set the title
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_INPUT_METHOD_SETTINGS));
    setTopBar(titleBar);

    // set the menu
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    
    m_listMenu->setPos(0, 0);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    
    m_listMenu->setContentProvider(this);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE, VFX_TRUE);

    // because there are one menu item which is two lines, so set the item height to be larger
    m_listMenu->setItemHeight(VAPP_IME_SETTING_PEN_SPEED_ITEM_HEIGHT);
    
    m_listMenu->m_signalItemTapped.connect(this, &VappIMESettingMainPage::enterNextPage);
}


void VappIMESettingMainPage::onEnter(VfxBool isBackward)
{
    if (isBackward == VFX_TRUE)
    {
        // update the show of the item which is two lines
    #if defined(__MMI_PREFER_INPUT_METHOD__)
        m_listMenu->updateItem(m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD]);
    #endif
    
    #if defined(__MMI_MIXED_LANG_SUPPORT__)
        m_listMenu->updateItem(m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG]);
        m_listMenu->updateItem(m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG]);
    #endif
    
    #if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
        m_listMenu->updateItem(m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED]);
    #endif
    }
}


VappIMESettingMainMenuItemEnum VappIMESettingMainPage::getMenuItem(VfxU32 index) const
{
    VfxS32 item;
    for (item = 0; item < VAPP_IME_SETTING_MAIN_MENU_ITEM_MAX_COUNT; item++)
    {
        if (m_itemIndexArray[item] == (VfxS32)index)
        {
            break;
        }
    }

    if (item == VAPP_IME_SETTING_MAIN_MENU_ITEM_MAX_COUNT)
    {
        VFX_ASSERT(0);
    }

    return (VappIMESettingMainMenuItemEnum)item;
}


void VappIMESettingMainPage::enterNextPage(VcpListMenu *menu, VfxU32 index)
{
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD:
        #if defined(__MMI_PREFER_INPUT_METHOD__)
            enterPreferedInputMethodSettingPage();
        #endif
            break;
        
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_WRITING_LANG:
        #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
            enterWritingLangSettingPage();
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG:
        #if defined(__MMI_MIXED_LANG_SUPPORT__)
            enterMainLangSettingPage();
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG:
        #if defined(__MMI_MIXED_LANG_SUPPORT__)
            enterSubLangSettingPage();
        #endif
            break;
        
        case VAPP_IME_SETTING_MAIN_MENU_ITEM_ADVANCED:
        #if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
            enterAdvancedSettingPage();
        #endif
            break;

        case VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED:
        #if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
            enterPenSpeedSettingPage();
        #endif
            break;
    }
}


void VappIMESettingMainPage::enterPreferedInputMethodSettingPage()
{
#if defined(__MMI_PREFER_INPUT_METHOD__)
    VappIMESettingPreferedInputMethodPage *methodPage;
    VFX_OBJ_CREATE_EX(methodPage, VappIMESettingPreferedInputMethodPage, m_mainScreen, (m_mainScreen));
    m_mainScreen->pushPage(VFX_ID_NULL, methodPage);
#endif
}


void VappIMESettingMainPage::enterWritingLangSettingPage()
{
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    VappIMESettingWritingLangPage *langPage;
    VFX_OBJ_CREATE_EX(langPage, VappIMESettingWritingLangPage, m_mainScreen, (m_mainScreen));
    m_mainScreen->pushPage(VFX_ID_NULL, langPage);
#endif
}


void VappIMESettingMainPage::enterMainLangSettingPage()
{
#if defined(__MMI_MIXED_LANG_SUPPORT__)
    VappIMESettingMainSubLangPage *langPage;
    VFX_OBJ_CREATE_EX(langPage, VappIMESettingMainSubLangPage, m_mainScreen, (m_mainScreen, VAPP_IME_SETTING_LANG_TYPE_MAIN));
    m_mainScreen->pushPage(VFX_ID_NULL, langPage);
#endif
}


void VappIMESettingMainPage::enterSubLangSettingPage()
{
#if defined(__MMI_MIXED_LANG_SUPPORT__)
    VappIMESettingMainSubLangPage *langPage;
    VFX_OBJ_CREATE_EX(langPage, VappIMESettingMainSubLangPage, m_mainScreen, (m_mainScreen, VAPP_IME_SETTING_LANG_TYPE_SUB));
    m_mainScreen->pushPage(VFX_ID_NULL, langPage);
#endif
}


void VappIMESettingMainPage::enterAdvancedSettingPage()
{
#if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
    VappIMESettingAdvancedPage *advancedPage;
    VFX_OBJ_CREATE_EX(advancedPage, VappIMESettingAdvancedPage, m_mainScreen, (m_mainScreen));
    m_mainScreen->pushPage(VFX_ID_NULL, advancedPage);
#endif
}


void VappIMESettingMainPage::enterPenSpeedSettingPage()
{
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
    VappIMESettingPenSpeedPage *penSpeedPage;
    VFX_OBJ_CREATE_EX(penSpeedPage, VappIMESettingPenSpeedPage, m_mainScreen, (m_mainScreen));
    m_mainScreen->pushPage(VFX_ID_NULL, penSpeedPage);
#endif
}


void VappIMESettingMainPage::changeSmartMethodState(VappIMESettingSwitch *sender, VfxBool state)
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
    if (state == VFX_TRUE)
    {
        ::mmi_imm_config_smart_alphabetic_input_modes(MMI_TRUE);
    }
    else
    {
        ::mmi_imm_config_smart_alphabetic_input_modes(MMI_FALSE);
        
        if ((::mmi_imm_get_input_mode_array_item(::mmi_imm_get_prefer_input_mode()))->Mode_Special_Attrib &
            IME_MODE_ATTR_SMART)
        {
            mmi_imm_input_mode_enum inputModeList[IMM_INPUT_MODE_MAX_NUM];
            ::mmi_imm_get_prefer_input_mode_list(inputModeList, IMM_INPUT_MODE_MAX_NUM);
            ::mmi_imm_set_prefer_input_mode(inputModeList[0]);
            ::mmi_imm_write_prefered_input_method_to_nvram(::mmi_imm_get_prefer_input_mode());

        #if defined(__MMI_PREFER_INPUT_METHOD__)
            m_listMenu->updateItem(m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD]);
        #endif
        }
    }
#endif
}


#if defined(__MMI_PREFER_INPUT_METHOD__)
/***************************************************************************** 
 * Class VappIMESettingPreferedInputMethodPage
 *****************************************************************************/
VappIMESettingPreferedInputMethodPage::VappIMESettingPreferedInputMethodPage(VfxMainScr *mainScreen) :
    m_mainScreen(mainScreen)
{
    m_count = ::mmi_imm_get_prefer_input_mode_list(m_inputModeList, IMM_INPUT_MODE_MAX_NUM);
    ::mmi_imm_get_prefer_input_mode_string_list(m_inputModeStrList, IMM_INPUT_MODE_MAX_NUM);
}


VfxBool VappIMESettingPreferedInputMethodPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if ((index < (VfxU32)m_count) && (fieldType == VCP_LIST_MENU_FIELD_TEXT))
    {
        text = VFX_WSTR_STATIC((VfxWChar*)m_inputModeStrList[index]);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}


VfxU32 VappIMESettingPreferedInputMethodPage::getCount() const
{
    return (VfxU32)m_count;
}


VcpListMenuItemStateEnum VappIMESettingPreferedInputMethodPage::getItemState(VfxU32 index) const
{
    if (index < (VfxU32)m_count)
    {
        if (m_inputModeList[index] == ::mmi_imm_get_prefer_input_mode())
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


void VappIMESettingPreferedInputMethodPage::onInit()
{
    VfxPage::onInit();
    
    // show the state bar
    setStatusBar(VFX_TRUE);

    // set the title
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_INPUT_METHOD_PREFERED_INPUT_METHOD));
    setTopBar(titleBar);

    // set the menu
    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);

    menu->setPos(0, 0);
    menu->setSize(getSize());
    menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    menu->setContentProvider(this);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);

    menu->m_signalItemTapped.connect(this, &VappIMESettingPreferedInputMethodPage::setInputMethodAndClose);
}


void VappIMESettingPreferedInputMethodPage::setInputMethodAndClose(VcpListMenu *menu, VfxU32 index)
{
    if (index < (VfxU32)m_count)
    {
        ::mmi_imm_set_prefer_input_mode(m_inputModeList[index]);
        ::mmi_imm_write_prefered_input_method_to_nvram(::mmi_imm_get_prefer_input_mode());
    }

    m_mainScreen->popPage();
}
#endif /* defined(__MMI_PREFER_INPUT_METHOD__) */


#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
/***************************************************************************** 
 * Class VappIMESettingWritingLangPage
 *****************************************************************************/
VappIMESettingWritingLangPage::VappIMESettingWritingLangPage(VfxMainScr *mainScreen) :
    m_mainScreen(mainScreen)
{
    VfxS32 index = 0;
    while (::g_ime_writing_lang_array[index].lang_id != IME_WRITING_LANG_123)
    {
        if (::g_ime_writing_lang_array[index].enabled)
        {
            m_enabled[index] = VFX_TRUE;
        }
        else
        {
            m_enabled[index] = VFX_FALSE;
        }
        
        index++;
    }

    m_count = index;
}


VfxBool VappIMESettingWritingLangPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if ((index < (VfxU32)m_count) && (fieldType == VCP_LIST_MENU_FIELD_TEXT))
    {
        text = VFX_WSTR_STATIC(::g_ime_writing_lang_array[index].lang_str_ptr);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}


VfxU32 VappIMESettingWritingLangPage::getCount() const
{
    return (VfxU32)m_count;
}


VfxBool VappIMESettingWritingLangPage::getItemIsDisabled(VfxU32 index) const
{
    if (index < (VfxU32)m_count)
    {
        // the language can not be un-selected
        if (::g_ime_writing_lang_array[index].lang_id == IME_WRITING_LANG_ABC)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }

    return VFX_FALSE;
}


VcpListMenuItemStateEnum VappIMESettingWritingLangPage::getItemState(VfxU32 index) const
{
    if (index < (VfxU32)m_count)
    {
        if (m_enabled[index] == VFX_TRUE)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


void VappIMESettingWritingLangPage::onInit()
{
    VfxPage::onInit();
    
    // show the state bar
    setStatusBar(VFX_TRUE);

    // set the title
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
#ifdef __MMI_IME_V3__
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_ML_SETTING));
#else
    titleBar->setTitle(VFX_WSTR_RES(STR_INPUT_METHOD_WRITING_LANGUAGE));
#endif
    setTopBar(titleBar);

    // set the button bar
    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem((VfxId)0, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem((VfxId)1, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolBar->m_signalButtonTap.connect(this, &VappIMESettingWritingLangPage::processButtonClicked);
    setBottomBar(toolBar);
    
    // set the menu
    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);

    menu->setPos(0, 0);
    menu->setSize(getSize());
    menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    menu->setContentProvider(this);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
    menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);

    menu->m_signalItemSelectionStateChanged.connect(this, &VappIMESettingWritingLangPage::processStateChanged);
}


void VappIMESettingWritingLangPage::processButtonClicked(VfxObject *sender, VfxId buttonId)
{
    if (buttonId == (VfxId)0)
    {
        // for perfermance, access NVRAM directly
        for (VfxS32 index = 0; index < m_count; index++)
        {
            if (m_enabled[index] == VFX_TRUE)
            {
                ::g_ime_writing_lang_array[index].enabled = MMI_TRUE;
                ::g_mmi_imm_enabled_writing_language |=  (1 << (15 - index));
            }
            else
            {
                ::g_ime_writing_lang_array[index].enabled = MMI_FALSE;
                ::g_mmi_imm_enabled_writing_language &= (~(1 << (15 - index)));
            }
        }
        // write to NVRAM
        VfxU32 data = ::g_mmi_imm_enabled_writing_language;
        VfxS16 error;
        WriteValue((U16)NVRAM_SETTING_ENABLED_WRITING_LANGUAGE, (void*)&data, (U8)DS_SHORT, (S16*)&error);

    #if defined(__MMI_MIXED_LANG_SUPPORT__)
        // check whether current main lang is disabled
        mmi_imm_support_writing_lang_enum mainLang = ::mmi_imm_get_main_lang();
        VFX_ASSERT((mainLang > IME_WRITING_LANG_NONE) && (mainLang < IME_WRITING_LANG_TOTAL));

        VfxS32 index = 0;
        while (::g_ime_writing_lang_array[index].lang_id != mainLang)
        {
            index++;
        }

        if (!(::g_ime_writing_lang_array[index].enabled))
        {
            // change language to be english
            mmi_imm_support_writing_lang_enum lang = IME_WRITING_LANG_ABC;
            ::mmi_imm_set_main_lang(lang);
            ::WriteValue((U16)NVRAM_SETTING_WRITING_LANG, (void*)&lang, (U8)DS_SHORT, (S16*)&error);

            index = 0;
            while (::g_ime_writing_lang_array[index].lang_id != lang)
            {
                index++;
            }
            mmi_imm_input_mode_enum inputMode = ::g_ime_writing_lang_array[index].default_input_mode;
            ::mmi_imm_set_prefer_input_mode(inputMode);
            ::WriteValue((U16)NVRAM_SETTING_PREFER_INPUT_METHOD, (void*)&inputMode, (U8)DS_SHORT, (S16*)&error);
        }

        // check whether current sub lang is disabled
        mmi_imm_support_writing_lang_enum subLang = ::mmi_imm_get_sub_lang();
        VFX_ASSERT((subLang >= IME_WRITING_LANG_NONE) && (subLang < IME_WRITING_LANG_TOTAL));

        if (subLang != IME_WRITING_LANG_NONE)
        {
            index = 0;
            while (::g_ime_writing_lang_array[index].lang_id != subLang)
            {
                index++;
            }

            if (!(::g_ime_writing_lang_array[index].enabled))
            {
                subLang = IME_WRITING_LANG_NONE;
                ::mmi_imm_set_sub_lang(subLang);
                ::WriteValue((U16)NVRAM_SETTING_WRITING_LANG_SUB, (void*)&subLang, (U8)DS_SHORT, (S16*)&error);
            }
        }
    #endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */
    }

    m_mainScreen->popPage();
}


void VappIMESettingWritingLangPage::processStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum state)
{
    if (index < (VfxU32)m_count)
    {
        if (state == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            m_enabled[index] = VFX_FALSE;
        }
        else if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            m_enabled[index] = VFX_TRUE;
        }
    }
}

#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */


#if defined(__MMI_MIXED_LANG_SUPPORT__)
/***************************************************************************** 
 * Class VappIMESettingMainSubLangPage
 *****************************************************************************/
VappIMESettingMainSubLangPage::VappIMESettingMainSubLangPage(VfxMainScr *mainScreen, VappIMESettingLangTypeEnum type) :
    m_mainScreen(mainScreen),
    m_type(type)
{
    if (m_type == VAPP_IME_SETTING_LANG_TYPE_MAIN)
    {
        m_count = 0;
        for (VfxS32 index = 0; ::g_ime_writing_lang_array[index].lang_id != IME_WRITING_LANG_123; index++)
        {
            if (::g_ime_writing_lang_array[index].enabled)
            {
                m_indexArray[m_count++] = index;
            }
        }
    }
    else if (m_type == VAPP_IME_SETTING_LANG_TYPE_SUB)
    {
        VfxS32 index = 0;
        mmi_imm_support_writing_lang_enum mainLang = ::mmi_imm_get_main_lang();
        VFX_ASSERT((mainLang > IME_WRITING_LANG_NONE) && (mainLang < IME_WRITING_LANG_TOTAL));
        
        while (::g_ime_writing_lang_array[index].lang_id != mainLang)
        {
            index++;
        }

        if (::g_ime_writing_lang_array[index].mixed_lang_support)
        {
            m_count = 0;
            for (VfxS32 i = 0; ::g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_123; i++)
            {
                if ((::g_ime_writing_lang_array[i].enabled) && (::g_ime_writing_lang_array[i].mixed_lang_support))
                {
                    m_indexArray[m_count++] = i;
                }
            }

            // add one item to show None
            m_count++;
        }
        else
        {
            m_count = 0;
        }
    }
    else
    {
        VFX_ASSERT(0);
    }
}


VfxBool VappIMESettingMainSubLangPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (index < (VfxU32)m_count)
    {
        if (m_type == VAPP_IME_SETTING_LANG_TYPE_MAIN)
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text = VFX_WSTR_STATIC(::g_ime_writing_lang_array[m_indexArray[index]].lang_str_ptr);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
        }
        else
        {
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                // the first item of sub language is None
                if (index == 0)
                {
                    text = VFX_WSTR_RES(STR_GLOBAL_NONE);
                    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                    return VFX_TRUE;
                }
                else
                {
                    text = VFX_WSTR_STATIC(::g_ime_writing_lang_array[m_indexArray[index - 1]].lang_str_ptr);
                    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                    return VFX_TRUE;
                }
            }
        }
    }
    
    return VFX_FALSE;
}


VfxU32 VappIMESettingMainSubLangPage::getCount() const
{
    return (VfxU32)m_count;
}


VcpListMenuItemStateEnum VappIMESettingMainSubLangPage::getItemState(VfxU32 index) const
{
    if (index < (VfxU32)m_count)
    {
        if (m_type == VAPP_IME_SETTING_LANG_TYPE_MAIN)
        {
            mmi_imm_support_writing_lang_enum lang = ::mmi_imm_get_main_lang();
            VFX_ASSERT((lang > IME_WRITING_LANG_NONE) && (lang < IME_WRITING_LANG_TOTAL));
            if (::g_ime_writing_lang_array[m_indexArray[index]].lang_id == lang)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            else
            {
                return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }
        }
        else
        {
            // the sub language may be none
            mmi_imm_support_writing_lang_enum lang = ::mmi_imm_get_sub_lang();
            VFX_ASSERT((lang >= IME_WRITING_LANG_NONE) && (lang < IME_WRITING_LANG_TOTAL));
            if (lang == IME_WRITING_LANG_NONE)
            {
                if (index == 0)
                {
                    return VCP_LIST_MENU_ITEM_STATE_SELECTED;
                }
                else
                {
                    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
                }
            }
            else
            {
                if (index == 0)
                {
                    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
                }
                else
                {
                    if (::g_ime_writing_lang_array[m_indexArray[index - 1]].lang_id == lang)
                    {
                        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
                    }
                    else
                    {
                        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
                    }
                }
            }
        }
    }
    
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


void VappIMESettingMainSubLangPage::onInit()
{
    VfxPage::onInit();
    
    // show the state bar
    setStatusBar(VFX_TRUE);

    // set the title
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    if (m_type == VAPP_IME_SETTING_LANG_TYPE_MAIN)
    {
        titleBar->setTitle(VFX_WSTR_RES(STR_WRITING_LANGUAGE_MAIN));
    }
    else
    {
        titleBar->setTitle(VFX_WSTR_RES(STR_WRITING_LANGUAGE_SUB));
    }
    setTopBar(titleBar);

    // set the menu
    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);

    menu->setPos(0, 0);
    menu->setSize(getSize());
    menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    menu->setContentProvider(this);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);

    menu->m_signalItemTapped.connect(this, &VappIMESettingMainSubLangPage::setLangAndClose);
}


void VappIMESettingMainSubLangPage::setLangAndClose(VcpListMenu *menu, VfxU32 index)
{
    if (index < (VfxU32)m_count)
    {
        if (m_type == VAPP_IME_SETTING_LANG_TYPE_MAIN)
        {
            // save the main language
            VfxS16 error;
            
            mmi_imm_support_writing_lang_enum mainLang = ::g_ime_writing_lang_array[m_indexArray[index]].lang_id;
            ::mmi_imm_set_main_lang(mainLang);
            ::WriteValue((U16)NVRAM_SETTING_WRITING_LANG, (void*)&mainLang, (U8)DS_SHORT, (S16*)&error);
            
            mmi_imm_input_mode_enum inputMode = ::g_ime_writing_lang_array[m_indexArray[index]].default_input_mode;
            ::mmi_imm_set_prefer_input_mode(inputMode);
            ::WriteValue((U16)NVRAM_SETTING_PREFER_INPUT_METHOD, (void*)&inputMode, (U8)DS_SHORT, (S16*)&error);

            // check whether current main language support mixed language
            if (!(::g_ime_writing_lang_array[m_indexArray[index]].mixed_lang_support))
            {
                mmi_imm_support_writing_lang_enum subLang = IME_WRITING_LANG_NONE;
                ::mmi_imm_set_sub_lang(subLang);
                ::WriteValue((U16)NVRAM_SETTING_WRITING_LANG_SUB, (void*)&subLang, (U8)DS_SHORT, (S16*)&error);
            }
        }
        else
        {
            // save the sub language
            VfxS16 error;
            
            mmi_imm_support_writing_lang_enum subLang;
            if (index == 0)
            {
                subLang = IME_WRITING_LANG_NONE;
            }
            else
            {
                subLang = ::g_ime_writing_lang_array[m_indexArray[index - 1]].lang_id;
            }
            ::mmi_imm_set_sub_lang(subLang);
            ::WriteValue((U16)NVRAM_SETTING_WRITING_LANG_SUB, (void*)&subLang, (U8)DS_SHORT, (S16*)&error);
        }
    }

    m_mainScreen->popPage();
}

#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */


#if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
/***************************************************************************** 
 * Class VappIMESettingAdvancedPage
 *****************************************************************************/
VappIMESettingAdvancedPage::VappIMESettingAdvancedPage(VfxMainScr *mainScreen) :
    m_mainScreen(mainScreen)
{
    // init the index array
    for (VfxS32 i = 0; i < VAPP_IME_SETTING_ADVANCED_MENU_ITEM_MAX_COUNT; i++)
    {
        m_itemIndexArray[i] = -1;
    }

    VfxS32 count = 0;
    
    // conside the setting of auto capitalization
#if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
	if (mmi_imm_memory_card_is_auto_capitalization_enabled())
	{
    m_itemIndexArray[VAPP_IME_SETTING_ADVANCED_MENU_ITEM_CAPITALIZATION] = count;
    count++;
	}
#endif

    // conside the setting of auto completion
#if defined (__MMI_IME_AUTO_COMPLETION_SETTING__)
    m_itemIndexArray[VAPP_IME_SETTING_ADVANCED_MENU_ITEM_COMPLETION] = count;
    count++;
#endif

    // conside the setting of phonetic prediction
#if defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__)
    m_itemIndexArray[VAPP_IME_SETTING_ADVANCED_MENU_ITEM_PHONETIC_PREDICT] = count;
    count++;
#endif

    // consider the setting of alphabetic prediction
#if defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
    m_itemIndexArray[VAPP_IME_SETTING_ADVANCED_MENU_ITEM_ALPHABETIC_PREDICT] = count;
    count++;
#endif
	#if defined (__MMI_QWERTY_KEYPAD_SUPPORT__) && \
		 defined (__MMI_COSMOS_KEYPAD_BAR__) && \
		 defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__) 
		if (mmi_imm_memory_card_is_auto_capitalization_enabled())
		{
			m_itemIndexArray[VAPP_IME_SETTING_ADVANCED_MENU_ITEM_CAPITALIZATION] = -1;
			count--;   
		}
	#endif
    m_count = count;
}


VfxBool VappIMESettingAdvancedPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_CAPITALIZATION:
        #if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
		if (mmi_imm_memory_card_is_auto_capitalization_enabled())
		{
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_AUTO_CAPITALIZATION);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
		}
        #endif
            break;

        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_COMPLETION:
        #if defined (__MMI_IME_AUTO_COMPLETION_SETTING__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_AUTO_COMPLETION);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
        #endif
            break;

        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_PHONETIC_PREDICT:
        #if defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_CHINESE_PREDICTION);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
        #endif
            break;

        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_ALPHABETIC_PREDICT:
        #if defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_INPUT_METHOD_ALPHABETIC_PREDICTION);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
        #endif
            break;
    }

    return VFX_FALSE;
}


VfxU32 VappIMESettingAdvancedPage::getCount() const
{
    return (VfxU32)m_count;
}


VfxBool VappIMESettingAdvancedPage::getItemIsHighlightable(VfxU32 index) const
{
    return VFX_FALSE;
}


VcpListMenuCellBaseControl *VappIMESettingAdvancedPage::getItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame)
{
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_CAPITALIZATION:
        #if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
			if (mmi_imm_memory_card_is_auto_capitalization_enabled())
			{
            if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
            {
                VappIMESettingSwitch *switchButton;
                VFX_OBJ_CREATE(switchButton, VappIMESettingSwitch, parentFrame);
                // connect the signal
                switchButton->m_signalSwitchChanged.connect(this, &VappIMESettingAdvancedPage::changeAutoCapitalizationState);

                // get the state of switch of smart input method
                if (::mmi_imm_is_auto_capitalization_enabled())
                {
                    switchButton->setChecked(VFX_TRUE);
                }
                else
                {
                    switchButton->setChecked(VFX_FALSE);
                }

                return switchButton;
            }
			}
        #endif
            break;

        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_COMPLETION:
        #if defined (__MMI_IME_AUTO_COMPLETION_SETTING__)
            if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
            {
                VappIMESettingSwitch *switchButton;
                VFX_OBJ_CREATE(switchButton, VappIMESettingSwitch, parentFrame);
                // connect the signal
                switchButton->m_signalSwitchChanged.connect(this, &VappIMESettingAdvancedPage::changeAutoCompletionState);

                // get the state of switch of smart input method
                if (::mmi_imm_is_auto_completion_enabled())
                {
                    switchButton->setChecked(VFX_TRUE);
                }
                else
                {
                    switchButton->setChecked(VFX_FALSE);
                }

                return switchButton;
            }
        #endif
            break;

        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_PHONETIC_PREDICT:
        #if defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__)
            if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
            {
                VappIMESettingSwitch *switchButton;
                VFX_OBJ_CREATE(switchButton, VappIMESettingSwitch, parentFrame);
                // connect the signal
                switchButton->m_signalSwitchChanged.connect(this, &VappIMESettingAdvancedPage::changePhoneticPredictState);

                // get the state of switch of smart input method
                if (::mmi_imm_is_chinese_word_prediction_enabled())
                {
                    switchButton->setChecked(VFX_TRUE);
                }
                else
                {
                    switchButton->setChecked(VFX_FALSE);
                }

                return switchButton;
            }
        #endif
            break;

        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_ALPHABETIC_PREDICT:
        #if defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
            if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
            {
                VappIMESettingSwitch *switchButton;
                VFX_OBJ_CREATE(switchButton, VappIMESettingSwitch, parentFrame);
                // connect the signal
                switchButton->m_signalSwitchChanged.connect(this, &VappIMESettingAdvancedPage::changeAlphabeticPredictState);

                // get the state of switch of smart input method
                if (::mmi_imm_is_alphabetic_word_prediction_enabled())
                {
                    switchButton->setChecked(VFX_TRUE);
                }
                else
                {
                    switchButton->setChecked(VFX_FALSE);
                }

                return switchButton;
            }
        #endif
            break;
    }

    return NULL;
}


void VappIMESettingAdvancedPage::closeItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VcpListMenuCellBaseControl *cellControl)
{
    switch (getMenuItem(index))
    {
        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_CAPITALIZATION:
        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_COMPLETION:
        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_PHONETIC_PREDICT:
        case VAPP_IME_SETTING_ADVANCED_MENU_ITEM_ALPHABETIC_PREDICT:
            if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
            {
                VFX_OBJ_CLOSE(cellControl);
            }
            break;
    }
}


void VappIMESettingAdvancedPage::onInit()
{
    VfxPage::onInit();
    
    // show the state bar
    setStatusBar(VFX_TRUE);

    // set the title
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_INPUT_METHOD_ADVANCED_OPTIONS));
    setTopBar(titleBar);

    // set the menu
    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);

    menu->setPos(0, 0);
    menu->setSize(getSize());
    menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    menu->setContentProvider(this);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
}


VappIMESettingAdvancedMenuItemEnum VappIMESettingAdvancedPage::getMenuItem(VfxU32 index) const
{
    VfxS32 item;
    for (item = 0; item < VAPP_IME_SETTING_ADVANCED_MENU_ITEM_MAX_COUNT; item++)
    {
        if (m_itemIndexArray[item] == (VfxS32)index)
        {
            break;
        }
    }

    if (item == VAPP_IME_SETTING_ADVANCED_MENU_ITEM_MAX_COUNT)
    {
        VFX_ASSERT(0);
    }

    return (VappIMESettingAdvancedMenuItemEnum)item;
}


void VappIMESettingAdvancedPage::changeAutoCapitalizationState(VappIMESettingSwitch *sender, VfxBool state)
{
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
	if (mmi_imm_memory_card_is_auto_capitalization_enabled())
	{
    if (state == VFX_TRUE)
    {
        ::mmi_imm_config_auto_capitalization(MMI_TRUE);
    }
    else
    {
        ::mmi_imm_config_auto_capitalization(MMI_FALSE);

        if ((::mmi_imm_get_input_mode_array_item(::mmi_imm_get_prefer_input_mode()))->Mode_Special_Attrib &
            IME_MODE_ATTR_TITLECASE)
        {
            mmi_imm_input_mode_enum inputModeList[IMM_INPUT_MODE_MAX_NUM];
            ::mmi_imm_get_prefer_input_mode_list(inputModeList, IMM_INPUT_MODE_MAX_NUM);
            ::mmi_imm_set_prefer_input_mode(inputModeList[0]);
            ::mmi_imm_write_prefered_input_method_to_nvram(::mmi_imm_get_prefer_input_mode());
        }
    }
	}
#endif
}


void VappIMESettingAdvancedPage::changeAutoCompletionState(VappIMESettingSwitch *sender, VfxBool state)
{
#if defined(__MMI_IME_AUTO_COMPLETION_SETTING__)
    if (state == VFX_TRUE)
    {
        ::mmi_imm_config_auto_completion(MMI_TRUE);
    }
    else
    {
        ::mmi_imm_config_auto_completion(MMI_FALSE);
    }
#endif
}


void VappIMESettingAdvancedPage::changePhoneticPredictState(VappIMESettingSwitch *sender, VfxBool state)
{
#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
    if (state == VFX_TRUE)
    {
        ::mmi_imm_config_chinese_word_prediction(MMI_TRUE);
    }
    else
    {
        ::mmi_imm_config_chinese_word_prediction(MMI_FALSE);
    }
#endif
}


void VappIMESettingAdvancedPage::changeAlphabeticPredictState(VappIMESettingSwitch *sender, VfxBool state)
{
#if defined(__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
    if (state == VFX_TRUE)
    {
        ::mmi_imm_config_alphabetic_word_prediction(MMI_TRUE);
    }
    else
    {
        ::mmi_imm_config_alphabetic_word_prediction(MMI_FALSE);
    }
#endif
}

#endif /* defined(__MMI_IME_INPUT_ADVANCED_SETTING__) */


#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
/***************************************************************************** 
 * Class VappIMESettingPenSpeedPage
 *****************************************************************************/
VappIMESettingPenSpeedPage::VappIMESettingPenSpeedPage(VfxMainScr *mainScreen) :
    m_mainScreen(mainScreen)
{
}


VfxBool VappIMESettingPenSpeedPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    switch ((VappIMESettingPenSpeedMenuItemEnum)index)
    {
        case VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_SLOW:
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_GLOBAL_SLOW);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            break;

        case VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_MEDIUM:
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_GLOBAL_MEDIUM);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            break;

        case VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_FAST:
            if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text.loadFromRes(STR_GLOBAL_FAST);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            break;
    }

    return VFX_FALSE;
}


VfxU32 VappIMESettingPenSpeedPage::getCount() const
{
    return (VfxU32)VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_MAX_COUNT;
}


VcpListMenuItemStateEnum VappIMESettingPenSpeedPage::getItemState(VfxU32 index) const
{
    switch (::mmi_imm_get_pen_speed())
    {
        case MMI_IMM_PEN_SPEED_SLOW:
            if ((VappIMESettingPenSpeedMenuItemEnum)index == VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_SLOW)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            else
            {
                return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }

            
        case MMI_IMM_PEN_SPEED_MEDIUM:
            if ((VappIMESettingPenSpeedMenuItemEnum)index == VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_MEDIUM)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            else
            {
                return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }

            
        case MMI_IMM_PEN_SPEED_FAST:
            if ((VappIMESettingPenSpeedMenuItemEnum)index == VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_FAST)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            else
            {
                return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
            }

    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


void VappIMESettingPenSpeedPage::onInit()
{
    VfxPage::onInit();
    
    // show the state bar
    setStatusBar(VFX_TRUE);

    // set the title
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_INPUT_METHOD_HANDWRITING_SPEED));
    setTopBar(titleBar);

    // set the menu
    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);

    menu->setPos(0, 0);
    menu->setSize(getSize());
    menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    menu->setContentProvider(this);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);

    menu->m_signalItemTapped.connect(this, &VappIMESettingPenSpeedPage::setSpeedAndClose);
}


void VappIMESettingPenSpeedPage::setSpeedAndClose(VcpListMenu *menu, VfxU32 index)
{
    switch ((VappIMESettingPenSpeedMenuItemEnum)index)
    {
        case VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_SLOW:
            ::mmi_imm_set_pen_speed(MMI_IMM_PEN_SPEED_SLOW);
            break;
            
        case VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_MEDIUM:
            ::mmi_imm_set_pen_speed(MMI_IMM_PEN_SPEED_MEDIUM);
            break;
            
        case VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_FAST:
            ::mmi_imm_set_pen_speed(MMI_IMM_PEN_SPEED_FAST);
            break;
    }

#if defined(__MMI_IME_V3__)
    getMainScr()->popPage();
#else
    m_mainScreen->popPage();
#endif
}

#endif /* defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__) */

