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
 *  vapp_uc_emontics.cpp
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/ 

#include "MMI_features.h" 

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)			
#include "vfx_uc_include.h"
#include "mmi_rp_vapp_unifiedcomposer_def.h"
#include "vapp_uc_gprot.h"
#include "vapp_uc_prot.h"
#include "vfx_adp_device.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_popup_def.h"

VFX_IMPLEMENT_CLASS("VappUcEmoticon", VappUcEmoticon, VfxBasePopup);

#if defined(__MMI_MAINLCD_480X800__)
#define  V_GAP 16
#define H_GAP 0 /*14*/
#else
#define  V_GAP 8
#define H_GAP  0 /*6*/
#endif

#if defined(__MMI_MAINLCD_480X800__)
#define VUC_EMOTICON_GAP_FROM_SIDE	21
#define VUC_EMOTICON_GAP_FROM_START	30
#define VUC_EMOTICON_POPUP_SIDE_SHADOW 7
#define VUC_EMOTICON_POPUP_BOTTOM_SHADOW 16
#elif defined(__MMI_MAINLCD_320X480__)
#define VUC_EMOTICON_GAP_FROM_SIDE	11
#define VUC_EMOTICON_GAP_FROM_START	16
#define VUC_EMOTICON_POPUP_SIDE_SHADOW 3
#define VUC_EMOTICON_POPUP_BOTTOM_SHADOW 8
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VUC_EMOTICON_GAP_FROM_SIDE	8
#define VUC_EMOTICON_GAP_FROM_START	13
#define VUC_EMOTICON_POPUP_SIDE_SHADOW 3
#define VUC_EMOTICON_POPUP_BOTTOM_SHADOW 8
#else
#define VUC_EMOTICON_GAP_FROM_SIDE	11
#define VUC_EMOTICON_GAP_FROM_START	16
#define VUC_EMOTICON_POPUP_SIDE_SHADOW 3
#define VUC_EMOTICON_POPUP_BOTTOM_SHADOW 8
#endif


VappUcEmoticon::VappUcEmoticon(): m_rows(0),
					  m_cols(0),
					  m_emontics_count(EMOTICON_COUNT)
	{
		VFX_ALLOC_MEM(m_buttons , (m_emontics_count + 1) * sizeof(VcpImageButton*), this);
		m_BaseId = IMG_ID_VAPP_UC_EMOTIC_1_ID;
		m_emontics_count = UC_EMOTICON_ICON_COUNT;
		m_strTable = getEmotionTablePointer();

	}
VfxU32 VappUcEmoticon::getWidth()
{
	VfxU32 width = 0;
	VfxU32 leftOutArea = 0;
	VfxU16 numRowItems = 0;

	vrt_size_struct mainScreenSize;
	vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

	width = (mainScreenSize.width * 9)/10 ;//+ H_GAP;
	width += (width%2);

	VfxSize  imageSize = this->getImageSize(m_BaseId);
	VfxU32 btnWidth = (imageSize.width * 8/5);//2) ;//- (imageSize.width / 2);//+ 2 * VAPP_UC_EMOTOCON_BTN_GAP;
	VfxU32 btnHeight = (imageSize.width *8/5);//2) ;//- (imageSize.width / 2);//+ 2 * VAPP_UC_EMOTOCON_BTN_GAP;

	numRowItems = (VfxU16)((width /*- H_GAP*/) / btnWidth);
	width = numRowItems * btnWidth + (VUC_EMOTICON_GAP_FROM_SIDE - (imageSize.width/4))*2 + VUC_EMOTICON_POPUP_SIDE_SHADOW * 2;
	leftOutArea = VUC_EMOTICON_GAP_FROM_SIDE *2;//width - (numRowItems * btnWidth);
/*	if(leftOutArea > H_GAP)
	{
		width = width - leftOutArea + H_GAP;
	}*/
	return width;
}
void VappUcEmoticon::onBtnStateChangd(VcpImageButton *obj, VcpImageButtonStateEnum state)
{
	VcpImageButton* btn = (VcpImageButton*) obj;
	if(state == VCP_IMAGE_BUTTON_STATE_PRESSED)
	{
		btn->setBorder(VFX_COLOR_RES(CLR_COSMOS_TEXT_LINK));
	}
	if(state == VCP_IMAGE_BUTTON_STATE_NORMAL)
	{
		btn->setBorder(VRT_COLOR_TRANSPARENT, 0);
	}
}

void VappUcEmoticon::onInit()
{
	VfxBasePopup::onInit();
	VfxU32 index = 1;
	VfxU16 numRowItems = 0;
	VfxWString itemText;
	VfxU32 width = this->getWidth();
	VfxSize  imageSize = this->getImageSize(m_BaseId);
	VfxU32 btnWidth = (imageSize.width *8/5);//2) ;//- (imageSize.width / 2);//+ 2 * VAPP_UC_EMOTOCON_BTN_GAP;
	VfxU32 btnHeight = (imageSize.width *8/5);//2) ;//- (imageSize.width / 2);//+ 2 * VAPP_UC_EMOTOCON_BTN_GAP;
	VfxU32 leftOutArea = 0;
	VcpImageButton *buttonCtrl = NULL;

	m_button_pressed = VFX_FALSE;
	VfxRenderer *renderer ;
	setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	numRowItems = (VfxU16)((width /*- H_GAP*/) / btnWidth);

	leftOutArea = width - (numRowItems * btnWidth);
	leftOutArea += (leftOutArea %2); 
	

	renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	m_dir = renderer->getScreenRotateType();


	while (index <= m_emontics_count)
	{
		VfxWString itemText;

		VFX_OBJ_CREATE(buttonCtrl, VcpImageButton, this);
//		buttonCtrl->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
//		buttonCtrl->setIsAutoResized(VFX_FALSE);
	/*	buttonCtrl->setRect(VfxRect((leftOutArea / 2) + VAPP_UC_EMOTOCON_BTN_X + m_cols * btnWidth,
									VCP_CONFIRM_POPUP_UP_HEIGHT  + m_rows * btnHeight,
									btnWidth,
									btnHeight));*/
		buttonCtrl->setRect(VfxRect((leftOutArea / 2 + 1) /*+ (VUC_EMOTICON_GAP_FROM_SIDE - (imageSize.width/4)) */+ m_cols * btnWidth,
									m_rows * btnHeight + (VUC_EMOTICON_GAP_FROM_START - (imageSize.width/4)),
									btnWidth,
									btnHeight));
		buttonCtrl->setId(index);
//		buttonCtrl->setBgImageList(VcpStateImage(IMG_ID_VAPP_UC_EMOTIC_BG_BT2));//, IMG_UC_FTO_EMOTIC_BG_BT4, IMG_UC_FTO_EMOTIC_BG_BT3, IMG_UC_FTO_EMOTIC_BG_BT3));
		buttonCtrl->setImage(VcpStateImage(m_BaseId + (index - 1)));
//		buttonCtrl->setText(itemText.loadFromMem(m_strTable[index -1].text));
		buttonCtrl->m_signalStateChanged.connect(this,&VappUcEmoticon::onBtnStateChangd);
		buttonCtrl->m_signalClicked.connect(this, &VappUcEmoticon::onButtonClick);

		if (index % numRowItems)
		{
			m_cols++;
		}
		else
		{
			m_rows++;
			m_cols = 0;
		}
		m_buttons[index - 1] = buttonCtrl;
		index++;
		
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
#else
	if(m_cols!=0)
	{
		m_rows++;
	}
#endif
	
	//this->setBgColor(VFX_COLOR_WHITE);
	this->setBounds(VfxRect(0,0,width /*+ 2 * VAPP_UC_EMOTOCON_BTN_X*/, (VUC_EMOTICON_GAP_FROM_START - (imageSize.width/4)) * 2 + m_rows * btnHeight + VUC_EMOTICON_POPUP_BOTTOM_SHADOW));
	this->setAutoDestory(VFX_TRUE);
	

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void VappUcEmoticon::onUpdate()
{
	VfxU32 width = this->getWidth();
	VfxTextFrame *textFrame =  NULL;
	VfxU32 leftOutArea = 0;
	VfxSize  imageSize = this->getImageSize(m_BaseId);
	VfxU32 btnWidth = (imageSize.width *8/5);//2) ;//- (imageSize.width / 2);//+ 2 * VAPP_UC_EMOTOCON_BTN_GAP;
	VfxU32 btnHeight = (imageSize.width *8/5);//2) ;//- (imageSize.width / 2);//+ 2 * VAPP_UC_EMOTOCON_BTN_GAP;

	

	VfxU32 index = 1;
	VfxU16 numRowItems = 0;
	
	VcpImageButton *buttonCtrl = NULL;

	numRowItems = (VfxU16)((width) / btnWidth);

	leftOutArea = width - (numRowItems * btnWidth);
	leftOutArea += (leftOutArea %2); 

	if (m_buttons && m_rows > 0)
	{
		m_cols = 0;
		m_rows = 0;
		while (index <= m_emontics_count)
		{
			

	
			m_buttons[index -1]->setRect(VfxRect((leftOutArea / 2 + 1) /*+ (VUC_EMOTICON_GAP_FROM_SIDE - (imageSize.width/4)) */+ m_cols * btnWidth,
									m_rows * btnHeight + (VUC_EMOTICON_GAP_FROM_START - (imageSize.width/4)),
									btnWidth,
									btnHeight));
	

			if (index % numRowItems)
			{
				m_cols++;
			}
			else
			{
				m_rows++;
				m_cols = 0;
			}
			index++;
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
#else
		if(m_cols!=0)
		{
			m_rows++;
		}
#endif
	}	
	
	this->setBounds(VfxRect(0,0,width/* + 2 * VAPP_UC_EMOTOCON_BTN_X*/, (VUC_EMOTICON_GAP_FROM_START - (imageSize.width/4)) * 2 + m_rows * btnHeight + VUC_EMOTICON_POPUP_BOTTOM_SHADOW));

}
void VappUcEmoticon::onRotate(const VfxScreenRotateParam &param)
{
	VfxBasePopup::onRotate(param);
	if(m_dir == param.rotateTo)
	{

	}
	else
	{
		onUpdate();
		m_dir = param.rotateTo ;
	}
	

}

VfxBool VappUcEmoticon::onKeyInput(VfxKeyEvent& event)
{
	if(event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		m_button_pressed = VFX_TRUE;
		leave(VFX_TRUE);
		return VFX_TRUE;
	}
	return VfxBasePopup::onKeyInput(event);
}

VfxWString VappUcEmoticon::getTextByIndex(VfxU32 index)const
{
	VfxWString text;
	text.loadFromMem(m_strTable[index].text);
	return text;
}

VcpIconTable *VappUcEmoticon::getEmotionTablePointer()
{
	return textIconTable;
}
VfxU32 VappUcEmoticon::getEmotionTableSize()
{
	return UC_EMOTICON_ICON_COUNT;
}
void VappUcEmoticon::onEnter()
{
	VfxBasePopup::onEnter();
#if 0
/* under construction !*/
/* under construction !*/
#endif
    onUpdate();
}
void VappUcEmoticon::onButtonClick(VfxObject* sender, VfxId id)
{
	VfxU32 index = m_emontics_count + 1;
	if(m_button_pressed)
	{
		return;
	}
	vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
    m_button_pressed = VFX_TRUE;
	if (id <= m_emontics_count)
	{
		index = id - 1;
	}
	m_signalcallback.postEmit(this, index);
	leave(VFX_TRUE);
}
#endif /* __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__ */
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */

