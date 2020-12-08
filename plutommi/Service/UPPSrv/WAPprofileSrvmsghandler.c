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
 * WAPProfileSrvMsgHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for message / interface handling for profile module.
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
//#include "MMI_include.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef WAP_SUPPORT

#include "WAPProfSrvConfig.h"
#include "WAPProfileSrvType.h"
#include "WAPProfileSrvProt.h"

//------------------------------ suggest Add ------------------------------

#include "stack_config.h"
#include "stack_msgs.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"

#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
//------------------------------ usage ------------------------------

    
#ifndef __SRV_UPP_SLIM__


/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_send_process_job_queue_ind
 * DESCRIPTION
 *  Sends process job queue indication to UPP itself.
 *  PARAMETERS:
 *  void
 *  sim_id(?)
 *  app_id(?)
 *  content(?)
 *****************************************************************************/
void srv_wap_prof_send_process_job_queue_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_prof_send_msg(MOD_MMI, MSG_ID_MMI_WAP_PROF_PROCESS_JOB_QUEUE_IND, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_process_job_queue_ind_hdlr
 * DESCRIPTION
 *  Handler for processing job queue.
 *  
 *  PARAMETERS:
 *  msg     [?]     
 *****************************************************************************/
void srv_wap_prof_process_job_queue_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_WAP_PROF_READY != g_srv_wap_prof_cntx.module_status)
    {
/*        MMI_PRINT(MMI_WAP_PROF_MOD_INET_APP, MMI_WAP_PROF_TRC_GRP9, "[WAP_PROF] Process job fail, Profile is busy status = %d", g_srv_wap_prof_cntx.module_status); */
        MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ERR_PROCESS_JOB_FAIL_PROFILE_BUSY, g_srv_wap_prof_cntx.module_status);

        /* job will be processed when ready. */
        return;
    }

    srv_wap_prof_process_job();
}


#endif

/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_send_msg
 * DESCRIPTION
 *  Send message to other modules
 *  
 *  PARAMETERS:
 *  dst_mod_id          [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 *****************************************************************************/
void srv_wap_prof_send_msg(U16 dst_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
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
#endif
	mmi_frm_send_ilm((oslModuleType) dst_mod_id,(oslMsgType) msg_id, 
                        (oslParaType *)local_param_ptr, (oslPeerBuffType *)peer_buf_ptr);

}


#endif /* WAP_SUPPORT */
