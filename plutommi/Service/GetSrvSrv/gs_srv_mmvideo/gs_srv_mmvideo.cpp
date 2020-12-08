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
*   gs_srv_mmvideo.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IMMVideo implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VIDEO_PLAY_SUPPORT__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "mdi_video.h"

extern U32 vm_graphic_get_trans_handle(S32 handle);

#ifdef __cplusplus
}
#endif  

#include "gs_srv_mmvideo_impl.h"
#include "vmlog.h"


gs_open_result_callback MMVideoService::m_gs_open_result_callback = NULL;
gs_play_finish_callback MMVideoService::m_gs_play_finish_callback = NULL;
gs_seek_result_callback MMVideoService::m_gs_seek_result_callback = NULL;
S32 MMVideoService::m_phandle = 0; 

void* MMVideoService::m_gs_open_result_user_data = NULL;
void* MMVideoService::m_gs_play_finish_user_data = NULL;
void* MMVideoService::m_gs_seek_result_user_data = NULL;



GS_IBase *CreateMMVideoService(U32 hd)
{
	MMVideoService* service = NULL;
	GS_NEW_EX(service, MMVideoService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}


void MMVideoService::open_result_callback_helper(S32 ret, gs_video_info_struct *video_info,void *user_data)
{
	if (m_gs_open_result_callback == NULL )
	{
		return;
	}

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}

	m_gs_open_result_callback(ret, video_info,m_gs_open_result_user_data);

	vm_pmng_reset_ctx();

}

void MMVideoService::play_finish_callback_helper (S32 ret,void *user_data)
{
	if(m_gs_play_finish_callback == NULL)
	{
		return;
	}
	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}
	m_gs_play_finish_callback(ret,m_gs_play_finish_user_data);
	vm_pmng_reset_ctx();
}

void MMVideoService::seek_result_callback_helper (S32 ret,void *user_data)
{

	if(m_gs_seek_result_callback ==  NULL)
	{
		return;
	}

	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}

	m_gs_seek_result_callback(ret,m_gs_seek_result_user_data);

	vm_pmng_reset_ctx();

}

S32 CALLCC MMVideoService::queryInterface(S32 iid, GS_IBase **pptr)
{
	/* Please notes: pptr may be a proxy, your call should not use it directly. */
	if (pptr == NULL)
		return 0;
	if (iid == IID_MMVIDEO)
	{
		//vm_log_debug("ProfileService::iid == IID_IPROFILE ");
		addRef();
		*pptr = BIND_PROXY(IMMVideo,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}



S32 CALLCC MMVideoService::video_ply_open_file(const S8 *filename,gs_open_result_callback open_result_callback,void* user_data)
{
	int ret = 0;
	m_phandle = vm_pmng_get_current_handle();


	if (m_phandle < 0)
	{
		return GS_RES_VDOPLY_ERR_OPEN_FILE_FAILED;
	}


	m_gs_open_result_callback = open_result_callback;
	m_gs_open_result_user_data = user_data;
	ret = mdi_video_ply_open_file(ASM_ANONYMOUS_ID,filename,(mdi_open_result_callback)open_result_callback_helper,m_gs_open_result_user_data);
	return ret;
}


S32 CALLCC MMVideoService::video_ply_close_file()
{
	//reset callback here??
	return mdi_video_ply_close_file();
}


S32 CALLCC MMVideoService::video_ply_play(gs_video_play_struct* pPlayStruct,gs_play_finish_callback callback,void* user_data)
{
	int ret= 0;
	gdi_handle handles[6] = {0};
	int gdi_layer_count = 6;

	int i = 0;
	U32 nativeHandle;


	U32 blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
	U32 play_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
	m_phandle = vm_pmng_get_current_handle();


	if (m_phandle < 0)
	{
		return GS_RES_VDOPLY_ERR_PLAY_FAILED;
	}

	if(pPlayStruct == NULL)
	{
		return GS_RES_VDOPLY_ERR_PLAY_FAILED;
	}

	m_gs_play_finish_callback = callback;
	m_gs_play_finish_user_data = user_data;

	nativeHandle = vm_graphic_get_trans_handle(pPlayStruct->player_layer_handle);

	gdi_layer_get_blt_layer_ext(&handles[0],&handles[1],&handles[2],&handles[3],&handles[4],&handles[5]);

	for(i = 0;i<gdi_layer_count;i++)
	{
		if(handles[i] == nativeHandle)
		{
			break;
		}
	}


	switch(i)
	{
	case 0:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
		play_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
		break;
	case 1:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
		play_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
		break;
	case 2:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_2;
		play_layer_flag = GDI_LAYER_ENABLE_LAYER_2;
		break;
	case 3:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_3;
		play_layer_flag = GDI_LAYER_ENABLE_LAYER_3;
		break;
#ifdef GDI_6_LAYERS
	case 4:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_4;
		play_layer_flag = GDI_LAYER_ENABLE_LAYER_4;
		break;
	case 5:
		blt_layer_flag = GDI_LAYER_ENABLE_LAYER_5;
		play_layer_flag = GDI_LAYER_ENABLE_LAYER_5;
		break;
#endif

	}



	ret =  mdi_video_ply_play(nativeHandle, 
		blt_layer_flag,
		play_layer_flag, 
		1, //repeat_count 
		MMI_TRUE, //is_visual_update
		pPlayStruct->is_play_audio,
		pPlayStruct->audio_path, 
		MDI_LCD_ROTATE_0,//rotate 
		100, //play_speed
		(mdi_play_finish_callback)play_finish_callback_helper,
		m_gs_play_finish_user_data);

	return ret;
}

S32 CALLCC MMVideoService::video_ply_stop()
{
	// reset callback here??
	return mdi_video_ply_stop();
}





S32 CALLCC MMVideoService::video_ply_snapshot(S32 layer_handle, PS8 file_name)
{
	U32 nativeHandle = vm_graphic_get_trans_handle(layer_handle);
	return mdi_video_ply_snapshot(nativeHandle,file_name);
}

void CALLCC MMVideoService::video_ply_get_cur_play_time(U64 *cur_play_time)
{
	return mdi_video_ply_get_cur_play_time(cur_play_time);
}    


S32 CALLCC MMVideoService::video_ply_seek_and_get_frame(int time,S32 player_layer_handle)
{
	int ret =0;
	m_phandle = vm_pmng_get_current_handle();

	if (m_phandle < 0)
	{
		return GS_RES_VDOPLY_ERR_SEEK_FAILED;
	}


	U32 nativeHandle = vm_graphic_get_trans_handle(player_layer_handle);
	ret = mdi_video_ply_seek_and_get_frame(time,nativeHandle);

	return ret;
}


S32 CALLCC MMVideoService::video_ply_non_block_seek_and_get_frame(int time,
				S32 player_layer_handle,
				gs_seek_result_callback seek_result_callback,
				void *user_data)
{
	int ret =0;
	m_phandle = vm_pmng_get_current_handle();

	if (m_phandle < 0)
	{
		return GS_RES_VDOPLY_ERR_SEEK_FAILED;
	}
	m_gs_seek_result_callback = seek_result_callback;
	m_gs_seek_result_user_data = user_data;
	U32 nativeHandle = vm_graphic_get_trans_handle(player_layer_handle);
	ret = mdi_video_ply_non_block_seek_and_get_frame(time,player_layer_handle,(mdi_seek_result_callback )m_gs_seek_result_callback,m_gs_seek_result_user_data);
	return ret;	

}

S32 CALLCC MMVideoService::video_ply_stop_non_block_seek()
{
	m_gs_seek_result_callback = NULL;
	return mdi_video_ply_stop_non_block_seek();
}

S32 CALLCC MMVideoService::video_ply_set_brightness(U16 brightness)
{
	return mdi_video_ply_set_brightness(brightness);
}

S32 CALLCC MMVideoService::video_ply_set_contrast(U16 contrast)
{
	return mdi_video_ply_set_contrast(contrast);
}


S32 CALLCC MMVideoService::video_ply_check_is_able_to_play(PS8 file_name)
{
	return mdi_video_ply_check_is_able_to_play(file_name);
}


BOOL CALLCC MMVideoService::video_is_playing()
{
	return mdi_video_is_playing();
}


BOOL CALLCC MMVideoService::video_is_recording()
{
#if defined (__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)

	return mdi_video_is_recording();
#else
    return MMI_FALSE;
#endif
}


S32 CALLCC MMVideoService::video_ply_get_total_duration(const S8 *filename, U64* total_duration)
{
	return 0;
}
#endif

