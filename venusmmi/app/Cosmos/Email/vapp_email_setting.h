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
 *  Vapp_email_setting.h
 *
 * Project:
 * --------
 *  COSMOS Email Account Global Setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_EMAIL_SETTING_H_
#define _VAPP_EMAIL_SETTING_H_

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#ifdef __EMAIL_COSMOS_DBG__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

extern "C" {
#include "EmailSrvGprot.h"
#include "FileMgrSrvGprot.h"
}

#include "vapp_email_prot.h"
#include "vapp_email_acct.h"
#include "vapp_email_mgr.h"

class VappEmailGlobalSettingScr: public VfxMainScr
{
public:
    VappEmailGlobalSettingScr();
    virtual ~VappEmailGlobalSettingScr();
    virtual void on1stReady();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
};

class VappEmailGlobalSettingCustomContentFrame
    : public VcpListMenuCellMultiTextFrame
{
public:
    virtual void onLayoutElements();
};

class VappEmailSettingSwitch : public VcpListMenuCellBaseControl
{
public:
    void setChecked(VfxBool checked, VfxBool isAnimated = VFX_TRUE);

public:
    VfxSignal2<VappEmailSettingSwitch*, VfxBool> m_signalSwitchChanged;

public:
    virtual void show();
    virtual void hide();
    
protected:
    virtual void onInit();
    virtual void setBounds(const VfxRect &value);

private:
    void emitSignal(VcpSwitch *sender, VfxBool state);
    
private:
    VcpSwitch *m_switch;
};


class VappEmailGlobalSettingMainPage
    : public VfxPage, public IVcpGroupListMenuContentProvider
{
public:
    VappEmailGlobalSettingMainPage();
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }

    virtual VfxU32 getCount(VfxU32 group) const;
    virtual VfxU32 getGroupCount() const;
    virtual VfxBool getItemText(
        VcpMenuPos,
        VcpListMenuFieldEnum,
        VfxWString&,
        VcpListMenuTextColorEnum&);
    virtual VfxBool getItemTextFormat(
        VcpMenuPos pos,
        VcpListMenuFieldEnum fieldType,
        VcpRichText &format);
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VcpMenuPos,
        VfxFrame *);
    virtual VcpListMenuCellBaseControl *getItemCustomControl(VcpMenuPos,
        VcpListMenuCellControlLocationTypeEnum,
        VfxFrame*);
    virtual VfxBool getItemImage(VcpMenuPos,
        VcpListMenuFieldEnum,
        VfxImageSrc &image);
    virtual VfxBool getItemIsHighlightable(VcpMenuPos pos) const;
    virtual VfxBool getItemIsDisabled(VcpMenuPos pos) const;
    EMAIL_ACCT_ID getAcctId(VfxU32) const;

public:
    enum EmailglobalSettingItemEnum
    {
        ITEM_SHOW_CC_BCC = 0,
        ITEM_DEFAULT_ACCT,
#ifdef __MMI_EMAIL_IMAP_PUSH__
        ITEM_PUSH_ACCT,
#endif
#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
        ITEM_STORAGE,
#endif
        ITEM_PRIORITY,
        ITEM_TOTAL
    };

    enum
    {
        ITEM_MENU_CLEAR = 0,
        ITEM_MENU_CREATE,
        ITEM_MENU_CLEAR_CREATE,
        ITEM_MENU_SET_MAX_ATT_SIZE,
        ITEM_MENU_FILL_STORAGE,
    };

private:
    void initData();
    void onToolBarClick(VfxObject* sender, VfxId id);
    void onMenuItemTapped(VcpGroupListMenu *menu, VcpMenuPos pos);
#ifdef __MTK_INTERNAL__
#ifdef __EMAIL_COSMOS_DBG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    void onPrioritySave(VfxObject *obj, VfxS32 selectedIndex);
    void onShowCcBccSwitchClick(VappEmailSettingSwitch*, VfxBool);
#ifdef __MMI_EMAIL_IMAP_PUSH__
    void onPushEnableSwitchClick(VappEmailSettingSwitch*,VfxBool enable);
#endif

private:
    VcpMenuPos selectedIndex;
    VfxU32 totalAcct;
    VfxBool showCcBcc;
    EMAIL_MSG_PRIO priority;
    EMAIL_ACCT_ID acctIdArray[MMI_EMAIL_MAX_ACCTS];
    EMAIL_ACCT_ID defaultAcctID;
    VcpToolBar *m_toolBar;
    VcpGroupListMenu *m_menu;
};

#ifndef __MMI_EMAIL_STOR_CANNOT_SWITCH__
class VappEmailGlobalSettingStoragePage
    : public VfxPage, public IVcpListMenuContentProvider
{
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemIsDisabled(VfxU32 index) const;

private:
    void initData();
    void onTcardPlug(VfxBool in);
    void onItemTapped(VcpListMenu *, VfxU32 index);
    void onSwitchStorage(VappEmailResEnum res);
    
private:
    enum {
        MENU_ITEM_PHONE = 0,
        MENU_ITEM_TCARD,
        MENU_ITEM_TOTAL,
    };

    VcpIndicatorPopup *indicator_pop;
    VcpListMenu *m_menu;
    VfxU32 m_itemCount;
    VfxU32 m_initSelectIndex;
    VfxU32 m_selectedIndex;
    VfxS32 drvCount;
    VfxBool isMemoryCardValid;
    U8 initDrvIndex;
};
#endif

class VappEmailGlobalSettingDftAcctPage
    : public VfxPage, public IVcpListMenuContentProvider
{
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }

    virtual VfxBool getItemText(
        VfxU32,
        VcpListMenuFieldEnum,
        VfxWString &,
        VcpListMenuTextColorEnum &color);
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

private:
    void initData();
    void onItemTapped(VcpListMenu *, VfxU32 index);

private:
    VcpIndicatorPopup *indicator_pop;
    VcpListMenu *m_menu;
    VfxU32 m_acctCount;
    EMAIL_ACCT_ID m_dftAcctId;
    EMAIL_ACCT_ID m_acctId[MMI_EMAIL_MAX_ACCTS + 1];
};


#ifdef __MMI_EMAIL_IMAP_PUSH__

class VappEmailGlobalSettingPushAcctPage
    : public VfxPage, public IVcpListMenuContentProvider
{
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }

    virtual VfxBool getItemText(
        VfxU32,
        VcpListMenuFieldEnum,
        VfxWString &,
        VcpListMenuTextColorEnum &color);
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

private:
    void initData();
    void onItemTapped(VcpListMenu *, VfxU32 index);

private:
    VcpListMenu *m_menu;
    EMAIL_ACCT_ID m_acctId[MMI_EMAIL_MAX_ACCTS];  //For select IMAP4 accounts    
    VfxU32 m_acctCount;
    EMAIL_ACCT_ID m_pushAcctId;
};

#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

extern VappEmailGlobalSettingScr *globalSettingScrPtr;

#endif /* _VAPP_EMAIL_SETTING_H_ */

