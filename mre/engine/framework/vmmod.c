#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__
#include "string.h"
//#include "stdlib.h"

#include "vmsys.h"
#include "vmmod.h"
#include "vmlog.h"

#define MRE_MAX_MODULE_NUM					(32)
#define MRE_SUPPORT_MAX_MODULE_NAME			(20)

/*
  * MRE的模块定义。
  */
typedef struct mre_module_t {
	/**
	 * 模块名称。
	 */
	char name[MRE_SUPPORT_MAX_MODULE_NAME + 1];

	/*
	  * 模块的生命周期事件的处理函数。
	  */
	MOD_EVT_PROCESS liefcircle_process;
} mre_module_t;

/*
  * 存储各个模块名称和cleanup function 和setup function
  * 函数的数据结构。
  */
typedef struct mre_modules_t {
	unsigned int curr_use_num;
	mre_module_t modues[MRE_MAX_MODULE_NUM];
} mre_modules_t;

/*
 * 存放各个模块清理函数和初始化函数的变量。
 */
static mre_modules_t mre_modules;

/**
 * 存放MRE状态的变量。
 */
MRE_MOD_STATUS mre_mod_status = MOD_STATUS_SHUTDOWN;

VMINT _vm_reg_module(VMSTR name, MOD_EVT_PROCESS process)
{
	unsigned int i = 0;

	if (!name || name[0] == 0)
	{
		return MRE_MODULE_NAME_NOT_EXISTS_ERROR;
	}

	for (i = 0; i < mre_modules.curr_use_num; i++)
	{
		if (strncmp(name, mre_modules.modues[i].name, 
			MRE_SUPPORT_MAX_MODULE_NAME) == 0)
		{
			return MRE_MODULE_NAME_CONFLICT_ERROR;
		}
	}

	if (mre_modules.curr_use_num < MRE_MAX_MODULE_NUM)
	{
		memset(mre_modules.modues[mre_modules.curr_use_num].name, 0x00, 
			sizeof(mre_modules.modues[mre_modules.curr_use_num].name));
		
		strncpy(mre_modules.modues[mre_modules.curr_use_num].name, 
			name, MRE_SUPPORT_MAX_MODULE_NAME);
		mre_modules.modues[mre_modules.curr_use_num].liefcircle_process = process;
		mre_modules.curr_use_num++;
	}
	else
	{
		return OVERFLOW_MAX_MODULE_NUM_ERROR;
	}

	return REG_MRE_MODULE_SUCCESS;
}

MRE_MOD_STATUS _vm_get_status(void)
{
	return mre_mod_status;
}

VMINT _vm_notify_modules(MRE_MOD_LIFECIRCLE_EVT event)
{
	int i = 0;

	switch (event)
	{
	case EVT_MOD_INIT:
	case EVT_MOD_ACTIVE:
		for (i = 0; i < (int)mre_modules.curr_use_num; i++)
		{
			vm_log_info("[%s] module will be notified [%d] event.", 
				mre_modules.modues[i].name, event);
			
			if (mre_modules.modues[i].liefcircle_process(event) != 0)
			{
				vm_log_error("%s module is failed to process %d event.", mre_modules.modues[i].name, event);
				if (event == EVT_MOD_INIT)
				{
					int j = i;
					
					while (j >= 0 && j < MRE_MAX_MODULE_NUM)
					{
						mre_modules.modues[j].liefcircle_process(EVT_MOD_RELEASE);
						j--;
					}
					return -1;
				}
			}
		}

		mre_mod_status = MOD_STATUS_RUNNING;
		break;
	case EVT_MOD_INACTIVE:
		for (i = (int)(mre_modules.curr_use_num - 1); i >= 0; i--)
		{
			vm_log_info("[%s] module will be notified [%d] event.", 
				mre_modules.modues[i].name, event);
			
			mre_modules.modues[i].liefcircle_process(event);
		}
		
		mre_mod_status = MOD_STATUS_PAUSE;
		
		break;
	case EVT_MOD_RELEASE:
		for (i = (int)(mre_modules.curr_use_num - 1); i >= 0; i--)
		{
			vm_log_info("[%s] module will be notified [%d] event.", 
				mre_modules.modues[i].name, event);
			
			mre_modules.modues[i].liefcircle_process(event);
		}
		
		mre_mod_status = MOD_STATUS_SHUTDOWN;
		
		break;
	default:
		vm_log_error("{MODULE MANAGER}Unkown module lifecircle event[%d]", event);
	}
			
	return 0;
}
	extern VMINT _vm_reg_timer_module(void);
	extern VMINT _vm_reg_io_module(void);
	extern VMINT _vm_reg_graphic_modual(void);
#ifdef __MRE_SAL_SOCKET__	    
	extern VMINT _vm_reg_tcp_module(void);
	extern VMINT _vm_reg_wifi_loc_module(void);
#endif
#if ( defined(__MRE_SAL_GPS__)) 
	extern VMINT _vm_reg_gps_modual(void);
#endif
	extern VMINT _vm_reg_cell_modual(void);
#ifdef __MRE_SAL_SMS__	
	extern VMINT _vm_reg_sms_module(void);
#endif	
#ifdef __MRE_SAL_MMS__
	extern VMINT _vm_reg_mms_modual(void);
#endif	
	extern VMINT _vm_reg_callout_module(void);
	extern VMINT _vm_reg_audio_module(void);
#if ( defined(__MRE_SAL_BITSTREAM__)) 
	extern VMINT _vm_reg_bitsteam_audio_module(void);
#endif
#if ( defined(__MRE_SAL_VIDEO__)) 
	extern VMINT _vm_reg_video_modual(void);
#endif
	extern VMINT _vm_reg_ime_module(void);
#if ( defined(__MRE_SAL_CAMERA__)) 
	extern VMINT _vm_reg_cam_module(void);
#endif
#ifdef __MRE_LIB_HTTP__       
	extern VMINT _vm_reg_http_module(void);
#endif

#ifdef __MRE_SAL_WPS__       
	extern VMINT _vm_reg_wps_module(void);
#endif

	extern VMINT _vm_reg_statusbar_module(void);
#ifdef __MRE_SAL_PHONEBOOK__	
	extern VMINT _vm_reg_phb_module(void);
#endif	
#ifdef __MRE_SAL_CHE_SHA1__	
	extern VMINT _vm_reg_sha1_modual(void);
#endif
#ifdef __MRE_SAL_CHE_MD5__	
	extern VMINT _vm_reg_md5_modual(void);
#endif
#if ( defined(__MRE_SAL_SENSOR__)) 
	extern VMINT _vm_reg_sensor_module(void);
#endif
#ifdef __MRE_LIB_NETWORK_VIP__    
#ifdef __MRE_LIB_NETWORK_VIP_VG__
	extern VMINT _vm_reg_vip_module(void);
#endif /* __MRE_LIB_NETWORK_VIP_VG__ */
#endif /* __MRE_LIB_NETWORK_VIP__ */
#ifdef __MRE_SAL_BTCM__
    extern VMINT _vm_reg_btcm_module(void);
#endif

#ifdef __MRE_SAL_BTSPP__
    extern VMINT _vm_reg_btspp_module(void);
#endif
    extern VMINT _vm_reg_multi_touch_module(void);
    extern VMINT _vm_reg_fs_async_module(void);

#ifdef __MRE_SAL_DA__
    extern VMINT _vm_reg_da_module(void);
#endif
	extern VMINT _vm_reg_alarm_module(void);

	extern VMINT _vm_reg_selector_module(void);
	extern VMINT _vm_reg_folder_browser_module(void);
	extern VMINT _vm_reg_common_ui_module(void);
#ifdef __MRE_SAL_TLS__
extern VMINT _vm_reg_tls_module(void);
#endif
	extern VMINT _vm_reg_folder_selector_module(void);

typedef VMINT (*vm_reg_module_fn)(void);
static vm_reg_module_fn reg_fn_array[]=
{
	_vm_reg_timer_module,
	 _vm_reg_io_module,
	_vm_reg_graphic_modual,
#ifdef __MRE_SAL_SOCKET__	    
	 _vm_reg_tcp_module,
	_vm_reg_wifi_loc_module,
#endif
#if ( defined(__MRE_SAL_GPS__)) 
	_vm_reg_gps_modual,
#endif
	_vm_reg_cell_modual,
#ifdef __MRE_SAL_SMS__	
	_vm_reg_sms_module,
#endif	
#ifdef __MRE_SAL_MMS__
	_vm_reg_mms_modual,
#endif	
	_vm_reg_callout_module,
	_vm_reg_audio_module,
#if ( defined(__MRE_SAL_BITSTREAM__)) 
	_vm_reg_bitsteam_audio_module,
#endif
#if ( defined(__MRE_SAL_VIDEO__)) 
	_vm_reg_video_modual,
#endif
	_vm_reg_ime_module,
#if ( defined(__MRE_SAL_CAMERA__)) 
	_vm_reg_cam_module,
#endif
#ifdef __MRE_LIB_HTTP__       
	_vm_reg_http_module,
#endif
	
#ifdef __MRE_SAL_WPS__       
	_vm_reg_wps_module,
#endif
	
	_vm_reg_statusbar_module,
#ifdef __MRE_SAL_PHONEBOOK__	
	_vm_reg_phb_module,
#endif	
#ifdef __MRE_SAL_CHE_SHA1__	
	_vm_reg_sha1_modual,
#endif
#ifdef __MRE_SAL_CHE_MD5__	
	_vm_reg_md5_modual,
#endif
#if ( defined(__MRE_SAL_SENSOR__)) 
	_vm_reg_sensor_module,
#endif
#ifdef __MRE_LIB_NETWORK_VIP__    
#ifdef __MRE_LIB_NETWORK_VIP_VG__
	 _vm_reg_vip_module,
#endif /* __MRE_LIB_NETWORK_VIP_VG__ */
#endif /* __MRE_LIB_NETWORK_VIP__ */
#ifdef __MRE_SAL_BTCM__
	 _vm_reg_btcm_module,
#endif
	
#ifdef __MRE_SAL_BTSPP__
	_vm_reg_btspp_module,
#endif
	_vm_reg_multi_touch_module,
	_vm_reg_fs_async_module,
	
#ifdef __MRE_SAL_DA__
	 _vm_reg_da_module,
#endif
	_vm_reg_alarm_module,
	
	 _vm_reg_selector_module,
	 _vm_reg_folder_browser_module,
	_vm_reg_common_ui_module,
#ifdef __MRE_SAL_TLS__
	_vm_reg_tls_module,
#endif
	_vm_reg_folder_selector_module,
};
VMINT _vm_reg_modules(void)
{    
	int res = REG_MRE_MODULE_SUCCESS;
	int i;
	for(i=0;i<sizeof(reg_fn_array)/sizeof(vm_reg_module_fn);i++)
	{
		if((res = reg_fn_array[i]())!=REG_MRE_MODULE_SUCCESS)
			break;
	}
	return res;
}
void _vm_initizlize_module_manager(void)
{
	//mre_modules.curr_use_num = 0;
	//memset(mre_modules.modues, 0x00, MRE_MAX_MODULE_NUM * sizeof(mre_module_t));
	memset(&mre_modules,0,sizeof(mre_modules));
}

void _vm_destory_module_manager(void)
{
	//mre_modules.curr_use_num = 0;
	//memset(mre_modules.modues, 0x00, MRE_MAX_MODULE_NUM * sizeof(mre_module_t));
	_vm_initizlize_module_manager();
}
#endif

