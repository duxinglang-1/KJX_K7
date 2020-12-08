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
 *  vapp_home_page_selector.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the page selector.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_COSMOS_PAGE_SELECTOR_H
#define VAPP_LAUNCHER_COSMOS_PAGE_SELECTOR_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_launcher_cosmos_def.h"
#include "vapp_launcher_cosmos_primitive.h"


/*****************************************************************************
 * Page Selector Debug Panel
 *****************************************************************************/

#if defined(VAPP_LAUNCHER_COSMOS_UT_PAGE_SELECTOR_DEBUG_PANEL)

class VappLauncherCosmosPageSelectorDebugPanel : public VfxControl
{
public:
    VappLauncherCosmosPageSelectorDebugPanel();

public:
    VfxSignal1 <VfxS32> m_signalAnimationTimeChanged;

public:
    void initAnimationTime(
        VfxS32 time
    );

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onContainPoint(
        const VfxPoint &point
    ) const;

    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        WIDTH = 320,
        GAP_X = 6,
        GAP_Y = 12,
        TOGGLE_AREA_HEIGHT = 30,
        FONT_SIZE = 32,
    #elif defined(__MMI_MAINLCD_320X480__)
        WIDTH = 160,
        GAP_X = 2,
        GAP_Y = 3,
        TOGGLE_AREA_HEIGHT = 15,
        FONT_SIZE = 14,
    #elif defined(__MMI_MAINLCD_240X400__)
        WIDTH = 120,
        GAP_X = 1,
        GAP_Y = 2,
        TOGGLE_AREA_HEIGHT = 14,
        FONT_SIZE = 13,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        WIDTH = 120,
        GAP_X = 1,
        GAP_Y = 2,
        TOGGLE_AREA_HEIGHT = 12,
        FONT_SIZE = 12,
    #endif /* defined(__MMI_MAINLCD_240X320__) */
        ANI_TIME_STEP = 10,
        ANI_TIME_STEP_ACCELERATE_CRITERIA = 2,
        ANI_TIME_ADJUST_TIMER_START_DELAY = 200,
        ANI_TIME_ADJUST_TIMER_DURATION = 80
    };

private:
    VfxBool m_isOn;
    VfxS32 m_aniTime;
    VfxTextFrame *m_aniTimeText;
    VfxFrame *m_aniTimeIncBtn;
    VfxFrame *m_aniTimeDecBtn;
    VfxS32 m_aniTimeDiff;
    VfxS32 m_aniTimeDiffChangeCount;
    VfxTimer *m_aniTimeAdjustTimer;

    static const VfxFloat s_opacity;

private:
    VfxBool onAniTimePenInput(
        VfxPenEvent &event
    );

    void updateAniTime(
        VfxS32 diff
    );

    void onAniTimeAdjustTimer(
        VfxTimer *timer
    );
};
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_PAGE_SELECTOR_DEBUG_PANEL) */


/*****************************************************************************
 * Page Snapshot
 *****************************************************************************/

class VappLauncherCosmosPageSnapshot : public VfxControl
{
public:
    VappLauncherCosmosPageSnapshot();

public:
    VfxSignal1 <VappLauncherCosmosPageSnapshot *> m_signalTapped;

public:
    void setId(
        VfxId id
    );

    VfxId getId() const;

    void setLayout(
        const VfxRect &sourceRect
    );

    void getLayout(
        VfxRect &sourceRect
    ) const;

    void addToContainer(
        VfxFrame *frame
    );

    void removeFromContainer(
        VfxObjList &objList
    );

    VfxBool isEmpty();

    void setHighlight(
        VfxBool isOn
    );

    void setAlert(
        VfxBool isOn
    );

    void setObjectHidden(
        VfxBool isHidden
    );

    void setBgImgOpacity(
        VfxFloat value
    );

    void setBgImgHidden(
        VfxBool isHidden
    );

    void setBgImgRect(
        const VfxRect &rect
    );

    void setContentRect(
        const VfxRect &rect,
        VfxBool inner9SlicesEdge
    );

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onPreviewPenInput(
        VfxPenEvent &event
    );

    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    virtual void setBounds(
        const VfxRect &value
    );

private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        BG_IMG_9SLICES_LEFT = 5,
        BG_IMG_9SLICES_TOP = 5,
        BG_IMG_9SLICES_RIGHT = 6,
        BG_IMG_9SLICES_BOTTOM = 8
    #elif defined(__MMI_MAINLCD_320X480__)
        BG_IMG_9SLICES_LEFT = 5,
        BG_IMG_9SLICES_TOP = 5,
        BG_IMG_9SLICES_RIGHT = 6,
        BG_IMG_9SLICES_BOTTOM = 8
    #elif defined(__MMI_MAINLCD_240X400__)
        BG_IMG_9SLICES_LEFT = 3,
        BG_IMG_9SLICES_TOP = 2,
        BG_IMG_9SLICES_RIGHT = 4,
        BG_IMG_9SLICES_BOTTOM = 4
    #else /* defined(__MMI_MAINLCD_240X320__) */
        BG_IMG_9SLICES_LEFT = 3,
        BG_IMG_9SLICES_TOP = 2,
        BG_IMG_9SLICES_RIGHT = 4,
        BG_IMG_9SLICES_BOTTOM = 4
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

private:
    VfxId m_id;
    VfxImageFrame *m_bgImg;
    VfxRect m_sourceRect;

#if defined(__COSMOS_3D_V10__)
    // Color material.
    VappLauncherCosmosColorMaterial *m_alertMaterial;
#else
    // Color filter.
    VappLauncherCosmosColorFilter *m_alertFilter;
#endif /* defined(__COSMOS_3D_V10__) */

    VfxObjList m_objList;

    static const VfxColor s_alertFilterMin;
    static const VfxColor s_alertFilterMax;
    static const VfxFloat s_highlightOpacity;

private:
    VfxPoint getRectOffset(
        const VfxRect &dst,
        const VfxRect &src
    ) const;

    void getInner9SliceRect(
        VfxRect &rect
    );

    VfxFPoint getResizeRatio(
        const VfxRect &dst,
        const VfxRect &src
    ) const;
};


/*****************************************************************************
 * Page Selector
 *****************************************************************************/

class VappLauncherCosmosPageSelector : public VfxControl
{
public:
    enum AbortCauseEnum
    {
        ABORT_CAUSE_PAGE_EXIT,
        ABORT_CAUSE_BACK_KEY,
        ABORT_CAUSE_HOME_KEY,
        ABORT_CAUSE_DROP_OUTSIDE
    };

// Constructor / Destructor
public:
    // Default constructor
    VappLauncherCosmosPageSelector();

    // Default destructor
    virtual ~VappLauncherCosmosPageSelector();

// Signal
public:
    // When the 'assemble' function is called, all pages will be assembed. After
    // the assembling animation is completed, this signal is emited.
    VfxSignal1 <VappLauncherCosmosPageSelector *> m_signalAssembled;

    // When a page is selected, this signal is emited with the index of the
    // selected page. Note that no further 'selected' or 'aborted' signal will
    // be emited unless this page selector is revived.
    VfxSignal2 <VappLauncherCosmosPageSelector *, VfxS32> m_signalSelected;

    // When the page selector is aborted, e.g., a back key or home key is
    // pressed, this signal is emited. Note that no further 'selected' or
    // 'aborted' signal will be emited unless this page selector is revived.
    VfxSignal2 <VappLauncherCosmosPageSelector *, AbortCauseEnum> m_signalAborted;

    // When the 'dismiss' function is called, all pages will be dismissed. After
    // the dismissing animation is completed, this signal is emited.
    VfxSignal1 <VappLauncherCosmosPageSelector *> m_signalDismissed;

// Method
public:
    void setInnerBorder(
        VfxS32 horizWidth,
        VfxS32 vertiWidth
    );

    void setOuterBorder(
        VfxS32 topWidth,
        VfxS32 bottomWidth,
        VfxS32 leftWidth,
        VfxS32 rightWidth
    );

    void setLayout(
        const VfxS32 *snapshotPerRow,
        VfxS32 totalRowNum
    );

    VfxBool doPenInput(
        VfxPenEvent &event
    );

    void setId(
        VfxId id
    );

    VfxId getId() const;

    VfxS32 getLastSelectedIndex() const;

    void setFocusSnapshot(
        VfxS32 idx
    );

    VfxS32 getFocusSnapshot() const;

    void setSnapshotLayout(
        VfxS32 idx,
        const VfxRect &sourceRect
    );

    void addToSnapshot(
        VfxS32 idx,
        VfxFrame *frame
    );

    void removeFromSnapshot(
        VfxS32 idx,
        VfxObjList &objList
    );

    void assemble();

    void dismiss();

    void revive();

    void setSnapshotAlert(
        VfxS32 idx,
        VfxBool isOn
    );

    void disableSnapshotAlert();

protected:
    virtual void onInit();

    virtual void onDeinit();

    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

private:
    enum StateEnum
    {
        STATE_ASSEMBLING,
        STATE_ASSEMBLED,
        STATE_DISMISSING,
        STATE_DISMISSED
    };

    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        INNER_BORDER_HORIZ_WIDTH = 18,
        INNER_BORDER_VERTI_WIDTH = 20,
        OUTER_BORDER_TOP_WIDTH = 135,
        OUTER_BORDER_BOTTOM_WIDTH = 115,
        OUTER_BORDER_LEFT_WIDTH = 26,
        OUTER_BORDER_RIGHT_WIDTH = 26,
    #elif defined(__MMI_MAINLCD_320X480__)
        INNER_BORDER_HORIZ_WIDTH = 18,
        INNER_BORDER_VERTI_WIDTH = 20,
        OUTER_BORDER_TOP_WIDTH = 82,
        OUTER_BORDER_BOTTOM_WIDTH = 78,
        OUTER_BORDER_LEFT_WIDTH = 19,
        OUTER_BORDER_RIGHT_WIDTH = 15,
    #elif defined(__MMI_MAINLCD_240X400__)
        INNER_BORDER_HORIZ_WIDTH = 14,
        INNER_BORDER_VERTI_WIDTH = 17,
        OUTER_BORDER_TOP_WIDTH = 72,
        OUTER_BORDER_BOTTOM_WIDTH = 68,
        OUTER_BORDER_LEFT_WIDTH = 14,
        OUTER_BORDER_RIGHT_WIDTH = 12,
    #else /* defined(__MMI_MAINLCD_240X320__) */
        INNER_BORDER_HORIZ_WIDTH = 14,
        INNER_BORDER_VERTI_WIDTH = 14,
        OUTER_BORDER_TOP_WIDTH = 62,
        OUTER_BORDER_BOTTOM_WIDTH = 59,
        OUTER_BORDER_LEFT_WIDTH = 14,
        OUTER_BORDER_RIGHT_WIDTH = 12,
    #endif /* defined(__MMI_MAINLCD_240X320__) */

        SNAPSHOT_PER_ROW = 3
    };

private:
    VfxS32 m_innerBorderVertiWidth;
    VfxS32 m_innerBorderHorizWidth;
    VfxS32 m_outerBorderTopWidth;
    VfxS32 m_outerBorderBottomWidth;
    VfxS32 m_outerBorderLeftWidth;
    VfxS32 m_outerBorderRightWidth;
    StateEnum m_state;
    VfxBool m_isResponseProvided;
    VfxId m_id;
    VfxS32 m_lastSelectedIndex;
    VfxS32 m_focusSnapshotIndex;
    VfxTimer *m_assembleTimer;
    VfxTimer *m_dismissTimer;
    VfxTimer *m_delayAbortTimer;
    VfxS32 m_totalRowNum;
    VfxS32 *m_snapshotPerRow;
    VappLauncherCosmosPageSnapshot *m_snapshot[VAPP_LAUNCHER_COSMOS_MAX_PAGE_NUM];

    static VfxS32 s_autoAnimationTime;

private:
    void emitSignalSelected(
        VfxS32 idx
    );

    void emitSignalAbort(
        AbortCauseEnum cause
    );

    VfxBool isSnapshotHitted(
        VfxPenEvent &event,
        VfxS32 idx
    );

    VfxS32 getMaxSnapshotNumPerRow() const;

    void getCoordinate(
        VfxS32 idx,
        VfxS32 &x,
        VfxS32 &y
    ) const;

    VfxSize getSnapshotSize() const;

    VfxRect getSnapshotRoom(
        VfxS32 idx
    ) const;

    VfxRect getSnapshotOutsideRoom(
        VfxS32 idx
    ) const;

    VfxRect tuneSnapshotRoom(
        const VfxRect &room,
        const VfxSize &originalSize
    ) const;

    void onSnapshotTapped(
        VappLauncherCosmosPageSnapshot *snapshot
    );

    void onTimerAssembled(
        VfxTimer *timer
    );

    void onTimerDismissed(
        VfxTimer *timer
    );

    void onTimerDelayAbortCallback(
        VfxTimer *timer
    );

#if defined(VAPP_LAUNCHER_COSMOS_UT_PAGE_SELECTOR_DEBUG_PANEL)
private:
    VappLauncherCosmosPageSelectorDebugPanel *m_debugPanel;

private:
    void createDebugPanel();

    void onAnimationTimeChanged(
        VfxS32 time
    );
#endif /* defined(VAPP_LAUNCHER_COSMOS_UT_PAGE_SELECTOR_DEBUG_PANEL) */
};

#endif /* VAPP_LAUNCHER_COSMOS_PAGE_SELECTOR_H */

