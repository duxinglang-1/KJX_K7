/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   wps_exec.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the execution control of WPS task.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_api.h"        /* Basic data type */

/* Timer Management  */
#include "stacklib.h"
#include "stack_common.h"
#include "kal_public_defs.h"
#include "stack_ltlcom.h" /* Task message communiction */
#include "app_str.h"
#include "event_shed.h" /* event schedulet */
#include "stack_timer.h"

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "msf_cfg.h"
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "int_exec.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/* Handle WPS primitives */
extern void wps_fsm(ilm_struct *ilm_ptr);

#if 0 
/* under construction !*/
/* under construction !*/
#endif /* 0 */

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
static int wps_current_mod_id;

int wps_get_current_mod_id(void)
{
    return wps_current_mod_id;
}
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

extern kal_mutexid wap_ctrl_mutex;


#ifdef MSF_NEW_EXCEPTION_HANDLING
mtk_jmpbuf wps_task_jmpbuf;
static kal_bool wps_in_critical_section = KAL_FALSE;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  wps_init
 * DESCRIPTION
 *  This function should be called to Initialize the WAP PS task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wps_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wps_reset
 * DESCRIPTION
 *  This function should be called to reset the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wps_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wps_task_main
 * DESCRIPTION
 *  This function is used to be WAP PS task entry point
 * CALLS
 *  
 * PARAMETERS
 *  task_entry_ptr      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    while (1)
    {
         msg_receive_extq_for_stack(&current_ilm);

        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);
#ifdef MSF_NEW_EXCEPTION_HANDLING
		if (setjmp(wps_task_jmpbuf) == 0)
		{
        wps_fsm(&current_ilm);  /* process external ILM */
    }
		else
		{
			if(wps_in_critical_section == KAL_TRUE)
			{
				wps_in_critical_section = KAL_FALSE;
				kal_give_mutex(wap_ctrl_mutex);
			}

			msg_send6(MOD_WPS, MOD_WAP, WPS_APP_SAP, MSG_ID_WAP_INTERNAL_ERROR_IND,  (local_para_struct*) NULL, (peer_buff_struct*) NULL);
		}
#else
        wps_fsm(&current_ilm);  /* process external ILM */
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_create
 * DESCRIPTION
 *  This function is used to create WAP PS task
 * CALLS
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wps_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(WPS_TASK_SUPPORT)
    static const comptask_handler_struct ms_handler_info = 
    {
        wps_task_main,  /* task entry function */
        wps_init,       /* task initialization function */
        NULL,           /* task configuration function */
        wps_reset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    *handle = (comptask_handler_struct*) & ms_handler_info;
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif 
}

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  MSF_wps_fsm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MSF_wps_fsm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool run = KAL_TRUE;
    kal_uint8 i;
    extern kal_bool wap_in_critical_section;
    extern int isSignalPending(module_type mod_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(wap_ctrl_mutex);
    wps_in_critical_section = wap_in_critical_section = KAL_TRUE;
    
    while (run)
    {
        run = KAL_FALSE;

        for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
        {
            if(((msf_modules[i].taskId == MOD_WPS)) && (msf_modules[i].isActive))
            {
                wps_current_mod_id = msf_modules[i].moduleId;
                if (msf_modules[i].pTaskWantsToRun())
                {
                    msf_modules[i].pTaskRun();
                    run = KAL_TRUE;
                }
                wps_current_mod_id = -1;
            }
        }
    }

    wps_in_critical_section = wap_in_critical_section = KAL_FALSE;
    kal_give_mutex(wap_ctrl_mutex);

    /* send the wake-up primitive to WAP task whenever WPS finish its jog */
    if (isSignalPending(MOD_WAP))
    {
        extern void hdi_notify_task(module_type src, module_type dst, msg_type msg_id);

        hdi_notify_task(MOD_WPS, MOD_WAP, MSG_ID_WPS_EXT_MSG_IND);
    }
    if (isSignalPending(MOD_MMS))
        {
        extern void hdi_notify_task(module_type src, module_type dst, msg_type msg_id);

        hdi_notify_task(MOD_WPS, MOD_MMS, MSG_ID_WAP_STATUS_UPDATE_IND);
    }
    if (isSignalPending(MOD_WPS) && (run == KAL_TRUE))
    {
        extern void hdi_notify_task(module_type src, module_type dst, msg_type msg_id);

        hdi_notify_task(MOD_WPS, MOD_WPS, MSG_ID_WAP_STATUS_UPDATE_IND);
    }
}
#endif /* WPS_TASK_SUPPORT */ 

