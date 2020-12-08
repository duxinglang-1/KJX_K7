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
 *  vapp_sms_setting_scrn.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_SETTING_SCRN_H__
#define __VAPP_SMS_SETTING_SCRN_H__
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_form.h"
#include "vapp_sms_setting_core.h"
#include "vapp_msg_features.h"

/***************************************************************************** 
 * Class 
 *****************************************************************************/
#ifdef __OP01__
#define __VAPP_SMSPREFER_STORAGE_SETTING__
#endif
class VappSmsPreferBearerPage;
class VappSmsProfileListPage;
class VappSmsPreferStoragePage;
/***************************************************************************** 
 * Class VcpSmsSwitch
 *****************************************************************************/
class VcpSmsSwitch : public VcpSwitch
{
    //VFX_DECLARE_CLASS(VcpSmsSwitch);
public:
	VcpSmsSwitch();
	
public:
	void setMovable(VfxBool isMovable);
protected:
	virtual VfxBool onPenInput(VfxPenEvent &event);
public:
    VfxSignal0 m_signalSwitchUnmovable;

private:
    VfxBool m_isSwitchMovable;
};

/***************************************************************************** 
 * Class VappSmsSettingSwitchCp
 *****************************************************************************/
class VappSmsSettingSwitchCp : public VcpListMenuCellBaseControl
{
    //VFX_DECLARE_CLASS(VappSmsSettingSwitchCp);

    typedef VappSmsSettingSwitchCp        Self;
    typedef VcpListMenuCellBaseControl    Super;

public:
    virtual void show() {};
    virtual void hide() {};
    void setSwitchStatus(VfxBool checked);
	void setSwitchMovable(VfxBool isMovable);


protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void OnSwitchSignal(VcpSwitch *sender, VfxBool isChecked);
	void onSwitchUnmovable();
    void onSwitchBoundsChanged(VfxFrame *source, const VfxRect &oldBounds);

public:
    VfxSignal2 <VfxObject*, VfxBool> m_signalSwitchChanged;
	VfxSignal0 m_signalSwitchUnmovable;
	

private:
    VfxBool m_switchStatus;
    VcpSmsSwitch *m_switch;
};

/***************************************************************************** 
 * Class VappSmsSettingPage
 *****************************************************************************/

class VappSmsSettingPage : public VfxPage,public IVcpGroupListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappSmsSettingPage);

    typedef VappSmsSettingPage    Self;
    typedef VfxPage               Super;

public:
    VappSmsSettingPage();
    virtual ~VappSmsSettingPage(){};
    virtual VfxU32 getCount(VfxU32 group) const;
    virtual VfxU32 getGroupCount() const;
    virtual VfxBool getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxBool getItemIsDisabled(
        VcpMenuPos pos   // [IN] position of the item
        ) const;
    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
    virtual VfxBool getItemIsHighlightable(
        VcpMenuPos pos   // [IN] position of the item
        ) const;
    virtual VcpListMenuCellBaseControl* getItemCustomControl(
        VcpMenuPos pos,                                  // [IN] position of the item
        VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
        VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
        );
    virtual VcpListMenuCellClientBaseFrame* getItemCustomContentFrame(VcpMenuPos pos, VfxFrame *parentFrame);
    virtual VfxBool hasGroupHeader(VfxS32 group) const;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void OnRPSwitch(VfxObject *sw, VfxBool isChecked);
#ifdef __SRV_SMS_DELIVERY_STATUS__
    void OnSRSwitch(VfxObject *sender, VfxBool isChecked);
	void OnSRSwitchUnmovable();
#endif
    void onItemTapped(VcpGroupListMenu *sender, VcpMenuPos pos);
    void onSelectNewItem(VfxObject *sender, VfxWString wString, srv_sms_sim_enum simId);
#ifdef __SMS_OVER_PS_SUPPORT__
    void onInitBearerDone(VfxObject *sender, VfxBool result);
    void onChangedBearer(VfxObject *sender, VfxU8 index);
#endif
	static mmi_ret onFlightModeSwitchProc(mmi_event_struct *evt);
    void getGroupNumber();

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	void onDefaultStorageChanged();
	void onSmsMsgFilterChanged();
#endif

private:
    enum
    {
        VAPP_SMS_SETTING_GROUP_ALL_SIM,
        VAPP_SMS_SETTING_GROUP_SIM_1
    };

    enum
    {
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		ITEM_ID_DEFAULT_STORAGE,
		ITEM_ID_MSG_FILTER,
	#endif
    #ifdef __SMS_OVER_PS_SUPPORT__
        ITEM_ID_PREFER_BEARER,
    #endif
        ITEM_ID_REPLY_PATH,

        ITEM_ID_PROFILE_SETTING = 0,
        ITEM_ID_VOICEMAIL_SERVER,
        ITEM_ID_DELIVERY_REPORT,
    #ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
        ITEM_ID_PREFER_STORAGE,
    #endif
    };

    VcpGroupListMenu *m_groupListMenu;
    SmsSetting *m_settings;
    VappSmsPreferBearerPage *m_bearerPage;
	VappSmsPreferStoragePage *m_selectPage;
    VappSmsProfileListPage *m_profilePage;
    VappSmsSettingSwitchCp *m_listMenuControl[VAPP_SMS_TOTAL_SIM];
	SmsProfileList *m_profileList[VAPP_SMS_TOTAL_SIM];
    VfxS32 m_groupNumber;
    VfxS32 m_groupToSimIndex[VAPP_SMS_TOTAL_SIM];
	VfxU8 m_isNosimInsert;
};


/***************************************************************************** 
 * Class VappSmsPreferBearerPage
 *****************************************************************************/
#ifdef __SMS_OVER_PS_SUPPORT__
class VappSmsPreferBearerPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappSmsPreferBearerPage);

    typedef VappSmsPreferBearerPage    Self;
    typedef VfxPage                    Super;

public:
    VappSmsPreferBearerPage(){}
    VappSmsPreferBearerPage(VfxU8 bearer):  m_curBearer(bearer){}
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onBearerItemTapped(VcpListMenu *sender, VfxU32 index);

public:
    VfxSignal2 <VfxObject *, VfxU8> m_signalChangedBearer;

private:
    enum
    {
        ITEM_ID_SMS_BRARER_PRE_GPRS,
        ITEM_ID_SMS_BRARER_PRE_GSM,
        ITEM_ID_SMS_BRARER_GSM_ONLY,
        ITEM_ID_SMS_BRARER_TOTAL
    };

    VcpListMenu *m_listMenu;
    VfxU8 m_curBearer;
};
#endif //__SMS_OVER_PS_SUPPORT__


/**************************************************************************** 
 * Class VappSmsProfileListPage
 *****************************************************************************/
class VappSmsProfileListPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappSmsProfileListPage);

    typedef VappSmsProfileListPage    Self;
    typedef VfxPage                   Super;

public:
	VappSmsProfileListPage(){}
    VappSmsProfileListPage(srv_sms_sim_enum simId, SmsProfileList *profileList)
		: m_profileList(profileList), m_simId(simId){}
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onProfileListItemTapped(VcpListMenu *sender, VfxU32 index);
    void onProfleChanged(VfxObject *sender, VfxWString name, VfxU8 index);
    void onEditButtonClicked(VcpListMenu *Sender, VfxU32 index);
    void onLoadPrfoleListDone(VfxBool result);

public:
    VfxSignal3<VfxObject*, VfxWString, srv_sms_sim_enum> m_signalActiveProfilechanged;

private:
	SmsProfile *m_profile[SRV_SMS_MAX_LFOUR_PROFILES];
    VcpTitleBar *m_titleBar;
    VcpListMenu *m_listMenu;
    SmsProfileList *m_profileList;
    srv_sms_sim_enum m_simId;
};


/***************************************************************************** 
 * Class VappSmsProfileEditPage
 *****************************************************************************/
class VappSmsProfileEditPage : public VfxPage
{
    //VFX_DECLARE_CLASS(VappSmsProfileEditPage);

    typedef VappSmsProfileEditPage    Self;
    typedef VfxPage                   Super;

public:
    typedef struct
    {
        srv_sms_sim_enum simId;
        VfxU8 profileIndex;
        VfxU8 profileNameLen;
    }VappSmsProfileEditInitData;

public:
    VappSmsProfileEditPage();
    VappSmsProfileEditPage(VappSmsProfileEditInitData data, SmsProfile *profile);

protected:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onToolbarTapped(VfxObject *sender, VfxId id);
    void onProfileItemTapped(VfxId id);
#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__
    void onVpChanged(VfxObject *sender, VfxS32 value);
#endif
#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__

    void onMsgTypeChanged(VfxObject *sender, VfxS32 value);
#endif
    void onFunctionBarClicked(VfxObject *sender, VfxId id);
    void onSetTextEditorState(VfxId id,VfxBool activated);
    void onTextActivated(VcpTextEditor *sender, VfxBool  activated);
    void onBarSaveCommond();
	void updateView();

public:
    VfxSignal3<VfxObject*, //sender
        VfxWString, // name
        VfxU8 // Server index
    > m_signalProfileChanged;

private:
    enum
    {
        ITEM_ID_TOOLBAR_SAVE,
        ITEM_ID_TOOLBAR_CANCLE,
        ITEM_ID_PROFILE_NAME,
        ITEM_ID_PROFILE_SC,
    #ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__
        ITEM_ID_VALIDITY_PERIOD,
    #endif
	#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__
        ITEM_ID_MESSAGE_TYPE,
    #endif
        ITEM_ID_PROFILE_EDITOR_NAME,
        ITEM_ID_PROFILE_EDITOR_SC,
        ITEM_ID_FUNCBAR_PREV,
        ITEM_ID_FUNCBAR_NEXT,
        ITEM_ID_FUNCBAR_SAVE,
        TTEM_ID_TOTAL
    };

    VcpForm *m_form;
    VcpToolBar *m_toolBar;
    SmsProfile *m_profile;
    srv_sms_sim_enum m_simId;
    VfxU8 m_profleIndex;
    VfxU8 m_profileNameLen;
};

#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__

/***************************************************************************** 
 * Class VappSmsVpSelectPage
 *****************************************************************************/
class VappSmsVpSelectPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappSmsVpSelectPage);

    typedef VappSmsVpSelectPage      Self;
    typedef VfxPage                  Super;

public:
    typedef struct
    {
        srv_sms_sim_enum simId;
        VfxU8 curVp;
    }VappSmsVpSelectInitData;

public:
    VappSmsVpSelectPage(){}
    VappSmsVpSelectPage(VappSmsVpSelectInitData data): m_curVp(data.curVp), m_simId(data.simId){}
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onVpItemTapped(VcpListMenu *sender, VfxU32 index);

public:
    VfxSignal2 <VfxObject *, VfxS32> m_signalSelectNewItem;

private:
    enum
    {
        ITEM_ID_SMS_VP_1HOUR,
        ITEM_ID_SMS_VP_6HOUR,
        ITEM_ID_SMS_VP_12HOUR,
        ITEM_ID_SMS_VP_1DAY,
        ITEM_ID_SMS_VP_3DAYS,
        ITEM_ID_SMS_VP_1WEEK,
        ITEM_ID_SMS_VP_MAX,
        ITEM_ID_SMS_VP_TOTAL
    };

    VcpListMenu *m_listMenu;
    VfxS32 m_curVp;
    srv_sms_sim_enum m_simId;
};
#endif

#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__

/***************************************************************************** 
 * Class VappSmsTypeSelectPage
 *****************************************************************************/
class VappSmsTypeSelectPage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappSmsTypeSelectPage);

    typedef VappSmsTypeSelectPage    Self;
    typedef VfxPage                  Super;

public:
    typedef struct
    {
        srv_sms_sim_enum simId;
        VfxU8 curType;
    }VappSmsTypeSelectInitData;

public:
    VappSmsTypeSelectPage(){}
    VappSmsTypeSelectPage(VappSmsTypeSelectInitData data): m_curType(data.curType), m_simId(data.simId){}
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onSmsTypeItemTapped(VcpListMenu *sender, VfxU32 index);

public:
    VfxSignal2 <VfxObject *, VfxS32> m_signalSelectNewItem;

private:
    enum
    {
        ITEM_ID_SMS_PID_PAGING,
        ITEM_ID_SMS_PID_EMAIL,
        ITEM_ID_SMS_PID_DEFAULT,
        ITEM_ID_SMS_PID_FAX_GP3,
        ITEM_ID_SMS_PID_FAX_GP4,
        ITEM_ID_SMS_PID_TOTAL
    };

    VcpListMenu *m_listMenu;
    VfxS32 m_curType;
    srv_sms_sim_enum m_simId;
};
#endif

/***************************************************************************** 
 * Class VappSmsTypeSelectPage
 *****************************************************************************/
#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
class VappSmsPreferStoragePage : public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappSmsPreferStoragePage);

public:
	enum VappPreStoEnum
	{
		VAPP_PRESTO_ID_ME,
		VAPP_PRESTO_ID_SIM,
		VAPP_PRESTO_ID_MAX
	};
	VappSmsPreferStoragePage::VappSmsPreferStoragePage(VfxS32 simindex);
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

protected:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	
private:
	void onItemTapped(VcpListMenu *sender, VfxU32 index);
	static void onPreferStorageInitDone(srv_sms_callback_struct *callbackData);
public:
	VfxSignal2 <VfxObject *, VfxS32> m_signalSelectNewItem;
private:
	VfxBool m_isMePreferStorage;
	srv_sms_storage_enum m_preferStorage;
	VcpListMenu *m_listMenu;
	VfxS32 m_simIndex;
};
#endif


#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
class VappSmsDefaultStoragePage : public VfxPage, public IVcpListMenuContentProvider
{
public:
	enum
	{
		ITEM_ID_PHONE,
		ITEM_ID_TCARD,
		ITEM_ID_MAX
	};
	
	VappSmsDefaultStoragePage();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemIsDisabled(
        VfxU32 index
        ) const;
	
protected:
	virtual void onInit();	
	virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
	void onItemTapped(VcpListMenu *sender, VfxU32 index);
	static mmi_ret onTcardPlugInOutProc(mmi_event_struct *evt);

public:
	VfxSignal0 m_signalDefaultStorageChanged;
	
private:
	VcpListMenu *m_listMenu;
};

class VappSmsMsgFilterPage : public VfxPage, public IVcpListMenuContentProvider
{
public:
	enum
	{
		ITEM_ID_PHONE,
		ITEM_ID_TCARD,
		ITEM_ID_MAX
	};
	enum
	{
		ITEM_ID_TOOLBAR_OK,
		ITEM_ID_TOOLBAR_CANCEL,
		ITEM_ID_TOOLBAR_MAX
	};
	
	VappSmsMsgFilterPage();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );
    virtual VfxBool getItemIsDisabled(
        VfxU32 index   // [IN] position of the item
        ) const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
	
protected:
	virtual void onInit();	
	virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
	//void onItemTapped(VcpListMenu *sender, VfxU32 index);
	void onToolbarTapped(VfxObject *sender, VfxId id);
	void onItemStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
	static mmi_ret onTcardPlugInOutProc(mmi_event_struct *evt);
	
public:
	VfxSignal0 m_signalSmsMsgFilterChanged;
	
private:
	VcpListMenu *m_listMenu;
	VcpToolBar *m_toolBar;
	VfxBool m_isItemSelected[ITEM_ID_MAX];
};

#endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
#endif /* __VAPP_SMS_SETTING_H__ */
