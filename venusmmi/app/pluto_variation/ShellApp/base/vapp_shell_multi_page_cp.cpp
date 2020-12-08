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
 *  vapp_shell_multi_page_cp.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  shell base component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_object_list.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_state_image.h"
#include "vcp_button.h"
#include "vfx_font_desc.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vrt_system.h"
#include "vfx_primitive_frame.h"
#include "vfx_system.h"
#include "vfx_auto_animate.h"
#include "vfx_animation.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_transform.h"
#include "vfx_text_frame.h"
#include "vcp_wheel_menu.h"
#include "vfx_timer.h"
#include "vfx_input_event.h"
#include "vrt_canvas.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_frame_effect.h"
#include "vcp_content_clone.h"

#include "vadp_app_trc.h"

#include "vapp_shell_panel_cfg.h"
#include "vapp_shell_multi_page_cp.h"
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
#include "mmi_rp_app_shellapp_base_def.h"
#endif
#include "vapp_shell_page_order.h"

#include "vapp_shell_panel.h"
#include "vapp_shell_panel_cfg.h "
#include "vadp_v2p_hs.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "math.h"
#include "kal_trace.h"
#include "gui_typedef.h"
#include "gui_touch_feedback.h"

#ifdef __cplusplus
}
#endif

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
VfxFloat VappShellWheelMenu::s_camera_disc = VAPP_SHELL_FRONTVIEW_CAMERA_DISTANCE;
VfxFloat VappShellWheelMenu::s_semininor = VAPP_SHELL_FRONTVIEW_SEMIMINOR;
VfxFloat VappShellWheelMenu::s_seminajor = VAPP_SHELL_FRONTVIEW_SEMIMAJOR;
VfxFloat VappShellWheelMenu::s_shift_x = VAPP_SHELL_FRONTVIEW_SHIFT_X;
VfxFloat VappShellWheelMenu::s_angle = VAPP_SHELL_FRONTVIEW_ANGLE;
VfxFloat VappShellWheelMenu::s_focused_angle = VAPP_SHELL_FRONTVIEW_FOCUSED_ANGLE;
VfxFloat VappShellWheelMenu::s_overview_near_plane = VAPP_SHELL_FRONTVIEW_CAMERA_NEARPLANE;

VfxFloat VappShellWheelMenu::s_aaa = VAPP_SHELL_FRONTVIEW_SEC_ANGLE;
#endif /*__MMI_VUI_SHELL_MULTI_PAGE__*/


#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
/*****************************************************************************
 * shell tamplate
 *****************************************************************************/
template <class type>
VfxFrame* chkCellInList(VfxS32 cell, VfxObjList &obj_list)
{
    // to let the class type cast to interface, use tamplate here
    type *item = NULL;
    VfxObjListEntry *cell_list = NULL;
    for (cell_list = obj_list.getHead();
         cell_list != NULL;
         cell_list = cell_list->getNext())
    {
        item = static_cast<type *>(cell_list->get());

        // Because it will remove from null parent list when a frame is closed
        VFX_DEV_ASSERT(item != NULL);

        if (item->getCellId() == cell)
        {
            // already in the list so we don't need to create a new one
            return static_cast<VfxFrame *>(item);
        }
        item = NULL;
    }

    return NULL;

}


/*****************************************************************************
 * VappShellShortCutPanel
 *****************************************************************************/

VappShellShortCutPanel::VappShellShortCutPanel(VfxU8 ind_num) :
    m_ScBgImg(NULL),
    m_is_hide(VFX_FALSE),
    m_ind_bg_panel(NULL),
    m_ind(NULL)
{
    for (VfxU8 i = 0; i < VAPP_SHELL_PANEL_TOTAL; i++)
        m_ind_bg[i] = NULL;

    m_ind_num = ind_num;
}


void VappShellShortCutPanel::onInit()
{
    VfxFrame::onInit();

    VfxSize scr_size = getScreenSize();
    setRect(0, 0, scr_size.width, PAGE_SHORTCUT_HEIGHT+PAGE_IND_HEIGHT);

    // create indicator bar if necessary
    createIndBar(m_ind_num);

    // create shortcut
    createShortCut();
}


void VappShellShortCutPanel::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappShellShortCutPanel::onEnterSwitch(VfxObject*, VfxId)
{
    m_signalEnterSwitch.emit();
}


void VappShellShortCutPanel::onEnterMenu(VfxObject*, VfxId)
{
    m_signalEnterMenu.emit();
}


void VappShellShortCutPanel::onEnterDial(VfxObject*, VfxId)
{
    m_signalEnterDial.emit();
}


void VappShellShortCutPanel::onEnterLock(VfxObject*, VfxId)
{
    m_signalEnterLock.emit();
}


void VappShellShortCutPanel::createShortCut()
{
    VfxSize scr_size = getScreenSize();
    VFX_OBJ_CREATE(m_ScBgImg, VfxFrame, this);
    m_ScBgImg->setRect(0, PAGE_IND_HEIGHT, scr_size.width, PAGE_SHORTCUT_HEIGHT);
    m_ScBgImg->setBgColor(VFX_COLOR_BLACK);
    m_ScBgImg->setAutoAnimate(VFX_TRUE);

    /* set state image list */
    VcpStateImage   imgList[MAX_SHORTCUT_NUM];
    imgList[0].setImage(VAPP_SHELL_IMG_SC_SWITCH, VAPP_SHELL_IMG_SC_SWITCH_PRESS, 0, 0);
    imgList[1].setImage(VAPP_SHELL_IMG_SC_MENU, VAPP_SHELL_IMG_SC_MENU_PRESS, 0, 0);
    imgList[2].setImage(VAPP_SHELL_IMG_SC_DIAL, VAPP_SHELL_IMG_SC_DIAL_PRESS, 0, 0);
    imgList[3].setImage(VAPP_SHELL_IMG_SC_LOCK, VAPP_SHELL_IMG_SC_LOCK_PRESS, 0, 0);

    VcpStateImage bgImg;
    bgImg.setImage(VAPP_SHELL_IMG_SC_BG_NOR, VAPP_SHELL_IMG_SC_BG_PRESS, 0, 0);

    VcpButton  *scButton[MAX_SHORTCUT_NUM];
    VfxU8 i;

    VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(SHORTCUT_FONT_SIZE));

    for (i = 0; i < MAX_SHORTCUT_NUM; i++)
    {
        VFX_OBJ_CREATE(scButton[i], VcpButton, m_ScBgImg);

        scButton[i]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
        scButton[i]->setImage(imgList[i]);
        scButton[i]->setBgImageList(bgImg);
        scButton[i]->setRect(VfxRect(
                                0 + ((scr_size.width/MAX_SHORTCUT_NUM)*i),
                                0,
                                scr_size.width/MAX_SHORTCUT_NUM,
                                PAGE_SHORTCUT_HEIGHT));
        scButton[i]->setTextFont(font);
        scButton[i]->setMargin(0, TOP_MARGIN, 0, BOTTOM_MARGIN);
    }

    scButton[0]->setText(VFX_WSTR_RES(VAPP_SHELL_SWITCH_TEXT));
    scButton[1]->setText(VFX_WSTR_RES(VAPP_SHELL_MENU_TEXT));
    scButton[2]->setText(VFX_WSTR_RES(VAPP_SHELL_DIAL_TEXT));
    scButton[3]->setText(VFX_WSTR_RES(VAPP_SHELL_LOCK_TEXT));

    scButton[0]->m_signalClicked.connect(this, &VappShellShortCutPanel::onEnterSwitch);
    scButton[1]->m_signalClicked.connect(this, &VappShellShortCutPanel::onEnterMenu);
    scButton[2]->m_signalClicked.connect(this, &VappShellShortCutPanel::onEnterDial);
    scButton[3]->m_signalClicked.connect(this, &VappShellShortCutPanel::onEnterLock);
}


void VappShellShortCutPanel::closeShortCut()
{
    VFX_OBJ_CLOSE(m_ScBgImg);
}


VfxSize VappShellShortCutPanel::getScreenSize() const
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;

    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    return VfxSize(main_screen_size.width, main_screen_size.height);
}


void VappShellShortCutPanel::adjustIndWidth(VfxU8 ind_idx, VfxS32 *ind_width)
{
    if (ind_width == NULL)
        return;

    // compute indicator width
    *ind_width = getScreenSize().width/m_ind_num;

    if (ind_idx == 0 ||
        ind_idx == (m_ind_num - 1))
    {
        VfxS8  ind_mod_width = getScreenSize().width % m_ind_num;
        if (ind_mod_width != 0)
        {
            if ((ind_mod_width % 2) == 0)
            {
                ind_mod_width /= 2;
                *ind_width += ind_mod_width;
            }
            else
            {
                VfxS8 div_val = ind_mod_width/2;
                if (div_val > 0)
                {
                    *ind_width += div_val;
                }

                if (ind_idx == (m_ind_num - 1))
                {
                    *ind_width += 1;
                }
            }
        }
    }

}


void VappShellShortCutPanel::displayInd(VfxU8 ind_idx)
{
    VfxS32 ind_width = 0;
    VfxS32 ind_pos_x = 0;

    adjustIndWidth(ind_idx, &ind_width);

    // create indicator
    VFX_DEV_ASSERT(m_ind_bg_panel != NULL);

    if (m_ind == NULL)
    {
        VFX_OBJ_CREATE(m_ind, VfxImageFrame, m_ind_bg_panel);
        m_ind->setResId(VAPP_SHELL_IMG_IND);
        m_ind->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        if (ind_idx == (m_ind_num - 1))
            m_ind->setBounds(0, 0, ind_width, PAGE_IND_HEIGHT);
        else
            m_ind->setBounds(0, 0, ind_width-1, PAGE_IND_HEIGHT);
        m_ind->setAutoAnimate(VFX_TRUE);
    }
    else
    {
        m_ind->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        if (ind_idx == (m_ind_num - 1))
            m_ind->setBounds(0, 0, ind_width, PAGE_IND_HEIGHT);
        else
            m_ind->setBounds(0, 0, ind_width-1, PAGE_IND_HEIGHT);
    }

    VfxRect ind_rect;
    if (ind_idx > 0)
    {
        ind_rect = m_ind_bg[ind_idx-1]->getRect();
        ind_pos_x = ind_rect.origin.x + ind_rect.size.width;
    }
    else
    {
        ind_pos_x = 0;
    }

    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_DISPLAY_IND, ind_idx, ind_pos_x);

    m_ind->setPos(ind_pos_x, 0);
    m_ind_bg_panel->bringToFront();
    m_ind->bringToFront();
}


void VappShellShortCutPanel::createIndBar(VfxU8 ind_num)
{
    VfxU8 i;
    VfxSize scr_size = getScreenSize();
    VfxS32 ind_width = 0;

    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_CREATE_IND_BAR, ind_num);

    // update new indicator numbers
    m_ind_num = ind_num;

    // create indicator bar if necessary
    if (m_ind_bg_panel)
    {
        VFX_OBJ_CLOSE(m_ind);
        VFX_OBJ_CLOSE(m_ind_bg_panel);
    }

    VFX_DEV_ASSERT(ind_num <= VAPP_SHELL_PANEL_TOTAL);

    VFX_OBJ_CREATE(m_ind_bg_panel, VfxFrame, this);
    m_ind_bg_panel->setAutoAnimate(VFX_TRUE);

    if (m_is_hide)
    {
        m_ind_bg_panel->setRect(0, PAGE_SHORTCUT_HEIGHT + PAGE_IND_HEIGHT,
                                                scr_size.width, PAGE_IND_HEIGHT);
    }
    else
    {
        m_ind_bg_panel->setRect(0, 0, scr_size.width, PAGE_IND_HEIGHT);
    }

    VfxPoint pos;
    VfxRect ind_rect;
    for (i = 0; i < ind_num; i++)
    {
        adjustIndWidth(i, &ind_width);

        VFX_OBJ_CREATE(m_ind_bg[i], VfxImageFrame, m_ind_bg_panel);
        m_ind_bg[i]->setResId(VAPP_SHELL_IMG_IND_BAR);
        m_ind_bg[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_ind_bg[i]->setBounds(0, 0, ind_width, PAGE_IND_HEIGHT);

        if (i > 0)
        {
            ind_rect = m_ind_bg[i-1]->getRect();
            pos = ind_rect.origin;
            pos.x += ind_rect.size.width;
        }
        else
        {
            pos = VfxPoint(0, 0);
        }
        m_ind_bg[i]->setPos(pos);
    }

    m_ind_bg_panel->bringToFront();
}


void VappShellShortCutPanel::hide(VfxBool isHidden)
{
    if (m_is_hide == isHidden)
        return;

    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_HIDE_SHORTCUT, 1, isHidden);

    if (isHidden)
    {
        VfxPoint ind_pos = m_ind_bg_panel->getPos();
        VfxPoint sc_pos = m_ScBgImg->getPos();
        ind_pos.y += (PAGE_SHORTCUT_HEIGHT + PAGE_IND_HEIGHT);
        sc_pos.y += PAGE_SHORTCUT_HEIGHT;

        // hide shortcut bar
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_ind_bg_panel->setPos(ind_pos);

        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_ScBgImg->setPos(sc_pos);

        VfxAutoAnimate::commit();
        setIsUnhittable(VFX_TRUE);
    }
    else
    {
        VfxPoint ind_pos = m_ind_bg_panel->getPos();
        VfxPoint sc_pos = m_ScBgImg->getPos();
        ind_pos.y -= (PAGE_SHORTCUT_HEIGHT + PAGE_IND_HEIGHT);
        sc_pos.y -= PAGE_SHORTCUT_HEIGHT;

        VfxAutoAnimate::begin();

        // unhide shortcut bar background
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_ind_bg_panel->setPos(ind_pos);

        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_ScBgImg->setPos(sc_pos);

        VfxAutoAnimate::commit();
        setIsUnhittable(VFX_FALSE);
    }

    m_is_hide = isHidden;
}


VfxBool VappShellShortCutPanel::isHide()
{
    return m_is_hide;
}


VfxSize VappShellShortCutPanel::getBarSize()
{
    VfxSize size;
    return size = getBounds().size;
}

#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */


/*****************************************************************************
 * Class VappShellWheelCell
 *****************************************************************************/

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__

VFX_IMPLEMENT_CLASS("VappShellWheelCell", VappShellWheelCell, VfxControl);

VappShellWheelCell::VappShellWheelCell(VappShellPanel *cell, VfxS8 cell_num) :
    m_img_frame(NULL),
    m_panel_border(NULL)

{
    m_cell_num = cell_num;
    m_cell = cell;
    setCacheMode(VFX_CACHE_MODE_FORCE);
}


VfxS8 VappShellWheelCell::getCellId()
{
    return m_cell_num;
}


void VappShellWheelCell::updateCell()
{
    VFX_DEV_ASSERT(m_cell != NULL);

    VFX_OBJ_CLOSE(m_img_frame);

    if (m_cell->getPanelState() >= VappShellPanel::APP_SHELL_INIT_VIEW)
    {
        m_cell->onUpdateView();
    }

    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_UPDATE_CONTENT);

    if (isCellInCurrentTree() == VFX_FALSE)
    {
        m_cell->setHidden(VFX_FALSE);
        VfxTransform affine;
        affine.data.affine.sx = 1.0f / VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR;
        affine.data.affine.sy = 1.0f / VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR;

        VfxRect cell_rect = m_cell->getAppBounds();
        m_cell->setBounds(VfxRect(0, cell_rect.origin.y,
                                  cell_rect.getWidth(),
                                  cell_rect.getHeight()));
        m_cell->setTransform(affine);
        m_cell->setPos(VAPP_SHELL_BORDER_WIDTH/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR,
            VAPP_SHELL_BORDER_WIDTH/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR);
        addChildFrame(m_cell);
    }
}


void VappShellWheelCell::onInit()
{
    VfxControl::onInit();

    VFX_DEV_ASSERT(m_cell != NULL);

    VfxU8 panel_state = m_cell->getPanelState();

    if (panel_state == VappShellPanel::APP_SHELL_ENTER_VIEW)
    {
        m_cell->onExitView(VappShellPanel::APP_SHELL_PANEL_SWITCH_EXIT);
    }

    if (panel_state == VappShellPanel::APP_SHELL_INIT)
    {
        // init cell's view when the cell is created
        m_cell->onInitView();
    }
    m_cell->setHidden(VFX_TRUE);
    m_cell->setFocused(VFX_FALSE);
    m_cell->setIsUnhittable(VFX_TRUE);

    sendToBack();
    setOpacity(1.0f);
    setAnchor(VfxFPoint(0.5, 0.5));
    setIsCached(VFX_TRUE);
    setIsOpaque(VFX_TRUE);

    VfxRect cell_rect = m_cell->getAppBounds();
    VFX_OBJ_CREATE(m_panel_border, VfxImageFrame, this);
    m_panel_border->setResId(VAPP_SHELL_IMG_PANEL_BK_BORDER);
    m_panel_border->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_panel_border->setRect(0, 0,
        (cell_rect.getWidth() + VAPP_SHELL_BORDER_WIDTH*2)/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR,
        (cell_rect.getHeight() + VAPP_SHELL_BORDER_WIDTH*2)/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR);

    VFX_OBJ_CREATE(m_img_frame, VfxImageFrame, this);
    VfxTransform affine;
    affine.data.affine.sx = 1.0f / VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR;
    affine.data.affine.sy = 1.0f / VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR;

#if !defined(__MMI_VUI_SHELL_BASE_SLIM__)
    m_img_frame->setResId(VAPP_SHELL_IMG_SWITCH_BG);
#else
    if (m_cell->getPanelId() == VAPP_SHELL_PANEL_HOME)
        m_img_frame->setResId(VAPP_SHELL_IMG_SWITCH_HOME);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_SHORTCUTS)
        m_img_frame->setResId(VAPP_SHELL_IMG_SWITCH_SC);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_IMAGE_VIEWER)
        m_img_frame->setResId(VAPP_SHELL_IMG_SWITCH_IMV);
    else
        m_img_frame->setResId(VAPP_SHELL_IMG_SWITCH_MUSIC);
#endif

    m_img_frame->setBounds(0, 0,
         cell_rect.getWidth(), cell_rect.getHeight());
    m_img_frame->setTransform(affine);
    m_img_frame->setPos(VAPP_SHELL_BORDER_WIDTH/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR,
                        VAPP_SHELL_BORDER_WIDTH/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR);

#if !defined(__MMI_VUI_SHELL_BASE_SLIM__)    // set panel icon
    VfxImageFrame *img_icon;
    VFX_OBJ_CREATE(img_icon, VfxImageFrame, m_img_frame);

    if (m_cell->getPanelId() == VAPP_SHELL_PANEL_HOME)
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_HOME);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_SHORTCUTS)
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_SC);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_IMAGE_VIEWER)
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_IMV);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_FAV_CONTACT)
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_FAV);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_MEDIA_PLAYER)
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_MUSIC);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_MSG_VIEWER)
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_MSG);
    else if (m_cell->getPanelId() == VAPP_SHELL_PANEL_RECENT_CALLS)
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_CALL);
    else
        img_icon->setResId(VAPP_SHELL_IMG_SWITCH_SETTING);

    img_icon->setAnchor(0.5, 0.5);
    img_icon->setPos(cell_rect.getWidth()/2, cell_rect.getHeight()/2);
    img_icon->setTransform(affine);
#endif /* !defined(__MMI_VUI_SHELL_BASE_SLIM__) */
    setRect(VfxRect(0, 0,
        (cell_rect.getWidth() + VAPP_SHELL_BORDER_WIDTH*2)/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR,
        (cell_rect.getHeight() + VAPP_SHELL_BORDER_WIDTH*2)/VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR));
    setAutoAnimate(VFX_TRUE);
}


VfxBool VappShellWheelCell::isCellInCurrentTree()
{
	VfxFrame *i = m_cell->getParentFrame();
    while (i != NULL)
    {
        if (i == this)
        {
            return VFX_TRUE;
        }
        i = i->getParentFrame();
    }

    return VFX_FALSE;
}


void VappShellWheelCell::onDeinit()
{
    // deinit cell's view when the cell is closed
    VFX_DEV_ASSERT(m_cell != NULL);
     if(isCellInCurrentTree())
    {
        if (m_cell->getPanelState() == VappShellPanel::APP_SHELL_INIT_VIEW &&
            m_cell->isPanelAlwaysExist() == VFX_FALSE)
        {
            m_cell->onDeinitView();
        }
        m_cell->removeFromParentFrame();
    }
    VfxControl::onDeinit();
}


/*****************************************************************************
 * Class VappShellWheelTextCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappShellWheelTextCell", VappShellWheelTextCell, VfxTextFrame);

VappShellWheelTextCell::VappShellWheelTextCell(VfxResId cell_str, VfxS8 cell_num)
{
    m_cell_num = cell_num;
    m_cell_str = cell_str;
    setCacheMode(VFX_CACHE_MODE_FORCE);
}


VfxS8 VappShellWheelTextCell::getCellId()
{
    return m_cell_num;
}


void VappShellWheelTextCell::onInit()
{
    VfxTextFrame::onInit();

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    VfxFontDesc font(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SHELL_APP_FONT_SIZE),
                         VFX_FONT_DESC_ATTR_BOLD,
                         VFX_FONT_DESC_EFFECT_NONE));
    VfxSize strSize = font.measureStr(VFX_WSTR_RES(m_cell_str));

    setFullLineHeightMode(VFX_FALSE);
    setAutoResized(VFX_FALSE);
    setBgColor(VFX_COLOR_TRANSPARENT);
    setFont(font);
    setBounds(0, 0, main_screen_size.width, strSize.height);
    setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    setString(VFX_WSTR_RES(m_cell_str));
    setIsCached(VFX_TRUE);
}


void VappShellWheelTextCell::onDeinit()
{
    VfxTextFrame::onDeinit();
}


/*****************************************************************************
 * Class VappShellWheelReflectCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappShellWheelReflectCell", VappShellWheelReflectCell, VcpContentClone);

 VappShellWheelReflectCell::VappShellWheelReflectCell(
        VappShellWheelCell *target_item,
        VfxS8 cell_num)
{
    m_cell_num = cell_num;
    m_target_item = target_item;
}


VfxS8 VappShellWheelReflectCell::getCellId()
{
    return m_cell_num;
}


void VappShellWheelReflectCell::onInit()
{
    VcpContentClone::onInit();

    /* to let wheel menu and colone use different FPE.
       we need to create another parent frame */
    setPos(0, 0);
    setBounds(VfxRect(0,0,
    m_target_item->getBounds().getWidth(),
    m_target_item->getBounds().getHeight()/5));

    /* create reflection */
    setTargetFrame(m_target_item);
    setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
    setOutputAlpha(VFX_TRUE);
    setTargetRect(
            VfxRect(0,
            (m_target_item->getBounds().getHeight() -
             m_target_item->getBounds().getHeight()/5),
             m_target_item->getBounds().getWidth(),
            (m_target_item->getBounds().getHeight()/5)));
}

void VappShellWheelReflectCell::onDeinit()
{
    VcpContentClone::onDeinit();
}


/*****************************************************************************
 * Class VappShellWheelMenu
 *****************************************************************************/

VappShellWheelMenu::VappShellWheelMenu(
                                       VfxU8 cur_scr_idx,
                                       VfxU8 max_panel_num,
                                       VappShellPanel **shell_panel_list) :
                   m_update_num(SHELL_APP_CELL_START_IDX),
                   m_update_content_timer(NULL),
                   m_update_timer(NULL),
                   m_select_timer(NULL),
                   m_title_frame(NULL),
                   m_movingFrame(NULL)
{
    m_cur_scr_idx = cur_scr_idx;
    m_shell_panel = shell_panel_list;
    m_count = max_panel_num;

    if (m_shell_panel[cur_scr_idx] != NULL)
    {
        m_cell_rect = m_shell_panel[cur_scr_idx]->getAppBounds();
    }
    else
    {
        VfxSize size = getSize();
        m_cell_rect = VfxRect(0, 0, size.width, size.height);
    }
}


void VappShellWheelMenu::onInit()
{
    VcpWheelMenu::onInit();

    setCacheMode(VFX_CACHE_MODE_PREVENT);
    setIsZSortChild(VFX_TRUE);

    VfxU32 num = SHELL_MAX_CELL_NUM;
    VfxU32 focus_num = 0;
    for (VfxU32 i = num/2; i < SHELL_MAX_CELL_NUM; i++)
    {
        if (i%m_count == 0)
        {
            focus_num = i;
            break;
        }
    }

    setFocus(focus_num + m_cur_scr_idx);

    if (m_update_timer == NULL)
    {
        VFX_OBJ_CREATE(m_update_timer, VfxTimer, this);
        m_update_timer->setStartDelay(SHELL_APP_UPDATE_CONTENT_TIME);
        m_update_timer->m_signalTick.connect(this,
                         &VappShellWheelMenu::onUpdatePanel);
        m_update_timer->start();
    }
#ifdef __MMI_VUI_SHELL_BASE_SLIM__
    // in slim project, we only enable bitmap font. Thus,
    // the title text has to put in the fixed position.
    VfxSize size = getSize();
    VfxFontDesc font(VFX_FONT_DESC_SIZE_MEDIUM,
                     VFX_FONT_DESC_ATTR_BOLD,
                     VFX_FONT_DESC_EFFECT_NONE);
    VFX_OBJ_CREATE(m_title_frame, VfxTextFrame, this);

    VfxRect rect = m_shell_panel[m_cur_scr_idx]->getAppBounds();

    m_title_frame->setAutoResized(VFX_TRUE);
    m_title_frame->setPos(rect.getWidth()/3, rect.getHeight()/5);
    m_title_frame->setAnchor(0.5, 0.5);
    m_title_frame->setBgColor(VFX_COLOR_TRANSPARENT);
    m_title_frame->setFont(font);
    m_title_frame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_title_frame->setString(
        VFX_WSTR_RES(m_shell_panel[m_cur_scr_idx]->getPanelStrId()));
    m_title_frame->setIsCached(VFX_TRUE);
    m_title_frame->bringToFront();
#endif /* __MMI_VUI_SHELL_BASE_SLIM__ */
}


void VappShellWheelMenu::onDeinit()
{
    // clear cell list
    m_text_list.clear();
    m_cell_list.clear();
    m_reflection_list.clear();
    VcpWheelMenu::onDeinit();
}


void VappShellWheelMenu::onUpdatePanel(VfxTimer *source)
{
    // set page index
    VFX_UNUSED(source);

    VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_UPDATE_CELL, 1);

    // update cell content
    if (m_update_content_timer == NULL)
    {
        VFX_OBJ_CREATE(m_update_content_timer, VfxTimer, this);
        m_update_content_timer->m_signalTick.connect(this,
                             &VappShellWheelMenu::updateCellContent);
    }

    // start update content timer
    m_update_content_timer->setStartDelay(0);
    m_update_content_timer->start();
}


void VappShellWheelMenu::updateCellContent(VfxTimer *source)
{
    if (m_update_num <= getBehindCount())
    {
        VfxS8 display_idx;

        display_idx = m_update_num;

        VappShellWheelCell* item =
            (VappShellWheelCell*) getCellIfPresent(getFocus() + display_idx, 1);
        if (item)
        {
            item->updateCell();
            this->setFocused(VFX_TRUE);
        }
        m_update_num++;
        if (m_update_num <= getBehindCount())
        {
            VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_UPDATE_CELL, 2);
            m_update_content_timer->setStartDelay(SHELL_APP_UPDATE_CONTENT_TIME);
            m_update_content_timer->start();
        }
        else
        {
            VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_UPDATE_CELL, 3);
            m_update_content_timer->stop();
            m_update_num = SHELL_APP_CELL_START_IDX;
        }
    }
    else
    {
        /* should not occur */
        VFX_DEV_ASSERT(0);
    }
}


VfxFrame* VappShellWheelMenu::createCell(VfxS32 cell, VfxS32 subCell)
{
    VfxS8 num = cell%m_count;
    VfxFrame *frame = NULL;

    MyWheelMenuUserData data;
    data.ori_y = m_cell_rect.origin.y;
    data.width = m_cell_rect.getWidth();
    data.height = m_cell_rect.getHeight();

    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_CREATE_CELL, num, cell);

    if (subCell == 0)
    {
        /* create text title */
        // check whether the cell is already in the text list
        frame = chkCellInList<VappShellWheelTextCell>(num, m_text_list);
        if (frame == NULL)
        {
            // create cell
            VappShellWheelTextCell *text_item = NULL;
            VFX_OBJ_CREATE_EX(text_item, VappShellWheelTextCell, this,
                              (m_shell_panel[num]->getPanelStrId(), num));
            frame = (VfxFrame *)text_item;
        }
    #ifdef __MMI_VUI_SHELL_BASE_SLIM__
        // don't show transformed title frame under slim mode
        frame->setHidden(VFX_TRUE);
    #endif /* __MMI_VUI_SHELL_BASE_SLIM__ */
    }
    else if (subCell == 1)
    {
        /* create body */
        // check whether the cell is already in the cell list
        frame = chkCellInList<VappShellWheelCell>(num, m_cell_list);
        if (frame == NULL)
        {
        VappShellWheelCell *item = NULL;
            // create cell
            VFX_OBJ_CREATE_EX(item, VappShellWheelCell, this,
                              (m_shell_panel[num], num));
            frame = (VfxFrame *)item;
        }

        /* to avoid focused grapped by panel, set focus here again */
        this->setFocused(VFX_TRUE);
    }
    else if (subCell == 2)
    {
        /* create reflection image */
        // check whether the cell is already in the cell reflection list
        frame = chkCellInList<VappShellWheelReflectCell>(num, m_reflection_list);
        if (frame == NULL)
        {
            VappShellWheelReflectCell *reflect_item = NULL;
            // create cell
            VappShellWheelCell *target_item = (VappShellWheelCell*) getCellIfPresent(cell, 1);

            VFX_OBJ_CREATE_EX(reflect_item, VappShellWheelReflectCell, this,
                              (target_item, num));
            frame = (VfxFrame *)reflect_item;
        }
    }

    if (frame)
    {
        frame->setOpacity(1.0f);
        setCellUserData(cell, subCell, frame, &data, sizeof(MyWheelMenuUserData));
    }

    return frame;
}


void VappShellWheelMenu::onUpdateCell(VfxS32 cell, VfxS32 subCell, VfxFrame* cellFrame)
{
}


void VappShellWheelMenu::onCloseCell(VfxS32 cell, VfxS32 subCell, VfxFrame* cellFrame)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_CLOSE_CELL, cell, subCell);

    // save the cell if not in the list
    if (subCell >= 0 && subCell <= 2)
    {
        // this is body cell and we want to keep it
        VfxObjList *cell_list = NULL;

        if (subCell == 0)
        {
            cell_list = &m_text_list;
        }
        else if (subCell == 1)
        {
            cell_list = &m_cell_list;
        }
        else
        {
            cell_list = &m_reflection_list;
        }

        if (cellFrame &&
            !cell_list->contains(cellFrame))
        {
            cellFrame->setOpacity(0.0f);
            cell_list->append(cellFrame);
        }
    }
    else
    {
        VFX_OBJ_CLOSE(cellFrame);
    }
}


void VappShellWheelMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
    if (m_update_timer)
    {
        m_update_timer->stop();
        m_update_timer->setStartDelay(SHELL_APP_UPDATE_TIME);
        m_update_timer->start();
    }
    if (m_update_content_timer)
    {
        m_update_content_timer->stop();
        m_update_num = SHELL_APP_CELL_START_IDX;
    }

#ifdef __MMI_VUI_SHELL_BASE_SLIM__
    if(m_title_frame)
    {
        VfxU8 count = focusItem % m_count;
        m_title_frame->setString(
            VFX_WSTR_RES(m_shell_panel[count]->getPanelStrId()));
    }
#endif /*__MMI_VUI_SHELL_BASE_SLIM__ */
}


VfxBool VappShellWheelMenu::onPenInput(VfxPenEvent &event)
{
    if (m_select_timer != NULL)
    {
        // under page select transition
        return VFX_TRUE;
    }

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
    }

    return VcpWheelMenu::onPenInput(event);
}


VfxBool VappShellWheelMenu::onKeyInput(VfxKeyEvent &event)
{

    if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
        (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
         event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (m_select_timer == NULL)
        {
            setFocus(getFocus() - 1);
        }
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
             (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
              event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (m_select_timer == NULL)
        {
            setFocus(getFocus() + 1);
        }
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_CSK &&
             event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_MENU_KEY_EVENT, 1);
        if (m_select_timer == NULL)
        {
            VFX_OBJ_CLOSE(m_update_timer);
            VFX_OBJ_CLOSE(m_update_content_timer);
            m_signalSelect.postEmit(getFocus()%m_count);
        }
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_END &&
             event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_MENU_KEY_EVENT, 2);
        if (m_select_timer == NULL)
        {
            VFX_OBJ_CLOSE(m_update_timer);
            VFX_OBJ_CLOSE(m_update_content_timer);
            m_signalSelect.postEmit(m_cur_scr_idx);
        }
        return VFX_TRUE;
    }

    if (event.keyCode != VFX_KEY_CODE_END &&
        event.keyCode != VFX_KEY_CODE_POWER &&
        event.keyCode != VFX_KEY_CODE_SEND)
    {
        /* retrieved all keys events except end and send key */
        VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_MENU_KEY_EVENT, 3);
        return VFX_TRUE;
    }

    VFX_LOG(VFX_INFO2, VAPP_SHELL_BASE_MENU_KEY_EVENT, 0);
    return VcpWheelMenu::onKeyInput(event);
}


void VappShellWheelMenu::onDragStart()
{
    if (m_update_timer)
    {
        m_update_timer->stop();
    }
    if (m_update_content_timer)
    {
        m_update_content_timer->stop();
        m_update_num = SHELL_APP_CELL_START_IDX;
    }
}


void VappShellWheelMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(yspeed);
    if (xspeed == 0)
    {
        setFocus(VfxS32(getScrollIndex() + 0.5f));
    }
    else
    {
        VfxS32   s      = xspeed < 0 ? -1 : 1;
        VfxFloat m      = VFX_ABS(xspeed) / 999.9f;
        VfxFloat next_idx = 0;

        if (m > 1) m = 1;

        next_idx = getScrollIndex() - s * m;
        if (next_idx >= 0.0f)
        {
            if (s < 0)
            next_idx = ceilf(next_idx);
            else
                next_idx = floorf(next_idx);
        }
        else
        {
            if (s < 0)
            next_idx = floorf(next_idx);
            else
                next_idx = ceilf(next_idx);
        }
        setFocus(VfxS32(next_idx), 300);
    }

    // in idle state
    // start a update timer
    if (m_update_timer)
    {
        m_update_timer->stop();
        m_update_timer->setStartDelay(SHELL_APP_UPDATE_TIME);
        m_update_timer->start();
    }
}


void VappShellWheelMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_UNUSED(yoffset);
    VfxFloat next_idx = getScrollIndex() + (VfxFloat(xoffset)*-1) / (getSize().width * 3/4);

    setScrollIndex(next_idx, 0);
    if (m_update_timer)
    {
        m_update_timer->stop();
    }
    if (m_update_content_timer)
    {
        m_update_content_timer->stop();
        m_update_num = SHELL_APP_CELL_START_IDX;
    }
}


void VappShellWheelMenu::onTap(VfxPoint pt)
{
    VappShellWheelCell* cell = (VappShellWheelCell*)getCellIfPresent(getFocus(), 1);

    if (cell)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 right = main_screen_size.width*2/3;
        VfxS32 up = main_screen_size.height/4;
        VfxS32 down = up + main_screen_size.height/2;

        if (pt.x > right)
        {
            setFocus(getFocus() + 1);
        }
        else
        {
            if ((pt.x <= right))
            {
                // because maybe the scroll index is changing by drag
                // fix it
                VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_ON_TAP, getFocus()%m_count);
                setFocus(getFocus());

                if (pt.y >= up && pt.y <= down)
                {
                #if !defined(__MMI_VUI_SHELL_BASE_SLIM__)
                    onCellSelect(getFocus(), 1);

                    VFX_OBJ_CLOSE(m_update_timer);
                    VFX_OBJ_CLOSE(m_update_content_timer);

                    if (m_select_timer == NULL)
                    {
                        VFX_OBJ_CREATE(m_select_timer, VfxTimer, this);
                        m_select_timer->m_signalTick.connect(this,
                                         &VappShellWheelMenu::onCellSelectFinish);
                    }
                    m_select_timer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
                    m_select_timer->start();
                #else /* !defined(__MMI_VUI_SHELL_BASE_SLIM__) */
                    m_signalSelect.postEmit(getFocus()%m_count);
                    VFX_OBJ_CLOSE(m_update_timer);
                    VFX_OBJ_CLOSE(m_update_content_timer);
                #endif /* !defined(__MMI_VUI_SHELL_BASE_SLIM__) */
                }
            }
        }
    }
    else
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_BASE_ON_TAP, -1);
    }
}


void VappShellWheelMenu::onCellSelectFinish(VfxTimer *source)
{
#if !defined(__MMI_VUI_SHELL_BASE_SLIM__)
    VFX_OBJ_CLOSE(m_select_timer);
    m_signalSelect.postEmit(getFocus()%m_count);
#endif /* !defined(__MMI_VUI_SHELL_BASE_SLIM__) */
}


void VappShellWheelMenu::onCellSelect(VfxS32 cell, VfxS32 subCell)
{
#if !defined(__MMI_VUI_SHELL_BASE_SLIM__)
    VappShellWheelReflectCell *reflectCell = (VappShellWheelReflectCell*)getCellIfPresent(cell, 2);
    VfxFloat zOrder = 0.0f;

    if (reflectCell != NULL)
    {
        zOrder = reflectCell ->getPosZ();
    }
    else
    {
        VappShellWheelTextCell *textCell = (VappShellWheelTextCell *)getCellIfPresent(cell, 0);
        if (textCell != NULL)
        {
            zOrder = textCell->getPosZ();
        }
    }

    m_movingFrame = pullOutSubCell(cell, subCell);
    VFX_DEV_ASSERT(m_movingFrame != NULL);

    VfxTransform tempTransform = m_movingFrame->forceGetTransform();
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_movingFrame->setTransform(tempTransform);
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN );
    m_movingFrame->setPosZ(zOrder-1.0f);
    m_movingFrame->setAutoAnimate(VFX_TRUE);
    VfxTransform tempTransform2 = VfxTransform(VFX_TRANSFORM_TYPE_MATRIX3X3);

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    tempTransform2.data.matrix3x3.m[0] = main_screen_size.width/VAPP_SHELL_REAL_CELL_WIDTH;
    tempTransform2.data.matrix3x3.m[4] = (main_screen_size.height -
        (VappShellShortCutPanel ::PAGE_SHORTCUT_HEIGHT+
         VappShellShortCutPanel ::PAGE_IND_HEIGHT+
         SHELL_APP_STATUS_BAR_HEIGHT))/VAPP_SHELL_REAL_CELL_HEIGHT;
    tempTransform2.data.matrix3x3.m[6] = VAPP_SHELL_SHIFT_X_POS;
    tempTransform2.data.matrix3x3.m[7] = VAPP_SHELL_SHIFT_Y_POS;

    m_movingFrame->setTransform(tempTransform2);
    m_movingFrame->setPos(main_screen_size.width/2.0f,
                                           (main_screen_size.height-SHELL_APP_STATUS_BAR_HEIGHT)/2.0f);
    VfxAutoAnimate::commit();
#endif /* !defined(__MMI_VUI_SHELL_BASE_SLIM__) */
}


VfxS32 VappShellWheelMenu::getCount()
{
    return SHELL_MAX_CELL_NUM;
}


VfxS32 VappShellWheelMenu::getSubCellCount()
{
    return SHELL_MAX_SUB_CELL_COUNT;
}


VfxS32 VappShellWheelMenu::getBehindCount()
{
    return SHELL_MAX_BEHIND_CELL_COUNT;
}


VfxS32 VappShellWheelMenu::getAheadCount()
{
    return SHELL_MAX_AHEAD_CELL_COUNT;
}


void VappShellWheelMenu::myFrontViewEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        VfxMatrix4x4                        &totalProject,
        VfxFloat                            fPos,
        VfxS32                              focus,
        VfxRect                             viewBounds,
        void                                *userData,
        VfxU32                              userDataSize
        )
{
    VFX_UNUSED(focus);
    VFX_UNUSED(userDataSize);

    VfxFloat offset = -1*cellRelPos;
    VfxMatrix4x4 cameraView;
    VfxMatrix4x4 modelView;
    VfxMatrix4x4 RT;

    // define ellipse semimajor axis a and semiminor axis b
    VfxFloat a = s_seminajor;
    VfxFloat b = s_semininor;

    // define the theta of ellipse parametric equation
    // the focus item is on the 60 degree of ellipse.
    VfxFloat aaa;

    MyWheelMenuUserData *data = (MyWheelMenuUserData*)userData;

    if (VFX_ABS(offset) < 1)
    {
        aaa = 1;
    }
    else
    {
        aaa = s_aaa;
    }
    VfxFloat theta;
    if (VFX_ABS(offset) <= 1)
    {
        theta = s_focused_angle + s_angle*offset;
    }
    else
    {
        if (offset > 0)
        {
            theta = s_focused_angle +
                         (VFX_ABS(offset)-1) * aaa * s_angle + s_angle;
        }
        else
        {
            theta = s_focused_angle +
                         (1- VFX_ABS(offset)) * aaa * s_angle - s_angle;
        }
    }
    //VfxFloat theta = s_focused_angle + s_angle*offset;

    VfxFloat norm;


    // set Camear parameters :
    // Se set translateX as viewBounds.size.width/2 and
    // translateY as viewBounds.size.height/2.
    // So the 3D origin will project into the screen center.
    // Set CameraDistance & nearPlane will change the perspecitve
    // degree of 3D scene.

    cameraView.setCamera(
        1.0f,
        1.0f,
        (VfxFloat)(viewBounds.size.width/2),
        (VfxFloat)(viewBounds.size.height/2),
        (VfxFloat)s_overview_near_plane,
        (VfxFloat)s_camera_disc,
        0,
        0,
        0);

    // set Model View :
    // The model view matirx decides the origin and direction of model.
    // We set the origin of each item to the center of item.
    // So we need to apply a negative translate.
    // 160/2 is the item's half width and 60/2 is item's half height.
     modelView.setTranslation((VfxFloat)(-1 * (data->width/2)),
                            (VfxFloat)(-1 * data->height/2),
                            0);
    if (subCell == 1 || subCell == 2)
    {
        VfxMatrix4x4 scale;
        scale.setScale(VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR,
                       VAPP_SHELL_MULTI_PAGE_CP_SCALE_FACTOR, 1);

        modelView = modelView * scale;
    }

    // set RT matrix :
    // RT matrix decide the rotate part and translate part of model.
    // We can calculate tangent vector as (-a*sin(theta), 0 , b * cos(theta)),
    // and normal vector as (b * cos(theta)), 0, -a*sin(theta)).
    // We need to transform or item x, z direction as tangent, normal vector.
    // So we need calculate orthonormal matix. We calculate norm.
    norm = sqrt(a * a * vfxSin(VFX_DEG_TO_RAD(theta)) * vfxSin(VFX_DEG_TO_RAD(theta)) + b * b * vfxCos(VFX_DEG_TO_RAD(theta)) * vfxCos(VFX_DEG_TO_RAD(theta)));

    RT.m[0] = a * vfxSin(VFX_DEG_TO_RAD(theta))/norm;
    RT.m[8] = b * vfxCos(VFX_DEG_TO_RAD(theta))/norm;
    RT.m[2] =  RT.m[8];
    RT.m[10] = -1 * RT.m[0];
    // The ralation part is parametric equation of ellipse.
    // We set a 250 shift on X, so the view will see the right side of ellipse.
    RT.m[12] = a * vfxCos(VFX_DEG_TO_RAD(theta)) + s_shift_x + data->width/4;
    RT.m[14] = -1 * b * vfxSin(VFX_DEG_TO_RAD(theta));
    if (subCell == 0)
    {
        RT.m[13] = -1*VAPP_SHELL_TEXT_RESERV_Y;
    }
    else if (subCell == 2)
    {
        RT.m[13] = data->height+VAPP_SHELL_BORDER_WIDTH*2;
    }

    // Now we multiply cameraView, RT and modelview to get totalProject.
    totalProject = cameraView * RT * modelView;

    return;
}


vrt_render_dirty_type_enum VappShellWheelMenu::myAllInOneViewEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,
        VfxFloat                            fPos,
        VfxS32                              focus,
        VfxRect                             viewBounds,
        void                                *userData,
        VfxU32                              userDataSize,
        VcpWheelMenuState state,
        VfxFloat level
        )
{
    VFX_UNUSED(focus);
    VFX_UNUSED(userDataSize);
    VFX_DEV_ASSERT(target_frame != NULL);
    VfxMatrix4x4 totalProject;


    myFrontViewEffectCB(cell, subCell, cellRelPos,
                            totalProject, fPos, focus, viewBounds,
                            userData, userDataSize);
    // Set as 3x3 matrix for VRT rendering.
    target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
    totalProject.initMatrix3x3(target_frame->transform.data.matrix3x3);


    if (cellRelPos >= (SHELL_MAX_BEHIND_CELL_COUNT+1) ||
        cellRelPos <= (SHELL_MAX_AHEAD_CELL_COUNT-1))
    {
        target_frame->opacity = 0.0f;
    }
    else if ((cellRelPos > 0 &&
                  cellRelPos < (SHELL_MAX_BEHIND_CELL_COUNT+1)) ||
                 (cellRelPos < 0 && cellRelPos > (SHELL_MAX_AHEAD_CELL_COUNT-1)))
    {
         VfxS8 sign;
        if (cellRelPos > 0 &&
            cellRelPos < (SHELL_MAX_BEHIND_CELL_COUNT+1))
            sign = 1;
        else
            sign = -1;

        target_frame->opacity = 1.0f - (sign * (cellRelPos - (VfxS32)(cellRelPos)));

        if (cellRelPos <= (SHELL_MAX_BEHIND_CELL_COUNT-1))
        {
            if (target_frame->opacity < 0.75f ||
                target_frame->opacity == 1.0f)
            {
                target_frame->opacity = 0.75f;
            }
        }
        else if (cellRelPos <= SHELL_MAX_BEHIND_CELL_COUNT)
        {
            if (
                target_frame->opacity == 1.0f ||
                target_frame->opacity < 0.3f)
            {
                target_frame->opacity = 0.3f;
            }
            else if (target_frame->opacity > 0.75f)
            {
                target_frame->opacity = 0.75f;
            }
        }
        else
        {
            if (target_frame->opacity > 0.3f)
            {
                target_frame->opacity = 0.3f;
            }
        }
    }
    else
    {
        target_frame->opacity = 1.0f;
    }


    if (subCell == 2)
    {
        // workaround solution: vrt does not guarantee order of the same z position. we need to minus 0.1 here
        // to assure reflection is drawn before content body
        target_frame->pos_z = VFX_ABS(cellRelPos) - 0.1f;
    }
    else
    {
        target_frame->pos_z = VFX_ABS(cellRelPos);
    }
    return  VRT_RENDER_DIRTY_TYPE_DIRTY;
}


VcpWheelMenuFrameEffectCBFuncPtr VappShellWheelMenu::getFrameEffectCB()
{
    return &VappShellWheelMenu::myAllInOneViewEffectCB;
}

#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */


