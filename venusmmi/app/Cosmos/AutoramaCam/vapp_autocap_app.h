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

#ifndef __VAPP_AUTOCAP_APP__
#define __VAPP_AUTOCAP_APP__

#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_camera.h"
#include "MMI_features_camcorder.h"
#include "MMI_include.h"


#ifdef __cplusplus
}
#endif

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))
#include "vapp_autocap_osd_mgr.h"
#include "vapp_autocap_setting_mgr.h"
#include "vapp_autocap_osd.h"

#if (AF_SUPPORT)
//#ifdef __KBD_2STEP_KEY_SUPPORT__
    #define VAPP_AUTOCAP_AF_SUPPORT
//#else
    //#define VAPP_AUTOCAP_TOUCH_AF_SUPPORT
//#endif
#endif

#if defined(__MTK_INTERNAL__) && !defined(__MTK_TARGET__)
/* under construction !*/
#endif

class AutoCapOSDMgr;
class AutoCapSettingMgr;
class VappAutoCapApp;
class VappAutoCapPage;
class AutoCapOSDStartingState;

#define VAPP_AUTOCAP_ERROR_TIMER_DUR           (2000)      /* 1000 ms */

// App event type
#define VAPP_AUTOCAP_NOT_READY             (-1)
#define VAPP_AUTOCAP_ERR_SAVE_FAIL             (-2)
#define VAPP_AUTOCAP_ERR_FILE_NAME_NOTFOUND    (-3)

typedef enum
{
    VAPP_AUTOCAP_STATE_EXIT = 0,               /* 0 */
/*****************************************************************/
/*******************      Camera       ***************************/
/*****************************************************************/
    /* main lcd */
    VAPP_AUTOCAP_STATE_PREVIEW,            /* 1 */
    VAPP_AUTOCAP_STATE_PREVIEW_FAILED,     /* 2 */
    VAPP_AUTOCAP_STATE_FOCUSING,           /* 3 */
    VAPP_AUTOCAP_STATE_FOCUSED,            /* 4 */
    VAPP_AUTOCAP_STATE_AUTORAMA_SHOT,      /* 5 */
    VAPP_AUTOCAP_STATE_AUTORAMA_STITCH,    /* 6 */
    VAPP_AUTOCAP_STATE_AUTORAMA_CLIP,      /* 7 */    
    VAPP_AUTOCAP_STATE_AUTORAMA_ENCODE,    /* 8 */        
    VAPP_AUTOCAP_STATE_AUTORAMA_DONE,      /* 9 */

    /* interrupt */
    VAPP_AUTOCAP_STATE_INT_PREVIEW,            /* 10 */

    VAPP_AUTOCAP_STATE_ENTER_FAIL,             /* 11 */    
    VAPP_AUTOCAP_STATE_INT_ENTER_FAIL,         /* 12 */  

    VAPP_AUTOCAP_STATE_END

}vapp_autocap_state_enum;

typedef enum
{
    VAPP_AUTOCAP_CB_TYPE_PANORAMA_QUICK_VIEW,       
    VAPP_AUTOCAP_CB_TYPE_PANORAMA_STITCH,        
    VAPP_AUTOCAP_CB_TYPE_MAV_CAPTURED,
    VAPP_AUTOCAP_CB_TYPE_MAV_SAVE_DONE,
    VAPP_AUTOCAP_CB_TYPE_CAM_AF,       

    VAPP_AUTOCAP_CB_TYPE_END    
}vapp_autocap_cb_type;



typedef struct
{
    U16                                         direction;
    U8                                          capture_count;

    // when in MAV only project
    // 0 cannot be a size of array
#if defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
    void                                       *capture_buffer_p[MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT];
    U32                                         capture_img_size[MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT];
#else
    void                                       *capture_buffer_p[1];
    U32                                         capture_img_size[1];
#endif

    MMI_BOOL                                    is_stitch_done;

    mdi_camera_panorama_stitch_result_struct    stitch_ind;
} vapp_autocap_panorama_shot_struct;

typedef struct
{
    U8                                          total_count;
    U8                                          captured_count;

    MDI_RESULT                                  result;
    void                                       *qv_buffer;
    VfxU32                                      qv_size;

} vapp_autocap_mav_shot_struct;

typedef struct
{
    vapp_autocap_state_enum                     next_state;
} vappAutoCapPopupParamStruct;

typedef struct
{
    VfxU32                                      dummy;
} vappAutoCapRestartParamStruct;


typedef struct
{
    VfxBool                                     isPowerOn;
    VfxBool                                     isPreviewStart;
    
    VfxBool                                     isAFon;
    VfxBool                                     isAFsuccess;

    VfxBool                                     isTakepicFailed;    

    VfxBool                                     isHightlightOn;  

}vapp_autocap_hw_flag_struct;

// =============================================================================
// MDI related opeation parameter start
// =============================================================================
typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;

}vapp_autocap_power_on_param_struct;


typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;

}vapp_autocap_power_off_param_struct;



typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;
    
    VfxVideoFrame                                *previewFrame;    
    VfxRect                                      *previewWindow;

    VfxBool                                       isResetZoom;

}vapp_autocap_preview_start_param_struct;

typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;     

}vapp_autocap_preview_stop_param_struct;


typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;
    
    vapp_autocap_panorama_shot_struct            *panoramaShotData;
    
    WCHAR                                        *fileName;

    // quick view
    VfxVideoFrame                                *previewFrame;    
    VfxRect                                      *previewWindow;    
    void                                         *quickviewBuffer;

}vapp_autocap_capture_param_struct;


typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;

    VfxVideoFrame                                *previewFrame;  

    vapp_autocap_panorama_shot_struct            *panoramaShotData;

    void                                         *quickViewBuffer; 

    void                                         *workingBuffer; 
    VfxS32                                        workingBufferSize;

}vapp_autocap_panorama_stitch_param_struct;

typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;
    VfxU32                                        encodeRoiX;
    VfxU32                                        encodeRoiY;
    VfxU32                                        encodeRoiW;
    VfxU32                                        encodeRoiH;    

}vapp_autocap_panorama_encode_param_struct;

typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting; 
    vapp_autocap_hw_flag_struct                  *flag;    

}vapp_autocap_capture_save_param_struct;

typedef struct
{
    VappAutoCapPage                              *obj; 
    vapp_autocap_hw_flag_struct                  *flag;
#if defined(VAPP_AUTOCAP_AF_SUPPORT) || defined(VAPP_AUTOCAP_TOUCH_AF_SUPPORT)
    mdi_camera_af_window_struct                   af_zone;
    mdi_video_rec_af_window_struct                rec_af_zone;
#endif    
    VfxU32                                        af_active_zone;
    VfxU32                                        af_success_zone;    
    
    // UT
    VfxTimer                                     *af_timer;

}vapp_autocap_autofocus_param_struct;

typedef struct
{
    AutoCapSettingMgr                            *Setting;    
    U32                                           size;
    U32                                           reserve_size;    

}vapp_autocap_estimate_size_param_struct;

typedef struct
{
    VappAutoCapPage                              *obj; 
    AutoCapSettingMgr                            *Setting;    
    vapp_autocap_hw_flag_struct                  *flag;

}vapp_autocap_general_param_struct;

typedef struct
{
    vapp_autocap_cb_type                          type;
    
    // panorama stitch 
    vapp_autocap_panorama_shot_struct             stitchRet;
    mdi_camera_panorama_stitch_quickview_struct   quickViewRet;    

    // panorama stitch
    vapp_autocap_mav_shot_struct                  mavRet;

    // AF
    mdi_camera_af_result_struct                   afRet;

}vapp_autocap_hw_result_callback_param_struct;
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

}vapp_autocap_global_config_struct;


typedef VfxCallback1<vappAutoCapPopupParamStruct> VappAutoCapPopupCallbackFunc;
typedef VfxCallback1<vappAutoCapRestartParamStruct> VappAutoCapRestartCallbackFunc;


class VappAutoCapOSDEvtHdlr
{
public:
    
    virtual void PreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void PreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void AutoramaShotHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void AutoramaStitchHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void AutoramaClipHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;       
    virtual void AutoramaDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    virtual void FocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;
    
    // process error popup event
    virtual void errorPopupHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;    

    // process global App event (for all osd State)
    virtual void appGlobalEventHdlr(mmi_cameco_evt_type_enum evt_type, void* param) = 0;        
    
};

class VappAutoCapApp : public VfxApp
{
   VFX_DECLARE_CLASS(VappAutoCapApp);

public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onInit(void);
  
};

class VappAutoCapScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappAutoCapScreen);

// Override
public:
    virtual void onInit();
    virtual void on1stReady();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    void setCallingParam(vapp_autocap_param_struct param);   
    virtual void onRotate(const VfxScreenRotateParam &param);      

    vapp_autocap_param_struct m_param;
    VfxU32                    m_pageId;
private:
};


class VappAutoCapModeSelectPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAutoCapModeSelectPage);

public:
    virtual void onInit();
    virtual void onDeinit();    
    
    virtual void onEnter(VfxBool isBackward);    
    virtual void onExit(VfxBool isBackward);

    void onMAVClicked(VfxObject *obj, VfxId id);
    void on3DimageClicked(VfxObject *obj, VfxId id);

    VfxImageFrame           *m_reflection[2];
    VcpImageButton          *m_mavMode;
    VcpImageButton          *m_3DimageMode;    
    VfxTextFrame            *m_mavName;
    VfxTextFrame            *m_3DimageName;    
};

class VappAutoCapPage : public VfxPage, VappAutoCapOSDEvtHdlr
{
    VFX_DECLARE_CLASS(VappAutoCapPage);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();    
    
    virtual void onEnter(VfxBool isBackward);    
    void onEntered(VfxTimer *source);        
    virtual void onExit(VfxBool isBackward);

    VfxBool isHorzUI(void);    
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    
    void setCallingParam(vapp_autocap_param_struct param); 
   
    static mmi_ret storageChangeNotifyHdlr(mmi_event_struct *evt);
    static mmi_ret USBChangeNotigyHdlr(mmi_event_struct *param);
    
    static VfxBool checkEnv(void);   
    static VfxBool decheckEnv(void);
    
    void configMem(void);
    void resetMem(void);
    
    void initEnv(void);
    void deinitEnv(void);   

    VfxU64 getFreeStorageSize(void);
    VfxBool checkRemovableStorage(void);    
    VfxBool checkSavePath(void);    
    
    void initSetting();
    void initApp(void);    
    void initPreviewWindow(void); 
            
    void enterState(vapp_autocap_state_enum state);   
    void exitState(void);    
    void recoverState(vapp_autocap_state_enum state);    
    void setState(vapp_autocap_state_enum state){m_state = state;};    
    vapp_autocap_state_enum getState(void){return m_state;};

    // OSD state event handler
    virtual void PreviewHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void PreviewFailedHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void AutoramaShotHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void AutoramaStitchHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void AutoramaClipHdlr(mmi_cameco_evt_type_enum evt_type, void* param);   
    virtual void AutoramaDoneHdlr(mmi_cameco_evt_type_enum evt_type, void* param);    
    virtual void FocusHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void errorPopupHdlr(mmi_cameco_evt_type_enum evt_type, void* param);
    virtual void appGlobalEventHdlr(mmi_cameco_evt_type_enum evt_type, void* param);      

    // state enter function
    void enterExitState(void);

    void enterPreviewState(void);
    void enterPreviewFailedState(void);
    void enterFocusingState(void);
    void enterFocusedState(void);
    void enterAutoramaShotState(void);
    void enterAutoramaStitchState(void);
    void enterAutoramaClipState(void);
    void enterAutoramaEncodeState(void);
    void enterAutoramaDoneState(void);
    void enterEnterFailState(void);

    void resultHWCallback(vapp_autocap_hw_result_callback_param_struct param);
    
    void dummyRestartPreview(vappAutoCapRestartParamStruct param);
    void camRestartPreview(vappAutoCapRestartParamStruct param);
    void camPanoRestartPreview(vappAutoCapRestartParamStruct param);
    void onPreviewFramePrepareDone(void);
    
    MDI_RESULT saveCapturedImage(WCHAR *filename, void *imageBuffer, VfxU32 imageBufferSize);

    void onAutoramaUpdateTick(VfxTimer *source);
    
    /* aud related */
    VfxBool isSlientMode(void);
    void playAutofocusSuccessSound(void);
    void playCatureSound(MDI_RESULT cap_ret);

    VfxBool isAppActive(void);

    static VfxBool isInCall(void);

    void onErrorExitTimerTick(VfxTimer *source);
    void onPreviewFrameDoneDelayTick(VfxTimer *source);

    // popup related
    void showPopupScreen(MDI_RESULT result, void * param, VappAutoCapPopupCallbackFunc callback);
    void stopPopupScreen(void);    
    void popupcallback(VfxTimer *source);    
    void popupRecovercallback(vappAutoCapPopupParamStruct param);
    void popupEntercallback(vappAutoCapPopupParamStruct param);    
    void exitAutoCapCUI(vappAutoCapPopupParamStruct param);    
    VfxU16 getMappingShownString(MDI_RESULT result, mmi_event_notify_enum *popup_type);
    VfxTimer *m_popupTimer; 

    void cleanPreviewScreen(void);

    // file name related
    VfxBool getNextFilename(WCHAR* fileBuf);
    void restoreFilename(void);

    void Capture(void);

// variables
public: 

    vapp_autocap_state_enum                             m_state;
    vapp_autocap_param_struct                           m_param;    
    
    AutoCapOSDMgr*                                      m_OSD;
    AutoCapOSDStartingState                            *m_enterScreenOSD;
    AutoCapSettingMgr*                                  m_Setting;    

    VfxU32                                              m_appID;
    
    // flag
    VfxBool                                             m_isAppInited;
    VfxBool                                             m_isStartingApp;    
    VfxBool                                             m_isPreemptable;        
    VfxBool                                             m_isMainLcdPreview;
    VfxBool                                             m_isOnForceHorz;
    VfxBool                                             m_isFirstEnterPreview;
    vapp_autocap_hw_flag_struct                         m_hwFlag;

    // preview related
    VfxRect                                             m_previewWindow;
    VfxVideoFrame*                                      m_previewFrame;
    VfxFrame                                           *m_picturePreviewFrame;
    VappAutoCapRestartCallbackFunc                      m_restartPreviewCallback;    
    VappAutoCapRestartCallbackFunc                      m_dummyRestartPreviewCallback;
    VappAutoCapRestartCallbackFunc                      m_camRestartPreviewCallback;
    VappAutoCapRestartCallbackFunc                      m_camPanoRestartPreviewCallback;
    VfxBool                                             m_isStartingPreview;    
    VfxTimer                                           *m_delayPreviewTimer;
    VfxBool                                             m_isDelayPreview;

    // autorama related
    VfxTimer                                           *m_autoramraUpdateTimer;   
    VfxU32                                              m_clipLeftBound;
    VfxU32                                              m_clipRightBound;  
    VfxU32                                              m_lastCaptureTime;
    vapp_autocap_panorama_direction_enum                m_lastDirection;    

    // mav related
    VfxBool                                             m_isHorzMAVMode;

    // memory config related
    void                                               *m_appMemBuffer;                 // pointer to start addr of whole ASM buffer
    void                                               *m_appMemQuickViewBuffer;        // the quick view memory
    void                                               *m_appMedMultiShotWorkingBuffer; // multo shot working buffer / best shot working buffer        

    
    // popup related
    VfxBool                                             m_isPopupRunning;
    VfxBool                                             m_isNotifyRunning;    
    vappAutoCapPopupParamStruct                         m_popupParam; 
    MDI_RESULT                                          m_CurrentPopupShownresult;
    VappAutoCapPopupCallbackFunc                        m_popupCallback;    
    VappAutoCapPopupCallbackFunc                        m_enterStateCB;
    VappAutoCapPopupCallbackFunc                        m_recoverStateCB;

    // error msg related 
    static MMI_ID                                       m_errStr;
    VcpImageButton                                     *m_back;

    // file name related
    WCHAR                                              *m_camFileNameBuf;
    
    // enter/exit related 
    VfxTimer                                           *m_autoExitTimer;    
    VfxTimer                                           *m_errorExitTimer;        
    VfxTimer                                           *m_postEnterTimer;   
    
    vapp_autocap_panorama_shot_struct                   m_panoramaShot;
    vapp_autocap_mav_shot_struct                        m_mavShot;

    /* HW param */
    vapp_autocap_preview_start_param_struct             m_preview_start_param;
    vapp_autocap_preview_stop_param_struct              m_preview_stop_param;
    vapp_autocap_power_on_param_struct                  m_power_on_param;
    vapp_autocap_power_off_param_struct                 m_power_off_param;
    vapp_autocap_capture_param_struct                   m_capture_param;
    vapp_autocap_panorama_stitch_param_struct           m_panorama_stitch_param;
    vapp_autocap_panorama_encode_param_struct           m_panorama_encode_param;
    vapp_autocap_capture_save_param_struct              m_capture_save_param;
    vapp_autocap_autofocus_param_struct                 m_autofocus_param;
    vapp_autocap_general_param_struct                   m_general_param;
    vapp_autocap_estimate_size_param_struct             m_est_size_param;

    /* OSD param */
    vapp_autocap_osd_hide_param_struct                  m_osd_hide_state_param;
    vapp_autocap_osd_hint_param_struct                  m_osd_hint_state_param;
    vapp_autocap_osd_cam_preview_param_struct           m_osd_cam_preview_state_param;
    vapp_autocap_osd_cam_quick_view_param_struct        m_osd_cam_quick_view_state_param;
    vapp_autocap_osd_focuse_param_struct                m_osd_focuse_state_param;
    vapp_autocap_osd_focuse_hint_param_struct           m_osd_focuse_hint_state_param;
    vapp_autocap_osd_cam_panoramashot_param_struct      m_osd_cam_panorama_state_param;
    vapp_autocap_osd_cam_panoramashot_clip_param_struct m_osd_cam_panorama_clip_state_param;    

    //Misc
    VfxU8                                               m_cbmId;

    //UT on MODIS
    void onAFTimerTick(VfxTimer *source);
    VfxU32                                              m_af_i;
    VfxU32                                              m_smile_i;
    VfxU32                                              m_contshot_i;    
};

#endif

#endif
