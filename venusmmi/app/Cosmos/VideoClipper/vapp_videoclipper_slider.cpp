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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_videoclipper_slider.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_VIDEO_CLIPPER__)
#include "vapp_videoclipper_slider.h"
#include "mmi_rp_vapp_videoclipper_slider_def.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_include.h"
#include "MMI_media_app_trc.h"

extern "C"
{
#include "GlobalResDef.h"   
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
* Class VappVideoClipperSliderThumb
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VappVideoClipperSliderThumb", VappVideoClipperSliderThumb, VcpImageButton);

VfxBool VappVideoClipperSliderThumb::onPenInput(VfxPenEvent &event)
{
    VfxS32 position;

    position = event.getRelPos(getParentFrame()).x;        

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_signalThumbPressed.emit(position);
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        m_signalThumbDrag.postEmit(position);
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_signalThumbReleased.postEmit(position);   
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_signalThumbAbort.postEmit(position);
    }
    return VcpImageButton::onPenInput(event);
}


void VappVideoClipperSliderThumb::setInitPos(VfxS32 x, VfxS32 y)
{
    m_initPos.x = x;
    m_initPos.y = y;
}


VfxPoint& VappVideoClipperSliderThumb::getInitPos()
{
    return m_initPos;
}


VFX_IMPLEMENT_CLASS("VappVideoClipperSlider", VappVideoClipperSlider, VfxControl);
VappVideoClipperSlider::VappVideoClipperSlider(): 
    m_length(LCD_WIDTH),
    m_barLength(LCD_WIDTH),    
    m_playThumbValue (0.0),
    m_startThumbValue(0.0),
    m_endThumbValue(1.0),
    m_startThumb(NULL),
    m_endThumb(NULL),
    m_playThumb(NULL),
    m_bar(NULL),
    m_clipperBar(NULL),
    m_playBar(NULL),
    m_min(0.0),
    m_max(100.0),
    m_startThumbOffset(0),
    m_endThumbOffset(0),
    m_minIntervalLength(0),
    m_startThumbFuzzyLength(0),
    m_minClipBarRatio(0.0),
    m_startThumbFuzzyRatio(0.0)
{
}


VappVideoClipperSlider::~VappVideoClipperSlider()
{

}


void VappVideoClipperSlider::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_bar, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_clipperBar, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_playBar, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_startThumb, VappVideoClipperSliderThumb, this);
    VFX_OBJ_CREATE(m_endThumb, VappVideoClipperSliderThumb, this);
    VFX_OBJ_CREATE(m_playThumb, VappVideoClipperSliderThumb, this);   

    m_bar->setAnchor(0.5, 0.5);
    m_bar->setResId(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_HRZT_BG);

    m_clipperBar->setResId(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_HRZT_H);
    m_clipperBar->setAnchor(0, 0.5);
    m_clipperBar->setAutoAnimate(VFX_FALSE);

    m_playBar->setResId(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_PLAY_H);
//    m_playBar->setResId(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_HRZT_BG);
    m_playBar->setAnchor(0, 0.5);
    m_playBar->setAutoAnimate(VFX_FALSE);
    
    VcpStateImage start(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_THUMB_CLIP_START);
    
    m_startThumb->setAnchor(0.5, 1.0);
    m_startThumb->setImage(start);
    m_startThumb->setSize(start.getImageNormal().getSize().width, start.getImageNormal().getSize().height);
    m_startThumb->m_signalThumbPressed.connect(this, &VappVideoClipperSlider::startThumbPressed);
    m_startThumb->m_signalThumbReleased.connect(this, &VappVideoClipperSlider::startThumbReleased);
    m_startThumb->m_signalThumbDrag.connect(this, &VappVideoClipperSlider::startThumbDrag);
    m_startThumb->m_signalThumbAbort.connect(this, &VappVideoClipperSlider::startThumbAbort);
          
    VcpStateImage end(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_THUMB_CLIP_END);

    m_endThumb->setAnchor(0.5, 1.0);
    m_endThumb->setImage(end);
    m_endThumb->setSize(end.getImageNormal().getSize().width, end.getImageNormal().getSize().height);
    m_endThumb->m_signalThumbPressed.connect(this, &VappVideoClipperSlider::endThumbPressed);
    m_endThumb->m_signalThumbReleased.connect(this, &VappVideoClipperSlider::endThumbReleased);
    m_endThumb->m_signalThumbDrag.connect(this, &VappVideoClipperSlider::endThumbDrag);
    m_endThumb->m_signalThumbAbort.connect(this, &VappVideoClipperSlider::endThumbAbort);
    m_endThumb->setAutoAnimate(VFX_FALSE);

    VcpStateImage play(IMG_ID_VAPPP_VDOCLIPPER_SLIDER_THUMB_PLAY);
    m_playThumb->setAnchor(0.5, 0.5);
    m_playThumb->setImage(play);    
    m_playThumb->setSize(play.getImageNormal().getSize().width, play.getImageNormal().getSize().height);
    m_playThumb->m_signalThumbPressed.connect(this, &VappVideoClipperSlider::playThumbPressed);
    m_playThumb->m_signalThumbReleased.connect(this, &VappVideoClipperSlider::playThumbReleased);
    m_playThumb->m_signalThumbDrag.connect(this, &VappVideoClipperSlider::playThumbDrag);
    m_playThumb->m_signalThumbAbort.connect(this, &VappVideoClipperSlider::playThumbAbort);
    m_playThumb->setAutoAnimate(VFX_FALSE);

    m_startThumbOffset = MAX(m_startThumb->getSize().width, m_playThumb->getSize().width) >> 1;
    m_endThumbOffset = MAX(m_endThumb->getSize().width, m_playThumb->getSize().width) >> 1;
}


void VappVideoClipperSlider::setBounds(const VfxRect &value)
{
    VfxRect adjustedRect = value;
    
    m_length = value.size.width;
    adjustedRect.size.width = m_length;
    adjustedRect.size.height = m_startThumb->getSize().height + m_playThumb->getSize().height;
    VfxControl::setBounds(adjustedRect);

    m_startThumb->setPos(m_startThumbOffset, m_startThumb->getBounds().getMaxY());
    m_startThumb->setInitPos(m_startThumb->getPos().x, m_startThumb->getPos().y);
    
    m_bar->setPos(m_length >> 1, m_startThumb->getPos().y);
    m_bar->setSize(
        m_length - (m_startThumbOffset-1)  - (m_endThumbOffset-1), 
        m_bar->getSize().height);
    m_bar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
//    m_bar->setBgColor(VFX_COLOR_GREY);
/*
    m_bar->setSize(
        m_length - m_startThumbOffset- m_endThumbOffset, 
        m_startThumb->getSize().height);
    m_bar->setBgColor(VFX_COLOR_GREY);
*/

    m_endThumb->setPos(
                    m_startThumb->getPos().x + m_bar->getSize().width - 1, 
                    m_startThumb->getPos().y);
    m_endThumb->setInitPos(m_endThumb->getPos().x, m_endThumb->getPos().y);

    m_playThumb->setPos(
                    m_startThumb->getPos().x, 
                    m_startThumb->getPos().y);
    m_playThumb->setInitPos(m_endThumb->getPos().x, m_endThumb->getPos().y);    

    m_clipperBar->setPos(m_startThumb->getPos().x, m_startThumb->getPos().y);
    m_clipperBar->setSize(m_endThumb->getPos().x - m_startThumb->getPos().x + 1, m_bar->getSize().height);
    m_clipperBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_playBar->setPos(m_startThumb->getPos().x, m_startThumb->getPos().y);
    m_playBar->setSize(m_playThumb->getPos().x - m_startThumb->getPos().x + 1, m_bar->getSize().height);
    m_playBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    updatePlayBar();
    
    m_barLength = m_endThumb->getInitPos().x - m_startThumb->getInitPos().x;
}


void VappVideoClipperSlider::setLength(VfxS32 len)
{
    setSize(len,0);
}


void VappVideoClipperSlider::setMinClipBarRatio(VfxFloat value)
{
    m_minClipBarRatio = value;
    
    if (m_minClipBarRatio > 0)
    {
        m_minIntervalLength = getSize().width * m_minClipBarRatio;
        m_minIntervalLength -= (m_startThumbOffset + m_endThumbOffset);
        
        if (m_minIntervalLength < 0)
            m_minIntervalLength = 0;

        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_SLIDER_MINLENGTH, m_minIntervalLength);
    }
    
}


void VappVideoClipperSlider::setStartThumbFuzzyRatio(VfxFloat value)
{
    m_startThumbFuzzyRatio = value;

    if (m_startThumbFuzzyRatio > 0)
    {
        m_startThumbFuzzyLength = getSize().width * m_startThumbFuzzyRatio;
        if (m_startThumbFuzzyLength < 0)
            m_startThumbFuzzyLength = 0;
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPER_SLIDER_FUZZYLENGTH, m_startThumbFuzzyLength);
    }
}

    
void VappVideoClipperSlider::setPlayThumbValue(VfxFloat value)
{
    m_playThumbValue = value;

    VfxS32 position = ValueToPosition(value);
    m_playThumb->setPos(
                    position, 
                    m_playThumb->getInitPos().y);
    updatePlayBar();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_SET_PLAY_VALUE, position, m_playBar->getHidden());

}


void VappVideoClipperSlider::setStartThumbValue(VfxFloat value)
{
    m_startThumbValue = value;

    VfxS32 position = ValueToPosition(value);

    m_startThumb->setPos(
                    position, 
                    m_startThumb->getInitPos().y);

    updateClipBar();
    updatePlayBar();
}


void VappVideoClipperSlider::setEndThumbValue(VfxFloat value)
{
    m_endThumbValue = value;

    VfxS32 position = ValueToPosition(value);

    m_endThumb->setPos(
                    position + m_startThumbOffset, 
                    m_endThumb->getInitPos().y);

    updateClipBar();
}


VfxPoint& VappVideoClipperSlider::getInitStartThumbPos()
{
    return m_startThumb->getInitPos();
}


VfxPoint& VappVideoClipperSlider::getInitEndThumbPos()
{
    return m_endThumb->getInitPos();
}


VfxPoint& VappVideoClipperSlider::getStartThumbPos()
{
    VfxPoint pos = m_startThumb->getPos();
    return pos;
}
    

VfxPoint& VappVideoClipperSlider::getEndThumbPos()
{
    VfxPoint pos = m_endThumb->getPos();
    return pos;
}


VfxPoint& VappVideoClipperSlider::getPlayThumbPos()
{
    VfxPoint pos = m_playThumb->getPos();
    return pos;
}


VfxBool VappVideoClipperSlider::onKeyInput(VfxKeyEvent &event)
{
    return VFX_TRUE;
}


VfxFloat VappVideoClipperSlider::PositionToValue(VfxS32 pos)
{
    VfxFloat value;
    VfxS32 PosInBar = pos - m_startThumb->getInitPos().x;

    value = ((VfxFloat)(PosInBar) * ((m_max - m_min) / (VfxFloat)(m_barLength))) + m_min;
    return value;
}


VfxS32 VappVideoClipperSlider::ValueToPosition(VfxFloat value)
{
    VfxS32 position;

    position = (VfxS32)(((value - m_min) * m_barLength)/(m_max - m_min));

    position += m_startThumb->getInitPos().x;
    return position;
}


void VappVideoClipperSlider::startThumbPressed(VfxS32 pos)
{
    checkStartThumbPos(pos);
    
    m_startThumbValue = PositionToValue(m_startThumb->getPos().x);
    m_signalStartThumbPressed.emit(this, m_startThumbValue);

    m_startThumb->setIsHighlight(VFX_TRUE);
    m_playBar->setHidden(VFX_TRUE);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_VDOCLIPPERSLIDER_START_PRESSED, pos);
}


void VappVideoClipperSlider::startThumbReleased(VfxS32 pos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_START_RELEASE, pos);
        
    checkStartThumbPos(pos);
    
    m_startThumbValue = PositionToValue(m_startThumb->getPos().x);
    m_signalStartThumbReleased.emit(this, m_startThumbValue);

    VfxU32 temp = m_startThumbValue*100;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_START_RELEASE_VALUE, temp);
    
    m_startThumb->setIsHighlight(VFX_FALSE);
    m_playBar->setHidden(VFX_FALSE);
}


void VappVideoClipperSlider::startThumbDrag(VfxS32 pos)
{
    checkStartThumbPos(pos);
    
    m_startThumbValue = PositionToValue(m_startThumb->getPos().x);
    m_signalStartThumbDrag.emit(this, m_startThumbValue);
}


void VappVideoClipperSlider::startThumbAbort(VfxS32 pos)
{
    checkStartThumbPos(pos);
    
    m_startThumbValue = PositionToValue(m_startThumb->getPos().x);
    m_signalStartThumbAbort.emit(this, m_startThumbValue);
}


void VappVideoClipperSlider::endThumbPressed(VfxS32 pos)
{
    m_playBar->setHidden(VFX_TRUE);
    checkEndThumbPos(pos);
    
    m_endThumbValue = PositionToValue(m_endThumb->getPos().x);   
    m_signalEndThumbPressed.emit(this, m_endThumbValue);

    m_endThumb->setIsHighlight(VFX_TRUE);
    m_clipperBar->setAutoAnimate(VFX_FALSE);

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_END_PRESSED, pos);
}


void VappVideoClipperSlider::endThumbReleased(VfxS32 pos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_END_RELEASE, pos);
    
    checkEndThumbPos(pos);  
    m_endThumbValue = PositionToValue(m_endThumb->getPos().x);
    
    VfxU32 temp = m_endThumbValue*100;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_END_RELEASE_VALUE, temp);
        
    m_signalEndThumbReleased.emit(this, m_endThumbValue);

    m_endThumb->setIsHighlight(VFX_FALSE);
    m_playBar->setHidden(VFX_FALSE);
}


void VappVideoClipperSlider::endThumbDrag(VfxS32 pos)
{
    checkEndThumbPos(pos);

    m_endThumbValue = PositionToValue(m_endThumb->getPos().x);
    m_signalEndThumbDrag.emit(this, m_endThumbValue);
}


void VappVideoClipperSlider::endThumbAbort(VfxS32 pos)
{
    checkEndThumbPos(pos);

    m_endThumbValue = PositionToValue(m_endThumb->getPos().x);
    m_signalEndThumbAbort.emit(this, m_endThumbValue);
}


void VappVideoClipperSlider::playThumbPressed(VfxS32 pos)
{
    m_playBar->setHidden(VFX_TRUE);
    checkPlayThumbPos(pos);

    m_playThumbValue = PositionToValue(m_playThumb->getPos().x);
    m_signalPlayThumbPressed.emit(this, m_playThumbValue);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_VDOCLIPPERSLIDER_PLAY_PRESSED, pos);
}


void VappVideoClipperSlider::playThumbReleased(VfxS32 pos)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_PLAY_RELEASE, pos);
    checkPlayThumbPos(pos);
        
    m_playThumbValue = PositionToValue(m_playThumb->getPos().x);
    m_signalPlayThumbReleased.emit(this, m_playThumbValue);

    VfxU32 temp = m_playThumbValue*100;
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_VDOCLIPPERSLIDER_PLAY_RELEASE_VALUE, temp);

    m_playBar->setHidden(VFX_FALSE);
}


void VappVideoClipperSlider::playThumbDrag(VfxS32 pos)
{
    checkPlayThumbPos(pos);
    
    m_playThumbValue = PositionToValue(m_playThumb->getPos().x);
    m_signalPlayThumbDrag.emit(this, m_playThumbValue);
}


void VappVideoClipperSlider::playThumbAbort(VfxS32 pos)
{
    checkPlayThumbPos(pos);
    
    m_playThumbValue = PositionToValue(m_playThumb->getPos().x);
    m_signalPlayThumbAbort.emit(this, m_playThumbValue);
}


void VappVideoClipperSlider::checkStartThumbPos(VfxS32 pos)
{
    if (pos + m_startThumbOffset + (m_minIntervalLength - m_startThumbFuzzyLength) < m_endThumb->getPos().x - m_endThumbOffset &&
        pos >= m_startThumb->getInitPos().x)
    {
        m_startThumb->setPos(pos, m_startThumb->getPos().y);
    }
    else if (pos + m_startThumbOffset > m_endThumb->getPos().x - m_endThumbOffset)
    {
        VfxS32 startPos = m_endThumb->getPos().x - (m_endThumbOffset - 1) - (m_startThumbOffset - 1) - (m_minIntervalLength - m_startThumbFuzzyLength);

        if (startPos < m_startThumbOffset)
            startPos = m_startThumbOffset;
        
        m_startThumb->setPos(
                        startPos, 
                        m_startThumb->getPos().y);
    }
    else if (pos < m_startThumb->getInitPos().x)
    {
        m_startThumb->setPos(m_startThumb->getInitPos().x, m_startThumb->getPos().y);
    }

    updateClipBar();
    updatePlayBar();
    
}


void VappVideoClipperSlider::checkEndThumbPos(VfxS32 pos)
{
    if (pos - m_endThumbOffset - m_minIntervalLength > m_startThumb->getPos().x + m_startThumbOffset &&
        pos <= m_endThumb->getInitPos().x)
    {
        m_endThumb->setPos(pos, m_startThumb->getPos().y);
    }
    else if (pos - m_endThumbOffset - m_minIntervalLength < m_startThumb->getPos().x + m_startThumbOffset)
    {
        VfxS32 endPos = m_startThumb->getPos().x + (m_startThumbOffset - 1)  + (m_endThumbOffset - 1) + m_minIntervalLength;

        if (endPos > getSize().width - m_endThumbOffset)
            endPos = getSize().width - m_endThumbOffset;
        
        m_endThumb->setPos(
                        endPos, 
                        m_endThumb->getPos().y);
    }
    else if (pos > m_endThumb->getInitPos().x)
    {
        m_endThumb->setPos(m_endThumb->getInitPos().x, m_endThumb->getPos().y);
    }
    updateClipBar();
}


void VappVideoClipperSlider::checkPlayThumbPos(VfxS32 pos)
{
    if (pos >= m_startThumb->getPos().x && pos <= m_endThumb->getPos().x)
    {
        m_playThumb->setPos(pos, m_playThumb->getPos().y);
    }
    else if (pos < m_startThumb->getPos().x)
    {
        m_playThumb->setPos(m_startThumb->getPos().x, m_playThumb->getPos().y);
    }
    else if (pos > m_endThumb->getPos().x)
    {
        m_playThumb->setPos(m_endThumb->getPos().x, m_playThumb->getPos().y);
    }
    updatePlayBar();
}


void VappVideoClipperSlider::updateClipBar()
{
    m_clipperBar->setPos(m_startThumb->getPos().x, m_startThumb->getPos().y);
    m_clipperBar->setSize(m_endThumb->getPos().x - m_startThumb->getPos().x + 1, m_bar->getSize().height);
}

void VappVideoClipperSlider::updatePlayBar()
{   
    if (m_playThumb->getPos().x - m_startThumb->getPos().x > 1)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_FALSE); 
        m_playBar->setPos(m_startThumb->getPos().x, m_startThumb->getPos().y);
        m_playBar->setSize(m_playThumb->getPos().x - m_startThumb->getPos().x + 1, m_bar->getSize().height);
        VfxAutoAnimate::commit();
    }
    else
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);        
        m_playBar->setPos(m_startThumb->getPos().x, m_startThumb->getPos().y);
        m_playBar->setSize(0, m_bar->getSize().height);
        VfxAutoAnimate::commit();
    }

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_VDOCLIPPERSLIDER_PLAYBAR_UPDATE, m_playBar->getHidden(), m_playBar->getSize().width);
}
    
#endif /* __MMI_VIDEO_CLIPPER__ */
