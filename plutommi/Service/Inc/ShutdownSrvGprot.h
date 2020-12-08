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
 *  ShutdownSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Global interface of shutdown service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_SHUTDOWN_GPROT_H__
#define __SRV_SHUTDOWN_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_is_running
 * DESCRIPTION
 *  Shutdown has been triggered and running.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if shutdown is running.
 *****************************************************************************/
extern MMI_BOOL srv_shutdown_is_running(void);

/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_normal_start
 * DESCRIPTION
 *  Launch normal shutdown flow.
 *  It plays shutdown animation and emit deinit events normally.
 * PARAMETERS
 *  trigger_man_app_id  : [IN] The ID of the application who triggers shutdown.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_shutdown_normal_start(MMI_ID trigger_man_app_id);

/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_exit_system
 * DESCRIPTION
 *  Power-down system directly, and do not care normal applications.
 *  It is also the final step of normal shutdown, FINAL_DEINIT will be emitted
 *  at this step.
 * PARAMETERS
 *  trigger_man_app_id  : [IN] The ID of the application who triggers shutdown.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_shutdown_exit_system(MMI_ID trigger_man_app_id);


/****************************************************************************
 * Events
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Event IDs of shutdown events.
 */
typedef enum
{
    /*
     * [INTERNAL]
     * Internal event to launch normal shutdown flow. Shutdown application core
     * will take over the control flow as received this event.
     *
     * SEE ALSO
     *  srv_shutdown_normal_start_evt_struct
     */
    EVT_ID_SRV_SHUTDOWN_NORMAL_START = SRV_SHUTDOWN_BASE, 
    
    /*
     * The first event of normal shutdown to applications. 
     * This event will be emitted if shutdown is triggered and starting to run.
     * Applications can listen to this event to de-initialize their module.
     * However, it will NOT be emitted for abnormal shutdown, e.g., low-power,
     * USB power-on mode, etc.
     *
     * SEE ALSO
     *  srv_shutdown_deinit_evt_struct
     */
    EVT_ID_SRV_SHUTDOWN_DEINIT,
    
    /*
     * The protocol event handlers of framework was all cleared.
     * If application needs to listen protocol events even in shutdown period,
     * this event should be subscribed to re-register handlers.
     *
     * SEE ALSO
     *  srv_shutdown_handler_reset_evt_struct
     */
    EVT_ID_SRV_SHUTDOWN_HANDLER_RESET,
    
    /*
     * The final event of shutdown. System is going to power off very soon.
     *
     * SEE ALSO
     *  srv_shutdown_final_deinit_evt_struct
     */
    EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT,

    EVT_ID_SRV_SHUTDOWN_END_OF_ENUM
} srv_shutdown_event_enum;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SHUTDOWN_DEINIT, to notify applications that
 *  system is going to shutdown.
 * SEE ALSO
 *  EVT_ID_SRV_SHUTDOWN_DEINIT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_shutdown_deinit_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SHUTDOWN_HANDLER_RESET, to notify applications that
 *  all protocol event handlers has been cleared. If application needs to re-register
 *  handlers, it should listen to this event.
 * SEE ALSO
 *  EVT_ID_SRV_SHUTDOWN_HANDLER_RESET
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_shutdown_handler_reset_evt_struct;

/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT, the final deinit event.
 *  If this event is emitted, system is going to power-down very soon.
 * SEE ALSO
 *  EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_shutdown_final_deinit_evt_struct;

#endif /* __SRV_SHUTDOWN_GPROT_H__ */

