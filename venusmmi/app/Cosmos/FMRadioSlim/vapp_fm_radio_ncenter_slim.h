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
 *   vapp_fm_radio_ncenter_slim.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  FM Radio NCenter header file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FM_RADIO_NCENTER_SLIM_H__
#define __VAPP_FM_RADIO_NCENTER_SLIM_H__

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO_SLIM__

#if defined(__MMI_NCENTER_SUPPORT__)

#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_cb_mgr_gprot.h"
#ifdef __cplusplus
}
#endif

#include "vsrv_notification.h"
#include "vsrv_ncenter.h"
#include "vcp_include.h"
 
/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VappWidgetFmRadioLcd;
class VappWidgetFmRadioPanel;
class VappFmRadioNCell;


/***************************************************************************** 
 * Class VappFmRadioNCell    
 *****************************************************************************/
class VappFmRadioNCell : public VsrvNCell
{
    VFX_DECLARE_CLASS(VappFmRadioNCell);        

// Constants
public:

    enum NCellSizeEnum
    {
        FM_NCELL_WIDTH = VAPP_NCENTER_ONGOING_CELL_WIDTH,
    #if defined(__MMI_MAINLCD_480X800__)
        FM_NCELL_HEIGHT = 167
    #elif defined(__MMI_MAINLCD_320X480__)
        FM_NCELL_HEIGHT = 101
    #else // __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__
        FM_NCELL_HEIGHT = 93 
    #endif
    };
    
// Override
public:
    // create FmRadio NCell UI
    virtual void onCreateView(void* viewData, VfxU32 viewDataSize); 

    // close FmRadio NCell UI
    virtual void onCloseView();    
    
    // process FmRadio NCell intent
    virtual void onProcessIntent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize);    
    
// Method
public:
    // close FM Radio NCell
    void onCloseButtonClicked(VfxObject* sender, VfxId id);

// Variable
private:    
    VappWidgetFmRadioPanel *m_fmPanel;
    VcpImageButton         *m_closeButton;
};


/*****************************************************************************
 * FM Radio Widget Panel
 *****************************************************************************/
class VappWidgetFmRadioPanel : public VfxControl
{
public:
    
    enum NcenterUIConstantsEnum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        PN_X = 8,
        PN_Y = 10,
        PN_HEIGHT = 152,
        PN_IMAGE_BTN_X = 12,
        PN_IMAGE_BTN_Y = 9,
        PN_CHANNEL_TEXT_X = 90,
        PN_CHANNEL_TEXT_Y = 18,
        PN_BUTTON_X = 84,
        PN_BUTTON_Y = 79,
        PN_BUTTON_WIDTH = 52,
        PN_BUTTON_HEIGHT = PN_BUTTON_WIDTH,
        PN_POWER_BUTTON_WIDTH = 66,
        PN_POWER_BUTTON_HEIGHT = PN_POWER_BUTTON_WIDTH,        
        PN_CHANNEL_FONT_SIZE = 26    
    #elif defined(__MMI_MAINLCD_320X480__)
        PN_X = 3,
        PN_Y = 5,
        PN_HEIGHT = 96,
        PN_IMAGE_BTN_X = 12,
        PN_IMAGE_BTN_Y = 7,
        PN_CHANNEL_TEXT_X = 46,
        PN_CHANNEL_TEXT_Y = 12,
        PN_BUTTON_X = 44,
        PN_BUTTON_Y = 47,
        PN_BUTTON_WIDTH = 34,
        PN_BUTTON_HEIGHT = PN_BUTTON_WIDTH,
        PN_POWER_BUTTON_WIDTH = 42,
        PN_POWER_BUTTON_HEIGHT = PN_POWER_BUTTON_WIDTH,        
        PN_CHANNEL_FONT_SIZE = 14
    #else // __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__
        PN_X = 4,
        PN_Y = 5,
        PN_HEIGHT = 86,
        PN_IMAGE_BTN_X = 6,
        PN_IMAGE_BTN_Y = 6,
        PN_CHANNEL_TEXT_X = 38,
        PN_CHANNEL_TEXT_Y = 11,
        PN_BUTTON_X = 25,
        PN_BUTTON_Y = 44,
        PN_BUTTON_WIDTH = 30,
        PN_BUTTON_HEIGHT = PN_BUTTON_WIDTH,
        PN_POWER_BUTTON_WIDTH = 36,
        PN_POWER_BUTTON_HEIGHT = PN_POWER_BUTTON_WIDTH,        
        PN_CHANNEL_FONT_SIZE = 13 
    #endif
    };

    enum 
    {
        MIN_FREQ = FM_RADIO_MIN_FREQ,
        MAX_FREQ = FM_RADIO_MAX_FREQ
    };

    enum
    {
        LONGPRESS_DUR_MAX = 350,
        LONGPRESS_DUR_MIN = 100,
        LONGPRESS_DUR_GAP = 25,

        SEEKING_PROMPT_TIME  = 200,
        SEEKING_PROMPT_DURATION_TIME = 300
    };

    enum
    {
        BTN_POWER,
        BTN_NEXT,
        BTN_PREV
    };

public:
    vadp_fm_radio_state_enum        m_state;
    VfxU16                          m_curFreq;

    VappWidgetFmRadioLcd            *m_LCD;


private:    
    VfxId                           m_buttonId;
    VfxId                           m_buttonPressed;
    VcpButton                       *m_btnPower;
    VcpButton                       *m_btnNext;
    VcpButton                       *m_btnPrev;
    VfxTimer                        *m_keyTimer;

    // for seeking prompt
    VfxTimer *m_seekingPromptTimer;
    VfxTimer *m_seekingDelayTimer;
    VfxBool   m_isSeekingDone;

public:
    VappWidgetFmRadioPanel(void);
    virtual void onDeinit(void);
    virtual void onInit();
    static mmi_ret onProc(mmi_event_struct *evt);
    void onButtonClicked(VfxObject* obj, VfxId id);

    void setFreq(VfxU16 freq);
    void updateState(void);
    void updateInfo(void);
    void updateChannelBox(void);

    void startSeek(VfxBool forward);
    static void seekCallback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data);
    void onSeekingTimeout(VfxTimer *source);  
    
    void interrupted(void);
    void setState(vadp_fm_radio_state_enum state);
    void powerOn(void);
    void powerOff(void);

    void onLockKeyHandler(VfxTimer *source);
    void ButtonAction(VfxId id);
    
    static void onWidgetUpdate(mmi_event_struct *evt, void *user_data);
    static MMI_BOOL backgroundCallback(mdi_result result, void *user_data);
    static void generalCallback(mdi_result result, void *user_data);

    // Key event process function.
    // RETURNS: Return true if event has been processed, otherwise return false.
    VfxBool processKeyEvent(
        VfxKeyEvent &event,      // [in] Key event need to be processed.
        VfxBool is_from_avrcp    // [in] Indicate whether the key event is transfered from AVRCP cmd
    );
    
#ifdef __MMI_AVRCP_SUPPORT__
    // AVRCP cmd process function.
    static VfxBool avrcpCmdCallback(
        VfxKeyEvent &event,     // [in]  Key event transfered from AVRCP cmd
        VfxBool is_from_avrcp,  // [in] Indicate whether the key event is transfered from AVRCP cmd
        void *user_data         // [in] User data, usually is the object point of this class
    );
#endif

private:
    void createNCenterPanelUI(void);
    U8 getAppId();
};


/*****************************************************************************
 * FM Radio LCD
 *****************************************************************************/
class VappWidgetFmRadioLcd : public VfxControl
{
public:
    VappWidgetFmRadioLcd(VappWidgetFmRadioPanel *fmPanel);
    
    virtual void onInit(); 
    void createNCenterLcdUI(void);
    void updateChannel(void);
    void updateState(vadp_fm_radio_state_enum state);
    void showSeekingPrompt(VfxBool isShow);

private:
    VfxTextFrame                *m_channel;
    VfxTextFrame                *m_seekingPrompt;
    VappWidgetFmRadioPanel      *m_panel;

};


#endif /* defined(__MMI_NCENTER_SUPPORT__) */
#endif // __MMI_FM_RADIO_SLIM__
#endif /*__VAPP_FM_RADIO_NCENTER_SLIM_H__*/
