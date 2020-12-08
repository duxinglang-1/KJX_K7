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
 *  CentralConfigAgentProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
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
 *============================================================================
 ****************************************************************************/


#ifndef SRV_CCA_PROT_H
#define SRV_CCA_PROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Abbreviation                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_features.h"

#ifdef __MMI_CCA_SUPPORT__

#include "kal_general_types.h"
#include "stack_config.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"

#include "MMIDataType.h"

#include "mmi_frm_queue_gprot.h"

#include "CcaSrvGprot.h"
#include "CcaSrvIprot.h"
#include "CcaSrvConfig.h"



#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 


/*----------------------------------------------------------------------------*/
/* Base type define                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CCA_H2P(handle, _st)                ((_st*)(handle))
#define SRV_CCA_P2H(_X)                         ((SRV_CCA_HANDLE)(_X))
#define SRV_CCA_H_CHK(handle)                   (handle)

#define SRV_CCA_NEW_ILM_DATA(type)              ((type*)OslConstructDataPtr(sizeof(type)))

#define srv_cca_malloc_type(x)                  (x*)srv_cca_malloc((U32)sizeof(x))

#define SRV_CCA_IDX2BIT(idx)                    (0x01 << (idx))

#define SRV_CCA_SET_FLAG(flag, bit_mask)        ((flag) |= (bit_mask))
#define SRV_CCA_CLEAR_FLAG(flag, bit_mask)      ((flag) &= ~(bit_mask))
#define SRV_CCA_CHECK_FLAG(flag, bit_mask)      (((flag) & (bit_mask)) > 0)

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_CCA_INVALID_CORE_DATA               ((S32)((U32)(~0) - 1))

/* Instance flag */
#define SRV_CCA_INST_FLAG_VIEW_IN_PROV_STATE    (0x00000001)


/* Old CCA events : should remove */
#define MSG_ID_SRV_CCA_APP_CONFIGURE_IND                    MSG_ID_MMI_CCA_APP_CONFIGURE_IND
#define MSG_ID_SRV_CCA_APP_CONFIGURE_RSP                    MSG_ID_MMI_CCA_APP_CONFIGURE_RSP
#define MSG_ID_SRV_CCA_SRC_NEW_DOC_IND                      MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND
#define MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP                      MSG_ID_MMI_CCA_SOURCE_NEW_DOC_RSP
#define MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND              MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND
#define MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND                  MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND
#define MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP                  MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP
#define MSG_ID_SRV_CCA_SRC_AUTH_IND                         MSG_ID_MMI_CCA_SOURCE_UI_AUTH_IND
#define MSG_ID_SRV_CCA_SRC_AUTH_RSP                         MSG_ID_MMI_CCA_SOURCE_UI_AUTH_RSP
#define MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND                 MSG_ID_MMI_CCA_NEW_DOC_CONTINUE_IND
#define MSG_ID_SRV_CCA_GET_PROF_IND                         MSG_ID_MMI_CCA_GET_PROF_IND
#define MSG_ID_SRV_CCA_GET_PROF_RSP                         MSG_ID_MMI_CCA_GET_PROF_RSP
#define MSG_ID_SRV_CCA_APP_GET_PROF_IND                     MSG_ID_MMI_CCA_APP_GET_PROF_IND
#define MSG_ID_SRV_CCA_APP_GET_PROF_RSP                     MSG_ID_MMI_CCA_APP_GET_PROF_RSP
#define MSG_ID_SRV_CCA_UPDATE_PROF_IND                      MSG_ID_MMI_CCA_UPDATE_PROF_IND
#define MSG_ID_SRV_CCA_UPDATE_PROF_RSP                      MSG_ID_MMI_CCA_UPDATE_PROF_RSP
#define MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND                  MSG_ID_MMI_CCA_APP_UPDATE_PROF_IND
#define MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP                  MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP
#define MSG_ID_SRV_CCA_SRC_SIM_PROFILE_STATUS_IND           MSG_ID_MMI_CCA_SOURCE_SIM_PROFILE_STATUS_IND
#define MSG_ID_SRV_CCA_APP_SIM_PROFILE_STATUS_IND           MSG_ID_MMI_CCA_APP_SIM_PROFILE_STATUS_IND
#define MSG_ID_SRV_CCA_SRC_CCA_READY_IND                    MSG_ID_MMI_CCA_SOURCE_CCA_READY_IND
#define MSG_ID_SRV_CCA_SESSION_BEGIN_IND                    MSG_ID_MMI_CCA_SESSION_BEGIN_IND
#define MSG_ID_SRV_CCA_SESSION_BEGIN_RSP                    MSG_ID_MMI_CCA_SESSION_BEGIN_RSP
#define MSG_ID_SRV_CCA_SESSION_END_IND                      MSG_ID_MMI_CCA_SESSION_END_IND
#define MSG_ID_SRV_CCA_SESSION_END_RSP                      MSG_ID_MMI_CCA_SESSION_END_RSP
#define MSG_ID_SRV_CCA_PROCESS_PROV_MSG_REQ                 MSG_ID_MMI_CCA_PROCESS_PROV_MSG_REQ
#define MSG_ID_SRV_CCA_PROCESS_PROV_MSG_CNF                 MSG_ID_MMI_CCA_PROCESS_PROV_MSG_CNF    
#define MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_REQ             MSG_ID_MMI_CCA_SOURCE_INSTALL_PROV_MSG_REQ 
#define MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_CNF             MSG_ID_MMI_CCA_SOURCE_INSTALL_PROV_MSG_CNF 


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
/* Internal symbols just follow srv_cca_symbols_enum */
typedef enum
{

    SRV_CCA_NS_INT__START = (0x0000 | SRV_CCA_NS_CCA) + 0x100,
    SRV_CCA_NS_DEPREL,                              /* 501 */
    SRV_CCA_NS_DEP_PROXY,                           /* 502 */
    SRV_CCA_NS_DEP_APPLICATION,                     /* 503 */
    SRV_CCA_NS_DEP_BOOTSTRAP,                       /* 504 */
    SRV_CCA_NS_DEP_ACCESS,                          /* 505 */
    SRV_CCA_NS_DEP_NAPDEF,                          /* 506 */
    SRV_CCA_NS_HSRCNODE,                            /* 507 */
    SRV_CCA_NS_REFNAPID,                            /* 508 */
    SRV_CCA_NS_REFPXID,                             /* 509 */
    SRV_CCA_NS_DEP_DATAACCT,                        /* 50A */
    SRV_CCA_NS_ISUSED,                              /* 50B */
    SRV_CCA_NS_INAPPCONTEXT,                        /* 50C */
    SRV_CCA_NS_NODEFLAG,                            /* 50D */
    SRV_CCA_NS_INT___LAST       
}srv_cca_int_symbols_enum;



typedef enum
{
    SRV_CCA_STATE_IDLE,
    SRV_CCA_STATE_PROV,
    SRV_CCA_STATE_ASYNC,
    SRV_CCA_STATE_PROCESS_MSG,
    CCA_STATE_MAX_ITEM
} srv_cca_state_enum;

typedef enum
{
    SRV_CCA_MEM_FULL_IN_APP,
    SRV_CCA_MEM_FULL_MAX_ITEM
} srv_cca_mem_full_type_enum;

typedef enum
{
    /* Common */
    SRV_CCA_JOB_NEXT_JOB_REQ = 1,

    /* Prov */
    SRV_CCA_JOB_INVALID_SETTING_IND_REQ,
    SRV_CCA_JOB_NEW_SETTING_IND_REQ,
    SRV_CCA_JOB_NEW_SETTING_RSP_FEEDBACK,  /* only used for ObigoQ03C to abort current UI flow */
    SRV_CCA_JOB_NEW_DOC_RSP_FEEDBACK,

    SRV_CCA_JOB_CANCEL_NEW_MSG,
    SRV_CCA_JOB_VIEW_NEW_MSG,
    SRV_CCA_JOB_ENTER_IDLE_SCREEN_NOTIFY,
    SRV_CCA_JOB_AUTH_ABORT,

    /* SPA */
    SRV_CCA_JOB_SIM_PROFILE_STATUS_FEEDBACK,

    /* DM */
    SRV_CCA_JOB_GET_PROF_IND_REQ,
    SRV_CCA_JOB_UPDATE_PROF_IND_REQ,
    SRV_CCA_JOB_APP_GET_PROF_RSP_FEEDBACK,
    SRV_CCA_JOB_APP_UPDATE_PROF_RSP_FEEDBACK,
    SRV_CCA_JOB_SESSION_BEGIN_IND_REQ,
    SRV_CCA_JOB_SESSION_END_IND_REQ,

    /* ProvBox */
    SRV_CCA_JOB_PROCESS_PROV_MSG_REQ,
    SRV_CCA_JOB_PROCESS_PROV_MSG_CNF,

    SRV_CCA_JOB_MAX_ITEM
} srv_cca_job_type_enum;


typedef enum
{
    SRV_CCA_OPER_NULL,
    SRV_CCA_OPER_GET,
    SRV_CCA_OPER_UPDATE,

    CCA_OPER_MAX_ITEM
} srv_cca_oper_enum;

typedef enum
{
    SRV_CCA_SESSION_STATE_IDLE,
    SRV_CCA_SESSION_STATE_NO_SESSION,
    SRV_CCA_SESSION_STATE_BEGIN,
    SRV_CCA_SESSION_STATE_IN_SESSION,
    SRV_CCA_SESSION_STATE_LAST
} srv_cca_session_state_enum;

typedef enum
{
    SRV_CCA_PROCESS_MSG_STATE_IDLE,
    SRV_CCA_PROCESS_MSG_STATE_SET_MSG_FLAG,
    SRV_CCA_PROCESS_MSG_STATE_GET_MSG_INFO,
    SRV_CCA_PROCESS_MSG_STATE_UPDATE_READ_STATUS,
    SRV_CCA_PROCESS_MSG_STATE_BEGIN_INSTALL_MSG,
    SRV_CCA_PROCESS_MSG_STATE_UPDATE_PIN_STATUS,
    SRV_CCA_PROCESS_MSG_STATE_RECEIVE_NEW_DOC,
    SRV_CCA_PROCESS_MSG_STATE_UPDATE_APP_INSTALL_STATUS,
    SRV_CCA_PROCESS_MSG_STATE_UPDATE_MSG_INSTALL_STATUS,
    SRV_CCA_PROCESS_MSG_STATE_END_PROCESS_MSG,
    SRV_CCA_PROCESS_MSG_STATE_RESET_MSG_FLAG,
    SRV_CCA_PROCESS_MSG_LAST
} srv_cca_process_msg_state_enum;

typedef enum
{
    SRV_CCA_TRANS_ID_SET_MSG_FLAG,
    SRV_CCA_TRANS_ID_RESET_MSG_FLAG,
    SRV_CCA_TRANS_ID_INSTALL_MSG,
    SRV_CCA_TRANS_ID_GET_MSG_INFO,
    SRV_CCA_TRANS_ID_UPDATE_READ_STATUS,
    SRV_CCA_TRANS_ID_UPDATE_PIN_STATUS,
    SRV_CCA_TRANS_ID_UPDATE_APP_INSTALL_STATUS,
    SRV_CCA_TRANS_ID_UPDATE_MSG_INSTALL_STATUS = SRV_CCA_TRANS_ID_UPDATE_APP_INSTALL_STATUS + SRV_CCA_MAX_APPS + 1,
    SRV_CCA_TRANS_ID_LAST
} srv_cca_trans_id_enum;


typedef enum
{
    SRV_CCA_CMP_RESULT_BEFORE = -1,     /* First element comes before second element */
    SRV_CCA_CMP_RESULT_UNEQUAL = -1,    /* first element is not equal to second element */
    SRV_CCA_CMP_RESULT_EQUAL = 0,       /* first element is equal to second element */
    SRV_CCA_CMP_RESULT_AFTER = 1,       /* First element comes after second element  */
    SRV_CCA_CMP_RESULT_MAX_ITEM
} srv_cca_cmp_result_enum;


/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef void (*SRV_CCA_MEM_FULL_HDLR) (U8 identifier);
typedef U8(*SRV_CCA_FP_LIST_ELEM_EQUAL) (void *elem, void *user_data);

typedef srv_cca_cmp_result_enum (*SRV_CCA_SLIST_CMP_FUNC) (void *src, void *dst);

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*---------------------- CCA Document ----------------------------------------*/
/* It's the base structure of all structure with the "*next" field in the first position */
typedef struct cca_slist_st
{
    struct cca_slist_st  *next;
}srv_cca_slist_struct;


typedef struct cca_doc_node_datalist_st
{
    struct cca_doc_node_datalist_st *next;
    srv_cca_core_data_struct data;
} srv_cca_doc_node_datalist_struct;


typedef struct cca_doc_node_st
{
    struct cca_doc_node_st *next;
    struct cca_doc_node_st *parent;
    struct cca_doc_node_st *child;

    srv_cca_doc_node_datalist_struct *listchain;
    U8 num_data;    /* U8 is enough in current ability support*/
    U8 num_child;   /* U8 is enough in current ability support*/
    U16 node_id;
} srv_cca_doc_node_struct;

typedef struct cca_doc_nodelist_st
{
    struct cca_doc_nodelist_st *next;
    srv_cca_doc_node_struct *node;
} srv_cca_doc_nodelist_struct;

typedef struct cca_doc_iter_nodes_st
{
    struct cca_doc_iter_nodes_st *next;

    srv_cca_doc_nodelist_struct *nodes;
    U8 num_nodes;   /* U8 is enough in current ability support*/
    U16 node_id;
} srv_cca_doc_iter_nodes_struct;

typedef struct
{
    srv_cca_doc_node_struct *doc_tree;  /* include dependency setting as a child node within Root */
    srv_cca_doc_iter_nodes_struct *iter_nodes_list;
    U16 config_id;
    U8 dtAcctIDAdded;
} srv_cca_document_struct;


/*---------------------- Context Control -------------------------------------*/
#ifdef __SRV_CCA_SUPPORT_AUTH__
typedef struct cca_ui_auth_state_st
{
    struct cca_ui_auth_state_st *next;
    module_type dest_mod_id;
    U16 source_id;
    srv_cca_prov_type_enum prov_type;
    S32 trans_id;
    S32 maxAttempts;
    S32 count;
} srv_cca_auth_struct;
#endif /* __SRV_CCA_SUPPORT_AUTH__ */

typedef struct
{
    /* Common part */
    srv_cca_state_enum cca_state;
    srv_cca_state_enum state;
    U16 sim_id;
    U32 inst_flags;
    
    /* provisioning context */
    U32 prov_flag;
    S32 hConfig;
    S32 crtConfigIndex;
    module_type prs_mod_id;
    srv_cca_prov_type_enum prov_type;
    U16 source_id;
    U16 specId;
    S16 numApp;
    srv_cca_status_enum msg_config_result;  /* the install status of whole message */
    srv_cca_app_config_result_struct configResult[SRV_CCA_MAX_APPS];

    MMI_BOOL has_selected;
    U8 sel_cfg_num;
    U16 sel_cfg_ids[SRV_CCA_MAX_APPS];

    mmi_proc_func evt_proc;
    void *user_data;
    
    /* process messge context */
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    void *msg_info_cnf;
    srv_cca_process_msg_state_enum process_state;
    U8 end_key_pressed;
    U8 update_info_fail;
    srv_cca_prov_type_enum bak_prov_type;
    srv_cca_status_enum result;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

    /* async context */
#ifdef __SRV_CCA_PROF_OPER__
    module_type src_mod_id;
    srv_cca_oper_enum oper;
#ifdef __SRV_CCA_DM_SESSION__
    srv_cca_session_state_enum session_state;
#endif
    U16 appId;
    S32 profId;
    S32 asynchConfig;

#endif /* __SRV_CCA_PROF_OPER__ */

} srv_cca_inst_struct;

typedef struct cca_job_st
{
    struct cca_job_st *next;
    U32 job_id;
    srv_cca_job_type_enum type;
    module_type src_mod_id;
    U32 flag;
    void *data;
    U32 data_size;
} srv_cca_job_struct;


typedef struct
{
    srv_cca_job_struct *job_list;
    srv_cca_job_struct *curr_job;
    srv_cca_inst_struct inst_tbl[SRV_CCA_INST_MAX_NUM];
}srv_cca_cntx_struct;

/*----------------------------------------------------------------------------*/
/* Extern global variables                                                    */
/*----------------------------------------------------------------------------*/
//extern MMI_ID g_cca_group;

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/
/* Utils*/

#define SRV_CCA_LOG_DOC(x)                      do{(x) = (x);}while(0)           
#define SRV_CCA_LOG(x)                          do{}while(0)

#ifdef __SRV_CCA_DUMP__
#undef SRV_CCA_LOG_DOC
#define SRV_CCA_LOG_DOC                         srv_cca_dump_doc

#undef SRV_CCA_LOG
#define SRV_CCA_LOG(X)                          srv_cca_log X

extern void srv_cca_log(CHAR *format, ...);
extern void srv_cca_dump_coredata(srv_cca_core_data_struct *coredata);
extern void srv_cca_dump_iter_datalist(srv_cca_iterator_struct *iter_datalist);
extern void srv_cca_dump_node(srv_cca_doc_node_struct *node);
extern void srv_cca_dump_iter_nodelist(srv_cca_iterator_struct *iter_nodelist);
extern void srv_cca_dump_doc(S32 hConfig);

#endif /* __SRV_CCA_DUMP__ */

extern MMI_BOOL srv_cca_is_inst_busy(SRV_CCA_HANDLE h_inst);


/* Memory */
extern void srv_cca_mem_init(void);
extern void *srv_cca_malloc(U32 size);
extern void srv_cca_mfree(void *ptr);
extern S32 srv_cca_oma_is_memfull_during_app_configure(void);
extern void srv_cca_register_memfull_notify(SRV_CCA_MEM_FULL_HDLR hdlr, U32 type);
extern void srv_cca_deregister_memfull_notify(U32 type);

extern srv_cca_slist_struct *srv_cca_slist_add_tail(srv_cca_slist_struct *slist, srv_cca_slist_struct *node);
extern srv_cca_slist_struct *srv_cca_slist_remove(srv_cca_slist_struct *slist, srv_cca_slist_struct *node);
extern srv_cca_slist_struct *srv_cca_slist_remove_by_index(srv_cca_slist_struct **slist, S32 index);
extern srv_cca_slist_struct *srv_cca_slist_get_node_by_index(srv_cca_slist_struct *slist, U32 index);
extern srv_cca_slist_struct *srv_cca_slist_get_node_by_data(srv_cca_slist_struct *slist,
                                                            SRV_CCA_SLIST_CMP_FUNC compare_func, void *data);
extern S32 srv_cca_slist_get_num_by_data(
                            srv_cca_slist_struct *slist,
                            SRV_CCA_SLIST_CMP_FUNC compare_func,
                            void *data);
extern S32 srv_cca_slist_get_index(srv_cca_slist_struct *slist, srv_cca_slist_struct *node);


/* APP Config */
extern srv_cca_cntx_struct *srv_cca_get_cntx(void);
extern srv_cca_inst_struct *srv_cca_get_inst(srv_cca_cntx_struct *cntx);
extern srv_cca_inst_struct *srv_cca_get_def_inst(void);

extern const srv_cca_app_config_struct * srv_cca_get_app_config(U32 index);
extern module_type srv_cca_get_module_id_by_source(U16 source_id);
extern module_type srv_cca_get_module_id_by_app(U16 app_id);
extern module_type srv_cca_get_module_id_by_config(U16 config_id);

/* Job */
extern srv_cca_job_struct *srv_cca_job_create_new_job(srv_cca_job_type_enum type, module_type src_mod_id, void *data);
extern void srv_cca_job_free_job(srv_cca_job_struct *job);
extern int srv_cca_job_center_has_next_job(void);
extern srv_cca_status_enum srv_cca_job_center_scheduler(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);


/* Doc Utils */
extern void srv_cca_doc_link_list_elem_to_last(srv_cca_generic_ptr_struct **start, srv_cca_generic_ptr_struct *elem);
extern void *srv_cca_doc_list_find(srv_cca_generic_ptr_struct *list, SRV_CCA_FP_LIST_ELEM_EQUAL fpEqual, void *user_data);

/* Core Data */
extern srv_cca_status_enum srv_cca_doc_coredata_append(srv_cca_core_data_struct *data_obj, S32 size, void *values);
extern S32 srv_cca_doc_coredata_values_exists_str(CHAR **values_s, S32 size, CHAR *str);
extern void srv_cca_doc_coredata_release_values(srv_cca_core_data_struct *coredata);
extern void srv_cca_doc_datalist_release(srv_cca_doc_node_datalist_struct *datalist, U8 deep_delete);
extern U8 srv_cca_doc_equal_param_id(void *elem, void *user_data);

extern U8 srv_cca_doc_coredata_remove_value(srv_cca_core_data_struct *coredata, srv_cca_data_type_enum type, void *value);

/* Data List */
extern srv_cca_doc_node_datalist_struct *srv_cca_doc_datalist_new(U16 param_id, srv_cca_data_type_enum data_type);
extern srv_cca_doc_node_datalist_struct *srv_cca_doc_datalist_find_ptr(
                                        srv_cca_doc_node_datalist_struct *datalist,
                                        U16 param_id);

/* Node */
extern U8 srv_cca_doc_equal_node_id(void *elem, void *user_data);
extern U8 srv_cca_doc_node_check_equal_content(S32 hNode1, S32 hNode2);
extern U8 srv_cca_doc_node_has_param_value(S32 hNode, U16 param, srv_cca_data_type_enum datatype, void *value);
extern S32 srv_cca_doc_find_node_match_param_value(
            S32 hStartNode,
            U16 node_symbol,
            U16 param,
            srv_cca_data_type_enum datatype,
            void *value);

/* Node Data */
extern srv_cca_status_enum srv_cca_doc_update_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values);
extern srv_cca_status_enum srv_cca_doc_update_nodedata_strs(S32 hNode, U16 param_id, S32 size, const CHAR **values);

extern srv_cca_status_enum srv_cca_doc_remove_nodedata(S32 hNode, U16 param_id);

/* Iterator */
extern srv_cca_iterator_struct *srv_cca_iterator_new(
                                srv_cca_traverse_type_enum trType,
                                srv_cca_iter_type_enum itType,
                                srv_cca_generic_ptr_struct *begin,
                                U8 dpDel);

extern srv_cca_status_enum srv_cca_doc_get_nodedata_by_param(
                        srv_cca_iterator_struct *iter,
                        U16 param_id,
                        srv_cca_core_data_struct **data_obj);



/* OMA */ /* Too many entry? */
extern S32 srv_cca_oma_handle_new_doc(srv_cca_cntx_struct *cntx, S32 hConfig);
extern void srv_cca_oma_new_doc_continue(srv_cca_cntx_struct *cntx);
extern void srv_cca_oma_new_doc_process_next_app(srv_cca_cntx_struct *cntx);

extern void srv_cca_oma_construct_l1symbols(
                S32 hConfig,
                S32 max_symbols,
                S32 *num_symbols,
                U16 *l1symbols,
                S32 *l1symbols_count);
extern S32 srv_cca_oma_is_in_app_context(srv_cca_doc_node_struct *l1node);

extern srv_cca_status_enum srv_cca_oma_revise_doc(S32 hRoot);

/* Context */
extern void srv_cca_start_provisioning_job(srv_cca_cntx_struct *cntx);

extern void srv_cca_configure_complete(srv_cca_cntx_struct *cntx);
extern int srv_cca_new_config_result(srv_cca_inst_struct *inst, U16 config_id, srv_cca_status_enum result);
extern srv_cca_status_enum srv_cca_get_config_result(srv_cca_inst_struct *inst, U16 config_id);
extern int srv_cca_delete_config_result(srv_cca_inst_struct *inst, U16 config_id);


extern void srv_cca_send_new_doc_continue_ind(void);
extern void srv_cca_send_src_new_setting_rsp(
                module_type dest_mod_id,
                srv_cca_src_new_setting_ind_struct *new_setting_ind,
                srv_cca_status_enum response);

extern void srv_cca_send_src_new_doc_rsp(
                module_type dest_mod_id,
                U16 source_id,
                srv_cca_prov_type_enum prov_type,
                U16 sim_id,
                U16 spec_id,
                srv_cca_app_config_result_struct *config_result,
                S32 config_num,
                srv_cca_status_enum msg_config_result,
                srv_cca_status_enum status);

extern void srv_cca_send_app_configure_ind(
                srv_cca_inst_struct *inst,
                srv_cca_prov_type_enum prov_type,
                U32 prov_flag,
                U16 sim_id,
                U16 config_id,
                S32 hConfig);

#ifdef __SRV_CCA_PROF_OPER__
extern void srv_cca_send_cca_app_get_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, srv_cca_status_enum result);
extern void srv_cca_send_cca_app_update_prof_rsp(
                U16 sim_id,
                U16 app_id,
                S32 prof_id,
                S32 hConfig,
                srv_cca_status_enum result);
#endif /* __SRV_CCA_PROF_OPER__ */


/* Dispatcher */
extern void srv_cca_dispatch_ready_ind(srv_cca_ready_ind_struct *cca_ready_ind);
extern void srv_cca_dispatch_src_new_setting_rsp(srv_cca_src_new_setting_rsp_struct *new_setting_rsp);
extern void srv_cca_dispatch_src_auth_rsp(srv_cca_src_auth_rsp_struct *auth_rsp);
extern void srv_cca_dispatch_src_new_doc_rsp(srv_cca_src_new_doc_rsp_struct *new_doc_rsp);
extern void srv_cca_dispatch_app_configure_ind(srv_cca_app_configure_ind_struct *newConfigDoc);
extern void srv_cca_send_cca_app_configure_rsp(U16 sim_id, U16 conf_id, S32 doc_hdl, srv_cca_status_enum status);

#ifdef __SRV_CCA_SPA__
extern void srv_cca_spa_init(void);


extern srv_cca_status_enum srv_cca_handle_src_sim_profile_status(srv_cca_cntx_struct *cntx, void *msg, int mod_id, void *ilm);

extern void srv_cca_dispatch_app_sim_profile_status_ind(srv_cca_app_sim_profile_status_ind_struct *sim_profile_status);
#endif /* __SRV_CCA_SPA__ */

#ifdef __SRV_CCA_PROF_OPER__
extern void srv_cca_dm_init(void);
extern void srv_cca_dm_reset_cntx(srv_cca_inst_struct *inst);

extern srv_cca_status_enum srv_cca_summit_job_to_async_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);
extern void srv_cca_dm_handle_in_idle(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);
extern void srv_cca_dm_handle_in_prov(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);
extern void srv_cca_dm_handle_in_process_msg(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);

extern void srv_cca_dispatch_profile_operations(srv_cca_oper_enum oper, U16 app_id, void *local_parm);
#endif /* __SRV_CCA_PROF_OPER__ */



#ifdef __MMI_PROV_MESSAGE_SUPPORT__
extern void srv_cca_provbox_init(void);
extern void srv_cca_provbox_reset_cntx(srv_cca_inst_struct *inst);
extern srv_cca_status_enum srv_cca_submit_job_to_process_msg_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);
extern srv_cca_status_enum srv_cca_provbox_handle_in_idle(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);

extern MMI_BOOL srv_cca_provbox_handle_pin_ok(void);
extern MMI_BOOL srv_cca_provbox_src_new_doc_ind_hdlr(int mod_id, srv_cca_src_new_doc_ind_struct *data);
extern MMI_BOOL srv_cca_provbox_app_config_rsp_hdlr(srv_cca_inst_struct *inst, srv_cca_app_configure_rsp_struct *data);

extern void srv_cca_preprocess_config_result(srv_cca_inst_struct *inst);

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 


extern void srv_cca_handle_auth_input(WCHAR *w_pin);
extern void srv_cca_handle_auth_fail(void);


extern void srv_cca_emit_notify_event(srv_cca_inst_struct *inst, srv_cca_notify_type_enum type);
extern void srv_cca_emit_post_install_event(srv_cca_inst_struct *inst);
extern void srv_cca_emit_install_finished_event(srv_cca_inst_struct *inst);



extern srv_cca_status_enum srv_cca_doc_coredata_get_value(SRV_CCA_HANDLE h_coredata, S32 index, 
                    srv_cca_data_type_enum *data_type, void *value);

extern srv_cca_status_enum srv_cca_doc_coredata_get_all_value(SRV_CCA_HANDLE h_coredata, S32 index, 
                    srv_cca_data_type_enum *data_type, void **value_list, S32 *num);

extern srv_cca_status_enum srv_cca_doc_coredata_update_value(SRV_CCA_HANDLE h_coredata, S32 index, 
                    srv_cca_data_type_enum data_type, void *value);


extern srv_cca_status_enum srv_cca_doc_coredata_update_int(SRV_CCA_HANDLE h_coredata, S32 index, S32 value);

extern srv_cca_status_enum srv_cca_doc_coredata_update_str(SRV_CCA_HANDLE h_coredata, S32 index, const CHAR *value);

/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif 

#endif

#endif /* SRV_CCA_PROT_H */ 

