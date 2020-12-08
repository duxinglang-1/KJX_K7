/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_core.h
 *
 * Created by Ingmar Persson
 *
 * Revision history:
 *
 */
#ifndef _msf_core_h
#define _msf_core_h

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif
#ifndef _msf_int_h
#include "msf_int.h"
#endif

/**********************************************************************
 * Global MSF Signals in Moblie Suite
 **********************************************************************/

#define MSF_SIG_MODULE_START            ((MSF_MODID_MSM << 8) + 0x01)
#define MSF_SIG_MODULE_TERMINATE        ((MSF_MODID_MSM << 8) + 0x02)
#define MSF_SIG_MODULE_STATUS           ((MSF_MODID_MSM << 8) + 0x03)
#define MSF_SIG_MODULE_EXECUTE_COMMAND  ((MSF_MODID_MSM << 8) + 0x04)

#define MSF_SIG_TIMER_SET               ((MSF_MODID_MSM << 8) + 0x05)
#define MSF_SIG_TIMER_RESET             ((MSF_MODID_MSM << 8) + 0x06)
#define MSF_SIG_TIMER_EXPIRED           ((MSF_MODID_MSM << 8) + 0x07)

#define MSF_SIG_WIDGET_NOTIFY           ((MSF_MODID_MSM << 8) + 0x08)
#define MSF_SIG_WIDGET_ACTION           ((MSF_MODID_MSM << 8) + 0x09)
#define MSF_SIG_WIDGET_USEREVT          ((MSF_MODID_MSM << 8) + 0x0A)
#define MSF_SIG_WIDGET_ACCESS_KEY       ((MSF_MODID_MSM << 8) + 0x0B)

#define MSF_SIG_PIPE_NOTIFY             ((MSF_MODID_MSM << 8) + 0x0C)

#define MSF_SIG_SOCKET_CONNECT_RESPONSE ((MSF_MODID_MSM << 8) + 0x0D)
#define MSF_SIG_SOCKET_NOTIFY           ((MSF_MODID_MSM << 8) + 0x0E)
#define MSF_SIG_SOCKET_HOST_BY_NAME     ((MSF_MODID_MSM << 8) + 0x0F)

#define MSF_SIG_FILE_NOTIFY             ((MSF_MODID_MSM << 8) + 0x10)

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#define MSF_SIG_REG_SET                 ((MSF_MODID_MSM << 8) + 0x11)
#define MSF_SIG_REG_GET                 ((MSF_MODID_MSM << 8) + 0x12)
#define MSF_SIG_REG_DELETE              ((MSF_MODID_MSM << 8) + 0x13)

#define MSF_SIG_REG_RESPONSE            ((MSF_MODID_MSM << 8) + 0x14)
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#define MSF_SIG_CONTENT_SEND            ((MSF_MODID_MSM << 8) + 0x15)
#define MSF_SIG_CONTENT_SEND_ACK        ((MSF_MODID_MSM << 8) + 0x16)

#define MSF_SIG_TEL_MAKE_CALL_RESPONSE  ((MSF_MODID_MSM << 8) + 0x17)
#define MSF_SIG_TEL_SEND_DTMF_RESPONSE  ((MSF_MODID_MSM << 8) + 0x18)

#define MSF_SIG_PB_ADD_ENTRY_RESPONSE   ((MSF_MODID_MSM << 8) + 0x19)

#define MSF_SIG_GET_ICONS               ((MSF_MODID_MSM << 8) + 0x1A)
#define MSF_SIG_GET_ICONS_RESPONSE      ((MSF_MODID_MSM << 8) + 0x1B)

#define MSF_SIG_OBJECT_ACTION           ((MSF_MODID_MSM << 8) + 0x1C)

#define MSF_SIG_PIM_OPEN_RESPONSE       ((MSF_MODID_MSM << 8) + 0x1D)
#define MSF_SIG_PIM_CLOSE_RESPONSE      ((MSF_MODID_MSM << 8) + 0x1E)
#define MSF_SIG_PIM_ADDR_LOOKUP_RESPONSE      ((MSF_MODID_MSM << 8) + 0x1F)
#define MSF_SIG_PIM_ADDR_LOOKUP_NAME_RESPONSE ((MSF_MODID_MSM << 8) + 0x20)
#define MSF_SIG_PIM_ADDR_GET_RECORD_RESPONSE  ((MSF_MODID_MSM << 8) + 0x21) 
#define MSF_SIG_PIM_ADDR_SET_RECORD_RESPONSE  ((MSF_MODID_MSM << 8) + 0x22) 

#define MSF_DLG_OPEN_RESPONSE_SIG       ((MSF_MODID_MSM << 8) + 0x23)
#define MSF_DLG_SAVE_RESPONSE_SIG       ((MSF_MODID_MSM << 8) + 0x24)
#define MSF_SAS_SAVE_AS_RESPONSE_SIG    ((MSF_MODID_MSM << 8) + 0x25)

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#define MSF_SIG_FILE_MOVE				((MSF_MODID_MSM << 8) + 0x26) /* Used by MSM to write itself a signal for file move*/
#define MSF_SIG_FILE_MOVE_RESPONSE		((MSF_MODID_MSM << 8) + 0x27) /* Used by MSM to write the application a signal about file move response*/
#define MSF_MMS_SIG_FILE_MOVE				((MSF_MODID_MSM << 8) + 0x28) /* Used by MMS task  to write MSM a signal about file move response*/
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */	  

#define MSF_SIG_REGISTER_CONTENT_ROUTING_DATA		((MSF_MODID_MSM << 8) + 0x29)

#define MSF_SIG_TIMER_RESET_ALL                     ((MSF_MODID_MSM << 8) + 0x2A)
/**********************************************************************
 * Type definitions
 **********************************************************************/
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef MSF_REGISTRY_SUPPORT
typedef struct {
  char*           path;
  char*           key;
  MSF_UINT8       type;
  MSF_INT32       value_i;
  unsigned char*  value_bv;
  MSF_UINT16      value_bv_length;
} msf_registry_param_t;
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

typedef struct {
  MSF_UINT16     drmDataLength;
  unsigned char *drmData;
  char          *drmContentHeaders;

} msf_content_drm_data_t;


typedef struct  {
  MSF_UINT8               routingFormat;
  char*                   routingIdentifier;
  char*                   contentUrl;
  char*                   contentSource;
  char*                   contentParameters;
  char*                   contentHeaders;
  MSF_INT32               networkAccountId;
  MSF_UINT8               contentDataType;
  MSF_UINT32              contentDataLength;
  unsigned char*          contentData;
  MSF_UINT8               contentDRMDataExists;
  msf_content_drm_data_t *contentDRMData;
  char*                   auxTypeIdentifier;
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
  MSF_INT32               attrLength;
  unsigned char           *attrString;
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
} msf_content_data_t;

typedef struct {
	MSF_UINT8	modId;
	MSF_UINT8	type;
	char*		value;
}msf_register_content_routing_data_t;


typedef struct {
  MSF_UINT8 type;
  union {
    char      *s_value;
    MSF_INT32  i_value;
  }_u;
} msf_mime_list_t;

typedef struct {
  MSF_UINT32 mime_hash;
  char      *s_mime;
  MSF_INT32  i_mime;
  MSF_UINT8  resource_type;
  char      *resource_str_id;
  MSF_UINT32 resource_int_id;
} msf_icon_list_t;

/**********************************************************************
 * Signal structures that are connected to the signals above.
 **********************************************************************/

/* Module */
typedef struct {
  MSF_UINT8           modId;  /* The module that shall be started. */
  char*               startOptions;
  MSF_UINT8           contentDataExists;
  msf_content_data_t* contentData;
  /* msf_content_area_t contentArea;*/
} msf_module_start_t;

typedef struct {
  MSF_UINT8     modId;  /* The module that shall be terminated. */
} msf_module_terminate_t;

typedef struct {
  MSF_UINT8     status;
  MSF_UINT8     modId;
  char*         modVersion; /* Only used when the module is activated */
} msf_module_status_t;

typedef struct  {
  MSF_UINT8           srcModId;
  char*               commandOptions;
  MSF_UINT8           contentDataExists;
  msf_content_data_t* contentData;
 /* msf_content_area_t contentArea;*/
} msf_module_execute_cmd_t;

/* Timer */
typedef struct {
  MSF_UINT32    timerID;
  MSF_UINT32    timerInterval;
} msf_timer_set_t;

typedef struct {
  MSF_UINT32    timerID;
} msf_timer_reset_t;

typedef struct {
  MSF_UINT32    timerID;
} msf_timer_expired_t;

/* Widget */
typedef struct {
  MSF_UINT32          handle;
  MsfNotificationType notificationType;
} msf_widget_notify_t;

typedef struct {
  MSF_UINT32    handle;
  MSF_UINT32    action;
} msf_widget_action_t;

typedef struct {
  MSF_UINT32    handle;
  MsfEvent      event;
} msf_widget_userevt_t;

typedef struct {
  MSF_UINT32    handle;
  MSF_UINT32    accessKey;
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
  MsfEvent      event;
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
} msf_widget_access_key_t;


/* Pipes */
typedef struct {
  MSF_INT32 handle;
  MSF_INT16 eventType;
} msf_pipe_notify_t;


/* Sockets */
typedef struct {
  MSF_INT32 socketId;
  MSF_INT16 result;
} msf_socket_connect_response_t;

typedef struct {
  MSF_INT32 socketId;
  MSF_INT16 eventType;
} msf_socket_notify_t;

typedef struct {
  MSF_INT32     requestId;
  MSF_INT16     result;
  MSF_INT16     addrLen;
  unsigned char addr[16];
} msf_socket_host_by_name_t;


/* File */
typedef struct {
  MSF_INT32 fileHandle;
  MSF_INT16 eventType;
} msf_file_notify_t;

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef MSF_REGISTRY_SUPPORT
/* Registry */
/* MSF_SIG_REG_GET, MSF_SIG_REG_DELETE */
typedef struct {
  MSF_INT16 id;
  char*     path;
  char*     key;
} msf_registry_identifier_t;

/* MSF_SIG_REG_SET, MSF_SIG_REG_RESPONSE */
typedef struct {
  MSF_INT16        id;
  char*            path;
  unsigned char*   next_element;
  unsigned char*   buffer_start;
  unsigned char*   buffer_end;
} msf_registry_response_t;
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__

typedef enum{
	MSF_FILE_MOVE_AVAILABLE,
	MSF_FILE_MOVE_BUSY
}msf_file_move_enum;

typedef struct{
  MSF_UINT8 flag;
  MSF_UINT8 modid;
  char *src_filename;
  msf_mms_storage_enum src_store;
  char *dst_filename; 
  msf_mms_storage_enum dst_store;
}msf_file_move_t;

typedef struct{
	MSF_INT32 status;
}msf_file_move_response_t;

#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */ 

/* Content routing */
typedef struct {
  MSF_UINT8           destModId;
  MSF_UINT8           sendAck;
  MSF_UINT8           id;
  MSF_UINT8           contentDataExists;
  char*               startOptions;
  msf_content_data_t* contentData;
  /* msf_content_area_t contentArea;*/
} msf_content_send_t;

typedef struct {
  MSF_UINT8  id;
  MSF_UINT8  status;
} msf_content_send_ack_t;

/* Telephone */
typedef struct {
  MSF_UINT16 telId;
  MSF_INT16  result;
} msf_tel_make_call_resp_t;

typedef struct {
  MSF_UINT16 telId;
  MSF_INT16  result;
} msf_tel_send_dtmf_resp_t;

/* PhoneBook */
typedef struct {
  MSF_UINT16 pbId;
  MSF_INT16  result;
} msf_pb_add_entry_resp_t;


typedef struct  {
  char                *mime_type;
  MsfResourceType      data_type;
  unsigned char       *data;
  MSF_INT32            data_len;
  char                *src_path;
  char                *file_name;
  MSF_INT32            excl_act_strings_cnt;
  char               **excl_act_strings;
  MSF_BOOL             cleanup;
} msm_object_action_t;


typedef struct {
  MSF_UINT8         src;
  MSF_UINT32        id;
  MSF_UINT16        n_items;
  msf_mime_list_t  *mime_list;
}msm_get_icon_map_table_t;

typedef struct {
  MSF_UINT32        id;
  MSF_UINT16        n_items;
  msf_icon_list_t  *icon_list;
} msm_get_icons_resp_t;

#ifdef MSF_CONFIG_PIM

/* PIM */
typedef struct{
  MSF_UINT16        requestId; 
  MSF_UINT16        result;
} msf_pim_open_resp_t;

typedef struct{
  MSF_UINT16        requestId;
  MSF_UINT16        result;
} msf_pim_close_resp_t;

typedef struct{
  MSF_UINT16            requestId; 
  MSF_UINT16            recordInfoLen;
  MsfPimAddrRecordInfo *recordInfos;
  MSF_UINT16            result;
} msf_pim_addr_lookup_resp_t;

typedef struct{
  MSF_UINT16        requestId; 
  char             *name; 
  MSF_UINT32        recordId;
  MSF_UINT16        result;
} msf_pim_addr_lookup_name_resp_t;

typedef struct{
  MSF_UINT16        requestId;
  MSF_UINT32        fieldsLen;
  MsfPimField      *fields; 
  MSF_UINT32        recordId;
  MSF_UINT16        result;
} msf_pim_addr_get_record_resp_t;

typedef struct{
  MSF_UINT16        requestId;
  MSF_UINT32        recordId;
  MSF_UINT16        result;
} msf_pim_addr_set_record_resp_t;

#endif /*MSF_CONFIG_PIM*/


typedef struct {
  MSF_UINT32              id;        /* operation identifier */
  long                    status;    /* status of operation */
  char*                   file_name;
} msf_dlg_save_response_sig_t;

typedef struct {
  MSF_UINT32              id;        /* operation identifier */
  long                    status;    /* status of operation */
  char*                   file_name;
} msf_dlg_open_response_sig_t;

typedef struct {
  MSF_UINT32              id;        /* operation identifier */
  long                    status;    /* status of operation */
  char*                   file_name;
} msf_sas_save_as_response_sig_t;

/**********************************************************************
 * Conversion routines for signal structs
 **********************************************************************/
#ifndef MSF_SIGNAL_API_REVISED
int
gmms_msf_cvt_content_data (msf_dcvt_t *obj, msf_content_data_t *p);

int
gmms_msf_cvt_module_start (msf_dcvt_t *obj, msf_module_start_t *p);

int
gmms_msf_cvt_module_terminate (msf_dcvt_t *obj, msf_module_terminate_t *p);

int
gmms_msf_cvt_module_status (msf_dcvt_t *obj, msf_module_status_t *p);

int
gmms_msf_cvt_module_execute_cmd (msf_dcvt_t *obj, msf_module_execute_cmd_t *p);

int
gmms_msf_cvt_timer_set (msf_dcvt_t *obj, msf_timer_set_t *p);

int
gmms_msf_cvt_timer_reset (msf_dcvt_t *obj, msf_timer_reset_t *p);

int
gmms_msf_cvt_timer_expired (msf_dcvt_t *obj, msf_timer_expired_t *p);

int
gmms_msf_cvt_wid_notify (msf_dcvt_t *obj, msf_widget_notify_t *p);

int
gmms_msf_cvt_wid_action (msf_dcvt_t *obj, msf_widget_action_t *p);

int
gmms_msf_cvt_wid_user_event (msf_dcvt_t *obj, msf_widget_userevt_t *p);

int
gmms_msf_cvt_wid_access_key (msf_dcvt_t *obj, msf_widget_access_key_t *p);

int
gmms_msf_cvt_pipe_notify (msf_dcvt_t *obj, msf_pipe_notify_t *p);

int
gmms_msf_cvt_file_notify (msf_dcvt_t *obj, msf_file_notify_t *p);

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
int
gmms_msf_cvt_file_move (msf_dcvt_t *obj, msf_file_move_t *p);

int
gmms_msf_cvt_file_move_response(msf_dcvt_t *obj, msf_file_move_response_t *p);
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */

int
gmms_msf_cvt_socket_connect_response (msf_dcvt_t *obj, msf_socket_connect_response_t *p);

int
gmms_msf_cvt_socket_notify (msf_dcvt_t *obj, msf_socket_notify_t *p);

int
gmms_msf_cvt_socket_host_by_name (msf_dcvt_t *obj, msf_socket_host_by_name_t *p);

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef MSF_REGISTRY_SUPPORT
int
msf_cvt_registry_identifier (msf_dcvt_t *obj, msf_registry_identifier_t *p);
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


int
gmms_msf_cvt_content_send (msf_dcvt_t *obj, msf_content_send_t *p);

int
gmms_msf_cvt_content_send_ack (msf_dcvt_t *obj, msf_content_send_ack_t *p);

int
msf_cvt_register_content_routing_data(msf_dcvt_t *obj, msf_register_content_routing_data_t *p);

int
gmms_msf_cvt_tel_make_call_resp (msf_dcvt_t *obj, msf_tel_make_call_resp_t *p);

int
gmms_msf_cvt_tel_send_dtmf_resp (msf_dcvt_t *obj, msf_tel_send_dtmf_resp_t *p);

int
gmms_msf_cvt_pb_add_entry_resp (msf_dcvt_t *obj, msf_pb_add_entry_resp_t *p);

int
gmms_msf_cvt_icon_list(msf_dcvt_t *obj, msf_icon_list_t *p);

int
gmms_msf_cvt_get_icons_resp (msf_dcvt_t *obj, msm_get_icons_resp_t *p);

int
gmms_msf_cvt_object_action(msf_dcvt_t *obj, msm_object_action_t *p);

#ifdef MSF_CONFIG_PIM

int
msf_cvt_pim_open_resp(msf_dcvt_t *obj, msf_pim_open_resp_t *p);

int
msf_cvt_pim_close_resp(msf_dcvt_t *obj, msf_pim_close_resp_t *p);

int
msf_cvt_pim_addr_lookup_resp(msf_dcvt_t *obj, msf_pim_addr_lookup_resp_t *p);

int
msf_cvt_pim_addr_lookup_name_resp(msf_dcvt_t *obj, msf_pim_addr_lookup_name_resp_t *p);

int
msf_cvt_pim_addr_get_record_resp(msf_dcvt_t *obj, msf_pim_addr_get_record_resp_t *p);

int
msf_cvt_pim_addr_set_record_resp(msf_dcvt_t *obj, msf_pim_addr_set_record_resp_t *p);

#endif /*MSF_CONFIG_PIM*/

int
gmms_msf_cvt_open_dlg_response (msf_dcvt_t *obj, msf_dlg_open_response_sig_t *p);

int
gmms_msf_cvt_save_dlg_response (msf_dcvt_t *obj, msf_dlg_save_response_sig_t *p);

int
gmms_msf_cvt_save_as_response (msf_dcvt_t *obj, msf_sas_save_as_response_sig_t *p);
#endif /*MSF_SIGNAL_API_REVISED*/

/**********************************************************************
 * Module status
 **********************************************************************/

#define MODULE_STATUS_NULL          0
#define MODULE_STATUS_STANDBY       1
#define MODULE_STATUS_CREATED       2
#define MODULE_STATUS_ACTIVE        3
#define MODULE_STATUS_SHUTTING_DOWN 4
#define MODULE_STATUS_TERMINATED    5



/**********************************************************************
 * Signaling macros
 **********************************************************************/

#define MSF_SIGNAL_REGISTER_QUEUE    gmms_HDIa_signalRegisterQueue

#define MSF_SIGNAL_DEREGISTER_QUEUE  gmms_HDIa_signalDeregisterQueue

#define MSF_SIGNAL_QUEUE_LENGTH      gmms_HDIa_signalQueueLength

#define MSF_SIGNAL_SEND              gmms_msf_signal_send

#define MSF_SIGNAL_RETRIEVE          gmms_msf_signal_retrieve

#ifndef MSF_SIGNAL_API_REVISED
#define MSF_SIGNAL_REG_FUNCTIONS     gmms_msf_signal_reg_functions

#define MSF_SIGNAL_CREATE            gmms_msf_signal_create

#define MSF_SIGNAL_DESTRUCT          gmms_msf_signal_destruct

#define MSF_SIGNAL_GET_SIGNAL_ID     gmms_msf_signal_get_signal_id

#define MSF_SIGNAL_GET_SOURCE        gmms_msf_signal_get_source

#define MSF_SIGNAL_GET_DESTINATION   gmms_msf_signal_get_destination

#define MSF_SIGNAL_GET_USER_DATA     gmms_msf_signal_get_user_data
#endif /*MSF_SIGNAL_API_REVISED*/

/**********************************************************************
 * Type definitions to signaling:
 **********************************************************************/
#ifndef MSF_SIGNAL_API_REVISED
typedef void* convert_function_t (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);
typedef void destruct_function_t (MSF_UINT8 module, MSF_UINT16 signal, void* p);
#endif
typedef void receive_function_t (MSF_UINT8 src_module, MSF_UINT16 signal, void* p);

/**********************************************************************
 * Time/Timer macros
 **********************************************************************/

#define MSF_TIME_ZONE_UNKNOWN        HDI_TIME_ZONE_UNKNOWN


#define MSF_TIME_GET_CURRENT         gmms_HDIa_timeGetCurrent

#define MSF_TIME_GET_CURRENT_WDLS    gmms_HDIa_timeGetCurrent_Wdls 

#define MSF_TIME_GET_TIME_ZONE       gmms_HDIa_timeGetTimeZone

#define MSF_TIME_GET_SECURE_CLOCK    gmms_HDIa_timeSecureClock

#define MSF_TIME_UTC_TO_LOCAL       gmms_HDIa_timeUTCToLocal

#define MSF_TIMER_SET                gmms_msf_timer_set

#define MSF_TIMER_RESET              gmms_msf_timer_reset

#define MSF_TIMER_RESET_ALL          gmms_msf_timer_reset_all

/**********************************************************************
 * Module macros
 **********************************************************************/

#define MSF_MODULE_IS_CREATED       gmms_msf_module_is_created

#define MSF_MODULE_IS_ACTIVE        gmms_msf_module_is_active

#define MSF_MODULE_IS_TERMINATED    gmms_msf_module_is_terminated

#define MSF_MODULE_START            gmms_msf_module_start

#define MSF_MODULE_TERMINATE        gmms_msf_module_terminate

#define MSF_KILL_TASK               gmms_HDIa_killTask

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/**********************************************************************
 * Registry macros
 **********************************************************************/
#ifdef MSF_REGISTRY_SUPPORT
#define MSF_REGISTRY_TYPE_INT       0
#define MSF_REGISTRY_TYPE_STR       1
#define MSF_REGISTRY_TYPE_DELETED   2


#define MSF_REGISTRY_SET_INIT           msf_registry_set_init

#define MSF_REGISTRY_SET_PATH           msf_registry_set_path

#define MSF_REGISTRY_SET_ADD_KEY_INT    msf_registry_set_add_key_int

#define MSF_REGISTRY_SET_ADD_KEY_STR    msf_registry_set_add_key_str

#define MSF_REGISTRY_SET_COMMIT         msf_registry_set_commit

#define MSF_REGISTRY_GET                msf_registry_get

#define MSF_REGISTRY_DELETE             msf_registry_delete

#define MSF_REGISTRY_RESPONSE_GET_NEXT  msf_registry_response_get_next

#define MSF_REGISTRY_RESPONSE_GET_PREV  msf_registry_response_get_prev

#define MSF_REGISTRY_RESPONSE_PEEK		msf_registry_response_peek

#define MSF_REGISTRY_RESPONSE_FREE      msf_registry_response_free
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/



/**********************************************************************
 * Content Routing macros
 **********************************************************************/

#define MSF_ROUTING_TYPE_MIME           1
#define MSF_ROUTING_TYPE_EXT            2
#define MSF_ROUTING_TYPE_PAPPID         3
#define MSF_ROUTING_TYPE_SCHEME         4

#define MSF_CONTENT_DATA_RAW            0
#define MSF_CONTENT_DATA_FILE           1
#define MSF_CONTENT_DATA_PIPE           2
#define MSF_CONTENT_DATA_NONE           3

#define MSF_CONTENT_STATUS_SUCCEED      0
#define MSF_CONTENT_STATUS_FAILED       1

#define MSF_CONTENT_SEND                gmms_msf_content_send_no_drm_no_ext
#define MSF_CONTENT_SEND_DRM            gmms_msf_content_send_no_ext
#define MSF_CONTENT_SEND_DRM_EXT        gmms_msf_content_send



#define MSF_REGISTER_CONTENT_ROUTING_DATA 	msf_register_content_routing_data

#define MSF_CONTENT_ROUTING_TYPE_MIME		1
#define MSF_CONTENT_ROUTING_TYPE_EXT		2
#define MSF_CONTENT_ROUTING_TYPE_PAPPID_N	3
#define MSF_CONTENT_ROUTING_TYPE_PAPPID_S	4
#define MSF_CONTENT_ROUTING_TYPE_SCHEME		5

/**********************************************************************
 * Object Action macros
 **********************************************************************/
#define MSF_OBJECT_ACTION               gmms_msf_object_action

#ifdef MSF_CFG_OBJECT_ACTION_EXT
#define MSF_OBJECT_ACTION_EXT           msf_object_action_ext
#endif

/**********************************************************************
 * Icon macros
 **********************************************************************/
#define MSF_GET_ICONS                   gmms_msf_get_icons

/**********************************************************************
 * Exported messaging functions:
 **********************************************************************/
#ifndef MSF_SIGNAL_API_REVISED
void
gmms_msf_signal_reg_functions (MSF_UINT8 module, convert_function_t *cf,
                                            destruct_function_t *df);

void*
gmms_msf_signal_create (MSF_UINT16 sigUid, MSF_UINT8 srcModId, MSF_UINT8 destModId,
                   MSF_UINT16 userDataLength);

void
gmms_msf_signal_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);

MSF_UINT16
gmms_msf_signal_get_signal_id (void* buffer);

MSF_UINT8
gmms_msf_signal_get_source (void* buffer);

MSF_UINT8
gmms_msf_signal_get_destination (void* buffer);

void*
gmms_msf_signal_get_user_data (void* buffer, MSF_UINT16* userDataLength);
#endif

void
gmms_msf_signal_send (MSF_UINT8 srcModId, MSF_UINT8 dstModId, MSF_UINT16 signalId, void* Signalbuffer);

int
gmms_msf_signal_retrieve (MSF_UINT8 modId, receive_function_t *rf);

/**********************************************************************
 * Exported timer functions:
 **********************************************************************/

void
gmms_msf_timer_set (MSF_UINT8 modId, int timerID, MSF_UINT32 timeInterval);

void
gmms_msf_timer_reset (MSF_UINT8 modId, int timerID);

void
gmms_msf_timer_reset_all(MSF_UINT8 modId);

/**********************************************************************
 * Exported module functions:
 **********************************************************************/

void
gmms_msf_module_is_created (MSF_UINT8 module_src, char* modVersion);

void
gmms_msf_module_is_active (MSF_UINT8 module_src);

void
gmms_msf_module_is_terminated (MSF_UINT8 module_src);

void
gmms_msf_module_start (MSF_UINT8 module_src, MSF_UINT8 module, char* startOptions,
                  msf_content_data_t* contentData, void* contentArea);

void
gmms_msf_module_terminate (MSF_UINT8 module_src, MSF_UINT8 module);

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/**********************************************************************
 * Exported registry functions:
 **********************************************************************/
#ifdef MSF_REGISTRY_SUPPORT
void*
msf_registry_set_init (MSF_UINT8 modId);

void
msf_registry_set_path (void* handle, char* path);

void
msf_registry_set_add_key_int (void* handle, char* key, MSF_INT32 value);

void
msf_registry_set_add_key_str (void* handle, char* key, unsigned char* value,
                              MSF_UINT16 valueLength);

void
msf_registry_set_commit (void* handle);

void
msf_registry_get (MSF_UINT8 modId, int id, char* path, char* key);

void
msf_registry_delete (MSF_UINT8 modId, char* path, char* key);

int
msf_registry_response_get_next (msf_registry_response_t* handle, msf_registry_param_t* param);

int
msf_registry_response_get_prev (msf_registry_response_t* handle, msf_registry_param_t* param);

int
msf_registry_response_peek (msf_registry_response_t* handle, msf_registry_param_t* param);

void
msf_registry_response_free (MSF_UINT8 modId, msf_registry_response_t* handle);
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


/**********************************************************************
 * Exported content routing functions:
 **********************************************************************/

void
gmms_msf_content_send (MSF_UINT8 src_modId, MSF_UINT8 dest_modId,
                  char* startOptions, msf_content_data_t* contentData, int sendAck, MSF_UINT8 id);

void
gmms_msf_content_send_no_ext (MSF_UINT8 src_modId, MSF_UINT8 dest_modId, char* startOptions, 
                         msf_content_data_t* contentData, int sendAck, MSF_UINT8 id);
void
gmms_msf_content_send_no_drm_no_ext (MSF_UINT8 src_modId, MSF_UINT8 dest_modId, char* startOptions, 
                                msf_content_data_t* contentData, int sendAck, MSF_UINT8 id);

void
msf_register_content_routing_data( MSF_UINT8 modId, MSF_UINT8 routingType, unsigned char* value);

/**********************************************************************
 * Exported Icon functions:
 **********************************************************************/
#define MSF_MIME_TYPE_STR 0x0001
#define MSF_MIME_TYPE_INT 0x0002

#define MSF_ICON_RESOURCE_TYPE_PREDEFINED 0x0001
#define MSF_ICON_RESOURCE_TYPE_FILE       0x0002

void
gmms_msf_get_icons (MSF_UINT8 src_modId, MSF_UINT32 id, 
               MSF_UINT16 n_items, msf_mime_list_t mime_list[]);


/**********************************************************************
 * Exported Object Action functions:
 **********************************************************************/
void
gmms_msf_object_action(MSF_UINT8             src_modId, 
                  const char           *mime_type,
                  MsfResourceType       data_type,
                  const unsigned char  *data,
                  MSF_INT32             data_len,
                  const char           *src_path,
                  const char           *file_name);

#ifdef MSF_CFG_OBJECT_ACTION_EXT
void
msf_object_action_ext(MSF_UINT8             src_modId, 
                      const char           *mime_type,
                      MsfResourceType       data_type,
                      const unsigned char  *data,
                      MSF_INT32             data_len,
                      const char           *src_path,
                      const char           *file_name,
                      const char*           excl_act_strings[],
                      MSF_INT32             excl_act_strings_cnt);
#endif

/**********************************************************************
 * Only used internally:
 **********************************************************************/
#ifndef MSF_SIGNAL_API_REVISED
  /* 6 bytes = 2 bytes signal + 1 byte source + 1 byte dest + 2 bytes data length. */
#define MSF_SIGNAL_HEADER_LENGTH   6



#define msf_cvt_content_data gmms_msf_cvt_content_data

#define msf_cvt_module_start gmms_msf_cvt_module_start

#define msf_cvt_module_terminate gmms_msf_cvt_module_terminate

#define msf_cvt_module_status gmms_msf_cvt_module_status

#define msf_cvt_module_execute_cmd gmms_msf_cvt_module_execute_cmd

#define msf_cvt_timer_set gmms_msf_cvt_timer_set

#define msf_cvt_timer_reset gmms_msf_cvt_timer_reset

#define msf_cvt_timer_expired gmms_msf_cvt_timer_expired

#define msf_cvt_wid_notify gmms_msf_cvt_wid_notify

#define msf_cvt_wid_action gmms_msf_cvt_wid_action

#define msf_cvt_wid_user_event gmms_msf_cvt_wid_user_event

#define msf_cvt_wid_access_key gmms_msf_cvt_wid_access_key

#define msf_cvt_pipe_notify gmms_msf_cvt_pipe_notify

#define msf_cvt_file_notify gmms_msf_cvt_file_notify

#define msf_cvt_socket_connect_response gmms_msf_cvt_socket_connect_response

#define msf_cvt_socket_notify gmms_msf_cvt_socket_notify

#define msf_cvt_socket_host_by_name gmms_msf_cvt_socket_host_by_name

#define msf_cvt_content_send gmms_msf_cvt_content_send

#define msf_cvt_content_send_ack gmms_msf_cvt_content_send_ack

#define msf_cvt_tel_make_call_resp gmms_msf_cvt_tel_make_call_resp

#define msf_cvt_tel_send_dtmf_resp gmms_msf_cvt_tel_send_dtmf_resp

#define msf_cvt_pb_add_entry_resp gmms_msf_cvt_pb_add_entry_resp

#define msf_cvt_icon_list gmms_msf_cvt_icon_list

#define msf_cvt_get_icons_resp gmms_msf_cvt_get_icons_resp

#define msf_cvt_object_action gmms_msf_cvt_object_action

#define msf_cvt_open_dlg_response gmms_msf_cvt_open_dlg_response

#define msf_cvt_save_dlg_response gmms_msf_cvt_save_dlg_response

#define msf_cvt_save_as_response gmms_msf_cvt_save_as_response

#define msf_signal_reg_functions gmms_msf_signal_reg_functions

#define msf_signal_create gmms_msf_signal_create

#define msf_signal_destruct gmms_msf_signal_destruct

#define msf_signal_get_signal_id gmms_msf_signal_get_signal_id

#define msf_signal_get_source gmms_msf_signal_get_source

#define msf_signal_get_destination gmms_msf_signal_get_destination

#define msf_signal_get_user_data gmms_msf_signal_get_user_data
#endif /*MSF_SIGNAL_API_REVISED*/

#define msf_signal_send gmms_msf_signal_send

#define msf_signal_retrieve gmms_msf_signal_retrieve

#define msf_timer_set gmms_msf_timer_set

#define msf_timer_reset gmms_msf_timer_reset

#define msf_module_is_created gmms_msf_module_is_created

#define msf_module_is_active gmms_msf_module_is_active

#define msf_module_is_terminated gmms_msf_module_is_terminated

#define msf_module_start gmms_msf_module_start

#define msf_module_terminate gmms_msf_module_terminate


#define msf_content_send gmms_msf_content_send

#define msf_content_send_no_ext gmms_msf_content_send_no_ext

#define msf_content_send_no_drm_no_ext gmms_msf_content_send_no_drm_no_ext

#define msf_get_icons gmms_msf_get_icons

#define msf_object_action gmms_msf_object_action

void msf_content_data_free(MSF_UINT8 modId, msf_content_data_t *contentData);


#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef MSF_REGISTRY_SUPPORT
#define MSF_REG_SET_TYPE_PATH             0
#define MSF_REG_SET_TYPE_INT              1
#define MSF_REG_SET_TYPE_STR              2
#define MSF_REG_SET_TYPE_DELETED          3

#define MSF_REG_MODID_INTEGRATION         -1

void*
msf_registry_set_int_commit (void* handle);

void
msf_registry_set_free_handle (MSF_UINT8 modId, void* handle);
#endif

typedef void(*msf_error_display_fp_t)(void);

extern void msf_register_error_display_function(msf_error_display_fp_t fp);
extern void msf_display_error(void);

#define MSF_REGISTER_ERROR_DISPLAY_FUNCTION msf_register_error_display_function
#define MSF_DISPLAY_ERROR   msf_display_error

#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#ifdef MSF_CFG_TRANSCODING_SUPPORT
/*
 * Search given host name in the black list. Returns true if not found, flase otherwise.
 */
MSF_BOOL
msf_is_transcoding_allowed(MSF_UINT8 module, const char *url);
#endif

#endif
