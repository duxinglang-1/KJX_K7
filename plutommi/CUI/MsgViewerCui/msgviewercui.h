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
 * MsgViewerCui.h
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
#ifndef CUI_MSGVIEWERCUI_H
#define CUI_MSGVIEWERCUI_H

#include "UmSrvDefs.h"
#include "MsgViewerCuiGProt.h"
/* This file is used by MMI task, Please use MMI type if possible */

#define CUI_MSG_VIEWER_MAX_INSTANCE 1

#define CUI_MSG_VIEWER_CHECK_INST_VALID(inst)       \
{                                                   \
    MMI_ASSERT(NULL != inst);                       \
    MMI_ASSERT(GRP_ID_INVALID != inst->group_id);   \
}

typedef enum
{
    CUI_MSG_VIEWER_STATUS_INVALID, 
    CUI_MSG_VIEWER_STATUS_INIT, 
    CUI_MSG_VIEWER_STATUS_READY, 
    CUI_MSG_VIEWER_STATUS_NO_MSG_LIST, 
    CUI_MSG_VIEWER_STATUS_DEINIT
} cui_msg_viewer_status_enum;

typedef struct
{
    mmi_id parent_grp_id;
    mmi_id group_id;
    mmi_id scrn_id;
    cui_msg_viewer_type_enum type;
    cui_msg_viewer_status_enum status;
    U32 curr_msg_id;
    srv_um_msg_enum curr_msg_type;
    void *msg_list;
} cui_msg_viewer_inst_struct;


typedef struct
{
    mmi_id base_scrn_id;
    cui_msg_viewer_inst_struct inst_table[CUI_MSG_VIEWER_MAX_INSTANCE];
} cui_msg_viewer_cntx_struct;


extern cui_msg_viewer_cntx_struct g_cui_msg_viewer;
extern cui_msg_viewer_cntx_struct *g_cui_msg_viewer_p;

/*****************************************************************************
 *  Adaptor                                                                  *
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_adp_get_viewer_ptr
 * DESCRIPTION
 *  Get the message application viewer pointer.
 * PARAMETERS
 *  msg_type        [IN]    The message type.
 * RETURNS
 *  The Launched viewr pointer
 * RETURN VALUES
 *  Message viewer unction pointer
 *****************************************************************************/
extern cui_msg_viewer_launch_ptr cui_msg_viewer_adp_get_viewer_ptr(srv_um_msg_enum msg_type);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_adp_launch_viewer_ptr
 * DESCRIPTION
 *  Launch the message application viewer pointer.
 * PARAMETERS
 *  msg_id          [IN]    The message id.
 *  msg_type        [IN]    The message type.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_adp_launch_viewer_ptr(srv_um_msg_enum msg_type, 
                                                 mmi_id parent_grp_id, 
                                                 U32 msg_id, 
                                                 void *user_data, 
                                                 cui_msg_viewer_type_enum type);


/*****************************************************************************
 *  Kernel                                                                   *
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_create_instance
 * DESCRIPTION
 *  Create a instance for message viewer cui. It is only allocate a usable
 *  memory to this instance.
 * PARAMETERS
 *  void
 * RETURNS
 *  The instance pointer of message viewr cui.
 * RETURN VALUES
 *  Pointer of memory
 *****************************************************************************/
extern cui_msg_viewer_inst_struct *cui_msg_viewer_create_instance(void);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_rel_instance
 * DESCRIPTION
 *  Release a instance for message viewer cui. It will free the memory from
 *  cui side.
 * PARAMETERS
 *  inst:           [IN]    Message viewer cui instance pointer.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_rel_instance(cui_msg_viewer_inst_struct *inst);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_get_instance
 * DESCRIPTION
 *  Get a instance for message viewer cui. It will return the pointer of found
 *  instance.
 * PARAMETERS
 *  grp_id:         [IN]    Group id of this instance. (should be unique)
 * RETURNS
 *  The instance pointer of message viewr cui.
 * RETURN VALUES
 *  Pointer of memory
 *****************************************************************************/
extern cui_msg_viewer_inst_struct *cui_msg_viewer_get_instance(mmi_id grp_id);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_schedule
 * DESCRIPTION
 *  The scheduler of message viewer cui. Currently, it has 4 different states.
 *      INIT, READY, NO_MSG_LIST, DEINIT.
 *      INIT        : It will create a group from FW and start to entry
 *                    message viewr marker.
 *      READY       : All data is ready. It will start to entry a marker and 
 *                    launch the corresponding message viewer.
 *      NO_MSG_LIST : If supporting the iterator viewer, it may not have the 
 *                    message list. In this state, it will wait the message
 *                    list set from caller.
 *      DEINIT      : It will deinit the marker and free the memory of message
 *                    viewer instance.
 * PARAMETERS
 *  inst:           [IN]    The instance of message viewer cui.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_schedule(cui_msg_viewer_inst_struct *inst);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_grp_proc
 * DESCRIPTION
 *  The proc handler of screen group. Currently, it does not have any handler
 *  inside.
 * PARAMETERS
 *  evt:            [IN]    Event sent from FW.
 * RETURNS
 *  The handler result of this event.
 * RETURN VALUES
 *  MMI_RET_OK.(always currently)
 *****************************************************************************/
extern mmi_ret cui_msg_viewer_grp_proc(mmi_event_struct *evt);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_schedule_init
 * DESCRIPTION
 *  Initial function of instance. It will create a screen group and start to
 *  entry a message viewer marker.
 * PARAMETERS
 *  inst:           [IN]    Instance of message viewer cui.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_schedule_init(cui_msg_viewer_inst_struct *inst);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_schedule_init_entry
 * DESCRIPTION
 *  The entry function with argument of initial state. It is the extra
 *  function for FW usage.
 * PARAMETERS
 *  arg:            [IN]    The argument sent from FW. The user data is also
 *                          inside.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_schedule_init_entry(mmi_scrn_essential_struct *arg);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_schedule_ready
 * DESCRIPTION
 *  Ready function of instance. It will launch the cooresponding message. For
 *  iterator viewer, it should also check the message list is taken.
 * PARAMETERS
 *  inst:           [IN]    Instance of message viewer cui.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_schedule_ready(cui_msg_viewer_inst_struct *inst);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_schedule_deinit
 * DESCRIPTION
 *  Deinitial function of instance. It will close the screen gruop and free
 *  the memory of instance.
 * PARAMETERS
 *  inst:           [IN]    Instance of message viewer cui.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_schedule_deinit(cui_msg_viewer_inst_struct *inst);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_entry
 * DESCRIPTION
 *  Entry function of message viewer marker. If go back to this screen, it
 *  means it should close the message viewer. Hence, it will send a event to 
 *  the caller to inform them that they should close it.
 * PARAMETERS
 *  arg:            [IN]    The argument sent from FW. The user_data is also
 *                          inside.
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void cui_msg_viewer_entry(mmi_scrn_essential_struct *arg);
/*****************************************************************************
 * FUNCTION
 *  cui_msg_viewer_leave_proc
 * DESCRIPTION
 *  Leave proc function of message viewer marker. If it receives the deinit 
 *  event, it should delete its own instance.
 * PARAMETERS
 *  evt:            [IN]    Framework event
 * RETURNS
 *  The handling result
 * RETURN VALUES
 *  MMI_RET: success
 *  Others: Fail
 *****************************************************************************/
extern mmi_ret cui_msg_viewer_leave_proc(mmi_event_struct *evt);
#endif /* CUI_MSGVIEWERCUI_H */

