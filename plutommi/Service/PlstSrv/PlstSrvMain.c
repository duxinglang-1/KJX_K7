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
 *  PlstSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  palyer list service task main functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "kal_public_defs.h"
#include "kal_release.h"
#include "task_main_func.h"
#include "kal_active_module.h"
#include "task_config.h"
#include "hisr_config.h"
#include "syscomp_config.h"

#if defined(__PLST_SERVICE_DB_SUPPORT__)
#include "PlstSrvGprot.h"
#include "PlstSrv.h"
#include "PlstSrvpls.h"
#endif

#if defined(__MMI_MOT_SUPPORT__)
#include "MotSrvGprot.h"
#endif

#if defined(__PLST_SERVICE_DB_SUPPORT__)
static pls_ps_cntx_struct g_pls_db;
pls_ps_cntx_struct* g_pls_db_cntx= &g_pls_db;
#endif

/*****************************************************************************
 * FUNCTION
 *  pls_main
 * DESCRIPTION
 *  player list service task main MSG loop
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MOT_SUPPORT__)
    if (ilm_ptr->msg_id >= MSG_ID_MOT_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MOT_CODE_END)
    {

        srv_mot_main(ilm_ptr);
    }
    else
#endif
    {
    #if defined(__PLST_SERVICE_DB_SUPPORT__)
        pls_db_msg_handler(ilm_ptr);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  pls_task_main
 * DESCRIPTION
 *  player list service task main function
 * PARAMETERS
 *  *task_entry_ptr    [IN]    task entry structure
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32   my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);
    stack_set_active_module_id (my_index, MOD_PLS);

    while (1)
    {
        receive_msg_ext_q_for_stack( task_info_g[task_entry_ptr->task_indx].task_ext_qid,
                         &current_ilm);
        pls_main(&current_ilm);
        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pls_init
 * DESCRIPTION
 *  player list service task init function
 * PARAMETERS
 *  *task_indx    [IN]    task index
 * RETURNS
 *  KAL_TRUE init OK
 *****************************************************************************/
kal_bool pls_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__PLST_SERVICE_DB_SUPPORT__)
    g_pls_db_cntx->g_pls_event = kal_create_event_group("pls_evt");
#endif
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pls_reset
 * DESCRIPTION
 *  player list service task reset function
 * PARAMETERS
 *  *task_indx    [IN]    task index
 * RETURNS
 *  KAL_TRUE    reset OK
 *****************************************************************************/
static kal_bool pls_reset( task_indx_type task_indx )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/******************************************************************
 * FUNCTION
 *    pls_create
 * DESCRIPTION
 *  player list service  task create function
 * PARAMETERS
 *  *handle    [IN]    task handle
 * RETURNS
 *  KAL_TRUE    create OK
 ******************************************************************/
kal_bool pls_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct pls_handler_info =
    {
       pls_task_main,          /* task entry function */
       pls_init,               /* task initialization function */
       NULL,                   /* task configuration function */
       pls_reset,              /* task reset handler */
       NULL,                   /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   *handle = (comptask_handler_struct*)&pls_handler_info;
    return KAL_TRUE;
}


