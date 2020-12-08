#ifndef _MMS_ADP_STRUCT_H
#define _MMS_ADP_STRUCT_H 

#include "kal_general_types.h"
#include "app_ltlcom.h"

/*Max length of PLMN number */
#define MMS_MAX_PLMN_NUM_LEN 7
#define MMS_MAX_MEM_CARD_DRV_COUNT 5 

/* This enum is used to specify both of sim identifier and status of sim mode. */
typedef enum
{
    MMS_SIM_ID_DEFAULT,      /* Default sim card is SIM1 */
    MMS_SIM_ID_SIM1,         /* SIM1, Sim mode only supports SIM1 */
    MMS_SIM_ID_SIM2,         /* SIM2, Sim mode only supports SIM2 */
    MMS_SIM_ID_DUAL_SIM,     /* SIM mode supports dual sim*/
    MMS_SIM_ID_NO_SIM,       /* No available sim */
    MMS_SIM_ID_FLIGHT_MODE,  /* Phone is in flight mode */
    MMS_SIM_ID_MAX_ITEM      /* Max items of mms_sim_id_enum */
}mms_sim_id_enum;

/* This enum is used to specify type of target data. */
typedef enum
{
    MMS_TARGET_DATA_ROAMING_STATUS,	/* Roaming status of target */
    MMS_TARGET_DATA_OWNER_NUMBER,		/* Owner number of target */
    MMS_TARGET_DATA_PLMN_NUMBER,		/* Plmn number of target */
    MMS_TARGET_DATA_MMS_VERSION,		/* MMS version of target */
    MMS_TARGET_DATA_USER_AGENT,			/* User agent of target */
    MMS_TARGET_DATA_TOTAL						/* Max number of target data */
}mms_target_data_type_enum;

/* This structure is used by local parameter of MSG_ID_MMS_TARGET_DATA_IND.*/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */	
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 data_type;   /* mms_target_data_type_enum */
}mms_target_data_ind_struct;

/* This structure is used by MMS_TARGET_DATA_ROAMING_STATUS target data*/
typedef struct
{
    kal_bool is_roaming;
    kal_int32 sim_id; /* 0: SIM1, 1:SIM2 */
}mms_target_data_roaming_status_struct;

/* This structure is used by MMS_TARGET_DATA_OWNER_NUMBER target data*/
typedef struct
{
    kal_uint8 owner_number[128];    /* MMA_MAX_ADDR_LEN */
}mms_target_data_owner_number_struct;

/* This structure is used by MMS_TARGET_DATA_PLMN_NUMBER target data*/
typedef struct
{
    kal_uint8 plmn_number[MMS_MAX_PLMN_NUM_LEN]; /*MMS_MAX_PLMN_NUM_LEN, the PLMN number (digit)*/
}mms_target_data_plmn_number_struct;

/* This structure is used by MMS_TARGET_DATA_MMS_VERSION target data*/
typedef struct
{
    kal_uint8 mms_version;  /* 0x10 is 1.0, 0x11 is 1.1, 0x12 is 1.2 */
}mms_target_data_mms_version_struct;

/* This structure is used by MMS_TARGET_DATA_USER_AGENT target data*/
typedef struct
{
    kal_uint32 user_agent_len;
    /* kal_uint8  user_agent[]; */
}mms_target_data_user_agent_struct;


/* DOM-NOT_FOR_SDK-BEGIN */
/* OBIGO Q03C MMS V01 only */

typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;
   kal_uint8  sim_status;        /* Which SIM card in slot */
   kal_uint8  setting_mode;      /*  Which SIM card is enabled in Setting */
}mms_sim_info_notify_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_int32 total_unread_num;
}mms_nmgr_info_rsp_struct;

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*OBIGO Q03C MMS V02 only */
/*Max length of data inserted. The value must be divided by 4*/
#define MMS_MAX_MULTI_OBJECT_INSERT_DATA_LEN 124 

typedef enum
{
    MMS_MULTI_OBJECT_INSERT_TYPE_ADDR_PHONE_NUMBER,	/* Phone number encoded by UTF8 */
    MMS_MULTI_OBJECT_INSERT_TYPE_ADDR_EMAIL,				/* Email encoded by UTF8 */
    MMS_MULTI_OBJECT_INSERT_TYPE_TOTAL
}mms_multi_object_insert_type_enum;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 request_id;
    kal_uint32 num_of_object;
    kal_bool more;
}mms_multi_object_insert_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 type; /*mms_multi_object_insert_type_enum*/
    kal_uint8 object[MMS_MAX_MULTI_OBJECT_INSERT_DATA_LEN];
}mms_multi_object_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result; /*KAL_TRUE: OK, KAL_FASLE: Aborted by MMS adaptation*/
    kal_uint32 request_id;
}mms_multi_object_insert_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 request_id;
    kal_bool is_aborted;
    kal_uint32 num_of_object;
    kal_bool more;
}mms_multi_object_insert_continue_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result; /*KAL_TRUE: OK, KAL_FASLE: Aborted by MMS adaptation*/
    kal_uint32 request_id;
}mms_multi_object_insert_continue_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 drv_count;
    kal_uint8 drv_list[MMS_MAX_MEM_CARD_DRV_COUNT];
}mms_mem_card_plug_in_out_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    kal_uint8 drv_enum;
}mms_mem_card_plug_in_out_res_struct;

/* Global context to provide the message ID of the sync deleted mms */
typedef struct mms_sync_delete_msg_ind_struct_st
{
    LOCAL_PARA_HDR
	kal_uint32 msg_id;
}mms_sync_delete_msg_ind_struct;

typedef struct mms_poweroff_struct_st
{
    LOCAL_PARA_HDR
    kal_uint32 request_id;
}mms_poweroff_struct;
/* DOM-NOT_FOR_SDK-END */

#endif
