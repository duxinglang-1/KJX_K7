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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VENUS_MMI_MMS_VIEWER_CP__
#define __VENUS_MMI_MMS_VIEWER_CP__
#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "vcp_text_view.h"
#include "vapp_msg_viewer.h"
extern "C"
{
	#include "MmsXMLDefSrv.h"
}

    
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_keypad.h"
#include "mdi_datatype.h"
#include "vfx_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vcp_text_utils.h"
#include "vfx_text_frame.h"
#include "vfx_signal.h"
#include "vfx_timer.h"
#include "vapp_video_player_cp.h"

class VappVideoPlayerComponent;

typedef enum 
{
	AUDIO_STATE_INIT,
	AUDIO_STATE_PLAY,
	AUDIO_STATE_PAUSE,
	AUDIO_STATE_PAUSE_FAIL,
	AUDIO_STATE_FINISH,
	AUDIO_STATE_MAX
}audioStateEnum;
class VappMmsAudioPlay: public VfxControl
{
	VFX_DECLARE_CLASS(VappMmsAudioPlay);
private:
	srv_mms_viewer_object_info_struct *m_audio_obj;
	VfxBool m_audioPlaying;
	VfxBool m_bgSuspend;
	VfxBool m_audioValid;
	VfxU32 m_currVol;
	VfxU16 *m_file_path;
	audioStateEnum m_state;
	VfxU32 m_srv_index;
public:
	VfxS32 m_audioFileHandle;
	VappMmsAudioPlay(srv_mms_viewer_object_info_struct * obj = NULL, VfxU32 index = 0)
	{
		m_audio_obj = obj;
		m_srv_index = index;
		VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_UP, this);
		VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_DOWN, this);
		m_audioPlaying = VFX_FALSE;
		m_bgSuspend = VFX_FALSE;
		m_currVol = 0;
		m_audioValid = VFX_FALSE;
		m_audioFileHandle = 0;
		m_file_path = NULL; 
		m_state = AUDIO_STATE_MAX;
	}
public:
	VfxBool allowAudioPlay(void);
	void playAudio(void);
	void deinitAudio(void);
	void stopAudio(void);
	virtual VfxBool onKeyInput(VfxKeyEvent& event);
	static void mediaStoppedCallback(mdi_result result, void *user_data);
	static mmi_ret listener(mmi_event_struct *);
	void resumeAudio(void);
	void pauseAudio(void);
	void mediaStoppedCallbackInt(mdi_result result);

};

class VappMmsVisual: public VfxControl 
{
	VFX_DECLARE_CLASS(VappMmsVisual);
//declaration
public:
	VfxFrame *getFrame(void);
//constructor
public:
	VappMmsVisual(srv_mms_viewer_object_type_enum type = SRV_MMS_OBJECT_TYPE_UNKNOWN, srv_mms_viewer_object_info_struct * obj = NULL)
	{
		m_type = type;
		m_video = NULL;
		m_image = NULL;
		m_obj = obj;
	}
	srv_mms_viewer_object_info_struct * getObj(void)
	{
		return m_obj;
	}
//override
protected:
	virtual void onInit(void);
	//virtual VfxBool onPenInput(VfxPenEvent &event);
//implementation
private:
	VfxAnimImageFrame *m_image;
	VappVideoPlayerComponent *m_video;
	srv_mms_viewer_object_type_enum m_type;
	srv_mms_viewer_object_info_struct *m_obj;

};

class VappMmsViewerCp : public VappMsgViewerCp
{
	VFX_DECLARE_CLASS(VappMmsViewerCp);
//declaration
//enum
public:
	enum redrawStateEnum
	{
		REDRAW_NONE,
		REDRAW_NEEDED,
		REDRAW_MEDIA_NEEDED,
		REDRAW_TEXT_NEEDED,
		REDRAW_DONE,
	};

	enum videoCurrState
	{
		VIDEO_STATE_NONE,
		VIDEO_STATE_PLAYBACK_FINISH,
		VIDEO_STATE_FAIL,
		VIDEO_STATE_TOTAL,
	};
//method
public:
	virtual void onInit(void);
	virtual void deInitCp(void);
	void deInitCpExt(void);
	virtual void setBounds(const VfxRect &value);
	
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
	void onUseDetailsReady(srv_mms_viewer_result_enum);
#endif
	void onKeywordClicked(VcpTextKeyWordEnum mode, VfxWChar *text, VfxS32 len);
	
#ifdef __DRM_SUPPORT__
	static void onImageRightsExpiry(void *);
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
	static void onVideoRightsExpiry(void *);
#endif
	static void onAudioRightsExpiry(void *);
#endif	
	VappMmsAudioPlay *getAudio(void);
	void handleMediaEnd(VfxU32);
	
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
	VappVideoPlayerComponent *getVideo(void);
	void onFileReady(VappVideoPlayerComponent *player, MDI_RESULT result);
	void onVideoPlaybackFinish(VappVideoPlayerComponent*, MDI_RESULT);
#endif
	void onTapEvent(VcpTextView *obj, VcpTextTapAreaEnum are, VcpRichTextFormat * frame);
	void setState(redrawStateEnum);
	void startMediaRightsConsumption(void);
	void onExit(VfxBool isBackward);
	
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
	VfxBool videoisfinished(void);
	void setopenfilestate(VfxBool b_open_file );
	VfxBool getopenfilestate(void);
	static mmi_ret listener(mmi_event_struct *);
	VappVideoPlayerState getVideoState(void);
#endif
	
//constructor
public:
	VappMmsViewerCp()
	{
		m_main_txt = NULL;
		m_audio = NULL;
		m_visual = NULL;
		m_img_file_h = 0;
		m_text_file_h = 0;
		m_state = REDRAW_NONE;
		m_img_file_path = NULL;
		m_page = NULL;
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
		m_video_file_h = 0;
		vidState = VIDEO_STATE_NONE;
		m_video_popup = NULL;
		m_opening_file = VFX_FALSE;
    #endif
		image_realy_size.height = 0;
		image_realy_size.width = 0;

		
	}

private:
	VfxColor convertFromGdiColorToColor(VfxU32 incolor_32);
	void upDatecpLayout(void);
	void upDateMediaBounds(void);
	void onContentReady(srv_mms_viewer_result_enum , VfxS32 );
	void setimagerealysize(VfxS32 width, VfxS32 height);
	
	void getimagerealysize(VfxS32 *width,VfxS32 *height);
private:
	VcpTextView *m_main_txt;
	VappMmsAudioPlay *m_audio;
	VappMmsVisual *m_visual;
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
	VcpActivityIndicator *m_video_popup;	
	VfxS32 m_video_file_h;
	videoCurrState vidState;
#endif
	VfxBool m_opening_file;
	VfxS32 m_img_file_h;
	VfxS32 m_text_file_h;
	redrawStateEnum m_state;
	VfxU16 *m_img_file_path;
	VfxU16 m_vfname[SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR];
	VfxPage *m_page;
	VfxSize image_realy_size;
//enum
private:
	enum
	{
		INFOBAR_MARGIN = 1,
#ifdef __MMI_MAINLCD_480X800__ 
		CP_TOP_MARGIN = 7,
		CP_BOTTOM_MARGIN = 7,
		CP_LEFT_MARGIN = 7,
		CP_RIGHT_MARGIN = 7,
		CP_MARGIN_BETWEEN_OBJECTS = 14,	
		CP_PAGE_WIDTH_PORTRAIT = 480,
		CP_IMAGE_SIZE_HEIGHT_PORTRAIT = 800,
		CP_IMAGE_SIZE_HEIGHT_LANDSCAPE = 800,
#elif defined(__MMI_MAINLCD_320X480__)
		CP_TOP_MARGIN = 4,
		CP_BOTTOM_MARGIN = 4,
		CP_LEFT_MARGIN = 4,
		CP_RIGHT_MARGIN = 4,
		CP_MARGIN_BETWEEN_OBJECTS = 10,
		CP_PAGE_WIDTH_PORTRAIT = 320,
		CP_IMAGE_SIZE_HEIGHT_PORTRAIT = 480,
		CP_IMAGE_SIZE_HEIGHT_LANDSCAPE = 480,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
		CP_TOP_MARGIN = 2,
		CP_BOTTOM_MARGIN = 2,
		CP_LEFT_MARGIN = 2,
		CP_RIGHT_MARGIN = 2,
		CP_MARGIN_BETWEEN_OBJECTS = 5,		
		CP_PAGE_WIDTH_PORTRAIT = 240,
		CP_IMAGE_SIZE_HEIGHT_PORTRAIT = 320,
		CP_IMAGE_SIZE_HEIGHT_LANDSCAPE = 320,
#else
		CP_TOP_MARGIN = 4,
		CP_BOTTOM_MARGIN = 4,
		CP_LEFT_MARGIN = 4,
		CP_RIGHT_MARGIN = 4,
		CP_MARGIN_BETWEEN_OBJECTS = 10,	
		CP_PAGE_WIDTH_PORTRAIT = 320,
		CP_IMAGE_SIZE_HEIGHT_PORTRAIT = 320,
		CP_IMAGE_SIZE_HEIGHT_LANDSCAPE = 320,
#endif
	}cpMargin;
};

/*Class for Displaying Clock in MMS*/

class VappMmsClock: public VfxTextFrame
{
	VFX_DECLARE_CLASS(VappMmsClock);

//declaration
//enum
public:
	enum clockState
	{
		STATE_NONE,
		STATE_PAUSE,
		STATE_RUNNING,
		STATE_WAIT
	};
//method
public:
	VfxU32 getTime(void);
	void getTime(VfxU32 *hrs, VfxU32 *mins, VfxU32 *sec);
	void setTime(VfxU32 hrs, VfxU32 mins, VfxU32 sec);
	void startClock(VfxBool isfrompause );
	void pauseClock(void);
	void waitClock(void);
	void ResumeClock(void);
	void changeState(clockState newState);
	clockState getClockState(void);
	VfxBool allowTimer(void);
//contsructor
public:
	VappMmsClock()
	{
		m_hrs = 0;
		m_min = 0;
		m_sec = 0;
		m_running = STATE_NONE;
		m_curr_tick = 0;
		m_from_pause = VFX_FALSE;
	}
//signal
public: 
	VfxSignal0 m_signalLastSlideEnd;
	VfxSignal0 m_signalSlideSwitch;
	VfxSignal1 <srv_mms_viewer_object_type_enum> m_signalMediaEnd;
//method

//override
protected:

	virtual void onDrawInt(VfxTimer *);
	virtual void onDraw(VfxDrawContext &dc);
	
//implement
//variable
private:
	VfxU32 m_hrs;
	VfxU32 m_min;
	VfxU32 m_sec;
	clockState m_running;
	VfxU32 m_curr_tick;
public:
	VfxBool m_from_pause;
//enum
private:
	enum
	{
#ifdef __MMI_MAINLCD_480X800__ 
		CLOCK_TOP_MARGIN = 10,
		CLOCK_BOTTOM_MARGIN = 9,
		CLOCK_FONT_SIZE = 24,
		CLOCK_RIGHT_MARGIN = 18,
#elif defined(__MMI_MAINLCD_320X480__)
		CLOCK_TOP_MARGIN = 3,
		CLOCK_BOTTOM_MARGIN = 4,
		CLOCK_FONT_SIZE = 15,
		CLOCK_RIGHT_MARGIN = 10,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
		CLOCK_TOP_MARGIN = 3,
		CLOCK_BOTTOM_MARGIN = 2,
		CLOCK_FONT_SIZE = 13,
		CLOCK_RIGHT_MARGIN = 5,
#else
		CLOCK_TOP_MARGIN = 3,
		CLOCK_BOTTOM_MARGIN = 4,
		CLOCK_FONT_SIZE = 15,
		CLOCK_RIGHT_MARGIN = 10,
#endif
		CLOCK_HRS = 3600,
		CLOCK_MINS = 60,
		CLOCK_CONVERTOR = 60,
		CLOCK_DECIMAL_CONVERTOR = 10,
		CLOCK_BUFF_LEN = 10,
		CLOCK_BUFF_LEN_UCS = 20,
	}clockMargins;
};

#else /*__MMI_MMS_2__*/

class VappMmsViewerCp : public VfxControl
{
	VFX_DECLARE_CLASS(VappMmsViewerCp);
	// empty class to avoid build error
};
VFX_IMPLEMENT_CLASS("VappMmsViewerCp", VappMmsViewerCp, VfxControl);

class VappMmsClock: public VfxObject
{
	VFX_DECLARE_CLASS(VappMmsClock);
	// empty class to avoid build error
};
VFX_IMPLEMENT_CLASS("VappMmsClock", VappMmsClock, VfxObject);
#endif

#endif /*__VENUS_MMI_MMS_VIEWER_CP__*/
