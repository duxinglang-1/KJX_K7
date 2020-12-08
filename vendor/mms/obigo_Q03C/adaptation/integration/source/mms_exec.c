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
 *   mms_exec.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the execution control of MMS task.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_platform.h"
#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#include "kal_public_api.h"

#include "kal_public_defs.h" 
#include "stack_ltlcom.h"


#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"        /* Stack timer */

#include "fat_fs.h"             /* file system */
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */ 
#include "stack_ltlcom.h"
#include "FileManagerGProt.h"
#include "fmt_struct.h"

#include "wps_struct.h"
#include "mms_adp_struct.h"

#include "msf_def.h"
#include "msf_cfg.h"
#include "int_exec.h"
#include "int_cmmn.h"
#include "int_timer.h"
#include "msm_int.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif

#include "msm.h"
static int update_ind_sent;
static kal_uint8 mms_sim_status;
static kal_uint8 mms_sim_setting_mode;
static kal_uint32 g_mms_poweroff_req_id = 0;

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
extern void 
gmms_HDIa_send_filemove_response_signal_to_msm(MSF_INT32 result);
#endif
mtk_jmpbuf mms_jmpbuf;  /* Buffer for longjmp */
/*****************************************************************************
 * FUNCTION
 *  mms_get_sim_status
 * DESCRIPTION
 *  This function is to return current dual SIM status
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mms_get_sim_status(void)
{
    return mms_sim_status;
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_sim_setting_mode
 * DESCRIPTION
 *  This function is to return current dual SIM settings
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  SIM setting mode
 *****************************************************************************/
kal_uint8 mms_get_sim_setting_mode(void)
{
    return mms_sim_setting_mode;
}

#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
/*****************************************************************************
 * FUNCTION
 *  mms_send_fmt_format_rsp
 * DESCRIPTION
 *  This function is used to send FMT format response
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_send_fmt_format_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    mmi_fmt_format_rsp_strcut *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_fmt_format_rsp_strcut*) construct_local_para((kal_uint16) sizeof(mmi_fmt_format_rsp_strcut), TD_RESET);
    rsp->result = FS_NO_ERROR;

    ilm_ptr = allocate_ilm(MOD_MMS);
    ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_RSP; /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;                  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp;
    SEND_ILM(MOD_MMS, MOD_FMT, INVALID_SAP, ilm_ptr);
}
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */


/*****************************************************************************
 * FUNCTION
 *  mms_send_poweroff_rsp
 * DESCRIPTION
 *  This function is used to notify MMI that MMS poweroff procedure is completed
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mms_send_poweroff_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int is_called = 0;    /* it should be called only once */

    ilm_struct *ilm_ptr = NULL;
    mms_poweroff_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_called)
    {
        return;
    }
    is_called = 1;

    rsp = (mms_poweroff_struct*) construct_local_para((kal_uint16) sizeof(mms_poweroff_struct), TD_RESET);
    rsp->request_id = g_mms_poweroff_req_id;
    g_mms_poweroff_req_id = 0;

    ilm_ptr = allocate_ilm(MOD_MMS);
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMS_POWEROFF_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp;
    SEND_ILM(MOD_MMS, MOD_MMI, INVALID_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  run_mms_task
 * DESCRIPTION
 *  Send one primitive to MMS message queue to allow execution next time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void run_mms_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    kal_uint32 num_of_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_ind_sent)
    {
        return;
    }

    if (msg_get_ext_queue_info(task_info_g[INDX_MMS].task_ext_qid, &num_of_msg) && num_of_msg > 0)
        return;

    update_ind_sent = 1;

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_MMS);
    ilm_ptr->msg_id = MSG_ID_WAP_STATUS_UPDATE_IND; /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;                  /* there are no peer message */
    ilm_ptr->local_para_ptr = NULL;                 /* there are no local message */
    ilm_ptr->src_mod_id  = MOD_MMS;
    ilm_ptr->dest_mod_id = MOD_MMS;
    ilm_ptr->sap_id = INVALID_SAP;
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  get_wps_status
 * DESCRIPTION
 *  To query if wap protocol stack has been up running
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void get_wps_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_MMS);
    ilm_ptr->msg_id = MSG_ID_WPS_STATUS_QUERY_REQ; /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;                  /* there are no peer message */
    ilm_ptr->local_para_ptr = NULL;                 /* there are no local message */
    ilm_ptr->src_mod_id  = MOD_MMS;
    ilm_ptr->dest_mod_id = MOD_WPS;
    ilm_ptr->sap_id = WPS_APP_SAP;
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mms_fsm
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mms_fsm(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    int is_msg_handled = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
    {
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
        if (msf_modules[i].taskId == MOD_MMS && msf_modules[i].isActive && msf_modules[i].pMsgHdlr)
#else
        if (msf_modules[i].isActive && msf_modules[i].pMsgHdlr)
#endif
        {
            if (msf_modules[i].pMsgHdlr((void*)ilm_ptr) == TRUE)
            {
                is_msg_handled = TRUE;
                break;
            }
        }
    }

    if (!is_msg_handled)
    {
        is_msg_handled = TRUE;
        switch (ilm_ptr->msg_id)
        {
            case MSG_ID_WAP_STATUS_UPDATE_IND:
                update_ind_sent = 0;
                break;
            case MSG_ID_WPS_READY_IND:
                if (mms_status == MMS_STATUS_NULL)
                {                    
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
                    mms_start_framework();
#endif
                }
                break;
            case MSG_ID_TIMER_EXPIRY:
                switch(evshed_get_index(ilm_ptr))
                {
                    case MSF_FILE_TIMER_ID:
                        hdi_file_timer_expiry_hdlr();
                        break;
                    case MSF_MSM_TIMER_ID:
                        mms_timer_expiry_hdlr();
                        break;
                }
                break;
#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
             case MSG_ID_MMI_FMT_FORMAT_REQ:
                {
                    kal_wap_trace(MOD_MMS, TRACE_FUNC, "sandeep: mms_send_fmt_format_rsp from Framework");
                    mms_send_fmt_format_rsp();
                }
                break;
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */
            case MSG_ID_WAP_INTERNAL_ERROR_IND:
                /*mms_action = MMS_ACTION_RESET;
                mms_stop_framework();*/
                break;
            case MSG_ID_MMS_POWEROFF_REQ:
            {
                mms_action = MMS_ACTION_NONE;
                /* If MMS is currently running and is not in initialization process, then terminate MMS first. */
                g_mms_poweroff_req_id = ((mms_poweroff_struct*)ilm_ptr->local_para_ptr)->request_id;
                if (mms_status == MMS_STATUS_ACTIVE)
                {
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
                    mms_stop_framework();
#endif
                }
                else
                {
                    /* If wap task is not yet done with initialization, then do not perform termination
                       to avoid unexpected problems. Simply let the shutdown process continue. */
                    mms_status = MMS_STATUS_TERMINATED;
                }
                break;
            }
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#ifdef __MMS_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif                    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
			case MSG_ID_MMS_FMT_FILE_MOVE_PROCESSING_IND:					
					{
						mmi_fmt_op_abort_processing_ind_struct *p = (mmi_fmt_op_abort_processing_ind_struct*)ilm_ptr->local_para_ptr;
						gmms_HDIa_send_filemove_response_signal_to_msm(p->result);						
					}
					break;		
#endif /* __NON_BLOCKING_FILE_MOVE_SUPPORT__ */
            default:
            #ifdef __DRM_SUPPORT__
                is_msg_handled = DRM_app_common_hdlr(ilm_ptr);
            #else
                is_msg_handled = FALSE;
            #endif
                break;
        }
    }

    free_ilm(ilm_ptr);

    /* Continue the execution of internal modules */
    if (is_msg_handled)
    {
        mms_execute_framework();
    }
    if(mms_status == MMS_STATUS_TERMINATED)
    {
        if(mms_action == MMS_ACTION_NONE)
        {
            mms_send_poweroff_rsp();
            return;
        }
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
        mms_init_framework();
        
        mms_start_framework();
#endif
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mms_init
 * DESCRIPTION
 *  This function should be called to Initialize the WAP PS task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mms_init(task_indx_type task_indx)
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
 *  mms_reset
 * DESCRIPTION
 *  This function should be called to reset the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mms_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*mms_action = MMS_ACTION_RESET;
    mms_stop_framework();*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mms_task_main
 * DESCRIPTION
 *  This function is used to be WAP PS task entry point
 * CALLS
 *  
 * PARAMETERS
 *  task_entry_ptr      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mms_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_init_framework();

    /* To register wps status to continue startup after receiving status update */
    get_wps_status();
    
    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);
		if (setjmp(mms_jmpbuf) == 0)
		{
        mms_fsm(&current_ilm);  /* process external ILM */
    }
		else
		{
			ilm_struct *ilm_ptr = NULL;
			ilm_ptr = allocate_ilm(MOD_MMS);
			ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
			ilm_ptr->msg_id = MSG_ID_WAP_INTERNAL_ERROR_IND;
			ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
			SEND_ILM(MOD_MMS, MOD_WAP, INVALID_SAP /*Add correct sap*/, ilm_ptr);
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_create
 * DESCRIPTION
 *  This function is used to create WAP PS task
 * CALLS
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mms_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct ms_handler_info = 
    {
        mms_task_main,  /* task entry function */
        mms_init,       /* task initialization function */
        NULL,           /* task configuration function */
        mms_reset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    *handle = (comptask_handler_struct*) & ms_handler_info;
    return KAL_TRUE;
}
