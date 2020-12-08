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
 *  vfx_app.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_APP_H__
#define __VFX_APP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

extern "C"
{
#include "MMIDataType.h"
#include "mmi_frm_utility_gprot.h"
}

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_context.h"
#include "vfx_cpp_base.h"
#include "vfx_weak_ptr.h"
#include "vfx_signal.h"
#include "vfx_archive.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// If Yes option is available
// See VfxApp::onProcessClose for more detail
#define VFX_APP_CLOSE_OPTION_YES_FLAG   0x0001
// If No option is available
// See VfxApp::onProcessClose for more detail
#define VFX_APP_CLOSE_OPTION_NO_FLAG    0x0002
// If Background option is available
// See VfxApp::onProcessClose for more detail
#define VFX_APP_CLOSE_OPTION_BG_FLAG    0x0004
// If Later option is available
// See VfxApp::onProcessClose for more detail
#define VFX_APP_CLOSE_OPTION_LATER_FLAG 0x0008

// VfxApp is closed because of pressing the END key
#define VFX_APP_CLOSE_REASON_ENDKEY_FLAG  0x0001
// VfxApp is closed because of OOM
#define VFX_APP_CLOSE_REASON_OOM_FLAG     0x0002
// VfxApp is closed because of Pluto's goback/delete request
#define VFX_APP_CLOSE_REASON_PLUTO_FLAG   0x0003

// History flag
#define VFX_APP_HISTORY_NODE_SERIALIZE_FLAG		0x0001
#define VFX_APP_HISTORY_NODE_PLATFORM_CTX_FLAG  0x0002

// Option/reason bitmask during app close.
// See VfxApp::onProcessClose for more detail
typedef VfxU32 VfxAppCloseOption;
typedef VfxU32 VfxAppCloseReason;

// Indicate the close reason, is it by end-key or by OOM screen.
typedef enum {
    VFX_APP_CLOSE_BY_ENDKEY,    // Close triggered by end-key
    VFX_APP_CLOSE_BY_OOM,       // Close triggered by OOM screen
    
    VFX_APP_CLOSE_BY_END_OF_ENUM
} VfxAppCloseReasonEnum;

// The answer (return value) of VfxApp::onProcessClose
typedef enum {
    VFX_APP_CLOSE_ANSWER_YES,   // Yes, the app can be closed
    VFX_APP_CLOSE_ANSWER_NO,    // No, the app cannot be closed
    VFX_APP_CLOSE_ANSWER_BG,    // The app will enter background
    VFX_APP_CLOSE_ANSWER_LATER, // The app will answer later
    
    VFX_APP_CLOSE_ANSWER_END_OF_ENUM
} VfxAppCloseAnswerEnum;

typedef enum {
    VFX_APP_NO_DYN_HEAP = 0, //default value, never trigger dynamic heap mechanism
    VFX_APP_DYN_HEAP_IN_ACTIVE_SWITCH = (1<<0), //trigger dynamic heap mechanism during active/inactive scenario
    VFX_APP_DYN_HEAP_IN_HIDDEN_SWITCH = (1<<1), //trigger dynamic heap mechanism during active/inactive scenario
} VfxAppDynHeapSettingEnum;

typedef void (*serializeCbFunc)(void *arg, VfxU32 argSize);

/* DOM-NOT_FOR_SDK-BEGIN */
typedef struct {
    MMI_EVT_PARAM_HEADER
    void   *serializeData;
    VfxS32 serializeDataSize;
} vfx_app_serialize_evt_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    mmi_id groupId;
} vfx_app_post_evt_struct;

extern void print_event(VfxU8 *str_prefix, mmi_event_struct *evt);

typedef struct {
    MMI_EVT_PARAM_HEADER
    void *arg1;
    void *arg2;
    void *arg3;
} vfx_app_post_invoke_evt_struct;

typedef void (*mmi_post_invoke_func_type)(void *arg1, void *arg2, void *arg3);

//flag : [IN] flag :VFX_TRUE if success (Heap Enlarged & unhidden). 
//                  VFX_FALSE if fail (OOM canceled & still hidden)
typedef VfxCallback1<VfxBool> VfxAppHeapCallback;

typedef VfxCallback2<
            mmi_group_event_struct *,   // original event sent
            mmi_ret                     // post result
            > VfxAppPostToCallerCb;

class VfxAppScr;
class VfxAppLauncher;
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
// This node is to keep history data of an VfxApp.
class AppHistoryNode : public VfxBase
{
public:
    AppHistoryNode();
    ~AppHistoryNode();

    mmi_id          groupId;
    VfxU16          flag;
    VfxClassInfo    *classInfo;
	VfxBool         logContext;
    void            *serializeData;
    VfxS32          serializeDataSize;
	mmi_proc_func   proxy_proc;
};
/* DOM-NOT_FOR_SDK-END */

/* 
 * VfxApp. This class is a Venus wrapper of an Pluto group.
 * It represent an Pluto top level group and it will have a group id.
 */
class VfxApp : public VfxObject
{
    VFX_DECLARE_CLASS(VfxApp);

    friend class VfxAppLauncher;

// Constructor / Destructor
public:
    VfxApp();
    virtual ~VfxApp();

/* DOM-NOT_FOR_SDK-BEGIN */
// Override
protected:
    virtual void onInit();

    // application is doing to die. release all your resource here.
    virtual void onDeinit();

// Override
public:
    // IVfxAllocatable interfaces    
    virtual VfxU32 _getId() const;
/* DOM-NOT_FOR_SDK-END */

// Method
public:
    // Get the memory context of app.
    VfxContext* getContext() const;

    // Close the app itself. Always call this function to close an APP
    // Do not use VFX_OBJ_CREATE to close an app pointer.
    void exit();

    // Close one screen of this AP via screen id
    void closeScreen(
        mmi_id screenId // [IN] id of screen to be closed.
    );

    // Get screen pointer from screen ID
    // RETURNS: the screen pointer, NULL if id not found.
    VfxAppScr* getScreen(
        mmi_id screenId // [IN] id of screen
    ) const;

    // Get associated group id
    // RETURNS: the group id of this app
    mmi_id getGroupId() const
    {
        return m_groupId;
    }

    // Get application caller's id
    // RETURNS: caller id
    mmi_id getCallerId() const;

    // Get application's dynamic heap setting
    // RETURNS: dynamic heap setting
    VfxU32 getDynHeapSetting() const;
    
    // Get VfxApp pointer by screen group id
    // RETURNS: App pointer, NULL if the group id not found or it is not a Venus App.
    static VfxApp *getObject(
        mmi_id gid  // [IN] group id
    );

    // Send event to application caller
    mmi_ret sendToCaller(
        mmi_group_event_struct *evt // [IN] event
    );

    // post event to application caller, the result will be callback via cb pointer.
    void postToCaller(
        mmi_group_event_struct *evt,    // [IN] event
        VfxAppPostToCallerCb cb = VFX_CALLBACK_NULL // [IN] callback that receive result
    );

    // Check if the app is running
    // Note. During onRun() app is already running, so it will return VFX_TRUE
    VfxBool isRunning() const;

    // Check whether the app is in top most.
    VfxBool isActive() const;

    // Check whether the app is in the active list.
    VfxBool isActiveSerial() const;

    // Check if self group is in active list.
    // If app A create and run cui B, 
    // A and B are both group active but only B is group top active.
    VfxBool isGroupActive() const;

    // Check if self group is in top most (seen by user).
    // If app A create and run cui B, 
    // A and B are both group active but only B is group top active.
    VfxBool isGroupTopActive() const;

    // Insert screen into history before the before_sid.
    mmi_id insertScreen(
        VfxClassInfo    *screenClassInfo,   // [IN] the screen class info
        mmi_id          before_sid          // [IN] the screen will be insert before the screen.
    );

    // Get Screen count within the group of this app
    VfxU32 getScreenCount() const;

    // Get the screen id upon the baseScreenID.
    // This API is used to navigate history.
    mmi_id getNextScreenId(
        mmi_id  baseScreenId            // [IN] The base screen ID
    ) const;

    // Get the screen id below the baseScreenID.
    // This API is used to navigate history.
    mmi_id getPrevScreenId(
        mmi_id  baseScreenId            // [IN] The base screen ID
    ) const;

    // Get the top most screen id in the history.
    mmi_id getTopScreenId() const;

    // Get the first screen id in the history.
    mmi_id getBottomScreenId() const;

    // Get the top screen 
    VfxAppScr* getTopScreen() const;

    // Set application visibility.
    void setHidden(VfxBool value);
    
    // Whether the application is hidden.
    //
    // NOTE: The default value is VFX_FALSE.
    VfxBool getHidden() const;

    // Put app into active state. Note that CUI is not allowed to use this function.
    VfxBool setActive(void);
    
    // Register/deregister callback event.
    // It is a wrapper of mmi_frm_cb_reg_event / mmi_frm_cb_dereg_event
    // Registered event can be handled at onProc() function.
    void registerCBEvent(
        mmi_event_id event_id,          // [IN] event to be reg/dereg
        VfxBool on                      // [IN] true to reg, false to dereg
    );

    void setCABCMode(mmi_frm_cabc_mode_enum mode);
    void resetCABCMode();
    mmi_frm_cabc_mode_enum getCABCMode() const;
    
    // set application's dynamic heap setting
    void setDynHeapSetting(VfxAppDynHeapSettingEnum flag);

	// Serialize application
	// This function is used if current application volunteers to free/shrink its memory usage when it's inactive.
	// This function will trigger VfxApp::onSerialize() where the app can serialize its data.
	// After the serialization of app is done, the callback function will be invoked. Application could launch app or CUI here.
	void serialize(
		void* serializeHint = NULL,     // [IN] hint for serialize. The hint will be passed to onSerialize()
		VfxBool reserveASM = VFX_FALSE, // [IN] indicate if the ASM quota should be reserved. Set FALSE if launch an app. Set TRUE if launch a CUI.
		serializeCbFunc cbFunc = NULL,  // [IN] callback function when the app is serialized
		void* cbArg = NULL,             // [IN] user data. The data will be passed to callback function
		VfxU32 cbArgSize = 0,           // [IN] user data size. This data will be passed to callback function
		mmi_proc_func proxy_proc = NULL // [IN] proc function after the app is serialized
	);

/* DOM-NOT_FOR_SDK-BEGIN */
// Method
public:
    // post invoke a function
    static void postInvoke(mmi_proc_func func, void *user_data);
    static void postInvoke(mmi_post_invoke_func_type func, void *arg1=NULL, void *arg2=NULL, void *arg3=NULL);
/* DOM-NOT_FOR_SDK-END */

// Overridable
protected:
    // entry point of App. override it to start your own application.
    virtual void onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    ) ;

    // Obsolete, please use onProcessClose()
    enum DelReason {
        DEL_BY_SOMEONE,
        DEL_BY_END_KEY,
        DEL_BY_END_OF_ENUM
    };

    // Obsolete, please use onProcessClose()
    // associated screen group is requested to be removed. return false if not agree.
    virtual mmi_ret onGroupDeleteReq(DelReason reason);

    // When application is activated
    // isGroupActive() will return VFX_TRUE.
    virtual void onGroupActive();

    // When application is inactivated, all belonging screens are invisible.
    // isGroupActive() will return VFX_FALSE.
    virtual void onGroupInactive();

    // When application is top activated
    // isGroupTopActive() will return VFX_TRUE.
    virtual void onGroupTopActive();

    // When application is top inactivated.
    // isGroupTopActive() will return VFX_FALSE.
    virtual void onGroupTopInactive();

    // When application is activated due to start of small screen redrawing
    virtual void onGroupSnapshotActive();

    // When application is inactivated due to end of small screen redrawing
    virtual void onGroupSnapshotInactive();

    // When application is hidden due to setHidden(VFX_TRUE).
    virtual void onGroupHidden();

    // When application is unhidden due to setHidden(VFX_FALSE).
    virtual void onGroupUnhidden();

    // Override this to handle group event and registered callback events
    virtual mmi_ret onProc(mmi_event_struct *evt);   

    // When application is about to be close by user action, including user 
    // pressing end-key or user choose to terminate one app in OOM screen.
    virtual VfxAppCloseAnswerEnum onProcessClose(
        VfxAppCloseOption options   // The available option app can choose. 
                                    // It is a bitmask.
    );

    // When application is about to be close by user action, including user 
    // pressing end-key or user choose to terminate one app in OOM screen. 
    // This function has the same behaviors as previous one but includes the close reason.
    virtual VfxAppCloseAnswerEnum onProcessClose(
        VfxAppCloseOption options,
        VfxAppCloseReason reason
    );

    // When receiving the BACK key in the screen, the function will be invoked.
    // Application could overwrite this function to refuse the closure of the screen.
    virtual VfxBool onScrBack(VfxAppScr *scr);

    // When there is no screen remained, this function will be invoked.
    // The VfxApp will be closed afterward.
    virtual void onScrEmpty(void);

	// When applicaion calls serializeAndxxx, this function will be invoked to serialize current
	// application's data. The serialized data will be used when onRestore is invoked.
	virtual void onSerialize(
		void *hint, 
		VfxArchive &archive
	);

	// If the application was serialized before, this function will be invoked to allow application
	// restoring to its previous state before it was serialized.
	virtual void onRestore(
		VfxArchive &archive
	);

// Method
protected:
    // If an App return VFX_APP_CLOSE_ANSWER_LATER during onProcessClose,
    // the App is responsible to proceed the close process via continueClose
    void continueClose(
        VfxAppCloseAnswerEnum answer = VFX_APP_CLOSE_ANSWER_YES
    );

/* DOM-NOT_FOR_SDK-BEGIN */
// Variable
protected:
    mmi_id      m_groupId;
    mmi_id      m_callerId;
    VfxWeakPtr<VfxAppScr> m_pTopScreen;  // previous screen for serialize, used by VfxAppScr

    enum AppState {
        APP_STATE_INIT,
        APP_STATE_NORMAL,
        APP_STATE_DEINITING,
    };

    AppState    m_appState;
    VfxAppLauncher *m_launcher;
    VfxBool     m_needToFreeCtx;
	VfxBool     m_logContext;
    VfxU8       m_CABCMode;
    VfxU32      m_DynHeapSetting;

// Implementation
protected:
    static mmi_ret static_proc(mmi_event_struct *evt);   
    static mmi_ret static_postDeinit(vfx_app_post_evt_struct *evt);
    static mmi_ret static_postFreeASM(vfx_app_post_evt_struct *evt);
    static void static_postToCallerResultCb(mmi_post_result_event_struct *evt);
    static void postInvokeHelper(vfx_app_post_invoke_evt_struct *evt);
    static mmi_ret static_changeHeapInUnhiddenProc(mmi_event_struct *evt);

// Framework internal used
protected:
    virtual void processGroupInactive();
	virtual void processSerialize(void *hint, VfxArchive &ar);
	virtual void processRestore(VfxArchive &ar);
    
// Implementation
protected:
    mmi_id getParentGroupId(void) const;
    
private:
    void postCheckEmpty(mmi_id groupId);
    VfxAppCloseAnswerEnum processClose(VfxAppCloseOption options, VfxU32 reason);
    void setSkipDeleteCheck(void);
    void processScrBack(VfxAppScr *scr);

    mmi_ret processGroupProc(mmi_event_struct *evt);
    static mmi_ret static_group_proc(mmi_event_struct *evt);
	static mmi_ret static_serialize_proc(mmi_event_struct *evt);
	static void static_restore(AppHistoryNode* node);

    void processRun(void* args, VfxU32 argSize);
	
	AppHistoryNode* createAppHistoryNode(void);

// Variable
private:
    VfxU32      m_closeState;       /* used during processClose() flow */
    VfxBool     m_skipDeleteCheck;  /* skip onGroupDeleteReq() */
    
    friend class VfxAppScr;
/* DOM-NOT_FOR_SDK-END */
};

/* DOM-NOT_FOR_SDK-BEGIN */
// Weak Pointer Type Define
typedef VfxWeakPtr <VfxApp> VfxAppWeakPtr;
/* DOM-NOT_FOR_SDK-END */



#endif /* __VFX_APP_H__ */

