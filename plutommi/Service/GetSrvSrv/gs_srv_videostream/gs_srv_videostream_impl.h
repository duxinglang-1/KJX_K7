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
*   gs_srv_videostream_impl.h
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
#ifndef _GS_SRV_VIDEOSTREAM_IMPL_H
#define _GS_SRV_VIDEOSTREAM_IMPL_H

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_videostream_interface_def.h"

#include "vmpromng.h"


class VideoStreamService : public GS_CBase, public IVideoStream
{
private:
	static gs_connect_result_callback m_gs_connect_result_callback;
	static gs_buffering_result_callback m_gs_buffering_result_callback;
	static gs_video_stream_play_finish_callback m_gs_play_finish_callback;
	static VM_P_HANDLE m_phandle;

	static void* m_gs_connect_result_callback_user_data;
	static void* m_gs_buffering_result_callback_user_data;
	static void* m_gs_play_finish_callback_user_data;



	U32 m_data_account_id_for_mdi_stream_connect;

	static void gs_connect_result_callback_helper(S32 ret, gs_video_info_struct* video_info,void *user_data);
	static void gs_buffering_result_callback_helper(S32 ret, gs_video_info_struct* video_info,void *user_data);
	static void gs_video_stream_play_finish_callback_helper (S32 ret,void *user_data);

 
public:
	VideoStreamService(U32 handle);

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

	virtual S32 CALLCC gs_video_stream_init();
	virtual S32 CALLCC gs_video_stream_deinit();
	virtual S32 CALLCC gs_video_stream_connect(gs_video_stream_connect_struct* p,	gs_connect_result_callback connect_result_callback,void* user_data);
	virtual S32 CALLCC gs_video_stream_disconnect();
	virtual MMI_BOOL CALLCC gs_video_stream_is_connected();
	virtual S32 CALLCC gs_video_stream_start_buffering(U32 time, gs_buffering_result_callback buffering_result_callback,void* user_data);
	virtual S32 CALLCC gs_video_stream_stop_buffering();
	virtual S32 CALLCC gs_video_stream_play(gs_video_stream_play_struct *p,gs_play_finish_callback play_finish_callback,void* user_data);
	virtual S32 CALLCC gs_video_stream_stop();
	virtual S32 CALLCC gs_video_stream_pause();
	virtual S32 CALLCC gs_video_stream_resume(gs_video_stream_resume_struct* p);
	virtual S32 CALLCC gs_video_stream_get_buf_percentage(S32 *percentage);
	virtual void CALLCC gs_video_stream_get_cur_play_time(U64 *cur_play_time);
	virtual S32 CALLCC gs_video_stream_set_brightness(U16 brightness);
	virtual S32 CALLCC gs_video_stream_set_contrast(U16 contrast);
	virtual S32 CALLCC gs_video_stream_get_dimension(S32 *video_width, S32 *video_height);
	virtual S32 CALLCC gs_video_stream_get_audio_info(PU8 aud_channel_no, PU16 aud_sample_rate);
	virtual S32 CALLCC gs_video_stream_set_track(U8 type);

};
#endif 

