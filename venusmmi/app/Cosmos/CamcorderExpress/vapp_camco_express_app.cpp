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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_features_camcorder.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"

#include "SettingProfileEnum.h"
#include "custom_events_notify.h"

#include "resource_camcorder_skins.h"

// for LCD size
#include "lcd_sw_inc.h"

#include "SoundEffect.h"
#include "gpiosrvgprot.h"

#include "Resource_audio.h"
#include "UCMSrvGprot.h"
#include "AlarmFrameworkProt.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#include "Wgui_categories_util.h"
#include "FileMgrResDef.h"

#include "ReminderSrvGprot.h"

// for backlight
#include "gpiosrvprot.h"

#include "custom_rec_config.h"

// for check fi in HS/main menu
#include "Vapp_launcher_gprot.h"

// for power off
#include "ShutdownSrvGprot.h"

#ifdef __cplusplus
}
#endif

#ifdef __VAPP_CAMCO_EXPRESS__

#include "AppMgrSrvGprot.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_camco_express_gprot.h"
#include "vapp_camco_express_app.h"
#include "vapp_camco_express_hw.h"
#include "vapp_camco_express_osd_mgr.h"
#include "vapp_camco_express_osd_state.h"

#include "vtst_rt_main.h"

#include "vapp_gallery_gprot.h"

// for env check interface
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#include "USBSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"
#endif
#ifdef __MMI_BT_SUPPORT__
//#include "vapp_bt_storage.h"
#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
#include "mmi_rp_vapp_fontmgr_def.h"  // for EVT_ID_VAPP_FONT_CHANGED
#endif

// for touch feedback
#include "vfx_adp_device.h"

extern "C" void gdi_lcd_set_high_priority_freeze(BOOL is_freeze);
static double vapp_camco_get_julian_day(MYTIME *p);

MMI_ID VappCamcoPage::m_errStr = 0;

// for global setting
vapp_camco_global_config_struct g_vapp_camco_config;

// for save previous captured pciture name
WCHAR g_vapp_camco_ext_calling_file_name[256];
WCHAR g_vapp_camco_last_file_name[256];

// for saving CUI setting
vcui_camco_setting_limit_struct g_vapp_camco_limit;
vcui_camco_setting_limit_struct g_vapp_camco_rec_limit[5];

// 0 mean 50Hz , 1 mean 60Hz
// customer can config that for different product
const U8 g_vapp_camco_banding_setting = 1;

VFX_IMPLEMENT_CLASS("VappCamcoApp", VappCamcoApp, VfxApp);

void VappCamcoApp::onInit(void)
{
    VfxApp::onInit();
}

void VappCamcoApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappCamcoScreen *scr;
    VFX_OBJ_CREATE(scr, VappCamcoScreen, this);
    scr->setCallingParam((*(vcui_camco_param_struct*)args));
    scr->show();
}

VFX_IMPLEMENT_CLASS("VcuiCamcoApp", VcuiCamcoApp, VfxCui);

void VcuiCamcoApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappCamcoScreen *scr;
    VFX_OBJ_CREATE(scr, VappCamcoScreen, this);
    scr->setCallingParam((*(vcui_camco_param_struct*)args));
    scr->show();
}

VFX_IMPLEMENT_CLASS("VcuiStandardCameraApp", VcuiStandardCameraApp, VfxCui);

void VcuiStandardCameraApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappCamcoScreen *scr;
    VFX_OBJ_CREATE(scr, VappCamcoScreen, this);
    scr->setCallingParam((*(vcui_camco_param_struct*)args));
    scr->show();
}

VFX_IMPLEMENT_CLASS("VcuiSlimCameraApp", VcuiSlimCameraApp, VfxCui);

void VcuiSlimCameraApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappCamcoScreen *scr;
    VFX_OBJ_CREATE(scr, VappCamcoScreen, this);
    scr->setCallingParam((*(vcui_camco_param_struct*)args));
    scr->show();
}

VFX_IMPLEMENT_CLASS("VcuiStandardRecorderApp", VcuiStandardRecorderApp, VfxCui);

void VcuiStandardRecorderApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappCamcoScreen *scr;
    VFX_OBJ_CREATE(scr, VappCamcoScreen, this);
    scr->setCallingParam((*(vcui_camco_param_struct*)args));
    scr->show();
}

VFX_IMPLEMENT_CLASS("VappCamcoScreen", VappCamcoScreen, VfxMainScr);

void VappCamcoScreen::onInit()
{
    VfxMainScr::onInit();
    setBgColor(VFX_COLOR_BLACK);
}

void VappCamcoScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappCamcoPage *page;
    VFX_OBJ_CREATE(page, VappCamcoPage, this);
    page->setCallingParam(m_param);
    pushPage(0, page);
}

void VappCamcoScreen::onEnter(VfxBool isBackward)
{
    VfxMainScr::onEnter(isBackward);

    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);

#if defined(__MMI_CABC__)
    setCABCMode(MMI_FRM_CABC_MODE_MOVING);
#endif
}

void VappCamcoScreen::onExit(VfxBool isBackward)
{
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, FALSE, VFX_SCR_TRANSIT_PRIORITY_USER);

    VfxMainScr::onExit(isBackward);
}

void VappCamcoScreen::setCallingParam(vcui_camco_param_struct param)
{
    m_param = param;
}

void VappCamcoScreen::onRotate(const VfxScreenRotateParam &param)
{
    VfxRect parentBounds = getParentFrame()->getBounds();

    setAnchor(0.5f, 0.5f);
    setPos(parentBounds.size.width / 2, parentBounds.size.height / 2);
    setSize(parentBounds.size);
    //VfxMainScr::onRotate
}

VFX_IMPLEMENT_CLASS("VappCamcoPage", VappCamcoPage, VfxPage);

void VappCamcoPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_INIT);

    VAPP_CAMCO_START_LOGGING("AIN");

    VfxPage::onInit();

    setAutoAnimate(VFX_FALSE);

    VFX_OBJ_CREATE(m_previewFrame,VfxVideoFrame,this);
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    m_previewFrame->setHint((VfxVideoFrame::HintEnum)((VfxU32)VfxVideoFrame::HINT_APP_CONTROL | (VfxU32)VfxVideoFrame::HINT_LIVE_ROTATION));
#else
    m_previewFrame->setHint(VfxVideoFrame::HINT_LIVE_ROTATION);
#endif

#ifdef VAPP_CAMCO_MODIS_PIC_PREVIEW
    VFX_OBJ_CREATE(m_picturePreviewFrame,VfxFrame,this);
    m_picturePreviewFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    m_picturePreviewFrame->setAnchor(0, 0);
    m_picturePreviewFrame->setPos(0, 0);
    m_picturePreviewFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    WCHAR fileName[30];
    CHAR fileNameAsc[15] = "";

    sprintf(fileNameAsc, "%c:\\1.jpg", SRV_FMGR_CARD_DRV);
    mmi_asc_to_wcs(fileName, fileNameAsc);

    VfxImageSrc s = VfxImageSrc(VFX_WSTR_MEM(fileName));

    m_picturePreviewFrame->setImgContent(s);
#endif

    VFX_OBJ_CREATE(m_enterScreenOSD,OSDStartingState,this);

    m_appID = getApp()->getGroupId();

    m_previewFrame->setAnchor(0.5, 0.5);
    m_previewFrame->setBgColor(VFX_COLOR_BLACK);
    m_previewFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    m_previewFrame->setBuffer(m_appID);
    m_previewFrame->setAutoAnimate(VFX_FALSE);

    m_state = VAPP_CAMCO_STATE_EXIT;

    m_enterStateCB = VappCamcoPopupCallbackFunc(this, &VappCamcoPage::popupEntercallback);
    m_recoverStateCB = VappCamcoPopupCallbackFunc(this, &VappCamcoPage::popupRecovercallback);
    m_exitStateCB = VappCamcoPopupCallbackFunc(this, &VappCamcoPage::exitCamcoCUI);

    m_camRestartPreviewCallback = VappCamcoRestartCallbackFunc(this, &VappCamcoPage::camRestartPreview);
    m_recRestartPreviewCallback = VappCamcoRestartCallbackFunc(this, &VappCamcoPage::recRestartPreview);

    setStatusBar(VFX_FALSE);


    VFX_OBJ_CREATE(m_autoExitTimer, VfxTimer, this);

    VFX_OBJ_CREATE(m_errorExitTimer, VfxTimer, this);
    m_errorExitTimer->setStartDelay(1500);
    m_errorExitTimer->m_signalTick.connect(this, &VappCamcoPage::onErrorExitTimerTick);

    VFX_OBJ_CREATE(m_postEnterTimer, VfxTimer, this);
    m_postEnterTimer->setStartDelay(100);
    m_postEnterTimer->m_signalTick.connect(this, &VappCamcoPage::onEntered);

    VFX_OBJ_CREATE(m_delayPreviewTimer, VfxTimer, this);
    m_delayPreviewTimer->setStartDelay(250);
    m_delayPreviewTimer->m_signalTick.connect(this, &VappCamcoPage::onPreviewFrameDoneDelayTick);

    // init countdown
    VFX_OBJ_CREATE(countdownCycTimer, VfxTimer, this);
    countdownCycTimer->m_signalTick.connect(this, &VappCamcoPage::countdownCyclic);

#ifdef __FACE_DETECTION_SUPPORT__
    // smile detect
    VFX_OBJ_CREATE(m_smileDetectCycTimer, VfxTimer, this);
    m_smileDetectCycTimer->setStartDelay(50);
    m_smileDetectCycTimer->m_signalTick.connect(this, &VappCamcoPage::smiledetectCyclic);
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    VFX_OBJ_CREATE(m_smileDetectSuccessTimer, VfxTimer, this);
    m_smileDetectSuccessTimer->setStartDelay(10);
    m_smileDetectSuccessTimer->m_signalTick.connect(this, &VappCamcoPage::smiledetectSuccess);
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    // scene detect
    VFX_OBJ_CREATE(m_sceneDetectCycTimer, VfxTimer, this);
    m_sceneDetectCycTimer->setStartDelay(50);
    m_sceneDetectCycTimer->m_signalTick.connect(this, &VappCamcoPage::sceneDetectCyclic);
#endif

    // record
    VFX_OBJ_CREATE(m_recordToneTimer, VfxTimer, this);
    m_recordToneTimer->setStartDelay(300);
    m_recordToneTimer->m_signalTick.connect(this, &VappCamcoPage::recordToneCyclic);

    VFX_OBJ_CREATE(m_recordUpdateTimer, VfxTimer, this);
    m_recordUpdateTimer->setStartDelay(400);
    m_recordUpdateTimer->m_signalTick.connect(this, &VappCamcoPage::recordingCyclic);

    VFX_OBJ_CREATE(m_popupTimer, VfxTimer, this);

    // init calling param
    m_param.mode = VCUI_CAMCO_FULL;
    m_param.level = VCUI_CAMCO_SETTING_FULL;
    m_param.settingLimitNum = 0;
    m_param.settingLimitation = NULL;

    // init flag
    m_hwFlag.isPowerOn          =   VFX_FALSE;
    m_hwFlag.isPreviewStart     =   VFX_FALSE;
    m_hwFlag.isAFon             =   VFX_FALSE;
    m_hwFlag.isAFsuccess        =   VFX_FALSE;
    m_hwFlag.isTakepicFailed    =   VFX_FALSE;
    m_hwFlag.isBurstshotFinish  =   VFX_FALSE;
    m_hwFlag.isOnRecord         =   VFX_FALSE;
    m_hwFlag.isRecordFailed     =   VFX_FALSE;
    m_hwFlag.isRecSaveSuccess   =   VFX_FALSE;
    m_hwFlag.isSmiledetectStart =   VFX_FALSE;
    m_hwFlag.isHDRing           =   VFX_FALSE;
    m_hwFlag.isCalBgProcessOn   =   VFX_TRUE;

    m_isPreemptable             =   VFX_TRUE;
    m_isExtCalling              =   VFX_FALSE;
    m_isMainLcdPreview          =   VFX_TRUE;
    m_isDelayPreview            =   VFX_FALSE;
    m_isStartingPreview         =   VFX_FALSE;
    m_isSaveBeforeLeave         =   VFX_FALSE;

    m_isOSDinSmileDetectMode    =   VFX_FALSE;

    m_isTonePlaying             =   VFX_FALSE;
    m_isAFTonePlaying           =   VFX_FALSE;

    m_isAppInited               =   VFX_FALSE;
    m_isStartingApp             =   VFX_TRUE;
    m_isStartingHorz            =   VFX_TRUE;

    m_isFontChanged             =   VFX_FALSE;

    m_isGetFileList             =   VFX_FALSE;

    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, storageChangeNotifyHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, storageChangeNotifyHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, storageChangeNotifyHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT, storageChangeNotifyHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, storageChangeNotifyHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, storageChangeNotifyHdlr, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, storageChangeNotifyHdlr, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &USBChangeNotigyHdlr, this);
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    mmi_frm_cb_reg_event(EVT_ID_VAPP_FONT_CHANGED, fontChangeNotigyHdlr, this);
#endif

    memset(g_vapp_camco_last_file_name, 0, sizeof(WCHAR)*256);

    VAPP_CAMCO_STOP_LOGGING("AIN");
}

void VappCamcoPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_DEINIT);

    VAPP_CAMCO_START_LOGGING("ADI");

    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, storageChangeNotifyHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, storageChangeNotifyHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, storageChangeNotifyHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT, storageChangeNotifyHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, storageChangeNotifyHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, storageChangeNotifyHdlr, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, storageChangeNotifyHdlr, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &USBChangeNotigyHdlr, this);
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_FONT_CHANGED, fontChangeNotigyHdlr, this);
#endif

    // it may still onEnter not init OSD / Setting
    if(m_isStartingApp)
    {
        deinitEnv();

        VfxPage::onDeinit();

        return;
    }

    if(m_state == VAPP_CAMCO_STATE_REC_INT_SAVING || m_state == VAPP_CAMCO_STATE_REC_SAVING || (m_hwFlag.isRecSaveSuccess && !m_hwFlag.isRecSaveCallback && m_isExtCalling))
    {
        vapp_camco_rec_stop_save_video();
    }

    vapp_camco_reset_hw_obj();

    if(m_isExtCalling)
    {
        vapp_camco_popup_callback_param_struct param;
        param.next_state = VAPP_CAMCO_STATE_EXIT;
        exitCamcoCUI(param);
    }
    enterState(VAPP_CAMCO_STATE_EXIT);

    deinitEnv();

    VfxPage::onDeinit();

    VAPP_CAMCO_STOP_LOGGING("ADI");
}

void VappCamcoPage::onErrorExitTimerTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_ERROR_EXIT_TIMER_TICK);
    getApp()->exit();
}

void VappCamcoPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    vapp_camco_osd_screen_param_struct rotParam;

    rotParam.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_ROT;

    if(!m_isStartingApp && m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER && m_Setting->getValue(VAPP_CAMCO_SETTING_VISCODEC) == VAPP_CAMCO_VISCODEC_3GP)
    {
        if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
        {
            rotParam.isHorz = m_isOSDHorz = VFX_TRUE;
            rotParam.isMirror = m_isOSDMirror = VFX_FALSE;
            param.rotateTo = m_currentRotation = VFX_SCR_ROTATE_TYPE_270;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, -1);
        }
        else
        {
            rotParam.isHorz = m_isOSDHorz = VFX_FALSE;
            rotParam.isMirror = m_isOSDMirror = VFX_FALSE;
            param.rotateTo = m_currentRotation = VFX_SCR_ROTATE_TYPE_0;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, -2);
        }
    }
    else
    {
        switch (param.rotateTo)
        {
            case VFX_SCR_ROTATE_TYPE_0:
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, 1);
                rotParam.isHorz = VFX_FALSE;
                rotParam.isMirror = VFX_FALSE;
                break;
            case VFX_SCR_ROTATE_TYPE_90:
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, 2);
                rotParam.isHorz = VFX_TRUE;
                rotParam.isMirror = VFX_TRUE;
                break;
            case VFX_SCR_ROTATE_TYPE_180:
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, 3);
                rotParam.isHorz = VFX_FALSE;
                rotParam.isMirror = VFX_TRUE;
                break;
            case VFX_SCR_ROTATE_TYPE_270:
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, 4);
                rotParam.isHorz = VFX_TRUE;
                rotParam.isMirror = VFX_FALSE;
                break;
        }
        m_isOSDHorz = rotParam.isHorz;
        m_isOSDMirror = rotParam.isMirror;
        m_currentRotation = param.rotateTo;
    }

    if(m_state == VAPP_CAMCO_STATE_REC_SAVE_DONE && !m_isDelayPreview && !m_isStartingPreview)
    {
        updateVideoFramRotate(VFX_TRUE, param.rotateFrom, param.rotateTo);
    }
    else
    {
        updateVideoFramRotate(VFX_FALSE, VFX_SCR_ROTATE_TYPE_NORMAL, VFX_SCR_ROTATE_TYPE_NORMAL);
    }

    if(!m_isStartingApp)
        m_OSD->setScreenParam(rotParam);
    else
        m_enterScreenOSD->rotateOSD(param.rotateFrom, param.rotateTo);
#else

    VfxBool isHorz = VFX_TRUE;

    // for show the first scree usage
    if(m_isStartingApp)
    {
        if(m_isStartingHorz)
        {
            m_isOSDMirror = VFX_FALSE;
            m_isOSDHorz = VFX_TRUE;
            param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, -1);
        }
        else
        {
            m_isOSDMirror = VFX_FALSE;
            m_isOSDHorz = VFX_FALSE;
            param.rotateTo = VFX_SCR_ROTATE_TYPE_0;
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, -2);
        }
        return;
    }
    else
    {

        if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
        {
            if((m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA && m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER))
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, 1);
                isHorz = VFX_FALSE;
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, 2);
                isHorz = VFX_TRUE;
            }
        }
        else if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_QUERY_ROTATE, 3);
            isHorz = VFX_FALSE;
        }
    }

    vapp_camco_osd_screen_param_struct rotParam;
    rotParam.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_ROT;
    rotParam.isMirror = m_isOSDMirror = VFX_FALSE;

#if !defined (HORIZONTAL_CAMERA)
    isHorz = VFX_FALSE;
#endif

    if(isHorz)
    {
        rotParam.isHorz = m_isOSDHorz = VFX_TRUE;

        m_OSD->setScreenParam(rotParam);
        param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
        m_currentRotation = param.rotateTo;
    }
    else
    {
        rotParam.isHorz = m_isOSDHorz = VFX_FALSE;

        m_OSD->setScreenParam(rotParam);
        param.rotateTo = VFX_SCR_ROTATE_TYPE_0;
        m_currentRotation = param.rotateTo;
    }
#endif
}

void VappCamcoPage::updateVideoFramRotate(VfxBool needRotateContent, VfxScrRotateTypeEnum from, VfxScrRotateTypeEnum to)
{
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_UPDATE_VDO_FRAME_ROTATE, needRotateContent, from, to);

    gdi_handle handleT = m_previewFrame->getLayerHandle();
    if(handleT)
    {
        if(m_isOSDHorz)
        {
            m_previewFrame->setPos(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1);

            if(!m_isVideoLayerHorz)
                m_previewFrame->setSize(m_previewWindow.size.height, m_previewWindow.size.width);
            else
                m_previewFrame->setSize(m_previewWindow.size.width, m_previewWindow.size.height);
        }
        else
        {
            m_previewFrame->setPos(GDI_LCD_WIDTH>>1, GDI_LCD_HEIGHT>>1);

            if(m_isVideoLayerHorz)
                m_previewFrame->setSize(m_previewWindow.size.height, m_previewWindow.size.width);
            else
                m_previewFrame->setSize(m_previewWindow.size.width, m_previewWindow.size.height);
        }

        gdi_layer_push_and_set_active(handleT);

        gdi_handle handleS;
        S32 width, height;

        if(needRotateContent)
        {
            U8 *buf_ptr;
            gdi_color_format cf;

            gdi_layer_get_dimension(&width, &height);
            gdi_layer_get_buffer_ptr(&buf_ptr);
            gdi_layer_get_color_format(&cf);

            gdi_layer_create_cf_using_outside_memory(
                cf,
                0,
                0,
                width,
                height,
                &handleS,
                (U8*)m_appMemQuickViewBuffer,
                width*height*2);
            memcpy(m_appMemQuickViewBuffer, buf_ptr, width*height*2);

            gdi_layer_resize(m_previewFrame->getSize().width, m_previewFrame->getSize().height);

            VfxScrRotateTypeEnum angle = (VfxScrRotateTypeEnum)((to + 4 - from) % 4);
            switch (angle)
            {
                case VFX_SCR_ROTATE_TYPE_0:
                    mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_0);
                    break;
                case VFX_SCR_ROTATE_TYPE_90:
                    mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_90);
                    break;
                case VFX_SCR_ROTATE_TYPE_180:
                    mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_180);
                    break;
                case VFX_SCR_ROTATE_TYPE_270:
                    mdi_util_rotate_layer_partial_region(handleS, 0, 0, width, height, handleT, GDI_LAYER_ROTATE_270);
                    break;
            }
            gdi_layer_free(handleS);

        }
        else
        {
            if(m_isVideoLayerHorz)
            {
                if(m_isOSDHorz)
                    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
                else
                    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
                gdi_layer_resize(m_previewWindow.size.width, m_previewWindow.size.height);
                gdi_layer_set_position((LCD_HEIGHT - m_previewWindow.size.width)/2, (LCD_WIDTH - m_previewWindow.size.height)/2);
            }
            else
            {
                if(m_isOSDHorz)
                    gdi_layer_set_rotate(GDI_LAYER_ROTATE_270);
                else
                    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
                gdi_layer_resize(m_previewWindow.size.width, m_previewWindow.size.height);
                gdi_layer_set_position((LCD_WIDTH - m_previewWindow.size.width)/2, (LCD_HEIGHT - m_previewWindow.size.height)/2);
            }
        }

        gdi_layer_pop_and_restore_active();
    }
#endif
}

void VappCamcoPage::setCallingParam(vcui_camco_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SET_CALLINGPARAM, m_param.mode);

    m_param = param;
}

void VappCamcoPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_EXIT, isBackward);

    VAPP_CAMCO_START_LOGGING("AEX");

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    // it may still onEnter not init OSD / Setting
    if(m_isStartingApp)
    {
        m_state = VAPP_CAMCO_STATE_EXIT;

        m_postEnterTimer->stop();

        ClearKeyEvents();

        decheckEnv();

        VfxPage::onExit(isBackward);

        return;
    }

    m_postEnterTimer->stop();

    stopPopupScreen();

    exitState();

    // should be called after stop preview because gdi will remove vdo frame element
    // stop preview will deactivate
    deinitEnv();

    // set state when change to be in history
    switch (m_state)
    {
        case VAPP_CAMCO_STATE_CAM_PREVIEW:
            if(m_isDelayPreview || m_isStartingPreview)
            {
                // the case happen when exit at switch app and frame not ready
                if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
                {
                    m_state = VAPP_CAMCO_STATE_REC_INT_PREVIEW;
                    break;
                }
            }
        case VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED:
        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
        case VAPP_CAMCO_STATE_CAM_FOCUSING:
        case VAPP_CAMCO_STATE_CAM_FOCUSED:
        case VAPP_CAMCO_STATE_CAM_CAPTURE:
        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
            m_state = VAPP_CAMCO_STATE_CAM_INT_PREVIEW;
            break;

        case VAPP_CAMCO_STATE_REC_PREVIEW:
            if(m_isDelayPreview || m_isStartingPreview)
            {
                if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                {
                    m_state = VAPP_CAMCO_STATE_CAM_INT_PREVIEW;
                    break;
                }
            }
        case VAPP_CAMCO_STATE_REC_PREVIEW_FAILED:
        case VAPP_CAMCO_STATE_REC_FOCUSING:
        case VAPP_CAMCO_STATE_REC_FOCUSED:
            m_state = VAPP_CAMCO_STATE_REC_INT_PREVIEW;
            break;

        case VAPP_CAMCO_STATE_REC_RECORDING:
        case VAPP_CAMCO_STATE_REC_PAUSE:
            if (m_hwFlag.isRecSaveSuccess && !m_isFontChanged)
            {
                m_state = VAPP_CAMCO_STATE_REC_INT_SAVING;
            }
            else
            {
                m_state = VAPP_CAMCO_STATE_REC_INT_PREVIEW;
            }
            break;

        case VAPP_CAMCO_STATE_REC_SAVING:
            if(m_isFontChanged)
            {
                m_state = VAPP_CAMCO_STATE_REC_INT_PREVIEW;
            }
            else
            {
                m_state = VAPP_CAMCO_STATE_REC_INT_SAVING;
            }
            break;

        case VAPP_CAMCO_STATE_REC_SAVE_DONE:
            m_state = VAPP_CAMCO_STATE_REC_INT_PREVIEW;
            break;

        case VAPP_CAMCO_STATE_ENTER_FAIL:
            m_state = VAPP_CAMCO_STATE_EXIT;
            break;

        case VAPP_CAMCO_STATE_EXIT:
            break;

        default:
        #ifndef __MMI_BACKGROUND_CALL__
            if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) <= 0 && !m_isStartingPreview && !m_isDelayPreview)
            {
                MMI_ASSERT(0);
            }
        #endif
            break;
    }

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        vapp_camco_cam_power_off(&m_cam_power_off_param);
    else
        vapp_camco_rec_power_off(&m_rec_power_off_param);

    m_Setting->storeSetting();

    setStartingFilenameIdx();

    m_OSD->exitState();

#ifdef __FACE_DETECTION_SUPPORT__
    m_smileDetectCycTimer->stop();
#endif
#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    m_smileDetectSuccessTimer->stop();
#endif
#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    m_sceneDetectCycTimer->stop();
#endif

    m_previewFrame->unPrepare();
    m_delayPreviewTimer->stop();

    if(m_isGetFileList)
    {
        srv_fmgr_filelist_abort(m_fileListHandle);
        srv_fmgr_filelist_destroy(m_fileListHandle);
        m_isGetFileList = VFX_FALSE;
    }
    m_isStartingPreview = VFX_FALSE;
    m_isDelayPreview = VFX_FALSE;
    m_isFontChanged = VFX_FALSE;

    ClearKeyEvents();

    decheckEnv();

    if(m_isExtCalling)
    {
        resetMem();
        m_state = VAPP_CAMCO_STATE_EXIT;
    }
    else
    {
        resetMem();
    }
    VfxPage::onExit(isBackward);

    VAPP_CAMCO_STOP_LOGGING("AEX");
}

void VappCamcoPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_ENTER, isBackward);

    VAPP_CAMCO_START_LOGGING("AEN");

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    VfxPage::onEnter(isBackward);

    getStartingFilenameIdx();

    VappCamcoPage::m_errStr = 0;

    if(checkEnv())
    {
        initEnv();

        // show a screen firstly
        // ========================================================================================
        m_isStartingApp = VFX_TRUE;

        if(m_param.mode == VCUI_CAMCO_RECORDER)
        {
            m_osd_starting_state_param.isCamera = VFX_FALSE;
            m_osd_starting_state_param.isExtCalling = VFX_TRUE;
        }
        else if(m_param.mode == VCUI_CAMCO_CAMERA)
        {
            m_osd_starting_state_param.isCamera = VFX_TRUE;
            m_osd_starting_state_param.isExtCalling = VFX_TRUE;
        }
        else
        {
            if(m_isAppInited)
            {
                if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                    m_osd_starting_state_param.isCamera = VFX_TRUE;
                else
                    m_osd_starting_state_param.isCamera = VFX_FALSE;
            }
            else
            {
                m_osd_starting_state_param.isCamera = VFX_TRUE;
            }

            m_osd_starting_state_param.isExtCalling = VFX_FALSE;
        }
    #if defined(__VAPP_CAMCO_ROTATABLE_UI__)
        switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
        {
            case MMI_FRM_SCREEN_ROTATE_0:
                m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_0;
                m_osd_starting_state_param.isOSDHorz = m_isOSDHorz = VFX_FALSE;
                m_osd_starting_state_param.isOSDMirror = m_isOSDMirror = VFX_FALSE;
                break;
            case MMI_FRM_SCREEN_ROTATE_90:
                m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_90;
                m_osd_starting_state_param.isOSDHorz = m_isOSDHorz = VFX_TRUE;
                m_osd_starting_state_param.isOSDMirror = m_isOSDMirror = VFX_FALSE;

                break;
            case MMI_FRM_SCREEN_ROTATE_180:
                m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_180;
                m_osd_starting_state_param.isOSDHorz = m_isOSDHorz = VFX_FALSE;
                m_osd_starting_state_param.isOSDMirror = m_isOSDMirror = VFX_TRUE;

                break;
            case MMI_FRM_SCREEN_ROTATE_270:
                m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_270;
                m_osd_starting_state_param.isOSDHorz = m_isOSDHorz = VFX_TRUE;
                m_osd_starting_state_param.isOSDMirror = m_isOSDMirror = VFX_TRUE;

                break;
        }
    #else

        vapp_camco_setting_set_struct m_settingSet;
        CamcoSettingMgr::getNvRamSetting(&m_settingSet);
        if(isBackward || m_osd_starting_state_param.isExtCalling)
        {
            if(m_settingSet.active_cam == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                if((m_settingSet.active_app == VAPP_CAMCO_APP_CAMERA && m_settingSet.capsize == VAPP_CAMCO_CAPSIZE_WALLPAPER))
                {
                    m_osd_starting_state_param.isOSDHorz= VFX_FALSE;
                    m_osd_starting_state_param.isOSDMirror = VFX_FALSE;
                    m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_0;
                    m_isStartingHorz = VFX_FALSE;
                }
                else
                {
                    m_osd_starting_state_param.isOSDHorz= VFX_TRUE;
                    m_osd_starting_state_param.isOSDMirror = VFX_FALSE;
                    m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_270;
                    m_isStartingHorz = VFX_TRUE;
                }
            }
            else
            {
                m_osd_starting_state_param.isOSDHorz= VFX_FALSE;
                m_osd_starting_state_param.isOSDMirror = VFX_FALSE;
                m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_0;
                m_isStartingHorz = VFX_FALSE;
            }
        }
        else
        {
            // new enter camcorder
            // it must be camera app with rear sensor
            if(m_settingSet.capsize == VAPP_CAMCO_CAPSIZE_WALLPAPER)
            {
                m_osd_starting_state_param.isOSDHorz= VFX_FALSE;
                m_osd_starting_state_param.isOSDMirror = VFX_FALSE;
                m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_0;
                m_isStartingHorz = VFX_FALSE;
            }
            else
            {
                m_osd_starting_state_param.isOSDHorz= VFX_TRUE;
                m_osd_starting_state_param.isOSDMirror = VFX_FALSE;
                m_osd_starting_state_param.scrnAngle = VFX_SCR_ROTATE_TYPE_270;
                m_isStartingHorz = VFX_TRUE;
            }
        }
    #endif
        m_enterScreenOSD->enterState(&m_osd_starting_state_param);

        // ========================================================================================

        // force blt this frame even Anti is on
        gdi_lcd_set_high_priority_freeze(KAL_FALSE);

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();

        m_postEnterTimer->start();
    }
    else
    {
        initApp();
        m_isStartingApp = VFX_FALSE;
        enterState(VAPP_CAMCO_STATE_ENTER_FAIL);
    }
    VAPP_CAMCO_STOP_LOGGING("AEN");
}

void VappCamcoPage::onEntered(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_ENTERED);

    VAPP_CAMCO_START_LOGGING("AEE");

    m_enterScreenOSD->exitState();
    m_isStartingApp = VFX_FALSE;

    initApp();

    configMem();

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        if(vapp_camco_cam_power_on(&m_cam_power_on_param) == MDI_RES_CAMERA_SUCCEED)
        {
            if(m_state == VAPP_CAMCO_STATE_EXIT)
            {
                // it may use backup sensor so that capability queried may be not the same as default sensor before power on
                // init setting again!
                //initSetting();

                enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            }
            else
            {
                recoverState(m_state);
            }
        }
        else
        {
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED);
        }
    }
    else
    {
        if(vapp_camco_rec_power_on(&m_rec_power_on_param) == MDI_RES_VDOREC_SUCCEED)
        {
            if(m_state == VAPP_CAMCO_STATE_EXIT)
            {
                // it may use backup sensor so that capability queried may be not the same as default sensor before power on
                // init setting again!
                // initSetting();

                enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            }
            else
            {
                recoverState(m_state);
            }
        }
        else
        {
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW_FAILED);
        }
    }
    VAPP_CAMCO_STOP_LOGGING("AEE");
}

void VappCamcoPage::exitState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_EXIT_STATE, m_state);

    switch (m_state)
    {
        case VAPP_CAMCO_STATE_CAM_PREVIEW:
            if(!m_hwFlag.isTakepicFailed)
            {
            #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
                vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);
            #endif
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
            }
            break;

        case VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED:
            break;

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        case VAPP_CAMCO_STATE_CAM_FOCUSING:
        case VAPP_CAMCO_STATE_CAM_FOCUSED:
            if(!m_hwFlag.isTakepicFailed)
            {
                vapp_camco_cam_autofocus_stop(&m_autofocus_param);
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
            }
            break;
    #endif

        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
            if(!m_hwFlag.isTakepicFailed)
            {
                countdownCycTimer->stop();

                deinitCountDownSound();

            #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
                vapp_camco_cam_autofocus_stop(&m_autofocus_param);
            #endif
            #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
                vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);
            #endif
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
            }

            break;

        case VAPP_CAMCO_STATE_CAM_CAPTURE:
            break;

        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
            break;

        case VAPP_CAMCO_STATE_REC_PREVIEW:
            if(!m_hwFlag.isRecordFailed)
            {
                vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
            }
            if(m_isTonePlaying)
            {
                m_recordToneTimer->stop();
                m_isTonePlaying = VFX_FALSE;
            }
            break;

        case VAPP_CAMCO_STATE_REC_PREVIEW_FAILED:
            break;

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        case VAPP_CAMCO_STATE_REC_FOCUSING:
        case VAPP_CAMCO_STATE_REC_FOCUSED:
            if(!m_hwFlag.isRecordFailed)
            {
                vapp_camco_cam_autofocus_stop(&m_autofocus_param);
                vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
            }
            if(m_isTonePlaying)
            {
                m_recordToneTimer->stop();
                m_isTonePlaying = VFX_FALSE;
            }
            break;
    #endif
        case VAPP_CAMCO_STATE_REC_RECORDING:
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
            m_isPreemptable = VFX_TRUE;
            srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, m_backlightBeforeRecording);
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
            m_recordUpdateTimer->stop();
            vapp_camco_rec_record_stop(&m_rec_record_param);
            if(!m_isFontChanged)
                vapp_camco_rec_save_video(&m_rec_record_save_param);
            if(!m_hwFlag.isRecSaveSuccess)
            {
                restoreFilename();
            }
            break;

        case VAPP_CAMCO_STATE_REC_PAUSE:
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
            m_isPreemptable = VFX_TRUE;
            srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, m_backlightBeforeRecording);
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
            vapp_camco_rec_record_stop(&m_rec_record_param);
            vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
            if(!m_isFontChanged)
                vapp_camco_rec_save_video(&m_rec_record_save_param);
            if(!m_hwFlag.isRecSaveSuccess)
            {
                restoreFilename();
            }
            break;

        case VAPP_CAMCO_STATE_REC_SAVING:
            if(m_isFontChanged)
                vapp_camco_rec_stop_save_video();
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
            m_isPreemptable = VFX_TRUE;
            break;

        case VAPP_CAMCO_STATE_REC_SAVE_DONE:
            break;

        case VAPP_CAMCO_STATE_ENTER_FAIL:
            m_errorExitTimer->stop();
            break;

        default:
            break;
    }
}

void VappCamcoPage::enterState(vapp_camco_state_enum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_STATE, state, m_Setting->getCurrApp());

    if(state != VAPP_CAMCO_STATE_ENTER_FAIL && state != VAPP_CAMCO_STATE_INT_ENTER_FAIL)
    {
        if (m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        {
            if (state > VAPP_CAMCO_STATE_CAM_INT_PREVIEW)
            {
                /* The current app is camera, the state shouldn't belong to the recorder state */
                MMI_ASSERT(0);
            }
        }
        else
        {
            if ((state > VAPP_CAMCO_STATE_EXIT &&  state < VAPP_CAMCO_STATE_REC_PREVIEW))
            {
                /* The current app is recorder, the state shouldn't belong to the camera state */
                MMI_ASSERT(0);
            }
        }
    }

    if(!srv_shutdown_is_running())
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);
#endif

    if(!m_isPreemptable)
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
        m_isPreemptable = MMI_TRUE;
    }

    /* Enter the next state */
    switch (state)
    {
        case VAPP_CAMCO_STATE_EXIT:
            enterExitState();
            break;

        case VAPP_CAMCO_STATE_CAM_PREVIEW:
            enterCamPreviewState();
            break;

        case VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED:
            enterCamPreviewFailedState();
            break;

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        case VAPP_CAMCO_STATE_CAM_FOCUSING:
            enterCamFocusingState();
            break;

        case VAPP_CAMCO_STATE_CAM_FOCUSED:
            enterCamFocusedState();
            break;
    #endif

        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
            enterCamCountdownState();
            break;

        case VAPP_CAMCO_STATE_CAM_CAPTURE:
            enterCamCaptureState();
            break;

        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
            enterCamSaveDoneState();
            break;

        case VAPP_CAMCO_STATE_REC_PREVIEW:
            enterRecPreviewState();
            break;

        case VAPP_CAMCO_STATE_REC_PREVIEW_FAILED:
            enterRecPreviewFailedState();
            break;

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        case VAPP_CAMCO_STATE_REC_FOCUSING:
            enterRecFocusingState();
            break;

        case VAPP_CAMCO_STATE_REC_FOCUSED:
            enterRecFocusedState();
            break;
    #endif

        case VAPP_CAMCO_STATE_REC_RECORDING:
            enterRecRecordingState();
            break;

        case VAPP_CAMCO_STATE_REC_PAUSE:
            enterRecPauseState();
            break;

        case VAPP_CAMCO_STATE_REC_SAVING:
            enterRecSavingState();
            break;

        case VAPP_CAMCO_STATE_REC_SAVE_DONE:
            enterRecSaveDoneState();
            break;

        case VAPP_CAMCO_STATE_ENTER_FAIL:
            enterEnterFailState();
            break;

        default:
            break;
    }
}


void VappCamcoPage::recoverState(vapp_camco_state_enum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RECOVER_STATE, state, 0);

    switch (state)
    {
        case VAPP_CAMCO_STATE_CAM_INT_PREVIEW:
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;

        case VAPP_CAMCO_STATE_REC_INT_PREVIEW:
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;

        case VAPP_CAMCO_STATE_REC_INT_SAVING:
            if (m_hwFlag.isRecSaveCallback  && m_recordSaveResult == MDI_RES_VDOREC_SUCCEED)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RECOVER_STATE, state, 1);
                enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            }
            else if (m_hwFlag.isRecSaveCallback)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RECOVER_STATE, state, 2);
                setState(VAPP_CAMCO_STATE_REC_SAVING);

                vapp_camco_popup_param_struct param;
                param.isConfirm = VFX_TRUE;
                param.isNeedClearScrn = VFX_TRUE;
                param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                param.callback = m_recoverStateCB;
                param.result = m_recordSaveResult;
                showPopupScreen(&param);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RECOVER_STATE, state, 3);
                setState(VAPP_CAMCO_STATE_REC_SAVING);
                m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_SAVING);
                m_osd_hint_state_param.isPreviewON = VFX_FALSE;
                m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
                m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
                m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
                m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;

                m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
            }
            break;

        default:
            break;
    }
}

VfxBool VappCamcoPage::checkEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECKENV, -1);

    if (isInCall() /*&& m_state == VAPP_CAMCO_STATE_EXIT*/)
    {

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECKENV, 1);

        VappCamcoPage::m_errStr = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;

        return VFX_FALSE;
    }

#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECKENV, 2);

        VcpPopupTypeEnum popupType;
        VappCamcoPage::m_errStr = vapp_usb_get_error_info(0, &popupType);

        return VFX_FALSE;
    }
#endif /* __MMI_USB_SUPPORT__ */

    return VFX_TRUE;
}

VfxBool VappCamcoPage::decheckEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_DECHECKENV);

    return VFX_TRUE;
}

void VappCamcoPage::configMem(void)
{
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

    m_appMemQuickViewBuffer = NULL;

    m_camFileNameBuf = (WCHAR*)gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    MMI_ASSERT(m_camFileNameBuf != NULL);
    memset(m_camFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);

    m_recFileNameBuf = (WCHAR*)gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    MMI_ASSERT(m_recFileNameBuf != NULL);
    memset(m_recFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CONFIG_MEM, GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL);

#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    m_appMemBuffer = applib_asm_alloc_nc_r(m_appID, GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL);
#else
    if(SRV_FMGR_FOLDER_FILELIST_MEM_SIZE > 10*1024)
        m_appMemBuffer = applib_asm_alloc_nc_r(m_appID, SRV_FMGR_FOLDER_FILELIST_MEM_SIZE);
    else
        m_appMemBuffer = applib_asm_alloc_nc_r(m_appID, 10*1024);
#endif

    if (m_appMemBuffer == NULL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CONFIG_MEM, -1);
        return;
    }
    m_appMemQuickViewBuffer = (VfxU8*)m_appMemBuffer;
    m_cam_capture_param.quickviewBuffer = m_appMemQuickViewBuffer;
    m_rec_fetch_param.quickviewBuffer = m_appMemQuickViewBuffer;
    m_osd_rec_preview_state_param.buffer = m_appMemQuickViewBuffer;
    m_osd_cam_preview_state_param.buffer = m_appMemQuickViewBuffer;
}

void VappCamcoPage::resetMem(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESET_MEM, m_appMemBuffer);

    if(m_appMemBuffer)
        applib_asm_free_r(m_appID, m_appMemBuffer);
    m_appMemBuffer = NULL;

    gui_free(m_camFileNameBuf);
    m_camFileNameBuf = NULL;
    gui_free(m_recFileNameBuf);
    m_recFileNameBuf = NULL;

    if(m_state == VAPP_CAMCO_STATE_EXIT)
    {
        //mmi_frm_asm_base_shrink_size(m_appID, VAPP_CAMCO_UI_MEM);
    }

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */
}

void VappCamcoPage::initEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_ENV);

    // stop bg ply
    mdi_audio_terminate_background_play();
    mdi_audio_suspend_background_play();

    /* stop MMI sleep */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    /* force all playing keypad tone off */
    srv_prof_stop_tone(SRV_PROF_TONE_KEYPAD);

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* stop LED patten */
    srv_pattern_send_req_to_hw(srv_led_pattern_get_bg_pattern(), 0);

    /* disable touch feedback */
    vfx_adp_touch_fb_disable_tone();
    vfx_adp_touch_fb_disable_vibrate();
}

void VappCamcoPage::deinitEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_DEINIT_ENV);

    // resume bg ply
    mdi_audio_resume_background_play();

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* resume LED patten */
    srv_pattern_play_req(srv_led_pattern_get_bg_pattern(), 1);

    /* let MMI can sleep */
    srv_backlight_turn_off();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* enable touch feedback */
    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();
}

VfxU64 VappCamcoPage::getFreeStorageSize(void)
{
    VfxU8 drive_str[32];
    int ret;
    FS_DiskInfo diskinfo;
    VfxU64 disk_size = 0;

    kal_wsprintf((U16*) drive_str, "%c:\\", m_Setting->getStorage());

    ret = FS_GetDevStatus(m_Setting->getStorage(), FS_FEATURE_STATE_ENUM);
    if (ret >= FS_NO_ERROR)
    {
        ret = FS_GetDiskInfo((U16*) drive_str, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (ret >= FS_NO_ERROR)
        {
            disk_size = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
        }
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GET_FREE_STORAGE_SIZE, disk_size);

    return disk_size;
}

void VappCamcoPage::findLastFileName(VfxBool isCameraApp)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GET_LAST_FILE, isCameraApp);

    // find the last file
    VfxS32 ret;
    VfxWChar folder[50];
    FMGR_FILTER filter;

    FMGR_FILTER_INIT(&filter);

    if(isCameraApp)
    {
        FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    }
    else
    {
        FMGR_FILTER_SET(&filter, FMGR_TYPE_AVI);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
    }

    kal_wsprintf(folder, "%c:\\%w", m_Setting->getStorage(), SHOOTING_DOWNLOAD_FOLDER_NAME);

    memset(g_vapp_camco_last_file_name, 0, sizeof(WCHAR)*256);
    m_lastFileTime = 0;
    m_lastFileindex = 0;

    if(SRV_FMGR_FOLDER_FILELIST_MEM_SIZE > 10*1024)
    {
        ret = srv_fmgr_folder_filelist_create(
            (WCHAR*)folder,
            &filter,
            FS_SORT_TIME,
            m_appMemQuickViewBuffer,
            SRV_FMGR_FOLDER_FILELIST_MEM_SIZE,
            &m_fileListHandle);
    }
    else
    {
        ret = srv_fmgr_folder_filelist_create(
            (WCHAR*)folder,
            &filter,
            FS_SORT_TIME,
            m_appMemQuickViewBuffer,
            10 * 1024,
            &m_fileListHandle);
    }

    if(ret < FS_NO_ERROR)
        return;

    srv_fmgr_filelist_refresh(m_fileListHandle, NULL, 0, SRV_FMGR_FILELIST_REFRESH_PROGRESS_ON, fileMgrEventHdlr, (void*)this);

    m_isGetFileList = VFX_TRUE;
}

VfxBool VappCamcoPage::checkRemovableStorage(void)
{
    if(srv_fmgr_drv_is_removable(m_Setting->getStorage())
        && !srv_fmgr_drv_is_accessible(m_Setting->getStorage()))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_REMOVABLE_STORAGE, 0);
        return VFX_FALSE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_REMOVABLE_STORAGE, 1);
        return VFX_TRUE;
    }
}

VfxBool VappCamcoPage::checkSavePath(void)
{
    VappCamcoPage::m_errStr = 0;
    m_osd_cam_preview_state_param.indicatorStringID = 0;
    m_osd_rec_preview_state_param.indicatorStringID = 0;

#if !defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
    if (FS_NO_ERROR != FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, -1);
        return VFX_FALSE;
    }
#endif

    // check drive
    if(!srv_fmgr_drv_is_accessible(m_Setting->getStorage()))
    {
        if(!srv_fmgr_drv_is_removable(m_Setting->getStorage()))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, -2);
            return VFX_FALSE;
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, 1);

            // card is removed case will be handled by "switch to phone" on the later of preview state
            // special case for memory card rule
            return VFX_TRUE;
        }
    }

    // check path
    VfxS32 fs_ret = 0;
    FS_HANDLE file_handle;
    WCHAR* filePath;

    m_Setting->getStoragePath(&filePath);
    file_handle = FS_Open((kal_uint16*) filePath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, 2);
        return VFX_TRUE;
    }

    /* create directory if it is not there */
    fs_ret = FS_CreateDir((PU16) filePath);

    if (fs_ret < 0)
    {
        if(fs_ret == FS_DISK_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, -3);
            if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                m_osd_cam_preview_state_param.indicatorStringID = FMGR_FS_DISK_FULL_TEXT;
            else
                m_osd_rec_preview_state_param.indicatorStringID = FMGR_FS_DISK_FULL_TEXT;
            VappCamcoPage::m_errStr = FMGR_FS_DISK_FULL_TEXT;
            return VFX_TRUE;
        }
        else if(fs_ret == FS_ROOT_DIR_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, -4);
            if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                m_osd_cam_preview_state_param.indicatorStringID = FMGR_FS_ROOT_DIR_FULL_TEXT;
            else
                m_osd_rec_preview_state_param.indicatorStringID = FMGR_FS_ROOT_DIR_FULL_TEXT;
            VappCamcoPage::m_errStr = FMGR_FS_ROOT_DIR_FULL_TEXT;
            return VFX_TRUE;
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, -5);
        return VFX_FALSE;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CHECK_SAVE_PATH, 3);
    return VFX_TRUE;
}

void VappCamcoPage::initApp(void)
{
    VfxBool appInitFlag = m_isAppInited;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_SETTING, m_isAppInited);

    if(!m_isAppInited)
    {
        VFX_OBJ_CREATE(m_Setting,CamcoSettingMgr,this);
        VFX_OBJ_CREATE(m_OSD,CamcoOSDMgr,this);

        m_cam_preview_start_param.Setting = m_Setting;
        m_cam_preview_start_param.obj = this;
        m_cam_preview_start_param.flag = &m_hwFlag;
        m_cam_preview_start_param.previewFrame = m_previewFrame;
    #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
        m_cam_preview_start_param.sd_data = &m_cam_smiledetect_param;
    #endif

        m_cam_preview_stop_param.Setting = m_Setting;
        m_cam_preview_stop_param.obj = this;
        m_cam_preview_stop_param.flag = &m_hwFlag;

        m_rec_preview_start_param.Setting = m_Setting;
        m_rec_preview_start_param.obj = this;
        m_rec_preview_start_param.flag = &m_hwFlag;
        m_rec_preview_start_param.previewFrame = m_previewFrame;

        m_rec_preview_stop_param.Setting = m_Setting;
        m_rec_preview_stop_param.obj = this;
        m_rec_preview_stop_param.flag = &m_hwFlag;

        m_cam_power_on_param.Setting = m_Setting;
        m_cam_power_on_param.obj = this;
        m_cam_power_on_param.flag = &m_hwFlag;

        m_cam_power_off_param.Setting = m_Setting;
        m_cam_power_off_param.obj = this;
        m_cam_power_off_param.flag = &m_hwFlag;

        m_rec_power_on_param.Setting = m_Setting;
        m_rec_power_on_param.obj = this;
        m_rec_power_on_param.flag = &m_hwFlag;

        m_rec_power_off_param.Setting = m_Setting;
        m_rec_power_off_param.obj = this;
        m_rec_power_off_param.flag = &m_hwFlag;

        m_cam_capture_param.Setting = m_Setting;
        m_cam_capture_param.obj = this;
        m_cam_capture_param.flag = &m_hwFlag;
        m_cam_capture_param.previewFrame = m_previewFrame;

        m_cam_capture_save_param.Setting = m_Setting;
        m_cam_capture_save_param.obj = this;
        m_cam_capture_save_param.flag = &m_hwFlag;

        m_rec_record_param.Setting = m_Setting;
        m_rec_record_param.obj = this;
        m_rec_record_param.flag = &m_hwFlag;
        m_rec_record_param.previewFrame = m_previewFrame;

        m_rec_record_save_param.Setting = m_Setting;
        m_rec_record_save_param.obj = this;
        m_rec_record_save_param.flag = &m_hwFlag;

        m_rec_fetch_param.Setting = m_Setting;
        m_rec_fetch_param.obj = this;
        m_rec_fetch_param.flag = &m_hwFlag;
        m_rec_fetch_param.previewFrame = m_previewFrame;

    #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
        m_cam_smiledetect_param.obj = this;
        m_cam_smiledetect_param.flag = &m_hwFlag;
    #endif

    #ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
        m_cam_scene_param.obj = this;
        m_cam_scene_param.flag = &m_hwFlag;
        m_cam_scene_param.currentScene = 0;
    #endif

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        m_autofocus_param.obj = this;
        m_autofocus_param.flag = &m_hwFlag;
    #endif

        m_general_param.obj = this;
        m_general_param.flag = &m_hwFlag;

        m_cam_est_size_param.Setting = m_Setting;
        m_cam_est_size_param.size = 999;

        m_rec_est_size_param.Setting = m_Setting;
        m_rec_est_size_param.size = 1;
        m_rec_est_size_param.reserve_size = 0;

        m_cam_bg_process_param.obj = this;
        m_cam_bg_process_param.flag = &m_hwFlag;

        /* init OSD state param */
        m_osd_hide_state_param.isCleanBG = VFX_TRUE;

        m_osd_hint_state_param.setting = m_Setting;
        m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_PROCESSING);
        m_osd_hint_state_param.hintIcon = MAIN_MENU_CAMCO_ICON;
        m_osd_hint_state_param.isPreviewON = VFX_FALSE;
        m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;

        m_osd_cam_preview_state_param.setting = m_Setting;
        m_osd_cam_preview_state_param.capturableNumber = 9999;
        m_osd_cam_preview_state_param.settingLevel = VAPP_CAMCO_OSD_SETTING_FULL;

        m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_cam_quick_view_state_param.savedImg.bgColor = VRT_COLOR_BLACK;

        m_osd_rec_preview_state_param.setting = m_Setting;
        m_osd_rec_preview_state_param.recordableTime = 9999;
        m_osd_rec_preview_state_param.settingLevel = VAPP_CAMCO_OSD_SETTING_FULL;

        m_osd_recording_state_param.setting = m_Setting;
        m_osd_pause_state_param.setting = m_Setting;

        m_osd_rec_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_rec_quick_view_state_param.savedImg.bgColor = VRT_COLOR_BLACK;

        m_OSD->setAutoExitTimer(m_autoExitTimer);

        if(m_param.mode == VCUI_CAMCO_FULL)
        {
            m_Setting->setCallingMode(VFX_FALSE, m_param);
            m_isExtCalling = VFX_FALSE;
        }
        else if(m_param.mode == VCUI_CAMCO_CAMERA || m_param.mode == VCUI_CAMCO_RECORDER)
        {
            m_Setting->setCallingMode(VFX_TRUE, m_param);
            m_isExtCalling = VFX_TRUE;
        }
        m_osd_cam_preview_state_param.settingLevel = (vapp_camco_osd_level_enum)m_param.level;
        m_osd_rec_preview_state_param.settingLevel = (vapp_camco_osd_level_enum)m_param.level;

        m_isAppInited = VFX_TRUE;
    }

    // OSD will only check the Horz param pass from App, not setting
    // so we need to update rotate after enter
#if defined(__VAPP_CAMCO_ROTATABLE_UI__)
    // get the current rot of target
    // it may be vertical before enter camcorder
    vapp_camco_osd_screen_param_struct rotParam;
    rotParam.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_ROT;

    switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
    {
        case MMI_FRM_SCREEN_ROTATE_0:
            rotParam.isHorz = VFX_FALSE;
            rotParam.isMirror = VFX_FALSE;
            break;
        case MMI_FRM_SCREEN_ROTATE_90:
            rotParam.isHorz = VFX_TRUE;
            rotParam.isMirror = VFX_TRUE;
            break;
        case MMI_FRM_SCREEN_ROTATE_180:
            rotParam.isHorz = VFX_FALSE;
            rotParam.isMirror = VFX_TRUE;
            break;
        case MMI_FRM_SCREEN_ROTATE_270:
            rotParam.isHorz = VFX_TRUE;
            rotParam.isMirror = VFX_FALSE;
            break;
    }
    m_isOSDHorz = rotParam.isHorz;
    m_isOSDMirror = rotParam.isMirror;
    m_OSD->setScreenParam(rotParam);
#else
    // force update rotate
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
#endif

    if(getState() == VAPP_CAMCO_STATE_EXIT)
    {
        // the timing need to init setting here
        // back from history and reset state (ex: enter Gallery) because it wont create setting
        // or ext calling because the calling data is set after create setting
        if(appInitFlag || m_isExtCalling)
        {
            initSetting();
        }
        // it mean the first time enter App
        // do somethin that create setting wont do
        else
        {
            if(m_Setting->m_callingParam.mode == VCUI_CAMCO_CAMERA)
            {
                m_Setting->setCurrApp(VAPP_CAMCO_APP_CAMERA);
            }
            else if(m_Setting->m_callingParam.mode == VCUI_CAMCO_RECORDER)
            {
                m_Setting->setCurrApp(VAPP_CAMCO_APP_RECORDER);
            }
            if(g_vapp_camco_config.isSetDefaultStorage)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_SETTING_STORAGE);

                m_Setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));
                m_Setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));
                g_vapp_camco_config.isSetDefaultStorage = VFX_FALSE;
            }
        }
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_SETTING_END);
}

void VappCamcoPage::initSetting()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_SETTING, m_Setting->m_callingParam.mode);

    if(m_Setting->m_callingParam.mode == VCUI_CAMCO_CAMERA)
    {
        m_Setting->setCurrApp(VAPP_CAMCO_APP_CAMERA);
    }
    else if(m_Setting->m_callingParam.mode == VCUI_CAMCO_RECORDER)
    {
        m_Setting->setCurrApp(VAPP_CAMCO_APP_RECORDER);
    }
    m_Setting->initAllSetting();
    m_Setting->loadSetting();
    m_Setting->setDefaultAllSetting();
    m_Setting->setValueAllSetting();
    m_Setting->customConfig();

#if !defined(__VAPP_CAMCO_ROTATABLE_UI__)
    // update screnn rotate with current setting
    // it may change rotation after default setting
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
#endif

    if(g_vapp_camco_config.isSetDefaultStorage)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_SETTING_STORAGE);

        m_Setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));
        m_Setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));
        g_vapp_camco_config.isSetDefaultStorage = VFX_FALSE;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_SETTING_END);
}

void VappCamcoPage::initPreviewWindow(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INIT_PREVIEW_WINDOW, 0, 0, 0, 0);

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        VfxU16 capsize = m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE);
        VfxU16 temp_width = 0;
        VfxU16 temp_height = 0;
        VfxU16 temp_factor = 0;
        VfxU16 lcd_width = 0;
        VfxU16 lcd_height = 0;

        if(m_isMainLcdPreview)
        {
        #ifdef HORIZONTAL_CAMERA
            if (m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                if (capsize == VAPP_CAMCO_CAPSIZE_WALLPAPER)
                {
                    lcd_width = GDI_LCD_WIDTH;
                    lcd_height = GDI_LCD_HEIGHT;
                    m_isVideoLayerHorz = VFX_FALSE;
                }
                else
                {
                    lcd_width = GDI_LCD_HEIGHT;
                    lcd_height = GDI_LCD_WIDTH;
                    m_isVideoLayerHorz = VFX_TRUE;
                }
            }
            else
        #endif
            {
                lcd_width = GDI_LCD_WIDTH;
                lcd_height = GDI_LCD_HEIGHT;
                m_isVideoLayerHorz = VFX_FALSE;
            }
        }
        else
        {
            ASSERT(0);
        }

        if (capsize == VAPP_CAMCO_CAPSIZE_WALLPAPER)
        {
            temp_width = GDI_LCD_WIDTH;
            temp_height = GDI_LCD_HEIGHT;
        }
        else
        {
        #if defined(__JPEG_SENSOR_SUPPORT__)
            #define W  (8)
            #define H  (6)
        #else
        #if( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
            #define W  (10)
            #define H  (6)
        #elif( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
            #define W  (6)
            #define H  (4)
        #elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
            #define W  (10)
            #define H  (6)
        #elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
            #define W  (8)
            #define H  (6)
        #else
            #define W  (8)
            #define H  (6)
        #endif
        #endif
            temp_factor = (lcd_height / H);
            temp_width = temp_factor * W;
            while (temp_width > lcd_width)
            {
                temp_factor--;
                temp_width = temp_factor * W;
            }
            temp_height = temp_factor * H;
        }

        m_previewWindow.size = VfxSize(temp_width, temp_height);
        m_previewWindow.origin = VfxPoint(lcd_width>>1, lcd_height>>1);

    }
    else if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
    {
        VfxU16 temp_width = 0;
        VfxU16 temp_height = 0;
        VfxU16 lcd_width = 0;
        VfxU16 lcd_height = 0;
        VfxU16 vdosize = m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE);
        VfxU16 height_base = 0;
        VfxU16 width_base = 0;
        VfxFloat f_temp_factor = 0;

        if(m_isMainLcdPreview)
        {
        #ifdef HORIZONTAL_CAMERA
            if (m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                lcd_width = GDI_LCD_HEIGHT;
                lcd_height = GDI_LCD_WIDTH;
                m_isVideoLayerHorz = VFX_TRUE;
            }
            else
        #endif
            {
                lcd_width = GDI_LCD_WIDTH;
                lcd_height = GDI_LCD_HEIGHT;
                m_isVideoLayerHorz = VFX_FALSE;
            }
        }
        else
        {
            ASSERT(0);
        }

        switch (vdosize)
        {
            case VAPP_CAMCO_RECSIZE_SQCIF:
                width_base = 16;
                height_base = 12;
                break;

            case VAPP_CAMCO_RECSIZE_QQVGA:
                width_base = 16;
                height_base = 12;
                break;

            case VAPP_CAMCO_RECSIZE_QCIF:
                width_base = 44;
                height_base = 36;
                break;

            case VAPP_CAMCO_RECSIZE_QVGA:
                width_base = 16;
                height_base = 12;
                break;

            case VAPP_CAMCO_RECSIZE_CIF:
                width_base = 44;
                height_base = 36;
                break;

            case VAPP_CAMCO_RECSIZE_WQVGA:
                width_base = 10;
                height_base = 6;
                break;

            case VAPP_CAMCO_RECSIZE_CIF2:
                width_base = 54;
                height_base = 30;
                break;

            case VAPP_CAMCO_RECSIZE_HVGA:
                width_base = 12;
                height_base = 8;
                break;

            case VAPP_CAMCO_RECSIZE_NHD:
                width_base = 16;
                height_base = 9;
                break;

            case VAPP_CAMCO_RECSIZE_VGA:
                width_base = 16;
                height_base = 12;
                break;

            case VAPP_CAMCO_RECSIZE_4CIF:
                width_base = 44;
                height_base = 36;
                break;

            case VAPP_CAMCO_RECSIZE_D1:
                width_base = 9;
                height_base = 6;
                break;

            case VAPP_CAMCO_RECSIZE_D12:
                width_base = 30;
                height_base = 24;
                break;

            case VAPP_CAMCO_RECSIZE_WVGA:
                width_base = 10;
                height_base = 6;
                break;

            case VAPP_CAMCO_RECSIZE_SVGA:
                width_base = 50;
                height_base = 38;
                break;

            case VAPP_CAMCO_RECSIZE_WVGA2:
                width_base = 53;
                height_base = 30;
                break;

            case VAPP_CAMCO_RECSIZE_FWVGA:
                width_base = 54;
                height_base = 30;
                break;

            case VAPP_CAMCO_RECSIZE_XGA:
                width_base = 32;
                height_base = 24;
                break;

            case VAPP_CAMCO_RECSIZE_720P:
                width_base = 16;
                height_base = 9;
                break;

            case VAPP_CAMCO_RECSIZE_4VGA:
                width_base = 32;
                height_base = 24;
                break;

            case VAPP_CAMCO_RECSIZE_SXGA:
                width_base = 40;
                height_base = 32;
                break;

            case VAPP_CAMCO_RECSIZE_16CIF:
                width_base = 44;
                height_base = 36;
                break;

            case VAPP_CAMCO_RECSIZE_4SVGA:
                width_base = 16;
                height_base = 12;
                break;

            case VAPP_CAMCO_RECSIZE_FHD:
                width_base = 60;
                height_base = 34;
                break;

            default:
                break;
        }

        /* w is key size */
        if ((width_base * lcd_height) > height_base * lcd_width)
        {
            f_temp_factor = (1.0 * lcd_width / width_base);
            temp_height = (U16) (f_temp_factor * height_base);
            if (temp_height > lcd_height)
                temp_height = lcd_height;
            if ((temp_height % 2) != 0)
                temp_height--;
            temp_width = lcd_width;
        }
        /* h is key size */
        else
        {
            f_temp_factor = (1.0 * lcd_height / height_base);
            temp_width = (U16) (f_temp_factor * width_base);
            if (temp_width > lcd_width)
                temp_width = lcd_width;
            if ((temp_width % 2) != 0)
                temp_width--;
            temp_height = lcd_height;
        }

        m_previewWindow.size = VfxSize(temp_width, temp_height);
        m_previewWindow.origin = VfxPoint(lcd_width>>1, lcd_height>>1);
    }
    else
    {
        ASSERT(0);
    }
    m_previewFrame->m_signalPlayReady.connect(this, &VappCamcoPage::onPreviewFramePrepareDone);

    MMI_TRACE(TRACE_GROUP_2,
        TRC_VAPP_CAMCO_INIT_PREVIEW_WINDOW,
        m_previewWindow.size.width,
        m_previewWindow.size.height,
        m_previewWindow.origin.x,
        m_previewWindow.origin.y);

    m_previewFrame->unPrepare();

    m_previewFrame->setPos(m_previewWindow.origin);
    m_previewFrame->setSize(m_previewWindow.size);

    m_previewFrame->prepare();

    updateVideoFramRotate(VFX_FALSE, VFX_SCR_ROTATE_TYPE_NORMAL, VFX_SCR_ROTATE_TYPE_NORMAL);

    gdi_handle handleT = m_previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    m_prepareFrameSize = (m_previewFrame->getSize().width * m_previewFrame->getSize().height * gdi_layer_get_bit_per_pixel()) >> 3;
    gdi_layer_get_buffer_ptr((U8**)&m_prepareFramePtr);
    gdi_layer_pop_and_restore_active();
}

void VappCamcoPage::onPreviewFramePrepareDone(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_PREVIEW_FRAME_PREPARE_DONE, m_isStartingPreview);

    if(!m_isStartingPreview)
    {
        return;
    }
    else
    {
        m_isStartingPreview = VFX_FALSE;
    }

    // for recorder preview case, need to wait for getlist done and draw the thumbnail
    // or it will be failed to do it when preview is ON
    //
    // for camera/recorder cases, it need to waiting for fmgr done or it will cause get list again and error in fmgr
    if(m_isGetFileList)
    {
        m_delayPreviewTimer->setStartDelay(100);
        m_delayPreviewTimer->start();
        m_isDelayPreview = VFX_TRUE;
    }
    else
    {
        onPreviewFrameDoneDelayTick(NULL);
    }
}

void VappCamcoPage::onPreviewFrameDoneDelayTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ON_PREVIEW_FRAME_PREPARE_DONE_TICK);

    // for recorder preview case, need to wait for getlist done and draw the thumbnail
    // or it will be failedto do it when preview is ON
    //
    // for camera/recorder cases, it need to waiting for fmgr done or it will cause get list again and error in fmgr
    if(m_isGetFileList)
    {
        m_delayPreviewTimer->setStartDelay(50);
        m_delayPreviewTimer->start();
        m_isDelayPreview = VFX_TRUE;
        return;
    }

    m_isDelayPreview = VFX_FALSE;

    vapp_camco_osd_screen_param_struct param;
    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
    param.isBusy = VFX_FALSE;
    m_OSD->setScreenParam(param);

    vapp_camco_restart_param_struct t;
    t.dummy = 0;
    m_restartPreviewCallback.invoke(t);
}

void VappCamcoPage::camRestartPreview(vapp_camco_restart_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CAM_RESTART_PREVIEW);

    m_cam_preview_start_param.isResetZoom = m_Setting->isNeedRestartPreview();
    VAPP_CAMCO_START_LOGGING("PRE");
    if(MDI_RES_CAMERA_SUCCEED == vapp_camco_cam_preview_start(&m_cam_preview_start_param))
    {
        VAPP_CAMCO_STOP_LOGGING("PRE");
        setState(VAPP_CAMCO_STATE_CAM_PREVIEW);
        m_Setting->resetRestartPreview();

        // get remain capture number
        vapp_camco_cam_get_estimated_picture_size(&m_cam_est_size_param);
        vapp_camco_osd_screen_param_struct renainSizeparam;

        // update error msg if remaincapture number is not enough
        renainSizeparam.type = VAPP_CAMCO_OSD_SCR_PARAM_CAM_REMAIN_SIZE_UPDATE;
        renainSizeparam.remain_size = (getFreeStorageSize() / m_cam_est_size_param.size);
        renainSizeparam.indicator_string = m_osd_cam_preview_state_param.indicatorStringID;
        m_OSD->setScreenParam(renainSizeparam);

        vapp_camco_osd_screen_param_struct zoomUpdateParam;
        zoomUpdateParam.type = VAPP_CAMCO_OSD_SCR_PARAM_ZOOM_UPDATE;
        zoomUpdateParam.zoom_value = m_Setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM);
        m_OSD->setScreenParam(zoomUpdateParam);

    #ifdef __FACE_DETECTION_SUPPORT__
        m_smileDetectCycTimer->start();
    #endif
    #ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
        if(m_Setting->getValue(VAPP_CAMCO_SETTING_ASD) == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            m_sceneDetectCycTimer->start();
        }
        else
        {
            m_sceneDetectCycTimer->stop();
        }
    #endif

        // check memory card status (for memory card rule)
        if(!checkRemovableStorage())
        {
        #if defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_IND_MSG_UPDATE;
            param.indicator_string = STR_GLOBAL_INSERT_MEMORY_CARD;
            VappCamcoPage::m_errStr = STR_GLOBAL_INSERT_MEMORY_CARD;
            m_OSD->setScreenParam(param);
        #else
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_CAM_NO_CARD;
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
        #endif
        }
    }
    else
    {
        VAPP_CAMCO_STOP_LOGGING("PRE");
        enterState(VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED);
    }
}

void VappCamcoPage::recRestartPreview(vapp_camco_restart_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_REC_RESTART_PREVIEW);

    VAPP_CAMCO_START_LOGGING("PRE");
    if(MDI_RES_CAMERA_SUCCEED == vapp_camco_rec_preview_start(&m_rec_preview_start_param))
    {

        VAPP_CAMCO_STOP_LOGGING("PRE");

        setState(VAPP_CAMCO_STATE_REC_PREVIEW);
        m_Setting->resetRestartPreview();

        // get remain record time
        vapp_camco_rec_get_estimated_video_size(&m_rec_est_size_param);
        VfxU64 freeSpace = getFreeStorageSize();

        if(freeSpace > m_rec_est_size_param.reserve_size)
        {
            freeSpace -= m_rec_est_size_param.reserve_size;
        }
        else
        {
            freeSpace = 0;
        }

        // update error msg if remain record time is not enough
        vapp_camco_osd_screen_param_struct renainSizeparam;
        renainSizeparam.type = VAPP_CAMCO_OSD_SCR_PARAM_REC_REMAIN_SIZE_UPDATE;
        renainSizeparam.remain_size = (freeSpace / m_rec_est_size_param.size);
        m_OSD->setScreenParam(renainSizeparam);

        // check memory card status (for memory card rule)
        if(!checkRemovableStorage())
        {
        #if defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_IND_MSG_UPDATE;
            param.indicator_string = STR_GLOBAL_INSERT_MEMORY_CARD;
            VappCamcoPage::m_errStr = STR_GLOBAL_INSERT_MEMORY_CARD;
            m_OSD->setScreenParam(param);
        #else
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_REC_NO_CARD;
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
        #endif
        }
    }
    else
    {
        VAPP_CAMCO_STOP_LOGGING("PRE");
        enterState(VAPP_CAMCO_STATE_REC_PREVIEW_FAILED);

    }

    if(m_state == VAPP_CAMCO_STATE_REC_PREVIEW)
    {
        m_hwFlag.isRecSaveSuccess  = VFX_FALSE;
        m_hwFlag.isRecordFailed = VFX_FALSE;
    }
}

void VappCamcoPage::camPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CAM_PREVIEW_HDLR, m_state, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_PREVIEW && m_state != VAPP_CAMCO_STATE_CAM_FOCUSING && m_state != VAPP_CAMCO_STATE_CAM_FOCUSED)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_ENTER_GALLERY:
        {
            VfxWString fimeName = VFX_WSTR_MEM(g_vapp_camco_last_file_name);
            VfxBool isFolder = VFX_FALSE;
            if(fimeName.isEmpty() || fimeName.isNull())
            {
                WCHAR* filePath;
                m_Setting->getStoragePath(&filePath);
                fimeName = VFX_WSTR_MEM(filePath);
                isFolder = VFX_TRUE;
            }

            setState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            enterState(VAPP_CAMCO_STATE_EXIT);

            vapp_gallery_image_viewer_launch_option_struct option;
            vapp_gallery_image_viewer_launch_option_init(&option);

            if(isFolder)
            {
                vapp_gallery_image_viewer_folder_launch(fimeName.getBuf(), &option);
            }
            else
            {
                vapp_gallery_image_viewer_launch(fimeName.getBuf(), &option);
            }
            break;
        }
        case VAPP_CAMCO_EVT_CAPTURE:
        {
        #if !defined(__MTK_TARGET__)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_CAMCO_NOTIFY_HW_NOT_READY));
            return;
        #endif

            if(m_isAFTonePlaying)
                mdi_audio_stop_string();

            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }

        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

            m_countdownDuration = m_Setting->getValue(VAPP_CAMCO_SETTING_SELFTIMER) * 5 * 1000;

        #ifdef __FACE_DETECTION_SUPPORT__
            m_smileDetectCycTimer->stop();
        #endif
        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            m_smileDetectSuccessTimer->stop();
        #endif
        #ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
            m_sceneDetectCycTimer->stop();
        #endif

            if (m_countdownDuration == 0)
            {
                Capture();
            }
            else
            {
                enterState(VAPP_CAMCO_STATE_CAM_COUNTDOWN);
            }
            break;
        }
        case VAPP_CAMCO_EVT_SWITCH_SENSOR:
        {
            exitState();
            vapp_camco_cam_power_off(&m_cam_power_off_param);

            initSetting();

        #if !defined(__VAPP_CAMCO_ROTATABLE_UI__)
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);

            }
            else
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
            }
        #else
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
            {
                case MMI_FRM_SCREEN_ROTATE_0:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_90:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_180:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_270:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
                    break;
            }
        #endif

            m_Setting->needRestartPreview();
            vapp_camco_cam_power_on(&m_cam_power_on_param);

            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);

            break;
        }
        case VAPP_CAMCO_EVT_SWITCH_APP:
        {
            exitState();
            vapp_camco_cam_power_off(&m_cam_power_off_param);
            vapp_camco_rec_power_on(&m_rec_power_on_param);

            initSetting();

        #if !defined(__VAPP_CAMCO_ROTATABLE_UI__)
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER)
            {
                // because camera use Vertical Ui on WP size with rear camera, but recorder use horizontal under rear camera
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
            }
        #else
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
            {
                case MMI_FRM_SCREEN_ROTATE_0:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_90:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_180:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_270:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
                    break;
            }
        #endif

            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;
        }
    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        case VAPP_CAMCO_EVT_FOCUS:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }

            enterState(VAPP_CAMCO_STATE_CAM_FOCUSING);
            break;
        }
    #endif
        case VAPP_CAMCO_EVT_RESTART_PREVIEW:
        {
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
            {
                case MMI_FRM_SCREEN_ROTATE_0:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_90:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_180:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_270:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
                    break;
            }
            if(m_Setting->isNeedRestartPreview())
            {
                enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            }
            break;
        }
        case VAPP_CAMCO_EVT_BG_CAL_START:
        {
            vapp_camco_background_calculation_start(&m_cam_bg_process_param);
            break;
        }
        case VAPP_CAMCO_EVT_BG_CAL_STOP:
        {
            vapp_camco_background_calculation_stop(&m_cam_bg_process_param);
            break;
        }
        case VAPP_CAMCO_EVT_SD_START:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }
            (*(VfxBool*)param) = VFX_TRUE;

        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_SD) == VAPP_CAMCO_SMILE_DETECT_ON)
                vapp_camco_cam_sd_start(&m_cam_smiledetect_param);
        #endif

            m_isOSDinSmileDetectMode = VFX_TRUE;
            break;
        }
        case VAPP_CAMCO_EVT_SD_STOP:
        {
        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);
        #endif
            m_isOSDinSmileDetectMode = VFX_FALSE;
            break;
        }
        case VAPP_CAMCO_EVT_OK:
        {
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }
        case VAPP_CAMCO_EVT_CANCEL:
        {
            exit();
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::camPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CAM_PREVIEW_FAILED_HDLR, m_state, evt_type);

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_BACK:
        {
            exit();
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::camSaveDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CAM_SAVE_DONE_HDLR, m_state, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_SAVE_DONE)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_VIEW_STOP:
        {
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::camCountdownHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CAM_COUNT_DOWN_HDLR, m_state, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_COUNTDOWN)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_BACK:
        {
            countdownCycTimer->stop();

            deinitCountDownSound();

        #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
            vapp_camco_cam_autofocus_stop(&m_autofocus_param);
        #endif

            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::recPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_REC_PREVIEW_HDLR, m_state, evt_type);

    if(m_isTonePlaying)
        return;

    if(m_state != VAPP_CAMCO_STATE_REC_PREVIEW && m_state != VAPP_CAMCO_STATE_REC_FOCUSING && m_state != VAPP_CAMCO_STATE_REC_FOCUSED)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_ENTER_GALLERY:
        {
            VfxWString fimeName = VFX_WSTR_MEM(g_vapp_camco_last_file_name);
            VfxBool isFolder = VFX_FALSE;
            if(fimeName.isEmpty() || fimeName.isNull())
            {
                WCHAR* filePath;
                m_Setting->getStoragePath(&filePath);
                fimeName = VFX_WSTR_MEM(filePath);
                isFolder = VFX_TRUE;
            }

            setState(VAPP_CAMCO_STATE_REC_PREVIEW);
            enterState(VAPP_CAMCO_STATE_EXIT);

            vapp_gallery_image_viewer_launch_option_struct option;
            vapp_gallery_image_viewer_launch_option_init(&option);
            option.content_is_image = MMI_FALSE;

            if(isFolder)
            {
                vapp_gallery_image_viewer_folder_launch(fimeName.getBuf(), &option);
            }
            else
            {
                vapp_gallery_image_viewer_launch(fimeName.getBuf(), &option);
            }

            break;
        }
        case VAPP_CAMCO_EVT_RECORD:
        {
        #if !defined(__MTK_TARGET__)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_CAMCO_NOTIFY_HW_NOT_READY));
            return;
        #endif

            // if there are some error when preview, show error again directly, no start record
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }

            playSoundandRecord();
            break;
        }
        case VAPP_CAMCO_EVT_SWITCH_SENSOR:
        {
            exitState();
            vapp_camco_rec_power_off(&m_rec_power_off_param);

            initSetting();

        #if !defined(__VAPP_CAMCO_ROTATABLE_UI__)
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
            }
            else
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
            }
        #else
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
            {
                case MMI_FRM_SCREEN_ROTATE_0:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_90:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_180:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_270:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
                    break;
            }
        #endif

            m_Setting->needRestartPreview();
            vapp_camco_rec_power_on(&m_rec_power_on_param);

            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);

            break;
        }
        case VAPP_CAMCO_EVT_SWITCH_APP:
        {
            exitState();
            vapp_camco_rec_power_off(&m_rec_power_off_param);
            vapp_camco_cam_power_on(&m_cam_power_on_param);

            initSetting();

        #if !defined(__VAPP_CAMCO_ROTATABLE_UI__)
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER)
            {
                // because recorder use horizontal under rear camera, but camera use Vertical Ui on WP size with rear camera
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
            }
        #else
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
            {
                case MMI_FRM_SCREEN_ROTATE_0:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_90:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_180:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_270:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
                    break;
            }
        #endif

            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }
    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        case VAPP_CAMCO_EVT_FOCUS:
        {
            // if there are some error when preview, show error again directly, no start record
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }

            enterState(VAPP_CAMCO_STATE_REC_FOCUSING);
            break;
        }
    #endif
        case VAPP_CAMCO_EVT_RESTART_PREVIEW:
        {
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
            {
                case MMI_FRM_SCREEN_ROTATE_0:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_90:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_180:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180, VFX_TRUE);
                    break;
                case MMI_FRM_SCREEN_ROTATE_270:
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
                    break;
            }
            if(m_Setting->isNeedRestartPreview())
            {
                enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            }
            break;
        }
        case VAPP_CAMCO_EVT_BG_CAL_START:
        {
            vapp_camco_background_calculation_start(&m_cam_bg_process_param);
            break;
        }
        case VAPP_CAMCO_EVT_BG_CAL_STOP:
        {
            vapp_camco_background_calculation_stop(&m_cam_bg_process_param);
            break;
        }
        case VAPP_CAMCO_EVT_OK:
        {
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;
        }
        case VAPP_CAMCO_EVT_CANCEL:
        {
            exit();
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::recPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_REC_PREVIEW_FAILED_HDLR, m_state, evt_type);

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_BACK:
        {
            exit();
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::recRecordingHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_REC_RECORDING_HDLR, m_state, evt_type);

    if(m_state != VAPP_CAMCO_STATE_REC_RECORDING || !m_hwFlag.isOnRecord)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_REC_STOP:
        {
            enterState(VAPP_CAMCO_STATE_REC_SAVING);
            break;
        }
        case VAPP_CAMCO_EVT_REC_STOP_EXIT:
        {
            m_isSaveBeforeLeave = VFX_TRUE;
            enterState(VAPP_CAMCO_STATE_REC_SAVING);
            break;
        }
        case VAPP_CAMCO_EVT_REC_PAUSE:
        {
            enterState(VAPP_CAMCO_STATE_REC_PAUSE);
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::recPauseHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_REC_PAUSE_HDLR, m_state, evt_type);

    if(m_state != VAPP_CAMCO_STATE_REC_PAUSE || !m_hwFlag.isOnRecord)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_REC_STOP:
        {
            enterState(VAPP_CAMCO_STATE_REC_SAVING);
            break;
        }
        case VAPP_CAMCO_EVT_REC_STOP_EXIT:
        {
            m_isSaveBeforeLeave = VFX_TRUE;
            enterState(VAPP_CAMCO_STATE_REC_SAVING);
            break;
        }
        case VAPP_CAMCO_EVT_REC_RESUME:
        {
            enterState(VAPP_CAMCO_STATE_REC_RECORDING);
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::recSaveDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_REC_SAVE_DONE_HDLR, m_state, evt_type);

    if(m_state != VAPP_CAMCO_STATE_REC_SAVE_DONE)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_VIEW_STOP:
        {
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;
        }
        default:
            ASSERT(0);
    }
};

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
void VappCamcoPage::camFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CAM_FOCUS_HDLR, m_state, evt_type);

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_FOCUS_STOP:
        {
            vapp_camco_cam_autofocus_stop(&m_autofocus_param);

        #ifdef __FACE_DETECTION_SUPPORT__
            m_smileDetectCycTimer->start();
        #endif

        #ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_ASD) == VAPP_CAMCO_SCENE_DETECT_ON)
            {
                m_sceneDetectCycTimer->start();
            }
        #endif

            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
            m_OSD->setScreenParam(param);

            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }
        case VAPP_CAMCO_EVT_SD_START:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }
            (*(VfxBool*)param) = VFX_TRUE;

        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_SD) == VAPP_CAMCO_SMILE_DETECT_ON)
                vapp_camco_cam_sd_start(&m_cam_smiledetect_param);
        #endif

            m_isOSDinSmileDetectMode = VFX_TRUE;
            break;
        }
        case VAPP_CAMCO_EVT_SD_STOP:
        {
        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);
        #endif
            m_isOSDinSmileDetectMode = VFX_FALSE;
            break;
        }
        case VAPP_CAMCO_EVT_CAPTURE:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }

            m_countdownDuration = m_Setting->getValue(VAPP_CAMCO_SETTING_SELFTIMER) * 5 * 1000;

        #ifdef __FACE_DETECTION_SUPPORT__
            m_smileDetectCycTimer->stop();
        #endif
        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            m_smileDetectSuccessTimer->stop();
        #endif
        #ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
            m_sceneDetectCycTimer->stop();
        #endif
            if (m_countdownDuration == 0)
            {
                Capture();
            }
            else
            {
                enterState(VAPP_CAMCO_STATE_CAM_COUNTDOWN);
            }
            break;
        }
        default:
            ASSERT(0);
    }
};

void VappCamcoPage::recFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_REC_FOCUS_HDLR, m_state, evt_type);

    if(m_isTonePlaying)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_FOCUS_STOP:
        {
            vapp_camco_rec_autofocus_stop(&m_autofocus_param);

            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
            m_OSD->setScreenParam(param);

            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;
        }
        case VAPP_CAMCO_EVT_RECORD:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(VappCamcoPage::m_errStr));
                break;
            }

            playSoundandRecord();
            break;
        }
        default:
            ASSERT(0);
    }
};
#endif

void VappCamcoPage::errorPopupHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ERROR_POPUP_HDLR, m_state, evt_type);

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_OK:
        {
            if(m_isNotifyRunning)
            {
                m_isNotifyRunning = VFX_FALSE;
                m_currentPopupParam.callback.invoke(m_currentPopupParam.callbackParam);
            }
            break;
        }
        default:
            ASSERT(0);
    }
}

void VappCamcoPage::appGlobalEventHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_APP_GLOBAL_EVENT_HDLR, m_state, evt_type);

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_AUTO_EXIT:
        {
            getApp()->exit();
            break;
        }
        default:
            ASSERT(0);
    }

}

// state enter function
void VappCamcoPage::enterExitState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_EXIT_STATE);

    exitState();

    m_state = VAPP_CAMCO_STATE_EXIT;
};

void VappCamcoPage::enterCamPreviewState(void)
{
#ifdef VAPP_CAMCO_MODIS_PIC_PREVIEW
    WCHAR fileName[30];
    CHAR fileNameAsc[15] = "";

    sprintf(fileNameAsc, "%c:\\1.jpg", SRV_FMGR_CARD_DRV);
    mmi_asc_to_wcs(fileName, fileNameAsc);

    VfxImageSrc s = VfxImageSrc(VFX_WSTR_MEM(fileName));

    m_picturePreviewFrame->setImgContent(s);
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_CAM_PREVIEW_STATE, m_hwFlag.isPreviewStart, m_Setting->isNeedRestartPreview());

    if(!checkSavePath())
    {
        if(VappCamcoPage::m_errStr == 0)
            VappCamcoPage::m_errStr = STR_ID_VAPP_CAMCO_NOTIFY_STORAGE_NOT_READY;

        if(m_hwFlag.isPreviewStart)
        {
        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);
        #endif
            vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
        }

        enterState(VAPP_CAMCO_STATE_ENTER_FAIL);
        return;
    }

    if(!m_hwFlag.isPreviewStart || m_Setting->isNeedRestartPreview())
    {
        if(m_Setting->isNeedRestartPreview())
        {
        #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
            vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);
        #endif
            vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
        }

        initPreviewWindow();

        findLastFileName(VFX_TRUE);

        m_osd_cam_preview_state_param.capturableNumber = (getFreeStorageSize() / m_cam_est_size_param.size);
        m_osd_cam_preview_state_param.isRestartEnter = VFX_TRUE;
        m_osd_cam_preview_state_param.previousFileName = NULL;
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW, &m_osd_cam_preview_state_param, (VappCamcoOSDEvtHdlr*)this);

        if(m_Setting->isNeedRestartPreview())
        {
            m_Setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_Setting->getMinValue(VAPP_CAMCO_SETTING_CAMZOOM));
        }

        m_restartPreviewCallback = m_camRestartPreviewCallback;
        m_isStartingPreview = VFX_TRUE;

        vapp_camco_osd_screen_param_struct param;

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
    #endif

        param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
        param.isBusy = VFX_TRUE;
        m_OSD->setScreenParam(param);

    #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

        return;
    }
    else
    {
        setState(VAPP_CAMCO_STATE_CAM_PREVIEW);

        //findLastFileName(VFX_TRUE);

        m_osd_cam_preview_state_param.capturableNumber = (getFreeStorageSize() / m_cam_est_size_param.size);
        m_osd_cam_preview_state_param.isRestartEnter = VFX_FALSE;
        m_osd_cam_preview_state_param.previousFileName = NULL;
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW, &m_osd_cam_preview_state_param, (VappCamcoOSDEvtHdlr*)this);

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        vapp_camco_osd_screen_param_struct param;
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
    #endif

        if(!checkRemovableStorage())
        {
        #if defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_IND_MSG_UPDATE;
            param.indicator_string = STR_GLOBAL_INSERT_MEMORY_CARD;
            VappCamcoPage::m_errStr = STR_GLOBAL_INSERT_MEMORY_CARD;
            m_OSD->setScreenParam(param);
        #else
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_CAM_NO_CARD;
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
        #endif
        }
    }
};

void VappCamcoPage::enterCamPreviewFailedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_CAM_PREVIEW_FAILED_STATE);

    setState(VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED);

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_PREVIEW_FAILED);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT;

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
};

void VappCamcoPage::enterCamCountdownState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_CAM_COUNTDOWN_STATE);

    setState(VAPP_CAMCO_STATE_CAM_COUNTDOWN);

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_PROCESSING);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_TRANSPARENT;
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_CAM_COUNT_DOWN;
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT;

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);

    initCountDownSound();

    kal_get_time(&m_countdownStartTicks);

    countdownCyclic(NULL);
};

void VappCamcoPage::enterCamCaptureState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_CAM_CAPTURE_STATE, m_state);

    MDI_RESULT ret = MDI_RES_CAMERA_ERR_FAILED;

    if (m_state == VAPP_CAMCO_STATE_CAM_PREVIEW ||
        m_state == VAPP_CAMCO_STATE_CAM_FOCUSING ||
        m_state == VAPP_CAMCO_STATE_CAM_FOCUSED ||
        m_state == VAPP_CAMCO_STATE_CAM_COUNTDOWN)
    {
        memset(m_camFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);

        if(getNextFilename(m_camFileNameBuf))
        {
            m_cam_capture_param.fileName = m_camFileNameBuf;

            VAPP_CAMCO_START_LOGGING("NOR");
            ret = vapp_camco_cam_normal_shot(&m_cam_capture_param);
            VAPP_CAMCO_STOP_LOGGING("NOR");
        }
        else
        {
            ret = VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND;
        }

        if(m_isExtCalling)
        {
            setState(VAPP_CAMCO_STATE_CAM_CAPTURE);

            if (ret == MDI_RES_CAMERA_SUCCEED)
            {
                VAPP_CAMCO_START_LOGGING("SAV");
                ret = vapp_camco_cam_save_capture_image(&m_cam_capture_save_param);
                VAPP_CAMCO_STOP_LOGGING("SAV");
            }

            if (ret == MDI_RES_CAMERA_SUCCEED)
            {
                vcui_camco_event_struct evt;

                MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_CAMCO_EVENT_RESULT_SUCCESS,  m_appID);
                mmi_wcscpy(g_vapp_camco_ext_calling_file_name, m_camFileNameBuf);
                evt.filePath = g_vapp_camco_ext_calling_file_name;
                VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
                app->postToCaller((mmi_group_event_struct*)&evt);

            }
            else
            {
                if(isAppActive())
                {
                    vapp_camco_popup_param_struct param;
                    param.isConfirm = VFX_TRUE;
                    param.isNeedClearScrn = VFX_TRUE;
                    param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                    param.callback = m_exitStateCB;
                    param.result = ret;
                    showPopupScreen(&param);
                }
                else
                {
                    vapp_camco_popup_callback_param_struct param;
                    param.next_state = VAPP_CAMCO_STATE_EXIT;
                    mmi_event_notify_enum popup_type;
                    VappCamcoPage::m_errStr = getMappingShownString(ret, &popup_type);
                    exitCamcoCUI(param);


                }
                if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)
                    restoreFilename();
            }
        }
        else
        {
            if (ret == MDI_RES_CAMERA_SUCCEED)
            {
                setState(VAPP_CAMCO_STATE_CAM_CAPTURE);

                m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_SAVING);
                m_osd_hint_state_param.isPreviewON = VFX_FALSE;
                m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
                m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
                m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
                m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;

                m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);

                enterState(VAPP_CAMCO_STATE_CAM_SAVE_DONE);

            }
            else
            {
                if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)
                    restoreFilename();

                vapp_camco_popup_param_struct param;
                param.isConfirm = VFX_TRUE;
                param.isNeedClearScrn = VFX_TRUE;
                param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                param.callback = m_recoverStateCB;
                param.result = ret;
                showPopupScreen(&param);
            }
        }
    }
};

void VappCamcoPage::enterCamSaveDoneState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_CAM_SAVE_DONE_STATE, m_state);

    vapp_camco_state_enum prev_state = m_state;

    if (prev_state == VAPP_CAMCO_STATE_CAM_CAPTURE)
    {
        MDI_RESULT ret;

        VAPP_CAMCO_START_LOGGING("SAV");
        ret = vapp_camco_cam_save_capture_image(&m_cam_capture_save_param);
        VAPP_CAMCO_STOP_LOGGING("SAV");

        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            setState(VAPP_CAMCO_STATE_CAM_SAVE_DONE);

            VAPP_CAMCO_START_LOGGING("QIK");
            m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_NORMAL_SHOT;
            m_osd_cam_quick_view_state_param.savedImg.bgColor = VRT_COLOR_TRANSPARENT;
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);
            VAPP_CAMCO_STOP_LOGGING("QIK");

        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

        }
        else
        {
            restoreFilename();

            vapp_camco_popup_param_struct param;
            param.isConfirm = VFX_TRUE;
            param.isNeedClearScrn = VFX_TRUE;
            param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
            param.callback = m_recoverStateCB;
            param.result = ret;
            showPopupScreen(&param);
            return;
        }
    }
};

void VappCamcoPage::enterRecPreviewState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_PREVIEW_STATE, m_hwFlag.isPreviewStart, m_Setting->isNeedRestartPreview());

    if(!checkSavePath())
    {
        if(VappCamcoPage::m_errStr == 0)
            VappCamcoPage::m_errStr = STR_ID_VAPP_CAMCO_NOTIFY_STORAGE_NOT_READY;

        if(m_hwFlag.isPreviewStart)
        {
            vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
        }

        enterState(VAPP_CAMCO_STATE_ENTER_FAIL);
        return;
    }

    /*
     * Once use mdi_vid to open file for show the first frame,
     * camera will be powered off.Therefore, need to repower on camera
     * againe before preview
     */
    vapp_camco_rec_power_on(&m_rec_power_on_param);

    if(!m_hwFlag.isPreviewStart || m_Setting->isNeedRestartPreview())
    {
        if(m_Setting->isNeedRestartPreview())
        {
            vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
        }

        initPreviewWindow();

        findLastFileName(VFX_FALSE);

        m_osd_rec_preview_state_param.recordableTime = getFreeStorageSize();
        if(m_osd_rec_preview_state_param.recordableTime > m_rec_est_size_param.reserve_size)
        {
            m_osd_rec_preview_state_param.recordableTime -= m_rec_est_size_param.reserve_size;
        }
        else
        {
            m_osd_rec_preview_state_param.recordableTime = 0;
        }
        m_osd_rec_preview_state_param.recordableTime = m_osd_rec_preview_state_param.recordableTime / m_rec_est_size_param.size;
        m_osd_rec_preview_state_param.isRestartEnter = VFX_TRUE;
        m_osd_rec_preview_state_param.previousFileName = NULL;
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW, &m_osd_rec_preview_state_param, (VappCamcoOSDEvtHdlr*)this);

        m_restartPreviewCallback = m_recRestartPreviewCallback;
        m_isStartingPreview = VFX_TRUE;

        vapp_camco_osd_screen_param_struct param;

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
    #endif

        param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
        param.isBusy = VFX_TRUE;
        m_OSD->setScreenParam(param);
        return;
    }
    else
    {
        setState(VAPP_CAMCO_STATE_REC_PREVIEW);

        //findLastFileName(VFX_FALSE);

        m_osd_rec_preview_state_param.recordableTime= (getFreeStorageSize() / m_rec_est_size_param.size);
        m_osd_rec_preview_state_param.isRestartEnter = VFX_FALSE;
        m_osd_rec_preview_state_param.previousFileName = NULL;
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW, &m_osd_rec_preview_state_param, (VappCamcoOSDEvtHdlr*)this);

    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        vapp_camco_osd_screen_param_struct param;
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
    #endif

        if(!checkRemovableStorage())
        {
        #if defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_IND_MSG_UPDATE;
            param.indicator_string = STR_GLOBAL_INSERT_MEMORY_CARD;
            VappCamcoPage::m_errStr = STR_GLOBAL_INSERT_MEMORY_CARD;
            m_OSD->setScreenParam(param);
        #else
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_REC_NO_CARD;
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
        #endif
        }
    }

    if(m_state == VAPP_CAMCO_STATE_REC_PREVIEW)
    {
        m_hwFlag.isRecSaveSuccess  = VFX_FALSE;
        m_hwFlag.isRecordFailed = VFX_FALSE;
    }
};

void VappCamcoPage::enterRecPreviewFailedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_PREVIEW_FAILED_STATE);

    setState(VAPP_CAMCO_STATE_REC_PREVIEW_FAILED);

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_PREVIEW_FAILED);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT;

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
};

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
void VappCamcoPage::enterCamFocusingState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_CAM_FOCUSING_STATE);

    setState(VAPP_CAMCO_STATE_CAM_FOCUSING);

    vapp_camco_cam_autofocus_start(&m_autofocus_param);
    vapp_camco_cam_get_autofocus_result(&m_autofocus_param);

    VfxU32 af_active_zone = 0;
    VfxS32 af_zone_count = 0;

    af_active_zone = m_autofocus_param.af_zone.af_active_zone;

    for (VfxU32 idx = VAPP_CAMCO_OSD_FOCUS_REGION_1; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
    {
        af_zone_count += af_active_zone & 0x00000001;
        af_active_zone = af_active_zone >> 1;
    }

    af_active_zone = m_autofocus_param.af_zone.af_active_zone;

    MMI_ASSERT(af_zone_count <= VAPP_CAMCO_OSD_FOCUS_REGION_END);

    m_autofocus_param.af_active_zone = m_autofocus_param.af_zone.af_active_zone;
    for (VfxU32 idx = VAPP_CAMCO_OSD_FOCUS_REGION_1; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
    {
        if (af_active_zone & 0x00000001)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING;
            param.focus.w = m_autofocus_param.af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
            param.index = idx;

            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
            VfxPoint p;
            p = transPointToOSDCoord(VfxPoint(param.focus.center_x,  param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
            if(m_isVideoLayerHorz != m_isOSDHorz)
            {
                VfxU32 t = param.focus.w;
                param.focus.w = param.focus.h;
                param.focus.h = t;
            }

            param.focus.center_x = p.x;
            param.focus.center_y = p.y;

            m_OSD->setScreenParam(param);
        }
        af_active_zone = af_active_zone >> 1;
    }
}

void VappCamcoPage::enterCamFocusedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_CAM_FOCUSED_STATE);

    MMI_ASSERT(m_state == VAPP_CAMCO_STATE_CAM_FOCUSING);

    setState(VAPP_CAMCO_STATE_CAM_FOCUSING);

    VfxU32 af_active_zone = m_autofocus_param.af_zone.af_active_zone;
    VfxU32 af_success_zone = m_autofocus_param.af_success_zone;

    for (VfxU32 idx = 0; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
    {
        VfxU32 is_success = af_success_zone & 0x00000001;

        if (is_success)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSED;
            param.focus.w = m_autofocus_param.af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
            param.index = idx;

            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
            VfxPoint p;
            p = transPointToOSDCoord(VfxPoint(param.focus.center_x,  param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
            if(m_isVideoLayerHorz != m_isOSDHorz)
            {
                VfxU32 t = param.focus.w;
                param.focus.w = param.focus.h;
                param.focus.h = t;
            }

            param.focus.center_x = p.x;
            param.focus.center_y = p.y;

            m_OSD->setScreenParam(param);

        }
        else if (af_active_zone & 0x00000001)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING;
            param.focus.w = m_autofocus_param.af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
            param.index = idx;

            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
            VfxPoint p;
            p = transPointToOSDCoord(VfxPoint(param.focus.center_x,  param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
            if(m_isVideoLayerHorz != m_isOSDHorz)
            {
                VfxU32 t = param.focus.w;
                param.focus.w = param.focus.h;
                param.focus.h = t;
            }

            param.focus.center_x = p.x;
            param.focus.center_y = p.y;

            m_OSD->setScreenParam(param);
        }

        af_success_zone = af_success_zone >> 1;
        af_active_zone = af_active_zone >> 1;
    }
};

void VappCamcoPage::enterRecFocusingState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_FOCUSING_STATE);

    setState(VAPP_CAMCO_STATE_REC_FOCUSING);

    vapp_camco_rec_autofocus_start(&m_autofocus_param);
    vapp_camco_rec_get_autofocus_result(&m_autofocus_param);

    VfxU32 af_active_zone = 0;
    VfxS32 af_zone_count = 0;

    af_active_zone = m_autofocus_param.rec_af_zone.af_active_zone;

    for (VfxU32 idx = VAPP_CAMCO_OSD_FOCUS_REGION_1; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
    {
        af_zone_count += af_active_zone & 0x00000001;
        af_active_zone = af_active_zone >> 1;
    }

    af_active_zone = m_autofocus_param.rec_af_zone.af_active_zone;

    MMI_ASSERT(af_zone_count <= VAPP_CAMCO_OSD_FOCUS_REGION_END);

    m_autofocus_param.af_active_zone = m_autofocus_param.rec_af_zone.af_active_zone;
    for (VfxU32 idx = VAPP_CAMCO_OSD_FOCUS_REGION_1; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
    {
        if (af_active_zone & 0x00000001)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING;
            param.focus.w = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
            param.index = idx;

            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
            VfxPoint p;
            p = transPointToOSDCoord(VfxPoint(param.focus.center_x,  param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
            if(m_isVideoLayerHorz != m_isOSDHorz)
            {
                VfxU32 t = param.focus.w;
                param.focus.w = param.focus.h;
                param.focus.h = t;
            }

            param.focus.center_x = p.x;
            param.focus.center_y = p.y;

            m_OSD->setScreenParam(param);
        }
        af_active_zone = af_active_zone >> 1;
    }
};

void VappCamcoPage::enterRecFocusedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_FOCUSED_STATE);

    MMI_ASSERT(m_state == VAPP_CAMCO_STATE_REC_FOCUSING);

    setState(VAPP_CAMCO_STATE_REC_FOCUSING);

    VfxU32 af_active_zone = m_autofocus_param.rec_af_zone.af_active_zone;
    VfxU32 af_success_zone = m_autofocus_param.af_success_zone;

    for (VfxU32 idx = 0; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
    {
        VfxU32 is_success = af_success_zone & 0x00000001;

        if (is_success)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSED;
            param.focus.w = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
            param.index = idx;

            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
            VfxPoint p;
            p = transPointToOSDCoord(VfxPoint(param.focus.center_x,  param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
            if(m_isVideoLayerHorz != m_isOSDHorz)
            {
                VfxU32 t = param.focus.w;
                param.focus.w = param.focus.h;
                param.focus.h = t;
            }

            param.focus.center_x = p.x;
            param.focus.center_y = p.y;

            m_OSD->setScreenParam(param);

        }
        else if (af_active_zone & 0x00000001)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING;
            param.focus.w = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
            param.index = idx;

            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
            VfxPoint p;
            p = transPointToOSDCoord(VfxPoint(param.focus.center_x,  param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
            if(m_isVideoLayerHorz != m_isOSDHorz)
            {
                VfxU32 t = param.focus.w;
                param.focus.w = param.focus.h;
                param.focus.h = t;
            }

            param.focus.center_x = p.x;
            param.focus.center_y = p.y;

            m_OSD->setScreenParam(param);
        }

        af_success_zone = af_success_zone >> 1;
        af_active_zone = af_active_zone >> 1;
    }
};
#endif

void VappCamcoPage::enterRecRecordingState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_RECORDING_STATE, m_state);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;

    if (m_state == VAPP_CAMCO_STATE_REC_PAUSE)
    {
        MDI_RESULT result;

        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING, &m_osd_recording_state_param, (VappCamcoOSDEvtHdlr*)this);
        result = vapp_camco_rec_record_resume(&m_rec_record_param);

        if (MDI_RES_VDOREC_SUCCEED == result)
        {
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_ON)
            {
                if(m_backlightBeforeRecording > 3)
                    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, (m_backlightBeforeRecording - 2 > 0) ? (m_backlightBeforeRecording - 2) : 0);
                else if(m_backlightBeforeRecording == 3)
                    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, 2);
                srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
            }

            setState(VAPP_CAMCO_STATE_REC_RECORDING);

            recordingCyclic(NULL);
        }
        else if (result == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
        {
            vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);
            kal_sleep_task(100);

            vapp_camco_popup_param_struct param;
            param.isConfirm = VFX_FALSE;
            param.isNeedClearScrn = VFX_FALSE;
            param.callbackParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
            param.callback = m_enterStateCB;

            if((vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
            {
                param.result = MDI_RES_VDOREC_REACH_TIME_LIMIT;
            }
            else
            {
                param.result = MDI_RES_VDOREC_REACH_SIZE_LIMIT;
            }
            showPopupScreen(&param);

        }
        else if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            vapp_camco_popup_param_struct param;
            param.isConfirm = VFX_FALSE;
            param.isNeedClearScrn = VFX_FALSE;
            param.callbackParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
            param.callback = m_enterStateCB;
            param.result = result;
            showPopupScreen(&param);
        }
        else
        {
            /* Camcorder is in VAPP_CAMCO_STATE_REC_PAUSE */
            m_hwFlag.isOnRecord = VFX_FALSE;

            vapp_camco_popup_param_struct param;\
            param.isConfirm = VFX_TRUE;
            param.isNeedClearScrn = VFX_TRUE;
            param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
            param.callback = m_recoverStateCB;
            param.result = result;
            showPopupScreen(&param);
        }

    }
    else
    {
        MDI_RESULT result;

        m_record.rec_time = 0;
        m_record.rec_size = 0;

        m_osd_recording_state_param.isPreviewHorz = m_isOSDHorz;
        m_osd_recording_state_param.isPreviewMirror = m_isOSDMirror;
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING, &m_osd_recording_state_param, (VappCamcoOSDEvtHdlr*)this);

        m_hwFlag.isRecordFailed = VFX_FALSE;
        if(getNextFilename(m_recFileNameBuf))
        {
            m_rec_record_param.fileName = m_recFileNameBuf;
            m_rec_record_save_param.fileName = m_recFileNameBuf;
            result = vapp_camco_rec_record_start(&m_rec_record_param);
        }
        else
        {
            result = VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND;
        }

        if(MDI_RES_VDOREC_SUCCEED == result)
        {
            m_backlightBeforeRecording = srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD);
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_ON)
            {
                if(m_backlightBeforeRecording > 3)
                    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, (m_backlightBeforeRecording - 2 > 0) ? (m_backlightBeforeRecording - 2) : 0);
                else if(m_backlightBeforeRecording == 3)
                    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, 2);
                srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
            }

            setState(VAPP_CAMCO_STATE_REC_RECORDING);
            recordingCyclic(NULL);
        }
        else
        {
            if(result != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)
                restoreFilename();

            if(m_isExtCalling)
            {
                vapp_camco_popup_param_struct param;
                param.isConfirm = VFX_TRUE;
                param.isNeedClearScrn = VFX_TRUE;
                param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                param.callback = m_exitStateCB;
                param.result = result;
                showPopupScreen(&param);
            }
            else
            {
                vapp_camco_popup_param_struct param;
                param.isConfirm = VFX_TRUE;
                param.isNeedClearScrn = VFX_TRUE;
                param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                param.callback = m_recoverStateCB;
                param.result = result;
                showPopupScreen(&param);
            }
        }
    }
};

void VappCamcoPage::enterRecPauseState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_PAUSE_STATE);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;

    MDI_RESULT result;

    m_recordUpdateTimer->stop();

    m_osd_pause_state_param.recTime = m_record.rec_time;
    m_osd_pause_state_param.recSize = m_record.rec_size;
    m_osd_pause_state_param.isPreviewHorz = m_osd_recording_state_param.isPreviewHorz;
    m_osd_pause_state_param.isPreviewMirror = m_osd_recording_state_param.isPreviewMirror;
    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_PAUSE, &m_osd_pause_state_param, (VappCamcoOSDEvtHdlr*)this);

    result = vapp_camco_rec_record_pause(&m_rec_record_param);

    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, m_backlightBeforeRecording);
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    if (result == MDI_RES_VDOREC_SUCCEED)
    {
        setState(VAPP_CAMCO_STATE_REC_PAUSE);

    }
    else if (result == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
    {
        vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);
        kal_sleep_task(100);

        vapp_camco_popup_param_struct param;
        param.isConfirm = VFX_TRUE;
        param.isNeedClearScrn = VFX_TRUE;
        param.callbackParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
        param.callback = m_enterStateCB;

        if((vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
        {
            param.result = MDI_RES_VDOREC_REACH_TIME_LIMIT;
        }
        else
        {
            param.result = MDI_RES_VDOREC_REACH_SIZE_LIMIT;
        }
        showPopupScreen(&param);

    }
    else if (result == MDI_RES_VDOREC_DISK_FULL)
    {
        vapp_camco_popup_param_struct param;
        param.isConfirm = VFX_FALSE;
        param.isNeedClearScrn = VFX_FALSE;
        param.callbackParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
        param.callback = m_enterStateCB;
        param.result = result;
        showPopupScreen(&param);
    }
    else
    {
        /* Camcorder is in VAPP_CAMCO_STATE_REC_PAUSE */
        m_hwFlag.isOnRecord = VFX_FALSE;

        vapp_camco_popup_param_struct param;
        param.isConfirm = VFX_TRUE;
        param.isNeedClearScrn = VFX_TRUE;
        param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
        param.callback = m_recoverStateCB;
        param.result = result;
        showPopupScreen(&param);
    }
};

void VappCamcoPage::enterRecSavingState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_SAVING_STATE);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;

    VAPP_CAMCO_START_LOGGING("SAV");
    vapp_camco_rec_record_stop(&m_rec_record_param);
    vapp_camco_rec_save_video(&m_rec_record_save_param);

    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, m_backlightBeforeRecording);
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    m_recordUpdateTimer->stop();

    if(m_hwFlag.isRecSaveSuccess)
    {
        setState(VAPP_CAMCO_STATE_REC_SAVING);

        m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_SAVING);
        m_osd_hint_state_param.isPreviewON = VFX_FALSE;
        m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
        m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
        m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;

        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
    }
    else
    {
        restoreFilename();

        vapp_camco_popup_param_struct param;
        param.isConfirm = VFX_TRUE;
        param.isNeedClearScrn = VFX_TRUE;
        param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
        param.callback = m_recoverStateCB;
        param.result = MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED;
        showPopupScreen(&param);
    }
};

void VappCamcoPage::enterRecSaveDoneState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_REC_SAVE_DONE_STATE);

    MDI_RESULT ret;

    setState(VAPP_CAMCO_STATE_REC_SAVE_DONE);

    m_rec_fetch_param.fileName = m_recFileNameBuf;
    m_rec_fetch_param.isRecWithHorzUI = m_osd_recording_state_param.isPreviewHorz;
    m_rec_fetch_param.isRecWithMirrorUI = m_osd_recording_state_param.isPreviewMirror;

    VAPP_CAMCO_STOP_LOGGING("SAV");
    VAPP_CAMCO_START_LOGGING("SHO");
    ret = vapp_camco_rec_fetch_frame(&m_rec_fetch_param);
    if(ret == MDI_RES_CAMERA_SUCCEED)
    {
        m_osd_rec_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_rec_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_RECORD;
        m_osd_rec_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_rec_quick_view_state_param.savedImg.bgColor = VRT_COLOR_TRANSPARENT;
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_QUICK_VIEW, &m_osd_rec_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);
        }
    else
    {
        restoreFilename();

        vapp_camco_popup_param_struct param;
        param.isConfirm = VFX_TRUE;
        param.isNeedClearScrn = VFX_TRUE;
        param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
        param.callback = m_recoverStateCB;
        param.result = ret;
        showPopupScreen(&param);
    }
    VAPP_CAMCO_STOP_LOGGING("SHO");
};

void VappCamcoPage::enterEnterFailState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ENTER_ENTER_FAIL_STATE);

    setState(VAPP_CAMCO_STATE_ENTER_FAIL);

#if !defined(__VAPP_CAMCO_ROTATABLE_UI__)
    // show with horz screen
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
#endif

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(VappCamcoPage::m_errStr);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT;

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);

    resetMem();

    m_errorExitTimer->start();
}

void VappCamcoPage::resultHWCallback(vapp_camco_hw_result_callback_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK, param.type, m_state);

    switch (param.type)
    {
    #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        case VAPP_CAMCO_CB_TYPE_CAM_AF:
        {
            if (m_state == VAPP_CAMCO_STATE_CAM_FOCUSING && !m_hwFlag.isTakepicFailed && !m_isTonePlaying)
            {
                if (param.afRet.af_result == MDI_AF_SEARCH_STATUS_FOUND_SUCCESS)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 0, 0);

                    m_autofocus_param.af_success_zone = param.afRet.af_success_zone;

                    playAutofocusSuccessSound();
                    m_hwFlag.isAFsuccess = VFX_TRUE;

                    enterState(VAPP_CAMCO_STATE_CAM_FOCUSED);
                }
                else if (param.afRet.af_result == MDI_AF_SEARCH_STATUS_SWITCH_MACRO)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 0, 1);

                    vapp_camco_osd_screen_param_struct af_param;
                    af_param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
                    af_param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_MACRO;
                    m_OSD->setScreenParam(af_param);
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 0, 2);

                    U32 af_active_zone = 0;

                    af_active_zone = m_autofocus_param.af_active_zone;

                    for (VfxU32 idx = VAPP_CAMCO_OSD_FOCUS_REGION_1; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
                    {
                        if (af_active_zone & 0x00000001)
                        {
                            vapp_camco_osd_screen_param_struct af_param;
                            af_param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
                            af_param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING_FAIL;
                            af_param.focus.w = m_autofocus_param.af_zone.af_zone[idx].af_zone_w;
                            af_param.focus.h = m_autofocus_param.af_zone.af_zone[idx].af_zone_h;
                            af_param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
                            af_param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
                            af_param.index = idx;

                            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
                            VfxPoint p;
                            p = transPointToOSDCoord(VfxPoint(af_param.focus.center_x,  af_param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
                            if(m_isVideoLayerHorz != m_isOSDHorz)
                            {
                                VfxU32 t = af_param.focus.w;
                                af_param.focus.w = af_param.focus.h;
                                af_param.focus.h = t;
                            }

                            af_param.focus.center_x = p.x;
                            af_param.focus.center_y = p.y;

                            m_OSD->setScreenParam(af_param);
                        }
                        af_active_zone = af_active_zone >> 1;
                    }
                }
            }
            break;
        }
        case VAPP_CAMCO_CB_TYPE_REC_AF:
        {
            if (m_state == VAPP_CAMCO_STATE_REC_FOCUSING && !m_hwFlag.isTakepicFailed && !m_isTonePlaying)
            {
                if (param.recAfRet.af_result == MDI_AF_SEARCH_STATUS_FOUND_SUCCESS)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 1, 0);

                    m_autofocus_param.af_success_zone = param.recAfRet.af_success_zone;

                    playAutofocusSuccessSound();
                    m_hwFlag.isAFsuccess = VFX_TRUE;

                    enterState(VAPP_CAMCO_STATE_REC_FOCUSED);
                }
                else if (param.recAfRet.af_result == MDI_AF_SEARCH_STATUS_SWITCH_MACRO)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 1, 1);

                    vapp_camco_osd_screen_param_struct af_param;
                    af_param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
                    af_param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_MACRO;
                    m_OSD->setScreenParam(af_param);
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 1, 2);

                    U32 af_active_zone = 0;

                    af_active_zone = m_autofocus_param.af_active_zone;

                    for (VfxU32 idx = VAPP_CAMCO_OSD_FOCUS_REGION_1; idx < VAPP_CAMCO_OSD_FOCUS_REGION_END; idx++)
                    {
                        if (af_active_zone & 0x00000001)
                        {
                            vapp_camco_osd_screen_param_struct af_param;
                            af_param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
                            af_param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING_FAIL;
                            af_param.focus.w = m_autofocus_param.af_zone.af_zone[idx].af_zone_w;
                            af_param.focus.h = m_autofocus_param.af_zone.af_zone[idx].af_zone_h;
                            af_param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
                            af_param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
                            af_param.index = idx;

                            // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
                            VfxPoint p;
                            p = transPointToOSDCoord(VfxPoint(af_param.focus.center_x,  af_param.focus.center_y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
                            if(m_isVideoLayerHorz != m_isOSDHorz)
                            {
                                VfxU32 t = af_param.focus.w;
                                af_param.focus.w = af_param.focus.h;
                                af_param.focus.h = t;
                            }

                            af_param.focus.center_x = p.x;
                            af_param.focus.center_y = p.y;

                            m_OSD->setScreenParam(af_param);
                        }
                        af_active_zone = af_active_zone >> 1;
                    }
                }
            }
            break;
        }
    #endif
        case VAPP_CAMCO_CB_TYPE_RECORD_FINISH:
        {
            m_hwFlag.isOnRecord = VFX_FALSE;
            m_hwFlag.isPreviewStart = VFX_FALSE;

            m_recordRecordingResult = param.recordRet;

            m_recordUpdateTimer->stop();

            srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, m_backlightBeforeRecording);
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

            if (param.recordRet == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 2, 0);

                vapp_camco_osd_screen_param_struct recUpdateParam;
                recUpdateParam.type = VAPP_CAMCO_OSD_SCR_PARAM_RECORDING_UPDATE;
                vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);
                m_record.rec_time = (U32) (m_record.rec_time / 1000);
                vapp_camco_rec_record_get_size(&recUpdateParam.rec_size);
                recUpdateParam.rec_time = m_record.rec_time;

                m_OSD->setScreenParam(recUpdateParam);

                cleanPreviewScreen();

                VfxTimer *timer;
                VFX_OBJ_CREATE(timer,VfxTimer,this);
                timer->setStartDelay(1);
                timer->m_signalTick.connect(this, &VappCamcoPage::recordingFinishTick);
                timer->start();
            }
            else if(param.recordRet == MDI_RES_VDOREC_REACH_TIME_LIMIT)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 2, 1);

                vapp_camco_osd_screen_param_struct recUpdateParam;
                recUpdateParam.type = VAPP_CAMCO_OSD_SCR_PARAM_RECORDING_UPDATE;
                vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);
                m_record.rec_time = (U32) (m_record.rec_time / 1000);
                vapp_camco_rec_record_get_size(&recUpdateParam.rec_size);
                recUpdateParam.rec_time = m_record.rec_time;

                m_OSD->setScreenParam(recUpdateParam);

                cleanPreviewScreen();

                VfxTimer *timer;
                VFX_OBJ_CREATE(timer,VfxTimer,this);
                timer->setStartDelay(1);
                timer->m_signalTick.connect(this, &VappCamcoPage::recordingFinishTick);
                timer->start();
            }
            else if (param.recordRet >= MDI_RES_VDOREC_SUCCEED)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 2, 2);

                vapp_camco_popup_param_struct recResultparam;
                recResultparam.isConfirm = VFX_FALSE;
                recResultparam.isNeedClearScrn = VFX_FALSE;
                recResultparam.callbackParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
                recResultparam.callback = m_enterStateCB;
                recResultparam.result = param.recordRet;
                showPopupScreen(&recResultparam);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 2, 3);

                vapp_camco_popup_param_struct recResultparam;
                recResultparam.isConfirm = VFX_TRUE;
                recResultparam.isNeedClearScrn = VFX_TRUE;
                recResultparam.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                recResultparam.callback = m_recoverStateCB;
                recResultparam.result = param.recordRet;
                showPopupScreen(&recResultparam);
            }
            break;
        }
        case VAPP_CAMCO_CB_TYPE_RECORD_SAVE:
        {
            m_hwFlag.isRecSaveCallback = VFX_TRUE;
            m_recordSaveResult = param.recordRet;

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 3, m_recordSaveResult);

            if (m_isExtCalling)
            {
                if (m_recordSaveResult >= MDI_RES_VDOREC_SUCCEED)
                {
                    vcui_camco_event_struct evt;

                    MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_CAMCO_EVENT_RESULT_SUCCESS,  m_appID);
                    mmi_wcscpy(g_vapp_camco_ext_calling_file_name, m_recFileNameBuf);
                    evt.filePath = g_vapp_camco_ext_calling_file_name;

                #ifdef __MMI_OP02_LEMEI_FTO__
                    // when press key to stop record and CUI is called in Lemei App
                    // behavior will be " Not send back file path to let App exit itself"
                    if(m_isSaveBeforeLeave)
                    {
                        m_isSaveBeforeLeave = VFX_FALSE;
                        evt.filePath = NULL;
                    }
                #endif

                    VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
                    app->postToCaller((mmi_group_event_struct*)&evt);


                }
                else
                {
                    if(isAppActive())
                    {
                        restoreFilename();

                        vapp_camco_popup_param_struct param;
                        param.isConfirm = VFX_TRUE;
                        param.isNeedClearScrn = VFX_TRUE;
                        param.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                        param.callback = m_exitStateCB;
                        param.result = m_recordSaveResult;
                        showPopupScreen(&param);
                    }
                    else
                    {
                        vapp_camco_popup_callback_param_struct param;
                        param.next_state = VAPP_CAMCO_STATE_EXIT;
                        mmi_event_notify_enum popup_type;
                        VappCamcoPage::m_errStr = getMappingShownString(m_recordSaveResult, &popup_type);
                        exitCamcoCUI(param);
                    }
                }

                if (m_state == VAPP_CAMCO_STATE_REC_INT_SAVING)
                {
                    /* For avoiding calling mdi_video_rec_stop_save() in del_scr_callback */
                    m_state = VAPP_CAMCO_STATE_REC_INT_PREVIEW;
                }
            }
            else
            {
                m_recordSaveResult = param.recordRet;

                if(m_state == VAPP_CAMCO_STATE_REC_SAVING && m_isSaveBeforeLeave)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 3, 1);
                    m_isSaveBeforeLeave = VFX_FALSE;
                    setState(VAPP_CAMCO_STATE_REC_SAVE_DONE);
                    exit();
                }
                else if (m_state == VAPP_CAMCO_STATE_REC_SAVING)
                {
                    if (m_recordSaveResult == MDI_RES_VDOREC_SUCCEED)
                    {
                        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 3, 2);
                        enterState(VAPP_CAMCO_STATE_REC_SAVE_DONE);
                    }
                    else
                    {
                        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESULT_HW_CALLBACK_EVENT, 3, 3);
                        restoreFilename();
                        m_hwFlag.isRecordFailed = VFX_TRUE;

                        vapp_camco_popup_param_struct recResultparam;
                        recResultparam.isConfirm = VFX_TRUE;
                        recResultparam.isNeedClearScrn = VFX_TRUE;
                        recResultparam.callbackParam.next_state = VAPP_CAMCO_STATE_EXIT;
                        recResultparam.callback = m_recoverStateCB;
                        recResultparam.result = m_recordSaveResult;
                        showPopupScreen(&recResultparam);
                    }
                }
            }
            break;
        }
    }
}

VfxBool VappCamcoPage::isSlientMode(void)
{
#ifdef __MMI_CAMCO_SILENT_MODE_SUPPORT__
    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ISSLIENTMODE, 1);
        return MMI_TRUE;
    }
    else
    {

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ISSLIENTMODE, 0);
        return MMI_FALSE;
    }
#else /* __MMI_CAMCO_SILENT_MODE_SUPPORT__ */
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_ISSLIENTMODE, 0);
    return MMI_FALSE;
#endif /* __MMI_CAMCO_SILENT_MODE_SUPPORT__ */ 
}

void VappCamcoPage::initCountDownSound(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_INITCOUNTDOWNSOUND);

    if(!isSlientMode())
    {
        m_multiSoundDummy = mdi_audio_mma_open_string(0, (void*)camco_sound_dummy_bg, CAMCO_SOUND_DUMMY_BG_LEN, MDI_FORMAT_SMF, 0, NULL, NULL);
        mdi_audio_mma_play(m_multiSoundDummy);

        m_countSoundData = get_audio((U16)(AUD_ID_VAPP_CAMCO_COUNTDOWN), &m_countSpundType, &m_countSoundLen);

        m_multiSoundCountdown = mdi_audio_mma_open_string(
                                    0,
                                    (void*)camco_sound_countdown,
                                    (U32) CAMCO_SOUND_COUNTDOWN_LEN,
                                    MDI_FORMAT_WAV,
                                    1,
                                    NULL,
                                    NULL);
    #ifdef __MTK_TARGET__
        mdi_audio_mma_get_estimated_duration(m_multiSoundCountdown, &m_countSoundDuration);
    #else
        m_countSoundDuration = 1000;
    #endif
    }
}

void VappCamcoPage::deinitCountDownSound(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_DEINITCOUNTDOWNSOUND);

    if (!isSlientMode())
    {
        mdi_audio_mma_stop(m_multiSoundDummy);
        mdi_audio_mma_close(m_multiSoundDummy);

        mdi_audio_mma_stop(m_multiSoundCountdown);
        mdi_audio_mma_close(m_multiSoundCountdown);


        m_multiSoundDummy = 0;
        m_multiSoundCountdown = 0;
    }
}

void VappCamcoPage::playCatureSound(MDI_RESULT cap_ret)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_PLAY_CATURE_SOUND, cap_ret, isSlientMode());

    U32 aud_len;
    U8 *aud_data = NULL;
    U8 aud_type;

    if (cap_ret != MDI_RES_CAMERA_SUCCEED || isSlientMode())
    {
        return;
    }

    aud_data = get_audio((U16) (AUD_ID_VAPP_CAMCO_CAPTURE_1), &aud_type, &aud_len);

    if (aud_data != NULL)
    {
        mdi_audio_play_string_with_vol_path(
            (void*)aud_data,
            aud_len,
            aud_type,
            DEVICE_AUDIO_PLAY_ONCE,
            NULL,
            NULL,
            LEVEL5,
            MDI_DEVICE_SPEAKER_BOTH);
    }
}

void VappCamcoPage::Capture(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_CAPTURE, m_state);

    if (m_state != VAPP_CAMCO_STATE_CAM_PREVIEW &&
        m_state != VAPP_CAMCO_STATE_CAM_FOCUSING &&
        m_state != VAPP_CAMCO_STATE_CAM_FOCUSED &&
        m_state != VAPP_CAMCO_STATE_CAM_COUNTDOWN)
    {
        return;
    }

    // it mean we need to wait for restart preview done
    // or new setting is not applied
    // the case may happen when setting anumation (beause we don't bloack event when animating)
    if(m_Setting->isNeedRestartPreview())
        return;

    enterState(VAPP_CAMCO_STATE_CAM_CAPTURE);
}

void VappCamcoPage::playSoundandRecord(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_PLAY_RECORD_SOUND, isSlientMode());

    if(isSlientMode())
    {
        enterState(VAPP_CAMCO_STATE_REC_RECORDING);
        return;
    }

    mdi_audio_play_id(TONE_WARNING1,DEVICE_AUDIO_PLAY_ONCE);
    m_recordToneTimer->start();
    m_isTonePlaying = VFX_TRUE;

    vapp_camco_osd_screen_param_struct param;
    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
    param.isBusy = VFX_TRUE;
    m_OSD->setScreenParam(param);
}

void VappCamcoPage::recordToneCyclic(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_PLAY_RECORD_TONE_DONE, m_state);

    m_isTonePlaying = VFX_FALSE;

    vapp_camco_osd_screen_param_struct param;
    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
    param.isBusy = VFX_FALSE;
    m_OSD->setScreenParam(param);

    if(m_state != VAPP_CAMCO_STATE_REC_PREVIEW && m_state != VAPP_CAMCO_STATE_REC_FOCUSING && m_state != VAPP_CAMCO_STATE_REC_FOCUSED)
        return;

    enterState(VAPP_CAMCO_STATE_REC_RECORDING);
}

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
void VappCamcoPage::playAutofocusSuccessSound(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_PLAY_AUTOFOCUS_SUCCESS_SOUND, isSlientMode());

    if (isSlientMode())
    {
        return;
    }

    mdi_audio_play_string_with_vol_path(
        (void*)camco_af_succeed,
        688,
        MDI_FORMAT_WAV,
        DEVICE_AUDIO_PLAY_ONCE,
        NULL,
        NULL,
        LEVEL5,
        MDI_DEVICE_SPEAKER_BOTH);

    VfxTimer *timer;
    VFX_OBJ_CREATE(timer,VfxTimer,this);
    m_isAFTonePlaying = VFX_TRUE;
    timer->setStartDelay(300);
    timer->m_signalTick.connect(this, &VappCamcoPage::autoFocusToneCyclic);
    timer->start();
}

void VappCamcoPage::autoFocusToneCyclic(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_PLAY_AUTOFOCUS_SUCCESS_SOUND_DONE);

    VFX_OBJ_CLOSE(source);

    if(m_isAFTonePlaying)
    {
        m_isAFTonePlaying = VFX_FALSE;
    }
}
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
void VappCamcoPage::sceneDetectCyclic(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SCN_DETECT_CYCLIC, m_state, m_isDelayPreview, m_isStartingPreview);

    if(m_isDelayPreview || m_isStartingPreview)
    {
        m_sceneDetectCycTimer->start();
        return;
    }

    if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW)
    {
        vapp_camco_cam_scenedetect_get_result(&m_cam_scene_param);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SCN_DETECT_CYCLIC, m_cam_scene_param.currentScene);

        ((CamSceneModeSetting*)(m_Setting->getSetting(VAPP_CAMCO_SETTING_CAMSCENEMODE)))->setActiveValue(m_cam_scene_param.currentScene);

        vapp_camco_osd_screen_param_struct param;
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_SCN_UPDATE;
        m_OSD->setScreenParam(param);

        m_sceneDetectCycTimer->start();
    }
}
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
void VappCamcoPage::smiledetectSuccess(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SMILEDETECT_SUCCESS);

    m_isOSDinSmileDetectMode = VFX_FALSE;

    // because we need to show the last frame with smiel rect
    // so we call capture with timer not function call
    Capture();
}
#endif

#ifdef __FACE_DETECTION_SUPPORT__
void VappCamcoPage::smiledetectCyclic(VfxTimer *source)
{
    VAPP_CAMCO_START_LOGGING("SMI");

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SMILEDETECT_CYCLIC, m_state, m_isDelayPreview, m_isStartingPreview);

    if(m_isDelayPreview || m_isStartingPreview)
    {
        m_smileDetectCycTimer->start();
        return;
    }

    vapp_camco_osd_screen_param_struct param;

    if(m_state != VAPP_CAMCO_STATE_CAM_PREVIEW && m_state != VAPP_CAMCO_STATE_CAM_FOCUSED & m_state != VAPP_CAMCO_STATE_CAM_FOCUSING)
        return;

    vapp_camco_cam_smiledetect_get_result(&m_cam_smiledetect_param);

    if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW || m_state == VAPP_CAMCO_STATE_CAM_FOCUSED || m_state == VAPP_CAMCO_STATE_CAM_FOCUSING)
    {
        // face detect part
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FD;
        m_OSD->setScreenParam(param);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SMILEDETECT_RESULT, m_cam_smiledetect_param.fd_result);

        if (m_cam_smiledetect_param.fd_result == MDI_RES_CAMERA_SUCCEED)
        {
            for (VfxU32 idx = 0; idx < m_cam_smiledetect_param.fd_searched_num; idx++)
            {
                param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FD;
                if(idx == 0)
                {
                    param.fd.type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED;
                }
                else
                {
                    param.fd.type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_TRACKING;
                }
                param.index = idx;
                param.fd.x= m_cam_smiledetect_param.fd_zone[idx].fd_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
                param.fd.y= m_cam_smiledetect_param.fd_zone[idx].fd_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
                param.fd.w= m_cam_smiledetect_param.fd_zone[idx].fd_zone_w;
                param.fd.h= m_cam_smiledetect_param.fd_zone[idx].fd_zone_h;

                // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
                VfxPoint p;
                p = transPointToOSDCoord(VfxPoint(param.fd.x,  param.fd.y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
                if(m_isVideoLayerHorz != m_isOSDHorz)
                {
                    VfxU32 t = param.fd.w;
                    param.fd.w = param.fd.h;
                    param.fd.h = t;
                }

                param.fd.x = p.x;
                param.fd.y = p.y;

                m_OSD->setScreenParam(param);

            }
        }

    #ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
        // smile detect part
        if(m_Setting->getValue(VAPP_CAMCO_SETTING_SD) == VAPP_CAMCO_SMILE_DETECT_ON && m_isOSDinSmileDetectMode)
        {
            vapp_camco_osd_screen_param_struct param;

            param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_SD;
            m_OSD->setScreenParam(param);

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SMILEDETECT_CYCLIC, m_cam_smiledetect_param.sd_end_flag);

            if (m_cam_smiledetect_param.sd_end_flag)
            {

                for (VfxU32 idx = 0; idx < m_cam_smiledetect_param.sd_searched_num; idx++)
                {
                    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_SD;
                    param.sd.type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED;
                    param.index = idx;
                    param.sd.x= m_cam_smiledetect_param.fd_zone[idx].sd_zone_x + m_previewWindow.getX() - (m_previewWindow.getWidth()>>1);
                    param.sd.y= m_cam_smiledetect_param.fd_zone[idx].sd_zone_y + m_previewWindow.getY() - (m_previewWindow.getHeight()>>1);
                    param.sd.w= m_cam_smiledetect_param.fd_zone[idx].sd_zone_w;
                    param.sd.h= m_cam_smiledetect_param.fd_zone[idx].sd_zone_h;

                    // MED will give the coord depend on video layer coord, so we need to transform to OSD coord
                    VfxPoint p;
                    p = transPointToOSDCoord(VfxPoint(param.sd.x,  param.sd.y), (m_isVideoLayerHorz?VFX_SCR_ROTATE_TYPE_270:VFX_SCR_ROTATE_TYPE_0), m_currentRotation);
                    if(m_isVideoLayerHorz != m_isOSDHorz)
                    {
                        VfxU32 t = param.sd.w;
                        param.sd.w = param.sd.h;
                        param.sd.h = t;
                    }

                    param.sd.x = p.x;
                    param.sd.y = p.y;

                    m_OSD->setScreenParam(param);
                }
            }

            if (m_cam_smiledetect_param.sd_end_flag && m_isOSDinSmileDetectMode)
            {
                VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                renderer->mustShowNextFrame();
                m_smileDetectSuccessTimer->start();
                return;
            }
        }
    #endif
        m_smileDetectCycTimer->start();
    }
    VAPP_CAMCO_STOP_LOGGING("SMI");
}
#endif

void VappCamcoPage::countdownCyclic(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_COUNTDOWN_CYCLIC, m_countdownDuration);

    double tick_elapsed;

    if (m_countdownDuration > 0)
    {
        if (m_countSoundData != NULL)
        {
            if (!isSlientMode())
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA, MDI_AUD_VOL_4);
                mdi_audio_mma_stop(m_multiSoundCountdown);
                mdi_audio_mma_play(m_multiSoundCountdown);
            }
        }
    }
    if(m_countdownDuration > 0)
    {
        kal_get_time(&m_countdownEndTicks);
        tick_elapsed = (m_countdownEndTicks - m_countdownStartTicks);
        m_countdownStartTicks = m_countdownEndTicks;
        tick_elapsed = ((double)tick_elapsed * 4.615);  /* msec */

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_COUNTDOWN_CYCLIC1, m_countdownDuration,  (VfxU32)((m_countdownDuration/2000.0) * 250 + 250));

        VfxU32 TimerDur = (VfxU32)((m_countdownDuration/2000.0) * 250 + 250);
        if(m_countSoundDuration + 460 > TimerDur)
            TimerDur = m_countSoundDuration + 460;
        countdownCycTimer->setStartDelay(TimerDur);
        countdownCycTimer->start();

        if(m_countdownDuration > tick_elapsed)
            m_countdownDuration -= tick_elapsed;
        else
            m_countdownDuration = 0;
    }
    else
    {
        deinitCountDownSound();
        Capture();
    }
}

void VappCamcoPage::recordingCyclic(VfxTimer *source)
{
    VAPP_CAMCO_START_LOGGING("REU");

    MMI_ASSERT(m_state == VAPP_CAMCO_STATE_REC_RECORDING);

    if(m_Setting->getValue(VAPP_CAMCO_SETTING_TIMELAPSE) == VAPP_CAMCO_TIME_LAPSE_OFF)
    {
        vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);
        m_record.rec_time = (U32) (m_record.rec_time / 1000);
    }
    else
    {
        vapp_camco_rec_record_get_count((VfxU64*)&m_record.rec_time);
    }

    VfxU64 rec_size;
    vapp_camco_rec_record_get_size(&rec_size);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RECORDINGCYCLIC, m_record.rec_time,  rec_size);

    /*
     * Sometimes, MED clears the record size after sending the reaching size limitation indication to MMI,
     * but MMI doesn't receive it yet. However, record timer timeout and then get the record size  = 0.
     * Therefore, MMI needs to cover this case.
     */
    if (rec_size < m_record.rec_size)
    {
        rec_size = m_record.rec_size;
    }
    else
    {
        m_record.rec_size = rec_size;
    }
    m_record.rec_size /= 1024;

    vapp_camco_osd_screen_param_struct param;
    param.type = VAPP_CAMCO_OSD_SCR_PARAM_RECORDING_UPDATE;
    param.rec_size = m_record.rec_size;
    param.rec_time = m_record.rec_time;

    m_OSD->setScreenParam(param);

    if (m_hwFlag.isOnRecord)
    {
        m_recordUpdateTimer->start();
    }

    VAPP_CAMCO_STOP_LOGGING("REU");
}

void VappCamcoPage::recordingFinishTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RECORD_FINISH_TICK, m_state);

    VFX_OBJ_CLOSE(source);

    if(m_state == VAPP_CAMCO_STATE_REC_RECORDING)
    {
        vapp_camco_popup_param_struct recResultparam;
        recResultparam.isConfirm = VFX_FALSE;
        recResultparam.isNeedClearScrn = VFX_FALSE;
        recResultparam.callbackParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
        recResultparam.callback = m_enterStateCB;
        recResultparam.result = m_recordRecordingResult;
        showPopupScreen(&recResultparam);
    }
}

VfxBool VappCamcoPage::isAppActive(void)
{
    if ((isInCall() ||
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0)) ||
        srv_reminder_is_expiring() ||
        m_state == VAPP_CAMCO_STATE_EXIT)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_IS_APP_ACTIVE, 0);
        return VFX_FALSE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_IS_APP_ACTIVE, 1);
        return VFX_TRUE;
    }
}

VfxBool VappCamcoPage::isInCall(void)
{
#if !defined(__RF_DESENSE_TEST__)
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_DATA_CSD_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_IS_APP_ACTIVE, 1);
        return VFX_TRUE;
    }
    else
#endif /* !defined(__RF_DESENSE_TEST__) */
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_IS_APP_ACTIVE, 0);
        return VFX_FALSE;
    }
}

VfxU16 VappCamcoPage::getMappingShownString(MDI_RESULT result, mmi_event_notify_enum *popup_type)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_MAPPING_SHOWN_STRING, result);

    switch (result)
    {
        case MDI_RES_CAMERA_ERR_DISK_FULL:
        case MDI_RES_VDOREC_ERR_DISK_FULL:
        case MDI_RES_VDOREC_DISK_FULL:
        case MDI_RES_VDOREC_ERR_MEMORY_INSUFFICIENT:
        case MDI_RES_VDOREC_ERR_STORAGE_INSUFFICIENT:
            *popup_type = MMI_EVENT_FAILURE;
            return FMGR_FS_DISK_FULL_TEXT;
            //break;

        case MDI_RES_CAMERA_ERR_NO_DISK:
        case MDI_RES_CAMERA_ERR_CAPTURE_FAILED:
        case MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_CAMCO_CAPTURE_FAILED;
            //break;

        case VAPP_CAMCO_CAM_NOT_READY:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_CAMCO_NOTIFY_HW_NOT_READY;
            //break;

        case MDI_RES_VDOREC_REACH_SIZE_LIMIT:
            *popup_type = MMI_EVENT_INFO;
            return STR_ID_VAPP_CAMCO_NOTIFY_REACH_SIZE_LIMIT;
            //break;

        case MDI_RES_VDOREC_REACH_TIME_LIMIT:
            *popup_type = MMI_EVENT_INFO;
            return STR_ID_VAPP_CAMCO_NOTIFY_REACH_TIME_LIMIT;
            //break;

        case MDI_RES_VDOREC_ERR_NO_DISK:
        case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
        case MDI_RES_VDOREC_ERR_WRITE_PROTECTION:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_CAMCO_NOTIFY_STORAGE_NOT_READY;
            //break;

        case MDI_RES_VDOREC_ERR_RESUME_FAILED:
        case MDI_RES_VDOREC_ERR_RECORD_FAILED:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_CAMCO_NOTIFY_ERROR;
            //break;

        case MDI_RES_VDOREC_ERR_PAUSE_FAILED:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_CAMCO_PAUSE_FAILED;
            //break;

        case VAPP_CAMCO_ERR_SAVE_FAIL:
        case MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED:
        case MDI_RES_CAMERA_ERR_SAVE_FAILED:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_GLOBAL_FAILED_TO_SAVE;
            //break;

        default:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_GLOBAL_ERROR;
            //break;
    }
}

void VappCamcoPage::showPopupScreen(vapp_camco_popup_param_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SHOW_POPUP_SCREEN, param->result, param->isConfirm);
    U16 string_id;
    srv_prof_tone_enum tone_type = SRV_PROF_TONE_WARNING;

    memcpy(&m_currentPopupParam, param, sizeof(vapp_camco_popup_param_struct));

    if(m_currentPopupParam.result != 0)
    {
        mmi_event_notify_enum popup_type;
        string_id = getMappingShownString(m_currentPopupParam.result, &popup_type);
        VappCamcoPage::m_errStr = string_id;
        srv_prof_tone_enum tone_type = mmi_get_event_based_sound(popup_type);
    }
    else
    {
        string_id = VappCamcoPage::m_errStr;
        tone_type = mmi_get_event_based_sound(MMI_EVENT_FAILURE);
    }

    if (tone_type != NONE_TONE)
    {
        srv_prof_play_tone(tone_type, NULL);
    }

    if(m_currentPopupParam.isNeedClearScrn)
    {
        if(!m_hwFlag.isPreviewStart)
            cleanPreviewScreen();
    }

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(string_id);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    if(!m_currentPopupParam.isConfirm)
    {
        m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
        m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;
    }
    else
    {
        m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_ERROR;
        m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_NOTIFY;
    }

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);

    if(!m_currentPopupParam.isConfirm)
    {
        m_popupTimer->setStartDelay(VAPP_CAMCO_ERROR_TIMER_DUR);
        m_popupTimer->m_signalTick.connect(this, &VappCamcoPage::popupcallback);
        m_popupTimer->start();
        m_isPopupRunning = VFX_TRUE;
    }
    else
    {
        m_isNotifyRunning = VFX_TRUE;
    }
}

void VappCamcoPage::stopPopupScreen(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_STOP_POPUP_SCREEN, m_isPopupRunning);

    if(m_isPopupRunning)
    {
        m_popupTimer->stop();
        m_isPopupRunning = VFX_FALSE;
    }
    else if(m_isNotifyRunning)
    {
        m_isNotifyRunning = VFX_FALSE;
    }
}

void VappCamcoPage::popupcallback(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_POPUP_CALLBACK);

    m_isPopupRunning = VFX_FALSE;
    m_currentPopupParam.callback.invoke(m_currentPopupParam.callbackParam);
}

void VappCamcoPage::popupRecovercallback(vapp_camco_popup_callback_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_POPUP_RECOVERCALLBACK, m_state);

    ClearKeyEvents();

    switch (m_state)
    {
        case VAPP_CAMCO_STATE_CAM_PREVIEW:
        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
        case VAPP_CAMCO_STATE_CAM_FOCUSING:
        case VAPP_CAMCO_STATE_CAM_FOCUSED:
        case VAPP_CAMCO_STATE_CAM_CAPTURE:
        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;

        case VAPP_CAMCO_STATE_REC_PREVIEW:
        case VAPP_CAMCO_STATE_REC_SAVING:
        case VAPP_CAMCO_STATE_REC_FOCUSING:
        case VAPP_CAMCO_STATE_REC_FOCUSED:
        case VAPP_CAMCO_STATE_REC_SAVE_DONE:
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;

        case VAPP_CAMCO_STATE_REC_RECORDING:
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;

        case VAPP_CAMCO_STATE_REC_PAUSE:
            enterState(VAPP_CAMCO_STATE_REC_SAVING);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}

void VappCamcoPage::exitCamcoCUI(vapp_camco_popup_callback_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_EXIT_CAMCO_CUI);

    vcui_camco_event_struct evt;

    MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_CAMCO_EVENT_RESULT_FAILED,  m_appID);
    evt.filePath = NULL;
    VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
    app->postToCaller((mmi_group_event_struct*)&evt);
}

void VappCamcoPage::popupEntercallback(vapp_camco_popup_callback_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_POPUP_ENTER_CALLBACK, param.next_state);

    enterState(param.next_state);
}

void VappCamcoPage::cleanPreviewScreen(void)
{
    gdi_handle handleT = m_previewFrame->getLayerHandle();
    if(handleT)
    {
        gdi_layer_push_and_set_active(handleT);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
}

VfxPoint VappCamcoPage::transPointToOSDCoord(VfxPoint p, VfxScrRotateTypeEnum from, VfxScrRotateTypeEnum to)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_TRANS_P_TO_OSD, from, to);

    if(from == VFX_SCR_ROTATE_TYPE_0)
    {
        if(to == VFX_SCR_ROTATE_TYPE_0)
            return p;
        else if(to == VFX_SCR_ROTATE_TYPE_90)
            return VfxPoint(LCD_HEIGHT - p.y, p.x);
        else if(to == VFX_SCR_ROTATE_TYPE_180)
            return VfxPoint(LCD_WIDTH - p.x, LCD_HEIGHT - p.y);
        else if(to == VFX_SCR_ROTATE_TYPE_270)
            return VfxPoint(p.y, LCD_WIDTH - p.x);
        else 
            return p;
    }
    else if(from == VFX_SCR_ROTATE_TYPE_270)
    {
        if(to == VFX_SCR_ROTATE_TYPE_0)
            return VfxPoint(LCD_WIDTH - p.y, p.x);
        else if(to == VFX_SCR_ROTATE_TYPE_90)
            return VfxPoint(LCD_HEIGHT - p.x, LCD_WIDTH - p.y);
        else if(to == VFX_SCR_ROTATE_TYPE_180)
            return VfxPoint(p.y, LCD_HEIGHT - p.x);
        else if(to == VFX_SCR_ROTATE_TYPE_270)
            return p;
        else
            return p;
    }
    else
    {
        return p;
    }
}

mmi_ret VappCamcoPage::fileMgrEventHdlr(mmi_event_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_FMGR_EVENT);

    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    VappCamcoPage* obj = (VappCamcoPage *)param->user_data;

    if(obj == NULL)
        return MMI_RET_OK;

    if(obj->m_isStartingApp)
        return MMI_RET_OK;

    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {
            srv_fmgr_filelist_refresh_result_event_struct *refreshEvent = (srv_fmgr_filelist_refresh_result_event_struct*)param;

            S32 ret;
            VfxS32 count = srv_fmgr_filelist_count(refreshEvent->handle);
            for(; obj->m_lastFileindex < count; obj->m_lastFileindex++)
            {
                srv_fmgr_fileinfo_struct info;

                ret = srv_fmgr_filelist_get_fileinfo(
                        refreshEvent->handle,
                        obj->m_lastFileindex,
                        &info);

                if(ret == FS_NO_ERROR)
                {
                    if(vapp_camco_get_julian_day(&(info.created_datetime)) > obj->m_lastFileTime) // newer
                    {
                        obj->m_lastFileTime = vapp_camco_get_julian_day(&(info.created_datetime));
                        ret = srv_fmgr_filelist_get_filepath(
                                                refreshEvent->handle,
                                                obj->m_lastFileindex,
                                                g_vapp_camco_last_file_name,
                                                256);
                    }
                }
                else if(ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
                {
                    if(srv_fmgr_filelist_get_state(refreshEvent->handle) == SRV_FMGR_FILELIST_STATE_READY)
                    {
        	            if ((srv_fmgr_filelist_get_capability(refreshEvent->handle) == SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND))
        	            {
        	            	ret = srv_fmgr_filelist_load_file(
                                refreshEvent->handle,
        	                    obj->m_lastFileindex,
        	                    fileMgrEventHdlr,
        	                    (void*)obj);

        					if (ret != 0)
        					{
                                srv_fmgr_filelist_destroy(refreshEvent->handle);
                                obj->m_isGetFileList = VFX_FALSE;
        		                return MMI_RET_OK;
        					}
        	            }
                    }
                    break;
                }
                else
                {
                    return MMI_RET_OK;
                }

            }

            if(obj->m_lastFileindex == count)
            {
                srv_fmgr_filelist_destroy(refreshEvent->handle);
                obj->m_isGetFileList = VFX_FALSE;

                if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                {
                    vapp_camco_osd_screen_param_struct param;
                    param.type = VAPP_CAMCO_OSD_SCR_PARAM_CAM_THUMBNAIL_UPDATE;
                    param.previousFileName = g_vapp_camco_last_file_name;
                    obj->m_OSD->setScreenParam(param);
                }
                else if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
                {
                    vapp_camco_osd_screen_param_struct param;
                    param.type = VAPP_CAMCO_OSD_SCR_PARAM_REC_THUMBNAIL_UPDATE;
                    param.previousFileName = g_vapp_camco_last_file_name;
                    obj->m_OSD->setScreenParam(param);
                }
            }
            break;
        }
        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
        {
            srv_fmgr_filelist_refresh_result_event_struct *refreshEvent = (srv_fmgr_filelist_refresh_result_event_struct*)param;

            S32 ret;
            VfxS32 count = srv_fmgr_filelist_count(refreshEvent->handle);
            for(; obj->m_lastFileindex < count; obj->m_lastFileindex++)
            {
                srv_fmgr_fileinfo_struct info;

                ret = srv_fmgr_filelist_get_fileinfo(
                        refreshEvent->handle,
                        obj->m_lastFileindex,
                        &info);

                if(ret == FS_NO_ERROR)
                {
                    if(vapp_camco_get_julian_day(&(info.created_datetime)) > obj->m_lastFileTime) // newer
                    {
                        obj->m_lastFileTime = vapp_camco_get_julian_day(&(info.created_datetime));
                        ret = srv_fmgr_filelist_get_filepath(
                                                refreshEvent->handle,
                                                obj->m_lastFileindex,
                                                g_vapp_camco_last_file_name,
                                                256);
                    }
                }
                else if(ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
                {
                    if(srv_fmgr_filelist_get_state(refreshEvent->handle) == SRV_FMGR_FILELIST_STATE_READY)
                    {
        	            if ((srv_fmgr_filelist_get_capability(refreshEvent->handle) == SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND))
        	            {
        	            	ret = srv_fmgr_filelist_load_file(
                                refreshEvent->handle,
        	                    obj->m_lastFileindex,
        	                    fileMgrEventHdlr,
        	                    (void*)obj);

        					if (ret != 0)
        					{
                                srv_fmgr_filelist_destroy(refreshEvent->handle);
                                obj->m_isGetFileList = VFX_FALSE;
        		                return MMI_RET_OK;
        					}
        	            }
                    }
                    break;
                }
                else
                {
                    return MMI_RET_OK;
                }

            }

            if(obj->m_lastFileindex == count)
            {
                srv_fmgr_filelist_destroy(refreshEvent->handle);
                obj->m_isGetFileList = VFX_FALSE;

                if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                {
                    vapp_camco_osd_screen_param_struct param;
                    param.type = VAPP_CAMCO_OSD_SCR_PARAM_CAM_THUMBNAIL_UPDATE;
                    param.previousFileName = g_vapp_camco_last_file_name;
                    obj->m_OSD->setScreenParam(param);
                }
                else if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
                {
                    vapp_camco_osd_screen_param_struct param;
                    param.type = VAPP_CAMCO_OSD_SCR_PARAM_REC_THUMBNAIL_UPDATE;
                    param.previousFileName = g_vapp_camco_last_file_name;
                    obj->m_OSD->setScreenParam(param);
                }
            }
            break;
        }
    }
    return MMI_RET_OK;
}

mmi_ret VappCamcoPage::fontChangeNotigyHdlr(mmi_event_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_FONT_EVENT);

    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    VappCamcoPage* obj = (VappCamcoPage *)param->user_data;

    if(obj == NULL)
        return MMI_RET_OK;

    if(obj->m_isStartingApp)
        return MMI_RET_OK;


    if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER &&
       (obj->m_state == VAPP_CAMCO_STATE_REC_RECORDING || obj->m_state == VAPP_CAMCO_STATE_REC_PAUSE || obj->m_state == VAPP_CAMCO_STATE_REC_SAVING))
    {
        obj->m_isFontChanged = VFX_TRUE;
    }
    return MMI_RET_OK;
}

mmi_ret VappCamcoPage::storageChangeNotifyHdlr(mmi_event_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_STORAGE_EVENT);

    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    VappCamcoPage* obj = (VappCamcoPage *)param->user_data;

    if(obj == NULL)
        return MMI_RET_OK;

    if(obj->m_isStartingApp)
        return MMI_RET_OK;

    switch(param->evt_id)
    {

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct* event = (srv_fmgr_notification_dev_plug_event_struct*)param;
            U8 drive = obj->m_Setting->getStorage();

            for (VfxU8 i = 0; i < event->count; i++)
            {
                if (event->drv_letters[i] == drive)
                {
                    ((StorageSetting*)(obj->m_Setting->getSetting(VAPP_CAMCO_SETTING_CAMSTORAGE)))->setDefault();
                    ((StorageSetting*)(obj->m_Setting->getSetting(VAPP_CAMCO_SETTING_VDOSTORAGE)))->setDefault();
                    if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA && obj->m_state == VAPP_CAMCO_STATE_CAM_PREVIEW)
                        obj->enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
                    else if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER && obj->m_state == VAPP_CAMCO_STATE_REC_PREVIEW)
                        obj->enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
                    else if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER && (obj->m_state == VAPP_CAMCO_STATE_REC_RECORDING || obj->m_state == VAPP_CAMCO_STATE_REC_PAUSE))
                        obj->enterState(VAPP_CAMCO_STATE_REC_SAVING);
                    return MMI_RET_OK;
                }
            }
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            srv_fmgr_notification_dev_plug_event_struct* event = (srv_fmgr_notification_dev_plug_event_struct*)param;
            U8 drive = obj->m_Setting->getStorage();

            for (VfxU8 i = 0; i < event->count; i++)
            {
                if (event->drv_letters[i] == drive)
                {
                    ((StorageSetting*)(obj->m_Setting->getSetting(VAPP_CAMCO_SETTING_CAMSTORAGE)))->setDefault();
                    ((StorageSetting*)(obj->m_Setting->getSetting(VAPP_CAMCO_SETTING_VDOSTORAGE)))->setDefault();
                    if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA && obj->m_state == VAPP_CAMCO_STATE_CAM_PREVIEW)
                        obj->enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
                    else if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER && obj->m_state == VAPP_CAMCO_STATE_REC_PREVIEW)
                        obj->enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
                    return MMI_RET_OK;
                }
            }
            break;
        }
    }
    return MMI_RET_OK;
}

mmi_ret VappCamcoPage::USBChangeNotigyHdlr(mmi_event_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_USB_EVENT);

    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    VappCamcoPage* obj = (VappCamcoPage *)param->user_data;

    if(obj == NULL)
        return MMI_RET_OK;

    if(obj->m_isStartingApp)
        return MMI_RET_OK;

    if(obj->m_isExtCalling)
    {
        vcui_camco_event_struct evt;

        MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_CAMCO_EVENT_RESULT_FAILED,  obj->getApp()->getGroupId());
        evt.filePath = NULL;
        VfxCui *app = VFX_OBJ_DYNAMIC_CAST(obj->getApp(), VfxCui);
        app->postToCaller((mmi_group_event_struct*)&evt);

    }
    else
    {
        VappCamcoApp *app = VFX_OBJ_DYNAMIC_CAST(obj->getApp(), VappCamcoApp);
        app->exit();
    }
    return MMI_RET_OK;

}

void VappCamcoPage::getStartingFilenameIdx(void)
{
    VfxS16 error = 0;

    ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &m_camStartingFilenameIdx, DS_SHORT, &error);
    ReadValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &m_recStartingFilenameIdx, DS_SHORT, &error);
}

void VappCamcoPage::setStartingFilenameIdx(void)
{
    VfxS16 error = 0;

    WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &m_camStartingFilenameIdx, DS_SHORT, &error);
    WriteValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &m_recStartingFilenameIdx, DS_SHORT, &error);
}

VfxBool VappCamcoPage::getNextFilename(WCHAR* fileBuf)
{
#define CAMCO_TEMP_BUFFER_LENGTH    (50)
#define CAMCO_MAX_FILE_NUM          (20000)

    CHAR buffer[CAMCO_TEMP_BUFFER_LENGTH];
    WCHAR *storageBuffer;
    WCHAR wcsBuffer[CAMCO_TEMP_BUFFER_LENGTH];
    WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH];
    VfxU16 filename_seq_no;
    VfxU16 start_no;
    FS_HANDLE file_handle;
    VfxU32 startTicks, endTicks;

    kal_get_time(&startTicks);

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        /* get/store sequentail number */
        filename_seq_no = m_camStartingFilenameIdx;
        if (filename_seq_no == 0xffff)
        {
            filename_seq_no = 1;    /* init value */
        }
        else
        {
            filename_seq_no++;

            if (filename_seq_no > 20000)    /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
        }
        start_no = filename_seq_no;
        m_Setting->getStoragePath(&storageBuffer);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GETNEXTFILENAME, filename_seq_no);

        do
        {
            sprintf((CHAR *) buffer, "IMG%05d", filename_seq_no);
            mmi_asc_to_wcs(wcsBuffer, buffer);

            mmi_wcscpy(wcsTestname, wcsBuffer);
            mmi_wcscat(wcsTestname, (const WCHAR *) L".jpg");

            mmi_wcscpy(fileBuf, storageBuffer);
            mmi_wcscat(fileBuf, wcsTestname);

            file_handle = FS_GetAttributes((U16*) fileBuf);
            if (file_handle < 0)
            {
                /* file not exist */
                m_camStartingFilenameIdx = filename_seq_no;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GETNEXTFILENAME, -1);
                return VFX_TRUE;
            }

            filename_seq_no++;
            if (filename_seq_no > 20000)    /* more than 4 digits */
            {
                filename_seq_no = 1;
            }

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GETNEXTFILENAME, filename_seq_no);
            if(start_no == filename_seq_no)
                return VFX_FALSE;

            // prevent MMI from taking too long time on finding the next file name
            kal_get_time(&endTicks);
            if((endTicks - startTicks) * 4.615  > 3000)
            {
                m_camStartingFilenameIdx = filename_seq_no;
                return VFX_FALSE;
            }
        }while(1);

    }
    else
    {
        /* get/store sequentail number */
        filename_seq_no = m_recStartingFilenameIdx;
        if (filename_seq_no == 0xffff)
        {
            filename_seq_no = 1;    /* init value */
        }
        else
        {
            filename_seq_no++;

            if (filename_seq_no > 20000)    /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
        }
        start_no = filename_seq_no;
        m_Setting->getStoragePath(&storageBuffer);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GETNEXTFILENAME, filename_seq_no);
        do
        {
            sprintf((CHAR *) buffer, "VDO%05d", filename_seq_no);
            mmi_asc_to_wcs(wcsBuffer, (CHAR *) buffer);

            mmi_wcscpy(wcsTestname, wcsBuffer);
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_VISCODEC) == VAPP_CAMCO_VISCODEC_MJPG)
            {
                mmi_wcscat(wcsTestname, (const WCHAR *) L".avi");
            }
            else
            {
                mmi_wcscat(wcsTestname, (const WCHAR *) L".3gp");
            }
            mmi_wcscpy(fileBuf, storageBuffer);
            mmi_wcscat(fileBuf, wcsTestname);

            file_handle = FS_GetAttributes((U16*) fileBuf);
            if (file_handle < 0)
            {
                /* file not exist */
                m_recStartingFilenameIdx = filename_seq_no;
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GETNEXTFILENAME, -1);
                return VFX_TRUE;
            }

            filename_seq_no++;
            if (filename_seq_no > 20000)    /* more than 4 digits */
            {
                filename_seq_no = 1;
            }

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_GETNEXTFILENAME, filename_seq_no);
            if(start_no == filename_seq_no)
                return VFX_FALSE;

            // prevent MMI from taking too long time on finding the next file name
            kal_get_time(&endTicks);
            if((endTicks - startTicks) * 4.615  > 3000)
            {
                m_recStartingFilenameIdx = filename_seq_no;
                return VFX_FALSE;
            }
        }while(1);
    }

}

void VappCamcoPage::restoreFilename(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESTOREFILENAME, 0);

    VfxU16 filename_seq_no;

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        filename_seq_no = m_camStartingFilenameIdx;

        if (filename_seq_no == 1)
        {
            filename_seq_no = 20000;
        }
        else
        {
            filename_seq_no--;
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESTOREFILENAME, filename_seq_no);
        m_camStartingFilenameIdx = filename_seq_no;
    }
    else
    {
        filename_seq_no = m_recStartingFilenameIdx;

        if (filename_seq_no == 1)
        {
            filename_seq_no = 20000;
        }
        else
        {
            filename_seq_no--;
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_RESTOREFILENAME, filename_seq_no);
        m_recStartingFilenameIdx = filename_seq_no;
    }
}

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
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

static double vapp_camco_get_julian_day(MYTIME *p)
{
    kal_int32 Y, M, D, A, B, X1, X2;
    double rJD;

    Y = p->nYear;
    M = p->nMonth;
    D = p->nDay;

    if (M <= 2)
    {
        Y--;
        M += 12;
    }

    A = Y / 100;
    B = 2 - A + (A / 4);
    X1 = (kal_int32)(365.25 * (Y + 4716));
    X2 = (kal_int32)(30.6001 * (M + 1));
    rJD = X1 + X2 + D + B - 1524.5;
    rJD += (p->nHour * 3600.0 + p->nMin * 60.0 + p->nSec) / 86400.0;

    return rJD;
}

mmi_ret storageChangeNotifyHdlr(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {

    #ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:

            srv_fmgr_notification_set_def_storage_event_struct *storage_evt = (srv_fmgr_notification_set_def_storage_event_struct*)evt;

            if(storage_evt->state ==SRV_FMGR_NOTIFICATION_STATE_AFTER )
            {
                g_vapp_camco_config.defaultDrv = (VfxU32)storage_evt->drv_letter;
                g_vapp_camco_config.isSetDefaultStorage = VFX_TRUE;
            }
            return MMI_RET_OK;
            break;
    #endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */
    }
    return MMI_RET_OK;
}

// ==========================================================================================
// App
// ==========================================================================================
extern "C" mmi_id vapp_camco_launch_app(void)
{
    vcui_camco_param_struct param;

    param.mode = VCUI_CAMCO_FULL;
    param.level = VCUI_CAMCO_SETTING_FULL;
    param.settingLimitNum = 0;
    param.settingLimitation = NULL;

    //VappCamcoCntx.currentAppID =
    return  VfxAppLauncher::launch(
                VAPP_CAMCO,
                VFX_OBJ_CLASS_INFO(VappCamcoApp),
                GRP_ID_ROOT,
                &param,
                sizeof(vcui_camco_param_struct));

}

extern "C" MMI_ID vapp_camco_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = 0;

    if (param == NULL && param_size == 0)
    {
        app_id = vapp_camco_launch_app();
    }
    else
    {
        switch (param->cat)
        {
        case MMI_LAUNCH_APP_IN_OPEN_CATEGORY:
            app_id = vapp_camco_launch_app();
            break;
        default:
            break;
        }
    }
    return app_id;
}

extern "C" mmi_ret vapp_camco_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

mmi_ret vapp_camco_pre_key_hdlr(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
		case EVT_ID_PRE_KEY_EVT_ROUTING:
		{
			VfxKeyEvent vEvt;
			mmi_frm_key_evt_struct *pEvt = (mmi_frm_key_evt_struct*)event;

			vEvt.keyCode = (VfxKeyCodeEnum)pEvt->key_code;
			vEvt.type = (VfxKeyEventTypeEnum)pEvt->key_type;

            if(vEvt.keyCode == VFX_KEY_CODE_CAMERA)
            {
                if(vEvt.type == VFX_KEY_EVENT_TYPE_FULL_PRESS_DOWN)
                {
                    VfxApp *app1 = (VappCamcoApp*)VfxAppLauncher::findApp(VAPP_CAMCO, VFX_OBJ_CLASS_INFO(VappCamcoApp), VFX_APP_LAUNACHER_FIND_APP_BG_FLAG|VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);
                    VfxApp *app2 = (VcuiStandardCameraApp*)VfxAppLauncher::findApp(VCUI_STANDARD_CAMERA, VFX_OBJ_CLASS_INFO(VcuiStandardCameraApp), VFX_APP_LAUNACHER_FIND_APP_BG_FLAG|VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);
                    VfxApp *app3 = (VcuiStandardRecorderApp*)VfxAppLauncher::findApp(VCUI_STANDARD_RECORDER, VFX_OBJ_CLASS_INFO(VcuiStandardRecorderApp), VFX_APP_LAUNACHER_FIND_APP_BG_FLAG|VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);
                    VfxApp *app4 = (VcuiSlimCameraApp*)VfxAppLauncher::findApp(VCUI_SLIM_CAMERA, VFX_OBJ_CLASS_INFO(VcuiSlimCameraApp), VFX_APP_LAUNACHER_FIND_APP_BG_FLAG|VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);
                    if(!app1 && !app2 && !app3 && !app4 && vapp_launcher_is_active())
                    {
                        vapp_camco_launch_app();
                    }
                }
            }
    		break;
		}
        default:
            break;
    }
    return MMI_RET_OK;
}

// ==========================================================================================
// Standard Camera CUI
// ==========================================================================================
extern "C" void vcui_standard_camera_struct_init(vcui_camco_param_struct *param)
{
    g_vapp_camco_limit.type = VCUI_CAMCO_SETTING_LIMIT_CAPSIZE;
    g_vapp_camco_limit.detail = VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_WP_ONLY;

    param->mode = VCUI_CAMCO_CAMERA;
    param->level = VCUI_CAMCO_SETTING_COMMON_ONLY;
    param->settingLimitNum = 1;
    param->settingLimitation = &g_vapp_camco_limit;
}

extern "C" mmi_id vcui_standard_camera_create(mmi_id parent_id, vcui_camco_param_struct *param)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
        VCUI_STANDARD_CAMERA,                      /* Cui's app id */
        VFX_OBJ_CLASS_INFO(VcuiStandardCameraApp), /* Cui class */
        parent_id,                                 /* parent group id */
        param,                                     /* parameters, if any */
        sizeof(vcui_camco_param_struct));

    return cui_id;
}

extern "C" void vcui_standard_camera_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

extern "C" void vcui_standard_camera_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

extern "C" vcui_camco_err_code_enum vcui_standard_camera_launchable_check(void)
{
    VfxBool ret;

    ret = VappCamcoPage::checkEnv();
    VappCamcoPage::decheckEnv();

    if(!ret)
    {
        return VCUI_CAMCO_ERR_MISC;
    }
    else
    {
        return VCUI_CAMCO_ERR_NONE;
    }
}

extern "C" MMI_ID vcui_standard_camera_get_err_string(vcui_camco_err_code_enum errCode)
{
    return VappCamcoPage::m_errStr;
}

// ==========================================================================================
// Standard Recorder CUI
// ==========================================================================================
extern "C" void vcui_standard_recorder_struct_init(vcui_camco_param_struct *param)
{
    g_vapp_camco_rec_limit[0].type = VCUI_CAMCO_SETTING_LIMIT_RECLIMIT;
    g_vapp_camco_rec_limit[0].detail = VCUI_CAMCO_SETTING_LIMIT_RECLIMIT_SIZE;
    g_vapp_camco_rec_limit[0].additionalInfo = 5 * 1024;
    g_vapp_camco_rec_limit[1].type = VCUI_CAMCO_SETTING_LIMIT_RECSIZE;
    g_vapp_camco_rec_limit[1].detail = VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_QCIF;
    g_vapp_camco_rec_limit[2].type = VCUI_CAMCO_SETTING_LIMIT_RECQTY;
    g_vapp_camco_rec_limit[2].detail = VCUI_CAMCO_SETTING_LIMIT_RECQTY_MMS_QTY;

    param->mode = VCUI_CAMCO_RECORDER;
    param->level = VCUI_CAMCO_SETTING_COMMON_ONLY;
    param->settingLimitNum = 3;
    param->settingLimitation = g_vapp_camco_rec_limit;

}

extern "C" void vcui_standard_recorder_recsize(VfxU32 limit)
{
    g_vapp_camco_rec_limit[0].additionalInfo = limit;
}

extern "C" mmi_id vcui_standard_recorder_create(mmi_id parent_id, vcui_camco_param_struct *param)
{

    mmi_id cui_id = VfxAppLauncher::createCui(
        VCUI_STANDARD_RECORDER,                      /* Cui's app id */
        VFX_OBJ_CLASS_INFO(VcuiStandardRecorderApp), /* Cui class */
        parent_id,                                 /* parent group id */
        param,                                     /* parameters, if any */
        sizeof(vcui_camco_param_struct));

    return cui_id;
}

extern "C" void vcui_standard_recorder_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

extern "C" void vcui_standard_recorder_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

extern "C" vcui_camco_err_code_enum vcui_standard_recorder_launchable_check(void)
{
    VfxBool ret;

    ret = VappCamcoPage::checkEnv();
    VappCamcoPage::decheckEnv();

    if(!ret)
    {
        return VCUI_CAMCO_ERR_MISC;
    }
    else
    {
        return VCUI_CAMCO_ERR_NONE;
    }
}

extern "C" MMI_ID vcui_standard_recorder_get_err_string(vcui_camco_err_code_enum errCode)
{
    return VappCamcoPage::m_errStr;
}

// ==========================================================================================
// Slim Camera CUI
// ==========================================================================================
extern "C" void vcui_slim_camera_struct_init(vcui_camco_param_struct *param)
{
    g_vapp_camco_limit.type = VCUI_CAMCO_SETTING_LIMIT_CAPSIZE;
    g_vapp_camco_limit.detail = VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_VGA;

    param->mode = VCUI_CAMCO_CAMERA;
    param->level = VCUI_CAMCO_SETTING_COMMON_ONLY;
    param->settingLimitNum = 1;
    param->settingLimitation = &g_vapp_camco_limit;

}

extern "C" mmi_id vcui_slim_camera_create(mmi_id parent_id, vcui_camco_param_struct *param)
{

    mmi_id cui_id = VfxAppLauncher::createCui(
        VCUI_SLIM_CAMERA,                          /* Cui's app id */
        VFX_OBJ_CLASS_INFO(VcuiSlimCameraApp),     /* Cui class */
        parent_id,                                 /* parent group id */
        param,                                     /* parameters, if any */
        sizeof(vcui_camco_param_struct));

    return cui_id;
}

extern "C" void vcui_slim_camera_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

extern "C" void vcui_slim_camera_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

extern "C" vcui_camco_err_code_enum vcui_slim_camera_launchable_check(void)
{
    VfxBool ret;

    ret = VappCamcoPage::checkEnv();
    VappCamcoPage::decheckEnv();

    if(!ret)
    {
        return VCUI_CAMCO_ERR_MISC;
    }
    else
    {
        return VCUI_CAMCO_ERR_NONE;
    }
}

extern "C" MMI_ID vcui_slim_camera_get_err_string(vcui_camco_err_code_enum errCode)
{
    return VappCamcoPage::m_errStr;
}

// ==========================================================================================
// dummp interface for otehrs APP, remove after FTO camcorder create new interface
// ==========================================================================================

void vapp_camco_cam_get_max_capture_resolution(VfxS32 *width_p, VfxS32 *height_p)
{
#ifdef __MMI_CAMCO_FEATURE_CAM_IMGSZIE_SUPPORT_5M__
    *width_p = 2592;
    *height_p = 1944;
#else
    *width_p = 2048;
    *height_p = 1536;
#endif
}

VfxU32 vapp_camco_rec_get_min_external_request_size(void)
{
#ifdef MJPG_ENCODE
    return 60;
#else
    return 30;
#endif
}

VfxU16 vapp_camco_setting_get_banding(void)
{
    if (g_vapp_camco_banding_setting == 0)
    {
        return MDI_CAMERA_BANDING_50HZ;
    }
    else
    {
        return MDI_CAMERA_BANDING_60HZ;
    }
}

extern "C" mmi_ret vapp_camco_init(mmi_event_struct *event)
{
    // init rec custom config setting
    custom_rec_set_table();

    return MMI_RET_OK;
}

#endif /*__VAPP_CAMCO_EXPRESS__*/
