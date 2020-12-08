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
 * vapp_sns_gprot.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SNS_GPROT_H__
#define __VAPP_SNS_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vfx_mc_include.h"
#include "../../Sns/Vapp_sns_base.h"
#include "../../Sns/Vapp_sns_base_cp.h"
#include "../../Sns/Vapp_sns_msg.h"
#include "vapp_ncenter_base_cell.h"
#include "vcp_image_button.h"
/* errCode: 0 => success 
            -1 => fail */
typedef void (*sns_query_pic_cb)(VfxS32 index, VfxWString path, VfxS32 errCode, void *user_data);

/***************************************************************************** 
 * Define
*****************************************************************************/  

/***************************************************************************** 
 * Enum
*****************************************************************************/  
typedef enum {
    GROUP_OPERATION_NONE,
    GROUP_OPERATION_ADD,
    GROUP_OPERATION_RENAME,
    GROUP_OPERATION_REMOVE,
    GROUP_OPERATION_EDIT_MEMBER,
    GROUP_OPERATION_END
} VappSnsContactGroupOpEnum;   


/*****************************************************************************
 * Class Declaration
 *****************************************************************************/

// VappSnsFormItemAcctViewer class declaration
class VappSnsFormItemAcctViewer : public VappSnsFormItemLabelViewer
{
    VFX_DECLARE_CLASS(VappSnsFormItemAcctViewer);

// Constructor / Destructor
public:
    VappSnsFormItemAcctViewer(
        VfxU32 providerId = 0, 
        VfxChar *userId = NULL,  
        VfxWChar *userName = NULL, 
        VfxWChar *profileUrl = NULL, 
        VfxBool isMe = VFX_FALSE, 
        VfxBool showName = VFX_TRUE
    );

// Override
protected:
    // Init function 
    virtual void onInit();

    // Button clicked handler
    virtual void onButtonClicked(VfxObject *sender, VfxId id);

#ifdef __MMI_SNS_MESSAGES__
    // Message composer event handler
    static mmi_ret onMsgComposerResultEvent(mmi_event_struct *param);
#endif /*__MMI_SNS_MESSAGES__*/

// Implement
public:
    // Object auto closed 
    void onBeforeAutoClosed();
    
// Variable
private:
    enum ButtonIdEnum {
        BUTTON_ID_BROWSER,
        BUTTON_ID_MESSAGE
    };

    // Provider id
    VfxU32 m_providerId;

    // Cui id
    mmi_id m_cuiId;
    
    // User id 
    VfxChar m_userId[SRV_SNS_MAX_LEN_ID + 1];

    // User name
    VfxWChar m_userName[SRV_SNS_MAX_LEN_NAME + 1];

    // Profile url
    VfxWChar m_profileUrl[(SRV_SNS_MAX_LEN_PIC_URL * 2) + 1];

    // Is me flag
    VfxBool m_isMe;

    // Show name flag
    VfxBool m_showName;
};

// VappSnsActivitiesPage class declaration
class VappSnsActivitiesPage : public VappSnsBasePage, public IVappSnsListContentProvider
{
    VFX_DECLARE_CLASS(VappSnsActivitiesPage);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsActivitiesPage();

    // Constructor with users id lists (use by contact)
    VappSnsActivitiesPage(VfxU32 provider, VfxChar *user, VfxU32 userLen, VfxBool isMe = VFX_FALSE);

    // Constructor with linked user id and user name (use by phonebook)
    VappSnsActivitiesPage(VfxU16 contactId);
    
// Enum
public:
    // Layout mode
    enum LayoutMode {
        LAYOUT_MODE_ACTIVITIES_ALL,
        LAYOUT_MODE_ACTIVITIES_PHONEBOOK,
        LAYOUT_MODE_ACTIVITIES_PROFILE
    };
    
    // Margin cell id
    enum ListMarginItemCellId {
        MARGIN_ITEM_TOP_REFRESH = 0,
        MARGIN_ITEM_BUTTOM_VIEW_MORE = 0,
    };
    
// Overridable
protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Enter function
    virtual void onEnter(VfxBool isBackWard);

    // Enter function
    virtual void onEntered(/*VfxBool isBackWard*/);

    // Exit function
    virtual void onExited2();

public:
    // Entered page [workaround-VcpTabCtrlPage can't provide correct entered timing]
    virtual void onSubPageEntered();

    // Proc function
    virtual mmi_ret onProc(mmi_event_struct *evt);

    // Query rotate function
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param
    );

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

    // Invalidate list
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

    // Item extened updated
    virtual void onItemExtUpdated(
        VfxS32 listId,
        VfxU16 index,
        VfxChar *objId,
        VfxS32 result
    );

    // Load callback function
    virtual void onGetLoadResults(
        VfxS32 listId, 
        VfxU16 total, 
        VfxS16 startIndex, 
        VfxS16 endIndex
    );

    // Account logged out
    virtual void onAccountLoggedOut(
        VfxU32 provider,
        srv_sns_log_out_type type
    );

    // Get list item
    virtual VfxFrame *getItem(
        VfxS32 group, 
        VfxS32 index
    );

    // Get list count
    virtual VfxU32 getCount();

    // Get cell hittable
    virtual VfxBool getCellIsDisabled(VfxS32 index);    

    // Get menu empty text
    VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

// Implement
private:
    // Get list 
    void getHappeningsList(
        VfxBool refresh
    );

    // Refresh button click
    void onRefreshBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    // View more button click
    void onViewMoreBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    // Filter selected handler
    void onFilterSelected(
        VfxPage *page
    );

    
// Variable
private:
    enum ToolBarId {
        TOOL_BAR_ID_POST = 0,
        TOOL_BAR_ID_UPLOAD,
        TOOL_BAR_ID_FILTER,
        TOOL_BAR_ID_SETTINGS
    };

    // Layout mode
    LayoutMode m_mode;

    // Support rotate flag
    VfxBool m_supportRotate;

    // Activities list
    VappSnsListCp *m_list;

    // Refresh cell
    VappSnsItemRefreshCell *m_refreshCell;

    // View more cell
    VappSnsItemViewMoreCell *m_viewMoreCell;

    // Service result code
    VfxS32 m_statusResult;

    // Cell count
    VfxU32 m_count;

    // Provider id
    VfxU32 m_provider;
    
    // Users id list
    VfxChar *m_user;

    // User number
    VfxU8 m_userNum;

    // Contact id 
    VfxU16 m_contactId;

    // List id
    VfxS32 m_listId;

    // Is me flag
    VfxBool m_isMe;

    // Filter type
    VappSnsFilterTypeEnum m_filterType;

    // Filter id
    VfxU32 m_filterId;

    // View more flag
    VfxBool m_viewMore;

    // Is backward flag
    VfxBool m_isBackward;
};


// VappSnsContactListPage class declaration
class VappSnsContactListPage : public VappSnsBasePage, IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSnsContactListPage);

// Enum
public:
    // Layout mode enum
    enum LayoutModeEnum {
        LAYOUT_MODE_VIEWER_ALL,
        LAYOUT_MODE_VIEWER_BY_PROVIDER,
        LAYOUT_MODE_VIEWER_BY_GROUP,
        LAYOUT_MODE_PICKER_ALL,
        LAYOUT_MODE_PICKER_BY_PROVIDER,
        LAYOUT_MODE_PICKER_BY_GROUP,
        LAYOUT_MODE_END
    };

// Constructor / Destructor
public:
    // Default constructor
    VappSnsContactListPage(
        LayoutModeEnum mode = LAYOUT_MODE_VIEWER_ALL, 
        const VfxWChar *searchName = NULL,
        VfxBool supportRotate = VFX_FALSE, 
        VfxBool hittable = VFX_TRUE
    ); 

// Override
public:
    // Entered page [workaround-VcpTabCtrlPage can't provide correct entered timing]
    virtual void onSubPageEntered();

	// Proc function
    virtual mmi_ret onProc(mmi_event_struct *evt);

protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Enter function
    virtual void onEnter(VfxBool isBackward);

    // Entered function
    virtual void onEntered();

    // Before close page function
    virtual void onBeforeAutoClose();

    // Exit page function
    virtual void onExit(VfxBool isBackward);

    // Back event
    virtual void onBack();

    // Rotate event
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param
    );

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
    
    // Invalidate list
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

    // Account logged out
    virtual void onAccountLoggedOut(
        VfxU32 provider,
        srv_sns_log_out_type type
    );

    // Popup click event
    virtual void onPopupButtonClicked(
        VfxObject *sender,
        VfxId id
    );

// Override
public:
    // IVcpGroupListMenuContentProvider
    virtual VfxBool getItemText (
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
    );   
    
    virtual VfxBool getItemImage(
        VcpMenuPos pos,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
    );

    virtual VfxBool getItemIsHighlightable(
        VcpMenuPos pos  
    ) const;    

    virtual VfxBool getMenuEmptyText (
        VfxWString &text,               
        VcpListMenuTextColorEnum &color
    );    

    virtual VcpListMenuItemStateEnum getItemState (
        VcpMenuPos pos    
    ) const;

    virtual void closeItemImage(
        VcpMenuPos index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType,     // [IN] the type of the field in the cell
        VfxImageSrc imgSrc                  // [IN] the image resource
    ) {};

    virtual VfxU32 getCount(
        VfxU32 group
    ) const;

    virtual VfxU32 getGroupCount() const;    

    virtual VfxBool hasGroupHeader(
        VfxS32 group    // [IN] position of the item
    ) const;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame (
        VcpMenuPos pos,         // [IN] position of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
    );



// Implementation
public:
    // This function is used to set filter type and id
    void setFilterId(
        VappSnsFilterTypeEnum type,
        VfxS32 filterId
    );

    // This function is used to update filter id
    void setFilterId();

    // This function is used to enable me contact
    void enableMeContact(
        VfxBool enable
    );

    // This function is used to set recommand coditions
    void enableRecommandList(
        VfxWChar *name
    );

    // This function is used to set max selected number
    void setMaxSelectedNum(
        VfxU8 num
    );


private:
    // This function is used to get contact list
    void getContactsList();
    
    // This function is used to get contact info
    VfxBool getContactInfo(
        VfxU32 index, 
        void **contact
    );

    // This function is used update layout
    void updateLayout();

    // This function used to handle item selection event
    void onItemSelectionChanged(
        VcpGroupListMenu *list, 
        VcpMenuPos pos, 
        VcpListMenuItemStateEnum state
    );

    // This function used to handle item tapped event
    void onItemTapped(
        VcpGroupListMenu *list, 
        VcpMenuPos pos
    );

    // This funtion is used to handle filter selected signal
    void onFilterSelected(
        VfxPage *page
    );

    // This function is used to handle rename signal
    void onGroupNameChanged(
        VfxObject* sender, 
        VcpInputPopupButtonEnum type
    );

    // This function is used to received operation executing result
    void onReceivedGroupResult(
        VappSnsContactGroupOpEnum op,
        srv_sns_result result
    );

    // This function is used to handle search button clicked event
    void onSearchBtnClicked(
        VcpTextEditor *textEditor,
        VfxWChar *text
    );

    // This function is used to handle back button clicker event
    void onSearchBtnCanceled(
        VcpTextEditor *textEditor
    );

    // This function is used to prepare storage memory
    VfxBool prepareStorage(VfxU8 num);

    // This function is used to post event to caller
    void postTocaller(VfxS32 result);

// Signal
public:
    // On item tapped (used by normal page)
    VfxSignal2 <VfxU32, VfxChar *> m_signalItemTapped;
    
    // On item selected signal 
    //VfxSignal1 <>

    // On multiple item selected signal
    

// Variable
private:
    // enum
    enum ButtonIdEnum {
        TOOL_BAR_ID_EDIT_MEMBER,
        TOOL_BAR_ID_RENAME,
        TOOL_BAR_ID_OK,
        TOOL_BAR_ID_CANCEL,
        TOOL_BAR_ID_FILTER,
        TOOL_BAR_ID_GROUP,

        COMMAND_POPUP_ID_ADD_MEMBER,
        COMMAND_POPUP_ID_REMOVE_MEMBER,
        COMMAND_POPUP_ID_CANCEL
    };

    // Selected result
    enum SelectedResultEnum {
        SELECTED_RESULT_CANCEL  = 0,
        SELECTED_RESULT_OK      = 1
    };

    // Sync state
    enum SyncState {
        SYNC_STATE_NONE,
        SYNC_STATE_WAITING_FOR_ANSWER,
        SYNC_STATE_SYNCING,
        SYNC_STATE_CANCELED,
        SYNC_STATE_DONE
    };

    // Layout mode
    LayoutModeEnum m_mode;

    // Support rotate
    VfxBool m_supportRotate;

    // List menu
    VcpGroupListMenu *m_list;

    // Search bar item
    VappSnsListMenuItemSearchBar *m_searchBar;

    // Account list id
    VfxS32 m_acctListId;

    // List id
    VfxS32 m_listId;

    // Count number
    VfxS32 m_count;

    // Total number
    VfxS32 m_total;

    // Filter id 
    VfxU32 m_providerId;

    // Sub filter id
    VfxS32 m_groupId;

    // Filter id
    vapp_sns_filter_struct m_filterId;
    
    // Has me contact
    VfxBool m_hasMeContact;

    // TODO: recommand list
    // Has recommand list
    VfxBool m_hasRecommand;

    // Group name
    VfxWString m_title;

    // Name
    VfxWChar m_searchName[SRV_SNS_MAX_LEN_NAME + 1];

    // List memory pointer
    srv_sns_user_list_struct *m_storage;

    // Storage size
    VfxU8 m_storageCount;

    // Max selected number
    VfxU8 m_maxSelectedNum;

    // Selected number
    VfxU8 m_selectedNum;

    // Group operation
    VfxBool m_toAdd;

    // Service status result
    VfxS32 m_statusResult;

    // Cui id
    mmi_id m_cuiId;

    // Backward flag
    VfxBool m_isBackward;

    // Start to sync
    SyncState m_syncState;

    // Hittable flag
    VfxBool m_hittable;
};


#ifdef __MMI_SNS_MESSAGES__

/* Key id use for addExtendId for each cell item */
#define VAPP_SNS_MSG_THREAD_KEY_ID 1
#define VAPP_SNS_MSG_MSG_KEY_ID 2

/*****************************************************************************
 * class VappSnsMsgMainPage
 *****************************************************************************/
class VappSnsMsgMainPage : public VappSnsBasePage, public IVappSnsListContentProvider
{
    VFX_DECLARE_CLASS(VappSnsMsgMainPage);

public:
    enum VappSnsMsgModeEnum
    {
        VAPP_SNS_MSG_THREAD_MODE = 1, 
        VAPP_SNS_MSG_MESSAGE_MODE, 
        VAPP_SNS_MSG_END_OF_MODE
    };
// constructor
public:
    VappSnsMsgMainPage(VappSnsMsgModeEnum mode = VAPP_SNS_MSG_THREAD_MODE);

// Method
public:
    void setThreadId(VfxChar *id, VfxU32 provider);

// provider
public:
    // Get list item
    virtual VfxFrame *getItem(VfxS32 group, VfxS32 index);
    // Get list count
    virtual VfxU32 getCount();
    // Get cell  is hittable or not
    virtual VfxBool getCellIsDisabled(VfxS32 index);
    // Get empty text
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);


protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onEnter(VfxBool isBackWard);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
// override
    virtual void onGetLoadResults(VfxS32 listId,VfxU16 total,VfxS16 startIndex,VfxS16 endIndex);
    virtual void onItemUpdated(VfxS32 listId, VfxU16 index, VappSnsItemUpdatedTypeEnum type, VfxWChar *path);
    virtual void onListInvaildated(VfxS32 listId);
    virtual void onSrvStatusChanged(VfxBool isReady, srv_sns_result result, VfxU32 listId);

private:
    void showLoading(VfxBool isLoading);
    VfxFrame *getThreadItem(VfxS32 group, VfxS32 index);
    void fillThreadItemInfo(VappSnsMsgLauncherCell *cell, srv_sns_thread_struct *info);
    void fillThreadImageInfo(VappSnsMsgLauncherCell *cell, srv_sns_thread_struct *info);
    VfxFrame *getMessageItem(VfxS32 group, VfxS32 index);
    void fillMessageItemInfo(VappSnsMsgLauncherCell *cell, srv_sns_message_struct *info);
    void fillMessageImageInfo(VappSnsMsgLauncherCell *cell, srv_sns_message_struct *info);
    void fillCaptionItemInfo(VappSnsMsgCaption *caption, srv_sns_thread_struct *info);
    void fillCaptionImageInfo(VappSnsMsgCaption *caption, srv_sns_thread_struct *info);
    VfxBool isThreadMode();
    VfxBool isMessageMode();
    void onClickNewMsg();
    void onClickAccountNewMsg(VfxObject *obj, VfxId id);
    void onClickRefresh(VfxObject *obj, VfxId id);
    void onCellTapped(VfxObject *obj, VfxId id);
    void onEditorBoundsChanged(VfxFrame *obj, const VfxRect &rect);
    void onClickCaptionRefresh(VfxObject *obj);
    void onClickCaptionRecipients(VfxObject *obj);
    void onClickViewMore(VfxObject *obj, VfxId id);

private:
    VappSnsMsgCaption *m_caption;
    VappSnsListCp *m_listMenu;
    VappSnsMsgSender *m_msgSender;
    VappSnsMsgModeEnum m_mode;
    VfxU16 m_totalCount;
    VfxBool m_isNeedReset;
    VappSnsMsgViewerPage *m_viewerPage;
    VfxS32 m_viewerPageIdx;
    VappSnsItemViewMoreCell *m_viewMoreCell;
    mmi_id m_snsComposerCui;
    VcpCommandPopup *m_accountPopup;
};
#endif /* __MMI_SNS_MESSAGES__ */
#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __VAPP_SNS_GPROT_H__ */
