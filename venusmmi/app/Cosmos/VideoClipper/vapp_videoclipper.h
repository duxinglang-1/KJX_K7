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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_videoclipper.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_VIDEOCLIPPER_H__
#define __VAPP_VIDEOCLIPPER_H__

#include "MMI_features.h" 

#if defined(__MMI_VIDEO_CLIPPER__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_videoclipper_slider.h"
#include "vapp_video_player_cp.h"
#include "../filemgr/Vapp_fmgr_cp.h"
#include "vcp_menu_popup.h"
#include "vapp_ncenter.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMIDataType.h"
#include "FileMgrSrvGprot.h"
#include "mdi_datatype.h"
#include "vcui_videoclipper_gprot.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VcuiVideoClipperCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiVideoClipperCui);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
// Method
public:

private:
    VfxWString m_content;
};

class VcuiVideoClipperScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VcuiVideoClipperScreen);

// Override
public:
    virtual void on1stReady();

// Method
public:
    void setParam(
        vcui_videoclipper_param_struct* param,   // initial parameter
        VfxU32 appID
        );


private:
    vcui_videoclipper_param_struct m_param;
    VfxU32 m_id;
    
};

class VcuiVideoClipperPage : public VfxPage
{
    VFX_DECLARE_CLASS(VcuiVideoClipperPage);
public:
    enum
    {
        STATE_IDLE = 0,
        STATE_PLAY_OPENING,
        STATE_PLAY_READY,
        STATE_PLAY_PLAYING,
        STATE_PLAY_PAUSED,
        STATE_PLAY_SEEKING,
        STATE_CLIP_PREPARING,
        STATE_CLIP_PREPARED,
        STATE_CLIP_CLIPPING,
        STATE_PLAY_INT_PLAYING,
        STATE_CLIP_INT_PREPARING
    };


    enum
    {
    #ifdef __MMI_MAINLCD_480X800__
        PLAY_PAUSE_BUTTON_X = 52,
        PLAY_PAUSE_BUTTON_Y = 132,
        TRIM_BUTTON_X = 748,
        TRIM_BUTTON_Y = 132,

        SLIDER_X = 68,
        SLIDER_Y = 368,
        SLIDER_BG_X = 10,
        SLIDER_BG_Y = 376,
        SLIDER_BG_HEIGHT = 104,
        TIME_TEXT_GAP_Y = 34,
        HINT_TEXTFRAME_Y = 323,
        HINT_STR_Y_OFFSET = 28,
    #elif __MMI_MAINLCD_320X480__    
        PLAY_PAUSE_BUTTON_X = 37,
        PLAY_PAUSE_BUTTON_Y = 80,
        TRIM_BUTTON_X = 441,
        TRIM_BUTTON_Y = 80,

        SLIDER_X = 31,
        SLIDER_Y = 250,
        SLIDER_BG_X = 5,
        SLIDER_BG_Y = 255,
        SLIDER_BG_HEIGHT = 65,
        TIME_TEXT_GAP_Y = 19,
        HINT_TEXTFRAME_Y = 208,
        HINT_STR_Y_OFFSET = 22,
    #elif __MMI_MAINLCD_240X400__    
        PLAY_PAUSE_BUTTON_X = 24,
        PLAY_PAUSE_BUTTON_Y = 72,
        TRIM_BUTTON_X = 376,
        TRIM_BUTTON_Y = 72,

        SLIDER_X = 25,
        SLIDER_Y = 178,
        SLIDER_BG_X = 4,
        SLIDER_BG_Y = 188,
        SLIDER_BG_HEIGHT = 48,
        TIME_TEXT_GAP_Y = 14,
        HINT_TEXTFRAME_Y = 150,
        HINT_STR_Y_OFFSET = 16,
    #elif __MMI_MAINLCD_240X320__    
        PLAY_PAUSE_BUTTON_X = 24,
        PLAY_PAUSE_BUTTON_Y = 72,
        TRIM_BUTTON_X = 296,
        TRIM_BUTTON_Y = 72,

        SLIDER_X = 25,
        SLIDER_Y = 178,
        SLIDER_BG_X = 4,
        SLIDER_BG_Y = 188,
        SLIDER_BG_HEIGHT = 48,
        TIME_TEXT_GAP_Y = 14,
        HINT_TEXTFRAME_Y = 150,
        HINT_STR_Y_OFFSET = 16,
    #else
        PLAY_PAUSE_BUTTON_X = 52,
        PLAY_PAUSE_BUTTON_Y = 132,
        TRIM_BUTTON_X = 748,
        TRIM_BUTTON_Y = 132,

        SLIDER_X = 68,
        SLIDER_Y = 368,
        SLIDER_BG_X = 10,
        SLIDER_BG_Y = 376,
        SLIDER_BG_HEIGHT = 104,
        TIME_TEXT_GAP_Y = 34,
        HINT_TEXTFRAME_Y = 323,
        HINT_STR_Y_OFFSET = 28,
    #endif
        END = 0
    
    };

    enum
    {
        OPTION_SAVE_ORIGINAL = 0,
        OPTION_SAVE_NEW,
        OPTION_CLOSE
    };
    
// Override
public:
    VcuiVideoClipperPage();
    
// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual void setBounds(const VfxRect &value);

// Method
public:
    void updateUI();
    
    void setParam(
        vcui_videoclipper_param_struct* param,   // initial parameter
        VfxU32 appID
        );
    
    void openFileReady(
        VappVideoPlayerComponent *player, 
        MDI_RESULT result
    );

    void seekFinished(
        VappVideoPlayerComponent *player, 
        MDI_RESULT result
    );

    void playBackFinished(
        VappVideoPlayerComponent *player, 
        MDI_RESULT result
    );

    void onPlayTimerTick(
        VfxTimer *source
    );

    void onProcessingTimerTick(
        VfxTimer *source
    );
    
    void onSaveMenuButtonClicked(
        VcpMenuPopup* pMenu, 
        VcpMenuPopupEventEnum event, 
        VcpMenuPopupItem* item
    );

    void onRenameFileClicked(
        VfxObject* sender, 
        VcpInputPopupButtonEnum id
    );

    void onProcessingCancel(
        VfxObject* obj, 
        VfxFloat processing
    );

    static mmi_ret cbEventHandler(
        mmi_event_struct *evt
    );
    
private:
    U64 msecToSec(
        U64 timeMsec
    );

    VfxWChar* pathGetFilename(
        VfxWChar* path
    );      

    void startClipMarkPressedHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void startClipMarkReleasedHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void startClipMarkDragHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void startClipMarkAbortHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void endClipMarkPressedHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void endClipMarkReleasedHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void endClipMarkDragHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void endClipMarkAbortHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );
    
    void playClipMarkPressedHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void playClipMarkReleasedHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void playClipMarkDragHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );

    void playClipMarkAbortHdlr(
        VappVideoClipperSlider *slider,
        VfxFloat value
    );
    
    static void clipPrepareCB(
        MDI_RESULT result, 
        void* userData);

    static void clipResultCB(
        MDI_RESULT result, 
        void* userData);

    void clipCbEventHdlr(
        MDI_RESULT result
    );
    
    void playVideo(
        VappVideoMsec time
    );

    void playVideo();

    void pauseVideo();

    void seekVideo(
        VappVideoMsec time
    );

    void stopVideo();

    void clipVideoOpen();

    void clipVideoStart();

    void clipVideoStop();

    void clipVideoClose();

    VappVideoMsec getVideoTime(
        VfxFloat normalizedValue
    );

    void playControlButtonClickHdlr(
        VfxObject* sender, 
        VfxId id
    );

    void pauseControlButtonClickHdlr(
        VfxObject* sender, 
        VfxId id
    );
    
    void clipButtonClickHdlr(
        VfxObject* sender, 
        VfxId id
    );

    void getTimeText(
        VfxWString &timeText, 
        U64 timeMsec, 
        VfxBool hideHourIfZero
    );

    void getFilePathAndRelatedInfo(
        VfxWString& inputFilePath, 
        VfxWString& outFileFolder, 
        VfxWString& outFileName, 
        VfxWString& outExtName
    );
    
    void setTimeText(
        VfxTextFrame *text, 
        VappVideoMsec time, 
        VfxBool hideHourIfZero = VFX_TRUE
    );

    VfxWString getDstFilePath(
        VfxWString& srcFolderPath,  
        VfxWString& srcFileName, 
        VfxWString& extName
    );

    void drawPlayIcon();

    void drawPauseIcon();

    void onProgressBarFinish();

    void onPopupButtonClicked(
        VfxObject* obj, 
        VfxId id
    );

    void onNotificationCenterChanged(
        VappNCenterEventEnum event
    );

    void enterState(
        VfxU8 state,
        VfxU32 line
    );

    void displayErrorPopup(
        VfxU16 stringID
    );
    
private:
    VfxTextFrame                    *m_textFrame;
    VcpImageButton                  *m_playControlButton;
    VcpImageButton                  *m_pauseControlButton;
    VcpImageButton                  *m_clipButton;
    VcpTitleBar                     *m_tbar;
    vcui_videoclipper_param_struct  m_setting;
    VfxImageFrame                   *m_sliderBgImage;
    VappVideoClipperSlider          *m_slider;
    VappVideoPlayerComponent        *m_video;
    static VfxU8                    m_state;
    VappVideoMsec                   m_startTime;
    VappVideoMsec                   m_endTime;
    VappVideoMsec                   m_playTime;
    VappVideoMsec                   m_totalTime;
    VfxBool                         m_isResought;
    VfxBool                         m_isWaitPlay;
    VfxBool                         m_isDelayPlay;
    VfxBool                         m_isWaitClip;
    VfxTextFrame                    *m_videoStartTimeText;
    VfxTextFrame                    *m_videoEndTimeText;
    VfxFrame                        *m_hintFrame;
    VfxTextFrame                    *m_hintText;
    VfxTimer                        *m_playTimer;
    VfxTimer                        *m_processingTimer;
    VfxWeakPtr <VcpMenuPopup>    m_popupMenu;
    VappFileNameEditorPopup         *m_rename_popup;
    VfxWString                      m_srcFilePath;
    VfxWString                      m_dstFilePath;
    VfxWString                      m_fileName;
    VcpIndicatorPopup               *m_processingPopup;
    VfxU32                          m_isDeleteSrc;
    VfxU32                          m_appID;
    vcui_videoclipper_event_enum    m_result;
    VfxU8 m_hBackgroundPlay;
};

#endif /* __MMI_VIDEO_CLIPPER__ */

#endif /* __VAPP_VIDEOCLIPPER_H__ */

