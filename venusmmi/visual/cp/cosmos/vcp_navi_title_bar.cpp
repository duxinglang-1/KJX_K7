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
 *  vcp_navi_title_bar.cpp
 *
 * Project:
 * --------
 *  FTO Components
 *
 * Description:
 * ------------
 *  Vinus Title Bar component
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vcp_navi_title_bar.h"
#include "MMIDataType.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vfx_primitive_frame.h"
#include "mmi_rp_srv_venus_component_title_bar_def.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"
#include "kal_general_types.h"
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"

#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__
#include "vcp_frame_effect.h"
#include "vfx_top_level.h"

#endif // __VCP_TITLE_BAR_USE_3D_EFFECT__

/*****************************************************************************
 * Global Variable
 *****************************************************************************/


static const S32 VCP_TITLE_BAR_TITLE_MARGIN_TOP = 3;
static const S32 VCP_TITLE_BAR_TITLE_MARGIN_BOTTOM = 3;


#if defined(__MMI_MAINLCD_480X800__)
static const S32 VCP_TITLE_BAR_HEIGHT = 45;
static const S32 VCP_TITLE_BAR_HEIGHT_LANDSCAPE = 45;
static const S32 VCP_TITLE_BAR_FONT_SIZE = 24;
static const S32 VCP_TITLE_BAR_SHADOW_HEIGHT = 4;
static const S32 VCP_TITLE_BAR_TITLE_MARGIN_HORIZONTAL = 14;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const S32 VCP_TITLE_BAR_HEIGHT = 18;
static const S32 VCP_TITLE_BAR_HEIGHT_LANDSCAPE = 18;
static const S32 VCP_TITLE_BAR_FONT_SIZE = 13;
static const S32 VCP_TITLE_BAR_SHADOW_HEIGHT = 2;
static const S32 VCP_TITLE_BAR_TITLE_MARGIN_HORIZONTAL = 6;

#else // default 320X480
static const S32 VCP_TITLE_BAR_HEIGHT = 23;
static const S32 VCP_TITLE_BAR_HEIGHT_LANDSCAPE = 23;
static const S32 VCP_TITLE_BAR_FONT_SIZE = 14;
static const S32 VCP_TITLE_BAR_SHADOW_HEIGHT = 2;
static const S32 VCP_TITLE_BAR_TITLE_MARGIN_HORIZONTAL = 8;

#endif
/*****************************************************************************
 * Class VcpTitleBar
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcpTitleBar", VcpTitleBar, VfxPageBar);

/*****************************************************************************
 * FUNCTION
 *  VcpTitleBar::VcpTitleBar
 * DESCRIPTION
 *  Constructor of VcpTitleBar class
 * PARAMETERS
 *
 * RETURNS
 *  *****************************************************************************/
VcpTitleBar::VcpTitleBar():m_background(NULL),
    m_titleControl(NULL), 
	m_title(VFX_WSTR_EMPTY),
    m_translucent(false),
    m_rotation(VFX_SCR_ROTATE_TYPE_NORMAL),
#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__
    m_effectDelayTimer(NULL),
#endif
    m_titleStyle(VCP_TITLE_BAR_STYLE_BASE)
{
    // XXX : initial value for testing
    //setTitle(VFX_WSTR_EMPTY);
}

void VcpTitleBar::onInit()
{
    VfxPageBar::onInit();

    // set default size
    setSize(getSize().width, VCP_TITLE_BAR_HEIGHT);

    setAutoAnimate(VFX_TRUE);

    VfxFrame * shadowFrame;
    VFX_OBJ_CREATE(shadowFrame, VfxFrame, this);
    shadowFrame->setImgContent(VfxImageSrc(VCP_IMG_TITLEBAR_SHADOW) );
    shadowFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    shadowFrame->setSize(getSize().width, VCP_TITLE_BAR_SHADOW_HEIGHT);
    setShadowFrame(shadowFrame);

#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__
    VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);

    VFX_OBJ_CREATE(m_effectDelayTimer, VfxTimer, this);
    m_effectDelayTimer->m_signalTick.connect(this, &VcpTitleBar::onDelayedEffect);
    m_effectDelayTimer->setStartDelay(500);

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->m_signalActiveScreenEnter.connect(this, &VcpTitleBar::onActiveScreenEnter);
    topLevel->m_signalActiveScreenExit.connect(this,  &VcpTitleBar::onActiveScreenExit);

#endif // __VCP_TITLE_BAR_USE_3D_EFFECT__
    m_signalBoundsChanged.connect(this, &VcpTitleBar::onBoundsChanged);
    checkUpdate();
}

#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__
void VcpTitleBar::onDeinit()
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->m_signalActiveScreenEnter.disconnect(this, &VcpTitleBar::onActiveScreenEnter);
    topLevel->m_signalActiveScreenExit.disconnect(this,  &VcpTitleBar::onActiveScreenExit);

    VfxPageBar::onDeinit();
}

#endif // __VCP_TITLE_BAR_USE_3D_EFFECT__

void VcpTitleBar::onUpdate()
{
    VfxPageBar::onUpdate();

    // check state

    // update title bar size
    if (m_titleStyle == VCP_TITLE_BAR_STYLE_BASE)
    {
        if (m_rotation == VFX_SCR_ROTATE_TYPE_90 || m_rotation == VFX_SCR_ROTATE_TYPE_270)
        {
            setSize(getSize().width, VCP_TITLE_BAR_HEIGHT_LANDSCAPE);
        }
        else
        {
            setSize(getSize().width, VCP_TITLE_BAR_HEIGHT);
        }
    }

    // update content
    updateBackground();

    updateTitle();
}

void VcpTitleBar::updateBackground()
{
    if (m_background == NULL)
    {
        VFX_OBJ_CREATE(m_background, VfxImageFrame, this);
        m_background->sendToBack();
    }

    // change the background according to style
    if (m_backgroundImage.getType() == VFX_IMAGE_SRC_TYPE_NULL)
    {
        if (m_translucent)
        {
            m_background->setImgContent(VfxImageSrc(VCP_IMG_TITLEBAR_BACKGROUND_TRANSLUCENT));
        }
        else
        {
            m_background->setImgContent(VfxImageSrc(VCP_IMG_TITLEBAR_BACKGROUND_NORMAL));
        }
    }
    else
    {
            m_background->setImgContent(m_backgroundImage);
    }

    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setBounds(getBounds());
    m_background->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_background->setAutoAnimate(VFX_TRUE);
}

void VcpTitleBar::updateTitle()
{
    switch (getTitleStyle())
    {
        case VCP_TITLE_BAR_STYLE_BASE:
            updateTitleStyleBase();
            break;
        case VCP_TITLE_BAR_STYLE_EMPTY:
            VFX_OBJ_CLOSE(m_titleControl);
            break;
        default:
            VFX_ASSERT(0);
            VFX_OBJ_CLOSE(m_titleControl);
            break;
    }
}

void VcpTitleBar::updateTitleStyleBase()
{
    // create title frame
    if (m_titleControl == NULL)
    {
        VFX_OBJ_CREATE(m_titleControl, VfxTextFrame, this);
    }
    insertChildFrameAfter(m_background, m_titleControl);
    // close the subtitle frame because it's not used in base style

    const S32 left = VCP_TITLE_BAR_TITLE_MARGIN_HORIZONTAL;
    const S32 top = VCP_TITLE_BAR_TITLE_MARGIN_TOP;
    const S32 right = getSize().width - VCP_TITLE_BAR_TITLE_MARGIN_HORIZONTAL;
    const S32 bottom = getSize().height - VCP_TITLE_BAR_TITLE_MARGIN_BOTTOM;

    m_titleControl->setString(getTitle());
    m_titleControl->setFullLineHeightMode(VFX_FALSE);
    updateTextFrame(m_titleControl, left, top, right, bottom);

    m_titleControl->setAutoAnimate(VFX_TRUE);
}

void VcpTitleBar::updateTextFrame(VfxTextFrame * textFrame, S32 left, S32 top, S32 right, S32 bottom)
{
    // set text frame properties
    const S32 maxWidth = right - left;
    const S32 centerY = (top + bottom + 1) / 2;
    const S32 maxHeight = bottom - top;

    // always use truncate mode to draw text
    // truncated or not truncated text rendering code path is quite different
    textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_TITLE_BAR_FONT_SIZE);
    fontDesc.effect = VFX_FE1_9;
    textFrame->setFont(fontDesc);

    textFrame->setAnchor(VfxFPoint(0.5f, 0.5f));
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);    
    textFrame->setSize(maxWidth, maxHeight);
    textFrame->setPos(getSize().width / 2, centerY);
    textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    VfxAutoAnimate::commit();            
    
    textFrame->setMargins(left, 0, getSize().width - right, 0);
    textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

}

void VcpTitleBar::onBoundsChanged(VfxFrame *frame, const VfxRect &old)
{
    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
}

VfxWString VcpTitleBar::getTitle() const
{
    return m_title;
}

void VcpTitleBar::setTitle(const VfxWString& title)
{
    if (m_title == title)
    {
        return;
    }

    m_title = title;
    checkUpdate();
}

VcpTitleBarStyleEnum VcpTitleBar::getTitleStyle() const
{
    return m_titleStyle;
}

void VcpTitleBar::setTitleStyle(VcpTitleBarStyleEnum style)
{
    if (m_titleStyle == style)
    {
        return;
    }

    m_titleStyle = style;
    checkUpdate();
}

void VcpTitleBar::setTitleBackground(const VfxImageSrc & background)
{
    m_backgroundImage = background;
}

void VcpTitleBar::onSetTranslucent(VfxBool translucent)
{
    if (m_translucent == translucent)
    {
        return;
    }

    m_translucent = translucent;
    checkUpdate();
}


void VcpTitleBar::onSetRotate(VfxScrRotateTypeEnum rotation)
{
    if(m_rotation == rotation)
    {
        return;
    }

    m_rotation = rotation;
    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }

}
void VcpTitleBar::setTitle(const VfxWChar* title)
{
    setTitle(VFX_WSTR_MEM(title));
}

void VcpTitleBar::setTitle(VfxResId titleId)
{
    setTitle(VFX_WSTR_RES(titleId));
}

#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__

void VcpTitleBar::onTransitionStop(VfxBool in, VfxS32 direction)
{
    setMaterial(NULL);
    m_effectDelayTimer->stop();
    m_frameEffect->restore();

    if (in)
    {
        m_effectDelayTimer->start();
    }
}

void VcpTitleBar::onDelayedEffect(VfxTimer *source)
{
    VfxFrame * frame = NULL;
    for (   frame = this;
            frame != NULL;
            frame = frame->getParentFrame() )
    {
        if (frame->getHidden() )
        {
            return;
        }
    }

    m_frameEffect->applyEffect(this, VCP_EFFECT_TITLE_BAR_LIGHT, 5000, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_FALSE);
}

void VcpTitleBar::onActiveScreenEnter(VfxWeakPtr<VfxScreen> scr)
{
    setMaterial(NULL);
    m_effectDelayTimer->stop();

    VfxFrame * frame = NULL;
    for (   frame = this;
            frame != NULL && (NULL == VFX_OBJ_DYNAMIC_CAST(frame, VfxScreen));
            frame = frame->getParentFrame() )
    {
        if (frame->getHidden() )
        {
            return;
        }
    }
    if (scr.isValid() && scr.get() == frame)
    {
        m_effectDelayTimer->start();
    }
}

void VcpTitleBar::onActiveScreenExit(VfxWeakPtr<VfxScreen> scr)
{
    setMaterial(NULL);
    m_effectDelayTimer->stop();
    m_frameEffect->restore();
}

#endif // __VCP_TITLE_BAR_USE_3D_EFFECT__

#ifdef __AFX_RT_TEST__
VfxBool VcpTitleBar::testGetTranslucent()
{
    return m_translucent;
}

void VcpTitleBar::testSetTranslucent(VfxBool translucent)
{
    onSetTranslucent(translucent);
}

VfxScrRotateTypeEnum VcpTitleBar::testGetRotation()
{
    return m_rotation;
}

void VcpTitleBar::testSetRotation(VfxScrRotateTypeEnum rotation)
{
    onSetRotate(rotation);
}

void VcpTitleBar::testForceUpdate()
{
    onUpdate();
    m_checkUpdate = VFX_FALSE;
}

VfxImageFrame * VcpTitleBar::testGetBackground()
{
    return m_background;
}

VfxTextFrame * VcpTitleBar::testGetTitleControl()
{
    return m_titleControl;
}

#endif // __AFX_RT_TEST__

