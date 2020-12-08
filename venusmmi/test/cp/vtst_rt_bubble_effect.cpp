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
 *  vtst_rt_bubble_effect.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Auto-Animation
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
#include "vcp_bubble_effect.h"
#include "vcp_res.h"
#include "vcp_button.h"

/*****************************************************************************
 * Test for VcpBubbleEffect
 *****************************************************************************/

class VtstRtBubbleEffect : public VtstRtScr
{
// Variable
public:
   VcpBubbleEffect *m_bubbleEffect;

// Constructor / Destructor
public:
    VtstRtBubbleEffect()
    {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxFrame *background;
        VFX_OBJ_CREATE(background, VfxFrame, this);
        background->setRect(0,0,320,480);
        background->setImgContent(VfxImageSrc(VFX_WSTR("E:\\bg.png")));

        VFX_OBJ_CREATE(m_bubbleEffect, VcpBubbleEffect, this);
        m_bubbleEffect->setBounds(0,0,320,480);
        //m_bubbleEffect->setIsInverse(VFX_TRUE);
        m_bubbleEffect->startFloat(VfxPoint(160,400));
        

        VcpButton *tempButton;

        VFX_OBJ_CREATE(tempButton, VcpButton, this);
        tempButton->setText(VFX_WSTR("Stop"));
        tempButton->setPos(20, 350);
        tempButton->setSize(100,30);
        tempButton->setId('Stop');
        tempButton->m_signalClicked.connect(this, &VtstRtBubbleEffect::onButtonClick);

        VFX_OBJ_CREATE(tempButton, VcpButton, this);
        tempButton->setText(VFX_WSTR("Start"));
        tempButton->setPos(20, 310);
        tempButton->setSize(100,30);
        tempButton->setId('Star');
        tempButton->m_signalClicked.connect(this, &VtstRtBubbleEffect::onButtonClick);


        VFX_OBJ_CREATE(m_card, VfxFrame, this);
        m_card->setBgColor(VFX_COLOR_FUCHSIA);
        m_card->setAnchor(0.5, 0.5);
        m_card->setPos(160, 400);
        m_card->setBounds(0, 0, 30, 50);

        
        confirm(VFX_WSTR("Bubble effect OK?"));
        
    }

    void onButtonClick(VfxObject* sender, VfxId id)
    {
        switch (id)
        {
            case 'Stop':
                m_bubbleEffect->stopFloat();
                break;
            case 'Star':
                m_bubbleEffect->startFloat(VfxPoint(160,400));
                break;
            default:
                break;
        }
    }

    virtual VfxBool onPenInput(VfxPenEvent & event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            m_bubbleEffect->shiftFloat(event.downPos);
            m_card->setPos(event.downPos);
            return VFX_TRUE;
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
        {
            m_bubbleEffect->shiftFloat(event.pos);
            m_card->setPos(event.pos);
            return VFX_TRUE;
        }
        return VtstRtScr::onPenInput(event);
    }


    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            return -1;
        }
        return VTST_RT_END_TESTCASE;
    }

    VfxFrame *m_card;
};


VtstTestResultEnum vtst_rt_bubble_effect(VfxU32 param)
{
    VTST_START_SCRN(VtstRtBubbleEffect);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

