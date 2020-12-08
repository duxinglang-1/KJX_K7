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
 *  vapp_launcher_robot_bar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the bars.
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

#ifndef VAPP_LAUNCHER_ROBOT_BAR_H
#define VAPP_LAUNCHER_ROBOT_BAR_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_robot_def.h"


/*****************************************************************************
 * Bar
 *****************************************************************************/

class VappLauncherRobotBar : public VfxControl
{
public:
    VappLauncherRobotBar();

public:
    VfxSignal1 <VappLauncherRobotBar *> m_signalFoldingChanged;

public:
    void fold(
        VfxBool isAnimatable = VFX_TRUE
    );

    void unfold(
        VfxBool isAnimatable = VFX_TRUE
    );

    VfxBool isFolded();

protected:
    virtual void onInit();
    virtual void onDeinit();

protected:
    virtual void onFold();
    virtual void onUnfold();

private:
    enum
    {
        AUTO_ANIMATE_TIME = 250
    };

private:
    VfxBool m_isFolded;
    VfxTimer *m_timerFolding;

private:
    void prepareSignal(
        VfxBool isAnimatable
    );

    void onTimerFolded(
        VfxTimer *timer
    );
};


/*****************************************************************************
 * Toolbar
 *****************************************************************************/

class VappLauncherRobotToolbar : public VappLauncherRobotBar
{
    VFX_DECLARE_CLASS(VappLauncherRobotToolbar);

public:
    enum ButtonEnum
    {
        BUTTON_ADD_WIDGET,
        BUTTON_ADD_SHORTCUT,
        BUTTON_SET_WALLPAPER,
        BUTTON_TOTAL
    };

public:
    class ButtonEntry : public VfxBase
    {
    public:
        ButtonEntry(ButtonEnum id, VfxResId text, VfxResId icon) :
            m_id(id),
            m_text(text),
            m_icon(icon)
        {
            // Do nothing.
        }

    public:
        ButtonEnum m_id;
        VfxResId m_text;
        VfxResId m_icon;
    };

public:
    VappLauncherRobotToolbar();

// Signal
public:
    // This signal is emitted when the user clicks the specified button.
    VfxSignal2 <
        VappLauncherRobotToolbar *,  // [IN] Toolbar
        ButtonEnum          // [IN] Button enum
    > m_signalExecute;

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onFold();

    virtual void onUnfold();

// Method
private:
    VfxSize getImageResSize(const VfxResId imageId) const;

    VfxPoint getButtonPos(VfxS32 index);

private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        SHORCUT_BG_WIDTH = 277,
        HALO_WIDTH = 96,
        HALO_HEIGHT = 96
    #elif defined(__MMI_MAINLCD_320X480__)
        SHORCUT_BG_WIDTH = 211,
        HALO_WIDTH = 76,
        HALO_HEIGHT = 76
    #elif defined(__MMI_MAINLCD_240X400__)
        SHORCUT_BG_WIDTH = 172,
        HALO_WIDTH = 70,
        HALO_HEIGHT = 70
    #else /* defined(__MMI_MAINLCD_240X320__) */
        SHORCUT_BG_WIDTH = 172,
        HALO_WIDTH = 70,
        HALO_HEIGHT = 70
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

private:
    VfxImageFrame *m_shortcutBg;
    VcpImageButton *m_button[BUTTON_TOTAL];

    static const ButtonEntry s_buttonTbl[];

private:
    void onButtonClicked(
        VfxObject *obj,
        VfxId id
    );

    VfxSize getSeparateLineSize();

    VfxRect getSeparateLineRect(
        VfxS32 index,
        const VfxSize &parentSize
    );

    VfxRect getButtonRect(
        VfxS32 index,
        const VfxSize &parentSize
    );
};


/*****************************************************************************
 * Android Shortcut Bar Class
 *****************************************************************************/

class VappLauncherRobotShortcutBar : public VappLauncherRobotBar
{
    VFX_DECLARE_CLASS(VappLauncherRobotShortcutBar); 

// Enum
public:
    enum ButtonEnum
    {
        BUTTON_DIALER,
        BUTTON_MAINMENU,
    #ifdef __MMI_GB_WINGUO__
        BUTTON_WINGUO,   
    #else
        BUTTON_BROWSER,
    #endif
        BUTTON_TOTAL
    };
    
private:
    enum
    {
        SHORTCUT_NUM = 4,
        SEPARATOR_NUM = SHORTCUT_NUM - 1
    };

// Class
public:
    class ButtonEntry : public VfxBase
    {
    public:
        ButtonEntry(ButtonEnum id, VfxResId icon, VfxResId iconHighLight) :
            m_id(id),
            m_icon(icon),
            m_iconHighLight(iconHighLight)
        {
            // Do nothing.
        }

    public:
        ButtonEnum m_id;
        VfxResId m_icon;
        VfxResId m_iconHighLight;
    };

// Constructor
public:
    VappLauncherRobotShortcutBar();

// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onFold();

    virtual void onUnfold();

    virtual VfxBool onPenInput(
        VfxPenEvent &event);

    virtual void onDraw(
        VfxDrawContext &dc
    );

// Method
public:
    void setIndex(VfxS32 idx);

    VfxS32 getIndex(void) const;

    VfxBool isIndicatorHitted(VfxPenEvent &event, VfxS32 &direction);

    void hideIndicator(VfxBool isHide);

private:
    void onButtonTapped(VfxObject *button, VfxId id);

    VfxPoint getButtonPos(VfxS32 index);

    VfxSize getImageResSize(const VfxResId imageId) const;

    VfxPoint getDotPos(VfxS32 indicatorIndex, VfxS32 sequenceIndex) const;

    VfxPoint getMidPosBySequenceIndex(VfxS32 index, VfxSize totalSize, VfxS32 totalNum) const;

    void layoutIndicator() const;

    void setIndicatorHighlight(VfxBool on, VfxS32 direction);

private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        SHORCUT_BG_WIDTH = 277,
        HALO_WIDTH = 96,
        HALO_HEIGHT = 96
    #elif defined(__MMI_MAINLCD_320X480__)
        SHORCUT_BG_WIDTH = 211,
        HALO_WIDTH = 76,
        HALO_HEIGHT = 76
    #elif defined(__MMI_MAINLCD_240X400__)
        SHORCUT_BG_WIDTH = 172,
        HALO_WIDTH = 70,
        HALO_HEIGHT = 70
    #else /* defined(__MMI_MAINLCD_240X320__) */
        SHORCUT_BG_WIDTH = 172,
        HALO_WIDTH = 70,
        HALO_HEIGHT = 70
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
public:
    // para: press which side of indicator
    VfxSignal1 <VfxS32> m_signalIndicatorClicked;
    
    VfxSignal0 m_signalIndicatorLongPressed;

    // This signal is emitted when the user clicks the specified button.
    VfxSignal1 <
        ButtonEnum          // [IN] Button enum
    > m_signalExecute;
    
private:
    // shortcut
    static const ButtonEntry s_buttonTbl[];
    VfxImageFrame *m_shortcutBg;
    VcpImageButton *m_button[BUTTON_TOTAL];

    // Indicator
    VfxS32 m_index;
    VfxImageFrame *m_dot[VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM];
    VfxImageFrame *m_halo[VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM];

    VfxBool indicatorHitted;
};


/*****************************************************************************
 * Trash Can
 *****************************************************************************/

class VappLauncherRobotTrashCanBar : public VappLauncherRobotBar
{
    VFX_DECLARE_CLASS(VappLauncherRobotTrashCanBar);

public:
    VappLauncherRobotTrashCanBar();

// Method
public:
    void setAlertDeleteWidget(VfxBool isAlert);
    
// Override
protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onFold();

    virtual void onUnfold();

private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        BG_WIDTH = 277,
    #elif defined(__MMI_MAINLCD_320X480__)
        BG_WIDTH = 211,
    #elif defined(__MMI_MAINLCD_240X400__)
        BG_WIDTH = 172,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        BG_WIDTH = 172,
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    VfxImageFrame *m_trashCanBgN;
    VfxImageFrame *m_trashCanBgH;
    VfxImageFrame *m_trashIconN;
    VfxImageFrame *m_trashIconH;

};

#endif /* VAPP_LAUNCHER_ROBOT_BAR_H */

