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
 *  vtst_rt_reflection.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for reflection
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__
#include "mmi_features.h"
#include "vtst_rt_main.h"
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
#include "vcp_content_clone.h"
#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_datatype.h"
#include "vrt_canvas.h"
#include "vfx_input_event.h"
#include "vfx_app_cat_scr.h"

//static VfxU8 g_imageBuff[100*149*2];
/***************************************************************************** 
 * Marquee Test Implementation
 *****************************************************************************/

class VtstRtReflection : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame1;
    VfxFrame *m_frame1_1;
    VfxFrame *m_frame1_2;
    VfxFrame *m_background;
    VcpContentClone *m_reflection;
    VfxPointTimeline *m_pointTimeline;
    //VfxFloatTimeline *m_filterTimeline;

    //VfxImageBuffer shadowBuff;
// Constructor / Destructor
public:
    VtstRtReflection()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setBgColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(m_background, VfxFrame, this);
        m_background->setRect(0,0,240,400);
        m_background->setImgContent(VfxImageSrc(VFX_WSTR("E:\\FrameEffect\\screen0.bmp")));
        m_background->setIsCached(VFX_TRUE);
        m_background->setIsOpaque(VFX_TRUE);
        m_background->setHidden(VFX_TRUE);
            
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setRect(VfxRect(20,20,100,149));
        
        //m_frame1->setImgContent(VfxImageSrc(VFX_WSTR("E:\\FrameEffect\\beanFlower2.jpg")));
        m_frame1->setBgColor(VFX_COLOR_YELLOW);
        //m_frame1->setIsCached(VFX_TRUE);
        //m_frame1->setIsOpaque(VFX_TRUE);
        m_frame1->setOpacity(0.5);

        VFX_OBJ_CREATE(m_frame1_2, VfxFrame, m_frame1);
        m_frame1_2->setRect(VfxRect(0,0,100,149));
        
        m_frame1_2->setImgContent(VfxImageSrc(VFX_WSTR("E:\\FrameEffect\\beanFlower2.jpg")));
        m_frame1_2->setBgColor(VFX_COLOR_YELLOW);
        m_frame1_2->setIsCached(VFX_TRUE);
        m_frame1_2->setIsOpaque(VFX_TRUE);

        VFX_OBJ_CREATE(m_frame1_1, VfxFrame, m_frame1);
        m_frame1_1->setRect(VfxRect(20,20,24,24));
        
        m_frame1_1->setImgContent(VfxImageSrc(VFX_WSTR("E:\\FrameEffect\\mouse.jpg")));
        m_frame1_1->setBgColor(VFX_COLOR_GREEN);
        m_frame1_1->setIsCached(VFX_TRUE);
        m_frame1_1->setIsOpaque(VFX_TRUE);

        VFX_OBJ_CREATE(m_pointTimeline,VfxPointTimeline,this);

        m_pointTimeline->setTarget(m_frame1_1);
        m_pointTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_pointTimeline->setDurationTime(500);
        m_pointTimeline->setRepeatDuration(3000);
        m_pointTimeline->setAutoReversed(VFX_TRUE);
        m_pointTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        m_pointTimeline->setFromValue(VfxPoint(20,20));
        m_pointTimeline->setToValue(VfxPoint(80,80));
        m_pointTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_pointTimeline->start(); 


        VFX_OBJ_CREATE(m_reflection, VcpContentClone, this);
        m_reflection->setPos(20, 180);
        m_reflection->setTargetFrame(m_frame1);
        //m_reflection->setBgColor(VFX_COLOR_RED);
        //m_reflection->setIsCached(VFX_TRUE);

        //m_reflection->setTargetRect(VfxRect(0,120,100,29));
        m_reflection->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
        m_reflection->setOutputAlpha(VFX_TRUE);
        m_reflection->setTargetRect(VfxRect(0,0,100,149));
        //m_reflection->setPos(40, 220);
       
        VfxS32Timeline *xPosTimeline;
        VFX_OBJ_CREATE(xPosTimeline, VfxS32Timeline, m_frame1);
        xPosTimeline->setTarget(m_frame1);
        xPosTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        xPosTimeline->setDurationTime(1000);
        xPosTimeline->setRepeatDuration(5000);
        xPosTimeline->setAutoReversed(VFX_TRUE);
        xPosTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        xPosTimeline->setFromValue(20);
        xPosTimeline->setToValue(100);
        xPosTimeline->start();

        VFX_OBJ_CREATE(xPosTimeline, VfxS32Timeline, m_reflection);
        xPosTimeline->setTarget(m_reflection);
        xPosTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        xPosTimeline->setDurationTime(1000);
        xPosTimeline->setRepeatDuration(5000);
        xPosTimeline->setAutoReversed(VFX_TRUE);
        xPosTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        xPosTimeline->setFromValue(20);
        xPosTimeline->setToValue(100);
        xPosTimeline->start(); 
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        VfxWString temp;
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            switch(event.keyCode)
            {
                case VFX_KEY_CODE_ARROW_UP:
                    m_reflection->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_COPY);
                    //m_reflection->setTargetRect(VfxRect(20,20,80,80));
                    //m_reflection->setPos(40, 220);
                    return VFX_TRUE;
                case VFX_KEY_CODE_ARROW_LEFT:
                    m_reflection->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_REFLECTION);
                    m_reflection->invalidate();
                    return VFX_TRUE;
                case VFX_KEY_CODE_ARROW_DOWN:
                    m_reflection->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
                    return VFX_TRUE;
                case VFX_KEY_CODE_ARROW_RIGHT:
                    m_reflection->setHidden(VFX_TRUE);
                    m_frame1->setFilter(NULL);
                    return VFX_TRUE;
                case VFX_KEY_CODE_5:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_6:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_7:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_8:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_9:
                    return VFX_TRUE;
                case VFX_KEY_CODE_0:
                    
                    return VFX_TRUE;
            }
        }
        return VtstRtScr::onKeyInput(event);
    }


    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

#endif /* !defined(__MMI_VUI_COSMOS_CP_SLIM__) */

VtstTestResultEnum vtst_rt_reflection(VfxU32 param)
{
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
    VTST_START_SCRN(VtstRtReflection);
#endif
    //VTST_START_SCRN(VtstRtFrameEffect);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__


