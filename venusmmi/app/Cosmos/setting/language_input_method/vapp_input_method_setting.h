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
 *  vapp_input_method_setting.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  The header file of the setting for input method
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_INPUT_METHOD_SETTING_H__
#define __VAPP_INPUT_METHOD_SETTING_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
    #include "MMI_features.h"
    #include "IMERes.h"
	#include "Imc_config.h"
    #include "ImeGprotEnums.h"
}
#include "vfx_uc_include.h"
#include "vcp_list_menu.h"
#include "vfx_page.h"
#include "vcp_switch.h"
#include "vcp_input_popup.h"
#if defined(__MMI_IME_V3__)
#include "vcp_include.h"
#endif

/***************************************************************************** 
 * Defination
 *****************************************************************************/
#define VAPP_IME_SETTING_WRITING_LANG_MAX_NUM   MAX_WRITING_LANG


/***************************************************************************** 
 * Enum
 *****************************************************************************/
// <group DOM_InputMethodSetting_Enum>
// use to record the main menu item
enum VappIMESettingMainMenuItemEnum
{
    VAPP_IME_SETTING_MAIN_MENU_ITEM_PREFERED_INPUT_METHOD = 0,
    VAPP_IME_SETTING_MAIN_MENU_ITEM_WRITING_LANG,
    VAPP_IME_SETTING_MAIN_MENU_ITEM_MAIN_LANG,
    VAPP_IME_SETTING_MAIN_MENU_ITEM_SUB_LANG,
    VAPP_IME_SETTING_MAIN_MENU_ITEM_SMART_SWITCH,
    VAPP_IME_SETTING_MAIN_MENU_ITEM_SPEED,
    VAPP_IME_SETTING_MAIN_MENU_ITEM_ADVANCED,
    VAPP_IME_SETTING_MAIN_MENU_ITEM_MAX_COUNT
};

#if defined(__MMI_IME_V3__)
typedef enum
{
	VAPP_IME_COLOR_WHITE ,
	VAPP_IME_COLOR_RED ,
	VAPP_IME_COLOR_YELLOW ,
	VAPP_IME_COLOR_GREEN ,
	VAPP_IME_COLOR_NONE
}VappIMEv3ColorEnum ;
#endif

// <group DOM_InputMethodSetting_Enum>
// the setting is main language or sub language
enum VappIMESettingLangTypeEnum
{
    VAPP_IME_SETTING_LANG_TYPE_MAIN = 0,
    VAPP_IME_SETTING_LANG_TYPE_SUB
};


// <group DOM_InputMethodSetting_Enum>
// use to record the advanced menu item
enum VappIMESettingAdvancedMenuItemEnum
{
    VAPP_IME_SETTING_ADVANCED_MENU_ITEM_CAPITALIZATION = 0,
    VAPP_IME_SETTING_ADVANCED_MENU_ITEM_COMPLETION,
    VAPP_IME_SETTING_ADVANCED_MENU_ITEM_PHONETIC_PREDICT,
    VAPP_IME_SETTING_ADVANCED_MENU_ITEM_ALPHABETIC_PREDICT,
    VAPP_IME_SETTING_ADVANCED_MENU_ITEM_MAX_COUNT
};


// <group DOM_InputMethodSetting_Enum>
// use to record the handwriting pen speed menu item
enum VappIMESettingPenSpeedMenuItemEnum
{
    VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_SLOW = 0,
    VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_MEDIUM,
    VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_FAST,
    VAPP_IME_SETTING_PEN_SPEED_MENU_ITEM_MAX_COUNT
};


#if defined(__MMI_IME_V3__)

enum VappIMEv3AdvanceSettingEnum
{
	VAPP_IME_MENU_ITEM_AUTO_SPACE_SETTING = 0 ,
	VAPP_IME_MENU_ITEM_AUTO_CAPITALIZATION_SETTING ,
	VAPP_IME_MENU_ITEM_ASSOCIATION_SETTING ,
	VAPP_IME_MENU_ITEM_FUZZY_PINYIN_SETTING ,
	VAPP_IME_MENU_ITEM_TOUCH_FEEDBACK_SETTING,
	VAPP_IME_MENU_ITEM_ADVANCE_SETTING_MAX_COUNT
};

enum VappIMEv3HandwritingSettingEnum
{
	VAPP_IME_MENU_ITEM_STROKE_COLOR_SETTING = 0,
	VAPP_IME_MENU_ITEM_HANDWRITING_SPEED_SETTING,
	VAPP_IME_MENU_ITEM_HANDWRITING_TRACE_WIDTH_SETTING,
	VAPP_IME_MENU_ITEM_HANDWRITING_LANGUAGE_SETTING,
	VAPP_IME_MENU_ITEM_HANDWRITING_SETTING_MAX_COUNT
};

#define MAX_INPUT_POPUP 3
class VappIMEv3SettingMainPage ;
/***************************************************************************** 
 * Class VappIMEv3SettingsMainPage
 *****************************************************************************/
class VappIMEv3SettingMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappIMEv3SettingMainPage);

public:
	VcpTitleBar *m_tiltebar;
	VcpForm *m_form ;
	VcpInputPopup *m_ActivePopup[MAX_INPUT_POPUP]  ;

	enum
	{
		INPUT_ML_SETTING = 0,
		INPUT_AD_SETTING,
		INPUT_HW_SETTING
	};
	
    VappIMEv3SettingMainPage();
	
    virtual void onInit(void);
    virtual void onExit(VfxBool isBackward);
protected:
	virtual VfxBool onKeyInput(VfxKeyEvent& event);

private:
    void drawMainPage(void);
    void onTapMenuHandler(VcpFormItemCell* sender, VfxId Id);


};
class VappIMEv3AdvanceSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappIMEv3AdvanceSettingPage);


// Variable
private: 
	VcpTitleBar * m_titleBar;
	VcpGroupListMenu *m_groupList;
	VfxS32 m_setUpdate;

public:
VappIMEv3AdvanceSettingPage()
{

}

	enum
	{
		VIME_AUTO_SPACE = 0,
		#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
			VIME_AUTO_CAP,
		#endif
		#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
			VIME_ASSOCIATION,
		#endif
		#if defined(__MMI_IME_FUZZY_PINYIN__)
			VIME_FUZZY_PINYIN,
		#endif
			VIME_MAX_COUNT
	};

// Override
public:
    virtual void onInit();
	virtual void onDeinit();
	VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
// Method
public:
	// <group DOM_VappMMSSettingPage_Method>
    // Refresh list if something is changed on page
	void onSettingRefresh(VcpGroupListMenu *menu, VcpMenuPos pos);

void onAutoSpaceSettingChanged(VcpFormItemSwitchCell * cell, VfxId id, VfxBool isOn);

#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
void onAutoCapSettingChanged(VcpFormItemSwitchCell * cell, VfxId id, VfxBool isOn);
#endif

#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
void onAssociationSettingChanged(VcpFormItemSwitchCell * cell, VfxId id, VfxBool isOn);
#endif

#if defined(__MMI_IME_FUZZY_PINYIN__)
void onFuzzyCellTapped(VcpFormItemCell * cell, VfxId id);
#endif

};


#if !defined(__MMI_NO_HANDWRITING__)

class VappIMEv3HWSettingContentProvider ;
class VappIMEv3HWSettingPage : public VfxPage, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappIMEv3HWSettingPage);


// Variable
private: 
	VcpTitleBar * m_titleBar;
	VcpGroupListMenu *m_groupList;
	VappIMEv3HWSettingContentProvider *m_listMenuContentProvider;
	VfxS32 m_setUpdate;

public:
VappIMEv3HWSettingPage()
{

}
// Override
public:
    virtual void onInit();
	virtual void onDeinit();
	VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
// Method
public:
	// <group DOM_VappMMSSettingPage_Method>
    // Refresh list if something is changed on page
	void onSettingRefresh(VcpGroupListMenu *menu, VcpMenuPos pos);

	// <group DOM_VappMMSSettingPage_Method>
    // Hanlde tap event on page list
	void onTapItem(VcpGroupListMenu *listMenu, VcpMenuPos pos);
	//static void VappMMSSettingPage::setResponseHandler(srv_mms_result_enum result, void *rsp_data, void* user_data);
	virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos  // [IN]  The position of the item
        ) const;

	//virtual void updateAllItems(); 
void onItemTap(VcpGroupListMenu *sender, VcpMenuPos index);
void onItemTapExt(VcpGroupListMenu *sender, VcpMenuPos index);
void updateItems(void);
private :
	void ShowStrokewitdhPopup(void );
//void signalHWswttingChanged(VcpSwitch *sw, VfxBool isChecked);
};

class VappIMEv3HWSettingContentProvider : public VfxObject, public IVcpGroupListMenuContentProvider
{

private:

    VcpMenuPos m_selectedIndex;
    VcpGroupListMenu *m_list;
	VfxS32 m_itemIndexArray[VAPP_IME_MENU_ITEM_HANDWRITING_SETTING_MAX_COUNT];
// Override
public:
	VfxU32 onTapItem ;
	VfxU32 onListGenerate  ;
	VfxU32 m_itemCount ;
VappIMEv3HWSettingContentProvider()
{
    // init the index array
	m_itemCount = 0 ;
    for (VfxS32 i = 0; i < VAPP_IME_MENU_ITEM_HANDWRITING_SETTING_MAX_COUNT; i++)
    {
        m_itemIndexArray[i] = 0;
    }

	//All items enable when HW is enable on project
	m_itemIndexArray[VAPP_IME_MENU_ITEM_STROKE_COLOR_SETTING] = 1;
	m_itemCount++ ;

	m_itemIndexArray[VAPP_IME_MENU_ITEM_HANDWRITING_SPEED_SETTING] = 1;
	m_itemCount++ ;

	m_itemIndexArray[VAPP_IME_MENU_ITEM_HANDWRITING_TRACE_WIDTH_SETTING] = 1;
	m_itemCount++ ;
	//On All project HW setting might not be enabled
#if !(defined(__MMI_IME_VK_TYPE_HANDWRITING__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__))
	m_itemIndexArray[VAPP_IME_MENU_ITEM_HANDWRITING_LANGUAGE_SETTING] = 1;
	m_itemCount++ ;
#endif
}
	virtual void setMenu(VcpGroupListMenu *menu)
	{
		m_list = menu;
	}

	void onUpdate();

	virtual VfxU32 getCount(VfxU32 group) const;

	virtual VfxU32 getGroupCount() const {return (VfxU32)1;}

	virtual VfxBool getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );

	virtual VfxBool getItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ); 

		virtual VfxBool getItemIsDisabled(
		VcpMenuPos pos    // [IN] the index of item
		) const;


    virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos  
        ) const ;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VcpMenuPos pos,
        VfxFrame *parentFrame
        );
    virtual VfxBool hasGroupHeader(
        VfxS32 group    // [IN] position of the item
        ) const {return VFX_FALSE;}

    virtual void closeItemCustomContentFrame(
        VcpMenuPos pos,  
        VcpListMenuCellClientBaseFrame *cell 
        )
    {if (cell){VFX_OBJ_CLOSE(cell);}}

	virtual VcpListMenuCellBaseControl *getItemCustomControl(VcpMenuPos pos, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame);

	virtual void closeItemCustomControl(VcpMenuPos pos, VcpListMenuCellControlLocationTypeEnum location, VcpListMenuCellBaseControl *cellControl)
    {/*m_contentProvider->closeItemCustomControl(pos.pos, location, cellControl);*/}

	 VappIMEv3HandwritingSettingEnum getMenuItembyIndex(VfxS32 index);
};

#endif


class VappIMEswitchControl : public VcpListMenuCellBaseControl
{
    VFX_DECLARE_CLASS(VappIMEswitchControl);
//Declaration
public:
    VcpSwitch *m_switch;

// Override
public:
    virtual void onInit();
    virtual void onDeinit();

    virtual void show() {};
    virtual void hide() {};

public:
	
	//Hnadle Touch Feedback response in this API
	void signalTouchFeedBackChanged(VcpSwitch *sw, VfxBool isChecked);
	void signalAutoSpaceChanged(VcpSwitch *sw, VfxBool isChecked);
	void signalAutoCapChanged(VcpSwitch *sw, VfxBool isChecked);
	void signalAssiciationChanged(VcpSwitch *sw, VfxBool isChecked);
	void signalLangFollowKeybrdChanged(VcpSwitch *sw, VfxBool isChecked);
	//void signalHWswttingChanged(VcpSwitch *sw, VfxBool isChecked);
public:
    VfxSignal2 <VappIMEswitchControl*, VfxBool> m_signalSwitchChanged;
	VfxSignal0 m_signalSwitchChange;
	void emitSignal(VcpSwitch *sender, VfxBool state);
	void emitSignal_Ext(VcpSwitch *sender, VfxBool state);
	


};
#if defined(__MMI_IME_FUZZY_PINYIN__)
class VappIMEv3FuzzyPinyinPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappIMEv3FuzzyPinyinPage);

	// Variable
private: 

	VfxU32 m_selectedIndex;
	VcpListMenu *m_List;
    VfxS32 m_count;
    // current screen
     VfxMainScr *m_mainScreen;
	 U16 temp_mmi_imm_enabled_fuzzy_pinyin;
public:

    VappIMEv3FuzzyPinyinPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );
        
   // VappIMEv3FuzzyPinyinPage();
    
    virtual void onInit();
VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
virtual VfxU32 getCount() const;
virtual void setMenu(VcpListMenu *menu);
virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index    // [IN] index of the item
        ) const; 

virtual VfxBool getItemIsDisabled(
	VfxU32 index    // [IN] the index of item
	) const;

virtual VfxBool getItemText(
	VfxU32 index,                    
	VcpListMenuFieldEnum fieldType,  
	VfxWString &text,                
	VcpListMenuTextColorEnum &color  
	);

void updateItem(VfxU32 index);


// Method
public:
    void processButtonClicked(VfxObject *sender, VfxId buttonId);

	void onPinyinSettingChanged
   (
	    VcpListMenu *menu, // Sender
		VfxU32 index,        // List item index
		VcpListMenuItemStateEnum state        // The new state
  );
};

#endif /*__MMI_IME_FUZZY_PINYIN__*/


class VappIMEv3FollowKeyboardPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappIMEv3FuzzyPinyinPage);
private: 
	VcpListMenu *m_List;
    // current screen
     VfxMainScr *m_mainScreen;
	// U16 temp_mmi_imm_enabled_fuzzy_pinyin;
public:
    VappIMEv3FollowKeyboardPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );     
    virtual void onInit();
virtual VfxU32 getCount() const;
virtual VfxBool getItemIsDisabled(
	VfxU32 index    // [IN] the index of item
	) const;
virtual VfxBool getItemText(
	VfxU32 index,                    
	VcpListMenuFieldEnum fieldType,  
	VfxWString &text,                
	VcpListMenuTextColorEnum &color  
	);
virtual VcpListMenuCellBaseControl *getItemCustomControl(VfxU32 index, 
		VcpListMenuCellControlLocationTypeEnum location, 
		VfxFrame *parentFrame);
// Method
public:
    void processButtonClicked(VfxObject *sender, VfxId buttonId);
	void onLangFollowSettingChanged
   (
	    VcpListMenu *menu, // Sender
		VfxU32 index,        // List item index
		VcpListMenuItemStateEnum state        // The new state
  );
	void updateItems(void);
	void onFollowKeyboardTap(VcpListMenu *sender, VfxU32 index);
};

#if !defined(__MMI_NO_HANDWRITING__)

class VappIMEv3LangFollowKbrdPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappIMEv3FuzzyPinyinPage);
private: 
	VfxU32 m_selectedIndex;
	VcpListMenu *m_List;
    VfxS32 m_count;
    // current screen
     VfxMainScr *m_mainScreen;
	// U16 temp_mmi_imm_enabled_fuzzy_pinyin;
public:
    VappIMEv3LangFollowKbrdPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );     
    virtual void onInit();
//VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
virtual VfxU32 getCount() const;
virtual void setMenu(VcpListMenu *menu);
virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index    // [IN] index of the item
        ) const; 
virtual VfxBool getItemIsDisabled(
	VfxU32 index    // [IN] the index of item
	) const;
virtual VfxBool getItemText(
	VfxU32 index,                    
	VcpListMenuFieldEnum fieldType,  
	VfxWString &text,                
	VcpListMenuTextColorEnum &color  
	);
// Method
public:
    void processButtonClicked(VfxObject *sender, VfxId buttonId);
	void onLangFollowSettingChanged
   (
	    VcpListMenu *menu, // Sender
		VfxU32 index,        // List item index
		VcpListMenuItemStateEnum state        // The new state
  );
};
#endif
class VappIMEv3TouchfeedBackPage : public VfxPage, public IVcpListMenuContentProvider
{
	// Variable
private: 

	VfxU32 m_selectedIndex;
	VcpListMenu *m_List;
    VfxS32 m_count;
    // current screen
     VfxMainScr *m_mainScreen;
public:

    VappIMEv3TouchfeedBackPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );
virtual void onInit();
//VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
virtual VfxU32 getCount() const{return (VfxU32)2 ;};
//virtual void setMenu(VcpListMenu *menu);
virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index    // [IN] index of the item
        ) const; 

virtual VfxBool getItemText(
	VfxU32 index,                    
	VcpListMenuFieldEnum fieldType,  
	VfxWString &text,                
	VcpListMenuTextColorEnum &color  
	);

void updateItem(VfxU32 index);


// Method
public:
    //void processButtonClicked(VfxObject *sender, VfxId buttonId);

	void processButtonClicked(VfxObject *sender, VfxId buttonId);

	void onTouchfeedBackSettingChanged
   (
	    VcpListMenu *menu, // Sender
		VfxU32 index,        // List item index
		VcpListMenuItemStateEnum state        // The new state
  );
};

#if !defined(__MMI_NO_HANDWRITING__)
class VappIMEv3StrokeColorPage : public VfxPage, public IVcpListMenuContentProvider
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
    //VFX_DECLARE_CLASS(VappIMEv3FuzzyPinyinPage);

	// Variable
private: 

	VfxU32 m_selectedIndex;
	VcpListMenu *m_List;
    VfxS32 m_count;
    // current screen
     VfxMainScr *m_mainScreen;
public:
	VappIMEv3StrokeColorPage()
	{

	}
       VappIMEv3StrokeColorPage(
        VfxMainScr *mainScreen            // the main screen to show page
        ); 
virtual void onInit();
VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
virtual VfxU32 getCount() const;
//virtual void setMenu(VcpListMenu *menu);
virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index    // [IN] index of the item
        ) const; 

//virtual VfxBool getItemIsDisabled(
//	VfxU32 index    // [IN] the index of item
//	) const;
/*
virtual VfxBool getItemText(
	VfxU32 index,                    
	VcpListMenuFieldEnum fieldType,  
	VfxWString &text,                
	VcpListMenuTextColorEnum &color  
	); */
    virtual VfxBool getItemTextFrameFormat(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxTextFrame *frame             // [OUT] the text frame
        );

void updateItem(VfxU32 index);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,           // [IN] index of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        ) ;
/*Color_frame_end*/
// Method
public:
    void processButtonClicked(VfxObject *sender, VfxId buttonId);

	void onStrokeColorSettingChanged
   (
	    VcpListMenu *menu, // Sender
		VfxU32 index,        // List item index
		VcpListMenuItemStateEnum state        // The new state
  );
	color *HwColor ;

};

class VappIMEstrokeColorFrame:public VcpListMenuCellClientBaseFrame
{
	//VFX_DECLARE_CLASS(VappBrwPrivateModeCustomFrame);
public:
	virtual void onCreateElements(void){}
	virtual void onCloseElements(void){}
	virtual void onLayoutElements(void);
    virtual void onUpdateElements(void){}
};
//class VappIMEv3StrokeColorCell: public VcpFormItemCell
//{
//    VFX_DECLARE_CLASS(VappIMEv3StrokeColorCell);
//};

class VappIMEv3HWwidthCell: public VcpFormItemCell
{
    VFX_DECLARE_CLASS(VappIMEv3HWwidthCell);
};
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
#endif
class VappSetHWstrokeWidthPopup ;

class VappSetHWstrokeWidthPopup : public VfxBasePopup
{
    VFX_DECLARE_CLASS(VappSetHWstrokeWidthPopup);

private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        POPUP_WIDTH = 290,
        POPUP_HEIGHT = 161,
        UP_HEIGHT = 25,
        ICON_X = 11,
        ICON_Y = 51,
        BAR_LENGTH = 219,
        BAR_X = 50, 
        BAR_Y = 47,
        BTN_X = 11,
        BTN_Y = 100,
        BTN_WIDTH = 268,
        BTN_HEIGHT = 45,
        TEXT_FNT_SIZE = 15
#elif defined(__MMI_MAINLCD_480X800__)
        POPUP_WIDTH = 446,
        POPUP_HEIGHT = 226,
        UP_HEIGHT = 45,
        ICON_X = 21,
        ICON_Y = 80, //70
        BAR_LENGTH = 338,
        BAR_X = 87, 
        BAR_Y = 72,
        BTN_X = 21,
        BTN_Y = 131,
        BTN_WIDTH = 404,
        BTN_HEIGHT = 70,
        TEXT_FNT_SIZE = 24
#elif defined(__MMI_MAINLCD_240X400__)
        POPUP_WIDTH = 222,
        POPUP_HEIGHT = 130,
        UP_HEIGHT = 20,
        ICON_X = 8,
        ICON_Y = 38,
        BAR_LENGTH = 175,
        BAR_X = 39,
        BAR_Y = 36,
        BTN_X = 8,
        BTN_Y = 74,
        BTN_WIDTH = 206,
        BTN_HEIGHT = 40,
        TEXT_FNT_SIZE = 13
#else  //if defined(__MMI_MAINLCD_240X320__)
        POPUP_WIDTH = 222,
        POPUP_HEIGHT = 130,
        UP_HEIGHT = 20,
        ICON_X = 8,
        ICON_Y = 38,
        BAR_LENGTH = 175,
        BAR_X = 39,
        BAR_Y = 36,
        BTN_X = 8,
        BTN_Y = 74,
        BTN_WIDTH = 206,
        BTN_HEIGHT = 40,
        TEXT_FNT_SIZE = 13
#endif
    };

private:
    VfxTextFrame* m_HWstrokeText;
    VfxU8 m_max;
    VfxU8 m_min;

public:
    //VfxSignal1 <VfxU8> m_signalBtnClicked;
    VfxU8 m_width;
    VfxTextFrame* hw_icon;
    VcpSlider* m_slider;
    //static VappSetPriorityPopup *m_self;

private:
    virtual void onInit(void);
    virtual void onDeinit(void);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval);
    void onButtonClicked(VfxObject *sender, VfxId id);
    //void onDecreasePri(void);
    //void onIncreasePri(void);

public:
    //void setInitPri(VfxU8 vol);
    //VfxU8 getPri(void);
    void setTitle(VfxWString id);
    VappSetHWstrokeWidthPopup();
};
#endif /*__MMI_NO_HANDWRITING__*/
#endif /*__MMI_IME_V3__*/
/***************************************************************************** 
 * Class VappIMESettingSwitch
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VappIMESettingSwitch is a switch on the menu item
 */
class VappIMESettingSwitch : public VcpListMenuCellBaseControl
{
// Method
public:
    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Method>
    // Sets the switch state
    void setChecked(
        VfxBool checked,                // [IN] checked flag 
        VfxBool isAnimated = VFX_TRUE   // [IN] is animated
    );

// Signal
public:
    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Signal>
    // switch state value change event
    VfxSignal2<
        VappIMESettingSwitch*,          // sender
        VfxBool                         // the state
        > m_signalSwitchChanged;

// Override
public:
    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Override>
    virtual void show();

    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Override>
    virtual void hide();
    
protected:
    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Override>
    virtual void onInit();

    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Override>
    virtual void setBounds(const VfxRect &value);

// Implementation
private:
    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Implementation>
    // connect with m_switch
    void emitSignal(
        VcpSwitch *sender,              // [IN] the sender
        VfxBool state                   // [IN] the state of switch
        );
    
// Variable
private:
    // <group DOM_InputMethodSetting_VappIMESettingSwitch_Variable>
    // the switch
    VcpSwitch *m_switch;
};


/***************************************************************************** 
 * Class VappIMESettingMainPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VappIMESettingMainPage is a page to show the main menu of the setting for input method
 */
class VappIMESettingMainPage : public VfxPage, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Constructor/Destructor>
    VappIMESettingMainPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );

// Override
public:
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual VfxU32 getCount() const;
    
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual VcpListMenuCellBaseControl *getItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame);

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual void closeItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VcpListMenuCellBaseControl *cellControl);

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *cell);

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
    
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual VfxBool getItemIsHighlightable(VfxU32 index) const;


protected:
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual void onInit();

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Override>
    virtual void onEnter(VfxBool isBackward);

// Implementation
private:
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // get the menu item
    VappIMESettingMainMenuItemEnum getMenuItem(
        VfxU32 index                                // [IN] the index of menu item in list menu
        ) const;
    
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // enter the next page
    void enterNextPage(
        VcpListMenu *menu,                              // Sender
        VfxU32 index                                    // List item index
        );

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // enter the prefered input method setting page
    void enterPreferedInputMethodSettingPage();
    
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // enter the writing language setting page
    void enterWritingLangSettingPage();

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // enter the main language setting page
    void enterMainLangSettingPage();

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // enter the sub language setting page
    void enterSubLangSettingPage();

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // enter the advanced setting page
    void enterAdvancedSettingPage();

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // enter the pen speed setting page
    void enterPenSpeedSettingPage();

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Implementation>
    // change the switch of smart input method, connect to signal
    void changeSmartMethodState(
        VappIMESettingSwitch *sender,           // sender
        VfxBool state                           // the state
        );

// Variable
private:
    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Variable>
    // current screen
    VfxMainScr *m_mainScreen;

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Variable>
    // record the index of each item
    VfxS32 m_itemIndexArray[VAPP_IME_SETTING_MAIN_MENU_ITEM_MAX_COUNT];

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Variable>
    // the count of menu item
    VfxS32 m_count;

    // <group DOM_InputMethodSetting_VappIMESettingMainPage_Variable>
    // the list menu
    VcpListMenu *m_listMenu;
};


#if defined(__MMI_PREFER_INPUT_METHOD__)
/***************************************************************************** 
 * Class VappIMESettingPreferedInputMethodPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VappIMESettingPreferedInputMethodPage is a page to show the prefered input method for the setting of input method
 */
class VappIMESettingPreferedInputMethodPage : public VfxPage, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Constructor/Destructor>
    VappIMESettingPreferedInputMethodPage(
        VfxMainScr *mainScreen              // [IN]: the main screen to show page
        );

// Override
public:
    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Override>
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Override>
    virtual VfxU32 getCount() const;

    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Override>
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Override>
    virtual void onInit();

// Implementation
private:
    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Implementation>
    // set the input method and close(popup) the page
    void setInputMethodAndClose(
        VcpListMenu *menu,                              // Sender
        VfxU32 index                                    // List item index
        );

// Variable
private:
    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Variable>
    // current screen
    VfxMainScr *m_mainScreen;

    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Variable>
    // the count of menu item
    VfxS32 m_count;

    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Variable>
    // the list of input mode
    mmi_imm_input_mode_enum m_inputModeList[IMM_INPUT_MODE_MAX_NUM];
    
    // <group DOM_InputMethodSetting_VappIMESettingPreferedInputMethodPage_Variable>
    // the list of input mode string
    VfxU8 *m_inputModeStrList[IMM_INPUT_MODE_MAX_NUM];
};
#endif /* defined(__MMI_PREFER_INPUT_METHOD__) */


#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
/***************************************************************************** 
 * Class VappIMESettingWritingLangPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VappIMESettingWritingLangPage is a page to show the writing language for the setting of input method
 */
class VappIMESettingWritingLangPage : public VfxPage, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Constructor/Destructor>
    VappIMESettingWritingLangPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );

// Override
public:
    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Override>
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Override>
    virtual VfxU32 getCount() const;

    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Override>
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;

    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Override>
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Override>
    virtual void onInit();

// Implementation
private:
    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Implementation>
    // process the user action. connect to signal
    void processButtonClicked(
        VfxObject *sender,                  // [IN] sender
        VfxId buttonId                      // [IN] the button id
        );

    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Implementation>
    // process the change of state of language (enabled, disabled)
    void processStateChanged(
        VcpListMenu *menu,                              // Sender
        VfxU32 index,                                   // List item index
        VcpListMenuItemStateEnum state                  // The new state
        );

// Variable
private:
    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Variable>
    // current screen
    VfxMainScr *m_mainScreen;

    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Variable>
    // the count of menu item
    VfxS32 m_count;

    // <group DOM_InputMethodSetting_VappIMESettingWritingLangPage_Variable>
    // the current state (enabled, disabled) of each language
    VfxBool m_enabled[VAPP_IME_SETTING_WRITING_LANG_MAX_NUM];
};

#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */


#if defined(__MMI_MIXED_LANG_SUPPORT__)
/***************************************************************************** 
 * Class VappIMESettingMainSubLangPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VappIMESettingMainSubLangPage is a page to show the main or sub writing language for the setting of input method
 */
class VappIMESettingMainSubLangPage : public VfxPage, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Constructor/Destructor>
    VappIMESettingMainSubLangPage(
        VfxMainScr *mainScreen,             // [IN]: the main screen to show page
        VappIMESettingLangTypeEnum type     // [IN]: main language or sub language
        );

// Override
public:
    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Override>
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Override>
    virtual VfxU32 getCount() const;

    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Override>
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Override>
    virtual void onInit();

// Implementation
private:
    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Implementation>
    // set the language and close(popup) the page
    void setLangAndClose(
        VcpListMenu *menu,                              // Sender
        VfxU32 index                                    // List item index
        );

// Variable
private:
    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Variable>
    // current screen
    VfxMainScr *m_mainScreen;

    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Variable>
    // the count of menu item
    VfxS32 m_count;

    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Variable>
    // main language or sub language
    VappIMESettingLangTypeEnum m_type;

    // <group DOM_InputMethodSetting_VappIMESettingMainSubLangPage_Variable>
    // record the index in global language array of each menu item
    VfxS32 m_indexArray[VAPP_IME_SETTING_WRITING_LANG_MAX_NUM];
};

#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */


#if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
/***************************************************************************** 
 * Class VappIMESettingAdvancedPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VappIMESettingAdvancedPage is a page to show the advanced setting of input method
 */
class VappIMESettingAdvancedPage : public VfxPage, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Constructor/Destructor>
    VappIMESettingAdvancedPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );

// Override
public:
    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Override>
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Override>
    virtual VfxU32 getCount() const;
    
    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Override>
    virtual VcpListMenuCellBaseControl *getItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame);

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Override>
    virtual void closeItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VcpListMenuCellBaseControl *cellControl);

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Override>
    virtual VfxBool getItemIsHighlightable(VfxU32 index) const;

protected:
    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Override>
    virtual void onInit();

// Implementation
private:
    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Implementation>
    // get the menu item
    VappIMESettingAdvancedMenuItemEnum getMenuItem(
        VfxU32 index                                // [IN] the index of menu item in list menu
        ) const;

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Implementation>
    // change the switch of auto capitalization, connect to signal
    void changeAutoCapitalizationState(
        VappIMESettingSwitch *sender,           // sender
        VfxBool state                           // the state
        );

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Implementation>
    // change the switch of auto completion, connect to signal
    void changeAutoCompletionState(
        VappIMESettingSwitch *sender,           // sender
        VfxBool state                           // the state
        );

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Implementation>
    // change the switch of phonetic prediction, connect to signal
    void changePhoneticPredictState(
        VappIMESettingSwitch *sender,           // sender
        VfxBool state                           // the state
        );

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Implementation>
    // change the switch of alphabetic prediction, connect to signal
    void changeAlphabeticPredictState(
        VappIMESettingSwitch *sender,           // sender
        VfxBool state                           // the state
        );
    
// Variable
private:
    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Variable>
    // current screen
    VfxMainScr *m_mainScreen;

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Variable>
    // record the index of each item
    VfxS32 m_itemIndexArray[VAPP_IME_SETTING_ADVANCED_MENU_ITEM_MAX_COUNT];

    // <group DOM_InputMethodSetting_VappIMESettingAdvancedPage_Variable>
    // the count of menu item
    VfxS32 m_count;
};
#endif /* defined(__MMI_IME_INPUT_ADVANCED_SETTING__) */


#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
/***************************************************************************** 
 * Class VappIMESettingPenSpeedPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VappIMESettingPenSpeedPage is a page to show the handwriting pen speed of input method
 */
class VappIMESettingPenSpeedPage : public VfxPage, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    // <group DOM_InputMethodSetting_VappIMESettingPenSpeedPage_Constructor/Destructor>
    VappIMESettingPenSpeedPage(
        VfxMainScr *mainScreen            // the main screen to show page
        );
	#if defined(__MMI_IME_V3__)
	VappIMESettingPenSpeedPage()
	{
	}
	#endif
// Override
public:
    // <group DOM_InputMethodSetting_VappIMESettingPenSpeedPage_Override>
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

    // <group DOM_InputMethodSetting_VappIMESettingPenSpeedPage_Override>
    virtual VfxU32 getCount() const;

    // <group DOM_InputMethodSetting_VappIMESettingPenSpeedPage_Override>
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    // <group DOM_InputMethodSetting_VappIMESettingPenSpeedPage_Override>
    virtual void onInit();

// Implementation
private:
    // <group DOM_InputMethodSetting_VappIMESettingPenSpeedPage_Override>
    // set the speed and close(popup) the page
    void setSpeedAndClose(
        VcpListMenu *menu,                              // Sender
        VfxU32 index                                    // List item index
        );

// Variable
private:
    // <group DOM_InputMethodSetting_VappIMESettingPenSpeedPage_Variable>
    // current screen
    VfxMainScr *m_mainScreen;
};
#endif /* defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__) */

#endif /* __VAPP_INPUT_METHOD_SETTING_H__ */

