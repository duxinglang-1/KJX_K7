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
 * TCM_COMMON.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common functions of TCM.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _TCM_COMMON_H
#define _TCM_COMMON_H

//------------------------------ suggest Add ------------------------------
#include "tcm_common_enums.h"  
#include "ppp_l4_enums.h"
#include "mmi_sm_enums.h"
//#include "kal_release.h"
#include "app_ltlcom.h"
//#include "kal_non_specific_general_types.h"
//[?] #include "custom_mmi_default_value.h"
//#include "l4c2abm_struct.h"
//[?] #include "mmi2abm_struct.h"
#include "mmi_l3_enums.h"
//[?] #include "l4c_common_enum.h"
#include "mcd_l3_inc_gprs_struct.h"
//#include "l3_inc_struct.h"
//#include "l3_inc_enums.h"
#include "stack_msgs.h"
//[?] #include "MMI_stack_msgs.h"

//------------------------------ suggest Add ------------------------------
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"

/* Poying: 3G Switchable. */
#include "sim_public_enum.h"

#ifdef __PS_SERVICE__
#if !((GPRS_MAX_PDP_SUPPORT >= 1) && (GPRS_MAX_PDP_SUPPORT <= 7))
   #error please define GPRS_MAX_PDP_SUPPORT in the range [1-7]
#endif

#if ((MAX_INT_PDP_CONTEXT + MAX_EXT_PDP_CONTEXT) < GPRS_MAX_PDP_SUPPORT)
   #error ((MAX_INT_PDP_CONTEXT + MAX_EXT_PDP_CONTEXT) < GPRS_MAX_PDP_SUPPORT) please increase the MAX_EXT_PDP_CONTEXT or decrease GPRS_MAX_PDP_SUPPORT
#endif

#if ((MAX_INT_PDP_CONTEXT > GPRS_MAX_PDP_SUPPORT))
   #error please define MAX_INT_PDP_CONTEXT <= GPRS_MAX_PDP_SUPPORT
#endif

#ifdef __TCM_EXT_CALL_HISTORY_SUPPORT__
   #ifndef __EXT_PDP_CONTEXT_ON__
      #error need to configure MAX_EXT_PDP_CONTEXT > 0 to turn on __TCM_EXT_CALL_HISTORY_SUPPORT__
   #endif
#endif
#endif // ~ #ifdef __PS_SERVICE__

#if (defined(__PPP_TYPE_PDP_DIALUP_SUPPORT__) || defined(__TCM_UT__))
#define MAX_PDU_LENGTH    1502 // 0x00, 0x21, then 1500 Bytes IP packet 
#else // __PPP_TYPE_PDP_DIALUP_SUPPORT__
#define MAX_PDU_LENGTH    1500
#endif // ~__PPP_TYPE_PDP_DIALUP_SUPPORT__
#define TCM_INIT_NPDU_NOS 0
#define MMI_MAX_NUM_CONFIG_OPTION_PACKETS 84
#define SESSION_INFO_PTR  session_info_block_struct*
/* These defines are used as a flag to determine the amount to be
 * subtracted from either a nsapi or context_id to get the
 * corresponding sib_id.
 */
#define GET_FROM_NSAPI         0
#define GET_FROM_CONTEXTID     1
#define MMI_CONFIG_PROTOCOL_PPP  0

#define TCM_RMMI_NSAPI 5
#define TCM_LMMI_NSAPI 6


#define SME_ASSERT(X,Y) ASSERT(X)

#define assert ASSERT
#define mmi_err(X,Y) NULL

/* Default values used in the various fields of session information
 * block.
 */
#define DEF_ADDRTYPE          IPV4_ADDR_TYPE /* Default address is
                                              * IPv4.
                                              */
#define DEF_L2P               PPP    /* Default L2P is PPP */
#define DEF_APNLENGTH         0      /* Default Apn length is zero or
                                      * no apn.
                                      */
#define DEF_APN               NULL   /* Default Apn is no apn */
#define DEF_NPDUNUM           0      /* Default Npdu number is zero */
#define DEF_PCONFOPTLENGTH    0      /* Default protocol configuration
                                      * option length is zero or no
                                      * protocol configuration length.
                                      */
#define DEF_PCONFOPTS         NULL   /* Default protocol configuration
                                      * options are no configuration.
                                      */
#define DEF_PDPADDRLEN        NULL_PDP_ADDR_LEN/* Default pdp address
                                                * length is set to
                                                * NULL_PDP_ADDR_LEN.
                                                */
/* Total number of MMI Modules */
#define MMI_NUM_MODULES       2

/* Total number of nsapi's */
/* Modified by: CH_Liang 2005.01.25
 * Description: define the NSAPI range.
 */
#define TCM_TOT_NSAPI     			GPRS_MAX_PDP_SUPPORT
#define TCM_TOT_EXT_CONTEXT 	MAX_EXT_PDP_CONTEXT	/* for External */
//#define TCM_TOT_INT_CONTEXT 	TCM_TOT_NSAPI	/* for Internal */
#define TCM_TOT_INT_CONTEXT 	MAX_INT_PDP_CONTEXT	/* for Internal */
#define TCM_TOT_CONTEXT   			(TCM_TOT_EXT_CONTEXT + TCM_TOT_INT_CONTEXT)

// obselete
#define MMI_TOT_VISIBLE_CONTEXT 	TCM_TOT_EXT_CONTEXT
#define MMI_TOT_CONTEXT   			TCM_TOT_CONTEXT
// ~ obselete

#define TCM_INVALID_NSAPI		 	0
#define TCM_INVALID_CONTEXT_ID 	0

#define TCM_MIN_NSAPI           	MIN_VALID_NSAPI
#define TCM_MAX_NSAPI           	MAX_VALID_NSAPI
/* End of Modification, 2005.03.19. Reviewed by: Joseph */

#define TCM_MIN_CONTEXT_ID      1
#define TCM_MAX_CONTEXT_ID      1 + TCM_TOT_CONTEXT -1
#define DST_PORT_RANGE          2
#define SRC_PORT_RANGE          2
#define TOS_TRAF_CLASS_MASK_LEN 2
#define TCM_PRIMARY_UNKNOWN     0xFF /* Context id is set to 12 which
                                    * is not a valid context_id. Sib
                                    * should be initialized to this
                                    * value.
                                    */
#define  TCM_TFT_FIELD_NOT_PRESENT -1

#define TCM_PDP_TYPE              IPV4_ADDR_TYPE
#define TCM_PDP_LEN               IPV4_ADDR_LEN
#define MAX_SRC_ADDR_SBNET_MASK_LEN 8

/* mtk00714 w0633: AT definition*/
#define TCM_CGDCONT_DEFINED	0x01
#define TCM_CGDSCONT_DEFINED	0x02
#define TCM_CGQREQ_DEFINED	0x04
#define TCM_CGQMIN_DEFINED	0x08
#define TCM_CGTFT_DEFINED	0x10

/* mtk00938: ACL */
#define MAX_SIM_READ_SIZE  256
#define MAX_SIM_WRITE_SIZE  255

#define L4C_CONFIG_OPTION_STRUCT_IPV4_ADDR_LENGTH 4
#define TCM_IPV4_ADDR_LENGTH 4

// TCM used query number (256~0xFFFF), not L4C used query number (0~255)
#define TCM_USED_QUERY_NUMBER_FOR_RESET_CERTAIN_CID_LAST_AND_RESET_TOTAL_HISTORY 0xFFFF
#define TCM_USED_QUERY_NUMBER_FOR_RESET_CERTAIN_CID_LAST_HISTORY 0xFFFE
#define TCM_USED_QUERY_NUMBER_FOR_RESET_TOTAL_HISTORY 0xFFFD

#define TCM_CONTROL_PLANE_FN_ENTRY_LOG(X,Y) kal_brief_trace(TRACE_GROUP_4, Y)
#define TCM_CONTROL_PLANE_TRACE_GROUP TRACE_GROUP_4
#define TCM_CONTROL_PLANE_FN_NORMAL_EXIT_LOG(X,Y) kal_brief_trace(TRACE_GROUP_4, Y)
#define TCM_CONTROL_PLANE_FN_ABNORMAL_EXIT_LOG(X,Y) kal_brief_trace(TRACE_WARNING, Y)
#define TCM_DATA_PLANE_FN_ENTRY_LOG(X,Y) kal_brief_trace(TRACE_GROUP_10, Y)
#define TCM_DATA_PLANE_FN_NORMAL_EXIT_LOG(X,Y) kal_brief_trace(TRACE_GROUP_10, Y)
#define TCM_DATA_PLANE_FN_ABNORMAL_EXIT_LOG(X,Y) kal_brief_trace(TRACE_WARNING, Y)

#define TCM_FN_ENTRY_LOG(X,Y) kal_brief_trace(TRACE_FUNC, Y)
#define TCM_FN_NORMAL_EXIT_LOG(X,Y) kal_brief_trace(TRACE_FUNC, Y)
#define TCM_FN_ABNORMAL_EXIT_LOG(X,Y) kal_brief_trace(TRACE_WARNING, Y)

/* This structure is used to cast any message received by the tcm
 * module. Once a message is cast to this type the corresponding nsapi
 * or context_id will be available.
 */
typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8 id;
} mmi_nsapi_cntxt_id_cast_struct;

typedef struct pkt_filter_struct
{
    kal_uint8                context_id;
    kal_uint8                pfi;
    kal_uint8                epi;
    kal_uint8                src_addr_sb_net_mask_len;
    packet_filter_type_enum  type;
    kal_uint8       src_addr_sb_net_mask[MAX_SRC_ADDR_SBNET_MASK_LEN];
    kal_bool        prot_number_present;
    kal_uint8       prot_number_next_hdr;
    kal_uint16      dst_port_range[DST_PORT_RANGE];
    kal_uint8       dst_port_len;
    kal_uint8       src_port_len;
    kal_uint16      src_port_range[SRC_PORT_RANGE];
    kal_bool        ipsec_spi_present;
    kal_uint8       tos_len;
    kal_uint8       tos_traffic_class_mask [TOS_TRAF_CLASS_MASK_LEN];
    kal_uint32      ipsec_spi;
    kal_bool	    flow_label_present;
    kal_uint32      flow_label;
    struct pkt_filter_struct   *next_ptr;
} mmi_packet_filter_struct;

typedef struct
{
    mmi_packet_filter_struct *filter_list_ptr;
} mmi_tft_struct;

/* MMI : This is added for class-B MMI */
typedef struct mmi_protocol_config_packet_struct
{
    kal_uint16 protocol_id;
    kal_uint8  protocol_config_size;
    kal_uint8  protocol_config[ MAX_CONFIG_OPTION_CONTENT_LEN ];
    struct mmi_protocol_config_packet_struct *next_ptr;
} mmi_protocol_config_packet_struct;

typedef struct
{
    kal_uint8      context_id;/* Context identifier */
    kal_uint8      nsapi;     /* Nsapi identifier */
    kal_uint8      token_id; /* Stores the token_id sent by SM incase
                              * of a network initiated context
                              * activation indication
                              */
    //kal_uint8      profile_id; /* Internal profile identifier */ // For removing profile id between L4C and TCM
    tcm_pdp_activate_req_additional_para_type_enum additional_para_type;
    kal_uint32 additional_para_content;

    kal_uint8 	  AT_definition; //mtk00714 w0633
	
    pdp_context_type_enum context_type; /* Context type identifier
                                         * (Primary/Secondary).
                                         */
                                         
    kal_uint8  primary_context_id;/* Primary context identifier to 
                                   * which this context is associated.
                                   */
    /***************************************/
    /* affected by +CGDCONT and +CGDSCONT */
    /***************************************/
    kal_uint8      apn_len;  /* Access point name length. This is a
                              * optional parameter at the time of
                              * context activation.
                              */
    pdp_addr_type_enum     pdp_addr_type;/* pdp address type */
    pdp_addr_len_enum      pdp_addr_len; /* pdp address length */
    tcm_addr_scheme_enum   addr_scheme; /* Addressing scheme
                                         * (Static/Dynamic)
                                         */
    kal_uint8 addr_val[MAX_PDP_ADDR_LEN];/* pdp address is stored in
                                          * this field. the address is
                                          * filled in the most
                                          * significant bits; this
                                          * address received will have
                                          * variable length.
                                          */
    kal_uint8      apn[MAX_APN_LEN]; /* Access point name. */
        
    snd_pcomp_algo_enum pcomp_algo;/* Protocol compression algorithm
                                    * to be used.
                                    */
    snd_dcomp_algo_enum dcomp_algo;/* Protocol decompression algorithm
                                    * to be used.
                                    */
                                    
    /***************************************/
    /* affected by +CGQREQ and +CGEQREQ */
    /***************************************/
    qos_struct     req_qos; /* Requeseted qos */
									
    /***************************************/
    /* affected by +CGQMIN and +CGEQMIN */
    /***************************************/
    qos_struct     min_qos; /* Minimum qos */
	
    /****************************************/
    qos_struct     neg_qos; /* Negotiated qos */

    context_mod_type_enum     mod_type; /* Context modification type
                                         * field.
                                         */ 
    mmi_ltwoh_protocol_enum   l2p;   /* Layer two protocol used */
    kal_uint8 prot_option_len; /* Protocol configuration option length
                                * field.
                                */
    /* MMI: This is added for class-B MMI */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    kal_uint8           config_protocol;
    mmi_protocol_config_packet_struct  prot_options_struct;
#endif
    initiated_enum initiated_by;/* Context initiation identifier
                                 * (network/Ms)
                                 */
#ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
    mmi_tft_struct tft_in_use;  /* Traffic flow template currently
                                 * being used by a context.
                                 */
    mmi_tft_struct tft_under_mod;/* Traffic flow template to which the
                                  * context is requested to modify to.
                                  */
#endif // ~ #ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
    tcm_startup_type_enum startup_type; /* pdp startup identifier.
                                         * Could be internal(via ATCI)
                                         * or external(via PPP).
                                         */
    tcm_context_main_state_enum  main_state;// tcm context main state
    tcm_context_sub_state_enum  sub_state;// tcm context sub state
    tcm_context_data_plane_state_enum data_plane_state; // tcm data plane sub state
    kal_uint8 nsapi_for_tcm_ratdm_deconfig_req_use;
    kal_bool has_enter_data_plane_configured_state;

#ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
    tft_opcode_enum     tft_opcode;   /* the tft operation opcode */
#endif // ~ #ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
    tcm_sib_usage_enum  is_sib_defined;/* Used to know whether the
                                        * sib is free or in use.
                                        */
    kal_uint8          dns[MAX_PDP_ADDR_LEN];
    kal_uint8          sec_dns[MAX_PDP_ADDR_LEN];//Secondary DNS address
#if ( (defined(__NDIS_SUPPORT__)) || (defined(__TCM_UT__)) )
    kal_uint8           dns2[MAX_PDP_ADDR_LEN];	
    //module_type	module_id;
#endif
    kal_uint8          is_chap;

    //kal_uint8          name_length; // Carlson: remove useless context
    //kal_uint8          name_dcs; // Carlson: remove useless context
    //kal_uint8          name[32]; // Carlson: remove useless context
    kal_uint8          user_name[TCM_MAX_GPRS_USER_NAME_LEN];
    kal_uint8          password[TCM_MAX_GPRS_PASSWORD_LEN];

    kal_uint8          src_id; /* L4C src_id, add 04.04.29 */
    kal_uint8            tear_down_flag;  //erica dallas 20060505: for 2ndary PDP

#ifdef __HSDPA_SUPPORT__
    data_speed_activate_enum data_speed;
#endif // ~ #ifdef __HSDPA_SUPPORT__

    kal_uint16 		req_n201u; //erica 20070112

#ifdef __APP_SECONDARY_PDP_SUPPORT__
	//kal_uint8		app_src;
#endif
}session_info_block_struct; /* End of type definition of session
                             * information block.
                             */
/* MMI common functions prototypes */


#ifdef __GEMINI__
#ifndef GEMINI_PLUS
#define MOD_TCM_TOTAL_SIM (2)
#else
#define MOD_TCM_TOTAL_SIM (GEMINI_PLUS)
#endif
#endif

/* Functions to manipulate the session information block  */
extern kal_bool tcm_is_test_sim(void); //for __GEMINI__
kal_bool tcm_check_if_truely_exist_pdp_addr(kal_uint8 * addr_val_ptr, kal_uint8 addr_length);
extern void tcm_error_handler( local_para_struct *local_para_ptr,
                               peer_buff_struct  *peer_buff_ptr );

extern kal_bool tcm_terminate_context( kal_uint8 sib_id );

extern void tcm_send_write_statistic_to_nvram( void );

extern kal_bool  tcm_create_sib( kal_uint8         sib_id );

// obselete
extern kal_bool  mmi_create_sib( kal_uint8         sib_id );
// ~ obselete

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // ~ #if 0

extern kal_bool tcm_check_msg( ilm_struct *ilm_ptr ); 

extern kal_bool tcm_string_cmp( kal_uint8  *str1,
                                kal_uint32 len1,
                                kal_uint8  *str2,
                                kal_uint32 len2 );

extern void tcm_qos_extend(qos_struct *qos, kal_uint8 pdp_addr_type_enum_value, tcm_qos_type_enum qos_type);
void tcm_change_qos_length_to_proper_length(qos_struct *s);
extern void tcm_qos_R98_to_R99(qos_struct *s, kal_uint8 pdp_addr_type_enum_value, tcm_qos_type_enum qos_type);
extern void tcm_qos_R99_to_R98(qos_struct *s, tcm_qos_type_enum qos_type);
extern kal_bool tcm_qos_check_if_need_to_do_R98_to_R99(qos_struct *s, tcm_qos_type_enum qos_type);
extern kal_bool tcm_qos_check_if_need_to_do_R99_to_R98(qos_struct *s, tcm_qos_type_enum qos_type);

#if 0 // TCM reduce code size
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // ~ #if 0 TCM reduce code size


extern kal_bool tcm_is_sib_free( kal_uint8          sib_id,
                                 tcm_sib_usage_enum *sib );

extern kal_uint8 tcm_nsapi_check( kal_uint8 nsapi );

extern kal_uint8 tcm_cntxt_id_check( kal_uint8 cntxt_id );

extern kal_uint8 tcm_pdp_addr_ltcheck( pdp_addr_len_enum  pl,
                                       pdp_addr_type_enum pt );

#if 0
/* under construction !*/
#endif // ~ #if 0

extern kal_uint8 tcm_qos_check( qos_struct *q_ptr );

#if 0
/* under construction !*/
/* under construction !*/
#endif // ~ #if 0

extern session_info_block_struct *tcm_get_sib_ptr( kal_uint8 sib_id );

extern mmi_packet_filter_struct *tcm_free_list(
                                mmi_packet_filter_struct *l_ptr );

extern mmi_packet_filter_struct *tcm_delete_list(
                                mmi_packet_filter_struct *d_ptr,
                                mmi_packet_filter_struct *s_ptr );
extern void tcm_append_list( mmi_packet_filter_struct **d_ptr,
			     mmi_packet_filter_struct **s_ptr,
			     kal_bool replace );

extern kal_uint8 tcm_get_sib_id( kal_int32 flag,
                                 kal_uint8 val );

extern kal_uint8 tcm_get_context_id_from_sib_id( kal_uint8 sib_id );

 /* erica 20051215  mark unused codes */
//extern kal_uint8 mmi_get_nsapi( kal_uint8 sib_id );

extern kal_bool tcm_alloc_nsapi( kal_uint8 context_id );
extern void tcm_free_nsapi( SESSION_INFO_PTR si_db_ptr );

extern kal_uint8 tcm_nsapi_to_cid( kal_uint8 nsapi );
extern kal_uint8 tcm_cid_to_nsapi( kal_uint8 cid );
#if 0
/* under construction !*/
#endif // ~ #if 0

//erica 20060916
extern void tcm_fill_config_options(void *config_option, 
							kal_uint8* config_option_num, 
							kal_uint8 is_chap, 
							kal_uint8* user_name, 
							kal_uint8*password);
#if ( (defined(__NDIS_SUPPORT__)) || (defined(__TCM_UT__) && defined(__UMTS_RAT__)) ) // only in 3G load we UT on TCM
extern kal_bool is_external_context(kal_uint8 context_id);
#endif

#ifdef __TCM_EXT_CALL_HISTORY_SUPPORT__
void tcm_change_call_history_is_writing(kal_bool new_value);
void tcm_change_call_history_needs_update(kal_bool new_value);
void tcm_update_call_history_to_nvram(void);
void tcm_call_history_increment_total_tx_bytes(kal_uint64 increment_amount);
void tcm_call_history_increment_total_rx_bytes(kal_uint64 increment_amount);
void tcm_call_history_change_last_update_tx_bytes(kal_uint8 sib_id, kal_uint64 current_rx_bytes);
void tcm_call_history_change_last_update_rx_bytes(kal_uint8 sib_id, kal_uint64 current_rx_bytes);
void tcm_call_hisotry_increment_tx_bytes(kal_uint8 sib_id, kal_uint64 increment_num_bytes);
void tcm_call_hisotry_increment_rx_bytes(kal_uint8 sib_id, kal_uint64 increment_num_bytes);
void tcm_update_call_history_duration(kal_uint8 sib_id);
void tcm_send_write_ext_call_history_to_nvram( void );
void tcm_update_call_history_when_enter_data_plane_configured_state(SESSION_INFO_PTR si_db_ptr);
void tcm_update_call_history_when_enter_data_plane_deconfigured_state(SESSION_INFO_PTR si_db_ptr, ilm_struct * ilm_ptr);
void tcm_l4ctcm_query_ext_gprs_history_req_hdlr(ilm_struct * ilm_ptr);
void tcm_l4ctcm_reset_ext_gprs_history_req_hdlr(ilm_struct * ilm_ptr);
void tcm_ratdm_reset_ps_statistics_cnf_hdlr_for_call_history(ilm_struct *ilm_ptr);
void tcm_ratdm_query_ps_statistics_cnf_hdlr_for_call_history(ilm_struct *ilm_ptr);
kal_bool tcm_this_query_is_triggered_by_l4c(kal_uint16 query_serial_number);
void tcm_reset_certain_cid_last_history(void);
#endif // ~ __TCM_EXT_CALL_HISTORY_SUPPORT__

#if (( (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) && (!defined(__MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_PHASE_OUT__)) ) || (defined(__TCM_UT__)))
void tcm_change_statistic_is_writing(kal_bool new_value);
void tcm_change_statistic_needs_update(kal_bool new_value);
void tcm_update_old_call_history_to_nvram(void);
void tcm_update_old_call_history_when_enter_data_plane_deconfigured_state(SESSION_INFO_PTR si_db_ptr, ilm_struct * ilm_ptr);
void tcm_update_old_call_history_when_enter_data_plane_configured_state(SESSION_INFO_PTR si_db_ptr);
void tcm_ratdm_reset_ps_statistics_cnf_hdlr_for_old_call_history(ilm_struct *ilm_ptr);
void tcm_ratdm_query_ps_statistics_cnf_hdlr_for_old_call_history(ilm_struct * ilm_ptr);
void l4ctcm_get_gprs_statistics_info_req_hdlr(ilm_struct * ilm_ptr);
#endif // ~ #if (( (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) && (!defined(__MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_PHASE_OUT__)) ) || (defined(__TCM_UT__)))

kal_bool tcm_check_if_qos_is_all_zero(qos_struct * s);
kal_bool tcm_check_if_eqos_is_all_zero(qos_struct * s);

void tcm_change_additional_para_value(SESSION_INFO_PTR si_db_ptr, kal_uint8 new_type, kal_uint32 new_value);
void tcm_change_tcm_context_main_state_value(SESSION_INFO_PTR si_db_ptr, tcm_context_main_state_enum new_value);
void tcm_change_tcm_context_sub_state_value(SESSION_INFO_PTR si_db_ptr, tcm_context_sub_state_enum new_value);
void tcm_change_tcm_context_data_plane_state_value(SESSION_INFO_PTR si_db_ptr, tcm_context_data_plane_state_enum new_value, ilm_struct *ilm_ptr);
void tcm_data_plane_fsm_event_occur(SESSION_INFO_PTR si_db_ptr, tcm_data_plane_fsm_event_enum event, ilm_struct *ilm_ptr);
void tcm_print_fsm_values(SESSION_INFO_PTR si_db_ptr);
void tcm_record_rcvd_msg_and_current_sib_state(msg_type, SESSION_INFO_PTR si_db_ptr);
void tcm_change_state_according_to_happened_events(SESSION_INFO_PTR si_db_ptr, ilm_struct *ilm_ptr);
void tcm_record_sent_fsm_msg(msg_type msg_id);

kal_bool tcm_check_sent_msgs_contain_these_msgs(msg_type msg_to_be_checked);

/* Poying: 3G Switchable. */
sim_interface_enum tcm_get_actual_sim_id(void) ;

#ifdef __TCM_UT__
void tcm_ut_get_current_time(kal_uint32 * return_value);
#endif // ~ #ifdef __TCM_UT__

#endif


