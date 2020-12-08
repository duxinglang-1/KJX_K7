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
 *   gs_srv_um_impl.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Class header file
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
#ifndef _UM_INTERFACE_
#define _UM_INTERFACE_

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_um_interface_def.h"


class UmService : public GS_CBase, public IUm
{

public:
    UmService(U32 handle):GS_CBase(handle){}

    /* Common API */
    virtual S32 CALLCC addRef()
    {
        return GS_CBase::addRef();
    }
    virtual S32 CALLCC release()
    {
        return GS_CBase::release();
    }
    virtual S32 CALLCC queryInterface(S32 iid, GS_IBase **pptr);

    /* Functional API */
    virtual MMI_BOOL CALLCC check_support_type(gs_srv_um_msg_enum msg_type);
    virtual MMI_BOOL CALLCC check_ready_type(gs_srv_um_msg_enum msg_type);
    virtual S32 CALLCC clear_msg_info_cache(void);
    virtual S32 CALLCC cancel_request(S32 pid);
    virtual S32 CALLCC get_request_progress(S32 pid, S32 *finish_number, S32 *total_number);
    virtual S32 CALLCC check_list(
        gs_srv_um_list_type_enum list_type,
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_list_filter_struct *filter,
        gs_srv_um_notify_list_handler cb_func,
        S32 user_data,
        gs_srv_um_list_cntx_struct **list_cntx);

    virtual S32 CALLCC check_msg_info(
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_msg_node_struct msg_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 msg_number,
        gs_srv_um_msg_info_struct msg_info[]);

    virtual S32 CALLCC get_msg_num(
        gs_srv_um_msg_enum msg_type,
        gs_srv_um_sim_enum sim_id,
        gs_srv_um_get_msg_num_cb cb_func,
        S32 user_data);  

    virtual S32 CALLCC get_list(
        gs_srv_um_list_type_enum list_type,
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_list_filter_struct *filter,
        gs_srv_um_get_msg_list_cb cb_func,
        S32 user_data);  

    virtual S32 CALLCC release_list(S32 list_cid, MMI_BOOL out_of_date);  
    virtual S32 CALLCC get_msg_info (
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_msg_node_struct msg_list[],
        U16 msg_number,
        gs_srv_um_get_msg_info_cb cb_func,
        S32 user_data);

    virtual S32 CALLCC delete_folder(
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_delete_folder_cb cb_func,
        S32 user_data);   

    virtual S32 CALLCC check_thread_info(
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_thread_id_struct thread_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 thread_number,
        gs_srv_um_thread_info_struct *thread_info[],
        gs_srv_um_msg_info_struct msg_info[]);       

    virtual S32 CALLCC get_thread_info (
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_thread_id_struct thread_list[],
        U16 thread_number,
        gs_srv_um_get_thread_info_cb cb_func,
        S32 user_data); 
        
    virtual S32 CALLCC mark_several_thread_op(
        gs_srv_um_box_identity_struct msg_box,
        gs_srv_um_thread_id_struct thread_list[],
        U16 thread_list_size,
        U32 mark_status[],
        gs_srv_um_mark_several_op_action_enum action_type,
        gs_srv_um_mark_several_thread_op_cb cb_func,
        S32 user_data);

    virtual S32 CALLCC tsfr_address_to_thread_id(gs_srv_um_addr_enum type, U16* ucs2_str, gs_srv_um_thread_id_struct *thread_id);
    virtual S32 CALLCC update_thread_id(gs_srv_um_thread_id_struct *thread_id);
    
};



#endif /* _UM_INTERFACE_ */ 

