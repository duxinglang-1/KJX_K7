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
 *  vapp_shell_settings.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  General settings' header file
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
 * removed!
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

#ifndef __VAPP_SHELL_SETTINGS_H__
#define __VAPP_SHELL_SETTINGS_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_SETTINGS__

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vdat_include.h"
#include "ShellApp\base\vapp_shell_panel.h"
#include "ShellApp\base\vapp_shell_page_order.h"
#include "ShellApp\base\vapp_shell_panel_cfg.h"

#include "vcp_page_panel.h"
#include "vcp_inline_menu.h"
#include "vcp_list_menu.h"
#include "vcp_command_title.h"
#include "vcp_waiting_icon.h"
#include "vcp_popup.h"
#include "vcp_switch.h"
#include "ProfilesSrvConfig.h"
#include "mmi_rp_app_venus_shell_settings_def.h"

    #include "vfx_cpp_base.h"
    #include "vfx_input_event.h"
    #include "vfx_control.h"
    #include "vfx_datatype.h"
    #include "vfx_signal.h"
    #include "vfx_primitive_frame.h"
    #include "vfx_text_frame.h"
    #include "vfx_object.h"
    #include "vfx_weak_ptr.h"
    #include "vfx_string.h"
    #include "vfx_image_src.h"
    #include "vfx_frame.h"
    #include "vfx_basic_type.h"
    #include "vfx_sys_memory.h"
    #include "vfx_animation.h"
/***************************************************************************** 
 * Class VappShellWaitingPopup
 *****************************************************************************/
class VappShellWaitingPopup : public VcpWaitingPopup
{
public:
	VappShellWaitingPopup(){};

protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);	
};


/***************************************************************************** 
 * Class VappShellBrightnessSelPopup
 *****************************************************************************/
class VappShellBrightnessSelPopup : public VfxControl
{

public:
    VappShellBrightnessSelPopup();
    VappShellBrightnessSelPopup(const VfxU16 &level);
    virtual ~VappShellBrightnessSelPopup(){};
    
	enum{
        
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        WIDTH        = 208,
        HEIGHT       = 132,
        SUN_POS_X    = 20,
        SUN_POS_Y    = 51,
        BAR_INTERVAL = 5,
        BAR_WIDTH    = 22,
        BAR1_HEIGHT  = 41,
        BAR2_HEIGHT  = 63,
        BAR3_HEIGHT  = 83,
        BAR4_HEIGHT  = 97,
        BAR5_HEIGHT  = 115,
        BAR1_POS_X   = 61,
        BAR1_POS_Y   = 46,
#else /* __MMI_MAINLCD_320X480__ */
        WIDTH        = 248,
        HEIGHT       = 155,
        SUN_POS_X    = 21,
        SUN_POS_Y    = 58,
        BAR_INTERVAL = 7,
        BAR_WIDTH    = 23,
        BAR1_HEIGHT  = 47,
        BAR2_HEIGHT  = 73,
        BAR3_HEIGHT  = 97,
        BAR4_HEIGHT  = 115,
        BAR5_HEIGHT  = 135,
        BAR1_POS_X   = 74,
        BAR1_POS_Y   = 55,
#endif /* __MMI_MAINLCD_240X320__ */
        MAX_LEVELS   = 5
    };
	void setCurrentLevel(
			const VfxU8 &level	//[IN] send to GPIO and Save
			);
    
	VfxSignal1<const VfxU16 &> m_signalLevel;

protected:
    virtual void onInit(void);
    virtual VfxBool onPenInput(VfxPenEvent &event);   
    virtual void updateLevelBar(void);
    
private:
	
	VfxImageFrame *m_levelBar[MAX_LEVELS];
    VfxU16        m_level;
	VfxBool 	  m_bDrag;
};


/***************************************************************************** 
 * Class VappShellOrderListItem
 *****************************************************************************/
class VappShellOrderListItem : public VcpListMenuCellClientBaseFrame
{
public:
	VappShellOrderListItem(
            const VfxBool &switchable = VFX_TRUE,
            const VfxBool &switchValue = VFX_FALSE                  
            );

    enum{
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        IMG_POS_X  = 9,
        TEXT_INX_X = 12,
        TEXT_LENGTH = 110,
#else /* __MMI_MAINLCD_320X480__ */
        IMG_POS_X  = 14,
        TEXT_INX_X = 14,
        TEXT_LENGTH = 150,
#endif /* __MMI_MAINLCD_240X320__ */
        POS_TOTAL
        };
    
	struct Content
	{
		 VfxU8	apId;
		 VfxS32 resId;
		 VfxU16 string;
         VfxBool switchable;
	};
	
	void setContent(
            const VfxU16 &appId,
			const VfxS32 &resId, 	//[IN]	imge res id
			const VfxU16 &stringId, //[IN]	text res id
			const VfxBool &checked	//[IN]	ON or OFF
		    );

    void setContent(
            const Content& content
                );
    
	VfxSignal2<const VfxU16 &, const VfxBool &>	m_signalSwitch;

// Overridable
public:
    virtual void onCreateElements(void);
    virtual void onCloseElements(void);
    virtual void onLayoutElements(void);
    virtual void onUpdateElements(void){};
private:
    void switchCallback(
            VcpSwitch *thiz, 
            VfxBool status
            );
    
private:
	VfxImageFrame *m_image;
	VfxTextFrame  *m_text;
	VcpSwitch	  *m_switch;
    
	VfxBool m_bSwitch;
    VfxBool m_bSwitchValue;
    VfxU16 m_appId;   
};


/***************************************************************************** 
 * Class VappShellSettingsOrderConfigContentProvider
 *****************************************************************************/
class VappShellSettingsOrderConfigContentProvider: public VfxObject, public IVcpListMenuContentProvider 
{

public:
    VappShellSettingsOrderConfigContentProvider();
    ~VappShellSettingsOrderConfigContentProvider(){};
    
    typedef struct 
    {
        VfxU16 id;
        VfxResId resId;
        VfxResId strId;
        VfxBool switchable; // whether can be switched.
    }ListItemStruct;

// Overridable
public:

    // Set the list menu pointer to content provider
    virtual void setMenu(VcpListMenu *list){ m_parentList = list;};

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
        {
            return VFX_FALSE;
        }

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
        {
            return VFX_FALSE;
        }

    // Free the image resource for the image fields of list cell
    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        )
        {}

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const
        {
            return VCP_LIST_MENU_ITEM_STATE_NONE;
        }

    // Swap two items, user should update its internal data of the two items
    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        );

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,   // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    // Uer should release the resource of the content frame which is created by 
    // itself, such as image resource
    virtual void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        );

    
private:
	void onSwitchCallback(const VfxU16 &id, const VfxBool &newState);
    void *getPanelInfo(const VfxU32 &index) const;
    
private:
    VcpListMenu *m_parentList;
    
};


/***************************************************************************** 
 * Class VappShellPageOrderConfigScr
 *****************************************************************************/
class VappShellPageOrderConfigScr : public VfxControl
{
public:
	VappShellPageOrderConfigScr();
	~VappShellPageOrderConfigScr(){};

    VfxSignal0 m_signalReqClose;
    
protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	
private:
	// Handler for Back Button
	void onCmdButtonUp(VfxObject* obj, VfxId id);
    void onBoundChange(VfxFrame *frame, const VfxRect &old);

private:
    
    VappShellSettingsOrderConfigContentProvider *m_content;

    VcpCommandTitle *m_cmdTitle;
	VcpListMenu		*m_list;
};


/****************************************************************************** 
 * Class VappShellSettingContentProvider
 *****************************************************************************/
class VappShellSettingContentProvider : public VcpInlineMenuDefaultContentProvider
{
public:
    VappShellSettingContentProvider(void);
    ~VappShellSettingContentProvider(void);

    // Inline items
    enum{
#ifdef __MMI_BT_SUPPORT__ 
    	INLINE_BT,
    	INLINE_BT_SEARCH,   // search BT device
	INLINE_GRP_SPLITOR1,
#endif /* __MMI_BT_SUPPORT__  */

#ifdef __MMI_WLAN_FEATURES__
    	INLINE_WIFI,
    	INLINE_WIFI_SEARCH, // search network		
	INLINE_GRP_SPLITOR2,
#endif /* __MMI_WLAN_FEATURES__ */

#if 0//def __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM == 1)
    	INLINE_FLIGHTMODE,  // for dual sim, it will be dual mode
#endif
    	INLINE_PROFILES,
#ifdef __MMI_AUTO_KEYPAD_LOCK__
    	INLINE_AUTOLOCK,
#endif
    	INLINE_WALLPAPER,
    	INLINE_BRIGHTNESS,		/* Brightness selection */
    	INLINE_SHELL_SETTINGS, /* Shell order config */
    	INLINE_TOTAL
    };
    
#ifdef __MMI_AUTO_KEYPAD_LOCK__	
    enum{
    	AUTOLOCK_OFF   , 
    	AUTOLOCK_5SECS , 
    	AUTOLOCK_30SECS, 
    	AUTOLOCK_1MINS , 
    	AUTOLOCK_5MINS , 
    	AUTOLOCK_TOTAL
    	};
#endif /* __MMI_AUTO_KEYPAD_LOCK__ */

    enum{GROUP1, GROUP2, GROUP_TOTAL};
    
    struct SettingsPair
    {
        VfxU16   id;
        VfxResId resId;
    };
    struct InlineCell
    {
        VfxId id;
        void *data; 
        VcpInlineCellTypeEnum type;        
    };
    void buildMenu(void);
    void initString(void);
#if 0//def __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif
	VfxU8 m_profilesNum;
    VcpInlineRadioListOptionStruct m_strListProfiles[SRV_PROF_PROFILES_TOTAL_NUM];
	VfxU8 m_enumListProfiles[SRV_PROF_PROFILES_TOTAL_NUM];

protected:
    virtual void* makeCustomCellData(
                        const VfxId &id //[IN]
                    );
private:
    VcpInlineCellRadioListData m_dataRadioList;
    VcpInlineCellSwitchData    m_dataSwitch;
    VcpInlineCellButtonData    m_dataButton;

#ifdef __MMI_AUTO_KEYPAD_LOCK__
    VcpInlineRadioListOptionStruct m_strListAutoLock[AUTOLOCK_TOTAL];
#endif
    VfxWString m_strListLang[15];

#ifdef __MMI_DUAL_SIM_MASTER__
    VcpInlineRadioListOptionStruct m_strListDualMode[4];
    VfxU8   m_nDualMode;
    VfxU8   m_eDualMode[4];
#endif /* __MMI_DUAL_SIM_MASTER__ */

    static const InlineCell s_cellTable[INLINE_TOTAL];
#ifdef __MMI_AUTO_KEYPAD_LOCK__
    static const VfxResId s_resAutoLock[AUTOLOCK_TOTAL];
#endif

};


/***************************************************************************** 
 * Class VappShellSettingsScr definition
 *****************************************************************************/
class VappShellSettingsScr : public VappShellPanel
{
    VAPP_SHELL_PANEL_CREATE(VappShellSettingsScr, VFX_FALSE);
	VFX_DECLARE_CLASS(VappShellSettingsScr);
    
public:
	VappShellSettingsScr();
	~VappShellSettingsScr(){};

    enum
    {
        BRIGHTNESS_POS_X = 40,
        BRIGHTNESS_POS_Y = 172,
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
	TITLE_HEIGHT = 60,
	TOP_MARGIN = 11,
	LEFT_MARGIN = 11,
	RIGHT_MARGIN = 11,
	BOTTOM_MARGIN = 11,
	SHADOW_MARGIN = 5,
#else /* __MMI_MAINLCD_240X320__ */
	TITLE_HEIGHT = 60,
	TOP_MARGIN = 15,
	LEFT_MARGIN = 15,
	RIGHT_MARGIN = 15,
	BOTTOM_MARGIN = 15,
	SHADOW_MARGIN = 5,
#endif /* __MMI_MAINLCD_240X320__ */
	ENUM_TOAL
    };

    enum
    {
        WALLPAPER_LIVE,   
        WALLPAPER_GALLERY,
        WALLPAPER_FMGR,
        WALLPAPER_CANCEL,
        WALLPAPER_TOTAL
    };

    enum
    {
        EFFECT_FADE_IN,
        EFFECT_FADE_OUT,
        EFFECT_TOTAL,
    };
    
    enum{SCR_MAIN, SCR_ORDER, SCR_WAITING, SCR_TOTAL};
    enum{SWITCH_BY_SHELL, SWITCH_BY_BT, SWITCH_BY_OTHER};
    
public:
        // onSwitchCallback
    void onSwitchCallback(VfxBool finish);
	void onSwitchWlanResult(mmi_event_struct *evt);
#ifdef __MMI_WLAN_FEATURES__
    void onSwitchHotspotCallback(VfxBool result);
#endif

protected:
    virtual void onInit(void);
    virtual void onInitView(void);
    virtual void onEnterView(void);
    virtual void onExitView(ShellExitCauseEnum cause);
    virtual void onDeinitView(void);		
    virtual void onDeinit(void);
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxS32 getPanelStrId(void) { return VAPP_SHELL_STR_SETTINGS_TITLE_TEXT;}
    
private:
	void regEvtHdlr(void);
	void unregEvtHdlr(void);
    void showWallpaperConfirm(void);
    void launchWallpaperApp(VfxId id);

    void showBrightnessScr(void);
    void closeBrightnessScr(void);
    void showSetOrderScr(VfxBool anim);

    void showWaitingIcon(void);
    void closeWaitingIcon(void);

#ifndef __MMI_DUAL_SIM_MASTER__
	void switchFlightmode(const VfxBool &state);
#endif
    
#ifdef __MMI_BT_SUPPORT__ 
    void launchBTSearch(void);
	void showActiveBTConfirm(void);
	void switchBT(const VfxBool &state);
	void initBTMenu(void);
	void onSwitchBTResult(const VfxBool &state);
#endif /* __MMI_BT_SUPPORT__  */

#ifdef __MMI_WLAN_FEATURES__
    // Hotspot checking
	void preSwitchWlan(const VfxBool &state); 

	void switchWlan(const VfxBool &state);
  	void onTurnOffHotspotPopCallback(VfxObject *obj, VfxId id);
    void launchWlanApp(void);
	void initWlanMenu(void);
#endif
    // inline submenu callback
    void onAutoLockSelection(const VfxU8 &selIndex);
    void onProfileSelection(const VfxU8 &selIndex);
    
    void onLevelClick(const VfxU16 &level); //brightness level click callback

    // inline callback
    void cellSwitchButtonCallback(VfxId id, VfxBool status);
    void cellOptionListCallback(VfxId id, VfxS32 index);
    void cellButtonCallback(VfxId id);

    //
    void pushFrame(VfxFrame *frame, VfxU16 effect);
  	// onWallpaper button select
  	void onCommandPopCallback(VfxObject *obj, VfxId id);
    void onPushFinish(VfxBaseTimeline *thiz, VfxBool finish);
    void onReqClose(void);
    void updateMenuStatus(void);
    void showErrorPopup(const VfxResId &resId);
	void initMenu(void);
#ifndef __OP01__
	void showActiveWlanConfirm(void);
	void onCommandPopCallbackForWlan(VfxObject *obj, VfxId id);
#endif    
private:
    VappShellBrightnessSelPopup *m_brightScr;
    VappShellPageOrderConfigScr *m_orderScr;
    
    VappShellSettingContentProvider *m_content;
    VcpInlineMenu   *m_inlineMenu;

    VfxWeakPtr<VappShellWaitingPopup> m_waitingPopupWeakPtr;
    
    VfxId   m_idPending;
    VfxBool m_bNewVisual;

    VfxPointTimeline     *m_ptTimeline;
    VfxTransformTimeline *m_transTimeline;

    VfxBool m_bClosing;    
    VfxU16 m_uActiveScr;
	VfxU16 m_uSwitchSrc;
	
	VfxImageFrame *m_bg;
	VfxImageFrame *m_bgShadow;
	VfxImageFrame *m_topBar;
	VfxTextFrame *m_titleText;
	VfxImageFrame *m_bottomBar;
	
public:
	static mmi_ret evtHandler(mmi_event_struct *evt);
    static void switchCallback(VfxS32 finish);
    static mmi_ret switchCallback3(mmi_event_struct *evt);   
#ifdef __MMI_WLAN_FEATURES__
    static void switchHotspotCallback(VfxU16 tethering_type, MMI_BOOL result, void *user_data);
#endif
    static VappShellSettingsScr *s_currScr;

    friend class VappShellSettingContentProvider;
};

#endif /* __MMI_VUI_SHELL_SETTINGS__ */

#endif /* __VAPP_SHELL_SETTINGS_H__ */

