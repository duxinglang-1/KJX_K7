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
 *   cal_high_task_main.c
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   CAL_HIGH task interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */

#include "cal_api.h"
#include "cal_comm_def.h"
#include "cal_if.h"
#include "cal_drv_features.h"
#include "cal_task_msg_if.h"

#ifdef __CAL_NEED_SW_ROTATE__
/*****************************************************************************
 * FUNCTION
 *  CalHighMsgHandle
 * DESCRIPTION
 *  This function is main message dispatching function of CAL High task.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalHighMsgHandle(ilm_struct *pIlmPtr)
{
    switch (pIlmPtr->msg_id)
    {
        case MSG_ID_CAL_ROTATE_IMAGE_REQ:
            ImageRotHandle(pIlmPtr);
        break;
        default:
            ASSERT(0);
    }
} /* CalHighMsgHandle() */


/*****************************************************************************
 * FUNCTION
 *  CalHighTaskMain
 * DESCRIPTION
 *  This function is main function of CAL HIGH task.
 * PARAMETERS
 *  task_entry_ptr      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void CalHighTaskMain(task_entry_struct *pTaskEntry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct CurrentIlm;
    kal_uint32 CalHighTaskIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&CalHighTaskIndex);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[CalHighTaskIndex].task_ext_qid, &CurrentIlm);
        stack_set_active_module_id(CalHighTaskIndex, CurrentIlm.dest_mod_id);

        CalHighMsgHandle(&CurrentIlm);

        free_ilm(&CurrentIlm);
    }
} /* CalHighTaskMain() */

/*****************************************************************************
 * FUNCTION
 *  CalHighTaskInit
 * DESCRIPTION
 *  This function is used to init CAL_HIGH task.
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalHighTaskInit(task_indx_type task_indx)
{
    /* init stack timer */
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  CalHighTaskReset
 * DESCRIPTION
 *  This function is used to reset CAL_HIGH task.
 * PARAMETERS
 *  task_indx       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalHighTaskReset(task_indx_type task_indx)
{
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  CalHighTaskCreate
 * DESCRIPTION
 *  This function is used to create media task configuration info.
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool CalHighTaskCreate(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct CalHighHandlerInfo =
    {
        CalHighTaskMain,    /* task entry function */
        CalHighTaskInit,    /* task initialization function */
        NULL,           /* task configuration function */
        CalHighTaskReset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & CalHighHandlerInfo;

    return KAL_TRUE;
}   /* CalHighTaskReset() */
#endif /* __CAL_FD_NEED_SW_ROTATE__ */
