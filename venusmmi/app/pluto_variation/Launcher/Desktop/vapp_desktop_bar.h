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
 *  vapp_desktop_bar.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_BAR_H
#define VAPP_DESKTOP_BAR_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_desktop_def.h"
#include "vapp_desktop_gprot.h"
#include "vapp_drawer_shortcut_bar.h"


/*****************************************************************************
 * Bar
 *****************************************************************************/

class VappDesktopBar : public VfxControl
{
public:
    VappDesktopBar();

public:
    VfxSignal1 <VappDesktopBar *> m_signalFoldingChanged;

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

class VappDesktopPageIndicator : public VappDesktopBar
{
    VFX_DECLARE_CLASS(VappDesktopPageIndicator);

public:
    VappDesktopPageIndicator();

public:
    VfxSignal1 <VappDesktopPageIndicator *> m_signalClicked;

public:
    void setIndex(
        VfxS32 idx
    );

    VfxS32 getIndex(void) const;

    VfxBool isHitted(
        VfxPenEvent &event
    );

protected:
    virtual void onInit();

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
        HEIGHT = VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH - 38,
        LEFT_GAP = 21,
        RIGHT_GAP = 21,
        GAP = 14,
        HITTABLE_HEIGHT = HEIGHT + 20
    #elif defined(__MMI_MAINLCD_320X480__)
        HEIGHT = VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH - 24,
        LEFT_GAP = 12,
        RIGHT_GAP = 12,
        GAP = 8,
        HITTABLE_HEIGHT = HEIGHT + 14
    #elif defined(__MMI_MAINLCD_240X400__)
        HEIGHT = VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH - 24,
        LEFT_GAP = 9,
        RIGHT_GAP = 9,
        GAP = 6,
        HITTABLE_HEIGHT = HEIGHT + 10
    #else /* defined(__MMI_MAINLCD_240X320__) */
        HEIGHT = VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH - 24,
        LEFT_GAP = 9,
        RIGHT_GAP = 9,
        GAP = 6,
        HITTABLE_HEIGHT = HEIGHT + 8
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

private:
    VfxS32 m_index;
    VfxImageFrame *m_dot[VAPP_DESKTOP_MAX_PAGE_NUM];

private:
    VfxSize getDotSize() const;

    VfxPoint getDotPos(
        VfxS32 idx
    ) const;

    void setHighlighted(
        VfxBool isOn
    );
};


/*****************************************************************************
 * Shortcut Bar Class
 *****************************************************************************/

class VappDesktopShortcutBar : public VappDesktopBar
{
    VFX_DECLARE_CLASS(VappDesktopShortcutBar);

public:
    VappDesktopShortcutBar();

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual void onFold();

    virtual void onUnfold();

private:
    VfxImageFrame *m_bgImg;
    VappDrawerShortcutBar *m_shortcut;
};


/*****************************************************************************
 * Toolbar
 *****************************************************************************/

class VappDesktopToolbar : public VappDesktopBar
{
    VFX_DECLARE_CLASS(VappDesktopToolbar);

public:
    enum ButtonEnum
    {
        BUTTON_ADD_WIDGET,
        BUTTON_ADD_SHORTCUT,
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
    VappDesktopToolbar();

// Signal
public:
    // This signal is emitted when the user clicks the specified button.
    VfxSignal2 <
        VappDesktopToolbar *,   // [IN] Toolbar
        ButtonEnum              // [IN] Button enum
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
        HEIGHT = 114,
        TOP_MARGIN = 15,
        BOTTOM_MARGIN = 10
    #elif defined(__MMI_MAINLCD_320X480__)
        HEIGHT = 75,
        TOP_MARGIN = 15,
        BOTTOM_MARGIN = 10
    #elif defined(__MMI_MAINLCD_240X400__)
        HEIGHT = 57,
        TOP_MARGIN = 9,
        BOTTOM_MARGIN = 4
    #else /* __MMI_MAINLCD_240X320__ */
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

    void onPostExecute(
        ButtonEnum buttonId
    );
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_BAR_H */

