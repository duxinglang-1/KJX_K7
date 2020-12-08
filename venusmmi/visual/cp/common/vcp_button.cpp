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
 *  vcp_button.cpp
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
#include "vcp_button.h"
#include "vcp_state_image.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_font_desc.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_image_src.h"
#include "vfx_string.h"
#include "mmi_rp_srv_venus_component_button_def.h"
#include "vfx_adp_device.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#if defined (__MTK_TARGET__) && defined (__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 

static const VfxS32 VCP_BUTTON_TOUCH_MINIMAL_SIZE = VFX_TOUCH_FINGER_WIDTH * 2;
static const VfxS32 VCP_BUTTON_PEN_INNER_MARGIN = VFX_TOUCH_FINGER_WIDTH * 3 / 2;
static const VfxS32 VCP_BUTTON_PEN_OUTER_MARGIN = VFX_TOUCH_FINGER_WIDTH * 2;


static const VfxFloat VCP_BUTTON_DISABLE_OPACITY = 0.6f;

#if defined(__MMI_MAINLCD_480X800__)

#ifdef __COSMOS_MMI__
static const VfxS32 VCP_BUTTON_COSMOS_DEFAULT_HEIGHT = 77;
static const VfxS32 VCP_BUTTON_COSMOS_DEFAULT_FONT_SIZE = 30; // font size 30 = real size 33
#endif

static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT = 8; // 8 + 4(shadow) X
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT = 20; // (77 - 33) = 44 = 20 + 24
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT = 12;
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT = 24;

static const VfxS32 VCP_BUTTON_IMAGE_TEXT_GAP_DEFAULT = 12; // gap between image and text

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

#ifdef __COSMOS_MMI__
static const VfxS32 VCP_BUTTON_COSMOS_DEFAULT_HEIGHT = 42;
static const VfxS32 VCP_BUTTON_COSMOS_DEFAULT_FONT_SIZE = 16;
#endif

static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT = 6;
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT = 8;
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT = 8;
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT = 10;

static const VfxS32 VCP_BUTTON_IMAGE_TEXT_GAP_DEFAULT = 6; // gap between image and text

#else // default 320X480

#ifdef __COSMOS_MMI__
static const VfxS32 VCP_BUTTON_COSMOS_DEFAULT_HEIGHT = 47;
static const VfxS32 VCP_BUTTON_COSMOS_DEFAULT_FONT_SIZE = 18; // font size 18 = real size 20
#endif

static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT = 8;
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT = 12; // 47 - 20 = 27 ~= 12 + 14
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT = 10;
static const VfxS32 VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT = 14;

static const VfxS32 VCP_BUTTON_IMAGE_TEXT_GAP_DEFAULT = 6; // gap between image and text
#endif

#define PRESSED_DOWN_STATE_STAY_DURATION 100

/*****************************************************************************
 * Class VcpButton
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpButton", VcpButton, VfxControl);


VcpButton::VcpButton() :
    m_state(VCP_BUTTON_STATE_NORMAL),
    m_placement(VCP_BUTTON_PLACEMENT_TEXT_ONLY),
    m_frameText(NULL),
    m_font(VFX_FONT_DESC_MEDIUM),
    m_frameImage(NULL),
    m_sizeImage(0, 0),
    m_sizeText(0, 0),
    m_textFrameDirty(VFX_FALSE),
    m_textImageGap(VCP_BUTTON_IMAGE_TEXT_GAP_DEFAULT),
    m_isHapticTouchEnabled(VFX_FALSE),
    m_isHighlighted(VFX_FALSE),
    m_isAutoResized(VFX_FALSE),
    m_style(VCP_BUTTON_STYLE_DEFAULT_01),
    m_id(0),
    m_minWidth(0),
    m_maxWidth(0),
    m_timer(NULL)
{
    for (VfxS32 i = 0 ; i < END_OF_TYPE ; i ++)
    {
        m_colorTextBorder[i] = VCP_BTN_COLOR_TXT_DEFAULT_BRDR;
    }
}


void VcpButton::onInit()
{
    VfxControl::onInit();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BoI", SA_start); 
#endif
    setAutoAnimate(VFX_TRUE);

    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // set default size
    // set back ground and margin
#ifdef __COSMOS_MMI__
    setSize(VfxSize(VCP_BUTTON_COSMOS_DEFAULT_HEIGHT * 3, VCP_BUTTON_COSMOS_DEFAULT_HEIGHT) );
    setBgImageList(VcpStateImage(VCP_IMG_BUTTON_DEFAULT_01_N,
                                VCP_IMG_BUTTON_DEFAULT_01_P,
                                VCP_IMG_BUTTON_DEFAULT_01_D,
                                VCP_IMG_BUTTON_DEFAULT_01_N) );
    setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
            VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);
    setTextColor(VCP_BTN_COLOR_TXT_DEFAULT_NRML);
    setFuzzy(VFX_TRUE);
#else
    setSize(VfxSize(50, 32) );
    setBgImageList(VcpStateImage(VCP_IMG_BUTTON_N, VCP_IMG_BUTTON_P, VCP_IMG_BUTTON_D, VCP_IMG_BUTTON_H) );
    setMargin(6, 5, 7, 7);

    setTextColor(VCP_BTN_COLOR_TXT_DEFAULT_NRML,
                VCP_BTN_COLOR_TXT_DEFAULT_PRSD,
                VCP_BTN_COLOR_TXT_DEFAULT_DSBD,
                VCP_BTN_COLOR_TXT_DEFAULT_HLTD);

#endif

    // create icon frame
    VFX_OBJ_CREATE(m_frameImage, VfxFrame, this);
    m_frameImage->setHidden(VFX_TRUE);

    // create label frame
    VFX_OBJ_CREATE(m_frameText, VfxTextFrame, this);
    m_frameText->setHidden(VFX_TRUE);
    m_frameText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_frameText->setFullLineHeightMode(VFX_FALSE);

#ifdef __COSMOS_MMI__
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_BUTTON_COSMOS_DEFAULT_FONT_SIZE);
    fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_DEFAULT_01)).effect;              
    setTextFont(fontDesc);
#endif

    // register signal
    m_signalBoundsChanged.connect(this, &VcpButton::onBoundsChanged);

    checkUpdate();

#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("BoI", SA_stop); 
#endif	
}


void VcpButton::forceUpdate()
{
    if (m_checkUpdate)
    {
        processUpdate();

        m_checkUpdate = VFX_FALSE;
    }
}


void VcpButton::resetButtonState()
{
    m_state = VCP_BUTTON_STATE_NORMAL;

    if (getIsDisabled() )
    {
        setImgContent(m_bgImageList.getImageDisabled() );
    }
    else if (m_isHighlighted)
    {
        setImgContent(m_bgImageList.getImageHighlight() );
    }
    else
    {
        setImgContent(m_bgImageList.getImageNormal() );
    }

    checkUpdate();
}


VfxBool VcpButton::onPenInput(VfxPenEvent &event)
{
    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            if (!getIsDisabled() )
            {
                if(m_timer)
                {
                    m_timer->stop();
                    VFX_OBJ_CLOSE(m_timer);
                }
                setState(VCP_BUTTON_STATE_PRESSED);                
                if(getIsHapticTouchEnabled())
                {
                    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
                }                
                m_signalStateChanged.postEmit(this, m_id, m_state);

            }
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            {
                VfxRect bounds = getBounds();
                if (m_state == VCP_BUTTON_STATE_PRESSED)
                {   // reset button while move out of button
                    VfxRect outerBounds(bounds.getX() - VCP_BUTTON_PEN_OUTER_MARGIN, bounds.getY() - VCP_BUTTON_PEN_OUTER_MARGIN,
                        bounds.getWidth() + 2 * VCP_BUTTON_PEN_OUTER_MARGIN, bounds.getHeight() + 2 * VCP_BUTTON_PEN_OUTER_MARGIN);
                    VfxBool isInOuterBounds = outerBounds.contains(event.getRelPos(this) );
                    if (!isInOuterBounds)
                    {
                        resetButtonState();
                        m_signalStateChanged.postEmit(this, m_id, m_state);
                    }
                }
                else if (!getIsDisabled() )
                {
                    VfxRect innerBounds(bounds.getX() - VCP_BUTTON_PEN_INNER_MARGIN, bounds.getY() - VCP_BUTTON_PEN_INNER_MARGIN,
                        bounds.getWidth() + 2 * VCP_BUTTON_PEN_INNER_MARGIN, bounds.getHeight() + 2 * VCP_BUTTON_PEN_INNER_MARGIN);
                    VfxBool isInInnerBounds = innerBounds.contains(event.getRelPos(this) );
                    if (isInInnerBounds)
                    {
                        setState(VCP_BUTTON_STATE_PRESSED);
                        if(getIsHapticTouchEnabled())
                        {
                            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
                        }

                        m_signalStateChanged.postEmit(this, m_id, m_state);
                    }
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (m_state == VCP_BUTTON_STATE_PRESSED)
            {
                //VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                //renderer->blockAfterNextCommit(1, VfxCallback0(this, &VcpButton::onAfterClick));
                onAfterClick();
                m_signalStateChanged.postEmit(this, m_id, VCP_BUTTON_STATE_NORMAL);

                // start timer for reset button
                VFX_OBJ_CREATE(m_timer, VfxTimer, this);
                m_timer->m_signalTick.connect(this, &VcpButton::OnPressedStateTimerOut);
                m_timer->setStartDelay(PRESSED_DOWN_STATE_STAY_DURATION);

                m_timer->start();

                      
            }
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            if (m_state == VCP_BUTTON_STATE_PRESSED)
            {
                resetButtonState();
                m_signalStateChanged.postEmit(this, m_id, m_state);
            }
            break;

        default:
            break;
    }

    checkUpdate();

    // handle all events
    return VFX_TRUE;
}

void VcpButton::onAfterClick()
{
    m_signalClicked.postEmit(this, m_id);
}

VfxBool VcpButton::onContainPoint(const VfxPoint &point) const
{
    VfxRect bounds = getBounds();
    if (bounds.size.width < VCP_BUTTON_TOUCH_MINIMAL_SIZE)
    {
        bounds.origin.x -= (VCP_BUTTON_TOUCH_MINIMAL_SIZE - bounds.size.width) / 2;
        bounds.size.width = VCP_BUTTON_TOUCH_MINIMAL_SIZE;
    }
    if (bounds.size.height < VCP_BUTTON_TOUCH_MINIMAL_SIZE)
    {
        bounds.origin.y -= (VCP_BUTTON_TOUCH_MINIMAL_SIZE - bounds.size.height) / 2;
        bounds.size.height = VCP_BUTTON_TOUCH_MINIMAL_SIZE;
    }
    return bounds.contains(point);
}

void VcpButton::updateItem()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BuI", SA_start); 
#endif
    // decide whether icon / lable to display
    if (m_placement == VCP_BUTTON_PLACEMENT_TEXT_ONLY || m_placement == VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT)
    {
        m_frameImage->setHidden(VFX_TRUE);
        m_frameText->setHidden(VFX_FALSE);
    }
    else if (m_placement == VCP_BUTTON_PLACEMENT_IMAGE_ONLY)
    {
        m_frameImage->setHidden(VFX_FALSE);
        m_frameText->setHidden(VFX_TRUE);
    }
    else
    {
        m_frameImage->setHidden(VFX_FALSE);
        m_frameText->setHidden(VFX_FALSE);
    }

    VcpButton::ButtonType buttonType = VcpButton::TYPE_NORMAL;
    VfxImageSrc image;

    // determine button type
    if (getIsDisabled() )
    {
        buttonType = VcpButton::TYPE_DISABLED;
    }
    else
    {
        if (m_state == VCP_BUTTON_STATE_PRESSED)
        {
            buttonType = VcpButton::TYPE_PRESSED;
        }
        else
        {
            if (getIsHighlighted() )
            {
                buttonType = VcpButton::TYPE_HIGHLIGHT;
            }
            else
            {
                buttonType = VcpButton::TYPE_NORMAL;
            }
        }
    }

    switch (buttonType)
    {
    case VcpButton::TYPE_NORMAL:
        image = m_iconImageList.getImageNormal();
        setImgContent(m_bgImageList.getImageNormal() );    
        break;
    case VcpButton::TYPE_PRESSED:
        image = m_iconImageList.getImagePressed();
        setImgContent(m_bgImageList.getImagePressed() );    
        break;
    case VcpButton::TYPE_DISABLED:
        image = m_iconImageList.getImageDisabled();
        setImgContent(m_bgImageList.getImageDisabled() );    
        break;
    case VcpButton::TYPE_HIGHLIGHT:
        image = m_iconImageList.getImageHighlight();
        setImgContent(m_bgImageList.getImageHighlight() );    
        break;
    default:
        VFX_ASSERT(VFX_FALSE);
        break;
    };

    // set image
    if (!m_frameImage->getHidden() )
    {
        m_sizeImage = image.getSize();
        m_frameImage->setSize(m_sizeImage);
        m_frameImage->setImgContent(image);
    }

    // set text
    if (!m_frameText->getHidden() )
    {
        m_frameText->setColor(m_colorText[buttonType]);
        m_frameText->setBorderColor(m_colorTextBorder[buttonType]);
    }

    // update opacity
    if (buttonType == VcpButton::TYPE_DISABLED)
    {
        m_frameImage->setOpacity(VCP_BUTTON_DISABLE_OPACITY);
        m_frameText->setOpacity(VCP_BUTTON_DISABLE_OPACITY);
    }
    else
    {
        m_frameImage->setOpacity(1.0f);
        m_frameText->setOpacity(1.0f);
    }
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("BuI", SA_stop); 
#endif	
}


// Auto resize button
void VcpButton::setIsAutoResized(VfxBool isAutoResized, VfxS32 minWidth, VfxS32 maxWidth)
{
    m_isAutoResized = isAutoResized;
    m_minWidth = minWidth;
    m_maxWidth = maxWidth;

    checkUpdate();
}


VfxBool VcpButton::getIsAutoResized() const
{
    return m_isAutoResized;
}


void VcpButton::resizeButton()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BrB", SA_start); 
#endif
    if (m_isAutoResized)
    {
        VfxSize size;

        // get minimun button size
        switch(m_placement)
        {
            case VCP_BUTTON_PLACEMENT_TEXT_ONLY:
            case VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT:
                size = m_sizeText;
                break;

            case VCP_BUTTON_PLACEMENT_IMAGE_ONLY:
                size = m_sizeImage;
                break;

            case VCP_BUTTON_PLACEMENT_OVERLAP:
                size.width = VFX_MAX(m_sizeImage.width, m_sizeText.width);
                size.height = VFX_MAX(m_sizeImage.height, m_sizeText.height);
                break;

            case VCP_BUTTON_PLACEMENT_IMAGE_LEFT:
            case VCP_BUTTON_PLACEMENT_IMAGE_RIGHT:
            case VCP_BUTTON_PLACEMENT_TEXT_LEFT_IMAGE_RIGHT:
            case VCP_BUTTON_PLACEMENT_IMAGE_TEXT_CENTER:
                size.width = m_sizeImage.width + m_sizeText.width + getTextImageGap();
                size.height = VFX_MAX(m_sizeImage.height, m_sizeText.height);
                break;

            case VCP_BUTTON_PLACEMENT_IMAGE_TOP:
            case VCP_BUTTON_PLACEMENT_IMAGE_BOTTOM:
                size.width = VFX_MAX(m_sizeImage.width, m_sizeText.width);
                size.height = m_sizeImage.height + m_sizeText.height + getTextImageGap();
                break;

            default:
                break;
        }

        // set button size
        VfxRect clientRect = getClientArea();
        VfxSize totalSize = getSize();

        totalSize.width += size.width - clientRect.size.width;
        if (m_placement != VCP_BUTTON_PLACEMENT_IMAGE_ONLY)
        {
            totalSize.width = (m_minWidth && (totalSize.width < m_minWidth) ) ? (m_minWidth) : (totalSize.width);
            totalSize.width = (m_maxWidth && (totalSize.width > m_maxWidth) ) ? (m_maxWidth) : (totalSize.width);
        }
        if (m_placement == VCP_BUTTON_PLACEMENT_IMAGE_TOP || m_placement == VCP_BUTTON_PLACEMENT_IMAGE_BOTTOM ||
            m_placement == VCP_BUTTON_PLACEMENT_IMAGE_ONLY)
        {
            totalSize.height += size.height - clientRect.size.height;
        }
        setSize(totalSize);
    }
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("BrB", SA_stop); 
#endif	
}


void VcpButton::layoutButton()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BlB", SA_start); 
#endif
    VfxS32 shift = 0;

    // get size information
    VfxRect clientRect = getClientArea();

    VfxSize sizeText = m_sizeText;

    // layout button
    switch(m_placement)
    {
        case VCP_BUTTON_PLACEMENT_TEXT_ONLY:
        case VCP_BUTTON_PLACEMENT_IMAGE_ONLY:
        case VCP_BUTTON_PLACEMENT_OVERLAP:
            {
                // center align icon
                if (m_placement != VCP_BUTTON_PLACEMENT_TEXT_ONLY)
                {
                    // set position
                    m_frameImage->setAnchor(VfxFPoint(0.5, 0.5) );
                    m_frameImage->setPos(VfxPoint(clientRect.getMidX(), clientRect.getMidY() ) );
                }

                // center align label
                if (m_placement != VCP_BUTTON_PLACEMENT_IMAGE_ONLY)
                {
                    // set position
                    m_frameText->setAnchor(VfxFPoint(0.5, 0.5) );
                    m_frameText->setPos(VfxPoint(clientRect.getMidX(), clientRect.getMidY() ) );
                }
            }
            break;

        case VCP_BUTTON_PLACEMENT_IMAGE_LEFT:
            {
                // set icon position
                m_frameImage->setAnchor(VfxFPoint(0.0, 0.5) );
                m_frameImage->setPos(VfxPoint(clientRect.getMinX(), clientRect.getMidY() ) );

                shift = m_sizeImage.width + getTextImageGap();

                // set label position
                m_frameText->setAnchor(VfxFPoint(0.0, 0.5) );
                m_frameText->setPos(VfxPoint(clientRect.getMinX() + shift, clientRect.getMidY() ) );

                // set label size
                clientRect.size.width -= shift;
            }
            break;

        case VCP_BUTTON_PLACEMENT_IMAGE_RIGHT:
            {
                // set icon position
                m_frameImage->setAnchor(VfxFPoint(1.0, 0.5) );
                m_frameImage->setPos(VfxPoint(clientRect.getMaxX(), clientRect.getMidY() ) );

                shift = m_sizeImage.width + getTextImageGap();

                // set label position
                m_frameText->setAnchor(VfxFPoint(1.0, 0.5) );
                m_frameText->setPos(VfxPoint(clientRect.getMaxX() - shift, clientRect.getMidY() ) );

                // set label size
                clientRect.size.width -= shift;
            }
            break;

        case VCP_BUTTON_PLACEMENT_IMAGE_TOP:
            {
                // set label position, align to bottom of client rect
                m_frameText->setAnchor(VfxFPoint(0.5, 1.0) );
                m_frameText->setPos(VfxPoint(clientRect.getMidX(), clientRect.getMaxY() ) );

                // set icon position, align to top of client rect
                m_frameImage->setAnchor(VfxFPoint(0.5, 0.0) );
                m_frameImage->setPos(VfxPoint(clientRect.getMidX(), clientRect.getMinY() ) );
            }
            break;

        case VCP_BUTTON_PLACEMENT_IMAGE_BOTTOM:
            {
                // set label position, align to top of client rect
                m_frameText->setAnchor(VfxFPoint(0.5, 0.0) );
                m_frameText->setPos(VfxPoint(clientRect.getMidX(), clientRect.getMinY() ) );

                // set icon position, align to bottom of client rect
                m_frameImage->setAnchor(VfxFPoint(0.5, 1.0) );
                m_frameImage->setPos(VfxPoint(clientRect.getMidX(), clientRect.getMaxY() ) );
            }
            break;

        case VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT:
            {
                // set label position
                m_frameText->setAnchor(VfxFPoint(0.0, 0.5) );
                m_frameText->setPos(VfxPoint(clientRect.getMinX(), clientRect.getMidY() ) );
            }
            break;

        case VCP_BUTTON_PLACEMENT_TEXT_LEFT_IMAGE_RIGHT:
            {
                // set label size
                sizeText.width = VFX_MIN(sizeText.width, 
                        clientRect.size.width - m_frameImage->getSize().width - m_textImageGap);

                // set label position
                m_frameText->setAnchor(VfxFPoint(0.0, 0.5) );
                m_frameText->setPos(VfxPoint(clientRect.getMinX(), clientRect.getMidY() ) );

                // set icon position
                m_frameImage->setAnchor(VfxFPoint(1.0, 0.5) );
                m_frameImage->setPos(VfxPoint(clientRect.getMaxX(), clientRect.getMidY() ) );
            }
            break;
        case VCP_BUTTON_PLACEMENT_IMAGE_TEXT_CENTER:
            {
                VfxS32 margin = (clientRect.size.width - sizeText.width - 
                    m_frameImage->getSize().width - m_textImageGap) / 2;
                if (margin < 0)
                {
                    margin = 0;
                }
                // set icon position
                m_frameImage->setAnchor(VfxFPoint(0.0, 0.5) );
                m_frameImage->setPos(VfxPoint(clientRect.getMinX() + margin, clientRect.getMidY() ) );

                shift = m_sizeImage.width + getTextImageGap();

                // set label position
                m_frameText->setAnchor(VfxFPoint(0.0, 0.5) );
                m_frameText->setPos(VfxPoint(clientRect.getMinX() + margin + shift, clientRect.getMidY() ) );

                // set label size
                clientRect.size.width -= shift;
            }
            break;

        default:
            break;
    }

    // set label size
    if (m_placement != VCP_BUTTON_PLACEMENT_IMAGE_ONLY)
    {
        sizeText.width = VFX_MIN(sizeText.width, clientRect.size.width);
        sizeText.height = VFX_MIN(sizeText.height, clientRect.size.height);
        m_frameText->setSize(sizeText);
    }
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("BlB", SA_stop); 
#endif	
}


void VcpButton::onBoundsChanged(VfxFrame *frame, const VfxRect &old)
{
    checkUpdate();
}


void VcpButton::onUpdate()
{
    if (m_style == VCP_BUTTON_STYLE_NORMAL) // deprecated
    {
        if (getText() != VFX_WSTR("DEPRECATED") )
        {
            setText(VFX_WSTR("DEPRECATED") );
            setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            setIsAutoResized(VFX_TRUE);
            m_checkUpdate = VFX_FALSE;
        }
    }

    if (m_textFrameDirty)
    {
        m_frameText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
        m_sizeText = m_frameText->getMeasureBounds().size;
        m_frameText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }

    updateItem();
    resizeButton();
    layoutButton();
    m_textFrameDirty = VFX_FALSE;
}


void VcpButton::setImage(const VcpStateImage &imageList)
{
    m_iconImageList = imageList;
    resetButtonState();
    checkUpdate();
}


const VfxImageSrc &VcpButton::getImage() const
{
    return m_frameImage->getImgContent();
}


const VcpStateImage & VcpButton::getStateImage() const
{
    return m_iconImageList;
}

void VcpButton::setText (VfxResId resId)
{
    setText(VFX_WSTR_RES(resId));
}

void VcpButton::setText (const VfxWChar *mem)
{
    setText(VFX_WSTR_MEM(mem));
}

void VcpButton::setText (const VfxWString &str)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BsT", SA_start); 
#endif	
    m_frameText->setString(str);
    m_textFrameDirty = VFX_TRUE;
    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("BsT", SA_stop); 
#endif		
}


VfxWString VcpButton::getText() const
{
    return m_frameText->getString();
}

void VcpButton::setPlacement(VcpButtonPlacementEnum placement)
{
    m_placement = placement;
    if((m_placement== VCP_BUTTON_PLACEMENT_IMAGE_TOP) || (m_placement== VCP_BUTTON_PLACEMENT_IMAGE_BOTTOM))
    {
        m_frameText->setFullLineHeightMode(VFX_TRUE);
    }
    else
    {
        m_frameText->setFullLineHeightMode(VFX_FALSE);
    }
    m_textFrameDirty = VFX_TRUE;
    checkUpdate();
}


VcpButtonPlacementEnum VcpButton::getPlacement() const
{
    return m_placement;
}


void VcpButton::setId(VfxId id)
{
    m_id = id;
}


VfxId VcpButton::getId() const
{
    return m_id;
}


void VcpButton::setTextFont(const VfxFontDesc &font)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BsF", SA_start); 
#endif	
    m_font = font;
    m_frameText->setFont(m_font);
    m_textFrameDirty = VFX_TRUE;
    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BsF", SA_stop); 
#endif		
}


VfxFontDesc VcpButton::getTextFont()
{
    return m_frameText->getFont();
}

void VcpButton::setTextColor(const VfxColor &color)
{
    for (VfxS32 i = 0 ; i < END_OF_TYPE ; i ++)
    {
        m_colorText[i] = color;
    }

    checkUpdate();
}


void VcpButton::setTextColor(const VfxColor &colorNormal, const VfxColor &colorPressed, const VfxColor &colorDisabled, const VfxColor &colorHighlgiht)
{
    m_colorText[TYPE_NORMAL] = colorNormal;
    m_colorText[TYPE_PRESSED] = colorPressed;
    m_colorText[TYPE_DISABLED] = colorDisabled;
    m_colorText[TYPE_HIGHLIGHT] = colorHighlgiht;

    checkUpdate();
}


void VcpButton::setTextBorderColor(const VfxColor &color)
{
    for (VfxS32 i = 0 ; i < END_OF_TYPE ; i ++)
    {
        m_colorTextBorder[i] = color;
    }

    checkUpdate();
}


void VcpButton::setTextBorderColor(const VfxColor &colorNormal, const VfxColor &colorPressed, const VfxColor &colorDisabled, const VfxColor &colorHighlgiht)
{
    m_colorTextBorder[TYPE_NORMAL] = colorNormal;
    m_colorTextBorder[TYPE_PRESSED] = colorPressed;
    m_colorTextBorder[TYPE_DISABLED] = colorDisabled;
    m_colorTextBorder[TYPE_HIGHLIGHT] = colorHighlgiht;

    checkUpdate();
}


void VcpButton::setStyle(VcpButtonStyleEnum style)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("BsS", SA_start); 
#endif	
    m_style = style;
    if (style == VCP_BUTTON_STYLE_DEFAULT_01)
    {
        setBgImageList(VcpStateImage(VCP_IMG_BUTTON_DEFAULT_01_N,
                                    VCP_IMG_BUTTON_DEFAULT_01_P,
                                    VCP_IMG_BUTTON_DEFAULT_01_D,
                                    VCP_IMG_BUTTON_DEFAULT_01_N) );
        setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
                VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);

        VfxFontDesc fontDesc = m_frameText->getFont();
#if defined(__MMI_VUI_COSMOS_CP__)
        fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_DEFAULT_01)).effect;
#else
        fontDesc.effect= VFX_FE1_4;
#endif
        setTextFont(fontDesc);
        setTextColor(VCP_BTN_COLOR_TXT_STYLE_DEFAULT_01);
    }
    else if (style == VCP_BUTTON_STYLE_DEFAULT_02)
    {
        setBgImageList(VcpStateImage(VCP_IMG_BUTTON_DEFAULT_02_N,
                                    VCP_IMG_BUTTON_DEFAULT_02_P,
                                    VCP_IMG_BUTTON_DEFAULT_02_D,
                                    VCP_IMG_BUTTON_DEFAULT_02_N) );
        setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
                VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);

        VfxFontDesc fontDesc = m_frameText->getFont();
        
#if defined(__MMI_VUI_COSMOS_CP__)
        fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_DEFAULT_02)).effect;
#else
        fontDesc.effect= VFX_FE1_1;
#endif
        setTextFont(fontDesc);
        setTextColor(VCP_BTN_COLOR_TXT_STYLE_DEFAULT_02);
    }
    else if (style == VCP_BUTTON_STYLE_RED)
    {
        setBgImageList(VcpStateImage(VCP_IMG_BUTTON_RED_N,
                                    VCP_IMG_BUTTON_RED_P,
                                    VCP_IMG_BUTTON_RED_D,
                                    VCP_IMG_BUTTON_RED_N) );
        setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
                VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);

        VfxFontDesc fontDesc = m_frameText->getFont();
#if defined(__MMI_VUI_COSMOS_CP__)
        fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_RED)).effect;
#else
        fontDesc.effect= VFX_FE1_3;
#endif
        setTextFont(fontDesc);
        setTextColor(VCP_BTN_COLOR_TXT_STYLE_RED);
    }
    else if (style == VCP_BUTTON_STYLE_GREY)
    {
        setBgImageList(VcpStateImage(VCP_IMG_BUTTON_GREY_N,
                                    VCP_IMG_BUTTON_GREY_P,
                                    VCP_IMG_BUTTON_GREY_D,
                                    VCP_IMG_BUTTON_GREY_N) );
        setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
                VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);

        VfxFontDesc fontDesc = m_frameText->getFont();
#if defined(__MMI_VUI_COSMOS_CP__)
        fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_GREY)).effect;
#else
        fontDesc.effect= VFX_FE1_3;
#endif
        setTextFont(fontDesc);
        setTextColor(VCP_BTN_COLOR_TXT_STYLE_GREY);
    }
    else if (style == VCP_BUTTON_STYLE_SIM1)
    {
        setBgImageList(VcpStateImage(VCP_IMG_BUTTON_SIM1_N,
                                    VCP_IMG_BUTTON_SIM1_P,
                                    VCP_IMG_BUTTON_SIM1_D,
                                    VCP_IMG_BUTTON_SIM1_N) );
        setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
                VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);

        VfxFontDesc fontDesc = m_frameText->getFont();
#if defined(__MMI_VUI_COSMOS_CP__)
        fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_SIM1)).effect;
#else
        fontDesc.effect= VFX_FE1_1;
#endif
        setTextFont(fontDesc);
        setTextColor(VCP_BTN_COLOR_TXT_STYLE_SIM1);
    }
    else if (style == VCP_BUTTON_STYLE_SIM2)
    {
        setBgImageList(VcpStateImage(VCP_IMG_BUTTON_SIM2_N,
                                    VCP_IMG_BUTTON_SIM2_P,
                                    VCP_IMG_BUTTON_SIM2_D,
                                    VCP_IMG_BUTTON_SIM2_N) );
        setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
                VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);

        VfxFontDesc fontDesc = m_frameText->getFont();
#if defined(__MMI_VUI_COSMOS_CP__)
        fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_SIM2)).effect;
#else
        fontDesc.effect= VFX_FE1_1;
#endif
        setTextFont(fontDesc);
        setTextColor(VCP_BTN_COLOR_TXT_STYLE_SIM2);
    }
    else if (style == VCP_BUTTON_STYLE_NORMAL) // deprecated
    {
        setBgImageList(VcpStateImage(VCP_IMG_BUTTON_RED_N,
                                    VCP_IMG_BUTTON_RED_P,
                                    VCP_IMG_BUTTON_RED_D,
                                    VCP_IMG_BUTTON_RED_N) );
        setMargin(VCP_BUTTON_COSMOS_MARGIN_LEFT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_TOP_DEFAULT,
                VCP_BUTTON_COSMOS_MARGIN_RIGHT_DEFAULT, VCP_BUTTON_COSMOS_MARGIN_BOTTOM_DEFAULT);

        VfxFontDesc fontDesc = m_frameText->getFont();
#if defined(__MMI_VUI_COSMOS_CP__)
        fontDesc.effect= (VFX_FONT_RES(VCP_FONT_BTN_STYLE_NORMAL)).effect;
#else
        fontDesc.effect= VFX_FE1_3;
#endif
        setTextFont(fontDesc);
        setTextColor(VCP_BTN_COLOR_TXT_STYLE_NORMAL);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }

#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("BsS", SA_stop); 
#endif		
}


void VcpButton::setBgImageList(const VcpStateImage &imageList)
{
    m_bgImageList = imageList;

    resetButtonState();
}

void VcpButton::setMargin(VfxS32 left, VfxS32 top, VfxS32 right, VfxS32 bottom)
{
    m_boundary = VfxRect(left, top, right, bottom);

    checkUpdate();
}

void VcpButton::getMargin(VfxS32 &left, VfxS32 &top, VfxS32 &right, VfxS32 &bottom)
{
    left = m_boundary.origin.x;
    top = m_boundary.origin.y;
    right = m_boundary.size.width;
    bottom = m_boundary.size.height;
}

void VcpButton::setInnerRect(const VfxRect & rect)
{
    VfxRect rectWithShadow = rect;
    rectWithShadow.size.width += VCP_BUTTON_SHADOW_MARGIN_RIGHT;
    rectWithShadow.size.height += VCP_BUTTON_SHADOW_MARGIN_BOTTOM;
    setRect(rectWithShadow);
}

VfxRect VcpButton::getInnerRect()
{
    VfxRect rect = getRect();
    rect.size.width -= VCP_BUTTON_SHADOW_MARGIN_RIGHT;
    rect.size.height -= VCP_BUTTON_SHADOW_MARGIN_BOTTOM;
    return rect;
}

void VcpButton::setTextImageGap(VfxS32 gap)
{
    m_textImageGap = gap;
}
    
VfxS32 VcpButton::getTextImageGap()
{
    return m_textImageGap;
}

void VcpButton::setIsDisabled (VfxBool isDisabled)
{
    VfxControl::setIsDisabled(isDisabled);
    if(isDisabled == VFX_TRUE)
    {
        m_state = VCP_BUTTON_STATE_NORMAL;
    }
    checkUpdate();
}

VfxTextFrame * VcpButton::getButtonTextFrame() const
{
    return m_frameText;
}

VfxFrame * VcpButton::getButtonImageFrame() const
{
    return m_frameImage;
}

void VcpButton::setIsHighlighted (VfxBool isHighlighted)
{
    m_isHighlighted = isHighlighted;
    resetButtonState();
}

void VcpButton::setIsHapticTouchEnabled(VfxBool state)
{
       m_isHapticTouchEnabled = state;
}

VfxBool VcpButton::getIsHapticTouchEnabled()
{
    return m_isHapticTouchEnabled;
}

VfxBool VcpButton::getIsHighlighted() const
{
    return m_isHighlighted;
}

void VcpButton::setState(VcpButtonStateEnum newState)
{
    if(getIsDisabled())
    {
        return;
    }
    m_state = newState;
    switch(m_state)
    {
    case VCP_BUTTON_STATE_PRESSED:
        setImgContent(m_bgImageList.getImagePressed() );    
        break;
    case VCP_BUTTON_STATE_NORMAL:
        setImgContent(m_bgImageList.getImageNormal() );    
        break;
    default:
        break;
    }
    checkUpdate();
}

VcpButtonStateEnum VcpButton::getState() const
{
    return m_state;
}

VfxRect VcpButton::getClientArea() const
{
    VfxRect rect = getBounds();

    rect.origin.x += m_boundary.origin.x;
    rect.origin.y += m_boundary.origin.y;

    rect.size.width -= (m_boundary.origin.x + m_boundary.size.width);
    rect.size.height -= (m_boundary.origin.y + m_boundary.size.height);

    return rect;
}
 
void VcpButton::OnPressedStateTimerOut(VfxTimer *timer)
    {
        ASSERT(timer);
        timer->stop();
        VFX_OBJ_CLOSE(m_timer);
        resetButtonState();

    }


/*****************************************************************************
 * Class VcpScrollingTextButton
 *****************************************************************************/
VcpScrollingTextButton::VcpScrollingTextButton():
m_scrollingText(NULL),
m_scrollOnHighlight(VFX_TRUE)
{}

void VcpScrollingTextButton::onInit()
{
    VcpButton::onInit();

}

void VcpScrollingTextButton::setScrollOnHighlight(VfxBool state)
{
    m_scrollOnHighlight = state;
    if(!state)
    {
        m_frameText->setHidden(VFX_FALSE);
        if(m_scrollingText)
        {
                VFX_OBJ_CLOSE(m_scrollingText);
        }
    }

}

VfxBool VcpScrollingTextButton::getScrollOnHighlight()
{
    return m_scrollOnHighlight;
}

void VcpScrollingTextButton::updateItem()
{
    VcpButton::updateItem();
    if(m_textFrameDirty)
    {
        if(getScrollOnHighlight())
        {
            VfxS32 left, top, right, bottom;
            getMargin(left, top, right, bottom);
            if(((getSize().width) - left - right) < (m_sizeText.width)  )
            {
                if(!m_scrollingText)
                {
                    VFX_OBJ_CREATE(m_scrollingText, VcpMarquee, this);
                    m_scrollingText->setAutoResized(VFX_TRUE);
                }
                m_scrollingText->setMovableFrame(getText(), m_font);
            }
            else
            {
                if(m_scrollingText)
                {
                    VFX_OBJ_CLOSE(m_scrollingText);
                }
            }
        }
    }
    if(m_scrollingText)
    {
        m_scrollingText->setTextColor(m_colorText[0]); 

        // update opacity
        if (getIsDisabled())
        {            
            m_scrollingText->setOpacity(VCP_BUTTON_DISABLE_OPACITY);
        }
        else
        {         
            m_scrollingText->setOpacity(1.0f);
        }
    }
} 

void VcpScrollingTextButton::onUpdate()
{
    VcpButton::onUpdate();
    if(!m_scrollingText)
    {
        return;
    }
    
        m_scrollingText->setAnchor(m_frameText->getAnchor());
        m_scrollingText->setPos(m_frameText->getPos());
        m_scrollingText->setSize(m_frameText->getSize());
        if(getScrollOnHighlight())
        {
            if(getIsHighlighted())
            {
                m_scrollingText->setHidden(VFX_FALSE);
                m_frameText->setHidden(VFX_TRUE);
                m_scrollingText->startScroll();
            }
            else
            {
                m_scrollingText->setHidden(VFX_TRUE);
                m_frameText->setHidden(VFX_FALSE);
                m_scrollingText->stopScroll();
            }
    }
}

void VcpScrollingTextButton::setText(VfxResId resId)
{
    setText(VFX_WSTR_RES(resId));
}

void VcpScrollingTextButton::setText(const VfxWChar *mem)
{
    setText(VFX_WSTR_MEM(mem));
}

void VcpScrollingTextButton::setText(const VfxWString &str)
{
    VcpButton::setText(str);
}


void VcpScrollingTextButton::setPlacement(VcpButtonPlacementEnum placement)
{
    VcpButton::setPlacement(placement);

}

void VcpScrollingTextButton::setTextFont(const VfxFontDesc &font)
{    
    VcpButton::setTextFont(font);
    m_font = font;
}

void VcpScrollingTextButton::setTextColor(const VfxColor &color )
{
    VcpButton::setTextColor(color);
}

void VcpScrollingTextButton::setTextColor(
    const VfxColor &colorNormal,        
    const VfxColor &colorPressed,      
    const VfxColor &colorDisabled,    
    const VfxColor &colorHighlight
    )
{
    VcpButton::setTextColor(colorNormal, colorPressed, colorDisabled, colorHighlight);
}

