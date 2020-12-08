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
 *  vtst_rt_frame_effect.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for VcpFrameEffect
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
#include "vcp_frame_effect.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vcp_frame_effect_type.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_input_event.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Marquee Test Implementation
 *****************************************************************************/

class VtstRtFrameEffect : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame1;
    VfxTextFrame *m_controlText;
    VcpEffectType  m_transitionType;
    VcpFrameEffect *m_frameEffect;
    VfxBool m_isReverse;
// Constructor / Destructor
public:
    VtstRtFrameEffect() :
        m_transitionType(VCP_EFFECT_NONE),
        m_isReverse(VFX_FALSE)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setRect(VfxRect(40,60,180,270));
        
        m_frame1->setImgContent(VfxImageSrc(VFX_WSTR("E:\\FrameEffect\\beanFlower.jpg")));
        m_frame1->setBgColor(VFX_COLOR_YELLOW);
        m_frame1->setIsCached(VFX_TRUE);
        m_frame1->setIsOpaque(VFX_TRUE);

        VfxFrame *tempFrame;
        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_frame1);
        tempFrame->setRect(20, 30, 50, 50);
        tempFrame->setBgColor(VFX_COLOR_OLIVE);
        tempFrame->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_frame1);
        tempFrame->setRect(0, 80, 180, 190);
        tempFrame->setBgColor(VFX_COLOR_GREEN);
        tempFrame->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_frame1);
        tempFrame->setRect(0, 230, 180, 40);
        tempFrame->setBgColor(VFX_COLOR_SILVER);
        tempFrame->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(tempFrame, VfxFrame, m_frame1);
        tempFrame->setRect(140, 40, 30, 30);
        tempFrame->setBgColor(VFX_COLOR_FUCHSIA);
        tempFrame->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(m_controlText, VfxTextFrame, this);
        m_controlText->setPos(VfxPoint(10, 30));
        m_controlText->setColor(VFX_COLOR_BLACK);
        m_controlText->setBgColor(VFX_COLOR_GREY);
        m_controlText->setAutoAnimate(VFX_TRUE);
        m_controlText->setString(VFX_WSTR("Hello Frame Effect"));

        VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        VfxWString temp;
        VfxS32 temp2;
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            switch(event.keyCode)
            {
                case VFX_KEY_CODE_1:
                    temp2 = (VfxS32)m_transitionType;
                    temp2 ++;
                    m_transitionType = (VcpEffectType)temp2;
                    if (m_transitionType == VCP_EFFECT_END)
                    {
                        m_transitionType = VCP_EFFECT_NONE;
                    }
                    
                    if (m_transitionType == VCP_EFFECT_NONE)
                    {
                        m_controlText->setString(VFX_WSTR("None"));
                    }
                    else if (m_transitionType == VCP_EFFECT_FADE_IN)
                    {
                        m_controlText->setString(VFX_WSTR("Fade In"));
                    }
                    else if (m_transitionType == VCP_EFFECT_FADE_OUT)
                    {
                        m_controlText->setString(VFX_WSTR("Fade Out"));
                    }
                    else if (m_transitionType == VCP_EFFECT_FADE_OUT_WAVE)
                    {
                        m_controlText->setString(VFX_WSTR("Fade Out Wave"));
                    }
                    else if (m_transitionType == VCP_EFFECT_FLIP)
                    {
                        m_controlText->setString(VFX_WSTR("Flip"));
                    }
                    else if (m_transitionType == VCP_EFFECT_PHOTOWALL)
                    {
                        m_controlText->setString(VFX_WSTR("Photo Wall"));
                    }
                    else if (m_transitionType == VCP_EFFECT_POPUP)
                    {
                        m_controlText->setString(VFX_WSTR("Popup"));
                    }
                    else if (m_transitionType == VCP_EFFECT_MORPH_FADE_IN)
                    {
                        m_controlText->setString(VFX_WSTR("Morph Fade In"));
                    }
                    else if (m_transitionType == VCP_EFFECT_FLY_OUT)
                    {
                        m_controlText->setString(VFX_WSTR("Fly Out"));
                    }
                    else if (m_transitionType == VCP_EFFECT_RECTANGLE_ROTATE_OUT)
                    {
                        m_controlText->setString(VFX_WSTR("Rectangle Rotate Out"));
                    }
                    else if (m_transitionType == VCP_EFFECT_SMALL_FLIP)
                    {
                        m_controlText->setString(VFX_WSTR("Small Flip"));
                    }
                    else if (m_transitionType == VCP_EFFECT_TRANSFORMER)
                    {
                        m_controlText->setString(VFX_WSTR("Transformer"));
                    }
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_2:
                    m_frameEffect->applyEffect(m_frame1, m_transitionType, 2000, VCP_EFFECT_DIRECTION_FROM_UP, m_isReverse);
                    return VFX_TRUE;
                case VFX_KEY_CODE_3:
                    {
                        VcpEffectMorphFadeInData input;
                        input.fromRect = VfxRect(82,282,80,80);
                        m_frameEffect->applyEffect(m_frame1, VCP_EFFECT_MORPH_FADE_IN, 2000, VCP_EFFECT_DIRECTION_FROM_UP, m_isReverse, &input, sizeof(input));
                    }
                    return VFX_TRUE;
                case VFX_KEY_CODE_4:
                    m_frameEffect->applyEffect(m_frame1, m_transitionType, 2000, VCP_EFFECT_DIRECTION_FROM_LEFT, m_isReverse);
                    return VFX_TRUE;
                case VFX_KEY_CODE_5:
                    m_frameEffect->applyEffect(m_frame1, m_transitionType, 2000);
                    return VFX_TRUE;
                case VFX_KEY_CODE_6:
                    m_frameEffect->applyEffect(m_frame1, m_transitionType, 2000, VCP_EFFECT_DIRECTION_FROM_RIGHT, m_isReverse);
                    return VFX_TRUE;
                case VFX_KEY_CODE_7:
                    if (m_isReverse)
                    {
                        m_isReverse = VFX_FALSE;
                    }
                    else
                    {
                        m_isReverse = VFX_TRUE;
                    }
                    return VFX_TRUE;
                case VFX_KEY_CODE_8:
                    
                    m_frameEffect->applyEffect(m_frame1, m_transitionType, 2000, VCP_EFFECT_DIRECTION_FROM_BOTTOM, m_isReverse);
                    return VFX_TRUE;
                case VFX_KEY_CODE_9:
                    m_frameEffect->restore();
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

VtstTestResultEnum vtst_rt_frame_effect(VfxU32 param)
{
    //VTST_START_SCRN_ROTATE(VtstRtFrameEffect);
    VTST_START_SCRN(VtstRtFrameEffect);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

