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
*   gs_srv_videorecord.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IVideoRecord implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "mdi_video.h"
extern U32 vm_graphic_get_trans_handle(S32 handle);

#ifdef __cplusplus
}
#endif 

#include "gs_srv_videorecord_impl.h"
#include "vmlog.h"

gs_save_result_callback VideoRecordService::m_gs_save_result_callback = NULL;
gs_record_result_callback VideoRecordService::m_gs_record_result_callback = NULL;
S32 VideoRecordService::m_phandle = 0;

void* VideoRecordService::m_gs_save_result_user_data = NULL;
void* VideoRecordService::m_gs_record_result_user_data = NULL;

GS_IBase *CreateVideoRecordService(U32 hd)
{
	VideoRecordService* service = NULL;
	GS_NEW_EX(service, VideoRecordService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}


VideoRecordService::VideoRecordService(U32 handle):GS_CBase(handle){}


void VideoRecordService::gs_save_result_callback_helper (S32 ret,void* user_data)
{
	kal_prompt_trace(MOD_IDLE,"SAVE CB RET = %d",ret);

	if (m_gs_save_result_callback == NULL )
	{
		return;
	}
	kal_prompt_trace(MOD_IDLE,"SAVE CB 2");

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}
	kal_prompt_trace(MOD_IDLE,"SAVE CB 3");

	m_gs_save_result_callback(ret,user_data);
	kal_prompt_trace(MOD_IDLE,"SAVE CB 4");
	vm_pmng_reset_ctx();
	kal_prompt_trace(MOD_IDLE,"SAVE CB 5");

}

void VideoRecordService::gs_record_result_callback_helper (S32 ret,void* user_data)
{
	kal_prompt_trace(MOD_IDLE,"record CB RET = %d",ret);

	if (m_gs_record_result_callback == NULL )
	{
		return;
	}
	kal_prompt_trace(MOD_IDLE,"RECORD CB 2");

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}
	kal_prompt_trace(MOD_IDLE,"RECORD CB 3");

	m_gs_record_result_callback(ret,user_data);
	kal_prompt_trace(MOD_IDLE,"RECORD CB 4");

	vm_pmng_reset_ctx();
	kal_prompt_trace(MOD_IDLE,"RECORD CB 5");

}

S32 CALLCC VideoRecordService::queryInterface(S32 iid, GS_IBase **pptr)
{
	if (pptr == NULL)
		return 0;
	if (iid == IID_IVIDEORECORD)
	{
		addRef();
		*pptr = BIND_PROXY(IVideoRecord,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}


S32 CALLCC VideoRecordService::gs_video_set_camera_id(U16 camera_id)
{
	S32 ret =  mdi_video_set_camera_id(camera_id);
	kal_prompt_trace(MOD_IDLE,"mdi_video_set_camera_id ret = %d",ret);
	return ret;

}


S32 CALLCC VideoRecordService::gs_video_detect_sensor_id(U8 cam_id)
{
	S32 ret = mdi_video_detect_sensor_id(cam_id);
	kal_prompt_trace(MOD_IDLE,"mdi_video_detect_sensor_id ret = %d",ret);
	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_power_on()
{
	S32 ret =  mdi_video_rec_power_on(ASM_ANONYMOUS_ID);
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_power_on ret = %d",ret);

	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_power_off()
{
	S32 ret  = mdi_video_rec_power_off();
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_power_off ret = %d",ret);
	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_record_start(S8 *filename, gs_record_result_callback record_result_callback,void* user_data)
{
	S32 ret;
	m_phandle = vm_pmng_get_current_handle();
	m_gs_record_result_callback = record_result_callback;
	m_gs_record_result_user_data = user_data;
	ret = mdi_video_rec_record_start(filename,(mdi_record_result_callback)gs_record_result_callback_helper,m_gs_record_result_user_data);
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_record_start ret = %d",ret);
	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_record_stop()
{
	S32 ret;
	ret = mdi_video_rec_record_stop();
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_record_stop ret = %d",ret);
	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_record_pause(MMI_BOOL stop_preview)
{
	S32 ret;
	ret = mdi_video_rec_record_pause( stop_preview);
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_record_pause ret = %d",ret);
	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_record_resume()
{
	S32 ret;

	ret = mdi_video_rec_record_resume();
	kal_prompt_trace(MOD_IDLE,"gs_video_rec_record_resume ret = %d",ret);
	return ret;

}


S32 CALLCC VideoRecordService::gs_video_rec_preview_start(
	S32 preview_layer_handle,
	MMI_BOOL is_lcd_update,
	gs_video_setting_struct *setting_p)
{
	gdi_handle handles[6] = {0};
	int gdi_layer_count = 6;


	U32 blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
	U32 preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
	int i = 0;

	S32 mdi_return;

	gdi_layer_get_blt_layer_ext(&handles[0],&handles[1],&handles[2],&handles[3],&handles[4],&handles[5]);
	kal_prompt_trace(MOD_IDLE,"video record blt layer %u,%u,%u,%u,%u,%u",handles[0],handles[1],handles[2],handles[3],handles[4],handles[5]);
	U32 nativeHandle = vm_graphic_get_trans_handle(preview_layer_handle);
	for(i=0;i<gdi_layer_count;i++)
	{
		if(handles[i] == nativeHandle)
		{
			break;
		}
	}

	kal_prompt_trace(MOD_IDLE,"video record cjl i = %d",i);

	switch(i)
	{
	case 0:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
		preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
		break;
	case 1:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
		preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
		break;
	case 2:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_2;
		preview_layer_flag = GDI_LAYER_ENABLE_LAYER_2;
		break;
	case 3:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_3;
		preview_layer_flag = GDI_LAYER_ENABLE_LAYER_3;
		break;
#ifdef GDI_6_LAYERS
	case 4:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_4;
		preview_layer_flag = GDI_LAYER_ENABLE_LAYER_4;
		break;
	case 5:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_5;
		preview_layer_flag = GDI_LAYER_ENABLE_LAYER_5;
		break;
#endif
	}
	kal_prompt_trace(MOD_IDLE,"preview_layer = %u,setting_p = %d,is_lcd_update = %d",nativeHandle,setting_p,is_lcd_update);

	mdi_return =  mdi_video_rec_preview_start(nativeHandle,blt_layer_flag,preview_layer_flag,is_lcd_update,(mdi_video_setting_struct*)setting_p);
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_preview_start = %d",mdi_return);
	return mdi_return;

}


S32 CALLCC VideoRecordService::gs_video_rec_preview_stop()
{
	S32 ret;

	ret = mdi_video_rec_preview_stop();
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_preview_stop = %d",ret);

	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_save_file(S8 *filepath, gs_save_result_callback save_result_callback,void* user_data)
{
	S32 ret;

	m_phandle = vm_pmng_get_current_handle();
	m_gs_save_result_callback = save_result_callback;
	m_gs_save_result_user_data = user_data;
	ret = mdi_video_rec_save_file(filepath,  (mdi_save_result_callback)gs_save_result_callback_helper,m_gs_save_result_user_data);
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_save_file = %d",ret);

	return ret;
}


S32 CALLCC VideoRecordService::gs_video_rec_stop_save()
{

	S32 ret = mdi_video_rec_stop_save();
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_stop_save = %d",ret);
	return ret;

}


BOOL CALLCC VideoRecordService::gs_video_rec_has_unsaved_file(S8 *filepath)
{
	BOOL ret =  mdi_video_rec_has_unsaved_file(filepath);
	kal_prompt_trace(MOD_IDLE,"mdi_video_rec_has_unsaved_file = %d",ret);

	return ret;

}


void CALLCC VideoRecordService::gs_video_rec_delete_unsaved_file(S8 *filepath)
{
	mdi_video_rec_delete_unsaved_file(filepath);
}


void CALLCC VideoRecordService::gs_video_rec_get_cur_record_time(U64 *cur_record_time)
{
	mdi_video_rec_get_cur_record_time(cur_record_time);
}



void CALLCC VideoRecordService::gs_video_rec_update_para_ev(U16 para)
{
	mdi_video_rec_update_para_ev( para);
}


void CALLCC VideoRecordService::gs_video_rec_update_para_zoom(U16 para)
{
	mdi_video_rec_update_para_zoom( para);
}


void CALLCC VideoRecordService::gs_video_rec_update_para_effect(U16 para)
{
	mdi_video_rec_update_para_effect( para);
}


void CALLCC VideoRecordService::gs_video_rec_update_para_wb(U16 para)
{
	mdi_video_rec_update_para_wb(para);
}


void CALLCC VideoRecordService::gs_video_rec_update_para_night(U16 para)
{
	mdi_video_rec_update_para_night(para);
}

U16 CALLCC VideoRecordService::gs_video_rec_get_max_zoom_factor(S32 record_width, S32 record_height)
{
	return mdi_video_rec_get_max_zoom_factor(record_width, record_height);
}


U64 CALLCC VideoRecordService::gs_video_rec_get_record_file_size()
{
	return mdi_video_rec_get_record_file_size();
}


void CALLCC VideoRecordService::gs_video_rec_load_default_setting(gs_video_setting_struct *setting_p)
{
	mdi_video_rec_load_default_setting((mdi_video_setting_struct*)setting_p);
}


S32 CALLCC VideoRecordService::gs_video_rec_update_blt_pause()
{
	return mdi_video_rec_update_blt_pause();
}


S32 CALLCC VideoRecordService::gs_video_rec_update_blt_resume(
	S32 preview_layer_handle,
	U32 blt_layer_flag,     
	U32 preview_layer_flag, 
	MMI_BOOL is_lcd_update)
{
	U32 nativeHandle = vm_graphic_get_trans_handle(preview_layer_handle);

	return mdi_video_rec_update_blt_resume(
		nativeHandle,
		blt_layer_flag,     
		preview_layer_flag, 
		is_lcd_update);
}

#endif


