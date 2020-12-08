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
 *  vapp_mms_viewer.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VENUS_MMI_MMS_VIEWER_APP__
#define __VENUS_MMI_MMS_VIEWER_APP__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vapp_msg_contact_bar.h"
#include "vapp_mms_viewer_cp.h"
#include "vapp_mms_data.h"
#include "vapp_mms_toolbar.h"
#include "vapp_ncenter.h"

extern "C"
{
	 #include "GlobalResDef.h"
}

typedef void (VfxObject::* clickOk) (VfxObject* , VfxId );
typedef void (*CheckFunc) (VfxBool& result,void *user_data);

typedef enum
	{
		MODE_STOP,
		MODE_PLAY,
		MODE_PAUSE,
		MODE_ALL
	}VappMmsViewerModeEnum;
typedef struct
{
    MMI_EVT_PARAM_HEADER

} vapp_mms_get_content_struct;

//Viewer Page class

class VappMmsDetailsViewer;

class VappMmsViewerPage : public VfxPage
{
	VFX_DECLARE_CLASS(VappMmsViewerPage);
	
//delcaration
	static VfxPage * myPage;
//method
public:
	VappMmsViewerData *getMyData(void);
	VappMmsViewerModeEnum getMode(void);
	virtual void onEnter(VfxBool isBackward);
	virtual void onEntered(void);
	static void deleteAppInstance(void *);
	inline srv_mms_viewer_xml_msg_struct *getMsgCntx(void)
	{
		if(m_data->getViewerInfo()->cat_info)
		{
			return m_data->getViewerInfo()->cat_info->msg_cntx;
		}
		return NULL;
	}
	inline static VfxPage *getMyPage(void)
	{
		return myPage;
	}
	inline VfxU8 getMsgType(void)
	{
		return m_data->getMsgInfo()->msg_type;
	}
	
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
	void onUseDetailsReady(void);
#endif
	void onPenInput(void);
	void onPreviewPageFinish(void);
        VfxPageBar  *getToolBar(VfxPageBarLocationEnum loc);
	VfxU32 getPanelHeightVideo(void)const;
	static void checkmmspageisgetcontent(VfxBool & result,void *user_data);	
	VfxBool checkmmsgetcontent();

	
//constructor
public:

	VappMmsViewerPage(VappMmsViewerModeEnum mode, VfxU32 msg_id, VfxBool is_preview = VFX_FALSE, VfxU32 index = 0, U8 storage_location = 0):m_mode(mode),m_msg_location(storage_location)
	{
		VFX_OBJ_CREATE_EX(m_data, VappMmsViewerData, this, (msg_id, is_preview, index));
		m_button_play = NULL;
		m_next = NULL;
		m_prev = NULL;
		m_attach = NULL;
		m_clock = NULL;
		m_dt_txt = NULL;
		m_subject_txt = NULL;
		m_view_size_txt = NULL;
		m_title_txt = NULL;
		m_main_cp = NULL;
		m_popup = NULL;
		m_tool_bar = NULL;
		m_contact_bar = NULL;
		m_cui_id = GRP_ID_INVALID;
		m_slideCount = 0;
		m_noload = VFX_FALSE;
		m_panel = NULL;
		m_detail_viewer = NULL;
		m_enter = VFX_FALSE;
		m_Backward = VFX_TRUE;
		m_exited = VFX_FALSE;		
		m_data_event_come = VFX_FALSE;
		m_wait_data_done = VFX_FALSE;
		m_preview_finish = VFX_FALSE;
	}
	VappMmsViewerPage()
	{
		m_button_play = NULL;
		m_next = NULL;
		m_prev = NULL;
		m_attach = NULL;
		m_clock = NULL;
		m_dt_txt = NULL;
		m_subject_txt = NULL;
		m_view_size_txt = NULL;
		m_title_txt = NULL;
		m_main_cp = NULL;
		m_popup = NULL;
		m_tool_bar = NULL;
		m_contact_bar = NULL;
		m_cui_id = GRP_ID_INVALID;
		m_msg_location = 0;
		m_slideCount = 0;
		m_noload = VFX_FALSE;
		m_panel = NULL;
		m_enter = VFX_FALSE;	
		m_Backward = VFX_TRUE;
		m_detail_viewer = NULL;
		m_exited = VFX_FALSE;
		m_data_event_come = VFX_FALSE;	
		m_wait_data_done = VFX_FALSE;
		m_preview_finish = VFX_FALSE;
	}
//property

	static mmi_ret listener(mmi_event_struct *param);
	void onNCenterStatus(VappNCenterEventEnum evt);
//overridable
protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	//void onToolBarClick(VfxObject* sender, VfxId id);
	void onFolding(VfxObject* sender, VfxBool is_fold);
	virtual void setBounds(const VfxRect &value);
	virtual VfxBool onPenInput(
        VfxPenEvent &event          // [IN] The pen event to be handled
    );
	virtual void onBack(void);
	virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onRotate(const VfxScreenRotateParam &param);
	virtual mmi_ret onProc(mmi_event_struct *evt);
	virtual void onExit(VfxBool);
	virtual VfxBool onKeyInput(VfxKeyEvent &event);
	void setbuttonstate(VcpButtonStateEnum m_button_state);
	void setButtonStateAfterOpenFile(void);
//implementation
//method
private:
	void onDataReady(srv_mms_viewer_result_enum, VfxS32);
	void onClick(VfxObject *obj, VfxId id);
	void onClickPrev(VfxObject *obj, VfxId id);
	void onClickNext(VfxObject *obj, VfxId id);
	void onClickPause(VfxObject *obj, VfxId id);
	void onClickAttachment(VfxObject *obj, VfxId id);
	void onLastSlideEnd(void);
	void onSlideSwitch(void);
	void onMediaEnd(srv_mms_viewer_object_type_enum);
	void displayPopupAndExit(void);
	void loadContactBar(void);
	mmi_ret listenerInt(mmi_event_struct *param);
	void onContentReady(srv_mms_viewer_result_enum , VfxS32 );
	void onDownloadDone(VfxFrame *,VfxBool);
	void handleRRRequest(void);
	void loadAllComponentsFromXml(void);
	void onContactProviderCloseCall(void);
private:
	void deleteAllChilds(void);
	void onConfirmRR(VfxObject* obj, VfxId id);
	void draw();
	void loadXML(void);
	void onClickOk(VfxObject* obj, VfxId id);
	void onClickRRErrorOk(VfxObject* obj, VfxId id);
	void alignAllChilds(void);
	void handlePause(void);
	void handleResizeButton(void);
	void upDateInternal(void);
	void searchAndDelete(void);
	VfxU32 getPanelHeight(void);
	void changeButtonState(VcpButton *, VcpButtonStateEnum);
//variables
private:
	VappMmsViewerModeEnum m_mode;
	VcpActivityIndicator *m_popup;
	VappMmsViewerData *m_data;	
	VcpButton *m_button_play, *m_next, *m_prev, *m_attach;
	VappMmsClock *m_clock;
	VfxTextFrame *m_title_txt;
	VfxTextFrame *m_dt_txt;
	VfxTextFrame *m_view_size_txt;
	VfxTextFrame *m_subject_txt;
	VappMmsViewerCp *m_main_cp;
	VappMmsToolBar *m_tool_bar;
	VappMsgContactBar *m_contact_bar;
	VcpPagePanel *m_panel;
	VappMmsDetailsViewer *m_detail_viewer;
	srv_mms_viewer_result_enum m_error_type;
	mmi_id m_cui_id;
	U8 m_msg_location;
	VfxS32 m_slideCount;
	VfxBool m_noload;
	VfxBool m_enter;
	VfxBool m_Backward;
	VfxBool m_exited;
	VfxBool m_data_event_come;	
	VfxBool m_wait_data_done ;
	VfxBool m_preview_finish;
//enum
	enum
	{
#ifdef __MMI_MAINLCD_480X800__ 
		DATE_TIME_BAR_TOP_MARGIN = 10,
		DATE_TIME_BAR_BOTTOM_MARGIN = 14,
		DATE_TIME_BAR_LEFT_MARGIN = 0,
		DATE_TIME_BAR_RIGHT_MARGIN = 14,
		GAP_BETWEEN_SUBJECT_SLIDE = 8,
		SUBJECT_FONT_SIZE = 30,
		SUBJECT_UPPER_MARGIN = 14,
		MMS_VIEW_FONT_SIZE = 21,
		MMS_VIEW_SIZE_LEFT_MARGIN = 14,		
		MMS_VIEW_SIZE_TOP_MARGIN = 10,
		TITLE_PLAY_LEFT_MARGIN = 18,
		TITLE_PLAY_TOP_MARGIN = 8,
		TITLE_PLAY_FONT_SIZE = 26,
		TITLE_PLAY_BOTTOM_MARGIN = 8,
		DT_FONT_SIZE = 21,
		PAGE_WIDTH_PORTRAIT = 480,
		SLIDE_BAR_LEFT_MARGIN = 14,
		BUTTON_PREV_WIDTH = 107,
		BUTTON_PLAY_WIDTH = 222,
		BUTTON_NEXT_WIDTH = 107,
		BUTTON_PAUSE_PLAY_WIDTH = 222,
		BUTTON_PAUSE_PREV_WIDTH = 107,
		BUTTON_PAUSE_NEXT_WIDTH = 107,
		BUTTON_PAUSE_HEIGHT = 84,
		BUTTON_PAUSE_COMM_GAP = 9,
		BUTTON_STOP_COMM_GAP = 9,
		BUTTON_PLAY_ONLY_WIDTH = 226,
		BUTTON_PLAY_ONLY_X = 127,
		BUTTON_PAUSE_PLAY_ONLY_X = 127,
		BUTTON_PAUSE_PLAY_ONLY_WIDTH = 226,
		BUTTON_PREV_WIDTH_LANDSCAPE = 189,
		BUTTON_NEXT_WIDTH_LANDSCAPE = 189,
		BUTTON_PLAY_WIDTH_LANDSCAPE = 376,
		BUTTON_PLAY_ONLY_WIDTH_LANDSCAPE = 380,
		BUTTON_PLAY_ONLY_X_LANDSCAPE = 210,
		BUTTON_PAUSE_PLAY_ONLY_X_LANDSCAPE = 210,
		BUTTON_LEFT_MARGIN = 14,
		BUTTON_BOTTOM_MARGIN = 14,
		CP_MARGIN_BETWEEN_BUTTON = 7,
#elif defined(__MMI_MAINLCD_320X480__)
		DATE_TIME_BAR_TOP_MARGIN = 3,
		DATE_TIME_BAR_BOTTOM_MARGIN = 3,
		DATE_TIME_BAR_LEFT_MARGIN = 0,
		DATE_TIME_BAR_RIGHT_MARGIN = 8,
		GAP_BETWEEN_SUBJECT_SLIDE = 4,
		SUBJECT_FONT_SIZE = 18,
		SUBJECT_UPPER_MARGIN = 10,	
		MMS_VIEW_FONT_SIZE = 14,
		MMS_VIEW_SIZE_LEFT_MARGIN = 10, 	
		MMS_VIEW_SIZE_TOP_MARGIN = 2,
		TITLE_PLAY_LEFT_MARGIN = 10,
		TITLE_PLAY_TOP_MARGIN = 3,
		TITLE_PLAY_FONT_SIZE = 15,
		TITLE_PLAY_BOTTOM_MARGIN = 4,
		DT_FONT_SIZE = 13,
		PAGE_WIDTH_PORTRAIT = 320,
		SLIDE_BAR_LEFT_MARGIN = 8,
		BUTTON_PREV_WIDTH = 65,
		BUTTON_PLAY_WIDTH = 165,
		BUTTON_NEXT_WIDTH = 65,
		BUTTON_PAUSE_PLAY_WIDTH = 170,
		BUTTON_PAUSE_PREV_WIDTH = 67,
		BUTTON_PAUSE_NEXT_WIDTH = 67,
		BUTTON_PAUSE_HEIGHT = 50,
		BUTTON_PAUSE_COMM_GAP = 4,
		BUTTON_STOP_COMM_GAP = 5,
		BUTTON_PLAY_ONLY_WIDTH = 168,
		BUTTON_PLAY_ONLY_X = 76,
		BUTTON_PAUSE_PLAY_ONLY_X = 73,
		BUTTON_PAUSE_PLAY_ONLY_WIDTH = 174,
		BUTTON_PREV_WIDTH_LANDSCAPE = 114,
		BUTTON_NEXT_WIDTH_LANDSCAPE = 114,
		BUTTON_PLAY_WIDTH_LANDSCAPE = 227,
        BUTTON_PLAY_ONLY_X_LANDSCAPE = 125,
		BUTTON_PAUSE_PLAY_ONLY_X_LANDSCAPE = 125,
		BUTTON_LEFT_MARGIN = 8,
		BUTTON_PLAY_ONLY_WIDTH_LANDSCAPE = 230,
		BUTTON_BOTTOM_MARGIN = 8,
		CP_MARGIN_BETWEEN_BUTTON = 4,		
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
		DATE_TIME_BAR_TOP_MARGIN = 2,
		DATE_TIME_BAR_BOTTOM_MARGIN = 5,
		DATE_TIME_BAR_LEFT_MARGIN = 0,
		DATE_TIME_BAR_RIGHT_MARGIN = 5,
		GAP_BETWEEN_SUBJECT_SLIDE = 1,
		SUBJECT_FONT_SIZE = 14,
		SUBJECT_UPPER_MARGIN = 5,
		MMS_VIEW_FONT_SIZE = 12,
		MMS_VIEW_SIZE_LEFT_MARGIN = 5, 	
		MMS_VIEW_SIZE_TOP_MARGIN = 1,
		TITLE_PLAY_LEFT_MARGIN = 5,
		TITLE_PLAY_TOP_MARGIN = 3,
		TITLE_PLAY_FONT_SIZE = 13,
		TITLE_PLAY_BOTTOM_MARGIN = 2,
		DT_FONT_SIZE = 11,
		PAGE_WIDTH_PORTRAIT = 240,
		SLIDE_BAR_LEFT_MARGIN = 5,
		BUTTON_PREV_WIDTH = 55,
		BUTTON_PLAY_WIDTH = 110,
		BUTTON_NEXT_WIDTH = 55,
		BUTTON_PAUSE_PLAY_WIDTH = 110,
		BUTTON_PAUSE_PREV_WIDTH = 55,
		BUTTON_PAUSE_NEXT_WIDTH = 55,
		BUTTON_PAUSE_HEIGHT = 38,
		BUTTON_PAUSE_COMM_GAP = 5,
		BUTTON_STOP_COMM_GAP = 5,
		BUTTON_PLAY_ONLY_WIDTH = 110,
		BUTTON_PLAY_ONLY_X = 65,
		BUTTON_PAUSE_PLAY_ONLY_X = 65,
		BUTTON_PAUSE_PLAY_ONLY_WIDTH = 110,
		BUTTON_LEFT_MARGIN = 5,
		BUTTON_BOTTOM_MARGIN = 5,
#if defined(__MMI_MAINLCD_240X320__) 
		BUTTON_PREV_WIDTH_LANDSCAPE = 75,
		BUTTON_NEXT_WIDTH_LANDSCAPE = 75,
		BUTTON_PLAY_WIDTH_LANDSCAPE = 150,
                BUTTON_PLAY_ONLY_X_LANDSCAPE = 85,
		BUTTON_PAUSE_PLAY_ONLY_X_LANDSCAPE = 85,
		BUTTON_PLAY_ONLY_WIDTH_LANDSCAPE = 150,
		CP_MARGIN_BETWEEN_BUTTON = 3,
#else /*defined(__MMI_MAINLCD_240X320__) */
		BUTTON_PREV_WIDTH_LANDSCAPE = 95,
		BUTTON_NEXT_WIDTH_LANDSCAPE = 95,
		BUTTON_PLAY_WIDTH_LANDSCAPE = 190,
                BUTTON_PLAY_ONLY_X_LANDSCAPE = 105,
		BUTTON_PAUSE_PLAY_ONLY_X_LANDSCAPE = 105,
		BUTTON_PLAY_ONLY_WIDTH_LANDSCAPE = 190,
		CP_MARGIN_BETWEEN_BUTTON = 3,
#endif /*defined(__MMI_MAINLCD_240X320__) */
#else
		DATE_TIME_BAR_TOP_MARGIN = 3,
		DATE_TIME_BAR_BOTTOM_MARGIN = 13,
		DATE_TIME_BAR_LEFT_MARGIN = 0,
		DATE_TIME_BAR_RIGHT_MARGIN = 8,
		GAP_BETWEEN_SUBJECT_SLIDE = 4,
		SUBJECT_FONT_SIZE = 18,
		SUBJECT_UPPER_MARGIN = 10,			
		MMS_VIEW_FONT_SIZE = 14,
		MMS_VIEW_SIZE_LEFT_MARGIN = 10, 	
		MMS_VIEW_SIZE_TOP_MARGIN = 2,	
		TITLE_PLAY_LEFT_MARGIN = 10,
		TITLE_PLAY_TOP_MARGIN = 3,
		TITLE_PLAY_FONT_SIZE = 15,
		TITLE_PLAY_BOTTOM_MARGIN = 4,
		DT_FONT_SIZE = 13,
		PAGE_WIDTH_PORTRAIT = 320,
		SLIDE_BAR_LEFT_MARGIN = 8,
		BUTTON_PREV_WIDTH = 65,
		BUTTON_PLAY_WIDTH = 165,
		BUTTON_NEXT_WIDTH = 65,
		BUTTON_PAUSE_PLAY_WIDTH = 170,
		BUTTON_PAUSE_PREV_WIDTH = 67,
		BUTTON_PAUSE_NEXT_WIDTH = 67,
		BUTTON_PAUSE_HEIGHT = 50,
		BUTTON_PAUSE_COMM_GAP = 4,
		BUTTON_STOP_COMM_GAP = 5,
		BUTTON_PLAY_ONLY_WIDTH = 168,
		BUTTON_PLAY_ONLY_X = 76,
		BUTTON_PAUSE_PLAY_ONLY_X = 73,
		BUTTON_PAUSE_PLAY_ONLY_WIDTH = 174,
		BUTTON_PREV_WIDTH_LANDSCAPE = 114,
		BUTTON_NEXT_WIDTH_LANDSCAPE = 114,
		BUTTON_PLAY_WIDTH_LANDSCAPE = 227,
        BUTTON_PLAY_ONLY_X_LANDSCAPE = 125,
		BUTTON_PAUSE_PLAY_ONLY_X_LANDSCAPE = 125,
		BUTTON_LEFT_MARGIN = 7,
		BUTTON_PLAY_ONLY_WIDTH_LANDSCAPE = 230,
		BUTTON_BOTTOM_MARGIN = 8,
		CP_MARGIN_BETWEEN_BUTTON = 4,
#endif
		SUBJECT_BODY_LEN = MMA_MAX_SUBJECT_LEN + 1,
		SUBJECT_TOTAL_LEN = SUBJECT_BODY_LEN + 8,
		DT_FONT_A = 0,
		DT_FONT_R = 154,
		DT_FONT_G = 154,
		DT_FONT_B = 154,
	}pageMargins;
friend class VappMmsViewerCp;
};

/*Base Class for MMS Viewer Screen*/
class VappMmsViewerScrn : public VfxMainScr
{
	VFX_DECLARE_CLASS(VappMmsViewerScrn);

//constructor
public:
	VappMmsViewerScrn(VfxU32 index = 0, VfxU32 msg_id = 0, VappMmsViewerModeEnum mode = MODE_STOP, VfxBool isPreview = VFX_FALSE, U8 location = 0):m_index(index), m_msgId(msg_id), m_mode(mode), m_isPreview(isPreview), m_msg_location(location) 
	{
	}
	//method
    VappMmsViewerPage *m_page;

//override
protected:
	virtual void on1stReady(void);
		
//implementation

//variables
private:
	VfxU32 m_index;
	VfxU32 m_msgId;
	VappMmsViewerModeEnum m_mode;
	VfxBool m_isPreview;
	U8 m_msg_location;
};

class VappMmsViewer : public VfxCui
{
	VFX_DECLARE_CLASS(VappMmsViewer);
//method
//override
public:
    VappMmsViewerScrn *m_scrn;
	
#ifdef __MMI_MMS_USE_ASM__  
	void callclosecontinue(void);
#endif

protected:
	virtual void onRun(void* args, VfxU32 argSize);
	virtual mmi_ret onProc(mmi_event_struct *evt);
	
#ifdef __MMI_MMS_USE_ASM__  
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);	
#endif
    using VfxCui::onProcessClose;	

};

class VappMmsPopup
{
//declaration

//constructor
public:
	VappMmsPopup(VfxResId resid = 0, VcpPopupTypeEnum emotion = VCP_POPUP_TYPE_END_OF_ENUM, VfxObject *memory = NULL, clickOk memFunc = NULL):m_str_id(resid), m_emotion(emotion), m_memory(memory), m_memFunc(memFunc)
	{

	}
//method
public:
		void displayPopup(void);

//implementation

//variable
private:
		VfxResId m_str_id;
		VcpPopupTypeEnum m_emotion;
		VfxObject *m_memory;
		clickOk m_memFunc;
};

typedef struct 
{
	VappMmsViewerModeEnum mode;
	VfxU32 msg_id;
	VfxU32 index;
	VfxBool isPreview;
	U8 msg_location;
}VappMmsViewerStartStruct;

#endif /* __MMI_MMS_2__ */
#endif /*__VENUS_MMI_MMS_VIEWER_APP__*/
