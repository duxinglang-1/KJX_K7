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
 *  vapp_videoclipper_slider.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_VIDEOCLIPPER_SLIDER_H__
#define __VAPP_VIDEOCLIPPER_SLIDER_H__
#include "MMI_features.h" 

#if defined(__MMI_VIDEO_CLIPPER__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VappVideoClipperSliderThumb : public VcpImageButton
{
    VFX_DECLARE_CLASS(VappVideoClipperSliderThumb);
public:  
    VfxSignal1 <
        VfxS32
    > m_signalThumbDrag; 
        
    VfxSignal1 < 
        VfxS32 // Pen down Value
    > m_signalThumbPressed;
    
    VfxSignal1 <
        VfxS32 // Pen up Value
    > m_signalThumbReleased;

    VfxSignal1 <
        VfxS32 // Pen up Value
    > m_signalThumbAbort;
    
public:
    VappVideoClipperSliderThumb(){}
    virtual ~VappVideoClipperSliderThumb(){}

    virtual VfxBool onPenInput(VfxPenEvent &event);

    void setInitPos(
        VfxS32 x, 
        VfxS32 y);
    
    VfxPoint& getInitPos();
    
private:
    VfxPoint m_initPos;
};

 
class VappVideoClipperSlider : public VfxControl
{   
    VFX_DECLARE_CLASS(VappVideoClipperSlider);

public:
    
public:    
    // Default constructor.
    VappVideoClipperSlider();
    virtual ~VappVideoClipperSlider();
    
    virtual void setBounds(const VfxRect &value);   
    
// Override
protected:
    virtual void onInit();

    virtual VfxBool onKeyInput(
        VfxKeyEvent &event          // [IN] The key event to be handled
    );

// Method
public:  
    void setLength(
        VfxS32 len
    );

    void setPlayThumbValue(
        VfxFloat value
    );

    void setStartThumbValue(
        VfxFloat value
    );

    void setEndThumbValue(
        VfxFloat value
    );

    void setMinValue(VfxFloat value)
    {
        m_min = value;
    }

    void setMaxValue(VfxFloat value)
    {
        m_max = value;
    }

    void setMinClipBarRatio(
        VfxFloat value
    );

    void setStartThumbFuzzyRatio(
        VfxFloat value
        );

    void setStartThumbAutoAnimate(VfxBool value)
    {
        m_startThumb->setAutoAnimate(value);
        m_clipperBar->setAutoAnimate(value);
    };
    
    void setPlayThumbAutoAnimate(VfxBool value)
    {
        m_playThumb->setAutoAnimate(value);
        m_playBar->setAutoAnimate(value);
    };

    VfxPoint& getInitStartThumbPos();

    VfxPoint& getInitEndThumbPos();

    VfxPoint& getStartThumbPos();

    VfxPoint& getEndThumbPos();

    VfxPoint& getPlayThumbPos();
    
    VfxS32 getLength()
    {
        return m_length;
    }

    VfxS32 getHeight()
    {
        return m_startThumb->getSize().height;
    }
    
    VfxFloat getPlayThumbValue()
    {
        return m_playThumbValue;
    }
    
    VfxFloat getStartThumbValue()
    {
        return m_startThumbValue;
    }

    VfxFloat getEndThumbValue()
    {
        return m_endThumbValue;
    }

    VfxFloat getMinValue()
    {
        return m_min;
    }

    VfxFloat getMaxValue()
    {
        return m_max;
    }

    VfxFloat PositionToValue(
        VfxS32 pos
    );

    VfxS32 ValueToPosition(
        VfxFloat value
    );
    
    VfxSignal2 <
        VappVideoClipperSlider*, // Slider pointer
        VfxFloat // New Value
    > m_signalPlayThumbDrag; 
    
    // This signal emits everytime a pen-down event happens on the slider thumb control.
    // It signifies that the user has started dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 < 
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen down Value
    > m_signalPlayThumbPressed;
    
    // This signal emits everytime a pen-up event happens on the slider thumb control.
    // It signifies that the user has stopped dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 <
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen up Value
    > m_signalPlayThumbReleased;

    VfxSignal2 <
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen up Value
    > m_signalPlayThumbAbort;
    
    VfxSignal2 <
        VappVideoClipperSlider *, // Slider pointer
        VfxFloat // New Value
    > m_signalStartThumbDrag; 
    
    // This signal emits everytime a pen-down event happens on the slider thumb control.
    // It signifies that the user has started dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 < 
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen down Value
    > m_signalStartThumbPressed;
    
    // This signal emits everytime a pen-up event happens on the slider thumb control.
    // It signifies that the user has stopped dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 <
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen up Value
    > m_signalStartThumbReleased;

    VfxSignal2 <
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen up Value
    > m_signalStartThumbAbort;

    VfxSignal2 <
        VappVideoClipperSlider *, // Slider pointer
        VfxFloat // New Value
    > m_signalEndThumbDrag; 
    
    // This signal emits everytime a pen-down event happens on the slider thumb control.
    // It signifies that the user has started dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 < 
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen down Value
    > m_signalEndThumbPressed;
    
    // This signal emits everytime a pen-up event happens on the slider thumb control.
    // It signifies that the user has stopped dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 <
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen up Value
    > m_signalEndThumbReleased;

    VfxSignal2 <
        VappVideoClipperSlider*, //Slider pointer
        VfxFloat // Pen up Value
    > m_signalEndThumbAbort;
    
// Implement
private:

    void startThumbPressed(
        VfxS32 pos
    );

    void startThumbReleased(
        VfxS32 pos
    );
    
    void startThumbDrag(
        VfxS32 pos
    );

    void startThumbAbort(
        VfxS32 pos
    );
    
    void endThumbPressed(
        VfxS32 pos
    );

    void endThumbReleased(
        VfxS32 pos
    );
    
    void endThumbDrag(
        VfxS32 pos
    );

    void endThumbAbort(
        VfxS32 pos
    );
    
    void playThumbPressed(
        VfxS32 pos
    );

    void playThumbReleased(
        VfxS32 pos
    );
    
    void playThumbDrag(
        VfxS32 pos
    );

    void playThumbAbort(
        VfxS32 pos
    );
    
    void checkStartThumbPos(
        VfxS32 pos
    );

    void checkEndThumbPos(
        VfxS32 pos
    );

    void checkPlayThumbPos(
        VfxS32 pos
    );

    void updateClipBar();

    void updatePlayBar();
    
    VfxS32      m_length;
    VfxS32      m_barLength;
    VfxFloat    m_playThumbValue;
    VfxFloat    m_startThumbValue;
    VfxFloat    m_endThumbValue;
    VappVideoClipperSliderThumb* m_startThumb;
    VappVideoClipperSliderThumb* m_endThumb;
    VappVideoClipperSliderThumb* m_playThumb;
    VfxImageFrame*   m_bar;
    VfxImageFrame*   m_clipperBar;
    VfxImageFrame*   m_playBar;
    VfxFloat    m_max;
    VfxFloat    m_min;
    VfxS32      m_startThumbOffset;
    VfxS32      m_endThumbOffset;
    VfxS32      m_minIntervalLength;
    VfxS32      m_startThumbFuzzyLength;
    VfxFloat    m_minClipBarRatio;
    VfxFloat    m_startThumbFuzzyRatio;
    
};

#endif /* __MMI_VIDEO_CLIPPER__*/

#endif /* __VAPP_VIDEOCLIPPER_SLIDER_H__ */

