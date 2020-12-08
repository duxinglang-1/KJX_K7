/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  Vapp_CBS_viewer_page.cpp
 *
 * Project:
 * --------
 *  App CBS
 *
 * Description:
 * ------------
 *  Venus App CBS multi option screen implements for C++
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#include "vapp_cbs_setting_page.h"
#include "vapp_cbs_channel_page.h"

#include "Vapp_cbs_iprot.h"
#include "vapp_cbs_viewer_page.h"
#include "vapp_cbs_new_msg.h"
#include "vapp_sms_util.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined( __MMI_MAINLCD_320X480__)
#define VAPP_CBS_VIEWER_LAYOUT_0_DEGREE		VAPP_CBS_LAYOUT_VIEWER_320_480_NORMAL
#define VAPP_CBS_VIEWER_LAYOUT_90_DEGREE	VAPP_CBS_LAYOUT_VIEWER_320_480_LANDSCAPE
#define VAPP_CBS_VIEWER_CONTENT_FONT_SIZE	18
#define VAPP_CBS_VIEWER_TIME_FONT_SIZE		14
#define VAPP_CBS_VIEWER_CONTENT_TIME_Y_GAP	10

#define VAPP_CBS_VIEWER_TITLE_NAME_FONT_SIZE 24
#define VAPP_CBS_VIEWER_TITLE_ID_FONT_SIZE	14
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_CBS_VIEWER_LAYOUT_0_DEGREE		VAPP_CBS_LAYOUT_VIEWER_480_800_NORMAL
#define VAPP_CBS_VIEWER_LAYOUT_90_DEGREE	VAPP_CBS_LAYOUT_VIEWER_480_800_LANDSCAPE
#define VAPP_CBS_VIEWER_CONTENT_FONT_SIZE	32
#define VAPP_CBS_VIEWER_TIME_FONT_SIZE		23
#define VAPP_CBS_VIEWER_CONTENT_TIME_Y_GAP	18

#define VAPP_CBS_VIEWER_TITLE_NAME_FONT_SIZE 35
#define VAPP_CBS_VIEWER_TITLE_ID_FONT_SIZE	26
#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_CBS_VIEWER_LAYOUT_0_DEGREE		VAPP_CBS_LAYOUT_VIEWER_240_320_NORMAL
#define VAPP_CBS_VIEWER_LAYOUT_90_DEGREE	VAPP_CBS_LAYOUT_VIEWER_240_320_LANDSCAPE
#define VAPP_CBS_VIEWER_CONTENT_FONT_SIZE	14
#define VAPP_CBS_VIEWER_TIME_FONT_SIZE		11
#define VAPP_CBS_VIEWER_CONTENT_TIME_Y_GAP	5

#define VAPP_CBS_VIEWER_TITLE_NAME_FONT_SIZE 18
#define VAPP_CBS_VIEWER_TITLE_ID_FONT_SIZE	13

#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_CBS_VIEWER_LAYOUT_0_DEGREE		VAPP_CBS_LAYOUT_VIEWER_240_400_NORMAL
#define VAPP_CBS_VIEWER_LAYOUT_90_DEGREE	VAPP_CBS_LAYOUT_VIEWER_240_400_LANDSCAPE
#define VAPP_CBS_VIEWER_CONTENT_FONT_SIZE	14
#define VAPP_CBS_VIEWER_TIME_FONT_SIZE		11
#define VAPP_CBS_VIEWER_CONTENT_TIME_Y_GAP	5

#define VAPP_CBS_VIEWER_TITLE_NAME_FONT_SIZE 18
#define VAPP_CBS_VIEWER_TITLE_ID_FONT_SIZE	13

#else
#define VAPP_CBS_VIEWER_LAYOUT_0_DEGREE		VAPP_CBS_LAYOUT_VIEWER_320_480_NORMAL
#define VAPP_CBS_VIEWER_LAYOUT_90_DEGREE	VAPP_CBS_LAYOUT_VIEWER_320_480_LANDSCAPE
#define VAPP_CBS_VIEWER_CONTENT_FONT_SIZE	18
#define VAPP_CBS_VIEWER_TIME_FONT_SIZE		14
#define VAPP_CBS_VIEWER_CONTENT_TIME_Y_GAP	10

#define VAPP_CBS_VIEWER_TITLE_NAME_FONT_SIZE 24
#define VAPP_CBS_VIEWER_TITLE_ID_FONT_SIZE	14
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Class Xyz
 ****************************************************************************/


//VFX_IMPLEMENT_CLASS("VappCbsViewerPage", VappCbsViewerPage, VfxPage);

void VappCbsViewerPage::onInit()
{
    VfxPage::onInit();	
    mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_DEL_MSG, cbsMsgChangeProc, this);
	mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_DEL_CHNL, cbsMsgChangeProc, this);
	VfxXmlLoader::loadBegin(this, VAPP_CBS_VIEWER_LAYOUT_0_DEGREE);
    initElements();
    VfxXmlLoader::loadEnd();
	
} 

void VappCbsViewerPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
}
void VappCbsViewerPage::onRotate(
	const VfxScreenRotateParam &param // The parameter to rotate
)
{
	deleteMemberFromLayout();	
	if (param.rotateTo == VFX_SCR_ROTATE_TYPE_90 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270)
	{
		VfxXmlLoader::loadBegin(this, VAPP_CBS_VIEWER_LAYOUT_90_DEGREE);
	}
	else
	{
		VfxXmlLoader::loadBegin(this, VAPP_CBS_VIEWER_LAYOUT_0_DEGREE);
	}
    initElements();
    VfxXmlLoader::loadEnd();
	setElements();
	updateContent();
};

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
#endif
VappMsgAddrType VappCbsViewerPage::keywordToAddrtype(VcpTextKeyWordEnum mode)
{
	VappMsgAddrType addrType = VAPP_MSG_ADDR_TYPE_NONE;
	switch (mode)
	{
		case VCP_TEXT_KEYWORD_PHONENUMBER:
			addrType = VAPP_MSG_ADDR_TYPE_PHONENUMBER;
			break;

		case VCP_TEXT_KEYWORD_EMAIL:
			addrType = VAPP_MSG_ADDR_TYPE_EMAIL;
			break;

		case VCP_TEXT_KEYWORD_URL:
			addrType = VAPP_MSG_ADDR_TYPE_URL;
			break;

		case VCP_TEXT_KEYWORD_USSD:
			addrType = VAPP_MSG_ADDR_TYPE_USSD;
			break;

		default:
			break;
	}
	return addrType;
}

void VappCbsViewerPage::onKeywordClicked(VcpTextKeyWordEnum mode, VfxWChar *text, VfxS32 textLen)
{

	VfxWString address;
	VfxWChar *addrText;
	VFX_ALLOC_MEM(addrText, (textLen + 1) * 2, this);
	memcpy(addrText, text, textLen * 2);
	addrText[textLen] = '\0';
	address.loadFromMem(addrText);
	VFX_FREE_MEM(addrText);
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
	VappMsgAddrType addrType = keywordToAddrtype(mode);

	if (m_addrOption == NULL)
	{
		VFX_OBJ_CREATE(m_addrOption, VappMsgAddrOption, this);
	}

	m_addrOption->setAddrItem(address, addrType);
	m_addrOption->show(this);
}

void VappCbsViewerPage::setElements()// layout title, layout text viewer
{
	
	m_titleText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(24)));  
	m_titleText->setColor(VFX_COLOR_WHITE); 
	 
	m_titleId->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(14)));
	m_titleId->setColor(VFX_COLOR_WHITE);

	m_toolBar->addItem(DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
#ifdef __MMI_SMS_DETAILS_INFO__
	m_toolBar->addItem(USE_DETAIL, (VfxResId)STR_GLOBAL_DETAILS, IMG_ID_VAPP_CBS_VIEWER_USE_DETAIL);
#endif
	m_toolBar->m_signalButtonTap.connect(this, &VappCbsViewerPage::onToolBarClicked);

	m_iconBorder->setImgContent(VfxImageSrc(IMG_ID_VAPP_CBS_VIEWER_TITLE_BG_BORDER));
	
	m_iconBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_CBS_VIEWER_TITLE_BG_IMAGE));
	
	m_titleBgFrame->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));

	m_contentText->setKeyword(VCP_TEXT_KEYWORD_PHONENUMBER
	#ifdef __MMI_EMAIL__
		| VCP_TEXT_KEYWORD_EMAIL
	#endif
		| VCP_TEXT_KEYWORD_URL 
		| VCP_TEXT_KEYWORD_USSD);
	m_contentText->m_signalKeywordClick.connect(this, &VappCbsViewerPage::onKeywordClicked);
    m_contentText->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(VAPP_SMS_TEXT_COLOR));

}

void VappCbsViewerPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_DEL_MSG, cbsMsgChangeProc, this);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_DEL_CHNL, cbsMsgChangeProc, this);
	
	VfxObject *detailsPage = (VfxObject *)m_detailsPage.get();
	VFX_OBJ_CLOSE(detailsPage);

	//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_VIEWER_ENTRY,  m_sim, m_msgId, m_contentText);
	VfxPage::onDeinit();
}

void VappCbsViewerPage::updateContent()
{
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_VIEWER_ENTRY, m_sim, m_msgId, m_contentText);

	VfxWChar channelName[SRV_CBS_CHNL_NAME_LEN + 1];
	srv_cbs_get_channel_name(channelName, m_channelId, vapp_sms_sim_index_to_sim_id(m_sim));
	
	VfxWString channelId;
	channelId.format("%d", m_channelId);

	m_titleText->setString(channelName);
	m_titleId->setString(channelId);
	
	m_titleText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_CBS_VIEWER_TITLE_NAME_FONT_SIZE)));
	m_titleId->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_CBS_VIEWER_TITLE_ID_FONT_SIZE)));

	// add time stamp
	U32 timestampInt;
	timestampInt = srv_cbs_get_msg_time(m_msgId, vapp_sms_sim_index_to_sim_id(m_sim));
	
	MYTIME time;
	mmi_dt_utc_sec_2_mytime(timestampInt, &time, MMI_FALSE);
	
	VfxDateTime timeStamp;
	timeStamp.setDate(time.nYear, time.nMonth, time.nDay);
	timeStamp.setTime(time.nHour, time.nMin, time.nSec);
	
	VfxDateTime todayStart;
	todayStart.setCurrentTime();
	todayStart.setTime(0, 0, 0);
	
	VfxU32 flags = 0;
	flags = VFX_DATE_TIME_DATE_YEAR |VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
	VfxWChar datatime[CBS_DATATIME_BUFF_LEN + 1];
	timeStamp.getDateTimeString(flags, datatime, CBS_DATATIME_BUFF_LEN);
	
	VfxWString text;
	text.loadFromMem(datatime);
    m_timestampFrame->setPos(VfxPoint(0, VAPP_CBS_VIEWER_CONTENT_TIME_Y_GAP));
    m_timestampFrame->setColor(VFX_COLOR_GREY);
    m_timestampFrame->setString(datatime);
    m_timestampFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_CBS_VIEWER_TIME_FONT_SIZE)));

	VfxWString content;
	content.loadFromMem(m_msgContent);
	m_contentText->setText(content);
	m_contentText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_CBS_VIEWER_CONTENT_FONT_SIZE)));
	
    VcpRichTextCustomFrame customFrame;
    customFrame.setFrame(m_timestampFrame);
    customFrame.setRange(content.getLength(), content.getLength());
    customFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN);
	m_contentText->addTextFormat(customFrame);

	m_contentText->forceUpdate();
	#ifdef __MMI_SMS_DETAILS_INFO__
    if (m_contentText->getTextStorage()->getRichTextFormat()->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
	{
		m_toolBar->setDisableItem(USE_DETAIL, VFX_TRUE);
	}
	#endif
	emitMsgViewedEvt();
}

void VappCbsViewerPage::emitMsgViewedEvt()
{
	VappCbsMSgViewedStruct event_data;
	MMI_FRM_INIT_EVENT(&event_data, EVT_ID_VAPP_CBS_MSG_VIEWED_IND);
	event_data.sim_id = vapp_sms_sim_index_to_sim_id(m_sim);
	event_data.msg_id = m_msgId;
	MMI_FRM_CB_EMIT_EVENT(&event_data);
}


void VappCbsViewerPage::initElements()
{

    VFX_OBJ_CREATE(m_timestampFrame, VfxTextFrame, this);
    

    m_bgFrame = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("bgFrame")), 
        VfxFrame);
	m_bgFrame->setBgColor(VFX_COLOR_RES(VAPP_SMS_VIEWER_TEXT_BACKGROUND_COLOR));
    

    m_titleBgFrame = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("titleBg")), 
        VfxFrame);
	

    m_iconBorder = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("iconBorder")),
        VfxFrame);
        
 
    m_iconBg = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("iconBg")),
        VfxFrame);


    m_icon = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("icon")),
        VfxImageFrame);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    m_titleText = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("titleText")),
        VfxTextFrame);
        

    m_titleId = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("channelId")), 
        VfxTextFrame);
        

    m_contentText = VFX_OBJ_DYNAMIC_CAST(
           VfxXmlLoader::findObjByName(VFX_WSTR("contentText")), 
           VcpTextView);
        

    m_toolBar = VFX_OBJ_DYNAMIC_CAST(
        VfxXmlLoader::findObjByName(VFX_WSTR("toolBar")), 
        VcpToolBar);
    m_toolBar->m_signalButtonTap.connect(this, &VappCbsViewerPage::onToolBarClicked);
}


void VappCbsViewerPage::deleteMemberFromLayout()
{
	VFX_OBJ_CLOSE(m_bgFrame);

	VFX_OBJ_CLOSE(m_titleBgFrame);
	VFX_OBJ_CLOSE(m_iconBorder);
	VFX_OBJ_CLOSE(m_iconBg);
	
	VFX_OBJ_CLOSE(m_icon);
		   
	VFX_OBJ_CLOSE(m_titleText);
	VFX_OBJ_CLOSE(m_titleId);
	
	VFX_OBJ_CLOSE(m_timestampFrame);
	VFX_OBJ_CLOSE(m_contentText); // will close time stamp

	VFX_OBJ_CLOSE(m_toolBar);
}


void VappCbsViewerPage::deleteCurrMsg()
{
	m_isDeleting = VFX_TRUE;
	//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_VIEWER_PRE_DELETE, m_sim, 0XFFFF, m_msgId);
	if (srv_cbs_delete_msg(m_msgId, vapp_sms_sim_index_to_sim_id(m_sim)))
	{
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_VIEWER_DELETE_RESULT, m_sim, 0XFFFF, m_msgId, 1);
		exit();
	}
	else
	{
		//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_VIEWER_DELETE_RESULT, m_sim, 0XFFFF, m_msgId, 0);
		//showErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_CBS_CHANNEL_VIEWER_DELETE_INFORM));
		vapp_cbs_show_error_confirm(this, VFX_WSTR_RES(STR_ID_VAPP_CBS_CHANNEL_VIEWER_DELETE_INFORM), CBS_FAILURE_CONF);
	}
	m_isDeleting = VFX_FALSE;
}
VappCbsViewerPage::VappCbsViewerPage(VfxS32 sim) : 
	//m_title(NULL), 
	m_channelId(VAPP_CB_INVALID_CHANNEL_ID), 
	m_msgId(VAPP_CB_INVALID_MSG_ID),
	m_sim(sim),
	m_isDeleting(VFX_FALSE),
	m_confirmPopup(NULL),
	m_bgFrame(NULL),
	m_contentText(NULL), 
	m_toolBar(NULL), 
	m_timestampFrame(NULL), 				
	m_addrOption(NULL)
{
	// do nothing but init members
};
//void VappCbsViewerPage::setSim(VappCbsSimEnum simId)
//{
	//m_sim = simId;
//};
//void VappCbsViewerPage::setMsgId(VfxId msgId)
//{
	//m_msgId = msgId;
//};
//void VappCbsViewerPage::setChannelId(VfxId channel)
//{
	//m_channelId = channel;
//}

void VappCbsViewerPage::setMsgIdAndChannelId(VfxId msgId, VfxId channel)
{
	m_msgId = msgId;
	m_channelId = channel;
}

VfxBool VappCbsViewerPage::readContent()
{
	return (VfxBool)srv_cbs_read_msg(m_msgId, vapp_sms_sim_index_to_sim_id(m_sim), (WCHAR *)m_msgContent, SRV_CBS_MAX_CONTENT_LEN);
};


void VappCbsViewerPage::confirmHandler(VfxObject* obj, VfxId id)
{
	VFX_OBJ_CLOSE(m_confirmPopup);
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		deleteCurrMsg();
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
#endif
}

void VappCbsViewerPage::onToolBarClicked(VfxObject *sender, VfxId id)
{
	switch(id)
	{
		case DELETE:
		{
			m_confirmPopup = vapp_cbs_show_error_confirm(this, VFX_WSTR_RES(STR_ID_VAPP_CBS_CHANNEL_VIEWER_DELETE_CONFIRM), CBS_WARNING_CONF);
			//VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
		    //m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
			//VfxWString ask = VFX_WSTR_RES(STR_ID_VAPP_CBS_CHANNEL_VIEWER_DELETE_CONFIRM);
		    //m_confirmPopup->setText(ask);
			//
		    //m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		   // m_confirmPopup->setCustomButton((VFX_WSTR_RES(STR_GLOBAL_DELETE)) , (VFX_WSTR_RES(STR_GLOBAL_CANCEL)), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
		    //m_confirmPopup->show(VFX_TRUE);
		    m_confirmPopup->m_signalButtonClicked.connect(this, &VappCbsViewerPage::confirmHandler);
			break;
		}
	#ifdef __MMI_SMS_DETAILS_INFO__
		case USE_DETAIL:
		{
			VappMsgUseDetailProvider *provider;
			VFX_OBJ_CREATE(provider, VappMsgUseDetailProvider, this);
			addAddrItemToUseDetail(provider);

            mmi_sim_enum MMISim = MMI_SIM1;
            MMISim = (mmi_sim_enum)(vapp_sms_sim_index_to_sim_id(m_sim) & 0x00FF);
            provider->setSimId(MMISim);

			VfxMainScr *mainScr;
			mainScr = getMainScr();
			VappMsgUseDetailPage *detailsPage = NULL;
			VFX_OBJ_CREATE(detailsPage, VappMsgUseDetailPage, mainScr);
			m_detailsPage = detailsPage;
			detailsPage->setProvider(*provider);
			mainScr->pushPage('CBUD', detailsPage);
			VFX_OBJ_CLOSE(provider);
			break;
		}
	#endif
		default:
		{
			//VFX_ASSERT((id == DELETE) || (id == USE_DETAIL));
			break;
		}
	}
}
#ifdef __MMI_SMS_DETAILS_INFO__

void VappCbsViewerPage::addAddrItemToUseDetail(VappMsgUseDetailProvider* provider)
{
	VcpTextStorage *textStorage = m_contentText->getTextStorage();
	VcpRichTextFormat *textFormat = textStorage->getRichTextFormat();
	for (; textFormat; textFormat = textFormat->getNext())
	{
		if (textFormat->m_type == VCP_RICH_TEXT_TYPE_TEXT)
		{
			VcpRichText *richtext= (VcpRichText*)textFormat;
			VappMsgAddrType addrType = keywordToAddrtype(richtext->m_mode);
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
		#endif
            if (addrType != VAPP_MSG_ADDR_TYPE_NONE)
			{
				VfxWChar *addrText;
				VfxWString address;
				VfxWChar *content = m_contentText->getText();
				VfxU32 start = textFormat->m_range.getStart();
				VfxU32 textLen = textFormat->m_range.getEnd()- start;

				VFX_ALLOC_MEM(addrText, (textLen + 1) * 2, this);
				memcpy(addrText, &content[start], textLen * 2);
				addrText[textLen] = '\0';
				address.loadFromMem(addrText);
				provider->addAddrItem(address, addrType);

				VFX_FREE_MEM(addrText);
			}
		}
	}
}
#endif


mmi_ret VappCbsViewerPage::cbsMsgChangeProc(mmi_event_struct *param)
{
	VappCbsViewerPage *currPage = (VappCbsViewerPage*)param->user_data;
	if (!currPage->m_isDeleting)
	{
		SRV_SIM_ENUM currSim = vapp_sms_sim_index_to_sim_id(currPage->m_sim);
		VfxU32 msg_id = 0;
		srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
		VfxU32 chnl_id = 0;
        VfxBool isNeedDelete = VFX_FALSE;

		switch(param->evt_id)
		{
			
			case EVT_ID_SRV_CBS_DEL_MSG:
			{
				
				srv_cbs_del_msg_event_struct *event = (srv_cbs_del_msg_event_struct*)param;
				msg_id = event->msg_id;
				sim_id = event->sim_id;
				VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_VIEWER_MSG_CHANGE_PROC, param->evt_id, msg_id, sim_id);
				if ((sim_id == currSim) && 
				(msg_id == currPage->m_msgId))
				{
                    isNeedDelete = VFX_TRUE;
				}
	            break;
			}
			
			case EVT_ID_SRV_CBS_DEL_CHNL:
			{
				srv_cbs_del_chnl_event_struct *event = (srv_cbs_del_chnl_event_struct *)param;
				chnl_id = event->chnl_id;
				sim_id = event->sim_id;
				VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_VIEWER_CHANNEL_CHANGE_PROC, param->evt_id, chnl_id);
				if ((sim_id == currSim) && 
					(chnl_id == currPage->m_channelId))
				{
                    isNeedDelete = VFX_TRUE;
				}
	            break;
			}
		}
        if (isNeedDelete)
        {
            //VcpConfirmPopup *errorPrompt = NULL;
            //VFX_OBJ_CREATE(errorPrompt, VcpConfirmPopup, currPage->getParent());
            //errorPrompt->setInfoType(VCP_POPUP_TYPE_INFO);
            //errorPrompt->setText(VFX_WSTR_RES(STR_GLOBAL_DELETED));
            //errorPrompt->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            //errorPrompt->setAutoDestory(VFX_TRUE);
            //errorPrompt->show(VFX_TRUE);
			vapp_cbs_show_error_confirm(currPage->getParent(), VFX_WSTR_RES(STR_GLOBAL_DELETED), CBS_INFO_CONF);
            currPage->exit();

        }
	}
	return MMI_RET_OK;
}



