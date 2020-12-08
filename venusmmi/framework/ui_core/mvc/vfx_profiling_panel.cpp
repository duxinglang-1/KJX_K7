/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vfx_profiling_panel.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  The frm profiling panel of Venus UI engine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_profiling_panel.h"
#include "vfx_timer.h"
#include "MMI_features.h"

extern "C"
{
#include "ProfilingEngine.h"
#include "gui_themes.h"
}

/***************************************************************************** 
 * Class VfxProfilingPanel
 *****************************************************************************/

VfxProfilingPanel::VfxProfilingPanel()
: m_placement(DISPLAY_PLACE_BOTTOM)
, m_autohideTimeout(3000)
, m_autohideTimer(NULL)
{
}

VfxProfilingPanel::~VfxProfilingPanel()
{
    unregisterProfilingCallback();
}

void VfxProfilingPanel::registerProfilingCallback()
{
#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_interactive_register_show_callback(profilingCallback, this);
    //s_curProfilingPanel = this;
#endif
}

void VfxProfilingPanel::unregisterProfilingCallback()
{
#ifdef __MMI_INTERACTIVE_PROFILNG__
    //if (s_curProfilingPanel == this)
    {
        mmi_frm_profiling_interactive_register_show_callback(NULL, NULL);
    }
#endif
}

void VfxProfilingPanel::setDisplayPlace(DisplayPlace placement)
{
    if (m_placement == placement)
    {
        return;
    }

    m_placement = placement;

    switch (placement)
    {
    case DISPLAY_PLACE_TOP:
        setAnchor(0.5f, 0.0f);
        setPos(LCD_WIDTH / 2, 0);
        break;

    case DISPLAY_PLACE_BOTTOM:
        setAnchor(0.5f, 1.0f);
        setPos(LCD_WIDTH / 2, LCD_HEIGHT);
        break;
    }

    invalidate();
}

void VfxProfilingPanel::setAutoHideTimeout(VfxMsec timeout)
{
    m_autohideTimeout = timeout;
}

void VfxProfilingPanel::resetAutoHide()
{
    if (m_autohideTimer)
    {
        m_autohideTimer->stop();
    }
    else
    {
        VFX_OBJ_CREATE(m_autohideTimer, VfxTimer, this);
    }

    setHidden(VFX_FALSE);

    m_autohideTimer->setStartDelay(m_autohideTimeout);
    m_autohideTimer->m_signalTick.connect(this, &VfxProfilingPanel::onAutoHide);
    m_autohideTimer->start();
}

void VfxProfilingPanel::onInit()
{
    VfxTextFrame::onInit();

    // Set properties
    //setAutoResized(VFX_TRUE);
    VfxFontDesc fontDesc = VfxFontDesc(*((vrt_font_struct *)&MMI_small_font));
    VfxSize strSize = fontDesc.measureStr((VfxWChar *)L"0000000");
    setAnchor(0.5f, 1.0f);
    setPos(LCD_WIDTH / 2, LCD_HEIGHT);
    setSize(strSize.width, strSize.height * 2);
    setFont(fontDesc);
    setColor(VFX_COLOR_WHITE);
    setAlignMode(ALIGN_MODE_CENTER);
    setLineMode(LINE_MODE_MULTI);
    setLineGap(0);
    setVerticalToCenter(VFX_TRUE);
    setIsOpaque(VFX_TRUE);
    setCacheMode(VFX_CACHE_MODE_PREVENT);
    setBgColor(VFX_COLOR_BLACK);
    setOpacity(0.6f);
    setHidden(VFX_TRUE);
}

void VfxProfilingPanel::onAutoHide(VfxTimer *timer)
{
    timer->stop();
    setHidden(VFX_TRUE);
}

void VfxProfilingPanel::profilingCallback(U8 *str, void *user_data)
{
    VfxProfilingPanel *panel = (VfxProfilingPanel *)user_data;
    panel->setString(VFX_WSTR_DYNAMIC((VfxWChar *)str));
    panel->resetAutoHide();
}


