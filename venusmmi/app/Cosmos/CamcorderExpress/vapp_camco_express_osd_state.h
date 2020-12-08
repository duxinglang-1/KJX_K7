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

#ifndef __VAPP_CAMCO_EXPRESS_OSD_STATE__
#define __VAPP_CAMCO_EXPRESS_OSD_STATE__

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_image_button.h"
#include "vcp_slider.h"
#include "vapp_camco_express_osd.h"
#include "vapp_camco_express_app.h"
#include "vapp_camco_express_cp_advance_menu.h"
#include "vapp_camco_express_cp_circle_menu.h"
#include "vapp_camco_express_cp_slider.h"
#include "vapp_camco_express_cp_rect_frame.h"
#include "vapp_camco_express_cp_rotatable.h"
#include "MMI_include.h"
#include "mmi_features_camcorder.h"

#ifdef __VAPP_CAMCO_EXPRESS__

class VappCamcoOSDEvtHdlr;

class CamcoOSDState : public VfxControl
{
#define  VAPP_CAMCO_OSD_AUTO_EXIT_TIME    (120000)

public:
    virtual void onInit(void);

    vapp_camco_osd_state_enum getStateName(void){return m_state;};

    virtual void enterState(void* param);
    virtual void exitState(void);
    virtual void drawBase(vapp_camco_osd_draw_image_struct param);

    VfxPoint coordTransform(VfxS32 x, VfxS32 y, VfxScrRotateTypeEnum targetAngle);
    void regEvtHdlr(VappCamcoOSDEvtHdlr* Hdlr){evtHdlr = Hdlr;};

    // auto exit related interface
    void refreshAutoExitTimer(void);
    void setAutoExitTimer(VfxTimer* t);
    virtual void AutoExitTimoutProcess(void);
    void onAutoExitTimerTick(VfxTimer *source);

    // event process related interface
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

    // state status related
    void setStatus(VfxBool isSet, vapp_camco_osd_state_status_enum type);
    VfxBool getStatus(vapp_camco_osd_state_status_enum type);
    VfxBool isUsableStatus(void);

    // rotate related
    void setHorz(VfxBool isHorz, VfxBool isMirror);
    VfxBool isHorz(void){return m_isHorz;};
    virtual void rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle);

    vapp_camco_osd_state_enum       m_state;        // the type of the state
    VfxU32                          m_status;       // the status of the state
                                                    //   0 means available
                                                    //   and otehrs values mean under some processing and cannot do others action)

    // rotate related
    VfxBool                         m_isHorz;       // if the OSD is under Horz coordination
    VfxBool                         m_isMirror;     // if the OSD is under Mirror coordination
    VfxScrRotateTypeEnum            m_scrnAngle;    // current screen rotation angle

    VfxBool                         m_isOnEnter;    // if it is under onEnter() function now
    VappCamcoOSDEvtHdlr            *evtHdlr;        // OSD event handler
    VfxTimer                       *m_autoExitTimer;// the timer for notify user has no action for 2 mins
};

class OSDStartingState : public CamcoOSDState
{
public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle);

private:
    VappCamcoCpRotatableImageButton *m_switcher;
    VappCamcoCpRotatableImageFrame  *m_switcherRec;
    VappCamcoCpRotatableImageFrame  *m_switcherCam;
    VappCamcoCpRotatableFrame       *m_galleryContainer;
    VappCamcoCpRotatableImageButton *m_gallery;
    VappCamcoCpRotatableFrame       *m_galleryContent;
    VappCamcoCpRotatableImageButton *m_capture;
    VappCamcoCpRotatableImageButton *m_captureContent;
    VappCamcoCpRotatableImageButton *m_sensorSwitcher;
    VappCamcoCpRotatableFrame       *m_rightBar;
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
    virtual void rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle);

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
#define CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER  2
#define CAMCO_CAM_PREVIEW_RESET_TIME 10000
#define CAMCO_CAM_PREVIEW_MOVE_THRESHOLD 15

typedef enum
{
    VAPP_CAMCO_PREVIEW_MODE_NORMAL,
    VAPP_CAMCO_PREVIEW_MODE_CLEAR,
    VAPP_CAMCO_PREVIEW_MODE_DIRSETTING,
    VAPP_CAMCO_PREVIEW_MODE_ADSETTING,
    VAPP_CAMCO_PREVIEW_MODE_SMILEDETECT,
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
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    void cleanFocus(void);
    void setFocus(VfxU32 idx, vapp_camco_osd_focus_struct region);
#endif
    void updateThumbnail(WCHAR *previousFileName);
    void updateZoomParam(VfxU32 v);
    void updateRemainSizeParam(VfxU32 v);
    void updateIndicatorMsg(VfxU32 v);
    void updateScnIcon(void);
    virtual void rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle);

private:
    void setNormalMode(void);
    void setClearMode(void);
    void setAdvanceSettingMode(void);
    void setDirectSettingMode(void);
    void setSmileDetectMode(void);

    void layout(void);
    void updateIcon(void);

    void onDirectSettingSeleted(VfxU32 ID);
    void onAdvanceSettingSelected(VfxU32 id, VfxU32 idx);
    void onZooming(VfxU32 value);
    void onFlashClicked(VfxObject *obj, VfxId id);
    void onAdvanceSettingClicked(VfxObject *obj, VfxId id);
    void onGalleryClicked(VfxObject *obj, VfxId id);
    void onCaptureClicked(VfxObject* obj, VfxId id);
    void onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state);
    void onSwitchSensorClicked(VfxObject *obj, VfxId id);
    void onSwitchAppClicked(VfxObject* obj, VfxId id);
    void onSwitchAppTick(VfxTimer *source);
    void onResetTimerTick(VfxTimer *source);
    void onDelayRestartPreviewTick(VfxTimer *source);

    void ZoomingIn(VfxTimer *source);
    void ZoomingOut(VfxTimer *source);

    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

    VappCamcoCpDirectSettingMenu    *m_directSettingControl;
    VappCamcoCpAdvanceMenu          *m_advanceSettingControl;

    VappCamcoCpRotatableImageButton *m_advanceSetting;
    VappCamcoCpRotatableFrame       *m_advanceSettingBg;
    VappCamcoCpRotatableImageButton *m_flashSetting;
    VappCamcoCpRotatableFrame       *m_flashSettingBg;

    VappCamcoCpSlider               *m_zoomer;
    VappCamcoCpRotatableImageButton *m_switcher;
    VappCamcoCpRotatableImageFrame  *m_switcherRec;
    VappCamcoCpRotatableImageFrame  *m_switcherCam;
    VappCamcoCpRotatableFrame       *m_galleryContainer;
    VappCamcoCpRotatableImageButton *m_gallery;
    VappCamcoCpRotatableFrame       *m_galleryContent;
    VappCamcoCpRotatableImageButton *m_capture;
    VappCamcoCpRotatableButton      *m_captureContent;
    VappCamcoCpRotatableImageButton *m_sensorSwitcher;

    VappCamcoCpRotatableFrame       *m_rightBar;
    VappCamcoCpRotatableImageFrame  *m_statusInd[CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER];
    VappCamcoCpRect                 *m_faceDetectRegion[VAPP_CAMCO_SUPPORT_FACE_NUM];
    VappCamcoCpRect                 *m_smileDetectRegion[VAPP_CAMCO_SUPPORT_FACE_NUM];
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    VfxImageFrame                   *m_indicatorImage;
    VappCamcoCpRect                 *m_focusRegion[VAPP_CAMCO_OSD_FOCUS_REGION_END];
#endif
    VappCamcoCpRotatableImageFrame  *m_smileDetectInd;

    VappCamcoCpRotatableTextFrame   *m_capturableNumber;
    VappCamcoCpRotatableTextFrame   *m_indicatorMsg;
    VappCamcoCpRotatableFrame       *m_indicatorMsgBg;

    vapp_camco_cam_preview_mode_enum m_mode;

    vapp_camco_osd_cam_preview_param_struct m_cntx;

    VfxBool                         m_isFirstEnter;
    VfxBool                         m_isFocussing;

    VfxTimer                        *m_resetScreenTimer;
    VfxTimer                        *m_zoomingTimer;
};

class OSDRecPreviewState : public CamcoOSDState
{
#define CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER  1
#define CAMCO_REC_PREVIEW_RESET_TIME 10000

   typedef enum
   {
       VAPP_CAMCO_PREVIEW_MODE_NORMAL,
       VAPP_CAMCO_PREVIEW_MODE_CLEAR,
       VAPP_CAMCO_PREVIEW_MODE_DIRSETTING,
       VAPP_CAMCO_PREVIEW_MODE_ADSETTING,
       VAPP_CAMCO_PREVIEW_MODE_END

   }vapp_camco_rec_preview_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    void cleanFocus(void);
    void setFocus(VfxU32 idx, vapp_camco_osd_focus_struct region);
#endif
    void updateThumbnail(WCHAR *previousFileName);
    void updateRemainSizeParam(VfxU32 v);
    void updateIndicatorMsg(VfxU32 v);
    virtual void rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle);

private:
    void setNormalMode(void);
    void setClearMode(void);
    void setAdvanceSettingMode(void);
    void setDirectSettingMode(void);

    void layout(void);
    void updateIcon(void);

    void onDirectSettingSeleted(VfxU32 ID);
    void onAdvanceSettingSelected(VfxU32 id, VfxU32 idx);
    void onZooming(VfxU32 value);
    void onFlashClicked(VfxObject *obj, VfxId id);
    void onAdvanceSettingClicked(VfxObject *obj, VfxId id);
    void onGalleryClicked(VfxObject *obj, VfxId id);
    void onCaptureClicked(VfxObject* obj, VfxId id);
    void onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state);
    void onSwitchSensorClicked(VfxObject *obj, VfxId id);
    void onSwitchAppClicked(VfxObject* obj, VfxId id);
    void onSwitchAppTick(VfxTimer *source);
    void onResetTimerTick(VfxTimer *source);
    void onDelayRestartPreviewTick(VfxTimer *source);

    void ZoomingIn(VfxTimer *source);
    void ZoomingOut(VfxTimer *source);

    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    VappCamcoCpDirectSettingMenu    *m_directSettingControl;
    VappCamcoCpAdvanceMenu          *m_advanceSettingControl;

    VappCamcoCpRotatableImageButton *m_advanceSetting;
    VappCamcoCpRotatableFrame       *m_advanceSettingBg;
    VappCamcoCpRotatableImageButton *m_flashSetting;
    VappCamcoCpRotatableFrame       *m_flashSettingBg;

    VappCamcoCpSlider               *m_zoomer;
    VappCamcoCpRotatableImageButton *m_switcher;
    VappCamcoCpRotatableImageFrame  *m_switcherRec;
    VappCamcoCpRotatableImageFrame  *m_switcherCam;
    VappCamcoCpRotatableFrame       *m_galleryContainer;
    VappCamcoCpRotatableImageButton *m_gallery;
    VappCamcoCpRotatableFrame       *m_galleryContent;
    VappCamcoCpRotatableImageButton *m_record;
    VappCamcoCpRotatableButton      *m_recordContent;
    VappCamcoCpRotatableImageButton *m_sensorSwitcher;

    VappCamcoCpRotatableFrame       *m_rightBar;
    VappCamcoCpRotatableImageFrame  *m_statusInd[CAMCO_REC_PREVIEW_STATUS_ICON_NUMBER];
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    VfxImageFrame                   *m_indicatorImage;
    VappCamcoCpRect                 *m_focusRegion[VAPP_CAMCO_OSD_FOCUS_REGION_END];
#endif
    VappCamcoCpRotatableTextFrame   *m_recordableTime;
    VappCamcoCpRotatableTextFrame   *m_indicatorMsg;
    VappCamcoCpRotatableFrame       *m_indicatorMsgBg;

    vapp_camco_rec_preview_mode_enum m_mode;

    vapp_camco_osd_rec_preview_param_struct m_cntx;

    VfxBool                         m_isFirstEnter;
    VfxBool                         m_isFocussing;

    VfxTimer                        *m_resetScreenTimer;
    VfxTimer                        *m_zoomingTimer;
};

class OSDRecRecordingState : public CamcoOSDState
{
    #define CAMCO_REC_SHIFT_DIS  80
    #define CAMCO_REC_RESET_TIME 5000

    typedef enum
    {
        VAPP_CAMCO_REC_MODE_NORMAL,
        VAPP_CAMCO_REC_MODE_CLEAR,
        VAPP_CAMCO_REC_MODE_END
    }vapp_camco_rec_recording_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);
    void setRecParam(VfxU32 time, VfxU32 size);

    virtual void rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle);

private:
    void setNormalMode(void);
    void setClearMode(void);

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

    VappCamcoCpSlider                           *m_zoomer;
    VappCamcoCpRotatableImageFrame              *m_recIcon;
    VappCamcoCpRotatableTextFrame               *m_recInfo;
    VappCamcoCpRotatableImageButton             *m_stop;
    VappCamcoCpRotatableImageButton             *m_stopContent;
    VappCamcoCpRotatableImageButton             *m_pause;
    VappCamcoCpRotatableImageButton             *m_pauseContent;
    VappCamcoCpRotatableImageFrame              *m_timelapseIcon;

    VfxTimer                                    *m_resetScreenTimer;
    VfxTimer                                    *m_zoomingTimer;

    vapp_camco_rec_recording_mode_enum           m_mode;

    vapp_camco_osd_rec_recording_param_struct    m_cntx;
};

class OSDRecPauseState : public CamcoOSDState
{
    #define CAMCO_REC_SHIFT_DIS  80
    #define CAMCO_REC_RESET_TIME 5000

    typedef enum
    {
        VAPP_CAMCO_REC_MODE_NORMAL,
        VAPP_CAMCO_REC_MODE_CLEAR,
        VAPP_CAMCO_REC_MODE_END
    }vapp_camco_rec_pause_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);

    virtual void rotateOSD(VfxScrRotateTypeEnum fromAngle, VfxScrRotateTypeEnum toAngle);

private:
    void setNormalMode(void);
    void setClearMode(void);

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

    VappCamcoCpSlider                       *m_zoomer;
    VappCamcoCpRotatableImageFrame          *m_recIcon;
    VappCamcoCpRotatableTextFrame           *m_recInfo;
    VappCamcoCpRotatableImageButton         *m_stop;
    VappCamcoCpRotatableImageButton         *m_stopContent;
    VappCamcoCpRotatableImageButton         *m_resume;
    VappCamcoCpRotatableImageButton         *m_resumeContent;
    VappCamcoCpRotatableImageFrame          *m_timelapseIcon;

    VfxTimer                                *m_resetScreenTimer;
    VfxTimer                                *m_zoomingTimer;

    vapp_camco_rec_pause_mode_enum          m_mode;

    vapp_camco_osd_rec_pause_param_struct   m_cntx;
};

class OSDQuickViewState : public CamcoOSDState
{
public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);
    virtual void drawBase(vapp_camco_osd_draw_image_struct param);

private:
    void onEffectTimerTick(VfxTimer *source);

    VfxImageFrame                           *m_shownImage;
    VfxTimer                                *m_effectTimer;
    vapp_camco_osd_quick_view_param_struct   m_cntx;
};

#endif /*__VAPP_CAMCO_EXPRESS__*/
#endif /*__VAPP_CAMCO_EXPRESS_OSD_STATE__*/