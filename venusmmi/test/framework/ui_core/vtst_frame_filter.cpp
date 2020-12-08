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
 *  vtst_frame_filter.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Frame filter example for Venus UI
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_frame_filter.h"

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_image_src.h"
#include "vfx_app_cat_scr.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include <string.h>


/***************************************************************************** 
 * Class VtstWaveFilter
 *****************************************************************************/

VtstWaveFilter::VtstWaveFilter() :
    m_distance(0)
{
}


VfxBool VtstWaveFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level)
{
    VfxU8 *inPtr   = inBuf.ptr;
    VfxU8 *outPtr  = outBuf;
    VfxU32 pitchBytes = inBuf.pitchBytes;
    
    VfxU32 i;
    for (i = 0; i < inBuf.height; i++)
    {
        VfxS32 offset = (i + (VfxS32)(m_distance * 4 * level)) % (m_distance * 4) - m_distance;
        if (offset > m_distance)
        {
            offset = m_distance * 2 - offset;
        }

        if (offset < 0)
        {
            VfxU32 copyBytes = (inBuf.width + offset) * sizeof(VfxU32);
            VfxU32 clearBytes = pitchBytes - copyBytes;
            memcpy(outPtr, inPtr + clearBytes, copyBytes);
            memset(outPtr + copyBytes, 0, clearBytes);
        }
        else
        {
            VfxU32 copyBytes = (inBuf.width - offset) * sizeof(VfxU32);
            VfxU32 clearBytes = pitchBytes - copyBytes;
            memset(outPtr, 0, clearBytes);
            memcpy(outPtr + clearBytes, inPtr, copyBytes);
        }
        inPtr += pitchBytes;
        outPtr += pitchBytes;
    }
    return VFX_TRUE;
}


/***************************************************************************** 
 * Class VtstFrameFilterScr
 *****************************************************************************/

VtstFrameFilterScr::VtstFrameFilterScr()
{
}


void VtstFrameFilterScr::onInit()
{
    VfxAppCatScr::onInit();

    /*
     * Setup the background color
     */
    setBgColor(VFX_COLOR_BLUE);

    VtstWaveFilter *filter;
    VFX_OBJ_CREATE(filter, VtstWaveFilter, this);
    filter->m_distance = 5;

    VfxTextFrame *text_frame;
    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setAutoResized(VFX_FALSE);
    text_frame->setPos(VfxPoint(0, 30));
    text_frame->setBounds(VfxRect(0, 0, 240, 40));
    text_frame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    text_frame->setString(VFX_WSTR("Wave Filter Example"));
    text_frame->setFilter(filter);

    VfxFloatTimeline *timeline;
    VFX_OBJ_CREATE(timeline, VfxFloatTimeline, this);
    timeline->setFromValue(0.0f);
    timeline->setToValue(1.0f);
    timeline->setDurationTime(1000);
    timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    timeline->setTarget(text_frame);
    timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    timeline->start();       
}

