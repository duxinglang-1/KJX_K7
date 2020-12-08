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
 *  vapp_phb_editor.h
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

#ifndef __PB_EDITOR_H__
#define __PB_EDITOR_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"
#include "vcp_form.h"
#include "vcp_date_picker.h"
#include "vcp_photo_border_frame.h"

#include "vapp_contact_entry.h"
#include "vapp_contact_op.h"
#include "vapp_contact_util.h"
#include "vcui_phb_gprot.h"

#define MMI_PHB_CONTACT_MAX_ITEM (30)

enum
{
#if defined(__MMI_MAINLCD_320X480__)
    ICON_SIZE = 66,
#elif defined(__MMI_MAINLCD_480X800__)
    ICON_SIZE = 116,
#else
    ICON_SIZE = 66,
#endif

    VAPP_PHB_FORM_ITEM_LEFT_GAP = VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2,

    VAPP_PHB_FORM_ITEM_T0P_GAP = 10,

    VAPP_PHB_EDITOR_UI_ENUM_END
};

enum vapp_phb_editor_type_enum
{
    VAPP_PHB_CONTACT_ADD,
    VAPP_PHB_CONTACT_EDIT,
    VAPP_PHB_CONTACT_TYPE_TOTAL
};

enum vapp_phb_cmd_type_enum
{
    VAPP_PHB_CONTACT_CMD_DONE,
    VAPP_PHB_CONTACT_CMD_SAVE,
    VAPP_PHB_CONTACT_CMD_DELETE,
    VAPP_PHB_CONTACT_CMD_PREV,
    VAPP_PHB_CONTACT_CMD_NEXT,
    VAPP_PHB_CONTACT_CMD_CANCEL,
    VAPP_PHB_CONTACT_CMD_TYPE_TOTAL
};


/***************************************************************************** 
 * Class VappPhbFieldItem
 *****************************************************************************/
class VappPhbFieldItem: public VfxObject
{
public:
    class ContactItem: public VfxBase
    {
    public:
        ContactItem():
            m_itemId(0),
            m_itemType(0),
            m_fieldId(0xFFFFFFFF),
            m_fieldType(0xFFFFFFFF),
            m_obj(NULL){}

        ContactItem(const ContactItem& id)
        {
            m_itemId = id.m_itemId;
            m_itemType = id.m_itemType;
            m_fieldId = id.m_fieldId;
            m_fieldType = id.m_fieldType;
            m_obj = id.m_obj;
        }

        ContactItem& operator= (const ContactItem& id)
        {
            m_itemId = id.m_itemId;
            m_itemType = id.m_itemType;
            m_fieldId = id.m_fieldId;
            m_fieldType = id.m_fieldType;
            m_obj = id.m_obj;

            return *this;
        }

        VfxBool isValid()
        {
            return (m_itemId == 0) ? VFX_FALSE : VFX_TRUE;
        }

        VfxU32 m_itemId;
        VfxU32 m_itemType;
        VfxU32 m_fieldId;
        VfxU32 m_fieldType;
        VfxObject *m_obj;
    };

    typedef ContactStack<VappPhbFieldItem::ContactItem> VappPhbFormItemStack;

public:
    VappPhbFieldItem();

    VfxU32 getNewItemId();

    void setItem(const ContactItem& id);

    void insertItem(const ContactItem& id, VfxU32 beforeItemId);

    void removeItem(VfxU32 itemId);

    VfxU32 getItemCount();

    VfxObject* getObj(VfxU32 fieldType, VfxU32 fieldId);

    VfxObject* getObj(VfxU32 itemType);

    ContactItem& getItemByIndex(VfxU32 index);

    ContactItem& getItem(VfxU32 itemId);

    ContactItem getItemByItemType(VfxU32 itemType);

    ContactItem& getPrevItem(VfxU32 itemId);

    ContactItem& getNextItem(VfxU32 itemId);

protected:
    virtual void onInit();

private:
    VfxU32 getItemIndex(VfxU32 itemId);

private:
    VappPhbFormItemStack *m_item;
    VfxU32 m_itemId;
    ContactItem m_temp;
};

typedef VappPhbFieldItem::ContactItem VappContactFieldItem;


/***************************************************************************** 
 * Class VappPhbPhotoCp
 *****************************************************************************/
class VappPhbPhotoCp: public VcpPhotoBorderFrame
{
public:
    VappPhbPhotoCp();

    void setPhoto(const VfxImageSrc &photo);

    void setDisableClick(VfxBool disable);

    VfxSignal2 <VfxObject*, VfxId> m_signalClicked;

protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    VfxBool m_disable;
};


/***************************************************************************** 
 * Class VappPhbNameCp
 *****************************************************************************/
class VappPhbNameCp: public VfxControl
{
public:
    VappPhbNameCp();

    void setName(const VfxWString& name);

#ifdef __MMI_PHB_USIM_SUPPORT__
    void setNickname(const VfxWString &nickname);
#endif

#ifdef __MMI_SNS_CONTACTS__
    void setComment(const VfxWString &comment);
#endif

protected:
    virtual void onInit();

    virtual void onUpdate();

private:
#ifdef __MMI_PHB_USIM_SUPPORT__
    VfxTextFrame *m_nickname;
#endif
#ifdef __MMI_SNS_CONTACTS__
    VfxTextFrame *m_comment;
#endif
    VfxTextFrame *m_name;

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        NAME_GAP = 3,
        TITLE_GAP = 2,
    #elif defined(__MMI_MAINLCD_480X800__)
        NAME_GAP = 7,
        TITLE_GAP = 5,
    #else
        NAME_GAP = 3,
        TITLE_GAP = 2,
    #endif

        ENUM_END
    };
};


/***************************************************************************** 
 * Class VappPhbEditorNameFormItem
 *****************************************************************************/
class VappPhbEditorNameFormItem: public VcpFormItemBase
{
public:
    VappPhbEditorNameFormItem();

    void setName(const VfxWString &name);

    void setImage(const VfxImageSrc &image);

#ifdef __MMI_PHB_LAST_NAME_FIELD__
    void onEditName(VfxObject* obj, VfxId id);
#endif

    VcpTextEditor* getEditor();

    VappPhbPhotoCp *getImageBtn();

public:
    VfxSignal0 m_nameTaped;
	VappPhbPhotoCp *m_image;

protected:
    virtual void onInit();

#ifdef __MMI_PHB_LAST_NAME_FIELD__
    virtual VfxBool onPenInput(VfxPenEvent &event);
#endif

private:
 
    VcpTextEditor *m_editor;
    VappPhbNameCp *m_name;
    VcpButton *m_editBtn;
};


#ifdef __MMI_PHB_INFO_FIELD__
/***************************************************************************** 
 * Class VappPhbEditorAddressFormItem
 *****************************************************************************/ 
class VappPhbEditorAddressFormItem: public VcpFormItemBase
{
public:
    void setLabel(const VfxWString& text);

    void onEditAddress(VfxObject* obj, VfxId id);

public:
    VfxSignal0 m_addressTaped;VfxSignal2 <VfxObject*, VfxId> m_signalClicked;

protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    VfxTextFrame *m_label;
    VcpButton *m_btn;
};
#endif /* __MMI_PHB_INFO_FIELD__ */


/***************************************************************************** 
 * Class VappPhbEditorBdayPickerFormItem
 *****************************************************************************/
class VappPhbEditorBdayPickerFormItem: public VcpFormItemBase
{
public:
    VappPhbEditorBdayPickerFormItem(){}

    VcpDatePicker *getPicker();

protected:
    virtual void onInit();

private:
    VcpDatePicker *m_picker;
};


/***************************************************************************** 
 * Class VappPhbSaveContactCui
 *****************************************************************************/ 
class VappPhbSaveContactCui: public VfxCui
{
    VFX_DECLARE_CLASS(VappPhbSaveContactCui);

public:
    VappPhbSaveContactCui();

    void setType(vcui_phb_save_contact_type_enum type);

    vcui_phb_save_contact_type_enum getType() const;

    void setId(mmi_phb_contact_id id);

    mmi_phb_contact_id getId() const;

    void setData(const VfxWChar* data, VfxU32 length, VfxU32 id, VfxU32 type);

    VappContactFieldObjList* getFieldList();

    void setUserData(VfxU32 userData);

    VfxU32 getUserData() const;

    void setFromPhb(VfxBool fromPhb);

    VfxBool getFromPhb(void);

    void onSavedDone(mmi_phb_contact_id id, VfxBool success);

public:
    virtual void onRun(void* args, VfxU32 argSize);

protected:
	using VfxApp:: onProcessClose;
    virtual void onInit();
   virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
   

public:
    vcui_phb_save_contact_type_enum m_type;
    mmi_phb_contact_id m_id;
    VappContactFieldObjList *m_dataList;
    VfxU32 m_userData;
    VfxBool m_fromPhb;
};


/***************************************************************************** 
 * Class VappPhbEditorScr
 *****************************************************************************/ 
class VappPhbEditorScr: public VfxMainScr
{
public:
    VappPhbEditorScr(){}

    VappPhbEditorScr(VappPhbSaveContactCui* cui);

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void on1stReady();

    virtual void onEnter(VfxBool isBackward);

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    void onButtonClick(VfxObject* obj, VfxId id);

    virtual mmi_ret onProc(mmi_event_struct *evt);

    void onContactUpdated(ContactTask* task, mmi_event_struct* evt);

private:
    void saveContact();

    void createNewContact();

    void editContact();

    void replaceContact();

    void setData(VappContactFieldObjList *list);

private:
    Contact *m_contact;

public:
    static MMI_BOOL onNmgrNotified(mmi_scenario_id scenarioId, void *userData);
    static VfxWString m_text;
    static mmi_id m_errorPopupId;
};


/***************************************************************************** 
 * Class VappPhbEditorPage
 *****************************************************************************/ 
typedef enum
{
    CUI_PHB_IMGEDT_OK,
   
    CUI_PHB_IMGEDT_E_BASE = -4000,        
    CUI_PHB_IMGEDT_E_UNEXPECTED,
    CUI_PHB_IMGEDT_E_INVALID_ARGS,
    CUI_PHB_IMGEDT_E_NOT_ENOUGH_BUFFER,
    CUI_PHB_IMGEDT_E_FILE_SIZE_TOO_LARGE,
    CUI_PHB_IMGEDT_E_FILE_ACCESS_DENIED,
    CUI_PHB_IMGEDT_E_UNSUPPORTED_RESOLUTION,
    CUI_PHB_IMGEDT_E_UNSUPPORTED_FORMAT,
    CUI_PHB_IMGEDT_E_NOT_IMPLEMENTED,
}cui_phb_imgclip_result;

class VappPhbEditorPage: public VfxPage
{
public:
    VappPhbEditorPage(Contact* contact);

public:
    void onToolBarClick(VfxObject* obj, VfxId id);

    void onImageClick(VfxObject* obj, VfxId id);

    void onImageFromClick(VfxObject* obj, VfxId id);

    void onRingClick(VfxObject* obj, VfxId id);

    void onLabelSelected(VfxU32 type, VfxWString label, VfxU32 userData);

    void onLabelClick(VfxObject* obj, VfxId id);

#ifdef __MMI_PHB_LAST_NAME_FIELD__
    void onNameTaped();
#endif

    void onNumberClick(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool addRemove);

    void onEmailClick(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool addRemove);

    void onBirthDayChanged();

#ifdef  __MMI_PHB_BIRTHDAY_FIELD__
    void onBirthDayClick(VcpTextEditor *editor, VfxBool active);
#endif 

#ifdef __MMI_PHB_INFO_FIELD__
    void onAddressTaped();
#endif
#ifdef  __MMI_PHB_CALLER_GROUP__

    void onGroupChanged(VfxObject* obj, VfxU8 groupId);
#endif

    void onGroupClick(VfxObject* obj, VfxId id);

    void onStorageChanged(phb_storage_enum storage);

    void onStorageClick(VfxObject* obj, VfxId id);

    void onContentChanged(VfxU32 fieldType, VfxU32 fieldId);

    void onEditorActived(VcpTextEditor *editor, VfxBool isActived);

    void onEditorPreActive();

    void finishOP();

    void onSaveDone(ContactOP*, CONTACT_STATE, srv_phb_async_op_cb_struct*);

    void onSaveDoneAndDelete(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* evt);

    void onDeleteDone(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result);
    static mmi_ret listener(mmi_event_struct *evt);

private:
    void createForm();

    void createName();

#ifdef __MMI_PHB_USIM_SUPPORT__
    void createNickname();
#endif

    void createNumber();

    void createNewNumber();

    void createEmail();

    void createNewEmail();

#ifdef __MMI_PHB_INFO_FIELD__
    void createAddress();
#endif
#if defined (__MMI_PHB_BIRTHDAY_FIELD__) || defined (__MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__) || defined (__MMI_PHB_INFO_FIELD__)

    void createOtherInfo();
#endif

    void createSetting();

    void updateName();

#ifdef __MMI_PHB_INFO_FIELD__
    void updateAddress();
#endif
#ifdef __MMI_PHB_CALLER_GROUP__ 
    void updateGroup();
#endif /* __MMI_PHB_CALLER_GROUP__ */

    void save();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	VfxWString createNewPicName();
	VfxWChar *getFileNamePos(const VfxWChar *fullpath);
	VfxWChar *getFileExtName(const VfxWChar *fullpath);
	VfxWChar img_path[SRV_FMGR_PATH_MAX_LEN + 1];
	VfxWString m_newPath;
	VfxSignal0 m_signalRefresh;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	VfxRect m_imgRect;
	VfxBool m_isBmp;
	VfxRect m_saveRect;
#if 1
	void decodeToThumbnail(const VfxRect& layerRect, WCHAR * path);
	//VfxImageBuffer UpdateImage(VfxWString  filePath);
	//void    *m_buffer;

#endif
protected:
    virtual void onInit();

    virtual void onEntered();

    virtual void onDeinit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual mmi_ret onProc(mmi_event_struct *evt);

    virtual void onBack();

private:
    VappPhbEditorPage(){}

private:
    vapp_phb_editor_type_enum m_action;
    mmi_phb_contact_id m_id;
    VcpForm *m_form;
    Contact *m_contact;
    VappPhbFieldItem *m_field;
    VfxU32 m_numCount;
    VfxU32 m_emailCount;
    ContactOP *m_save;
    ContactOP *m_delete;
    VcpTextEditor *m_activeEditor;
    VcpToolBar *m_toolbar;
    VcpIndicatorPopup *m_progress;
    VfxBool m_autoAdd;
    VfxBool m_autoAddEmail;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	VfxS32  m_state;


    enum PB_CONTACT_ITEM_TYPE
    {
        PB_CONTACT_ITEM_NAME,
        PB_CONTACT_ITEM_NICKNAME,
        PB_CONTACT_ITEM_NUMBER_CAP,
        PB_CONTACT_ITEM_NUMBER,
        PB_CONTACT_ITEM_NUMBER_NEW,
        PB_CONTACT_ITEM_EMAIL_CAP,
        PB_CONTACT_ITEM_EMAIL,
        PB_CONTACT_ITEM_EMAIL_NEW,
        PB_CONTACT_ITEM_SNS_CAP,
        PB_CONTACT_ITEM_SNS,
        PB_CONTACT_ITEM_SNS_NEW,
        PB_CONTACT_ITEM_OTHER_CAP,
        PB_CONTACT_ITEM_BDAY,
        PB_CONTACT_ITEM_ADDRESS,
        PB_CONTACT_ITEM_TITLE,
        PB_CONTACT_ITEM_COMPANY,
        PB_CONTACT_ITEM_NOTE,
        PB_CONTACT_ITEM_SETTINGS_CAP,
        PB_CONTACT_ITEM_GROUP,
        PB_CONTACT_ITEM_RINGTONE,
        PB_CONTACT_ITEM_STORAGE,
        PB_CONTACT_ITEM_TYPE_TOTAL
    };

    enum vapp_phb_image_cmd_type_enum
    {
        VAPP_PHB_IMAGE_CMD_FILE,
        VAPP_PHB_IMAGE_CMD_CAMERA,
        VAPP_PHB_IMAGE_CMD_REMOVE,
        VAPP_PHB_IMAGE_CMD_TYPE_TOTAL
    };
};


#ifdef __MMI_PHB_LAST_NAME_FIELD__
/***************************************************************************** 
 * Class VappPhbEditorNamePage
 *****************************************************************************/ 
class VappPhbEditorNamePage: public VfxPage
{
public:
    VappPhbEditorNamePage():
        m_form(NULL),
        m_contact(NULL),
        m_field(NULL){}

    VappPhbEditorNamePage(Contact *contact):
        m_form(NULL),
        m_contact(contact),
        m_field(NULL){}

    void nameDone();

    void onEditorActived(VcpTextEditor *editor, VfxBool isActived);

    void onFuncBarTapped(VfxObject *obj, VfxId id);

    void onToolBarClick(VfxObject *obj, VfxId id);

    VfxSignal2<VfxU32, VfxU32> m_nameChanged;

protected:
    virtual void onInit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    VcpForm *m_form;
    Contact *m_contact;
    VappPhbFieldItem *m_field;
    VfxU32 m_currItemId;

    enum PB_EDIT_NAME_TYPE
    {
        PB_EDIT_NAME_LAST_NAME = 1,
        PB_EDIT_NAME_FIRST_NAME,
        PB_EDIT_NAME_NICK,
        PB_EDIT_NAME_TITLE,
        PB_EDIT_NAME_COMPANY,
        PB_EDIT_NAME_TYPE_TOTAL
    };
};
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */


#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
/***************************************************************************** 
 * Class VappPhbEditorCustomTypePage
 *****************************************************************************/ 
class VappPhbEditorCustomTypePage: public VfxPage
{
public:
    VappPhbEditorCustomTypePage(){}

    VappPhbEditorCustomTypePage(ContactFieldType* type):
        m_type(type),
        m_form(NULL){}

    void onToolBarClick(VfxObject* obj, VfxId id);

    void onFuncBarTapped(VfxObject* obj, VfxId id);

    VfxSignal1<VfxU8> m_signalNewType;

protected:
    virtual void onInit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onSave();

private:
    ContactFieldType* m_type;
    VcpForm *m_form;

private:
    enum
    {
        VAPP_PHB_EDITOR_CUSTOM_TYPE = 1
    };
};
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */


/***************************************************************************** 
 * Class VappPhbTypeSelectorPage
 *****************************************************************************/ 
class VappPhbTypeSelectorPage: public VfxPageHandler, public IVcpGroupListMenuContentProvider
{
public:
    VappPhbTypeSelectorPage(
        VfxU8 typeId,
        mmi_phb_contact_field_id_enum fieldId,
        phb_storage_enum storage,
        VfxU32 userData);

    void onItemTaped(VcpGroupListMenu* list, VcpMenuPos pos);

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    void onAddNewType(VfxU8 type);

    void onDeleteClicked(VcpGroupListMenu *list, VcpMenuPos pos);

    void onDelete(VfxObject* obj, VfxId id);
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */

    VfxSignal3<VfxU32, VfxWString, VfxU32> m_typeSelected;

protected:
    virtual void onPageInit(VfxPageEx * page);

    virtual void onPageEntered(VfxPageEx * page);

    virtual void onPageRotate(VfxPageEx * page, const VfxScreenRotateParam &param);// change onQueryRotate to onPageRotate

    virtual VfxBool getItemText(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    virtual VcpListMenuCellBaseControl *getItemCustomControl(
        VcpMenuPos pos,                                  // [IN] position of the item
        VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
        VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
        );
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */

    virtual VfxU32 getCount(VfxU32 group) const;

    virtual VfxU32 getGroupCount() const;

    virtual VfxBool hasGroupHeader(VfxS32 group) const;

    virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos                   // [IN] position of the item
        ) const;

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    virtual VfxBool getItemStateValidation(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuItemStateEnum state   // [IN] the state to be checked
        ) const;
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */

private:
    VappPhbTypeSelectorPage(){}

private:
    VfxU8 m_type;
    mmi_phb_contact_field_id_enum m_field;
    phb_storage_enum m_storage;
    ContactFieldType *m_typeObj;
    VcpGroupListMenu *m_list;
    VfxId m_index;
    VfxU32 m_userData;
};


#ifdef __MMI_PHB_INFO_FIELD__
/***************************************************************************** 
 * Class VappPhbEditorAddressPage
 *****************************************************************************/ 
class VappPhbEditorAddressPage: public VfxPage
{
public:
    VappPhbEditorAddressPage(Contact *contact);

    void onEditorActived(VcpTextEditor *editor, VfxBool isActived);

    void onFuncBarTapped(VfxObject* obj, VfxId id);

    void onToolBarClick(VfxObject* obj, VfxId id);

    VfxSignal2<VfxU32, VfxU32> m_addressChanged;

protected:
    virtual void onInit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    VappPhbEditorAddressPage(){}

    void onSave();

private:
    Contact *m_contact;
    VcpForm *m_form;
    VappPhbFieldItem *m_field;
    VfxU32 m_currItemId;

    enum PB_EDITOR_ADDRESS_TYPE_ENUM
    {
        PB_EDITOR_ADDRESS_POBOX = 1,
        PB_EDITOR_ADDRESS_EXTENSION,
        PB_EDITOR_ADDRESS_STREET,
        PB_EDITOR_ADDRESS_CITY,
        PB_EDITOR_ADDRESS_STATE,
        PB_EDITOR_ADDRESS_POSTALCODE,
        PB_EDITOR_ADDRESS_COUNTRY,
        PB_EDITOR_ADDRESS_TYPE_TOTAL
    };
};
#endif /* __MMI_PHB_INFO_FIELD__ */


/***************************************************************************** 
 * Class VappPhbEditorSelectStoragePage
 *****************************************************************************/ 
class VappPhbEditorSelectStoragePage: public VfxPage, public IVcpListMenuContentProvider
{
public:
    VappPhbEditorSelectStoragePage(phb_storage_enum storage);

    void onItemTaped(VcpListMenu *list, VfxU32 index);

    void onButtonClicked(VfxObject *obj, VfxId id);

    void onStateChanged(VcpListMenu *list, VfxU32 index, VcpListMenuItemStateEnum state);

    VfxSignal1<phb_storage_enum> m_storageChanged;

protected:
    virtual void onInit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index                     // [IN] index of the item
        ) const;

    virtual VfxBool getItemIsDisabled(
        VfxU32 index                     // [IN] the index of item
        ) const;

private:
    VappPhbEditorSelectStoragePage(){}

private:
    phb_storage_enum m_oldStorage;
    phb_storage_enum m_storage;
    VcpListMenu *m_list;
};


/***************************************************************************** 
 * Class VappPhbEditorBdayPage
 *****************************************************************************/ 
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
class VappPhbEditorBdayPage: public VfxPage
{
public:
    VappPhbEditorBdayPage(){}

    VappPhbEditorBdayPage(VappContactBday *bday);

    void onToolBarClick(VfxObject *obj, VfxId id);

    void onBirthDayChanged(VfxObject *obj, VcpDatePickerStruct* date);

public:
    VfxSignal0 m_signalBirthDayChanged;

protected:
    virtual void onInit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    VfxU16 m_year;
    VfxU8 m_month;
    VfxU8 m_day;
    VappContactBday *m_bday;
    VcpForm *m_form;

    enum vapp_phb_editor_bday_form_item_enum
    {
        VAPP_PHB_EDITOR_BDAY_TIMER_PICKER
    };
};
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

#endif /* __PB_EDITOR_H__ */

