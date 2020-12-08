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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "GPSGProt.h"
#include "GpioSrvGprot.h"
}


#include "vcp_include.h"
#include "vapp_gpssetting.h"
#include "mmi_rp_vapp_gps_setting_def.h"
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
extern void mmi_gps_mgr_notify_accept(void);
extern void mmi_gps_mgr_notify_decline(void);
extern void mmi_gps_mgr_exit_notify_src(void);

VappGPSMGRScreen * GPS_MGR_ptr = NULL;
VappGPSMGRScreen * GPS_MGR_CP_ptr = NULL;

extern "C" void vapp_gps_mgr_notify_init(void)
{
#ifdef __AGPS_USER_PLANE__
    mmi_gps_mgr_register_notify_function(vapp_gps_mgr_notify_callback, NULL);
#endif
#ifdef __AGPS_CONTROL_PLANE__
    mmi_gps_mgr_cp_register_notify_function(vapp_gps_mgr_notify_callback, NULL);
#endif
}


void vapp_gps_mgr_notify_callback(mmi_gps_srv_notify_type_enum type, mmi_gps_srv_notify_type_struct *notify, void *user_data)
{
    VfxAppLauncher::launch(
        VAPP_GPS_MGR,
        VFX_OBJ_CLASS_INFO(VappGPSMGRApp),
        GRP_ID_ROOT,
        notify,
        sizeof(mmi_gps_srv_notify_type_struct));
}

extern "C" void vapp_gps_mgr_notify_timeout(void)
{
    if(GPS_MGR_ptr != NULL)
    {
        GPS_MGR_ptr->timeOut();
        GPS_MGR_ptr = NULL;
    }
}

extern "C" void vapp_gps_mgr_cp_notify_timeout(void)
{
    if(GPS_MGR_CP_ptr != NULL)
    {
        GPS_MGR_CP_ptr->timeOut();
        GPS_MGR_CP_ptr = NULL;
    }
}


VFX_IMPLEMENT_CLASS("VappGPSMGRApp", VappGPSMGRApp, VfxApp);

void VappGPSMGRApp::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    memcpy(&notify, (mmi_gps_srv_notify_type_struct *)args, sizeof(mmi_gps_srv_notify_type_struct));
    // create and display main screen
    VappGPSMGRScreen*scr;
    VFX_OBJ_CREATE(scr, VappGPSMGRScreen, this);
    scr->show();
}

VFX_IMPLEMENT_CLASS("VappGPSMGRScreen", VappGPSMGRScreen, VfxAppScr);

void VappGPSMGRScreen::onInit()
{
    VfxAppScr::onInit();
    setIsSmallScreen();

    const VappGPSMGRApp *GPSMGRApp ;
    VcpConfirmPopup *m_cfmPopup;
    VFX_OBJ_CREATE(m_cfmPopup,VcpConfirmPopup,this);

    GPSMGRApp = (VappGPSMGRApp *)(getApp()); // get cui instance

    if (GPSMGRApp->notify.owner == MMI_GPS_SRV_NOTIFY_OWNER_UP)
    {
        GPS_MGR_ptr = this;
    }
    else
    {
        GPS_MGR_CP_ptr = this;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VAPP_GPS_MGR_NOTIFY_TYPE, GPSMGRApp->notify.type);

     switch(GPSMGRApp->notify.type)
     {
        case MMI_GPS_SRV_NOTIFY_TYPE_POPUP:
            m_cfmPopup ->setInfoType(VCP_POPUP_TYPE_INFO);
            m_cfmPopup ->setText((const VfxWChar*)GPSMGRApp->notify.notify_p);
            m_cfmPopup ->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            m_cfmPopup ->m_signalButtonClicked.connect(this, &VappGPSMGRScreen::ConfirmSelected);
            //m_cmdPopup ->setAutoDestory(VFX_FALSE);
            m_cfmPopup ->show(VFX_TRUE);

            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            break;

        case MMI_GPS_SRV_NOTIFY_TYPE_CONFIRM:
            m_cfmPopup ->setInfoType(VCP_POPUP_TYPE_INFO);
            m_cfmPopup ->setText((const VfxWChar*)GPSMGRApp->notify.notify_p);
            m_cfmPopup ->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            m_cfmPopup ->m_signalButtonClicked.connect(this, &VappGPSMGRScreen::ConfirmSelected);
            m_cfmPopup ->show(VFX_TRUE);

            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            break;

        default:
            m_cfmPopup ->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_cfmPopup ->setText((VfxResId)STR_GLOBAL_ERROR);
            m_cfmPopup ->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            m_cfmPopup ->show(VFX_TRUE);

            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            break;
        }
}

void VappGPSMGRScreen::onDeinit()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VAPP_GPS_MGR_ON_DEINIT);
    const VappGPSMGRApp *GPSMGRApp;

    GPSMGRApp = (VappGPSMGRApp *)(getApp()); // get cui instance

    if (GPSMGRApp->notify.owner == MMI_GPS_SRV_NOTIFY_OWNER_UP)
    {
        GPS_MGR_ptr = NULL;
    }
    else
    {
        GPS_MGR_CP_ptr = NULL;
    }
    VfxScreen::onDeinit();
}

void VappGPSMGRScreen::timeOut()
{
    exit();
}

void VappGPSMGRScreen::ConfirmSelected(VfxObject* obj, VfxId id)
{
    const VappGPSMGRApp *GPSMGRApp;

    GPSMGRApp = (VappGPSMGRApp *)(getApp()); // get cui instance

    if (GPSMGRApp->notify.owner == MMI_GPS_SRV_NOTIFY_OWNER_UP)
    {
    #ifdef __AGPS_USER_PLANE__
        switch(id)
        {
            case VCP_CONFIRM_POPUP_BUTTON_YES:
                mmi_gps_mgr_notify_accept();
                break;
            case VCP_CONFIRM_POPUP_BUTTON_NO:
                mmi_gps_mgr_notify_decline();
                break;
            case VCP_CONFIRM_POPUP_BUTTON_OK:
                mmi_gps_mgr_exit_notify_src();
                break;
        }
    #endif
    }
    else
    {
    #ifdef __AGPS_CONTROL_PLANE__
        switch(id)
        {
            case VCP_CONFIRM_POPUP_BUTTON_YES:
                mmi_gps_mgr_mtlr_notify_accept();
                break;
            case VCP_CONFIRM_POPUP_BUTTON_NO:
                mmi_gps_mgr_mtlr_notify_decline();
                break;
            case VCP_CONFIRM_POPUP_BUTTON_OK:
                mmi_gps_mgr_exit_mtlr_notify_src();
                break;
        }
    #endif
    }

    exit();
}

#endif /*__GPS_SUPPORT__*/


