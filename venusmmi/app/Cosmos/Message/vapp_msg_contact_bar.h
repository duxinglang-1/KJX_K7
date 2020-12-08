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
 *  vapp_msg_contact_bar.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_MSG_CONTACT_BAR_H__
#define __VAPP_MSG_CONTACT_BAR_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcui_phb_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappMsgContactProvider;
class VappMsgContactListProvider;

enum VappMsgContactEnum
{
    VAPP_MSG_CONTACT_TYPE_NONE,
    VAPP_MSG_CONTACT_TYPE_PHONENUMBER,
    VAPP_MSG_CONTACT_TYPE_EMAIL,
    VAPP_MSG_CONTACT_TYPE_SNS_NICKNAME,
    VAPP_MSG_CONTACT_TYPE_ALPHANUMBIC,

    VAPP_MSG_CONTACT_TYPE_TOTAL
};

enum VappMsgContactBarModeEnum
{
    VAPP_MSG_BAR_MODE_DEFAULT,
    /* Show Recipient List always when click the address field */
    VAPP_MSG_BAR_MODE_SHOW_LIST_ALWAYS,
    VAPP_MSG_BAR_MODE_TOTAL
};


/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappMsgContact : public VfxBase
{
public:
    VappMsgContact() : 
        m_type(VAPP_MSG_CONTACT_TYPE_NONE)
    {
    };

    VappMsgContact& operator= (VappMsgContact& other)
    {
        m_type = other.m_type;
        m_address = other.m_address;
        m_statusIcon = other.m_statusIcon;
		return *this;
    };

public:
    VappMsgContactEnum m_type;
    VfxWString m_address;
    VfxImageSrc m_statusIcon;
};

class VappMsgContactBar : public VfxControl
{
    VFX_DECLARE_CLASS(VappMsgContactBar);

public:
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
	#endif
public:
    VappMsgContactBar();
    virtual ~VappMsgContactBar() {};
	void setLiteMode(VfxBool mode);
    void setContact(VappMsgContactProvider* provider);

    void setContact(VfxWString& contact, VappMsgContactEnum type);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
    //void setContact(VfxWString& contact, ContactType type);
    //Set the message's status icon in the portrait
    void setStatusIcon(const VfxImageSrc& image);

    //Set one icon in the right side, ex. SIM Card icon in Dual SIM Version or SNS Logo
    void setRightIcon(const VfxImageSrc& image);
    //Set two icon in the right side, ex, SIM Card icon and MMS's attachment icon.
    void setRightIcon(const VfxImageSrc& image1, const VfxImageSrc& image2);

    void setMode(VappMsgContactBarModeEnum mode);
    S32 getShadowHeight(void);

    void enableTap(VfxBool enable){};
	void onRotate();

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);
    virtual void onUpdate();
    virtual VfxBool onPenInput(VfxPenEvent& event);

private:
    void onBoundChanged(VfxFrame* frame, const VfxRect& rect);
    //void onProviderUpdate(void);

    void createSingleContactLayout(void);
    void createGroupContactLayout(void);

    void drawPortrait(void);
    void drawRightIcon(void);
    void drawAddressField(VfxWString& addrStr);

    VfxS32 getContactFieldRightX(void);

    void getSingleContactString(VfxWString& singleStr);
    void getGroupContactString(VfxWString& groupStr);
    void portraitPenDownEffect(void);
    void portraitPenUpEffect(void);
    void onClickPortrait(void);
    void onClickAddressField(void);

    VfxBool isHitFrame(VfxFrame* frame, VfxPenEvent& event);
    void onPopupButtonClicked(VfxObject* obj, VfxId id);
    void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void saveContact(vcui_phb_save_contact_type_enum tpye);

    static mmi_ret onPhbContactChanged(mmi_event_struct *param);
    static mmi_ret onCuiProc(mmi_event_struct *evt);

public:
	VfxSignal0 m_signalDeinit;

private:
    enum
    {
        MAX_RIGHT_ICON          = 2,

    #if defined(__MMI_MAINLCD_480X800__)
        ADDR_FONT_SIZE          = 30,
        BAR_SHADOW_HEIGHT       = 4,
    #elif defined(__MMI_MAINLCD_320X480__)
        ADDR_FONT_SIZE          = 21,
        BAR_SHADOW_HEIGHT       = 2,
    #else /* __MMI_MAINLCD_240X320__ __MMI_MAINLCD_240X400__  */
        ADDR_FONT_SIZE          = 18,
        BAR_SHADOW_HEIGHT       = 2,
    #endif

        TEXT_ICON_OFFSET        = 10,
        ICON_ICON_OFFSET        = 12,
        MAX_GROUP_ADDR_LINE     = 1
    };

    enum buttonId
    {
        BUTTON_ADD_NEW,
        BUTTON_ADD_EXIST,
        BUTTON_CANCEL
    };

    VappMsgContact m_contact;
    VappMsgContactProvider *m_provider;
    VfxImageSrc m_rightIcon1;
    VfxImageSrc m_rightIcon2;

    VfxFrame *m_portraitBgFrame;
    VfxFrame *m_portraitFgFrame;
    VfxFrame *m_portraitFrame;
    VfxFrame *m_statusFrame;
    VfxTextFrame *m_addrFrame;
    VfxImageFrame *m_rightFrame1;
    VfxImageFrame *m_rightFrame2;

    VfxPoint m_singlePos;
    VfxPoint m_groupPos;

    VfxBool m_isLayoutCreated;
    VfxBool m_isGroup;
    VfxBool m_isOriGroup;
	VfxBool m_isLiteMode;

    VfxBool m_isHitPortrait;
    VfxBool m_isHitAddr;
    VfxBool m_isSaveEnabled;
    VfxBool m_isHitAddrEnabled;
    VfxBool m_isDataReady;
    VappMsgContactBarModeEnum m_mode;

    VfxId m_buttonId;
};

class VappMsgContactProvider : public VfxObject
{
    //VFX_DECLARE_CLASS(VappMsgContactProvider);

public:
    VappMsgContactProvider(){};

    virtual VfxBool getContact(VappMsgContact& contact, VcpMenuPos index = VcpMenuPos(0, 0))
    {
        return VFX_FALSE;
    };

	virtual VfxU32 getCount(VfxU32 group = 0) const
	{
        return 0;
	};

	virtual VfxU32 getGroupCount(void) const
	{
	    return 1;
    };

	virtual VfxBool hasGroupHeader(VfxS32 group) const
	{
    	return VFX_FALSE;
	};

	virtual VfxBool getHeaderText(VfxS32 group, VfxWString& text) const
	{
    	return VFX_FALSE;
	};

	virtual VfxBool getGroupPrefix(VfxU32 group, VfxWString& text) const
	{
    	return VFX_FALSE;
	};

	virtual VfxBool isShowMemberInBar(VfxU32 group) const
	{
    	return VFX_TRUE;
	};

    virtual VfxBool isShowRecipientList(VfxWString& causeStr)
    {
        return VFX_TRUE;
    };

    virtual VfxBool isResendFailed(void)
    {
        return VFX_TRUE;
    };

    virtual VfxBool isDisableResendButton(void)
    {
        return VFX_FALSE;
    };

    virtual void resendFailed(void)
    {
    };

public:
    static VfxBool getContactName(VfxWString& name, VfxWString& address, VappMsgContactEnum type);
    static VfxBool getContactPhbName(VfxWString& name, VfxWString& address, VappMsgContactEnum type);
    static void getContactImage(
            		VfxImageSrc& image,
            		VfxWString& address,
            		VappMsgContactEnum type = VAPP_MSG_CONTACT_TYPE_PHONENUMBER);
    static void getEmptyContactName(VfxWString& name, VappMsgContactEnum type);

public:
    //VfxSignal0 m_signalUpdate;
};

class VappMsgContactListPage : public VfxPage
{
public:
    VappMsgContactListPage();
	VappMsgContactListPage(VappMsgContactBar *contactbar);
    virtual ~VappMsgContactListPage() {};

    void setProvider(VappMsgContactProvider* provider);

protected:
    virtual void onInit(void);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    virtual void onUpdate(void);

private:
    //void onProviderUpdate(void);
    void onButtonClicked(VfxObject * sender, VfxId bottomId);
	void onMemoryOut(void);

private:
    enum buttonId
    {
        BUTTON_RESEND_FAILED
    };

private:
    VappMsgContactListProvider *m_listProvider;
    VappMsgContactProvider *m_contactProvider;
	VcpGroupListMenu *m_listMenu;
	VcpToolBar *m_toolBar;
	VfxWeakPtr<VfxObject> m_contactBar;
	VfxBool m_isProviderUpdate;
};

class VappMsgContactListProvider : public VfxObject, public IVcpGroupListMenuContentProvider
{
public:
    VappMsgContactListProvider();
    virtual ~VappMsgContactListProvider(){};

    void setProvider(VappMsgContactProvider* provider);

    virtual VfxBool getItemText(
                VcpMenuPos pos,
                VcpListMenuFieldEnum fieldType,
                VfxWString& text,
                VcpListMenuTextColorEnum& color);

    virtual VfxBool getItemImage(
                VcpMenuPos pos,
                VcpListMenuFieldEnum fieldType,
                VfxImageSrc& image);

    virtual VfxU32 getCount(VfxU32 group) const;
	virtual VfxBool hasGroupHeader(VfxS32 group) const;
	virtual VfxU32 getGroupCount(void) const;
    virtual VfxBool getItemIsHighlightable(VcpMenuPos pos) const;

private:
    VappMsgContactProvider *m_provider;
};
#endif /* __VAPP_MSG_CONTACT_BAR_H__ */

