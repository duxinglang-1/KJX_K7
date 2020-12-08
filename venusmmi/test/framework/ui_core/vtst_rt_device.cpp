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
 *  vtst_rt_device.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Device Adaptor 
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

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vfx_mc_include.h"
#include "vtst_rt_main.h"
#include "vfx_adp_device.h"

#include "vtst_test_button.h"


/***************************************************************************** 
 * class VtstRtDevTouchFeedback
 *****************************************************************************/

class VtstRtDevTouchFeedback : public VtstRtScr
{
// Variable
public:
    VtstButton *m_button1;
    VtstButton *m_button2;
    VtstButton *m_button3;
    VtstButton *m_button4;
    VtstButton *m_button5;

// Constructor / Destructor
public:
    VtstRtDevTouchFeedback() : 
        m_button1(NULL),
        m_button2(NULL),
        m_button3(NULL),
        m_button4(NULL),
        m_button5(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Touch Feedback Test"));

        VFX_OBJ_CREATE(m_button1, VtstButton, this);
        m_button1->setRect(10, 50, 200, 30);
        m_button1->setLabel(VFX_WSTR("Feedback Down"));
        m_button1->m_signalClicked.connect(this, &VtstRtDevTouchFeedback::onButtonClicked);

        VFX_OBJ_CREATE(m_button2, VtstButton, this);
        m_button2->setRect(10, 90, 200, 30);
        m_button2->setLabel(VFX_WSTR("Feedback Down Vibrate"));
        m_button2->m_signalClicked.connect(this, &VtstRtDevTouchFeedback::onButtonClicked);

        VFX_OBJ_CREATE(m_button3, VtstButton, this);
        m_button3->setRect(10, 130, 200, 30);
        m_button3->setLabel(VFX_WSTR("Feedback Down Tone"));
        m_button3->m_signalClicked.connect(this, &VtstRtDevTouchFeedback::onButtonClicked);

        VFX_OBJ_CREATE(m_button4, VtstButton, this);
        m_button4->setRect(10, 170, 200, 30);
        m_button4->setLabel(VFX_WSTR("Feedback Hold"));
        m_button4->m_signalClicked.connect(this, &VtstRtDevTouchFeedback::onButtonClicked);

        VFX_OBJ_CREATE(m_button5, VtstButton, this);
        m_button5->setRect(10, 210, 200, 30);
        m_button5->setLabel(VFX_WSTR("Feedback Special"));
        m_button5->m_signalClicked.connect(this, &VtstRtDevTouchFeedback::onButtonClicked);
    }

    void onButtonClicked(VtstButton *source)
    {
        if (source == m_button1)
        {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
        }
        else if (source == m_button2)
        {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN_VIBRATE);
        }
        else if (source == m_button3)
        {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN_TONE);
        }
        else if (source == m_button4)
        {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
        }
        else if (source == m_button5)
        {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_SPECIAL);
        }
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Correct?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_dev_touch_feedback(VfxU32 param)
{
    VTST_START_SCRN(VtstRtDevTouchFeedback);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

