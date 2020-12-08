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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_op_launcher_key_hs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements shortcut bar
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_OP_LAUNCHER_KEY_HS_H
#define VAPP_OP_LAUNCHER_KEY_HS_H

#include "MMI_features.h"

#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_key_clock.h"
#include "vapp_launcher_key_mainmenu_builder.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "DtcntSrvGprot.h"
#include "NwNameSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Configuration (Debug Only)
 *****************************************************************************/

/* Unit-test: enable catcher logging. */
#define VAPP_OP_KEYLAUNCHER_UT_ENABLE_CATCHER_LOG

/* Unit-test: enable SWLA logging. */
#define VAPP_OP_KEYLAUNCHER_UT_ENABLE_SWLA_LOG

/*
 * Catcher logging:
 *
 * Note: Only target compiler supports C99 __VA_ARGS__.
 */
#if defined(__MTK_TARGET__) && defined(VAPP_OP_KEYLAUNCHER_UT_ENABLE_CATCHER_LOG)
#define VAPP_OP_KEYLAUNCHER_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define VAPP_OP_KEYLAUNCHER_LOG(_x)     VAPP_OP_KEYLAUNCHER_LOG_EX _x
#else
#define VAPP_OP_KEYLAUNCHER_LOG(_x)
#endif

/*
 * SWLA logging:
 */
#if defined(__MTK_TARGET__) && defined(VAPP_OP_KEYLAUNCHER_UT_ENABLE_SWLA_LOG)
#define VAPP_OP_KEYLAUNCHER_SLA(_x)    SLA_CustomLogging _x
#else
#define VAPP_OP_KEYLAUNCHER_SLA(_x)
#endif

	
/*****************************************************************************
 * Idle page, Which is one page of Home
 *****************************************************************************/

class VappOpKeyLauncherShrtBar;
class VappOpKeyLauncherOperatorFrame;
#ifdef __MMI_OP01_WIFI__
class VappOp01KeyLauncherWlanSwitch;
#endif
class VappOpKeyLauncherIdleModeText;

class VappOpKeyLauncherIdlePage : public VfxControl
{
VFX_DECLARE_CLASS(VappOpKeyLauncherIdlePage);

// Constructor / Destructor
public:
    // Default constructor.
    VappOpKeyLauncherIdlePage();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

#ifdef __MMI_OP01_WIFI__
// Override
protected:
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );
#endif

public:
	// This function will set whether hidden or focused to receive key event
	virtual void setHidden(VfxBool value);

// Layout
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 320,
        VAPP_OP_KEYLAUNCHER_OPNAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_Y = 150,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_Y = 220,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT = 18,
        VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_MARGIN = 10,
        VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_Y = 310,
        VAPP_OP_KEYLAUNCHER_SHORTCUT_BAR_Y = 340
    #elif defined(__MMI_MAINLCD_240X400__)
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 240,
        VAPP_OP_KEYLAUNCHER_OPNAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_Y = 105,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_Y = 180,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT = 14,
        VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_MARGIN = 7,
        VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_Y = 263,
        VAPP_OP_KEYLAUNCHER_SHORTCUT_BAR_Y = 298
    #else /* __MMI_MAINLCD_240X320__ */
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 240,
        VAPP_OP_KEYLAUNCHER_OPNAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_Y = 96,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_Y = 160,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT = 14,
        VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_MARGIN = 7,
        VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_Y = 213,
        VAPP_OP_KEYLAUNCHER_SHORTCUT_BAR_Y = 223
    #endif
    };

// State
    enum VappOp01FocuseStateEnum
    {
        FOCUSE_STATE_SHORTCUT,
        FOCUSE_STATE_WLAN,
        FOCUSE_STATE_END_OF_ENUM
    };

// Variable
private:
	// Date and time frame at top of idel page
	VappLauncherKeyClock            *m_dateTime;

    // Operator name
    VappOpKeyLauncherOperatorFrame    *m_opName;

	VappOpKeyLauncherIdleModeText   *m_idleMode;

#ifdef __MMI_OP01_WIFI__
    // WLAN button
    VappOp01KeyLauncherWlanSwitch   *m_wlanButton;
#endif

    // Shortcut bar
    VappOpKeyLauncherShrtBar        *m_shortcutBar;

    static VappOp01FocuseStateEnum  s_focuseState;
    
// Implement
private:
	// This function is to create shortcut bar
	void createShortcutBar();

    // This function is to create operator name
	void createOperatorName();

#ifdef __MMI_OP01_WIFI__
    // This function is to create WLAN button
    void createWlanButton();

    void onUnFocusedWlanButton(void);

    void onUnFocusedShrt(void);
#endif
};


/***************************************************************************** 
 * Class VappOpKeyLauncherShrtBar
 *****************************************************************************/

class VappOpKeyLauncherShrtBar : public VfxControl
{
VFX_DECLARE_CLASS(VappOpKeyLauncherShrtBar);

// Constructor / Destructor
public:
    VappOpKeyLauncherShrtBar(){}

    VappOpKeyLauncherShrtBar(VfxBool isFocused);

// Method
public:
    void setUnFocused();

    void setIsFocused();

// Signal
public:
    VfxSignal0 m_signalIsFocused;

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

//
// This block implements the handler for the pen input and key input
//

// Override
protected:
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        SHORTCUT_BAR_WIDTH = 320,
        SHORTCUT_BAR_MARGIN = 4,
    #else
        SHORTCUT_BAR_WIDTH = 240,
        SHORTCUT_BAR_MARGIN = 3,
    #endif
        SHORTCUT_COUNT_MAX = 4
    };

// Variable
private:
	// Max only show SHORTCUT_MAX_COUNT app in Idle page
	mmi_app_package_name_struct m_shortcutPackage[SHORTCUT_COUNT_MAX];

	// Shortcut cell
	VappKeyMainmenuCell *m_shortcutCell[SHORTCUT_COUNT_MAX];

	// Current count of Shortcut in Idle page
	VfxU32 m_shortcutCount;

    VfxBool m_isFocused;

	// Current highlight index of shortcut in Idle page
	static VfxU32 m_shortcutHighlightIdx;

private:
	// Switch shortcut highlight to next or pervious
	void switchShortcutHighlight(VfxS32 inc);

	// Launche the highlight shortcut app
	void launchShortcut(void *userData);

    // Set preset shortcut
    void initShortcut();
};


/***************************************************************************** 
 * Class VappOpKeyLauncherOperatorElement
 *****************************************************************************/

class VappOpKeyLauncherOperatorElement : public VfxFrame
{
// Constructor / Destructor
public:
    // Default constructor
    VappOpKeyLauncherOperatorElement(VfxS32 simId);   

// Override
protected:
    virtual void onInit();

// Method
public:
    void updateOperatorName();

// Layout
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 320,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT = 30,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_ICON_X = 0,
        VAPP_OP_KEYLAUNCHER_OPNAME_ICON_TEXT_GAP = 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X = 28,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y = 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE = 12,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_Y = VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y + VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE + 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_SIZE = 9
    #elif defined(__MMI_MAINLCD_240X400__)
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 240,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT = 34,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_ICON_X = 0,
        VAPP_OP_KEYLAUNCHER_OPNAME_ICON_TEXT_GAP = 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X = 28,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y = 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE = 12,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_Y = VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y + VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE + 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_SIZE = 9
    #else /* __MMI_MAINLCD_240X320__ */
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 240,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT = 31,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_ICON_X = 0,
        VAPP_OP_KEYLAUNCHER_OPNAME_ICON_TEXT_GAP = 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X = 28,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y = 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE = 12,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_Y = VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y + VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE + 2,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_SIZE = 9
    #endif
    };

// Variable
private:
    VfxS32 m_simId;
    VfxImageFrame   *m_imgSim;
    VfxTextFrame    *m_textOPN;    
    VfxTextFrame    *m_textSPN;
    VfxTextFrame    *m_rightParenthesis;
    VfxS32 m_textPosX;
};


/***************************************************************************** 
 * Class VappOpKeyLauncherOperatorFrame 
 *****************************************************************************/

class VappOpKeyLauncherOperatorFrame : public VfxFrame
{
    // Constructor / Destructor
public:
    // Default constructor
    VappOpKeyLauncherOperatorFrame();   

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Layout
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 320,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT = 30,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X = 28,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE = 12
    #elif defined(__MMI_MAINLCD_240X400__)
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 240,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT = 34,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X = 28,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE = 12
    #else /* __MMI_MAINLCD_240X320__ */
        VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH = 240,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X = 3,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH = VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - (VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_X << 1),
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT = 31,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X = 28,
        VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE = 12
    #endif
    };

private:
    void initOperatorNameCell();
    void update();
    static mmi_ret refreshOpName(mmi_event_struct* event);

// Variable
private:
    VappOpKeyLauncherOperatorElement *m_operElement[MMI_SIM_TOTAL]; 

	// Used to show "Emergency call only" "Flight mode"
	VfxTextFrame *m_text;
};


/************************************************************************************************ 
 * Class VappOpKeyLauncherIdleModeText: idle mode text class used for display SAT icon and string
 ***********************************************************************************************/

class VappOpKeyLauncherIdleModeText : public VfxFrame
{
// Constructor / Destructor
public:
    VappOpKeyLauncherIdleModeText();

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
    
    static mmi_ret refreshIdleModeText(mmi_event_struct* event);
    
    void updateSAT();

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

// Layout
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH = 314,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT = 18,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH = 8,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT = VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_X = 0,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_TEXT_GAP = 8,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_X = VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_X + VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH + VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_TEXT_GAP,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH = VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH - VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_X,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT = VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE = 12,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED = 10
    #elif defined(__MMI_MAINLCD_240X400__)
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH = 234,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT = 14,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH = 8,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT = VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_X = 0,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_TEXT_GAP = 8,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_X = VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_X + VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH + VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_TEXT_GAP,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH = VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH - VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_X,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT = VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE = 12,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED = 10
    #else /* __MMI_MAINLCD_240X320__ */
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH = 234,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT = 14,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH = 8,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT = VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_X = 0,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_TEXT_GAP = 8,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_X = VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_X + VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH + VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_TEXT_GAP,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH = VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH - VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_X,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT = VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE = 12,
        VAPP_OP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED = 10
    #endif
    };

// Variable
private:
    // SAT or song name string
    VcpMarquee        *m_idleModeText;

    // SAT icon
    VfxImageFrame     *m_idleModeIcon;

    // SAT string
    VfxWString        m_idleModeStr;
};


#ifdef __MMI_OP01_WIFI__
/***************************************************************************** 
 * Class VappOp01KeyLauncherWlanSwitch: WLAN switch class
 *****************************************************************************/

class VappOp01KeyLauncherWlanSwitch : public VfxControl
{
VFX_DECLARE_CLASS(VappOp01KeyLauncherWlanSwitch);

// Constructor / Destructor
public:
    VappOp01KeyLauncherWlanSwitch(){}

    VappOp01KeyLauncherWlanSwitch(VfxBool isFocused);

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

    enum VappOP01WlanStateEnum
    {
        WLAN_SWITCH_POWER_OFF = 0,
        WLAN_SWITCH_POWER_WAITING,
        WLAN_SWITCH_POWER_ON,
        WLAN_SWITCH_CONNECT_WAITING,
        WLAN_SWITCH_CONNECTED,
        WLAN_SWITCH_TOTAL
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

// Method
public:
    void updateButton();

    void setUnFocused();

    void setIsFocused();

    static mmi_ret refreshWlanButton(mmi_event_struct* evt);

    static void wlanSwitchRsponse(void *user_data, srv_dtcnt_wlan_req_res_enum res);

// Signal
public:
    VfxSignal0 m_signalIsFocused;

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Slots
private:
    void onStartScrollInd(VfxTimer *timer);

// Variable
private:
    VfxImageFrame   *m_buttonBg;
    
    VfxImageFrame   *m_wlanIcon;

    VfxFrame        *m_IndFrame;

    VfxImageFrame   *m_switchInd[IND_NUMBER];

    VfxTimer        *m_indTimer;    // Indicator scroll timer

    VfxS32          m_scrollIndex;   // Scroll index from timer start for indicator scroll

    VfxBool         m_isFocused;

    VfxBool         m_isNeedSwitch;

    VappOP01WlanStateEnum   m_wlanStatus;   // WLAN status

// Implementation
private:
    // Set button state
    void setWlanButtonState();

    // Set WLAN switch
    void setWlanSwitch(
        VappOP01WlanSwitchEnum state   // [IN] switch
    );

    void startScrollInd();

    void switchWlan();

    VappOP01WlanStateEnum getWlanState();
};
#endif /* __MMI_OP01_WIFI__ */

#endif /* defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__) */
#endif /* VAPP_OP_LAUNCHER_KEY_HS_H */

