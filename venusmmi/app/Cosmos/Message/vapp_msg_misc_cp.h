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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH´Ë
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
 *  vapp_msg_misc_cp.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_MSG_MISC_CP_H__
#define __VAPP_MSG_MISC_CP_H__
#include "MMI_features.h" 
#include "ui_core\base\vfx_base.h"
#include "ui_core\pme\vfx_pme.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_msg_dialog_cell.h"
#include "vapp_msg_viewer.h"
#include "vcp_var_height_menu.h"
#include "Vapp_msg_data_provider.h"
#include "vcp_menu_popup.h"

//NCenter 2.0
#include "vsrv_ndeclaration.h"
#include "vsrv_notification.h"

#include "SmsSrvGProt.h"
#include "vapp_msg_ncenter_gprot.h"

//NSS
#include "NotificationGprot.h"

/*****************************************************************************
 * class VappMsgDialogCellCp
 *****************************************************************************/
class VappMsgDialogCellCp : public VappMsgDialogCell
{
    VFX_DECLARE_CLASS(VappMsgDialogCellCp);

// Constructor
public:
    VappMsgDialogCellCp(VfxU32 index = 0, VfxU32 msgId = 0, srv_um_msg_enum msgType = SRV_UM_MSG_NONE);

// Property
    void setMsgInfo(VfxU32 index, VfxU32 msgId, srv_um_msg_enum msgType);
    void setCellDisabled(VfxBool isDisabled);
    VfxU32 getIndex() const;
    VfxU32 getMsgId() const;
    srv_um_msg_enum getMsgType() const;
    srv_um_msg_box_enum getMsgBox() const;

// Overridable
protected:
    virtual void onInit();
    virtual void forceUpdateContent();
    virtual VfxBool isDisabled();

// Implementation
private:
    VappMsgViewerCp *createViewer(VfxU32 type, VfxU32 msgId, VfxU32 msgType, VfxObject *parent);
    void onMsgViewerContentReady(VfxObject *obj, VfxBool isReady);

    VfxU32 m_index;
    VfxU32 m_msgId;
    srv_um_msg_enum m_msgType;
    VappMsgViewerCp *m_msgViewer;          /* for viewer component */
    VfxBool m_isCellDiabled;
};


/*****************************************************************************
 * class IVappMsgDialogListContentProvider
 *****************************************************************************/
class IVappMsgDialogListContentProvider
{
// Overridable
public:
    virtual VfxBool getItemInfo(VfxU32 index, VfxU32 &msgId, srv_um_msg_enum &msgType) = 0;
    virtual VfxU32 getCount() = 0;
    virtual VfxBool getMarkStatus(VfxU32 index) = 0;
    virtual VfxBool getCellIsDisabled(VfxU32 index) = 0;
    virtual VfxBool getLoadingStatus() = 0;
};


/*****************************************************************************
 * class VappMsgDialogListCp
 *****************************************************************************/
enum VappMsgDialogListCpModeEnum
{
    VAPP_MSG_DIALOG_LIST_CP_MODE_NORMAL, 
    VAPP_MSG_DIALOG_LIST_CP_MODE_MS, 
    VAPP_MSG_DIALOG_LIST_CP_MODE_END
};
class VappMsgDialogListCp : public VcpVarHeightMenu
{
    VFX_DECLARE_CLASS(VappMsgDialogListCp);

// Constructor
public:
    VappMsgDialogListCp(VcpVarHeightMenu::VcpVarHeightMenuLayoutType type = VcpVarHeightMenu::LAYOUT_REVERSE);

// Property
    void setProvider(IVappMsgDialogListContentProvider *provider);
    void setMode(VappMsgDialogListCpModeEnum newMode, VfxBool isUpdateExistCell);
    void setMarkAll(VfxBool isMark);
    VappMsgDialogListCpModeEnum getMode() const;
    VfxBool hasPlayAnimation()const {return m_hasPlayAnimation;}

// Method
// Event
    VfxSignal4 <
        VfxControl *,   /* object */
        VfxU32,         /* index */
        VfxU32,         /* message id */
        srv_um_msg_enum /* message type */
    > m_signalCellTapped;
    VfxSignal3 <
        VfxControl *,   /* object */
        VfxU32,         /* index */
        VfxBool         /* mark / unmark */
    > m_signalCellMarked;
    VfxSignal4 <
        VfxControl *,           /* object */
        srv_um_msg_box_enum,    /* message box type */
        VfxU32,                 /* message id */
        srv_um_msg_enum         /* message type */
    > m_signalCellLongPressed;

// Overridable
public:
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
    virtual VfxU32 getCount();

    /* No need to overrider this fucntion now becuase VcpVarHeightMenu design change */
    /* virtual VfxU32 getItemHeight(
        VfxU32 index      // [IN] The index of the item
    ); */
    virtual VfxBool getMenuEmptyText(
        VfxWString & text,
        VcpListMenuTextColorEnum & color);
    
    virtual void reset(); 

public:
    virtual void onBoundsChanged(
        VfxFrame *frame,
        const VfxRect &rect);


protected:
    virtual void onInit();

// Implementation
private:
    VfxFrame *intCreateCell(VfxU32 group, VfxU32 index);
    void onCellTapped(VcpVarHeightMenuCell *varHeightCell);
    void onCellMarked(VfxControl *control, VfxBool isMarked);
    void onCellLongPressed(VcpVarHeightMenuCell *varHeightCell);
    void onCellAnimationPlayed();

    IVappMsgDialogListContentProvider *m_contentProvider;
    VappMsgDialogListCpModeEnum m_mode;
    VfxU32 m_defaultCellHeight;
    VfxBool m_hasPlayAnimation;
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
 * class VappMsgCntxOptItemCp
 *****************************************************************************/
class VappMsgCntxOptItemCp : public VcpMenuPopupItem
{
    VFX_DECLARE_CLASS(VappMsgCntxOptItemCp);

// Constructor
public:
    VappMsgCntxOptItemCp();

// Property
    VfxU32 getMsgId() const;
    srv_um_msg_enum getMsgType() const;
    VfxU32 getIndex() const;
    VfxU32 getThrdIdType() const;
    VfxU64 getThrdIdValue() const;
    void setMsgId(VfxU32 msgId);
    void setMsgType(srv_um_msg_enum msgType);
    void setIndex(VfxU32 index);
    void setThrdIdType(VfxU32 thrdIdType);
    void setThrdIdValue(VfxU64 thrdIdValue);
// Method
// Event

// Overridable
public:

protected:
    virtual void onInit();

// Implementation
private:
    VfxU32 m_msgId;
    srv_um_msg_enum m_msgType;
    VfxU32 m_index;
    VfxU32 m_thrdIdType;
    VfxU64 m_thrdIdValue;
};


/*****************************************************************************
 * class VappMessageList
 *****************************************************************************/
enum VappMessageListStyleEnum
{
    VAPP_MESSAGE_LIST_STYLE_NORMAL, 
    VAPP_MESSAGE_LIST_STYLE_THREAD, 
    VAPP_MESSAGE_LIST_STYLE_END
};
enum VappMessageListCopyStorageEnum
{
    VAPP_MESSAGE_LIST_COPY_STORAGE_NONE, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_ARCHIVE, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_SIM1, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_SIM2, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_SIM3, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_SIM4, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_PHONE, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_MEMORY_CARD, 
    VAPP_MESSAGE_LIST_COPY_STORAGE_END
};

class VappMessageList : public VfxObject
{
    VFX_DECLARE_CLASS(VappMessageList);

// Constructor
public:
    VappMessageList(
                VfxU32 msgType = SRV_UM_MSG_ALL, 
                VfxU32 boxType = SRV_UM_MSG_BOX_INBOX, 
                VfxU32 simType = SRV_UM_SIM_ALL, 
                VappMessageListStyleEnum style = VAPP_MESSAGE_LIST_STYLE_NORMAL);

// Property
    void setThreadId(const srv_um_thread_id_struct threadId);
    void setMsgType(const VfxU32 msgType);
    void setBoxType(const VfxU32 boxType);
    void setSortType(const srv_um_list_idx_enum index);
    void setStyle(const VappMessageListStyleEnum style);
    void setMarkStatus(const VfxU32 index, const VfxBool isMark);
    void setMarkAll(VfxBool isMark, srv_um_msg_enum msgType = SRV_UM_MSG_ALL, VappMessageListCopyStorageEnum storage = VAPP_MESSAGE_LIST_COPY_STORAGE_NONE);
    VfxS32 getCount();
    VfxBool getMsgInfo(const VfxU32 index, srv_um_msg_info_struct *&msgInfo);
    VfxBool getMsgInfo(const VfxU32 index, srv_um_msg_info_struct *&msgInfo, srv_um_thread_info_struct *&threaInfo);
    VfxS32 getIndex(const VfxU32 msgId, const VfxU32 msgType) const;
    VfxU32 getMsgId(const VfxU32 index) const;
    srv_um_msg_enum getMsgType(const VfxU32 index) const;
    VfxU32 getThreadIdType(const VfxU32 index) const;
    VfxU64 getThreadIdValue(const VfxU32 index) const;
    VfxBool getMarkStatus(const VfxU32 index);
    VfxU32 getNumMarked() const;
    VfxBool getIsAllMarked(VfxBool isMark, srv_um_msg_enum msgType = SRV_UM_MSG_ALL, VappMessageListCopyStorageEnum storage = VAPP_MESSAGE_LIST_COPY_STORAGE_NONE) const;
    VfxU32 getNumValidMsMsg(srv_um_msg_enum msgType = SRV_UM_MSG_ALL, VappMessageListCopyStorageEnum storage = VAPP_MESSAGE_LIST_COPY_STORAGE_NONE) const;
    VfxBool getIsMsActionActive() const;
    VfxBool getMsActionDuriation(VfxS32 &finishNum, VfxS32 &totalNum) const;

// Method
    VfxBool isMsgList();        /*  only check if there is a message list, do not send any request to service */
    VfxBool checkMsgList();
    void freeMsStatus();
    VfxBool deleteMarked();    /* a async interface, caller should listen the m_signalOperationResult */
    VfxBool copyMarked(VappMessageListCopyStorageEnum storage);    /* a async interface, caller should listen the m_signalOperationResult */
    void cancelMsAction();

// Event
    VfxSignal1 <VfxObject*> m_signalListUpdated;
    VfxSignal2 <
        VfxObject*, /* VappMessageList class */
        VfxU32      /* index of message info */
    > m_signalSingleMsgUpdated;
    VfxSignal4 <
        VfxObject*, /* VappMessageList class */
        VfxU32,     /* Number of total success messages */
        VfxU32,     /* Number of total failed messages */
        VfxS32      /* Error code */
    > m_signalOperationResult;

// Overridable
protected:
    virtual void onInit();
    virtual void onDeinit();

// Implementation
private:
    // Callback for UM service
    static void onMsgListStatusCb(VfxS32 event, VfxS32 listId, VfxS32 userData);
    static mmi_ret onMsgSrvEvtCb(mmi_event_struct *param);
    // Signal funciton for message data provider
    void onGetMsgNumCb(srv_um_get_msg_num_result result);
    void onGetMsgListCb(srv_um_get_msg_list_result result);
    void onGetMsgInfoCb(srv_um_get_msg_info_result result);
    void onGetThreadListCb(srv_um_get_thread_list_result result);
    void onGetThreadInfoCb(srv_um_get_thread_info_result result);
    void onMarkSeveralOpCb(srv_um_mark_several_op_result result);
    void onMarkSeveralThreadOpCb(srv_um_mark_several_thread_op_result result);
    void resetList(VfxBool out_of_date);
    VfxBool generateMsList(VfxBool isReset);
    void updateMsList();
    void checkUpdateMsgInfoList();

private:
    VfxBool m_isMsActionActive;
    srv_um_box_identity_struct m_boxId;
    VfxS32 m_listId;
    srv_um_list_filter_struct m_listFilter;
    srv_um_list_cntx_struct *m_list;
    srv_um_list_cntx_struct *m_msList;
    VfxU32 *m_msMarkStatus;
    VfxU32 m_numMarked;
    VappMsgDataProvider *m_msgDataProvider;
    VappMessageListStyleEnum m_style;
    VfxU32 m_updateMsgInfoListSize;
    VfxBool *m_updateMsgInfoList;
    VfxBool m_isResetList;
};

/*************************************************************************************
* NCenter 2.0
**************************************************************************************/

enum VappMsgFullNCenterMsgTypeEnum
{
	VAPP_MSG_FULL_NCENTER_NONE = 0,
	VAPP_MSG_FULL_NCENTER_SMS_SIM1 =	0x01, 
	VAPP_MSG_FULL_NCENTER_SMS_SIM2 =	0x02, 
	VAPP_MSG_FULL_NCENTER_SMS_SIM3 =	0x04, 
	VAPP_MSG_FULL_NCENTER_SMS_SIM4 =	0x08, 
	VAPP_MSG_FULL_NCENTER_SMS_PHONE =	0x10, 
	VAPP_MSG_FULL_NCENTER_SMS_CARD =    0x20,
	VAPP_MSG_FULL_NCENTER_MMS_PHONE =	0x40, 
	VAPP_MSG_FULL_NCENTER_MMS_CARD =	0x80, 
	VAPP_MSG_FULL_NCENTER_PROV =		0x100, 
	VAPP_MSG_FULL_NCENTER_END_MSG_TYPE
};

enum VappMsgFullNcenterNVRAMEnum
{
	VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT, 
	VAPP_MSG_FULL_NCENTER_DISPLAY_TAG, 
	VAPP_MSG_FULL_NCENTER_NVRAM_END
};

enum VappMsgFullNcenterTextFieldEnum
{
    VAPP_MSG_FULL_NCENTER_MAIN_TEXT, 
    VAPP_MSG_FULL_NCENTER_SUB_TEXT, 
    VAPP_MSG_FULL_NCENTER_END_TEXT
};

typedef struct vapp_msg_ncenter_info {
    VappMsgNCenterCellMenu type;
} vapp_msg_ncenter_info_struct; 


//NCenter
extern "C" mmi_ret vapp_msg_event_ncenter_hdlr(mmi_event_struct *evt);
extern "C" mmi_ret vapp_msg_ready_event_hdlr(mmi_event_struct *evt);
extern "C" mmi_ret vapp_msg_refresh_event_hdlr(mmi_event_struct *evt);

extern "C" void vapp_msg_show_ncenter_cell(VappMsgNCenterCellMenu type, VfxU32 data = 0);
extern "C" void vapp_msg_check_show_mem_full_cell(VappMsgNCenterCellMenu type);
extern "C" void vapp_msg_show_ncenter_unread_nmgr_text(mmi_event_struct *evt);
extern "C" void vapp_msg_show_ncenter_send_fail_balloon(mmi_event_struct *evt, VfxBool isSMS);
extern "C" void vapp_msg_close_ncenter_cell(VappMsgNCenterCellMenu type);

//Unread
extern "C" mmi_ret vapp_msg_unread_event_hdlr(mmi_event_struct * evt);
extern "C" void vapp_msg_unread_intent_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);

//Unsend
extern "C" mmi_ret vapp_msg_unsend_event_hdlr(mmi_event_struct * evt);
extern "C" mmi_ret vapp_msg_sms_send_event_hdlr(mmi_event_struct * evt);
#ifdef __MMI_MMS_IN_UM__
extern "C" mmi_ret vapp_msg_mms_send_event_hdlr(mmi_event_struct * evt);
#endif /* __MMI_MMS_IN_UM__ */
extern "C" void vapp_msg_unsend_intent_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);
extern "C" void vapp_msg_unsend_launch_callback(VfxAppLauncherResultEnum result, void *userData);
extern "C" VfxU32 vapp_msg_get_sending_count();
extern "C" VfxU32 vapp_msg_get_send_fail_count();

//memory full
extern "C" mmi_ret vapp_msg_sms_mem_full_event_hdlr(mmi_event_struct *evt);
#ifdef __MMI_MMS_IN_UM__
extern "C" mmi_ret vapp_msg_mms_mem_full_event_hdlr(mmi_event_struct *evt);
#endif /* __MMI_MMS_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
extern "C" mmi_ret vapp_msg_prov_mem_full_event_hdlr(mmi_event_struct *evt);
#endif /* __MMI_PROV_IN_UM__ */
extern "C" void vapp_msg_mem_full_intent_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);
extern "C" void vapp_msg_mem_full_launch_callback(VfxAppLauncherResultEnum result, void *userData);
extern "C" srv_sms_sim_enum vapp_msg_tsfr_type_to_sms_sim(VappMsgFullNCenterMsgTypeEnum type);
extern "C" VfxU32 vapp_msg_tsfr_type_to_strId(VappMsgFullNCenterMsgTypeEnum type, VappMsgFullNcenterTextFieldEnum field);
extern "C" VfxBool vapp_msg_is_insert_sim(VappMsgFullNCenterMsgTypeEnum type);
extern "C" VfxU32 vapp_msg_query_memory_max(VappMsgFullNCenterMsgTypeEnum type);
#ifdef __MMI_PROV_IN_UM__
extern "C" VfxU32 vapp_msg_query_prov_max();
#endif /* __MMI_PROV_IN_UM__ */
#ifdef __MMI_MMS_IN_UM__
extern "C" VfxU32 vapp_msg_query_mms_max(VappMsgFullNCenterMsgTypeEnum type);
#endif /* __MMI_MMS_IN_UM__ */
extern "C" VfxU32 vapp_msg_query_sms_max(srv_sms_sim_enum simCard, VappMsgFullNCenterMsgTypeEnum type);
extern "C" VappMsgNCenterCellMenu vapp_msg_full_ncenter_msg_type_to_cell(VappMsgFullNCenterMsgTypeEnum type);
extern "C" VappMsgFullNCenterMsgTypeEnum vapp_msg_full_ncenter_msg_cell_to_type(VappMsgNCenterCellMenu cell);

//NVRAM
extern "C" VfxBool vapp_msg_read_nvram_setting(VappMsgNCenterCellMenu type);
extern "C" void vapp_msg_write_nvram_setting(VappMsgNCenterCellMenu tag, VfxBool setting);

extern "C" VfxU32 vapp_msg_read_nvram_mem_full_setting(VappMsgFullNcenterNVRAMEnum tag);
extern "C" void vapp_msg_write_nvram_mem_full_setting_single(VappMsgFullNCenterMsgTypeEnum singleSetting, VfxBool isOn, VappMsgFullNcenterNVRAMEnum tag);
extern "C" void vapp_msg_write_nvram_mem_full_setting(VfxU8 setting, VappMsgFullNcenterNVRAMEnum tag);
extern "C" MMI_BOOL vapp_msg_update_mem_full_previous_setting(VappMsgFullNCenterMsgTypeEnum singleSetting);
extern "C" MMI_BOOL vapp_msg_mem_full_cell_is_previous_show(VappMsgFullNCenterMsgTypeEnum singleSetting);
extern "C" MMI_BOOL vapp_msg_mem_full_cell_is_show(VappMsgFullNCenterMsgTypeEnum singleSetting);

//NSS
typedef enum
{	
    ICON_UNREAD,
    ICON_UNSEND,
    ICON_SENDING,
    ICON_MEMFULL
}icon_type;

extern "C" void vapp_msg_nss_set_alert_info_icon(icon_type type, mmi_frm_nmgr_alert_struct& alert_info);
extern "C" void vapp_msg_nss_set_alert_info_unread_text_preview(VfxWString* previewText, mmi_frm_nmgr_alert_struct& alert_info);
extern "C" void vapp_msg_nss_set_alert_info_unsend_balloon(VfxWString* previewText, mmi_frm_nmgr_alert_struct& alert_info);
extern "C" void vapp_msg_nss_cancel_alert(icon_type type);
extern "C" mmi_ret vapp_msg_nss_unread_launch (mmi_event_struct *param);
#endif /* __VAPP_MSG_MISC_CP_H__ */
