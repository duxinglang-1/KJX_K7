/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 * Vapp_notepaper.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __VAPP_NOTEPAPER_H__
#define __VAPP_NOTEPAPER_H__

/*****************************************************************************
 * Include
 *****************************************************************************/

/**********  KAL Layer Header **************/

/**********  MMI Layer Header **************/
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_primitive_frame.h"
#include "vfx_weak_ptr.h"
#include "vfx_timer.h"
#include "vfx_text_frame.h"
#include "vfx_input_event.h"

#include "vcp_frame_effect_type.h"
#include "vcp_frame_effect.h"

#include "vapp_notepaper_cfg.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
class VappNotePaper;

/*****************************************************************************
 * Class IVappNotePaperFrameProvider
 *****************************************************************************/

/*
 * like IVcpListMenuContentProvider
 */

class IVappNotePaperFrameProvider
{
public:
    // Overridable
    virtual VfxFrame* createNPFrame(
        VfxS32 page,    // [IN] the page index
        VfxSize size    // [IN] the frame size
        ) = 0;

    // Uer should release the resource of the content frame which is created by
    // itself, such as image resource
    virtual void closeNPFrame(
        VfxFrame *cell // [IN] the content frame to be released
        ) = 0;

    virtual VfxFrame* updateNPFrame(
        VfxS32 page,    // [IN] the page index
        VfxSize size,   // [IN] the frame size
        VfxFrame *cell  // [IN] original frame
        ) = 0;

    virtual VfxU32 getNPCount() const = 0;

};


/*****************************************************************************
 * Class VappNotePaper
 *****************************************************************************/

class VappNotePaper : public VfxControl
{
    VFX_DECLARE_CLASS(VappNotePaper);

    typedef VappNotePaper    Self;
    typedef VfxControl       Super;

// Declaration
private:
    enum PageEnum
    {
        PREV_PAGE_FRAME       = 0,
        CURRENT_PAGE_FRAME    = 1,
        NEXT_PAGE_FRAME       = 2,
        TOTAL_PAGE_FRAME
    };

    enum
    {
        ONSWIPE_MINIMUM_SPEED = 50,
    #if defined(__MMI_MAINLCD_240X320__)
        ONTAP_MAXIMUM_DISTANCE = 25,        // distance to judge change page
    #elif defined(__MMI_MAINLCD_320X480__)
        ONTAP_MAXIMUM_DISTANCE = 28,        // distance to judge change page
    #else
        ONTAP_MAXIMUM_DISTANCE = 25,        // distance to judge change page
    #endif
    };


// Constructor / Destructor
public:
    VappNotePaper();

// Property set/get
public:
    void setCurrentPage(VfxS32 page);
    VfxS32 getCurrentPage() const;
    VfxS32 getTotalPage() const;
    VfxSize getPageSize() const;
    void setFrameProvider(
        IVappNotePaperFrameProvider *provider
    );

    // freeze notepaper
    // 1) stop all frame effect
    // 2) do not update screen anymore
    void setIsFreeze(
        VfxBool isFreeze
    );

    VfxBool getIsFreeze() const;

    VfxBool getIsFlipping() const;

    VfxBool getIsDeleting() const;

// method
public:
    VfxS32 showNextPage();
    VfxS32 showPrevPage();

    VfxS32 deletePage(
        VcpEffectType EffectType = VCP_EFFECT_MORPH_FADE_IN,
        VfxMsec Duration = 1500,
        VcpEffectTypeDirection direction = VCP_EFFECT_DIRECTION_FROM_NONE,
        VfxBool isReverse = VFX_TRUE,
        void *data = NULL,
        VfxS32 dataSize = 0
    );

// Signal
public:
    // This signal is invoked when one page index is changed
    // void YourClass::onPageIndexChanged(VfxS32 pageIndex, VfxFrame *cell)
    VfxSignal2 <VfxS32, VfxFrame *> m_signalPageIndexChanged;

    // This signal is invoked when one page index is changed
    // void YourClass::onTap(VfxS32 pageIndex, VfxFrame *cell)
    VfxSignal2 <VfxS32, VfxFrame *> m_signalTap;

    // This signal is inovked when delete page frame effect finished
    // void YourClass::onPageDeleted(void)
    VfxSignal0 m_signalPageDeleted;

protected:
    // On init
    virtual void onInit();
    // On Deinit
    virtual void onDeinit();

    virtual void onUpdate();

private:
    VfxImageFrame       *m_baseImageFrame;
    VfxImageFrame       *m_scorllImageFrame;
    VfxImageFrame       *m_bottomImageFrame;
    VfxImageFrame       *m_flipImageFrame;

    //VfxFrame            *m_pageFrame[TOTAL_PAGE_FRAME];
    VfxFrameWeakPtr     m_pageFrame[TOTAL_PAGE_FRAME];
    VfxS32              m_pageIndex;
    VfxS32              m_totalPage;

    VfxTimer            *m_flipTimer;
    VfxS32              m_flipFrameCount;
    VfxBool             m_flipForward;

    IVappNotePaperFrameProvider *m_frameProvider;

    VcpFrameEffect      *m_frameEffect;

    VfxS32              m_maxMoveOffset;  // The max offset when drag. This is used for detecting tap or scroll.
    VfxMsec             m_lastPenEventTime;

    VfxBool             m_isFreeze;
    VfxBool             m_isDeleting;

    VfxBool             m_canTapInFlipping;

    VfxMsec             m_minTimeBetweenPenEvent;

    VfxTextFrame        *m_debugFrame;

// Override
protected:
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    // Notify when the user start drag the menu
    virtual void onDragStart();

    // Notify when the user stop drag the menu
    virtual void onDragEnd(
        VfxS32 xspeed,         // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed,         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
        VfxPenEvent &event
    );

    // Notify when the notepaper is dragged
    virtual void onDrag(
        VfxS32 xoffset,
        VfxS32 yoffset);

    // Notify when the notepaper is tapped
    virtual void onTap(VfxPoint pt);

    // Notify when the notepaper is swipped
    virtual void onSwipe(
        VfxS32 xspeed,      // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed       // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
    );

    virtual void onPageDeleted(
        VfxFrame *target,
        VfxBool isCompleted
    );

private:
    void stopFlipPage();
    void updateFlipFrame();
    void onFlipTimerExpired(VfxTimer *timer);

    // update page frame , set the current page to pageIndex
    // emit the m_signalPageIndexChanged if page changed
    void updateToPage(
        VfxS32 pageIndex,                   // page index
        VfxBool isForceUpdate               // force to update all frame
    );

    // Load all frame, especially the previous page and next page for cache
    void loadFrame(
        VfxBool isLoadAllFrame              // force to load and update all frame
    );

    void showDebugInfo();

private:
    const static VfxS32 notePaperFlipBounds[VAPP_NOTEPAPER_FLIP_FRAME_NUMBER];
    const static VfxS32 flipPageFramePosition[VAPP_NOTEPAPER_FLIP_FRAME_NUMBER][4];
    const static VfxS32 scrollImagePosition[4];
    const static VfxS32 bottomImagePosition[4];

};

/*****************************************************************************
 * Global Function
 *****************************************************************************/

#endif
