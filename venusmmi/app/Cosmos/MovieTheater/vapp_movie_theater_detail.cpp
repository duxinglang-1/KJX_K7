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
 *  vapp_movie_theater_detail.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_COSMOS_MOVIE_THEATER__
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_movie_theater_def.h"
#include "mmi_rp_vapp_fmgr_def.h"
#include "vapp_movie_theater.h"
#include "vapp_movie_theater_detail.h"
#include "vcp_include.h"
#include "vcp_title_bar.h"
#include "../xml/vfx_xml_loader.h"

#include "vapp_gallery_gprot.h"

extern "C"
{
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "MotSrvGprot.h"
}

/*
//DCM
*/

#pragma arm section code = "DYNAMIC_CODE_MOT_ROCODE", rodata = "DYNAMIC_CODE_MOT_RODATA"


/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/


//VFX_IMPLEMENT_CLASS("VappMovieTheaterTitleCell", VappMovieTheaterTitleCell, VfxControl);


void VappMovieTheaterTitleCell::onInit()
{
    VfxControl::onInit();

    m_bg = NULL;

    setBounds(VfxRect(0, 0, ITEM_WIDTH, ITEM_HEIGHT));

    VFX_OBJ_CREATE(m_bg, VfxFrame, this);
    m_bg->setBounds(VfxRect(0, 0, ITEM_WIDTH, ITEM_HEIGHT));
    //m_bg->setImgContent(VfxImageSrc(IMG_ID_VAPP_FMGR_PARENT_FOLDER_BG));
    m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VfxS32 x = 0, y = 0;

    /* create thumb icon */
    VFX_OBJ_CREATE(m_img, VfxImageFrame, m_bg);
    m_img->setResId(IMG_ID_VAPP_MOVIE_THEATER_DEFAULT_VIDEO_ICON);
    m_img->setSize(THUMB_ICON_WIDTH, THUMB_ICON_HEIGHT);
    m_img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_img->setAnchor(0, 0.5);

    x = ICON_LSIDE_ALIGN;
    y = ITEM_HEIGHT/2;
    m_img->setPos(x, y);

    x += THUMB_ICON_WIDTH + ICON_RSIDE_ALIGN;   // for text position

    /* create main text */
    VFX_OBJ_CREATE(m_txt, VfxTextFrame, m_bg);
    m_txt->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_txt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_txt->setSize(TEXT_WIDTH, MAIN_TEXT_HEIGHT);
    m_txt->setAutoResized(VFX_FALSE);
    m_txt->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_txt->forceUpdate();

    /* create sub text */
    VFX_OBJ_CREATE(m_txt_sub, VfxTextFrame, m_bg);
    m_txt_sub->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SUB_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_txt_sub->setSize(TEXT_WIDTH, SUB_TEXT_HEIGHT);
    m_txt_sub->setAutoResized(VFX_FALSE);
    m_txt_sub->setString(VFX_WSTR_RES(STR_GLOBAL_LOADING));
    m_txt_sub->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    m_txt_sub->forceUpdate();

    x += TEXT_LSIDE_ALIGN;
    y = (ITEM_HEIGHT-(m_txt->getSize().height+m_txt_sub->getSize().height+TXT_Y_GAP))/2;

    m_txt->setPos(x, y);

    y += m_txt->getSize().height + TXT_Y_GAP;

    m_txt_sub->setPos(x, y);
}

void VappMovieTheaterTitleCell::onDeinit()
{
    VFX_OBJ_CLOSE(m_img);
    VFX_OBJ_CLOSE(m_txt);
    VFX_OBJ_CLOSE(m_txt_sub);
    VFX_OBJ_CLOSE(m_bg);

    VfxControl::onDeinit();
}

void VappMovieTheaterTitleCell::setMainText(VfxWString &text)
{
    m_txt->setString(text);
}

void VappMovieTheaterTitleCell::setSubText(VfxWString &text)
{
    m_txt_sub->setString(text);
}

void VappMovieTheaterTitleCell::setImage(const VfxU8 *buf)
{
    m_img->setMem(buf);
    m_img->setSize(THUMB_ICON_WIDTH, THUMB_ICON_HEIGHT);
    m_img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
}

//VFX_IMPLEMENT_CLASS("VappMovieTheaterDetailCell", VappMovieTheaterDetailCell, VcpFormItemBase);

VappMovieTheaterDetailCell::VappMovieTheaterDetailCell() :
    m_firstCell(VFX_FALSE)
{
}

VappMovieTheaterDetailCell::VappMovieTheaterDetailCell(VfxBool firstCell) :
    m_firstCell(firstCell)
{
}

void VappMovieTheaterDetailCell::onInit()
{
    VcpFormItemBase::onInit();

    m_txt = NULL;
    m_txt_sub = NULL;

    /* set background color */
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    VfxS32 x = GAP;
    VfxS32 y = CELL_GAP;
    if (m_firstCell)
    {
        y = (GAP - VCPFRM_ITEM_HORZ_GAP_1);
    }

    // create main text
    VFX_OBJ_CREATE(m_txt, VfxTextFrame, this);
    m_txt->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_txt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_txt->setPos(x, y);
    m_txt->setSize(ITEM_WIDTH-(EDITOR_SIZE+2*GAP+EDITOR_GAP), MAIN_TEXT_HEIGHT);
    m_txt->setAutoResized(VFX_FALSE);
    m_txt->forceUpdate();


    VfxS32 height = GAP + SUB_TEXT_HEIGHT;
    setSize(ITEM_WIDTH, GAP + SUB_TEXT_HEIGHT);
    setHeight(height);
}

void VappMovieTheaterDetailCell::setMainText(const VfxWString &text)
{
    VfxS32 t_dis = m_firstCell? (GAP - VCPFRM_ITEM_HORZ_GAP_1) : CELL_GAP;

    m_txt->setString(text);

    VfxS32 height = t_dis + m_txt->getSize().height + TXT_Y_GAP;
    setHeight(height);
}

void VappMovieTheaterDetailCell::setSubText(const VfxWString &text)
{
    // create sub text
    VfxS32 t_dis = m_firstCell? (GAP - VCPFRM_ITEM_HORZ_GAP_1) : CELL_GAP;

    if (m_txt_sub == NULL)
    {
        VfxS32 x = GAP, y = t_dis + m_txt->getSize().height + TXT_Y_GAP;
        VFX_OBJ_CREATE(m_txt_sub, VfxTextFrame, this);
        m_txt_sub->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));

        m_txt_sub->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SUB_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        m_txt_sub->setPos(x, y);
        m_txt_sub->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_txt_sub->setSize((ITEM_WIDTH-(2*GAP+EDITOR_GAP)), SUB_TEXT_HEIGHT);
    }
    m_txt_sub->setString(text);
    m_txt_sub->forceUpdate();

    VfxS32 height = t_dis + m_txt_sub->getSize().height + m_txt->getSize().height + TXT_Y_GAP;

    setHeight(height);
}


//VFX_IMPLEMENT_CLASS("VappMovieTheaterDetailPage", VappMovieTheaterDetailPage, VappMovieTheaterPage);

VappMovieTheaterDetailPage::VappMovieTheaterDetailPage():
    m_titleBar(NULL),
    m_titleCell(NULL),
    m_form(NULL),
    m_toolBar(NULL)
{
    m_titleCellImage = NULL;
}

void VappMovieTheaterDetailPage::onInit()
{
    VappMovieTheaterPage::onInit(); // call base class
}

void VappMovieTheaterDetailPage::onDeinit()
{
    VappMovieTheaterPage::onDeinit();
}

void VappMovieTheaterDetailPage::onEnter(VfxBool isBackward)
{
    if (m_titleBar == NULL)
    {
        VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
        m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
        m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_DETAILS));
        setTopBar(m_titleBar);
    }

    if (m_titleCell == NULL)
    {
        VFX_OBJ_CREATE(m_titleCell, VappMovieTheaterTitleCell, this);

        m_titleCellImage = (VfxU8*)applib_asm_alloc_nc_r(m_appId, VAPP_MOVIE_THEATER_THUMBNAIL_RES_SIZE);
        //VFX_ALLOC_MEM(m_titleCellImage, SRV_MOT_THUMBNAIL_SIZE + 8, this);

        VfxWString text;

        m_provider->getMediaName(m_currMediaId, text);
        m_titleCell->setMainText(text);

        m_provider->getMediaDurationStr(m_currMediaId, text);
        m_titleCell->setSubText(text);

        U32 thumbnail_size;                                     /* thumbnail size */

        m_provider->getMediaThumb(m_currMediaId, m_titleCellImage, thumbnail_size);
        if (thumbnail_size)
        {
            m_titleCell->setImage(m_titleCellImage);
        }
    }

    if (m_toolBar == NULL)
    {

        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);

        m_toolBar->addItem('PLAY', VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_PLAY), IMG_ID_VAPP_MOVIE_THEATER_PLAY_ICON);
        m_toolBar->setDisableItem('PLAY', VFX_FALSE);
        m_toolBar->m_signalButtonTap.connect(this, &VappMovieTheaterDetailPage::onClickToolBarButton);
        m_toolBar->setHidden(VFX_FALSE);
        setBottomBar(m_toolBar);
    }

    drawFileDetail();
}

void VappMovieTheaterDetailPage::onExited2()
{
    if (m_titleCell)
    {
        VFX_OBJ_CLOSE(m_titleCell);
    }
    if (m_titleCellImage)
    {
        applib_asm_free_r(m_appId, m_titleCellImage);
        m_titleCellImage = NULL;
    }
}

void VappMovieTheaterDetailPage::setSource(srv_mot_cat_enum catId, VfxU32 mediaId)
{
    m_currCatId = catId;
    m_currMediaId = mediaId;
}

void VappMovieTheaterDetailPage::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{
    VfxWString path;
    VfxU64 time = 0;

    m_provider->getMediaPath(m_currMediaId, path);
    if (m_currCatId == SRV_MOT_CAT_RECENT_PLAY)
    {
        m_provider->getMediaLastPlayTime(m_currMediaId, time);
    }

    launchVideoPlayer(path, time);
}

void VappMovieTheaterDetailPage::drawFileDetail()
{
    if (m_form == NULL)
    {
        VFX_OBJ_CREATE(m_form, VcpForm, this);
        m_form->setContentTopGap(VCPFRM_ITEM_HORZ_GAP_1);
        m_form->setSize(getParentControl()->getSize().width, getParentControl()->getSize().height - VAPP_MOVIE_THEATER_STATUS_BAR_HEIGHT - m_titleBar->getSize().height - VappMovieTheaterTitleCell::ITEM_HEIGHT - m_toolBar->getSize().height);
        m_form->setPos(0, VappMovieTheaterTitleCell::ITEM_HEIGHT);
        m_form->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

        VfxWString str;
        VfxId itemId = 0;
        VappMovieTheaterDetailCell *cell;

        VFX_OBJ_CREATE_EX(cell, VappMovieTheaterDetailCell, m_form, (VFX_TRUE));
        cell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_MOVIE_NAME));
        m_provider->getMediaTitle(m_currMediaId, str);
        if (!str.isEmpty())
        {
            cell->setSubText(str);
            str.setNull();
        }
        m_form->addItem(cell, itemId++);

        VFX_OBJ_CREATE(cell, VappMovieTheaterDetailCell, m_form);
        cell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_DURATION));
        m_provider->getMediaDuration(m_currMediaId, str);
        if (!str.isEmpty())
        {
            cell->setSubText(str);
            str.setNull();
        }
        m_form->addItem(cell, itemId++);

        VFX_OBJ_CREATE(cell, VappMovieTheaterDetailCell, m_form);
        cell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_YEAR));
        m_provider->getMediaYear(m_currMediaId, str);
        if (!str.isEmpty())
        {
            cell->setSubText(str);
            str.setNull();
        }
        m_form->addItem(cell, itemId++);

        VFX_OBJ_CREATE(cell, VappMovieTheaterDetailCell, m_form);
        cell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_STARRING));
        m_provider->getMediaStarring(m_currMediaId, str);
        if (!str.isEmpty())
        {
            cell->setSubText(str);
            str.setNull();
        }
        m_form->addItem(cell, itemId++);

        VFX_OBJ_CREATE(cell, VappMovieTheaterDetailCell, m_form);
        cell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_CATEGORY));
        m_provider->getCategoryString(m_currMediaId, str);
        if (!str.isEmpty())
        {
            cell->setSubText(str);
            str.setNull();
        }
        m_form->addItem(cell, itemId++);

        VFX_OBJ_CREATE(cell, VappMovieTheaterDetailCell, m_form);
        cell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_PLOT));
        m_provider->getMediaPlot(m_currMediaId, str);
        if (!str.isEmpty())
        {
            cell->setSubText(str);
            str.setNull();
        }
        m_form->addItem(cell, itemId++);
    }
}

//DCM
#pragma arm section code, rodata


#endif
