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
 * Vapp_shell_msg_viewer.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef __VAPP_SHELL_MSG_VIEWER_H__
#define __VAPP_SHELL_MSG_VIEWER_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_MSG_VIEWER__

/*****************************************************************************
 * Include
 *****************************************************************************/

/**********  KAL Layer Header **************/

/**********  MMI Layer Header **************/

#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_text_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_base_popup.h"
#include "vfx_sys_memory.h"

#include "vcp_command_title.h"
#include "vcp_list_menu.h"
#include "vcp_waiting_icon.h"
#include "vcp_segment_button.h"
#include "vcp_page_panel.h"
#include "vcp_popup.h"

#include "ShellApp\base\vapp_shell_panel.h"
#include "vapp_msg_data_provider.h"
#include "vapp_notepaper.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

    #include "MMIDataType.h"
    #include "UmSrvGprot.h"
    #include "SmsSrvGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Class VappShellMsgListView
 *****************************************************************************/

class VappShellMsgListScreen : public VfxControl, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappShellMsgListScreen);

    typedef VappShellMsgListScreen      Self;
    typedef VfxControl                  Super;

// Constructor / Destructor
public:
    VappShellMsgListScreen();

    void setMsgList(
        VappMsgList *msgList
    );

    // This method is to freeze mainscreen to update screen
    void setIsFreeze(
        VfxBool isFreeze
    );

    VfxBool getIsFreeze() const;

    VfxBool getIsDirty() const;

    void setIsDirty(VfxBool isDirty);

// Events
public:
    // This signal is invoked when the list Menu button is clicked.
    VfxSignal0 m_signalBackButtonClicked;
    // This signal is invoked when the list Menu item is selected.
    VfxSignal1 <VfxS32> m_signalItemSelected;

private:
    VcpListMenu         *m_listMenu;
    VcpCommandTitle     *m_commandTitle;
    VappMsgList         *m_msgList;
    VappMsgDataProvider *m_dataProvider;
    srv_um_msg_info_struct *m_msgInfo;
    VfxBool             m_isFreeze;
    VfxBool             m_isDirty;

private:
    void onBackButtonClick(VfxObject* sender, VfxId id);
    void onMsgListUpdated();
    void onMsgListReleased();
    void onGetMsgInfoFinished(srv_um_get_msg_info_result result);
    void onListMenuTap(VcpListMenu *menu, VfxU32 index);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();

// Override IVcpListMenuContentProvider
protected:

    virtual void setMenu(VcpListMenu *);

    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
        );

    virtual void closeItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc Image
        );

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const;


    virtual VfxBool swapItem(
        VfxU32 index1,
        VfxU32 index2
        );

    // Get the content frame of the item, it's used when the cell style is
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        ) {return NULL;}

    // Uer should release the resource of the content frame which is created by
    // itself, such as image resource
    virtual void closeItemCustomContentFrame(
        VfxU32 index,                        // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        ) {};
};

/*****************************************************************************
 * Class VappShellMsgNotePaperFrame
 *****************************************************************************/

class VappShellMsgNotePaperFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappShellMsgNotePaperFrame);

    typedef VappShellMsgNotePaperFrame  Self;
    typedef VfxFrame                    Super;

    // Constructor / Destructor
public:
    VappShellMsgNotePaperFrame(void);

    void setSize(
        const VfxSize &value        // [IN] The size to set
    );

    void setPageData(const srv_um_msg_node_struct &msgNode, const VfxS32 pageIndex, const VfxS32 totalPage);

    void setName(const VfxWString &value);
    void setDate(const VfxWString &value);
    void setContent(const VfxWString &value);
    void setCurrentPage(const VfxWString &value);
    void setTotalPage(const VfxWString &value);
    void setIsRead(VfxBool isRead);
    void updateMsgInfo();

private:
    VfxTextFrame        *m_nameFrame;
    VfxTextFrame        *m_dateFrame;
    VfxTextFrame        *m_contentFrame;
    VfxTextFrame        *m_currentPageFrame;
    VfxTextFrame        *m_totalPageFrame;
    VcpWaitingIcon      *m_waitingIcon;
    VfxImageFrame       *m_newMsgIcon;

    VappMsgDataProvider *m_dataProvider;
    srv_um_msg_node_struct m_msgNode;
    srv_um_msg_info_struct *m_msgInfo;
    srv_sms_msg_data_struct m_smsData;

    VfxBool              m_loading;
    VfxS32               m_pageIndex;
    VfxS32               m_totalPage;
    VfxBool              m_IsRead;

private:
    void onGetMsgInfoFinished(srv_um_get_msg_info_result result);
    void showNewMsgAnimation();

    // todo
    // need to get the message id and message type

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    static void onReadSmsDataFinished(srv_sms_callback_struct* callback_data);
};


/*****************************************************************************
 * Class VappShellMsgMainScreen
 *****************************************************************************/

class VappShellMsgMainScreen : public VfxControl, IVappNotePaperFrameProvider
{
    VFX_DECLARE_CLASS(VappShellMsgMainScreen);

    typedef VappShellMsgMainScreen    Self;
    typedef VfxControl                Super;

    enum
    {
        VAPP_SHELL_MV_TOOLBAR_NEW_MESSAGE,
        VAPP_SHELL_MV_TOOLBAR_REPLY_MESSAGE,
        VAPP_SHELL_MV_TOOLBAR_SWITCH_LIST_MENU,
        VAPP_SHELL_MV_TOOLBAR_DELETE,
        VAPP_SHELL_MV_TOOLBAR_TOTAL_ENUM
    };

public:
    VappShellMsgMainScreen(void);

    void setMsgIndex(
        VfxS32 index
    );

    VfxS32 getMsgIndex(void) const;

    void setMsgList(
        VappMsgList *msgList
    );

    // This method is to freeze mainscreen to update screen
    void setIsFreeze(
        VfxBool isFreeze
    );

    VfxBool getIsFreeze() const;

    // Set the frame is focused
    virtual void setFocused(
        VfxBool value   // [IN] VFX_TRUE means this frame will get focus
    );

    VfxS32 replyMsg(void);

    VfxS32 createMsg(void);

    VfxS32 deleteMsg(void);

    void forceUpdate(void);

// Events
public:
    // This signal is invoked when the switch list Menu button is clicked.
    VfxSignal0 m_signalSwitchButtonClicked;

private:
    VappNotePaper               *m_notePaper;
    VcpSegmentButton            *m_toolbar;
    VfxS32                      m_cacheMsgIndex;     // start from 1
    srv_um_msg_node_struct      m_cacheMsgNode;
    VappMsgList                 *m_msgList;
    VfxBool                     m_isFreeze;
    VfxImageFrame               *m_noMsgImage;
    VfxTextFrame                *m_noMsgText;
    VcpWaitingIcon              *m_waitingIcon;
    VfxBool                     m_deleteConfirmed;
    VcpConfirmPopup             *m_confirmPopup;
    VfxBool                     m_isDirty;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();

// IVappNotePaperFrameProvider
protected:
    // Overridable
    virtual VfxFrame* createNPFrame(
        VfxS32 page,    // [IN] the page index
        VfxSize size    // [IN] the frame size
    );

    // Uer should release the resource of the content frame which is created by
    // itself, such as image resource
    virtual void closeNPFrame(
        VfxFrame *cell // [IN] the content frame to be released
    );

    virtual VfxFrame* updateNPFrame(
        VfxS32 page,    // [IN] the page index
        VfxSize size,   // [IN] the frame size
        VfxFrame *cell  // [IN] original frame
    );

    virtual VfxU32 getNPCount() const;


protected:
    void onToolbarClick(VfxObject *sender, VfxId Id);
    void onMsgListUpdating();
    void onMsgListUpdated();
    void onMsgListReleased();
    void onPageIndexChanged(VfxS32 pageIndex, VfxFrame *cell);

    void onNotePaperTap(VfxS32 pageIndex, VfxFrame *cell);
    void onNotePaperPageDeleted(void);

    void onConfirmPopupClicked(VfxObject* sender, VfxId id);
    void onConfirmPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);


private:
    void showDeleteConfirm();

private:
    static void smsDeletedCb(srv_sms_callback_struct* callback_data);
    static mmi_ret screenGroupProg(mmi_event_struct *evt);
    const static VfxResId toolbarConfig[VAPP_SHELL_MV_TOOLBAR_TOTAL_ENUM][4];
};


/*****************************************************************************
 * Class VappShellMsgViewer
 *****************************************************************************/

class VappShellMsgViewer : public VappShellPanel
{
    VAPP_SHELL_PANEL_CREATE(VappShellMsgViewer, VFX_TRUE);

    VFX_DECLARE_CLASS(VappShellMsgViewer);

    typedef VappShellMsgViewer    Self;
    typedef VappShellPanel        Super;

    enum
    {
        MAIN_SCREEN_VIEW = 0,
        LIST_SCREEN_VIEW = 1
    };

    // Constructor / Destructor
public:
    VappShellMsgViewer();

// Property set/get
public:
    virtual VfxS32 getPanelStrId();
    static VfxResId getReadImgId(VfxBool isRead);

    // Set the frame is focused
    virtual void setFocused(
        VfxBool value   // [IN] VFX_TRUE means this frame will get focus
    );

    static VappShellMsgViewer *getActiveShellMsgViewer();
    void onTimeChanged(VfxU32 flag);
private:
    VcpPagePanel            *m_pagePanel;
    VappShellMsgMainScreen  *m_mainScreen;
    VappShellMsgListScreen  *m_listScreen;
    VfxS32                  m_viewMode;
    srv_um_list_cntx_struct *m_listCntx;
    VappMsgList             *m_msgList;

    // Override
protected:
    virtual void onInit(void);

    virtual void onDeinit(void);

    virtual void onInitView(void);

    virtual void onDeinitView(void);

    virtual void onEnterView(void);

    virtual void onExitView(
        ShellExitCauseEnum cause
    );

    virtual void onUpdateView();

    virtual void onUpdate();

private:
    VfxBool serviceIsAvailable(void);
    void onSwitchView(void);
    void onSwitchView(VfxS32 index);
    void onMsgListUpdating(void);
    void onMsgListUpdated(void);
    void onMsgListReleased(void);

private:
    static mmi_ret onUmSrvReadyNotify(mmi_event_struct *param);
    static mmi_ret onUmSrvRefreshNotify(mmi_event_struct *param);
    static VappShellMsgViewer *m_activeShellMsgViewer;

};

/*****************************************************************************
 * Global Function
 *****************************************************************************/


#endif /* __MMI_VUI_SHELL_MSG_VIEWER__ */

#endif

