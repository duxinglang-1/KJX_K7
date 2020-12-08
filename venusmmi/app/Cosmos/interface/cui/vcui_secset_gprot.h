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
 *  vcui_secset_gprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Security setting CUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SECSET_GPROT_H__
#define __VCUI_SECSET_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif


#include "MMI_features.h"
#include "MMIDataType.h"


/****************************************************************************
 * API
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Return value to disallow closing on PASSIVE_CLOSING event.
 * SEE ALSO
 *  EVT_ID_VCUI_VERIFY_PASSIVE_CLOSING
 */
#define VCUI_SECSET_DONT_CLOSE (-1)


/*
 * DESCRIPTION
 *  Type of verification CUI.
 * SEE ALSO
 *  vcui_verify_create, vcui_verify_set_sim
 */
typedef enum
{
    VCUI_VERIFY_TYPE_CHV1,       /* CHV1; need to specify SIM by vcui_verify_set_sim() */
    VCUI_VERIFY_TYPE_CHV2,       /* CHV2; need to specify SIM by vcui_verify_set_sim() */
    VCUI_VERIFY_TYPE_PHONE_PASSWORD, /* Phone password */

    VCUI_VERIFY_TYPE_END_OF_ENUM
} vcui_verify_type_enum;


/*****************************************************************************
 * FUNCTION
 *  vcui_verify_create
 * DESCRIPTION
 *  Create a verification CUI
 *  Note: before using verification CUI, please check whether the password
 *  is allowed to be verified. For example, CHV2 may be blocked or disabled.
 * PARAMETERS
 *  grp_id      : [IN] Parent group ID
 *  type        : [IN] Verification type. If type is CHV1 or CHV2, please call
 *                     vcui_verify_set_sim() to specify which SIM.
 * RETURNS
 *  Instance ID
 *****************************************************************************/
mmi_id vcui_verify_create(mmi_id grp_id, vcui_verify_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  vcui_verify_set_sim
 * DESCRIPTION
 *  To specify the SIM. If application create a CHV1 or CHV2 verification CUI,
 *  it is also needed to give the SIM.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  sim             : [IN] SIM ID.
 *                         On single SIM project, this value can only be MMI_SIM1.
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_verify_set_sim(mmi_id instance_id, mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  vcui_verify_run
 * DESCRIPTION
 *  Show the verification screen.
 *  If the password can not be verified, for example, BLOCKED or DISABLED,
 *  an result/cancel event will be emitted directly and no screen will be shown.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_verify_run(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  vcui_verify_close
 * DESCRIPTION
 *  Close the verification CUI.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_verify_close(mmi_id instance_id);


/*****************************************************************************
 * Events
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Verification CUI events.
 */
typedef enum
{
    /*
     * Verification result.
     * If user inputs wrong password, the verification will be continued and
     * no event will be emitted, until the verification blocked, cancelled or
     * error happens.
     *
     * Structure:
     *  vcui_verify_result_evt_struct
     */
    EVT_ID_VCUI_VERIFY_RESULT = VCUI_VERIFY_BASE,

    /*
     * Cancel.
     * User selects cancel or SIM status changed and unable to continue
     * the verification.
     *
     * Structure:
     *  vcui_verify_cancel_evt_struct
     */
    EVT_ID_VCUI_VERIFY_CANCEL,

    /*
     * Verification is being closed unexpectedly.
     * For example, some application calls mmi_frm_group_close() or
     * user presses End key to go back to idle.
     * User can return VCUI_SECSET_DONT_CLOSE to forbid the CUI from being
     * closed.
     * vcui_verify_close() will not trigger this event.
     *
     * Structure:
     *  vcui_verify_passive_closing_evt_struct
     */
    EVT_ID_VCUI_VERIFY_PASSIVE_CLOSING,

    EVT_ID_VCUI_VERIFY_END_OF_ENUM
} vcui_verify_event_enum;


/*
 * DESCRIPTION
 *  Fail cause of operation.
 */
typedef enum
{
    VCUI_VERIFY_FAIL_CAUSE_NONE,           /* None */
    VCUI_VERIFY_FAIL_CAUSE_WRONG_PASSWORD, /* Wrong password */
    VCUI_VERIFY_FAIL_CAUSE_OPERATION_BLOCKED,  /* Operation blocked */
    VCUI_VERIFY_FAIL_CAUSE_DISABLED,       /* Password disabled */
    VCUI_VERIFY_FAIL_CAUSE_TEMP_FAIL,      /* Operation blocked */
    VCUI_VERIFY_FAIL_CAUSE_SIM_ERROR,      /* SIM error */

    VCUI_VERIFY_FAIL_CAUSE_END_OF_ENUM
} vcui_verify_fail_cause_enum;

/*
 * DESCRIPTION
 *  Structure of EVT_ID_VCUI_VERIFY_RESULT.
 * SEE ALSO
 *  EVT_ID_VCUI_VERIFY_RESULT
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    MMI_BOOL success;   /* Success or not */
    vcui_verify_fail_cause_enum fail_cause; /* If failed, the cause */
} vcui_verify_result_evt_struct;

/*
 * DESCRIPTION
 *  Cause of cancel event.
 */
typedef enum
{
    VCUI_VERIFY_CANCEL_CAUSE_USER_CANCEL, /* User selects to cancel */
    VCUI_VERIFY_CANCEL_CAUSE_UNAVAILABLE, /* SIM become unavailable while the CUI is displaying */
    VCUI_VERIFY_CANCEL_CAUSE_ANOTHER_INST_RUN, /* Another instance with the same SIM & the same type is launched */

    VCUI_VERIFY_CANCEL_CAUSE_END_OF_ENUM
} vcui_verify_cancel_cause_enum;

/*
 * DESCRIPTION
 *  Structure of EVT_ID_VCUI_VERIFY_CANCEL.
 * SEE ALSO
 *  EVT_ID_VCUI_VERIFY_CANCEL
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    
    vcui_verify_cancel_cause_enum cause; /* Cause of the cancel event */
} vcui_verify_cancel_evt_struct;


/*
 * DESCRIPTION
 *  Structure of EVT_ID_VCUI_VERIFY_PASSIVE_CLOSING.
 * SEE ALSO
 *  EVT_ID_VCUI_VERIFY_PASSIVE_CLOSING
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} vcui_verify_passive_closing_evt_struct;


#ifdef __cplusplus
}
#endif

#endif /* __VCUI_SECSET_GPROT_H__ */
 
