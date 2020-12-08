/**********************************************************************************
*Filename:     kjx_include.h
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2013/12/18
*
***********************************************************************************/
#if !defined(KJX_INCLUDE_H)
#define KJX_INCLUDE_H
#include "MMIDataType.h"
#include "NwInfoSrvGprot.h"
#include "dcl_uart.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "soc_consts.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIntStruct.h"
#include "app_datetime.h"
#include "syscomp_config.h"
#include "DtcntSrvIntDef.h"
#include "task_config.h"
#include "OslMemory_Int.h"
#include "GlobalConstants.h"
#include "EventsDef_Int.h"
//#include "EventsGprot_Int.h"
#include "TimerEvents.h"
#include "mmi_msg_struct.h"
#include "intrCtrl.h"
#include "us_timer.h"
#include "PowerOnChargerProt.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "UcmSrvGprot.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_events_gprot.h"
#include "gui.h"
#include "gdi_include.h"
#include "GlobalResDef.h"
#include "gui_status_icon.h"
#include "gui_typedef.h"
#if defined(__KJX_NBR_CELL__)
#include "nbr_public_struct.h"
#endif
#include "FontRes.h"
#include "SSCStringTable.h"
#include "kjx_type_define.h"
#include "kjx_net.h"
#include "dcl_uart.h"
#include "kjx_socket.h"
#include "kjx_gps.h"
#include "kjx_gps_main.h"
#include "kjx_prin.h"
#include "kjx_gprs_format.h"
//#include "kjx_timer.h"
#include "TimerEvents.h"
#include "kjx_led_isink.h"
#include "kjx_main.h"
#include "kjx_sensor.h"
#include "kjx_agps.h"
#include "kjx_rfid.h"
#include "mmi_rp_app_kjx_def.h"
//#include "kjx_obd.h"
//#include "kjx_infrared.h"
//#include "kjx_dog_get_data.h"
//#include "kjx_dog_gps_data.h"
//#include "kjx_dog_display.h"
#include "kjx_socket_foreign.h"
#if defined(CUSTOMER_NAME_A2)
#include "kjx_main_a2.h"
#elif defined(CUSTOMER_NAME_W80)
#include "kjx_main_w80.h"
#elif defined(CUSTOMER_NAME_200)
#include "kjx_main_200.h"
#elif defined(CUSTOMER_NAME_A3)
#include "kjx_main_a3.h"
#elif defined(CUSTOMER_NAME_MEGE2)
#include "kjx_main_mege2.h"
#elif defined(CUSTOMER_NAME_SPIRIT)
#include "kjx_main_spirit.h"
#elif defined(CUSTOMER_NAME_BABY1)
#include "kjx_main_baby1.h"
#elif defined(CUSTOMER_NAME_SKY)
#include "kjx_main_sky.h"
#elif defined(CUSTOMER_NAME_OLDMAN)
#include "kjx_main_oldman.h"
#elif defined(CUSTOMER_NAME_TOUR)
#include "kjx_main_tour.h"
#endif
#include <stdlib.h>

#include <math.h>

//#define  mmi_include_use_header 
#define ClearProtocolEventHandler(event)   \
        mmi_frm_clear_protocol_event_handler(event, (PsIntFuncPtr)NULL)
#define SetProtocolEventHandler(func, event)   \
			mmi_frm_set_protocol_event_handler(event, (PsIntFuncPtr)func, MMI_FALSE)

/***************************************************************************************/
extern srv_dtcnt_store_info_context g_srv_dtcnt_store_ctx;
extern kal_mutexid g_srv_dtcnt_mutex_op;
extern task_info_struct *task_info_g;
extern kjxNetInfo g_kjxNetInfo;
extern kjx_socket_foreign kjx_socket_foreign_setting_default[];

/***************************************************************************************/
/***************************************************************************************/
extern uint32 kjx_gps_get_data_from_buffer(U8 *in_data_buffer,U8 *out_data_buffer,U16 out_data_len,U16 data_index,U16 in_data_len);
extern int32 kjx_gps_data_into_number(U8 *in_data_buffer,U16 in_data_len, U8 *float_len);
extern void kjx_gps_data_decode(U8 *data,U16 data_len);
extern void kjx_gps_turn_on(void);
extern void kjx_gps_turn_off(void);
extern void kjx_gps_open_pwr(void);
extern void kjx_gps_close_pwr(void);
extern void kjx_gps_uart_turnon_power(UART_PORT port, kal_bool on);
extern kal_bool kjx_gps_uart_open(UART_PORT port, module_type ownerid);
extern void kjx_gps_uart_close(UART_PORT port, module_type ownerid);
extern void kjx_gps_uart_set_owner(UART_PORT port, module_type ownerid);
extern module_type kjx_gps_uart_get_owner_id(UART_PORT port);
extern kal_uint16 kjx_gps_uart_get_rx_avail(UART_PORT port);
extern kal_uint16 kjx_gps_uart_read_bytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
extern void kjx_gps_uart_clear_rx_buf(UART_PORT port, module_type ownerid);
extern void kjx_gps_uart_clear_tx_buf(UART_PORT port, module_type ownerid);
extern void kjx_gps_uart_rx_pure(UART_PORT port, module_type ownerid);
extern void kjx_gps_uart_tx_pure(UART_PORT port, module_type ownerid);
extern void kjx_gps_uart_setDCBConfig(UART_PORT port, UARTDCBStruct UART_Config, module_type ownerid);
extern void kjx_gps_recv_data_from_uart(void *msg);
extern void kjx_gps_tack_gps_init(void);
extern kal_bool kjx_gps_task_init(task_indx_type task_indx);
extern void kjx_gps_task_main(task_entry_struct * task_entry_ptr);
extern kal_bool kjx_gps_task_create(comptask_handler_struct **handle);
extern void kjx_gps_func_init(void);
extern void kjx_gps_disable_sleep(void);
extern void kjx_gps_enable_sleep(void);
#ifdef __KJX_FUN_GPS__
extern void kjx_gps_time_sync(kjx_gps_data g_kjx_gps_data);
extern void kjx_gps_do_something_with_data(kjx_gps_func* g_kjx_gps_func,kjx_gps_data g_kjx_gps_data);
extern void kjx_gps_get_data_with_decode(char* gps_data,int len,kjx_gps_func* g_kjx_gps_func);
#endif
extern void kjx_gps_main(void);
extern void kjx_func_null(void);
extern void kjx_restart(void);
extern void kjx_func_init(void);
extern void kjx_sensor_main(void);
extern void kjx_eint_main(void);
extern void kjx_func_main(void);
extern void kjx_set_protocol_event_handler(U16 eventID, PsFuncPtr funcPtr);
extern kjx_sim_enum kjx_get_active_card(void);
extern srv_dtcnt_account_info_st* kjx_srv_dtcnt_db_store_get_acc_info_by_apn(S8 *apn, S8 SimId);
extern srv_dtcnt_result_enum kjx_srv_dtcnt_get_acc_id_by_apn(kjx_socket_event_func *socket_func,S8 *apn, U32 *acc_id_out, S8 SimId,U8 app_id);
extern int kjx_set_gprs_data_account_req (kjx_socket_event_func *socket_func,U8 *name, U8 *apn, srv_dtcnt_prof_gprs_auth_type_enum auth_type, U8 *user_name, U8 *passwd, U8 *dns, U8 proxy,U8 * proxy_add);
extern void kjx_get_host_by_name_rsp(void* inMsg);
extern void kjx_get_host_by_name_req(kjx_socket_event_func *socket_func,U32 acctId, kal_int32 socket_id, const S8 *hostName,kal_uint16 dstPort, char access_id);
extern void kjx_set_data_acc_rsp(kjx_socket_event_func *socket_func,kal_uint32 *msg,kjxNetInfo *kjxNet,kjx_access_id access_id);
extern void kjx_set_gprs_data_acount(kjx_socket_event_func *socket_func,kjxNetInfo *kjxNet,kal_int8 access_id, set_data_acc_rsp rspCallback);
extern kal_int8 kjx_socket_create(U32 account_id);
extern kal_int8 kjx_socket_connect(kal_int8 socketId, U8 ip[], U16 port);
extern S32 kjx_socket_send(kal_int8 socketId, const S8 *buf, S32 len);
extern S32 kjx_socket_recv(kal_int8 socketId, const S8 *buf, S32 len);
extern kal_int8 kjx_socket_close(kal_int8 socketId);
extern void kjx_socket_event_handler(soc_event_enum socket_event,S32 result);
extern void kjx_socket_notify(void *inMsg);
extern void kjx_socket_get_host_fail(void);
extern kal_int32 kjx_socket_connect_again(kjx_socket_event_func* socket_event_func,void* inMsg);
extern void kjx_socket_connet_success(void);
extern void kjx_socket_connet_wouldblock(void);
extern void kjx_socket_connet_error(void);
extern void kjx_socket_get_host_error(kal_int8 access_id);
extern void kjx_socket_main(void);
extern void kjx_socket_func_init(void);
extern void kjx_socket_init(void);
extern void kjx_socket_ipaddr_init(void);
extern void kjx_socket_session_free(void);
extern MMI_BOOL srv_dtcnt_db_store_status_check(void);
extern void kjx_trace(const char *fmt, ...);
extern int ComputeCRC(U8 * val, size_t len);
extern void kjx_get_cellid(void);
extern void kjx_get_imei(void);
extern void kjx_get_cellid_req(void);
extern void kjx_get_cellId_rsp(void *info);
extern void kjx_cellId_rsp(void *inMsg);
extern void kjx_get_imei_rsp(void *Msg);
extern void kjx_get_iccid_rsp(void *info);
extern void kjx_get_iccid_req(void);
extern void kjx_get_iccid(void);
extern void kjx_socket_notify_connect(void);
extern U16 kjx_gprs_set_send_data(void);
extern U16 kjx_gprs_set_pack_data(void);
extern U16 kjx_gprs_get_unpack_data(void);
extern U16 kjx_gprs_get_user_data(void);
extern S32 kjx_gprs_set_send_buffer(void);
extern void kjx_gprs_set_pack_struct(void);
extern void kjx_socket_notify_error(kal_int8 socket_id);
extern void kjx_socket_login_again(void);
extern void kjx_socket_notify_read(kal_int8 socket_id);
extern void kjx_socket_recvbuf_hex_to_acsii(kal_int32 len);
#if defined(__MOTION_SENSOR_MMA8452Q_SUPPORT__)
extern void acc_mag_sensor_start(void);
extern int yas_mma8452q_read_reg(unsigned char adr, unsigned char *buf, unsigned char len);
extern int kjx_acc_data_initialize(void);
#endif
extern void custom_isink_control(kal_bool open,PMU_ISINK_LIST_ENUM ISINK_X);
extern void kjx_set_led_status(kjx_led_id index,BOOL status);
extern void kjx_delay_uSec(int delay);
extern void kjx_led_red_blink(U16 total,int delayOn,int delayOff);
extern void kjx_led_blue_blink(U16 total,int delayOn,int delayOff);
extern void kjx_led_green_blink(U16 total,int delayOn,int delayOff);
extern void kjx_led_yellow_blink(U16 total,int delayOn,int delayOff);
extern void kjx_get_cur_battery_status(void);
extern kal_uint8* asci_to_16hex(kal_uint8* str) ;
extern void kjx_sensor_func_init(void);
extern U8 kjx_sys_get_cur_gsm_status(void);
extern void kjx_func_custom_init(void);
extern double kjx_set_lat_and_lng_data(S8* lat1, S8* lng1, S8* lat2, S8* lng2);
extern double kjx_get_distance(double lat1, double lng1, double lat2, double lng2);
extern void delay_uSec(uint16 delay);
extern void kjx_gps_extern_do_somthing(U8 *data,U16 data_len);
extern void kjx_set_gsm_led(U16 led_type);
extern S32 srv_ucm_query_call_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_index_info_struct *index_list);
extern void kjx_mege2_send_sms_with_custom(kjx_sms_send_type type);
extern void kjx_shut_down(void);
extern void kjx_step_set_work_time(void);
extern PU8 get_image(MMI_ID_TYPE i);
extern U16 kjx_get_project_id(void);
extern void kjx_handle_position(void);
extern void kjx_handle_send_gps_data(void);
extern void kjx_report_to_custmer_with_type(kjx_sms_send_type sms_type,kjx_socket_type socket_type);
extern kal_bool applib_dt_is_valid(applib_time_struct *t);
extern void PhnsetSendSetTimeReqMessage(const MYTIME *time);

#if defined(__NPR_TTS__)
extern void Npr_Tts_play_stop(void);
extern int  Npr_Ttsplayer_playtextw(char* pszText,void (*end_call)(void*info));
#endif

#ifdef __KJX_ALARM__
#include "AlarmDef.h"
#include "AlarmSrvGprot.h"
#include "AlarmProt.h"
#include "ProfilesSrvGprot.h"
extern alm_context_struct g_alm_cntx;
#endif

#if defined(__MEGE_LED_LIGHT__)
extern void LED_smile_light(void);
extern void LED_happy_light(void);
extern void LED_cry_light(void);
extern void LED_all_light(void);
extern void LED_gps_suc(void);
extern void LED_foolish_light(void);
extern void LED_light_flash_select(char* string);
#endif
#if defined(__LIGHT_DROP_DETECT__)
extern void ap3426_entry(void);
#endif
extern BOOL kjx_is_on_work_time(void);
extern void kjx_socket_function_init(void);
extern char* kjx_switch_string(char* string,int index,char* version);
extern void kjx_main_lcd_set_level_0(void);
extern char* kjx_get_parameter_string(char* stringbuffer,char* header,char* ender,char* sign,int index);
extern char* kjx_get_parameter_string_only_in_buffer(char* stringbuffer,char* sign,int index);
extern char* kjx_get_parameter_string_only_in_buffer_extern(char* stringbuffer,char* sign,int index);
extern int kjx_get_parameter_number(char* stringbuffer,char* header,char* ender,char* sign,int MaxNum);
extern char* kjx_get_parameter_string_extern(char* stringbuffer,char* header,char* ender,char* subHeader,char* subEnder,int index);
extern BOOL kjx_is_charging(void);
#endif
