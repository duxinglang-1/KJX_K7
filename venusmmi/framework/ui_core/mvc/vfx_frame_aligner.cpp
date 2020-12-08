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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_frame_aligner.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_frame_aligner.h"

// For VfxFrame
#include "vfx_frame.h"


/***************************************************************************** 
 * Class VfxFrameAligner
 *****************************************************************************/

VfxFrameAligner::VfxFrameAligner() :
    m_mode(0)
{
    for (VfxS32 i = 0 ; i < VFX_FRAME_ALIGNER_SIDE_END_OF_ENUM ; i ++)
    {
        m_dist[i] = 0;
    }
}


void VfxFrameAligner::setAlignment(VfxFrameAlignerSideEnum side, VfxFrameAlignerModeEnum mode, VfxS32 dist)
{
    // error check
    if ((side >= VFX_FRAME_ALIGNER_SIDE_END_OF_ENUM) || (mode >= VFX_FRAME_ALIGNER_MODE_END_OF_ENUM))
    {
        return;
    }

    m_mode = (m_mode & (~(0x3 << (side * 2)))) | (mode << (side * 2));
    m_dist[side] = dist;
}


VfxFrameAlignerModeEnum VfxFrameAligner::getAlignMode(VfxFrameAlignerSideEnum side)
{
    return (VfxFrameAlignerModeEnum)((m_mode >> (side * 2)) & 0x3);
}


VfxS32 VfxFrameAligner::getAlignDist(VfxFrameAlignerSideEnum side)
{
    return m_dist[side];
}


VfxBool VfxFrameAligner::isEmpty()
{
    return (m_mode == 0) ? (VFX_TRUE) : (VFX_FALSE);
}


void VfxFrameAligner::alignChildFrames(VfxFrame *targetFrame)
{
    for (VfxFrame *f = targetFrame->getFirstChildFrame() ; f != NULL ; f = f->getNextFrame())
    {
        f->alignParent();
    }
}


void VfxFrameAligner::alignParentFrame(VfxFrame *targetFrame)
{
    VfxFrameAligner *aligner = targetFrame->getAligner();
    if (aligner == NULL)
    {
        return;
    }

    VfxFrame *pframe = targetFrame->getParentFrame();
    VfxRect pbounds = pframe->getBounds();
    VfxRect bounds = targetFrame->getBounds();
    VfxRect b = targetFrame->convertRectTo(bounds, pframe);
    VfxS32 x1 = b.getMinX(), y1 = b.getMinY(), x2 = b.getMaxX(), y2 = b.getMaxY();
    VfxFrameAlignerModeEnum mode1, mode2;
    VfxS32 dist;

    // adjust left and right
    mode1 = aligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_LEFT);
    mode2 = aligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_RIGHT);
    if (mode1 != VFX_FRAME_ALIGNER_MODE_NONE)
    {
        dist = aligner->getAlignDist(VFX_FRAME_ALIGNER_SIDE_LEFT);
        if (mode1 == VFX_FRAME_ALIGNER_MODE_SIDE)
        {
            x1 = pbounds.getMinX() - dist;
        }
        else if (mode1 == VFX_FRAME_ALIGNER_MODE_MID)
        {
            x1 = pbounds.getMidX() - dist;
        }
    }
    if (mode2 != VFX_FRAME_ALIGNER_MODE_NONE)
    {
        dist = aligner->getAlignDist(VFX_FRAME_ALIGNER_SIDE_RIGHT);
        if (mode2 == VFX_FRAME_ALIGNER_MODE_SIDE)
        {
            x2 = pbounds.getMaxX() - dist;
        }
        else if (mode2 == VFX_FRAME_ALIGNER_MODE_MID)
        {
            x2 = pbounds.getMidX() - dist;
        }
    }
    if ((mode1 != VFX_FRAME_ALIGNER_MODE_NONE) &&
        (mode2 == VFX_FRAME_ALIGNER_MODE_NONE))
    {
        x2 = x1 + b.getWidth() - 1;
    }
    if ((mode1 == VFX_FRAME_ALIGNER_MODE_NONE) &&
        (mode2 != VFX_FRAME_ALIGNER_MODE_NONE))
    {
        x1 = x2 - b.getWidth() + 1;
    }

    // adjust up and down
    mode1 = aligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_TOP);
    mode2 = aligner->getAlignMode(VFX_FRAME_ALIGNER_SIDE_BOTTOM);
    if (mode1 != VFX_FRAME_ALIGNER_MODE_NONE)
    {
        dist = aligner->getAlignDist(VFX_FRAME_ALIGNER_SIDE_TOP);
        if (mode1 == VFX_FRAME_ALIGNER_MODE_SIDE)
        {
            y1 = pbounds.getMinY() - dist;
        }
        else if (mode1 == VFX_FRAME_ALIGNER_MODE_MID)
        {
            y1 = pbounds.getMidY() - dist;
        }
    }
    if (mode2 != VFX_FRAME_ALIGNER_MODE_NONE)
    {
        dist = aligner->getAlignDist(VFX_FRAME_ALIGNER_SIDE_BOTTOM);
        if (mode2 == VFX_FRAME_ALIGNER_MODE_SIDE)
        {
            y2 = pbounds.getMaxY() - dist;
        }
        else if (mode2 == VFX_FRAME_ALIGNER_MODE_MID)
        {
            y2 = pbounds.getMidY() - dist;
        }
    }
    if ((mode1 != VFX_FRAME_ALIGNER_MODE_NONE) &&
        (mode2 == VFX_FRAME_ALIGNER_MODE_NONE))
    {
        y2 = y1 + b.getHeight() - 1;
    }
    if ((mode1 == VFX_FRAME_ALIGNER_MODE_NONE) &&
        (mode2 != VFX_FRAME_ALIGNER_MODE_NONE))
    {
        y1 = y2 - b.getHeight() + 1;
    }

    // apply new position and bounds
    VfxS32 w = x2 - x1 + 1;
    VfxS32 h = y2 - y1 + 1;

    bounds.size.width = w;
    bounds.size.height = h;
    targetFrame->setBounds(bounds);

    VfxFPoint anc = targetFrame->getAnchor();
    VfxPoint pos;
    pos.x = x1 + (VfxS32)(anc.x * w);
    pos.y = y1 + (VfxS32)(anc.y * h);
    targetFrame->setPos(pos);
}

