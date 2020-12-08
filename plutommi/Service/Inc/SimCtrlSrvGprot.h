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
 *  SimCtrlSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The API of SIM control service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SIM_CTRL_SRV_GPROT_H__
#define __SIM_CTRL_SRV_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "ps_public_struct.h"
#include "MMI_features.h"
#include "mmi_frm_utility_gprot.h"


/****************************************************************************
 * Constants
 ****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __GSMCDMA_DUALSIM__
#define __INVALID_SIM_RECOVERY__
#endif
/* DOM-NOT_FOR_SDK-END */

/*
 * DESCRIPTION
 *  Number of MCC digits.
 */
#define SRV_MCC_LEN 3

/*
 * DESCRIPTION
 *  Maximum number of MNC digits.
 */
#define SRV_MAX_MNC_LEN 3

/*
 * DESCRIPTION
 *  Maximum length of PLMN numbers.
 *  If you use this value for a PLMN output buffer, please remember to add a character space
 *  for the null terminator. For example:
 *  <code>
 *  CHAR plmn_buffer[SRV_MAX_PLMN_LEN + 1];
 *  srv_sim_ctrl_get_home_plmn(MMI_SIM1, plmn_buffer, sizeof(plmn_buffer));
 *  </code>
 */
#define SRV_MAX_PLMN_LEN 6

/*
 * DESCRIPTION
 *  Maximum length of IMSI numbers.
 *  If you use this value for a IMSI output buffer, please remember to add a character space
 *  for the null terminator. For example:
 *  <code>
 *  CHAR imsi_buffer[SRV_MAX_IMSI_LEN + 1];
 *  srv_sim_ctrl_get_imsi(MMI_SIM1, imsi_buffer, sizeof(imsi_buffer));
 *  </code>
 */
#define SRV_MAX_IMSI_LEN 16

/*
 * DESCRIPTION
 *  Infinite number of remaining attempts.
 */
#define SRV_SIM_CTRL_ATTEMPT_INFINITE_NUMBER 0xffff

/*
 * DESCRIPTION
 *  Minimum length of CHV
 */
#define SRV_SIM_CTRL_MIN_CHV_LEN 4

/*
 * DESCRIPTION
 *  Maximum length of CHV
 */
#define SRV_SIM_CTRL_MAX_CHV_LEN 8

/*
 * DESCRIPTION
 *  Minimum length of UBCHV
 */
#define SRV_SIM_CTRL_MIN_UBCHV_LEN 8

/*
 * DESCRIPTION
 *  Maximum length of UBCHV
 */
#define SRV_SIM_CTRL_MAX_UBCHV_LEN 8

/*
 * DESCRIPTION
 *  Maximum number of EHPLMN entries support
 */
#define SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM 4


/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Possible unavailable causes of SIM.
 * SEE ALSO
 *  srv_sim_ctrl_get_unavailable_cause
 */
typedef enum
{
    /* SIM is available, or not defined cause. */
    SRV_SIM_CTRL_UA_CAUSE_NONE,
    /* SIM module is initializing, the information is not available yet */
    SRV_SIM_CTRL_UA_CAUSE_INITIALIZING,
    /* CHV1 is required */
    SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED,
    /* SIM card is absent */
    SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED,
    /* Fatal error on accessing the SIM */
    SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR,
    /* CHV1(PIN1) is blocked */
    SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED,
    /* UBCHV1(PUK1) is blocked */
    SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED,
    /* Require personalization verification */
    SRV_SIM_CTRL_UA_CAUSE_PERSON_REQUIRED,
    /* Blocked due to personalization verification failed */
    SRV_SIM_CTRL_UA_CAUSE_PERSON_BLOCKED,
    /* BT access profile */
    SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE,
    /* G+C dual SIM disconnected */
    SRV_SIM_CTRL_UA_CAUSE_DISCONNECTED,
    /* SIM recovery */
    SRV_SIM_CTRL_UA_CAUSE_RECOVERY,

    SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM
} srv_sim_ctrl_ua_cause_enum;


/*
 * DESCRIPTION
 *  Information of SIM change.
 */
typedef enum
{
    SRV_SIM_CTRL_CHANGE_CHECK_INVALID,   /* Invalid, maybe SIM is not inserted or blocked */
    SRV_SIM_CTRL_CHANGE_CHECK_UNKNOWN,   /* Unknown; maybe the IMSI is unavailable */
    SRV_SIM_CTRL_CHANGE_CHECK_THE_SAME,  /* The same SIM */
    SRV_SIM_CTRL_CHANGE_CHECK_CHANGED,   /* New SIM */

    SRV_SIM_CTRL_CHANGE_CHECK_END_OF_ENUM
} srv_sim_ctrl_change_check_enum;


/*
 * DESCRIPTION
 *  Password type of SIM.
 */
typedef enum
{
    SRV_SIM_CTRL_PWD_TYPE_NONE,     /* None */
    SRV_SIM_CTRL_PWD_TYPE_CHV1,     /* CHV1 (PIN1) */
    SRV_SIM_CTRL_PWD_TYPE_CHV2,     /* CHV2 (PIN2) */
    SRV_SIM_CTRL_PWD_TYPE_UBCHV1,   /* Unblock CHV1 (PUK1) */
    SRV_SIM_CTRL_PWD_TYPE_UBCHV2,   /* Unblock CHV2 (PUK2) */

    SRV_SIM_CTRL_PWD_TYPE_END_OF_ENUM
} srv_sim_ctrl_pwd_type_enum;

/*
 * DESCRIPTION
 *  Operator of SIM.
 */
typedef enum
{
    SRV_SIM_CTRL_OP_UNKNOWN,        /* Unknown operator */
    SRV_SIM_CTRL_OP_CMCC,           /* CMCC */
    SRV_SIM_CTRL_OP_CU,             /* CU */
    SRV_SIM_CTRL_OP_END_OF_ENUM
} srv_sim_ctrl_op_enum;

/*
 * DESCRIPTION
 *  Return structure of srv_sim_ctrl_get_eh_plmn().
 */
typedef struct
{
    /* Number of PLMNs */
    S32 num;

    /*
     * Pointers to PLMN strings.
     * NOTE: They point to internal context of SimCtrl for performance concern,
     * do not remove the const qualifier or modify the content.
     */
    const CHAR *plmn[SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM];
} srv_sim_ctrl_plmn_list_struct;


/****************************************************************************
 * Global functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_is_available
 * DESCRIPTION
 *  To query whether the SIM is available or not.
 *  A SIM is available only if it is present and all verifications are passed.
 *  If not available, client can query the cause by srv_sim_ctrl_get_unavailable_cause().
 *  Note that this function only tells SIM status from lower layer, not
 *  not take settings into account. Even if SIM is reported as available, it
 *  may be disabled by mode setting and we can not use it.
 * PARAMETERS
 *  sim         : [IN] Which SIM, not accept invalid value. If passes MMI_SIM2
 *                     on signal SIM project, it will assert fail.
 * RETURNS
 *  MMI_TRUE if the specified SIM is available.
 * SEE ALSO
 *  srv_sim_ctrl_get_unavailable_cause
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_is_available(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_unavailable_cause
 * DESCRIPTION
 *  If a SIM is not available, application can query the cause by this function.
 * PARAMETERS
 *  sim         : [IN] Which SIM
 * RETURNS
 *  Unavailable cause.
 * SEE ALSO
 *  srv_sim_ctrl_is_available
 *****************************************************************************/
extern srv_sim_ctrl_ua_cause_enum srv_sim_ctrl_get_unavailable_cause(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_n_remaining_attempts
 * DESCRIPTION
 *  Get the number of remaining attempts.
 * PARAMETERS
 *  sim         : [IN] Which SIM
 *  pwd_type    : [IN] Password type
 * RETURN VALUES
 *  -1  : Unknown
 *   0  : Blocked
 *  >0  : Valid value
 *****************************************************************************/
extern S32 srv_sim_ctrl_get_n_remaining_attempts(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_chv1_is_blocked
 * DESCRIPTION
 *  To query if CHV1 is blocked.
 * PARAMETERS
 *  sim         : [IN] Which SIM
 *  pwd_type    : [IN] Password type
 * RETURN VALUES
 *  MMI_TRUE if CHV1 is blocked.
 *****************************************************************************/
#define srv_sim_ctrl_chv1_is_blocked(sim) (srv_sim_ctrl_get_unavailable_cause(sim) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_imsi
 * DESCRIPTION
 *  Get the IMSI of the SIM.
 *
 *  NOTE: It requires time to read IMSI. IMSI is ready only if
 *  SRV_SIM_CTRL_IMSI_CHANGED has been emitted after SIM is available.
 *  Do not assume home PLMN is always the same as the 2~7 digits of IMSI.
 *  For some features, such as AT&T ENS, they may be not the same.
 *  Please always get home PLMN by srv_sim_ctrl_get_home_plmn().
 * PARAMETERS
 *  sim             : [IN]  Which SIM
 *  out_imsi_buffer : [OUT] IMSI buffer to be filled in, it shall at least
 *                          (SRV_MAX_IMSI_LEN + 1) bytes.
 *  buffer_size     : [IN]  Byte size of out_imsi_buffer.
 *                          It shall >= (SRV_MAX_IMSI_LEN + 1.)
 * RETURN VALUES
 *  MMI_TRUE    : If IMSI is available and returned.
 *  MMI_FALSE   : IMSI is unavailable; for example, SIM is not inserted.
 * SEE ALSO
 *  srv_sim_ctrl_get_home_plmn
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_get_imsi(mmi_sim_enum sim, CHAR *out_imsi_buffer, U32 buffer_size);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_home_plmn
 * DESCRIPTION
 *  Get home PLMN specified in the SIM.
 *  If multiple home PLMN exist, e.g. EHPLMN, this API will return the
 *  highest-priority one.
 *
 *  NOTE: It requires time to read home PLMN. Home PLMN is ready only if
 *  SRV_SIM_CTRL_HOME_PLMN_CHANGED has been emitted after SIM is available.
 * PARAMETERS
 *  sim             : [IN]  Which SIM
 *  out_plmn_buffer : [OUT] PLMN buffer to be filled in, it shall at least
 *                          (SRV_MAX_PLMN_LEN + 1) bytes.
 *  buffer_size     : [IN]  Byte size of out_plmn_buffer.
 *                          It shall >= (SRV_MAX_PLMN_LEN + 1.)
 * RETURN VALUES
 *  MMI_TRUE    : If home PLMN is available and returned.
 *  MMI_FALSE   : Home PLMN is unavailable or not ready.
 * SEE ALSO
 *  SRV_SIM_CTRL_HOME_PLMN_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_get_home_plmn(mmi_sim_enum sim, CHAR *out_plmn_buffer, U32 buffer_size);

#ifdef __R7_EHPLMN__
/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_eh_plmn
 * DESCRIPTION
 *  Get equivalent home PLMN list(EHPLMN). Please refer to 23.122.
 *  The return value is available only if EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED
 *  has been emitted.
 * PARAMETERS
 *  sim             : [IN]  Which SIM
 *  out_plmn_list   : [OUT] EHPLMN list; do not modify the content
 * RETURN VALUES
 *  MMI_TRUE    : If EHPLMN exists
 *  MMI_FALSE   : Return value is invalid
 * SEE ALSO
 *  SRV_SIM_CTRL_HOME_PLMN_CHANGED
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_get_eh_plmn(mmi_sim_enum sim, srv_sim_ctrl_plmn_list_struct *out_plmn_list);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_change_check
 * DESCRIPTION
 *  To determine whether SIM is changed by comparing to previous power-on or
 *  previous SIM.
 *  The return value is valid only if the SIM is available & verified until
 *  unavailable or next "init" verification. If another SIM init verification
 *  is performed, this value will be updated. BT, G+C, SIM IMSI refresh, or
 *  SIM hot-swap may cause init verifications.
 * PARAMETERS
 *  sim             : [IN]  Which SIM
 * RETURNS
 *  srv_sim_ctrl_change_check_enum
 *****************************************************************************/
extern srv_sim_ctrl_change_check_enum srv_sim_ctrl_get_change_check(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_any_verifying_sim
 * DESCRIPTION
 *  Check whether any SIM is in verifying.
 *  See the description of srv_sim_ctrl_is_in_verifying for the definition of a verifying SIM.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if some SIM is in verifying
 * SEE ALSO
 *  srv_sim_ctrl_is_in_verifying
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_any_verifying_sim(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_is_in_verifying
 * DESCRIPTION
 *  To determine whether the SIM is in verifying.
 *  A verifying SIM is a SIM which is inserted, and reading verification data
 *  or needs verification.
 *  For example, CHV-required SIM or UBCHV-required SIM, etc.
 *  However, a blocked SIM or not-inserted SIM is NOT a verifying SIM.
 * PARAMETERS
 *  sim         : [IN] Which SIM
 * RETURNS
 *  MMI_TRUE if the SIM is in verifying
 * SEE ALSO
 *  srv_sim_ctrl_any_verifying_sim
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_is_in_verifying(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_one_available_sim
 * DESCRIPTION
 *  To get one SIM which is available. If no SIM is available, it returns 0.
 *  Client can use this function to query whether there is anything available.
 *  Note that this function only tells SIM status from lower layer, not
 *  not take settings into account. Even if SIM is reported as available, it
 *  may be disabled by mode setting and we can not use it.
 * PARAMETERS
 *  void
 * RETURNS
 *  One available SIM in mmi_sim_enum. If no SIM is available, 0 will be returned.
 *  If both SIM are available, it returns MMI_SIM1 by default.
 * SEE ALSO
 *  srv_sim_ctrl_is_available
 *****************************************************************************/
extern U32 srv_sim_ctrl_get_one_available_sim(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_any_sim_is_available
 * DESCRIPTION
 *  To query if there is any SIM available.
 *  This function will check all SIM status and return a summary result.
 *  Note that this function only tells SIM status from lower layer, not
 *  not take settings into account. Even if SIM is reported as available, it
 *  may be disabled by mode setting and we can not use it.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if any SIM is available.
 * SEE ALSO
 *  srv_sim_ctrl_get_one_available_sim, srv_sim_ctrl_is_available
 *****************************************************************************/
#define srv_sim_ctrl_any_sim_is_available() (srv_sim_ctrl_get_one_available_sim() != 0)

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_is_inserted
 * DESCRIPTION
 *  To query whether the SIM is inserted or not.
 *  The result is valid only if bootup completed.
 * PARAMETERS
 *  sim     : [IN] Which SIM (mmi_sim_enum)
 * RETURNS
 *  MMI_TRUE if the SIM is inserted.
 *****************************************************************************/
#define srv_sim_ctrl_is_inserted(sim) \
    (srv_sim_ctrl_get_unavailable_cause(sim) != SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED && \
     srv_sim_ctrl_get_unavailable_cause(sim) != SRV_SIM_CTRL_UA_CAUSE_RECOVERY)

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_num_of_inserted
 * DESCRIPTION
 *  Get the number of inserted SIMs. This function is valid only after SIM
 *  module ready (bootup animation).
 *  The earliest safe point is after BEFORE_IDLE emitted.
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of inserted SIMs.
 *  For example, if only SIM2 & SIM3 are inserted, returns 2.
 *****************************************************************************/
extern S32 srv_sim_ctrl_get_num_of_inserted(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_pwd_is_enabled
 * DESCRIPTION
 *  To query whether the CHV is enabled or not.
 *  The result is valid only if bootup completed.
 * PARAMETERS
 *  sim         : [IN] Which SIM (mmi_sim_enum)
 *  pwd_type    : [IN] CHV1 or CHV2
 * RETURNS
 *  MMI_TRUE if the CHV of the SIM is enabled.
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_pwd_is_enabled(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_pwd_is_verified
 * DESCRIPTION
 *  To query whether the CHV is verified or not.
 *  The result is valid only if bootup completed.
 * PARAMETERS
 *  sim         : [IN] Which SIM (mmi_sim_enum)
 *  pwd_type    : [IN] CHV1 or CHV2
 * RETURNS
 *  MMI_TRUE if the CHV of the SIM is verified.
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_pwd_is_verified(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_pwd_is_blocked
 * DESCRIPTION
 *  To query whether the CHV is blocked or not.
 *  The result is valid only if bootup completed.
 * PARAMETERS
 *  sim         : [IN] Which SIM (mmi_sim_enum)
 *  pwd_type    : [IN] CHV1, CHV2, UBCHV1, or UBCHV2
 * RETURNS
 *  MMI_TRUE if the CHV of the SIM is blocked.
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_pwd_is_blocked(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_verify
 * DESCRIPTION
 *  Verify password of the SIM.
 *  This function is only used to verify CHV1 and CHV2 now. For UBCHVs, please
 *  call srv_sim_ctrl_verify_ubchv() instead.
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 *  pwd_type            : [IN] Password type
 *  pwd                 : [IN] UCS2-encoded string of password
 *  result_proc         : [IN] Callback for result, the result will be notified
 *                             by EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT
 *  user_data           : [IN] To be passed into result_proc().
 * RETURNS
 *  Session ID
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT
 *****************************************************************************/
extern S32 srv_sim_ctrl_verify(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum pwd_type,
    const WCHAR *pwd,
    mmi_proc_func result_proc,
    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_verify_ubchv
 * DESCRIPTION
 *  Verify password of the SIM.
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 *  pwd_type            : [IN] Password type
 *  ubchv               : [IN] UCS2-encoded string of UBCHV password
 *  new_chv             : [IN] UCS2-encoded string of new CHV
 *  result_proc         : [IN] Callback for result, the result will be notified
 *                             by EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT
 *  user_data           : [IN] To be passed into result_proc().
 * RETURNS
 *  Session ID; < 0 means the session is not started
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT
 *****************************************************************************/
extern S32 srv_sim_ctrl_verify_ubchv(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum pwd_type,
    const WCHAR *ubchv,
    const WCHAR *new_chv,
    mmi_proc_func result_proc,
    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_set_enabled
 * DESCRIPTION
 *  Set enabled of SIM password
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 *  type                : [IN] Password type
 *  password            : [IN] UCS2-encoded string of password
 *  enabled             : [IN] Enabled property to be set
 *  proc                : [IN] Callback for result, the result will be notified
 *                             by EVT_ID_SRV_SIM_CTRL_SET_ENABLED_RESULT
 *  user_data           : [IN] To be passed into proc().
 * RETURNS
 *  Session ID; < 0 means the session is not started
 *  If the current state of enabled is already the same as the target,
 *  an invalid session ID will be returned and the callback will not be called.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_SET_ENABLED_RESULT
 *****************************************************************************/
extern S32 srv_sim_ctrl_set_enabled(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum type,
    const WCHAR *password,
    MMI_BOOL enabled,
    mmi_proc_func proc,
    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_change_password
 * DESCRIPTION
 *  Change password (of CHV)
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 *  type                : [IN] Password type
 *  old_pwd             : [IN] Old password in UCS2
 *  new_pwd             : [IN] New password in UCS2
 *  proc                : [IN] Callback for result, the result will be notified
 *                             by EVT_ID_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT
 *  user_data           : [IN] To be passed into proc().
 * RETURNS
 *  Session ID; < 0 means the session is not started
 *  If the current state of enabled is already the same as the target,
 *  an invalid session ID will be returned and the callback will not be called.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT
 *****************************************************************************/
extern S32 srv_sim_ctrl_change_password(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum type,
    const WCHAR *old_pwd,
    const WCHAR *new_pwd,
    mmi_proc_func proc,
    void *user_data);
    

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_is_usim
 * DESCRIPTION
 *  Query about whether the SIM is universal SIM
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 * RETURNS
 *  MMI_TRUE if universal SIM
 *****************************************************************************/
extern MMI_BOOL srv_sim_ctrl_is_usim(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_op
 * DESCRIPTION
 *  Query the SIM operator
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 * RETURNS
 *  srv_sim_ctrl_op_enum
 *****************************************************************************/
extern srv_sim_ctrl_op_enum srv_sim_ctrl_get_op(mmi_sim_enum sim);

/****************************************************************************
 * Events
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Event ID of SIM events.
 *  Note that all SIM events will be emitted until BEFORE_IDLE, even the status
 *  is already known during booting animation.
 */
typedef enum
{
    EVT_ID_SRV_SIM_CTRL_START = SRV_SIM_CTRL_BASE,

    /*
     * SIM's availability changed.
     * This event will be emitted at least once after bootup for each SIM, to
     * notify application the initial status of SIM.
     *
     * Structure:
     *  srv_sim_ctrl_availability_changed_evt_struct
     * See also:
     *  EVT_ID_SRV_SIM_CTRL_AVAILABLE, EVT_ID_SRV_SIM_CTRL_UNAVAILABLE
     */
    EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED,

    /*
     * SIM is available.
     * NOTE that even SIM is available currently, it may be unavailable later
     * because of SIM lost, access error, SIM access mode changes or other
     * unexpected error. As SIM becomes unavailable, it may become available
     * again. This event will only be emitted when the SIM becomes available
     * from unavailable.
     *
     * Structure:
     *  srv_sim_ctrl_available_evt_struct
     * See also:
     *  EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, EVT_ID_SRV_SIM_CTRL_UNAVAILABLE
     */
    EVT_ID_SRV_SIM_CTRL_AVAILABLE,

    /*
     * SIM is unavailable.
     * NOTE that SIM is unavailable currently does not imply that SIM is always
     * unavailable, may be the unavailable is temporary. This event will only be
     * emitted when the SIM becomes unavailable from available.
     *
     * Structure:
     *  srv_sim_ctrl_unavailable_evt_struct
     * See also:
     *  EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, EVT_ID_SRV_SIM_CTRL_AVAILABLE
     */
    EVT_ID_SRV_SIM_CTRL_UNAVAILABLE,

    /*
     * SIM refreshed event.
     * As SIM refreshed, applications need to refresh SIM values.
     *
     * Structure:
     *  srv_sim_ctrl_refreshed_evt_struct
     */
    EVT_ID_SRV_SIM_CTRL_REFRESHED,

    /*
     * No SIM is available.
     * On single SIM project this event is the same as EVT_ID_SRV_SIM_CTRL_UNAVAILABLE
     * of the SIM. On dual SIM project, this event will be emitted only if both
     * SIM is unavailable.
     * NOTE that SIM is unavailable currently does not imply that SIM is always
     * unavailable, may be the unavailable is temporary.
     *
     * Structure:
     *  srv_sim_ctrl_no_sim_available_evt_struct
     */
    EVT_ID_SRV_SIM_CTRL_NO_SIM_AVAILABLE,

    /*
     * After SIM is available, it requires time to read home PLMN from the SIM.
     * This event is used to notify the home PLMN ready. If home PLMN is
     * updated on SIM refresh or SIM status changed, this event will also be emitted.
     *
     * Structure:
     *  srv_sim_ctrl_home_plmn_changed_evt_struct
     */
    EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED,

    /*
     * After SIM is available, it requires time to get IMSI from the SIM.
     * This event is used to notify the IMSI ready. If IMSI is
     * updated on SIM refresh or SIM status changed, this event will also be emitted.
     * Usually IMSI ready time is earlier than home PLMN. Because to get home PLMN
     * requires one additional file EF_AD to be read.
     *
     * Structure:
     *  srv_sim_ctrl_imsi_changed_evt_struct
     */
    EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED,

    /*
     * External SIM event detected. For example, plug-in/plug-out, BT access profile, etc.
     *
     *
     * Structure:
     *  srv_sim_ctrl_event_detected_evt_struct
     */
    EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED,

    /*
     * This event is used for srv_sim_ctrl_verify() to notify the result
     * of verification.
     *
     * Structure:
     *  srv_sim_ctrl_verify_result_evt_struct
     * See also:
     *  srv_sim_ctrl_verify, srv_sim_ctrl_verify_ubchv
     */
    EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT,

    /*
     * This event is used for srv_sim_ctrl_sync() to notify the completion of
     * synchronization.
     *
     * Structure:
     *  srv_sim_ctrl_sync_completed_evt_struct
     * See also:
     *  srv_sim_ctrl_sync
     */
    EVT_ID_SRV_SIM_CTRL_SYNC_COMPLETED,

    /*
     * This event is used for srv_sim_ctrl_set_enabled() to notify the result of
     * enabled-setting request.
     *
     * Structure:
     *  srv_sim_ctrl_set_enabled_result_evt_struct
     * See also:
     *  srv_sim_ctrl_set_enabled
     */
    EVT_ID_SRV_SIM_CTRL_SET_ENABLED_RESULT,

    /*
     * This event is used for srv_sim_ctrl_change_password() to notify the result of
     * change-password request.
     *
     * Structure:
     *  srv_sim_ctrl_change_password_result_evt_struct
     * See also:
     *  srv_sim_ctrl_change_password
     */
    EVT_ID_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT,

    EVT_ID_SRV_SIM_CTRL_END_OF_ENUM
} srv_sim_ctrl_event_enum;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED.
 *  This event will be emitted if the availibility changed or unavailable cause
 *  changed of each SIM. Client can determine which SIM changed by the sim field.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;               /* Which SIM */
    MMI_BOOL is_available_before;   /* Previous availibility; MMI_TRUE if available */
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before; /* Previous unavailable cause */
    MMI_BOOL is_available_now;      /* Current availibility; MMI_TRUE if available */
    srv_sim_ctrl_ua_cause_enum unavailable_cause; /* The cause if unavailable */
} srv_sim_ctrl_availability_changed_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_AVAILABLE.
 *  It will be emitted if SIM is available.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_AVAILABLE
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;   /* Which SIM */
    srv_sim_ctrl_ua_cause_enum ua_cause_before;    /* Unavailable cause before */
} srv_sim_ctrl_available_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_AVAILABLE.
 *  It will be emitted if SIM became unavailable in the first time.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_UNAVAILABLE
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;                       /* Which SIM */
} srv_sim_ctrl_unavailable_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED.
 *  Please use srv_sim_ctrl_get_home_plmn() to get current home PLMN.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED, srv_sim_ctrl_get_home_plmn
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which SIM */
} srv_sim_ctrl_home_plmn_changed_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED.
 *  Please use srv_sim_ctrl_get_imsi() to get current IMSI.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED, srv_sim_ctrl_get_imsi
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which SIM */
} srv_sim_ctrl_imsi_changed_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_REFRESHED.
 *  It is used to notify application that SIM was refreshed. Applications have
 *  to refresh the data from SIM.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_REFRESHED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which SIM */
} srv_sim_ctrl_refreshed_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_NO_SIM_AVAILABLE.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_NO_SIM_AVAILABLE
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_sim_ctrl_no_sim_available_evt_struct;


/*
 * DESCRIPTION
 *  Fail cause of operation.
 */
typedef enum
{
    SRV_SIM_CTRL_FAIL_CAUSE_NONE,           /* None */
    SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD, /* Wrong password */
    SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED,  /* Operation blocked */
    SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL,      /* Temporary fail */
    SRV_SIM_CTRL_FAIL_CAUSE_SIM_ERROR,      /* SIM error */

    SRV_SIM_CTRL_FAIL_CAUSE_END_OF_ENUM
} srv_sim_ctrl_fail_cause_enum;


/*
 * DESCRIPTION
 *  The result of SIM password verification.
 * SEE ALSO
 *  EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Which SIM. */
    mmi_sim_enum sim;

    /* Password type. */
    srv_sim_ctrl_pwd_type_enum type;

    /* Success or not */
    MMI_BOOL success;

    /* Fail cause of verification */
    srv_sim_ctrl_fail_cause_enum fail_cause;

    /* The number of remaining attempts of the verification type. */
    U32 n_remaining_attempts;
} srv_sim_ctrl_verify_result_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_SYNC_COMPLETED.
 * SEE ALSO
 *  srv_sim_ctrl_sync
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    S32 session_id;   /* Session ID*/
    mmi_sim_enum sim; /* Which SIM synchonized */
} srv_sim_ctrl_sync_completed_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_SET_ENABLED_RESULT.
 * SEE ALSO
 *  srv_sim_ctrl_set_enabled
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which SIM */
    srv_sim_ctrl_pwd_type_enum type; /* Password type */
    MMI_BOOL success;       /* Success or not */
    srv_sim_ctrl_fail_cause_enum fail_cause; /* Fail cause */
    MMI_BOOL is_enabled;    /* Current status */
} srv_sim_ctrl_set_enabled_result_evt_struct;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT.
 * SEE ALSO
 *  srv_sim_ctrl_change_password
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    mmi_sim_enum sim;       /* Which SIM */
    srv_sim_ctrl_pwd_type_enum type; /* Password type */
    MMI_BOOL success;       /* Success or not */
    srv_sim_ctrl_fail_cause_enum fail_cause; /* Fail cause */
} srv_sim_ctrl_change_password_result_evt_struct;


/*
 * DESCRIPTION
 *  Types of SIM events detected.
 * SEE ALSO
 *  srv_sim_ctrl_event_detected_evt_struct
 */
typedef enum
{
    /* BT access profile is enabled */
    SRV_SIM_CTRL_EVENT_DET_BT_ACCESS_ON,
    /* BT access profile is disabled */
    SRV_SIM_CTRL_EVENT_DET_BT_ACCESS_OFF,
    /* G+C dual SIM disconnected */
    SRV_SIM_CTRL_EVENT_DET_DISCONNECTED,
    /* G+C dual SIM connected */
    SRV_SIM_CTRL_EVENT_DET_CONNECTED,
    /* SIM is removed */
    SRV_SIM_CTRL_EVENT_DET_REMOVED,
    /* SIM is inserted */
    SRV_SIM_CTRL_EVENT_DET_INSERTED,
    /* SIM recovery start */
    SRV_SIM_CTRL_EVENT_DET_RECOVERY_START,
    /* SIM recovery end */
    SRV_SIM_CTRL_EVENT_DET_RECOVERY_END,
    /* VSIM on */
    SRV_SIM_CTRL_EVENT_DET_VSIM_ON,
    /* VSIM off */
    SRV_SIM_CTRL_EVENT_DET_VSIM_OFF,

    /*
     * Verification completed.
     * We can know whether the SIM changed only verified.
     */
    SRV_SIM_CTRL_EVENT_DET_REINIT_VERIFIED,

    /* SIM is not inserted when bootup */
    SRV_SIM_CTRL_EVENT_DET_BOOTUP_WITH_SIM,
    /* SIM is inserted when bootup */
    SRV_SIM_CTRL_EVENT_DET_BOOTUP_WITHOUT_SIM,

    SRV_SIM_CTRL_EVENT_DET_END_OF_ENUM
} srv_sim_ctrl_event_detection_enum;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED.
 * SEE ALSO
 *  srv_sim_ctrl_event_detected_evt_struct
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Which SIM */
    mmi_sim_enum sim;

    /* SIM event type */
    srv_sim_ctrl_event_detection_enum type;

    /* Change check. Valid only if type = REINIT_VERIFIED. */
    srv_sim_ctrl_change_check_enum change_check;
} srv_sim_ctrl_event_detected_evt_struct;


/****************************************************************************
 * Non-published utilities
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

extern MMI_BOOL srv_sim_ctrl_is_initializing(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_mnc_len_in_ef_ad
 * DESCRIPTION
 *  Get the length of MNC which is described in EF_AD
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 * RETURNS
 *  The field value of length of MNC in the IMSI, which is described in EF_AD.
 *  If EF_AD is not present, returns 0.
 *****************************************************************************/
extern S32 srv_sim_ctrl_get_mnc_len_in_ef_ad(mmi_sim_enum sim);

extern void srv_sim_ctrl_force_to_update_imsi(mmi_sim_enum sim);
#ifdef __ENS__
extern void srv_sim_ctrl_update_home_plmn(mmi_sim_enum sim, const U8 plmn_bcd[3]);
#endif
#ifdef __R7_EHPLMN__
extern void srv_sim_ctrl_ehplmn_refresh(mmi_sim_enum sim);
#endif

extern MMI_BOOL srv_sim_ctrl_get_home_plmn_for_network(
    mmi_sim_enum sim,
    CHAR *out_plmn_buffer,
    U32 buffer_size);

extern void srv_sim_ctrl_update_chv_info(mmi_sim_enum sim, const sim_chv_info_struct *chv_info);


#ifdef __INVALID_SIM_RECOVERY__
extern MMI_BOOL srv_sim_ctrl_invalid_sim_recovery_get_status(mmi_sim_enum sim);
extern void srv_sim_ctrl_invalid_sim_recovery_set_pin(mmi_sim_enum sim, const CHAR *pwd);
#endif /* __INVALID_SIM_RECOVERY__ */

#define SRV_SIM_CTRL_MAX_SIM_NUM (MMI_MAX_SIM_NUM)

#define srv_sim_ctrl_get_index mmi_frm_sim_to_index
#define srv_sim_ctrl_get_sim_by_index mmi_frm_index_to_sim

/* DOM-NOT_FOR_SDK-END */
 
#endif /* __SIM_CTRL_SRV_GPROT_H__ */


