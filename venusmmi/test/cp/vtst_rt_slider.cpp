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
 *  vtst_rt_slider.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpSlider
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

#include "vcp_slider.h"

 #include "vfx_config.h"
 #include "vfx_text_frame.h"
 #include "vcp_button.h"
 #include "vfx_cpp_base.h"
 #include "vfx_sys_memory.h"
 #include "vfx_object.h"
 #include "vfx_string.h"
 #include "vfx_datatype.h"
 #include "vfx_font_desc.h"
 #include "vfx_signal.h"
 #include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Control Test Implementation
 *****************************************************************************/

class VtstRtSlider : public VtstRtScr
{
// Variable
public:
	VcpSlider *m_slider;
	VfxTextFrame *m_curValue;
    VcpButton *m_toggleMotionType;
// Constructor / Destructor
public:
    VtstRtSlider()
    {
    }

// Override
public:
    virtual void onInit()
    {
		VtstRtScr::onInit();
		
        VfxS32 x = 20;
        VfxS32 y = 50;
        VfxS32 width = getSize().width/2;
        VfxS32 height = getSize().height/10;
		
		VcpButton *switchLayout;
		VFX_OBJ_CREATE(switchLayout,VcpButton, this);
		switchLayout->setPos(x, y);
		switchLayout->setSize(width, height);
		switchLayout->setText(VFX_WSTR("switch layout"));
		switchLayout->setTextFont(VFX_FONT_DESC_SMALL);
		switchLayout->m_signalClicked.connect(this, &VtstRtSlider::onSwitchLayout);

        y += height + 5;
      
      VFX_OBJ_CREATE(m_toggleMotionType,VcpButton, this);
		m_toggleMotionType->setPos(x, y);
		m_toggleMotionType->setSize(width, height);
		m_toggleMotionType->setText(VFX_WSTR(" Discrete mode"));
		m_toggleMotionType->setTextFont(VFX_FONT_DESC_SMALL);
		m_toggleMotionType->m_signalClicked.connect(this, &VtstRtSlider::onToggleMotionType);

        y += height + 5;

		VcpButton *moveAhead;
		VFX_OBJ_CREATE(moveAhead,VcpButton, this);
		moveAhead->setPos(x, y);
		moveAhead->setSize(width, height);
		moveAhead->setText(VFX_WSTR("move ahead"));
		moveAhead->setTextFont(VFX_FONT_DESC_SMALL);
		moveAhead->m_signalClicked.connect(this, &VtstRtSlider::onMoveAhead);

        y += height + 5;

		VFX_OBJ_CREATE(m_slider, VcpSlider, this);
      m_slider->setAnchor(1.0, 1.0);
		m_slider->setPos((getSize().width*9)/10, (getSize().height*4)/5);
		m_slider->setLength(200);
		m_slider->setMaxValue(10);
		m_slider->setMinValue(-5);
		m_slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
		m_slider->m_signalUserChangedValue.connect(this, &VtstRtSlider::onValueChange);
      m_slider->setFocused(VFX_TRUE);
		
		VfxFloat slidervalue = 0;
		VfxFloat maxval = 10;
		VfxFloat minval = -5;

		VfxTextFrame *maxValue;
		VfxTextFrame *minValue;
		
		VfxWString val;
		VfxWString max;
		VfxWString min;

		VFX_OBJ_CREATE(m_curValue, VfxTextFrame, this);
		VFX_OBJ_CREATE(maxValue, VfxTextFrame, this);
		VFX_OBJ_CREATE(minValue, VfxTextFrame, this);
		maxValue->setPos(x, y);
        y += height/2;
		maxValue->setSize(x, 30);

		m_curValue->setPos(x, y);
        y += height/2;
		m_curValue->setSize(x, 30);

		minValue->setPos(x, y);
		minValue->setSize(x, 30);


		val.format("curr = %f",slidervalue);
		m_curValue->setString(val);
		max.format("max = %f",maxval);
		maxValue->setString(max);
		min.format("min = %f",minval);
		minValue->setString(min);


		
		// return 0;
    
    }

	void onSwitchLayout(VfxObject* sender, VfxId id)
	{	
		if(m_slider->getLayout() == VCP_SLIDER_LAYOUT_HORZ)
		{
			m_slider->setLayout(VCP_SLIDER_LAYOUT_VERT);
		}
		else if (m_slider->getLayout() == VCP_SLIDER_LAYOUT_VERT)
		{
			m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
		}
	}

    void onToggleMotionType(VfxObject* sender, VfxId id)
    {
        if(!m_slider->getTotalDiscreteStepsForPen())
        {
            m_slider->setTotalDiscreteStepsForPen(10);
            m_toggleMotionType->setText(VFX_WSTR("Set Smooth mode"));
        }
        else
        {
            m_slider->setTotalDiscreteStepsForPen(0);
            m_toggleMotionType->setText(VFX_WSTR("Set 10 step mode"));
        }
    }

	void onMoveAhead(VfxObject* sender, VfxId id)
	{
		VfxFloat curr = m_slider->getCurrentValue() + m_slider->getMaxValue()/20;	
		if(curr > m_slider->getMaxValue())
		{
			curr = 0;
		}
		m_slider->setCurrentValue(curr);
		VfxWString val;
		val.format("curr = %f",curr);
		m_curValue->setString(val);
	}
	
	void onValueChange(VfxObject *sender, // Slider pointer
                    VfxFloat oldval, // Old Value
                    VfxFloat newval// New Value
                    )
	{
		VfxWString val;
		val.format("curr = %f",newval);
		m_curValue->setString(val);
	}

   virtual VfxS32 phase(VfxS32 idx)
    {
        setTitle(VFX_WSTR("Slider Test"));
        confirm(VFX_WSTR("Result is correct?"));
        
        return -1;
    }

    virtual VfxS32 start() {return 1;}
};


VtstTestResultEnum vtst_rt_slider(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSlider);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

