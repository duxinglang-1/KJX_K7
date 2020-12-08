
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
 *  vapp_widget_quick_switch.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements quick switch widget.
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_QUICK_SWITCH__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_quick_switch.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_widget_quick_switch_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "vapp_sound_settings_gprot.h"
#include "vcp_confirm_popup.h"

/* Pluto MMI headers */
extern "C"
{
#include "dtcntsrviprot.h"      //WLAN
#include "dtcntsrvgprot.h"      //WLAN
#include "ProfilesSrvGprot.h"   //slient mode &WLAN
#include "BtcmSrvGprot.h"       //BT
#include "GpioSrvGprot.h"       //brightness
#include "GpioSrvProt.h"        //brightness
#include "ModeSwitchSrvGprot.h" //flightmode
#include "UcmSrvGprot.h"        //check incoming call
}

/*****************************************************************************
 * Define
 *****************************************************************************/
#if defined (__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
#endif
    
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}

#define QSW_MEASURE_TIME_START(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define QSW_MEASURE_TIME_STOP(_symbol_)  SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define QSW_MEASURE_TIME_START(_symbol_)
#define QSW_MEASURE_TIME_STOP(_symbol_)
#endif

#ifdef __MMI_OP01_WIFI__
#include "vcui_dtcnt_wlan_gprot.h"
#endif /* __MMI_OP01_WIFI*/

/*****************************************************************************
 * Quick Switch Widget
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetQuickSwitch,
    VAPP_WIDGET_TYPE_QUICK_SWITCH,
    VappWidgetQuickSwitchPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetQuickSwitch, VappWidget);

VappWidgetQuickSwitch::VappWidgetQuickSwitch() :
    m_bgImg(NULL),
    m_indicatorWifi(NULL),
    m_indicatorBt(NULL),
    m_indicatorSilent(NULL),
    m_indicatorFlight(NULL),
    m_indicatorMin(NULL),
    m_indicatorMid(NULL),
    m_indicatorMax(NULL),
    m_buttonWifi(NULL),
    m_buttonBt(NULL),
    m_buttonSilent(NULL),
    m_buttonFlight(NULL),
    m_buttonBrightness(NULL),
    m_flightBtnStatus(VFX_TRUE),
    m_wifiBtnStatus(VFX_TRUE),
    m_btSrvHandle(-1),
    m_lastLevel(0),    
    m_confirmPopup(NULL),
    m_confirmFlag(0),
    m_btIndicator(NULL),
    m_fightModeIndicator(NULL)
{
    // Do nothing.
}


VappWidgetId VappWidgetQuickSwitch::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_QUICK_SWITCH);
}


VfxSize VappWidgetQuickSwitch::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetQuickSwitch::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_QUICK_SWITCH);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetQuickSwitch::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_ICON);
    return icon;
}


void VappWidgetQuickSwitch::onCreateView()
{
    QSW_MEASURE_TIME_START("QCR");

    VappWidget::onCreateView();


    // Initial UI componment
    initialUI();

    // Register Event handler
    registerEvent();

    // Update button status
    updateStatus();
    
    // Initialize & acquire the backlight indicator status
    getCurrentLightLevel();

    QSW_MEASURE_TIME_STOP("QCR");
}


void VappWidgetQuickSwitch::onReleaseView()
{
    QSW_MEASURE_TIME_START("QRL");

    // Release UI componment
    releaseUI();    

    // Deregister events
    deregisterEvent();

    VappWidget::onReleaseView();
    
    QSW_MEASURE_TIME_STOP("QRL");    
}


void VappWidgetQuickSwitch::initialUI()
{
    VfxSize bgImgSize(BG_WIDTH, BG_HEIGHT);

    setSize(bgImgSize);

    // Background Image.
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
	m_bgImg->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BG_N);
    m_bgImg->setSize(bgImgSize);
    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // Separator
    for (VfxS32 i = 0; i < SEPARATOR_NUM; i++ )
    {
        VfxImageFrame *separator;

        VFX_OBJ_CREATE(separator, VfxImageFrame, m_bgImg);
        separator->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_LINE);
        separator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        separator->setBounds(VfxRect(0, 0, SEPARATOR_BOUNDS_X, SEPARATOR_BOUNDS_Y));
        separator->setPos(getSeparatorPos(bgImgSize, i+1));
    }

    // Indicator
    VFX_OBJ_CREATE(m_indicatorWifi, VfxImageFrame, this);          //WIFI
    m_indicatorWifi->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    m_indicatorWifi->setPos(INDICATOR_WIFI_X, INDICATOR_Y);

    VFX_OBJ_CREATE(m_indicatorBt, VfxImageFrame, this);             //BT 
    m_indicatorBt->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    m_indicatorBt->setPos(INDICATOR_BT_X, INDICATOR_Y);

    VFX_OBJ_CREATE(m_indicatorSilent, VfxImageFrame, this);         //Silent
    m_indicatorSilent->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    m_indicatorSilent->setPos(INDICATOR_SILENT_X, INDICATOR_Y);

    VFX_OBJ_CREATE(m_indicatorFlight, VfxImageFrame, this);         //Flight
    m_indicatorFlight->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    m_indicatorFlight->setPos(INDICATOR_FLIGHT_X, INDICATOR_Y);

    VFX_OBJ_CREATE(m_indicatorMin, VfxImageFrame, this);            //Backlight Min
    m_indicatorMin->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    m_indicatorMin->setPos(INDICATOR_MIN_X, INDICATOR_Y);

    VFX_OBJ_CREATE(m_indicatorMid, VfxImageFrame, this);            //Backlight Mid
    m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    m_indicatorMid->setPos(INDICATOR_MID_X, INDICATOR_Y);

    VFX_OBJ_CREATE(m_indicatorMax, VfxImageFrame, this);            //Backlight Max
    m_indicatorMax->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    m_indicatorMax->setPos(INDICATOR_MAX_X, INDICATOR_Y);

    // Create Buttons
    VFX_OBJ_CREATE(m_buttonWifi, VcpImageButton, this);       // Wifi
    m_buttonWifi->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_N));
    m_buttonWifi->setBounds(VfxRect(0, 0, BTN_BOUNDS_X, BTN_BOUNDS_Y));
    m_buttonWifi->setPos(VfxPoint(BTN_WIFI_X, BTN_Y));
    m_buttonWifi->setIsEffect(VFX_TRUE);
    m_buttonWifi->setEffectSize(VfxSize(EFFECT_W, EFFECT_H));
    m_buttonWifi->m_signalClicked.connect(this, &VappWidgetQuickSwitch::onWifiBtnClicked);

    VFX_OBJ_CREATE(m_buttonBt, VcpImageButton, this);         // BT
    m_buttonBt->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BT_N));
    m_buttonBt->setBounds(VfxRect(0, 0, BTN_BOUNDS_X, BTN_BOUNDS_Y));
    m_buttonBt->setPos(VfxPoint(BTN_BT_X, BTN_Y));
    m_buttonBt->setIsEffect(VFX_TRUE);
    m_buttonBt->setEffectSize(VfxSize(EFFECT_W, EFFECT_H));
    m_buttonBt->m_signalClicked.connect(this, &VappWidgetQuickSwitch::onBtBtnClicked);

    VFX_OBJ_CREATE(m_buttonSilent, VcpImageButton, this);     // Silent
    m_buttonSilent->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_N));
    m_buttonSilent->setBounds(VfxRect(0, 0, BTN_BOUNDS_X, BTN_BOUNDS_Y));
    m_buttonSilent->setPos(VfxPoint(BTN_SILENT_X, BTN_Y));
    m_buttonSilent->setIsEffect(VFX_TRUE);
    m_buttonSilent->setEffectSize(VfxSize(EFFECT_W, EFFECT_H));
    m_buttonSilent->m_signalClicked.connect(this, &VappWidgetQuickSwitch::onSilentBtnClicked);

    VFX_OBJ_CREATE(m_buttonFlight, VcpImageButton, this);      // Flight
    m_buttonFlight->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_FLIGHT_N));
    m_buttonFlight->setBounds(VfxRect(0, 0, BTN_BOUNDS_X, BTN_BOUNDS_Y));
    m_buttonFlight->setPos(VfxPoint(BTN_FLIGHT_X, BTN_Y));
    m_buttonFlight->setIsEffect(VFX_TRUE);
    m_buttonFlight->setEffectSize(VfxSize(EFFECT_W, EFFECT_H));
    m_buttonFlight->m_signalClicked.connect(this, &VappWidgetQuickSwitch::onFlightBtnClicked);

    VFX_OBJ_CREATE(m_buttonBrightness, VcpImageButton, this);  // Brightness
    m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H));
    m_buttonBrightness->setBounds(VfxRect(0, 0, BTN_BOUNDS_X, BTN_BOUNDS_Y));
    m_buttonBrightness->setPos(VfxPoint(BTN_BRIGHTNESS_X, BTN_Y));
    m_buttonBrightness->setIsEffect(VFX_TRUE);
    m_buttonBrightness->setEffectSize(VfxSize(EFFECT_W, EFFECT_H));
    m_buttonBrightness->m_signalClicked.connect(this, &VappWidgetQuickSwitch::onBrightnessBtnClicked);

    // Create BT activity indicator
    VFX_OBJ_CREATE(m_btIndicator, VcpActivityIndicator, this);

    // Sets the position of activity indicator.
    m_btIndicator->setAnchor(0.0F, 0.0F);
    m_btIndicator->setBounds(m_buttonBt->getBounds());
    m_btIndicator->setPos(m_buttonBt->getPos().x, m_buttonBt->getPos().y);
    m_btIndicator->setIsUnhittable(VFX_TRUE);

    // Create flight mode activity Indicator
    VFX_OBJ_CREATE(m_fightModeIndicator, VcpActivityIndicator, this);

    // Sets the position of activity indicator.
    m_fightModeIndicator->setAnchor(0.0F, 0.0F);
    m_fightModeIndicator->setBounds(m_buttonBt->getBounds());
    m_fightModeIndicator->setPos(m_buttonFlight->getPos().x, m_buttonFlight->getPos().y);
    m_fightModeIndicator->setIsUnhittable(VFX_TRUE);
}


void VappWidgetQuickSwitch::releaseUI()
{
    VFX_OBJ_CLOSE(m_bgImg);
    VFX_OBJ_CLOSE(m_indicatorWifi);
    VFX_OBJ_CLOSE(m_indicatorBt);
    VFX_OBJ_CLOSE(m_indicatorSilent);
    VFX_OBJ_CLOSE(m_indicatorFlight);
    VFX_OBJ_CLOSE(m_indicatorMin);
    VFX_OBJ_CLOSE(m_indicatorMid);
    VFX_OBJ_CLOSE(m_indicatorMax);
    VFX_OBJ_CLOSE(m_buttonWifi);
    VFX_OBJ_CLOSE(m_buttonBt);
    VFX_OBJ_CLOSE(m_buttonSilent);
    VFX_OBJ_CLOSE(m_buttonFlight);
    VFX_OBJ_CLOSE(m_buttonBrightness);
    VFX_OBJ_CLOSE(m_btIndicator);
    VFX_OBJ_CLOSE(m_fightModeIndicator);
}


void VappWidgetQuickSwitch::onSerializeView(VfxArchive *ar)
{
    // Release UI componment
    releaseUI();
    
}

void VappWidgetQuickSwitch::onRestoreView(VfxArchive *ar)
{
    QSW_MEASURE_TIME_START("QRS");

    // Restore UI componment, since it's been release on onSerializeView
    initialUI();
    
    // Update button status
    // Scenario: Home->Dailer->NCenter->tap flight mode button in NCenter.
    //           The UI componment will be release while enter dailer.
    //           So, we need to update status in restore view.
    updateStatus();

    // Acquire current backlight level.
    getCurrentLightLevel();
    
    QSW_MEASURE_TIME_START("QRS");
}


VfxPoint VappWidgetQuickSwitch::onGetEditButtonOffset()
{
    return VfxPoint(getSize().width - EDIT_BTN_OFFSET_X, EDIT_BTN_OFFSET_Y);
}


void VappWidgetQuickSwitch::onWifiBtnClicked(VfxObject *sender, VfxId id)
{

    // Check if there is WIFI-tethering availabe.
    MMI_BOOL isTetheringOff = srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS);

    // Check if  tetghering is switching, the switching might take quite long time in some case.
    MMI_BOOL isTetheringSwitching = srv_tethering_is_switching(SRV_TETHERING_TYPE_WIFI_HS);
    
    //Check if flight mode is switching.
    MMI_BOOL isFlightSwitching = srv_mode_switch_is_switching();
    
    #ifdef __MMI_OP01_WIFI__     //WIFI  cannot be turned on in flighmode in CMCC project    
    if(isTetheringSwitching || m_flightBtnStatus || isFlightSwitching)
    {
        m_wifiBtnStatus = VFX_FALSE;
    }
    else
    {
        m_wifiBtnStatus = VFX_TRUE;    
    }
    #else                        //WIFI can be turned on in flightmode in default project    
        if(isTetheringSwitching || isFlightSwitching)
        {
            m_wifiBtnStatus = VFX_FALSE;
        }
        else
        {
            m_wifiBtnStatus = VFX_TRUE;
        }
     #endif    

    // Pop up balloon message when WIFI is not available.
    if(m_wifiBtnStatus == FALSE)
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(
            VCP_INFO_BALLOON_TYPE_INFO,
            VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
    }
    else
    {
        //flight mode and tethering won't turn on at the same time.
        //turn on wifi (in the stauts of flight mode on and wifi off)
        if (m_flightBtnStatus && (SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status()))
        {
            m_confirmFlag = VAPP_WIFI_ON_CONFIRM;
            showConfirmScreen();
        }
        else
        {
            if (isTetheringOff) //WIFI tethering is OFF
            {
                if(SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE == srv_dtcnt_wlan_switch_state())
                {
                    srv_dtcnt_wlan_init(NULL, NULL);   //turn on wifi
                    m_buttonWifi->setIsHighlight(VFX_TRUE);
                }
                else
                {
                    #ifdef __MMI_OP01_WIFI__
                        vapp_wlan_send_cmcc_deinit();
                    #else
                        srv_dtcnt_wlan_deinit(NULL, NULL);    //turn off wifi
                    #endif /* __MMI_OP01_WIFI__ */
                    m_buttonWifi->setIsHighlight(VFX_FALSE);
                }
            }
            else                //WIFI tethering is ON
            {
                m_confirmFlag = VAPP_TETHERING_ON_CONFIRM;
                showConfirmScreen();
            }
        }
    }
}


void VappWidgetQuickSwitch::onBtBtnClicked(VfxObject *sender, VfxId id)
{
    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)     // turn on BT
    {
        //show popup warning when trun on BT in flight mode
        if (srv_mode_switch_is_network_service_available() == MMI_FALSE)      //flight mode status is on
        {
            m_confirmFlag = VAPP_BT_POWER_ON_CONFIRM;
            showConfirmScreen();
         }     
        else                                                                  //flight mode status is off
    {
        srv_bt_cm_switch_on();
        showLoading(m_btIndicator);

        }
    }
    else                                                          //turn off BT 
    {
        //show popup warning message if  turn off BT with live connection.
        if (srv_bt_cm_get_existed_conn_num() > 0)
        {
            m_confirmFlag = VAPP_BT_POWER_OFF_CONFIRM;
            showConfirmScreen();
        }
        else
        {
        srv_bt_cm_switch_off();
        }
    }
}


void VappWidgetQuickSwitch::showConfirmScreen(void)
{
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);

    switch (m_confirmFlag)
    {
        case VAPP_BT_POWER_ON_CONFIRM:
            m_confirmPopup->setText(STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_IN_FLIGHT_MODE_ASK);
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_confirmPopup->setCustomButton(
            STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_TURN_ON,
            STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
        break;
        
        case VAPP_BT_POWER_OFF_CONFIRM:
            m_confirmPopup->setText(STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_OFF_WITH_CONNECTION);
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_confirmPopup->setCustomButton(
                STR_ID_VAPP_WIDGET_QUICK_SWITCH_BT_TURN_OFF,
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
        break;
        
        case VAPP_TETHERING_ON_CONFIRM:
            // show confirm popup to turn off wifi tethering
            m_confirmPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_confirmPopup->setCustomButton (
                STR_GLOBAL_OK, 
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_confirmPopup->setInfoType (VCP_POPUP_TYPE_QUESTION);
            m_confirmPopup->setText (STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_OFF_HOT_SPOT);
        break;
        
        case VAPP_WIFI_ON_CONFIRM:
            // show confirm pop up to turn on WLAN in flight mode.
            m_confirmPopup->setText(STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_ON_CONFIRM);
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_confirmPopup->setCustomButton(
                STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN,
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
        break;
    }

    m_confirmPopup->m_signalButtonClicked.connect(this,&VappWidgetQuickSwitch::onConfirmClicked);
    m_confirmPopup->show(VFX_TRUE);   
}


void VappWidgetQuickSwitch::onConfirmClicked(VfxObject* sender, VfxU32 id)
{

    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:

            switch (m_confirmFlag)
            {
                case VAPP_BT_POWER_ON_CONFIRM:
                    showLoading(m_btIndicator);
                    srv_bt_cm_switch_on();

                break;

                case VAPP_BT_POWER_OFF_CONFIRM:
                    srv_bt_cm_switch_off();
                break;

                case VAPP_TETHERING_ON_CONFIRM:
                    // Stop Wi-Fi tethering
                    srv_tethering_stop (SRV_TETHERING_TYPE_WIFI_HS, afterStopTethering, getObjHandle());
                break;

                case VAPP_WIFI_ON_CONFIRM:
                    //turn on WLAN on flight mode
                    srv_dtcnt_wlan_init(NULL, NULL);   //turn on wifi
                    m_buttonWifi->setIsHighlight(VFX_TRUE);
                break;
}

        break;

        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        break;
    }
m_confirmPopup = NULL;
}


void VappWidgetQuickSwitch::onSilentBtnClicked(VfxObject *sender, VfxId id)
{
    if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
    {
        srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);
        m_indicatorSilent->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_buttonSilent->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_H));
    }
    else
    {
        srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
        m_indicatorSilent->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonSilent->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_N));
    }
    vapp_sound_settings_update_status_icon();
}


void VappWidgetQuickSwitch::onFlightBtnClicked(VfxObject *sender, VfxId id)
{
    showLoading(m_fightModeIndicator);
    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)       //turn on
    {
        // Flight mode is not workable during the call.
        if (srv_ucm_is_any_call())
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
            return;
        }
        else
    {
        srv_mode_switch_switch_flight_mode(
            MMI_TRUE,
            MMI_TRUE,
            &VappWidgetQuickSwitch::flightEvtHdlr,
            getObjHandle());
        m_flightBtnStatus = VFX_TRUE;
        m_wifiBtnStatus =VFX_FALSE;
    }
    }
    else if (srv_mode_switch_is_network_service_available() == MMI_FALSE) //turn off
    {
        srv_mode_switch_switch_flight_mode(
            MMI_FALSE,
            MMI_TRUE,
            &VappWidgetQuickSwitch::flightEvtHdlr,
            getObjHandle());
        m_flightBtnStatus = VFX_FALSE;
        m_wifiBtnStatus =VFX_TRUE;
    }
}


void VappWidgetQuickSwitch::onBrightnessBtnClicked(VfxObject *sender, VfxId id)
{
    m_currentLevel = srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD);

    // increasing level
    if (m_currentLevel <  m_maxLevel && m_lastLevel != m_maxLevel &&
		m_lastLevel    >= m_minLevel && m_lastLevel != m_midLevel || 
		m_currentLevel == m_minLevel )
    {
        if (m_currentLevel == m_minLevel)                                      //min stage -> level0
        {
            m_indicatorMin->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
            m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H));
            srv_gpio_setting_set_bl_level(m_level0, MMI_TRUE);
			m_lastLevel = m_level0;
        }
        else if (m_currentLevel > m_minLevel && m_currentLevel < m_midLevel )  // level0  -> mid_level 
        {
            m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
            m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H));            
            srv_gpio_setting_set_bl_level(m_midLevel, MMI_TRUE);
        }
        else if (m_currentLevel >=m_midLevel )                                 // mid_level -> max_level
        {
            m_indicatorMax->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
            m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H));            
            srv_gpio_setting_set_bl_level(m_maxLevel, MMI_TRUE);
            m_lastLevel=m_midLevel;
			m_currentLevel=srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD);
        }
    }
    
    //decreasing level
    else if(m_currentLevel <= m_maxLevel && m_currentLevel > m_midLevel)       // max mode:max -> mid
    {
        if (m_currentLevel== m_maxLevel)
        {
            m_indicatorMax->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);   //max->mid
            srv_gpio_setting_set_bl_level(m_midLevel,MMI_TRUE);
            m_lastLevel=m_maxLevel;
    }
        else if (m_currentLevel < m_maxLevel)
        {
            m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);   //mid->level0
            srv_gpio_setting_set_bl_level(m_level0,MMI_TRUE);
            m_lastLevel=m_midLevel;
        }

    }
    else if (m_currentLevel <= m_midLevel &&
             m_lastLevel == m_maxLevel ||
             m_currentLevel == m_lastLevel)                                     // mid->level0
    {
            m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
            srv_gpio_setting_set_bl_level(m_level0,MMI_TRUE);
            m_lastLevel=m_midLevel;
           
    }
    else if(m_currentLevel <= m_level0 && m_lastLevel == m_midLevel)            // level0->min
    {
        m_indicatorMin->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_N));
        srv_gpio_setting_set_bl_level(m_minLevel,MMI_TRUE);
        m_lastLevel = m_level0;
    }
}


void VappWidgetQuickSwitch::updateStatus()
{

    //Check Wifi mode status.
    if(SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE == srv_dtcnt_wlan_switch_state())
    {
        m_indicatorWifi->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonWifi->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_N));
    }
    else
    {
        m_indicatorWifi->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_buttonWifi->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_H));
    }

    //Check BT mode status.
    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
    {
        m_indicatorBt->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_buttonBt->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BT_H));
    }
    else
    {
        m_indicatorBt->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonBt->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BT_N));        
    }    

    //Check silent mode status.
    if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
    {
        m_indicatorSilent->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
    }
    else
    {
        m_indicatorSilent->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_buttonSilent->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_H));
    }

    //Check flight mode status.
    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
    {
        m_indicatorFlight->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonFlight->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_FLIGHT_N));
        m_flightBtnStatus = VFX_FALSE;
    }
    else if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        m_indicatorFlight->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_buttonFlight->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_FLIGHT_H));
        m_wifiBtnStatus =VFX_FALSE; //if flight mode turned on before launch quick switch.
        m_flightBtnStatus = VFX_TRUE;
    }    
}


void VappWidgetQuickSwitch::afterStopTethering(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{

    //The callback function after wifi tethering has been stopped.
    //MAUI_03021563: It takes around 1mins to close tethering while in calling status.
    VappWidgetQuickSwitch *widget = 
        (VappWidgetQuickSwitch*)VfxObject::handleToObject((VfxObjHandle)user_data);

    //Check Wi-Fi_status 
        if(SRV_DTCNT_WLAN_SWITCH_STATE_CLOSE == srv_dtcnt_wlan_switch_state())
        {
            srv_dtcnt_wlan_init(NULL, NULL);
            //TODO: use wlanEvtHandle to set images
            widget->m_indicatorWifi->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
            widget->m_buttonWifi->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_H));
            widget->m_buttonWifi->setIsHighlight(VFX_TRUE);
        }
        else
        {
            #ifdef __MMI_OP01_WIFI__
                vapp_wlan_send_cmcc_deinit();
            #else
                srv_dtcnt_wlan_deinit(NULL, NULL);
            #endif /* __MMI_OP01_WIFI__ */

            widget->m_indicatorWifi->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
            widget->m_buttonWifi->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_N));
            widget->m_buttonWifi->setIsHighlight(VFX_FALSE);
        }

}


mmi_ret VappWidgetQuickSwitch::wlanEvtHandle(mmi_event_struct* param)
{
    VappWidgetQuickSwitch *widget = 
        (VappWidgetQuickSwitch*)VfxObject::handleToObject((VfxObjHandle)param->user_data);

    // Do not update widget status while it has been serialized.
    if(widget == NULL || widget->isSerialized())
    {
        return MMI_RET_OK;
    }
    
    switch(param->evt_id)
    {
        //WLAN on event.
        case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND:
            VappWidgetQuickSwitch::responseInitEvent(param);
            break;
            
        //WLAN off event.
        case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
            VappWidgetQuickSwitch::responseDeinitEvent(param);
            break;
    }
    return MMI_RET_OK;
}


void VappWidgetQuickSwitch::responseInitEvent(mmi_event_struct* param)
{

    //WLAN on event.

    srv_dtcnt_wlan_init_res_ind_evt_struct* evt =
        (srv_dtcnt_wlan_init_res_ind_evt_struct *)param;
    
    VappWidgetQuickSwitch *widget = 
        (VappWidgetQuickSwitch*)VfxObject::handleToObject((VfxObjHandle)param->user_data);    

    // use switch case for further check afterwards.
    switch (evt->res)
    {
        //turn on successfuly
        case SRV_DTCNT_WLAN_REQ_RES_DONE:
            widget->m_buttonWifi->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_H));
            widget->m_indicatorWifi->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
            break;
            
        //either terminated or duplicated or failed.
        default:
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(
                VCP_INFO_BALLOON_TYPE_INFO,
                VFX_WSTR_RES(STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_ON_FAILED));
            return;
            break;
    }
}


void VappWidgetQuickSwitch::responseDeinitEvent(mmi_event_struct* param)
{
    //WLAN off event.
    srv_dtcnt_wlan_deinit_res_ind_evt_struct* evt = 
        (srv_dtcnt_wlan_deinit_res_ind_evt_struct*) param;
    
    VappWidgetQuickSwitch *widget = 
        (VappWidgetQuickSwitch*)VfxObject::handleToObject((VfxObjHandle)param->user_data);     

    // use switch case for further check afterwards.
    switch (evt->res)
    {
	    case SRV_DTCNT_WLAN_REQ_RES_DONE:
            widget->m_buttonWifi->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_WIFI_N));
            widget->m_indicatorWifi->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
            break;
            
        //either terminated or duplicated or failed.
        default:
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(
                VCP_INFO_BALLOON_TYPE_INFO,
                VFX_WSTR_RES(STR_ID_VAPP_WIDGET_QUICK_SWITCH_WLAN_OFF_FAILED));
            return;
            break;
    }
}


mmi_ret VappWidgetQuickSwitch::onProc(mmi_event_struct *evt)
{
    VappWidgetQuickSwitch *widget = 
        (VappWidgetQuickSwitch*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);

    // Do not update widget status while it has been serialized.
    if(widget == NULL || (widget->isSerialized()))
    {
        return MMI_RET_OK;
    }

    switch(evt->evt_id)
    {
        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:           // Flight event
        {
            srv_mode_switch_notify_struct *notify_evt = (srv_mode_switch_notify_struct *)evt;

            if (notify_evt->curr_flight_mode == SRV_MODE_SWITCH_ON &&
                notify_evt->select_flight_mode == SRV_MODE_SWITCH_OFF)
            {
                widget->m_indicatorFlight->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
                widget->m_buttonFlight->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_FLIGHT_N));
                widget->m_wifiBtnStatus =VFX_TRUE;
                widget->m_flightBtnStatus = VFX_FALSE;
            }
            else if (notify_evt->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
                     notify_evt->select_flight_mode == SRV_MODE_SWITCH_ON)
            {
                widget->m_indicatorFlight->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
                widget->m_buttonFlight->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_FLIGHT_H));
                widget->m_wifiBtnStatus = VFX_FALSE;
                widget->m_flightBtnStatus = VFX_TRUE;                
            }
            widget->hideLoading(widget->m_fightModeIndicator);
            widget->hideLoading(widget->m_btIndicator);  
            break;
        }

        case EVT_ID_SRV_PROF_PROFILE_SWITCHED:                // Silent event
        {
            if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_NOT_ACTIVATED)
            {
                widget->m_indicatorSilent->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
                widget->m_buttonSilent->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_N));
            }
            else
            {
                widget->m_indicatorSilent->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
                widget->m_buttonSilent->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_SILENT_H));
            }

            vapp_sound_settings_update_status_icon();

            break;
        }

        case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
        {
            // When BT turned off by flight mode, once flight mode turned off,
            // it will restore (turn on) BT, and therefore it needs to show activity indicator.
            // show the ind if BT is switching.
            
        	srv_bt_cm_power_status_enum btPowerStatus = srv_bt_cm_get_power_status();

        	if(btPowerStatus == SRV_BT_CM_POWER_SWITCHING_ON ||
               btPowerStatus == SRV_BT_CM_POWER_SWITCHING_OFF)
            {
                widget->showLoading(widget->m_btIndicator);
            }

	    break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


void VappWidgetQuickSwitch::registerEvent()
{
    // WLAN _INIT
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND, 
        VappWidgetQuickSwitch::wlanEvtHandle, 
        getObjHandle());
    
    // WLAN _DEINIT    
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND, 
        VappWidgetQuickSwitch::wlanEvtHandle, 
        getObjHandle());

    // Bluetooth
    VfxU32 eventMask;

    eventMask = SRV_BT_CM_EVENT_ACTIVATE |
                SRV_BT_CM_EVENT_DEACTIVATE |
                SRV_BT_CM_EVENT_CONNECT_RES |
                SRV_BT_CM_EVENT_DISCONNECT_IND |
                SRV_BT_CM_EVENT_RELEASE_ALL_CONN;

    m_btSrvHandle = srv_bt_cm_set_notify(
                        VappWidgetQuickSwitch::btEvtHdlr,
                        eventMask,
                        getObjHandle());
        
    // Silent mode
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_PROF_PROFILE_SWITCHED,
        VappWidgetQuickSwitch::onProc,
        getObjHandle());

    // Flight mode
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY,
        VappWidgetQuickSwitch::onProc,
        getObjHandle());

    // Backlight level updated
    mmi_frm_cb_reg_event(
        EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE,
        VappWidgetQuickSwitch::onProc,
        getObjHandle());    

    // The use of event before BT is switching.
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY,
        VappWidgetQuickSwitch::onProc,
        getObjHandle());
}


void VappWidgetQuickSwitch::btEvtHdlr(U32 event, void *para)
{
    // Get object's pointer.
    srv_bt_cm_activate_struct *res = (srv_bt_cm_activate_struct *)para;
    VappWidgetQuickSwitch *widget = (VappWidgetQuickSwitch *)VfxObject::handleToObject((VfxObjHandle)res->user_data);

    // Do not update widget status while it has been serialized.
    if (!widget || widget->isSerialized() || widget->m_confirmPopup)
    {
        VFX_OBJ_CLOSE(widget->m_confirmPopup);
        return;
    }

    switch(event)
    {
        case SRV_BT_CM_EVENT_ACTIVATE:
        {
            widget->m_indicatorBt->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
            widget->m_buttonBt->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BT_H));
            widget->hideLoading(widget->m_btIndicator);

            if(widget->m_confirmFlag == VAPP_BT_POWER_ON_CONFIRM)
            {
                //close the BT confirm pop-up while the BT has been turned on in other page
                //scenario: 1st popup in quick switch /2nd pop up in contacts while sharing via BT
                if (widget->m_confirmPopup)
                {
                    VFX_OBJ_CLOSE(widget->m_confirmPopup);
                }                
            }
            break;
        }

        case SRV_BT_CM_EVENT_DEACTIVATE:
        {
            widget->m_indicatorBt->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
            widget->m_buttonBt->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BT_N));

            if(widget->m_confirmFlag == VAPP_BT_POWER_OFF_CONFIRM)
            {
                //close the BT confirm pop-up while the BT has been turned off in other page
                if (widget->m_confirmPopup)
                {
                    VFX_OBJ_CLOSE(widget->m_confirmPopup);
                }                
            }            
            break;
        }

        default:
            break;
    }
}


mmi_ret VappWidgetQuickSwitch::flightEvtHdlr(mmi_event_struct *event)
{
    return MMI_RET_OK;
}


void VappWidgetQuickSwitch::deregisterEvent()
{
    // WLAN
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND,
        (mmi_proc_func)&VappWidgetQuickSwitch::wlanEvtHandle,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND,
        (mmi_proc_func)&VappWidgetQuickSwitch::wlanEvtHandle,
        getObjHandle());

    // BT
    srv_bt_cm_reset_notify(m_btSrvHandle);

    // Slient mode
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_PROF_PROFILE_SWITCHED,
        (mmi_proc_func)&VappWidgetQuickSwitch::onProc,
        getObjHandle());

    // Flight mode
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY,
        (mmi_proc_func)&VappWidgetQuickSwitch::onProc,
        getObjHandle());

    // Backlight level changed.
    mmi_frm_cb_dereg_event(
    EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE,
    (mmi_proc_func)&VappWidgetQuickSwitch::onProc,
    getObjHandle());

    // The use of event before BT is switching.
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY,
        VappWidgetQuickSwitch::onProc,
        getObjHandle());
}


VfxPoint VappWidgetQuickSwitch::getSeparatorPos(
    const VfxSize &size,
    VfxS32 idx) const
{
    VFX_ASSERT(idx >= 0 && idx < SHORTCUT_NUM);

    VfxPoint pos;
    pos.x = ((size.width-(SHADOW*2)) * idx / SHORTCUT_NUM)+SHADOW;
    pos.y = size.height >> SEPARATOR_OFFSET_Y;

    return pos;
}


void VappWidgetQuickSwitch::showLoading(VcpActivityIndicator *ind)
{
    ind->start();

}


void VappWidgetQuickSwitch::hideLoading(VcpActivityIndicator *ind)
{
    ind->stop();
}


void VappWidgetQuickSwitch::getCurrentLightLevel()
{
    m_currentLevel = srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD);

    m_maxLevel = SRV_GPIO_BACKLIGHT_MAX_LEVEL;
    m_midLevel = (SRV_GPIO_BACKLIGHT_MIN_LEVEL+SRV_GPIO_BACKLIGHT_MAX_LEVEL)/2;
    m_minLevel = SRV_GPIO_BACKLIGHT_MIN_LEVEL;
    m_level0 = (m_minLevel+m_midLevel)/2;
    m_lastLevel = m_minLevel;    
    
    if(m_currentLevel == m_maxLevel)                                        // Max Level
    {
        m_indicatorMin->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_indicatorMax->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H));
    }
    else if (m_currentLevel >= m_midLevel && m_currentLevel < m_maxLevel)   // Mid Level
    {
        m_indicatorMin->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_indicatorMax->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H));
    }
    else if (m_currentLevel < m_midLevel && m_currentLevel > m_minLevel)    // Level0
    {
        m_indicatorMin->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_H);
        m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_indicatorMax->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_H));
    }
    else                                                                    // min level , without indicator 1,2,3
    {
        m_indicatorMin->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_indicatorMid->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_indicatorMax->setResId(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_INDICATOR_N);
        m_buttonBrightness->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_QUICK_SWITCH_BRIGHTNESS_N));
    }
}
#endif /* __MMI_VUI_WIDGET_QUICK_SWITCH__*/
