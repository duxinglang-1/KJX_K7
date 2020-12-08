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
 * Vapp_notepaper.cpp
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
 *==============================================================================
 *******************************************************************************/


/*****************************************************************************
 * Include
 *****************************************************************************/

/**********  KAL Layer Header **************/

#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#ifdef __cplusplus
}
#endif

/**********  MMI Layer Header **************/
#include "MMI_features.h"

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_primitive_frame.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vfx_system.h"
#include "vfx_animation.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vfx_weak_ptr.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_input_event.h"
#include "vcp_frame_effect_type.h"
#include "vcp_frame_effect.h"
#include "vrt_datatype.h"

#include "mmi_rp_app_venus_notepaper_def.h"
#include "vapp_notepaper.h"
#include "vadp_app_trc.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "gui_touch_feedback.h"
#ifdef __cplusplus
}
#endif

#ifdef __MMI_VUI_SHELL_MSG_VIEWER__
/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * Class VappNotePaper
 *****************************************************************************/

const VfxS32 VappNotePaper::notePaperFlipBounds[VAPP_NOTEPAPER_FLIP_FRAME_NUMBER] = VAPP_NOTE_PAPER_FLIP_BOUNDS_Y;
const VfxS32 VappNotePaper::flipPageFramePosition[VAPP_NOTEPAPER_FLIP_FRAME_NUMBER][4] = VAPP_NOTEPAPER_FLIP_FRAME_POSITION;
const VfxS32 VappNotePaper::scrollImagePosition[4] = VAPP_NOTEPAPER_SCROLL_IMAGE_POSITION;
const VfxS32 VappNotePaper::bottomImagePosition[4] = VAPP_NOTEPAPER_BOTTOM_IMAGE_POSITION;

VFX_IMPLEMENT_CLASS("VappNotePaper", VappNotePaper, VfxControl);

VappNotePaper::VappNotePaper():
    m_baseImageFrame(NULL),
    m_scorllImageFrame(NULL),
    m_bottomImageFrame(NULL),
    m_flipImageFrame(NULL),
    m_flipTimer(NULL),
    m_flipFrameCount(0),
    m_flipForward(VFX_FALSE),
    m_frameProvider(NULL),
    m_frameEffect(NULL),
    m_totalPage(0),
    m_pageIndex(0),
    m_maxMoveOffset(0),
    m_lastPenEventTime(0),
    m_isFreeze(VFX_FALSE),
    m_isDeleting(VFX_FALSE),
    m_canTapInFlipping(VFX_FALSE),
    m_minTimeBetweenPenEvent(0),
    m_debugFrame(NULL)
{
    for(int i = 0; i < TOTAL_PAGE_FRAME ; i++)
    {
        m_pageFrame[i] = NULL;
    }
}

void VappNotePaper::onInit(void)
{
    Super::onInit();

    VFX_OBJ_CREATE(m_baseImageFrame, VfxImageFrame, this);
    m_baseImageFrame->setResId(IMG_ID_NOTEPAPER_PAGE_BASE);
    m_baseImageFrame->setPos(0, 0);

    VFX_OBJ_CREATE(m_scorllImageFrame, VfxImageFrame, this);
    m_scorllImageFrame->setResId(IMG_ID_NOTEPAPER_PAGE_SCROLL);
    m_scorllImageFrame->setPos(scrollImagePosition[0], scrollImagePosition[1]);

    VFX_OBJ_CREATE(m_bottomImageFrame, VfxImageFrame, this);
    m_bottomImageFrame->setResId(IMG_ID_NOTEPAPER_PAGE_BOTTOM);
    m_bottomImageFrame->setPos(bottomImagePosition[0], bottomImagePosition[1]);

    VFX_OBJ_CREATE(m_flipImageFrame, VfxImageFrame, this);
    m_flipImageFrame->setResId(IMG_ID_NOTEPAPER_PAGE_FLIP_1);
    m_flipImageFrame->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_flipTimer, VfxTimer, this);
    m_flipTimer->setStartDelay(VAPP_NOTEPAPER_FLIP_TIME_INTERVAL_MS);
    m_flipTimer->setDuration(VAPP_NOTEPAPER_FLIP_TIME_INTERVAL_MS);
    m_flipTimer->m_signalTick.connect(this, &Self::onFlipTimerExpired);

    this->setSize(m_baseImageFrame->getSize());
//    this->setPos(VAPP_NOTEPAPER_BOUNDS_X, VAPP_NOTEPAPER_BOUNDS_Y);
//    this->setBounds(VAPP_NOTEPAPER_BOUNDS_X, VAPP_NOTEPAPER_BOUNDS_Y,
//        VAPP_NOTEPAPER_BOUNDS_WIDTH, VAPP_NOTEPAPER_BOUNDS_HEIGHT);
}

void VappNotePaper::onDeinit(void)
{
    VFX_OBJ_CLOSE(m_baseImageFrame);
    VFX_OBJ_CLOSE(m_scorllImageFrame);
    VFX_OBJ_CLOSE(m_flipImageFrame);

    for(int i = 0; i < TOTAL_PAGE_FRAME ; i++)
    {
        if (m_pageFrame[i].isValid())
        {
            m_frameProvider->closeNPFrame(m_pageFrame[i].get());
        }
    }
    Super::onDeinit();
}

// -------------------------------------------------------------
// Property set/get
// -------------------------------------------------------------

void VappNotePaper::setCurrentPage(VfxS32 pageIndex)
{
    m_pageIndex = pageIndex;
    checkUpdate();
}

VfxS32 VappNotePaper::getCurrentPage(void) const
{
    return m_pageIndex;
}

VfxS32 VappNotePaper::getTotalPage(void) const
{
    return m_totalPage;
}

VfxSize VappNotePaper::getPageSize(void) const
{
    return VfxSize(VAPP_NOTEPAPER_SIZE_X, VAPP_NOTEPAPER_SIZE_Y);
}

void VappNotePaper::setFrameProvider(IVappNotePaperFrameProvider *provider)
{
    m_frameProvider = provider;
}

void VappNotePaper::setIsFreeze(VfxBool isFreeze)
{
    m_isFreeze = isFreeze;

    if (isFreeze && getIsFlipping())
    {
        stopFlipPage();
    }

    // todo: stop delete page frame effect if possible
    if (m_isDeleting)
    {
        VFX_OBJ_CLOSE(m_frameEffect);
    }
}

VfxBool VappNotePaper::getIsFreeze() const
{
    return m_isFreeze;
}

VfxBool VappNotePaper::getIsFlipping() const
{
    if (m_flipFrameCount > 0 && m_flipFrameCount < VAPP_NOTEPAPER_FLIP_FRAME_NUMBER)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappNotePaper::getIsDeleting() const
{
    return m_isDeleting;
}


// -------------------------------------------------------------
// Method
// -------------------------------------------------------------

VfxS32 VappNotePaper::showNextPage(void)
{
    if (!m_pageFrame[NEXT_PAGE_FRAME].isValid())
    {
        m_pageFrame[NEXT_PAGE_FRAME] = m_frameProvider->createNPFrame(m_pageIndex + 1, getPageSize());

        // next page is not existed
        if (!m_pageFrame[NEXT_PAGE_FRAME].isValid())
        {
            return -1;
        }
    }

    VFX_LOG(VFX_FUNC, VAPP_NOTEPAPER_SHOWNEXTPAGE, m_flipForward, m_flipFrameCount);

    // free prev page frame, and change order
    if (m_pageFrame[PREV_PAGE_FRAME].isValid())
    {
        m_frameProvider->closeNPFrame(m_pageFrame[PREV_PAGE_FRAME].get());
    }
    m_pageFrame[PREV_PAGE_FRAME] = m_pageFrame[CURRENT_PAGE_FRAME];
    m_pageFrame[CURRENT_PAGE_FRAME] = m_pageFrame[NEXT_PAGE_FRAME];
    m_pageFrame[NEXT_PAGE_FRAME] = NULL;

    // add the current page to notepaper, prepare to flip page
    insertChildFrameAfter(m_bottomImageFrame, m_pageFrame[CURRENT_PAGE_FRAME].get());

    // original the flippling direction is to next page
    // we will reply the frame effect or we will start the frame effect
    // from original place
    if (m_flipForward || m_flipFrameCount == 0)
    {
        m_flipFrameCount = 0;
        m_pageFrame[CURRENT_PAGE_FRAME]->setPos(0, VAPP_NOTEPAPER_SIZE_Y);
        m_pageFrame[CURRENT_PAGE_FRAME]->setBounds(0, 0, VAPP_NOTEPAPER_SIZE_X, 0);
        m_pageFrame[CURRENT_PAGE_FRAME]->setHidden(VFX_FALSE);
    }
    else
    {
        m_pageFrame[CURRENT_PAGE_FRAME]->setPos(0, notePaperFlipBounds[m_flipFrameCount-1]);
        m_pageFrame[CURRENT_PAGE_FRAME]->setBounds(0, notePaperFlipBounds[m_flipFrameCount-1], VAPP_NOTEPAPER_SIZE_X , VAPP_NOTEPAPER_SIZE_Y - notePaperFlipBounds[m_flipFrameCount-1]);
        m_pageFrame[CURRENT_PAGE_FRAME]->setHidden(VFX_FALSE);
    }

    m_pageIndex++;
    m_signalPageIndexChanged.emit(m_pageIndex, m_pageFrame[CURRENT_PAGE_FRAME].get());

    m_flipForward = VFX_TRUE;
    m_flipTimer->start();

    // pre load the frame
    loadFrame(VFX_FALSE);

    return 0;
}

VfxS32 VappNotePaper::showPrevPage(void)
{
    if (!m_pageFrame[PREV_PAGE_FRAME].isValid())
    {
        m_pageFrame[PREV_PAGE_FRAME] = m_frameProvider->createNPFrame(m_pageIndex - 1, getPageSize());
        // next page is not existed
        if (!m_pageFrame[PREV_PAGE_FRAME].isValid())
        {
            return -1;
        }
    }

    VFX_LOG(VFX_FUNC, VAPP_NOTEPAPER_SHOWPREVPAGE, m_flipForward, m_flipFrameCount);

    // free next page frame, and change order
    if (m_pageFrame[NEXT_PAGE_FRAME].isValid())
    {
        m_frameProvider->closeNPFrame(m_pageFrame[NEXT_PAGE_FRAME].get());
    }
    m_pageFrame[NEXT_PAGE_FRAME] = m_pageFrame[CURRENT_PAGE_FRAME];
    m_pageFrame[CURRENT_PAGE_FRAME] = m_pageFrame[PREV_PAGE_FRAME];
    m_pageFrame[PREV_PAGE_FRAME] = NULL;

    // add the current page to notepaper, prepare to flip page
    insertChildFrameAfter(m_bottomImageFrame, m_pageFrame[CURRENT_PAGE_FRAME].get());


    // original the flippling direction is to previous page
    // we will reply the frame effect or we will start the frame effect
    // from original place

    if (!m_flipForward || m_flipFrameCount == (VAPP_NOTEPAPER_FLIP_FRAME_NUMBER + 1))
    {
        m_flipFrameCount = VAPP_NOTEPAPER_FLIP_FRAME_NUMBER + 1;
        m_pageFrame[CURRENT_PAGE_FRAME]->setPos(0, 0);
        m_pageFrame[CURRENT_PAGE_FRAME]->setBounds(0, 0, VAPP_NOTEPAPER_SIZE_X , 0);
        m_pageFrame[CURRENT_PAGE_FRAME]->setHidden(VFX_FALSE);
    }
    else
    {
        m_pageFrame[CURRENT_PAGE_FRAME]->setPos(0, 0);
        m_pageFrame[CURRENT_PAGE_FRAME]->setBounds(0, 0, VAPP_NOTEPAPER_SIZE_X, notePaperFlipBounds[m_flipFrameCount-1] );
        m_pageFrame[CURRENT_PAGE_FRAME]->setHidden(VFX_FALSE);
    }

    m_pageIndex--;
    m_signalPageIndexChanged.emit(m_pageIndex, m_pageFrame[CURRENT_PAGE_FRAME].get());

    m_flipForward = VFX_FALSE;
    m_flipTimer->start();

    // pre load the frame
    loadFrame(VFX_FALSE);

    return 0;
}

void VappNotePaper::loadFrame(VfxBool isLoadAllFrame)
{
    if (!m_frameProvider)
    {
        return;
    }

    VFX_LOG(VFX_FUNC, VAPP_NOTEPAPER_LOADALLFRAME, isLoadAllFrame);

    for(VfxS32 i = 0; i < TOTAL_PAGE_FRAME ; i++)
    {
        if (!m_pageFrame[i].isValid())
        {
            m_pageFrame[i] = m_frameProvider->createNPFrame(i - CURRENT_PAGE_FRAME + m_pageIndex, getPageSize());
            if (m_pageFrame[i].isValid())
            {
                m_pageFrame[i]->setSize(getPageSize());
                m_pageFrame[i]->setHidden(VFX_TRUE);
            }
        }
        // updateNPFrame will update the content automatically if the content is changed,
        // we do not need to close the frame first, so "isForceUpdate" is useless now
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        else if (isLoadAllFrame)
        {
            m_pageFrame[i] = m_frameProvider->updateNPFrame(i - CURRENT_PAGE_FRAME + m_pageIndex, getPageSize(), m_pageFrame[i].get());
        }
    }

}

VfxS32 VappNotePaper::deletePage(
    VcpEffectType EffectType,
    VfxMsec Duration,
    VcpEffectTypeDirection direction,
    VfxBool isReverse,
    void *data,
    VfxS32 dataSize)
{
    VFX_ASSERT(m_pageFrame[CURRENT_PAGE_FRAME].get());

    VFX_LOG(VFX_FUNC, VAPP_NOTEPAPER_DELETEPAGE);

    m_isDeleting = VFX_TRUE;

//    VfxS32 deletePageIndex = m_pageIndex;

    // Add background image to current page frame and prepare to move out
    m_pageFrame[CURRENT_PAGE_FRAME]->setImgContent(VfxImageSrc(IMG_ID_NOTEPAPER_PAGE_BASE));

    // appy frame effect to current page
    VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
    m_frameEffect->m_signalFinished.connect(this, &Self::onPageDeleted);

    m_frameEffect->applyEffect(
        m_pageFrame[CURRENT_PAGE_FRAME].get(),
        EffectType, Duration, direction, isReverse, data, dataSize);

    //m_totalPage--;

    // Last page
    if (m_pageIndex == m_totalPage)
    {
        m_pageFrame[CURRENT_PAGE_FRAME] = m_pageFrame[PREV_PAGE_FRAME];
        m_pageFrame[PREV_PAGE_FRAME] = NULL;
        m_pageIndex--;

        m_signalPageIndexChanged.emit(m_pageIndex, m_pageFrame[CURRENT_PAGE_FRAME].get());
    }
    else
    {
        m_pageFrame[CURRENT_PAGE_FRAME] = m_pageFrame[NEXT_PAGE_FRAME];
        m_pageFrame[NEXT_PAGE_FRAME] = NULL;
        m_pageIndex++;

        m_signalPageIndexChanged.emit(m_pageIndex, m_pageFrame[CURRENT_PAGE_FRAME].get());
    }

    if (m_pageFrame[CURRENT_PAGE_FRAME].isValid())
    {
        // add the current page to notepaper, prepare to flip page
        insertChildFrameAfter(m_bottomImageFrame, m_pageFrame[CURRENT_PAGE_FRAME].get());
        m_pageFrame[CURRENT_PAGE_FRAME]->setPos(0,0);
        m_pageFrame[CURRENT_PAGE_FRAME]->setBounds(0,0, VAPP_NOTEPAPER_SIZE_X, VAPP_NOTEPAPER_SIZE_Y);
        m_pageFrame[CURRENT_PAGE_FRAME]->setHidden(VFX_FALSE);
    }
    else
    {
        //setHidden(VFX_TRUE);
    }

    return 0;
}

void VappNotePaper::stopFlipPage()
{
    ASSERT(m_pageFrame[CURRENT_PAGE_FRAME].isValid());

    m_flipTimer->stop();

    if (m_flipForward)
    {
        m_flipFrameCount = VAPP_NOTEPAPER_FLIP_FRAME_NUMBER + 1;
        m_pageFrame[PREV_PAGE_FRAME]->removeFromParentFrame();
        m_pageFrame[PREV_PAGE_FRAME]->setHidden(VFX_TRUE);
    }
    else
    {
        m_flipFrameCount = 0;
        m_pageFrame[NEXT_PAGE_FRAME]->removeFromParentFrame();
        m_pageFrame[NEXT_PAGE_FRAME]->setHidden(VFX_TRUE);
    }

    m_flipImageFrame->setHidden(VFX_TRUE);
    m_bottomImageFrame->setHidden(VFX_FALSE);

    // hide the scroll bar
    if (m_pageIndex == 1)
    {
        m_scorllImageFrame->setHidden(VFX_TRUE);
    }
    else
    {
        m_scorllImageFrame->setHidden(VFX_FALSE);
    }

    m_pageFrame[CURRENT_PAGE_FRAME]->setBounds(0,0, VAPP_NOTEPAPER_SIZE_X, VAPP_NOTEPAPER_SIZE_Y);

}

void VappNotePaper::updateFlipFrame()
{

    if ( (m_flipForward && m_flipFrameCount > VAPP_NOTEPAPER_FLIP_FRAME_NUMBER) ||
         (!m_flipForward && m_flipFrameCount < 1))
    {
        stopFlipPage();
        return;
    }

    // hide the scroll bar
    if (m_pageIndex == 1 && !m_flipForward)
    {
        m_scorllImageFrame->setHidden(VFX_TRUE);
    }

    // update the flip image frame
    m_flipImageFrame->setResId(IMG_ID_NOTEPAPER_PAGE_FLIP_1 + m_flipFrameCount - 1);
    m_flipImageFrame->setPos(flipPageFramePosition[m_flipFrameCount - 1][0], flipPageFramePosition[m_flipFrameCount - 1][1]);
    m_flipImageFrame->setHidden(VFX_FALSE);

    if (m_flipFrameCount == 1)
    {
        m_bottomImageFrame->setHidden(VFX_TRUE);
    }
    else
    {
        m_bottomImageFrame->setHidden(VFX_FALSE);
    }

    // update the content frame
    VfxFrameWeakPtr top,bottom;

    if (m_flipForward)
    {
        top = m_pageFrame[PREV_PAGE_FRAME];
        bottom = m_pageFrame[CURRENT_PAGE_FRAME];
    }
    else
    {
        top = m_pageFrame[CURRENT_PAGE_FRAME];
        bottom = m_pageFrame[NEXT_PAGE_FRAME];
    }

    top->setPos(0, 0);
    top->setBounds(0, 0, VAPP_NOTEPAPER_SIZE_X , notePaperFlipBounds[m_flipFrameCount-1]);

    bottom->setPos(0, notePaperFlipBounds[m_flipFrameCount-1]);
    bottom->setBounds(0, notePaperFlipBounds[m_flipFrameCount-1], VAPP_NOTEPAPER_SIZE_X , VAPP_NOTEPAPER_SIZE_Y - notePaperFlipBounds[m_flipFrameCount-1]);
}

// -------------------------------------------------------------
// Event Handler
// -------------------------------------------------------------
void VappNotePaper::onUpdate()
{
    if (!m_frameProvider)
    {
        return;
    }

    //VFX_LOG(VFX_FUNC, VAPP_NOTEPAPER_UPDATETOPAGE, m_pageIndex);

    if (getIsFlipping())
    {
        stopFlipPage();
    }

    m_totalPage = m_frameProvider->getNPCount();

    loadFrame(VFX_TRUE);

    if (m_pageFrame[CURRENT_PAGE_FRAME].isValid())
    {
        insertChildFrameAfter(m_bottomImageFrame, m_pageFrame[CURRENT_PAGE_FRAME].get());

        m_pageFrame[CURRENT_PAGE_FRAME]->setPos(0,0);
        m_pageFrame[CURRENT_PAGE_FRAME]->setBounds(0,0, VAPP_NOTEPAPER_SIZE_X, VAPP_NOTEPAPER_SIZE_Y);
        m_pageFrame[CURRENT_PAGE_FRAME]->setHidden(VFX_FALSE);

        // hide the scroll bar
        if (m_pageIndex == 1)
        {
            m_scorllImageFrame->setHidden(VFX_TRUE);
        }
        else
        {
            m_scorllImageFrame->setHidden(VFX_FALSE);
        }
    }
    else
    {
        m_pageIndex = 0;
    }

    m_signalPageIndexChanged.emit(m_pageIndex, m_pageFrame[CURRENT_PAGE_FRAME].get());
}

void VappNotePaper::showDebugInfo()
{
    VfxWString str;
    str.format("TapInFlipping=%d MinPenEventTime=%d", m_canTapInFlipping, m_minTimeBetweenPenEvent);

    if (m_debugFrame == NULL)
    {
      VFX_OBJ_CREATE(m_debugFrame, VfxTextFrame, this);
      m_debugFrame->setPos(20, 250);
    }

    m_debugFrame->setString(str);
    m_debugFrame->setOpacity(1.0f);
    m_debugFrame->setColor(VFX_COLOR_RED);
    m_debugFrame->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));

}

void VappNotePaper::onDragStart()
{
}

void VappNotePaper::onSwipe(VfxS32 xspeed, VfxS32 yspeed)
{
    if (yspeed > 0)
    {
        showPrevPage();
    }
    else
    {
        showNextPage();
    }
}

void VappNotePaper::onDragEnd(VfxS32 xspeed, VfxS32 yspeed, VfxPenEvent &event)
{
    if (VFX_ABS(yspeed) >= ONSWIPE_MINIMUM_SPEED)
    {
        VFX_LOG(VFX_INFO2, VAPP_NOTEPAPER_ONDRAGEND, xspeed, yspeed);

        m_lastPenEventTime = event.timeStamp;
        onSwipe(xspeed, yspeed);
    }
}

void VappNotePaper::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
}

void VappNotePaper::onTap(VfxPoint pt)
{
    VFX_LOG(VFX_INFO2, VAPP_NOTEPAPER_ONTAP, getIsFlipping(), m_canTapInFlipping);

    if (!getIsFlipping() || m_canTapInFlipping)
    {
        m_signalTap.emit(m_pageIndex, m_pageFrame[CURRENT_PAGE_FRAME].get());
    }
}

VfxBool VappNotePaper::onKeyInput(VfxKeyEvent &event)
{
	switch (event.type)
    {
    	case VFX_KEY_EVENT_TYPE_DOWN:
		{
        #ifdef __VAPP_NOTEPAPER_DEBUG__
			if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
	        {
                showPrevPage();
	            return VFX_TRUE;
	        }

	        if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
	        {
                showNextPage();
	            return VFX_TRUE;
	        }

			if (event.keyCode == VFX_KEY_CODE_CSK)
			{
                onTap(VfxPoint(0,0));
                return VFX_TRUE;
			}

            if (event.keyCode == VFX_KEY_CODE_1)
            {
                m_canTapInFlipping = !m_canTapInFlipping;
                showDebugInfo();
                return VFX_TRUE;
            }

            if (event.keyCode == VFX_KEY_CODE_2)
            {
                m_minTimeBetweenPenEvent += 50;
                showDebugInfo();
                return VFX_TRUE;
            }

            if (event.keyCode == VFX_KEY_CODE_3)
            {
                m_minTimeBetweenPenEvent -= 50;
                if (m_minTimeBetweenPenEvent < 0)
                {

                    m_minTimeBetweenPenEvent = 0;
                }
                showDebugInfo();
                return VFX_TRUE;
            }
        #endif

			break;
		}

		default:
			break;
    }
    return Super::onKeyInput(event);
}

VfxBool VappNotePaper::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VFX_LOG(VFX_INFO2, VAPP_NOTEPAPER_PENDOWN);

        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);

        m_maxMoveOffset = 0;
        onDragStart();
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        VFX_LOG(VFX_INFO2, VAPP_NOTEPAPER_PENUP, m_maxMoveOffset);

        if (m_maxMoveOffset <= ONTAP_MAXIMUM_DISTANCE)
        {
            // this is a tap
            VfxPoint dowmpt = event.getRelDownPos(this);

            onDragEnd(0, 0, event);

            if (event.downTimeStamp - m_lastPenEventTime > m_minTimeBetweenPenEvent)
            {
                onTap(dowmpt);
            }
        }
        else if (event.timeStamp > event.downTimeStamp)
        {
            VfxPoint dowmpt = event.getRelDownPos(this);
            VfxPoint pt     = event.getRelPos(this);
            VfxS32   yv      = (1000 * (pt.y - dowmpt.y)) / (event.timeStamp - event.downTimeStamp);
            VfxS32   xv      = (1000 * (pt.x - dowmpt.x)) / (event.timeStamp - event.downTimeStamp);

            onDragEnd(xv, yv, event);
        }
        else
        {
            onDragEnd(0, 0, event);
        }

        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        onDragEnd(0, 0, event);
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        VfxPoint dowmpt = event.getRelDownPos(this);
        VfxPoint prept  = event.getRelPrevPos(this);
        VfxPoint pt     = event.getRelPos(this);

        VfxS32 xoffset = VFX_ABS(pt.x - dowmpt.x);
        VfxS32 yoffset = VFX_ABS(pt.y - dowmpt.y);

        m_maxMoveOffset = yoffset > m_maxMoveOffset ? yoffset : m_maxMoveOffset;
        m_maxMoveOffset = xoffset > m_maxMoveOffset ? xoffset : m_maxMoveOffset;

        onDrag(pt.x - prept.x, pt.y - prept.y);

        return VFX_TRUE;
    }

    return Super::onPenInput(event);
}


void VappNotePaper::onPageDeleted(VfxFrame *target, VfxBool isCompleted)
{
    VFX_LOG(VFX_FUNC, VAPP_NOTEPAPER_ONPAGEDELETED, isCompleted);

    VFX_OBJ_CLOSE(m_frameEffect);
    m_frameProvider->closeNPFrame(target);
    m_isDeleting = VFX_FALSE;
    m_signalPageDeleted.emit();
}

void VappNotePaper::onFlipTimerExpired(VfxTimer *timer)
{
    if (m_flipForward)
    {
        m_flipFrameCount++;
    }
    else
    {
        m_flipFrameCount--;
    }
    updateFlipFrame();
}

#endif /* __MMI_VUI_SHELL_MSG_VIEWER__ */


