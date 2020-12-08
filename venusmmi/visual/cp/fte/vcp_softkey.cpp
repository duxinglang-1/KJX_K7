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
 *  vcp_softkey.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_softkey.h"
#include "vcp_res.h"

#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "vrt_system.h"
#include "vfx_input_event.h"

#ifdef __cplusplus
extern "C"
{
#include "kal_release.h"
#include "kal_general_types.h"
#include "mmi_rp_srv_venus_component_softkey_def.h"
}
#endif 
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VCP_SOFTKEY_CLASS_NAME, VcpSoftkey, VfxControl);

static const vrt_font_struct s_softkeyDefaultFont = {1, 0, 0, 1, 0, 1, 0, 0, VRT_TRUE};
/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VcpSoftkeyConfig::VcpSoftkeyConfig
 * DESCRIPTION
 *  Object constructor
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VcpSoftkeyConfig::VcpSoftkeyConfig():
    m_icon(NULL),
    m_isDisplayed(VFX_FALSE),
    m_isDisabled(VFX_FALSE),
    m_next(NULL)
{

}

VcpSoftkeyConfig::~VcpSoftkeyConfig()
{
    if (m_next)
    {
        delete m_next;
        m_next = NULL;
    }
}


VcpSoftkey::VcpSoftkey():
    m_normalColor(VFX_COLOR_WHITE),
    m_normalBorderColor(VFX_COLOR_BLACK),
    m_downColor(VFX_COLOR_WHITE),
    m_downBorderColor(VFX_COLOR_BLACK),
    m_borderGap(VCP_SOFTKEY_BORDER_GAP),
    m_shiftOffset(VCP_SOFTKEY_SHIFT_OFFSET),
    m_background(NULL),
    m_font(VfxFontDesc(s_softkeyDefaultFont))
{
    VfxS32 i;

    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        m_buttons[i] = NULL;
        m_softkeyConfig[i] = NULL;
    }
}


const VfxColor &VcpSoftkey::getNormalColor() const
{
    return m_normalColor;
}


const VfxColor &VcpSoftkey::getNormalBorderColor() const
{
    return m_normalBorderColor;
}


const VfxColor &VcpSoftkey::getDownColor() const
{
    return m_downColor;
}


const VfxColor &VcpSoftkey::getDownBorderColor() const
{
    return m_downBorderColor;
}


VfxS32 VcpSoftkey::getBorderGap() const
{
    return m_borderGap;
}


VfxS32 VcpSoftkey::getShiftOffset() const
{
    return m_shiftOffset;
}


void VcpSoftkey::setNormalColor(const VfxColor &value)
{
    m_normalColor = value;

    textColorChanged();
}


void VcpSoftkey::setNormalBorderColor(const VfxColor &value)
{
    m_normalBorderColor = value;

    textColorChanged();
}


void VcpSoftkey::setDownColor(const VfxColor &value)
{
    m_downColor = value;

    textColorChanged();
}


void VcpSoftkey::setDownBorderColor(const VfxColor &value)
{
    m_downBorderColor = value;

    textColorChanged();
}


void VcpSoftkey::setBorderGap(VfxS32 value)
{
    m_borderGap = value;
    
    realignSoftkey(VCP_SOFTKEY_LSK);
    realignSoftkey(VCP_SOFTKEY_RSK);
}


void VcpSoftkey::setShiftOffset(VfxS32 value)
{
    m_shiftOffset = value;

    VfxS32 i;
    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        realignSoftkey((VcpSoftkeyEnum)i);
    }
}


void VcpSoftkey::setSoftkey(VcpSoftkeyEnum sk, const VfxWString &label, const VfxImageSrc &icon)
{
    assertValidSoftkey(sk);
    
    m_softkeyConfig[sk]->m_label= label;
    m_softkeyConfig[sk]->m_icon= icon;

    // TODO: Justin: VfxWString & VfxImage should provide isEmpty() method        
    // if (!label.isEmpty() || !icon.isEmpty()) 
    // {
    //    c->m_isDisplayed = VFX_TRUE;
    // }
    // else
    // {
    //    // In case that user clear the softkey label & icon 
    //    c->m_isDisplayed = VFX_FALSE;
    // }
    // TODO: remember to setup the button here

    if (!label.isNull())
    {
        VfxTextFrame *tempUpLabel, *tempDownLabel;
        VFX_OBJ_CREATE(tempUpLabel, VfxTextFrame, m_buttons[sk]);
        VFX_OBJ_CREATE(tempDownLabel, VfxTextFrame, m_buttons[sk]);
        tempUpLabel->setString(label);
        tempUpLabel->setColor(this->getNormalColor());
        tempUpLabel->setBorderColor(this->getNormalBorderColor());
        tempDownLabel->setString(label);
        tempDownLabel->setColor(this->getDownColor());
        tempDownLabel->setBorderColor(this->getDownBorderColor());

        if (sk == VCP_SOFTKEY_LSK)
        {
            tempUpLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            tempDownLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        }
        if (sk == VCP_SOFTKEY_RSK)
        {
            tempUpLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
            tempDownLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        }
        if (sk == VCP_SOFTKEY_CSK)
        {
            tempUpLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
            tempDownLabel->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        }
        m_buttons[sk]->setBackgroundUp(tempUpLabel);
        m_buttons[sk]->setBackgroundDown(tempDownLabel);
    }

    if (!icon.isNull() && !icon.isEmpty())
    {
        m_buttons[sk]->setBackgroundUp(icon, VFX_FALSE);
        m_buttons[sk]->setBackgroundDown(icon, VFX_FALSE);
    }
    realignSoftkey(sk);
}


void VcpSoftkey::setSoftkeyBackground(VcpSoftkeyEnum sk, const VfxImageSrc &background)
{
    assertValidSoftkey(sk);
    m_buttons[sk]->setImgContent(background);
}


void VcpSoftkey::setSoftkeyBackgroundContentPlacement(VcpSoftkeyEnum sk, VfxFrameContentPlacementTypeEnum value)
{
    assertValidSoftkey(sk);
    m_buttons[sk]->setContentPlacement(value);
}


void VcpSoftkey::setFont(const VfxFontDesc &font)
{
    m_font = font;

    VfxS32 i;
    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        if (m_softkeyConfig[i]->m_label)
        {
            realignSoftkey((VcpSoftkeyEnum)i);
        }
    }
}


void VcpSoftkey::realignSoftkey(VcpSoftkeyEnum sk)
{
    assertValidSoftkey(sk);

    VfxPoint pos = VFX_POINT_ZERO;
    VfxRect bounds = VFX_RECT_ZERO;

    if (m_softkeyConfig[sk]->m_label)
    {
        VfxTextFrame *tempFrame = NULL;
        tempFrame = (VfxTextFrame *)m_buttons[sk]->getBackgroundUp();
        tempFrame->setFont(m_font);
        tempFrame = (VfxTextFrame *)m_buttons[sk]->getBackgroundDown();
        tempFrame->setFont(m_font);
        bounds.size.height = tempFrame->getMeasureBounds().size.height;
        bounds.size.width = tempFrame->getMeasureBounds().size.width;

        pos.y = (m_buttons[sk]->getBounds().size.height - bounds.size.height) / 2;
        if (sk == VCP_SOFTKEY_LSK)
        {
            pos.x = getBorderGap();
        }
        if (sk == VCP_SOFTKEY_RSK)
        {
            pos.x = m_buttons[sk]->getBounds().size.width - getBorderGap() - bounds.size.width;
            if (pos.x < 0)
            {
                pos.x = 0;
            }
        }
        if (sk == VCP_SOFTKEY_CSK)
        {
            pos.x = (m_buttons[sk]->getBounds().size.width - bounds.size.width) / 2;
        }
    }
    else if (!(m_softkeyConfig[sk]->m_icon.isNull()) && !(m_softkeyConfig[sk]->m_icon.isEmpty()))
    {
        bounds.size = m_softkeyConfig[sk]->m_icon.getSize();
        pos.y = (m_buttons[sk]->getBounds().size.height - bounds.size.height) / 2;
        if (sk == VCP_SOFTKEY_LSK)
        {
            pos.x = getBorderGap();
        }
        if (sk == VCP_SOFTKEY_RSK)
        {
            pos.x = m_buttons[sk]->getBounds().size.width - getBorderGap() - bounds.size.width;
        }
        if (sk == VCP_SOFTKEY_CSK)
        {
            pos.x = (m_buttons[sk]->getBounds().size.width - bounds.size.width) / 2;
        }
    }

    m_buttons[sk]->getBackgroundUp()->setPos(pos);
    pos.x += getShiftOffset();
    pos.y += getShiftOffset();
    m_buttons[sk]->getBackgroundDown()->setPos(pos);
        
    m_buttons[sk]->getBackgroundUp()->setBounds(bounds);
    m_buttons[sk]->getBackgroundDown()->setBounds(bounds);
}


void VcpSoftkey::setSoftkeyWidth(VcpSoftkeyEnum sk, VfxS32 width)
{
    assertValidSoftkey(sk);
    vrt_size_struct main_screen_size;
    VfxColorTypeEnum main_screen_color_format;
    VfxRect bounds = m_buttons[sk]->getBounds();
    if (sk == VCP_SOFTKEY_LSK)
    {
        m_buttons[sk]->setBounds(VfxRect(0, 0, width + getBorderGap() + getShiftOffset(), bounds.size.height));
    }
    if (sk == VCP_SOFTKEY_RSK)
    {
        m_buttons[sk]->setBounds(VfxRect(0, 0, width + getBorderGap(), bounds.size.height));
    }
    if (sk == VCP_SOFTKEY_CSK)
    {
        m_buttons[sk]->setBounds(VfxRect(0, 0, width + getShiftOffset(), bounds.size.height));
    }
    vrt_sys_get_main_screen_info(
        &main_screen_size, 
        &main_screen_color_format);
    if (sk == VCP_SOFTKEY_RSK)
    {
        m_buttons[sk]->setPos(VfxPoint(main_screen_size.width - width - getBorderGap(), 0));
    }
    realignSoftkey(sk);
}


VfxS32 VcpSoftkey::getSoftkeyWidth(VcpSoftkeyEnum sk)
{
    assertValidSoftkey(sk);
    return m_buttons[sk]->getBounds().size.width;
}


void VcpSoftkey::onBoundsValueChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);
    
    VfxS32 i;
    VfxRect bounds = VFX_RECT_ZERO;

    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        bounds = m_buttons[i]->getBounds();
        bounds.size.height = getBounds().size.height;
        m_buttons[i]->setBounds(bounds);
        realignSoftkey((VcpSoftkeyEnum)i);
    }
}


void VcpSoftkey::textColorChanged()
{
    VfxS32 i;
    VfxTextFrame *tempFrame = NULL;
    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        if (m_softkeyConfig[i]->m_label)
        {
            tempFrame = (VfxTextFrame *)m_buttons[i]->getBackgroundDown();
            tempFrame->setColor(this->getDownColor());
            tempFrame->setBorderColor(this->getDownBorderColor());
            tempFrame = (VfxTextFrame *)m_buttons[i]->getBackgroundUp();
            tempFrame->setColor(this->getNormalColor());
            tempFrame->setBorderColor(this->getNormalBorderColor());
        }
    }
}


vcp_softkey_callback_type & VcpSoftkey::getCallback(VcpSoftkeyEnum sk) const
{
    assertValidSoftkey(sk);
    return m_softkeyConfig[sk]->m_callback;
}


void VcpSoftkey::pushSoftkeyConfig(VcpSoftkeyEnum sk)
{
    assertValidSoftkey(sk);

    VcpSoftkeyConfig *c = new VcpSoftkeyConfig;
    c->m_next = m_softkeyConfig[sk];
    m_softkeyConfig[sk] = c;
    
    m_buttons[sk]->disable(m_softkeyConfig[sk]->m_isDisabled);
}

void VcpSoftkey::popSoftkeyConfig(VcpSoftkeyEnum sk)
{
    assertValidSoftkey(sk);
    VcpSoftkeyConfig *c = m_softkeyConfig[sk];
    VFX_ASSERT(c->m_next);
    m_softkeyConfig[sk] = c->m_next;
    c->m_next = NULL;
    delete c;

    m_buttons[sk]->disable(m_softkeyConfig[sk]->m_isDisabled);
}


void VcpSoftkey::setSoftkeyBarBackground(VfxFrame *f)
{
    VFX_OBJ_ASSERT_VALID(f);

    replaceChildFrameWith(m_background, f);

    VFX_OBJ_CLOSE(m_background);
    
    m_background = f;
}


VfxFrame * VcpSoftkey::getSoftkeyBarBackground() const
{
    return m_background;
}


void VcpSoftkey::hideSoftkey(VcpSoftkeyEnum sk)
{
    assertValidSoftkey(sk);

    m_buttons[sk]->setHidden(VFX_TRUE);
}

void VcpSoftkey::disableSoftkey(VcpSoftkeyEnum sk, VfxBool isDisabled)
{
    assertValidSoftkey(sk);

    m_softkeyConfig[sk]->m_isDisabled = isDisabled;
    m_buttons[sk]->disable(isDisabled);
}

void VcpSoftkey::disableSoftkey(VfxBool isDisabled)
{
    VfxS32 i;
    
    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        disableSoftkey((VcpSoftkeyEnum) i, isDisabled);
    }
}

void VcpSoftkey::unhideSoftkey(VcpSoftkeyEnum sk)
{
    assertValidSoftkey(sk);

    m_buttons[sk]->setHidden(VFX_FALSE);
}

void VcpSoftkey::onInit()
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 i;
    vrt_size_struct main_screen_size;
    VfxColorTypeEnum main_screen_color_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VfxControl::onInit();
    
    vrt_sys_get_main_screen_info(
        &main_screen_size, 
        &main_screen_color_format);

    this->setBounds(VfxRect(0, 0, main_screen_size.width, VCP_SOFTKEY_HEIGHT));

    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setPos(VFX_POINT_ZERO);
    m_background->setBounds(VfxRect(0, 0, main_screen_size.width, VCP_SOFTKEY_HEIGHT));
    m_background->setBgColor(VFX_COLOR_TRANSPARENT);

    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        VFX_OBJ_CREATE(m_buttons[i], VcpButtonInternal, this);
        m_softkeyConfig[i] = new VcpSoftkeyConfig;
    }

    m_buttons[VCP_SOFTKEY_LSK]->setKeyCode(VFX_KEY_CODE_LSK);
    m_buttons[VCP_SOFTKEY_RSK]->setKeyCode(VFX_KEY_CODE_RSK);
    m_buttons[VCP_SOFTKEY_CSK]->setKeyCode(VFX_KEY_CODE_ENTER);

    m_buttons[VCP_SOFTKEY_LSK]->setPos(VFX_POINT_ZERO);
    m_buttons[VCP_SOFTKEY_RSK]->setPos(VfxPoint(main_screen_size.width - VCP_SOFTKEY_LRSK_WIDTH, 0));
    m_buttons[VCP_SOFTKEY_CSK]->setAnchor(VfxFPoint(0.5, 0));
    m_buttons[VCP_SOFTKEY_CSK]->setPos(VfxPoint(main_screen_size.width / 2, 0));

    m_buttons[VCP_SOFTKEY_LSK]->setBounds(VfxRect(0, 0, VCP_SOFTKEY_LRSK_WIDTH, VCP_SOFTKEY_HEIGHT));
    m_buttons[VCP_SOFTKEY_RSK]->setBounds(VfxRect(0, 0, VCP_SOFTKEY_LRSK_WIDTH, VCP_SOFTKEY_HEIGHT));
    m_buttons[VCP_SOFTKEY_CSK]->setBounds(VfxRect(0, 0, VCP_SOFTKEY_CSK_WIDTH, VCP_SOFTKEY_HEIGHT));

    {
        VfxImageSrc lsk_down(VCP_IMG_SOFTKEY_LSK_DOWN);
        VfxImageSrc lsk_up(VCP_IMG_SOFTKEY_LSK_UP);
        VfxImageSrc rsk_down(VCP_IMG_SOFTKEY_RSK_DOWN);
        VfxImageSrc rsk_up(VCP_IMG_SOFTKEY_RSK_UP);

    m_buttons[VCP_SOFTKEY_LSK]->setBackgroundDown(lsk_down);
    m_buttons[VCP_SOFTKEY_LSK]->setBackgroundUp(lsk_up);
    m_buttons[VCP_SOFTKEY_RSK]->setBackgroundDown(rsk_down);
    m_buttons[VCP_SOFTKEY_RSK]->setBackgroundUp(rsk_up);
    }

    m_buttons[VCP_SOFTKEY_LSK]->m_eventDown.connect(this,           &VcpSoftkey::onEvent_LSKButtonDown);
    m_buttons[VCP_SOFTKEY_LSK]->m_eventUp.connect(this,              &VcpSoftkey::onEvent_LSKButtonUp);
    m_buttons[VCP_SOFTKEY_LSK]->m_eventLongpress.connect(this,     &VcpSoftkey::onEvent_LSKButtonLongpress);

    m_buttons[VCP_SOFTKEY_RSK]->m_eventDown.connect(this,           &VcpSoftkey::onEvent_RSKButtonDown);
    m_buttons[VCP_SOFTKEY_RSK]->m_eventUp.connect(this,              &VcpSoftkey::onEvent_RSKButtonUp);
    m_buttons[VCP_SOFTKEY_RSK]->m_eventLongpress.connect(this,     &VcpSoftkey::onEvent_RSKButtonLongpress);

    m_buttons[VCP_SOFTKEY_CSK]->m_eventDown.connect(this,           &VcpSoftkey::onEvent_CSKButtonDown);
    m_buttons[VCP_SOFTKEY_CSK]->m_eventUp.connect(this,              &VcpSoftkey::onEvent_CSKButtonUp);
    m_buttons[VCP_SOFTKEY_CSK]->m_eventLongpress.connect(this,     &VcpSoftkey::onEvent_CSKButtonLongpress);
    
    m_signalBoundsChanged.connect(this, &VcpSoftkey::onBoundsValueChanged);
#ifdef __LOW_COST_SUPPORT_COMMON__
    m_buttons[VCP_SOFTKEY_LSK]->disableUpRedraw(VFX_TRUE);
    m_buttons[VCP_SOFTKEY_RSK]->disableUpRedraw(VFX_TRUE);
#endif
}


void VcpSoftkey::onDeinit()
{
    VfxS32 i;

    for (i = 0; i < VCP_SOFTKEY_TOTAL; i++)
    {
        delete m_softkeyConfig[i];
    }

    VfxControl::onDeinit();
}


void VcpSoftkey::onDraw(VfxDrawContext &dc)
{
    VFX_UNUSED(dc);
}


void VcpSoftkey::assertValidSoftkey(VcpSoftkeyEnum sk) const 
{
    VFX_ASSERT(sk >= 0 && sk < VCP_SOFTKEY_TOTAL);
}


void VcpSoftkey::onEvent_LSKButtonDown()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_LSK]->m_isDisabled);
    
    m_softkeyConfig[VCP_SOFTKEY_LSK]->m_callback.emit(VCP_SOFTKEY_DOWN);
}


void VcpSoftkey::onEvent_LSKButtonUp()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_LSK]->m_isDisabled);

    m_softkeyConfig[VCP_SOFTKEY_LSK]->m_callback.emit(VCP_SOFTKEY_UP);
}


void VcpSoftkey::onEvent_LSKButtonLongpress()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_LSK]->m_isDisabled);

    m_softkeyConfig[VCP_SOFTKEY_LSK]->m_callback.emit(VCP_SOFTKEY_LONGPRESS);
}


void VcpSoftkey::onEvent_RSKButtonDown()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_RSK]->m_isDisabled);

    m_softkeyConfig[VCP_SOFTKEY_RSK]->m_callback.emit(VCP_SOFTKEY_DOWN);
}


void VcpSoftkey::onEvent_RSKButtonUp()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_RSK]->m_isDisabled);

    m_softkeyConfig[VCP_SOFTKEY_RSK]->m_callback.emit(VCP_SOFTKEY_UP);
}


void VcpSoftkey::onEvent_RSKButtonLongpress()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_RSK]->m_isDisabled);
    
    m_softkeyConfig[VCP_SOFTKEY_RSK]->m_callback.emit(VCP_SOFTKEY_LONGPRESS);
}


void VcpSoftkey::onEvent_CSKButtonDown()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_CSK]->m_isDisabled);
    
    m_softkeyConfig[VCP_SOFTKEY_CSK]->m_callback.emit(VCP_SOFTKEY_DOWN);
}


void VcpSoftkey::onEvent_CSKButtonUp()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_CSK]->m_isDisabled);

    m_softkeyConfig[VCP_SOFTKEY_CSK]->m_callback.emit(VCP_SOFTKEY_UP);
}


void VcpSoftkey::onEvent_CSKButtonLongpress()
{
    // VFX_ASSERT(!m_softkeyConfig[VCP_SOFTKEY_CSK]->m_isDisabled);

    m_softkeyConfig[VCP_SOFTKEY_CSK]->m_callback.emit(VCP_SOFTKEY_LONGPRESS);
}


