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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   vapp_sns_main.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements SNS class declaration.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_CONTACT_H__
#define __VAPP_SNS_CONTACT_H__
 
#include "MMI_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "MMIDataType.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_photo_border_frame.h"
#include "vcp_tabctrl_page.h"
#include "vapp_sns_gprot.h"
//#include "SnsTypes.h"
#include "SnsSrvTypes.h"

#include "vapp_sns_main_cp.h"
#include "vapp_sns_base.h"


/***************************************************************************** 
 * Define
*****************************************************************************/

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
// VappSnsContactAgent class declaration
class VappSnsContactAgent : public VappSnsBaseAgent
{
    VFX_DECLARE_CLASS(VappSnsContactAgent);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsContactAgent();

// Implementation
public:
    // Get list of friends
    VfxS32 getFriends(
        VfxU32 provider, 
        VfxS32 group, 
        VfxU16 contactId = 0,
        VfxWChar *name = NULL
    );

    // Get friends info
    VfxS32 getUserInfo(
        VfxU32 provider,
        VfxChar *userId,
        VfxBool isDownloadPic = VFX_TRUE
    );


    // Add group (TODO: callback function + signal)
    void addGroup(
        VfxWChar *name
    );

    // Rename group (TODO: callback function + signal)
    void renameGroup(
        VfxU32 group,
        VfxWChar *name
    );
    
    // Remove group (TODO: callback function + signal)
    void removeGroup(
        VfxU32 *group, 
        VfxU8 num
    );

    // Check if a member
    VfxBool isSelectedMember(
        srv_sns_user_list_struct *userList,
        VfxU8 userListSize,
        VfxS32 listId,
        VfxS16 index
    );

    // Edit member
    VfxS32 editMember(
        srv_sns_user_list_struct *userList,
        VfxU8 userListSize,
        VfxS32 listId,
        VfxS16 index,
        VfxBool toAdd
    );

    // Commit edit result (TODO: callback function + signal)
    void editMemberConfirm(
        VfxS32 group,
        srv_sns_user_list_struct *userList,
        VfxU8 userListSize,        
        VfxBool toAdd
    );

    // Group operation callback handler
    mmi_ret groupOpCallbackHandler(
        mmi_event_struct *param
    );

    // This function is used to query the sns support send message to multiple contacts or not
    VfxBool isSupportMultiContacts(
        VfxU32 provider
    );

// Signal 
public:
    // Group updated signal
    VfxSignal2 <VappSnsContactGroupOpEnum, srv_sns_result> m_signalGroupOpFinished;

// Variable
private:
    // Group operation
    VappSnsContactGroupOpEnum m_activeGroupOp;

};


// VappSnsProfilePage class declaration
class VappSnsProfilePage : public VappSnsBasePage
{
    VFX_DECLARE_CLASS(VappSnsProfilePage);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsProfilePage(VfxU32 providerId = 0, VfxChar *userId = NULL, VfxU8 userIdLen = 0); 

    VappSnsProfilePage(srv_sns_info_struct *userInfo, VfxBool isMe = VFX_FALSE);

// Override
protected:
    // Init function
    virtual void onInit();

    // Deinit function 
    virtual void onDeinit();

    // Page auto close function
    virtual void onBeforeAutoClose();

    // Enter function
    virtual void onEnter(
        VfxBool isBackWard
    );

    // Entered function
    virtual void onEntered();
    
    // On load result
    virtual void onGetLoadResults(
        VfxS32 listId,
        VfxU16 total,
        VfxS16 startIndex,
        VfxS16 endIndex
    );

    // Status changed
    virtual void onSrvStatusChanged(
        VfxBool isReady,
        srv_sns_result result, 
        VfxU32 listId
    );

    // Item updated
    virtual void onItemUpdated(
        VfxS32 listId,
        VfxU16 index, 
        VappSnsItemUpdatedTypeEnum type, 
        VfxWChar *path
    );

// Implementation
public:
    // Entered page [workaround-VcpTabCtrlPage can't provide correct entered timing]
    virtual void onSubPageEntered();

    // Get user info
    void getUserInfo();

    // Set user name
    void setUserName(
        const VfxWString &name, 
        const VfxWString &userPic, 
        const VfxWString &status
    );
    
    // Set user info
    VfxBool setUserInfo();

// Variable
private:
    enum FormItemIdEnum {
        FORM_ITEM_ID_NAME = 1,
        FORM_ITEM_ID_ACCOUNT,
        FORM_ITEM_ID_BIRTHDAY,
        FORM_ITEM_ID_PHONE,
        FORM_ITEM_ID_EMAIL,
        FORM_ITEM_ID_ADDRESS,
        FORM_ITEM_ID_TOTAL
    };

    enum ButtonIdEnum {
        BUTTON_ID_BROWSER,
        BUTTON_ID_MESSAGE
    };

    // Provider id
    VfxU32 m_providerId;

    // User id 
    VfxChar *m_userId;

    // Form
    VcpForm *m_form;

    // List id
    VfxS32 m_listId;

    // User info
    srv_sns_info_struct *m_userInfo;

    // Is me flag
    VfxBool m_isMe;

    // Name cp
    VappSnsFormItemNameCp *m_nameCp;

    // Account 
    VappSnsFormItemAcctViewer *m_account;

    // Birthday    
    VappSnsFormItemLabelViewer *m_birthday;

    // Phone
    VappSnsFormItemLabelViewer *m_phone;

    // Email 
    VappSnsFormItemLabelViewer *m_email;

    // Address
    VappSnsFormItemLabelViewer *m_address;

    // Error string text frame
    VfxTextFrame *m_errorStringFrame;

    // Is backward flag
    VfxBool m_isBackward;
};


#ifdef __MMI_SNS_CONTACTS__
// VappSnsGroupListPage class declaration
class VappSnsGroupListPage : public VappSnsBasePage, IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSnsGroupListPage);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsGroupListPage(VfxBool isCreate = VFX_FALSE); 

// Override
protected:
    // Init function
    virtual void onInit();

    // Init function
    virtual void onDeinit();

    // Enter function
    virtual void onEnter(VfxBool isBackWard);

    // Entered function
    virtual void onEntered();

    // Back function
    virtual void onBack();

    // This function is used handle tool bar click event
    virtual void onToolbarTapped(
        VfxObject *sender,
        VfxId id
    );

    // Status changed
    virtual void onSrvStatusChanged(
        VfxBool isReady,
        srv_sns_result result, 
        VfxU32 listId
    );

    // List invaildated
    virtual void onListInvaildated(
        VfxS32 listId
    );

    // Item updated
    virtual void onItemUpdated(
        VfxS32 listId,
        VfxU16 index, 
        VappSnsItemUpdatedTypeEnum type, 
        VfxWChar *path
    );

    // Counts updated
    virtual void onCountUpdated(
        VfxU8 messages, 
        VfxU8 notifications, 
        VfxU8 requests
    ); 

    // Load callback function
    virtual void onGetLoadResults(
        VfxS32 listId, 
        VfxU16 total, 
        VfxS16 startIndex, 
        VfxS16 endIndex
    );

    // Popup click handler
    virtual void onPopupButtonClicked(
        VfxObject *sender, 
        VfxId id
    );

// Override
public:
    // IVcpListMenuContentProvider
    virtual VfxBool getItemText (
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
    );   

    virtual VfxU32 getCount() const;
    
    virtual VfxBool getItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
    );
    
    virtual VfxBool getMenuEmptyText (
        VfxWString &text,               
        VcpListMenuTextColorEnum &color
    );    

    virtual VcpListMenuItemStateEnum getItemState (
        VfxU32 index    
    ) const;

// Implementation
private:
    // This function is used to create a new group
    void onGroupCreated(
        VfxObject* sender, 
        VcpInputPopupButtonEnum type
    );

    // This function used to handle item tapped event
    void onItemTapped(
        VcpListMenu *list, 
        VfxU32 index
    );

    // This function is used to received operation executing result
    void onReceivedOpResult(
        VappSnsContactGroupOpEnum op,
        srv_sns_result result
    );

    // This function is used to get group info
    VfxBool getGroupInfo(
        VfxU32 index, 
        void **group
    );

    // This function is used to get group name
    VfxU8 getGroupName(
        VfxU32 index, 
        VfxWString &name, 
        VfxU32 *groupId = NULL
    );


    // This function is used to handle tool bar clicked event at viewer mode
    void groupListManager(
        VfxObject *sender, 
        VfxId id
    );

    // This function is used to handle tool bar clicked event at edit mode 
    void deleteManager(
        VfxObject *sender, 
        VfxId id
    );

    // This function is used to update tool bar
    void updateLayout(
        VfxBool isEditing
    );

    // This function is used to update mark all tool bar item
    void updateMarkAllItem();

    // This function is used to query is selected all item
    VfxBool isSelectAll();

// Variable
private:
    // enum
    enum ToolBarIdEnum {
        // Viewer mode
        TOOL_BAR_ID_ADD_GROUP    = 0,
        TOOL_BAR_ID_DELETE_GROUP = 1,

        // Editor mode
        TOOL_BAR_ID_SELECT_ALL   = 0,
        TOOL_BAR_ID_DELETE       = 1,
        TOOL_BAR_ID_CANCEL       = 2
    };

    // List menu
    VcpListMenu *m_list;

    // Group list
    VfxS32 m_listId;

    // List count
    VfxU32 m_count;

    // Selected group
    VfxBool *m_selectedGroup;

    // Removed group
    VfxU32 *m_removedGroup;

    // Selected group count
    VfxU8 m_selectNum;

    // Is create new on flag
    VfxBool m_isCreateNew;

    // Service status result
    VfxS32 m_statusResult;
};

#endif /* __MMI_SNS_CONTACTS__ */

#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __VAPP_SNS_CONTACT_H__*/

