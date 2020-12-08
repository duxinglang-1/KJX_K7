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
*   gs_srv_mmvideo_impl.h
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef GS_SRV_MMVIDEO_IMPL_H
#define GS_SRV_MMVIDEO_IMPL_H

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_mmvideo_interface_def.h"
#include "vmpromng.h"


class MMVideoService : public GS_CBase, public IMMVideo
{
private:

	static gs_open_result_callback m_gs_open_result_callback;
	static void* m_gs_open_result_user_data;
	static gs_play_finish_callback m_gs_play_finish_callback;
	static void* m_gs_play_finish_user_data;
	static gs_seek_result_callback m_gs_seek_result_callback;
	static void* m_gs_seek_result_user_data;
	static S32 m_phandle;


	static void open_result_callback_helper(S32 ret, gs_video_info_struct *video_info,void *user_data);
	static void play_finish_callback_helper (S32 ret,void *user_data);
	static void seek_result_callback_helper (S32 ret,void *user_data);


public:
	MMVideoService(U32 handle):GS_CBase(handle){}


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

	virtual S32 CALLCC video_ply_open_file(const S8 *filename,gs_open_result_callback open_result_callback,void* user_data);
	virtual S32 CALLCC video_ply_close_file();
	virtual S32 CALLCC video_ply_play(gs_video_play_struct* pPlayStruct,gs_play_finish_callback callback,void* user_data);

	virtual S32 CALLCC video_ply_stop();
	virtual S32 CALLCC video_ply_snapshot(S32 layer_handle, PS8 file_name);
	virtual void CALLCC video_ply_get_cur_play_time(U64 *cur_play_time);
	virtual S32 CALLCC video_ply_seek_and_get_frame(int time,S32 player_layer_handle);
	virtual S32 CALLCC video_ply_non_block_seek_and_get_frame(int time,
                    S32 player_layer_handle,
                    gs_seek_result_callback seek_result_callback,
                    void *user_data);
	virtual S32 CALLCC video_ply_stop_non_block_seek();
	virtual S32 CALLCC video_ply_set_brightness(U16 brightness);
	virtual S32 CALLCC video_ply_set_contrast(U16 contrast);

	virtual S32 CALLCC video_ply_check_is_able_to_play(PS8 file_name);
	virtual BOOL CALLCC video_is_playing();

	virtual BOOL CALLCC video_is_recording(void);
	virtual S32 CALLCC video_ply_get_total_duration(const S8 *filename, U64* total_duration);
};
#endif 

