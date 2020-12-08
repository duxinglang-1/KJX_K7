#ifndef _RATDM_TRC_GEN_H_
#define _RATDM_TRC_GEN_H_

// RATDM_STATE_CHANGE
#define RATDM_STATE_CHANGE_size "dd"
#define RATDM_STATE_CHANGE RATDM_STATE_CHANGE__enum,RATDM_STATE_CHANGE_size

// RATDM_NSAPI_STATE_CHANGE
#define RATDM_NSAPI_STATE_CHANGE_size "hdd"
#define RATDM_NSAPI_STATE_CHANGE RATDM_NSAPI_STATE_CHANGE__enum,RATDM_NSAPI_STATE_CHANGE_size

// RATDM_NSAPI_QUEUE_SUSPEND
#define RATDM_NSAPI_QUEUE_SUSPEND_size "h"
#define RATDM_NSAPI_QUEUE_SUSPEND RATDM_NSAPI_QUEUE_SUSPEND__enum,RATDM_NSAPI_QUEUE_SUSPEND_size

// RATDM_NSAPI_QUEUE_RESUME
#define RATDM_NSAPI_QUEUE_RESUME_size "h"
#define RATDM_NSAPI_QUEUE_RESUME RATDM_NSAPI_QUEUE_RESUME__enum,RATDM_NSAPI_QUEUE_RESUME_size

// RATDM_NSAPI_ALL_STATE_TRACE
#define RATDM_NSAPI_ALL_STATE_TRACE_size "hddh"
#define RATDM_NSAPI_ALL_STATE_TRACE RATDM_NSAPI_ALL_STATE_TRACE__enum,RATDM_NSAPI_ALL_STATE_TRACE_size

// RATDM_RAU_STATUS_CHANGE
#define RATDM_RAU_STATUS_CHANGE_size "dd"
#define RATDM_RAU_STATUS_CHANGE RATDM_RAU_STATUS_CHANGE__enum,RATDM_RAU_STATUS_CHANGE_size

// RATDM_QUEUE_STATE_1
#define RATDM_QUEUE_STATE_1_size "hhhh"
#define RATDM_QUEUE_STATE_1 RATDM_QUEUE_STATE_1__enum,RATDM_QUEUE_STATE_1_size

// RATDM_QUEUE_STATE_2
#define RATDM_QUEUE_STATE_2_size "hhhddd"
#define RATDM_QUEUE_STATE_2 RATDM_QUEUE_STATE_2__enum,RATDM_QUEUE_STATE_2_size

// RATDM_SERVICE_REQUEST_TRIGGER_ELEMENT
#define RATDM_SERVICE_REQUEST_TRIGGER_ELEMENT_size "hhhd"
#define RATDM_SERVICE_REQUEST_TRIGGER_ELEMENT RATDM_SERVICE_REQUEST_TRIGGER_ELEMENT__enum,RATDM_SERVICE_REQUEST_TRIGGER_ELEMENT_size

// RATDM_TX_RX_STATE
#define RATDM_TX_RX_STATE_size "hdd"
#define RATDM_TX_RX_STATE RATDM_TX_RX_STATE__enum,RATDM_TX_RX_STATE_size

// RATDM_NSAPI_DURING_RAT_CHANGE
#define RATDM_NSAPI_DURING_RAT_CHANGE_size "hhh"
#define RATDM_NSAPI_DURING_RAT_CHANGE RATDM_NSAPI_DURING_RAT_CHANGE__enum,RATDM_NSAPI_DURING_RAT_CHANGE_size

// RATDM_RX_STATISTICS_CHANGE
#define RATDM_RX_STATISTICS_CHANGE_size "hdd"
#define RATDM_RX_STATISTICS_CHANGE RATDM_RX_STATISTICS_CHANGE__enum,RATDM_RX_STATISTICS_CHANGE_size

// RATDM_POWER_ON_RAT
#define RATDM_POWER_ON_RAT_size "d"
#define RATDM_POWER_ON_RAT RATDM_POWER_ON_RAT__enum,RATDM_POWER_ON_RAT_size

// RATDM_RAT_CHANGE_FROM_3G_TO_2G
#define RATDM_RAT_CHANGE_FROM_3G_TO_2G_size ""
#define RATDM_RAT_CHANGE_FROM_3G_TO_2G RATDM_RAT_CHANGE_FROM_3G_TO_2G__enum,RATDM_RAT_CHANGE_FROM_3G_TO_2G_size

// RATDM_RAT_CHANGE_FROM_2G_TO_3G
#define RATDM_RAT_CHANGE_FROM_2G_TO_3G_size ""
#define RATDM_RAT_CHANGE_FROM_2G_TO_3G RATDM_RAT_CHANGE_FROM_2G_TO_3G__enum,RATDM_RAT_CHANGE_FROM_2G_TO_3G_size

// RATDM_CREATE_NSAPI_CONTEXT
#define RATDM_CREATE_NSAPI_CONTEXT_size "h"
#define RATDM_CREATE_NSAPI_CONTEXT RATDM_CREATE_NSAPI_CONTEXT__enum,RATDM_CREATE_NSAPI_CONTEXT_size

// RATDM_DELETE_NSAPI_CONTEXT
#define RATDM_DELETE_NSAPI_CONTEXT_size "h"
#define RATDM_DELETE_NSAPI_CONTEXT RATDM_DELETE_NSAPI_CONTEXT__enum,RATDM_DELETE_NSAPI_CONTEXT_size

// RATDM_INIT_3G_FLC_PROFILES
#define RATDM_INIT_3G_FLC_PROFILES_size ""
#define RATDM_INIT_3G_FLC_PROFILES RATDM_INIT_3G_FLC_PROFILES__enum,RATDM_INIT_3G_FLC_PROFILES_size

// RATDM_DEINIT_3G_FLC_PROFILES
#define RATDM_DEINIT_3G_FLC_PROFILES_size ""
#define RATDM_DEINIT_3G_FLC_PROFILES RATDM_DEINIT_3G_FLC_PROFILES__enum,RATDM_DEINIT_3G_FLC_PROFILES_size

// RATDM_INIT_2G_FLC_PROFILES
#define RATDM_INIT_2G_FLC_PROFILES_size ""
#define RATDM_INIT_2G_FLC_PROFILES RATDM_INIT_2G_FLC_PROFILES__enum,RATDM_INIT_2G_FLC_PROFILES_size

// RATDM_DEINIT_2G_FLC_PROFILES
#define RATDM_DEINIT_2G_FLC_PROFILES_size ""
#define RATDM_DEINIT_2G_FLC_PROFILES RATDM_DEINIT_2G_FLC_PROFILES__enum,RATDM_DEINIT_2G_FLC_PROFILES_size

// RATDM_SHRINK_FLC_NPDU_POOL
#define RATDM_SHRINK_FLC_NPDU_POOL_size "hh"
#define RATDM_SHRINK_FLC_NPDU_POOL RATDM_SHRINK_FLC_NPDU_POOL__enum,RATDM_SHRINK_FLC_NPDU_POOL_size

// RATDM_SERVICE_REQ_TIMER_EXPIRY
#define RATDM_SERVICE_REQ_TIMER_EXPIRY_size ""
#define RATDM_SERVICE_REQ_TIMER_EXPIRY RATDM_SERVICE_REQ_TIMER_EXPIRY__enum,RATDM_SERVICE_REQ_TIMER_EXPIRY_size

// RATDM_START_TIMER_FOR_SERVICE_REQ
#define RATDM_START_TIMER_FOR_SERVICE_REQ_size "dh"
#define RATDM_START_TIMER_FOR_SERVICE_REQ RATDM_START_TIMER_FOR_SERVICE_REQ__enum,RATDM_START_TIMER_FOR_SERVICE_REQ_size

// RATDM_WAIT_FOR_RAU_RESULT
#define RATDM_WAIT_FOR_RAU_RESULT_size "d"
#define RATDM_WAIT_FOR_RAU_RESULT RATDM_WAIT_FOR_RAU_RESULT__enum,RATDM_WAIT_FOR_RAU_RESULT_size

// RATDM_NOT_PROCESS_QUEUE_WRONG_RATDM_STATE
#define RATDM_NOT_PROCESS_QUEUE_WRONG_RATDM_STATE_size "d"
#define RATDM_NOT_PROCESS_QUEUE_WRONG_RATDM_STATE RATDM_NOT_PROCESS_QUEUE_WRONG_RATDM_STATE__enum,RATDM_NOT_PROCESS_QUEUE_WRONG_RATDM_STATE_size

// RATDM_NOT_PROCESS_QUEUE_WRONG_RAU_STATUS
#define RATDM_NOT_PROCESS_QUEUE_WRONG_RAU_STATUS_size "d"
#define RATDM_NOT_PROCESS_QUEUE_WRONG_RAU_STATUS RATDM_NOT_PROCESS_QUEUE_WRONG_RAU_STATUS__enum,RATDM_NOT_PROCESS_QUEUE_WRONG_RAU_STATUS_size

// RATDM_SET_SERVICE_REQUEST_TRIGGER_BY_UL_DATA
#define RATDM_SET_SERVICE_REQUEST_TRIGGER_BY_UL_DATA_size "hdd"
#define RATDM_SET_SERVICE_REQUEST_TRIGGER_BY_UL_DATA RATDM_SET_SERVICE_REQUEST_TRIGGER_BY_UL_DATA__enum,RATDM_SET_SERVICE_REQUEST_TRIGGER_BY_UL_DATA_size

// RATDM_NOT_TRIGGER_SERVICE_REQUEST_UL_DATA_DUE_TO_NSAPI_STATE
#define RATDM_NOT_TRIGGER_SERVICE_REQUEST_UL_DATA_DUE_TO_NSAPI_STATE_size "hd"
#define RATDM_NOT_TRIGGER_SERVICE_REQUEST_UL_DATA_DUE_TO_NSAPI_STATE RATDM_NOT_TRIGGER_SERVICE_REQUEST_UL_DATA_DUE_TO_NSAPI_STATE__enum,RATDM_NOT_TRIGGER_SERVICE_REQUEST_UL_DATA_DUE_TO_NSAPI_STATE_size

// RATDM_RECEIVE_UL_DATA_WHEN_RAU_STATUS_IS
#define RATDM_RECEIVE_UL_DATA_WHEN_RAU_STATUS_IS_size "d"
#define RATDM_RECEIVE_UL_DATA_WHEN_RAU_STATUS_IS RATDM_RECEIVE_UL_DATA_WHEN_RAU_STATUS_IS__enum,RATDM_RECEIVE_UL_DATA_WHEN_RAU_STATUS_IS_size

// RATDM_PRINT_SERVICE_REQUEST_TRIGGERS
#define RATDM_PRINT_SERVICE_REQUEST_TRIGGERS_size "dhd"
#define RATDM_PRINT_SERVICE_REQUEST_TRIGGERS RATDM_PRINT_SERVICE_REQUEST_TRIGGERS__enum,RATDM_PRINT_SERVICE_REQUEST_TRIGGERS_size

// RATDM_SR_INTER_RAT_CANCELLED_SINCE_INTER_RAT_FINISHED
#define RATDM_SR_INTER_RAT_CANCELLED_SINCE_INTER_RAT_FINISHED_size ""
#define RATDM_SR_INTER_RAT_CANCELLED_SINCE_INTER_RAT_FINISHED RATDM_SR_INTER_RAT_CANCELLED_SINCE_INTER_RAT_FINISHED__enum,RATDM_SR_INTER_RAT_CANCELLED_SINCE_INTER_RAT_FINISHED_size

// RATDM_PROCESS_SERVICE_REQUEST_TRIGGER
#define RATDM_PROCESS_SERVICE_REQUEST_TRIGGER_size "d"
#define RATDM_PROCESS_SERVICE_REQUEST_TRIGGER RATDM_PROCESS_SERVICE_REQUEST_TRIGGER__enum,RATDM_PROCESS_SERVICE_REQUEST_TRIGGER_size

// RATDM_INSERT_SERVICE_REQUEST_TRIGGER
#define RATDM_INSERT_SERVICE_REQUEST_TRIGGER_size "d"
#define RATDM_INSERT_SERVICE_REQUEST_TRIGGER RATDM_INSERT_SERVICE_REQUEST_TRIGGER__enum,RATDM_INSERT_SERVICE_REQUEST_TRIGGER_size

// RATDM_MORE_THAN_ONE_SERVICE_REQUEST_TRIGGER
#define RATDM_MORE_THAN_ONE_SERVICE_REQUEST_TRIGGER_size "d"
#define RATDM_MORE_THAN_ONE_SERVICE_REQUEST_TRIGGER RATDM_MORE_THAN_ONE_SERVICE_REQUEST_TRIGGER__enum,RATDM_MORE_THAN_ONE_SERVICE_REQUEST_TRIGGER_size

// RATDM_DELETE_SERVICE_REQUEST_TRIGGER
#define RATDM_DELETE_SERVICE_REQUEST_TRIGGER_size "dhd"
#define RATDM_DELETE_SERVICE_REQUEST_TRIGGER RATDM_DELETE_SERVICE_REQUEST_TRIGGER__enum,RATDM_DELETE_SERVICE_REQUEST_TRIGGER_size

// RATDM_ABORT_SERVICE_REQUEST_PROCEDURE
#define RATDM_ABORT_SERVICE_REQUEST_PROCEDURE_size ""
#define RATDM_ABORT_SERVICE_REQUEST_PROCEDURE RATDM_ABORT_SERVICE_REQUEST_PROCEDURE__enum,RATDM_ABORT_SERVICE_REQUEST_PROCEDURE_size

// RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_IMMEDIATELY
#define RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_IMMEDIATELY_size ""
#define RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_IMMEDIATELY RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_IMMEDIATELY__enum,RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_IMMEDIATELY_size

// RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_AFTER_TIMER_EXPIRY
#define RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_AFTER_TIMER_EXPIRY_size ""
#define RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_AFTER_TIMER_EXPIRY RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_AFTER_TIMER_EXPIRY__enum,RATDM_RETRY_SERVICE_REQUEST_PROCEDURE_AFTER_TIMER_EXPIRY_size

// RATDM_SERVICE_REQUEST_FOR_RAB_REEST_FAIL_BUT_CURRENT_RAT_GSM
#define RATDM_SERVICE_REQUEST_FOR_RAB_REEST_FAIL_BUT_CURRENT_RAT_GSM_size ""
#define RATDM_SERVICE_REQUEST_FOR_RAB_REEST_FAIL_BUT_CURRENT_RAT_GSM RATDM_SERVICE_REQUEST_FOR_RAB_REEST_FAIL_BUT_CURRENT_RAT_GSM__enum,RATDM_SERVICE_REQUEST_FOR_RAB_REEST_FAIL_BUT_CURRENT_RAT_GSM_size

// RATDM_IGNORE_SELECTIVE_RAU_FAILURE_SINCE_WCDMA
#define RATDM_IGNORE_SELECTIVE_RAU_FAILURE_SINCE_WCDMA_size ""
#define RATDM_IGNORE_SELECTIVE_RAU_FAILURE_SINCE_WCDMA RATDM_IGNORE_SELECTIVE_RAU_FAILURE_SINCE_WCDMA__enum,RATDM_IGNORE_SELECTIVE_RAU_FAILURE_SINCE_WCDMA_size

// RATDM_WCDMA_TO_GSM_CHECK_FAIL_DUE_TO_RAU_STATUS
#define RATDM_WCDMA_TO_GSM_CHECK_FAIL_DUE_TO_RAU_STATUS_size "d"
#define RATDM_WCDMA_TO_GSM_CHECK_FAIL_DUE_TO_RAU_STATUS RATDM_WCDMA_TO_GSM_CHECK_FAIL_DUE_TO_RAU_STATUS__enum,RATDM_WCDMA_TO_GSM_CHECK_FAIL_DUE_TO_RAU_STATUS_size

// RATDM_GSM_TO_WCDMA_CHECK_FAIL_DUE_TO_RAU_STATUS
#define RATDM_GSM_TO_WCDMA_CHECK_FAIL_DUE_TO_RAU_STATUS_size "d"
#define RATDM_GSM_TO_WCDMA_CHECK_FAIL_DUE_TO_RAU_STATUS RATDM_GSM_TO_WCDMA_CHECK_FAIL_DUE_TO_RAU_STATUS__enum,RATDM_GSM_TO_WCDMA_CHECK_FAIL_DUE_TO_RAU_STATUS_size

// RATDM_MOVE_LAST_TX_SN_AS_SNDCP_REQUESTED
#define RATDM_MOVE_LAST_TX_SN_AS_SNDCP_REQUESTED_size "hhh"
#define RATDM_MOVE_LAST_TX_SN_AS_SNDCP_REQUESTED RATDM_MOVE_LAST_TX_SN_AS_SNDCP_REQUESTED__enum,RATDM_MOVE_LAST_TX_SN_AS_SNDCP_REQUESTED_size

// RATDM_SERVICE_REQUEST_ENCOUNTER_T3319_RUNNING
#define RATDM_SERVICE_REQUEST_ENCOUNTER_T3319_RUNNING_size ""
#define RATDM_SERVICE_REQUEST_ENCOUNTER_T3319_RUNNING RATDM_SERVICE_REQUEST_ENCOUNTER_T3319_RUNNING__enum,RATDM_SERVICE_REQUEST_ENCOUNTER_T3319_RUNNING_size

// RATDM_SERVICE_ACCEPT_START_T3319
#define RATDM_SERVICE_ACCEPT_START_T3319_size ""
#define RATDM_SERVICE_ACCEPT_START_T3319 RATDM_SERVICE_ACCEPT_START_T3319__enum,RATDM_SERVICE_ACCEPT_START_T3319_size

// RATDM_SERVICE_REQUEST_T3319_TIMEOUT
#define RATDM_SERVICE_REQUEST_T3319_TIMEOUT_size ""
#define RATDM_SERVICE_REQUEST_T3319_TIMEOUT RATDM_SERVICE_REQUEST_T3319_TIMEOUT__enum,RATDM_SERVICE_REQUEST_T3319_TIMEOUT_size

// RATDM_AT_LEAST_ONE_SERVICE_REQUEST_TRIGGER_T3319_IS_RUNNING
#define RATDM_AT_LEAST_ONE_SERVICE_REQUEST_TRIGGER_T3319_IS_RUNNING_size "h"
#define RATDM_AT_LEAST_ONE_SERVICE_REQUEST_TRIGGER_T3319_IS_RUNNING RATDM_AT_LEAST_ONE_SERVICE_REQUEST_TRIGGER_T3319_IS_RUNNING__enum,RATDM_AT_LEAST_ONE_SERVICE_REQUEST_TRIGGER_T3319_IS_RUNNING_size

// RATDM_PROCESS_PENDING_ACTION_FUNC
#define RATDM_PROCESS_PENDING_ACTION_FUNC_size ""
#define RATDM_PROCESS_PENDING_ACTION_FUNC RATDM_PROCESS_PENDING_ACTION_FUNC__enum,RATDM_PROCESS_PENDING_ACTION_FUNC_size

// RATDM_IS_PS_DATA_PENDING
#define RATDM_IS_PS_DATA_PENDING_size "d"
#define RATDM_IS_PS_DATA_PENDING RATDM_IS_PS_DATA_PENDING__enum,RATDM_IS_PS_DATA_PENDING_size

// RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_ENTRY
#define RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_ENTRY_size "hd"
#define RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_ENTRY RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_ENTRY__enum,RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_ENTRY_size

// RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_FAIL
#define RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_FAIL_size ""
#define RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_FAIL RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_FAIL__enum,RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_FAIL_size

// RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_TRUE
#define RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_TRUE_size ""
#define RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_TRUE RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_TRUE__enum,RATDM_CHECK_NEED_TO_TRIGGER_SR_AGAIN_RETURN_TRUE_size

// RATDM_FIND_SR_REQ_IN_SR_GUARD_PERIOD
#define RATDM_FIND_SR_REQ_IN_SR_GUARD_PERIOD_size ""
#define RATDM_FIND_SR_REQ_IN_SR_GUARD_PERIOD RATDM_FIND_SR_REQ_IN_SR_GUARD_PERIOD__enum,RATDM_FIND_SR_REQ_IN_SR_GUARD_PERIOD_size

// RATDM_FIND_SR_REQ_NOT_IN_SR_GUARD_PERIOD
#define RATDM_FIND_SR_REQ_NOT_IN_SR_GUARD_PERIOD_size ""
#define RATDM_FIND_SR_REQ_NOT_IN_SR_GUARD_PERIOD RATDM_FIND_SR_REQ_NOT_IN_SR_GUARD_PERIOD__enum,RATDM_FIND_SR_REQ_NOT_IN_SR_GUARD_PERIOD_size

// RATDM_FIND_SR_REQ_ENTRY
#define RATDM_FIND_SR_REQ_ENTRY_size "hd"
#define RATDM_FIND_SR_REQ_ENTRY RATDM_FIND_SR_REQ_ENTRY__enum,RATDM_FIND_SR_REQ_ENTRY_size

// RATDM_FIND_SR_REQ_RETURN_TRUE
#define RATDM_FIND_SR_REQ_RETURN_TRUE_size ""
#define RATDM_FIND_SR_REQ_RETURN_TRUE RATDM_FIND_SR_REQ_RETURN_TRUE__enum,RATDM_FIND_SR_REQ_RETURN_TRUE_size

// RATDM_FIND_SR_REQ_RETURN_FALSE
#define RATDM_FIND_SR_REQ_RETURN_FALSE_size ""
#define RATDM_FIND_SR_REQ_RETURN_FALSE RATDM_FIND_SR_REQ_RETURN_FALSE__enum,RATDM_FIND_SR_REQ_RETURN_FALSE_size

// RATDM_CHECK_NEED_INTER_RAT_SR_REQ_ENTRY
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_ENTRY_size ""
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_ENTRY RATDM_CHECK_NEED_INTER_RAT_SR_REQ_ENTRY__enum,RATDM_CHECK_NEED_INTER_RAT_SR_REQ_ENTRY_size

// RATDM_CHECK_NEED_INTER_RAT_SR_REQ_PRINT_STATE
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_PRINT_STATE_size "hddd"
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_PRINT_STATE RATDM_CHECK_NEED_INTER_RAT_SR_REQ_PRINT_STATE__enum,RATDM_CHECK_NEED_INTER_RAT_SR_REQ_PRINT_STATE_size

// RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_TRUE
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_TRUE_size ""
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_TRUE RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_TRUE__enum,RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_TRUE_size

// RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_FALSE
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_FALSE_size ""
#define RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_FALSE RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_FALSE__enum,RATDM_CHECK_NEED_INTER_RAT_SR_REQ_RETURN_FALSE_size

// RATDM_PROCESS_NPDU_QUEUE_FUNC
#define RATDM_PROCESS_NPDU_QUEUE_FUNC_size "dhhhh"
#define RATDM_PROCESS_NPDU_QUEUE_FUNC RATDM_PROCESS_NPDU_QUEUE_FUNC__enum,RATDM_PROCESS_NPDU_QUEUE_FUNC_size

// RATDM_PROCESS_NPDU_QUEUE_TAG
#define RATDM_PROCESS_NPDU_QUEUE_TAG_size "dhhh"
#define RATDM_PROCESS_NPDU_QUEUE_TAG RATDM_PROCESS_NPDU_QUEUE_TAG__enum,RATDM_PROCESS_NPDU_QUEUE_TAG_size

// RATDM_BYPASS_NPDU
#define RATDM_BYPASS_NPDU_size "dhhhh"
#define RATDM_BYPASS_NPDU RATDM_BYPASS_NPDU__enum,RATDM_BYPASS_NPDU_size

// RATDM_BYPASS_MULTI_NPDU
#define RATDM_BYPASS_MULTI_NPDU_size "h"
#define RATDM_BYPASS_MULTI_NPDU RATDM_BYPASS_MULTI_NPDU__enum,RATDM_BYPASS_MULTI_NPDU_size

// RATDM_ACK_NPDU_QUEUE
#define RATDM_ACK_NPDU_QUEUE_size "hh"
#define RATDM_ACK_NPDU_QUEUE RATDM_ACK_NPDU_QUEUE__enum,RATDM_ACK_NPDU_QUEUE_size

// RATDM_TCP_PKT_SEND
#define RATDM_TCP_PKT_SEND_size "d"
#define RATDM_TCP_PKT_SEND RATDM_TCP_PKT_SEND__enum,RATDM_TCP_PKT_SEND_size

// RATDM_TCP_PKT_RECEIVE
#define RATDM_TCP_PKT_RECEIVE_size "d"
#define RATDM_TCP_PKT_RECEIVE RATDM_TCP_PKT_RECEIVE__enum,RATDM_TCP_PKT_RECEIVE_size

// RATDM_NON_TCP_PKT_SEND
#define RATDM_NON_TCP_PKT_SEND_size "d"
#define RATDM_NON_TCP_PKT_SEND RATDM_NON_TCP_PKT_SEND__enum,RATDM_NON_TCP_PKT_SEND_size

// RATDM_NON_TCP_PKT_RECEIVE
#define RATDM_NON_TCP_PKT_RECEIVE_size "d"
#define RATDM_NON_TCP_PKT_RECEIVE RATDM_NON_TCP_PKT_RECEIVE__enum,RATDM_NON_TCP_PKT_RECEIVE_size

// RATDM_NW_ACK_NPDU_NOT_PERFORMED
#define RATDM_NW_ACK_NPDU_NOT_PERFORMED_size "hhh"
#define RATDM_NW_ACK_NPDU_NOT_PERFORMED RATDM_NW_ACK_NPDU_NOT_PERFORMED__enum,RATDM_NW_ACK_NPDU_NOT_PERFORMED_size

// RATDM_TCM_DATA_REQ_QUEUE_STATUS
#define RATDM_TCM_DATA_REQ_QUEUE_STATUS_size "h"
#define RATDM_TCM_DATA_REQ_QUEUE_STATUS RATDM_TCM_DATA_REQ_QUEUE_STATUS__enum,RATDM_TCM_DATA_REQ_QUEUE_STATUS_size

// RATDM_DATA_CNF_QUEUE_STATUS
#define RATDM_DATA_CNF_QUEUE_STATUS_size "hh"
#define RATDM_DATA_CNF_QUEUE_STATUS RATDM_DATA_CNF_QUEUE_STATUS__enum,RATDM_DATA_CNF_QUEUE_STATUS_size

// RATDM_PS_STATISTICS_RESET
#define RATDM_PS_STATISTICS_RESET_size "ddd"
#define RATDM_PS_STATISTICS_RESET RATDM_PS_STATISTICS_RESET__enum,RATDM_PS_STATISTICS_RESET_size

// RATDM_PREVIOUS_RAU_IS_ABORTED
#define RATDM_PREVIOUS_RAU_IS_ABORTED_size ""
#define RATDM_PREVIOUS_RAU_IS_ABORTED RATDM_PREVIOUS_RAU_IS_ABORTED__enum,RATDM_PREVIOUS_RAU_IS_ABORTED_size

// RATDM_PDCP_V_A_NOT_SYNC
#define RATDM_PDCP_V_A_NOT_SYNC_size "hh"
#define RATDM_PDCP_V_A_NOT_SYNC RATDM_PDCP_V_A_NOT_SYNC__enum,RATDM_PDCP_V_A_NOT_SYNC_size

// RATDM_RETRANSMIT_ON_GOING
#define RATDM_RETRANSMIT_ON_GOING_size ""
#define RATDM_RETRANSMIT_ON_GOING RATDM_RETRANSMIT_ON_GOING__enum,RATDM_RETRANSMIT_ON_GOING_size

// RATDM_PROCESS_QUEUE_BUT_SUSPENDED
#define RATDM_PROCESS_QUEUE_BUT_SUSPENDED_size "h"
#define RATDM_PROCESS_QUEUE_BUT_SUSPENDED RATDM_PROCESS_QUEUE_BUT_SUSPENDED__enum,RATDM_PROCESS_QUEUE_BUT_SUSPENDED_size

// RATDM_PROCESS_QUEUE_BUT_EMPTY
#define RATDM_PROCESS_QUEUE_BUT_EMPTY_size "h"
#define RATDM_PROCESS_QUEUE_BUT_EMPTY RATDM_PROCESS_QUEUE_BUT_EMPTY__enum,RATDM_PROCESS_QUEUE_BUT_EMPTY_size

// RATDM_RETRANSMIT_QUEUE_BUT_SUSPENDED
#define RATDM_RETRANSMIT_QUEUE_BUT_SUSPENDED_size "h"
#define RATDM_RETRANSMIT_QUEUE_BUT_SUSPENDED RATDM_RETRANSMIT_QUEUE_BUT_SUSPENDED__enum,RATDM_RETRANSMIT_QUEUE_BUT_SUSPENDED_size

// RATDM_RETRANSMIT_QUEUE_BUT_EMPTY
#define RATDM_RETRANSMIT_QUEUE_BUT_EMPTY_size "h"
#define RATDM_RETRANSMIT_QUEUE_BUT_EMPTY RATDM_RETRANSMIT_QUEUE_BUT_EMPTY__enum,RATDM_RETRANSMIT_QUEUE_BUT_EMPTY_size

// RATDM_PROC_NPDUQ_RETRANSMIT_NPDU_NOT_EXIST
#define RATDM_PROC_NPDUQ_RETRANSMIT_NPDU_NOT_EXIST_size "h"
#define RATDM_PROC_NPDUQ_RETRANSMIT_NPDU_NOT_EXIST RATDM_PROC_NPDUQ_RETRANSMIT_NPDU_NOT_EXIST__enum,RATDM_PROC_NPDUQ_RETRANSMIT_NPDU_NOT_EXIST_size

// RATDM_NOT_PROCESS_QUEUE_NSAPI_DURING_RAT_CHANGE
#define RATDM_NOT_PROCESS_QUEUE_NSAPI_DURING_RAT_CHANGE_size "d"
#define RATDM_NOT_PROCESS_QUEUE_NSAPI_DURING_RAT_CHANGE RATDM_NOT_PROCESS_QUEUE_NSAPI_DURING_RAT_CHANGE__enum,RATDM_NOT_PROCESS_QUEUE_NSAPI_DURING_RAT_CHANGE_size

// RATDM_NSAPI_CONTEXT_NOT_EXIST_WHEM_SM_ACTIVATE
#define RATDM_NSAPI_CONTEXT_NOT_EXIST_WHEM_SM_ACTIVATE_size "h"
#define RATDM_NSAPI_CONTEXT_NOT_EXIST_WHEM_SM_ACTIVATE RATDM_NSAPI_CONTEXT_NOT_EXIST_WHEM_SM_ACTIVATE__enum,RATDM_NSAPI_CONTEXT_NOT_EXIST_WHEM_SM_ACTIVATE_size

// RATDM_NSAPI_TX_Q_VA_NOT_EQUAL_NW_NEXT_RX_SN
#define RATDM_NSAPI_TX_Q_VA_NOT_EQUAL_NW_NEXT_RX_SN_size "hhh"
#define RATDM_NSAPI_TX_Q_VA_NOT_EQUAL_NW_NEXT_RX_SN RATDM_NSAPI_TX_Q_VA_NOT_EQUAL_NW_NEXT_RX_SN__enum,RATDM_NSAPI_TX_Q_VA_NOT_EQUAL_NW_NEXT_RX_SN_size

// RATDM_PROCESS_TX_QUEUE_TI_NOT_MATCH
#define RATDM_PROCESS_TX_QUEUE_TI_NOT_MATCH_size "hh"
#define RATDM_PROCESS_TX_QUEUE_TI_NOT_MATCH RATDM_PROCESS_TX_QUEUE_TI_NOT_MATCH__enum,RATDM_PROCESS_TX_QUEUE_TI_NOT_MATCH_size

// RATDM_NSAPI_NOT_IN_ACTIVE_STATE_WHEN_PROCESS_QUEUE
#define RATDM_NSAPI_NOT_IN_ACTIVE_STATE_WHEN_PROCESS_QUEUE_size "d"
#define RATDM_NSAPI_NOT_IN_ACTIVE_STATE_WHEN_PROCESS_QUEUE RATDM_NSAPI_NOT_IN_ACTIVE_STATE_WHEN_PROCESS_QUEUE__enum,RATDM_NSAPI_NOT_IN_ACTIVE_STATE_WHEN_PROCESS_QUEUE_size

// RATDM_NSAPI_NOT_CONFIG_DURING_INTER_RAT
#define RATDM_NSAPI_NOT_CONFIG_DURING_INTER_RAT_size "d"
#define RATDM_NSAPI_NOT_CONFIG_DURING_INTER_RAT RATDM_NSAPI_NOT_CONFIG_DURING_INTER_RAT__enum,RATDM_NSAPI_NOT_CONFIG_DURING_INTER_RAT_size

// RATDM_NSAPI_CONTEXT_PTR_CID_IS_NOT_VALID
#define RATDM_NSAPI_CONTEXT_PTR_CID_IS_NOT_VALID_size "d"
#define RATDM_NSAPI_CONTEXT_PTR_CID_IS_NOT_VALID RATDM_NSAPI_CONTEXT_PTR_CID_IS_NOT_VALID__enum,RATDM_NSAPI_CONTEXT_PTR_CID_IS_NOT_VALID_size

// RATDM_INPUT_AN_INVALID_TCM_CID
#define RATDM_INPUT_AN_INVALID_TCM_CID_size "d"
#define RATDM_INPUT_AN_INVALID_TCM_CID RATDM_INPUT_AN_INVALID_TCM_CID__enum,RATDM_INPUT_AN_INVALID_TCM_CID_size

// RATDM_INVALID_NSAPI
#define RATDM_INVALID_NSAPI_size "h"
#define RATDM_INVALID_NSAPI RATDM_INVALID_NSAPI__enum,RATDM_INVALID_NSAPI_size

// RATDM_INVALID_NSAPI_IN_MSG
#define RATDM_INVALID_NSAPI_IN_MSG_size "hd"
#define RATDM_INVALID_NSAPI_IN_MSG RATDM_INVALID_NSAPI_IN_MSG__enum,RATDM_INVALID_NSAPI_IN_MSG_size

// RATDM_INVALID_NSAPI_STATE
#define RATDM_INVALID_NSAPI_STATE_size "hd"
#define RATDM_INVALID_NSAPI_STATE RATDM_INVALID_NSAPI_STATE__enum,RATDM_INVALID_NSAPI_STATE_size

// RATDM_INVALID_NSAPI_RAT_STATE
#define RATDM_INVALID_NSAPI_RAT_STATE_size "hd"
#define RATDM_INVALID_NSAPI_RAT_STATE RATDM_INVALID_NSAPI_RAT_STATE__enum,RATDM_INVALID_NSAPI_RAT_STATE_size

// RATDM_MM_SEQ_REQ_ACK_NPDU_FAIL
#define RATDM_MM_SEQ_REQ_ACK_NPDU_FAIL_size "hhh"
#define RATDM_MM_SEQ_REQ_ACK_NPDU_FAIL RATDM_MM_SEQ_REQ_ACK_NPDU_FAIL__enum,RATDM_MM_SEQ_REQ_ACK_NPDU_FAIL_size

// RATDM_SM_RAB_ACTIVATE_ON_TWO_SIM
#define RATDM_SM_RAB_ACTIVATE_ON_TWO_SIM_size ""
#define RATDM_SM_RAB_ACTIVATE_ON_TWO_SIM RATDM_SM_RAB_ACTIVATE_ON_TWO_SIM__enum,RATDM_SM_RAB_ACTIVATE_ON_TWO_SIM_size

// RATDM_RATCM_REGAIN_COVERAGE_ON_ANOTHER_SIM
#define RATDM_RATCM_REGAIN_COVERAGE_ON_ANOTHER_SIM_size ""
#define RATDM_RATCM_REGAIN_COVERAGE_ON_ANOTHER_SIM RATDM_RATCM_REGAIN_COVERAGE_ON_ANOTHER_SIM__enum,RATDM_RATCM_REGAIN_COVERAGE_ON_ANOTHER_SIM_size

// RATDM_MM_SELECTIVE_RAU_ON_ANOTHRE_SIM
#define RATDM_MM_SELECTIVE_RAU_ON_ANOTHRE_SIM_size ""
#define RATDM_MM_SELECTIVE_RAU_ON_ANOTHRE_SIM RATDM_MM_SELECTIVE_RAU_ON_ANOTHRE_SIM__enum,RATDM_MM_SELECTIVE_RAU_ON_ANOTHRE_SIM_size

// RATDM_MM_SR_PROCEDURE_ON_ANOTHER_SIM
#define RATDM_MM_SR_PROCEDURE_ON_ANOTHER_SIM_size ""
#define RATDM_MM_SR_PROCEDURE_ON_ANOTHER_SIM RATDM_MM_SR_PROCEDURE_ON_ANOTHER_SIM__enum,RATDM_MM_SR_PROCEDURE_ON_ANOTHER_SIM_size

// RATDM_INVALID_CID
#define RATDM_INVALID_CID_size "h"
#define RATDM_INVALID_CID RATDM_INVALID_CID__enum,RATDM_INVALID_CID_size

// RATDM_NSAPI_CONTEXT_NOT_EXIST
#define RATDM_NSAPI_CONTEXT_NOT_EXIST_size "h"
#define RATDM_NSAPI_CONTEXT_NOT_EXIST RATDM_NSAPI_CONTEXT_NOT_EXIST__enum,RATDM_NSAPI_CONTEXT_NOT_EXIST_size

// RATDM_ACK_NUMBER_MAYBE_WRONG
#define RATDM_ACK_NUMBER_MAYBE_WRONG_size "hh"
#define RATDM_ACK_NUMBER_MAYBE_WRONG RATDM_ACK_NUMBER_MAYBE_WRONG__enum,RATDM_ACK_NUMBER_MAYBE_WRONG_size

// RATDM_NO_MORE_PDU_TO_BE_ACK
#define RATDM_NO_MORE_PDU_TO_BE_ACK_size ""
#define RATDM_NO_MORE_PDU_TO_BE_ACK RATDM_NO_MORE_PDU_TO_BE_ACK__enum,RATDM_NO_MORE_PDU_TO_BE_ACK_size

// RATDM_L4C_EXT_PDP_STATISTICS_IND_HDLR
#define RATDM_L4C_EXT_PDP_STATISTICS_IND_HDLR_size "h"
#define RATDM_L4C_EXT_PDP_STATISTICS_IND_HDLR RATDM_L4C_EXT_PDP_STATISTICS_IND_HDLR__enum,RATDM_L4C_EXT_PDP_STATISTICS_IND_HDLR_size

// RATDM_CHECK_NPDU_QUEUE_FLC_GUARD_PATTERN
#define RATDM_CHECK_NPDU_QUEUE_FLC_GUARD_PATTERN_size ""
#define RATDM_CHECK_NPDU_QUEUE_FLC_GUARD_PATTERN RATDM_CHECK_NPDU_QUEUE_FLC_GUARD_PATTERN__enum,RATDM_CHECK_NPDU_QUEUE_FLC_GUARD_PATTERN_size

// RATDM_FLC2_CHECK_PEER_BUFF
#define RATDM_FLC2_CHECK_PEER_BUFF_size "d"
#define RATDM_FLC2_CHECK_PEER_BUFF RATDM_FLC2_CHECK_PEER_BUFF__enum,RATDM_FLC2_CHECK_PEER_BUFF_size

// RATDM_UT_CHECK_SER_REQ_CAUSE
#define RATDM_UT_CHECK_SER_REQ_CAUSE_size "dd"
#define RATDM_UT_CHECK_SER_REQ_CAUSE RATDM_UT_CHECK_SER_REQ_CAUSE__enum,RATDM_UT_CHECK_SER_REQ_CAUSE_size


#endif // RATDM_TRC_GEN.H
