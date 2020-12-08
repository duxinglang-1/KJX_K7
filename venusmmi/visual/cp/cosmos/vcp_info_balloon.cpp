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
 *  vcp_info_balloon.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Info Balloon component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
    #include "GlobalResDef.h"
}

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_res.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_info_balloon.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_string.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "mmi_rp_srv_venus_component_info_balloon_def.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_object_list.h"
#include "vfx_top_level.h"
#include "vfx_animation.h"
#include "vfx_signal.h"
#include "vfx_timer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpInfoBalloonUpperItem 
 *****************************************************************************/  
//VFX_IMPLEMENT_CLASS("VcpInfoBalloonUpperItem", VcpInfoBalloonUpperItem, VfxControl);
VcpInfoBalloonBaseItem::VcpInfoBalloonBaseItem():
	m_opacityTimeline(NULL),
    m_durationTimer(NULL),
    m_index(0),
    m_state(VCP_INFO_BALLOON_ANIMATION_STATE_NONE)
{

}
void VcpInfoBalloonBaseItem::onInit()
{
	VfxControl::onInit();
    setIsUnhittable(VFX_TRUE);

    // Set image icon
    VFX_OBJ_CREATE(m_iconFrame, VfxFrame, this);
    m_iconFrame->setAnchor(0.5, 0.5);   
    m_iconFrame->setSize(VCP_INFO_BALLOON_ICON_WIDTH, VCP_INFO_BALLOON_ICON_HEIGHT);
    m_iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_iconFrame->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);

    m_textFrame->setAnchor(0, 0.5);    
#ifdef __MMI_VUI_COSMOS_CP__
    m_textFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_INFO_BALLOON_TXT));
#else
	m_textFrame->setColor(VfxColor(255,15,15,15));
#endif
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_INFO_BALLOON_TEXT_SIZE);
    m_textFrame->setFont(fontDesc);
}


void VcpInfoBalloonBaseItem::timeOut(VfxTimer *timer)
{
    VFX_UNUSED(timer);
    VFX_OBJ_CLOSE(m_durationTimer);
    leave();
}

        
void VcpInfoBalloonBaseItem::leave()
{
	VFX_OBJ_CLOSE(m_durationTimer);

	if (m_opacityTimeline == NULL)
	{
		VFX_OBJ_CREATE(m_opacityTimeline, VfxFloatTimeline, this);
	}

    m_opacityTimeline->setTarget(this);
    m_opacityTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_opacityTimeline->setDurationTime(VCP_INFO_BALLOON_FADING_TIME);

    m_opacityTimeline->setIsFromCurrent(VFX_TRUE);
    m_opacityTimeline->setToValue(0.0f);

    m_opacityTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_opacityTimeline->m_signalStopped.connect(this, &VcpInfoBalloonUpperItem::finishState);
    m_opacityTimeline->start();
    m_state = VCP_INFO_BALLOON_ANIMATION_STATE_FADING;
}


void VcpInfoBalloonBaseItem::finishState(VfxBaseTimeline *timeline, VfxBool stop)
{
    m_signalLeaveFinished.emit(this, m_index);
}


void VcpInfoBalloonBaseItem::exit()
{
    VcpInfoBalloonBaseItem *self = this;
    VFX_OBJ_CLOSE(self);
}



VcpInfoBalloonUpperItem::VcpInfoBalloonUpperItem()   
{
}

void VcpInfoBalloonUpperItem::onInit()
{
    VFX_OBJ_CREATE(m_backgroundLeft, VfxFrame, this);
    m_backgroundLeft->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundLeft->setImgContent(VfxImageSrc(VCP_IMG_INFO_BALLOON_BG_LEFT));
    m_backgroundLeft->setPos(0, VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT);

    VFX_OBJ_CREATE(m_backgroundCenter, VfxFrame, this);
    m_backgroundCenter->setBounds(VfxRect(0, 0, VCP_INFO_BALLOON_UPPER_ARROW_WIDTH, VCP_INFO_BALLOON_UPPER_HEIGHT));
    m_backgroundCenter->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundCenter->setImgContent(VfxImageSrc(VCP_IMG_INFO_BALLOON_BG_CENTER));

    VFX_OBJ_CREATE(m_backgroundRight, VfxFrame, this);
    m_backgroundRight->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundRight->setImgContent(VfxImageSrc(VCP_IMG_INFO_BALLOON_BG_RIGHT));
    
	VcpInfoBalloonBaseItem::onInit();
    m_iconFrame->setPos(VCP_INFO_BALLOON_ICON_X, VCP_INFO_BALLOON_UPPER_ICON_Y);    
    m_textFrame->setPos(VCP_INFO_BALLOON_TEXT_X, VCP_INFO_BALLOON_UPPER_TEXT_Y);
}

void VcpInfoBalloonUpperItem::adjustPos(const VfxPoint &arrow)
{
    VfxS32 textWidth = m_textFrame->getSize().width;
	VfxS32 parentWidth = getParentFrame()->getSize().width;
    
	if (textWidth > parentWidth - VCP_INFO_BALLOON_TEXT_X - VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN)
    {
        textWidth = parentWidth - VCP_INFO_BALLOON_TEXT_X - VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN;
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_textFrame->setSize(textWidth, getSize().height);
    }
    
    VfxS32 totalWidth = textWidth + VCP_INFO_BALLOON_TEXT_X + VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN;
    setBounds(VfxRect(0, 0, textWidth + VCP_INFO_BALLOON_TEXT_X + VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN, VCP_INFO_BALLOON_UPPER_HEIGHT));
    VfxS32 arrowX = arrow.x;

    m_backgroundCenter->setImgContent(VfxImageSrc(VCP_IMG_INFO_BALLOON_BG_CENTER));
   
    if (arrow.x < VCP_INFO_BALLOON_UPPER_MIN_X)
    {
        //VFX_DEV_ASSERT(0);
        setPos(0, arrow.y); 
        arrowX = VCP_INFO_BALLOON_UPPER_MIN_X;
        m_backgroundCenter->setImgContent(VfxImageSrc(VCP_IMG_INFO_BALLOON_BG_CENTER_LEFT));
    }
    else if (arrow.x < VCP_INFO_BALLOON_UPPER_MIN_X + VCP_INFO_BALLOON_UPPER_SUIT_X)
    {
        setPos(0, arrow.y);      
    }
    else if (arrow.x < parentWidth - totalWidth + VCP_INFO_BALLOON_UPPER_SUIT_X)
    {
        setPos(arrow.x - VCP_INFO_BALLOON_UPPER_ARROW_WIDTH/2 - VCP_INFO_BALLOON_UPPER_SUIT_X, arrow.y);
    }
    else if (arrow.x < parentWidth - VCP_INFO_BALLOON_UPPER_MIN_X)
    {
        setPos(parentWidth - totalWidth, arrow.y);
    }
    else
    {
        //VFX_DEV_ASSERT(0);
        setPos(getParentFrame()->getSize().width - totalWidth, arrow.y);
        arrowX = parentWidth - VCP_INFO_BALLOON_UPPER_MIN_X;
        m_backgroundCenter->setImgContent(VfxImageSrc(VCP_IMG_INFO_BALLOON_BG_CENTER_RIGHT));
    }

    VfxS32 leftWidth = arrowX - getPos().x - VCP_INFO_BALLOON_UPPER_ARROW_WIDTH/2;

    m_backgroundLeft->setSize(
                            leftWidth, 
                            VCP_INFO_BALLOON_UPPER_HEIGHT - VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT
                            );
    m_backgroundCenter->setPos(leftWidth, 0);
    
    m_backgroundRight->setPos(leftWidth + VCP_INFO_BALLOON_UPPER_ARROW_WIDTH, VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT);
    m_backgroundRight->setSize(
                            totalWidth - VCP_INFO_BALLOON_UPPER_ARROW_WIDTH - leftWidth,
                            VCP_INFO_BALLOON_UPPER_HEIGHT - VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT
                            );
    
}

void VcpInfoBalloonUpperItem::show(const VfxPoint &arrow)
{
    
    adjustPos(arrow);
	setOpacity(0.0);
    VFX_OBJ_CREATE(m_opacityTimeline, VfxFloatTimeline, this);
    
    m_opacityTimeline->setTarget(this);
    m_opacityTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_opacityTimeline->setDurationTime(VCP_INFO_BALLOON_FADING_TIME);

    m_opacityTimeline->setFromValue(0);
    m_opacityTimeline->setToValue(1.0f);

    m_opacityTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    
    m_opacityTimeline->start();
    m_state = VCP_INFO_BALLOON_ANIMATION_STATE_FLYING;

    VFX_OBJ_CREATE(m_durationTimer, VfxTimer, this);
    m_durationTimer->setStartDelay(VCP_INFO_BALLOON_FLYING_TIME + VCP_INFO_BALLOON_STAYING_TIME);
    m_durationTimer->m_signalTick.connect(this, &VcpInfoBalloonUpperItem::timeOut);
    m_durationTimer->start();
}


void VcpInfoBalloonUpperItem::onRotate(VfxScreenRotateParam param)
{
    VFX_UNUSED(param);
    if (m_state == VCP_INFO_BALLOON_ANIMATION_STATE_FLYING)
    {
        // close time line and stay there for VCP_INFO_BALLOON_STAYING_TIME;
        VFX_OBJ_CLOSE(m_opacityTimeline);
        m_durationTimer->stop();
        m_durationTimer->setStartDelay(VCP_INFO_BALLOON_STAYING_TIME);
        m_durationTimer->start();
    }
    else if (m_state == VCP_INFO_BALLOON_ANIMATION_STATE_FADING)
    {
        // leave immediately
        VFX_OBJ_CLOSE(m_opacityTimeline);
        m_signalLeaveFinished.emit(this, m_index);
    }
}


/***************************************************************************** 
 * Class VcpInfoBalloonBottomItem 
 *****************************************************************************/  
//VFX_IMPLEMENT_CLASS("VcpInfoBalloonBottomItem", VcpInfoBalloonBottomItem, VfxControl);

VcpInfoBalloonBottomItem::VcpInfoBalloonBottomItem():
    m_exitScreenState(VCP_INFO_BALLOON_ANIMATION_STATE_NONE)
{
}


void VcpInfoBalloonBottomItem::onInit()
{
    setImgContent(VfxImageSrc(VCP_IMG_INFO_BALLOON_BG));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setAnchor(0.5, 0);

    VcpInfoBalloonBaseItem::onInit();
    m_iconFrame->setPos(VCP_INFO_BALLOON_ICON_X, VCP_INFO_BALLOON_BOTTOM_ICON_Y);    
    m_textFrame->setPos(VCP_INFO_BALLOON_TEXT_X, VCP_INFO_BALLOON_BOTTOM_TEXT_Y);
}



void VcpInfoBalloonBottomItem::show()
{
    VfxS32 textWidth = m_textFrame->getSize().width; 
    VfxS32 parentWidth = getParentFrame()->getSize().width;
    VfxS32 parentHeight = getParentFrame()->getSize().height;
    if (textWidth > parentWidth - VCP_INFO_BALLOON_TEXT_X - VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN)
    {
        textWidth = parentWidth - VCP_INFO_BALLOON_TEXT_X - VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN;
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_textFrame->setSize(textWidth, getSize().height);
    }
    setBounds(VfxRect(0, 0, textWidth + VCP_INFO_BALLOON_TEXT_X + VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN, VCP_INFO_BALLOON_BOTTOM_HEIGHT));

    VFX_OBJ_CREATE(m_posTimeline, VfxPointTimeline, this);
    m_posTimeline->setTarget(this);

	startPosTimeLine();

    m_state = VCP_INFO_BALLOON_ANIMATION_STATE_NONE;

    // workaround for timeline reset when screen changed
    setPos(VfxPoint(parentWidth/2, parentHeight + VCP_INFO_BALLOON_BOTTOM_Y));

    VFX_OBJ_CREATE(m_durationTimer, VfxTimer, this);
    m_durationTimer->setStartDelay(VCP_INFO_BALLOON_FLYING_TIME + VCP_INFO_BALLOON_STAYING_TIME);
    m_durationTimer->m_signalTick.connect(this, &VcpInfoBalloonBottomItem::timeOut);
    m_durationTimer->start();
}

void  VcpInfoBalloonBottomItem::startPosTimeLine()
{
	VfxS32 parentWidth = getParentFrame()->getSize().width;
	VfxS32 parentHeight = getParentFrame()->getSize().height;

	m_posTimeline->setFromValue(VfxPoint(parentWidth/2, parentHeight + VCP_INFO_BALLOON_BOTTOM_Y + VCP_INFO_BALLOON_BOTTOM_Y_DISTANCE));
	m_posTimeline->setToValue(VfxPoint(parentWidth/2, parentHeight + VCP_INFO_BALLOON_BOTTOM_Y));
	m_posTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
	m_posTimeline->setDurationTime(VCP_INFO_BALLOON_FLYING_TIME);
	m_posTimeline->m_signalStarted.connect(this, &VcpInfoBalloonBottomItem::startFly);
	m_posTimeline->m_signalStopped.connect(this, &VcpInfoBalloonBottomItem::finishFly);
	m_posTimeline->start();
}

        
//void VcpInfoBalloonBottomItem::leave()
//{
//    VFX_OBJ_CLOSE(m_durationTimer);
//    VFX_OBJ_CREATE(m_opacityTimeline, VfxFloatTimeline, this);
//
//    m_opacityTimeline->setTarget(this);
//    m_opacityTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
//    m_opacityTimeline->setDurationTime(VCP_INFO_BALLOON_FADING_TIME);
//
//    m_opacityTimeline->setIsFromCurrent(VFX_TRUE);
//    m_opacityTimeline->setToValue(0.0f);
//
//    m_opacityTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
//    m_opacityTimeline->m_signalStopped.connect(this, &VcpInfoBalloonBottomItem::finishState);
//    m_opacityTimeline->start();
//    m_state = VCP_INFO_BALLOON_ANIMATION_STATE_FADING;
//}


void VcpInfoBalloonBottomItem::startFly(VfxBaseTimeline *timeline)
{
    m_state = VCP_INFO_BALLOON_ANIMATION_STATE_FLYING;
}


void VcpInfoBalloonBottomItem::finishFly(VfxBaseTimeline *timeline, VfxBool stop)
{
    if (stop)
    {
        m_state = VCP_INFO_BALLOON_ANIMATION_STATE_STAYING;
    }
    else
    {
        m_state = VCP_INFO_BALLOON_ANIMATION_STATE_NONE;
    }
}


//void VcpInfoBalloonBottomItem::finishState(VfxBaseTimeline *timeline, VfxBool stop)
//{
//    m_signalLeaveFinished.emit(this, m_index);
//}


//void VcpInfoBalloonBottomItem::exit()
//{
//    VcpInfoBalloonBottomItem *self = this;
//    VFX_OBJ_CLOSE(self);
//}

void VcpInfoBalloonBottomItem::onRotate(VfxScreenRotateParam param)
{
    VFX_UNUSED(param);
	VfxS32 parentWidth = getParentFrame()->getSize().width;
	VfxS32 parentHeight = getParentFrame()->getSize().height;

	if (m_textFrame != NULL)
	{
		VfxS32 textWidth = m_textFrame->getSize().width; 
    
		if (textWidth > parentWidth - VCP_INFO_BALLOON_TEXT_X - VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN)
		{
			textWidth = parentWidth - VCP_INFO_BALLOON_TEXT_X - VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN;
			m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
			m_textFrame->setSize(textWidth, getSize().height);
			setBounds(VfxRect(0, 0, textWidth + VCP_INFO_BALLOON_TEXT_X + VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN, VCP_INFO_BALLOON_BOTTOM_HEIGHT));
		}
	}
    
    if (m_state == VCP_INFO_BALLOON_ANIMATION_STATE_FLYING)
    {
        // close time line and stay there for VCP_INFO_BALLOON_STAYING_TIME;
        VFX_OBJ_CLOSE(m_posTimeline);
        // workaround for timeline reset when screen changed
        setPos(VfxPoint(parentWidth/2, parentHeight + VCP_INFO_BALLOON_BOTTOM_Y));
        if (m_durationTimer)
		{
        	m_durationTimer->stop();
        	m_durationTimer->setStartDelay(VCP_INFO_BALLOON_STAYING_TIME);
        	m_durationTimer->start();
		}
    }
    else if (m_state == VCP_INFO_BALLOON_ANIMATION_STATE_FADING)
    {
        // leave immediately
        VFX_OBJ_CLOSE(m_opacityTimeline);
        m_signalLeaveFinished.emit(this, m_index);
    }
	else if (m_state == VCP_INFO_BALLOON_ANIMATION_STATE_STAYING)
	{
        setPos(VfxPoint(parentWidth/2, parentHeight + VCP_INFO_BALLOON_BOTTOM_Y));
        
	}
    else if (m_state == VCP_INFO_BALLOON_ANIMATION_STATE_NONE)
    {
		setPos(VfxPoint(parentWidth/2, parentHeight + VCP_INFO_BALLOON_BOTTOM_Y));		
		if (m_posTimeline)
		{
			startPosTimeLine();
		}
    }
}


void VcpInfoBalloonBottomItem::onScreenEnter()
{
    if ((m_exitScreenState == VCP_INFO_BALLOON_ANIMATION_STATE_NONE && m_state != VCP_INFO_BALLOON_ANIMATION_STATE_NONE) ||
        (m_exitScreenState == VCP_INFO_BALLOON_ANIMATION_STATE_FLYING && m_state == VCP_INFO_BALLOON_ANIMATION_STATE_STAYING) || 
		(m_exitScreenState == VCP_INFO_BALLOON_ANIMATION_STATE_NONE && m_state == VCP_INFO_BALLOON_ANIMATION_STATE_NONE))
    {
        if (m_posTimeline != NULL && m_durationTimer != NULL)
        {
            VFX_OBJ_CLOSE(m_durationTimer);
            VFX_OBJ_CLOSE(m_posTimeline);

            show();
        }
    }
}


void VcpInfoBalloonBottomItem::onScreenExit()
{
    m_exitScreenState = m_state;
}


/***************************************************************************** 
 * Class VcpInfoBalloon 
 *****************************************************************************/  
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VcpInfoBalloon);

VcpInfoBalloon::VcpInfoBalloon() :
    upperIndex(0),
    bottomIndex(0)
{
    VfxS32 i;
    for (i = 0; i < VCP_INFO_BALLOON_MAX_NUMBER; i++)
    {
        m_upperBalloon[i] = NULL;
        m_bottomBalloon[i] = NULL;
    }
}

void VcpInfoBalloon::onInit()
{
    VfxObject::onInit();
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->m_signalRotated.connect(this, &VcpInfoBalloon::onRotate);
    topLevel->m_signalActiveScreenEntered.connect(this, &VcpInfoBalloon::onActiveScreenEnter);
    topLevel->m_signalActiveScreenExit.connect(this, &VcpInfoBalloon::onActiveScreenExit);
}

void VcpInfoBalloon::addItem(VfxResId icon, const VfxWString &text)
{
    if (m_bottomBalloon[bottomIndex])
    {
        VfxS32 preIndex = (bottomIndex + VCP_INFO_BALLOON_MAX_NUMBER - 1) % VCP_INFO_BALLOON_MAX_NUMBER;
        if (m_bottomBalloon[preIndex])
        {
            m_bottomBalloon[preIndex]->exit();
			m_bottomBalloon[preIndex] = NULL;
        }
        m_bottomBalloon[bottomIndex]->leave();
    }
	VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    bottomIndex ++;
    bottomIndex %= VCP_INFO_BALLOON_MAX_NUMBER;
    
    VFX_OBJ_CREATE(m_bottomBalloon[bottomIndex], VcpInfoBalloonBottomItem, this);
    m_bottomBalloon[bottomIndex]->setText(text);
    m_bottomBalloon[bottomIndex]->setImage(VfxImageSrc(icon));
    m_bottomBalloon[bottomIndex]->m_signalLeaveFinished.connect(this, &VcpInfoBalloon::killBalloonBottomItem);
    m_bottomBalloon[bottomIndex]->setIndex(bottomIndex);
    topLevel->addChildFrame(m_bottomBalloon[bottomIndex]);
    m_bottomBalloon[bottomIndex]->setPosZ(VCP_INFO_BALLOON_Z_ORDER);
    m_bottomBalloon[bottomIndex]->show();
	if (topLevel->getActiveScreenState() == VFX_TOP_LEVEL_ACTIVE_SCREEN_STATE_ENTERING)
	{
		m_bottomBalloon[bottomIndex]->setHidden(VFX_TRUE);
	}
}


void VcpInfoBalloon::addItem(VfxResId icon, const VfxWString &text, const VfxPoint &arrowPos)
{
    if (m_upperBalloon[upperIndex])
    {
        VfxS32 preIndex = (upperIndex + VCP_INFO_BALLOON_MAX_NUMBER - 1) % VCP_INFO_BALLOON_MAX_NUMBER;
        if (m_upperBalloon[preIndex])
        {
            m_upperBalloon[preIndex]->exit();
			m_upperBalloon[preIndex] = NULL;
        }
        m_upperBalloon[upperIndex]->leave();
    }
    upperIndex ++;
    upperIndex %= VCP_INFO_BALLOON_MAX_NUMBER;
    
    VFX_OBJ_CREATE(m_upperBalloon[upperIndex], VcpInfoBalloonUpperItem, this);
    m_upperBalloon[upperIndex]->setText(text);
    m_upperBalloon[upperIndex]->setImage(VfxImageSrc(icon));
    m_upperBalloon[upperIndex]->m_signalLeaveFinished.connect(this, &VcpInfoBalloon::killBalloonUpperItem);
    m_upperBalloon[upperIndex]->setIndex(upperIndex);
    VFX_OBJ_GET_INSTANCE(VfxTopLevel)->addChildFrame(m_upperBalloon[upperIndex]);
    m_upperBalloon[upperIndex]->setPosZ(VCP_INFO_BALLOON_Z_ORDER);
    m_upperBalloon[upperIndex]->show(arrowPos);
}


VfxResId VcpInfoBalloon::selectIcon(VcpInfoBalloonTypeEnum type)
{
    VfxResId icon = VCP_IMG_INFO_BALLOON_FAILURE;
    switch (type)
    {
        case VCP_INFO_BALLOON_TYPE_FAILURE:
            icon = VCP_IMG_INFO_BALLOON_FAILURE;
            break;
        case VCP_INFO_BALLOON_TYPE_INFO:
            icon = VCP_IMG_INFO_BALLOON_INFO;
            break;
        case VCP_INFO_BALLOON_TYPE_WARNING:
            icon = VCP_IMG_INFO_BALLOON_WARNING;
            break;
        case VCP_INFO_BALLOON_TYPE_SUCCESS:
            icon = VCP_IMG_INFO_BALLOON_SUCCESS;
            break;
        case VCP_INFO_BALLOON_TYPE_PROGRESS:
            icon = VCP_IMG_INFO_BALLOON_PROGRESS;
            break;
        default:
            VFX_ASSERT(0);
    }
    return icon;
}


void VcpInfoBalloon::addItem(VcpInfoBalloonTypeEnum type, const VfxWString &text)
{
    VfxResId icon = selectIcon(type);
    addItem(icon, text);
}


void VcpInfoBalloon::addItem(VcpInfoBalloonTypeEnum type, const VfxWString &text, const VfxPoint &arrowPos)
{
    VfxResId icon = selectIcon(type);
    addItem(icon, text, arrowPos);
}


void VcpInfoBalloon::onActiveScreenEnter(VfxWeakPtr<VfxScreen> scr)
{
    if (m_upperBalloon[upperIndex])
    {
        m_upperBalloon[upperIndex]->setHidden(VFX_FALSE);
    }

    if (m_bottomBalloon[bottomIndex])
    {
        m_bottomBalloon[bottomIndex]->setHidden(VFX_FALSE);
        m_bottomBalloon[bottomIndex]->onScreenEnter();
    }
}


void VcpInfoBalloon::onActiveScreenExit(VfxWeakPtr<VfxScreen> scr)
{
    if (m_upperBalloon[upperIndex])
    {
        m_upperBalloon[upperIndex]->setHidden(VFX_TRUE);
    }

	for (VfxU16 i = 0; i < VCP_INFO_BALLOON_MAX_NUMBER; i++)
    {
		if (m_bottomBalloon[i])
		{
            m_bottomBalloon[i]->onScreenExit();
			m_bottomBalloon[i]->setHidden(VFX_TRUE);
		}
    }
}


void VcpInfoBalloon::killBalloonUpperItem(VfxObject *object, VfxS32 index)
{
    m_upperBalloon[index]->exit();
    m_upperBalloon[index] = NULL;
	m_signalBallonClosed.emit(this);
}


void VcpInfoBalloon::killBalloonBottomItem(VfxObject *object, VfxS32 index)
{
    m_bottomBalloon[index]->exit();
    m_bottomBalloon[index] = NULL;
	m_signalBallonClosed.emit(this);
}


void VcpInfoBalloon::moveCurrentUpperItem(const VfxPoint &arrowPos)
{
    if (m_upperBalloon[upperIndex])
    {
        m_upperBalloon[upperIndex]->adjustPos(arrowPos);
    }
}


void VcpInfoBalloon::cancelCurrentUpperItem()
{
    if (m_upperBalloon[upperIndex])
    {
        m_upperBalloon[upperIndex]->leave();
        //m_upperBalloon[upperIndex]->exit();
        //m_upperBalloon[upperIndex] = NULL;
    }
}


void VcpInfoBalloon::cancelCurrentBottomItem()
{
    if (m_bottomBalloon[bottomIndex])
    {
        m_bottomBalloon[bottomIndex]->leave();
        //m_bottomBalloon[bottomIndex]->exit();
        //m_bottomBalloon[bottomIndex] = NULL;
    }
}


void VcpInfoBalloon::onPopupChanged(VfxWeakPtr<VfxBasePopup> popup)
{
    if(popup.get())
    {
        cancelCurrentUpperItem();
        cancelCurrentBottomItem();    
    }
}

void VcpInfoBalloon::onRotate(VfxScreenRotateParam param)
{
    if (m_upperBalloon[upperIndex])
    {
        m_upperBalloon[upperIndex]->onRotate(param);
    }
     
    for (VfxU16 i = 0; i < VCP_INFO_BALLOON_MAX_NUMBER; i++)
	{
		if (m_bottomBalloon[i])
		{
          m_bottomBalloon[i]->onRotate(param);
		}
	}    
}
vrt_allocator_handle VcpInfoBalloon::getAllocator()
{
	return vfx_sys_mem_get_global_allocator();
}


