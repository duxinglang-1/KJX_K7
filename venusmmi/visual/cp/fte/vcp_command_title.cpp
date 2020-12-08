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
 *  vcp_command_title.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Common title component
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

#include "vcp_command_title.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vfx_basic_type.h"
#include "vfx_text_frame.h"
#include "vfx_frame.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "vcp_button.h"
#include "vcp_state_image.h"
#include "mmi_rp_srv_venus_component_command_title_def.h"

/***************************************************************************** 
 * Class VcpCommandTitle
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpCommandTitle", VcpCommandTitle, VfxControl);


VcpCommandTitle::VcpCommandTitle() :
    m_frameText(NULL),
    m_sizeText(0, 0)
{
    for (VfxS32 i = 0 ; i < MAX_ADDON_FRAMES ; i++)
    {
        m_frameAddOn[i] = NULL;

        m_button[i] = NULL;
        m_buttonId[i] = 0;
        m_callback[i] = VFX_CALLBACK_NULL;
    }
}


void VcpCommandTitle::onInit()
{
    VfxControl::onInit();

    // set default size
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    setSize(VfxSize(main_screen_size.width, DEFAULT_HEIGHT));

    // set visual
  //  createVisual(VIS_ID_COMMAND_TITLE);
  //  getVisual()->setType(VfxVisual::TYPE_NORMAL);
	setImgContent(VfxImageSrc(VCP_IMG_COMMANDTITLE_N));
	setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    // create label frame
    VFX_OBJ_CREATE(m_frameText, VfxTextFrame, this);
    m_frameText->setAnchor(VfxFPoint(0.5, 0.5));
    m_frameText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_frameText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_frameText->setAutoAnimate(VFX_TRUE);

    // register signal
    m_signalBoundsChanged.connect(this, &VcpCommandTitle::onBoundsChanged);

    checkUpdate();
}


void VcpCommandTitle::onDeInit()
{
    for (VfxS32 i = 0 ; i < MAX_ADDON_FRAMES ; i++)
    {
        VFX_OBJ_CLOSE(m_frameAddOn[i]);
    }

    VfxControl::onDeinit();
}


void VcpCommandTitle::onUpdate()
{
    VfxRect clientRect = getBounds();// (getVisual()) ? (getVisual()->getClientArea(VfxVisual::TYPE_NORMAL)) : (getBounds());
    VfxS32 left_margin = 0, right_margin = 0;

    // decide item position
    VfxFrame *frame = m_frameAddOn[0];
    if (frame)
    {
        frame->setAnchor(VfxFPoint(0.0, 0.5));
        frame->setPos(VfxPoint(clientRect.getMinX(), clientRect.getMidY()));

        left_margin = frame->getSize().width + GAP;
    }
    
    frame = m_frameAddOn[1];
    if (frame)
    {
        frame->setAnchor(VfxFPoint(1.0, 0.5));
        frame->setPos(VfxPoint(clientRect.getMaxX(), clientRect.getMidY()));

        right_margin = frame->getSize().width + GAP;
    }

    m_frameText->setSize(clientRect.size);
    m_frameText->setPos(VfxPoint(clientRect.getMidX(), clientRect.getMidY()));
    m_frameText->setMargins(left_margin, 0, right_margin, 0);
}


void VcpCommandTitle::setText (const VfxWString &str)
{
    VfxFontDesc font;

    m_sizeText = font.measureStr(str.getBuf());
    m_frameText->setString(str);
    checkUpdate();
}


void VcpCommandTitle::setAddOnFrame (VfxU32 index, VfxFrame *frame)
{
    // close old item
    VFX_OBJ_CLOSE(m_frameAddOn[index]);

    // add new item
    m_frameAddOn[index] = frame;
    addChildFrame(frame);
    frame->m_signalBoundsChanged.connect(this, &VcpCommandTitle::onItemBoundsChange);
    checkUpdate();
}


void VcpCommandTitle::setAddOnTextButton (VfxU32 index, const VfxWString &str, VfxId id, VcpCommandTitleButtonCB handler)
{
    VcpButton* button;

    // create new button
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setText(str);
    button->setTextFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    button->setIsAutoResized(VFX_TRUE, BUTTON_MIN_WIDTH, 0);
    button->setSize(BUTTON_MIN_WIDTH, BUTTON_HEIGHT);
    button->m_signalClicked.connect(this, &VcpCommandTitle::buttonClick);
    button->setAutoAnimate(VFX_TRUE);

    // add to title
    setAddOnFrame(index, button);

    m_button[index] = button;
    m_buttonId[index] = id;
    m_callback[index] = handler;
}


void VcpCommandTitle::setAddOnImageButton (VfxU32 index, const VcpStateImage &imageList, VfxId id, VcpCommandTitleButtonCB handler)
{
    VcpButton* button;

    // create new button
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setImage(imageList);
    button->setIsAutoResized(VFX_TRUE, BUTTON_MIN_WIDTH, 0);
    button->setSize(BUTTON_MIN_WIDTH, BUTTON_HEIGHT);
    button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    button->m_signalClicked.connect(this, &VcpCommandTitle::buttonClick);
    button->setAutoAnimate(VFX_TRUE);

    // add to title
    setAddOnFrame(index, button);

    m_button[index] = button;
    m_buttonId[index] = id;
    m_callback[index] = handler;
}


void VcpCommandTitle::setButtonIsDisabled (VfxId id, VfxBool isDisabled)
{
    for (VfxS32 i = 0 ; i < MAX_ADDON_FRAMES ; i++)
    {
        if (m_buttonId[i] == id && m_button[i] != NULL)
        {
            m_button[i]->setIsDisabled(isDisabled);
        }
    }
}


VfxBool VcpCommandTitle::getButtonIsDisabled (VfxId id) const
{
    for (VfxS32 i = 0 ; i < MAX_ADDON_FRAMES ; i++)
    {
        if (m_buttonId[i] == id && m_button[i] != NULL)
        {
            return m_button[i]->getIsDisabled();
        }
    }

    return VFX_FALSE;
}


void VcpCommandTitle::buttonClick(VfxObject* sender, VfxId id)
{
    VcpButton* button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);
    VfxS32 i = 0;

    for (i = 0 ; i < MAX_ADDON_FRAMES ; i++)
    {
        if (m_button[i] == button)
        {
            break;
        }
    }

    if (i < MAX_ADDON_FRAMES)
    {
        m_callback[i].invoke(this, m_buttonId[i]);
    }
}

