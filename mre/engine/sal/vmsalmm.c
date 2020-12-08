#include "vmswitch.h"
#ifdef __MRE_SAL_AUDIO__

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "UcmSrvGprot.h"
#include "gpiosrvgprot.h"
#include "vmsys.h"
#include "vmsalmm.h"
#include "vmdl.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmmacrostub.h"
#include "mmi_frm_input_gprot.h"
#include "vmmm.h"
#include "device.h"
#include "string.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_led_patterns.h"
#include "vmtimer.h"
#include "gpiosrvgprot.h"
#include "DevConfigGprot.h"
#include "MMI_trc.h"
#include "vmfilere.h"


#define VM_FILE_EXT_AMR (L".amr")
#define VM_FILE_EXT_WAV (L".wav")

typedef enum
{
   VM_RECORD_STATE_IDLE,
   VM_RECORD_STATE_RECORD,
   VM_RECORD_STATE_RECORD_PAUSED,
   VM_RECORD_NO_OF_STATE
} vm_recorder_state_enum;

extern VMINT mre_running;

#define INIT_VALUE		(-1)

extern VMINT record_res_handle;

static void vm_record_callback(VMINT result, void *user_data);

extern mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void);
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);
extern VMINT vm_get_res_header(void);
extern VMINT vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);
extern VMINT vm_ucs2_to_default(VMSTR dst, VMINT size, VMWSTR src);
extern VMINT _vm_remap_usr_disk(VMWSTR dest_filename, VMWSTR source_filename);
extern VMINT _vm_get_disk_permission(void);
extern VMINT vm_audio_preprocess_play(VMINT type);

void vm_vibrator_once(void)
{
	static VMINT g_vibrator_time = 0;
	VMINT current_time = vm_get_tick_count();
	
	if (current_time - g_vibrator_time > 1000)
	{
		g_vibrator_time = current_time;
		srv_vibrator_play_once();
	}
}


void vm_vibrator_on(void)
{
	srv_gpio_set_device_level(SRV_GPIO_DEV_VIBRATOR,SRV_GPIO_DEV_LEVEL1);
}

void vm_vibrator_off(void)
{
	srv_gpio_set_device_level(SRV_GPIO_DEV_VIBRATOR,SRV_GPIO_DEV_LEVEL0);
}


void vm_set_key_tone_on(void)
{
	if (vm_pmng_is_fg(vm_pmng_get_current_handle()))
		mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
}

void vm_set_key_tone_off(void)
{
	if (vm_pmng_is_fg(vm_pmng_get_current_handle()))
		mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
}

vm_kbd_tone_state_enum vm_get_key_tone_state(void)
{
	vm_kbd_tone_state_enum retval = VM_KEY_TONE_INVALID;
	
	switch(mmi_frm_kbd_get_key_tone_state())
	{
	case MMI_KEY_TONE_ENABLED:
		retval = VM_KEY_TONE_ENABLED;
		break;
	case MMI_KEY_VOL_TONE_DISABLED:
		retval = VM_KEY_VOL_TONE_DISABLED;
		break;
	case MMI_KEY_VOL_UP_DOWN_TONE_DISABLED:
		retval = VM_KEY_VOL_UP_DOWN_TONE_DISABLED;
		break;
	case MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED:
		retval = VM_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED;
		break;
	case MMI_KEY_TONE_DISABLED:
		retval = VM_KEY_TONE_DISABLED;
		break;
	default :
		retval = VM_KEY_TONE_INVALID;
		break;
	}

	return retval;
}

VMINT vm_set_key_tone_state(vm_kbd_tone_state_enum key_tone_state)
{
	if (vm_pmng_is_fg(vm_pmng_get_current_handle()))
	{
		mmi_frm_kbd_tone_state_enum setval = MMI_KEY_TONE_INVALID;

		if ((int)key_tone_state > VM_KEY_TONE_INVALID || (int)key_tone_state < VM_KEY_TONE_ENABLED)
		{
			return FALSE;
		}
		
		switch(key_tone_state)
	{
	case VM_KEY_TONE_ENABLED:
		setval = MMI_KEY_TONE_ENABLED;
		break;
	case VM_KEY_VOL_TONE_DISABLED:
		setval = MMI_KEY_VOL_TONE_DISABLED;
		break;
	case VM_KEY_VOL_UP_DOWN_TONE_DISABLED:
		setval = MMI_KEY_VOL_UP_DOWN_TONE_DISABLED;
		break;
	case VM_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED:
		setval = MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED;
		break;
	case VM_KEY_TONE_DISABLED:
		setval = MMI_KEY_TONE_DISABLED;
		break;
	default :
		setval = MMI_KEY_TONE_INVALID;
		break;
	}

		mmi_frm_kbd_set_tone_state((mmi_frm_kbd_tone_state_enum)setval);
		return TRUE;
	}

	return FALSE;
}

VMINT vm_sal_query_calling(void)
{
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
		return TRUE;
	else
		return FALSE;
}


VMINT vm_audio_is_vpp_file(void)
{
	return vm_get_res_header()> 0 ? TRUE : FALSE;
}

VMINT vm_audio_is_calling(void)
{
	return vm_sal_query_calling();
}

static void vm_release_recode_resource(void)
{
	vm_res_release_data(VM_RES_TYPE_RECORD_HANDLE, record_res_handle);
	record_res_handle = INIT_VALUE;
}

static void vm_record_callback(VMINT result, void *user_data)
{
	if (mre_running == FALSE)
		return;

	if (result == MDI_AUDIO_TERMINATED 
		|| result == MDI_AUDIO_END_OF_FILE
		|| result == MDI_AUDIO_DISC_FULL
		|| result == MDI_AUDIO_NO_SPACE)
	{
		vm_recorder_callback vm_record_cb;
		VM_P_HANDLE res_handle;
		
		res_handle = vm_res_get_process_handle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle);
		vm_res_get_callback(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, (void**)&vm_record_cb);
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_EVENT_RESP_CALLBACK_ADDR,vm_record_cb);
		
		if (vm_record_cb != NULL)
		{
			PMNG_WRAP_CALLBACK(res_handle, vm_record_cb(result));
		}
		
	}
}



VMINT vm_record_preprocess(void)
{
	if (!vm_pmng_is_fg(vm_pmng_get_current_handle()))
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_CUR_PRO_BG);
		return VM_RECORD_FAILED;
	}

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_RECORD_HANDLE) < 0)
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_RESOURCE_NOT_ENOUGH);
		return VM_RECORD_FAILED;
	}

	return VM_RECORD_SUCCEED;	
}

VMINT vm_record_start(VMSTR drv_name, VMSTR dir_name, VMSTR rec_name, VMUINT8 format, VMWSTR full_rec_file_wname, vm_recorder_callback vm_record_cb)
{
	VMWCHAR * full_temp_wname = NULL;
	VMCHAR usr_drv_name[DRV_NAME_LEN];
	VMWCHAR * app_wpath = NULL;
	VMCHAR * temp_fn = NULL;
	VMCHAR * full_file_name = NULL;
	VMWCHAR * full_file_wname = NULL;
	VMWCHAR drv_wname[DRV_NAME_LEN];
	VMINT returnval = VM_RECORD_FAILED;
	VMINT result ;
	VMUINT8 file_format = MDI_FORMAT_AMR;
	
	if (drv_name == NULL || dir_name == NULL || rec_name == NULL)
	{
		return VM_RECORD_FAILED;
	}
	
	if (strlen(rec_name) < 1 
		|| strlen(rec_name) >= REC_NAME_LEN 
		|| strlen(drv_name) != 1 
		|| strlen(dir_name) > DIR_NAME_LEN
	)
	{
		return VM_RECORD_FAILED;
	}
	
	if ((drv_name[0] > 'a'  && drv_name[0]  < 'z' )||(drv_name[0] > 'A'  && drv_name[0]  < 'Z' ))
	{
		;
	}
	else
	{
		return VM_RECORD_FAILED;
	}

	if (vm_sal_query_calling() == TRUE || !vm_pmng_is_fg(vm_pmng_get_current_handle()) || vm_audio_preprocess_play(VM_RES_TYPE_AUDIO_HANDLE) == FALSE)
		return VM_RECORD_FAILED;
	
	record_res_handle =  vm_res_save_data(VM_RES_TYPE_RECORD_HANDLE, NULL, 0, (void*)vm_record_cb, vm_pmng_get_current_handle());
	
	if (record_res_handle <= INIT_VALUE)
		return VM_RECORD_FAILED;

	if (_vm_get_disk_permission() == VM_PERMISSION_SYS_DRV)
	{
		vm_default_to_ucs2(drv_wname, DRV_NAME_LEN, drv_name);
		if (vm_get_disk_free_space(drv_wname) < 1)
			return VM_RECORD_FAILED; 
	}
	else
	{
		if ((temp_fn = vm_calloc(MAX_NAME_LEN))== NULL)
		{
			MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_START_MALLOC_TEMP_FN_FAIL);
			return VM_RECORD_FAILED;
		}
		if ((app_wpath = vm_calloc(MAX_WNAME_LEN)) == NULL)
		{
			MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_START_MALLOC_WPATH_FAIL);
			vm_free(temp_fn);
			return VM_RECORD_FAILED;
		}
		
		if ((vm_get_exec_filename((VMWSTR)app_wpath)) != 0)
		{
			MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_START_EXEC_FILE_FAIL);
			vm_free(temp_fn);
			vm_free(app_wpath);
			return VM_RECORD_FAILED;
		}
		vm_ucs2_to_default((VMSTR)temp_fn, MAX_NAME_LEN, (VMWSTR)app_wpath);
		memset(usr_drv_name, 0x00, DRV_NAME_LEN);
		sprintf(usr_drv_name, "%c", (VMCHAR)temp_fn[0]);

		vm_free(temp_fn);
		vm_free(app_wpath);
		
		vm_default_to_ucs2(drv_wname, DRV_NAME_LEN, usr_drv_name);
		if (vm_get_disk_free_space(drv_wname) < 1)
		{
			return VM_RECORD_FAILED; 
		}	
	}

	full_temp_wname = vm_calloc(MAX_WNAME_LEN);
	if (full_temp_wname == NULL)
	{
		vm_free(full_file_name);
		return VM_RECORD_FAILED;
	}

	full_file_name = vm_calloc(MAX_NAME_LEN);
	if (full_file_name == NULL)
	{
		return VM_RECORD_FAILED;
	}

	full_file_wname = vm_calloc(MAX_WNAME_LEN);
	if (full_file_wname == NULL)
	{
		vm_free(full_file_name);
		vm_free(full_temp_wname);
		return VM_RECORD_FAILED;
	}
	if (strlen(dir_name) < 1)
	{
		sprintf(full_file_name, "%s:\\%s", drv_name, rec_name);
	}
	else if(strlen(dir_name) <= DIR_NAME_LEN)
	{
		sprintf(full_file_name, "%s:\\%s", drv_name, dir_name);

		vm_default_to_ucs2(full_temp_wname, MAX_WNAME_LEN, full_file_name);	
		_vm_remap_usr_disk((VMWSTR)full_file_wname, (VMWSTR)full_temp_wname);		

		vm_file_mkdir(full_file_wname);

		memset(full_file_name, 0x00, MAX_NAME_LEN);
		sprintf(full_file_name, "%s:\\%s\\%s", drv_name, dir_name, rec_name);

	}
	else
	{
		return VM_RECORD_FAILED;
	}

	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_START_FULL_FILE_NAME,full_file_name);
	
	memset(full_file_wname, 0x00, MAX_WNAME_LEN);
	memset(full_temp_wname, 0x00, MAX_WNAME_LEN);
	
	vm_default_to_ucs2(full_temp_wname, MAX_WNAME_LEN, full_file_name);	

	switch(format)
	{
	case VM_FORMAT_AMR:
		file_format = MDI_FORMAT_AMR;
		vm_wstrcat(full_temp_wname, (VMWSTR)VM_FILE_EXT_AMR);
		break;
	case VM_FORMAT_WAV:
		file_format = MDI_FORMAT_WAV_DVI_ADPCM;
		vm_wstrcat(full_temp_wname, (VMWSTR)VM_FORMAT_WAV);
		break;
	}
	_vm_remap_usr_disk((VMWSTR)full_file_wname, (VMWSTR)full_temp_wname);
	
	if(full_rec_file_wname != NULL)
	{
		vm_wstrcat(full_rec_file_wname, full_file_wname);
	}
		
		
	vm_file_delete(full_file_wname);
	

	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_SAL_START,file_format);

	result = mdi_audio_start_record_with_limit(full_file_wname, file_format, 0, vm_record_callback, NULL, 0, 0);

    if (result == VM_AUDIO_SUCCEED)
    {
   	    vm_res_set_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, VM_RECORD_STATE_RECORD);
  		returnval = VM_RECORD_SUCCEED;
    }
    else
    {
	    vm_release_recode_resource();
  		returnval = VM_RECORD_FAILED;
    }
	
	vm_free(full_file_name);
	vm_free(full_file_wname);
	vm_free(full_temp_wname);
    return returnval;
}



VMINT vm_record_pause(void)
{
	VMINT status = VM_RECORD_NO_OF_STATE; 
	VMINT returnval = VM_RECORD_FAILED;
	VMINT result;

	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_PAUSE);
	if (vm_record_preprocess() == VM_RECORD_FAILED)
		return returnval;

	result = vm_res_get_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, &status);
	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_PAUSE_STATUS_VALUE,status);
	if(status == VM_RECORD_STATE_RECORD_PAUSED || result  == VM_RES_OUT_OF_RESOURCE)
	{
		return returnval;
	}
	
	result = mdi_audio_pause(vm_record_callback, NULL);
	   
	if (result == MDI_AUDIO_SUCCESS)
    {
   	    vm_res_set_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, VM_RECORD_STATE_RECORD_PAUSED);
  		returnval = VM_RECORD_SUCCEED;
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_PAUSE_SUCCESS);		
    }
    else
    {
  		returnval = VM_RECORD_FAILED;
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_SAL_PAUSE_FAIL);		
    }
    return returnval;	   
}

VMINT vm_record_resume(void)
{
	VMINT status = VM_RECORD_NO_OF_STATE; 
	VMINT returnval = VM_RECORD_FAILED;	
	VMINT result;

	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_RESUME);
	
	if (vm_record_preprocess() == FALSE)
		return returnval;

	vm_res_get_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, &status);
	if( status == VM_RECORD_STATE_RECORD)
	{
		return returnval;
	}
	
	result = mdi_audio_resume(vm_record_callback, NULL);

	if (result == MDI_AUDIO_SUCCESS)
       {
       	vm_res_set_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, VM_RECORD_STATE_RECORD);
      		returnval = VM_RECORD_SUCCEED;
			MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_SAL_RESUME_SUCCESS);
       }
       else
       {
      		returnval = VM_RECORD_FAILED;
					MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_SAL_RESUME_FAIL);
       }

		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_RESUME_RET,returnval);
       return returnval;
}

VMINT vm_record_stop(void)
{
	VMINT returnval = VM_RECORD_FAILED;
	VMINT result;

  	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_STOP);
	
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_RECORD_HANDLE) > 0)
	{
		result = mdi_audio_stop_record();
		if (result == MDI_AUDIO_SUCCESS)
	       {
	      		returnval = VM_RECORD_SUCCEED;
				vm_release_recode_resource();
				MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_SAL_STOP_SUCCESS);
	       }
	       else
	       {
	      		returnval = VM_RECORD_FAILED;
	      		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_SAL_STOP_FAIL);
	       }
	}
	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_RECORD_STOP_RET,returnval);
	return returnval;
}

#endif /* __MRE_SAL_AUDIO__ */

