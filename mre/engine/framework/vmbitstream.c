#include "vmswitch.h"
#include "mmi_features.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_bitstream.h"

#include "vmlog.h"
#include "vmsys.h"
#include "vmgraph.h"
#include "vmsalbitstream.h"
#include "vmbitstream.h"
#include "vmmod.h"
#include "vmmm.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmpromnginner.h"
#include "MMI_trc.h"
#include "vmmacrostub.h"
#include "vmsalmm.h"

#ifdef __MRE_SAL_BITSTREAM__

#define VM_INVALID_HANDLE  (-1)
#define REG_BITSTREAM_MODULE_FAILED	(-2)


VMINT bitstream_start = FALSE;
VMINT bitstream_handle = NULL;
VMINT bitstream_res_handle = VM_INVALID_HANDLE;
static VM_P_HANDLE bitstream_interrupt_handle = NULL;

static vm_bitstream_audio_result_callback bitstream_interrupt_cb = NULL;

extern VMINT mre_running;

extern VMINT vm_audio_get_used_res_type(VM_P_HANDLE *used_handle);

extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);

static void vm_release_bitstream_audio_resource(void)
{
	if (bitstream_handle != NULL)
	{
		vm_bitstream_audio_close(bitstream_handle);
		bitstream_handle = NULL;
		bitstream_interrupt_handle = NULL;
		bitstream_interrupt_cb = NULL;
	}
}

void vm_bitstream_audio_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
		break;
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
		vm_release_bitstream_audio_resource();
		break;
	}
}

static VMINT vm_bitstream_audio_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		bitstream_handle = NULL;
		bitstream_start = FALSE;
		bitstream_interrupt_handle = NULL;
		bitstream_interrupt_cb = NULL;
		vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_BIT_HANDLE, vm_bitstream_audio_notify_callback);
		break;
	case EVT_MOD_ACTIVE:		
		break;
	case EVT_MOD_INACTIVE:
		break;
	case EVT_MOD_RELEASE:
		vm_release_bitstream_audio_resource();
		vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_BIT_HANDLE, NULL);
		break;
	default:
		return REG_BITSTREAM_MODULE_FAILED;
	}

	return REG_MRE_MODULE_SUCCESS;
}

VMINT _vm_reg_bitsteam_audio_module(void)
{
	int res = REG_MRE_MODULE_SUCCESS;
	
	if ((res = _vm_reg_module("BITSTREAM AUDIO MODULE", (MOD_EVT_PROCESS)vm_bitstream_audio_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_BITSTREAM_AUDIO_REG_FAIL,res);
	}

	return res;
}

VMINT vm_bitstream_audio_preprocess_play(void)
{
	VMINT audio_type;
	VM_P_HANDLE use_audio_handle;
	int result = FALSE;	
	VM_P_HANDLE current_handle = vm_pmng_get_current_handle();

	if (vm_sal_query_calling() == TRUE)
		return result;

	audio_type = vm_audio_get_used_res_type(&use_audio_handle);

	switch(audio_type)
	{
	case NULL:
		vm_audio_suspend_bg_play();
		result = TRUE;
		break;
	case VM_RES_TYPE_AUDIO_HANDLE:
		vm_audio_stop(NULL);	
		result = TRUE;
		break;
	case VM_RES_TYPE_MIDI_HANDLE:
		vm_midi_stop_all();
		result = TRUE;
		break;
#if ( defined(__MRE_SAL_VIDEO__)) 
	case VM_RES_TYPE_VIDEO_HANDLE:
#endif
#if ( defined(__MRE_SAL_BITSTREAM__)) 
	case VM_RES_TYPE_AUDIO_BIT_HANDLE:
#endif
	case VM_RES_TYPE_RECORD_HANDLE:
		result = FALSE;
		break;
	}
	return result;
}

void vm_bitstream_audio_callback(VMINT handle, VMINT result) 
{
	VM_P_HANDLE use_bitstream_handle;
	vm_bitstream_audio_result_callback cb;

	if (mre_running == FALSE)
		return;

	vm_res_get_callback(VM_RES_TYPE_AUDIO_BIT_HANDLE, bitstream_res_handle, (void**)&cb);

	if (cb != NULL)
	{
		use_bitstream_handle = vm_res_get_process_handle(VM_RES_TYPE_AUDIO_BIT_HANDLE, bitstream_res_handle);
		if (vm_pmng_set_ctx(use_bitstream_handle) == VM_PMNG_OP_OK)
		{
			cb(handle, result);
			vm_pmng_reset_ctx();
		}
	}
}


VMINT vm_bitstream_audio_open(
	VMINT* handle,
	vm_bitstream_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback)
{
	vm_bitstream_pcm_audio_cfg_struct audio_cfg;

	memset(&audio_cfg, 0, sizeof(vm_bitstream_pcm_audio_cfg_struct));
	audio_cfg.vm_codec_type = audio_type->vm_codec_type;
	return vm_bitstream_audio_open_pcm(handle, &audio_cfg, callback);
}


VMINT vm_bitstream_audio_open_pcm(
	VMINT* handle,
	vm_bitstream_pcm_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback)
{
	VMINT result = VM_BITSTREAM_FAILED;
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

	if ((audio_type == NULL) || (vm_bitstream_audio_preprocess_play() == FALSE))
		return result;
	
	if ((bitstream_res_handle = vm_res_save_data(VM_RES_TYPE_AUDIO_BIT_HANDLE, NULL, 0, (void*)callback, process_handle))>= 0)
	{
		mdi_bitstream_audio_cfg_struct cfg;
		
		cfg.codec_type = (mdi_bitstream_codec_type_enum)audio_type->vm_codec_type;
		cfg.isStereo = (MMI_BOOL)audio_type->isStereo;
		cfg.bitPerSample = audio_type->bitPerSample;
		cfg.sampleFreq = (mdi_bitstream_sample_freq_enum)audio_type->sampleFreq;

		result = mdi_bitstream_audio_open_handle(handle, &cfg, vm_bitstream_audio_callback);


		if (result == VM_BITSTREAM_SUCCEED)
		{
			bitstream_handle = *handle;
			vm_res_set_callback(VM_RES_TYPE_AUDIO_BIT_HANDLE, bitstream_res_handle, (void*)callback);
		}
		else
		{
			vm_res_release_data(VM_RES_TYPE_AUDIO_BIT_HANDLE, bitstream_res_handle);
			bitstream_res_handle = VM_INVALID_HANDLE;
		}
	}

	return result;
}

VMINT vm_bitstream_audio_finished(VMINT handle)
{
	return mdi_bitstream_audio_finished(handle);
}

VMINT vm_bitstream_audio_close(VMINT handle)
{
	VMINT result = VM_BITSTREAM_FAILED;

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_BIT_HANDLE) > 0)
	{
		if (bitstream_start == TRUE)
		{
			mdi_bitstream_audio_stop(handle);
			bitstream_start = FALSE;
		}	
	
		result = mdi_bitstream_audio_close(handle);
		if (result == VM_BITSTREAM_SUCCEED)
		{
			vm_res_release_data(VM_RES_TYPE_AUDIO_BIT_HANDLE, bitstream_res_handle);
			bitstream_res_handle = VM_INVALID_HANDLE;
			bitstream_handle = NULL;
			vm_audio_resume_bg_play();
		}
	}
	return result;
}

VMINT vm_bitstream_audio_get_buffer_status(
	VMINT handle, 
	vm_bitstream_audio_buffer_status *status)
{
	VMINT result = VM_BITSTREAM_FAILED;

	if (bitstream_res_handle != VM_INVALID_HANDLE) 
	{
		result = mdi_bitstream_audio_get_buffer_status(handle, (mdi_bitstream_audio_buffer_status*)status);
	}

	return result;
}

VMINT vm_bitstream_audio_put_data(
	VMINT 		handle,
	VMUINT8* 	buffer,
	VMUINT 		buffer_size,
	VMUINT*		written)
{
	VMINT result = VM_BITSTREAM_FAILED;

	if ((bitstream_handle == handle) && (bitstream_res_handle != VM_INVALID_HANDLE) && (buffer != NULL) && (buffer_size != 0))
		result = mdi_bitstream_audio_put_data(handle, buffer, buffer_size, written);

	return result;
}

 VMINT vm_bitstream_audio_put_frame(
	VMINT 		handle,
	VMUINT8*	buffer,
	VMUINT		buffer_size,
	VMUINT 		timestamp)
{
	return VM_BITSTREAM_FAILED;
}

VMINT vm_bitstream_audio_start(
	VMINT handle,
	vm_bitstream_audio_start_param *para)
{
	VMINT result = VM_BITSTREAM_FAILED;
    VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
    _vm_pcb_t* pcb = NULL;
    VMINT iscosmos = 0;

	if (bitstream_start == TRUE || para == NULL)
		return result;

#ifdef __COSMOS_MMI_PACKAGE__
    iscosmos = 1;
#endif	
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, pHandle, NULL)) != NULL)
    {
        if(iscosmos == 0 || pcb->volume_type == 0)
        {
            if (para->volume < MDI_AUD_VOL_NUM + 1 )
            {
                para->volume = (VMUINT8)MDI_AUD_VOL_MUTE(para->volume);
            }
        }
#ifdef __COSMOS_MMI_PACKAGE__
        else
        {           
            if (para->volume < 17 )
            {
                para->volume = (VMUINT8)MDI_AUD_VOL_EX_MUTE(para->volume);
            }           
        }
#endif
    }

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_BIT_HANDLE) > 0)
	{
		result = mdi_bitstream_audio_start(handle, (mdi_bitstream_audio_start_param*)para);
		if (result == VM_BITSTREAM_SUCCEED)
			bitstream_start = TRUE;
	}

	return result;
}

VMINT vm_bitstream_audio_stop(VMINT handle)
{
	VMINT result = VM_BITSTREAM_FAILED;

	if (bitstream_start == FALSE)
		return result;
	
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_BIT_HANDLE) > 0)
	{
		result = mdi_bitstream_audio_stop(handle);
		if (result == VM_BITSTREAM_SUCCEED)
			bitstream_start = FALSE;
	}

	return result;
}

VMINT vm_bitstream_audio_get_play_time(
	VMINT handle,
	VMUINT* current_time)
{
	VMINT result = VM_BITSTREAM_FAILED;

	if ((bitstream_handle == handle) && (current_time != NULL))
		result = mdi_bitstream_audio_get_play_time(handle, current_time);

	return result;
}



static void vm_bitstream_interrupt_callback(VMINT result, void *user_data)
{
	if(bitstream_interrupt_cb == NULL || bitstream_interrupt_handle == NULL)
		return;
	
	if(result == MDI_AUDIO_TERMINATED )	
	{
		if (vm_pmng_set_ctx(bitstream_interrupt_handle) == VM_PMNG_OP_OK)
		{
			bitstream_interrupt_cb((VMINT)user_data, VM_BITSTREAM_INTERRUPT);
			vm_pmng_reset_ctx();
		}
	}
}

static VMINT vm_bitstream_background_callback(VMINT result, void *user_data)
{

	if(bitstream_interrupt_cb == NULL || bitstream_interrupt_handle == NULL)
		return TRUE;
	
	if(result == MDI_AUDIO_TERMINATED)	
	{
		if (vm_pmng_set_ctx(bitstream_interrupt_handle) == VM_PMNG_OP_OK)
		{
			bitstream_interrupt_cb((VMINT)user_data, VM_BITSTREAM_INTERRUPT);
			vm_pmng_reset_ctx();
		}
	}
	else
	{
		if (vm_pmng_set_ctx(bitstream_interrupt_handle) == VM_PMNG_OP_OK)
		{
			bitstream_interrupt_cb((VMINT)user_data, VM_BITSTREAM_INTERRUPT_RESUME);
			vm_pmng_reset_ctx();
		}
	}
	return TRUE;
}

VMINT vm_bitstream_audio_register_interrupt_callback(vm_bitstream_audio_result_callback callback)
{
	bitstream_interrupt_handle = vm_pmng_get_current_handle();
	bitstream_interrupt_cb = callback;
	mdi_audio_clear_interrupt_callback();
	mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MRE, (mdi_bg_callback)vm_bitstream_background_callback, (void*)NULL);	
	mdi_audio_register_interrupt_callback((mdi_ext_callback)vm_bitstream_interrupt_callback, (void*)NULL);
	return bitstream_interrupt_handle;
}


void vm_bitstream_audio_clear_interrupt_callback(VMINT handle)
{
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	
	if(handle == pHandle)
	{
		bitstream_interrupt_cb = NULL;
		bitstream_interrupt_handle = NULL;
		mdi_audio_clear_interrupt_callback();
		mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MRE);
	}
}

VMINT vm_get_bitstream_sym(VMCHAR* func_name)
{
	return 0;
}

#endif
