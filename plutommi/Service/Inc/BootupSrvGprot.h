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
 *  BootupSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of bootup.
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
 
#ifndef __SRV_BOOTUP_SRV_GPROT_H__
#define __SRV_BOOTUP_SRV_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "custom_nvram_sec.h" /* SML_MAX_RETRY_COUNT */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"


/****************************************************************************
 * Constants
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Infinite number of remaining attempts.
 * SEE ALSO
 *  srv_bootup_verify_result_struct, srv_bootup_get_verification_info
 */
#define SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER 0xffff


/*
 * DESCRIPTION
 *  Maximum retrial number of personalization lock.
 * SEE ALSO
 *  srv_bootup_verify_result_struct, srv_bootup_get_verification_info
 */
#define SRV_BOOTUP_MAX_PERSONALIZATION_TRIAL_NUM  (SML_MAX_RETRY_COUNT)


/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Current booting mode.
 *  However, it may be exceptional booting that needs different behavior. Please
 *  also determine exceptional bootup by srv_bootup_is_exception_mode().
 * SEE ALSO
 *  srv_bootup_get_booting_mode, srv_bootup_is_exception_mode
 */
typedef enum
{
    SRV_BOOTUP_MODE_INVALID,        /* Unknown yet. The booting mode is known until bootup is launched. */
    SRV_BOOTUP_MODE_NORMAL,         /* Normal bootup. Usually power-on by key press */
    SRV_BOOTUP_MODE_USB,            /* USB mode */
    SRV_BOOTUP_MODE_ALARM,          /* Alarm ringing */
    SRV_BOOTUP_MODE_PRECHARGE,      /* Charger connected in, but power is not sufficient to show charging screen. */
    SRV_BOOTUP_MODE_CHARGE,         /* Normal charging. */
    
    SRV_BOOTUP_MODE_END_OF_ENUM
} srv_bootup_mode_enum;

/*
 * DESCRIPTION
 *  Verification type required by bootup.
 * SEE ALSO
 *  srv_bootup_get_verification_type
 */
typedef enum
{
    SRV_BOOTUP_VERI_NONE,           /* No verification is required */
    SRV_BOOTUP_VERI_PHONE_LOCK,     /* Phone lock password */
    SRV_BOOTUP_VERI_CHV1,           /* CHV1(PIN1) */
    SRV_BOOTUP_VERI_UBCHV1,         /* Unblock CHV1(PUK1) */
    SRV_BOOTUP_VERI_NP,             /* Personalization: Network control key */
    SRV_BOOTUP_VERI_NSP,            /* Personalization: Network subset control key */
    SRV_BOOTUP_VERI_SP,             /* Personalization: Service provider control key */
    SRV_BOOTUP_VERI_CP,             /* Personalization: Corporate control key */
    SRV_BOOTUP_VERI_SIMP,           /* Personalization: SIM/USIM personalization control key */
    SRV_BOOTUP_VERI_NSSP,           /* Personalization: NSP + SP */
    SRV_BOOTUP_VERI_SIMCP,          /* Personalization: SIMP + CP */

    SRV_BOOTUP_VERI_END_OF_ENUM
} srv_bootup_verification_type_enum;

/*
 * DESCRIPTION
 *  The result of verification.
 */
typedef struct
{
    /*
     * Which protocol.
     * If the password is not related to protocol module, e.g., phone lock,
     * this value is invalid.
     */
    mmi_sim_enum sim;

    /* Type of verification */
    srv_bootup_verification_type_enum type;

    /*
     * Success or not.
     * NOTE even if success, not apply all verfication required are passed. Client should
     * also call srv_bootup_is_verification_passed() and srv_bootup_get_verification_type()
     * to check whether there is any further verfication required.
     */
    MMI_BOOL success;

    /*
     * Verification failed may be caused by a fatal error. For example, SIM
     * removed suddenly and future CHV trial is not allowed.
     */
    MMI_BOOL fatal_error;

    /*
     * The number of remaining attempts of the verification type.
     * If the verfication is locked, this value will be 0. If not limited,
     * this value will be SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER.
     */
    S32 n_remaining_attempts;
} srv_bootup_verify_result_struct;


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_bootup_verify_result_callback
 * DESCRIPTION
 *  The result callback for verification.
 * PARAMETERS
 *  user_data   : [IN] The user data passed in to the command function.
 *  result      : [IN] Result
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_bootup_verify_phonelock, srv_bootup_verify
 *****************************************************************************/
typedef void (*srv_bootup_verify_result_callback)(void *user_data, const srv_bootup_verify_result_struct *result);


/****************************************************************************
 * Global functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_is_launched
 * DESCRIPTION
 *  Normal bootup is launched.
 *  This is used by the applications who receive events before system is really
 *  booted-up. They can query the state by this function to know if they can
 *  operator UI, or other bootup-dependent operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_bootup_is_launched(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_is_booting
 * DESCRIPTION
 *  System is still booting.
 *  The return value will be true until entered Idle and all bootup
 *  flow completed.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if in booting period.
 *****************************************************************************/
extern MMI_BOOL srv_bootup_is_booting(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_is_completed
 * DESCRIPTION
 *  Bootup is completed and entered idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if boot completed.
 *****************************************************************************/
#define srv_bootup_is_completed() \
    (srv_bootup_is_launched() && !srv_bootup_is_booting())

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_get_booting_mode
 * DESCRIPTION
 *  Get booting mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  Bootup mode: srv_bootup_mode_enum.
 * SEE ALSO
 *  srv_bootup_mode_enum
 *****************************************************************************/
extern srv_bootup_mode_enum srv_bootup_get_booting_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_is_exception_mode
 * DESCRIPTION
 *  Is exceptional bootup. The return value will be MMI_TRUE only if some assert
 *  fail or fatal error caused the phone reboot.
 *  Normally applications only need to know bootup mode by srv_bootup_get_booting_mode(),
 *  but if need different behavior on exceptional booting, use this function
 *  to query.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if it is exceptional bootup.
 * SEE ALSO
 *  srv_bootup_get_booting_mode
 *****************************************************************************/
extern MMI_BOOL srv_bootup_is_exception_mode(void);


/****************************************************************************
 * Events
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Event IDs of bootup.
 */
typedef enum
{
    /*
     * [INTERNAL]
     * Notify bootup control flow module to handle bootup.
     * The bootup control flow module should implement all bootup necessary steps.
     *
     * Structure:
     *  srv_bootup_start_evt_struct
     */
    EVT_ID_SRV_BOOTUP_START = SRV_BOOTUP_BASE,

    /*
     * [INTERNAL]
     * Notify the status change of SIM.
     *
     * Structure:
     *  srv_bootup_sim_status_changed_evt_struct
     */
    EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED,

    /*
     * This event will be emitted once bootup sanity check is passed. The applications
     * which need to be initialized as earlier as possible will require this event,
     * for example, interrupt applications, services needed during booting.
     * If no such requirement, please subscribe EVT_ID_SRV_BOOTUP_NORMAL_INIT.
     *
     * Please register your event proc in BootupInitConfig.h
     *
     * Structure:
     *  srv_bootup_early_init_evt_struct
     * See also:
     *  EVT_ID_SRV_BOOTUP_NORMAL_INIT
     */
    EVT_ID_SRV_BOOTUP_EARLY_INIT,

    /*
     * The normal init event of booting. Applications usually subscribe to do their
     * initializations. If your application has NVRAM or file accessing, it is recommended
     * to trigger the initialization here. If your application does not need to be
     * initialized on booting or large amount of initialization is required, you may try
     * lazy initialization. That is, initialize only when the application is really launched,
     * to accelerate bootup speed.
     *
     * Please register your event proc in BootupInitConfig.h
     *
     * Structure:
     *  srv_bootup_normal_init_evt_struct
     */
    EVT_ID_SRV_BOOTUP_NORMAL_INIT,

    /*
     * Before entering idle screen, this event will be emitted. At this step, almost
     * all initializations are completed, including SIM.
     *
     * Please register your event proc in BootupInitConfig.h
     *
     * Structure:
     *  srv_bootup_before_idle_evt_struct
     */
    EVT_ID_SRV_BOOTUP_BEFORE_IDLE,

    /*
     * The bootup flow has completed and entered idle screen. All application is possible
     * to be launched.
     *
     * Please register your event proc in BootupInitConfig.h
     *
     * Structure:
     *  srv_bootup_completed_evt_struct
     */
    EVT_ID_SRV_BOOTUP_COMPLETED,

    /*
     * SIM slots were initialized and we can know how many SIMs are inserted.
     * Available only if (MMI_MAX_SIM_NUM >= 2); that is, on multiple SIM projects.
     *
     * Structure:
     *  srv_bootup_sim_slot_ready_evt_struct
     */
    EVT_ID_SRV_BOOTUP_SIM_SLOT_READY,

    EVT_ID_SRV_BOOTUP_END_OF_ENUM
} srv_bootup_event_enum;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_BOOTUP_EARLY_INIT, to trigger applications'
 *  initializations more early.
 * SEE ALSO
 *  EVT_ID_SRV_BOOTUP_EARLY_INIT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    
    /*
     * MMI_TRUE if exception mode, the same as the return value of
     * srv_bootup_is_exception_mode(). Usually application does not care this
     * field, see the description of srv_bootup_is_exception_mode().
     */
    MMI_BOOL is_exception_mode;
} srv_bootup_early_init_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_BOOTUP_NORMAL_INIT, to notify applications do
 *  initializations.
 * SEE ALSO
 *  EVT_ID_SRV_BOOTUP_NORMAL_INIT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /*
     * MMI_TRUE if exception mode, the same as the return value of
     * srv_bootup_is_exception_mode(). Usually application does not care this
     * field, see the description of srv_bootup_is_exception_mode().
     */
    MMI_BOOL is_exception_mode;
} srv_bootup_normal_init_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_BOOTUP_BEFORE_IDLE, to notify it is going to
 *  idle first time.
 * SEE ALSO
 *  EVT_ID_SRV_BOOTUP_BEFORE_IDLE
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /*
     * MMI_TRUE if exception mode, the same as the return value of
     * srv_bootup_is_exception_mode(). Usually application does not care this
     * field, see the description of srv_bootup_is_exception_mode().
     */
    MMI_BOOL is_exception_mode;
} srv_bootup_before_idle_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_BOOTUP_COMPLETED, to notify the bootup flow
 *  has completed and entered idle screen.
 * SEE ALSO
 *  EVT_ID_SRV_BOOTUP_COMPLETED
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /*
     * MMI_TRUE if exception mode, the same as the return value of
     * srv_bootup_is_exception_mode(). Usually application does not care this
     * field, see the description of srv_bootup_is_exception_mode().
     */
    MMI_BOOL is_exception_mode;
} srv_bootup_completed_evt_struct;


#if (MMI_MAX_SIM_NUM >= 2)
/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_BOOTUP_SIM_SLOT_READY, which will be emitted
 *  on SIM slots were initialized.
 *  NOTE: Only supported on multiple SIM projects.
 *
 * SEE ALSO
 *  EVT_ID_SRV_BOOTUP_SIM_SLOT_READY
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    /* Number of SIMs inserted */
    S32 n_inserted;
    /* Bit set of SIM-inserted slots */
    U32 inserted_sims;
} srv_bootup_sim_slot_ready_evt_struct;
#endif


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_verification_is_passed
 * DESCRIPTION
 *  To query if all verfications of speficic protocol layer for bootup are passed.
 *  Note that the verification of a protocol layer is passed does NOT imply
 *  the SIM is available. Verfication passed means the verification on the SIM
 *  is no longer required. Maybe SIM blocked, SIM not inserted. User can use
 *  srv_sim_ctrl_is_available() to query the availability of SIM during booting.
 *  This function is only for the applications which can be launched during
 *  booting, need to know the verification status. But we suggest applications
 *  allow normal operations only after booting completed, do not use this function
 *  unless you really require. Query srv_bootup_is_completed() instead if possible.
 * PARAMETERS
 *  sim     : [IN] Which protocol layer
 * RETURNS
 *  MMI_TRUE if no verfication is required anymore.
 * SEE ALSO
 *  srv_bootup_get_verification_type
 *****************************************************************************/
extern MMI_BOOL srv_bootup_verification_is_passed(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_get_verification_type
 * DESCRIPTION
 *  Get the type of verfication currently required.
 * PARAMETERS
 *  sim                  : [IN] Which protocol layer
 *  n_remaining_attempts : [OUT] Number of remaining attempts. If equals to 0,
 *                               we can not do verification anymore.
 * RETURNS
 *  srv_bootup_verification_type_enum
 * SEE ALSO
 *  srv_bootup_is_verification_passed
 *****************************************************************************/
extern srv_bootup_verification_type_enum srv_bootup_get_verification_info(
                                            mmi_sim_enum sim,
                                            S32 *n_remaining_attempts);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_verify
 * DESCRIPTION
 *  Verfiy the password currently required.
 *  This function can be used only if srv_bootup_get_verification_type() ==
 *  SRV_BOOTUP_VERI_CHV1 or SRV_BOOTUP_VERI_PERSONALIZATION_LOCK.
 * PARAMETERS
 *  sim                 : [IN] Which SIM
 *  password            : [IN] UCS2-encoded string of password.
 *  result_callback     : [IN] Callback to return result.
 *  user_data           : [IN] The data pointer to be passed into result_callback().
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bootup_verify(
                mmi_sim_enum sim,
                const WCHAR *password,
                srv_bootup_verify_result_callback result_callback,
                void *user_data);


extern void srv_bootup_set_mode(void* msg);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_power_on_ind_hdlr
 * DESCRIPTION
 *  [For MMI framework only]
 *  The event handler of MMI_EQ_POWER_ON_IND.
 *  This handler stores the necessary information from the power-on indication,
 *  and start normal booting if the power-on mode is POWER_ON_KEYPAD or
 *  POWER_ON_EXCEPTION.
 * PARAMETERS
 *  msg     : [IN] mmi_eq_power_on_ind_struct*
 * RETURNS
 *  MMI_TRUE if the power-on mode is POWER_ON_KEYPAD or POWER_ON_EXCEPTION.
 *  Otherwise, returns MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_bootup_power_on_ind_hdlr(void *msg);

extern MMI_BOOL srv_bootup_sec_password_required_ind_hdlr(mmi_sim_enum sim, void *msg);
extern MMI_BOOL srv_bootup_sec_smu_fail_ind_hdlr(mmi_sim_enum sim, void *msg);

/* DOM-NOT_FOR_SDK-END */


#endif /* __SRV_BOOTUP_SRV_GPROT_H__ */


