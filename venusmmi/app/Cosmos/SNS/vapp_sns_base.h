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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_BASE_H__
#define __VAPP_SNS_BASE_H__
 
#include "MMI_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "MMIDataType.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "SnsSrvTypes.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SNS_BASE_AGENT_MAX_VALID_LIST_NUM 5

#define VAPP_SNS_TRACE0(tr)                  MMI_TRACE(TRACE_GROUP_7, tr)
#define VAPP_SNS_TRACE1(tr, a1)              MMI_TRACE(TRACE_GROUP_7, tr, a1)
#define VAPP_SNS_TRACE2(tr, a1, a2)          MMI_TRACE(TRACE_GROUP_7, tr, a1, a2)
#define VAPP_SNS_TRACE3(tr, a1, a2, a3)      MMI_TRACE(TRACE_GROUP_7, tr, a1, a2, a3)
#define VAPP_SNS_TRACE4(tr, a1, a2, a3, a4)  MMI_TRACE(TRACE_GROUP_7, tr, a1, a2, a3, a4)
#define VAPP_SNS_TRACE6(tr, a1, a2, a3, a4, a5, a6)  MMI_TRACE(TRACE_GROUP_7, tr, a1, a2, a3, a4, a5, a6)


// Indicate the page states
typedef enum {
    VAPP_SNS_PAGE_STATE_NONE = 0,              
    VAPP_SNS_PAGE_STATE_ENTER,
    VAPP_SNS_PAGE_STATE_EXIT,
    VAPP_SNS_PAGE_STATE_CLOSED
} VappSnsPageStateEnum;

// Indicate the page types
typedef enum {
    VAPP_SNS_LAUNCHER_TYPE_UNKNOWN = 0,             // Unknown page type
    VAPP_SNS_LAUNCHER_TYPE_MAIN_HAPPENINGS,         // Use to show activities 
    VAPP_SNS_LAUNCHER_TYPE_TIDINGS_NOTIFICATION,   // Use to show tidings comments page
    VAPP_SNS_LAUNCHER_TYPE_TIDINGS_REQUEST,         // Use to show tidings DM page
    VAPP_SNS_LAUNCHER_TYPE_CONTACT_PROFILE,            // Use to show user profile
    VAPP_SNS_LAUNCHER_TYPE_CONTACT_HAPPENINGS,            // Use to show friend lists
    VAPP_SNS_LAUNCHER_TYPE_CONTACT_ALBUM,        // Use to show freind reguest
    VAPP_SNS_LAUNCHER_TYPE_END
} VappSnsLauncherTypeEnum;

// Filter type
typedef enum {
    VAPP_SNS_FILTER_TYPE_ALL,
    VAPP_SNS_FILTER_TYPE_BY_PROVIDER,
    VAPP_SNS_FILTER_TYPE_BY_GROUP,
    VAPP_SNS_FILTER_TYPE_BY_NOT_IN_GROUP
} VappSnsFilterTypeEnum;

// Item update type
typedef enum {
    VAPP_SNS_ITEM_UPDATED_TYPE_PIC_USER,            //SRV_SNS_PIC_USER
    VAPP_SNS_ITEM_UPDATED_TYPE_PIC_THUMBNAIL,       //SRV_SNS_PIC_THUMBNAIL
    VAPP_SNS_ITEM_UPDATED_TYPE_PIC_PHOTO,           //SRV_SNS_PIC_PHOTO
    VAPP_SNS_ITEM_UPDATED_TYPE_ALL
} VappSnsItemUpdatedTypeEnum;

typedef struct {
    VappSnsFilterTypeEnum type;
    S32 id;
} vapp_sns_filter_struct;

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
class VappSnsBaseAgent;
class VappSnsBasePage;

//VappSnsBaseAgent class declaration
class VappSnsBaseAgent :  public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsBaseAgent);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsBaseAgent(VfxBool autoSetInstance = VFX_TRUE);

// Enum
public:
    enum EventType {
        EVENT_TYPE_START = 0,

        SERVICE_STATUS_EVENT = EVENT_TYPE_START,    //EVT_ID_SRV_SNS_READY
        INVALIDATE_LIST_EVNET,                      //EVT_ID_SRV_SNS_LIST_INVALIDATED
        UPDATE_ITEM_EVENT,                          //EVT_ID_SRV_SNS_ITEM_UPDATED
        UPDATE_ITEM_EXT_EVENT,                      //EVT_ID_SRV_SNS_ITEM_EXT_UPDATED
        UPDATE_COUNT_EVENT,                         //EVT_ID_SRV_SNS_COUNTS_UPDATED
        ACCOUNT_LOGOUT_EVENT,                       //EVT_ID_SRV_SNS_ACCOUNT_LOGGED_OUT

        EVENT_TYPE_END,
    };

    enum ListSpecId {
        // When received signal with list id = LIST_SPEC_ID_NEED_TO_RELOAD should reload the list
        LIST_SPEC_ID_NEED_TO_RELOAD = -1,                  
    };

// Overridable
public:
    // Init function
    virtual void onInit();

    // Deinit function 
    virtual void onDeinit();

    // Load callback 
    virtual mmi_ret loadResultCb(mmi_event_struct *param);

    // Load callback 
    virtual mmi_ret loadItemResultCb(mmi_event_struct *param);

// Method
public:
    // Init service
    static void initSrv();    

    // This function is used to check sns service is ready or not
    static VfxBool isReady(
        VfxBool isAutoInit = VFX_FALSE
    );

    // Get ready result (if srv ready, return SRV_SNS_OK, otherwise, return unready error code)
    static srv_sns_result getReadyResult();

    // Retry a request
    srv_sns_result retryRequest(
        VfxS32 reqId                //[IN] request id
    );

    // This function is used to cancel a pending operation
    srv_sns_result abortRequest(
        VfxS32 reqId                //[IN] request id
    );

    // Check the list is valid or not
    VfxBool checkList(
        VfxS32 listId, 
        VfxS16 *start_index = NULL, 
        VfxS16 *end_index = NULL, 
        VfxU16 *total = NULL
    );

    // Check the item of list is valid or not
    VfxBool checkListItem(
        VfxS32 listId, 
        VfxS16 index
    );

    // Load a list (asychronized API), will invoke onGetLoadResults function when load finished.
    // When invoking m_siganlGetLoadResult, please override VappSnsBasePage::onGetLoadResult 
    // to handle the data.
    VfxS32 loadList(
       VfxS32 listId, 
       VfxU32 index,
       VfxBool isCancelPrevious = VFX_TRUE      //[IN] VFX_TRUE will force cancel the previous unfinished job
    );  

    // Get list item by index
    srv_sns_result getListItem(
        VfxS32 listId, 
        VfxU32 index,
        void **out,
        VfxBool isAutoLoad = VFX_TRUE
    );

    // This function is used to release the data list
    srv_sns_result releaseList(
        VfxS32 listId               //[IN] list id
    );

    // Check is there any accounts has been login
    static VfxBool isLogin(
        VfxU32 providerId = 0
    );

    // Get accounts filtered by login status and features
    VfxS32 getAccounts(
        VfxBool isLogin,
        srv_sns_feature_category category,
        VfxU8 features,
        VfxU16 *count
    );  

    // Get groups
    VfxS32 getGroups();

    // Check features supported by an union of providers
    VfxBool checkFeature(
        VfxU32 providers,
        srv_sns_feature_category category,
        VfxU8 features
    );

    // Check is url or not
    VfxBool checkIsUrl(
        VfxWChar *url
    );    

    // Get sns icon by provider id
    VfxFileRawData &getProviderIcon(
        VfxU32 providerId,
        srv_sns_logo_enum size = SRV_SNS_LOGO_SMALL
    );


    // Get sns name by provider id
    static VfxWChar *getProviderName(
        VfxU32 providerId
    );

    // Get sns error string
    static VfxResId getErrorString(
        VfxS32 errorCode
    );

    // TODO: add common API...

    // This function is used to get active list id, the active list id will be set 
    // when entering loading state.
    // RETURN: Return list id of the job which is waiting for service's feedback.
    //              If there are more than one active job, will return the lastest list id.
    //              The value -1 means there is no job in loading state.
    VfxS32 getActiveListId();

    // Event handler
    mmi_ret eventHandler(mmi_event_struct *param);

    // Register event callback
    // [Notes] If you set enableCompletedInfo to VFX_TRUE, you have to connect and parse the event struct by m_signalServiceEvent.
    //            Agent will NOT post the specific signal again. 
    void registerEventCb(
        EventType type,
        VfxBool enableCompletedInfo = VFX_FALSE     //[In] Set the flag true, if you care about the whole event struct from service.
    );

    // De-register event callback
    void deregisterEventCb(
        EventType type
    );

    // Transfer type
    EventType transferType(
        VfxU16 type
    );

    // Enable compeleted info
    // [Notes] If you set enableCompletedInfo to VFX_TRUE, you have to connect and parse the event struct by m_signalServiceEvent.
    //            Agent will NOT post the specific signal again.  
    void enableCompletedInfo(
        EventType type,
        VfxBool enable
    );

    // Set view more table
    void setViewMore(
        VfxU32 listId, 
        VfxBool hasMore,
        VfxBool clear
    );

    // Get view more table
    VfxBool checkHasMore(
        VfxU32 listId
    );
    
   
// Method
private:

    // Prepare queued item buffer
    void prepareQueuedReqBuffer(VfxU16 totalCount);
    
    // Check the queued get item request
    void checkQueuedGetItemReq(VfxS32 listId, VfxS16 start, VfxS16 end);

// Signal
public:
    // Service status signal (Ready status, service result, list id (if exists))
    VfxSignal3 <VfxBool, srv_sns_result, VfxU32> m_signalSrvStatusChanged;

    // List invalidated signal
    VfxSignal1 <VfxS32> m_signalListInvalidated;

    // Item update signal
    VfxSignal4 <VfxS32, VfxU16, VappSnsItemUpdatedTypeEnum, VfxWChar *> m_signalItemUpdated;

    // Item update extend signal
    VfxSignal4 <VfxS32, VfxU16, VfxChar *, VfxS32> m_signalItemExtUpdated;

    // Count update signal
    VfxSignal3 <VfxU8, VfxU8, VfxU8> m_signalCountUpdated;

    // Account log out signal
    VfxSignal2 <VfxU32, srv_sns_log_out_type> m_signalAccountLoggedOut;

    // Load result signal
    VfxSignal4 <VfxS32, VfxU16, VfxS16, VfxS16> m_signalGetLoadResults;

    // Whole struct signal
    VfxSignal2 <EventType, void *> m_signalServiceEvent;

// Variable
private:
    typedef struct {
        VfxU32 list_id;
        VfxBool more;
    } vapp_sns_more_struct;

    // Service status
    VfxBool m_isSrvReady;

    // Service lastest result code
    srv_sns_result m_result;
    
    // Active list id
    VfxS32 m_activeListId;

    // Is auto loading flag
    VfxBool m_isAutoLoading;

    // Queued request list items array
    VfxBool *m_queuedReqItemsList;

    // Active list total count
    VfxU16 m_queuedReqItemsTotal;

    // Whole event struct information flag
    VfxBool m_enableWholeStruct[EVENT_TYPE_END];

    // View more table
    vapp_sns_more_struct m_hasMore[VAPP_SNS_BASE_AGENT_MAX_VALID_LIST_NUM];

    // Auto set instance flag
    VfxBool m_autoSetInstance;

    // Data
    void *m_signalData; 

    // Icon raw data;
    VfxFileRawData m_rawData;
};

//VappSnsProcessingControl class declaration
class VappSnsProcessingControl : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsProcessingControl);

// Contructor / Destructor
public:
    // Default constructor
    VappSnsProcessingControl() {};

    virtual ~VappSnsProcessingControl() {};

public:
    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if ((event.keyCode == VFX_KEY_CODE_ARROW_UP || event.keyCode == VFX_KEY_CODE_ARROW_DOWN))
        {
            return VFX_TRUE;
        }
        
        return VFX_FALSE;
    }
    
};


//VappSnsBasePage class declaration
class VappSnsBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSnsBasePage);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsBasePage();

    virtual ~VappSnsBasePage();

// Enum
public:
    // Process state
    enum ProcessingState {
        STATE_NONE,
        STATE_LOADING,
        STATE_LOADED,
        STATE_REFRESHING
    };

// Override
public:
    // Proc function
    virtual mmi_ret onProc(mmi_event_struct *evt);

    // On sub page enter function
    virtual void onSubPageEntered();    

protected:
    // Init function
    virtual void onInit();

    // Deinit funciton
    virtual void onDeinit();

    // Enter Page
    virtual void onEnter(
        VfxBool isBackWard
    );

    // Exit page
    virtual void onExited();

    // Before close page
    virtual void onBeforeAutoClose();

    // This function is used handle tool bar click event
    virtual void onToolbarTapped(
        VfxObject *sender,
        VfxId id
    );

    // This function is used handle tab switch click event
    virtual void onTabSwitched(
        VfxObject *sender,
        VfxId id
    );   

    // Status changed
    // Please override this function to handle status changed event       
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
    // Please override this function to handle item updated event
    virtual void onItemUpdated(
        VfxS32 listId,
        VfxU16 index, 
        VappSnsItemUpdatedTypeEnum type, 
        VfxWChar *path
    );

    // Extend item updated
    // Please override this function to handle item updated ext event
    virtual void onItemExtUpdated(
        VfxS32 listId,
        VfxU16 index,
        VfxChar *objId,
        VfxS32 result
    );

    // Counts updated
    // Please override this function to handle counts updated event
    virtual void onCountUpdated(
        VfxU8 messages, 
        VfxU8 notifications, 
        VfxU8 requests
    );

    // Load callback 
    // Please override this function to handle load callback event
    virtual void onGetLoadResults(
        VfxS32 listId, 
        VfxU16 total, 
        VfxS16 startIndex, 
        VfxS16 endIndex
    );

    // Popup click event
    virtual void onPopupButtonClicked(
        VfxObject *sender,
        VfxId id
    );

    // Account logged out
    // Please override this function to handle account logged out event
    virtual void onAccountLoggedOut(
        VfxU32 provider,
        srv_sns_log_out_type type
    );

    // Service status changed callback
    void onSrvStatusChangedCb(
        VfxObject *sender, 
        VfxId id
    );

    // Click setting button
    virtual void onSettingButtonClicked(
        VfxObject *sender, 
        VfxId id
    );

// Method
public:
    // Set page agent
    // [NOTES] please set the agent  and set autoRegister to VFX_TRUE to receive service event!!
    void setAgent(
        VappSnsBaseAgent *agent,
        VfxBool autoRegister
    );

    // Get page agent
    VappSnsBaseAgent *getAgent();

    // This function is used to set page title
    void setTitle(
        const VfxWString &title
    );

    // This function is used to get title
    VfxWString getTitle();

    // This function is used to set need to update
    void setNeedToUpdate(
        VfxBool needToUpdate
    );

    // This function is used to get if need to update
    VfxBool getNeedToUpdate();

    // This function is used to add tab bar item in page
    void setTabBarItem(
        VfxId tabId, 
        const VfxWString &tabString, 
        VfxResId tabIcon,
        VfxBool isHightLighted,
        VfxBool isLastItem
    );

    // Hide tool bar 
    void setIsHideToolBar(
        VfxBool isHide
    );

    // This function is used to add tool bar item in page
    void setToolBarItem(
        VfxId buttonId, 
        const VfxWString &buttonString, 
        VfxResId buttonIcon, 
        VfxBool isLastItem
    );

    // This function is used to add tool bar item in page
    void setToolBarItem(
        VfxId buttonId, 
        const VfxWString &buttonString, 
        const VfxImageSrc &buttonIcon, 
        VfxBool isLastItem
    );

    // This function is used to change tool bar item in page
    void changeToolBarItem(
        VfxId buttonId, 
        const VfxWString &buttonString, 
        VfxResId buttonIcon
    );

    // This function is used to change tool bar item in page
    void changeToolBarItem(
        VfxId buttonId, 
        const VfxWString &buttonString, 
        const VfxImageSrc &buttonIcon
    );

    // This function is used to remove tool bar item in page
    void removeToolBarItem(
        VfxId buttonId
    );

    // This function is used to disable tool bar item in page
    void disableToolBarItem(
        VfxId buttonId,
        VfxBool isDisable
    );

    // Show confirm popup
    void setConfirmPopup(
        const VfxWString &text,
        VcpPopupTypeEnum type = VCP_POPUP_TYPE_WARNING,              
        VcpConfirmPopupButtonSetEnum buttonSet = VCP_CONFIRM_BUTTON_SET_OK
    );

    // Show confirm popup
    void setPopupWithCustomizedBtn(
        const VfxWString &text, 
        VcpPopupTypeEnum type,
        const VfxWString &btnText1, 
        const VfxWString &btnText2,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2
    );

    // Show command popup
    void setCommandPopup(
        const VfxWString &text,
        VcpPopupTypeEnum type = VCP_POPUP_TYPE_INFO 
    );

    // Add command pop up item
    VfxBool addCommandPopupItem(
        VfxId id,                      
        VfxBool isLast,
        const VfxWString &text,         
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL,
        VfxBool enable = VFX_TRUE
    );

    // Show indicator popup when loading
    void setIndicatorPopup(
        VfxBool display,
        const VfxWString &text = VFX_WSTR_NULL
    );

    // Delete all popup
    void hideAllPopup();

    // Show processing page
    void setProcessing(
        VfxBool processing,
        VfxBool isAutoChangeToolBarStatus = VFX_TRUE
    );

    // Get processing flag
    VfxBool getProcessing();

    // Enable accounts setting page
    void enableAcctSettings(
        VfxBool enable
    );
   
    // Get time string
    VfxWString &getTimeString(
        VfxU32 timestamp,
        VfxDateTime &date,
        VfxU32 flag = VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY
    );

    // Set main page flag
    // Default value is false. If it is not main page, the page will auto close once receiving service not ready event
    // If you care about the auto close timing, please override the onBeforeAutoClose virtual function
    void setIsAutoClose(VfxBool isAutoClose)
    {
        m_isAutoClose = isAutoClose;
    }

    // Get main page flag
    VfxBool getIsAutoClose()
    {
        return m_isAutoClose;
    }

    // Before close page
    void beforeAutoClose()
    {
        onBeforeAutoClose();
    }

    // Check if the page is active
    VfxBool checkIsActive()
    {
        return (/*getApp()->isActive() == VFX_TRUE &&*/ isActive() == VFX_TRUE && m_isEntered == VFX_TRUE);
    }

    // Set if the tab page is active
    void setIsTabPageActive(VfxBool isActive)
    {
        m_isTabPageActive = isActive;
    }

    // Check if the tab page is active
    VfxBool getIsTabPageActive()
    {
        return m_isTabPageActive;
    }

private:
    // Event handler
    void eventHandler(
        VappSnsBaseAgent::EventType type,
        void *param
    );

// Signal
public:
    // State changed signal
    VfxSignal3 <VappSnsBasePage*, VappSnsPageStateEnum, VfxBool> m_signalStateChanged;

public:
    // Process state
    ProcessingState m_processState;

private:
    // Need to update flag
    VfxBool m_needToUpdate;
    
    // Agent
    VappSnsBaseAgent *m_agent;

    // Internal agent 
    VappSnsBaseAgent *m_agentInternal;

    // Tab title bar
    VcpTabTitleBar *m_tabTitleBar;

    // Tool bar
    VcpToolBar *m_toolBar;

    // Indicator popup
    VcpIndicatorPopup *m_indicatorPopup;

    // Comfirm popup
    VcpConfirmPopup *m_confirmPopup;

    // Command popup 
    VcpCommandPopup *m_commandPopup;

    // Loading frame
    VappSnsProcessingControl *m_processingFrame;

    // Loading icon
    VcpActivityIndicator *m_loadingIcon;

    // No account text frame 
    VfxTextFrame *m_noAcctFrame;

    // Account setting button
    VcpButton *m_noAcctBtn;

    // Auto close flag
    VfxBool m_isAutoClose;

    // Auto logged out popup
    VcpConfirmPopup *m_autoLoggedOutPopup;

    // Is page entered
    VfxBool m_isEntered;

    // Is tab page actived flag
    VfxBool m_isTabPageActive;
};

#endif /*__SOCIAL_NETWORK_SUPPORT__*/
#endif /* __VAPP_SNS_BASE_H__*/

