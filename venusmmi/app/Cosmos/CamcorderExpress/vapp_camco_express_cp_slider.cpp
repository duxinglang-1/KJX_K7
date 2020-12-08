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

#include "vapp_camco_express_cp_slider.h"

#ifdef __VAPP_CAMCO_EXPRESS__

void VappCamcoCpSlider::onInit()
{
    VfxControl::onInit();
    m_minValue = 0;
    m_maxValue = 1;
    m_currentValue = 0.5;
    VFX_OBJ_CREATE(m_maxImg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_minImg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_indImg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_barImg, VfxImageFrame, this);

    m_maxImg->setAnchor(0.5, 0.5);
    m_maxImg->setIsUnhittable(VFX_TRUE);
    m_minImg->setAnchor(0.5, 0.5);
    m_minImg->setIsUnhittable(VFX_TRUE);
    m_indImg->setAnchor(0.5, 0.5);
    m_barImg->setAnchor(0.5, 0.5);
    m_barImg->setIsUnhittable(VFX_TRUE);

    m_indImg->bringToFront();

    m_isMoving = VFX_FALSE;

    m_minPos = 0;
    m_maxPos = 1;

    m_curveR = 0;

    m_signalBoundsChanged.connect(this, &VappCamcoCpSlider::onBoundsValueChanged);
}

void VappCamcoCpSlider::setCpImage(VfxImageSrc minimg, VfxImageSrc maximg, VfxImageSrc indimg, VfxImageSrc barimg)
{
    m_maxImg->setImgContent(maximg);
    m_maxImg->setSize(maximg.getSize().width, maximg.getSize().height);

    m_minImg->setImgContent(minimg);
    m_minImg->setSize(minimg.getSize().width, minimg.getSize().height);

    m_indImg->setImgContent(indimg);
    m_indImg->setSize(indimg.getSize().width, indimg.getSize().height);

    m_barImg->setImgContent(barimg);
    m_barImg->setSize(barimg.getSize().width, barimg.getSize().height);

    VfxU32 nW = (maximg.getSize().width > minimg.getSize().width)?(maximg.getSize().width + VAPP_CAMCO_CP_SLIDER_V_SPACE): (minimg.getSize().width + VAPP_CAMCO_CP_SLIDER_V_SPACE);
    VfxU32 nH = (maximg.getSize().height > minimg.getSize().height)?(maximg.getSize().height + VAPP_CAMCO_CP_SLIDER_V_SPACE): (minimg.getSize().height + VAPP_CAMCO_CP_SLIDER_V_SPACE);
    if(m_isVerticalMode)
    {
        setSize(
            barimg.getSize().width + (indimg.getSize().width>>1) + nW + VAPP_CAMCO_CP_SLIDER_SPACE,
            (nH+ nH + barimg.getSize().height));
    }
    else
    {
        setSize(
            (nW + nW + barimg.getSize().height),
            barimg.getSize().width + (indimg.getSize().width>>1) + nH + VAPP_CAMCO_CP_SLIDER_SPACE);
    }
}

void VappCamcoCpSlider::setValueRange(VfxS32 min, VfxS32 max)
{
    m_minValue = min;
    m_maxValue = max;
    m_range = m_maxValue - m_minValue;
    ASSERT(m_range > 0);
}

VfxS32 VappCamcoCpSlider::getCurrentValue(void)
{
    return m_currentValue;
}

void VappCamcoCpSlider::setCurrentValue(VfxS32 value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_OSD_CP_SLIDER_UPDATE, value, m_minValue, m_maxValue, m_isVerticalMode, m_isInverseMode);

    if(value < m_minValue)
        value = m_minValue;
    if(value > m_maxValue)
        value = m_maxValue;

    m_currentValue = value;

    if(m_curveR == 0)
    {
        VfxS32 x, y;

        if(m_isVerticalMode)
        {
            x = m_barImg->getPos().x;
            if(!m_isInverseMode)
                y = m_minPos + ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;
            else
                y = m_minPos - ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;

        }
        else
        {
            y = m_barImg->getPos().y;
            if(!m_isInverseMode)
                x = m_minPos + ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;
            else
                x = m_minPos - ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;
        }
        m_indImg->setPos(x, y);
    }
    else
    {
        VfxS32 x, y;

        if(m_isVerticalMode)
        {
            if(!m_isInverseMode)
                y = m_minPos + ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;
            else
                y = m_minPos - ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;
            VfxU32 rel_y = vfxAbs(y - m_barImg->getPos().y);
            x = g_vapp_camco_skin.zoomIndR + m_barImg->getPos().x - (m_barImg->getSize().width>>1) + m_curveR * (1- vfxSqrt(1 - ((VfxFloat)(rel_y*rel_y)/(m_curveR*m_curveR))));

        }
        else
        {
            if(!m_isInverseMode)
                x = m_minPos + ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;
            else
                x = m_minPos - ((VfxFloat)(m_currentValue - m_minValue) / m_range) * m_length;
            VfxU32 rel_x = vfxAbs(x - m_barImg->getPos().x);
            y = g_vapp_camco_skin.zoomIndR + m_barImg->getPos().y - (m_barImg->getSize().width>>1) + m_curveR * (1- vfxSqrt(1 - ((VfxFloat)(rel_x*rel_x)/(m_curveR*m_curveR))));
        }
        m_indImg->setPos(x, y);
    }

    invalidate();
}

void VappCamcoCpSlider::setCurveR(VfxU32 r)
{
    m_curveR = r;
}

void VappCamcoCpSlider::onBoundsValueChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    m_barImg->setAnchor(0.5, 0.5);

    if(m_isVerticalMode)
    {
        if(!m_isInverseMode)
        {
            m_barImg->setPos(
                ((m_indImg->getSize().width>>1) + (m_barImg->getSize().width>>1)),
                (m_minImg->getSize().height + VAPP_CAMCO_CP_SLIDER_V_SPACE +(m_barImg->getSize().height>>1)) );
        }
        else
        {
            m_barImg->setPos(
                ((m_indImg->getSize().width>>1) + (m_barImg->getSize().width>>1)),
                (m_maxImg->getSize().height + VAPP_CAMCO_CP_SLIDER_V_SPACE + (m_barImg->getSize().height>>1)) );
        }

        VfxS32 x = m_barImg->getPos().x + (m_barImg->getSize().width>>1) + (m_maxImg->getSize().width>>1);
        VfxS32 y = m_barImg->getPos().y;


        VfxU32 nH = (m_maxImg->getSize().height > m_minImg->getSize().height)?m_maxImg->getSize().height: m_minImg->getSize().height;

        if(!m_isInverseMode)
        {
            m_maxImg->setPos(x + VAPP_CAMCO_CP_SLIDER_SPACE, y + (m_barImg->getSize().height>>1) + (nH>>1) + VAPP_CAMCO_CP_SLIDER_V_SPACE);
            m_minImg->setPos(x + VAPP_CAMCO_CP_SLIDER_SPACE, y - (m_barImg->getSize().height>>1) - (nH>>1) - VAPP_CAMCO_CP_SLIDER_V_SPACE);
        }
        else
        {
            m_maxImg->setPos(x + VAPP_CAMCO_CP_SLIDER_SPACE, y - (m_barImg->getSize().height>>1) - (nH>>1) - VAPP_CAMCO_CP_SLIDER_V_SPACE);
            m_minImg->setPos(x + VAPP_CAMCO_CP_SLIDER_SPACE, y + (m_barImg->getSize().height>>1) + (nH>>1) + VAPP_CAMCO_CP_SLIDER_V_SPACE);
        }

        if(!m_isInverseMode)
        {
            m_minPos = y - (m_barImg->getSize().height>>1) + (g_vapp_camco_skin.zoomIndBetweeR>>1);
            m_maxPos = y + (m_barImg->getSize().height>>1) - (g_vapp_camco_skin.zoomIndBetweeR>>1);
        }
        else
        {
            m_minPos = y + (m_barImg->getSize().height>>1) - (g_vapp_camco_skin.zoomIndBetweeR>>1);
            m_maxPos = y - (m_barImg->getSize().height>>1) + (g_vapp_camco_skin.zoomIndBetweeR>>1);
        }
    }
    else
    {
        if(!m_isInverseMode)
        {
            m_barImg->setPos(
                (m_minImg->getSize().width + VAPP_CAMCO_CP_SLIDER_V_SPACE + (m_barImg->getSize().height>>1)),
                ((m_indImg->getSize().height>>1) + (m_barImg->getSize().width>>1)));
        }
        else
        {
            m_barImg->setPos(
                (m_maxImg->getSize().width + VAPP_CAMCO_CP_SLIDER_V_SPACE + (m_barImg->getSize().height>>1)),
                ((m_indImg->getSize().height>>1) + (m_barImg->getSize().width>>1)));
        }

        VfxS32 x = m_barImg->getPos().x;
        VfxS32 y = m_barImg->getPos().y + (m_barImg->getSize().width>>1) + (m_maxImg->getSize().width>>1);

        VfxU32 nH = (m_maxImg->getSize().height > m_minImg->getSize().height)?m_maxImg->getSize().height: m_minImg->getSize().height;

        if(!m_isInverseMode)
        {
            m_maxImg->setPos(x + (m_barImg->getSize().height>>1) + (nH>>1) + VAPP_CAMCO_CP_SLIDER_V_SPACE, y + VAPP_CAMCO_CP_SLIDER_SPACE);
            m_minImg->setPos(x - (m_barImg->getSize().height>>1) - (nH>>1) - VAPP_CAMCO_CP_SLIDER_V_SPACE, y + VAPP_CAMCO_CP_SLIDER_SPACE);
        }
        else
        {
            m_maxImg->setPos(x - (m_barImg->getSize().height>>1) - (nH>>1) - VAPP_CAMCO_CP_SLIDER_V_SPACE, y + VAPP_CAMCO_CP_SLIDER_SPACE);
            m_minImg->setPos(x + (m_barImg->getSize().height>>1) + (nH>>1) + VAPP_CAMCO_CP_SLIDER_V_SPACE, y + VAPP_CAMCO_CP_SLIDER_SPACE);
        }

        if(!m_isInverseMode)
        {
            m_minPos = x - (m_barImg->getSize().height>>1) + (g_vapp_camco_skin.zoomIndBetweeR>>1);
            m_maxPos = x + (m_barImg->getSize().height>>1) - (g_vapp_camco_skin.zoomIndBetweeR>>1);
        }
        else
        {
            m_minPos = x + (m_barImg->getSize().height>>1) - (g_vapp_camco_skin.zoomIndBetweeR>>1);
            m_maxPos = x - (m_barImg->getSize().height>>1) + (g_vapp_camco_skin.zoomIndBetweeR>>1);
        }
    }
    m_length = vfxAbs(m_minPos - m_maxPos);
}

VfxBool VappCamcoCpSlider::onPenInput(VfxPenEvent & event)
{
    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        pos = (event.getRelPos(m_indImg));

        VfxRect BB = m_indImg->getBounds();
        BB.origin.x -= BB.size.width * 2;
        BB.origin.y -= BB.size.height * 2;
        BB.size.height = BB.getHeight() * 4;
        BB.size.width = BB.getWidth() * 4;

        if(BB.contains(pos))
        {
            m_isMoving = VFX_TRUE;
            return VFX_TRUE;
        }
    #if VAPP_CAMCO_CP_SUPPORT_QUICK_MOVE
        pos = (event.getRelPos(this));
        VfxRect b;
        if(m_isVerticalMode)
        {
            b.origin = VfxPoint(m_barImg->getPos().x - (m_barImg->getSize().width>>1), m_barImg->getPos().y - (m_barImg->getSize().height>>1));
            b.size = m_barImg->getSize();
        }
        else
        {
            b.origin = VfxPoint(m_barImg->getPos().x - (m_barImg->getSize().height>>1), m_barImg->getPos().y - (m_barImg->getSize().width>>1));
            b.size = VfxSize(m_barImg->getSize().height, m_barImg->getSize().width);
        }
        if(b.contains(pos))
        {
            m_isMoving = VFX_TRUE;

            VfxU32 newValue;
            if(m_isVerticalMode)
            {
                if(!m_isInverseMode)
                {
                    if(pos.y > m_maxPos)
                       pos.y = m_maxPos;
                    if(pos.y < m_minPos)
                       pos.y = m_minPos;
                }
                else
                {
                    if(pos.y < m_maxPos)
                       pos.y = m_maxPos;
                    if(pos.y > m_minPos)
                       pos.y = m_minPos;
                }

                if(!m_isInverseMode)
                {
                    newValue = m_minValue + (VfxFloat)(pos.y - m_minPos)/m_length * m_range;
                }
                else
                {
                    newValue = m_minValue + (VfxFloat)(m_minPos - pos.y)/m_length * m_range;
                }
            }
            else
            {
                if(!m_isInverseMode)
                {
                    if(pos.x > m_maxPos)
                       pos.x = m_maxPos;
                    if(pos.x < m_minPos)
                       pos.x = m_minPos;
                }
                else
                {
                    if(pos.x < m_maxPos)
                       pos.x = m_maxPos;
                    if(pos.x > m_minPos)
                       pos.x = m_minPos;
                }


                if(!m_isInverseMode)
                {
                    newValue = m_minValue + (VfxFloat)(pos.x - m_minPos)/m_length * m_range;
                }
                else
                {
                    newValue = m_minValue + (VfxFloat)(m_minPos - pos.x)/m_length * m_range;
                }

            }
            setCurrentValue(newValue);
            m_signalValueChanged.emit(newValue);
            return VFX_TRUE;
        }
    #endif
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_isMoving = VFX_FALSE;
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if(m_isMoving && !getHidden())
        {
            VfxU32 newValue;

            if(m_isVerticalMode)
            {
                if(!m_isInverseMode)
                {
                    if(pos.y > m_maxPos)
                       pos.y = m_maxPos;
                    if(pos.y < m_minPos)
                       pos.y = m_minPos;
                }
                else
                {
                    if(pos.y < m_maxPos)
                       pos.y = m_maxPos;
                    if(pos.y > m_minPos)
                       pos.y = m_minPos;
                }

                if(!m_isInverseMode)
                {
                    newValue = m_minValue + (VfxFloat)(pos.y - m_minPos)/m_length * m_range;
                }
                else
                {
                    newValue = m_minValue + (VfxFloat)(m_minPos - pos.y)/m_length * m_range;
                }
            }
            else
            {
                if(!m_isInverseMode)
                {
                    if(pos.x > m_maxPos)
                       pos.x = m_maxPos;
                    if(pos.x < m_minPos)
                       pos.x = m_minPos;
                }
                else
                {
                    if(pos.x < m_maxPos)
                       pos.x = m_maxPos;
                    if(pos.x > m_minPos)
                       pos.x = m_minPos;
                }
                if(!m_isInverseMode)
                {
                    newValue = m_minValue + (VfxFloat)(pos.x - m_minPos)/m_length * m_range;
                }
                else
                {
                    newValue = m_minValue + (VfxFloat)(m_minPos - pos.x)/m_length * m_range;
                }

            }
            setCurrentValue(newValue);
            m_signalValueChanged.emit(newValue);
        }
        return VFX_TRUE;
    }
    return VFX_TRUE;
}

void VappCamcoCpSlider::setVertical(VfxBool isVertical)
{
    m_isVerticalMode = isVertical;

    VfxU32 nW = (m_maxImg->getSize().width > m_minImg->getSize().width)?(m_maxImg->getSize().width + VAPP_CAMCO_CP_SLIDER_V_SPACE): (m_minImg->getSize().width + VAPP_CAMCO_CP_SLIDER_V_SPACE);
    VfxU32 nH = (m_maxImg->getSize().height > m_minImg->getSize().height)?(m_maxImg->getSize().height + VAPP_CAMCO_CP_SLIDER_V_SPACE): (m_minImg->getSize().height + VAPP_CAMCO_CP_SLIDER_V_SPACE);
    if(m_isVerticalMode)
    {
        setSize(
            m_barImg->getSize().width + (m_indImg->getSize().width>>1) + nW + VAPP_CAMCO_CP_SLIDER_SPACE,
            (nH+ nH + m_barImg->getSize().height));
    }
    else
    {
        setSize(
            (nW + nW + m_barImg->getSize().height),
            m_barImg->getSize().width + (m_indImg->getSize().width>>1) + nH + VAPP_CAMCO_CP_SLIDER_SPACE);
    }

    if(m_isVerticalMode)
    {
        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(0);
        m_barImg->setTransform(t);
    }
    else
    {
        VfxTransform t;
        t.setIdentity();
        t.data.affine.rz = VFX_DEG_TO_RAD(90);
        m_barImg->setTransform(t);
    }
    onBoundsValueChanged(this, getBounds());
    setCurrentValue(m_currentValue);
}

void VappCamcoCpSlider::setInverse(VfxBool isInverse)
{
    m_isInverseMode = isInverse;

    onBoundsValueChanged(this, getBounds());
    setCurrentValue(m_currentValue);
}

#endif /*__VAPP_CAMCO_EXPRESS__*/
