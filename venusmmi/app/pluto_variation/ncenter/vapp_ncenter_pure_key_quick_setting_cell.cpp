/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   vapp_ncenter_quick_setting_cell.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *****************************************************************************
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#define __MMI_NCENTER_NATIVE_WIDGET_SUPPORT__
#ifdef __MMI_NCENTER_NATIVE_WIDGET_SUPPORT__

extern "C" 
{
    #include "ModeSwitchSrvGprot.h" // for srv_mode_switch_is_network_service_available
    #include "TetheringSrvGprot.h" // for SRV_TETHERING_TYPE_WIFI_HS
    #include "BtcmSrvGprot.h" // for srv_bt_cm_get_power_status
    #include "ProfilesSrvGprot.h" // for srv_prof_is_profile_activated
    #include "DtcntSrvGprot.h" // for SRV_DTCNT_WLAN_STATUS_INACTIVE
    #include "UcmSrvGprot.h" // for srv_ucm_is_any_call
    #include "DtcntSrvIprot.h" // for srv_dtcnt_wlan_init
    #include "gpiosrvgprot.h" // for SRV_GPIO_BACKLIGHT_MIN_LEVEL
    #include "gpiosrvprot.h" // for srv_backlight_get_real_level
    #include "mmi_rp_srv_prof_def.h" // for EVT_ID_SRV_PROF_PROFILE_SWITCHED
    #include "wgui_categories_util.h" // for wgui_status_icon_bar_reset_icon_display

    #include "GlobalResDef.h"
    #include "mmi_common_app_trc.h"
}

#include "mmi_rp_app_ncenter_def.h"
#include "vapp_ncenter_pure_key.h"

#if defined(__COSMOS_MMI_PACKAGE__)
#include "vcp_global_popup.h" // for vcp_global_popup_show_confirm_two_button_str
#include "vcui_dtcnt_wlan_gprot.h" // for vapp_wlan_send_cmcc_deinit
#else
#include "vcp_confirm_popup.h" // for VcpConfirmPopup
#endif
#include "vapp_ncenter_pure_key_quick_setting_cell.h"

/*****************************************************************************
 * Class VappQuickSettingCell implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappQuickSettingCell", VappQuickSettingCell, VfxFrame);
/*---------------------------------------------------------------------------*
 * Function: onInit()
 * Description: add_description_here
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::onInit()
{ 
//local var:
    m_rowNum = 1 + (VAPP_QSETTING_TOTAL - 2) / 5;
    m_popupHandle = 0;
    VfxSize cellSize(((VfxFrame*)getParent())->getSize().width, ELEMENT_HIGHT * m_rowNum+ 10);
//func implementation:
    VfxFrame::onInit();
#ifdef __MMI_WLAN_FEATURES__
    m_elementInfo[VAPP_QSETTING_WIFI - 1].elementID = VAPP_QSETTING_WIFI;
    m_elementInfo[VAPP_QSETTING_WIFI - 1].buttonImage_N = IMG_ID_VAPP_QUICK_SETTING_WIFI_N;
    m_elementInfo[VAPP_QSETTING_WIFI - 1].buttonImage_H = IMG_ID_VAPP_QUICK_SETTING_WIFI_H;
    m_elementInfo[VAPP_QSETTING_WIFI - 1].indicatorCount = 1;
#endif //__MMI_WLAN_FEATURES__
#ifdef __MMI_BT_SUPPORT__
    m_elementInfo[VAPP_QSETTING_BT - 1].elementID = VAPP_QSETTING_BT;
    m_elementInfo[VAPP_QSETTING_BT - 1].buttonImage_N = IMG_ID_VAPP_QUICK_SETTING_BT_N;
    m_elementInfo[VAPP_QSETTING_BT - 1].buttonImage_H = IMG_ID_VAPP_QUICK_SETTING_BT_H;
    m_elementInfo[VAPP_QSETTING_BT - 1].indicatorCount = 1;
#endif //__MMI_BT_SUPPORT__
    m_elementInfo[VAPP_QSETTING_SILENCE - 1].elementID = VAPP_QSETTING_SILENCE;
    m_elementInfo[VAPP_QSETTING_SILENCE - 1].buttonImage_N = IMG_ID_VAPP_QUICK_SETTING_SILENT_N;
    m_elementInfo[VAPP_QSETTING_SILENCE - 1].buttonImage_H = IMG_ID_VAPP_QUICK_SETTING_SILENT_H;
    m_elementInfo[VAPP_QSETTING_SILENCE - 1].indicatorCount = 1;
    
    m_elementInfo[VAPP_QSETTING_FLIGHT_MODE - 1].elementID = VAPP_QSETTING_FLIGHT_MODE;
    m_elementInfo[VAPP_QSETTING_FLIGHT_MODE - 1].buttonImage_N = IMG_ID_VAPP_QUICK_SETTING_FLIGHT_N;
    m_elementInfo[VAPP_QSETTING_FLIGHT_MODE - 1].buttonImage_H = IMG_ID_VAPP_QUICK_SETTING_FLIGHT_H;
    m_elementInfo[VAPP_QSETTING_FLIGHT_MODE - 1].indicatorCount = 1;
    
    m_elementInfo[VAPP_QSETTING_LIGHT - 1].elementID = VAPP_QSETTING_LIGHT;
    m_elementInfo[VAPP_QSETTING_LIGHT - 1].buttonImage_N = IMG_ID_VAPP_QUICK_SETTING_BRIGHTNESS_N;
    m_elementInfo[VAPP_QSETTING_LIGHT - 1].buttonImage_H = IMG_ID_VAPP_QUICK_SETTING_BRIGHTNESS_H;
    m_elementInfo[VAPP_QSETTING_LIGHT - 1].indicatorCount = 3;
    
    setSize(cellSize);
    createBgImg(cellSize);
    createElements(VfxSize((getSize().width - 10)/(VAPP_QSETTING_TOTAL - 1), ELEMENT_HIGHT));
    registerEvent();
    m_turningOffTethering = VFX_FALSE;
}

/*---------------------------------------------------------------------------*
 * Function: onDeinit()
 * Description: add_description_here
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::onDeinit()
{
//local var:
    
//func implementation:
    deregisterEvent();
    VfxFrame::onDeinit();
}


/*---------------------------------------------------------------------------*
 * Function: flightEvtHdlr()
 * Description: call back function for fligh mode switching. just return MMI_RET_OK.
 *    @return: return MMI_RET_OK
 *---------------------------------------------------------------------------*/
mmi_ret VappQuickSettingCell::flightEvtHdlr(    mmi_event_struct *event)
{
//local var:
    
//func implementation:
    return MMI_RET_OK;
}


/*---------------------------------------------------------------------------*
 * Function: enentHdlr()
 * Description: enent handler, handle the enents, execpt bt envent.
 *    @return: 
 *---------------------------------------------------------------------------*/
mmi_ret VappQuickSettingCell::enentHdlr(mmi_event_struct *evt)
{
//local var:
    VappQuickSettingCell* selfObj;
    VappQuickSettingElement* element;
//func implementation:

    //update elements status.
    selfObj = (VappQuickSettingCell*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if(!selfObj)
        return MMI_RET_OK;
    
    switch(evt->evt_id)
    {
#ifdef __MMI_WLAN_FEATURES__       
        case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND://WLAN on event. may fail
        {
            srv_dtcnt_wlan_init_res_ind_evt_struct* wlanEvt =
            (srv_dtcnt_wlan_init_res_ind_evt_struct *)evt;
            if(wlanEvt->res == SRV_DTCNT_WLAN_REQ_RES_DONE)
            {
                element = selfObj->findElementById(VAPP_QSETTING_WIFI);
                element->increaseIndicator();
            }
            else
            {
                //fail to turn on, show balloon.
            }
            break;
        }
        case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND://WLAN off event. may fail
        {
            srv_dtcnt_wlan_deinit_res_ind_evt_struct* wlanEvt = 
                (srv_dtcnt_wlan_deinit_res_ind_evt_struct*) evt;
            if(wlanEvt->res == SRV_DTCNT_WLAN_REQ_RES_DONE)
            {
                element = selfObj->findElementById(VAPP_QSETTING_WIFI);
                element->decreaseIndicator();
            }
            else
            {
                //fail to turn off, show balloon.
            }
            break;
        }
#endif //__MMI_WLAN_FEATURES__
        case EVT_ID_SRV_PROF_PROFILE_SWITCHED:
        {
            VfxBool silent;
            element = selfObj->findElementById(VAPP_QSETTING_SILENCE);
            if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
            {
                 element->decreaseIndicator();
                silent = VFX_FALSE;
            }
            else
            {
                element->increaseIndicator();
                silent = VFX_TRUE;
            }

            // update stauts icon bar.
            MMI_BOOL vibrate = srv_prof_if_can_vibrate();

            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SILENT);
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_VIBRATION);
            wgui_status_icon_bar_reset_icon_display(STATUS_ICON_VIBRATE_AND_RING);

            if(silent && !vibrate )
            {
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_SILENT);
            }
            else if(silent && vibrate)
            {
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_VIBRATION);
            }
            else if(!silent && vibrate)
            {
                wgui_status_icon_bar_set_icon_display(STATUS_ICON_VIBRATE_AND_RING);
            }

            wgui_status_icon_bar_update();
            break;
        }
        
        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:           // Flight event
        {
            srv_mode_switch_notify_struct *notify_evt = (srv_mode_switch_notify_struct *)evt;
            element = selfObj->findElementById(VAPP_QSETTING_FLIGHT_MODE);

            if (notify_evt->curr_flight_mode == SRV_MODE_SWITCH_ON &&
                notify_evt->select_flight_mode == SRV_MODE_SWITCH_OFF)
            {
                element->decreaseIndicator();
            }
            else if (notify_evt->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
                     notify_evt->select_flight_mode == SRV_MODE_SWITCH_ON)
            {
                 element->increaseIndicator();
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_WLAN_FEATURES__ 
/*---------------------------------------------------------------------------*
 * Function: afterStopTethering()
 * Description: auto turn wlan, if stoping successful.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::afterStopTethering(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
//local var:
    
   VappQuickSettingCell* selfObj;
//func implementation:
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_AFTER_STOP_TETHERING);
   selfObj = (VappQuickSettingCell*)VfxObject::handleToObject((VfxObjHandle)user_data);
    if(selfObj)
    {
        selfObj->m_turningOffTethering = VFX_FALSE;
       //The callback function after wifi tethering has been stopped.
        if(result)
        {// turn wlan
            selfObj->findElementById(VAPP_QSETTING_WIFI)->showProcessInd();
            srv_dtcnt_wlan_init(NULL, NULL);
        }
	return;
    }
    if(result)
    {
        // turn wlan
        srv_dtcnt_wlan_init(NULL, NULL);
        return;
    }
}
#endif //__MMI_WLAN_FEATURES__

#ifdef __MMI_BT_SUPPORT__
/*---------------------------------------------------------------------------*
 * Function: btEvtHdlr()
 * Description: handle bt event
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::btEvtHdlr(U32 event, void* para)
{
//local var:
    VappQuickSettingElement* element;
    srv_bt_cm_activate_struct *res = (srv_bt_cm_activate_struct *)para;
    VappQuickSettingCell *selfObj = (VappQuickSettingCell *)VfxObject::handleToObject((VfxObjHandle)res->user_data);
//func implementation:

    if(selfObj)
    {
        element = selfObj->findElementById(VAPP_QSETTING_BT);
        //update BT elements status.
        if(SRV_BT_CM_EVENT_ACTIVATE == event)
        {
            element->increaseIndicator();
        }
        else if(SRV_BT_CM_EVENT_DEACTIVATE == event)
        {
            element->decreaseIndicator();
        }
        else
            element->showProcessInd();
    }
}
#endif //__MMI_BT_SUPPORT__

/*---------------------------------------------------------------------------*
 * Function: onUserClicked()
 * Description: called when user clicked the element button.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::onUserClicked(VfxObject *sender, VfxId id)
{
//local var:
    VappQuickSettingElement* element;
    VfxS32 orignalIndicator = -1;
    VfxS32 settingToIndicator = -1;

//func implementation:
    if (isDisplayFocus() == VFX_FALSE || getFocusIndex() != id - 1)
    {
        // focus is changed when pen up
        return;
    }
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ON_USER_CLICKED, id);
    element = findElementById(id);
    if(element && element->isEnable())
    {
        orignalIndicator = element->getCurrentIndicator();
    
        switch(id)
        {
#ifdef __MMI_WLAN_FEATURES__
            case VAPP_QSETTING_WIFI:
#endif
#ifdef __MMI_BT_SUPPORT__
            case VAPP_QSETTING_BT:
#endif
            case VAPP_QSETTING_FLIGHT_MODE:
            case VAPP_QSETTING_SILENCE:
                if(0 == orignalIndicator)
                    settingToIndicator = 1;
                else if(1 == orignalIndicator)
                    settingToIndicator = 0;
                else
                    return;
            break;
            case VAPP_QSETTING_LIGHT:
            {
                if(m_lightUp)//increasing
                {
                    element->increaseIndicator();
                    settingToIndicator = orignalIndicator + 1;
                    if(2 == orignalIndicator)
                        m_lightUp = VFX_FALSE;
                }
                else//decreasing
                {
                    element->decreaseIndicator();
                    settingToIndicator = orignalIndicator - 1;
                    if(1 == orignalIndicator)
                        m_lightUp = VFX_TRUE;
                }
                break;
            }
            default:
                return;
        }
        setSrvStatusById(settingToIndicator, id);
    }
}


/*---------------------------------------------------------------------------*
 * Function: onStateChanged()
 * Description: called when the element button state changed.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::onStateChanged(VcpImageButton* img_bt, VcpImageButtonStateEnum state)
{
//local var:
    VfxS32 i = 0;

//func implementation:
    if(state == VCP_IMAGE_BUTTON_STATE_PRESSED)
    {
        for (i = 0; i < VAPP_QSETTING_TOTAL -  1; i ++)
        {
            if (m_elementInfo[i].elementHandle->m_imageButton == img_bt)
            {
                break;
            }
        }
        if (i < VAPP_QSETTING_TOTAL -  1)
        {
            VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
			
            if(isDisplayFocus() == VFX_FALSE)
            {
                VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
                //disable list highlight
                nc->clearListFocus();
                setDisplayFocus(VFX_TRUE);
                setFocusIndex(i);
            }
            else
            {
                setFocusIndex(i);
            }
            nc->setLSKString(getLSKStringID());
        }
    }
}


/*---------------------------------------------------------------------------*
 * Function: setDisplayFocus()
 * Description: display or hide focus.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::setDisplayFocus(VfxBool flag)
{
    m_display_focus = flag;
    
    if (m_display_focus)
    {
        m_focusImg->setHidden(VFX_FALSE);
    }
    else
    {
        m_focusImg->setHidden(VFX_TRUE);
    }
}


/*---------------------------------------------------------------------------*
 * Function: isDisplayFocus()
 * Description: display or hide focus.
 *---------------------------------------------------------------------------*/
VfxBool VappQuickSettingCell::isDisplayFocus(void)
{
    return m_display_focus;
}


/*---------------------------------------------------------------------------*
 * Function: getFocusIndex()
 * Description: get focus item index.
 *---------------------------------------------------------------------------*/
VfxS32 VappQuickSettingCell::getFocusIndex(void)
{
    return m_focus_idx;
}


/*---------------------------------------------------------------------------*
 * Function: changeFocusItemState()
 * Description: change focus item state.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::changeFocusItemState(void)
{
    onUserClicked(0, m_focus_idx + 1);
}


/*---------------------------------------------------------------------------*
 * Function: getLSKStringID()
 * Description: get focus item LSK string.
 *---------------------------------------------------------------------------*/
VfxResId VappQuickSettingCell::getLSKStringID(void)
{
    VfxS32 orignalIndicator = -1;
    VappQuickSettingElement* element = findElementById(m_focus_idx + 1);
    
    if(element && element->isEnable())
    {
        orignalIndicator = element->getCurrentIndicator();
        
        switch(m_focus_idx + 1)
        {
#ifdef __MMI_WLAN_FEATURES__
            case VAPP_QSETTING_WIFI:
#endif
#ifdef __MMI_BT_SUPPORT__
            case VAPP_QSETTING_BT:
#endif
            case VAPP_QSETTING_FLIGHT_MODE:
            case VAPP_QSETTING_SILENCE:
                if(0 == orignalIndicator)
                    return STR_GLOBAL_ON;
                else if(1 == orignalIndicator)
                    return STR_GLOBAL_OFF;
                else
                    return 0;
            break;
            case VAPP_QSETTING_LIGHT:
            {
                if(m_lightUp)//increasing
                {
                    if(0 == orignalIndicator)
                        return STR_ID_VAPP_NCENTER_CHANGE;
                    else if(1 == orignalIndicator)
                        return STR_ID_VAPP_NCENTER_CHANGE;
                    else
                        return STR_ID_VAPP_NCENTER_CHANGE;
                }
                else//decreasing
                {
                    if(0 == orignalIndicator)
                        return STR_ID_VAPP_NCENTER_CHANGE;
                    else if(1 == orignalIndicator)
                        return STR_ID_VAPP_NCENTER_CHANGE;
                    else
                        return STR_ID_VAPP_NCENTER_CHANGE;
                }
                break;
            }
            default:
                break;
        }
    }

    return 0;
}


/*---------------------------------------------------------------------------*
 * Function: setFocusIndex()
 * Description: display or hide focus.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::setFocusIndex(VfxS32 idx)
{
    VfxS32 focus_w = (UI_device_width - FOCUS_GAP_X1 - FOCUS_GAP_X2 - (FOCUS_GAP_SEPATATOR * (VAPP_QSETTING_TOTAL - 2))) / (VAPP_QSETTING_TOTAL - 1);
    if (idx < 0 || idx >= (VAPP_QSETTING_TOTAL - 1))
    {
        return;
    }
    
    m_focus_idx = idx;
    if (m_focusImg)
    {
        m_focusImg->setPos(FOCUS_X + (idx * (focus_w + FOCUS_GAP_SEPATATOR)), FOCUS_Y);
        if (m_display_focus)
        {
            m_focusImg->setHidden(VFX_FALSE);
        }
        else
        {
            m_focusImg->setHidden(VFX_TRUE);
        }
    }
}


/*---------------------------------------------------------------------------*
 * Function: setFocusIndex()
 * Description: display or hide focus.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::moveFocus(VfxKeyCodeEnum key_code)
{
    if (key_code == VFX_KEY_CODE_ARROW_LEFT)
    {
        if (m_focus_idx == 0)
        {
            setFocusIndex(VAPP_QSETTING_TOTAL - 2);
        }
        else
        {
            setFocusIndex(m_focus_idx - 1);
        }
    }
    else if (key_code == VFX_KEY_CODE_ARROW_RIGHT)
    {
        if (m_focus_idx == VAPP_QSETTING_TOTAL - 2)
        {
            setFocusIndex(0);
        }
        else
        {
            setFocusIndex(m_focus_idx + 1);
        }
    }
}


/*---------------------------------------------------------------------------*
 * Function: showComfirmPopup()
 * Description: popup a comfirm.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::showComfirmPopup()
{
//local var:
    VfxResId textResId;
    VfxResId button1ResId;
//func implementation:
    button1ResId = STR_ID_QSETTING_BUTTON_ON;

    switch(m_comfirmType)
    {
#ifdef __MMI_WLAN_FEATURES__
        case VAPP_QSETTING_COMFIRM_WIFI_ON_WITH_FLIGHT_MODE:
            textResId = STR_ID_QSETTING_WLAN_IN_FLIGHT_MODE_ASK;
            break;
        case VAPP_QSETTING_COMFIRM_WIFI_ON_WITH_TETHERING:
            textResId = STR_ID_QSETTING_WLAN_TURN_OFF_HOT_SPOT;
            button1ResId = STR_ID_QSETTING_BUTTON_OK;
            break;
#endif //__MMI_WLAN_FEATURES__
#ifdef __MMI_BT_SUPPORT__
        case VAPP_QSETTING_COMFIRM_BT_ON_WITH_FLIGHT_MODE:
            textResId = STR_ID_QSETTING_BT_IN_FLIGHT_MODE_ASK;
            break;
        case VAPP_QSETTING_COMFIRM_BT_OFF_WITH_CONNECTING:
            textResId = STR_ID_QSETTING_BT_TURN_OFF_WITH_CONNECTION_CONFIRM;
            button1ResId = STR_ID_QSETTING_BUTTON_OFF;
            break;
#endif //__MMI_WLAN_FEATURES__
        default:
            return;
    }

    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
    VappNCenterScr *scr = nc->getNCenterScr();
    if(scr)
    {
        VcpConfirmPopup *popup = NULL;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, scr);
        popup->setInfoType(VCP_POPUP_TYPE_WARNING);
        popup->setText(VFX_WSTR_RES(textResId));
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        popup->setCustomButton(
                VFX_WSTR_RES(button1ResId),
                VFX_WSTR_RES(STR_ID_QSETTING_BUTTON_CANCEL),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL
                );
        popup->m_signalButtonClicked.connect(this, &VappQuickSettingCell::onFTEComirmed);
        popup->setAutoDestory(VFX_TRUE);
        popup->show(VFX_TRUE);
    }
}

/*---------------------------------------------------------------------------*
 * Function: onFTEComirmed()
 * Description: call back when user clicked popup button on FTE.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::onFTEComirmed(VfxObject *obj, VfxId id)
{
//local var:
    
//func implementation:
    onUserComfirmed(id, getObjHandle());
}


/*---------------------------------------------------------------------------*
 * Function: onUserComfirmed()
 * Description: This function handles the popup clicked signal
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::onUserComfirmed(VfxId id, void *userData)
{
//local var:
    VappQuickSettingCell* selfObj;
//func implementation:
    selfObj = (VappQuickSettingCell*)VfxObject::handleToObject((VfxObjHandle)userData);

    if(selfObj)
    {
        selfObj->m_popupHandle = 0;
        if(VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
        {
            switch(selfObj->m_comfirmType)
            {
#ifdef __MMI_WLAN_FEATURES__
                case VAPP_QSETTING_COMFIRM_WIFI_ON_WITH_FLIGHT_MODE:
                    selfObj->findElementById(VAPP_QSETTING_WIFI)->showProcessInd();
                    srv_dtcnt_wlan_init(NULL, NULL);
                    break;
                case VAPP_QSETTING_COMFIRM_WIFI_ON_WITH_TETHERING:
                    selfObj->findElementById(VAPP_QSETTING_WIFI)->showProcessInd();
                    selfObj->m_turningOffTethering = VFX_TRUE;
                    srv_tethering_stop (SRV_TETHERING_TYPE_WIFI_HS, VappQuickSettingCell::afterStopTethering, userData);
                    break;
#endif //__MMI_WLAN_FEATURES__
#ifdef __MMI_BT_SUPPORT__
                case VAPP_QSETTING_COMFIRM_BT_ON_WITH_FLIGHT_MODE:
                    srv_bt_cm_switch_on();
                    break;
                case VAPP_QSETTING_COMFIRM_BT_OFF_WITH_CONNECTING:
                    srv_bt_cm_switch_off();
                    break;
#endif //__MMI_WLAN_FEATURES__

                default:
                    return;
            }
        }
    }
}


/*---------------------------------------------------------------------------*
 * Function: getSrvStatusById()
 * Description: get indicator count from service by elementID.
 *    @return: current indicator count.
 *---------------------------------------------------------------------------*/
VfxS32 VappQuickSettingCell::getSrvStatusById(VfxS32 aElementId)
{
//local var:
    VfxS32 returnVal = 0;
//func implementation:
    switch(aElementId)
    {
#ifdef __MMI_WLAN_FEATURES__
        case VAPP_QSETTING_WIFI:
        {
            srv_dtcnt_wlan_switch_state_enum state = srv_dtcnt_wlan_switch_state();
            if(SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE == state || SRV_DTCNT_WLAN_SWITCH_STATE_OPENING == state)
            {
                returnVal = 0;
            }
            else
            {
                returnVal = 1;
            }    
            break;
        }
#endif //__MMI_WLAN_FEATURES__
#ifdef __MMI_BT_SUPPORT__
        case VAPP_QSETTING_BT:
        {
            srv_bt_cm_power_status_enum btStatus = srv_bt_cm_get_power_status();
            if(SRV_BT_CM_POWER_ON == btStatus || SRV_BT_CM_POWER_SWITCHING_OFF == btStatus)
            {
                returnVal = 1;
            }
            else
            {
                returnVal = 0;
            }
            break;
        }
#endif //__MMI_BT_SUPPORT__
        case VAPP_QSETTING_SILENCE:
        {
            if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
            {
                returnVal = 0;
            }
            else
            {
                returnVal = 1;
            }
            break;
        }
        case VAPP_QSETTING_FLIGHT_MODE:
        {
            if (srv_mode_switch_is_network_service_available())
            {
                returnVal = 0;
            }
            else
            {
                returnVal = 1;
            }
            break;
        }
        case VAPP_QSETTING_LIGHT:
        {
            returnVal = getCurrentLightIndex();
        }
    }

    return returnVal;
}

/*---------------------------------------------------------------------------*
 * Function: setSrvStatusById()
 * Description: set indicator count to service by elementID.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::setSrvStatusById(VfxU32 aNewStatus, VfxS32 aElementId)
{
//local var:
    MMI_BOOL isFlightSwitching;
    MMI_BOOL isFlightOFF;    
    VappQuickSettingElement* element;
    
//func implementation:
    element = findElementById(aElementId);

    //get flight mode status.
    isFlightSwitching = srv_mode_switch_is_switching();
    isFlightOFF = srv_mode_switch_is_network_service_available();


    switch(aElementId)
    {
#ifdef __MMI_WLAN_FEATURES__
        case VAPP_QSETTING_WIFI:
        {
            //check if there is WIFI-tethering availabe.
            MMI_BOOL isTetheringOff = srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS);
            
            // Check if  tetghering is switching, the switching might take quite long time in some case.
            MMI_BOOL isTetheringSwitching = srv_tethering_is_switching(SRV_TETHERING_TYPE_WIFI_HS);

            if(isTetheringSwitching ||
#ifdef __MMI_OP01_WIFI__     //WIFI  cannot be turned on in flighmode in CMCC project    
                    (!isFlightOFF) ||
#endif
                    isFlightSwitching || m_turningOffTethering)
            {
                // Pop up balloon message when WIFI is not available.
/*
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(
                VCP_INFO_BALLOON_TYPE_INFO,
                VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
*/
                MMI_TRACE(TRACE_GROUP_10, WIFI_CURRENT_NOT_AVAILABLE);
                return;
                
            }
            if(aNewStatus)// turn on wifi
            {
#ifndef __MMI_OP01_WIFI__
                if(!isFlightOFF)
                { // popup flightmode ask.
                    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
                    if(nc)
                    {
                        nc->showPopup(VFX_WSTR_RES(STR_ID_QSETTING_WLAN_IN_FLIGHT_MODE_ASK), IMG_GLOBAL_QUESTION, STR_GLOBAL_YES, STR_GLOBAL_NO, VappNCenter::VAPP_NCENTER_CONFIRM_POPUP);
                    }
                    return;
                }
                else
#endif //__MMI_OP01_WIFI__
                if(!isTetheringOff) // popup tethering  ask.
                {//flight mode and tethering won't turn on at the same time.
                    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
                    if(nc)
                    {
                        nc->showPopup(VFX_WSTR_RES(STR_ID_QSETTING_WLAN_TURN_OFF_HOT_SPOT), IMG_GLOBAL_QUESTION, STR_GLOBAL_YES, STR_GLOBAL_NO, VappNCenter::VAPP_NCENTER_CONFIRM_POPUP);
                    }
                    return;
                }
                else // open wifi directly
                {
                    element->showProcessInd();
                    srv_dtcnt_wlan_init(NULL, NULL);
                }
            }
            else // turn off wifi
            {
                element->showProcessInd();
                srv_dtcnt_wlan_deinit(NULL, NULL);      //turn off wifi
            }
            break;
        }
#endif // __MMI_WLAN_FEATURES__
#ifdef __MMI_BT_SUPPORT__

        case VAPP_QSETTING_BT:
        {
            if (srv_mode_switch_is_switching())
            {
/*
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(
                VCP_INFO_BALLOON_TYPE_INFO,
                VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
*/
                return;
            }
            srv_bt_cm_power_status_enum btStatus = srv_bt_cm_get_power_status();
            if(aNewStatus && SRV_BT_CM_POWER_OFF == btStatus)// turn on BT
            {
                if (!srv_mode_switch_is_network_service_available()) // ZHY: if in flight mode
                {
#ifdef __MMI_BT_IN_FLIGHT_MODE__
                    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
                    if(nc)
                    {
                        nc->showPopup(VFX_WSTR_RES(STR_ID_QSETTING_BT_IN_FLIGHT_MODE_ASK), IMG_GLOBAL_QUESTION, STR_GLOBAL_YES, STR_GLOBAL_NO, VappNCenter::VAPP_NCENTER_CONFIRM_POPUP);
                    }
#else
                    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
                    if(nc)
                    {
                        nc->showPopup(VFX_WSTR_RES(STR_ID_QSETTING_NOT_AVAILABLE), IMG_GLOBAL_FAIL, STR_GLOBAL_OK, NULL, VappNCenter::VAPP_NCENTER_REMIND_POPUP);
                    }
#endif  //__MMI_BT_IN_FLIGHT_MODE__
                    return;
                }
                else
                { // turn on BT directly.
                    srv_bt_cm_switch_on();              
                }
            }
            else if(aNewStatus == 0 && SRV_BT_CM_POWER_ON == btStatus)// turn off BT
            {
                if (srv_bt_cm_get_existed_conn_num() > 0)
                {
                    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
                    if(nc)
                    {
                        nc->showPopup(VFX_WSTR_RES(STR_ID_QSETTING_BT_TURN_OFF_WITH_CONNECTION_CONFIRM), IMG_GLOBAL_QUESTION, STR_GLOBAL_YES, STR_GLOBAL_NO, VappNCenter::VAPP_NCENTER_CONFIRM_POPUP);
                    }
                    return;
                }
                else
                { // turn off BT directly
                    srv_bt_cm_switch_off();
                }
            }
            break;
        }
#endif //__MMI_BT_SUPPORT__
        case VAPP_QSETTING_SILENCE:
        {
            if(aNewStatus)
            {
                srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);
            }
            else
            {
                srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
            }
            break;
        }
        case VAPP_QSETTING_FLIGHT_MODE:
        {
            if (srv_ucm_is_any_call())
            {                
                {
                    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
                    if(nc)
                    {
                        nc->showPopup(VFX_WSTR_RES(STR_ID_QSETTING_BALLOON_IN_CALL), IMG_GLOBAL_FAIL, STR_GLOBAL_OK, NULL, VappNCenter::VAPP_NCENTER_REMIND_POPUP);
                    }
                }
                return;
            }
            if(isFlightSwitching||m_turningOffTethering)
                return;
            element->showProcessInd();

            srv_mode_switch_switch_flight_mode(
                isFlightOFF,
                MMI_TRUE,
                &VappQuickSettingCell::flightEvtHdlr,
                NULL);
            
#ifdef __MMI_WLAN_FEATURES__
            //check if wifi need show progress indicator.
            VfxS32 wifiCurrentStatus = getSrvStatusById(VAPP_QSETTING_WIFI);
            if((isFlightOFF && wifiCurrentStatus) ||
                (!isFlightOFF && srv_dtcnt_wlan_need_init_check() && (wifiCurrentStatus == 0)))
            {
                findElementById(VAPP_QSETTING_WIFI)->showProcessInd();
            }
#endif //__MMI_WLAN_FEATURES__
            break;
        }
        case VAPP_QSETTING_LIGHT:
        { 
            U8 level[4];
            if(aNewStatus > 3)
            {
                return;
            }
            level[0] = SRV_GPIO_BACKLIGHT_MIN_LEVEL;
            level[3] = SRV_GPIO_BACKLIGHT_MAX_LEVEL;
            level[2] = (level[0] + level[3])>>1;
            level[1] = (level[0] + level[2])>>1;
               srv_gpio_setting_set_bl_level(level[aNewStatus], MMI_TRUE);
            break;
        }
        default:
            return;
    }
}


/*---------------------------------------------------------------------------*
 * Function: getCurrentLightIndex()
 * Description: get the current light index of LCD.
 *    @return: return the index of light, 0, 1, 2, or 3
 *---------------------------------------------------------------------------*/
VfxS32 VappQuickSettingCell::getCurrentLightIndex()
{
//local var:
    U8 currentLevel;
    U8 midLevel;
    U8 minLevel;
//func implementation:
    currentLevel = srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD);

    midLevel = (SRV_GPIO_BACKLIGHT_MIN_LEVEL+SRV_GPIO_BACKLIGHT_MAX_LEVEL)/2;
    minLevel = SRV_GPIO_BACKLIGHT_MIN_LEVEL;
    
    if(currentLevel >= SRV_GPIO_BACKLIGHT_MAX_LEVEL)                                        // Max Level
    {
        return 3;
    }
    else if (currentLevel >= midLevel && currentLevel < SRV_GPIO_BACKLIGHT_MAX_LEVEL)   // Mid Level
    {
        return 2;
    }
    else if (currentLevel < midLevel && currentLevel > minLevel)    // Level0
    {
        return 1;
    }
    else                                                                    // min level , without indicator 1,2,3
    {
        return 0;
    }
}

/*---------------------------------------------------------------------------*
 * Function: findElementById()
 * Description: get the element handle by its ID.
 *    @return: return the element handle if found, or NULL.
 *---------------------------------------------------------------------------*/
VappQuickSettingElement* VappQuickSettingCell::findElementById(VfxS32 aElementId)
{
//local var:
    VappQuickSettingElement* tempElement;
//func implementation:
    if( aElementId > 0 && aElementId < VAPP_QSETTING_TOTAL)
        tempElement = m_elementInfo[aElementId - 1].elementHandle;
    else
        tempElement = NULL;
    return tempElement;    
}


/*---------------------------------------------------------------------------*
 * Function: registerEvent()
 * Description: Register events of callback manager.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::registerEvent()
{
//local var:
    VfxObjHandle selfHandle;
//func implementation:
    selfHandle = getObjHandle();
        
#ifdef __MMI_WLAN_FEATURES__
        // WLAN
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND,
        &VappQuickSettingCell::enentHdlr,
        selfHandle);

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND,
        &VappQuickSettingCell::enentHdlr,
        selfHandle);
#endif // __MMI_WLAN_FEATURES__
#ifdef __MMI_BT_SUPPORT__
    // Bluetooth
    VfxU32 eventMask;

    eventMask = SRV_BT_CM_EVENT_ACTIVATE |
                SRV_BT_CM_EVENT_BEGIN_ACTIVATE |
                SRV_BT_CM_EVENT_BEGIN_DEACTIVATE |
                SRV_BT_CM_EVENT_DEACTIVATE;

    m_btSrvHandle = srv_bt_cm_set_notify(
                        &VappQuickSettingCell::btEvtHdlr,
                        eventMask,
                        selfHandle);

#endif // __MMI_BT_SUPPORT__        
    // Silent mode
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_PROF_PROFILE_SWITCHED,
        &VappQuickSettingCell::enentHdlr,
       selfHandle);

    // Flight mode
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY,
        &VappQuickSettingCell::enentHdlr,
        selfHandle);    
}


/*---------------------------------------------------------------------------*
 * Function: createBgImg()
 * Description: create the background image.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::createBgImg(const VfxSize& aBackgroundSize)
{
//local var:
    VfxFrame* backgroundFrame;
    VfxS32 focus_w = (UI_device_width - FOCUS_GAP_X1 - FOCUS_GAP_X2 - (FOCUS_GAP_SEPATATOR * (VAPP_QSETTING_TOTAL - 2))) / (VAPP_QSETTING_TOTAL - 1);
//func implementation:

    //create a background frame, for VRT cash and postion setting.
    VFX_OBJ_CREATE(backgroundFrame,VfxFrame,this);
    backgroundFrame->setSize(aBackgroundSize);
    
    VFX_OBJ_CREATE(m_bgImg,VfxImageFrame,backgroundFrame);
    m_bgImg->setResId(IMG_ID_VAPP_QUICK_SETTING_BG_N);
    m_bgImg->setSize(aBackgroundSize.width - BG_IMGE_WIDTH, BG_IMGE_HEIGHT);
    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImg->setPos(BG_IMG_POS_X, BG_IMG_POS_Y);

    // focus image
    VFX_OBJ_CREATE(m_focusImg, VfxImageFrame, backgroundFrame);
    m_focusImg->setResId(VAPP_IMG_NCENTER_LIST_HIGHLIGHT_BACKGROUND);
    m_focusImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_focusImg->setPos(FOCUS_X, FOCUS_Y);
    m_focusImg->setSize(focus_w,  FOCUS_H);
    setDisplayFocus(VFX_FALSE);
    setFocusIndex(0);
    
    // Separator

    for (VfxS32 i = 1; i < VAPP_QSETTING_TOTAL - 1; i++)
    {
        VfxImageFrame *separator;

        VFX_OBJ_CREATE(separator, VfxImageFrame, backgroundFrame);
        separator->setResId(IMG_ID_VAPP_QUICK_SETTING_LINE);
        separator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        separator->setBounds(VfxRect(0, 0, 2, ELEMENT_HIGHT));
        separator->setPos(
                            5 + (((aBackgroundSize.width -10)/(VAPP_QSETTING_TOTAL - 1))* i), 
                            5
                            );
    }
}


/*---------------------------------------------------------------------------*
 * Function: createElements()
 * Description: create the elements
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::createElements(const VfxSize& aElementSize)
{
//local var:
    VfxS32 width = aElementSize.width;
//func implementation:
    for (VfxS32 i = 0; i < VAPP_QSETTING_TOTAL - 1; i++ )
    {
        VFX_OBJ_CREATE_EX(
                m_elementInfo[i].elementHandle,
                VappQuickSettingElement,
                this,
                (
                    m_elementInfo[i].elementID,
                    ELEMENT_HIGHT,
                    m_elementInfo[i].buttonImage_N, 
                    m_elementInfo[i].buttonImage_H, 
                    m_elementInfo[i].indicatorCount
                )
            );
        m_elementInfo[i].elementHandle->setSize(VfxSize(ELEMENT_HIGHT,ELEMENT_HIGHT));
        m_elementInfo[i].elementHandle->setAnchor(0.5,0);
        m_elementInfo[i].elementHandle->setPos(VfxPoint(
                            5 +((i%5)* width) + (width>>1), 
                            5 + ((i/5)*ELEMENT_HIGHT))
                            );
        m_elementInfo[i].elementHandle->m_imageButton->m_signalClicked.connect(
                                                            this,
                                                            &VappQuickSettingCell::onUserClicked
                                                            );
        m_elementInfo[i].elementHandle->m_imageButton->m_signalStateChanged.connect(
                                                            this,
                                                            &VappQuickSettingCell::onStateChanged
                                                            );
        
        m_elementInfo[i].elementHandle->setIndicator(getSrvStatusById(m_elementInfo[i].elementID));
    }
    
    if(3 == findElementById(VAPP_QSETTING_LIGHT)->getCurrentIndicator())
        m_lightUp = VFX_FALSE;
    else
        m_lightUp = VFX_TRUE;
}

/*---------------------------------------------------------------------------*
 * Function: deregisterEvent()
 * Description: Deregister events of callback manager.
 *---------------------------------------------------------------------------*/
void VappQuickSettingCell::deregisterEvent()
{
//local var:
    VfxObjHandle selfHandle;
//func implementation:
    selfHandle = getObjHandle();
    
#ifdef __MMI_WLAN_FEATURES__

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND,
        (mmi_proc_func)&VappQuickSettingCell::enentHdlr,
        selfHandle);

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND,
        (mmi_proc_func)&VappQuickSettingCell::enentHdlr,
        selfHandle);
#endif //  __MMI_WLAN_FEATURES__    
#ifdef __MMI_BT_SUPPORT__

    // BT
    srv_bt_cm_reset_notify(m_btSrvHandle);
#endif // __MMI_BT_SUPPORT__
    // Slient mode
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_PROF_PROFILE_SWITCHED,
        (mmi_proc_func)&VappQuickSettingCell::enentHdlr,
        selfHandle);

    // Flight mode
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY,
        (mmi_proc_func)&VappQuickSettingCell::enentHdlr,
        selfHandle);
}


/*---------------------------------------------------------------------------*/

/*****************************************************************************
 * Class VappQuickSettingElement implementation
 *****************************************************************************/

/*---------------------------------------------------------------------------*
 * Function: onInit()
 * Description: virtual function from VfxObject, called when create.
 *---------------------------------------------------------------------------*/
void VappQuickSettingElement::onInit()
{ 
//local var:
    VfxImageFrame* frame;
    VfxU32 indicatorPosX;
//func implementation:
    VfxFrame::onInit();
    m_activityInd = NULL;

    //create indicators.
    VFX_OBJ_CREATE(frame, VfxImageFrame, this);
    frame->setResId(IMG_ID_VAPP_QUICK_SETTING_INDICATOR_N);
    indicatorPosX = m_elementWidth>>1;
    frame->setAnchor(0.5, 0);
    frame->setPos(indicatorPosX, INDICATOR_Y);
    m_indicatorImage[m_indicatorCount >> 1] = frame;
    if(3 == m_indicatorCount)
    {
        VFX_OBJ_CREATE(m_indicatorImage[0], VfxImageFrame, this);
        m_indicatorImage[0]->setResId(IMG_ID_VAPP_QUICK_SETTING_INDICATOR_N);
        m_indicatorImage[0]->setAnchor(0.5, 0);
        m_indicatorImage[0]->setPos(indicatorPosX - INDICATOR_PACE, INDICATOR_Y);
        
        VFX_OBJ_CREATE(m_indicatorImage[2], VfxImageFrame, this);
        m_indicatorImage[2]->setResId(IMG_ID_VAPP_QUICK_SETTING_INDICATOR_N);
        m_indicatorImage[2]->setAnchor(0.5, 0);
        m_indicatorImage[2]->setPos(indicatorPosX + INDICATOR_PACE, INDICATOR_Y);
    }

    //create image button.
    VFX_OBJ_CREATE(m_imageButton, VcpImageButton, this);
    m_imageButton->setImage(VcpStateImage(m_buttonImageId[0]));
    m_imageButton->setBounds(VfxRect(0, 0, BTN_BOUNDS_X, BTN_BOUNDS_Y));

    m_imageButton->setIsEffect(VFX_TRUE);
    m_imageButton->setEffectSize(VfxSize(EFFECT_W, EFFECT_H));
    m_imageButton->setId(m_elementId);
    m_imageButton->setAnchor(0.5, 0);
    m_imageButton->setPos(m_elementWidth>>1, BTN_Y);
}

/*---------------------------------------------------------------------------*
 * Function: setIndicator()
 * Description: set the current indicator index.
 *---------------------------------------------------------------------------*/
void VappQuickSettingElement::setIndicator(VfxU32 aIndicatorCont)
{ 
//local var:
    VfxU32 i;
//func implementation:
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_SET_INDICATOR, aIndicatorCont);

    if(aIndicatorCont <= m_indicatorCount)
    {
        if(m_currentIndex > 0 && aIndicatorCont == 0)
        {
            m_imageButton->setImage(VcpStateImage(m_buttonImageId[0]));
            m_imageButton->setIsHighlight(VFX_FALSE);
        }
        else if(m_currentIndex == 0 && aIndicatorCont > 0)
        {
            m_imageButton->setImage(VcpStateImage(m_buttonImageId[1]));
            m_imageButton->setIsHighlight(VFX_TRUE);
        }
            
        m_currentIndex = aIndicatorCont;
        for(i=0; i < m_indicatorCount; i++)
        {
            if(i < aIndicatorCont)
                m_indicatorImage[i]->setResId(IMG_ID_VAPP_QUICK_SETTING_INDICATOR_H);
            else
                m_indicatorImage[i]->setResId(IMG_ID_VAPP_QUICK_SETTING_INDICATOR_N);                
        }
    }
    cancelProcessInd();
}


/*---------------------------------------------------------------------------*
 * Function: increaseIndicator()
 * Description: add (+1) to current indicator index.
 *---------------------------------------------------------------------------*/
void VappQuickSettingElement::increaseIndicator()
{
//local var:
    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
    VappNCenterScr *scr = nc->getNCenterScr();

//func implementation:
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_INCREASE_INDICATOR);
    if(m_currentIndex < m_indicatorCount)
    {
        if(m_currentIndex == 0)
        {
            m_imageButton->setImage(VcpStateImage(m_buttonImageId[1]));
            m_imageButton->setIsHighlight(VFX_TRUE);
        }
        m_indicatorImage[m_currentIndex]->setResId(IMG_ID_VAPP_QUICK_SETTING_INDICATOR_H);
        m_currentIndex++;
        cancelProcessInd();
        nc->setQuickSettingSoftkey();
    }
}

/*---------------------------------------------------------------------------*
 * Function: decreaseIndicator()
 * Description: add (-1) to currnet indicator index.
 *---------------------------------------------------------------------------*/
void VappQuickSettingElement::decreaseIndicator()
{
//local var:
    VappNCenter* nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
    VappNCenterScr *scr = nc->getNCenterScr();

//func implementation:
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_DECREASE_INDICATOR);
    if(m_currentIndex > 0)
    {
        m_indicatorImage[m_currentIndex - 1]->setResId(IMG_ID_VAPP_QUICK_SETTING_INDICATOR_N);
        m_currentIndex--;
        if(0 == m_currentIndex)
        {
            m_imageButton->setImage(VcpStateImage(m_buttonImageId[0]));
            m_imageButton->setIsHighlight(VFX_FALSE);
        }
        cancelProcessInd();
        nc->setQuickSettingSoftkey();
    }
}


 /*---------------------------------------------------------------------------*
 * Function: getCurrentIndicator()
 * Description: get the current indicator index.
 *---------------------------------------------------------------------------*/
VfxU32 VappQuickSettingElement::getCurrentIndicator() const
{
//local var:
    
//func implementation:
    return m_currentIndex;
}


/*---------------------------------------------------------------------------*
 * Function: getId()
 * Description: get the element ID
 *    @return: return the ID of the element.
 *---------------------------------------------------------------------------*/
VfxS32 VappQuickSettingElement::getId() const
{
//local var:
    
//func implementation:
    return m_elementId;
}

/*---------------------------------------------------------------------------*
 * Function: showProcessInd()
 * Description: show process indicator animation.
 *---------------------------------------------------------------------------*/
void VappQuickSettingElement::showProcessInd()
{
//local var:
    
//func implementation:
    if(!m_activityInd)
    {
        VFX_OBJ_CREATE(m_activityInd, VcpWaitingIcon, this);
        m_activityInd->setAnchor(0.5, 0.5);
        m_activityInd->setPos((getSize().width)>>1, (getSize().height)>>1);
        m_activityInd->start();
        m_imageButton->setIsEffect(VFX_FALSE);
    }
}

/*---------------------------------------------------------------------------*
 * Function: cancelProcessInd()
 * Description: stop process indicator animation.
 *---------------------------------------------------------------------------*/
void VappQuickSettingElement::cancelProcessInd()
{
//local var:
    
//func implementation:
    if(m_activityInd)
    {
        VFX_OBJ_CLOSE(m_activityInd);
        m_imageButton->setIsEffect(VFX_TRUE);
    }
}

/*---------------------------------------------------------------------------*
 * Function: isEnable()
 * Description: 
 *    @return: return VFX_TURE if can be clicked
 *---------------------------------------------------------------------------*/
VfxBool VappQuickSettingElement::isEnable()
{
//local var:
    
//func implementation:
    if(m_activityInd)
    {
        return VFX_FALSE;
    }
    else 
    {
        return VFX_TRUE;
    }
}

/*---------------------------------------------------------------------------*/

#endif //__MMI_NCENTER_NATIVE_WIDGET_SUPPORT__
//End of File 

