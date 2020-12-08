/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  Vapp_setting_motion.cpp
 *
 * Project:
 * --------
 *  MAUI
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
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
extern "C"
{
#include "mmi_features.h"
}

#ifdef MOTION_SENSOR_SUPPORT
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_setting_motion.h"

extern "C"
{
#include "ReminderSrvGprot.h" //alarm
#include "ScreenRotationGprot.h" // rotation
#include "CallSetSrvGprot.h" //ucm
#include "sensorsrvgport.h" //motion sensor
}

/***************************************************************************** 
 * Function
 *****************************************************************************/
void vapp_setting_motion_launch(VfxMainScr *mainScr)
{
    VappSettingMotionPage *settingMotionPage;
    VFX_OBJ_CREATE(settingMotionPage, VappSettingMotionPage, mainScr);    
    mainScr->pushPage(0, settingMotionPage);
}


/***************************************************************************** 
 * Class VappSettingMotionPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSettingMotionPage", VappSettingMotionPage, VfxPage);
void VappSettingMotionPage::onInit()
{
    VfxPage::onInit();

    // need to use other app's interface to get current status
    m_motionSensorSwitchValue = (VfxBool)srv_sensor_motion_get_switch();
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_GET_MOTION_SENSOR_SWITCH_VALUE, m_motionSensorSwitchValue);
    m_orientationSwitchValue = (VfxBool)mmi_get_ui_rotation_state_by_mcube_sensor();
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_GET_ORIENTATION_SWITCH_VALUE, m_orientationSwitchValue);
    m_muteCallSwitchValue = (VfxBool)srv_callset_flip_to_mute_call_get_mode();
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_GET_FLIP_TO_MUTE_CALL_SWITCH_VALUE, m_muteCallSwitchValue);
    m_muteAlarmSwitchValue = (VfxBool)srv_reminder_get_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER);
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_GET_FLIP_TO_MUTE_ALARM_SWITCH_VALUE, m_muteAlarmSwitchValue);
#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    m_tapTapToRecordSwitchValue = (VfxBool)srv_callset_tap_tap_to_record_in_call_get_mode();
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_GET_TAP_TAP_TO_RECORD_SWITCH_VALUE, m_tapTapToRecordSwitchValue);
#endif
    //title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION);
    titleBar->setTitle(str);
    setTopBar(titleBar); 

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemSwitchCell *switchCell;
    // motion sensor
    VFX_OBJ_CREATE(switchCell, VcpFormItemSwitchCell, m_form);
    switchCell->setSwitchStatus(m_motionSensorSwitchValue);
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_SENSOR);
    switchCell->setMainText(str);
    switchCell->setIsTappable(VFX_FALSE);
    switchCell->m_signalSwitchChangeReq.connect(this, &VappSettingMotionPage::onSwitchChanged);
    m_form->addItem(switchCell, MOTION_SETTING_ITEM_ID_MOTION_SENSOR);

    // orientation
    VFX_OBJ_CREATE(switchCell, VcpFormItemSwitchCell, m_form);
    if (m_motionSensorSwitchValue)
    {
        switchCell->setSwitchStatus(m_orientationSwitchValue);
    }
    else
    {
        switchCell->setSwitchStatus(VFX_FALSE);
        switchCell->setIsDisabled(VFX_TRUE);
    }
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_ORIENTATION);
    switchCell->setMainText(str);
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_AUTO_SWITCH_DISPLAY_ORIENTATION);
    switchCell->setHintText(str);
    switchCell->setIsTappable(VFX_FALSE);
    switchCell->m_signalSwitchChangeReq.connect(this, &VappSettingMotionPage::onSwitchChanged);
    m_form->addItem(switchCell, MOTION_SETTING_ITEM_ID_ORIENTATION);

    // mute call
    VFX_OBJ_CREATE(switchCell, VcpFormItemSwitchCell, m_form);
    if (m_motionSensorSwitchValue)
    {
        switchCell->setSwitchStatus(m_muteCallSwitchValue);
    }
    else
    {
        switchCell->setSwitchStatus(VFX_FALSE);
        switchCell->setIsDisabled(VFX_TRUE);
    }
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_FLIP_TO_MUTE_CALL);
    switchCell->setMainText(str);
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_FLIP_PHONE_TO_MUTE_INCOMING_CALL);
    switchCell->setHintText(str);
    switchCell->setIsTappable(VFX_FALSE);
    switchCell->m_signalSwitchChangeReq.connect(this, &VappSettingMotionPage::onSwitchChanged);
    m_form->addItem(switchCell, MOTION_SETTING_ITEM_ID_MUTE_CALL);

    // mute alarm
    VFX_OBJ_CREATE(switchCell, VcpFormItemSwitchCell, m_form);
    if (m_motionSensorSwitchValue)
    {
        switchCell->setSwitchStatus(m_muteAlarmSwitchValue);
    }
    else
    {
        switchCell->setSwitchStatus(VFX_FALSE);
        switchCell->setIsDisabled(VFX_TRUE);
    }
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_FLIP_TO_MUTE_ALARM);
    switchCell->setMainText(str);
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_FLIP_PHONE_TO_MUTE_ALARM);
    switchCell->setHintText(str);
    switchCell->setIsTappable(VFX_FALSE);
    switchCell->m_signalSwitchChangeReq.connect(this, &VappSettingMotionPage::onSwitchChanged);
    m_form->addItem(switchCell, MOTION_SETTING_ITEM_ID_MUTE_ALARM);

#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    // tap-tap
    VFX_OBJ_CREATE(switchCell, VcpFormItemSwitchCell, m_form);
    if (m_motionSensorSwitchValue)
    {
        switchCell->setSwitchStatus(m_tapTapToRecordSwitchValue);
    }
    else
    {
        switchCell->setSwitchStatus(VFX_FALSE);
        switchCell->setIsDisabled(VFX_TRUE);
    }
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_TAP_TAP_TO_RECORD);
    switchCell->setMainText(str);
    str.loadFromRes(STR_ID_VAPP_SETTING_MOTION_START_TO_RECORD_SECRETLY_INCALL);
    switchCell->setHintText(str);
    switchCell->setIsTappable(VFX_FALSE);
    switchCell->m_signalSwitchChangeReq.connect(this, &VappSettingMotionPage::onSwitchChanged);
    m_form->addItem(switchCell, MOTION_SETTING_ITEM_ID_TAPTAP_TO_RECORD);
#endif
}


void VappSettingMotionPage::onSwitchChanged(
        VcpFormItemSwitchCell* sender,  // Sender
        VfxId id,                       // Sender id
        VfxBool switchVal               // new switch value
    )
{
    switch (id)
    {
        case MOTION_SETTING_ITEM_ID_MOTION_SENSOR:
        {
            // set value to app
            m_motionSensorSwitchValue = switchVal;
            srv_sensor_motion_set_switch((MMI_BOOL)m_motionSensorSwitchValue);
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_SET_MOTION_SENSOR_SWITCH_VALUE, m_motionSensorSwitchValue);
            if (m_motionSensorSwitchValue)
            {
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_ORIENTATION)))->setSwitchStatus(m_orientationSwitchValue);
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_MUTE_CALL)))->setSwitchStatus(m_muteCallSwitchValue);
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_MUTE_ALARM)))->setSwitchStatus(m_muteAlarmSwitchValue);
            #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_TAPTAP_TO_RECORD)))->setSwitchStatus(m_tapTapToRecordSwitchValue);
            #endif
            }
            else
            {
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_ORIENTATION)))->setSwitchStatus(VFX_FALSE);
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_MUTE_CALL)))->setSwitchStatus(VFX_FALSE);
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_MUTE_ALARM)))->setSwitchStatus(VFX_FALSE);
            #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
                ((VcpFormItemSwitchCell*)(m_form->getItem(MOTION_SETTING_ITEM_ID_TAPTAP_TO_RECORD)))->setSwitchStatus(VFX_FALSE);
            #endif
            }            
            m_form->getItem(MOTION_SETTING_ITEM_ID_ORIENTATION)->setIsDisabled(!switchVal);
            m_form->getItem(MOTION_SETTING_ITEM_ID_MUTE_CALL)->setIsDisabled(!switchVal);
            m_form->getItem(MOTION_SETTING_ITEM_ID_MUTE_ALARM)->setIsDisabled(!switchVal);
        #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
            m_form->getItem(MOTION_SETTING_ITEM_ID_TAPTAP_TO_RECORD)->setIsDisabled(!switchVal);
        #endif
            break;
        }
        case MOTION_SETTING_ITEM_ID_ORIENTATION:
        {
            // set value to app
            m_orientationSwitchValue = switchVal;
            mmi_set_ui_rotation_state_by_mcube_sensor((MMI_BOOL)m_orientationSwitchValue);
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_SET_ORIENTATION_SWITCH_VALUE, m_orientationSwitchValue);
            break;
        }
        case MOTION_SETTING_ITEM_ID_MUTE_CALL:
        {
            // set value to app
            m_muteCallSwitchValue = switchVal;
            srv_callset_flip_to_mute_call_set_mode((MMI_BOOL)m_muteCallSwitchValue);
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_SET_FLIP_TO_MUTE_CALL_SWITCH_VALUE, m_muteCallSwitchValue);
            break;
        }
        case MOTION_SETTING_ITEM_ID_MUTE_ALARM:
        {
            // set value to app
            m_muteAlarmSwitchValue = switchVal;
            srv_reminder_set_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER, (MMI_BOOL)m_muteAlarmSwitchValue);
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_SET_FLIP_TO_MUTE_ALARM_SWITCH_VALUE, m_muteAlarmSwitchValue);
            break;
        }
    #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
        case MOTION_SETTING_ITEM_ID_TAPTAP_TO_RECORD:
        {
            // set value to app
            m_tapTapToRecordSwitchValue = switchVal;
            srv_callset_tap_tap_to_record_in_call_set_mode((MMI_BOOL)m_tapTapToRecordSwitchValue);
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, VAPP_SETTING_MOTION_SET_TAP_TAP_TO_RECORD_SWITCH_VALUE, m_tapTapToRecordSwitchValue);
            break;
        }
    #endif
        default:
            break;
    }
    sender->setSwitchStatus(switchVal);
}
#endif
