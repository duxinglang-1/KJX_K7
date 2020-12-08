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
 *  vapp_msg.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MSG_H__
#define __VAPP_MSG_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#include "vapp_msg_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_msg_gprot.h"
#include "vapp_msg_misc_cp.h"
#include "vapp_msg_contact_bar.h"
#include "vcp_tabctrl_page.h"
#include "vcp_menu_popup.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
#endif
{
    #include "UcSrvGprot.h" /* srv_uc_info_type_enum */
#ifdef __MMI_PUSH_IN_UM__
    #include "WAPPushSrvGprots.h" /* for srv_wap_push_msg_read_status_enum */
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
    #include "ProvBoxSrvGprot.h" /* for srv_provbox_result_enum */
#endif /* __MMI_PROV_IN_UM__ */
    #include "MMI_features.h"

#ifdef __MMI_SSO__
    #include "SmsSrvGprot.h"
    #include "SsoSrvGprot.h"
#endif /* __CLOUD_SUPPORT__ */
}


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappMsgScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappMsgScreen);

//constructor
public:
    VappMsgScreen();

public:
    enum VAPP_MSG_SCREEN_PAGE_ID
    {
        VAPP_MSG_SCREEN_PAGE_TEST, 
        VAPP_MSG_SCREEN_PAGE_ENTRY_POINT, 
        VAPP_MSG_SCREEN_PAGE_TAB, 
        VAPP_MSG_SCREEN_PAGE_CONVERSATION, 
        VAPP_MSG_SCREEN_PAGE_BOX_LIST, 
        VAPP_MSG_SCREEN_PAGE_FOLDER, 
        VAPP_MSG_SCREEN_PAGE_ARCHIVE, 
        VAPP_MSG_SCREEN_PAGE_SIM_MSG, 
        VAPP_MSG_SCREEN_PAGE_DIALOG_LIST, 
        VAPP_MSG_SCREEN_PAGE_DIALOG_LIST_SMS_TEMPLATE_LIST, 
        VAPP_MSG_SCREEN_PAGE_VIEWER, 
        VAPP_MSG_SCREEN_PAGE_SETTING, 
        VAPP_MSG_SCREEN_PAGE_TEMPLATE, 
        VAPP_MSG_SCREEN_PAGE_MEMORY_STATUS, 
        VAPP_MSG_SCREEN_PAGE_SMS_SETTING, 
        VAPP_MSG_SCREEN_PAGE_MMS_SETTING, 
        VAPP_MSG_SCREEN_PAGE_PUSH_SETTING, 
        VAPP_MSG_SCREEN_PAGE_CB_SETTING, 
        VAPP_MSG_SCREEN_PAGE_END
    };

//method
public:
#ifdef __MMI_UM_BOX_LIST_SUPPORT__
    void setMode(VfxBool isConversation);
#endif
    void setFirstEntryMode(VappMsgLaunchMode mode);
    VfxBool checkIsEntered();

// Override
public:
    virtual void on1stReady();
    virtual void on2ndReady();

private:
    void entrySimFolder(srv_um_sim_enum umSim);
    #ifdef __MMI_SNS_MESSAGES__
    VfxPage *createSimPage(VfxU8 select);
    #endif /*__MMI_SNS_MESSAGES__*/

private:
    VappMsgLaunchMode m_mode;
    VfxBool m_isEntered;
    VfxPage* m_pageFirstEnter;
};


#ifdef __MMI_SNS_MESSAGES__
/*****************************************************************************
 * class VappMsgTabPage
 *****************************************************************************/
class VappMsgTabPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappMsgTabPage);

public:
    enum
    {
        VAPP_MSG_TAB_NATIVE = 1, 
        VAPP_MSG_TAB_SNS = 2
    };

// Constructor/Destroctor
public:
    VappMsgTabPage(VappMsgLaunchMode mode = VAPP_MSG_LAUNCH_NORMAL);

// Override
protected:
    virtual void onInit();
    virtual VfxPage *onCreateTabPage(VfxId tabId);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onUpdate();

private:

private:
    VappMsgLaunchMode m_mode;
};
#endif /* __MMI_SNS_MESSAGES__ */

/*****************************************************************************
 * class VappMsgBoxListPage
 *****************************************************************************/
#ifdef __MMI_UM_BOX_LIST_SUPPORT__
class VappMsgBoxListPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMsgBoxListPage);

    enum
    {
        VAPP_MSG_BOX_LIST_INBOX = 0, 
        VAPP_MSG_BOX_LIST_SENT, 
        VAPP_MSG_BOX_LIST_OUTBOX, 
        VAPP_MSG_BOX_LIST_DRAFT, 
        VAPP_MSG_BOX_LIST_ARCHIVE, 
        VAPP_MSG_BOX_LIST_TOTAL_NUM
    };
    enum
    {
        VAPP_MSG_BOX_LIST_TOOLBAR_NEW_MSG = 1, 
        VAPP_MSG_BOX_LIST_TOOLBAR_SIM_MSG, 
        VAPP_MSG_BOX_LIST_TOOLBAR_SETTING, 
        VAPP_MSG_BOX_LIST_TOOLBAR_END
    };
    enum
    {
        VAPP_MSG_BOX_LIST_SIM_NONE, 
        VAPP_MSG_BOX_LIST_SIM_1, 
        VAPP_MSG_BOX_LIST_SIM_2, 
        VAPP_MSG_BOX_LIST_SIM_3, 
        VAPP_MSG_BOX_LIST_SIM_4, 
        VAPP_MSG_BOX_LIST_SIM_CANCEL, 
        VAPP_MSG_BOX_LIST_SIM_TOTAL
    };
// Constructor/Destroctor
public:
    VappMsgBoxListPage(VfxBool isNeedTitle = VFX_TRUE);

// Property
// Method
// Event

    // Override IVcpListMenuContentProvider
    virtual void setMenu(VcpListMenu *menu);
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxBool getItemTextFrameFormat(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxTextFrame *frame             // [OUT] the text frame
        );
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onEntered();
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Implementation
private:
    void onGetMsgNumFinished(srv_um_get_msg_num_result result);
    void onItemTapped(VcpListMenu *listMenu, VfxU32 index);
    void onToolbarClick(VfxObject *obj, VfxId id);
#if (MMI_MAX_SIM_NUM >= 2)
    void onSimCmdClicked(VfxObject *obj, VfxId id);
#endif /* MMI_MAX_SIM_NUM >= 2 */
    static mmi_ret onMsgSrvEvtCb(mmi_event_struct *param);

    VcpListMenu *m_listMenu;
    VfxBool m_isRequest;
    VappMsgDataProvider *m_msgDataProvider;
    srv_um_get_msg_num_result m_msgNumber;
    VfxBool m_isNeedReset;
    VfxBool m_isEntered;
    VfxBool m_isNeedTitle;
};
#endif  /* __MMI_UM_BOX_LIST_SUPPORT__ */ 


/*****************************************************************************
 * class VappMsgDialogPage
 *****************************************************************************/
enum VappMsgDialogPageModeEnum
{
    VAPP_MSG_DIALOG_PAGE_MODE_NORMAL, 
    VAPP_MSG_DIALOG_PAGE_MODE_MARK_SEVERAL, 
    VAPP_MSG_DIALOG_PAGE_END
};
class VappMsgDialogPage : public VfxPage, public IVappMsgDialogListContentProvider
{
    VFX_DECLARE_CLASS(VappMsgDialogPage);

// Constructor
#if defined(__MMI_MAINLCD_320X480__) /* HVGA */
    #define VAPP_MSG_DIALOG_EDITOR_HEIGHT           (39)
    #define VAPP_MSG_DIALOG_EDITOR_MAX_HEIGHT       (VAPP_MSG_DIALOG_EDITOR_HEIGHT * 2)
    #define VAPP_MSG_DIALOG_EDITOR_LEFT_MARGIN      (8)
    #define VAPP_MSG_DIALOG_EDITOR_RIGHT_MARGIN     (8)
    #define VAPP_MSG_DIALOG_EDITOR_UP_MARGIN        (8)
    #define VAPP_MSG_DIALOG_EDITOR_DOWN_MARGIN      (5)
    #define VAPP_MSG_DIALOG_EDITOR_SHADOW           (2)
#elif defined(__MMI_MAINLCD_480X800__) /* WVGA */
    #define VAPP_MSG_DIALOG_EDITOR_HEIGHT           (67)
    #define VAPP_MSG_DIALOG_EDITOR_MAX_HEIGHT       (VAPP_MSG_DIALOG_EDITOR_HEIGHT * 2)
    #define VAPP_MSG_DIALOG_EDITOR_LEFT_MARGIN      (10)
    #define VAPP_MSG_DIALOG_EDITOR_RIGHT_MARGIN     (10)
    #define VAPP_MSG_DIALOG_EDITOR_UP_MARGIN        (10)
    #define VAPP_MSG_DIALOG_EDITOR_DOWN_MARGIN      (9)
    #define VAPP_MSG_DIALOG_EDITOR_SHADOW           (2)
#elif defined(__MMI_MAINLCD_240X320__) /* QVGA */
    #define VAPP_MSG_DIALOG_EDITOR_HEIGHT           (36)
    #define VAPP_MSG_DIALOG_EDITOR_MAX_HEIGHT       (VAPP_MSG_DIALOG_EDITOR_HEIGHT * 1.5)
    #define VAPP_MSG_DIALOG_EDITOR_LEFT_MARGIN      (5)
    #define VAPP_MSG_DIALOG_EDITOR_RIGHT_MARGIN     (5)
    #define VAPP_MSG_DIALOG_EDITOR_UP_MARGIN        (5)
    #define VAPP_MSG_DIALOG_EDITOR_DOWN_MARGIN      (4)
    #define VAPP_MSG_DIALOG_EDITOR_SHADOW           (2)
#elif defined(__MMI_MAINLCD_240X400__) /* WQVGA */
    #define VAPP_MSG_DIALOG_EDITOR_HEIGHT           (36)
    #define VAPP_MSG_DIALOG_EDITOR_MAX_HEIGHT       (VAPP_MSG_DIALOG_EDITOR_HEIGHT * 2)
    #define VAPP_MSG_DIALOG_EDITOR_LEFT_MARGIN      (5)
    #define VAPP_MSG_DIALOG_EDITOR_RIGHT_MARGIN     (5)
    #define VAPP_MSG_DIALOG_EDITOR_UP_MARGIN        (5)
    #define VAPP_MSG_DIALOG_EDITOR_DOWN_MARGIN      (4)
    #define VAPP_MSG_DIALOG_EDITOR_SHADOW           (2)
#else
    #define VAPP_MSG_DIALOG_EDITOR_HEIGHT           (39)
    #define VAPP_MSG_DIALOG_EDITOR_MAX_HEIGHT       (VAPP_MSG_DIALOG_EDITOR_HEIGHT * 2)
    #define VAPP_MSG_DIALOG_EDITOR_LEFT_MARGIN      (8)
    #define VAPP_MSG_DIALOG_EDITOR_RIGHT_MARGIN     (8)
    #define VAPP_MSG_DIALOG_EDITOR_UP_MARGIN        (8)
    #define VAPP_MSG_DIALOG_EDITOR_DOWN_MARGIN      (5)
    #define VAPP_MSG_DIALOG_EDITOR_SHADOW           (2)
#endif /* __MMI_MAINLCD_?X?__ */
    #define VAPP_MSG_DIALOG_EDITOR_BG_HEIGHT        (VAPP_MSG_DIALOG_EDITOR_HEIGHT + VAPP_MSG_DIALOG_EDITOR_UP_MARGIN + VAPP_MSG_DIALOG_EDITOR_DOWN_MARGIN)
    #define VAPP_MSG_DIALOG_EDITOR_BG_MAX_HEIGHT    (VAPP_MSG_DIALOG_EDITOR_HEIGHT * 2 + VAPP_MSG_DIALOG_EDITOR_UP_MARGIN + VAPP_MSG_DIALOG_EDITOR_DOWN_MARGIN)
    enum VappMsgDialogPageToolbarEnum
    {
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_SEND = 1, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_CALL, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_RESEND_FAIL, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_DELETE, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_COPY, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_INSERT, 

        VAPP_MSG_DIALOG_PAGE_TOOLBAR_MS_SELECT_ALL, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_MS_DELETE, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_MS_COPY, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_MS_CANCEL, 
        VAPP_MSG_DIALOG_PAGE_TOOLBAR_END
    };
    enum VappMsgDialogPageMsActionEnum
    {
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_NONE, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_DELETE, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_TO_ARCHIVE, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_TO_SIM1, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_TO_SIM2, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_TO_SIM3, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_TO_SIM4, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_TO_SIM_SELECT, 
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_SMS_TO_PHONE, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_SMS_TO_MEM_CARD, 
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_MMS_TO_PHONE, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_MMS_TO_MEM_CARD, 
        VAPP_MSG_DIALOG_PAGE_MS_ACTION_COPY_TO_TOTAL
    };
    enum
    {
        VAPP_MSG_DIALOG_PAGE_LP_NONE, 
        VAPP_MSG_DIALOG_PAGE_LP_DELETE, 
        VAPP_MSG_DIALOG_PAGE_LP_FORWARD, 
        VAPP_MSG_DIALOG_PAGE_LP_EDIT, 
        VAPP_MSG_DIALOG_PAGE_LP_END
    };
    enum
    {
        VAPP_MSG_DIALOG_PAGE_FB_EMOTICON, 
        VAPP_MSG_DIALOG_PAGE_FB_INSERT, 
        VAPP_MSG_DIALOG_PAGE_FB_TEMPLATE, 
        VAPP_MSG_DIALOG_PAGE_FB_SEND, 
        VAPP_MSG_FOLDER_FB_END
    };
	enum VAPP_MSG_TCARD_SAVE_STORAGE_CAHNGE_STATUS
	{
		VAPP_MSG_TCARD_SAVE_NONE,
		VAPP_MSG_TCARD_SAVE_PHONE_CARD_FULL,
		VAPP_MSG_TCARD_SAVE_PHONE_NO_CARD,
		VAPP_MSG_TCARD_SAVE_CARD_PHONE_FULL
	};	

#ifdef __MMI_SMS_COMPOSER__
    enum VAPP_MSG_DIALOG_PAGE_PHB_CUI_STATUE
    {        
        VAPP_MSG_POP_PHB_NUM,       
        VAPP_MSG_POP_PHB_NAME,
        VAPP_MSG_POP_END
    };    
#endif
public:
    VappMsgDialogPage(
                VfxU32 msgType = SRV_UM_MSG_ALL, 
                VfxU32 boxType = SRV_UM_MSG_BOX_ALL,  
                VfxU32 simType = SRV_UM_SIM_ALL , 
                VappMsgDialogPageModeEnum mode = VAPP_MSG_DIALOG_PAGE_MODE_NORMAL);

// Property
    void setAddress(
            VfxWString addr, 
            srv_um_addr_enum addrType, 
            srv_um_sim_enum simId, 
            srv_um_thread_id_struct thrdId, 
            VfxU32 msgId,               /* for multiple address used */
            srv_um_msg_enum msgType,    /* for multiple address used */
            VfxBool isMultiple);
// Method
// Event

// Overridable
public:
    // for IVAppMessageDialogListContentProvider
    virtual VfxBool getItemInfo(VfxU32 index, VfxU32 &msgId, srv_um_msg_enum &msgType);
    virtual VfxU32 getCount();
    virtual VfxBool getMarkStatus(VfxU32 index);
    virtual VfxBool getCellIsDisabled(VfxU32 index);
    virtual VfxBool getLoadingStatus();
    // for page ime layout
    void adjustImeResize(const VfxSize &size,VfxFrame *focusFrame);
    virtual void onObjectNotify(VfxId id,void * userData);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onEntered();
    virtual void onExited();
    virtual void onBack();
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Implementation
private:
    void onToolbarClick(VfxObject *obj, VfxId id);
    void onListUpdate(VfxObject *obj);
    void onMsOpResult(VfxObject * obj, VfxU32 success, VfxU32 fail, VfxS32 error);
    void onCellTapped(VfxControl *control, VfxU32 index, VfxU32 msgId, srv_um_msg_enum msgType);
    void onCellMarked(VfxControl *control, VfxU32 index, VfxBool isMarked);
    void onCellLongPressed(VfxControl *control, srv_um_msg_box_enum msgBox, VfxU32 msgId, srv_um_msg_enum msgType);
    void onContextMenuSelected(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
    void onLpActionClicked(VfxObject *obj, VfxId id);
    void onMsActionClicked(VfxObject *obj, VfxId id);
    void onCopyCmdClicked(VfxObject *obj, VfxId id);
    void onMsOpCancelled(VfxObject *obj, VfxFloat progress);
    void onMsProgressTimeout(VfxTimer *timer);
    void onEditorTextChanged(VcpTextEditor *editor);
    void onEditorFbClick(VfxObject *obj, VfxId id);
    void onEditorBoundsChange(VfxFrame *frame, const VfxRect &rect);
#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)      
    void onEmoticonClicked(VfxObject *obj, VfxU32 index);
#endif
#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    void onSmsTemplateClicked(VfxObject *obj, VfxWString templateString, VfxU16 templateId);
#endif
    static mmi_ret onMsgSrvEvtCb(mmi_event_struct *param);
    mmi_ret smsSendEvtHdlr(mmi_event_struct *evt);
#ifdef __MMI_MMS_IN_UM__
	mmi_ret mmsSendEvtHdlr(mmi_event_struct * evt);
#endif /* __MMI_MMS_IN_UM__ */
    static void smsSendCb(srv_sms_callback_struct *cbData);
#if (MMI_MAX_SIM_NUM >= 2)
    void onSendConfirmClicked(VfxObject *obj, VfxId id);
#endif /* MMI_MAX_SIM_NUM */
    void onRestrictConfirmClicked(VfxObject *obj, VfxId id);
    void showLoading();
    void stopLoading();
    void createEditor();
    VfxPage *createViewerPage(VfxU32 msgId, VfxU32 msgType);
    void updateToolbar();
    void msActionClicked(srv_um_mark_several_op_action_enum action);
    void createContextItem(
            VcpMenuPopup *cntx, 
            srv_um_msg_box_enum boxType, 
            srv_um_msg_enum msgType, 
            VfxU32 msgId, 
            VfxU32 index);
    VappMsgCntxOptItemCp* createContextSingleItem(
            VcpMenuPopup * parentCntx, 
            VfxId itemId, 
            VfxWString itemText, 
            VfxU32 msgId, 
            srv_um_msg_enum msgType, 
            VfxU32 index);
    VappMsgContactEnum transferCtbarType(srv_um_addr_enum addressType);

#ifdef __MMI_UNIFIED_COMPOSER__
    srv_uc_info_type_enum transferUcType(srv_um_msg_enum msgType);
#endif
    srv_um_msg_enum getMsMarkAllMsgType();
    VappMessageListCopyStorageEnum getTransMsMsgListCopyType();
    void setContactBar();
    VfxBool getAllMsgRead();
    void setAllMsgRead();
    void setAllMsgReadInt();
    VfxBool setMsgRead(VfxU32 msgId, srv_um_msg_enum msgType);
    static void setSmsReadCb(srv_sms_callback_struct *cbPara);
#ifdef __MMI_PUSH_IN_UM__
    static void setPushReadCb(srv_wap_push_msg_read_status_enum result, void *user_data);
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
    static void setProvReadCb(srv_provbox_result_enum result, void *cbPara);
#endif /* __MMI_PROV_IN_UM__ */
    static void *allocMem(VfxU32 size, void * userData);
    static void freeMem(void *ptr);
    void saveRemainderTextToDraft();
    void updateMsToolbar();
    void sendSms(mmi_sim_enum simCard);
    VfxBool checkMsgSimVsInsertSim(srv_um_sim_enum msgSim, mmi_sim_enum *tsfrSim);
    VfxU16 tsfrSimCard2StrId(srv_um_sim_enum msgSim);
    void toolbarSend();
    void toolbarCall();
    void toolbarResendFail();
    void toolbarDelete();
    void toolbarCopy();
    void toolbarInsert();
    void toolbarMsSelectAll();
    void toolbarMsDelete();
    void toolbarMsCopy();
    void toolbarMsCancel();
    void longpressDelete(VappMsgCntxOptItemCp *item);
    void longpressForward(VappMsgCntxOptItemCp *item);
    void longpressEdit(VappMsgCntxOptItemCp *item);
#ifdef __MMI_SMS_COMPOSER__
	void onCommandPopClicked(VfxObject *obj, VfxId id);
	void openPhbCui(VfxU32 mode);
#endif

private:
    VfxBool m_isSetAddr;
    VappMsgDialogPageModeEnum m_mode;
    VfxBool m_isNewMode;
    VfxBool m_isNeedReset;
    srv_um_box_identity_struct m_boxId;
    srv_um_list_filter_struct m_listFilter;
    VappMessageList *m_list;
    VappMsgDialogListCp *m_listMenu;
    VfxU32 m_editorMaxLength;
    VcpTextEditor *m_editor;
    VfxWString m_address;
    srv_um_addr_enum m_addressType;
    srv_um_sim_enum m_addressSimId;
    VcpActivityIndicator *m_loading;
    VcpToolBar *m_toolbar;
    srv_um_mark_several_op_action_enum m_msAction;
    VcpIndicatorPopup *m_msProcessLoading;
    VappMsgContactBar *m_contactBar;
    VfxTimer *m_msProcessTimer;
    VfxBool m_isBlockUpdate;
    VcpFunctionBar *m_editFuncbar;
    VfxU32 m_msgId;
    srv_um_msg_enum m_msgType;
    VfxBool m_isMultiAddr;
    VfxBool m_isStartSetAllMsgRead;
    VfxBool m_isWaitSetAllRead;
    VfxU32 m_setAllReadIndex;
    VcpMenuPopup *m_contextMenu;
    void *m_actionPtr;
    VfxBool m_isEntered;
    VfxBool m_isStartEnter;
    VfxBool m_isNotification;
    VappMsgCopyFilter m_msgCopyFilter;
    VAPP_MSG_TCARD_SAVE_STORAGE_CAHNGE_STATUS m_saveStatus;
#ifdef __MMI_SMS_COMPOSER__
	mmi_id m_phbCuiId;
	VAPP_MSG_DIALOG_PAGE_PHB_CUI_STATUE m_phbCuiStatue;
#endif
};

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * class VappMsgSettingPage
 *****************************************************************************/
class VappMsgSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappMsgSettingPage);

    enum
    {
    #ifdef __MMI_UM_TEMPLATE_SUPPORT__ 
        VAPP_MSG_SETTING_TEMPLATE = 1, 
        VAPP_MSG_SETTING_MEMORY_STATUS, 
    #else
        VAPP_MSG_SETTING_MEMORY_STATUS=1,
    #endif    
        VAPP_MSG_SETTING_SMS, 
#ifdef __MMI_MMS_IN_UM__        
    #ifdef __MMI_MMS_SETTING_PAGE__
        VAPP_MSG_SETTING_MMS, 
    #endif /* __MMI_MMS_SETTING_PAGE__ */
#endif	
	#ifdef __MMI_PUSH_IN_UM__
        VAPP_MSG_SETTING_PUSH,
    #endif
        VAPP_MSG_SETTING_CB, 
#ifdef __SMS_CLOUD_SUPPORT__
        VAPP_MSG_SETTING_BACKUP_CLOUD,
        VAPP_MSG_SETTING_RESTORE_CLOUD,
#endif /* __SMS_CLOUD_SUPPORT__ */
        VAPP_MSG_SETTING_CONVERSATION, 
        VAPP_MSG_SETTING_TOTAL
    };
// Constructor
public:
    VappMsgSettingPage(VfxBool isRotate = VFX_TRUE);
#ifdef __SMS_CLOUD_SUPPORT__
    void smsBackupRestore();
#endif /* __SMS_CLOUD_SUPPORT__ */

// Property
// Method
// Event

// Overridable
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );

#ifdef __SMS_CLOUD_SUPPORT__
	virtual void onBack();
#endif
	
// Implementation
private:
    void getSettingText(VfxU32 id, VfxWString &text);
    void onCellTapped(VcpFormItemCell *cell, VfxId id);
#ifdef __MMI_UM_BOX_LIST_SUPPORT__    
    void onCsSettingChanged(VcpFormItemSwitchCell *cell, VfxId id, VfxBool isOn);
    void onSetSwitchStatusDone(VfxBool isOn);
#endif
#ifdef __SMS_CLOUD_SUPPORT__ 
    void showLoading();
    void stopLoading();
    void cancelSmsBackupRestore();    
    void onBackUpRestoreTapped();
    void onBackupRestoreCancelled(VfxObject *obj, VfxFloat progress);
    void updateProcessLoading(U16 current_value, U16 total_value);
    void onCmdPopupClicked(VfxObject * obj, VfxId id);
    static void onSmsBackupCallback(srv_sms_callback_struct* callback_data);
    static mmi_ret onSmsBackupRestore(mmi_event_struct *param);	
    static mmi_ret handleCuiProc(mmi_event_struct *param);
#endif /* __SMS_CLOUD_SUPPORT__  */
    static mmi_ret onAppMsgEvt(mmi_event_struct *param);

private:
    VfxBool                  m_isRotate;
#ifdef __SMS_CLOUD_SUPPORT__ 
    SMS_HANDLE               m_smsHandle;
    VcpIndicatorPopup*       m_backupLoading;
    VcpIndicatorPopup*       m_restoreLoading;
    srv_sso_provider_struct* m_providerArray;
    srv_sso_provider_struct* m_providers;
    srv_sso_account_struct*  m_accounts;
    VfxBool                  m_isBackup;
    VfxU8                    m_ssoCount;
    VfxBool                  m_isSmsAbort;
#endif /* __SMS_CLOUD_SUPPORT__  */
 };

 
/*****************************************************************************
 * class VappMsgTemplatePage
 *****************************************************************************/
#ifdef __MMI_UM_TEMPLATE_SUPPORT__  
class VappMsgTemplatePage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappMsgTemplatePage);

    enum
    {
        VAPP_MSG_TEMPLATE_SMS = 1, 
        VAPP_MSG_TEMPLATE_MMS, 
        VAPP_MSG_TEMPLATE_TOTAL
    };
// Constructor
public:
    VappMsgTemplatePage();

// Property
// Method
// Event

// Overridable
protected:
    virtual void onInit();
    virtual VfxPage *onCreateTabPage(VfxId tabId);
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );

// Implementation
private:
 };
#endif  /* __MMI_UM_TEMPLATE_SUPPORT__ */ 

/*****************************************************************************
 * class VappMsgMemoryStatusPage
 *****************************************************************************/
class VappMsgMemoryStatusPage : public VfxPage, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMsgMemoryStatusPage);

    #define SIZE_RANGE 1024

    enum
    {
        VAPP_MSG_MEM_STATUS_SMS, 
    #ifdef __MMI_MMS_IN_UM__
        VAPP_MSG_MEM_STATUS_MMS, 
    #endif /* __MMI_MMS_IN_UM__ */
        VAPP_MSG_MEM_STATUS_TOTAL
    };
    enum
    {
        VAPP_MSG_MEM_STATUS_SMS_SIM1, 
    #if (MMI_MAX_SIM_NUM >= 2)
        VAPP_MSG_MEM_STATUS_SMS_SIM2, 
    #endif /* MMI_MAX_SIM_NUM */
    #if (MMI_MAX_SIM_NUM >= 3)
        VAPP_MSG_MEM_STATUS_SMS_SIM3, 
    #endif /* MMI_MAX_SIM_NUM */
    #if (MMI_MAX_SIM_NUM >= 4)
        VAPP_MSG_MEM_STATUS_SMS_SIM4, 
    #endif /* MMI_MAX_SIM_NUM */
        VAPP_MSG_MEM_STATUS_SMS_PHONE, 
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        VAPP_MSG_MEM_STATUS_SMS_MEMORY_CARD, 
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
        VAPP_MSG_MEM_STATUS_SMS_TOTAL
    };
    enum
    {
    #ifndef __COSMOS_NO_USER_DRIVE__
        VAPP_MSG_MEM_STATUS_MMS_PHONE, 
    #endif /* __COSMOS_NO_USER_DRIVE__ */
        VAPP_MSG_MEM_STATUS_MMS_MEM_CARD, 
        VAPP_MSG_MEM_STATUS_MMS_TOTAL
    };
// Constructor
public:
    VappMsgMemoryStatusPage();

// Property
// Method
// Event

// Overridable
    virtual VfxBool getItemText(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxBool getItemIsDisabled(VcpMenuPos pos) const;
    virtual VfxU32 getCount(VfxU32 group) const;
    virtual VfxU32 getGroupCount() const;

// Overridable
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );

// Implementation
private:
    void fillSmsStatusData(VfxS32 idx, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
    void fillSmsSingleSimData(VcpListMenuFieldEnum fieldType, VfxWString simStr, srv_sms_sim_enum smsSimId, VfxWString &outputText);
#ifdef __MMI_MMS_IN_UM__
    void fillMmsStatusData(VfxS32 idx, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
#endif /* __MMI_MMS_IN_UM__ */
    static mmi_ret onMsgSrvEvtCb(mmi_event_struct *param);

	void fillFreeMemoryData(VfxWString &text, VfxBool isPhone);

private:
    VcpGroupListMenu *m_listMenu;
 };
#endif /* __VAPP_MSG_H__ */
