/*  Copyright Statement:
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
 *  vapp_sns_settings.h
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_SETTINGS_H__
#define __VAPP_SNS_SETTINGS_H__

#include "MMI_features.h"

#ifdef __MMI_SSO__

#ifdef __cplusplus
extern "C"
{
#endif
#include "SsoSrvGprot.h"
#ifdef __cplusplus
}
#endif
#endif

#include "vfx_page.h"
#include "vcp_form.h"
#include "vcp_text_editor.h"

#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)
#include "vcui_sso_gprot.h"
#include "vapp_sso_sns_account_setting.h"
#endif

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vapp_sns_base.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvGprot.h"
#ifdef __cplusplus
}
#endif

#ifndef __SSO_DEV__
#define __SSO_DEV__
#endif

class VappSnsSettingsPage : public VappSnsBasePage
{
    VFX_DECLARE_CLASS(VappSnsSettingsPage);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEntered();
    
    void onItemTap(VcpFormItemCell* cell, VfxId cell_id);
private:
    void enterAccountsSettings();
    void getReminderText(VfxWString &text);
    
    static mmi_ret dtcntEvtListener(mmi_event_struct* evt);
    static mmi_ret Listener(mmi_event_struct* evt);
    enum
	{
		ID_SNS_ACCOUNTS_SETTINGS = 1,
		ID_SNS_NEWS_REMINDER,

        ID_SNS_END
	};

    VfxU32 m_intervalId;
    VcpForm *m_form;
    VcpFormItemLauncherCell *m_accounts_settings;
    VcpFormItemLauncherCell *m_news_reminder;
};

class VappAccountSetupPage : public VappSnsBasePage
{
    VFX_DECLARE_CLASS(VappAccountSetupPage);

public:
    VappAccountSetupPage();
    VappAccountSetupPage(VfxU32 provider, VfxWChar *user, VfxWChar *title, VfxBool syncContacts, VfxBool syncCalendar);
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    
private:
    void onSwitch(VcpFormItemSwitchCell* cell, VfxId cell_id, VfxBool state);

    void onMenuButtonTap(VfxObject *sender, VfxId id);

    void showProcessingPop(VfxWString str);
    void onCancelProcessing(VfxObject *obj, VfxFloat processing);
    static mmi_ret onLogoutCb(mmi_event_struct *param);
private:
    void logout();
    void switchSyncContacts(VcpFormItemSwitchCell* cell, VfxBool state);
    void switchSyncCalendar(VcpFormItemSwitchCell* cell, VfxBool state);
    void onItemTap(VcpFormItemCell* cell, VfxId cell_id);

    static mmi_ret Listener(mmi_event_struct* evt);
private:  
    enum VAPP_ACCOUNT_SETUP_ITEM_TYPE
    {
        ID_SYNC_CONTACTS = 1,
        ID_SYNC_CALENDAR,
        ID_SNS_LOGOUT,

        ID_TOTAL
    };

    #define SNS_PW_MASK_STR VfxWString().format("********")
    
    VfxU32 m_provider;
    VfxS32 m_reqId;
    VcpIndicatorPopup *m_processing;
    VfxBool m_syncCalendarFlag;
    VfxBool m_syncContactsFlag;
    VfxId m_currActiveId;
    VfxChar *m_title;
    VfxChar *m_user;
    VcpForm *m_form;
    VcpFormItemSwitchCell *m_syncCalendar;
    VcpFormItemSwitchCell *m_syncContact;
    VcpFormItemLauncherCell *m_logout;
    static VappAccountSetupPage *m_self;
};

class VappSyncIntervalPage : public VappSnsBasePage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSyncIntervalPage);
public:
    VappSyncIntervalPage();
    VappSyncIntervalPage(VfxU32 index, VfxBool isReminder = VFX_FALSE);
    
protected:
    virtual void onInit();
    virtual void onDeinit();
public:
    // <group DOM_ListMenu_IVcpListMenuContentProvider_Overridable>
    // Get the text resource for the text fields of list cell
    // RETURNS: VFX_TRUE or VFX_FALSE
    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

public:
    static VfxU32 secToIndex(srv_sns_sync_interval_enum interval,  VfxWString &text);
    
private:
    void onItemTapped(VcpListMenu *list_menu, VfxU32 index);

    srv_sns_sync_interval_enum indexToEnum(VfxU32 index);

    static mmi_ret Listener(mmi_event_struct* evt);
private:
    #define LIST_COUNT 7
    #define REMINDER_LIST_COUNT 6

    VfxBool m_isReminder;
    VfxU32 m_currentIndex;
    VcpListMenu *m_list;
};
#endif /* __SOCIAL_NETWORK_SUPPORT__*/

#if defined(__SOCIAL_NETWORK_SUPPORT__)
class VappAccountsCell : public VcpFormItemCell
{
    VFX_DECLARE_CLASS(VappAccountsCell);

public:
    VappAccountsCell();
    VappAccountsCell(srv_sns_account_struct *account);

public:
    void update(void);
    void updateAccount(srv_sns_account_struct *account);
    srv_sns_account_struct* getAccount();

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);

    virtual void onCellTap(VfxPenEvent &event);

private:
    void onButtonClicked(VfxObject *item, VfxId id);
    void snsInit(void);

private:

#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 10,
        TEXT1_TOP_GAPS    = 6,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 10,
        TEXT2_BOTTOM_GAPS = 6,
        IMG_LEFT_GAPS     = 10,
        IMG_RIGHT_GAPS    = 10,
        IMG_MAX_WIDTH     = 30
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 14,
        TEXT1_TOP_GAPS    = 13,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 14,
        TEXT2_BOTTOM_GAPS = 13,
        IMG_LEFT_GAPS     = 14,
        IMG_RIGHT_GAPS    = 14,
        IMG_MAX_WIDTH     = 45
    };
#else
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 5,
        TEXT1_TOP_GAPS    = 7,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 5,
        TEXT2_BOTTOM_GAPS = 4,
        IMG_LEFT_GAPS     = 5,
        IMG_RIGHT_GAPS    = 5,
        IMG_MAX_WIDTH     = 25
    };
#endif

#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        TAIL_FRAME_LEFT_GAPS   = 0,
        TAIL_FRAME_RIGHT_GAPS  = 10,
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TAIL_FRAME_LEFT_GAPS   = 0,
        TAIL_FRAME_RIGHT_GAPS  = 14,
    };
#else
    enum
    {
        TAIL_FRAME_LEFT_GAPS  = 0,
        TAIL_FRAME_RIGHT_GAPS  = 5
    };
#endif

#if defined(__MMI_MAINLCD_320X480__)
#define FONT_SIZE_HINT           VFX_FONT_DESC_VF_SIZE(14)
#define FONT_SIZE_MAIN          VFX_FONT_DESC_VF_SIZE(20)
#elif defined(__MMI_MAINLCD_480X800__)
#define FONT_SIZE_HINT           VFX_FONT_DESC_VF_SIZE(21)
#define FONT_SIZE_MAIN          VFX_FONT_DESC_VF_SIZE(30)
#else
#define FONT_SIZE_HINT           VFX_FONT_DESC_VF_SIZE(12)
#define FONT_SIZE_MAIN          VFX_FONT_DESC_VF_SIZE(16)
#endif

    VfxImageFrame *m_icon;
    VcpImageButton *m_sync;
    VfxImageFrame *m_doingSync;
    srv_sns_account_struct *m_account;

};
#endif /* defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__) */
#endif /* __VAPP_SNS_SETTINGS_H__ */

