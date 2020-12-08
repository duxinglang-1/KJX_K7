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
 *  vapp_gpssetting.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VAPP_GPSSETTING_H__
#define __VAPP_GPSSETTING_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_GPSSETTING_SIM_NUM1 = 0,
    VAPP_GPSSETTING_SIM_NUM2,
    VAPP_GPSSETTING_SIM_NUM3,
    VAPP_GPSSETTING_SIM_NUM4,
    VAPP_GPSSETTING_SIM_NUM_COUNT
} vapp_gpssetting_sim_enum;

/*****************************************************************************
 * Class
 *****************************************************************************/
class VappGPSSettingApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappGPSSettingApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VappGPSSettingScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappGPSSettingScreen);

// Override
public:
    virtual void on1stReady();
};


class VappGPSSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGPSSettingPage);

private:
    enum
    {
        ID_FORM_GPS_GROUP_TITLE,
        ID_FORM_GPS_SWITCH,
        ID_FORM_TIME_SYNC_SWITCH,
        ID_FORM_AGPS_GROUP_TITLE,
        ID_FORM_AGPS_SWITCH,
        ID_FORM_SIM1_PROFILE_LAUNCH,
        ID_FORM_SIM2_PROFILE_LAUNCH,
        ID_FORM_SIM3_PROFILE_LAUNCH,
        ID_FORM_SIM4_PROFILE_LAUNCH,
        ID_FORM_SEND_LOCATION_SWITCH,
        ID_FORM_ENTER_EM_GPS_LAUNCH,
        ID_FORM_NUM_BASE
    };

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    void onButtonClicked(VcpFormItemCell* sender, VfxId id);
    void SwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
#ifdef __FLIGHT_MODE_DISABLE_AGPS__
    static mmi_ret switchInFlightMode(mmi_event_struct *evt);
#endif
    VcpForm*                    m_form;
    VcpFormItemLauncherCell*    mSimLaunch;
    VcpFormItemSwitchCell*      mSwitchGPS;
    VcpFormItemSwitchCell*      mSwitchSendLocation;
    VcpFormItemSwitchCell*      mSwitchAGPS;
    VcpFormItemSwitchCell*      mSwitchTimeSync;
    VcpFormItemSwitchCell*      mSwitch[ID_FORM_NUM_BASE];
    #ifdef __MMI_ENGINEER_MODE__
        VcpFormItemLauncherCell*    mEngineerModeLaunch;
    #endif
    //VfxBool status_changed;

};



#if defined(__AGPS_USER_PLANE__)
class VappGPSProfilePage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGPSProfilePage);

// Override
public:
    VappGPSProfilePage(): m_index(0)
        {};
    VappGPSProfilePage(VfxS32 Id): m_index(Id)
        {};

    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    void onButtonClicked(VfxObject* sender, VfxId id);
    void SwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
    void onTBClick(VfxObject* obj, VfxId id);
    void onInputItemServerAddActived(VcpTextEditor *obj, VfxBool isActive);
    void onInputItemPortNumberActived(VcpTextEditor *obj, VfxBool isActive);
    void onFuncBarClick(VfxObject *sender, VfxId id);
    void setBackFromOTAP();

    VcpFormItemTextInput*   mTextInputServerAddr;
    VcpFormItemTextInput*   mTextInputServerPort;
    VcpFormItemBigArrowButton*  mBigArrowButton;
    VfxU32 mSelectedDataAccount;
    VcpFunctionBar *m_funcBar;
    VcpForm* m_form;
    VfxId m_ActiveItemId;
private:
    enum
    {
        ID_TOOLBAR_SAVE,
        ID_TOOLBAR_BACK,
        ID_TOOLBAR_NUM_BASE
    };
    enum
    {
        ID_FORM_PROFILE_SERVER_ADDR,
        ID_FORM_PROFILE_PORT_NUMBER,
        ID_FORM_PROFILE_PORT_NUMBER_INVALID,
        ID_FORM_PROFILE_DATA_ACCOUNT,
        ID_FORM_PROFILE_FUNC_BAR,
        ID_FORM_PROFILE_FUNC_BAR_PREV,
        ID_FORM_PROFILE_FUNC_BAR_NEXT,
        ID_FORM_PROFILE_FUNC_BAR_SAVE,
        ID_FORM_PROFILE_NUM_BASE
    };
    VfxS32 m_index;
    VfxBool back_from_otap;

    mmi_id m_da_gid;
};

extern void vapp_gps_setting_profile_set();
#endif

//class VappGPSSettingOTAPCuiScr: public VfxMainScr
//{
//    VFX_DECLARE_CLASS(VappGPSSettingOTAPCuiScr);
//    // Override
//    public:
//        virtual void on1stReady();
//};
//
//class VappGPSSettingOTAPCuiPage : public VfxPage
//{
//    VFX_DECLARE_CLASS(VappGPSSettingOTAPCuiPage);
//    public:
//        virtual void onInit();
//        enum
//        {
//            ID_FORM_TOOLBAR_INTALL_BUTTON,
//            ID_FORM_TOOLBAR_SKIP_BUTTON,
//            ID_FORM_TOOLBAR_BASE
//        };
//
//    protected:
//        void onToolbarTapped(
//            VfxObject* sender,  // sender
//            VfxId id            // id
//        );
//};
//
///*******************************************************************************
//* Export CUI API
//*******************************************************************************/
///* Create GPS CUI*/
//class VappGPSSettingOTAPCui: public VfxCui
//{
//    VFX_DECLARE_CLASS(VappGPSSettingOTAPCui);
//
//public:
//// Constructor / Destructor
//    VappGPSSettingOTAPCui() : m_scr(NULL),install(NULL),skip(NULL) {}
//    virtual ~VappGPSSettingOTAPCui() {}
//
//// Override
//public:
//    // initial parameter and entry main src
//    virtual void onRun(
//        void *arg,          // parameter
//        VfxU32 argSize      // parameter size
//    );
//    virtual mmi_ret onProc(
//        mmi_event_struct * evt
//    );
//
//    virtual void onInit();
//
//    virtual void onDeinit();
//    void (*install)(void);
//    void (*skip)(void);
//// Method
//
//// Implementation
//
//private:
//    VappGPSSettingOTAPCuiScr *m_scr;
//};

class VappGPSSettingPopupCui: public VfxCui
{
    VFX_DECLARE_CLASS(VappGPSSettingPopupCui);
public:
// Constructor / Destructor
    VappGPSSettingPopupCui():isPopupOnly(VFX_TRUE),isHighLightYes(VFX_FALSE),isHighLightNo(VFX_FALSE){}
    virtual ~VappGPSSettingPopupCui() {}
// Override
public:
    // initial parameter and entry main src
    virtual void onRun(
        void *arg,          // parameter
        VfxU32 argSize      // parameter size
    );
    virtual mmi_ret onProc(
        mmi_event_struct * evt
    );
    virtual void onInit();
    virtual void onDeinit();

// Method

// Implementation
public:
    VfxWString mText;
    VfxBool isPopupOnly;
    VfxBool isHighLightYes;
    VfxBool isHighLightNo;
};

class VappGPSSettingPopupCuiScr: public VfxMainScr
{
    VFX_DECLARE_CLASS(VappGPSSettingPopupCuiScr);
    // Override
    public:
        virtual void on1stReady();
};

class VappGPSSettingPopupCuiPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGPSSettingPopupCuiPage);
    public:
        virtual void onInit();
        void onPopupStateChange(VfxBasePopup* popup, VfxBasePopupStateEnum state);
};

/*******************************************************************************
* Export GPS API
*******************************************************************************/
extern void vapp_gps_mgr_notify_callback(mmi_gps_srv_notify_type_enum type, mmi_gps_srv_notify_type_struct *notify, void *user_data);

class VappGPSMGRApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappGPSMGRApp);
public:
    mmi_gps_srv_notify_type_struct notify;
    mmi_gps_srv_notify_type_enum   type;
// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VappGPSMGRScreen : public VfxAppScr
{
    VFX_DECLARE_CLASS(VappGPSMGRScreen);

// Override
public:
    //virtual void on1stReady();
    virtual void onInit();
    virtual void onDeinit();
    void timeOut();
    void ConfirmSelected(VfxObject* obj, VfxId id);
};

#endif /* __VAPP_GPSSETTING_H__ */

