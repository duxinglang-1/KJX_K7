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
 

/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */









/*******************************************************************************
 *
 * Filename:
 * ---------
 * phs_msg.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _phs_msg_h
#define _phs_msg_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _phs_sig_h
#include "phs_sig.h"
#endif


#ifndef _phs_cfg_h
#include "phs_cfg.h"
#endif

#ifndef _stk_if_h
#include "stk_if.h"
#endif





#define PHS_MSG_SIG_NEW_MESSAGE                    PHS_MODULE_MSG + 1
//#define PHS_MSG_SIG_UIS_MESSAGE_DATA               PHS_MODULE_MSG + 2   /* ARK OLD CODE FOR PMG */ 
#define PHS_MSG_SIG_PMG_MESSAGE_DATA               PHS_MODULE_MSG + 2     /* ARK NEW CODE FOR PMG */










#define PHS_STATE_NEW_MSG                     0
#define PHS_STATE_WHITELIST_DONE              1
#define PHS_STATE_PRS_STARTED                 2
#define PHS_STATE_PARSING_SI                  3
#define PHS_STATE_PARSING_SL                  4
#define PHS_STATE_PARSING_CO                  5
#define PHS_STATE_READING_HEADER              6
#define PHS_STATE_READING_BODY                7


#define PHS_PRIO_LOW                             0
#define PHS_PRIO_MEDIUM                          1
#define PHS_PRIO_HIGH                            2
#define PHS_PRIO_DELETE                          3
#define PHS_PRIO_CACHE                           4
#define PHS_PRIO_NONE                            5




/* ARK NEW CODE PMG START */
typedef void umdb_msg_list_handle_t;
typedef void umdb_msg_error_list_handle_t;
typedef void umdb_attr_key_value_list_handle_t;
typedef MSF_UINT8 umdb_msg_type_id_t;
typedef MSF_UINT32 umdb_msg_id_t;
typedef MSF_UINT32 umdb_attr_key_t;
/* ARK NEW CODE PMG END */



typedef struct phs_co_data_st {
  struct phs_co_data_st    *next;           
  int                       type;           
  char                     *text;           
} phs_co_data_t;

/* ARK NEW CODE PMG START*/

typedef enum {
  UMDB_RAW_DATA_WITH_PIPE,
  UMDB_RAW_DATA_WITH_FILE,
  UMDB_RAW_DATA_NONE
} umdb_raw_data_option_t;


typedef enum
{
   WAP_PHS_SIM_DEFAULT = 1,
   WAP_PHS_SIM1 = 1,
   WAP_PHS_SIM2,
   WAP_PHS_SIM3,
   WAP_PHS_SIM4,
   WAP_PHS_SIM_ALL,
   WAP_PHS_SIM_END
}wap_phs_sim_type_enum;

typedef struct phs_prsd_info_st {
  char                    *href;           
  int                      priority;         
  char                    *si_id;          
  char                    *text;           
  MSF_UINT32               created;        
  MSF_UINT32               expired;        
  phs_co_data_t           *co_data;        
  char                   **info_attrs;            
  char                   **info_contents;         
  int                      nbr_of_info_elements;  
} phs_prs_info_t;



typedef struct umdb_msg_t{
  umdb_msg_type_id_t msg_type; 
  umdb_msg_id_t msg_id;   
  MSF_UINT16 nbr_of_key_values;
  umdb_attr_key_value_list_handle_t *key_value_list; 


  umdb_raw_data_option_t raw_data_option; 

  union {
    const char *pipe_names;  
    const char *file_handles;  
  } raw_data;
} umdb_msg_t;





typedef enum {

  UMDB_RESULT_READ_RAW_DATA_FAILED, 
  UMDB_RESULT_WRITE_RAW_DATA_FAILED, 
  UMDB_RESULT_COPY_RAW_DATA_FAILED, 
  UMDB_RESULT_ERROR_MSG_NOT_EXIST,  
  UMDB_RESULT_ERROR_MSG_RECOVER_ONGOING, 
  UMDB_RESULT_ERROR_MSG_LOCKED_TO_HOST,   
  UMDB_RESULT_ERROR_MSG_LOCKED,     
  UMDB_RESULT_ERROR_MSG_CANNOT_UNLOCK,     
  UMDB_RESULT_ERROR_MSG_ALREADY_VISIBLE,   
  UMDB_RESULT_ERROR_DELAYED,        
  UMDB_RESULT_ERROR_VIEW_NOT_EXIST, 
  UMDB_RESULT_ERROR_OUT_OF_STORAGE_MEMORY, 
  UMDB_RESULT_ERROR_MSGS_OF_DIFFERENT_MSG_TYPES, 
  UMDB_RESULT_ERROR_TOO_LATE, 
  UMDB_RESULT_ERROR_UNEXPECTED, 
  UMDB_RESULT_ERROR_ABORTED,
  
  UMDB_RESULT_FAILED,               
  


  UMDB_RESULT_SUCCESS,              
  
  UMDB_RESULT_SUCCESS_WITH_FAILURES,
  UMDB_RESULT_SUCCESS_EXT_SMS_STORAGE_NOT_SYNCHRONIZED, 
  UMDB_RESULT_SUCCESS_VIEW_NOT_EXIST
} umdb_result_code_t;

typedef struct umdb_oper_reply_get_filtered_t{
  MSF_UINT16 transaction_id;  
  MSF_UINT32 to_sub_mod_id;   
  MSF_UINT16 nbr_of_msgs;
  umdb_msg_list_handle_t *msg_list;  
  MSF_UINT16 nbr_of_errors;
  umdb_msg_error_list_handle_t *error_list;  
  MSF_BOOL complete;  
  umdb_result_code_t result;  
} umdb_oper_reply_get_filtered_t;


typedef enum pmg_msg_type_attribute_t{
  UMDB_MSG_TYPE_NONE = 0, 
  UMDB_MSG_TYPE_PUSH_SI,
  UMDB_MSG_TYPE_PUSH_SL,
  UMDB_MSG_TYPE_MMS,
  UMDB_MSG_TYPE_EMS,
  UMDB_MSG_TYPE_PROVISIONING,
  UMDB_MSG_TYPE_EMAIL,
  UMDB_MSG_TYPE_COUNT  
} pmg_msg_type_attribute_t;

/* ARK NEW CODE PMG END*/

void
phs_msg_init (void);

void
phs_msg_main (phs_signal_t* signal);

void
phs_handle_new_push (stk_recv_request_t *p);

void
phs_handle_content_send_ack (int id, int status);

void 
phs_msg_delete_all_message_in_list (void);

#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES 

void
phs_handle_parsing_aborted (int msg_id);

#endif /* PHS_CONFIG_WAP_PUSH_MESSAGES */
#endif /* _phs_msg_h */


