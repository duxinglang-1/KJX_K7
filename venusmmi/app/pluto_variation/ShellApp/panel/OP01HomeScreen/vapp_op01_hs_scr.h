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
 *  vapp_op01_hs_scr.h
 *
 * Project:
 * --------
 *  Venus OP01 Homescreen
 *
 * Description:
 * ------------
 *  OP01 Homescreen
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_OP01_HS_SCR_H__
#define __VAPP_OP01_HS_SCR_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vdat_include.h"
#include "vapp_shell_panel.h"
#include "vapp_op01_hs_cp.h"

class VappWallpaper;

/***************************************************************************** 
 * Class VappOp01HsScr
 *****************************************************************************/

/*
 * This class implements the Venus home screen.
 *
 * EXAMPLE
 * <code>
 *  static VappOp01HsScr *category;
 *
 *  void mmi_entry_screen(void)
 *  {
 *      EntryNewScreen(SCREEN_ID, mmi_entry_screen, mmi_exit_screen, NULL);
 *
 *      VcpAppScr::initalize();
 *
 *      VFX_OBJ_CREATE_EX(
 *          category,
 *          VappOp01HsScr, 
 *          VcpAppScr::getContext(), 
 *          (setting, history));    // constructor parameters
 *  }
 *
 *
 *  void mmi_exit_screen(void)
 *  {
 *      VFX_OBJ_CLOSE(category);
 *
 *      VcpAppScr::deinitalize();
 *  }
 * </code>
 */
class VappOp01HsScr : public VappShellPanel
{
    VAPP_SHELL_PANEL_CREATE(VappOp01HsScr, VFX_FALSE);

// Constructor / Destructor
public:
    // Construct the home screen with the specified history.
    VappOp01HsScr();

// Method
public:
    void updateWlanButton();

    void updateHintBox(VfxS32 id, VfxS32 num);

    void suspendLiveWallpaper();

    void resumeLiveWallpaper();

#ifdef __MMI_OP01_DCD_V30__
    void updateDCDNewsImgArea();

    void updateDCDNewsContentArea();

    void updateDCDWhetherArea();
#endif

// Override
protected:
    // Application can do component initalization here. Don't 
    // create components here. In this stage, it is only supposed to
    // do some component initialization, such as send message to other
    // task to gather some data.
    virtual void onInit();

    // Application can do component deinitalization here.
    virtual void onDeinit();
    
    // Application can create components shown in the switch wheelmenu
    virtual void onInitView();
    
    // Applicaiton can close components which are created in onInitView stage
    virtual void onDeinitView();
    
    // Application can create components which waste lots of resources here.
    virtual void onEnterView();
    
    // exit view. Application can release those resources which is obtained in onEnterView
    virtual void onExitView(
        ShellExitCauseEnum cause
    );

    virtual void onSwitchBegin(VfxBool isSwitchOut);

    virtual void onSwitchEnd();

    virtual VfxBool onPenInput(VfxPenEvent &event);

// Slots
protected:
    // This function is the event handler when network name changes.
    void onNetworkNameChanged(
        VdatNetworkInfo *networkSrv // [IN] Network info service instance
    );

    // This function is the event handler when network status changes.
    void onNetworkStatusChanged(
        VdatNetworkInfo *networkSrv // [IN] Network info service instance
    );

    // This function is the event handler when the idle mode text changes.
    void onIdleModeTextChanged(
        VdatNetworkInfo *networkSrv // [IN] Network info service instance
    );

    // This function is the event handler when the idle mode icon changes.
    void onIdleModeIconChanged(
        VdatNetworkInfo *networkSrv // [IN] Network info service instance
    );

// Declaration
private:
    // UI component layout of the Venus home screen.
    enum VappOp01HsLayoutEnum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        TOP_MARGIN = 7,
        LEFT_MARGIN = 8,
        RIGHT_MARGIN = LEFT_MARGIN,
        LINE_GAP = 8,
        HINT_BOX_POS_Y = 196,
        BUTTON_POS_Y = HINT_BOX_POS_Y,
        SHCT_BAR_POS_Y = 355,
        DCD_BAR_POS_Y = 267,
        DATE_TIME_POS_Y = 58,
        IDLE_MODE_TEXT_POS_Y = 200
    #else /* defined(__MMI_MAINLCD_320X480__) */
        TOP_MARGIN = 6,
        LEFT_MARGIN = 7,
        RIGHT_MARGIN = LEFT_MARGIN,
        LINE_GAP = 4,
        HINT_BOX_POS_Y = 149,
        BUTTON_POS_Y = HINT_BOX_POS_Y,
    #if defined(__MMI_MAINLCD_240X320__)
        SHCT_BAR_POS_Y = 213,
        DCD_BAR_POS_Y = 151,
    #elif defined(__MMI_MAINLCD_240X400__)
        SHCT_BAR_POS_Y = 293,
        DCD_BAR_POS_Y = 218,
    #endif
        DATE_TIME_POS_Y = 50,
        IDLE_MODE_TEXT_POS_Y = 155
    #endif /* defined(__MMI_MAINLCD_320X480__) */
    };

    enum
    {
        TYPE_SMS,
        TYPE_MMS,
        TYPE_CALL,
        TYPE_TOTAL
    };

    // Wallpaper setting confirm enum
    enum
    {
        WALLPAPER_LIVE,
        WALLPAPER_GALLERY,
        WALLPAPER_FMGR,
        WALLPAPER_CANCEL,
        WALLPAPER_TOTAL
    };

    // This structure saves the history of the Venus home screen.
    struct VappOp01HsHistory
    {
        // View mode, include sidebar view mode and expanded view mode
        VfxS32 viewMode;
 
        // If shortcut panel is open, it is VFX_TRUE; otherwise, it is VFX_FALSE.
        VfxS32 viewState;

        // The vertical position of the sidebar
        VfxS32 viewItemHilitePos;

        // The horizontal highlight position of shortcut bar.
        VfxS32 shortcutHilitePos;
    };

    // This structure saves the setting of the Venus home screen.
    struct VappOp01HsSetting
    {
        // If alarm is active, it is VFX_TRUE; otherwise, it is VFX_FALSE.
        VfxBool isAlarmActive;

        // If time number is 0~23, it is VFX_TRUE; otherwise, it is VFX_FALSE.
        VfxBool isFullNumberTime;

        // If clock size is large, it is VFX_TRUE; otherwise, it is VFX_FALSE.
        VfxBool isLargeClock;   
    };

// Variable
private:
    // This block declares the UI component of the App category.

    // Background image frame
    VappWallpaper    *m_wallpaper;

    // Virtual control to let homescreen receive pen event
    VfxControl  *m_virConrol;

    // Network info
    VappOp01HsNwInfo    *m_networkInfo;

    // Idle mode text
    VappOp01HsIdleModeText *m_idleModeText;

    // Date and time
    VappOp01HsDateTime  *m_dateTime;

    // Hint box for Call/SMS/MMS 
    VappOp01HsHintBox  *m_hintBox[TYPE_TOTAL];

    // Hint number
    VfxS32              m_hintNum;

    // Search button
    VappOp01HsSearchButton *m_searchButton;

    // WLAN button
    VappOp01HsWlanSwitch    *m_wlanButton;

    // Shortcut bat
    VappOp01HsShctBar   *m_shctBar;

#ifdef __MMI_OP01_DCD_V30__
    // DCD bar
    VappOp01HsDCDBar    *m_dcdBar;
#endif

// Variable
private:
    // This block declares the variable related to the wallpaper.

    // wallpaper will resume after bootup Initiation (1 sec)
    static VfxBool           s_bootupInit;
    
    // Timer to resume wallpaper after bootup initiation
    VfxTimer               *m_timerResumeWallpaper;

// Variable
private:
    // This block declares the variables related to the pen event handler.

    // If long-press is workable for the wallpaper setting option menu.
    VfxBool                 m_longPressEnable;

    // If the pen down event is received.
    VfxBool                 m_isRecvPenDown;

    // The max. allowable offset that the long-press event can still work.
    static const VfxS32     s_penOffsetThreshold;

// Implementation
private:
    // This block implements the functions to init / deinit components.

    // This function initializes the wallpaper.
    void initWallpaper();

    // This function deinitializes the wallpaper.
    void deinitWallpaper();

    // This function initializes network info.
    void initNetworkInfo();

    // This function deinitializes network info.
    void deinitNetworkInfo();

    // This function initializes idle mode text.
    void initIdleModeText();

    // This function deinitializes idle mode text.
    void deinitIdleModeText();

    // This function initializes date and time.
    void initDateTime();

    // This function deinitializes date and time.
    void deinitDateTime();

    // This function initializes hint box.
    void initHintBox();

    // This function deinitializes hint box.
    void deinitHintBox();

    // This function initializes search button.
    void initSearchButton();

    // This function deinitializes search button.
    void deinitSearchButton();

    // This function initializes WLAN button.
    void initWlanButton();

    // This function deinitializes WLAN button.
    void deinitWlanButton();

    // This function initializes shortcut bar.
    void initShctBar();

    // This function deinitializes shortcut bar.
    void deinitShctBar();

#ifdef __MMI_OP01_DCD_V30__
    // This function initializes DCD bar.
    void initDCDBar();

    // This function deinitializes DCD bar.
    void deinitDCDBar();
#endif

// Implementation
private:
    // This block implements the functions related to the home screen wallpaper.

    // This function is used to resume wallpaper when timeout after bootup
    // only callback once
    void onResumeWallpaper(VfxTimer *timer);

#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__)
// Implementation
private:
    // This block implements wallpaper setting confirm popup after long press HS

    // This function show wallpaper setting popup confirm
    void showWallpaperConfirm(void);

    // This function determine and excute callback function
    void onCommandPopCallback(VfxObject *obj, VfxId id);
#endif /* defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) */

// Implementation
private:
    // This block implements some misc. functions for the App category.

    // This function gets the screen size.
    // RETURNS: screen size
    VfxSize getScreenSize();
};


#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
#endif /* __VAPP_OP01_HS_SCR_H__ */

