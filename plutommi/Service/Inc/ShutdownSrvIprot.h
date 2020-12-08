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
 *  ShutdownSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Private interface of shutdown service.
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

#ifndef __SRV_SHUTDOWN_PROT_H__
#define __SRV_SHUTDOWN_PROT_H__


/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "ShutdownSrvGprot.h"


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_SHUTDOWN_NORMAL_START, to launch shutdown flow.
 * SEE ALSO
 *  EVT_ID_SRV_SHUTDOWN_NORMAL_START
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_shutdown_normal_start_evt_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_deinit
 * DESCRIPTION
 *  [INTERNAL]
 *  Emit deinit event to applications.
 *  srv_shutdown_is_running() will become TRUE only if deinit event emitted.
 *  If shutdown application wants to stop shutdown flow, do not emit event,
 *  to prevent the de-initialized application from being launched.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * SEE ALSO
 *  EVT_ID_SRV_SHUTDOWN_DEINIT
 *****************************************************************************/
extern void srv_shutdown_deinit(void);


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_shutdown_deinit_completed_callback
 * DESCRIPTION
 *  [INTERNAL]
 *  The function protocol type of deinit completed callback.
 * PARAMETERS
 *  user_data   : [IN] The data pointer passed into the srv_shutdown_deinit_protocol().
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_shutdown_deinit_completed_callback)(void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_shutdown_deinit_protocol
 * DESCRIPTION
 *  [INTERNAL]
 *  De-initialize protocol layer. After completed, the completed_callback will
 *  be called.
 * PARAMETERS
 *  completed_callback      : [IN] The callback to be notified completed.
 *  user_data               : [IN] To be passed into completed_callback().
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_shutdown_deinit_protocol(
                srv_shutdown_deinit_completed_callback completed_callback,
                void *user_data);


#endif /* __SRV_SHUTDOWN_PROT_H__ */

