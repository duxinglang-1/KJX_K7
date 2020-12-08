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
 *  vapp_widget_key_image_viewer_cell.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_key_image_viewer_cell.h"

/*****************************************************************************
 * VappWidgetKeyImageViewerCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWidgetKeyImageViewerCell", VappWidgetKeyImageViewerCell, VfxImageFrame);

void VappWidgetKeyImageViewerCell::onInit()
{
	VfxImageFrame::onInit();

	setAnchor(0.5, 0.5);
	setSize(CELL_WIDTH, CELL_HEIGHT);
	setBounds(0, 0, CELL_WIDTH, CELL_HEIGHT);

	VFX_OBJ_CREATE(m_waitingIcon, VcpWaitingIcon, this);
	m_waitingIcon->setAnchor(0.5f, 0.5f);
	m_waitingIcon->setPos(CELL_CURR_POS);
	m_waitingIcon->setHidden(VFX_TRUE);
}

void VappWidgetKeyImageViewerCell::onDeinit()
{
	closeImage();
	VfxImageFrame::onDeinit();
}

void VappWidgetKeyImageViewerCell::setId(VfxS32 id)
{
	m_id = id;
}

VfxS32 VappWidgetKeyImageViewerCell::getId()
{
	return m_id;
}

void VappWidgetKeyImageViewerCell::setImageIndex(VfxS32 idx)
{
	m_imgIdx = idx;
}

VfxS32 VappWidgetKeyImageViewerCell::getImageIndex()
{
	return m_imgIdx;
}

void VappWidgetKeyImageViewerCell::openImage(VfxBool isMoving)
{	
	if (m_isImgBufLock)
		return;

	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_OPEN_IMG, m_id));

	VfxS32 ret;

	setSize(CELL_WIDTH, CELL_HEIGHT);

	if (isMoving)
	{
		ret = m_cacher->lockImageBufferBlock(CACHE_SRC_TYPE_MEM, m_imgIdx, &m_pImgBuf);
		if (ret == SRV_MEDIACACHE_OK)
		{
			showImageWithMem((VfxU8*)m_pImgBuf);
		}
		else
		{
			showWaiting();
			m_isNeedRetryOpenImg = VFX_TRUE;
		}
	}
	else
	{
		ret = m_cacher->lockImageBufferNonBlock(
					CACHE_SRC_TYPE_DB, 
					&VappWidgetKeyImageViewerCell::lockImgBufCallback,
					this,
					m_imgIdx,
					&m_pImgBuf);
		if (ret == SRV_MEDIACACHE_OK)
		{
			showImageWithMem((VfxU8*)m_pImgBuf);
		}
		else if (ret == SRV_MEDIACACHE_ERR_DECODING)
		{
			showWaiting();
		}
		else
		{
			showError();
		}
	}

	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_LOCK_IMG_BUF, m_id, ret));
	
}

void VappWidgetKeyImageViewerCell::closeImage()
{
	if (m_isImgBufLock)
	{
		m_cacher->unlockImageBuffer(m_pImgBuf);
		m_isImgBufLock = VFX_FALSE;
	}
	setImgContent(VfxImageSrc());
}

void VappWidgetKeyImageViewerCell::lockImgBufCallback(VfxS32 err_group,VfxS32 err_code,void * user_data)
{
	VappWidgetKeyImageViewerCell *cell = (VappWidgetKeyImageViewerCell*)user_data;
	cell->onImageBufferLocked(err_code);
}

void VappWidgetKeyImageViewerCell::onImageBufferLocked(VfxS32 err_code)
{
	if (m_isImgBufLock)
		return;

	VfxS32 ret = err_code;

	if (ret == SRV_MEDIACACHE_OK)
	{
		ret = m_cacher->lockImageBufferBlock(CACHE_SRC_TYPE_DB, m_imgIdx, &m_pImgBuf);

		VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_IMG_BUF_LOCKED, m_id, ret));
		
		if (ret == SRV_MEDIACACHE_OK)
		{
			showImageWithMem((VfxU8*)m_pImgBuf);
			return;
		}
	}

	showError();
	
}

void VappWidgetKeyImageViewerCell::onFocus()
{
	openImage(VFX_FALSE);
}

void VappWidgetKeyImageViewerCell::onUnFocus()
{
	closeImage();
}

void VappWidgetKeyImageViewerCell::setMoveEnable()
{
	VFX_OBJ_CREATE(m_timeline, VfxPointTimeline, this);
	m_timeline->m_signalStopped.connect(this, &VappWidgetKeyImageViewerCell::onSlideDone);
}

void VappWidgetKeyImageViewerCell::onMove(
	VfxS32 distance, 
    VfxBool isNeedUpdate)
{
	setPos(getPos().x, getPos().y + distance);
	
	if (isNeedUpdate)
	{
		if (getResId() == IMG_ID_WIDGET_KEY_IMAGE_VIEWER_DEFAULT)
		{
			setImgContent(VfxImageSrc());
		}
		openImage(VFX_TRUE);
	}
}

void VappWidgetKeyImageViewerCell::onSlideIn(VappWidgetKeyImageViewerSwitchTypeEnum type)
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_MOVE_IN, m_id, type));

	posAnimationHdlr(getPos(), CELL_CURR_POS);

	if (!m_isImgBufLock)
	{
		openImage(VFX_TRUE);
	}
}

void VappWidgetKeyImageViewerCell::onSlideOut(VappWidgetKeyImageViewerSwitchTypeEnum type)
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_MOVE_OUT, m_id, type));
	
	if (type == SWITCH_TYPE_NEXT)
	{
		posAnimationHdlr(getPos(), CELL_PREV_POS);
	}
	else
	{
		posAnimationHdlr(getPos(), CELL_NEXT_POS);
	}
}

void VappWidgetKeyImageViewerCell::onSkip(VappWidgetKeyImageViewerSwitchTypeEnum type)
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_SKIP, m_id, type));

	closeImage();
	
	m_isNeedRetryOpenImg = VFX_FALSE;

	if (type == SWITCH_TYPE_NEXT)
	{
		setPos(CELL_NEXT_POS);
	}
	else
	{
		setPos(CELL_PREV_POS);
	}
}

void VappWidgetKeyImageViewerCell::onSlideDone(VfxBaseTimeline * timeline,VfxBool isComplete)
{
	if (isComplete)
	{
		VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_MOVE_DONE, m_id, m_isNeedRetryOpenImg));
	
		setPos(((VfxPointTimeline*)timeline)->getToValue());
		if (m_isNeedRetryOpenImg)
		{
			m_isNeedRetryOpenImg = VFX_FALSE;
			onFocus();
		}
		m_signalMoveDone.emit();
	}
}

void VappWidgetKeyImageViewerCell::posAnimationHdlr(VfxPoint fromValue, VfxPoint toValue)
{
	m_timeline->setTarget(this);
	m_timeline->setFromValue(fromValue);
	m_timeline->setToValue(toValue);
	m_timeline->setDuration(IMAGE_SWITCH_DURATION);
	m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
	m_timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
	m_timeline->start();
}

void VappWidgetKeyImageViewerCell::showImageWithMem(VfxU8 * mem)
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_SHOW_MEM, m_id));

	closeWaiting();

	VfxS32 ret = m_cacher->getImageInfo(m_imgIdx, &m_imgWidth, &m_imgHeight);

	if (ret >= SRV_MEDIACACHE_OK)
	{	
		VfxImageBuffer imageBuf;
		imageBuf.ptr = mem;
	    imageBuf.pitchBytes = m_imgWidth * 2;
	    imageBuf.width = m_imgWidth;
	    imageBuf.height = m_imgHeight;
	    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;

		setSize(m_imgWidth, m_imgHeight);
	    setImgContent(VfxImageSrc(imageBuf));
	    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

		m_isImgBufLock = VFX_TRUE;
		//m_isNeedRetryOpenImg = VFX_FALSE;	//error
	}
	else
	{
		showError();
	}
}

void VappWidgetKeyImageViewerCell::showWaiting()
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_SHOW_DEFAULT, m_id));

	m_waitingIcon->start();
}

void VappWidgetKeyImageViewerCell::closeWaiting()
{
	VAPP_WKIV_LOG((TRC_VAPP_WIDGET_KEY_IMAGE_VIEWER_CLOSE_DEFAULT, m_id));

	m_waitingIcon->stop();
}

void VappWidgetKeyImageViewerCell::showError()
{
	closeWaiting();	

	setResId(IMG_ID_WIDGET_KEY_IMAGE_VIEWER_DEFAULT);
}

#endif


