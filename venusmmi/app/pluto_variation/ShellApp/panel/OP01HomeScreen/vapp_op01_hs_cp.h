/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  vapp_op01_hs_cp.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of homescreen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_OP11_HS_CP_H__
#define __VAPP_OP11_HS_CP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vdat_include.h"


/********************************************************************************* 
 * Class VappOp01HsNwInfo: network info class used for show network name and SPN
 ********************************************************************************/

class VappOp01HsNwInfo : public VfxFrame
{
// Declare
public:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        SECOND_TEXT_POS_X = 160,
        SINGLE_TEXT_WIDTH = 304,
        TWO_TEXT_WIDTH = 152
    #else
        SECOND_TEXT_POS_X = 137,
        SINGLE_TEXT_WIDTH = 226,
        TWO_TEXT_WIDTH = 130
    #endif
    };

// Constructor / Destructor
public:
    VappOp01HsNwInfo();

// Method
public:
    // Set network name string
    void setNetworkName(
        const VfxWString &str       // [IN] network name string
    );

    // Set network status string
    void setNetworkStatus(
        const VfxWString &str       // [IN] SPN string
    );

    // Refine layout
    void refineLayout();

// Override
protected:
    virtual void onInit();

// Variable
private:
    // Network name string
    VfxTextFrame        *m_nwNameText;

    // Network state string
    VfxTextFrame        *m_nwStateText;
};

/********************************************************************************************* 
 * Class VappOp01HsIdleModeText: idle mode text class used for display SAT icon or song name
 ********************************************************************************************/

class VappOp01HsIdleModeText : public VfxFrame
{
// Constructor / Destructor
public:
    VappOp01HsIdleModeText();

// Method
public:
    // Set network name string
    void setIdleModeText(
        const VfxWString &str       // [IN] SAT or song name string
    );

    // Set network status string
    void setIdleModeIcon(
        const VfxU8 *iconPtr       // [IN] SAT icon
    );

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

// Variable
private:
    // SAT or song name string
    VcpMarquee        *m_idleModeText;

    // SAT icon
    VfxImageFrame     *m_idleModeIcon;

    // SAT string
    VfxWString        m_idleModeStr;

    // Left/right bracket
    VfxTextFrame      *m_bracketFrame[2];

// Declare
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        FRAME_WIDTH = 320,
        FRAME_HEIGHT = 36,
        ICON_WIDTH = 8,
        ICON_HEIGHT = ICON_WIDTH,
        ICON_POS_X = 8,
        ICON_POS_Y = (FRAME_HEIGHT - ICON_HEIGHT) >> 1,
        TEXT_WIDTH = 252,
        TEXT_HEIGHT = FRAME_HEIGHT,
        ICON_BRACKET_GAP = 5,
        BRACKET_POS_X1 = ICON_POS_X + ICON_WIDTH + ICON_BRACKET_GAP,
        BRACKET_POS_X2 = FRAME_WIDTH - BRACKET_POS_X1,
        MARQUEE_SPEED = 10
    #else
        FRAME_WIDTH = 240,
        FRAME_HEIGHT = 28,
        ICON_WIDTH = 8,
        ICON_HEIGHT = ICON_WIDTH,
        ICON_POS_X = 7,
        ICON_POS_Y = (FRAME_HEIGHT - ICON_HEIGHT) >> 1,
        TEXT_WIDTH = 176,
        TEXT_HEIGHT = FRAME_HEIGHT,
        ICON_BRACKET_GAP = 5,
        BRACKET_POS_X1 = ICON_POS_X + ICON_WIDTH + ICON_BRACKET_GAP,
        BRACKET_POS_X2 = FRAME_WIDTH - BRACKET_POS_X1,
        MARQUEE_SPEED = 10
    #endif
    };
};


/***************************************************************************** 
 * Class VappHsStatusIcon: status icon class
 *****************************************************************************/

class VappHsStatusIcon : public VfxControl
{
// Constructor / Destructor
public:
    // Default constructor
    VappHsStatusIcon() {}

// Override
protected:
    virtual void onInit();
};

/***************************************************************************** 
 * Class VappOp01HsHintBox: unread call/SMS/MMS info class
 *****************************************************************************/

class VappOp01HsHintBox : public VfxControl
{
// Declare
public:
    // Hint box type
    enum VappOP01HintTypeEnum
    {
        HINT_TYPE_NONE = 0,
        HINT_TYPE_SMS,
        HINT_TYPE_MMS,
        HINT_TYPE_CALL,
        HINT_TYPE_END_OF_ENUM
    };

    // Hint box state
    enum VappOP01HintStateEnum
    {
        HINT_STATE_NORMAL = 0,
        HINT_STATE_PRESSED,
        HINT_STATE_END_OF_ENUM
    };

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        ICON_POS_X = 2,
        TEXT_POS_X = 53
    #else
        ICON_POS_X = 3,
        TEXT_POS_X = 49
    #endif
    };

// Constructor / Destructor
public:
    VappOp01HsHintBox();

// Method
public:
    // Set hint string
    void setHintStr(
        VfxS32 num   // [IN] number
    );

    // Set hint type
    void setHintType(
        VappOP01HintTypeEnum type   // [IN] type
    );

// Override
protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slots
private:
    void launchApp();

    // Set hint state
    void setHintState(
        VappOP01HintStateEnum state   // [IN] state
    );

// Variable
private:
    VfxImageFrame           *m_hintBoxBg;

    VfxImageFrame           *m_hintBoxIcon;
    
    VfxTextFrame            *m_hintStr;

    VappOP01HintTypeEnum    m_hintType;
};

/***************************************************************************** 
 * Class VappOp01HsSearchButton: search button class
 *****************************************************************************/

class VappOp01HsSearchButton : public VfxControl
{
// Declare
public:
    // Button state
    enum VappOP01ButtonStateEnum
    {
        BUTTON_STATE_NORMAL = 0,
        BUTTON_STATE_PRESSED,
        BUTTON_STATE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    VappOp01HsSearchButton();

// Override
protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slots
private:
    void launchApp();

    // Set button state
    void setButtonState(
        VappOP01ButtonStateEnum state   // [IN] state
    );

// Variable
private:
    VfxImageFrame   *m_buttonBg;
    
    VfxImageFrame   *m_searchIcon;
};

/***************************************************************************** 
 * Class VappOp01HsWlanSwitch: WLAN switch class
 *****************************************************************************/

class VappOp01HsWlanSwitch : public VfxControl
{
// Declare
public:
    // WLAN switch
    enum VappOP01WlanSwitchEnum
    {
        WLAN_SWITCH_OFF = 0,
        WLAN_SWITCH_ON,
        WLAN_SWITCH_END_OF_ENUM
    };

    // WLAN state
    enum VappOP01WlanButtonStateEnum
    {
        WLAN_STATE_NORMAL = 0,
        WLAN_STATE_PRESSED,
        WLAN_STATE_END_OF_ENUM
    };

    enum
    {
        IND_NUMBER = 4,
    #if defined(__MMI_MAINLCD_320X480__)
        ICON_POS_Y = 9,
        IND_POS_X = 9,
        IND_POS_Y = 49,
        IND_GAP = 6,
        IND_HEIGHT = 6
    #else
        ICON_POS_Y = 8,
        IND_POS_X = 8,
        IND_POS_Y = 45,
        IND_GAP = 6,
        IND_HEIGHT = 5
    #endif
    };

// Constructor / Destructor
public:
    VappOp01HsWlanSwitch(VfxS32 status);

// Method
public:
    void updateButton();

// Override
protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slots
private:
    void onStartScrollInd(VfxTimer *timer);

// Variable
private:
    VfxImageFrame   *m_buttonBg;
    
    VfxImageFrame   *m_wlanIcon;

    VfxFrame        *m_IndFrame;

    VfxImageFrame   *m_switchInd[IND_NUMBER];

    VfxS32         m_wlanStatus;     // WLAN status

    VfxTimer        *m_indTimer;    // Indicator scroll timer

    VfxS32          m_scrollIndex;   // Scroll index from timer start for indicator scroll

// Implementation
private:
    // Set button state
    void setWlanButtonState(
        VappOP01WlanButtonStateEnum state   // [IN] state
    );

    // Set WLAN switch
    void setWlanSwitch(
        VappOP01WlanSwitchEnum state   // [IN] switch
    );

    void startScrollInd();

    void switchWlan();
};

/***************************************************************************** 
 * Class VappOp01HsDateTime: date and time class
 *****************************************************************************/

class VappOp01HsDateTime : public VfxControl
{
// Declare
public:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        LINE_GAP = 6
    #else
        LINE_GAP = 4
    #endif
    };

// Constructor / Destructor
public:
    VappOp01HsDateTime();

// Override
protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slots
private:
    void launchApp();

    void setTextNormal();

    void setTextPressed();

// Variable
private:
    VcpDigitalTextClock *m_time;
    
    VcpDigitalTextClock *m_day;
};

/***************************************************************************** 
 * Class VappOp01HsShctIcon: shortcut icon class
 *****************************************************************************/

class VappOp01HsShctIcon : public VfxControl
{
// Declare
public:
    // Shortcut state
    enum VappOP01ShctStateEnum
    {
        SHCT_STATE_NORMAL,
        SHCT_STATE_PRESSED,
        SHCT_STATE_END_OF_ENUM
    };

    // Shortcut layout
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        ICON_WIDTH = 60,
        ICON_HEIGHT = 60
    #else
        ICON_WIDTH = 46,
        ICON_HEIGHT = 46
    #endif
    };


// Constructor / Destructor
public:
    VappOp01HsShctIcon(
        VfxS32 index,
        VfxS32 resId,
        FuncPtr penHandler
    );

// Signal
public:
    VfxSignal1 <VfxS32> m_signalPressed;
    
    VfxSignal1 <VfxS32> m_signalNormal;

// Override
protected:
    virtual void onInit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slots
private:
    void launchApp();

// Implementation
private:
    void shctIconRoomIn();

    void shctIconRoomOut();

// Variable
private:
    VfxS32                  m_shctIndex;

    VfxS32                  m_shctResId;

    FuncPtr                 m_penHandler;

    VfxImageFrame           *m_shctIconImg;

    VappOP01ShctStateEnum   m_shctState;

    VfxTransformTimeline    *m_zoomTimeLine;
};

/***************************************************************************** 
 * Class VappOp01HsShctBar: shortcut bar class
 *****************************************************************************/

class VappOp01HsShctBar : public VfxControl
{
// Declare
public:
    // Shortcut bar layout
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        ARROW_ICON_GAP = 1,
        ICON_GAP = 4,
        ARROW_WIDTH = 33,
        ARROW_HEIGHT = 60,
        ICON_WIDTH = 60,
        ICON_HEIGHT = 60,
        SC_BG_WIDTH = 320,
        SC_BG_HEIGHT = 62,
        SC_AREA_POS_X = 30,
        SC_AREA_WIDTH = SC_BG_WIDTH - (SC_AREA_POS_X << 1),
        SC_AREA_HEIGHT = SC_BG_HEIGHT,
    #else
        ARROW_ICON_GAP = 0,
        ICON_GAP = 2,
        ARROW_WIDTH = 25,
        ARROW_HEIGHT = 46,
        ICON_WIDTH = 46,
        ICON_HEIGHT = 46,
        SC_BG_WIDTH = 240,
        SC_BG_HEIGHT = 50,
        SC_AREA_POS_X = 23,
        SC_AREA_WIDTH = SC_BG_WIDTH - (SC_AREA_POS_X << 1),
        SC_AREA_HEIGHT = SC_BG_HEIGHT,
    #endif
        MAX_CNT = 11,
        MAX_CNT_PER_VIEW = 4,
        MAX_VIEW_CNT = MAX_CNT + MAX_CNT_PER_VIEW,
        SCROLL_TL_DURATION = 300
    };

// Constructor / Destructor
public:
    VappOp01HsShctBar();

// Method
public:

// Override
protected:
    virtual void onInit();

// Implementation
private:
    void initShctItem();

    void onShctPressed(VfxS32 index);

    void onShctNormal(VfxS32 index);

    void onLeftArrowUp();

    void onRightArrowUp();

    void onScrollAnimStop(VfxBaseTimeline *timeline, VfxBool isCompleted);

// Variable
private:
    VfxImageFrame       *m_shctBarBg;

    VfxControl          *m_shctArea;

    VfxImageFrame       *m_shctHighlightBg[MAX_VIEW_CNT];

    VappOp01HsShctIcon  *m_shctIcon[MAX_VIEW_CNT];

    VcpButtonInternal   *m_arrowButton[2];

    VfxS32              m_scrollFromId;

    VfxS32              m_scrollToId;

    VfxS32              m_shctCount;

    VfxS32Timeline      *m_scrollingTl;
};

#ifdef __MMI_OP01_DCD_V30__
/***************************************************************************** 
 * Class VappOp01HsDCDMarquee: DCD content marquee class
 *****************************************************************************/

class VappOp01HsDCDMarquee : public VfxControl
{
    VFX_DECLARE_CLASS(VappOp01HsDCDMarquee);

// Constructor
public:
    VappOp01HsDCDMarquee();

// Declaration
public:
    enum 
    {
        // Scrolled pixels per second
        SLOW_SPEED = 5,
        MIDDLE_SPEED = 10,
        FAST_SPEED = 15,

        // Time delay before scrolling
        DELAY_TIME = 3000
    };

// Signal
public:    
    // Signal when the scrolling is finished
    VfxSignal1 <VappOp01HsDCDMarquee *> m_signalScrollFinished;

// Method
public:
    VfxS32 getSpeed() const;

    VfxMsec getStartDelay() const;

    void setSpeed(VfxS32 value);

    void setStartDelay(VfxMsec value);

    void startScroll();

    void stopScroll();
    
    VfxBool needScroll();

    VfxBool isScrolling() const 
    {
        return m_isScrolling;
    }

    // Release the previous movable frame and related data
    void clearMovableFrame();
      
    void setMovableFrame(VfxFrame *frame);

// Override
protected: 
    virtual void onInit();

    virtual void onDeinit();

// Implementation
private: 
    void startTimeline();

    void stopTimeline();
   
    inline VfxRect getMovableBounds() const {return m_movableFrame == NULL ? VFX_RECT_ZERO : m_movableFrame->getBounds();}

    inline VfxRect getMarqueeBounds() const {return getBounds();}

    VfxS32 computeTimelineDuration(
        VfxS32 distance // The moving distance
    );

// Slot
private:    
    // Callback when timeline is stopped
    void onTimelineStop(VfxBaseTimeline *timeline, VfxBool isCompleted);

// Variables
private:
    VfxFrame *m_movableFrame;

    VfxS32Timeline *m_scrollTimeline;

    VfxBool m_isScrolling;

    VfxS32 m_speed;

    VfxMsec m_startDelay;
};


/***************************************************************************** 
 * Class VappOp01HsDCDNewsArea: DCD news area class
 *****************************************************************************/

class VappOp01HsDCDNewsArea : public VfxControl
{
    VFX_DECLARE_CLASS(VappOp01HsDCDNewsArea);

// Constructor / Destructor
public:
    VappOp01HsDCDNewsArea();

// Method
public:
    void updateImg();

    void updateContent();

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

    void onScrollStop(VappOp01HsDCDMarquee *scrollFrame);

    void entryDCDChannelFirstPage();

// Implementation
private:
    void creatNewsContent();
    
    VfxFrame* getCurrentContent();

    VfxFrame* getPrevContent();

    VfxFrame* getNextContent();

    void closeContentFrame();

    void scrollToNextNews(VfxBool isNext);

// Declare
private:
    // Content layout
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        // News image layout
        IMG_AREA_WIDTH = 80,
        IMG_AREA_HEIGHT = 86,
        IMAGE_DEFAULT_POS_X = 5,
        IMAGE_DEFAULT_POS_Y = 8,
        IMAGE_DEFAULT_WIDTH = 70,
        IMAGE_DEFAULT_HEIGHT = IMAGE_DEFAULT_WIDTH,
        IMAGE_POS_X = 15,
        IMAGE_POS_Y = 18,
        IMAGE_WIDTH = 50,
        IMAGE_HEIGHT = 50,

        // News content layout
        CONTENT_AREA_POS_X = IMG_AREA_WIDTH,
        CONTENT_AREA_POS_Y = 3,
        CONTENT_WIDTH = 158,
        CONTENT_HEIGHT = IMG_AREA_HEIGHT - (CONTENT_AREA_POS_Y << 1),
        CONTENT_OFFSET_Y = 2,    // For content align-middle in content area when not scrolling
        CONTENT_FONT_SIZE = 16,
        CONTENT_LINE_HEIGHT = 20,
    #elif defined(__MMI_MAINLCD_240X400__)
        // News image layout
        IMG_AREA_WIDTH = 60,
        IMG_AREA_HEIGHT = 73,
        IMAGE_DEFAULT_POS_X = 5,
        IMAGE_DEFAULT_POS_Y = 12,
        IMAGE_DEFAULT_WIDTH = 50,
        IMAGE_DEFAULT_HEIGHT = IMAGE_DEFAULT_WIDTH,
        IMAGE_POS_X = IMAGE_DEFAULT_POS_X,
        IMAGE_POS_Y = IMAGE_DEFAULT_POS_Y,
        IMAGE_WIDTH = IMAGE_DEFAULT_WIDTH,
        IMAGE_HEIGHT = IMAGE_WIDTH,
        
        // News content layout
        CONTENT_AREA_POS_X = IMG_AREA_WIDTH,
        CONTENT_AREA_POS_Y = 2,
        CONTENT_WIDTH = 118,
        CONTENT_HEIGHT = IMG_AREA_HEIGHT - (CONTENT_AREA_POS_Y << 1),
        CONTENT_OFFSET_Y = 2,    // For content align-middle in content area when not scrolling
        CONTENT_FONT_SIZE = 14,
        CONTENT_LINE_HEIGHT = 17,
    #else
        // News image layout
        IMG_AREA_WIDTH = 60,
        IMG_AREA_HEIGHT = 60,
        IMAGE_DEFAULT_POS_X = 5,
        IMAGE_DEFAULT_POS_Y = 5,
        IMAGE_DEFAULT_WIDTH = 50,
        IMAGE_DEFAULT_HEIGHT = IMAGE_DEFAULT_WIDTH,
        IMAGE_POS_X = IMAGE_DEFAULT_POS_X,
        IMAGE_POS_Y = IMAGE_DEFAULT_POS_Y,
        IMAGE_WIDTH = IMAGE_DEFAULT_WIDTH,
        IMAGE_HEIGHT = IMAGE_WIDTH,
        
        // News content layout
        CONTENT_AREA_POS_X = IMG_AREA_WIDTH,
        CONTENT_AREA_POS_Y = 2,
        CONTENT_WIDTH = 118,
        CONTENT_HEIGHT = IMG_AREA_HEIGHT - (CONTENT_AREA_POS_Y << 1),
        CONTENT_OFFSET_Y = 2,    // For content align-middle in content area when not scrolling
        CONTENT_FONT_SIZE = 12,
        CONTENT_LINE_HEIGHT = 14,
    #endif
        // TODO: Need to confirm according to Spec
        MAX_LINE_NUMBER = 10
    };

// Variable
private:
    VfxImageFrame           *m_newsImg;

    VappOp01HsDCDMarquee    *m_newsContent;

    VfxFrame                *m_scrollArea;

    VfxTextFrame            *m_channelName;

    VfxTextFrame            *m_entryList[MAX_LINE_NUMBER];

    VfxS32                  m_contentHeight;

    static const VfxS32     s_penScrollThreshold;
};


/***************************************************************************** 
 * Class VappOp01HsDCDWeatherArea: DCD weather area class
 *****************************************************************************/

class VappOp01HsDCDWeatherArea : public VfxControl
{
// Constructor / Destructor
public:
    VappOp01HsDCDWeatherArea();

// Method
public:
    void update();

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slots
private:
    void creatWeatherContent();

    void EntryDCDWeatherFirstPage();

// Declare
private:
    // Image layout
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        // Whether area layout 
        WHETHER_AREA_WIDTH = 80,
        WHETHER_AREA_HEIGHT = 86,

        // Default image layout
        WEATHER_IMAGE_DEFAULT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        WEATHER_IMAGE_DEFAULT_POS_Y = 8,
        WEATHER_IMAGE_DEFAULT_WIDTH = 70,
        WEATHER_IMAGE_DEFAULT_HEIGHT = WEATHER_IMAGE_DEFAULT_WIDTH,

        // Whether image layout
        WEATHER_IMAGE_WIDTH = 37,
        WEATHER_IMAGE_HEIGHT = WEATHER_IMAGE_WIDTH,
        WEATHER_IMAGE_POS_X = (WHETHER_AREA_WIDTH >> 1),
        WEATHER_IMAGE_POS_Y = 5,

        // City name layout
        CITY_NEME_TEXT_WIDTH = WHETHER_AREA_WIDTH - 4,
        CITY_NEME_TEXT_HEIGHT = (WHETHER_AREA_HEIGHT >> 2),
        CITY_NEME_TEXT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        CITY_NEME_TEXT_POS_Y = 55,
        CITY_NAME_TEXT_FONT_SIZE = 14,

        // Temperature layout
        TEMPERATURE_TEXT_WIDTH = WHETHER_AREA_WIDTH,
        TEMPERATURE_TEXT_HIGHT = CITY_NEME_TEXT_HEIGHT,
        TEMPERATURE_TEXT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        TEMPERATURE_TEXT_POS_Y = 75,
        TEMPERATURE_TEXT_FONT_SIZE = CITY_NAME_TEXT_FONT_SIZE
    #elif defined(__MMI_MAINLCD_240X400__)
        // Whether area layout 
        WHETHER_AREA_WIDTH = 60,
        WHETHER_AREA_HEIGHT = 73,
        
        // Default image layout
        WEATHER_IMAGE_DEFAULT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        WEATHER_IMAGE_DEFAULT_POS_Y = 11,
        WEATHER_IMAGE_DEFAULT_WIDTH = 50,
        WEATHER_IMAGE_DEFAULT_HEIGHT = WEATHER_IMAGE_DEFAULT_WIDTH,
        
        // Whether image layout
        WEATHER_IMAGE_WIDTH = 32,
        WEATHER_IMAGE_HEIGHT = WEATHER_IMAGE_WIDTH,
        WEATHER_IMAGE_POS_X = (WHETHER_AREA_WIDTH >> 1),
        WEATHER_IMAGE_POS_Y = 5,
        
        // City name layout
        CITY_NEME_TEXT_WIDTH = WHETHER_AREA_WIDTH - 6,
        CITY_NEME_TEXT_HEIGHT = (WHETHER_AREA_HEIGHT >> 2),
        CITY_NEME_TEXT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        CITY_NEME_TEXT_POS_Y = 48,
        CITY_NAME_TEXT_FONT_SIZE = 10,
        
        // Temperature layout
        TEMPERATURE_TEXT_WIDTH = WHETHER_AREA_WIDTH,
        TEMPERATURE_TEXT_HIGHT = CITY_NEME_TEXT_HEIGHT,
        TEMPERATURE_TEXT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        TEMPERATURE_TEXT_POS_Y = 64,
        TEMPERATURE_TEXT_FONT_SIZE = CITY_NAME_TEXT_FONT_SIZE
    #else
        // Whether area layout 
        WHETHER_AREA_WIDTH = 60,
        WHETHER_AREA_HEIGHT = 60,
        
        // Default image layout
        WEATHER_IMAGE_DEFAULT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        WEATHER_IMAGE_DEFAULT_POS_Y = 5,
        WEATHER_IMAGE_DEFAULT_WIDTH = 50,
        WEATHER_IMAGE_DEFAULT_HEIGHT = WEATHER_IMAGE_DEFAULT_WIDTH,
        
        // Whether image layout
        WEATHER_IMAGE_WIDTH = 25,
        WEATHER_IMAGE_HEIGHT = WEATHER_IMAGE_WIDTH,
        WEATHER_IMAGE_POS_X = (WHETHER_AREA_WIDTH >> 1),
        WEATHER_IMAGE_POS_Y = 5,
        
        // City name layout
        CITY_NEME_TEXT_WIDTH = WHETHER_AREA_WIDTH - 6,
        CITY_NEME_TEXT_HEIGHT = (WHETHER_AREA_HEIGHT >> 2),
        CITY_NEME_TEXT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        CITY_NEME_TEXT_POS_Y = 38,
        CITY_NAME_TEXT_FONT_SIZE = 10,
        
        // Temperature layout
        TEMPERATURE_TEXT_WIDTH = WHETHER_AREA_WIDTH,
        TEMPERATURE_TEXT_HIGHT = CITY_NEME_TEXT_HEIGHT,
        TEMPERATURE_TEXT_POS_X = (WHETHER_AREA_WIDTH >> 1),
        TEMPERATURE_TEXT_POS_Y = 52,
        TEMPERATURE_TEXT_FONT_SIZE = CITY_NAME_TEXT_FONT_SIZE
    #endif
    };

// Variable
private:
    VfxImageFrame   *m_weatherImg;

    VfxTextFrame    *m_cityName;

    VfxTextFrame    *m_temperatureValue;
};


/***************************************************************************** 
 * Class VappOp01HsDCDBar: DCD bar class
 *****************************************************************************/

class VappOp01HsDCDBar : public VfxControl
{
// Declare
public:
    // DCD bar layout
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        BG_WIDTH = 320,
        BG_HEIGHT = 86,
        NEWS_AREA_WIDTH = 240,
        NEWS_AREA_HEIGHT = BG_HEIGHT,
        WEATHER_AREA_POS_X = NEWS_AREA_WIDTH,
        WEATHER_AREA_WIDTH = BG_WIDTH >> 2,
        WEATHER_AREA_HEIGHT = BG_HEIGHT
    #elif defined(__MMI_MAINLCD_240X400__)
        BG_WIDTH = 240,
        BG_HEIGHT = 73,
        NEWS_AREA_WIDTH = 180,
        NEWS_AREA_HEIGHT = BG_HEIGHT,
        WEATHER_AREA_POS_X = NEWS_AREA_WIDTH,
        WEATHER_AREA_WIDTH = BG_WIDTH >> 2,
        WEATHER_AREA_HEIGHT = BG_HEIGHT
    #else
        BG_WIDTH = 240,
        BG_HEIGHT = 60,
        NEWS_AREA_WIDTH = 180,
        NEWS_AREA_HEIGHT = BG_HEIGHT,
        WEATHER_AREA_POS_X = NEWS_AREA_WIDTH,
        WEATHER_AREA_WIDTH = BG_WIDTH >> 2,
        WEATHER_AREA_HEIGHT = BG_HEIGHT
    #endif
    };

// Constructor / Destructor
public:
    VappOp01HsDCDBar();

// Method
public:
    void updateDCDNewsImgArea();

    void updateDCDNewsContentArea();

    void updateDCDWhetherArea();

// Override
protected:
    virtual void onInit();

// Variable
private:
    VfxImageFrame               *m_dcdBarBg;

    VappOp01HsDCDNewsArea       *m_dcdNewsArea;

    VappOp01HsDCDWeatherArea    *m_dcdWeatherArea;
};

#endif /* __MMI_OP01_DCD_V30__ */
#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
#endif /* __VAPP_OP11_HS_CP_H__ */

