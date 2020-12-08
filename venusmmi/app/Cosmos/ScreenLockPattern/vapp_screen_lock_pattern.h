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
 *  vapp_screen_lock_pattern.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  pattern screen lock class.
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

#ifndef __VAPP_SCREEN_LOCK_PATTERN_H__
#define __VAPP_SCREEN_LOCK_PATTERN_H__

#include "MMI_features.h"


#ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__
/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_page.h"
#include "vapp_screen_lock_base.h"
#include "vapp_screen_lock_pattern_time.h"
#include "vapp_screen_lock_pattern_frame.h"
#include "vapp_wallpaper.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

#define VAPP_SCREEN_LOCK_PATTERN_BACKLIGHT_OFF_TIME                8

class VappScreenLockPatternSettingPage;
/*
 * Screen Pattern Class
 */
class VappScreenLockPattern : public VappScreenLock
{
    VAPP_SCREEN_LOCK_DECLARE_CLASS(VappScreenLockPattern);

public:
    // Default constructor
    VappScreenLockPattern();

    virtual VappScreenLockId getId() const;

// Override
protected:
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onPageEnter();
    virtual void onPageExit();
    virtual void onSerializeView();
    virtual void onRestoreView();

    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const;

    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    );

    virtual VfxS32 getScreenshotNum() const;

    virtual VfxFrame **createScreenshot(
        VfxObject *parentObj
    ) const;

    virtual VfxBool onGetConfigurationSupported() const;
    virtual void onCreateConfiguration();

    virtual VfxResId onGetStatusBarBg();
    virtual VfxBool onGetStatusBarTranslucent();

private:
    void initWallpaper();
    void createWallpaper();
    void releaseWallpaper();
    void deinitWallpaper();
    void wallpaperUpdatedHdlr();

    void onExitSetting(VappScreenLockPatternSettingPage* sender, VfxBool result);
    void onPattern(VfxU8* pattern);
    static mmi_ret eventHandler(mmi_event_struct *event);
    void onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop);

private:

    VappWallpaper *m_wallpaper;
    VappScreenLockPatternTime *m_time;
    VappScreenLockPatternFrame *m_frame;
    VappScreenLockPatternSettingPage *m_setting;
    VfxU8 m_pattern[VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER];
};

class VappScreenLockPatternSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappScreenLockPatternSettingPage);

    enum SETTING_STATE_ENUM
    {
        SETTING_STATE_INITED = 0,
        SETTING_STATE_PATTERN_SET_DONE = 1,
        SETTING_STATE_CONFIRM = 2
    };

    enum CLICK_RESULT_ENUM
    {
        CLICK_RESULT_NONE = 0,
        CLICK_RESULT_OK = 1,
        CLICK_RESULT_CANCEL = 2,
    };

public:
    VappScreenLockPatternSettingPage();

    VfxSignal2<VappScreenLockPatternSettingPage *, VfxBool> m_signalExit;

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);

private:
    void onToolBarClick(VfxObject* sender, VfxId id);
    void onSetPattern(VfxU8 *pattern);
    void onSavePattern();
    void onExitSettingPage(VfxObject* sender, VfxBool in, VfxS32 direction);

    VfxBool m_isExitApp;
    VappScreenLockPatternFrame *m_frame;
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_buttomBar;
    SETTING_STATE_ENUM m_state;
    CLICK_RESULT_ENUM m_res;
    VfxU8 m_currPattern[VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER];
};

#endif // #ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

#endif /* __VAPP_SCREEN_LOCK_PATTERN_H__ */
