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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Vapp_sat_base.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements  SAT Base Class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "MMIDataType.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_string.h"

#include "vcp_navi_title_bar.h"

#include "vapp_sat_title_bar.h"
#include "mmi_rp_vapp_sat_def.h"
#include "vadp_app_trc.h"
#include "vadp_app_trc_gen.h"
#include "mmi_rp_srv_venus_component_title_bar_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SAT_EDITOR_SHOW_HINT_INTERVAL_NUM  10
#define VAPP_SAT_PAGE_CP_MARGIN                 10


/*****************************************************************************
 * Global Variable
 *****************************************************************************/
//static const S32 VAPP_SAT_TITLE_BAR_MARGIN_TOP      = 3;
//static const S32 VAPP_SAT_TITLE_BAR_MARGIN_BOTTOM   = 3;


#if defined(__MMI_MAINLCD_480X800__)
static const S32 VAPP_SAT_TITLE_BAR_HEIGHT              = 40;
//static const S32 VAPP_SAT_TITLE_BAR_HEIGHT_LANDSCAPE    = 40;
static const S32 VAPP_SAT_TITLE_BAR_FONT_SIZE           = 26;
static const S32 VAPP_SAT_TITLE_BAR_SHADOW_HEIGHT       = 4;
//static const S32 VAPP_SAT_TITLE_BAR_MARGIN_HORIZONTAL  = 18;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const S32 VAPP_SAT_TITLE_BAR_HEIGHT              = 18;
//static const S32 VAPP_SAT_TITLE_BAR_HEIGHT_LANDSCAPE    = 18;
static const S32 VAPP_SAT_TITLE_BAR_FONT_SIZE           = 13;
static const S32 VAPP_SAT_TITLE_BAR_SHADOW_HEIGHT       = 2;
//static const S32 VAPP_SAT_TITLE_BAR_MARGIN_HORIZONTAL   = 6;

#else // default 320X480
static const S32 VAPP_SAT_TITLE_BAR_HEIGHT              = 23;
//static const S32 VAPP_SAT_TITLE_BAR_HEIGHT_LANDSCAPE    = 23;
static const S32 VAPP_SAT_TITLE_BAR_FONT_SIZE           = 15;
static const S32 VAPP_SAT_TITLE_BAR_SHADOW_HEIGHT       = 2;
//static const S32 VAPP_SAT_TITLE_BAR_MARGIN_HORIZONTAL   = 8;

#endif


/*****************************************************************************
 * Class VappSatBaseTitleBar
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappSatBaseTitleBar", VappSatBaseTitleBar, VfxPageBar);

VappSatBaseTitleBar::VappSatBaseTitleBar() :
    m_background(NULL),
    m_imageFrame(NULL),
    m_marquee(NULL)
    
{
}


void VappSatBaseTitleBar::onInit()
{
    VfxPageBar::onInit();

    // set default size
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    setSize(VfxSize(main_screen_size.width, VAPP_SAT_TITLE_BAR_HEIGHT));
    setAutoAnimate(VFX_TRUE);

    m_textWidth = main_screen_size.width - VAPP_SAT_PAGE_CP_MARGIN * 2;
    m_dispWidth = m_textWidth;
    m_xPos = main_screen_size.width / 2;
    m_yPos = VAPP_SAT_TITLE_BAR_HEIGHT / 2;

    setShodow();

    VFX_OBJ_CREATE(m_background, VfxImageFrame, this);  // background image
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);  // Title icon
#endif  //__SAT_DISABLE_ICON_SUPPORT__
    VFX_OBJ_CREATE(m_marquee, VcpMarquee, this);        // Title text

    m_signalBoundsChanged.connect(this, &VappSatBaseTitleBar::onBoundsChanged);
    checkUpdate();
}


void VappSatBaseTitleBar::onUpdate()
{
    VfxPageBar::onUpdate();

    updateBackground();
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    updateImageFrame();
#endif
    setMarquee();
}


void VappSatBaseTitleBar::setMarquee()
{
    m_marquee->setMovableFrame(getString(), VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SAT_TITLE_BAR_FONT_SIZE)));
    VfxFontDesc f;
    f.size = VFX_FONT_DESC_VF_SIZE(VAPP_SAT_TITLE_BAR_FONT_SIZE);
    VfxSize s = f.measureStr(getString());

    if (s.width <= m_textWidth)
    {
        m_textWidth = s.width;
    }

    m_marquee->setAnchor(0.5f, 0.5f);
    m_marquee->setPos(m_xPos, m_yPos);
    m_marquee->setBounds(0, 0, m_textWidth, VAPP_SAT_TITLE_BAR_HEIGHT);
    m_marquee->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);

    m_marquee->startScroll();
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (m_dispWidth != m_textWidth)
    {
        VfxS32 ext_w = VAPP_SAT_PAGE_CP_MARGIN + m_imageFrame->getSize().width;
        if (m_imageFrame->getSize().width == 0)
        {
            ext_w = 0;
        }

        VfxS32 w = (m_dispWidth - ext_w - m_textWidth) / 2;
        if (w < 0)
        {
            w = 0;
        }

        m_imageFrame->setPos(VAPP_SAT_PAGE_CP_MARGIN + w, m_yPos);
        m_marquee->setAnchor(0.0f, 0.5f);
        m_marquee->setPos(VAPP_SAT_PAGE_CP_MARGIN + ext_w + w, m_yPos);
    }
#endif //__SAT_DISABLE_ICON_SUPPORT__
}


void VappSatBaseTitleBar::setShodow()
{
    VfxFrame *shadowFrame;
    VFX_OBJ_CREATE(shadowFrame, VfxFrame, this);
    shadowFrame->setImgContent(VfxImageSrc(VCP_IMG_TITLEBAR_SHADOW));
    shadowFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    shadowFrame->setSize(getSize().width, VAPP_SAT_TITLE_BAR_SHADOW_HEIGHT);
    setShadowFrame(shadowFrame);
}


void VappSatBaseTitleBar::updateBackground()
{
    // change the background according to style
    m_background->sendToBack();
    m_background->setImgContent(VfxImageSrc(VCP_IMG_TITLEBAR_BACKGROUND_NORMAL));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setBounds(getBounds());

    m_background->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);

    m_background->setAutoAnimate(VFX_TRUE);
}

#ifndef __SAT_DISABLE_ICON_SUPPORT__
void VappSatBaseTitleBar::updateImageFrame()
{
    m_textWidth = m_dispWidth;
    if (getIcon().isNull())
    {
        m_imageFrame->setHidden(VFX_TRUE);
        return;
    }

    m_imageFrame->setAnchor(0.0f, 0.5f);
    m_imageFrame->setPos(m_xPos - VAPP_SAT_PAGE_CP_MARGIN, m_yPos);
    m_imageFrame->setImgContent(getIcon());
    m_imageFrame->setHidden(VFX_FALSE);

    m_textWidth -= (VAPP_SAT_PAGE_CP_MARGIN + m_imageFrame->getSize().width);
}
#endif //__SAT_DISABLE_ICON_SUPPORT__

void VappSatBaseTitleBar::onBoundsChanged(VfxFrame *frame, const VfxRect &old)
{
    checkUpdate();
}


void VappSatBaseTitleBar::setIconAndString(const VfxImageSrc &imgScr, const VfxWString &string)
{
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    m_icon   = imgScr;
#endif
    m_string = string;
    checkUpdate();
}

#ifndef __SAT_DISABLE_ICON_SUPPORT__
VfxImageSrc VappSatBaseTitleBar::getIcon() const
{
    return m_icon;
}
#endif //__SAT_DISABLE_ICON_SUPPORT__

VfxWString VappSatBaseTitleBar::getString() const
{
    return m_string;
}

