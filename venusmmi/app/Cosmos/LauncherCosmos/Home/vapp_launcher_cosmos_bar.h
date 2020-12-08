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
 *  vapp_launcher_cosmos_bar.h
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

#ifndef VAPP_LAUNCHER_COSMOS_BAR_H
#define VAPP_LAUNCHER_COSMOS_BAR_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_cosmos_def.h"
#include "vapp_launcher_cosmos_mm_shortcut_bar.h"


/*****************************************************************************
 * Bar
 *****************************************************************************/

class VappLauncherCosmosBar : public VfxControl
{
public:
    VappLauncherCosmosBar();

public:
    VfxSignal1 <VappLauncherCosmosBar *> m_signalFoldingChanged;

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
 * Page Indicator Class
 *****************************************************************************/

class VappLauncherCosmosPageIndicator : public VappLauncherCosmosBar
{
    VFX_DECLARE_CLASS(VappLauncherCosmosPageIndicator);

    struct VappLauncherCosmosPageIndicatorHResIdStruct
    {
        VfxResId resId;
    };

public:
    VappLauncherCosmosPageIndicator();

public:
    VfxSignal1 <VappLauncherCosmosPageIndicator *> m_signalClicked;

public:
    void setIndex(
        VfxS32 idx
    );

    VfxS32 getIndex(void) const;

    VfxBool isHitted(
        VfxPenEvent &event
    );

    void setHaloEffect(
        VfxBool isOn
    );

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

protected:
    virtual void onFold();

    virtual void onUnfold();

private:
    enum
    {
        //
        // Height = Top-Border-Width - Status-Icon-Bar-Height
        //
    #if defined(__MMI_MAINLCD_480X800__)
        POS_Y = 38,
        HEIGHT = 50,
        LEFT_GAP = 21,
        RIGHT_GAP = 21,
        GAP = 0,
        HITTABLE_HEIGHT = HEIGHT + 20,
        HALO_MIN_WIDTH = 27,
        HALO_MIN_HEIGHT = 27,
        HALO_MAX_WIDTH = 39,
        HALO_MAX_HEIGHT = 39,
        BREATH_AREA_POS_Y = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_TOP_WIDTH,
        BREATH_AREA_HEIGHT = VAPP_LAUNCHER_COSMOS_DESKTOP_VALID_HEIGHT
    #elif defined(__MMI_MAINLCD_320X480__)
        POS_Y = 24,
        HEIGHT = 37,
        LEFT_GAP = 12,
        RIGHT_GAP = 12,
        GAP = 0,
        HITTABLE_HEIGHT = HEIGHT + 14,
        HALO_MIN_WIDTH = 17,
        HALO_MIN_HEIGHT = 17,
        HALO_MAX_WIDTH = 25,
        HALO_MAX_HEIGHT = 25,
        BREATH_AREA_POS_Y = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_TOP_WIDTH,
        BREATH_AREA_HEIGHT = VAPP_LAUNCHER_COSMOS_DESKTOP_VALID_HEIGHT
    #elif defined(__MMI_MAINLCD_240X400__)
        POS_Y = 24,
        HEIGHT = 27,
        LEFT_GAP = 9,
        RIGHT_GAP = 9,
        GAP = 0,
        HITTABLE_HEIGHT = HEIGHT + 10,
        HALO_MIN_WIDTH = 15,
        HALO_MIN_HEIGHT = 15,
        HALO_MAX_WIDTH = 21,
        HALO_MAX_HEIGHT = 21,
        BREATH_AREA_POS_Y = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_TOP_WIDTH,
        BREATH_AREA_HEIGHT = VAPP_LAUNCHER_COSMOS_DESKTOP_VALID_HEIGHT
    #else /* defined(__MMI_MAINLCD_240X320__) */
        POS_Y = 24,
        HEIGHT = 27,
        LEFT_GAP = 9,
        RIGHT_GAP = 9,
        GAP = 0,
        HITTABLE_HEIGHT = HEIGHT + 8,
        HALO_MIN_WIDTH = 15,
        HALO_MIN_HEIGHT = 15,
        HALO_MAX_WIDTH = 21,
        HALO_MAX_HEIGHT = 21,
        BREATH_AREA_POS_Y = VAPP_LAUNCHER_COSMOS_DESKTOP_OUTER_BORDER_TOP_WIDTH,
        BREATH_AREA_HEIGHT = VAPP_LAUNCHER_COSMOS_DESKTOP_VALID_HEIGHT
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    VfxS32 m_index;
    
    // used m_selectedDot to represent seleted page dot 
    // instead of change image resource on m_dot
    // then these frame will always in cache, or it will dirty when change image source
    // besides, do not hide m_easeOutDot, should use setOpacity
    VfxImageFrame *m_easeOutDot;
    VfxImageFrame *m_selectedDot;
    VfxImageFrame *m_dot[VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM];
    VfxImageFrame *m_halo[VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM];

    static const VfxSize s_haloMinSize;
    static const VfxSize s_haloMaxSize;

    // Table for the indicator Highlight res id mapping
    static const VappLauncherCosmosPageIndicatorHResIdStruct s_indicatorHResIdTbl[];

private:
    VfxSize getDotSize() const;

    VfxPoint getDotPos(
        VfxS32 idx
    ) const;

    void getTransform(
        VfxSize from,
        VfxSize to,
        VfxTransform &trans
    ) const;

    void getTransform(
        VfxResId from,
        VfxResId to,
        VfxTransform &trans
    ) const;
};


/*****************************************************************************
 * Shortcut Bar Class
 *****************************************************************************/

class VappLauncherCosmosShortcutBar : public VappLauncherCosmosBar
{
    VFX_DECLARE_CLASS(VappLauncherCosmosShortcutBar);

public:
    VappLauncherCosmosShortcutBar();

public:
    void serialize();

    void restore();

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onDraw(
        VfxDrawContext &dc
    );

    virtual void onFold();

    virtual void onUnfold();

private:
  
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        HEIGHT = 140,
    #elif defined(__MMI_MAINLCD_320X480__)
        HEIGHT = 80,
    #elif defined(__MMI_MAINLCD_240X400__)
        HEIGHT = 65,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        HEIGHT = 65,
    #endif /* defined(__MMI_MAINLCD_240X320__) */

        SHORTCUT_NUM = 4,
        SEPARATOR_NUM = SHORTCUT_NUM - 1
    };

// Variable
public: 
    VfxSignal0 m_signalMMLaunched;
    
private:
    VappLauncherCosmosMmShortcutBar *m_shortcut;

private:
    VfxPoint getSeparatorPos(
        const VfxSize &size,
        VfxS32 idx
    ) const;

    void onMainMenuLaunched();
};


/*****************************************************************************
 * Toolbar
 *****************************************************************************/

class VappLauncherCosmosToolbar : public VappLauncherCosmosBar
{
    VFX_DECLARE_CLASS(VappLauncherCosmosToolbar);

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
    VappLauncherCosmosToolbar();

// Signal
public:
    // This signal is emitted when the user clicks the specified button.
    VfxSignal2 <
        VappLauncherCosmosToolbar *,  // [IN] Toolbar
        ButtonEnum          // [IN] Button enum
    > m_signalExecute;

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onFold();

    virtual void onUnfold();

private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        FONT_SIZE = 23,
        HEIGHT = 114,
        TOP_MARGIN = 15,
        BOTTOM_MARGIN = 10
    #elif defined(__MMI_MAINLCD_320X480__)
        FONT_SIZE = 14,
        HEIGHT = 75,
        TOP_MARGIN = 15,
        BOTTOM_MARGIN = 10
    #elif defined(__MMI_MAINLCD_240X400__)
        FONT_SIZE = 13,
        HEIGHT = 57,
        TOP_MARGIN = 9,
        BOTTOM_MARGIN = 4
    #else /* __MMI_MAINLCD_240X320__ */
        FONT_SIZE = 12,
        HEIGHT = 57,
        TOP_MARGIN = 9,
        BOTTOM_MARGIN = 4
    #endif /* __MMI_MAINLCD_240X320__ */
    };

private:
    VcpButton *m_button[BUTTON_TOTAL];

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

#endif /* VAPP_LAUNCHER_COSMOS_BAR_H */

