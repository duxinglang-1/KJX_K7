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
 *  vapp_mms_lite_viewer.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MMS_LITE_VIEWER_H__
#define __VAPP_MMS_LITE_VIEWER_H__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_msg_viewer.h"
#include "Vapp_mms_data.h"
#include "vcp_photo_border_frame.h"
extern "C"
{
#include "MMSSRVProt.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__

#define VAPP_MMS_STATUS_ICON_SIZE 34
#define VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN 0
#define VAPP_MMS_STATUS_ICON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_STATUS_ICON_SIZE)/2)

#define VAPP_MMS_THUMBNAIL_LEFT_MARGIN 14
#define VAPP_MMS_THUMBNAIL_RIGHT_MARGIN 14
#define VAPP_MMS_THUMBNAIL_UPPER_MARGIN 0
#define VAPP_MMS_THUMBNAIL_SIZE 70
#define VAPP_MMS_THUMBNAIL_IMAGE_SIZE 64
#define VAPP_MMS_BUTTON_HEIGHT VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_WIDTH VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_BUTTON_HEIGHT)/2)
#define VAPP_MMS_BUTTON_RIGHT_MARGIN 0
#define VAPP_MMS_BUTTON_LEFT_MARGIN 14
#define VAPP_MMS_BUTTON_FONT_SIZE 28
#define VAPP_MMS_SUBJECT_FONT_SIZE 26
#define VAPP_MMS_NOTIFICATION_SUBJECT_LEFT_MARGIN 0
#define VAPP_MMS_TEXT_MARGIN 6
#define VAPP_MMS_SUBJECT_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - (2*VAPP_MMS_SUBJECT_FONT_SIZE) - VAPP_MMS_TEXT_MARGIN)/2)
#define VAPP_MMS_SIZE_FONT_SIZE 20
#define VAPP_MMS_SUBJECT_SINGLE_LINE_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_SUBJECT_FONT_SIZE)/2)      

#elif defined(__MMI_MAINLCD_320X480__)

#define VAPP_MMS_STATUS_ICON_SIZE 26
#define VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN 0
#define VAPP_MMS_STATUS_ICON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_STATUS_ICON_SIZE)/2)

#define VAPP_MMS_THUMBNAIL_LEFT_MARGIN 6
#define VAPP_MMS_THUMBNAIL_RIGHT_MARGIN 6
#define VAPP_MMS_THUMBNAIL_UPPER_MARGIN 0
#define VAPP_MMS_THUMBNAIL_SIZE 46
#define VAPP_MMS_THUMBNAIL_IMAGE_SIZE 40
#define VAPP_MMS_BUTTON_HEIGHT VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_WIDTH VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_BUTTON_HEIGHT)/2)
#define VAPP_MMS_BUTTON_RIGHT_MARGIN 0
#define VAPP_MMS_BUTTON_LEFT_MARGIN 8
#define VAPP_MMS_BUTTON_FONT_SIZE 16
#define VAPP_MMS_SUBJECT_FONT_SIZE 16
#define VAPP_MMS_NOTIFICATION_SUBJECT_LEFT_MARGIN 0
#define VAPP_MMS_TEXT_MARGIN 4
#define VAPP_MMS_SUBJECT_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - (2*VAPP_MMS_SUBJECT_FONT_SIZE) - VAPP_MMS_TEXT_MARGIN)/2)
#define VAPP_MMS_SIZE_FONT_SIZE 14
#define VAPP_MMS_SUBJECT_SINGLE_LINE_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_SUBJECT_FONT_SIZE)/2)    


#elif defined(__MMI_MAINLCD_240X320__)

#define VAPP_MMS_STATUS_ICON_SIZE 24
#define VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN 0
#define VAPP_MMS_STATUS_ICON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_STATUS_ICON_SIZE)/2)

#define VAPP_MMS_THUMBNAIL_LEFT_MARGIN 5
#define VAPP_MMS_THUMBNAIL_RIGHT_MARGIN 5
#define VAPP_MMS_THUMBNAIL_UPPER_MARGIN 0
#define VAPP_MMS_THUMBNAIL_SIZE 36
#define VAPP_MMS_THUMBNAIL_IMAGE_SIZE 32
#define VAPP_MMS_BUTTON_HEIGHT VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_WIDTH VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_BUTTON_HEIGHT)/2)
#define VAPP_MMS_BUTTON_RIGHT_MARGIN 0
#define VAPP_MMS_BUTTON_LEFT_MARGIN 8
#define VAPP_MMS_BUTTON_FONT_SIZE 14
#define VAPP_MMS_SUBJECT_FONT_SIZE 14
#define VAPP_MMS_NOTIFICATION_SUBJECT_LEFT_MARGIN 0
#define VAPP_MMS_TEXT_MARGIN 2
#define VAPP_MMS_SUBJECT_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - (2*VAPP_MMS_SUBJECT_FONT_SIZE) - VAPP_MMS_TEXT_MARGIN)/2)
#define VAPP_MMS_SIZE_FONT_SIZE 12
#define VAPP_MMS_SUBJECT_SINGLE_LINE_UPPER_MARGIN  ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_SUBJECT_FONT_SIZE)/2)        

#elif defined(__MMI_MAINLCD_240X400__)

#define VAPP_MMS_STATUS_ICON_SIZE 24
#define VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN 0
#define VAPP_MMS_STATUS_ICON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_STATUS_ICON_SIZE)/2)

#define VAPP_MMS_THUMBNAIL_LEFT_MARGIN 5
#define VAPP_MMS_THUMBNAIL_RIGHT_MARGIN 5
#define VAPP_MMS_THUMBNAIL_UPPER_MARGIN 0
#define VAPP_MMS_THUMBNAIL_SIZE 36
#define VAPP_MMS_THUMBNAIL_IMAGE_SIZE 32
#define VAPP_MMS_BUTTON_HEIGHT VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_WIDTH VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_BUTTON_HEIGHT)/2)
#define VAPP_MMS_BUTTON_RIGHT_MARGIN 0
#define VAPP_MMS_BUTTON_LEFT_MARGIN 8
#define VAPP_MMS_BUTTON_FONT_SIZE 14
#define VAPP_MMS_SUBJECT_FONT_SIZE 14
#define VAPP_MMS_NOTIFICATION_SUBJECT_LEFT_MARGIN 0
#define VAPP_MMS_TEXT_MARGIN 2
#define VAPP_MMS_SUBJECT_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - (2*VAPP_MMS_SUBJECT_FONT_SIZE) - VAPP_MMS_TEXT_MARGIN)/2)
#define VAPP_MMS_SIZE_FONT_SIZE 12
#define VAPP_MMS_SUBJECT_SINGLE_LINE_UPPER_MARGIN  ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_SUBJECT_FONT_SIZE)/2)        

#else
   
#define VAPP_MMS_STATUS_ICON_SIZE 26
#define VAPP_MMS_LITE_VIEWER_INNER_LEFT_MARGIN 0
#define VAPP_MMS_STATUS_ICON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_STATUS_ICON_SIZE)/2)

#define VAPP_MMS_THUMBNAIL_LEFT_MARGIN 6
#define VAPP_MMS_THUMBNAIL_RIGHT_MARGIN 6
#define VAPP_MMS_THUMBNAIL_UPPER_MARGIN 0
#define VAPP_MMS_THUMBNAIL_SIZE 46
#define VAPP_MMS_THUMBNAIL_IMAGE_SIZE 40
#define VAPP_MMS_BUTTON_HEIGHT VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_WIDTH VAPP_MMS_STATUS_ICON_SIZE
#define VAPP_MMS_BUTTON_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_BUTTON_HEIGHT)/2)
#define VAPP_MMS_BUTTON_RIGHT_MARGIN 0
#define VAPP_MMS_BUTTON_LEFT_MARGIN 8
#define VAPP_MMS_BUTTON_FONT_SIZE 16
#define VAPP_MMS_SUBJECT_FONT_SIZE 16
#define VAPP_MMS_NOTIFICATION_SUBJECT_LEFT_MARGIN 0
#define VAPP_MMS_TEXT_MARGIN 4
#define VAPP_MMS_SUBJECT_UPPER_MARGIN ((VAPP_MMS_THUMBNAIL_SIZE - (2*VAPP_MMS_SUBJECT_FONT_SIZE) - VAPP_MMS_TEXT_MARGIN)/2)
#define VAPP_MMS_SIZE_FONT_SIZE 14
#define VAPP_MMS_SUBJECT_SINGLE_LINE_UPPER_MARGIN  ((VAPP_MMS_THUMBNAIL_SIZE - VAPP_MMS_SUBJECT_FONT_SIZE)/2)    

#endif

#define VAPP_MMS_SUBJECT_FONT_COLOR_R 21
#define VAPP_MMS_SUBJECT_FONT_COLOR_G 21
#define VAPP_MMS_SUBJECT_FONT_COLOR_B 1

#define VAPP_MMS_SIZE_FONT_COLOR_R 109
#define VAPP_MMS_SIZE_FONT_COLOR_G 109
#define VAPP_MMS_SIZE_FONT_COLOR_B 109



/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

class VappMMSLiteViewer : public VappMsgViewerCp
{
 VFX_DECLARE_CLASS(VappMMSLiteViewer);
private:
	typedef enum
	{
		OBJ_TYPE_NONE,
		OBJ_TYPE_IMAGE,
		OBJ_TYPE_VIDEO
	}obj_type_enum;

    
// Constructor
public:
    VappMMSLiteViewer(VfxU32 msg_id = 0) 
			:m_msg_id(msg_id),
			m_msg_type(0),
			m_parent_file_handle(0),
			m_outer_size(0,0),
			m_old_outer_size(0,0),
			m_liteview_size(0,0),
			m_frame(NULL), 
			m_s_frame(NULL),
			m_txt_subject(NULL),
			m_txt_size(NULL),
			m_button(NULL),
			m_indicator(NULL),
			m_data(NULL),
			m_video_th_memory(NULL),
			m_yuv_video_th_memory(NULL),
			m_th_data(NULL),
			m_sync_info(NULL),
			m_result(0),
			m_file_path(NULL),
			m_is_msg_invalid(VFX_FALSE),
			m_is_set_outer_size(VFX_TRUE),
			m_is_register(VFX_FALSE),
			m_is_read(VFX_FALSE),
			m_is_reg_free_ev(VFX_FALSE),
			m_is_inter_update(VFX_FALSE)
	{
	}
	

// Property
    virtual void setMsgId(VfxU32 msgId);
    /*virtual void setMsgType(VfxU32 msgType);*/
	virtual VfxU32 getTimestamp();
// Method
    virtual void forceUpdate();
	VfxBool isMsgInValid(void);

// Overridable
protected:
    void setSize(VfxS32 w, VfxS32 h);
	virtual void setBounds(const VfxRect &value);
    virtual void onInit();
	virtual void onDeinit();
    

// Implementation
private:
	void onClickResend(VfxObject *obj, VfxId id);
    void onClickDownload(VfxObject *obj, VfxId id);
	void onMmsContentReady(void);
	void setInternalSize(VfxS32 w, VfxS32 h);
	void closeCommonObjects(void);
	VfxBool openFile(const WCHAR *msg_path,VfxU32 obj_offset, VfxU32 obj_size);
	VfxSize setTextData(VfxFrame *txt,
								  const VfxWString &str,
							   VfxBool autoResize,
							      VfxBool autoFont,
								    VfxU32 fontSize,
								    const VfxColor &color,
								  VfxTextFrame::AlignModeEnum alignMode,
								       const VfxSize  &size,
								       const VfxPoint &pos);
	static mmi_ret listener(mmi_event_struct* evt);
	static mmi_ret serviceFree(mmi_event_struct* evt);
	
	static void dataReadyCb(srv_mms_result_enum result, void *rsp_data, void* user_data);
	static void * allocMem(U32 size, void *user_data);
    static void  freeMem(void *mem);

private:
    
    VfxU32 m_msg_id;
    VfxU32 m_msg_type;
	VfxS32 m_parent_file_handle;
	VfxSize m_outer_size;
	VfxSize m_old_outer_size;
	VfxSize m_liteview_size;

	VfxFrame *m_frame;
	VcpPhotoBorderFrame *m_s_frame;

	VfxTextFrame *m_txt_subject;
	VfxTextFrame *m_txt_size;

	VcpImageButton *m_button;
    VcpActivityIndicator *m_indicator;
	VappMmsViewerData *m_data;
	VfxU8 * m_video_th_memory;
	
	VfxU8 * m_yuv_video_th_memory;
	srv_mms_get_lite_view_data_struct * m_th_data;
    srv_mms_sync_msg_info_struct *m_sync_info;
    VfxS32 m_result;
    VfxU16 *m_file_path;
	
	VfxBool m_is_msg_invalid;
	VfxBool m_is_set_outer_size;
    VfxBool m_is_register;
	VfxBool m_is_read;
	VfxBool m_is_reg_free_ev;
	VfxBool m_is_inter_update;



};

#endif /* __MMI_MMS_2__  */
#endif /* __VAPP_MMS_LITE_VIEWETR_H__ */

