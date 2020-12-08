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
 *  vcp_progress_indicator.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Progress indicator components
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "vcp_progress_indicator.h"
#include "mmi_rp_srv_venus_component_progress_indicator_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpProgressIndicatorBase 
 *****************************************************************************/  
//VFX_IMPLEMENT_CLASS("VcpProgressIndicatorBase", VcpProgressIndicatorBase, VfxControl);

VcpProgressIndicatorBase::VcpProgressIndicatorBase():
    m_fgFrame(NULL),
    m_bgFrame(NULL),
    m_barFrame(NULL),
    m_isFrameAnimate(VFX_TRUE)
{
}


void VcpProgressIndicatorBase::onInit()
{
    VfxControl::onInit();

    //setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_bgFrame, VfxFrame, this);
    m_bgFrame->setImgContent(VfxImageSrc(VCP_IMG_PROGRESS_INDICATOR_BG));
    m_bgFrame->setSize(0, VCP_PROGRESS_INDICATOR_FG_OFFSET + VCP_PROGRESS_INDICATOR_HEIGHT + VCP_PROGRESS_INDICATOR_FG_OFFSET);
    m_bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_fgFrame, VfxFrame, this);
    m_fgFrame->setPos(VCP_PROGRESS_INDICATOR_FG_OFFSET,VCP_PROGRESS_INDICATOR_FG_OFFSET);
    m_fgFrame->setSize(0, VCP_PROGRESS_INDICATOR_HEIGHT);
        
    VFX_OBJ_CREATE(m_barFrame, VfxImageFrame, m_fgFrame);
    m_barFrame->setImgContent(VfxImageSrc(VCP_IMG_PROGRESS_INDICATOR_FG));
    m_barFrame->setPos(0 - VCP_PROGRESS_INDICATOR_PATTERN_WIDTH, 0);
    m_barFrame->setSize(VCP_PROGRESS_INDICATOR_WIDTH_MAX, VCP_PROGRESS_INDICATOR_HEIGHT);
    m_barFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_frameAnimate, VfxPointTimeline, this);
    m_frameAnimate->setTarget(m_barFrame);

    VfxPoint point = m_barFrame->getPos();
    m_frameAnimate->setFromValue(point);
    
    point.x += VCP_PROGRESS_INDICATOR_PATTERN_WIDTH;
    
    m_frameAnimate->setToValue(point);
    m_frameAnimate->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
    m_frameAnimate->setDurationTime(VCP_PROGRESS_INDICATOR_PATTERN_MOTION_TIME);
    m_frameAnimate->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_frameAnimate->start();
}


void VcpProgressIndicatorBase::setWidth(VfxU32 width)
{
    VfxControl::setBounds(VfxRect(0, 0, width, VCP_PROGRESS_INDICATOR_FG_OFFSET + VCP_PROGRESS_INDICATOR_HEIGHT + VCP_PROGRESS_INDICATOR_FG_OFFSET));
    m_fgFrame->setSize(getSize().width - 2 * VCP_PROGRESS_INDICATOR_FG_OFFSET, VCP_PROGRESS_INDICATOR_HEIGHT);
    m_bgFrame->setSize(getSize());
}


void VcpProgressIndicatorBase::pauseProgress() 
{
    if(!m_isFrameAnimate)
    {
        return;
    }
    m_frameAnimate->stop();
    m_isFrameAnimate = VFX_FALSE;
}


void VcpProgressIndicatorBase::resumeProgress() 
{
    if(m_isFrameAnimate)
    {
        return;
    }
    m_frameAnimate->start();
    m_isFrameAnimate = VFX_TRUE;
}


/***************************************************************************** 
 * Class VcpProgressIndicator 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpProgressIndicator", VcpProgressIndicator, VcpProgressIndicatorBase);

VcpProgressIndicator::VcpProgressIndicator():
    m_progressValue(0.0),
    m_maxProgressValue(1.0),
    m_anime(NULL),
    m_isAnimate(VFX_TRUE)
{
}


void VcpProgressIndicator::onInit()
{
    VcpProgressIndicatorBase::onInit();
    m_fgFrame->setSize(0,VCP_PROGRESS_INDICATOR_HEIGHT);
    VFX_OBJ_CREATE(m_anime, VfxSizeTimeline, this);
}


void VcpProgressIndicator::adjustProgress(VfxBool is_anim)
{
    VfxS32 width;
    VfxSize size;
    
    width = (m_progressValue/m_maxProgressValue) * (VfxFloat)(getSize().width - 2 * VCP_PROGRESS_INDICATOR_FG_OFFSET);
    size = m_fgFrame->getSize();

    if(is_anim)
    {
        m_anime->setTarget(m_fgFrame);
        m_anime->setFromValue(size);
        size.width = width;
        m_anime->setToValue(size);

        m_anime->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE);
        m_anime->setDurationTime(VCP_PROGRESS_INDICATOR_PATTERN_MOTION_TIME);
        m_anime->start();
    }
    else
    {
        size.width = width;
        m_anime->stop();
    }
	m_fgFrame->setSize(size);
	if(m_progressValue == 0.0f || m_progressValue == m_maxProgressValue)
	{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);        
    renderer->mustShowNextFrame(); 
	} 
}


VfxBool VcpProgressIndicator::setMaxProgressValue(VfxFloat max_progress_value)
{
    if(max_progress_value < m_progressValue)
    {
        return VFX_FALSE;
    }

    if((max_progress_value > 0.0) && (max_progress_value <= 1.0))
    {
        m_maxProgressValue = max_progress_value;
        adjustProgress(m_isAnimate);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


void VcpProgressIndicator::setIsAnimate(VfxBool isAnim)
{
    if(m_isAnimate != isAnim)
    {
        if(!isAnim)
        {
            m_anime->stop();
        }
        m_isAnimate = isAnim;
    }
}


VfxBool VcpProgressIndicator::setProgress(VfxFloat progress_value)
{
    if((progress_value >= 0.0) && (progress_value <= m_maxProgressValue))
    {
        m_progressValue = progress_value;
        adjustProgress(m_isAnimate);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


//Override
void VcpProgressIndicator::setWidth(VfxU32 width)
{
    VfxSize size = m_fgFrame->getSize();
    VcpProgressIndicatorBase::setWidth(width);
    m_fgFrame->setSize(size);
    adjustProgress(VFX_FALSE);
}


