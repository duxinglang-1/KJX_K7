/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_task.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  GDI task 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "task_main_func.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stack_init.h"
#include "stacklib.h"
#include "event_shed.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"

#include "gdi_include.h"
#include "gdi_internal.h"
#include "gdi_2d_engine.h"
#include "gdi_layer.h"


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 typedef struct
 {
     gdi_msg_id_enum id; 
     void *arg;
 } gdi_msg_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void gdi_task_main(task_entry_struct *task_entry_ptr);
static kal_bool gdi_task_init(task_indx_type task_indx);

 
/***************************************************************************** 
 * Local Function
 *****************************************************************************/

 /*****************************************************************************
  * FUNCTION
  *  gdi_task_process_msg
  * DESCRIPTION
  *  Processes a message.
  * PARAMETERS
  *  ilm       [IN]  message pointer
  * RETURNS
  *  void
  *****************************************************************************/
static void gdi_task_process_msg(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (ilm->msg_id)
    {
    #if 0 //not currently use now (reserve for future usage) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    #ifdef GDI_GOVL_SUPPORT
        case MSG_ID_GDI_GOVL_FLATTEN_CALLBACK_IND:
            gdi_layer_govl_nb_callback_ind_handler();   
            break;
    #endif
    
        case MSG_ID_GDI_G2D_FILL_RECT_CALLBACK_IND:
            gdi_2d_fill_rect_callback_ind_handler();
            break;
            
        default:
            GDI_ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gdi_task_init
 * DESCRIPTION
 *  GDI Task init function
 * PARAMETERS
 *  task_indx       [IN]    task index
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
static kal_bool gdi_task_init(task_indx_type task_indx)
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
 *  gdi_task_main
 * DESCRIPTION
 *  GDI Task main function
 * PARAMETERS
 *  task_entry_ptr       [IN]   task entry structure
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 task_index;

    ilm_struct ilm;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&task_index);

    while (1)
    {
        /* 
         * Idle message loop
         */

        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &ilm);
        stack_set_active_module_id(task_index, ilm.dest_mod_id);
        gdi_task_process_msg(&ilm);
        free_ilm(&ilm);
    }
}



/*****************************************************************************
 * FUNCTION
 *  gdi_create_task
 * DESCRIPTION
 *  Task create function
 * PARAMETERS
 *  handle      [IN]    task create handle
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
kal_bool gdi_create_task(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static comptask_handler_struct gdi_handler_info = 
    {
        gdi_task_main,   /* task entry function */
        gdi_task_init,   /* task initialization function */
        NULL,       /* task configuration function */
        NULL,  /* task reset handler */
        NULL        /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    *handle = (comptask_handler_struct*)&gdi_handler_info;
    
    return KAL_TRUE;
}
