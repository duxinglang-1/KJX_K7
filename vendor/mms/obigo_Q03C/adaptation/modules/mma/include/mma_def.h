/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   mma_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMA_DEF_H
#define _MMA_DEF_H

#include "MMI_features.h"
#include "kal_general_types.h"

#ifndef _msf_mem_h
#include "msf_mem.h"
#endif 
#include "mms_def.h"
#include "mma_cfg.h"
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"

/******************************************************************************
 * Macro definition
 *****************************************************************************/
#define JSR_MAX_APP_ID_LENGTH 100

#define MMA_TRANSLATE_MSG_ID(X)  ((X) & 0X0FFFFFFF)

/*
 * MMA_NON_ASCII_NAME_CONV_SUPPORT 
 * Define this macro to convert the non-ascii
 * filenames to ascii file names. 
 */
#define MMA_NON_ASCII_NAME_CONV_SUPPORT

/* MMA SUBModule */
typedef enum
{
    MMA_SUBMODULE_MSG_MGR,
    MMA_SUBMODULE_MSG_CREATE,
    MMA_SUBMODULE_MSG_PARSE,
    MMA_SUBMODULE_MSG_SENDRECV,
    MMA_SUBMODULE_MSG_SETTING,
    MMA_SUBMODULE_MSG_MAIN,
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    MMA_SUBMODULE_MSG_DRMSRV,
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    MMA_SUBMODULE_TOTAL
} mma_submodule_enum;

typedef enum
{
    MMA_SUBMODULE_STATE_IDLE,
    MMA_SUBMODULE_STATE_INITING,    /* INITING => READY */
    MMA_SUBMODULE_STATE_READY,
    MMA_SUBMODULE_STATE_DEINITING   /* DEINITING => IDLE */
} mma_submodule_state_enum;

/* internal event id */
typedef enum
{
    /* MMA_SUBMODULE_MSG_PARSE */
    MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO = 5000,  /* i_param = source mma module, u_param1 = msg_id */
    MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO_REPLY,   /* i_param =  result, u_param1 = msg_id, p_param = mma_basic_msg_info_struct */
    MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND,
    MMA_INT_SIG_TYPE_MSG_PARSE_NEXT_IND,
    MMA_INT_SIG_TYPE_MSG_PARSE_REQ,
    MMA_INT_SIG_TYPE_FREE_MMS_CONTENT_INFO,
#ifdef __MMI_VCARD__
	MMA_INT_SIG_TYPE_MSG_VCARD_VERSION_RSP,
#endif

#ifdef __MMI_MMS_USE_ASM__
    MMA_INT_SIG_TYPE_MSG_GET_ASM_POOL_RSP,
    MMA_INT_SIG_TYPE_MSG_DEINIT_ASM_POOL_REQ,
#endif /* __MMI_MMS_USE_ASM__ */

    /* MMA_SUBMODULE_MSG_CREATE */
    MMA_INT_SIG_TYPE_MSG_INT_CREATE_REQ,
    MMA_INT_SIG_TYPE_MSG_INT_CREATE_RSP,
    MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND,
    MMA_INT_SIG_TYPE_MSG_CREATE_NEXT_IND,
    /* MMA_SUBMODULE_MSG_SENDRECV */
    MMA_INT_SIG_TYPE_MSG_SEND_MSG,
    MMA_INT_SIG_TYPE_MSG_SEND_MSG_RSP,
    MMA_INT_SIG_TYPE_MSG_SEND_RR_RSP,
    MMA_INT_SIG_TYPE_MSG_CANCEL_SEND_MSG,
    MMA_INT_SIG_TYPE_MSG_RECV_MSG,
    MMA_INT_SIG_TYPE_MSG_RECV_MSG_RSP,
    MMA_INT_SIG_TYPE_MSG_RECV_IND_RES,
    MMA_INT_SIG_TYPE_MSG_CANCEL_RECV_MSG,
    MMA_INT_SIG_TYPE_MSG_PROGRESS_IND,
    MMA_INT_SIG_TYPE_MSG_RECV_MSG_PROGRESS,
    MMA_INT_SIG_TYPE_MSG_MMS_OBJ_IND,
    MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES,
    MMA_INT_SIG_TYPE_MSG_PROCESS_SEND_Q_IND,
    MMA_INT_SIG_TYPE_MSG_PROCESS_RECV_Q_IND,
    /* MMA_SUBMODULE_MSG_MGR */
    MMA_INT_SIG_TYPE_MSG_CONTINUE_MSG_OPER,
    MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_NUM_REQ,
    MMA_INT_SIG_TYPE_MSG_UM_GET_LIST_REQ,
    MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_INFO_REQ,
    MMA_INT_SIG_TYPE_MSG_UM_DELETE_MSG_REQ,
    MMA_INT_SIG_TYPE_MSG_UM_DELETE_FOLDER_REQ,
    MMA_INT_SIG_TYPE_MSG_UPDATE_NEW_MSG_REQ,
    MMA_INT_SIG_TYPE_MSG_GET_REPORT_NOTIF_REQ,
#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
    MMA_INT_SIG_TYPE_MSG_GET_MSG_INFO_REQ,
    MMA_INT_SIG_TYPE_MSG_GET_MSG_LIST_REQ,
#endif	/* MMA_JSR_PST_MMS_OPERATON_SUPPORT */
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
    MMA_INT_SIG_TYPE_MSG_DELETE_REQ,
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
    MMA_INT_SIG_TYPE_MSG_SAVE_REQ,
    MMA_INT_SIG_TYPE_MSG_MMS_DELETE_IND,                    /* The result of deleting msg from MMS service */
    MMA_INT_SIG_TYPE_MSG_MMS_MOVE_IND,                      /* The result of moving msg from MMS service */
    MMA_INT_SIG_TYPE_MSG_CREATE_NEW_MMS_REQ,                /* The signal is used to inform MMS MSGMGR of new MMS is created, msg_id is saved in sig->u_param */
    MMA_INT_SIG_TYPE_MSG_CREATE_NEW_MMS_RSP,                /* msg_id is saved in sig->u_param, result is saved in sig->i_param */
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
    MMA_INT_SIG_TYPE_MSG_VALIDATE_MSG_REQ,
    MMA_INT_SIG_TYPE_MSG_SET_READMARK_REQ,
    MMA_INT_SIG_TYPE_MSG_GET_UNREAD_MSG_LIST_REQ,
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
    MMA_INT_SIG_TYPE_MSG_GET_RECENT_EVT_LIST_REQ,
    MMA_INT_SIG_TYPE_MSG_DELETE_RECENT_EVT_REQ,
    MMA_INT_SIG_TYPE_MSG_CREATE_REQ,
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
	MMA_INT_SIG_TYPE_MSG_GET_ATTR_AND_THUMBNAIL_REQ,
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
    /* MMA_SUBMODULE_MSG_SETTING */
    MMA_INT_SIG_TYPE_MSG_SET_SETTING_REQ,
    MMA_INT_SIG_TYPE_MSG_GET_SETTING_REQ,
    MMA_INT_SIG_TYPE_MSG_SET_PROFILE_REQ,
    MMA_INT_SIG_TYPE_MSG_SET_PROFILE_RSP,
    MMA_INT_SIG_TYPE_MSG_SET_MMSC_VERSION,
	MMA_INT_SIG_TYPE_MSG_SET_USER_AGENT,
	MMA_INT_SIG_TYPE_MSG_SET_PLMN_NUMBER,
	MMA_INT_SIG_TYPE_MSG_SET_OWNER_NUMBER,
	MMA_INT_SIG_TYPE_MSG_SET_ROAMING_STATUS,
    /* Main */
    MMA_INT_SIG_TYPE_MSG_TERMINATE_IND,
    MMA_INT_SIG_TYPE_MSG_SEND_READY_IND_REQ,
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
    MMA_INT_SIG_TYPE_MSG_SET_APPDATA_REQ,
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
    MMA_INT_SIG_TYPE_MSG_GET_MEM_STATUS_REQ,
    MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ,
    MMA_INT_SIG_TYPE_MSG_EXIT_USB_REQ,
    MMA_INT_SIG_TYPE_NOTIFY,                                /* Triagger internal modules */
    MMA_INT_SIG_TYPE_PIPE_NOTIFY,

    /* DRMSRV */
#ifdef __MMI_MMS_MMA_DRM_ENCODING__    
    MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_REQ,
    MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_DONE,
    MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_RSP,
    MMA_INT_SIG_TYPE_MSG_DRMSRV_CONTINUE_IND,
    MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_NEXT_IND,
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
	MMA_INT_SIG_TYPE_MSG_GET_MSG_NUM_REQ,
#endif	/* MMA_JSR_PST_MMS_OPERATON_SUPPORT */
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
    MMA_INT_SIG_TYPE_MSG_GET_MSG_PROPERTY_REQ,
	MMA_INT_SIG_TYPE_MSG_RR_MARK_REQ,
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_IND,
    MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND,
    MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_RES,
    MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_RES,
    MMA_INT_SIG_TYPE_MSG_CHG_STORAGE_REQ,
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
    MMA_INT_SIG_TYPE_MSG_FMT_FORMAT_IND,
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */
#ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
    MMA_INT_SIG_TYPE_MSG_UM_TRAVERSE_MSG_REQ,
#endif
    MMA_INT_SIG_TYPE_MSG_UPDATE_ADDR_OBLECTS_INFO,
    MMA_INT_SIG_TYPE_MSG_SYNC_DELETE_MSG_IND,
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
    MMA_INT_SIG_TYPE_MSG_UPDATE_MMS_THUMBNAIL_INFO,
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
    MMA_INT_SIG_TYPE_MSG_CPY_TO_ARCHIVE_REQ,
#endif  /* __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__ */
#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
    MMA_INT_SIG_TYPE_MSG_DEF_TMPLT_GEN_DONE_IND,
#endif
    MMA_INT_SIG_TYPE_TOTAL
} mma_int_sig_type_enum;

typedef enum
{
    MMA_MSG_STATE_NULL,
    MMA_MSG_STATE_OPENING,
    MMA_MSG_STATE_OPENED,
    MMA_MSG_STATE_CLOSING,
    MMA_MSG_STATE_CLOSED
} mma_msg_state_enum;

/* need to remove. Will see it later */
typedef enum
{
    MMA_DRM_NO_PROTECTION = 0,              /* no DRM protection */
    MMA_DRM_PROCESS_FORWARD_LOCK_CD = 1,    /* Forward locked */
    MMA_DRM_PROCESS_SEPERATE_DELIVERY = 2   /* Separate delivery DRM (encrypted DCF) */
} mma_drm_type_for_process_enum;

typedef struct mms_mma_queue_struct_st
{
    MSF_UINT32 first_id;
    MSF_UINT32 second_id;
	kal_uint8 action_type;
    void *data;
    struct mms_mma_queue_struct_st *next;
} mms_mma_queue_struct;

typedef struct mma_signal_st
{
    int dst;
    int type;
    long i_param;
    unsigned long u_param1;
    unsigned long u_param2;
    unsigned long u_param3;
    void *p_param;
    struct mma_signal_st *next;
} mma_signal_struct;


typedef struct
{
    char *address;              /*!< The recipent address. */
    MmsAddressType addrType;    /*!< Address Type (PLMN or EMAIL) */
    MmsTimeSec date;            /*!< Date and time when the message was handled */
    MmsStatus readStatus;           /*!< Status of the message. */
    char *subject;              /*!< subject of the actual MMS */
    //MSF_UINT32 msgId;         /*!< Message is to the orignated message or zero if it is not found */
	//char *serverMsgId;	
}MmaReport;

typedef struct mma_msg_info_list_st
{
	kal_uint8 folder;                       /* mma_folder_enum */
    kal_uint8 prev_folder;
    kal_uint8 suffix;                       /* MmsFileType */
    kal_uint8 new_msg_state;
    kal_uint8 msg_sim_id;       /* srv_um_sim_enum */ /* add here to prevent extra file read operation */
    kal_uint8 user_can_not_see;
	kal_uint8 is_read;
    kal_uint8 is_rr_send;
    kal_uint8 mms_msg_type;     /* mma_msg_type_enum */
    kal_uint8 mms_priority;
    kal_uint32 msg_id;
    kal_uint32 flag;                        /* mma_msgmgr_msg_oper_enum */
    kal_uint32 receive_date;
    kal_uint32 def_noti_msg_id;             /* can be shifted in global context */
    struct mma_msg_info_list_st *next;
} mma_msg_info_list_struct;

typedef void (*mma_int_sig_function) (mma_signal_struct *);
typedef kal_bool(*mma_submodule_init_function) (void);
typedef kal_bool(*mma_submodule_terminate_function) (void);

typedef struct
{
    mma_submodule_state_enum state;
    mma_int_sig_function int_sig_process_func;
    mma_submodule_init_function init_func;
    mma_submodule_terminate_function terminate_func;
} mma_submodule_info_struct;

#define MMA_APP_SOURCE_MODULE MOD_MMI

/* memory */
#define MMA_ALLOC(s)            MSF_MEM_ALLOC(MSF_MODID_MMA,s)
#define MMA_CALLOC(s)           MSF_MEM_CALLOC(MSF_MODID_MMA,1, s)
#define MMA_FREE(p)             {mma_mem_free(p); p = NULL;}

/* folder */
#define MMA_GET_MMS_XML_FILEPATH(x, d)   sprintf(x, "%s%c%02d.xml", MMA_CFG_MMS_XML_FOLDER, MMA_CFG_MMS_XML_PREFIX, d);

#define MMA_UNKNOWN_MIME_STR  "application/octet-stream"
#define MMA_MAX_VIRTUAL_FILE_PATH_SIZE (10 + 256)       /* strlen("/external/") + 256 > FS_GenVFN_SIZE */

/* custom */
#define MMA_HEADER_APPLICATION_ID_STR  "Application-ID"
#define MMA_HEADER_REPLY_APPLICATION_ID_STR  "Reply-To-Application-ID"

/* DRM Strings */
#define MMA_MEDIA_TYPE_STRING_DRM1  "application/vnd.oma.drm.message"
#define MMA_MEDIA_TYPE_STRING_DRM2  "application/vnd.oma.drm.content"

/* size constant */
#define MMA_1_KB_IN_BYTE     1024       /* bytes per KB */

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
#define DUMMY_NAME    "XXX"
#endif
/*Header buffer that might get added by the server */
#define MMA_EXTRA_HEADER_BUFFER 200

/* Time constant */
#define MMA_1_SEC_IN_DSEC    10 /* decimal seconds per second */
#define MMA_1_SEC_IN_MSEC    1000       /* decimal seconds per second */
#define MMA_1_HOUR_IN_SEC    3600       /* seconds per hour */
#define MMA_12_HOURS_IN_SEC  43200      /* seconds for 12 hours */
#define MMA_1_DAY_IN_SEC     86400      /* seconds per day */
#define MMA_1_WEEK_IN_SEC    604800     /* seconds per week */

/* UCS2 */
#define ENCODING_LENGTH       2

/* Signal */
#define MMA_SIGNAL_SENDTO(d, sig)                                                                                          \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, \
    (unsigned long)0L, NULL)

#define MMA_SIGNAL_SENDTO_I(d, sig, i) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), i, (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, NULL)

#define MMA_SIGNAL_SENDTO_IU(d, sig, i, u) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (i), (u), 0L, 0L, NULL)

#define MMA_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (i), (u1), (u2), 0L, NULL)

#define MMA_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (i), (u), (unsigned long)0L, 0L, (p))

#define MMA_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (i), (u1), (u2), (unsigned long)0L, (p))

#define MMA_SIGNAL_SENDTO_IUUUP(d, sig, i, u1, u2, u3, p) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (i), (u1), (u2), (u3), (p))

#define MMA_SIGNAL_SENDTO_IUUU(d, sig, i, u1, u2, u3) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (i), (u1), (u2), (u3), NULL)

#define MMA_SIGNAL_SENDTO_IP(d, sig, i, p)                                                                                      \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (i), (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, \
        (p))

#define MMA_SIGNAL_SENDTO_U(d, sig, u)                                                                                          \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (unsigned long)0L, (u), (unsigned long)0L, (unsigned long)0L, \
        NULL)

#define MMA_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (unsigned long)0L, (u1), (u2), (unsigned long)0L, NULL)

#define MMA_SIGNAL_SENDTO_UUP(d, sig, u1, u2, p) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (unsigned long)0L, (u1), (u2), (unsigned long)0L, (p))

#define MMA_SIGNAL_SENDTO_UP(d, sig, u, p) \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (unsigned long)0L, (u), 0L, (unsigned long)0L, (p))

#define MMA_SIGNAL_SENDTO_P(d, sig, p)                                                                                     \
    mma_send_int_sig(&g_mms_mma_int_sig_queue_list_p, (d), (sig), (unsigned long)0L, (unsigned long)0L, (unsigned long)0L, \
    (unsigned long)0L, (p))

#define MMA_FOLDER "/mma/"

#define MMA_CHECKSUM_FOLDER "/mma/checksum/"

#define MMA_MAX_USER_DEF_TEMPLATE_NUM 5

#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
#define MMA_MAX_MMS_SIZE (wap_custom_get_max_mms_msg_size() + wap_custom_get_mms_user_element_header_size())
#else 
#define MMA_MAX_MMS_SIZE wap_custom_get_max_mms_msg_size()
#endif 

extern kal_int32 mma_msf_file_open_in_blocking_mode(MSF_UINT8 modId, const char *fileName, int mode, long size, mma_msg_storage_type_enum storage_type);

extern mma_signal_struct *g_mms_mma_int_sig_queue_list_p;

#endif /* _MMA_DEF_H */ 

