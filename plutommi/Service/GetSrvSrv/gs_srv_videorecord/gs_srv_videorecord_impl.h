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

/*****************************************************************************
*
* Filename:
* ---------
*   CALLCC gs_srv_videorecord_impl.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   Class header file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _GS_SRV_VIDEORECORD_IMPL_H
#define _GS_SRV_VIDEORECORD_IMPL_H

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_videorecord_interface_def.h"
#include "vmpromng.h"

class VideoRecordService : public GS_CBase, public IVideoRecord
{
private:
	static  gs_save_result_callback m_gs_save_result_callback;
	static gs_record_result_callback m_gs_record_result_callback;
	static S32 m_phandle;
	static void* m_gs_save_result_user_data;
	static void* m_gs_record_result_user_data;

	static  void gs_save_result_callback_helper (S32 ret,void *user_data);
	static  void gs_record_result_callback_helper (S32 ret,void *user_data);



public:
	VideoRecordService(U32 handle);

	/* Common API */
	virtual S32 CALLCC addRef()
	{
		return GS_CBase::addRef();
	}
	virtual S32 CALLCC release()
	{
		return GS_CBase::release();
	}
	virtual S32 CALLCC queryInterface(S32 iid, GS_IBase **pptr);

	/* Functional API */
	virtual S32 CALLCC gs_video_set_camera_id(U16 camera_id);
	virtual S32 CALLCC gs_video_detect_sensor_id(U8 cam_id);
	virtual S32 CALLCC gs_video_rec_power_on();
	virtual S32 CALLCC gs_video_rec_power_off();
	virtual S32 CALLCC gs_video_rec_record_start(S8 *filename,  gs_record_result_callback record_result_callback,void* user_data);
	virtual S32 CALLCC gs_video_rec_record_stop();
	virtual S32 CALLCC gs_video_rec_record_pause(MMI_BOOL stop_preview);
	virtual S32 CALLCC gs_video_rec_record_resume();
	virtual S32 CALLCC gs_video_rec_preview_start(
		S32 preview_layer_handle,
		MMI_BOOL is_lcd_update,
		gs_video_setting_struct *setting_p);

	virtual S32 CALLCC gs_video_rec_preview_stop();
	virtual S32 CALLCC gs_video_rec_save_file(S8 *filepath,  gs_save_result_callback save_result_callback,void* user_data);
	virtual S32 CALLCC gs_video_rec_stop_save();
	virtual BOOL       CALLCC gs_video_rec_has_unsaved_file(S8 *filepath);
	virtual void CALLCC gs_video_rec_delete_unsaved_file(S8 *filepath);
	virtual void CALLCC gs_video_rec_get_cur_record_time(U64 *cur_record_time);
	virtual void CALLCC gs_video_rec_update_para_ev(U16 para);
	virtual void CALLCC gs_video_rec_update_para_zoom(U16 para);
	virtual void CALLCC gs_video_rec_update_para_effect(U16 para);
	virtual void CALLCC gs_video_rec_update_para_wb(U16 para);
	virtual void CALLCC gs_video_rec_update_para_night(U16 para);
	virtual U16 CALLCC gs_video_rec_get_max_zoom_factor(S32 record_width, S32 record_height);
	virtual U64 CALLCC gs_video_rec_get_record_file_size();
	virtual void CALLCC gs_video_rec_load_default_setting( gs_video_setting_struct *setting_p);
	virtual S32 CALLCC gs_video_rec_update_blt_pause();


	virtual S32 CALLCC gs_video_rec_update_blt_resume(
		S32 preview_layer_handle,
		U32 blt_layer_flag,     
		U32 preview_layer_flag, 
		MMI_BOOL is_lcd_update);

};


#endif
