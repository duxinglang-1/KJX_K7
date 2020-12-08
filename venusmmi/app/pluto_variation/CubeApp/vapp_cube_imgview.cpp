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
 *  vapp_cube_imgview.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cube Image View Screen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#if defined(__MMI_VUI_3D_CUBE_APP_IMGVIEW__)

#include "MMIDataType.h"
#include "vrt_datatype.h"
#include "trc\vadp_app_trc.h"
#include "vfx_uc_include.h"
#include "vcp_frame_effect.h"
#include "ui_core\mvc\vfx_primitive_frame.h"
#include "ui_core\mvc\vfx_animation.h"
#include "vcp_marquee.h"

#include "gdi_datatype.h"

#ifdef __cplusplus
extern "C"
#endif
{
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "custom_events_notify.h"
#include "MediaCacheSrvGprot.h"
#ifdef __cplusplus
}
#endif

#include "vapp_cube_scr.h"
#include "vcp_base_menu.h"
#include "vapp_cube_imgview_config.h"
#include "vapp_cube_imgview.h"
#include "Vapp_cube_res.h"
#include "MediaPlayerResDef.h"
#include "CubeApp\vadp_cube_imgview.h"

#include "CubeAppGprot.h"

#ifdef MMI_CUBE_LITE
#define __VUI_CUBE_DISABLE_EFFECT__ 
#endif

/***************************************************************************** 
 * Function Definition
 *****************************************************************************/
mmi_vapp_cube_imgview_cntx_struct g_vapp_cube_imgview_cntx = {
    0,
    2,
    MMI_VAPP_CUBE_IMGVIEW_STATE_INITED_UNKNOWN,
	VFX_FALSE,
	MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION
};

mmi_vapp_cube_imgview_app_mode_enum VappCubeImgViewScr::m_appState = MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION;

VFX_IMPLEMENT_CLASS(MMI_VAPP_CUBE_IMGVIEW_SCR_CLASS_NAME, VappCubeImgViewScr, VappCubeScr);

VappCubeImgViewScr::VappCubeImgViewScr()
{
    m_rectAvailRegion = VRT_FRAME_DEFAULT_BOUNDS;
    m_cellCount = 0;
    m_loading = NULL;
    m_effectFront = NULL;
    m_effectBack = NULL;
    m_currCell = NULL;
    m_appState = MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION;

    m_navigationModeMenu = NULL;
    m_navigationModeBg = NULL;
    m_text = NULL;
    
    m_viewModeFrame = NULL;
    m_viewModeMenu = NULL;
    m_viewModeBg = NULL;
    m_button = NULL;
    m_prevArrow = NULL;
    m_nextArrow = NULL;
    m_upArrowTimeLine = NULL;
    m_downArrowTimeLine = NULL;
    m_opacityFrame = NULL;
	m_loadingCount = 0;
	m_timer = NULL;
    m_timerViewModeUpdate = NULL;
}

VfxS32 VappCubeImgViewScr::createFileList(VfxS32 *cellCount)
{
	VfxS32 fileList;
	VfxS32 result;

	fileList = vadp_cube_imgview_get_file_list();
	if (fileList)
	{
		*cellCount = vadp_cube_imgview_get_file_list_count();
        if (*cellCount >= FS_NO_ERROR)
        {
            result = MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_SUCCESS;
        }
        else
        {
            result = MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_FAIL;
        }
	}
	else
	{
        g_vapp_cube_imgview_cntx.focusIndex = 0;
		result = vadp_cube_imgview_create_file_list(
			(void*)this,
			NULL, 
			VADP_CUBE_IMGVIEW_FILTER_TPYE_IMAGE, 
			VADP_CUBE_IMGVIEW_SORT_TYPE_BY_TIME,
			VappCubeImgViewScr::onSortOver);
		
		if (result >= FS_NO_ERROR)
		{
			*cellCount = 0;
                        result = MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_LOADING;
		}
		else
		{
			*cellCount = 0;
            result = MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_FAIL;
		}
	}

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_CREATE_FILE_LIST, result, *cellCount);

	return result;
}

void VappCubeImgViewScr::onInit()
{
    VappCubeScr::onInit();

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ONINIT);

    VfxS32 string_id = vadp_cube_imgview_get_forbid_item_info();

    if (!string_id)
    {   
        VfxS32 cellCount;
        m_rectAvailRegion = getAppBounds();

        VFX_OBJ_CREATE(m_navigationModeBg, VfxImageFrame, this);
        m_navigationModeBg->setPos(VfxPoint(0, 0));
        m_navigationModeBg->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
        m_navigationModeBg->setResId(VAPP_CUBE_IMG_IMGVIEW_NAVIGATION_BG);
        m_navigationModeBg->setIsOpaque(VFX_TRUE);
        m_navigationModeBg->setIsCached(VFX_TRUE);
        
        //VFX_OBJ_CREATE(m_imageFrameBack, VfxImageFrame, this);
        VFX_OBJ_CREATE(m_effectFront, VcpFrameEffect, this);
        VFX_OBJ_CREATE(m_effectBack, VcpFrameEffect, this);
        
        VfxS32 result = 0;
        
        result = createFileList(&cellCount);
        if ((result == MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_SUCCESS) && (cellCount > 0))
        {
            vadp_cube_imgview_set_l2_image_info(MMI_VAPP_CUBE_IMGVIEW_CELL_WIDTH * 16 /9, MMI_VAPP_CUBE_IMGVIEW_CELL_HEIGHT * 16 / 9);
            vadp_cube_imgview_create_cache();
            g_vapp_cube_imgview_cntx.is_give_up_sort_result = VFX_TRUE;
        }
		else
		{
			g_vapp_cube_imgview_cntx.is_give_up_sort_result = VFX_FALSE;
		}
        
        VFX_OBJ_CREATE(m_navigationModeMenu, VappCubeImgviewMenu, this);
        m_navigationModeMenu->setCellWidth(MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH);
        m_navigationModeMenu->setCellHeight(MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT);
        m_navigationModeMenu->setCellCount(cellCount);
        m_navigationModeMenu->setRect(m_rectAvailRegion);
        m_navigationModeMenu->m_eventTapCell.connect(this, &VappCubeImgViewScr::onEventTapCell);
        m_navigationModeMenu->setCacheNumber(1);
        m_navigationModeMenu->setIsOpaque(VFX_TRUE);
        
        VFX_OBJ_CREATE(m_loadingContainer, VfxFrame, this);
        m_loadingContainer->setPos(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_X, MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_Y));
        m_loadingContainer->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_HEIGHT));

        VFX_OBJ_CREATE(m_loadingBg, VfxImageFrame, m_loadingContainer);
        m_loadingBg->setPos(VfxPoint(0, 0));
        m_loadingBg->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_BG);
        m_loadingBg->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_HEIGHT));
        m_loadingBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        
        VfxS32 icon_width, icon_height;
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOADING_0, &icon_width, &icon_height);
        VFX_OBJ_CREATE(m_loading, VfxImageFrame, m_loadingContainer);
        m_loading->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_WIDTH - icon_width)>>1, MMI_VAPP_CUBE_IMGVIEW_LOADING_OFFSET_Y));
        m_loading->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_0);
        
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(MMI_VAPP_CUBE_IMGVIEW_LOADING_INTERVAL);
        m_timer->setDuration(MMI_VAPP_CUBE_IMGVIEW_LOADING_INTERVAL);
        m_timer->m_signalTick.connect(this, &VappCubeImgViewScr::onLoadingTimerExpir);
        
        VFX_OBJ_CREATE(m_timerViewModeUpdate, VfxTimer, this);
        m_timerViewModeUpdate->setStartDelay(VRT_TIMELINE_DEFAULT_DUR_TIME);
        m_timerViewModeUpdate->setDuration(VRT_TIMELINE_DEFAULT_DUR_TIME);
        m_timerViewModeUpdate->m_signalTick.connect(this, &VappCubeImgViewScr::onViewModeUpdate);
        
        VfxU16 image;
        image = VAPP_CUBE_IMG_IMGVIEW_POPUP_FAILURE;
        VFX_OBJ_CREATE(m_popupIcon, VfxImageFrame, m_loadingContainer);
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_POPUP_FAILURE, &icon_width, &icon_height);
        m_popupIcon->setResId(image);
        m_popupIcon->setHidden(VFX_FALSE);
        m_popupIcon->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH - icon_width)>>1, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_Y));
        m_popupIcon->setBounds(VfxRect(0, 0, icon_width, icon_height));
        m_popupIcon->setHidden(VFX_TRUE);

        VFX_OBJ_CREATE(m_text, VcpMarquee, m_loadingContainer);

        m_text->setPos(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_TEXT_OFFSET_X, MMI_VAPP_CUBE_IMGVIEW_TEXT_OFFSET_Y));
        m_text->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_TEXT_WIDTH, MMI_VAPP_CUBE_IMGVIEW_TEXT_HEIGHT));
        m_text->setHalign(VcpMarquee::HALIGN_CENTER);
        m_text->setValign(VcpMarquee::VALIGN_CENTER);
        m_text->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
        m_text->setStartDelay(VcpMarquee::DEFAULT_START_DELAY);
        m_text->setMovableFrame(VFX_WSTR_RES(string_id), VCP_MARQUEE_DEFAULT_FONT);
        m_text->startScroll();
        
        VFX_OBJ_CREATE(m_viewModeFrame, VfxImageFrame, this);
        m_viewModeFrame->setHidden(VFX_TRUE);
        //m_viewModeFrame->setRect(m_rectAvailRegion);
        m_viewModeFrame->setRect(VfxRect(0,0,LCD_WIDTH, LCD_HEIGHT));
        m_viewModeFrame->setIsOpaque(VFX_TRUE);
        
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        
        VFX_OBJ_CREATE(m_viewModeBg, VfxImageFrame, m_viewModeFrame);
        m_viewModeBg->setPos(VfxPoint(0, 0));
        m_viewModeBg->setBgColor(VFX_COLOR_BLACK);
        m_viewModeBg->setResId(VAPP_CUBE_IMG_IMGVIEW_VIEW_MODE_BG);
        m_viewModeBg->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
        m_viewModeBg->setIsOpaque(VFX_TRUE);
        //m_viewModeBg->setIsCached(VFX_TRUE);
        
        VFX_OBJ_CREATE(m_prevArrow, VfxImageFrame, m_viewModeFrame);
        m_prevArrow->setPos(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_UP_ARROW_OFFSET_X, MMI_VAPP_CUBE_IMGVIEW_UP_ARROW_OFFSET_Y));
        m_prevArrow->setResId(VAPP_CUBE_IMG_IMGVIEW_ARROW_UP);
        m_prevArrow->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_UP_ARROW_WIDTH, MMI_VAPP_CUBE_IMGVIEW_UP_ARROW_HEIGHT));
        m_prevArrow->setHidden(VFX_FALSE);
        
        VFX_OBJ_CREATE(m_nextArrow, VfxImageFrame, m_viewModeFrame);
        m_nextArrow->setPos(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_DOWN_ARROW_OFFSET_X, MMI_VAPP_CUBE_IMGVIEW_DOWN_ARROW_OFFSET_Y));
        m_nextArrow->setResId(VAPP_CUBE_IMG_IMGVIEW_ARROW_DOWN);
        m_nextArrow->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_DOWN_ARROW_WIDTH, MMI_VAPP_CUBE_IMGVIEW_DOWN_ARROW_HEIGHT));
        m_nextArrow->setHidden(VFX_FALSE);
        
        VFX_OBJ_CREATE(m_upArrowTimeLine, VfxFloatTimeline, m_viewModeFrame);
        m_upArrowTimeLine->setFromValue(0);
        m_upArrowTimeLine->setToValue(1.0f);
        m_upArrowTimeLine->setDurationTime(MMI_VAPP_CUBE_IMGVIEW_TIMELINE_DUR);
        m_upArrowTimeLine->setRepeatCount(MMI_VAPP_CUBE_IMGVIEW_TIMELINE_REP_COUNT);
        m_upArrowTimeLine->setAutoReversed(1);
        m_upArrowTimeLine->setTarget(m_prevArrow);
        m_upArrowTimeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_upArrowTimeLine->m_signalStopped.connect(this, &VappCubeImgViewScr::onTimeLineStop);
        
        VFX_OBJ_CREATE(m_downArrowTimeLine, VfxFloatTimeline, m_viewModeFrame);
        m_downArrowTimeLine->setFromValue(0);
        m_downArrowTimeLine->setToValue(1.0f);
        m_downArrowTimeLine->setDurationTime(MMI_VAPP_CUBE_IMGVIEW_TIMELINE_DUR);
        m_downArrowTimeLine->setRepeatCount(MMI_VAPP_CUBE_IMGVIEW_TIMELINE_REP_COUNT);
        m_downArrowTimeLine->setAutoReversed(1);
        m_downArrowTimeLine->setTarget(m_nextArrow);
        m_downArrowTimeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_downArrowTimeLine->m_signalStopped.connect(this, &VappCubeImgViewScr::onTimeLineStop);
        
        VFX_OBJ_CREATE(m_button, VappCubeImgviewButton2, m_viewModeFrame);
        //for hilight is bigger than button, so the button bounds is hilight, when touch I will check the real position
        m_button->setPos(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_X, MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_Y));
        m_button->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_HEIGHT));
        m_button->m_eventPenUp.connect(this, &VappCubeImgViewScr::onEventUpClose);
        //m_button->setHidden(VFX_FALSE);
        
        VFX_OBJ_CREATE(m_viewModeMenu, VappCubeImgviewMenu2, m_viewModeFrame);
        //m_viewModeMenu->setHidden(1);
        m_viewModeMenu->setCellWidth(getAvailRect().getWidth());
        m_viewModeMenu->setCellHeight(getAvailRect().getHeight());
        //m_viewModeMenu->setPos(VfxPoint(0, getAvailRect().getY()));
        //m_viewModeMenu->setBounds(VfxRect(0, 0, getAvailRect().getWidth(), getAvailRect().getHeight()));
        //m_viewModeMenu->setViewRect(VfxRect(0, 0, getAvailRect().getWidth(), getAvailRect().getHeight()));
        m_viewModeMenu->setRect(m_rectAvailRegion);
        m_viewModeMenu->setCellCount(cellCount);
        m_viewModeMenu->m_eventTapCell.connect(this, &VappCubeImgViewScr::onViewModeEventTapCell);
        m_viewModeMenu->setIsOpaque(VFX_TRUE);
        m_viewModeMenu->setCacheNumber(1);
        m_viewModeMenu->m_viewModeFocusChange.connect(m_navigationModeMenu, &VappCubeImgviewMenu::onFocusChange);
        
        if (result == MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_SUCCESS)
        {
            if (!cellCount)
            {
                m_loadingContainer->setHidden(VFX_FALSE);
                m_loading->setHidden(VFX_TRUE);
                m_text->setMovableFrame(VFX_WSTR_RES(STR_GLOBAL_EMPTY), VCP_MARQUEE_DEFAULT_FONT);
                m_navigationModeMenu->getLayout()->setFocusItem(VcpMenuPos(0, g_vapp_cube_imgview_cntx.focusIndex));
                m_navigationModeMenu->setHidden(VFX_TRUE);

                VfxU16 image;
                VfxS32 icon_width, icon_height;
                image = VAPP_CUBE_IMG_IMGVIEW_POPUP_INFO;
                VFX_OBJ_CREATE(m_popupIcon, VfxImageFrame, m_loadingContainer);
                gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_POPUP_INFO, &icon_width, &icon_height);
                m_popupIcon->setResId(image);
                m_popupIcon->setHidden(VFX_FALSE);
                m_popupIcon->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH - icon_width)>>1, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_Y));
                m_popupIcon->setBounds(VfxRect(0, 0, icon_width, icon_height));
                m_popupIcon->setHidden(VFX_FALSE);
                
                m_text->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH - MMI_VAPP_CUBE_IMGVIEW_TEXT_WIDTH)>>1, 
                    MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_Y + icon_height + MMI_VAPP_CUBE_IMGVIEW_LOADING_ICON_STRING_GAP));
                
                m_loadingContainer->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_HEIGHT));
                m_loadingBg->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_HEIGHT));
            }
            else
            {
                m_navigationModeMenu->getLayout()->setFocusItem(VcpMenuPos(0, g_vapp_cube_imgview_cntx.focusIndex));
				m_viewModeMenu->getLayout()->setFocusItem(VcpMenuPos(0, g_vapp_cube_imgview_cntx.focusIndex));
                m_text->setMovableFrame(VFX_WSTR_RES(STR_GLOBAL_DONE), VCP_MARQUEE_DEFAULT_FONT);
                m_loadingContainer->setHidden(VFX_TRUE);

				if (g_vapp_cube_imgview_cntx.mode == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION)
				{
					m_navigationModeMenu->setHidden(VFX_FALSE);
					m_viewModeFrame->setHidden(VFX_TRUE);
					setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION);
				}
				else
				{
					m_navigationModeMenu->setHidden(VFX_TRUE);
					m_viewModeFrame->setHidden(VFX_FALSE);
					m_button->bringToFront();
					setArrowHidden(VFX_TRUE);
					startViewModeUpdateTimer();
					setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW);
				}
            }
        }
        else if (result == MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_LOADING)
        {
            m_text->setMovableFrame(VFX_WSTR_RES(STR_GLOBAL_LOADING), VCP_MARQUEE_DEFAULT_FONT);
            m_timer->start();
        }
        else
        {	
            m_text->setMovableFrame(VFX_WSTR_RES(STR_GLOBAL_ERROR), VCP_MARQUEE_DEFAULT_FONT);
            m_loadingContainer->setHidden(VFX_FALSE);
        }
        
        g_vapp_cube_imgview_cntx.state = MMI_VAPP_CUBE_IMGVIEW_STATE_INITED;
    }
    else
    {
        m_rectAvailRegion = getAppBounds();
        
        g_vapp_cube_imgview_cntx.state = MMI_VAPP_CUBE_IMGVIEW_STATE_INITED;

        VFX_OBJ_CREATE(m_navigationModeBg, VfxImageFrame, this);
        m_navigationModeBg->setPos(VfxPoint(0, 0));
        m_navigationModeBg->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
        m_navigationModeBg->setResId(VAPP_CUBE_IMG_IMGVIEW_NAVIGATION_BG);
        m_navigationModeBg->setIsOpaque(VFX_TRUE);
        m_navigationModeBg->setIsCached(VFX_TRUE);

        VFX_OBJ_CREATE(m_loadingContainer, VfxFrame, this);
        m_loadingContainer->setPos(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_X, MMI_VAPP_CUBE_IMGVIEW_LOADING_BG_OFFSET_Y));
        m_loadingContainer->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_HEIGHT));
        
        VFX_OBJ_CREATE(m_loadingBg, VfxImageFrame, m_loadingContainer);
        m_loadingBg->setPos(VfxPoint(0, 0));
        m_loadingBg->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_BG);
        m_loadingBg->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_HEIGHT));
        m_loadingBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        VfxU16 image;
        VfxS32 icon_width, icon_height;
        image = VAPP_CUBE_IMG_IMGVIEW_POPUP_FAILURE;
        VFX_OBJ_CREATE(m_popupIcon, VfxImageFrame, m_loadingContainer);
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_POPUP_FAILURE, &icon_width, &icon_height);
        m_popupIcon->setResId(image);
        m_popupIcon->setHidden(VFX_FALSE);
        m_popupIcon->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH - icon_width)>>1, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_Y));
        m_popupIcon->setBounds(VfxRect(0, 0, icon_width, icon_height));
        
        VFX_OBJ_CREATE(m_text, VcpMarquee, m_loadingContainer);
        m_text->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH - MMI_VAPP_CUBE_IMGVIEW_TEXT_WIDTH)>>1, 
            MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_Y + icon_height + MMI_VAPP_CUBE_IMGVIEW_LOADING_ICON_STRING_GAP));
        m_text->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_TEXT_WIDTH, MMI_VAPP_CUBE_IMGVIEW_TEXT_HEIGHT));
        m_text->setHalign(VcpMarquee::HALIGN_CENTER);
        m_text->setValign(VcpMarquee::VALIGN_CENTER);
        m_text->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
        m_text->setStartDelay(VcpMarquee::DEFAULT_START_DELAY);
        m_text->setMovableFrame(VFX_WSTR_RES(string_id), VCP_MARQUEE_DEFAULT_FONT);
        m_text->startScroll();
    }
}

void VappCubeImgViewScr::onDeinit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ONDEINIT);

    g_vapp_cube_imgview_cntx.is_give_up_sort_result = VFX_TRUE;

	g_vapp_cube_imgview_cntx.mode = getAppState();;

    if (g_vapp_cube_imgview_cntx.mode == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION)
    {
        if (m_navigationModeMenu)
        {
            g_vapp_cube_imgview_cntx.focusIndex = m_navigationModeMenu->getLayout()->getFocusItem().pos;
        }
    }
    else if(g_vapp_cube_imgview_cntx.mode == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW)
    {
        if (m_viewModeMenu)
        {
            g_vapp_cube_imgview_cntx.focusIndex = m_viewModeMenu->getLayout()->getFocusItem().pos;
        }
    }

    g_vapp_cube_imgview_cntx.state = MMI_VAPP_CUBE_IMGVIEW_STATE_DEINITED;

    VappCubeScr::onDeinit();

    vadp_cube_imgview_close_cache();
}

VfxBool VappCubeImgViewScr::onPenInput(VfxPenEvent &event)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_PENINPUT);
    
    VFX_UNUSED(event);
	
    return VappCubeScr::onPenInput(event);
}


void VappCubeImgViewScr::onSortOver(void* user_data, VfxS32 count, VfxS32 sort_state)
{    
	if (g_vapp_cube_imgview_cntx.is_give_up_sort_result == VFX_TRUE)
	{
		return;
	}

    if (g_vapp_cube_imgview_cntx.state == MMI_VAPP_CUBE_IMGVIEW_STATE_INITED)
    {
        VappCubeImgViewScr* my_data = VFX_OBJ_DYNAMIC_CAST((VfxObject*)user_data, VappCubeImgViewScr);
        
        VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_SORTOVER, my_data, count, sort_state);

        if(my_data)
        {   
#if 1
			my_data->m_timer->stop();
#endif
            if (count != 0)
            {
                my_data->m_navigationModeMenu->setCellWidth(MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH);
                my_data->m_navigationModeMenu->setCellHeight(MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT);
                my_data->m_navigationModeMenu->setCellCount(count);
                //my_data->m_navigationModeMenu->setPos(VfxPoint(m_rectAvailRegion.getX(), m_rectAvailRegion.getY()));
                //my_data->m_navigationModeMenu->setBounds(VfxRect(0, 0, m_rectAvailRegion.getWidth(), m_rectAvailRegion.getHeight()));
                my_data->m_navigationModeMenu->setRect(my_data->m_rectAvailRegion);
                //m_navigationModeMenu->setViewRect(m_rectAvailRegion);
                my_data->m_navigationModeMenu->m_eventTapCell.connect(my_data, &VappCubeImgViewScr::onEventTapCell);
                my_data->m_navigationModeMenu->setCacheNumber(1);
                my_data->m_navigationModeMenu->setIsOpaque(VFX_TRUE);
                my_data->m_navigationModeMenu->getLayout()->setFocusItem(VcpMenuPos(0, g_vapp_cube_imgview_cntx.focusIndex));
                
                my_data->m_navigationModeMenu->setHidden(VFX_FALSE);
                my_data->m_navigationModeMenu->setCellCount(count);
                
                my_data->m_viewModeMenu->setCellCount(count);
                my_data->m_viewModeMenu->getLayout()->setFocusItem(VcpMenuPos(0, g_vapp_cube_imgview_cntx.focusIndex));
                my_data->m_loadingContainer->setHidden(VFX_TRUE);

                
                /* config db and start it */
                vadp_cube_imgview_set_l2_image_info(MMI_VAPP_CUBE_IMGVIEW_CELL_WIDTH * 16 /9, MMI_VAPP_CUBE_IMGVIEW_CELL_HEIGHT * 16 / 9);
                vadp_cube_imgview_create_cache();
                
				if (g_vapp_cube_imgview_cntx.mode == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION)
				{
					my_data->m_navigationModeMenu->setHidden(VFX_FALSE);
					my_data->m_viewModeFrame->setHidden(VFX_TRUE);
					setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION);
				}
				else
				{
					my_data->m_navigationModeMenu->setHidden(VFX_TRUE);
					my_data->m_viewModeFrame->setHidden(VFX_FALSE);
					my_data->m_button->bringToFront();
					my_data->setArrowHidden(VFX_TRUE);
					my_data->startViewModeUpdateTimer();
					setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW);
				}
            }
            else
            {
                my_data->m_loading->setHidden(VFX_TRUE);
                my_data->m_text->setMovableFrame(VFX_WSTR_RES(STR_GLOBAL_EMPTY), VCP_MARQUEE_DEFAULT_FONT);
                
                VfxU16 image;
                VfxS32 icon_width, icon_height;
                image = VAPP_CUBE_IMG_IMGVIEW_POPUP_INFO;
                VFX_OBJ_CREATE(my_data->m_popupIcon, VfxImageFrame, my_data->m_loadingContainer);
                gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_POPUP_INFO, &icon_width, &icon_height);
                my_data->m_popupIcon->setResId(image);
                my_data->m_popupIcon->setHidden(VFX_FALSE);
                my_data->m_popupIcon->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH - icon_width)>>1, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_Y));
                my_data->m_popupIcon->setBounds(VfxRect(0, 0, icon_width, icon_height));
                my_data->m_popupIcon->setHidden(VFX_FALSE);

                my_data->m_text->setPos(VfxPoint((MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH - MMI_VAPP_CUBE_IMGVIEW_TEXT_WIDTH)>>1, 
                    MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_Y + icon_height + MMI_VAPP_CUBE_IMGVIEW_LOADING_ICON_STRING_GAP));

                my_data->m_loadingContainer->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_HEIGHT));
                my_data->m_loadingBg->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_ERROR_OFFSET_HEIGHT));
            }
        }
    }
}

void VappCubeImgViewScr::onDecodeOver(void* user_data, VfxS32 index, void *memory_addr, S32 state, S32 mode)
{
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
#endif
}

void VappCubeImgViewScr::onEventTapCell(VfxS32 index, VfxFrame* cell)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_EVENT_TAP_CELL, index);

    m_viewModeFrame->bringToFront();
    m_viewModeFrame->setHidden(VFX_FALSE);
    setArrowHidden(VFX_FALSE);

    setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_TURN_TO_BACK);
    m_navigationModeMenu->setSkipUpdate(VFX_TRUE);
    ////TODO will not receive any event in navigation menu
    VcpMenuPos pos;
    pos.group = 0;
    pos.pos = index;
    //m_viewModeMenu->setFocusItem(pos, VFX_FALSE);
    //m_viewModeMenu->getLayout()->update();
    g_vapp_cube_imgview_cntx.currCellPos = index;
    m_viewModeMenu->setEffectFinished(VFX_FALSE);
    m_currCell = cell;

    
    //vadp_cube_imgview_pause_cache();
    
    //m_navigationModeMenu->backUpCellBuffer();
    //m_navigationModeMenu->closeAllImage();
    m_navigationModeMenu->m_timer->stop();

    //vadp_cube_imgview_set_l2_image_info(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH, MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT);
    //vadp_cube_imgview_change_to_view_mode(index);

#ifndef __VUI_CUBE_DISABLE_EFFECT__
    m_viewModeMenu->setFocusItem(pos, VFX_TRUE);

    m_effectBack->applyEffect(m_viewModeFrame, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT);
    m_effectFront->applyEffect(m_currCell, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_TRUE);
    m_effectBack->m_signalFinished.connect(this, &VappCubeImgViewScr::onBackEffectFinished);  

#else
    m_viewModeMenu->setFocusItem(pos, VFX_FALSE);
    VappCubeImgviewMenuLayout *my_layout = (VappCubeImgviewMenuLayout *)m_viewModeMenu->getLayout();
    my_layout->disableAnimation();

    onBackEffectFinished(m_viewModeFrame, VFX_TRUE);
#endif
}

#if 1
void VappCubeImgViewScr::onLoadingTimerExpir(VfxTimer *timer)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_LOADING_TIMER_ARRIVE, m_loadingCount);
        
	m_loadingCount = (m_loadingCount + 1) % MMI_VAPP_CUBE_IMGVIEW_LOADING_COUNT_ALL;
	m_loading->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_0 + m_loadingCount);

	timer->start();
}

void VappCubeImgViewScr::onViewModeUpdate(VfxTimer *timer)
{
    timer->stop();
    m_viewModeMenu->heavyUpdate();
}
#endif

void VappCubeImgViewScr::onBackEffectFinished(VfxFrame *frame, VfxBool isComplete)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_BACK_EFFECT_FINISH, isComplete);

    VcpMenuPos pos;
    pos.group = 0;
    pos.pos = g_vapp_cube_imgview_cntx.currCellPos;

    setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW);

    //vadp_cube_imgview_set_l2_image_info(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH, MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT);
    //vadp_cube_imgview_change_to_view_mode(g_vapp_cube_imgview_cntx.currCellPos);
    //vadp_cube_imgview_register_clip_callback(clipCallback, NULL);

    VappCubeImgviewCell2* cell = (VappCubeImgviewCell2*)(m_viewModeMenu->getCellIfPresent(0, g_vapp_cube_imgview_cntx.currCellPos));
    if (cell)
    {
        cell->invalidate();
    }

    //m_viewModeFrame->setArrowHidden(VFX_TRUE);
    m_navigationModeMenu->setHidden(VFX_TRUE);
    m_navigationModeMenu->setIsCached(VFX_FALSE);

    //vadp_cube_imgview_resume_cache();

    m_viewModeMenu->heavyUpdate();

    m_viewModeBg->setIsCached(VFX_TRUE);
    m_viewModeMenu->setEffectFinished(VFX_TRUE);
    startTimeLine();
    m_effectBack->m_signalFinished.disconnect(this, &VappCubeImgViewScr::onBackEffectFinished);
    m_button->bringToFront();
}

void VappCubeImgViewScr::onFrontEffectFinished(VfxFrame *frame, VfxBool isComplete)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_FRONT_EFFECT_FINISH, isComplete);
        
    setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION);

    vadp_cube_imgview_resume_cache();

    m_viewModeFrame->setHidden(VFX_TRUE);
    //m_viewModeMenu->closeAllImage();
    m_viewModeBg->setIsCached(VFX_FALSE);

    m_navigationModeBg->setIsCached(VFX_TRUE);

    m_effectFront->m_signalFinished.disconnect(this, &VappCubeImgViewScr::onFrontEffectFinished);
    m_effectBack->m_signalFinished.disconnect(this, &VappCubeImgViewScr::onFrontEffectFinished);

    //vadp_cube_imgview_set_l2_image_info(MMI_VAPP_CUBE_IMGVIEW_CELL_WIDTH, MMI_VAPP_CUBE_IMGVIEW_CELL_HEIGHT);
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *)m_viewModeMenu->getLayout();
    //vadp_cube_imgview_change_to_navigation_mode(layout->getFocusItem().pos);
    //vadp_cube_imgview_register_clip_callback(clipCallback, NULL);
#if 0////TODO
/* under construction !*/
#endif

    m_navigationModeMenu->setSkipUpdate(VFX_FALSE);    
    m_navigationModeMenu->heavyUpdate();
}

void VappCubeImgViewScr::onEventUpClose(VfxPenEvent &event)
{
    if (VappCubeImgViewScr::getAppState() == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW)
    {
        if (m_button->containPoint(event.getRelPos(m_button)))
        {
            VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_EVENT_BUTTON_UP, 1);
            
            setAppState(MMI_VAPP_CUBE_IMGVIEW_APP_MODE_TURN_TO_FRONT);
            
            //m_navigationModeMenu->setSkipUpdate(VFX_FALSE);
            m_navigationModeMenu->setHidden(VFX_FALSE);
            
            //m_viewModeFrame->setHidden(VFX_FALSE);
            
            
            VfxRect r = m_viewModeMenu->getViewRect();
            VfxS32 index = m_viewModeMenu->getFocusIndexByRect(r);
            
            VappCubeImgviewCell *cell;
            cell = (VappCubeImgviewCell *)m_navigationModeMenu->getCellIfPresent(0, index);
            
            stopViewModeUpdateTimer();

            vadp_cube_imgview_pause_cache();
            
#ifndef __VUI_CUBE_DISABLE_EFFECT__
            m_effectBack->applyEffect(m_viewModeFrame, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_TRUE);
            if (cell)
            {
                m_effectFront->applyEffect(cell, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT);
                m_effectFront->m_signalFinished.connect(this, &VappCubeImgViewScr::onFrontEffectFinished);
            }
            else
            {
                m_effectFront->restore();
                m_effectBack->m_signalFinished.connect(this, &VappCubeImgViewScr::onFrontEffectFinished);
            }
#else
            onFrontEffectFinished(cell, VFX_TRUE);
#endif
            
        }
        else
        {
            VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_EVENT_BUTTON_UP, 0);
        }
    }
}

void VappCubeImgViewScr::onTimerDrag(VfxTimer *timer)
{
    VfxRect r = m_viewModeMenu->getViewRect();
    VfxS32 index = m_viewModeMenu->getFocusIndexByRect(r);

    VappCubeImgviewCell *cell;
    cell = (VappCubeImgviewCell *)m_navigationModeMenu->getCellIfPresent(0, index);

    m_effectBack->applyEffect(cell, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT);
    m_effectFront->applyEffect(m_viewModeFrame, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT, VFX_TRUE);
    m_effectFront->m_signalFinished.connect(this, &VappCubeImgViewScr::onFrontEffectFinished);
}

VfxRect VappCubeImgViewScr::getAvailRect()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_GET_AVAILABLE_RECT, m_rectAvailRegion.origin.x, m_rectAvailRegion.origin.y, m_rectAvailRegion.size.width, m_rectAvailRegion.size.height);
    return m_rectAvailRegion;
}

void VappCubeImgViewScr::startTimeLine()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_START_TIMELINE);
    m_upArrowTimeLine->start();
    m_downArrowTimeLine->start();
}

void VappCubeImgViewScr::stopTimeLine()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_STOP_TIMELINE);
    m_upArrowTimeLine->stop();
    m_downArrowTimeLine->stop();
}

void VappCubeImgViewScr::onTimeLineStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_ON_TIMELINE_STOP);
    setArrowHidden(VFX_TRUE);
}

void VappCubeImgViewScr::setArrowHidden(VfxBool hidden)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_SET_ARROW_HIDDEN);

    m_prevArrow->setHidden(hidden);
    m_nextArrow->setHidden(hidden);
    if (hidden)
    {
        m_prevArrow->setOpacity(0);
        m_nextArrow->setOpacity(0);
    }
    else
    {
        m_prevArrow->setOpacity(1.0f);
        m_nextArrow->setOpacity(1.0f);
    }
}

mmi_vapp_cube_imgview_app_mode_enum VappCubeImgViewScr::getAppState()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_GET_APP_STATE, m_appState);
    return m_appState;
}

void VappCubeImgViewScr::setAppState(mmi_vapp_cube_imgview_app_mode_enum state)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_SET_APP_STATE, state);
    m_appState = state;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif
/* under construction !*/
/* under construction !*/
#endif

void VappCubeImgViewScr::onViewModeEventTapCell(VfxS32 index, VfxFrame* cell)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_VIEW_MODE_TAP_CELL, index);
    
    stopTimeLine();
    setArrowHidden(VFX_TRUE);
}

void VappCubeImgViewScr::getTargetWidthHeight(S32 index, S32 mode, PS32 width, PS32 height)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_SCR_GET_TARGET_WIDTH_HEIGHT, index, mode );

    if (mode == VADP_CUBE_IMGVIEW_MODE_NAVIGATION)
    {
        m_navigationModeMenu->getCellWidthHeight(index, width, height);
    }
    else
    {
        m_viewModeMenu->getCellWidthHeight(index, width, height);
    }
}

void VappCubeImgViewScr::startViewModeUpdateTimer()
{
    m_timerViewModeUpdate->start();
}

void VappCubeImgViewScr::stopViewModeUpdateTimer()
{
    m_timerViewModeUpdate->stop();
}


// navigation mode menu related
VFX_IMPLEMENT_CLASS(MMI_VAPP_CUBE_IMGVIEW_MENU_CLASS_NAME, VappCubeImgviewMenu, VcpBaseMenu);

VappCubeImgviewMenu::VappCubeImgviewMenu()
{
    m_skipUpdate = VFX_FALSE;
    m_cancelFreeMode = VFX_FALSE;
}

void VappCubeImgviewMenu::onInit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ONINIT);

    VcpBaseMenu::onInit();   

    enableVerticalScrollIndicator(VFX_TRUE);
    m_state = Opening;

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_timer->setDuration(VFX_TIMELINE_DEFAULT_DUR_TIME);
    m_timer->m_signalTick.connect(this, &VappCubeImgviewMenu::onTimerTick);
}

void VappCubeImgviewMenu::onDeinit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ONDEINIT);
    
    VcpBaseMenu::onDeinit();
}

VcpBaseMenuLayout* VappCubeImgviewMenu::createLayout()
{   
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_CREATE_LAYOUT);
    
    VappCubeImgviewMenuLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VappCubeImgviewMenuLayout, this, (this));
    
    return layout;
}

VfxFrame* VappCubeImgviewMenu::createCell(VfxS32 group, VfxS32 pos )
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_CREATE_CELL, group, pos);

    VappCubeImgviewCell* cell;
    VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout*)m_layout;
    VcpMenuPos p;
    p.group = group;
    p.pos = pos;

    VFX_OBJ_CREATE_EX(cell, VappCubeImgviewCell, this, (this->m_layout));
    cell->setContentIndex(pos);

    VfxRect r = layout->queryCellRect(p);
    //cell->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH, MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT));
    cell->setPos(VfxPoint(r.getX(), r.getY()));
    cell->setIsOpaque(VFX_TRUE);
    cell->setIsCached(VFX_TRUE);

    //cell->setPos(VfxPoint(r.getMidX(), r.getMidY()));

#if 1
    VfxRect r_bg = layout->queryCellRect(p);
    cell->setBgPos(VfxPoint(0, 0));
    //cell->setBgBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH, MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT));

    VfxRect r_content = layout->queryCellContentRectByPos(p);
    
    cell->setContentPos(VfxPoint(r_content.getX() - cell->getPos().x, r_content.getY() - cell->getPos().y));
    cell->setContentBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_CELL_WIDTH, MMI_VAPP_CUBE_IMGVIEW_CELL_HEIGHT));
#endif

    return cell;
}

void VappCubeImgviewMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_CLOSE_CELL, group, pos);

     VappCubeImgviewCell *cell = (VappCubeImgviewCell*)cellFrame;
    
    cell->closeImage();
    VFX_OBJ_CLOSE(cellFrame);
}

void VappCubeImgviewMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag )
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_UPDATE_CELL, pos, flag, getSkipUpdate());

    VappCubeImgviewCell* item = (VappCubeImgviewCell*) cell;
    VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *)m_layout;
    
    //item->updateCellImage(group, pos);
    if (flag & VCP_CELL_FLAG_FIRSTINIT)
   	{
        item->addDisplayRights();

        if (flag & VCP_CELL_FLAG_OPENING)
       	{
            item->updateCellImage(group, pos);
            item->enter(rect, VFX_TRUE);
       	}
        else
        {
            item->updateCellImage(group, pos);
            item->enter(rect, VFX_FALSE);
        }
   	}
    else if (flag & VCP_CELL_FLAG_CLOSING)
   	{
        item->leave(rect);
   	}
    else
    {
        item->updateCellImage(group, pos);
        item->updatePos(rect, VFX_FALSE);
    }
}


void VappCubeImgviewMenu::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_TAP_CELL, group, pos);
        
    VappCubeImgviewCell* item = (VappCubeImgviewCell*) cell;
    
    m_layout->setFocusItem(VcpMenuPos(group, pos));

    m_eventTapCell.emit(pos, cell);
}

VfxBool VappCubeImgviewMenu::onKeyInput(VfxKeyEvent &event)
{
    if (VappCubeImgViewScr::getAppState() == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION)
    {
        if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
        {
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *)m_layout;
                
                VcpMenuPos focus = m_layout->getFocusItem();
                /*the focus maybe the last line or the last last line , so need auto change the focus*/
                if ((focus.pos / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT) > (m_layout->getCellCount(0) / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT - (MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_COUNT - 2)))
                {
                    focus.pos -= MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
                }

                if ((focus.pos / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT) > (m_layout->getCellCount(0) / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT - (MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_COUNT - 2)))
                {
                    focus.pos -= MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
                }

                if (focus.pos > MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT)
                {
                    focus.pos -= MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
                }

                if (focus.pos < MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT)
                {
                    focus.pos = MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
                }
                m_layout->setFocusItem(focus, VFX_TRUE);
                
                VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_KEY_INPUT, MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION, event.type, focus.pos);
                
                return VFX_TRUE;
            }
        }
        else if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
        {
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *)m_layout;
                
                VcpMenuPos focus = m_layout->getFocusItem();

                VfxS32 aa = focus.pos / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
                VfxS32 bb = m_layout->getCellCount(0) / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT - (MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_COUNT - 2);
                if ((focus.pos / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT) < 
                    ((m_layout->getCellCount(0) + 1) / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT - 
                     (MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_COUNT - 2) - 1))
                {
                    focus.pos += MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
                }
                m_layout->setFocusItem(focus, VFX_TRUE);
                
                VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_KEY_INPUT, MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION, event.type, focus.pos);
                
                return VFX_TRUE;
            }
        }
    }
    
    return VFX_FALSE;
}


void VappCubeImgviewMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_FOCUS_INDEX_CHANGE);
    //vadp_cube_imgview_focus_change(focusItem.pos);
}

void VappCubeImgviewMenu::onDragStart()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_DRAG_START);
}

void VappCubeImgviewMenu::onDragEnd()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_DRAG_END);
    
    makeVisible(m_layout->getFocusItem());

    if (m_cancelFreeMode == VFX_TRUE)
    {
        VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame();
        scr->regDefaultPageAct(this);
        m_cancelFreeMode = VFX_FALSE;
    }

    heavyUpdate();
}

void VappCubeImgviewMenu::onViewScrollEnd()
{
    vadp_cube_imgview_resume_cache();
}


void VappCubeImgviewMenu::onViewScrollStart()
{
    vadp_cube_imgview_pause_cache();
}


void VappCubeImgviewMenu::decodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code)
{
    VappCubeImgviewMenu* this_ptr = (VappCubeImgviewMenu*) user_data;
    //VfxObjWeakPtr weak_ptr = this_ptr;
    
    if (this_ptr != NULL)
    {
        this_ptr->heavyUpdate(index, error_code);
    }
}

void VappCubeImgviewMenu::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    
    m_timer->stop();
    if (!m_isScrolling)
    {
       heavyUpdate();
    }
}

void VappCubeImgviewMenuLayout::onViewChanged()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_VIEW_CHANGE);
    
	VcpBaseMenuLayout::onViewChanged();
	
    VfxS32 centerY = getViewPos().y + getViewSize().height/2;
    VfxS32 newFocus = getCellPosByPt(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_CELL_START_X, centerY)).pos;
    VfxS32 oldFocus = getFocusItem().pos;
	
    if (newFocus != oldFocus)
    {
        setFocusItem(VcpMenuPos(0,newFocus), VFX_FALSE);
    }
}


void VappCubeImgviewMenuLayout::disableAnimation()
{
    VcpMenuPos pos;
    pos.group = 0;
    pos.pos = g_vapp_cube_imgview_cntx.currCellPos;

    makeVisible(pos, VFX_FALSE);    
}


void VappCubeImgviewMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_DRAG, yoffset, m_cancelFreeMode);
        
    VcpBaseMenu::onDrag(xoffset, yoffset);
    
    if (VFX_ABS(yoffset) > 25)
    {
        if (!m_cancelFreeMode)
        {
            VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame();
            scr->deregDefaultPageAct(this);
            m_cancelFreeMode = VFX_TRUE;
        }
    }    
}
    
void VappCubeImgviewMenu::getCellWidthHeight(S32 index, PS32 width, PS32 height)
{
    VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *)m_layout;

    *width = layout->getCellContentWidth();
    *height = layout->getCellContentHeight();

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_GET_CELL_WIDTH_HEIGHT, *width, *height);
}

void VappCubeImgviewMenu::setCellWidth(VfxS32 value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_SET_CELL_WIDTH, value);

    VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *) m_layout;
    
    if (layout)
    {
        layout->setCellWidth(value);
    }
}

void VappCubeImgviewMenu::setCellHeight(VfxS32 value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_SET_CELL_HEIGHT, value);
        
    VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *) m_layout;
    
    if (layout)
    {
        layout->setCellHeight(value);
    }
}


void VappCubeImgviewMenu::setCellCount(VfxS32 value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_SET_CELL_COUNT, value);
        
    VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *) m_layout;
    
    if (layout)
    {
        layout->setCellCount(value);
    }
}

void VappCubeImgviewMenu::updateMenu()
{
    onUpdate();
}

void VappCubeImgviewMenu::onFocusChange(VfxS32 group, VfxS32 pos)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_ON_FOCUS_CHANGE, group, pos);
        
    VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *)getLayout();
    layout->setFocusItem(VcpMenuPos(group,pos), VFX_TRUE);
}

void VappCubeImgviewMenu::heavyUpdate(VfxS32 index, VfxS32 error_code)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappCubeImgviewCell* cell;
    VcpMenuPos p;
    
    p.group = 0;
    p.pos = index;
    cell = (VappCubeImgviewCell*)getCellIfPresent(p.group, p.pos);
    
    if (cell && (cell->getImageState() != VappCubeImgviewCell::IMAGE_STATE_DISPLAY))
   	{
        if (error_code == SRV_MEDIACACHE_OK)
            cell->updateCellImage(p.group, p.pos);
        else
            cell->setErrorIcon();
    }
    
    heavyUpdate();
}

void VappCubeImgviewMenu::heavyUpdate(void)
{
    if (getSkipUpdate())
    {
        return;
    }

    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappCubeImgviewCell* cell;
    VcpMenuPos p;
    void *buffer_p;
    VfxS32 ret = 0;
    
    while(!itr.isEnd())
    {
        p = itr.next();
        
        cell = (VappCubeImgviewCell*)getCellIfPresent(p.group, p.pos);

        if (cell && (cell->getImageState() != VappCubeImgviewCell::IMAGE_STATE_DISPLAY) &&
            (cell->getImageState() != VappCubeImgviewCell::IMAGE_STATE_ERROR) && 
            (cell->getImageState() != VappCubeImgviewCell::IMAGE_STATE_LOCKING) )
        {
            ret = vadp_cube_imgview_get_lock_image_buffer_nonblocking(
                (void*)this, 
                p.pos, 
                decodeCallBack, 
                &buffer_p);
            
            if (ret == SRV_MEDIACACHE_OK)
            {
                VfxS32 width, height, orig_width, orig_height;

                vadp_cube_imgview_get_image_info(cell->m_index, &orig_width, &orig_height, &width, &height);
                cell->setImageBuffer(buffer_p, width,height);
                m_timer->start();	
            }
#ifdef __DRM_SUPPORT__
            else if (ret == VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING)
            {
                cell->setLockingIcon();
                m_timer->start();
            }
#endif
            else if (ret == SRV_MEDIACACHE_ERR_NOT_SUPPORT)
            {
                cell->setErrorIcon();
                m_timer->start();
            }
            else if (ret == SRV_MEDIACACHE_ERR_DECODING)
            {
                m_timer->stop();
            }
            break; 
       	}			
   	}    
}

void VappCubeImgviewMenu::closeAllImage(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappCubeImgviewCell* cell;
    VcpMenuPos p;
    
    while(!itr.isEnd())
    {
        p = itr.next();
        
        cell = (VappCubeImgviewCell*)getCellIfPresent(p.group, p.pos);
        
        if (cell && (cell->getImageState() == VappCubeImgviewCell::IMAGE_STATE_DISPLAY))
        {
            cell->closeImage();
       	}			
   	}    
}

void VappCubeImgviewMenu::restorAllImage(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappCubeImgviewCell* cell;
    VcpMenuPos p;
    
    while(!itr.isEnd())
    {
        p = itr.next();
        
        cell = (VappCubeImgviewCell*)getCellIfPresent(p.group, p.pos);
        
        if (cell)
        {
            cell->setLoadingIcon();
       	}			
   	}    
}

void VappCubeImgviewMenu::onAfterUpdate(const VcpMenuRegion& currentRegion, const VcpMenuRegion& targetRegion)
{
    //if (!m_isScrolling)
    {
        heavyUpdate();
    }
}

void VappCubeImgviewMenu::setCacheNumber(VfxS32 number)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU1_SET_CACHE_NUMBER, number);
        
	VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *)getLayout();

    m_cacheLen = number * (layout->getCellHeight() + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP) / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
}

//navigation mode menu layout related function
//VFX_IMPLEMENT_CLASS(MMI_VAPP_CUBE_IMGVIEW_MENU_LAYOUT_CLASS_NAME, VappCubeImgviewMenuLayout, VcpBaseMenuLayout);
VappCubeImgviewMenuLayout::VappCubeImgviewMenuLayout(VcpBaseMenu* menu):
VcpBaseMenuLayout(menu)
{
    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    m_CellContentWidth = 0;
    m_cellContentHeight = 0;
}

void VappCubeImgviewMenuLayout::onInit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_ONINIT);
        
    VcpBaseMenuLayout::onInit();

    setCellWidth(MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH);
    setCellHeight(MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT);
    //setCellBgStartPoint(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_START_X, MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_START_Y));
    setCellContentWidth(MMI_VAPP_CUBE_IMGVIEW_CELL_WIDTH);
    setCellContentHeight(MMI_VAPP_CUBE_IMGVIEW_CELL_HEIGHT);
}

void VappCubeImgviewMenuLayout::onDeinit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_ONDEINIT);
    
    //base menu layout do not have onDeinit. so strange
    VcpBaseMenuLayout::onDeinit();
}

VfxS32 VappCubeImgviewMenuLayout::getCellCount(VfxS32 group)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CELL_COUNT, m_cellCount);
    
    return m_cellCount;
}

VfxS32  VappCubeImgviewMenuLayout::getContentLength()
{
    VfxS32 length = MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y + (m_cellCount + 1) / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT * (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP);

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CONTENT_LEN, length);
    
    return  length;
}

VcpMenuRegion VappCubeImgviewMenuLayout::queryRegion(const VfxRect& r )
{
    VcpMenuRegion region = VcpMenuRegion(getCellPosByPt(r.origin), getCellPosByPt(VfxPoint(r.getMaxX(), r.getMaxY())));

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_QUERY_REGION, region.begin.pos, region.end.pos);

    return region;
}

VfxRect VappCubeImgviewMenuLayout::queryCellRect(VcpMenuPos pos)
{
    VfxS32 row, col;
    
    row = pos.pos / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
    col = pos.pos % MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
    
    VfxRect r = VfxRect(
        MMI_VAPP_CUBE_IMGVIEW_CELL_START_X + (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH + MMI_VAPP_CUBE_IMGVIEW_CELL_COL_GAP) * col,
        MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y+ (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP) * row,
        MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH,
        MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT);

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_QUERY_CELL_RECT, pos.pos, r.origin.x, r.origin.y, r.size.width, r.size.height);

    return r;
}


VfxRect VappCubeImgviewMenuLayout::queryCellContentRectByPos(VcpMenuPos pos)
{
    VfxS32 row, col;
    
    row = pos.pos / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
    col = pos.pos % MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT;
    
    VfxRect r = VfxRect(
        MMI_VAPP_CUBE_IMGVIEW_CELL_START_X + (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH + MMI_VAPP_CUBE_IMGVIEW_CELL_COL_GAP) * col + (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH - MMI_VAPP_CUBE_IMGVIEW_CELL_WIDTH) / 2,
        MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y + (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP) * row + (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT - MMI_VAPP_CUBE_IMGVIEW_CELL_HEIGHT) / 2,
        MMI_VAPP_CUBE_IMGVIEW_CELL_WIDTH,
        MMI_VAPP_CUBE_IMGVIEW_CELL_HEIGHT);
    
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_QUEYR_CELL_RECT_BY_POS, pos.pos, r.origin.x, r.origin.y, r.size.width, r.size.height);

    return r;
}


VfxSize VappCubeImgviewMenuLayout::getContentSize()
{
    VfxSize size = VfxSize(MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH * 2 + MMI_VAPP_CUBE_IMGVIEW_CELL_COL_GAP, 
        (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP) * m_cellCount / MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT);

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CONTNET_SIZE, size.width, size.height);
    return size;
}

void VappCubeImgviewMenuLayout::getPreferFocusMargin(VfxS32 margin[4])
{
    VfxRect r = ((VappCubeImgviewMenu *)getParent())->getBounds();
    margin[MARGIN_LEFT] = 0;
   	//margin[MARGIN_UP] = (r.getHeight() - m_cellHeight) / 2;
	margin[MARGIN_UP] = MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y + MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP;
    margin[MARGIN_RIGHT] = 0;
  	//margin[MARGIN_DOWN] = (r.getHeight() - m_cellHeight) / 2; 
	//margin[MARGIN_DOWN] = MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y + MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + 
	//	MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP + MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT; 
	//margin[MARGIN_DOWN] = r.getHeight() - (MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y + MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP) ;
	//margin[MARGIN_DOWN] = MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y + MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP;
    margin[MARGIN_DOWN] = r.getHeight() - margin[MARGIN_UP] - MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT;

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_GET_PREFER_MAGIN, margin[0], margin[1], margin[2], margin[3]);
}

void VappCubeImgviewMenuLayout::setFocusItem(VcpMenuPos focus, VfxBool isMoveToVisible)
{
    VcpBaseMenuLayout:: setFocusItem(focus, isMoveToVisible);

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_SET_FOCUS_ITEM, focus.pos, isMoveToVisible);
}


VcpMenuPos VappCubeImgviewMenuLayout::getCellPosByPt(VfxPoint pt )
{
    VcpMenuPos pos;

    pos.group = 0;

    VfxS32 row = (pt.y - MMI_VAPP_CUBE_IMGVIEW_CELL_START_Y) / (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT + MMI_VAPP_CUBE_IMGVIEW_CELL_ROW_GAP);
    VfxS32 col = (pt.x - MMI_VAPP_CUBE_IMGVIEW_CELL_START_X + MMI_VAPP_CUBE_IMGVIEW_CELL_COL_GAP) / 
        (MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH + MMI_VAPP_CUBE_IMGVIEW_CELL_COL_GAP);

    if (col >= MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT)
    {
        col = MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT - 1;
    }
    else if(col < 0)
    {
        col = 0;
    }

    pos.pos = row * MMI_VAPP_CUBE_IMGVIEW_CELL_COL_COUNT + col;

    if (pos.pos < 0)
    {
        pos.pos = 0;
    }

    if (pos.pos >= getCellCount(pos.group))
   	{
        pos.pos = getCellCount(pos.group) - 1;
   	}

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT1_GET_CELL_POS_BY_PT, pt.x, pt.y, pos.group, pos.pos);
  	return pos;
}


//cell related
//VFX_IMPLEMENT_CLASS(MMI_VAPP_CUBE_IMGVIEW_CELL_CLASS_NAME, VappCubeImgviewCell, VfxFrame);
VappCubeImgviewCell::VappCubeImgviewCell(VcpBaseMenuLayout *layout)
{
    m_bgImage = NULL;
    m_contentImage = NULL;
    m_image = NULL;
    m_frame = NULL;
    m_index = 0;
    m_layout = layout;
    m_imageBuffer = NULL;
    m_displayRights = 0;
    m_state = IMAGE_STATE_NULL;
    m_memoryPtr = NULL;
}

void VappCubeImgviewCell::onInit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_ONINIT);
        
    VfxFrame::onInit();

    setBgColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_bgImage, VfxImageFrame, this);
    m_bgImage->setResId(VAPP_CUBE_IMG_IMGVIEW_CELL_BG);
    m_bgImage->setIsOpaque(VFX_TRUE);
    //m_bgImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_bgImage->setBgColor(VFX_COLOR_BLACK);
    
    VFX_OBJ_CREATE(m_contentImage, VfxImageFrame, this);
    m_contentImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    m_contentImage->setBgColor(VFX_COLOR_BLACK);
    m_contentImage->setIsOpaque(VFX_TRUE);

    VFX_OBJ_CREATE(m_image, VfxImage, m_contentImage);
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_0);    

    setAnchor(VfxFPoint(0.5, 0.5));
    
    
}

void VappCubeImgviewCell::onDeinit()
{   
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_ONDEINIT);
    
    VfxFrame::onDeinit();
}

void VappCubeImgviewCell::setBgPos(const VfxPoint &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_SET_BG_POS, value.x, value.y);
    
    m_bgImage->setPos(value);
}

void VappCubeImgviewCell::setContentPos(const VfxPoint &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_SET_CONTENT_POS, value.x, value.y);
    
    m_contentImage->setPos(value);
}

void VappCubeImgviewCell::setBgBounds(const VfxRect &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_SET_BOUNDS, value.origin.x, value.origin.y, value.size.width, value.size.height);

    m_bgImage->setBounds(value);
}

void VappCubeImgviewCell::setContentBounds(const VfxRect &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_SET_CONTENT_BOUNDS, value.origin.x, value.origin.y, value.size.width, value.size.height);
    m_contentImage->setBounds(value);
}

void VappCubeImgviewCell::updateCellImage(VfxS32 group, VfxS32 pos)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_UPDATE_CELL, group, pos);

    VappCubeImgviewMenu *menu = (VappCubeImgviewMenu *)getParentFrame()->getParentFrame();

    VfxS32 cellContentWidth, cellContentHeight;
    cellContentWidth = ((VappCubeImgviewMenuLayout*)m_layout)->getCellContentWidth();
    cellContentHeight = ((VappCubeImgviewMenuLayout*)m_layout)->getCellContentHeight();
    
    VfxS32 result = 0;
    
    if ((m_state == IMAGE_STATE_LOADING) || (m_state == IMAGE_STATE_NULL))
    {        
        result = vadp_cube_imgview_get_lock_image_buffer(m_index, SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE, cellContentWidth, cellContentHeight, &m_memoryPtr);
    }
    else if (m_state == IMAGE_STATE_ERROR)
    {
        result = VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
    }
    else if (m_state = IMAGE_STATE_LOCKING)
    {
        result = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
    }
    else
    {
        result = 0;
    }
    
    VfxS32 width, height, orig_width, orig_height;
    if (m_memoryPtr)
    {
        vadp_cube_imgview_get_image_info(m_index, &orig_width, &orig_height, &width, &height);
        setImageBuffer(m_memoryPtr, width, height);
        
        m_state = IMAGE_STATE_DISPLAY;

#if 0   ////TODO only Test
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
    }
    else if (result == VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING)
    {
        if (m_state != IMAGE_STATE_ERROR)
        {
            setLockingIcon();
        }
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOCK, &width, &height);
        m_state = IMAGE_STATE_LOCKING;
    }
    else if(result == VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR)
    {
        if (m_state != IMAGE_STATE_ERROR)
        {
            setErrorIcon();
        }
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_ERROR, &width, &height);
        m_state = IMAGE_STATE_ERROR;
    }
    else
    {
        if (m_state != IMAGE_STATE_LOADING)
        {
            setLoadingIcon();
        }
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOADING_0, &width, &height);
        m_state = IMAGE_STATE_LOADING;
    }
    
    m_contentImage->setContent(m_image);
    
    if ((width < cellContentWidth) || (height < cellContentHeight))
    {
        m_contentImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    }
    else
    {
        m_contentImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
        //m_contentImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    }
}

void VappCubeImgviewCell::updatePos(const VfxRect& r, VfxBool animation)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_UPDATE_POS, r.origin.x, r.origin.y, r.size.width, r.size.height, animation);
    
    setAutoAnimate(animation);
    setPos(VfxPoint(r.getMidX(), r.getMidY()));
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_CELL_BG_WIDTH, MMI_VAPP_CUBE_IMGVIEW_CELL_BG_HEIGHT));
    //setPos(VfxPoint(r.getMidX(), r.getMidY()));

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
#endif
}

void VappCubeImgviewCell::enter(VfxRect r, VfxBool is_animation)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_ENTER, r.origin.x, r.origin.y, r.size.width, r.size.height, is_animation);

    if (is_animation)
    {
        //setPos(VfxPoint(r.getMidX(), r.getMidY()));
        updatePos(r, VFX_TRUE);
        //setOpacity(1.0f);
    }
    else
   	{
       	updatePos(r, VFX_FALSE);
        //setOpacity(1.0f);
   	} 
}

void VappCubeImgviewCell::leave(VfxRect r)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_LEAVE, r.origin.x, r.origin.y, r.size.width, r.size.height);
    
    setAutoAnimate(VFX_TRUE);
   	updatePos(r, VFX_FALSE);
   	//setOpacity(0);
}


void VappCubeImgviewCell::setContentIndex(VfxS32 index)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_SET_CONTENT_INDEX, index);
        
    m_index = index;
}

void VappCubeImgviewCell::addDisplayRights()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_ADD_DISPLAY_RIGHTS);
    m_displayRights = 1;
}

void VappCubeImgviewCell::reduceDisplayRights()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_REDUCE_DISPLAY_RIGHTS);
    m_displayRights = 0;
}

void VappCubeImgviewCell::closeImage()
{
    if (m_state == IMAGE_STATE_DISPLAY)
    {
        vadp_cube_imgview_free_image_buffer(m_index, m_memoryPtr);
        m_memoryPtr = NULL;
    }

    if (m_state != IMAGE_STATE_NULL)
    {
        m_state = IMAGE_STATE_NULL;
    }
}

void VappCubeImgviewCell::setErrorIcon()
{
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_ERROR);
    m_state = IMAGE_STATE_ERROR;
    invalidate();
}

void VappCubeImgviewCell::setLockingIcon()
{
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_LOCK);
    m_state = IMAGE_STATE_LOCKING;
    invalidate();
}

void VappCubeImgviewCell::setLoadingIcon()
{
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_0);
    m_state = IMAGE_STATE_LOADING;
    invalidate();
}

void VappCubeImgviewCell::setImageBuffer(void *buffer_p, S32 width, S32 height)
{
    VappCubeImgviewMenu *menu = (VappCubeImgviewMenu *)getParentFrame()->getParentFrame();

    if (menu)
    {
        VappCubeImgviewMenuLayout *layout = (VappCubeImgviewMenuLayout *)menu->getLayout();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        VfxImageBuffer imageBuf;

        m_memoryPtr = buffer_p;

        imageBuf.ptr = (VfxU8*)m_memoryPtr;
        imageBuf.pitchBytes = width* 2;
        imageBuf.width = width;
        imageBuf.height = height;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
        m_image->setImageBuf(imageBuf);
        
        if (m_state != IMAGE_STATE_DISPLAY)
        {
            invalidate();
            m_state = IMAGE_STATE_DISPLAY;
        }
    }
}

// base menu 2 related button/cell/layout/menu/frame

//view mode button
VFX_IMPLEMENT_CLASS(MMI_VAPP_CUBE_IMGVIEW_BUTTON2_CLASS_NAME, VappCubeImgviewButton2, VfxControl);

VappCubeImgviewButton2::VappCubeImgviewButton2()
{
    m_image = NULL;
    m_imageHighLight = NULL;
    m_imageId = 0;
    m_imageHighLightImageId = 0;
    m_currPentype = 0;
}

VappCubeImgviewButton2::~VappCubeImgviewButton2()
{
    
}

void VappCubeImgviewButton2::setImage(VfxS32 image)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_BTN2_SET_IMG, image);
    m_imageId = image;
}

void VappCubeImgviewButton2::setImageHighLight(VfxS32 highLightImage)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_BTN2_SET_HILIGHT_IMG, highLightImage);
    m_imageHighLightImageId = highLightImage;
}

void VappCubeImgviewButton2::setDraw(VfxPenEventTypeEnum type)
{
    
}

void VappCubeImgviewButton2::onInit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_BTN2_ONINIT);
    
    VfxControl::onInit();
    
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_ICON_BACK);
    m_image->setPos(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_BUTTON_OFFSET_X - MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_X, 
        MMI_VAPP_CUBE_IMGVIEW_BUTTON_OFFSET_Y - MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_Y));
    m_image->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_BUTTON_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_BUTTON_OFFSET_HEIGHT));
    //m_image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    
    VFX_OBJ_CREATE(m_imageHighLight, VfxImageFrame, this);
    m_imageHighLight->setResId(VAPP_CUBE_IMG_IMGVIEW_ICON_BACK_HIGHLIGHT);
    m_imageHighLight->setPos(VfxPoint(0, 0));
    m_imageHighLight->setBounds(VfxRect(0, 0, MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_WIDTH, MMI_VAPP_CUBE_IMGVIEW_BUTTON_HILIGHT_OFFSET_HEIGHT));
    m_imageHighLight->setHidden(VFX_TRUE);
    //m_imageHighLight->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
}

void VappCubeImgviewButton2::onDeinit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_BTN2_ONDEINIT);
    
    VfxControl::onDeinit();
}

VfxBool VappCubeImgviewButton2::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos(event.getRelPos(this));
	VfxRect r = m_image->getBounds();
	r.origin = m_image->getPos();

    VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();
    if (scr)
    {
        scr->stopTimeLine();        
    }

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
		if (r.contains(pos))
        {
			m_currPentype = VFX_PEN_EVENT_TYPE_DOWN;
			
			if (m_imageHighLight)
				m_imageHighLight->setHidden(VFX_FALSE);
			
			m_eventPenDown.emit(event);
            VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_BTN2_ONPENINPUT, event.type);
            
			return VFX_TRUE;
		}
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
		if (r.contains(pos))
        {
			m_currPentype = VFX_PEN_EVENT_TYPE_UP;
			
			if (m_imageHighLight)
				m_imageHighLight->setHidden(VFX_TRUE);
			
			m_eventPenUp.emit(event);
            VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_BTN2_ONPENINPUT, event.type);
			return VFX_TRUE;
		}
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (r.contains(pos))
        {
            m_currPentype = VFX_PEN_EVENT_TYPE_DOWN;
            
            if (m_imageHighLight)
            {
                m_imageHighLight->setHidden(VFX_FALSE);
            }
        }
        else
        {
            m_currPentype = VFX_PEN_EVENT_TYPE_UP;
            
            if (m_imageHighLight)
                m_imageHighLight->setHidden(VFX_TRUE);
        }
        VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_BTN2_ONPENINPUT, event.type);

        return VFX_TRUE;
    }
    m_currPentype = VFX_PEN_EVENT_TYPE_UP;
    return VfxControl::onPenInput(event);
}

// menu layout2
VappCubeImgviewMenu2::VappCubeImgviewMenu2()
{
    m_skipUpdate = VFX_FALSE;
    m_cancelFreeMode = VFX_FALSE;
}


VappCubeImgviewMenu2::~VappCubeImgviewMenu2()
{

}

void VappCubeImgviewMenu2::onInit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ONINIT);

    VcpBaseMenu::onInit();   

    enableVerticalScrollIndicator(VFX_TRUE);
    m_state = Opening;
}
    
void VappCubeImgviewMenu2::onDeinit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ONDEINIT);
    
    VcpBaseMenu::onDeinit();
}
    
VcpBaseMenuLayout* VappCubeImgviewMenu2::createLayout()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_CREATE_LAYOUT);
    
    VappCubeImgviewMenuLayout2* layout;
    VFX_OBJ_CREATE_EX(layout, VappCubeImgviewMenuLayout2, this, (this));
    
    return layout;
}
    
VfxFrame* VappCubeImgviewMenu2::createCell(VfxS32 group, VfxS32 pos)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_CREATE_CELL, group, pos);
    
    VappCubeImgviewCell2* cell;
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2*)m_layout;
    VcpMenuPos p;
    p.group = group;
    p.pos = pos;

    VFX_OBJ_CREATE_EX(cell, VappCubeImgviewCell2, this, (this->m_layout));
    cell->setCellFileIndex(pos);
    cell->setCellPos(pos);
    cell->setIsOpaque(VFX_TRUE);
  
    //cell->setIsCached(VFX_TRUE);    
    return cell;
}

void VappCubeImgviewMenu2::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_CLOSE_CELL, group, pos);
    
    VappCubeImgviewCell2 *cell = (VappCubeImgviewCell2*)cellFrame;
    cell->closeImage();

    VFX_OBJ_CLOSE(cellFrame);
}












    
void VappCubeImgviewMenu2::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag )
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_UPDATE_CELL, group, pos, flag, getSkipUpdate());

    VappCubeImgviewCell2* item = (VappCubeImgviewCell2*) cell;
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *)m_layout;
    
    VcpMenuPos p;
    p.group = group;
    p.pos = pos;
    
    VfxRect r_bg = layout->queryCellRect(p);
    
    item->setPos(VfxPoint(r_bg.getX(), r_bg.getY()));
    item->setBounds(VfxRect(0, 0, layout->getCellWidth(), layout->getCellHeight()));
    
    //if (flag & VCP_CELL_FLAG_FIRSTINIT)
    {
        item->updateCellImage(group, pos);
    }
}

void VappCubeImgviewCell2::updateCellImage(VfxS32 group, VfxS32 pos)
{
    //VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL1_UPDATE_CELL, group, pos);
    
    VfxS32 cellContentWidth, cellContentHeight, resize_w, resize_h, cellBgWidth, cellBgHeight;
    cellContentWidth = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellContentWidth();
    cellContentHeight = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellContentHeight();
    cellBgWidth = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellBgWidth();
    cellBgHeight = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellBgHeight();

    VfxS32 result = 0;
    VfxS32 source;
    if ((m_state == IMAGE_STATE_LOADING) || (m_state == IMAGE_STATE_NULL))
    {        
        source = SRV_MEDIACACHE_OK;
        //result = vadp_cube_imgview_get_lock_image_buffer(m_index, SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE, cellContentWidth, cellContentHeight, &m_memoryPtr);
        result = vadp_cube_imgview_get_image_buffer(m_index, cellContentWidth, cellContentHeight, &resize_w, &resize_h, &m_memoryPtr, &source);
        
        if (result >= 0)
        {
            if (m_memoryPtr)
            {
                if (source == SRV_MEDIACACHE_OK_L2)
                {
                    m_state = IMAGE_STATE_DISPLAY_L2;
                }
                else if (source == SRV_MEDIACACHE_OK_L1)
                {
                    m_state = IMAGE_STATE_DISPLAY_L1;
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
        }
        else if (result == VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING)
        {
            result = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
        }
        else if (result == SRV_MEDIACACHE_ERR_DECODING)
        {
            ;// do nothing
        }
        else
        {
            result = VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
        }

        m_cellBufferWidth = resize_w;
        m_cellBufferHeight = resize_h;
    }
    else if (m_state == IMAGE_STATE_DISPLAY_L2)
    {
        source = SRV_MEDIACACHE_OK_L1;
        //result = vadp_cube_imgview_get_lock_image_buffer(m_index, SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE, cellContentWidth, cellContentHeight, &m_memoryPtr);
        result = vadp_cube_imgview_get_image_buffer(m_index, cellContentWidth, cellContentHeight, &resize_w, &resize_h, &m_memoryPtr, &source);
        
        if (m_memoryPtr)
        {
            if (source == SRV_MEDIACACHE_OK_L2)
            {
                m_state = IMAGE_STATE_DISPLAY_L2;
            }
            else if (source == SRV_MEDIACACHE_OK_L1)
            {
                m_state = IMAGE_STATE_DISPLAY_L1;
            }
            else
            {
                MMI_ASSERT(0);
            }
        }

        m_cellBufferWidth = resize_w;
        m_cellBufferHeight = resize_h;
    }
    else if (m_state == IMAGE_STATE_LOCKING)
    {
        result = VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING;
    }
    else if (m_state == IMAGE_STATE_ERROR)
    {
        result = VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
    }
    else
    {
        result = 0;
    }
    
    VfxS32 cell_width, cell_height, cell_content_width, cell_content_height;

    cell_width = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellWidth();
    cell_height = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellHeight();

    if (m_memoryPtr)
    {
        setImageBuffer(m_memoryPtr);
        displayPhotoFrame();
        invalidate();

        cell_content_width = m_cellBufferWidth;
        cell_content_height = m_cellBufferHeight;
    }
    else if (result == SRV_MEDIACACHE_ERR_DECODING)
    {
        m_photoFrame->setHidden(VFX_TRUE);
        m_bgImageFrame->setHidden(VFX_TRUE);
        m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_0);
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOADING_0, &cell_content_width, &cell_content_height);
        m_state = IMAGE_STATE_LOADING;
    }
    else if (result == VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING)
    {
        m_photoFrame->setHidden(VFX_TRUE);
        m_bgImageFrame->setHidden(VFX_TRUE);
        if (m_state != IMAGE_STATE_LOCKING)
        {
            setLockingIcon();
        }
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOCK, &cell_content_width, &cell_content_height);
        m_state = IMAGE_STATE_LOCKING;
    }
    else if (result == VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR)
    {
        m_photoFrame->setHidden(VFX_TRUE);
        m_bgImageFrame->setHidden(VFX_TRUE);
        if (m_state != IMAGE_STATE_ERROR)
        {
            setErrorIcon();
        }
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_ERROR, &cell_content_width, &cell_content_height);
        m_state = IMAGE_STATE_ERROR;
    }
    else
    {
        m_photoFrame->setHidden(VFX_TRUE);
        m_bgImageFrame->setHidden(VFX_TRUE);
        if (m_state != IMAGE_STATE_LOADING)
        {
            setLoadingIcon();
        }
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOADING_0, &cell_content_width, &cell_content_height);
        m_state = IMAGE_STATE_LOADING;
    }
       
    setContentPos(VfxPoint((cell_width - cell_content_width)/2, (cell_height - cell_content_height)/2));
    setContentBounds(VfxRect(0, 0, cell_content_width, cell_content_height));

    m_contentImage->setContent(m_image);
}









void VappCubeImgviewMenu2::onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_TAP_CELL, group, pos);
        
    m_eventTapCell.emit(pos, cell);
}

VfxBool VappCubeImgviewMenu2::onKeyInput(VfxKeyEvent &event)
{
	if (VappCubeImgViewScr::getAppState() == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW)
	{
		if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
		{
			if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *)m_layout;
				
				VcpMenuPos focus = m_layout->getFocusItem();
				if (focus.pos > 0)
				{
					focus.pos -= MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT;
				}
				m_layout->setFocusItem(focus, VFX_TRUE);
				
                VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_KEY_INPUT, event.type);
                
				return VFX_TRUE;
			}
		}
		else if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
		{
			if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *)m_layout;
				
				VcpMenuPos focus = m_layout->getFocusItem();
				if (focus.pos < m_layout->getCellCount(0) - MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT)
				{
					focus.pos += MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT;
				}
				m_layout->setFocusItem(focus, VFX_TRUE);
				
                VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_KEY_INPUT, event.type);
				return VFX_TRUE;
			}
		}
	}
	
    return VFX_FALSE;
}

void VappCubeImgviewMenu2::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_FOCUS_INDEX_CHANGE, focusItem.pos, previousFocusItem.pos);
        
    VfxRect rect;
    rect = queryCellRect(focusItem.pos);
    vadp_cube_imgview_focus_change(focusItem.pos);

    m_viewModeFocusChange.emit(0, m_layout->getFocusItem().pos);

    //setContentOffset(VfxPoint(rect.getX(), rect.getY()));
    //vadp_cube_imgview_focus_change(focusItem.pos, VADP_CUBE_IMGVIEW_MODE_VIEW);    
}

void VappCubeImgviewMenu2::getCellWidthHeight(S32 index, PS32 width, PS32 height)
{    
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *)m_layout;
    
    *width = layout->getCellContentWidth();
    *height = layout->getCellContentHeight();

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_GET_CELL_WIDTH_HEIGHT, index, *width, *height);
}

void VappCubeImgviewMenu2::onDragStart()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_DRAG_START);
        
    VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();
    if (scr)
    {
        scr->stopTimeLine();        
    }
    
    return;
}

void VappCubeImgviewMenu2::onDragEnd()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_DRAG_END);
    
    if (m_cancelFreeMode == VFX_TRUE)
    {
        VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();
        if (scr)
        {
            scr->regDefaultPageAct(this);
            m_cancelFreeMode = VFX_FALSE;
        }
    }

    makeVisible(m_layout->getFocusItem());
    m_viewModeFocusChange.emit(0, m_layout->getFocusItem().pos);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    //vadp_cube_imgview_focus_change(m_layout->getFocusItem().pos, VADP_CUBE_IMGVIEW_MODE_VIEW);

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
#endif
}

void VappCubeImgviewMenu2::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_ON_DRAG);
    
    VcpBaseMenu::onDrag(xoffset, yoffset);
    
    if (VFX_ABS(yoffset) > 25)
    {
        if (!m_cancelFreeMode)
        {
            VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();
            scr->deregDefaultPageAct(this);
            m_cancelFreeMode = VFX_TRUE;
        }
    } 
}

void VappCubeImgviewMenu2::setFocusItem(VcpMenuPos focus, VfxBool isMoveToVisible)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_SET_FOCUS_ITEM, focus.pos, isMoveToVisible);
    
    m_layout->setFocusItem(focus, isMoveToVisible);
}

void VappCubeImgviewMenu2::setCellCount(VfxS32 value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_SET_CELL_COUNT, value);
    
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *) m_layout;
    
    if (layout)
    {
        layout->setCellCount(value);
    }
}

void VappCubeImgviewMenu2::setCellWidth(VfxS32 value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_SET_CELL_WIDTH, value);
    
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *) m_layout;
    
    if (layout)
    {
        layout->setCellWidth(value);
    }
}

void VappCubeImgviewMenu2::setCellHeight(VfxS32 value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_SET_CELL_HEIGHT, value);
    
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *) m_layout;
    
    if (layout)
    {
        layout->setCellHeight(value);
    }
}  

VfxRect VappCubeImgviewMenu2::queryCellRect(VfxS32 index)
{
    VfxRect rect;
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *) m_layout;

    if (layout)
    {
        VcpMenuPos pos;

        pos.group = 0;
        pos.pos = index;
        rect = layout->queryCellRect(pos);
    }

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_QUERY_CELL_RECT, index, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
    return rect;
}

void VappCubeImgviewMenu2::setCacheNumber(VfxS32 number)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_SET_CACHE_NUMBER, number);
        
	VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *) m_layout;
    m_cacheLen = number * layout->getCellHeight();
}

void VappCubeImgviewMenu2::onAfterUpdate(const VcpMenuRegion& currentRegion, const VcpMenuRegion& targetRegion)
{
    return;
    if (!m_isScrolling)
    {
        if (VappCubeImgViewScr::getAppState() == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW)
        {
            heavyUpdate();
        }
    }
}

void VappCubeImgviewMenu2::onViewScrollStart()
{
    vadp_cube_imgview_pause_cache();
}


void VappCubeImgviewMenu2::onViewScrollEnd()
{
    vadp_cube_imgview_resume_cache();
    
    //if (!m_isScrolling)
    {
        if (VappCubeImgViewScr::getAppState() == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW)
        {
            heavyUpdate();
        }
    }
}

void VappCubeImgviewMenu2::decodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code)
{
    VappCubeImgviewMenu2* this_ptr = (VappCubeImgviewMenu2*) user_data;
    VfxObjWeakPtr weak_ptr = this_ptr;
    
    if (weak_ptr != NULL)
    {
        this_ptr->heavyUpdate(index, error_code);
    }
}

VfxRect VappCubeImgviewMenu2::getViewRect()
{
    VfxRect r;
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *)m_layout;
    r = layout->getViewRect();

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_GET_VIEW_RECT, r.origin.x, r.origin.y, r.size.width, r.size.height);
    
    return r;
}


S32 VappCubeImgviewMenu2::getFocusIndexByRect(VfxRect r)
{
    VcpMenuPos p;
    VappCubeImgviewMenuLayout2 *layout = (VappCubeImgviewMenuLayout2 *)m_layout;
    p = layout->getCellPosByPt(VfxPoint(r.origin.x + r.size.width / 2, r.origin.y + r.size.height / 2));

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_MENU2_GET_FOCUS_INDEX_BY_PT, r.origin.x, r.origin.y, r.size.width, r.size.height, p.pos);
    
    return p.pos;
}

void VappCubeImgviewMenu2::heavyUpdate(VfxS32 index, VfxS32 error_code)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappCubeImgviewCell2* cell;
    VcpMenuPos p;
    
    p.group = 0;
    p.pos = index;
    cell = (VappCubeImgviewCell2*)getCellIfPresent(p.group, p.pos);
    
    if (cell)
   	{
        if (error_code == SRV_MEDIACACHE_OK)
        {
            cell->updateCellImage(p.group, p.pos);
        }
        else
        {
            if (cell->getImageState() == VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L2)
            {
                cell->setImageState(VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L1);
            }
            else
            {
                cell->setErrorIcon();
            }
        }
    }
    
    heavyUpdate();
}

void VappCubeImgviewMenu2::heavyUpdate(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappCubeImgviewCell2* cell;
    VcpMenuPos p;
    VfxS32 ret;

    while(!itr.isEnd())
    {
        p = itr.next();
        
        cell = (VappCubeImgviewCell2*)getCellIfPresent(p.group, p.pos);
        
        if (cell)
        {
            if ((cell->getImageState() != VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L1) &&
                (cell->getImageState() != VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L2) &&
                (cell->getImageState() != VappCubeImgviewCell2::IMAGE_STATE_ERROR) && 
                (cell->getImageState() != VappCubeImgviewCell2::IMAGE_STATE_LOCKING))
            {
                ret = cell->getImageBufferNoblocking((void*)this, SRV_MEDIACACHE_OK);
                if (ret == SRV_MEDIACACHE_ERR_DECODING)
                {
                    VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();

                    scr->startViewModeUpdateTimer();
                    break;
                }
                else
                {
                    VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();

                    scr->startViewModeUpdateTimer();
                    break;
                }
            }
            else if ((cell->getImageState() == VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L2) && 
                     (cell->getImageState() != VappCubeImgviewCell2::IMAGE_STATE_ERROR) && 
                     (cell->getImageState() != VappCubeImgviewCell2::IMAGE_STATE_LOCKING))
            {
                ret = cell->getImageBufferNoblocking((void*)this, SRV_MEDIACACHE_OK_L1);
                if (ret == SRV_MEDIACACHE_ERR_DECODING)
                {
                    VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();

                    scr->startViewModeUpdateTimer();
                    break;
                }
                else
                {
                    VappCubeImgViewScr* scr = (VappCubeImgViewScr*)getParentFrame()->getParentFrame()->getParentFrame();

                    scr->startViewModeUpdateTimer();
                    break;
                }
            }
       	}			
    }
}

// menu 2 layout
VappCubeImgviewMenuLayout2::VappCubeImgviewMenuLayout2(VcpBaseMenu* menu) :
VcpBaseMenuLayout(menu)
{ 
    m_cellCount = 0;
    m_cellWidth = 0;
    m_cellHeight = 0;
    
    m_cellBgStartX = 0;
    m_cellBgStartY = 0;
    m_cellBgWidth = 0;
    m_cellBgHeight = 0;
    
    m_cellContentStartX = 0;
    m_cellContentStartY = 0;
    m_CellContentWidth = 0;
    m_cellContentHeight = 0;
}

void VappCubeImgviewMenuLayout2::onInit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_ONINIT);
        
    VcpBaseMenuLayout::onInit();

    setCellWidth(getViewSize().width);
    setCellHeight(getViewSize().height);

    setCellBgWidth(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_BG_WIDTH);
    setCellBgHeight(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_BG_HEIGHT);
    //setCellBgStartPoint(VfxPoint(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_START_X, MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_START_Y));
    setCellContentWidth(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH);
    setCellContentHeight(MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT);
    setCellContentStartPoint(VfxPoint(0, 0));
}

void VappCubeImgviewMenuLayout2::onDeinit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_ONDEINIT);
    
    //base menu layout do not have onDeinit. so strange
    VcpBaseMenuLayout::onDeinit();
}

VfxS32 VappCubeImgviewMenuLayout2::getCellCount(VfxS32 group)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CELL_COUNT, m_cellCount);
    
    return m_cellCount;
}

VfxS32 VappCubeImgviewMenuLayout2::getContentLength()
{
    VfxS32 len = getCellCount(0) * (getCellHeight() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_ROW_GAP) / MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT;

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CONTENT_LEN, len);
    
    return len;
}


VcpMenuRegion VappCubeImgviewMenuLayout2::queryRegion(const VfxRect& r)
{
    VcpMenuRegion region = VcpMenuRegion(
        getCellPosByPt(VfxPoint(r.getX(), r.getY())),
        getCellPosByPt(VfxPoint(r.getMaxX(), r.getMaxY())));

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_QUERY_REGION, r.origin.x, r.origin.y, r.size.width, r.size.height, region.begin.pos, region.end.pos);

    return region;
}

VfxRect VappCubeImgviewMenuLayout2::queryCellRect(VcpMenuPos pos)
{
    VfxS32 row, col;
    
    row = pos.pos / MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT;
    col = pos.pos % MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT;
    
    VfxRect r = VfxRect(
        MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_START_X + (getCellWidth() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_GAP) * col,
        (getCellHeight() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_ROW_GAP) * row,
        getCellWidth(),
        getCellHeight());

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_QUERY_CELL_RECT, pos.pos, r.origin.x, r.origin.y, r.size.width, r.size.height);

    return r;
}

VfxRect VappCubeImgviewMenuLayout2::queryCellContentRectByPos(VcpMenuPos pos)
{
    VfxS32 row, col;
    
    row = pos.pos / MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT;
    col = pos.pos % MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT;
    
    VfxRect r = VfxRect(
        MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_START_X + (getCellContentWidth() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_GAP) * col,// + (MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_BG_WIDTH - MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_WIDTH) / 2,
        (getCellContentHeight() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_ROW_GAP) * row,// + (MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_BG_HEIGHT - MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_HEIGHT) / 2,
        getCellContentWidth(),
        getCellContentHeight());

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_QUERY_CONTENT_RECT_BY_POS, pos.pos, r.origin.x, r.origin.y, r.size.width, r.size.height);
    
    return r;
}

VfxSize VappCubeImgviewMenuLayout2::getContentSize()
{
    VfxSize size = VfxSize(getCellWidth() * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_GAP + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_GAP, 
        (getCellHeight() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_ROW_GAP) * getCellCount(0) / MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT);

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CONTENT_SIZE, size.width, size.height);
    return size;
}

void VappCubeImgviewMenuLayout2::getPreferFocusMargin(VfxS32 margin[4])
{
    margin[MARGIN_LEFT] = 0;
   	margin[MARGIN_UP] = 0;
    margin[MARGIN_RIGHT] = 0;
  	margin[MARGIN_DOWN] = 0; 

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_GET_PREFER_MARGIN, margin[0], margin[1], margin[2], margin[3]) ;
}

void VappCubeImgviewMenuLayout2::onViewChanged()
{
    VcpBaseMenuLayout::onViewChanged();

    VfxS32 centerY = getViewPos().y + getViewSize().height/2;
    VfxS32 newFocus = getCellPosByPt(VfxPoint(getViewPos().x, centerY)).pos;
    VfxS32 oldFocus = getFocusItem().pos;

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_ON_VIEW_CHANGE, newFocus, oldFocus);

    if (newFocus != oldFocus)
    {
        setFocusItem(VcpMenuPos(0,newFocus), VFX_FALSE);
    }
    //makeVisible(m_layout->getFocusItem());
}



VcpMenuPos VappCubeImgviewMenuLayout2::getCellPosByPt(VfxPoint pt)
{
    VcpMenuPos pos;
    
    pos.group = 0;
    
    VfxS32 row = (pt.y) / (getCellHeight() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_ROW_GAP);
    VfxS32 col = (pt.x - MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_START_X + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_GAP) / 
        (getCellWidth() + MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_GAP);
    
    if (col >= MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT)
    {
        col = MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT - 1;
    }
    else if(col < 0)
    {
        col = 0;
    }
    
    pos.pos = row * MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_COL_COUNT + col;
    
    if (pos.pos < 0)
    {
        pos.pos = 0;
    }
    
    if (pos.pos >= getCellCount(pos.group))
   	{
        //pos.pos = getCellCount(pos.group) - 1;
   	}
    
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_GET_CELL_POS_BY_PT, pt.x, pt.y, pos.group, pos.pos);
        
    return pos;
}

VfxRect VappCubeImgviewMenuLayout2::getViewRect()
{
    VfxRect r;
    r = VfxRect(getViewPos(), getViewSize());

    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_LAYOUT2_GET_VIEW_RECT, r.origin.x, r.origin.y, r.size.width, r.size.height);
        
    return r;
}

// menu 2 cell
VappCubeImgviewCell2::VappCubeImgviewCell2(VcpBaseMenuLayout *layout)
{
    m_bgImageFrame = NULL;
    m_photoFrame = NULL;
    m_bgImage = NULL;
    m_contentImage = NULL;
    m_image = NULL;
    
    m_pos = 0;
    m_layout = layout;
    m_index = 0;
    m_imageBuffer = 0;

    m_state = IMAGE_STATE_NULL;
    m_memoryPtr = NULL;
}

VappCubeImgviewCell2::~VappCubeImgviewCell2()
{

}

void VappCubeImgviewCell2::onInit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_ONINIT);
        
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_bgImageFrame, VfxImageFrame, this);
    m_bgImageFrame->setBgColor(VFX_COLOR_BLACK);
    m_bgImageFrame->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_contentImage, VfxImageFrame, this);
    //m_contentImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    m_contentImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_contentImage->setBgColor(VFX_COLOR_BLACK);
    m_contentImage->setIsOpaque(VFX_TRUE);
    m_contentImage->setHidden(VFX_FALSE);
    m_contentImage->setBgColor(MMI_VAPP_CUBE_IMGVIEW_DEFAULT_BK_COLOR);

    VFX_OBJ_CREATE(m_image, VfxImage, m_contentImage);
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_0);

    VFX_OBJ_CREATE(m_photoFrame, VfxImageFrame, this);
    m_photoFrame->setResId(VAPP_CUBE_IMGVIEW_FRAME);
    m_photoFrame->setHidden(VFX_TRUE);
    m_photoFrame->setBounds(VfxRect(0, 0, 0, 0));
    m_photoFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

void VappCubeImgviewCell2::onDeinit()
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_ONDEINIT);
    
    /*Use FW auto close child*/

    VfxFrame::onDeinit();
}

void VappCubeImgviewCell2::setBgPos(const VfxPoint &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_SET_BG_POS, value.x, value.y);
    
    m_photoFrame->setPos(value);
}

void VappCubeImgviewCell2::setContentPos(const VfxPoint &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_SET_CONTENT_POS, value.x, value.y);
    
    m_contentImage->setPos(value);
}

void VappCubeImgviewCell2::setBgBounds(const VfxRect &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_SET_BG_BOUNDS, value.origin.x, value.origin.y, value.size.width, value.size.height);

    m_photoFrame->setBounds(value);
}


void VappCubeImgviewCell2::setContentBounds(const VfxRect &value)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_SET_CONTENT_BOUNDS, value.origin.x, value.origin.y, value.size.width, value.size.height);
    m_contentImage->setBounds(value);
}

void VappCubeImgviewCell2::onDraw( VfxDrawContext &dc )
{    
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_ON_DRAW);   

    return;
    
    VfxS32 cellContentWidth, cellContentHeight, cellWidth, cellHeight;
    
    cellContentWidth = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellContentWidth();
    cellContentHeight = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellContentHeight();
    cellWidth = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellWidth();
    cellHeight = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellHeight();
    
    VfxS32 result = SRV_MEDIACACHE_ERR_DECODING;

    if ((m_state == IMAGE_STATE_LOADING) || (m_state == IMAGE_STATE_NULL))
    {
        if (VappCubeImgViewScr::getAppState() == MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW)
        {
            result = vadp_cube_imgview_get_lock_image_buffer(m_index, SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE, cellContentWidth, cellContentHeight,  &m_memoryPtr);
        }
    }
    else if (m_state == IMAGE_STATE_ERROR)
    {
        result = -1;
    }
    else
    {
        result = 0;
    }
    
    VfxS32 image_offset_x, image_offset_y;
    image_offset_x = (cellWidth - cellContentWidth) / 2;
    image_offset_y = (cellHeight - cellContentHeight) / 2;
    
    if (m_memoryPtr)
    {
        VfxRect r = VfxRect(image_offset_x, image_offset_y, cellContentWidth, cellContentHeight);
        VfxImageBuffer imageBuf;
        imageBuf.ptr = (VfxU8  *)m_memoryPtr;
        imageBuf.pitchBytes = cellContentWidth * 2;
        imageBuf.width = cellContentWidth;
        imageBuf.height = cellContentHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
#if 0   ////TODO only Test
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
        
        dc.drawImageBuffer(image_offset_x, image_offset_y, imageBuf);

        
        if (m_state != IMAGE_STATE_DISPLAY_L2)
        {
            m_state = IMAGE_STATE_DISPLAY_L2;
            invalidate();
        }
    }
    else if(result == SRV_MEDIACACHE_ERR_DECODING)
    {
        S32 width, height;
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOADING_0, &width, &height);
        dc.drawImageFromRes((cellWidth - width) / 2,(cellHeight - height) / 2, VAPP_CUBE_IMG_IMGVIEW_LOADING_0);
        m_state = IMAGE_STATE_LOADING;
    }
    else if (result < 0)
    {
        S32 width, height;
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_ERROR, &width, &height);
        dc.drawImageFromRes((cellWidth - width) / 2,(cellHeight - height) / 2, VAPP_CUBE_IMG_IMGVIEW_ERROR);
        m_state = IMAGE_STATE_ERROR;
    }
    else
    {
        S32 width, height;
        gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOADING_0, &width, &height);
        dc.drawImageFromRes((cellWidth - width) / 2,(cellHeight - height) / 2, VAPP_CUBE_IMG_IMGVIEW_LOADING_0);
        m_state = IMAGE_STATE_LOADING;
    }
    
}

void VappCubeImgviewCell2::setCellPos(VfxS32 index)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_IMGVIEW_CELL2_SET_CELL_POS, index);
    
    m_pos = index;
}


void VappCubeImgviewCell2::closeImage()
{
    if ((m_state == IMAGE_STATE_DISPLAY_L1) || (m_state == IMAGE_STATE_DISPLAY_L2))
    {
        vadp_cube_imgview_view_mode_free_image_buffer(m_index, m_memoryPtr);
        m_memoryPtr = NULL;
    }

    if (m_state != IMAGE_STATE_NULL)
    {
        m_state = IMAGE_STATE_NULL;
    }
}

void VappCubeImgviewCell2::setImageState(S32 state)
{
    m_state = state;
}

void VappCubeImgviewCell2::setImageBufferWidthHeight(S32 width, S32 height)
{
    m_cellBufferWidth = width;
    m_cellBufferHeight = height;
}

void VappCubeImgviewCell2::displayPhotoFrame()
{
    VfxS32 cell_width, cell_height;
    
    cell_width = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellWidth();
    cell_height = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellHeight();

    VfxS32 temp_content_width = m_cellBufferWidth;
    VfxS32 temp_content_height = m_cellBufferHeight;
    VfxBool isDisplayBgColor = VFX_FALSE;
    
    if (temp_content_width < MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MIN_WIDTH)
    {
        temp_content_width = MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MIN_WIDTH;
        isDisplayBgColor = VFX_TRUE;
    }
    
    if (temp_content_height < MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MIN_HEIGHT)
    {
        temp_content_height = MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MIN_HEIGHT;
        isDisplayBgColor = VFX_TRUE;
    }
    
    kal_prompt_trace(MOD_MMI, "[CUBE_NEW] content pos is %d, %d", (cell_width - temp_content_width)/2 - MMI_VAPP_CUBE_IMGVIEW_CORNER_GAP, (cell_height - temp_content_height)/2 - MMI_VAPP_CUBE_IMGVIEW_CORNER_GAP);

    setBgPos(VfxPoint((cell_width - temp_content_width)/2 - MMI_VAPP_CUBE_IMGVIEW_CORNER_GAP, (cell_height - temp_content_height)/2 - MMI_VAPP_CUBE_IMGVIEW_CORNER_GAP));
    setBgBounds(VfxRect(0, 0, temp_content_width + MMI_VAPP_CUBE_IMGVIEW_CORNER_GAP * 2, temp_content_height + MMI_VAPP_CUBE_IMGVIEW_CORNER_GAP * 2));  //in W10.11 will remove -1
    m_photoFrame->setHidden(VFX_FALSE);
    
    if (isDisplayBgColor)
    {
        m_bgImageFrame->setHidden(VFX_FALSE);
        m_bgImageFrame->setPos(VfxPoint((cell_width - temp_content_width)/2, (cell_height - temp_content_height)/2));
        m_bgImageFrame->setBounds(VfxRect(0, 0, temp_content_width, temp_content_height));  //in W10.11 will remove -1
    }
    else
    {
        m_bgImageFrame->setHidden(VFX_TRUE);
    }    
}

void VappCubeImgviewCell2::setImageBuffer(void *buffer_p)
{
    VappCubeImgviewMenu2 *menu = (VappCubeImgviewMenu2 *)getParentFrame()->getParentFrame();
    
    if (menu)
    {
        VfxImageBuffer imageBuf;
        
        m_memoryPtr = buffer_p;
        
        imageBuf.ptr = (VfxU8*)m_memoryPtr;
        imageBuf.pitchBytes = m_cellBufferWidth * 2;
        imageBuf.width = m_cellBufferWidth;
        imageBuf.height = m_cellBufferHeight;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
        m_image->setImageBuf(imageBuf);
        
        invalidate();
    }
}

void VappCubeImgviewCell2::setErrorIcon()
{
    if (m_memoryPtr)
    {
        closeImage();
    }

    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_ERROR);
    m_state = IMAGE_STATE_ERROR;

    VfxS32 cell_width, cell_height, cell_content_width, cell_content_height;
    
    cell_width = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellWidth();
    cell_height = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellHeight();
    gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_ERROR, &cell_content_width, &cell_content_height);
    setContentPos(VfxPoint((cell_width - cell_content_width)/2, (cell_height - cell_content_height)/2));
    setContentBounds(VfxRect(0, 0, cell_content_width, cell_content_height));

    invalidate();
}

void VappCubeImgviewCell2::setLockingIcon()
{
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_LOCK);
    m_state = IMAGE_STATE_LOCKING;

    VfxS32 cell_width, cell_height, cell_content_width, cell_content_height;
    
    cell_width = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellWidth();
    cell_height = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellHeight();
    gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOCK, &cell_content_width, &cell_content_height);
    setContentPos(VfxPoint((cell_width - cell_content_width)/2, (cell_height - cell_content_height)/2));
    setContentBounds(VfxRect(0, 0, cell_content_width, cell_content_height));

    invalidate();
}

void VappCubeImgviewCell2::setLoadingIcon()
{
    m_image->setResId(VAPP_CUBE_IMG_IMGVIEW_LOADING_0);
    m_state = IMAGE_STATE_LOADING;

    VfxS32 cell_width, cell_height, cell_content_width, cell_content_height;
    
    cell_width = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellWidth();
    cell_height = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellHeight();
    gdi_image_get_dimension_id(VAPP_CUBE_IMG_IMGVIEW_LOADING_0, &cell_content_width, &cell_content_height);
    setContentPos(VfxPoint((cell_width - cell_content_width)/2, (cell_height - cell_content_height)/2));
    setContentBounds(VfxRect(0, 0, cell_content_width, cell_content_height));
    
    invalidate();
}

VfxS32 VappCubeImgviewCell2::getImageBufferNoblocking(void* menu_ptr, VfxS32 expect_source)
{
    VfxS32 ret = 0;
    VfxS32 cell_width, cell_height;
    VfxS32 cellContentWidth, cellContentHeight, resize_w, resize_h;
    void *memory_ptr_internal = NULL;

    cellContentWidth = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellContentWidth();
    cellContentHeight = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellContentHeight();
    cell_width = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellWidth();
    cell_height = ((VappCubeImgviewMenuLayout2*)m_layout)->getCellHeight();

    VfxS32 source = expect_source;

    ret = vadp_cube_imgview_get_image_buffer_nonblocking(menu_ptr, m_index, cellContentWidth, cellContentHeight, 
        &resize_w, &resize_h, &memory_ptr_internal, &source, &VappCubeImgviewMenu2::decodeCallBack);

    if (ret == SRV_MEDIACACHE_OK)
    {
        if (source == SRV_MEDIACACHE_OK_L2)
        {
            if (expect_source == SRV_MEDIACACHE_OK_L1)
            {
                return SRV_MEDIACACHE_ERR_DECODING;
            }
            else
            {
                setImageState(VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L2);
                setImageBufferWidthHeight(resize_w, resize_h);
                
                setImageBuffer(memory_ptr_internal);
                displayPhotoFrame();
                invalidate();

                setContentPos(VfxPoint((cell_width - m_cellBufferWidth)/2, (cell_height - m_cellBufferHeight)/2));
                setContentBounds(VfxRect(0, 0, m_cellBufferWidth, m_cellBufferHeight));
                
                m_contentImage->setContent(m_image);
            }
        }
        else if ((source == SRV_MEDIACACHE_OK_L1) && memory_ptr_internal)
        {
            setImageState(VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L1);
            setImageBufferWidthHeight(resize_w, resize_h);
            
            setImageBuffer(memory_ptr_internal);
            displayPhotoFrame();
            invalidate();

            setContentPos(VfxPoint((cell_width - m_cellBufferWidth)/2, (cell_height - m_cellBufferHeight)/2));
            setContentBounds(VfxRect(0, 0, m_cellBufferWidth, m_cellBufferHeight)); 
            
            m_contentImage->setContent(m_image);
        }
        else
        {
            //MMI_ASSERT(0);
        }
    }
    else if (ret == VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING)
    {
        setLockingIcon();
    }
    else if (ret == SRV_MEDIACACHE_ERR_DECODING)
    {
        setLoadingIcon();
    }
    else if (ret < 0)
    {
        if (getImageState() == IMAGE_STATE_DISPLAY_L2)
        {
            setImageState(IMAGE_STATE_DISPLAY_L1);
        }
        else
        {
            setErrorIcon();
        }
    }

    return ret;
}

void VappCubeImgviewMenu2::closeAllImage(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());
    VappCubeImgviewCell2* cell;
    VcpMenuPos p;
    
    while(!itr.isEnd())
    {
        p = itr.next();
        
        cell = (VappCubeImgviewCell2*)getCellIfPresent(p.group, p.pos);
        
        if (cell && ((cell->getImageState() == VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L2) || ((cell->getImageState() == VappCubeImgviewCell2::IMAGE_STATE_DISPLAY_L1))))
        {
            cell->closeImage();
       	}			
   	}    
}


#endif
