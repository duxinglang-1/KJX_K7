#include "vmswitch.h"

#include "SensorSrvGport.h"
#include "vmsys.h"
#include "vmresmng.h"
#include "vmmod.h"

#define VM_SRV_SENSOR_HANDLE SRV_SENSOR_HANDLE
#define VM_SRV_SENSOR_RESULT SRV_SENSOR_RESULT
#define vm_srv_sensor_type_enum srv_sensor_type_enum

extern VMINT mre_running;

#ifdef __MRE_SAL_SENSOR__

typedef void (*VM_SRV_SENSOR_EVENT_HDLR)(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data); 
static void vm_sensor_notify_process_status(VM_P_HANDLE process_handle, VMINT sys_state)
{
	VMINT resHandle = 0;
	VM_SRV_SENSOR_HANDLE sensor_handle = -1;
	
	switch (sys_state)
	{
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
        while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_SENSOR)) 
            != VM_RES_NOT_FIND)
        {
			srv_sensor_stop_listen(sensor_handle);
			vm_res_release_data(VM_RES_TYPE_SENSOR, resHandle);
			vm_res_findclose(VM_RES_TYPE_SENSOR); 
        }
	default:
		break;
	}
}

static VMINT sensor_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	VMINT resHandle = 0;
	VM_SRV_SENSOR_HANDLE sensor_handle = -1;
	
	switch(event)
	{
	case EVT_MOD_INIT:
		if (vm_res_type_set_notify_callback(VM_RES_TYPE_SENSOR, 
			vm_sensor_notify_process_status) != 0)
		{
			return -1;
		}
		break;
	case EVT_MOD_ACTIVE:
		break;
	case EVT_MOD_INACTIVE:
		break;
	case EVT_MOD_RELEASE:
        while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_SENSOR)) 
            != VM_RES_NOT_FIND)
        {
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_SENSOR, resHandle, &sensor_handle) == VM_RES_OK)
			{
				srv_sensor_stop_listen(sensor_handle);
				vm_res_release_data(VM_RES_TYPE_SENSOR, resHandle);
				vm_res_findclose(VM_RES_TYPE_SENSOR); 
			}
        }
		vm_res_type_set_notify_callback(VM_RES_TYPE_SENSOR, NULL);
		
		break;
	default:
		resHandle = -2;
	}

	return resHandle;
}

VMINT _vm_reg_sensor_module(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("SENSOR MODULE", (MOD_EVT_PROCESS)sensor_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		res = -1;
	}

	return res;
}

static void vm_srv_sensor_event_callback(
            srv_sensor_type_enum            type,
            void                           *sensor_data, 
            void                            *user_data)
{
	VM_SRV_SENSOR_EVENT_HDLR cb;
	VMINT resid = -1;

	if (mre_running == FALSE)
		return;

	if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_SENSOR)) != VM_RES_NOT_FIND)
	{
		VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_SENSOR, resid);
		vm_res_get_callback(VM_RES_TYPE_SENSOR, resid, (void**)&cb);

		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
		{
			if (cb != NULL)
			{
				cb(type, sensor_data, user_data);
			}

			vm_pmng_reset_ctx();
		}
		
		vm_res_findclose(VM_RES_TYPE_SENSOR);
	}
}


VM_SRV_SENSOR_HANDLE vm_srv_sensor_start_listen(vm_srv_sensor_type_enum type, void *option, 
                                                 VM_SRV_SENSOR_EVENT_HDLR event_hdlr, void *user_data)
{
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
	SRV_SENSOR_HANDLE sensor_handle = -1;
	VMINT handle = -1;

	if ((handle = vm_res_save_data(VM_RES_TYPE_SENSOR, NULL, 0, (void*)event_hdlr, process_handle))>= 0)
	{
		sensor_handle = srv_sensor_start_listen(type, option, vm_srv_sensor_event_callback, user_data);;
		if (sensor_handle < SRV_SENSOR_MOTION_SUCCEED )
		{
			vm_res_release_data(VM_RES_TYPE_SENSOR, sensor_handle);
		}
		else
		{
			vm_res_set_mtk_reshandle(VM_RES_TYPE_SENSOR, handle, sensor_handle);
		}
	}
	
	return sensor_handle;
}


VM_SRV_SENSOR_RESULT vm_srv_sensor_stop_listen(VM_SRV_SENSOR_HANDLE handle)
{
	SRV_SENSOR_RESULT result = -1;
	VMINT resHandle = 0;
	VM_SRV_SENSOR_HANDLE sensor_handle = -1;
	
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

	if ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_SENSOR)) != VM_RES_NOT_FIND)
    {
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_SENSOR, resHandle, &sensor_handle) == VM_RES_OK)
		{
			if(sensor_handle == handle)
        	{
        		result = srv_sensor_stop_listen(handle);
			}
			vm_res_release_data(VM_RES_TYPE_SENSOR, resHandle);
            vm_res_findclose(VM_RES_TYPE_SENSOR); 
		}
	}

	return result;
}

VM_SRV_SENSOR_RESULT vm_srv_sensor_enable_mode(VM_SRV_SENSOR_HANDLE handle , VMUINT16 sensor_mode)
{
	SRV_SENSOR_RESULT result = SRV_SENSOR_MOTION_NO_SLOT;
	VMINT resHandle = 0;
	VM_SRV_SENSOR_HANDLE sensor_handle = -1;
	
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

	if ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_SENSOR)) != VM_RES_NOT_FIND)
    {
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_SENSOR, resHandle, &sensor_handle) == VM_RES_OK)
		{
			if(sensor_handle == handle)
        	{
        		result = srv_sensor_motion_enable_mode(handle, sensor_mode);
			}
		}
	}

	return result;	
}

VM_SRV_SENSOR_RESULT vm_srv_sensor_disable_mode(VM_SRV_SENSOR_HANDLE handle, VMUINT16 sensor_mode)
{
	SRV_SENSOR_RESULT result = SRV_SENSOR_MOTION_NO_SLOT;
	VMINT resHandle = 0;
	VM_SRV_SENSOR_HANDLE sensor_handle = -1;
	
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

	if ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_SENSOR)) != VM_RES_NOT_FIND)
    {
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_SENSOR, resHandle, &sensor_handle) == VM_RES_OK)
		{
			if(sensor_handle == handle)
        	{
        		result = srv_sensor_motion_disable_mode(handle, sensor_mode);
			}
		}
	}

	return result;	
}

#endif

VMINT vm_srv_sensor_is_available(vm_srv_sensor_type_enum sensor_type)
{
#ifdef __MRE_SAL_SENSOR__
	return 1;
#else
	return 0;
#endif
	//return srv_sensor_is_available(sensor_type);
}


