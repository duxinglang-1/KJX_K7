/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  vtst_rt_frame_filter.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Frame Filter
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_frame_filter.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_image_src.h"
#include "vfx_string.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vrt_datatype.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Class VtstWaveFilter
 *****************************************************************************/
 
class VtstWaveFilter : public VfxFrameFilter
{
// Vairable
public:
    VfxS32 m_distance;

// Constructor / Destructor
public:
    VtstWaveFilter();

// Override
protected:
    virtual BufferModeEnum onGetBufferMode() const
    {
        return BUFFER_MODE_OUT_OF_PLACE;
    }
    
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level);
};


/***************************************************************************** 
 * Frame Filter Test Implementation
 *****************************************************************************/

class VtstRtFrameFilter : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtFrameFilter()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Frame Filter"));

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

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_frame_filter(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameFilter);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

