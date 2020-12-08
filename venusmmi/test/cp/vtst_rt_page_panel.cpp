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
 *  vtst_frame_anchor.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  A Frame Anchor Point example for Venus UI
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

#include "vtst_rt_page_panel.h"
#include "vcp_button.h"
#include "vtst_rt_main.h"
#include "vcp_page_panel.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vcp_frame_effect.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vfx_text_frame.h"
#include "vfx_input_event.h"
#include "vcp_frame_effect_type.h"
#include "vfx_app_cat_scr.h"

#include "vapp_platform_context.h"

static const VfxWChar *effectName[VCP_PAGE_EFFECT_END] = 
{
    (const VfxWChar *)L"None",
    (const VfxWChar *)L"Fade in",
    (const VfxWChar *)L"Flip",
    (const VfxWChar *)L"Push",
    (const VfxWChar *)L"Enter",
    (const VfxWChar *)L"Leave",
    (const VfxWChar *)L"Zoom",
    (const VfxWChar *)L"Big",
    (const VfxWChar *)L"Small flip",
    (const VfxWChar *)L"Flip out Flip in",
    (const VfxWChar *)L"Cosmos entry",
    (const VfxWChar *)L"3D Circle",
    (const VfxWChar *)L"3D Cube",
    (const VfxWChar *)L"3D Blinds",
    (const VfxWChar *)L"3D Brick",
    (const VfxWChar *)L"3D Twist",
    (const VfxWChar *)L"3D Curl",
    (const VfxWChar *)L"3D Fusion",
    (const VfxWChar *)L"3D Ripple"
};

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
VtstRtPagePanel::VtstRtPagePanel() :
    m_page(NULL),
    m_test(NULL),
    m_controlText(NULL),
    m_targetFrame(NULL),
    m_transitionType(VCP_PAGE_EFFECT_3D_CIRCLE),
    m_list(NULL)
{
}

void VtstRtPagePanel::onInit()
{
    VtstRtScr::onInit();

    /*
     * Setup the background color
     */
    setBgColor(VFX_COLOR_BLUE);

    VFX_OBJ_CREATE(m_page, VcpPagePanel, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
    addChildFrame(m_page);
    
    m_page->setPos(VfxPoint(0, 0));
    m_page->setSize(getSize());

    VFX_OBJ_CREATE(m_frame1, VfxFrame, m_page);
    m_frame1->setSize(getSize());
    m_frame1->setImgContent(VfxImageSrc(VFX_WSTR("E:\\FrameEffect\\beanFlower2.jpg")));
    m_frame1->setBgColor(VFX_COLOR_RED);
    m_frame1->setIsCached(VFX_TRUE);
    
    VFX_OBJ_CREATE(m_control1, VfxControl, m_page);
    m_control1->setSize(getSize());
    m_control1->setImgContent(VfxImageSrc(VFX_WSTR("E:\\FrameEffect\\beanFlower3.jpg")));
    m_control1->setBgColor(VFX_COLOR_YELLOW);
    m_control1->setIsCached(VFX_TRUE);
    
   // Create a text
    VFX_OBJ_CREATE(m_controlText, VfxTextFrame, this);
    m_controlText->setPos(VfxPoint(10, 30));
    m_controlText->setColor(VFX_COLOR_BLACK);
    m_controlText->setBgColor(VFX_COLOR_GREY);
    m_controlText->setAutoAnimate(VFX_TRUE);
    m_controlText->setString(VFX_WSTR("Hello Page"));

    m_targetFrame = m_control1;

    m_page->setCurrentFrame(m_frame1);
    
    VFX_OBJ_CREATE(m_list, VcpListMenu, m_frame1);
    m_list->setSize(getSize().width, getSize().height * 4 / 5);
    m_list->setContentProvider(this);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->m_signalItemTapped.connect(this, &VtstRtPagePanel::onItemSelected);

    VfxFrame *colorFrame;
    VFX_OBJ_CREATE(colorFrame, VfxFrame, m_control1);
    colorFrame->setRect(0, 0, getSize().width/2, getSize().height/2);
    colorFrame->setBgColor(VFX_COLOR_GREEN);
        


    VcpButton *button;

    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setText(VFX_WSTR("Left"));
    button->setPos(0, getSize().height - 100);
    button->setSize(60, 40);
    button->setId(VFX_KEY_CODE_4);
    button->m_signalClicked.connect(this, &VtstRtPagePanel::onButtonClick);

    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setText(VFX_WSTR("right"));
    button->setPos(60, getSize().height - 100);
    button->setSize(60, 40);
    button->setId(VFX_KEY_CODE_6);
    button->m_signalClicked.connect(this, &VtstRtPagePanel::onButtonClick);

    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setText(VFX_WSTR("up"));
    button->setPos(120, getSize().height - 100);
    button->setSize(60, 40);
    button->setId(VFX_KEY_CODE_2);
    button->m_signalClicked.connect(this, &VtstRtPagePanel::onButtonClick);

    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setText(VFX_WSTR("bottom"));
    button->setPos(180, getSize().height - 100);
    button->setSize(60, 40);
    button->setId(VFX_KEY_CODE_8);
    button->m_signalClicked.connect(this, &VtstRtPagePanel::onButtonClick);

    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setText(VFX_WSTR("back"));
    button->setPos(240, getSize().height - 100);
    button->setSize(60, 40);
    button->setId(VFX_KEY_CODE_9);
    button->m_signalClicked.connect(this, &VtstRtPagePanel::onButtonClick);
}


VfxBool VtstRtPagePanel::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{ 
    text = VFX_WSTR_STATIC(effectName[index]); 
    return VFX_TRUE;
}


void VtstRtPagePanel::onItemSelected(VcpListMenu *sender, VfxU32 index)
{
    m_transitionType = (VcpPageEffectType)index;
    updateText();
}

void VtstRtPagePanel::updateText()
{
    if (m_transitionType == VCP_PAGE_EFFECT_END)
    {
        m_transitionType = VCP_PAGE_EFFECT_NONE;
    }

    m_controlText->setString(VFX_WSTR_STATIC(effectName[m_transitionType]));
}

void VtstRtPagePanel::onButtonClick(VfxObject* sender, VfxId id)
{
    VfxWString temp;
    VfxS32 temp2;
   
    switch(id)
    {
        case VFX_KEY_CODE_1:
            temp2 = (VfxS32)m_transitionType;
            temp2 ++;
            m_transitionType = (VcpPageEffectType)temp2;
            //m_transitionType ++;
            updateText();
            return;
        case VFX_KEY_CODE_2:
            if (m_targetFrame == m_control1)
            {
                m_targetFrame = m_frame1;
            }
            else
            {
                m_targetFrame = m_control1;
            }
            m_page->switchTo(m_targetFrame, m_transitionType, 10000, VCP_PAGE_DIRECTION_FROM_UP);
            return;
        case VFX_KEY_CODE_3:
            m_frameEffect->applyEffect(m_frame3, VCP_EFFECT_FLIP, 2000, VCP_EFFECT_DIRECTION_FROM_LEFT);
            return;
        case VFX_KEY_CODE_4:
            if (m_targetFrame == m_control1)
            {
                m_targetFrame = m_frame1;
            }
            else
            {
                m_targetFrame = m_control1;
            }
            m_page->switchTo(m_targetFrame, m_transitionType, 10000, VCP_PAGE_DIRECTION_FROM_LEFT);
            return;
        case VFX_KEY_CODE_5:
            if (m_targetFrame == m_control1)
            {
                m_targetFrame = m_frame1;
            }
            else
            {
                m_targetFrame = m_control1;
            }
            m_page->switchTo(m_targetFrame, m_transitionType, 2000);
            return;
        case VFX_KEY_CODE_6:
            if (m_targetFrame == m_control1)
            {
                m_targetFrame = m_frame1;
            }
            else
            {
                m_targetFrame = m_control1;
            }
            m_page->switchTo(m_targetFrame, m_transitionType, 10000, VCP_PAGE_DIRECTION_FROM_RIGHT);
            return;
       case VFX_KEY_CODE_8:
            if (m_targetFrame == m_control1)
            {
                m_targetFrame = m_frame1;
            }
            else
            {
                m_targetFrame = m_control1;
            }
            m_page->switchTo(m_targetFrame, m_transitionType, 10000, VCP_PAGE_DIRECTION_FROM_BOTTOM);
            return;
       case VFX_KEY_CODE_9:
            if (m_targetFrame == m_control1)
            {
                m_targetFrame = m_frame1;
            }
            else
            {
                m_targetFrame = m_control1;
            }
            m_page->switchTo(m_targetFrame, m_transitionType, 2000, VCP_PAGE_DIRECTION_BACKWARD);
            return;
    }
}
VfxBool VtstRtPagePanel::onKeyInput(VfxKeyEvent &event)
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
                m_transitionType = (VcpPageEffectType)temp2;
                //m_transitionType ++;
                updateText();
                return VFX_TRUE;
            case VFX_KEY_CODE_2:
                if (m_targetFrame == m_control1)
                {
                    m_targetFrame = m_frame1;
                }
                else
                {
                    m_targetFrame = m_control1;
                }
                m_page->switchTo(m_targetFrame, m_transitionType, 2000, VCP_PAGE_DIRECTION_FROM_UP);
                return VFX_TRUE;
            case VFX_KEY_CODE_3:
                m_frameEffect->applyEffect(m_frame3, VCP_EFFECT_FLIP, 2000, VCP_EFFECT_DIRECTION_FROM_LEFT);
                return VFX_TRUE;
            case VFX_KEY_CODE_4:
                if (m_targetFrame == m_control1)
                {
                    m_targetFrame = m_frame1;
                }
                else
                {
                    m_targetFrame = m_control1;
                }
                m_page->switchTo(m_targetFrame, m_transitionType, 2000, VCP_PAGE_DIRECTION_FROM_LEFT);
                return VFX_TRUE;
            case VFX_KEY_CODE_5:
                if (m_targetFrame == m_control1)
                {
                    m_targetFrame = m_frame1;
                }
                else
                {
                    m_targetFrame = m_control1;
                }
                m_page->switchTo(m_targetFrame, m_transitionType, 2000);
                return VFX_TRUE;
            case VFX_KEY_CODE_6:
                if (m_targetFrame == m_control1)
                {
                    m_targetFrame = m_frame1;
                }
                else
                {
                    m_targetFrame = m_control1;
                }
                m_page->switchTo(m_targetFrame, m_transitionType, 2000, VCP_PAGE_DIRECTION_FROM_RIGHT);
                return VFX_TRUE;
            case VFX_KEY_CODE_7:
                if (m_targetFrame == m_control1)
                {
                    m_targetFrame = m_frame1;
                }
                else
                {
                    m_targetFrame = m_control1;
                }
                VcpPageZoomData input;
                input.ScaleXonCurrentFrame = 2.0;
                input.ScaleYonCurrentFrame = 2.0;
                input.ScaleXonTargetFrame = 0.5;
                input.ScaleYonTargetFrame = 0.5;
                m_page->switchTo(m_targetFrame, m_transitionType, 2000, VCP_PAGE_DIRECTION_FROM_LEFT, VFX_FALSE, &input, sizeof(VcpPageZoomData));
                
                return VFX_TRUE;
            case VFX_KEY_CODE_8:
                if (m_targetFrame == m_control1)
                {
                    m_targetFrame = m_frame1;
                }
                else
                {
                    m_targetFrame = m_control1;
                }
                m_page->switchTo(m_targetFrame, m_transitionType, 2000, VCP_PAGE_DIRECTION_FROM_BOTTOM);
                return VFX_TRUE;
            case VFX_KEY_CODE_9:
                if (m_targetFrame == m_control1)
                {
                    m_targetFrame = m_frame1;
                }
                else
                {
                    m_targetFrame = m_control1;
                }
                m_page->switchTo(m_targetFrame, m_transitionType, 2000, VCP_PAGE_DIRECTION_BACKWARD);
                
                return VFX_TRUE;
            case VFX_KEY_CODE_0:
                
                return VFX_TRUE;
        }
    }
    return VtstRtScr::onKeyInput(event);
}


VtstTestResultEnum vtst_rt_page_panel(VfxU32 param)
{
    VTST_START_SCRN(VtstRtPagePanel);
    return VTST_TR_OK;
}
#endif /*__AFX_RT_TEST__ */
