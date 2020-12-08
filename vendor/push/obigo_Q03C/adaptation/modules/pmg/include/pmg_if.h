/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   pmg_if.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG function prototypes, constant/macro/structure definition 
 *   for module interface
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _pmg_if_h
#define _pmg_if_h

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif 

#ifndef _msf_def_h
#include "msf_def.h"
#endif 

#ifndef _pmg_fs_h
#include "pmg_fs.h"
#endif 

#ifndef _pmg_msg_h
#include "pmg_msg.h"
#endif 

#include "kal_release.h"

#ifndef _PMG_STRUCT_H
#include "pmg_struct.h"
#endif 


//suggested add
 #include "msf_dcvt.h"
    #include "msf_def.h"
    #include "pmg_main.h"
    #include "msf_cfg.h"
    #include "msf_core.h"
    #include "kal_general_types.h"
    #include "MMI_features.h"
    #include "msf_int.h"


#ifdef WPS_PMG_CONVERSATION_BOX
#include "umsrvstruct.h"
#endif /* WPS_PMG_CONVERSATION_BOX */
/**********************************************************************
 * Signals in PMG
 **********************************************************************/
#define PMG_SIG_GET_MSG_BY_ATTRIBUTE            ((MSF_MODID_PMG << 8) + 0x01)
#define PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY      ((MSF_MODID_PMG << 8) + 0x02)
#define PMG_SIG_DELETE_MSG                      ((MSF_MODID_PMG << 8) + 0x03)
#define PMG_SIG_CREATE_MSG                      ((MSF_MODID_PMG << 8) + 0x04)
#define PMG_SIG_INBOX_CONFIG_REQ                ((MSF_MODID_PMG << 8) + 0x05)
#define PMG_SIG_INBOX_MSG_COUNT_REQ             ((MSF_MODID_PMG << 8) + 0x06)
#define PMG_SIG_INBOX_MSG_LIST_REQ              ((MSF_MODID_PMG << 8) + 0x07)
#define PMG_SIG_INBOX_GET_MSG_REQ               ((MSF_MODID_PMG << 8) + 0x08)
#define PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ       ((MSF_MODID_PMG << 8) + 0x09)
#define PMG_SIG_INBOX_DELETE_MSG_REQ            ((MSF_MODID_PMG << 8) + 0x0A)
#define PMG_SIG_INBOX_DELETE_ALL_REQ            ((MSF_MODID_PMG << 8) + 0x0B)
#define PMG_SIG_INBOX_UPDATE_MSG_REQ            ((MSF_MODID_PMG << 8) + 0x0C)
#define PMG_SIG_INBOX_NEW_MSG_RSP               ((MSF_MODID_PMG << 8) + 0x0D)
#define PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ        ((MSF_MODID_PMG << 8) + 0x0E)
#define PMG_SIG_INBOX_DLG_RESPONSE              ((MSF_MODID_PMG << 8) + 0x0F)
#define PMG_SIG_UM_GET_MSG_NUM_REQ              ((MSF_MODID_PMG << 8) + 0x10)
#define PMG_SIG_UM_GET_LIST_REQ                 ((MSF_MODID_PMG << 8) + 0x11)
#define PMG_SIG_UM_DELETE_FOLDER_REQ            ((MSF_MODID_PMG << 8) + 0x12)
#define PMG_SIG_UM_MULTI_OP_REQ                 ((MSF_MODID_PMG << 8) + 0x13)
#define PMG_SIG_DISPLAY_DIALOG_REQ              ((MSF_MODID_PMG << 8) + 0x14)
#define PMG_SIG_UM_GET_MSG_INFO_REQ             ((MSF_MODID_PMG << 8) + 0x15)
#define PMG_SIG_INBOX_DLG_QUERY_REQ             ((MSF_MODID_PMG << 8) + 0x16)

#define PMG_SIG_CONTENT_DATA_ROUTE_REQ			((MSF_MODID_PMG << 8) + 0x17)	
#define PMG_SIG_SET_DATA_TO_SETTING_REQ			((MSF_MODID_PMG << 8) + 0x18)
#define PMG_SIG_SET_DEF_CONN					((MSF_MODID_PMG << 8) + 0x19)
#define PMG_SIG_SET_LIST_DATA_IND				((MSF_MODID_PMG << 8) + 0x20)
#define PMG_SIG_UM_GET_TRAVERSE_LIST_REQ	((MSF_MODID_PMG << 8) + 0x21)
#define PMG_SIG_INBOX_MSG_READ_STATUS_REQ	((MSF_MODID_PMG << 8) + 0x22)
#define PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ	((MSF_MODID_PMG << 8) + 0x23)






void PMGif_startInterface(void);

void *pmg_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

void pmg_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p);

#define PMG_SEND_SIGNAL(cvtFunc, signalName, srcmod, destmod) do {                      \
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);                         \
    cvtFunc (&cvt_obj, &param);                                                         \
    length = (MSF_UINT16)cvt_obj.pos;                                                   \
    signal_buffer = MSF_SIGNAL_CREATE (signalName, srcmod, destmod, length);            \
    if (signal_buffer != NULL) {                                                        \
        user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);                  \
        msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, MSF_MODID_PMG);    \
        cvtFunc (&cvt_obj, &param);                                                     \
        MSF_SIGNAL_SEND (signal_buffer);                                                \
    }                                                                                   \
  } while (0)

/**********************************************************************
 * Constants
 **********************************************************************/

#define PMG_MAX_PARTIAL_TEXT_CHARS      64

#define PMG_MAX_PUSH_MESSAGES           WAP_PMG_MAX_PUSH_MESSAGES
#define PMG_MAX_INFOITEMS               WAP_PMG_MAX_INFOITEMS
#define PMG_MAX_MSG_LIST_SIZE           WAP_PMG_MAX_MSG_LIST_SIZE
#define PMG_MAX_MSG_INFOITEM_LIST_SIZE  WAP_PMG_MAX_MSG_INFOITEM_LIST_SIZE
#define PMG_MAX_MSG_ADDR_LIST_SIZE      WAP_PMG_MAX_MSG_ADDR_LIST_SIZE
#define PMG_MAX_DELETED_MSG_LIST_SIZE   WAP_PMG_MAX_DELETED_MSG_LIST_SIZE

#define PMG_MAX_MSG_LIST_HREF_CHARS     WAP_PMG_MAX_MSG_LIST_HREF_CHARS
#define PMG_MAX_MSG_LIST_TEXT_CHARS     WAP_PMG_MAX_MSG_LIST_TEXT_CHARS
#define PMG_MAX_MSG_TEXT_CHARS          WAP_PMG_MAX_MSG_TEXT_CHARS
#define PMG_MAX_ADDR_CHARS              WAP_PMG_MAX_ADDR_CHARS
#define PMG_MAX_INFOITEM_CLASS_CHARS    WAP_PMG_MAX_INFOITEM_CLASS_CHARS
#define PMG_MAX_INFOITEM_TEXT_CHARS     WAP_PMG_MAX_INFOITEM_TEXT_CHARS
#define PMG_MAX_MSG_HREF_CHARS          WAP_PMG_MAX_MSG_HREF_CHARS
#define PMG_MAX_MSG_SIID_CHARS          128

#define PMG_STRTYPE_ASCII   WAP_PMG_STRTYPE_ASCII
#define PMG_STRTYPE_UCS2    WAP_PMG_STRTYPE_UCS2

#define PMG_STATUS_OK           WAP_PMG_STATUS_OK
#define PMG_STATUS_FAIL         WAP_PMG_STATUS_FAIL
#define PMG_STATUS_NOT_FOUND    WAP_PMG_STATUS_NOT_FOUND

#define PMG_PARAM_NOT_SPECIFIED WAP_PMG_PARAM_NOT_SPECIFIED
#define PMG_PARAM_YES           WAP_PMG_PARAM_YES
#define PMG_PARAM_NO            WAP_PMG_PARAM_NO

#define PMG_MSGTYPE_NULL    WAP_PMG_MSGTYPE_NULL
#define PMG_MSGTYPE_SI      WAP_PMG_MSGTYPE_SI
#define PMG_MSGTYPE_SL      WAP_PMG_MSGTYPE_SL
#define PMG_MSGTYPE_CO      WAP_PMG_MSGTYPE_CO
#define PMG_MSGTYPE_SIA     WAP_PMG_MSGTYPE_SIA

#define PMG_MSGPRIO_LOW     WAP_PMG_MSGPRIO_LOW
#define PMG_MSGPRIO_MEDIUM  WAP_PMG_MSGPRIO_MEDIUM
#define PMG_MSGPRIO_HIGH    WAP_PMG_MSGPRIO_HIGH
#define PMG_MSGPRIO_NONE    WAP_PMG_MSGPRIO_NONE
#define PMG_MSGPRIO_DELETE  WAP_PMG_MSGPRIO_DELETE
#define PMG_MSGPRIO_CACHE   WAP_PMG_MSGPRIO_CACHE

#define PMG_ADDR_NULL   WAP_PMG_ADDR_NULL   /* 0 */
#define PMG_ADDR_PHONE  WAP_PMG_ADDR_PHONE  /* 1 */
#define PMG_ADDR_IP     WAP_PMG_ADDR_IP		/* 2 */
#define PMG_ADDR_TEXT   WAP_PMG_ADDR_TEXT   /* 3*/

#if PMG_MAX_MSG_LIST_TEXT_CHARS > PMG_MAX_PARTIAL_TEXT_CHARS
#error PMG_MAX_MSG_LIST_TEXT_CHARS must not be greater than PMG_MAX_PARTIAL_TEXT_CHARS
#endif 

#if PMG_MAX_MSG_LIST_HREF_CHARS > PMG_MAX_PARTIAL_TEXT_CHARS
#error PMG_MAX_MSG_LIST_HREF_CHARS must not be greater than PMG_MAX_PARTIAL_TEXT_CHARS
#endif 

#define PMG_UM_MULTI_OP_DELETE          0   /* SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE */
#define PMG_UM_MULTI_OP_MOVE_TO_ARCHIVE 1   /* SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE */

#define PMG_DLG_MAX_POPUP_SIZE      WAP_PMG_DLG_MAX_POPUP_SIZE
#define PMG_DLG_MAX_TITLE_SIZE      WAP_PMG_DLG_MAX_TITLE_SIZE
#define PMG_DLG_MAX_SOFTKEY_SIZE    WAP_PMG_DLG_MAX_SOFTKEY_SIZE
#define PMG_DLG_MAX_CONTENT_SIZE    WAP_PMG_DLG_MAX_CONTENT_SIZE
#define PMG_DLG_MAX_ITEM_TEXT_SIZE  WAP_PMG_DLG_MAX_ITEM_TEXT_SIZE

#define PMG_DLG_MAX_SELECT_ITEMS    WAP_PMG_DLG_MAX_SELECT_ITEMS

typedef enum
{
    PMG_AUTH_LIST_TYPE_WHITE = 0x1,
    PMG_AUTH_LIST_TYPE_BLACK = 0x2
} pmg_auth_list_type;
/**********************************************************************
 * Exported Interface Functions
 **********************************************************************/

/*
 * SI: attribute = si-id.
 * SL: attribute = href.
 */
typedef struct
{
    MSF_UINT16 transID;
    MSF_UINT8 msgType;
    char *attribute;
} pmg_get_msg_by_attribute_t;

/* for MAUI_02100925 remove hole form this structure */
typedef struct
{
    MSF_UINT32 msg;
    MSF_UINT16 transID;
    MSF_UINT8 result;
    
} pmg_get_msg_by_attribute_reply_t;

int pmg_cvt_get_msg_by_attribute_reply(msf_dcvt_t *obj, pmg_get_msg_by_attribute_reply_t *p);

void PMGif_getMsgByAttribute(MSF_UINT8 modid, MSF_UINT16 transID, MSF_UINT8 msgType, char *attribute);

typedef struct
{
    MSF_UINT32 msgID;
    MSF_UINT8 isReplace;
} pmg_delete_msg_t;

void PMGif_deleteMsg(MSF_UINT8 modid, MSF_UINT32 msgID, MSF_UINT8 is_replace);

typedef struct
{
    MSF_UINT32 msg;
} pmg_create_msg_t;

void PMGif_createMsg(MSF_UINT8 modid, pmg_full_msg_t *msg);

typedef struct
{
    MSF_UINT8 wapPushEnabled;
    MSF_UINT8 slEnabled;
    MSF_UINT8 trustEnabled;
    MSF_UINT8 blackListEnabled;
    MSF_UINT32 maxTrustAddrNo;
    MSF_UINT32 maxBlackAddrNo;
} pmg_inbox_config_req_t;

void PMGif_inboxConfigReq(
    MSF_UINT8 wapPushEnabled, 
    MSF_UINT8 slEnabled, 
    MSF_UINT8 trustEnabled, 
    MSF_UINT8 blackListEnabled,
    MSF_UINT32 max_trust_addr_no,
    MSF_UINT32 max_black_addr_no);

typedef struct
{
    int transID;
    MSF_UINT8 msgType;
    MSF_UINT8 isRead;
    MSF_UINT8 isExpired;
    MSF_UINT8 hasInfo;
} pmg_inbox_msg_count_req_t;

void PMGif_inboxMsgCountReq(int transID, MSF_UINT8 msgType, MSF_UINT8 isRead, MSF_UINT8 isExpired, MSF_UINT8 hasInfo);

typedef struct
{
    int transID;
    MSF_UINT8 msgType;
    MSF_UINT8 isRead;
    MSF_UINT8 isExpired;
    MSF_UINT8 hasInfo;
    MSF_UINT32 startFrom;
    MSF_UINT32 size;
} pmg_inbox_msg_list_req_t;

void
PMGif_inboxMsgListReq(
    int transID,
    MSF_UINT8 msgType,
    MSF_UINT8 isRead,
    MSF_UINT8 isExpired,
    MSF_UINT8 hasInfo,
    MSF_UINT32 startFrom,
    MSF_UINT32 size);

typedef struct
{
    int transID;
    int msgID;
} pmg_inbox_get_msg_req_t;

void PMGif_inboxGetMsgReq(int transID, int msgID);
/*sks*/
typedef struct
{
	MSF_UINT32 msg_id;
	srv_wap_push_msg_read_status_func status_func;

} pmg_inbox_msg_read_status_req_t;

void PMGif_inboxReadStatusReq(MSF_UINT32 msg_id,srv_wap_push_msg_read_status_func status_func);

/*sks*/

typedef struct
{
    int transID;
    int msgID;
    MSF_UINT32 startFrom;
} pmg_inbox_get_msg_infotag_req_t;

void PMGif_inboxGetMsgInfoTagReq(int transID, int msgID, MSF_UINT32 startFrom);

typedef struct
{
    int transID;
    int msgID;
} pmg_inbox_delete_msg_req_t;

void PMGif_inboxDeleteMsgReq(int transID, int msgID);

typedef struct
{
    int transID;
    MSF_UINT8 msgType;
} pmg_inbox_delete_all_req_t;

void PMGif_inboxDeleteAllReq(int transID, MSF_UINT8 msgType);

typedef struct
{
    int transID;
    int msgID;
    MSF_UINT8 read;
} pmg_inbox_update_msg_req_t;

typedef struct
{
    MSF_UINT8 read;
} pmg_inbox_update_all_msg_req_t;


void PMGif_inboxUpdateMsgReq(int transID, int msgID, MSF_UINT8 read);

void PMGif_inboxNewMsgRsp(void);

typedef struct
{
    char *addr;
    MSF_UINT8 addrType;
} pmg_addr_t;

typedef struct
{
    int transID;
    int type;  /* pmg_auth_list_type */
    int segment;
    int size;
    int addrs;
	int total_segment;
} pmg_inbox_auth_addr_list_req_t;

void PMGif_inboxSetAuthListReq(int transID, pmg_auth_list_type type, int segment, int size, int addrs, int total_segment);

typedef struct
{
    int type;
    kal_uint32 id;
    int result;
} pmg_inbox_dlg_response_t;

void PMGif_inboxDialogResponse(int type, kal_uint32 id, int result);

typedef struct
{
    kal_uint32 transID;
    kal_uint32 dlgID;
} pmg_inbox_dlg_query_req_t;

void PMGif_inboxDialogQueryReq(int transID, int dlgID);

#ifdef __MMI_PUSH_IN_UM__

typedef struct
{
    MSF_UINT8 msgType;
} pmg_um_get_msg_num_req_t;

void PMGif_umGetMsgNumReq(MSF_UINT8 msgType);

typedef struct
{
    MSF_UINT8 msgType;
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    MSF_UINT8 idxType;
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

   MSF_UINT32 sim_id;
    MSF_UINT32 startFrom;
} pmg_um_get_list_req_t;


#ifdef WPS_PMG_CONVERSATION_BOX
typedef struct
{
    MSF_UINT8 msgType;
    MSF_INT16 startFrom;
	MSF_UINT32 pid;
	srv_um_traverse_func traverse_func;
	MSF_UINT32 app_id;
	MSF_UINT32 sim_id;
	
} pmg_um_get_traverse_list_req_t;

#endif /* WPS_PMG_CONVERSATION_BOX */

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
void PMGif_umGetListReq(MSF_UINT8 msgType, MSF_UINT32 startFrom, MSF_UINT8 idxType, MSF_UINT32 sim_id);
#else
void PMGif_umGetListReq(MSF_UINT8 msgType, MSF_UINT32 startFrom, MSF_UINT32 sim_id);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */


#ifdef WPS_PMG_CONVERSATION_BOX
void PMGif_umGetTraverseListReq(MSF_UINT8 msgType, MSF_INT16 startFrom, srv_um_traverse_func traverse_func, MSF_UINT32 pid, MSF_UINT32 app_id, MSF_UINT32 sim_id);
#endif /* WPS_PMG_CONVERSATION_BOX */

typedef struct
{
    MSF_UINT8 msgType;
    MSF_UINT16 msgNumber;
    MSF_UINT32 *msgIDs;
} pmg_um_get_msg_info_req_t;

void PMGif_umGetMsgInfoReq(MSF_UINT8 msgType, MSF_UINT16 msgNumber, MSF_UINT32 *msgIDs);

typedef struct
{
    MSF_UINT8 msgType;
} pmg_um_delete_folder_req_t;

void PMGif_umDeleteFolderReq(MSF_UINT8 msgType);

typedef struct
{
    MSF_UINT8 action;       /* PMG_UM_MULTI_OP_DELETE, PMG_UM_MULTI_OP_MOVE_TO_ARCHIVE */
    MSF_UINT32 msgNumber;
    MSF_UINT32 *msgIDs;
} pmg_um_multi_op_req_t;

void PMGif_umMultiOpReq(MSF_UINT8 action, MSF_UINT32 msgNumber, MSF_UINT32 *msgIDs);

#endif /* __MMI_PUSH_IN_UM__ */ 

typedef struct {
  MSF_UINT16     drmDataLength;
  unsigned char *drmData;
  char          *drmContentHeaders;

} pmg_content_drm_data_t;


/*
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
  pmg_content_drm_data_t *contentDRMData;
  char*                   auxTypeIdentifier;
  MSF_INT32               attrLength;
  unsigned char           *attrString;
} pmg_content_data_t; */

typedef struct  {
  MSF_UINT8               routingFormat;
  MSF_UINT8               contentDataType;
  MSF_UINT8               contentDRMDataExists;
  char*                   routingIdentifier;
  char*                   contentUrl;
  char*                   contentSource;
  char*                   contentParameters;
  char*                   contentHeaders;
  MSF_INT32               networkAccountId;  
  MSF_UINT32              contentDataLength;
  unsigned char*          contentData;  
  pmg_content_drm_data_t *contentDRMData;
  char*                   auxTypeIdentifier;
  MSF_INT32               attrLength;
  unsigned char           *attrString;
} pmg_content_data_t;

/* Content routing */
typedef struct {
  MSF_UINT8           destModId;
  MSF_UINT8           sendAck;
  MSF_UINT8           id;
  MSF_UINT8           contentDataExists;
  char*               startOptions;
  pmg_content_data_t* contentData;
  /* msf_content_area_t contentArea;*/
} pmg_content_send_t;

void PMGif_contentDataRoute(MSF_UINT8 src_modId, pmg_content_send_t* send);

int PMGif_getProfileInfo(MSF_UINT32 sim_id, wps_pmg_channel_struct *ch_info); 

/**********************************************************************
 * Exported Message Creation Functions
 **********************************************************************/

char *pmg_lib_cvt_text(const char *text);

char *pmg_lib_cvt_href(const char *href);

char *pmg_lib_cvt_addr(const char *addr, MSF_INT16 addrLen, MSF_UINT8 addrType, MSF_UINT8 has_num_plan);

int
pmg_lib_extract_address(msf_sockaddr_t *sockaddr, char **oa, MSF_UINT16 *oalen, char **sc, MSF_UINT16 *sclen);

pmg_full_msg_t *pmg_lib_new_msg(void);

void pmg_lib_release_msg(pmg_full_msg_t *msg);

void pmg_lib_msg_set_created(pmg_full_msg_t *msg, MSF_UINT32 created);

void pmg_lib_msg_set_expired(pmg_full_msg_t *msg, MSF_UINT32 expired);

void pmg_lib_msg_set_msgType(pmg_full_msg_t *msg, MSF_UINT8 msgType);

int pmg_lib_msg_get_msgType(int msfMimeInt);

void pmg_lib_msg_set_priority(pmg_full_msg_t *msg, MSF_UINT8 priority);

void pmg_lib_msg_set_read(pmg_full_msg_t *msg, MSF_UINT8 read);

void pmg_lib_msg_set_sim_id(pmg_full_msg_t *msg, MSF_UINT32 sim_id);

void pmg_lib_msg_set_siid(pmg_full_msg_t *msg, const char *siid);

void pmg_lib_msg_set_text(pmg_full_msg_t *msg, const char *text);

void pmg_lib_msg_set_smsc(pmg_full_msg_t *msg, const char *smsc, MSF_INT16 addrLen, MSF_UINT8 addrType);

void pmg_lib_msg_set_from(pmg_full_msg_t *msg, const char *from, MSF_INT16 addrLen, MSF_UINT8 addrType);

void pmg_lib_msg_set_href(pmg_full_msg_t *msg, const char *href);

void pmg_lib_msg_add_infoitem(pmg_full_msg_t *msg, char *infoClass, char *infoText);

void pmg_lib_msg_log_address(const char *addr, MSF_INT16 addrLen);

/**********************************************************************
 * Exported Dialog Display Requests Functions
 **********************************************************************/

typedef void (*PMG_FP_DLG_RSP) (void *dlgHandle, void *user_data);

typedef enum
{
    PMG_DLG_SIA_CONFIRM,
    PMG_DLG_UNKNOWN_ADDR 
} pmg_dlg_type;

typedef struct pmg_dlg_display_req_t
{
    struct pmg_dlg_display_req_t *next;

    pmg_dlg_type dlgType;

    PMG_FP_DLG_RSP cbLsk;
    PMG_FP_DLG_RSP cbRsk;

    union {
        struct {
            MSF_UINT8 msgType; /* WAP_PMG_MSGTYPE_XXX */
            MSF_UINT8 smscType;
            MSF_UINT8 fromType; /* Originating address type */
            char *smsc;
            char *from;         /* OA addr */
            char *text;
            char *href;
        } msgInfo;

        struct {
            char *host;
            MSF_UINT16 port;
        } siaInfo;
    } dlgInfo;
} pmg_dlg_display_req_t;


/* unified push // for registry data unified push */
typedef struct 
{
	MSF_UINT16     security_level;
	MSF_UINT16     support_SIR;
	MSF_UINT16     support_SL;
	MSF_UINT16     whitelist_disable;
	MSF_UINT16     blacklist_enable;
	MSF_UINT16     whitelist_behavior;

}pmg_phs_setting_data_t;

typedef enum
{
  PMG_PHS_SMS_UDP_CONNECTIONS,
  PMG_PHS_WTLS_CONNECTIONS,
  PMG_PHS_HTTP_CONNECTIONS
}pmg_phs_connection_data;

typedef enum
{
    PMG_PHS_WL_LIST_DATA,
    PMG_PHS_BL_LIST_DATA,
    PMG_PHS_CNF_DATA,
	PMG_PHS_OTHER_DATA
} pmg_phs_setting_data;

typedef struct
{
	MSF_UINT16	   net_id;
	MSF_UINT32 	   type;
}pmg_phs_def_con;

typedef struct
{
	char	   *file_name;
	MSF_UINT8   list_type;
}pmg_phs_list_data_t;


typedef struct
{
    char	   *file_name;	
}pmg_phs_temp_t;



/* unified push */
int pmg_cvt_set_data_to_phs_setting(msf_dcvt_t *obj, pmg_phs_setting_data_t *setting_data);
int pmg_cvt_set_def_con(msf_dcvt_t *obj, pmg_phs_def_con *conn_data);
int pmg_cvt_content_send(msf_dcvt_t *obj,pmg_content_send_t *send);
int pmg_cvt_content_data (msf_dcvt_t *obj, pmg_content_data_t *p);
int pmg_cvt_content_drm_data (msf_dcvt_t *obj, pmg_content_drm_data_t *p);
int pmg_cvt_data_list(msf_dcvt_t *obj, pmg_phs_list_data_t *p);

pmg_dlg_display_req_t *pmg_lib_new_dlg_display_req(void);

typedef struct
{
    int dlg_request;
} pmg_display_dialog_req_t;

void pmg_lib_release_dlg_display_req(pmg_dlg_display_req_t *dlgreq);
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
void PMGif_inboxTurnOnOffPush(MSF_UINT8 push_turn_on_switch);
#endif /*__MMI_PUSH_TURN_ON_OFF_SWITCH__*/
void PMGif_displayDialog(pmg_dlg_display_req_t *dlgRequest);
const U8* pmg_if_get_accept_header(void);

void PMGif_inboxUpdateAllMsgReq(MSF_UINT8 read);
void PMGif_inboxGetReadStatus(MSF_UINT32 msg_id,srv_wap_push_msg_read_status_func status_func);

#endif /* _pmg_if_h */ 

