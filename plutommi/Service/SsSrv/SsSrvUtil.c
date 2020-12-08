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

/*******************************************************************************
 * Filename:
 * ---------
 *  SsSrvUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS service utilities
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "SsSrvGprot.h"
#include "SsSrvIprot.h"
#include "SsSrvProt.h"
#include "mmi_rp_srv_ss_def.h"

#include "NwUsabSrvGprot.h" /* srv_nw_usab_is_usable */
#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_xxx */
#include "App_usedetails.h" /* applib_ss_string_parsing_unicode */
#include "CphsSrvGprot.h" /* srv_cphs_is_service_available */
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_is_network_service_available */

#include "MMI_features.h"
#include "l3_inc_enums.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "NetSetSrvGprot.h"
#include "l4c_common_enum.h"
#include "csmss_common_enums.h"
#include "UcmSrvGprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "gui.h"
#include "Gsm7BitNationalLang.h"
#include "sim_common_enums.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "CallSetSrvGprot.h" /* srv_callset_line_switch_get_id */



/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/

#ifdef __MMI_SS_SHOW_CAUSE__
static const srv_ss_cause_table_struct g_srv_ss_cause_str[] = 
{
#ifdef __MMI_OP12_SS_ERR_MSG__
    {CM_SS_ERR_UNKNOWNSUBSCRIBER, "Not available"}, /*0x01*/
    {CM_SS_ERR_ILLEGALSUBSCRIBER, "Not available"}, /*0x0a*/
    {CM_SS_ERR_TELESERVICENOTPROVISIONED, "Not available"}, /*0x0b*/                    
    {CM_SS_ERR_CALLBARRED, "Not available"}, /*0x0d*/  
    {CM_SS_ERR_ILLEGALSS_OPERATION, "Not available"}, /*0x10*/ 
    {CM_SS_ERR_SS_ERRORSTATUS, "Not available"}, /*0x11*/ 
    {CM_SS_ERR_SS_NOTAVAILABLE, "Not available"}, /*0x12*/ 
    {CM_SS_ERR_SS_SUBSCRIPTIONVIOLATION, "Not available"}, /*0x13*/ 
    {CM_SS_ERR_SS_INCOMPABILITY, "Not available"}, /*0x14*/ 
    {CM_SS_ERR_FACILITYNOTSUPPORTED, "Not available"}, /*0x15*/
    {CM_SS_ERR_SYSTEMFAILURE, "Not available"}, /*0x22*/
    {CM_SS_ERR_DATAMISSING, "Not available"}, /*0x23*/
    {CM_SS_ERR_UNEXPECTEDDATAVALUE, "Not available"}, /*0x24*/
    {CM_SS_ERR_MAXNUMBEROFMPTY_PARTICIPANTSEXCEEDED, "Not available"}, /*0x7e*/
    {CM_SS_ERR_RESOURCESNOTAVAILABLE, "Not available"}, /*0x7f*/
    {CM_SS_ERR_PW_REGISTRATIONFAILURE, "Password error"}, /*0x25*/
    {CM_SS_ERR_NEGATIVEPW_CHECK, "Password error"}, /*0x26*/
    {CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION, "Password error, this function has been locked, so please call customer center."}, /*0x2b*/
#else /* __MMI_OP12_SS_ERR_MSG__ */
    {CM_UNASSIGNED_NUM, "Cm unassigned num"},
    {CM_NO_ROUTE_TO_DESTINATION, "Cm no route to destination"},
    {CM_CHANNEL_UN_ACCP, "Cm channel un accp"},
    {CM_OPR_DTR_BARRING, "Cm opr dtr barring"},
    {CM_CALL_BARRED, "Cm call barred"},
    {CM_RESERVED, "Cm reserved"},
    {CM_NORMAL_CALL_CLR, "Cm normal call clr"},
    {CM_USER_BUSY, "Cm user busy"},
    {CM_NO_USER_RESPONDING, "Cm no user responding"},
    {CM_NO_ANSWER_ON_ALERT, "Cm no answer on alert"},
    {CM_CALL_REJECTED, "Ccm call rejected"},
    {CM_NUMBER_CHANGED, "Cm number changed"},
    {CM_PRE_EMPTION, "Cm pre emption"},
    {CM_NON_SEL_USER_CLEAR, "Cm non sel user clear"},
    {CM_DEST_OUT_OF_ORDER, "Cm dest out of order"},
    {CM_INVALID_NUMBER_FORMAT, "Cm invalid number format"},
    {CM_FACILITY_REJECT, "Cm facility reject"},
    {CM_RES_STATUS_ENQ, "Cm res status enq"},
    {CM_NORMAL_UNSPECIFIED, "Cm normal unspecified"},
    {CM_NO_CIRCUIT_CHANNEL_AVAIL, "Cm no circuit channel avail"},
    {CM_NETWORK_OUT_OF_ORDER, "Cm network out of order"},
    {CM_TEMPORARY_FAILURE, "Cm temporary failure"},
    {CM_SWITCH_EQUIPMENT_CONGESTION, "Cm switch equipment congestion"},
    {CM_ACCESS_INFO_DISCARDED, "Cm access info discarded"},
    {CM_REQUESTED_CKT_CHANEL_NOT_AVIL, "Cm requested ckt chanel not avil"},
    {CM_RESOURCE_UNAVAIL_UNSPECIFIED, "Cm resource unavail unspecified"},
    {CM_QOS_UNAVAIL, "Cm qos unavail"},
    {CM_REQ_FAC_NOT_SUBS, "Cm req fac not subs"},
    {CM_IC_BAR_CUG, "Cm ic bar cug"},
    {CM_BEARER_CAP_NOT_AUTHORISED, "Cm bearer cap not authorised"},
    {CM_BEARER_CAP_NOT_AVAIL, "Cm bearer cap not avail"},
    {CM_SER_UNAVAILABLE, "Cm ser unavailable"},
    {CM_BEARER_SER_UNIMPL, "Cm bearer ser unimpl"},
    {CM_ACM_EXCEEDED, "Cm acm exceeded"},
    {CM_REQ_FACILITY_UNAVAIL, "Cm req facility unavail"},
    {CM_RESTR_DIGITAL_INFO, "Cm restr digital info"},
    {CM_SER_OPT_UNIMPL, "Cm ser opt unimpl"},
    {CM_INVALID_TI_VALUE, "Cm invalid ti value"},
    {CM_USER_NOT_IN_CUG, "Cm user not in cug"},
    {CM_INCOMPATIBLE_DEST, "Cm incompatible dest"},
    {CM_INVALID_TRANSIT_NW_SEL, "Cm invalid transit nw sel"},
    {CM_SEMANTIC_ERR, "Cm semantic err"},
    {CM_INVALID_MANDATORY_INF, "Cm invalid mandatory inf"},
    {CM_MSG_TYPE_UNIMPL, "Cm msg type unimpl"},
    {CM_MSG_TYPE_NOT_COMPATIBLE, "Cm msg type not compatible"},
    {CM_IE_NON_EX, "Cm ie non ex"},
    {CM_COND_IE_ERR, "Cm cond ie err"},
    {CM_INCOMP_MESG_WITH_STATE, "Cm incomp mesg with state"},
    {CM_RECOVERY_ON_TIMER_EXPIRY, "Cm recovery on timer expiry"},
    {CM_PROTOCOL_ERR_UNSPECIFIED, "Cm protocol err unspecified"},
    {CM_INTER_WRK_UNSPECIFIED, "Cm inter wrk unspecified"},
    {TELEMATIC_INT_WRK_NOT_SUPPORT, "Telematic int wrk not support"},
    {SMS_TYPE0_NOT_SUPPORT, "Sms type0 not support"},
    {CANNOT_REPLACE_MSG, "Cannot replace msg"},
    {UNSPECIFIED_PID_ERROR, "Unspecified pid error"},
    {ALPHABET_NOT_SUPPORT, "Alphabet not support"},
    {MSG_CLASS_NOT_SUPPORT, "Msg class not support"},
    {UNSPECIFIED_TP_DCS, "Unspecified tp dcs"},
    {CMD_CANNOT_ACTION, "Cmd cannot action"},
    {CMD_NOT_SUPPORT, "Cmd not support"},
    {UNSPECIFIED_CMD_ERROR, "Uunspecified cmd error"},
    {TPDU_NOT_SUPPORT, "Tpdu not support"},
    {SC_BUSY, "Sc busy"},
    {NO_SC_SUBSCRIPTION, "No sc subscription"},
    {SC_SYS_FAILURE, "Sc sys failure"},
    {INVALID_SME_ADDR, "Invalid sme addr"},
    {DEST_SME_BARRED, "Dest sme barred"},
    {SM_REJ_DUP_SM, "Sm rej dup sm"},
    {TP_VPF_NOT_SUPPORT, "Tp vpf not support"},
    {TP_VP_NOT_SUPPORT, "Tp vp not support"},
    {SIM_STORAGE_FULL, "Sim storage full"},
    {NO_SMS_STO_IN_SIM, "No sms sto in sim"},
    {ERROR_IN_MS, "Error in ms"},
    {MEM_CAP_EXCEEDED, "Mem cap exceeded"},
    {SMS_SAT_BUSY, "Sms sat busy"},
    {SMS_SAT_DL_ERROR, "Sms sat dl error"},
    {SMS_CP_RETRY_EXCEED, "Sms cp retry exceed"},
    {SMS_RP_TR1M_TIMEOUT, "Sms rp tr1m timeout"},
    {SMS_CONNECTION_BROKEN, "Sms connection broken"},
    {UNSPECIFIED_TP_FCS, "Unspecified tp fcs"},
    {INVALID_PDU_MODE_PARA, "Invalid pdu mode para"},
    {INVALID_TEXT_MODE_PARA, "Invalid text mode para"},
    {SMS_SIM_FAILURE, "Sms sim failure"},
    {MEM_FAILURE, "Mem failure"},
    {INVALID_MEM_INDEX, "Invalid mem index"},
    {MEM_FULL, "Mem full"},
    {SCA_UNKNOWN, "Sca unknown"},
    {NO_CNMA_EXPECTED, "No cnma expected"},
    {SMSAL_UNSPECIFIED_ERROR_CAUSE, "Smsal unspecified error cause"},
    {SMSAL_NO_ERROR, "Smsal no error"},
    {MSG_LEN_EXCEEDED, "Msg len exceeded"},
    {INVALID_REQ_PARAMETER, "Invalid req parameter"},
    {SMS_ME_STORAGE_FAILURE, "Sms me storage failure"},
    {SMSAL_INVALID_BEARER, "Smsal invalid bearer"},
    {SMSAL_INVALID_SERVICE_MODE, "Smsal invalid service mode"},
    {SMSAL_INVALID_STORAGE_TYPE, "Smsal invalid storage type"},
    {SMSAL_INVALID_MSG_FORMAT, "Smsal invalid msg format"},
    {TOO_MANY_MO_CONCAT_MSG, "Too many mo concat msg"},
    {SMSAL_NOT_READY, "Smsal not ready"},
    {SMSAL_NO_MO_SERVICE, "Smsal no mo service"},
    {NOT_SUPP_SR_CMD_IN_STORAGE, "Not supp sr cmd in storage"},
    {SMSAL_NOT_SUPPORT_MSG_TYPE, "Smsal not support msg type"},
    {CSMCC_CMD_NOT_ALLOW, "Csmcc cmd not allow"},
    {CSMCC_ILLEGAL_CALL_ID, "Csmcc illegal call id"},
    {CSMCC_CALL_ALLOC_FAIL, "Csmcc call alloc fail"},
    {CSMCC_BC_FILL_FAIL, "Csmcc bc fill fail"},
    {CSMCC_CALL_RE_EST, "Csmcc call re est"},
    {CSMCC_ILLEGAL_DTMF_TONE, "Csmcc illegal dtmf tone"},
    {CSMCC_ILLEGAL_BC, "Csmcc illegal bc"},
    {CSMCC_MODIFY_ACTUAL_MODE, "Csmcc modify actual mode"},
    {CSMCC_DATA_ACT_FAIL, "Ccsmcc data act fail"},
    {CSMCC_NO_RESPONSE_FROM_NW, "Csmcc no response from nw"},
    {CSMCC_CALL_ACCEPT_NOT_ALLOW, "Csmcc call accept not allow"},
    {CM_SS_ERR_UNKNOWNSUBSCRIBER, "Cm ss err unknown subscriber"},
    {CM_SS_ERR_ILLEGALSUBSCRIBER, "Cm ss err illegal subscriber"},
    {CM_SS_ERR_BEARERSERVICENOTPROVISIONED, "Cm ss err bearer service not provisioned"},
    {CM_SS_ERR_TELESERVICENOTPROVISIONED, "Cm ss err teleservice not provisioned"},
    {CM_SS_ERR_ILLEGALEQUIPMENT, "Cm ss err illegal equipment"},
    {CM_SS_ERR_CALLBARRED, "Cm ss err call barred"},
    {CM_SS_ERR_ILLEGALSS_OPERATION, "Cm ss err illegalss operation"},
    {CM_SS_ERR_SS_ERRORSTATUS, "Cm ss err ss error status"},
    {CM_SS_ERR_SS_NOTAVAILABLE, "Cm ss err ss not available"},
    {CM_SS_ERR_SS_SUBSCRIPTIONVIOLATION, "Cm ss err ss subscription violation"},
    {CM_SS_ERR_SS_INCOMPABILITY, "Cm ss err ss incompability"},
    {CM_SS_ERR_FACILITYNOTSUPPORTED, "Cm ss err facility not supported"},
    {CM_SS_ERR_ABSENTSUBSCRIBER, "Cm ss err absent subscriber"},
    {CM_SS_ERR_SHORTTERMDENIAL, "Cm ss err short termdenial"},
    {CM_SS_ERR_LONGTERMDENIAL, "Cm ss err long termdenial"},
    {CM_SS_ERR_SYSTEMFAILURE, "Cm ss err system failure"},
    {CM_SS_ERR_DATAMISSING, "Cm ss err data missing"},
    {CM_SS_ERR_UNEXPECTEDDATAVALUE, "Cm ss err unexpected data value"},
    {CM_SS_ERR_PW_REGISTRATIONFAILURE, "Cm ss err pw registration failure"},
    {CM_SS_ERR_NEGATIVEPW_CHECK, "Cm ss err negative pw check"},
    {CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION, "Cm ss err number of pw attempts violation"},
    {CM_SS_ERR_POSITIONMETHODFAILURE, "Cm ss err position method failure"},
    {CM_SS_ERR_UNKNOWNALPHABET, "Cm ss err unknown alphabet"},
    {CM_SS_ERR_USSD_BUSY, "Cm ss err ussd busy"},
    {CM_SS_ERR_REJECTEDBYUSER, "Cm ss err rejected by user"},
    {CM_SS_ERR_REJECTEDBYNETWORK, "Cm ss err rejected by network"},
    {CM_SS_ERR_DEFLECTIONTOSERVEDSUBSCRIBER, "Cm ss err deflection to served subscriber"},
    {CM_SS_ERR_SPECIALSERVICECODE, "Cm ss err special service code"},
    {CM_SS_ERR_INVALIDDEFLECTIONTONUMBER, "Cm ss err invalid deflection to number"},
    {CM_SS_ERR_MAXNUMBEROFMPTY_PARTICIPANTSEXCEEDED, "Cm ss err max number of mpty participants exceeded"},
    {CM_SS_ERR_RESOURCESNOTAVAILABLE, "Cm ss err resources not available"},
    {CM_SS_GENERALPROBLEM_UNRECOGNIZEDCOMPONENT, "Cm ss general problem unrecognized component"},
    {CM_SS_GENERALPROBLEM_MISTYPEDCOMPONENT, "Cm ss general problem mistyped component"},
    {CM_SS_GENERALPROBLEM_BADLYSTRUCTUREDCOMPONENT, "Cm ss general problem badly structured component"},
    {CM_SS_INVOKEPROBLEM_DUPLICATEINVOKEID, "Cm ss invoke problem duplicate invokeid"},
    {CM_SS_INVOKEPROBLEM_UNRECOGNIZEDOPERATION, "Cm ss invoke problem unrecognized operation"},
    {CM_SS_INVOKEPROBLEM_MISTYPEDPARAMETER, "Cm ss invoke problem mistyped parameter"},
    {CM_SS_INVOKEPROBLEM_RESOURCELIMITATION, "Cm ss invoke problem resource limitation"},
    {CM_SS_INVOKEPROBLEM_INITIATINGRELEASE, "Cm ss invoke problem initiating release"},
    {CM_SS_INVOKEPROBLEM_UNRECOGNIZEDLINKDID, "Cm ss invoke problem unrecognized linkdid"},
    {CM_SS_INVOKEPROBLEM_LINKEDRESONSEUNEXPECTED, "Cm ss invokeproblem linkedresonseunexpected"},
    {CM_SS_INVOKEPROBLEM_UNEXPECTEDLINKEDOPERATION, "Cm ss invokeproblem unexpectedlinkedoperation"},
    {CM_SS_RETURNRESULTPROBLEM_RR_UNRECOGNIZEDINVOKEID, "Cm ss returnresultproblem rr unrecognizedinvokeid"},
    {CM_SS_RETURNRESULTPROBLEM_RR_RETURNRESULTUNEXPECTED, "Cm ss returnresultproblem rr returnresultunexpected"},
    {CM_SS_RETURNRESULTPROBLEM_RR_MISTYPEDPARAMETER, "Cm ss returnresultproblem rr mistypedparameter"},
    {CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDINVOKEID, "Cm ss returnerrorproblem re unrecognizedinvokeid"},
    {CM_SS_RETURNERRORPROBLEM_RE_RETURNERRORUNEXPECTED, "Cm ss returnerrorproblem re returnerrorunexpected"},
    {CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDERROR, "Cm ss returnerrorproblem re unrecognizederror"},
    {CM_SS_RETURNERRORPROBLEM_RE_UNEXPECTEDERROR, "Cm ss returnerrorproblem re unexpectederror"},
    {CM_SS_RETURNERRORPROBLEM_RE_MISTYPEDPARAMETER, "Cm ss returnerrorproblem re mistypedparameter"},
    {CM_MM_CAUSE_NONE, "Cm mm cause none"},
    {CM_MM_IMSI_UNKNOWN_IN_HLR, "Cm mm imsi unknown in hlr"},
    {CM_MM_ILLEGAL_MS, "Cm mm illegal ms"},
    {CM_MM_IMSI_UNKNOWN_IN_VLR, "Cm mm imsi unknown in vlr"},
    {CM_MM_IMEI_NOT_ACCEPTED, "Cm mm imei not accepted"},
    {CM_MM_ILLEGAL_ME, "Cm mm illegal me"},
    {CM_MM_GPRS_NOT_ALLOWED, "Cm mm gprs not allowed"},
    {CM_MM_GPRS_NON_GPRS_NOT_ALLOWED, "Cm mm gprs non gprs not allowed"},
    {CM_MM_MS_ID_NOT_DERIVED_BY_NW, "Cm mm ms id not derived by nw"},
    {CM_MM_IMPLICIT_DETACH, "Cm mm implicit detach"},
    {CM_MM_PLMN_NOT_ALLOWED, "Cm mm plmn not allowed"},
    {CM_MM_LOCATION_AREA_NOT_ALLOWED, "Cm mm location area not allowed"},
    {CM_MM_ROAMING_AREA_NOT_ALLOWED, "Cm mm roaming area not allowed"},
    {CM_MM_GPRS_NOT_ALLOWED_IN_PLMN, "Cm mm gprs not allowed in plmn"},
    {CM_MM_NO_SUITABLE_CELLS_IN_LA, "Cm mm no suitable cells in la"},
    {CM_MM_MSC_TEMP_NOT_REACHABLE, "Cm mm msc temp not reachable"},
    {CM_MM_NETWORK_FAILURE, "Cm mm network failure"},
    {CM_MM_MAC_FAILURE, "Cm mm mac failure"},
    {CM_MM_SYNC_FAILURE, "Cm mm sync failure"},
    {CM_MM_CONGESTION, "Cm mm congestion"},
    {CM_MM_SERV_OPTION_NOT_SUPPORTED, "Cm mm serv option not supported"},
    {CM_MM_REQ_SERV_OPTION_NOT_SUBSCRIBED, "Cm mm req serv option not subscribed"},
    {CM_MM_SERV_OPTION_TEMP_OUT_OF_ORDER, "Cm mm serv option temp out of order"},
    {CM_MM_CALL_CANNOT_BE_IDENTIFIED, "Cm mm call cannot be identified"},
    {CM_MM_NO_PDP_CONTEXT_ACTIVATED, "Cm mm no pdp context activated"},
    {CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN, "Cm mm retry upon entry into newcell min"},
    {CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX, "Cm mm retry upon entry into newcell max"},
    {CM_MM_SEMANTICALLY_INCORRECT_MSG, "Cm mm semantically incorrect msg"},
    {CM_MM_INVALID_MM_MAND_INFO, "Cm mm invalid mm mand info"},
    {CM_MM_MSG_TYPE_NON_EXISTENT, "Cm mm msg type non existent"},
    {CM_MM_MSG_TYPE_NOT_IMPLEMENTED, "Cm mm msg type not implemented"},
    {CM_MM_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE, "Cm mm msg type incompat with proto state"},
    {CM_MM_IE_NOT_IMPLEMENTED, "Cm mm ie not implemented"},
    {CM_MM_CONDITIONAL_MM_IE_ERROR, "Cm mm conditional mm ie error"},
    {CM_MM_MSG_NOT_COMPAT_WITH_PROTO_STATE, "Cm mm msg not compat with proto state"},
    {CM_MM_PROTO_ERROR_UNSPECIFIED, "Cm mm proto error unspecified"},
    {CM_MM_ACCESS_BARRED, "Cm mm access barred"},
    {CM_MM_ASSIGNMENT_REJECT, "Cm mm assignment reject"},
    {CM_MM_RANDOM_ACCES_FAILURE, "Cm mm random acces failure"},
    {CM_MM_RR_NO_SERVICE, "Cm mm rr no service"},
    {CM_MM_RR_CONN_RELEASE, "Cm mm rr conn release"},
    {CM_MM_AUTH_FAILURE, "Cm mm auth failure"},
    {CM_MM_IMSI_DETACH, "Cm mm imsi detach"},
    {CM_MM_ABORT_BY_NW, "Cm mm abort by nw"},
    {CM_MM_CONN_TIMEOUT, "Cm mm conn timeout"},
    {CM_MM_CM_ENQUEUE_FAIL, "Cm mm cm enqueue fail"},
    {CM_MM_NOT_UPDATED, "Cm mm not updated"},
    {CM_MM_STATE_NOT_ALLOWED_CM, "Cm mm state not allowed cm"},
    {CM_MM_EMERGENCY_NOT_ALLOWED, "Cm mm emergency not allowed"},
    {CM_MM_NO_SERVICE, "Cm mm no service"},
    {CM_MM_ACCESS_CLASS_BARRED, "Cm mm access class barred"},
    {SIM_CAUSE_CMD_SUCCESS, "Sim cause cmd success"},
    {SIM_CAUSE_CMD_FAIL, "Sim cause cmd fail"},
    {SIM_CAUSE_FATAL_ERROR, "Sim cause fatal error"},
    {SIM_CAUSE_NO_INSERTED, "Sim cause no inserted"},
    {SIM_CAUSE_CHV_NOT_INIT, "Sim cause chv not init"},
    {SIM_CAUSE_CHV_VERIFY_ERROR, "Sim cause chv verify error"},
    {SIM_CAUSE_CHV_BLOCK, "Sim cause chv block"},
    {SIM_CAUSE_ACCESS_NOT_ALLOW, "Sim cause access not allow"},
    {SIM_CAUSE_SAT_CMD_BUSY, "Sim cause sat cmd busy"},
    {SIM_CAUSE_DL_ERROR, "Sim cause dl error"},
    {SIM_CAUSE_MEMORY_PROBLEM, "Sim cause memory problem"},
    {SIM_CAUSE_TECHNICAL_PROBLEM, "Sim cause technical problem"},
    {SIM_CAUSE_PUK_UNLOCK, "Sim cause puk unlock"},
    {PHB_CAUSE_FDN_BLOCKED, "Phb cause fdn blocked"},
#endif /* __MMI_OP12_SS_ERR_MSG__ */
    {(U16)NULL, ""}
};

#endif /* __MMI_SS_SHOW_CAUSE__ */ 


/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_available
 * DESCRIPTION
 *  to check if ss service is available
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if ss service is available
 *****************************************************************************/
MMI_BOOL srv_ss_is_available(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* general */
    if (!srv_mode_switch_is_network_service_available()) /* flight mode */
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_AVAILABLE, sim, MMI_FALSE, 1);
        return MMI_FALSE;
    }

    /* sim specific */
    if (!srv_sim_ctrl_is_available(sim) || !srv_nw_usab_is_usable(sim))
    {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_AVAILABLE, sim, MMI_FALSE, 2);
            return MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_AVAILABLE, sim, MMI_TRUE, 1);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_valid_sim
 * DESCRIPTION
 *  to check if sim is available
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if sim is valid
 *****************************************************************************/
MMI_BOOL srv_ss_is_valid_sim(mmi_sim_enum sim)
{
	if ((sim == MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
		|| (sim == MMI_SIM2)
#if (MMI_MAX_SIM_NUM >= 3)
		|| (sim == MMI_SIM3)
#if (MMI_MAX_SIM_NUM == 4)
		|| (sim == MMI_SIM4)
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
		)
    {
    	return MMI_TRUE;
    }

	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_valid_ss_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim     [IN]    target sim
 *  length  [IN]    string length
 *  str     [IN]    string in UCS2
 * RETURNS
 *  MMI_TRUE if it is valid ss string
 *****************************************************************************/
MMI_BOOL srv_ss_is_valid_ss_string(mmi_sim_enum sim, U8 length, WCHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_ss_is_valid_sim(sim) || !length || !str)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_VALID_SS_STRING, sim, length, str, MMI_FALSE, 1);
        return MMI_FALSE;
    }

    if (srv_ss_check_ucs2(length, str) &&
    #ifdef __MMI_USSD_REPLY_UCS2__
        length > SRV_SS_MAX_UCS2_LENGTH
    #else /* __MMI_USSD_REPLY_UCS2__ */
        MMI_TRUE
    #endif /* __MMI_USSD_REPLY_UCS2__ */
        )
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_VALID_SS_STRING, sim, length, str, MMI_FALSE, 2);
        return MMI_FALSE;
    }

    if (SS_OPERATION == applib_ss_string_parsing_unicode(
                            str, 
                            length, 
                            srv_ss_get_sim_interface(sim), 
                            MMI_FALSE)
        )
    {
        return MMI_TRUE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_SS_IS_VALID_SS_STRING, sim, length, str, MMI_FALSE, 3);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_valid_call_forward_number
 * DESCRIPTION
 *  to check if str is valid call forwarding number
 * PARAMETERS
 *  sim : [IN] target sim
 *  length : [IN] string length
 *  WCHAR : [IN] string
 * RETURNS
 *  MMI_TRUE if it is valid call forwarding number
 *****************************************************************************/
MMI_BOOL srv_ss_is_valid_call_forward_number(mmi_sim_enum sim, U8 length, WCHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR asc_num[SRV_UCM_MAX_NUM_URI_LEN];
    srv_ucm_call_type_enum call_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!length || !str || !srv_ss_is_valid_sim(sim))
    {
        return MMI_FALSE;
    }

    if (str[0] == L'+' &&
        length > SRV_SS_MAX_FWD_ADDR_LEN)
    {
        return MMI_FALSE;
    }
    else if (str[0] != L'+' &&
        length > (SRV_SS_MAX_FWD_ADDR_LEN - 1))
    {
        return MMI_FALSE;
    }

    memset(asc_num, 0, sizeof(asc_num));
    mmi_ucs2_n_to_asc(asc_num, (CHAR*)str, length * ENCODING_LENGTH);
    call_type = srv_ss_get_call_type(sim);

    return srv_ucm_is_valid_number(call_type, (PU8)asc_num);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_check_ucs2
 * DESCRIPTION
 *  to check if sim-related call setting service is available
 * PARAMETERS
 *  length : [IN] string length in character
 *  str : [IN] string
 * RETURNS
 *  MMI_TRUE if UCS2 char exists
 *****************************************************************************/
MMI_BOOL srv_ss_check_ucs2(U8 length, WCHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < length)
    {
        if (UI_TEST_UCS2_CHARACTER((U16)str[count]))
        {
            return MMI_TRUE;
        }
        count++;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_sim_interface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim   [IN]    mmi sim interface
 * RETURNS
 * sim_interface_enum
 *****************************************************************************/
U8 srv_ss_get_sim_interface(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sim)
    {
        case MMI_SIM1:
            return SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return SIM3;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return SIM4;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            return 0xff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim   [IN]    sim id
 * RETURNS
 * srv_ucm_call_type_enum
 *****************************************************************************/
srv_ucm_call_type_enum srv_ss_get_call_type(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_ucm_call_type_enum call_type[] =
    {
		SRV_UCM_SIM1_CALL_TYPE_ALL,
#if (MMI_MAX_SIM_NUM >= 2)
		SRV_UCM_SIM2_CALL_TYPE_ALL,
#if (MMI_MAX_SIM_NUM >= 3)
		SRV_UCM_SIM3_CALL_TYPE_ALL,
#if (MMI_MAX_SIM_NUM == 4)
		SRV_UCM_SIM4_CALL_TYPE_ALL
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    };
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	return call_type[mmi_frm_sim_to_index(sim)];
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_bs_string
 * DESCRIPTION
 *  to get the SS default basic service string
 * PARAMETERS
 *  bs_code : [IN] basic service code
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_bs_string(srv_ss_bs_code_enum bs_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if (bs_code < SRV_SS_BS_CODE_AUXILIARY_TELEPHONY)
	{
		return (STR_ID_SRV_SS_BS_ALL_TELESERVICES + bs_code);
	}
	
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_result_string
 * DESCRIPTION
 *  to get the SS default result string
 * PARAMETERS
 *  result : [IN] result
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_result_string(srv_ss_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	static const U16 result_string[] = 
    {
    	STR_GLOBAL_DONE,			// SRV_SS_RESULT_OK
		STR_GLOBAL_UNFINISHED,		// SRV_SS_RESULT_INVALID_INPUT
		STR_GLOBAL_BUSY_TRY_LATER,	//SRV_SS_RESULT_BUSY
		STR_ID_SRV_SS_NOT_AVAILABLE,//SRV_SS_RESULT_NOT_AVAILABLE
		STR_GLOBAL_UNFINISHED,		// SRV_SS_RESULT_ABORT
		STR_GLOBAL_INVALID_NUMBER,	// SRV_SS_RESULT_INVALID_NUMBER
		STR_GLOBAL_UNFINISHED,		// SRV_SS_RESULT_CMD_NOT_SUPPORT
		STR_ID_SRV_SS_WRONG_PASSWD, // SRV_SS_RESULT_PASSWD_WRONG
		STR_ID_SRV_SS_BLOCK,		// SRV_SS_RESULT_PASSWD_BLOCK
		STR_GLOBAL_UNFINISHED,		// SRV_SS_RESULT_AUTO_REJECT
		STR_ID_SRV_SS_FDN_FAIL		// SRV_SS_RESULT_FDN_FAIL
    };
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (result <= SRV_SS_RESULT_FDN_FAIL) ? result_string[result] : STR_GLOBAL_UNFINISHED;
}


#ifdef __MMI_SS_SHOW_CAUSE__
/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_cause_string
 * DESCRIPTION
 *  to get the SS error cause string
 * PARAMETERS
 *  cause : [IN] error cause
 *  str : [OUT] result string
 * RETURNS
 *  string ID
 *****************************************************************************/ 
void srv_ss_get_cause_string(srv_ss_ps_cause_enum cause, srv_ss_cause_str_struct *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; g_srv_ss_cause_str[i].cause != (U16)NULL; i++)
    {
        if (cause == g_srv_ss_cause_str[i].cause)
        {
            mmi_asc_n_to_ucs2((CHAR*)str->string, (CHAR*)g_srv_ss_cause_str[i].cause_string, SRV_SS_MAX_CAUSE_LENGTH);
            return;
        }
    }
    mmi_ucs2cpy((CHAR*)str->string, (CHAR*)GetString(STR_GLOBAL_UNFINISHED));
    mmi_ucs2cat((CHAR*)str->string, (CHAR*)L"\n");
    mmi_ucs2cat((CHAR*)str->string, (CHAR*)GetString(STR_ID_SRV_SS_UNKNOWN_CAUSE));
}
#endif /* __MMI_SS_SHOW_CAUSE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_status_string
 * DESCRIPTION
 *  to get the SS default status string
 * PARAMETERS
 *  status : [IN] status
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_status_string(srv_ss_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (status < SRV_SS_STATUS_STATUS_TOTAL) ? (STR_ID_SRV_SS_ACTIVATED + status) : STR_GLOBAL_UNFINISHED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_bs_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_bs_code  [IN] l4_bs_code_enum
 * RETURNS
 *  void
 *****************************************************************************/
srv_ss_bs_code_enum srv_ss_get_bs_code(U8 ps_bs_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	typedef struct
    {
    	U16 key;
		U16 value;
    }srv_ss_map;
	
	static const srv_ss_map bs_table[] = 
	{
		{L4_ALL_TELESERVICES, SRV_SS_BS_CODE_ALL_TELESERVICES},
		{L4_TELEPHONY, SRV_SS_BS_CODE_TELEPHONY},
		{L4_ALL_DATA_TELESERVICES, SRV_SS_BS_CODE_ALL_DATA_TELESERVICES},
		{L4_FACSIMILE_SERVICES, SRV_SS_BS_CODE_FACSIMILE_SERVICES},
		{L4_SHORT_MESSAGE_SERVICES, SRV_SS_BS_CODE_SHORT_MESSAGE_SERVICES},
		{L4_ALL_TELESERVICES_EXCEPT_SMS, SRV_SS_BS_CODE_ALL_TELESERVICES_EXCEPT_SMS},
		{L4_VOICE_GROUP_CALL_SERVICE, SRV_SS_BS_CODE_VOICE_GROUP_CALL_SERVICE},
		{L4_VOICE_BROADCAST_SERVICE, SRV_SS_BS_CODE_VOICE_BROADCAST_SERVICE},
		{L4_ALL_BEARER_SERVICES, SRV_SS_BS_CODE_ALL_BEARER_SERVICES},
		{L4_ALL_ASYNC_SERVICES, SRV_SS_BS_CODE_ALL_ASYNC_SERVICES},
		{L4_ALL_SYNC_SERVICES, SRV_SS_BS_CODE_ALL_SYNC_SERVICES},
		{L4_ALL_DATA_CIRCUIT_SYNC, SRV_SS_BS_CODE_ALL_DATA_CIRCUIT_SYNC},
		{L4_ALL_DATA_CIRCUIT_ASYNC, SRV_SS_BS_CODE_ALL_DATA_CIRCUIT_ASYNC},
		{L4_ALL_GPRS_BEARER_SERVICES, SRV_SS_BS_CODE_ALL_GPRS_BEARER_SERVICES},
		{L4_BS_ALLPADACCESSCA_SERVICES, SRV_SS_BS_CODE_ALLPADACCESSCA_SERVICES},
		{L4_BS_ALLDATAPDS_SERVICES, SRV_SS_BS_CODE_ALLDATAPDS_SERVICES},
		{L4_AUXILIARY_TELEPHONY, SRV_SS_BS_CODE_AUXILIARY_TELEPHONY}
	}; 
	
	U32 i, size = sizeof(bs_table) / sizeof(srv_ss_map);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	for (i = 0; i < size; i++)
	{
		if (ps_bs_code == bs_table[i].key)
		{
			return (srv_ss_bs_code_enum)bs_table[i].value;
		}
	}
	
    return SRV_SS_BS_CODE_TOTAL;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_forward_type_string
 * DESCRIPTION
 *  to get the call forward type string
 * PARAMETERS
 *  type : [IN] call bar type
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_call_forward_type_string(srv_ss_call_forward_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (type <= SRV_SS_CALL_FORWARD_TYPE_UNKNOWN) ? (STR_ID_SRV_SS_CFU + type) : STR_ID_SRV_SS_CF_UNKNOWN; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_bar_type_string
 * DESCRIPTION
 *  to get the call barring type string
 * PARAMETERS
 *  type : [IN] call bar type
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_call_bar_type_string(srv_ss_call_bar_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (type <= SRV_SS_CALL_BAR_TYPE_UNKNOWN) ? (STR_ID_SRV_SS_BAOC + type) : STR_ID_SRV_SS_CB_UNKNOWN;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_wait_string
 * DESCRIPTION
 *  to get the call waiting string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_call_wait_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return STR_ID_SRV_SS_CW;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_id_type_string
 * DESCRIPTION
 *  to get the call identification type string
 * PARAMETERS
 *  type : [IN] call id type
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_call_id_type_string(srv_ss_call_id_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (type < SRV_SS_CALL_ID_TYPE_TOTAL) ? (STR_ID_SRV_SS_CLIP + type) : 0;   
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_cnap_string
 * DESCRIPTION
 *  to get the cnap string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_cnap_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return STR_ID_SRV_SS_CNAP;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_ccbs_string
 * DESCRIPTION
 *  to get the ccbs string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_ccbs_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return STR_ID_SRV_SS_CCBS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_emlpp_string
 * DESCRIPTION
 *  to get the emlpp string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
U16 srv_ss_get_emlpp_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return STR_ID_SRV_SS_EMLPP;
}


/*****************************************************************************
 * FUNCTION
 *  AppendBScodeString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_dir  [IN] direction, l4c_ss_direction_enum
 * RETURNS
 *  void
 *****************************************************************************/
srv_ss_direction_enum srv_ss_get_direction(U8 ps_dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (srv_ss_direction_enum)((ps_dir < SRV_SS_DIR_NONE) ? (SRV_SS_DIR_MO + ps_dir) : SRV_SS_DIR_NONE);    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_cf_type  [IN]    call forward type, l4_ss_code_enum
 * RETURNS
 *  
 *****************************************************************************/
srv_ss_call_forward_type_enum srv_ss_get_cf_type(U8 ps_cf_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (srv_ss_call_forward_type_enum)((ps_cf_type <= L4_CFC) ? (SRV_SS_CALL_FORWARD_CFU + (ps_cf_type - L4_CFU)) : SRV_SS_CALL_FORWARD_TYPE_UNKNOWN);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ps_cb_type  [IN]    call bar type, l4_ss_code_enum
 * RETURNS
 *  
 *****************************************************************************/
srv_ss_call_bar_type_enum srv_ss_get_cb_type(U8 ps_cb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (srv_ss_call_bar_type_enum)((ps_cb_type <= L4_BIC) ? (SRV_SS_CALL_BAR_BAOC + (ps_cb_type - L4_BAOC)) : SRV_SS_CALL_BAR_TYPE_UNKNOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_check_capability
 * DESCRIPTION
 *  check ss capability
 * PARAMETERS
 *  sim : [IN]    target sim
 *  op : [IN] operation
 *  type : [IN] ss type
 *  call_type : [IN] call type
 * RETURNS
 *  MMI_TRUE if SIM supports the SS
 *****************************************************************************/
MMI_BOOL srv_ss_check_capability(mmi_sim_enum sim, srv_ss_act_enum op, U8 type, srv_ss_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op)
    {
        case SRV_SS_ACT_CALL_FORWARD:
            return srv_ss_support_cf(sim, (srv_ss_call_forward_type_enum)type, call_type);

        case SRV_SS_ACT_CALL_BAR:
            return srv_ss_support_cb(sim, (srv_ss_call_bar_type_enum)type, call_type);

        case SRV_SS_ACT_CALL_WAIT:
            return srv_ss_support_cw(sim);

        case SRV_SS_ACT_CALL_IDENTIFICATION:
            return srv_ss_support_cid(sim);

        default:
            return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_support_cf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void*
 *****************************************************************************/
MMI_BOOL srv_ss_support_cf(mmi_sim_enum sim, srv_ss_call_forward_type_enum type, srv_ss_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((call_type == SRV_SS_DATA_CALL) &&
        !srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_DATA, sim))
    {
        return MMI_FALSE;
    }

    switch (type)
    {
        case SRV_SS_CALL_FORWARD_CFU:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFU, sim);
            break;

        case SRV_SS_CALL_FORWARD_CFB:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFB, sim);
            break;

        case SRV_SS_CALL_FORWARD_CFNRY:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFNRY, sim);
            break;

        case SRV_SS_CALL_FORWARD_CFNRC:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFNRC, sim);
            break;

        case SRV_SS_CALL_FORWARD_CFALL:
            res = (MMI_BOOL)(srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFU, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFB, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFNRY, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFNRC, sim));
            break;


        case SRV_SS_CALL_FORWARD_CFALLCONDITIONAL:
            res = (MMI_BOOL)(srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFB, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFNRY, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_OFFERING, SRV_CPHS_SERVICE_CFNRC, sim));
            break;

        default:
            res = MMI_FALSE;
            break;

    }

    return res;
}



/*****************************************************************************
 * FUNCTION
 *  srv_ss_support_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void*
 *****************************************************************************/
MMI_BOOL srv_ss_support_cb(mmi_sim_enum sim, srv_ss_call_bar_type_enum type, srv_ss_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (type)
    {
        case SRV_SS_CALL_BAR_BAOC:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOAC, sim);
            break;

        case SRV_SS_CALL_BAR_BOIC:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOIC, sim);
            break;

        case SRV_SS_CALL_BAR_BOICEXHC:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOIC_EXHC, sim);
            break;

        case SRV_SS_CALL_BAR_BAIC:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BAIC, sim);
            break;

        case SRV_SS_CALL_BAR_BAICROAM:
            res = srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BIC_ROAM, sim);
            break;

        case SRV_SS_CALL_BAR_BAC:
            res = (MMI_BOOL)(srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOAC, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOIC, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOIC_EXHC, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BAIC, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BIC_ROAM, sim));
            break;

        case SRV_SS_CALL_BAR_BOC:
            res = (MMI_BOOL)(srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOAC, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOIC, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BOIC_EXHC, sim));
            break;

        case SRV_SS_CALL_BAR_BIC:
            res = (MMI_BOOL)(srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BAIC, sim) ||
                    srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_RESTRICTION, SRV_CPHS_SERVICE_BIC_ROAM, sim));
            break;

        default:
            res = MMI_FALSE;
            break;

    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_support_cw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void*
 *****************************************************************************/
MMI_BOOL srv_ss_support_cw(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_cphs_is_service_available(SRV_CPHS_GROUP_CALL_COMPLETION, SRV_CPHS_SERVICE_CW, sim);
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_support_cid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void*
 *****************************************************************************/
MMI_BOOL srv_ss_support_cid(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (MMI_BOOL)(srv_cphs_is_service_available(SRV_CPHS_GROUP_NUMBER_IDENTIFI, SRV_CPHS_SERVICE_CLI_BLOCK, sim) ||
                srv_cphs_is_service_available(SRV_CPHS_GROUP_NUMBER_IDENTIFI, SRV_CPHS_SERVICE_CLI_SEND, sim) ||
                srv_cphs_is_service_available(SRV_CPHS_GROUP_NUMBER_IDENTIFI, SRV_CPHS_SERVICE_COLP, sim) ||
                srv_cphs_is_service_available(SRV_CPHS_GROUP_NUMBER_IDENTIFI, SRV_CPHS_SERVICE_COLR, sim) ||
                srv_cphs_is_service_available(SRV_CPHS_GROUP_NUMBER_IDENTIFI, SRV_CPHS_SERVICE_CLIP, sim));
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_check_call_type
 * DESCRIPTION
 *  to check if the basic service code includes the target call type
 * PARAMETERS
 *  bs : [IN] basic service code
 *  call_type : [IN] call type
 * RETURNS
 *  MMI_TRUE if the bs code includes the call type
 *            ex. 20 (all data) includes video call
 *            ex. 24 (sync data) also includes video call
 *****************************************************************************/
MMI_BOOL srv_ss_check_call_type(mmi_sim_enum sim, srv_ss_bs_code_enum bs, srv_ss_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (call_type)
    {
        case SRV_SS_VOICE_CALL:
        {
            if (srv_callset_line_switch_get_id(sim) == SRV_CALLSET_LINE2)
            {
                if (bs == SRV_SS_BS_CODE_AUXILIARY_TELEPHONY)
                {
                    return MMI_TRUE;
                }
                else
                {
                    return MMI_FALSE;
                }
            }
            else
            {
                if (bs == SRV_SS_BS_CODE_ALL_TELESERVICES ||
                        bs == SRV_SS_BS_CODE_TELEPHONY ||
                        bs == SRV_SS_BS_CODE_ALL_TELESERVICES_EXCEPT_SMS)
                {
                    return MMI_TRUE;
                }
                else
                {
                    return MMI_FALSE;
                }
               
            }
        }

        case SRV_SS_VIDEO_CALL:
        {
            if (bs == SRV_SS_BS_CODE_ALL_BEARER_SERVICES ||
                    bs == SRV_SS_BS_CODE_ALL_SYNC_SERVICES ||
                    bs == SRV_SS_BS_CODE_ALL_DATA_CIRCUIT_SYNC)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }

        case SRV_SS_DATA_CALL:
        {
            if (bs == SRV_SS_BS_CODE_ALL_BEARER_SERVICES ||
                    bs == SRV_SS_BS_CODE_ALL_ASYNC_SERVICES ||
                    bs == SRV_SS_BS_CODE_ALL_DATA_CIRCUIT_ASYNC)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }

        case SRV_SS_ALL_CALL:
        {
            return MMI_TRUE;
        }

        default:
            return MMI_FALSE;
    }
    
}



