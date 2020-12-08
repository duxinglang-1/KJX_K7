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
 *  vcp_photo_border_frame.cpp
 *
 * Project:
 * --------
 *  FTO Components
 *
 * Description:
 * ------------
 *  Vinus Photo Border Frame Component
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
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __COSMOS_MMI__

#include "vcp_photo_border_frame.h"
#include "vfx_image_src.h"
#include "mmi_rp_srv_venus_component_photo_border_frame_def.h"
#include "vfx_timer.h"

#define VCP_PHOTO_BRDR_ANIM_TIMEOUT 1000

#ifdef __MTK_TARGET__
	//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VCP_BORDER_PEN_INNER_MARGIN = 60;
static const VfxS32 VCP_BORDER_PEN_OUTER_MARGIN = 80;
#else
static const VfxS32 VCP_BORDER_PEN_INNER_MARGIN = 30;
static const VfxS32 VCP_BORDER_PEN_OUTER_MARGIN = 40;
#endif

static const VfxS32 VCP_PHOTO_BORDER_FRAME_MIN_SIZE = 14;

static const VfxS32 VCP_PHOTO_BORDER_FRAME_MARGIN = 4;

static const VfxS32 VCP_PHOTO_BORDER_FRAME_DEFAULT_WIDTH = 50;
static const VfxS32 VCP_PHOTO_BORDER_FRAME_DEFAULT_HEIGHT = 50;

/*****************************************************************************
 * Class VcpPhotoBorderFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcpPhotoBorderFrame", VcpPhotoBorderFrame, VfxControl);

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 ********************************************************************************/
VcpPhotoBorderFrame::VcpPhotoBorderFrame():
    m_content(NULL),
    m_bg(NULL),
    m_fg(NULL),
    m_placement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_IMAGE_SIZE),
    m_imgContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL),
    m_maxWidth(VCP_PHOTO_BORDER_FRAME_DEFAULT_WIDTH),
    m_maxHeight(VCP_PHOTO_BORDER_FRAME_DEFAULT_HEIGHT),
    m_state(VCP_BORDER_STATE_NORMAL),
    m_penUpTimer(NULL)
{
}


void VcpPhotoBorderFrame::setImgContent(const VfxImageSrc &value)
{
    m_content->setImgContent(value);
    if (value.getType() == VFX_IMAGE_SRC_TYPE_PATH)
    {
        m_content->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
    }
    else
    {
        m_content->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_AUTO);
    }
    checkUpdate();
}


void VcpPhotoBorderFrame::setImgResId(VfxResId resId)
{
    setImgContent(VfxImageSrc(resId) );
}


void VcpPhotoBorderFrame::setImgPath(const VfxWString & path)
{
    setImgContent(VfxImageSrc(path) );
}
void VcpPhotoBorderFrame::setImgPath(const VfxWChar  *path)
{
    setImgContent(VfxImageSrc(VFX_WSTR_MEM(path)) );
}

void VcpPhotoBorderFrame::setPlacement(VcpPhotoBorderFramePlacementEnum placement)
{
    m_placement = placement;
}

void VcpPhotoBorderFrame::setImageContentPlacement(VfxFrameContentPlacementTypeEnum contentPlacement)
{
    m_imgContentPlacement = contentPlacement;
}

void VcpPhotoBorderFrame::setMaxSize(const VfxSize & maxSize)
{
    m_maxWidth = VFX_MAX(maxSize.width, VCP_PHOTO_BORDER_FRAME_MIN_SIZE);
    m_maxHeight = VFX_MAX(maxSize.height, VCP_PHOTO_BORDER_FRAME_MIN_SIZE);
    checkUpdate();
}


void VcpPhotoBorderFrame::forceUpdate()
{
    if (m_checkUpdate)
    {
        processUpdate();

        m_checkUpdate = VFX_FALSE;
    }
}


void VcpPhotoBorderFrame::invalidateImageFrame()
{
    getImageFrame()->invalidate();
}


void VcpPhotoBorderFrame::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("PbI", SA_start); 
#endif
    VfxControl::onInit();

    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_bg, VfxFrame, this);
    m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bg->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_BG));
    m_bg->setSize(VCP_PHOTO_BORDER_FRAME_MIN_SIZE, VCP_PHOTO_BORDER_FRAME_MIN_SIZE);
    m_bg->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_content, VfxFrame, this);
    m_content->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_content->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_fg, VfxFrame, this);
    m_fg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_fg->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG));
    m_fg->setSize(VCP_PHOTO_BORDER_FRAME_MIN_SIZE, VCP_PHOTO_BORDER_FRAME_MIN_SIZE);
    m_fg->setAutoAnimate(VFX_TRUE);


    VFX_OBJ_CREATE(m_penUpTimer, VfxTimer, this);               
    m_penUpTimer->m_signalTick.connect(this, &VcpPhotoBorderFrame::onPenRelease);


    checkUpdate();
	
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("PbI", SA_stop); 
#endif
}


void VcpPhotoBorderFrame::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("PbU", SA_start); 
#endif
    VfxControl::onUpdate();

    VfxS32 innerWidth = 0;
    VfxS32 innerHeight = 0;
    const VfxImageSrc imgSrc = m_content->getImgContent();

    if (m_placement == VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_IMAGE_SIZE)
    {
        m_content->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
        if (imgSrc.isNull() )
        {
            innerWidth = m_maxWidth - VCP_PHOTO_BORDER_FRAME_MARGIN * 2;
            innerHeight = m_maxHeight - VCP_PHOTO_BORDER_FRAME_MARGIN * 2;
        }
        else
        {
            VfxSize imageSize = imgSrc.getSize();
            innerWidth = imageSize.width;
            innerHeight = imageSize.height;
        }
    }
    else if (m_placement == VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_MAX_SIZE)
    {
        m_content->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
        const VfxS32 innerMaxWidth = m_maxWidth - VCP_PHOTO_BORDER_FRAME_MARGIN * 2;
        const VfxS32 innerMaxHeight = m_maxHeight - VCP_PHOTO_BORDER_FRAME_MARGIN * 2;

        VfxSize imageSize = imgSrc.getSize();
        if (imgSrc.isNull() || imageSize.width == 0 || imageSize.height == 0)
        {
            innerWidth = innerMaxWidth;
            innerHeight = innerMaxHeight;
        }
        else
        {
            //if (imageSize.width / imageSize.height > innerMaxWidth / innerMaxHeight) // equivalent to the next line
            if (imageSize.width * innerMaxHeight > innerMaxWidth * imageSize.height)
            {
                // the image ratio is larger width
                innerWidth = innerMaxWidth;
                innerHeight = innerMaxWidth * imageSize.height / imageSize.width;
            }
            else
            {
                innerHeight = innerMaxHeight;
                innerWidth = innerMaxHeight * imageSize.width / imageSize.height;
            }
        }
    }
    else if (m_placement == VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE)
    {
        m_content->setContentPlacement(m_imgContentPlacement);
        innerWidth = m_maxWidth - VCP_PHOTO_BORDER_FRAME_MARGIN * 2;
        innerHeight = m_maxHeight - VCP_PHOTO_BORDER_FRAME_MARGIN * 2;
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }

    VFX_ASSERT(m_bg);
    VFX_ASSERT(m_fg);
    
    m_content->setRect(VCP_PHOTO_BORDER_FRAME_MARGIN, VCP_PHOTO_BORDER_FRAME_MARGIN, innerWidth, innerHeight);
    m_bg->setRect(VCP_PHOTO_BORDER_FRAME_MARGIN, VCP_PHOTO_BORDER_FRAME_MARGIN, innerWidth, innerHeight);

    const VfxS32 borderWidth = innerWidth + VCP_PHOTO_BORDER_FRAME_MARGIN * 2;
    const VfxS32 borderHeight = innerHeight + VCP_PHOTO_BORDER_FRAME_MARGIN * 2;

    setSize(borderWidth, borderHeight);

    m_fg->setSize(borderWidth, borderHeight);
#if defined(__MAUI_SOFTWARE_LA__)
		SLA_CustomLogging("PbU", SA_stop); 
#endif
}

VfxBool VcpPhotoBorderFrame::onPenInput(VfxPenEvent &event)
{
    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            if (!getIsDisabled() )
            {
                m_state = VCP_BORDER_STATE_PRESSED;
                m_fg->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG_P));
            }
            break;
		case VFX_PEN_EVENT_TYPE_LONG_TAP:
            if (!getIsDisabled() )
            {
            	m_signalLongPress.postEmit();
            }
			break;
        case VFX_PEN_EVENT_TYPE_MOVE:
            {
                VfxRect bounds = getBounds();
                if (m_state == VCP_BORDER_STATE_PRESSED)
                {   // reset button while move out of button
                    VfxRect outerBounds(bounds.getX() - VCP_BORDER_PEN_OUTER_MARGIN, bounds.getY() - VCP_BORDER_PEN_OUTER_MARGIN,
                        bounds.getWidth() + 2 * VCP_BORDER_PEN_OUTER_MARGIN, bounds.getHeight() + 2 * VCP_BORDER_PEN_OUTER_MARGIN);
                    VfxBool isInOuterBounds = outerBounds.contains(event.getRelPos(this) );
                    if (!isInOuterBounds)
                    {
                        m_state = VCP_BORDER_STATE_NORMAL;
                        m_fg->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG));
                    }
                }
                else if (!getIsDisabled() )
                {
                    VfxRect innerBounds(bounds.getX() - VCP_BORDER_PEN_INNER_MARGIN, bounds.getY() - VCP_BORDER_PEN_INNER_MARGIN,
                        bounds.getWidth() + 2 * VCP_BORDER_PEN_INNER_MARGIN, bounds.getHeight() + 2 * VCP_BORDER_PEN_INNER_MARGIN);
                    VfxBool isInInnerBounds = innerBounds.contains(event.getRelPos(this) );
                    if (isInInnerBounds)
                    {
                        m_state = VCP_BORDER_STATE_PRESSED;
                        m_fg->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG_P));
                    }
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (m_state == VCP_BORDER_STATE_PRESSED)
            {
                m_state = VCP_BORDER_STATE_NORMAL;
                m_signalClicked.postEmit();
                m_penUpTimer->setStartDelay(VCP_PHOTO_BRDR_ANIM_TIMEOUT);
                m_penUpTimer->start();
            }
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            if (m_state == VCP_BORDER_STATE_PRESSED)
            {
                m_state = VCP_BORDER_STATE_NORMAL;
                m_fg->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG));
            }
            break;

        default:
            break;
    }

    checkUpdate();

    // handle all events
    return VFX_TRUE;
}

void VcpPhotoBorderFrame::onPenRelease(VfxTimer *timer)
{
    timer->stop();
    m_fg->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG));
}

VfxFrame * VcpPhotoBorderFrame::getImageFrame() const
{
    return m_content;
}

void VcpPhotoBorderFrame::setImageFrame(VfxFrame * content)
{
    VFX_OBJ_CLOSE(m_content);

    m_content = content;
    insertChildFrameAfter(m_bg, m_content);
    checkUpdate();
}

#endif // __COSMOS_MMI__

