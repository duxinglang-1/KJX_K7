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

#ifndef __VAPP_CAMC_OOSD_STATE__
#define __VAPP_CAMC_OOSD_STATE__

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_image_button.h"
#include "vcp_slider.h"
#include "vapp_camco_osd.h"
#include "vapp_camco_app.h"
#include "vapp_camco_cp_base_menu.h"
#include "vapp_camco_cp_advance_menu.h"
#include "vapp_camco_cp_circle_menu.h"
#include "vapp_camco_cp_slider.h"
#include "vapp_camco_cp_switcher.h"
#include "vapp_camco_cp_rect_frame.h"
#include "vapp_camco_cp_rotatable.h"
#include "MMI_include.h"
#include "mmi_features_camcorder.h"

#ifdef __VAPP_CAMCO__

class VappCamcoOSDEvtHdlr;

class CamcoOSDState : public VfxControl
{   
#define  VAPP_CAMCO_OSD_AUTO_EXIT_TIME    (120000)

public:
    virtual void onInit(void);

    virtual void enterState(void* param);
    virtual void exitState(void);  
    virtual void drawBase(vapp_camco_osd_draw_image_struct param);        
    void updateScreen(void);
    virtual void clean(const VfxColor &value = VFX_COLOR_TRANSPARENT);
    void enableState(void){setHidden(VFX_FALSE); };
    void disableState(void){setHidden(VFX_TRUE); };    
    VfxPoint coordTransform2Vertical(VfxS32 x, VfxS32 y);
    void setAutoExitTimer(VfxTimer* t);
    void refreshAutoExitTimer(void);
    vapp_camco_osd_state_enum getStateName(void){return m_state;};    
    void regEvtHdlr(VappCamcoOSDEvtHdlr* Hdlr){evtHdlr = Hdlr;};
    virtual void AutoExitTimoutProcess(void);
    void onAutoExitTimerTick(VfxTimer *source);    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    void setisBusy(VfxBool isBusy){m_isBusy = isBusy;};
    VfxBool getisBusy(void){return m_isBusy;};    
    void setHorz(VfxBool isHorz, VfxBool isMirror);    
    VfxBool isHorz(void){return m_isHorz;};
    virtual void rotateOSD(VfxBool isHorz, VfxBool isMirror);
    
    vapp_camco_osd_state_enum       m_state;
    VfxBool                         m_isBusy;
    VfxBool                         m_isActive;
    VfxBool                         m_isHorz;
    VfxBool                         m_isMirror;    
    VfxBool                         m_isOnEnter;
    VappCamcoOSDEvtHdlr            *evtHdlr;
    VfxTimer                       *m_autoExitTimer;


};

class OSDStartingState : public CamcoOSDState
{
public:
    virtual void onInit(void);
    virtual void enterState(void* param);    
    virtual void exitState(void);    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:    
    VappCamcoCpRotatableImageButton *m_switcher;  
    VappCamcoCpRotatableFrame       *m_switcherRec;
    VappCamcoCpRotatableFrame       *m_switcherCam;
    VappCamcoCpRotatableImageButton *m_gallery;
    VappCamcoCpRotatableFrame       *m_galleryContent;        
    VappCamcoCpRotatableImageButton *m_usedSensor;
    VappCamcoCpRotatableImageButton *m_unusedSensor;     
    VappCamcoCpRotatableImageFrame  *m_rightBar;   
};


class OSDHideState : public CamcoOSDState
{
public:
    virtual void onInit(void);
    virtual void enterState(void* param);    

private:    
    vapp_camco_osd_hide_param_struct m_cntx;
};

class OSDHinteState : public CamcoOSDState
{

public:
    virtual void onInit(void);
    virtual void enterState(void* param);    
    virtual void exitState(void);      
    virtual void drawBase(vapp_camco_osd_draw_image_struct param);  
    void setHint(VfxWString hint);    
    void onOkClicked(VfxObject *obj, VfxId id);
    void onBackClicked(VfxObject *obj, VfxId id);  
    void onConfirmClicked(VfxObject *obj, VfxId id);
    virtual void rotateOSD(VfxBool isHorz, VfxBool isMirror);

private:
    VfxTextFrame                        *m_hint;
    VcpIndicatorPopup                   *m_processingPopup;    
    VcpIndicatorPopup                   *m_IndicatorPopup;   
    VcpConfirmPopup                     *m_confirmPopup;    
    VcpConfirmPopup                     *m_notifyPopup;        
    VfxImageFrame                       *m_icon;    
    VfxImageFrame                       *m_background;
    vapp_camco_osd_hint_param_struct     m_cntx;

};


class OSDCamPreviewState : public CamcoOSDState
{
#define CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER  8
//#define CAMCO_CAM_PREVIEW_CAPTUABLE_DIGIT  4
#define CAMCO_CAM_PREVIEW_SHIFT_DIS  80
#define CAMCO_CAM_PREVIEW_RESET_TIME 10000
#define CAMCO_CAM_PREVIEW_MOVE_THRESHOLD 15

typedef enum
{
    VAPP_CAMCO_PREVIEW_MODE_NORMAL,
    VAPP_CAMCO_PREVIEW_MODE_TRANSITION,        
    VAPP_CAMCO_PREVIEW_MODE_CLEAR,            
    VAPP_CAMCO_PREVIEW_MODE_DIRSETTING,                
    VAPP_CAMCO_PREVIEW_MODE_ADSETTING,
    VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT,    
    VAPP_CAMCO_PREVIEW_MODE_FRAME_SELECT,    
    VAPP_CAMCO_PREVIEW_MODE_END
    
}vapp_camco_cam_preview_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);    
    void cleanFaceDetect(void);
    void setFaceDetect(VfxU32 idx, vapp_camco_osd_facedetect_region_struct region);
    void cleanSmileDetect(void);    
    void setSmileDetect(VfxU32 idx, vapp_camco_osd_smiledetect_region_struct region);  
    void cleanFocus(void);
    void setFocus(VfxU32 idx, vapp_camco_osd_focus_struct region);
    void updateZoomParam(VfxU32 v);
    void updateRemainSizeParam(VfxU32 v);    
    void updateIndicatorMsg(VfxU32 v);    
    void updateScnIcon(void);
    void enterSmileDetect(void);
    virtual void rotateOSD(VfxBool isHorz, VfxBool isMirror);
    
private:
    void setNormalMode(void);
    void setClearMode(void);
    void setClearModeinternal(VfxTimer *source);    
    void setAdvanceSettingMode(void);
    void setDirectSettingMode(VfxObject * target);
    void setSmileDetectMode(void);
    void setFrameSelectMode(void);

    void layout(void);
    void updateIcon(void);
    void updateSettingBar(VfxS16 isForceDirection);    
    void updateAuxiliary(void);

    void onBeforeSettingEnter(VfxU32 ID);
    void onSettingEnter(VfxU32 ID);
    void onSettingTraverse(VfxU32 ID);    
    void onDirectSettingLeave(VfxObject* sender, VfxId id);    
    void onAdvanceSettingLeave(VfxObject* sender, VfxId id);
    void onAdvanceSettingTraverse(VfxU32 id);    
    void onZooming(VfxU32 value);  
    void onSettingSet(VfxU32 ID);     
    void onGalleryClicked(VfxObject *obj, VfxId id);    
    void onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state);
    void onCaptureClicked(VfxObject* obj, VfxId id);    
    void onSwitchSensorClicked(VfxObject *obj, VfxId id);
    void onSwitchAppClicked(VfxObject* obj, VfxId id);    
    void onSwitchAppTick(VfxTimer *source);
    void onResetClicked(VfxObject *obj, VfxId id);        
    void onResetTimerTick(VfxTimer *source);      
    void onGalleryTimerTick(VfxTimer *source);    
    void onCPEffctDoneTick(VfxU32 ID);    
    void onCPEffctDoneTick2(VfxU32 ID);        
    void onPostProcessTimerTick(VfxTimer *source);
    void onAdvanceSettingSelected(VfxU32 id, VfxU32 idx);
    void onRestoreConfirm(VfxObject* obj, VfxId id);  
    void onSettingError(VfxObject* obj, VfxId id);
    void ZoomingIn(VfxTimer *source);       
    void ZoomingOut(VfxTimer *source);          
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

    VfxBool isHorzUI(void);    
        
    VappCamcoCpBaseMenu             *m_settingBar;      
    VappCamcoCpCircleMenu           *m_directSettingControl;        
    VappCamcoCpAdvanceMenu          *m_advanceSettingControl;            
    
    VappCamcoCpSlider               *m_zoomer;       
    VappCamcoCpRotatableImageButton *m_switcher;  
    VappCamcoCpRotatableFrame       *m_switcherRec;
    VappCamcoCpRotatableFrame       *m_switcherCam;    
    VappCamcoCpRotatableFrame       *m_galleryContainer;
    VappCamcoCpRotatableImageButton *m_gallery;
    VappCamcoCpRotatableFrame       *m_galleryContent;        
    VappCamcoCpRotatableButton      *m_usedSensor;
    VappCamcoCpRotatableImageButton *m_unusedSensor; 
    
    VappCamcoCpRotatableFrame       *m_coverFrame;   
    
    VappCamcoCpRotatableImageFrame  *m_rightBar;    
    VappCamcoCpRotatableImageFrame  *m_statusInd[CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER];         
    VappCamcoCpRect                 *m_faceDetectRegion[VAPP_CAMCO_SUPPORT_FACE_NUM];
    VappCamcoCpRect                 *m_smileDetectRegion[VAPP_CAMCO_SUPPORT_FACE_NUM];
    VappCamcoCpRotatableImageFrame  *m_imageFrame; // add frame selected frame

    VfxImageFrame                   *m_indicatorImage;
    VappCamcoCpRect                 *m_focusRegion[VAPP_CAMCO_OSD_FOCUS_REGION_END];

    VcpConfirmPopup                 *m_confirmPopup;    
    
    VappCamcoCpRotatableTextFrame   *m_capturableNumber;   
    VappCamcoCpRotatableFrame       *m_auxiliary[4];
    VappCamcoCpRotatableTextFrame   *m_indicatorMsg;    
    VappCamcoCpRotatableImageFrame  *m_indicatorMsgBg;    
    
    vapp_camco_cam_preview_mode_enum m_mode;
    vapp_camco_cam_preview_mode_enum m_previousMode;           //only valid after start fade out UI and before enter clean mode
    VfxObject*                       m_previousModeDirSettingObj;
    
    vapp_camco_osd_facedetect_struct m_facedetect;   
    vapp_camco_osd_smiledetect_struct m_smiledetect;           
    vapp_camco_osd_cam_preview_param_struct m_cntx;  

    vapp_camco_capmode_enum          m_CurrentCapmode;
    
    VfxS32                           m_lastX;
    VfxS32                           m_hiliteFrameIdx;

    VfxBool                          m_isDownProcessed;
    VfxBool                          m_isdelaySD;
    VfxBool                          m_isdelayRestartPreview;    
    VfxBool                          m_isOSDHorz;
    VfxBool                          m_isClicking;    
    VfxBool                          m_isFocussing;

    VfxTimer                        *m_resetScreenTimer;
    VfxTimer                        *m_fadeOutScreenTimer;       
    VfxTimer                        *m_postProcessTimer;   
    VfxTimer                        *m_zoomingTimer;    
    VfxTimer                        *m_clickTimer;      
};


class OSDCamContShotState : public CamcoOSDState
{
#define VAPP_CAMCO_CONT_SHOT_FREQ 1500

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);
    virtual void drawBase(vapp_camco_osd_draw_image_struct param);     
    virtual void rotateOSD(VfxBool isHorz, VfxBool isMirror);    
    void oncaptureTimerTick(VfxTimer *source);
    void onStopTimerTick(VfxTimer *source);
    void onCapture(VcpImageButton* obj, VcpImageButtonStateEnum state);    
    virtual VfxBool onPenInput(VfxPenEvent & event);   
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
private:
    VappCamcoCpRotatableImageButton         *m_capture;
    vapp_camco_osd_cam_contshot_param_struct m_cntx;   
    VfxBool                                  m_keyDown;

    VfxTimer                                *m_captureTimer;
    VfxTimer                                *m_stopTimer;    

};


class OSDRecPreviewState : public CamcoOSDState
{
//#define CAMCO_REC_PREVIEW_CAPTUABLE_DIGIT  3   
#define CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER  7
#define CAMCO_REC_PREVIEW_SHIFT_DIS  80
#define CAMCO_REC_PREVIEW_RESET_TIME 10000
   
   typedef enum
   {
       VAPP_CAMCO_PREVIEW_MODE_NORMAL,
       VAPP_CAMCO_PREVIEW_MODE_TRANSITION,        
       VAPP_CAMCO_PREVIEW_MODE_CLEAR,            
       VAPP_CAMCO_PREVIEW_MODE_DIRSETTING,                
       VAPP_CAMCO_PREVIEW_MODE_ADSETTING,
       VAPP_CAMCO_PREVIEW_MODE_END
       
   }vapp_camco_rec_preview_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);    
    void cleanFaceDetect(void);
    void setFaceDetect(VfxU32 idx, vapp_camco_osd_facedetect_region_struct region);
    void cleanSmileDetect(void);    
    void setSmileDetect(VfxU32 idx, vapp_camco_osd_smiledetect_region_struct region);  
    void cleanFocus(void);
    void setFocus(VfxU32 idx, vapp_camco_osd_focus_struct region);
    void updateRemainSizeParam(VfxU32 v);    
    void updateIndicatorMsg(VfxU32 v); 
    virtual void rotateOSD(VfxBool isHorz, VfxBool isMirror);
    
private:
    void setNormalMode(void);
    void setClearMode(void);
    void setClearModeinternal(VfxTimer *source);    
    void setAdvanceSettingMode(void);
    void setDirectSettingMode(VfxObject * target);

    void layout(void);
    void updateIcon(void);

    void updateSettingBar(VfxS16 isForceDirection);

    void onBeforeSettingEnter(VfxU32 ID);    
    void onSettingEnter(VfxU32 ID);
    void onSettingTraverse(VfxU32 ID);    
    void onDirectSettingLeave(VfxObject* sender, VfxId id);    
    void onAdvanceSettingLeave(VfxObject* sender, VfxId id);
    void onAdvanceSettingTraverse(VfxU32 id);   
    void onZooming(VfxU32 value);    
    void onSettingSet(VfxU32 ID);    
    void onGalleryClicked(VfxObject *obj, VfxId id);    
    void onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state);
    void onCaptureClicked(VfxObject* obj, VfxId id);
    void onSwitchSensorClicked(VfxObject *obj, VfxId id);
    void onSwitchAppClicked(VfxObject* obj, VfxId id);    
    void onSwitchAppTick(VfxTimer *source);    
    void onResetClicked(VfxObject *obj, VfxId id);        
    void onResetTimerTick(VfxTimer *source);     
    void onGalleryTimerTick(VfxTimer *source);    
    void onCPEffctDoneTick(VfxU32 ID);    
    void onCPEffctDoneTick2(VfxU32 ID);        
    void onAdvanceSettingSelected(VfxU32 id, VfxU32 idx);
    void onRestoreConfirm(VfxObject* obj, VfxId id);     
    void onSettingError(VfxObject* obj, VfxId id);    
    void ZoomingIn(VfxTimer *source);       
    void ZoomingOut(VfxTimer *source);          
    VfxBool isHorzUI(void);    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    VappCamcoCpBaseMenu             *m_settingBar;          
    VappCamcoCpCircleMenu           *m_directSettingControl;        
    VappCamcoCpAdvanceMenu          *m_advanceSettingControl;            
    
    VappCamcoCpSlider               *m_zoomer;       
    VappCamcoCpRotatableImageButton *m_switcher; 
    VappCamcoCpRotatableFrame       *m_switcherRec;
    VappCamcoCpRotatableFrame       *m_switcherCam;    
    VappCamcoCpRotatableFrame       *m_galleryContainer;
    VappCamcoCpRotatableImageButton *m_gallery;
    VappCamcoCpRotatableFrame       *m_galleryContent;    
    VappCamcoCpRotatableButton      *m_usedSensor;
    VappCamcoCpRotatableImageButton *m_unusedSensor; 

    VfxImageFrame                   *m_indicatorImage;
    VappCamcoCpRect                 *m_focusRegion[VAPP_CAMCO_OSD_FOCUS_REGION_END];

    VappCamcoCpRotatableFrame       *m_coverFrame;
    
    VappCamcoCpRotatableImageFrame  *m_rightBar;    
    VappCamcoCpRotatableImageFrame  *m_statusInd[CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER];   
    VappCamcoCpRotatableTextFrame   *m_recordableTime;   
    VappCamcoCpRotatableTextFrame   *m_indicatorMsg;    
    VappCamcoCpRotatableImageFrame  *m_indicatorMsgBg;    

    VcpConfirmPopup                 *m_confirmPopup;

    vapp_camco_rec_preview_mode_enum m_mode;
    vapp_camco_rec_preview_mode_enum m_previousMode;                  //only valid after start fade out UI and before enter clean mode
    VfxObject*                       m_previousModeDirSettingObj;
        
    vapp_camco_osd_rec_preview_param_struct m_cntx;  

    VfxBool                          m_isDownProcessed;
    VfxBool                          m_isOSDHorz;    
    VfxBool                          m_isClicking;   
    VfxBool                          m_isFocussing;

    VfxTimer                        *m_resetScreenTimer;
    VfxTimer                        *m_fadeOutScreenTimer;      
    VfxTimer                        *m_zoomingTimer;
    VfxTimer                        *m_clickTimer;      
};

class OSDRecRecordingState : public CamcoOSDState
{
    #define CAMCO_REC_SHIFT_DIS  80
    #define CAMCO_REC_RESET_TIME 5000

    typedef enum
    {
        VAPP_CAMCO_REC_MODE_NORMAL,
        VAPP_CAMCO_REC_MODE_TRANSITION,            
        VAPP_CAMCO_REC_MODE_CLEAR,            
        VAPP_CAMCO_REC_MODE_END
        
    }vapp_camco_rec_recording_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param); 
    virtual void exitState(void);    
    void setRecParam(VfxU32 time, VfxU32 size);
    
private:

    void setRotate(VfxBool isHorz, VfxBool isMirror);

    void setNormalMode(void);
    void setClearMode(void);
    void setClearModeinternal(VfxTimer *source);   

    void layout(void);

    void onStopClicked(VfxObject *obj, VfxId id);    
    void onPauseClicked(VfxObject *obj, VfxId id);
    void onResetClicked(VfxObject *obj, VfxId id); 
    void onZooming(VfxU32 value);        
    void onResetTimerTick(VfxTimer *source);
    void ZoomingIn(VfxTimer *source);       
    void ZoomingOut(VfxTimer *source);           
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    VappCamcoCpSlider *m_zoomer;       
    VappCamcoCpRotatableImageFrame *m_recIcon;
    VappCamcoCpRotatableTextFrame *m_recInfo;    
    VappCamcoCpRotatableImageButton *m_stop;
    VappCamcoCpRotatableImageButton *m_pause;
    VappCamcoCpRotatableImageFrame *m_timelapseIcon;

    VfxTimer *m_resetScreenTimer;
    VfxTimer *m_fadeOutScreenTimer;    
    VfxTimer *m_zoomingTimer;

    vapp_camco_rec_recording_mode_enum m_mode;

    VfxU32 rec_time;
    VfxU32 rec_size;    
    VfxU32 rec_progress;    

    vapp_camco_osd_rec_recording_param_struct m_cntx;     

};

class OSDRecPauseState : public CamcoOSDState
{
    #define CAMCO_REC_SHIFT_DIS  80
    #define CAMCO_REC_RESET_TIME 5000

    typedef enum
    {
        VAPP_CAMCO_REC_MODE_NORMAL,
        VAPP_CAMCO_REC_MODE_TRANSITION,            
        VAPP_CAMCO_REC_MODE_CLEAR,            
        VAPP_CAMCO_REC_MODE_END
        
    }vapp_camco_rec_pause_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);
    
private:

    void setRotate(VfxBool isHorz, VfxBool isMirror);

    void setNormalMode(void);
    void setClearMode(void);
    void setClearModeinternal(VfxTimer *source);    

    void layout(void);

    void onStopClicked(VfxObject *obj, VfxId id);    
    void onResumeClicked(VfxObject *obj, VfxId id);
    void onResetClicked(VfxObject *obj, VfxId id);   
    void onZooming(VfxU32 value);    
    void onResetTimerTick(VfxTimer *source);
    void ZoomingIn(VfxTimer *source);       
    void ZoomingOut(VfxTimer *source);      

    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    VappCamcoCpSlider *m_zoomer;       
    VappCamcoCpRotatableImageFrame *m_recIcon;
    VappCamcoCpRotatableTextFrame *m_recInfo;    
    VappCamcoCpRotatableImageButton *m_stop;
    VappCamcoCpRotatableImageButton *m_resume;
    VappCamcoCpRotatableImageFrame *m_timelapseIcon;
    //VcpProgressIndicator *m_progress; 

    VfxTimer *m_resetScreenTimer;
    VfxTimer *m_fadeOutScreenTimer;  
    VfxTimer *m_zoomingTimer;
    
    vapp_camco_rec_pause_mode_enum m_mode;

    vapp_camco_osd_rec_pause_param_struct m_cntx;     
  
};

class OSDCamQuickViewState : public CamcoOSDState
{
    #define VAPP_CAMCO_CAM_QK_VIEW_ANUMATE (0)
public:

    virtual void onInit(void);
    virtual void enterState(void* param);   
    virtual void drawBase(vapp_camco_osd_draw_image_struct param);  
    
private:
    void onEffectTimerTick(VfxTimer *source);
    void onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);    
        
    VfxImageFrame  *m_shownImage;    
    vapp_camco_osd_cam_quick_view_param_struct m_cntx;   
    
    VfxTimer *m_effectTimer;    

};

class OSDRecQuickViewState : public CamcoOSDState
{
    #define VAPP_CAMCO_REC_QK_VIEW_ANUMATE (0)
public:
    
    virtual void onInit(void);
    virtual void enterState(void* param);   
    virtual void drawBase(vapp_camco_osd_draw_image_struct param);  
        
private:
    void onEffectTimerTick(VfxTimer *source);
    void onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);    
    
    VfxImageFrame  *m_shownImage;    
    vapp_camco_osd_rec_quick_view_param_struct m_cntx;   
    
    VfxTimer *m_effectTimer;    


};

class OSDCamMultiQuickViewState : public CamcoOSDState
{
#define VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM 5
#define VAPP_CAMCO_CAM_MULTI_SHOT_MOVE_SPEED 500
#define VAPP_CAMCO_MULTI_QK_VIEW_ANUMATE (0)

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);
    virtual void drawBase(VfxImageFrame *target, vapp_camco_osd_draw_image_struct param);
    void rotateQuickView(VfxBool isHorz, VfxBool isMirror);
    virtual void rotateOSD(VfxBool isHorz, VfxBool isMirror);
    
private:

    virtual VfxBool onPenInput(VfxPenEvent & event);
    void onSaveClicked(VfxObject *obj, VfxId id);    
    void onEndOfSlideTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void onEndOfSelectEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);    
    void onEndOfSelectEffectTimeline2(VfxBaseTimeline *timeline, VfxBool isCompleted);        
    void onEndOfSaveTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    VfxImageFrame                       *m_imageFlow[2];  
    VappCamcoCpRotatableImageButton     *m_save;
    VfxImageFrame                       *m_capturedPic[VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM];    
    VappCamcoCpRotatableImageFrame      *m_check[VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM];    
    VfxImageFrame                       *m_bar;        
    VfxFrame                            *m_ind;     
    VcpActivityIndicator                *m_waittingIcon;

    vapp_camco_osd_cam_quick_view_param_struct  m_cntx; 
    VfxU32                                      m_hiliteIdx;
    VfxS32                                      m_lastX;
    VfxS32                                      m_lastY;    
    VfxBool                                     m_active;    
    VfxBool                                     m_isDownProcessed;
    VfxBool                                     m_isChecked[VAPP_CAMCO_CAM_MULTI_SHOT_MAX_NUM];    
    VfxBool                                     m_isImageFrameMoving;
    VfxBool                                     m_isOSDHorz;
    VfxBool                                     m_isAnimating;    

};



#endif

#endif
