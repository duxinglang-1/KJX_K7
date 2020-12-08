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
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_MAIN_H__
#define __VAPP_SNS_MAIN_H__
 
#include "MMI_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "MMIDataType.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_photo_border_frame.h"
#include "vcp_tabctrl_page.h"
//#include "SnsTypes.h"
#include "SnsSrvTypes.h"

#include "vapp_sns_main_cp.h"
#include "vapp_sns_base.h"
#include "vapp_sns_factory.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalResDef.h"
#include "SnsSrvTypes.h"
#include "SnsSrvGprot.h"
#ifdef __cplusplus
}
#endif

//#define __TEST_NEW_EVENT__


/***************************************************************************** 
 * Define
*****************************************************************************/
#ifdef __MMI_SNS_CENTER__
extern "C" MMI_ID vapp_sns_app_launch(void* param, U32 param_size);
#endif /*__MMI_SNS_CENTER__ */

#ifdef __MMI_SNS_SLIM__
#define VAPP_SNS_HAPPENINGS_CACHE_LEN (LCD_HEIGHT * 1.5)
#else
#define VAPP_SNS_HAPPENINGS_CACHE_LEN (LCD_HEIGHT * 2.5)
#endif

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
class VappSnsApp;
class VappSnsMainScr;
class VappSnsTidingsPage;
class VappSnsProviderSelPage;
class VappSnsSwitchBar;

#ifdef __MMI_SNS_CENTER__
//VappSnsApp class declaration
class VappSnsApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappSnsApp);
    
// Constructor / Destructor
public:
    //Default constructor
    VappSnsApp();

// Override
public:
    // Application's entry point
    virtual void onRun(
        void* args, 
        VfxU32 argSize
    );

    // Application's exit point
    virtual void onDeinit();

    // Proc funciton, handle events
    virtual mmi_ret onProc(
        mmi_event_struct * evt
    );

// Method
public:


// Variable
private:
    // Main screen
    VappSnsMainScr *m_screen;
};

//VappSnsMainScr class declaration
class VappSnsMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappSnsMainScr);
    
// Constructor / Destructor
public:
    // Default constructor
    VappSnsMainScr();

// Override
public:
    // Please refer VfxMainScr::on1stReady
    virtual void on1stReady();

    // Main screen exit point
    //virtual void onDeinit();

// Method
public:

};
#endif /*__MMI_SNS_CENTER__ */

// VappSnsAppAgent class declaration
class VappSnsAppAgent : public VappSnsBaseAgent
{
    VFX_DECLARE_CLASS(VappSnsAppAgent);

// Constrctor / Destructor
public:
    // Default constructor
    VappSnsAppAgent();

// Method
public:
    // Get activities list
    VfxS32 getActivities(
        srv_sns_activity_enum type,
        VfxU32 provider,                      // either select by provider
        VfxU16 group,                         // or select by group
        VfxBool isDownloadPic,
        VfxBool forceRefresh
    );

    // Get activities list by id
    VfxS32 getActivityById(
        VfxU32 provider,
        VfxChar *act_id,
        VfxBool isDownloadPic
    );

    // Get activities list by users
    VfxS32 getActivitiesByUser(
        VfxU32 provider, 
        VfxChar *userId, 
        VfxBool isDownloadPic, 
        VfxBool forceRefresh
    );    

    // Get activities list by me
    VfxS32 getActivitiesByMe(
        VfxBool isDownloadPic, 
        VfxBool forceRefresh
    );
    
    // Get activities list by contact
    VfxS32 getActivitiesByContact(
        VfxU16 contactId, 
        VfxBool isDownloadPic, 
        VfxBool forceRefresh
    );    

    // Get photo list by id
    VfxS32 getPhotoById(
        VfxU32 provider, 
        VfxChar *photoId,
        VfxBool isDownloadPic
    );

    // Get comment list of activties
    VfxS32 getComments(
        VfxU32 provider,    
        VfxChar *activityId,
        VfxBool isPhoto,
        VfxBool isDownloadPic, 
        VfxBool forceRefresh
    );    

    // Get notification list
    VfxS32 getNotifications(
        VfxU32 provider, 
        VfxBool isDownloadPic,
        VfxBool forceRefresh
    );

    // Get request list
    VfxS32 getRequests(
        VfxU32 provider, 
        VfxBool isDownloadPic,        
        VfxBool forceRefresh
    );

    // Get user info
    VfxS32 getUserInfo(
        VfxU32 provider,    
        VfxChar *userId, 
        VfxBool isDownloadPic
    );

    // Post status
    VfxS32 postStatus(
        VfxWChar *status, 
        VfxU32 *providers, 
        VfxU8 count
    );

    // Post comment
    VfxS32 postComment(
        VfxU32 provider,
        VfxChar *activityId,
        VfxBool isPhoto,        
        VfxWChar *comment
    );

    // Clear one notification
    VfxS32 clearNotification(
        VfxU32 provider, 
        VfxChar *objId
    );

    // Clear multiple notifications
    VfxS32 clearNotifications(
        VfxU32 provider, 
        VfxChar **objId, 
        VfxU8 count
    );

    // Get service status result
    VfxS32 getServiceResult()
    {
        return m_srvStatusResult;
    }

    // Set service status result
    void setServiceResult(
        VfxS32 result
    )
    {
        m_srvStatusResult = result;
    }

    // Check service result
    static VfxBool checkSrvResult();

    // Get lastest list id
    VfxS32 getLastestListId()
    {
        return m_listId;
    }

// Variable
private:
    // Service status result
    VfxS32 m_srvStatusResult;    

    // Last loaded list id
    VfxS32 m_listId;
};

// VappSnsTabCtrlPage class declaration
class VappSnsTabCtrlPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappSnsTabCtrlPage);

// Enum 
public:
    enum LayoutMode {
        LAYOUT_MODE_MAIN,
        LAYOUT_MODE_MAIN_WITH_NOTIFICATION,
        LAYOUT_MODE_MAIN_WITH_REQUEST,
        LAYOUT_MODE_CONTACT
    };

// Constructor / Destructor
public:
    // Default constructor
    VappSnsTabCtrlPage(
        LayoutMode mode = LAYOUT_MODE_MAIN, 
        VfxU32 providerId = 0,
        VfxChar *userId = NULL,
        VfxU8 userIdLen = 0,
        VfxBool isMe = VFX_FALSE
    );

    // Default constructor
    VappSnsTabCtrlPage(
        LayoutMode mode,
        void *userData,
        VfxBool isMe
    );
   
// Override
protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Entered function
    virtual void onEntered();
    
    // Proc function
    virtual mmi_ret onProc(mmi_event_struct *evt);

    // This function is call while tab page is being created
    virtual VfxPage *onCreateTabPage(VfxId tabId);

    // This function is call in the beginning of tab switching
    virtual void onTabSwitching(VfxId tabId);

    // This function is call in the end of tab switching
    virtual void onTabSwitched(VfxId tabId);

    // This function is called when the count updated
    void onCountsUpdated(VfxU8 message, VfxU8 notifications, VfxU8 requests);

    // This function is used to handle the service status change event
    void onSrvStatusChanged(VfxBool isReady, srv_sns_result result, VfxU32 listId);

    // This function is used to handle to auto logout event
    void onAccountLoggedOut(VfxU32 providerId, srv_sns_log_out_type type);
    
// Variable
private:
    enum TabId {
        TAB_ID_MAIN_START = 1,  /* Don't modify */
        TAB_ID_MAIN_HAPPENINGS = TAB_ID_MAIN_START,
        TAB_ID_MAIN_TIDINGS,
        TAB_ID_MAIN_END,        /* Don't modify */

        TAB_ID_CONTACT_START,   /* Don't modify */
        TAB_ID_CONTACT_PROFILE = TAB_ID_CONTACT_START,  
        TAB_ID_CONTACT_HAPPENINGS,
        TAB_ID_CONTACT_ALBUM,
        TAB_ID_CONTACT_END      /* Don't modify */
    };

public:
    // Layout mode
    LayoutMode m_mode;

private:
    // Provider id
    VfxU32 m_providerId;

    // User id
    VfxChar *m_userId;

    // Is me flag
    VfxBool m_isMe;

    // User data point
    void *m_userDataPointer;

    // Base agent
    VappSnsBaseAgent *m_agent;
};


// VappSnsCommentsPage class declaration
class VappSnsCommentsPage : public VappSnsBasePage, public IVappSnsListContentProvider
{
    VFX_DECLARE_CLASS(VappSnsCommentsPage);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsCommentsPage(
        VfxBool isTitleTappable = VFX_TRUE,
        VfxBool supportRotate = VFX_FALSE
    );

    // Constructor with provider id, activity id, user id [used by image viewer]
    VappSnsCommentsPage(
        VfxU32 provider, 
        VfxChar *photoId,
        VfxChar *userId,           
        VfxBool isTitleTappable = VFX_TRUE,
        VfxBool supportRotate = VFX_FALSE,
        VfxS32 syncListId = 0,
        VfxU32 syncItemIndex = 0        
    );

    // Constructor with provider id and activity id [used by notification details]
    VappSnsCommentsPage(
        VfxU32 provider, 
        VfxChar *activityId,
        VfxBool isTitleTappable = VFX_TRUE,
        VfxBool supportRotate = VFX_FALSE,
        VfxS32 syncListId = 0,
        VfxU32 syncItemIndex = 0
    );

    // Constructor with activity info [used by happenings, widget]
    VappSnsCommentsPage(
        srv_sns_activity_struct *activity, 
        VfxBool isTitleTappable = VFX_TRUE,
        VfxBool supportRotate = VFX_FALSE,
        VfxS32 syncListId = 0,
        VfxU32 syncItemIndex = 0, 
        VappSnsItemLauncherCell *cell = NULL
    );

// Enum
public:
    // Page mode
    enum LayoutMode {
        LAYOUT_MODE_ACTIVITIES_COMMENTS,        // The normal activity, including has a picture which is not belong a album
        LAYOUT_MODE_NOTIFICATIONS_COMMENTS,     // Notifications comments
        LAYOUT_MODE_IMAGE_VIEWER_COMMENTS       // The image is a photo in album
    };

    // Specific handler action mode
    enum SpecificHandlerActionType {
        ACTION_TYPE_ADD_TOOLBAR_ITEM,
        ACTION_TYPE_HANDLE_TOOLBAR_EVENT
    };

// Overridable
public:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Enter function 
    virtual void onEnter(
        VfxBool isBackWard
    );

    // Entered function 
    virtual void onEntered();

    // Query rotate function
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param
    );

    // Update title cell
    VfxBool updateTitleCell(
        srv_sns_user_struct user
    );   


    // Update first cell
    VfxBool updateFirstCell(
        const VfxWString &text, 
        const VfxWString &hint1, 
        const VfxWString &hint2, 
        const VfxImageSrc &image
    );

    // Add text view item
    void updateTextViewItem();

    // View earlier item
    void updateViewMoreItem();

    // Set page content
    virtual void prepareContent(
        VfxBool forceReload = VFX_FALSE
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

    // Item extend updated
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
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

// Enum
private:
    enum ToolBarId {
        TOOL_BAR_ID_ADD = 0,
        TOOL_BAR_ID_COMMENTS,
        TOOL_BAR_ID_CUTOMIZED_INITIAL_VALUE
    };

// Implementation
private:
    // Create tool bar
    void createCustomizedToolBar();

    // Update tool bar
    void updateCustomizedToolBar(
        VfxId updatedId
    );

    // Update tool bar item status
    void updateCustomizedToolBarStatus(
        VfxId updateId
    );

    // Get extend string
    VfxWString &getExtendString(
        VfxWString &string
    );

    // Merge hyperlink to activity message
    VfxWString &getMessageWithUrl(
        VfxWString &message,
        VfxChar *link,
        VfxU16 linkLength
    );
    
    // View more button click
    void onViewMoreBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    // Refresh comments
    void onRefreshBtnClicked(
        VfxObject *sender
    );

    // User tapped handler
    void onTitleTapped(
        VfxObject *sender
    );

    // Show animation
    void showAnimation(
        VfxFrame *fadeInFrame, 
        VfxFrame *fadeOutFrame
    );

    // Free Activity data
    void freeActivitlyData();

    // Copy activity structure
    void copyActivityData(
        srv_sns_activity_struct *activity
    );

// Variable
private:
    // Layout mode
    LayoutMode m_mode;

    // Is user name/image tappable
    VfxBool m_isTitleTappable;

    // Rotate flag
    VfxBool m_supportRotate;

    // Activities cell info
    srv_sns_activity_struct *m_activity;

    // Activities cell info pointer
    srv_sns_activity_struct *m_activity_p;

    // Photo cell info
    srv_sns_photo_struct *m_photo;

    // Provider id
    VfxU32 m_providerId;

    // Activity id
    VfxChar m_activityId[SRV_SNS_MAX_LEN_ID];

    // User id
    VfxChar m_userId[SRV_SNS_MAX_LEN_ID];

    // Comments list
    VappSnsListCp *m_list;

    // Tool bar controller
    VappSnsToolBarController *m_customizedTbCtrl;

    // List id
    VfxS32 m_listId;

    // Activities id 
    VfxS32 m_activityListId;

    // User info list id
    VfxS32 m_userInfoListId;

    // Cell count
    VfxU32 m_count;

    // Hide comments
    VfxBool m_isCommentsHidden;

    // Activities title frame
    VappSnsItemCaption *m_titleCell;

    // Activities cell frame
    VappSnsItemTextView *m_firstCell;

    // Text view cell frame
    VappSnsItemTextViewCell *m_textViewCell;

    // View more cell
    VappSnsItemViewMoreCell *m_viewMoreCell;

    // Fade in timeline
    VfxFloatTimeline *m_fadeInTimeline;

    // Fade out timeline
    VfxFloatTimeline *m_fadeOutTimeline;

    // View more flag
    VfxBool m_viewMore;

    // Refreshing flag
    VfxBool m_refreshing;

    // Service status result
    VfxS32 m_statusResult;

    // Previous list id (used to sync information)
    VfxS32 m_syncListId;

    // Previous item index (used to sync information)
    VfxU32 m_syncItemIndex;

    // Error string text frame
    VfxTextFrame *m_errorStringFrame;

    // Backward flag
    VfxBool m_isBackward;
};

#ifdef __MMI_SNS_CENTER__
class VappSnsReqListContentProvider : public VfxControl, public IVappSnsListContentProvider
{
    VFX_DECLARE_CLASS(VappSnsReqListContentProvider);

public:
    VappSnsReqListContentProvider(){}
    virtual ~VappSnsReqListContentProvider(){}
    
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
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

public:
    VappSnsTidingsPage *m_page;
};

class VappSnsNotiListContentProvider : public VfxControl, public IVappSnsListContentProvider
{
    VFX_DECLARE_CLASS(VappSnsNotiListContentProvider);

public:
    VappSnsNotiListContentProvider(){}
    virtual ~VappSnsNotiListContentProvider(){}
    
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
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

public:
    VappSnsTidingsPage *m_page;
};

// VappSnsTidingsPage class declaration
class VappSnsTidingsPage : public VappSnsBasePage
{
    VFX_DECLARE_CLASS(VappSnsTidingsPage);
// Enum
public:
    // Layout mode
    enum LayoutMode {
        LAYOUT_MODE_NONE,
        LAYOUT_MODE_NOTIFICATION,
        LAYOUT_MODE_REQUESTS,
        LAYOUT_MODE_ALL
    };
    
    // Margin cell id
    enum ListMarginItemCellId {
        MARGIN_ITEM_TOP_REFRESH = 0
    };

// Constructor / Destructor

    // Default constructor
    VappSnsTidingsPage(LayoutMode mode = LAYOUT_MODE_NOTIFICATION);
    
// Overridable
public:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Enter function 
    virtual void onEnter(VfxBool isBackWard);

    // On sub page entered
    virtual void onSubPageEntered();

    // Exited function
    virtual void onExited2();

    // This function is used handle tab switch click event
    virtual void onSegmentBtnSwitched(
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

    // Load callback function
    virtual void onGetLoadResults(
        VfxS32 listId, 
        VfxU16 total, 
        VfxS16 startIndex, 
        VfxS16 endIndex
    );

    // Get list item
    virtual VfxFrame *getItem(
        LayoutMode mode,
        VfxS32 group, 
        VfxS32 index
    );

    // Get list count
    virtual VfxU32 getCount(LayoutMode mode);

    // Get cell hittable
    virtual VfxBool getCellIsDisabled(LayoutMode mode, VfxS32 index);    

    // Get menu empty text
    VfxBool getMenuEmptyText(LayoutMode mode, VfxWString &text, VcpListMenuTextColorEnum &color);

// Implement
public:
    // Refresh button click event
    void onRefreshBtnClicked(
        VfxObject *sender,
        VfxId id
    );

    // Cell status changed event
    void onCellStatusChanged(
        VcpMenuPos menuPos,
        VappSnsRequestCellStatus status
    );

    // Get tidings list
    void getTidingList(VfxBool refresh, LayoutMode mode = LAYOUT_MODE_ALL);

private:
    // Get refreshing status
    LayoutMode getRefreshingStatus()
    {
        return m_refreshing;
    }

    // Set refreshing status
    void setRefreshingStatus(LayoutMode mode, VfxBool finish = VFX_FALSE);

// Variable
private:
    // Layout mode
    LayoutMode m_mode;

    // Refreshing list
    LayoutMode m_refreshing;

    // Notification list
    VappSnsListCp *m_notiList;

    // Notification provider
    VappSnsNotiListContentProvider *m_notiProvider;

    // Notification count
    VfxU32 m_notiCount;

    // Notification list id
    VfxS32 m_notiListId;

    // Request list
    VappSnsListCp *m_reqList;

    // Request provider
    VappSnsReqListContentProvider *m_reqProvider;

    // Request counts
    VfxU32 m_reqCount;

    // Request list id
    VfxS32 m_reqListId;

    // Request status array
    VappSnsRequestCellStatus *m_reqStatus;

    // Focused request index
    VfxS32 m_focusedReqIndex;

    // Swtich bar
    VappSnsSwitchBar *m_switchBar;

    // Service status result
    VfxS32 m_statusResult;
};
#endif /*__MMI_SNS_CENTER__*/


// VappSnsProviderSelPage class declaration
class VappSnsProviderSelPage : public VappSnsBasePage, IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSnsProviderSelPage);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsProviderSelPage(
        VfxBool enableGroupFilter = VFX_TRUE, 
        VfxBool supportRotate = VFX_FALSE
    ); 
    
    VappSnsProviderSelPage(
        srv_sns_feature_category category, 
        VfxU8 feature = 0, 
        VappSnsFilterTypeEnum type = VAPP_SNS_FILTER_TYPE_ALL, 
        VfxU32 m_filterId = 0,
        VfxBool enableGroupFilter = VFX_TRUE,
        VfxBool supportRotate = VFX_FALSE, 
        VfxU32 *defaultSelectedAcct = NULL,
        VfxU32 defaultSelectedCount = 0
    );

// Enum
public:
    // Data type
    enum AccountDataType {
        ACCOUNT_DATA_TYPE_GROUP,
        ACCOUNT_DATA_TYPE_PROVIDER
    };

// Override
public:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Enter function
    virtual void onEnter(VfxBool isBackward);

    // Entered function 
    virtual void onEntered();

    // Back function
    virtual void onBack();

    // Query rotate function
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param
    );

    // Status changed
    virtual void onSrvStatusChanged(
        VfxBool isReady, 
        srv_sns_result result, 
        VfxU32 listId
    );

    // list invaildated
    virtual void onListInvaildated(
        VfxS32 listId
    );

    // Item updated event
    virtual void onItemUpdated(
        VfxS32 listId, 
        VfxU16 index, 
        VappSnsItemUpdatedTypeEnum type, 
        VfxWChar *path
    );

    // This function is used handle tool bar click event
    virtual void onToolbarTapped(
        VfxObject *sender,
        VfxId id
    );
    
    // Load callback function
    virtual void onGetLoadResults(
        VfxS32 listId, 
        VfxU16 total, 
        VfxS16 startIndex, 
        VfxS16 endIndex
    );

#ifdef __MMI_SNS_CONTACTS__
    // Popup button clicked handler
    virtual void onPopupButtonClicked(
        VfxObject * sender,
        VfxId id
    );
#endif

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
public:
    // Get account list
    void getAccountList();

    // Get selected account num
    VfxU8 getSelectedNum();

    // Get selected account
    void getSelectedAccount(VfxU32 *selectedAcct, VfxU8 num);

    // Check the selected type is provider id or group id
    VappSnsFilterTypeEnum getFilterType();
    
    // Check the page is valid or not
    VfxBool checkPageInvalid();

private:
    // Check the itme type is provider or group
    AccountDataType getDataType(VfxU32 index);

    // Get account info
    VfxBool getAcctInfo(VfxU32 index, void** data);

    // Get account name
    VfxBool getAcctName(VfxU32 index, VfxWString &text);

    // Get account image
    VfxBool getAcctImage(VfxU32 index, VfxImageSrc &image);

    // Get account id by index
    VfxBool getAcctId(VfxU32 index, VfxU32 *id);

    // Update the selected list
    VfxBool checkIsSelected(VfxU32 tappedIndex, VfxBool toUpdate = VFX_FALSE);


// Implementation
private:
    // Update layout
    void updateLayout();

    // This function used to handle item selection event
    void onItemSelectionChanged(
        VcpListMenu *list, 
        VfxU32 index, 
        VcpListMenuItemStateEnum state
    );

    // This function used to handle item tapped event
    void onItemTapped(
        VcpListMenu *list, 
        VfxU32 index
    );

// Signal
public:
    // Select signal
    VfxSignal1 <VfxPage *> m_signalAccountSelected;

// Variable
private:
    // enum
    enum ToolBarId {
        TOOL_BAR_ID_CREATE_GROUP,
        TOOL_BAR_ID_SELECT_ALL,
        TOOL_BAR_ID_OK,
        TOOL_BAR_ID_CANCEL
    };

    // Support rotate flag
    VfxBool m_supportRotate;

    // List menu
    VcpListMenu *m_list;

    // List id (provider)
    VfxS32 m_providersListId;

    // Provider count
    VfxU32 m_providersCount;

    // List id (group)
    VfxS32 m_groupsListId;

    // Groups count
    VfxU32 m_groupsCount;

    // Enable group filter flag
    VfxBool m_enableGroupFilter;

    // Category
    srv_sns_feature_category m_category;

    // Feature
    VfxU8 m_feature;

    // Selected account
    VfxU32 *m_selectedAcct;

    // Selected count
    VfxU32 m_selectedCount;

    // Default selected account
    VfxU32 *m_defaultAcct;

    // Default selected count
    VfxU32 m_defaultCount;

    // Select all flag
    VfxBool m_selectAll;

    // The selected id type flag
    VappSnsFilterTypeEnum m_filterType;

    // Filter id
    VfxU32 m_filterId;

    // Service status result
    VfxS32 m_statusResult;

    // Need to post
    VfxBool m_needToPost;

    // Is backward flag
    VfxBool m_isBackward;
};


// VappSnsEditorPage class declaration
class VappSnsEditorPage : public VappSnsBasePage
{
    VFX_DECLARE_CLASS(VappSnsEditorPage);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsEditorPage();

    // Constructor with a provider and activities id 
    VappSnsEditorPage(
        VfxU32 provider, 
        VfxChar *activityId, 
        VfxBool isPhoto = VFX_FALSE, 
        VfxWString userId = VFX_WSTR_NULL
    );

// Enum
public:
    // Page mode enum
    enum EditorMode {
        COMMENT_EDITOR,
        STATUS_EDITOR,
        UPLOAD_EDITOR
    };

    // Button type
    enum ButtonType {
        BUTTON_TYPE_ACCOUNTS_SELECT,
        BUTTON_TYPE_POST,
        BUTTON_TYPE_CANCEL
    };

    // Component size
    enum ComponentSize {
        MARGIN_TOP                  = VAPP_SNS_EDITOR_PAGE_TOP_MARGIN,     //8,4,4
        MARGIN_BUTTOM               = VAPP_SNS_EDITOR_PAGE_BUTTON_MARGIN,  //26,14,8
        COMPONENT_MARGIN            = VAPP_SNS_ITEM_STD_MARGIN,            //14,8,5
        TEXT_EDITOR_HEIGHT_STATUS   = VAPP_SNS_EDITOR_PAGE_EDITOR_MIN_H,   //60,36,32
        TEXT_EDITOR_HEIGHT_COMMENT  = VAPP_SNS_EDITOR_PAGE_EDITOR_MIN_H,   //60,36,32
    };

// Overridable
public:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Enter function 
    virtual void onEnter(
        VfxBool isBackWard
    );

    // Entered function
    virtual void onEntered();

    // This function is used handle tool bar click event
    virtual void onToolbarTapped(
        VfxObject *sender,
        VfxId id
    );

    // Button click handler
    void onButtonClicked(
        VfxObject *sender,
        VfxId id
    );

// Implementation
private:
    // Create text editor
    void setEditor(
        VfxS32 x, 
        VfxS32 y, 
        VfxS32 maxLen
    );

    // Get button string
    VfxResId getButtonString(
        ButtonType btnId
    );

    // Create accounts selection button
    void setActSelBtn(
        VfxS32 x, 
        VfxS32 y
    );

    // On text changed
    void onTextChanged(
        VcpTextEditor *sender
    );

    // On comment posted callback
    void onCommentPostedCb(
        S32 processId,
        U32 count,
        srv_sns_result result
    );

    // On form item bounds changed
    void onFormItemBoundsChanged(
        VfxFrame *obj, 
        const VfxRect &rect
    );

// Variable
private:
    // Tool bar id
    enum ToolBarIdEnum {
        TOOL_BAR_ID_POST,
        TOOL_BAR_ID_CANCEL
    };

    // Form id enum
    enum FormItemIdEnum {
        FORM_ITEM_ID_EDITOR         = 1,
        FORM_ITEM_ID_ACCT_SETTING   = 2,
    };

    // Page mode
    EditorMode m_mode;

    // Form
    VcpForm *m_baseForm;

    // Text editor
    VcpTextEditor *m_textEditor;

    // Function bar
    VcpFunctionBar *m_FunctionBar;

    // Account button [STATUS_EDITOR, UPLOADE_EDITOR]
    VappSnsAcctSelButton *m_actSelBtn;

    // Provider id [COMMENT_EDITOR]
    VfxU32 m_providerId;

    // User name [COMMENT_EDITOR]
    VfxWString m_userId;

    // Activity id [COMMENT_EDITOR]
    VfxChar m_activityId[SRV_SNS_MAX_LEN_ID];

    // Process id 
    VfxS32 m_processId;

    // Callback
    mmi_proc_func m_callback;

    // Is empty content flag
    VfxBool m_hasText;    

    // Is comment to photo flag
    VfxBool m_isPhoto;

    // Temp buffer
    VfxS8 *m_tempBuffer;
};

#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#endif /* __VAPP_SNS_MAIN_H__*/

