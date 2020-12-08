/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   vapp_fm_radio_slim.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FM Radio header file
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
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FM_RADIO_SLIM_H__
#define __VAPP_FM_RADIO_SLIM_H__

#include "MMI_features.h"

#if defined(__MMI_FM_RADIO_SLIM__)

#include "vapp_fm_radio_util_slim.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_form.h"
#include "vcp_page_panel.h"
#include "vcp_activity_indicator.h"

#if defined(__MMI_NCENTER_SUPPORT__)
#include "vapp_ncenter.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
#include "vcp_loading_popup.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#include "Mdi_datatype.h"
#include "custom_mmi_folders_config.h"
#include "Common_nvram_editor_data_item.h"
#include "Mdi_audio.h"
#include "fmr_config_customize.h"

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_FM_RADIO_AUTO_LIST_NUM         20
#define VAPP_FM_RADIO_FAV_LIST_NUM          20
#define VAPP_FM_RADIO_FAV_NAME_CHAR_NUM     20
#define VAPP_FM_RADIO_PROGRAM_NAME_CHAR_NUM 20

#define HALO_EFFECT_RATIO                   (2.5f)
#define HALO_EFFECT_RATIO_2                 (1.5f)
#define CP_OPACITY_LIGHT                    (1.0f)
#define CP_OPACITY_DARK_INFO                (0.3f)
#define CP_OPACITY_DARK_TUNER               (0.5f)

#define MAIN_PAGE_BG_COLOR                  (VfxColor(255,30,30,30))
#define LIST_HIGHLIGHT_COLOR                (VfxColor(255,22,150,195))


/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VappFMRadioApp;
class VappFMRadioScreen;
class VappFMRadioControl;
class VappFMRadioTuner;
class VappFMRadioLPButton;
class VappFMRadioAutoMgr;
class VappFMRadioListAuto;
class VappFMRadioListFav;
class VappFMRadioMainPage;
class VappFMRadioInfo;
class VappFMRadioChannelBox;


/***************************************************************************** 
 * Class VappFMRadioApp
 *****************************************************************************/
class VappFMRadioApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappFMRadioApp);

public:

    enum 
    {
        MIN_FREQ = FM_RADIO_MIN_FREQ,
        MAX_FREQ = FM_RADIO_MAX_FREQ,
        FM_FREQ_NUMBER = FM_RADIO_CHANNEL_NUMBER
    };

    enum PageIdEnum
    {
        PAGE_MAIN_PAGE = 1,
        PAGE_CHANNEL_LIST = 2,

        PAGE_END      
    };

    static VappFMRadioApp *m_self;

    vadp_fm_radio_state_enum m_state;
    VfxU16 m_curFreq;
    VfxTimer *m_delaySetFreqTimer;
    VfxTimer *m_delaySetPowerOnFreqTimer;

#ifdef __MMI_FM_VIA_A2DP__ 
    // Used for showing loading animation to user if connect A2DP take a long time. 
    VfxTimer *m_a2dpConnectTimer;  
#endif

    VappFMRadioMainPage *m_mainPage;
    VappFMRadioScreen *m_scr;

    VfxSignal2 <vadp_fm_radio_state_enum, vadp_fm_radio_state_enum> m_stateChanged;

public:
    VappFMRadioApp();

    virtual void onInit(void);
    virtual void onDeinit(void);
    using VfxApp::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options, VfxAppCloseReason reason);
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);

    void powerOn(void);
    void powerOff(void);
    void switchOutputPath(void);
    vadp_fm_radio_state_enum getState(void);
    void pureSetState(vadp_fm_radio_state_enum state);
    void setState(vadp_fm_radio_state_enum state);
    VfxU16 getPreFreq(void);
    VfxU16 getFreq(void);
    void setFreq(VfxU16 freq, VfxBool is_apply);
    void setSeekFreq(VfxU16 freq, VfxBool is_apply);
    void setFreqHdlr(VfxTimer *source);
    void delaySetFreq(void);  
    void queryState(void);
    void onAppUpdate(void);

    // Check whether DelaySetPowerOnFreq timer is enabled.
    VfxBool isDelaySetPowerOnFreqEnable();
    // Check whether the FM Radio main interface shows in top most currently.
    VfxBool isFMRadioMainInterfaceActive();
    void updateSpeakerState(void);

    static void procCallback(mmi_event_struct *evt, void *user_data);
    static void generalCallback(mdi_result result, void *user_data);
    static MMI_BOOL backgroundCallback(mdi_result result, void *user_data);

#ifdef __MMI_FM_VIA_A2DP__
    // Connect A2DP has began.
    void connectA2dpBegin(void);
    // Connect A2DP has end.
    void connectA2dpEnd(void);
    // Connect A2DP has timeout and need to show loading animation.
    void onConnectA2dpTimeout(
        VfxTimer *timer         // [in] The timer which has timeout.
    );
#endif 

#ifdef __MMI_AVRCP_SUPPORT__
    // AVRCP cmd process function.
    static VfxBool avrcpCmdCallback(
        VfxKeyEvent &event,     // [in] Key event transfered from AVRCP cmd
        VfxBool is_from_avrcp,  // [in] Indicate whether the key event is transfered from AVRCP cmd
        void *user_data         // [in] User data, usually is the object point of this class
    );
#endif

#if defined(__MMI_NCENTER_SUPPORT__)
    // Handle NCenter events
    void onNCenterStatusChanged(VappNCenterEventEnum evt);
#endif

};

/***************************************************************************** 
 * Class VappFMRadioScreen
 *****************************************************************************/
class VappFMRadioScreen : public VfxMainScr
{

// Override
public:
    VappFMRadioScreen(void);
    virtual void on1stReady(void);
    virtual void onEnter(VfxBool isBackward);
    virtual void onExited(VfxBool isBackward);
};


/***************************************************************************** 
 * Class VappFMRadioControl
 *****************************************************************************/
class VappFMRadioControl : public VfxControl
{
    friend class VappFMRadioMainPage;

public:
    enum UIConstantsEnum
    { 
    #if defined(__MMI_MAINLCD_320X480__)
        TUNER_X = 12,
        TUNER_Y = 0,
        TUNER_WIDTH = 296,
        TUNER_HEIGHT = 56,
        BTN_POWER_X = 123,
        BTN_POWER_Y = 100,
        BTN_POWER_WIDTH = 74,
        BTN_POWER_HEIGHT = 75,
        BTN_SPEAKER_X = 23,
        BTN_SPEAKER_Y = 191,
        BTN_SPEAKER_WIDTH = 35,
        BTN_SPEAKER_HEIGHT = 36  
    #else // defined(__MMI_MAINLCD_240X320__) !! defined(__MMI_MAINLCD_240X400__)
        TUNER_X = 6,
        TUNER_Y = 0,
        TUNER_WIDTH = 228,
        TUNER_HEIGHT = 42,
        BTN_POWER_X = 92,
        BTN_POWER_Y = 76,
        BTN_POWER_WIDTH = 56,
        BTN_POWER_HEIGHT = 57,
        BTN_SPEAKER_X = 16,
        BTN_SPEAKER_Y = 128,
        BTN_SPEAKER_WIDTH = 26,
        BTN_SPEAKER_HEIGHT = 27 
    #endif        
    };

private:
    VappFMRadioTuner    *m_tuner;
    VcpButton           *m_btnPower;
    VcpImageButton      *m_btnSpeaker;
    VcpImageButton      *m_btnFav;    

public:
    VappFMRadioControl();
    virtual void onInit(void);
    void drawButtonState(VfxId button, VfxKeyEventTypeEnum key_event);
    void updateSpeakerBtn(VfxU8 audio_path);

};



/***************************************************************************** 
 * Class VappFMRadioMainPage
 *****************************************************************************/
class VappFMRadioMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappFMRadioMainPage);
    friend class VappFMRadioApp;

public:
    enum
    {
        BTN_PREV,
        BTN_NEXT,
        BTN_SPEAKER,
        BTN_FAV,
        BTN_ARROWL,
        BTN_ARROWR,
        BTN_POWER,

        TOOL_BAR_BTN_CHANNEL_LIST
    };

    enum UIConstantsEnum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        INFO_X = 0,
        INFO_Y = 0,
        INFO_WIDTH = LCD_WIDTH,
        INFO_HEIGHT = 167,
        PANEL_X = 0,
        PANEL_Y = INFO_HEIGHT,
        PANEL_WIDTH = INFO_WIDTH,
        PANEL_HEIGHT = LCD_HEIGHT - CFG_UI_STATUS_BAR_HEIGHT - INFO_HEIGHT
    #else // defined(__MMI_MAINLCD_240X320__) !! defined(__MMI_MAINLCD_240X400__)
        INFO_X = 0,
        INFO_Y = 0,
        INFO_WIDTH = LCD_WIDTH,
        INFO_HEIGHT = 90,
        PANEL_X = 0,
        PANEL_Y = INFO_HEIGHT,
        PANEL_WIDTH = INFO_WIDTH,
        PANEL_HEIGHT = LCD_HEIGHT - CFG_UI_STATUS_BAR_HEIGHT - INFO_HEIGHT
    #endif    
    };

    enum
    {
        LONGPRESS_DUR_MAX = 350,
        LONGPRESS_DUR_MIN = 100,
        LONGPRESS_DUR_GAP = 25,

        SEEKING_PROMPT_TIME  = 200,
        SEEKING_PROMPT_DURATION_TIME = 300
    };

private:
    VappFMRadioApp *m_app;
    VappFMRadioInfo *m_info;
    VcpToolBar *m_toolBar;   
    VcpActivityIndicator *m_waitingIcon;
    VfxTimer *m_arrowRTimer;
    VfxTimer *m_arrowLTimer;
    VfxU16 m_tempFreq;
    VfxId m_buttonPressed;

    // for seeking prompt
    VfxTimer *m_seekingPromptTimer;
    VfxTimer *m_seekingDelayTimer;
    VfxBool   m_isSeekingDone;

#ifdef __MMI_FM_VIA_A2DP__
    // Used for creating loading animation
    VcpLoadingPopup *m_loadingPopup;
#endif

public:
    VappFMRadioControl *m_control;

public:
    VappFMRadioMainPage();
    virtual void onInit(void);
    virtual void onDeinit(void);
    void updateState(void);
    // Update freq with checking seeking state.
    void updateFreq(VfxBool spin_wheel);
    // Update freq without checking seeking state.
    void pureUpdateFreq(VfxBool spin_wheel);
    static VfxU16 WStringToFreq(VfxWChar *s, VfxObject* parent);

    void showWaitingIcon(void);
    void hideWaitingIcon(void);

#ifdef __MMI_FM_VIA_A2DP__
    // Show loading animation to user.
    void createLoadingPopup();
    // Stop loading animation.
    void closeLoadingPopup();
#endif 

private:
    void drawMainPage(void);
    void arrowBtnLongPressed(VfxTimer *source);
    void onWheelStatus(VfxObject *sender, VfxPenEvent event);
    void onButtonStatus(VfxObject *sender, VfxId id, VfxPenEventTypeEnum type);

    void getFavName(VfxWChar** str, VfxU16 freq);

    void updateChannelBox(void);

    static void seekCallback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data);
    void startSeek(VfxBool forward);
    void onSeekingTimeout(VfxTimer *source);

    void onSetFreqStopRecButtonClicked(VfxObject* sender, VfxId btn);
    void onButtonClicked(VfxObject *sender, VfxId id);

    VfxBool LPButtonAction(VfxId id, VfxPenEventTypeEnum type);
    void ButtonAction(VfxId id);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    // Key event process function.
    // RETURNS: Return true if event has been processed, otherwise return false.
    VfxBool processKeyEvent(
        VfxKeyEvent &event,      // [in] Key event need to be processed.
        VfxBool is_from_avrcp    // [in] Indicate whether the key event is transfered from AVRCP cmd
    );

    void onEnterFreqSet(void);
    void onSetFreqPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    void onAddToFavPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    virtual void onExited(void);
    virtual void onEnter(VfxBool isBackward);
};



/***************************************************************************** 
 * Class VappFMRadioInfo
 *****************************************************************************/
class VappFMRadioInfo : public VfxControl
{
    friend class VappFMRadioMainPage;
    
public:
    enum UIConstantsEnum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        BTN_PREV_X = 50,
        BTN_PREV_Y = 98,
        BTN_PREV_WIDTH = 17,
        BTN_PREV_HEIGHT = 21,
        CHANNEL_BOX_X = 67,
        CHANNEL_BOX_Y = 0,
        CHANNEL_BOX_WIDTH = 186,
        CHANNEL_BOX_HEIGHT = VappFMRadioMainPage::INFO_HEIGHT 
    #else // defined(__MMI_MAINLCD_240X320__) !! defined(__MMI_MAINLCD_240X400__)
        BTN_PREV_X = 37,
        BTN_PREV_Y = 46,
        BTN_PREV_WIDTH = 13,
        BTN_PREV_HEIGHT = 16,
        CHANNEL_BOX_X = 50,
        CHANNEL_BOX_Y = 0,
        CHANNEL_BOX_WIDTH = 140,
        CHANNEL_BOX_HEIGHT = VappFMRadioMainPage::INFO_HEIGHT
    #endif        
    };

public:
    VappFMRadioChannelBox   *m_channelBox;

private:
    VcpImageButton          *m_btnPrev;
    VcpImageButton          *m_btnNext;

public:
    VappFMRadioInfo();
    virtual void onInit(void);
    void setLight(VfxBool turn_on);
    void updateInfoString(void);

private:
    void drawInfo(void);

};


/***************************************************************************** 
 * Class VappFMRadioChannelBox
 *****************************************************************************/
class VappFMRadioChannelBox : public VfxControl
{
private:

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        CHANNEL_NAME_Y = 40,          
        CHANNEL_NAME_HEIGHT = 20,
        CHANNEL_NAME_FONT_SIZE = 18,
        CHANNEL_NUMBER_Y = 109,
        CHANNEL_NUMBER_FONT_SIZE = 66
    #else // defined(__MMI_MAINLCD_240X320__) !! defined(__MMI_MAINLCD_240X400__)
        CHANNEL_NAME_Y = 9,          
        CHANNEL_NAME_HEIGHT = 18,
        CHANNEL_NAME_FONT_SIZE = 14,
        CHANNEL_NUMBER_Y = 54,
        CHANNEL_NUMBER_FONT_SIZE = 50
    #endif         
    };

public:
    VfxSignal2 <VfxWChar**, VfxU16> m_signalGetFavName;


private:
    VfxTextFrame   *m_channelName;  
    VfxTextFrame   *m_channelNumber;
    VfxTextFrame   *m_seekingPrompt;

public:
    VappFMRadioChannelBox();
    virtual void onInit(void);
    void setLight(VfxBool turn_on);
    VfxBool setFreq(VfxU16 freq);
    void showSeekingPrompt(VfxBool isShow);

};


/***************************************************************************** 
 * Class VappFMRadioLPButton
 *****************************************************************************/
class VappFMRadioLPButton : public VcpImageButton
{
public:
    VfxSignal3 <VfxObject*, VfxId, VfxPenEventTypeEnum> m_buttonStatus;

// Override
public:
    VappFMRadioLPButton();
    virtual VfxBool onPenInput(VfxPenEvent &event);
};


/***************************************************************************** 
 * Class VappFMRadioTuner
 *****************************************************************************/
class VappFMRadioTuner : public VfxControl
{    
public:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        BTN_ARROWL_X = 13,
        BTN_ARROWL_Y = 19,
        BTN_ARROWL_WIDTH = 12,
        BTN_ARROWL_HEIGHT = 20,
        MARK_HORIZONTAL_X = 45,
        MARK_HORIZONTAL_Y = 17,
        MARK_HORIZONTAL_WIDTH = 206,
        MARK_HORIZONTAL_HEIGHT = 1,        
        MARK_VERTICAL_WIDTH = 2,
        MARK_VERTICAL_HEIGHT = 4,
        MARK_TO_FREQ = 12,
        FREQ_FONT_SIZE = 16,
    #else // defined(__MMI_MAINLCD_240X320__) !! defined(__MMI_MAINLCD_240X400__)
        BTN_ARROWL_X = 13,
        BTN_ARROWL_Y = 14,
        BTN_ARROWL_WIDTH = 9,
        BTN_ARROWL_HEIGHT = 16,
        MARK_HORIZONTAL_X = 37,
        MARK_HORIZONTAL_Y = 13,
        MARK_HORIZONTAL_WIDTH = 154,
        MARK_HORIZONTAL_HEIGHT = 1,        
        MARK_VERTICAL_WIDTH = 2,
        MARK_VERTICAL_HEIGHT = 4,
        MARK_TO_FREQ = 8,
        FREQ_FONT_SIZE = 14,
    #endif
        VERTICAL_MARK_COUNT = 6
    };

private:
    VfxImageFrame *m_pin;
    VfxFloat m_interval;
    VfxTextFrame *m_low_freq;
    VfxTextFrame *m_high_freq;
    VfxRect       m_tunerTouchRect;

    VfxFrame *m_markHotizontal;
    VfxFrame *m_markHotizontalWhite;
    VfxFrame* m_markVertical[VERTICAL_MARK_COUNT];

public:
    VfxSignal2 <VfxObject*, VfxPenEvent> m_wheelStatus;
    VappFMRadioLPButton *m_btnArrowL;
    VappFMRadioLPButton *m_btnArrowR;
    
public:
    VappFMRadioTuner();
    virtual void onInit(void);

    void setLight(VfxBool turn_on);
    void setPin(VfxU16 freq);
    virtual VfxBool onPenInput(VfxPenEvent &event);

    static VfxFloat getWheelPixelsToFreq();

};


/***************************************************************************** 
 * Class VappFMRadioAutoMgr
 *****************************************************************************/
class VappFMRadioAutoMgr : public VfxObject
{
public:
    nvram_ef_vapp_fmrdo_auto_list_struct m_freq;
    VfxU8 m_total;

public:
    virtual void onInit(void);
    void updateFreq();
    VfxU8 getTotal(void);
    VfxU16 getFreq(VfxU8 index);
};


/***************************************************************************** 
 * Class VappFMRadioListAuto
 *****************************************************************************/
class VappFMRadioListAuto : public VfxFrame, public IVcpListMenuContentProvider
{
    friend class VappFMRadioChannelListPage;

private:
    enum ToolBarBtnEnum
    {
        TOOL_BAR_BTN_AUTO_SEARCH,

        TOOL_BAR_BTN_END
    };

    VappFMRadioApp *m_app;
    VfxU16 m_signalCount;
    VcpConfirmPopup *m_startCnf;
    VcpToolBar *m_autoListToolBar;
    
    static VappFMRadioListAuto *m_self;

public:
    VcpListMenu *m_list;
    VcpIndicatorPopup *m_waiting;
    VappFMRadioAutoMgr *m_autoMgr;


public:
    
    VappFMRadioListAuto();
    virtual void onInit(void);
    virtual void onDeinit(void);

    void setApp(VappFMRadioApp* app);
    void updateAutoList(void);
    void onCancelAutoSearch(VfxObject* sender, VfxFloat curr_progress);
    void onAutoSearchButtonClicked(VfxObject* sender, VfxId btn);
    void onButtonClicked(VfxObject *sender, VfxId id);
    void onItemTapped(VcpListMenu *menu, VfxU32 index);
    void onStateChanged(vadp_fm_radio_state_enum pre_state, vadp_fm_radio_state_enum new_state);
    void startAutoScan(void);
    void abortAutoScan(void);
    void onAutoScanDone(void);
    VfxBool errBalloonHandler(void);
    void showWaitingPopup(void);

    // Get the text frame format for the text fields of list cell
    // User can update the text frame font, text color, etc.
    virtual VfxBool getItemTextFrameFormat(
                 VfxU32 index,                   // [IN] the index of item
                 VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
                 VfxTextFrame *frame             // [OUT] the text frame
                 );

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxWString &text,                // [OUT] the text resource
                 VcpListMenuTextColorEnum &color  // [OUT] the text color
                 );

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

};


/***************************************************************************** 
 * Class VappFMRadioFavMgr
 *****************************************************************************/
class VappFMRadioFavMgr : public VfxObject
{
public:
    nvram_ef_vapp_fmrdo_fav_list_struct m_data;
    VfxU8 m_total;
    VfxU8 m_editIndex;
    VfxSignal0 m_favListUpdated;

public:
    virtual void onInit(void);
    VfxU8 getTotal(void);
    VfxU16 getFreq(VfxU8 index);
    VfxWChar* getName(VfxU8 index);
    VfxU8 getEditIndex(void);
    void setEditIndex(VfxU8 index);
    void editList(VfxU16 freq, VfxWString name, VfxU8 index);
    VfxBool addToList(VfxU16 freq, VfxWString name);
    void DeleteItems(VfxBool* item_p);

};


/***************************************************************************** 
 * Class VappFMRadioListFav
 *****************************************************************************/
class VappFMRadioListFav : public VfxFrame, public IVcpListMenuContentProvider
{
    friend class VappFMRadioChannelListPage;

private:
    enum ToolBarBtnEnum
    {
        TOOL_BAR_BTN_ADD,
        TOOL_BAR_BTN_DELETE,
        TOOL_BAR_BTN_SELECT_ALL,
        TOOL_BAR_BTN_DELETE2,
        TOOL_BAR_BTN_CANCEL,

        TOOL_BAR_BTN_END
    };

    enum VappFMRadioFavListMode
    {
        ADD_MODE,
        DELETE_MODE
    };

    VappFMRadioApp *m_app;
    VcpInputPopup *m_edit;
    VcpInputPopup *m_addFav;
    VappFMRadioFavMgr *m_favMgr;
    VappFMRadioFavListMode m_mode;
    VfxBool m_select[VAPP_FM_RADIO_FAV_LIST_NUM];
    VfxU8 m_select_total;
    VfxBool m_showSelectAll;
    VfxS8 m_tappedIdx;
    VcpConfirmPopup *m_deleteCnf;
    VcpToolBar *m_favListToolBar;

public:
    VcpListMenu *m_list;

public:

    VappFMRadioListFav();
    virtual void onInit(void);
    void onItemTapped(VcpListMenu *menu, VfxU32 index);
    void setApp(VappFMRadioApp* app);

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should creat and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame* getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);

    // Get the text frame format for the text fields of list cell
    // User can update the text frame font, text color, etc.
    virtual VfxBool getItemTextFrameFormat(
                 VfxU32 index,                   // [IN] the index of item
                 VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
                 VfxTextFrame *frame             // [OUT] the text frame
                 );

    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxWString &text,                // [OUT] the text resource
                 VcpListMenuTextColorEnum &color  // [OUT] the text color
                 );

    // Get the item count of the lis menu
    virtual VfxU32 getCount(void) const;

    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
                 VfxU32 index,                    // [IN] the index of item
                 VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                 VfxImageSrc &image               // [OUT] the image resource
                 );

    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
                VfxU32 index   // [IN] index of the item
                ) const;


    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

    void onDeleteButtonClicked(VfxObject* sender, VfxId btn);
    void onButtonClicked(VfxObject *sender, VfxId id);
    void onBtnSelectAllClicked();
    void updateButton(void);
    void updateListMenu(void);
    void addToFavList(VfxU16 freq, VfxWString name);
    void cancelDelete(void);
    virtual VfxBool onBackKey(void);

    VfxWChar* getFavName(VfxU16 freq);
    void onAddToFavPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    void onEditPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn);
    void onEditButtonClicked(VcpListMenu *listmenu, VfxU32 index);
    void onEditTextActivated(VcpTextEditor *sender, VfxBool activated);
    void onSelectedChanged(VcpListMenu* menu, VfxU32 index, VcpListMenuItemStateEnum state);

};


/***************************************************************************** 
 * Class VappFMRadioChannelListPage
 *****************************************************************************/
class VappFMRadioChannelListPage : public VfxPage
{

public:    
    enum TabBarItemEnum
    {
        TAB_ITEM_AUTO_SEARCH,
        TAB_ITEM_FAVORITE,

        TAB_ITEM_END
    };

public:
    VappFMRadioChannelListPage();
    virtual void onInit();
    virtual void onBack();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    
    void onTabSwitch (VfxObject* sender, VfxId id);
    void updateList(void);
    void onAutoScanDone();

private:
    VappFMRadioApp      *m_app;
    VcpTabTitleBar      *m_tabBar;
    VcpPagePanel        *m_pagePanel;
    TabBarItemEnum       m_tabChoose;
    VappFMRadioListAuto *m_autoList;
    VappFMRadioListFav  *m_favList;
};


#endif // __MMI_FM_RADIO_SLIM__
#endif // __VAPP_FM_RADIO_SLIM_H__
