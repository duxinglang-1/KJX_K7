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
 *   srv_um_interface.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IUm interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_um_interface_def.h"

#include "gs_srv_um_type.h"

/*****************************************************************************
 * Ium methods
 *****************************************************************************/

S32 __inline IUm_addRef(IUm *obj)
{
    return obj->vt->addRef(obj);
}


S32 __inline IUm_release(IUm *obj)
{
    return obj->vt->release(obj);
}


S32 __inline IUm_queryInterface(IUm *obj, S32 iid, IBase **pptr)
{
    return obj->vt->queryInterface(obj, iid, pptr);
}

  
MMI_BOOL __inline IUm_check_support_type(IUm *obj, gs_srv_um_msg_enum msg_type)
{
    return obj->vt->check_support_type(obj, msg_type);
}

MMI_BOOL __inline IUm_check_ready_type(IUm *obj,gs_srv_um_msg_enum msg_type)
{
    return obj->vt->check_ready_type(obj, msg_type);
}

S32 __inline IUm_clear_msg_info_cache(IUm *obj)
{
    return obj->vt->clear_msg_info_cache(obj);
}

S32 __inline IUm_cancel_request(IUm *obj, S32 pid)        
{
    return obj->vt->cancel_request(obj, pid);
}        

S32 __inline IUm_get_request_progress(S32 pid, S32 *finish_number, S32 *total_number)        
{
    return obj->vt->get_request_progress(obj, pid, finish_number, total_number);
} 


S32 __inline IUm_check_list(  IUm *obj,
                                gs_srv_um_list_type_enum list_type,
                                gs_srv_um_box_identity_struct msg_box,
                                gs_srv_um_list_filter_struct *filter,
                                gs_srv_um_notify_list_handler cb_func,
                                S32 user_data,
                                gs_srv_um_list_cntx_struct **list_cntx)
{
    return obj->vt->check_list(obj,list_type,msg_box,filter,cb_func,user_data,list_cntx);
}

S32 __inline IUm_check_msg_info(   IUm *obj, 
                                        gs_srv_um_box_identity_struct msg_box,
                                        gs_srv_um_msg_node_struct msg_list[],
                                        U16 list_info_size,
                                        U16 start_entry,
                                        U16 msg_number,
                                        gs_srv_um_msg_info_struct msg_info[])
{
    return obj->vt->check_msg_info(obj, msg_box, msg_list, list_info_size, start_entry, msg_number, msg_info);
}

S32 __inline IUm_get_msg_num(IUm *obj, 
                                        gs_srv_um_msg_enum msg_type,
                                        gs_srv_um_sim_enum sim_id,
                                        gs_srv_um_get_msg_num_cb cb_func,
                                        S32 user_data)
{
    return obj->vt->get_msg_num(obj, msg_type, sim_id, cb_func, user_data);
}
        
S32 __inline IUm_get_list(IUm *obj, 
                                gs_srv_um_list_type_enum list_type,
                                gs_srv_um_box_identity_struct msg_box,
                                gs_srv_um_list_filter_struct *filter,
                                gs_srv_um_get_msg_list_cb cb_func,
                                S32 user_data)        
{
    return obj->vt->get_list(obj, list_type, msg_box, filter, cb_func, user_data); 
}

S32 __inline IUm_release_list(IUm *obj, S32 list_cid, MMI_BOOL out_of_date)
{
    return obj->vt->release_list(obj, list_cid, out_of_date);
}

S32 __inline IUm_get_msg_info( IUm *obj, 
                                        gs_srv_um_box_identity_struct msg_box,
                                        gs_srv_um_msg_node_struct msg_list[],
                                        U16 msg_number,
                                        gs_srv_um_get_msg_info_cb cb_func,
                                        S32 user_data)
{
    return obj->vt->get_msg_info(obj, msg_box, msg_list, msg_number, cb_func, user_data);
}

S32 __inline IUm_delete_folder(IUm *obj,
                                                         gs_srv_um_box_identity_struct msg_box,
                                                         gs_srv_um_delete_folder_cb cb_func,
                                                         S32 user_data)
{
    return obj->vt->delete_folder(obj, msg_box, cb_func, user_data);
}

S32 __inline IUm_check_thread_info(IUm *obj, 
                                            gs_srv_um_box_identity_struct msg_box,
                                            gs_srv_um_thread_id_struct thread_list[],
                                            U16 list_info_size,
                                            U16 start_entry,
                                            U16 thread_number,
                                            gs_srv_um_thread_info_struct *thread_info[],
                                            gs_srv_um_msg_info_struct msg_info[])
{
    return obj->vt->check_thread_info(obj,msg_box, thread_list, list_info_size, start_entry, thread_number, thread_info,msg_info);
}
       
S32 __inline IUm_get_thread_info(  IUm *obj, 
                                            gs_srv_um_box_identity_struct msg_box,
                                            gs_srv_um_thread_id_struct thread_list[],
                                            U16 thread_number,
                                            gs_srv_um_get_thread_info_cb cb_func,
                                            S32 user_data)
{
    return obj->vt->get_thread_info(obj,msg_box,thread_list,thread_number, cb_func,user_data);
}

S32 __inline IUm_mark_several_thread_op(IUm *obj, 
                                                    gs_srv_um_box_identity_struct msg_box,
                                                    gs_srv_um_thread_id_struct thread_list[],
                                                    U16 thread_list_size,
                                                    U32 mark_status[],
                                                    gs_srv_um_mark_several_op_action_enum action_type,
                                                    gs_srv_um_mark_several_thread_op_cb cb_func,
                                                    S32 user_data)
{
    return obj->vt->mark_several_thread_op(obj,msg_box,thread_list,thread_list_size,mark_status,action_type,cb_func,user_data);
}

S32 __inline IUm_tsfr_address_to_thread_id(IUm *obj,gs_srv_um_addr_enum type, U16* ucs2_str, gs_srv_um_thread_id_struct *thread_id)        
{
    return obj->vt->tsfr_address_to_thread_id(obj,type,ucs2_str,thread_id);
}       

S32 __inline IUm_update_thread_id(IUm *obj,gs_srv_um_thread_id_struct *thread_id)        
{
    return obj->vt->update_thread_id(obj,thread_id);
}     


