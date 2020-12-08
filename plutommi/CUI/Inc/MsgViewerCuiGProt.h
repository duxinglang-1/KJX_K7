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

/*******************************************************************************
 * Filename:
 * ---------
 * MsgViewerCuiGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_MSGVIEWERCUI_GPROT_H
#define CUI_MSGVIEWERCUI_GPROT_H

#include "UMSrvDefs.h"
#include "UmSrvGprot.h"

/*****************************************************************************
 * To identify the message viewer's type 
 ****************************************************************************/
typedef enum
{
    CUI_MSG_VIEWER_TYPE_INVALID,            /* Starting point of this enum */
    CUI_MSG_VIEWER_TYPE_NORMAL,             /* Normal viewer */
    CUI_MSG_VIEWER_TYPE_ITERATOR,           /* Iterator viewer */
    CUI_MSG_VIEWER_TYPE_CSK_KEY,         /* CSK viewer, for MMS widget only*/
    CUI_MSG_VIEWER_TYPE_INTUITIVE_CMD,         /* TAP viewer, for MMS widget only */
    CUI_MSG_VIEWER_TYPE_TOTAL               /* The end of cui_msg_viewer_type_enum */
} cui_msg_viewer_type_enum;

/*****************************************************************************
 * <GROUP Event>
 * Message viewer's event. This event sends to caller to notify the currnet 
 * situation. 
 ****************************************************************************/
typedef enum
{
    EVT_ID_CUI_MSG_VIEWER_CLOSE = CUI_MSG_VIEWER_BASE,      /* Notify the caller should close this viewer */
    EVT_ID_CUI_MSG_VIEWER_TOTAL                             /* The end of cui_msg_viewer_event_enum */
} cui_msg_viewer_event_enum;

/*****************************************************************************
 * <GROUP Event>
 * Event structure of message viewer 
 ****************************************************************************/
typedef struct  
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
} cui_msg_viewer_event_struct;

/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_launch_ptr
 * DESCRIPTION
 *  General launching function for each different message viewer, such as SMS
 *  viewer, MMS viewer and so on.
 *
 * PARAMETERS
 *  parent_grp_id:  [IN]    The parent groupd id
 *  msg_id:         [IN]    The unique message id
 *  user_data:      [IN]    This message viewer instance's user data
 *  type:           [IN]    Opening type of viewer. Please refer to 
 *                          cui_msg_viewer_type_enum
 *
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*cui_msg_viewer_launch_ptr)(mmi_id parent_grp_id, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_create
 * DESCRIPTION
 *  Create message viewer cui instance.
 * PARAMETERS
 *  grp_id:         [IN]    Parent group id
 *  msg_id:         [IN]    Msg id to view
 *  msg_type:       [IN]    Msg type to view
 *  flag:           [IN]    reserved
 * RETURNS
 *  Group id of current message viewer instance
 * RETURN VALUES
 *  Group id
 *****************************************************************************/
extern mmi_id cui_msg_viewer_create(mmi_id parent_grp_id, U32 msg_id, srv_um_msg_enum msg_type, U32 flag);

extern void cui_msg_viewer_set_widget_csk_invoke(mmi_id group_id);
extern void cui_msg_viewer_set_widget_tap_invoke(mmi_id group_id);

/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_run
 * DESCRIPTION
 *  Run message viewer cui instance.
 * PARAMETERS
 *  grp_id:         [IN]    Group id
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_run(mmi_id grp_id);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_close
 * DESCRIPTION
 *  Close message viewer cui instance.
 * PARAMETERS
 *  grp_id:         [IN]    Group id
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_close(mmi_id grp_id);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_set_style
 * DESCRIPTION
 *  Set the style of current viewer. It should call before cui_msg_viewer_run.
 * PARAMETERS
 *  grp_id:         [IN]    Parent group id
 *  type:           [IN]    Type of viewer
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_set_style(mmi_id grp_id, cui_msg_viewer_type_enum type);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_set_msg_list
 * DESCRIPTION
 *  Set the message list of current viewer. After set the list to viewer, it
 *  could support iterator feature
 * PARAMETERS
 *  grp_id:         [IN]    Parent group id
 *  msg_list:       [IN]    The message list
 *  msg_list_size:  [IN]    The size of message list
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_set_msg_list(mmi_id grp_id, srv_um_msg_node_struct *msg_list, U16 msg_list_size);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_rel_msg_list
 * DESCRIPTION
 *  Release the message list from current viewer. If it does not set any new
 *  message list to this viewer instance, it will display a loading always.
 * PARAMETERS
 *  grp_id:         [IN]    Parent group id
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_rel_msg_list(mmi_id grp_id);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_init
 * DESCRIPTION
 *  Initialize all viewer instances.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_init(void);
#endif /* CUI_MSGVIEWERCUI_GPROT_H */

