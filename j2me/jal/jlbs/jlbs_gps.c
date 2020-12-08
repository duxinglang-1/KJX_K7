/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * jlbs_gps.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifdef SUPPORT_JSR_179
/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "jal.h"
#include "jam_internal.h"
#include "jvm_internal.h"
#include "jam_mvm_manager.h"
#include "mmi_include.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "GPSSetting.h"
#include "GPSGProt.h"

extern kal_mutexid g_jam_gps_mutex;
extern kal_eventgrpid g_java_event_group_1;

static kal_uint32 jlbs_gps_open_counter = 0;
static kal_int16 jlbs_gps_handle = -1;
static kal_uint8 jlbs_gps_type = JLBS_GPS_TYPE_END;
static kal_uint8 jlbs_gps_usage_type = JLBS_GPS_USAGE_END;
static void (*jlbs_gps_callback)(void) = NULL;
static jlbs_gps_nmea_data_struct *jlbs_gps_nmea_location_data = NULL;
static kal_char *jlbs_gps_nmea_raw_data = NULL;
static kal_int16 jlbs_gps_nmea_raw_data_sentence_length[JLBS_GPS_NMEA_END];
static kal_uint8 jlbs_gps_nmea_raw_data_read_start;
static mdi_gps_nmea_utc_date_struct jlbs_gps_utc_date;
static kal_int32 jlbs_gps_agps_result = -1;
static kal_uint8 jlbs_gps_is_gps_on = MMI_GPS_RECEIVER_OFF;
static kal_uint8 jlbs_gps_selected_gps_type = 0;


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_get_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jlbs_gps_get_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jlbs_gps_is_gps_on = mmi_gps_get_receiver_setting();
    jlbs_gps_selected_gps_type = (kal_uint8) mmi_gps_setting_get_is_agps_on();
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_callback_hanlder
 * DESCRIPTION
 *  gps callback hanlder function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jlbs_gps_callback_hanlder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jlbs_gps_callback != NULL)
    {
        (*jlbs_gps_callback)();
    }
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_send_ilm
 * DESCRIPTION
 * PARAMETERS
 *  local_para_ptr      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jlbs_gps_send_ilm(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    java_send_msg_from_active_mod(MOD_MMI,MMI_J2ME_SAP,MSG_ID_MMI_JAVA_SET_AGPS_REQ,local_para_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_translate_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint64 jlbs_gps_translate_timestamp(kal_int8 hour, kal_int8 minute, kal_int8 second, kal_int8 millisecond)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint64 timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	timestamp = getJulianOffsetTimeInMillis(jlbs_gps_utc_date.year + 2000,   /* year */
									   		jlbs_gps_utc_date.month - 1,	/* month */
									   		jlbs_gps_utc_date.day, /* day */
									   		hour, /* hour */
									   		minute, /* minute */
									  		second, /* second */
									   		millisecond);

	/* adjust the timezone from GMT - local time offset, the TimeZone class will add local time offset */
    timestamp += (kal_uint64) (((int)(mmi_dt_get_tz() * 60)) * 60 * 1000);

	return timestamp;
}



/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_nmea_gga_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jlbs_gps_nmea_gga_handler(mdi_gps_nmea_gga_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_gga_struct *gga_data = param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(g_jam_gps_mutex);
	
    if (!jlbs_gps_nmea_location_data)
    {
    	kal_give_mutex(g_jam_gps_mutex);
        return;
    }

	sprintf(_kvmLogStr,"jlbs_gps_nmea_gga_handler: state = %d \n", gga_data->quality);
    Kprintf();

	if (gga_data->quality != 0)
	{
		jlbs_gps_nmea_location_data->latitude = gga_data->latitude;
		jlbs_gps_nmea_location_data->longitude = gga_data->longitude;
		jlbs_gps_nmea_location_data->altitude = gga_data->altitude;
		jlbs_gps_nmea_location_data->horizontalAccuracy = gga_data->h_precision;
		jlbs_gps_nmea_location_data->timestamp = (double)jlbs_gps_translate_timestamp(gga_data->utc_time.hour, /* hour */
	                                 												gga_data->utc_time.minute, /* minute */
	                                 												gga_data->utc_time.second, /* second */
	                                 												gga_data->utc_time.millisecond);
		jlbs_gps_callback_hanlder();
	}

	kal_give_mutex(g_jam_gps_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_nmea_rmc_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jlbs_gps_nmea_rmc_handler(mdi_gps_nmea_rmc_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_rmc_struct *rmc_data = param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(g_jam_gps_mutex);
    if (!jlbs_gps_nmea_location_data)
    {
    	kal_give_mutex(g_jam_gps_mutex);
        return;
    }

	sprintf(_kvmLogStr,"jlbs_gps_nmea_rmc_handler: state = %c \n", rmc_data->status);
    Kprintf();

	if (rmc_data->status == 'A')
	{
	    jlbs_gps_nmea_location_data->latitude = rmc_data->latitude;
	    jlbs_gps_nmea_location_data->longitude = rmc_data->longitude;
	    jlbs_gps_nmea_location_data->speed = rmc_data->ground_speed; 
	    jlbs_gps_nmea_location_data->course = rmc_data->trace_degree; 

		jlbs_gps_utc_date.year = rmc_data->utc_date.year;
		jlbs_gps_utc_date.month= rmc_data->utc_date.month;
		jlbs_gps_utc_date.day = rmc_data->utc_date.day;

		jlbs_gps_nmea_location_data->timestamp = (double)jlbs_gps_translate_timestamp(rmc_data->utc_time.hour, /* hour */
	                                 												rmc_data->utc_time.minute, /* minute */
	                                 												rmc_data->utc_time.second, /* second */
	                                 												rmc_data->utc_time.millisecond);
		jlbs_gps_callback_hanlder();
	}
	kal_give_mutex(g_jam_gps_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_nmea_gsa_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jlbs_gps_nmea_gsa_handler(mdi_gps_nmea_gsa_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_gsa_struct *gsa_data = param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(g_jam_gps_mutex);
    if (!jlbs_gps_nmea_location_data)
    {
    	kal_give_mutex(g_jam_gps_mutex);
        return;
    }

	sprintf(_kvmLogStr,"jlbs_gps_nmea_gsa_handler: state = %d \n", gsa_data->fix_mode);
    Kprintf();

	if (gsa_data->fix_mode != 1)
	{
		jlbs_gps_nmea_location_data->horizontalAccuracy= gsa_data->hdop;
    	jlbs_gps_nmea_location_data->verticalAccuracy= gsa_data->vdop;
		jlbs_gps_callback_hanlder();
	}
	kal_give_mutex(g_jam_gps_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_nmea_gll_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jlbs_gps_nmea_gll_handler(mdi_gps_nmea_gll_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_gps_nmea_gll_struct *gll_data = param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(g_jam_gps_mutex);
    if (!jlbs_gps_nmea_location_data)
    {
    	kal_give_mutex(g_jam_gps_mutex);
        return;
    }

	sprintf(_kvmLogStr,"jlbs_gps_nmea_gll_handler: state = %c \n", gll_data->status);
    Kprintf();

	if (gll_data->status == 'A')
	{
		jlbs_gps_nmea_location_data->latitude = gll_data->latitude;
	    jlbs_gps_nmea_location_data->longitude = gll_data->longitude;
		jlbs_gps_nmea_location_data->timestamp = (double)jlbs_gps_translate_timestamp(gll_data->utc_time.hour, /* hour */
	                                 												gll_data->utc_time.minute, /* minute */
	                                 												gll_data->utc_time.second, /* second */
	                                 												gll_data->utc_time.millisecond);
		jlbs_gps_callback_hanlder();
	}
	kal_give_mutex(g_jam_gps_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_nmea_raw_data_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jlbs_gps_nmea_raw_data_handler(const U8 *buffer, U32 length)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_char *start_ptr = NULL;
	kal_uint8 nmea_type = JLBS_GPS_NMEA_END;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_take_mutex(g_jam_gps_mutex);
    if (!jlbs_gps_nmea_raw_data)
    {
    	kal_give_mutex(g_jam_gps_mutex);
        return;
    }
	
    if (strncmp(buffer, "$GPGGA", 6) == 0)
    {
    	sprintf(_kvmLogStr,"jlbs_gps_nmea_raw_data_handler: GPGGA, length = %d \n", length);
    	Kprintf();
    	start_ptr = &jlbs_gps_nmea_raw_data[JLBS_GPS_NMEA_GPGGA * JLBS_GPS_MAX_RAW_DATA_LEN];
		nmea_type = JLBS_GPS_NMEA_GPGGA;
    }
	else if (strncmp(buffer, "$GPRMC", 6) == 0)
    {
    	sprintf(_kvmLogStr,"jlbs_gps_nmea_raw_data_handler: GPRMC, length = %d \n", length);
    	Kprintf();
    	start_ptr = &jlbs_gps_nmea_raw_data[JLBS_GPS_NMEA_GPRMC * JLBS_GPS_MAX_RAW_DATA_LEN];
		nmea_type = JLBS_GPS_NMEA_GPRMC;
    }
	else if (strncmp(buffer, "$GPGSA", 6) == 0)
    {
    	sprintf(_kvmLogStr,"jlbs_gps_nmea_raw_data_handler: GPGSA, length = %d \n", length);
    	Kprintf();
    	start_ptr = &jlbs_gps_nmea_raw_data[JLBS_GPS_NMEA_GPGSA * JLBS_GPS_MAX_RAW_DATA_LEN];
		nmea_type = JLBS_GPS_NMEA_GPGSA;
    }
	else if (strncmp(buffer, "$GPGLL", 6) == 0)
    {
    	sprintf(_kvmLogStr,"jlbs_gps_nmea_raw_data_handler: GPGLL, length = %d \n", length);
    	Kprintf();
    	start_ptr = &jlbs_gps_nmea_raw_data[JLBS_GPS_NMEA_GPGLL * JLBS_GPS_MAX_RAW_DATA_LEN];
		nmea_type = JLBS_GPS_NMEA_GPGLL;
    }
	else if (strncmp(buffer, "$GPVTG", 6) == 0)
	{
		sprintf(_kvmLogStr,"jlbs_gps_nmea_raw_data_handler: GPVTG, length = %d \n", length);
		Kprintf();
		start_ptr = &jlbs_gps_nmea_raw_data[JLBS_GPS_NMEA_GPVTG * JLBS_GPS_MAX_RAW_DATA_LEN];
		nmea_type = JLBS_GPS_NMEA_GPVTG;
	}
    else if (strncmp(buffer, "$GPGSV", 6) == 0)
	{
		sprintf(_kvmLogStr,"jlbs_gps_nmea_raw_data_handler: GPGSV, length = %d \n", length);
		Kprintf();
		start_ptr = &jlbs_gps_nmea_raw_data[JLBS_GPS_NMEA_GPGSV * JLBS_GPS_MAX_RAW_DATA_LEN];
		nmea_type = JLBS_GPS_NMEA_GPGSV;
	}

	if (start_ptr && nmea_type != JLBS_GPS_NMEA_END)
	{
		strncpy(start_ptr, (CHAR *)buffer, length);
		start_ptr[length] = 0;
		jlbs_gps_nmea_raw_data_sentence_length[nmea_type] = length;
		sprintf(_kvmLogStr,"jlbs_gps_nmea_raw_data_handler: copy end: %s \n", start_ptr);
    	Kprintf();
		jlbs_gps_callback_hanlder();
	}
	kal_give_mutex(g_jam_gps_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_gps_event_callback
 * DESCRIPTION
 *  gps callback function
 * PARAMETERS
 *  type - type of NMEA data
 *  buffer - content of NMEA data.
 *  length - length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void jlbs_gps_gps_event_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_FUNC, FUNC_J2ME_GPS_CALLBACK, (int)type);

	if (jlbs_gps_open_counter == 0)
	{
		return;
	}
	
    switch(type)
    {
        case MDI_GPS_PARSER_NMEA_GGA:
            jlbs_gps_nmea_gga_handler(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_RMC:
            jlbs_gps_nmea_rmc_handler(buffer);
            break;
        case MDI_GPS_PARSER_NMEA_GSA:
            jlbs_gps_nmea_gsa_handler(buffer);
            break;
		case MDI_GPS_PARSER_NMEA_GLL:
			jlbs_gps_nmea_gll_handler(buffer);
			break;
        case MDI_GPS_PARSER_RAW_DATA:
            jlbs_gps_nmea_raw_data_handler(buffer, length);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_agps_event_callback
 * DESCRIPTION
 *  agps callback function
 * PARAMETERS
 *  type - type of NMEA data
 *  buffer - content of NMEA data.
 *  length - length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void jlbs_gps_agps_event_callback(S32 type, void *buffer, U32 length)
{
    jlbs_gps_gps_event_callback((mdi_gps_parser_info_enum)type, buffer, length);
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_open
 * DESCRIPTION
 *  open gps connection
 * PARAMETERS
 *
 * RETURNS
 *  port number - open success
 *  jlbs_gps_result_enum - open fail
 *****************************************************************************/
kal_int32 jlbs_gps_open(kal_uint8 type, void (*callback_ptr)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int ret = -1;
	int i = 0;
	kal_uint32 event_group;
	jlbs_gps_set_agps_req_struct *p = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_FUNC, FUNC_J2ME_GPS_OPEN, jlbs_gps_handle, type, callback_ptr, jlbs_gps_selected_gps_type);

    if (jlbs_gps_is_gps_on != MMI_GPS_RECEIVER_YES)
    {
        return JLBS_GPS_SERVICE_OFF;
    }

	if (jlbs_gps_open_counter > 0)
	{
		sprintf(_kvmLogStr,"jlbs_gps_open: Already opened, counter=%d \n", (int)jlbs_gps_open_counter);
    	Kprintf();
        jlbs_gps_open_counter++;
		return jlbs_gps_handle;
	}

	if (type != JLBS_GPS_TYPE_LOCATION && type != JLBS_GPS_TYPE_RAW_DATA)
	{
		return JLBS_GPS_ERROR;
	}

#if defined(__AGPS_CONTROL_PLANE__)
	if ((srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        || srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        || srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        || srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        ) && srv_mode_switch_is_network_service_available())
	{
		if (jlbs_gps_selected_gps_type == JLBS_GPS_USAGE_AGPS_CONTROL_PLANE)
		{
			sprintf(_kvmLogStr,"jlbs_gps_open: __AGPS_CONTROL_PLANE__ \n");
		    Kprintf();
			
			p = (jlbs_gps_set_agps_req_struct*) construct_local_para(sizeof(jlbs_gps_set_agps_req_struct),TD_CTRL);

			if (type == JLBS_GPS_TYPE_LOCATION)
			{
				p->mode = MDI_GPS_UART_MODE_LOCATION;
			}
			else
			{
				p->mode = MDI_GPS_UART_MODE_RAW_DATA;
			}
			p->handle = 0;
			p->op_type = 0;
			p->agps_type = JLBS_GPS_USAGE_AGPS_CONTROL_PLANE;
			p->update_callback = (void*)jlbs_gps_agps_event_callback;

			jlbs_gps_agps_result = -1;
			jlbs_gps_send_ilm(p);
			kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_LBS_WAITING_RESULT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
			ret = jlbs_gps_agps_result;
			
			sprintf(_kvmLogStr,"jlbs_gps_open: return = %d, handle = %d \n", ret, jlbs_gps_handle);
		    Kprintf();
			
			if (ret == 0)
			{
				jlbs_gps_usage_type = JLBS_GPS_USAGE_AGPS_CONTROL_PLANE;
			}
		}
	}
#endif	/* __AGPS_CONTROL_PLANE__ */
	
	if (jlbs_gps_usage_type == JLBS_GPS_USAGE_END && ret < 0)
	{
		if ((jlbs_gps_handle = mdi_get_gps_port()) == -1)
		{
			sprintf(_kvmLogStr,"jlbs_gps_open: mdi_get_gps_port() = -1 \n");
	    	Kprintf();
			return JLBS_GPS_ERROR;
		}

		sprintf(_kvmLogStr,"jlbs_gps_open: gps port = %d \n", jlbs_gps_handle);
	    Kprintf();
	}

#if defined(__AGPS_USER_PLANE__)
    if ((srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        || srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        || srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        || srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        ) && srv_mode_switch_is_network_service_available())
	{
		if (jlbs_gps_selected_gps_type == JLBS_GPS_USAGE_AGPS_USER_PLANE && ret < 0)
		{
			sprintf(_kvmLogStr,"jlbs_gps_open: __AGPS_USER_PLANE__ \n");
	    	Kprintf();

			p = (jlbs_gps_set_agps_req_struct*) construct_local_para(sizeof(jlbs_gps_set_agps_req_struct),TD_CTRL);
			
			if (type == JLBS_GPS_TYPE_LOCATION)
			{
				p->mode = MDI_GPS_UART_MODE_LOCATION;
			}
			else
			{
				p->mode = MDI_GPS_UART_MODE_RAW_DATA;
			}
			p->handle = jlbs_gps_handle;
			p->op_type = 0;
			p->agps_type = JLBS_GPS_USAGE_AGPS_USER_PLANE;
			p->update_callback = (void*)jlbs_gps_gps_event_callback;
			
			jlbs_gps_agps_result = -1;
			jlbs_gps_send_ilm(p);
			kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_LBS_WAITING_RESULT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
			ret = jlbs_gps_agps_result;
			
			sprintf(_kvmLogStr,"jlbs_gps_open: return = %d \n", ret);
		    Kprintf();

			if (ret == 0)
			{
				jlbs_gps_usage_type = JLBS_GPS_USAGE_AGPS_USER_PLANE;
			}
		}
	}
#endif /* __AGPS_USER_PLANE__ */

	if (jlbs_gps_usage_type == JLBS_GPS_USAGE_END && ret < 0) 
	{	
		sprintf(_kvmLogStr,"jlbs_gps_open: mdi_gps_uart_open \n");
    	Kprintf();
		if (type == JLBS_GPS_TYPE_LOCATION)
		{
			ret = (int)mdi_gps_uart_open(jlbs_gps_handle, MDI_GPS_UART_MODE_LOCATION, jlbs_gps_gps_event_callback);
		}
		else
		{
			ret = (int)mdi_gps_uart_open(jlbs_gps_handle, MDI_GPS_UART_MODE_RAW_DATA, jlbs_gps_gps_event_callback);
		}

		sprintf(_kvmLogStr,"jlbs_gps_open: mdi_gps_uart_open = %d \n", ret);
	    Kprintf();

		if (ret == 0 || ret == 1)
		{
			jlbs_gps_usage_type = JLBS_GPS_USAGE_GPS;
		}
	}

	if (ret < 0)
	{
		jlbs_gps_handle = -1;
		return JLBS_GPS_ERROR;
	}

	kal_take_mutex(g_jam_gps_mutex);
	if (type == JLBS_GPS_TYPE_LOCATION)
	{
		if (jlbs_gps_nmea_location_data)
		{
			jvm_free(jlbs_gps_nmea_location_data);
			jlbs_gps_nmea_location_data = NULL;
		}
		jlbs_gps_nmea_location_data = (jlbs_gps_nmea_data_struct*)jvm_malloc(sizeof(jlbs_gps_nmea_data_struct));
		if (!jlbs_gps_nmea_location_data)
		{
			jlbs_gps_handle = -1;
			kal_give_mutex(g_jam_gps_mutex);
			return JLBS_GPS_OUT_OF_MEMORY;
		}
		jlbs_gps_utc_date.year = 4;
		jlbs_gps_utc_date.month = 1;
		jlbs_gps_utc_date.day = 1;
	}
	else
	{
		if (jlbs_gps_nmea_raw_data)
		{
			jvm_free(jlbs_gps_nmea_raw_data);
			jlbs_gps_nmea_raw_data = NULL;
		}
		jlbs_gps_nmea_raw_data = (kal_char*)jvm_malloc(JLBS_GPS_NMEA_END * JLBS_GPS_MAX_RAW_DATA_LEN);
		if (!jlbs_gps_nmea_raw_data)
		{
			jlbs_gps_handle = -1;
			kal_give_mutex(g_jam_gps_mutex);
			return JLBS_GPS_OUT_OF_MEMORY;
		}
		memset(jlbs_gps_nmea_raw_data, 0, JLBS_GPS_NMEA_END * JLBS_GPS_MAX_RAW_DATA_LEN);
		for (; i < JLBS_GPS_NMEA_END; i++)
		{
			jlbs_gps_nmea_raw_data_sentence_length[i] = 0;
		}
		jlbs_gps_nmea_raw_data_read_start = JLBS_GPS_NMEA_GPGGA;
	}

	jlbs_gps_type = type;
	jlbs_gps_callback = callback_ptr;
	jlbs_gps_open_counter++;
		
	kal_give_mutex(g_jam_gps_mutex);

	sprintf(_kvmLogStr,"jlbs_gps_open: open successfully \n");
    Kprintf();

    return jlbs_gps_handle;
}

/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_close
 * DESCRIPTION
 *  close gps connection
 * PARAMETERS
 *  handle - gps handle to close
 * RETURNS
 *****************************************************************************/
kal_int32 jlbs_gps_close(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int ret = -1;
	int i = 0;
	kal_uint32 event_group;
	jlbs_gps_set_agps_req_struct *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_FUNC, FUNC_J2ME_GPS_CLOSE, jlbs_gps_handle, handle);

	if (jlbs_gps_open_counter == 0)
	{
		return JLBS_GPS_ERROR;
	}
	
	ASSERT(handle == jlbs_gps_handle);

    if (jlbs_gps_open_counter > 1)
    {
        jlbs_gps_open_counter--;
        return JLBS_GPS_OK;
    }
	
#if defined(__AGPS_CONTROL_PLANE__)
	if (jlbs_gps_usage_type == JLBS_GPS_USAGE_AGPS_CONTROL_PLANE)
	{
		p = (jlbs_gps_set_agps_req_struct*) construct_local_para(sizeof(jlbs_gps_set_agps_req_struct),TD_CTRL);

		p->agps_type = JLBS_GPS_USAGE_AGPS_CONTROL_PLANE;
		p->handle = jlbs_gps_handle;
		p->op_type = 1;
		
		jlbs_gps_agps_result = -1;
		jlbs_gps_send_ilm(p);
		kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_LBS_WAITING_RESULT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		ret = jlbs_gps_agps_result;
		
		sprintf(_kvmLogStr,"jlbs_gps_close: CONTROL_PLANE return = %d \n", ret);
    	Kprintf();
	}
#endif /* __AGPS_CONTROL_PLANE__ */

#if defined(__AGPS_USER_PLANE__)
	if (jlbs_gps_usage_type == JLBS_GPS_USAGE_AGPS_USER_PLANE && ret < 0)
	{
		p = (jlbs_gps_set_agps_req_struct*) construct_local_para(sizeof(jlbs_gps_set_agps_req_struct),TD_CTRL);
		
		if (jlbs_gps_type == JLBS_GPS_TYPE_LOCATION)
		{
			p->mode = MDI_GPS_UART_MODE_LOCATION;
		}
		else
		{
			p->mode = MDI_GPS_UART_MODE_RAW_DATA;
		}
		

		p->agps_type = JLBS_GPS_USAGE_AGPS_USER_PLANE;
		p->handle = jlbs_gps_handle;
		p->op_type = 1;
		p->update_callback = (void*)jlbs_gps_gps_event_callback;
		
		jlbs_gps_agps_result = -1;
		jlbs_gps_send_ilm(p);
		kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_LBS_WAITING_RESULT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
		ret = jlbs_gps_agps_result;
		
		sprintf(_kvmLogStr,"jlbs_gps_close: USER_PLANE return = %d \n", ret);
    	Kprintf();
	}
#endif /* __AGPS_USER_PLANE__ */

	if (jlbs_gps_usage_type == JLBS_GPS_USAGE_GPS && ret < 0)
	{
		if (jlbs_gps_type == JLBS_GPS_TYPE_LOCATION)
		{
			ret = (int)mdi_gps_uart_close(jlbs_gps_handle, MDI_GPS_UART_MODE_LOCATION, jlbs_gps_gps_event_callback);
		}
		else
		{	
			ret = (int)mdi_gps_uart_close(jlbs_gps_handle, MDI_GPS_UART_MODE_RAW_DATA, jlbs_gps_gps_event_callback);
		}
		
		sprintf(_kvmLogStr,"jlbs_gps_close: mdi_gps_uart_close = %d \n", ret);
    	Kprintf();
	}

	if (ret < 0)
	{
		return JLBS_GPS_ERROR;
	}

	kal_take_mutex(g_jam_gps_mutex);
	if (jlbs_gps_type == JLBS_GPS_TYPE_LOCATION)
	{
		if (jlbs_gps_nmea_location_data)
		{
			jvm_free(jlbs_gps_nmea_location_data);
		}
		jlbs_gps_nmea_location_data = NULL;
	}
	else
	{
		if (jlbs_gps_nmea_raw_data)
		{
			jvm_free(jlbs_gps_nmea_raw_data);
		}
		jlbs_gps_nmea_raw_data = NULL;
		for (; i < JLBS_GPS_NMEA_END; i++)
		{
			jlbs_gps_nmea_raw_data_sentence_length[i] = 0;
		}
		jlbs_gps_nmea_raw_data_read_start = JLBS_GPS_NMEA_GPGGA;
	}

	jlbs_gps_handle = -1;
	jlbs_gps_type = JLBS_GPS_TYPE_END;
	jlbs_gps_usage_type = JLBS_GPS_USAGE_END;
	jlbs_gps_callback = NULL;
	jlbs_gps_open_counter = 0;
	
	kal_give_mutex(g_jam_gps_mutex);

	return JLBS_GPS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_getRawData
 * DESCRIPTION
 *  get raw data from gps receiver
 * PARAMETERS
 *  port - opened gps handle
 *  buffer - allocated buffer for raw data.
 *  length - length of the buffer
 * RETURNS
 *  readbytes - total bytes read from gps receiver.
 *****************************************************************************/
kal_int32 jlbs_gps_getRawData(kal_int32 handle, kal_char *buffer, kal_uint16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i;
	int index = jlbs_gps_nmea_raw_data_read_start; 
	int total_len = 0;
	kal_char *pos = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_FUNC, FUNC_J2ME_GPS_GET_RAW_DATA, jlbs_gps_handle, handle, buffer, (int)length);
	
	kal_take_mutex(g_jam_gps_mutex);
	if (handle != jlbs_gps_handle || !buffer || length <= 0)
	{
		kal_give_mutex(g_jam_gps_mutex);
		return JLBS_GPS_ERROR;
	}

	if (length < jlbs_gps_nmea_raw_data_sentence_length[index])
	{
		kal_give_mutex(g_jam_gps_mutex);
		return total_len;
	}

	memset(buffer, 0, length);
	pos = buffer;

	for (i = 0; i < JLBS_GPS_NMEA_END && total_len + jlbs_gps_nmea_raw_data_sentence_length[index] <= length; i++)
	{
		if (jlbs_gps_nmea_raw_data_sentence_length[index] > 0)
		{
			memcpy(pos, &jlbs_gps_nmea_raw_data[index * JLBS_GPS_MAX_RAW_DATA_LEN], jlbs_gps_nmea_raw_data_sentence_length[index]);
			sprintf(_kvmLogStr,"jlbs_gps_getRawData: index = %d, length = %d, sentence = %s\n",
					index, jlbs_gps_nmea_raw_data_sentence_length[index], pos);
    		Kprintf();
			
			pos += jlbs_gps_nmea_raw_data_sentence_length[index];
			total_len += jlbs_gps_nmea_raw_data_sentence_length[index];
		}
		
		index++;
		if (index == JLBS_GPS_NMEA_END)
		{
			index = JLBS_GPS_NMEA_GPGGA;
		}
	}
	
	jlbs_gps_nmea_raw_data_read_start = index;

	sprintf(_kvmLogStr, 
			"jlbs_gps_getRawDataSingleLine: total_len = %d, new_start_index = %d, buffer = %s\n", 
			total_len, jlbs_gps_nmea_raw_data_read_start, buffer);
    Kprintf();
	
	kal_give_mutex(g_jam_gps_mutex);
	
	return total_len;
}

/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_getLocation
 *  get parsed data from gps receiver
 * PARAMETERS
 *  port - opened gps handle
 *  nmea_data - parsed NMEA data
 * RETURNS
 *  readbytes - total bytes read from gps receiver.
 *****************************************************************************/
kal_int32 jlbs_gps_getLocation(kal_int32 handle, jlbs_gps_nmea_data_struct *nmea_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_FUNC, FUNC_J2ME_GPS_GET_LOCATION, jlbs_gps_handle, handle, jlbs_gps_nmea_location_data, nmea_data);

	if (handle != jlbs_gps_handle || !nmea_data || !jlbs_gps_nmea_location_data || jlbs_gps_type != JLBS_GPS_TYPE_LOCATION)
	{
		return JLBS_GPS_ERROR;
	}
	
	kal_take_mutex(g_jam_gps_mutex);
	memcpy(nmea_data, jlbs_gps_nmea_location_data, sizeof(jlbs_gps_nmea_data_struct));
	kal_give_mutex(g_jam_gps_mutex);
	return JLBS_GPS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_initialize
 *  initialize gps
 * PARAMETERS
 *  
 * RETURNS
 *****************************************************************************/
kal_int32 jlbs_gps_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sprintf(_kvmLogStr,"jlbs_gps_initialize\n");
    Kprintf();

	return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_finalize
 *  finalize gps
 * PARAMETERS
 *  
 * RETURNS
 *****************************************************************************/
kal_int32 jlbs_gps_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sprintf(_kvmLogStr,"jlbs_gps_finalize:%d", jlbs_gps_open_counter);
    Kprintf();
	
	if (jlbs_gps_open_counter > 0)
	{
        jlbs_gps_open_counter = 1;
		jlbs_gps_close(jlbs_gps_handle);
	}

	return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_is_need_cost
 *  finalize gps
 * PARAMETERS
 *  
 * RETURNS
 *****************************************************************************/
kal_int32 jlbs_gps_is_need_cost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sprintf(_kvmLogStr,"jlbs_gps_is_need_cost->jlbs_gps_selected_gps_type=%d\n", jlbs_gps_selected_gps_type);
    Kprintf();

#ifdef __AGPS_SUPPORT__
    if ((srv_sim_ctrl_is_available(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
        || srv_sim_ctrl_is_available(MMI_SIM2)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        || srv_sim_ctrl_is_available(MMI_SIM3)
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        || srv_sim_ctrl_is_available(MMI_SIM4)
#endif
        ) && srv_mode_switch_is_network_service_available())
    {
        if (jlbs_gps_selected_gps_type)
        {
            ret = 1;
        }
    }
#endif

	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jlbs_gps_response_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *****************************************************************************/
void jlbs_gps_response_handler(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	jlbs_gps_set_agps_rsp_struct *p = (jlbs_gps_set_agps_rsp_struct*) ilm_ptr->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_trace(TRACE_FUNC, FUNC_J2ME_GPS_RSP_HDLR, p->handle, p->result);
	jlbs_gps_handle = p->handle;
    jlbs_gps_agps_result = p->result;
	kal_set_eg_events(g_java_event_group_1, JAVA_EG_LBS_WAITING_RESULT, KAL_OR);
}
#endif /* SUPPORT_JSR_179 */
