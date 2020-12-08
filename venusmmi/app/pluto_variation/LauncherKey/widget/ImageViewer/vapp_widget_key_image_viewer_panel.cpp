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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_key_image_viewer_panel.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_key_image_viewer_panel.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "ImageViewerGprot.h"
#include "ImageViewCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VappWidgetKeyImageViewerPanel
 *****************************************************************************/

VfxS32  VappWidgetKeyImageViewerPanel::m_currImgIdx  = 0;
VfxBool VappWidgetKeyImageViewerPanel::m_isViewImage = VFX_FALSE;
mmi_id  VappWidgetKeyImageViewerPanel::m_imgViewParentGid = GRP_ID_INVALID;


VFX_IMPLEMENT_CLASS("VappWidgetKeyImageViewerPanel", VappWidgetKeyImageViewerPanel, VfxControl);

void VappWidgetKeyImageViewerPanel::onInit()
{
	VAPP_WKIV_SLA(("IOI", SA_start));

	VfxControl::onInit();

	setFocused(VFX_TRUE);
	
	VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
	m_bg->setResId(IMG_ID_WIDGET_KEY_IMAGE_VIEWER_BG);
	m_bg->setSize(VIEW_PANEL_WIDTH, VIEW_PANEL_HEIGHT);
	m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	
	VFX_OBJ_CREATE(m_container, VfxFrame, this);
	m_container->setSize(CELL_WIDTH, CELL_HEIGHT);
	m_container->setPos((VIEW_PANEL_WIDTH - CELL_WIDTH)>>1, (VIEW_PANEL_HEIGHT - CELL_HEIGHT)>>1);

	VfxS32 i;
	for(i = CELL_IDX_PREV; i < CELL_IDX_TOTAL; i++)
	{
		s_cellTbl[i] = NULL;
	}

	if (m_isViewImage)
		m_isViewImage = VFX_FALSE;

	VAPP_WKIV_SLA(("IOI", SA_stop));
}

void VappWidgetKeyImageViewerPanel::onDeinit()
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_DEINIT, 1));

	VfxS32 i;
	for(i = CELL_IDX_PREV; i < CELL_IDX_TOTAL; i++)
	{
		if(s_cellTbl[i])
		{
			VFX_OBJ_CLOSE(s_cellTbl[i]);
		}
	}

	if (m_cacher)
	{
		m_cacher->stopCache(!m_isViewImage);
		VFX_OBJ_CLOSE(m_cacher);
	}
	
	setFocused(VFX_FALSE);
	
	VfxControl::onDeinit();
}

void VappWidgetKeyImageViewerPanel::creatView()
{
	VAPP_WKIV_SLA(("ICV", SA_start));
	
	if (!prepareView())
	{
		createDefaultView();
	}
	//else
	//{
	//	m_cacher->m_signalCacheStarted.connect(this, &VappWidgetKeyImageViewerPanel::onCacheStarted);
	//}

	VAPP_WKIV_SLA(("ICV", SA_stop));
}
	
VfxBool VappWidgetKeyImageViewerPanel::prepareView()
{
	VFX_OBJ_CREATE(m_cacher, VappWidgetKeyImageViewerCache, this);
	//m_cacher->m_signalEmpty.connect(this, &VappWidgetKeyImageViewerPanel::createDefaultView);
	m_cacher->m_signalMsg.connect(this, &VappWidgetKeyImageViewerPanel::onMsgReceived);
	return m_cacher->startCache(m_currImgIdx);
}

void VappWidgetKeyImageViewerPanel::onMsgReceived(VappWidgetKeyImageViewerMsgEnum msg)
{
	switch (msg)
	{
		case FILE_LIST_EMPTY:
			createDefaultView();
			break;
			
		case FILE_LIST_DIRTY:
		case FILE_LIST_RESET:
			m_currImgIdx = 0;
			break;

		case MEDIA_CACHE_START:
			onCacheStarted();
			break;

		default:
			VFX_ASSERT(0);
	}
}

void VappWidgetKeyImageViewerPanel::createDefaultView()
{
	VFX_OBJ_CREATE(s_cellTbl[CELL_IDX_CURR], VappWidgetKeyImageViewerCell, m_container);
	s_cellTbl[CELL_IDX_CURR]->setResId(IMG_ID_WIDGET_KEY_IMAGE_VIEWER_NONE);
	s_cellTbl[CELL_IDX_CURR]->setPos(CELL_CURR_POS);
}

void VappWidgetKeyImageViewerPanel::onCacheStarted()
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_START));

	m_imgCount = m_cacher->getImageCount();

	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_IMG_COUNT, m_imgCount));
	
	VFX_OBJ_CREATE_EX(s_cellTbl[CELL_IDX_CURR], VappWidgetKeyImageViewerCell, m_container, (m_cacher));
	s_cellTbl[CELL_IDX_CURR]->setImageIndex(m_currImgIdx);
	s_cellTbl[CELL_IDX_CURR]->setPos(CELL_CURR_POS);

	if (m_imgCount > 1)
	{	
		s_cellTbl[CELL_IDX_CURR]->setMoveEnable();
		s_cellTbl[CELL_IDX_CURR]->m_signalMoveDone.connect(this, &VappWidgetKeyImageViewerPanel::onSwitchDone);
	
		VFX_OBJ_CREATE_EX(s_cellTbl[CELL_IDX_PREV], VappWidgetKeyImageViewerCell, m_container, (m_cacher));
		s_cellTbl[CELL_IDX_PREV]->setImageIndex(getPrevIndex(m_currImgIdx));
		s_cellTbl[CELL_IDX_PREV]->setPos(CELL_PREV_POS);
		s_cellTbl[CELL_IDX_PREV]->setMoveEnable();
		s_cellTbl[CELL_IDX_PREV]->m_signalMoveDone.connect(this, &VappWidgetKeyImageViewerPanel::onSwitchDone);
		
		VFX_OBJ_CREATE_EX(s_cellTbl[CELL_IDX_NEXT], VappWidgetKeyImageViewerCell, m_container, (m_cacher));
		s_cellTbl[CELL_IDX_NEXT]->setImageIndex(getNextIndex(m_currImgIdx));
		s_cellTbl[CELL_IDX_NEXT]->setPos(CELL_NEXT_POS);
		s_cellTbl[CELL_IDX_NEXT]->setMoveEnable();
		s_cellTbl[CELL_IDX_NEXT]->m_signalMoveDone.connect(this, &VappWidgetKeyImageViewerPanel::onSwitchDone);

		s_cellTbl[CELL_IDX_PREV]->setId(-1);
		s_cellTbl[CELL_IDX_CURR]->setId(0);
		s_cellTbl[CELL_IDX_NEXT]->setId(1);
	}

	showImage();
}

void VappWidgetKeyImageViewerPanel::showImage()
{
	s_cellTbl[CELL_IDX_CURR]->onFocus();
}

void VappWidgetKeyImageViewerPanel::onSwitchDone()
{
	m_switchFlag = m_switchFlag << 1;

	if (m_switchFlag & 0x04)
	{
		switchDoneHdlr();
	}	
}

void VappWidgetKeyImageViewerPanel::switchDoneHdlr()
{
	m_switchFlag = 0x01;

	VappWidgetKeyImageViewerCell *cell;
		
	if (m_switchType == SWITCH_TYPE_PREV)
	{
		cell = s_cellTbl[CELL_IDX_PREV];
		s_cellTbl[CELL_IDX_PREV] = s_cellTbl[CELL_IDX_NEXT];
		s_cellTbl[CELL_IDX_NEXT] = s_cellTbl[CELL_IDX_CURR];
		s_cellTbl[CELL_IDX_CURR] = cell;
	}
	else
	{
		cell = s_cellTbl[CELL_IDX_PREV];
		s_cellTbl[CELL_IDX_PREV] = s_cellTbl[CELL_IDX_CURR];
		s_cellTbl[CELL_IDX_CURR] = s_cellTbl[CELL_IDX_NEXT];
		s_cellTbl[CELL_IDX_NEXT] = cell;
	}

	m_currImgIdx = s_cellTbl[CELL_IDX_CURR]->getImageIndex();
	m_cacher->goToIndex(m_currImgIdx);

	VfxS32 i;
	for(i = CELL_IDX_PREV; i < CELL_IDX_TOTAL; i++)
	{
		VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_SWITCH_DONE, s_cellTbl[i]->getId(), s_cellTbl[i]->getImageIndex()));
	}

	m_isSwitching = VFX_FALSE;
	
}

VfxBool VappWidgetKeyImageViewerPanel::onKeyInput(VfxKeyEvent & event)
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_KEY_INPUT, event.keyCode, event.type));

	switch (event.keyCode)
	{
		case VFX_KEY_CODE_CSK:
			if (event.type == VFX_KEY_EVENT_TYPE_UP)
			{
				viewImage();
				return VFX_TRUE;
			}
			break;
			
		case VFX_KEY_CODE_ARROW_UP:
		case VFX_KEY_CODE_ARROW_DOWN:	
			keySwitchHdlr(event);
			return VFX_TRUE;

		default:
			break;
	}	

	return VFX_FALSE; 
}

void VappWidgetKeyImageViewerPanel::keySwitchHdlr(VfxKeyEvent & event)
{
	if (m_imgCount <= 1)
		return;

	if (m_isSwitching)
		return;

	m_isSwitching = VFX_TRUE;

	switch (event.keyCode)
	{
		case VFX_KEY_CODE_ARROW_UP:
			showPrevImage();
			break; 
		
		case VFX_KEY_CODE_ARROW_DOWN:
			showNextImage();			
			break;

		default:
			break;
	}
	
}

void VappWidgetKeyImageViewerPanel::showPrevImage()
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_PREV, m_currImgIdx));
	
	m_switchType = SWITCH_TYPE_PREV;
	
	s_cellTbl[CELL_IDX_NEXT]->onSkip(SWITCH_TYPE_PREV);
	VfxS32 prev = getPrevIndex(s_cellTbl[CELL_IDX_PREV]->getImageIndex());
	s_cellTbl[CELL_IDX_NEXT]->setImageIndex(prev);

	s_cellTbl[CELL_IDX_PREV]->onSlideIn(SWITCH_TYPE_PREV);

	s_cellTbl[CELL_IDX_CURR]->onSlideOut(SWITCH_TYPE_PREV);		
}

void VappWidgetKeyImageViewerPanel::showNextImage()
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_NEXT, m_currImgIdx));
	
	m_switchType = SWITCH_TYPE_NEXT;
	
	s_cellTbl[CELL_IDX_PREV]->onSkip(SWITCH_TYPE_NEXT);
	VfxS32 next = getNextIndex(s_cellTbl[CELL_IDX_NEXT]->getImageIndex());
	s_cellTbl[CELL_IDX_PREV]->setImageIndex(next);

	s_cellTbl[CELL_IDX_NEXT]->onSlideIn(SWITCH_TYPE_NEXT);

	s_cellTbl[CELL_IDX_CURR]->onSlideOut(SWITCH_TYPE_NEXT);
}

VfxS32 VappWidgetKeyImageViewerPanel::getPrevIndex(VfxS32 idx)
{
	VfxS32 i = idx;
	i -= 1;
	if (i < 0)
	{
		i = m_imgCount -1;
	}
	
	return i;
}

VfxS32 VappWidgetKeyImageViewerPanel::getNextIndex(VfxS32 idx)
{
	VfxS32 i = idx;
	i += 1;
	if (i > m_imgCount - 1)
	{
		i = 0;
	}
	
	return i;
}

VfxBool VappWidgetKeyImageViewerPanel::onPenInput(VfxPenEvent & event)
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_PEN_INPUT, event.type));

	if (!getFocused())
		return VFX_TRUE;

	VfxPoint pos = event.getRelPos(this);

	switch (event.type)
	{
		case VFX_PEN_EVENT_TYPE_DOWN:
			if (isPenFocused(pos) && !m_isSwitching)
			{
				m_isFocused = VFX_TRUE;
			}
			break;

		case VFX_PEN_EVENT_TYPE_UP:
			if (m_isFocused)
			{
				if (m_isMoved)
				{
					penSwitchHdlr(event);
				}
				else
				{
					viewImage();
				}
				m_isFocused = VFX_FALSE;
			}
			m_isMoved = VFX_FALSE;
			break;

		case VFX_PEN_EVENT_TYPE_MOVE:
			if (m_isFocused)
			{
				m_isMoved = VFX_TRUE;
				
				if (isPenFocused(pos))
				{
					penMoveHdlr(event);
				}
				else
				{
					m_isFocused = VFX_FALSE;
					penSwitchHdlr(event);
				}
			}
			break;

		case VFX_PEN_EVENT_TYPE_ABORT:
			m_isFocused = VFX_FALSE;
			//will not receive pen up
			break;

		default:
			break;

	}

	return VFX_TRUE;
}

VfxBool VappWidgetKeyImageViewerPanel::isPenFocused(VfxPoint pos)
{
	return (pos.x > m_container->getPos().x)
		&& (pos.x < m_container->getPos().x + m_container->getSize().width)
		&& (pos.y > m_container->getPos().y)
		&& (pos.y < m_container->getPos().y + m_container->getSize().height);	
}

void VappWidgetKeyImageViewerPanel::penSwitchHdlr(VfxPenEvent & event)
{
	if ((m_imgCount <= 1))
		return;

	if (m_isSwitching)
		return;

	m_isSwitching = VFX_TRUE;

	if ((event.pos.y - event.downPos.y) < 0)
	{
		showNextImage();
	}
	else if ((event.pos.y - event.downPos.y) > 0)
	{
		showPrevImage();
	}
}

void VappWidgetKeyImageViewerPanel::penMoveHdlr(VfxPenEvent & event)
{
	if ((m_imgCount <= 1))
		return;

	VfxS32 off = event.pos.y - event.prevPos.y;
	
	if (event.pos.y - event.downPos.y < 0)
	{
		//if there are 2 images, the move in cell will lock the other image
		//so the move out cell should unlock it first
		if (m_imgCount == 2)
		{
			s_cellTbl[CELL_IDX_PREV]->onUnFocus();
		}
		
		s_cellTbl[CELL_IDX_PREV]->onMove(off, VFX_FALSE);		
		s_cellTbl[CELL_IDX_CURR]->onMove(off, VFX_FALSE);
		s_cellTbl[CELL_IDX_NEXT]->onMove(off, VFX_TRUE);
	}
	else
	{
		if (m_imgCount == 2)
		{
			s_cellTbl[CELL_IDX_NEXT]->onUnFocus();
		}
		
		s_cellTbl[CELL_IDX_NEXT]->onMove(off, VFX_FALSE);
		s_cellTbl[CELL_IDX_CURR]->onMove(off, VFX_FALSE);		
		s_cellTbl[CELL_IDX_PREV]->onMove(off, VFX_TRUE);
	}
}

void VappWidgetKeyImageViewerPanel::viewImage()
{	
	if (m_imgCount)
	{
		m_isViewImage = VFX_TRUE;
		
		m_imgViewParentGid = mmi_frm_group_create_ex(
					GRP_ID_ROOT, 
					GRP_ID_AUTO_GEN, 
					&VappWidgetKeyImageViewerPanel::eventProc, 
					this,
					MMI_FRM_NODE_SMART_CLOSE_FLAG); 
			
		if ((m_imgViewGid = cui_imgview_create(m_imgViewParentGid)) != GRP_ID_INVALID)
		{
			cui_imgview_set_mode_filelist(
				m_imgViewGid, 
				VappWidgetKeyImageViewerCache::m_fileListHandle, 
				m_currImgIdx);
			cui_imgview_set_app_id(m_imgViewGid, m_imgViewParentGid);
			cui_imgview_set_ui_direction(m_imgViewGid, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
			cui_imgview_set_display_cap(m_imgViewGid, CUI_IMGVIEW_CAP_ALL, MMI_TRUE);
			cui_imgiew_set_storage_enable(m_imgViewGid);
			cui_imgview_run(m_imgViewGid);
		}
		else
		{
			mmi_frm_group_close(m_imgViewParentGid);
			m_isViewImage = VFX_FALSE;
		}	 
	}
	else
	{
		mmi_imgview_launch();		
	}
    
}

mmi_ret VappWidgetKeyImageViewerPanel::eventProc(mmi_event_struct * evt)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif

	switch(evt->evt_id)
    {
        case EVT_ID_IMGVIEW_CLOSE_GID:
        {
            mmi_group_event_struct *cui_evt = (mmi_group_event_struct*)evt;
			
            //m_cacher->setImageIndex(cui_imgview_get_cur_index(cui_evt->sender_id));
            m_currImgIdx = cui_imgview_get_cur_index(cui_evt->sender_id);
            cui_imgview_close(cui_evt->sender_id);
            mmi_frm_group_close(m_imgViewParentGid);
            break;
        }

		case EVT_ID_IMGVIEW_STORAGE_CHANGE:
		{
            mmi_group_event_struct *cui_evt = (mmi_group_event_struct*)evt;
			
            //m_cacher->setImageIndex(cui_imgview_get_cur_index(cui_evt->sender_id));
            m_currImgIdx = cui_imgview_get_cur_index(cui_evt->sender_id);
            cui_imgview_close(cui_evt->sender_id);
            mmi_frm_group_close(m_imgViewParentGid);
			break;
		}

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        {
            mmi_group_event_struct *cui_evt = (mmi_group_event_struct*)evt;
			
            //m_cacher->setImageIndex(cui_imgview_get_cur_index(cui_evt->sender_id));
            m_currImgIdx = cui_imgview_get_cur_index(cui_evt->sender_id);
            break;
        }

        default:
            break;
    }
	
    return MMI_RET_OK;
}

void VappWidgetKeyImageViewerPanel::eventHdlr(mmi_event_struct * evt)
{
	switch(evt->evt_id)
    {
        case EVT_ID_IMGVIEW_CLOSE_GID:
        {
            mmi_group_event_struct *cui_evt = (mmi_group_event_struct*)evt;
			
            //m_cacher->setImageIndex(cui_imgview_get_cur_index(cui_evt->sender_id));
            m_currImgIdx = cui_imgview_get_cur_index(cui_evt->sender_id);
            cui_imgview_close(cui_evt->sender_id);
            mmi_frm_group_close(m_imgViewParentGid);
            break;
        }

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        {
            mmi_group_event_struct *cui_evt = (mmi_group_event_struct*)evt;
			
            //m_cacher->setImageIndex(cui_imgview_get_cur_index(cui_evt->sender_id));
            m_currImgIdx = cui_imgview_get_cur_index(cui_evt->sender_id);
            break;
        }

        default:
            break;
    }
}

#endif

