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
 * Vapp_cbs_new_msg.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines class of CB app pages of venus.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================

**********************************************************************************/
#include "mmi_features.h"

#include "vapp_cbs_new_msg.h"
#include "mmi_rp_vapp_cb_new_msg_def.h"
#include "mmi_rp_srv_venus_component_popup_def.h"

#include "vapp_sms_util.h"

static VfxScrRotateTypeEnum g_vapp_cbs_new_msg_background_scrn_rotation;

#if defined( __MMI_MAINLCD_320X480__)
#define VAPP_CBS_POPUP_VIEWER_WIDTH  					284
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN                168
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX                286
#define VAPP_CBS_POPUP_VIEWER_X_GAP                     18
#define VAPP_CBS_POPUP_VIEWER_WIDTH_LANDSCAPE  			(VAPP_CBS_POPUP_VIEWER_WIDTH + 50)
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN_LANDSCAPE      VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX_LANDSCAPE      (LCD_WIDTH  - (LCD_HEIGHT - VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX))

#define VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP 				23 
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE			23
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_COLOR 			(255, 15, 15, 15)
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT			(VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE + 4)

#define VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM 13
#define VAPP_CBS_POPUP_VIEWER_CONTENT_FONT_SIZE			18


#define VAPP_CBS_POPUP_VIEWER_TIME_FONT_SIZE			14

#define VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP     	18
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP     	14
#define VAPP_CBS_POPUP_VIEWER_BUTTON_Y_POS  			210
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT  			40


#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_CBS_POPUP_VIEWER_WIDTH  					446
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN                282
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX                720
#define VAPP_CBS_POPUP_VIEWER_X_GAP                     26
#define VAPP_CBS_POPUP_VIEWER_WIDTH_LANDSCAPE  			(VAPP_CBS_POPUP_VIEWER_WIDTH + 75)
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN_LANDSCAPE      VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX_LANDSCAPE      (LCD_WIDTH  - (LCD_HEIGHT - VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX))

#define VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP 				37 
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE			30
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_COLOR 			(255, 21, 21, 21)
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT			(VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE + 6)

#define VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM 11
#define VAPP_CBS_POPUP_VIEWER_CONTENT_FONT_SIZE			21

#define VAPP_CBS_POPUP_VIEWER_TIME_FONT_SIZE			20

#define VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP     	30
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP     	16
#define VAPP_CBS_POPUP_VIEWER_BUTTON_Y_POS  			210
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT         	80


#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_CBS_POPUP_VIEWER_WIDTH  					222
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN                168
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX                220
#define VAPP_CBS_POPUP_VIEWER_X_GAP                     8
#define VAPP_CBS_POPUP_VIEWER_WIDTH_LANDSCAPE  			(VAPP_CBS_POPUP_VIEWER_WIDTH + 20)
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN_LANDSCAPE      VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX_LANDSCAPE      (LCD_WIDTH - 14 -6)

#define VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP 				17 
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE			16
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_COLOR 			(255, 21, 21, 21)
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT			(VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE + 4)

#define VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM 5
#define VAPP_CBS_POPUP_VIEWER_CONTENT_FONT_SIZE			14

#define VAPP_CBS_POPUP_VIEWER_TIME_FONT_SIZE			14

#define VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP     	13
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP     	5
#define VAPP_CBS_POPUP_VIEWER_BUTTON_Y_POS  			210
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT  			40


#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_CBS_POPUP_VIEWER_WIDTH  					222
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN                168
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX                300
#define VAPP_CBS_POPUP_VIEWER_X_GAP                     8
#define VAPP_CBS_POPUP_VIEWER_WIDTH_LANDSCAPE  			(VAPP_CBS_POPUP_VIEWER_WIDTH + 20)
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN_LANDSCAPE      VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX_LANDSCAPE      (LCD_WIDTH - 14 - 6)

#define VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP 				17 
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE			16
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_COLOR 			(255, 21, 21, 21)
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT			(VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE + 4)

#define VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM 5
#define VAPP_CBS_POPUP_VIEWER_CONTENT_FONT_SIZE			14


#define VAPP_CBS_POPUP_VIEWER_TIME_FONT_SIZE			14

#define VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP     	13
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP     	5
#define VAPP_CBS_POPUP_VIEWER_BUTTON_Y_POS  			210
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT  			40

#else
#define VAPP_CBS_POPUP_VIEWER_WIDTH  					284
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN                168
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX                286
#define VAPP_CBS_POPUP_VIEWER_X_GAP                     18
#define VAPP_CBS_POPUP_VIEWER_WIDTH_LANDSCAPE  			(LCD_HEIGHT - (LCD_WIDTH - VAPP_CBS_POPUP_VIEWER_WIDTH))
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN_LANDSCAPE      VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN
#define VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX_LANDSCAPE      (LCD_WIDTH  - (LCD_HEIGHT - VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX))

#define VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP 				23 
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE			23
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_COLOR 			(255, 15, 15, 15)
#define VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT			(VAPP_CBS_POPUP_VIEWER_TITLE_FONT_SIZE + 4)

#define VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM 13
#define VAPP_CBS_POPUP_VIEWER_CONTENT_FONT_SIZE			18


#define VAPP_CBS_POPUP_VIEWER_TIME_FONT_SIZE			14

#define VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP     	18
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP     	18
#define VAPP_CBS_POPUP_VIEWER_BUTTON_Y_POS  			210
#define VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT  			40

#endif


#define VAPP_CBS_POPUP_VIEWER_CONTENT_HEIGHT_MIN 		(VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN - \
                                                         VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP - \
                                                         VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT -\
                                                         VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP)
#define VAPP_CBS_POPUP_VIEWER_CONTENT_HEIGHT_MIN_LANDSCAPE 		(VAPP_CBS_POPUP_VIEWER_HEIGHT_MIN_LANDSCAPE- \
															 VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP - \
															 VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT -\
															 VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM -\
															 VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP -\
															 VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT -\
															 VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP)


#define VAPP_CBS_POPUP_VIEWER_CONTENT_HEIGHT_MAX 		(VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX - \
														 VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP - \
                                                         VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT -\
                                                         VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP)                                                       
#define VAPP_CBS_POPUP_VIEWER_CONTENT_HEIGHT_MAX_LANDSCAPE 		(VAPP_CBS_POPUP_VIEWER_HEIGHT_MAX_LANDSCAPE- \
														 VAPP_CBS_POPUP_VIEWER_TITLE_Y_GAP - \
                                                         VAPP_CBS_POPUP_VIEWER_TITLE_FONT_HEIGHT -\
                                                         VAPP_CBS_POPUP_VIEWER_CONTENT_Y_GAP_FROM_TITLE_BOTTOM -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_TAIL_Y_GAP -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_HEIGHT -\
                                                         VAPP_CBS_POPUP_VIEWER_BUTTON_HEAD_Y_GAP)




#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_CBS_POPUP_VIEWER_TIME_Y_GAP                        4   
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_CBS_POPUP_VIEWER_TIME_Y_GAP                        7   
#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_CBS_POPUP_VIEWER_TIME_Y_GAP                        3   
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_CBS_POPUP_VIEWER_TIME_Y_GAP                        3   
#else
#define VAPP_CBS_POPUP_VIEWER_TIME_Y_GAP                        4   
#endif

#define VAPP_CBS_POPUP_VIEWER_TIME_FONT_COLOR			VfxColor(255, 154, 154, 154)
#define VAPP_CBS_POPUP_VIEWER_CONTENT_FONT_COLOR		VfxColor(255, 80, 80, 80)
#define VAPP_CBS_NEW_MSG_VIEWER_POPUP_HEADER_HEIGHT             15

extern "C"
{
/*****************************************************************************
 * FUNCTION
 *	vapp_cbs_new_msg_event_proc
 * DESCRIPTION
 *	
 * PARAMETERS
 *	
 * RETURNS
 *	
 *****************************************************************************/
mmi_ret vapp_cbs_msg_event_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_cbs_new_msg_event_struct *new_msg = (srv_cbs_new_msg_event_struct*)evt; 

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if ((new_msg->mode == SRV_CBS_MODE_IMMEDICATE))
	{
		VappCbsNewMsgManager *handleApp = VFX_OBJ_GET_INSTANCE(VappCbsNewMsgManager);
		handleApp->addNewInd(evt);
	}
	return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  VappCbsNewMsgManager::VappCbsNewMsgShow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL VappCbsNewMsgManager::VappCbsNewMsgShow(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
        VfxTopLevel *toplevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        g_vapp_cbs_new_msg_background_scrn_rotation = toplevel->getScreenRotateType();

	

		mmi_id app_id = VfxAppLauncher::launch(
			VAPP_CB_NEW_MSG, 
			VFX_OBJ_CLASS_INFO(VappCbsNewMsgApp),
			GRP_ID_ROOT,
			NULL, 
			0);

	return MMI_TRUE;
}

}

VFX_IMPLEMENT_CLASS("VappCbsNewMsgApp", VappCbsNewMsgApp, VfxApp);
VappCbsNewMsgApp::VappCbsNewMsgApp() : m_popupViewer(NULL)
{
    //Do nothing
};

void VappCbsNewMsgApp::updateView()
{
	m_popupViewer->updateView();
}

void VappCbsNewMsgApp::onDeinit()
{
	VappCbsNewMsgManager *cbsMgr = VFX_OBJ_GET_INSTANCE(VappCbsNewMsgManager);
    cbsMgr->setRelatedApp(NULL);
    VfxApp::onDeinit();
}



void VappCbsNewMsgApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
	VappCbsNewMsgManager *cbsMgr = VFX_OBJ_GET_INSTANCE(VappCbsNewMsgManager);
	cbsMgr->setRelatedApp(this);
	VFX_OBJ_CREATE_EX(m_popupViewer, VappCbsNewMsgPopupViewer, this, (g_vapp_cbs_new_msg_background_scrn_rotation));
	m_popupViewer->show();

};



VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappCbsNewMsgManager);

VappCbsNewMsgManager::VappCbsNewMsgManager() : 
	m_totalUnitNumber(0)
{
	// do nothing here
}


	
VfxU8 VappCbsNewMsgManager::getNotifyIndex()
{
	return m_totalUnitNumber - 1;
}


void VappCbsNewMsgManager::notify(VfxBool needSetAppActive)
{

	if (m_totalUnitNumber)
{

		VappCbsNewMsgApp *app = (VappCbsNewMsgApp *)VfxAppLauncher::findApp(VAPP_CB_NEW_MSG, VFX_OBJ_CLASS_INFO(VappCbsNewMsgApp), 
			VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
	
	
		if (app)
		{
			app->updateView();
			if (needSetAppActive)
			{
				app->setActive();
			}
		}
		else
		{
			MMI_BOOL is_deferred = mmi_frm_nmgr_is_scenario_deferred(
					MMI_SCENARIO_ID_CELL_BROADCAST,
					&VappCbsNewMsgManager::VappCbsNewMsgShow,
					NULL);
	
	if (!is_deferred)
	{
		mmi_frm_nmgr_notify_by_app(
			MMI_SCENARIO_ID_CELL_BROADCAST,
			MMI_EVENT_NON_TONE,
            &VappCbsNewMsgManager::VappCbsNewMsgShow,
			NULL);
	}
		}

	}
	else
	{
		VfxApp *cbsApp = getRelatedApp();
		if (cbsApp)
		{
			VfxAppLauncher::terminate(cbsApp->getGroupId());
		}	
	}
}


void VappCbsNewMsgManager::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_DEL_MSG, cbsMsgDeleteProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_CBS_MSG_VIEWED_IND, cbsMsgDeleteProc, this);
    VfxObject::onDeinit();
};


void VappCbsNewMsgManager::onInit()
{
    VfxObject::onInit();
    mmi_frm_cb_reg_event(EVT_ID_VAPP_CBS_MSG_VIEWED_IND, cbsMsgDeleteProc,this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_DEL_MSG, cbsMsgDeleteProc, this);
    
    //VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_NEW_MSG_MANAGER_INIT);
};




void VappCbsNewMsgManager::getContent(VfxU8 index, VfxWString &content)
{
	VfxWChar temp[SRV_CBS_MAX_CONTENT_LEN + 1] = {0};
	srv_cbs_read_msg(m_msgUnits[index].m_msgId, vapp_sms_sim_index_to_sim_id(m_msgUnits[index].m_simId), 
		temp, SRV_CBS_MAX_CONTENT_LEN);

	content.loadFromMem(temp);
}

void VappCbsNewMsgManager::getFormatAddr(VfxU8 index, VfxWString &addr)
{
    VfxWChar channelName[SRV_CBS_CHNL_NAME_LEN + 1];
    VfxWString titleString;
	titleString.loadFromRes(STR_ID_VAPP_CBS_CHANNEL_VIEWER_FROM);
    VfxId channelId;
    channelId = srv_cbs_get_msg_chnl_id(m_msgUnits[index].m_msgId, vapp_sms_sim_index_to_sim_id(m_msgUnits[index].m_simId));
	
    //add channel name
    srv_cbs_get_channel_name(channelName, channelId, vapp_sms_sim_index_to_sim_id(m_msgUnits[index].m_simId));
    titleString += (VFX_WSTR_MEM(channelName));
	VfxU32 nameLength = titleString.getLength();

    
    //add channel id below
    VfxWString channelIdString;
    channelIdString.format("%d", channelId);

	titleString += VFX_WSTR("(");
	titleString += channelIdString;
	titleString += VFX_WSTR(")");

	addr = titleString;


}
void VappCbsNewMsgManager::getFormatTimestamp(VfxU8 index, VfxWString &timesatmp)
{
	U32 timestampInt;
    timestampInt = srv_cbs_get_msg_time(m_msgUnits[index].m_msgId, vapp_sms_sim_index_to_sim_id(m_msgUnits[index].m_simId));
    MYTIME time;
    mmi_dt_utc_sec_2_mytime(timestampInt, &time, MMI_FALSE);
    VfxDateTime timeStamp;
    timeStamp.setDate(time.nYear, time.nMonth, time.nDay);
    timeStamp.setTime(time.nHour, time.nMin, time.nSec);

    VfxU32 flags = VFX_DATE_TIME_DATE_YEAR |VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
    VfxWChar datatime[CBS_DATATIME_BUFF_LEN + 1];
    timeStamp.getDateTimeString(flags, datatime, CBS_DATATIME_BUFF_LEN);
    timesatmp.loadFromMem(datatime);
}



/*****************************************************************************
 * FUNCTION
 *  VappCbsNewMsgManager::deleteInd
 * DESCRIPTION
 *  remove one new CB message node to new msg handle manager
 * PARAMETERS
 *  msg_id [IN] : msg id of msg to remvoe
 *  sim_id [IN} : sim id of msg to remvoe
 * RETURNS
 *  void
 *****************************************************************************/
void VappCbsNewMsgManager::deleteInd(VfxId msg_id, VfxS32 sim_id)
{
	for(VfxU32 i = 0; i < m_totalUnitNumber; ++i)
	{
		if ((m_msgUnits[i].m_msgId == msg_id) && (m_msgUnits[i].m_simId == sim_id))
		{
			VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_NEW_MSG_MANAGER_REMOVE_UNIT, sim_id, msg_id);
			for (; i < m_totalUnitNumber - 1; ++i)
			{
				m_msgUnits[i].m_msgId = m_msgUnits[i + 1].m_msgId;
				m_msgUnits[i].m_simId = m_msgUnits[i + 1].m_simId;
			}
			m_msgUnits[i].m_msgId = VAPP_CB_INVALID_MSG_ID;
			m_msgUnits[i].m_simId = CB_SIM_INVALID;
			--m_totalUnitNumber;
            break;
		}
	}
};

VfxBool VappCbsNewMsgManager::deleteInd(VfxU8 index)
{
	for (; index< m_totalUnitNumber - 1; ++index)
{
		m_msgUnits[index].m_msgId = m_msgUnits[index + 1].m_msgId;
		m_msgUnits[index].m_simId = m_msgUnits[index + 1].m_simId;
}
	m_msgUnits[index].m_msgId = VAPP_CB_INVALID_MSG_ID;
	m_msgUnits[index].m_simId = CB_SIM_INVALID;
	--m_totalUnitNumber;
	return VFX_TRUE;
}




/*****************************************************************************
 * FUNCTION
 *  VappCbsNewMsgManager::cbsNewMsgProc
 * DESCRIPTION
 *  process a new CB msg recivied.
 * PARAMETERS
 *  evt [IN] : new msg event data
 * RETURNS
 *  mmi_ret MMI_RET_OK, will not block other evt hanler 
 *****************************************************************************/


VfxBool VappCbsNewMsgManager::addNewInd(mmi_event_struct *evt)
{
	
	srv_cbs_new_msg_event_struct *new_msg = (srv_cbs_new_msg_event_struct*)evt; 

	if(m_totalUnitNumber == MAX_NEW_HOLD_NUMBER)
	{
		deleteInd(0);
	}
		
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_NEW_MSG_MANAGER_ADD_UNIT, new_msg->sim_id, new_msg->msg_id);
	m_msgUnits[m_totalUnitNumber].m_msgId = new_msg->msg_id;
	m_msgUnits[m_totalUnitNumber].m_simId = vapp_sms_sim_id_to_sim_index(new_msg->sim_id);
	++m_totalUnitNumber;
	
	notify(VFX_TRUE);
	return MMI_RET_OK;
};	 





/*****************************************************************************
 * FUNCTION
 *  VappCbsNewMsgManager::cbsMsgDeleteProc
 * DESCRIPTION
 *  handle msg delete event
 * PARAMETERS
 *  evt [IN] :  msg delete evt
 * RETURNS
 *  mmi_ret  MMI_RET_OK not block other proc 
 *****************************************************************************/
mmi_ret VappCbsNewMsgManager::cbsMsgDeleteProc(mmi_event_struct *evt)
{
	VappCbsNewMsgManager *cbsMgr = (VappCbsNewMsgManager *)evt->user_data;
	srv_cbs_del_msg_event_struct* event_data = (srv_cbs_del_msg_event_struct*)evt;
	
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_NEW_MSG_MANAGER_NEW_MSG_PROC, event_data->evt_id, event_data->msg_id, event_data->sim_id);
	cbsMgr->deleteInd(event_data->msg_id, vapp_sms_sim_id_to_sim_index(event_data->sim_id));
	cbsMgr->notify(VFX_FALSE);
	return MMI_RET_OK;
};	




/***************************************************************************** 
 * Class VappCbsNewMsgPopupViewer
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappCbsNewMsgPopupViewer", VappCbsNewMsgPopupViewer, VfxBasePopup);

VappCbsNewMsgPopupViewer::VappCbsNewMsgPopupViewer(VfxScrRotateTypeEnum dir):
	m_rotation(dir),
	m_notifyCp(NULL)
{
    setIsSmallScreen();
}

void VappCbsNewMsgPopupViewer::onInit()
{

    VfxAppScr::onInit();
    VFX_OBJ_CREATE_EX(
        m_notifyCp,
        VappSmsClass0NotifyCp,
        this,
        (g_vapp_cbs_new_msg_background_scrn_rotation, VappSmsClass0NotifyCp::NOTIFY_CP_TYPE_CBS));
	VappCbsNewMsgManager *cbsMgr = VFX_OBJ_GET_INSTANCE(VappCbsNewMsgManager);
	m_notifyCp->setRelatedNmgr(cbsMgr);
	m_notifyCp->updateView();


}

void VappCbsNewMsgPopupViewer::onEnter(VfxBool isBackward)
{
	VfxAppScr::onEnter(isBackward);
	m_notifyCp->show(VFX_TRUE);
}

void VappCbsNewMsgPopupViewer::updateView()
{
	m_notifyCp->updateView();
}

void VappCbsNewMsgPopupViewer::onQueryRotateEx(VfxScreenRotateParam & param)
{
    param.rotateTo = m_rotation;
}



