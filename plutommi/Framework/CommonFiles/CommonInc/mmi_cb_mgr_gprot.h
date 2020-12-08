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
 * mmi_cb_mgr_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is callback manager gprot header file.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_CB_MGR_GPROT_H
#define MMI_CB_MGR_GPROT_H

/* DOM-NOT_FOR_SDK-BEGIN */
#include "MMIDataType.h"
/* DOM-NOT_FOR_SDK-END */

#include "kal_general_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * typedef
 *****************************************************************************/
/* This is for DOM generation, otherwise MMI_EVT_PARAM_HEADER will generate class not struct. */

#ifdef __BUILD_DOM__
/* This struct is for mmi event struct */
typedef struct
{
    /* Event id */
    U16 evt_id; 
    /* Event structure size */
    U16 size; 
    /* User data pointer */
    void *user_data;
}mmi_event_struct;

/******************************************************************
 This struct is for mmi post result event struct, the whole member is 
 typedef struct
 {
    //Event header
    MMI_EVT_PARAM_HEADER
    //Result value
    mmi_ret result;
    //Event pointer
    mmi_event_struct *evt_p;
 } mmi_post_result_event_struct;
**********************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* Event header */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    /* Result value */
    mmi_ret result;
    /* Event pointer */
    mmi_event_struct *evt_p;
} mmi_post_result_event_struct;

/* mmi proc function type */
typedef mmi_ret (*mmi_proc_func) (mmi_event_struct *param);
/* mmi prost event result function type */
typedef mmi_ret (*mmi_post_event_result_proc_func)(mmi_post_result_event_struct *result_evt);
#endif /* __BUILD_DOM__ */

/*****************************************************************************
 * Extern Global Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_emit_event
 * DESCRIPTION
 *  Emit event to all callee callback, if callback return MMI_RET_OK, 
 *  continue to execute the rest of callback funtions, 
 *¡¡otherwise, stop execution and return result of the current callback.
 *  caller and callee app should decide the meaning of the return value.
 *  The event id must declare in sender's res file, using <sender id="xxx", hfile="xxxx">.
 *  The callback declares in receiver's res file.
 * PARAMETERS
 *  evt :            [IN]  event structure pointer.
 * RETURNS
 *  Return MMI_RET_ERR_WRONG_PARA if evt pointer if NULL;
 *  otherwise, return MMI_RET_OK.
 *****************************************************************************/
extern mmi_ret mmi_frm_cb_emit_event(mmi_event_struct *evt);


/* See the discription of mmi_frm_cb_emit_event */
#define MMI_FRM_CB_EMIT_EVENT(_evt)        mmi_frm_cb_emit_event((mmi_event_struct *)(_evt))


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_emit_post_event
 * DESCRIPTION
 *  Emit post events, the callback of this event will be invoked after current 
 *  function flow and before next input event like key, pen, timer, primitive.
 * PARAMETERS
 *  evt :      [IN]  post event structure pointer.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_cb_emit_post_event(mmi_event_struct *evt);


/* See the discription of mmi_frm_cb_emit_post_event */
#define MMI_FRM_CB_EMIT_POST_EVENT(_evt)       mmi_frm_cb_emit_post_event((mmi_event_struct *)(_evt))


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_emit_post_event_ex
 * DESCRIPTION
 *  Emit post events, the callback of this events will be invoked after current 
 *  function flow, this extension api support reveiver feedback result value back to
 *  sender through result_cb.
 *  And result callback will be invoked with EVT_ID_POST_CB_RST and result_cb_user_data to
 *  notify sender the result.
 * PARAMETERS
 *  evt :                 [IN]    event structure pointer;
 *  result_cb :           [IN]    result callback;
 *  result_cb_user_data : [IN]    result callback user data;
 * RETURNS
 *  Return MMI_RET_OK if success;
 *****************************************************************************/
extern void mmi_frm_cb_emit_post_event_ex(mmi_event_struct *evt, mmi_post_event_result_proc_func result_cb, void *result_cb_user_data);


/* See the discription of mmi_frm_cb_emit_post_event_ex */
#define MMI_FRM_CB_EMIT_POST_EVENT_EX(_evt, _rst_cb, _rst_cb_user_data)      \
        mmi_frm_cb_emit_post_event_ex((mmi_event_struct *)(_evt), (mmi_post_event_result_proc_func)(_rst_cb), (void *)(_rst_cb_user_data))

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_reg_event
 * DESCRIPTION
 *  Register event callback dynamically with user data pointer. Dynamic registry means your usage has life cycle,
 *  and you must call mmi_frm_cb_dereg_event when you do not use it.
 *  If you do not match this condition, please use the static registry method. 
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  call_back :   [IN]  callback function.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered;
 *  return MMI_RET_ERR_WRONG_PARA if call_back is NULL.
 *****************************************************************************/
extern mmi_ret mmi_frm_cb_reg_event(U16 evt_id, mmi_proc_func call_back, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_dereg_event
 * DESCRIPTION
 *  Deregister event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  call_back :   [IN]  callback function.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to deregister callback with designated user data;
 *  return MMI_RET_ERR_NO_CB_AND_DATA if the designated callback with 
 *  designated user data hasn't been registered;
 *  return MMI_RET_ERR_WRONG_PARA if call_back is NULL.
 *****************************************************************************/
extern mmi_ret mmi_frm_cb_dereg_event(U16 evt_id, mmi_proc_func call_back, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_has_event_reg
 * DESCRIPTION
 *  Check if callback with user data has been registered for designated event.
 * PARAMETERS
 *  evt_id :    [IN]  callback execution type.
 *  call_back : [IN]  callback function.
 *  user_data : [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered;
 *  return MMI_RET_ERR_WRONG_PARA if call_back is NULL.
 *****************************************************************************/
MMI_BOOL mmi_frm_cb_has_event_reg(U16 evt_id, mmi_proc_func call_back, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_cb_register_receiver_count
 * DESCRIPTION
 *  Query the register receiver count, including static and dynamic. Please pay
 *  attention it is different with the execute receiver count.
 * PARAMETERS
 *  evt_id    : [IN] the event id you want to query.
 * RETURNS
 *  MMI_RET_ERR_CANT_FIND_EVT or the number of register receiver count
 *****************************************************************************/
extern S32 mmi_frm_cb_register_receiver_count(U16 evt_id);



#endif /* MMI_CB_MGR_GPROT_H */

