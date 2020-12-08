/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_screen_lock_steam.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the steam screen lock class.
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

#ifndef VAPP_SCREEN_LOCK_STEAM_H
#define VAPP_SCREEN_LOCK_STEAM_H

#include "MMI_features.h"

#ifdef __COSMOS_3D_SCREEN_LOCK__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vapp_screen_lock_base.h"

#include "vapp_screen_lock_steam_unlock_item_factory.h"
#include "vapp_screen_lock_steam_icon.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y               720
#define VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP               164
#define VAPP_STEAM_SCREEN_LOCK_EDGE_FRAME_HEIGHT         12
#define VAPP_STEAM_SCREEN_LOCK_UNLOCK_CRITERIA          100
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y               432
#define VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP               110
#define VAPP_STEAM_SCREEN_LOCK_EDGE_FRAME_HEIGHT         12
#define VAPP_STEAM_SCREEN_LOCK_UNLOCK_CRITERIA           70
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y               360
#define VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP                79
#define VAPP_STEAM_SCREEN_LOCK_EDGE_FRAME_HEIGHT         12
#define VAPP_STEAM_SCREEN_LOCK_UNLOCK_CRITERIA           70
#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y               288
#define VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP                79
#define VAPP_STEAM_SCREEN_LOCK_EDGE_FRAME_HEIGHT         12
#define VAPP_STEAM_SCREEN_LOCK_UNLOCK_CRITERIA           70
#else
#define VAPP_STEAM_SCREEN_LOCK_ICON_POS_Y               330
#define VAPP_STEAM_SCREEN_LOCK_ICON_X_GAP               105
#define VAPP_STEAM_SCREEN_LOCK_EDGE_FRAME_HEIGHT         12
#define VAPP_STEAM_SCREEN_LOCK_UNLOCK_CRITERIA           70
#endif

#define VAPP_STEAM_SCREEN_LOCK_MAX_ICON_NUM                      3
#define VAPP_STEAM_SCREEN_LOCK_ICON_INITIAL_OPACITY              0.9
#define VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME                      8
#define VAPP_SCREEN_LOCK_UNLOCK_SLIDE_ANI_DURATION      	150
#define VAPP_SCREEN_LOCK_RESTORE_LOCK_SLIDE_ANI_DURATION    300

class VappSteamScreenLockFrame;
class VappWallpaper;
class VappSteamScreenLockTime;
class VappSteamScreenLockDummyFrame;

#define VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME                8

/*****************************************************************************
 * Class VappSteamScreenLockGlowEffectFrame
 *****************************************************************************/

class VappSteamScreenLockGlowEffectFrame : public VfxImageFrame
{
    VFX_DECLARE_CLASS(VappSteamScreenLockGlowEffectFrame);

// Constructor
public:
    VappSteamScreenLockGlowEffectFrame();

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
};


/*****************************************************************************
 * Class VappSteamScreenLockWindowEdgeFrame
 *****************************************************************************/

class VappSteamScreenLockWindowEdgeFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappSteamScreenLockWindowEdgeFrame);

// Constructor
public:
    VappSteamScreenLockWindowEdgeFrame();

// Override
public:
    virtual void onInit();

// Method
public:
    void updateBlingEffectPos(VfxS32 dummyFrameOffsetY, VfxS32 unlockDistance);

// Variable
public:
    VappSteamScreenLockGlowEffectFrame *m_blingEffect;

private:
    VfxImageFrame *m_edgetFrame;
    
};


/*****************************************************************************
 * Screen Lock Steam Class
 *****************************************************************************/

/*
 * Screen Lock Steam Class
 */
class VappScreenLockSteam : public VappScreenLock
{
    VAPP_SCREEN_LOCK_DECLARE_CLASS(VappScreenLockSteam);

// Enum
private:
    // State enum
    enum VappSteamScreenLockState
    {
        STATE_NORMAL,
        STATE_UNLOCKING,
        STATE_SLIDING,
        STATE_LAST
    };

// Struct
    struct FramePropertyEffectData
    {
        VfxS32 var;
    };


// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockSteam();

// Override
public:
    virtual VappScreenLockId getId() const;

    // Get string resource ID for the name of this screen lock
    // RETURNS: length of the screen lock name
    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const;

    // Create screen lock icon.
    // RETURNS: frame
    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    );

    virtual VfxS32 getScreenshotNum() const;

    VfxFrame **createScreenshot(VfxObject *parentObj) const;

// Override
protected:
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onPageEnter();
    virtual void onPageExit();
    virtual void onSerializeView();
    virtual void onRestoreView();    
    virtual VfxBool onGetStatusBarTranslucent();
    virtual VfxResId onGetStatusBarBg();    

//Method
public:
    VfxBool isUnlocking();
    VfxBool onPreviewPenInput(VfxPenEvent &event);

private:
    void onIconDragStartHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent);
    void onIconDragHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent);
    void onIconDragEndHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent);
    void onIconDragAbortHandler(VappSteamScreenLockIcon *icon, const VfxPenEvent &penEvent);
    void onSlideDummyStopped(VfxBaseTimeline *timeline, VfxBool isCompleted);
    VfxSize getScreenSize();

    
// Implementation
public:
    static mmi_ret eventHandler(mmi_event_struct *event);

private:

    /*void onAppActive();
    void onAppInActive();*/

	// This function create unlock item by card pos
	VappSteamScreenLockIcon *createUnlockItem(
								VappScreenLockSteamUnlockItemPos pos, 
								VfxObject *parentObj);

    // This function initializes the wallpaper.
    void initWallpaper();
    
    void createWallpaper();
    void releaseWallpaper();

    // This function deinitializes the wallpaper.
    void deinitWallpaper();

    void wallpaperUpdatedHdlr();

    // handler when receiving pre key event
    mmi_ret preKeyHandler(mmi_event_struct *event);


    static vrt_render_dirty_type_enum edgeHoleFrameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum edgeFrameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum blingEffectFrameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size);

    void produceWaterDropTimerCallback(VfxTimer *sender);


// Variable
private:

    VfxBool         m_isAllowFlowWaterDrop;
    
    // Background image frame
    VappWallpaper               *m_wallpaper;

	VfxS32			m_freeFallHeight;
	VfxS32			m_freeFallTime;
	VfxS32			m_freeFallDurTime;

    // Total number of cards
    VfxS32          m_numIcons;

    VfxS32          m_numFlowWaterDrop;

    VfxS32 m_activeIconIndex;

    // produce water drop randomly from top window if user slide the window
    VfxTimer *m_timerFlowWaterDrop;
        
    VfxFrame *m_dummyFrame;

    VappSteamScreenLockWindowEdgeFrame *m_widowEdge;

    VappSteamScreenLockGlowEffectFrame *m_edgetEffectFrame;
    
    VfxS32  m_unlockDistance;

    //VfxImageFrame *statusBarBg;

    VappSteamScreenLockFrame    *m_lockFrame;
    
    // operator and time area
    VappSteamScreenLockTime     *m_timeArea;

    // The array of the cards
    VappSteamScreenLockIcon     *m_icon[3];

    // target icon
    VappSteamScreenLockIcon     *m_targetIcon;

    VfxImageFrame *m_ffectFrame[3];

    VfxS32Timeline              *m_tlSlideDummyPosY;

    VappSteamScreenLockState    m_lockState;
        
    VfxS32 totalOffsetY;

    VfxS32 m_oridownPosY;
    VfxS32 m_edgeEffectHeight;

};
#endif /* #ifdef __COSMOS_3D_SCREEN_LOCK__*/
#endif /*VAPP_SCREEN_LOCK_STEAM_H */
