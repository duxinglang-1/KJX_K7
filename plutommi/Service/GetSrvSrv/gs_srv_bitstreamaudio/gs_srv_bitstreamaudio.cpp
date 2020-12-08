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
*   gs_srv_bitstreamaudio.cpp  
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IBitstreamAudio implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#if defined(__BITSTREAM_API_SUPPORT__)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "gdi_datatype.h"
#include "mdi_datatype.h"
#include "mdi_bitstream.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_bitstreamaudio_impl.h"
#include "vmlog.h"

bistream_audio_open_handle_result_callback BitstreamAudioService::m_result_callback = NULL;
S32 BitstreamAudioService::m_phandle = 0;

GS_IBase *CreateBitstreamAudioService(U32 hd)
{
	BitstreamAudioService* service = NULL;
	GS_NEW_EX(service, BitstreamAudioService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}

BitstreamAudioService::BitstreamAudioService(U32 handle):GS_CBase(handle)
{

}


void BitstreamAudioService::bistream_audio_open_handle_result_callback_helper(S32 handle, S32 result)
{
	if (m_result_callback == NULL )
	{
		return;
	}
	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}
	m_result_callback(handle, result);
	vm_pmng_reset_ctx();
}

S32 CALLCC BitstreamAudioService::queryInterface(S32 iid, GS_IBase **pptr)
{
	/* Please notes: pptr may be a proxy, your call should not use it directly. */
	if (pptr == NULL)
		return 0;
	if (iid == IID_IBITSTREAMAUDIO)
	{
		addRef();
		*pptr = BIND_PROXY(IBitstreamAudio,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}

S32 CALLCC BitstreamAudioService::gs_bitstream_audio_open_handle(S32* p_handle, gs_bitstream_audio_cfg_struct* p_cfg,bistream_audio_open_handle_result_callback result_callback )
{
	m_phandle = vm_pmng_get_current_handle();
	m_result_callback = result_callback;
	return mdi_bitstream_audio_open_handle(p_handle, (mdi_bitstream_audio_cfg_struct*)p_cfg, bistream_audio_open_handle_result_callback_helper);

}
S32 CALLCC BitstreamAudioService::gs_bitstream_audio_close(S32 handle)
{
	return mdi_bitstream_audio_close(handle);
}
S32 CALLCC BitstreamAudioService::gs_bitstream_audio_get_buffer_status(S32 handle, gs_bitstream_audio_buffer_status* p_status)
{
	return mdi_bitstream_audio_get_buffer_status(handle,  (mdi_bitstream_audio_buffer_status *)p_status);
}

S32 CALLCC BitstreamAudioService::gs_bitstream_audio_put_data(S32 handle, U8* p_buffer, U32 buffer_size, U32* p_used_size)
{
	return  mdi_bitstream_audio_put_data(handle, p_buffer, buffer_size, p_used_size);
}

S32 CALLCC BitstreamAudioService::gs_bitstream_audio_put_frame(S32 handle, U8* p_buffer, U32 buffer_size, U32 timestamp)
{
	return mdi_bitstream_audio_put_frame( handle, p_buffer, buffer_size, timestamp);
}

S32 CALLCC BitstreamAudioService::gs_bitstream_audio_start(S32 handle, gs_bitstream_audio_start_param* p_para)
{
	return mdi_bitstream_audio_start( handle, (mdi_bitstream_audio_start_param *)p_para);
}

S32 CALLCC BitstreamAudioService::gs_bitstream_audio_stop(S32 handle)
{
	return mdi_bitstream_audio_stop(handle);
}

S32 CALLCC BitstreamAudioService::gs_bitstream_audio_get_play_time(S32 handle, U32* p_ms_current_time)
{
	return mdi_bitstream_audio_get_play_time(handle,  p_ms_current_time);
}

U16 CALLCC BitstreamAudioService::gs_bitstream_audio_get_open_handle_count()
{
	return mdi_bitstream_audio_get_open_handle_count();
}
#endif
