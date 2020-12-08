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

// for power off
#include "ShutdownSrvGprot.h"

#ifdef __cplusplus
}
#endif

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))

#include "AppMgrSrvGprot.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_autocap_gprot.h"
#include "vapp_autocap_app.h"
#include "vapp_autocap_hw.h"
#include "vapp_autocap_osd_mgr.h"
#include "vapp_autocap_osd_state.h"

#include "vtst_rt_main.h"

#include "vapp_gallery_gprot.h"

// for drag N center
#include "Vapp_ncenter_gprot.h"

// for env check interface
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#include "USBSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"
#endif
#ifdef __MMI_BT_SUPPORT__
//#include "vapp_bt_storage.h"
#endif

#include "vcui_camco_gprot.h"

#include "vapp_fmgr_table.h"
#include "mmi_rp_file_type_def.h"

extern vapp_autocap_banding_enum g_vapp_autocap_banding_setting;

MMI_ID VappAutoCapPage::m_errStr = 0;

vapp_autocap_global_config_struct g_vapp_autocap_config;
WCHAR g_vapp_autocap_prev_file_name[256] = {0};
WCHAR g_vapp_mav_prev_file_name[256] = {0};
WCHAR g_vapp_3d_camera_prev_file_name[256] = {0};

VFX_IMPLEMENT_CLASS("VappAutoCapApp", VappAutoCapApp, VfxApp);

void VappAutoCapApp::onInit(void)
{
    VfxApp::onInit();

}

void VappAutoCapApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappAutoCapScreen *scr;
    VFX_OBJ_CREATE(scr, VappAutoCapScreen, this); 
	if(args != NULL)
	{
        scr->setCallingParam((*(vapp_autocap_param_struct*)args));
	}
	else
	{
        vapp_autocap_param_struct param;
		param.isMultiAngleViewMode = KAL_FALSE;
		scr->setCallingParam(param);
	}
    scr->show();

}

VFX_IMPLEMENT_CLASS("VappAutoCapScreen", VappAutoCapScreen, VfxMainScr);

void VappAutoCapScreen::onInit()
{
    VfxMainScr::onInit();
    setBgColor(VFX_COLOR_BLACK);
}

void VappAutoCapScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    if(!m_param.isMultiAngleViewMode)
    {
        VappAutoCapPage *page;
        VFX_OBJ_CREATE(page, VappAutoCapPage, this);
        m_param.is3DCameraMode = MMI_FALSE;
        page->setCallingParam(m_param);
        pushPage(0, page);
    }
    else
    {
        // create and display first page
    #if defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
        VappAutoCapModeSelectPage *page;
        VFX_OBJ_CREATE(page, VappAutoCapModeSelectPage, this);
        m_pageId = pushPage(0, page);
    #elif defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && !defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
        VappAutoCapPage *page;
        VFX_OBJ_CREATE(page, VappAutoCapPage, this);
        m_param.is3DCameraMode = MMI_FALSE;
        page->setCallingParam(m_param);
        pushPage(0, page);
    #elif !defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
        VappAutoCapPage *page;
        VFX_OBJ_CREATE(page, VappAutoCapPage, this);
        m_param.is3DCameraMode = MMI_TRUE;
        page->setCallingParam(m_param);
        pushPage(0, page);
    #endif
    }
}

void VappAutoCapScreen::onEnter(VfxBool isBackward)
{
    VfxMainScr::onEnter(isBackward);

    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
}

void VappAutoCapScreen::onExit(VfxBool isBackward)
{
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, FALSE, VFX_SCR_TRANSIT_PRIORITY_USER);

    VfxMainScr::onExit(isBackward);
}

void VappAutoCapScreen::setCallingParam(vapp_autocap_param_struct param)
{
    m_param = param;
}


void VappAutoCapScreen::onRotate(const VfxScreenRotateParam &param)   
{
    VfxRect parentBounds = getParentFrame()->getBounds();

    setAnchor(0.5f, 0.5f);
    setPos(parentBounds.size.width / 2, parentBounds.size.height / 2);
    setSize(parentBounds.size);    
    //VfxMainScr::onRotate
}

VFX_IMPLEMENT_CLASS("VappAutoCapModeSelectPage", VappAutoCapModeSelectPage, VfxPage);

void VappAutoCapModeSelectPage::onInit()
{
    VfxPage::onInit(); 

#if defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)

    setBgColor(VfxColor(255, 48, 48, 48));

    VFX_OBJ_CREATE(m_reflection[0], VfxImageFrame, this);
    VFX_OBJ_CREATE(m_reflection[1], VfxImageFrame, this);
    VFX_OBJ_CREATE(m_mavMode, VcpImageButton, this);
    VFX_OBJ_CREATE(m_3DimageMode, VcpImageButton, this);
    VFX_OBJ_CREATE(m_mavName, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_3DimageName, VfxTextFrame, this);   

    m_reflection[0]->setAnchor(0.5, 0.3);
    m_reflection[0]->setImgContent(VfxImageSrc(IMG_ID_3D_CAMERA_REFLECTION_ICON));
    m_reflection[0]->setAutoAnimate(VFX_FALSE);
    m_reflection[0]->setIsUnhittable(VFX_TRUE);

    m_reflection[1]->setAnchor(0.5, 0.4);
    m_reflection[1]->setImgContent(VfxImageSrc(IMG_ID_3D_CAMERA_REFLECTION_ICON));
    m_reflection[1]->setAutoAnimate(VFX_FALSE);
    m_reflection[1]->setIsUnhittable(VFX_TRUE);

    VcpStateImage SI = VcpStateImage(MAIN_MENU_MAV_MODE_ICON,MAIN_MENU_MAV_MODE_ICON,MAIN_MENU_MAV_MODE_ICON,MAIN_MENU_MAV_MODE_ICON);

    m_mavMode->setFuzzy(VFX_TRUE);
    m_mavMode->setAnchor(0.5, 0.5);
    m_mavMode->setImage(SI);
    m_mavMode->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_mavMode->setAutoAnimate(VFX_FALSE);
    //m_mavMode->setIsEffect(VFX_TRUE);
    //m_mavMode->setEffectSize(m_mavMode->getSize());

    SI = VcpStateImage(MAIN_MENU_3D_IMAGE_MODE_ICON,MAIN_MENU_3D_IMAGE_MODE_ICON,MAIN_MENU_3D_IMAGE_MODE_ICON,MAIN_MENU_3D_IMAGE_MODE_ICON);

    m_3DimageMode->setFuzzy(VFX_TRUE);
    m_3DimageMode->setAnchor(0.5, 0.5);
    m_3DimageMode->setImage(SI);
    m_3DimageMode->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
    m_3DimageMode->setAutoAnimate(VFX_FALSE);
    //m_3DimageMode->setIsEffect(VFX_TRUE);
    //m_3DimageMode->setEffectSize(m_3DimageMode->getSize());
    
    m_mavName->setString(VFX_WSTR_RES(STR_ID_VAPP_AUTOCAP_MAV_MODE));
    m_mavName->setAnchor(0.5, 0.5);    
    m_mavName->setAutoAnimate(VFX_FALSE);
    m_mavName->setColor(VFX_COLOR_WHITE);
    VfxFontDesc font = m_mavName->getFont();
    font.effect = VFX_FONT_DESC_EFFECT_GRADIENT_DROP_SHADOW;
    m_mavName->setFont(font);
    
    m_3DimageName->setString(VFX_WSTR_RES(STR_ID_VAPP_AUTOCAP_3D_IMAGE_MODE));
    m_3DimageName->setAnchor(0.5, 0.5);
    m_3DimageName->setAutoAnimate(VFX_FALSE);
    m_3DimageName->setColor(VFX_COLOR_WHITE);
    font = m_3DimageName->getFont();
    font.effect = VFX_FONT_DESC_EFFECT_GRADIENT_DROP_SHADOW;
    m_3DimageName->setFont(font);

    m_mavMode->m_signalClicked.connect(this, &VappAutoCapModeSelectPage::onMAVClicked);
    m_3DimageMode->m_signalClicked.connect(this, &VappAutoCapModeSelectPage::on3DimageClicked);
#endif
}

void VappAutoCapModeSelectPage::onDeinit()
{
    VfxPage::onDeinit(); 
}

void VappAutoCapModeSelectPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward); 

    vapp_ncenter_disable_drag();

#if defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
    setSize(LCD_WIDTH, LCD_HEIGHT);
    m_mavMode->setPos(LCD_WIDTH / 2, LCD_HEIGHT / 4);
    m_reflection[0]->setPos(LCD_WIDTH / 2, LCD_HEIGHT / 4 + (m_mavMode->getSize().height / 2));
    m_3DimageMode->setPos(LCD_WIDTH / 2, 2 * LCD_HEIGHT / 3);
    m_reflection[1]->setPos(LCD_WIDTH / 2, (2 * LCD_HEIGHT / 3) + (m_3DimageMode->getSize().height / 2));    
    m_mavName->setPos(m_mavMode->getPos().x, m_mavMode->getPos().y + (m_mavMode->getSize().height/2) + m_mavName->getSize().height);
    m_3DimageName->setPos(m_3DimageMode->getPos().x, m_3DimageMode->getPos().y + (m_3DimageMode->getSize().height/2) + m_3DimageName->getSize().height);
#endif
}

void VappAutoCapModeSelectPage::onExit(VfxBool isBackward)
{
    vapp_ncenter_enable_drag();

    VfxPage::onExit(isBackward); 
}

void VappAutoCapModeSelectPage::onMAVClicked(VfxObject *obj, VfxId id)
{
#if defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
    VappAutoCapScreen* scr = (VappAutoCapScreen*)getMainScr();
    scr->m_param.is3DCameraMode = KAL_FALSE;
    
    VappAutoCapPage *page;
    VFX_OBJ_CREATE(page, VappAutoCapPage, scr);
    page->setCallingParam(scr->m_param);
    scr->pushPage(0, page);
    scr->closePage(scr->m_pageId);

    vapp_ncenter_enable_drag();
#endif
}

void VappAutoCapModeSelectPage::on3DimageClicked(VfxObject *obj, VfxId id)
{
#if defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
    VappAutoCapScreen* scr = (VappAutoCapScreen*)getMainScr();
    scr->m_param.is3DCameraMode = KAL_TRUE;
    
    VappAutoCapPage *page;
    VFX_OBJ_CREATE(page, VappAutoCapPage, scr);
    page->setCallingParam(scr->m_param);
    scr->pushPage(0, page);
    scr->closePage(scr->m_pageId);

    vapp_ncenter_enable_drag();
#endif
}

VFX_IMPLEMENT_CLASS("VappAutoCapPage", VappAutoCapPage, VfxPage);

void VappAutoCapPage::onAFTimerTick(VfxTimer *source)
{
#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
#ifndef __MTK_TARGET__


    vapp_autocap_hw_result_callback_param_struct param;

    if(m_af_i%2 == 0)
    {
        param.type = VAPP_AUTOCAP_CB_TYPE_CAM_AF;
        param.afRet.af_result = MDI_AF_SEARCH_STATUS_FOUND_FAIL;
    }
    else
    {
        param.type = VAPP_AUTOCAP_CB_TYPE_CAM_AF;
        param.afRet.af_result = MDI_AF_SEARCH_STATUS_FOUND_SUCCESS;    
        param.afRet.af_success_zone = 1;            
    }
    resultHWCallback(param);        
  
    m_af_i++;
    source->start();    
#endif 
#endif  
}

void VappAutoCapPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_INIT);

    VfxPage::onInit(); 

    VFX_OBJ_CREATE(m_previewFrame,VfxVideoFrame,this);       

#ifdef VAPP_AUTOCAP_MODIS_PIC_PREVIEW
    VFX_OBJ_CREATE(m_picturePreviewFrame,VfxFrame,this); 
    m_picturePreviewFrame->setSize(GDI_LCD_WIDTH*4.0/3.0, GDI_LCD_WIDTH);
    m_picturePreviewFrame->setAnchor(0, 0);
    m_picturePreviewFrame->setPos(0, 0);    
    m_picturePreviewFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    WCHAR fileName[30];
    CHAR fileNameAsc[15] = "";
    
    sprintf(fileNameAsc, "%c:\\1.bmp", SRV_FMGR_CARD_DRV);    
    mmi_asc_to_wcs(fileName, fileNameAsc);

    VfxImageSrc s = VfxImageSrc(VFX_WSTR_MEM(fileName));
    
    m_picturePreviewFrame->setImgContent(s);
    
#endif

    VFX_OBJ_CREATE(m_enterScreenOSD, AutoCapOSDStartingState, this);

    m_appID = getApp()->getGroupId();
    
    m_previewFrame->setAnchor(0.5, 0.5);
    m_previewFrame->setBgColor(VFX_COLOR_BLACK);
    m_previewFrame->setSize(GDI_LCD_HEIGHT, GDI_LCD_WIDTH);    
    m_previewFrame->setBuffer(m_appID);
    m_previewFrame->setAutoAnimate(VFX_FALSE);
    
    m_state = VAPP_AUTOCAP_STATE_EXIT;

    m_enterStateCB = VappAutoCapPopupCallbackFunc(this, &VappAutoCapPage::popupEntercallback);
    m_recoverStateCB = VappAutoCapPopupCallbackFunc(this, &VappAutoCapPage::popupRecovercallback);  

    m_camRestartPreviewCallback = VappAutoCapRestartCallbackFunc(this, &VappAutoCapPage::camRestartPreview);  
    m_camPanoRestartPreviewCallback = VappAutoCapRestartCallbackFunc(this, &VappAutoCapPage::camPanoRestartPreview);  
    m_dummyRestartPreviewCallback = VappAutoCapRestartCallbackFunc(this, &VappAutoCapPage::dummyRestartPreview); 

    setStatusBar(VFX_FALSE);  

    VFX_OBJ_CREATE(m_autoExitTimer, VfxTimer, this);    

    VFX_OBJ_CREATE(m_errorExitTimer, VfxTimer, this);   
    m_errorExitTimer->setStartDelay(1500);    
    m_errorExitTimer->m_signalTick.connect(this, &VappAutoCapPage::onErrorExitTimerTick);

    VFX_OBJ_CREATE(m_postEnterTimer, VfxTimer, this);      
    m_postEnterTimer->setStartDelay(250);       
    m_postEnterTimer->m_signalTick.connect(this, &VappAutoCapPage::onEntered); 

    VFX_OBJ_CREATE(m_delayPreviewTimer, VfxTimer, this);      
    m_delayPreviewTimer->setStartDelay(250);       
    m_delayPreviewTimer->m_signalTick.connect(this, &VappAutoCapPage::onPreviewFrameDoneDelayTick); 

    VFX_OBJ_CREATE(m_autoramraUpdateTimer, VfxTimer, this);      
    m_autoramraUpdateTimer->setStartDelay(15);       
    m_autoramraUpdateTimer->m_signalTick.connect(this, &VappAutoCapPage::onAutoramaUpdateTick); 
     
    VFX_OBJ_CREATE(m_popupTimer, VfxTimer, this);

    
    // init flag    
    m_hwFlag.isPowerOn          =   VFX_FALSE;   
    m_hwFlag.isPreviewStart     =   VFX_FALSE;      
    m_hwFlag.isAFon             =   VFX_FALSE;  
    m_hwFlag.isAFsuccess        =   VFX_FALSE;     
    m_hwFlag.isTakepicFailed    =   VFX_FALSE; 
    m_hwFlag.isHightlightOn     =   VFX_FALSE; 
    
    m_isOnForceHorz             =   VFX_FALSE;

    m_isPreemptable             =   VFX_TRUE;    
    m_isMainLcdPreview          =   VFX_TRUE;    
    m_isFirstEnterPreview       =   VFX_TRUE;    
    m_isDelayPreview            =   VFX_FALSE;
    m_isStartingPreview         =   VFX_FALSE; 

    m_isAppInited               =   VFX_FALSE;
    m_isStartingApp             =   VFX_TRUE;

    m_isHorzMAVMode             =   VFX_FALSE;

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

    // UT on MOIDS
    m_af_i = 0;
    m_smile_i = 0;   
    m_contshot_i = 0;
}

void VappAutoCapPage::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_DEINIT);

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

    // it may still onEnter not init OSD / Setting
    if(m_isStartingApp)
    {
        deinitEnv();
        
        VfxPage::onDeinit();

        return;
    }

    vapp_autocap_reset_hw_obj();

    enterState(VAPP_AUTOCAP_STATE_EXIT);

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
        if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
            mmi_wcscat(wcsTestname, (const WCHAR *) L"mavData.camco");
        else if(m_param.isMultiAngleViewMode && m_param.is3DCameraMode)
            mmi_wcscat(wcsTestname, (const WCHAR *) L"3DcameraData.camco");
        else
            mmi_wcscat(wcsTestname, (const WCHAR *) L"autoramaData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_CREATE_ALWAYS | FS_READ_WRITE);

        if (file_handle >= 0)
        {
            U32 write_size;
            CHAR * buffer;

            if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
                buffer = (CHAR *)g_vapp_mav_prev_file_name;
            else if(m_param.isMultiAngleViewMode && m_param.is3DCameraMode)
                buffer = (CHAR *)g_vapp_3d_camera_prev_file_name;
            else
                buffer = (CHAR *)g_vapp_autocap_prev_file_name;

            if (FS_Write(file_handle, (CHAR*)buffer, 256*2, &write_size) >= 0)
            {
                ASSERT(write_size == 256*2);
            }
        }
        FS_Close(file_handle);
    }

    VfxPage::onDeinit(); 

}

VfxBool VappAutoCapPage::isHorzUI(void)
{
    if(m_isStartingApp)
    {
        if(m_param.isMultiAngleViewMode)
        {
            if(m_isHorzMAVMode)
                return VFX_TRUE;
            else
                return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }
    }
#if defined (HORIZONTAL_CAMERA)
    if(m_isOnForceHorz)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, 1);          
        return VFX_TRUE;    
    }
    else if(m_state == VAPP_AUTOCAP_STATE_ENTER_FAIL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, 2);          
        return VFX_TRUE;    
    }
    else if(m_Setting->getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
    {
        if(m_param.isMultiAngleViewMode)
        {
            if(m_isHorzMAVMode)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, -1);
                return VFX_TRUE;
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, -3);
                return VFX_FALSE;
            }
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, 3);        
            return VFX_TRUE;
        }
    }
    else if(m_Setting->getCurrCam() == VAPP_AUTOCAP_SENSOR_SUB_CAMERA)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, -2);     
        return VFX_FALSE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, -1);     
        return VFX_FALSE;
    }
#else      
    if(m_isOnForceHorz)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, 1);          
        return VFX_TRUE;    
    }
    else if(m_state == VAPP_AUTOCAP_STATE_ENTER_FAIL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, 2);          
        return VFX_TRUE;    
    }
    else 
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_HZUI, -1);     
        return VFX_FALSE;
    }
#endif

}

void VappAutoCapPage::onErrorExitTimerTick(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_ERROR_EXIT_TIMER_TICK); 
    getApp()->exit();
}

void VappAutoCapPage::onQueryRotateEx(VfxScreenRotateParam &param)
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


void VappAutoCapPage::setCallingParam(vapp_autocap_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SET_CALLINGPARAM, 0);

    m_param = param;    
}


void VappAutoCapPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_EXIT, isBackward);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    // it may still onEnter not init OSD / Setting
    if(m_isStartingApp)
    {        
        m_state = VAPP_AUTOCAP_STATE_EXIT;
        
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
        case VAPP_AUTOCAP_STATE_PREVIEW:
        case VAPP_AUTOCAP_STATE_PREVIEW_FAILED:
        case VAPP_AUTOCAP_STATE_FOCUSING:
        case VAPP_AUTOCAP_STATE_FOCUSED:
            m_state = VAPP_AUTOCAP_STATE_INT_PREVIEW;
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_SHOT:
            m_state = VAPP_AUTOCAP_STATE_INT_PREVIEW;
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_STITCH:
            m_state = VAPP_AUTOCAP_STATE_INT_PREVIEW;        
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_DONE:
            m_state = VAPP_AUTOCAP_STATE_INT_PREVIEW;
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_CLIP:
            m_state = VAPP_AUTOCAP_STATE_INT_PREVIEW;
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE:
            m_state = VAPP_AUTOCAP_STATE_INT_PREVIEW;
            break;
            
        case VAPP_AUTOCAP_STATE_ENTER_FAIL:
            m_state = VAPP_AUTOCAP_STATE_EXIT;            
            break;

        case VAPP_AUTOCAP_STATE_EXIT:  
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


    vapp_autocap_power_off(&m_power_off_param);

    if (m_hwFlag.isHightlightOn)
    {
        vapp_autocap_highlight_turn_off(&m_general_param);
        m_Setting->setValue(VAPP_AUTOCAP_SETTING_HIGHLIGHT, VAPP_AUTOCAP_HIGHLIGHT_OFF);
    }

    m_Setting->storeSetting();
    m_Setting->storeSceneSetting(); 
    if(m_camFileNameBuf)
    {
        if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
            mmi_wcscpy(g_vapp_mav_prev_file_name, m_camFileNameBuf);             
        else if(m_param.isMultiAngleViewMode && m_param.is3DCameraMode)
            mmi_wcscpy(g_vapp_3d_camera_prev_file_name, m_camFileNameBuf);             
        else
            mmi_wcscpy(g_vapp_autocap_prev_file_name, m_camFileNameBuf); 
    }
    

    m_OSD->exitState();
    
    m_previewFrame->unPrepare();    
    m_delayPreviewTimer->stop();
    m_isStartingPreview = VFX_FALSE;
    m_isDelayPreview = VFX_FALSE;   

    ClearKeyEvents();

    decheckEnv();

    resetMem(); 

    VfxPage::onExit(isBackward); 

}

void VappAutoCapPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_ENTER, isBackward);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    VfxPage::onEnter(isBackward); 

    VappAutoCapPage::m_errStr = 0;    
    
    if(checkEnv())
    {
        initEnv();    

        // show a screen firstly
        m_isStartingApp = VFX_TRUE;
        // param for start state
        // 00 : Horz autorama
        // 01 : Vert autorama
        // 10 : Horz MAV
        // 11 : Vert MAV
        if(m_param.isMultiAngleViewMode)
        {
            VfxU8 isVertical;
            if(m_isHorzMAVMode)
                isVertical = 2;
            else
                isVertical = 3;
            m_enterScreenOSD->enterState((void*)&isVertical);
        }
        else
        {
            VfxU8 isVertical = 0;
            m_enterScreenOSD->enterState((void*)&isVertical);
        }
              
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();

        m_postEnterTimer->start();            
    }
    else
    {
        initApp();       
        enterState(VAPP_AUTOCAP_STATE_ENTER_FAIL);
    }    

}

void VappAutoCapPage::onEntered(VfxTimer *source) 
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_ENTER, 101);

    initApp();

    configMem();   

    if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
        mmi_wcscpy(m_camFileNameBuf, g_vapp_mav_prev_file_name);           
    else if(m_param.isMultiAngleViewMode && m_param.is3DCameraMode)
        mmi_wcscpy(m_camFileNameBuf, g_vapp_3d_camera_prev_file_name);         
    else
        mmi_wcscpy(m_camFileNameBuf, g_vapp_autocap_prev_file_name);

	m_enterScreenOSD->exitState();
    m_isStartingApp = VFX_FALSE;

    if(vapp_autocap_power_on(&m_power_on_param) == MDI_RES_CAMERA_SUCCEED)
    {
        // when the 1st power on and enter App
        // the rotation may be wrong (because we think it will be Horz)
        if((m_Setting->getValue(VAPP_AUTOCAP_SETTING_CAPSIZE) == VAPP_AUTOCAP_CAPSIZE_WALLPAPER || m_Setting->getCurrCam() == VAPP_AUTOCAP_SENSOR_SUB_CAMERA))
        {
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
        }

        if(m_state == VAPP_AUTOCAP_STATE_EXIT)
        {                                       
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);                    
        }
        else
        {
            recoverState(m_state);
        }
    }
    else
    {
        enterState(VAPP_AUTOCAP_STATE_PREVIEW_FAILED);                                        
    }
}

void VappAutoCapPage::exitState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_EXIT_STATE, m_state);   

    switch (m_state)
    {
        case VAPP_AUTOCAP_STATE_PREVIEW:
            if(!m_hwFlag.isTakepicFailed)
            {
                vapp_autocap_preview_stop(&m_preview_stop_param);               
            }
            break;

        case VAPP_AUTOCAP_STATE_PREVIEW_FAILED:
            break;


        case VAPP_AUTOCAP_STATE_FOCUSING:
        case VAPP_AUTOCAP_STATE_FOCUSED:
            if(!m_hwFlag.isTakepicFailed)
            {
                vapp_autocap_autofocus_stop(&m_autofocus_param);
                vapp_autocap_preview_stop(&m_preview_stop_param);
            }
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_SHOT:
            if(m_param.isMultiAngleViewMode)
            {
                vapp_autocap_mav_stop();
                restoreFilename();
            }
            else
            {
                vapp_autocap_reset_panorama_3a();
                vapp_autocap_preview_stop(&m_preview_stop_param);
                m_autoramraUpdateTimer->stop();
            }
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
            m_isPreemptable = MMI_TRUE;    
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_CLIP:
            vapp_autocap_panorama_stop_stitch();
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);            
            m_isPreemptable = MMI_TRUE;                
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE:
            if(m_param.isMultiAngleViewMode)
            {
                vapp_autocap_mav_stop();
                restoreFilename();
            }
            else
            {
                vapp_autocap_panorama_stop_stitch();
            }
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);            
            m_isPreemptable = MMI_TRUE;                
            break;


        case VAPP_AUTOCAP_STATE_AUTORAMA_STITCH:
            vapp_autocap_panorama_stop_stitch();
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
            m_isPreemptable = MMI_TRUE;    
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_DONE:
            break;
            
        case VAPP_AUTOCAP_STATE_ENTER_FAIL:
            m_errorExitTimer->stop();
            break;
        
        default:
            break;
    }

}

void VappAutoCapPage::enterState(vapp_autocap_state_enum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_STATE, state);   

    if(!srv_shutdown_is_running())       
        vapp_autocap_bk_turn_on();
    
    if(!m_isPreemptable)
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION); 
        m_isPreemptable = MMI_TRUE;
    } 
    
    /* Enter the next state */
    switch (state)
    {


        case VAPP_AUTOCAP_STATE_EXIT:
            enterExitState();
            break;

        case VAPP_AUTOCAP_STATE_PREVIEW:
            enterPreviewState();
            break;

        case VAPP_AUTOCAP_STATE_PREVIEW_FAILED:
            enterPreviewFailedState();
            break;

        case VAPP_AUTOCAP_STATE_FOCUSING:
            enterFocusingState();
            break;

        case VAPP_AUTOCAP_STATE_FOCUSED:
            enterFocusedState();
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_SHOT:
            enterAutoramaShotState();
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_STITCH:
            enterAutoramaStitchState();
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE:
            enterAutoramaEncodeState();
            break;                        

        case VAPP_AUTOCAP_STATE_AUTORAMA_DONE:
            enterAutoramaDoneState();
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_CLIP:
            enterAutoramaClipState();
            break;
            
        case VAPP_AUTOCAP_STATE_ENTER_FAIL:
            enterEnterFailState();
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

}


void VappAutoCapPage::recoverState(vapp_autocap_state_enum state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RECOVER_STATE, state, 0);   

    switch (state)
    {
        case VAPP_AUTOCAP_STATE_INT_PREVIEW:
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            break;

        case VAPP_AUTOCAP_STATE_AUTORAMA_STITCH:
            if (m_panoramaShot.is_stitch_done &&
                m_panoramaShot.stitch_ind.result == MDI_RES_CAMERA_SUCCEED)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RECOVER_STATE, state, 1);  
                enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            }
            else if (m_panoramaShot.is_stitch_done)
            {                    
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RECOVER_STATE, state, 2);  
                vappAutoCapPopupParamStruct param;
                param.next_state = VAPP_AUTOCAP_STATE_PREVIEW;
                showPopupScreen(m_panoramaShot.stitch_ind.result, &param, m_enterStateCB);        
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RECOVER_STATE, state, 3);  
                enterState(VAPP_AUTOCAP_STATE_AUTORAMA_STITCH);
            }
            break;

        default:
            //MMI_ASSERT(0);
            break;
    }

}    

VfxBool VappAutoCapPage::checkEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_USB_NOTIFY, -1);

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

    if (isInCall() /*&& m_state == VAPP_AUTOCAP_STATE_EXIT*/)
    {

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_USB_NOTIFY, 1);    
        
        VappAutoCapPage::m_errStr = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;

        return VFX_FALSE;
    }

#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {       
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_USB_NOTIFY, 2);          
        
        VcpPopupTypeEnum popupType;       
        VappAutoCapPage::m_errStr = vapp_usb_get_error_info(0, &popupType);
        
        return VFX_FALSE;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    return VFX_TRUE;
} 

VfxBool VappAutoCapPage::decheckEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_DECHECKENV);          

#if 0
#ifdef __MMI_BT_SUPPORT__
/* under construction !*/
#endif
#endif
    return VFX_TRUE;
} 


void VappAutoCapPage::configMem(void)
{

    VfxU32 appmem_size = 0;
    VfxU8* currentP;
    VfxU8* tempP;
    
    m_appMemQuickViewBuffer = NULL;    
    m_appMedMultiShotWorkingBuffer = NULL;

    m_camFileNameBuf = (WCHAR*)gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
    MMI_ASSERT(m_camFileNameBuf != NULL);
    memset(m_camFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);

    if(!m_param.isMultiAngleViewMode)
    {
        appmem_size =
            MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_CLIP_MEM_SIZE  +
            AUTOCAP_CAM_MULTISHOT_BUFFER_SIZE;

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CONFIG_MEM, appmem_size);

        m_appMemBuffer = applib_asm_alloc_nc_r(m_appID, appmem_size);

        if (m_appMemBuffer == NULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CONFIG_MEM, -1);
            return;
        }

        currentP = (VfxU8*)m_appMemBuffer;

        m_appMemQuickViewBuffer = currentP;
        currentP += MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_CLIP_MEM_SIZE;

        m_appMedMultiShotWorkingBuffer = currentP;
        currentP += AUTOCAP_CAM_MULTISHOT_BUFFER_SIZE;

    #if defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
        VfxU32 buffer_size = (MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_MEM_SIZE / MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT);
        tempP = (VfxU8*) m_appMedMultiShotWorkingBuffer;

        for (VfxU8 idx = 0; idx < MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT; idx++)
        {
            m_panoramaShot.capture_buffer_p[idx] = tempP;
            tempP += buffer_size;
        }
    #endif

        m_capture_param.quickviewBuffer = m_appMemQuickViewBuffer;
        m_panorama_stitch_param.workingBuffer = m_appMedMultiShotWorkingBuffer;
        m_panorama_stitch_param.quickViewBuffer = m_appMemQuickViewBuffer;

    #if defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
        buffer_size = ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * AUTOCAP_OSD_BYTE_PER_PIXEL) * 2) / (MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT);
        tempP = (VfxU8*)m_capture_param.quickviewBuffer;
        for (VfxU8 idx = 0; idx < MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT; idx++)
        {
            m_osd_cam_panorama_state_param.capturedPicture[idx].drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF;
            m_osd_cam_panorama_state_param.capturedPicture[idx].srcBuffAdress = (void*)tempP;
            m_osd_cam_panorama_state_param.capturedPicture[idx].srcWidth = g_vapp_autocap_skin.previousIconSize[0];
            m_osd_cam_panorama_state_param.capturedPicture[idx].srcHeight = g_vapp_autocap_skin.previousIconSize[1];
            tempP += buffer_size;
        }
    #endif
    }
}

void VappAutoCapPage::resetMem(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESET_MEM, m_appMemBuffer);    

    if(m_appMemBuffer)
        applib_asm_free_r(m_appID, m_appMemBuffer);
    m_appMemBuffer = NULL;
    
    m_appMedMultiShotWorkingBuffer = NULL;                

    gui_free(m_camFileNameBuf);
    m_camFileNameBuf = NULL;   
}

void VappAutoCapPage::initEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_INIT_ENV);        
    
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

void VappAutoCapPage::deinitEnv(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_DEINIT_ENV);    
    
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

VfxU64 VappAutoCapPage::getFreeStorageSize(void)
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


VfxBool VappAutoCapPage::checkRemovableStorage(void)
{      
    if(srv_fmgr_drv_is_removable(m_Setting->getStorage()) 
        && !srv_fmgr_drv_is_accessible(m_Setting->getStorage()))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_REMOVABLE_STORAGE, 0);      
        return VFX_FALSE;
    }        
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_REMOVABLE_STORAGE, 1);      
        return VFX_TRUE;        
    }        
}

VfxBool VappAutoCapPage::checkSavePath(void)
{ 
    VappAutoCapPage::m_errStr = 0;
    m_osd_cam_preview_state_param.indicatorStringID = 0;
    
    if (FS_NO_ERROR != FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, -1);     
        return VFX_FALSE;
    }

    // check drive    
    if(!srv_fmgr_drv_is_accessible(m_Setting->getStorage()))
    {
    #if !defined(__LOW_COST_SUPPORT_COMMON__)
        if(!srv_fmgr_drv_is_removable(m_Setting->getStorage()))
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, -2);             
            return VFX_FALSE;
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, 1);             
            
            // card is removed case will be handled by "switch to phone" on the later of preview state
            // special case for memory card rule
            return VFX_TRUE;       
        }
    #else
        return VFX_FALSE;
    #endif
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
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, 2);                     
        return VFX_TRUE;   
    }
   
    /* create directory if it is not there */
    fs_ret = FS_CreateDir((PU16) filePath);

    if (fs_ret < 0)
    {
        if(fs_ret == FS_DISK_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, -3);            
            m_osd_cam_preview_state_param.indicatorStringID = FMGR_FS_DISK_FULL_TEXT;
            VappAutoCapPage::m_errStr = FMGR_FS_DISK_FULL_TEXT;
            return VFX_TRUE;               
        }
        else if(fs_ret == FS_ROOT_DIR_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, -4);            
            m_osd_cam_preview_state_param.indicatorStringID = FMGR_FS_ROOT_DIR_FULL_TEXT;
            VappAutoCapPage::m_errStr = FMGR_FS_ROOT_DIR_FULL_TEXT;            
            return VFX_TRUE;               
        }

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, -5);                         
        return VFX_FALSE;
    }
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_CHECK_SAVE_PATH, 3);  
    return VFX_TRUE;

}


void VappAutoCapPage::initApp(void)    
{
    VfxBool appInitFlag = m_isAppInited;
    
    if(!m_isAppInited)
    {
        VFX_OBJ_CREATE(m_Setting,AutoCapSettingMgr,this);     
        VFX_OBJ_CREATE(m_OSD,AutoCapOSDMgr,this);   

        m_preview_start_param.Setting = m_Setting;
        m_preview_start_param.obj = this;
        m_preview_start_param.flag = &m_hwFlag;    
        m_preview_start_param.previewFrame = m_previewFrame;
        m_preview_start_param.previewWindow = &m_previewWindow;
        
        m_preview_stop_param.Setting = m_Setting;
        m_preview_stop_param.obj = this;    
        m_preview_stop_param.flag = &m_hwFlag;    
        
        m_power_on_param.Setting = m_Setting;
        m_power_on_param.obj = this;
        m_power_on_param.flag = &m_hwFlag;        
        
        m_power_off_param.Setting = m_Setting;
        m_power_off_param.obj = this;
        m_power_off_param.flag = &m_hwFlag;        
        
        m_capture_param.Setting = m_Setting;
        m_capture_param.obj = this;
        m_capture_param.flag = &m_hwFlag;        
        m_capture_param.previewFrame = m_previewFrame;
        m_capture_param.previewWindow = &m_previewWindow;    
        m_capture_param.panoramaShotData = &m_panoramaShot;
        
        m_panorama_stitch_param.Setting = m_Setting;
        m_panorama_stitch_param.obj = this;
        m_panorama_stitch_param.flag = &m_hwFlag;        
        m_panorama_stitch_param.panoramaShotData = &m_panoramaShot;
        m_panorama_stitch_param.workingBufferSize = AUTOCAP_CAM_MULTISHOT_BUFFER_SIZE; 
        m_panorama_stitch_param.previewFrame = m_previewFrame;
        
        m_panorama_encode_param.Setting = m_Setting;
        m_panorama_encode_param.obj = this;
        m_panorama_encode_param.flag = &m_hwFlag;     
        
        m_capture_save_param.Setting = m_Setting;
        m_capture_save_param.obj = this;
        m_capture_save_param.flag = &m_hwFlag;        
        
        m_autofocus_param.obj = this;    
        m_autofocus_param.flag = &m_hwFlag;         
        VFX_OBJ_CREATE(m_autofocus_param.af_timer, VfxTimer, this);
        m_autofocus_param.af_timer->m_signalTick.connect(this, &VappAutoCapPage::onAFTimerTick);
        
        m_general_param.obj = this;    
        m_general_param.flag = &m_hwFlag;      
        
        m_est_size_param.Setting = m_Setting;
        m_est_size_param.size = 999;    
        
        /* init OSD state param */
        m_osd_hide_state_param.isCleanBG = VFX_TRUE;
        
        m_osd_hint_state_param.setting = m_Setting;
        m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_AUTOCAP_STITCHING);
        m_osd_hint_state_param.hintIcon = 0;
        m_osd_hint_state_param.isPreviewON = VFX_FALSE;
        m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
        m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
        
        m_osd_cam_preview_state_param.setting = m_Setting;
        m_osd_cam_preview_state_param.previewWindow = VfxRect(GDI_LCD_HEIGHT>>1, GDI_LCD_WIDTH>>1,426,320);
        m_osd_cam_preview_state_param.capturableNumber = 9999;
        
        m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
        m_osd_cam_quick_view_state_param.savedImg.bgColor = VRT_COLOR_BLACK;
        
        m_osd_cam_panorama_clip_state_param.leftBound = &m_clipLeftBound;
        m_osd_cam_panorama_clip_state_param.rightBound = &m_clipRightBound;               
        
        m_osd_cam_panorama_state_param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_END;            

        m_OSD->setAutoExitTimer(m_autoExitTimer);

        m_Setting->setCallingMode(VFX_FALSE, m_param);
       
        m_isAppInited = VFX_TRUE;
    }            


    if(getState() == VAPP_AUTOCAP_STATE_EXIT)
    {
        // the timing need to init setting here
        // back from history and reset state (ex: enter Gallery) because it wont create setting
        // or need calling param case (because we set it aftar setting is created)
        if(appInitFlag || m_param.isMultiAngleViewMode)
        {
            initSetting();
        }
        // it mean the first time enter App
        // do something that create setting wont do
        else
        {
            m_Setting->setCurrApp(VAPP_AUTOCAP_APP_CAMERA);
            if(g_vapp_autocap_config.isSetDefaultStorage)
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_INIT_SETTING);      
                
                m_Setting->setValue(VAPP_AUTOCAP_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(g_vapp_autocap_config.defaultDrv));
                g_vapp_autocap_config.isSetDefaultStorage = VFX_FALSE;
            }            
        }
    }      
}

void VappAutoCapPage::initSetting()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_INIT_SETTING, 0);  

    m_Setting->setCurrApp(VAPP_AUTOCAP_APP_CAMERA);
    m_Setting->initAllSetting();
    m_Setting->loadSetting();
    m_Setting->loadSceneSetting();    
    m_Setting->setDefaultAllSetting();
    m_Setting->setValueAllSetting();

    if(g_vapp_autocap_config.isSetDefaultStorage)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_INIT_SETTING_STORAGE);      
        
        m_Setting->setValue(VAPP_AUTOCAP_SETTING_CAMSTORAGE, srv_fmgr_drv_get_type(g_vapp_autocap_config.defaultDrv));
        g_vapp_autocap_config.isSetDefaultStorage = VFX_FALSE;
    }
} 

void VappAutoCapPage::initPreviewWindow(void) 
{   
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_INIT_PREVIEW_WINDOW, 0, 0, 0, 0);   

    VfxU16 capsize = m_Setting->getValue(VAPP_AUTOCAP_SETTING_CAPSIZE);
    VfxU16 temp_width = 0;
    VfxU16 temp_height = 0;
    VfxU16 temp_factor = 0;
    VfxU16 lcd_width = 0;
    VfxU16 lcd_height = 0;
    VfxBool isRot = VFX_FALSE;
    
    if(m_isMainLcdPreview)
    {
    #ifdef HORIZONTAL_CAMERA        
        if (m_Setting->getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
        {
            if (capsize == VAPP_AUTOCAP_CAPSIZE_WALLPAPER && !m_isOnForceHorz)
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

    if (capsize == VAPP_AUTOCAP_CAPSIZE_WALLPAPER)
    {
    #ifdef HORIZONTAL_CAMERA        
        if (m_Setting->getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
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
    else if (capsize == VAPP_AUTOCAP_CAPSIZE_HLCD)
    {
        temp_width = lcd_width;
        temp_height = lcd_height;
    }
    else
    {
        temp_factor = (lcd_height / 12);
        temp_width = temp_factor * 16;
        while (temp_width > lcd_width)
        {
            temp_factor--;
            temp_width = temp_factor * 16;
        }
        temp_height = temp_factor * 12;
    }
    if(!isRot)
    {
        m_previewWindow.size = VfxSize(temp_width, temp_height);       
        m_previewWindow.origin = VfxPoint(temp_width>>1, lcd_height>>1);            
    }            
    else
    {
        m_previewWindow.size = VfxSize(temp_height, temp_width);                
        m_previewWindow.origin = VfxPoint(temp_height>>1, lcd_width>>1);                 
    }

    m_previewFrame->m_signalPlayReady.connect(this, &VappAutoCapPage::onPreviewFramePrepareDone);           

    MMI_TRACE(TRACE_GROUP_2, 
        TRC_VAPP_AUTOCAP_INIT_PREVIEW_WINDOW, 
        m_previewWindow.size.width, 
        m_previewWindow.size.height, 
        m_previewWindow.origin.x, 
        m_previewWindow.origin.y);   
    
    m_previewFrame->unPrepare();    
    m_previewFrame->setSize(m_previewWindow.size);
    m_previewFrame->setPos(m_previewWindow.origin);
    m_previewFrame->prepare();    

}

void VappAutoCapPage::onPreviewFramePrepareDone(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_PREVIEW_FRAME_PREPARE_DONE); 

    if(!m_isStartingPreview)
    {
        return;
    }
    else
    {
        m_isStartingPreview = VFX_FALSE;
    }
    
    if(m_state != VAPP_AUTOCAP_STATE_EXIT)
    {
        m_delayPreviewTimer->setStartDelay(600);            
        m_delayPreviewTimer->start();
        m_isDelayPreview = VFX_TRUE;
             
    }
    else
    {
        onPreviewFrameDoneDelayTick(NULL);
    }

}

void VappAutoCapPage::onPreviewFrameDoneDelayTick(VfxTimer *source) 
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_PREVIEW_FRAME_PREPARE_DONE); 
    
    m_isDelayPreview = VFX_FALSE;

    vapp_autocap_osd_screen_param_struct param;
    param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_SET_BUSY;
    param.isBusy = VFX_FALSE;
    m_OSD->setScreenParam(param);            
    
    vappAutoCapRestartParamStruct t;
    t.dummy = 0;
    m_restartPreviewCallback.invoke(t);
}

void VappAutoCapPage::dummyRestartPreview(vappAutoCapRestartParamStruct param)
{

}

void VappAutoCapPage::camRestartPreview(vappAutoCapRestartParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESTART_PREVIEW);   
    
    m_preview_start_param.isResetZoom = m_Setting->isNeedRestartPreview();       
    if(MDI_RES_CAMERA_SUCCEED == vapp_autocap_preview_start(&m_preview_start_param))
    {
        setState(VAPP_AUTOCAP_STATE_PREVIEW);
        m_Setting->resetRestartPreview();
    
        vapp_autocap_osd_screen_param_struct zoomUpdateParam;
        zoomUpdateParam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_ZOOM_UPDATE;
        zoomUpdateParam.zoom_value = m_Setting->getValue(VAPP_AUTOCAP_SETTING_CAMZOOM);            
        m_OSD->setScreenParam(zoomUpdateParam);

    #if !defined(__LOW_COST_SUPPORT_COMMON__)
        if(!checkRemovableStorage()) 
        {
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.isHorzUI = isHorzUI();
            m_osd_hint_state_param.event= VAPP_AUTOCAP_OSD_HINT_EVT_CAM_NO_CARD;
            m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_CONFIRM;  
            
            m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_HINT, &m_osd_hint_state_param, (VappAutoCapOSDEvtHdlr*)this);    
        }
    #endif
    }
    else
    {
        enterState(VAPP_AUTOCAP_STATE_PREVIEW_FAILED);     
    }

    if(m_state == VAPP_AUTOCAP_STATE_PREVIEW)
    {

        if(m_Setting->getValue(VAPP_AUTOCAP_SETTING_HIGHLIGHT) == VAPP_AUTOCAP_HIGHLIGHT_ON)    
        {
            vapp_autocap_highlight_turn_on(&m_general_param);        
        }
        else
        {
            vapp_autocap_highlight_turn_off(&m_general_param);
        }                
    }
   
}

void VappAutoCapPage::camPanoRestartPreview(vappAutoCapRestartParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PANO_RESTART_PREVIEW);       
    
    m_preview_start_param.isResetZoom = VFX_TRUE;               
    if(vapp_autocap_preview_start(&m_preview_start_param) == MDI_RES_CAMERA_SUCCEED)
    {
        vapp_autocap_osd_screen_param_struct zoomUpdateParam;
        zoomUpdateParam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_ZOOM_UPDATE;
        zoomUpdateParam.zoom_value = m_Setting->getMinValue(VAPP_AUTOCAP_SETTING_CAMZOOM);
        m_OSD->setScreenParam(zoomUpdateParam);
        
        m_OSD->updateScreen();            
    }
    else
    {
        vappAutoCapPopupParamStruct param;
        param.next_state = VAPP_AUTOCAP_STATE_AUTORAMA_STITCH;
        showPopupScreen(STR_ID_VAPP_AUTOCAP_PREVIEW_FAILED, &param, m_enterStateCB);
    }

}


void VappAutoCapPage::PreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PREVIEW_HDLR, evt_type);

    // resume bg calculation will after animation, sometimes it will restarting   
    if(evt_type != VAPP_AUTOCAP_EVT_BG_CAL_START)
    {
        if(m_isStartingPreview || m_isDelayPreview)
            return;
    }
    
    if(m_state != VAPP_AUTOCAP_STATE_PREVIEW && m_state != VAPP_AUTOCAP_STATE_FOCUSING && m_state != VAPP_AUTOCAP_STATE_FOCUSED)
        return;
    
    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_ENTER_GALLERY:
        {

            VfxWString fimeName = VFX_WSTR_MEM(m_camFileNameBuf);

            if(fimeName.isEmpty() || fimeName.isNull())
            {
                WCHAR* filePath;
                m_Setting->getStoragePath(&filePath);                 
                fimeName = VFX_WSTR_MEM(filePath);
            }
               
            setState(VAPP_AUTOCAP_STATE_PREVIEW);
            enterState(VAPP_AUTOCAP_STATE_EXIT);       
            
            vapp_gallery_image_viewer_launch_option_struct option;
            vapp_gallery_image_viewer_launch_option_init(&option);            

            if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
            {
            #ifdef __MMI_CAMCO_FEATURE_CAM_MAV_MODE__
                FMGR_FILTER filter;
                FMGR_FILTER_INIT(&filter);
                FMGR_FILTER_SET(&filter, FMGR_TYPE_MAV);
                option.filter = &filter;
            #endif
                option.confirm_scenario = MMI_TRUE;
                option.disable_SSE = MMI_TRUE;
            }
            else
            {
                option.filter = NULL;
                option.confirm_scenario = MMI_FALSE;
            }

            vapp_gallery_image_viewer_launch(fimeName.getBuf(), &option);
       
            break;
        }
        case VAPP_AUTOCAP_EVT_CAPTURE:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappAutoCapPage::m_errStr != 0)
            {            
                vapp_autocap_preview_stop(&m_preview_stop_param);                   
                showPopupScreen(0, NULL, m_recoverStateCB);
                break;
            }
            Capture();
          
            break;
        }
        case VAPP_AUTOCAP_EVT_SWITCH_SENSOR:
        { 
            m_isFirstEnterPreview = VFX_TRUE;
            
            exitState();
            vapp_autocap_power_off(&m_power_off_param);       
                        
            initSetting();
            
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            if(m_Setting->getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
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
            vapp_autocap_power_on(&m_power_on_param);

            enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            
            break;
        }             
        case VAPP_AUTOCAP_EVT_FOCUS:
        {
            // if there are some error when preview, show error again directly, no start capture
            if(VappAutoCapPage::m_errStr != 0)
            {
                vapp_autocap_preview_stop(&m_preview_stop_param);
                showPopupScreen(0, NULL, m_recoverStateCB);
                break;
            }
            enterState(VAPP_AUTOCAP_STATE_FOCUSING);            
            break;
        }
        case VAPP_AUTOCAP_EVT_RESTART:
        {
            if(m_Setting->getValue(VAPP_AUTOCAP_SETTING_CAPSIZE) == VAPP_AUTOCAP_CAPSIZE_WALLPAPER)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);              
            }
            else
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);                                   
            }
            m_isFirstEnterPreview = VFX_TRUE;                 
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);            
            break;
        }
        case VAPP_AUTOCAP_EVT_FORCE_HORZ:
        {
            m_isOnForceHorz = VFX_TRUE;
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);  
            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);                
            break;
        }
        case VAPP_AUTOCAP_EVT_DE_FORCE_HORZ:
        {
            m_isOnForceHorz = VFX_FALSE;
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);      
            m_isFirstEnterPreview = VFX_TRUE;            
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);                                           
            break;
        }
        case VAPP_AUTOCAP_EVT_VIEW_SWITCH:
        {
            if(m_param.isMultiAngleViewMode && m_state == VAPP_AUTOCAP_STATE_PREVIEW)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                if(m_isHorzMAVMode)
                {
                    m_isHorzMAVMode = VFX_FALSE;
                    m_Setting->setValue(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_CAPSIZE_WALLPAPER);
                    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0, VFX_TRUE);
                }
                else
                {
                    m_isHorzMAVMode = VFX_TRUE;
                    m_Setting->setValue(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_CAPSIZE_HLCD);
                    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
                    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270, VFX_TRUE);
                }
                m_isFirstEnterPreview = VFX_TRUE;
                enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            }
            break;
        }
        case VAPP_AUTOCAP_EVT_OK:
        {
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);            
            break;            
        }
        case VAPP_AUTOCAP_EVT_CANCEL:
        {
            exit();
            break;
        }   
        case VAPP_AUTOCAP_EVT_BG_CAL_START:
        {
            vapp_autocap_background_calculation_start();
            break;
        }
        case VAPP_AUTOCAP_EVT_BG_CAL_STOP:            
        {
            vapp_autocap_background_calculation_stop();            
            break;
        }          
        default:
            ASSERT(0);
    }            

};
void VappAutoCapPage::PreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PREVIEW_FAILED_HDLR, evt_type);

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_BACK:
        {
            exit();
            break;
        }
        default:
            ASSERT(0);
    }    

};

void VappAutoCapPage::AutoramaShotHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PANORAMASHOT_HDLR, evt_type);

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_STITCH:
        {
            vapp_autocap_preview_stop(&m_preview_stop_param);
    
            enterState(VAPP_AUTOCAP_STATE_AUTORAMA_STITCH);
            break;
        }           
        case VAPP_AUTOCAP_EVT_BACK:
        {
            m_autoramraUpdateTimer->stop();
            
            if (m_hwFlag.isPowerOn)
            {
                vapp_autocap_reset_panorama_3a();
                m_Setting->needRestartPreview();
                enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            }
            else
            {
                enterState(VAPP_AUTOCAP_STATE_PREVIEW_FAILED);
            }

            break;
        }                
        default:
            ASSERT(0);
    }  

};

void VappAutoCapPage::AutoramaStitchHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PANORAMA_CLIP_HDLR, evt_type);

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_BACK:
        {
            vapp_autocap_panorama_stop_stitch();

            if (m_hwFlag.isPowerOn)
            {
                enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            }
            else
            {
                enterState(VAPP_AUTOCAP_STATE_PREVIEW_FAILED);
            }
            break;
        }    
        default:
            ASSERT(0);
    }  

};

void VappAutoCapPage::AutoramaClipHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PANORAMA_STITCH_HDLR, evt_type);

    // when from clip state enter encode state, UI does not change
    // so we need to skip it
    if(m_state != VAPP_AUTOCAP_STATE_AUTORAMA_CLIP)
        return;

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_CLIP:
        {            
            if(m_osd_cam_panorama_clip_state_param.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT || m_osd_cam_panorama_clip_state_param.direction ==VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT)
            {
                m_panorama_encode_param.encodeRoiX = m_clipLeftBound;
                m_panorama_encode_param.encodeRoiY = 0;
                m_panorama_encode_param.encodeRoiW = m_clipRightBound - m_clipLeftBound;            
                m_panorama_encode_param.encodeRoiH = m_osd_cam_panorama_clip_state_param.quickViewSize[1];  
            }
            else
            {
                m_panorama_encode_param.encodeRoiX = 0;
                m_panorama_encode_param.encodeRoiY = m_clipLeftBound;
                m_panorama_encode_param.encodeRoiW = m_osd_cam_panorama_clip_state_param.quickViewSize[0];            
                m_panorama_encode_param.encodeRoiH = m_clipRightBound - m_clipLeftBound;  
            } 
            enterState(VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE);
            
            break;
        }  
        case VAPP_AUTOCAP_EVT_BACK:
        {            
            if(m_osd_cam_panorama_clip_state_param.direction == VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT || m_osd_cam_panorama_clip_state_param.direction ==VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT)
            {
                m_panorama_encode_param.encodeRoiX = 0;
                m_panorama_encode_param.encodeRoiY = 0;
                m_panorama_encode_param.encodeRoiW = m_osd_cam_panorama_clip_state_param.quickViewSize[0];
                m_panorama_encode_param.encodeRoiH = m_osd_cam_panorama_clip_state_param.quickViewSize[1];  
            }
            else
            {
                m_panorama_encode_param.encodeRoiX = 0;
                m_panorama_encode_param.encodeRoiY = 0;
                m_panorama_encode_param.encodeRoiW = m_osd_cam_panorama_clip_state_param.quickViewSize[0];            
                m_panorama_encode_param.encodeRoiH = m_osd_cam_panorama_clip_state_param.quickViewSize[1];  
            } 
            enterState(VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE);
            
            break;
        }    
        case VAPP_AUTOCAP_EVT_CANCEL:
        {
            vapp_autocap_panorama_stop_stitch();
            mmi_frm_end_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);            
            m_isPreemptable = MMI_TRUE;  

            enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            
            break;            
        }
        default:
            ASSERT(0);
    }  

};

void VappAutoCapPage::AutoramaDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PANORAMA_DONE_HDLR, evt_type);

    if(m_state != VAPP_AUTOCAP_STATE_AUTORAMA_DONE)
        return;

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_VIEW_STOP:
        {
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            break;
        }    
        default:
            ASSERT(0);
    }    

};

void VappAutoCapPage::FocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_FOCUS_HDLR, evt_type);

    if(m_state == VAPP_AUTOCAP_STATE_INT_PREVIEW)
        return;

    if(m_isStartingPreview || m_isDelayPreview)
        return;

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_FOCUS_STOP:
        {
            vapp_autocap_autofocus_stop(&m_autofocus_param);            
            m_isFirstEnterPreview = VFX_TRUE;
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            break;
        }  
        case VAPP_AUTOCAP_EVT_CAPTURE:
        {
            Capture();
            break;
        }          
        default:
            ASSERT(0);
    }    

};

void VappAutoCapPage::errorPopupHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ERROR_POPUP_HDLR, evt_type);

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_OK:
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

void VappAutoCapPage::appGlobalEventHdlr(mmi_cameco_evt_type_enum evt_type, void* param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_APP_GLOBAL_EVENT_HDLR, evt_type);

    switch (evt_type)
    {
        case VAPP_AUTOCAP_EVT_AUTO_EXIT:
        {
            getApp()->exit();
            break;        
        }                 
        default:
            ASSERT(0);
    }  

}


// state enter function
void VappAutoCapPage::enterExitState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_EXIT_STATE);

    exitState();

    if (m_state == VAPP_AUTOCAP_STATE_AUTORAMA_SHOT ||
        m_state == VAPP_AUTOCAP_STATE_AUTORAMA_STITCH)
    {
        vapp_autocap_reset_panorama_3a();
    }

    m_Setting->setValue(VAPP_AUTOCAP_SETTING_HIGHLIGHT, VAPP_AUTOCAP_HIGHLIGHT_OFF);

    if(m_camFileNameBuf)
    {
        if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
            mmi_wcscpy(g_vapp_mav_prev_file_name, m_camFileNameBuf);      
        else if(m_param.isMultiAngleViewMode && m_param.is3DCameraMode)
            mmi_wcscpy(g_vapp_3d_camera_prev_file_name, m_camFileNameBuf);      
        else    
            mmi_wcscpy(g_vapp_autocap_prev_file_name, m_camFileNameBuf); 
    }

    m_state = VAPP_AUTOCAP_STATE_EXIT;
    
};

void VappAutoCapPage::enterPreviewState(void)
{

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PREVIEW_STATE, 0);

    if(!checkSavePath())
    {
    #if !defined(__LOW_COST_SUPPORT_COMMON__)
        if(VappAutoCapPage::m_errStr == 0)
            VappAutoCapPage::m_errStr = STR_ID_VAPP_AUTOCAP_NOTIFY_STORAGE_NOT_READY;
    #else
        if(VappAutoCapPage::m_errStr == 0)
            VappAutoCapPage::m_errStr = STR_GLOBAL_INSERT_MEMORY_CARD;
    #endif
    
        if(m_hwFlag.isPreviewStart)
        {
            vapp_autocap_preview_stop(&m_preview_stop_param);        
        }
        
        enterState(VAPP_AUTOCAP_STATE_ENTER_FAIL);
        return;
    }

    if(!m_hwFlag.isPreviewStart || m_Setting->isNeedRestartPreview())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PREVIEW_STATE, 1);
        
        if(m_Setting->isNeedRestartPreview())
        {
            vapp_autocap_preview_stop(&m_preview_stop_param);
        }

        if(m_param.isMultiAngleViewMode)
        {
            if(m_isHorzMAVMode)
                m_Setting->setValue(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_CAPSIZE_HLCD);
            else
                m_Setting->setValue(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_CAPSIZE_WALLPAPER);
        }    
        
        initPreviewWindow();
        
        m_osd_cam_preview_state_param.previewWindow = m_previewWindow;
        m_osd_cam_preview_state_param.isCleanModeEnter = !m_isFirstEnterPreview;
        m_osd_cam_preview_state_param.capturableNumber = (getFreeStorageSize() / m_est_size_param.size);
        m_osd_cam_preview_state_param.previousFileName = m_camFileNameBuf;
        m_osd_cam_preview_state_param.isRestartEnter = VFX_TRUE;
        m_osd_cam_preview_state_param.isMavMode= m_param.isMultiAngleViewMode;
        m_osd_cam_preview_state_param.is3DCameraMode = m_param.is3DCameraMode;
        m_isFirstEnterPreview = VFX_FALSE;        
        m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_CAMERA_PREVIEW, &m_osd_cam_preview_state_param, (VappAutoCapOSDEvtHdlr*)this);    
        m_OSD->clean();
        m_OSD->updateScreen();              

        if(m_Setting->isNeedRestartPreview())
        {
            m_Setting->setValue(VAPP_AUTOCAP_SETTING_CAMZOOM, m_Setting->getMinValue(VAPP_AUTOCAP_SETTING_CAMZOOM));    
        }        
        
        m_restartPreviewCallback = m_camRestartPreviewCallback;
        m_isStartingPreview = VFX_TRUE;
        
        vapp_autocap_osd_screen_param_struct param;
        param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_RESET_FOCUS;
        m_OSD->setScreenParam(param);
        param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_SET_BUSY;
        param.isBusy = VFX_TRUE;
        m_OSD->setScreenParam(param);           
        return;
  
    }
    else
    {
        setState(VAPP_AUTOCAP_STATE_PREVIEW);    

    #if !defined(__LOW_COST_SUPPORT_COMMON__)
        if(!checkRemovableStorage()) 
        {
            m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE);
            m_osd_hint_state_param.isPreviewON = VFX_FALSE;
            m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
            m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
            m_osd_hint_state_param.isHorzUI = isHorzUI();
            m_osd_hint_state_param.event = VAPP_AUTOCAP_OSD_HINT_EVT_CAM_NO_CARD;        
            m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_CONFIRM;   
            
            m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_HINT, &m_osd_hint_state_param, (VappAutoCapOSDEvtHdlr*)this);    
        }
        else
    #endif
        {
            m_osd_cam_preview_state_param.previewWindow = m_previewWindow;
            m_osd_cam_preview_state_param.isCleanModeEnter = !m_isFirstEnterPreview;
            m_osd_cam_preview_state_param.capturableNumber = (getFreeStorageSize() / m_est_size_param.size);
            m_osd_cam_preview_state_param.previousFileName = m_camFileNameBuf;    
            m_osd_cam_preview_state_param.isRestartEnter = VFX_FALSE;            
            m_osd_cam_preview_state_param.isMavMode= m_param.isMultiAngleViewMode;
            m_osd_cam_preview_state_param.is3DCameraMode = m_param.is3DCameraMode;
            m_isFirstEnterPreview = VFX_FALSE;                  
            m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_CAMERA_PREVIEW, &m_osd_cam_preview_state_param, (VappAutoCapOSDEvtHdlr*)this);    
            m_OSD->clean();
            m_OSD->updateScreen();               
            vapp_autocap_osd_screen_param_struct param;
            param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_RESET_FOCUS;
            m_OSD->setScreenParam(param);
        }


    }

    if(m_state == VAPP_AUTOCAP_STATE_PREVIEW)
    {

        if(m_Setting->getValue(VAPP_AUTOCAP_SETTING_HIGHLIGHT) == VAPP_AUTOCAP_HIGHLIGHT_ON)    
        {
            vapp_autocap_highlight_turn_on(&m_general_param);        
        }
        else
        {
            vapp_autocap_highlight_turn_off(&m_general_param);
        }                
    }

};

void VappAutoCapPage::enterPreviewFailedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PREVIEW_FAILED_STATE);

    if(m_param.isMultiAngleViewMode)
    {
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);
    }
    else
    {
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);
    }
    setState(VAPP_AUTOCAP_STATE_PREVIEW_FAILED);
    
    m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_AUTOCAP_PREVIEW_FAILED);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.isHorzUI = isHorzUI();
    m_osd_hint_state_param.event = VAPP_AUTOCAP_OSD_HINT_EVT_OTHERS;        
    m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_HINT_TEXT;  

    m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_HINT, &m_osd_hint_state_param, (VappAutoCapOSDEvtHdlr*)this);        

    m_OSD->updateScreen();

};


void VappAutoCapPage::enterFocusingState(void)
{   
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_FOCUSING_STATE);

#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)

    setState(VAPP_AUTOCAP_STATE_FOCUSING);
    
    vapp_autocap_autofocus_start(&m_autofocus_param);

    vapp_autocap_get_autofocus_result(&m_autofocus_param);        

    VfxU32 af_active_zone = 0;
    VfxS32 af_zone_count = 0;    

    af_active_zone = m_autofocus_param.af_zone.af_active_zone;

    for (VfxU32 idx = VAPP_AUTOCAP_OSD_FOCUS_REGION_1; idx < VAPP_AUTOCAP_OSD_FOCUS_REGION_END; idx++)
    {
        af_zone_count += af_active_zone & 0x00000001;
        af_active_zone = af_active_zone >> 1;
    }

    af_active_zone = m_autofocus_param.af_zone.af_active_zone;    

    MMI_ASSERT(af_zone_count <= VAPP_AUTOCAP_OSD_FOCUS_REGION_END);

    m_autofocus_param.af_active_zone = m_autofocus_param.af_zone.af_active_zone;
    for (VfxU32 idx = VAPP_AUTOCAP_OSD_FOCUS_REGION_1; idx < VAPP_AUTOCAP_OSD_FOCUS_REGION_END; idx++)
    {
        if (af_active_zone & 0x00000001)
        {
            vapp_autocap_osd_screen_param_struct param;
            param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSING;
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


void VappAutoCapPage::enterFocusedState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_FOCUSED_STATE);

#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
    MMI_ASSERT(m_state == VAPP_AUTOCAP_STATE_FOCUSING);

    setState(VAPP_AUTOCAP_STATE_FOCUSING);
    

    VfxU32 af_active_zone = m_autofocus_param.af_zone.af_active_zone;
    VfxU32 af_success_zone = m_autofocus_param.af_success_zone;

    for (VfxU32 idx = 0; idx < VAPP_AUTOCAP_OSD_FOCUS_REGION_END; idx++)
    {

        VfxU32 is_success = af_success_zone & 0x00000001;

        if (is_success)
        {

            vapp_autocap_osd_screen_param_struct param;
            param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSED;
            param.focus.w = m_autofocus_param.af_zone.af_zone[idx].af_zone_w;
            param.focus.h = m_autofocus_param.af_zone.af_zone[idx].af_zone_h;
            param.focus.center_x = m_autofocus_param.af_zone.af_zone[idx].af_zone_x + m_osd_cam_preview_state_param.previewWindow.getX() - (m_osd_cam_preview_state_param.previewWindow.getWidth()>>1);
            param.focus.center_y = m_autofocus_param.af_zone.af_zone[idx].af_zone_y + m_osd_cam_preview_state_param.previewWindow.getY() - (m_osd_cam_preview_state_param.previewWindow.getHeight()>>1);
            param.index = idx;

            m_OSD->setScreenParam(param);
            
        }
        else if (af_active_zone & 0x00000001)
        {
            vapp_autocap_osd_screen_param_struct param;
            param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_SET_FOCUS;
            param.focus.type = VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSING;
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


void VappAutoCapPage::enterAutoramaShotState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PANORAMASHOT_STATE, m_state, m_panoramaShot.capture_count );

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;   
       
    if(m_param.isMultiAngleViewMode)
    {
        MDI_RESULT result;
        if(getNextFilename(m_camFileNameBuf))
        {
            m_capture_param.fileName = m_camFileNameBuf;
            result = vapp_autocap_mav_shot(&m_capture_param);

        }
        else
        {
            result = VAPP_AUTOCAP_ERR_FILE_NAME_NOTFOUND;
        }

        playCatureSound(result);

        if (result == MDI_RES_CAMERA_SUCCEED)
        {
            setState(VAPP_AUTOCAP_STATE_AUTORAMA_SHOT);
            m_mavShot.captured_count++;

            m_osd_cam_panorama_state_param.isHorzUI = isHorzUI();
            m_osd_cam_panorama_state_param.isMavMode = m_param.isMultiAngleViewMode;
            m_osd_cam_panorama_state_param.count = m_mavShot.captured_count;
        #if defined (__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__)
        #if defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
            if(!m_param.is3DCameraMode)
                m_osd_cam_panorama_state_param.totalCount = MMI_CAMCO_FEATURE_CAM_MAV_IMAGE_COUNT;
            else
                m_osd_cam_panorama_state_param.totalCount = MMI_CAMCO_FEATURE_CAM_3D_IMAGE_COUNT;
        #elif defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && !defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
            m_osd_cam_panorama_state_param.totalCount = MMI_CAMCO_FEATURE_CAM_MAV_IMAGE_COUNT;
        #elif !defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__) && defined(__MMI_CAMCO_FEATURE_CAM_3D_CAMERA_MODE__)
                m_osd_cam_panorama_state_param.totalCount = MMI_CAMCO_FEATURE_CAM_3D_IMAGE_COUNT;
        #endif
        #endif
            m_osd_cam_panorama_state_param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT;
            m_osd_cam_panorama_state_param.previewWindow = m_previewWindow;
            m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT, &m_osd_cam_panorama_state_param, (VappAutoCapOSDEvtHdlr*)this);

            vapp_autocap_osd_screen_param_struct OSDparam;
            OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_DIR_UPDATE;
            OSDparam.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT;
            m_OSD->setScreenParam(OSDparam);

            OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_RATIO_UPDATE;
            OSDparam.ratio = 0;
            m_OSD->setScreenParam(OSDparam);

            OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_MV_UPDATE;
            OSDparam.motionX = 0;
            OSDparam.motionY = 0;
            m_OSD->setScreenParam(OSDparam);
        }
        else
        {
            restoreFilename();
            showPopupScreen(result, NULL, m_recoverStateCB);
            return;
        }

    #if !defined(__MTK_TARGET__)
        m_mavShot.captured_count = 5;
    #if defined (__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__) && defined(__MMI_CAMCO_FEATURE_CAM_MAV_MODE__)
        m_mavShot.total_count = MMI_CAMCO_FEATURE_CAM_MAV_IMAGE_COUNT;
    #endif
        m_mavShot.captured_count = m_mavShot.captured_count;

        m_osd_cam_panorama_state_param.isHorzUI = isHorzUI();
        m_osd_cam_panorama_state_param.isMavMode = m_param.isMultiAngleViewMode;
        m_osd_cam_panorama_state_param.count = m_mavShot.captured_count;
        m_osd_cam_panorama_state_param.totalCount = m_mavShot.total_count;
        m_osd_cam_panorama_state_param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT;
        m_osd_cam_panorama_state_param.previewWindow = m_previewWindow;
        m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT, &m_osd_cam_panorama_state_param, (VappAutoCapOSDEvtHdlr*)this);

        vapp_autocap_osd_screen_param_struct OSDparam;
        OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_DIR_UPDATE;
        OSDparam.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT;
        m_OSD->setScreenParam(OSDparam);

        OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_RATIO_UPDATE;
        OSDparam.ratio = 0;
        m_OSD->setScreenParam(OSDparam);

        OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_MV_UPDATE;
        OSDparam.motionX = 5 * m_previewWindow.size.width;
        OSDparam.motionY = 0;
        m_OSD->setScreenParam(OSDparam);
    #endif
    }
    else
    {
        if (m_panoramaShot.capture_count < MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT)
        {
            MDI_RESULT result = vapp_autocap_panorama_shot(&m_capture_param);
            playCatureSound(result);

        #ifdef VAPP_AUTOCAP_MODIS_PIC_PREVIEW
            WCHAR fileName[30];
            CHAR fileNameAsc[15] = "";

            sprintf(fileNameAsc, "%c:\\2.bmp", SRV_FMGR_CARD_DRV);
            mmi_asc_to_wcs(fileName, fileNameAsc);

            VfxImageSrc s = VfxImageSrc(VFX_WSTR_MEM(fileName));

            m_picturePreviewFrame->setImgContent(s);

        #endif

            if (result == MDI_RES_CAMERA_SUCCEED)
            {
                setState(VAPP_AUTOCAP_STATE_AUTORAMA_SHOT);
                m_panoramaShot.capture_count++;
                if (m_panoramaShot.capture_count < MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT)
                {

                    m_osd_cam_panorama_state_param.isHorzUI = isHorzUI();
                    m_osd_cam_panorama_state_param.isMavMode = m_param.isMultiAngleViewMode;
                    m_osd_cam_panorama_state_param.count = m_panoramaShot.capture_count;
                    m_osd_cam_panorama_state_param.totalCount = MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT;
                    if(m_panoramaShot.capture_count == 1)
                        m_osd_cam_panorama_state_param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_END;
                    else
                        m_osd_cam_panorama_state_param.direction = (vapp_autocap_panorama_direction_enum)m_Setting->getValue(VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION);
                    m_osd_cam_panorama_state_param.previewWindow = m_previewWindow;
                    m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT, &m_osd_cam_panorama_state_param, (VappAutoCapOSDEvtHdlr*)this);

                    m_preview_start_param.isResetZoom = VFX_FALSE;
                    if(vapp_autocap_preview_start(&m_preview_start_param) == MDI_RES_CAMERA_SUCCEED)
                    {
                        m_OSD->updateScreen();
                    }
                    else
                    {
                        vappAutoCapPopupParamStruct param;
                        param.next_state = VAPP_AUTOCAP_STATE_AUTORAMA_STITCH;
                        showPopupScreen(STR_ID_VAPP_AUTOCAP_PREVIEW_FAILED, &param, m_enterStateCB);
                    }

                    m_autoramraUpdateTimer->start();

                }
                else
                {
                    enterState(VAPP_AUTOCAP_STATE_AUTORAMA_STITCH);
                }

            }
            else
            {
                if(m_panoramaShot.capture_count == 0)
                {
                    showPopupScreen(STR_ID_VAPP_AUTOCAP_PREVIEW_FAILED, NULL, m_recoverStateCB);
                }
                else
                {
                    enterState(VAPP_AUTOCAP_STATE_AUTORAMA_STITCH);
                }
            }
        }
    }
};

void VappAutoCapPage::enterAutoramaStitchState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PANORAMA_STITCH_STATE, m_state);


    MDI_RESULT ret;

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;     
    m_autoramraUpdateTimer->stop();
    
    m_panoramaShot.is_stitch_done = MMI_FALSE;
    m_panoramaShot.stitch_ind.result = MDI_RES_CAMERA_SUCCEED;
    
    // quick view buffer will be used by dirver
    // cannot blt the capture screen or the previous shot pic will show error
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();    
    
    ret = vapp_autocap_panorama_stitch(&m_panorama_stitch_param);    

    setState(VAPP_AUTOCAP_STATE_AUTORAMA_STITCH);

    if (ret == MDI_RES_CAMERA_SUCCEED)
    {    

        m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_AUTOCAP_STITCHING);
        m_osd_hint_state_param.isPreviewON = VFX_FALSE;
        m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
        m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
        m_osd_hint_state_param.isHorzUI = isHorzUI(); 
        m_osd_hint_state_param.event = VAPP_AUTOCAP_OSD_HINT_EVT_CAM_STITCHING;        
        m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_PROCESSING;  
                
        m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_HINT, &m_osd_hint_state_param, (VappAutoCapOSDEvtHdlr*)this);   
    
        m_OSD->updateScreen();    
    }
    else
    {
        showPopupScreen(ret, NULL, m_recoverStateCB);
    }

#ifdef VAPP_AUTOCAP_MODIS_PIC_PREVIEW
    vapp_autocap_hw_result_callback_param_struct param;
    
    param.type = VAPP_AUTOCAP_CB_TYPE_PANORAMA_QUICK_VIEW;

    param.quickViewRet.quickview_start_x = 0;
    param.quickViewRet.quickview_start_y = 0;
    param.quickViewRet.quickview_width = 909;
    param.quickViewRet.quickview_height = 260;  
    param.quickViewRet.result = MDI_RES_CAMERA_SUCCEED;


    FS_HANDLE fileHandle;
    VfxU32 read;

    WCHAR fileName[30];
    CHAR fileNameAsc[15] = "";
    
    sprintf(fileNameAsc, "%c:\\3.bmp", SRV_FMGR_CARD_DRV);    
    mmi_asc_to_wcs(fileName, fileNameAsc);
    
    fileHandle = FS_Open((U16*)fileName, FS_CREATE | FS_READ_ONLY);

    FS_Read(fileHandle, (void*)m_panorama_stitch_param.quickViewBuffer, 709334, (U32*) &read);
    FS_Close(fileHandle);
    
    resultHWCallback(param);
#endif    

};

void VappAutoCapPage::enterAutoramaClipState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PANORAMA_CLIP_STATE, m_state);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;  
        
    m_state = VAPP_AUTOCAP_STATE_AUTORAMA_CLIP;
    
    m_osd_cam_panorama_clip_state_param.isHorzUI= isHorzUI(); 
    m_osd_cam_panorama_clip_state_param.direction =  (vapp_autocap_panorama_direction_enum)m_Setting->getValue(VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION);
    m_osd_cam_panorama_clip_state_param.previewWindow = m_previewWindow;  
    if(m_osd_cam_panorama_clip_state_param.direction ==VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT || m_osd_cam_panorama_clip_state_param.direction ==VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT)
    {
        *(m_osd_cam_panorama_clip_state_param.leftBound) = 0;
        *(m_osd_cam_panorama_clip_state_param.rightBound) = m_osd_cam_panorama_clip_state_param.quickViewSize[0];    
    }
    else
    {
        *(m_osd_cam_panorama_clip_state_param.leftBound) = 0;
        *(m_osd_cam_panorama_clip_state_param.rightBound) = m_osd_cam_panorama_clip_state_param.quickViewSize[1];    
    }        
    m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_PANORAMA_CLIP, &m_osd_cam_panorama_clip_state_param, (VappAutoCapOSDEvtHdlr*)this);   
    
    m_OSD->updateScreen();  

}


void VappAutoCapPage::enterAutoramaEncodeState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PANORAMA_ENCODE_STATE, m_state);

    MDI_RESULT ret;

    mmi_frm_start_scenario(MMI_SCENARIO_ID_CAMCO_NONPREEMPTION);
    m_isPreemptable = MMI_FALSE;
        
    if(m_param.isMultiAngleViewMode)
    {
        ret = MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        ret = vapp_autocap_panorama_encode(&m_panorama_encode_param);
    }

    setState(VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE);

    if (ret == MDI_RES_CAMERA_SUCCEED)
    {    
        m_osd_hint_state_param.hintText = VFX_WSTR_RES(STR_ID_VAPP_AUTOCAP_STITCHING);
        m_osd_hint_state_param.isPreviewON = VFX_FALSE;
        m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
        m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
        m_osd_hint_state_param.isHorzUI = isHorzUI(); 
        m_osd_hint_state_param.event = VAPP_AUTOCAP_OSD_HINT_EVT_CAM_STITCHING;        
        m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_PROCESSING;  
                
        m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_HINT, &m_osd_hint_state_param, (VappAutoCapOSDEvtHdlr*)this);   
    
        m_OSD->updateScreen();    
    }
    else
    {
        showPopupScreen(ret, NULL, m_recoverStateCB);
    }

};

void VappAutoCapPage::enterAutoramaDoneState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_CAM_PANORAMA_DONE_STATE, m_state);

    vapp_autocap_state_enum prev_state = m_state;

    vapp_autocap_highlight_turn_off(&m_general_param);

    if (prev_state == VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE)
    {
        if(m_param.isMultiAngleViewMode)
        {
            MDI_RESULT ret;

            ret = vapp_autocap_mav_save();

            m_mavShot.captured_count = 0;

            if(ret == MDI_RES_CAMERA_SUCCEED)
            {
                setState(VAPP_AUTOCAP_STATE_AUTORAMA_DONE);

                ASSERT(m_camFileNameBuf != NULL);

                VfxWString fimeName = VFX_WSTR_MEM(m_camFileNameBuf);

                if(fimeName.isEmpty() || fimeName.isNull())
                {
                    WCHAR* filePath;
                    m_Setting->getStoragePath(&filePath);
                    fimeName = VFX_WSTR_MEM(filePath);
                }

                setState(VAPP_AUTOCAP_STATE_PREVIEW);
                enterState(VAPP_AUTOCAP_STATE_EXIT);

                vapp_gallery_image_viewer_launch_option_struct option;
                vapp_gallery_image_viewer_launch_option_init(&option);
   
                if(!m_param.is3DCameraMode)
                {
                #ifdef __MMI_CAMCO_FEATURE_CAM_MAV_MODE__
                    FMGR_FILTER filter;
                    FMGR_FILTER_INIT(&filter);
                    FMGR_FILTER_SET(&filter, FMGR_TYPE_MAV);
                    option.filter = &filter;
                #endif
                    option.disable_SSE = MMI_TRUE;
                    option.confirm_scenario = MMI_TRUE;
                }
                else
                {
                    option.filter = NULL;
                    option.disable_SSE = MMI_TRUE;
                    option.confirm_scenario = MMI_FALSE;                    
                }

                vapp_gallery_image_viewer_launch(fimeName.getBuf(), &option);


            }
            else
            {
                restoreFilename();
                showPopupScreen(ret, NULL, m_recoverStateCB);
                return;
            }

        }
        else
        {
            MDI_RESULT ret;

            memset(m_camFileNameBuf, 0, SRV_FMGR_PATH_BUFFER_SIZE);
            if(getNextFilename(m_camFileNameBuf))
            {
                ret = saveCapturedImage(
                        m_camFileNameBuf,
                        (VfxS8*) m_panoramaShot.stitch_ind.jpeg_buffer_address,
                        m_panoramaShot.stitch_ind.jpeg_buffer_size);
            }
            else
            {
                ret = VAPP_AUTOCAP_ERR_FILE_NAME_NOTFOUND;
            }

            if (ret == MDI_RES_CAMERA_SUCCEED)
            {
                setState(VAPP_AUTOCAP_STATE_AUTORAMA_DONE);

                m_osd_cam_quick_view_state_param.type = VAPP_AUTOCAP_OSD_QV_EVT_PANORAMA_SHOT;
                m_osd_cam_quick_view_state_param.savedImg.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_JPEG;
                m_osd_cam_quick_view_state_param.savedImg.srcJpgBuffAdress = (void *)m_panoramaShot.stitch_ind.jpeg_buffer_address;
                m_osd_cam_quick_view_state_param.savedImg.cacheBuffAdress = m_panorama_stitch_param.quickViewBuffer;
                m_osd_cam_quick_view_state_param.savedImg.srcSize = m_panoramaShot.stitch_ind.jpeg_buffer_size;
                m_osd_cam_quick_view_state_param.isHorzUI = isHorzUI();

                m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_CAMERA_QUICK_VIEW, &m_osd_cam_quick_view_state_param, (VappAutoCapOSDEvtHdlr*)this);
                m_OSD->updateScreen();
            }
            else
            {

                restoreFilename();
                showPopupScreen(ret, NULL, m_recoverStateCB);
                return;
            }
        }
    }    

    vapp_autocap_bk_turn_off();   
}


void VappAutoCapPage::onAutoramaUpdateTick(VfxTimer *source) 
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ON_UPDATE);

#if !defined(__MTK_TARGET__)
#ifdef VAPP_AUTOCAP_MODIS_PIC_PREVIEW
    vapp_autocap_osd_screen_param_struct paramM;
    paramM.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_DIR_UPDATE;
    paramM.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_END;
    m_OSD->setScreenParam(paramM);  

    paramM.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_RATIO_UPDATE;
    paramM.ratio = 32.0 / 64.0;
    m_OSD->setScreenParam(paramM);  

    paramM.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_MV_UPDATE;
    paramM.motionX = 0;
    paramM.motionY = 0;    
    m_OSD->setScreenParam(paramM);    
#endif
    m_autoramraUpdateTimer->start();        
    return;
#endif

    if(m_isStartingPreview || m_isDelayPreview)
    {
        m_autoramraUpdateTimer->start();        
        return;
    }
    
    mdi_camera_panorama_cap_info_struct autoCapResult;
    
    mdi_camera_get_panorama_cap_info(&autoCapResult);

    vapp_autocap_osd_screen_param_struct param;
    param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_DIR_UPDATE;
    if(autoCapResult.stitch_dir == AUTOCAP_DIR_RIGHT)
        param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT;
    else if(autoCapResult.stitch_dir == AUTOCAP_DIR_LEFT)
        param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT;
    else if(autoCapResult.stitch_dir == AUTOCAP_DIR_UP)
        param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_UP;
    else if(autoCapResult.stitch_dir == AUTOCAP_DIR_DOWN)
        param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN;
    else if(autoCapResult.stitch_dir == AUTOCAP_DIR_NO)
        param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_END;
    m_Setting->setValue(VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION, param.direction);    
    m_OSD->setScreenParam(param);  

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PANORAMA_UPDATE, 
        autoCapResult.stitch_dir, 
        autoCapResult.mv_x,
        autoCapResult.mv_y,
        autoCapResult.ready_to_shot);

    param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_RATIO_UPDATE;
    param.ratio = autoCapResult.overlap_ratio / 64.0;
    m_OSD->setScreenParam(param);    

    m_osd_cam_panorama_state_param.overlapRatio = param.ratio;

    param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_MV_UPDATE;
    param.motionX = autoCapResult.mv_x;
    param.motionY = autoCapResult.mv_y;    
    m_OSD->setScreenParam(param);    

    if(m_lastDirection == VAPP_AUTOCAP_PANORAMA_DIRECTION_END && param.direction != VAPP_AUTOCAP_PANORAMA_DIRECTION_END)
    {
        kal_get_time(&m_lastCaptureTime);    
    }
    m_lastDirection = param.direction;
    
    VfxU32 currentTime;
    kal_get_time(&currentTime);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PANORAMA_UPDATE2, currentTime, m_lastCaptureTime);
    
    if(((currentTime - m_lastCaptureTime) * 4.615 > 30000 )&& (!autoCapResult.ready_to_shot))
    {
    #if !defined(__LOW_COST_SUPPORT_COMMON__)    
        //if(autoCapResult.stitch_dir != AUTOCAP_DIR_NO)
        //{
            m_autoramraUpdateTimer->stop();
            vapp_autocap_preview_stop(&m_preview_stop_param);

            enterState(VAPP_AUTOCAP_STATE_AUTORAMA_STITCH);
        //}
        //else
        //{
        //    m_autoramraUpdateTimer->stop();
        //    vapp_autocap_reset_panorama_3a();
        //    m_Setting->needRestartPreview();
        //    enterState(VAPP_AUTOCAP_STATE_PREVIEW);
        //}
    #else
        m_autoramraUpdateTimer->start();
    #endif
    }
    else if(autoCapResult.ready_to_shot)
    {
        m_autoramraUpdateTimer->stop();    
        enterState(VAPP_AUTOCAP_STATE_AUTORAMA_SHOT);    
        kal_get_time(&m_lastCaptureTime);
    }
    else
    {
        m_autoramraUpdateTimer->start();
    } 
}


void VappAutoCapPage::enterEnterFailState(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ENTER_ENTER_FAIL_STATE);

    setState(VAPP_AUTOCAP_STATE_ENTER_FAIL);

    // show with horz screen
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);

    m_osd_hint_state_param.hintText = VFX_WSTR_RES(VappAutoCapPage::m_errStr);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    m_osd_hint_state_param.isHorzUI = isHorzUI();
    m_osd_hint_state_param.event = VAPP_AUTOCAP_OSD_HINT_EVT_OTHERS;    
    m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_HINT_TEXT;
        
    m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_HINT, &m_osd_hint_state_param, (VappAutoCapOSDEvtHdlr*)this);         
    m_OSD->updateScreen();        

    resetMem();

    m_errorExitTimer->start();

}

void VappAutoCapPage::resultHWCallback(vapp_autocap_hw_result_callback_param_struct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK, param.type, m_state);

    switch (param.type)
    {
        case VAPP_AUTOCAP_CB_TYPE_PANORAMA_QUICK_VIEW:
        {
            if (m_state == VAPP_AUTOCAP_STATE_AUTORAMA_STITCH)
            {
                m_osd_cam_panorama_clip_state_param.quickViewStartPoint[0] = param.quickViewRet.quickview_start_x;
                m_osd_cam_panorama_clip_state_param.quickViewStartPoint[1] = param.quickViewRet.quickview_start_y;
                m_osd_cam_panorama_clip_state_param.quickViewSize[0] = param.quickViewRet.quickview_width;
                m_osd_cam_panorama_clip_state_param.quickViewSize[1] = param.quickViewRet.quickview_height;  
                m_osd_cam_panorama_clip_state_param.quickViewBuffer = m_panorama_stitch_param.quickViewBuffer;    
                m_osd_cam_panorama_clip_state_param.quickViewSourceBuffer = m_panorama_stitch_param.quickViewBuffer;

                if (param.quickViewRet.result == MDI_RES_CAMERA_SUCCEED)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 0, 0);                
                    
                    if(m_panoramaShot.capture_count > 1)
                    {   
                        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 0, 1);                       
                        enterState(VAPP_AUTOCAP_STATE_AUTORAMA_CLIP);
                    }
                    else
                    {
                        if(m_osd_cam_panorama_clip_state_param.direction ==VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT || m_osd_cam_panorama_clip_state_param.direction ==VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT)
                        {
                            *(m_osd_cam_panorama_clip_state_param.leftBound) = 0;
                            *(m_osd_cam_panorama_clip_state_param.rightBound) = m_osd_cam_panorama_clip_state_param.quickViewSize[0];    
                        }
                        else
                        {
                            *(m_osd_cam_panorama_clip_state_param.leftBound) = 0;
                            *(m_osd_cam_panorama_clip_state_param.rightBound) = m_osd_cam_panorama_clip_state_param.quickViewSize[1];    
                        }   
                        
                        m_panorama_encode_param.encodeRoiX = 0;
                        m_panorama_encode_param.encodeRoiY = 0;
                        m_panorama_encode_param.encodeRoiW = m_osd_cam_panorama_clip_state_param.quickViewSize[0];            
                        m_panorama_encode_param.encodeRoiH = m_osd_cam_panorama_clip_state_param.quickViewSize[1];  

                        enterState(VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE);
                    }
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 0, 3); 
                    showPopupScreen(param.stitchRet.stitch_ind.result, NULL, m_recoverStateCB);                 
                }
            }                
 
            break;
        }
        case VAPP_AUTOCAP_CB_TYPE_PANORAMA_STITCH:
        {
            if (m_state == VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE)
            {
                m_panoramaShot.stitch_ind.result = param.stitchRet.stitch_ind.result;
                m_panoramaShot.stitch_ind.jpeg_buffer_address = param.stitchRet.stitch_ind.jpeg_buffer_address;
                m_panoramaShot.stitch_ind.jpeg_buffer_size = param.stitchRet.stitch_ind.jpeg_buffer_size;
                m_panoramaShot.stitch_ind.jpeg_image_width = param.stitchRet.stitch_ind.jpeg_image_width;
                m_panoramaShot.stitch_ind.jpeg_image_height = param.stitchRet.stitch_ind.jpeg_image_height;            
                
                m_panoramaShot.is_stitch_done = MMI_TRUE;            
                if (param.stitchRet.stitch_ind.result== MDI_RES_CAMERA_SUCCEED)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 1, 0);                           
                    enterState(VAPP_AUTOCAP_STATE_AUTORAMA_DONE);
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 1, 1);                     
                    showPopupScreen(param.stitchRet.stitch_ind.result, NULL, m_recoverStateCB);                 
                }
            }            
            break;
        }  
        case VAPP_AUTOCAP_CB_TYPE_MAV_CAPTURED:
        {
            if(param.mavRet.captured_count != param.mavRet.total_count)
            {
                m_mavShot.captured_count = param.mavRet.captured_count;
                m_mavShot.total_count = param.mavRet.total_count;

                m_osd_cam_panorama_state_param.isHorzUI = isHorzUI();
                m_osd_cam_panorama_state_param.isMavMode = m_param.isMultiAngleViewMode;
                m_osd_cam_panorama_state_param.count = m_mavShot.captured_count;
                m_osd_cam_panorama_state_param.totalCount = m_mavShot.total_count;
                m_osd_cam_panorama_state_param.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT;
                m_osd_cam_panorama_state_param.previewWindow = m_previewWindow;
                m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT, &m_osd_cam_panorama_state_param, (VappAutoCapOSDEvtHdlr*)this);

                vapp_autocap_osd_screen_param_struct OSDparam;
                OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_DIR_UPDATE;
                OSDparam.direction = VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT;
                m_OSD->setScreenParam(OSDparam);

                OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_RATIO_UPDATE;
                OSDparam.ratio = 0;
                m_OSD->setScreenParam(OSDparam);

                OSDparam.type = VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_MV_UPDATE;
                OSDparam.motionX = param.mavRet.captured_count * m_previewWindow.size.width;
                OSDparam.motionY = 0;
                m_OSD->setScreenParam(OSDparam);
            }
            else
            {
                enterState(VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE);
            }
            break;
        }
        case VAPP_AUTOCAP_CB_TYPE_MAV_SAVE_DONE:
        {
            m_mavShot.result = param.mavRet.result;
            m_mavShot.qv_buffer = param.mavRet.qv_buffer;
            m_mavShot.qv_size = param.mavRet.qv_size;

            if(param.mavRet.result == MDI_RES_CAMERA_SUCCEED)
            {
                enterState(VAPP_AUTOCAP_STATE_AUTORAMA_DONE);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 0, 3);
                showPopupScreen(param.mavRet.result, NULL, m_recoverStateCB);
            }
        }
        case VAPP_AUTOCAP_CB_TYPE_CAM_AF:
        {
        #if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
            if (m_state == VAPP_AUTOCAP_STATE_FOCUSING && !m_hwFlag.isTakepicFailed)
            {
                if (param.afRet.af_result == MDI_AF_SEARCH_STATUS_FOUND_SUCCESS)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 2, 0); 
                    
                    m_autofocus_param.af_success_zone = param.afRet.af_success_zone;
                    
                    playAutofocusSuccessSound();
                    m_hwFlag.isAFsuccess = VFX_TRUE;

                    enterState(VAPP_AUTOCAP_STATE_FOCUSED);
                }
                else if (param.afRet.af_result == MDI_AF_SEARCH_STATUS_SWITCH_MACRO)
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 2, 1);                 

                    vapp_autocap_osd_screen_param_struct af_param;
                    af_param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_SET_FOCUS;
                    af_param.focus.type = VAPP_AUTOCAP_OSD_FOCUS_TYPE_MACRO;
                    m_OSD->setScreenParam(af_param);
                }
                else
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESULT_HW_CALLBACK_EVENT, 2, 2);                 
                    
                    U32 af_active_zone = 0;                
                    
                    af_active_zone = m_autofocus_param.af_active_zone;
                    
                    for (VfxU32 idx = VAPP_AUTOCAP_OSD_FOCUS_REGION_1; idx < VAPP_AUTOCAP_OSD_FOCUS_REGION_END; idx++)
                    {
                        if (af_active_zone & 0x00000001)
                        {
                            vapp_autocap_osd_screen_param_struct af_param;
                            af_param.type = VAPP_AUTOCAP_OSD_SCR_PARAM_SET_FOCUS;
                            af_param.focus.type = VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSING_FAIL;
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
        default:
            ASSERT(0);
    }
}

VfxBool VappAutoCapPage::isSlientMode(void)
{
#ifdef __MMI_AUTOCAP_SILENT_MODE_SUPPORT__
    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == TRUE)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ISSLIENTMODE, 1);       
        return MMI_TRUE;
    }
    else
    {

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ISSLIENTMODE, 0);       
        return MMI_FALSE;
    }
#else /* __MMI_AUTOCAP_SILENT_MODE_SUPPORT__ */     
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_ISSLIENTMODE, 0);   
    return MMI_FALSE;
#endif /* __MMI_AUTOCAP_SILENT_MODE_SUPPORT__ */ 
}


void VappAutoCapPage::playAutofocusSuccessSound(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PLAY_AUTOFOCUS_SUCCESS_SOUND);   

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
}

void VappAutoCapPage::playCatureSound(MDI_RESULT cap_ret)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_PLAY_CATURE_SOUND);   

    U32 aud_len;
    U8 *aud_data = NULL;
    U8 aud_type;
    
    if (cap_ret != MDI_RES_CAMERA_SUCCEED || isSlientMode())
    {
        return;
    }

    switch (m_Setting->getValue(VAPP_AUTOCAP_SETTING_SHUTTERSOUND))
    {
        case VAPP_AUTOCAP_SHUTTERSOUND_OFF:
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1:
            aud_data = get_audio((U16) (AUD_ID_VAPP_AUTOCAP_CAPTURE_1), &aud_type, &aud_len);
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_2:
            aud_data = get_audio((U16) (AUD_ID_VAPP_AUTOCAP_CAPTURE_2), &aud_type, &aud_len);
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_3:
            aud_data = get_audio((U16) (AUD_ID_VAPP_AUTOCAP_CAPTURE_3), &aud_type, &aud_len);
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

MDI_RESULT  VappAutoCapPage::saveCapturedImage(WCHAR *filename, void *imageBuffer, VfxU32 imageBufferSize)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 0);

#ifdef __MTK_TARGET__

    FS_HANDLE file_handle;
    U32 written;
    S32 fs_ret = 0;
    MMI_BOOL is_error_handle_done = MMI_FALSE;
    MDI_RESULT result = VAPP_AUTOCAP_ERR_SAVE_FAIL;

    file_handle = FS_Open((U16*) filename, FS_CREATE | FS_READ_WRITE);

    if (file_handle > 0)
    {
        fs_ret = FS_Write(file_handle, imageBuffer, imageBufferSize, (U32*) & written);
        FS_Close(file_handle);

        if(fs_ret == FS_MSDC_READ_SECTOR_ERROR || fs_ret == FS_MSDC_WRITE_SECTOR_ERROR  || fs_ret == FS_MEDIA_CHANGED)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 3);            
        }            
        /* cant write in whole file, must be disk full */
        else if (imageBufferSize != written)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 3);         
            
            /* delete the file that is not save complete */
            FS_Delete((U16*) filename);

            result = MDI_RES_CAMERA_ERR_DISK_FULL;
            is_error_handle_done = MMI_TRUE;
        }
        else if (fs_ret == 0)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 1);             
            result = MDI_RES_CAMERA_SUCCEED;
        }
    }

    if (file_handle < 0 || (fs_ret < 0 && !is_error_handle_done))
    {

        if (file_handle == FS_DISK_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 4);         
            result = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_ROOT_DIR_FULL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 5);         
            result = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_WRITE_PROTECTION)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 6);         
            result = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SAVE_CAPTURED_IMAGE, 7);         
            result = VAPP_AUTOCAP_ERR_SAVE_FAIL;
        }
    }

    return result;
#else
    return MDI_RES_CAMERA_SUCCEED;    
#endif
}

void VappAutoCapPage::Capture(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_COUNTDOWNLEDTURNOFF, m_state, -1);     

    if (m_state != VAPP_AUTOCAP_STATE_PREVIEW &&
        m_state != VAPP_AUTOCAP_STATE_FOCUSING &&
        m_state != VAPP_AUTOCAP_STATE_FOCUSED)
    {
        return;
    }

    m_panoramaShot.capture_count = 0;
    m_mavShot.captured_count = 0;

    kal_get_time(&m_lastCaptureTime);  
    m_lastDirection = VAPP_AUTOCAP_PANORAMA_DIRECTION_END;
    
    enterState(VAPP_AUTOCAP_STATE_AUTORAMA_SHOT);

}

VfxBool VappAutoCapPage::isAppActive(void)
{
    if ((isInCall() || (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0)) ||
        (srv_reminder_is_expiring()))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_APP_ACTIVE, 0);       
        return VFX_FALSE;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_APP_ACTIVE, 1);       
        return VFX_TRUE;
    }        
}

VfxBool VappAutoCapPage::isInCall(void)
{
#if !defined(__RF_DESENSE_TEST__)
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_DATA_CSD_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_APP_ACTIVE, 1);           
        return VFX_TRUE;
    }
    else
#endif /* !defined(__RF_DESENSE_TEST__) */ 
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_IS_APP_ACTIVE, 0);           
        return VFX_FALSE;
    }
}

VfxU16 VappAutoCapPage::getMappingShownString(MDI_RESULT result, mmi_event_notify_enum *popup_type)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_MAPPING_SHOWN_STRING, result); 

    switch (result)
    {
        case MDI_RES_CAMERA_ERR_DISK_FULL:
            *popup_type = MMI_EVENT_FAILURE;
            return FMGR_FS_DISK_FULL_TEXT;
            //break;

        case MDI_RES_CAMERA_ERR_NO_DISK:
        case MDI_RES_CAMERA_ERR_CAPTURE_FAILED:
        case MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_AUTOCAP_CAPTURE_FAILED;
            //break;

        case VAPP_AUTOCAP_NOT_READY:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_AUTOCAP_NOTIFY_HW_NOT_READY;
            //break;

        case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
            *popup_type = MMI_EVENT_FAILURE;
            return STR_ID_VAPP_AUTOCAP_NOTIFY_WRITE_PROTECT;
            //break;

        case VAPP_AUTOCAP_ERR_SAVE_FAIL:
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

void VappAutoCapPage::showPopupScreen(MDI_RESULT result, void * param, VappAutoCapPopupCallbackFunc callback)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_SHOW_POPUP_SCREEN, result, param); 
    U16 string_id;
    srv_prof_tone_enum tone_type = SRV_PROF_TONE_WARNING;

    if(result != 0)
    {
        mmi_event_notify_enum popup_type;
        string_id = getMappingShownString(result, &popup_type);
        if(!param)
        {    
            VappAutoCapPage::m_errStr = string_id;
        }
        srv_prof_tone_enum tone_type = mmi_get_event_based_sound(popup_type);

        m_CurrentPopupShownresult = result;
    }
    else
    {
        string_id = VappAutoCapPage::m_errStr;    
        tone_type = mmi_get_event_based_sound(MMI_EVENT_FAILURE);        
    }

    if(param)    
        memcpy(&m_popupParam, param,sizeof(vappAutoCapPopupParamStruct)); 
    m_popupCallback = callback;    
    
    if (tone_type != NONE_TONE)
    {
        srv_prof_play_tone(tone_type, NULL);
    }    
    
    if(!param)
    {
        cleanPreviewScreen();
    }
    m_osd_hint_state_param.hintText = VFX_WSTR_RES(string_id);
    m_osd_hint_state_param.isPreviewON = VFX_FALSE;
    m_osd_hint_state_param.bgContent.drawingType = VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR;
    m_osd_hint_state_param.bgContent.bgColor = VRT_COLOR_BLACK;
    if(param)
    {
        m_osd_hint_state_param.event = VAPP_AUTOCAP_OSD_HINT_EVT_OTHERS;    
        m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_PROCESSING;    
    }        
    else
    {
        m_osd_hint_state_param.event = VAPP_AUTOCAP_OSD_HINT_EVT_ERROR;    
        m_osd_hint_state_param.type = VAPP_AUTOCAP_OSD_HINT_TYPE_NOTIFY;   
    }        
    m_osd_hint_state_param.isHorzUI = isHorzUI();
        
    m_OSD->enterState(VAPP_AUTOCAP_OSD_STATE_HINT, &m_osd_hint_state_param, (VappAutoCapOSDEvtHdlr*)this);                  
    m_OSD->updateScreen();                

    vapp_autocap_highlight_turn_off(&m_general_param);    
    if(param)
    {
        m_popupTimer->setStartDelay(VAPP_AUTOCAP_ERROR_TIMER_DUR);
        m_popupTimer->m_signalTick.connect(this, &VappAutoCapPage::popupcallback);
        m_popupTimer->start();    
        m_isPopupRunning = VFX_TRUE;
    }    
    else
    {
        m_isNotifyRunning = VFX_TRUE;   
    }
}

void VappAutoCapPage::stopPopupScreen(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_STOP_POPUP_SCREEN, m_isPopupRunning); 

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

void VappAutoCapPage::popupcallback(VfxTimer *source)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_POPUP_CALLBACK); 

    m_isPopupRunning = VFX_FALSE;
    m_popupCallback.invoke(m_popupParam);
}

void VappAutoCapPage::popupRecovercallback(vappAutoCapPopupParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_POPUP_RECOVERCALLBACK, m_state); 

    ClearKeyEvents();

    switch (m_state)
    {
        case VAPP_AUTOCAP_STATE_PREVIEW:
        case VAPP_AUTOCAP_STATE_FOCUSING:
        case VAPP_AUTOCAP_STATE_FOCUSED:
        case VAPP_AUTOCAP_STATE_AUTORAMA_SHOT:
        case VAPP_AUTOCAP_STATE_AUTORAMA_STITCH:
        case VAPP_AUTOCAP_STATE_AUTORAMA_DONE:
        case VAPP_AUTOCAP_STATE_AUTORAMA_CLIP:
        case VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE:            
            enterState(VAPP_AUTOCAP_STATE_PREVIEW);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

}

void VappAutoCapPage::popupEntercallback(vappAutoCapPopupParamStruct param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_POPUP_ENTER_CALLBACK, param.next_state); 

    enterState(param.next_state);
}

void VappAutoCapPage::cleanPreviewScreen(void)
{
    gdi_handle handleT = m_previewFrame->getLayerHandle();
    gdi_layer_push_and_set_active(handleT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
}

mmi_ret VappAutoCapPage::storageChangeNotifyHdlr(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_STORAGE_NOTIFY);

    VappAutoCapPage* obj = (VappAutoCapPage *)evt->user_data;

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
                //if (event->drv_letters[i] == drive)
                {
                    if(obj->m_param.isMultiAngleViewMode)
                    {
                        if(!obj->m_mavShot.captured_count)
                        {
                            if(obj->m_state == VAPP_AUTOCAP_STATE_PREVIEW)
                                obj->enterState(VAPP_AUTOCAP_STATE_PREVIEW);
                        }
                    }
                    else
                    {
                        if(obj->m_state == VAPP_AUTOCAP_STATE_PREVIEW)
                            obj->enterState(VAPP_AUTOCAP_STATE_PREVIEW);
                    }
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
                //if (event->drv_letters[i] == drive)
                {
                    if(obj->m_state == VAPP_AUTOCAP_STATE_PREVIEW)
                        obj->enterState(VAPP_AUTOCAP_STATE_PREVIEW);
                    return MMI_RET_OK;
                }
            }
            break;               
        }
    }
    return MMI_RET_OK;
    
}

mmi_ret VappAutoCapPage::USBChangeNotigyHdlr(mmi_event_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_USB_NOTIFY);

    VappAutoCapPage *pThis = (VappAutoCapPage*)param->user_data;

    VappAutoCapApp *app = VFX_OBJ_DYNAMIC_CAST(pThis->getApp(), VappAutoCapApp);    
    app->exit();

    return MMI_RET_OK;

}

VfxBool VappAutoCapPage::getNextFilename(WCHAR* fileBuf)
{
#define CAMCO_TEMP_BUFFER_LENGTH_A    (50)
#define CAMCO_MAX_FILE_NUM          (20000)

    CHAR buffer[CAMCO_TEMP_BUFFER_LENGTH_A];
    WCHAR *storageBuffer;
    WCHAR wcsBuffer[CAMCO_TEMP_BUFFER_LENGTH_A];
    WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH_A];
    VfxS16 error = 0;
    VfxU16 filename_seq_no;
    VfxU16 start_no;
    FS_HANDLE file_handle;
    VfxU32 startTicks, endTicks;
    
    kal_get_time(&startTicks);

    if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
        mmi_wcscpy((WCHAR *)g_vapp_mav_prev_file_name, (const WCHAR *)m_camFileNameBuf);     
    else if(m_param.isMultiAngleViewMode && m_param.is3DCameraMode)
        mmi_wcscpy((WCHAR *)g_vapp_3d_camera_prev_file_name, (const WCHAR *)m_camFileNameBuf);    
    else    
        mmi_wcscpy((WCHAR *)g_vapp_autocap_prev_file_name, (const WCHAR *)m_camFileNameBuf); 

    /* get/store sequentail number */
    ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
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
    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_GETNEXTFILENAME, filename_seq_no); 

    do
    {
        sprintf((CHAR *) buffer, "IMG%05d", filename_seq_no);
        mmi_asc_to_wcs(wcsBuffer, (CHAR *) buffer);
        
        mmi_wcscpy(wcsTestname, wcsBuffer);
        if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
        {
            mmi_wcscat(wcsTestname, (WCHAR *) L".mav");
        }
        else
        {
        mmi_wcscat(wcsTestname, (WCHAR *) L".jpg");
        }
        
        mmi_wcscpy(fileBuf, storageBuffer);
        mmi_wcscat(fileBuf, wcsTestname);
        
        file_handle = FS_GetAttributes((U16*) fileBuf);
        if (file_handle < 0)
        {
            /* file not exist */
            WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_GETNEXTFILENAME, -1);                
            return VFX_TRUE;
        }
        
        filename_seq_no++;
        if (filename_seq_no > 20000)    /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_GETNEXTFILENAME, filename_seq_no); 
        if(start_no == filename_seq_no)
            return VFX_FALSE;

        // prevent MMI from taking too long time on finding the next file name
        kal_get_time(&endTicks);
        if((endTicks - startTicks) * 4.615  > 1000)
        {
            WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
            return VFX_FALSE;
        }                
    }while(1);
}

void VappAutoCapPage::restoreFilename(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESTOREFILENAME, 0); 

    VfxS16 error = 0;
    VfxU16 filename_seq_no;

    ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);

    if (filename_seq_no == 1)
    {
        filename_seq_no = 20000;
    }
    else
    {
        filename_seq_no--;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_AUTOCAP_RESTOREFILENAME, filename_seq_no);        
    WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    if(m_param.isMultiAngleViewMode && !m_param.is3DCameraMode)
        mmi_wcscpy(m_camFileNameBuf, g_vapp_mav_prev_file_name); 
    else if(m_param.isMultiAngleViewMode && m_param.is3DCameraMode)
        mmi_wcscpy(m_camFileNameBuf, g_vapp_3d_camera_prev_file_name);   
    else        
        mmi_wcscpy(m_camFileNameBuf, g_vapp_autocap_prev_file_name); 
        
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
                g_vapp_autocap_config.defaultDrv = (VfxU32)storage_evt->drv_letter;
                g_vapp_autocap_config.isSetDefaultStorage = VFX_TRUE;
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
extern "C" mmi_id vapp_autocap_launch_app(void)
{

    vapp_autocap_param_struct param;
    param.isMultiAngleViewMode = KAL_FALSE;
    param.is3DCameraMode = KAL_FALSE;    

    //VappAutoCapCntx.currentAppID = 
    return  VfxAppLauncher::launch( 
                VAPP_AUTOCAP,   
                VFX_OBJ_CLASS_INFO(VappAutoCapApp),
                GRP_ID_ROOT, 
                &param,
                sizeof(vapp_autocap_param_struct));

}


extern "C" MMI_ID vapp_autocap_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = 0;

    if (param == NULL && param_size == 0)
    {
        app_id = vapp_autocap_launch_app();
    }
    else
    {
        switch (param->cat)
        {
        case MMI_LAUNCH_APP_IN_OPEN_CATEGORY:
            app_id = vapp_autocap_launch_app();
            break;
        default:
            break;
        }
    }
    return app_id;
}

extern "C" mmi_ret vapp_autocap_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

extern "C" mmi_ret vapp_autocap_init(mmi_event_struct *event)
{
#define CAMCO_TEMP_BUFFER_LENGTH_B    (256)

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
        mmi_wcscat(wcsTestname, (const WCHAR *) L"autoramaData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            U32 read_size;

            if (FS_Read(file_handle, (CHAR*)g_vapp_autocap_prev_file_name, 256*2, &read_size) >= 0)
            {
                isGetnameSuccess = VFX_TRUE;
            }
        }
        FS_Close(file_handle);
    }

    if(!isGetnameSuccess)
    {
        // init previous file name buffer
        memset(g_vapp_autocap_prev_file_name, 0, 512);
    }
    return MMI_RET_OK;
}

// ==========================================================================================
// 3D camera
// ==========================================================================================
extern "C" mmi_id vapp_3d_camera_launch_app(void)
{

    vapp_autocap_param_struct param;
    param.isMultiAngleViewMode = KAL_TRUE;
    param.is3DCameraMode = KAL_FALSE;

    //VappAutoCapCntx.currentAppID =
    return  VfxAppLauncher::launch(
                VAPP_3D_CAMERA,
                VFX_OBJ_CLASS_INFO(VappAutoCapApp),
                GRP_ID_ROOT,
                &param,
                sizeof(vapp_autocap_param_struct));

}


extern "C" MMI_ID vapp_3d_camera_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = 0;

    if (param == NULL && param_size == 0)
    {
        app_id = vapp_3d_camera_launch_app();
    }
    else
    {
        switch (param->cat)
        {
        case MMI_LAUNCH_APP_IN_OPEN_CATEGORY:
            app_id = vapp_3d_camera_launch_app();
            break;
        default:
            break;
        }
    }
    return app_id;
}

extern "C" mmi_ret vapp_3d_camera_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

extern "C" mmi_ret vapp_3d_camera_init(mmi_event_struct *event)
{
#define CAMCO_TEMP_BUFFER_LENGTH_C    (256)

    VfxBool isGetnameSuccess = VFX_FALSE;
    FS_HANDLE file_handle;
    WCHAR drv_buf[8];
    CHAR buf[64];

    if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_SYSTEM_DRV, FS_MOUNT_STATE_ENUM))
    {
        WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH_C];

        sprintf((CHAR *)buf, "%c:\\", (U8)SRV_FMGR_SYSTEM_DRV);
        mmi_asc_to_wcs(drv_buf, (CHAR *)buf);

        mmi_wcscpy(wcsTestname, drv_buf);
        mmi_wcscat(wcsTestname, (const WCHAR *) L"mavData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            U32 read_size;

            if (FS_Read(file_handle, (CHAR*)g_vapp_mav_prev_file_name, 256*2, &read_size) >= 0)
            {
                isGetnameSuccess = VFX_TRUE;
            }
        }
        FS_Close(file_handle);
    }

    if(!isGetnameSuccess)
    {
        // init previous file name buffer
        memset(g_vapp_mav_prev_file_name, 0, 512);
    }

    isGetnameSuccess = VFX_FALSE;

    if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_SYSTEM_DRV, FS_MOUNT_STATE_ENUM))
    {
        WCHAR wcsTestname[CAMCO_TEMP_BUFFER_LENGTH_C];

        sprintf((CHAR *)buf, "%c:\\", (U8)SRV_FMGR_SYSTEM_DRV);
        mmi_asc_to_wcs(drv_buf, (CHAR *)buf);

        mmi_wcscpy(wcsTestname, drv_buf);
        mmi_wcscat(wcsTestname, (const WCHAR *) L"3DcameraData.camco");

        file_handle = FS_Open((U16*) wcsTestname, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            U32 read_size;

            if (FS_Read(file_handle, (CHAR*)g_vapp_3d_camera_prev_file_name, 256*2, &read_size) >= 0)
            {
                isGetnameSuccess = VFX_TRUE;
            }
        }
        FS_Close(file_handle);
    }

    if(!isGetnameSuccess)
    {
        // init previous file name buffer
        memset(g_vapp_3d_camera_prev_file_name, 0, 512);
    }

    return MMI_RET_OK;
}

#endif
