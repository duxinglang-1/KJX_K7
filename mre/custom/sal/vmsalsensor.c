#include "vmswitch.h"
#ifdef __MRE_SAL_SENSOR__


#include "Fat_fs.h"
#include "SettingDefs.h"
#include "CommonScreens.h"
#include "lcd_sw_rnd.h"
#include "lcd_if.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "kal_release.h"
#include "SettingProfileEnum.h"
#include "gpiosrvgprot.h"
#include "vmsys.h"
#include "math.h"
#include "vmopt.h"
#include "vmextsensor.h"
#include "vmlog.h"
#include "vm_freescale_MMA7455L.h"
#include "SensorSrvGport.h"
#include "MMI_trc.h"
#ifdef __MMI_MOTION_APP__
static VMINT start_ext_sensor(void);
static VMINT stop_ext_sensor(void);
static VMINT set_numeric_option_ext_sensor(const VMSTR control_name, 
	VMINT opt_value);

static g_sensor_data_t gData = {0, 0, 0};
static SRV_SENSOR_HANDLE g_s_handle = -1;
static VMINT freeScaleHandle = 0;
static VM_MOTION_SENSITIVE_ENUM motion_sensitive = MOTION_SENSITIVE_HIGH;

#endif


VMINT vm_reg_all_ext_sensors(void)
{
#ifdef __MMI_MOTION_APP__
	vm_core_scb_t scb = 
		{
			USE_SENSOR_NAME, start_ext_sensor, stop_ext_sensor, 
			set_numeric_option_ext_sensor, NULL
		};
	
	if (vm_register_ext_sensor(&freeScaleHandle, &scb) 
		!= VM_EXT_SENSOR_SUCCESS)
	{
		//vm_log_error("Failed to reg \"%s\" sensor.", USE_SENSOR_NAME);
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_SENSOR_SAL_REG_FAIL,USE_SENSOR_NAME);
		return -1;
	}

	g_s_handle = -1;
	motion_sensitive = MOTION_SENSITIVE_HIGH;
#endif

	return 0;
}

#ifdef __MMI_MOTION_APP__
#define MTK_ONE_G_VALUE			(1000)





void vm_motion_tilt_detail_callback(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
	srv_sensor_motion_tilt_struct* detail_data = (srv_sensor_motion_tilt_struct*)sensor_data;
	if(detail_data == NULL)
	{
		//add log
		return;
	}
	else
	{

		gData.x = -((detail_data->acc.x * ONE_G_VALUE)  / MTK_ONE_G_VALUE);
		gData.y = ((detail_data->acc.y * ONE_G_VALUE)  / MTK_ONE_G_VALUE);
		gData.z = -((detail_data->acc.y * ONE_G_VALUE)  / MTK_ONE_G_VALUE);

	vm_notify_data_by_ext_sensor(freeScaleHandle, 
		&gData, sizeof(g_sensor_data_t));
		
	}
	
}
                                                                              
static VMINT start_ext_sensor(void)
{
	VMINT mtk_gsensor_sensitive = SRV_SENSOR_MOTION_SHAKE_STRONG;

	switch (motion_sensitive)
	{
	case MOTION_SENSITIVE_LOW:
		mtk_gsensor_sensitive = SRV_SENSOR_MOTION_SHAKE_WEAK;
		break;
	case MOTION_SENSITIVE_NORMAL:
		mtk_gsensor_sensitive = SRV_SENSOR_MOTION_SHAKE_MEDIUM;
		break;
	default:
		mtk_gsensor_sensitive = SRV_SENSOR_MOTION_SHAKE_STRONG;
		break;
	}

	if (g_s_handle < 0)
	{
		if ((g_s_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_TILT, 
			0, vm_motion_tilt_detail_callback, NULL)) >= 0)
		{
			return 0;
		}
	}
	return -1;
}

static VMINT stop_ext_sensor(void)
{
	if (g_s_handle >= 0)
	{
		srv_sensor_stop_listen(g_s_handle);
		g_s_handle = -1;

		return 0;
	}

	return -1;
}

static VMINT set_numeric_option_ext_sensor(const VMSTR control_name, 
	VMINT opt_value)
{
	if (control_name == NULL || strlen(control_name) == 0 
		|| strcmp(control_name, MOTION_SENSITIVE) != 0 
		||  opt_value < MOTION_SENSITIVE_LOW 
		|| opt_value > MOTION_SENSITIVE_HIGH)
	{
		return -1;
	}
	
	motion_sensitive = opt_value;
	return 0;
}
#endif
#endif
