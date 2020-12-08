#ifndef _PMG_STRUCT_H
#define _PMG_STRUCT_H 

#include "kal_general_types.h"
#include "MMI_features.h"


/* Maximum Push message number supported in storage */
#define WAP_PMG_MAX_PUSH_MESSAGES           20
/* Maximum info item number supported for each SI message */
#define WAP_PMG_MAX_INFOITEMS               10
/* Maximum entry number sent in one MSG_ID_WPS_PMG_MSG_LIST_CNF primitive response */
#define WAP_PMG_MAX_MSG_LIST_SIZE           10
/******************************************************************
  * Maximum entry number of list sent to Push Inbox application via
  * MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF primitive                   
  ******************************************************************/
#define WAP_PMG_MAX_MSG_INFOITEM_LIST_SIZE  5
/************************************************************************
  * Maximum address entry number of while/black list configuration in one
  * MSG_ID_WPS_PMG_XXX_ADDR_LIST_REQ primitive request.                  
  ************************************************************************/
#define WAP_PMG_MAX_MSG_ADDR_LIST_SIZE      5
/*******************************************************************
  * Maximum array entry number of deleted message information in one
  * MSG_ID_WPS_PMG_DELETE_IND primitive indication.                 
  *******************************************************************/
#define WAP_PMG_MAX_DELETED_MSG_LIST_SIZE   5

/************************************************************************
  * Maximum character number for hyperlink information of each list entry
  * carried in MSG_ID_WPS_PMG_MSG_LIST_CNF primitive response            
  ************************************************************************/
#define WAP_PMG_MAX_MSG_LIST_HREF_CHARS     48
/*********************************************************************
  * Maximum character number for content text information of each list
  * entry carried in MSG_ID_WPS_PMG_MSG_LIST_CNF primitive response   
  *********************************************************************/
#define WAP_PMG_MAX_MSG_LIST_TEXT_CHARS     30
#ifdef __MMI_OP12_BRW_PUSH_LARGE_CONTENT_SUPPORT__
/* Maximum character number for message content text information carried in MSG_ID_WPS_PMG_GET_MSG_CNF 
   primitive response or other message inquiry primitive response */
#define WAP_PMG_MAX_MSG_TEXT_CHARS          160
#else
/************************************************************************
  * Maximum character number for message content text information carried
  * in MSG_ID_WPS_PMG_GET_MSG_CNF primitive response or other message
  * inquiry primitive response                                           
  ************************************************************************/
#define WAP_PMG_MAX_MSG_TEXT_CHARS          160
#endif
/*************************************************************************
  * Maximum character number for message OA/SC address information carried
  * in MSG_ID_WPS_PMG_GET_MSG_CNF primitive response or other message
  * inquiry primitive response                                            
  *************************************************************************/
#define WAP_PMG_MAX_ADDR_CHARS              128
/**********************************************************************
  * Maximum character number for class attribute information of message
  * info item carried in MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF primitive
  * response                                                           
  **********************************************************************/
#define WAP_PMG_MAX_INFOITEM_CLASS_CHARS    96
/**************************************************************************
  * Maximum character number for text attribute information of message info
  * item carried in MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF primitive response  
  **************************************************************************/
#define WAP_PMG_MAX_INFOITEM_TEXT_CHARS     96
/*************************************************************************
  * Maximum character number for hyperlink information carried in
  * MSG_ID_WPS_PMG_GET_MSG_CNF primitive response or other message inquiry
  * primitive response                                                    
  *************************************************************************/
#define WAP_PMG_MAX_MSG_HREF_CHARS          255

/* The separator charater to delimit the SC/OA address pair */
#define WAP_PMG_ADDR_PHONE_SEP	((kal_uint8)'/')

#define WAP_PMG_DLG_MAX_POPUP_SIZE      62
#define WAP_PMG_DLG_MAX_TITLE_SIZE      32
#define WAP_PMG_DLG_MAX_SOFTKEY_SIZE    14
#define WAP_PMG_DLG_MAX_CONTENT_SIZE    162
#define WAP_PMG_DLG_MAX_ITEM_TEXT_SIZE  62

#define WAP_PMG_DLG_MAX_SELECT_ITEMS    5

#define WAP_PMG_USERNAME_PASSWORD_LEN    41

/* String encoding type */
typedef enum
{
    WAP_PMG_STRTYPE_ASCII,  /* ASCII encoding */
    WAP_PMG_STRTYPE_UCS2    /* UCS2 encoding */
} wps_pmg_dcs_enum;

/* Response status type */
typedef enum
{
    WAP_PMG_STATUS_OK,      /* Request completed successfully */
    WAP_PMG_STATUS_FAIL,    /* Request completed in failure */
    WAP_PMG_STATUS_NOT_FOUND    /* Request completed in failure due to message not found */
} wps_pmg_status_enum;

/* Query parameter type */
typedef enum
{
    WAP_PMG_PARAM_NOT_SPECIFIED,  /* Don't care the parameter value */
    WAP_PMG_PARAM_YES,            /* The boolean parameter value should be TRUE */
    WAP_PMG_PARAM_NO              /* The boolean parameter value should be FALSE */
} wps_pmg_param_enum;

/* Push message type */
typedef enum
{
    WAP_PMG_MSGTYPE_NULL,  /* Dummy starter */
    WAP_PMG_MSGTYPE_SI,    /* Service indication message */
    WAP_PMG_MSGTYPE_SL,    /* Service loading message */
    WAP_PMG_MSGTYPE_CO,    /* Cache operation message */
    WAP_PMG_MSGTYPE_SIA    /* Session initiation application message */
} wps_pmg_msg_type_enum;

/* Push message priority/action type */
typedef enum
{
    WAP_PMG_MSGPRIO_NULL,      /* Dummy starter */
    WAP_PMG_MSGPRIO_LOW,       /* SI/SL priority low */
    WAP_PMG_MSGPRIO_MEDIUM,    /* SI priority medium */
    WAP_PMG_MSGPRIO_HIGH,      /* SI/SL priority high */
    WAP_PMG_MSGPRIO_NONE,      /* SI action none */
    WAP_PMG_MSGPRIO_DELETE,    /* SI action delete */
    WAP_PMG_MSGPRIO_CACHE      /* SL action cache */
} wps_pmg_msg_prio_enum;

/* Address type */
typedef enum
{
    WAP_PMG_ADDR_NULL,    /* Dummy starter */
    WAP_PMG_ADDR_PHONE,   /* Phone number address */
    WAP_PMG_ADDR_IP,      /* IP address */
    WAP_PMG_ADDR_TEXT     /* Text address */
} wps_pmg_addr_type_enum;

/* Push message folder type */
typedef enum
{
    WAP_PMG_FOLDER_INBOX  /* Inbox folder */
} wps_pmg_folder_enum;

/* Push message retrieval type */
typedef enum
{
    WAP_PMG_RETR_DISABLED,                  /* Push message retrieval not allowed */
    WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED,    /* Only allowed trusted push message */
    WAP_PMG_RETR_ACCEPT_ALL                 /* Allow all Push message retrievals */
} wps_pmg_retrieval_enum;

/* White list match behavior */
typedef enum
{
    WAP_PMG_WL_DISABLED,         /* White list functionality disabled */
    WAP_PMG_WL_ACTION_NOTIFY,    /* White list functionality enabled. Notify user if address not matched */
    WAP_PMG_WL_ACTION_DISCARD    /* White list functionality enabled. Discard message if address not matched */
} wps_pmg_white_list_action_enum;

/* Black list match behavior */
typedef enum
{
    WAP_PMG_BL_DISABLED,        /* Black list functionality disabled */
    WAP_PMG_BL_ACTION_NOTIFY    /* Black list functionality enabled. Notify user if address matched */
} wps_pmg_black_list_action_enum;

/* Notification dialog type */
typedef enum
{
    WAP_PMG_DLG_SIA_CONFIRM,            /* SIA connection confirm dialog */
    WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM,    /* White/Black list notification dialog */
    WAP_PMG_DLG_TOTAL                   /* Dummy end item */
} wps_pmg_dlg_type_enum;


typedef enum
{
    WAP_PMG_SIM_DEFAULT = 1,
    WAP_PMG_SIM1 = 1,
    WAP_PMG_SIM2,
    WAP_PMG_SIM3,
    WAP_PMG_SIM4,
    WAP_PMG_SIM_ALL,
    WAP_PMG_SIM_END
}wps_pmg_sim_type_enum;


typedef enum
{
    WAP_PMG_CONNECTION_TYPE_HTTP,
    WAP_PMG_CONNECTION_TYPE_WSP_CO,
    WAP_PMG_CONNECTION_TYPE_END
}wps_pmg_conn_type_enum;


/* Message basic information structure used in wps_pmg_delete_ind_struct */
typedef struct 
{
    kal_int32 msg_id;    /* Message ID */
    kal_uint8 msg_type;  /* Message type. Ref to wps_pmg_msg_type_enum */
} pmg_msg_id_struct;

/* Message general information structure carried in MSG_ID_WPS_PMG_MSG_LIST_CNF primitive response */
typedef struct 
{
    kal_int32 msg_id;      /* Message ID */
    kal_uint8 msg_type;    /* Message type. Ref to wps_pmg_msg_type_enum */
    kal_uint8 href[WAP_PMG_MAX_MSG_LIST_HREF_CHARS+1];    /* Zero-terminated ASCII string partial URL (end with ¡K characters where needed) */
    kal_uint32 created;    /* Message creation timestamp in UTC format */
    kal_uint32 expired;    /* Message expiration timestamp in UTC format */
    kal_uint8 priority;    /* Message priority type. Ref to wps_pmg_msg_prio_enum */
    kal_uint8 text[WAP_PMG_MAX_MSG_LIST_TEXT_CHARS+2];    /* Zero-terminated ASCII or UCS2 string partial message text (end with ¡K characters where needed) */
    kal_uint8 text_type;   /* Text encoding type. Ref. to wps_pmg_dcs_enum */
    kal_uint8 read;        /* 0: unread, 1: read */
/* for dual sim support */
   kal_uint32 sim_id;
} pmg_msg_list_struct;

/* Address information structure */
typedef struct 
{
    kal_uint8 addr[WAP_PMG_MAX_ADDR_CHARS+1];  /***********************************************************************
                                                 * Zero-terminated ASCII string if addr_type is IP or text.
                                                 * If addr_type is phone number, the address array = { <b>OA Addr</b>,
                                                 * WAP_PMG_ADDR_PHONE_SEP, <b>SC Addr</b>, WAP_PMG_ADDR_PHONE_SEP } and
                                                 * the OA and SC address strings must not include any zero-termination
                                                 * characters.
                                                 * <img name="SAP_SRV_PMG_network" />
                                                 * Some examples of handling the extreme cases are given below:
                                                 * \1. OA, SC both exist:
                                                 * 
                                                 * OA addr = &quot;1234&quot;
                                                 * SC addr = &quot;5678&quot;
                                                 * addr array =
                                                 * { '1', '2', '3', '4',
                                                 * WAP_PMG_ADDR_PHONE_SEP,
                                                 * '5', '6', '7', '8',
                                                 * WAP_PMG_ADDR_PHONE_SEP,
                                                 * 0, 0, 0, 0, ....etc}
                                                 * 
                                                 * \2. OA does not exist:
                                                 * 
                                                 * OA addr = &quot;&quot;
                                                 * SC addr = &quot;5678&quot;
                                                 * addr array =
                                                 * { WAP_PMG_ADDR_PHONE_SEP,
                                                 * '5', '6', '7', '8',
                                                 * WAP_PMG_ADDR_PHONE_SEP,
                                                 * 0, 0, 0, 0, ....etc}
                                                 * 
                                                 * \3. SC does not exist:
                                                 * 
                                                 * OA addr = &quot;1234&quot;
                                                 * SC addr = &quot;&quot;;
                                                 * addr array =
                                                 * { '1', '2', '3', '4',
                                                 * WAP_PMG_ADDR_PHONE_SEP,
                                                 * WAP_PMG_ADDR_PHONE_SEP,
                                                 * 0, 0, 0, 0, ....etc}                                                
                                                 ***********************************************************************/
    kal_uint8 addr_type;   /* Address type. Ref. to wps_pmg_addr_type_enum */
} pmg_addr_struct;

/*************************************************************************
  * Message detailed information structure returned in
  * MSG_ID_WPS_PMG_GET_MSG_CNF primitive or other message inquiry response
  *************************************************************************/
typedef struct 
{
	pmg_addr_struct smsc;	/* SMSC address used for trust list validation */
    kal_uint8 msg_type;     /* Message type. Ref to wps_pmg_msg_type_enum */
	kal_uint8 text_type;	/* Text encoding type. Ref. to wps_pmg_dcs_enum */
	pmg_addr_struct from;   /* Originating sender address (push-initiator address or URL) used for display only */
    kal_uint8 priority;     /* Message priority type. Ref to wps_pmg_msg_prio_enum */
	kal_uint8 read;         /* 0: unread, 1: read */
    kal_uint8 text[WAP_PMG_MAX_MSG_TEXT_CHARS+2];    /* Zero-terminated ASCII or UCS2 string message text */
    kal_uint8 has_info;     /* 0: no INFO tag present, non-zero:  number of INFO items */
	kal_int32 msg_id;       /* Message ID */
	kal_uint32 created;     /* Message creation timestamp in UTC format */
	kal_uint32 expired;     /* Message expiration timestamp in UTC format */
    kal_uint32 sim_id;	

} pmg_detailed_msg_struct;

/* Message info item structure returned in MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF primitive response */
typedef struct 
{
    kal_uint8 info_class[WAP_PMG_MAX_INFOITEM_CLASS_CHARS+2];  /* Zero-terminated string for class attribute */
    kal_uint8 info_text[WAP_PMG_MAX_INFOITEM_TEXT_CHARS+2];    /* Zero-terminated string for text attribute */
    kal_uint8 class_type;  /* Class attribute string encoding type. Ref. to wps_pmg_dcs_enum */
    kal_uint8 text_type;   /* Text attribute string encoding type. Ref. to wps_pmg_dcs_enum */
} pmg_msg_infoitem_struct;


/* Configuration setting structure carried in MSG_ID_WPS_PMG_CONFIG_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 wap_push_enabled;   /**************************************************************************
                                    * To enable/disable WAP PUSH message, ex. SI, SL, CO and SIA, retrieval.
                                    * Ref. to wps_pmg_retrieval_enum.
                                    * The received push messages will be discarded automatically by PHS if it
                                    * is set as WAP_PMG_RETR_DISABLED, and will not be available at a later
                                    * stage when queried by application. If set as
                                    * WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED, only those message with WSP
                                    * Push-Flag header field¡¦s Authenticated or Trusted bit set can be
                                    * retrieved. If set as WAP_PMG_RETR_ACCEPT_ALL, all WAP Push messages
                                    * would be retrieved. Even though this setting item has been set to
                                    * WAP_PMG_RETR_DISABLED, application is still able to interact with the
                                    * adaption layer, for example, application can still retrieve a list of
                                    * SI messages even if this setting item has been set to
                                    * WAP_PMG_RETR_DISABLED.                                                 
                                    **************************************************************************/
    kal_uint8 sl_enabled;         /* Enable SL low/medium/cache message retrieval. 0=disabled, 1=enabled */
    kal_uint8 trust_enabled;      /***************************************************************************
                                    * White list behavior. Ref. to wps_pmg_white_list_action_enum.
                                    * When set as WAP_PMG_WL_DISABLED, message from any source address would
                                    * be admitted and processed with later procedure, ex. black list check if
                                    * enabled; when set as WAP_PMG_WL_ACTION_NOTIFY, PHS would check incoming
                                    * WAP push message address against the white list addresses. If the
                                    * incoming message source doesn¡¦t match any of the entries, user would be
                                    * notified to take later action. If set as WAP_PMG_WL_ACTION_DISCARD, PHS
                                    * would check against the white list addresses as well but discard the
                                    * message silently if not matched.                                        
                                    ***************************************************************************/
    kal_uint8 black_list_enabled; /*************************************************************************
                                    * Black list behavior. Ref. to wps_pmg_black_list_action_enum.
                                    * When set as WAP_PMG_BL_DISABLED, message from any source address would
                                    * be admitted and processed; when set as WAP_PMG_BL_ACTION_NOTIFY, PHS
                                    * would check incoming WAP push message address against the black list
                                    * addresses. If the incoming message source matches any of the entries,
                                    * the message would be discarded silently. Otherwise user would be
                                    * notified to take later action.                                        
                                    *************************************************************************/
    kal_uint32 max_trust_addr_no; /* Applicatiob-customized maximum white list entry number */
    kal_uint32 max_black_addr_no; /* Applicatiob-customized maximum black list entry number */
} wps_pmg_config_req_struct;

/* Configuration result returned in MSG_ID_WPS_PMG_CONFIG_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 status;    /* Configuration result. Should be WAP_PMG_STATUS_OK */
} wps_pmg_config_cnf_struct;

/* The incoming message information structure carried in MSG_ID_WPS_PMG_NEW_MSG_IND primitive inidication */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    pmg_detailed_msg_struct msg_data;  /* The incoming message information */
} wps_pmg_new_msg_ind_struct;

/* The deleted message list structure carried in MSG_ID_WPS_PMG_DELETE_IND primitive inidication */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 size;    /* The deleted message list size */
    pmg_msg_id_struct msgs[WAP_PMG_MAX_DELETED_MSG_LIST_SIZE];  /* The deleted message list information */
    kal_uint32  msg_count;
} wps_pmg_delete_ind_struct;

/* The replacing message information structure carried in MSG_ID_WPS_PMG_REPLACE_IND primitive inidication */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 msg_type;  /* The replaced/replacing message type. Ref to wps_pmg_msg_type_enum */
    kal_int32 msg_id;    /* The replaced message ID */
    pmg_detailed_msg_struct msg_data;    /* The replacing message information */
} wps_pmg_replace_ind_struct;

/* The criteria information structure carried in MSG_ID_WPS_PMG_MSG_COUNT_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;      /* Transaction ID */
    kal_uint8 msg_type;      /* The message type criteria. Ref to wps_pmg_msg_type_enum and wps_pmg_param_enum */
    kal_uint8 is_read;       /* The read status criteria. Ref to wps_pmg_param_enum */
    kal_uint8 is_expired;    /* The expiration status criteria. Ref to wps_pmg_param_enum */
    kal_uint8 has_info;      /* The info item criteria. Ref to wps_pmg_param_enum */
} wps_pmg_msg_count_req_struct;

/* message read status request structure sks  */

typedef void (*srv_wap_push_msg_read_status_func) (kal_bool Read_Status);

typedef struct
{
 	kal_uint8 ref_count;
	kal_uint16 msg_len;

	kal_int32 msg_id;
	srv_wap_push_msg_read_status_func status_func;
	
}wps_pmg_msg_read_status_req_struct;


#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
typedef struct
	{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_uint8 push_turn_on_switch;
	}wps_pmg_push_turn_on_off_req_struct;
#endif /*__MMI_PUSH_TURN_ON_OFF_SWITCH__*/
/*sks*/

/* The message count information structure returned in MSG_ID_WPS_PMG_MSG_COUNT_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32  trans_id;     /* Transaction ID. Should be the same as wps_pmg_msg_count_req_struct */
   kal_uint32 msg_count_sim1;
#if(MMI_MAX_SIM_NUM >= 2)
   kal_uint32 msg_count_sim2;
	#if(MMI_MAX_SIM_NUM >= 3)
	kal_uint32 msg_count_sim3;
	#endif
	#if(MMI_MAX_SIM_NUM >= 4)
	kal_uint32 msg_count_sim4;
	#endif

#endif /* (MMI_MAX_SIM_NUM >= 2) */

} wps_pmg_msg_count_cnf_struct;

/* The criteria information structure carried in MSG_ID_WPS_PMG_MSG_LIST_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;      /* Transaction ID */
    kal_uint8 msg_type;      /* The message type criteria. Ref to wps_pmg_msg_type_enum and wps_pmg_param_enum */
    kal_uint8 is_read;       /* The read status criteria. Ref to wps_pmg_param_enum */
    kal_uint8 is_expired;    /* The expiration status criteria. Ref to wps_pmg_param_enum */
    kal_uint8 has_info;      /* The info item criteria. Ref to wps_pmg_param_enum */
    kal_uint32 start_from;   /* 0: Initial list retrieval, or value of ¡§more¡¨ parameter from response primitive to fetch remaining list. */
    kal_uint32 size;         /* The expected returned list entry number. 0: retrieve all messages */
} wps_pmg_msg_list_req_struct;

/* The message list information structure returned in MSG_ID_WPS_PMG_MSG_LIST_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;      /* Transaction ID. Should be the same as wps_pmg_msg_list_req_struct */
    pmg_msg_list_struct msg_list_data[WAP_PMG_MAX_MSG_LIST_SIZE];    /* General message information list */
    kal_uint32 size;         /* Number of returned message entry in this primitive */
    kal_uint32 more;         /* 0: no more data, non-zero: next start index */
    kal_uint32 size_remain;  /* 0: no more data, non-zero: number of messages remains */
} wps_pmg_msg_list_cnf_struct;

/* The request structure carried in MSG_ID_WPS_PMG_MSG_LIST_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;    /* Transaction ID */
    kal_int32 msg_id;      /* The request message ID */
} wps_pmg_get_msg_req_struct;

/* The detailed message information structure returned in MSG_ID_WPS_PMG_GET_MSG_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
	kal_uint8 status;      /* Request result. Ref. to wps_pmg_status_enum */
    kal_int32 trans_id;    /* Transaction ID. Should be the same as wps_pmg_get_msg_req_struct */
    pmg_detailed_msg_struct msg_data;    /* The request message information */
    
} wps_pmg_get_msg_cnf_struct;

/* The info item request structure carried in MSG_ID_WPS_PMG_GET_MSG_INFOTAG_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;    /* Transaction ID */
    kal_int32 msg_id;      /* The request message ID */
    kal_uint32 start_from; /* 0: Initial list retrieval, or value of ¡§more¡¨ parameter from response primitive to fetch remaining list. */
} wps_pmg_get_msg_infotag_req_struct;

/* The info item information structure returned in MSG_ID_WPS_PMG_GET_MSG_INFOTAG_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

	kal_uint8 status;      /* Request result. Ref. to wps_pmg_status_enum */
    kal_int32 trans_id;    /* Transaction ID. Should be the same as wps_pmg_get_msg_infotag_req_struct */
    pmg_msg_infoitem_struct info_item_list_data[WAP_PMG_MAX_MSG_INFOITEM_LIST_SIZE];  /* The info item information */
    kal_uint32 size;       /* Number of returned info item(s) in this primitive */
    kal_uint32 more;       /* 0: no more data, non-zero: next start index */
} wps_pmg_get_msg_infotag_cnf_struct;

/* The request structure carried in MSG_ID_WPS_PMG_DELETE_MSG_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;    /* Transaction ID */
    kal_int32 msg_id;      /* The request message ID */
} wps_pmg_delete_msg_req_struct;

/* The result structure returned in MSG_ID_WPS_PMG_DELETE_MSG_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 status;     /* Request result. Ref. to wps_pmg_status_enum */
    kal_int32 trans_id;   /* Transaction ID. Should be the same as wps_pmg_delete_msg_req_struct */
    kal_int32 msg_id;
} wps_pmg_delete_msg_cnf_struct;

/* The deletion criteria structure carried in MSG_ID_WPS_PMG_DELETE_ALL_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 msg_type;    /* The to-be-all-deleted message type. Ref to wps_pmg_msg_type_enum and wps_pmg_param_enum */
    kal_int32 trans_id;    /* Transaction ID */
} wps_pmg_delete_all_req_struct;

/* The result structure returned in MSG_ID_WPS_PMG_DELETE_ALL_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 status;      /* Request result. Ref. to wps_pmg_status_enum */
    kal_int32 trans_id;    /* Transaction ID. Should be the same as wps_pmg_delete_all_req_struct */
} wps_pmg_delete_all_cnf_struct;

/* The to-be-updated message information structure carried in MSG_ID_WPS_PMG_UPDATE_MSG_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 read;        /* The updating read status value */
    kal_int32 trans_id;    /* Transaction ID */
    kal_int32 msg_id;      /* The to-be-updated message ID */
} wps_pmg_update_msg_req_struct;

/* The result structure returned in MSG_ID_WPS_PMG_UPDATE_MSG_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 status;      /* Request result. Ref. to wps_pmg_status_enum */
    kal_int32 trans_id;    /* Transaction ID. Should be the same as wps_pmg_update_msg_req_struct */
	kal_int32 msg_id;      /* The to-be-updated message ID */
} wps_pmg_update_msg_cnf_struct;

/* The to-be-updated message information structure carried in MSG_ID_WPS_PMG_UPDATE_MSG_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 read;        /* The updating read status value */

} wps_pmg_update_all_msg_req_struct;


/* The to-be-updated message information structure carried in MSG_ID_WPS_PMG_UPDATE_MSG_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
   wps_pmg_status_enum status_result;

} wps_pmg_update_all_msg_cnf_struct;




/* The SIA dialog information structure carried in MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 trans_id;        /* Transaction ID */
    pmg_addr_struct host_addr;  /* Peer host address */
    kal_uint16 host_port;       /* Peer host port */
} wps_pmg_dlg_sia_confirm_req_struct;

/* The SIA dialog decision returned in MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 result;      /* accept: TRUE, reject: FALSE */
    kal_int32 trans_id;    /* Transaction ID. Should be the same as corresponding wps_pmg_dlg_sia_confirm_req_struct */
} wps_pmg_dlg_sia_confirm_cnf_struct;

/* The white/black list dialog information structure carried in MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 trans_id;    /* Transaction ID */
    kal_uint8 msg_type;     /* The incoming message type. Ref to wps_pmg_msg_type_enum */
    kal_uint8 text_type;    /* SI Message content string encoding type. Ref. to wps_pmg_dcs_enum */
    kal_uint8 text[WAP_PMG_MAX_MSG_TEXT_CHARS+2];  /*************************************************************************
                                                     * Message content information. The field could be empty and, when empty,
                                                     * the ¡§text_type¡¨ field should be ignored.                            
                                                     *************************************************************************/
    kal_uint8 href[WAP_PMG_MAX_MSG_HREF_CHARS+2];  /* SI or SL Hyperlink information */
    pmg_addr_struct smsc;   /************************************************************************
                              * Message sender address (SMSC part): If the message is sent via SMS,
                              * SMSC address would be provided in ¡§smsc¡¨ field while originating
                              * address in ¡§from¡¨ field. If not by SMS, the smsc field with address
                              * type equals to WAP_PMG_ADDR_NULL should be ignored.                  
                              ************************************************************************/
    pmg_addr_struct from;   /* Message sender address (Originating sender part): push-initiator address or URL */
} wps_pmg_dlg_unknown_addr_req_struct;

/* The white/black list dialog decision returned in MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;	/* accept: TRUE, reject: FALSE */    
    kal_int32 trans_id;    /* Transaction ID. Should be the same as corresponding wps_pmg_dlg_unknown_addr_req_struct */

} wps_pmg_dlg_unknown_addr_cnf_struct;

/* The configured white list information structure carried in MSG_ID_WPS_PMG_TRUST_ADDR_LIST_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;    /* Transaction ID */
    kal_int32 segment;     /* Start from 0. Used if mulitple requests are needed */
    kal_int32 size;        /* Number of to-be-set address entreis in this primitive */
    kal_int32 total_segment; 
    pmg_addr_struct addresses[WAP_PMG_MAX_MSG_ADDR_LIST_SIZE];    /* To-be-set address entreis */
} wps_pmg_trust_addr_list_req_struct;

/* The configured black list information structure carried in MSG_ID_WPS_PMG_BLACK_ADDR_LIST_REQ primitive request */
typedef wps_pmg_trust_addr_list_req_struct wps_pmg_black_addr_list_req_struct;

/* The response returned in MSG_ID_WPS_PMG_TRUST_ADDR_LIST_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;    /* Transaction ID. Should be the same as corresponding wps_pmg_trust_addr_list_req_struct */
} wps_pmg_trust_addr_list_cnf_struct;

/* The response returned in MSG_ID_WPS_PMG_BLACK_ADDR_LIST_CNF primitive response */
typedef wps_pmg_trust_addr_list_cnf_struct wps_pmg_black_addr_list_cnf_struct;

/* The folder information structure carried in MSG_ID_WPS_PMG_DELETE_FOLDER_IND primitive indication */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint8 folder;	/* The folder under which all messages were deleted. Ref. to wps_pmg_folder_enum */
} wps_pmg_delete_folder_ind_struct;

/* The structure used to query dialog details carried in MSG_ID_WAP_PMG_DLG_QUERY_REQ primitive request */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;
    kal_int32 dlg_trans_id;  /* ref trans_id in wps_pmg_dlg_unknown_addr_req_struct or wps_pmg_dlg_sia_confirm_req_struct */
} wps_pmg_dlg_query_req_struct;

/* The dialog information details returned in MSG_ID_WAP_PMG_DLG_QUERY_CNF primitive response */
typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_int32 trans_id;
    kal_uint8 result;      /* found: TRUE, not found: FALSE */
    kal_uint8 dlg_type;    /* wps_pmg_dlg_type_enum */
    kal_int32 dlg_trans_id;
    union {
        wps_pmg_dlg_sia_confirm_req_struct sia;  /* if dlg_type == WAP_PMG_DLG_SIA_CONFIRM */
        wps_pmg_dlg_unknown_addr_req_struct msg; /* if dlg_type == WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM */
    } dlg_data_union;
} wps_pmg_dlg_query_cnf_struct;

typedef struct 
{  
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 str_id;   
} wps_pmg_error_dlg_struct;


typedef struct {
  kal_uint16				proxy_port;
  kal_uint8					proxy_ip[4];
  wps_pmg_conn_type_enum	connection_type;
  kal_uint32				network_account_id;
  kal_uint8					username[WAP_PMG_USERNAME_PASSWORD_LEN];
  kal_uint8					password[WAP_PMG_USERNAME_PASSWORD_LEN];
} wps_pmg_channel_struct;

#endif  /* _PMG_STRUCT_H */
