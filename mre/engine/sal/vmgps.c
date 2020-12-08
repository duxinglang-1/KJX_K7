#include "vmswitch.h"
#ifdef __MRE_SAL_GPS__
#include "vmsys.h"
#include "vmlog.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmsalgps.h"
#include "vmgps.h"
#include "mdi_datatype.h"
#include "Mdi_gps.h"
#include "vmmacrostub.h"
#include "MMI_trc.h"

#define REG_GPS_MODULE_FAILED -2

typedef enum{
	VM_SAL_GPS_NO_GPS = -3,
	VM_SAL_GPS_UART_HANDLE_WRONG = -2,
	VM_SAL_GPS_MALLOC_FAILED = -1,
	VM_SAL_GPS_OPEN_SUCCESS = 0				
} vm_sal_gps_open_state_enum;

static VMINT16 s_vm_gps_port;	
static VMINT s_vm_sal_gps_parser_enabled_by_mre;

extern VMINT mre_running;

vm_gps_info_struct *s_vm_sal_gps_info = NULL;

static void vm_gps_modual_initialize(void);
static void vm_gps_modual_finialize(void);
static VMINT vm_gps_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);
static void vm_gps_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state);
static VMINT vm_gps_delete_cur_process_res(VM_P_HANDLE process_handle);
static VMINT vm_gps_res_save_data_faild(void);
static void vm_gps_set_parser(void);
static VMINT vm_gps_open_by_cur_process(void);
static void vm_sal_gps_nmea_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length);

VMINT _vm_reg_gps_modual(void)
{
	int res_code = REG_MRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("GPS MODUAL", (MOD_EVT_PROCESS)vm_gps_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_GPS_FAIL_TO_REGISTER_MODULE,res_code);
	}

	return res_code;
}

static VMINT vm_gps_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_gps_modual_initialize();
		break;
	case EVT_MOD_RELEASE:
		vm_gps_modual_finialize();
		break;
	default:
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_GPS_RECV_UNKNOWN_EVT,event);
		return REG_GPS_MODULE_FAILED;
	}

	return REG_MRE_MODULE_SUCCESS;
}

static void vm_gps_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state)
{
	if (sys_state == VM_PMNG_UNLOAD)
	{
		vm_gps_delete_cur_process_res(process_handle);
	}
}


static void vm_gps_modual_initialize(void)
{
	s_vm_sal_gps_parser_enabled_by_mre = FALSE;
	vm_res_type_set_notify_callback(VM_RES_TYPE_GPS, vm_gps_notify_process_handler);
}

static void vm_gps_modual_finialize(void)
{
	if(s_vm_sal_gps_info != NULL)
	{
		mdi_gps_uart_close((VMUINT16)s_vm_gps_port,MDI_GPS_UART_MODE_LOCATION,vm_sal_gps_nmea_callback);
		_vm_kernel_free(s_vm_sal_gps_info);
		s_vm_sal_gps_info = NULL;

		if(s_vm_sal_gps_parser_enabled_by_mre)
		{
			mdi_gps_disable_parser();
			s_vm_sal_gps_parser_enabled_by_mre= FALSE;
		}
	}
}


static void vm_sal_gps_nmea_gga_callback(mdi_gps_nmea_gga_struct *param)
{
	if(param)
	{
		s_vm_sal_gps_info->gga_data.gga_latitude = param->latitude;
		s_vm_sal_gps_info->gga_data.gga_longitude = param->longitude;
		s_vm_sal_gps_info->gga_data.gga_h_precision = param->h_precision;
		s_vm_sal_gps_info->gga_data.gga_altitude = param->altitude;
		s_vm_sal_gps_info->gga_data.gga_unit_of_altitude = param->unit_of_altitude;
		s_vm_sal_gps_info->gga_data.gga_geoidal = param->geoidal;
		s_vm_sal_gps_info->gga_data.gga_unit_of_geoidal = param->unit_of_geoidal;
		s_vm_sal_gps_info->gga_data.gga_gps_age = param->gps_age;
		s_vm_sal_gps_info->gga_data.gga_station_id = param->station_id;
		s_vm_sal_gps_info->gga_data.gga_sat_in_view = param->sat_in_view;
		memcpy(&(s_vm_sal_gps_info->gga_data.gga_utc_time), &(param->utc_time),sizeof(mdi_gps_nmea_utc_time_struct));
		s_vm_sal_gps_info->gga_data.gga_north_south = param->north_south;
		s_vm_sal_gps_info->gga_data.gga_east_west = param->east_west;
		s_vm_sal_gps_info->gga_data.gga_quality = param->quality;
	}
}
static void vm_sal_gps_nmea_rmc_callback(mdi_gps_nmea_rmc_struct *param)
{
	if(param)
	{
		s_vm_sal_gps_info->rmc_data.rmc_latitude = param->latitude;
		s_vm_sal_gps_info->rmc_data.rmc_longitude = param->longitude;
		s_vm_sal_gps_info->rmc_data.rmc_ground_speed = param->ground_speed;
		s_vm_sal_gps_info->rmc_data.rmc_trace_degree = param->trace_degree;
		s_vm_sal_gps_info->rmc_data.rmc_magnetic = param->magnetic;
		memcpy(&(s_vm_sal_gps_info->rmc_data.rmc_utc_time), &(param->utc_time),sizeof(mdi_gps_nmea_utc_time_struct));
		memcpy(&(s_vm_sal_gps_info->rmc_data.rmc_utc_date), &(param->utc_date),sizeof(mdi_gps_nmea_utc_date_struct));
		s_vm_sal_gps_info->rmc_data.rmc_status = param->status;
		s_vm_sal_gps_info->rmc_data.rmc_north_south = param->north_south;
		s_vm_sal_gps_info->rmc_data.rmc_east_west = param->east_west;
		s_vm_sal_gps_info->rmc_data.rmc_magnetic_e_w = param->magnetic_e_w;
		s_vm_sal_gps_info->rmc_data.rmc_cmode = param->cmode;
	}
}
static void vm_sal_gps_nmea_vtg_callback(mdi_gps_nmea_vtg_struct *param)
{
	if(param)
	{
		s_vm_sal_gps_info->vtg_data.vtg_hspeed_knot = param->hspeed_knot;
		s_vm_sal_gps_info->vtg_data.vtg_hspeed_km = param->hspeed_km;
		s_vm_sal_gps_info->vtg_data.vtg_true_heading = param->true_heading;
		s_vm_sal_gps_info->vtg_data.vtg_mag_heading = param->mag_heading;
		s_vm_sal_gps_info->vtg_data.vtg_mode = param->mode;
	}
}
static void vm_sal_gps_nmea_gsa_callback(mdi_gps_nmea_gsa_struct *param)
{
	VMINT i;
	if(param)
	{
		s_vm_sal_gps_info->gsa_data.gsa_pdop = param->pdop;
		s_vm_sal_gps_info->gsa_data.gsa_hdop = param->hdop;
		s_vm_sal_gps_info->gsa_data.gsa_vdop = param->vdop;
		for(i=0;i<VM_GPS_GSA_SATE_MAX;i++)
		{
			s_vm_sal_gps_info->gsa_data.gsa_sate_id[i] = param->sate_id[i];
		}
		s_vm_sal_gps_info->gsa_data.gsa_op_mode = param->op_mode;
		s_vm_sal_gps_info->gsa_data.gsa_fix_mode = param->fix_mode;
	}
	
}
static void vm_sal_gps_nmea_gsv_callback(mdi_gps_nmea_gsv_struct *param)
{
	VMINT i;
	if(param)
	{
		s_vm_sal_gps_info->gsv_data.gsv_msg_sum = param->msg_sum;
		s_vm_sal_gps_info->gsv_data.gsv_msg_index = param->msg_index;
		s_vm_sal_gps_info->gsv_data.gsv_sates_in_view = param->sates_in_view;
		s_vm_sal_gps_info->gsv_data.gsv_max_snr = param->max_snr;
		s_vm_sal_gps_info->gsv_data.gsv_min_snr = param->min_snr;
		s_vm_sal_gps_info->gsv_data.gsv_num_sv_trk = param->num_sv_trk;
		for(i=0;i<MDI_GPS_NMEA_MAX_SVVIEW;i++)
		{
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].sate_id = param->rsv[i].sate_id;
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].elevation = param->rsv[i].elevation;
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].azimuth = param->rsv[i].azimuth;
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].snr = param->rsv[i].snr;
		}
	}
	
}
static void vm_sal_gps_nmea_gll_callback(mdi_gps_nmea_gll_struct *param)
{
	if(param)
	{
		s_vm_sal_gps_info->gll_data.gll_latitude = param->latitude;
		s_vm_sal_gps_info->gll_data.gll_longitude = param->longitude;
		memcpy(&(s_vm_sal_gps_info->gll_data.gll_utc_time), &(param->utc_time),sizeof(mdi_gps_nmea_utc_time_struct));
		s_vm_sal_gps_info->gll_data.gll_north_south = param->north_south;
		s_vm_sal_gps_info->gll_data.gll_east_west = param->east_west;
		s_vm_sal_gps_info->gll_data.gll_status = param->status;
		s_vm_sal_gps_info->gll_data.gll_mode = param->mode;
	}
	
}


static void vm_sal_gps_nmea_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
	if (mre_running == FALSE)
	{
     		return;
  	}
	if(buffer)
	{
		switch(type)
		{
			case MDI_GPS_PARSER_NMEA_GGA:
				vm_sal_gps_nmea_gga_callback((mdi_gps_nmea_gga_struct *)buffer);
				break;
			case MDI_GPS_PARSER_NMEA_RMC:
				vm_sal_gps_nmea_rmc_callback((mdi_gps_nmea_rmc_struct *)buffer);
				break;
			case MDI_GPS_PARSER_NMEA_GSA:
				vm_sal_gps_nmea_gsa_callback((mdi_gps_nmea_gsa_struct *)buffer);
				break;
			case MDI_GPS_PARSER_NMEA_GSV:
				vm_sal_gps_nmea_gsv_callback((mdi_gps_nmea_gsv_struct *)buffer);
				break;    
			case MDI_GPS_PARSER_NMEA_VTG:
				vm_sal_gps_nmea_vtg_callback((mdi_gps_nmea_vtg_struct *)buffer);
				break;        
			case MDI_GPS_PARSER_NMEA_GLL:
				vm_sal_gps_nmea_gll_callback((mdi_gps_nmea_gll_struct *)buffer);
				break;                                   
		}
	}
}

VMINT vm_gps_open(void)
{
	s_vm_gps_port = mdi_get_gps_port();

	if(s_vm_gps_port >= 0)
	{
		if(s_vm_sal_gps_info == NULL)
		{
			VMINT gps_handle;

			if((s_vm_sal_gps_info = (vm_gps_info_struct*)_vm_kernel_malloc(sizeof(vm_gps_info_struct))) == NULL)
			{
				MMI_TRACE(TRACE_GROUP_5,TRC_MRE_GPS_SAL_UART_OPEN_MALLOC_FAIL);
				return VM_SAL_GPS_MALLOC_FAILED;
			}
			
			memset(s_vm_sal_gps_info,0,sizeof(vm_gps_info_struct));
			
			gps_handle = mdi_gps_uart_open(s_vm_gps_port,MDI_GPS_UART_MODE_LOCATION,vm_sal_gps_nmea_callback);
			
			if(gps_handle < VM_SAL_GPS_OPEN_SUCCESS)
			{
				_vm_kernel_free(s_vm_sal_gps_info);
				s_vm_sal_gps_info = NULL;
				return VM_SAL_GPS_UART_HANDLE_WRONG;
			}

			if (vm_gps_res_save_data_faild())
			{
				mdi_gps_uart_close((VMUINT16)s_vm_gps_port,MDI_GPS_UART_MODE_LOCATION,vm_sal_gps_nmea_callback);
				_vm_kernel_free(s_vm_sal_gps_info);
				s_vm_sal_gps_info = NULL;

				return VM_GPS_OPEN_RES_LESS;
			}
			
			vm_gps_set_parser();
						
			return VM_GPS_OPEN_SUCCESS;
		}
		else
		{
			if (vm_gps_res_save_data_faild())
			{
				return VM_GPS_OPEN_RES_LESS;
			}
			
			vm_gps_set_parser();
			
			return VM_GPS_OPEN_ALREADY_OPEN;
		}
	}
	return VM_GPS_OPEN_PORT_NUMBER_WRONG;
}

VMINT vm_gps_close(void)
{
	return vm_gps_delete_cur_process_res(vm_pmng_get_current_handle());
}

vm_gps_gga_data_struct* vm_gps_get_gga_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return &(s_vm_sal_gps_info->gga_data);
	}
	return NULL;
}

vm_gps_rmc_data_struct* vm_gps_get_rmc_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return &(s_vm_sal_gps_info->rmc_data);
	}
	return NULL;
}

vm_gps_gll_data_struct* vm_gps_get_gll_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return &(s_vm_sal_gps_info->gll_data);
	}
	return NULL;
}

vm_gps_gsv_data_struct* vm_gps_get_gsv_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return &(s_vm_sal_gps_info->gsv_data);
	}
	return NULL;
}

vm_gps_gsa_data_struct* vm_gps_get_gsa_data(void )
{
	if (vm_gps_open_by_cur_process())
	{
		return &(s_vm_sal_gps_info->gsa_data);
	}
	return NULL;
}

vm_gps_vtg_data_struct* vm_gps_get_vtg_data(  void )
{
	if (vm_gps_open_by_cur_process())
	{
		return &(s_vm_sal_gps_info->vtg_data);
	}
	return NULL;
}

static VMINT vm_gps_delete_cur_process_res(VM_P_HANDLE process_handle)
{
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_GPS) > 0)
	{
		VMINT res_handle = 0;
		if ((res_handle = vm_res_findfirst(process_handle, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
		{
			vm_res_findclose(VM_RES_TYPE_GPS);
			vm_res_release_data(VM_RES_TYPE_GPS, res_handle);
			
			if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_GPS) <= 0)
			{
				if(s_vm_sal_gps_info != NULL)
				{
					mdi_gps_uart_close((VMUINT16)s_vm_gps_port,MDI_GPS_UART_MODE_LOCATION,vm_sal_gps_nmea_callback);
					_vm_kernel_free(s_vm_sal_gps_info);
					s_vm_sal_gps_info = NULL;

					if(s_vm_sal_gps_parser_enabled_by_mre)
					{
						mdi_gps_disable_parser();
						s_vm_sal_gps_parser_enabled_by_mre= FALSE;
					}
					return VM_GPS_CLOSE_SUCCESS;
				}
			}
			return VM_GPS_CLOSE_STILL_APP_USE_DATA;
		}
		vm_res_findclose(VM_RES_TYPE_GPS);
		return VM_GPS_CLOSE_STILL_APP_USE_DATA;
	}
	return VM_GPS_CLOSE_FAILED;
}

static VMINT vm_gps_res_save_data_faild(void)
{
	if (vm_res_get_data_list_count_by_proecss(vm_pmng_get_current_handle(), VM_RES_TYPE_GPS) <= 0)
	{
		if (vm_res_save_data(VM_RES_TYPE_GPS, NULL, 0, NULL, vm_pmng_get_current_handle()) < 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

static void vm_gps_set_parser(void)
{
	mdi_gps_set_work_port((VMUINT8)s_vm_gps_port);
	
	if(!mdi_gps_is_parser_enabled())
	{
		mdi_gps_enable_parser();
		s_vm_sal_gps_parser_enabled_by_mre = TRUE;
	}
}

static VMINT vm_gps_open_by_cur_process(void)
{
	if(s_vm_sal_gps_info != NULL)
	{
		if (vm_res_get_data_list_count_by_proecss(vm_pmng_get_current_handle(), VM_RES_TYPE_GPS) > 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}
#endif
