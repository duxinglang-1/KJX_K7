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
*   gs_srv_bitstreamrecord.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   BitstreamRecord implement file
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
	//#include "custom_mmi_default_value.h"
#include "gdi_datatype.h"
#include "mdi_datatype.h"
#include "mdi_bitstream.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_bitstreamrecord_impl.h"
#include "vmlog.h"

bistream_record_open_handle_result_callback BitstreamRecordService::m_result_callback = NULL;
S32 BitstreamRecordService::m_phandle = 0;

extern "C" VMINT vm_sal_query_calling(void);

GS_IBase *CreateBitstreamRecordService(U32 hd)
{
	BitstreamRecordService* service = NULL;
	GS_NEW_EX(service, BitstreamRecordService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}

BitstreamRecordService::BitstreamRecordService(U32 handle):GS_CBase(handle)
{
}

void BitstreamRecordService::bistream_record_open_handle_result_callback_helper(S32 handle, S32 result)
{
	kal_prompt_trace(MOD_IDLE,"bitstream record cb: handle = %d,result = %d",handle,result);
	if (m_result_callback == NULL )
	{
		return;
	}
	kal_prompt_trace(MOD_IDLE,"bitstream record cb 1");
	if (vm_pmng_set_ctx(m_phandle) != VM_PMNG_OP_OK)
	{
		return;
	}
	kal_prompt_trace(MOD_IDLE,"bitstream record cb 2");
	m_result_callback(handle, result);
	kal_prompt_trace(MOD_IDLE,"bitstream record cb 3");
	vm_pmng_reset_ctx();
	kal_prompt_trace(MOD_IDLE,"bitstream record cb 4");
}

S32 CALLCC BitstreamRecordService::queryInterface(S32 iid, GS_IBase **pptr)
{
	/* Please notes: pptr may be a proxy, your call should not use it directly. */
	if (pptr == NULL)
		return 0;
	if (iid == IID_IBITSTREAMRECORD)
	{
		addRef();
		*pptr = BIND_PROXY(IBitstreamRecord,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}



S32 CALLCC BitstreamRecordService::gs_bitstream_record_open(S32* handle_p,gs_bitstream_record_cfg_struct* cfg_p,bistream_record_open_handle_result_callback callback)
{
	S32 ret = -500;
	
	if (vm_sal_query_calling() == TRUE)
		return MDI_RES_STREAM_REC_ERR_FAILED;
	
	m_phandle = vm_pmng_get_current_handle();
	m_result_callback = callback;
    if(cfg_p)
    {	
        if(GS_BITSTREAM_CODEC_TYPE_SILENT == cfg_p->codec_type)
        {
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_SILENT;
        }
		else if(GS_BITSTREAM_CODEC_TYPE_AMR == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_AMR;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_AMRWB == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_AMRWB;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_AAC == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_AAC;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_DAF == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_DAF;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_MP4A == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_MP4A;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_MP4AG == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_MP4AG;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_WAV == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_WAV;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_ADPCM == cfg_p->codec_type)
		{
        	cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_ADPCM;
		}
		else if(GS_BITSTREAM_CODEC_TYPE_PCM == cfg_p->codec_type)
		{
			cfg_p->codec_type = MDI_BITSTREAM_CODEC_TYPE_PCM;
		}
		else
		{
			return ret;
		}



		if(GS_BITSTREAM_RECORD_QUALITY_LOW == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_LOW;
		}
		else if(GS_BITSTREAM_RECORD_QUALITY_MED == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_MED;
		}
		else if(GS_BITSTREAM_RECORD_QUALITY_HIGH == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_HIGH;
		}
		else if(GS_BITSTREAM_RECORD_QUALITY_BEST == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_QUALITY_BEST;
		}
		else if(GS_BITSTREAM_RECORD_AMR_4_75 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_4_75;
		}
		else if(GS_BITSTREAM_RECORD_AMR_5_15 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_5_15;
		}
		else if(GS_BITSTREAM_RECORD_AMR_5_9 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_5_9;
		}
		else if(GS_BITSTREAM_RECORD_AMR_6_7 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_6_7;
		}
		else if(GS_BITSTREAM_RECORD_AMR_7_4 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_7_4;
		}	
		else if(GS_BITSTREAM_RECORD_AMR_7_95 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_7_95;
		}
		else if(GS_BITSTREAM_RECORD_AMR_10_2 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_10_2;
		}
		else if(GS_BITSTREAM_RECORD_AMR_12_2 == cfg_p->quality )
		{
			cfg_p->quality = MDI_BITSTREAM_RECORD_AMR_12_2;
		}
		else
		{
			return ret;
		}

	    kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_open type=%d,quality=%d",cfg_p->codec_type,cfg_p->quality);

	    ret = mdi_bitstream_record_open(handle_p,(mdi_bitstream_record_cfg_struct*)cfg_p,bistream_record_open_handle_result_callback_helper);
	    kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_open ret = %d",ret);
    }
    return ret;
}

S32 CALLCC BitstreamRecordService::gs_bitstream_record_close(S32 handle)
{
	S32 ret = mdi_bitstream_record_close( handle);
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_close ret = %d",ret);
	return ret;
}

S32 CALLCC BitstreamRecordService::gs_bitstream_record_start(S32 handle)
{
	S32 ret;
	if (vm_sal_query_calling() == TRUE)
		return MDI_RES_STREAM_REC_ERR_FAILED;
	ret	=  mdi_bitstream_record_start( handle);
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_start ret = %d",ret);
	return ret;
}

S32 CALLCC BitstreamRecordService::gs_bitstream_record_stop(S32 handle)
{
	S32 ret =  mdi_bitstream_record_stop(handle);
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_stop ret = %d",ret);
	return ret;
}

S32 CALLCC BitstreamRecordService::gs_bitstream_record_get(S32 handle,gs_bitstream_record_get_type_enum get_type,void* data_p,U16* data_len_p)
{
    mdi_bitstream_record_get_type_enum mdi_get_type;
	if(get_type ==GS_BITSTREAM_RECORD_GET_LENGTH )
	{
		mdi_get_type = MDI_BITSTREAM_RECORD_GET_LENGTH;
	}
	else if(get_type ==GS_BITSTREAM_RECORD_GET_DATA )
	{
		mdi_get_type = MDI_BITSTREAM_RECORD_GET_DATA;
	}
	else if(get_type == GS_BITSTREAM_RECORD_GET_STRENGTH)
	{
		mdi_get_type = MDI_BITSTREAM_RECORD_GET_STRENGTH;
	}
	else
	{
		return -500;
	}
	
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_get get_type = %d",get_type);
	S32 ret =  mdi_bitstream_record_get( handle, mdi_get_type,data_p, data_len_p);
	if(get_type ==MDI_BITSTREAM_RECORD_GET_LENGTH )
	{
		U16* r1 = (U16*)data_p;
		U16 r2 = (U16)*data_len_p;
		kal_prompt_trace(MOD_IDLE,"record_get_len:data_p = %d",*r1);
		kal_prompt_trace(MOD_IDLE,"record_get_len:data_len_p = %d",r2);

	}
	if(get_type ==MDI_BITSTREAM_RECORD_GET_DATA)
	{
		U16* r1 = (U16*)data_p;
		U16 r2 = (U16)*data_len_p;
		kal_prompt_trace(MOD_IDLE,"record_get_DATA:data_p = %d",*r1);
		kal_prompt_trace(MOD_IDLE,"record_get_DATA:data_len_p = %d",r2);
	}
	if(get_type ==MDI_BITSTREAM_RECORD_GET_STRENGTH)
	{
		U32* r1 = (U32*)data_p;
		U16 r2 = (U16)*data_len_p;
		kal_prompt_trace(MOD_IDLE,"record_get_strength:data_p = %d",*r1);
		kal_prompt_trace(MOD_IDLE,"record_get_strength:data_len_p = %d",r2);
	}
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_get ret = %d",ret);
	return ret;
} 

S32 CALLCC BitstreamRecordService::gs_bitstream_record_set(S32 handle,gs_bitstream_record_set_type_enum set_type,void* data_p,U16 data_len)
{
    mdi_bitstream_record_set_type_enum mdi_set_type;
	if(GS_BITSTREAM_RECORD_SET_PAUSE ==set_type )
	{
		mdi_set_type =MDI_BITSTREAM_RECORD_SET_PAUSE;
	}
	else if(GS_BITSTREAM_RECORD_SET_RESUME == set_type)
	{
		mdi_set_type =MDI_BITSTREAM_RECORD_SET_RESUME;
	}
	else if(GS_BITSTREAM_RECORD_SET_CB_THRESHOLD ==set_type)
	{
		mdi_set_type =MDI_BITSTREAM_RECORD_SET_CB_THRESHOLD;
	}
	else
	{
		return -500;
	}
	
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_set TYPE = %d",mdi_set_type);
	S32 ret =  mdi_bitstream_record_set( handle, mdi_set_type, data_p, data_len);
	kal_prompt_trace(MOD_IDLE,"mdi_bitstream_record_set ret = %d",ret);
	return ret;
}
#endif
