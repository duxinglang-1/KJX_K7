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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH此
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
 *  vapp_msg_ext_cp.h
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

not happen on tempload 


[Lifang 5\17]

Dear Ken,

我放了一份新的12.20的bin在\\glbfs14\sw_releases\Valid_Before_20120701\from Lifang，麻烦您验证一下。

谢谢！



0515 Ken

hi , Lifang，你這份load 開不了機，你用的應該是1217 的code base，目前hq 這邊都用e2 的手機了，所以只能用18 以上的code base 。

e1的手機全部回收了…，可能要請你generate 一份1218 或1220 code base的load 再進patch 來驗，麻煩你了




[Lifang 5\13]

Dear Ken,

我在\\glbfs14\sw_releases\Valid_Before_20120701\from Lifang放了一个bin档，由于这笔issue的复现有点难且不是必现，因此我不是很肯定已经把这笔issue解了，想请您帮忙验证一下。

谢谢！


Basic function so set high


[Load Path]

\\mtksfs07\Public3\11B_branch_load\W12.17_Stage1\KHAN50_V11_DEMO_GPRS(12864_COSMOS_HVGA_CN)\12.17_official_release

 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_MSG_GPROT_H__
#define __VAPP_MSG_GPROT_H__

#include "MMI_features.h"  
#include "vfx_mc_include.h"
#include "vapp_ncenter_base_cell.h"
#include "Vapp_msg_misc_cp.h"
#include "vapp_msg_contact_bar.h"
/* Service headers: */
#ifdef __cplusplus
extern "C"
#endif
{
    #include "UcSrvGprot.h" /* srv_uc_info_type_enum */
    #include "mmi_rp_vapp_msg_def.h" /* EVT_ID_VAPP_MSG_ENTRY */
    #include "Custom_phb_config.h" /* mmi_phb_contact_id */
    #include "MMIDataType.h" /* mmi_sim_enum */
}


/* Service headers: */
#ifdef __cplusplus
extern "C"
#endif
{
    #include "UmSrvGprot.h" /* srv_um_get_msg_info_result */
    #include "SmsSrvGprot.h" /* srv_sms_callback_struct */
#ifdef __MMI_PUSH_IN_UM__
    #include "WAPPushSrvGprots.h" /* for srv_wap_push_msg_read_status_enum */
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
    #include "ProvBoxSrvGprot.h" /* for srv_provbox_result_enum */
#endif /* __MMI_PROV_IN_UM__ */
}

typedef struct
{
    MMI_EVT_PARAM_HEADER
    VfxBool isEntry;
} VappMsgEntryStruct;

typedef enum
{
    VAPP_MSG_LAUNCH_NORMAL, 
    VAPP_MSG_LAUNCH_INBOX, 
    VAPP_MSG_LAUNCH_OUTBOX, 
    VAPP_MSG_LAUNCH_SIM1_BOX, 
    VAPP_MSG_LAUNCH_SIM2_BOX, 
    VAPP_MSG_LAUNCH_SIM3_BOX, 
    VAPP_MSG_LAUNCH_SIM4_BOX, 
    VAPP_MSG_LAUNCH_SNS, 
    VAPP_MSG_LAUNCH_TOTAL_MODE
} VappMsgLaunchMode;

typedef void (*intentCallbackFunc) (VfxAppLauncherResultEnum result, void * userData);

typedef struct
{
    VappMsgLaunchMode mode;
    intentCallbackFunc cbFunc;
    void* cbFuncParam;
    VfxU32 cbFuncParamSize;
} VappMsgLaunchStruct;

/*****************************************************************************
 * FUNCTION
 *  vapp_msg_launch
 * DESCRIPTION
 *      Mesage launch function.
 * PARAMETERS
 *  param:          [IN]    The launch function parameter, please refer to 
 *                          VappMsgLaunchStruct.
 *  param_size:     [IN]    The size of parameter.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern "C" MMI_ID vapp_msg_launch(void * param, U32 param_size);

/*****************************************************************************
 * FUNCTION
 *  vapp_msg_launch_with_callback
 * DESCRIPTION
 *      Mesage launch function with launch callback.If there are no callback, please use vapp_msg_launch
 * PARAMETERS
 *  param:          [IN]    The launch function parameter, please refer to 
 *                          VappMsgLaunchStruct.
 *  param_size:     [IN]    The size of parameter.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern "C" MMI_ID vapp_msg_launch_with_callback(void * param, U32 param_size);

/*****************************************************************************
 * FUNCTION
 *  vapp_msg_setting_fw_launch
 * DESCRIPTION
 *      This interface only use for setting framework for specified usage. It
 *      will push the message setting page into setting framework's main 
 *      screen.
 * PARAMETERS
 *  mainScr:            [IN]    The parent main screen pointer
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern "C" void vapp_msg_setting_fw_launch(VfxMainScr *mainScr);

/***************************************************************************** 
 * FUNCTION
 *  vapp_msg_launch_inbox
 * DESCRIPTION
 *      This interface only prvider for MRE to launch inbox.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern "C" MMI_ID vapp_msg_launch_inbox(); 
 
typedef void (*subMsgCareHomeKeyCbFunc) (VfxBool& result, void *user_data);

class VappMsgApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappMsgApp);

// Override
public:

	VappMsgApp();
    virtual void onRun(void* args, VfxU32 argSize);
	
    VfxBool setSubMsgCareHomeKeyCb(subMsgCareHomeKeyCbFunc cbFunc, void *user_data); 
    VfxBool releaseSubMsgCareHomeKeyCb(subMsgCareHomeKeyCbFunc cbFunc);
    VfxBool subMsgFreeHomeKey();
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

protected:
    virtual void onInit();
    virtual void onDeinit();
    using VfxApp::onProcessClose;
private:
    static mmi_ret onMsgSrvEvtCb(mmi_event_struct *param);
#if (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__))    
    static mmi_ret onSimDetected(mmi_event_struct * param);
#endif

private:
    subMsgCareHomeKeyCbFunc m_subMsgCb;
    VfxBool                 m_isCloseApp;
    void*                   m_userData; 
};

/*****************************************************************************
 * class VappMsgDialogPage
 *****************************************************************************/
class VappMsgPhbDialogPage : public VfxPage, public IVappMsgDialogListContentProvider
{
    VFX_DECLARE_CLASS(VappMsgPhbDialogPage);

    // Constructor / Destructor
#if defined(__MMI_MAINLCD_320X480__) /* HVGA */
    #define VAPP_MSG_PHB_DIALOG_CB_BG_HEIGHT            (52)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_FONT_SIZE       (20)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (198)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (230)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_COLOR           (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NAME)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_FONT_SIZE     (14)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (198)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (230)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_COLOR         (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NUMBER)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_WIDTH            (66)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_HEIGHT           (40)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_WIDTH            (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_HEIGHT           (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_MARGIN           (8)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT          (8)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_RIGHT         (8)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP            (6)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_DOWN          (6)
#elif defined(__MMI_MAINLCD_480X800__) /* WVGA */
    #define VAPP_MSG_PHB_DIALOG_CB_BG_HEIGHT            (86)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_FONT_SIZE       (36)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (274)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (333)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_COLOR           (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NAME)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_FONT_SIZE     (21)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (274)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (333)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_COLOR         (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NUMBER)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_WIDTH            (105)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_HEIGHT           (70)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_WIDTH            (45)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_HEIGHT           (45)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_MARGIN           (14)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT          (14)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_RIGHT         (14)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP            (8)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_DOWN          (8)
#elif defined(__MMI_MAINLCD_240X320__) /* QVGA */
    #define VAPP_MSG_PHB_DIALOG_CB_BG_HEIGHT            (45)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_FONT_SIZE       (18)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (142)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (171)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_COLOR           (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NAME)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_FONT_SIZE     (13)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (142)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (171)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_COLOR         (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NUMBER)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_WIDTH            (54)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_HEIGHT           (38)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_WIDTH            (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_HEIGHT           (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_MARGIN           (5)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT          (5)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_RIGHT         (5)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP            (4)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_DOWN          (3)
#elif defined(__MMI_MAINLCD_240X400__) /* WQVGA */
    #define VAPP_MSG_PHB_DIALOG_CB_BG_HEIGHT            (45)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_FONT_SIZE       (18)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (142)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (171)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_COLOR           (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NAME)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_FONT_SIZE     (13)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (142)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (171)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_COLOR         (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NUMBER)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_WIDTH            (54)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_HEIGHT           (38)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_WIDTH            (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_HEIGHT           (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_MARGIN           (5)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT          (5)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_RIGHT         (5)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP            (4)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_DOWN          (3)
#else
    #define VAPP_MSG_PHB_DIALOG_CB_BG_HEIGHT            (52)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_FONT_SIZE       (20)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (198)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH           (230)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_COLOR           (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NAME)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_FONT_SIZE     (14)
#if (MMI_MAX_SIM_NUM >= 2)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (198)
#else /* MMI_MAX_SIM_NUM >= 2 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH         (230)
#endif /* MMI_MAX_SIM_NUM == 1 */
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_COLOR         (CLR_ID_VAPP_MSG_PHB_DIALOG_CB_NUMBER)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_WIDTH            (66)
    #define VAPP_MSG_PHB_DIALOG_CB_BTN_HEIGHT           (40)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_WIDTH            (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_HEIGHT           (24)
    #define VAPP_MSG_PHB_DIALOG_CB_SIM_MARGIN           (8)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT          (8)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_RIGHT         (8)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP            (6)
    #define VAPP_MSG_PHB_DIALOG_CB_MARGIN_DOWN          (6)
#endif /* __MMI_MAINLCD_?X?__ */
    #define VAPP_MSG_PHB_DIALOG_CB_NAME_MARGIN_RIGHT    (GDI_LCD_WIDTH - VAPP_MSG_PHB_DIALOG_CB_NAME_WIDTH - VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT)
    #define VAPP_MSG_PHB_DIALOG_CB_NUMBER_MARGIN_RIGHT  (GDI_LCD_WIDTH - VAPP_MSG_PHB_DIALOG_CB_NUMBER_WIDTH - VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT)

    enum
    {
        VAPP_MSG_PHB_DIALOG_TB_SWITCH_NUMBER = 1, 
        VAPP_MSG_PHB_DIALOG_TB_SWITCH_SIM, 
        VAPP_MSG_PHB_DIALOG_TB_SWITCH_TOTAL
    };
public:
    // Default constructor
    VappMsgPhbDialogPage(mmi_phb_contact_id id = 0);   

// Overridable
protected:
    virtual void onInit();
    virtual void onUpdate();
    virtual void onEntered();
    virtual mmi_ret onProc(mmi_event_struct *evt);

public:
    // for IVAppMessageDialogListContentProvider
    virtual VfxBool getItemInfo(VfxU32 index, VfxU32 &msgId, srv_um_msg_enum &msgType);
    virtual VfxU32 getCount();
    virtual VfxBool getMarkStatus(VfxU32 index);
    virtual VfxBool getCellIsDisabled(VfxU32 index);
    virtual VfxBool getLoadingStatus();

private:
    void showLoading();
    void stopLoading();
    void relayout();
    VfxBool getAllMsgRead();
    void setAllMsgRead();
    void setAllMsgReadInt();
    VfxBool setMsgRead(VfxU32 msgId,srv_um_msg_enum msgType);
    static void setSmsReadCb(srv_sms_callback_struct *cbPara);
#ifdef __MMI_PUSH_IN_UM__
    static void setPushReadCb(srv_wap_push_msg_read_status_enum result, void *user_data);
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
    static void setProvReadCb(srv_provbox_result_enum result, void *cbPara);
#endif /* __MMI_PROV_IN_UM__ */
    srv_um_sim_enum switchSimToUmSimEnum(mmi_sim_enum sim) const;
    VfxU32 switchSimToImgId(mmi_sim_enum sim) const;
    void onListUpdate(VfxObject *obj);
    void onMsOpResult(VfxObject *obj, VfxU32 success, VfxU32 fail, VfxS32 error);
    void onToolbarClick(VfxObject *obj, VfxId id);
    void onNumberSelectorClicked(VfxObject *obj, VfxId id);
#if (MMI_MAX_SIM_NUM >= 2)
    void onSimSelectorClicked(VfxObject *obj, VfxId id);
#endif /* MMI_MAX_SIM_NUM >= 2 */
    void onClearBtnClicked(VfxObject *obj, VfxId id);
    void onClearAllClicked(VfxObject *obj, VfxId id);
    void onMsActionCancelled(VfxObject *obj, VfxFloat process);
    void onMsProgressTimeout(VfxTimer *timer);

// implementation
private:
    mmi_phb_contact_id m_id;
    VfxU32 m_subId;
    srv_um_thread_id_struct m_thrdId;
    VfxBool m_isNeedReset;
    VfxBool m_isBlockUpdate;
    srv_um_box_identity_struct m_boxId;
    srv_um_list_filter_struct m_listFilter;
    VappMessageList *m_list;
    VappMsgDialogListCp *m_listMenu;
    VcpActivityIndicator *m_loading;
    VcpToolBar *m_toolbar;
    VfxBool m_isStartSetAllMsgRead;
    VfxBool m_isWaitSetAllRead;
    VfxU32 m_setAllReadIndex;
    VfxTextFrame *m_name;
    VfxTextFrame *m_number;
    VcpButton *m_clearBtn;
    srv_um_mark_several_op_action_enum m_msAction;
    VcpIndicatorPopup *m_msProcessing;
    VfxTimer *m_msProcessTimer;
    mmi_sim_enum m_sim;
    VfxFrame *m_simImg;
};

enum VappMsgStorageEnum
{
	VAPP_MSG_STORAGE_NONE,
	VAPP_MSG_STORAGE_PHONE,
	VAPP_MSG_STORAGE_MEMORY_CARD,
	VAPP_MSG_STORAGE_PHONE_AND_MEMORY,
	VAPP_MSG_STORAGE_SIM,
	VAPP_MSG_STORAGE_ALL,
	VAPP_MSG_STORAGE_TOTAL
};

struct VappMsgCopyFilter
{
	srv_um_msg_box_enum msg_box;
	srv_um_msg_enum msg_type;
	VappMsgStorageEnum msg_storage;
};


/*****************************************************************************
 * class VappMsgFolderPage
 *****************************************************************************/
enum VappMsgFolderTypeEnum
{
    VAPP_MSG_FOLDER_TYPE_NORMAL, 
    VAPP_MSG_FOLDER_TYPE_CONVERSATION, 
    VAPP_MSG_FOLDER_TYPE_LITE,      /* only support sms only */
    VAPP_MSG_FOLDER_TYPE_END
};
enum VappMsgFolderModeEnum
{
    VAPP_MSG_FOLDER_MODE_NORMAL, 
    VAPP_MSG_FOLDER_MODE_MS,        /* mark several */
    VAPP_MSG_FOLDER_MODE_END
};

class VappMsgFolderPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMsgFolderPage);

    enum VappMsgToolbarEnum
    {
        VAPP_MSG_FOLDER_TOOL_BAR_NEW_MSG =       0x00000001, 
        VAPP_MSG_FOLDER_TOOL_BAR_ADD_TEMPLATE =  0x00000002, 
        VAPP_MSG_FOLDER_TOOL_BAR_COPY_TO_INBOX = 0x00000004, 
        VAPP_MSG_FOLDER_TOOL_BAR_ARCHIVE =       0x00000008, 
        VAPP_MSG_FOLDER_TOOL_BAR_COPY =          0x00000010, 
        VAPP_MSG_FOLDER_TOOL_BAR_SORT =          0x00000020, 
        VAPP_MSG_FOLDER_TOOL_BAR_DELETE =        0x00000040, 
        VAPP_MSG_FOLDER_TOOL_BAR_SIM_MSG =       0x00000080, 
        VAPP_MSG_FOLDER_TOOL_BAR_SETTING =       0x00000100, 

        VAPP_MSG_FOLDER_TOOL_BAR_MS_SELECT_ALL = 0x00010000, 
        VAPP_MSG_FOLDER_TOOL_BAR_MS_DELETE =     0x00020000, 
        VAPP_MSG_FOLDER_TOOL_BAR_MS_COPY =       0x00040000, 
        VAPP_MSG_FOLDER_TOOL_BAR_MS_CANCEL =     0x00080000, 
        VAPP_MSG_FOLDER_TOOL_BAR_END =           0x00100000
    };
    enum
    {
        VAPP_MSG_FOLDER_COPY_NONE, 
        VAPP_MSG_FOLDER_COPY_TO_ARCHIVE, 
        VAPP_MSG_FOLDER_COPY_SMS_TO_SIM1, 
        VAPP_MSG_FOLDER_COPY_SMS_TO_SIM2, 
        VAPP_MSG_FOLDER_COPY_SMS_TO_SIM3, 
        VAPP_MSG_FOLDER_COPY_SMS_TO_SIM4, 
        VAPP_MSG_FOLDER_COPY_SMS_TO_SIM_SELECT, 
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        VAPP_MSG_FOLDER_COPY_SMS_TO_PHONE,
        VAPP_MSG_FOLDER_COPY_SMS_TO_MEMORY_CARD,
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
        VAPP_MSG_FOLDER_COPY_MMS_TO_PHONE, 
        VAPP_MSG_FOLDER_COPY_MMS_TO_MEMORY_CARD, 
        VAPP_MSG_FOLDER_COPY_CANCEL, 
        VAPP_MSG_FOLDER_COPY_END
    };
    enum
    {
        VAPP_MSG_FOLDER_SORT_BY_NONE, 
        VAPP_MSG_FOLDER_SORT_BY_RECIPIENT, 
        VAPP_MSG_FOLDER_SORT_BY_MSG_TYPE, 
        VAPP_MSG_FOLDER_SORT_BY_READ_STATUS, 
        VAPP_MSG_FOLDER_SORT_BY_TIME, 
        VAPP_MSG_FOLDER_SORT_BY_CANCEL, 
        VAPP_MSG_FOLDER_SORT_BY_END
    };
    enum
    {
        VAPP_MSG_FOLDER_SIM_NONE, 
        VAPP_MSG_FOLDER_SIM_1, 
        VAPP_MSG_FOLDER_SIM_2, 
        VAPP_MSG_FOLDER_SIM_3, 
        VAPP_MSG_FOLDER_SIM_4, 
        VAPP_MSG_FOLDER_SIM_CANCEL, 
        VAPP_MSG_FOLDER_SIM_END, 
    };
    enum
    {
        VAPP_MSG_FOLDER_LP_TYPE_NONE, 
        VAPP_MSG_FOLDER_LP_TYPE_DELETE, 
        VAPP_MSG_FOLDER_LP_TYPE_CALL, 
        VAPP_MSG_FOLDER_LP_TYPE_FORWARD, 
        VAPP_MSG_FOLDER_LP_TYPE_RESEND, 
        VAPP_MSG_FOLDER_LP_TYPE_EDIT, 
        VAPP_MSG_FOLDER_LP_TYPE_VIEW_WEBSITE, 
        VAPP_MSG_FOLDER_LP_TYPE_INSTALL, 
        VAPP_MSG_FOLDER_LP_TYPE_USE, 
        VAPP_MSG_FOLDER_LP_TYPE_END
    };
// Constructor/Destroctor
public:
    VappMsgFolderPage(
                VfxU32 msgType = SRV_UM_MSG_ALL, 
                VfxU32 boxType = SRV_UM_MSG_BOX_INBOX, 
                VfxU32 simType = SRV_UM_SIM_ALL, 
                VappMsgFolderTypeEnum style = VAPP_MSG_FOLDER_TYPE_NORMAL, 
                VappMsgFolderModeEnum mode = VAPP_MSG_FOLDER_MODE_NORMAL, 
                VfxBool isNeedTitle = VFX_TRUE);

// Property
    void setMode(VappMsgFolderModeEnum newMode);
// Method
// Event

    // Override IVcpListMenuContentProvider
    virtual void setMenu(VcpListMenu *);
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
    virtual VfxBool getItemIsDisabled(
        VfxU32 index
        ) const;
    virtual VfxBool getMenuEmptyText(
        VfxWString & text,
        VcpListMenuTextColorEnum & color);
        


// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onExited();
    virtual void onEntered();
    virtual void onBack();
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Implementation
private:
    void showLoading();
    void stopLoading();
    VfxU32 getUnreadCount();
    void setTitle(VfxU32 number, VfxU32 unreadNumber, VfxBool isValid);
    VfxBool getReadStatus(VfxU32 msgId, srv_um_msg_enum msgType);
    void modeChange();
    void createToolbar(VappMsgFolderTypeEnum type, VappMsgFolderModeEnum mode);
    void updateToolbar(VappMsgFolderTypeEnum type, VappMsgFolderModeEnum mode);
    void addToolBarItem(VappMsgToolbarEnum id);
    void enableToolbar(VappMsgFolderTypeEnum type, VappMsgFolderModeEnum mode, VfxBool enable);
    VfxU32 getMsgTypeIcon(VfxU32 msgType, VfxU32 msgStatus);
    void createContextItem(
        VcpMenuPopup *cntx, 
        srv_um_msg_box_enum boxType, 
        srv_um_msg_enum msgType, 
        VfxU32 msgId, 
        VfxU32 index);
    VappMsgCntxOptItemCp *createContextSingleItem(
        VcpMenuPopup * parentCntx, 
        VfxId itemId, 
        VfxWString itemText, 
        VfxU32 msg_id, 
        srv_um_msg_enum msgType, 
        VfxU32 index);
    VappMsgCntxOptItemCp *createContextSingleItem(
        VcpMenuPopup * parentCntx, 
        VfxId itemId, 
        VfxWString itemText, 
        VfxU32 thrdIdType, 
        VfxU64 thrdIdValue, 
        VfxU32 index);
	
#ifdef __MMI_UNIFIED_COMPOSER__
    srv_uc_info_type_enum transferUcType(srv_um_msg_enum msgType);
#endif
    VfxPage *createViewerPage(VfxU32 msgId, VfxU32 msgType);
    static void *allocMem(VfxU32 size, void *userData);
    static void freeMem(void *ptr);
    srv_um_msg_enum getMsMarkAllMsgType();
    VappMessageListCopyStorageEnum getTransMsMsgListCopyType();
    VfxWString transfer2PhbName(srv_um_msg_info_struct *msgInfo);
    VfxWString transferSingle2PhbName(VfxWChar *addr);
    void updateMsToolbar();
    void onMsgListUpdated(VfxObject *obj);
    void onSingleMsgUpdated(VfxObject *obj, VfxU32 index);
    void onMsOpResult(VfxObject *obj, VfxU32 success, VfxU32 fail, VfxS32 error);
    void onListItemTapped(VcpListMenu *listMenu, VfxU32 index);
    void onListItemSelected(VcpListMenu *listMenu, VfxU32 index, VcpListMenuItemStateEnum state);
    void onListItemLongPressed(VcpListMenu *listMenu, VfxU32 index);
    void onContextMenuSelected(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
    void onLpActionClicked(VfxObject *obj, VfxId id);
    void onToolbarClick(VfxObject *obj, VfxId id);
    void onMsActionClicked(VfxObject *obj, VfxId id);
    void onMsOpCancelled(VfxObject *obj, VfxFloat progress);
    void onCopyCmdClicked(VfxObject *obj, VfxId id);
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__    
    void onSortCmdClicked(VfxObject *obj, VfxId id);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

#if (MMI_MAX_SIM_NUM >= 2)
    void onSimCmdClicked(VfxObject *obj, VfxId id);
#endif /* MMI_MAX_SIM_NUM >= 2 */
    void onMsProgressTimeout(VfxTimer *timer);
    void onPushViewWebsiteCb();
#ifdef __MMI_PROV_IN_UM__
    static MMI_BOOL onProvInstallCb(void *userData);
#endif /* __MMI_PROV_IN_UM__ */
    static mmi_ret onPhbSrvEvt(mmi_event_struct *param);
#ifdef __MMI_USB_SUPPORT__
    static mmi_ret onMsModeEvt(mmi_event_struct *param);
#endif /* __MMI_USB_SUPPORT__ */
    void onRestrictConfirmClicked(VfxObject *obj, VfxId id);
    VfxU16 tsfrSimCard2StrId(mmi_sim_enum sim);
    mmi_sim_enum tsfrUmSim2Sim(srv_um_sim_enum umSim);
    void toolbarNewMsg();
    void toolbarAddTemplate();
    void toolbarCopy2Inbox();
    void toolbarDelete();
#if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)    
    void toolbarArchive();
#endif
    void toolbarSimMsg();
    void toolbarSetting();
    void toolbarCopy();
#if defined (__UNIFIED_MESSAGE_SORT_MESSAGE_LIST__)    
    void toolbarSort();
#endif
    void toolbarMsSelectAll();
    void toolbarMsDelete();
    void toolbarMsCopy();
    void toolbarMsCancel();
    void longpressDelete(VappMsgCntxOptItemCp *item);
    void longpressCall(VappMsgCntxOptItemCp *item);
    void longpressForward(VappMsgCntxOptItemCp *item);
    void longpressResend(VappMsgCntxOptItemCp *item);
    void longpressEdit(VappMsgCntxOptItemCp *item);
    void longpressViewWebsite(VappMsgCntxOptItemCp *item);
    void longpressInstall(VappMsgCntxOptItemCp *item);
    void longpressUse(VappMsgCntxOptItemCp *item);
    //void setPreferredSim(srv_um_msg_enum msgType, U32 msgId, U16 msgIndex);

// Member
private:
    VcpTitleBar *m_title;
    VfxBool m_isTitleValid;
    VfxBool m_isNeedTitle;
    VappMessageList *m_list;
    VcpListMenu *m_listMenu;
    VcpToolBar *m_toolbar;
    srv_um_box_identity_struct m_boxId;
    srv_um_list_filter_struct m_listFilter;
    VcpActivityIndicator *m_loading;
    VappMsgFolderTypeEnum m_style;
    VfxU32 m_enterIndex;
    VfxBool m_isStartEnter;
    VfxBool m_isSetNewMode;
    VappMsgFolderModeEnum m_mode;
    srv_um_mark_several_op_action_enum m_msOpAction;
    VcpIndicatorPopup *m_msProcessLoading;
    VfxTimer* m_msProcessTimer;
    VfxBool m_isBlockUpdate;
    VfxBool m_isNeedReset;
    VfxBool m_isNeedUpdate;
    VcpMenuPopup *m_contextMenu;
    VcpConfirmPopup *m_confirmPopup;
    void *m_actionPtr;
    VfxBool m_isEntered;
    VfxBool m_isInMsgApp;
    VfxBool m_isExited;
    VfxBool m_isNotification;
    VappMsgCopyFilter m_msgCopyFilter;
};
#endif /* __VAPP_MSG_GPROT_H__ */
