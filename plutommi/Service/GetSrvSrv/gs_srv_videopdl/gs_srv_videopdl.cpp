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
*   gs_srv_videopdl.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IVideoPDL implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VIDEO_PDL__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
	//#include "custom_mmi_default_value.h"
#include "mdi_video.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_videopdl_impl.h"
#include "vmlog.h"

gs_progressive_result_callback VideoPDLService::m_result_callback = NULL;
S32 VideoPDLService::m_phandle = 0;
void* VideoPDLService::m_user_data = NULL;

GS_IBase *CreateVideoPDLService(U32 hd)
{
	VideoPDLService* service = NULL;
	GS_NEW_EX(service, VideoPDLService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}

VideoPDLService::VideoPDLService(U32 handle):GS_CBase(handle){}


void VideoPDLService::gs_progressive_result_callback_helper (S32 ret , gs_video_info_struct* video_info,void *user_data)
	{
		if (m_result_callback == NULL )
		{
			return;
		}
		if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
		{
			return;
		}
		m_result_callback(ret, video_info,m_user_data);
		vm_pmng_reset_ctx();
	}

S32 CALLCC VideoPDLService::queryInterface(S32 iid, GS_IBase **pptr)
{
	if (pptr == NULL)
		return 0;
	if (iid == IID_IVIDEOPDL)
	{
		addRef();
		*pptr = BIND_PROXY(IVideoPDL,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}


S32 CALLCC VideoPDLService::gs_video_progressive_open_file(const S8 *filename,gs_progressive_result_callback progressive_result_callback,void* user_data)
{
	m_phandle = vm_pmng_get_current_handle();
	m_result_callback = progressive_result_callback;
	m_user_data = user_data;
	return mdi_video_progressive_open_file(ASM_ANONYMOUS_ID,filename,(mdi_progressive_result_callback)gs_progressive_result_callback_helper,m_user_data);
}


S32 CALLCC VideoPDLService::gs_video_progressive_close_file()
{
	return mdi_video_progressive_close_file();
}


S32 CALLCC VideoPDLService::gs_video_progressive_get_max_play_time(U64 *max_play_time)
{
	return mdi_video_progressive_get_max_play_time(max_play_time);
}


S32 CALLCC VideoPDLService::gs_video_progressive_get_buf_percentage(S32 *buf_percentage)
{
	return mdi_video_progressive_get_buf_percentage(buf_percentage);
}


S32 CALLCC VideoPDLService::gs_video_progressive_is_pdl_format(U8 *file_buf, S32 buf_size, MMI_BOOL *is_pdl)
{
	return mdi_video_progressive_is_pdl_format(file_buf,  buf_size, is_pdl);

}
#endif
