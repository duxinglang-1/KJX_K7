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
 *  vapp_gpssetting.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#if defined(__GPS_SUPPORT__)
extern "C"
{
#include "MMI_include.h"
#include "mdi_datatype.h"
#include "GPSGProt.h"
#include "GPSSetting.h"
#include "app_str.h"
#include "SimCtrlSrvGprot.h"
//#include "DataAccountGProt.h"
extern void em_gps_enter_main_src(void);
#ifdef __FLIGHT_MODE_DISABLE_AGPS__
#include "ModeSwitchSrvGProt.h"
#endif
#include "cbm_api.h"
}

#include "vcp_include.h"
#include "vcp_list_menu.h"

#if defined(__AGPS_USER_PLANE__)
#include "vapp_dtcnt_gprot.h"
#include "vcui_dtcnt_select_gprot.h"
#endif

#include "vapp_gpssetting.h"
#include "vapp_setting_gps.h"
/*#include "vfx_xml_loader.h"*/
#include "mmi_rp_vapp_gps_setting_def.h"
#include "mmi_rp_srv_gps_def.h"
#endif
/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Function
 *****************************************************************************/
#ifdef __AGPS_USER_PLANE__
VappGPSProfilePage * GPS_setting_profile_ptr  = NULL;
#endif

extern "C" void vapp_gps_setting_launch(void)
{
#if defined(__GPS_SUPPORT__)
    VfxAppLauncher::launch(
        VAPP_GPS_SETTING,
        VFX_OBJ_CLASS_INFO(VappGPSSettingApp),
        GRP_ID_ROOT);
#endif
}

#ifdef __AGPS_USER_PLANE__
extern void vapp_gps_setting_profile_set(void)
{
    if(GPS_setting_profile_ptr != NULL)
    {
        GPS_setting_profile_ptr->setBackFromOTAP();
    }
}

static void vapp_gps_register_cbm_app_id(VfxU8* app_id)
{
    cbm_app_info_struct info;

    *app_id = 0;
    info.app_str_id = STR_ID_VAPP_GPS_SETTING_GPS_SETTING;
    info.app_icon_id = IMG_GLOBAL_OK;  // used this temperally.
    info.app_type = DTCNT_APPTYPE_GPS;
    cbm_register_app_id_with_app_info(&info, (kal_uint8*)app_id);
}

static void vapp_gps_deregister_cbm_app_id(VfxU8 app_id)
{
    cbm_deregister_app_id((kal_uint8)app_id);
}

static void vapp_gps_get_data_account_name(VfxU32 account_id, WCHAR* account_name_p, VfxU8 len, VappDtcntGetAcctNameTypeEnum type)
{

    cbm_sim_id_enum sim_id;
    VfxU8 app_id = 0;

    vapp_gps_register_cbm_app_id(&app_id);

    sim_id = (cbm_sim_id_enum)mmi_gps_setting_get_sim();

    account_id = cbm_encode_data_account_id(account_id, sim_id, app_id, MMI_FALSE);

    vapp_dtcnt_get_full_account_name(account_id, (WCHAR*)account_name_p, len, type);

    vapp_gps_deregister_cbm_app_id(app_id);
}

#endif

#if defined(__GPS_SUPPORT__)
VFX_IMPLEMENT_CLASS("VappGPSSettingApp", VappGPSSettingApp, VfxApp);

void VappGPSSettingApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappGPSSettingScreen *scr;
    VFX_OBJ_CREATE(scr, VappGPSSettingScreen, this);
    scr->show();
}

VFX_IMPLEMENT_CLASS("VappGPSSettingScreen", VappGPSSettingScreen, VfxMainScr);

void VappGPSSettingScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappGPSSettingPage *page;
    VFX_OBJ_CREATE(page, VappGPSSettingPage, this);
    pushPage(0, page);
}


VFX_IMPLEMENT_CLASS("VappGPSSettingPage", VappGPSSettingPage, VfxPage);

void VappGPSSettingPage::onInit()
{
    VfxU16 m_gps_receiver_setting;
    VfxPage::onInit(); // call base class
//    status_changed = VFX_FALSE;
    // Title Bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle((VfxResId)STR_ID_VAPP_GPS_SETTING_GPS_SETTING);    // set title text
    setTopBar(titleBar);

    // get screen size
    vrt_size_struct main_screen_size;
    VfxColorTypeEnum main_screen_color_format;
    vrt_sys_get_main_screen_info(
        &main_screen_size,
        &main_screen_color_format);

    // create VcpForm for the screen
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(main_screen_size);

    // GPS group title
    VcpFormItemCaption*         m_caption;
    VFX_OBJ_CREATE(m_caption, VcpFormItemCaption, m_form);
    m_caption->setText((VfxResId)STR_ID_VAPP_GPS_SETTING_GPS);
    m_form->addItem(m_caption, ID_FORM_GPS_GROUP_TITLE);

    m_gps_receiver_setting = mmi_gps_get_receiver_setting();

    // TimeSync switch button
    VFX_OBJ_CREATE(mSwitchTimeSync, VcpFormItemSwitchCell, m_form);
    mSwitchTimeSync->setMainText((VfxResId)STR_ID_VAPP_GPS_SETTING_TIME_SYNC);
    mSwitchTimeSync->setSwitchStatus((mmi_gps_setting_get_time_sync() == MMI_TRUE) ? VFX_TRUE : VFX_FALSE);
    mSwitchTimeSync->setIsDisabled(!m_gps_receiver_setting);
    mSwitchTimeSync->setIsTappable(VFX_FALSE);
    mSwitchTimeSync->m_signalSwitchChangeReq.connect(this, &VappGPSSettingPage::SwitchChangeReq);
    m_form->addItem(mSwitchTimeSync, ID_FORM_TIME_SYNC_SWITCH);

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    // AGPS group title, when define UP or CP add this
    VFX_OBJ_CREATE(m_caption, VcpFormItemCaption, m_form);
    m_caption->setText((VfxResId)STR_ID_VAPP_GPS_SETTING_AGPS);
    m_form->addItem(m_caption, ID_FORM_AGPS_GROUP_TITLE);

    // AGPS switch, control UP and CP
    VFX_OBJ_CREATE(mSwitchAGPS, VcpFormItemSwitchCell, m_form);
    mSwitchAGPS->setMainText((VfxResId)STR_ID_VAPP_GPS_SETTING_AGPS);
    mSwitchAGPS->setSwitchStatus((mmi_gps_setting_get_is_agps_on() == MMI_TRUE) ? VFX_TRUE : VFX_FALSE);
    mSwitchAGPS->setIsDisabled(!m_gps_receiver_setting);
    mSwitchAGPS->setIsTappable(VFX_FALSE);
    mSwitchAGPS->m_signalSwitchChangeReq.connect(this, &VappGPSSettingPage::SwitchChangeReq);
    m_form->addItem(mSwitchAGPS, ID_FORM_AGPS_SWITCH);
#endif /*defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)*/

#ifdef __AGPS_USER_PLANE__
        {
            // DataAccount get name and show
            VfxWString mServerDAName;
            VfxU32 mSelectedDataAccount;

            mSelectedDataAccount = mmi_gps_setting_get_data_account(mmi_gps_setting_get_sim());

            vapp_gps_get_data_account_name(
                mSelectedDataAccount,
                (WCHAR*)mServerDAName.lockBuf((MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH),
                (MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH,
                VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
            mServerDAName.unlockBuf();

            // create the Laucher
            VFX_OBJ_CREATE(mSimLaunch, VcpFormItemLauncherCell, m_form);
            mSimLaunch->setMainText((VfxResId)STR_ID_VAPP_GPS_SETTING_AGPS_PROFILE);
            mSimLaunch->setHintText(mServerDAName);
            mSimLaunch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            mSimLaunch->m_signalTap.connect(this, &VappGPSSettingPage::onButtonClicked);
            mSimLaunch->setIsDisabled(!(m_gps_receiver_setting && mSwitchAGPS->getSwitchStatus()));
            m_form->addItem(mSimLaunch, VAPP_GPSSETTING_SIM_NUM1);
        }
#endif /*__AGPS_USER_PLANE__*/

#ifdef __ALLOW_FORBIDDEN_MY_LOCATION__
    // CP send location switch
    VFX_OBJ_CREATE(mSwitchSendLocation, VcpFormItemSwitchCell, m_form);
    mSwitchSendLocation->setMainText((VfxResId)STR_ID_VAPP_GPS_SETTING_SEND_LOCATION);
    mSwitchSendLocation->setSwitchStatus(mmi_gps_setting_get_send_location() ? VFX_TRUE : VFX_FALSE);
    mSwitchSendLocation->setHintText((VfxResId)STR_ID_VAPP_GPS_SETTING_SEND_LOCATION_HINT);
    mSwitchSendLocation->setIsDisabled(!(m_gps_receiver_setting && mSwitchAGPS->getSwitchStatus()));
    mSwitchSendLocation->setIsTappable(VFX_FALSE);
    mSwitchSendLocation->m_signalSwitchChangeReq.connect(this, &VappGPSSettingPage::SwitchChangeReq);
    m_form->addItem(mSwitchSendLocation, ID_FORM_SEND_LOCATION_SWITCH);
#endif /*__ALLOW_FORBIDDEN_MY_LOCATION__*/

#ifdef __MMI_ENGINEER_MODE__
    // engineer mode launcher
    mEngineerModeLaunch = NULL;
    if (MMI_TRUE == mmi_gps_setting_get_em_on_off())
    {
        VFX_OBJ_CREATE(mEngineerModeLaunch, VcpFormItemLauncherCell, m_form);
        mEngineerModeLaunch->setMainText((VfxResId)STR_ID_VAPP_GPS_SETTING_EM_AGPS);
        mEngineerModeLaunch->setHintText((VfxResId)STR_ID_VAPP_GPS_SETTING_EM_AGPS);
        mEngineerModeLaunch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        mEngineerModeLaunch->m_signalTap.connect(this, &VappGPSSettingPage::onButtonClicked);
        m_form->addItem(mEngineerModeLaunch, ID_FORM_ENTER_EM_GPS_LAUNCH);
    }
#endif /*__MMI_ENGINEER_MODE__*/

#ifdef __FLIGHT_MODE_DISABLE_AGPS__
    if (!srv_mode_switch_is_network_service_available())
    {
        //mSwitchAGPS->setIsDisabled(!srv_mode_switch_is_network_service_available());
        if(mSwitchAGPS->getSwitchStatus() == VFX_TRUE)
        {
            SwitchChangeReq(mSwitchAGPS,ID_FORM_AGPS_SWITCH,VFX_FALSE);
            mmi_gps_setting_set_flight_mode_agps(MMI_TRUE);
            //status_changed = VFX_TRUE;
        }
        mSwitchAGPS->setIsDisabled(VFX_TRUE);
    }
    else
    {
        if(mmi_gps_setting_get_flight_mode_agps() == VFX_TRUE)
        {
            SwitchChangeReq(mSwitchAGPS,ID_FORM_AGPS_SWITCH,VFX_TRUE);
            mmi_gps_setting_set_flight_mode_agps(MMI_FALSE);
            //status_changed = VFX_FALSE;
        }
    }

    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, &VappGPSSettingPage::switchInFlightMode, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappGPSSettingPage::switchInFlightMode, this);
#endif
}

void VappGPSSettingPage::onDeinit()
{
#ifdef __FLIGHT_MODE_DISABLE_AGPS__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, &VappGPSSettingPage::switchInFlightMode, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappGPSSettingPage::switchInFlightMode, this);
#endif
    VfxPage::onDeinit();
}

void VappGPSSettingPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

#ifdef __AGPS_USER_PLANE__
    {
        // DataAccount get name and show
        VfxWString mServerDAName;
        VfxU32 mSelectedDataAccount;

        mSelectedDataAccount = mmi_gps_setting_get_data_account(mmi_gps_setting_get_sim());

        vapp_gps_get_data_account_name(
            mSelectedDataAccount,
            (WCHAR*)mServerDAName.lockBuf((MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH),
            (MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH,
            VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
        mServerDAName.unlockBuf();

        // create the Laucher
        mSimLaunch->setHintText(mServerDAName);
    }
#endif /*__AGPS_USER_PLANE__*/

#ifdef __MMI_ENGINEER_MODE__
    // engineer mode launcher
    if (mEngineerModeLaunch != NULL &&
        MMI_FALSE == mmi_gps_setting_get_em_on_off())
    {
        m_form->removeItem(ID_FORM_ENTER_EM_GPS_LAUNCH);
    }
#endif /*__MMI_ENGINEER_MODE__*/
}

void VappGPSSettingPage::onButtonClicked(VcpFormItemCell* sender, VfxId id)
{
#if defined(__AGPS_USER_PLANE__)
    VcpFormItemLauncherCell* m_switch_p = (VcpFormItemLauncherCell*)sender;
    VappGPSProfilePage *page;
#endif

    switch (id)
    {
    case VAPP_GPSSETTING_SIM_NUM1:
    case VAPP_GPSSETTING_SIM_NUM2:
    case VAPP_GPSSETTING_SIM_NUM3:
    case VAPP_GPSSETTING_SIM_NUM4:
#if defined(__AGPS_USER_PLANE__)
        if (VFX_FALSE == m_switch_p->getIsDisabled())
        {
            // When create profile page, pass the id to it so get rigth settings
            VFX_OBJ_CREATE_EX(page, VappGPSProfilePage, this, (id));
            getMainScr()->pushPage(0, page);
        }
#endif
        break;
#ifdef __MMI_ENGINEER_MODE__
    case ID_FORM_ENTER_EM_GPS_LAUNCH:
        em_gps_enter_main_src();
        break;
#endif /*__MMI_ENGINEER_MODE__*/
    default:
        break;
    }
}

#ifdef __FLIGHT_MODE_DISABLE_AGPS__
mmi_ret VappGPSSettingPage::switchInFlightMode(mmi_event_struct *evt)
{
    VfxObject *obj = (VfxObject*)evt->user_data;
    VappGPSSettingPage *page = VFX_OBJ_DYNAMIC_CAST(obj, VappGPSSettingPage);

    if (!page)
    {
        return MMI_RET_OK;
    }
    VcpFormItemSwitchCell* cell = page->mSwitchAGPS;

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
        {
            cell->setIsDisabled(VFX_TRUE);
            break;
        }
        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            if (srv_mode_switch_is_network_service_available())
            {
                cell->setIsDisabled(VFX_FALSE);
                if(mmi_gps_setting_get_flight_mode_agps() == VFX_TRUE)
                {
                    page->SwitchChangeReq(cell,ID_FORM_AGPS_SWITCH,VFX_TRUE);
                    mmi_gps_setting_set_flight_mode_agps(MMI_FALSE);
                }
            }
            else
            {
                cell->setIsDisabled(VFX_TRUE);
                if(cell->getSwitchStatus() == VFX_TRUE)
                {
                    page->SwitchChangeReq(cell,ID_FORM_AGPS_SWITCH,VFX_FALSE);
                    mmi_gps_setting_set_flight_mode_agps(MMI_TRUE);
                }
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* __FLIGHT_MODE_DISABLE_AGPS__ */

void VappGPSSettingPage::SwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    VcpFormItemSwitchCell* m_switch_p = (VcpFormItemSwitchCell*)item;

    switch (id)
    {
    case ID_FORM_GPS_SWITCH:
        m_switch_p->setSwitchStatus(newStatus);
        mSwitchTimeSync->setIsDisabled(!newStatus);
        mSwitchAGPS->setIsDisabled(!newStatus);
        if (VFX_TRUE == mSwitchAGPS->getSwitchStatus())
        {
            mSimLaunch->setIsDisabled(!newStatus);
        #ifdef __ALLOW_FORBIDDEN_MY_LOCATION__
            mSwitchSendLocation->setIsDisabled(!newStatus);
        #endif /*__ALLOW_FORBIDDEN_MY_LOCATION__*/
        }
        mmi_gps_set_receiver_setting(newStatus);
        break;
    case ID_FORM_TIME_SYNC_SWITCH:
        m_switch_p->setSwitchStatus(newStatus);
        mmi_gps_setting_set_time_sync(newStatus);
        break;
    case ID_FORM_AGPS_SWITCH:
        m_switch_p->setSwitchStatus(newStatus);
        mSimLaunch->setIsDisabled(!newStatus);

        #ifdef __ALLOW_FORBIDDEN_MY_LOCATION__
            if (newStatus == VFX_TRUE)
            {
                mSwitchSendLocation->setSwitchStatus(mmi_gps_setting_get_send_location());
            }
            else
            {
                mSwitchSendLocation->setSwitchStatus(VFX_FALSE);
            }
            mSwitchSendLocation->setIsDisabled(!newStatus);
        #endif /*__ALLOW_FORBIDDEN_MY_LOCATION__*/

        mmi_gps_setting_set_agps_on_off(newStatus);
        break;
    case ID_FORM_SEND_LOCATION_SWITCH:
        m_switch_p->setSwitchStatus(newStatus);
        mmi_gps_setting_set_send_location(newStatus);
        break;
    default:
        m_switch_p->setSwitchStatus(newStatus);
        break;
    }
}

#if defined(__AGPS_USER_PLANE__)
VFX_IMPLEMENT_CLASS("VappGPSProfilePage", VappGPSProfilePage, VfxPage);
void VappGPSProfilePage::onInit()
{
    VfxPage::onInit(); // call base class

    GPS_setting_profile_ptr = this;

    // OTAP work around....
    back_from_otap = VFX_TRUE;
    m_da_gid = GRP_ID_INVALID;

    // Title Bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);

    titleBar->setTitle((VfxResId)STR_ID_VAPP_GPS_SETTING_AGPS_PROFILE);    // set title text
    setTopBar(titleBar);

    // ToolBar
    VcpToolBar* toolbar;
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    toolbar->addItem(ID_TOOLBAR_SAVE, (VfxResId)STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);       // add tool bar "save" button
    toolbar->addItem(ID_TOOLBAR_BACK, (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL); // add tool bar "cancel" button
    toolbar->m_signalButtonTap.connect(this, &VappGPSProfilePage::onTBClick);
    setBottomBar(toolbar);

    // Get screen size
    vrt_size_struct main_screen_size;
    VfxColorTypeEnum main_screen_color_format;
    vrt_sys_get_main_screen_info(
        &main_screen_size,
        &main_screen_color_format);

    // Create Form
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(main_screen_size);

    // Function bar
    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem((VfxResId)STR_GLOBAL_PREV, (VfxId)ID_FORM_PROFILE_FUNC_BAR_PREV);
    m_funcBar->addItem((VfxResId)STR_GLOBAL_NEXT, (VfxId)ID_FORM_PROFILE_FUNC_BAR_NEXT);
    m_funcBar->addItem((VfxResId)STR_GLOBAL_SAVE, (VfxId)ID_FORM_PROFILE_FUNC_BAR_SAVE);
    m_funcBar->setItemSpecial(ID_FORM_PROFILE_FUNC_BAR_SAVE);
    m_funcBar->m_signalButtonTap.connect(this, &VappGPSProfilePage::onFuncBarClick);

    // Server Address get and show
    VfxWString mServerAddr;
    VFX_OBJ_CREATE(mTextInputServerAddr, VcpFormItemTextInput, m_form);
    mTextInputServerAddr->setLabelText((VfxResId)STR_ID_VAPP_GPS_SETTING_SERVER_ADDRESS);
    mmi_gps_setting_get_server_addr(m_index, mServerAddr.lockBuf(NVRAM_EF_AGPS_PROFILE_SIZE), AGPS_MAX_PROFILE_ADDR_LEN * 2);
    mServerAddr.unlockBuf();
    mTextInputServerAddr->getTextBox()->setText((VfxWChar*)mServerAddr.getBuf(),AGPS_MAX_PROFILE_ADDR_LEN - 1);
    mTextInputServerAddr->getTextBox()->m_signalActivated.connect(this, &VappGPSProfilePage::onInputItemServerAddActived);
    mTextInputServerAddr->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
    m_form->addItem(mTextInputServerAddr, ID_FORM_PROFILE_SERVER_ADDR);

    // Server Port get and show
    VfxWString mServerPort;
    VcpTextEditor* mTextEditor;
    VFX_OBJ_CREATE(mTextInputServerPort, VcpFormItemTextInput, m_form);
    mTextInputServerPort->setLabelText((VfxResId)STR_ID_VAPP_GPS_SETTING_PORT_NUMBER);
    mTextEditor = mTextInputServerPort->getTextBox();
    mTextEditor->setIME(IMM_INPUT_TYPE_NUMERIC);
    mTextEditor->setText(
        mServerPort.format(
            "%d",
            mmi_gps_setting_get_server_port(m_index)),
        5);
    mTextInputServerPort->getTextBox()->m_signalActivated.connect(this, &VappGPSProfilePage::onInputItemPortNumberActived);
    mTextInputServerPort->getTextBox()->setFunctionBar(m_funcBar, VFX_FALSE);
    m_form->addItem(mTextInputServerPort, ID_FORM_PROFILE_PORT_NUMBER);

    // DataAccount get name and show
    VcpArrowButton* mArrowButton;
    VfxWString mServerDAName;
    VFX_OBJ_CREATE(mBigArrowButton, VcpFormItemBigArrowButton, m_form);
    mBigArrowButton->setButtonText((VfxResId)STR_ID_VAPP_GPS_SETTING_DATA_ACCOUNT);

    mmi_gps_setting_prefer_sim_enum sim_id;

    sim_id = mmi_gps_setting_get_sim();
    mSelectedDataAccount = mmi_gps_setting_get_data_account(sim_id);

    vapp_gps_get_data_account_name(
        mSelectedDataAccount,
        (WCHAR*)mServerDAName.lockBuf((MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH),
        (MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH,
        VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
    mServerDAName.unlockBuf();

    mBigArrowButton->setHintText(mServerDAName);
    mArrowButton = mBigArrowButton->getButton();
    mArrowButton->m_signalClicked.connect(this, &VappGPSProfilePage::onButtonClicked);
    mArrowButton->setId(ID_FORM_PROFILE_DATA_ACCOUNT);

    mmi_sim_enum m_sim_id = MMI_SIM_NONE;
    switch(sim_id)
    {
        case MMI_GPS_SETTING_PREFER_SIM_NO1:
            m_sim_id = MMI_SIM1;
            break;
        case MMI_GPS_SETTING_PREFER_SIM_NO2:
            m_sim_id = MMI_SIM2;
            break;
        case MMI_GPS_SETTING_PREFER_SIM_NO3:
            m_sim_id = MMI_SIM3;
            break;
        case MMI_GPS_SETTING_PREFER_SIM_NO4:
            m_sim_id = MMI_SIM4;
            break;
    }

    if(MMI_FALSE == srv_sim_ctrl_is_available(m_sim_id))
    {
        mArrowButton->setIsDisabled(VFX_TRUE);
    }
    m_form->addItem(mBigArrowButton, ID_FORM_PROFILE_DATA_ACCOUNT);

}

void VappGPSProfilePage::onDeinit()
{
    if (m_funcBar)
    {
        VFX_OBJ_CLOSE(m_funcBar);
    }
    GPS_setting_profile_ptr = NULL;
    m_da_gid = GRP_ID_INVALID;
    VfxPage::onDeinit();
}

void VappGPSProfilePage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
    if(VFX_TRUE == isBackward && back_from_otap == VFX_TRUE)
    {
        VfxWString mServerAddr;
        mmi_gps_setting_get_server_addr(m_index, mServerAddr.lockBuf(NVRAM_EF_AGPS_PROFILE_SIZE), AGPS_MAX_PROFILE_ADDR_LEN * 2);
        mServerAddr.unlockBuf();
        mTextInputServerAddr->getTextBox()->setText((VfxWChar*)mServerAddr.getBuf(),AGPS_MAX_PROFILE_ADDR_LEN - 1);

        VfxWString mServerPort;
        mTextInputServerPort->getTextBox()->setText(
            mServerPort.format(
                "%d",
                mmi_gps_setting_get_server_port(m_index)),
            5);

        VfxWString mServerDAName;

        mSelectedDataAccount = mmi_gps_setting_get_data_account(mmi_gps_setting_get_sim());

        vapp_gps_get_data_account_name(
            mSelectedDataAccount,
            (WCHAR*)mServerDAName.lockBuf((MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH),
            (MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH,
            VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
        mServerDAName.unlockBuf();
        mBigArrowButton->setHintText(mServerDAName);
    }
}

void VappGPSProfilePage::setBackFromOTAP()
{
    back_from_otap = VFX_TRUE;

    /* update data account because may changed by OTAP */
    if (m_da_gid != GRP_ID_INVALID)
    {
        VfxU8 sim_id, cbm_app_id;

        vapp_gps_register_cbm_app_id(&cbm_app_id);

        sim_id = mmi_gps_setting_get_sim();
        mSelectedDataAccount = mmi_gps_setting_get_data_account(sim_id);
        mSelectedDataAccount = cbm_encode_data_account_id(mSelectedDataAccount, (cbm_sim_id_enum)sim_id, cbm_app_id, MMI_FALSE);

        vcui_dtcnt_select_set_account_id(m_da_gid, (cui_dtcnt_sim_enum)sim_id, mSelectedDataAccount);

        vapp_gps_deregister_cbm_app_id(cbm_app_id);
    }
}

void VappGPSProfilePage::onFuncBarClick(VfxObject *sender, VfxId id)
{
    VfxId nextId = 0xFF;
    VfxWString mStringTemp;
    VfxU32 port;

    switch(id)
    {
        case ID_FORM_PROFILE_FUNC_BAR_PREV:
        case ID_FORM_PROFILE_FUNC_BAR_NEXT:
            if (m_ActiveItemId == ID_FORM_PROFILE_SERVER_ADDR)
            {
                nextId = ID_FORM_PROFILE_PORT_NUMBER;
            }
            else
            {
                nextId = ID_FORM_PROFILE_SERVER_ADDR;
                m_ActiveItemId = ID_FORM_PROFILE_SERVER_ADDR;
            }
            break;

        case ID_FORM_PROFILE_FUNC_BAR_SAVE:
            mStringTemp = mTextInputServerAddr->getText();
            mmi_gps_setting_set_server_addr(m_index, mStringTemp.getBuf(), AGPS_MAX_PROFILE_ADDR_LEN * 2);
            mStringTemp = mTextInputServerPort->getText();
            port = app_ucs2_wtoi(mStringTemp.getBuf());
            if (port > 0 && port < 65536)
            {
                mmi_gps_setting_set_server_port(m_index, port);
                mmi_gps_setting_set_data_account(m_index, mSelectedDataAccount);
                getMainScr()->popPage();
            }
            else
            {/*
                VcpConfirmPopup *m_cfmPopup;
                VFX_OBJ_CREATE(m_cfmPopup,VcpConfirmPopup,this);
                m_cfmPopup ->setInfoType(VCP_POPUP_TYPE_INFO);
                m_cfmPopup ->setText((VfxResId)STR_ID_VAPP_GPS_SETTING_INVALID_PORT);
                m_cfmPopup ->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                m_cfmPopup ->setAutoDestory(VFX_TRUE);
                m_cfmPopup ->show(VFX_TRUE);*/
                mTextInputServerPort->setWarningText((VfxResId)STR_ID_VAPP_GPS_SETTING_INVALID_PORT);
            }
            break;
        default:
            break;
        }

    if (nextId != 0xFF)
    {
        VcpFormItemTextInput *textInput;
        textInput = (VcpFormItemTextInput *)m_form->getItem(nextId);
        textInput->getTextBox()->activate();
    }
}


void VappGPSProfilePage::onInputItemPortNumberActived(VcpTextEditor *obj, VfxBool isActive)
{
    VfxWString mStringTemp;
//  VfxU32 port;

    if (VFX_TRUE == isActive)
    {
        m_ActiveItemId = ID_FORM_PROFILE_PORT_NUMBER;
        m_funcBar->setDisableItem(ID_FORM_PROFILE_FUNC_BAR_PREV, VFX_FALSE);
        m_funcBar->setDisableItem(ID_FORM_PROFILE_FUNC_BAR_NEXT, VFX_TRUE);
    }
    /*else
    {
        mStringTemp = mTextInputServerPort->getText();
        port = app_ucs2_wtoi(mStringTemp.getBuf());

        if (port > 0 && port <= 65536)
        {
            mTextInputServerPort->setWarningText(VFX_WSTR_NULL);
        }
        else
        {
            mTextInputServerPort->setWarningText((VfxResId)STR_GLOBAL_INVALID_NUMBER);
        }
    }*/
}


void VappGPSProfilePage::onInputItemServerAddActived(VcpTextEditor *obj, VfxBool isActive)
{
    if (VFX_TRUE == isActive)
    {
        m_funcBar->setDisableItem(ID_FORM_PROFILE_FUNC_BAR_PREV, VFX_TRUE);
        m_funcBar->setDisableItem(ID_FORM_PROFILE_FUNC_BAR_NEXT, VFX_FALSE);
        m_ActiveItemId = ID_FORM_PROFILE_SERVER_ADDR;
    }
}

void VappGPSProfilePage::onButtonClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
    case ID_FORM_PROFILE_DATA_ACCOUNT:
        cui_dtcnt_select_run_struct para;
        mmi_id da_gid;

        back_from_otap = VFX_FALSE;
        memset(&para, 0, sizeof(cui_dtcnt_select_run_struct));
        para.app_id  = 0;
        para.icon_id = 0;
        para.str_id = STR_GLOBAL_DATA_ACCOUNT;
        para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
        para.bearers = DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS;
        para.option = CUI_DTCNT_SELECT_SIM;
        {
            VfxU32 sim_id = (VfxU32)mmi_gps_setting_get_sim();

            if (sim_id == 0)
            {
                para.sim_selection = CUI_DTCNT_SELECT_SIM1;
                para.sim_account_id[0] = mSelectedDataAccount;
            }
        #if MMI_SIM_TOTAL > 1
            else if (sim_id == 1)
            {
                para.sim_selection = CUI_DTCNT_SELECT_SIM2;
                para.sim_account_id[1] = mSelectedDataAccount;
            }
        #endif
        #if MMI_SIM_TOTAL > 2
            else if (sim_id == 2)
            {
                para.sim_selection = CUI_DTCNT_SELECT_SIM3;
                para.sim_account_id[2] = mSelectedDataAccount;
            }
        #endif
        #if MMI_SIM_TOTAL > 3
            else if (sim_id == 3)
            {
                para.sim_selection = CUI_DTCNT_SELECT_SIM4;
                para.sim_account_id[3] = mSelectedDataAccount;
            }
        #endif
        }
        da_gid = vcui_dtcnt_select_create(getMainScr()->getGroupId());
        m_da_gid = da_gid;
        vfxSetCuiCallerScr(da_gid, getMainScr());
        vcui_dtcnt_select_set_param(da_gid, &para);
        vcui_dtcnt_select_run(da_gid);
        break;
    default:
        break;
    }
}


void VappGPSProfilePage::onTBClick(VfxObject* obj, VfxId id)
{
    VfxWString mStringTemp;
    VfxU32 port;

    switch (id)
    {
    case ID_TOOLBAR_SAVE:
        mStringTemp = mTextInputServerAddr->getText();
        mmi_gps_setting_set_server_addr(m_index, mStringTemp.getBuf(), AGPS_MAX_PROFILE_ADDR_LEN * 2);
        mStringTemp = mTextInputServerPort->getText();
        port = app_ucs2_wtoi(mStringTemp.getBuf());
        if (port > 0 && port < 65536)
        {
            mmi_gps_setting_set_server_port(m_index, port);
            mmi_gps_setting_set_data_account(mmi_gps_setting_get_sim(), mSelectedDataAccount);
            getMainScr()->popPage();
        }
        else
        {/*
            VcpConfirmPopup *m_cfmPopup;
            VFX_OBJ_CREATE(m_cfmPopup,VcpConfirmPopup,this);
            m_cfmPopup ->setInfoType(VCP_POPUP_TYPE_INFO);
            m_cfmPopup ->setText((VfxResId)STR_ID_VAPP_GPS_SETTING_INVALID_PORT);
            m_cfmPopup ->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            m_cfmPopup ->setAutoDestory(VFX_TRUE);
            m_cfmPopup ->show(VFX_TRUE);*/
            mTextInputServerPort->setWarningText((VfxResId)STR_ID_VAPP_GPS_SETTING_INVALID_PORT);
        }
        break;
    case ID_TOOLBAR_BACK:
        getMainScr()->popPage();
        break;
    default:
        break;
    }
}

mmi_ret VappGPSProfilePage::onProc(mmi_event_struct *evt)
{
    cui_dtcnt_select_event_any_sim_selected_struct *dtcntEvt = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
    VfxWString mServerDAName;

    switch(evt->evt_id)
    {
    case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:

        mSelectedDataAccount = dtcntEvt->accountId;
        // update DataAccount name
        vapp_gps_get_data_account_name(
            mSelectedDataAccount,
            (WCHAR*)mServerDAName.lockBuf((MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH),
            (MAX_DATA_ACCOUNT_NAME_LEN+1)*ENCODING_LENGTH,
            VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
        mServerDAName.unlockBuf();

        mBigArrowButton->setHintText(mServerDAName);
        break;

    case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
    case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
    case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
    case CUI_DTCNT_SELECT_EVENT_CLOSE:
        vcui_dtcnt_select_close(dtcntEvt->sender_id);
        m_da_gid = GRP_ID_INVALID;
        break;
    }

    return VfxPage::onProc(evt);
}
#endif /*defined(__AGPS_USER_PLANE__)*/

VFX_IMPLEMENT_CLASS("VappGPSQuerySettingCell", VappGPSQuerySettingCell, VcpFormItemSwitchCell);
static gps_setting_switch_cb mLancherCB = NULL;
static void *onSwitch_user_data;

void VappGPSQuerySettingCell::onInit()
{
    VcpFormItemSwitchCell::onInit();

    setMainText((VfxResId)STR_ID_VAPP_GPS_SETTING_GPS);
    m_switchState = mmi_gps_get_receiver_setting() ? VFX_TRUE : VFX_FALSE;
    setSwitchStatus(m_switchState);
    setIsTappable(VFX_FALSE);
    m_signalSwitchChangeReq.connect(this, &VappGPSQuerySettingCell::onSwitch);
}

void VappGPSQuerySettingCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool switchValue)
{
    m_switchState = switchValue;
    setSwitchStatus(m_switchState);
    mmi_gps_set_receiver_setting(m_switchState);
    if (mLancherCB)
    {
        (*mLancherCB)(onSwitch_user_data);
    }
}

void VappGPSQuerySettingCell::set_onSwitch_call_function(gps_setting_switch_cb cb_func, void *user_data)
{
    mLancherCB = cb_func;
    onSwitch_user_data = user_data;
}


VFX_IMPLEMENT_CLASS("VappGPSSettingLaucherCell", VappGPSSettingLaucherCell, VcpFormItemLauncherCell);
void VappGPSSettingLaucherCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText((VfxResId)STR_ID_VAPP_GPS_SETTING_GPS_SETTING);
    VfxWString hintString = getHint();
    if (!hintString.isNull())
    {
        setHintText(hintString);
    }
    m_signalTap.connect(this, &VappGPSSettingLaucherCell::onTap);
    setIsHidden(VFX_FALSE);
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    setIsDisabled(!mmi_gps_get_receiver_setting());
    VappGPSQuerySettingCell::set_onSwitch_call_function(&VappGPSSettingLaucherCell::onSwitchUpdateCell,this);
}

VfxWString VappGPSSettingLaucherCell::getHint()
{
    return VFX_WSTR_RES(STR_ID_VAPP_GPS_SETTING_GPS);
}

void VappGPSSettingLaucherCell::updateCell()
{
    VfxWString hintString = getHint();
    if (!hintString.isNull())
    {
        setHintText(hintString);
    }
}


void VappGPSSettingLaucherCell::onSwitchUpdateCell(void *user_data)
{
    VfxBool m_switchState;
    //if (VappGPSSettingLaucherCell::m_btPowerSwitchCellSelf)
    {
        VappGPSSettingLaucherCell* cell = (VappGPSSettingLaucherCell*)user_data;
        m_switchState = mmi_gps_get_receiver_setting() ? VFX_TRUE : VFX_FALSE;;
        cell->setIsDisabled(!m_switchState);
    }

}


void VappGPSSettingLaucherCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    // create and display first page
    VappGPSSettingPage *page;
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr && mmi_gps_get_receiver_setting() != MMI_GPS_RECEIVER_OFF)
    {
        VFX_OBJ_CREATE(page, VappGPSSettingPage, this);
        mainScr->pushPage(0, page);
    }
}

#endif /*__GPS_SUPPORT__*/


