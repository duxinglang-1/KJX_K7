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
 *  vapp_phb_group.h
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

#ifdef __MMI_PHB_CALLER_GROUP__
#ifndef __PB_GROUP_H__
#define __PB_GROUP_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#include "vapp_contact_group.h"
#include "vapp_phb_list.h"
#include "vapp_phb_editor.h"
#include "vapp_phb_multi.h"
#include "vapp_phb_gprot.h"

#define MMI_PHB_NEW_GROUP_ID (0xFE)

/***************************************************************************** 
 * Class VappPhbGroupScr
 *****************************************************************************/ 
class VappPhbGroupScr : public VfxMainScr
{
protected:
    virtual void on1stReady();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    ContactGroupManager* m_groupManager;
};


/***************************************************************************** 
 * Class VappPhbGroupListCp
 *****************************************************************************/ 
class VappPhbGroupListCp: public VcpListMenu, public IVcpListMenuContentProvider
{
public:
    VappPhbGroupListCp(ContactGroupManager *groupManager);

    void setMarkSet(VappContactGroupMarkObj *mark);

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    void getGroupList(); // refresh group list
#endif

protected:
    virtual void onInit();

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 id                        // [IN] position of the item
        ) const;

    virtual VfxU32 getCount() const;

private:
    VappPhbGroupListCp(){}
    
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    void onGroupListChanged(ContactGroupManager *groupManager, mmi_event_struct *evt);

    void updateGroupList();

    void getGroupListInter();
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

private:
    ContactGroupManager* m_groupManager;
    VappContactGroupMarkObj *m_mark;
    VfxBool m_updateGroupList;
    VfxSignal2<VappPhbGroupListCp *, VfxU32> m_signalGroupListReady;
};


/***************************************************************************** 
 * Class VappPhbMarkDeleteGroupObj
 *****************************************************************************/ 
class VappPhbMarkDeleteGroupObj: public VfxObject
{
public:
    VappPhbMarkDeleteGroupObj(
        VappPhbGroupListCp* list,
        VfxPage *page,
        VappPhbMarkCmdInterface *cmd,
        ContactGroupManager *groupManager);

    void onToolBarClicked(VfxObject* obj, VfxId id);

    void onOptionClicked(VfxObject *obj, VfxId id);

    void onStateChanged(VcpListMenu *list, VfxU32 id, VcpListMenuItemStateEnum state);

    void onGroupDeleted(ContactGroupManager* manager, VfxU8 groupId, srv_phb_group_op_type_enum op);

    void onGroupOp(ContactGroupManager* manager, VfxS32 result, srv_phb_group_op_type_enum op);

protected:
    virtual void onInit();

private:
    VappPhbMarkDeleteGroupObj(){}

    void configToolBar();

    void closeSelf();

private:
    VfxPage             *m_page;
    VappPhbGroupListCp  *m_list;
    VcpToolBar          *m_tool;
    VappContactGroupMarkObj *m_mark;
    VappPhbMarkCmdInterface *m_cmd;
    ContactGroupManager     *m_groupManager;
    VcpIndicatorPopup *m_progress;
};


/***************************************************************************** 
 * Class VappPhbGroupListPage
 *****************************************************************************/ 
class VappPhbGroupListPage: public VfxPage, public VappPhbMarkCmdInterface
{
public:
    enum vapp_phb_group_cmd_type_enum
    {
        VAPP_PHB_GROUP_CMD_ADD,
        VAPP_PHB_GROUP_CMD_DELETE,
        VAPP_PHB_GROUP_CMD_TYPE_TOTAL
    };

public:
    VappPhbGroupListPage(ContactGroupManager *groupManager);

    void onItemTaped(VcpListMenu* obj, VfxU32 id);

    void onToolBarClicked(VfxObject* obj, VfxId id);

    void onOptionClicked(VfxObject* obj, VfxId id);

    void onGroupListChanged(ContactGroupManager* manager, VfxU8 groupId, srv_phb_group_op_type_enum op);

    void onGroupListOp(ContactGroupManager* manager, VfxS32 result, srv_phb_group_op_type_enum op);

    virtual void onCmdStart(vapp_phb_mark_cmd_type_enum cmd);

    virtual void onCmdEnd(vapp_phb_mark_cmd_type_enum cmd);

protected:
    virtual void onInit();

    virtual void onEntered();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    VappPhbGroupListPage(){}

private:
    ContactGroupManager *m_groupManager;
    VappPhbGroupListCp *m_groupList;
    VcpToolBar *m_toolBar;
};


/***************************************************************************** 
 * Class VappPhbGroupEditorScr
 *****************************************************************************/ 
class VappPhbGroupEditorScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappPhbGroupEditorScr);

public:
    VappPhbGroupEditorScr(phb_storage_enum storage, ContactGroupManager *manager, VfxU8 groupId = MMI_PHB_INVALID_GROUP_ID);

protected:
    virtual void on1stReady();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

public:
    phb_storage_enum m_storage;
    ContactGroupManager *m_groupManager;
    VfxU8 m_groupId;

private:
    VappPhbGroupEditorScr(){}
};


/***************************************************************************** 
 * Class VappPhbGroupNameFormItem
 *****************************************************************************/
class VappPhbGroupNameFormItem : public VcpFormItemBase
{
public:
    VappPhbGroupNameFormItem();

    VcpTextEditor* getEditor();

    VappPhbPhotoCp *getImageBtn();

protected:
    virtual void onInit();

private:
    VappPhbPhotoCp      *m_image;
    VcpTextEditor       *m_editor;
};


/***************************************************************************** 
 * Class VappPhbGroupEditorPage
 *****************************************************************************/ 
class VappPhbGroupEditorPage: public VfxPage
{
public:
    enum vapp_phb_group_editor_cmd_type_enum
    {
        VAPP_PHB_GROUP_EDITOR_CMD_SAVE,
        VAPP_PHB_GROUP_EDITOR_CMD_CANCEL,
        VAPP_PHB_GROUP_EDITOR_CMD_TYPE_TOTAL
    };

    enum vapp_phb_group_form_item_type_enum
    {
        VAPP_PHB_GROUP_FORM_ITEM_NAME,
        VAPP_PHB_GROUP_FORM_ITEM_RING,
        VAPP_PHB_GROUP_FORM_ITEM_TYPE_TOTAL
    };

public:
    VappPhbGroupEditorPage(phb_storage_enum storage, VfxU8 groupId);

    void onToolBarClicked(VfxObject* obj, VfxId id);

    void onImageClicked(VfxObject* obj, VfxId id);

    void onOptionClicked(VfxObject* obj, VfxId id);

    void onRingClicked(VfxObject* obj, VfxId id);

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    VappPhbGroupEditorPage(){}

private:
    phb_storage_enum m_storage;
    VfxU8 m_groupId;
    VcpForm *m_form;
    ContactGroup *m_group;

    enum vapp_phb_image_cmd_type_enum
    {
        VAPP_PHB_IMAGE_CMD_FILE,
        VAPP_PHB_IMAGE_CMD_CAMERA,
        VAPP_PHB_IMAGE_CMD_REMOVE,
        VAPP_PHB_IMAGE_CMD_TYPE_TOTAL
    };
};


/***************************************************************************** 
 * Class VappPhbGroupMemberListPage
 *****************************************************************************/ 
class VappPhbGroupMemberListPage: public VfxPage, public VappPhbMarkCmdInterface
{
public:
    enum vapp_phb_group_member_list_cmd_type_enum
    {
        VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_GROUP,
        VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_MEMBER,
        VAPP_PHB_GROUP_MEMBER_LIST_CMD_MESSAGE,
        VAPP_PHB_GROUP_MEMBER_LIST_CMD_TYPE_TOTAL
    };

    enum
    {
        VAPP_PHB_GROUP_ADD_GROUP_MEMBER,
        VAPP_PHB_GROUP_REMOVE_GROUP_MEMBER,
        VAPP_PHB_GROUP_MOVE_GROUP_MEMBER,
        VAPP_PHB_GROUP_EDIT_GROUP_MEMBER_CANCEL
    };

public:
    VappPhbGroupMemberListPage(ContactGroupManager *groupManager, VfxU8 groupId);

    void onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos);

    void onToolBarClicked(VfxObject* obj, VfxId id);

    void onOptionClicked(VfxObject *obj, VfxId id);

    void onCountChanged(VappPhbListCp* list, VfxU32 count);

    void onGroupListChanged(ContactGroupManager* manager, VfxU8 groupId, srv_phb_group_op_type_enum op);

    virtual void onCmdStart(vapp_phb_mark_cmd_type_enum cmd);

    virtual void onCmdEnd(vapp_phb_mark_cmd_type_enum cmd);

protected:
    virtual void onInit();

    virtual void onBack();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    VappPhbGroupMemberListPage(){}

    void editGroup();

    void addMember();

    void editMember();

#ifdef __MMI_PHB_MARK_MESSAGE__
    void sendMessage();
#endif 

    void onCancelClick(VfxObject *obj, VfxFloat num); 

private:
    void onGroupMemberChanged(ContactGroupManager *groupManager);

private:
    ContactGroupManager *m_groupManager;
    VfxU8 m_groupId;
    VappPhbListCp *m_list;
    VcpToolBar *m_toolBar;
    VcpTitleBar *m_titleBar;
    VfxObject *m_cmdObj;
    VcpIndicatorPopup *m_progress;
};


/***************************************************************************** 
 * Class VappPhbGroupSelectorPage
 *****************************************************************************/ 
class VappPhbGroupSelectorPage: public VfxPage, public IVcpListMenuContentProvider
{
public:
    VappPhbGroupSelectorPage(phb_storage_enum storage, VfxU8 groupId = MMI_PHB_INVALID_GROUP_ID, VfxBool viewOnly = VFX_FALSE);

    void onStateChanged(VcpListMenu *list, VfxU32 index, VcpListMenuItemStateEnum state);

    void onItemTaped(VcpListMenu *list, VfxU32 index);

    void onGroupAdded(ContactGroupManager *manager, VfxU8 groupId, srv_phb_group_op_type_enum op);

    VfxSignal2<VfxObject*, VfxU8> m_signalGroupSelected;

protected:
    virtual void onInit();

    virtual void onEntered();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index                     // [IN] index of the item
        ) const;

    virtual VfxBool getItemIsDisabled(
        VfxU32 index                     // [IN] the index of item
        ) const;

    virtual VfxBool getItemStateValidation(
        VfxU32 index,                    // [IN] index of the item
        VcpListMenuItemStateEnum state   // [IN] the state to be checked
        ) const;

    virtual VfxU32 getCount() const;

private:
    VappPhbGroupSelectorPage(){}

private:
    phb_storage_enum     m_storage;
    VfxU8                m_groupId;
    VfxBool              m_viewOnly;
    ContactGroupManager *m_group;
    VcpListMenu         *m_list;
};

#endif /* __PB_GROUP_H__ */
#endif /* __MMI_PHB_CALLER_GROUP__ */

