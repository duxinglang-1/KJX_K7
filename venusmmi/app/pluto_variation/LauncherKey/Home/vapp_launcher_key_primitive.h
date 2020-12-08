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
 *  vapp_launcher_key_primitive.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the tool bar, ....
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

#ifndef VAPP_KEYLAUNCHER_PRIMITIVE_H
#define VAPP_KEYLAUNCHER_PRIMITIVE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_key_mainmenu_builder.h"
#include "vapp_launcher_key_clock.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"
#include "NwNameSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

// layout

#if defined(__MMI_MAINLCD_320X480__)
	#define VAPP_KEYLAUNCHER_OP_FRAME_X                 (3)
    #define VAPP_KEYLAUNCHER_OP_FRAME_Y                 (150)
	
    #define VAPP_KEYLAUNCHER_OP_FRAME_WIDTH             (LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_OP_FRAME_X)
    #define VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT            (32-2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_ICON_X            (0)

    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_X       (28)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y       (2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE    (12)
    
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_Y       (VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y + VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE + 2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_SIZE    (9)
    
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X          (3)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_Y          (275)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH      (LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT     (17)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH       (8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X           (0)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X           (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X + VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH + 8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH       (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH - VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE        (12)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED    (10)

	#define VAPP_KEYLAUNCHER_SEARCH_BAR_X              (36)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A            (288) // Has shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_B            (389) // Has not shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH          (246)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT         (54)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_X         (18)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_Y         (15)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_X       (104-36)  // Middle Pos X  
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_SIZE    (19)

	#define VAPP_KEYLAUNCHER_SHORTCUT_Y                (VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A + VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT + 5)

#elif defined(__MMI_MAINLCD_240X400__)
	#define VAPP_KEYLAUNCHER_OP_FRAME_X                 (3)
    #define VAPP_KEYLAUNCHER_OP_FRAME_Y                 (96)

    #define VAPP_KEYLAUNCHER_OP_FRAME_WIDTH             (LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_OP_FRAME_X)
    #define VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT            (34)
    #define VAPP_KEYLAUNCHER_OP_FRAME_ICON_X            (0)

    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_X       (28)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y       (2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE    (12)
    
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_Y       (VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y + VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE + 2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_SIZE    (9)

    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X          (3)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_Y          (232)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH      (LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT     (14)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH       (8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X           (0)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X           (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X + VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH + 8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH       (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH - VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE        (12)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED    (10)   

	#define VAPP_KEYLAUNCHER_SEARCH_BAR_X              (28)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A            (256) // Has shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_B            (332) // Has not shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH          (186)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT         (41)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_X         (15)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_Y         (8)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_X       (75-28)  // Middle Pos X  
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_SIZE    (13)

	#define VAPP_KEYLAUNCHER_SHORTCUT_Y                (VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A + VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT + 5)//(303)

#elif defined(__MMI_MAINLCD_240X320__)
	#define VAPP_KEYLAUNCHER_OP_FRAME_X                 (3)
    #define VAPP_KEYLAUNCHER_OP_FRAME_Y                 (19+5)
    
    #define VAPP_KEYLAUNCHER_OP_FRAME_WIDTH             (LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_OP_FRAME_X)
    #define VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT            (31)
    #define VAPP_KEYLAUNCHER_OP_FRAME_ICON_X            (0)

    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_X       (28)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y       (2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE    (12)
    
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_Y       (VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y + VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE + 2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_SIZE    (9)

    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X          (3)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_Y          (155+5)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH      (LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT     (14)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH       (8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X           (0)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X           (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X + VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH + 8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH       (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH - VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE        (12)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED    (10)   

	#define VAPP_KEYLAUNCHER_SEARCH_BAR_X              (28)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A            (175) // Has shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_B            (251) // Has not shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH          (186)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT         (41)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_X         (15)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_Y         (8)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_X       (75-28)  // Middle Pos X  
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_SIZE    (13)

	#define VAPP_KEYLAUNCHER_SHORTCUT_Y                (VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A + VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT + 5)//(223)

#else // defined(__MMI_MAINLCD_320X240__)
	#define VAPP_KEYLAUNCHER_OP_FRAME_X                 (3)
    #define VAPP_KEYLAUNCHER_OP_FRAME_Y                 (27)
    
    #define VAPP_KEYLAUNCHER_OP_FRAME_WIDTH             (LCD_WIDTH / 2 - 2 * VAPP_KEYLAUNCHER_OP_FRAME_X)
    #define VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT            (31)
    #define VAPP_KEYLAUNCHER_OP_FRAME_ICON_X            (0)

    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_X       (20)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y       (2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE    (12)
    
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_Y       (VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y + VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE + 2)
    #define VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_SIZE    (9)

    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X          (3)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_Y          (92)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH      (LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT     (14)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH       (8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X           (0)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X           (VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X + VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH + 8)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH       (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH - VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT      (VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE        (12)
    #define VAPP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED    (10)    

	#define VAPP_KEYLAUNCHER_SEARCH_BAR_X              (63)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A            (108) // Has shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_Y_B            (174) // Has not shortcut
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH          (184)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT         (35)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_X         (16)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_Y         (6)
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_X       (116-63)  // Middle Pos X  
	#define VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_SIZE    (13)

	#define VAPP_KEYLAUNCHER_SHORTCUT_Y                (VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A + VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT + 5)//(146)
    
#endif
	

/*****************************************************************************
 * Toolbar
 *****************************************************************************/

class VappKeyLauncherToolbar : public VfxFrame
{
//    VFX_DECLARE_CLASS(VappKeyLauncherToolbar);

public:
    VappKeyLauncherToolbar();

public:
	// Button id enum
	enum ButtonId
	{
		MAINMENU_IN_IDLE,
		WIDGET_IN_IDLE,
		MAINMENU_IN_WIDGET,
		IDLE_IN_WIDGET,
	};

	// Toolbar style
	enum ToolbarStyle
	{
		STYLE_IDLE,
		STYLE_WIDGETS,
	};
	
// Signal
public:
    // This signal is emitted when the user clicks the specified button.
    VfxSignal3 <
        VfxObject *,   // [IN] Toolbar
        VfxId,          // [IN] Button id
        VcpSoftkeyEventEnum
    > m_signalExecute;

// Override
protected:
    virtual void onInit();

public:
	virtual void setHidden(VfxBool value);
	
// Implement
private:
    VcpSoftkey              *m_softkeybar;

	ToolbarStyle             m_style;

public:
	void setStyle(ToolbarStyle style);

private:
    void onEventLsk(VcpSoftkeyEventEnum event_type);

	void onEventRsk(VcpSoftkeyEventEnum event_type);

    void onPostExecute(
        VfxId id, VcpSoftkeyEventEnum event
    );
};


/*****************************************************************************
 * Idle page, Which is one page of Home
 *****************************************************************************/
class VappKeyLauncherOperatorFrame;
class VappKeyLauncherShortcut;
class VappKeyLauncherIdleModeText;


class VappKeyLauncherIdlePage : public VfxControl
{
VFX_DECLARE_CLASS(VappKeyLauncherIdlePage);

// Constructor / Destructor
public:
    // Default constructor.
    VappKeyLauncherIdlePage();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

public:
	// This function will set if Hidden and if Focused to receive Key event
	virtual void setHidden(VfxBool value);


//
// This block implements the shortcut.
//

// Variable
private:
	// Shortcut control
	VappKeyLauncherShortcut *m_shortcut;

// Implement
private:
	// This function is to create and draw all shortcut
	void createShortcutView();

};


/***************************************************************************** 
 * Class VappKeyLauncherShortcut
 *****************************************************************************/

class VappKeyLauncherShortcut : public VfxControl
{
//VFX_DECLARE_CLASS(VappKeyLauncherShortcut);

// Constructor / Destructor
public:
    // Default constructor.
    VappKeyLauncherShortcut();

//
// This block implements the handler for the pen input and key input
//

// Override
protected:
	// Please refer to VfxControl.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    // Please refer to VfxControl.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );


//
// This block implements the operator name and service name.
//

// Declaration
private:
    enum
    {
	#if defined(__MMI_MAINLCD_320X240__)
        SHORTCUT_MAX_COUNT = 5,
	#else
		SHORTCUT_MAX_COUNT = 4,
	#endif
    };

// Variable
private:
	// Max only show SHORTCUT_MAX_COUNT app in Idle page
	mmi_app_package_name_struct m_shortcutPackage[SHORTCUT_MAX_COUNT];

	// Shortcut cell
	VappKeyMainmenuCell *m_shortcutCell[SHORTCUT_MAX_COUNT];

	// Current count of Shortcut in Idle page, user can set in Setting app
	VfxU32 m_shortcutCount;

	// Current highlight index of shortcut in Idle page, range [0, SHORTCUT_MAX_COUNT-1]
	static VfxU32 m_shortcutHighlightIdx;

// Implement
public:
	// This function is get data from setting, then create and draw all shortcut
	void createView();

private:
	// Check if current index shortcut is pre installed app
	VfxBool isShortcutPreInstalled(VfxU32 index);

	// Switch shortcut highlight to next or pervious
	void switchShortcutHighlight(VfxS32 inc);

	// Launche the highlight shortcut app
	void launchShortcut(void *userData);
};


/***************************************************************************** 
 * Class VappKeyLauncherOperatorElement
 *****************************************************************************/

class VappKeyLauncherOperatorElement : public VfxFrame
{
    // Constructor / Destructor
public:
    // Default constructor
    VappKeyLauncherOperatorElement(VfxS32 simId);   

// Override
protected:
    virtual void onInit();

// Method
public:
    void updateOperatorName(VfxS32 maxWidth);

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
 * Class VappKeyLauncherOperatorFrame 
 *****************************************************************************/

class VappKeyLauncherOperatorFrame : public VfxFrame
{
    // Constructor / Destructor
public:
    // Default constructor
    VappKeyLauncherOperatorFrame();   

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void initOperatorNameCell();
    void update(VfxS32 maxWidth);
    static mmi_ret eventHandler(mmi_event_struct *event);

// Variable
private:
    VappKeyLauncherOperatorElement *m_operElement[MMI_SIM_TOTAL]; 

	// Used to show "Emergency call only" "Flight mode"
	VfxTextFrame *m_text;
};


/********************************************************************************************* 
 * Class VappKeyLauncherIdleModeText: idle mode text class used for display SAT icon
 ********************************************************************************************/

class VappKeyLauncherIdleModeText : public VfxFrame
{
// Constructor / Destructor
public:
    VappKeyLauncherIdleModeText();

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
    
    static mmi_ret eventHandler(mmi_event_struct *event);
    
    void updateSAT();

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
};


/***************************************************************************** 
 * Class VappKeyLauncherSearchBar 
 *****************************************************************************/
#ifdef __MMI_SEARCH_WEB__

class VappKeyLauncherSearchBar : public VfxControl
{
VFX_DECLARE_CLASS(VappKeyLauncherSearchBar);

// Constructor / Destructor
public:
    // Default constructor.
    VappKeyLauncherSearchBar();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

	VfxBool onPenInput(VfxPenEvent &event);
};
#endif /* __MMI_SEARCH_WEB__ */

#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */
#endif /* VAPP_KEYLAUNCHER_PRIMITIVE_H */



