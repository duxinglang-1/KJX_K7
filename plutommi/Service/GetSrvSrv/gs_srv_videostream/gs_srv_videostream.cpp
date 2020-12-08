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
*   gs_srv_videostream.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IVideoStream implement file
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
#ifdef __MMI_VIDEO_STREAM__
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "mdi_video.h"
#include "DtcntSrvGprot.h"
#include "ABM_SOC_ENUMS.H"
#include "abm_api.h"
#include "cbm_api.h"
#include "mmi_rp_app_mre_def.h"

extern U32 vm_graphic_get_trans_handle(S32 handle);
#ifdef __cplusplus
}
#endif 

#include "gs_srv_videostream_impl.h"
#include "vmlog.h"


 
gs_connect_result_callback VideoStreamService::m_gs_connect_result_callback = NULL;
gs_buffering_result_callback VideoStreamService::m_gs_buffering_result_callback = NULL;
gs_video_stream_play_finish_callback VideoStreamService::m_gs_play_finish_callback = NULL;
VM_P_HANDLE VideoStreamService::m_phandle = 0;

void* VideoStreamService::m_gs_connect_result_callback_user_data = NULL;
void* VideoStreamService::m_gs_buffering_result_callback_user_data = NULL;
void* VideoStreamService::m_gs_play_finish_callback_user_data = NULL;

GS_IBase *CreateVideoStreamService(U32 hd)
{
	VideoStreamService* service = NULL;
	GS_NEW_EX(service, VideoStreamService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}

VideoStreamService::VideoStreamService(U32 handle):GS_CBase(handle)
{

	cbm_app_info_struct app_info;
	U8 app_id;
	
	app_info.app_icon_id = IMAGE_MRE_LARGE_ICON;
	app_info.app_str_id = STR_MRE_TITLE;
	app_info.app_type = DTCNT_APPTYPE_MRE_NET;
	cbm_register_app_id_with_app_info(&app_info, &app_id);

	m_data_account_id_for_mdi_stream_connect = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID,(cbm_sim_id_enum)0,app_id,KAL_FALSE);

	if (m_data_account_id_for_mdi_stream_connect == CBM_INVALID_ACCT_ID)
	{
		ASSERT(0);
	}
	cbm_deregister_app_id(app_id);

}


void VideoStreamService::gs_connect_result_callback_helper(S32 ret, gs_video_info_struct* video_info,void *user_data)
{
	if (m_gs_connect_result_callback == NULL )
	{
		return;
	}

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}

	m_gs_connect_result_callback(ret, video_info,user_data);

	vm_pmng_reset_ctx();

}

void VideoStreamService::gs_buffering_result_callback_helper(S32 ret, gs_video_info_struct* video_info,void *user_data)
{

	if (m_gs_buffering_result_callback == NULL )
	{
		return;
	}

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}

	m_gs_buffering_result_callback(ret, video_info,user_data);

	vm_pmng_reset_ctx();

}


void VideoStreamService::gs_video_stream_play_finish_callback_helper (S32 ret,void *user_data)
{

	if (m_gs_buffering_result_callback == NULL )
	{
		return;
	}

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}

	m_gs_play_finish_callback(ret,user_data);

	vm_pmng_reset_ctx();

}


S32 CALLCC VideoStreamService::queryInterface(S32 iid, GS_IBase **pptr)
{
	/* Please notes: pptr may be a proxy, your call should not use it directly. */
	if (pptr == NULL)
		return 0;
	if (iid == IID_IVIDEOSTREAM)
	{
		//vm_log_debug("ProfileService::iid == IID_IPROFILE ");
		addRef();
		*pptr = BIND_PROXY(IVideoStream,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}


S32 CALLCC VideoStreamService::gs_video_stream_init()
{
	S32 ret;
	ret = mdi_video_stream_init(ASM_ANONYMOUS_ID);

	return ret;
} 

S32 CALLCC VideoStreamService::gs_video_stream_deinit()
{
	S32 ret;
	ret = mdi_video_stream_deinit();
	return ret;

}

S32 CALLCC VideoStreamService::gs_video_stream_connect(gs_video_stream_connect_struct* p,	gs_connect_result_callback connect_result_callback,void* user_data)
{
	S32 ret = 0;


	m_phandle = vm_pmng_get_current_handle();

	if (m_phandle < 0)
	{
		return GS_RES_VDOPLY_ERR_FAILED;
	}

	if(p == NULL)
	{
		return GS_RES_VDOPLY_ERR_FAILED;
	}	

	m_gs_connect_result_callback = connect_result_callback;
	m_gs_connect_result_callback_user_data = user_data;

	ret =  mdi_video_stream_connect(
		m_data_account_id_for_mdi_stream_connect,
		(mdi_video_stream_type_enum)p->stream_type, 
		(CHAR*)p->data_path,
		p->use_proxy,
		(CHAR*)p->proxy,
		p->port,
		p->use_udp_port,
		p->highest_udp_port,
		p->lowest_udp_port,            
		(mdi_connect_result_callback)gs_connect_result_callback_helper,
		NULL);

	return ret;
}


S32 CALLCC VideoStreamService::gs_video_stream_disconnect()
{
	S32 ret;
	ret =  mdi_video_stream_disconnect();
	return ret;

}


MMI_BOOL CALLCC VideoStreamService::gs_video_stream_is_connected()
{
	MMI_BOOL ret=  mdi_video_stream_is_connected();
	return ret;

}


S32 CALLCC VideoStreamService::gs_video_stream_start_buffering(U32 time, gs_buffering_result_callback buffering_result_callback,void* user_data)
{
	S32 ret;

	m_phandle = vm_pmng_get_current_handle();
	if (m_phandle < 0)
	{
		return GS_RES_VDOPLY_ERR_PLAY_FAILED;
	}


	m_gs_buffering_result_callback = buffering_result_callback;
	m_gs_buffering_result_callback_user_data = user_data;

	ret =  mdi_video_stream_start_buffering(time, (mdi_buffering_result_callback)gs_buffering_result_callback_helper,NULL);
	return ret;

}


S32 CALLCC VideoStreamService::gs_video_stream_stop_buffering()
{
	S32 ret= mdi_video_stream_stop_buffering();
	return ret;

}


S32 CALLCC VideoStreamService::gs_video_stream_play(gs_video_stream_play_struct *p,gs_play_finish_callback play_finish_callback,void* user_data)
{
	int ret= 0;


	m_phandle = vm_pmng_get_current_handle();

	if (m_phandle < 0)
	{
		return GS_RES_VDOPLY_ERR_PLAY_FAILED;
	}

	if(p == NULL)
	{
		return GS_RES_VDOPLY_ERR_PLAY_FAILED;
	}
	m_gs_play_finish_callback = play_finish_callback;
	m_gs_play_finish_callback_user_data = user_data;



	U32 nativeHandle = vm_graphic_get_trans_handle(p->player_layer_handle);


	ret =  mdi_video_stream_play(
		nativeHandle, 
		p->blt_layer_flag,
		p->play_layer_flag, 
		p->is_visual_update, 
		p->audio_path, 
		p->rotate, 
		gs_video_stream_play_finish_callback_helper,
		NULL);

	return ret;
}

S32 CALLCC VideoStreamService::gs_video_stream_stop()
{
	S32 ret =  mdi_video_stream_stop();
	return ret;
}

S32 CALLCC VideoStreamService::gs_video_stream_pause()
{
	S32 ret  = mdi_video_stream_pause();

	return ret;
}

S32 CALLCC VideoStreamService::gs_video_stream_resume(gs_video_stream_resume_struct* p)
{
	S32 ret;
	U32 nativeHandle = vm_graphic_get_trans_handle(p->player_layer_handle);



	if(p != NULL)
	{

		ret =  mdi_video_stream_resume(
			nativeHandle, 
			p->blt_layer_flag,
			p->play_layer_flag, 
			p->is_visual_update, 
			p->audio_path, 
			p->rotate);
		return ret;
	}
	else
	{
		return GS_RES_VDOPLY_ERR_FAILED;
	}

}



S32 CALLCC VideoStreamService::gs_video_stream_get_buf_percentage(S32 *percentage)
{
	S32 ret = mdi_video_stream_get_buf_percentage(percentage);

	return ret;
}

void CALLCC VideoStreamService::gs_video_stream_get_cur_play_time(U64 *cur_play_time)
{
	mdi_video_stream_get_cur_play_time(cur_play_time);
}

S32 CALLCC VideoStreamService::gs_video_stream_set_brightness(U16 brightness)
{
	return mdi_video_stream_set_brightness(brightness);
}

S32 CALLCC VideoStreamService::gs_video_stream_set_contrast(U16 contrast)
{
	return mdi_video_stream_set_contrast(contrast);
}

S32 CALLCC VideoStreamService::gs_video_stream_get_dimension(S32 *video_width, S32 *video_height)
{
	S32 ret = mdi_video_stream_get_dimension(video_width, video_height);
	return ret;
}


S32 CALLCC VideoStreamService::gs_video_stream_get_audio_info(PU8 aud_channel_no, PU16 aud_sample_rate)
{
	S32 ret =  mdi_video_stream_get_audio_info( aud_channel_no, aud_sample_rate);
	return ret;

}


S32 CALLCC VideoStreamService::gs_video_stream_set_track(U8 type)
{
	S32 ret =  mdi_video_stream_set_track(type);
	return ret;
}

#endif


