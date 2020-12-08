#include "vmswitch.h"
#ifdef __MRE_SAL_AUDIO__
#include "vmsys.h"
#include "vmmm.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmio.h"
#include "vmchset.h"
#include "vmmod.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmfilere.h"
#include "vmsalmm.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmpromnginner.h"
#include "string.h"
#include "stdio.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "MMI_trc.h"
#include "mmi_rp_app_mre_def.h"
#include "ProfilesSrvGprot.h"
#include "Resource_audio.h"
#include "UcmSrvGprot.h"
#include "gpiosrvgprot.h"

#if defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h" 
#include "vapp_vol_dialog_gprot.h"
#endif

#include "ProfilesSrv.h"
#include "mmi_rp_srv_prof_def.h"
#include "mdi_bitstream.h"
#include "mdi_video.h"

#define INIT_VALUE		(-1)
#define REG_AUDIO_MODULE_FAILED  (-2)
#define REPEAT_MAX 		(255)
#define MILLISECONDS	(1000)

typedef enum
{
	VM_AUDIO_NONE,
	VM_AUDIO_FILE,
	VM_AUDIO_STRING,
	VM_AUDIO_MAX
}VM_AUDIO_TYPE_ENUM;

extern VMINT mre_running;

VMINT record_res_handle = INIT_VALUE;

static VM_AUDIO_TYPE_ENUM vm_audio_type = VM_AUDIO_NONE;
static VMINT current_volume = DEFAULT_VOLUME;
static VMWCHAR vm_audio_path[MAX_NAME_LEN] = {0};
static VMINT g_midi_type = MDI_FORMAT_SMF;
static VMINT audio_is_pause = FALSE;
static mdi_handle vm_slient_handle = -1;

static void vm_audio_callback(VMINT result, void *user_data);
static void vm_audio_mixed_callback(VMINT handle, VMINT result, void* user_data);

static void vm_audio_interrupt_callback_internal(VMINT result, void *user_data);
static VMINT vm_audio_background_callback_internal(VMINT result, void *user_data);

static void vm_auido_func_after_play_successed(void);
static void vm_auido_func_after_stop_successed(void);

static void vm_midi_resume_background_play(void);

VMINT vm_audio_get_used_res_type(VM_P_HANDLE *used_handle);
VMINT vm_audio_preprocess_play(VMINT type);

extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
extern VMINT vm_audio_is_vpp_file(void);

static VMINT vm_audio_duration_internal(VMWSTR filename) 
{
	VMINT result, duration;

	if (filename == NULL)
	{
		return VM_AUDIO_FAILED;
	}

	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > MAX_NAME_LEN)
	{
		return VM_AUDIO_FAILED;
	}

	duration = VM_AUDIO_FAILED;
	result = mdi_audio_get_duration(filename, (U32*)&duration);

	return result == MDI_AUDIO_SUCCESS ? (duration) : VM_AUDIO_FAILED;
}

static VMINT vm_audio_is_really_active(void)
{
	VMINT audio_type;
	int result = FALSE;	
	VM_P_HANDLE use_audio_handle;

	audio_type = vm_audio_get_used_res_type(&use_audio_handle);
	
	switch(audio_type)
	{
	case VM_RES_TYPE_AUDIO_HANDLE:
	case VM_RES_TYPE_MIDI_HANDLE:
		result = TRUE;
		break;
	}
	
	return result;
}

#ifdef __COSMOS_MMI_PACKAGE__

mmi_ret vm_audio_volume_event_hdlr(mmi_event_struct *evt)
{
    srv_prof_evt_vol_change_struct * volChangeEvt = NULL;
    vapp_vol_dialog_evt_struct *volEvent = NULL;
	VM_P_HANDLE pHandle;
	_vm_pcb_t* pcb = NULL;

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
	{
		vm_res_node_t data;
		vm_res_get_data_list_by_type(VM_RES_TYPE_AUDIO_HANDLE, &data, 1);
		pHandle = data.phandle;
	}
	else
	{
		return MMI_RET_OK;
	}


	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, pHandle, NULL)) == NULL)
	{
		return MMI_RET_OK;
	}
    
    switch(evt->evt_id)
    {
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:      
        {
            volEvent = (vapp_vol_dialog_evt_struct*) evt;
			
            if (volEvent->type == VAPP_VOL_DIALOG_IS_MEDIA && vm_audio_is_really_active() && pcb->volume_type == 1)
            {
                return !MMI_RET_OK;
            }
            else
            {
                return MMI_RET_OK;
            }
        }
        case EVT_ID_SRV_PROF_VOL_CHANGED:
            volChangeEvt = (srv_prof_evt_vol_change_struct*)evt;
            if(SRV_PROF_VOL_MEDIA == volChangeEvt->vol_type && pcb->volume_type == 1)
            {
                current_volume = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());
                return MMI_RET_OK;
            }
			else if(SRV_PROF_VOL_RING == volChangeEvt->vol_type && pcb->volume_type == 0)
			{
                current_volume = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_ring_vol());
                return MMI_RET_OK;
			}
            break;
        default:
            break;
    }
	
	return !MMI_RET_OK;

}
#endif
mmi_ret vm_audio_play_event_hdlr(mmi_event_struct *param)
{
    if (vm_audio_is_really_active())
    {
        return !MMI_RET_OK;
    }
    else
    {
        return MMI_RET_OK;
    }
}


mmi_ret vm_audio_fmgr_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_adv_action_event_struct *adv_action = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(param->evt_id)
    {
	    case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
	        adv_action = (srv_fmgr_notification_adv_action_event_struct *) param;
			
			if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
			{
		        if (adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE ||
		            adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE ||
		            adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_RENAME )
		        {
		            if((vm_wstrlen(vm_audio_path) > 0) && (vm_wstrcmp((VMWSTR)vm_audio_path,(VMWSTR)adv_action->src_filepath) == 0))
		            {
		                return MMI_RET_ERR;
		            }
		        }
				 else if(adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL)
				 {
				 	if(kal_wstrncmp((const WCHAR *)adv_action->src_filepath, (const WCHAR *)vm_audio_path, kal_wstrlen(adv_action->src_filepath)) == 0)
				 	{
				 		return MMI_RET_ERR;
				 	}
				 }
			}
	    break;
    }
    return MMI_RET_OK;
}


/* resource manager begin */

void vm_audio_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
		if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
		{
			vm_res_node_t data;
			vm_res_get_data_list_by_type(VM_RES_TYPE_AUDIO_HANDLE, &data, 1);
			if (process_handle == data.phandle)
				vm_audio_stop(NULL);
		}
		vm_get_volume();
		break;
	}
}

void vm_mixed_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_MIDI_NOTIFY_CALLBACK_PROCESS_INFO,process_handle, sys_state);
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
		break;
	case VM_PMNG_BACKGROUND:
	case VM_PMNG_UNLOAD:
		vm_midi_stop_all();
		break;
	}	
}

void vm_record_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
		break;
	case VM_PMNG_BACKGROUND:
	case VM_PMNG_UNLOAD:
		vm_record_stop(); 
		break;
	}
}

void vm_interrup_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
		break;
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
		if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_INTERRUPT) > 0)
		{
			vm_res_node_t data;
			vm_res_get_data_list_by_type(VM_RES_TYPE_AUDIO_INTERRUPT, &data, 1);
			
			if (process_handle == data.phandle)
			{
				mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MRE); 
			}
		}
		break;
	}
}

VMINT vm_init_audio_module(void)
{
	record_res_handle = INIT_VALUE;	
	vm_get_volume();
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE,(mmi_proc_func)vm_audio_volume_event_hdlr, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_VOL_CHANGED,(mmi_proc_func)vm_audio_volume_event_hdlr, NULL);
#endif
    mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_IS_PLAYING, (mmi_proc_func)vm_audio_play_event_hdlr, NULL);
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, vm_audio_fmgr_notify_hdlr, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_HANDLE, vm_audio_notify_callback);
	vm_res_type_set_notify_callback(VM_RES_TYPE_MIDI_HANDLE, vm_mixed_notify_callback);
	vm_res_type_set_notify_callback(VM_RES_TYPE_RECORD_HANDLE, vm_record_notify_callback);
	vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_INTERRUPT, vm_interrup_notify_callback);

    mdi_audio_mma_build_BLSI_table(MMI_TRUE);

	return REG_MRE_MODULE_SUCCESS;
}

VMINT vm_finialize_audio_module(void)
{	
	vm_vibrator_off();
	record_res_handle = INIT_VALUE;	
	vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_HANDLE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_MIDI_HANDLE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_RECORD_HANDLE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_INTERRUPT, NULL);
#ifdef __COSMOS_MMI_PACKAGE__
	mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE,(mmi_proc_func)vm_audio_volume_event_hdlr, NULL);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_VOL_CHANGED,(mmi_proc_func)vm_audio_volume_event_hdlr, NULL);
#endif
	mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_IS_PLAYING, (mmi_proc_func)vm_audio_play_event_hdlr, NULL);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, vm_audio_fmgr_notify_hdlr, NULL);
    mdi_audio_mma_build_BLSI_table(MMI_FALSE);
	if(vm_slient_handle != -1)
	{
		mdi_audio_mma_stop(vm_slient_handle);
		mdi_audio_mma_close(vm_slient_handle);
		vm_slient_handle = -1;
	}
		
	return REG_MRE_MODULE_SUCCESS;
}

static VMINT vm_audio_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_init_audio_module();
		break;
	case EVT_MOD_INACTIVE:
		vm_vibrator_off();
	case EVT_MOD_ACTIVE:		
		break;
	case EVT_MOD_RELEASE:
		vm_finialize_audio_module();
		break;
	default:
		return REG_AUDIO_MODULE_FAILED;
	}
	
	return REG_MRE_MODULE_SUCCESS;
}

VMINT _vm_reg_audio_module(void)
{
	int res = REG_MRE_MODULE_SUCCESS;
	
	if ((res = _vm_reg_module("AUDIO MODULE", (MOD_EVT_PROCESS)vm_audio_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_AUDIO_REG_FAIL,res);
	}

	return res;
}


static void vm_release_audio_resource(void)
{
	VMINT resHandle;

	while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_AUDIO_HANDLE)) != VM_RES_NOT_FIND)
	{
		vm_res_release_data(VM_RES_TYPE_AUDIO_HANDLE, resHandle);
		vm_res_findclose(VM_RES_TYPE_AUDIO_HANDLE);
	}
}

static void vm_release_midi_resource(VMINT *res_handle)
{
	vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, *res_handle);
	*res_handle = VM_MIDI_FAILED;
}


/* resource manager end */



/* audio play file begin */

VMINT vm_audio_can_play_internal()
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	VM_PROCESS_STATUS pStatus = vm_pmng_state(pHandle);
		
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/	
	if (pHandle > 0 && pStatus == VM_PMNG_FOREGROUND)
	{
		return 1;
	}
	else if (pHandle > 0 && (pStatus == VM_PMNG_BACKGROUND || pStatus == VM_PMNG_INACTIVE) || (vm_audio_is_vpp_file() == 1))
	{
		if( mdi_audio_is_idle()
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
			&& !mdi_video_is_playing()
#endif
#if defined(__MMI_VIDEO_RECORDER__)
			&& !mdi_video_is_recording()
#endif
#if defined(BGSND_ENABLE)
			&& mdi_audio_snd_is_idle()
#endif
#if defined(__MMI_MOBILE_TV_PLAYER__)
			&& (mdi_mtv_is_playing()==MMI_FALSE)
#endif
#if defined(__BITSTREAM_API_SUPPORT__)
			&& (mdi_bitstream_audio_get_open_handle_count() == 0)
#endif
			&& !mdi_audio_mma_is_open() )
		{
			return 1;
		}
		else
		{
			vm_log_fatal("vm_sal_audio_can_play audio resource occupied");
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void vm_audio_callback(VMINT result, void *user_data) 
{
	void (*audio_callback)(VMINT result) = NULL;
	VMINT res_handle = VM_RES_NOT_FIND;
	VM_P_HANDLE mtk_handle = 0;

	if (mre_running == FALSE)
		return;

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_AUDIO_HANDLE)) != VM_RES_NOT_FIND)
	{
		mtk_handle = vm_res_get_process_handle(VM_RES_TYPE_AUDIO_HANDLE, res_handle);
		vm_res_get_callback(VM_RES_TYPE_AUDIO_HANDLE, res_handle, (void**)&audio_callback);
		vm_res_findclose(VM_RES_TYPE_AUDIO_HANDLE);
	}

	if (audio_callback != NULL && mtk_handle != 0 && vm_pmng_set_ctx(mtk_handle) == VM_PMNG_OP_OK )
	{

		switch (result) 
		{
			case MDI_AUDIO_SUCCESS:
				break;
			case MDI_AUDIO_RESUME:
				audio_callback(VM_AUDIO_RESULT_RESUME);
				break;
			case MDI_AUDIO_BLOCKED:
				audio_callback(VM_AUDIO_RESULT_PAUSE);
				break;
			case MDI_AUDIO_TERMINATED:	
				vm_audio_type = VM_AUDIO_NONE;
				memset(vm_audio_path, 0, MAX_NAME_LEN*2);
				audio_callback(VM_AUDIO_RESULT_STOP);
				break;
			case MDI_AUDIO_END_OF_FILE:
				vm_auido_func_after_stop_successed();
				if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
				{
					memset(vm_audio_path,0, MAX_NAME_LEN*2);
					vm_release_audio_resource();
				}
				audio_callback(VM_AUDIO_RESULT_END_OF_FILE);
				break;
			case MDI_AUDIO_DEMO_END:
				memset(vm_audio_path, 0, MAX_NAME_LEN*2);
				audio_callback(VM_AUDIO_RESULT_DEMO_END);	
				break; 
			case VM_AUDIO_RESULT_INTERRUPT:
				vm_audio_type = VM_AUDIO_NONE;
				audio_callback(VM_AUDIO_RESULT_INTERRUPT);
				break;
			case VM_AUDIO_RESULT_INTERRUPT_RESUME:
				if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
				{
					vm_release_audio_resource();
				}
				audio_callback(VM_AUDIO_RESULT_INTERRUPT_RESUME);
				break;
			default:
				memset(vm_audio_path, 0, MAX_NAME_LEN*2);
				audio_callback(VM_AUDIO_RESULT_STOP);
				break;
		}
		
		vm_pmng_reset_ctx();
	}	
}


static void vm_audio_interrupt_callback_internal(VMINT result, void *user_data)
{
	if(result == MDI_AUDIO_TERMINATED)	
	{
		vm_audio_callback(VM_AUDIO_RESULT_INTERRUPT, user_data);
	}
}

static VMINT vm_audio_background_callback_internal(VMINT result, void *user_data)
{
	mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MRE);
	if(result == MDI_AUDIO_TERMINATED)	
	{
		vm_audio_callback(VM_AUDIO_RESULT_INTERRUPT, user_data);
	}
	else
	{
		vm_audio_callback(VM_AUDIO_RESULT_INTERRUPT_RESUME, user_data);
	}
	return TRUE;
}

static void vm_auido_func_after_play_successed(void)
{
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	VMINT i;
	VMINT found = 0;
	
	if ((i = vm_res_findfirst(pHandle, VM_RES_TYPE_AUDIO_INTERRUPT)) != VM_RES_NOT_FIND)
	{
		found = 1;
		vm_res_findclose(VM_RES_TYPE_AUDIO_INTERRUPT);
	}				
	
	if(!found)
	{
		mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MRE, (mdi_bg_callback)vm_audio_background_callback_internal, NULL);	
		mdi_audio_register_interrupt_callback((mdi_ext_callback)vm_audio_interrupt_callback_internal, NULL);
	}
	
}

static void vm_auido_func_after_stop_successed(void)
{
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	VMINT i;
	VMINT found = 0;

	if ((i = vm_res_findfirst(pHandle, VM_RES_TYPE_AUDIO_INTERRUPT)) != VM_RES_NOT_FIND)
	{
		found = 1;
		vm_res_findclose(VM_RES_TYPE_AUDIO_INTERRUPT);
	}				

	vm_audio_type = VM_AUDIO_NONE;
	
	if(!found)
	{
		mdi_audio_clear_interrupt_callback();
		mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MRE);
	}
}


VMINT vm_audio_get_used_res_type(VM_P_HANDLE *used_handle)
{
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_MIDI_HANDLE) > 0)
		return VM_RES_TYPE_MIDI_HANDLE;

	if ((vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE)) > 0)
	{
		vm_res_node_t data;
		vm_res_get_data_list_by_type(VM_RES_TYPE_AUDIO_HANDLE, &data, 1);
		*used_handle = data.phandle;
		return VM_RES_TYPE_AUDIO_HANDLE;
	}
	
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_RECORD_HANDLE) > 0)
		return VM_RES_TYPE_RECORD_HANDLE;
#if ( defined(__MRE_SAL_VIDEO__)) 
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_VIDEO_HANDLE) > 0)
		return VM_RES_TYPE_VIDEO_HANDLE;
#endif
#if ( defined(__MRE_SAL_BITSTREAM__)) 
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_BIT_HANDLE) > 0)
		return VM_RES_TYPE_AUDIO_BIT_HANDLE;
#endif

	return NULL;
}

VMINT vm_audio_preprocess_play(VMINT type)
{
	VMINT audio_type;		
	VM_P_HANDLE use_audio_handle = INIT_VALUE;
	VM_P_HANDLE current_handle;
	int result = FALSE;	

	if (vm_sal_query_calling() == TRUE)
		return FALSE;
	
	audio_type = vm_audio_get_used_res_type(&use_audio_handle);
	current_handle = vm_pmng_get_current_handle();
	
	switch(audio_type)
	{
	case NULL:
		result = TRUE;
		break;
	case VM_RES_TYPE_AUDIO_HANDLE:
		{
			//前后台audio 资源相互抢占的情况有以下四种：
			// 1. 占用audio 的进程为前台，申请 进程也为前台，可抢占(返回TRUE)。
			// 2. 占用audio 的进程为后台，申请 进程的为前台，可抢占(返回TRUE)。
			// 3. 占用audio 的进程为后台，申请 进程也为后台，可抢占(返回TRUE)。
			// 4. 占用audio 的进程为前台，申请 进程的为后台，不可抢占(返回FALSE)。
			if ((!vm_pmng_is_fg(current_handle)) && vm_pmng_is_fg(use_audio_handle))
			{
				//本情况为占用audio 的进程是前台，申请 进程的为后台
				MMI_TRACE(TRACE_GROUP_5,TRC_MRE_AUDIO_CUR_BG_USE_FG);
				result = FALSE;
			}
			else
			{
				//本情况为可抢占
				//通知MRE 系统停止使用音频资源				
				vm_audio_stop(NULL);	
				result = TRUE;
			}
		}
		break;
	case VM_RES_TYPE_MIDI_HANDLE:
		{
			if(type == VM_RES_TYPE_AUDIO_HANDLE)
			{
				vm_midi_stop_all();
				result = TRUE;
			}
			else if(type == VM_RES_TYPE_MIDI_HANDLE)
			{
				VMINT midi_count = vm_res_get_data_list_count_by_proecss(current_handle, VM_RES_TYPE_MIDI_HANDLE);
				if (midi_count < VM_MIDI_PLAY_MAX)
					result = TRUE;
			}
		}
		
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

	MMI_TRACE(TRACE_GROUP_5,TRC_MRE_AUDIO_PREPRO_PLAY_RET,result);
	return result;
}

VMINT vm_audio_bytes_duration_internal(void *audio_data, VMUINT len, VMUINT8 format)
{
	VMINT result, duration;

	result = mdi_audio_get_duration_by_string(audio_data, len, format, (U32*)&duration);

	return result == MDI_AUDIO_SUCCESS ? (duration) : VM_AUDIO_FAILED;
}

VMINT vm_audio_play_bytes_internal(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path,  VMBOOL block, void (*f)(VMINT result))
{
	int result = VM_AUDIO_FAILED;	
	VMINT res_handle;
	VMUINT8 volume = current_volume;
	VMINT iscosmos = 0;
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	_vm_pcb_t* pcb = NULL;

	if (!(format == VM_FORMAT_MP3 || format == VM_FORMAT_AAC|| format == VM_FORMAT_AMR|| format == VM_FORMAT_WAV))
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_AUDIO_PLAY_BYTES_FORMAT_NOT_SUPPORT);
		return VM_AUDIO_FAILED;
	}
	
	if (audio_data == NULL || len == 0 || vm_audio_preprocess_play(VM_RES_TYPE_AUDIO_HANDLE) == FALSE)
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_AUDIO_PLAY_BYTES_PREPROCESS_FAIL);
		return VM_AUDIO_FAILED;
	}

	if(start_time != 0)
	{
		if(start_time >= vm_audio_bytes_duration_internal(audio_data, len, format))
			return VM_AUDIO_FAILED;
	}
	
	vm_release_audio_resource();
		
	res_handle = vm_res_save_data(VM_RES_TYPE_AUDIO_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle());
	
	if (res_handle > INIT_VALUE)
	{
		vm_audio_type = VM_AUDIO_STRING;

		if(!vm_audio_can_play_internal())
		{
			return VM_AUDIO_FAILED;
		}
		
#ifdef __COSMOS_MMI_PACKAGE__
		iscosmos = 1;
#endif
			
		if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, pHandle, NULL)) != NULL)
		{
			if(iscosmos == 0 || pcb->volume_type == 0)
				volume = (VMUINT8)MDI_AUD_VOL_MUTE(current_volume);
#ifdef __COSMOS_MMI_PACKAGE__
			else
				volume = (VMUINT8)MDI_AUD_VOL_EX_MUTE(current_volume);
#endif
		}
		

		if(block == TRUE)
		{
			result = mdi_audio_play_string_with_vol_path_non_block(
						audio_data, 
						len, 
						format, 
						DEVICE_AUDIO_PLAY_ONCE, 
						vm_audio_callback,
						NULL,
						volume,
						path);
		}
		else
		{
			result = mdi_audio_play_string_portion_with_vol_path(
						audio_data, 
						len, 
						format, 
						start_time, 
						0, 
						DEVICE_AUDIO_PLAY_ONCE, 
						vm_audio_callback,
						NULL, 
						volume,
						path);
		}
				
		if(result == MDI_AUDIO_SUCCESS)
		{
			vm_auido_func_after_play_successed();
			result = VM_AUDIO_SUCCEED;
		}
		else
		{
			vm_release_audio_resource();
			result = VM_AUDIO_FAILED;
		}
	}
	return result;
}


VMINT vm_audio_play_file(VMWSTR filename, void (*f)(VMINT result)) 
{
	return vm_audio_play_file_ex(filename, 0, VM_DEVICE_SPEAKER2, f);
}

VMINT vm_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
	int result = VM_AUDIO_FAILED;	
	VMINT res_handle;
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	_vm_pcb_t* pcb = NULL;
	VMINT iscosmos = 0;
	VMUINT8 volume = current_volume;

	if (filename == NULL)
	{
		return VM_AUDIO_FAILED;
	}
	
	if (vm_wstrlen(filename) <= 0 || vm_wstrlen(filename) > MAX_NAME_LEN)
	{
		return VM_AUDIO_FAILED;
	}
	
	if ( vm_audio_preprocess_play(VM_RES_TYPE_AUDIO_HANDLE) == FALSE)
	{
		return VM_AUDIO_FAILED;
	}
	else if(start_time != 0)
	{
		if(start_time > vm_audio_duration_internal(filename))
			return VM_AUDIO_FAILED;
	}

	vm_release_audio_resource();
	
	res_handle = vm_res_save_data(VM_RES_TYPE_AUDIO_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle());

	if (res_handle > INIT_VALUE)
	{
		if(!vm_audio_can_play_internal())
		{
			return VM_AUDIO_FAILED;
		}
		
#ifdef __COSMOS_MMI_PACKAGE__
		iscosmos = 1;
#endif
		
		if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, pHandle, NULL)) != NULL)
		{
			if(iscosmos == 0 || pcb->volume_type == 0)
				volume = (VMUINT8)MDI_AUD_VOL_MUTE(current_volume);
#ifdef __COSMOS_MMI_PACKAGE__
			else
				volume = (VMUINT8)MDI_AUD_VOL_EX_MUTE(current_volume);
#endif
		}

		vm_audio_type = VM_AUDIO_FILE;
		
		vm_wstrcpy(vm_audio_path, filename);

		result = mdi_audio_play_file_portion_with_vol_path(
			filename,
			start_time,
			0, 
			DEVICE_AUDIO_PLAY_ONCE,
			NULL,
			vm_audio_callback,
			NULL,
			volume,
			path);	
		
		if(result == MDI_AUDIO_SUCCESS)
		{
			vm_auido_func_after_play_successed();
			result = VM_AUDIO_SUCCEED;
		}
		else
		{
			vm_release_audio_resource();
			result = VM_AUDIO_FAILED;
		}
		
	}
	
	return result;
}

VMINT vm_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
	return vm_audio_play_bytes_internal(audio_data, len, format, start_time, path, FALSE, f);	
}


VMINT vm_audio_play_bytes_no_block(void *audio_data, VMUINT len, VMUINT8 format, VMUINT path, void (*f)(VMINT result))
{
	return vm_audio_play_bytes_internal(audio_data, len, format, 0, path, TRUE, f);
}



VMINT vm_audio_pause(void (*f)(VMINT result)) 
{
	int result = VM_AUDIO_FAILED;	

	if ((vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0) && audio_is_pause == FALSE)
	{
		result = mdi_audio_pause(vm_audio_callback, NULL);
		
		if(result != MDI_AUDIO_SUCCESS)
		{
			result = VM_AUDIO_FAILED;
		}
		else
		{
			audio_is_pause = TRUE;
			result = VM_AUDIO_SUCCEED;
		}
	}
	return result;
}

VMINT vm_audio_resume(void (*f)(VMINT result)) 
{
	int result = VM_AUDIO_FAILED;	

	if ((vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0) &&  audio_is_pause == TRUE)
	{
		if(!vm_audio_can_play_internal())
		{
			return VM_AUDIO_FAILED;
		}
		
		result = mdi_audio_resume(vm_audio_callback, NULL);
		
		if(result != MDI_AUDIO_SUCCESS)
		{
			result = VM_AUDIO_FAILED;
		}
		else
		{
			audio_is_pause = FALSE;
			result = VM_AUDIO_SUCCEED;
		}
	}
	return result;
}

VMINT vm_audio_stop(void (*f)(VMINT result)) 
{
	int audio_count = 0;
	int result = VM_AUDIO_FAILED;	

	audio_count = vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE);
	
	if (audio_count > 0)
	{
		memset(vm_audio_path,0, MAX_NAME_LEN*2);

		if (vm_audio_type == VM_AUDIO_FILE)
		{
			result = mdi_audio_stop_file();
		}
		else if (vm_audio_type == VM_AUDIO_STRING)
		{
			result = mdi_audio_stop_string();
		}
		else
		{
			result = VM_AUDIO_FAILED;
		}
	
		if( result == MDI_AUDIO_SUCCESS)
		{
			vm_auido_func_after_stop_successed();
			audio_is_pause = FALSE;
			result = VM_AUDIO_SUCCEED;
		}
		else
		{
			result = VM_AUDIO_FAILED;
		}
		
		vm_release_audio_resource();
		
	}
	return result;
}

VMINT vm_audio_stop_all(void) 
{
	int result = VM_AUDIO_FAILED;	
	memset(vm_audio_path,0, MAX_NAME_LEN*2);
	result = mdi_audio_stop_all();
	return result;
}

VMINT vm_audio_duration(VMWSTR filename) 
{
	int result = VM_AUDIO_FAILED;	

	result = vm_audio_duration_internal(filename) / MILLISECONDS;

	return result;
}

VMINT vm_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format)
{
	int result = VM_AUDIO_FAILED;	

	if (audio_data == NULL || len == 0)
	{
		return result;
	}

	switch(format)
	{
		case VM_FORMAT_MP3:
		case VM_FORMAT_AAC:
		case VM_FORMAT_MIDI:
		case VM_FORMAT_AMR:
			result = vm_audio_bytes_duration_internal(audio_data, len, format) / MILLISECONDS;
		break;
	}
	return result;
}

VMINT vm_audio_get_time(void)
{
	int result = VM_AUDIO_FAILED;	

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
	{
		VMUINT offset;
		
		result =  mdi_audio_get_progress_time(&offset);
		
		if(result == MDI_AUDIO_SUCCESS)
		{
			return (VMINT)offset;
		}
		else
		{
			return (VMINT)VM_AUDIO_FAILED;
		}
	}

	return result;
}

/* audio play file end */


static void vm_midi_resume_background_play(void)
{
	int midi_count = 0;
	VM_P_HANDLE current_handle = vm_pmng_get_current_handle();
	
	midi_count = vm_res_get_data_list_count_by_proecss(current_handle, VM_RES_TYPE_MIDI_HANDLE);
	if (midi_count == 0)
	{
		if (mdi_audio_is_background_play_suspended() == MMI_TRUE)
		{
			mdi_audio_resume_background_play();
		}
	}
}

VMINT vm_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) )
{
	int res_handle = VM_MIDI_FAILED;
	vm_auido_mixed_open_struct mixed_open;
	VMINT handle;
	
    mixed_open.data = midibuf;
    mixed_open.data_len = len;
    mixed_open.format = (vm_format_enum)g_midi_type;
    mixed_open.repeats = (VMINT8)repeat;
    mixed_open.output_path = path;
    mixed_open.async_mode = TRUE;
    mixed_open.callback = f;
    mixed_open.user_data = &g_midi_type;

	handle = vm_audio_mixed_open(&mixed_open);

	if(handle != VM_AUDIO_FAILED)
	{
		vm_audio_mixed_set_start_time(handle, start_time);
		vm_audio_mixed_play(handle);
	}
	
	g_midi_type = MDI_FORMAT_SMF;

	return handle;

}

void vm_midi_set_type(VMINT type)
{
	g_midi_type = type;
}

VMINT vm_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) )
{
	return vm_midi_play_by_bytes_ex(midibuf, len, 0, repeat, VM_DEVICE_SPEAKER2, f);
}

VMINT vm_midi_pause(VMINT handle)
{
	return vm_audio_mixed_pause(handle);
}

VMINT vm_midi_resume(VMINT handle)
{
	return vm_audio_mixed_resume(handle);
}

VMINT vm_midi_get_time(VMINT handle, VMUINT *current_time)
{
	return vm_audio_mixed_get_time(handle, current_time);
}

void vm_midi_stop(VMINT handle) 
{
	vm_audio_mixed_stop(handle);
	vm_audio_mixed_close(handle);
	vm_midi_resume_background_play();
}

void vm_midi_stop_all(void)
{
	vm_audio_mixed_close_all();
	vm_midi_resume_background_play();
}

/* mixed play file start */
static void vm_audio_mixed_callback(VMINT handle, VMINT result, void* user_data) 
{
	VMINT res_handle = VM_RES_NOT_FIND, res = 0;
	void (*mixed_callback)(VMINT handle, VMINT result, void* user_data) = NULL;
	void (*midi_callback)(VMINT handle, VMINT result) = NULL;
	VM_P_HANDLE use_mixed_handle = 0;

	if(result == MDI_AUDIO_END_OF_FILE) 
	{
		mdi_audio_mma_close(handle);
	}

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_MIDI_HANDLE)) != VM_RES_NOT_FIND)
	{
		if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, &res))== VM_RES_OK)
		{
			if (res == handle)
			{
				if(user_data == &g_midi_type)
				{
					vm_res_get_callback(VM_RES_TYPE_MIDI_HANDLE, res_handle, (void**)&midi_callback);
				}
				else
				{
					vm_res_get_callback(VM_RES_TYPE_MIDI_HANDLE, res_handle, (void**)&mixed_callback);
				}
				use_mixed_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, res_handle);
				vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, res_handle);
			}
		}
		
		while ((res_handle = vm_res_findnext(-1, VM_RES_TYPE_MIDI_HANDLE)) != VM_RES_NOT_FIND)
		{		
			vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, &res);
			if (res == handle)
			{
				if(user_data == &g_midi_type)
				{
					vm_res_get_callback(VM_RES_TYPE_MIDI_HANDLE, res_handle, (void**)&midi_callback);
				}
				else
				{
					vm_res_get_callback(VM_RES_TYPE_MIDI_HANDLE, res_handle, (void**)&mixed_callback);
				}
				use_mixed_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, res_handle);
				vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, res_handle);
				break;
			}
		}
		vm_res_findclose(VM_RES_TYPE_MIDI_HANDLE);
	}	

	if (mixed_callback != NULL)
	{
		if (vm_pmng_set_ctx(use_mixed_handle) == VM_PMNG_OP_OK)
		{
			switch (result) 
			{
				case MDI_AUDIO_END_OF_FILE:
					mixed_callback((VMINT)handle, VM_AUDIO_RESULT_END_OF_FILE, user_data);
					break;
				case MDI_AUDIO_TERMINATED:
					mixed_callback((VMINT)handle, VM_AUDIO_RESULT_STOP, user_data);
					break;
				case VM_AUDIO_RESULT_INTERRUPT:
					mixed_callback((VMINT)handle, VM_AUDIO_RESULT_INTERRUPT, user_data);
					break;
				default:
					mixed_callback((VMINT)handle, VM_FORMAT_OTHER, user_data);
					break;
			}

			vm_pmng_reset_ctx();
		}
	}
	else if(midi_callback != NULL)
	{
		if (vm_pmng_set_ctx(use_mixed_handle) == VM_PMNG_OP_OK)
		{
			switch (result) 
			{
				case VM_AUDIO_RESULT_END_OF_FILE:
					midi_callback((VMINT)handle, VM_AUDIO_RESULT_END_OF_FILE);
					vm_midi_resume_background_play();
					break;
				default:
					midi_callback((VMINT)handle, VM_FORMAT_OTHER);
					break;
			}

			vm_pmng_reset_ctx();
		}
	}
	else
	{
		return;
	}
}

static VMUCHAR *vm_get_audio(VMUINT16 i, VMUINT8 *type, VMUINT *filelen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 *s = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(type != NULL && filelen != NULL);

    *type = 0;;
    *filelen = 0;

    if (i == 0)
    {
        return (NULL);
    }

    s = (VMUINT8*) GetAudio((VMUINT16) i);
    if (s == NULL)
    {
        return (NULL);
    }
    if (s[0] == '\0')
    {
        return (NULL);
    }

    *type = s[0];

    *filelen |= (U32) (s[1]);
    *filelen |= (U32) ((VMUINT32) s[2] << 8);
    *filelen |= (U32) ((VMUINT32) s[3] << 16);
    *filelen |= (U32) ((VMUINT32) s[4] << 24);

    return (s + 8);
}

void vm_audio_mixed_set_speedup_mode(VMBOOL mode)
{

		if(mode)
		{
			VMUINT slient_len;
			VMUCHAR slient_type;
			VMUCHAR *audio_data_slient;

			audio_data_slient = vm_get_audio(AUD_ID_MRE_FEEDBACK_SLIENT, &slient_type, &slient_len);
		
			if (audio_data_slient)
			{
				if(vm_slient_handle == -1)
				{
					vm_slient_handle = mdi_audio_mma_open_string(0,	
						audio_data_slient, slient_len, slient_type,	0,
						NULL,NULL);
					mdi_audio_mma_play(vm_slient_handle);
				}
			}
		}
		else
		{
			if(vm_slient_handle != -1)
			{
				mdi_audio_mma_stop(vm_slient_handle);
				mdi_audio_mma_close(vm_slient_handle);
				vm_slient_handle = -1;
			}
		}
}

VMINT vm_audio_mixed_open(vm_auido_mixed_open_struct* mixed_open_p)
{
	int res_handle = VM_AUDIO_FAILED;
	int res = VM_AUDIO_FAILED;
	
	if(mixed_open_p == NULL)
		return res;
	
	if ( mixed_open_p->data == NULL || mixed_open_p->repeats > REPEAT_MAX ||vm_audio_preprocess_play(VM_RES_TYPE_MIDI_HANDLE) == FALSE)
		return res;

	if ((res_handle = vm_res_save_data(VM_RES_TYPE_MIDI_HANDLE, NULL, 0, (void*)mixed_open_p->callback, vm_pmng_get_current_handle())) >= 0)
	{
		VMINT handle;
		mdi_mma_open_struct mixed_open;
	
		if(!vm_audio_can_play_internal())
		{
			return VM_AUDIO_FAILED;
		}
	
		mixed_open.app_id = 0;
		mixed_open.data = mixed_open_p->data;
		mixed_open.data_len = mixed_open_p->data_len;
		mixed_open.file_name = NULL;
		mixed_open.is_pdl = MMI_FALSE;
		mixed_open.mdi_format = mixed_open_p->format;
		mixed_open.output_path = mixed_open_p->output_path;
		mixed_open.repeats = mixed_open_p->repeats;
		mixed_open.user_data = mixed_open_p->user_data;
		mixed_open.callback = vm_audio_mixed_callback;
		mixed_open.handle_p  = &handle;
	
		mdi_audio_mma_open(&mixed_open);
		
		if ( handle != 0 )	 
		{
			mdi_audio_mma_set_param(handle, MDI_MMA_PARAM_SET_ASYNC_MODE, (void*)&mixed_open_p->async_mode);
			mdi_audio_set_headset_mode_output_path(mixed_open_p->output_path);
			vm_res_set_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, handle);
		}
		else
		{
			vm_release_midi_resource(&res_handle);
		}
	}

	return res_handle;
											  
}

VMINT vm_audio_mixed_play(VMINT handle)
{
	VMINT res, result = VM_AUDIO_FAILED;
	VM_P_HANDLE res_handle = VM_AUDIO_FAILED;
	VM_P_HANDLE pmng_handle = VM_AUDIO_FAILED;

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();
	
	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{		
			mdi_result play_result;
			
			if(!vm_audio_can_play_internal())
			{
				return VM_AUDIO_FAILED;
			}
			
			play_result = mdi_audio_mma_play(res);
				
			if (play_result != MDI_AUDIO_SUCCESS)
			{
				result = VM_AUDIO_FAILED;
			}
			else
			{
				result = VM_AUDIO_SUCCEED;
			}
		}
	}
	return result;				  
}

VMINT vm_audio_mixed_pause(VMINT handle)
{
	VMINT res, result = VM_MIDI_FAILED;

	VM_P_HANDLE res_handle = VM_MIDI_FAILED;
	VM_P_HANDLE pmng_handle = VM_MIDI_FAILED;

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	
	pmng_handle = vm_pmng_get_current_handle();
	
	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			result = mdi_audio_mma_pause(res);
		}
	}
	return result;
}

VMINT vm_audio_mixed_resume(VMINT handle)
{
	VMINT res, result = VM_MIDI_FAILED;
	VM_P_HANDLE res_handle = VM_MIDI_FAILED;
	VM_P_HANDLE pmng_handle = VM_MIDI_FAILED;

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();
	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			result = mdi_audio_mma_resume(res);
		}
	}
	return result;	
}

VMINT vm_audio_mixed_get_time(VMINT handle, VMUINT *current_time)
{
	VMINT res, result = VM_MIDI_FAILED;
	VM_P_HANDLE res_handle = VM_MIDI_FAILED;
	VM_P_HANDLE pmng_handle = VM_MIDI_FAILED;

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();
	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			*current_time = 0;
			result = mdi_audio_mma_get_current_time(res, current_time);
		}
	}
	return result;	
}

VMINT vm_audio_mixed_set_start_time(VMINT handle, VMUINT start_time)
{
	VMINT res, result = VM_AUDIO_FAILED;
	VM_P_HANDLE res_handle = VM_AUDIO_FAILED;
	VM_P_HANDLE pmng_handle = VM_AUDIO_FAILED;
	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();

	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			result = mdi_audio_mma_set_start_time(res, start_time);
		}
	}
	return result;	
}

void vm_audio_mixed_stop(VMINT handle)
{
	int res;
	VM_P_HANDLE res_handle = VM_AUDIO_FAILED;
	VM_P_HANDLE pmng_handle = VM_AUDIO_FAILED;


	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();

	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			 mdi_audio_mma_stop(res);
		}
	}
}

void vm_audio_mixed_close(VMINT handle)
{
	int res;
	VM_P_HANDLE res_handle = VM_AUDIO_FAILED;
	VM_P_HANDLE pmng_handle = VM_AUDIO_FAILED;


	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();

	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			mdi_audio_mma_close(res);
			vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, handle);
		}
	}
}

void vm_audio_mixed_close_all(void)
{
	VMINT res_handle = VM_RES_NOT_FIND, res = 0;
	
	while ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_MIDI_HANDLE)) != VM_RES_NOT_FIND)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, &res) == 0)
		{
			mdi_audio_mma_stop(res);
			mdi_audio_mma_close(res);
			vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, res_handle);
		}
		vm_res_findclose(VM_RES_TYPE_MIDI_HANDLE);
	}
}
/* mixed play file end */

void vm_set_volume(VMINT volume) 
{
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	_vm_pcb_t* pcb = NULL;
	VMINT iscosmos = 0;
	srv_prof_setting_struct settings;

#ifdef __COSMOS_MMI_PACKAGE__
	iscosmos = 1;
#endif	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, pHandle, NULL)) != NULL)
	{
		if(iscosmos == 0 || pcb->volume_type == 0)
		{
			if (volume < MDI_AUD_VOL_NUM + 1 && volume >= 0)
			{
				current_volume = volume;
				
				mdi_audio_set_volume(MDI_VOLUME_MEDIA, (VMUINT8)MDI_AUD_VOL_MUTE(volume));
				srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings);
				settings.ring_vol = (srv_prof_volume_level)volume;
				srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings);
				
				srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
				settings.ring_vol = (srv_prof_volume_level)volume;
				srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);
			}
		}
#ifdef __COSMOS_MMI_PACKAGE__
		else
		{			
			if (volume < 17 && volume >= 0)
			{
				current_volume = volume;
				
				mdi_audio_set_volume(MDI_VOLUME_MEDIA, (VMUINT8)MDI_AUD_VOL_EX_MUTE(volume));
				
				srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings);
				settings.media_vol = (srv_prof_volume_level)volume;
				srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings);
				
				srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
				settings.media_vol = (srv_prof_volume_level)volume;
				srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);
			}			
		}
#endif
	}
}


VMINT vm_get_volume(void)
{
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	_vm_pcb_t* pcb = NULL;
	
	current_volume = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_ring_vol());
	
#ifdef __COSMOS_MMI_PACKAGE__
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, pHandle, NULL)) != NULL)
	{
		if(pcb->volume_type == 1)
			current_volume = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());
	}
#endif

	return current_volume;
}


VMINT vm_audio_set_volume_type(VMINT type)
{
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	_vm_pcb_t* pcb = NULL;
	VMINT is_cosmos = 0;
	
#ifdef __COSMOS_MMI_PACKAGE__
	is_cosmos = 1;
#endif
	if((type != 1 && type != 0) || (type == 1 && is_cosmos != 1))
	{
		return FALSE;
	}

	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, pHandle, NULL)) != NULL)
	{
		pcb->volume_type = type;
		return TRUE;
	}
	
	return FALSE;
}


void vm_audio_resume_bg_play(void)
{
	if (mdi_audio_is_background_play_suspended() == MMI_TRUE)
	{
		mdi_audio_resume_background_play();
	}
}

void vm_audio_suspend_bg_play(void)
{
	if (mdi_audio_is_background_play_suspended() == MMI_FALSE)
	{
		mdi_audio_suspend_background_play();
	}
}

static void vm_audio_interrupt_callback(VMINT result, void *user_data)
{
	VM_P_HANDLE phandle;

	if (mre_running == FALSE)
		return ;

	if(result == MDI_AUDIO_TERMINATED ) 
	{
		vm_audio_result_callback cb;
		VMINT resid = vm_res_findfirst(-1, VM_RES_TYPE_AUDIO_INTERRUPT);

		while (resid != VM_RES_NOT_FIND)
		{
			phandle = vm_res_get_process_handle(VM_RES_TYPE_AUDIO_INTERRUPT, resid);

			vm_res_get_callback(VM_RES_TYPE_AUDIO_INTERRUPT, resid, (void**)&cb);

			if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
			{
				if (cb != NULL)
				{
					cb((VMINT)user_data, VM_AUDIO_RESULT_INTERRUPT);
				}

				vm_pmng_reset_ctx();
			}

			resid = vm_res_findnext(-1, VM_RES_TYPE_AUDIO_INTERRUPT);
		}
		
		vm_res_findclose(VM_RES_TYPE_AUDIO_INTERRUPT);
	}
}

static VMINT vm_audio_background_callback(VMINT result, void *user_data)
{

	vm_audio_result_callback cb;
	VMINT resid = -1;
	VM_P_HANDLE phandle;

	if (mre_running == FALSE)
		return TRUE;

	resid = vm_res_findfirst(-1, VM_RES_TYPE_AUDIO_INTERRUPT);
	
	while (resid != VM_RES_NOT_FIND)
	{
		phandle = vm_res_get_process_handle(VM_RES_TYPE_AUDIO_INTERRUPT, resid);

		vm_res_get_callback(VM_RES_TYPE_AUDIO_INTERRUPT, resid, (void**)&cb);
	
		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
		{
			if (cb != NULL)
			{
					if(result == MDI_AUDIO_TERMINATED)
					{
						cb((VMINT)user_data, VM_AUDIO_RESULT_INTERRUPT);
					}
					else
					{
					cb((VMINT)user_data, VM_AUDIO_RESULT_INTERRUPT_RESUME);
				}
			}

			vm_pmng_reset_ctx();
		}
		resid = vm_res_findnext(-1, VM_RES_TYPE_AUDIO_INTERRUPT);
	}

	vm_res_findclose(VM_RES_TYPE_AUDIO_INTERRUPT);

	return TRUE;
}

VMINT vm_audio_register_interrupt_callback(vm_audio_result_callback callback)
{
	VM_P_HANDLE handle = 0;
	VMINT res_handle;

	handle = vm_pmng_get_current_handle();
	
	vm_audio_clear_interrupt_callback(handle);

	res_handle =  vm_res_save_data(VM_RES_TYPE_AUDIO_INTERRUPT, NULL, 0, (void*)callback, handle);	
	if (res_handle <= INIT_VALUE)
		return 0;
	
	mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MRE, (mdi_bg_callback)vm_audio_background_callback, (void*)NULL);	
	return handle;
}

void vm_audio_clear_interrupt_callback(VMINT handle)
{
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	VMINT i;
	
	if (pHandle == handle)
	{			
		if ((i = vm_res_findfirst(handle, VM_RES_TYPE_AUDIO_INTERRUPT)) != VM_RES_NOT_FIND)
		{
			mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MRE);	
			vm_res_release_data(VM_RES_TYPE_AUDIO_INTERRUPT, i);
			vm_res_findclose(VM_RES_TYPE_AUDIO_INTERRUPT);
		}				
	}
}

void vm_audio_play_beep(void)
{
	srv_prof_play_tone_with_id(SRV_PROF_TONE_GENERAL_TONE, TONE_GENERAL_BEEP, SRV_PROF_RING_TYPE_ONCE, NULL);
}

VMBOOL vm_audio_is_app_playing(void)
{
	return srv_prof_is_app_playing();
}

void vm_audio_terminate_background_play(void)
{
	mdi_audio_terminate_background_play();
}

VMINT vm_get_mm_sym(VMCHAR* func_name)
{
	return 0;
}

#endif 

