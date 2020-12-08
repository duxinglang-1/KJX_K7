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
 *  vapp_sms_notifier_scrn.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "GlobalResDef.h"
#include "vapp_sms_notifier_scrn.h"
#include "vapp_sms_notifier_core.h"
#include "vcp_include.h"
#include "vtst_rt_main.h" //will removed?
#include "vfx_xml_loader.h"
#include "vapp_ncenter_base_cell.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"
#include "vapp_cbs_new_msg.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmsSrvGprot.h"
    #include "PhbSrvGprot.h"
    #include "Unicodexdcl.h"
    #include "Wgui_categories_util.h"
    #include "CustDataRes.h"
    #include "UCMGprot.h"
    #include "UCMSrvGprot.h"
	#include "mmi_frm_scenario_gprot.h"
#ifdef __cplusplus
}
#endif

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_SMS_CLASS0_WIDTH                    (284)

#define VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT         (94)
#define VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT      (75)

#define VAPP_SMS_CLASS0_HEIGHT                   (VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT+VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT)

#define VAPP_SMS_CLASS0_CONTACT_FRAME_X          (18)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_Y          (23)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_WIDTH      (248)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_HEIGHT     (20)
#define VAPP_SMS_CLASS0_CONTACT_TEXT_SIZE        (20)

#define VAPP_SMS_CLASS0_CONTENT_VIEW_X           (18)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_Y           (56)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_WIDTH       (248)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT  (38)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MAX_HEIGHT  (302)
#define VAPP_SMS_CLASS0_CONTENT_TEXT_SIZE        (18)
#define VAPP_SMS_CLASS0_CONTENT_TIME_GAP         (4)
#define VAPP_SMS_CLASS0_TIME_TEXT_SIZE           (14)

#define VAPP_SMS_CLASS0_BUTTON1_X                (18)
#define VAPP_SMS_CLASS0_BUTTON1_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON2_X                (146)
#define VAPP_SMS_CLASS0_BUTTON2_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON_WIDTH             (120)
#define VAPP_SMS_CLASS0_BUTTON_HEIGHT            (47)

#define VAPP_SMS_CLASS0_MID_WIDTH                (160)
#define VAPP_SMS_CLASS0_MID_HEIGHT               (240)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_CUT_HEIGHT (160)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH  (50)

#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_SMS_CLASS0_WIDTH                    (446)

#define VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT         (126)
#define VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT      (115)

#define VAPP_SMS_CLASS0_HEIGHT                   (VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT+VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT)

#define VAPP_SMS_CLASS0_CONTACT_FRAME_X          (21)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_Y          (37)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_WIDTH      (404)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_HEIGHT     (30)
#define VAPP_SMS_CLASS0_CONTACT_TEXT_SIZE        (30)

#define VAPP_SMS_CLASS0_CONTENT_VIEW_X           (21)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_Y           (78)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_WIDTH       (404)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT  (48)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MAX_HEIGHT  (527)
#define VAPP_SMS_CLASS0_CONTENT_TEXT_SIZE        (21)
#define VAPP_SMS_CLASS0_CONTENT_TIME_GAP         (7)
#define VAPP_SMS_CLASS0_TIME_TEXT_SIZE           (20)

#define VAPP_SMS_CLASS0_BUTTON1_X                (21)
#define VAPP_SMS_CLASS0_BUTTON1_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON2_X                (228)
#define VAPP_SMS_CLASS0_BUTTON2_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON_WIDTH             (197)
#define VAPP_SMS_CLASS0_BUTTON_HEIGHT            (70)

#define VAPP_SMS_CLASS0_MID_WIDTH                (240)
#define VAPP_SMS_CLASS0_MID_HEIGHT               (400)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_CUT_HEIGHT (320)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH  (76)

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VAPP_SMS_CLASS0_WIDTH                    (222)

#define VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT         (65)
#define VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT      (68)

#define VAPP_SMS_CLASS0_HEIGHT                   (VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT+VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT)

#define VAPP_SMS_CLASS0_CONTACT_FRAME_X          (8)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_Y          (17)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_WIDTH      (206)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_HEIGHT     (16)
#define VAPP_SMS_CLASS0_CONTACT_TEXT_SIZE        (16)

#define VAPP_SMS_CLASS0_CONTENT_VIEW_X           (8)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_Y           (36)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_WIDTH       (206)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT  (29)
#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MAX_HEIGHT  (182)
#else
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MAX_HEIGHT  (262)
#endif
#define VAPP_SMS_CLASS0_CONTENT_TEXT_SIZE        (14)
#define VAPP_SMS_CLASS0_CONTENT_TIME_GAP         (3)
#define VAPP_SMS_CLASS0_TIME_TEXT_SIZE           (12)

#define VAPP_SMS_CLASS0_BUTTON1_X                (8)
#define VAPP_SMS_CLASS0_BUTTON1_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON2_X                (113)
#define VAPP_SMS_CLASS0_BUTTON2_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON_WIDTH             (100)
#define VAPP_SMS_CLASS0_BUTTON_HEIGHT            (40)


#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_SMS_CLASS0_MID_WIDTH                (120)
#define VAPP_SMS_CLASS0_MID_HEIGHT               (160)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_CUT_HEIGHT  (80)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH   (20)
#else
#define VAPP_SMS_CLASS0_MID_WIDTH                (120)
#define VAPP_SMS_CLASS0_MID_HEIGHT               (200)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_CUT_HEIGHT  (160)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH   (38)
#endif

#else
#define VAPP_SMS_CLASS0_WIDTH                    (284)

#define VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT         (94)
#define VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT      (75)

#define VAPP_SMS_CLASS0_HEIGHT                   (VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT+VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT)

#define VAPP_SMS_CLASS0_CONTACT_FRAME_X          (18)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_Y          (23)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_WIDTH      (248)
#define VAPP_SMS_CLASS0_CONTACT_FRAME_HEIGHT     (20)
#define VAPP_SMS_CLASS0_CONTACT_TEXT_SIZE        (20)

#define VAPP_SMS_CLASS0_CONTENT_VIEW_X           (18)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_Y           (56)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_WIDTH       (248)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT  (38)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_MAX_HEIGHT  (302)
#define VAPP_SMS_CLASS0_CONTENT_TEXT_SIZE        (18)
#define VAPP_SMS_CLASS0_CONTENT_TIME_GAP         (4)
#define VAPP_SMS_CLASS0_TIME_TEXT_SIZE           (14)

#define VAPP_SMS_CLASS0_BUTTON1_X                (18)
#define VAPP_SMS_CLASS0_BUTTON1_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON2_X                (146)
#define VAPP_SMS_CLASS0_BUTTON2_Y                (15)
#define VAPP_SMS_CLASS0_BUTTON_WIDTH             (120)
#define VAPP_SMS_CLASS0_BUTTON_HEIGHT            (47)

#define VAPP_SMS_CLASS0_MID_WIDTH                (160)
#define VAPP_SMS_CLASS0_MID_HEIGHT               (240)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_CUT_HEIGHT (160)
#define VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH  (50)
#endif

/***************************************************************************** 
 * Class VappSmsClass0NotifyCp
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsClass0NotifyCp", VappSmsClass0NotifyCp, VfxBasePopup);


VappSmsClass0NotifyCp::VappSmsClass0NotifyCp(VfxScrRotateTypeEnum dir, VappSmsClass0NotifyCp::NotifyType type):
	m_backgroundTop(NULL),
	m_backgroundBottom(NULL),
    m_contactFrame(NULL),
    m_contentView(NULL),
    m_timeFrame(NULL),
    m_saveButton(NULL),
    m_closeButton(NULL),
    m_okButton(NULL),
    m_relatedNmgr(NULL),
    m_curNotifyIndex(0),
    m_dir(dir),
    m_notifyType(type)    
{
}

void VappSmsClass0NotifyCp::onInit()
{
    VfxBasePopup::onInit();
#if (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__))
	if (m_notifyType == NOTIFY_CP_TYPE_SMS)
	{
	mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_READY, &VappSmsClass0NotifyCp::onSmsReady, getObjHandle());
	}
#endif /* (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__)) */ 
	createCp();
    //updateView();
}


void VappSmsClass0NotifyCp::createCp()
{
    setBounds(0, 0, VAPP_SMS_CLASS0_WIDTH, VAPP_SMS_CLASS0_HEIGHT);

    VFX_OBJ_CREATE(m_backgroundTop, VfxFrame, this);
    m_backgroundTop->setIsCached(VFX_TRUE);
    m_backgroundTop->setSize(VAPP_SMS_CLASS0_WIDTH, VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT);

    VFX_OBJ_CREATE(m_backgroundBottom, VfxFrame, this);
    m_backgroundBottom->setIsCached(VFX_TRUE);
    m_backgroundBottom->setPos(0, VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT);
    m_backgroundBottom->setSize(VAPP_SMS_CLASS0_WIDTH, VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT);

#ifdef __MMI_VUI_COSMOS_CP__
    setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif

    VFX_OBJ_CREATE(m_contactFrame, VfxTextFrame, m_backgroundTop);
    m_contactFrame->setPos(VAPP_SMS_CLASS0_CONTACT_FRAME_X, VAPP_SMS_CLASS0_CONTACT_FRAME_Y);
    m_contactFrame->setSize(VAPP_SMS_CLASS0_CONTACT_FRAME_WIDTH, VAPP_SMS_CLASS0_CONTACT_FRAME_HEIGHT);
    m_contactFrame->setBgColor(getBgColor());
    VfxColor color = VFX_COLOR_RES(VAPP_SMS_CLASS0_CONTACT_TEXT_COLOR);
    m_contactFrame->setColor(color);
    VfxFontDesc contactFontDesc;
    contactFontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_SMS_CLASS0_CONTACT_TEXT_SIZE);
    m_contactFrame->setFont(contactFontDesc);
    m_contactFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);


    VFX_OBJ_CREATE(m_contentView, VcpTextView, m_backgroundTop);
    m_contentView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_contentView->setPos(VAPP_SMS_CLASS0_CONTENT_VIEW_X, VAPP_SMS_CLASS0_CONTENT_VIEW_Y);
    m_contentView->setSize(VAPP_SMS_CLASS0_CONTENT_VIEW_WIDTH, VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT);
    m_contentView->m_signalBoundsChanged.connect(this, &VappSmsClass0NotifyCp::onContentBoundsChanged);
    m_contentView->setAutoResized(VFX_TRUE, VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT, VAPP_SMS_CLASS0_CONTENT_VIEW_MAX_HEIGHT);
    m_contentView->setBgColor(getBgColor());
    color = VFX_COLOR_RES(VAPP_SMS_CLASS0_CONTENT_TEXT_COLOR);
    m_contentView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, color);
    VfxFontDesc fontDesc1;
    fontDesc1.size = VFX_FONT_DESC_VF_SIZE(VAPP_SMS_CLASS0_CONTENT_TEXT_SIZE);
    m_contentView->setFont(fontDesc1);


    VFX_OBJ_CREATE(m_timeFrame, VfxTextFrame, m_backgroundTop);
    m_timeFrame->setPos(VfxPoint(0, VAPP_SMS_CLASS0_CONTENT_TIME_GAP));
    m_timeFrame->setBgColor(getBgColor());
    color = VFX_COLOR_RES(VAPP_SMS_CLASS0_CONTENT_TIME_COLOR);
    m_timeFrame->setColor(color);
    m_timeFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SMS_CLASS0_TIME_TEXT_SIZE)));

	if (m_notifyType == NOTIFY_CP_TYPE_SMS)
	{
    VFX_OBJ_CREATE(m_saveButton, VcpButton, m_backgroundBottom);
    m_saveButton->setText((VfxResId)STR_GLOBAL_SAVE);
    m_saveButton->setId(ITEM_ID_BUTTON_SAVE);
    m_saveButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_saveButton->setInnerRect(VfxRect(
                                    VAPP_SMS_CLASS0_BUTTON1_X, 
                                    VAPP_SMS_CLASS0_BUTTON1_Y, 
                                    VAPP_SMS_CLASS0_BUTTON_WIDTH, 
                                    VAPP_SMS_CLASS0_BUTTON_HEIGHT
                                 ));
    color = VFX_COLOR_RES(VAPP_SMS_CLASS0_BUTTON1_COLOR);
    m_saveButton->setTextColor(color);
	    m_saveButton->m_signalClicked.connect(this, &VappSmsClass0NotifyCp::onButtonClicked);


    VFX_OBJ_CREATE(m_closeButton, VcpButton, m_backgroundBottom);
    m_closeButton->setText((VfxResId)STR_GLOBAL_DISCARD);
    m_closeButton->setId(ITEM_ID_BUTTON_DISCARD);
    m_closeButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_closeButton->setInnerRect(VfxRect(
                                    VAPP_SMS_CLASS0_BUTTON2_X, 
                                    VAPP_SMS_CLASS0_BUTTON2_Y, 
                                    VAPP_SMS_CLASS0_BUTTON_WIDTH, 
                                    VAPP_SMS_CLASS0_BUTTON_HEIGHT
                                 ));
    m_closeButton->setStyle(VCP_BUTTON_STYLE_GREY);
    color = VFX_COLOR_RES(VAPP_SMS_CLASS0_BUTTON2_COLOR);
    m_closeButton->setTextColor(color);
	    m_closeButton->m_signalClicked.connect(this, &VappSmsClass0NotifyCp::onButtonClicked);
	}
	else
	{
		VFX_OBJ_CREATE(m_okButton, VcpButton, m_backgroundBottom);
	    m_okButton->setText((VfxResId)STR_GLOBAL_OK);
	    m_okButton->setId(ITEM_ID_BUTTON_OK);
	    m_okButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
	    m_okButton->setInnerRect(VfxRect(
	                                    VAPP_SMS_CLASS0_BUTTON1_X, 
	                                    VAPP_SMS_CLASS0_BUTTON1_Y, 
	                                    VAPP_SMS_CLASS0_BUTTON_WIDTH + VAPP_SMS_CLASS0_BUTTON2_X - VAPP_SMS_CLASS0_BUTTON1_X,
	                                    VAPP_SMS_CLASS0_BUTTON_HEIGHT
	                                 ));
	    m_okButton->setStyle(VCP_BUTTON_STYLE_GREY);
	    color = VFX_COLOR_RES(VAPP_SMS_CLASS0_BUTTON2_COLOR);
	    m_okButton->setTextColor(color);
	    m_okButton->m_signalClicked.connect(this, &VappSmsClass0NotifyCp::onButtonClicked);
	}
}


#if (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__))
mmi_ret VappSmsClass0NotifyCp::onSmsReady(mmi_event_struct *evt)
{
    VappSmsClass0NotifyCp *notifyCp = (VappSmsClass0NotifyCp*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
	if (!notifyCp)
		return MMI_RET_OK;
	srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_sms_ready_struct *event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;
	

	if (!event_info->is_sms_ready)
	{
		notifyCp->m_saveButton->setIsDisabled(VFX_TRUE);
	}
	else
	{
		notifyCp->m_saveButton->setIsDisabled(VFX_FALSE);
	}
	return MMI_RET_OK;
}
#endif /* (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__)) */ 

void VappSmsClass0NotifyCp::updateView()
{



	m_curNotifyIndex = m_relatedNmgr->getNotifyIndex();

	//update phone number
	VfxWString fromAddr;
	m_relatedNmgr->getFormatAddr(m_curNotifyIndex, fromAddr);
	m_contactFrame->setString(fromAddr);

    //update message content
    VfxWString content;
	m_relatedNmgr->getContent(m_curNotifyIndex, content);
	m_contentView->setText(content);


	//update timestamp
	VfxWString timestamp;
	m_relatedNmgr->getFormatTimestamp(m_curNotifyIndex, timestamp);
	m_timeFrame->setString(timestamp);
	VcpRichTextCustomFrame customFrame;
	customFrame.setFrame(m_timeFrame);

	customFrame.setRange(content.getLength(), content.getLength());
	customFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN);
	m_contentView->setTextFormat(&customFrame);


    onUpdate();
}

void VappSmsClass0NotifyCp::onUpdate()
{
    VfxS32 popupWidthAdd, textWidthAdd, buttonWidthAdd, maxDecressHieght;

    setAnchor(0.5, 0.5);

    if (m_dir == VFX_SCR_ROTATE_TYPE_90 || m_dir == VFX_SCR_ROTATE_TYPE_270)
    {
        popupWidthAdd = VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH;
        textWidthAdd= VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH;
        buttonWidthAdd = VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH/2;
        maxDecressHieght = VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_CUT_HEIGHT;
        setPos(VAPP_SMS_CLASS0_MID_HEIGHT, VAPP_SMS_CLASS0_MID_WIDTH);
    }
    else
    {
        popupWidthAdd = 0;
        textWidthAdd= 0;
        buttonWidthAdd = 0;
        maxDecressHieght = 0;
        setPos(VAPP_SMS_CLASS0_MID_WIDTH, VAPP_SMS_CLASS0_MID_HEIGHT);
    }

    m_backgroundBottom->setSize(VAPP_SMS_CLASS0_WIDTH + popupWidthAdd, VAPP_SMS_CLASS0_BOTTOM_FRAME_HEIGHT);

	if (m_notifyType == NOTIFY_CP_TYPE_SMS)
	{
    m_saveButton->setInnerRect(VfxRect(
                                    VAPP_SMS_CLASS0_BUTTON1_X, 
                                    VAPP_SMS_CLASS0_BUTTON1_Y, 
                                    VAPP_SMS_CLASS0_BUTTON_WIDTH + buttonWidthAdd, 
                                    VAPP_SMS_CLASS0_BUTTON_HEIGHT
                                 ));
    m_closeButton->setInnerRect(VfxRect(
                                    VAPP_SMS_CLASS0_BUTTON2_X + buttonWidthAdd, 
                                    VAPP_SMS_CLASS0_BUTTON2_Y, 
                                    VAPP_SMS_CLASS0_BUTTON_WIDTH + buttonWidthAdd, 
                                    VAPP_SMS_CLASS0_BUTTON_HEIGHT
                                 ));
	}
	else
	{
	    m_okButton->setInnerRect(VfxRect(
                                VAPP_SMS_CLASS0_BUTTON1_X, 
                                VAPP_SMS_CLASS0_BUTTON1_Y, 
                                VAPP_SMS_CLASS0_BUTTON_WIDTH + VAPP_SMS_CLASS0_BUTTON2_X - VAPP_SMS_CLASS0_BUTTON1_X + 2*buttonWidthAdd, 
                                VAPP_SMS_CLASS0_BUTTON_HEIGHT
                             ));
	}

    m_contactFrame->setSize(VAPP_SMS_CLASS0_CONTACT_FRAME_WIDTH + textWidthAdd, VAPP_SMS_CLASS0_CONTACT_FRAME_HEIGHT);
    m_contentView->setSize(VAPP_SMS_CLASS0_CONTENT_VIEW_WIDTH + textWidthAdd, m_contentView->getSize().height);
    m_contentView->setAutoResized(
        VFX_TRUE, VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT,
        VAPP_SMS_CLASS0_CONTENT_VIEW_MAX_HEIGHT - maxDecressHieght);

}

void VappSmsClass0NotifyCp::onDeinit()
{

#if (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__))
	if (m_notifyType == NOTIFY_CP_TYPE_SMS)
	{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_READY, &VappSmsClass0NotifyCp::onSmsReady, getObjHandle());
	}
#endif /* (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__)) */ 
    VfxBasePopup::onDeinit();
}

void VappSmsClass0NotifyCp::onRotate(const VfxScreenRotateParam &param)
{
    m_dir = param.rotateTo;
    onUpdate();
    VfxBasePopup::onRotate(param);
}

void VappSmsClass0NotifyCp::onContentBoundsChanged(VfxFrame *frame, const VfxRect &rect)
{
    if (frame == m_contentView)
    {
        VfxS32 popupWidthAdd;

        if (m_dir == VFX_SCR_ROTATE_TYPE_90 || m_dir == VFX_SCR_ROTATE_TYPE_270)
        {
            popupWidthAdd = VAPP_SMS_CLASS0_CONTENT_VIEW_LANDSCAPE_ADD_WIDTH;
        }
        else
        {
            popupWidthAdd = 0;
        }

        VfxS32 contentHeight = m_contentView->getSize().height;
        VfxS32 extheight = contentHeight - VAPP_SMS_CLASS0_CONTENT_VIEW_MIN_HEIGHT;
        VfxS32 class0Height = VAPP_SMS_CLASS0_HEIGHT + extheight;
        VfxS32 topHeight = VAPP_SMS_CLASS0_TOP_FRAME_HEIGHT + extheight;

        setSize(VAPP_SMS_CLASS0_WIDTH+popupWidthAdd, class0Height);
        m_backgroundTop->setSize(VAPP_SMS_CLASS0_WIDTH+popupWidthAdd, topHeight);
        m_backgroundBottom->setPos(0, topHeight);
    }
}

void VappSmsClass0NotifyCp::onButtonClicked(VfxObject *sender, VfxId id)
{

	if (m_notifyType == NOTIFY_CP_TYPE_SMS)
	{
    SmsClass0NotifyManager *class0Manager= VFX_OBJ_GET_INSTANCE(SmsClass0NotifyManager);

        if (id == ITEM_ID_BUTTON_SAVE)
        {			
			//srv_sms_memory_status_struct status;
    		//vfx_sys_mem_zero(&status, sizeof(srv_sms_memory_status_struct));
   
       		//srv_sms_get_memory_status(SRV_SMS_SIM_1, &status);
			//if (status.me_used >= status.me_total)
			//{
				//VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
				//balloon->addItem(VCP_INFO_BALLOON_TYPE_SUCCESS, VFX_WSTR_RES(STR_ID_VAPP_SMS_PHONE_STORAGE_EXCEEDED));
				//return;
			//}
            class0Manager->m_signalClass0Saved.connect(this, &VappSmsClass0NotifyCp::onSaved);
		m_saveButton->setIsDisabled(VFX_TRUE);
		m_closeButton->setIsDisabled(VFX_TRUE);
            class0Manager->save(m_curNotifyIndex);
        }
        else if (id == ITEM_ID_BUTTON_DISCARD)
        {
	        m_relatedNmgr->deleteInd(m_curNotifyIndex);
	        m_relatedNmgr->notify(VFX_FALSE);
        }
    }
	else
		{
		m_relatedNmgr->deleteInd(m_curNotifyIndex);
		m_relatedNmgr->notify(VFX_TRUE);
		
        }
}

VfxBool VappSmsClass0NotifyCp::onKeyInput(VfxKeyEvent & event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN
        && event.keyCode == VFX_KEY_CODE_BACK
        )
    {
        m_relatedNmgr->deleteInd(m_curNotifyIndex);
        m_relatedNmgr->notify(VFX_FALSE);
    }

    return VfxBasePopup::onKeyInput(event);
}

void VappSmsClass0NotifyCp::onSaved(
    VfxBool result,
    srv_sms_cause_enum cause)
{
        SmsClass0NotifyManager *class0Manager= VFX_OBJ_GET_INSTANCE(SmsClass0NotifyManager);

        class0Manager->m_signalClass0Saved.disconnect(this, &VappSmsClass0NotifyCp::onSaved);

		m_saveButton->setIsDisabled(VFX_FALSE);
		m_closeButton->setIsDisabled(VFX_FALSE);
        if (result)
        {
    	class0Manager->deleteInd(m_curNotifyIndex);
            class0Manager->notify(VFX_FALSE);
        }
        else
        {
		    VcpConfirmPopup *failPopup;	    
	        VFX_OBJ_CREATE(failPopup, VcpConfirmPopup, this->getParent());
	        failPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
	        failPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
	        failPopup->setText((VfxResId)STR_GLOBAL_FAILED_TO_SAVE);
	        failPopup->show(VFX_TRUE);
        }

}

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


static VfxScrRotateTypeEnum g_vapp_sms_class0_dir = VFX_SCR_ROTATE_TYPE_NORMAL;

#if (defined(__DM_LAWMO_SUPPORT__) || defined(__DM_MO_SUPPORT__))
mmi_ret VappSmsClass0CancelInd(mmi_event_struct *evt)
{
	VappClass0NewMsgApp *app = (VappClass0NewMsgApp *)VfxAppLauncher::findApp(VAPP_SMS_CLASS0, VFX_OBJ_CLASS_INFO(VappClass0NewMsgApp), 
		VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
	
	if (app)
    {
		VfxAppLauncher::terminate(app->getGroupId());
    }
	return MMI_RET_OK;	
}
#endif






MMI_BOOL vapp_sms_class0_scrn_entry(mmi_scenario_id scen_id,void * arg)
    {
	VappClass0NewMsgApp *app = (VappClass0NewMsgApp *)VfxAppLauncher::findApp(VAPP_SMS_CLASS0, VFX_OBJ_CLASS_INFO(VappClass0NewMsgApp), 
		VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

	if (app)
{
		app->updateView();
		app->setActive();
    }
	else
	{
    VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    g_vapp_sms_class0_dir = toplevel->getScreenRotateType();

		mmi_id app_id = VfxAppLauncher::launch(
			VAPP_SMS_CLASS0, 
			VFX_OBJ_CLASS_INFO(VappClass0NewMsgApp),
			GRP_ID_ROOT,
			NULL, 
			0);
	}

    return MMI_TRUE;
}
#ifdef __cplusplus
}

#endif /* __cplusplus */


/*************************sms class0*********************/


VappSmsClass0ViewerScr::VappSmsClass0ViewerScr(VfxScrRotateTypeEnum dir):
	m_notifyCp(NULL),
	m_rotation(dir)

{
    setIsSmallScreen();
}

void VappSmsClass0ViewerScr::onInit()
{
    VfxAppScr::onInit();
    VFX_OBJ_CREATE_EX(
        m_notifyCp,
        VappSmsClass0NotifyCp,
        this,
        (g_vapp_sms_class0_dir, VappSmsClass0NotifyCp::NOTIFY_CP_TYPE_SMS));
	SmsClass0NotifyManager *class0Mgr = VFX_OBJ_GET_INSTANCE(SmsClass0NotifyManager);
	m_notifyCp->setRelatedNmgr(class0Mgr);
	m_notifyCp->updateView();


}
void VappSmsClass0ViewerScr::onEnter(VfxBool isBackward)
{
	VfxAppScr::onEnter(isBackward);
	m_notifyCp->show(VFX_TRUE);
}

void VappSmsClass0ViewerScr::updateView()
{
	m_notifyCp->updateView();
}

void VappSmsClass0ViewerScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = m_rotation;
}

/*****************************************************************************
 * Class VappClass0NewMsgApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappClass0NewMsgApp", VappClass0NewMsgApp, VfxApp);

VappClass0NewMsgApp::VappClass0NewMsgApp() : m_popupViewer(NULL)
{}


void VappClass0NewMsgApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
	SmsClass0NotifyManager *class0Mgr = VFX_OBJ_GET_INSTANCE(SmsClass0NotifyManager);
	class0Mgr->setRelatedApp(this);
	VFX_OBJ_CREATE_EX(m_popupViewer, VappSmsClass0ViewerScr, this, (g_vapp_sms_class0_dir));
	m_popupViewer->show();
}

void VappClass0NewMsgApp::updateView()
    {
	m_popupViewer->updateView();
}

void VappClass0NewMsgApp::onDeinit()
{
	SmsClass0NotifyManager *class0Mgr = VFX_OBJ_GET_INSTANCE(SmsClass0NotifyManager);
    class0Mgr->setRelatedApp(NULL);
    VfxApp::onDeinit();
}

void VappClass0NewMsgApp::onGroupActive()
{
	mmi_frm_start_scenario(MMI_SCENARIO_ID_NEW_CLASS0_SMS);
}
void VappClass0NewMsgApp::onGroupInactive()
{
	mmi_frm_end_scenario(MMI_SCENARIO_ID_NEW_CLASS0_SMS);
}



