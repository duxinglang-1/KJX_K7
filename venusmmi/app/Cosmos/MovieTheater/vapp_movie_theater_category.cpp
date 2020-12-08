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
 *  vapp_movie_theater_category.cpp
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
#include "vapp_movie_theater_category.h"
#include "vapp_movie_theater_detail.h"
#include "vcp_include.h"
#include "vcp_tab_title_bar.h"
#include "../xml/vfx_xml_loader.h"

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
#define VTHUMB_WIDTH (VappMovieTheaterCategoryMenuItemFrame::VIDEO_THUMB_W)
#define VTHUMB_HEIGHT (VappMovieTheaterCategoryMenuItemFrame::VIDEO_THUMB_H)
#define VTHUMB_BK_COLOR (231)

enum VappMovieTheaterCategoryLayout
{
#if defined(__MMI_MAINLCD_320X480__)
    TITLE_LINE_TOP = 5,
    TITLE_LINE_RIGHT = 0,
    DESC_LINE_TOP = 30,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    DETAIL_ICON_TOP = 15, //29,
    DETAIL_ICON_LEFT = 45, //23,
    BOOKMARK_TEXT_LEFT = 88,
    TIME_TEXT_W = 62,
    TIME_TEXT_h = 20,

#elif defined(__MMI_MAINLCD_480X800__)
    TITLE_LINE_TOP = 12,
    TITLE_LINE_RIGHT = 0,
    DESC_LINE_TOP = 57,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    DETAIL_ICON_TOP = 22,//52,
    DETAIL_ICON_LEFT = 61,//31,
    BOOKMARK_TEXT_LEFT = 121,
    TIME_TEXT_W = 84,
    TIME_TEXT_h = 30,

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    TITLE_LINE_TOP = 5,
    TITLE_LINE_RIGHT = 0,
    DESC_LINE_TOP = 32,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    DETAIL_ICON_TOP = 3, //5,
    DETAIL_ICON_LEFT = 40,//24,
    BOOKMARK_TEXT_LEFT = 54,
    TIME_TEXT_W = 47,
    TIME_TEXT_h = 20,

#else
    // prevent build error
    TITLE_LINE_TOP = 5,
    TITLE_LINE_RIGHT = 0,
    DESC_LINE_TOP = 30,
    TEXT_LEFT = VTHUMB_WIDTH + 8,
    DETAIL_ICON_TOP = 26,
    DETAIL_ICON_LEFT = 23,
    BOOKMARK_TEXT_LEFT = 65,
    TIME_TEXT_W = 45,
    TIME_TEXT_h = 20,

#endif
};

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappMovieTheaterCategoryPage", VappMovieTheaterCategoryPage, VappMovieTheaterPage);

VappMovieTheaterCategoryPage::VappMovieTheaterCategoryPage(srv_mot_cat_enum cat):
    m_videoMenu(NULL),
    m_isExit(VFX_FALSE)
    //m_thumbRefreshTimer(NULL)
{
    m_currCatId = cat;
    m_currCatNum = (VfxU32)-1;
}

void VappMovieTheaterCategoryPage::onInit()
{
    MMI_ID_TYPE str_id;

    VappMovieTheaterPage::onInit(); // call base class

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    kal_mem_set(&m_viewState, 0, sizeof(m_viewState));

    // title bar
    VcpTitleBar *bar = NULL;
    srv_mot_get_category_string_id(m_currCatId, &str_id);
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(str_id));
    setTopBar(bar);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}

void VappMovieTheaterCategoryPage::setupVideoMenu()
{
    if (NULL == m_videoMenu)
    {
        VFX_OBJ_CREATE(m_videoMenu, VcpListMenu, this);
        // use default VcpListMenu item height
        m_videoMenu->setSize(getSize());
        m_videoMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT);
        m_videoMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
        m_videoMenu->m_signalItemTapped.connect(this, &VappMovieTheaterCategoryPage::onItemTapped);
        m_videoMenu->m_signalCmdButtonClicked.connect(this, &VappMovieTheaterCategoryPage::onClickCmdButton);
        m_videoMenu->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE);
        m_videoMenu->setContentProvider(this);
//        m_videoMenu->m_signalViewScrollStart.connect(this, &VappMovieTheaterCategoryPage::handleViewScrollStart);
//        m_videoMenu->m_signalViewScrollEnd.connect(this, &VappMovieTheaterCategoryPage::handleViewScrollEnd);
    }

    m_videoMenu->setMenuMode(
                    //isMultiSelecting() ? VCP_LIST_MENU_MODE_MULTI_SELECTION : VCP_LIST_MENU_MODE_NORMAL,
                    VCP_LIST_MENU_MODE_NORMAL,
                    VFX_FALSE);
}

void VappMovieTheaterCategoryPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_ENTER);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    m_isExit = VFX_FALSE;

//    if(m_thumbRefreshTimer)
//    {
//        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_M_THUMB_REFRESH_TIMER_START_LINE_D, __LINE__);
//        m_thumbRefreshTimer->start();
//    }

    // show waiting icon until list is ready
    showPageWaitIcon(VFX_TRUE);

    onMediaListReady();
}

void VappMovieTheaterCategoryPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_ENTERED);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    checkUpdate();

	if(m_currCatId == SRV_MOT_CAT_RECENT_PLAY)
	{
	    srv_mot_ret_enum ret = m_plUpdateRet;

		if(ret == SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH)
		{
			m_plUpdateRet = SRV_MOT_S_OK;
			VfxWString text;
			
			m_provider->getErrorString(ret, text);
			mmi_frm_nmgr_balloon(
				  MMI_SCENARIO_ID_DEFAULT,
				  MMI_EVENT_INFO_BALLOON,
				  MMI_NMGR_BALLOON_TYPE_FAILURE,
				  text.getBuf());
		}
	}
}

void VappMovieTheaterCategoryPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_EXIT);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

//    if(m_thumbRefreshTimer)
//    {
//        m_thumbRefreshTimer->stop();
//        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_M_THUMB_REFRESH_TIMER_STOP_LINE_D, __LINE__);
//    }

    m_isExit = VFX_TRUE;
    return;
}

void VappMovieTheaterCategoryPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_EXITED2);
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    if(m_videoMenu)
    {
        m_videoMenu->getViewState(&m_viewState);
//        m_videoMenu->m_signalViewScrollStart.disconnect(this, &VappMovieTheaterCategoryPage::handleViewScrollStart);
//        m_videoMenu->m_signalViewScrollEnd.disconnect(this, &VappMovieTheaterCategoryPage::handleViewScrollEnd);
        VFX_OBJ_CLOSE(m_videoMenu);
        m_provider->destroyMediaCache();
    }

//    if(m_thumbRefreshTimer)
//    {
//        m_thumbRefreshTimer->stop();
//    }
}

void VappMovieTheaterCategoryPage::onUpdate()
{
    VappMovieTheaterPage::onUpdate();
    if(m_videoMenu)
    {
        m_videoMenu->updateAllItems();
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappMovieTheaterCategoryPage::onMediaListReady()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_VIDEO_PAGE_ON_MEDIA_LIST_READY);

    m_provider->getCategoryCount(m_currCatId, &m_currCatNum);

    if(m_currCatNum == 0)
    {
        setPageMessage(VFX_WSTR_RES(STR_ID_VAPP_MOVIE_THEATER_NO_VIDEO));
        showPageMessage(VFX_TRUE);
    }
    else
    {
        showPageMessage(VFX_FALSE);
        // create video list after list ready
        setupVideoMenu();
        checkUpdate();
    }

    if(m_videoMenu)
    {
//        m_videoMenu->m_signalViewScrollStart.connect(this, &VappMovieTheaterCategoryPage::handleViewScrollStart);
//        m_videoMenu->m_signalViewScrollEnd.connect(this, &VappMovieTheaterCategoryPage::handleViewScrollEnd);
        m_videoMenu->setViewState(&m_viewState);

        m_provider->refreshCategoryList(m_currCatId);
        m_provider->createMediaCache();
    }
    showPageWaitIcon(VFX_FALSE);
}

void VappMovieTheaterCategoryPage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VfxWString path;
    VfxU64 time = 0;
    VfxU32 mediaId;

    m_provider->getMediaId(index, mediaId);
    m_currMediaId = mediaId;

    m_provider->getMediaPath(mediaId, path);
    if (m_currCatId == SRV_MOT_CAT_RECENT_PLAY)
    {

        m_provider->getMediaLastPlayTime(mediaId, time);
    }

    launchVideoPlayer(path, time);
}

void VappMovieTheaterCategoryPage::onClickCmdButton(VcpListMenu *listmenu, VfxU32 index)
{
    VappMovieTheaterDetailPage *page = NULL;
    VFX_OBJ_CREATE(page, VappMovieTheaterDetailPage, getMainScr());

    page->setProvider(m_provider);

    VfxU32 mediaId;
    m_provider->getMediaId(index, mediaId);
    page->setSource(m_currCatId, mediaId);

    getMainScr()->pushPage(0, page);
}

////////////////////////////////////////////////////////////////////
//  Implementation of IListMenuContentProvider - Custom Layout
////////////////////////////////////////////////////////////////////

VfxU32 VappMovieTheaterCategoryPage::getCount() const
{

    // m_currCatNum should be set when list CP ready.
    /*
    if (m_currCatNum == (VfxU32)-1)
    {
        m_provider->getCategoryCount(m_currCatId, (VfxU32*)&m_currCatNum);
    }
    */

    return m_currCatNum;
}

VfxBool VappMovieTheaterCategoryPage::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{

    VfxU32 mediaId;
    m_provider->getMediaId(index, mediaId);
	
    // item texts
    if(VCP_LIST_MENU_FIELD_TEXT == fieldType)
    {
        m_provider->getMediaName(mediaId, text);

        return VFX_TRUE;
    }
    else if(VCP_LIST_MENU_FIELD_SUB_TEXT1 == fieldType &&
            !m_isExit)
    {
        if (m_currCatId == SRV_MOT_CAT_RECENT_PLAY)
        {
            m_provider->getMediaLastPlayTimeStr(mediaId, text);
        }
        else
        {
            m_provider->getMediaDurationStr(mediaId, text);
        }

        return VFX_TRUE;
    }
    else if(VCP_LIST_MENU_FIELD_SUB_TEXT2 == fieldType &&
            !m_isExit)
    {
        return VFX_FALSE;
    }
    return VFX_FALSE;
}

VfxBool VappMovieTheaterCategoryPage::getItemImage(
    VfxU32 index,                 // [IN] the index of item
    VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    )
{

    VfxU32 mediaId;
    m_provider->getMediaId(index, mediaId);

    if(VCP_LIST_MENU_FIELD_ICON == fieldType)
    {
            U8 *thumbnail_buf;
            U32 thumbnail_size;                                             /* thumbnail size */
            m_provider->getMediaThumb(mediaId, &thumbnail_buf, thumbnail_size);
            if (thumbnail_size)
            {
                image.setMem(thumbnail_buf);
            }
            else
            {
                image.setResId(IMG_ID_VAPP_MOVIE_THEATER_DEFAULT_VIDEO_ICON);
            }
            return VFX_TRUE;
    }
    else if(VCP_LIST_MENU_FIELD_ICON_EXTRA1 == fieldType)
    {
        //image.setResId(IMG_ID_VAPP_MOVIE_THEATER_DETAIL_ICON);
        //return VFX_TRUE;
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
             fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED ||
             fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
             fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
    {
        image = VfxImageSrc(IMG_ID_VAPP_MOVIE_THEATER_DETAIL_ICON);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappMovieTheaterCategoryPage::closeItemImage(
    VfxU32 index,                 // [IN] the index of item
    VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
    VfxImageSrc imgSrc              // [IN] the image resource
    )
{
    VfxU32 mediaId;
    m_provider->getMediaId(index, mediaId);

    if(VCP_LIST_MENU_FIELD_ICON == fieldType)
    {
        if (imgSrc.getType() == VFX_IMAGE_SRC_TYPE_MEM)
        {
            m_provider->freeMediaThumb(mediaId);
        }
    }
}

VcpListMenuItemStateEnum VappMovieTheaterCategoryPage::getItemState(
    VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;

}

VcpListMenuCellClientBaseFrame* VappMovieTheaterCategoryPage::getItemCustomContentFrame(
                                                        VfxU32 index,
                                                        VfxFrame *parentFrame)
{
    VappMovieTheaterCategoryMenuItemFrame *pCell = NULL;
    VFX_OBJ_CREATE(pCell, VappMovieTheaterCategoryMenuItemFrame, parentFrame);
    return pCell;
}


void VappMovieTheaterCategoryPage::closeItemCustomContentFrame(VfxU32 index,
                                                       VcpListMenuCellClientBaseFrame *cell)
{
    VFX_OBJ_CLOSE(cell);
    return;
}

VappMovieTheaterCategoryMenuItemFrame::VappMovieTheaterCategoryMenuItemFrame()
{
}

void VappMovieTheaterCategoryMenuItemFrame::onLayoutElements()
{
    if(NULL == m_textFrame2)
    {
        VFX_OBJ_CREATE(m_textFrame2, VfxTextFrame, this);
        m_textFrame2->setAutoAnimate(VFX_TRUE);
    }

    VcpListMenuCellIconTripleTextFrame::onLayoutElements();

    // adjust video thumbnail icon position.
    if(m_imageFrame)
    {
        m_imageFrame->setSize(VTHUMB_WIDTH, VTHUMB_HEIGHT);
        m_imageFrame->setPos(1, 1);
        //m_imageFrame->setBgColor(VfxColor(255, VTHUMB_BK_COLOR, VTHUMB_BK_COLOR, VTHUMB_BK_COLOR));
        //m_imageFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
        m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    // file name position
    if(m_textFrame1)
    {
        const VfxS32 titleLineWidth = getRect().getWidth() - TEXT_LEFT - TEXT1_RIGHT_GAPS - TITLE_LINE_RIGHT;
        m_textFrame1->setSize(titleLineWidth, m_textFrame1->getSize().height);
        m_textFrame1->setPos(TEXT_LEFT, TITLE_LINE_TOP);
        m_textFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    // duration text
    if(m_textFrame2)
    {
        VfxTextFrame *durationTxt = VFX_OBJ_DYNAMIC_CAST(m_textFrame2, VfxTextFrame);
        if(durationTxt)
        {
            durationTxt->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            durationTxt->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
        }
        const VfxS32 durationLineWidth = getRect().getWidth() - TEXT_LEFT - TEXT1_RIGHT_GAPS - TITLE_LINE_RIGHT;
        m_textFrame2->setSize(durationLineWidth, m_textFrame2->getSize().height);
        m_textFrame2->setPos(TEXT_LEFT, DESC_LINE_TOP);
        m_textFrame2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_NONE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    // last played icon (a pause icon)
    if (m_extraImgFrame1)
    {
        m_extraImgFrame1->setPos(getSize().width - DETAIL_ICON_LEFT, DETAIL_ICON_TOP);
        m_extraImgFrame1->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                         VFX_FRAME_ALIGNER_MODE_SIDE,
                                         VFX_FRAME_ALIGNER_MODE_SIDE,
                                         VFX_FRAME_ALIGNER_MODE_SIDE);
    }


}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//DCM
#pragma arm section code, rodata

#endif
