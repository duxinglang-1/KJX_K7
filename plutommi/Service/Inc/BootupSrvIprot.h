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
 *  BootupSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal interface of bootup.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_BOOTUP_SRV_IPROT_H__
#define __SRV_BOOTUP_SRV_IPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "BootupSrvGprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * DESCRIPTION
 *  [INTERNAL]
 *  The protocol mode to be applied.
 * SEE ALSO
 *  srv_bootup_boot_protocol
 */
typedef enum
{
    /*
     * Enter flight mode.
     * If no SIM is inserted and we need to allow emergency call, we should apply
     * SRV_BOOTUP_PROTOCOL_MODE_SIM1_ONLY.
     */
    SRV_BOOTUP_PROTOCOL_MODE_NONE        = 0x0,
    
    /* Turn on SIM1 only for dual SIM project. */
    SRV_BOOTUP_PROTOCOL_MODE_SIM1_ONLY   = MMI_SIM1,

    /* Turn on SIM2 only for dual SIM project. */
    SRV_BOOTUP_PROTOCOL_MODE_SIM2_ONLY   = MMI_SIM2,

#if (MMI_MAX_SIM_NUM >= 3) // Gemini+
    SRV_BOOTUP_PROTOCOL_MODE_SIM3_ONLY   = MMI_SIM3,

#if (MMI_MAX_SIM_NUM >= 4)
    SRV_BOOTUP_PROTOCOL_MODE_SIM4_ONLY   = MMI_SIM4,
#endif

#else
    /* Turn on both SIMs for dual SIM project. */
    SRV_BOOTUP_PROTOCOL_MODE_DUAL_SIM    = (MMI_SIM1 | MMI_SIM2),
#endif

    SRV_BOOTUP_PROTOCOL_MODE_ALL_SIM     = ( MMI_SIM1
                                           | MMI_SIM2
#if (MMI_MAX_SIM_NUM >= 3) // Gemini+
                                           | MMI_SIM3
#if (MMI_MAX_SIM_NUM >= 4) // Gemini+
                                           | MMI_SIM4
#endif
#endif
                                           ),

    /* Enter flight mode for single SIM project. */
    SRV_BOOTUP_PROTOCOL_MODE_FLIGHT_MODE = 0x0,

    /* Enter normal mode. For dual SIM projects, it implies dual SIM mode. */
#if (MMI_MAX_SIM_NUM >= 3) // Gemini+
    SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE = SRV_BOOTUP_PROTOCOL_MODE_ALL_SIM,
#elif (MMI_MAX_SIM_NUM == 2)
    SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE = SRV_BOOTUP_PROTOCOL_MODE_DUAL_SIM,
#else
    /* Enter normal mode */
    SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE = MMI_SIM1,
#endif

    SRV_BOOTUP_PROTOCOL_MODE_END_OF_ENUM
} srv_bootup_protocol_mode_enum;

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_bootup_work_completed_callback
 * DESCRIPTION
 *  [INTERNAL]
 *  The function prototype of completed callback.
 * PARAMETERS
 *  user_data   : [IN] User data passed into the work function.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_bootup_verify_phonelock, srv_bootup_verify
 *****************************************************************************/
typedef void (*srv_bootup_work_completed_callback)(void *user_data);


/*
 * DESCRIPTION
 *  [INTERNAL]
 *  Result of cancelling verification.
 * SEE ALSO
 *  srv_bootup_cancel_verification, srv_bootup_cancel_verification_callback
 */
typedef struct
{
    mmi_sim_enum sim;                       /* Which SIM / protocol layer */
    srv_bootup_verification_type_enum type; /* Verification type */
    MMI_BOOL success;                       /* Success or not */
} srv_bootup_cancel_verification_result_struct;


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_bootup_cancel_verification_callback
 * DESCRIPTION
 *  [INTERNAL]
 *  The function prototype of the callback of cancelling verification.
 * PARAMETERS
 *  user_data   : [IN] User data passed into the srv_bootup_cancel_verification().
 *  sim         : [IN] Which SIM / protocol layer
 *  success     : [IN] Success or not
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_bootup_cancel_verification
 *****************************************************************************/
typedef void (*srv_bootup_cancel_verification_callback)(
                void *user_data,
                const srv_bootup_cancel_verification_result_struct *result);

/****************************************************************************
 * Global functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_init_sim_module
 * DESCRIPTION
 *  [INTERNAL]
 *  Initalize SIM module and query SIMs inserted or not.
 *  Client can use srv_bootup_sim_is_inserted() only after SIM module is initialized. 
 * PARAMETERS
 *  completed_callback  : [IN] Callback after completed.
 *  user_data           : [IN] To be passed into the completed callback function.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_bootup_sim_is_inserted
 *****************************************************************************/
extern void srv_bootup_init_sim_module(
                srv_bootup_work_completed_callback completed_callback,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sim_is_inserted
 * DESCRIPTION
 *  [INTERNAL]
 *  Query if SIM is inserted in the SIM slot. Before query, bootup control
 *  flow has to invoke srv_bootup_init_sim_module() to initialize SIM module.
 * PARAMETERS
 *  sim     : [IN] SIM slot to be queried.
 * RETURNS
 *  MMI_TRUE if it is inserted.
 * SEE ALSO
 *  srv_bootup_init_sim_module
 *****************************************************************************/
extern MMI_BOOL srv_bootup_sim_is_inserted(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_notify_completed
 * DESCRIPTION
 *  [INTERNAL]
 *  Notify bootup service that the flow has completed and the control is transferred
 *  back to bootup service. Bootup service will emit EVT_ID_SRV_BOOTUP_COMPLETED,
 *  finally.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * SEE ALSO
 *  EVT_ID_SRV_BOOTUP_COMPLETED
 *****************************************************************************/
extern void srv_bootup_notify_completed(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_boot_protocol
 * DESCRIPTION
 *  [INTERNAL]
 *  Initialize protocol layer modules.
 *  This action will enable protocol layer to initialize SIM further,
 *  search network and initialize protocol related modules.
 * PARAMETERS
 *  mode                : [IN] Bootup mode.
 *  completed_callback  : [IN] Once completed, this function will be invoked.
 *  user_data           : [IN] To be passed into the completed_callback.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bootup_boot_protocol(
                srv_bootup_protocol_mode_enum mode,
                srv_bootup_work_completed_callback completed_callback,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_phone_lock_is_required
 * DESCRIPTION
 *  [INTERNAL]
 *  To check whether phone lock is required. Bootup application should use
 *  srv_bootup_verify_phone_lock to unlock phone. Currently, phone lock
 *  should be verified before any SIM password.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if needs phone password.
 *****************************************************************************/
extern MMI_BOOL srv_bootup_phone_lock_is_required(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_verify_phone_lock
 * DESCRIPTION
 *  Verify phonelock.
 *  This function can be used only if srv_bootup_get_verification_type() ==
 *  SRV_BOOTUP_VERI_PHONE_LOCK.
 * PARAMETERS
 *  password            : [IN] UCS2-encoded string of password.
 *  result_callback     : [IN] Callback to return result.
 *  user_data           : [IN] The data pointer to be passed into result_callback().
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bootup_verify_phone_lock(
                const WCHAR *password,
                srv_bootup_verify_result_callback result_callback,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_verify_ubchv
 * DESCRIPTION
 *  [INTERNAL]
 *  Verify UBCHV of the SIM.
 *  This function can be used only if srv_bootup_get_verification_type() ==
 *  SRV_BOOTUP_VERI_UBCHV1.
 * PARAMETERS
 *  sim             : [IN] Which SIM
 *  ubchv           : [IN] UCS2-encoded string of the password to unblock CHV.
 *  newchv          : [IN] UCS2-encoded string of the new CHV
 *  result_callback : [IN] The verification result will be notified by this
 *                         callback.
 *  user_data       : [IN] To be passed into the callback.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_bootup_get_verification_type
 *****************************************************************************/
extern void srv_bootup_verify_ubchv(
                mmi_sim_enum sim,
                const WCHAR *ubchv,
                const WCHAR *newchv,
                srv_bootup_verify_result_callback result_callback,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_veri_can_be_cancelled
 * DESCRIPTION
 *  [INTERNAL]
 *  Query if current verification can be cancelled or not.
 *  This function is supported only if __CANCEL_LOCK_POWERON__ is defined.
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 * RETURNS
 *  MMI_TRUE if current verification can be cancelled.
 * SEE ALSO
 *  srv_bootup_cancel_verification
 *****************************************************************************/
extern MMI_BOOL srv_bootup_veri_can_be_cancelled(mmi_sim_enum sim);


#ifdef __CANCEL_LOCK_POWERON__
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_cancel_verification
 * DESCRIPTION
 *  [INTERNAL]
 *  Cancel the verification of SIM. This API will try to initialize SIM
 *  related module (e.g., phone book, SMS) as SIM is not inserted.
 *  This function is supported only if __CANCEL_LOCK_POWERON__ is defined,
 *  and only supported type can be cancelled
 *  (query by srv_bootup_veri_can_be_cancelled()).
 *  The state of srv_bootup_get_verification_info() will not change even
 *  if the verification of the SIM is cancelled. UI part can still request
 *  the verification after then.
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 *  result_callback     : [IN] Callback for completed
 *  user_data           : [IN] To be passed into completed_callback
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_bootup_veri_can_be_cancelled, srv_bootup_get_verification_info
 *****************************************************************************/
extern void srv_bootup_cancel_verification(
                mmi_sim_enum sim,
                srv_bootup_cancel_verification_callback result_callback,
                void *user_data);
                
#endif /* __CANCEL_LOCK_POWERON__ */


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_veri_is_cancelled
 * DESCRIPTION
 *  [INTERNAL]
 *  To query whether the verification of the SIM has been cancelled.
 *  If the verification has been cancelled, UI part can just skip the verification
 *  and continue next step. However, the state of required verification returned
 *  by srv_bootup_get_verification_info() will not change for the cancelling.
 *  UI part can still request the verification in the future by srv_bootup_verify().
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 * RETURNS
 *  MMI_TRUE if current verification can be cancelled.
 * SEE ALSO
 *  srv_bootup_cancel_verification, srv_bootup_get_verification_info
 *****************************************************************************/
extern MMI_BOOL srv_bootup_veri_is_cancelled(mmi_sim_enum sim);


/****************************************************************************
 * Events
 ****************************************************************************/

/*
 * DESCRIPTION
 *  [INTERNAL]
 *  The event structure of EVT_ID_SRV_BOOTUP_START, to start bootup flow.
 * SEE ALSO
 *  EVT_ID_SRV_BOOTUP_START
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    MMI_BOOL is_exception_mode; /* MMI_TRUE if exception mode */
} srv_bootup_start_evt_struct;


/*
 * DESCRIPTION
 *  [INTERNAL]
 *  The event structure of EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED, to notify the
 *  error of SIM. For the new state of SIM, please refer to SIM ctrl.
 * SEE ALSO
 *  srv_sim_ctrl_get_unavailable_cause
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Which SIM */
    mmi_sim_enum sim;

    /*
     * Fatal error, including SIM removed, access error on SIM, etc. Please
     * refer to srv_sim_ctrl_get_unavailable_cause() to get the details.
     */
    MMI_BOOL fatal_error;
} srv_bootup_sim_status_changed_evt_struct;


/* DOM-NOT_FOR_SDK-BEGIN */

typedef enum
{
    SRV_BOOTUP_PROTOCOL_QUERY_INVALID,
    SRV_BOOTUP_PROTOCOL_QUERY_ASK_USER,
    SRV_BOOTUP_PROTOCOL_QUERY_APPLY_DEFAULT,

    SRV_BOOTUP_PROTOCOL_QUERY_END_OF_ENUM
} srv_bootup_protocol_query_enum;

extern srv_bootup_protocol_query_enum srv_bootup_protocol_get_query_setting(void);

extern MMI_BOOL srv_bootup_protocol_is_ready(void);

extern MMI_BOOL srv_bootup_protocol_is_activated(mmi_sim_enum sim);

extern MMI_BOOL srv_bootup_is_auto_power_on_test(void);

extern MMI_BOOL srv_bootup_auto_shutdown_is_enabled(void);

/* DOM-NOT_FOR_SDK-END */

#endif /* __SRV_BOOTUP_SRV_IPROT_H__ */

