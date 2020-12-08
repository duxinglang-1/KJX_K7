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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_desktop_popup_menu.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the base of the popup menu.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_desktop_popup_menu.h"
#include "mmi_rp_vapp_desktop_def.h"


/*****************************************************************************
 * Desktop List Menu
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDesktopPopupMenu", VappDesktopPopupMenu, VfxAppCatScr);


VappDesktopPopupMenu::VappDesktopPopupMenu() :
    m_callback(NULL),
    m_bgFrame(NULL),
    m_topBar(NULL),
    m_bottomBar(NULL)
{
    setIsSmallScreen();
}


void VappDesktopPopupMenu::onInit()
{
    VfxAppCatScr::onInit();

    //
    // Layout this popup menu.
    //
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    setSize(screenSize.width, screenSize.height);

    //
    // UI components
    //
    createBgFrame();

    createTopBar();

    createBottomBar();
}


VfxBool VappDesktopPopupMenu::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_RSK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        closeScreen();
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_END &&
             event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        closeScreen();
        return VFX_TRUE;
    }

    return VfxAppCatScr::onKeyInput(event);
}


VfxBool VappDesktopPopupMenu::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_UP:
            closeScreen();
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappDesktopPopupMenu::registerCallback(
    VappDesktopPopupMenu::CallbackFunc callback)
{
    m_callback = callback;
}


void VappDesktopPopupMenu::closeScreen()
{
    vfxPostInvoke0(this, &VappDesktopPopupMenu::onPostCloseScreen);
}


VfxRect VappDesktopPopupMenu::getContentBounds()
{
    VFX_ASSERT(m_topBar && m_bottomBar);

    VfxSize topBarSize = m_topBar->getSize();
    VfxSize bottomBarSize = m_bottomBar->getSize();

    VfxPoint origin(getPopupOrigin());
    VfxSize size(WIDTH, HEIGHT);

    origin.y += topBarSize.height;
    size.height -= topBarSize.height + bottomBarSize.height;

    return VfxRect(origin, size);
}


VfxBool VappDesktopPopupMenu::getTitleText(VfxWString &text)
{
    return VFX_FALSE;
}


void VappDesktopPopupMenu::createBgFrame()
{
    VFX_OBJ_CREATE(m_bgFrame, VfxFrame, this);
    m_bgFrame->setSize(getSize());
    m_bgFrame->setBgColor(VFX_COLOR_BLACK);
    m_bgFrame->setOpacity(0.3f);
}


void VappDesktopPopupMenu::createTopBar()
{
    //
    // Top bar background.
    //
    VFX_OBJ_CREATE(m_topBar, VfxImageFrame, this);
    m_topBar->setResId(IMG_ID_VAPP_DESKTOP_POPUP_TOP_BG);
    m_topBar->setPos(getPopupOrigin());
    m_topBar->setSize(WIDTH, m_topBar->getSize().height);
    m_topBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    //
    // Get and set the title text.
    //
    VfxWString titleText;
    VfxBool ret = getTitleText(titleText);

    if (ret)
    {
        VfxSize size = m_topBar->getSize();

        VfxTextFrame *title;

        VFX_OBJ_CREATE(title, VfxTextFrame, m_topBar);
        title->setHints(VFX_FRAME_HINTS_RARE_TRANSLUCENT);
        title->setFont(VFX_FONT_DESC_MEDIUM);
        title->setColor(VFX_COLOR_WHITE);
        title->setString(titleText);
        title->setAnchor(0.5f, 0.5f);
        title->setPos(size.width / 2, size.height / 2);
    }
}


void VappDesktopPopupMenu::createBottomBar()
{
    VfxPoint origin = getPopupOrigin();

    //
    // Bottom bar background.
    //
    VFX_OBJ_CREATE(m_bottomBar, VfxImageFrame, this);
    m_bottomBar->setResId(IMG_ID_VAPP_DESKTOP_POPUP_BOTTOM_BG);
    m_bottomBar->setPos(origin.x, origin.y + HEIGHT);
    m_bottomBar->setSize(WIDTH, m_bottomBar->getSize().height);
    m_bottomBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bottomBar->setAnchor(0.0f, 1.0f);
}


VfxPoint VappDesktopPopupMenu::getPopupOrigin() const
{
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    VfxPoint origin;

    origin.x = (screenSize.width - WIDTH) / 2;
    origin.y = (screenSize.height - HEIGHT) / 2;

    return origin;
}


void VappDesktopPopupMenu::onPostCloseScreen()
{
    mmi_frm_scrn_close_active_id();
}
#endif /* defined(__MMI_VUI_LAUNCHER__) */

