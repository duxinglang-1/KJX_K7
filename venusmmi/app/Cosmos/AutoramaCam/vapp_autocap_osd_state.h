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
#include "vapp_autocap_osd.h"
#include "vapp_autocap_app.h"
#include "vapp_autocap_setting_mgr.h"
#include "vapp_autocap_cp_slider.h"
#include "vapp_autocap_cp_rect_frame.h"
#include "MMI_include.h"
#include "MMI_features.h"
#include "MMI_features_camcorder.h"

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))
class VappAutoCapOSDEvtHdlr;

class AutoCapOSDState : public VfxControl
{   
#define  VAPP_AUTOCAP_OSD_AUTO_EXIT_TIME    (120000)

public:
    virtual void onInit(void);

    virtual void enterState(void* param);
    virtual void exitState(void);  
    virtual void drawBase(vapp_autocap_osd_draw_image_struct param);        
    void updateScreen(void);
    virtual void clean(const VfxColor &value = VFX_COLOR_TRANSPARENT);
    void enableState(void){setHidden(VFX_FALSE); };
    void disableState(void){setHidden(VFX_TRUE); };    
    VfxPoint coordTransform2Vertical(VfxU32 x, VfxU32 y);
    void setAutoExitTimer(VfxTimer* t);
    void refreshAutoExitTimer(void);
    vapp_autocap_osd_state_enum getStateName(void){return m_state;};    
    void regEvtHdlr(VappAutoCapOSDEvtHdlr* Hdlr){evtHdlr = Hdlr;};
    virtual void AutoExitTimoutProcess(void);
    void onAutoExitTimerTick(VfxTimer *source);    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    void setisBusy(VfxBool isBusy){m_isBusy = isBusy;};
    
    vapp_autocap_osd_state_enum         m_state;
    VfxBool                             m_isBusy;
    VappAutoCapOSDEvtHdlr              *evtHdlr;
    VfxTimer                           *m_autoExitTimer;


};

class AutoCapOSDStartingState : public AutoCapOSDState
{
public:
    virtual void onInit(void);
    virtual void enterState(void* param);    
    virtual void exitState(void);    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:    
    VcpImageButton                           *m_storageSetting;
    VcpImageButton                           *m_gallery;
    VfxFrame                                 *m_galleryContent;
    VcpImageButton                           *m_usedSensor;
    VcpImageButton                           *m_viewSwitcher;

    VfxImageFrame                            *m_rightBar;    
};

class AutoCapOSDHideState : public AutoCapOSDState
{
public:
    virtual void onInit(void);
    virtual void enterState(void* param);    

private:    
    vapp_autocap_osd_hide_param_struct m_cntx;
};

class AutoCapOSDHinteState : public AutoCapOSDState
{

public:
    virtual void onInit(void);
    virtual void enterState(void* param);    
    virtual void exitState(void);      
    virtual void drawBase(vapp_autocap_osd_draw_image_struct param);  
    void setHint(VfxWString hint);    
    void onOkClicked(VfxObject *obj, VfxId id);
    void onBackClicked(VfxObject *obj, VfxFloat id);  
    void onConfirmClicked(VfxObject *obj, VfxId id);

private:
    VfxTextFrame                        *m_hint;
    VfxImageFrame                       *m_icon;    
    VcpIndicatorPopup                   *m_processingPopup;    
    VcpIndicatorPopup                   *m_IndicatorPopup;   
    VcpConfirmPopup                     *m_confirmPopup;    
    VcpConfirmPopup                     *m_notifyPopup;        
    VfxImageFrame                       *m_background;
    vapp_autocap_osd_hint_param_struct   m_cntx;
};


class AutoCapOSDCamPreviewState : public AutoCapOSDState, public IVcpListMenuContentProvider 
{
#define CAMCO_CAM_PREVIEW_STATUS_ICON_NUMBER  8
//#define CAMCO_CAM_PREVIEW_CAPTUABLE_DIGIT  4
#define CAMCO_CAM_PREVIEW_SHIFT_DIS  80
#define CAMCO_CAM_PREVIEW_RESET_TIME 10000
#define CAMCO_CAM_PREVIEW_MOVE_THRESHOLD 15

class VappAutoCapMenuCusItemMark : public VcpListMenuCheckMark
{
public:
    VappAutoCapMenuCusItemMark():
        VcpListMenuCheckMark(VFX_FALSE)
    {
    }    
    VappAutoCapMenuCusItemMark(VfxBool isMultiSelect):
        VcpListMenuCheckMark(isMultiSelect)
    {
    }
    virtual ~VappAutoCapMenuCusItemMark(){}

    VfxImageFrame* m_imageFrame;
};


typedef enum
{
    VAPP_AUTOCAP_PREVIEW_MODE_NORMAL,      
    VAPP_AUTOCAP_PREVIEW_MODE_CLEAR,                         
    VAPP_AUTOCAP_PREVIEW_MODE_END
    
}vapp_autocap_preview_mode_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void exitState(void);    
    void cleanFocus(void);
    void setFocus(VfxU32 idx, vapp_autocap_osd_focus_struct region);
    void updateZoomParam(VfxU32 v);
    void updateIndicatorMsg(VfxU32 v);    
    
private:
    void setNormalMode(void);
    void setClearMode(void);
    void setClearModeinternal(VfxTimer *source);    

    void layout(void);
        
    void onZooming(VfxU32 value);  
    void ZoomingIn(VfxTimer *source);
    void ZoomingOut(VfxTimer *source);    
    void onGalleryClicked(VfxObject *obj, VfxId id);    
    void onCaptureClicked(VfxObject* obj, VfxId id);    
    void onCaptured(VfxObject* sender, VfxId id, VcpButtonStateEnum state);
    void onStorageSettingClicked(VfxObject *obj, VfxId id);
    void onViewSwitchClicked(VfxObject *obj, VfxId id);
    void onSettingSelectionChanged(VfxBasePopup *sender, VfxBasePopupStateEnum state);
    
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    VfxBool isHorzUI(void);    

    VcpImageButton                           *m_storageSetting;           
    VappAutoCapCpSlider                      *m_zoomer;       
    VcpImageButton                           *m_gallery;
    VfxFrame                                 *m_galleryContent;        
    VcpButton                                *m_usedSensor;
    VcpImageButton                           *m_viewSwitcher;

    VfxImageFrame                            *m_rightBar;    
    VfxImageFrame                            *m_leftBar;    

    VfxImageFrame                            *m_modeIcon;
    
    VfxTextFrame                             *m_indicatorMsg;    
    VfxImageFrame                            *m_indicatorMsgBg;    

    VfxImageFrame                            *m_indIcon[4];		

    VfxImageFrame                            *m_indicatorImage;
    VappAutoCapCpRect                        *m_focusRegion[VAPP_AUTOCAP_OSD_FOCUS_REGION_END];

    vapp_autocap_preview_mode_enum            m_mode;
    
    vapp_autocap_osd_cam_preview_param_struct m_cntx;  
    
    VfxU32                                    m_settingMenuCount;
    VfxU32                                    m_settingMenuHiliteIdx;    
    vapp_autocap_setting_list_struct          m_settingList;    

    VcpSelectPopup                           *m_StoragePopup;

    VfxTimer                                 *m_zoomingTimer;      

    VfxBool                                   m_isFocussing;
};

class AutoCapOSDCamQuickViewState : public AutoCapOSDState
{
    #define VAPP_AUTOCAP_QK_VIEW_ANUMATE (0)
public:

    virtual void onInit(void);
    virtual void enterState(void* param);   
    virtual void drawBase(vapp_autocap_osd_draw_image_struct param);  
    
private:
    void onEffectTimerTick(VfxTimer *source);
    void onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);    
        
    VfxFrame  *m_shownImage;    
    vapp_autocap_osd_cam_quick_view_param_struct m_cntx;   
    
    VfxTimer *m_effectTimer;    

};

class AutoCapOSDCamPanoramaShotState : public AutoCapOSDState
{
#define CAMCO_CAM_MAX_MAV_NUM   (20)

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void drawBase(VfxFrame *target, vapp_autocap_osd_draw_image_struct param);  
    void setDirection(vapp_autocap_panorama_direction_enum dir);
    void setMotion(VfxS32 x, VfxS32 y);
    void setRatio(VfxFloat r);    

private:

    void onCancelClicked(VfxObject *obj, VfxId id);
    void onStitchClicked(VfxObject *obj, VfxId id);
    void updateIcon(void);    
    void updateProgress(void);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    VfxFrame       *m_prevIcon[CAMCO_CAM_MAX_MAV_NUM];
    VfxFrame       *m_targetIcon;
    VfxImageFrame  *m_directionIcon[VAPP_AUTOCAP_PANORAMA_DIRECTION_END];          
    VfxImageFrame  *m_realDirection;    
    VfxTextFrame   *m_directionHint;   
    VfxImageFrame  *m_indIcon[4];	
    VfxFrame       *m_rect;             
    VcpImageButton *m_cancel;
    VcpImageButton *m_stitch;
    VfxImageFrame  *m_div;    
    VfxImageFrame  *m_softkeyBar;
    
    vapp_autocap_osd_cam_panoramashot_param_struct m_cntx; 

};

class AutoCapOSDCamPanoramaClipState : public AutoCapOSDState
{
    
    typedef enum
    {
        vapp_autocap_PANO_CLIP_TOUCH_OBJ_NONE,    
        vapp_autocap_PANO_CLIP_TOUCH_OBJ_LEFT_BOUND,
        vapp_autocap_PANO_CLIP_TOUCH_OBJ_RIGHT_BOUND,            
        vapp_autocap_PANO_CLIP_TOUCH_OBJ_END
        
    }vapp_autocap_panorama_clip_touch_obj_enum;

public:
    virtual void onInit(void);
    virtual void enterState(void* param);
    virtual void drawBase(VfxFrame *target, vapp_autocap_osd_draw_image_struct param);  

private:

    void onSaveClicked(VfxObject *obj, VfxId id);
    void onDeleteClicked(VfxObject *obj, VfxId id);        
    virtual VfxBool onPenInput(VfxPenEvent & event);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    void layout(void);
    void updateClipBound(VfxU32 pos, vapp_autocap_panorama_clip_touch_obj_enum obj);    
    void updateClipResult(void);

    VfxFrame *m_clipResultImage;
    VfxFrame *m_clipSourceImage;    
    VfxFrame *m_sourceBg;            
    VfxFrame *m_leftBound;
    VfxFrame *m_rightBound;      
    VfxFrame *m_leftCover;      
    VfxFrame *m_rightCover;  
    VfxFrame *m_horzSplit; 
    VfxFrame *m_vertBg;     
    VcpImageButton *m_save;     
    VcpImageButton *m_delete; 

    VfxBool   m_isHorzClip;

    vapp_autocap_panorama_clip_touch_obj_enum m_touchObject;   

    vapp_autocap_osd_cam_panoramashot_clip_param_struct m_cntx;     
};

#endif

#endif
