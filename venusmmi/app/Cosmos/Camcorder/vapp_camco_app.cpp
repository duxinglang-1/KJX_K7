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

#include "lcd_sw_inc.h" /* for LCD size */
//#include "Gui_SettingPLUTO.h"

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

#include "custom_rec_config.h"

// for backlight
#include "gpiosrvprot.h"

// for power off
#include "ShutdownSrvGprot.h"

// for check if in HS/main menu
#include "Vapp_launcher_gprot.h"

#ifdef __cplusplus
}
#endif

#ifdef __VAPP_CAMCO__

#include "AppMgrSrvGprot.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_camco_gprot.h"
#include "vapp_camco_app.h"
#include "vapp_camco_hw.h"
#include "vapp_camco_osd_mgr.h"
#include "vapp_camco_osd_state.h"

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

extern vapp_camco_banding_enum g_vapp_camco_banding_setting;

MMI_ID VappCamcoPage::m_errStr = 0;

// for global setting 
vapp_camco_global_config_struct g_vapp_camco_config;

// for save previous captured pciture name
WCHAR g_vapp_camco_cam_prev_file_name[256];
WCHAR g_vapp_camco_cam_hdr_prev_file_name[256];
WCHAR g_vapp_camco_rec_prev_file_name[256];

// for saving CUI setting
vcui_camco_setting_limit_struct g_vapp_camco_limit;
vcui_camco_setting_limit_struct g_vapp_camco_rec_limit[5];

// for keep previous capsize / camera id  to show the correct first screen rotation
VfxS16 g_vapp_camco_previous_rot = -1; //default is Horz size

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
    setIsCustomRotate(VFX_TRUE);
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

void VappCamcoPage::onAFTimerTick(VfxTimer *source)
{
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
#ifndef __MTK_TARGET__

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        vapp_camco_hw_result_callback_param_struct param;

        if(m_af_i%2 == 0)
        {
            param.type = VAPP_CAMCO_CB_TYPE_CAM_AF;
            param.afRet.af_result = MDI_AF_SEARCH_STATUS_FOUND_FAIL;
        }
        else
        {
            param.type = VAPP_CAMCO_CB_TYPE_CAM_AF;
            param.afRet.af_result = MDI_AF_SEARCH_STATUS_FOUND_SUCCESS;    
            param.afRet.af_success_zone = 1;            
        }
        resultHWCallback(param);        
    }
    else
    {
        vapp_camco_hw_result_callback_param_struct param;
    
        if(m_af_i%2 == 0)
        {
            param.type = VAPP_CAMCO_CB_TYPE_REC_AF;
            param.afRet.af_result = MDI_AF_SEARCH_STATUS_FOUND_FAIL;
        }
        else
        {
            param.type = VAPP_CAMCO_CB_TYPE_REC_AF;
            param.afRet.af_result = MDI_AF_SEARCH_STATUS_FOUND_SUCCESS;    
            param.afRet.af_success_zone = 1;            
        }
        resultHWCallback(param);        
    }
  
    m_af_i++;
    source->start();    
#endif 
#endif  
}

void VappCamcoPage::onSaveTimerTick(VfxTimer *source)
{
#ifndef __MTK_TARGET__
    vapp_camco_hw_result_callback_param_struct param;

    param.type = VAPP_CAMCO_CB_TYPE_RECORD_SAVE;
    param.recordRet = MDI_RES_VDOREC_SUCCEED;
            
    resultHWCallback(param);   
#endif  
}

void VappCamcoPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_INIT);

    VfxPage::onInit(); 

    setAutoAnimate(VFX_FALSE);

    VFX_OBJ_CREATE(m_previewFrame,VfxVideoFrame,this);       

#ifdef VAPP_CAMCO_MODIS_PIC_PREVIEW
    VFX_OBJ_CREATE(m_picturePreviewFrame,VfxFrame,this); 
    m_picturePreviewFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    m_picturePreviewFrame->setAnchor(0, 0);
    m_picturePreviewFrame->setPos(0, 0);    
    m_picturePreviewFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    WCHAR fileName[30];
    CHAR fileNameAsc[15] = "";
    
    sprintf(fileNameAsc, "%c:\\4.bmp", SRV_FMGR_CARD_DRV);    
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
    m_dummyRestartPreviewCallback = VappCamcoRestartCallbackFunc(this, &VappCamcoPage::dummyRestartPreview); 

    setStatusBar(VFX_FALSE);  


    VFX_OBJ_CREATE(m_autoExitTimer, VfxTimer, this);    

    VFX_OBJ_CREATE(m_errorExitTimer, VfxTimer, this);   
    m_errorExitTimer->setStartDelay(1500);    
    m_errorExitTimer->m_signalTick.connect(this, &VappCamcoPage::onErrorExitTimerTick);

    VFX_OBJ_CREATE(m_postEnterTimer, VfxTimer, this);      
    m_postEnterTimer->setStartDelay(1);       
    m_postEnterTimer->m_signalTick.connect(this, &VappCamcoPage::onEntered); 

    VFX_OBJ_CREATE(m_delayPreviewTimer, VfxTimer, this);      
    m_delayPreviewTimer->setStartDelay(250);       
    m_delayPreviewTimer->m_signalTick.connect(this, &VappCamcoPage::onPreviewFrameDoneDelayTick); 

    // init countdown
    VFX_OBJ_CREATE(countdownLedTimer, VfxTimer, this);    
    countdownLedTimer->setStartDelay(100);      
    countdownLedTimer->m_signalTick.connect(this, &VappCamcoPage::countdownLedTurnOff);    

    VFX_OBJ_CREATE(countdownCycTimer, VfxTimer, this);                
    countdownCycTimer->m_signalTick.connect(this, &VappCamcoPage::countdownCyclic); 

    // smile detect    
    VFX_OBJ_CREATE(m_smileDetectCycTimer, VfxTimer, this);      
    m_smileDetectCycTimer->setStartDelay(50);       
    m_smileDetectCycTimer->m_signalTick.connect(this, &VappCamcoPage::smiledetectCyclic); 

    VFX_OBJ_CREATE(m_smileDetectSuccessTimer, VfxTimer, this);      
    m_smileDetectSuccessTimer->setStartDelay(10);       
    m_smileDetectSuccessTimer->m_signalTick.connect(this, &VappCamcoPage::smiledetectSuccess); 

    // scene detect
    VFX_OBJ_CREATE(m_sceneDetectCycTimer, VfxTimer, this);      
    m_sceneDetectCycTimer->setStartDelay(50);       
    m_sceneDetectCycTimer->m_signalTick.connect(this, &VappCamcoPage::sceneDetectCyclic);     
    
        
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
    m_hwFlag.isHightlightOn     =   VFX_FALSE; 
    m_hwFlag.isHDRing           =   VFX_FALSE;     
    m_hwFlag.isCalBgProcessOn   =   VFX_TRUE;     
    
    m_isOnForceHorz             =   VFX_FALSE;

    m_isPreemptable             =   VFX_TRUE;    
    m_isExtCalling              =   VFX_FALSE; 
    m_isMainLcdPreview          =   VFX_TRUE;    
    m_isFirstEnterPreview       =   VFX_FALSE;    
    m_isDelayPreview            =   VFX_FALSE;
    m_isStartingPreview         =   VFX_FALSE; 
    m_isSaveBeforeLeave         =   VFX_FALSE; 

    m_isTonePlaying             =   VFX_FALSE; 
    m_isAFTonePlaying           =   VFX_FALSE; 

    m_isAppInited               =   VFX_FALSE;
    m_isStartingApp             =   VFX_TRUE;

    m_isFontChanged             =   VFX_FALSE;
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
    mmi_frm_cb_reg_event(EVT_ID_ORIENTATION_CHANGED, sensorChangeNotifyHdlr, this);
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)    
    mmi_frm_cb_reg_event(EVT_ID_VAPP_FONT_CHANGED, fontChangeNotigyHdlr, this);
#endif

    // UT on MOIDS
    m_af_i = 0;
    m_smile_i = 0;   
    m_contshot_i = 0;
}

void VappCamcoPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_DEINIT);

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
    mmi_frm_cb_dereg_event(EVT_ID_ORIENTATION_CHANGED, sensorChangeNotifyHdlr, this);
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
        vappCamcoPopupParamStruct param;
        param.next_state = VAPP_CAMCO_STATE_EXIT;
        exitCamcoCUI(param);
    }
    enterState(VAPP_CAMCO_STATE_EXIT);

    deinitEnv();

    // store the name to file for the next bootup
    #define CAMCO_TEMP_BUFFER_LENGTH    (256)
    FS_HANDLE file_handle;

    if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_SYSTEM_DRV, FS_MOUNT_STATE_ENUM))
    {
        WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH];
        WCHAR drv_buf[8];
        CHAR buf[64];

        sprintf((CHAR *)buf, "%c:\\", (U8)SRV_FMGR_SYSTEM_DRV);
        mmi_asc_to_wcs(drv_buf, (CHAR *)buf);

        mmi_wcscpy(wcsTestname, drv_buf);
        mmi_wcscat(wcsTestname, (const WCHAR *) L"cameraData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_CREATE_ALWAYS | FS_READ_WRITE);

        if (file_handle >= 0)
        {
            U32 write_size;

            if (FS_Write(file_handle, (CHAR*)g_vapp_camco_cam_prev_file_name, 256*2, &write_size) >= 0)
            {
                ASSERT(write_size == 256*2);
            }
        }
        FS_Close(file_handle);
        
        mmi_wcscpy(wcsTestname, drv_buf);
        mmi_wcscat(wcsTestname, (const WCHAR *) L"recorderData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_CREATE_ALWAYS);

        if (file_handle >= 0)
        {
            U32 write_size;

            if (FS_Write(file_handle, (CHAR*)g_vapp_camco_rec_prev_file_name, 256*2, &write_size) >= 0)
            {
                ASSERT(write_size == 256*2);
            }
        }
        FS_Close(file_handle);        
    }
    
    VfxPage::onDeinit(); 

}

VfxBool VappCamcoPage::isHorzUI(void)
{
    // for show the first scree usage
    if(m_isStartingApp)
    {	 
        if(m_state == VAPP_CAMCO_STATE_ENTER_FAIL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 1000);          
            return VFX_TRUE;    
        }
        
    #if defined (HORIZONTAL_CAMERA)
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 1001);  	
        if(m_param.mode == VCUI_CAMCO_FULL)
        {   
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 1002); 
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, g_vapp_camco_previous_rot); 			
            if(g_vapp_camco_previous_rot == VAPP_CAMCO_CAPSIZE_WALLPAPER)
                return VFX_FALSE;
            else
                return VFX_TRUE;            
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 1003);         
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, m_param.mode);   			
            if(m_param.mode == VCUI_CAMCO_RECORDER)
            {
                return VFX_TRUE;
            }
            else
            {
                for(VfxU8 i = 0; i < m_param.settingLimitNum; i++)
                {
                    if(m_param.settingLimitation[i].type == VCUI_CAMCO_SETTING_LIMIT_CAPSIZE &&
                       m_param.settingLimitation[i].detail == VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_WP_ONLY)
                    {
                        return VFX_FALSE;
                    }
                }       
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 1004);      				
                return VFX_TRUE;				
            }
        }            
    #else 
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 2001); 	
        return VFX_FALSE;        
    #endif
	}

#if defined (HORIZONTAL_CAMERA)
    if(m_isOnForceHorz)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 1);          
        return VFX_TRUE;    
    }
    else if(m_state == VAPP_CAMCO_STATE_ENTER_FAIL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 2);          
        return VFX_TRUE;    
    }
    else if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        if((m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA && m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER) ||
           (m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER && m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, -1);        
            return VFX_FALSE;            
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 3);        
            return VFX_TRUE;
        }
    }
    else if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, -2);     
        return VFX_FALSE;
    }
    else 
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, -1);     
        return VFX_FALSE;
    }
#else      
    if(m_isOnForceHorz)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 1);          
        return VFX_TRUE;    
    }
    else if(m_state == VAPP_CAMCO_STATE_ENTER_FAIL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, 2);          
        return VFX_TRUE;    
    }
    else 
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_HZUI, -1);     
        return VFX_FALSE;
    }
#endif

}

void VappCamcoPage::onErrorExitTimerTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_ERROR_EXIT_TIMER_TICK); 
    getApp()->exit();
}

void VappCamcoPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if(isHorzUI())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CMACO_ON_QUERY_ROTATE, 270);     
        param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CMACO_ON_QUERY_ROTATE, 0);         
        param.rotateTo = VFX_SCR_ROTATE_TYPE_0;
    }
}


void VappCamcoPage::setCallingParam(vcui_camco_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SET_CALLINGPARAM, m_param.mode);

    m_param = param;
    
}


void VappCamcoPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_EXIT, isBackward);

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

    // there should be keep any change for preview rotate when back to AP
    // default enter a normal prview screen
    m_isOnForceHorz = VFX_FALSE;
    
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
        case VAPP_CAMCO_STATE_CAM_SMILE_DECT:
        case VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED:
        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
        case VAPP_CAMCO_STATE_CAM_FOCUSING:
        case VAPP_CAMCO_STATE_CAM_FOCUSED:
        case VAPP_CAMCO_STATE_CAM_CAPTURE:
        case VAPP_CAMCO_STATE_CAM_CONTSHOT:
        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
        case VAPP_CAMCO_STATE_CAM_BURSTSHOT:
        case VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT:
        case VAPP_CAMCO_STATE_CAM_AEBSHOT:
        case VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT:
        case VAPP_CAMCO_STATE_CAM_HDR_SHOT:
        case VAPP_CAMCO_STATE_CAM_HDR_DONE:
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

    // reset bg calculation when leave App
    vapp_camco_background_calculation_start(&m_cam_bg_process_param);    

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        vapp_camco_cam_power_off(&m_cam_power_off_param);
    else
        vapp_camco_rec_power_off(&m_rec_power_off_param);

    if (m_hwFlag.isHightlightOn)
    {
        vapp_camco_highlight_turn_off(&m_general_param);
        m_Setting->setValue(VAPP_CAMCO_SETTING_HIGHLIGHT, VAPP_CAMCO_HIGHLIGHT_OFF);
    }

    m_Setting->storeSetting();
    m_Setting->storeSceneSetting(); 

    if(m_camFileNameBuf && m_recFileNameBuf)
    {
        mmi_wcscpy(g_vapp_camco_cam_prev_file_name, m_camFileNameBuf);
        mmi_wcscpy(g_vapp_camco_rec_prev_file_name, m_recFileNameBuf);
    }

    setStartingFilenameIdx();

    m_OSD->exitState();
    
    m_previewFrame->unPrepare();    
    m_delayPreviewTimer->stop();
    m_isStartingPreview = VFX_FALSE;
    m_isDelayPreview = VFX_FALSE;   
    m_isFontChanged = VFX_FALSE;

    ClearKeyEvents();

    decheckEnv();

    if(m_isExtCalling)
    {
        // ext calling need to free MMi memory when exit screen, canot wait for deinit
        m_Setting->setValue(VAPP_CAMCO_SETTING_HIGHLIGHT, VAPP_CAMCO_HIGHLIGHT_OFF);        
        if(m_camFileNameBuf && m_recFileNameBuf)
        {
            mmi_wcscpy(g_vapp_camco_cam_prev_file_name, m_camFileNameBuf); 
            mmi_wcscpy(g_vapp_camco_rec_prev_file_name, m_recFileNameBuf);         
        }
        resetMem();        
        m_state = VAPP_CAMCO_STATE_EXIT;
    }
   
    resetMem(); 

    if(!m_Setting->IsExtSetting())
    {
#if defined (HORIZONTAL_CAMERA)    
		MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_EXIT, 1001);
		MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_EXIT, m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE));
		MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_EXIT, m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE));		
        if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
        {
            if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                g_vapp_camco_previous_rot = (VfxU16)m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE);
            else
                g_vapp_camco_previous_rot = -1;
        }
        else
        {
            g_vapp_camco_previous_rot = -1;
        } 
		MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_EXIT, g_vapp_camco_previous_rot);		
#else	 
		MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_EXIT, 1002);
        g_vapp_camco_previous_rot = VAPP_CAMCO_CAPSIZE_WALLPAPER;    
#endif	  
    }

    VfxPage::onExit(isBackward); 

}

void VappCamcoPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_ENTER, isBackward);

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
        m_osd_starting_state_param.isHorz = isHorzUI();    
        switch (mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR))
        {
            case MMI_FRM_SCREEN_ROTATE_0:
                m_osd_starting_state_param.isOSDHorz= VFX_FALSE;
                m_osd_starting_state_param.isOSDMirror = VFX_FALSE; 
                break;
            case MMI_FRM_SCREEN_ROTATE_90:
                m_osd_starting_state_param.isOSDHorz = VFX_TRUE;
                m_osd_starting_state_param.isOSDMirror = VFX_TRUE;        
                break;
            case MMI_FRM_SCREEN_ROTATE_180:
                m_osd_starting_state_param.isOSDHorz = VFX_FALSE;
                m_osd_starting_state_param.isOSDMirror = VFX_TRUE;        
                break;
            case MMI_FRM_SCREEN_ROTATE_270:
                m_osd_starting_state_param.isOSDHorz = VFX_TRUE;
                m_osd_starting_state_param.isOSDMirror = VFX_FALSE;  
                break;
        }        
        
        m_enterScreenOSD->enterState(&m_osd_starting_state_param);

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


}

void VappCamcoPage::onEntered(VfxTimer *source) 
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_ENTER, 101);

    initApp();
    
    configMem();   

    mmi_wcscpy(m_camFileNameBuf, g_vapp_camco_cam_prev_file_name); 
    mmi_wcscpy(m_recFileNameBuf, g_vapp_camco_rec_prev_file_name); 

	m_enterScreenOSD->exitState();
    m_isStartingApp = VFX_FALSE;

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        if(vapp_camco_cam_power_on(&m_cam_power_on_param) == MDI_RES_CAMERA_SUCCEED)
        {
            // when the 1st power on and enter App
            // the rotation may be wrong (because we think it will be Horz)
            if(g_vapp_camco_previous_rot == -1 && 
               (m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER || m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA))
            {
                VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();            
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);                    
            }        
            
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
            // when the 1st power on and enter App
            // the rotation may be wrong (because we think it will be Horz)
            if(g_vapp_camco_previous_rot == -1 && 
               (m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER || m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA))
            {
                VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();            
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);                    
            }
                    
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

}

void VappCamcoPage::exitState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXIT_STATE, m_state);   

    switch (m_state)
    {
        case VAPP_CAMCO_STATE_CAM_PREVIEW:
        case VAPP_CAMCO_STATE_CAM_SMILE_DECT:
            if(!m_hwFlag.isTakepicFailed)
            {
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);               
            }
            break;

        case VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED:
            break;


        case VAPP_CAMCO_STATE_CAM_FOCUSING:
        case VAPP_CAMCO_STATE_CAM_FOCUSED:
            if(!m_hwFlag.isTakepicFailed)
            {
                vapp_camco_cam_autofocus_stop(&m_autofocus_param);
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
            }
            break;

        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
            if(!m_hwFlag.isTakepicFailed)
            {
                countdownLedTimer->stop();   
                countdownCycTimer->stop();     
                countdownLedTurnOff(NULL);

                deinitCountDownSound();
                
                vapp_camco_cam_autofocus_stop(&m_autofocus_param);
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
            }

            break;

        case VAPP_CAMCO_STATE_CAM_CAPTURE:
            break;

        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
            break;

        case VAPP_CAMCO_STATE_CAM_CONTSHOT:

            vapp_camco_cam_autofocus_stop(&m_autofocus_param);
            vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);

            break;
            
        case VAPP_CAMCO_STATE_CAM_BURSTSHOT:
            if(!m_hwFlag.isBurstshotFinish)
            {
                vapp_camco_cam_burstshot_stop(NULL);
            }
            break;

        case VAPP_CAMCO_STATE_CAM_HDR_SHOT:
        {
            if(m_hwFlag.isHDRing)
            {            
                MDI_RESULT ret = vapp_camco_cam_hdr_shot_stop(&m_cam_hdr_shot_param);   
                restoreFilename();

                // if stop succes, the last picture should be HDR pre-processing picture
                if(ret == MDI_RES_CAMERA_SUCCEED)
                {
                    mmi_wcscpy(m_camFileNameBuf, m_camSlaveFileNameBuf);             
                    mmi_wcscpy(g_vapp_camco_cam_prev_file_name, m_camSlaveFileNameBuf);                             
                }   
                else
                {
                    mmi_wcscpy(m_camFileNameBuf, g_vapp_camco_cam_hdr_prev_file_name);             
                    mmi_wcscpy(g_vapp_camco_cam_prev_file_name, g_vapp_camco_cam_hdr_prev_file_name);                             
                }                                   
            }
            break;            
        }        
        case VAPP_CAMCO_STATE_CAM_HDR_DONE:
            break;
            
        case VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT:
            break;

        case VAPP_CAMCO_STATE_CAM_AEBSHOT:
            break;

        case VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT:
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

        case VAPP_CAMCO_STATE_REC_SAVING_PREV:
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_STATE, state);   

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
        vapp_camco_bk_turn_on();
    
    vapp_camco_cam_sd_stop(&m_cam_smiledetect_param);    


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

        case VAPP_CAMCO_STATE_CAM_FOCUSING:
            enterCamFocusingState();
            break;

        case VAPP_CAMCO_STATE_CAM_FOCUSED:
            enterCamFocusedState();
            break;

        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
            enterCamCountdownState();
            break;

        case VAPP_CAMCO_STATE_CAM_CAPTURE:
            enterCamCaptureState();
            break;

        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
            enterCamSaveDoneState();
            break;

        case VAPP_CAMCO_STATE_CAM_CONTSHOT:
            enterCamContshotState();
            break;

    #ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__
        case VAPP_CAMCO_STATE_CAM_BURSTSHOT:
            enterCamBurstshotState();
            break;

        case VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT:
            enterCamBurstshotSelectState();
            break;
    #endif /* __MMI_CAMCOFEATURE_Cam_BURSTSHOT_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__
        case VAPP_CAMCO_STATE_CAM_AEBSHOT:
            enterCamAebshotState();
            break;

        case VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT:
            enterCamAebshotSelectState();
            break;
    #endif /* __MMI_CAMCOFEATURE_Cam_AEBSHOT_SELECT__ */ 

    #ifdef __SMILE_SHUTTER_SUPPORT__
        case VAPP_CAMCO_STATE_CAM_SMILE_DECT:
            enterCamSmileDectState();
            break;
    #endif /* __SMILE_SHUTTER_SUPPORT__ */ /* __MMI_CAMCOFEATURE_ADDFRAME_COLOR_IDX__ */

    #ifdef __MMI_CAMCO_FEATURE_CAM_HDRSHOT__
        case VAPP_CAMCO_STATE_CAM_HDR_SHOT:
            enterCamHDRShotState();
            break;

        case VAPP_CAMCO_STATE_CAM_HDR_DONE:
            enterCamHDRDoneState();
            break;
    #endif

        case VAPP_CAMCO_STATE_REC_PREVIEW:
            enterRecPreviewState();
            break;

        case VAPP_CAMCO_STATE_REC_PREVIEW_FAILED:
            enterRecPreviewFailedState();
            break;

        case VAPP_CAMCO_STATE_REC_FOCUSING:
            enterRecFocusingState();
            break;

        case VAPP_CAMCO_STATE_REC_FOCUSED:
            enterRecFocusedState();
            break;

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
            MMI_ASSERT(0);
            break;

    }

}


void VappCamcoPage::recoverState(vapp_camco_state_enum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RECOVER_STATE, state, 0);   

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
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RECOVER_STATE, state, 1);  
                enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            }
            else if (m_hwFlag.isRecSaveCallback)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RECOVER_STATE, state, 2);  
                setState(VAPP_CAMCO_STATE_REC_SAVING);
                showPopupScreen(m_recordSaveResult, NULL, m_recoverStateCB);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RECOVER_STATE, state, 3);         
                setState(VAPP_CAMCO_STATE_REC_SAVING);
                m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_SAVING);
                m_osd_hint_state_param.isPreviewON = VFX_FALSE;
                m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
                m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
                m_osd_hint_state_param.isFWHorz = isHorzUI();
                m_osd_hint_state_param.isHorzUI = m_isOSDHorz;                
                m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;
                m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;                
                    
                m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);         
                m_OSD->updateScreen();      

            }
            break;            
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
    #endif
        default:
            //MMI_ASSERT(0);
            break;
    }

}    

VfxBool VappCamcoPage::checkEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_USB_NOTIFY, -1);

#if 0
#ifdef __MMI_BT_SUPPORT__
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
#endif

    if (isInCall() /*&& m_state == VAPP_CAMCO_STATE_EXIT*/)
    {

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_USB_NOTIFY, 1);    
        
        VappCamcoPage::m_errStr = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;

        return VFX_FALSE;
    }

#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {       
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_USB_NOTIFY, 2);          
        
        VcpPopupTypeEnum popupType;       
        VappCamcoPage::m_errStr = vapp_usb_get_error_info(0, &popupType);
        
        return VFX_FALSE;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    if(mdi_camera_set_camera_id(MDI_CAMERA_MAIN) != MDI_RES_CAMERA_SUCCEED)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_USB_NOTIFY, 3);

        VappCamcoPage::m_errStr = STR_ID_VAPP_CAMCO_NOTIFY_HW_NOT_READY;
        return VFX_FALSE;
    }

    return VFX_TRUE;
} 

VfxBool VappCamcoPage::decheckEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_DECHECKENV);          

#if 0
#ifdef __MMI_BT_SUPPORT__
/* under construction !*/
#endif
#endif
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

    VfxU32 appmem_size = 0;
    VfxU8* currentP;
    
    m_appMemQuickViewBuffer = NULL;    
    m_appMultiShotThumbnailsBuffer = NULL;
    m_appMedMultiShotWorkingBuffer = NULL;
    m_appAddFrameLayerBuffer = NULL;

    m_camFileNameBuf = (WCHAR*)gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    MMI_ASSERT(m_camFileNameBuf != NULL);
    memset(m_camFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);

    m_camSlaveFileNameBuf = (WCHAR*)gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    MMI_ASSERT(m_camSlaveFileNameBuf != NULL);
    memset(m_camSlaveFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);
        
    m_recFileNameBuf = (WCHAR*)gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    MMI_ASSERT(m_recFileNameBuf != NULL);
    memset(m_recFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);

    if (!m_isExtCalling)
    {
    #if defined(__MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__) || defined(__MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__)
        appmem_size =
            GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL * 2 +        
            MMI_CAMCO_CAM_CACHE_IMAGE_SIZE * MMI_CAMCO_CAM_CACHE_IMAGE_COUNT +
            MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE;
    #elif defined(__MMI_CAMCO_FEATURE_CAM_BESTSHOT__)
        appmem_size = 
            GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL * 2  +
            MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE;
    #else 
        appmem_size = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL * 2 ;
    #endif 
    }
    else
    {
        appmem_size = GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL * 2 ;
    }
   
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    appmem_size += 256*4;  // for overlay palette
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CONFIG_MEM, appmem_size);    

    m_appMemBuffer = applib_asm_alloc_nc_r(m_appID, appmem_size);

    if (m_appMemBuffer == NULL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CONFIG_MEM, -1);      
        return;
    }

    currentP = (VfxU8*)m_appMemBuffer; 

    m_appMemQuickViewBuffer = currentP;
    currentP += (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL) * 2;            
    
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    m_appAddFrameLayerBuffer = m_appMemQuickViewBuffer;
    
    m_overlayPalette = (VfxU32*)currentP;
    currentP += 256*4;  
#endif

    if(!m_isExtCalling)
    {
    #if defined(__MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__) || defined(__MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__)
        
        m_appMultiShotThumbnailsBuffer = currentP;
        currentP += (MMI_CAMCO_CAM_CACHE_IMAGE_SIZE * MMI_CAMCO_CAM_CACHE_IMAGE_COUNT);     

        m_appMedMultiShotWorkingBuffer = currentP;
        currentP += MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE;     

        VfxU8* tempP;
        
        #ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__
            tempP= (VfxU8*) m_appMultiShotThumbnailsBuffer;

            for (VfxU8 idx = 0; idx < MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT; idx++)
            {
                m_burstShot.cache_img_p[idx] = tempP;
                tempP += MMI_CAMCO_CAM_CACHE_IMAGE_SIZE;
            }
        #endif /* __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__ */ 

        #ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__
            tempP= (U8*) m_appMultiShotThumbnailsBuffer;

            for (VfxU8 idx = 0; idx < MMI_CAMCO_FEATURE_CAM_AEBSHOT_IMAGE_COUNT; idx++)
            {
                m_aebShot.cache_img_p[idx] = tempP;
                tempP += MMI_CAMCO_CAM_CACHE_IMAGE_SIZE;
            }
        #endif /* __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__ */     

    #elif defined(__MMI_CAMCO_FEATURE_CAM_BESTSHOT__)

        m_appMedMultiShotWorkingBuffer = currentP;
        currentP += MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE;    
        
    #endif
    
    }   

    m_cam_capture_param.buffer = m_appMedMultiShotWorkingBuffer;
    m_cam_capture_param.quickviewBuffer = m_appMemQuickViewBuffer;
    m_rec_fetch_param.quickviewBuffer = m_appMemQuickViewBuffer;    
    m_osd_rec_preview_state_param.buffer = m_appMemQuickViewBuffer;    
}

void VappCamcoPage::resetMem(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESET_MEM, m_appMemBuffer);    

    if(m_appMemBuffer)
        applib_asm_free_r(m_appID, m_appMemBuffer);
    m_appMemBuffer = NULL;
    
    m_appMultiShotThumbnailsBuffer = NULL;        
    m_appMedMultiShotWorkingBuffer = NULL;                
    m_appAddFrameLayerBuffer = NULL;    

    gui_free(m_camFileNameBuf);
    m_camFileNameBuf = NULL;   
    gui_free(m_camSlaveFileNameBuf);
    m_camSlaveFileNameBuf = NULL;           
    gui_free(m_recFileNameBuf);
    m_recFileNameBuf = NULL;    

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_INIT_ENV);        
    
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

} 

void VappCamcoPage::deinitEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_DEINIT_ENV);    

    // resume bg ply
    mdi_audio_resume_background_play();
    
    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* resume LED patten */
    srv_pattern_play_req(srv_led_pattern_get_bg_pattern(), 1);

    /* let MMI can sleep */
    srv_backlight_turn_off();

    /* resume background audio */

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

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

    return disk_size;
}


VfxBool VappCamcoPage::checkRemovableStorage(void)
{      
    if(srv_fmgr_drv_is_removable(m_Setting->getStorage()) 
        && !srv_fmgr_drv_is_accessible(m_Setting->getStorage()))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_REMOVABLE_STORAGE, 0);      
        return VFX_FALSE;
    }        
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_REMOVABLE_STORAGE, 1);      
        return VFX_TRUE;        
    }        
}

VfxBool VappCamcoPage::checkSavePath(void)
{ 
    VappCamcoPage::m_errStr = 0;
    m_osd_cam_preview_state_param.indicatorStringID = 0;
    m_osd_rec_preview_state_param.indicatorStringID = 0;
    
    if (FS_NO_ERROR != FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, -1);     
        return VFX_FALSE;
    }

    // check drive    
    if(!srv_fmgr_drv_is_accessible(m_Setting->getStorage()))
    {
        if(!srv_fmgr_drv_is_removable(m_Setting->getStorage()))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, -2);             
            return VFX_FALSE;
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, 1);             
            
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
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, 2);                     
        return VFX_TRUE;   
    }
   
    /* create directory if it is not there */
    fs_ret = FS_CreateDir((PU16) filePath);

    if (fs_ret < 0)
    {
        if(fs_ret == FS_DISK_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, -3);            
            if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                m_osd_cam_preview_state_param.indicatorStringID = FMGR_FS_DISK_FULL_TEXT;
            else
                m_osd_rec_preview_state_param.indicatorStringID = FMGR_FS_DISK_FULL_TEXT;
            VappCamcoPage::m_errStr = FMGR_FS_DISK_FULL_TEXT;
            return VFX_TRUE;               
        }
        else if(fs_ret == FS_ROOT_DIR_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, -4);            
            if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
                m_osd_cam_preview_state_param.indicatorStringID = FMGR_FS_ROOT_DIR_FULL_TEXT;
            else
                m_osd_rec_preview_state_param.indicatorStringID = FMGR_FS_ROOT_DIR_FULL_TEXT; 
            VappCamcoPage::m_errStr = FMGR_FS_ROOT_DIR_FULL_TEXT;            
            return VFX_TRUE;               
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, -5);                         
        return VFX_FALSE;
    }
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CHECK_SAVE_PATH, 3);  
    return VFX_TRUE;

}

void VappCamcoPage::initApp(void)    
{
    VfxBool appInitFlag = m_isAppInited;
    
    if(!m_isAppInited)
    {
        VFX_OBJ_CREATE(m_Setting,CamcoSettingMgr,this);     
        VFX_OBJ_CREATE(m_OSD,CamcoOSDMgr,this);   

        m_cam_preview_start_param.Setting = m_Setting;
        m_cam_preview_start_param.obj = this;
        m_cam_preview_start_param.flag = &m_hwFlag;    
        m_cam_preview_start_param.previewFrame = m_previewFrame;
        m_cam_preview_start_param.previewWindow = &m_previewWindow;
        
        m_cam_preview_stop_param.Setting = m_Setting;
        m_cam_preview_stop_param.obj = this;    
        m_cam_preview_stop_param.flag = &m_hwFlag;    

        m_rec_preview_start_param.Setting = m_Setting;
        m_rec_preview_start_param.obj = this;
        m_rec_preview_start_param.flag = &m_hwFlag;        
        m_rec_preview_start_param.previewFrame = m_previewFrame;
        m_rec_preview_start_param.previewWindow = &m_previewWindow;
        
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
        m_cam_capture_param.previewWindow = &m_previewWindow;    

#ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__    
        m_cam_capture_param.burstShotJpgData = &m_burstShot.jpeg_data;
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__    
        m_cam_capture_param.aebShotJpgData = &m_aebShot.jpeg_data;
#endif

        m_cam_capture_param.buffer_size = MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE; 

        m_cam_capture_save_param.Setting = m_Setting;
        m_cam_capture_save_param.obj = this;
        m_cam_capture_save_param.flag = &m_hwFlag;        
         
        m_cam_hdr_shot_param.Setting = m_Setting;
        m_cam_hdr_shot_param.obj = this;
        m_cam_hdr_shot_param.flag = &m_hwFlag;   
        m_cam_hdr_shot_param.previewFrame = m_previewFrame;
        
        m_rec_record_param.Setting = m_Setting;
        m_rec_record_param.obj = this;
        m_rec_record_param.flag = &m_hwFlag;        
        m_rec_record_param.previewFrame = m_previewFrame;

        m_rec_record_save_param.Setting = m_Setting;
        m_rec_record_save_param.obj = this;
        m_rec_record_save_param.flag = &m_hwFlag;        
        VFX_OBJ_CREATE(m_rec_record_save_param.save_timer, VfxTimer, this);
        m_rec_record_save_param.save_timer->m_signalTick.connect(this, &VappCamcoPage::onSaveTimerTick);        

        m_rec_fetch_param.Setting = m_Setting;
        m_rec_fetch_param.obj = this;
        m_rec_fetch_param.flag = &m_hwFlag;        
        m_rec_fetch_param.previewFrame = m_previewFrame;
        m_rec_fetch_param.previewWindow = &m_previewWindow;

        m_cam_smiledetect_param.obj = this;
        m_cam_smiledetect_param.flag = &m_hwFlag;          

        m_cam_scene_param.obj = this;
        m_cam_scene_param.flag = &m_hwFlag;    
        m_cam_scene_param.currentScene = 0;

        m_autofocus_param.obj = this;    
        m_autofocus_param.flag = &m_hwFlag;         
        VFX_OBJ_CREATE(m_autofocus_param.af_timer, VfxTimer, this);
        m_autofocus_param.af_timer->m_signalTick.connect(this, &VappCamcoPage::onAFTimerTick);

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
        m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_STITCHING);
        m_osd_hint_state_param.hintIcon = MAIN_MENU_CAMCO_ICON;
        m_osd_hint_state_param.isPreviewON = VFX_FALSE;
        m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
        
        m_osd_cam_preview_state_param.setting = m_Setting;
        m_osd_cam_preview_state_param.previewWindow = VfxRect(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1,426,320);
        m_osd_cam_preview_state_param.capturableNumber = 9999;
        m_osd_cam_preview_state_param.settingLevel = VAPP_CAMCO_OSD_SETTING_FULL;

        m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_cam_quick_view_state_param.savedImg.bgColor = VRT_COLOR_BLACK;
        m_osd_cam_quick_view_state_param.previewWindow = VfxRect(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1,426,320);
                      
        m_osd_cam_add_frame_state_param.setting = m_Setting;  
       
        m_osd_rec_preview_state_param.setting = m_Setting;
        m_osd_rec_preview_state_param.previewWindow = VfxRect(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1,426,320);
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

    // get the current rot of target
    // it may be vertical before enter camcorder
    vapp_camco_osd_screen_param_struct rotParam;    
    rotParam.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_ROT;

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER &&
       m_Setting->getValue(VAPP_CAMCO_SETTING_VISCODEC) == VAPP_CAMCO_VISCODEC_3GP)
    {
        if(m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
        {
            rotParam.isHorz = VFX_TRUE;
            rotParam.isMirror = VFX_FALSE;
        }
        else
        {
            rotParam.isHorz = VFX_FALSE;
            rotParam.isMirror = VFX_FALSE;
        }
    }
    else
    {
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
    }
    m_isOSDHorz = rotParam.isHorz;
    m_isOSDMirror = rotParam.isMirror;
    m_OSD->setScreenParam(rotParam);     

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
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_INIT_SETTING_STORAGE);      
                
                m_Setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));
                m_Setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));        
                g_vapp_camco_config.isSetDefaultStorage = VFX_FALSE;
            }            
        }
    }      
}

void VappCamcoPage::initSetting()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_INIT_SETTING, m_Setting->m_callingParam.mode);  

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
    m_Setting->loadSceneSetting();    
    m_Setting->setDefaultAllSetting();
    m_Setting->setValueAllSetting();
    m_Setting->customConfig();    

    // update screnn rotate with current setting
    // it may change rotation after default setting
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);             

    if(g_vapp_camco_config.isSetDefaultStorage)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_INIT_SETTING_STORAGE);      
        
        m_Setting->setValue(VAPP_CAMCO_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));
        m_Setting->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, srv_fmgr_drv_get_type(g_vapp_camco_config.defaultDrv));        
        g_vapp_camco_config.isSetDefaultStorage = VFX_FALSE;
    }
} 

void VappCamcoPage::initPreviewWindow(void) 
{   
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_INIT_PREVIEW_WINDOW, 0, 0, 0, 0);   

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        VfxU16 capsize = m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE);
        VfxU16 temp_width = 0;
        VfxU16 temp_height = 0;
        VfxU16 temp_factor = 0;
        VfxU16 lcd_width = 0;
        VfxU16 lcd_height = 0;
        VfxBool isRot = VFX_FALSE;
        
        if(m_isMainLcdPreview)
        {
        #ifdef HORIZONTAL_CAMERA        
            if (m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                if (capsize == VAPP_CAMCO_CAPSIZE_WALLPAPER && !m_isOnForceHorz)
                {
                    lcd_width = GDI_LCD_HEIGHT;
                    lcd_height = GDI_LCD_WIDTH;    
                    isRot = VFX_TRUE;
                }
                else
                {
                    lcd_width = GDI_LCD_HEIGHT;
                    lcd_height = GDI_LCD_WIDTH;
                    isRot = VFX_FALSE;                    
                }
            }
            else
        #endif        
            {
                if (m_isOnForceHorz)
                {     
                    lcd_width = GDI_LCD_WIDTH;
                    lcd_height = GDI_LCD_HEIGHT;  
                    isRot = VFX_TRUE;                    
                }
                else
                {
                    lcd_width = GDI_LCD_WIDTH;
                    lcd_height = GDI_LCD_HEIGHT;
                    isRot = VFX_FALSE;                    
                }
            }        
        }
        else
        {
            ASSERT(0);
        }

        if (capsize == VAPP_CAMCO_CAPSIZE_WALLPAPER)
        {
        #ifdef HORIZONTAL_CAMERA        
            if (m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                temp_width = GDI_LCD_HEIGHT;
                temp_height = GDI_LCD_WIDTH;                
            }
            else
        #endif        
            {
                temp_width = GDI_LCD_WIDTH;
                temp_height = GDI_LCD_HEIGHT;      
            }
        }
        else if (capsize == VAPP_CAMCO_CAPSIZE_HLCD)
        {
            temp_width = lcd_width;
            temp_height = lcd_height;
        }
        else
        {
            temp_factor = (lcd_height / 6);
            temp_width = temp_factor * 8;
            while (temp_width > lcd_width)
            {
                temp_factor--;
                temp_width = temp_factor * 8;
            }
            temp_height = temp_factor * 6;
        }
        if(!isRot)
        {
            m_previewWindow.size = VfxSize(temp_width, temp_height);       
            m_previewWindow.origin = VfxPoint(lcd_width>>1, lcd_height>>1);            
        }            
        else
        {
            m_previewWindow.size = VfxSize(temp_height, temp_width);                
            m_previewWindow.origin = VfxPoint(lcd_height>>1, lcd_width>>1);                 
        }
        
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
        VfxBool isRot = VFX_FALSE;

        if(m_isMainLcdPreview)
        {
        #ifdef HORIZONTAL_CAMERA        
            if (m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                if (vdosize == VAPP_CAMCO_RECSIZE_WALLPAPER && !m_isOnForceHorz)
                {
                    lcd_width = GDI_LCD_HEIGHT;
                    lcd_height = GDI_LCD_WIDTH;    
                    isRot = VFX_TRUE;
                }
                else
                {
                    lcd_width = GDI_LCD_HEIGHT;
                    lcd_height = GDI_LCD_WIDTH;
                    isRot = VFX_FALSE;                    
                }              
            }
            else
        #endif        
            {
                if (m_isOnForceHorz)
                {     
                    lcd_width = GDI_LCD_WIDTH;
                    lcd_height = GDI_LCD_HEIGHT;         
                    isRot = VFX_TRUE;                      
                }
                else
                {
                    lcd_width = GDI_LCD_WIDTH;
                    lcd_height = GDI_LCD_HEIGHT;
                    isRot = VFX_FALSE;                      
                }            
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

        if (vdosize == VAPP_CAMCO_RECSIZE_WALLPAPER)
        {
        #ifdef HORIZONTAL_CAMERA        
            if (m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
            {
                temp_width = GDI_LCD_HEIGHT;
                temp_height = GDI_LCD_WIDTH;                
            }
            else
        #endif        
            {
                temp_width = GDI_LCD_WIDTH;
                temp_height = GDI_LCD_HEIGHT;      
            }
        }
        else
        {
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
        }            
        
        if(!isRot)
        {
            m_previewWindow.size = VfxSize(temp_width, temp_height);
            m_previewWindow.origin = VfxPoint(lcd_width>>1, lcd_height>>1);                        
        }
        else
        {
            m_previewWindow.size = VfxSize(temp_height, temp_width);        
            m_previewWindow.origin = VfxPoint(lcd_height>>1, lcd_width>>1);            
        }
        
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
    m_previewFrame->setSize(m_previewWindow.size);
    m_previewFrame->setPos(m_previewWindow.origin);
    m_previewFrame->prepare();    


    gdi_handle handleT = m_previewFrame->getLayerHandle();
    S32 width, height;
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_get_dimension(&width, &height);
    m_prepareFrameSize = (width * height * gdi_layer_get_bit_per_pixel()) >> 3;
    gdi_layer_get_buffer_ptr((U8**)&m_prepareFramePtr);
    gdi_layer_pop_and_restore_active();

}

void VappCamcoPage::onPreviewFramePrepareDone(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_PREVIEW_FRAME_PREPARE_DONE); 

    if(!m_isStartingPreview)
    {
        return;
    }
    else
    {
        m_isStartingPreview = VFX_FALSE;
    }
    
    if((m_state != VAPP_CAMCO_STATE_EXIT) && (m_state != VAPP_CAMCO_STATE_CAM_SAVE_DONE))
    {
        m_delayPreviewTimer->setStartDelay(350);            
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ON_PREVIEW_FRAME_PREPARE_DONE); 
    
    m_isDelayPreview = VFX_FALSE;

    vapp_camco_osd_screen_param_struct param;
    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
    param.isBusy = VFX_FALSE;
    m_OSD->setScreenParam(param);            
    
    vappCamcoRestartParamStruct t;
    t.dummy = 0;
    m_restartPreviewCallback.invoke(t);
}

void VappCamcoPage::dummyRestartPreview(vappCamcoRestartParamStruct param)
{

}

void VappCamcoPage::camRestartPreview(vappCamcoRestartParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_RESTART_PREVIEW);   
    
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
        if(getFreeStorageSize() < m_cam_est_size_param.size * 0.5 && m_osd_cam_preview_state_param.indicatorStringID == 0)
            renainSizeparam.indicator_string = FMGR_FS_DISK_FULL_TEXT;
        else
            renainSizeparam.indicator_string = m_osd_cam_preview_state_param.indicatorStringID;         
        VappCamcoPage::m_errStr = renainSizeparam.indicator_string;

        m_OSD->setScreenParam(renainSizeparam);
    
        vapp_camco_osd_screen_param_struct zoomUpdateParam;
        zoomUpdateParam.type = VAPP_CAMCO_OSD_SCR_PARAM_ZOOM_UPDATE;
        zoomUpdateParam.zoom_value = m_Setting->getValue(VAPP_CAMCO_SETTING_CAMZOOM);            
        m_OSD->setScreenParam(zoomUpdateParam);

        // check memory card status (for memory card rule)            
        if(!checkRemovableStorage()) 
        {
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.isFWHorz = isHorzUI();
            m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
            m_osd_hint_state_param.event= VAPP_CAMCO_OSD_HINT_EVT_CAM_NO_CARD;
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;  
            
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);    
        }
    }
    else
    {
        VAPP_CAMCO_STOP_LOGGING("PRE");     
        enterState(VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED);     
    }

    if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW)
    {

        if(m_Setting->getValue(VAPP_CAMCO_SETTING_HIGHLIGHT) == VAPP_CAMCO_HIGHLIGHT_ON)    
        {
            vapp_camco_highlight_turn_on(&m_general_param);        
        }
        else
        {
            vapp_camco_highlight_turn_off(&m_general_param);
        }                
    }

#ifdef __VAPP_CAMCO_3D_SPEEDUP__   
    // when 3D speedup ON, stop CAL mean no preview 
    if(!m_hwFlag.isCalBgProcessOn)  
    {
        vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);        
    }
#endif      
}

void VappCamcoPage::recRestartPreview(vappCamcoRestartParamStruct param)
{       
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_RESTART_PREVIEW);    
    
    // work for w < h preview on setting menu
    if(m_isOnForceHorz &&  (m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA || m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER))
    {
        vapp_camco_rec_preview_set_rot(0);    
    }
    
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

        if(freeSpace < m_rec_est_size_param.size * 0.5 && m_osd_rec_preview_state_param.indicatorStringID == 0)
            renainSizeparam.indicator_string = FMGR_FS_DISK_FULL_TEXT;
        else
            renainSizeparam.indicator_string = m_osd_rec_preview_state_param.indicatorStringID;             
        VappCamcoPage::m_errStr = renainSizeparam.indicator_string;
        
        m_OSD->setScreenParam(renainSizeparam);

        // check memory card status (for memory card rule)        
        if(!checkRemovableStorage()) 
        {
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.isFWHorz = isHorzUI();
            m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
            m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_REC_NO_CARD;        
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;  
            
            
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);    
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

        if(m_Setting->getValue(VAPP_CAMCO_SETTING_HIGHLIGHT) == VAPP_CAMCO_HIGHLIGHT_ON)    
        {
            vapp_camco_highlight_turn_on(&m_general_param);
        }
        else
        {
            vapp_camco_highlight_turn_off(&m_general_param);
        }            
    }    

#ifdef __VAPP_CAMCO_3D_SPEEDUP__   
    // when 3D speedup ON, stop CAL mean no preview 
    if(!m_hwFlag.isCalBgProcessOn)  
    {
        vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);        
    }
#endif      

}

void VappCamcoPage::camPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_HDLR, evt_type);

    // resume bg calculation will after animation, sometimes it will restarting   
    if(evt_type != VAPP_CAMCO_EVT_BG_CAL_START)
    {
        if(m_isStartingPreview || m_isDelayPreview)
            return;
    }
    
    // smile detect / scene dectect may start/end at enter previou state 
    // and app may still at save done, popup error state cause HW frame is not ready yet
    if(evt_type != VAPP_CAMCO_EVT_ENTER_SMILEDETECT && 
       evt_type != VAPP_CAMCO_EVT_LEAVE_SMILEDETECT &&
       evt_type != VAPP_CAMCO_EVT_START_SCN_DETECT &&
       evt_type != VAPP_CAMCO_EVT_STOP_SCN_DETECT)
    {
        if(m_state != VAPP_CAMCO_STATE_CAM_PREVIEW && m_state != VAPP_CAMCO_STATE_CAM_FOCUSING && m_state != VAPP_CAMCO_STATE_CAM_FOCUSED && m_state != VAPP_CAMCO_STATE_CAM_SMILE_DECT)
            return;
    }
    
    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_ENTER_GALLERY:
        {

            VfxWString fimeName = VFX_WSTR_MEM(m_camFileNameBuf);
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
            if(m_isAFTonePlaying)
                mdi_audio_stop_string();
            
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {

                m_smileDetectCycTimer->stop();  
                m_smileDetectSuccessTimer->stop();             
                
                m_sceneDetectCycTimer->stop();  
            
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);            
                showPopupScreen(0, NULL, m_recoverStateCB);
                break;
            }

        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */             
        
            U16 capmode = m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE);
            vapp_camco_selftimer_enum selftimer = VAPP_CAMCO_SELFTIMER_OFF;            
            
            if (capmode != VAPP_CAMCO_CAPMODE_CONT_SHOT &&
                capmode != VAPP_CAMCO_CAPMODE_SMILE_SHOT)
            {
                selftimer = (vapp_camco_selftimer_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_SELFTIMER);
            }            
            m_smileDetectCycTimer->stop();  
            m_smileDetectSuccessTimer->stop();             

            m_sceneDetectCycTimer->stop();  

            vfx_adp_touch_fb_disable_tone();
            vfx_adp_touch_fb_disable_vibrate();

            if (selftimer == VAPP_CAMCO_SELFTIMER_OFF)
            {  
                Capture();
            }
            else if (selftimer != VAPP_CAMCO_SELFTIMER_END)
            {
                m_countdownDuration = (S32) selftimer *5 * 1000;

                enterState(VAPP_CAMCO_STATE_CAM_COUNTDOWN);
            }            
          
            break;
        }
        case VAPP_CAMCO_EVT_SWITCH_SENSOR:
        {            
            m_isFirstEnterPreview = VFX_TRUE;
            
            exitState();
            vapp_camco_cam_power_off(&m_cam_power_off_param);       
                        
            initSetting();

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

            m_Setting->needRestartPreview();
            vapp_camco_cam_power_on(&m_cam_power_on_param);

            // update the rot
            mmi_frm_auto_rotate_evt_struct evt;
            evt.user_data = this;
            evt.new_degree = mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR);
            sensorChangeNotifyHdlr((mmi_event_struct*)&evt);

            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            
            break;
        }            
        case VAPP_CAMCO_EVT_SWITCH_APP: 
        {
              
            exitState();
            vapp_camco_cam_power_off(&m_cam_power_off_param);   
            vapp_camco_rec_power_on(&m_rec_power_on_param);               
            
            initSetting();
            
            if((m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER &&
               m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_RECSIZE_WALLPAPER) ||
               (m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) != VAPP_CAMCO_CAPSIZE_WALLPAPER &&
               m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER)
              )
            {
                // because camera use Vertical Ui on WP size with rear camera, but recorder use horizontal under rear camera
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);              
            }  
            
            // update the rot
            mmi_frm_auto_rotate_evt_struct evt;
            evt.user_data = this;
            evt.new_degree = mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR);
            sensorChangeNotifyHdlr((mmi_event_struct*)&evt);

            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;
        }       
        case VAPP_CAMCO_EVT_ENTER_SMILEDETECT:
        {            
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT ||
               m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT )
            {
                m_smileDetectCycTimer->start();
            }
            else
            {
                ASSERT(0);
            }
            break;            
        }
        case VAPP_CAMCO_EVT_LEAVE_SMILEDETECT:
        {
            m_smileDetectCycTimer->stop();  
            m_smileDetectSuccessTimer->stop();            
            break;                        
        }
        case VAPP_CAMCO_EVT_START_SMILEDETECT:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {
                showPopupScreen(0, NULL, m_recoverStateCB);
                break;
            }
            
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
            {            
                enterState(VAPP_CAMCO_STATE_CAM_SMILE_DECT);            
            }
            else
            {
                ASSERT(0);
            }            
            break;                        
        }
        case VAPP_CAMCO_EVT_STOP_SMILEDETECT:
        {  
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;                        
        }   
        case VAPP_CAMCO_EVT_START_SCN_DETECT:
        {
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)
            {
                m_sceneDetectCycTimer->start();
            }
            else
            {
                ASSERT(0);
            }            
            break;
        }
        case VAPP_CAMCO_EVT_STOP_SCN_DETECT:
        {
            m_sceneDetectCycTimer->stop();      
            break;            
        }
        case VAPP_CAMCO_EVT_FOCUS:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappCamcoPage::m_errStr != 0)
            {

                m_smileDetectCycTimer->stop();  
                m_smileDetectSuccessTimer->stop();             
                
                m_sceneDetectCycTimer->stop();  
            
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);            
                showPopupScreen(0, NULL, m_recoverStateCB);
                break;
            }
            
            if(m_state != VAPP_CAMCO_STATE_CAM_SMILE_DECT)
                enterState(VAPP_CAMCO_STATE_CAM_FOCUSING);            
            break;
        }
        case VAPP_CAMCO_EVT_RESTART:
        {
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);              
            }
            else
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);                                   
            }
            m_isFirstEnterPreview = VFX_TRUE;                 
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);            
            break;
        }
        case VAPP_CAMCO_EVT_FORCE_HORZ:
        {
            
            m_isOnForceHorz = VFX_TRUE;
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);  
            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);                
            break;
        }
        case VAPP_CAMCO_EVT_DE_FORCE_HORZ:
        {
            // update the rot
            mmi_frm_auto_rotate_evt_struct evt;
            evt.user_data = this;
            evt.new_degree = mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR);
            sensorChangeNotifyHdlr((mmi_event_struct*)&evt);

            m_isOnForceHorz = VFX_FALSE;
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);      
            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);                                           
            break;
        }
        case VAPP_CAMCO_EVT_NOTIFY_HORZ:
        {            
            m_isOnForceHorz = VFX_TRUE;
            break;
        }
        case VAPP_CAMCO_EVT_DE_NOTIFY_HORZ:
        {
            m_isOnForceHorz = VFX_FALSE;
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
        case VAPP_CAMCO_EVT_BG_CAL_START:
        {
        #ifdef __VAPP_CAMCO_3D_SPEEDUP__            
            m_cam_preview_start_param.isResetZoom = VFX_TRUE;                           
            vapp_camco_cam_preview_start(&m_cam_preview_start_param);
        #endif    
            vapp_camco_background_calculation_start(&m_cam_bg_process_param);
            break;
        }
        case VAPP_CAMCO_EVT_BG_CAL_STOP:            
        {
        #ifdef __VAPP_CAMCO_3D_SPEEDUP__                        
            vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
        #endif
            vapp_camco_background_calculation_stop(&m_cam_bg_process_param);            
            break;
        }          
        default:
            ASSERT(0);
    }            

};
void VappCamcoPage::camPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_PREVIEW_FAILED_HDLR, evt_type);

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_SAVE_DONE_HDLR, evt_type);

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_COUNT_DOWN_HDLR, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_COUNTDOWN)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_BACK:
        {
            countdownLedTimer->stop();   
            countdownCycTimer->stop();     
            countdownLedTurnOff(NULL);

            deinitCountDownSound();

            vapp_camco_cam_autofocus_stop(&m_autofocus_param);

            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }    
        default:
            ASSERT(0);
    }  

};

void VappCamcoPage::camContshotHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_CONTSHOT_HDLR, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_CONTSHOT)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_CAPTURE:
        {
            MDI_RESULT ret;
            
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

            if(getNextFilename(m_camFileNameBuf))
            {
                m_cam_capture_param.fileName = m_camFileNameBuf;
                
                VAPP_CAMCO_START_LOGGING("CON"); 
                ret = vapp_camco_cam_contshot(&m_cam_capture_param);
                VAPP_CAMCO_STOP_LOGGING("CON");                 
            }
            else
            {
                ret = VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND;
            }

        #ifndef __MTK_TARGET__        
            if(m_contshot_i%5 == 0)
            {
                m_previewFrame->setBgColor(VfxColor(VRT_COLOR_BLACK));
            }
            else if(m_contshot_i%5 == 1)
            {
                m_previewFrame->setBgColor(VfxColor(VRT_COLOR_GREEN));
            }
            else if(m_contshot_i%5 == 2)
            {
                m_previewFrame->setBgColor(VfxColor(VRT_COLOR_AQUA));
            }
            else if(m_contshot_i%5 == 3)
            {
                m_previewFrame->setBgColor(VfxColor(VRT_COLOR_WHITE));
            }
            else if(m_contshot_i%5 == 4)
            {
                m_previewFrame->setBgColor(VfxColor(VRT_COLOR_PURPLE));
            }            
            m_contshot_i++;
        #endif    

            if(ret != MDI_RES_CAMERA_SUCCEED)
            {            
                m_hwFlag.isTakepicFailed = VFX_TRUE;
            
                vapp_camco_cam_autofocus_stop(&m_autofocus_param);

                if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)
                    restoreFilename();
                
                vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);

                vappCamcoPopupParamStruct param;
                param.next_state = VAPP_CAMCO_STATE_CAM_CONTSHOT;
                showPopupScreen(ret, &param, m_enterStateCB);                
            }
            else
            {
                playCatureSound(ret);            
                
                // because the content is changed by HW and VRT won't know that
                // so need AP to triger invalidate() for update captured content
                invalidate();
            }
            
        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */             
            break;
        }    
        case VAPP_CAMCO_EVT_CONT_SHOT_FINISH:
        {
            // stop show error popup if exist
            if(m_isPopupRunning)
            {
                stopPopupScreen();

                vappCamcoPopupParamStruct param;
                param.next_state = VAPP_CAMCO_STATE_CAM_PREVIEW;
                showPopupScreen(m_CurrentPopupShownresult, &param, m_enterStateCB);          
            }
            else
            {
                vapp_camco_cam_autofocus_stop(&m_autofocus_param);
                m_Setting->needRestartPreview();

                m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
                m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_CONT_SHOT;
                m_osd_cam_quick_view_state_param.savedImg.bgColor = VRT_COLOR_BLACK;
                m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI();
                m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);            
                m_OSD->updateScreen();
            }            
            break;
        }   
        case VAPP_CAMCO_EVT_VIEW_STOP:
        {
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);        

            vfx_adp_touch_fb_enable_tone();
            vfx_adp_touch_fb_enable_vibrate();
            break;
        }
        default:
            ASSERT(0);
    }    

};

void VappCamcoPage::camBurstshotSelectHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_BURSTSHOT_SELECT_HDLR, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_VIEW_STOP:
        {
            // if show error popup, not goto preview state directly,
            // wait for user check 
            if(!m_isNotifyRunning)
            {
                enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);            
            }         
            break;
        }    
        case VAPP_CAMCO_EVT_MULTISHOT_SAVE:
        {
        #ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__    

            MDI_RESULT ret;

            if(m_isNotifyRunning)
                break;
            
            if(getNextFilename(m_camFileNameBuf))       
            {
                ret = saveCapturedImage(
                    m_camFileNameBuf, 
                    (void*) m_burstShot.jpeg_data.file_address[(*(VfxU16*)param)],
                    (VfxU32) m_burstShot.jpeg_data.file_size[(*(VfxU16*)param)]);   
            }
            else
            {
                ret = VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND;
            }
            
            if (ret != MDI_RES_CAMERA_SUCCEED)
            {        
                if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)            
                    restoreFilename();       
                showPopupScreen(ret, NULL, m_recoverStateCB);                
            }

        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */             
        
        #endif    
            break;
        }     
        default:
            ASSERT(0);
    }  

};

void VappCamcoPage::camAebshotSelectHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_AEBSHOT_SELECT_HDLR, evt_type);

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_VIEW_STOP:
        {
            // if show error popup, not goto preview state directly,
            // wait for user check 
            if(!m_isNotifyRunning)
            {
                enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);            
            }         
            break;
        }    
        case VAPP_CAMCO_EVT_MULTISHOT_SAVE:
        {
        #ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__            
            MDI_RESULT ret;

            if(m_isNotifyRunning)
                break;
            
            if(getNextFilename(m_camFileNameBuf))
            {
                ret = saveCapturedImage(
                    m_camFileNameBuf, 
                    (void*) m_aebShot.jpeg_data.file_address[(*(VfxU16*)param)],
                    (VfxU32) m_aebShot.jpeg_data.file_size[(*(VfxU16*)param)]);   
            }
            else
            {
                ret = VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND;
            }
            
            if (ret != MDI_RES_CAMERA_SUCCEED)
            {    
                if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)
                    restoreFilename();       
                showPopupScreen(ret, NULL, m_recoverStateCB);                
            }

        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */        
        
        #endif    
            break;
        }                
        default:
            ASSERT(0);
    }  

};

void VappCamcoPage::camSmileDectHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_SMILEDECT_HDLR, evt_type);

    return;
};

void VappCamcoPage::camHDRShotHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_HDRSHOT_HDLR, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_HDR_SHOT)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_BACK:
        {
            if(m_hwFlag.isHDRing)
            {
                MDI_RESULT ret = vapp_camco_cam_hdr_shot_stop(&m_cam_hdr_shot_param);
                
                restoreFilename();

                // if stop succes, the last picture should be HDR pre-processing picture
                if(ret == MDI_RES_CAMERA_SUCCEED)
                {
                    mmi_wcscpy(m_camFileNameBuf, m_camSlaveFileNameBuf);             
                    mmi_wcscpy(g_vapp_camco_cam_prev_file_name, m_camSlaveFileNameBuf);                             
                }
                else                
                {
                    mmi_wcscpy(m_camFileNameBuf, g_vapp_camco_cam_hdr_prev_file_name);             
                    mmi_wcscpy(g_vapp_camco_cam_prev_file_name, g_vapp_camco_cam_hdr_prev_file_name);                             
                }
            }            
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);            
            break;
        }    
        default:
            ASSERT(0);
    }    

};

void VappCamcoPage::camHDRDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_HDRDONE_HDLR, evt_type);

    if(m_state != VAPP_CAMCO_STATE_CAM_HDR_DONE)
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

void VappCamcoPage::camFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_CAM_FOCUS_HDLR, evt_type);

    if(m_state == VAPP_CAMCO_STATE_CAM_INT_PREVIEW)
        return;

    if(m_isStartingPreview || m_isDelayPreview)
        return;

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_FOCUS_STOP:
        {
            vapp_camco_cam_autofocus_stop(&m_autofocus_param);            
            m_isFirstEnterPreview = VFX_TRUE;
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }  
        case VAPP_CAMCO_EVT_CAPTURE:
        {
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
            {
                enterState(VAPP_CAMCO_STATE_CAM_PREVIEW); 
                vapp_camco_osd_screen_param_struct updateParam;
                updateParam.type = VAPP_CAMCO_OSD_SCR_PARAM_FOCUS_ENTER_SD;
                m_OSD->setScreenParam(updateParam);
            }
            else
            {                                         
                U16 capmode = m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE);
                vapp_camco_selftimer_enum selftimer = VAPP_CAMCO_SELFTIMER_OFF;            
                
                if (capmode != VAPP_CAMCO_CAPMODE_CONT_SHOT &&
                    capmode != VAPP_CAMCO_CAPMODE_SMILE_SHOT)
                {
                    selftimer = (vapp_camco_selftimer_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_SELFTIMER);
                }            
                m_smileDetectCycTimer->stop();  
                m_smileDetectSuccessTimer->stop(); 
    
                m_sceneDetectCycTimer->stop(); 
                
                if (selftimer == VAPP_CAMCO_SELFTIMER_OFF)
                {  
                    Capture();
                }
                else if (selftimer != VAPP_CAMCO_SELFTIMER_END)
                {
                    m_countdownDuration = (S32) selftimer *5 * 1000;
    
                    enterState(VAPP_CAMCO_STATE_CAM_COUNTDOWN);
                }   
            }
            break;
        }          
        default:
            ASSERT(0);
    }    

};

void VappCamcoPage::recPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_HDLR, evt_type);

    // resume bg calculation will after animation, sometimes it will restarting   
    if(evt_type != VAPP_CAMCO_EVT_BG_CAL_START)
    {
        if(m_isStartingPreview || m_isDelayPreview)
            return;
    }

    if(m_isTonePlaying)
        return;

    if(m_state != VAPP_CAMCO_STATE_REC_PREVIEW && m_state != VAPP_CAMCO_STATE_REC_FOCUSING && m_state != VAPP_CAMCO_STATE_REC_FOCUSED)
        return;
    
    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_ENTER_GALLERY:
        {
            VfxWString fimeName = VFX_WSTR_MEM(m_recFileNameBuf);
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
            // if there are some error when preview, show error again directly, no start record
            if(VappCamcoPage::m_errStr != 0)
            {
                vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
                showPopupScreen(0, NULL, m_recoverStateCB);
                break;
            }
            
            
            mdi_audio_play_id(TONE_WARNING1,DEVICE_AUDIO_PLAY_ONCE);                   
            m_recordToneTimer->start();    
            m_isTonePlaying = VFX_TRUE;

            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
            param.isBusy = VFX_TRUE;
            m_OSD->setScreenParam(param);               
            break;
        }
        case VAPP_CAMCO_EVT_SWITCH_SENSOR:
        {
             
            m_isFirstEnterPreview = VFX_TRUE;
            
            exitState();
            vapp_camco_rec_power_off(&m_rec_power_off_param);         
            
            initSetting();

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

            m_Setting->needRestartPreview();
            vapp_camco_rec_power_on(&m_rec_power_on_param);

            // update the rot
            mmi_frm_auto_rotate_evt_struct evt;
            evt.user_data = this;
            evt.new_degree = mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR);
            sensorChangeNotifyHdlr((mmi_event_struct*)&evt);

            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            
            break;
        }            
        case VAPP_CAMCO_EVT_SWITCH_APP: 
        {
               
            exitState();
            vapp_camco_rec_power_off(&m_rec_power_off_param);     
            vapp_camco_cam_power_on(&m_cam_power_on_param);                           

            initSetting();

            if((m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) == VAPP_CAMCO_CAPSIZE_WALLPAPER &&
               m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) != VAPP_CAMCO_RECSIZE_WALLPAPER) ||
               (m_Setting->getValue(VAPP_CAMCO_SETTING_CAPSIZE) != VAPP_CAMCO_CAPSIZE_WALLPAPER &&
               m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER))
            {
                // because recorder use horizontal under rear camera, but camera use Vertical Ui on WP size with rear camera
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);              
            } 
            
            // update the rot
            mmi_frm_auto_rotate_evt_struct evt;
            evt.user_data = this;
            evt.new_degree = mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR);
            sensorChangeNotifyHdlr((mmi_event_struct*)&evt);

            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_CAMCO_STATE_CAM_PREVIEW);
            break;
        }
        case VAPP_CAMCO_EVT_RESTART:
        {
            if(m_Setting->getValue(VAPP_CAMCO_SETTING_RECSIZE) == VAPP_CAMCO_RECSIZE_WALLPAPER)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
            }
            else
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);                                   
            }    
            
            m_isFirstEnterPreview = VFX_TRUE;                 
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);            
            break;
        }        
        case VAPP_CAMCO_EVT_FORCE_HORZ:
        {
            
            m_isOnForceHorz = VFX_TRUE;
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);  
            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);                
            break;
        }
        case VAPP_CAMCO_EVT_DE_FORCE_HORZ:
        {
            // update the rot
            mmi_frm_auto_rotate_evt_struct evt;
            evt.user_data = this;
            evt.new_degree = mmi_frm_auto_rotate_get_degree(MMI_FRM_AUTO_ROTATE_SENSOR);
            sensorChangeNotifyHdlr((mmi_event_struct*)&evt);

            m_isOnForceHorz = VFX_FALSE;          
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);    
            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);                
            break;
        }
        case VAPP_CAMCO_EVT_NOTIFY_HORZ:
        {            
            m_isOnForceHorz = VFX_TRUE;
            break;
        }
        case VAPP_CAMCO_EVT_DE_NOTIFY_HORZ:
        {
            m_isOnForceHorz = VFX_FALSE;
            break;
        }         
        case VAPP_CAMCO_EVT_FOCUS:
        {
            // if there are some error when preview, show error again directly, no start record
            if(VappCamcoPage::m_errStr != 0)
            {
                vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
                showPopupScreen(0, NULL, m_recoverStateCB);
                break;
            }
            
            enterState(VAPP_CAMCO_STATE_REC_FOCUSING);            
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
        case VAPP_CAMCO_EVT_BG_CAL_START:
        {
        #ifdef __VAPP_CAMCO_3D_SPEEDUP__                                  
            vapp_camco_rec_preview_start(&m_rec_preview_start_param);
        #endif    
            break;
        }
        case VAPP_CAMCO_EVT_BG_CAL_STOP:            
        {
        #ifdef __VAPP_CAMCO_3D_SPEEDUP__                        
            vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
        #endif
            break;
        }                 
        default:
            ASSERT(0);
    }    

};

void VappCamcoPage::recPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PREVIEW_FAILED_HDLR, evt_type);

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_RECORDING_HDLR, evt_type);

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_PAUSE_HDLR, evt_type);

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_SAVE_DONE_HDLR, evt_type);

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

void VappCamcoPage::recFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_REC_FOCUS_HDLR, evt_type);

    if(m_state == VAPP_CAMCO_STATE_REC_INT_PREVIEW)
        return;

    if(m_isStartingPreview || m_isDelayPreview)
        return;

    if(m_isTonePlaying)
        return;
    
    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_FOCUS_STOP:
        {
            vapp_camco_rec_autofocus_stop(&m_autofocus_param);
            m_isFirstEnterPreview = VFX_TRUE;
            enterState(VAPP_CAMCO_STATE_REC_PREVIEW);
            break;
        }  
        case VAPP_CAMCO_EVT_RECORD:
        {
            mdi_audio_play_id(TONE_WARNING1,DEVICE_AUDIO_PLAY_ONCE);                   
            m_recordToneTimer->start();     
            m_isTonePlaying = VFX_TRUE;

            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
            param.isBusy = VFX_TRUE;
            m_OSD->setScreenParam(param);      
            break;
        }          
        default:
            ASSERT(0);
    }    

};

void VappCamcoPage::errorPopupHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ERROR_POPUP_HDLR, evt_type);

    switch (evt_type)
    {
        case VAPP_CAMCO_EVT_OK:
        {
            if(m_isNotifyRunning)
            { 
                m_isNotifyRunning = VFX_FALSE;
                m_popupCallback.invoke(m_popupParam);
            }
            break;
        }    
        default:
            ASSERT(0);
    }  

}

void VappCamcoPage::appGlobalEventHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_APP_GLOBAL_EVENT_HDLR, evt_type);

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_EXIT_STATE);

    exitState();

    m_Setting->setValue(VAPP_CAMCO_SETTING_HIGHLIGHT, VAPP_CAMCO_HIGHLIGHT_OFF);

    if(m_camFileNameBuf && m_recFileNameBuf)
    {
        mmi_wcscpy(g_vapp_camco_cam_prev_file_name, m_camFileNameBuf); 
        mmi_wcscpy(g_vapp_camco_rec_prev_file_name, m_recFileNameBuf); 
    }

    m_state = VAPP_CAMCO_STATE_EXIT;
    
};

void VappCamcoPage::enterCamPreviewState(void)
{
#ifdef VAPP_CAMCO_MODIS_PIC_PREVIEW    
    WCHAR fileName[30];
    CHAR fileNameAsc[15] = "";
    
    sprintf(fileNameAsc, "%c:\\4.bmp", SRV_FMGR_CARD_DRV);    
    mmi_asc_to_wcs(fileName, fileNameAsc);
    
    VfxImageSrc s = VfxImageSrc(VFX_WSTR_MEM(fileName));
    
    m_picturePreviewFrame->setImgContent(s);        
#endif

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_PREVIEW_STATE, 0);

    if(!checkSavePath())
    {
        if(VappCamcoPage::m_errStr == 0)
            VappCamcoPage::m_errStr = STR_ID_VAPP_CAMCO_NOTIFY_STORAGE_NOT_READY;
        
        if(m_hwFlag.isPreviewStart)
        {
            vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);        
        }
        
        enterState(VAPP_CAMCO_STATE_ENTER_FAIL);
        return;
    }

    if(!m_hwFlag.isPreviewStart || m_Setting->isNeedRestartPreview())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_PREVIEW_STATE, 1);
        
        if(m_Setting->isNeedRestartPreview())
        {
            vapp_camco_cam_preview_stop(&m_cam_preview_stop_param);
        }
    
        initPreviewWindow();
        
        m_osd_cam_preview_state_param.previewWindow = m_previewWindow;
        m_osd_cam_preview_state_param.isCleanModeEnter = !m_isFirstEnterPreview;
        m_osd_cam_preview_state_param.capturableNumber = (getFreeStorageSize() / m_cam_est_size_param.size);
        m_osd_cam_preview_state_param.previousFileName = m_camFileNameBuf;
        m_osd_cam_preview_state_param.isRestartEnter = VFX_TRUE;
        m_isFirstEnterPreview = VFX_FALSE;        
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW, &m_osd_cam_preview_state_param, (VappCamcoOSDEvtHdlr*)this);    
        m_OSD->clean();
        m_OSD->updateScreen();              

        if(m_Setting->isNeedRestartPreview())
        {
            m_Setting->setValue(VAPP_CAMCO_SETTING_CAMZOOM, m_Setting->getMinValue(VAPP_CAMCO_SETTING_CAMZOOM));    
        }        
        
        m_restartPreviewCallback = m_camRestartPreviewCallback;
        m_isStartingPreview = VFX_TRUE;
        
        vapp_camco_osd_screen_param_struct param;
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
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
    #endif     
    }
    else
    {
        setState(VAPP_CAMCO_STATE_CAM_PREVIEW);    

        if(!checkRemovableStorage()) 
        {
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.isFWHorz = isHorzUI();
            m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
            m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_CAM_NO_CARD;        
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;   
            
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);    
        }
        else
        {
            m_osd_cam_preview_state_param.previewWindow = m_previewWindow;
            m_osd_cam_preview_state_param.isCleanModeEnter = !m_isFirstEnterPreview;
            m_osd_cam_preview_state_param.capturableNumber = (getFreeStorageSize() / m_cam_est_size_param.size);
            m_osd_cam_preview_state_param.previousFileName = m_camFileNameBuf;    
            m_osd_cam_preview_state_param.isRestartEnter = VFX_FALSE;            
            m_isFirstEnterPreview = VFX_FALSE;                  
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW, &m_osd_cam_preview_state_param, (VappCamcoOSDEvtHdlr*)this);    
            m_OSD->clean();
            m_OSD->updateScreen();               

            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
            m_OSD->setScreenParam(param);
            // no restart preview but need to update size info or it will be clean
            vapp_camco_cam_get_estimated_picture_size(&m_cam_est_size_param);
            vapp_camco_osd_screen_param_struct renainSizeparam;
            renainSizeparam.type = VAPP_CAMCO_OSD_SCR_PARAM_CAM_REMAIN_SIZE_UPDATE;
            renainSizeparam.remain_size = (getFreeStorageSize() / m_cam_est_size_param.size);
            if(getFreeStorageSize() < m_cam_est_size_param.size * 0.5 && m_osd_cam_preview_state_param.indicatorStringID == 0)
                renainSizeparam.indicator_string = FMGR_FS_DISK_FULL_TEXT;
            else
                renainSizeparam.indicator_string = m_osd_cam_preview_state_param.indicatorStringID;               
            VappCamcoPage::m_errStr = renainSizeparam.indicator_string;           
            
            m_OSD->setScreenParam(renainSizeparam);        
        }


    }

    if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW)
    {

        if(m_Setting->getValue(VAPP_CAMCO_SETTING_HIGHLIGHT) == VAPP_CAMCO_HIGHLIGHT_ON)    
        {
            vapp_camco_highlight_turn_on(&m_general_param);        
        }
        else
        {
            vapp_camco_highlight_turn_off(&m_general_param);
        }                
    }

};

void VappCamcoPage::enterCamPreviewFailedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_PREVIEW_FAILED_STATE);

    setState(VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED);
    
    m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_PREVIEW_FAILED);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.isFWHorz = isHorzUI();
    m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;        
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT;  

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);        

    m_OSD->updateScreen();

};


void VappCamcoPage::enterCamFocusingState(void)
{   
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_FOCUSING_STATE);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)

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
            param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_osd_cam_preview_state_param.previewWindow.getX() - (m_osd_cam_preview_state_param.previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_osd_cam_preview_state_param.previewWindow.getY() - (m_osd_cam_preview_state_param.previewWindow.getHeight()>>1);
            param.index = idx;

            m_OSD->setScreenParam(param);
        }
        af_active_zone = af_active_zone >> 1;
    }

    m_OSD->updateScreen();           
#endif    
}


void VappCamcoPage::enterCamFocusedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_FOCUSED_STATE);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
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
            param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_osd_cam_preview_state_param.previewWindow.getX() - (m_osd_cam_preview_state_param.previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_osd_cam_preview_state_param.previewWindow.getY() - (m_osd_cam_preview_state_param.previewWindow.getHeight()>>1);
            param.index = idx;

            m_OSD->setScreenParam(param);
            
        }
        else if (af_active_zone & 0x00000001)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING;
            param.focus.w = m_autofocus_param.af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_osd_cam_preview_state_param.previewWindow.getX() - (m_osd_cam_preview_state_param.previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_osd_cam_preview_state_param.previewWindow.getY() - (m_osd_cam_preview_state_param.previewWindow.getHeight()>>1);
            param.index = idx;

            m_OSD->setScreenParam(param);
        }

        af_success_zone = af_success_zone >> 1;
        af_active_zone = af_active_zone >> 1;
    }

    m_OSD->updateScreen();     
#endif
};


void VappCamcoPage::enterCamCountdownState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_COUNTDOWN_STATE);
    
    setState(VAPP_CAMCO_STATE_CAM_COUNTDOWN);

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_TRANSPARENT;
    m_osd_hint_state_param.isFWHorz = isHorzUI();
    m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_CAM_COUNT_DOWN;        
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT;  

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);  

    m_OSD->updateScreen();   

    initCountDownSound();
    
    kal_get_time(&m_countdownStartTicks);

    countdownCyclic(NULL);    

};

void VappCamcoPage::enterCamCaptureState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_CAPTURE_STATE, 0);

    MDI_RESULT ret = MDI_RES_CAMERA_ERR_FAILED;
    
    if (m_state == VAPP_CAMCO_STATE_CAM_PREVIEW ||
        m_state == VAPP_CAMCO_STATE_CAM_SMILE_DECT ||
        m_state == VAPP_CAMCO_STATE_CAM_FOCUSING ||
        m_state == VAPP_CAMCO_STATE_CAM_FOCUSED ||
        m_state == VAPP_CAMCO_STATE_CAM_COUNTDOWN)
    {
        vapp_camco_capmode_enum capmode = (vapp_camco_capmode_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE);

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_CAPTURE_STATE, capmode);

        memset(m_camFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);
        
        if(getNextFilename(m_camFileNameBuf))
        {
            m_cam_capture_param.fileName = m_camFileNameBuf;

            if (capmode == VAPP_CAMCO_CAPMODE_NORMAL || 
                capmode == VAPP_CAMCO_CAPMODE_SMILE_SHOT ||  
                capmode == VAPP_CAMCO_CAPMODE_ASD_SHOT ||
                capmode == VAPP_CAMCO_CAPMODE_ZSD_SHOT)
            {         
                VAPP_CAMCO_START_LOGGING("NOR");
                ret = vapp_camco_cam_normal_shot(&m_cam_capture_param);            
                VAPP_CAMCO_STOP_LOGGING("NOR");
            }
            else if (capmode == VAPP_CAMCO_CAPMODE_ADD_FRAME)
            {
                VAPP_CAMCO_START_LOGGING("ADD");            
                ret = vapp_camco_cam_addframe_shot(&m_cam_capture_param);
                VAPP_CAMCO_STOP_LOGGING("ADD");                
            }
            else if(capmode == VAPP_CAMCO_CAPMODE_BEST_SHOT)
            {
                VAPP_CAMCO_START_LOGGING("BSS");              
                ret = vapp_camco_cam_bestshot(&m_cam_capture_param);
                VAPP_CAMCO_STOP_LOGGING("BSS");                              
            }
            playCatureSound(ret);            
            
            if(capmode == VAPP_CAMCO_CAPMODE_BEST_SHOT)
                m_previewFrame->setBgColor(VFX_COLOR_BLACK);

            m_OSD->updateScreen();   
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
                if(m_state == VAPP_CAMCO_STATE_EXIT)
                    evt.filePath = g_vapp_camco_cam_prev_file_name;
                else
                    evt.filePath = m_camFileNameBuf;
                VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
                app->postToCaller((mmi_group_event_struct*)&evt);

            }
            else
            {
                if(isAppActive())
                {
                    showPopupScreen(ret, NULL, m_exitStateCB);                
                }
                else
                {
                    vappCamcoPopupParamStruct param;
                    param.next_state = VAPP_CAMCO_STATE_EXIT;                    
                    mmi_event_notify_enum popup_type;
                    VappCamcoPage::m_errStr = getMappingShownString(ret, &popup_type);                    
                    exitCamcoCUI(param);


                }            
                if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)                                
                    restoreFilename();
            }  
            vfx_adp_touch_fb_enable_tone();
            vfx_adp_touch_fb_enable_vibrate();            
        }
        else           
        {
            if (ret == MDI_RES_CAMERA_SUCCEED)
            {        
                setState(VAPP_CAMCO_STATE_CAM_CAPTURE);

    
                if(capmode == VAPP_CAMCO_CAPMODE_BEST_SHOT)   
                {
                    VAPP_CAMCO_START_LOGGING("DRA");                                    
                    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();                                 
                    drawCaptureImage(
                        m_previewFrame->getLayerHandle(), 
                        (void*)m_cam_capture_param.capture_buf_ptr, 
                        (VfxU32)m_cam_capture_param.capture_size);
                    m_previewFrame->invalidate();    
                    VAPP_CAMCO_STOP_LOGGING("DRA");                                        
                }
                m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_SAVING);
                m_osd_hint_state_param.isPreviewON = VFX_FALSE;
                m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
                m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
                m_osd_hint_state_param.isFWHorz = isHorzUI();
                m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
                m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;        
                m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;  
                
                
                m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
                m_OSD->updateScreen();
                
                enterState(VAPP_CAMCO_STATE_CAM_SAVE_DONE);

            }
            else
            {   
                if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)
                    restoreFilename();
                
                showPopupScreen(ret, NULL, m_recoverStateCB);                  
                
            }
        }

        
    }

};

void VappCamcoPage::enterCamSaveDoneState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_SAVE_DONE_STATE, m_state);

    vapp_camco_state_enum prev_state = m_state;

    vapp_camco_highlight_turn_off(&m_general_param);

    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();
		
    if (prev_state == VAPP_CAMCO_STATE_CAM_CAPTURE)
    {
        MDI_RESULT ret;    
        
        if (m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_BEST_SHOT)
        {
            VAPP_CAMCO_START_LOGGING("SAV");              
            ret = saveCapturedImage(m_camFileNameBuf, (void*)m_cam_capture_param.capture_buf_ptr, (VfxU32)m_cam_capture_param.capture_size);
            VAPP_CAMCO_STOP_LOGGING("SAV");                          
        }
        else
        {
            VAPP_CAMCO_START_LOGGING("SAV");                      
            ret = vapp_camco_cam_save_capture_image(&m_cam_capture_save_param);
            VAPP_CAMCO_STOP_LOGGING("SAV");                                      
        }    

        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            setState(VAPP_CAMCO_STATE_CAM_SAVE_DONE);
            
            VAPP_CAMCO_START_LOGGING("QIK"); 
            m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_NORMAL_SHOT;            
            m_osd_cam_quick_view_state_param.savedImg.bgColor = VRT_COLOR_TRANSPARENT;
            m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI();
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);            
            m_OSD->updateScreen();
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
            showPopupScreen(ret, NULL, m_recoverStateCB);
            return;
        }        
    }

};

void VappCamcoPage::enterCamContshotState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_CONTSHOT_STATE);

    setState(VAPP_CAMCO_STATE_CAM_CONTSHOT);
    m_osd_contshot_state_param.isHorzUI = isHorzUI(); 
    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_CONTSHOT, &m_osd_contshot_state_param, (VappCamcoOSDEvtHdlr*)this);
    m_OSD->updateScreen();
    
};

void VappCamcoPage::enterCamBurstshotState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_BURSTSHOT_STATE);

#ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HIDE, &m_osd_hide_state_param, (VappCamcoOSDEvtHdlr*)this);
    m_OSD->updateScreen();

    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();   

    VAPP_CAMCO_START_LOGGING("BUS");  
    MDI_RESULT result = vapp_camco_cam_burstshot(&m_cam_capture_param);
    VAPP_CAMCO_STOP_LOGGING("BUS");  
    
    playCatureSound(result);    

    if (result == MDI_RES_CAMERA_SUCCEED)
    {
        setState(VAPP_CAMCO_STATE_CAM_BURSTSHOT);

        m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_STITCHING);
        m_osd_hint_state_param.isPreviewON = VFX_FALSE;
        m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
        m_osd_hint_state_param.isFWHorz = isHorzUI();
        m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
        m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;        
        m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;  


        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
        m_OSD->updateScreen();
        vapp_camco_highlight_turn_off(&m_general_param);
    }
    else
    {          
        showPopupScreen(result, NULL, m_recoverStateCB);                          
    }

#ifndef __MTK_TARGET__ 
    vapp_camco_hw_result_callback_param_struct param;

    param.type = VAPP_CAMCO_CB_TYPE_BURSTSHOT;
    param.burstShotRet = MDI_RES_CAMERA_SUCCEED;
    param.burstShotCapturedCount = MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT;    

    resultHWCallback(param);
#endif

#endif
};

void VappCamcoPage::enterCamBurstshotSelectState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_BURSTSHOT_SELECT_STATE, m_state);

#ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__

    vapp_camco_bk_turn_off();

    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();
		
    if (m_state == VAPP_CAMCO_STATE_CAM_BURSTSHOT)
    {
        setState(VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT);   
        
        VAPP_CAMCO_START_LOGGING("QIK"); 
        m_osd_cam_quick_view_state_param.count = MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT;
        m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_BURST_SHOT;              
        m_osd_cam_quick_view_state_param.hiliteIdx = 0;
        m_osd_cam_quick_view_state_param.previewWindow = m_previewWindow;
        for (VfxU32 index = 0; index < MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT; index++)
        {            
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].drawingType = VAPP_CAMCO_DRAW_IMG_SRC_JPEG;        
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcJpgBuffAdress = (void*) m_cam_capture_param.burstShotJpgData->file_address[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].cacheBuffAdress = (void*) m_burstShot.cache_img_p[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcSize = m_cam_capture_param.burstShotJpgData->file_size[index];
        }
        m_osd_cam_quick_view_state_param.animationImg[0].cacheBuffAdress = m_appMemQuickViewBuffer;
        m_osd_cam_quick_view_state_param.animationImg[1].cacheBuffAdress = (VfxS8*)m_appMemQuickViewBuffer + (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL);        
        m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI();        
        
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_MULTI_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);        

        m_OSD->updateScreen();
        VAPP_CAMCO_STOP_LOGGING("QIK");      

    #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */         
        
    }
    else if (m_state == VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT)
    {       
        setState(VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT);   

        VAPP_CAMCO_START_LOGGING("QIK"); 
        m_osd_cam_quick_view_state_param.count = MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT;
        m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_BURST_SHOT;                      
        m_osd_cam_quick_view_state_param.hiliteIdx = 0;     
        for (VfxU32 index = 0; index < MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT; index++)
        {
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].drawingType = VAPP_CAMCO_DRAW_IMG_SRC_JPEG;        
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcJpgBuffAdress = (void*) m_cam_capture_param.burstShotJpgData->file_address[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].cacheBuffAdress = (void*) m_burstShot.cache_img_p[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcSize = m_cam_capture_param.burstShotJpgData->file_size[index];
        }
        m_osd_cam_quick_view_state_param.animationImg[0].cacheBuffAdress = m_appMemQuickViewBuffer;
        m_osd_cam_quick_view_state_param.animationImg[1].cacheBuffAdress = (VfxS8*)m_appMemQuickViewBuffer + (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL);                
        m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI();            
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_MULTI_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);        

        m_OSD->updateScreen();    
        VAPP_CAMCO_STOP_LOGGING("QIK");    
        
    }
    vapp_camco_bk_turn_off();    
#endif    
};

void VappCamcoPage::enterCamAebshotState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_AEBSHOT_STATE);

#ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HIDE, &m_osd_hide_state_param, (VappCamcoOSDEvtHdlr*)this);
    m_OSD->updateScreen();

    VAPP_CAMCO_START_LOGGING("AEB");  
    MDI_RESULT result = vapp_camco_cam_aebshot(&m_cam_capture_param);
    VAPP_CAMCO_STOP_LOGGING("AEB");      
    playCatureSound(result);    

    if (result == MDI_RES_CAMERA_SUCCEED)
    {
        setState(VAPP_CAMCO_STATE_CAM_AEBSHOT);
        
        enterState(VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT);

        vapp_camco_highlight_turn_off(&m_general_param);
    }
    else
    {   
        showPopupScreen(result, NULL, m_recoverStateCB);                  
        
    }
#endif
};

void VappCamcoPage::enterCamAebshotSelectState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_AEBSHOT_SELECT_STATE, m_state);

#ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__
    vapp_camco_bk_turn_off();

    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();
		
    if (m_state == VAPP_CAMCO_STATE_CAM_AEBSHOT)
    {
        setState(VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT);   

        VAPP_CAMCO_START_LOGGING("QIK"); 
        m_osd_cam_quick_view_state_param.count = MMI_CAMCO_FEATURE_CAM_AEBSHOT_IMAGE_COUNT;
        m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_EV_BEST_SHOT;                      
        m_osd_cam_quick_view_state_param.hiliteIdx = 0;
        m_osd_cam_quick_view_state_param.previewWindow = m_previewWindow;
        for (VfxU32 index = 0; index < MMI_CAMCO_FEATURE_CAM_AEBSHOT_IMAGE_COUNT; index++)
        {
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].drawingType = VAPP_CAMCO_DRAW_IMG_SRC_JPEG;        
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcJpgBuffAdress = (void*) m_cam_capture_param.aebShotJpgData->file_address[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].cacheBuffAdress = (void*) m_aebShot.cache_img_p[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcSize = m_cam_capture_param.aebShotJpgData->file_size[index];
        }
        m_osd_cam_quick_view_state_param.animationImg[0].cacheBuffAdress = m_appMemQuickViewBuffer;
        m_osd_cam_quick_view_state_param.animationImg[1].cacheBuffAdress = (VfxS8*)m_appMemQuickViewBuffer + (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL);                
        m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI(); 
        
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_MULTI_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);        

        m_OSD->updateScreen();
        VAPP_CAMCO_STOP_LOGGING("QIK");         

    #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */              
    }
    else if (m_state == VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT)
    {   
        setState(VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT);   

        VAPP_CAMCO_START_LOGGING("QIK"); 
        m_osd_cam_quick_view_state_param.count = MMI_CAMCO_FEATURE_CAM_AEBSHOT_IMAGE_COUNT;
        m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_EV_BEST_SHOT;               
        m_osd_cam_quick_view_state_param.hiliteIdx = 0;
        for (VfxU32 index = 0; index < MMI_CAMCO_FEATURE_CAM_AEBSHOT_IMAGE_COUNT; index++)
        {
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].drawingType = VAPP_CAMCO_DRAW_IMG_SRC_JPEG;        
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcJpgBuffAdress = (void*) m_cam_capture_param.aebShotJpgData->file_address[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].cacheBuffAdress = (void*) m_aebShot.cache_img_p[index];
            m_osd_cam_quick_view_state_param.capturedMultiShotImg[index].srcSize = m_cam_capture_param.aebShotJpgData->file_size[index];
        }
        m_osd_cam_quick_view_state_param.animationImg[0].cacheBuffAdress = m_appMemQuickViewBuffer;
        m_osd_cam_quick_view_state_param.animationImg[1].cacheBuffAdress = (VfxS8*)m_appMemQuickViewBuffer + (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * CAMCO_OSD_BYTE_PER_PIXEL);                
        m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI();    
        
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_MULTI_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);        

        m_OSD->updateScreen();    
        VAPP_CAMCO_STOP_LOGGING("QIK");               
    }
    vapp_camco_bk_turn_off();  
    
#endif
};

void VappCamcoPage::enterCamSmileDectState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_SMILEDECT_STATE);

    MDI_RESULT ret;  

    ret = vapp_camco_cam_sd_start(&m_cam_smiledetect_param);    
    if(ret == MDI_RES_CAMERA_SUCCEED)
    {
        setState(VAPP_CAMCO_STATE_CAM_SMILE_DECT);        
    #ifndef __MTK_TARGET__        
        m_smile_i = 0;        
    #endif

        vapp_camco_osd_screen_param_struct param;
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
    }
    else
    {
        showPopupScreen(ret, NULL, m_recoverStateCB);
    }

};

void VappCamcoPage::enterCamHDRShotState(void)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_HDRSHOT_STATE);

    MDI_RESULT ret;  
    
    mmi_wcscpy(g_vapp_camco_cam_hdr_prev_file_name, m_camFileNameBuf);

    if(getNextFilename(m_camSlaveFileNameBuf))
    {
        m_cam_hdr_shot_param.fileNameOrigin = m_camSlaveFileNameBuf;
        
        getNextFilename(m_camFileNameBuf);
        m_cam_hdr_shot_param.fileNameHDR= m_camFileNameBuf;        
        
        ret = vapp_camco_cam_hdr_shot_start(&m_cam_hdr_shot_param);   
        playCatureSound(ret); 

    }
    else
    {
        ret = VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND;
    }    
       
    
    if(ret == MDI_RES_CAMERA_SUCCEED)
    {    
        setState(VAPP_CAMCO_STATE_CAM_HDR_SHOT);        

        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HIDE, &m_osd_hide_state_param, (VappCamcoOSDEvtHdlr*)this);
        m_OSD->updateScreen();
        
        vapp_camco_highlight_turn_off(&m_general_param);        
    }
    else
    {
        if(ret != VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND)    
            restoreFilename();
        
        showPopupScreen(ret, NULL, m_recoverStateCB);
    }

}

void VappCamcoPage::enterCamHDRDoneState(void)
{
    //MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_CAM_HDRDONE_STATE);

    vapp_camco_state_enum prev_state = m_state;

    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();

    vapp_camco_highlight_turn_off(&m_general_param);

    if (prev_state == VAPP_CAMCO_STATE_CAM_HDR_SHOT)
    {
        MDI_RESULT ret;    
        
        ret = vapp_camco_cam_hdr_shot_save(&m_cam_hdr_shot_param);

        if (ret == MDI_RES_CAMERA_SUCCEED)
        {
            setState(VAPP_CAMCO_STATE_CAM_SAVE_DONE);

            m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_cam_quick_view_state_param.type = VAPP_CAMCO_OSD_QV_EVT_NORMAL_SHOT;            
            m_osd_cam_quick_view_state_param.savedImg.bgColor = VRT_COLOR_TRANSPARENT;
            m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI();
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_CAMERA_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);            
            m_OSD->updateScreen();

        }
        else
        {
            restoreFilename();
            showPopupScreen(ret, NULL, m_recoverStateCB);
            return;
        }        
    }

};

void VappCamcoPage::enterRecPreviewState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_PREVIEW_STATE, 0);

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
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_PREVIEW_STATE, 1);
        
        if(m_Setting->isNeedRestartPreview())
        {
            vapp_camco_rec_preview_stop(&m_rec_preview_stop_param);
        }
        
        initPreviewWindow();

        m_osd_rec_preview_state_param.previewWindow = m_previewWindow;
        m_osd_rec_preview_state_param.isCleanModeEnter = !m_isFirstEnterPreview;
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
        m_osd_rec_preview_state_param.previousFileName = m_recFileNameBuf;        
        m_osd_rec_preview_state_param.isRestartEnter = VFX_TRUE;                    
        m_isFirstEnterPreview = VFX_FALSE;        
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW, &m_osd_rec_preview_state_param, (VappCamcoOSDEvtHdlr*)this);    
        m_OSD->clean();
        m_OSD->updateScreen();            

        m_restartPreviewCallback = m_recRestartPreviewCallback;
        m_isStartingPreview = VFX_TRUE;    

        vapp_camco_osd_screen_param_struct param;
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
        param.isBusy = VFX_TRUE;
        m_OSD->setScreenParam(param);           
        return;
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
    #endif
    }
    else
    {
        setState(VAPP_CAMCO_STATE_REC_PREVIEW);    
        if(!checkRemovableStorage()) 
        {
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.isFWHorz = isHorzUI();
            m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
            m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_REC_NO_CARD;        
            m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM;     
            
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);    
        }  
        else
        {
            m_osd_rec_preview_state_param.previewWindow = m_previewWindow;
            m_osd_rec_preview_state_param.isCleanModeEnter = !m_isFirstEnterPreview;
            m_osd_rec_preview_state_param.recordableTime= (getFreeStorageSize() / m_rec_est_size_param.size);     
            m_osd_rec_preview_state_param.previousFileName = m_recFileNameBuf;        
            m_osd_rec_preview_state_param.isRestartEnter = VFX_FALSE;                   
            m_isFirstEnterPreview = VFX_FALSE;                  
            m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW, &m_osd_rec_preview_state_param, (VappCamcoOSDEvtHdlr*)this);    
            m_OSD->clean();
            m_OSD->updateScreen();  

            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS;
            m_OSD->setScreenParam(param);
            // no restart preview but need to update size info or it will be clean
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
            
            vapp_camco_osd_screen_param_struct renainSizeparam;        
            renainSizeparam.type = VAPP_CAMCO_OSD_SCR_PARAM_REC_REMAIN_SIZE_UPDATE;
            renainSizeparam.remain_size = (freeSpace / m_rec_est_size_param.size);

            if(freeSpace < m_rec_est_size_param.size * 0.5 && m_osd_rec_preview_state_param.indicatorStringID == 0)
                renainSizeparam.indicator_string = FMGR_FS_DISK_FULL_TEXT;
            else
                renainSizeparam.indicator_string = m_osd_rec_preview_state_param.indicatorStringID;    
            VappCamcoPage::m_errStr = renainSizeparam.indicator_string;            
            
            m_OSD->setScreenParam(renainSizeparam);            
        }        
    }

    if(m_state == VAPP_CAMCO_STATE_REC_PREVIEW)
    {
    
        m_hwFlag.isRecSaveSuccess  = VFX_FALSE;     
        m_hwFlag.isRecordFailed = VFX_FALSE;  

        if(m_Setting->getValue(VAPP_CAMCO_SETTING_HIGHLIGHT) == VAPP_CAMCO_HIGHLIGHT_ON)    
        {
            vapp_camco_highlight_turn_on(&m_general_param);
        }
        else
        {
            vapp_camco_highlight_turn_off(&m_general_param);
        }            
    }

};

void VappCamcoPage::enterRecPreviewFailedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_PREVIEW_FAILED_STATE);

    setState(VAPP_CAMCO_STATE_REC_PREVIEW_FAILED);

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_PREVIEW_FAILED);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.isFWHorz = isHorzUI();
    m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;        
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT;

    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);        

    m_OSD->updateScreen();

};


void VappCamcoPage::enterRecFocusingState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_FOCUSING_STATE);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)

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
            param.focus.center_x = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_x + m_osd_rec_preview_state_param.previewWindow.getX() - (m_osd_rec_preview_state_param.previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_y + m_osd_rec_preview_state_param.previewWindow.getY() - (m_osd_rec_preview_state_param.previewWindow.getHeight()>>1);
            param.index = idx;

            m_OSD->setScreenParam(param);
        }
        af_active_zone = af_active_zone >> 1;
    }

    m_OSD->updateScreen();           

#endif
};

void VappCamcoPage::enterRecFocusedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_FOCUSED_STATE);

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)

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
            param.focus.center_x = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_x + m_osd_rec_preview_state_param.previewWindow.getX() - (m_osd_rec_preview_state_param.previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_y + m_osd_rec_preview_state_param.previewWindow.getY() - (m_osd_rec_preview_state_param.previewWindow.getHeight()>>1);
            param.index = idx;

            m_OSD->setScreenParam(param);
            
        }
        else if (af_active_zone & 0x00000001)
        {
            vapp_camco_osd_screen_param_struct param;
            param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING;
            param.focus.w = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_x + m_osd_rec_preview_state_param.previewWindow.getX() - (m_osd_rec_preview_state_param.previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.rec_af_zone.af_zone[idx].af_zone_y + m_osd_rec_preview_state_param.previewWindow.getY() - (m_osd_rec_preview_state_param.previewWindow.getHeight()>>1);
            param.index = idx;

            m_OSD->setScreenParam(param);
        }

        af_success_zone = af_success_zone >> 1;
        af_active_zone = af_active_zone >> 1;
    }

    m_OSD->updateScreen();     
#endif
};


void VappCamcoPage::enterRecRecordingState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_RECORDING_STATE, m_state);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;     

    if (m_state == VAPP_CAMCO_STATE_REC_PAUSE)
    {
        MDI_RESULT result;

        m_osd_recording_state_param.previewWindow = m_previewWindow;         
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING, &m_osd_recording_state_param, (VappCamcoOSDEvtHdlr*)this);         
        m_OSD->updateScreen();
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
            m_OSD->updateScreen();            
    
        }
        else if (result == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
        {
            m_record.rec_progress_ratio = 100;
            vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);
            m_OSD->updateScreen();               
            kal_sleep_task(100);

            vappCamcoPopupParamStruct param;
            param.next_state = VAPP_CAMCO_STATE_REC_SAVING;            
            
            if((vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S ||
               (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
            {            
                showPopupScreen(MDI_RES_VDOREC_REACH_TIME_LIMIT, &param, m_enterStateCB);
            }
            else
            {
                showPopupScreen(MDI_RES_VDOREC_REACH_SIZE_LIMIT, &param, m_enterStateCB);            
            }
            
        }
        else if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            vappCamcoPopupParamStruct param;
            param.next_state = VAPP_CAMCO_STATE_REC_SAVING;            
            showPopupScreen(result, &param, m_enterStateCB);        
        }
        else
        {
            /* Camcorder is in VAPP_CAMCO_STATE_REC_PAUSE */
            m_hwFlag.isOnRecord = VFX_FALSE;
            showPopupScreen(result, NULL, m_recoverStateCB);              
        }

    }
    else
    {
        MDI_RESULT result;
        
        m_record.rec_time = 0;
        m_record.rec_size = 0;        
        m_record.rec_progress_ratio = 0;

        m_osd_recording_state_param.previewWindow = m_previewWindow;   
        m_osd_recording_state_param.isPreviewHorz = m_isOSDHorz;        
        m_osd_recording_state_param.isPreviewMirror = m_isOSDMirror;          
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING, &m_osd_recording_state_param, (VappCamcoOSDEvtHdlr*)this);            
        m_OSD->updateScreen();

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
                showPopupScreen(result, NULL, m_exitStateCB);                        
            }
            else
            {
                showPopupScreen(result, NULL, m_recoverStateCB);          
            }                
        }


    }
};

void VappCamcoPage::enterRecPauseState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_PAUSE_STATE);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;     

    MDI_RESULT result;

    m_recordUpdateTimer->stop();       
    
    m_osd_pause_state_param.recTime = m_record.rec_time;
    m_osd_pause_state_param.recSize = m_record.rec_size;    
    m_osd_pause_state_param.previewWindow = m_previewWindow;    
    m_osd_pause_state_param.isPreviewHorz = m_osd_recording_state_param.isPreviewHorz;    
    m_osd_pause_state_param.isPreviewMirror = m_osd_recording_state_param.isPreviewMirror;      
    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_PAUSE, &m_osd_pause_state_param, (VappCamcoOSDEvtHdlr*)this);         
    m_OSD->updateScreen();

    result = vapp_camco_rec_record_pause(&m_rec_record_param);

    srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, m_backlightBeforeRecording);
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

    if (result == MDI_RES_VDOREC_SUCCEED)
    {
        setState(VAPP_CAMCO_STATE_REC_PAUSE);

    }
    else if (result == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
    {
        m_record.rec_progress_ratio = 100;
        vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);
        m_OSD->updateScreen();               
        kal_sleep_task(100);
        
        vappCamcoPopupParamStruct param;
        param.next_state = VAPP_CAMCO_STATE_REC_SAVING;            

        if((vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_15S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_30S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_60S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_300S ||
           (vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT) == VAPP_CAMCO_LIMIT_TIME_600S)
        {            
            showPopupScreen(MDI_RES_VDOREC_REACH_TIME_LIMIT, &param, m_enterStateCB);
        }
        else
        {
            showPopupScreen(MDI_RES_VDOREC_REACH_SIZE_LIMIT, &param, m_enterStateCB);            
        }        

    }
    else if (result == MDI_RES_VDOREC_DISK_FULL)
    {
        vappCamcoPopupParamStruct param;
        param.next_state = VAPP_CAMCO_STATE_REC_SAVING;            
        showPopupScreen(result, &param, m_enterStateCB);        
    }
    else
    {
        /* Camcorder is in VAPP_CAMCO_STATE_REC_PAUSE */
        m_hwFlag.isOnRecord = VFX_FALSE;
        showPopupScreen(result, NULL, m_recoverStateCB);              
    }


};
void VappCamcoPage::enterRecSavingState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_SAVING_STATE);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE; 

    VAPP_CAMCO_START_LOGGING("SAV"); 
    vapp_camco_rec_record_stop(&m_rec_record_param);
    vapp_camco_rec_save_video(&m_rec_record_save_param);
    
    vapp_camco_highlight_turn_off(&m_general_param);

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
        m_osd_hint_state_param.isFWHorz = isHorzUI();
        m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
        m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;        
        m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;
            
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);         
        m_OSD->updateScreen();        
    }
    else
    {
        restoreFilename();
        showPopupScreen(MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED, NULL, m_recoverStateCB);        
    }

};

void VappCamcoPage::enterRecSaveDoneState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_REC_SAVE_DONE_STATE);

    MDI_RESULT ret;

    setState(VAPP_CAMCO_STATE_REC_SAVE_DONE);   

    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();

    vapp_camco_highlight_turn_off(&m_general_param);

    m_rec_fetch_param.fileName = m_recFileNameBuf;     
    m_rec_fetch_param.isRecWithHorzUI = m_osd_recording_state_param.isPreviewHorz;
    m_rec_fetch_param.isRecWithMirrorUI = m_osd_recording_state_param.isPreviewMirror;    

    VAPP_CAMCO_STOP_LOGGING("SAV"); 
    VAPP_CAMCO_START_LOGGING("SHO"); 
    ret = vapp_camco_rec_fetch_frame(&m_rec_fetch_param);
    if(ret == MDI_RES_CAMERA_SUCCEED)
    {
        m_OSD->updateScreen();        
            
        m_osd_rec_quick_view_state_param.savedImg.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
        m_osd_rec_quick_view_state_param.savedImg.bgColor = VRT_COLOR_TRANSPARENT;
        m_osd_rec_quick_view_state_param.isHorzUI = isHorzUI();    
        m_OSD->enterState(VAPP_CAMCO_OSD_STATE_VIDEO_QUICK_VIEW, &m_osd_rec_quick_view_state_param, (VappCamcoOSDEvtHdlr*)this);         
    
        m_OSD->updateScreen();         
    }
    else
    {
        restoreFilename();     
        showPopupScreen(ret, NULL, m_recoverStateCB);           
    }
    VAPP_CAMCO_STOP_LOGGING("SHO");     
};

void VappCamcoPage::enterEnterFailState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ENTER_ENTER_FAIL_STATE);

    setState(VAPP_CAMCO_STATE_ENTER_FAIL);

    // show with horz screen
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(VappCamcoPage::m_errStr);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.isFWHorz = isHorzUI();
    m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
    m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;    
    m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT;
        
    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);         
    m_OSD->updateScreen();        

    resetMem();

    m_errorExitTimer->start();

}

void VappCamcoPage::resultHWCallback(vapp_camco_hw_result_callback_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK, param.type, m_state);

    switch (param.type)
    {
        case VAPP_CAMCO_CB_TYPE_BURSTSHOT:
        {
            if (m_state != VAPP_CAMCO_STATE_CAM_BURSTSHOT)
            {
                return;
            }            
            if (param.burstShotCapturedCount < MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT && param.burstShotRet == MDI_RES_CAMERA_SUCCEED)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 0, 1);
                return;
            }
            else if (param.burstShotRet != MDI_RES_CAMERA_SUCCEED)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 0, 2);            
                showPopupScreen(param.burstShotRet, NULL, m_recoverStateCB);                             
                return;
            }
                        
            if (param.burstShotCapturedCount == MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT && param.burstShotRet == MDI_RES_CAMERA_SUCCEED)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 0, 3);            
                m_hwFlag.isBurstshotFinish = VFX_TRUE;
                enterState(VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT);
            }
            
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_CAM_HDRSHOT__
        case VAPP_CAMCO_CB_TYPE_HDRSHOT_CAPTURE:    
        {
            if(param.HDRresult == MDI_RES_CAMERA_SUCCEED)    
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 6, 0);                 
                m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_CAMCO_STITCHING);
                m_osd_hint_state_param.isPreviewON = VFX_FALSE;
                m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
                m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_TRANSPARENT;
                m_osd_hint_state_param.isFWHorz = isHorzUI();
                m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
                m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_CAM_HDR_PROCESSING;        
                m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_HINT;  

                m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);
                m_OSD->updateScreen();            
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 6, param.HDRresult);                
                showPopupScreen(param.HDRresult, NULL, m_recoverStateCB);                 
            }            
            break;
        }
        case VAPP_CAMCO_CB_TYPE_HDRSHOT_PROCESS:    
        {
            if(param.HDRresult == MDI_RES_CAMERA_SUCCEED)    
            {            
                U8* dst_p;

                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 7, 0);                 
                
                gdi_handle handleT = m_previewFrame->getLayerHandle();
                gdi_layer_push_and_set_active(handleT);
                gdi_layer_get_buffer_ptr(&dst_p);            
                gdi_layer_pop_and_restore_active();            
                
                memcpy((void*)dst_p, (void*)param.buffer_address, param.buffer_size);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 7, param.HDRresult);                
                showPopupScreen(param.HDRresult, NULL, m_recoverStateCB);                 
            }              
            break;
        }   
        case VAPP_CAMCO_CB_TYPE_HDRSHOT_DONE:
        {  
            if(param.HDRresult == MDI_RES_CAMERA_SUCCEED)    
            {                       
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 8, 0);                            
                enterState(VAPP_CAMCO_STATE_CAM_HDR_DONE);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 8, param.HDRresult);                
                showPopupScreen(param.HDRresult, NULL, m_recoverStateCB);                 
            }               
            break;
        }               
    #endif        
        case VAPP_CAMCO_CB_TYPE_CAM_AF:
        {
        #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
            if (m_state == VAPP_CAMCO_STATE_CAM_FOCUSING && !m_hwFlag.isTakepicFailed)
            {
                if (param.afRet.af_result == MDI_AF_SEARCH_STATUS_FOUND_SUCCESS)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 2, 0); 
                    
                    m_autofocus_param.af_success_zone = param.afRet.af_success_zone;
                    
                    playAutofocusSuccessSound();
                    m_hwFlag.isAFsuccess = VFX_TRUE;

                    enterState(VAPP_CAMCO_STATE_CAM_FOCUSED);
                }
                else if (param.afRet.af_result == MDI_AF_SEARCH_STATUS_SWITCH_MACRO)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 2, 1);                 
                    
                    vapp_camco_osd_screen_param_struct af_param;
                    af_param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
                    af_param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_MACRO;
                    m_OSD->setScreenParam(af_param);
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 2, 2);                 
                    
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
                            af_param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_osd_cam_preview_state_param.previewWindow.getX() - (m_osd_cam_preview_state_param.previewWindow.getWidth()>>1);
                            af_param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_osd_cam_preview_state_param.previewWindow.getY() - (m_osd_cam_preview_state_param.previewWindow.getHeight()>>1);
                            af_param.index = idx;

                            m_OSD->setScreenParam(af_param);
                        }
                        af_active_zone = af_active_zone >> 1;
                    }                
                }
                m_OSD->updateScreen();
            }     
        #endif
            break;
        }  
        case VAPP_CAMCO_CB_TYPE_REC_AF:
        {
        #if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
            if (m_state == VAPP_CAMCO_STATE_REC_FOCUSING && !m_hwFlag.isTakepicFailed)
            {
                if (param.recAfRet.af_result == MDI_AF_SEARCH_STATUS_FOUND_SUCCESS)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 3, 0);  
                    
                    m_autofocus_param.af_success_zone = param.recAfRet.af_success_zone;
                    
                    playAutofocusSuccessSound();
                    m_hwFlag.isAFsuccess = VFX_TRUE;

                    enterState(VAPP_CAMCO_STATE_REC_FOCUSED);
                }
                else if (param.recAfRet.af_result == MDI_AF_SEARCH_STATUS_SWITCH_MACRO)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 3, 1);                  
                    
                    vapp_camco_osd_screen_param_struct af_param;
                    af_param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS;
                    af_param.focus.type = VAPP_CAMCO_OSD_FOCUS_TYPE_MACRO;
                    m_OSD->setScreenParam(af_param);
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 3, 2);                  
                    
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
                            af_param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_osd_rec_preview_state_param.previewWindow.getX() - (m_osd_rec_preview_state_param.previewWindow.getWidth()>>1);
                            af_param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_osd_rec_preview_state_param.previewWindow.getY() - (m_osd_rec_preview_state_param.previewWindow.getHeight()>>1);
                            af_param.index = idx;

                            m_OSD->setScreenParam(af_param);
                        }
                        af_active_zone = af_active_zone >> 1;
                    }                
                }
                m_OSD->updateScreen();
            }   
        #endif
            break;
        }         
        case VAPP_CAMCO_CB_TYPE_RECORD_FINISH:
        {
            m_hwFlag.isOnRecord = VFX_FALSE;
            m_hwFlag.isPreviewStart = VFX_FALSE;

            m_recordUpdateTimer->stop();

            srv_backlight_set_real_level(SRV_BACKLIGHT_TYPE_MAINLCD, m_backlightBeforeRecording);
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

            if (param.recordRet == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 4, 0);                
                
                vapp_camco_osd_screen_param_struct recUpdateParam;
                recUpdateParam.type = VAPP_CAMCO_OSD_SCR_PARAM_RECORDING_UPDATE;
                vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);     
                vapp_camco_rec_record_get_size(&recUpdateParam.rec_size);
                recUpdateParam.rec_time = m_record.rec_time;
                m_record.rec_progress_ratio = 100;                
                
                m_OSD->setScreenParam(recUpdateParam);

                cleanPreviewScreen();

                vappCamcoPopupParamStruct popupParam;
                popupParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
                showPopupScreen(param.recordRet, &popupParam, m_enterStateCB);                  
            }
            else if(param.recordRet == MDI_RES_VDOREC_REACH_TIME_LIMIT)
            {
                vapp_camco_osd_screen_param_struct recUpdateParam;
                recUpdateParam.type = VAPP_CAMCO_OSD_SCR_PARAM_RECORDING_UPDATE;
                vapp_camco_rec_record_get_time((VfxU64*)&m_record.rec_time);     
                vapp_camco_rec_record_get_size(&recUpdateParam.rec_size);
                recUpdateParam.rec_time = m_record.rec_time;
                m_record.rec_progress_ratio = 100;                
                
                m_OSD->setScreenParam(recUpdateParam);

                cleanPreviewScreen();
                
                vappCamcoPopupParamStruct popupParam;
                popupParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
                showPopupScreen(MMI_CAMCO_REC_REACH_TIME_LIMIT, &popupParam, m_enterStateCB);               
            }
            else if (param.recordRet >= MDI_RES_VDOREC_SUCCEED)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 4, 1);                            
                
                vappCamcoPopupParamStruct popupParam;
                popupParam.next_state = VAPP_CAMCO_STATE_REC_SAVING;
                showPopupScreen(param.recordRet, &popupParam, m_enterStateCB); 
            }            
            else 
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 4, 2);                            
                
                showPopupScreen(param.recordRet, NULL, m_recoverStateCB);                                     
            }           
            break;
        }
        case VAPP_CAMCO_CB_TYPE_RECORD_SAVE:
        {
            m_hwFlag.isRecSaveCallback = VFX_TRUE;
            m_recordSaveResult = param.recordRet;

            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESULT_HW_CALLBACK_EVENT, 5, m_recordSaveResult);     

            if (m_isExtCalling)
            {         

                if (m_recordSaveResult >= MDI_RES_VDOREC_SUCCEED)
                {                
                    vcui_camco_event_struct evt;
                
                    MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_CAMCO_EVENT_RESULT_SUCCESS,  m_appID);
                    if(m_state == VAPP_CAMCO_STATE_EXIT)
                        evt.filePath = g_vapp_camco_rec_prev_file_name;
                    else                    
                        evt.filePath = m_recFileNameBuf;
                    
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
                        showPopupScreen(m_recordSaveResult, NULL, m_exitStateCB); 
                        restoreFilename();                            
                    }
                    else
                    {
                        vappCamcoPopupParamStruct param;
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
                    m_isSaveBeforeLeave = VFX_FALSE;
                    setState(VAPP_CAMCO_STATE_REC_SAVE_DONE);
                    exit();
                }
                else if (m_state == VAPP_CAMCO_STATE_REC_SAVING)
                {
                    if (m_recordSaveResult == MDI_RES_VDOREC_SUCCEED)
                    {
                        enterState(VAPP_CAMCO_STATE_REC_SAVE_DONE);
                    }
                    else
                    {
                        restoreFilename();                         
                        m_hwFlag.isRecordFailed = VFX_TRUE;                       
                        showPopupScreen(m_recordSaveResult, NULL, m_recoverStateCB);                            
                    }
                }
            }            
            break;
        }
        default:
            ASSERT(0);
    }
}

VfxBool VappCamcoPage::isSlientMode(void)
{
#ifdef __MMI_CAMCO_SILENT_MODE_SUPPORT__
    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == TRUE)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ISSLIENTMODE, 1);       
        return MMI_TRUE;
    }
    else
    {

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ISSLIENTMODE, 0);       
        return MMI_FALSE;
    }
#else /* __MMI_CAMCO_SILENT_MODE_SUPPORT__ */     
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_ISSLIENTMODE, 0);   
    return MMI_FALSE;
#endif /* __MMI_CAMCO_SILENT_MODE_SUPPORT__ */ 
}

void VappCamcoPage::initCountDownSound(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_INITCOUNTDOWNSOUND);   

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_DEINITCOUNTDOWNSOUND);   

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


void VappCamcoPage::playAutofocusSuccessSound(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_PLAY_AUTOFOCUS_SUCCESS_SOUND);   

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

void VappCamcoPage::playCatureSound(MDI_RESULT cap_ret)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_PLAY_CATURE_SOUND);   

    U32 aud_len;
    U8 *aud_data = NULL;
    U8 aud_type;
    
    if (cap_ret != MDI_RES_CAMERA_SUCCEED || isSlientMode())
    {
        return;
    }

    switch (m_Setting->getValue(VAPP_CAMCO_SETTING_SHUTTERSOUND))
    {
        case VAPP_CAMCO_SHUTTERSOUND_OFF:
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_1:
            aud_data = get_audio((U16) (AUD_ID_VAPP_CAMCO_CAPTURE_1), &aud_type, &aud_len);
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_2:
            aud_data = get_audio((U16) (AUD_ID_VAPP_CAMCO_CAPTURE_2), &aud_type, &aud_len);
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_3:
            aud_data = get_audio((U16) (AUD_ID_VAPP_CAMCO_CAPTURE_3), &aud_type, &aud_len);
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

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

MDI_RESULT  VappCamcoPage::saveCapturedImage(WCHAR *filename, void *imageBuffer, VfxU32 imageBufferSize)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 0);

#ifdef __MTK_TARGET__

    FS_HANDLE file_handle;
    U32 written;
    S32 fs_ret = 0;
    MMI_BOOL is_error_handle_done = MMI_FALSE;
    MDI_RESULT result = VAPP_CAMCO_ERR_SAVE_FAIL;

    file_handle = FS_Open((U16*) filename, FS_CREATE | FS_READ_WRITE);

    if (file_handle > 0)
    {
        fs_ret = FS_Write(file_handle, (void*)imageBuffer, imageBufferSize, (U32*) & written);
        FS_Close(file_handle);

        if(fs_ret == FS_MSDC_READ_SECTOR_ERROR || fs_ret == FS_MSDC_WRITE_SECTOR_ERROR  || fs_ret == FS_MEDIA_CHANGED)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 3);            
        }            
        /* cant write in whole file, must be disk full */
        else if (imageBufferSize != written)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 3);         
            
            /* delete the file that is not save complete */
            FS_Delete((U16*) filename);

            result = MDI_RES_CAMERA_ERR_DISK_FULL;
            is_error_handle_done = MMI_TRUE;
        }
        else if (fs_ret == 0)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 1);             
            result = MDI_RES_CAMERA_SUCCEED;
        }
    }

    if (file_handle < 0 || (fs_ret < 0 && !is_error_handle_done))
    {

        if (file_handle == FS_DISK_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 4);         
            result = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_ROOT_DIR_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 5);         
            result = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_WRITE_PROTECTION)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 6);         
            result = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, 7);         
            result = VAPP_CAMCO_ERR_SAVE_FAIL;
        }
    }

    return result;
#else
    return MDI_RES_CAMERA_SUCCEED;    
#endif
}

void VappCamcoPage::drawCaptureImage(gdi_handle handleT, void *imageBuffer, VfxU32 imageBufferSize)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_DRAW_CAPTURE_IMAGE, 0);  

    S32 image_width;
    S32 image_height;
    S32 result;
    S32 offset_x;
    S32 offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;

    m_previewFrame->setBgColor(VFX_COLOR_BLACK);
    
    gdi_layer_push_and_set_active(handleT);

    result = gdi_image_jpeg_get_dimension(
                (U8*)imageBuffer,
                imageBufferSize,
                &image_width,
                &image_height);
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, result);  

    if (result >= 0)
    {
        if ((m_previewWindow.size.width >= image_width) && (m_previewWindow.size.height >= image_height))
        {
            /* align preview window at the center of screen */
            offset_x = ((m_previewWindow.size.width - image_width) >> 1);
            offset_y = ((m_previewWindow.size.height - image_height) >> 1);

            result = gdi_image_jpeg_draw(
                        offset_x, 
                        offset_y, 
                        (U8*)imageBuffer, 
                        imageBufferSize);
            
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, result);            
        }
        else
        {
            gdi_image_util_fit_bbox(
                    m_previewWindow.size.width,
                    m_previewWindow.size.height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
            
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, resized_offset_x);    
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, resized_offset_y);    
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, resized_width);    
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, resized_height);                

            result = gdi_image_jpeg_draw_resized(
                        resized_offset_x,
                        resized_offset_y,
                        resized_width,
                        resized_height,
                        (U8*)imageBuffer,
                        imageBufferSize);
            
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SAVE_CAPTURED_IMAGE, result);                
        }
    }
    gdi_layer_pop_and_restore_active();

}

void VappCamcoPage::Capture(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_COUNTDOWNLEDTURNOFF, m_state, -1);     

    if (m_state != VAPP_CAMCO_STATE_CAM_PREVIEW &&
        m_state != VAPP_CAMCO_STATE_CAM_SMILE_DECT &&
        m_state != VAPP_CAMCO_STATE_CAM_FOCUSING &&
        m_state != VAPP_CAMCO_STATE_CAM_FOCUSED &&
        m_state != VAPP_CAMCO_STATE_CAM_COUNTDOWN)
    {
        return;
    }
    U16 capmode = m_Setting->getValue(VAPP_CAMCO_SETTING_CAPMODE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_COUNTDOWNLEDTURNOFF, m_state, capmode); 

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__  
    if (capmode == VAPP_CAMCO_CAPMODE_ADD_FRAME)
    {

        VfxU8 overlay_palette_size = 0;
        VfxU32 *overlay_palette_addr = NULL;
        
        vapp_camco_draw_add_frame(
            m_appAddFrameLayerBuffer,
            m_overlayPalette,     
            (VfxU16) m_Setting->getSettingStatusIcon(VAPP_CAMCO_SETTING_ADDFRAME_FRAME), 
            &overlay_palette_size, 
            &overlay_palette_addr);    

        vapp_camco_set_add_frame(overlay_palette_addr, m_appAddFrameLayerBuffer);
    }    
#endif    

    vapp_camco_background_calculation_stop(&m_cam_bg_process_param);

    m_osd_cam_quick_view_state_param.isHorzCapture = m_isOSDHorz;
    m_osd_cam_quick_view_state_param.isMirrorCapture = m_isOSDMirror;

    if (capmode == VAPP_CAMCO_CAPMODE_CONT_SHOT)
    {
        enterState(VAPP_CAMCO_STATE_CAM_CONTSHOT);
    }
    else if (capmode == VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL)
    {
    #ifdef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__                
        enterState(VAPP_CAMCO_STATE_CAM_BURSTSHOT);
    #endif            
    }
    else if (capmode == VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL)
    {
    #ifdef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__                
        enterState(VAPP_CAMCO_STATE_CAM_AEBSHOT);
    #endif            
    }
    else if (capmode == VAPP_CAMCO_CAPMODE_HDR_SHOT)
    {
    #ifdef __MMI_CAMCO_FEATURE_CAM_HDRSHOT__     
        enterState(VAPP_CAMCO_STATE_CAM_HDR_SHOT);
    #endif
    }    
    else
    {
        enterState(VAPP_CAMCO_STATE_CAM_CAPTURE);  
    }

    vapp_camco_background_calculation_start(&m_cam_bg_process_param);    
    
}

void VappCamcoPage::autoFocusToneCyclic(VfxTimer *source) 
{
    VFX_OBJ_CLOSE(source);

    if(m_isAFTonePlaying)
    {
        m_isAFTonePlaying = VFX_FALSE;
    }
}

void VappCamcoPage::recordToneCyclic(VfxTimer *source) 
{
    m_isTonePlaying = VFX_FALSE;

    vapp_camco_osd_screen_param_struct param;
    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY;
    param.isBusy = VFX_FALSE;
    m_OSD->setScreenParam(param);
    
    if(m_state != VAPP_CAMCO_STATE_REC_PREVIEW && m_state != VAPP_CAMCO_STATE_REC_FOCUSING && m_state != VAPP_CAMCO_STATE_REC_FOCUSED)
        return;
        
    enterState(VAPP_CAMCO_STATE_REC_RECORDING);
}

void VappCamcoPage::sceneDetectCyclic(VfxTimer *source) 
{
#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
#ifdef VAPP_CAMCO_MODIS_PIC_PREVIEW    
    return;
#endif

    if(m_isDelayPreview || m_isStartingPreview)
    {
        m_sceneDetectCycTimer->start();           
        return;
    }

    if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW)
    {
        vapp_camco_cam_scenedetect_get_result(&m_cam_scene_param);

        ((CamSceneModeSetting*)(m_Setting->getSetting(VAPP_CAMCO_SETTING_CAMSCENEMODE)))->setActiveValue(m_cam_scene_param.currentScene);

        vapp_camco_osd_screen_param_struct param; 
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_SCN_UPDATE;            
        m_OSD->setScreenParam(param); 
        
        m_OSD->updateScreen();

        m_sceneDetectCycTimer->start();     
    }
#endif
}

void VappCamcoPage::smiledetectSuccess(VfxTimer *source) 
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SMILEDETECT_SUCCESS); 

    // because we need to show the last frame with smiel rect
    // so we call capture with timer not function call
    Capture();
}

void VappCamcoPage::smiledetectCyclic(VfxTimer *source) 
{
    VAPP_CAMCO_START_LOGGING("SMI"); 

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SMILEDETECT_CYCLIC, m_state, 0); 

    if(m_isDelayPreview || m_isStartingPreview)
    {
        m_smileDetectCycTimer->start();           
        return;
    }
    
#if defined(__SMILE_SHUTTER_SUPPORT__)  

    vapp_camco_osd_screen_param_struct param;    
    
    if(m_state == VAPP_CAMCO_STATE_CAM_SMILE_DECT)
        m_cam_smiledetect_param.isSmileDetectON = VFX_TRUE;
    else if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW || m_state == VAPP_CAMCO_STATE_CAM_FOCUSED || m_state == VAPP_CAMCO_STATE_CAM_FOCUSING)
        m_cam_smiledetect_param.isSmileDetectON = VFX_FALSE;
    else
        return;
    
    vapp_camco_cam_smiledetect_get_result(&m_cam_smiledetect_param);

    if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW || m_state == VAPP_CAMCO_STATE_CAM_FOCUSED || m_state == VAPP_CAMCO_STATE_CAM_FOCUSING || m_state == VAPP_CAMCO_STATE_CAM_SMILE_DECT)
    {
        // face detect part            
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_FD;            
        m_OSD->setScreenParam(param);     

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SMILEDETECT_CYCLIC, m_state, m_cam_smiledetect_param.fd_result);        
        
        if (m_cam_smiledetect_param.fd_result == MDI_RES_CAMERA_SUCCEED)
        {

            for (VfxU32 idx = 0; idx < m_cam_smiledetect_param.fd_searched_num; idx++)
            {         
                if(idx == 0)
                {
                    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FD;
                    param.fd.type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED;
                    param.index = idx;                    
                    param.fd.x= m_cam_smiledetect_param.fd_zone[idx].fd_zone_x - (m_cam_smiledetect_param.fd_zone[idx].fd_zone_w>>1) + m_previewFrame->getPos().x - (m_previewFrame->getSize().width>>1);
                    param.fd.y= m_cam_smiledetect_param.fd_zone[idx].fd_zone_y - (m_cam_smiledetect_param.fd_zone[idx].fd_zone_h>>1) + m_previewFrame->getPos().y - (m_previewFrame->getSize().height>>1);
                    param.fd.w= m_cam_smiledetect_param.fd_zone[idx].fd_zone_w;
                    param.fd.h= m_cam_smiledetect_param.fd_zone[idx].fd_zone_h;
                    
                    m_OSD->setScreenParam(param);                    
                }                    
                else
                {
                    param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_FD;
                    param.fd.type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_TRACKING;
                    param.index = idx;                    
                    param.fd.x= m_cam_smiledetect_param.fd_zone[idx].fd_zone_x - (m_cam_smiledetect_param.fd_zone[idx].fd_zone_w>>1) + m_previewFrame->getPos().x - (m_previewFrame->getSize().width>>1);
                    param.fd.y= m_cam_smiledetect_param.fd_zone[idx].fd_zone_y - (m_cam_smiledetect_param.fd_zone[idx].fd_zone_h>>1) + m_previewFrame->getPos().y - (m_previewFrame->getSize().height>>1);
                    param.fd.w= m_cam_smiledetect_param.fd_zone[idx].fd_zone_w;
                    param.fd.h= m_cam_smiledetect_param.fd_zone[idx].fd_zone_h;
                    
                    m_OSD->setScreenParam(param);
           
                }
            }
        }    
        
        if(m_state == VAPP_CAMCO_STATE_CAM_PREVIEW || m_state == VAPP_CAMCO_STATE_CAM_FOCUSED || m_state == VAPP_CAMCO_STATE_CAM_FOCUSING)
            m_smileDetectCycTimer->start();     
    }
    if (m_state == VAPP_CAMCO_STATE_CAM_SMILE_DECT)
    {
        // smile detect part

    #ifndef __MTK_TARGET__      
        m_smile_i++;
    #endif    
        vapp_camco_osd_screen_param_struct param;   
    
        param.type = VAPP_CAMCO_OSD_SCR_PARAM_RESET_SD;            
        m_OSD->setScreenParam(param);        

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SMILEDETECT_CYCLIC, m_state,  m_cam_smiledetect_param.sd_end_flag);        

        if (m_cam_smiledetect_param.sd_end_flag)
        {

            for (VfxU32 idx = 0; idx < m_cam_smiledetect_param.sd_searched_num; idx++)
            {
                param.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_SD;
                param.sd.type = VAPP_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED;
                param.index = idx;                
                param.sd.x= m_cam_smiledetect_param.fd_zone[idx].sd_zone_x - (m_cam_smiledetect_param.fd_zone[idx].sd_zone_w>>1) + m_previewFrame->getPos().x - (m_previewFrame->getSize().width>>1);
                param.sd.y= m_cam_smiledetect_param.fd_zone[idx].sd_zone_y - (m_cam_smiledetect_param.fd_zone[idx].sd_zone_h>>1)+ m_previewFrame->getPos().y - (m_previewFrame->getSize().height>>1);
                param.sd.w= m_cam_smiledetect_param.fd_zone[idx].sd_zone_w;
                param.sd.h= m_cam_smiledetect_param.fd_zone[idx].sd_zone_h;
                
                m_OSD->setScreenParam(param);                
            }
        }

        m_OSD->updateScreen();

        if (m_cam_smiledetect_param.sd_end_flag)
        {
            VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
            renderer->mustShowNextFrame();               
            m_smileDetectSuccessTimer->start();       
        }
        else
        {
            m_smileDetectCycTimer->start();            
        }
    #ifndef __MTK_TARGET__  
        if(m_smile_i == 50)
        {
            Capture();        
        }
    #endif        
    }
#endif    

    VAPP_CAMCO_STOP_LOGGING("SMI"); 

}

void VappCamcoPage::countdownCyclic(VfxTimer *source) 
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_COUNTDOWN_CYCLIC, m_countdownDuration,  0);  

    VfxU16 highlight;
    double tick_elapsed;

    highlight = m_Setting->getValue(VAPP_CAMCO_SETTING_HIGHLIGHT);

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
        if (highlight == VAPP_CAMCO_HIGHLIGHT_ON)
        {
            vapp_camco_highlight_turn_on(&m_general_param);
        }
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_COUNTDOWN_CYCLIC, m_countdownDuration,  (VfxU32)((m_countdownDuration/2000.0) * 250 + 250));          

        countdownLedTimer->start();   
        
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
        countdownLedTimer->stop();
        if (highlight == VAPP_CAMCO_HIGHLIGHT_ON)
        {
            vapp_camco_highlight_turn_on(&m_general_param);
        }
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

    switch ((vapp_camco_limit_enum)m_Setting->getValue(VAPP_CAMCO_SETTING_LIMIT))
    {
        case VAPP_CAMCO_LIMIT_NO_LIMIT:
            break;

        case VAPP_CAMCO_LIMIT_TIME_15S:
            m_record.rec_progress_ratio = (U16) (m_record.rec_time * 100) / MMI_CAMCO_REC_TIME_LIMIT_1;
            break;

        case VAPP_CAMCO_LIMIT_TIME_30S:
            m_record.rec_progress_ratio = (U16) (m_record.rec_time * 100) / MMI_CAMCO_REC_TIME_LIMIT_2;
            break;

        case VAPP_CAMCO_LIMIT_TIME_60S:
            m_record.rec_progress_ratio = (U16) (m_record.rec_time * 100) / MMI_CAMCO_REC_TIME_LIMIT_3;
            break;

        case VAPP_CAMCO_LIMIT_TIME_300S:
            m_record.rec_progress_ratio = (U16) (m_record.rec_time * 100) / MMI_CAMCO_REC_TIME_LIMIT_4;
            break;

        case VAPP_CAMCO_LIMIT_TIME_600S:
            m_record.rec_progress_ratio = (U16) (m_record.rec_time * 100) / MMI_CAMCO_REC_TIME_LIMIT_5;
            break;

        case VAPP_CAMCO_LIMIT_SIZE_95K:
            m_record.rec_progress_ratio = (U16) (rec_size * 100) / MMI_CAMCO_REC_SIZE_LIMIT_1;
            break;

        case VAPP_CAMCO_LIMIT_SIZE_195K:
            m_record.rec_progress_ratio = (U16) (rec_size * 100) / MMI_CAMCO_REC_SIZE_LIMIT_2;
            break;

        case VAPP_CAMCO_LIMIT_SIZE_295K:
            m_record.rec_progress_ratio = (U16) (rec_size * 100) / MMI_CAMCO_REC_SIZE_LIMIT_3;
            break;

        default:
            break;
    }
    
    // external calling may with special limitation
    if(m_isExtCalling && ((LimitSetting*)(m_Setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getTimeLimit() > 0)
    {
        VfxU32 L = ((LimitSetting*)(m_Setting->getSetting(VAPP_CAMCO_SETTING_LIMIT)))->getTimeLimit();    

        m_record.rec_progress_ratio = (U16) (m_record.rec_time * 100) / L;
    }
    
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

void VappCamcoPage::countdownLedTurnOff(VfxTimer *source) 
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_COUNTDOWNLEDTURNOFF);       
    vapp_camco_highlight_turn_off(&m_general_param);
}

VfxBool VappCamcoPage::isAppActive(void)
{
    if ((isInCall() ||
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0)) ||
        (srv_reminder_is_expiring()) || 
        m_state == VAPP_CAMCO_STATE_EXIT)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_APP_ACTIVE, 0);       
        return VFX_FALSE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_APP_ACTIVE, 1);       
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
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_APP_ACTIVE, 1);           
        return VFX_TRUE;
    }
    else
#endif /* !defined(__RF_DESENSE_TEST__) */ 
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_IS_APP_ACTIVE, 0);           
        return VFX_FALSE;
    }
}

VfxU16 VappCamcoPage::getMappingShownString(MDI_RESULT result, mmi_event_notify_enum *popup_type)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_MAPPING_SHOWN_STRING, result); 

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

        case MMI_CAMCO_REC_REACH_TIME_LIMIT:
            *popup_type = MMI_EVENT_INFO;
            return STR_ID_VAPP_CAMCO_NOTIFY_REACH_TIME_LIMIT;
            //break;

        case MDI_RES_VDOREC_ERR_NO_DISK:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_CAMCO_NOTIFY_STORAGE_NOT_READY;
            //break;

        case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
        case MDI_RES_VDOREC_ERR_WRITE_PROTECTION:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_CAMCO_NOTIFY_WRITE_PROTECT;
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
        case MDI_RES_VDOREC_ERR_NO_FRAME_ENCODED:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_GLOBAL_FAILED_TO_SAVE;
            //break;
            
        default:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_GLOBAL_ERROR;
            //break;

    }

}

void VappCamcoPage::showPopupScreen(MDI_RESULT result, void * param, VappCamcoPopupCallbackFunc callback)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SHOW_POPUP_SCREEN, result, param); 
    U16 string_id;
    srv_prof_tone_enum tone_type = SRV_PROF_TONE_WARNING;

    if(result != 0)
    {
        mmi_event_notify_enum popup_type;
        string_id = getMappingShownString(result, &popup_type);
        if(!param)
        {    
            VappCamcoPage::m_errStr = string_id;
        }
        srv_prof_tone_enum tone_type = mmi_get_event_based_sound(popup_type);

        m_CurrentPopupShownresult = result;
    }
    else
    {
        string_id = VappCamcoPage::m_errStr;    
        tone_type = mmi_get_event_based_sound(MMI_EVENT_FAILURE);        
    }

    if(param)    
        memcpy(&m_popupParam, param,sizeof(vappCamcoPopupParamStruct)); 
    m_popupCallback = callback;    
    
    if (tone_type != NONE_TONE)
    {
        srv_prof_play_tone(tone_type, NULL);
    }    
    
    if(!param)
    {
        if(!m_hwFlag.isPreviewStart)
            cleanPreviewScreen();
    }
    m_osd_hint_state_param.hintText = VFX_WSTR_RES(string_id);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_CAMCO_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    if(param)
    {
        m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_OTHERS;    
        m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING;    
    }        
    else
    {
        m_osd_hint_state_param.event = VAPP_CAMCO_OSD_HINT_EVT_ERROR;    
        m_osd_hint_state_param.type = VAPP_CAMCO_OSD_HINT_TYPE_NOTIFY;   
    }        
    m_osd_hint_state_param.isFWHorz = isHorzUI();
    m_osd_hint_state_param.isHorzUI = m_isOSDHorz;            
        
    m_OSD->enterState(VAPP_CAMCO_OSD_STATE_HINT, &m_osd_hint_state_param, (VappCamcoOSDEvtHdlr*)this);                  
    m_OSD->updateScreen();                

    vapp_camco_highlight_turn_off(&m_general_param);    
    if(param)
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_STOP_POPUP_SCREEN, m_isPopupRunning); 

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_POPUP_CALLBACK); 

    m_isPopupRunning = VFX_FALSE;
    m_popupCallback.invoke(m_popupParam);
}

void VappCamcoPage::popupRecovercallback(vappCamcoPopupParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_POPUP_RECOVERCALLBACK, m_state); 

    ClearKeyEvents();

    switch (m_state)
    {
        case VAPP_CAMCO_STATE_CAM_PREVIEW:
        case VAPP_CAMCO_STATE_CAM_COUNTDOWN:
        case VAPP_CAMCO_STATE_CAM_FOCUSING:
        case VAPP_CAMCO_STATE_CAM_FOCUSED:
        case VAPP_CAMCO_STATE_CAM_BURSTSHOT:
        case VAPP_CAMCO_STATE_CAM_CAPTURE:
        case VAPP_CAMCO_STATE_CAM_SAVE_DONE:
        case VAPP_CAMCO_STATE_CAM_SMILE_DECT:
        case VAPP_CAMCO_STATE_CAM_BURSTSHOT_SELECT:    
        case VAPP_CAMCO_STATE_CAM_AEBSHOT_SELECT:            
        case VAPP_CAMCO_STATE_CAM_HDR_SHOT:                  
        case VAPP_CAMCO_STATE_CAM_HDR_DONE:                              
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

void VappCamcoPage::exitCamcoCUI(vappCamcoPopupParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXIT_CAMCO_CUI); 

    vcui_camco_event_struct evt;
    
    MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_CAMCO_EVENT_RESULT_FAILED,  m_appID);
    evt.filePath = NULL;
    VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
    app->postToCaller((mmi_group_event_struct*)&evt);

}

void VappCamcoPage::popupEntercallback(vappCamcoPopupParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_POPUP_ENTER_CALLBACK, param.next_state); 

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

mmi_ret VappCamcoPage::sensorChangeNotifyHdlr(mmi_event_struct *evt)
{
    mmi_frm_auto_rotate_evt_struct *rotateEvt = (mmi_frm_auto_rotate_evt_struct*)evt;

    vapp_camco_osd_screen_param_struct rotParam;
    VappCamcoPage* obj = (VappCamcoPage *)evt->user_data;

    if(obj->m_isStartingApp)
        return MMI_RET_OK;
    
    rotParam.type = VAPP_CAMCO_OSD_SCR_PARAM_SET_ROT;

    if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER &&
       obj->m_Setting->getValue(VAPP_CAMCO_SETTING_VISCODEC) == VAPP_CAMCO_VISCODEC_3GP)
    {
        if(obj->m_Setting->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
        {
            rotParam.isHorz = VFX_TRUE;
            rotParam.isMirror = VFX_FALSE;
        }
        else
        {
            rotParam.isHorz = VFX_FALSE;
            rotParam.isMirror = VFX_FALSE;
        }
    }
    else
    {
        switch (rotateEvt->new_degree)
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
    }
    obj->m_isOSDHorz = rotParam.isHorz;
    obj->m_isOSDMirror = rotParam.isMirror;    

    obj->m_OSD->setScreenParam(rotParam);

    return MMI_RET_OK;

}

mmi_ret VappCamcoPage::fontChangeNotigyHdlr(mmi_event_struct *evt)
{
    VappCamcoPage* obj = (VappCamcoPage *)evt->user_data;

    if(obj->m_Setting->getCurrApp() == VAPP_CAMCO_APP_RECORDER &&
       (obj->m_state == VAPP_CAMCO_STATE_REC_RECORDING || obj->m_state == VAPP_CAMCO_STATE_REC_PAUSE || obj->m_state == VAPP_CAMCO_STATE_REC_SAVING))
    {
        obj->m_isFontChanged = VFX_TRUE;
    }

    return MMI_RET_OK;
}

mmi_ret VappCamcoPage::storageChangeNotifyHdlr(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_STORAGE_NOTIFY);

    VappCamcoPage* obj = (VappCamcoPage *)evt->user_data;

    if(obj->m_isStartingApp)
        return MMI_RET_OK;

    switch(evt->evt_id)
    {
        
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct* event = (srv_fmgr_notification_dev_plug_event_struct*)evt;
            U8 drive = obj->m_Setting->getStorage();
            
            for (VfxU8 i = 0; i < event->count; i++)
            {
                if (event->drv_letters[i] == drive)
                {
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
            srv_fmgr_notification_dev_plug_event_struct* event = (srv_fmgr_notification_dev_plug_event_struct*)evt;
            U8 drive = obj->m_Setting->getStorage();
            
            for (VfxU8 i = 0; i < event->count; i++)
            {
                if (event->drv_letters[i] == drive)
                {
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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_USB_NOTIFY);

    VappCamcoPage *pThis = (VappCamcoPage*)param->user_data;

    if(pThis->m_isStartingApp)
        return MMI_RET_OK;
    
    if(pThis->m_isExtCalling)
    {
        vcui_camco_event_struct evt;
        
        MMI_FRM_INIT_GROUP_EVENT(&evt, VCUI_CAMCO_EVENT_RESULT_FAILED,  pThis->getApp()->getGroupId());
        evt.filePath = NULL;
        VfxCui *app = VFX_OBJ_DYNAMIC_CAST(pThis->getApp(), VfxCui);
        app->postToCaller((mmi_group_event_struct*)&evt);

    }
    else
    {
        VappCamcoApp *app = VFX_OBJ_DYNAMIC_CAST(pThis->getApp(), VappCamcoApp);    
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
#define CAMCO_TEMP_BUFFER_LENGTH_A    (50)
#define CAMCO_MAX_FILE_NUM          (20000)

    CHAR buffer[CAMCO_TEMP_BUFFER_LENGTH_A];
    WCHAR *storageBuffer;
    WCHAR wcsBuffer[CAMCO_TEMP_BUFFER_LENGTH_A];
    WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH_A];
    VfxU16 filename_seq_no;
    VfxU16 start_no;
    FS_HANDLE file_handle;
    VfxU32 startTicks, endTicks;
    
    kal_get_time(&startTicks);

    if(m_Setting->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        mmi_wcscpy(g_vapp_camco_cam_prev_file_name, m_camFileNameBuf); 

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
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_GETNEXTFILENAME, filename_seq_no); 

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
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_GETNEXTFILENAME, -1);                
                return VFX_TRUE;
            }
            
            filename_seq_no++;
            if (filename_seq_no > 20000)    /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
            
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_GETNEXTFILENAME, filename_seq_no); 
            if(start_no == filename_seq_no)
                return VFX_FALSE;

            // prevent MMI from taking too long time on finding the next file name
            kal_get_time(&endTicks);
            if((endTicks - startTicks) * 4.615  > 1300)
            {
                m_camStartingFilenameIdx = filename_seq_no;
                return VFX_FALSE;
            }                
        }while(1);
    
    }
    else
    {
        mmi_wcscpy(g_vapp_camco_rec_prev_file_name, m_recFileNameBuf);  

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
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_GETNEXTFILENAME, filename_seq_no); 
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
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_GETNEXTFILENAME, -1);                
                return VFX_TRUE;
            }
            
            filename_seq_no++;
            if (filename_seq_no > 20000)    /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
            
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_GETNEXTFILENAME, filename_seq_no); 
            if(start_no == filename_seq_no)
                return VFX_FALSE;
            
            // prevent MMI from taking too long time on finding the next file name
            kal_get_time(&endTicks);
            if((endTicks - startTicks) * 4.615  > 1000)
            {
                m_recStartingFilenameIdx = filename_seq_no;            
                return VFX_FALSE;
            }                            
        }while(1);    
    }

    //return VFX_FALSE;
}

void VappCamcoPage::restoreFilename(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESTOREFILENAME, 0); 

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
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESTOREFILENAME, filename_seq_no);        
        m_camStartingFilenameIdx = filename_seq_no;
        mmi_wcscpy(m_camFileNameBuf, g_vapp_camco_cam_prev_file_name); 
        
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
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_RESTOREFILENAME, filename_seq_no);   
        m_recStartingFilenameIdx = filename_seq_no;
        mmi_wcscpy(m_recFileNameBuf, g_vapp_camco_rec_prev_file_name);         
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


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


VtstTestResultEnum vtst_rt_camco_launch(VfxU32 param)
{
    vapp_camco_launch_app();
    return VTST_TR_OK;

}

// ==========================================================================================
// Camcorder CUI
// ==========================================================================================
extern "C" void vcui_camcorder_struct_init(vcui_camco_param_struct *param)
{
    param->mode = VCUI_CAMCO_CAMERA;
    param->level = VCUI_CAMCO_SETTING_COMMON_ONLY;
    param->settingLimitNum = 0;
    param->settingLimitation = NULL;
}

extern "C" mmi_id vcui_camcorder_create(mmi_id parent_id, vcui_camco_param_struct *param)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
        VCUI_CAMCO,                           /* Cui's app id */
        VFX_OBJ_CLASS_INFO(VcuiCamcoApp),     /* Cui class */
        parent_id,                            /* parent group id */
        param,                                /* parameters, if any */  
        sizeof(vcui_camco_param_struct));     
    
    return cui_id;
}

extern "C" void vcui_camcorder_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}
    

extern "C" void vcui_camcorder_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

extern "C" vcui_camco_err_code_enum vcui_camcorder_launchable_check(void)
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

extern "C" MMI_ID vcui_camcorder_get_err_string(vcui_camco_err_code_enum errCode)
{
    return VappCamcoPage::m_errStr;
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

#ifdef __MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__
    *width_p = 4092;
    *height_p = 3070;
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
    if (g_vapp_camco_banding_setting == VAPP_CAMCO_BANDING_50HZ)
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
#define CAMCO_TEMP_BUFFER_LENGTH_B    (256)

    // init rec custom config setting
    custom_rec_set_table();

    VfxBool isGetnameSuccess = VFX_FALSE;
    FS_HANDLE file_handle;
    WCHAR drv_buf[8];
    CHAR buf[64];

    if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_SYSTEM_DRV, FS_MOUNT_STATE_ENUM))
    {
        WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH_B];

        sprintf((CHAR *)buf, "%c:\\", (U8)SRV_FMGR_SYSTEM_DRV);
        mmi_asc_to_wcs(drv_buf, (CHAR *)buf);

        mmi_wcscpy(wcsTestname, drv_buf);
        mmi_wcscat(wcsTestname, (const WCHAR *) L"cameraData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            U32 read_size;

            if (FS_Read(file_handle, (CHAR*)g_vapp_camco_cam_prev_file_name, 256*2, &read_size) >= 0)
            {
                isGetnameSuccess = VFX_TRUE;
            }
        }
        FS_Close(file_handle);
    }

    if(!isGetnameSuccess)
    {
        // init previous file name buffer
        memset(g_vapp_camco_cam_prev_file_name, 0, 512);
    }

    isGetnameSuccess = VFX_FALSE;

    if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_SYSTEM_DRV, FS_MOUNT_STATE_ENUM))
    {
        WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH_B];

        sprintf((CHAR *)buf, "%c:\\", (U8)SRV_FMGR_SYSTEM_DRV);
        mmi_asc_to_wcs(drv_buf, (CHAR *)buf);

        mmi_wcscpy(wcsTestname, drv_buf);
        mmi_wcscat(wcsTestname, (const WCHAR *) L"recorderData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            U32 read_size;

            if (FS_Read(file_handle, (CHAR*)g_vapp_camco_rec_prev_file_name, 256*2, &read_size) >= 0)
            {
                isGetnameSuccess = VFX_TRUE;
            }
        }
        FS_Close(file_handle);
    }

    if(!isGetnameSuccess)
    {
        // init previous file name buffer
        memset(g_vapp_camco_rec_prev_file_name, 0, 512);
    }

    memset(g_vapp_camco_cam_hdr_prev_file_name, 0, 512);

    return MMI_RET_OK;
}

VfxU16 vapp_camco_get_storage(void)
{
    return 0;
}


#ifdef __cplusplus
extern "C"
{
#endif

extern void mmi_camco_init_app(void)
{
};

//---------

#ifdef __cplusplus
}
#endif
#endif
