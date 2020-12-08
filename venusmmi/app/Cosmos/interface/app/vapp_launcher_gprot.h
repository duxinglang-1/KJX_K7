/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher_gprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the external interface for launcher APP.
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

#ifndef VAPP_LAUNCHER_GPROT_H
#define VAPP_LAUNCHER_GPROT_H

#include "MMI_features.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"


/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_VAPP_LAUNCHER_ACTIVE. */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} vapp_launcher_active_evt_struct;

/* This is the structure for the EVT_ID_VAPP_LAUNCHER_INACTIVE. */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} vapp_launcher_inactive_evt_struct;


/*****************************************************************************
 * Structure
 *****************************************************************************/

/* Parameter structure for the launcher launch function. */
typedef struct
{
    mmi_id base_app_id;
} vapp_launcher_launch_param_struct;


/*****************************************************************************
 * Function
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_launcher_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret vapp_launcher_main_evt_hdlr(mmi_event_struct *event);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_launch
 * DESCRIPTION
 *  This function launches the launcher.
 * PARAMETERS
 *  void
 * RETURNS
 *  Group ID of launcher App.
 *****************************************************************************/
extern MMI_ID vapp_launcher_launch(void *param, U32 param_size);


/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_display
 * DESCRIPTION
 *  This function displays the launcher.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_launcher_display();


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_restart
 * DESCRIPTION
 *  This function restarts the launcher.
 *
 *  DO NOT CALL THIS FUNCTION UNLESS YOU KNOW CLEARLY WHAT THIS FUNCTION DOES.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  Group ID of launcher App.
 *****************************************************************************/
extern MMI_ID vapp_launcher_restart();

/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_reload
 * DESCRIPTION
 *  This function re-creat launcher object.
 *
 *  DO NOT CALL THIS FUNCTION UNLESS YOU KNOW CLEARLY WHAT THIS FUNCTION DOES.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_ID vapp_launcher_reload();
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  vapp_launcher_is_active
 * DESCRIPTION
 *  This function checks if the launcher App is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL vapp_launcher_is_active();


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* VAPP_LAUNCHER_GPROT_H */

