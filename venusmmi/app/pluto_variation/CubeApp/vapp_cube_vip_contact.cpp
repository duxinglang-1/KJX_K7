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
 *  vapp_cube_vip_contact.cpp
 *
 * Project:
 * --------
 *  3D cube vip contact screen class
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP__

#include "ui_core\base\vfx_base.h"
#include "ui_core\pme\vfx_pme.h"
#include "trc\vadp_app_trc.h"
#include "vcp_frame_effect.h"
#include "vapp_cube_res.h"

#include "CubeApp\vadp_p2v_cube_vip_contact.h"
#include "CubeApp\vadp_v2p_cube_vip_contact.h"
#include "vapp_cube_vip_contact.h"

#ifndef FMGR_MAX_PATH_LEN
#define FMGR_MAX_PATH_LEN (260)
#endif

/***************************************************************************** 
 * VappCubeButton Implement 
 *****************************************************************************/
VappCubeButton::VappCubeButton() : 
	VcpButtonInternal(), 
	m_frmText(NULL), 
	m_frmBg(NULL)
{
}
void VappCubeButton::onInit(void)
{
	VcpButtonInternal::onInit();

	VFX_OBJ_CREATE(m_frmText, VfxTextFrame, this);

	m_frmText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_frmText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_frmText->setAutoResized(VFX_FALSE);
	
}

void VappCubeButton::setText(const VfxWString & string)
{
	m_frmText->bringToFront();
	
	m_frmText->setBounds(getBounds());
	m_frmText->setString(string);
	
	VfxSize size = m_frmText->getFont().measureStr(string.getBuf());
	VfxS32 y = (getBounds().getHeight() - size.height) / 2 - 5;
	m_frmText->setPos(VfxPoint(0, y));
}

void VappCubeButton::setDownResId(const VfxS32 &resId)
{
	if (resId == 0)
	{
		return;
	}
	
	VfxImage *image;
	VFX_OBJ_CREATE(image, VfxImage, this);
	
	image->setResId(resId);
	setBackgroundDown(image, VFX_TRUE);
}

void VappCubeButton::setUpResId(const VfxS32 &resId)
{
	if (resId == 0)
	{
		return;
	}
	
	VfxImage *image;
	VFX_OBJ_CREATE(image, VfxImage, this);
	
	image->setResId(resId);
	setBackgroundUp(image, VFX_TRUE);
}

void VappCubeButton::setBgResId(const VfxS32 &resId)
{
	if (resId == 0)
	{
		return;
	}
	
	VfxImage *image;
	VFX_OBJ_CREATE(image, VfxImage, this);
	image->setResId(resId);

	if (m_frmBg == NULL)
	{
		VFX_OBJ_CREATE(m_frmBg, VfxImageFrame, this);
		m_frmBg->sendToBack();
	}
	
	m_frmBg->setResId(resId);
	m_frmBg->setPos(0, 0);
}


/***************************************************************************** 
 * VappCubeAnimateControl Implement 
 *****************************************************************************/
VappCubeAnimateControl::VappCubeAnimateControl() : 
	m_frmImage(NULL),
	m_frmText(NULL),
	m_timerTick(NULL),						
	m_sStartResId(-1),
	m_nCount(-1),
	m_nDuration(0)
{
}

VappCubeAnimateControl::VappCubeAnimateControl(const VfxS32 &startResId, const VfxS32 &resCount) :
	m_frmImage(NULL),
	m_frmText(NULL),
	m_timerTick(NULL),
	m_sStartResId(startResId),
	m_nCount(resCount),
	m_nDuration(100)
{
}

void VappCubeAnimateControl::onInit(void)
{
	VfxControl::onInit();

	VfxImage *imageBg;
	VFX_OBJ_CREATE(imageBg, VfxImage, this);
	imageBg->setResId(VAPP_CUBE_IMG_VIP_CONTACT_LOADING_BG);
	setContent(imageBg);
	setBounds(VfxRect(VFX_POINT_ZERO, imageBg->getSize()));
	
	// loading animation frame
	VFX_OBJ_CREATE(m_frmImage, VfxImageFrame, this);
	m_frmImage->setResId(m_sStartResId);
	m_frmImage->setPos(VfxPoint(IMG_POS_X, IMG_POS_Y));
	
	VFX_OBJ_CREATE(m_frmText, VfxTextFrame, this);
	m_frmText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_frmText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_frmText->setFont(VFX_FONT_DESC_LARGE);
	m_frmText->setColor(VFX_COLOR_WHITE);
	
	VfxWString strLoading;
	strLoading.loadFromRes(STR_GLOBAL_LOADING);
	m_frmText->setString(strLoading);
	m_frmText->setPos(VfxPoint(TEXT_POS_X, TEXT_POS_Y));
	m_frmText->setBounds(VfxRect(VFX_POINT_ZERO,  VfxSize(TEXT_WIDTH, TEXT_HEIGHT)));
	
}

void VappCubeAnimateControl::startAnimate(void)
{
	if (m_timerTick == NULL)
	{
		VFX_OBJ_CREATE(m_timerTick, VfxTimer, this);
		m_timerTick->setDuration(m_nDuration);
		m_timerTick->m_signalTick.connect(this, &VappCubeAnimateControl::onTimerExpire);
	}
	m_timerTick->start();
}

void VappCubeAnimateControl::stopAnimate(void)
{
	if (m_timerTick != NULL)
	{
		m_timerTick->stop();
		VFX_OBJ_CLOSE(m_timerTick);
	}
}

void VappCubeAnimateControl::setDuration(const VfxU16 & mesc)
{
	m_nDuration = mesc;
}
void VappCubeAnimateControl::setRes(const VfxS32 &startResId, const VfxS32 &resCount)
{
	m_sStartResId = startResId;
	m_nCount = resCount;
}

void VappCubeAnimateControl::onTimerExpire(VfxTimer * source)
{
	VFX_UNUSED(source);
	
	VfxS32 resId = m_frmImage->getResId() - m_sStartResId;
	VfxS32 newId = ++resId % m_nCount;
	
	m_frmImage->setResId(newId + m_sStartResId);
}

/***************************************************************************** 
 * Class VappContactControl
 *****************************************************************************/
VappCubeContactDndImage :: VappCubeContactDndImage() : 
	VappCubeDndImage(),
	m_tlAnchor(NULL),
	m_frmText(NULL),
	m_frmCenterImage(NULL),
	m_ptPrevPos(VFX_POINT_ZERO),
	m_eState(0)
{
}

void VappCubeContactDndImage::onInit()
{
	VappCubeDndImage::onInit();

	VFX_OBJ_CREATE(m_frmText, VfxTextFrame, this);
	m_frmText->setPos(VFX_POINT_ZERO);

	m_frmText->setHidden(VFX_TRUE);
	m_frmText->setBgColor(VFX_COLOR_GREY);
	m_frmText->setColor(VFX_COLOR_SILVER);
	m_frmText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_frmText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_frmText->setFont(VFX_FONT_DESC_SMALL);
	
	// to avoid position shift at its first show.
	setAutoAnimate(VFX_FALSE);
	setIsCached(VFX_TRUE);
	//setIsOpaque(VFX_TRUE);
}

VfxBool VappCubeContactDndImage::onPenInput(VfxPenEvent & event)
{
	// only at edit mode, the dnd image can work.
	if (m_eState == VappCubeVipContactScr::STATE_EDIT)
	{
		return VappCubeDndImage::onPenInput(event);
	}
	// at normal mode, release the pen event to parent.
	else
	{		
		return VFX_FALSE;
	}	
}

void VappCubeContactDndImage::setImage(const VfxS32 &value)
{
	// close forground image.
	VFX_OBJ_CLOSE(m_frmCenterImage);
	
	VfxImage *image = getContent();
    if (image == NULL)
    {
        VfxImage *image;

        VFX_OBJ_CREATE(image, VfxImage, this);
        image->setResId(value);

        setContent(image);
        setBounds(VfxRect(VFX_POINT_ZERO, image->getSize()));
		// Fill the full bounds
		setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    }
	else
	{
		image->setResId(value);
		invalidate();
	}
}

void VappCubeContactDndImage::setCenterImage(const VfxWString &value)
{
    if (m_frmCenterImage == NULL)
    {
        VFX_OBJ_CREATE(m_frmCenterImage, VfxImageFrame, this);
		m_frmCenterImage->setSrc(value);
		m_frmCenterImage->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(IMAGE_WIDTH, IMAGE_HEIGHT)));
		m_frmCenterImage->setPos(VfxPoint(IMAGE_POS_X, IMAGE_POS_Y));
		// Fill the full bounds
		m_frmCenterImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    }
	else
	{
		m_frmCenterImage->setSrc(value);
	}	
}
void VappCubeContactDndImage::setCenterImage(const VfxS32 &value)
{
    if (m_frmCenterImage == NULL)
    {
        VFX_OBJ_CREATE(m_frmCenterImage, VfxImageFrame, this);
		m_frmCenterImage->setResId(value);
		m_frmCenterImage->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(IMAGE_WIDTH, IMAGE_HEIGHT)));
		m_frmCenterImage->setPos(VfxPoint(IMAGE_POS_X, IMAGE_POS_Y));
		// Fill the full bounds
		m_frmCenterImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
		
    }
	else
	{
		m_frmCenterImage->setResId(value);
	}
}

VfxWString VappCubeContactDndImage::getImageSrc(void) const
{
    if (m_frmCenterImage != NULL)
    {
        return m_frmCenterImage->getSrc();
    }

	return VFX_WSTR_NULL;
}

const VfxS32 VappCubeContactDndImage::getImageResId(void) const
{
    if (m_frmCenterImage != NULL)
    {
        return m_frmCenterImage->getResId();
    }

	return 0;
}

void VappCubeContactDndImage::setText(const VfxWString & text)
{
	if (text.isEmpty())
	{
		m_frmText->setHidden(VFX_TRUE);	
		return;
	}
	
	m_frmText->setHidden(VFX_FALSE);
	m_frmText->bringToFront();
	if (m_frmText->getPos() == VFX_POINT_ZERO)
	{
		VfxSize size = m_frmText->getFont().measureStr(text.getBuf());
		VfxU16 h = m_frmCenterImage->getBounds().getHeight() - size.height;

		m_frmText->setOpacity(0.65f);
		VfxU16 w = m_frmCenterImage->getBounds().getWidth();
		m_frmText->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(w, h)));

		//text frame is on the center image.
		VfxPoint imagePt = m_frmCenterImage->getPos();
		m_frmText->setPos(VfxPoint(imagePt.x, imagePt.y + h));
	}
	m_frmText->setString(text);
}


const VfxWString VappCubeContactDndImage::getText(void) const
{
	return m_frmText->getString();
}

void VappCubeContactDndImage::setEditmode(const VfxBool &bEdit)
{
	if (bEdit)
	{
		m_eState = VappCubeVipContactScr::STATE_EDIT;
	}
	else
	{
		m_eState = 0;
	}
}

void VappCubeContactDndImage::startShake(void)
{
	m_ptPrevPos = getPos();
	
    static const VfxS8 offset_table[DRAG_MOVE_OFFSET_TABLE_SIZE][4] = 
    {
        // {x1 offset, y1 offset, x2 offset, y2 offset}
        {-2, -2, 1, 1},
        {0, -2, 0, 2},
        {2, -2, -1, 1},
        {2, 0, -2, 0},
        {2, 2, -1, -1},
        {0, 2, 0, -2},
        {-2, 2, 1, -1},
        {-2, 0, 2, 0}
    };	
    VfxS32 startTime = rand() % DRAG_EFFECT_RANDOM_DELAY;

    if (m_tlAnchor == NULL)
    {
        VFX_OBJ_CREATE(m_tlAnchor, VfxFPointTimeline, this);        
    }
    
    m_tlAnchor->setIsFromCurrent(VFX_TRUE);
    const VfxS8 *offsets = offset_table[(rand() % DRAG_MOVE_OFFSET_TABLE_SIZE)];
    m_tlAnchor->setFromValue(VfxFPoint(0.5F + 0.015F * offsets[0], 0.5F + 0.015F * offsets[1]));
    m_tlAnchor->setToValue(VfxFPoint(0.5F + 0.015F * offsets[2], 0.5F + 0.015F * offsets[3]));
    m_tlAnchor->setDurationTime(SHAKE_DURATION);
    m_tlAnchor->setAutoReversed(VFX_TRUE);
    m_tlAnchor->setStartTime(startTime);
    m_tlAnchor->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_tlAnchor->setTarget(this);
    m_tlAnchor->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_ANCHOR_POINT);

	m_tlAnchor->start();
}

void VappCubeContactDndImage::stopShake(void)
{
    if (m_tlAnchor != NULL)
    {
    	m_tlAnchor->stop();
		
        VFX_OBJ_CLOSE(m_tlAnchor);
    }
	
	setAnchor(VfxFPoint(0.5F, 0.5f));
}

const VfxPoint &VappCubeContactDndImage::getPrevPos(void) const
{
	return m_ptPrevPos;
}

void VappCubeContactDndImage::setPrevPos(const VfxPoint & point)
{
	m_ptPrevPos = point;
}

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global function
 *****************************************************************************/
VappContactControl::VappContactControl() : 
	m_frmTitle(NULL),
	m_frmImage(NULL),
	m_Animation(NULL),
	m_tlTrans(NULL),
	m_tlPoint(NULL)
{
	for (VfxU8 i = 0; i < BTN_TOTAL; i++)
	{
		m_imgBtnDown[i] = NULL;
		m_imgBtnUp[i] = NULL;
		m_cpBtn[i] = NULL;
	}	
}

void VappContactControl::onInit()
{
	VfxControl::onInit();
	
	setAnchor(VfxFPoint(0.5, 0.5));
	setAutoAnimate(VFX_TRUE);
	setIsCached(VFX_TRUE);
	//setIsOpaque(VFX_TRUE);
	
	// Background image
	VfxImageFrame *bgImage;
	VFX_OBJ_CREATE(bgImage, VfxImageFrame, this);
	bgImage->setResId(VAPP_CUBE_IMG_VIP_CONTACT_ZOOM_IN_BG);
	setBounds(VfxRect(VFX_POINT_ZERO, bgImage->getBounds().size));
	
	// Button
	configCustomButton();

	VfxU8 i;

	for (i = 0; i < BTN_TOTAL; i++)
	{
		VFX_OBJ_CREATE(m_cpBtn[i], VappCubeButton, this);
		m_cpBtn[i]->setUpResId(m_tblBtnConfig[i].imgUp);
		m_cpBtn[i]->setDownResId(m_tblBtnConfig[i].imgDown);		
		m_cpBtn[i]->setBgResId(m_tblBtnConfig[i].imgBg);
		
		m_cpBtn[i]->m_eventUp.connect(this, m_tblBtnConfig[i].handler);
	}
	
	VfxS32 x, y;
	m_cpBtn[BTN_CALL]->setPos(VfxPoint(BTN_CALL_X, BTN_CALL_Y));
	m_cpBtn[BTN_SMS]->setPos(VfxPoint(BTN_SMS_X, BTN_SMS_Y));
	m_cpBtn[BTN_TRASH]->setPos(VfxPoint(BTN_TRASH_X, BTN_TRASH_Y));
	m_cpBtn[BTN_CLOSE]->setPos(VfxPoint(BTN_CLOSE_X, BTN_CLOSE_Y));

	// Title
	VFX_OBJ_CREATE(m_frmTitle, VfxTextFrame, this);
	
	m_frmTitle->setPos(VfxPoint(m_cpBtn[BTN_TRASH]->getBounds().getMaxX(), TXT_TITLE_Y));
	
	VfxS32 w = getBounds().getWidth() -
			   m_cpBtn[BTN_TRASH]->getBounds().getWidth() -
			   m_cpBtn[BTN_CLOSE]->getBounds().getWidth();

	m_frmTitle->setBounds(VfxRect(0, 0, w, m_cpBtn[BTN_TRASH]->getBounds().getHeight()));
	m_frmTitle->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_frmTitle->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_frmTitle->setAutoResized(VFX_FALSE);
	
	// Center Image
	VFX_OBJ_CREATE(m_frmImage, VfxImageFrame, this);
	m_frmImage->setAnchor(VfxFPoint(0.5, 0.5));
	m_frmImage->setIsCached(VFX_TRUE);
	
	x = CENTER_IMAGE_X + CENTER_IMAGE_WIDTH / 2;
	y = CENTER_IMAGE_Y + CENTER_IMAGE_HEIGHT / 2 ;
	m_frmImage->setPos(VfxPoint(x, y));

}

void VappContactControl::configCustomButton(void)
{
	// Add custom button's parameters
	m_tblBtnConfig[BTN_CALL].imgUp = VAPP_CUBE_IMG_VIP_CONTACT_CALL_BTN_UP;
	m_tblBtnConfig[BTN_CALL].imgDown = VAPP_CUBE_IMG_VIP_CONTACT_CALL_BTN_DOWN;
	m_tblBtnConfig[BTN_CALL].imgBg = 0;
	m_tblBtnConfig[BTN_CALL].imgDisable = VAPP_CUBE_IMG_VIP_CONTACT_CALL_BTN_DISABLE;
	m_tblBtnConfig[BTN_CALL].handler = &VappContactControl::onBtnCall;

	m_tblBtnConfig[BTN_SMS].imgUp = VAPP_CUBE_IMG_VIP_CONTACT_SMS_BTN_UP;
	m_tblBtnConfig[BTN_SMS].imgDown = VAPP_CUBE_IMG_VIP_CONTACT_SMS_BTN_DOWN;
	m_tblBtnConfig[BTN_SMS].imgBg = 0;
	m_tblBtnConfig[BTN_SMS].imgDisable = VAPP_CUBE_IMG_VIP_CONTACT_SMS_BTN_DISABLE;
	m_tblBtnConfig[BTN_SMS].handler = &VappContactControl::onBtnSms;

	m_tblBtnConfig[BTN_TRASH].imgUp = VAPP_CUBE_IMG_VIP_CONTACT_TRASH_BTN_UP;
	m_tblBtnConfig[BTN_TRASH].imgBg = VAPP_CUBE_IMG_VIP_CONTACT_TRASH_BTN_UP;
	m_tblBtnConfig[BTN_TRASH].imgDown = VAPP_CUBE_IMG_VIP_CONTACT_HILITE_EFFECT;
	m_tblBtnConfig[BTN_TRASH].imgDisable = 0;
	m_tblBtnConfig[BTN_TRASH].handler = &VappContactControl::onBtnTrash;

	m_tblBtnConfig[BTN_CLOSE].imgUp = 0;
	m_tblBtnConfig[BTN_CLOSE].imgBg = VAPP_CUBE_IMG_VIP_CONTACT_CLOSE;
	m_tblBtnConfig[BTN_CLOSE].imgDown = VAPP_CUBE_IMG_VIP_CONTACT_HILITE_EFFECT;
	m_tblBtnConfig[BTN_CLOSE].imgDisable = 0;
	m_tblBtnConfig[BTN_CLOSE].handler = &VappContactControl::onBtnClose;
}

void VappContactControl::setTitle(const VfxWString &title)
{
	VfxRect bounds = m_frmTitle->getBounds();
	// set string will reset the bounds
	m_frmTitle->setString(title);
	VfxSize size = m_frmTitle->getFont().measureStr(title.getBuf());
	VfxS32 newY = (bounds.getHeight() - size.height)/2 + TXT_TITLE_Y;
	VfxPoint oldPoint = m_frmTitle->getPos();
	m_frmTitle->setPos(VfxPoint(oldPoint.x, newY));
}

const VfxWString &VappContactControl::getTitle(void) const
{
	return m_frmTitle->getString();
}

void VappContactControl::enableBtn(const VappContactControl::Button & btn, const VfxBool & bEnable)
{
	VFX_ASSERT(btn >= 0 && btn <= BTN_TOTAL);

	if (bEnable)
	{
		m_cpBtn[btn]->setUpResId(m_tblBtnConfig[btn].imgUp);
		m_cpBtn[btn]->setDownResId(m_tblBtnConfig[btn].imgDown);
	}
	else
	{
		m_cpBtn[btn]->setUpResId(m_tblBtnConfig[btn].imgDisable);
	}
	
	m_cpBtn[btn]->disable(bEnable == VFX_FALSE);
}

void VappContactControl::setImage(const VfxS32 &resId)
{
	m_frmImage->setResId(resId);
	// The iamge size is fixed.
	m_frmImage->setBounds(VfxRect(VFX_POINT_ZERO, 
								  VfxSize(CENTER_IMAGE_WIDTH, CENTER_IMAGE_HEIGHT)));
	m_frmImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
}

void VappContactControl::setImage(const VfxWString &src)
{
	m_frmImage->setSrc(src);
	// The iamge size is fixed.
	m_frmImage->setBounds(VfxRect(VFX_POINT_ZERO, 
								  VfxSize(CENTER_IMAGE_WIDTH, CENTER_IMAGE_HEIGHT)));
	m_frmImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
}

void VappContactControl::onBtnCall(void)
{
	m_signalAction.emit(BTN_CALL);
}

void VappContactControl::onBtnSms(void)
{
	m_signalAction.emit(BTN_SMS);
}

void VappContactControl::onRotateStop(VfxBaseTimeline *timeline, VfxBool stop)
{
	VFX_UNUSED(stop);
	
	if (timeline == m_tlTrans)
	{
		m_cpBtn[BTN_TRASH]->bringToFront();
		
		m_tlPoint->setTarget(m_frmImage);
		m_tlPoint->setFromValue(m_frmImage->getPos());
		
		VfxPoint point = m_cpBtn[BTN_TRASH]->getPos();
		
		point.x += (m_cpBtn[BTN_TRASH]->getBounds()).getWidth() / 2;
		point.y += (m_cpBtn[BTN_TRASH]->getBounds()).getWidth() / 2;
		
		m_tlPoint->setToValue(point);
		m_tlPoint->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
		m_tlPoint->setDurationTime(CONTACT_ROTATE_TIME);

		m_tlPoint->m_signalStopped.connect(this, &VappContactControl::onRotateStop);
		m_tlPoint->start();
	}
	else if (timeline == m_tlPoint)
	{
		m_signalAction.emit(BTN_TRASH);
	}
}
void VappContactControl::onBtnTrash(void)
{
	VfxTransform trans;

	if (m_tlTrans == NULL)
	{
		VFX_OBJ_CREATE(m_tlTrans, VfxTransformTimeline, this);
	}	

	// don't allow to press button when trash action starts.
	enableBtn(BTN_CALL, VFX_FALSE);
	enableBtn(BTN_SMS, VFX_FALSE);
	enableBtn(BTN_CLOSE, VFX_FALSE);
	
	m_tlTrans->m_signalStopped.connect(this, &VappContactControl::onRotateStop);
	m_tlTrans->setTarget(m_frmImage);

	trans.init(VRT_TRANSFORM_TYPE_AFFINE);

	m_tlTrans->setFromValue(trans);

	trans.data.affine.rz = 6.28f;	// just two circle.
	trans.data.affine.sx = 0.1f;
	trans.data.affine.sy = 0.1f;
 
	m_tlTrans->setToValue(trans);
	m_tlTrans->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
	m_tlTrans->setDurationTime(CONTACT_ROTATE_TIME);
	
	if (m_Animation == NULL)
	{
		VFX_OBJ_CREATE(m_Animation, VfxAnimation, this);
	}
	
	m_Animation->addChild(m_tlTrans);

	if (m_tlPoint == NULL)
	{
		VFX_OBJ_CREATE(m_tlPoint, VfxPointTimeline, this);
	}
	
	m_tlPoint->setTarget(m_frmImage);
	m_tlPoint->setFromValue(m_frmImage->getPos());

	VfxPoint point = m_cpBtn[BTN_TRASH]->getPos();
	
	point.x += (m_cpBtn[BTN_TRASH]->getBounds()).getWidth() / 2;
	point.y -= 10;
	
	m_tlPoint->setToValue(point);
	m_tlPoint->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
	m_tlPoint->setDurationTime(CONTACT_ROTATE_TIME);
	m_frmImage->bringToFront();

	// after time-line, the property won't be applied to frame
	m_frmImage->setPos(point);
	
	m_Animation->addChild(m_tlPoint);
	m_Animation->start();
}

void VappContactControl::onBtnClose(void)
{
	m_signalAction.emit(BTN_CLOSE);
}

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappContactNumberFrame
 *****************************************************************************/
VappContactNumberFrame::VappContactNumberFrame() :
	m_lstNumber(NULL),
	m_frmTitle(NULL),
	m_cpBtnSwitch(NULL)
{
}

void VappContactNumberFrame::onInit()
{
	VfxControl::onInit();
	
	setIsCached(VFX_TRUE);
	//setIsOpaque(VFX_TRUE);
	setAnchor(VfxFPoint(0.5, 0.5));

	VfxImageFrame *frame;
	VFX_OBJ_CREATE(frame, VfxImageFrame, this);
	frame->setResId(VAPP_CUBE_IMG_VIP_CONTACT_LIST_BG);
	setBounds(frame->getBounds());
	
	// switch button
	VFX_OBJ_CREATE(m_cpBtnSwitch, VappCubeButton, this);

	VfxImage *btnDownImage;
	
	VFX_OBJ_CREATE(btnDownImage, VfxImage, this);
	btnDownImage->setResId(VAPP_CUBE_IMG_VIP_CONTACT_HILITE_EFFECT);
	m_cpBtnSwitch->setBackgroundDown(btnDownImage, VFX_TRUE);
	m_cpBtnSwitch->setBgResId(VAPP_CUBE_IMG_VIP_CONTACT_SWITCH_BTN_UP);

	// register button handler.
	m_cpBtnSwitch->m_eventUp.connect(getParentControl(), &VappCubeVipContactScr::onSwitchNotify);
	m_cpBtnSwitch->setPos(VfxPoint(BTN_SWITCH_X, BTN_SWITCH_Y));
	
	// text title
	VFX_OBJ_CREATE(m_frmTitle, VfxTextFrame, this);

	VfxS32 x;
	x = getBounds().getWidth() - btnDownImage->getSize().width * 2;
	m_frmTitle->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(x, m_cpBtnSwitch->getBounds().getHeight())));
	m_frmTitle->setPos(VfxPoint(TITLE_POS_X + m_cpBtnSwitch->getBounds().getWidth(), TITLE_POS_Y));
	m_frmTitle->setColor(VFX_COLOR_WHITE);
	m_frmTitle->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_frmTitle->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	
	// number list
	VFX_OBJ_CREATE_EX(m_lstNumber, VappListCtrl, this, (VFX_FALSE));
	m_lstNumber->setHighlightRes(VAPP_CUBE_IMG_VIP_CONTACT_LIST_HILITE);
	
	VfxRect rect = getBounds();

	// number list
	m_lstNumber->setFont(VFX_FONT_DESC_LARGE);
	m_lstNumber->setBounds(VfxRect(VfxPoint(0, 0),
									VfxSize(FRM_LIST_WIDTH, rect.getHeight() - TITLE_HEIGHT)));

	m_lstNumber->setPos(VfxPoint(FRM_LIST_X, FRM_LIST_Y));
	m_lstNumber->m_signalSelChange.connect(getParentControl(), &VappCubeVipContactScr::onNumberSelect);
}


void VappContactNumberFrame::setTitle(const VfxWString &title)
{
	VfxRect oldBounds = m_frmTitle->getBounds();

	m_frmTitle->setString(title);

	VfxPoint oldPoint = m_frmTitle->getPos();
	VfxSize size = m_frmTitle->getFont().measureStr(title.getBuf());
	VfxS32 newY = (oldBounds.getHeight() - size.height) / 2;
	m_frmTitle->setPos(VfxPoint(oldPoint.x, oldPoint.y + newY));
}

void VappContactNumberFrame::setCurrSel(const VfxU8 & nSel)
{
	m_lstNumber->setCurrSel(nSel);
}
void VappContactNumberFrame::insertContent(const VfxWString &string, const VfxU32 flag)
{
	VappListCtrl::LC_ITEM item;

	item.string = string;
	item.imgId = vadp_v2p_vip_contact_get_number_res(flag);
	item.iItemHeight = LIST_ITEM_HEIGHT;
	item.iImageWidth = LIST_ITEM_HEIGHT;
	item.userData = (void*)flag;
	
	m_lstNumber->insertItem(item);
}


/***************************************************************************** 
 * Class VappCubeVipContactScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VfxCubeVipContactScrClassName", VappCubeVipContactScr, VappCubeScr);
VappCubeVipContactScr::VappCubeVipContactScr() : 
	m_animLoading(NULL),
	m_Animate(NULL),
	m_tlRect(NULL),
	m_tlPos(NULL),
	m_tlTransform(NULL),
	m_frmNumList(NULL),
	m_frmCurrCont(NULL),
	m_frmEffectCont(NULL),
	m_frmEffectList(NULL),
	m_tmLongPress(NULL),
	m_tmRefresh(NULL),
	m_btnEditDone(NULL),
	m_imgBg(NULL),
	m_imgLoading(NULL),
	m_txtLoading(NULL),
	m_pSetting(NULL),
	m_frmHiliteEffect(NULL),
	m_bLongPress(VFX_FALSE),
	m_uOldIdx(0xFFFF),
	m_bSwitching(VFX_FALSE)
{
	m_struContactNumber.flag = 0;
	for (VfxS32 i = 0; i < TOTAL_CONTACTS; i++)
	{
		m_dndImage[i] = NULL;
	}
}

void VappCubeVipContactScr::onInit()
{
	VappCubeScr::onInit();

	// set background image
	
	VfxImageFrame *bgFrame;
	VFX_OBJ_CREATE(bgFrame, VfxImageFrame, this);
	bgFrame->setResId(VAPP_CUBE_IMG_VIP_CONTACT_BG);
	//bgFrame->setIsCached(VFX_TRUE);
	//bgFrame->setIsOpaque(VFX_TRUE);
	
	VfxU8 i;
	
	for (i = 0; i < TOTAL_CONTACTS; i++)
	{
		VFX_OBJ_CREATE(m_dndImage[i], VappCubeContactDndImage, this);
	}
	
	//Save elemt size.
	VfxImage *image;
	VFX_OBJ_CREATE(image, VfxImage, NULL);
	image->setResId(VAPP_CUBE_IMG_VIP_CONTACT_NORMAL);
	m_sizeElem = image->getSize();
	VFX_OBJ_CLOSE(image);

	m_pSetting = (Setting *)vadp_v2p_vip_contact_get_setting();
	m_pSetting->active = 0xFF;
			
	if (!vadp_v2p_contact_is_available())
	{
		m_pSetting->state = STATE_INVALID;
		
		// Loading screen
		VfxS32 count = VAPP_CUBE_IMG_VIP_CONTACT_LOADING_CNT - VAPP_CUBE_IMG_VIP_CONTACT_LOADING_0;
		VFX_OBJ_CREATE_EX(m_animLoading, 
					   	  VappCubeAnimateControl, 
					      this, 
					      (VAPP_CUBE_IMG_VIP_CONTACT_LOADING_0, count));

		m_animLoading->setPos(VfxPoint(LOADING_POS_X, LOADING_POS_Y));
		m_animLoading->startAnimate();
		
    	// Refresh timer will check whether the contact is availble again and again.
		VFX_OBJ_CREATE(m_tmRefresh, VfxTimer, this);
	    m_tmRefresh->setStartDelay(VCP_BUTTON_TIMER_START_DELAY_LONGPRESS);
	    m_tmRefresh->setDuration(2000);
	    m_tmRefresh->m_signalTick.connect(this, &VappCubeVipContactScr::onTimerExpire);
		m_tmRefresh->start();		
	}
	else
	{
		// reset the state
		m_pSetting->state = STATE_IDLE;
	}
	
    VFX_OBJ_CREATE(m_tmLongPress, VfxTimer, this);
    m_tmLongPress->setStartDelay(VCP_BUTTON_TIMER_START_DELAY_LONGPRESS);
    m_tmLongPress->setDuration(0);
    m_tmLongPress->m_signalTick.connect(this, &VappCubeVipContactScr::onTimerExpire);
		
	for (i = 0; i < TOTAL_CONTACTS; i++)
	{
		// register dnd event handler
        m_dndImage[i]->m_signalDrag.connect(this, &VappCubeVipContactScr::onContactDrag);
        m_dndImage[i]->m_signalMove.connect(this, &VappCubeVipContactScr::onContactMove);
		m_dndImage[i]->m_signalAbort.connect(this, &VappCubeVipContactScr::onContactAbort);
		m_dndImage[i]->m_signalDrop.connect(this, &VappCubeVipContactScr::onContactDrop);

	}
	updatePostion();
	updateContent();
}


void VappCubeVipContactScr::onDeinit()
{
	if (m_pSetting->state == STATE_EDIT)
	{
		onBtnEditDown();
	}
	else
	{
		vadp_v2p_vip_contact_save_setting();
	}	
	
    VappCubeScr::onDeinit();
}

void VappCubeVipContactScr::updatePostion(void)
{
	// Matrix position 
	//DndImage's anchor is at 0.5 position

	
	VfxS8 left = (getBounds().getWidth() - HORI_MARGIN) / 2 -  m_sizeElem.width/ 2;
	VfxS8 top = MATRIX_TOP_Y_POS + m_sizeElem.height / 2;
	
	for (VfxU8 i = 0; i < TOTAL_CONTACTS; i++)
	{
		m_dndImage[i]->setPos(VfxPoint(left + (i % 2) * (HORI_MARGIN + m_sizeElem.width), 
										top + (i / 2) * (VERT_MARTIN + m_sizeElem.width)));
		
		m_posArray[i] = m_dndImage[i]->getPos();
	}
}

void VappCubeVipContactScr::onContactDrag(VappCubeDndImage *image, VfxPenEvent &event)
{
	VFX_UNUSED(event);
	
	VappCubeContactDndImage *dndImage = (VappCubeContactDndImage *)image;

	dndImage->stopShake();
	
	image->bringToFront();
	m_ptPrevPos = image->getPos();
}

void VappCubeVipContactScr::onContactMove(VappCubeDndImage *image, VfxPenEvent &event)
{
	VfxRect rect = getAppBounds();

	// alignment the new position for the moved frame.
	VfxPoint point = image->getPos();
	point.x += event.getRelPos(this).x - event.getRelPrevPos(this).x;
	point.y += event.getRelPos(this).y - event.getRelPrevPos(this).y;

	VfxS32 xMin = rect.getMinX() + image->getBounds().getWidth() / 2;
	VfxS32 yMin = rect.getMinY() + image->getBounds().getHeight() / 2;
	
	VfxS32 xMax = rect.getMaxX() - image->getBounds().getWidth() / 2;
	VfxS32 yMax = rect.getMaxY() - image->getBounds().getHeight() / 2;
	
	point.x = point.x < xMin ? xMin : point.x;
	point.y = point.y < yMin ? yMin : point.y;

	point.x = point.x > xMax ? xMax : point.x;
	point.y = point.y > yMax ? yMax : point.y;
	
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
	image->setPos(point);
	
	VfxAutoAnimate::commit();

}

void VappCubeVipContactScr::onContactDrop(VappCubeDndImage *image, VfxPenEvent &event)
{
	VFX_UNUSED(event);
	
	if (m_tmLongPress->getIsEnabled())
	{
		m_tmLongPress->stop();
	}
	
	VfxPoint point = image->getPos();
	VfxPoint currPt;
	
	VfxFrame *frmNear = NULL;
	VfxS32 x, y;

	// locate the nearest dnd image.
	for (VfxU8 i = 0; i < TOTAL_CONTACTS; i++)
	{
		//don't compare with itself
		if (m_dndImage[i] == image)
		{		
			if (frmNear != NULL) 
			{
				break;
			}
			
			continue;
		}
		
		if (frmNear == NULL)
		{
			currPt = m_dndImage[i]->getPrevPos();
		
			x = VFX_ABS(currPt.x - point.x);
			y = VFX_ABS(currPt.y - point.y);

			if (VfxCubeSqrt(x*x + y*y) < SWAP_THRESHHOLD)
			{		
				frmNear = m_dndImage[i];
			}
		}

	}
	
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
	VfxAutoAnimate::setDuration(2000);
	VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
	image->setOpacity(1.0f);

	VappCubeContactDndImage *dndMovingImage = (VappCubeContactDndImage *)image;
	VappCubeContactDndImage *dndNearFrame = (VappCubeContactDndImage *)frmNear;
	
	// If there is nearest frame, swap the two frame's position
	if (frmNear != NULL)
	{
		dndNearFrame->stopShake();
		
		dndMovingImage->setPos(frmNear->getPos());
		frmNear->setPos(m_ptPrevPos);
		
		dndNearFrame->startShake();

		dndMovingImage->startShake();
		// Swap the two store index.
		const VfxU16 currIdx = lodateFrameIndex(dndMovingImage);
		const VfxU16 movedIdx = lodateFrameIndex(dndNearFrame);

		VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_EDIT_SWAP, currIdx, movedIdx);
		
		vfxSwap<VfxU16>(m_pSetting->index[currIdx], m_pSetting->index[movedIdx]);
		vfxSwap<VappCubeContactDndImage *>(m_dndImage[currIdx], m_dndImage[movedIdx]);
		
		//vadp_v2p_vip_contact_save_setting();
	}
	// No swap, Goback to its original position
	else
	{
		VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_NO_SWAP);
		image->setPos(m_ptPrevPos);
		dndMovingImage->startShake();
	}
	
	VfxAutoAnimate::commit();
	
}

const VfxU16 VappCubeVipContactScr::lodateFrameIndex(const VappCubeContactDndImage *frame)
{
	for (VfxU8 i = 0; i < TOTAL_CONTACTS; i++)
	{
		//don't compare with itself
		if (m_posArray[i] == frame->getPrevPos())
		{
			return i;
		}
	}
	
	VFX_ASSERT(!"Can't lodate");
	return 0xFF;
}

void VappCubeVipContactScr::onContactAbort(VappCubeDndImage *image, VfxPenEvent &event)
{
	VFX_UNUSED(image);
	VFX_UNUSED(event);
	
	if (m_tmLongPress->getIsEnabled())
	{
		m_tmLongPress->stop();
	}
}

void VappCubeVipContactScr::onSwitchNotify(void)
{
	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_SWITCH_NOFITY);
	if (m_bSwitching)
	{
		return;
	}
	
	m_frmEffectList->applyEffect(m_frmNumList, 
							 VCP_EFFECT_FLIP, 
							 CONTACT_ROTATE_TIME, 
							 VCP_EFFECT_DIRECTION_FROM_LEFT,
							 VFX_TRUE);
	
	m_frmCurrCont->setHidden(VFX_FALSE);
	m_frmEffectCont->applyEffect(m_frmCurrCont, 
						 VCP_EFFECT_FLIP, 
						 CONTACT_ROTATE_TIME, 
						 VCP_EFFECT_DIRECTION_FROM_LEFT);
	m_frmEffectCont->m_signalFinished.connect(this, &VappCubeVipContactScr::onRotateContFinish);
	
	m_bSwitching = VFX_TRUE;
}

void VappCubeVipContactScr::onNumberSelect(void *user_data)
{
	if (user_data == NULL)
	{
		return;
	}

	const VfxU32 flag  = (VfxU32)user_data;
	const VfxWChar *buffer;
	
	if (flag & CONTACT_NUMBER_MASK_HOME)
	{
		buffer = m_struContactNumber.home.getBuf();
	}
	else if (flag & CONTACT_NUMBER_MASK_OFFICE)
	{
		buffer = m_struContactNumber.office.getBuf(); 
	}
	else if (flag & CONTACT_NUMBER_MASK_MOBILE)
	{
		buffer = m_struContactNumber.mobile.getBuf();
	}
	else if (flag & CONTACT_NUMBER_MASK_FAX)
	{
		buffer = m_struContactNumber.fax.getBuf();
	}
	else
	{
		VFX_ASSERT(!"NO Number");
	}

	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_NUM_SELECT, flag);
	
	vfxPostInvoke2(this, &VappCubeVipContactScr::makeCall, buffer, flag);
}

void VappCubeVipContactScr::onUpdateCont(const VfxU16 &index)
{
	VFX_ASSERT(index < TOTAL_CONTACTS);

	// close the active frame, because the current contact may be not the current one
	if (m_pSetting->active == index)
	{
		VFX_OBJ_CLOSE(m_frmCurrCont);
		VFX_OBJ_CLOSE(m_frmNumList);
	}

	m_dndImage[index]->setImage(VAPP_CUBE_IMG_VIP_CONTACT_NORMAL);
	if (m_pSetting->index[index] != INVALID_CONT_INDEX)
	{
		VfxWChar buffer[(FMGR_MAX_PATH_LEN + 1)];
		VfxWString strPath;
		VfxS32 resId;

		S8 ret = vadp_v2p_vip_contact_get_image_path(m_pSetting->index[index], 
													 buffer, 
													 (FMGR_MAX_PATH_LEN + 1));
		
		VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_UPDATE_CONT, index, ret);
		
		if (ret != 0)
		{
			// check the file path.
			vfx_sys_file_handle handle = vfx_sys_file_open(buffer, VFX_UC_SYS_FILE_OPEN_MODE_READ);
			if (handle != NULL)
			{
			    vfx_sys_file_close(handle);				
			    strPath.loadFromMem(buffer);
			    m_dndImage[index]->setCenterImage(strPath);
		        }		
			else
			{
			    m_dndImage[index]->setCenterImage(VAPP_CUBE_IMG_VIP_CONTACT_DEFAULT);	
			}
		}		
		else if (vadp_v2p_vip_contact_get_image_id(m_pSetting->index[index], &resId))
		{
			m_dndImage[index]->setCenterImage(resId);
			// make the image fill all the bounds
		}
		else
		{
			m_dndImage[index]->setCenterImage(VAPP_CUBE_IMG_VIP_CONTACT_DEFAULT);
		}
		m_dndImage[index]->setBounds(VfxRect(VFX_POINT_ZERO, m_sizeElem));

		// don't show text on small screen size
#ifdef __MMI_MAINLCD_240X320__
		m_dndImage[index]->setText(VFX_WSTR_NULL);
#else
		m_dndImage[index]->setText(getText(index));
#endif
	}
	else
	{
		m_dndImage[index]->setText(VFX_WSTR_NULL);
		m_dndImage[index]->setCenterImage(VAPP_CUBE_IMG_VIP_CONTACT_DEFAULT);
	}
}

void VappCubeVipContactScr::createListScreen()
{
	VFX_OBJ_CREATE(m_frmNumList, VappContactNumberFrame, this);
	
	VfxRect bound = m_frmCurrCont->getBounds();
	// float from the buttom of the contact control.
	m_frmNumList->setBounds(bound);
	m_frmNumList->setPos(m_frmCurrCont->getPos());
	m_frmNumList->setTitle(m_frmCurrCont->getTitle());
	
	// Totally four numbers right now
	if (!m_struContactNumber.mobile.isEmpty())
	{
		m_frmNumList->insertContent(m_struContactNumber.mobile, CONTACT_NUMBER_MASK_MOBILE);
	}	
	if (!m_struContactNumber.home.isEmpty())
	{
		m_frmNumList->insertContent(m_struContactNumber.home, CONTACT_NUMBER_MASK_HOME);
	}
	if (!m_struContactNumber.office.isEmpty())
	{
		m_frmNumList->insertContent(m_struContactNumber.office, CONTACT_NUMBER_MASK_OFFICE);
	}
	if (!m_struContactNumber.fax.isEmpty())
	{
		m_frmNumList->insertContent(m_struContactNumber.fax, CONTACT_NUMBER_MASK_FAX);
	}
	
	m_frmNumList->setCurrSel(0);
}

void VappCubeVipContactScr::createContactScreen()
{
	if (m_frmCurrCont == NULL)
	{
		VFX_OBJ_CREATE(m_frmCurrCont, VappContactControl, this);

		m_frmCurrCont->m_signalAction.connect(this, &VappCubeVipContactScr::actionHandler);
		m_frmCurrCont->setAutoAnimate(VFX_FALSE);
	}

	VfxWString strTitle = m_dndImage[m_pSetting->active]->getText();
	
	if (!strTitle.isEmpty())
	{
		m_frmCurrCont->setTitle(strTitle);
	}
	else
	{
		m_frmCurrCont->setTitle(getText(m_pSetting->active));
	}

	// the DndImage's center image will be the contact's image
	VfxS32 resId = m_dndImage[m_pSetting->active]->getImageResId();

	if (resId != 0)
	{
		m_frmCurrCont->setImage(resId);
	}
	else
	{
		m_frmCurrCont->setImage(m_dndImage[m_pSetting->active]->getImageSrc());
	}
	
	m_struContactNumber.flag = 0;
	loadNumber(m_pSetting->active);

	//Lock all button at create time.
		m_frmCurrCont->enableBtn(VappContactControl::BTN_CALL, VFX_FALSE);
		m_frmCurrCont->enableBtn(VappContactControl::BTN_SMS, VFX_FALSE);
	m_frmCurrCont->enableBtn(VappContactControl::BTN_TRASH, VFX_FALSE);
	m_frmCurrCont->enableBtn(VappContactControl::BTN_CLOSE, VFX_FALSE);
	
	VfxRect prevBounds = m_frmCurrCont->getBounds();
	m_frmCurrCont->setPos(m_dndImage[m_pSetting->active]->getPos());

	VfxTransform trans = m_frmCurrCont->getTransform();
	trans.type = VRT_TRANSFORM_TYPE_AFFINE;

	VfxU16 width = m_dndImage[m_pSetting->active]->getBounds().getWidth();
	VfxFloat scale =  (VfxFloat)width / prevBounds.getWidth();
	
	trans.data.affine.sx = scale;
	trans.data.affine.sy = scale;
	
	m_frmCurrCont->setTransform(trans);
	
	if (m_Animate == NULL)
	{
		VFX_OBJ_CREATE(m_Animate, VfxAnimation, this);
	}

	// Anchor is at (0.5, 0.5), make it at the center of the AppBounds.
	VfxS32 x = CONTACT_CONTROL_POS_X + m_frmCurrCont->getBounds().getWidth() / 2;
	VfxS32 y = CONTACT_CONTROL_POS_Y + m_frmCurrCont->getBounds().getHeight() / 2;
		
	if (m_tlPos == NULL)
	{
		VFX_OBJ_CREATE(m_tlPos, VfxPointTimeline, this);
	}
	
	m_tlPos->setTarget(m_frmCurrCont);
	m_tlPos->setFromValue(m_frmCurrCont->getPos());
	m_tlPos->setToValue(VfxPoint(x, y));
	m_tlPos->setDurationTime(CONTACT_ROTATE_TIME);
	m_tlPos->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);

	m_Animate->addChild(m_tlPos);

	m_frmCurrCont->setPos(VfxPoint(x, y));
	
	m_frmCurrCont->setOpacity(1.0f);
	
	trans = m_frmCurrCont->getTransform();
	trans.type = VRT_TRANSFORM_TYPE_AFFINE;
	trans.data.affine.rz = 6.28f; // 2 pai
		
	trans.data.affine.sx = 1.0f;
	trans.data.affine.sy = 1.0f;
	
	if (m_tlTransform == NULL)
	{
		VFX_OBJ_CREATE(m_tlTransform, VfxTransformTimeline, this);
		m_tlTransform->m_signalStopped.connect(this, &VappCubeVipContactScr::onContactCreateFinish);
	}

	m_tlTransform->setTarget(m_frmCurrCont);
	m_tlTransform->setFromValue(m_frmCurrCont->getTransform());
	m_tlTransform->setToValue(trans);
	m_tlTransform->setDurationTime(CONTACT_ROTATE_TIME);
	m_tlTransform->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);

	m_Animate->addChild(m_tlTransform);

	m_frmCurrCont->setTransform(trans);
	m_Animate->start();

	deregDefaultPageAct(this);
}

void VappCubeVipContactScr::showEditScreen(void)
{
    // show edit done bar.
    vrt_size_struct main_screen_size;
    VfxColorTypeEnum main_screen_color_format;
    
	// Button Edit Down will be at the place of shortcut bar.
	VFX_OBJ_CREATE(m_btnEditDone, VappCubeButton, this);
	
    vrt_sys_get_main_screen_info(
        &main_screen_size, 
        &main_screen_color_format);

	// get button size
	VfxImage *image;
	VFX_OBJ_CREATE(image, VfxImage, this);
	image->setResId(VAPP_CUBE_IMG_VIP_CONTACT_BTN_DONE_DOWN);
	VfxSize btnSize = image->getSize();
	VFX_OBJ_CLOSE(image);

	m_btnEditDone->setPos(VfxPoint(0, main_screen_size.height - btnSize.height));
	
	m_btnEditDone->setDownResId(VAPP_CUBE_IMG_VIP_CONTACT_BTN_DONE_DOWN);
	m_btnEditDone->setUpResId(VAPP_CUBE_IMG_VIP_CONTACT_BTN_DONE_UP);
	m_btnEditDone->m_eventUp.connect(this, &VappCubeVipContactScr::onBtnEditDown);

	VfxWString strDone;
	strDone.loadFromRes(STR_GLOBAL_DONE);
	m_btnEditDone->setText(strDone);
}

void VappCubeVipContactScr::onRotateContFinish(VfxFrame *frame, VfxBool finish)
{
	VFX_UNUSED(finish);
	m_bSwitching = VFX_FALSE;
	
	if (frame == m_frmCurrCont)
	{
		m_frmEffectCont->m_signalFinished.disconnect(this, 
													 &VappCubeVipContactScr::onRotateContFinish);
		m_frmNumList->setHidden(VFX_TRUE);
	}
	else if (frame == m_frmNumList)
	{
		m_frmEffectList->m_signalFinished.disconnect(this, 
													 &VappCubeVipContactScr::onRotateContFinish);
		m_frmCurrCont->setHidden(VFX_TRUE);
	}
}

void VappCubeVipContactScr::actionHandler(VappContactControl::Button btn)
{

	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_ACTION_HANDLER, btn);
	
	switch(btn)
	{
	case VappContactControl::BTN_CALL:
		{
			// more than one number
			if (m_struContactNumber.flag > 1)
			{
				VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_CALL_MULTI_NUM, m_pSetting->active);
				
				if (m_frmEffectCont == NULL)
				{
					VFX_OBJ_CREATE(m_frmEffectCont, VcpFrameEffect, this);
				}

				m_frmCurrCont->setHidden(VFX_FALSE);
				m_frmEffectCont->applyEffect(m_frmCurrCont, 
											VCP_EFFECT_FLIP, 
											CONTACT_ROTATE_TIME, 
											VCP_EFFECT_DIRECTION_FROM_RIGHT,
											VFX_TRUE);
				// create number list frame
				if (m_frmEffectList == NULL)
				{
					VFX_OBJ_CREATE(m_frmEffectList, VcpFrameEffect, this);
				}

				if (m_frmNumList == NULL)
				{
					createListScreen();
				}
				
				m_frmNumList->setHidden(VFX_FALSE);

				m_frmEffectList->applyEffect(m_frmNumList, 
											VCP_EFFECT_FLIP, 
											CONTACT_ROTATE_TIME, 
											VCP_EFFECT_DIRECTION_FROM_RIGHT);
				
				m_frmEffectList->m_signalFinished.connect(this, &VappCubeVipContactScr::onRotateContFinish);
			}
			else
			{
				VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_CALL_ONE_NUM, m_pSetting->active);
				
				const VfxWChar *buffer;
				VfxU32 flag;

				if (!m_struContactNumber.home.isEmpty())
				{
					buffer = m_struContactNumber.home.getBuf();
					flag = CONTACT_NUMBER_MASK_HOME;
				}
				else if (!m_struContactNumber.office.isEmpty())
				{
					buffer = m_struContactNumber.office.getBuf();
					flag = CONTACT_NUMBER_MASK_OFFICE;
				}
				else if (!m_struContactNumber.mobile.isEmpty())
				{
					buffer = m_struContactNumber.mobile.getBuf();
					flag = CONTACT_NUMBER_MASK_MOBILE;
				}
				else if (!m_struContactNumber.fax.isEmpty())
				{
					buffer = m_struContactNumber.fax.getBuf();
					flag = CONTACT_NUMBER_MASK_FAX;
				}
				else
				{
					VFX_ASSERT(!"NO Number");
				}			

				vfxPostInvoke2(this, &VappCubeVipContactScr::makeCall, buffer, flag);
			}
	
		}
		break;
		
	case VappContactControl::BTN_SMS:
		if (!m_struContactNumber.mobile.isEmpty())
		{
			vfxPostInvoke1(this, &VappCubeVipContactScr::sendSms, m_struContactNumber.mobile.getBuf());
		}
		 
		break;
		
	case VappContactControl::BTN_TRASH:
		{
			m_pSetting->index[m_pSetting->active] = INVALID_CONT_INDEX;
			
			m_dndImage[m_pSetting->active]->setText(VFX_WSTR_NULL);
			m_dndImage[m_pSetting->active]->setImage(VAPP_CUBE_IMG_VIP_CONTACT_NORMAL);
			m_dndImage[m_pSetting->active]->setCenterImage(VAPP_CUBE_IMG_VIP_CONTACT_DEFAULT);
			vadp_v2p_vip_contact_save_setting();
		}
		// Go though button close process
	case VappContactControl::BTN_CLOSE:
		{	
	        VfxAutoAnimate::begin();
	        VfxAutoAnimate::setDisable(VFX_TRUE);
			VfxAutoAnimate::setDuration(3000);
			VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
			
			m_frmCurrCont->setOpacity(0.0f);
			
	        VfxAutoAnimate::commit();
			m_pSetting->active = 0xFF;
			
			VFX_OBJ_CLOSE(m_frmCurrCont);
			VFX_OBJ_CLOSE(m_frmNumList);

			// Register the switch page action
			regDefaultPageAct(this);
		}
		break;
		
	default:
		break;
	}
}

VfxBool VappCubeVipContactScr::findSelect(const VfxPoint &point, VfxU16 &index)
{
	for (VfxS8 i = 0; i < TOTAL_CONTACTS; i++)
	{
		if (m_dndImage[i]->containPoint(convertPointTo(point, m_dndImage[i])))
		{
			VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_FIND_SELECT, i);
			index = i;
			return VFX_TRUE;
		}
	}
	
	return VFX_FALSE;
}

void VappCubeVipContactScr::onBtnEditDown(void)
{
	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_EDIT_DONE);
	
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);				
	VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);

	// restore the original image status.
	for (VfxU8 i = 0; i < TOTAL_CONTACTS; i++)
	{
		m_dndImage[i]->setBorderColor(VFX_COLOR_TRANSPARENT);
		m_dndImage[i]->setBorderWidth(0);
		m_dndImage[i]->setOpacity(1.0f);
		m_dndImage[i]->setEditmode(VFX_FALSE);
		m_dndImage[i]->stopShake();
		// allow to switch page
		regDefaultPageAct(m_dndImage[i]);
	}
	
	VfxAutoAnimate::commit();

	m_pSetting->state = STATE_IDLE;
	
	hideShortcutBar(VFX_FALSE);
	
	VFX_OBJ_CLOSE(m_btnEditDone);
	
	vadp_v2p_vip_contact_save_setting();
}

void VappCubeVipContactScr::onTimerExpire(VfxTimer * source)
{
	// change to edit mode
	if (source == m_tmLongPress)
	{
		m_pSetting->state = STATE_EDIT;
		m_pSetting->active = 0xFF;

		hideShortcutBar(VFX_TRUE);
		showEditScreen();
		
		updateContent();
	}
	else if (source == m_tmRefresh)
	{
		// check the contact time and time again.
		if (vadp_v2p_contact_is_available())
		{
			VFX_OBJ_CLOSE(m_txtLoading);
			VFX_OBJ_CLOSE(m_imgLoading);
			VFX_OBJ_CLOSE(m_tmRefresh);
			m_animLoading->stopAnimate();
			VFX_OBJ_CLOSE(m_animLoading);
			m_pSetting->state = STATE_IDLE;
			updateContent();
		}
	}
}

void VappCubeVipContactScr::updateContent(void)
{
	VfxU8 i;

	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_UPDATE_STATE, m_pSetting->state);
	switch(m_pSetting->state)
	{
		case STATE_INVALID:
			for (i = 0; i < TOTAL_CONTACTS; i++)
			{
				m_dndImage[i]->setImage(VAPP_CUBE_IMG_VIP_CONTACT_DISABLE);
			}

			// start loading animation.
			m_animLoading->bringToFront();
			m_animLoading->startAnimate();
			
		break;
		
		case STATE_EDIT:
			for (i = 0; i < TOTAL_CONTACTS; i++)
			{
				//m_dndImage[i]->setBorderColor(VFX_COLOR_BLUE);
				//m_dndImage[i]->setBorderWidth(1);
				m_dndImage[i]->setOpacity(1.0f);
				m_dndImage[i]->setEditmode(VFX_TRUE);
				m_dndImage[i]->setAutoAnimate(VFX_TRUE);
				m_dndImage[i]->startShake();
				deregDefaultPageAct(m_dndImage[i]);
			}
			// go thru to next case
		case STATE_IDLE:
			for (i = 0; i < TOTAL_CONTACTS; i++)
			{
				onUpdateCont(i);
			}
			
			break;
			
		default:
			VFX_ASSERT(!"Error vip contact state");
	}
}

const VfxWString VappCubeVipContactScr::getText(const VfxU16 &index)
{	
	VfxWChar buffer[MMI_PHB_NAME_FIELD_LENGTH];
	
	vadp_v2p_vip_contact_get_name(m_pSetting->index[index], buffer, MMI_PHB_NAME_FIELD_LENGTH);

	VfxWString string;
	string.loadFromMem(buffer);

	// if name is empty, get number
	if (string.isEmpty())
	{
		loadNumber(index);
		
		if (!m_struContactNumber.mobile.isEmpty())
		{
			return m_struContactNumber.mobile;
		}
		else if (!m_struContactNumber.home.isEmpty())
		{
			return m_struContactNumber.home;
		}
		else if (!m_struContactNumber.office.isEmpty())
		{
			return m_struContactNumber.office;
		}
		else if (!m_struContactNumber.fax.isEmpty())
		{
			return m_struContactNumber.fax;
		}
		else
		{
			return VFX_WSTR_NULL;
		}
	}
	
	return string;
}

void VappCubeVipContactScr::loadNumber(const VfxU16 &index)
{
	VfxWChar buffer[CONT_NUM_LENGTH + 1];
	VfxS8 ret;

	m_struContactNumber.mobile.setNull();
	ret = vadp_v2p_vip_contact_get_number(buffer,
										  CONT_NUM_LENGTH + 1, 
										  m_pSetting->index[index],
										  CONTACT_NUMBER_MASK_MOBILE);
	if (ret != 0)
	{
		m_struContactNumber.mobile.loadFromMem(buffer);
		m_struContactNumber.flag++;
	}

	m_struContactNumber.home.setNull();
	ret = vadp_v2p_vip_contact_get_number(buffer,
										  CONT_NUM_LENGTH + 1, 
										  m_pSetting->index[index],
										  CONTACT_NUMBER_MASK_HOME);
	if (ret != 0)
	{
		m_struContactNumber.home.loadFromMem(buffer);
		m_struContactNumber.flag++;
	}

	m_struContactNumber.office.setNull();
	ret = vadp_v2p_vip_contact_get_number(buffer,
										  CONT_NUM_LENGTH + 1, 
										  m_pSetting->index[index],
										  CONTACT_NUMBER_MASK_OFFICE);
	if (ret != 0)
	{
		m_struContactNumber.office.loadFromMem(buffer);
		m_struContactNumber.flag++;
	}

	m_struContactNumber.fax.setNull();
	ret = vadp_v2p_vip_contact_get_number(buffer,
										  CONT_NUM_LENGTH + 1, 
										  m_pSetting->index[index],
										  CONTACT_NUMBER_MASK_FAX);
	if (ret != 0)
	{
		m_struContactNumber.fax.loadFromMem(buffer);
		m_struContactNumber.flag++;
	}
}

VfxBool VappCubeVipContactScr::onPenInput(VfxPenEvent & event)
{
	VfxU16 index;

	switch(event.type)
	{
		case VFX_PEN_EVENT_TYPE_DOWN:

			if (m_pSetting->state != STATE_INVALID &&
				m_pSetting->active == 0xFF && 
				findSelect(event.getRelPos(this), index))
			{
				if (m_tmLongPress->getIsEnabled())
				{
					m_tmLongPress->stop();
				}
				m_tmLongPress->start();
				m_pSetting->active = (VfxU8)index;
				
			    VfxAutoAnimate::begin();
			    VfxAutoAnimate::setDisable(VFX_TRUE);
				VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
				
				m_dndImage[index]->setOpacity(0.65f);
				
			    VfxAutoAnimate::commit();				
			}
			break;
			
		case VFX_PEN_EVENT_TYPE_UP:
			
			if (m_pSetting->state != STATE_EDIT &&
				m_pSetting->active != 0xFF &&
				m_frmCurrCont == NULL)
			{
			    VfxAutoAnimate::begin();
			    VfxAutoAnimate::setDisable(VFX_TRUE);
				VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
				
				m_dndImage[m_pSetting->active]->setOpacity(1.0f);
				
			    VfxAutoAnimate::commit();
				
				if (m_tmLongPress->getIsEnabled())
				{
					m_tmLongPress->stop();
				}
		    	// Select new contact
				if (m_pSetting->index[m_pSetting->active] == INVALID_CONT_INDEX)
				{
					vadp_v2p_vip_contact_save_setting();
					vfxPostInvoke1(this, &VappCubeVipContactScr::selectContact, (VfxU16)m_pSetting->active);
				}
				else
				{
					createContactScreen();
				}
				
			}

			break;

		default:
			;
	}


	return VappCubeScr::onPenInput(event);
}

VfxBool VappCubeVipContactScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_END &&
        event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        if (m_pSetting->state == STATE_EDIT)
    	{
    		onBtnEditDown();
    	}
    }
	
	return VappCubeScr::onKeyInput(event);
}

void VappCubeVipContactScr::makeCall(const VfxWChar *number, VfxU32 flag)
{
	vadp_v2p_vip_contact_make_call(number, flag, m_pSetting->index[m_pSetting->active]);
}

void VappCubeVipContactScr::sendSms(const VfxWChar *number)
{
	vadp_v2p_vip_contact_send_sms(number);
}

void VappCubeVipContactScr::selectContact(VfxU16 index)
{
	VFX_LOG(VFX_STATE2, VAPP_CUBE_VIP_CONTACT_SELECT_CONTACT, index);
	
	vadp_v2p_vip_contact_select_contact(index);
}

void VappCubeVipContactScr::onContactCreateFinish(VfxBaseTimeline * timeline, VfxBool finish)
{
	VFX_UNUSED(timeline);
	
	if (finish)
	{
		//if no number or network is available, disable call/sms button.
		if (vadp_v2p_vip_contact_is_nwk_available() != 0)
		{
			if (m_struContactNumber.flag != 0)
			{
				m_frmCurrCont->enableBtn(VappContactControl::BTN_CALL, VFX_TRUE);
				
				if (!m_struContactNumber.mobile.isEmpty() &&
				    vadp_v2p_vip_contact_is_sms_available())
				{
					m_frmCurrCont->enableBtn(VappContactControl::BTN_SMS, VFX_TRUE);
				}				
			}
		}
		
		m_frmCurrCont->enableBtn(VappContactControl::BTN_TRASH, VFX_TRUE);
		m_frmCurrCont->enableBtn(VappContactControl::BTN_CLOSE, VFX_TRUE);
	}
}

#endif /* __MMI_VUI_3D_CUBE_APP__ */

