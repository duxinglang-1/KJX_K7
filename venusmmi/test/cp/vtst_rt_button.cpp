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
 *  vtst_rt_button.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Screens for button cp testing
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
 * removed!
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

#if defined(__AFX_RT_TEST__)

#include "vtst_rt_main.h"
#include "vcp_button_util.h"
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vcp_button.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "GlobalResDef.h"
#include "vcp_state_image.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Class VtstRtButtonScr
 *****************************************************************************/

class VtstRtButtonScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtButtonScr();

// Override
protected:
    virtual void onInit();

    virtual VfxS32 start() {return 2;}

    virtual VfxS32 phase(VfxS32 idx);

// implementation
private:
    void onButtonClick(VfxObject* sender, VfxId id);
    VcpButton* m_button1;
    VcpButton* m_button2;
    VcpButton* m_button3;
    VcpButton* m_button4;
    VcpButton* m_button5;
    VcpButton* m_button6;
    VcpButton* m_button7;
    VcpButton* m_button8;
    VcpButton* m_button9;
    VcpButton* m_button10;
    VcpButton* m_button11;
    VcpButton* m_button12;
    VcpButton* m_button13;
    VcpButton* m_button14;
    VcpButton* m_button15;
    VcpButton* m_button16;
    VcpButton* m_button17;
};

VtstRtButtonScr::VtstRtButtonScr():
    m_button1(NULL),
    m_button2(NULL),
    m_button3(NULL),
    m_button4(NULL),
    m_button5(NULL),
    m_button6(NULL),
    m_button7(NULL),
    m_button8(NULL),
    m_button9(NULL),
    m_button10(NULL),
    m_button11(NULL),
    m_button12(NULL),
    m_button13(NULL),
    m_button14(NULL),
    m_button15(NULL),
    m_button16(NULL),
    m_button17(NULL)
{
}

void VtstRtButtonScr::onInit()
{
    VtstRtScr::onInit();
    setTitle(VFX_WSTR("UI Button"));
    setBgColor(VFX_COLOR_WHITE);
}


VfxS32 VtstRtButtonScr::phase(VfxS32 idx)
{
    confirm(VFX_WSTR("Result is correct?"));

    VFX_OBJ_CLOSE(m_button1);
    VFX_OBJ_CLOSE(m_button2);
    VFX_OBJ_CLOSE(m_button3);
    VFX_OBJ_CLOSE(m_button4);
    VFX_OBJ_CLOSE(m_button5);
    VFX_OBJ_CLOSE(m_button6);
    VFX_OBJ_CLOSE(m_button7);
    VFX_OBJ_CLOSE(m_button8);
    VFX_OBJ_CLOSE(m_button9);
    VFX_OBJ_CLOSE(m_button10);
    VFX_OBJ_CLOSE(m_button11);
    VFX_OBJ_CLOSE(m_button12);
    VFX_OBJ_CLOSE(m_button13);
    VFX_OBJ_CLOSE(m_button14);
    VFX_OBJ_CLOSE(m_button15);
    VFX_OBJ_CLOSE(m_button16);
    VFX_OBJ_CLOSE(m_button17);

    VcpButton * testButton;
    VFX_OBJ_CREATE(testButton, VcpButton, this);
    const VfxS32 buttonHeight = testButton->getSize().height;
    VFX_OBJ_CLOSE(testButton);
    const VfxS32 baseX = 10;
    const VfxS32 baseY = 10;
    const VfxS32 space = buttonHeight + 5;
    switch (idx)
    {
    case 0:
    {
        VFX_OBJ_CREATE(m_button1, VcpButton, this);
        m_button1->setPos(VfxPoint(baseX, baseY));
        m_button1->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
        m_button1->setImage(VcpStateImage(IMG_GLOBAL_L1));
        m_button1->setIsAutoResized(VFX_TRUE);

        VFX_OBJ_CREATE(m_button2, VcpButton, this);
        m_button2->setPos(VfxPoint(baseX + buttonHeight * 3 / 2, baseY));
        m_button2->setText(VFX_WSTR("Label"));
        m_button2->setIsAutoResized(VFX_TRUE);


        VFX_OBJ_CREATE(m_button4, VcpButton, this);
        m_button4->setImage(VcpStateImage(IMG_GLOBAL_L1));
        m_button4->setText(VFX_WSTR("Overlap"));
        m_button4->setRect(VfxRect(baseX + buttonHeight * 7 / 2, baseY, buttonHeight * 2, m_button4->getSize().height));
        m_button4->setPlacement(VCP_BUTTON_PLACEMENT_OVERLAP);

        VFX_OBJ_CREATE(m_button3, VcpButton, this);
        m_button3->setImage(VcpStateImage(IMG_GLOBAL_L1));
        m_button3->setText(VFX_WSTR("Left"));
        m_button3->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
        m_button3->setRect(VfxRect(baseX, baseY + space, buttonHeight * 4, m_button3->getSize().height));
        m_button3->setIsAutoResized(VFX_TRUE);
        m_button3->setTextColor(VFX_COLOR_BLACK);

        VFX_OBJ_CREATE(m_button5, VcpButton, this);
        m_button5->setImage(VcpStateImage(IMG_GLOBAL_L1));
        m_button5->setText(VFX_WSTR("Right"));
        m_button5->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_RIGHT);
        m_button5->setRect(VfxRect(baseX, baseY + space * 2, buttonHeight * 4, m_button5->getSize().height));
        m_button5->setIsDisabled(VFX_TRUE);

        VFX_OBJ_CREATE(m_button6, VcpButton, this);
        m_button6->setImage(VcpStateImage(IMG_GLOBAL_L1));
        m_button6->setText(VFX_WSTR("Top"));
        m_button6->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
        m_button6->setRect(VfxRect(baseX, baseY + space * 3, buttonHeight * 2, buttonHeight * 2));
        //m_button6->setIsAutoResized(VFX_TRUE);

        VcpStateImage image(IMG_GLOBAL_L1, IMG_GLOBAL_L2, IMG_GLOBAL_L3, IMG_GLOBAL_L4);
        VFX_OBJ_CREATE(m_button7, VcpButton, this);
        m_button7->setImage(image);
        m_button7->setText(VFX_WSTR("Bottom"));
        m_button7->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_BOTTOM);
        m_button7->setRect(VfxRect(baseX + buttonHeight * 2, baseY + space * 3, buttonHeight * 2, buttonHeight * 2));
        m_button7->m_signalClicked.connect(this, &VtstRtButtonScr::onButtonClick);
        m_button7->setTextColor(VFX_COLOR_RED, VFX_COLOR_GREEN, VFX_COLOR_OLIVE, VFX_COLOR_SILVER);
        m_button7->setIsAutoResized(VFX_TRUE);

        break;
    }
    case 1:
    {
        VFX_OBJ_CREATE(m_button8, VcpButton, this);
        m_button8->setRect(VfxRect(baseX, baseY, buttonHeight * 3, buttonHeight));
        m_button8->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_button8->setText(VFX_WSTR("Label white"));

        VFX_OBJ_CREATE(m_button9, VcpButton, this);
        m_button9->setRect(VfxRect(baseX + buttonHeight * 3, baseY, buttonHeight * 3, buttonHeight));
        m_button9->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
        m_button9->setText(VFX_WSTR("Label green"));
        m_button9->setStyle(VCP_BUTTON_STYLE_DEFAULT_02);

        VFX_OBJ_CREATE(m_button10, VcpButton, this);
        m_button10->setRect(VfxRect(baseX, baseY + space, buttonHeight * 3, buttonHeight));
        m_button10->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_LEFT_IMAGE_RIGHT);
        m_button10->setText(VFX_WSTR("Text"));
        m_button10->setImage(VcpStateImage(IMG_GLOBAL_L1));

        // utility buttons
        m_button11 = vcpCreateArrowButton(this);
        m_button11->setRect(VfxRect(baseX, baseY + space * 2, buttonHeight * 4, buttonHeight));
        VfxS32 x = m_button11->getButtonImageFrame()->getRect().origin.x;
        m_button11->setText(VFX_WSTR("Arrow"));
        m_button11->setRect(VfxRect(baseX, baseY + space * 2, buttonHeight * 3, buttonHeight));
        VfxS32 x2 = m_button11->getButtonImageFrame()->getRect().origin.x;

        m_button12 = vcpCreateAddButton(VFX_FALSE, this);
        m_button12->setPos(baseX + buttonHeight * 3, baseY + space * 2);
        m_button12->setIsAutoResized(VFX_TRUE);

        m_button13 = vcpCreateCancelButton(this);
        m_button13->setPos(baseX + buttonHeight * 4, baseY + space * 2);
        m_button13->setIsAutoResized(VFX_TRUE);

        VFX_OBJ_CREATE(m_button14, VcpButton, this);
        m_button14->setStyle(VCP_BUTTON_STYLE_SIM1);
        m_button14->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
        m_button14->setImage(VcpStateImage(IMG_GLOBAL_L1));
        m_button14->setText(VFX_WSTR("Sim1"));
        m_button14->setRect(VfxRect(baseX, baseY + space * 3, buttonHeight * 3, buttonHeight));

        VFX_OBJ_CREATE(m_button15, VcpButton, this);
        m_button15->setStyle(VCP_BUTTON_STYLE_SIM2);
        m_button15->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
        m_button15->setImage(VcpStateImage(IMG_GLOBAL_L1));
        m_button15->setText(VFX_WSTR("Sim2"));
        m_button15->setPos(baseX + buttonHeight * 3, baseY + space * 3);
        m_button15->setIsAutoResized(VFX_TRUE);

        VFX_OBJ_CREATE(m_button16, VcpButton, this);
        m_button16->setPos(baseX, baseY + space * 4);
        m_button16->setStyle(VCP_BUTTON_STYLE_RED);

        VFX_OBJ_CREATE(m_button17, VcpButton, this);
        m_button17->setPos(baseY + space * 3, baseY + space * 4);
        m_button17->setStyle(VCP_BUTTON_STYLE_NORMAL);
        break;
    }
    default:
        VFX_ASSERT(VFX_FALSE);
        break;
    };
    return -1;
}


void VtstRtButtonScr::onButtonClick(VfxObject* sender, VfxId id)
{
    VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

    if (button)
    {
        if (button->getIsHighlighted())
        {
            button->setIsHighlighted(VFX_FALSE);
        }
        else
        {
            button->setIsHighlighted(VFX_TRUE);
        }
    }
}


VtstTestResultEnum vtst_rt_button(VfxU32 param)
{
    VTST_START_SCRN(VtstRtButtonScr);
    return VTST_TR_OK;
}


#endif /* __AFX_RT_TEST__ */
