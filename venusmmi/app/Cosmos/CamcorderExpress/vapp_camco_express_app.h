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
#ifndef __VAPP_CAMCO_EXPRESS_APP__
#define __VAPP_CAMCO_EXPRESS_APP__

#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_camera.h"
#include "MMI_features_camcorder.h"
#include "MMI_include.h"

#include "vcui_camco_gprot.h"

#ifdef __cplusplus
}
#endif

#ifdef __VAPP_CAMCO_EXPRESS__
#include "vapp_camco_express_osd_mgr.h"
#include "vapp_camco_express_setting_mgr.h"
#include "vapp_camco_express_osd.h"

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* defined(__MM_DEBUG_MEASURE__) */
#define VAPP_CAMCO_START_LOGGING(_symbol_)
#define VAPP_CAMCO_STOP_LOGGING(_symbol_)
#endif /* defined(__MM_DEBUG_MEASURE__) */

#if (AF_SUPPORT)
//#ifdef __KBD_2STEP_KEY_SUPPORT__
    #define VAPP_CAMCO_AF_SUPPORT
//#else
    //#define VAPP_CAMCO_TOUCH_AF_SUPPORT
//#endif
#endif

#if defined(__MTK_INTERNAL__) && !defined(__MTK_TARGET__)
/* under construction !*/
#endif

#if defined(__MMI_CAMCO_FEATURE_CAM_ASD_SHOT__)
//#define __VAPP_CAMCO_ASD_ALWAYS_SHOW_ICON__
#endif

class CamcoOSDMgr;
class CamcoSettingMgr;
class VappCamcoApp;
class VappCamcoPage;
class OSDStartingState;

#define VAPP_CAMCO_ERROR_TIMER_DUR           (2000)      /* 1000 ms */

// App event type
#define VAPP_CAMCO_CAM_NOT_READY             (-1)
#define VAPP_CAMCO_ERR_SAVE_FAIL             (-2)
#define VAPP_CAMCO_ERR_FILE_NAME_NOTFOUND    (-3)

#define VAPP_CAMCO_REC_SIZE_LIMIT_NO_LIMIT   (0)
#define VAPP_CAMCO_REC_SIZE_LIMIT_1          (95)            /* 95k */
#define VAPP_CAMCO_REC_SIZE_LIMIT_2          (195)           /* 195k */
#define VAPP_CAMCO_REC_SIZE_LIMIT_3          (295)           /* 295k */

#define VAPP_CAMCO_REC_TIME_LIMIT_NO_LIMIT   (0)
#define VAPP_CAMCO_REC_TIME_LIMIT_1          (15)            /* 15 sec */
#define VAPP_CAMCO_REC_TIME_LIMIT_2          (30)            /* 30 sec */
#define VAPP_CAMCO_REC_TIME_LIMIT_3          (60)            /* 60 sec */
#define VAPP_CAMCO_REC_TIME_LIMIT_4          (300)           /* 300 sec */
#define VAPP_CAMCO_REC_TIME_LIMIT_5          (600)           /* 600 sec */

typedef enum
{
    VAPP_CAMCO_STATE_EXIT = 0,               /* 0 */
/*****************************************************************/
/*******************      Camera       ***************************/
/*****************************************************************/
    /* main lcd */
    VAPP_CAMCO_STATE_CAM_PREVIEW,            /* 1 */
    VAPP_CAMCO_STATE_CAM_PREVIEW_FAILED,     /* 2 */
    VAPP_CAMCO_STATE_CAM_FOCUSING,           /* 3 */
    VAPP_CAMCO_STATE_CAM_FOCUSED,            /* 4 */
    VAPP_CAMCO_STATE_CAM_COUNTDOWN,          /* 5 */
    VAPP_CAMCO_STATE_CAM_CAPTURE,            /* 6 */
    VAPP_CAMCO_STATE_CAM_SAVE_DONE,          /* 7 */

    /* interrupt */
    VAPP_CAMCO_STATE_CAM_INT_PREVIEW,        /* 9 */

/*****************************************************************/
/*******************      Video Recorder    **********************/
/*****************************************************************/
    VAPP_CAMCO_STATE_REC_PREVIEW,            /* 10 */
    VAPP_CAMCO_STATE_REC_PREVIEW_FAILED,     /* 11 */
    VAPP_CAMCO_STATE_REC_FOCUSING,           /* 12 */
    VAPP_CAMCO_STATE_REC_FOCUSED,            /* 13 */
    VAPP_CAMCO_STATE_REC_RECORDING,          /* 14 */
    VAPP_CAMCO_STATE_REC_PAUSE,              /* 15 */
    VAPP_CAMCO_STATE_REC_SAVING,             /* 16 */
    VAPP_CAMCO_STATE_REC_SAVE_DONE,          /* 17 */

    /* interrupt */
    VAPP_CAMCO_STATE_REC_INT_PREVIEW,        /* 18 */
    VAPP_CAMCO_STATE_REC_INT_SAVING,         /* 19 */

    VAPP_CAMCO_STATE_ENTER_FAIL,             /* 20 */
    VAPP_CAMCO_STATE_INT_ENTER_FAIL,         /* 21 */

    VAPP_CAMCO_STATE_END
}vapp_camco_state_enum;

typedef enum
{
    VAPP_CAMCO_CB_TYPE_RECORD_FINISH,
    VAPP_CAMCO_CB_TYPE_RECORD_SAVE,
    VAPP_CAMCO_CB_TYPE_CAM_AF,
    VAPP_CAMCO_CB_TYPE_REC_AF,

    VAPP_CAMCO_CB_TYPE_END
}vapp_camco_cb_type;

typedef struct
{
    U64                                         rec_size;
    U64                                         rec_time;
}vapp_camco_rec_record_struct;

typedef struct
{
    vapp_camco_state_enum                       next_state;
}vapp_camco_popup_callback_param_struct;

typedef VfxCallback1<vapp_camco_popup_callback_param_struct> VappCamcoPopupCallbackFunc;

typedef struct
{
    MDI_RESULT                                  result;

    VfxBool                                     isNeedClearScrn;
    VfxBool                                     isConfirm;
    VappCamcoPopupCallbackFunc                  callback;
    vapp_camco_popup_callback_param_struct      callbackParam;
}vapp_camco_popup_param_struct;

typedef struct
{
    VfxU32                                      dummy;
} vapp_camco_restart_param_struct;

typedef VfxCallback1<vapp_camco_restart_param_struct> VappCamcoRestartCallbackFunc;

typedef struct
{
    VfxBool                                     isPowerOn;
    VfxBool                                     isPreviewStart;

    VfxBool                                     isAFon;
    VfxBool                                     isAFsuccess;

    VfxBool                                     isTakepicFailed;

    VfxBool                                     isBurstshotFinish;

    VfxBool                                     isHDRing;

    VfxBool                                     isOnRecord;
    VfxBool                                     isRecordFailed;
    VfxBool                                     isRecSaveSuccess;
    VfxBool                                     isRecSaveCallback;

    VfxBool                                     isSmiledetectStart;

    VfxBool                                     isCalBgProcessOn;
}vapp_camco_hw_flag_struct;

// =============================================================================
// MDI related opeation parameter start
// =============================================================================
typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_cam_power_on_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_cam_power_off_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_rec_power_on_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_rec_power_off_param_struct;

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
typedef struct
{
    VappCamcoPage                              *obj;
    vapp_camco_hw_flag_struct                  *flag;

    MDI_RESULT                                  fd_result;       /* Face detection result */
    VfxU32                                      fd_searched_num;        /* The number of found face */

    MMI_BOOL                                    sd_end_flag;
    VfxU8                                       sd_searched_num;

    mdi_camera_fd_zone_struct                   fd_zone[MDI_CAMERA_FD_MAX_NO];    /* The array of face detection zone */
}vapp_camco_cam_sd_param_struct;
#endif

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;

    VfxVideoFrame                              *previewFrame;

    VfxBool                                     isResetZoom;

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    vapp_camco_cam_sd_param_struct             *sd_data;
#endif
}vapp_camco_cam_preview_start_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_cam_preview_stop_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;

    VfxVideoFrame                              *previewFrame;
}vapp_camco_rec_preview_start_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_rec_preview_stop_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;

    // normal . add frame . best
    WCHAR                                      *fileName;
    void                                       *capture_buf_ptr;
    VfxU32                                      capture_size;

    // quick view
    VfxVideoFrame                              *previewFrame;
    void                                       *quickviewBuffer;
}vapp_camco_cam_capture_param_struct;

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
typedef struct
{
    VappCamcoPage                              *obj;
    vapp_camco_hw_flag_struct                  *flag;

    VfxU16                                      currentScene;
}vapp_camco_cam_scene_param_struct;
#endif

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_cam_capture_save_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
    VfxVideoFrame                              *previewFrame;

    WCHAR                                      *fileName;
}vapp_camco_rec_record_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;

    WCHAR                                      *fileName;
}vapp_camco_rec_record_save_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;

    WCHAR                                      *fileName;

    // quick view
    VfxVideoFrame                              *previewFrame;
    VfxRect                                    *previewWindow;

    void                                       *quickviewBuffer;

    VfxBool                                     isRecWithHorzUI;
    VfxBool                                     isRecWithMirrorUI;
}vapp_camco_rec_fetch_param_struct;

#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
typedef struct
{
    VappCamcoPage                              *obj;
    vapp_camco_hw_flag_struct                  *flag;
    mdi_camera_af_window_struct                 af_zone;
    mdi_video_rec_af_window_struct              rec_af_zone;
    VfxU32                                      af_active_zone;
    VfxU32                                      af_success_zone;
}vapp_camco_autofocus_param_struct;
#endif

typedef struct
{
    CamcoSettingMgr                            *Setting;
    VfxU32                                      size;
    VfxU32                                      reserve_size;
}vapp_camco_estimate_size_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_cal_background_param_struct;

typedef struct
{
    VappCamcoPage                              *obj;
    CamcoSettingMgr                            *Setting;
    vapp_camco_hw_flag_struct                  *flag;
}vapp_camco_general_param_struct;

typedef struct
{
    vapp_camco_cb_type                          type;

    VfxU32                                      buffer_address;
    VfxU32                                      buffer_size;
    MDI_RESULT                                  HDRresult;

    // AF
    mdi_camera_af_result_struct                 afRet;
    mdi_video_rec_af_result_struct              recAfRet;

    // Record
    MDI_RESULT                                  recordRet;
}vapp_camco_hw_result_callback_param_struct;
// =============================================================================
// MDI related opeation parameter end
// =============================================================================

// =============================================================================
// independent to object of camcorder, for all instance
// =============================================================================
typedef struct
{
    VfxBool                                     isSetDefaultStorage;
    VfxU32                                      defaultDrv;

}vapp_camco_global_config_struct;

// =================================================================================
// OSD event hander abstract interface
// App will implement this for receive OSD event
// =================================================================================
class VappCamcoOSDEvtHdlr
{
public:
    virtual void camPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void camPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void camSaveDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void camCountdownHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    virtual void camFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
#endif
    virtual void recPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void recPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void recRecordingHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void recPauseHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void recSaveDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    virtual void recFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
#endif

    // process error popup event
    virtual void errorPopupHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;

    // process global App event (for all osd State)
    virtual void appGlobalEventHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
};

class VappCamcoApp : public VfxApp
{
   VFX_DECLARE_CLASS(VappCamcoApp);

public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onInit(void);
};

class VcuiCamcoApp : public VfxCui
{
   VFX_DECLARE_CLASS(VcuiCamcoApp);

public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VcuiStandardCameraApp : public VfxCui
{
   VFX_DECLARE_CLASS(VcuiStandardCameraApp);

public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VcuiStandardRecorderApp : public VfxCui
{
   VFX_DECLARE_CLASS(VcuiStandardRecorderApp);

public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VcuiSlimCameraApp : public VfxCui
{
   VFX_DECLARE_CLASS(VcuiSlimCameraApp);

public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VappCamcoScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappCamcoScreen);

// Override
public:
    virtual void onInit();
    virtual void on1stReady();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    void setCallingParam(vcui_camco_param_struct param);
    virtual void onRotate(const VfxScreenRotateParam &param);
private:
    vcui_camco_param_struct m_param;
};

class VappCamcoPage : public VfxPage, VappCamcoOSDEvtHdlr
{
    VFX_DECLARE_CLASS(VappCamcoPage);

public:
    virtual void onInit();
    virtual void onDeinit();

    virtual void onEnter(VfxBool isBackward);
    void onEntered(VfxTimer *source);
    virtual void onExit(VfxBool isBackward);

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    void updateVideoFramRotate(VfxBool needRotateContent, VfxScrRotateTypeEnum from, VfxScrRotateTypeEnum to);

    void setCallingParam(vcui_camco_param_struct param);

    // callback manger related interface
    static mmi_ret fileMgrEventHdlr(mmi_event_struct *param);
    static mmi_ret storageChangeNotifyHdlr(mmi_event_struct *param);
    static mmi_ret USBChangeNotigyHdlr(mmi_event_struct *param);
    static mmi_ret fontChangeNotigyHdlr(mmi_event_struct *param);

    // App pre-running env. related interface
    static VfxBool checkEnv(void);
    static VfxBool decheckEnv(void);

    // memory related interface
    void configMem(void);
    void resetMem(void);

    // App running env. related interface
    void initEnv(void);
    void deinitEnv(void);

    // save path related interface
    void findLastFileName(VfxBool isCameraApp);
    VfxU64 getFreeStorageSize(void);
    VfxBool checkRemovableStorage(void);
    VfxBool checkSavePath(void);

    // init related interface
    void initSetting();
    void initApp(void);
    void initPreviewWindow(void);

    // state related interface
    void enterState(vapp_camco_state_enum state);
    void exitState(void);
    void recoverState(vapp_camco_state_enum state);
    void setState(vapp_camco_state_enum state){m_state = state;};
    vapp_camco_state_enum getState(void){return m_state;};

    // OSD state event handler implementation
    virtual void camPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void camPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void camSaveDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void camCountdownHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void recPreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void recPreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void recRecordingHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void recPauseHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void recSaveDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    void camFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    void recFocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
#endif
    virtual void errorPopupHdlr(mmi_cameco_evt_type_enum evt_type, void* param);

    virtual void appGlobalEventHdlr(mmi_cameco_evt_type_enum evt_type, void* param);

    // state enter function
    void enterExitState(void);
    void enterCamPreviewState(void);
    void enterCamPreviewFailedState(void);
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    void enterCamFocusingState(void);
    void enterCamFocusedState(void);
#endif
    void enterCamCountdownState(void);
    void enterCamCaptureState(void);
    void enterCamSaveDoneState(void);
    void enterCamContshotState(void);
#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    void enterCamSmileDectState(void);
#endif

    void enterRecPreviewState(void);
    void enterRecPreviewFailedState(void);
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    void enterRecFocusingState(void);
    void enterRecFocusedState(void);
#endif
    void enterRecRecordingState(void);
    void enterRecPauseState(void);
    void enterRecSavingState(void);
    void enterRecSaveDoneState(void);
    void enterEnterFailState(void);

    // MDI callback handle interface
    void resultHWCallback(vapp_camco_hw_result_callback_param_struct param);

    // video frame dalay restart preview related interface
    void camRestartPreview(vapp_camco_restart_param_struct param);
    void recRestartPreview(vapp_camco_restart_param_struct param);
    void onPreviewFramePrepareDone(void);

    // smile detect related interface
#ifdef __FACE_DETECTION_SUPPORT__
    void smiledetectCyclic(VfxTimer *source);
#endif
#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    void smiledetectSuccess(VfxTimer *source);
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    // scene detect related interface
    void sceneDetectCyclic(VfxTimer *source);
#endif

    // countdown related interface
    void countdownCyclic(VfxTimer *source);

    // recording related interface
    void playSoundandRecord(void);
    void recordToneCyclic(VfxTimer *source);
    void recordingCyclic(VfxTimer *source);
    void recordingFinishTick(VfxTimer *source);

    // audio related interface
    VfxBool isSlientMode(void);
    void initCountDownSound(void);
    void deinitCountDownSound(void);
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    void playAutofocusSuccessSound(void);
#endif
    void playCatureSound(MDI_RESULT cap_ret);
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    void autoFocusToneCyclic(VfxTimer *source);
#endif

    // condition check related interface
    VfxBool isAppActive(void);
    static VfxBool isInCall(void);

    // timer related interface
    void onErrorExitTimerTick(VfxTimer *source);
    void onPreviewFrameDoneDelayTick(VfxTimer *source);

    // popup related interface
    void showPopupScreen(vapp_camco_popup_param_struct * param);
    void stopPopupScreen(void);
    void popupcallback(VfxTimer *source);
    void popupRecovercallback(vapp_camco_popup_callback_param_struct param);
    void popupEntercallback(vapp_camco_popup_callback_param_struct param);
    void exitCamcoCUI(vapp_camco_popup_callback_param_struct param);
    VfxU16 getMappingShownString(MDI_RESULT result, mmi_event_notify_enum *popup_type);
    VfxTimer *m_popupTimer;

    // file name related interface
    VfxBool getNextFilename(WCHAR* fileBuf);
    void restoreFilename(void);
    void getStartingFilenameIdx(void);
    void setStartingFilenameIdx(void);

    // Misc.
    void cleanPreviewScreen(void);
    VfxPoint transPointToOSDCoord(VfxPoint p, VfxScrRotateTypeEnum from, VfxScrRotateTypeEnum to);

    void Capture(void);

    // profiling
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
#endif

// variables
public:

    vapp_camco_state_enum                               m_state;                        // App state

    vcui_camco_param_struct                             m_param;                        // App calling paramter, tell App
                                                                                        //  1) App is camera/recorder/full
                                                                                        //  2) setting mode is full/connim/ none
                                                                                        //  3) addition limitaion

    CamcoOSDMgr*                                        m_OSD;                          // OSD manager
    OSDStartingState                                   *m_enterScreenOSD;                // the first screen after entering Ap, easy to sho no need to load any setting
    CamcoSettingMgr*                                    m_Setting;                      // Setting manager

    VfxU32                                              m_appID;                        // App instance ID

    // flag
    VfxBool                                             m_isAppInited;                  // if the OSD/Setting Object is created and initialized
    VfxBool                                             m_isStartingApp;                // if the App is in Starting state;
    VfxBool                                             m_isStartingHorz;               // if the rotation is Horz during starting app
    VfxBool                                             m_isPreemptable;                // nmgr status (if app is at highest level)
    VfxBool                                             m_isExtCalling;                 // if CUI mode or not
    VfxBool                                             m_isMainLcdPreview;             // if use main LCD or not (current not used)
    VfxBool                                             m_isVideoLayerHorz;             // if video layer is Horz or not
    VfxBool                                             m_isOSDHorz;                    // if G sensor rot angle is Horz or not
    VfxBool                                             m_isOSDMirror;                  // if G sensor rot angle is Mirror or not
    VfxBool                                             m_isOSDinSmileDetectMode;       // if UI is on SD mdoe (auto-capture only on this mode)
    VfxBool                                             m_isAFTonePlaying;              // if the AF tone is play (cannot capture at that time)
    VfxBool                                             m_isFontChanged;                // if font is changed (it will cause re-entry camcorder)
    VfxBool                                             m_isGetFileList;                // if still get file list (because vdo open and preview is exclusive)
    vapp_camco_hw_flag_struct                           m_hwFlag;                       // including HW related flags

    VfxScrRotateTypeEnum                                m_currentRotation;              // the current rotata angle of OSD

    // preview related
    VfxRect                                             m_previewWindow;                // original preview window size on original LCD size
    VfxVideoFrame*                                      m_previewFrame;                 // preview video frame
    VfxFrame                                           *m_picturePreviewFrame;
    VappCamcoRestartCallbackFunc                        m_restartPreviewCallback;
    VappCamcoRestartCallbackFunc                        m_camRestartPreviewCallback;
    VappCamcoRestartCallbackFunc                        m_recRestartPreviewCallback;
    VfxBool                                             m_isStartingPreview;
    VfxTimer                                           *m_delayPreviewTimer;
    VfxBool                                             m_isDelayPreview;
    void                                               *m_prepareFramePtr;
    VfxU32                                              m_prepareFrameSize;

    // memory config related
    void                                               *m_appMemBuffer;                 // pointer to start addr of whole ASM buffer
    void                                               *m_appMemQuickViewBuffer;        // the quick view memory

    // popup related
    VfxBool                                             m_isPopupRunning;
    VfxBool                                             m_isNotifyRunning;
    vapp_camco_popup_param_struct                       m_currentPopupParam;
    VappCamcoPopupCallbackFunc                          m_enterStateCB;
    VappCamcoPopupCallbackFunc                          m_recoverStateCB;
    VappCamcoPopupCallbackFunc                          m_exitStateCB;

    // error msg related
    static MMI_ID                                       m_errStr;
    VcpImageButton                                     *m_back;

    // count down sound related
    mdi_handle                                          m_multiSoundDummy;
    mdi_handle                                          m_multiSoundCountdown;
    VfxU8                                               m_countSpundType;
    VfxU32                                              m_countSoundLen;
    VfxU32                                              m_countSoundDuration;
    VfxU8                                              *m_countSoundData;

    // file name related
    WCHAR                                              *m_camFileNameBuf;
    VfxU16                                              m_camStartingFilenameIdx;
    WCHAR                                              *m_recFileNameBuf;
    VfxU16                                              m_recStartingFilenameIdx;

    // count down related
    VfxU32                                              m_countdownDuration;
    VfxU32                                              m_countdownStartTicks;
    VfxU32                                              m_countdownEndTicks;
    VfxTimer                                           *countdownCycTimer;

    // enter / exit related
    VfxTimer                                           *m_autoExitTimer;
    VfxTimer                                           *m_errorExitTimer;
    VfxTimer                                           *m_postEnterTimer;

    // smile detect related
#ifdef __FACE_DETECTION_SUPPORT__
    VfxTimer                                           *m_smileDetectCycTimer;
#endif
#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    VfxTimer                                           *m_smileDetectSuccessTimer;
#endif

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    // auto scene detect timer
    VfxTimer                                           *m_sceneDetectCycTimer;
#endif

    // record related
    vapp_camco_rec_record_struct                        m_record;
    MDI_RESULT                                          m_recordSaveResult;
    MDI_RESULT                                          m_recordRecordingResult;
    VfxTimer                                           *m_recordToneTimer;
    VfxTimer                                           *m_recordUpdateTimer;
    VfxBool                                             m_isSaveBeforeLeave;
    VfxBool                                             m_isTonePlaying;


    /* HW param */
    vapp_camco_cam_preview_start_param_struct           m_cam_preview_start_param;
    vapp_camco_cam_preview_stop_param_struct            m_cam_preview_stop_param;
    vapp_camco_rec_preview_start_param_struct           m_rec_preview_start_param;
    vapp_camco_rec_preview_stop_param_struct            m_rec_preview_stop_param;
    vapp_camco_cam_power_on_param_struct                m_cam_power_on_param;
    vapp_camco_cam_power_off_param_struct               m_cam_power_off_param;
    vapp_camco_rec_power_on_param_struct                m_rec_power_on_param;
    vapp_camco_rec_power_off_param_struct               m_rec_power_off_param;
    vapp_camco_cam_capture_param_struct                 m_cam_capture_param;
    vapp_camco_cam_capture_save_param_struct            m_cam_capture_save_param;
    vapp_camco_rec_record_param_struct                  m_rec_record_param;
    vapp_camco_rec_record_save_param_struct             m_rec_record_save_param;
    vapp_camco_rec_fetch_param_struct                   m_rec_fetch_param;
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    vapp_camco_autofocus_param_struct                   m_autofocus_param;
#endif
#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    vapp_camco_cam_sd_param_struct                      m_cam_smiledetect_param;
#endif
    vapp_camco_general_param_struct                     m_general_param;
    vapp_camco_estimate_size_param_struct               m_cam_est_size_param;
    vapp_camco_estimate_size_param_struct               m_rec_est_size_param;
    vapp_camco_cal_background_param_struct              m_cam_bg_process_param;
#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    vapp_camco_cam_scene_param_struct                   m_cam_scene_param;
#endif

    /* OSD param */
    vapp_camco_osd_starting_param_struct                m_osd_starting_state_param;
    vapp_camco_osd_hide_param_struct                    m_osd_hide_state_param;
    vapp_camco_osd_hint_param_struct                    m_osd_hint_state_param;
    vapp_camco_osd_cam_preview_param_struct             m_osd_cam_preview_state_param;
    vapp_camco_osd_rec_preview_param_struct             m_osd_rec_preview_state_param;
    vapp_camco_osd_rec_recording_param_struct           m_osd_recording_state_param;
    vapp_camco_osd_rec_pause_param_struct               m_osd_pause_state_param;
    vapp_camco_osd_quick_view_param_struct              m_osd_rec_quick_view_state_param;
    vapp_camco_osd_quick_view_param_struct              m_osd_cam_quick_view_state_param;
#if defined(VAPP_CAMCO_AF_SUPPORT) || defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
    vapp_camco_osd_focuse_param_struct                  m_osd_focuse_state_param;
    vapp_camco_osd_focuse_hint_param_struct             m_osd_focuse_hint_state_param;
#endif

    // thumbnail file related
    SRV_FMGR_FILELIST_HANDLE                            m_fileListHandle;
    double                                              m_lastFileTime;
    VfxS32                                              m_lastFileindex;

    //backlight
    VfxU8                                               m_backlightBeforeRecording;

    //Misc
    VfxU8                                               m_cbmId;

    // profiling
#if defined(__MTK_INTERNAL__) && defined (__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

};

// class implementation is at source file


#endif /*__VAPP_CAMCO_EXPRESS__*/
#endif /*__VAPP_CAMCO_EXPRESS_APP__*/
