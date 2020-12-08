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
 *  vapp_mms_setting.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MMSSETTING_H__
#define __VAPP_MMSSETTING_H__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_mms_def.h"
#include "vapp_mms_setting_prot.h"



 extern "C" {
   #include "MmsSrvGprot.h"
 }

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/


class VappMMSSettingScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappMMSSettingScreen);

// Override
public:
    virtual void on1stReady();
	virtual VfxBool onKeyInput(VfxKeyEvent& event);
	virtual void onQueryRotateEx( VfxScreenRotateParam &param);
};


class VMMSSettingListMenuCustomContentFrame : public VcpListMenuCellClientBaseFrame
{
//Declaration
private:
    VfxTextFrame *m_textFrame;
// Constructor / Destructor
public:
    VMMSSettingListMenuCustomContentFrame(){}

    virtual ~VMMSSettingListMenuCustomContentFrame(){}
	
// Override
public:
	virtual void onCreateElements();
	virtual void onCloseElements(){}
	virtual void onLayoutElements();
	virtual void onUpdateElements(){}

};

class VMMSSettingGroupListMenuContentProvider : public VfxObject, public IVcpGroupListMenuContentProvider
{

private:
	srv_mms_nvram_compose_settings_struct* m_composeSet;
	srv_mms_nvram_sending_settings_struct *m_sendSet;
	srv_mms_nvram_retrieval_settings_struct *m_retvlSet;

    VcpMenuPos m_selectedIndex;
    VcpGroupListMenu *m_list;

// Override
public:
	virtual VfxBool hasGroupHeader(VfxS32 group) const;
	virtual void setMenu(VcpGroupListMenu *menu)
	{
		m_list = menu;
		m_composeSet = srv_mms_get_nvram_compose_settings();		
	}

	void onUpdate();

	virtual VfxU32 getCount(VfxU32 group) const;

	virtual VfxU32 getGroupCount() const {return VAPP_LIST_HEADER_MAX;}

    virtual VfxBool getItemIsDisabled(VcpMenuPos pos) const;
	virtual VfxBool getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxBool getItemIsHighlightable(
    VcpMenuPos pos) const;

	virtual VfxBool getItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ); 

	   virtual void closeItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType, 
        VfxImageSrc Image               
        );

        virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos  
        ) const ;

       virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VcpMenuPos pos,
        VfxFrame *parentFrame
        );

       virtual void closeItemCustomContentFrame(
        VcpMenuPos pos,  
        VcpListMenuCellClientBaseFrame *cell 
        )
    {if (cell){VFX_OBJ_CLOSE(cell);}}

	 virtual VcpListMenuCellBaseControl *getItemCustomControl(VcpMenuPos pos, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame);

	 virtual void closeItemCustomControl(VcpMenuPos pos, VcpListMenuCellControlLocationTypeEnum location, VcpListMenuCellBaseControl *cellControl)
    {/*m_contentProvider->closeItemCustomControl(pos.pos, location, cellControl);*/}

public:
	
#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
	void sendingSetDeliverySwitchSignal(VfxObject *sw, VfxBool isChecked);
	void sendingSetReadSwitchSignal(VfxObject *sw, VfxBool isChecked);

	void retrievalSetDeliverySwitchSignal(VfxObject *sw, VfxBool isChecked);
	void retrievalSetReadSwitchSignal(VfxObject *sw, VfxBool isChecked);
#endif	
#ifdef __MMI_MMS_SETTING_ADVERTISEMENT__
	void retrievalSetAdvtSwitchSignal(VfxObject *sw, VfxBool isChecked);
#endif
#ifdef __MMI_MMS_SETTING_ANONYMOUS__
	void retrievalSetAnonmsSwitchSignal(VfxObject *sw, VfxBool isChecked);
#endif
	
		    VfxSignal2 <
        VcpGroupListMenu *, // Sender
        VcpMenuPos         // List item position
    > m_signalMMSSettingRefresh;
};





class VappMMSSettingApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappMMSSettingApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};



class VappMMSSettingPage : public VfxPage, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMMSSettingPage);


// Variable
private: 
	VcpTitleBar * m_titleBar;
	VcpGroupListMenu *m_groupList;
	VMMSSettingGroupListMenuContentProvider *m_listMenuContentProvider;
	VfxS32 m_setUpdate;
private:
	enum
	{
		VAPP_COMPOSER_SETTING_UPDATE = 0x00000001,
		VAPP_SENDING_SETTING_UPDATE = 0x00000010,
		VAPP_RETRIEVAL_SETTING_UPDATE = 0x00000100,
		VAPP_OPEN_SETTING_UPDATE = 0x00001000,
	};
// Constructor / Destructor
public:
VappMMSSettingPage()
{

}
// Override
public:
    virtual void onInit();
	virtual void onDeinit();
	virtual void onQueryRotateEx( VfxScreenRotateParam &param);
// Method
public:
	// <group DOM_VappMMSSettingPage_Method>
    // Refresh list if something is changed on page
	void onSettingRefresh(VcpGroupListMenu *menu, VcpMenuPos pos);

	// <group DOM_VappMMSSettingPage_Method>
    // Hanlde tap event on page list
	void onTapItem(VcpGroupListMenu *listMenu, VcpMenuPos pos);
	static void setResponseHandler(srv_mms_result_enum result, void *rsp_data, void* user_data);


};


#ifndef __COSMOS_NO_USER_DRIVE__ 				  

class VappMMSSetPrefStPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMMSSetPrefStPage);

//Declaration
private:


	VfxU32 m_selectedIndex;
	VcpListMenu *m_menu;
	VcpTitleBar *m_titleBar;
	VfxU8 m_prefStorage;

// Constructor/Destructors
public:
	VappMMSSetPrefStPage(){}

// Override
public:
	virtual void onInit();
	virtual void onDeinit(void);
	virtual void onQueryRotateEx( VfxScreenRotateParam &param);
	static mmi_ret memoryCardPlugOut(mmi_event_struct *param);
	static mmi_ret memoryCardPlugIn(mmi_event_struct *param);
    static mmi_ret usbMassStorageHdlr(mmi_event_struct *param);
    
	virtual void setMenu(VcpListMenu *menu);

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const;
	virtual VfxU32 getCount() const;
	virtual VfxBool getItemIsDisabled(
        VfxU32 index       
        ) const;
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
	void updateItem(VfxU32 index);

	virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
		{return VFX_TRUE;}	

	//Methods
public:
	 void onTapItem(VcpListMenu *menu,VfxU32 index);


	    VfxSignal2 <
        VcpGroupListMenu *, // Sender
        VcpMenuPos         // List item position
    > m_signalMMSSettingRefresh;

};
#endif
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__	
class VappMMSSetFilterPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMMSSetFilterPage);

//Declaration
private:

	 enum
    {
        BUTTON_OK = 0,
        BUTTON_CANCEL,
 	}bottom_id;
	typedef enum
    {
    
		FILTER_NONE = 0X00,
        FILTER_SELECT ,
        FILTER_CANCEL ,
 	}item_state;

	VfxU32 m_selectedIndex;
	VcpListMenu *m_menu;
	VcpTitleBar *m_titleBar;
	VfxU8 m_prefStorage;
	VcpToolBar * m_toolBar;
 	item_state m_phone_state;
	item_state m_memory_card_state;

// Constructor/Destructors
public:
	VappMMSSetFilterPage()
	{
		m_phone_state = FILTER_NONE;
		m_memory_card_state = FILTER_NONE;
		m_toolBar = NULL;
		m_titleBar = NULL;
		m_menu = NULL;
	}

// Override
public:
	virtual void onInit();
	void onDeinit(void);
	void onQueryRotateEx( VfxScreenRotateParam &param);
	static mmi_ret memoryCardPlugOut(mmi_event_struct *param);
	static mmi_ret memoryCardPlugIn(mmi_event_struct *param);
    static mmi_ret usbMassStorageHdlr(mmi_event_struct *param);
    
	virtual void setMenu(VcpListMenu *menu);

    void onButtonClicked(VfxObject *sender, VfxId bottom_id);

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const;
	virtual VfxU32 getCount() const;
	virtual VfxBool VappMMSSetFilterPage::getItemIsDisabled(
        VfxU32 index       
        ) const;
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
	//void updateItem(VfxU32 index);

	virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
		{return VFX_TRUE;}	

	//Methods
public:
	 //void onTapItem(VcpListMenu *menu,VfxU32 index);
	 void onSelectChangeed(       VcpListMenu * menu,              // Sender
        								VfxU32 index,                     // List item index
    									VcpListMenuItemStateEnum  satte  // The new state)
        );


	    VfxSignal2 <
        VcpGroupListMenu *, // Sender
        VcpMenuPos         // List item position
    > m_signalMMSSettingRefresh;

};
#endif
class VappMMSSetDataActPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMMSSetDataActPage);

//Declaration
private:


	VfxU32 m_selectedIndex;
	VcpListMenu *m_menu;
	VcpTitleBar *m_titleBar;
	VfxU8 m_prefStorage;

// Constructor/Destructors
public:
	VappMMSSetDataActPage(){}

// Override
public:
	virtual void onInit();
	virtual void onQueryRotateEx( VfxScreenRotateParam &param);
	virtual void setMenu(VcpListMenu *menu);

	virtual VfxU32 getCount() const;

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
	
	virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
		{return VFX_TRUE;}	

	//Methods
public:
	 void onTapItem(VcpListMenu *menu,VfxU32 index);

};


class VappMMSSetSwitchControl : public VcpListMenuCellBaseControl
{
    VFX_DECLARE_CLASS(VappMMSSetSwitchControl);
//Declaration
private:
    VcpSwitch *m_switch;

// Override
public:
    virtual void onInit();
    virtual void onDeinit();

    virtual void show() {};
    virtual void hide() {};

public:
	void setMMSChecked(VfxBool checked);
    void signalMMSSwitchChanged(VcpSwitch *sender, VfxBool isChecked);
public:
    VfxSignal2 <VfxObject*, VfxBool> m_signalSwitchChanged;


};

#endif /* __MMI_MMS_2__ */
#endif /* __VAPP_MMSSETTING_H__ */

