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
 *  vapp_clog_detail.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vfx_input_event.h"
#include "vfx_app_scr.h"

#include "vcp_photo_border_frame.h"
#include "vapp_sim_setting_gprot.h"
#include "mmi_rp_app_usbsrv_def.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMIDataType.h"
#include "GlobalResdef.h"
#include "Unicodexdcl.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_utility_gprot.h"

#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "NwUsabSrvGprot.h"
#include "UcmSrvGprot.h"
#include "CalllogSrvGprot.h"
#include "FileMgrSrvGProt.h"

}
#endif
#include "vapp_clog_config.h"
#include "vapp_clog_ui.h"
#include "vapp_clog_action.h"
#include "vapp_clog_data_provider.h"
#include "mmi_rp_vapp_calllog_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vapp_contact_storage.h"
#include "mmi_rp_vapp_contact_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef struct
{
    VfxId general_btnId;
    VfxResId general_strId;
    VfxResId general_iconId;
    VfxResId child_iconId;
} vapp_clog_btn_cntx_struct;


typedef struct
{
    mmi_sim_enum sim_id;
    VfxId button_id;
    VfxResId icon_id;
} vapp_clog_sim_cntx_struct;


// total COMBO_BUTTON_TOTAL_ITEMS
/*static const vapp_clog_btn_cntx_struct vapp_clog_btn_cntx_s[] = 
{
    {VAPP_CLOG_BTN_CALL_SELECT, STR_GLOBAL_DIAL, IMG_COSMOS_GEMINI_SIM_CALL, IMG_COSMOS_GEMINI_BUTTON_SIM},
    {VAPP_CLOG_BTN_SEND_MSG_SELECT, STR_GLOBAL_MESSAGE, IMG_COSMOS_GEMINI_SIM_MSG, IMG_COSMOS_GEMINI_BUTTON_SIM},
};


static const vapp_clog_sim_cntx_struct vapp_clog_sim_s[2][MMI_SIM_TOTAL] =
{
    {
    #if (MMI_MAX_SIM_NUM >= 1)
        {MMI_SIM1, VAPP_CLOG_BTN_CALL_VOICE_SIM1, IMG_COSMOS_GEMINI_SIM1_CALL},
    #endif
    #if (MMI_MAX_SIM_NUM >= 2)
        {MMI_SIM2, VAPP_CLOG_BTN_CALL_VOICE_SIM2, IMG_COSMOS_GEMINI_SIM2_CALL},
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        {MMI_SIM3, VAPP_CLOG_BTN_CALL_VOICE_SIM3, IMG_COSMOS_GEMINI_SIM3_CALL},
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        {MMI_SIM4, VAPP_CLOG_BTN_CALL_VOICE_SIM4, IMG_COSMOS_GEMINI_SIM4_CALL},
    #endif
    },
    {
    #if (MMI_MAX_SIM_NUM >= 1)
        {MMI_SIM1, VAPP_CLOG_BTN_SEND_MSG, IMG_COSMOS_GEMINI_SIM1_MSG},
    #endif
    #if (MMI_MAX_SIM_NUM >= 2)
        {MMI_SIM2, VAPP_CLOG_BTN_SEND_MSG_SIM2, IMG_COSMOS_GEMINI_SIM2_MSG},
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        {MMI_SIM3, VAPP_CLOG_BTN_SEND_MSG_SIM3, IMG_COSMOS_GEMINI_SIM3_MSG},
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        {MMI_SIM4, VAPP_CLOG_BTN_SEND_MSG_SIM4, IMG_COSMOS_GEMINI_SIM4_MSG},
    #endif
    }
};
*/

/*****************************************************************************
 * Class VappCLogDetail
 *****************************************************************************/ 
VappCLogDetail::VappCLogDetail(const srv_clog_log_struct & log):
    m_form(NULL),
    m_logItem(log),
    m_action(NULL),
    m_clogDataSrv(NULL)
{
    m_perferSIM[COMBO_BUTTON_CALL] = MMI_SIM_NONE;
    m_perferSIM[COMBO_BUTTON_MSG] = MMI_SIM_NONE;
    m_insertSIM = 0;
}


void VappCLogDetail::onInit()
{
    VfxPage::onInit();
    VFX_OBJ_CREATE(m_action, VppCLogAction, this);
    VFX_OBJ_CREATE_EX(m_clogDataSrv, VappCLogDataProvider, this, (VAPP_CLOG_PAGE_BASIC));
    VFX_OBJ_CREATE(m_showTimer, VfxTimer, this);
    
    VfxS32 i;
    VfxU8 sim_id;
    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (srv_sim_ctrl_is_inserted((mmi_sim_enum)sim_id))
            m_insertSIM |= sim_id;
    }
    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_CLOG_DETAILS);
    setTopBar(titleBar);
    creatForm();
    creatToolBar();
    
    regListener();
    m_action->setGroupId(getApp()->getGroupId());
    m_action->setAppScr(getMainScr());
}


void VappCLogDetail::onDeinit()
{
    //VFX_OBJ_CLOSE(m_form);
    deregListener();
    VfxPage::onDeinit();
}


void VappCLogDetail::onEnter(VfxBool isBackward)
{
    if (isBackward == VFX_TRUE) // update Head Image
    {
        ((VappCLogDetailIDCard*)(m_form->getItem(LOG_NAME_NUMBER)))->setText(m_logItem.data.call_log);
        updatePhbToolBar();
    
        creatComboButton(m_callBtn, COMBO_BUTTON_CALL); // prefer SIM maybe happen changed
        creatComboButton(m_msgBtn, COMBO_BUTTON_MSG);
    }
    m_showTimer->setStartDelay(1);
    m_showTimer->m_signalTick.connect(this, &VappCLogDetail::showlistscreen);
    m_showTimer->start();
}


void VappCLogDetail::showlistscreen(VfxTimer *timer)
{
    clearUnreadMissedCount();
}

void VappCLogDetail::onExit(VfxBool isBackward)
{
    m_showTimer->stop();
}


void VappCLogDetail::clearUnreadMissedCount()
{
    if (m_logItem.data.call_log.unread_num > 0 && (getMainScr()->isActive() && isActive()))
    {
        srv_clog_update_log_req_struct req;    
        srv_clog_init_para(SRV_CLOG_PARA_UPDATE_LOG_REQ, &req);

        req.log_data.cate = SRV_CLOG_CATE_CALL;
        req.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
        req.log_data.data.call_log.log_id = m_logItem.data.call_log.log_id;
        req.log_data.data.call_log.unread_num = 0;

        srv_clog_update_log(
            0,
            0,
            &req,
            NULL);
     }
}


void VappCLogDetail::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}


//Todo, refersh timestampe when log udpated
void VappCLogDetail::creatForm()
{
    m_action->setLog(m_logItem); // set log to action obj
    
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    creatLogIDCard();
    m_form->insertSeparator(LOG_NAME_NUMBER);
    
    creatLogType();
    
    VappCLogDetailInfo *info;
    VFX_OBJ_CREATE_EX(info , VappCLogDetailInfo, m_form, (m_logItem.data.call_log));
    m_form->addItem(info, DETAIL_INFO);
    m_form->insertSeparator(DETAIL_INFO);
    
    //creatMultiCallBtn();
    createMultiBtn(COMBO_BUTTON_CALL, THREE_CALL_BTN);
   
#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    createVideoCallBtn();
#endif
	createMultiBtn(COMBO_BUTTON_MSG, SEND_MSG_BTN);
    //createEditBeforeCallBtn();
    createMultiBtn(COMBO_BUTTON_TOTAL_ITEMS, EDIT_BEFORE_CALL_BTN);    
    //createMsgBtn();
   

    updateBtnStatus();
}


void VappCLogDetail::creatLogIDCard()
{
    VappCLogDetailIDCard *logIDCard;
    VFX_OBJ_CREATE(logIDCard, VappCLogDetailIDCard, m_form);
    logIDCard->setText(m_logItem.data.call_log);
    logIDCard->m_photoBorder->m_signalClicked.connect(this, &VappCLogDetail::onPhotoClicked);
    m_form->addItem(logIDCard, LOG_NAME_NUMBER);
}


void VappCLogDetail::onPhotoClicked()
{
    if (srv_phb_check_number_id(m_logItem.data.call_log.phb_id))
        m_action->onButtonClicked(this, VAPP_CLOG_BTN_VIEW_CONTACT);
    else
        m_action->onButtonClicked(this, VAPP_CLOG_BTN_SAVE_TO_CONTACT);
}

void VappCLogDetail::creatLogType()
{
    VappCLogDetailType *logType;
    VFX_OBJ_CREATE_EX(logType, VappCLogDetailType, m_form, 
        (m_logItem.data.call_log.log_type, m_logItem.data.call_log.sim_id));
    m_form->addItem(logType, LOG_TYPE);
    m_form->insertSeparator(LOG_TYPE);
}


/*void VappCLogDetail::creatMultiCallBtn()
{
    VfxU32 CELL_HEIGHT = VCPFRM_STD_UI_CNTRL_HEIGHT + VAPP_CLOG_TOP_GAP;

    VfxFrame *threeCallFrm;
    VFX_OBJ_CREATE(threeCallFrm, VfxFrame, m_form);
    threeCallFrm->setSize(m_form->getSize().width, CELL_HEIGHT);

    VFX_OBJ_CREATE(m_callBtn, VcpComboButton, threeCallFrm);
    creatComboButton(m_callBtn, COMBO_BUTTON_CALL);

    VcpFormItemCustomFrame *threeCall;
    VFX_OBJ_CREATE(threeCall, VcpFormItemCustomFrame, this);
    threeCall->attachCustomFrame(threeCallFrm);

    m_form->addItem(threeCall, THREE_CALL_BTN);
}
*/

#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)	
void VappCLogDetail::createVideoCallBtn()
{
    VfxU32 CELL_HEIGHT = VCPFRM_STD_UI_CNTRL_HEIGHT + VAPP_CLOG_TOP_GAP;

    VfxFrame *videoCallFrm;
    VFX_OBJ_CREATE(videoCallFrm, VfxFrame, m_form);
    videoCallFrm->setSize(m_form->getSize().width, CELL_HEIGHT);

    VFX_OBJ_CREATE(m_callVideoBtn, VcpButton, videoCallFrm);
    m_callVideoBtn->setPos(VAPP_CLOG_LEFT_GAP, VAPP_CLOG_TOP_GAP);
	m_callVideoBtn->setSize(LCD_WIDTH - VAPP_CLOG_LEFT_GAP - VAPP_CLOG_RIGHT_GAP, VCPFRM_STD_UI_CNTRL_HEIGHT);
    //m_callVideoBtn->setText(VFX_WSTR_RES(STR_GLOBAL_DIAL));
    m_callVideoBtn->setText(STR_GLOBAL_DIAL);
    m_callVideoBtn->setImage(VcpStateImage(IMG_ID_VAPP_CLOG_DETAIL_CALL_VIDEO));
    m_callVideoBtn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
    m_callVideoBtn->setId(VAPP_CLOG_BTN_CALL_VIDEO);
    m_callVideoBtn->m_signalClicked.connect(m_action, &VppCLogAction::onButtonClicked);

    VcpFormItemCustomFrame *videoCall;
    VFX_OBJ_CREATE(videoCall, VcpFormItemCustomFrame, this);
    videoCall->attachCustomFrame(videoCallFrm);

    m_form->addItem(videoCall, VIDEO_CALL_BTN);
}
#endif /* __MMI_VIDEO_TELEPHONY__ && __OP01__ */	


/*void VappCLogDetail::createEditBeforeCallBtn()
{
    VfxU32 CELL_HEIGHT = VCPFRM_STD_UI_CNTRL_HEIGHT + VAPP_CLOG_TOP_GAP;

    VfxFrame *editeBeforeCallFrm;
    VFX_OBJ_CREATE(editeBeforeCallFrm, VfxFrame, m_form);
    editeBeforeCallFrm->setSize(m_form->getSize().width, CELL_HEIGHT);

    VFX_OBJ_CREATE(m_editBeforeCallBtn, VcpButton, editeBeforeCallFrm);
    m_editBeforeCallBtn->setPos(VAPP_CLOG_LEFT_GAP, VAPP_CLOG_TOP_GAP);
    m_editBeforeCallBtn->setSize(LCD_WIDTH - VAPP_CLOG_LEFT_GAP - VAPP_CLOG_RIGHT_GAP, VCPFRM_STD_UI_CNTRL_HEIGHT);
    m_editBeforeCallBtn->setText(VFX_WSTR_RES(STR_GLOBAL_EDIT_BEFORE_CALL));
    m_editBeforeCallBtn->setImage(VcpStateImage(IMG_COSMOS_EDIT)); // general call icon
    m_editBeforeCallBtn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
    m_editBeforeCallBtn->setId(VAPP_CLOG_BTN_EDIT_BEFORE_CALL);
    m_editBeforeCallBtn->m_signalClicked.connect(m_action, &VppCLogAction::onButtonClicked);

    VcpFormItemCustomFrame *editeBeforeCall;
    VFX_OBJ_CREATE(editeBeforeCall, VcpFormItemCustomFrame, this);
    editeBeforeCall->attachCustomFrame(editeBeforeCallFrm);

    m_form->addItem(editeBeforeCall, EDIT_BEFORE_CALL_BTN);    
}*/


/*void VappCLogDetail::createMsgBtn()
{
    VfxFrame *msgFrm;
    VFX_OBJ_CREATE(msgFrm, VfxFrame, m_form);
    msgFrm->setSize(m_form->getSize().width, VCPFRM_STD_UI_CNTRL_HEIGHT + VAPP_CLOG_TOP_GAP);
    
    VFX_OBJ_CREATE(m_msgBtn , VcpComboButton, msgFrm);
    creatComboButton(m_msgBtn, COMBO_BUTTON_MSG);
    
    VcpFormItemCustomFrame *msg;
    VFX_OBJ_CREATE(msg, VcpFormItemCustomFrame, this);
    msg->attachCustomFrame(msgFrm);
    
    m_form->addItem(msg, SEND_MSG_BTN);
}
*/
void VappCLogDetail::createMultiBtn(CreateComboTypeEnum type, VfxId id)
{
    VfxFrame *baseFrame;
    VFX_OBJ_CREATE(baseFrame, VfxFrame, m_form);
    baseFrame->setSize(m_form->getSize().width, VCPFRM_STD_UI_CNTRL_HEIGHT + VAPP_CLOG_TOP_GAP);
    if( type == COMBO_BUTTON_CALL )
    {
        VFX_OBJ_CREATE(m_callBtn , VcpComboButton, baseFrame);
        creatComboButton(m_callBtn, type);
    }
    else 
    if( type == COMBO_BUTTON_MSG )
    {
        VFX_OBJ_CREATE(m_msgBtn , VcpComboButton, baseFrame);
        creatComboButton(m_msgBtn, type);
    }
    else
    {

        VFX_OBJ_CREATE(m_editBeforeCallBtn, VcpButton, baseFrame);
        m_editBeforeCallBtn->setPos(VAPP_CLOG_LEFT_GAP, VAPP_CLOG_TOP_GAP);
        m_editBeforeCallBtn->setSize(LCD_WIDTH - VAPP_CLOG_LEFT_GAP - VAPP_CLOG_RIGHT_GAP, VCPFRM_STD_UI_CNTRL_HEIGHT);
        //m_editBeforeCallBtn->setText(VFX_WSTR_RES(STR_GLOBAL_EDIT_BEFORE_CALL));
        m_editBeforeCallBtn->setText(STR_GLOBAL_EDIT_BEFORE_CALL);
        m_editBeforeCallBtn->setImage(VcpStateImage(IMG_COSMOS_EDIT)); // general call icon
        m_editBeforeCallBtn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
        m_editBeforeCallBtn->setId(VAPP_CLOG_BTN_EDIT_BEFORE_CALL);    
        m_editBeforeCallBtn->m_signalClicked.connect(m_action, &VppCLogAction::onButtonClicked);
    }
    VcpFormItemCustomFrame *multi;
    VFX_OBJ_CREATE(multi, VcpFormItemCustomFrame, this);
    multi->attachCustomFrame(baseFrame);
    m_form->addItem(multi, id);
    /*if(type == COMBO_BUTTON_MSG)
    {
        m_form->addItem(multi, SEND_MSG_BTN);
    }
    else if(type == COMBO_BUTTON_CALL )
    {
        m_form->addItem(multi, THREE_CALL_BTN);
    }
    else
    {
        m_form->addItem(multi, EDIT_BEFORE_CALL_BTN)

    }*/
}


void VappCLogDetail::creatComboButton(VcpComboButton *btn, CreateComboTypeEnum type)
{
    btn->setPos(VAPP_CLOG_LEFT_GAP, VAPP_CLOG_TOP_GAP);
    btn->setSize(LCD_WIDTH - VAPP_CLOG_LEFT_GAP - VAPP_CLOG_RIGHT_GAP, VCPFRM_STD_UI_CNTRL_HEIGHT);
    VfxBool call = VFX_TRUE;

    //Todo, need get form PhoneBook
    srv_clog_call_log_struct *log = &(m_logItem.data.call_log);
    srv_phb_number_op_type_enum phb_op_type;
    if (type == COMBO_BUTTON_CALL)
    {
         phb_op_type = SRV_PHB_NUMBER_OP_TYPE_DIAL;
    }
    else// if (type == COMBO_BUTTON_MSG)
    {
        phb_op_type = SRV_PHB_NUMBER_OP_TYPE_MESSAGE;
        call = VFX_FALSE;
    }
    srv_phb_get_preferred_sim((U16 *) log->cid,
        log->phb_id.contact_index,
        phb_op_type,
        &m_perferSIM[type]);

    VfxId button_id;
    VfxWString main_string;
    VfxWString hint_string;
    VfxResId icon_id;
    VfxId child_button_id;
    VfxResId child_icon_id;
    VfxS32 sim_count = srv_sim_ctrl_get_num_of_inserted();
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_CREAT_COMBO_BUTTON, type, sim_count, m_insertSIM, m_perferSIM[0], m_perferSIM[1]);
    
    if (sim_count < 2)
    {
       // btn->setText(VFX_WSTR_RES(vapp_clog_btn_cntx_s[type].general_strId));
        //btn->setText(VFX_WSTR_RES(call ? STR_GLOBAL_DIAL : STR_GLOBAL_MESSAGE));
        btn->setText(call ? STR_GLOBAL_DIAL : STR_GLOBAL_MESSAGE);
       // btn->setImage(VcpStateImage(vapp_clog_btn_cntx_s[type].general_iconId)); // general call icon
        btn->setImage(VcpStateImage(call ? IMG_COSMOS_GEMINI_SIM_CALL : IMG_COSMOS_GEMINI_SIM_MSG));
        btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
        btn->setHasChildBtn(VFX_FALSE);
        btn->setId(getButtonId((mmi_sim_enum)m_insertSIM, type));
    }
    else // sim_count >= 2
    {
        if (MMI_SIM_NONE == m_perferSIM[type])
        {
            /*button_id = vapp_clog_btn_cntx_s[type].general_btnId;
            icon_id = vapp_clog_btn_cntx_s[type].general_iconId; // general call icon
            child_button_id = vapp_clog_btn_cntx_s[type].general_btnId;
            child_icon_id = vapp_clog_btn_cntx_s[type].child_iconId; // multi call select icon
            */
            button_id = call? VAPP_CLOG_BTN_CALL_SELECT: VAPP_CLOG_BTN_SEND_MSG_SELECT;
            btn->setImage(VcpStateImage(call ? IMG_COSMOS_GEMINI_SIM_CALL : IMG_COSMOS_GEMINI_SIM_MSG));
            icon_id = call ? IMG_COSMOS_GEMINI_SIM_CALL : IMG_COSMOS_GEMINI_SIM_MSG;
            child_button_id = button_id;
            child_icon_id = IMG_COSMOS_GEMINI_BUTTON_SIM;
        }
        else // has prefer SIM
        {
            button_id = getButtonId(m_perferSIM[type], type);
            hint_string = vapp_sim_settings_get_sim_name(m_perferSIM[type]);
            // get sim name form SIM setting app

            icon_id = call ? ContactSim::getCallIconId(m_perferSIM[type]):icon_id = ContactSim::getMsgIconId(m_perferSIM[type]) ;
    

            if (sim_count == 2)
            {
                mmi_sim_enum another_sim = (mmi_sim_enum)(m_insertSIM & (~m_perferSIM[type]));
                child_button_id = getButtonId(another_sim, type);
                child_icon_id = call ? ContactSim::getCallIconId(another_sim) : ContactSim::getMsgIconId(another_sim);
            }
            else if (sim_count > 2)
            {
                child_button_id =  call? VAPP_CLOG_BTN_CALL_SELECT: VAPP_CLOG_BTN_SEND_MSG_SELECT;
                child_icon_id = IMG_COSMOS_GEMINI_BUTTON_SIM; 
            }
        }
        
        //main_string = VFX_WSTR_RES(call ? STR_GLOBAL_DIAL : STR_GLOBAL_MESSAGE);
        main_string = call ? STR_GLOBAL_DIAL : STR_GLOBAL_MESSAGE;
        //btn->setStyle(VCP_BUTTON_STYLE_SIM1);
        btn->setId(button_id);
        btn->setText(main_string);
        if (!hint_string.isNull())
            btn->setHintText(hint_string);
        btn->setImage(VcpStateImage(icon_id));
        btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
        btn->setHasChildBtn(VFX_TRUE, child_button_id); // need set child button id
        btn->setChildButtonIcon(VcpStateImage(child_icon_id));
    }
    
    updateComboButtonStatus(btn, type, sim_count);
/*   
    if (sim_count == 0)
    {
        btn->setIsDisabled(VFX_TRUE);
    }
    else if (sim_count == 1)
    {
        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
            btn->setIsDisabled(VFX_TRUE);
    }
    else
    {
        if (m_perferSIM[type] != MMI_SIM_NONE && (srv_mode_switch_get_network_mode(m_perferSIM[type]) == SRV_MODE_SWITCH_OFF))
            btn->setIsOnlyMainBtnDisabled(VFX_TRUE);
    }
    
     // in condition (only have 2 sim inserted, and exist preferred SIM, and the another sim is closed, then child btn should set disable
    if (sim_count == 2 && m_perferSIM[type] != MMI_SIM_NONE && 
        srv_mode_switch_get_network_mode((mmi_sim_enum)(m_insertSIM & (~m_perferSIM[type]))) == SRV_MODE_SWITCH_OFF)
    {
        btn->setChildIsDisabled(VFX_TRUE);
    }
*/   
    btn->m_signalClicked.connect(this, &VappCLogDetail::onButtonClicked);
    btn->m_signalChildBtnClicked.connect(this, &VappCLogDetail::onChildButtonClicked);
}


void VappCLogDetail::updateComboButtonStatus(VcpComboButton *btn, CreateComboTypeEnum type, VfxS32 sim_count)
{
    if (sim_count == 0)
    {
        btn->setIsDisabled(VFX_TRUE);
    }
    else if (sim_count == 1)
    {
        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
            btn->setIsDisabled(VFX_TRUE);
        else
            btn->setIsDisabled(VFX_FALSE);
    }
    else
    {
        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
        {
            btn->setIsDisabled(VFX_TRUE);
            btn->setChildIsDisabled(VFX_TRUE);

            return;
        }
        else
        {
            btn->setIsDisabled(VFX_FALSE);
            btn->setChildIsDisabled(VFX_FALSE);
        }
        
        if (m_perferSIM[type] != MMI_SIM_NONE && (srv_mode_switch_get_network_mode(m_perferSIM[type]) == SRV_MODE_SWITCH_OFF))
        {
            btn->setIsOnlyMainBtnDisabled(VFX_TRUE);
        }
        else
        {
            btn->setIsOnlyMainBtnDisabled(VFX_FALSE);
        }
        
        if (m_perferSIM[type] != MMI_SIM_NONE && 
            srv_mode_switch_get_network_mode((mmi_sim_enum)(m_insertSIM & (~m_perferSIM[type]))) == SRV_MODE_SWITCH_OFF)
        {
            btn->setChildIsDisabled(VFX_TRUE);
        }
        else
        {
            btn->setChildIsDisabled(VFX_FALSE);
        }
    }
}


VfxId VappCLogDetail::getButtonId(mmi_sim_enum sim_id, CreateComboTypeEnum type)
{

       VfxBool call;
       if(type == COMBO_BUTTON_CALL )
        {
            call = VFX_TRUE;
        }
        else
        {
            call = VFX_FALSE;
        }
        switch(sim_id)
        {
         #if (MMI_MAX_SIM_NUM >= 1)
            case MMI_SIM1:
                return call ? VAPP_CLOG_BTN_CALL_VOICE_SIM1: VAPP_CLOG_BTN_SEND_MSG;
        #endif
        #if (MMI_MAX_SIM_NUM >= 2)
            case MMI_SIM2:
                return call ? VAPP_CLOG_BTN_CALL_VOICE_SIM2: VAPP_CLOG_BTN_SEND_MSG_SIM2;
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
            case MMI_SIM3:
                return call ? VAPP_CLOG_BTN_CALL_VOICE_SIM3: VAPP_CLOG_BTN_SEND_MSG_SIM3;
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            case MMI_SIM4:     
                return call ? VAPP_CLOG_BTN_CALL_VOICE_SIM4 : VAPP_CLOG_BTN_SEND_MSG_SIM4;
        #endif
            default:
                    break;
        }
    return VAPP_CLOG_BTN_END_OF_ENUM;   
}


/*VfxResId VappCLogDetail::getButtonIconId(mmi_sim_enum sim_id, CreateComboTypeEnum type)
{
    VfxS32 i;
    for (i = 0; i < (sizeof(vapp_clog_sim_s[type]) / sizeof(vapp_clog_sim_cntx_struct)); i++)
    {
        if (sim_id == vapp_clog_sim_s[type][i].sim_id)
            return vapp_clog_sim_s[type][i].icon_id;
    }
    return IMG_COSMOS_SIM1;
}*/




void VappCLogDetail::onButtonClicked(VfxObject* sender, VfxId btnID)
{
    onChildButtonClicked(NULL, btnID);
}


void VappCLogDetail::onChildButtonClicked(VcpButton* sender, VfxId btnID)
{
    CreateComboTypeEnum type ;
    VfxBool call = VFX_TRUE;
    if (btnID == VAPP_CLOG_BTN_SEND_MSG_SELECT)
    {
        type = COMBO_BUTTON_MSG;
        call = VFX_FALSE;
    }
    else if (btnID == VAPP_CLOG_BTN_CALL_SELECT)
    {
        type = COMBO_BUTTON_CALL;
    }
    else
    {
        m_action->onButtonClicked(NULL, btnID);
        return;
    }

    VcpMenuPopup *cntxMenu;
    VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
    //cntxMenu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOG_SELECT_SIM));
    cntxMenu->setTitle(STR_ID_VAPP_CLOG_SELECT_SIM);
    //show other SIM (exclude prefer SIM)
    VfxS32 i;
    VfxU8 sim;
    VfxU8 other_sim = m_insertSIM & (~m_perferSIM[type]);
    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        if (other_sim & sim)
        {
            VfxId btn_id = getButtonId((mmi_sim_enum)sim, type);
            //VfxWString main_str = VFX_WSTR_RES(vapp_clog_btn_cntx_s[type].general_strId);
            VfxWString sim_name = vapp_sim_settings_get_sim_name((mmi_sim_enum)sim);
            VfxWString main_str = call ? VFX_WSTR_RES(VAPP_PHB_STR_CALL) : VFX_WSTR_RES(VAPP_PHB_STR_MESSAGE);
            //VfxResId icon_id = getButtonIconId((mmi_sim_enum)sim, type);

             VfxResId   icon_id = call ? ContactSim::getCallIconId((mmi_sim_enum)sim): ContactSim::getMsgIconId((mmi_sim_enum)sim);


            cntxMenu->addItem(btn_id, main_str, VfxImageSrc(icon_id), VCP_MENU_POPUP_ITEM_TYPE_2);
            ((VcpMenuPopupItemType2 *)cntxMenu->getItemById(btn_id))->setHintText(sim_name);
            if (srv_mode_switch_get_network_mode((mmi_sim_enum)sim) == SRV_MODE_SWITCH_OFF)
                cntxMenu->getItemById(btn_id)->setIsDisabled(VFX_TRUE); // how to setdisable
        }
    }
    cntxMenu->m_signalMenuCallback.connect(this, &VappCLogDetail::onCntxMenuClick);
    cntxMenu->show(VFX_TRUE);
}

void VappCLogDetail::onCntxMenuClick(
        VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
    if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        m_action->setLog(m_logItem);
        m_action->onButtonClicked((VfxObject *)menu, item->getId());
    }
}



void VappCLogDetail::creatToolBar()
{
    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);    
	setBottomBar(m_toolBar);    
    updatePhbToolBar();
    //m_toolBar->addItem(VAPP_CLOG_BTN_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->addItem(VAPP_CLOG_BTN_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	m_toolBar->m_signalButtonTap.connect(m_action, &VppCLogAction::onButtonClicked);
}


void VappCLogDetail::updatePhbToolBar() // save or view contact
{
    VcpToolBar * m_toolBar = (VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    if (m_toolBar == NULL)
        return;
    m_toolBar->removeItem(VAPP_CLOG_BTN_VIEW_CONTACT);
    m_toolBar->removeItem(VAPP_CLOG_BTN_SAVE_TO_CONTACT);
    if (srv_phb_check_number_id(m_logItem.data.call_log.phb_id))
    {
        m_toolBar->addItem(VAPP_CLOG_BTN_VIEW_CONTACT, (VfxResId)STR_ID_VAPP_CLOG_VIEW_CONTACT, VCP_IMG_TOOL_BAR_COMMON_ITEM_PREVIEW, VAPP_CLOG_BTN_DELETE);
    }
    else
    {
        m_toolBar->addItem(VAPP_CLOG_BTN_SAVE_TO_CONTACT, (VfxResId)STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE, VAPP_CLOG_BTN_DELETE);
    }
}


void VappCLogDetail::regListener()
{
    m_clogDataSrv->m_signalClogUpdated.connect(this, &VappCLogDetail::onUpdateForm);
}


void VappCLogDetail::deregListener()
{
    m_clogDataSrv->m_signalClogUpdated.disconnect(this, &VappCLogDetail::onUpdateForm);
}


/*mmi_ret VappCLogDetail::listener(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}
*/

void VappCLogDetail::updateBtnStatus()
{   
    if (srv_sim_ctrl_get_num_of_inserted() == 0 || srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
        m_editBeforeCallBtn->setIsDisabled(VFX_TRUE);

#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    if (srv_sim_ctrl_is_inserted(MMI_SIM1))
    {
        m_callVideoBtn->setIsDisabled(VFX_FALSE);
    }
    else
    {  
        m_callVideoBtn->setIsDisabled(VFX_TRUE);
    }
#endif  
}

void VappCLogDetail::onUpdateForm(void *evt)
{
    mmi_event_struct *event = (mmi_event_struct *)evt;
    VfxS32 get_ret;
    switch(event->evt_id)
    {
        // Todo: need handle Same Contact page
        case EVT_ID_SRV_CLOG_ADD_LOG:
        {
            srv_clog_evt_add_log_struct *add_evt = (srv_clog_evt_add_log_struct *) evt;
            if (add_evt->old_idf.log_id == m_logItem.data.call_log.log_id)
            {
                get_ret = m_clogDataSrv->getClogByID(add_evt->new_idf.log_id, m_logItem);
                if (SRV_CLOG_RET_OK != get_ret)
                    return;
                m_action->setLog(m_logItem);
                ((VappCLogDetailInfo *)(m_form->getItem(DETAIL_INFO)))->setClog(m_logItem.data.call_log);
                ((VappCLogDetailIDCard*)(m_form->getItem(LOG_NAME_NUMBER)))->setText(m_logItem.data.call_log);
                updatePhbToolBar();
                // Todo udpate
                clearUnreadMissedCount();
            }
            
            break;
    	}
        case EVT_ID_SRV_CLOG_DEL_LOG:
        {
            srv_clog_evt_del_log_struct *del_evt = (srv_clog_evt_del_log_struct *) evt;
            if (del_evt->idf.log_id == m_logItem.data.call_log.log_id)
            {
                getMainScr()->popPage();
            }
            break;
    	}
        case EVT_ID_SRV_CLOG_UPDATE_LOG:
        {
            srv_clog_evt_update_log_struct *update_evt = (srv_clog_evt_update_log_struct *) evt;
            if (update_evt->log.data.call_log.log_id == m_logItem.data.call_log.log_id)
            {
                get_ret = m_clogDataSrv->getClogByID(update_evt->log.data.call_log.log_id, m_logItem);
                if (SRV_CLOG_RET_OK != get_ret)
                    return;
                m_action->setLog(m_logItem);
                ((VappCLogDetailInfo *)(m_form->getItem(DETAIL_INFO)))->setClog(m_logItem.data.call_log);
                ((VappCLogDetailIDCard*)(m_form->getItem(LOG_NAME_NUMBER)))->setText(m_logItem.data.call_log);
                updatePhbToolBar();
            }
            break;
        }
        case EVT_ID_SRV_CLOG_DEL_ALL:
        {
            getMainScr()->popPage();
            break;
        }
        case EVT_ID_SRV_CLOG_UPDATE_ALL:
		case EVT_ID_SRV_CLOG_READY:	
        {
            break;
    	}

        case EVT_ID_PHB_READY:
        {
            get_ret = m_clogDataSrv->getClogByID(m_logItem.data.call_log.log_id, m_logItem);
            if (SRV_CLOG_RET_OK != get_ret)
                return;
            m_action->setLog(m_logItem);
            ((VappCLogDetailIDCard*)(m_form->getItem(LOG_NAME_NUMBER)))->setText(m_logItem.data.call_log);
            updatePhbToolBar();
            break;
        }
        
        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            VfxS32 sim_count = srv_sim_ctrl_get_num_of_inserted();
            
            if (sim_count == 0)
            {
                m_editBeforeCallBtn->setIsDisabled(VFX_TRUE);
            }
            else if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
            {
                m_editBeforeCallBtn->setIsDisabled(VFX_TRUE);
            }
            else
            {
                m_editBeforeCallBtn->setIsDisabled(VFX_FALSE);
            }

            updateComboButtonStatus(m_callBtn, COMBO_BUTTON_CALL, sim_count);
            //updateComboButtonStatus(m_multiBtn, COMBO_BUTTON_MSG, sim_count);
            updateComboButtonStatus(m_msgBtn, COMBO_BUTTON_MSG, sim_count);
            
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
    #endif
          //  kal_prompt_trace(MOD_MMI,"VappCLogDetail::onUpdateForm EVT_ID = %d", event->evt_id);
            ((VappCLogDetailIDCard*)(m_form->getItem(LOG_NAME_NUMBER)))->setText(m_logItem.data.call_log);
            break;
        default:
            break;
    }
    
}


mmi_ret VappCLogDetail::onProc(mmi_event_struct *evt)
{
    if (m_action != NULL)
        return m_action->onProc(evt);

	return MMI_RET_DONT_CARE;
}


VfxBool VappCLogDetail::onKeyInput(VfxKeyEvent & event)
{
    VfxId call_type_id = VAPP_CLOG_BTN_END_OF_ENUM; //invalid type
    mmi_sim_enum sim_id = (mmi_sim_enum)(m_logItem.data.call_log.sim_id);
    
	if (event.type == VFX_KEY_EVENT_TYPE_DOWN &&
		event.keyCode == VFX_KEY_CODE_SEND)
	{
        if (m_perferSIM[COMBO_BUTTON_CALL] != MMI_SIM_NONE && srv_nw_usab_is_usable(m_perferSIM[COMBO_BUTTON_CALL]))
        {
            call_type_id = getButtonId(m_perferSIM[COMBO_BUTTON_CALL], COMBO_BUTTON_CALL);
        }
        else if (sim_id != MMI_SIM_NONE && srv_nw_usab_is_usable(sim_id))
        {
            call_type_id = getButtonId(sim_id, COMBO_BUTTON_CALL);
        }
        else
        {
            sim_id = srv_nw_usab_get_one_usable_sim();
            if (sim_id != MMI_SIM_NONE)
            {
                call_type_id = getButtonId(sim_id, COMBO_BUTTON_CALL);
            }
        }

        if (call_type_id == VAPP_CLOG_BTN_END_OF_ENUM)
        {
            CHAR ascii_cid[SRV_CLOG_CID_MAX_LEN + 1];
            mmi_wcs_to_asc(ascii_cid, m_logItem.data.call_log.cid);
            if(srv_ucm_is_emergency_number(SRV_UCM_CALL_TYPE_ALL, (U8 *) ascii_cid))
                call_type_id = VAPP_CLOG_BTN_CALL_VOICE_SIM1;
        }

        if (call_type_id != VAPP_CLOG_BTN_END_OF_ENUM)
        {
            m_action->onButtonClicked(NULL, call_type_id);
        }
	}

	return VfxPage::onKeyInput(event);
}

/***************************************************************************** 
* Class VappCLogDetailIDCard
*****************************************************************************/
VappCLogDetailIDCard::VappCLogDetailIDCard() :
    m_str(NULL),
    m_subStr(NULL),
    m_isContact(VFX_FALSE)
{
}


void VappCLogDetailIDCard::onInit()
{
    VcpFormItemBase::onInit();
    setHeight(CELL_HEIGHT);

    VFX_OBJ_CREATE(m_str, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_subStr, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_photoBorder, VcpPhotoBorderFrame, this);
    
    m_photoBorder->setPos(LEFT_GAP + IMG_WIDTH / 2, CELL_HEIGHT / 2);
    m_photoBorder->setAnchor(0.5, 0.5);
    m_photoBorder->setMaxSize(VfxSize(IMG_WIDTH, IMG_HEIGHT));
    m_photoBorder->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_MAX_SIZE);
    
    m_str->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_STT_FONT)));
    m_str->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_str->setPos(MAIN_STR_POS_X, MAIN_STR_POS_Y);
    m_str->setSize(LCD_WIDTH - MAIN_STR_POS_X - RIGHT_GAP, MAIN_STT_FONT + 4);
    m_str->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_str->setString(VFX_WSTR_EMPTY);
    //m_str->setAutoResized(VFX_FALSE);

    m_subStr->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SUB_STT_FONT)));
    m_subStr->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));    
    m_subStr->setPos(SUB_STR_POS_X, SUB_STR_POS_Y);
    m_subStr->setSize(LCD_WIDTH - SUB_STR_POS_X - RIGHT_GAP, SUB_STT_FONT);
    m_subStr->setString(VFX_WSTR_EMPTY);
    m_subStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    //m_subStr->setAutoResized(VFX_FALSE);
}


void VappCLogDetailIDCard::setText(const srv_clog_call_log_struct & calllog)
{
    if (calllog.name[0] != 0) // have name string
    {
         m_str->setString(VFX_WSTR_MEM((VfxWChar *)calllog.name));
        //m_str->setString(VFX_WSTR_MEM((VfxWChar *)calllog.name));
        m_subStr->setString((VfxWChar *)calllog.cid);
    }
    else if (srv_phb_check_number_id(calllog.phb_id)) // stored in PHB, but no name string
    {
       // m_str->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNNAMED));
        m_str->setString(STR_ID_VAPP_CLOG_UNNAMED);
        //m_subStr->setString(VFX_WSTR_MEM((VfxWChar *)calllog.cid));
        m_subStr->setString(calllog.cid);
    }
    else
    {
        //m_str->setString(VFX_WSTR_MEM((VfxWChar *)calllog.cid));
        m_str->setString((VfxWChar *)calllog.cid);
        //m_subStr->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNSAVED));
        m_subStr->setString(STR_ID_VAPP_CLOG_UNSAVED);
    }

    if (srv_phb_check_number_id(calllog.phb_id))
    {
        VfxU16 store_index = srv_phb_get_store_index_by_number_id(calllog.phb_id);
        VfxU16 image_id, res_type;
        VfxU16 image_path[SRV_FMGR_PATH_MAX_LEN] = {0};
        srv_phb_get_image(store_index, &image_id, image_path, &res_type);
        if ((image_path[0] != 0) && (srv_fmgr_fs_path_exist((WCHAR*)image_path) >= 0))// stored in PHB, and have head image
            m_photoBorder->setImgPath(VFX_WSTR_MEM(image_path));
        else
            m_photoBorder->setImgResId(IMG_COSMOS_HEAD_PORTRAIT_2);
    }
    else // not stored in PHB
        m_photoBorder->setImgResId(IMG_ID_VAPP_CLOG_SAVE_CONTACT);//VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
}



/***************************************************************************** 
* Class VappCLogDetailInfo
*****************************************************************************/
VappCLogDetailInfo::VappCLogDetailInfo(const srv_clog_call_log_struct & calllog) :
    m_clog(calllog)
{
}


void VappCLogDetailInfo::setClog(const srv_clog_call_log_struct & calllog, VfxBool needKeepViewState)
{
    m_clog = calllog;

    setHeight(VappCLogDetailTimeListItemCell::ITEM_HEIGHT * getCount()); //to modify size when log update
    m_timeList->resetAllItems(needKeepViewState);
}


void VappCLogDetailInfo::onInit()
{
    VcpFormItemBase::onInit();

    setHeight(VappCLogDetailTimeListItemCell::ITEM_HEIGHT * getCount());

    VFX_OBJ_CREATE(m_timeList, VcpListMenu, this);
    m_timeList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_timeList->setItemHeight(VappCLogDetailTimeListItemCell::ITEM_HEIGHT);
    m_timeList->setItemHighlightHidden(VFX_TRUE); // don't show highlight color when press one item
    m_timeList->setShadowIsDisabled(VFX_TRUE); // don't show shadow in top of list
    m_timeList->setContentProvider(this);
    m_timeList->setSize(getSize());
    m_timeList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


VfxBool VappCLogDetailInfo::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    VappCLogUtils clogUtils;

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (m_clog.timestamp[index] != 0)
        {
            VfxDateTime logTime;        
            VfxWChar buf[30];
            VfxU32 flags = VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
        
            clogUtils.convertUTC2DT(m_clog.timestamp[index], logTime);
            logTime.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));		    
	    //text = VFX_WSTR_MEM(buf); 
	    	text.loadFromMem(buf);
        }
        else //if (m_clog.timestamp[index] == 0) // indicate this log is sync form SIM
        {
            //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKNOWN);
            text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
        }
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    }
#ifdef __MMI_CLOG_CALL_TIME__
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        if (m_clog.timestamp[index] != 0)
        {
            clogUtils.sec2mytime(m_clog.duration[index], text, m_clog.log_type);        
	    }
        else //if (m_clog.timestamp[index] == 0) // indicate this log is sync form SIM
        {
            //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKNOWN);
            text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
        }
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
    }
#endif /* __MMI_CLOG_CALL_TIME__ */

    return VFX_TRUE;	
}


VfxU32 VappCLogDetailInfo::getCount() const
{
    VfxU32 count;
    count = m_clog.total_num > SRV_CLOG_TIME_DETAIL_MAX_NUM ? SRV_CLOG_TIME_DETAIL_MAX_NUM : m_clog.total_num;
    return count;
}


VcpListMenuCellClientBaseFrame * VappCLogDetailInfo::getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        ) 
{
    VappCLogDetailTimeListItemCell *item;
    VFX_OBJ_CREATE(item, VappCLogDetailTimeListItemCell, parentFrame);

	return item;
}


VfxBool VappCLogDetailInfo::getMenuEmptyText(
                            VfxWString &text,                // [OUT] the text resource
                            VcpListMenuTextColorEnum &color  // [OUT] the text color
                            )
{
    //text = VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKNOWN);
    text.loadFromRes(STR_ID_VAPP_CLOG_UNKNOWN);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	return VFX_TRUE;
}

/***************************************************************************** 
* Class VappCLogDetailType
*****************************************************************************/

VappCLogDetailType::VappCLogDetailType(VfxU8 which_type, VfxU8 which_sim) :
    m_logType(which_type),
    m_logSim(which_sim)
{
}


void VappCLogDetailType::onInit()
{
    VcpFormItemBase::onInit();

    setHeight(CELL_HEIGHT);
    
    VfxImageFrame *logTypeIcon;
    VFX_OBJ_CREATE(logTypeIcon, VfxImageFrame, this);
    logTypeIcon->setPos(VAPP_CLOG_LEFT_GAP, CELL_HEIGHT / 2);
    logTypeIcon->setAnchor(0, 0.5);
    
    VfxTextFrame *logTypeStr;
    VFX_OBJ_CREATE(logTypeStr, VfxTextFrame, this);
    
    switch (m_logType)
    {
        case SRV_CLOG_CLT_MISSED:
            logTypeIcon->setResId(IMG_COSMOS_MISSED_CALL);
            //logTypeStr->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_MISSED_CALL));
            logTypeStr->setString(STR_ID_VAPP_CLOG_MISSED_CALL);
            break;

        case SRV_CLOG_CLT_DIALED:
            logTypeIcon->setResId(IMG_COSMOS_DIALED_CALL);
            //logTypeStr->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_DIALLED_CALL));
            logTypeStr->setString(STR_ID_VAPP_CLOG_DIALLED_CALL);
            break;

        case SRV_CLOG_CLT_RECVED:
            logTypeIcon->setResId(IMG_COSMOS_RECEIVED_CALL);
            //logTypeStr->setString(VFX_WSTR_RES(STR_ID_VAPP_CLOG_RECEIVED_CALL));
            logTypeStr->setString(STR_ID_VAPP_CLOG_RECEIVED_CALL);
            break;

        default :
            break;
    }

	logTypeStr->setPos(2 * VAPP_CLOG_LEFT_GAP + logTypeIcon->getSize().width, CELL_HEIGHT / 2);
    logTypeStr->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(STR_FONT_SIZE)));
    logTypeStr->setAnchor(0, 0.5);
    logTypeStr->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));

#if (MMI_MAX_SIM_NUM >= 2)    

    VfxImageFrame *logSIMIcon;
    VFX_OBJ_CREATE(logSIMIcon, VfxImageFrame, this);
    logSIMIcon->setPos(LCD_WIDTH - VAPP_CLOG_RIGHT_GAP, CELL_HEIGHT / 2);
    logSIMIcon->setAnchor(1, 0.5);

     switch (m_logSim)
     {
         case MMI_SIM1:
             logSIMIcon->setResId(IMG_COSMOS_SIM1);
             break;
         case MMI_SIM2:
             logSIMIcon->setResId(IMG_COSMOS_SIM2);
             break;
    #if (MMI_MAX_SIM_NUM >= 3)
         case MMI_SIM3:
             logSIMIcon->setResId(IMG_COSMOS_SIM3);
             break;
    #if (MMI_MAX_SIM_NUM >= 4)
         case MMI_SIM4:
             logSIMIcon->setResId(IMG_COSMOS_SIM4);
             break;
    #endif
    #endif
         default:
             break;
     }     
     if (1 >= srv_sim_ctrl_get_num_of_inserted()) // only 1 SIM or no SIM is inserted
     {
         logSIMIcon->setResId(0);
     }
#endif /* (MMI_MAX_SIM_NUM >= 2) */    
    
}


/*****************************************************************************
 * Class VappCLogDetailTimeListItemCell
 *****************************************************************************/

void VappCLogDetailTimeListItemCell::onUpdateTextFrameStyle(VcpListMenuFieldEnum fieldType, VfxTextFrame *frame)
{
    VcpListMenuCellMultiTextFrameEx::onUpdateTextFrameStyle(fieldType, frame);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT || fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        frame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SRT_FONT_SIZE)));
    }
}

void VappCLogDetailTimeListItemCell::onUpdateTextViewStyle(VcpListMenuFieldEnum fieldType, VcpTextView *frame)
{
    VcpListMenuCellMultiTextFrameEx::onUpdateTextViewStyle(fieldType, frame);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT || fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        frame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SRT_FONT_SIZE)));
    }
}


