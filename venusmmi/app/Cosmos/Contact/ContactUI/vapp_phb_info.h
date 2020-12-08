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
 *  vapp_phb_info.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __PB_INFO_H__
#define __PB_INFO_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_form.h"
#include "vcp_menu_popup.h"

#include "vapp_contact_entry.h"
#include "vapp_contact_vcard.h"
#include "vapp_phb_editor.h"
#include "vapp_uc_gprot.h"
#include "vapp_phb_gprot.h"
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MMI_SNS_CONTACTS__
#include "SnsSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappPhbViewerScr
 *****************************************************************************/ 
class VappPhbViewerScr : public VfxMainScr
{
public:
    VappPhbViewerScr(mmi_phb_contact_id id);

    void onContactUpdated(ContactTask* task, mmi_event_struct* evt);

protected:
    virtual void on1stReady();

    virtual void on2ndReady();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    mmi_phb_contact_id m_id;
    VfxPage *m_page;

    VappPhbViewerScr(){}
};


/***************************************************************************** 
 * Class VappPhbViewerPage
 *****************************************************************************/ 
class VappPhbViewerPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappPhbViewerPage);

public:
    VappPhbViewerPage(mmi_phb_contact_id id):
        m_id(id){}

protected:
    virtual void onInit();

    virtual VfxPage *onCreateTabPage(VfxId tabId);

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

public:
    void updatePage();

private:
    VfxPage *m_profilePage;

private:
    mmi_phb_contact_id m_id;

    VappPhbViewerPage(){}
};


/***************************************************************************** 
 * Class VappPhbViewerProfilePage
 *****************************************************************************/
 #ifdef __MMI_PHB_NEED_SERIALZE__
    typedef struct
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        VappUcEntryStruct *entry;
    #endif
        mmi_id m_groupId;
        mmi_phb_contact_id m_id;
        mmi_id m_cuiId; 
        VfxApp *m_ptr;

    }VappPhbUcSerialze;
#endif
class VappPhbViewerProfilePage : public VfxPage
{
public:
    VappPhbViewerProfilePage(mmi_phb_contact_id id, VfxBool viewOnly = VFX_FALSE);

    void onToolBarClick(VfxObject* obj, VfxId id);

    void onMoreActionClick(VfxObject *obj, VfxId id);

    void moreAction(VfxObject *obj, VfxId id);
#ifdef __MMI_PHB_BIRTHDAY_FIELD__

    void onBdayClicked(VfxObject* obj, VfxId id);
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

    void selectSimPopup(VfxBool call, mmi_sim_enum sim);

    void onSimSelected(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);
	#ifdef __IP_NUMBER__
	void onIpSimSelected(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);
	#endif /* __IP_NUMBER__ */
    void makeCall(VfxObject *obj, VfxId id);

    void makeChildCall(VcpButton *button, VfxId id);

    void sendMsg(VfxObject *obj, VfxId id);

    void sendChildMsg(VcpButton *button, VfxId id);

    void sendEmail(VfxObject *obj, VfxId id);
	
#ifdef __MMI_VCARD__
    void onShareSelected(VfxObject *obj, VfxId id);

    void shareContact();
#endif /* __MMI_VCARD__ */
    
#ifdef __MMI_SNS_CONTACTS__
    void updatePage();
#endif
#ifdef __IP_NUMBER__
    void simPopupShow(VfxObject *obj, VfxU32 m_itemId);
#endif /* __IP_NUMBER__ */
#if (defined( __MMI_SMS_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__))
    void createMsg(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim);
#endif
protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onEntered();

    virtual mmi_ret onProc(mmi_event_struct *evt);

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void buildForm();

    void createName();

    void createNumber();

    void createEmail();

#ifdef __MMI_SNS_CONTACTS__
    void createSNS();
#endif

#ifdef __MMI_PHB_INFO_FIELD__
    void createAddress();
#endif

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    void createBday();
#endif

#ifdef __MMI_PHB_INFO_FIELD__
    void createTitle();
#endif

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    void createCompany();
#endif

#ifdef __MMI_PHB_INFO_FIELD__
    void createNote();
#endif

    static mmi_ret listener(mmi_event_struct *evt);

#ifdef __MMI_SNS_CONTACTS__
    VfxS32 loadSnsList(VfxS32 listId, VfxU32 index = 0);

    void disableSnsToolBar(VfxBool isEnable);

    void refreshForm();

    void snsAccountsLinked();

    void snsAccountsUnlinked();

    void snsDoLinked();

    void snsDoUnlinked();

    void onSettingConfirmPopup(VfxObject *obj, VfxId id);

    void createSettingConfirmPopup();

    VfxBool checkAccountsSetting();

    void onProviderCommandClicked(VfxObject *obj, VfxId id);

    void createProviderCommandPopup();

    void onProviderSelectButtonClicked(VfxObject *obj, VfxId buttonId);

    void createProviderSelectPopup();
#endif /* __MMI_SNS_CONTACTS__ */

private:
    mmi_phb_contact_id   m_id;
    VcpFormItemBase     *m_name;
    VappContactNumber    m_number;
    ContactEntry        *m_contact;
    VcpToolBar          *m_toolBar;
    VcpForm             *m_form;
    VappPhbFieldItem    *m_field;
    VfxU32               m_fieldId;
    VfxU32               m_itemId;
    VfxU32               m_itemIdArray[MMI_PHB_NUMBER_FIELD_COUNT];
    //void                *m_buffer;
    VfxBool m_isMsmode;
#ifdef __MMI_SNS_CONTACTS__
    VfxBool m_linkMark[SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT];
    VfxS16  m_linkIndex[SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT];
    VfxU16  m_providerCount;
    VfxS32 m_listId;
    VfxU16 m_linkedCount;
    VfxS16 m_startIndex;
    VfxS16 m_endIndex;
    VfxBool m_refresh;
#endif /* __MMI_SNS_CONTACTS__ */

private:
    MMI_ID               m_cui;
#ifdef __MMI_VCARD__
    VappContactvCard    *m_vcard;
#endif /* __MMI_VCARD__ */
    VfxWChar            *m_path;
    VfxBool              m_viewOnly;
    VfxBool              m_b2ndReady;
    VfxBool              m_editTcard;

private:
    VappPhbViewerProfilePage(){}

private:
    enum CONTACT_PROFILE_CMD
    {
        CONTACT_PROFIEL_CMD_EDIT,
			
#ifdef __MMI_VCARD__
        CONTACT_PROFIEL_CMD_SHARE,
#endif /* __MMI_VCARD__ */
        CONTACT_PROFIEL_CMD_DELETE,
        CONTACT_PROFIEL_CMD_COPY,
        CONTACT_PROFILE_CMD_SNS_LINK,
        CONTACT_PROFILE_CMD_SNS_UNLINK,
        CONTACT_PROFIEL_CMD_TOTAL
    };

    enum CONTACT_PROFILE_FIELD_TYPE
    {
        CONTACT_PROFILE_FIELD_NAME,
        CONTACT_PROFILE_FIELD_NUMBER,
        CONTACT_PROFILE_FIELD_EMAIL,
        CONTACT_PROFILE_FIELD_SNS,
        CONTACT_PROFILE_FIELD_IM,
        CONTACT_PROFILE_FIELD_BIRTHDAY,
        CONTACT_PROFILE_FIELD_ADDRESS,
        CONTACT_PROFILE_FIELD_NOTE,
        CONTACT_PROFILE_FIELD_TITLE,
        CONTACT_PROFILE_FIELD_COMPANY,
        CONTACT_PROFILE_FIELD_TYPE_TOTAL
    };

    enum vapp_phb_viewer_more_action_enum
    {
        VAPP_PHB_PROFILE_EDIT_BEFORE_CALL,
        VAPP_PHB_PROFILE_VIDEO_CALL,
        VAPP_PHB_PROFILE_BLOCK_NUMBER,
        VAPP_PHB_PROFILE_IP_DIAL,
        VAPP_PHB_PROFILE_ACTION_TOTAL
    };

    enum vapp_phb_viewer_share_contact_enum
    {
        VAPP_PHB_PROFILE_SHARE_BY_SMS,
        VAPP_PHB_PROFILE_SHARE_BY_MMS,
        VAPP_PHB_PROFILE_SHARE_BY_EMAIL,
        VAPP_PHB_PROFILE_SHARE_BY_BT,
        VAPP_PHB_PROFILE_SHARE_TOTAL
    };

    enum
    {
        VAPP_PHB_SELECT_SIM_CALL = 0x10,
        VAPP_PHB_SELECT_SIM_MSG = 0x20
    };
#ifdef __MMI_PHB_NEED_SERIALZE__
    VappPhbUcSerialze m_ucSerialize;
#endif
//	VfxImageBuffer UpdateImage(VfxWString filePath);
};


/***************************************************************************** 
 * Class VappPhbLocatorScr
 *****************************************************************************/ 
class VappPhbLocatorScr : public VfxMainScr
{
public:
    VappPhbLocatorScr(mmi_phb_contact_id id);

    void onContactUpdated(ContactTask* task, mmi_event_struct* evt);

protected:
    virtual void on1stReady();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    mmi_phb_contact_id m_id;

    VappPhbLocatorScr(){}
};


/***************************************************************************** 
 * Class VappPhbViewerNameFormItem
 *****************************************************************************/
class VappPhbViewerNameFormItem : public VcpFormItemBase
{
public:
    VappPhbViewerNameFormItem();

    void setName(const VfxWString &name);

#ifdef __MMI_PHB_USIM_SUPPORT__
    void setNickname(const VfxWString &nickname);
#endif

#ifdef __MMI_SNS_CONTACTS__
    void setComment(const VfxWString &content);
#endif

    void setImage(const VfxImageSrc &image);

    void setIcon(const VfxImageSrc &icon);
    VappPhbPhotoCp      *m_image;

protected:
    virtual void onInit();

private:
    VappPhbNameCp       *m_name;
    VfxImageFrame       *m_icon;
};


/***************************************************************************** 
 * Class VappPhbViewerNumFormItem
 *****************************************************************************/ 
class VappPhbViewerNumFormItem : public VcpFormItemBase
{
public:
    VappPhbViewerNumFormItem():
        m_title(NULL),
        m_content(NULL),
        m_icon(NULL){}

    void setItemContent(const VfxWString &title, const VfxWString &content, mmi_sim_enum call, mmi_sim_enum message);

    void setButtonInfo(VcpComboButton* button, VfxBool call,  mmi_sim_enum sim);

    VcpComboButton* getCallBtn();

    VcpComboButton* getMsgBtn();

    VcpButton* getMoreBtn();

    void onItemBoundsChanged(VfxFrame *frame, const VfxRect& rect);

#ifdef __MMI_CM_BLACK_LIST__
    void setBlockIcon(VfxBool reset = VFX_FALSE);
#endif

protected:
    virtual void onInit();

private:
    VfxTextFrame    *m_title;
    VfxTextFrame    *m_content;
    VfxImageFrame   *m_icon;
    phb_storage_enum m_sim;
    VcpComboButton  *m_btnCall;
    VcpComboButton  *m_btnMsg;
    VcpButton       *m_btnMore;
};


/***************************************************************************** 
 * Class VappPhbViewerLabelTextFormItem
 *****************************************************************************/
#if (defined (__MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__) ||defined (__MMI_PHB_INFO_FIELD__)|| defined (__MMI_PHB_MYCARD__))
class VappPhbViewerLabelTextFormItem : public VcpFormItemBase
{
public:
    VappPhbViewerLabelTextFormItem(){}

    void setItemContent(const VfxWString& label, const VfxWString& text);

    void changeItemHeight(void *p);

    void onItemBoundsChanged(VfxFrame *frame, const VfxRect &rect);

protected:
    virtual void onInit();

private:
    VfxTextFrame *m_label;
    VfxTextFrame *m_text;
};
#endif 


/***************************************************************************** 
 * Class VappPhbViewerLabelBtnFormItem
 *****************************************************************************/ 
class VappPhbViewerLabelBtnFormItem : public VcpFormItemBase
{
public:
    enum VappPhbViewerLabelBtnFormItemType
    {
        VAPP_PHB_VIEWER_FORM_ITEM_LABEL,
        VAPP_PHB_VIEWER_FORM_ITEM_LABEL_BTN
    };

public:
    VappPhbViewerLabelBtnFormItem():
        m_title(NULL),
        m_content(NULL),
        m_icon(NULL),
        m_btn(NULL),
        m_type(VAPP_PHB_VIEWER_FORM_ITEM_LABEL_BTN){}

    void setStyle(VappPhbViewerLabelBtnFormItemType type);

    void setItemContent(const VfxWString &title, const VfxWString &content);

    VcpButton *getButton();

    void onItemBoundsChanged(VfxFrame *frame, const VfxRect& rect);

protected:
    virtual void onInit();

private:
    VfxTextFrame    *m_title;
    VfxTextFrame    *m_content;
    VfxImageFrame   *m_icon;
    VcpButton       *m_btn;
    VappPhbViewerLabelBtnFormItemType m_type;
};


#ifdef __MMI_SNS_CONTACTS__
/***************************************************************************** 
 * Class VappPhbSelectCoreMenu
 *****************************************************************************/ 
class VappPhbSelectCoreMenu : public VcpSelectCoreMenu
{
public:
    void setProviderId(VfxU32 providerId, VfxU32 index);

    VfxU32 getProviderId(VfxU32 index);

protected:
    virtual VfxBool getItemImage(
                  VfxU32 index,                    // [IN] the position of item
                  VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                  VfxImageSrc &image               // [OUT] the image resource
                  );

    virtual void update();

private:
    VfxU32 m_providerId[SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT];
};
#endif /* __MMI_SNS_CONTACTS__ */

#endif /* __PB_INFO_H__ */

