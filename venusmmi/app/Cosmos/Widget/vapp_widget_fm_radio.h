/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_fm_radio.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the cosmos fm radio widget.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WIDGET_FM_RADIO_H__
#define __VAPP_WIDGET_FM_RADIO_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FM_RADIO__) || defined(__MMI_NCENTER_SUPPORT__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_ncenter_base_cell.h"

#include "../cosmos/fmradio/vapp_fm_radio_util.h"
#include "../cosmos/fmradio/vapp_fm_radio.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "fmr_config_customize.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VappWidgetFmRadioLcd;
class VappWidgetFmRadioPanel;


/*****************************************************************************
 * FM Radio Panel
 *****************************************************************************/
class VappWidgetFmRadioPanel : public VfxControl
{
public:

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    enum WidgetUIConstantsEnum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        WIDGET_FM_WIDTH = 425,
        WIDGET_FM_HEIGHT = 210,
        WIDGET_FM_TITLE_FONT_SIZE = 28,
        WIDGET_FM_SUB_TITLE_FONT_SIZE = 19,
        WIDGET_FM_GET_BUFFER_OFFSET_X = 12,
        WIDGET_FM_GET_BUFFER_OFFSET_Y = 15,
        PN_BUTTON_W = 60,
        PN_BUTTON_H = 62,
        LOCK_TEXT_Y = 123,
        GAP_NEXT_POWER = 32,
        GAP_PREV_POWER = 32,
    #elif defined(__MMI_MAINLCD_320X480__)
        WIDGET_FM_WIDTH = 283,
        WIDGET_FM_HEIGHT = 141,
        WIDGET_FM_TITLE_FONT_SIZE = 20,
        WIDGET_FM_SUB_TITLE_FONT_SIZE = 13,
        WIDGET_FM_GET_BUFFER_OFFSET_X = 12,
        WIDGET_FM_GET_BUFFER_OFFSET_Y = 15,
        PN_BUTTON_W = 40,
        PN_BUTTON_H = 40,
        LOCK_TEXT_Y = 84,
        GAP_NEXT_POWER = 19,
        GAP_PREV_POWER = 19,
    #else // __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__
        WIDGET_FM_WIDTH = 216,
        WIDGET_FM_HEIGHT = 109,
        WIDGET_FM_TITLE_FONT_SIZE = 20,
        WIDGET_FM_SUB_TITLE_FONT_SIZE = 9,
        WIDGET_FM_GET_BUFFER_OFFSET_X = 12,
        WIDGET_FM_GET_BUFFER_OFFSET_Y = 12,
        PN_BUTTON_W = 31,
        PN_BUTTON_H = 32,
        LOCK_TEXT_Y = 63,
        GAP_NEXT_POWER = 15,
        GAP_PREV_POWER = 15,
    #endif
    };
#endif

#if defined(__MMI_NCENTER_SUPPORT__)
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
#endif

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
        MODE_LOCK,
        MODE_NCENTER,
        MODE_WIDGET
    };

    enum
    {
        BTN_POWER,
        BTN_NEXT,
        BTN_PREV
    };

private:
    VfxS32 m_width;
    VfxS32 m_height;

    VfxS32 m_width_hole;
    VfxS32 m_height_hole; 
    VfxImageFrame *m_background;
    VfxImageFrame *m_hole;
    
    VfxId m_buttonId;
    VcpButton *m_btnPower;
    VcpButton *m_btnNext;
    VcpButton *m_btnPrev;
    VfxId m_buttonPressed;
    VfxTimer *m_keyTimer;

    // for seeking prompt
    VfxTimer *m_seekingPromptTimer;
    VfxTimer *m_seekingDelayTimer;
    VfxBool   m_isSeekingDone;

#ifdef __MMI_FM_RADIO_RECORD__
    VcpConfirmPopup *m_startCnf;
#endif

public:
    vadp_fm_radio_state_enum m_state;
    VappWidgetFmRadioLcd *m_LCD;
    VfxU16 m_curFreq;
    VfxU8 m_mode;

public:
    VappWidgetFmRadioPanel(void);
    VappWidgetFmRadioPanel(VfxU8 mode);
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
    
    void setPanelActive(VfxBool is_active);
    void interrupted(void);
    void setState(vadp_fm_radio_state_enum state);
    void powerOn(void);
    void powerOff(void);

    void onLockKeyHandler(VfxTimer *source);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    void ButtonAction(VfxId id);

#ifdef __MMI_FM_RADIO_RECORD__
    VfxBool stopRecConfirm(void);
    void onStopRecButtonClicked(VfxObject* sender, VfxId btn);
#endif

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
#endif // __MMI_AVRCP_SUPPORT__

private:

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    void createWidgetPanelUI(void);
#endif

#if defined(__MMI_NCENTER_SUPPORT__)
    void createNCenterPanelUI(void);
#endif

    U8 getAppId();
};

/*****************************************************************************
 * FM Radio Panel
 *****************************************************************************/
class VappWidgetFmRadioLcd : public VfxControl
{
public:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        LCD_W = 274,
        LCD_H = 97,
        FM_X = 40,
        FM_Y = 24,
        CHANNEL_X = 116,
        CHANNEL_Y = 24,
        CHANNEL_FONT_ZISE = 48,
        RDS_FONT_SIZE = 21
    #elif defined(__MMI_MAINLCD_320X480__)
        LCD_W = 183,
        LCD_H = 66,
        FM_X = 32,
        FM_Y = 17,
        CHANNEL_X = 84,
        CHANNEL_Y = 17,
        CHANNEL_FONT_ZISE = 32,
        RDS_FONT_SIZE = 14
    #else
        LCD_W = 138,
        LCD_H = 50,
        FM_X = 23,
        FM_Y = 13,
        CHANNEL_X = 62,
        CHANNEL_Y = 13,
        CHANNEL_FONT_ZISE = 24,
        RDS_FONT_SIZE = 14
    #endif

    };


private:
    VfxFrame *m_dark;
    VfxFrame *m_highlight;
    VfxTextFrame *m_channel;
    VfxTextFrame *m_seekingPrompt;

public:
    VappWidgetFmRadioPanel* m_panel;

public:
    VappWidgetFmRadioLcd(VappWidgetFmRadioPanel *fmPanel);
    virtual void onInit();

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    void createWidgetLcdUI(void);
#endif
    
#if defined(__MMI_NCENTER_SUPPORT__)
    void createNCenterLcdUI(void);
#endif
    virtual VfxBool onPenInput(VfxPenEvent & event);
    void updateChannel(void);
    void updateState(vadp_fm_radio_state_enum state);
    void showSeekingPrompt(VfxBool isShow);

};

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)

/*****************************************************************************
 * FM Radio Widget
 *****************************************************************************/
 
class VappWidgetFmRadio : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetFmRadio);

private:
    VappWidgetFmRadioPanel *m_panel;

public:
    VappWidgetFmRadio();

#if defined(__MMI_NCENTER_SUPPORT__)
    virtual void onInit();
    virtual void onDeinit();
    // Handle NCenter events
    void onNCenterStatusChanged(VappNCenterEventEnum evt);
#endif

    virtual VappWidgetId getId() const;
    virtual VfxSize getMaxSize() const;
    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    virtual VfxFrame *createIcon(VfxObject *parentObj);
    virtual void onSerializeView(VfxArchive *ar);
    virtual void onRestoreView(VfxArchive *ar);
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual VfxPoint onGetEditButtonOffset(void);
};
#endif /* defined(__MMI_VUI_WIDGET_FM_RADIO__) */

#endif /* defined(__MMI_VUI_WIDGET_FM_RADIO__) || defined(__MMI_NCENTER_SUPPORT__) */ 
#endif /* __VAPP_WIDGET_FM_RADIO_H__ */

